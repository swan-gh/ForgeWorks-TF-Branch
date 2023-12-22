#include "MemoryManager.h"

struct MMGR g_memManager;

void SetMMGR(struct MMGR const* p_mmgr)
{
	g_memManager = *p_mmgr;
}

void mmgrSetOwner(const char* file, const unsigned int line, const char* func)
{
	g_memManager.mmgrSetOwner(file, line, func);
}

void* mmgrAllocator(
	const char* sourceFile, const unsigned int sourceLine, const char* sourceFunc, const unsigned int allocationType, size_t alignment,
	size_t reportedSize)
{
	return g_memManager.mmgrAllocator(sourceFile,sourceLine,sourceFunc,allocationType,alignment,reportedSize);
}

void* mmgrReallocator(
	const char* sourceFile, const unsigned int sourceLine, const char* sourceFunc, const unsigned int reallocationType, size_t reportedSize,
	void* reportedAddress)
{
	return g_memManager.mmgrReallocator(sourceFile, sourceLine, sourceFunc, reallocationType, reportedSize, reportedAddress);
}

void mmgrDeallocator(
	const char* sourceFile, const unsigned int sourceLine, const char* sourceFunc, const unsigned int deallocationType,
	const void* reportedAddress)
{
	g_memManager.mmgrDeallocator(sourceFile, sourceLine, sourceFunc, deallocationType, reportedAddress);
}

bool mmgrValidateAddress(const void* reportedAddress)
{
	return g_memManager.mmgrValidateAddress(reportedAddress);
}

bool mmgrValidateAllocUnit(const sAllocUnit* allocUnit)
{
	return g_memManager.mmgrValidateAllocUnit(allocUnit);
}

bool mmgrValidateAllAllocUnits()
{
	return g_memManager.mmgrValidateAllAllocUnits();
}

unsigned int mmgrCalcUnused(const sAllocUnit* allocUnit)
{
	return g_memManager.mmgrCalcUnused(allocUnit);
}

unsigned int mmgrCalcAllUnused()
{
	return g_memManager.mmgrCalcAllUnused();
}

void mmgrSetExecutableName(const char* name, size_t length)
{

}

void mmgrSetLogFileDirectory(const char* directory)
{

}

void mmgrDumpAllocUnit(const sAllocUnit* allocUnit, const char* prefix)
{
	g_memManager.mmgrDumpAllocUnit(allocUnit, prefix);
}

void mmgrDumpMemoryReport(const char* filename, const bool overwrite)
{
	g_memManager.mmgrDumpMemoryReport(filename, overwrite);
}
