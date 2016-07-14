//
//  ViewController.h
//  MonetaryMobileDemo
//
//  Copyright © 2016 Monetary. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MonetaryMobileToken/MonetaryMobileToken.h>

@interface ViewController : UIViewController <MonetaryTokenDelegate>

- (IBAction)btnGetAToken_Pressed:(id)sender;

@end

