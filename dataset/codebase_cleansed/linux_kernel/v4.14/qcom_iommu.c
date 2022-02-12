static struct qcom_iommu_domain *to_qcom_iommu_domain(struct iommu_domain *dom)
{
return container_of(dom, struct qcom_iommu_domain, domain);
}
static struct qcom_iommu_dev * to_iommu(struct iommu_fwspec *fwspec)
{
if (!fwspec || fwspec->ops != &qcom_iommu_ops)
return NULL;
return fwspec->iommu_priv;
}
static struct qcom_iommu_ctx * to_ctx(struct iommu_fwspec *fwspec, unsigned asid)
{
struct qcom_iommu_dev *qcom_iommu = to_iommu(fwspec);
if (!qcom_iommu)
return NULL;
return qcom_iommu->ctxs[asid - 1];
}
static inline void
iommu_writel(struct qcom_iommu_ctx *ctx, unsigned reg, u32 val)
{
writel_relaxed(val, ctx->base + reg);
}
static inline void
iommu_writeq(struct qcom_iommu_ctx *ctx, unsigned reg, u64 val)
{
writeq_relaxed(val, ctx->base + reg);
}
static inline u32
iommu_readl(struct qcom_iommu_ctx *ctx, unsigned reg)
{
return readl_relaxed(ctx->base + reg);
}
static inline u64
iommu_readq(struct qcom_iommu_ctx *ctx, unsigned reg)
{
return readq_relaxed(ctx->base + reg);
}
static void qcom_iommu_tlb_sync(void *cookie)
{
struct iommu_fwspec *fwspec = cookie;
unsigned i;
for (i = 0; i < fwspec->num_ids; i++) {
struct qcom_iommu_ctx *ctx = to_ctx(fwspec, fwspec->ids[i]);
unsigned int val, ret;
iommu_writel(ctx, ARM_SMMU_CB_TLBSYNC, 0);
ret = readl_poll_timeout(ctx->base + ARM_SMMU_CB_TLBSTATUS, val,
(val & 0x1) == 0, 0, 5000000);
if (ret)
dev_err(ctx->dev, "timeout waiting for TLB SYNC\n");
}
}
static void qcom_iommu_tlb_inv_context(void *cookie)
{
struct iommu_fwspec *fwspec = cookie;
unsigned i;
for (i = 0; i < fwspec->num_ids; i++) {
struct qcom_iommu_ctx *ctx = to_ctx(fwspec, fwspec->ids[i]);
iommu_writel(ctx, ARM_SMMU_CB_S1_TLBIASID, ctx->asid);
}
qcom_iommu_tlb_sync(cookie);
}
static void qcom_iommu_tlb_inv_range_nosync(unsigned long iova, size_t size,
size_t granule, bool leaf, void *cookie)
{
struct iommu_fwspec *fwspec = cookie;
unsigned i, reg;
reg = leaf ? ARM_SMMU_CB_S1_TLBIVAL : ARM_SMMU_CB_S1_TLBIVA;
for (i = 0; i < fwspec->num_ids; i++) {
struct qcom_iommu_ctx *ctx = to_ctx(fwspec, fwspec->ids[i]);
size_t s = size;
iova &= ~12UL;
iova |= ctx->asid;
do {
iommu_writel(ctx, reg, iova);
iova += granule;
} while (s -= granule);
}
}
static irqreturn_t qcom_iommu_fault(int irq, void *dev)
{
struct qcom_iommu_ctx *ctx = dev;
u32 fsr, fsynr;
u64 iova;
fsr = iommu_readl(ctx, ARM_SMMU_CB_FSR);
if (!(fsr & FSR_FAULT))
return IRQ_NONE;
fsynr = iommu_readl(ctx, ARM_SMMU_CB_FSYNR0);
iova = iommu_readq(ctx, ARM_SMMU_CB_FAR);
dev_err_ratelimited(ctx->dev,
"Unhandled context fault: fsr=0x%x, "
"iova=0x%016llx, fsynr=0x%x, cb=%d\n",
fsr, iova, fsynr, ctx->asid);
iommu_writel(ctx, ARM_SMMU_CB_FSR, fsr);
return IRQ_HANDLED;
}
static int qcom_iommu_init_domain(struct iommu_domain *domain,
struct qcom_iommu_dev *qcom_iommu,
struct iommu_fwspec *fwspec)
{
struct qcom_iommu_domain *qcom_domain = to_qcom_iommu_domain(domain);
struct io_pgtable_ops *pgtbl_ops;
struct io_pgtable_cfg pgtbl_cfg;
int i, ret = 0;
u32 reg;
mutex_lock(&qcom_domain->init_mutex);
if (qcom_domain->iommu)
goto out_unlock;
pgtbl_cfg = (struct io_pgtable_cfg) {
.pgsize_bitmap = qcom_iommu_ops.pgsize_bitmap,
.ias = 32,
.oas = 40,
.tlb = &qcom_gather_ops,
.iommu_dev = qcom_iommu->dev,
};
qcom_domain->iommu = qcom_iommu;
pgtbl_ops = alloc_io_pgtable_ops(ARM_32_LPAE_S1, &pgtbl_cfg, fwspec);
if (!pgtbl_ops) {
dev_err(qcom_iommu->dev, "failed to allocate pagetable ops\n");
ret = -ENOMEM;
goto out_clear_iommu;
}
domain->pgsize_bitmap = pgtbl_cfg.pgsize_bitmap;
domain->geometry.aperture_end = (1ULL << pgtbl_cfg.ias) - 1;
domain->geometry.force_aperture = true;
for (i = 0; i < fwspec->num_ids; i++) {
struct qcom_iommu_ctx *ctx = to_ctx(fwspec, fwspec->ids[i]);
if (!ctx->secure_init) {
ret = qcom_scm_restore_sec_cfg(qcom_iommu->sec_id, ctx->asid);
if (ret) {
dev_err(qcom_iommu->dev, "secure init failed: %d\n", ret);
goto out_clear_iommu;
}
ctx->secure_init = true;
}
iommu_writeq(ctx, ARM_SMMU_CB_TTBR0,
pgtbl_cfg.arm_lpae_s1_cfg.ttbr[0] |
((u64)ctx->asid << TTBRn_ASID_SHIFT));
iommu_writeq(ctx, ARM_SMMU_CB_TTBR1,
pgtbl_cfg.arm_lpae_s1_cfg.ttbr[1] |
((u64)ctx->asid << TTBRn_ASID_SHIFT));
iommu_writel(ctx, ARM_SMMU_CB_TTBCR2,
(pgtbl_cfg.arm_lpae_s1_cfg.tcr >> 32) |
TTBCR2_SEP_UPSTREAM);
iommu_writel(ctx, ARM_SMMU_CB_TTBCR,
pgtbl_cfg.arm_lpae_s1_cfg.tcr);
iommu_writel(ctx, ARM_SMMU_CB_S1_MAIR0,
pgtbl_cfg.arm_lpae_s1_cfg.mair[0]);
iommu_writel(ctx, ARM_SMMU_CB_S1_MAIR1,
pgtbl_cfg.arm_lpae_s1_cfg.mair[1]);
reg = SCTLR_CFIE | SCTLR_CFRE | SCTLR_AFE | SCTLR_TRE |
SCTLR_M | SCTLR_S1_ASIDPNE;
if (IS_ENABLED(CONFIG_BIG_ENDIAN))
reg |= SCTLR_E;
iommu_writel(ctx, ARM_SMMU_CB_SCTLR, reg);
}
mutex_unlock(&qcom_domain->init_mutex);
qcom_domain->pgtbl_ops = pgtbl_ops;
return 0;
out_clear_iommu:
qcom_domain->iommu = NULL;
out_unlock:
mutex_unlock(&qcom_domain->init_mutex);
return ret;
}
static struct iommu_domain *qcom_iommu_domain_alloc(unsigned type)
{
struct qcom_iommu_domain *qcom_domain;
if (type != IOMMU_DOMAIN_UNMANAGED && type != IOMMU_DOMAIN_DMA)
return NULL;
qcom_domain = kzalloc(sizeof(*qcom_domain), GFP_KERNEL);
if (!qcom_domain)
return NULL;
if (type == IOMMU_DOMAIN_DMA &&
iommu_get_dma_cookie(&qcom_domain->domain)) {
kfree(qcom_domain);
return NULL;
}
mutex_init(&qcom_domain->init_mutex);
spin_lock_init(&qcom_domain->pgtbl_lock);
return &qcom_domain->domain;
}
static void qcom_iommu_domain_free(struct iommu_domain *domain)
{
struct qcom_iommu_domain *qcom_domain = to_qcom_iommu_domain(domain);
if (WARN_ON(qcom_domain->iommu))
return;
iommu_put_dma_cookie(domain);
pm_runtime_get_sync(qcom_domain->iommu->dev);
free_io_pgtable_ops(qcom_domain->pgtbl_ops);
pm_runtime_put_sync(qcom_domain->iommu->dev);
kfree(qcom_domain);
}
static int qcom_iommu_attach_dev(struct iommu_domain *domain, struct device *dev)
{
struct qcom_iommu_dev *qcom_iommu = to_iommu(dev->iommu_fwspec);
struct qcom_iommu_domain *qcom_domain = to_qcom_iommu_domain(domain);
int ret;
if (!qcom_iommu) {
dev_err(dev, "cannot attach to IOMMU, is it on the same bus?\n");
return -ENXIO;
}
pm_runtime_get_sync(qcom_iommu->dev);
ret = qcom_iommu_init_domain(domain, qcom_iommu, dev->iommu_fwspec);
pm_runtime_put_sync(qcom_iommu->dev);
if (ret < 0)
return ret;
if (qcom_domain->iommu != qcom_iommu) {
dev_err(dev, "cannot attach to IOMMU %s while already "
"attached to domain on IOMMU %s\n",
dev_name(qcom_domain->iommu->dev),
dev_name(qcom_iommu->dev));
return -EINVAL;
}
return 0;
}
static void qcom_iommu_detach_dev(struct iommu_domain *domain, struct device *dev)
{
struct iommu_fwspec *fwspec = dev->iommu_fwspec;
struct qcom_iommu_dev *qcom_iommu = to_iommu(fwspec);
struct qcom_iommu_domain *qcom_domain = to_qcom_iommu_domain(domain);
unsigned i;
if (!qcom_domain->iommu)
return;
pm_runtime_get_sync(qcom_iommu->dev);
for (i = 0; i < fwspec->num_ids; i++) {
struct qcom_iommu_ctx *ctx = to_ctx(fwspec, fwspec->ids[i]);
iommu_writel(ctx, ARM_SMMU_CB_SCTLR, 0);
}
pm_runtime_put_sync(qcom_iommu->dev);
qcom_domain->iommu = NULL;
}
static int qcom_iommu_map(struct iommu_domain *domain, unsigned long iova,
phys_addr_t paddr, size_t size, int prot)
{
int ret;
unsigned long flags;
struct qcom_iommu_domain *qcom_domain = to_qcom_iommu_domain(domain);
struct io_pgtable_ops *ops = qcom_domain->pgtbl_ops;
if (!ops)
return -ENODEV;
spin_lock_irqsave(&qcom_domain->pgtbl_lock, flags);
ret = ops->map(ops, iova, paddr, size, prot);
spin_unlock_irqrestore(&qcom_domain->pgtbl_lock, flags);
return ret;
}
static size_t qcom_iommu_unmap(struct iommu_domain *domain, unsigned long iova,
size_t size)
{
size_t ret;
unsigned long flags;
struct qcom_iommu_domain *qcom_domain = to_qcom_iommu_domain(domain);
struct io_pgtable_ops *ops = qcom_domain->pgtbl_ops;
if (!ops)
return 0;
pm_runtime_get_sync(qcom_domain->iommu->dev);
spin_lock_irqsave(&qcom_domain->pgtbl_lock, flags);
ret = ops->unmap(ops, iova, size);
spin_unlock_irqrestore(&qcom_domain->pgtbl_lock, flags);
pm_runtime_put_sync(qcom_domain->iommu->dev);
return ret;
}
static phys_addr_t qcom_iommu_iova_to_phys(struct iommu_domain *domain,
dma_addr_t iova)
{
phys_addr_t ret;
unsigned long flags;
struct qcom_iommu_domain *qcom_domain = to_qcom_iommu_domain(domain);
struct io_pgtable_ops *ops = qcom_domain->pgtbl_ops;
if (!ops)
return 0;
spin_lock_irqsave(&qcom_domain->pgtbl_lock, flags);
ret = ops->iova_to_phys(ops, iova);
spin_unlock_irqrestore(&qcom_domain->pgtbl_lock, flags);
return ret;
}
static bool qcom_iommu_capable(enum iommu_cap cap)
{
switch (cap) {
case IOMMU_CAP_CACHE_COHERENCY:
return true;
case IOMMU_CAP_NOEXEC:
return true;
default:
return false;
}
}
static int qcom_iommu_add_device(struct device *dev)
{
struct qcom_iommu_dev *qcom_iommu = to_iommu(dev->iommu_fwspec);
struct iommu_group *group;
struct device_link *link;
if (!qcom_iommu)
return -ENODEV;
link = device_link_add(dev, qcom_iommu->dev, DL_FLAG_PM_RUNTIME);
if (!link) {
dev_err(qcom_iommu->dev, "Unable to create device link between %s and %s\n",
dev_name(qcom_iommu->dev), dev_name(dev));
return -ENODEV;
}
group = iommu_group_get_for_dev(dev);
if (IS_ERR_OR_NULL(group))
return PTR_ERR_OR_ZERO(group);
iommu_group_put(group);
iommu_device_link(&qcom_iommu->iommu, dev);
return 0;
}
static void qcom_iommu_remove_device(struct device *dev)
{
struct qcom_iommu_dev *qcom_iommu = to_iommu(dev->iommu_fwspec);
if (!qcom_iommu)
return;
iommu_device_unlink(&qcom_iommu->iommu, dev);
iommu_group_remove_device(dev);
iommu_fwspec_free(dev);
}
static int qcom_iommu_of_xlate(struct device *dev, struct of_phandle_args *args)
{
struct qcom_iommu_dev *qcom_iommu;
struct platform_device *iommu_pdev;
unsigned asid = args->args[0];
if (args->args_count != 1) {
dev_err(dev, "incorrect number of iommu params found for %s "
"(found %d, expected 1)\n",
args->np->full_name, args->args_count);
return -EINVAL;
}
iommu_pdev = of_find_device_by_node(args->np);
if (WARN_ON(!iommu_pdev))
return -EINVAL;
qcom_iommu = platform_get_drvdata(iommu_pdev);
if (WARN_ON(asid < 1) ||
WARN_ON(asid > qcom_iommu->num_ctxs))
return -EINVAL;
if (!dev->iommu_fwspec->iommu_priv) {
dev->iommu_fwspec->iommu_priv = qcom_iommu;
} else {
if (WARN_ON(qcom_iommu != dev->iommu_fwspec->iommu_priv))
return -EINVAL;
}
return iommu_fwspec_add_ids(dev, &asid, 1);
}
static int qcom_iommu_enable_clocks(struct qcom_iommu_dev *qcom_iommu)
{
int ret;
ret = clk_prepare_enable(qcom_iommu->iface_clk);
if (ret) {
dev_err(qcom_iommu->dev, "Couldn't enable iface_clk\n");
return ret;
}
ret = clk_prepare_enable(qcom_iommu->bus_clk);
if (ret) {
dev_err(qcom_iommu->dev, "Couldn't enable bus_clk\n");
clk_disable_unprepare(qcom_iommu->iface_clk);
return ret;
}
return 0;
}
static void qcom_iommu_disable_clocks(struct qcom_iommu_dev *qcom_iommu)
{
clk_disable_unprepare(qcom_iommu->bus_clk);
clk_disable_unprepare(qcom_iommu->iface_clk);
}
static int qcom_iommu_sec_ptbl_init(struct device *dev)
{
size_t psize = 0;
unsigned int spare = 0;
void *cpu_addr;
dma_addr_t paddr;
unsigned long attrs;
static bool allocated = false;
int ret;
if (allocated)
return 0;
ret = qcom_scm_iommu_secure_ptbl_size(spare, &psize);
if (ret) {
dev_err(dev, "failed to get iommu secure pgtable size (%d)\n",
ret);
return ret;
}
dev_info(dev, "iommu sec: pgtable size: %zu\n", psize);
attrs = DMA_ATTR_NO_KERNEL_MAPPING;
cpu_addr = dma_alloc_attrs(dev, psize, &paddr, GFP_KERNEL, attrs);
if (!cpu_addr) {
dev_err(dev, "failed to allocate %zu bytes for pgtable\n",
psize);
return -ENOMEM;
}
ret = qcom_scm_iommu_secure_ptbl_init(paddr, psize, spare);
if (ret) {
dev_err(dev, "failed to init iommu pgtable (%d)\n", ret);
goto free_mem;
}
allocated = true;
return 0;
free_mem:
dma_free_attrs(dev, psize, cpu_addr, paddr, attrs);
return ret;
}
static int get_asid(const struct device_node *np)
{
u32 reg;
if (of_property_read_u32_index(np, "reg", 0, &reg))
return -ENODEV;
return reg / 0x1000;
}
static int qcom_iommu_ctx_probe(struct platform_device *pdev)
{
struct qcom_iommu_ctx *ctx;
struct device *dev = &pdev->dev;
struct qcom_iommu_dev *qcom_iommu = dev_get_drvdata(dev->parent);
struct resource *res;
int ret, irq;
ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
ctx->dev = dev;
platform_set_drvdata(pdev, ctx);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ctx->base = devm_ioremap_resource(dev, res);
if (IS_ERR(ctx->base))
return PTR_ERR(ctx->base);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "failed to get irq\n");
return -ENODEV;
}
iommu_writel(ctx, ARM_SMMU_CB_FSR, iommu_readl(ctx, ARM_SMMU_CB_FSR));
ret = devm_request_irq(dev, irq,
qcom_iommu_fault,
IRQF_SHARED,
"qcom-iommu-fault",
ctx);
if (ret) {
dev_err(dev, "failed to request IRQ %u\n", irq);
return ret;
}
ret = get_asid(dev->of_node);
if (ret < 0) {
dev_err(dev, "missing reg property\n");
return ret;
}
ctx->asid = ret;
dev_dbg(dev, "found asid %u\n", ctx->asid);
qcom_iommu->ctxs[ctx->asid - 1] = ctx;
return 0;
}
static int qcom_iommu_ctx_remove(struct platform_device *pdev)
{
struct qcom_iommu_dev *qcom_iommu = dev_get_drvdata(pdev->dev.parent);
struct qcom_iommu_ctx *ctx = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
qcom_iommu->ctxs[ctx->asid - 1] = NULL;
return 0;
}
static bool qcom_iommu_has_secure_context(struct qcom_iommu_dev *qcom_iommu)
{
struct device_node *child;
for_each_child_of_node(qcom_iommu->dev->of_node, child)
if (of_device_is_compatible(child, "qcom,msm-iommu-v1-sec"))
return true;
return false;
}
static int qcom_iommu_device_probe(struct platform_device *pdev)
{
struct device_node *child;
struct qcom_iommu_dev *qcom_iommu;
struct device *dev = &pdev->dev;
struct resource *res;
int ret, sz, max_asid = 0;
for_each_child_of_node(dev->of_node, child)
max_asid = max(max_asid, get_asid(child));
sz = sizeof(*qcom_iommu) + (max_asid * sizeof(qcom_iommu->ctxs[0]));
qcom_iommu = devm_kzalloc(dev, sz, GFP_KERNEL);
if (!qcom_iommu)
return -ENOMEM;
qcom_iommu->num_ctxs = max_asid;
qcom_iommu->dev = dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res)
qcom_iommu->local_base = devm_ioremap_resource(dev, res);
qcom_iommu->iface_clk = devm_clk_get(dev, "iface");
if (IS_ERR(qcom_iommu->iface_clk)) {
dev_err(dev, "failed to get iface clock\n");
return PTR_ERR(qcom_iommu->iface_clk);
}
qcom_iommu->bus_clk = devm_clk_get(dev, "bus");
if (IS_ERR(qcom_iommu->bus_clk)) {
dev_err(dev, "failed to get bus clock\n");
return PTR_ERR(qcom_iommu->bus_clk);
}
if (of_property_read_u32(dev->of_node, "qcom,iommu-secure-id",
&qcom_iommu->sec_id)) {
dev_err(dev, "missing qcom,iommu-secure-id property\n");
return -ENODEV;
}
if (qcom_iommu_has_secure_context(qcom_iommu)) {
ret = qcom_iommu_sec_ptbl_init(dev);
if (ret) {
dev_err(dev, "cannot init secure pg table(%d)\n", ret);
return ret;
}
}
platform_set_drvdata(pdev, qcom_iommu);
pm_runtime_enable(dev);
ret = devm_of_platform_populate(dev);
if (ret) {
dev_err(dev, "Failed to populate iommu contexts\n");
return ret;
}
ret = iommu_device_sysfs_add(&qcom_iommu->iommu, dev, NULL,
dev_name(dev));
if (ret) {
dev_err(dev, "Failed to register iommu in sysfs\n");
return ret;
}
iommu_device_set_ops(&qcom_iommu->iommu, &qcom_iommu_ops);
iommu_device_set_fwnode(&qcom_iommu->iommu, dev->fwnode);
ret = iommu_device_register(&qcom_iommu->iommu);
if (ret) {
dev_err(dev, "Failed to register iommu\n");
return ret;
}
bus_set_iommu(&platform_bus_type, &qcom_iommu_ops);
if (qcom_iommu->local_base) {
pm_runtime_get_sync(dev);
writel_relaxed(0xffffffff, qcom_iommu->local_base + SMMU_INTR_SEL_NS);
pm_runtime_put_sync(dev);
}
return 0;
}
static int qcom_iommu_device_remove(struct platform_device *pdev)
{
struct qcom_iommu_dev *qcom_iommu = platform_get_drvdata(pdev);
bus_set_iommu(&platform_bus_type, NULL);
pm_runtime_force_suspend(&pdev->dev);
platform_set_drvdata(pdev, NULL);
iommu_device_sysfs_remove(&qcom_iommu->iommu);
iommu_device_unregister(&qcom_iommu->iommu);
return 0;
}
static int __maybe_unused qcom_iommu_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct qcom_iommu_dev *qcom_iommu = platform_get_drvdata(pdev);
return qcom_iommu_enable_clocks(qcom_iommu);
}
static int __maybe_unused qcom_iommu_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct qcom_iommu_dev *qcom_iommu = platform_get_drvdata(pdev);
qcom_iommu_disable_clocks(qcom_iommu);
return 0;
}
static int __init qcom_iommu_init(void)
{
int ret;
ret = platform_driver_register(&qcom_iommu_ctx_driver);
if (ret)
return ret;
ret = platform_driver_register(&qcom_iommu_driver);
if (ret)
platform_driver_unregister(&qcom_iommu_ctx_driver);
return ret;
}
static void __exit qcom_iommu_exit(void)
{
platform_driver_unregister(&qcom_iommu_driver);
platform_driver_unregister(&qcom_iommu_ctx_driver);
}
