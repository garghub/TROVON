void update_vsyscall_tz(void)
{
vsyscall_gtod_data.tz_minuteswest = sys_tz.tz_minuteswest;
vsyscall_gtod_data.tz_dsttime = sys_tz.tz_dsttime;
}
void update_vsyscall(struct timekeeper *tk)
{
struct vsyscall_gtod_data *vdata = &vsyscall_gtod_data;
gtod_write_begin(vdata);
vdata->vclock_mode = tk->tkr.clock->archdata.vclock_mode;
vdata->cycle_last = tk->tkr.cycle_last;
vdata->mask = tk->tkr.mask;
vdata->mult = tk->tkr.mult;
vdata->shift = tk->tkr.shift;
vdata->wall_time_sec = tk->xtime_sec;
vdata->wall_time_snsec = tk->tkr.xtime_nsec;
vdata->monotonic_time_sec = tk->xtime_sec
+ tk->wall_to_monotonic.tv_sec;
vdata->monotonic_time_snsec = tk->tkr.xtime_nsec
+ ((u64)tk->wall_to_monotonic.tv_nsec
<< tk->tkr.shift);
while (vdata->monotonic_time_snsec >=
(((u64)NSEC_PER_SEC) << tk->tkr.shift)) {
vdata->monotonic_time_snsec -=
((u64)NSEC_PER_SEC) << tk->tkr.shift;
vdata->monotonic_time_sec++;
}
vdata->wall_time_coarse_sec = tk->xtime_sec;
vdata->wall_time_coarse_nsec = (long)(tk->tkr.xtime_nsec >>
tk->tkr.shift);
vdata->monotonic_time_coarse_sec =
vdata->wall_time_coarse_sec + tk->wall_to_monotonic.tv_sec;
vdata->monotonic_time_coarse_nsec =
vdata->wall_time_coarse_nsec + tk->wall_to_monotonic.tv_nsec;
while (vdata->monotonic_time_coarse_nsec >= NSEC_PER_SEC) {
vdata->monotonic_time_coarse_nsec -= NSEC_PER_SEC;
vdata->monotonic_time_coarse_sec++;
}
gtod_write_end(vdata);
}
