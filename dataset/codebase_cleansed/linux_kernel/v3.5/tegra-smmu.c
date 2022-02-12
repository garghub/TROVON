static inline u32 smmu_read(struct smmu_device *smmu, size_t offs)
{
return readl(smmu->regs + offs);
}
static inline void smmu_write(struct smmu_device *smmu, u32 val, size_t offs)
{
writel(val, smmu->regs + offs);
}
static inline u32 ahb_read(struct smmu_device *smmu, size_t offs)
{
return readl(smmu->regs_ahbarb + offs);
}
static inline void ahb_write(struct smmu_device *smmu, u32 val, size_t offs)
{
writel(val, smmu->regs_ahbarb + offs);
}
static int __smmu_client_set_hwgrp(struct smmu_client *c,
unsigned long map, int on)
{
int i;
struct smmu_as *as = c->as;
u32 val, offs, mask = SMMU_ASID_ENABLE(as->asid);
struct smmu_device *smmu = as->smmu;
WARN_ON(!on && map);
if (on && !map)
return -EINVAL;
if (!on)
map = smmu_client_hwgrp(c);
for_each_set_bit(i, &map, HWGRP_COUNT) {
offs = HWGRP_ASID_REG(i);
val = smmu_read(smmu, offs);
if (on) {
if (WARN_ON(val & mask))
goto err_hw_busy;
val |= mask;
} else {
WARN_ON((val & mask) == mask);
val &= ~mask;
}
smmu_write(smmu, val, offs);
}
FLUSH_SMMU_REGS(smmu);
c->hwgrp = map;
return 0;
err_hw_busy:
for_each_set_bit(i, &map, HWGRP_COUNT) {
offs = HWGRP_ASID_REG(i);
val = smmu_read(smmu, offs);
val &= ~mask;
smmu_write(smmu, val, offs);
}
return -EBUSY;
}
static int smmu_client_set_hwgrp(struct smmu_client *c, u32 map, int on)
{
u32 val;
unsigned long flags;
struct smmu_as *as = c->as;
struct smmu_device *smmu = as->smmu;
spin_lock_irqsave(&smmu->lock, flags);
val = __smmu_client_set_hwgrp(c, map, on);
spin_unlock_irqrestore(&smmu->lock, flags);
return val;
}
static void smmu_flush_regs(struct smmu_device *smmu, int enable)
{
u32 val;
smmu_write(smmu, SMMU_PTC_FLUSH_TYPE_ALL, SMMU_PTC_FLUSH);
FLUSH_SMMU_REGS(smmu);
val = SMMU_TLB_FLUSH_VA_MATCH_ALL |
SMMU_TLB_FLUSH_ASID_MATCH_disable;
smmu_write(smmu, val, SMMU_TLB_FLUSH);
if (enable)
smmu_write(smmu, SMMU_CONFIG_ENABLE, SMMU_CONFIG);
FLUSH_SMMU_REGS(smmu);
}
static void smmu_setup_regs(struct smmu_device *smmu)
{
int i;
u32 val;
for (i = 0; i < smmu->num_as; i++) {
struct smmu_as *as = &smmu->as[i];
struct smmu_client *c;
smmu_write(smmu, SMMU_PTB_ASID_CUR(as->asid), SMMU_PTB_ASID);
val = as->pdir_page ?
SMMU_MK_PDIR(as->pdir_page, as->pdir_attr) :
SMMU_PTB_DATA_RESET_VAL;
smmu_write(smmu, val, SMMU_PTB_DATA);
list_for_each_entry(c, &as->client, list)
__smmu_client_set_hwgrp(c, c->hwgrp, 1);
}
smmu_write(smmu, smmu->translation_enable_0, SMMU_TRANSLATION_ENABLE_0);
smmu_write(smmu, smmu->translation_enable_1, SMMU_TRANSLATION_ENABLE_1);
smmu_write(smmu, smmu->translation_enable_2, SMMU_TRANSLATION_ENABLE_2);
smmu_write(smmu, smmu->asid_security, SMMU_ASID_SECURITY);
smmu_write(smmu, SMMU_TLB_CONFIG_RESET_VAL, SMMU_TLB_CONFIG);
smmu_write(smmu, SMMU_PTC_CONFIG_RESET_VAL, SMMU_PTC_CONFIG);
smmu_flush_regs(smmu, 1);
val = ahb_read(smmu, AHB_XBAR_CTRL);
val |= AHB_XBAR_CTRL_SMMU_INIT_DONE_DONE <<
AHB_XBAR_CTRL_SMMU_INIT_DONE_SHIFT;
ahb_write(smmu, val, AHB_XBAR_CTRL);
}
static void flush_ptc_and_tlb(struct smmu_device *smmu,
struct smmu_as *as, dma_addr_t iova,
unsigned long *pte, struct page *page, int is_pde)
{
u32 val;
unsigned long tlb_flush_va = is_pde
? SMMU_TLB_FLUSH_VA(iova, SECTION)
: SMMU_TLB_FLUSH_VA(iova, GROUP);
val = SMMU_PTC_FLUSH_TYPE_ADR | VA_PAGE_TO_PA(pte, page);
smmu_write(smmu, val, SMMU_PTC_FLUSH);
FLUSH_SMMU_REGS(smmu);
val = tlb_flush_va |
SMMU_TLB_FLUSH_ASID_MATCH__ENABLE |
(as->asid << SMMU_TLB_FLUSH_ASID_SHIFT);
smmu_write(smmu, val, SMMU_TLB_FLUSH);
FLUSH_SMMU_REGS(smmu);
}
static void free_ptbl(struct smmu_as *as, dma_addr_t iova)
{
unsigned long pdn = SMMU_ADDR_TO_PDN(iova);
unsigned long *pdir = (unsigned long *)page_address(as->pdir_page);
if (pdir[pdn] != _PDE_VACANT(pdn)) {
dev_dbg(as->smmu->dev, "pdn: %lx\n", pdn);
ClearPageReserved(SMMU_EX_PTBL_PAGE(pdir[pdn]));
__free_page(SMMU_EX_PTBL_PAGE(pdir[pdn]));
pdir[pdn] = _PDE_VACANT(pdn);
FLUSH_CPU_DCACHE(&pdir[pdn], as->pdir_page, sizeof pdir[pdn]);
flush_ptc_and_tlb(as->smmu, as, iova, &pdir[pdn],
as->pdir_page, 1);
}
}
static void free_pdir(struct smmu_as *as)
{
unsigned addr;
int count;
struct device *dev = as->smmu->dev;
if (!as->pdir_page)
return;
addr = as->smmu->iovmm_base;
count = as->smmu->page_count;
while (count-- > 0) {
free_ptbl(as, addr);
addr += SMMU_PAGE_SIZE * SMMU_PTBL_COUNT;
}
ClearPageReserved(as->pdir_page);
__free_page(as->pdir_page);
as->pdir_page = NULL;
devm_kfree(dev, as->pte_count);
as->pte_count = NULL;
}
static unsigned long *locate_pte(struct smmu_as *as,
dma_addr_t iova, bool allocate,
struct page **ptbl_page_p,
unsigned int **count)
{
unsigned long ptn = SMMU_ADDR_TO_PFN(iova);
unsigned long pdn = SMMU_ADDR_TO_PDN(iova);
unsigned long *pdir = page_address(as->pdir_page);
unsigned long *ptbl;
if (pdir[pdn] != _PDE_VACANT(pdn)) {
*ptbl_page_p = SMMU_EX_PTBL_PAGE(pdir[pdn]);
ptbl = page_address(*ptbl_page_p);
} else if (!allocate) {
return NULL;
} else {
int pn;
unsigned long addr = SMMU_PDN_TO_ADDR(pdn);
dev_dbg(as->smmu->dev, "New PTBL pdn: %lx\n", pdn);
*ptbl_page_p = alloc_page(GFP_ATOMIC);
if (!*ptbl_page_p) {
dev_err(as->smmu->dev,
"failed to allocate smmu_device page table\n");
return NULL;
}
SetPageReserved(*ptbl_page_p);
ptbl = (unsigned long *)page_address(*ptbl_page_p);
for (pn = 0; pn < SMMU_PTBL_COUNT;
pn++, addr += SMMU_PAGE_SIZE) {
ptbl[pn] = _PTE_VACANT(addr);
}
FLUSH_CPU_DCACHE(ptbl, *ptbl_page_p, SMMU_PTBL_SIZE);
pdir[pdn] = SMMU_MK_PDE(*ptbl_page_p,
as->pde_attr | _PDE_NEXT);
FLUSH_CPU_DCACHE(&pdir[pdn], as->pdir_page, sizeof pdir[pdn]);
flush_ptc_and_tlb(as->smmu, as, iova, &pdir[pdn],
as->pdir_page, 1);
}
*count = &as->pte_count[pdn];
return &ptbl[ptn % SMMU_PTBL_COUNT];
}
static void put_signature(struct smmu_as *as,
dma_addr_t iova, unsigned long pfn)
{
struct page *page;
unsigned long *vaddr;
page = pfn_to_page(pfn);
vaddr = page_address(page);
if (!vaddr)
return;
vaddr[0] = iova;
vaddr[1] = pfn << PAGE_SHIFT;
FLUSH_CPU_DCACHE(vaddr, page, sizeof(vaddr[0]) * 2);
}
static inline void put_signature(struct smmu_as *as,
unsigned long addr, unsigned long pfn)
{
}
static int alloc_pdir(struct smmu_as *as)
{
unsigned long *pdir;
int pdn;
u32 val;
struct smmu_device *smmu = as->smmu;
if (as->pdir_page)
return 0;
as->pte_count = devm_kzalloc(smmu->dev,
sizeof(as->pte_count[0]) * SMMU_PDIR_COUNT, GFP_ATOMIC);
if (!as->pte_count) {
dev_err(smmu->dev,
"failed to allocate smmu_device PTE cunters\n");
return -ENOMEM;
}
as->pdir_page = alloc_page(GFP_ATOMIC | __GFP_DMA);
if (!as->pdir_page) {
dev_err(smmu->dev,
"failed to allocate smmu_device page directory\n");
devm_kfree(smmu->dev, as->pte_count);
as->pte_count = NULL;
return -ENOMEM;
}
SetPageReserved(as->pdir_page);
pdir = page_address(as->pdir_page);
for (pdn = 0; pdn < SMMU_PDIR_COUNT; pdn++)
pdir[pdn] = _PDE_VACANT(pdn);
FLUSH_CPU_DCACHE(pdir, as->pdir_page, SMMU_PDIR_SIZE);
val = SMMU_PTC_FLUSH_TYPE_ADR | VA_PAGE_TO_PA(pdir, as->pdir_page);
smmu_write(smmu, val, SMMU_PTC_FLUSH);
FLUSH_SMMU_REGS(as->smmu);
val = SMMU_TLB_FLUSH_VA_MATCH_ALL |
SMMU_TLB_FLUSH_ASID_MATCH__ENABLE |
(as->asid << SMMU_TLB_FLUSH_ASID_SHIFT);
smmu_write(smmu, val, SMMU_TLB_FLUSH);
FLUSH_SMMU_REGS(as->smmu);
return 0;
}
static void __smmu_iommu_unmap(struct smmu_as *as, dma_addr_t iova)
{
unsigned long *pte;
struct page *page;
unsigned int *count;
pte = locate_pte(as, iova, false, &page, &count);
if (WARN_ON(!pte))
return;
if (WARN_ON(*pte == _PTE_VACANT(iova)))
return;
*pte = _PTE_VACANT(iova);
FLUSH_CPU_DCACHE(pte, page, sizeof(*pte));
flush_ptc_and_tlb(as->smmu, as, iova, pte, page, 0);
if (!--(*count)) {
free_ptbl(as, iova);
smmu_flush_regs(as->smmu, 0);
}
}
static void __smmu_iommu_map_pfn(struct smmu_as *as, dma_addr_t iova,
unsigned long pfn)
{
struct smmu_device *smmu = as->smmu;
unsigned long *pte;
unsigned int *count;
struct page *page;
pte = locate_pte(as, iova, true, &page, &count);
if (WARN_ON(!pte))
return;
if (*pte == _PTE_VACANT(iova))
(*count)++;
*pte = SMMU_PFN_TO_PTE(pfn, as->pte_attr);
if (unlikely((*pte == _PTE_VACANT(iova))))
(*count)--;
FLUSH_CPU_DCACHE(pte, page, sizeof(*pte));
flush_ptc_and_tlb(smmu, as, iova, pte, page, 0);
put_signature(as, iova, pfn);
}
static int smmu_iommu_map(struct iommu_domain *domain, unsigned long iova,
phys_addr_t pa, size_t bytes, int prot)
{
struct smmu_as *as = domain->priv;
unsigned long pfn = __phys_to_pfn(pa);
unsigned long flags;
dev_dbg(as->smmu->dev, "[%d] %08lx:%08x\n", as->asid, iova, pa);
if (!pfn_valid(pfn))
return -ENOMEM;
spin_lock_irqsave(&as->lock, flags);
__smmu_iommu_map_pfn(as, iova, pfn);
spin_unlock_irqrestore(&as->lock, flags);
return 0;
}
static size_t smmu_iommu_unmap(struct iommu_domain *domain, unsigned long iova,
size_t bytes)
{
struct smmu_as *as = domain->priv;
unsigned long flags;
dev_dbg(as->smmu->dev, "[%d] %08lx\n", as->asid, iova);
spin_lock_irqsave(&as->lock, flags);
__smmu_iommu_unmap(as, iova);
spin_unlock_irqrestore(&as->lock, flags);
return SMMU_PAGE_SIZE;
}
static phys_addr_t smmu_iommu_iova_to_phys(struct iommu_domain *domain,
unsigned long iova)
{
struct smmu_as *as = domain->priv;
unsigned long *pte;
unsigned int *count;
struct page *page;
unsigned long pfn;
unsigned long flags;
spin_lock_irqsave(&as->lock, flags);
pte = locate_pte(as, iova, true, &page, &count);
pfn = *pte & SMMU_PFN_MASK;
WARN_ON(!pfn_valid(pfn));
dev_dbg(as->smmu->dev,
"iova:%08lx pfn:%08lx asid:%d\n", iova, pfn, as->asid);
spin_unlock_irqrestore(&as->lock, flags);
return PFN_PHYS(pfn);
}
static int smmu_iommu_domain_has_cap(struct iommu_domain *domain,
unsigned long cap)
{
return 0;
}
static int smmu_iommu_attach_dev(struct iommu_domain *domain,
struct device *dev)
{
struct smmu_as *as = domain->priv;
struct smmu_device *smmu = as->smmu;
struct smmu_client *client, *c;
u32 map;
int err;
client = devm_kzalloc(smmu->dev, sizeof(*c), GFP_KERNEL);
if (!client)
return -ENOMEM;
client->dev = dev;
client->as = as;
map = (unsigned long)dev->platform_data;
if (!map)
return -EINVAL;
err = smmu_client_enable_hwgrp(client, map);
if (err)
goto err_hwgrp;
spin_lock(&as->client_lock);
list_for_each_entry(c, &as->client, list) {
if (c->dev == dev) {
dev_err(smmu->dev,
"%s is already attached\n", dev_name(c->dev));
err = -EINVAL;
goto err_client;
}
}
list_add(&client->list, &as->client);
spin_unlock(&as->client_lock);
if (map & HWG_AVPC) {
struct page *page;
page = as->smmu->avp_vector_page;
__smmu_iommu_map_pfn(as, 0, page_to_pfn(page));
pr_info("Reserve \"page zero\" for AVP vectors using a common dummy\n");
}
dev_dbg(smmu->dev, "%s is attached\n", dev_name(dev));
return 0;
err_client:
smmu_client_disable_hwgrp(client);
spin_unlock(&as->client_lock);
err_hwgrp:
devm_kfree(smmu->dev, client);
return err;
}
static void smmu_iommu_detach_dev(struct iommu_domain *domain,
struct device *dev)
{
struct smmu_as *as = domain->priv;
struct smmu_device *smmu = as->smmu;
struct smmu_client *c;
spin_lock(&as->client_lock);
list_for_each_entry(c, &as->client, list) {
if (c->dev == dev) {
smmu_client_disable_hwgrp(c);
list_del(&c->list);
devm_kfree(smmu->dev, c);
c->as = NULL;
dev_dbg(smmu->dev,
"%s is detached\n", dev_name(c->dev));
goto out;
}
}
dev_err(smmu->dev, "Couldn't find %s\n", dev_name(c->dev));
out:
spin_unlock(&as->client_lock);
}
static int smmu_iommu_domain_init(struct iommu_domain *domain)
{
int i;
unsigned long flags;
struct smmu_as *as;
struct smmu_device *smmu = smmu_handle;
for (i = 0; i < smmu->num_as; i++) {
struct smmu_as *tmp = &smmu->as[i];
spin_lock_irqsave(&tmp->lock, flags);
if (!tmp->pdir_page) {
as = tmp;
goto found;
}
spin_unlock_irqrestore(&tmp->lock, flags);
}
dev_err(smmu->dev, "no free AS\n");
return -ENODEV;
found:
if (alloc_pdir(as) < 0)
goto err_alloc_pdir;
spin_lock(&smmu->lock);
smmu_write(smmu, SMMU_PTB_ASID_CUR(as->asid), SMMU_PTB_ASID);
smmu_write(smmu,
SMMU_MK_PDIR(as->pdir_page, as->pdir_attr), SMMU_PTB_DATA);
FLUSH_SMMU_REGS(smmu);
spin_unlock(&smmu->lock);
spin_unlock_irqrestore(&as->lock, flags);
domain->priv = as;
dev_dbg(smmu->dev, "smmu_as@%p\n", as);
return 0;
err_alloc_pdir:
spin_unlock_irqrestore(&as->lock, flags);
return -ENODEV;
}
static void smmu_iommu_domain_destroy(struct iommu_domain *domain)
{
struct smmu_as *as = domain->priv;
struct smmu_device *smmu = as->smmu;
unsigned long flags;
spin_lock_irqsave(&as->lock, flags);
if (as->pdir_page) {
spin_lock(&smmu->lock);
smmu_write(smmu, SMMU_PTB_ASID_CUR(as->asid), SMMU_PTB_ASID);
smmu_write(smmu, SMMU_PTB_DATA_RESET_VAL, SMMU_PTB_DATA);
FLUSH_SMMU_REGS(smmu);
spin_unlock(&smmu->lock);
free_pdir(as);
}
if (!list_empty(&as->client)) {
struct smmu_client *c;
list_for_each_entry(c, &as->client, list)
smmu_iommu_detach_dev(domain, c->dev);
}
spin_unlock_irqrestore(&as->lock, flags);
domain->priv = NULL;
dev_dbg(smmu->dev, "smmu_as@%p\n", as);
}
static int tegra_smmu_suspend(struct device *dev)
{
struct smmu_device *smmu = dev_get_drvdata(dev);
smmu->translation_enable_0 = smmu_read(smmu, SMMU_TRANSLATION_ENABLE_0);
smmu->translation_enable_1 = smmu_read(smmu, SMMU_TRANSLATION_ENABLE_1);
smmu->translation_enable_2 = smmu_read(smmu, SMMU_TRANSLATION_ENABLE_2);
smmu->asid_security = smmu_read(smmu, SMMU_ASID_SECURITY);
return 0;
}
static int tegra_smmu_resume(struct device *dev)
{
struct smmu_device *smmu = dev_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&smmu->lock, flags);
smmu_setup_regs(smmu);
spin_unlock_irqrestore(&smmu->lock, flags);
return 0;
}
static int tegra_smmu_probe(struct platform_device *pdev)
{
struct smmu_device *smmu;
struct resource *regs, *regs2, *window;
struct device *dev = &pdev->dev;
int i, err = 0;
if (smmu_handle)
return -EIO;
BUILD_BUG_ON(PAGE_SHIFT != SMMU_PAGE_SHIFT);
regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
regs2 = platform_get_resource(pdev, IORESOURCE_MEM, 1);
window = platform_get_resource(pdev, IORESOURCE_MEM, 2);
if (!regs || !regs2 || !window) {
dev_err(dev, "No SMMU resources\n");
return -ENODEV;
}
smmu = devm_kzalloc(dev, sizeof(*smmu), GFP_KERNEL);
if (!smmu) {
dev_err(dev, "failed to allocate smmu_device\n");
return -ENOMEM;
}
smmu->dev = dev;
smmu->num_as = SMMU_NUM_ASIDS;
smmu->iovmm_base = (unsigned long)window->start;
smmu->page_count = resource_size(window) >> SMMU_PAGE_SHIFT;
smmu->regs = devm_ioremap(dev, regs->start, resource_size(regs));
smmu->regs_ahbarb = devm_ioremap(dev, regs2->start,
resource_size(regs2));
if (!smmu->regs || !smmu->regs_ahbarb) {
dev_err(dev, "failed to remap SMMU registers\n");
err = -ENXIO;
goto fail;
}
smmu->translation_enable_0 = ~0;
smmu->translation_enable_1 = ~0;
smmu->translation_enable_2 = ~0;
smmu->asid_security = 0;
smmu->as = devm_kzalloc(dev,
sizeof(smmu->as[0]) * smmu->num_as, GFP_KERNEL);
if (!smmu->as) {
dev_err(dev, "failed to allocate smmu_as\n");
err = -ENOMEM;
goto fail;
}
for (i = 0; i < smmu->num_as; i++) {
struct smmu_as *as = &smmu->as[i];
as->smmu = smmu;
as->asid = i;
as->pdir_attr = _PDIR_ATTR;
as->pde_attr = _PDE_ATTR;
as->pte_attr = _PTE_ATTR;
spin_lock_init(&as->lock);
INIT_LIST_HEAD(&as->client);
}
spin_lock_init(&smmu->lock);
smmu_setup_regs(smmu);
platform_set_drvdata(pdev, smmu);
smmu->avp_vector_page = alloc_page(GFP_KERNEL);
if (!smmu->avp_vector_page)
goto fail;
smmu_handle = smmu;
return 0;
fail:
if (smmu->avp_vector_page)
__free_page(smmu->avp_vector_page);
if (smmu->regs)
devm_iounmap(dev, smmu->regs);
if (smmu->regs_ahbarb)
devm_iounmap(dev, smmu->regs_ahbarb);
if (smmu && smmu->as) {
for (i = 0; i < smmu->num_as; i++) {
if (smmu->as[i].pdir_page) {
ClearPageReserved(smmu->as[i].pdir_page);
__free_page(smmu->as[i].pdir_page);
}
}
devm_kfree(dev, smmu->as);
}
devm_kfree(dev, smmu);
return err;
}
static int tegra_smmu_remove(struct platform_device *pdev)
{
struct smmu_device *smmu = platform_get_drvdata(pdev);
struct device *dev = smmu->dev;
smmu_write(smmu, SMMU_CONFIG_DISABLE, SMMU_CONFIG);
platform_set_drvdata(pdev, NULL);
if (smmu->as) {
int i;
for (i = 0; i < smmu->num_as; i++)
free_pdir(&smmu->as[i]);
devm_kfree(dev, smmu->as);
}
if (smmu->avp_vector_page)
__free_page(smmu->avp_vector_page);
if (smmu->regs)
devm_iounmap(dev, smmu->regs);
if (smmu->regs_ahbarb)
devm_iounmap(dev, smmu->regs_ahbarb);
devm_kfree(dev, smmu);
smmu_handle = NULL;
return 0;
}
static int __devinit tegra_smmu_init(void)
{
bus_set_iommu(&platform_bus_type, &smmu_iommu_ops);
return platform_driver_register(&tegra_smmu_driver);
}
static void __exit tegra_smmu_exit(void)
{
platform_driver_unregister(&tegra_smmu_driver);
}
