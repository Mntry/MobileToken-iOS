# Getting started with MobileToken for iOS

###Add MonetaryMobileToken.framework to your Xcode project
1. In the project navigator, select the project or group within a project to which you want to add the framework.
2. Choose File > Add Files to “*Your Project Name*”.
3. Select the MonetaryMobileToken.framework bundle, and click Add.
4. In the project settings, choose the Build Phases tab.
5. Under the Embed Frameworks section, choose "+" to add a new Embedded Framework.
6. Select the MonetaryMobileToken.framework bundle, and click Add.

###Include the framework in your code
```objective-c
#import <MonetaryMobileToken/MonetaryMobileToken.h>
```

###Implement the tokenization delegate
#####Implement the `MonetaryTokenDelegate` protocol
```objective-c
@interface ViewController : UIViewController <MonetaryTokenDelegate>
```
#####Implement `MonetaryTokenDelegate` methods
```objective-c
- (void)tokenCreated:(MonetaryToken *)token
{
  // A token has been received!
}
```

In the `tokenCreated` method, the received `MonetaryToken` object contains 5 `NSString` properties:  
* `Token`: The one-time-use token for the user-entered account data.
* `Brand`: The card brand of account represented by the token.
* `ExpirationMonth`: The 2-digit expiration month of the account.
* `ExpirationYear`: The 4-digit expiration year of the account.
* `Last4`: The last 4 digits of the account number.

```objective-c
- (void)tokenizationError:(NSError *)error
{
  // A tokenization error has occurred!
}
```
The `tokenizationError` method will receive an `NSError` object with one of the 4 following error codes:
* `MMConnectionError`: Failed to communicate with Monetary Token API.
* `MMAuthenticationError`: Public key authentication failed.
* `MMDataValidationError`: Failed to tokenize due to invalid account information.
* `MMTokenizationError`: An error has occurred tokenizing the account data at the Monetary Token API.
```objective-c
- (void)tokenizationCancelled
{
  // The user has cancelled tokenization!
}
```

###Request a token for keyed account
#####Provide a `MonetaryTokenizer` object with a Monetary public key, a `MonetaryTokenDelegate` object which to send events, and a `UIViewController` over which to display the account entry views
```objective-c
MonetaryTokenizer *tokenizer = [MonetaryTokenizer new];
[tokenizer requestKeyedTokenWithPublicKey:@"[Public Key Goes Here]"
                              andDelegate:self
                       overViewController:self];
```
