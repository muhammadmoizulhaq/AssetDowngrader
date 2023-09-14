// Copyright 2023 Naotsun. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

namespace AssetDowngrader
{
	/**
	 * A utility class that defines utility functions used in this plugin.
	 */
	class ASSETDOWNGRADER_API FAssetDowngraderUtils
	{
	public:
		// Returns the names and guids of all custom versions.
		static TMap<FString, FString> GetCustomVersionGuids();

		// Returns the specified byte data with the byte order reversed.
		// The size of the specified byte data must be 16.
		static TArray<uint8> FlipEndianness(const TArray<uint8>& BytesToFlip);

		// Constructs byte data with the specified version information.
		static TArray<uint8> BuildVersionBytes(const uint16 MajorVersion, const uint32 MinorVersion, const uint32 ChangeList);
	};
}
