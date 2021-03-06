static long __estimate_accuracy(struct timespec *tv)
{
long slack;
int divfactor = 1000;
if (tv->tv_sec < 0)
return 0;
if (task_nice(current) > 0)
divfactor = divfactor / 5;
if (tv->tv_sec > MAX_SLACK / (NSEC_PER_SEC/divfactor))
return MAX_SLACK;
slack = tv->tv_nsec / divfactor;
slack += tv->tv_sec * (NSEC_PER_SEC/divfactor);
if (slack > MAX_SLACK)
return MAX_SLACK;
return slack;
}
long select_estimate_accuracy(struct timespec *tv)
{
unsigned long ret;
struct timespec now;
if (rt_task(current))
return 0;
ktime_get_ts(&now);
now = timespec_sub(*tv, now);
ret = __estimate_accuracy(&now);
if (ret < current->timer_slack_ns)
return current->timer_slack_ns;
return ret;
}
void poll_initwait(struct poll_wqueues *pwq)
{
init_poll_funcptr(&pwq->pt, __pollwait);
pwq->polling_task = current;
pwq->triggered = 0;
pwq->error = 0;
pwq->table = NULL;
pwq->inline_index = 0;
}
static void free_poll_entry(struct poll_table_entry *entry)
{
remove_wait_queue(entry->wait_address, &entry->wait);
fput(entry->filp);
}
void poll_freewait(struct poll_wqueues *pwq)
{
struct poll_table_page * p = pwq->table;
int i;
for (i = 0; i < pwq->inline_index; i++)
free_poll_entry(pwq->inline_entries + i);
while (p) {
struct poll_table_entry * entry;
struct poll_table_page *old;
entry = p->entry;
do {
entry--;
free_poll_entry(entry);
} while (entry > p->entries);
old = p;
p = p->next;
free_page((unsigned long) old);
}
}
static struct poll_table_entry *poll_get_entry(struct poll_wqueues *p)
{
struct poll_table_page *table = p->table;
if (p->inline_index < N_INLINE_POLL_ENTRIES)
return p->inline_entries + p->inline_index++;
if (!table || POLL_TABLE_FULL(table)) {
struct poll_table_page *new_table;
new_table = (struct poll_table_page *) __get_free_page(GFP_KERNEL);
if (!new_table) {
p->error = -ENOMEM;
return NULL;
}
new_table->entry = new_table->entries;
new_table->next = table;
p->table = new_table;
table = new_table;
}
return table->entry++;
}
static int __pollwake(wait_queue_t *wait, unsigned mode, int sync, void *key)
{
struct poll_wqueues *pwq = wait->private;
DECLARE_WAITQUEUE(dummy_wait, pwq->polling_task);
smp_wmb();
pwq->triggered = 1;
return default_wake_function(&dummy_wait, mode, sync, key);
}
static int pollwake(wait_queue_t *wait, unsigned mode, int sync, void *key)
{
struct poll_table_entry *entry;
entry = container_of(wait, struct poll_table_entry, wait);
if (key && !((unsigned long)key & entry->key))
return 0;
return __pollwake(wait, mode, sync, key);
}
static void __pollwait(struct file *filp, wait_queue_head_t *wait_address,
poll_table *p)
{
struct poll_wqueues *pwq = container_of(p, struct poll_wqueues, pt);
struct poll_table_entry *entry = poll_get_entry(pwq);
if (!entry)
return;
entry->filp = get_file(filp);
entry->wait_address = wait_address;
entry->key = p->_key;
init_waitqueue_func_entry(&entry->wait, pollwake);
entry->wait.private = pwq;
add_wait_queue(wait_address, &entry->wait);
}
int poll_schedule_timeout(struct poll_wqueues *pwq, int state,
ktime_t *expires, unsigned long slack)
{
int rc = -EINTR;
set_current_state(state);
if (!pwq->triggered)
rc = schedule_hrtimeout_range(expires, slack, HRTIMER_MODE_ABS);
__set_current_state(TASK_RUNNING);
smp_store_mb(pwq->triggered, 0);
return rc;
}
int poll_select_set_timeout(struct timespec *to, long sec, long nsec)
{
struct timespec ts = {.tv_sec = sec, .tv_nsec = nsec};
if (!timespec_valid(&ts))
return -EINVAL;
if (!sec && !nsec) {
to->tv_sec = to->tv_nsec = 0;
} else {
ktime_get_ts(to);
*to = timespec_add_safe(*to, ts);
}
return 0;
}
static int poll_select_copy_remaining(struct timespec *end_time, void __user *p,
int timeval, int ret)
{
struct timespec rts;
struct timeval rtv;
if (!p)
return ret;
if (current->personality & STICKY_TIMEOUTS)
goto sticky;
if (!end_time->tv_sec && !end_time->tv_nsec)
return ret;
ktime_get_ts(&rts);
rts = timespec_sub(*end_time, rts);
if (rts.tv_sec < 0)
rts.tv_sec = rts.tv_nsec = 0;
if (timeval) {
if (sizeof(rtv) > sizeof(rtv.tv_sec) + sizeof(rtv.tv_usec))
memset(&rtv, 0, sizeof(rtv));
rtv.tv_sec = rts.tv_sec;
rtv.tv_usec = rts.tv_nsec / NSEC_PER_USEC;
if (!copy_to_user(p, &rtv, sizeof(rtv)))
return ret;
} else if (!copy_to_user(p, &rts, sizeof(rts)))
return ret;
sticky:
if (ret == -ERESTARTNOHAND)
ret = -EINTR;
return ret;
}
static int max_select_fd(unsigned long n, fd_set_bits *fds)
{
unsigned long *open_fds;
unsigned long set;
int max;
struct fdtable *fdt;
set = ~(~0UL << (n & (BITS_PER_LONG-1)));
n /= BITS_PER_LONG;
fdt = files_fdtable(current->files);
open_fds = fdt->open_fds + n;
max = 0;
if (set) {
set &= BITS(fds, n);
if (set) {
if (!(set & ~*open_fds))
goto get_max;
return -EBADF;
}
}
while (n) {
open_fds--;
n--;
set = BITS(fds, n);
if (!set)
continue;
if (set & ~*open_fds)
return -EBADF;
if (max)
continue;
get_max:
do {
max++;
set >>= 1;
} while (set);
max += n * BITS_PER_LONG;
}
return max;
}
static inline void wait_key_set(poll_table *wait, unsigned long in,
unsigned long out, unsigned long bit,
unsigned int ll_flag)
{
wait->_key = POLLEX_SET | ll_flag;
if (in & bit)
wait->_key |= POLLIN_SET;
if (out & bit)
wait->_key |= POLLOUT_SET;
}
int do_select(int n, fd_set_bits *fds, struct timespec *end_time)
{
ktime_t expire, *to = NULL;
struct poll_wqueues table;
poll_table *wait;
int retval, i, timed_out = 0;
unsigned long slack = 0;
unsigned int busy_flag = net_busy_loop_on() ? POLL_BUSY_LOOP : 0;
unsigned long busy_end = 0;
rcu_read_lock();
retval = max_select_fd(n, fds);
rcu_read_unlock();
if (retval < 0)
return retval;
n = retval;
poll_initwait(&table);
wait = &table.pt;
if (end_time && !end_time->tv_sec && !end_time->tv_nsec) {
wait->_qproc = NULL;
timed_out = 1;
}
if (end_time && !timed_out)
slack = select_estimate_accuracy(end_time);
retval = 0;
for (;;) {
unsigned long *rinp, *routp, *rexp, *inp, *outp, *exp;
bool can_busy_loop = false;
inp = fds->in; outp = fds->out; exp = fds->ex;
rinp = fds->res_in; routp = fds->res_out; rexp = fds->res_ex;
for (i = 0; i < n; ++rinp, ++routp, ++rexp) {
unsigned long in, out, ex, all_bits, bit = 1, mask, j;
unsigned long res_in = 0, res_out = 0, res_ex = 0;
in = *inp++; out = *outp++; ex = *exp++;
all_bits = in | out | ex;
if (all_bits == 0) {
i += BITS_PER_LONG;
continue;
}
for (j = 0; j < BITS_PER_LONG; ++j, ++i, bit <<= 1) {
struct fd f;
if (i >= n)
break;
if (!(bit & all_bits))
continue;
f = fdget(i);
if (f.file) {
const struct file_operations *f_op;
f_op = f.file->f_op;
mask = DEFAULT_POLLMASK;
if (f_op->poll) {
wait_key_set(wait, in, out,
bit, busy_flag);
mask = (*f_op->poll)(f.file, wait);
}
fdput(f);
if ((mask & POLLIN_SET) && (in & bit)) {
res_in |= bit;
retval++;
wait->_qproc = NULL;
}
if ((mask & POLLOUT_SET) && (out & bit)) {
res_out |= bit;
retval++;
wait->_qproc = NULL;
}
if ((mask & POLLEX_SET) && (ex & bit)) {
res_ex |= bit;
retval++;
wait->_qproc = NULL;
}
if (retval) {
can_busy_loop = false;
busy_flag = 0;
} else if (busy_flag & mask)
can_busy_loop = true;
}
}
if (res_in)
*rinp = res_in;
if (res_out)
*routp = res_out;
if (res_ex)
*rexp = res_ex;
cond_resched();
}
wait->_qproc = NULL;
if (retval || timed_out || signal_pending(current))
break;
if (table.error) {
retval = table.error;
break;
}
if (can_busy_loop && !need_resched()) {
if (!busy_end) {
busy_end = busy_loop_end_time();
continue;
}
if (!busy_loop_timeout(busy_end))
continue;
}
busy_flag = 0;
if (end_time && !to) {
expire = timespec_to_ktime(*end_time);
to = &expire;
}
if (!poll_schedule_timeout(&table, TASK_INTERRUPTIBLE,
to, slack))
timed_out = 1;
}
poll_freewait(&table);
return retval;
}
int core_sys_select(int n, fd_set __user *inp, fd_set __user *outp,
fd_set __user *exp, struct timespec *end_time)
{
fd_set_bits fds;
void *bits;
int ret, max_fds;
unsigned int size;
struct fdtable *fdt;
long stack_fds[SELECT_STACK_ALLOC/sizeof(long)];
ret = -EINVAL;
if (n < 0)
goto out_nofds;
rcu_read_lock();
fdt = files_fdtable(current->files);
max_fds = fdt->max_fds;
rcu_read_unlock();
if (n > max_fds)
n = max_fds;
size = FDS_BYTES(n);
bits = stack_fds;
if (size > sizeof(stack_fds) / 6) {
ret = -ENOMEM;
bits = kmalloc(6 * size, GFP_KERNEL);
if (!bits)
goto out_nofds;
}
fds.in = bits;
fds.out = bits + size;
fds.ex = bits + 2*size;
fds.res_in = bits + 3*size;
fds.res_out = bits + 4*size;
fds.res_ex = bits + 5*size;
if ((ret = get_fd_set(n, inp, fds.in)) ||
(ret = get_fd_set(n, outp, fds.out)) ||
(ret = get_fd_set(n, exp, fds.ex)))
goto out;
zero_fd_set(n, fds.res_in);
zero_fd_set(n, fds.res_out);
zero_fd_set(n, fds.res_ex);
ret = do_select(n, &fds, end_time);
if (ret < 0)
goto out;
if (!ret) {
ret = -ERESTARTNOHAND;
if (signal_pending(current))
goto out;
ret = 0;
}
if (set_fd_set(n, inp, fds.res_in) ||
set_fd_set(n, outp, fds.res_out) ||
set_fd_set(n, exp, fds.res_ex))
ret = -EFAULT;
out:
if (bits != stack_fds)
kfree(bits);
out_nofds:
return ret;
}
static long do_pselect(int n, fd_set __user *inp, fd_set __user *outp,
fd_set __user *exp, struct timespec __user *tsp,
const sigset_t __user *sigmask, size_t sigsetsize)
{
sigset_t ksigmask, sigsaved;
struct timespec ts, end_time, *to = NULL;
int ret;
if (tsp) {
if (copy_from_user(&ts, tsp, sizeof(ts)))
return -EFAULT;
to = &end_time;
if (poll_select_set_timeout(to, ts.tv_sec, ts.tv_nsec))
return -EINVAL;
}
if (sigmask) {
if (sigsetsize != sizeof(sigset_t))
return -EINVAL;
if (copy_from_user(&ksigmask, sigmask, sizeof(ksigmask)))
return -EFAULT;
sigdelsetmask(&ksigmask, sigmask(SIGKILL)|sigmask(SIGSTOP));
sigprocmask(SIG_SETMASK, &ksigmask, &sigsaved);
}
ret = core_sys_select(n, inp, outp, exp, to);
ret = poll_select_copy_remaining(&end_time, tsp, 0, ret);
if (ret == -ERESTARTNOHAND) {
if (sigmask) {
memcpy(&current->saved_sigmask, &sigsaved,
sizeof(sigsaved));
set_restore_sigmask();
}
} else if (sigmask)
sigprocmask(SIG_SETMASK, &sigsaved, NULL);
return ret;
}
static inline unsigned int do_pollfd(struct pollfd *pollfd, poll_table *pwait,
bool *can_busy_poll,
unsigned int busy_flag)
{
unsigned int mask;
int fd;
mask = 0;
fd = pollfd->fd;
if (fd >= 0) {
struct fd f = fdget(fd);
mask = POLLNVAL;
if (f.file) {
mask = DEFAULT_POLLMASK;
if (f.file->f_op->poll) {
pwait->_key = pollfd->events|POLLERR|POLLHUP;
pwait->_key |= busy_flag;
mask = f.file->f_op->poll(f.file, pwait);
if (mask & busy_flag)
*can_busy_poll = true;
}
mask &= pollfd->events | POLLERR | POLLHUP;
fdput(f);
}
}
pollfd->revents = mask;
return mask;
}
static int do_poll(struct poll_list *list, struct poll_wqueues *wait,
struct timespec *end_time)
{
poll_table* pt = &wait->pt;
ktime_t expire, *to = NULL;
int timed_out = 0, count = 0;
unsigned long slack = 0;
unsigned int busy_flag = net_busy_loop_on() ? POLL_BUSY_LOOP : 0;
unsigned long busy_end = 0;
if (end_time && !end_time->tv_sec && !end_time->tv_nsec) {
pt->_qproc = NULL;
timed_out = 1;
}
if (end_time && !timed_out)
slack = select_estimate_accuracy(end_time);
for (;;) {
struct poll_list *walk;
bool can_busy_loop = false;
for (walk = list; walk != NULL; walk = walk->next) {
struct pollfd * pfd, * pfd_end;
pfd = walk->entries;
pfd_end = pfd + walk->len;
for (; pfd != pfd_end; pfd++) {
if (do_pollfd(pfd, pt, &can_busy_loop,
busy_flag)) {
count++;
pt->_qproc = NULL;
busy_flag = 0;
can_busy_loop = false;
}
}
}
pt->_qproc = NULL;
if (!count) {
count = wait->error;
if (signal_pending(current))
count = -EINTR;
}
if (count || timed_out)
break;
if (can_busy_loop && !need_resched()) {
if (!busy_end) {
busy_end = busy_loop_end_time();
continue;
}
if (!busy_loop_timeout(busy_end))
continue;
}
busy_flag = 0;
if (end_time && !to) {
expire = timespec_to_ktime(*end_time);
to = &expire;
}
if (!poll_schedule_timeout(wait, TASK_INTERRUPTIBLE, to, slack))
timed_out = 1;
}
return count;
}
int do_sys_poll(struct pollfd __user *ufds, unsigned int nfds,
struct timespec *end_time)
{
struct poll_wqueues table;
int err = -EFAULT, fdcount, len, size;
long stack_pps[POLL_STACK_ALLOC/sizeof(long)];
struct poll_list *const head = (struct poll_list *)stack_pps;
struct poll_list *walk = head;
unsigned long todo = nfds;
if (nfds > rlimit(RLIMIT_NOFILE))
return -EINVAL;
len = min_t(unsigned int, nfds, N_STACK_PPS);
for (;;) {
walk->next = NULL;
walk->len = len;
if (!len)
break;
if (copy_from_user(walk->entries, ufds + nfds-todo,
sizeof(struct pollfd) * walk->len))
goto out_fds;
todo -= walk->len;
if (!todo)
break;
len = min(todo, POLLFD_PER_PAGE);
size = sizeof(struct poll_list) + sizeof(struct pollfd) * len;
walk = walk->next = kmalloc(size, GFP_KERNEL);
if (!walk) {
err = -ENOMEM;
goto out_fds;
}
}
poll_initwait(&table);
fdcount = do_poll(head, &table, end_time);
poll_freewait(&table);
for (walk = head; walk; walk = walk->next) {
struct pollfd *fds = walk->entries;
int j;
for (j = 0; j < walk->len; j++, ufds++)
if (__put_user(fds[j].revents, &ufds->revents))
goto out_fds;
}
err = fdcount;
out_fds:
walk = head->next;
while (walk) {
struct poll_list *pos = walk;
walk = walk->next;
kfree(pos);
}
return err;
}
static long do_restart_poll(struct restart_block *restart_block)
{
struct pollfd __user *ufds = restart_block->poll.ufds;
int nfds = restart_block->poll.nfds;
struct timespec *to = NULL, end_time;
int ret;
if (restart_block->poll.has_timeout) {
end_time.tv_sec = restart_block->poll.tv_sec;
end_time.tv_nsec = restart_block->poll.tv_nsec;
to = &end_time;
}
ret = do_sys_poll(ufds, nfds, to);
if (ret == -EINTR) {
restart_block->fn = do_restart_poll;
ret = -ERESTART_RESTARTBLOCK;
}
return ret;
}
