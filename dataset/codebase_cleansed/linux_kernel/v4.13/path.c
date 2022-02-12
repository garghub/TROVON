static char *get_pathname(void)
{
static char pathname_array[4][PATH_MAX];
static int idx;
return pathname_array[3 & ++idx];
}
static char *cleanup_path(char *path)
{
if (!memcmp(path, "./", 2)) {
path += 2;
while (*path == '/')
path++;
}
return path;
}
char *mkpath(const char *fmt, ...)
{
va_list args;
unsigned len;
char *pathname = get_pathname();
va_start(args, fmt);
len = vsnprintf(pathname, PATH_MAX, fmt, args);
va_end(args);
if (len >= PATH_MAX)
return bad_path;
return cleanup_path(pathname);
}
int path__join(char *bf, size_t size, const char *path1, const char *path2)
{
return scnprintf(bf, size, "%s%s%s", path1, path1[0] ? "/" : "", path2);
}
int path__join3(char *bf, size_t size, const char *path1, const char *path2, const char *path3)
{
return scnprintf(bf, size, "%s%s%s%s%s", path1, path1[0] ? "/" : "",
path2, path2[0] ? "/" : "", path3);
}
bool is_regular_file(const char *file)
{
struct stat st;
if (stat(file, &st))
return false;
return S_ISREG(st.st_mode);
}
