//
//  MonetaryTokenizer.h
//  MonetaryMobileToken
//
//  Copyright © 2016 Monetary. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MonetaryMobileToken/MonetaryTokenDelegate.h>

/**
 Monetary Tokenizer class for initiating account data entry and tokenization.
 */
@interface MonetaryTokenizer : NSObject

/**
 Initialize MonetaryTokenizer with custom UI properties.
 
 @param  acceptButtonText Text to display on Accept buttons of user-input dialogs.
 @param  acceptButtonColor Color to set Accept buttons of user-input dialogs.
 @param  cancelButtonText Text to display on Cancel buttons of user-input dialogs.
 @param  cancelButtonColor Color to set Cancel buttons of user-input dialogs.
 */
- (id)initWithCustomAcceptButtonText:(NSString *)acceptButtonText
                   acceptButtonColor:(UIColor *)acceptButtonColor
                    cancelButtonText:(NSString *)cancelButtonText
                andCancelButtonColor:(UIColor *)cancelButtonColor;

/**
 Request a token with user-input account data.
 
 Calling this method with the appropriate parameters presents the user with 3 account data entry views, then tokenizes the data input by the user and calls the provided delegate with tokenization results.
 
 @param  publicKey A Monetary public key for authentication.
 @param  delegate A MonetaryTokenDelegate object which to call with tokenization results.
 @param  parentViewController A UIViewController over which to display account data entry views.
 */
- (void)requestKeyedTokenWithPublicKey:(NSString *)publicKey
                           andDelegate:(NSObject<MonetaryTokenDelegate> *)delegate
                    overViewController:(UIViewController *)parentViewController;

@end