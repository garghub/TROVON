static inline unsigned long wait_piowc(void)
{
volatile unsigned long *piows;
unsigned long zeroval, ws;
piows = pda->pio_write_status_addr;
zeroval = pda->pio_write_status_val;
do {
cpu_relax();
} while (((ws = *piows) & SH_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_MASK) != zeroval);
return (ws & SH_PIO_WRITE_STATUS_WRITE_DEADLOCK_MASK) != 0;
}
void sn_migrate(struct task_struct *task)
{
pda_t *last_pda = pdacpu(task_thread_info(task)->last_cpu);
volatile unsigned long *adr = last_pda->pio_write_status_addr;
unsigned long val = last_pda->pio_write_status_val;
while (unlikely((*adr & SH_PIO_WRITE_STATUS_PENDING_WRITE_COUNT_MASK)
!= val))
cpu_relax();
}
void sn_tlb_migrate_finish(struct mm_struct *mm)
{
if (mm == current->mm && mm && atomic_read(&mm->mm_users) == 1)
flush_tlb_mm(mm);
}
static void
sn2_ipi_flush_all_tlb(struct mm_struct *mm)
{
unsigned long itc;
itc = ia64_get_itc();
smp_flush_tlb_cpumask(*mm_cpumask(mm));
itc = ia64_get_itc() - itc;
__this_cpu_add(ptcstats.shub_ipi_flushes_itc_clocks, itc);
__this_cpu_inc(ptcstats.shub_ipi_flushes);
}
void
sn2_global_tlb_purge(struct mm_struct *mm, unsigned long start,
unsigned long end, unsigned long nbits)
{
int i, ibegin, shub1, cnode, mynasid, cpu, lcpu = 0, nasid;
int mymm = (mm == current->active_mm && mm == current->mm);
int use_cpu_ptcga;
volatile unsigned long *ptc0, *ptc1;
unsigned long itc, itc2, flags, data0 = 0, data1 = 0, rr_value, old_rr = 0;
short nix;
nodemask_t nodes_flushed;
int active, max_active, deadlock, flush_opt = sn2_flush_opt;
if (flush_opt > 2) {
sn2_ipi_flush_all_tlb(mm);
return;
}
nodes_clear(nodes_flushed);
i = 0;
for_each_cpu(cpu, mm_cpumask(mm)) {
cnode = cpu_to_node(cpu);
node_set(cnode, nodes_flushed);
lcpu = cpu;
i++;
}
if (i == 0)
return;
preempt_disable();
if (likely(i == 1 && lcpu == smp_processor_id() && mymm)) {
do {
ia64_ptcl(start, nbits << 2);
start += (1UL << nbits);
} while (start < end);
ia64_srlz_i();
__this_cpu_inc(ptcstats.ptc_l);
preempt_enable();
return;
}
if (atomic_read(&mm->mm_users) == 1 && mymm) {
flush_tlb_mm(mm);
__this_cpu_inc(ptcstats.change_rid);
preempt_enable();
return;
}
if (flush_opt == 2) {
sn2_ipi_flush_all_tlb(mm);
preempt_enable();
return;
}
itc = ia64_get_itc();
nix = nodes_weight(nodes_flushed);
rr_value = (mm->context << 3) | REGION_NUMBER(start);
shub1 = is_shub1();
if (shub1) {
data0 = (1UL << SH1_PTC_0_A_SHFT) |
(nbits << SH1_PTC_0_PS_SHFT) |
(rr_value << SH1_PTC_0_RID_SHFT) |
(1UL << SH1_PTC_0_START_SHFT);
ptc0 = (long *)GLOBAL_MMR_PHYS_ADDR(0, SH1_PTC_0);
ptc1 = (long *)GLOBAL_MMR_PHYS_ADDR(0, SH1_PTC_1);
} else {
data0 = (1UL << SH2_PTC_A_SHFT) |
(nbits << SH2_PTC_PS_SHFT) |
(1UL << SH2_PTC_START_SHFT);
ptc0 = (long *)GLOBAL_MMR_PHYS_ADDR(0, SH2_PTC +
(rr_value << SH2_PTC_RID_SHFT));
ptc1 = NULL;
}
mynasid = get_nasid();
use_cpu_ptcga = local_node_uses_ptc_ga(shub1);
max_active = max_active_pio(shub1);
itc = ia64_get_itc();
spin_lock_irqsave(PTC_LOCK(shub1), flags);
itc2 = ia64_get_itc();
__this_cpu_add(ptcstats.lock_itc_clocks, itc2 - itc);
__this_cpu_inc(ptcstats.shub_ptc_flushes);
__this_cpu_add(ptcstats.nodes_flushed, nix);
if (!mymm)
__this_cpu_inc(ptcstats.shub_ptc_flushes_not_my_mm);
if (use_cpu_ptcga && !mymm) {
old_rr = ia64_get_rr(start);
ia64_set_rr(start, (old_rr & 0xff) | (rr_value << 8));
ia64_srlz_d();
}
wait_piowc();
do {
if (shub1)
data1 = start | (1UL << SH1_PTC_1_START_SHFT);
else
data0 = (data0 & ~SH2_PTC_ADDR_MASK) | (start & SH2_PTC_ADDR_MASK);
deadlock = 0;
active = 0;
ibegin = 0;
i = 0;
for_each_node_mask(cnode, nodes_flushed) {
nasid = cnodeid_to_nasid(cnode);
if (use_cpu_ptcga && unlikely(nasid == mynasid)) {
ia64_ptcga(start, nbits << 2);
ia64_srlz_i();
} else {
ptc0 = CHANGE_NASID(nasid, ptc0);
if (ptc1)
ptc1 = CHANGE_NASID(nasid, ptc1);
pio_atomic_phys_write_mmrs(ptc0, data0, ptc1, data1);
active++;
}
if (active >= max_active || i == (nix - 1)) {
if ((deadlock = wait_piowc())) {
if (flush_opt == 1)
goto done;
sn2_ptc_deadlock_recovery(nodes_flushed, ibegin, i, mynasid, ptc0, data0, ptc1, data1);
if (reset_max_active_on_deadlock())
max_active = 1;
}
active = 0;
ibegin = i + 1;
}
i++;
}
start += (1UL << nbits);
} while (start < end);
done:
itc2 = ia64_get_itc() - itc2;
__this_cpu_add(ptcstats.shub_itc_clocks, itc2);
if (itc2 > __this_cpu_read(ptcstats.shub_itc_clocks_max))
__this_cpu_write(ptcstats.shub_itc_clocks_max, itc2);
if (old_rr) {
ia64_set_rr(start, old_rr);
ia64_srlz_d();
}
spin_unlock_irqrestore(PTC_LOCK(shub1), flags);
if (flush_opt == 1 && deadlock) {
__this_cpu_inc(ptcstats.deadlocks);
sn2_ipi_flush_all_tlb(mm);
}
preempt_enable();
}
void
sn2_ptc_deadlock_recovery(nodemask_t nodes, short ib, short ie, int mynasid,
volatile unsigned long *ptc0, unsigned long data0,
volatile unsigned long *ptc1, unsigned long data1)
{
short nasid, i;
int cnode;
unsigned long *piows, zeroval, n;
__this_cpu_inc(ptcstats.deadlocks);
piows = (unsigned long *) pda->pio_write_status_addr;
zeroval = pda->pio_write_status_val;
i = 0;
for_each_node_mask(cnode, nodes) {
if (i < ib)
goto next;
if (i > ie)
break;
nasid = cnodeid_to_nasid(cnode);
if (local_node_uses_ptc_ga(is_shub1()) && nasid == mynasid)
goto next;
ptc0 = CHANGE_NASID(nasid, ptc0);
if (ptc1)
ptc1 = CHANGE_NASID(nasid, ptc1);
n = sn2_ptc_deadlock_recovery_core(ptc0, data0, ptc1, data1, piows, zeroval);
__this_cpu_add(ptcstats.deadlocks2, n);
next:
i++;
}
}
void sn_send_IPI_phys(int nasid, long physid, int vector, int delivery_mode)
{
long val;
unsigned long flags = 0;
volatile long *p;
p = (long *)GLOBAL_MMR_PHYS_ADDR(nasid, SH_IPI_INT);
val = (1UL << SH_IPI_INT_SEND_SHFT) |
(physid << SH_IPI_INT_PID_SHFT) |
((long)delivery_mode << SH_IPI_INT_TYPE_SHFT) |
((long)vector << SH_IPI_INT_IDX_SHFT) |
(0x000feeUL << SH_IPI_INT_BASE_SHFT);
mb();
if (enable_shub_wars_1_1()) {
spin_lock_irqsave(&sn2_global_ptc_lock, flags);
}
pio_phys_write_mmr(p, val);
if (enable_shub_wars_1_1()) {
wait_piowc();
spin_unlock_irqrestore(&sn2_global_ptc_lock, flags);
}
}
void sn2_send_IPI(int cpuid, int vector, int delivery_mode, int redirect)
{
long physid;
int nasid;
physid = cpu_physical_id(cpuid);
nasid = cpuid_to_nasid(cpuid);
if (unlikely(nasid == -1))
ia64_sn_get_sapic_info(physid, &nasid, NULL, NULL);
sn_send_IPI_phys(nasid, physid, vector, delivery_mode);
}
bool sn_cpu_disable_allowed(int cpu)
{
if (is_shub2() && sn_prom_feature_available(PRF_CPU_DISABLE_SUPPORT)) {
if (cpu != 0)
return true;
else
printk(KERN_WARNING
"Disabling the boot processor is not allowed.\n");
} else
printk(KERN_WARNING
"CPU disable is not supported on this system.\n");
return false;
}
static void *sn2_ptc_seq_start(struct seq_file *file, loff_t * offset)
{
if (*offset < nr_cpu_ids)
return offset;
return NULL;
}
static void *sn2_ptc_seq_next(struct seq_file *file, void *data, loff_t * offset)
{
(*offset)++;
if (*offset < nr_cpu_ids)
return offset;
return NULL;
}
static void sn2_ptc_seq_stop(struct seq_file *file, void *data)
{
}
static int sn2_ptc_seq_show(struct seq_file *file, void *data)
{
struct ptc_stats *stat;
int cpu;
cpu = *(loff_t *) data;
if (!cpu) {
seq_printf(file,
"# cpu ptc_l newrid ptc_flushes nodes_flushed deadlocks lock_nsec shub_nsec shub_nsec_max not_my_mm deadlock2 ipi_fluches ipi_nsec\n");
seq_printf(file, "# ptctest %d, flushopt %d\n", sn2_ptctest, sn2_flush_opt);
}
if (cpu < nr_cpu_ids && cpu_online(cpu)) {
stat = &per_cpu(ptcstats, cpu);
seq_printf(file, "cpu %d %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld\n", cpu, stat->ptc_l,
stat->change_rid, stat->shub_ptc_flushes, stat->nodes_flushed,
stat->deadlocks,
1000 * stat->lock_itc_clocks / per_cpu(ia64_cpu_info, cpu).cyc_per_usec,
1000 * stat->shub_itc_clocks / per_cpu(ia64_cpu_info, cpu).cyc_per_usec,
1000 * stat->shub_itc_clocks_max / per_cpu(ia64_cpu_info, cpu).cyc_per_usec,
stat->shub_ptc_flushes_not_my_mm,
stat->deadlocks2,
stat->shub_ipi_flushes,
1000 * stat->shub_ipi_flushes_itc_clocks / per_cpu(ia64_cpu_info, cpu).cyc_per_usec);
}
return 0;
}
static ssize_t sn2_ptc_proc_write(struct file *file, const char __user *user, size_t count, loff_t *data)
{
int cpu;
char optstr[64];
if (count == 0 || count > sizeof(optstr))
return -EINVAL;
if (copy_from_user(optstr, user, count))
return -EFAULT;
optstr[count - 1] = '\0';
sn2_flush_opt = simple_strtoul(optstr, NULL, 0);
for_each_online_cpu(cpu)
memset(&per_cpu(ptcstats, cpu), 0, sizeof(struct ptc_stats));
return count;
}
static int sn2_ptc_proc_open(struct inode *inode, struct file *file)
{
return seq_open(file, &sn2_ptc_seq_ops);
}
static int __init sn2_ptc_init(void)
{
if (!ia64_platform_is("sn2"))
return 0;
proc_sn2_ptc = proc_create(PTC_BASENAME, 0444,
NULL, &proc_sn2_ptc_operations);
if (!proc_sn2_ptc) {
printk(KERN_ERR "unable to create %s proc entry", PTC_BASENAME);
return -EINVAL;
}
spin_lock_init(&sn2_global_ptc_lock);
return 0;
}
static void __exit sn2_ptc_exit(void)
{
remove_proc_entry(PTC_BASENAME, NULL);
}
