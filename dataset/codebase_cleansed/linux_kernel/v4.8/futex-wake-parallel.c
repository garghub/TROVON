static void *waking_workerfn(void *arg)
{
struct thread_data *waker = (struct thread_data *) arg;
struct timeval start, end;
gettimeofday(&start, NULL);
waker->nwoken = futex_wake(&futex, nwakes, futex_flag);
if (waker->nwoken != nwakes)
warnx("couldn't wakeup all tasks (%d/%d)",
waker->nwoken, nwakes);
gettimeofday(&end, NULL);
timersub(&end, &start, &waker->runtime);
pthread_exit(NULL);
return NULL;
}
static void wakeup_threads(struct thread_data *td, pthread_attr_t thread_attr)
{
unsigned int i;
pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_JOINABLE);
for (i = 0; i < nwaking_threads; i++) {
if (pthread_create(&td[i].worker, &thread_attr,
waking_workerfn, (void *)&td[i]))
err(EXIT_FAILURE, "pthread_create");
}
for (i = 0; i < nwaking_threads; i++)
if (pthread_join(td[i].worker, NULL))
err(EXIT_FAILURE, "pthread_join");
}
static void *blocked_workerfn(void *arg __maybe_unused)
{
pthread_mutex_lock(&thread_lock);
threads_starting--;
if (!threads_starting)
pthread_cond_signal(&thread_parent);
pthread_cond_wait(&thread_worker, &thread_lock);
pthread_mutex_unlock(&thread_lock);
while (1) {
if (futex_wait(&futex, 0, NULL, futex_flag) != EINTR)
break;
}
pthread_exit(NULL);
return NULL;
}
static void block_threads(pthread_t *w, pthread_attr_t thread_attr)
{
cpu_set_t cpu;
unsigned int i;
threads_starting = nblocked_threads;
for (i = 0; i < nblocked_threads; i++) {
CPU_ZERO(&cpu);
CPU_SET(i % ncpus, &cpu);
if (pthread_attr_setaffinity_np(&thread_attr, sizeof(cpu_set_t), &cpu))
err(EXIT_FAILURE, "pthread_attr_setaffinity_np");
if (pthread_create(&w[i], &thread_attr, blocked_workerfn, NULL))
err(EXIT_FAILURE, "pthread_create");
}
}
static void print_run(struct thread_data *waking_worker, unsigned int run_num)
{
unsigned int i, wakeup_avg;
double waketime_avg, waketime_stddev;
struct stats __waketime_stats, __wakeup_stats;
init_stats(&__wakeup_stats);
init_stats(&__waketime_stats);
for (i = 0; i < nwaking_threads; i++) {
update_stats(&__waketime_stats, waking_worker[i].runtime.tv_usec);
update_stats(&__wakeup_stats, waking_worker[i].nwoken);
}
waketime_avg = avg_stats(&__waketime_stats);
waketime_stddev = stddev_stats(&__waketime_stats);
wakeup_avg = avg_stats(&__wakeup_stats);
printf("[Run %d]: Avg per-thread latency (waking %d/%d threads) "
"in %.4f ms (+-%.2f%%)\n", run_num + 1, wakeup_avg,
nblocked_threads, waketime_avg/1e3,
rel_stddev_stats(waketime_stddev, waketime_avg));
}
static void print_summary(void)
{
unsigned int wakeup_avg;
double waketime_avg, waketime_stddev;
waketime_avg = avg_stats(&waketime_stats);
waketime_stddev = stddev_stats(&waketime_stats);
wakeup_avg = avg_stats(&wakeup_stats);
printf("Avg per-thread latency (waking %d/%d threads) in %.4f ms (+-%.2f%%)\n",
wakeup_avg,
nblocked_threads,
waketime_avg/1e3,
rel_stddev_stats(waketime_stddev, waketime_avg));
}
static void do_run_stats(struct thread_data *waking_worker)
{
unsigned int i;
for (i = 0; i < nwaking_threads; i++) {
update_stats(&waketime_stats, waking_worker[i].runtime.tv_usec);
update_stats(&wakeup_stats, waking_worker[i].nwoken);
}
}
static void toggle_done(int sig __maybe_unused,
siginfo_t *info __maybe_unused,
void *uc __maybe_unused)
{
done = true;
}
int bench_futex_wake_parallel(int argc, const char **argv,
const char *prefix __maybe_unused)
{
int ret = 0;
unsigned int i, j;
struct sigaction act;
pthread_attr_t thread_attr;
struct thread_data *waking_worker;
argc = parse_options(argc, argv, options,
bench_futex_wake_parallel_usage, 0);
if (argc) {
usage_with_options(bench_futex_wake_parallel_usage, options);
exit(EXIT_FAILURE);
}
sigfillset(&act.sa_mask);
act.sa_sigaction = toggle_done;
sigaction(SIGINT, &act, NULL);
ncpus = sysconf(_SC_NPROCESSORS_ONLN);
if (!nblocked_threads)
nblocked_threads = ncpus;
if (nwaking_threads > nblocked_threads || !nwaking_threads)
nwaking_threads = nblocked_threads;
if (nblocked_threads % nwaking_threads)
errx(EXIT_FAILURE, "Must be perfectly divisible");
nwakes = nblocked_threads/nwaking_threads;
blocked_worker = calloc(nblocked_threads, sizeof(*blocked_worker));
if (!blocked_worker)
err(EXIT_FAILURE, "calloc");
if (!fshared)
futex_flag = FUTEX_PRIVATE_FLAG;
printf("Run summary [PID %d]: blocking on %d threads (at [%s] "
"futex %p), %d threads waking up %d at a time.\n\n",
getpid(), nblocked_threads, fshared ? "shared":"private",
&futex, nwaking_threads, nwakes);
init_stats(&wakeup_stats);
init_stats(&waketime_stats);
pthread_attr_init(&thread_attr);
pthread_mutex_init(&thread_lock, NULL);
pthread_cond_init(&thread_parent, NULL);
pthread_cond_init(&thread_worker, NULL);
for (j = 0; j < bench_repeat && !done; j++) {
waking_worker = calloc(nwaking_threads, sizeof(*waking_worker));
if (!waking_worker)
err(EXIT_FAILURE, "calloc");
block_threads(blocked_worker, thread_attr);
pthread_mutex_lock(&thread_lock);
while (threads_starting)
pthread_cond_wait(&thread_parent, &thread_lock);
pthread_cond_broadcast(&thread_worker);
pthread_mutex_unlock(&thread_lock);
usleep(100000);
wakeup_threads(waking_worker, thread_attr);
for (i = 0; i < nblocked_threads; i++) {
ret = pthread_join(blocked_worker[i], NULL);
if (ret)
err(EXIT_FAILURE, "pthread_join");
}
do_run_stats(waking_worker);
if (!silent)
print_run(waking_worker, j);
free(waking_worker);
}
pthread_cond_destroy(&thread_parent);
pthread_cond_destroy(&thread_worker);
pthread_mutex_destroy(&thread_lock);
pthread_attr_destroy(&thread_attr);
print_summary();
free(blocked_worker);
return ret;
}
