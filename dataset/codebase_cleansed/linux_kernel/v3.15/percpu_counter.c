static int percpu_counter_fixup_free(void *addr, enum debug_obj_state state)
{
struct percpu_counter *fbc = addr;
switch (state) {
case ODEBUG_STATE_ACTIVE:
percpu_counter_destroy(fbc);
debug_object_free(fbc, &percpu_counter_debug_descr);
return 1;
default:
return 0;
}
}
static inline void debug_percpu_counter_activate(struct percpu_counter *fbc)
{
debug_object_init(fbc, &percpu_counter_debug_descr);
debug_object_activate(fbc, &percpu_counter_debug_descr);
}
static inline void debug_percpu_counter_deactivate(struct percpu_counter *fbc)
{
debug_object_deactivate(fbc, &percpu_counter_debug_descr);
debug_object_free(fbc, &percpu_counter_debug_descr);
}
static inline void debug_percpu_counter_activate(struct percpu_counter *fbc)
{ }
static inline void debug_percpu_counter_deactivate(struct percpu_counter *fbc)
{ }
void percpu_counter_set(struct percpu_counter *fbc, s64 amount)
{
int cpu;
unsigned long flags;
raw_spin_lock_irqsave(&fbc->lock, flags);
for_each_possible_cpu(cpu) {
s32 *pcount = per_cpu_ptr(fbc->counters, cpu);
*pcount = 0;
}
fbc->count = amount;
raw_spin_unlock_irqrestore(&fbc->lock, flags);
}
void __percpu_counter_add(struct percpu_counter *fbc, s64 amount, s32 batch)
{
s64 count;
preempt_disable();
count = __this_cpu_read(*fbc->counters) + amount;
if (count >= batch || count <= -batch) {
unsigned long flags;
raw_spin_lock_irqsave(&fbc->lock, flags);
fbc->count += count;
__this_cpu_sub(*fbc->counters, count - amount);
raw_spin_unlock_irqrestore(&fbc->lock, flags);
} else {
this_cpu_add(*fbc->counters, amount);
}
preempt_enable();
}
s64 __percpu_counter_sum(struct percpu_counter *fbc)
{
s64 ret;
int cpu;
unsigned long flags;
raw_spin_lock_irqsave(&fbc->lock, flags);
ret = fbc->count;
for_each_online_cpu(cpu) {
s32 *pcount = per_cpu_ptr(fbc->counters, cpu);
ret += *pcount;
}
raw_spin_unlock_irqrestore(&fbc->lock, flags);
return ret;
}
int __percpu_counter_init(struct percpu_counter *fbc, s64 amount,
struct lock_class_key *key)
{
raw_spin_lock_init(&fbc->lock);
lockdep_set_class(&fbc->lock, key);
fbc->count = amount;
fbc->counters = alloc_percpu(s32);
if (!fbc->counters)
return -ENOMEM;
debug_percpu_counter_activate(fbc);
#ifdef CONFIG_HOTPLUG_CPU
INIT_LIST_HEAD(&fbc->list);
spin_lock(&percpu_counters_lock);
list_add(&fbc->list, &percpu_counters);
spin_unlock(&percpu_counters_lock);
#endif
return 0;
}
void percpu_counter_destroy(struct percpu_counter *fbc)
{
if (!fbc->counters)
return;
debug_percpu_counter_deactivate(fbc);
#ifdef CONFIG_HOTPLUG_CPU
spin_lock(&percpu_counters_lock);
list_del(&fbc->list);
spin_unlock(&percpu_counters_lock);
#endif
free_percpu(fbc->counters);
fbc->counters = NULL;
}
static void compute_batch_value(void)
{
int nr = num_online_cpus();
percpu_counter_batch = max(32, nr*2);
}
static int percpu_counter_hotcpu_callback(struct notifier_block *nb,
unsigned long action, void *hcpu)
{
#ifdef CONFIG_HOTPLUG_CPU
unsigned int cpu;
struct percpu_counter *fbc;
compute_batch_value();
if (action != CPU_DEAD && action != CPU_DEAD_FROZEN)
return NOTIFY_OK;
cpu = (unsigned long)hcpu;
spin_lock(&percpu_counters_lock);
list_for_each_entry(fbc, &percpu_counters, list) {
s32 *pcount;
unsigned long flags;
raw_spin_lock_irqsave(&fbc->lock, flags);
pcount = per_cpu_ptr(fbc->counters, cpu);
fbc->count += *pcount;
*pcount = 0;
raw_spin_unlock_irqrestore(&fbc->lock, flags);
}
spin_unlock(&percpu_counters_lock);
#endif
return NOTIFY_OK;
}
int percpu_counter_compare(struct percpu_counter *fbc, s64 rhs)
{
s64 count;
count = percpu_counter_read(fbc);
if (abs(count - rhs) > (percpu_counter_batch*num_online_cpus())) {
if (count > rhs)
return 1;
else
return -1;
}
count = percpu_counter_sum(fbc);
if (count > rhs)
return 1;
else if (count < rhs)
return -1;
else
return 0;
}
static int __init percpu_counter_startup(void)
{
compute_batch_value();
hotcpu_notifier(percpu_counter_hotcpu_callback, 0);
return 0;
}
