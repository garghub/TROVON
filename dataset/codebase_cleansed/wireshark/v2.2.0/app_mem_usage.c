static gsize
win32_get_total_mem_used_by_app(void)
{
HANDLE pHandle;
PROCESS_MEMORY_COUNTERS pmc;
SIZE_T workingSize = 0;
pHandle = GetCurrentProcess();
if (GetProcessMemoryInfo(pHandle, &pmc, sizeof(pmc))){
workingSize = pmc.WorkingSetSize;
}
CloseHandle(pHandle);
if(workingSize == 0){
return -1;
}else{
return (int)workingSize;
}
}
static gboolean
linux_get_memory(gsize *ptotal, gsize *prss)
{
static int fd = -1;
static intptr_t pagesize = 0;
char buf[128];
unsigned long total, rss;
ssize_t ret;
if (!pagesize)
pagesize = sysconf(_SC_PAGESIZE);
if (pagesize == -1)
return FALSE;
if (fd < 0) {
char path[64];
g_snprintf(path, sizeof(path), "/proc/%d/statm", getpid());
fd = ws_open(path, O_RDONLY);
}
if (fd < 0)
return FALSE;
ret = pread(fd, buf, sizeof(buf)-1, 0);
if (ret <= 0)
return FALSE;
buf[ret] = '\0';
if (sscanf(buf, "%lu %lu", &total, &rss) != 2)
return FALSE;
if (ptotal)
*ptotal = pagesize * (gsize) total;
if (prss)
*prss = pagesize * (gsize) rss;
return TRUE;
}
static gsize
linux_get_total_mem_used_by_app(void)
{
gsize total;
if (!linux_get_memory(&total, NULL))
total = 0;
return total;
}
static gsize
linux_get_rss_mem_used_by_app(void)
{
gsize rss;
if (!linux_get_memory(NULL, &rss))
rss = 0;
return rss;
}
void
memory_usage_component_register(const ws_mem_usage_t *component)
{
if (memory_register_num >= MAX_COMPONENTS)
return;
memory_components[memory_register_num++] = component;
}
const char *
memory_usage_get(guint idx, gsize *value)
{
if (idx >= memory_register_num)
return NULL;
if (value)
*value = memory_components[idx]->fetch();
return memory_components[idx]->name;
}
void
memory_usage_gc(void)
{
guint i;
for (i = 0; i < memory_register_num; i++) {
if (memory_components[i]->gc)
memory_components[i]->gc();
}
}
