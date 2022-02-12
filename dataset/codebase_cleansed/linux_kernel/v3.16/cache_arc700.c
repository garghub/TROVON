char *arc_cache_mumbojumbo(int c, char *buf, int len)
{
int n = 0;
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
PR_CACHE(&cpuinfo_arc700[c].icache, IS_ENABLED(CONFIG_ARC_HAS_ICACHE),
"I-Cache");
PR_CACHE(&cpuinfo_arc700[c].dcache, IS_ENABLED(CONFIG_ARC_HAS_DCACHE),
"D-Cache");
return buf;
}
void read_decode_cache_bcr(void)
{
struct cpuinfo_arc_cache *p_ic, *p_dc;
unsigned int cpu = smp_processor_id();
struct bcr_cache {
#ifdef CONFIG_CPU_BIG_ENDIAN
unsigned int pad:12, line_len:4, sz:4, config:4, ver:8;
#else
unsigned int ver:8, config:4, sz:4, line_len:4, pad:12;
#endif
} ibcr, dbcr;
p_ic = &cpuinfo_arc700[cpu].icache;
READ_BCR(ARC_REG_IC_BCR, ibcr);
BUG_ON(ibcr.config != 3);
p_ic->assoc = 2;
p_ic->line_len = 8 << ibcr.line_len;
p_ic->sz = 0x200 << ibcr.sz;
p_ic->ver = ibcr.ver;
p_dc = &cpuinfo_arc700[cpu].dcache;
READ_BCR(ARC_REG_DC_BCR, dbcr);
BUG_ON(dbcr.config != 2);
p_dc->assoc = 4;
p_dc->line_len = 16 << dbcr.line_len;
p_dc->sz = 0x200 << dbcr.sz;
p_dc->ver = dbcr.ver;
}
void arc_cache_init(void)
{
unsigned int __maybe_unused cpu = smp_processor_id();
struct cpuinfo_arc_cache __maybe_unused *ic, __maybe_unused *dc;
char str[256];
printk(arc_cache_mumbojumbo(0, str, sizeof(str)));
#ifdef CONFIG_ARC_HAS_ICACHE
ic = &cpuinfo_arc700[cpu].icache;
if (ic->ver) {
if (ic->line_len != L1_CACHE_BYTES)
panic("ICache line [%d] != kernel Config [%d]",
ic->line_len, L1_CACHE_BYTES);
if (ic->ver != CONFIG_ARC_MMU_VER)
panic("Cache ver [%d] doesn't match MMU ver [%d]\n",
ic->ver, CONFIG_ARC_MMU_VER);
}
#endif
#ifdef CONFIG_ARC_HAS_DCACHE
dc = &cpuinfo_arc700[cpu].dcache;
if (dc->ver) {
unsigned int dcache_does_alias;
if (dc->line_len != L1_CACHE_BYTES)
panic("DCache line [%d] != kernel Config [%d]",
dc->line_len, L1_CACHE_BYTES);
dcache_does_alias = (dc->sz / dc->assoc) > PAGE_SIZE;
if (dcache_does_alias && !cache_is_vipt_aliasing())
panic("Enable CONFIG_ARC_CACHE_VIPT_ALIASING\n");
else if (!dcache_does_alias && cache_is_vipt_aliasing())
panic("Don't need CONFIG_ARC_CACHE_VIPT_ALIASING\n");
}
#endif
}
static inline void __cache_line_loop(unsigned long paddr, unsigned long vaddr,
unsigned long sz, const int cacheop)
{
unsigned int aux_cmd, aux_tag;
int num_lines;
const int full_page_op = __builtin_constant_p(sz) && sz == PAGE_SIZE;
if (cacheop == OP_INV_IC) {
aux_cmd = ARC_REG_IC_IVIL;
#if (CONFIG_ARC_MMU_VER > 2)
aux_tag = ARC_REG_IC_PTAG;
#endif
}
else {
aux_cmd = cacheop & OP_INV ? ARC_REG_DC_IVDL : ARC_REG_DC_FLDL;
#if (CONFIG_ARC_MMU_VER > 2)
aux_tag = ARC_REG_DC_PTAG;
#endif
}
if (!full_page_op) {
sz += paddr & ~CACHE_LINE_MASK;
paddr &= CACHE_LINE_MASK;
vaddr &= CACHE_LINE_MASK;
}
num_lines = DIV_ROUND_UP(sz, L1_CACHE_BYTES);
#if (CONFIG_ARC_MMU_VER <= 2)
paddr |= (vaddr >> PAGE_SHIFT) & 0x1F;
#else
if (full_page_op)
write_aux_reg(aux_tag, paddr);
#endif
while (num_lines-- > 0) {
#if (CONFIG_ARC_MMU_VER > 2)
if (!full_page_op) {
write_aux_reg(aux_tag, paddr);
paddr += L1_CACHE_BYTES;
}
write_aux_reg(aux_cmd, vaddr);
vaddr += L1_CACHE_BYTES;
#else
write_aux_reg(aux_cmd, paddr);
paddr += L1_CACHE_BYTES;
#endif
}
}
static inline void wait_for_flush(void)
{
while (read_aux_reg(ARC_REG_DC_CTRL) & DC_CTRL_FLUSH_STATUS)
;
}
static inline void __dc_entire_op(const int cacheop)
{
unsigned int tmp = tmp;
int aux;
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
}
static inline void __dc_line_op(unsigned long paddr, unsigned long vaddr,
unsigned long sz, const int cacheop)
{
unsigned long flags, tmp = tmp;
local_irq_save(flags);
if (cacheop == OP_FLUSH_N_INV) {
tmp = read_aux_reg(ARC_REG_DC_CTRL);
write_aux_reg(ARC_REG_DC_CTRL, tmp | DC_CTRL_INV_MODE_FLUSH);
}
__cache_line_loop(paddr, vaddr, sz, cacheop);
if (cacheop & OP_FLUSH)
wait_for_flush();
if (cacheop == OP_FLUSH_N_INV)
write_aux_reg(ARC_REG_DC_CTRL, tmp & ~DC_CTRL_INV_MODE_FLUSH);
local_irq_restore(flags);
}
static void __ic_line_inv_vaddr_local(unsigned long paddr, unsigned long vaddr,
unsigned long sz)
{
unsigned long flags;
local_irq_save(flags);
__cache_line_loop(paddr, vaddr, sz, OP_INV_IC);
local_irq_restore(flags);
}
static inline void __ic_entire_inv(void)
{
write_aux_reg(ARC_REG_IC_IVIC, 1);
read_aux_reg(ARC_REG_IC_CTRL);
}
static void __ic_line_inv_vaddr_helper(void *info)
{
struct ic_line_inv_vaddr_ipi *ic_inv = (struct ic_line_inv_vaddr_ipi*) info;
__ic_line_inv_vaddr_local(ic_inv->paddr, ic_inv->vaddr, ic_inv->sz);
}
static void __ic_line_inv_vaddr(unsigned long paddr, unsigned long vaddr,
unsigned long sz)
{
struct ic_line_inv_vaddr_ipi ic_inv = { paddr, vaddr , sz};
on_each_cpu(__ic_line_inv_vaddr_helper, &ic_inv, 1);
}
void flush_dcache_page(struct page *page)
{
struct address_space *mapping;
if (!cache_is_vipt_aliasing()) {
clear_bit(PG_dc_clean, &page->flags);
return;
}
mapping = page_mapping(page);
if (!mapping)
return;
if (!mapping_mapped(mapping)) {
clear_bit(PG_dc_clean, &page->flags);
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
__dc_line_op(paddr, vaddr, len, OP_FLUSH_N_INV);
__ic_line_inv_vaddr(paddr, vaddr, len);
}
void __inv_icache_page(unsigned long paddr, unsigned long vaddr)
{
__ic_line_inv_vaddr(paddr, vaddr, PAGE_SIZE);
}
void ___flush_dcache_page(unsigned long paddr, unsigned long vaddr)
{
__dc_line_op(paddr, vaddr & PAGE_MASK, PAGE_SIZE, OP_FLUSH_N_INV);
}
noinline void flush_cache_all(void)
{
unsigned long flags;
local_irq_save(flags);
__ic_entire_inv();
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
u_vaddr &= PAGE_MASK;
___flush_dcache_page(paddr, u_vaddr);
if (vma->vm_flags & VM_EXEC)
__inv_icache_page(paddr, u_vaddr);
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
clear_bit(PG_dc_clean, &to->flags);
if (clean_src_k_mappings) {
__flush_dcache_page(kfrom, kfrom);
set_bit(PG_dc_clean, &from->flags);
} else {
clear_bit(PG_dc_clean, &from->flags);
}
}
void clear_user_page(void *to, unsigned long u_vaddr, struct page *page)
{
clear_page(to);
clear_bit(PG_dc_clean, &page->flags);
}
