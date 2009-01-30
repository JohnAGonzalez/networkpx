/*
 *     Generated by class-dump 3.1.2.
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2007 by Steve Nygard.
 */

#import <UIKit/UIView.h>
#import <UIKit/UIApplication.h>
#import <UIKit2/CDStructures.h>
#import <CoreFoundation/CFDictionary.h>
#import <Foundation/NSDate.h>
#import <UIKit/UITextInputTraits.h>

@class NSArray, NSMutableDictionary, NSString, NSTimer, UIAutocorrectInlinePrompt, UIDelayedAction, UIKeyboardInputManager, UIKeyboardLanguageIndicator, UIKeyboardLayout, UITextInputTraits, CandWord;
@protocol UIKeyboardInput, UIKeyboardCandidateList;

@interface UIKeyboardImpl : UIView {
	// +32
	id<UIKeyboardInput> m_delegate;
	
	
    UIKeyboardLanguageIndicator *m_languageIndicator;
    NSArray *m_userSelectedInputModes;
    NSString *m_previousInputString;
	
    UIKeyboardInputManager *m_inputManager;		// +48
    NSString *m_autocorrection;				// +52
    UIAutocorrectInlinePrompt *m_autocorrectPrompt;	// +56
    UIDelayedAction *m_autocorrectPromptAction;		// +60
    NSArray *m_candidates;				// +64
    id <UIKeyboardCandidateList> m_candidateList;	// +68
    UIKeyboardLayout *m_layout;				// +72
    NSMutableDictionary *m_keyedLayouts;		// +76
    NSString *m_inputModeLastChosen;
    UIDelayedAction *m_synchronizePreferencesAction;
    NSTimer *m_autoDeleteTimer;

	// +92
    unsigned int m_autoDeleteCount;
    double m_autoDeleteLastDelete;	// +96
    double m_autoDeleteInterval;	// +104
    unsigned short m_autoDeleteShiftCharacter;	// +112

	// +116
    UIDelayedAction *m_longPressAction;
    int m_orientation;			// +120
    UIView *m_caretView;		// +124
    NSTimer *m_caretTimer;		// +128
    struct CGPoint m_inputPoint;	// +132
    int m_changeCount;			// +140
    double m_changeTime;		// +144
    struct __CFRunLoopObserver *m_observer;	// +152
    UITextInputTraits *m_defaultTraits;	// +156
    UITextInputTraits *m_traits;	// +160
    int m_returnKeyState;		// +164
    BOOL m_autocorrectionPreference;	// +168
    BOOL m_autocapitalizationPreference;// +169
    BOOL m_doubleSpacePeriodPreference;	// +170
    BOOL m_autoDeleteOK;		// +171
    BOOL m_autoshift;			// +172
    BOOL m_initializationDone;		// +173
    BOOL m_preferencesNeedSynchronization;	// +174
    BOOL m_shift;			// +175
    BOOL m_shiftLockedEnabled;		// +176
    BOOL m_shiftLocked;			// +177
    BOOL m_changed;			// +178
    BOOL m_selecting;			// +179
    BOOL m_inDealloc;			// +180
    BOOL m_caretVisible;		// +181
    BOOL m_caretBlinks;			// +182
    BOOL m_caretShowingNow;		// +183
    BOOL m_updatingPreferences;		// +184
    BOOL m_anotherTouchWaiting;		// +185
    BOOL m_performDecomposingDelete;	// +186
    BOOL m_delegateIsSMSTextView;	// +187
    BOOL m_performanceLoggingEnabled;	// +188
    BOOL m_shouldSkipCandidateSelection;// +189
    BOOL m_autocorrectPromptTimerFired;	// +190
    BOOL m_userChangedSelection;	// +191
    BOOL m_shouldChargeKeys;		// +192
    BOOL m_longPress;			// +193
    BOOL m_syntheticInput;		// +194
    BOOL m_shiftNeedsUpdate;		// +195
    BOOL m_shiftPreventAutoshift;	// +196
    BOOL m_shiftHeldDownNeedsUpdated;	// +197
}

+ (UIKeyboardImpl*)sharedInstance;
+ (UIKeyboardImpl*)activeInstance;
+ (void)releaseSharedInstance;

+ (CGSize)defaultSize;
+ (CGSize)defaultSizeForOrientation:(int)angle;
+ (CGSize)defaultSizeForInterfaceOrientation:(UIInterfaceOrientation)orientation;
+ (int)orientationForSize:(CGSize)size;

- (id)initWithFrame:(CGRect)frm;
- (void)delayedInit;
- (void)dealloc;
- (void)clearLayouts;
- (void)removeFromSuperview;

