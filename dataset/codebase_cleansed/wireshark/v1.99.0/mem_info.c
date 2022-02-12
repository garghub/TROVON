void
get_mem_info(GString *str _U_)
{
#ifdef _WIN32
MEMORYSTATUSEX statex;
statex.dwLength = sizeof (statex);
if (GlobalMemoryStatusEx(&statex))
g_string_append_printf(str, ", with ""%" G_GINT64_MODIFIER "d" "MB of physical memory.\n"
