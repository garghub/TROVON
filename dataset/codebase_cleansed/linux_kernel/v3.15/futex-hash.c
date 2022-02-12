static void *workerfn(void *arg)
{
int ret;
unsigned int i;
struct worker *w = (struct worker *) arg;
pthread_mutex_lock(&thread_lock);
threads_starting--;
if (!threads_starting)
pthread_cond_signal(&thread_parent);
pthread_cond_wait(&thread_worker, &thread_lock);
pthread_mutex_unlock(&thread_lock);
do {
for (i = 0; i < nfutexes; i++, w->ops++) {
ret = futex_wait(&w->futex[i], 1234, NULL,
fshared ? 0 : FUTEX_PRIVATE_FLAG);
if (!silent &&
(!ret || errno != EAGAIN || errno != EWOULDBLOCK))
warn("Non-expected futex return call");
}
} while (!done);
return NULL;
}
static void toggle_done(int sig __maybe_unused,
siginfo_t *info __maybe_unused,
void *uc __maybe_unused)
{
done = true;
gettimeofday(&end, NULL);
timersub(&end, &start, &runtime);
}
static void print_summary(void)
{
unsigned long avg = avg_stats(&throughput_stats);
double stddev = stddev_stats(&throughput_stats);
printf("%sAveraged %ld operations/sec (+- %.2f%%), total secs = %d\n",
!silent ? "\n" : "", avg, rel_stddev_stats(stddev, avg),
(int) runtime.tv_sec);
}
int bench_futex_hash(int argc, const char **argv,
const char *prefix __maybe_unused)
{
int ret = 0;
cpu_set_t cpu;
struct sigaction act;
unsigned int i, ncpus;
pthread_attr_t thread_attr;
struct worker *worker = NULL;
argc = parse_options(argc, argv, options, bench_futex_hash_usage, 0);
if (argc) {
usage_with_options(bench_futex_hash_usage, options);
exit(EXIT_FAILURE);
}
ncpus = sysconf(_SC_NPROCESSORS_ONLN);
sigfillset(&act.sa_mask);
act.sa_sigaction = toggle_done;
sigaction(SIGINT, &act, NULL);
if (!nthreads)
nthreads = ncpus;
worker = calloc(nthreads, sizeof(*worker));
if (!worker)
goto errmem;
printf("Run summary [PID %d]: %d threads, each operating on %d [%s] futexes for %d secs.\n\n",
getpid(), nthreads, nfutexes, fshared ? "shared":"private", nsecs);
init_stats(&throughput_stats);
pthread_mutex_init(&thread_lock, NULL);
pthread_cond_init(&thread_parent, NULL);
pthread_cond_init(&thread_worker, NULL);
threads_starting = nthreads;
pthread_attr_init(&thread_attr);
gettimeofday(&start, NULL);
for (i = 0; i < nthreads; i++) {
worker[i].tid = i;
worker[i].futex = calloc(nfutexes, sizeof(*worker[i].futex));
if (!worker[i].futex)
goto errmem;
CPU_ZERO(&cpu);
CPU_SET(i % ncpus, &cpu);
ret = pthread_attr_setaffinity_np(&thread_attr, sizeof(cpu_set_t), &cpu);
if (ret)
err(EXIT_FAILURE, "pthread_attr_setaffinity_np");
ret = pthread_create(&worker[i].thread, &thread_attr, workerfn,
(void *)(struct worker *) &worker[i]);
if (ret)
err(EXIT_FAILURE, "pthread_create");
}
pthread_attr_destroy(&thread_attr);
pthread_mutex_lock(&thread_lock);
while (threads_starting)
pthread_cond_wait(&thread_parent, &thread_lock);
pthread_cond_broadcast(&thread_worker);
pthread_mutex_unlock(&thread_lock);
sleep(nsecs);
toggle_done(0, NULL, NULL);
for (i = 0; i < nthreads; i++) {
ret = pthread_join(worker[i].thread, NULL);
if (ret)
err(EXIT_FAILURE, "pthread_join");
}
pthread_cond_destroy(&thread_parent);
pthread_cond_destroy(&thread_worker);
pthread_mutex_destroy(&thread_lock);
for (i = 0; i < nthreads; i++) {
unsigned long t = worker[i].ops/runtime.tv_sec;
update_stats(&throughput_stats, t);
if (!silent) {
if (nfutexes == 1)
printf("[thread %2d] futex: %p [ %ld ops/sec ]\n",
worker[i].tid, &worker[i].futex[0], t);
else
printf("[thread %2d] futexes: %p ... %p [ %ld ops/sec ]\n",
worker[i].tid, &worker[i].futex[0],
&worker[i].futex[nfutexes-1], t);
}
free(worker[i].futex);
}
print_summary();
free(worker);
return ret;
errmem:
err(EXIT_FAILURE, "calloc");
}
