static inline struct cpuacct *css_ca(struct cgroup_subsys_state *css)
{
return css ? container_of(css, struct cpuacct, css) : NULL;
}
static inline struct cpuacct *task_ca(struct task_struct *tsk)
{
return css_ca(task_css(tsk, cpuacct_cgrp_id));
}
static inline struct cpuacct *parent_ca(struct cpuacct *ca)
{
return css_ca(ca->css.parent);
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
ca->cpuusage = alloc_percpu(struct cpuacct_usage);
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
static u64 cpuacct_cpuusage_read(struct cpuacct *ca, int cpu,
enum cpuacct_stat_index index)
{
struct cpuacct_usage *cpuusage = per_cpu_ptr(ca->cpuusage, cpu);
u64 data;
BUG_ON(index > CPUACCT_STAT_NSTATS);
#ifndef CONFIG_64BIT
raw_spin_lock_irq(&cpu_rq(cpu)->lock);
#endif
if (index == CPUACCT_STAT_NSTATS) {
int i = 0;
data = 0;
for (i = 0; i < CPUACCT_STAT_NSTATS; i++)
data += cpuusage->usages[i];
} else {
data = cpuusage->usages[index];
}
#ifndef CONFIG_64BIT
raw_spin_unlock_irq(&cpu_rq(cpu)->lock);
#endif
return data;
}
static void cpuacct_cpuusage_write(struct cpuacct *ca, int cpu, u64 val)
{
struct cpuacct_usage *cpuusage = per_cpu_ptr(ca->cpuusage, cpu);
int i;
#ifndef CONFIG_64BIT
raw_spin_lock_irq(&cpu_rq(cpu)->lock);
#endif
for (i = 0; i < CPUACCT_STAT_NSTATS; i++)
cpuusage->usages[i] = val;
#ifndef CONFIG_64BIT
raw_spin_unlock_irq(&cpu_rq(cpu)->lock);
#endif
}
static u64 __cpuusage_read(struct cgroup_subsys_state *css,
enum cpuacct_stat_index index)
{
struct cpuacct *ca = css_ca(css);
u64 totalcpuusage = 0;
int i;
for_each_possible_cpu(i)
totalcpuusage += cpuacct_cpuusage_read(ca, i, index);
return totalcpuusage;
}
static u64 cpuusage_user_read(struct cgroup_subsys_state *css,
struct cftype *cft)
{
return __cpuusage_read(css, CPUACCT_STAT_USER);
}
static u64 cpuusage_sys_read(struct cgroup_subsys_state *css,
struct cftype *cft)
{
return __cpuusage_read(css, CPUACCT_STAT_SYSTEM);
}
static u64 cpuusage_read(struct cgroup_subsys_state *css, struct cftype *cft)
{
return __cpuusage_read(css, CPUACCT_STAT_NSTATS);
}
static int cpuusage_write(struct cgroup_subsys_state *css, struct cftype *cft,
u64 val)
{
struct cpuacct *ca = css_ca(css);
int cpu;
if (val)
return -EINVAL;
for_each_possible_cpu(cpu)
cpuacct_cpuusage_write(ca, cpu, 0);
return 0;
}
static int __cpuacct_percpu_seq_show(struct seq_file *m,
enum cpuacct_stat_index index)
{
struct cpuacct *ca = css_ca(seq_css(m));
u64 percpu;
int i;
for_each_possible_cpu(i) {
percpu = cpuacct_cpuusage_read(ca, i, index);
seq_printf(m, "%llu ", (unsigned long long) percpu);
}
seq_printf(m, "\n");
return 0;
}
static int cpuacct_percpu_user_seq_show(struct seq_file *m, void *V)
{
return __cpuacct_percpu_seq_show(m, CPUACCT_STAT_USER);
}
static int cpuacct_percpu_sys_seq_show(struct seq_file *m, void *V)
{
return __cpuacct_percpu_seq_show(m, CPUACCT_STAT_SYSTEM);
}
static int cpuacct_percpu_seq_show(struct seq_file *m, void *V)
{
return __cpuacct_percpu_seq_show(m, CPUACCT_STAT_NSTATS);
}
static int cpuacct_all_seq_show(struct seq_file *m, void *V)
{
struct cpuacct *ca = css_ca(seq_css(m));
int index;
int cpu;
seq_puts(m, "cpu");
for (index = 0; index < CPUACCT_STAT_NSTATS; index++)
seq_printf(m, " %s", cpuacct_stat_desc[index]);
seq_puts(m, "\n");
for_each_possible_cpu(cpu) {
struct cpuacct_usage *cpuusage = per_cpu_ptr(ca->cpuusage, cpu);
seq_printf(m, "%d", cpu);
for (index = 0; index < CPUACCT_STAT_NSTATS; index++) {
#ifndef CONFIG_64BIT
raw_spin_lock_irq(&cpu_rq(cpu)->lock);
#endif
seq_printf(m, " %llu", cpuusage->usages[index]);
#ifndef CONFIG_64BIT
raw_spin_unlock_irq(&cpu_rq(cpu)->lock);
#endif
}
seq_puts(m, "\n");
}
return 0;
}
static int cpuacct_stats_show(struct seq_file *sf, void *v)
{
struct cpuacct *ca = css_ca(seq_css(sf));
s64 val[CPUACCT_STAT_NSTATS];
int cpu;
int stat;
memset(val, 0, sizeof(val));
for_each_possible_cpu(cpu) {
u64 *cpustat = per_cpu_ptr(ca->cpustat, cpu)->cpustat;
val[CPUACCT_STAT_USER] += cpustat[CPUTIME_USER];
val[CPUACCT_STAT_USER] += cpustat[CPUTIME_NICE];
val[CPUACCT_STAT_SYSTEM] += cpustat[CPUTIME_SYSTEM];
val[CPUACCT_STAT_SYSTEM] += cpustat[CPUTIME_IRQ];
val[CPUACCT_STAT_SYSTEM] += cpustat[CPUTIME_SOFTIRQ];
}
for (stat = 0; stat < CPUACCT_STAT_NSTATS; stat++) {
seq_printf(sf, "%s %lld\n",
cpuacct_stat_desc[stat],
(long long)cputime64_to_clock_t(val[stat]));
}
return 0;
}
void cpuacct_charge(struct task_struct *tsk, u64 cputime)
{
struct cpuacct *ca;
int index = CPUACCT_STAT_SYSTEM;
struct pt_regs *regs = task_pt_regs(tsk);
if (regs && user_mode(regs))
index = CPUACCT_STAT_USER;
rcu_read_lock();
for (ca = task_ca(tsk); ca; ca = parent_ca(ca))
this_cpu_ptr(ca->cpuusage)->usages[index] += cputime;
rcu_read_unlock();
}
void cpuacct_account_field(struct task_struct *tsk, int index, u64 val)
{
struct cpuacct *ca;
rcu_read_lock();
for (ca = task_ca(tsk); ca != &root_cpuacct; ca = parent_ca(ca))
this_cpu_ptr(ca->cpustat)->cpustat[index] += val;
rcu_read_unlock();
}
