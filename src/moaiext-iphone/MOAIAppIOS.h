// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef	MOAIAPPIOS_H
#define	MOAIAPPIOS_H

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <moaicore/moaicore.h>
#import <moaiext-iphone/ReachabilityListener.h>

//================================================================//
// MOAIAppIOS
//================================================================//
/**	@name	MOAIAppIOS
	@text	Wrapper for iPhone app delegate.

	@const	APP_OPENED_FROM_URL
	@const	ASYNC_NAME_RESOLVE
	@const	SESSION_START
	@const	SESSION_END
*/
class MOAIAppIOS :
	public MOAIGlobalClass < MOAIAppIOS, MOAILuaObject > {
private:

	enum {
		APP_OPENED_FROM_URL,
		ASYNC_NAME_RESOLVE,
		SESSION_START,
		SESSION_END,
		TOTAL,
	};
		
	enum {
		DOMAIN_DOCUMENTS   = NSDocumentDirectory,
		DOMAIN_APP_SUPPORT = NSApplicationSupportDirectory,
	};
	
	UIApplication*			mApplication;
	MOAILuaRef				mListeners [ TOTAL ];
	ReachabilityListener*	mReachabilityListener;

	//----------------------------------------------------------------//
	static int		_getDirectoryInDomain		( lua_State* L );
	static int		_setListener				( lua_State* L );

public:
	
	DECL_LUA_SINGLETON ( MOAIAppIOS )
	
	SET ( UIApplication*, Application, mApplication )
	
	//----------------------------------------------------------------//
	void		AppOpenedFromURL			( NSURL* url );
	void		DidResolveHostName			( NSString* hostname, cc8* ipAddress );
	void		DidStartSession				( bool resumed );
				MOAIAppIOS					();
				~MOAIAppIOS					();
	void		RegisterLuaClass			( MOAILuaState& state );
	void		WillEndSession				();
};

#endif