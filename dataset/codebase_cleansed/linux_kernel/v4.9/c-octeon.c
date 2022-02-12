static void octeon_flush_data_cache_page(unsigned long addr)
{
}
static inline void octeon_local_flush_icache(void)
{
asm volatile ("synci 0($0)");
}
static void local_octeon_flush_icache_range(unsigned long start,
unsigned long end)
{
octeon_local_flush_icache();
}
static void octeon_flush_icache_all_cores(struct vm_area_struct *vma)
{
extern void octeon_send_ipi_single(int cpu, unsigned int action);
#ifdef CONFIG_SMP
int cpu;
cpumask_t mask;
#endif
mb();
octeon_local_flush_icache();
#ifdef CONFIG_SMP
preempt_disable();
cpu = smp_processor_id();
if (vma)
mask = *mm_cpumask(vma->vm_mm);
else
mask = *cpu_online_mask;
cpumask_clear_cpu(cpu, &mask);
for_each_cpu(cpu, &mask)
octeon_send_ipi_single(cpu, SMP_ICACHE_FLUSH);
preempt_enable();
#endif
}
static void octeon_flush_icache_all(void)
{
octeon_flush_icache_all_cores(NULL);
}
static void octeon_flush_cache_mm(struct mm_struct *mm)
{
}
static void octeon_flush_icache_range(unsigned long start, unsigned long end)
{
octeon_flush_icache_all_cores(NULL);
}
static void octeon_flush_cache_sigtramp(unsigned long addr)
{
struct vm_area_struct *vma;
down_read(&current->mm->mmap_sem);
vma = find_vma(current->mm, addr);
octeon_flush_icache_all_cores(vma);
up_read(&current->mm->mmap_sem);
}
static void octeon_flush_cache_range(struct vm_area_struct *vma,
unsigned long start, unsigned long end)
{
if (vma->vm_flags & VM_EXEC)
octeon_flush_icache_all_cores(vma);
}
static void octeon_flush_cache_page(struct vm_area_struct *vma,
unsigned long page, unsigned long pfn)
{
if (vma->vm_flags & VM_EXEC)
octeon_flush_icache_all_cores(vma);
}
static void octeon_flush_kernel_vmap_range(unsigned long vaddr, int size)
{
BUG();
}
static void probe_octeon(void)
{
unsigned long icache_size;
unsigned long dcache_size;
unsigned int config1;
struct cpuinfo_mips *c = &current_cpu_data;
int cputype = current_cpu_type();
config1 = read_c0_config1();
switch (cputype) {
case CPU_CAVIUM_OCTEON:
case CPU_CAVIUM_OCTEON_PLUS:
c->icache.linesz = 2 << ((config1 >> 19) & 7);
c->icache.sets = 64 << ((config1 >> 22) & 7);
c->icache.ways = 1 + ((config1 >> 16) & 7);
c->icache.flags |= MIPS_CACHE_VTAG;
icache_size =
c->icache.sets * c->icache.ways * c->icache.linesz;
c->icache.waybit = ffs(icache_size / c->icache.ways) - 1;
c->dcache.linesz = 128;
if (cputype == CPU_CAVIUM_OCTEON_PLUS)
c->dcache.sets = 2;
else
c->dcache.sets = 1;
c->dcache.ways = 64;
dcache_size =
c->dcache.sets * c->dcache.ways * c->dcache.linesz;
c->dcache.waybit = ffs(dcache_size / c->dcache.ways) - 1;
c->options |= MIPS_CPU_PREFETCH;
break;
case CPU_CAVIUM_OCTEON2:
c->icache.linesz = 2 << ((config1 >> 19) & 7);
c->icache.sets = 8;
c->icache.ways = 37;
c->icache.flags |= MIPS_CACHE_VTAG;
icache_size = c->icache.sets * c->icache.ways * c->icache.linesz;
c->dcache.linesz = 128;
c->dcache.ways = 32;
c->dcache.sets = 8;
dcache_size = c->dcache.sets * c->dcache.ways * c->dcache.linesz;
c->options |= MIPS_CPU_PREFETCH;
break;
case CPU_CAVIUM_OCTEON3:
c->icache.linesz = 128;
c->icache.sets = 16;
c->icache.ways = 39;
c->icache.flags |= MIPS_CACHE_VTAG;
icache_size = c->icache.sets * c->icache.ways * c->icache.linesz;
c->dcache.linesz = 128;
c->dcache.ways = 32;
c->dcache.sets = 8;
dcache_size = c->dcache.sets * c->dcache.ways * c->dcache.linesz;
c->options |= MIPS_CPU_PREFETCH;
break;
default:
panic("Unsupported Cavium Networks CPU type");
break;
}
c->icache.waysize = icache_size / c->icache.ways;
c->dcache.waysize = dcache_size / c->dcache.ways;
c->icache.sets = icache_size / (c->icache.linesz * c->icache.ways);
c->dcache.sets = dcache_size / (c->dcache.linesz * c->dcache.ways);
if (smp_processor_id() == 0) {
pr_notice("Primary instruction cache %ldkB, %s, %d way, "
"%d sets, linesize %d bytes.\n",
icache_size >> 10,
cpu_has_vtag_icache ?
"virtually tagged" : "physically tagged",
c->icache.ways, c->icache.sets, c->icache.linesz);
pr_notice("Primary data cache %ldkB, %d-way, %d sets, "
"linesize %d bytes.\n",
dcache_size >> 10, c->dcache.ways,
c->dcache.sets, c->dcache.linesz);
}
}
static void octeon_cache_error_setup(void)
{
extern char except_vec2_octeon;
set_handler(0x100, &except_vec2_octeon, 0x80);
}
void octeon_cache_init(void)
{
probe_octeon();
shm_align_mask = PAGE_SIZE - 1;
flush_cache_all = octeon_flush_icache_all;
__flush_cache_all = octeon_flush_icache_all;
flush_cache_mm = octeon_flush_cache_mm;
flush_cache_page = octeon_flush_cache_page;
flush_cache_range = octeon_flush_cache_range;
flush_cache_sigtramp = octeon_flush_cache_sigtramp;
flush_icache_all = octeon_flush_icache_all;
flush_data_cache_page = octeon_flush_data_cache_page;
flush_icache_range = octeon_flush_icache_range;
local_flush_icache_range = local_octeon_flush_icache_range;
__flush_icache_user_range = octeon_flush_icache_range;
__local_flush_icache_user_range = local_octeon_flush_icache_range;
__flush_kernel_vmap_range = octeon_flush_kernel_vmap_range;
build_clear_page();
build_copy_page();
board_cache_error_setup = octeon_cache_error_setup;
}
int register_co_cache_error_notifier(struct notifier_block *nb)
{
return raw_notifier_chain_register(&co_cache_error_chain, nb);
}
int unregister_co_cache_error_notifier(struct notifier_block *nb)
{
return raw_notifier_chain_unregister(&co_cache_error_chain, nb);
}
static void co_cache_error_call_notifiers(unsigned long val)
{
int rv = raw_notifier_call_chain(&co_cache_error_chain, val, NULL);
if ((rv & ~NOTIFY_STOP_MASK) != NOTIFY_OK) {
u64 dcache_err;
unsigned long coreid = cvmx_get_core_num();
u64 icache_err = read_octeon_c0_icacheerr();
if (val) {
dcache_err = cache_err_dcache[coreid];
cache_err_dcache[coreid] = 0;
} else {
dcache_err = read_octeon_c0_dcacheerr();
}
pr_err("Core%lu: Cache error exception:\n", coreid);
pr_err("cp0_errorepc == %lx\n", read_c0_errorepc());
if (icache_err & 1) {
pr_err("CacheErr (Icache) == %llx\n",
(unsigned long long)icache_err);
write_octeon_c0_icacheerr(0);
}
if (dcache_err & 1) {
pr_err("CacheErr (Dcache) == %llx\n",
(unsigned long long)dcache_err);
}
}
}
asmlinkage void cache_parity_error_octeon_recoverable(void)
{
co_cache_error_call_notifiers(0);
}
asmlinkage void cache_parity_error_octeon_non_recoverable(void)
{
co_cache_error_call_notifiers(1);
panic("Can't handle cache error: nested exception");
}
