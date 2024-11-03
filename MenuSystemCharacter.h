#pragma once

#include "CoreMinimal.h"
#include "OnlineSubsystem.h"
class MenuSystemCharacter
{
public:
	


	
	 MenuSystemCharacter();
	~MenuSystemCharacter();


	//只需用T共享指针将指针指向I在线会话
	TSharedPtr<class IOnlineSession,ESPMode::ThreadSafe> OnlineSessionInterface;

public:
	
};
