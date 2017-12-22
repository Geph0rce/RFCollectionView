//
//  RFCollectionDataProvider.m
//  Masonry
//
//  Created by qianjie on 2017/12/22.
//

#import "RFCollectionDataProvider.h"

@implementation RFCollectionDataProvider

- (id)dataAtIndex:(NSUInteger)index {
    guard (index < self.data.count) else {
        DLog(@"index (%@) is out of bounds of self.data (%@)", @(index), @(self.data.count));
        return nil;
    }
    
    return self.data[index];
}

- (NSUInteger)numberOfItems {
    return self.data.count;
}

@end