- (void)applicationSuspendedEventsOnly:(id)fp8;
- (void)applicationResumedEventsOnly:(id)fp8;

- (void)defaultsDidChange;
- (void)defaultsDidChange:(id)fp8;

- (void)synchronizePreferencesIfNeeded;
- (void)synchronizePreferences;
- (void)touchSynchronizePreferencesTimer;
- (void)clearSynchronizePreferencesTimer;

-(BOOL)performanceLoggingPreference;
-(BOOL)autocorrectionPreference;
-(BOOL)autocapitalizationPreference;
-(BOOL)doubleSpacePeriodPreference;
-(NSString*)UILanguagePreference;
-(BOOL)keyboardsExpandedPreference;
-(NSArray*)inputModePreference;
-(NSString*)localePreference;

-(NSString*)inputModeFirstPreference;
-(NSString*)inputModeLastChosenPreference;
-(NSString*)inputModeLastUsedPreference;

-(BOOL)shiftLockPreference;

-(void)setKeyboardsExpandedPreference;
-(void)setInputModePreference;
-(void)setInputModeLastChosenPreference;
-(void)setInputModeLastUsedPreference;

- (void)setKeyboardDefault:(id)fp8 forKey:(id)fp12;
- (id)keyboardDefaultForKey:(id)fp8;

- (void)setInputMode:(NSString*)mode;
- (void)setInputModeIfDifferentThanCurrent:(NSString*)mode;
- (void)setInputModeFromPreferences;
- (void)setInputModeToNextInPreferredList;
- (void)setInputModeToNextASCIICapableInPreferredList;

- (void)showInputModeIndicator;

- (void)fadeAnimationDidStop:(id)fp8 finished:(id)fp12;

- (NSString*)inputModeLastChosen;

- (void)setOrientationForSize:(CGSize)size;
- (void)setFrame:(CGRect)frm;
- (void)updateLayoutForInterfaceOrientation:(UIInterfaceOrientation)orientation;

- (void)takeTextInputTraitsFrom:(id)fp8;

@property(retain) NSObject<UIKeyboardInput>* delegate;

- (void)setDelegate:(id<UIKeyboardInput>)del force:(BOOL)force;

- (BOOL)delegateIsSMSTextView;

- (void)textChanged:(id)fp8;

@property(retain) id<UITextInputTraits> textInputTraits;

- (void)enable;

- (BOOL)callShouldInsertText:(NSString*)txt;
- (BOOL)callShouldDelete;
- (void)callChangedSelection;
- (int)callPositionForAutocorrection:(NSString*)autocor;
- (void)callChanged;
- (void)setChanged;
- (void)clearChangedDelegate;
- (void)clearInputManager;
- (void)handleObserverCallback;
- (void)prepareForGeometryChange;
- (void)geometryChangeDone:(BOOL)done;
- (void)updateLayout;
@property(assign,readonly) int orientation;
- (void)prepareForSelectionChange;
- (void)updateSelectionWithPoint:(CGPoint)pnt;
- (void)updateForChangedSelection;
- (void)updateInputManagerAutoShiftFlag;
- (void)notifyShiftState;
- (void)updateShiftState;
- (void)setShiftOffIfNeeded;
- (void)toggleShift;
@property(assign,getter=isShifted) BOOL shift;
@property(assign,getter=isShiftLocked) BOOL shiftLocked;
- (void)setShift:(BOOL)shifted autoshift:(BOOL)autoshifted;
- (void)setShiftPreventAutoshift:(BOOL)aBool;
- (void)setShiftNeedsUpdate;
- (BOOL)isAutoShifted;
- (BOOL)shiftLockedEnabled;
- (void)clearShiftState;
- (void)forceShiftUpdate;
- (void)forceShiftUpdateIfKeyboardStateChanged;
- (BOOL)shouldSkipCandidateSelection;
- (void)setShouldSkipCandidateSelection:(BOOL)fp8;

- (void)installCaret;
- (void)clearCaret;
- (void)hideCaret:(int)fp8;
- (void)showCaret:(int)fp8;
- (void)caretBlinkTimerFired:(id)fp8;
- (void)clearCaretBlinkTimer;
- (void)touchCaretBlinkTimer;
- (void)startCaretBlinkIfNeeded;
- (void)setCaretBlinks:(BOOL)fp8;
- (void)setCaretVisible:(BOOL)fp8;
- (BOOL)caretBlinks;
- (BOOL)caretVisible;
- (void)updateCaretRect;
- (void)caretChanged;

