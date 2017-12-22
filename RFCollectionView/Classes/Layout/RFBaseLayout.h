//
//  RFBaseLayout.h
//  Masonry
//
//  Created by qianjie on 2017/12/22.
//

#import <Foundation/Foundation.h>

@interface RFBaseLayout : NSObject

@property (nonatomic, strong) NSArray *frames;
@property (nonatomic, assign) CGSize contentSize;

- (void)didLayout;

- (void)layout;

- (CGRect)frameAtIndex:(NSUInteger)index;

- (NSArray *)visibleIndexes:(CGRect)activeFrame;

@end

