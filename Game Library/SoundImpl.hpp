//
//  SoundImpl.hpp
//  Game Framework
//
//  Created by numata on July 24, 2009.
//  Copyright (c) 2009-2016 Satoshi Numata. All rights reserved.
//

#import <AudioToolbox/AudioToolbox.h>
#import <Foundation/Foundation.h>
#import <OpenAL/al.h>
#import <OpenAL/alc.h>


void __InitOpenAL();
void __CleanUpOpenAL();


@interface SoundImpl : NSObject {
    float*  mAudioBuffer;
    
    ALsizei mDataSize;
    ALuint  mALBuffer;
    ALuint  mALSource;
    ALsizei mSampleRate;
    ALenum  mOutputFormat;
    
    ALfloat mSourcePos[3];
    
    float   mVolume;
    float   mPitch;
}

+ (float)listenerHorizontalOrientation;
+ (void)setListenerHorizontalOrientation:(float)radAngle;

+ (void)getListenerX:(float*)x y:(float*)y z:(float*)z;
+ (void)setListenerX:(float)x y:(float)y z:(float)z;

- (id)initWithName:(NSString*)name doLoop:(BOOL)doLoop;

- (void)play;
- (void)pause;
- (void)stop;

- (BOOL)isPlaying;
- (BOOL)isPaused;

- (void)getSourceX:(float*)x y:(float*)y z:(float*)z;
- (void)setSourceX:(float)x y:(float)y z:(float)z;

- (float)pitch;
- (void)setPitch:(float)pitch;

- (float)volume;
- (void)setVolume:(float)volume;

@end

