static int perf_flag_probe(void)
{
struct perf_event_attr attr = {
.type = PERF_COUNT_SW_CPU_CLOCK,
.config = PERF_COUNT_SW_CPU_CLOCK,
};
int fd;
int err;
fd = sys_perf_event_open(&attr, 0, -1, -1,
PERF_FLAG_FD_CLOEXEC);
err = errno;
if (fd >= 0) {
close(fd);
return 1;
}
WARN_ONCE(err != EINVAL,
"perf_event_open(..., PERF_FLAG_FD_CLOEXEC) failed with unexpected error %d (%s)\n",
err, strerror(err));
fd = sys_perf_event_open(&attr, 0, -1, -1, 0);
err = errno;
if (WARN_ONCE(fd < 0,
"perf_event_open(..., 0) failed unexpectedly with error %d (%s)\n",
err, strerror(err)))
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
