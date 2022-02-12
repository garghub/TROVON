static void
end_string(GString *str)
{
size_t point;
char *p, *q;
point = str->len;
if (point == 0 || str->str[point - 1] != '\n')
g_string_append(str, "\n");
p = str->str;
while (*p != '\0') {
q = strchr(p, '\n');
if (q - p > 80) {
q = p + 80;
while (q > p && *q != ' ')
q--;
if (q != p)
*q = '\n';
}
p = q + 1;
}
}
void
get_compiled_version_info(GString *str, void (*prepend_info)(GString *),
void (*append_info)(GString *))
{
if (sizeof(str) == 4)
g_string_append(str, "(32-bit) ");
else
g_string_append(str, "(64-bit) ");
if (prepend_info)
(*prepend_info)(str);
g_string_append(str, "with ");
g_string_append_printf(str,
#ifdef GLIB_MAJOR_VERSION
"GLib %d.%d.%d", GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION,
GLIB_MICRO_VERSION);
#else
"GLib (version unknown)");
void get_os_version_info(GString *str)
{
#if defined(_WIN32)
OSVERSIONINFOEX info;
SYSTEM_INFO system_info;
nativesi_func_ptr nativesi_func;
#elif defined(HAVE_SYS_UTSNAME_H)
struct utsname name;
#endif
#if HAVE_OS_X_FRAMEWORKS
SInt32 macosx_ver, macosx_major_ver, macosx_minor_ver, macosx_bugfix_ver;
#endif
#if defined(_WIN32)
memset(&info, '\0', sizeof info);
info.dwOSVersionInfoSize = sizeof info;
if (!GetVersionEx((OSVERSIONINFO *)&info)) {
g_string_append(str, "unknown Windows version");
return;
}
memset(&system_info, '\0', sizeof system_info);
nativesi_func = (nativesi_func_ptr)GetProcAddress(GetModuleHandle(_T("kernel32.dll")), "GetNativeSystemInfo");
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
#ifdef HAVE_OS_X_FRAMEWORKS
Gestalt(gestaltSystemVersion, &macosx_ver);
if(macosx_ver >= 0x1040) {
Gestalt(gestaltSystemVersionMajor, &macosx_major_ver);
Gestalt(gestaltSystemVersionMinor, &macosx_minor_ver);
Gestalt(gestaltSystemVersionBugFix, &macosx_bugfix_ver);
g_string_append_printf(str, "Mac OS %ld.%ld.%ld",
(long)macosx_major_ver,
(long)macosx_minor_ver,
(long)macosx_bugfix_ver);
} else {
g_string_append_printf(str, "Mac OS X < 10.4 [%lx]",
(long)macosx_ver);
}
g_string_append_printf(str, " (%s %s)", name.sysname, name.release);
#else
g_string_append_printf(str, "%s %s", name.sysname, name.release);
#endif
}
#else
g_string_append(str, "an unknown OS");
#endif
}
void
get_runtime_version_info(GString *str, void (*additional_info)(GString *))
{
#ifndef _WIN32
gchar *lang;
#endif
g_string_append(str, "on ");
get_os_version_info(str);
#ifndef _WIN32
if ((lang = getenv ("LANG")) != NULL)
g_string_append_printf(str, ", with locale %s", lang);
else
g_string_append(str, ", without locale");
#endif
g_string_append(str, ", ");
get_runtime_pcap_version(str);
#if defined(HAVE_LIBZ) && !defined(_WIN32)
g_string_append_printf(str, ", with libz %s", zlibVersion());
#endif
if (additional_info)
(*additional_info)(str);
g_string_append(str, ".");
#if defined(__GNUC__) && defined(__VERSION__)
#if defined(__clang__)
g_string_append_printf(str, "\n\nBuilt using clang %s.\n", __VERSION__);
#elif defined(__llvm__)
g_string_append_printf(str, "\n\nBuilt using llvm-gcc %s.\n", __VERSION__);
#else
g_string_append_printf(str, "\n\nBuilt using gcc %s.\n", __VERSION__);
#endif
#elif defined(__HP_aCC)
g_string_append_printf(str, "\n\nBuilt using HP aCC %d.\n", __HP_aCC);
#elif defined(__xlC__)
g_string_append_printf(str, "\n\nBuilt using IBM XL C %d.%d\n",
(__xlC__ >> 8) & 0xFF, __xlC__ & 0xFF);
#ifdef __IBMC__
if ((__IBMC__ % 10) != 0)
g_string_append_printf(str, " patch %d", __IBMC__ % 10);
#endif
g_string_append_printf(str, "\n");
#elif defined(__INTEL_COMPILER)
g_string_append_printf(str, "\n\nBuilt using Intel C %d.%d",
__INTEL_COMPILER / 100, (__INTEL_COMPILER / 10) % 10);
if ((__INTEL_COMPILER % 10) != 0)
g_string_append_printf(str, " patch %d", __INTEL_COMPILER % 10);
#ifdef __INTEL_COMPILER_BUILD_DATE
g_string_sprinta(str, ", compiler built %04d-%02d-%02d",
__INTEL_COMPILER_BUILD_DATE / 10000,
(__INTEL_COMPILER_BUILD_DATE / 100) % 100,
__INTEL_COMPILER_BUILD_DATE % 100);
#endif
g_string_append_printf(str, "\n");
#elif defined(_MSC_FULL_VER)
# if _MSC_FULL_VER > 99999999
g_string_append_printf(str, "\n\nBuilt using Microsoft Visual C++ %d.%d",
(_MSC_FULL_VER / 10000000) - 6,
(_MSC_FULL_VER / 100000) % 100);
# if (_MSC_FULL_VER % 100000) != 0
g_string_append_printf(str, " build %d",
_MSC_FULL_VER % 100000);
# endif
# else
g_string_append_printf(str, "\n\nBuilt using Microsoft Visual C++ %d.%d",
(_MSC_FULL_VER / 1000000) - 6,
(_MSC_FULL_VER / 10000) % 100);
# if (_MSC_FULL_VER % 10000) != 0
g_string_append_printf(str, " build %d",
_MSC_FULL_VER % 10000);
# endif
# endif
g_string_append_printf(str, "\n");
#elif defined(_MSC_VER)
g_string_append_printf(str, "\n\nBuilt using Microsoft Visual C++ %d.%d\n",
(_MSC_VER / 100) - 6, _MSC_VER % 100);
#elif defined(__SUNPRO_C)
g_string_append_printf(str, "\n\nBuilt using Sun C %d.%d",
(__SUNPRO_C >> 8) & 0xF, (__SUNPRO_C >> 4) & 0xF);
if ((__SUNPRO_C & 0xF) != 0)
g_string_append_printf(str, " patch %d", __SUNPRO_C & 0xF);
g_string_append_printf(str, "\n");
#endif
end_string(str);
}
const char *
get_copyright_info(void)
{
return
"Copyright 1998-2012 Gerald Combs <gerald@wireshark.org> and contributors.\n"
"This is free software; see the source for copying conditions. There is NO\n"
"warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n";
}
guint32
get_os_major_version()
{
OSVERSIONINFO info;
info.dwOSVersionInfoSize = sizeof info;
if (GetVersionEx(&info)) {
return info.dwMajorVersion;
}
return 0;
}
