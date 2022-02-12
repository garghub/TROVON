static int show_stat(struct seq_file *p, void *v)
{
int i, j;
unsigned long jif;
cputime64_t user, nice, system, idle, iowait, irq, softirq, steal;
cputime64_t guest, guest_nice;
u64 sum = 0;
u64 sum_softirq = 0;
unsigned int per_softirq_sums[NR_SOFTIRQS] = {0};
struct timespec boottime;
user = nice = system = idle = iowait =
irq = softirq = steal = cputime64_zero;
guest = guest_nice = cputime64_zero;
getboottime(&boottime);
jif = boottime.tv_sec;
for_each_possible_cpu(i) {
user = cputime64_add(user, kstat_cpu(i).cpustat.user);
nice = cputime64_add(nice, kstat_cpu(i).cpustat.nice);
system = cputime64_add(system, kstat_cpu(i).cpustat.system);
idle = cputime64_add(idle, kstat_cpu(i).cpustat.idle);
idle = cputime64_add(idle, arch_idle_time(i));
iowait = cputime64_add(iowait, kstat_cpu(i).cpustat.iowait);
irq = cputime64_add(irq, kstat_cpu(i).cpustat.irq);
softirq = cputime64_add(softirq, kstat_cpu(i).cpustat.softirq);
steal = cputime64_add(steal, kstat_cpu(i).cpustat.steal);
guest = cputime64_add(guest, kstat_cpu(i).cpustat.guest);
guest_nice = cputime64_add(guest_nice,
kstat_cpu(i).cpustat.guest_nice);
sum += kstat_cpu_irqs_sum(i);
sum += arch_irq_stat_cpu(i);
for (j = 0; j < NR_SOFTIRQS; j++) {
unsigned int softirq_stat = kstat_softirqs_cpu(j, i);
per_softirq_sums[j] += softirq_stat;
sum_softirq += softirq_stat;
}
}
sum += arch_irq_stat();
seq_printf(p, "cpu %llu %llu %llu %llu %llu %llu %llu %llu %llu "
"%llu\n",
(unsigned long long)cputime64_to_clock_t(user),
(unsigned long long)cputime64_to_clock_t(nice),
(unsigned long long)cputime64_to_clock_t(system),
(unsigned long long)cputime64_to_clock_t(idle),
(unsigned long long)cputime64_to_clock_t(iowait),
(unsigned long long)cputime64_to_clock_t(irq),
(unsigned long long)cputime64_to_clock_t(softirq),
(unsigned long long)cputime64_to_clock_t(steal),
(unsigned long long)cputime64_to_clock_t(guest),
(unsigned long long)cputime64_to_clock_t(guest_nice));
for_each_online_cpu(i) {
user = kstat_cpu(i).cpustat.user;
nice = kstat_cpu(i).cpustat.nice;
system = kstat_cpu(i).cpustat.system;
idle = kstat_cpu(i).cpustat.idle;
idle = cputime64_add(idle, arch_idle_time(i));
iowait = kstat_cpu(i).cpustat.iowait;
irq = kstat_cpu(i).cpustat.irq;
softirq = kstat_cpu(i).cpustat.softirq;
steal = kstat_cpu(i).cpustat.steal;
guest = kstat_cpu(i).cpustat.guest;
guest_nice = kstat_cpu(i).cpustat.guest_nice;
seq_printf(p,
"cpu%d %llu %llu %llu %llu %llu %llu %llu %llu %llu "
"%llu\n",
i,
(unsigned long long)cputime64_to_clock_t(user),
(unsigned long long)cputime64_to_clock_t(nice),
(unsigned long long)cputime64_to_clock_t(system),
(unsigned long long)cputime64_to_clock_t(idle),
(unsigned long long)cputime64_to_clock_t(iowait),
(unsigned long long)cputime64_to_clock_t(irq),
(unsigned long long)cputime64_to_clock_t(softirq),
(unsigned long long)cputime64_to_clock_t(steal),
(unsigned long long)cputime64_to_clock_t(guest),
(unsigned long long)cputime64_to_clock_t(guest_nice));
}
seq_printf(p, "intr %llu", (unsigned long long)sum);
for_each_irq_nr(j)
seq_printf(p, " %u", kstat_irqs(j));
seq_printf(p,
"\nctxt %llu\n"
"btime %lu\n"
"processes %lu\n"
"procs_running %lu\n"
"procs_blocked %lu\n",
nr_context_switches(),
(unsigned long)jif,
total_forks,
nr_running(),
nr_iowait());
seq_printf(p, "softirq %llu", (unsigned long long)sum_softirq);
for (i = 0; i < NR_SOFTIRQS; i++)
seq_printf(p, " %u", per_softirq_sums[i]);
seq_putc(p, '\n');
return 0;
}
static int stat_open(struct inode *inode, struct file *file)
{
unsigned size = 4096 * (1 + num_possible_cpus() / 32);
char *buf;
struct seq_file *m;
int res;
if (size > KMALLOC_MAX_SIZE)
size = KMALLOC_MAX_SIZE;
buf = kmalloc(size, GFP_KERNEL);
if (!buf)
return -ENOMEM;
res = single_open(file, show_stat, NULL);
if (!res) {
m = file->private_data;
m->buf = buf;
m->size = size;
} else
kfree(buf);
return res;
}
static int __init proc_stat_init(void)
{
proc_create("stat", 0, NULL, &proc_stat_operations);
return 0;
}
