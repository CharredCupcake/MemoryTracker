#pragma once
#include <iostream>

static struct MemoryTracker
{
	uint64_t allocatedMemory = 0;
	uint64_t deallocatedMemory = 0;

	static uint64_t currentMemoryUsage()
	{
		return MTinstance.allocatedMemory - MTinstance.deallocatedMemory;
	}

}MTinstance;

void* operator new(size_t size)
{
	MTinstance.allocatedMemory += size;
	return malloc(size);
}

void operator delete(void* memory, size_t size)
{
	MTinstance.deallocatedMemory += size;
	free(memory);
}
