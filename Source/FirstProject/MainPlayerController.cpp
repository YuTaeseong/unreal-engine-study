// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"
#include "Blueprint/UserWidget.h"

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (HUDOverlayAsset) {
		HUDDOverlay = CreateWidget<UUserWidget>(this, HUDOverlayAsset);
	}
	HUDDOverlay->AddToViewport();
	HUDDOverlay->SetVisibility(ESlateVisibility::Visible);
}
 