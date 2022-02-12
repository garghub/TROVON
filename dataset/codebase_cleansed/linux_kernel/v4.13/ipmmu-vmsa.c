static struct ipmmu_vmsa_domain *to_vmsa_domain(struct iommu_domain *dom)
{
return container_of(dom, struct ipmmu_vmsa_domain, io_domain);
}
static struct ipmmu_vmsa_iommu_priv *to_priv(struct device *dev)
{
#if defined(CONFIG_ARM)
return dev->archdata.iommu;
#else
return dev->iommu_fwspec->iommu_priv;
#endif
}
static void set_priv(struct device *dev, struct ipmmu_vmsa_iommu_priv *p)
{
#if defined(CONFIG_ARM)
dev->archdata.iommu = p;
#else
dev->iommu_fwspec->iommu_priv = p;
#endif
}
static u32 ipmmu_read(struct ipmmu_vmsa_device *mmu, unsigned int offset)
{
return ioread32(mmu->base + offset);
}
static void ipmmu_write(struct ipmmu_vmsa_device *mmu, unsigned int offset,
u32 data)
{
iowrite32(data, mmu->base + offset);
}
static u32 ipmmu_ctx_read(struct ipmmu_vmsa_domain *domain, unsigned int reg)
{
return ipmmu_read(domain->mmu, domain->context_id * IM_CTX_SIZE + reg);
}
static void ipmmu_ctx_write(struct ipmmu_vmsa_domain *domain, unsigned int reg,
u32 data)
{
ipmmu_write(domain->mmu, domain->context_id * IM_CTX_SIZE + reg, data);
}
static void ipmmu_tlb_sync(struct ipmmu_vmsa_domain *domain)
{
unsigned int count = 0;
while (ipmmu_ctx_read(domain, IMCTR) & IMCTR_FLUSH) {
cpu_relax();
if (++count == TLB_LOOP_TIMEOUT) {
dev_err_ratelimited(domain->mmu->dev,
"TLB sync timed out -- MMU may be deadlocked\n");
return;
}
udelay(1);
}
}
static void ipmmu_tlb_invalidate(struct ipmmu_vmsa_domain *domain)
{
u32 reg;
reg = ipmmu_ctx_read(domain, IMCTR);
reg |= IMCTR_FLUSH;
ipmmu_ctx_write(domain, IMCTR, reg);
ipmmu_tlb_sync(domain);
}
static void ipmmu_utlb_enable(struct ipmmu_vmsa_domain *domain,
unsigned int utlb)
{
struct ipmmu_vmsa_device *mmu = domain->mmu;
ipmmu_write(mmu, IMUASID(utlb), 0);
ipmmu_write(mmu, IMUCTR(utlb),
IMUCTR_TTSEL_MMU(domain->context_id) | IMUCTR_FLUSH |
IMUCTR_MMUEN);
}
static void ipmmu_utlb_disable(struct ipmmu_vmsa_domain *domain,
unsigned int utlb)
{
struct ipmmu_vmsa_device *mmu = domain->mmu;
ipmmu_write(mmu, IMUCTR(utlb), 0);
}
static void ipmmu_tlb_flush_all(void *cookie)
{
struct ipmmu_vmsa_domain *domain = cookie;
ipmmu_tlb_invalidate(domain);
}
static void ipmmu_tlb_add_flush(unsigned long iova, size_t size,
size_t granule, bool leaf, void *cookie)
{
}
static int ipmmu_domain_allocate_context(struct ipmmu_vmsa_device *mmu,
struct ipmmu_vmsa_domain *domain)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&mmu->lock, flags);
ret = find_first_zero_bit(mmu->ctx, IPMMU_CTX_MAX);
if (ret != IPMMU_CTX_MAX) {
mmu->domains[ret] = domain;
set_bit(ret, mmu->ctx);
}
spin_unlock_irqrestore(&mmu->lock, flags);
return ret;
}
static int ipmmu_domain_init_context(struct ipmmu_vmsa_domain *domain)
{
u64 ttbr;
int ret;
domain->cfg.quirks = IO_PGTABLE_QUIRK_ARM_NS;
domain->cfg.pgsize_bitmap = SZ_1G | SZ_2M | SZ_4K;
domain->cfg.ias = 32;
domain->cfg.oas = 40;
domain->cfg.tlb = &ipmmu_gather_ops;
domain->io_domain.geometry.aperture_end = DMA_BIT_MASK(32);
domain->io_domain.geometry.force_aperture = true;
domain->cfg.iommu_dev = domain->mmu->dev;
domain->iop = alloc_io_pgtable_ops(ARM_32_LPAE_S1, &domain->cfg,
domain);
if (!domain->iop)
return -EINVAL;
ret = ipmmu_domain_allocate_context(domain->mmu, domain);
if (ret == IPMMU_CTX_MAX) {
free_io_pgtable_ops(domain->iop);
return -EBUSY;
}
domain->context_id = ret;
ttbr = domain->cfg.arm_lpae_s1_cfg.ttbr[0];
ipmmu_ctx_write(domain, IMTTLBR0, ttbr);
ipmmu_ctx_write(domain, IMTTUBR0, ttbr >> 32);
ipmmu_ctx_write(domain, IMTTBCR, IMTTBCR_EAE |
IMTTBCR_SH0_INNER_SHAREABLE | IMTTBCR_ORGN0_WB_WA |
IMTTBCR_IRGN0_WB_WA | IMTTBCR_SL0_LVL_1);
ipmmu_ctx_write(domain, IMMAIR0, domain->cfg.arm_lpae_s1_cfg.mair[0]);
ipmmu_ctx_write(domain, IMBUSCR,
ipmmu_ctx_read(domain, IMBUSCR) &
~(IMBUSCR_DVM | IMBUSCR_BUSSEL_MASK));
ipmmu_ctx_write(domain, IMSTR, ipmmu_ctx_read(domain, IMSTR));
ipmmu_ctx_write(domain, IMCTR, IMCTR_INTEN | IMCTR_FLUSH | IMCTR_MMUEN);
return 0;
}
static void ipmmu_domain_free_context(struct ipmmu_vmsa_device *mmu,
unsigned int context_id)
{
unsigned long flags;
spin_lock_irqsave(&mmu->lock, flags);
clear_bit(context_id, mmu->ctx);
mmu->domains[context_id] = NULL;
spin_unlock_irqrestore(&mmu->lock, flags);
}
static void ipmmu_domain_destroy_context(struct ipmmu_vmsa_domain *domain)
{
ipmmu_ctx_write(domain, IMCTR, IMCTR_FLUSH);
ipmmu_tlb_sync(domain);
ipmmu_domain_free_context(domain->mmu, domain->context_id);
}
static irqreturn_t ipmmu_domain_irq(struct ipmmu_vmsa_domain *domain)
{
const u32 err_mask = IMSTR_MHIT | IMSTR_ABORT | IMSTR_PF | IMSTR_TF;
struct ipmmu_vmsa_device *mmu = domain->mmu;
u32 status;
u32 iova;
status = ipmmu_ctx_read(domain, IMSTR);
if (!(status & err_mask))
return IRQ_NONE;
iova = ipmmu_ctx_read(domain, IMEAR);
ipmmu_ctx_write(domain, IMSTR, 0);
if (status & IMSTR_MHIT)
dev_err_ratelimited(mmu->dev, "Multiple TLB hits @0x%08x\n",
iova);
if (status & IMSTR_ABORT)
dev_err_ratelimited(mmu->dev, "Page Table Walk Abort @0x%08x\n",
iova);
if (!(status & (IMSTR_PF | IMSTR_TF)))
return IRQ_NONE;
if (!report_iommu_fault(&domain->io_domain, mmu->dev, iova, 0))
return IRQ_HANDLED;
dev_err_ratelimited(mmu->dev,
"Unhandled fault: status 0x%08x iova 0x%08x\n",
status, iova);
return IRQ_HANDLED;
}
static irqreturn_t ipmmu_irq(int irq, void *dev)
{
struct ipmmu_vmsa_device *mmu = dev;
irqreturn_t status = IRQ_NONE;
unsigned int i;
unsigned long flags;
spin_lock_irqsave(&mmu->lock, flags);
for (i = 0; i < IPMMU_CTX_MAX; i++) {
if (!mmu->domains[i])
continue;
if (ipmmu_domain_irq(mmu->domains[i]) == IRQ_HANDLED)
status = IRQ_HANDLED;
}
spin_unlock_irqrestore(&mmu->lock, flags);
return status;
}
static struct iommu_domain *__ipmmu_domain_alloc(unsigned type)
{
struct ipmmu_vmsa_domain *domain;
domain = kzalloc(sizeof(*domain), GFP_KERNEL);
if (!domain)
return NULL;
spin_lock_init(&domain->lock);
return &domain->io_domain;
}
static void ipmmu_domain_free(struct iommu_domain *io_domain)
{
struct ipmmu_vmsa_domain *domain = to_vmsa_domain(io_domain);
ipmmu_domain_destroy_context(domain);
free_io_pgtable_ops(domain->iop);
kfree(domain);
}
static int ipmmu_attach_device(struct iommu_domain *io_domain,
struct device *dev)
{
struct ipmmu_vmsa_iommu_priv *priv = to_priv(dev);
struct ipmmu_vmsa_device *mmu = priv->mmu;
struct ipmmu_vmsa_domain *domain = to_vmsa_domain(io_domain);
unsigned long flags;
unsigned int i;
int ret = 0;
if (!mmu) {
dev_err(dev, "Cannot attach to IPMMU\n");
return -ENXIO;
}
spin_lock_irqsave(&domain->lock, flags);
if (!domain->mmu) {
domain->mmu = mmu;
ret = ipmmu_domain_init_context(domain);
} else if (domain->mmu != mmu) {
dev_err(dev, "Can't attach IPMMU %s to domain on IPMMU %s\n",
dev_name(mmu->dev), dev_name(domain->mmu->dev));
ret = -EINVAL;
} else
dev_info(dev, "Reusing IPMMU context %u\n", domain->context_id);
spin_unlock_irqrestore(&domain->lock, flags);
if (ret < 0)
return ret;
for (i = 0; i < priv->num_utlbs; ++i)
ipmmu_utlb_enable(domain, priv->utlbs[i]);
return 0;
}
static void ipmmu_detach_device(struct iommu_domain *io_domain,
struct device *dev)
{
struct ipmmu_vmsa_iommu_priv *priv = to_priv(dev);
struct ipmmu_vmsa_domain *domain = to_vmsa_domain(io_domain);
unsigned int i;
for (i = 0; i < priv->num_utlbs; ++i)
ipmmu_utlb_disable(domain, priv->utlbs[i]);
}
static int ipmmu_map(struct iommu_domain *io_domain, unsigned long iova,
phys_addr_t paddr, size_t size, int prot)
{
struct ipmmu_vmsa_domain *domain = to_vmsa_domain(io_domain);
if (!domain)
return -ENODEV;
return domain->iop->map(domain->iop, iova, paddr, size, prot);
}
static size_t ipmmu_unmap(struct iommu_domain *io_domain, unsigned long iova,
size_t size)
{
struct ipmmu_vmsa_domain *domain = to_vmsa_domain(io_domain);
return domain->iop->unmap(domain->iop, iova, size);
}
static phys_addr_t ipmmu_iova_to_phys(struct iommu_domain *io_domain,
dma_addr_t iova)
{
struct ipmmu_vmsa_domain *domain = to_vmsa_domain(io_domain);
return domain->iop->iova_to_phys(domain->iop, iova);
}
static int ipmmu_find_utlbs(struct ipmmu_vmsa_device *mmu, struct device *dev,
unsigned int *utlbs, unsigned int num_utlbs)
{
unsigned int i;
for (i = 0; i < num_utlbs; ++i) {
struct of_phandle_args args;
int ret;
ret = of_parse_phandle_with_args(dev->of_node, "iommus",
"#iommu-cells", i, &args);
if (ret < 0)
return ret;
of_node_put(args.np);
if (args.np != mmu->dev->of_node || args.args_count != 1)
return -EINVAL;
utlbs[i] = args.args[0];
}
return 0;
}
static int ipmmu_init_platform_device(struct device *dev)
{
struct ipmmu_vmsa_iommu_priv *priv;
struct ipmmu_vmsa_device *mmu;
unsigned int *utlbs;
unsigned int i;
int num_utlbs;
int ret = -ENODEV;
num_utlbs = of_count_phandle_with_args(dev->of_node, "iommus",
"#iommu-cells");
if (num_utlbs < 0)
return -ENODEV;
utlbs = kcalloc(num_utlbs, sizeof(*utlbs), GFP_KERNEL);
if (!utlbs)
return -ENOMEM;
spin_lock(&ipmmu_devices_lock);
list_for_each_entry(mmu, &ipmmu_devices, list) {
ret = ipmmu_find_utlbs(mmu, dev, utlbs, num_utlbs);
if (!ret) {
break;
}
}
spin_unlock(&ipmmu_devices_lock);
if (ret < 0)
goto error;
for (i = 0; i < num_utlbs; ++i) {
if (utlbs[i] >= mmu->num_utlbs) {
ret = -EINVAL;
goto error;
}
}
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv) {
ret = -ENOMEM;
goto error;
}
priv->mmu = mmu;
priv->utlbs = utlbs;
priv->num_utlbs = num_utlbs;
priv->dev = dev;
set_priv(dev, priv);
return 0;
error:
kfree(utlbs);
return ret;
}
static struct iommu_domain *ipmmu_domain_alloc(unsigned type)
{
if (type != IOMMU_DOMAIN_UNMANAGED)
return NULL;
return __ipmmu_domain_alloc(type);
}
static int ipmmu_add_device(struct device *dev)
{
struct ipmmu_vmsa_device *mmu = NULL;
struct iommu_group *group;
int ret;
if (to_priv(dev)) {
dev_warn(dev, "IOMMU driver already assigned to device %s\n",
dev_name(dev));
return -EINVAL;
}
group = iommu_group_alloc();
if (IS_ERR(group)) {
dev_err(dev, "Failed to allocate IOMMU group\n");
ret = PTR_ERR(group);
goto error;
}
ret = iommu_group_add_device(group, dev);
iommu_group_put(group);
if (ret < 0) {
dev_err(dev, "Failed to add device to IPMMU group\n");
group = NULL;
goto error;
}
ret = ipmmu_init_platform_device(dev);
if (ret < 0)
goto error;
mmu = to_priv(dev)->mmu;
if (!mmu->mapping) {
struct dma_iommu_mapping *mapping;
mapping = arm_iommu_create_mapping(&platform_bus_type,
SZ_1G, SZ_2G);
if (IS_ERR(mapping)) {
dev_err(mmu->dev, "failed to create ARM IOMMU mapping\n");
ret = PTR_ERR(mapping);
goto error;
}
mmu->mapping = mapping;
}
ret = arm_iommu_attach_device(dev, mmu->mapping);
if (ret < 0) {
dev_err(dev, "Failed to attach device to VA mapping\n");
goto error;
}
return 0;
error:
if (mmu)
arm_iommu_release_mapping(mmu->mapping);
if (!IS_ERR_OR_NULL(group))
iommu_group_remove_device(dev);
kfree(to_priv(dev)->utlbs);
kfree(to_priv(dev));
set_priv(dev, NULL);
return ret;
}
static void ipmmu_remove_device(struct device *dev)
{
struct ipmmu_vmsa_iommu_priv *priv = to_priv(dev);
arm_iommu_detach_device(dev);
iommu_group_remove_device(dev);
kfree(priv->utlbs);
kfree(priv);
set_priv(dev, NULL);
}
static struct iommu_domain *ipmmu_domain_alloc_dma(unsigned type)
{
struct iommu_domain *io_domain = NULL;
switch (type) {
case IOMMU_DOMAIN_UNMANAGED:
io_domain = __ipmmu_domain_alloc(type);
break;
case IOMMU_DOMAIN_DMA:
io_domain = __ipmmu_domain_alloc(type);
if (io_domain)
iommu_get_dma_cookie(io_domain);
break;
}
return io_domain;
}
static void ipmmu_domain_free_dma(struct iommu_domain *io_domain)
{
switch (io_domain->type) {
case IOMMU_DOMAIN_DMA:
iommu_put_dma_cookie(io_domain);
default:
ipmmu_domain_free(io_domain);
break;
}
}
static int ipmmu_add_device_dma(struct device *dev)
{
struct iommu_fwspec *fwspec = dev->iommu_fwspec;
struct iommu_group *group;
if (!fwspec || !fwspec->iommu_priv)
return -ENODEV;
group = iommu_group_get_for_dev(dev);
if (IS_ERR(group))
return PTR_ERR(group);
spin_lock(&ipmmu_slave_devices_lock);
list_add(&to_priv(dev)->list, &ipmmu_slave_devices);
spin_unlock(&ipmmu_slave_devices_lock);
return 0;
}
static void ipmmu_remove_device_dma(struct device *dev)
{
struct ipmmu_vmsa_iommu_priv *priv = to_priv(dev);
spin_lock(&ipmmu_slave_devices_lock);
list_del(&priv->list);
spin_unlock(&ipmmu_slave_devices_lock);
iommu_group_remove_device(dev);
}
static struct device *ipmmu_find_sibling_device(struct device *dev)
{
struct ipmmu_vmsa_iommu_priv *priv = to_priv(dev);
struct ipmmu_vmsa_iommu_priv *sibling_priv = NULL;
bool found = false;
spin_lock(&ipmmu_slave_devices_lock);
list_for_each_entry(sibling_priv, &ipmmu_slave_devices, list) {
if (priv == sibling_priv)
continue;
if (sibling_priv->mmu == priv->mmu) {
found = true;
break;
}
}
spin_unlock(&ipmmu_slave_devices_lock);
return found ? sibling_priv->dev : NULL;
}
static struct iommu_group *ipmmu_find_group_dma(struct device *dev)
{
struct iommu_group *group;
struct device *sibling;
sibling = ipmmu_find_sibling_device(dev);
if (sibling)
group = iommu_group_get(sibling);
if (!sibling || IS_ERR(group))
group = generic_device_group(dev);
return group;
}
static int ipmmu_of_xlate_dma(struct device *dev,
struct of_phandle_args *spec)
{
if (!of_device_is_available(spec->np))
return -ENODEV;
return ipmmu_init_platform_device(dev);
}
static void ipmmu_device_reset(struct ipmmu_vmsa_device *mmu)
{
unsigned int i;
for (i = 0; i < 4; ++i)
ipmmu_write(mmu, i * IM_CTX_SIZE + IMCTR, 0);
}
static int ipmmu_probe(struct platform_device *pdev)
{
struct ipmmu_vmsa_device *mmu;
struct resource *res;
int irq;
int ret;
mmu = devm_kzalloc(&pdev->dev, sizeof(*mmu), GFP_KERNEL);
if (!mmu) {
dev_err(&pdev->dev, "cannot allocate device data\n");
return -ENOMEM;
}
mmu->dev = &pdev->dev;
mmu->num_utlbs = 32;
spin_lock_init(&mmu->lock);
bitmap_zero(mmu->ctx, IPMMU_CTX_MAX);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mmu->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mmu->base))
return PTR_ERR(mmu->base);
mmu->base += IM_NS_ALIAS_OFFSET;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "no IRQ found\n");
return irq;
}
ret = devm_request_irq(&pdev->dev, irq, ipmmu_irq, 0,
dev_name(&pdev->dev), mmu);
if (ret < 0) {
dev_err(&pdev->dev, "failed to request IRQ %d\n", irq);
return ret;
}
ipmmu_device_reset(mmu);
spin_lock(&ipmmu_devices_lock);
list_add(&mmu->list, &ipmmu_devices);
spin_unlock(&ipmmu_devices_lock);
platform_set_drvdata(pdev, mmu);
return 0;
}
static int ipmmu_remove(struct platform_device *pdev)
{
struct ipmmu_vmsa_device *mmu = platform_get_drvdata(pdev);
spin_lock(&ipmmu_devices_lock);
list_del(&mmu->list);
spin_unlock(&ipmmu_devices_lock);
#if defined(CONFIG_ARM) && !defined(CONFIG_IOMMU_DMA)
arm_iommu_release_mapping(mmu->mapping);
#endif
ipmmu_device_reset(mmu);
return 0;
}
static int __init ipmmu_init(void)
{
int ret;
ret = platform_driver_register(&ipmmu_driver);
if (ret < 0)
return ret;
if (!iommu_present(&platform_bus_type))
bus_set_iommu(&platform_bus_type, &ipmmu_ops);
return 0;
}
static void __exit ipmmu_exit(void)
{
return platform_driver_unregister(&ipmmu_driver);
}
