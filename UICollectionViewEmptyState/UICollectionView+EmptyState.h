//
//  UICollectionView+EmptyState.h
//  UICollectionViewEmptyState
//
//  Created by Jonathan Crooke on 14/05/2013.
//  Copyright (c) 2013 Jon Crooke. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//  SOFTWARE.

#import <UIKit/UIKit.h>

@protocol UICollectionViewEmptyStateDelegate;

@interface UICollectionView (EmptyState)

/** The view to be displayed when content is empty */
@property (nonatomic, strong) UIView *emptyState_view;

/** Convenience method to create a UIImageView with a centred UIImage placeholder */
- (UIImageView*) setEmptyStateImageViewWithImage:(UIImage*) image;

/** 
 If YES and section 0 contains a supplementary header view,
 don't overlay it. Useful if you have important controls in
 this header. Note that no supplementary views are displayed
 on a collection view at all if numberOfSectionsInCollectionView
 is 0.
 @note If you'd like to update this property at runtime, you must
 reload the collection view or invalidate its layout.
 */
@property (nonatomic, assign) BOOL emptyState_shouldRespectSectionHeader;

/**
 If YES, will set the empty state view property to nil during
 the next layout if it wasn't added. This is useful if the empty
 view is rarely required, and you would prefer to unswizzle the
 collection view to avoid unwanted side-effects.
 */
@property (nonatomic, assign) BOOL emptyState_shouldNilViewIfNotRequired;

/** Fade in animation duration. 0.0 = no animation */
@property (nonatomic, assign) NSTimeInterval emptyState_showAnimationDuration;

/** Fade out animation duration. 0.0 = no animation */
@property (nonatomic, assign) NSTimeInterval emptyState_hideAnimationDuration;

/** Delay before displaying the overlay */
@property (nonatomic, assign) NSTimeInterval emptyState_showDelay;

/** Delay before removing the overlay */
@property (nonatomic, assign) NSTimeInterval emptyState_hideDelay;

/** Further customisation */
@property (nonatomic, unsafe_unretained) id <UICollectionViewEmptyStateDelegate> emptyState_delegate;

@end

#pragma mark -

/**
 *  Overlay life-cycle delegate protocol
 */
@protocol UICollectionViewEmptyStateDelegate <NSObject>
@optional
/**
 *  Called when the overlay will be added to the collection view.
 *  @note View has been added to the collection view at this point,
 *  and method invoked from within the animation block.
 */
- (void)        collectionView:(UICollectionView*) collectionView
  willAddEmptyStateOverlayView:(UIView*) view
                      animated:(BOOL) animated;

/**
 *  Called when the overlay will be removed from the collection view.
 *  @note Invoked from within the animation block.
 */
- (void)          collectionView:(UICollectionView*) collectionView
 willRemoveEmptyStateOverlayView:(UIView*) view
                        animated:(BOOL) animated;

/**
 *  Called after the add animation (if any) has completed.
 */
- (void)        collectionView:(UICollectionView*) collectionView
   didAddEmptyStateOverlayView:(UIView*) view;

/**
 *  Called after the remove animation (if any) has completed.
 */
- (void)          collectionView:(UICollectionView*) collectionView
  didRemoveEmptyStateOverlayView:(UIView*) view;

/**
 *  Called with the proposed frame for the empty state overlay.
 *  @return A different frame if you wish to modify its value.
 */
- (CGRect) collectionView:(UICollectionView*) collectionView
             willSetFrame:(CGRect) proposed
 forEmptyStateOverlayView:(UIView*) view;
@end
