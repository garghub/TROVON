bool tracefs_configured(void)
{
return tracefs_find_mountpoint() != NULL;
}
const char *tracefs_find_mountpoint(void)
{
const char *ret;
if (tracefs_found)
return (const char *)tracefs_mountpoint;
ret = find_mountpoint("tracefs", (long) TRACEFS_MAGIC,
tracefs_mountpoint, PATH_MAX + 1,
tracefs_known_mountpoints);
if (ret)
tracefs_found = true;
return ret;
}
char *tracefs_mount(const char *mountpoint)
{
if (tracefs_find_mountpoint())
goto out;
if (mountpoint == NULL) {
mountpoint = getenv(PERF_TRACEFS_ENVIRONMENT);
if (mountpoint == NULL)
mountpoint = TRACEFS_DEFAULT_PATH;
}
if (mount(NULL, mountpoint, "tracefs", 0, NULL) < 0)
return NULL;
tracefs_found = true;
strncpy(tracefs_mountpoint, mountpoint, sizeof(tracefs_mountpoint));
out:
return tracefs_mountpoint;
}
