// Copyright 2023 Naotsun. All Rights Reserved.

#include "AssetDowngrader/Utilities/AssetDowngraderUtils.h"

namespace AssetDowngrader
{
	DEFINE_LOG_CATEGORY_STATIC(LogAssetDowngraderTest, All, All);
	static FAutoConsoleCommand Test
	(
		TEXT("AssetDowngrader.Test"),
		TEXT(""),
		FConsoleCommandDelegate::CreateLambda(
			[]()
			{
				TMap<FString, FString> CustomVersionGuids = FAssetDowngraderUtils::GetCustomVersionGuids();
				for (const auto& Pair : CustomVersionGuids)
				{
					const FString& FriendlyName = Pair.Key;
					const FString& Guid = Pair.Value;
					UE_LOG(LogAssetDowngraderTest, Warning, TEXT("%s {%s}"), *FriendlyName, *Guid);
				}
			}
		)
	);
	
	TMap<FString, FString> FAssetDowngraderUtils::GetCustomVersionGuids()
	{
		TMap<FString, FString> CustomVersionGuids;
		
		const FCustomVersionArray& CustomVersions = FCurrentCustomVersions::GetAll().GetAllVersions();
		CustomVersionGuids.Reserve(CustomVersions.Num());
		for (const auto& CustomVersion : CustomVersions)
		{
			const FString& FriendlyName = CustomVersion.GetFriendlyName().ToString();
			const FString& Guid = CustomVersion.Key.ToString();
			CustomVersionGuids.Emplace(FriendlyName, Guid);
		}

		return CustomVersionGuids;
	}

	TArray<uint8> FAssetDowngraderUtils::FlipEndianness(const TArray<uint8>& BytesToFlip)
	{
		check(BytesToFlip.Num() == 16);
		
		TArray<uint8> ProcessedBytes;
		ProcessedBytes.SetNumZeroed(16);

		int32 ByteIndex = 0;
		for (int32 Chunk = 0; Chunk < 4; Chunk++)
		{
			for (int32 ReverseOrder = 3; ReverseOrder >= 0; ReverseOrder--)
			{
				ProcessedBytes[ByteIndex] = BytesToFlip[Chunk * 4 + ReverseOrder];
				ByteIndex++;
			}
		}
		
		return ProcessedBytes;
	}

	TArray<uint8> FAssetDowngraderUtils::BuildVersionBytes(const uint16 MajorVersion, const uint32 MinorVersion, const uint32 ChangeList)
	{
		TArray<uint8> BuiltVersionBytes;

		BuiltVersionBytes.Add(static_cast<uint8>(MajorVersion & 0xFF));
		BuiltVersionBytes.Add(static_cast<uint8>((MajorVersion >> 8) & 0xFF));
		BuiltVersionBytes.Add(static_cast<uint8>(MinorVersion & 0xFF));
		BuiltVersionBytes.Add(static_cast<uint8>((MinorVersion >> 8) & 0xFF));
		BuiltVersionBytes.Add(static_cast<uint8>((MinorVersion >> 16) & 0xFF));
		BuiltVersionBytes.Add(static_cast<uint8>((MinorVersion >> 24) & 0xFF));
		BuiltVersionBytes.Add(static_cast<uint8>(ChangeList & 0xFF));
		BuiltVersionBytes.Add(static_cast<uint8>((ChangeList >> 8) & 0xFF));
		BuiltVersionBytes.Add(static_cast<uint8>((ChangeList >> 16) & 0xFF));
		BuiltVersionBytes.Add(static_cast<uint8>((ChangeList >> 24) & 0xFF));
		
		return BuiltVersionBytes;
	}
}
