static void allocate_lppacas(int nr_cpus, unsigned long limit)
{
if (nr_cpus <= NR_LPPACAS)
return;
lppaca_size = PAGE_ALIGN(sizeof(struct lppaca) *
(nr_cpus - NR_LPPACAS));
extra_lppacas = __va(memblock_alloc_base(lppaca_size,
PAGE_SIZE, limit));
}
static struct lppaca *new_lppaca(int cpu)
{
struct lppaca *lp;
if (cpu < NR_LPPACAS)
return &lppaca[cpu];
lp = extra_lppacas + (cpu - NR_LPPACAS);
*lp = lppaca[0];
return lp;
}
static void free_lppacas(void)
{
long new_size = 0, nr;
if (!lppaca_size)
return;
nr = num_possible_cpus() - NR_LPPACAS;
if (nr > 0)
new_size = PAGE_ALIGN(nr * sizeof(struct lppaca));
if (new_size >= lppaca_size)
return;
memblock_free(__pa(extra_lppacas) + new_size, lppaca_size - new_size);
lppaca_size = new_size;
}
static inline void allocate_lppacas(int nr_cpus, unsigned long limit) { }
static inline void free_lppacas(void) { }
void __init initialise_paca(struct paca_struct *new_paca, int cpu)
{
unsigned long kernel_toc = (unsigned long)(&__toc_start) + 0x8000UL;
#ifdef CONFIG_PPC_BOOK3S
new_paca->lppaca_ptr = new_lppaca(cpu);
#else
new_paca->kernel_pgd = swapper_pg_dir;
#endif
new_paca->lock_token = 0x8000;
new_paca->paca_index = cpu;
new_paca->kernel_toc = kernel_toc;
new_paca->kernelbase = (unsigned long) _stext;
new_paca->kernel_msr = MSR_KERNEL;
new_paca->hw_cpu_id = 0xffff;
new_paca->kexec_state = KEXEC_STATE_NONE;
new_paca->__current = &init_task;
#ifdef CONFIG_PPC_STD_MMU_64
new_paca->slb_shadow_ptr = &slb_shadow[cpu];
#endif
}
void setup_paca(struct paca_struct *new_paca)
{
local_paca = new_paca;
#ifdef CONFIG_PPC_BOOK3E
mtspr(SPRN_SPRG_TLB_EXFRAME, local_paca->extlb);
#else
if (cpu_has_feature(CPU_FTR_HVMODE))
mtspr(SPRN_SPRG_HPACA, local_paca);
#endif
mtspr(SPRN_SPRG_PACA, local_paca);
}
void __init allocate_pacas(void)
{
int cpu, limit;
limit = min(0x10000000ULL, ppc64_rma_size);
if (firmware_has_feature(FW_FEATURE_ISERIES))
limit = min(limit, HvPagesToMap * HVPAGESIZE);
paca_size = PAGE_ALIGN(sizeof(struct paca_struct) * nr_cpu_ids);
paca = __va(memblock_alloc_base(paca_size, PAGE_SIZE, limit));
memset(paca, 0, paca_size);
printk(KERN_DEBUG "Allocated %u bytes for %d pacas at %p\n",
paca_size, nr_cpu_ids, paca);
allocate_lppacas(nr_cpu_ids, limit);
for (cpu = 0; cpu < nr_cpu_ids; cpu++)
initialise_paca(&paca[cpu], cpu);
}
void __init free_unused_pacas(void)
{
int new_size;
new_size = PAGE_ALIGN(sizeof(struct paca_struct) * nr_cpu_ids);
if (new_size >= paca_size)
return;
memblock_free(__pa(paca) + new_size, paca_size - new_size);
printk(KERN_DEBUG "Freed %u bytes for unused pacas\n",
paca_size - new_size);
paca_size = new_size;
free_lppacas();
}
