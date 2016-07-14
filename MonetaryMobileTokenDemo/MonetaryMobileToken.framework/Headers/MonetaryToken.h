//
//  MonetaryToken.h
//  MonetaryMobileToken
//
//  Copyright © 2016 Monetary. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MonetaryToken : NSObject

@property (strong, nonatomic) NSString *Token;
@property (strong, nonatomic) NSString *Brand;
@property (strong, nonatomic) NSString *ExpirationMonth;
@property (strong, nonatomic) NSString *ExpirationYear;
@property (strong, nonatomic) NSString *Last4;

@end
