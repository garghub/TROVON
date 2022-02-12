static dma_addr_t __arm_lpae_dma_addr(void *pages)
{
return (dma_addr_t)virt_to_phys(pages);
}
static void *__arm_lpae_alloc_pages(size_t size, gfp_t gfp,
struct io_pgtable_cfg *cfg)
{
struct device *dev = cfg->iommu_dev;
dma_addr_t dma;
void *pages = alloc_pages_exact(size, gfp | __GFP_ZERO);
if (!pages)
return NULL;
if (!selftest_running) {
dma = dma_map_single(dev, pages, size, DMA_TO_DEVICE);
if (dma_mapping_error(dev, dma))
goto out_free;
if (dma != virt_to_phys(pages))
goto out_unmap;
}
return pages;
out_unmap:
dev_err(dev, "Cannot accommodate DMA translation for IOMMU page tables\n");
dma_unmap_single(dev, dma, size, DMA_TO_DEVICE);
out_free:
free_pages_exact(pages, size);
return NULL;
}
static void __arm_lpae_free_pages(void *pages, size_t size,
struct io_pgtable_cfg *cfg)
{
if (!selftest_running)
dma_unmap_single(cfg->iommu_dev, __arm_lpae_dma_addr(pages),
size, DMA_TO_DEVICE);
free_pages_exact(pages, size);
}
static void __arm_lpae_set_pte(arm_lpae_iopte *ptep, arm_lpae_iopte pte,
struct io_pgtable_cfg *cfg)
{
*ptep = pte;
if (!selftest_running)
dma_sync_single_for_device(cfg->iommu_dev,
__arm_lpae_dma_addr(ptep),
sizeof(pte), DMA_TO_DEVICE);
}
static int arm_lpae_init_pte(struct arm_lpae_io_pgtable *data,
unsigned long iova, phys_addr_t paddr,
arm_lpae_iopte prot, int lvl,
arm_lpae_iopte *ptep)
{
arm_lpae_iopte pte = prot;
struct io_pgtable_cfg *cfg = &data->iop.cfg;
if (iopte_leaf(*ptep, lvl)) {
WARN_ON(!selftest_running);
return -EEXIST;
} else if (iopte_type(*ptep, lvl) == ARM_LPAE_PTE_TYPE_TABLE) {
arm_lpae_iopte *tblp;
size_t sz = ARM_LPAE_BLOCK_SIZE(lvl, data);
tblp = ptep - ARM_LPAE_LVL_IDX(iova, lvl, data);
if (WARN_ON(__arm_lpae_unmap(data, iova, sz, lvl, tblp) != sz))
return -EINVAL;
}
if (cfg->quirks & IO_PGTABLE_QUIRK_ARM_NS)
pte |= ARM_LPAE_PTE_NS;
if (lvl == ARM_LPAE_MAX_LEVELS - 1)
pte |= ARM_LPAE_PTE_TYPE_PAGE;
else
pte |= ARM_LPAE_PTE_TYPE_BLOCK;
pte |= ARM_LPAE_PTE_AF | ARM_LPAE_PTE_SH_IS;
pte |= pfn_to_iopte(paddr >> data->pg_shift, data);
__arm_lpae_set_pte(ptep, pte, cfg);
return 0;
}
static int __arm_lpae_map(struct arm_lpae_io_pgtable *data, unsigned long iova,
phys_addr_t paddr, size_t size, arm_lpae_iopte prot,
int lvl, arm_lpae_iopte *ptep)
{
arm_lpae_iopte *cptep, pte;
size_t block_size = ARM_LPAE_BLOCK_SIZE(lvl, data);
struct io_pgtable_cfg *cfg = &data->iop.cfg;
ptep += ARM_LPAE_LVL_IDX(iova, lvl, data);
if (size == block_size && (size & cfg->pgsize_bitmap))
return arm_lpae_init_pte(data, iova, paddr, prot, lvl, ptep);
if (WARN_ON(lvl >= ARM_LPAE_MAX_LEVELS - 1))
return -EINVAL;
pte = *ptep;
if (!pte) {
cptep = __arm_lpae_alloc_pages(ARM_LPAE_GRANULE(data),
GFP_ATOMIC, cfg);
if (!cptep)
return -ENOMEM;
pte = __pa(cptep) | ARM_LPAE_PTE_TYPE_TABLE;
if (cfg->quirks & IO_PGTABLE_QUIRK_ARM_NS)
pte |= ARM_LPAE_PTE_NSTABLE;
__arm_lpae_set_pte(ptep, pte, cfg);
} else {
cptep = iopte_deref(pte, data);
}
return __arm_lpae_map(data, iova, paddr, size, prot, lvl + 1, cptep);
}
static arm_lpae_iopte arm_lpae_prot_to_pte(struct arm_lpae_io_pgtable *data,
int prot)
{
arm_lpae_iopte pte;
if (data->iop.fmt == ARM_64_LPAE_S1 ||
data->iop.fmt == ARM_32_LPAE_S1) {
pte = ARM_LPAE_PTE_AP_UNPRIV | ARM_LPAE_PTE_nG;
if (!(prot & IOMMU_WRITE) && (prot & IOMMU_READ))
pte |= ARM_LPAE_PTE_AP_RDONLY;
if (prot & IOMMU_MMIO)
pte |= (ARM_LPAE_MAIR_ATTR_IDX_DEV
<< ARM_LPAE_PTE_ATTRINDX_SHIFT);
else if (prot & IOMMU_CACHE)
pte |= (ARM_LPAE_MAIR_ATTR_IDX_CACHE
<< ARM_LPAE_PTE_ATTRINDX_SHIFT);
} else {
pte = ARM_LPAE_PTE_HAP_FAULT;
if (prot & IOMMU_READ)
pte |= ARM_LPAE_PTE_HAP_READ;
if (prot & IOMMU_WRITE)
pte |= ARM_LPAE_PTE_HAP_WRITE;
if (prot & IOMMU_MMIO)
pte |= ARM_LPAE_PTE_MEMATTR_DEV;
else if (prot & IOMMU_CACHE)
pte |= ARM_LPAE_PTE_MEMATTR_OIWB;
else
pte |= ARM_LPAE_PTE_MEMATTR_NC;
}
if (prot & IOMMU_NOEXEC)
pte |= ARM_LPAE_PTE_XN;
return pte;
}
static int arm_lpae_map(struct io_pgtable_ops *ops, unsigned long iova,
phys_addr_t paddr, size_t size, int iommu_prot)
{
struct arm_lpae_io_pgtable *data = io_pgtable_ops_to_data(ops);
arm_lpae_iopte *ptep = data->pgd;
int ret, lvl = ARM_LPAE_START_LVL(data);
arm_lpae_iopte prot;
if (!(iommu_prot & (IOMMU_READ | IOMMU_WRITE)))
return 0;
prot = arm_lpae_prot_to_pte(data, iommu_prot);
ret = __arm_lpae_map(data, iova, paddr, size, prot, lvl, ptep);
wmb();
return ret;
}
static void __arm_lpae_free_pgtable(struct arm_lpae_io_pgtable *data, int lvl,
arm_lpae_iopte *ptep)
{
arm_lpae_iopte *start, *end;
unsigned long table_size;
if (lvl == ARM_LPAE_START_LVL(data))
table_size = data->pgd_size;
else
table_size = ARM_LPAE_GRANULE(data);
start = ptep;
if (lvl == ARM_LPAE_MAX_LEVELS - 1)
end = ptep;
else
end = (void *)ptep + table_size;
while (ptep != end) {
arm_lpae_iopte pte = *ptep++;
if (!pte || iopte_leaf(pte, lvl))
continue;
__arm_lpae_free_pgtable(data, lvl + 1, iopte_deref(pte, data));
}
__arm_lpae_free_pages(start, table_size, &data->iop.cfg);
}
static void arm_lpae_free_pgtable(struct io_pgtable *iop)
{
struct arm_lpae_io_pgtable *data = io_pgtable_to_data(iop);
__arm_lpae_free_pgtable(data, ARM_LPAE_START_LVL(data), data->pgd);
kfree(data);
}
static int arm_lpae_split_blk_unmap(struct arm_lpae_io_pgtable *data,
unsigned long iova, size_t size,
arm_lpae_iopte prot, int lvl,
arm_lpae_iopte *ptep, size_t blk_size)
{
unsigned long blk_start, blk_end;
phys_addr_t blk_paddr;
arm_lpae_iopte table = 0;
blk_start = iova & ~(blk_size - 1);
blk_end = blk_start + blk_size;
blk_paddr = iopte_to_pfn(*ptep, data) << data->pg_shift;
for (; blk_start < blk_end; blk_start += size, blk_paddr += size) {
arm_lpae_iopte *tablep;
if (blk_start == iova)
continue;
tablep = &table - ARM_LPAE_LVL_IDX(blk_start, lvl, data);
if (__arm_lpae_map(data, blk_start, blk_paddr, size, prot, lvl,
tablep) < 0) {
if (table) {
tablep = iopte_deref(table, data);
__arm_lpae_free_pgtable(data, lvl + 1, tablep);
}
return 0;
}
}
__arm_lpae_set_pte(ptep, table, &data->iop.cfg);
iova &= ~(blk_size - 1);
io_pgtable_tlb_add_flush(&data->iop, iova, blk_size, blk_size, true);
return size;
}
static int __arm_lpae_unmap(struct arm_lpae_io_pgtable *data,
unsigned long iova, size_t size, int lvl,
arm_lpae_iopte *ptep)
{
arm_lpae_iopte pte;
struct io_pgtable *iop = &data->iop;
size_t blk_size = ARM_LPAE_BLOCK_SIZE(lvl, data);
if (WARN_ON(lvl == ARM_LPAE_MAX_LEVELS))
return 0;
ptep += ARM_LPAE_LVL_IDX(iova, lvl, data);
pte = *ptep;
if (WARN_ON(!pte))
return 0;
if (size == blk_size) {
__arm_lpae_set_pte(ptep, 0, &iop->cfg);
if (!iopte_leaf(pte, lvl)) {
io_pgtable_tlb_add_flush(iop, iova, size,
ARM_LPAE_GRANULE(data), false);
io_pgtable_tlb_sync(iop);
ptep = iopte_deref(pte, data);
__arm_lpae_free_pgtable(data, lvl + 1, ptep);
} else {
io_pgtable_tlb_add_flush(iop, iova, size, size, true);
}
return size;
} else if (iopte_leaf(pte, lvl)) {
return arm_lpae_split_blk_unmap(data, iova, size,
iopte_prot(pte), lvl, ptep,
blk_size);
}
ptep = iopte_deref(pte, data);
return __arm_lpae_unmap(data, iova, size, lvl + 1, ptep);
}
static int arm_lpae_unmap(struct io_pgtable_ops *ops, unsigned long iova,
size_t size)
{
size_t unmapped;
struct arm_lpae_io_pgtable *data = io_pgtable_ops_to_data(ops);
arm_lpae_iopte *ptep = data->pgd;
int lvl = ARM_LPAE_START_LVL(data);
unmapped = __arm_lpae_unmap(data, iova, size, lvl, ptep);
if (unmapped)
io_pgtable_tlb_sync(&data->iop);
return unmapped;
}
static phys_addr_t arm_lpae_iova_to_phys(struct io_pgtable_ops *ops,
unsigned long iova)
{
struct arm_lpae_io_pgtable *data = io_pgtable_ops_to_data(ops);
arm_lpae_iopte pte, *ptep = data->pgd;
int lvl = ARM_LPAE_START_LVL(data);
do {
if (!ptep)
return 0;
pte = *(ptep + ARM_LPAE_LVL_IDX(iova, lvl, data));
if (!pte)
return 0;
if (iopte_leaf(pte,lvl))
goto found_translation;
ptep = iopte_deref(pte, data);
} while (++lvl < ARM_LPAE_MAX_LEVELS);
return 0;
found_translation:
iova &= (ARM_LPAE_GRANULE(data) - 1);
return ((phys_addr_t)iopte_to_pfn(pte,data) << data->pg_shift) | iova;
}
static void arm_lpae_restrict_pgsizes(struct io_pgtable_cfg *cfg)
{
unsigned long granule;
if (cfg->pgsize_bitmap & PAGE_SIZE)
granule = PAGE_SIZE;
else if (cfg->pgsize_bitmap & ~PAGE_MASK)
granule = 1UL << __fls(cfg->pgsize_bitmap & ~PAGE_MASK);
else if (cfg->pgsize_bitmap & PAGE_MASK)
granule = 1UL << __ffs(cfg->pgsize_bitmap & PAGE_MASK);
else
granule = 0;
switch (granule) {
case SZ_4K:
cfg->pgsize_bitmap &= (SZ_4K | SZ_2M | SZ_1G);
break;
case SZ_16K:
cfg->pgsize_bitmap &= (SZ_16K | SZ_32M);
break;
case SZ_64K:
cfg->pgsize_bitmap &= (SZ_64K | SZ_512M);
break;
default:
cfg->pgsize_bitmap = 0;
}
}
static struct arm_lpae_io_pgtable *
arm_lpae_alloc_pgtable(struct io_pgtable_cfg *cfg)
{
unsigned long va_bits, pgd_bits;
struct arm_lpae_io_pgtable *data;
arm_lpae_restrict_pgsizes(cfg);
if (!(cfg->pgsize_bitmap & (SZ_4K | SZ_16K | SZ_64K)))
return NULL;
if (cfg->ias > ARM_LPAE_MAX_ADDR_BITS)
return NULL;
if (cfg->oas > ARM_LPAE_MAX_ADDR_BITS)
return NULL;
if (!selftest_running && cfg->iommu_dev->dma_pfn_offset) {
dev_err(cfg->iommu_dev, "Cannot accommodate DMA offset for IOMMU page tables\n");
return NULL;
}
data = kmalloc(sizeof(*data), GFP_KERNEL);
if (!data)
return NULL;
data->pg_shift = __ffs(cfg->pgsize_bitmap);
data->bits_per_level = data->pg_shift - ilog2(sizeof(arm_lpae_iopte));
va_bits = cfg->ias - data->pg_shift;
data->levels = DIV_ROUND_UP(va_bits, data->bits_per_level);
pgd_bits = va_bits - (data->bits_per_level * (data->levels - 1));
data->pgd_size = 1UL << (pgd_bits + ilog2(sizeof(arm_lpae_iopte)));
data->iop.ops = (struct io_pgtable_ops) {
.map = arm_lpae_map,
.unmap = arm_lpae_unmap,
.iova_to_phys = arm_lpae_iova_to_phys,
};
return data;
}
static struct io_pgtable *
arm_64_lpae_alloc_pgtable_s1(struct io_pgtable_cfg *cfg, void *cookie)
{
u64 reg;
struct arm_lpae_io_pgtable *data;
if (cfg->quirks & ~IO_PGTABLE_QUIRK_ARM_NS)
return NULL;
data = arm_lpae_alloc_pgtable(cfg);
if (!data)
return NULL;
reg = (ARM_LPAE_TCR_SH_IS << ARM_LPAE_TCR_SH0_SHIFT) |
(ARM_LPAE_TCR_RGN_WBWA << ARM_LPAE_TCR_IRGN0_SHIFT) |
(ARM_LPAE_TCR_RGN_WBWA << ARM_LPAE_TCR_ORGN0_SHIFT);
switch (ARM_LPAE_GRANULE(data)) {
case SZ_4K:
reg |= ARM_LPAE_TCR_TG0_4K;
break;
case SZ_16K:
reg |= ARM_LPAE_TCR_TG0_16K;
break;
case SZ_64K:
reg |= ARM_LPAE_TCR_TG0_64K;
break;
}
switch (cfg->oas) {
case 32:
reg |= (ARM_LPAE_TCR_PS_32_BIT << ARM_LPAE_TCR_IPS_SHIFT);
break;
case 36:
reg |= (ARM_LPAE_TCR_PS_36_BIT << ARM_LPAE_TCR_IPS_SHIFT);
break;
case 40:
reg |= (ARM_LPAE_TCR_PS_40_BIT << ARM_LPAE_TCR_IPS_SHIFT);
break;
case 42:
reg |= (ARM_LPAE_TCR_PS_42_BIT << ARM_LPAE_TCR_IPS_SHIFT);
break;
case 44:
reg |= (ARM_LPAE_TCR_PS_44_BIT << ARM_LPAE_TCR_IPS_SHIFT);
break;
case 48:
reg |= (ARM_LPAE_TCR_PS_48_BIT << ARM_LPAE_TCR_IPS_SHIFT);
break;
default:
goto out_free_data;
}
reg |= (64ULL - cfg->ias) << ARM_LPAE_TCR_T0SZ_SHIFT;
reg |= ARM_LPAE_TCR_EPD1;
cfg->arm_lpae_s1_cfg.tcr = reg;
reg = (ARM_LPAE_MAIR_ATTR_NC
<< ARM_LPAE_MAIR_ATTR_SHIFT(ARM_LPAE_MAIR_ATTR_IDX_NC)) |
(ARM_LPAE_MAIR_ATTR_WBRWA
<< ARM_LPAE_MAIR_ATTR_SHIFT(ARM_LPAE_MAIR_ATTR_IDX_CACHE)) |
(ARM_LPAE_MAIR_ATTR_DEVICE
<< ARM_LPAE_MAIR_ATTR_SHIFT(ARM_LPAE_MAIR_ATTR_IDX_DEV));
cfg->arm_lpae_s1_cfg.mair[0] = reg;
cfg->arm_lpae_s1_cfg.mair[1] = 0;
data->pgd = __arm_lpae_alloc_pages(data->pgd_size, GFP_KERNEL, cfg);
if (!data->pgd)
goto out_free_data;
wmb();
cfg->arm_lpae_s1_cfg.ttbr[0] = virt_to_phys(data->pgd);
cfg->arm_lpae_s1_cfg.ttbr[1] = 0;
return &data->iop;
out_free_data:
kfree(data);
return NULL;
}
static struct io_pgtable *
arm_64_lpae_alloc_pgtable_s2(struct io_pgtable_cfg *cfg, void *cookie)
{
u64 reg, sl;
struct arm_lpae_io_pgtable *data;
if (cfg->quirks)
return NULL;
data = arm_lpae_alloc_pgtable(cfg);
if (!data)
return NULL;
if (data->levels == ARM_LPAE_MAX_LEVELS) {
unsigned long pgd_pages;
pgd_pages = data->pgd_size >> ilog2(sizeof(arm_lpae_iopte));
if (pgd_pages <= ARM_LPAE_S2_MAX_CONCAT_PAGES) {
data->pgd_size = pgd_pages << data->pg_shift;
data->levels--;
}
}
reg = ARM_64_LPAE_S2_TCR_RES1 |
(ARM_LPAE_TCR_SH_IS << ARM_LPAE_TCR_SH0_SHIFT) |
(ARM_LPAE_TCR_RGN_WBWA << ARM_LPAE_TCR_IRGN0_SHIFT) |
(ARM_LPAE_TCR_RGN_WBWA << ARM_LPAE_TCR_ORGN0_SHIFT);
sl = ARM_LPAE_START_LVL(data);
switch (ARM_LPAE_GRANULE(data)) {
case SZ_4K:
reg |= ARM_LPAE_TCR_TG0_4K;
sl++;
break;
case SZ_16K:
reg |= ARM_LPAE_TCR_TG0_16K;
break;
case SZ_64K:
reg |= ARM_LPAE_TCR_TG0_64K;
break;
}
switch (cfg->oas) {
case 32:
reg |= (ARM_LPAE_TCR_PS_32_BIT << ARM_LPAE_TCR_PS_SHIFT);
break;
case 36:
reg |= (ARM_LPAE_TCR_PS_36_BIT << ARM_LPAE_TCR_PS_SHIFT);
break;
case 40:
reg |= (ARM_LPAE_TCR_PS_40_BIT << ARM_LPAE_TCR_PS_SHIFT);
break;
case 42:
reg |= (ARM_LPAE_TCR_PS_42_BIT << ARM_LPAE_TCR_PS_SHIFT);
break;
case 44:
reg |= (ARM_LPAE_TCR_PS_44_BIT << ARM_LPAE_TCR_PS_SHIFT);
break;
case 48:
reg |= (ARM_LPAE_TCR_PS_48_BIT << ARM_LPAE_TCR_PS_SHIFT);
break;
default:
goto out_free_data;
}
reg |= (64ULL - cfg->ias) << ARM_LPAE_TCR_T0SZ_SHIFT;
reg |= (~sl & ARM_LPAE_TCR_SL0_MASK) << ARM_LPAE_TCR_SL0_SHIFT;
cfg->arm_lpae_s2_cfg.vtcr = reg;
data->pgd = __arm_lpae_alloc_pages(data->pgd_size, GFP_KERNEL, cfg);
if (!data->pgd)
goto out_free_data;
wmb();
cfg->arm_lpae_s2_cfg.vttbr = virt_to_phys(data->pgd);
return &data->iop;
out_free_data:
kfree(data);
return NULL;
}
static struct io_pgtable *
arm_32_lpae_alloc_pgtable_s1(struct io_pgtable_cfg *cfg, void *cookie)
{
struct io_pgtable *iop;
if (cfg->ias > 32 || cfg->oas > 40)
return NULL;
cfg->pgsize_bitmap &= (SZ_4K | SZ_2M | SZ_1G);
iop = arm_64_lpae_alloc_pgtable_s1(cfg, cookie);
if (iop) {
cfg->arm_lpae_s1_cfg.tcr |= ARM_32_LPAE_TCR_EAE;
cfg->arm_lpae_s1_cfg.tcr &= 0xffffffff;
}
return iop;
}
static struct io_pgtable *
arm_32_lpae_alloc_pgtable_s2(struct io_pgtable_cfg *cfg, void *cookie)
{
struct io_pgtable *iop;
if (cfg->ias > 40 || cfg->oas > 40)
return NULL;
cfg->pgsize_bitmap &= (SZ_4K | SZ_2M | SZ_1G);
iop = arm_64_lpae_alloc_pgtable_s2(cfg, cookie);
if (iop)
cfg->arm_lpae_s2_cfg.vtcr &= 0xffffffff;
return iop;
}
static void dummy_tlb_flush_all(void *cookie)
{
WARN_ON(cookie != cfg_cookie);
}
static void dummy_tlb_add_flush(unsigned long iova, size_t size,
size_t granule, bool leaf, void *cookie)
{
WARN_ON(cookie != cfg_cookie);
WARN_ON(!(size & cfg_cookie->pgsize_bitmap));
}
static void dummy_tlb_sync(void *cookie)
{
WARN_ON(cookie != cfg_cookie);
}
static void __init arm_lpae_dump_ops(struct io_pgtable_ops *ops)
{
struct arm_lpae_io_pgtable *data = io_pgtable_ops_to_data(ops);
struct io_pgtable_cfg *cfg = &data->iop.cfg;
pr_err("cfg: pgsize_bitmap 0x%lx, ias %u-bit\n",
cfg->pgsize_bitmap, cfg->ias);
pr_err("data: %d levels, 0x%zx pgd_size, %lu pg_shift, %lu bits_per_level, pgd @ %p\n",
data->levels, data->pgd_size, data->pg_shift,
data->bits_per_level, data->pgd);
}
static int __init arm_lpae_run_tests(struct io_pgtable_cfg *cfg)
{
static const enum io_pgtable_fmt fmts[] = {
ARM_64_LPAE_S1,
ARM_64_LPAE_S2,
};
int i, j;
unsigned long iova;
size_t size;
struct io_pgtable_ops *ops;
selftest_running = true;
for (i = 0; i < ARRAY_SIZE(fmts); ++i) {
cfg_cookie = cfg;
ops = alloc_io_pgtable_ops(fmts[i], cfg, cfg);
if (!ops) {
pr_err("selftest: failed to allocate io pgtable ops\n");
return -ENOMEM;
}
if (ops->iova_to_phys(ops, 42))
return __FAIL(ops, i);
if (ops->iova_to_phys(ops, SZ_1G + 42))
return __FAIL(ops, i);
if (ops->iova_to_phys(ops, SZ_2G + 42))
return __FAIL(ops, i);
iova = 0;
j = find_first_bit(&cfg->pgsize_bitmap, BITS_PER_LONG);
while (j != BITS_PER_LONG) {
size = 1UL << j;
if (ops->map(ops, iova, iova, size, IOMMU_READ |
IOMMU_WRITE |
IOMMU_NOEXEC |
IOMMU_CACHE))
return __FAIL(ops, i);
if (!ops->map(ops, iova, iova + size, size,
IOMMU_READ | IOMMU_NOEXEC))
return __FAIL(ops, i);
if (ops->iova_to_phys(ops, iova + 42) != (iova + 42))
return __FAIL(ops, i);
iova += SZ_1G;
j++;
j = find_next_bit(&cfg->pgsize_bitmap, BITS_PER_LONG, j);
}
size = 1UL << __ffs(cfg->pgsize_bitmap);
if (ops->unmap(ops, SZ_1G + size, size) != size)
return __FAIL(ops, i);
if (ops->map(ops, SZ_1G + size, size, size, IOMMU_READ))
return __FAIL(ops, i);
if (ops->iova_to_phys(ops, SZ_1G + size + 42) != (size + 42))
return __FAIL(ops, i);
iova = 0;
j = find_first_bit(&cfg->pgsize_bitmap, BITS_PER_LONG);
while (j != BITS_PER_LONG) {
size = 1UL << j;
if (ops->unmap(ops, iova, size) != size)
return __FAIL(ops, i);
if (ops->iova_to_phys(ops, iova + 42))
return __FAIL(ops, i);
if (ops->map(ops, iova, iova, size, IOMMU_WRITE))
return __FAIL(ops, i);
if (ops->iova_to_phys(ops, iova + 42) != (iova + 42))
return __FAIL(ops, i);
iova += SZ_1G;
j++;
j = find_next_bit(&cfg->pgsize_bitmap, BITS_PER_LONG, j);
}
free_io_pgtable_ops(ops);
}
selftest_running = false;
return 0;
}
static int __init arm_lpae_do_selftests(void)
{
static const unsigned long pgsize[] = {
SZ_4K | SZ_2M | SZ_1G,
SZ_16K | SZ_32M,
SZ_64K | SZ_512M,
};
static const unsigned int ias[] = {
32, 36, 40, 42, 44, 48,
};
int i, j, pass = 0, fail = 0;
struct io_pgtable_cfg cfg = {
.tlb = &dummy_tlb_ops,
.oas = 48,
};
for (i = 0; i < ARRAY_SIZE(pgsize); ++i) {
for (j = 0; j < ARRAY_SIZE(ias); ++j) {
cfg.pgsize_bitmap = pgsize[i];
cfg.ias = ias[j];
pr_info("selftest: pgsize_bitmap 0x%08lx, IAS %u\n",
pgsize[i], ias[j]);
if (arm_lpae_run_tests(&cfg))
fail++;
else
pass++;
}
}
pr_info("selftest: completed with %d PASS %d FAIL\n", pass, fail);
return fail ? -EFAULT : 0;
}
