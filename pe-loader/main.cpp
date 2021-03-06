#include "stdafx.h"
#include "pe-loader.hpp"

extern "C" HMODULE load_library(const std::string& library, unsigned long process_id)
{
	HANDLE process_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, process_id);
	if (process_handle = INVALID_HANDLE_VALUE)
	{
		return NULL;
	}

	HMODULE module_handle = grr::pe_loader::load_library(library, process_handle);
	CloseHandle(process_handle);

	return module_handle;
}

extern "C" HMODULE load_memory_library(const void* source_image, HANDLE process_handle)
{
	return grr::pe_loader::load_memory_library(source_image, std::string(), process_handle);
}