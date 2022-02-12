static void reset_entries(void)
{
nr_entries = 0;
memset(entries, 0, sizeof(entries));
memset(tstat_hash_table, 0, sizeof(tstat_hash_table));
atomic_set(&overflow_count, 0);
}
static struct entry *alloc_entry(void)
{
if (nr_entries >= MAX_ENTRIES)
return NULL;
return entries + nr_entries++;
}
static int match_entries(struct entry *entry1, struct entry *entry2)
{
return entry1->timer == entry2->timer &&
entry1->start_func == entry2->start_func &&
entry1->expire_func == entry2->expire_func &&
entry1->pid == entry2->pid;
}
static struct entry *tstat_lookup(struct entry *entry, char *comm)
{
struct entry **head, *curr, *prev;
head = tstat_hashentry(entry);
curr = *head;
while (curr) {
if (match_entries(curr, entry))
return curr;
curr = curr->next;
}
prev = NULL;
curr = *head;
raw_spin_lock(&table_lock);
while (curr) {
if (match_entries(curr, entry))
goto out_unlock;
prev = curr;
curr = curr->next;
}
curr = alloc_entry();
if (curr) {
*curr = *entry;
curr->count = 0;
curr->next = NULL;
memcpy(curr->comm, comm, TASK_COMM_LEN);
smp_mb();
if (prev)
prev->next = curr;
else
*head = curr;
}
out_unlock:
raw_spin_unlock(&table_lock);
return curr;
}
void timer_stats_update_stats(void *timer, pid_t pid, void *startf,
void *timerf, char *comm, u32 tflags)
{
raw_spinlock_t *lock;
struct entry *entry, input;
unsigned long flags;
if (likely(!timer_stats_active))
return;
lock = &per_cpu(tstats_lookup_lock, raw_smp_processor_id());
input.timer = timer;
input.start_func = startf;
input.expire_func = timerf;
input.pid = pid;
input.flags = tflags;
raw_spin_lock_irqsave(lock, flags);
if (!timer_stats_active)
goto out_unlock;
entry = tstat_lookup(&input, comm);
if (likely(entry))
entry->count++;
else
atomic_inc(&overflow_count);
out_unlock:
raw_spin_unlock_irqrestore(lock, flags);
}
static void print_name_offset(struct seq_file *m, unsigned long addr)
{
char symname[KSYM_NAME_LEN];
if (lookup_symbol_name(addr, symname) < 0)
seq_printf(m, "<%p>", (void *)addr);
else
seq_printf(m, "%s", symname);
}
static int tstats_show(struct seq_file *m, void *v)
{
struct timespec64 period;
struct entry *entry;
unsigned long ms;
long events = 0;
ktime_t time;
int i;
mutex_lock(&show_mutex);
if (timer_stats_active)
time_stop = ktime_get();
time = ktime_sub(time_stop, time_start);
period = ktime_to_timespec64(time);
ms = period.tv_nsec / 1000000;
seq_puts(m, "Timer Stats Version: v0.3\n");
seq_printf(m, "Sample period: %ld.%03ld s\n", (long)period.tv_sec, ms);
if (atomic_read(&overflow_count))
seq_printf(m, "Overflow: %d entries\n", atomic_read(&overflow_count));
seq_printf(m, "Collection: %s\n", timer_stats_active ? "active" : "inactive");
for (i = 0; i < nr_entries; i++) {
entry = entries + i;
if (entry->flags & TIMER_DEFERRABLE) {
seq_printf(m, "%4luD, %5d %-16s ",
entry->count, entry->pid, entry->comm);
} else {
seq_printf(m, " %4lu, %5d %-16s ",
entry->count, entry->pid, entry->comm);
}
print_name_offset(m, (unsigned long)entry->start_func);
seq_puts(m, " (");
print_name_offset(m, (unsigned long)entry->expire_func);
seq_puts(m, ")\n");
events += entry->count;
}
ms += period.tv_sec * 1000;
if (!ms)
ms = 1;
if (events && period.tv_sec)
seq_printf(m, "%ld total events, %ld.%03ld events/sec\n",
events, events * 1000 / ms,
(events * 1000000 / ms) % 1000);
else
seq_printf(m, "%ld total events\n", events);
mutex_unlock(&show_mutex);
return 0;
}
static void sync_access(void)
{
unsigned long flags;
int cpu;
for_each_online_cpu(cpu) {
raw_spinlock_t *lock = &per_cpu(tstats_lookup_lock, cpu);
raw_spin_lock_irqsave(lock, flags);
raw_spin_unlock_irqrestore(lock, flags);
}
}
static ssize_t tstats_write(struct file *file, const char __user *buf,
size_t count, loff_t *offs)
{
char ctl[2];
if (count != 2 || *offs)
return -EINVAL;
if (copy_from_user(ctl, buf, count))
return -EFAULT;
mutex_lock(&show_mutex);
switch (ctl[0]) {
case '0':
if (timer_stats_active) {
timer_stats_active = 0;
time_stop = ktime_get();
sync_access();
}
break;
case '1':
if (!timer_stats_active) {
reset_entries();
time_start = ktime_get();
smp_mb();
timer_stats_active = 1;
}
break;
default:
count = -EINVAL;
}
mutex_unlock(&show_mutex);
return count;
}
static int tstats_open(struct inode *inode, struct file *filp)
{
return single_open(filp, tstats_show, NULL);
}
void __init init_timer_stats(void)
{
int cpu;
for_each_possible_cpu(cpu)
raw_spin_lock_init(&per_cpu(tstats_lookup_lock, cpu));
}
static int __init init_tstats_procfs(void)
{
struct proc_dir_entry *pe;
pe = proc_create("timer_stats", 0644, NULL, &tstats_fops);
if (!pe)
return -ENOMEM;
return 0;
}
