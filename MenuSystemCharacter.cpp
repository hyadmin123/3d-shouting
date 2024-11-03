#include "MenuSystemCharacter.h"

#include "Interfaces/OnlineSessionInterface.h"

MenuSystemCharacter::MenuSystemCharacter()
{
	IOnlineSubsystem * OnlineSubsystem = IOnlineSubsystem::Get();

	if (OnlineSubsystem)
	{
		OnlineSessionInterface = OnlineSubsystem->GetSessionInterface();
	}

	OnlineSessionInterface =  OnlineSubsystem->GetSessionInterface();
	//在UE中打印出来
	if (GEngine) //游戏运行时指向当前游戏世界的实例
	{
		    GEngine->AddOnScreenDebugMessage(
			-1,
			-15.f,
			FColor::Blue,
			FString::Printf(TEXT("Found subsystem %s"),*OnlineSubsystem->GetSubsystemName().ToString())
			);
	}

	
}