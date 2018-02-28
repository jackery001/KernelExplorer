#pragma once

enum class KExploreIoctls : ULONG { 
    GetExportedName			= CTL_CODE(FILE_DEVICE_UNKNOWN, 0x900, METHOD_BUFFERED, FILE_ANY_ACCESS),
    ReadMemory				= CTL_CODE(FILE_DEVICE_UNKNOWN, 0x901, METHOD_OUT_DIRECT, FILE_ANY_ACCESS),
    WriteMemory				= CTL_CODE(FILE_DEVICE_UNKNOWN, 0x902, METHOD_IN_DIRECT, FILE_ANY_ACCESS),
    EnumJobs				= CTL_CODE(FILE_DEVICE_UNKNOWN, 0x903, METHOD_BUFFERED, FILE_ANY_ACCESS),
    EnumChildJobs			= CTL_CODE(FILE_DEVICE_UNKNOWN, 0x904, METHOD_BUFFERED, FILE_ANY_ACCESS),
    OpenObject				= CTL_CODE(FILE_DEVICE_UNKNOWN, 0x905, METHOD_BUFFERED, FILE_ANY_ACCESS),
    ReadProcessMemory		= CTL_CODE(FILE_DEVICE_UNKNOWN, 0x906, METHOD_OUT_DIRECT, FILE_ANY_ACCESS),
    WriteProcessMemory		= CTL_CODE(FILE_DEVICE_UNKNOWN, 0x907, METHOD_IN_DIRECT, FILE_ANY_ACCESS),
    EnumProcesses			= CTL_CODE(FILE_DEVICE_UNKNOWN, 0x908, METHOD_BUFFERED, FILE_ANY_ACCESS),
    EnumThreads				= CTL_CODE(FILE_DEVICE_UNKNOWN, 0x909, METHOD_BUFFERED, FILE_ANY_ACCESS),
    EnumProcessThreads      = CTL_CODE(FILE_DEVICE_UNKNOWN, 0x909, METHOD_BUFFERED, FILE_ANY_ACCESS),
    InitKernelFunctions		= CTL_CODE(FILE_DEVICE_UNKNOWN, 0x90a, METHOD_BUFFERED, FILE_ANY_ACCESS),
    DereferenceObjects		= CTL_CODE(FILE_DEVICE_UNKNOWN, 0x90b, METHOD_BUFFERED, FILE_ANY_ACCESS),
    CloseHandle				= CTL_CODE(FILE_DEVICE_UNKNOWN, 0x90c, METHOD_BUFFERED, FILE_ANY_ACCESS),
	OpenProcess				= CTL_CODE(FILE_DEVICE_UNKNOWN, 0x90d, METHOD_BUFFERED, FILE_ANY_ACCESS),
	OpenThread				= CTL_CODE(FILE_DEVICE_UNKNOWN, 0x90e, METHOD_BUFFERED, FILE_ANY_ACCESS),
	EnumObjecs				= CTL_CODE(FILE_DEVICE_UNKNOWN, 0x90f, METHOD_OUT_DIRECT, FILE_ANY_ACCESS),
};

struct KernelObjectData {
	PVOID Address;
	HANDLE Handle;
};

struct OpenProcessData {
	ULONG ProcessId;
	ACCESS_MASK AccessMask;
};

struct OpenThreadData {
	ULONG ThreadId;
	ACCESS_MASK AccessMask;
};

struct OpenHandleData {
    PVOID Object;
    ACCESS_MASK AccessMask;
};

struct ReadWriteProcessMemoryData {
    ULONG ProcessId; 
    PVOID Address;
};

#ifndef KERNELDRIVER

struct KernelFunctions {
    PVOID PspGetNextJob;
    PVOID PsGetNextProcess;
};

#else

typedef PEJOB (*FPspGetNextJob)(PEJOB Job);
typedef PEPROCESS (*FPsGetNextProcess)(PEPROCESS Process);

struct KernelFunctions {
    FPspGetNextJob PspGetNextJob;
    FPsGetNextProcess PsGetNextProcess;
};

#endif
