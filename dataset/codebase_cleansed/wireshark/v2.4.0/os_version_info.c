static char *
get_string_from_dictionary(CFPropertyListRef dict, CFStringRef key)
{
CFStringRef cfstring;
cfstring = (CFStringRef)CFDictionaryGetValue((CFDictionaryRef)dict,
(const void *)key);
if (cfstring == NULL)
return NULL;
if (CFGetTypeID(cfstring) != CFStringGetTypeID()) {
return NULL;
}
return CFString_to_C_string(cfstring);
}
static gboolean
get_macos_version_info(GString *str)
{
static const UInt8 server_version_plist_path[] =
"/System/Library/CoreServices/ServerVersion.plist";
static const UInt8 system_version_plist_path[] =
"/System/Library/CoreServices/SystemVersion.plist";
CFURLRef version_plist_file_url;
CFReadStreamRef version_plist_stream;
CFDictionaryRef version_dict;
char *string;
version_plist_file_url = CFURLCreateFromFileSystemRepresentation(NULL,
server_version_plist_path, sizeof server_version_plist_path - 1,
false);
if (version_plist_file_url == NULL)
return FALSE;
version_plist_stream = CFReadStreamCreateWithFile(NULL,
version_plist_file_url);
CFRelease(version_plist_file_url);
if (version_plist_stream == NULL)
return FALSE;
if (!CFReadStreamOpen(version_plist_stream)) {
CFRelease(version_plist_stream);
version_plist_file_url = CFURLCreateFromFileSystemRepresentation(NULL,
system_version_plist_path, sizeof system_version_plist_path - 1,
false);
if (version_plist_file_url == NULL)
return FALSE;
version_plist_stream = CFReadStreamCreateWithFile(NULL,
version_plist_file_url);
CFRelease(version_plist_file_url);
if (version_plist_stream == NULL)
return FALSE;
if (!CFReadStreamOpen(version_plist_stream)) {
CFRelease(version_plist_stream);
return FALSE;
}
}
#ifdef HAVE_CFPROPERTYLISTCREATEWITHSTREAM
version_dict = (CFDictionaryRef)CFPropertyListCreateWithStream(NULL,
version_plist_stream, 0, kCFPropertyListImmutable,
NULL, NULL);
#else
version_dict = (CFDictionaryRef)CFPropertyListCreateFromStream(NULL,
version_plist_stream, 0, kCFPropertyListImmutable,
NULL, NULL);
#endif
if (version_dict == NULL) {
CFRelease(version_plist_stream);
return FALSE;
}
if (CFGetTypeID(version_dict) != CFDictionaryGetTypeID()) {
CFRelease(version_dict);
CFReadStreamClose(version_plist_stream);
CFRelease(version_plist_stream);
return FALSE;
}
string = get_string_from_dictionary(version_dict,
CFSTR("ProductName"));
if (string == NULL) {
CFRelease(version_dict);
CFReadStreamClose(version_plist_stream);
CFRelease(version_plist_stream);
return FALSE;
}
g_string_append_printf(str, "%s", string);
g_free(string);
string = get_string_from_dictionary(version_dict,
CFSTR("ProductUserVisibleVersion"));
if (string == NULL) {
CFRelease(version_dict);
CFReadStreamClose(version_plist_stream);
CFRelease(version_plist_stream);
return FALSE;
}
g_string_append_printf(str, " %s", string);
g_free(string);
string = get_string_from_dictionary(version_dict,
CFSTR("ProductBuildVersion"));
if (string == NULL) {
CFRelease(version_dict);
CFReadStreamClose(version_plist_stream);
CFRelease(version_plist_stream);
return FALSE;
}
g_string_append_printf(str, ", build %s", string);
g_free(string);
CFRelease(version_dict);
CFReadStreamClose(version_plist_stream);
CFRelease(version_plist_stream);
return TRUE;
}
void
get_os_version_info(GString *str)
{
#if defined(_WIN32)
HMODULE kernel_dll_handle;
OSVERSIONINFOEX info;
SYSTEM_INFO system_info;
nativesi_func_ptr nativesi_func;
#elif defined(HAVE_SYS_UTSNAME_H)
struct utsname name;
#endif
#if defined(_WIN32)
memset(&info, '\0', sizeof info);
info.dwOSVersionInfoSize = sizeof info;
if (!GetVersionEx((OSVERSIONINFO *)&info)) {
g_string_append(str, "unknown Windows version");
return;
}
memset(&system_info, '\0', sizeof system_info);
kernel_dll_handle = GetModuleHandle(_T("kernel32.dll"));
if (kernel_dll_handle == NULL) {
g_string_append(str, "unknown Windows version");
return;
}
nativesi_func = (nativesi_func_ptr)GetProcAddress(kernel_dll_handle, "GetNativeSystemInfo");
if(nativesi_func)
nativesi_func(&system_info);
else
GetSystemInfo(&system_info);
switch (info.dwPlatformId) {
case VER_PLATFORM_WIN32s:
g_string_append_printf(str, "Windows 3.1 with Win32s");
break;
case VER_PLATFORM_WIN32_WINDOWS:
switch (info.dwMajorVersion) {
case 4:
switch (info.dwMinorVersion) {
case 0:
g_string_append_printf(str, "Windows 95");
break;
case 10:
g_string_append_printf(str, "Windows 98");
break;
case 90:
g_string_append_printf(str, "Windows Me");
break;
default:
g_string_append_printf(str, "Windows OT, unknown version %lu.%lu",
info.dwMajorVersion, info.dwMinorVersion);
break;
}
break;
default:
g_string_append_printf(str, "Windows OT, unknown version %lu.%lu",
info.dwMajorVersion, info.dwMinorVersion);
break;
}
break;
case VER_PLATFORM_WIN32_NT:
switch (info.dwMajorVersion) {
case 3:
case 4:
g_string_append_printf(str, "Windows NT %lu.%lu",
info.dwMajorVersion, info.dwMinorVersion);
break;
case 5:
switch (info.dwMinorVersion) {
case 0:
g_string_append_printf(str, "Windows 2000");
break;
case 1:
g_string_append_printf(str, "Windows XP");
break;
case 2:
if ((info.wProductType == VER_NT_WORKSTATION) &&
(system_info.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)) {
g_string_append_printf(str, "Windows XP Professional x64 Edition");
} else {
g_string_append_printf(str, "Windows Server 2003");
if (system_info.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
g_string_append_printf(str, " x64 Edition");
}
break;
default:
g_string_append_printf(str, "Windows NT, unknown version %lu.%lu",
info.dwMajorVersion, info.dwMinorVersion);
break;
}
break;
case 6: {
gboolean is_nt_workstation;
if (system_info.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
g_string_append(str, "64-bit ");
else if (system_info.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL)
g_string_append(str, "32-bit ");
#ifndef VER_NT_WORKSTATION
#define VER_NT_WORKSTATION 0x01
is_nt_workstation = ((info.wReserved[1] & 0xff) == VER_NT_WORKSTATION);
#else
is_nt_workstation = (info.wProductType == VER_NT_WORKSTATION);
#endif
switch (info.dwMinorVersion) {
case 0:
g_string_append_printf(str, is_nt_workstation ? "Windows Vista" : "Windows Server 2008");
break;
case 1:
g_string_append_printf(str, is_nt_workstation ? "Windows 7" : "Windows Server 2008 R2");
break;
case 2:
g_string_append_printf(str, is_nt_workstation ? "Windows 8" : "Windows Server 2012");
break;
case 3:
g_string_append_printf(str, is_nt_workstation ? "Windows 8.1" : "Windows Server 2012 R2");
break;
default:
g_string_append_printf(str, "Windows NT, unknown version %lu.%lu",
info.dwMajorVersion, info.dwMinorVersion);
break;
}
break;
}
case 10: {
gboolean is_nt_workstation;
if (system_info.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64)
g_string_append(str, "64-bit ");
else if (system_info.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL)
g_string_append(str, "32-bit ");
is_nt_workstation = (info.wProductType == VER_NT_WORKSTATION);
switch (info.dwMinorVersion) {
case 0:
g_string_append_printf(str, is_nt_workstation ? "Windows 10" : "Windows Server 2016");
break;
default:
g_string_append_printf(str, "Windows NT, unknown version %lu.%lu",
info.dwMajorVersion, info.dwMinorVersion);
break;
}
break;
}
default:
g_string_append_printf(str, "Windows NT, unknown version %lu.%lu",
info.dwMajorVersion, info.dwMinorVersion);
break;
}
break;
default:
g_string_append_printf(str, "Unknown Windows platform %lu version %lu.%lu",
info.dwPlatformId, info.dwMajorVersion, info.dwMinorVersion);
break;
}
if (info.szCSDVersion[0] != '\0')
g_string_append_printf(str, " %s", utf_16to8(info.szCSDVersion));
g_string_append_printf(str, ", build %lu", info.dwBuildNumber);
#elif defined(HAVE_SYS_UTSNAME_H)
if (uname(&name) < 0) {
g_string_append_printf(str, "unknown OS version (uname failed - %s)",
g_strerror(errno));
return;
}
if (strcmp(name.sysname, "AIX") == 0) {
g_string_append_printf(str, "%s %s.%s", name.sysname, name.version,
name.release);
} else {
#ifdef HAVE_MACOS_FRAMEWORKS
if (get_macos_version_info(str)) {
g_string_append_printf(str, " (%s %s)", name.sysname, name.release);
} else {
g_string_append_printf(str, "%s %s", name.sysname, name.release);
}
#else
g_string_append_printf(str, "%s %s", name.sysname, name.release);
#endif
}
#else
g_string_append(str, "an unknown OS");
#endif
}
guint32
get_windows_major_version(void)
{
OSVERSIONINFO info;
info.dwOSVersionInfoSize = sizeof info;
if (GetVersionEx(&info)) {
return info.dwMajorVersion;
}
return 0;
}
