void get_avenrun(unsigned long *loads, unsigned long offset, int shift)
{
loads[0] = (avenrun[0] + offset) << shift;
loads[1] = (avenrun[1] + offset) << shift;
loads[2] = (avenrun[2] + offset) << shift;
}
long calc_load_fold_active(struct rq *this_rq, long adjust)
{
long nr_active, delta = 0;
nr_active = this_rq->nr_running - adjust;
nr_active += (long)this_rq->nr_uninterruptible;
if (nr_active != this_rq->calc_load_active) {
delta = nr_active - this_rq->calc_load_active;
this_rq->calc_load_active = nr_active;
}
return delta;
}
static unsigned long
calc_load(unsigned long load, unsigned long exp, unsigned long active)
{
unsigned long newload;
newload = load * exp + active * (FIXED_1 - exp);
if (active >= load)
newload += FIXED_1-1;
return newload / FIXED_1;
}
static inline int calc_load_write_idx(void)
{
int idx = calc_load_idx;
smp_rmb();
if (!time_before(jiffies, READ_ONCE(calc_load_update)))
idx++;
return idx & 1;
}
static inline int calc_load_read_idx(void)
{
return calc_load_idx & 1;
}
void calc_load_enter_idle(void)
{
struct rq *this_rq = this_rq();
long delta;
delta = calc_load_fold_active(this_rq, 0);
if (delta) {
int idx = calc_load_write_idx();
atomic_long_add(delta, &calc_load_idle[idx]);
}
}
void calc_load_exit_idle(void)
{
struct rq *this_rq = this_rq();
this_rq->calc_load_update = READ_ONCE(calc_load_update);
if (time_before(jiffies, this_rq->calc_load_update))
return;
if (time_before(jiffies, this_rq->calc_load_update + 10))
this_rq->calc_load_update += LOAD_FREQ;
}
static long calc_load_fold_idle(void)
{
int idx = calc_load_read_idx();
long delta = 0;
if (atomic_long_read(&calc_load_idle[idx]))
delta = atomic_long_xchg(&calc_load_idle[idx], 0);
return delta;
}
static unsigned long
fixed_power_int(unsigned long x, unsigned int frac_bits, unsigned int n)
{
unsigned long result = 1UL << frac_bits;
if (n) {
for (;;) {
if (n & 1) {
result *= x;
result += 1UL << (frac_bits - 1);
result >>= frac_bits;
}
n >>= 1;
if (!n)
break;
x *= x;
x += 1UL << (frac_bits - 1);
x >>= frac_bits;
}
}
return result;
}
static unsigned long
calc_load_n(unsigned long load, unsigned long exp,
unsigned long active, unsigned int n)
{
return calc_load(load, fixed_power_int(exp, FSHIFT, n), active);
}
static void calc_global_nohz(void)
{
unsigned long sample_window;
long delta, active, n;
sample_window = READ_ONCE(calc_load_update);
if (!time_before(jiffies, sample_window + 10)) {
delta = jiffies - sample_window - 10;
n = 1 + (delta / LOAD_FREQ);
active = atomic_long_read(&calc_load_tasks);
active = active > 0 ? active * FIXED_1 : 0;
avenrun[0] = calc_load_n(avenrun[0], EXP_1, active, n);
avenrun[1] = calc_load_n(avenrun[1], EXP_5, active, n);
avenrun[2] = calc_load_n(avenrun[2], EXP_15, active, n);
WRITE_ONCE(calc_load_update, sample_window + n * LOAD_FREQ);
}
smp_wmb();
calc_load_idx++;
}
static inline long calc_load_fold_idle(void) { return 0; }
static inline void calc_global_nohz(void) { }
void calc_global_load(unsigned long ticks)
{
unsigned long sample_window;
long active, delta;
sample_window = READ_ONCE(calc_load_update);
if (time_before(jiffies, sample_window + 10))
return;
delta = calc_load_fold_idle();
if (delta)
atomic_long_add(delta, &calc_load_tasks);
active = atomic_long_read(&calc_load_tasks);
active = active > 0 ? active * FIXED_1 : 0;
avenrun[0] = calc_load(avenrun[0], EXP_1, active);
avenrun[1] = calc_load(avenrun[1], EXP_5, active);
avenrun[2] = calc_load(avenrun[2], EXP_15, active);
WRITE_ONCE(calc_load_update, sample_window + LOAD_FREQ);
calc_global_nohz();
}
void calc_global_load_tick(struct rq *this_rq)
{
long delta;
if (time_before(jiffies, this_rq->calc_load_update))
return;
delta = calc_load_fold_active(this_rq, 0);
if (delta)
atomic_long_add(delta, &calc_load_tasks);
this_rq->calc_load_update += LOAD_FREQ;
}
