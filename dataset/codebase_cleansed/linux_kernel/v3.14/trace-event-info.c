int bigendian(void)
{
unsigned char str[] = { 0x1, 0x2, 0x3, 0x4, 0x0, 0x0, 0x0, 0x0};
unsigned int *ptr;
ptr = (unsigned int *)(void *)str;
return *ptr == 0x01020304;
}
static int record_file(const char *file, ssize_t hdr_sz)
{
unsigned long long size = 0;
char buf[BUFSIZ], *sizep;
off_t hdr_pos = lseek(output_fd, 0, SEEK_CUR);
int r, fd;
int err = -EIO;
fd = open(file, O_RDONLY);
if (fd < 0) {
pr_debug("Can't read '%s'", file);
return -errno;
}
if (hdr_sz) {
if (write(output_fd, &size, hdr_sz) != hdr_sz)
goto out;
}
do {
r = read(fd, buf, BUFSIZ);
if (r > 0) {
size += r;
if (write(output_fd, buf, r) != r)
goto out;
}
} while (r > 0);
sizep = (char*)&size;
if (bigendian())
sizep += sizeof(u64) - hdr_sz;
if (hdr_sz && pwrite(output_fd, sizep, hdr_sz, hdr_pos) < 0) {
pr_debug("writing file size failed\n");
goto out;
}
err = 0;
out:
close(fd);
return err;
}
static int record_header_files(void)
{
char *path;
struct stat st;
int err = -EIO;
path = get_tracing_file("events/header_page");
if (!path) {
pr_debug("can't get tracing/events/header_page");
return -ENOMEM;
}
if (stat(path, &st) < 0) {
pr_debug("can't read '%s'", path);
goto out;
}
if (write(output_fd, "header_page", 12) != 12) {
pr_debug("can't write header_page\n");
goto out;
}
if (record_file(path, 8) < 0) {
pr_debug("can't record header_page file\n");
goto out;
}
put_tracing_file(path);
path = get_tracing_file("events/header_event");
if (!path) {
pr_debug("can't get tracing/events/header_event");
err = -ENOMEM;
goto out;
}
if (stat(path, &st) < 0) {
pr_debug("can't read '%s'", path);
goto out;
}
if (write(output_fd, "header_event", 13) != 13) {
pr_debug("can't write header_event\n");
goto out;
}
if (record_file(path, 8) < 0) {
pr_debug("can't record header_event file\n");
goto out;
}
err = 0;
out:
put_tracing_file(path);
return err;
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
static int copy_event_system(const char *sys, struct tracepoint_path *tps)
{
struct dirent *dent;
struct stat st;
char *format;
DIR *dir;
int count = 0;
int ret;
int err;
dir = opendir(sys);
if (!dir) {
pr_debug("can't read directory '%s'", sys);
return -errno;
}
while ((dent = readdir(dir))) {
if (dent->d_type != DT_DIR ||
strcmp(dent->d_name, ".") == 0 ||
strcmp(dent->d_name, "..") == 0 ||
!name_in_tp_list(dent->d_name, tps))
continue;
format = malloc(strlen(sys) + strlen(dent->d_name) + 10);
if (!format) {
err = -ENOMEM;
goto out;
}
sprintf(format, "%s/%s/format", sys, dent->d_name);
ret = stat(format, &st);
free(format);
if (ret < 0)
continue;
count++;
}
if (write(output_fd, &count, 4) != 4) {
err = -EIO;
pr_debug("can't write count\n");
goto out;
}
rewinddir(dir);
while ((dent = readdir(dir))) {
if (dent->d_type != DT_DIR ||
strcmp(dent->d_name, ".") == 0 ||
strcmp(dent->d_name, "..") == 0 ||
!name_in_tp_list(dent->d_name, tps))
continue;
format = malloc(strlen(sys) + strlen(dent->d_name) + 10);
if (!format) {
err = -ENOMEM;
goto out;
}
sprintf(format, "%s/%s/format", sys, dent->d_name);
ret = stat(format, &st);
if (ret >= 0) {
err = record_file(format, 8);
if (err) {
free(format);
goto out;
}
}
free(format);
}
err = 0;
out:
closedir(dir);
return err;
}
static int record_ftrace_files(struct tracepoint_path *tps)
{
char *path;
int ret;
path = get_tracing_file("events/ftrace");
if (!path) {
pr_debug("can't get tracing/events/ftrace");
return -ENOMEM;
}
ret = copy_event_system(path, tps);
put_tracing_file(path);
return ret;
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
static int record_event_files(struct tracepoint_path *tps)
{
struct dirent *dent;
struct stat st;
char *path;
char *sys;
DIR *dir;
int count = 0;
int ret;
int err;
path = get_tracing_file("events");
if (!path) {
pr_debug("can't get tracing/events");
return -ENOMEM;
}
dir = opendir(path);
if (!dir) {
err = -errno;
pr_debug("can't read directory '%s'", path);
goto out;
}
while ((dent = readdir(dir))) {
if (dent->d_type != DT_DIR ||
strcmp(dent->d_name, ".") == 0 ||
strcmp(dent->d_name, "..") == 0 ||
strcmp(dent->d_name, "ftrace") == 0 ||
!system_in_tp_list(dent->d_name, tps))
continue;
count++;
}
if (write(output_fd, &count, 4) != 4) {
err = -EIO;
pr_debug("can't write count\n");
goto out;
}
rewinddir(dir);
while ((dent = readdir(dir))) {
if (dent->d_type != DT_DIR ||
strcmp(dent->d_name, ".") == 0 ||
strcmp(dent->d_name, "..") == 0 ||
strcmp(dent->d_name, "ftrace") == 0 ||
!system_in_tp_list(dent->d_name, tps))
continue;
sys = malloc(strlen(path) + strlen(dent->d_name) + 2);
if (!sys) {
err = -ENOMEM;
goto out;
}
sprintf(sys, "%s/%s", path, dent->d_name);
ret = stat(sys, &st);
if (ret >= 0) {
ssize_t size = strlen(dent->d_name) + 1;
if (write(output_fd, dent->d_name, size) != size ||
copy_event_system(sys, tps) < 0) {
err = -EIO;
free(sys);
goto out;
}
}
free(sys);
}
err = 0;
out:
closedir(dir);
put_tracing_file(path);
return err;
}
static int record_proc_kallsyms(void)
{
unsigned int size;
const char *path = "/proc/kallsyms";
struct stat st;
int ret, err = 0;
ret = stat(path, &st);
if (ret < 0) {
size = 0;
if (write(output_fd, &size, 4) != 4)
err = -EIO;
return err;
}
return record_file(path, 4);
}
static int record_ftrace_printk(void)
{
unsigned int size;
char *path;
struct stat st;
int ret, err = 0;
path = get_tracing_file("printk_formats");
if (!path) {
pr_debug("can't get tracing/printk_formats");
return -ENOMEM;
}
ret = stat(path, &st);
if (ret < 0) {
size = 0;
if (write(output_fd, &size, 4) != 4)
err = -EIO;
goto out;
}
err = record_file(path, 4);
out:
put_tracing_file(path);
return err;
}
static void
put_tracepoints_path(struct tracepoint_path *tps)
{
while (tps) {
struct tracepoint_path *t = tps;
tps = tps->next;
zfree(&t->name);
zfree(&t->system);
free(t);
}
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
if (pos->name) {
ppath->next = tracepoint_name_to_path(pos->name);
if (ppath->next)
goto next;
if (strchr(pos->name, ':') == NULL)
goto try_id;
goto error;
}
try_id:
ppath->next = tracepoint_id_to_path(pos->attr.config);
if (!ppath->next) {
error:
pr_debug("No memory to alloc tracepoints list\n");
put_tracepoints_path(&path);
return NULL;
}
next:
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
static int tracing_data_header(void)
{
char buf[20];
ssize_t size;
buf[0] = 23;
buf[1] = 8;
buf[2] = 68;
memcpy(buf + 3, "tracing", 7);
if (write(output_fd, buf, 10) != 10)
return -1;
size = strlen(VERSION) + 1;
if (write(output_fd, VERSION, size) != size)
return -1;
if (bigendian())
buf[0] = 1;
else
buf[0] = 0;
if (write(output_fd, buf, 1) != 1)
return -1;
buf[0] = sizeof(long);
if (write(output_fd, buf, 1) != 1)
return -1;
if (write(output_fd, &page_size, 4) != 4)
return -1;
return 0;
}
struct tracing_data *tracing_data_get(struct list_head *pattrs,
int fd, bool temp)
{
struct tracepoint_path *tps;
struct tracing_data *tdata;
int err;
output_fd = fd;
tps = get_tracepoints_path(pattrs);
if (!tps)
return NULL;
tdata = malloc(sizeof(*tdata));
if (!tdata)
return NULL;
tdata->temp = temp;
tdata->size = 0;
if (temp) {
int temp_fd;
snprintf(tdata->temp_file, sizeof(tdata->temp_file),
"/tmp/perf-XXXXXX");
if (!mkstemp(tdata->temp_file)) {
pr_debug("Can't make temp file");
return NULL;
}
temp_fd = open(tdata->temp_file, O_RDWR);
if (temp_fd < 0) {
pr_debug("Can't read '%s'", tdata->temp_file);
return NULL;
}
output_fd = temp_fd;
}
err = tracing_data_header();
if (err)
goto out;
err = record_header_files();
if (err)
goto out;
err = record_ftrace_files(tps);
if (err)
goto out;
err = record_event_files(tps);
if (err)
goto out;
err = record_proc_kallsyms();
if (err)
goto out;
err = record_ftrace_printk();
out:
if (temp) {
tdata->size = lseek(output_fd, 0, SEEK_CUR);
close(output_fd);
output_fd = fd;
}
if (err)
zfree(&tdata);
put_tracepoints_path(tps);
return tdata;
}
int tracing_data_put(struct tracing_data *tdata)
{
int err = 0;
if (tdata->temp) {
err = record_file(tdata->temp_file, 0);
unlink(tdata->temp_file);
}
free(tdata);
return err;
}
int read_tracing_data(int fd, struct list_head *pattrs)
{
int err;
struct tracing_data *tdata;
tdata = tracing_data_get(pattrs, fd, false);
if (!tdata)
return -ENOMEM;
err = tracing_data_put(tdata);
return err;
}
