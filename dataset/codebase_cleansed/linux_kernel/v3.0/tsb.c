static inline unsigned long tsb_hash(unsigned long vaddr, unsigned long hash_shift, unsigned long nentries)
{
vaddr >>= hash_shift;
return vaddr & (nentries - 1);
}
static inline int tag_compare(unsigned long tag, unsigned long vaddr)
{
return (tag == (vaddr >> 22));
}
void flush_tsb_kernel_range(unsigned long start, unsigned long end)
{
unsigned long v;
for (v = start; v < end; v += PAGE_SIZE) {
unsigned long hash = tsb_hash(v, PAGE_SHIFT,
KERNEL_TSB_NENTRIES);
struct tsb *ent = &swapper_tsb[hash];
if (tag_compare(ent->tag, v))
ent->tag = (1UL << TSB_TAG_INVALID_BIT);
}
}
static void __flush_tsb_one(struct tlb_batch *tb, unsigned long hash_shift,
unsigned long tsb, unsigned long nentries)
{
unsigned long i;
for (i = 0; i < tb->tlb_nr; i++) {
unsigned long v = tb->vaddrs[i];
unsigned long tag, ent, hash;
v &= ~0x1UL;
hash = tsb_hash(v, hash_shift, nentries);
ent = tsb + (hash * sizeof(struct tsb));
tag = (v >> 22UL);
tsb_flush(ent, tag);
}
}
void flush_tsb_user(struct tlb_batch *tb)
{
struct mm_struct *mm = tb->mm;
unsigned long nentries, base, flags;
spin_lock_irqsave(&mm->context.lock, flags);
base = (unsigned long) mm->context.tsb_block[MM_TSB_BASE].tsb;
nentries = mm->context.tsb_block[MM_TSB_BASE].tsb_nentries;
if (tlb_type == cheetah_plus || tlb_type == hypervisor)
base = __pa(base);
__flush_tsb_one(tb, PAGE_SHIFT, base, nentries);
#ifdef CONFIG_HUGETLB_PAGE
if (mm->context.tsb_block[MM_TSB_HUGE].tsb) {
base = (unsigned long) mm->context.tsb_block[MM_TSB_HUGE].tsb;
nentries = mm->context.tsb_block[MM_TSB_HUGE].tsb_nentries;
if (tlb_type == cheetah_plus || tlb_type == hypervisor)
base = __pa(base);
__flush_tsb_one(tb, HPAGE_SHIFT, base, nentries);
}
#endif
spin_unlock_irqrestore(&mm->context.lock, flags);
}
static void setup_tsb_params(struct mm_struct *mm, unsigned long tsb_idx, unsigned long tsb_bytes)
{
unsigned long tsb_reg, base, tsb_paddr;
unsigned long page_sz, tte;
mm->context.tsb_block[tsb_idx].tsb_nentries =
tsb_bytes / sizeof(struct tsb);
base = TSBMAP_BASE;
tte = pgprot_val(PAGE_KERNEL_LOCKED);
tsb_paddr = __pa(mm->context.tsb_block[tsb_idx].tsb);
BUG_ON(tsb_paddr & (tsb_bytes - 1UL));
switch (tsb_bytes) {
case 8192 << 0:
tsb_reg = 0x0UL;
#ifdef DCACHE_ALIASING_POSSIBLE
base += (tsb_paddr & 8192);
#endif
page_sz = 8192;
break;
case 8192 << 1:
tsb_reg = 0x1UL;
page_sz = 64 * 1024;
break;
case 8192 << 2:
tsb_reg = 0x2UL;
page_sz = 64 * 1024;
break;
case 8192 << 3:
tsb_reg = 0x3UL;
page_sz = 64 * 1024;
break;
case 8192 << 4:
tsb_reg = 0x4UL;
page_sz = 512 * 1024;
break;
case 8192 << 5:
tsb_reg = 0x5UL;
page_sz = 512 * 1024;
break;
case 8192 << 6:
tsb_reg = 0x6UL;
page_sz = 512 * 1024;
break;
case 8192 << 7:
tsb_reg = 0x7UL;
page_sz = 4 * 1024 * 1024;
break;
default:
printk(KERN_ERR "TSB[%s:%d]: Impossible TSB size %lu, killing process.\n",
current->comm, current->pid, tsb_bytes);
do_exit(SIGSEGV);
}
tte |= pte_sz_bits(page_sz);
if (tlb_type == cheetah_plus || tlb_type == hypervisor) {
tsb_reg |= tsb_paddr;
mm->context.tsb_block[tsb_idx].tsb_reg_val = tsb_reg;
mm->context.tsb_block[tsb_idx].tsb_map_vaddr = 0;
mm->context.tsb_block[tsb_idx].tsb_map_pte = 0;
} else {
tsb_reg |= base;
tsb_reg |= (tsb_paddr & (page_sz - 1UL));
tte |= (tsb_paddr & ~(page_sz - 1UL));
mm->context.tsb_block[tsb_idx].tsb_reg_val = tsb_reg;
mm->context.tsb_block[tsb_idx].tsb_map_vaddr = base;
mm->context.tsb_block[tsb_idx].tsb_map_pte = tte;
}
if (tlb_type == hypervisor) {
struct hv_tsb_descr *hp = &mm->context.tsb_descr[tsb_idx];
switch (tsb_idx) {
case MM_TSB_BASE:
hp->pgsz_idx = HV_PGSZ_IDX_BASE;
break;
#ifdef CONFIG_HUGETLB_PAGE
case MM_TSB_HUGE:
hp->pgsz_idx = HV_PGSZ_IDX_HUGE;
break;
#endif
default:
BUG();
}
hp->assoc = 1;
hp->num_ttes = tsb_bytes / 16;
hp->ctx_idx = 0;
switch (tsb_idx) {
case MM_TSB_BASE:
hp->pgsz_mask = HV_PGSZ_MASK_BASE;
break;
#ifdef CONFIG_HUGETLB_PAGE
case MM_TSB_HUGE:
hp->pgsz_mask = HV_PGSZ_MASK_HUGE;
break;
#endif
default:
BUG();
}
hp->tsb_base = tsb_paddr;
hp->resv = 0;
}
}
void __init pgtable_cache_init(void)
{
unsigned long i;
for (i = 0; i < 8; i++) {
unsigned long size = 8192 << i;
const char *name = tsb_cache_names[i];
tsb_caches[i] = kmem_cache_create(name,
size, size,
0, NULL);
if (!tsb_caches[i]) {
prom_printf("Could not create %s cache\n", name);
prom_halt();
}
}
}
static unsigned long tsb_size_to_rss_limit(unsigned long new_size)
{
unsigned long num_ents = (new_size / sizeof(struct tsb));
if (sysctl_tsb_ratio < 0)
return num_ents - (num_ents >> -sysctl_tsb_ratio);
else
return num_ents + (num_ents >> sysctl_tsb_ratio);
}
void tsb_grow(struct mm_struct *mm, unsigned long tsb_index, unsigned long rss)
{
unsigned long max_tsb_size = 1 * 1024 * 1024;
unsigned long new_size, old_size, flags;
struct tsb *old_tsb, *new_tsb;
unsigned long new_cache_index, old_cache_index;
unsigned long new_rss_limit;
gfp_t gfp_flags;
if (max_tsb_size > (PAGE_SIZE << MAX_ORDER))
max_tsb_size = (PAGE_SIZE << MAX_ORDER);
new_cache_index = 0;
for (new_size = 8192; new_size < max_tsb_size; new_size <<= 1UL) {
new_rss_limit = tsb_size_to_rss_limit(new_size);
if (new_rss_limit > rss)
break;
new_cache_index++;
}
if (new_size == max_tsb_size)
new_rss_limit = ~0UL;
retry_tsb_alloc:
gfp_flags = GFP_KERNEL;
if (new_size > (PAGE_SIZE * 2))
gfp_flags = __GFP_NOWARN | __GFP_NORETRY;
new_tsb = kmem_cache_alloc_node(tsb_caches[new_cache_index],
gfp_flags, numa_node_id());
if (unlikely(!new_tsb)) {
if (mm->context.tsb_block[tsb_index].tsb == NULL &&
new_cache_index > 0) {
new_cache_index = 0;
new_size = 8192;
new_rss_limit = ~0UL;
goto retry_tsb_alloc;
}
if (mm->context.tsb_block[tsb_index].tsb != NULL)
mm->context.tsb_block[tsb_index].tsb_rss_limit = ~0UL;
return;
}
tsb_init(new_tsb, new_size);
spin_lock_irqsave(&mm->context.lock, flags);
old_tsb = mm->context.tsb_block[tsb_index].tsb;
old_cache_index =
(mm->context.tsb_block[tsb_index].tsb_reg_val & 0x7UL);
old_size = (mm->context.tsb_block[tsb_index].tsb_nentries *
sizeof(struct tsb));
if (unlikely(old_tsb &&
(rss < mm->context.tsb_block[tsb_index].tsb_rss_limit))) {
spin_unlock_irqrestore(&mm->context.lock, flags);
kmem_cache_free(tsb_caches[new_cache_index], new_tsb);
return;
}
mm->context.tsb_block[tsb_index].tsb_rss_limit = new_rss_limit;
if (old_tsb) {
extern void copy_tsb(unsigned long old_tsb_base,
unsigned long old_tsb_size,
unsigned long new_tsb_base,
unsigned long new_tsb_size);
unsigned long old_tsb_base = (unsigned long) old_tsb;
unsigned long new_tsb_base = (unsigned long) new_tsb;
if (tlb_type == cheetah_plus || tlb_type == hypervisor) {
old_tsb_base = __pa(old_tsb_base);
new_tsb_base = __pa(new_tsb_base);
}
copy_tsb(old_tsb_base, old_size, new_tsb_base, new_size);
}
mm->context.tsb_block[tsb_index].tsb = new_tsb;
setup_tsb_params(mm, tsb_index, new_size);
spin_unlock_irqrestore(&mm->context.lock, flags);
if (old_tsb) {
tsb_context_switch(mm);
preempt_disable();
smp_tsb_sync(mm);
preempt_enable();
kmem_cache_free(tsb_caches[old_cache_index], old_tsb);
}
}
int init_new_context(struct task_struct *tsk, struct mm_struct *mm)
{
#ifdef CONFIG_HUGETLB_PAGE
unsigned long huge_pte_count;
#endif
unsigned int i;
spin_lock_init(&mm->context.lock);
mm->context.sparc64_ctx_val = 0UL;
#ifdef CONFIG_HUGETLB_PAGE
huge_pte_count = mm->context.huge_pte_count;
mm->context.huge_pte_count = 0;
#endif
for (i = 0; i < MM_NUM_TSBS; i++)
mm->context.tsb_block[i].tsb = NULL;
tsb_grow(mm, MM_TSB_BASE, get_mm_rss(mm));
#ifdef CONFIG_HUGETLB_PAGE
if (unlikely(huge_pte_count))
tsb_grow(mm, MM_TSB_HUGE, huge_pte_count);
#endif
if (unlikely(!mm->context.tsb_block[MM_TSB_BASE].tsb))
return -ENOMEM;
return 0;
}
static void tsb_destroy_one(struct tsb_config *tp)
{
unsigned long cache_index;
if (!tp->tsb)
return;
cache_index = tp->tsb_reg_val & 0x7UL;
kmem_cache_free(tsb_caches[cache_index], tp->tsb);
tp->tsb = NULL;
tp->tsb_reg_val = 0UL;
}
void destroy_context(struct mm_struct *mm)
{
unsigned long flags, i;
for (i = 0; i < MM_NUM_TSBS; i++)
tsb_destroy_one(&mm->context.tsb_block[i]);
spin_lock_irqsave(&ctx_alloc_lock, flags);
if (CTX_VALID(mm->context)) {
unsigned long nr = CTX_NRBITS(mm->context);
mmu_context_bmap[nr>>6] &= ~(1UL << (nr & 63));
}
spin_unlock_irqrestore(&ctx_alloc_lock, flags);
}
