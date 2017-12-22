//
//  RFFlowLayout.m
//  Masonry
//
//  Created by qianjie on 2017/12/22.
//

#import "RFFlowLayout.h"
@implementation RFFlowLayout

- (void)layout:(CGSize)collectionViewSize dataProvider:(RFCollectionDataProvider *)dataProvider sizeProvider:(RFCollectionSizeProvider)sizeProvider {
    guard (sizeProvider) else {
        DLog(@"sizeProvider is nil");
        return;
    }
    NSMutableArray *sizes = [[NSMutableArray alloc] init];
    for (int i = 0; i < dataProvider.numberOfItems; i++) {
        NSObject *data = [dataProvider dataAtIndex:i];
        CGSize size = sizeProvider(i, data, collectionViewSize);
        [sizes addObject:@(size)];
    }
}

@end
