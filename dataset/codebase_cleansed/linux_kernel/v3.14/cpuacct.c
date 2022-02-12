static inline struct cpuacct *css_ca(struct cgroup_subsys_state *css)
{
return css ? container_of(css, struct cpuacct, css) : NULL;
}
static inline struct cpuacct *task_ca(struct task_struct *tsk)
{
return css_ca(task_css(tsk, cpuacct_subsys_id));
}
static inline struct cpuacct *parent_ca(struct cpuacct *ca)
{
return css_ca(css_parent(&ca->css));
}
static struct cgroup_subsys_state *
cpuacct_css_alloc(struct cgroup_subsys_state *parent_css)
{
struct cpuacct *ca;
if (!parent_css)
return &root_cpuacct.css;
ca = kzalloc(sizeof(*ca), GFP_KERNEL);
if (!ca)
goto out;
ca->cpuusage = alloc_percpu(u64);
if (!ca->cpuusage)
goto out_free_ca;
ca->cpustat = alloc_percpu(struct kernel_cpustat);
if (!ca->cpustat)
goto out_free_cpuusage;
return &ca->css;
out_free_cpuusage:
free_percpu(ca->cpuusage);
out_free_ca:
kfree(ca);
out:
return ERR_PTR(-ENOMEM);
}
static void cpuacct_css_free(struct cgroup_subsys_state *css)
{
struct cpuacct *ca = css_ca(css);
free_percpu(ca->cpustat);
free_percpu(ca->cpuusage);
kfree(ca);
}
static u64 cpuacct_cpuusage_read(struct cpuacct *ca, int cpu)
{
u64 *cpuusage = per_cpu_ptr(ca->cpuusage, cpu);
u64 data;
#ifndef CONFIG_64BIT
raw_spin_lock_irq(&cpu_rq(cpu)->lock);
data = *cpuusage;
raw_spin_unlock_irq(&cpu_rq(cpu)->lock);
#else
data = *cpuusage;
#endif
return data;
}
static void cpuacct_cpuusage_write(struct cpuacct *ca, int cpu, u64 val)
{
u64 *cpuusage = per_cpu_ptr(ca->cpuusage, cpu);
#ifndef CONFIG_64BIT
raw_spin_lock_irq(&cpu_rq(cpu)->lock);
*cpuusage = val;
raw_spin_unlock_irq(&cpu_rq(cpu)->lock);
#else
*cpuusage = val;
#endif
}
static u64 cpuusage_read(struct cgroup_subsys_state *css, struct cftype *cft)
{
struct cpuacct *ca = css_ca(css);
u64 totalcpuusage = 0;
int i;
for_each_present_cpu(i)
totalcpuusage += cpuacct_cpuusage_read(ca, i);
return totalcpuusage;
}
static int cpuusage_write(struct cgroup_subsys_state *css, struct cftype *cft,
u64 reset)
{
struct cpuacct *ca = css_ca(css);
int err = 0;
int i;
if (reset) {
err = -EINVAL;
goto out;
}
for_each_present_cpu(i)
cpuacct_cpuusage_write(ca, i, 0);
out:
return err;
}
static int cpuacct_percpu_seq_show(struct seq_file *m, void *V)
{
struct cpuacct *ca = css_ca(seq_css(m));
u64 percpu;
int i;
for_each_present_cpu(i) {
percpu = cpuacct_cpuusage_read(ca, i);
seq_printf(m, "%llu ", (unsigned long long) percpu);
}
seq_printf(m, "\n");
return 0;
}
static int cpuacct_stats_show(struct seq_file *sf, void *v)
{
struct cpuacct *ca = css_ca(seq_css(sf));
int cpu;
s64 val = 0;
for_each_online_cpu(cpu) {
struct kernel_cpustat *kcpustat = per_cpu_ptr(ca->cpustat, cpu);
val += kcpustat->cpustat[CPUTIME_USER];
val += kcpustat->cpustat[CPUTIME_NICE];
}
val = cputime64_to_clock_t(val);
seq_printf(sf, "%s %lld\n", cpuacct_stat_desc[CPUACCT_STAT_USER], val);
val = 0;
for_each_online_cpu(cpu) {
struct kernel_cpustat *kcpustat = per_cpu_ptr(ca->cpustat, cpu);
val += kcpustat->cpustat[CPUTIME_SYSTEM];
val += kcpustat->cpustat[CPUTIME_IRQ];
val += kcpustat->cpustat[CPUTIME_SOFTIRQ];
}
val = cputime64_to_clock_t(val);
seq_printf(sf, "%s %lld\n", cpuacct_stat_desc[CPUACCT_STAT_SYSTEM], val);
return 0;
}
void cpuacct_charge(struct task_struct *tsk, u64 cputime)
{
struct cpuacct *ca;
int cpu;
cpu = task_cpu(tsk);
rcu_read_lock();
ca = task_ca(tsk);
while (true) {
u64 *cpuusage = per_cpu_ptr(ca->cpuusage, cpu);
*cpuusage += cputime;
ca = parent_ca(ca);
if (!ca)
break;
}
rcu_read_unlock();
}
void cpuacct_account_field(struct task_struct *p, int index, u64 val)
{
struct kernel_cpustat *kcpustat;
struct cpuacct *ca;
rcu_read_lock();
ca = task_ca(p);
while (ca != &root_cpuacct) {
kcpustat = this_cpu_ptr(ca->cpustat);
kcpustat->cpustat[index] += val;
ca = parent_ca(ca);
}
rcu_read_unlock();
}
