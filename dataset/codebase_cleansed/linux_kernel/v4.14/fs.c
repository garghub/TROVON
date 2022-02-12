static bool fs__read_mounts(struct fs *fs)
{
bool found = false;
char type[100];
FILE *fp;
fp = fopen("/proc/mounts", "r");
if (fp == NULL)
return NULL;
while (!found &&
fscanf(fp, "%*s %" STR(PATH_MAX) "s %99s %*s %*d %*d\n",
fs->path, type) == 2) {
if (strcmp(type, fs->name) == 0)
found = true;
}
fclose(fp);
return fs->found = found;
}
static int fs__valid_mount(const char *fs, long magic)
{
struct statfs st_fs;
if (statfs(fs, &st_fs) < 0)
return -ENOENT;
else if ((long)st_fs.f_type != magic)
return -ENOENT;
return 0;
}
static bool fs__check_mounts(struct fs *fs)
{
const char * const *ptr;
ptr = fs->mounts;
while (*ptr) {
if (fs__valid_mount(*ptr, fs->magic) == 0) {
fs->found = true;
strcpy(fs->path, *ptr);
return true;
}
ptr++;
}
return false;
}
static void mem_toupper(char *f, size_t len)
{
while (len) {
*f = toupper(*f);
f++;
len--;
}
}
static bool fs__env_override(struct fs *fs)
{
char *override_path;
size_t name_len = strlen(fs->name);
char upper_name[name_len + 5 + 1];
memcpy(upper_name, fs->name, name_len);
mem_toupper(upper_name, name_len);
strcpy(&upper_name[name_len], "_PATH");
override_path = getenv(upper_name);
if (!override_path)
return false;
fs->found = true;
strncpy(fs->path, override_path, sizeof(fs->path));
return true;
}
static const char *fs__get_mountpoint(struct fs *fs)
{
if (fs__env_override(fs))
return fs->path;
if (fs__check_mounts(fs))
return fs->path;
if (fs__read_mounts(fs))
return fs->path;
return NULL;
}
static const char *fs__mountpoint(int idx)
{
struct fs *fs = &fs__entries[idx];
if (fs->found)
return (const char *)fs->path;
return fs__get_mountpoint(fs);
}
static const char *mount_overload(struct fs *fs)
{
size_t name_len = strlen(fs->name);
char upper_name[5 + name_len + 12 + 1];
snprintf(upper_name, name_len, "PERF_%s_ENVIRONMENT", fs->name);
mem_toupper(upper_name, name_len);
return getenv(upper_name) ?: *fs->mounts;
}
static const char *fs__mount(int idx)
{
struct fs *fs = &fs__entries[idx];
const char *mountpoint;
if (fs__mountpoint(idx))
return (const char *)fs->path;
mountpoint = mount_overload(fs);
if (mount(NULL, mountpoint, fs->name, 0, NULL) < 0)
return NULL;
return fs__check_mounts(fs) ? fs->path : NULL;
}
int filename__read_int(const char *filename, int *value)
{
char line[64];
int fd = open(filename, O_RDONLY), err = -1;
if (fd < 0)
return -1;
if (read(fd, line, sizeof(line)) > 0) {
*value = atoi(line);
err = 0;
}
close(fd);
return err;
}
int filename__read_ull(const char *filename, unsigned long long *value)
{
char line[64];
int fd = open(filename, O_RDONLY), err = -1;
if (fd < 0)
return -1;
if (read(fd, line, sizeof(line)) > 0) {
*value = strtoull(line, NULL, 0);
if (*value != ULLONG_MAX)
err = 0;
}
close(fd);
return err;
}
int filename__read_str(const char *filename, char **buf, size_t *sizep)
{
size_t size = 0, alloc_size = 0;
void *bf = NULL, *nbf;
int fd, n, err = 0;
char sbuf[STRERR_BUFSIZE];
fd = open(filename, O_RDONLY);
if (fd < 0)
return -errno;
do {
if (size == alloc_size) {
alloc_size += BUFSIZ;
nbf = realloc(bf, alloc_size);
if (!nbf) {
err = -ENOMEM;
break;
}
bf = nbf;
}
n = read(fd, bf + size, alloc_size - size);
if (n < 0) {
if (size) {
pr_warning("read failed %d: %s\n", errno,
strerror_r(errno, sbuf, sizeof(sbuf)));
err = 0;
} else
err = -errno;
break;
}
size += n;
} while (n > 0);
if (!err) {
*sizep = size;
*buf = bf;
} else
free(bf);
close(fd);
return err;
}
int filename__write_int(const char *filename, int value)
{
int fd = open(filename, O_WRONLY), err = -1;
char buf[64];
if (fd < 0)
return err;
sprintf(buf, "%d", value);
if (write(fd, buf, sizeof(buf)) == sizeof(buf))
err = 0;
close(fd);
return err;
}
int procfs__read_str(const char *entry, char **buf, size_t *sizep)
{
char path[PATH_MAX];
const char *procfs = procfs__mountpoint();
if (!procfs)
return -1;
snprintf(path, sizeof(path), "%s/%s", procfs, entry);
return filename__read_str(path, buf, sizep);
}
int sysfs__read_ull(const char *entry, unsigned long long *value)
{
char path[PATH_MAX];
const char *sysfs = sysfs__mountpoint();
if (!sysfs)
return -1;
snprintf(path, sizeof(path), "%s/%s", sysfs, entry);
return filename__read_ull(path, value);
}
int sysfs__read_int(const char *entry, int *value)
{
char path[PATH_MAX];
const char *sysfs = sysfs__mountpoint();
if (!sysfs)
return -1;
snprintf(path, sizeof(path), "%s/%s", sysfs, entry);
return filename__read_int(path, value);
}
int sysfs__read_str(const char *entry, char **buf, size_t *sizep)
{
char path[PATH_MAX];
const char *sysfs = sysfs__mountpoint();
if (!sysfs)
return -1;
snprintf(path, sizeof(path), "%s/%s", sysfs, entry);
return filename__read_str(path, buf, sizep);
}
int sysfs__read_bool(const char *entry, bool *value)
{
char *buf;
size_t size;
int ret;
ret = sysfs__read_str(entry, &buf, &size);
if (ret < 0)
return ret;
switch (buf[0]) {
case '1':
case 'y':
case 'Y':
*value = true;
break;
case '0':
case 'n':
case 'N':
*value = false;
break;
default:
ret = -1;
}
free(buf);
return ret;
}
int sysctl__read_int(const char *sysctl, int *value)
{
char path[PATH_MAX];
const char *procfs = procfs__mountpoint();
if (!procfs)
return -1;
snprintf(path, sizeof(path), "%s/sys/%s", procfs, sysctl);
return filename__read_int(path, value);
}
int sysfs__write_int(const char *entry, int value)
{
char path[PATH_MAX];
const char *sysfs = sysfs__mountpoint();
if (!sysfs)
return -1;
if (snprintf(path, sizeof(path), "%s/%s", sysfs, entry) >= PATH_MAX)
return -1;
return filename__write_int(path, value);
}
