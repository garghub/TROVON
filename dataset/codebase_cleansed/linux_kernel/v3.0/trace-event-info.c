static void die(const char *fmt, ...)
{
va_list ap;
int ret = errno;
if (errno)
perror("trace-cmd");
else
ret = -1;
va_start(ap, fmt);
fprintf(stderr, " ");
vfprintf(stderr, fmt, ap);
va_end(ap);
fprintf(stderr, "\n");
exit(ret);
}
void *malloc_or_die(unsigned int size)
{
void *data;
data = malloc(size);
if (!data)
die("malloc");
return data;
}
static const char *find_debugfs(void)
{
const char *path = debugfs_mount(NULL);
if (!path)
die("Your kernel not support debugfs filesystem");
return path;
}
static const char *find_tracing_dir(void)
{
static char *tracing;
static int tracing_found;
const char *debugfs;
if (tracing_found)
return tracing;
debugfs = find_debugfs();
tracing = malloc_or_die(strlen(debugfs) + 9);
sprintf(tracing, "%s/tracing", debugfs);
tracing_found = 1;
return tracing;
}
static char *get_tracing_file(const char *name)
{
const char *tracing;
char *file;
tracing = find_tracing_dir();
if (!tracing)
return NULL;
file = malloc_or_die(strlen(tracing) + strlen(name) + 2);
sprintf(file, "%s/%s", tracing, name);
return file;
}
static void put_tracing_file(char *file)
{
free(file);
}
static ssize_t write_or_die(const void *buf, size_t len)
{
int ret;
if (calc_data_size) {
calc_data_size += len;
return len;
}
ret = write(output_fd, buf, len);
if (ret < 0)
die("writing to '%s'", output_file);
return ret;
}
int bigendian(void)
{
unsigned char str[] = { 0x1, 0x2, 0x3, 0x4, 0x0, 0x0, 0x0, 0x0};
unsigned int *ptr;
ptr = (unsigned int *)(void *)str;
return *ptr == 0x01020304;
}
static unsigned long long copy_file_fd(int fd)
{
unsigned long long size = 0;
char buf[BUFSIZ];
int r;
do {
r = read(fd, buf, BUFSIZ);
if (r > 0) {
size += r;
write_or_die(buf, r);
}
} while (r > 0);
return size;
}
static unsigned long long copy_file(const char *file)
{
unsigned long long size = 0;
int fd;
fd = open(file, O_RDONLY);
if (fd < 0)
die("Can't read '%s'", file);
size = copy_file_fd(fd);
close(fd);
return size;
}
static unsigned long get_size_fd(int fd)
{
unsigned long long size = 0;
char buf[BUFSIZ];
int r;
do {
r = read(fd, buf, BUFSIZ);
if (r > 0)
size += r;
} while (r > 0);
lseek(fd, 0, SEEK_SET);
return size;
}
static unsigned long get_size(const char *file)
{
unsigned long long size = 0;
int fd;
fd = open(file, O_RDONLY);
if (fd < 0)
die("Can't read '%s'", file);
size = get_size_fd(fd);
close(fd);
return size;
}
static void read_header_files(void)
{
unsigned long long size, check_size;
char *path;
int fd;
path = get_tracing_file("events/header_page");
fd = open(path, O_RDONLY);
if (fd < 0)
die("can't read '%s'", path);
size = get_size_fd(fd);
write_or_die("header_page", 12);
write_or_die(&size, 8);
check_size = copy_file_fd(fd);
close(fd);
if (size != check_size)
die("wrong size for '%s' size=%lld read=%lld",
path, size, check_size);
put_tracing_file(path);
path = get_tracing_file("events/header_event");
fd = open(path, O_RDONLY);
if (fd < 0)
die("can't read '%s'", path);
size = get_size_fd(fd);
write_or_die("header_event", 13);
write_or_die(&size, 8);
check_size = copy_file_fd(fd);
if (size != check_size)
die("wrong size for '%s'", path);
put_tracing_file(path);
close(fd);
}
static bool name_in_tp_list(char *sys, struct tracepoint_path *tps)
{
while (tps) {
if (!strcmp(sys, tps->name))
return true;
tps = tps->next;
}
return false;
}
static void copy_event_system(const char *sys, struct tracepoint_path *tps)
{
unsigned long long size, check_size;
struct dirent *dent;
struct stat st;
char *format;
DIR *dir;
int count = 0;
int ret;
dir = opendir(sys);
if (!dir)
die("can't read directory '%s'", sys);
while ((dent = readdir(dir))) {
if (dent->d_type != DT_DIR ||
strcmp(dent->d_name, ".") == 0 ||
strcmp(dent->d_name, "..") == 0 ||
!name_in_tp_list(dent->d_name, tps))
continue;
format = malloc_or_die(strlen(sys) + strlen(dent->d_name) + 10);
sprintf(format, "%s/%s/format", sys, dent->d_name);
ret = stat(format, &st);
free(format);
if (ret < 0)
continue;
count++;
}
write_or_die(&count, 4);
rewinddir(dir);
while ((dent = readdir(dir))) {
if (dent->d_type != DT_DIR ||
strcmp(dent->d_name, ".") == 0 ||
strcmp(dent->d_name, "..") == 0 ||
!name_in_tp_list(dent->d_name, tps))
continue;
format = malloc_or_die(strlen(sys) + strlen(dent->d_name) + 10);
sprintf(format, "%s/%s/format", sys, dent->d_name);
ret = stat(format, &st);
if (ret >= 0) {
size = get_size(format);
write_or_die(&size, 8);
check_size = copy_file(format);
if (size != check_size)
die("error in size of file '%s'", format);
}
free(format);
}
closedir(dir);
}
static void read_ftrace_files(struct tracepoint_path *tps)
{
char *path;
path = get_tracing_file("events/ftrace");
copy_event_system(path, tps);
put_tracing_file(path);
}
static bool system_in_tp_list(char *sys, struct tracepoint_path *tps)
{
while (tps) {
if (!strcmp(sys, tps->system))
return true;
tps = tps->next;
}
return false;
}
static void read_event_files(struct tracepoint_path *tps)
{
struct dirent *dent;
struct stat st;
char *path;
char *sys;
DIR *dir;
int count = 0;
int ret;
path = get_tracing_file("events");
dir = opendir(path);
if (!dir)
die("can't read directory '%s'", path);
while ((dent = readdir(dir))) {
if (dent->d_type != DT_DIR ||
strcmp(dent->d_name, ".") == 0 ||
strcmp(dent->d_name, "..") == 0 ||
strcmp(dent->d_name, "ftrace") == 0 ||
!system_in_tp_list(dent->d_name, tps))
continue;
count++;
}
write_or_die(&count, 4);
rewinddir(dir);
while ((dent = readdir(dir))) {
if (dent->d_type != DT_DIR ||
strcmp(dent->d_name, ".") == 0 ||
strcmp(dent->d_name, "..") == 0 ||
strcmp(dent->d_name, "ftrace") == 0 ||
!system_in_tp_list(dent->d_name, tps))
continue;
sys = malloc_or_die(strlen(path) + strlen(dent->d_name) + 2);
sprintf(sys, "%s/%s", path, dent->d_name);
ret = stat(sys, &st);
if (ret >= 0) {
write_or_die(dent->d_name, strlen(dent->d_name) + 1);
copy_event_system(sys, tps);
}
free(sys);
}
closedir(dir);
put_tracing_file(path);
}
static void read_proc_kallsyms(void)
{
unsigned int size, check_size;
const char *path = "/proc/kallsyms";
struct stat st;
int ret;
ret = stat(path, &st);
if (ret < 0) {
size = 0;
write_or_die(&size, 4);
return;
}
size = get_size(path);
write_or_die(&size, 4);
check_size = copy_file(path);
if (size != check_size)
die("error in size of file '%s'", path);
}
static void read_ftrace_printk(void)
{
unsigned int size, check_size;
char *path;
struct stat st;
int ret;
path = get_tracing_file("printk_formats");
ret = stat(path, &st);
if (ret < 0) {
size = 0;
write_or_die(&size, 4);
goto out;
}
size = get_size(path);
write_or_die(&size, 4);
check_size = copy_file(path);
if (size != check_size)
die("error in size of file '%s'", path);
out:
put_tracing_file(path);
}
static struct tracepoint_path *
get_tracepoints_path(struct list_head *pattrs)
{
struct tracepoint_path path, *ppath = &path;
struct perf_evsel *pos;
int nr_tracepoints = 0;
list_for_each_entry(pos, pattrs, node) {
if (pos->attr.type != PERF_TYPE_TRACEPOINT)
continue;
++nr_tracepoints;
ppath->next = tracepoint_id_to_path(pos->attr.config);
if (!ppath->next)
die("%s\n", "No memory to alloc tracepoints list");
ppath = ppath->next;
}
return nr_tracepoints > 0 ? path.next : NULL;
}
bool have_tracepoints(struct list_head *pattrs)
{
struct perf_evsel *pos;
list_for_each_entry(pos, pattrs, node)
if (pos->attr.type == PERF_TYPE_TRACEPOINT)
return true;
return false;
}
int read_tracing_data(int fd, struct list_head *pattrs)
{
char buf[BUFSIZ];
struct tracepoint_path *tps = get_tracepoints_path(pattrs);
if (tps == NULL)
return -1;
output_fd = fd;
buf[0] = 23;
buf[1] = 8;
buf[2] = 68;
memcpy(buf + 3, "tracing", 7);
write_or_die(buf, 10);
write_or_die(VERSION, strlen(VERSION) + 1);
if (bigendian())
buf[0] = 1;
else
buf[0] = 0;
write_or_die(buf, 1);
buf[0] = sizeof(long);
write_or_die(buf, 1);
page_size = sysconf(_SC_PAGESIZE);
write_or_die(&page_size, 4);
read_header_files();
read_ftrace_files(tps);
read_event_files(tps);
read_proc_kallsyms();
read_ftrace_printk();
return 0;
}
ssize_t read_tracing_data_size(int fd, struct list_head *pattrs)
{
ssize_t size;
int err = 0;
calc_data_size = 1;
err = read_tracing_data(fd, pattrs);
size = calc_data_size - 1;
calc_data_size = 0;
if (err < 0)
return err;
return size;
}
