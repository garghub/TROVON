static void init_clock(void)
{
clock_fd = sys_perf_event_open(&clock_attr, getpid(), -1, -1, 0);
if (clock_fd < 0 && errno == ENOSYS)
die("No CONFIG_PERF_EVENTS=y kernel support configured?\n");
else
BUG_ON(clock_fd < 0);
}
static u64 get_clock(void)
{
int ret;
u64 clk;
ret = read(clock_fd, &clk, sizeof(u64));
BUG_ON(ret != sizeof(u64));
return clk;
}
static double timeval2double(struct timeval *ts)
{
return (double)ts->tv_sec +
(double)ts->tv_usec / (double)1000000;
}
static void alloc_mem(void **dst, size_t length)
{
*dst = zalloc(length);
if (!dst)
die("memory allocation failed - maybe length is too large?\n");
}
static u64 do_memset_clock(memset_t fn, size_t len, bool prefault)
{
u64 clock_start = 0ULL, clock_end = 0ULL;
void *dst = NULL;
int i;
alloc_mem(&dst, len);
if (prefault)
fn(dst, -1, len);
clock_start = get_clock();
for (i = 0; i < iterations; ++i)
fn(dst, i, len);
clock_end = get_clock();
free(dst);
return clock_end - clock_start;
}
static double do_memset_gettimeofday(memset_t fn, size_t len, bool prefault)
{
struct timeval tv_start, tv_end, tv_diff;
void *dst = NULL;
int i;
alloc_mem(&dst, len);
if (prefault)
fn(dst, -1, len);
BUG_ON(gettimeofday(&tv_start, NULL));
for (i = 0; i < iterations; ++i)
fn(dst, i, len);
BUG_ON(gettimeofday(&tv_end, NULL));
timersub(&tv_end, &tv_start, &tv_diff);
free(dst);
return (double)((double)len / timeval2double(&tv_diff));
}
int bench_mem_memset(int argc, const char **argv,
const char *prefix __used)
{
int i;
size_t len;
double result_bps[2];
u64 result_clock[2];
argc = parse_options(argc, argv, options,
bench_mem_memset_usage, 0);
if (use_clock)
init_clock();
len = (size_t)perf_atoll((char *)length_str);
result_clock[0] = result_clock[1] = 0ULL;
result_bps[0] = result_bps[1] = 0.0;
if ((s64)len <= 0) {
fprintf(stderr, "Invalid length:%s\n", length_str);
return 1;
}
if (only_prefault && no_prefault)
only_prefault = no_prefault = false;
for (i = 0; routines[i].name; i++) {
if (!strcmp(routines[i].name, routine))
break;
}
if (!routines[i].name) {
printf("Unknown routine:%s\n", routine);
printf("Available routines...\n");
for (i = 0; routines[i].name; i++) {
printf("\t%s ... %s\n",
routines[i].name, routines[i].desc);
}
return 1;
}
if (bench_format == BENCH_FORMAT_DEFAULT)
printf("# Copying %s Bytes ...\n\n", length_str);
if (!only_prefault && !no_prefault) {
if (use_clock) {
result_clock[0] =
do_memset_clock(routines[i].fn, len, false);
result_clock[1] =
do_memset_clock(routines[i].fn, len, true);
} else {
result_bps[0] =
do_memset_gettimeofday(routines[i].fn,
len, false);
result_bps[1] =
do_memset_gettimeofday(routines[i].fn,
len, true);
}
} else {
if (use_clock) {
result_clock[pf] =
do_memset_clock(routines[i].fn,
len, only_prefault);
} else {
result_bps[pf] =
do_memset_gettimeofday(routines[i].fn,
len, only_prefault);
}
}
switch (bench_format) {
case BENCH_FORMAT_DEFAULT:
if (!only_prefault && !no_prefault) {
if (use_clock) {
printf(" %14lf Clock/Byte\n",
(double)result_clock[0]
/ (double)len);
printf(" %14lf Clock/Byte (with prefault)\n ",
(double)result_clock[1]
/ (double)len);
} else {
print_bps(result_bps[0]);
printf("\n");
print_bps(result_bps[1]);
printf(" (with prefault)\n");
}
} else {
if (use_clock) {
printf(" %14lf Clock/Byte",
(double)result_clock[pf]
/ (double)len);
} else
print_bps(result_bps[pf]);
printf("%s\n", only_prefault ? " (with prefault)" : "");
}
break;
case BENCH_FORMAT_SIMPLE:
if (!only_prefault && !no_prefault) {
if (use_clock) {
printf("%lf %lf\n",
(double)result_clock[0] / (double)len,
(double)result_clock[1] / (double)len);
} else {
printf("%lf %lf\n",
result_bps[0], result_bps[1]);
}
} else {
if (use_clock) {
printf("%lf\n", (double)result_clock[pf]
/ (double)len);
} else
printf("%lf\n", result_bps[pf]);
}
break;
default:
die("unknown format: %d\n", bench_format);
break;
}
return 0;
}
