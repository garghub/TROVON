static inline void gart_set_pte(struct gart_device *gart,
unsigned long offs, u32 pte)
{
writel(offs, gart->regs + GART_ENTRY_ADDR);
writel(pte, gart->regs + GART_ENTRY_DATA);
dev_dbg(gart->dev, "%s %08lx:%08x\n",
pte ? "map" : "unmap", offs, pte & GART_PAGE_MASK);
}
static inline unsigned long gart_read_pte(struct gart_device *gart,
unsigned long offs)
{
unsigned long pte;
writel(offs, gart->regs + GART_ENTRY_ADDR);
pte = readl(gart->regs + GART_ENTRY_DATA);
return pte;
}
static void do_gart_setup(struct gart_device *gart, const u32 *data)
{
unsigned long iova;
for_each_gart_pte(gart, iova)
gart_set_pte(gart, iova, data ? *(data++) : 0);
writel(1, gart->regs + GART_CONFIG);
FLUSH_GART_REGS(gart);
}
static void gart_dump_table(struct gart_device *gart)
{
unsigned long iova;
unsigned long flags;
spin_lock_irqsave(&gart->pte_lock, flags);
for_each_gart_pte(gart, iova) {
unsigned long pte;
pte = gart_read_pte(gart, iova);
dev_dbg(gart->dev, "%s %08lx:%08lx\n",
(GART_ENTRY_PHYS_ADDR_VALID & pte) ? "v" : " ",
iova, pte & GART_PAGE_MASK);
}
spin_unlock_irqrestore(&gart->pte_lock, flags);
}
static inline void gart_dump_table(struct gart_device *gart)
{
}
static inline bool gart_iova_range_valid(struct gart_device *gart,
unsigned long iova, size_t bytes)
{
unsigned long iova_start, iova_end, gart_start, gart_end;
iova_start = iova;
iova_end = iova_start + bytes - 1;
gart_start = gart->iovmm_base;
gart_end = gart_start + gart->page_count * GART_PAGE_SIZE - 1;
if (iova_start < gart_start)
return false;
if (iova_end > gart_end)
return false;
return true;
}
static int gart_iommu_attach_dev(struct iommu_domain *domain,
struct device *dev)
{
struct gart_device *gart;
struct gart_client *client, *c;
int err = 0;
gart = gart_handle;
if (!gart)
return -EINVAL;
domain->priv = gart;
domain->geometry.aperture_start = gart->iovmm_base;
domain->geometry.aperture_end = gart->iovmm_base +
gart->page_count * GART_PAGE_SIZE - 1;
domain->geometry.force_aperture = true;
client = devm_kzalloc(gart->dev, sizeof(*c), GFP_KERNEL);
if (!client)
return -ENOMEM;
client->dev = dev;
spin_lock(&gart->client_lock);
list_for_each_entry(c, &gart->client, list) {
if (c->dev == dev) {
dev_err(gart->dev,
"%s is already attached\n", dev_name(dev));
err = -EINVAL;
goto fail;
}
}
list_add(&client->list, &gart->client);
spin_unlock(&gart->client_lock);
dev_dbg(gart->dev, "Attached %s\n", dev_name(dev));
return 0;
fail:
devm_kfree(gart->dev, client);
spin_unlock(&gart->client_lock);
return err;
}
static void gart_iommu_detach_dev(struct iommu_domain *domain,
struct device *dev)
{
struct gart_device *gart = domain->priv;
struct gart_client *c;
spin_lock(&gart->client_lock);
list_for_each_entry(c, &gart->client, list) {
if (c->dev == dev) {
list_del(&c->list);
devm_kfree(gart->dev, c);
dev_dbg(gart->dev, "Detached %s\n", dev_name(dev));
goto out;
}
}
dev_err(gart->dev, "Couldn't find\n");
out:
spin_unlock(&gart->client_lock);
}
static int gart_iommu_domain_init(struct iommu_domain *domain)
{
return 0;
}
static void gart_iommu_domain_destroy(struct iommu_domain *domain)
{
struct gart_device *gart = domain->priv;
if (!gart)
return;
spin_lock(&gart->client_lock);
if (!list_empty(&gart->client)) {
struct gart_client *c;
list_for_each_entry(c, &gart->client, list)
gart_iommu_detach_dev(domain, c->dev);
}
spin_unlock(&gart->client_lock);
domain->priv = NULL;
}
static int gart_iommu_map(struct iommu_domain *domain, unsigned long iova,
phys_addr_t pa, size_t bytes, int prot)
{
struct gart_device *gart = domain->priv;
unsigned long flags;
unsigned long pfn;
if (!gart_iova_range_valid(gart, iova, bytes))
return -EINVAL;
spin_lock_irqsave(&gart->pte_lock, flags);
pfn = __phys_to_pfn(pa);
if (!pfn_valid(pfn)) {
dev_err(gart->dev, "Invalid page: %08x\n", pa);
spin_unlock_irqrestore(&gart->pte_lock, flags);
return -EINVAL;
}
gart_set_pte(gart, iova, GART_PTE(pfn));
FLUSH_GART_REGS(gart);
spin_unlock_irqrestore(&gart->pte_lock, flags);
return 0;
}
static size_t gart_iommu_unmap(struct iommu_domain *domain, unsigned long iova,
size_t bytes)
{
struct gart_device *gart = domain->priv;
unsigned long flags;
if (!gart_iova_range_valid(gart, iova, bytes))
return 0;
spin_lock_irqsave(&gart->pte_lock, flags);
gart_set_pte(gart, iova, 0);
FLUSH_GART_REGS(gart);
spin_unlock_irqrestore(&gart->pte_lock, flags);
return 0;
}
static phys_addr_t gart_iommu_iova_to_phys(struct iommu_domain *domain,
dma_addr_t iova)
{
struct gart_device *gart = domain->priv;
unsigned long pte;
phys_addr_t pa;
unsigned long flags;
if (!gart_iova_range_valid(gart, iova, 0))
return -EINVAL;
spin_lock_irqsave(&gart->pte_lock, flags);
pte = gart_read_pte(gart, iova);
spin_unlock_irqrestore(&gart->pte_lock, flags);
pa = (pte & GART_PAGE_MASK);
if (!pfn_valid(__phys_to_pfn(pa))) {
dev_err(gart->dev, "No entry for %08llx:%08x\n",
(unsigned long long)iova, pa);
gart_dump_table(gart);
return -EINVAL;
}
return pa;
}
static int gart_iommu_domain_has_cap(struct iommu_domain *domain,
unsigned long cap)
{
return 0;
}
static int tegra_gart_suspend(struct device *dev)
{
struct gart_device *gart = dev_get_drvdata(dev);
unsigned long iova;
u32 *data = gart->savedata;
unsigned long flags;
spin_lock_irqsave(&gart->pte_lock, flags);
for_each_gart_pte(gart, iova)
*(data++) = gart_read_pte(gart, iova);
spin_unlock_irqrestore(&gart->pte_lock, flags);
return 0;
}
static int tegra_gart_resume(struct device *dev)
{
struct gart_device *gart = dev_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&gart->pte_lock, flags);
do_gart_setup(gart, gart->savedata);
spin_unlock_irqrestore(&gart->pte_lock, flags);
return 0;
}
static int tegra_gart_probe(struct platform_device *pdev)
{
struct gart_device *gart;
struct resource *res, *res_remap;
void __iomem *gart_regs;
int err;
struct device *dev = &pdev->dev;
if (gart_handle)
return -EIO;
BUILD_BUG_ON(PAGE_SHIFT != GART_PAGE_SHIFT);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
res_remap = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!res || !res_remap) {
dev_err(dev, "GART memory aperture expected\n");
return -ENXIO;
}
gart = devm_kzalloc(dev, sizeof(*gart), GFP_KERNEL);
if (!gart) {
dev_err(dev, "failed to allocate gart_device\n");
return -ENOMEM;
}
gart_regs = devm_ioremap(dev, res->start, resource_size(res));
if (!gart_regs) {
dev_err(dev, "failed to remap GART registers\n");
err = -ENXIO;
goto fail;
}
gart->dev = &pdev->dev;
spin_lock_init(&gart->pte_lock);
spin_lock_init(&gart->client_lock);
INIT_LIST_HEAD(&gart->client);
gart->regs = gart_regs;
gart->iovmm_base = (dma_addr_t)res_remap->start;
gart->page_count = (resource_size(res_remap) >> GART_PAGE_SHIFT);
gart->savedata = vmalloc(sizeof(u32) * gart->page_count);
if (!gart->savedata) {
dev_err(dev, "failed to allocate context save area\n");
err = -ENOMEM;
goto fail;
}
platform_set_drvdata(pdev, gart);
do_gart_setup(gart, NULL);
gart_handle = gart;
bus_set_iommu(&platform_bus_type, &gart_iommu_ops);
return 0;
fail:
if (gart_regs)
devm_iounmap(dev, gart_regs);
if (gart && gart->savedata)
vfree(gart->savedata);
devm_kfree(dev, gart);
return err;
}
static int tegra_gart_remove(struct platform_device *pdev)
{
struct gart_device *gart = platform_get_drvdata(pdev);
struct device *dev = gart->dev;
writel(0, gart->regs + GART_CONFIG);
if (gart->savedata)
vfree(gart->savedata);
if (gart->regs)
devm_iounmap(dev, gart->regs);
devm_kfree(dev, gart);
gart_handle = NULL;
return 0;
}
static int tegra_gart_init(void)
{
return platform_driver_register(&tegra_gart_driver);
}
static void __exit tegra_gart_exit(void)
{
platform_driver_unregister(&tegra_gart_driver);
}
