static void __init allocate_lppacas(int nr_cpus, unsigned long limit)
{
if (nr_cpus <= NR_LPPACAS)
return;
lppaca_size = PAGE_ALIGN(sizeof(struct lppaca) *
(nr_cpus - NR_LPPACAS));
extra_lppacas = __va(memblock_alloc_base(lppaca_size,
PAGE_SIZE, limit));
}
static struct lppaca * __init new_lppaca(int cpu)
{
struct lppaca *lp;
if (cpu < NR_LPPACAS)
return &lppaca[cpu];
lp = extra_lppacas + (cpu - NR_LPPACAS);
*lp = lppaca[0];
return lp;
}
static void __init free_lppacas(void)
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
static void __init allocate_slb_shadows(int nr_cpus, int limit)
{
int size = PAGE_ALIGN(sizeof(struct slb_shadow) * nr_cpus);
if (early_radix_enabled())
return;
slb_shadow = __va(memblock_alloc_base(size, PAGE_SIZE, limit));
memset(slb_shadow, 0, size);
}
static struct slb_shadow * __init init_slb_shadow(int cpu)
{
struct slb_shadow *s;
if (early_radix_enabled())
return NULL;
s = &slb_shadow[cpu];
if (!slb_shadow)
return NULL;
s->persistent = cpu_to_be32(SLB_NUM_BOLTED);
s->buffer_length = cpu_to_be32(sizeof(*s));
return s;
}
static void __init allocate_slb_shadows(int nr_cpus, int limit) { }
void __init initialise_paca(struct paca_struct *new_paca, int cpu)
{
#ifdef CONFIG_PPC_BOOK3S
new_paca->lppaca_ptr = new_lppaca(cpu);
#else
new_paca->kernel_pgd = swapper_pg_dir;
#endif
new_paca->lock_token = 0x8000;
new_paca->paca_index = cpu;
new_paca->kernel_toc = kernel_toc_addr();
new_paca->kernelbase = (unsigned long) _stext;
new_paca->kernel_msr = MSR_KERNEL & ~(MSR_IR | MSR_DR);
new_paca->hw_cpu_id = 0xffff;
new_paca->kexec_state = KEXEC_STATE_NONE;
new_paca->__current = &init_task;
new_paca->data_offset = 0xfeeeeeeeeeeeeeeeULL;
#ifdef CONFIG_PPC_STD_MMU_64
new_paca->slb_shadow_ptr = init_slb_shadow(cpu);
#endif
#ifdef CONFIG_PPC_BOOK3E
new_paca->tcd_ptr = &new_paca->tcd;
#endif
}
void setup_paca(struct paca_struct *new_paca)
{
local_paca = new_paca;
#ifdef CONFIG_PPC_BOOK3E
mtspr(SPRN_SPRG_TLB_EXFRAME, local_paca->extlb);
#else
if (early_cpu_has_feature(CPU_FTR_HVMODE))
mtspr(SPRN_SPRG_HPACA, local_paca);
#endif
mtspr(SPRN_SPRG_PACA, local_paca);
}
void __init allocate_pacas(void)
{
u64 limit;
int cpu;
limit = ppc64_rma_size;
#ifdef CONFIG_PPC_BOOK3S_64
limit = min(0x10000000ULL, limit);
#endif
paca_size = PAGE_ALIGN(sizeof(struct paca_struct) * nr_cpu_ids);
paca = __va(memblock_alloc_base(paca_size, PAGE_SIZE, limit));
memset(paca, 0, paca_size);
printk(KERN_DEBUG "Allocated %u bytes for %u pacas at %p\n",
paca_size, nr_cpu_ids, paca);
allocate_lppacas(nr_cpu_ids, limit);
allocate_slb_shadows(nr_cpu_ids, limit);
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
void copy_mm_to_paca(struct mm_struct *mm)
{
#ifdef CONFIG_PPC_BOOK3S
mm_context_t *context = &mm->context;
get_paca()->mm_ctx_id = context->id;
#ifdef CONFIG_PPC_MM_SLICES
VM_BUG_ON(!mm->context.addr_limit);
get_paca()->addr_limit = mm->context.addr_limit;
get_paca()->mm_ctx_low_slices_psize = context->low_slices_psize;
memcpy(&get_paca()->mm_ctx_high_slices_psize,
&context->high_slices_psize, TASK_SLICE_ARRAY_SZ(mm));
#else
get_paca()->mm_ctx_user_psize = context->user_psize;
get_paca()->mm_ctx_sllp = context->sllp;
#endif
#else
return;
#endif
}
