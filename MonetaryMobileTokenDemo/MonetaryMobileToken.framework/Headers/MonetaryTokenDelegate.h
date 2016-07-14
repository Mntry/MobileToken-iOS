//
//  MonetaryTokenDelegate.h
//  MonetaryMobileToken
//
//  Copyright © 2016 Monetary. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MonetaryMobileToken/MonetaryToken.h>

@protocol MonetaryTokenDelegate <NSObject>

- (void)tokenCreated:(MonetaryToken *)token;
- (void)tokenizationError:(NSError *)error;
- (void)tokenizationCancelled;

@end