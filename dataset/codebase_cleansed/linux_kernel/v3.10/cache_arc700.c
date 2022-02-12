char *arc_cache_mumbojumbo(int cpu_id, char *buf, int len)
{
int n = 0;
unsigned int c = smp_processor_id();
#define PR_CACHE(p, enb, str) \
{ \
if (!(p)->ver) \
n += scnprintf(buf + n, len - n, str"\t\t: N/A\n"); \
else \
n += scnprintf(buf + n, len - n, \
str"\t\t: (%uK) VIPT, %dway set-asc, %ub Line %s\n", \
TO_KB((p)->sz), (p)->assoc, (p)->line_len, \
enb ? "" : "DISABLED (kernel-build)"); \
}
PR_CACHE(&cpuinfo_arc700[c].icache, __CONFIG_ARC_HAS_ICACHE, "I-Cache");
PR_CACHE(&cpuinfo_arc700[c].dcache, __CONFIG_ARC_HAS_DCACHE, "D-Cache");
return buf;
}
void __cpuinit read_decode_cache_bcr(void)
{
struct bcr_cache ibcr, dbcr;
struct cpuinfo_arc_cache *p_ic, *p_dc;
unsigned int cpu = smp_processor_id();
p_ic = &cpuinfo_arc700[cpu].icache;
READ_BCR(ARC_REG_IC_BCR, ibcr);
if (ibcr.config == 0x3)
p_ic->assoc = 2;
p_ic->line_len = 8 << ibcr.line_len;
p_ic->sz = 0x200 << ibcr.sz;
p_ic->ver = ibcr.ver;
p_dc = &cpuinfo_arc700[cpu].dcache;
READ_BCR(ARC_REG_DC_BCR, dbcr);
if (dbcr.config == 0x2)
p_dc->assoc = 4;
p_dc->line_len = 16 << dbcr.line_len;
p_dc->sz = 0x200 << dbcr.sz;
p_dc->ver = dbcr.ver;
}
void __cpuinit arc_cache_init(void)
{
unsigned int temp;
unsigned int cpu = smp_processor_id();
struct cpuinfo_arc_cache *ic = &cpuinfo_arc700[cpu].icache;
struct cpuinfo_arc_cache *dc = &cpuinfo_arc700[cpu].dcache;
int way_pg_ratio = way_pg_ratio;
int dcache_does_alias;
char str[256];
printk(arc_cache_mumbojumbo(0, str, sizeof(str)));
if (!ic->ver)
goto chk_dc;
#ifdef CONFIG_ARC_HAS_ICACHE
if ((ic->assoc != ARC_ICACHE_WAYS) ||
(ic->line_len != ARC_ICACHE_LINE_LEN)) {
panic("Cache H/W doesn't match kernel Config");
}
#if (CONFIG_ARC_MMU_VER > 2)
if (ic->ver != 3) {
if (running_on_hw)
panic("Cache ver doesn't match MMU ver\n");
pr_err("Use -prop=icache_version=3,-prop=dcache_version=3\n");
}
#endif
#endif
temp = read_aux_reg(ARC_REG_IC_CTRL);
#ifdef CONFIG_ARC_HAS_ICACHE
temp &= ~IC_CTRL_CACHE_DISABLE;
#else
temp |= IC_CTRL_CACHE_DISABLE;
#endif
write_aux_reg(ARC_REG_IC_CTRL, temp);
chk_dc:
if (!dc->ver)
return;
#ifdef CONFIG_ARC_HAS_DCACHE
if ((dc->assoc != ARC_DCACHE_WAYS) ||
(dc->line_len != ARC_DCACHE_LINE_LEN)) {
panic("Cache H/W doesn't match kernel Config");
}
dcache_does_alias = (dc->sz / ARC_DCACHE_WAYS) > PAGE_SIZE;
if (dcache_does_alias && !cache_is_vipt_aliasing())
panic("Enable CONFIG_ARC_CACHE_VIPT_ALIASING\n");
else if (!dcache_does_alias && cache_is_vipt_aliasing())
panic("Don't need CONFIG_ARC_CACHE_VIPT_ALIASING\n");
#endif
temp = read_aux_reg(ARC_REG_DC_CTRL);
temp &= ~DC_CTRL_INV_MODE_FLUSH;
#ifdef CONFIG_ARC_HAS_DCACHE
write_aux_reg(ARC_REG_DC_CTRL, temp & ~IC_CTRL_CACHE_DISABLE);
#else
write_aux_reg(ARC_REG_DC_FLSH, 0x1);
write_aux_reg(ARC_REG_DC_CTRL, temp | IC_CTRL_CACHE_DISABLE);
#endif
return;
}
static inline void wait_for_flush(void)
{
while (read_aux_reg(ARC_REG_DC_CTRL) & DC_CTRL_FLUSH_STATUS)
;
}
static inline void __dc_entire_op(const int cacheop)
{
unsigned long flags, tmp = tmp;
int aux;
local_irq_save(flags);
if (cacheop == OP_FLUSH_N_INV) {
tmp = read_aux_reg(ARC_REG_DC_CTRL);
write_aux_reg(ARC_REG_DC_CTRL, tmp | DC_CTRL_INV_MODE_FLUSH);
}
if (cacheop & OP_INV)
aux = ARC_REG_DC_IVDC;
else
aux = ARC_REG_DC_FLSH;
write_aux_reg(aux, 0x1);
if (cacheop & OP_FLUSH)
wait_for_flush();
if (cacheop == OP_FLUSH_N_INV)
write_aux_reg(ARC_REG_DC_CTRL, tmp & ~DC_CTRL_INV_MODE_FLUSH);
local_irq_restore(flags);
}
static inline void __dc_line_loop(unsigned long paddr, unsigned long vaddr,
unsigned long sz, const int aux_reg)
{
int num_lines;
if (!(__builtin_constant_p(sz) && sz == PAGE_SIZE)) {
sz += paddr & ~DCACHE_LINE_MASK;
paddr &= DCACHE_LINE_MASK;
vaddr &= DCACHE_LINE_MASK;
}
num_lines = DIV_ROUND_UP(sz, ARC_DCACHE_LINE_LEN);
#if (CONFIG_ARC_MMU_VER <= 2)
paddr |= (vaddr >> PAGE_SHIFT) & 0x1F;
#endif
while (num_lines-- > 0) {
#if (CONFIG_ARC_MMU_VER > 2)
write_aux_reg(ARC_REG_DC_PTAG, paddr);
write_aux_reg(aux_reg, vaddr);
vaddr += ARC_DCACHE_LINE_LEN;
#else
write_aux_reg(aux_reg, paddr);
#endif
paddr += ARC_DCACHE_LINE_LEN;
}
}
static inline void __dc_line_op(unsigned long paddr, unsigned long vaddr,
unsigned long sz, const int cacheop)
{
unsigned long flags, tmp = tmp;
int aux;
local_irq_save(flags);
if (cacheop == OP_FLUSH_N_INV) {
tmp = read_aux_reg(ARC_REG_DC_CTRL);
write_aux_reg(ARC_REG_DC_CTRL, tmp | DC_CTRL_INV_MODE_FLUSH);
}
if (cacheop & OP_INV)
aux = ARC_REG_DC_IVDL;
else
aux = ARC_REG_DC_FLDL;
__dc_line_loop(paddr, vaddr, sz, aux);
if (cacheop & OP_FLUSH)
wait_for_flush();
if (cacheop == OP_FLUSH_N_INV)
write_aux_reg(ARC_REG_DC_CTRL, tmp & ~DC_CTRL_INV_MODE_FLUSH);
local_irq_restore(flags);
}
static void __ic_line_inv_vaddr(unsigned long paddr, unsigned long vaddr,
unsigned long sz)
{
unsigned long flags;
int num_lines;
if (!(__builtin_constant_p(sz) && sz == PAGE_SIZE)) {
sz += paddr & ~ICACHE_LINE_MASK;
paddr &= ICACHE_LINE_MASK;
vaddr &= ICACHE_LINE_MASK;
}
num_lines = DIV_ROUND_UP(sz, ARC_ICACHE_LINE_LEN);
#if (CONFIG_ARC_MMU_VER <= 2)
paddr |= (vaddr >> PAGE_SHIFT) & 0x1F;
#endif
local_irq_save(flags);
while (num_lines-- > 0) {
#if (CONFIG_ARC_MMU_VER > 2)
write_aux_reg(ARC_REG_IC_PTAG, paddr);
write_aux_reg(ARC_REG_IC_IVIL, vaddr);
vaddr += ARC_ICACHE_LINE_LEN;
#else
write_aux_reg(ARC_REG_IC_IVIL, paddr);
#endif
paddr += ARC_ICACHE_LINE_LEN;
}
local_irq_restore(flags);
}
void flush_dcache_page(struct page *page)
{
struct address_space *mapping;
if (!cache_is_vipt_aliasing()) {
set_bit(PG_arch_1, &page->flags);
return;
}
mapping = page_mapping(page);
if (!mapping)
return;
if (!mapping_mapped(mapping)) {
set_bit(PG_arch_1, &page->flags);
} else if (page_mapped(page)) {
void *paddr = page_address(page);
unsigned long vaddr = page->index << PAGE_CACHE_SHIFT;
if (addr_not_cache_congruent(paddr, vaddr))
__flush_dcache_page(paddr, vaddr);
}
}
void dma_cache_wback_inv(unsigned long start, unsigned long sz)
{
__dc_line_op_k(start, sz, OP_FLUSH_N_INV);
}
void dma_cache_inv(unsigned long start, unsigned long sz)
{
__dc_line_op_k(start, sz, OP_INV);
}
void dma_cache_wback(unsigned long start, unsigned long sz)
{
__dc_line_op_k(start, sz, OP_FLUSH);
}
void flush_icache_range(unsigned long kstart, unsigned long kend)
{
unsigned int tot_sz, off, sz;
unsigned long phy, pfn;
if (kstart < TASK_SIZE) {
BUG_ON("Flush icache range for user virtual addr space");
return;
}
tot_sz = kend - kstart;
if (tot_sz > PAGE_SIZE) {
flush_cache_all();
return;
}
if (likely(kstart > PAGE_OFFSET)) {
__sync_icache_dcache(kstart, kstart, kend - kstart);
return;
}
while (tot_sz > 0) {
off = kstart % PAGE_SIZE;
pfn = vmalloc_to_pfn((void *)kstart);
phy = (pfn << PAGE_SHIFT) + off;
sz = min_t(unsigned int, tot_sz, PAGE_SIZE - off);
__sync_icache_dcache(phy, kstart, sz);
kstart += sz;
tot_sz -= sz;
}
}
void __sync_icache_dcache(unsigned long paddr, unsigned long vaddr, int len)
{
unsigned long flags;
local_irq_save(flags);
__ic_line_inv_vaddr(paddr, vaddr, len);
__dc_line_op(paddr, vaddr, len, OP_FLUSH_N_INV);
local_irq_restore(flags);
}
void __inv_icache_page(unsigned long paddr, unsigned long vaddr)
{
__ic_line_inv_vaddr(paddr, vaddr, PAGE_SIZE);
}
void ___flush_dcache_page(unsigned long paddr, unsigned long vaddr)
{
__dc_line_op(paddr, vaddr & PAGE_MASK, PAGE_SIZE, OP_FLUSH_N_INV);
}
void flush_icache_all(void)
{
unsigned long flags;
local_irq_save(flags);
write_aux_reg(ARC_REG_IC_IVIC, 1);
read_aux_reg(ARC_REG_IC_CTRL);
local_irq_restore(flags);
}
noinline void flush_cache_all(void)
{
unsigned long flags;
local_irq_save(flags);
flush_icache_all();
__dc_entire_op(OP_FLUSH_N_INV);
local_irq_restore(flags);
}
void flush_cache_mm(struct mm_struct *mm)
{
flush_cache_all();
}
void flush_cache_page(struct vm_area_struct *vma, unsigned long u_vaddr,
unsigned long pfn)
{
unsigned int paddr = pfn << PAGE_SHIFT;
__sync_icache_dcache(paddr, u_vaddr, PAGE_SIZE);
}
void flush_cache_range(struct vm_area_struct *vma, unsigned long start,
unsigned long end)
{
flush_cache_all();
}
void flush_anon_page(struct vm_area_struct *vma, struct page *page,
unsigned long u_vaddr)
{
__flush_dcache_page(page_address(page), u_vaddr);
__flush_dcache_page(page_address(page), page_address(page));
}
void copy_user_highpage(struct page *to, struct page *from,
unsigned long u_vaddr, struct vm_area_struct *vma)
{
void *kfrom = page_address(from);
void *kto = page_address(to);
int clean_src_k_mappings = 0;
if (page_mapped(from) && addr_not_cache_congruent(kfrom, u_vaddr)) {
__flush_dcache_page(kfrom, u_vaddr);
clean_src_k_mappings = 1;
}
copy_page(kto, kfrom);
set_bit(PG_arch_1, &to->flags);
if (clean_src_k_mappings) {
__flush_dcache_page(kfrom, kfrom);
} else {
set_bit(PG_arch_1, &from->flags);
}
}
void clear_user_page(void *to, unsigned long u_vaddr, struct page *page)
{
clear_page(to);
set_bit(PG_arch_1, &page->flags);
}
