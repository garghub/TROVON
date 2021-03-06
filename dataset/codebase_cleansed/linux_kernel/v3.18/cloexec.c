static int perf_flag_probe(void)
{
struct perf_event_attr attr = {
.type = PERF_TYPE_SOFTWARE,
.config = PERF_COUNT_SW_CPU_CLOCK,
.exclude_kernel = 1,
};
int fd;
int err;
int cpu;
pid_t pid = -1;
char sbuf[STRERR_BUFSIZE];
cpu = sched_getcpu();
if (cpu < 0)
cpu = 0;
while (1) {
fd = sys_perf_event_open(&attr, pid, cpu, -1,
PERF_FLAG_FD_CLOEXEC);
if (fd < 0 && pid == -1 && errno == EACCES) {
pid = 0;
continue;
}
break;
}
err = errno;
if (fd >= 0) {
close(fd);
return 1;
}
WARN_ONCE(err != EINVAL && err != EBUSY,
"perf_event_open(..., PERF_FLAG_FD_CLOEXEC) failed with unexpected error %d (%s)\n",
err, strerror_r(err, sbuf, sizeof(sbuf)));
fd = sys_perf_event_open(&attr, pid, cpu, -1, 0);
err = errno;
if (WARN_ONCE(fd < 0 && err != EBUSY,
"perf_event_open(..., 0) failed unexpectedly with error %d (%s)\n",
err, strerror_r(err, sbuf, sizeof(sbuf))))
return -1;
close(fd);
return 0;
}
unsigned long perf_event_open_cloexec_flag(void)
{
static bool probed;
if (!probed) {
if (perf_flag_probe() <= 0)
flag = 0;
probed = true;
}
return flag;
}
