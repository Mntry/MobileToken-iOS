//
//  MonetaryTokenizer.h
//  MonetaryMobileToken
//
//  Copyright © 2016 Monetary. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MonetaryMobileToken/MonetaryTokenDelegate.h>

@interface MonetaryTokenizer : NSObject

- (void)requestKeyedTokenWithPublicKey:(NSString *)publicKey andDelegate:(NSObject<MonetaryTokenDelegate> *)delegate overViewController:(UIViewController *)parentViewController;

@end