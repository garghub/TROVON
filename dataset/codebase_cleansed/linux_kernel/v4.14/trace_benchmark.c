static void trace_do_benchmark(void)
{
u64 start;
u64 stop;
u64 delta;
u64 stddev;
u64 seed;
u64 last_seed;
unsigned int avg;
unsigned int std = 0;
if (!trace_benchmark_event_enabled() || !tracing_is_on())
return;
local_irq_disable();
start = trace_clock_local();
trace_benchmark_event(bm_str);
stop = trace_clock_local();
local_irq_enable();
bm_cnt++;
delta = stop - start;
if (bm_cnt == 1) {
bm_first = delta;
scnprintf(bm_str, BENCHMARK_EVENT_STRLEN,
"first=%llu [COLD CACHED]", bm_first);
return;
}
bm_last = delta;
if (delta > bm_max)
bm_max = delta;
if (!bm_min || delta < bm_min)
bm_min = delta;
if (bm_cnt > UINT_MAX) {
scnprintf(bm_str, BENCHMARK_EVENT_STRLEN,
"last=%llu first=%llu max=%llu min=%llu ** avg=%u std=%d std^2=%lld",
bm_last, bm_first, bm_max, bm_min, bm_avg, bm_std, bm_stddev);
return;
}
bm_total += delta;
bm_totalsq += delta * delta;
if (bm_cnt > 1) {
stddev = (u64)bm_cnt * bm_totalsq - bm_total * bm_total;
do_div(stddev, (u32)bm_cnt);
do_div(stddev, (u32)bm_cnt - 1);
} else
stddev = 0;
delta = bm_total;
do_div(delta, bm_cnt);
avg = delta;
if (stddev > 0) {
int i = 0;
seed = avg;
do {
last_seed = seed;
seed = stddev;
if (!last_seed)
break;
do_div(seed, last_seed);
seed += last_seed;
do_div(seed, 2);
} while (i++ < 10 && last_seed != seed);
std = seed;
}
scnprintf(bm_str, BENCHMARK_EVENT_STRLEN,
"last=%llu first=%llu max=%llu min=%llu avg=%u std=%d std^2=%lld",
bm_last, bm_first, bm_max, bm_min, avg, std, stddev);
bm_std = std;
bm_avg = avg;
bm_stddev = stddev;
}
static int benchmark_event_kthread(void *arg)
{
msleep(100);
while (!kthread_should_stop()) {
trace_do_benchmark();
cond_resched_rcu_qs();
}
return 0;
}
int trace_benchmark_reg(void)
{
if (!ok_to_run) {
pr_warning("trace benchmark cannot be started via kernel command line\n");
return -EBUSY;
}
bm_event_thread = kthread_run(benchmark_event_kthread,
NULL, "event_benchmark");
if (IS_ERR(bm_event_thread)) {
pr_warning("trace benchmark failed to create kernel thread\n");
return PTR_ERR(bm_event_thread);
}
return 0;
}
void trace_benchmark_unreg(void)
{
if (!bm_event_thread)
return;
kthread_stop(bm_event_thread);
bm_event_thread = NULL;
strcpy(bm_str, "START");
bm_total = 0;
bm_totalsq = 0;
bm_last = 0;
bm_max = 0;
bm_min = 0;
bm_cnt = 0;
bm_first = 0;
bm_std = 0;
bm_avg = 0;
bm_stddev = 0;
}
static __init int ok_to_run_trace_benchmark(void)
{
ok_to_run = true;
return 0;
}
