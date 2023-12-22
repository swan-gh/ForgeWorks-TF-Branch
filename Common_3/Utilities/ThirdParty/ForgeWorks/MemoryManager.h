#pragma once

#include "../OpenSource/FluidStudios/MemoryManager/mmgr.h"

#ifdef __cplusplus
extern "C"
{
#endif

struct MMGR
{
	void(* mmgrSetOwner)(const char* file, const unsigned int line, const char* func);
	bool*(* mmgrBreakOnRealloc)(void* reportedAddress);
	bool*(* mmgrBreakOnDealloc)(void* reportedAddress);
	void* (*mmgrAllocator)(
	const char* sourceFile, const unsigned int sourceLine, const char* sourceFunc, const unsigned int allocationType, size_t alignment,
	size_t reportedSize);
	void* (*mmgrReallocator)(
		const char* sourceFile, const unsigned int sourceLine, const char* sourceFunc, const unsigned int reallocationType,
		size_t reportedSize, void* reportedAddress);
	void (*mmgrDeallocator)(
		const char* sourceFile, const unsigned int sourceLine, const char* sourceFunc, const unsigned int deallocationType,
		const void* reportedAddress);
	bool (*mmgrValidateAddress)(const void* reportedAddress);
	bool (*mmgrValidateAllocUnit)(const sAllocUnit* allocUnit);
	bool (*mmgrValidateAllAllocUnits)(void);
	unsigned int (*mmgrCalcUnused)(const sAllocUnit* allocUnit);
	unsigned int (*mmgrCalcAllUnused)(void);
	void (*mmgrDumpAllocUnit)(const sAllocUnit* allocUnit, const char* prefix);
	void    (*mmgrDumpMemoryReport)(const char* filename, const bool overwrite);
	sMStats (*mmgrGetMemoryStatistics)(void);
};

void SetMMGR(struct MMGR const* p_mmgr);

#ifdef __cplusplus
}
#endif
