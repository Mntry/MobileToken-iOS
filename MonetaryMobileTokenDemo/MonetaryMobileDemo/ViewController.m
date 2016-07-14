//
//  ViewController.m
//  MonetaryMobileDemo
//
//  Copyright © 2016 Monetary. All rights reserved.
//

#import "ViewController.h"

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)btnGetAToken_Pressed:(id)sender
{
    MonetaryTokenizer *tokenizer = [MonetaryTokenizer new];
    [tokenizer requestKeyedTokenWithPublicKey:@"[Public Key Goes Here]"
                                  andDelegate:self
                           overViewController:self];
}

- (void)tokenCreated:(MonetaryToken *)token
{
    UIAlertController *alertController = [UIAlertController
                                          alertControllerWithTitle:@"We've got a token!"
                                          message:token.Token
                                          preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction *okAction = [UIAlertAction
                               actionWithTitle:NSLocalizedString(@"OK", @"OK action")
                               style:UIAlertActionStyleDefault
                               handler:nil];
    
    [alertController addAction:okAction];
    
    [self presentViewController:alertController animated:YES completion:nil];
}

- (void)tokenizationError:(NSError *)error
{
    UIAlertController *alertController = [UIAlertController
                                          alertControllerWithTitle:error.localizedFailureReason
                                          message:error.localizedRecoverySuggestion
                                          preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction *okAction = [UIAlertAction
                               actionWithTitle:NSLocalizedString(@"OK", @"OK action")
                               style:UIAlertActionStyleDefault
                               handler:nil];
    
    [alertController addAction:okAction];
    
    [self presentViewController:alertController animated:YES completion:nil];
}

- (void)tokenizationCancelled
{
    UIAlertController *alertController = [UIAlertController
                                          alertControllerWithTitle:@"User cancelled!"
                                          message:@"The user has cancelled entering account data."
                                          preferredStyle:UIAlertControllerStyleAlert];
    
    UIAlertAction *okAction = [UIAlertAction
                               actionWithTitle:NSLocalizedString(@"OK", @"OK action")
                               style:UIAlertActionStyleDefault
                               handler:nil];
    
    [alertController addAction:okAction];
    
    [self presentViewController:alertController animated:YES completion:nil];
}

@end
