static inline pid_t gettid(void)
{
return (pid_t)syscall(__NR_gettid);
}
static int get_e_machine(struct jitheader *hdr)
{
ssize_t sret;
char id[16];
int fd, ret = -1;
struct {
uint16_t e_type;
uint16_t e_machine;
} info;
fd = open("/proc/self/exe", O_RDONLY);
if (fd == -1)
return -1;
sret = read(fd, id, sizeof(id));
if (sret != sizeof(id))
goto error;
if (id[0] != 0x7f || id[1] != 'E' || id[2] != 'L' || id[3] != 'F')
goto error;
sret = read(fd, &info, sizeof(info));
if (sret != sizeof(info))
goto error;
hdr->elf_mach = info.e_machine;
ret = 0;
error:
close(fd);
return ret;
}
static inline uint64_t
get_arch_timestamp(void)
{
#if defined(__i386__) || defined(__x86_64__)
unsigned int low, high;
asm volatile("rdtsc" : "=a" (low), "=d" (high));
return low | ((uint64_t)high) << 32;
#else
return 0;
#endif
}
static inline uint64_t
timespec_to_ns(const struct timespec *ts)
{
return ((uint64_t) ts->tv_sec * NSEC_PER_SEC) + ts->tv_nsec;
}
static inline uint64_t
perf_get_timestamp(void)
{
struct timespec ts;
int ret;
if (use_arch_timestamp)
return get_arch_timestamp();
ret = clock_gettime(perf_clk_id, &ts);
if (ret)
return 0;
return timespec_to_ns(&ts);
}
static int
debug_cache_init(void)
{
char str[32];
char *base, *p;
struct tm tm;
time_t t;
int ret;
time(&t);
localtime_r(&t, &tm);
base = getenv("JITDUMPDIR");
if (!base)
base = getenv("HOME");
if (!base)
base = ".";
strftime(str, sizeof(str), JIT_LANG"-jit-%Y%m%d", &tm);
snprintf(jit_path, PATH_MAX - 1, "%s/.debug/", base);
ret = mkdir(jit_path, 0755);
if (ret == -1) {
if (errno != EEXIST) {
warn("jvmti: cannot create jit cache dir %s", jit_path);
return -1;
}
}
snprintf(jit_path, PATH_MAX - 1, "%s/.debug/jit", base);
ret = mkdir(jit_path, 0755);
if (ret == -1) {
if (errno != EEXIST) {
warn("cannot create jit cache dir %s", jit_path);
return -1;
}
}
snprintf(jit_path, PATH_MAX - 1, "%s/.debug/jit/%s.XXXXXXXX", base, str);
p = mkdtemp(jit_path);
if (p != jit_path) {
warn("cannot create jit cache dir %s", jit_path);
return -1;
}
return 0;
}
static int
perf_open_marker_file(int fd)
{
long pgsz;
pgsz = sysconf(_SC_PAGESIZE);
if (pgsz == -1)
return -1;
marker_addr = mmap(NULL, pgsz, PROT_READ|PROT_EXEC, MAP_PRIVATE, fd, 0);
return (marker_addr == MAP_FAILED) ? -1 : 0;
}
static void
perf_close_marker_file(void)
{
long pgsz;
if (!marker_addr)
return;
pgsz = sysconf(_SC_PAGESIZE);
if (pgsz == -1)
return;
munmap(marker_addr, pgsz);
}
static void
init_arch_timestamp(void)
{
char *str = getenv("JITDUMP_USE_ARCH_TIMESTAMP");
if (!str || !*str || !strcmp(str, "0"))
return;
use_arch_timestamp = 1;
}
void *jvmti_open(void)
{
char dump_path[PATH_MAX];
struct jitheader header;
int fd;
FILE *fp;
init_arch_timestamp();
if (!perf_get_timestamp()) {
if (use_arch_timestamp)
warnx("jvmti: arch timestamp not supported");
else
warnx("jvmti: kernel does not support %d clock id", perf_clk_id);
}
memset(&header, 0, sizeof(header));
debug_cache_init();
snprintf(dump_path, PATH_MAX, "%s/jit-%i.dump", jit_path, getpid());
fd = open(dump_path, O_CREAT|O_TRUNC|O_RDWR, 0666);
if (fd == -1)
return NULL;
if (perf_open_marker_file(fd)) {
warnx("jvmti: failed to create marker file");
return NULL;
}
fp = fdopen(fd, "w+");
if (!fp) {
warn("jvmti: cannot create %s", dump_path);
close(fd);
goto error;
}
warnx("jvmti: jitdump in %s", dump_path);
if (get_e_machine(&header)) {
warn("get_e_machine failed\n");
goto error;
}
header.magic = JITHEADER_MAGIC;
header.version = JITHEADER_VERSION;
header.total_size = sizeof(header);
header.pid = getpid();
header.timestamp = perf_get_timestamp();
if (use_arch_timestamp)
header.flags |= JITDUMP_FLAGS_ARCH_TIMESTAMP;
if (!fwrite(&header, sizeof(header), 1, fp)) {
warn("jvmti: cannot write dumpfile header");
goto error;
}
return fp;
error:
fclose(fp);
return NULL;
}
int
jvmti_close(void *agent)
{
struct jr_code_close rec;
FILE *fp = agent;
if (!fp) {
warnx("jvmti: invalid fd in close_agent");
return -1;
}
rec.p.id = JIT_CODE_CLOSE;
rec.p.total_size = sizeof(rec);
rec.p.timestamp = perf_get_timestamp();
if (!fwrite(&rec, sizeof(rec), 1, fp))
return -1;
fclose(fp);
fp = NULL;
perf_close_marker_file();
return 0;
}
int
jvmti_write_code(void *agent, char const *sym,
uint64_t vma, void const *code, unsigned int const size)
{
static int code_generation = 1;
struct jr_code_load rec;
size_t sym_len;
FILE *fp = agent;
int ret = -1;
if (size == 0)
return 0;
if (!fp) {
warnx("jvmti: invalid fd in write_native_code");
return -1;
}
sym_len = strlen(sym) + 1;
rec.p.id = JIT_CODE_LOAD;
rec.p.total_size = sizeof(rec) + sym_len;
rec.p.timestamp = perf_get_timestamp();
rec.code_size = size;
rec.vma = vma;
rec.code_addr = vma;
rec.pid = getpid();
rec.tid = gettid();
if (code)
rec.p.total_size += size;
flockfile(fp);
rec.code_index = code_generation++;
ret = fwrite_unlocked(&rec, sizeof(rec), 1, fp);
fwrite_unlocked(sym, sym_len, 1, fp);
if (code)
fwrite_unlocked(code, size, 1, fp);
funlockfile(fp);
ret = 0;
return ret;
}
int
jvmti_write_debug_info(void *agent, uint64_t code, const char *file,
jvmti_line_info_t *li, int nr_lines)
{
struct jr_code_debug_info rec;
size_t sret, len, size, flen;
uint64_t addr;
const char *fn = file;
FILE *fp = agent;
int i;
if (!nr_lines)
return 0;
if (!fp) {
warnx("jvmti: invalid fd in write_debug_info");
return -1;
}
flen = strlen(file) + 1;
rec.p.id = JIT_CODE_DEBUG_INFO;
size = sizeof(rec);
rec.p.timestamp = perf_get_timestamp();
rec.code_addr = (uint64_t)(uintptr_t)code;
rec.nr_entry = nr_lines;
size += nr_lines * sizeof(struct debug_entry);
size += flen * nr_lines;
rec.p.total_size = size;
flockfile(fp);
sret = fwrite_unlocked(&rec, sizeof(rec), 1, fp);
if (sret != 1)
goto error;
for (i = 0; i < nr_lines; i++) {
addr = (uint64_t)li[i].pc;
len = sizeof(addr);
sret = fwrite_unlocked(&addr, len, 1, fp);
if (sret != 1)
goto error;
len = sizeof(li[0].line_number);
sret = fwrite_unlocked(&li[i].line_number, len, 1, fp);
if (sret != 1)
goto error;
len = sizeof(li[0].discrim);
sret = fwrite_unlocked(&li[i].discrim, len, 1, fp);
if (sret != 1)
goto error;
sret = fwrite_unlocked(fn, flen, 1, fp);
if (sret != 1)
goto error;
}
funlockfile(fp);
return 0;
error:
funlockfile(fp);
return -1;
}
