//
//  BugsnagMetaData.h
//
//  Created by Conrad Irwin on 2014-10-01.
//
//  Copyright (c) 2014 Bugsnag, Inc. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall remain in place
// in this source code.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#import <Foundation/Foundation.h>

@protocol BugsnagMetadataDelegate;

@interface BugsnagMetadata : NSObject <NSMutableCopying>

- (instancetype _Nonnull)initWithDictionary:(NSMutableDictionary *_Nonnull)dict;

/**
 * Get a named metadata section
 *
 * @param sectionName The name of the section
 * @returns The mutable dictionary representing the metadata section, if it
 *          exists, or nil if not.
 */
- (NSMutableDictionary *_Nullable)getMetadata:(NSString *_Nonnull)sectionName
    NS_SWIFT_NAME(getMetadata(_:));

- (void)clearMetadataInSection:(NSString *_Nonnull)section
    NS_SWIFT_NAME(clearMetadata(_:));

- (NSDictionary *_Nonnull)toDictionary;

- (void)addAttribute:(NSString *_Nonnull)attributeName
           withValue:(id _Nullable)value
       toTabWithName:(NSString *_Nonnull)tabName;

@property(unsafe_unretained) id<BugsnagMetadataDelegate> _Nullable delegate;

@end

@protocol BugsnagMetadataDelegate <NSObject>
- (void)metadataChanged:(BugsnagMetadata *_Nonnull)metadata;
@end
