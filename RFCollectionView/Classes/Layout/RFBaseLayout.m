//
//  RFBaseLayout.m
//  Masonry
//
//  Created by qianjie on 2017/12/22.
//

#import "RFBaseLayout.h"

@implementation RFBaseLayout

- (void)didLayout {}

- (void)layout {}

- (CGRect)frameAtIndex:(NSUInteger)index {
    return CGRectZero;
}

- (NSArray *)visibleIndexes:(CGRect)activeFrame {
    return [NSArray array];
}

@end
