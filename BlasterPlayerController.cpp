// #include "BlasterPlayerController.h"
// #include "BlasterPlayerController.h"
//
// #include "Components/ProgressBar.h"
// #include "Components/TextBlock.h"
//
// #include "Net/UnrealNetwork.h"
//
// #include "Kismet/GameplayStatics.h"
//
// #include "Components/Image.h"
//
//
// void ABlasterPlayerController::BroadcastElim(APlayerState* Attacker, APlayerState* Victim)
// {
// 	ClientElimAnnouncement(Attacker, Victim);
// }
//
//
// void ABlasterPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
// {
// 	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
//
// 	DOREPLIFETIME(ABlasterPlayerController, MatchState);
// 	DOREPLIFETIME(ABlasterPlayerController, bShowTeamScores);
// }
//
//
//
// void ABlasterPlayerController::Tick(float DeltaTime)
// {
// 	Super::Tick(DeltaTime);
//
// 	SetHUDTime();
// 	CheckTimeSync(DeltaTime);
// 	PollInit();
// 	CheckPing(DeltaTime);
// }
//
//
//
// void ABlasterPlayerController::OnRep_ShowTeamScores()
// {
// 	if (bShowTeamScores)
// 	{
// 		InitTeamScores();
// 	}
// 	else
// 	{
// 		HideTeamScores();
// 	}
// }
//
// // Is the ping too high?
// void ABlasterPlayerController::ServerReportPingStatus_Implementation(bool bHighPing)
// {
// 	HighPingDelegate.Broadcast(bHighPing);
// }
//
// void ABlasterPlayerController::CheckTimeSync(float DeltaTime)
// {
// 	TimeSyncRunningTime += DeltaTime;
// 	if (IsLocalController() && TimeSyncRunningTime > TimeSyncFrequency)
// 	{
// 		ServerRequestServerTime(GetWorld()->GetTimeSeconds());
// 		TimeSyncRunningTime = 0.f;
// 	}
// }
//
// void ABlasterPlayerController::SetupInputComponent()
// {
// 	Super::SetupInputComponent();
// 	if (InputComponent == nullptr) return;
//
// 	InputComponent->BindAction("Quit", IE_Pressed, this, &ABlasterPlayerController::ShowReturnToMainMenu);
//
// }
//
// void ABlasterPlayerController::ServerRequestServerTime_Implementation(float TimeOfClientRequest)
// {
// 	float ServerTimeOfReceipt = GetWorld()->GetTimeSeconds();
// 	ClientReportServerTime(TimeOfClientRequest, ServerTimeOfReceipt);
// }
//
// void ABlasterPlayerController::ClientReportServerTime_Implementation(float TimeOfClientRequest, float TimeServerReceivedClientRequest)
// {
// 	float RoundTripTime = GetWorld()->GetTimeSeconds() - TimeOfClientRequest;
// 	SingleTripTime = 0.5f * RoundTripTime;
// 	float CurrentServerTime = TimeServerReceivedClientRequest + SingleTripTime;
// 	ClientServerDelta = CurrentServerTime - GetWorld()->GetTimeSeconds();
// }
//
// float ABlasterPlayerController::GetServerTime()
// {
// 	if (HasAuthority()) return GetWorld()->GetTimeSeconds();
// 	else return GetWorld()->GetTimeSeconds() + ClientServerDelta;
// }
//
// void ABlasterPlayerController::ReceivedPlayer()
// {
// 	Super::ReceivedPlayer();
// 	if (IsLocalController())
// 	{
// 		ServerRequestServerTime(GetWorld()->GetTimeSeconds());
// 	}
// }
//
//
