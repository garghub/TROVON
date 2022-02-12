void
get_cpu_info(GString *str)
{
guint32 CPUInfo[4];
char CPUBrandString[0x40];
unsigned nExIds;
if (!ws_cpuid(CPUInfo, 0x80000000))
return;
nExIds = CPUInfo[0];
if (nExIds<0x80000005)
return;
memset(CPUBrandString, 0, sizeof(CPUBrandString));
ws_cpuid(CPUInfo, 0x80000002);
memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
ws_cpuid(CPUInfo, 0x80000003);
memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
ws_cpuid(CPUInfo, 0x80000004);
memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
if (str->len > 0)
g_string_append(str, ", with ");
g_string_append_printf(str, "%s", CPUBrandString);
if (ws_cpuid_sse42())
g_string_append(str, " (with SSE4.2)");
}