- (void)keyActivated;
- (void)keyDeactivated;

- (void)setInputPoint:(CGPoint)pnt;

- (void)handleDeleteAsRepeat:(BOOL)rpt;
- (void)handleDelete;
- (void)handleStringInput:(NSString*)inp;
- (BOOL)acceptInputString:(NSString*)str;
- (void)setPreviousInputString:(NSString*)str;
- (void)addInputString:(NSString*)str;
- (void)setInputString:(NSString*)str;
- (BOOL)shouldEnableShiftForDeletedCharacter:(unichar)chr;

- (void)updateLayoutAndSetShift;
- (void)handleDeleteWithZeroInputCount;
- (void)handleDeleteWithNonZeroInputCount;
- (void)deleteFromInput;

- (void)acceptAutocorrection;
- (void)acceptCandidate:(CandWord*)cand atIndex:(NSUInteger)idx;
- (void)acceptCurrentCandidate;
- (void)acceptCurrentCandidateIfSelected;
- (void)showNextCandidates;
- (void)candidateListAcceptCandidate:(CandWord*)cand;
- (void)candidateListSelectionDidChange:(id)fp8;
- (NSArray*)candidateList;

- (void)clearInput;
- (void)setInputObject:(id)obj;
- (void)addInputObject:(id)obj;
- (void)clearTransientState;
- (void)clearAnimations;

- (void)acceptWord:(id)fp8 firstDelete:(unsigned int)fp12 addString:(id)fp16;
- (BOOL)_shouldSuggestUserEnteredString:(id)fp8;
- (BOOL)displaysCandidates;
- (void)updateCandidateDisplayAsyncWithCandidates:(id)fp8 forInputManager:(id)fp12;
- (void)updateCandidateDisplay;
- (void)setAutocorrection:(id)fp8;
- (id)autocorrectPrompt;
- (void)removeAutocorrectPrompt;
- (void)setCandidates:(id)fp8;
@property(readonly) UIReturnKeyType returnKeyType;
@property(assign) BOOL returnKeyEnabled;
- (void)updateReturnKey;
- (void)updateReturnKey:(BOOL)fp8;
- (id)automaticallySelectedOverlay;
- (id)inputOverlayContainer;
- (void)updateTextCandidateView;
- (CGRect)convertRectToAutocorrectRect:(CGRect)rect delegateView:(id)fp24 container:(id)fp28;
- (void)touchAutocorrectPromptTimer;
- (void)clearAutocorrectPromptTimer;
- (void)updateAutocorrectPromptAction;
- (void)updateAutocorrectPrompt:(id)fp8;
- (void)animateAutocorrection;
- (void)fadeAutocorrectPrompt;
- (void)autocorrectionAnimationDidStop:(id)fp8 finished:(id)fp12 context:(void *)fp16;
- (void)delegateSuggestionsForCurrentInput;
- (void)generateCandidates:(BOOL)fp8;
- (BOOL)shouldChargeKeys;
- (CFDictionaryRef)chargedKeyProbabilities;
- (void)touchAutoDeleteTimerWithThreshold:(NSTimeInterval)fp8;
- (void)autoDeleteTimerFired:(id)fp8;
- (void)startAutoDeleteTimer;
- (void)stopAutoDelete;
- (void)touchLongPressTimerWithDelay:(NSTimeInterval)fp8;
- (void)touchLongPressTimer;
- (void)clearLongPressTimer;
- (void)longPressAction;
- (BOOL)isLongPress;
- (void)clearTimers;
- (void)clearChangeTimeAndCount;
- (void)updateChangeTimeAndIncrementCount;
- (int)changeCount;
- (void)setAnotherTouchWaiting:(BOOL)fp8;
- (void)handleHardwareKeyDownFromSimulator:(struct __GSEvent *)fp8;
- (void)timeMark:(unsigned int)fp8 message:(id)fp12;
- (void)timeMark:(unsigned int)fp8;
- (void)timeElapsed:(unsigned int)fp8 message:(id)fp12;
- (BOOL)canHandleKeyHitTest;
- (void)clearKeyAreas;
- (void)registerKeyArea:(CGPoint)fp8 withRadii:(CGPoint)fp16 forKeyCode:(unichar)fp24 forLowerKey:(NSString*)fp28 forUpperKey:(NSString*)fp32;
- (int)keyHitTest:(CGPoint)fp8 touchStage:(int)fp16 atTime:(NSTimeInterval)fp20 withPathInfo:(PathInfo*)fp28 forceShift:(BOOL)fp32;
- (BOOL)keySlidIntoSwipe;

@end
