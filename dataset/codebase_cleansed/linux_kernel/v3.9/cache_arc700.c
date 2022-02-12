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
void __init read_decode_cache_bcr(void)
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
void __init arc_cache_init(void)
{
unsigned int temp;
unsigned int cpu = smp_processor_id();
struct cpuinfo_arc_cache *ic = &cpuinfo_arc700[cpu].icache;
struct cpuinfo_arc_cache *dc = &cpuinfo_arc700[cpu].dcache;
int way_pg_ratio = way_pg_ratio;
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
way_pg_ratio = ic->sz / ARC_ICACHE_WAYS / PAGE_SIZE;
switch (way_pg_ratio) {
case 0:
case 1:
___flush_icache_rtn = __ic_line_inv_no_alias;
break;
case 2:
___flush_icache_rtn = __ic_line_inv_2_alias;
break;
case 4:
___flush_icache_rtn = __ic_line_inv_4_alias;
break;
default:
panic("Unsupported I-Cache Sz\n");
}
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
if ((dc->sz / ARC_DCACHE_WAYS) > PAGE_SIZE)
panic("D$ aliasing not handled right now\n");
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
static inline void __dc_line_loop(unsigned long start, unsigned long sz,
int aux_reg)
{
int num_lines, slack;
if (!(__builtin_constant_p(sz) && sz == PAGE_SIZE)) {
slack = start & ~DCACHE_LINE_MASK;
sz += slack;
start -= slack;
}
num_lines = DIV_ROUND_UP(sz, ARC_DCACHE_LINE_LEN);
while (num_lines-- > 0) {
#if (CONFIG_ARC_MMU_VER > 2)
write_aux_reg(ARC_REG_DC_PTAG, start);
#endif
write_aux_reg(aux_reg, start);
start += ARC_DCACHE_LINE_LEN;
}
}
static inline void __dc_line_op(unsigned long start, unsigned long sz,
const int cacheop)
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
__dc_line_loop(start, sz, aux);
if (cacheop & OP_FLUSH)
wait_for_flush();
if (cacheop == OP_FLUSH_N_INV)
write_aux_reg(ARC_REG_DC_CTRL, tmp & ~DC_CTRL_INV_MODE_FLUSH);
local_irq_restore(flags);
}
static void __ic_line_inv_no_alias(unsigned long start, int num_lines)
{
while (num_lines-- > 0) {
#if (CONFIG_ARC_MMU_VER > 2)
write_aux_reg(ARC_REG_IC_PTAG, start);
#endif
write_aux_reg(ARC_REG_IC_IVIL, start);
start += ARC_ICACHE_LINE_LEN;
}
}
static void __ic_line_inv_2_alias(unsigned long start, int num_lines)
{
while (num_lines-- > 0) {
#if (CONFIG_ARC_MMU_VER > 2)
write_aux_reg(ARC_REG_IC_PTAG, start);
write_aux_reg(ARC_REG_IC_IVIL,
start & ~(0x1 << PAGE_SHIFT));
write_aux_reg(ARC_REG_IC_IVIL, start | (0x1 << PAGE_SHIFT));
#else
write_aux_reg(ARC_REG_IC_IVIL, start);
write_aux_reg(ARC_REG_IC_IVIL, start | 0x01);
#endif
start += ARC_ICACHE_LINE_LEN;
}
}
static void __ic_line_inv_4_alias(unsigned long start, int num_lines)
{
while (num_lines-- > 0) {
#if (CONFIG_ARC_MMU_VER > 2)
write_aux_reg(ARC_REG_IC_PTAG, start);
write_aux_reg(ARC_REG_IC_IVIL,
start & ~(0x3 << PAGE_SHIFT));
write_aux_reg(ARC_REG_IC_IVIL,
start & ~(0x2 << PAGE_SHIFT));
write_aux_reg(ARC_REG_IC_IVIL,
start & ~(0x1 << PAGE_SHIFT));
write_aux_reg(ARC_REG_IC_IVIL, start | (0x3 << PAGE_SHIFT));
#else
write_aux_reg(ARC_REG_IC_IVIL, start);
write_aux_reg(ARC_REG_IC_IVIL, start | 0x01);
write_aux_reg(ARC_REG_IC_IVIL, start | 0x02);
write_aux_reg(ARC_REG_IC_IVIL, start | 0x03);
#endif
start += ARC_ICACHE_LINE_LEN;
}
}
static void __ic_line_inv(unsigned long start, unsigned long sz)
{
unsigned long flags;
int num_lines, slack;
if (!(__builtin_constant_p(sz) && sz == PAGE_SIZE)) {
slack = start & ~ICACHE_LINE_MASK;
sz += slack;
start -= slack;
}
num_lines = DIV_ROUND_UP(sz, ARC_ICACHE_LINE_LEN);
local_irq_save(flags);
(*___flush_icache_rtn) (start, num_lines);
local_irq_restore(flags);
}
static void __ic_line_inv_vaddr(unsigned long phy_start,
unsigned long vaddr, unsigned long sz)
{
unsigned long flags;
int num_lines, slack;
unsigned int addr;
slack = phy_start & ~ICACHE_LINE_MASK;
sz += slack;
phy_start -= slack;
num_lines = DIV_ROUND_UP(sz, ARC_ICACHE_LINE_LEN);
#if (CONFIG_ARC_MMU_VER > 2)
vaddr &= ~ICACHE_LINE_MASK;
addr = phy_start;
#else
addr = phy_start | ((vaddr >> 13) & 0x1F);
#endif
local_irq_save(flags);
while (num_lines-- > 0) {
#if (CONFIG_ARC_MMU_VER > 2)
write_aux_reg(ARC_REG_IC_PTAG, addr);
write_aux_reg(ARC_REG_IC_IVIL, vaddr);
vaddr += ARC_ICACHE_LINE_LEN;
#else
write_aux_reg(ARC_REG_IC_IVIL, addr);
#endif
addr += ARC_ICACHE_LINE_LEN;
}
local_irq_restore(flags);
}
void flush_dcache_page(struct page *page)
{
__dc_line_op((unsigned long)page_address(page), PAGE_SIZE, OP_FLUSH);
}
void dma_cache_wback_inv(unsigned long start, unsigned long sz)
{
__dc_line_op(start, sz, OP_FLUSH_N_INV);
}
void dma_cache_inv(unsigned long start, unsigned long sz)
{
__dc_line_op(start, sz, OP_INV);
}
void dma_cache_wback(unsigned long start, unsigned long sz)
{
__dc_line_op(start, sz, OP_FLUSH);
}
void flush_icache_range(unsigned long kstart, unsigned long kend)
{
unsigned int tot_sz, off, sz;
unsigned long phy, pfn;
unsigned long flags;
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
__ic_line_inv(kstart, kend - kstart);
__dc_line_op(kstart, kend - kstart, OP_FLUSH);
return;
}
while (tot_sz > 0) {
off = kstart % PAGE_SIZE;
pfn = vmalloc_to_pfn((void *)kstart);
phy = (pfn << PAGE_SHIFT) + off;
sz = min_t(unsigned int, tot_sz, PAGE_SIZE - off);
local_irq_save(flags);
__dc_line_op(phy, sz, OP_FLUSH);
__ic_line_inv(phy, sz);
local_irq_restore(flags);
kstart += sz;
tot_sz -= sz;
}
}
void flush_icache_range_vaddr(unsigned long paddr, unsigned long u_vaddr,
int len)
{
__ic_line_inv_vaddr(paddr, u_vaddr, len);
__dc_line_op(paddr, len, OP_FLUSH);
}
void flush_icache_page(struct vm_area_struct *vma, struct page *page)
{
if (!(vma->vm_flags & VM_EXEC))
return;
__ic_line_inv((unsigned long)page_address(page), PAGE_SIZE);
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
