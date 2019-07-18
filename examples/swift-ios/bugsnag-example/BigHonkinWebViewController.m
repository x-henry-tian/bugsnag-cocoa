#import <WebKit/WebKit.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import <signal.h>
#import "BigHonkinWebViewController.h"
#import <Bugsnag/Bugsnag.h>

@interface BigHonkinWebViewController ()
@property (nonatomic, strong) WKWebView *webView;
@property (nonatomic, strong) NSOperationQueue *noteQueue;
@end

@implementation BigHonkinWebViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.noteQueue = [NSOperationQueue new];
    [[NSNotificationCenter defaultCenter] addObserverForName:nil object:nil queue:self.noteQueue usingBlock:^(NSNotification * _Nonnull note) {
        NSLog(@"--> Received note: '%@'", note.name);
    }];
    self.webView = [[WKWebView alloc] initWithFrame:self.view.bounds];
    [self.view addSubview:self.webView];
}

- (void)didReceiveMemoryWarning {
    NSLog(@"--> Received a low memory warning");
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];

    dispatch_queue_t load_queue = dispatch_queue_create("com.bugsnag.load_queue", nil);
    dispatch_async(load_queue, ^{
        NSMutableData *data = [NSMutableData new];
        unsigned long long total = 0;
        while (true) {
            NSUInteger size = 200 * 1024 * 1024;
            void *bytes = malloc(size);
            [data appendBytes:bytes length:size];
            total += size;
            unsigned long long mb = total / (1024 * 1024);
            if (mb % 1000 == 0)
                NSLog(@"Allocated %llu mb", mb);
        }
    });
}

@end
