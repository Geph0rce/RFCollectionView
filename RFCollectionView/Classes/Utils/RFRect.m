//
//  RFRect.m
//  Masonry
//
//  Created by qianjie on 2017/12/22.
//

#import "RFRect.h"

@implementation RFRect

- (BOOL)intersectsRect:(RFRect *)rect {
    return CGRectIntersectsRect(self.frame, rect.frame);
}

@end
