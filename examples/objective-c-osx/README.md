# Example MacOS integration with Bugsnag

1. Run `pod install`
2. Open the generated workspace in XCode
3. Insert your API key in the AppDelegate's `application:didFinishLaunchingWithOptions:`

    `NSString *apiKey = @"<YOUR_APIKEY_HERE>";`

4. Run the app! There are several examples of different kinds of errors which can be thrown.
