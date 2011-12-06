//
//  FTShareTwitter.h
//  FTShareView
//
//  Created by cescofry on 06/12/2011.
//  Copyright (c) 2011 Fuerte International. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "SA_OAuthTwitterEngine.h"
#import "SA_OAuthTwitterController.h"


#pragma mark --
#pragma mark Data Type

@interface FTShareTwitterData : NSObject {
    NSString *_message;
}

@property (nonatomic, retain) NSString *message;

- (BOOL)isRequestValid;

@end



#pragma mark --
#pragma mark Class


@protocol FTShareTwitterDelegate;
@interface FTShareTwitter : NSObject <SA_OAuthTwitterControllerDelegate, SA_OAuthTwitterEngineDelegate> {
    SA_OAuthTwitterEngine *_twitter;
    id <FTShareTwitterDelegate> _twitterDelegate;
    FTShareTwitterData *_twitterParams;
    id _referencedController;
}

@property (nonatomic, assign) id<FTShareTwitterDelegate> twitterDelegate;

- (void)setUpTwitterWithConsumerKey:(NSString *)consumerKey secret:(NSString *)secret referencedController:(id)referencedController andDelegate:(id<FTShareTwitterDelegate>)delegate;
- (void)shareViaTwitter:(FTShareTwitterData *)data;
@end



#pragma mark --
#pragma mark Delegate

@protocol FTShareTwitterDelegate <NSObject>

@optional

- (FTShareTwitterData *)twitterData;
- (void)twitterLoginDialogController:(UIViewController *)controller;
- (void)twitterDidLogin:(NSError *)error;
- (void)twitterDidPost:(NSError *)error;

@end
