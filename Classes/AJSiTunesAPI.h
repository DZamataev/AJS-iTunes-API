/*
 * Copyright (c) 2011, Andy Smart. All rights reserved.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Andy Smart nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ANDY SMART ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ANDY SMART BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import <Foundation/Foundation.h>
#import "ASIHTTPRequest.h"
#import "AJSiTunesAPIDelegate.h"
#import "AJSiTunesResult.h"

typedef void (^AJSiTunesAPICompletionBlock)(NSArray *results);
typedef void (^AJSiTunesAPIFailureBlock)(NSError *error);

@interface AJSiTunesAPI : NSObject
{
    @private
    ASIHTTPRequest *_request;
    id <AJSiTunesAPIDelegate> _delegate;
}

- (void) searchMediaWithSearchTerm:(NSString *)searchTerm;
- (void) searchMediaWithType:(kAJSiTunesAPIMediaType)type 
                  searchTerm:(NSString *)keywords
                 countryCode:(NSString *)countryCode
                       limit:(NSInteger)limit; //Restricted to 200 max

- (void) searchMediaWithSearchTerm:(NSString *)searchTerm 
                   completionBlock:(AJSiTunesAPICompletionBlock)completionBlock 
                      failureBlock:(AJSiTunesAPIFailureBlock)failureBlock;

- (void) searchMediaWithType:(kAJSiTunesAPIMediaType)type 
                  searchTerm:(NSString *)keywords
                 countryCode:(NSString *)countryCode
                       limit:(NSInteger)limit
             completionBlock:(AJSiTunesAPICompletionBlock)completionBlock
                failureBlock:(AJSiTunesAPIFailureBlock)failureBlock;

@property (nonatomic, assign) id <AJSiTunesAPIDelegate> delegate;

@end
