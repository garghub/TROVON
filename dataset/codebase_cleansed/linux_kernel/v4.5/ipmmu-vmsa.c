static struct ipmmu_vmsa_domain *to_vmsa_domain(struct iommu_domain *dom)
{
return container_of(dom, struct ipmmu_vmsa_domain, io_domain);
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
static int ipmmu_domain_init_context(struct ipmmu_vmsa_domain *domain)
{
u64 ttbr;
domain->cfg.quirks = IO_PGTABLE_QUIRK_ARM_NS;
domain->cfg.pgsize_bitmap = SZ_1G | SZ_2M | SZ_4K,
domain->cfg.ias = 32;
domain->cfg.oas = 40;
domain->cfg.tlb = &ipmmu_gather_ops;
domain->cfg.iommu_dev = domain->mmu->dev;
domain->iop = alloc_io_pgtable_ops(ARM_32_LPAE_S1, &domain->cfg,
domain);
if (!domain->iop)
return -EINVAL;
domain->context_id = 0;
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
static void ipmmu_domain_destroy_context(struct ipmmu_vmsa_domain *domain)
{
ipmmu_ctx_write(domain, IMCTR, IMCTR_FLUSH);
ipmmu_tlb_sync(domain);
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
struct iommu_domain *io_domain;
struct ipmmu_vmsa_domain *domain;
if (!mmu->mapping)
return IRQ_NONE;
io_domain = mmu->mapping->domain;
domain = to_vmsa_domain(io_domain);
return ipmmu_domain_irq(domain);
}
static struct iommu_domain *ipmmu_domain_alloc(unsigned type)
{
struct ipmmu_vmsa_domain *domain;
if (type != IOMMU_DOMAIN_UNMANAGED)
return NULL;
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
struct ipmmu_vmsa_archdata *archdata = dev->archdata.iommu;
struct ipmmu_vmsa_device *mmu = archdata->mmu;
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
}
spin_unlock_irqrestore(&domain->lock, flags);
if (ret < 0)
return ret;
for (i = 0; i < archdata->num_utlbs; ++i)
ipmmu_utlb_enable(domain, archdata->utlbs[i]);
return 0;
}
static void ipmmu_detach_device(struct iommu_domain *io_domain,
struct device *dev)
{
struct ipmmu_vmsa_archdata *archdata = dev->archdata.iommu;
struct ipmmu_vmsa_domain *domain = to_vmsa_domain(io_domain);
unsigned int i;
for (i = 0; i < archdata->num_utlbs; ++i)
ipmmu_utlb_disable(domain, archdata->utlbs[i]);
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
static int ipmmu_add_device(struct device *dev)
{
struct ipmmu_vmsa_archdata *archdata;
struct ipmmu_vmsa_device *mmu;
struct iommu_group *group = NULL;
unsigned int *utlbs;
unsigned int i;
int num_utlbs;
int ret = -ENODEV;
if (dev->archdata.iommu) {
dev_warn(dev, "IOMMU driver already assigned to device %s\n",
dev_name(dev));
return -EINVAL;
}
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
return -ENODEV;
for (i = 0; i < num_utlbs; ++i) {
if (utlbs[i] >= mmu->num_utlbs) {
ret = -EINVAL;
goto error;
}
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
archdata = kzalloc(sizeof(*archdata), GFP_KERNEL);
if (!archdata) {
ret = -ENOMEM;
goto error;
}
archdata->mmu = mmu;
archdata->utlbs = utlbs;
archdata->num_utlbs = num_utlbs;
dev->archdata.iommu = archdata;
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
arm_iommu_release_mapping(mmu->mapping);
kfree(dev->archdata.iommu);
kfree(utlbs);
dev->archdata.iommu = NULL;
if (!IS_ERR_OR_NULL(group))
iommu_group_remove_device(dev);
return ret;
}
static void ipmmu_remove_device(struct device *dev)
{
struct ipmmu_vmsa_archdata *archdata = dev->archdata.iommu;
arm_iommu_detach_device(dev);
iommu_group_remove_device(dev);
kfree(archdata->utlbs);
kfree(archdata);
dev->archdata.iommu = NULL;
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
if (!IS_ENABLED(CONFIG_OF) && !pdev->dev.platform_data) {
dev_err(&pdev->dev, "missing platform data\n");
return -EINVAL;
}
mmu = devm_kzalloc(&pdev->dev, sizeof(*mmu), GFP_KERNEL);
if (!mmu) {
dev_err(&pdev->dev, "cannot allocate device data\n");
return -ENOMEM;
}
mmu->dev = &pdev->dev;
mmu->num_utlbs = 32;
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
arm_iommu_release_mapping(mmu->mapping);
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
