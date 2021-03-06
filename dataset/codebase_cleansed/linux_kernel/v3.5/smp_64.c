void smp_info(struct seq_file *m)
{
int i;
seq_printf(m, "State:\n");
for_each_online_cpu(i)
seq_printf(m, "CPU%d:\t\tonline\n", i);
}
void smp_bogo(struct seq_file *m)
{
int i;
for_each_online_cpu(i)
seq_printf(m,
"Cpu%dClkTck\t: %016lx\n",
i, cpu_data(i).clock_tick);
}
void __cpuinit smp_callin(void)
{
int cpuid = hard_smp_processor_id();
__local_per_cpu_offset = __per_cpu_offset(cpuid);
if (tlb_type == hypervisor)
sun4v_ktsb_register();
__flush_tlb_all();
setup_sparc64_timer();
if (cheetah_pcache_forced_on)
cheetah_enable_pcache();
local_irq_enable();
callin_flag = 1;
__asm__ __volatile__("membar #Sync\n\t"
"flush %%g6" : : : "memory");
current_thread_info()->new_child = 0;
atomic_inc(&init_mm.mm_count);
current->active_mm = &init_mm;
notify_cpu_starting(cpuid);
while (!cpumask_test_cpu(cpuid, &smp_commenced_mask))
rmb();
ipi_call_lock_irq();
set_cpu_online(cpuid, true);
ipi_call_unlock_irq();
preempt_disable();
}
void cpu_panic(void)
{
printk("CPU[%d]: Returns from cpu_idle!\n", smp_processor_id());
panic("SMP bolixed\n");
}
static inline long get_delta (long *rt, long *master)
{
unsigned long best_t0 = 0, best_t1 = ~0UL, best_tm = 0;
unsigned long tcenter, t0, t1, tm;
unsigned long i;
for (i = 0; i < NUM_ITERS; i++) {
t0 = tick_ops->get_tick();
go[MASTER] = 1;
membar_safe("#StoreLoad");
while (!(tm = go[SLAVE]))
rmb();
go[SLAVE] = 0;
wmb();
t1 = tick_ops->get_tick();
if (t1 - t0 < best_t1 - best_t0)
best_t0 = t0, best_t1 = t1, best_tm = tm;
}
*rt = best_t1 - best_t0;
*master = best_tm - best_t0;
tcenter = (best_t0/2 + best_t1/2);
if (best_t0 % 2 + best_t1 % 2 == 2)
tcenter++;
return tcenter - best_tm;
}
void smp_synchronize_tick_client(void)
{
long i, delta, adj, adjust_latency = 0, done = 0;
unsigned long flags, rt, master_time_stamp;
#if DEBUG_TICK_SYNC
struct {
long rt;
long master;
long diff;
long lat;
} t[NUM_ROUNDS];
#endif
go[MASTER] = 1;
while (go[MASTER])
rmb();
local_irq_save(flags);
{
for (i = 0; i < NUM_ROUNDS; i++) {
delta = get_delta(&rt, &master_time_stamp);
if (delta == 0)
done = 1;
if (!done) {
if (i > 0) {
adjust_latency += -delta;
adj = -delta + adjust_latency/4;
} else
adj = -delta;
tick_ops->add_tick(adj);
}
#if DEBUG_TICK_SYNC
t[i].rt = rt;
t[i].master = master_time_stamp;
t[i].diff = delta;
t[i].lat = adjust_latency/4;
#endif
}
}
local_irq_restore(flags);
#if DEBUG_TICK_SYNC
for (i = 0; i < NUM_ROUNDS; i++)
printk("rt=%5ld master=%5ld diff=%5ld adjlat=%5ld\n",
t[i].rt, t[i].master, t[i].diff, t[i].lat);
#endif
printk(KERN_INFO "CPU %d: synchronized TICK with master CPU "
"(last diff %ld cycles, maxerr %lu cycles)\n",
smp_processor_id(), delta, rt);
}
static void smp_synchronize_one_tick(int cpu)
{
unsigned long flags, i;
go[MASTER] = 0;
smp_start_sync_tick_client(cpu);
while (!go[MASTER])
rmb();
go[MASTER] = 0;
membar_safe("#StoreLoad");
spin_lock_irqsave(&itc_sync_lock, flags);
{
for (i = 0; i < NUM_ROUNDS*NUM_ITERS; i++) {
while (!go[MASTER])
rmb();
go[MASTER] = 0;
wmb();
go[SLAVE] = tick_ops->get_tick();
membar_safe("#StoreLoad");
}
}
spin_unlock_irqrestore(&itc_sync_lock, flags);
}
static unsigned long kimage_addr_to_ra(void *p)
{
unsigned long val = (unsigned long) p;
return kern_base + (val - KERNBASE);
}
static void __cpuinit ldom_startcpu_cpuid(unsigned int cpu, unsigned long thread_reg, void **descrp)
{
extern unsigned long sparc64_ttable_tl0;
extern unsigned long kern_locked_tte_data;
struct hvtramp_descr *hdesc;
unsigned long trampoline_ra;
struct trap_per_cpu *tb;
u64 tte_vaddr, tte_data;
unsigned long hv_err;
int i;
hdesc = kzalloc(sizeof(*hdesc) +
(sizeof(struct hvtramp_mapping) *
num_kernel_image_mappings - 1),
GFP_KERNEL);
if (!hdesc) {
printk(KERN_ERR "ldom_startcpu_cpuid: Cannot allocate "
"hvtramp_descr.\n");
return;
}
*descrp = hdesc;
hdesc->cpu = cpu;
hdesc->num_mappings = num_kernel_image_mappings;
tb = &trap_block[cpu];
hdesc->fault_info_va = (unsigned long) &tb->fault_info;
hdesc->fault_info_pa = kimage_addr_to_ra(&tb->fault_info);
hdesc->thread_reg = thread_reg;
tte_vaddr = (unsigned long) KERNBASE;
tte_data = kern_locked_tte_data;
for (i = 0; i < hdesc->num_mappings; i++) {
hdesc->maps[i].vaddr = tte_vaddr;
hdesc->maps[i].tte = tte_data;
tte_vaddr += 0x400000;
tte_data += 0x400000;
}
trampoline_ra = kimage_addr_to_ra(hv_cpu_startup);
hv_err = sun4v_cpu_start(cpu, trampoline_ra,
kimage_addr_to_ra(&sparc64_ttable_tl0),
__pa(hdesc));
if (hv_err)
printk(KERN_ERR "ldom_startcpu_cpuid: sun4v_cpu_start() "
"gives error %lu\n", hv_err);
}
static int __cpuinit smp_boot_one_cpu(unsigned int cpu, struct task_struct *idle)
{
unsigned long entry =
(unsigned long)(&sparc64_cpu_startup);
unsigned long cookie =
(unsigned long)(&cpu_new_thread);
void *descr = NULL;
int timeout, ret;
callin_flag = 0;
cpu_new_thread = task_thread_info(idle);
if (tlb_type == hypervisor) {
#if defined(CONFIG_SUN_LDOMS) && defined(CONFIG_HOTPLUG_CPU)
if (ldom_domaining_enabled)
ldom_startcpu_cpuid(cpu,
(unsigned long) cpu_new_thread,
&descr);
else
#endif
prom_startcpu_cpuid(cpu, entry, cookie);
} else {
struct device_node *dp = of_find_node_by_cpuid(cpu);
prom_startcpu(dp->phandle, entry, cookie);
}
for (timeout = 0; timeout < 50000; timeout++) {
if (callin_flag)
break;
udelay(100);
}
if (callin_flag) {
ret = 0;
} else {
printk("Processor %d is stuck.\n", cpu);
ret = -ENODEV;
}
cpu_new_thread = NULL;
kfree(descr);
return ret;
}
static void spitfire_xcall_helper(u64 data0, u64 data1, u64 data2, u64 pstate, unsigned long cpu)
{
u64 result, target;
int stuck, tmp;
if (this_is_starfire) {
cpu = (((cpu & 0x3c) << 1) |
((cpu & 0x40) >> 4) |
(cpu & 0x3));
}
target = (cpu << 14) | 0x70;
again:
tmp = 0x40;
__asm__ __volatile__(
"wrpr %1, %2, %%pstate\n\t"
"stxa %4, [%0] %3\n\t"
"stxa %5, [%0+%8] %3\n\t"
"add %0, %8, %0\n\t"
"stxa %6, [%0+%8] %3\n\t"
"membar #Sync\n\t"
"stxa %%g0, [%7] %3\n\t"
"membar #Sync\n\t"
"mov 0x20, %%g1\n\t"
"ldxa [%%g1] 0x7f, %%g0\n\t"
"membar #Sync"
: "=r" (tmp)
: "r" (pstate), "i" (PSTATE_IE), "i" (ASI_INTR_W),
"r" (data0), "r" (data1), "r" (data2), "r" (target),
"r" (0x10), "0" (tmp)
: "g1");
stuck = 100000;
do {
__asm__ __volatile__("ldxa [%%g0] %1, %0"
: "=r" (result)
: "i" (ASI_INTR_DISPATCH_STAT));
if (result == 0) {
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
return;
}
stuck -= 1;
if (stuck == 0)
break;
} while (result & 0x1);
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
if (stuck == 0) {
printk("CPU[%d]: mondo stuckage result[%016llx]\n",
smp_processor_id(), result);
} else {
udelay(2);
goto again;
}
}
static void spitfire_xcall_deliver(struct trap_per_cpu *tb, int cnt)
{
u64 *mondo, data0, data1, data2;
u16 *cpu_list;
u64 pstate;
int i;
__asm__ __volatile__("rdpr %%pstate, %0" : "=r" (pstate));
cpu_list = __va(tb->cpu_list_pa);
mondo = __va(tb->cpu_mondo_block_pa);
data0 = mondo[0];
data1 = mondo[1];
data2 = mondo[2];
for (i = 0; i < cnt; i++)
spitfire_xcall_helper(data0, data1, data2, pstate, cpu_list[i]);
}
static void cheetah_xcall_deliver(struct trap_per_cpu *tb, int cnt)
{
int nack_busy_id, is_jbus, need_more;
u64 *mondo, pstate, ver, busy_mask;
u16 *cpu_list;
cpu_list = __va(tb->cpu_list_pa);
mondo = __va(tb->cpu_mondo_block_pa);
__asm__ ("rdpr %%ver, %0" : "=r" (ver));
is_jbus = ((ver >> 32) == __JALAPENO_ID ||
(ver >> 32) == __SERRANO_ID);
__asm__ __volatile__("rdpr %%pstate, %0" : "=r" (pstate));
retry:
need_more = 0;
__asm__ __volatile__("wrpr %0, %1, %%pstate\n\t"
: : "r" (pstate), "i" (PSTATE_IE));
__asm__ __volatile__("stxa %0, [%3] %6\n\t"
"stxa %1, [%4] %6\n\t"
"stxa %2, [%5] %6\n\t"
"membar #Sync\n\t"
:
: "r" (mondo[0]), "r" (mondo[1]), "r" (mondo[2]),
"r" (0x40), "r" (0x50), "r" (0x60),
"i" (ASI_INTR_W));
nack_busy_id = 0;
busy_mask = 0;
{
int i;
for (i = 0; i < cnt; i++) {
u64 target, nr;
nr = cpu_list[i];
if (nr == 0xffff)
continue;
target = (nr << 14) | 0x70;
if (is_jbus) {
busy_mask |= (0x1UL << (nr * 2));
} else {
target |= (nack_busy_id << 24);
busy_mask |= (0x1UL <<
(nack_busy_id * 2));
}
__asm__ __volatile__(
"stxa %%g0, [%0] %1\n\t"
"membar #Sync\n\t"
:
: "r" (target), "i" (ASI_INTR_W));
nack_busy_id++;
if (nack_busy_id == 32) {
need_more = 1;
break;
}
}
}
{
u64 dispatch_stat, nack_mask;
long stuck;
stuck = 100000 * nack_busy_id;
nack_mask = busy_mask << 1;
do {
__asm__ __volatile__("ldxa [%%g0] %1, %0"
: "=r" (dispatch_stat)
: "i" (ASI_INTR_DISPATCH_STAT));
if (!(dispatch_stat & (busy_mask | nack_mask))) {
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
if (unlikely(need_more)) {
int i, this_cnt = 0;
for (i = 0; i < cnt; i++) {
if (cpu_list[i] == 0xffff)
continue;
cpu_list[i] = 0xffff;
this_cnt++;
if (this_cnt == 32)
break;
}
goto retry;
}
return;
}
if (!--stuck)
break;
} while (dispatch_stat & busy_mask);
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
: : "r" (pstate));
if (dispatch_stat & busy_mask) {
printk("CPU[%d]: mondo stuckage result[%016llx]\n",
smp_processor_id(), dispatch_stat);
} else {
int i, this_busy_nack = 0;
udelay(2 * nack_busy_id);
for (i = 0; i < cnt; i++) {
u64 check_mask, nr;
nr = cpu_list[i];
if (nr == 0xffff)
continue;
if (is_jbus)
check_mask = (0x2UL << (2*nr));
else
check_mask = (0x2UL <<
this_busy_nack);
if ((dispatch_stat & check_mask) == 0)
cpu_list[i] = 0xffff;
this_busy_nack += 2;
if (this_busy_nack == 64)
break;
}
goto retry;
}
}
}
static void hypervisor_xcall_deliver(struct trap_per_cpu *tb, int cnt)
{
int retries, this_cpu, prev_sent, i, saw_cpu_error;
unsigned long status;
u16 *cpu_list;
this_cpu = smp_processor_id();
cpu_list = __va(tb->cpu_list_pa);
saw_cpu_error = 0;
retries = 0;
prev_sent = 0;
do {
int forward_progress, n_sent;
status = sun4v_cpu_mondo_send(cnt,
tb->cpu_list_pa,
tb->cpu_mondo_block_pa);
if (likely(status == HV_EOK))
break;
n_sent = 0;
for (i = 0; i < cnt; i++) {
if (likely(cpu_list[i] == 0xffff))
n_sent++;
}
forward_progress = 0;
if (n_sent > prev_sent)
forward_progress = 1;
prev_sent = n_sent;
if (unlikely(status == HV_ECPUERROR)) {
for (i = 0; i < cnt; i++) {
long err;
u16 cpu;
cpu = cpu_list[i];
if (cpu == 0xffff)
continue;
err = sun4v_cpu_state(cpu);
if (err == HV_CPU_STATE_ERROR) {
saw_cpu_error = (cpu + 1);
cpu_list[i] = 0xffff;
}
}
} else if (unlikely(status != HV_EWOULDBLOCK))
goto fatal_mondo_error;
if (unlikely(!forward_progress)) {
if (unlikely(++retries > 10000))
goto fatal_mondo_timeout;
udelay(2 * cnt);
}
} while (1);
if (unlikely(saw_cpu_error))
goto fatal_mondo_cpu_error;
return;
fatal_mondo_cpu_error:
printk(KERN_CRIT "CPU[%d]: SUN4V mondo cpu error, some target cpus "
"(including %d) were in error state\n",
this_cpu, saw_cpu_error - 1);
return;
fatal_mondo_timeout:
printk(KERN_CRIT "CPU[%d]: SUN4V mondo timeout, no forward "
" progress after %d retries.\n",
this_cpu, retries);
goto dump_cpu_list_and_out;
fatal_mondo_error:
printk(KERN_CRIT "CPU[%d]: Unexpected SUN4V mondo error %lu\n",
this_cpu, status);
printk(KERN_CRIT "CPU[%d]: Args were cnt(%d) cpulist_pa(%lx) "
"mondo_block_pa(%lx)\n",
this_cpu, cnt, tb->cpu_list_pa, tb->cpu_mondo_block_pa);
dump_cpu_list_and_out:
printk(KERN_CRIT "CPU[%d]: CPU list [ ", this_cpu);
for (i = 0; i < cnt; i++)
printk("%u ", cpu_list[i]);
printk("]\n");
}
static void xcall_deliver(u64 data0, u64 data1, u64 data2, const cpumask_t *mask)
{
struct trap_per_cpu *tb;
int this_cpu, i, cnt;
unsigned long flags;
u16 *cpu_list;
u64 *mondo;
local_irq_save(flags);
this_cpu = smp_processor_id();
tb = &trap_block[this_cpu];
mondo = __va(tb->cpu_mondo_block_pa);
mondo[0] = data0;
mondo[1] = data1;
mondo[2] = data2;
wmb();
cpu_list = __va(tb->cpu_list_pa);
cnt = 0;
for_each_cpu(i, mask) {
if (i == this_cpu || !cpu_online(i))
continue;
cpu_list[cnt++] = i;
}
if (cnt)
xcall_deliver_impl(tb, cnt);
local_irq_restore(flags);
}
static void smp_cross_call_masked(unsigned long *func, u32 ctx, u64 data1, u64 data2, const cpumask_t *mask)
{
u64 data0 = (((u64)ctx)<<32 | (((u64)func) & 0xffffffff));
xcall_deliver(data0, data1, data2, mask);
}
static void smp_cross_call(unsigned long *func, u32 ctx, u64 data1, u64 data2)
{
smp_cross_call_masked(func, ctx, data1, data2, cpu_online_mask);
}
static void smp_start_sync_tick_client(int cpu)
{
xcall_deliver((u64) &xcall_sync_tick, 0, 0,
cpumask_of(cpu));
}
void arch_send_call_function_ipi_mask(const struct cpumask *mask)
{
xcall_deliver((u64) &xcall_call_function, 0, 0, mask);
}
void arch_send_call_function_single_ipi(int cpu)
{
xcall_deliver((u64) &xcall_call_function_single, 0, 0,
cpumask_of(cpu));
}
void __irq_entry smp_call_function_client(int irq, struct pt_regs *regs)
{
clear_softint(1 << irq);
generic_smp_call_function_interrupt();
}
void __irq_entry smp_call_function_single_client(int irq, struct pt_regs *regs)
{
clear_softint(1 << irq);
generic_smp_call_function_single_interrupt();
}
static void tsb_sync(void *info)
{
struct trap_per_cpu *tp = &trap_block[raw_smp_processor_id()];
struct mm_struct *mm = info;
if (tp->pgd_paddr == __pa(mm->pgd))
tsb_context_switch(mm);
}
void smp_tsb_sync(struct mm_struct *mm)
{
smp_call_function_many(mm_cpumask(mm), tsb_sync, mm, 1);
}
static inline void __local_flush_dcache_page(struct page *page)
{
#ifdef DCACHE_ALIASING_POSSIBLE
__flush_dcache_page(page_address(page),
((tlb_type == spitfire) &&
page_mapping(page) != NULL));
#else
if (page_mapping(page) != NULL &&
tlb_type == spitfire)
__flush_icache_page(__pa(page_address(page)));
#endif
}
void smp_flush_dcache_page_impl(struct page *page, int cpu)
{
int this_cpu;
if (tlb_type == hypervisor)
return;
#ifdef CONFIG_DEBUG_DCFLUSH
atomic_inc(&dcpage_flushes);
#endif
this_cpu = get_cpu();
if (cpu == this_cpu) {
__local_flush_dcache_page(page);
} else if (cpu_online(cpu)) {
void *pg_addr = page_address(page);
u64 data0 = 0;
if (tlb_type == spitfire) {
data0 = ((u64)&xcall_flush_dcache_page_spitfire);
if (page_mapping(page) != NULL)
data0 |= ((u64)1 << 32);
} else if (tlb_type == cheetah || tlb_type == cheetah_plus) {
#ifdef DCACHE_ALIASING_POSSIBLE
data0 = ((u64)&xcall_flush_dcache_page_cheetah);
#endif
}
if (data0) {
xcall_deliver(data0, __pa(pg_addr),
(u64) pg_addr, cpumask_of(cpu));
#ifdef CONFIG_DEBUG_DCFLUSH
atomic_inc(&dcpage_flushes_xcall);
#endif
}
}
put_cpu();
}
void flush_dcache_page_all(struct mm_struct *mm, struct page *page)
{
void *pg_addr;
u64 data0;
if (tlb_type == hypervisor)
return;
preempt_disable();
#ifdef CONFIG_DEBUG_DCFLUSH
atomic_inc(&dcpage_flushes);
#endif
data0 = 0;
pg_addr = page_address(page);
if (tlb_type == spitfire) {
data0 = ((u64)&xcall_flush_dcache_page_spitfire);
if (page_mapping(page) != NULL)
data0 |= ((u64)1 << 32);
} else if (tlb_type == cheetah || tlb_type == cheetah_plus) {
#ifdef DCACHE_ALIASING_POSSIBLE
data0 = ((u64)&xcall_flush_dcache_page_cheetah);
#endif
}
if (data0) {
xcall_deliver(data0, __pa(pg_addr),
(u64) pg_addr, cpu_online_mask);
#ifdef CONFIG_DEBUG_DCFLUSH
atomic_inc(&dcpage_flushes_xcall);
#endif
}
__local_flush_dcache_page(page);
preempt_enable();
}
void __irq_entry smp_new_mmu_context_version_client(int irq, struct pt_regs *regs)
{
struct mm_struct *mm;
unsigned long flags;
clear_softint(1 << irq);
mm = current->active_mm;
if (unlikely(!mm || (mm == &init_mm)))
return;
spin_lock_irqsave(&mm->context.lock, flags);
if (unlikely(!CTX_VALID(mm->context)))
get_new_mmu_context(mm);
spin_unlock_irqrestore(&mm->context.lock, flags);
load_secondary_context(mm);
__flush_tlb_mm(CTX_HWBITS(mm->context),
SECONDARY_CONTEXT);
}
void smp_new_mmu_context_version(void)
{
smp_cross_call(&xcall_new_mmu_context_version, 0, 0, 0);
}
void kgdb_roundup_cpus(unsigned long flags)
{
smp_cross_call(&xcall_kgdb_capture, 0, 0, 0);
}
void smp_fetch_global_regs(void)
{
smp_cross_call(&xcall_fetch_glob_regs, 0, 0, 0);
}
void smp_flush_tlb_mm(struct mm_struct *mm)
{
u32 ctx = CTX_HWBITS(mm->context);
int cpu = get_cpu();
if (atomic_read(&mm->mm_users) == 1) {
cpumask_copy(mm_cpumask(mm), cpumask_of(cpu));
goto local_flush_and_out;
}
smp_cross_call_masked(&xcall_flush_tlb_mm,
ctx, 0, 0,
mm_cpumask(mm));
local_flush_and_out:
__flush_tlb_mm(ctx, SECONDARY_CONTEXT);
put_cpu();
}
void smp_flush_tlb_pending(struct mm_struct *mm, unsigned long nr, unsigned long *vaddrs)
{
u32 ctx = CTX_HWBITS(mm->context);
int cpu = get_cpu();
if (mm == current->mm && atomic_read(&mm->mm_users) == 1)
cpumask_copy(mm_cpumask(mm), cpumask_of(cpu));
else
smp_cross_call_masked(&xcall_flush_tlb_pending,
ctx, nr, (unsigned long) vaddrs,
mm_cpumask(mm));
__flush_tlb_pending(ctx, nr, vaddrs);
put_cpu();
}
void smp_flush_tlb_kernel_range(unsigned long start, unsigned long end)
{
start &= PAGE_MASK;
end = PAGE_ALIGN(end);
if (start != end) {
smp_cross_call(&xcall_flush_tlb_kernel_range,
0, start, end);
__flush_tlb_kernel_range(start, end);
}
}
void smp_capture(void)
{
int result = atomic_add_ret(1, &smp_capture_depth);
if (result == 1) {
int ncpus = num_online_cpus();
#ifdef CAPTURE_DEBUG
printk("CPU[%d]: Sending penguins to jail...",
smp_processor_id());
#endif
penguins_are_doing_time = 1;
atomic_inc(&smp_capture_registry);
smp_cross_call(&xcall_capture, 0, 0, 0);
while (atomic_read(&smp_capture_registry) != ncpus)
rmb();
#ifdef CAPTURE_DEBUG
printk("done\n");
#endif
}
}
void smp_release(void)
{
if (atomic_dec_and_test(&smp_capture_depth)) {
#ifdef CAPTURE_DEBUG
printk("CPU[%d]: Giving pardon to "
"imprisoned penguins\n",
smp_processor_id());
#endif
penguins_are_doing_time = 0;
membar_safe("#StoreLoad");
atomic_dec(&smp_capture_registry);
}
}
void __irq_entry smp_penguin_jailcell(int irq, struct pt_regs *regs)
{
clear_softint(1 << irq);
preempt_disable();
__asm__ __volatile__("flushw");
prom_world(1);
atomic_inc(&smp_capture_registry);
membar_safe("#StoreLoad");
while (penguins_are_doing_time)
rmb();
atomic_dec(&smp_capture_registry);
prom_world(0);
preempt_enable();
}
int setup_profiling_timer(unsigned int multiplier)
{
return -EINVAL;
}
void __init smp_prepare_cpus(unsigned int max_cpus)
{
}
void __devinit smp_prepare_boot_cpu(void)
{
}
void __init smp_setup_processor_id(void)
{
if (tlb_type == spitfire)
xcall_deliver_impl = spitfire_xcall_deliver;
else if (tlb_type == cheetah || tlb_type == cheetah_plus)
xcall_deliver_impl = cheetah_xcall_deliver;
else
xcall_deliver_impl = hypervisor_xcall_deliver;
}
void __devinit smp_fill_in_sib_core_maps(void)
{
unsigned int i;
for_each_present_cpu(i) {
unsigned int j;
cpumask_clear(&cpu_core_map[i]);
if (cpu_data(i).core_id == 0) {
cpumask_set_cpu(i, &cpu_core_map[i]);
continue;
}
for_each_present_cpu(j) {
if (cpu_data(i).core_id ==
cpu_data(j).core_id)
cpumask_set_cpu(j, &cpu_core_map[i]);
}
}
for_each_present_cpu(i) {
unsigned int j;
cpumask_clear(&per_cpu(cpu_sibling_map, i));
if (cpu_data(i).proc_id == -1) {
cpumask_set_cpu(i, &per_cpu(cpu_sibling_map, i));
continue;
}
for_each_present_cpu(j) {
if (cpu_data(i).proc_id ==
cpu_data(j).proc_id)
cpumask_set_cpu(j, &per_cpu(cpu_sibling_map, i));
}
}
}
int __cpuinit __cpu_up(unsigned int cpu, struct task_struct *tidle)
{
int ret = smp_boot_one_cpu(cpu, tidle);
if (!ret) {
cpumask_set_cpu(cpu, &smp_commenced_mask);
while (!cpu_online(cpu))
mb();
if (!cpu_online(cpu)) {
ret = -ENODEV;
} else {
if (tlb_type != hypervisor)
smp_synchronize_one_tick(cpu);
}
}
return ret;
}
void cpu_play_dead(void)
{
int cpu = smp_processor_id();
unsigned long pstate;
idle_task_exit();
if (tlb_type == hypervisor) {
struct trap_per_cpu *tb = &trap_block[cpu];
sun4v_cpu_qconf(HV_CPU_QUEUE_CPU_MONDO,
tb->cpu_mondo_pa, 0);
sun4v_cpu_qconf(HV_CPU_QUEUE_DEVICE_MONDO,
tb->dev_mondo_pa, 0);
sun4v_cpu_qconf(HV_CPU_QUEUE_RES_ERROR,
tb->resum_mondo_pa, 0);
sun4v_cpu_qconf(HV_CPU_QUEUE_NONRES_ERROR,
tb->nonresum_mondo_pa, 0);
}
cpumask_clear_cpu(cpu, &smp_commenced_mask);
membar_safe("#Sync");
local_irq_disable();
__asm__ __volatile__(
"rdpr %%pstate, %0\n\t"
"wrpr %0, %1, %%pstate"
: "=r" (pstate)
: "i" (PSTATE_IE));
while (1)
barrier();
}
int __cpu_disable(void)
{
int cpu = smp_processor_id();
cpuinfo_sparc *c;
int i;
for_each_cpu(i, &cpu_core_map[cpu])
cpumask_clear_cpu(cpu, &cpu_core_map[i]);
cpumask_clear(&cpu_core_map[cpu]);
for_each_cpu(i, &per_cpu(cpu_sibling_map, cpu))
cpumask_clear_cpu(cpu, &per_cpu(cpu_sibling_map, i));
cpumask_clear(&per_cpu(cpu_sibling_map, cpu));
c = &cpu_data(cpu);
c->core_id = 0;
c->proc_id = -1;
smp_wmb();
fixup_irqs();
local_irq_enable();
mdelay(1);
local_irq_disable();
ipi_call_lock();
set_cpu_online(cpu, false);
ipi_call_unlock();
cpu_map_rebuild();
return 0;
}
void __cpu_die(unsigned int cpu)
{
int i;
for (i = 0; i < 100; i++) {
smp_rmb();
if (!cpumask_test_cpu(cpu, &smp_commenced_mask))
break;
msleep(100);
}
if (cpumask_test_cpu(cpu, &smp_commenced_mask)) {
printk(KERN_ERR "CPU %u didn't die...\n", cpu);
} else {
#if defined(CONFIG_SUN_LDOMS)
unsigned long hv_err;
int limit = 100;
do {
hv_err = sun4v_cpu_stop(cpu);
if (hv_err == HV_EOK) {
set_cpu_present(cpu, false);
break;
}
} while (--limit > 0);
if (limit <= 0) {
printk(KERN_ERR "sun4v_cpu_stop() fails err=%lu\n",
hv_err);
}
#endif
}
}
void __init smp_cpus_done(unsigned int max_cpus)
{
pcr_arch_init();
}
void smp_send_reschedule(int cpu)
{
xcall_deliver((u64) &xcall_receive_signal, 0, 0,
cpumask_of(cpu));
}
void __irq_entry smp_receive_signal_client(int irq, struct pt_regs *regs)
{
clear_softint(1 << irq);
scheduler_ipi();
}
void smp_send_stop(void)
{
}
static void * __init pcpu_alloc_bootmem(unsigned int cpu, size_t size,
size_t align)
{
const unsigned long goal = __pa(MAX_DMA_ADDRESS);
#ifdef CONFIG_NEED_MULTIPLE_NODES
int node = cpu_to_node(cpu);
void *ptr;
if (!node_online(node) || !NODE_DATA(node)) {
ptr = __alloc_bootmem(size, align, goal);
pr_info("cpu %d has no node %d or node-local memory\n",
cpu, node);
pr_debug("per cpu data for cpu%d %lu bytes at %016lx\n",
cpu, size, __pa(ptr));
} else {
ptr = __alloc_bootmem_node(NODE_DATA(node),
size, align, goal);
pr_debug("per cpu data for cpu%d %lu bytes on node%d at "
"%016lx\n", cpu, size, node, __pa(ptr));
}
return ptr;
#else
return __alloc_bootmem(size, align, goal);
#endif
}
static void __init pcpu_free_bootmem(void *ptr, size_t size)
{
free_bootmem(__pa(ptr), size);
}
static int __init pcpu_cpu_distance(unsigned int from, unsigned int to)
{
if (cpu_to_node(from) == cpu_to_node(to))
return LOCAL_DISTANCE;
else
return REMOTE_DISTANCE;
}
static void __init pcpu_populate_pte(unsigned long addr)
{
pgd_t *pgd = pgd_offset_k(addr);
pud_t *pud;
pmd_t *pmd;
pud = pud_offset(pgd, addr);
if (pud_none(*pud)) {
pmd_t *new;
new = __alloc_bootmem(PAGE_SIZE, PAGE_SIZE, PAGE_SIZE);
pud_populate(&init_mm, pud, new);
}
pmd = pmd_offset(pud, addr);
if (!pmd_present(*pmd)) {
pte_t *new;
new = __alloc_bootmem(PAGE_SIZE, PAGE_SIZE, PAGE_SIZE);
pmd_populate_kernel(&init_mm, pmd, new);
}
}
void __init setup_per_cpu_areas(void)
{
unsigned long delta;
unsigned int cpu;
int rc = -EINVAL;
if (pcpu_chosen_fc != PCPU_FC_PAGE) {
rc = pcpu_embed_first_chunk(PERCPU_MODULE_RESERVE,
PERCPU_DYNAMIC_RESERVE, 4 << 20,
pcpu_cpu_distance,
pcpu_alloc_bootmem,
pcpu_free_bootmem);
if (rc)
pr_warning("PERCPU: %s allocator failed (%d), "
"falling back to page size\n",
pcpu_fc_names[pcpu_chosen_fc], rc);
}
if (rc < 0)
rc = pcpu_page_first_chunk(PERCPU_MODULE_RESERVE,
pcpu_alloc_bootmem,
pcpu_free_bootmem,
pcpu_populate_pte);
if (rc < 0)
panic("cannot initialize percpu area (err=%d)", rc);
delta = (unsigned long)pcpu_base_addr - (unsigned long)__per_cpu_start;
for_each_possible_cpu(cpu)
__per_cpu_offset(cpu) = delta + pcpu_unit_offsets[cpu];
__local_per_cpu_offset = __per_cpu_offset(smp_processor_id());
of_fill_in_cpu_data();
if (tlb_type == hypervisor)
mdesc_fill_in_cpu_data(cpu_all_mask);
}
