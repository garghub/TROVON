static u32 lv1ent_offset(sysmmu_iova_t iova)
{
return iova >> SECT_ORDER;
}
static u32 lv2ent_offset(sysmmu_iova_t iova)
{
return (iova >> SPAGE_ORDER) & (NUM_LV2ENTRIES - 1);
}
static sysmmu_pte_t *section_entry(sysmmu_pte_t *pgtable, sysmmu_iova_t iova)
{
return pgtable + lv1ent_offset(iova);
}
static sysmmu_pte_t *page_entry(sysmmu_pte_t *sent, sysmmu_iova_t iova)
{
return (sysmmu_pte_t *)phys_to_virt(
lv2table_base(sent)) + lv2ent_offset(iova);
}
static struct exynos_iommu_domain *to_exynos_domain(struct iommu_domain *dom)
{
return container_of(dom, struct exynos_iommu_domain, domain);
}
static void sysmmu_unblock(struct sysmmu_drvdata *data)
{
writel(CTRL_ENABLE, data->sfrbase + REG_MMU_CTRL);
}
static bool sysmmu_block(struct sysmmu_drvdata *data)
{
int i = 120;
writel(CTRL_BLOCK, data->sfrbase + REG_MMU_CTRL);
while ((i > 0) && !(readl(data->sfrbase + REG_MMU_STATUS) & 1))
--i;
if (!(readl(data->sfrbase + REG_MMU_STATUS) & 1)) {
sysmmu_unblock(data);
return false;
}
return true;
}
static void __sysmmu_tlb_invalidate(struct sysmmu_drvdata *data)
{
if (MMU_MAJ_VER(data->version) < 5)
writel(0x1, data->sfrbase + REG_MMU_FLUSH);
else
writel(0x1, data->sfrbase + REG_V5_MMU_FLUSH_ALL);
}
static void __sysmmu_tlb_invalidate_entry(struct sysmmu_drvdata *data,
sysmmu_iova_t iova, unsigned int num_inv)
{
unsigned int i;
if (MMU_MAJ_VER(data->version) < 5) {
for (i = 0; i < num_inv; i++) {
writel((iova & SPAGE_MASK) | 1,
data->sfrbase + REG_MMU_FLUSH_ENTRY);
iova += SPAGE_SIZE;
}
} else {
if (num_inv == 1) {
writel((iova & SPAGE_MASK) | 1,
data->sfrbase + REG_V5_MMU_FLUSH_ENTRY);
} else {
writel((iova & SPAGE_MASK),
data->sfrbase + REG_V5_MMU_FLUSH_START);
writel((iova & SPAGE_MASK) + (num_inv - 1) * SPAGE_SIZE,
data->sfrbase + REG_V5_MMU_FLUSH_END);
writel(1, data->sfrbase + REG_V5_MMU_FLUSH_RANGE);
}
}
}
static void __sysmmu_set_ptbase(struct sysmmu_drvdata *data, phys_addr_t pgd)
{
if (MMU_MAJ_VER(data->version) < 5)
writel(pgd, data->sfrbase + REG_PT_BASE_ADDR);
else
writel(pgd >> PAGE_SHIFT,
data->sfrbase + REG_V5_PT_BASE_PFN);
__sysmmu_tlb_invalidate(data);
}
static void __sysmmu_enable_clocks(struct sysmmu_drvdata *data)
{
BUG_ON(clk_prepare_enable(data->clk_master));
BUG_ON(clk_prepare_enable(data->clk));
BUG_ON(clk_prepare_enable(data->pclk));
BUG_ON(clk_prepare_enable(data->aclk));
}
static void __sysmmu_disable_clocks(struct sysmmu_drvdata *data)
{
clk_disable_unprepare(data->aclk);
clk_disable_unprepare(data->pclk);
clk_disable_unprepare(data->clk);
clk_disable_unprepare(data->clk_master);
}
static void __sysmmu_get_version(struct sysmmu_drvdata *data)
{
u32 ver;
__sysmmu_enable_clocks(data);
ver = readl(data->sfrbase + REG_MMU_VERSION);
if (ver == 0x80000001u)
data->version = MAKE_MMU_VER(1, 0);
else
data->version = MMU_RAW_VER(ver);
dev_dbg(data->sysmmu, "hardware version: %d.%d\n",
MMU_MAJ_VER(data->version), MMU_MIN_VER(data->version));
__sysmmu_disable_clocks(data);
}
static void show_fault_information(struct sysmmu_drvdata *data,
const struct sysmmu_fault_info *finfo,
sysmmu_iova_t fault_addr)
{
sysmmu_pte_t *ent;
dev_err(data->sysmmu, "%s: %s FAULT occurred at %#x\n",
dev_name(data->master), finfo->name, fault_addr);
dev_dbg(data->sysmmu, "Page table base: %pa\n", &data->pgtable);
ent = section_entry(phys_to_virt(data->pgtable), fault_addr);
dev_dbg(data->sysmmu, "\tLv1 entry: %#x\n", *ent);
if (lv1ent_page(ent)) {
ent = page_entry(ent, fault_addr);
dev_dbg(data->sysmmu, "\t Lv2 entry: %#x\n", *ent);
}
}
static irqreturn_t exynos_sysmmu_irq(int irq, void *dev_id)
{
struct sysmmu_drvdata *data = dev_id;
const struct sysmmu_fault_info *finfo;
unsigned int i, n, itype;
sysmmu_iova_t fault_addr = -1;
unsigned short reg_status, reg_clear;
int ret = -ENOSYS;
WARN_ON(!data->active);
if (MMU_MAJ_VER(data->version) < 5) {
reg_status = REG_INT_STATUS;
reg_clear = REG_INT_CLEAR;
finfo = sysmmu_faults;
n = ARRAY_SIZE(sysmmu_faults);
} else {
reg_status = REG_V5_INT_STATUS;
reg_clear = REG_V5_INT_CLEAR;
finfo = sysmmu_v5_faults;
n = ARRAY_SIZE(sysmmu_v5_faults);
}
spin_lock(&data->lock);
clk_enable(data->clk_master);
itype = __ffs(readl(data->sfrbase + reg_status));
for (i = 0; i < n; i++, finfo++)
if (finfo->bit == itype)
break;
BUG_ON(i == n);
fault_addr = readl(data->sfrbase + finfo->addr_reg);
show_fault_information(data, finfo, fault_addr);
if (data->domain)
ret = report_iommu_fault(&data->domain->domain,
data->master, fault_addr, finfo->type);
BUG_ON(ret != 0);
writel(1 << itype, data->sfrbase + reg_clear);
sysmmu_unblock(data);
clk_disable(data->clk_master);
spin_unlock(&data->lock);
return IRQ_HANDLED;
}
static void __sysmmu_disable(struct sysmmu_drvdata *data)
{
unsigned long flags;
clk_enable(data->clk_master);
spin_lock_irqsave(&data->lock, flags);
writel(CTRL_DISABLE, data->sfrbase + REG_MMU_CTRL);
writel(0, data->sfrbase + REG_MMU_CFG);
data->active = false;
spin_unlock_irqrestore(&data->lock, flags);
__sysmmu_disable_clocks(data);
}
static void __sysmmu_init_config(struct sysmmu_drvdata *data)
{
unsigned int cfg;
if (data->version <= MAKE_MMU_VER(3, 1))
cfg = CFG_LRU | CFG_QOS(15);
else if (data->version <= MAKE_MMU_VER(3, 2))
cfg = CFG_LRU | CFG_QOS(15) | CFG_FLPDCACHE | CFG_SYSSEL;
else
cfg = CFG_QOS(15) | CFG_FLPDCACHE | CFG_ACGEN;
cfg |= CFG_EAP;
writel(cfg, data->sfrbase + REG_MMU_CFG);
}
static void __sysmmu_enable(struct sysmmu_drvdata *data)
{
unsigned long flags;
__sysmmu_enable_clocks(data);
spin_lock_irqsave(&data->lock, flags);
writel(CTRL_BLOCK, data->sfrbase + REG_MMU_CTRL);
__sysmmu_init_config(data);
__sysmmu_set_ptbase(data, data->pgtable);
writel(CTRL_ENABLE, data->sfrbase + REG_MMU_CTRL);
data->active = true;
spin_unlock_irqrestore(&data->lock, flags);
clk_disable(data->clk_master);
}
static void sysmmu_tlb_invalidate_flpdcache(struct sysmmu_drvdata *data,
sysmmu_iova_t iova)
{
unsigned long flags;
spin_lock_irqsave(&data->lock, flags);
if (data->active && data->version >= MAKE_MMU_VER(3, 3)) {
clk_enable(data->clk_master);
if (sysmmu_block(data)) {
if (data->version >= MAKE_MMU_VER(5, 0))
__sysmmu_tlb_invalidate(data);
else
__sysmmu_tlb_invalidate_entry(data, iova, 1);
sysmmu_unblock(data);
}
clk_disable(data->clk_master);
}
spin_unlock_irqrestore(&data->lock, flags);
}
static void sysmmu_tlb_invalidate_entry(struct sysmmu_drvdata *data,
sysmmu_iova_t iova, size_t size)
{
unsigned long flags;
spin_lock_irqsave(&data->lock, flags);
if (data->active) {
unsigned int num_inv = 1;
clk_enable(data->clk_master);
if (MMU_MAJ_VER(data->version) == 2)
num_inv = min_t(unsigned int, size / PAGE_SIZE, 64);
if (sysmmu_block(data)) {
__sysmmu_tlb_invalidate_entry(data, iova, num_inv);
sysmmu_unblock(data);
}
clk_disable(data->clk_master);
}
spin_unlock_irqrestore(&data->lock, flags);
}
static int __init exynos_sysmmu_probe(struct platform_device *pdev)
{
int irq, ret;
struct device *dev = &pdev->dev;
struct sysmmu_drvdata *data;
struct resource *res;
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->sfrbase = devm_ioremap_resource(dev, res);
if (IS_ERR(data->sfrbase))
return PTR_ERR(data->sfrbase);
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_err(dev, "Unable to find IRQ resource\n");
return irq;
}
ret = devm_request_irq(dev, irq, exynos_sysmmu_irq, 0,
dev_name(dev), data);
if (ret) {
dev_err(dev, "Unabled to register handler of irq %d\n", irq);
return ret;
}
data->clk = devm_clk_get(dev, "sysmmu");
if (PTR_ERR(data->clk) == -ENOENT)
data->clk = NULL;
else if (IS_ERR(data->clk))
return PTR_ERR(data->clk);
data->aclk = devm_clk_get(dev, "aclk");
if (PTR_ERR(data->aclk) == -ENOENT)
data->aclk = NULL;
else if (IS_ERR(data->aclk))
return PTR_ERR(data->aclk);
data->pclk = devm_clk_get(dev, "pclk");
if (PTR_ERR(data->pclk) == -ENOENT)
data->pclk = NULL;
else if (IS_ERR(data->pclk))
return PTR_ERR(data->pclk);
if (!data->clk && (!data->aclk || !data->pclk)) {
dev_err(dev, "Failed to get device clock(s)!\n");
return -ENOSYS;
}
data->clk_master = devm_clk_get(dev, "master");
if (PTR_ERR(data->clk_master) == -ENOENT)
data->clk_master = NULL;
else if (IS_ERR(data->clk_master))
return PTR_ERR(data->clk_master);
data->sysmmu = dev;
spin_lock_init(&data->lock);
ret = iommu_device_sysfs_add(&data->iommu, &pdev->dev, NULL,
dev_name(data->sysmmu));
if (ret)
return ret;
iommu_device_set_ops(&data->iommu, &exynos_iommu_ops);
iommu_device_set_fwnode(&data->iommu, &dev->of_node->fwnode);
ret = iommu_device_register(&data->iommu);
if (ret)
return ret;
platform_set_drvdata(pdev, data);
__sysmmu_get_version(data);
if (PG_ENT_SHIFT < 0) {
if (MMU_MAJ_VER(data->version) < 5) {
PG_ENT_SHIFT = SYSMMU_PG_ENT_SHIFT;
LV1_PROT = SYSMMU_LV1_PROT;
LV2_PROT = SYSMMU_LV2_PROT;
} else {
PG_ENT_SHIFT = SYSMMU_V5_PG_ENT_SHIFT;
LV1_PROT = SYSMMU_V5_LV1_PROT;
LV2_PROT = SYSMMU_V5_LV2_PROT;
}
}
if (!dma_dev)
dma_dev = &pdev->dev;
pm_runtime_enable(dev);
return 0;
}
static int __maybe_unused exynos_sysmmu_suspend(struct device *dev)
{
struct sysmmu_drvdata *data = dev_get_drvdata(dev);
struct device *master = data->master;
if (master) {
struct exynos_iommu_owner *owner = master->archdata.iommu;
mutex_lock(&owner->rpm_lock);
if (data->domain) {
dev_dbg(data->sysmmu, "saving state\n");
__sysmmu_disable(data);
}
mutex_unlock(&owner->rpm_lock);
}
return 0;
}
static int __maybe_unused exynos_sysmmu_resume(struct device *dev)
{
struct sysmmu_drvdata *data = dev_get_drvdata(dev);
struct device *master = data->master;
if (master) {
struct exynos_iommu_owner *owner = master->archdata.iommu;
mutex_lock(&owner->rpm_lock);
if (data->domain) {
dev_dbg(data->sysmmu, "restoring state\n");
__sysmmu_enable(data);
}
mutex_unlock(&owner->rpm_lock);
}
return 0;
}
static inline void update_pte(sysmmu_pte_t *ent, sysmmu_pte_t val)
{
dma_sync_single_for_cpu(dma_dev, virt_to_phys(ent), sizeof(*ent),
DMA_TO_DEVICE);
*ent = cpu_to_le32(val);
dma_sync_single_for_device(dma_dev, virt_to_phys(ent), sizeof(*ent),
DMA_TO_DEVICE);
}
static struct iommu_domain *exynos_iommu_domain_alloc(unsigned type)
{
struct exynos_iommu_domain *domain;
dma_addr_t handle;
int i;
BUG_ON(PG_ENT_SHIFT < 0 || !dma_dev);
domain = kzalloc(sizeof(*domain), GFP_KERNEL);
if (!domain)
return NULL;
if (type == IOMMU_DOMAIN_DMA) {
if (iommu_get_dma_cookie(&domain->domain) != 0)
goto err_pgtable;
} else if (type != IOMMU_DOMAIN_UNMANAGED) {
goto err_pgtable;
}
domain->pgtable = (sysmmu_pte_t *)__get_free_pages(GFP_KERNEL, 2);
if (!domain->pgtable)
goto err_dma_cookie;
domain->lv2entcnt = (short *)__get_free_pages(GFP_KERNEL | __GFP_ZERO, 1);
if (!domain->lv2entcnt)
goto err_counter;
for (i = 0; i < NUM_LV1ENTRIES; i++)
domain->pgtable[i] = ZERO_LV2LINK;
handle = dma_map_single(dma_dev, domain->pgtable, LV1TABLE_SIZE,
DMA_TO_DEVICE);
BUG_ON(handle != virt_to_phys(domain->pgtable));
if (dma_mapping_error(dma_dev, handle))
goto err_lv2ent;
spin_lock_init(&domain->lock);
spin_lock_init(&domain->pgtablelock);
INIT_LIST_HEAD(&domain->clients);
domain->domain.geometry.aperture_start = 0;
domain->domain.geometry.aperture_end = ~0UL;
domain->domain.geometry.force_aperture = true;
return &domain->domain;
err_lv2ent:
free_pages((unsigned long)domain->lv2entcnt, 1);
err_counter:
free_pages((unsigned long)domain->pgtable, 2);
err_dma_cookie:
if (type == IOMMU_DOMAIN_DMA)
iommu_put_dma_cookie(&domain->domain);
err_pgtable:
kfree(domain);
return NULL;
}
static void exynos_iommu_domain_free(struct iommu_domain *iommu_domain)
{
struct exynos_iommu_domain *domain = to_exynos_domain(iommu_domain);
struct sysmmu_drvdata *data, *next;
unsigned long flags;
int i;
WARN_ON(!list_empty(&domain->clients));
spin_lock_irqsave(&domain->lock, flags);
list_for_each_entry_safe(data, next, &domain->clients, domain_node) {
spin_lock(&data->lock);
__sysmmu_disable(data);
data->pgtable = 0;
data->domain = NULL;
list_del_init(&data->domain_node);
spin_unlock(&data->lock);
}
spin_unlock_irqrestore(&domain->lock, flags);
if (iommu_domain->type == IOMMU_DOMAIN_DMA)
iommu_put_dma_cookie(iommu_domain);
dma_unmap_single(dma_dev, virt_to_phys(domain->pgtable), LV1TABLE_SIZE,
DMA_TO_DEVICE);
for (i = 0; i < NUM_LV1ENTRIES; i++)
if (lv1ent_page(domain->pgtable + i)) {
phys_addr_t base = lv2table_base(domain->pgtable + i);
dma_unmap_single(dma_dev, base, LV2TABLE_SIZE,
DMA_TO_DEVICE);
kmem_cache_free(lv2table_kmem_cache,
phys_to_virt(base));
}
free_pages((unsigned long)domain->pgtable, 2);
free_pages((unsigned long)domain->lv2entcnt, 1);
kfree(domain);
}
static void exynos_iommu_detach_device(struct iommu_domain *iommu_domain,
struct device *dev)
{
struct exynos_iommu_owner *owner = dev->archdata.iommu;
struct exynos_iommu_domain *domain = to_exynos_domain(iommu_domain);
phys_addr_t pagetable = virt_to_phys(domain->pgtable);
struct sysmmu_drvdata *data, *next;
unsigned long flags;
if (!has_sysmmu(dev) || owner->domain != iommu_domain)
return;
mutex_lock(&owner->rpm_lock);
list_for_each_entry(data, &owner->controllers, owner_node) {
pm_runtime_get_noresume(data->sysmmu);
if (pm_runtime_active(data->sysmmu))
__sysmmu_disable(data);
pm_runtime_put(data->sysmmu);
}
spin_lock_irqsave(&domain->lock, flags);
list_for_each_entry_safe(data, next, &domain->clients, domain_node) {
spin_lock(&data->lock);
data->pgtable = 0;
data->domain = NULL;
list_del_init(&data->domain_node);
spin_unlock(&data->lock);
}
owner->domain = NULL;
spin_unlock_irqrestore(&domain->lock, flags);
mutex_unlock(&owner->rpm_lock);
dev_dbg(dev, "%s: Detached IOMMU with pgtable %pa\n", __func__,
&pagetable);
}
static int exynos_iommu_attach_device(struct iommu_domain *iommu_domain,
struct device *dev)
{
struct exynos_iommu_owner *owner = dev->archdata.iommu;
struct exynos_iommu_domain *domain = to_exynos_domain(iommu_domain);
struct sysmmu_drvdata *data;
phys_addr_t pagetable = virt_to_phys(domain->pgtable);
unsigned long flags;
if (!has_sysmmu(dev))
return -ENODEV;
if (owner->domain)
exynos_iommu_detach_device(owner->domain, dev);
mutex_lock(&owner->rpm_lock);
spin_lock_irqsave(&domain->lock, flags);
list_for_each_entry(data, &owner->controllers, owner_node) {
spin_lock(&data->lock);
data->pgtable = pagetable;
data->domain = domain;
list_add_tail(&data->domain_node, &domain->clients);
spin_unlock(&data->lock);
}
owner->domain = iommu_domain;
spin_unlock_irqrestore(&domain->lock, flags);
list_for_each_entry(data, &owner->controllers, owner_node) {
pm_runtime_get_noresume(data->sysmmu);
if (pm_runtime_active(data->sysmmu))
__sysmmu_enable(data);
pm_runtime_put(data->sysmmu);
}
mutex_unlock(&owner->rpm_lock);
dev_dbg(dev, "%s: Attached IOMMU with pgtable %pa\n", __func__,
&pagetable);
return 0;
}
static sysmmu_pte_t *alloc_lv2entry(struct exynos_iommu_domain *domain,
sysmmu_pte_t *sent, sysmmu_iova_t iova, short *pgcounter)
{
if (lv1ent_section(sent)) {
WARN(1, "Trying mapping on %#08x mapped with 1MiB page", iova);
return ERR_PTR(-EADDRINUSE);
}
if (lv1ent_fault(sent)) {
dma_addr_t handle;
sysmmu_pte_t *pent;
bool need_flush_flpd_cache = lv1ent_zero(sent);
pent = kmem_cache_zalloc(lv2table_kmem_cache, GFP_ATOMIC);
BUG_ON((uintptr_t)pent & (LV2TABLE_SIZE - 1));
if (!pent)
return ERR_PTR(-ENOMEM);
update_pte(sent, mk_lv1ent_page(virt_to_phys(pent)));
kmemleak_ignore(pent);
*pgcounter = NUM_LV2ENTRIES;
handle = dma_map_single(dma_dev, pent, LV2TABLE_SIZE,
DMA_TO_DEVICE);
if (dma_mapping_error(dma_dev, handle)) {
kmem_cache_free(lv2table_kmem_cache, pent);
return ERR_PTR(-EADDRINUSE);
}
if (need_flush_flpd_cache) {
struct sysmmu_drvdata *data;
spin_lock(&domain->lock);
list_for_each_entry(data, &domain->clients, domain_node)
sysmmu_tlb_invalidate_flpdcache(data, iova);
spin_unlock(&domain->lock);
}
}
return page_entry(sent, iova);
}
static int lv1set_section(struct exynos_iommu_domain *domain,
sysmmu_pte_t *sent, sysmmu_iova_t iova,
phys_addr_t paddr, int prot, short *pgcnt)
{
if (lv1ent_section(sent)) {
WARN(1, "Trying mapping on 1MiB@%#08x that is mapped",
iova);
return -EADDRINUSE;
}
if (lv1ent_page(sent)) {
if (*pgcnt != NUM_LV2ENTRIES) {
WARN(1, "Trying mapping on 1MiB@%#08x that is mapped",
iova);
return -EADDRINUSE;
}
kmem_cache_free(lv2table_kmem_cache, page_entry(sent, 0));
*pgcnt = 0;
}
update_pte(sent, mk_lv1ent_sect(paddr, prot));
spin_lock(&domain->lock);
if (lv1ent_page_zero(sent)) {
struct sysmmu_drvdata *data;
list_for_each_entry(data, &domain->clients, domain_node)
sysmmu_tlb_invalidate_flpdcache(data, iova);
}
spin_unlock(&domain->lock);
return 0;
}
static int lv2set_page(sysmmu_pte_t *pent, phys_addr_t paddr, size_t size,
int prot, short *pgcnt)
{
if (size == SPAGE_SIZE) {
if (WARN_ON(!lv2ent_fault(pent)))
return -EADDRINUSE;
update_pte(pent, mk_lv2ent_spage(paddr, prot));
*pgcnt -= 1;
} else {
int i;
dma_addr_t pent_base = virt_to_phys(pent);
dma_sync_single_for_cpu(dma_dev, pent_base,
sizeof(*pent) * SPAGES_PER_LPAGE,
DMA_TO_DEVICE);
for (i = 0; i < SPAGES_PER_LPAGE; i++, pent++) {
if (WARN_ON(!lv2ent_fault(pent))) {
if (i > 0)
memset(pent - i, 0, sizeof(*pent) * i);
return -EADDRINUSE;
}
*pent = mk_lv2ent_lpage(paddr, prot);
}
dma_sync_single_for_device(dma_dev, pent_base,
sizeof(*pent) * SPAGES_PER_LPAGE,
DMA_TO_DEVICE);
*pgcnt -= SPAGES_PER_LPAGE;
}
return 0;
}
static int exynos_iommu_map(struct iommu_domain *iommu_domain,
unsigned long l_iova, phys_addr_t paddr, size_t size,
int prot)
{
struct exynos_iommu_domain *domain = to_exynos_domain(iommu_domain);
sysmmu_pte_t *entry;
sysmmu_iova_t iova = (sysmmu_iova_t)l_iova;
unsigned long flags;
int ret = -ENOMEM;
BUG_ON(domain->pgtable == NULL);
prot &= SYSMMU_SUPPORTED_PROT_BITS;
spin_lock_irqsave(&domain->pgtablelock, flags);
entry = section_entry(domain->pgtable, iova);
if (size == SECT_SIZE) {
ret = lv1set_section(domain, entry, iova, paddr, prot,
&domain->lv2entcnt[lv1ent_offset(iova)]);
} else {
sysmmu_pte_t *pent;
pent = alloc_lv2entry(domain, entry, iova,
&domain->lv2entcnt[lv1ent_offset(iova)]);
if (IS_ERR(pent))
ret = PTR_ERR(pent);
else
ret = lv2set_page(pent, paddr, size, prot,
&domain->lv2entcnt[lv1ent_offset(iova)]);
}
if (ret)
pr_err("%s: Failed(%d) to map %#zx bytes @ %#x\n",
__func__, ret, size, iova);
spin_unlock_irqrestore(&domain->pgtablelock, flags);
return ret;
}
static void exynos_iommu_tlb_invalidate_entry(struct exynos_iommu_domain *domain,
sysmmu_iova_t iova, size_t size)
{
struct sysmmu_drvdata *data;
unsigned long flags;
spin_lock_irqsave(&domain->lock, flags);
list_for_each_entry(data, &domain->clients, domain_node)
sysmmu_tlb_invalidate_entry(data, iova, size);
spin_unlock_irqrestore(&domain->lock, flags);
}
static size_t exynos_iommu_unmap(struct iommu_domain *iommu_domain,
unsigned long l_iova, size_t size)
{
struct exynos_iommu_domain *domain = to_exynos_domain(iommu_domain);
sysmmu_iova_t iova = (sysmmu_iova_t)l_iova;
sysmmu_pte_t *ent;
size_t err_pgsize;
unsigned long flags;
BUG_ON(domain->pgtable == NULL);
spin_lock_irqsave(&domain->pgtablelock, flags);
ent = section_entry(domain->pgtable, iova);
if (lv1ent_section(ent)) {
if (WARN_ON(size < SECT_SIZE)) {
err_pgsize = SECT_SIZE;
goto err;
}
update_pte(ent, ZERO_LV2LINK);
size = SECT_SIZE;
goto done;
}
if (unlikely(lv1ent_fault(ent))) {
if (size > SECT_SIZE)
size = SECT_SIZE;
goto done;
}
ent = page_entry(ent, iova);
if (unlikely(lv2ent_fault(ent))) {
size = SPAGE_SIZE;
goto done;
}
if (lv2ent_small(ent)) {
update_pte(ent, 0);
size = SPAGE_SIZE;
domain->lv2entcnt[lv1ent_offset(iova)] += 1;
goto done;
}
if (WARN_ON(size < LPAGE_SIZE)) {
err_pgsize = LPAGE_SIZE;
goto err;
}
dma_sync_single_for_cpu(dma_dev, virt_to_phys(ent),
sizeof(*ent) * SPAGES_PER_LPAGE,
DMA_TO_DEVICE);
memset(ent, 0, sizeof(*ent) * SPAGES_PER_LPAGE);
dma_sync_single_for_device(dma_dev, virt_to_phys(ent),
sizeof(*ent) * SPAGES_PER_LPAGE,
DMA_TO_DEVICE);
size = LPAGE_SIZE;
domain->lv2entcnt[lv1ent_offset(iova)] += SPAGES_PER_LPAGE;
done:
spin_unlock_irqrestore(&domain->pgtablelock, flags);
exynos_iommu_tlb_invalidate_entry(domain, iova, size);
return size;
err:
spin_unlock_irqrestore(&domain->pgtablelock, flags);
pr_err("%s: Failed: size(%#zx) @ %#x is smaller than page size %#zx\n",
__func__, size, iova, err_pgsize);
return 0;
}
static phys_addr_t exynos_iommu_iova_to_phys(struct iommu_domain *iommu_domain,
dma_addr_t iova)
{
struct exynos_iommu_domain *domain = to_exynos_domain(iommu_domain);
sysmmu_pte_t *entry;
unsigned long flags;
phys_addr_t phys = 0;
spin_lock_irqsave(&domain->pgtablelock, flags);
entry = section_entry(domain->pgtable, iova);
if (lv1ent_section(entry)) {
phys = section_phys(entry) + section_offs(iova);
} else if (lv1ent_page(entry)) {
entry = page_entry(entry, iova);
if (lv2ent_large(entry))
phys = lpage_phys(entry) + lpage_offs(iova);
else if (lv2ent_small(entry))
phys = spage_phys(entry) + spage_offs(iova);
}
spin_unlock_irqrestore(&domain->pgtablelock, flags);
return phys;
}
static struct iommu_group *get_device_iommu_group(struct device *dev)
{
struct iommu_group *group;
group = iommu_group_get(dev);
if (!group)
group = iommu_group_alloc();
return group;
}
static int exynos_iommu_add_device(struct device *dev)
{
struct iommu_group *group;
if (!has_sysmmu(dev))
return -ENODEV;
group = iommu_group_get_for_dev(dev);
if (IS_ERR(group))
return PTR_ERR(group);
iommu_group_put(group);
return 0;
}
static void exynos_iommu_remove_device(struct device *dev)
{
struct exynos_iommu_owner *owner = dev->archdata.iommu;
if (!has_sysmmu(dev))
return;
if (owner->domain) {
struct iommu_group *group = iommu_group_get(dev);
if (group) {
WARN_ON(owner->domain !=
iommu_group_default_domain(group));
exynos_iommu_detach_device(owner->domain, dev);
iommu_group_put(group);
}
}
iommu_group_remove_device(dev);
}
static int exynos_iommu_of_xlate(struct device *dev,
struct of_phandle_args *spec)
{
struct exynos_iommu_owner *owner = dev->archdata.iommu;
struct platform_device *sysmmu = of_find_device_by_node(spec->np);
struct sysmmu_drvdata *data, *entry;
if (!sysmmu)
return -ENODEV;
data = platform_get_drvdata(sysmmu);
if (!data)
return -ENODEV;
if (!owner) {
owner = kzalloc(sizeof(*owner), GFP_KERNEL);
if (!owner)
return -ENOMEM;
INIT_LIST_HEAD(&owner->controllers);
mutex_init(&owner->rpm_lock);
dev->archdata.iommu = owner;
}
list_for_each_entry(entry, &owner->controllers, owner_node)
if (entry == data)
return 0;
list_add_tail(&data->owner_node, &owner->controllers);
data->master = dev;
device_link_add(dev, data->sysmmu, DL_FLAG_PM_RUNTIME);
return 0;
}
static int __init exynos_iommu_init(void)
{
int ret;
lv2table_kmem_cache = kmem_cache_create("exynos-iommu-lv2table",
LV2TABLE_SIZE, LV2TABLE_SIZE, 0, NULL);
if (!lv2table_kmem_cache) {
pr_err("%s: Failed to create kmem cache\n", __func__);
return -ENOMEM;
}
ret = platform_driver_register(&exynos_sysmmu_driver);
if (ret) {
pr_err("%s: Failed to register driver\n", __func__);
goto err_reg_driver;
}
zero_lv2_table = kmem_cache_zalloc(lv2table_kmem_cache, GFP_KERNEL);
if (zero_lv2_table == NULL) {
pr_err("%s: Failed to allocate zero level2 page table\n",
__func__);
ret = -ENOMEM;
goto err_zero_lv2;
}
ret = bus_set_iommu(&platform_bus_type, &exynos_iommu_ops);
if (ret) {
pr_err("%s: Failed to register exynos-iommu driver.\n",
__func__);
goto err_set_iommu;
}
return 0;
err_set_iommu:
kmem_cache_free(lv2table_kmem_cache, zero_lv2_table);
err_zero_lv2:
platform_driver_unregister(&exynos_sysmmu_driver);
err_reg_driver:
kmem_cache_destroy(lv2table_kmem_cache);
return ret;
}
