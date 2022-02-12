static struct mtk_iommu_domain *to_mtk_domain(struct iommu_domain *dom)
{
return container_of(dom, struct mtk_iommu_domain, domain);
}
static void mtk_iommu_tlb_flush_all(void *cookie)
{
struct mtk_iommu_data *data = cookie;
writel_relaxed(F_INVLD_EN1 | F_INVLD_EN0, data->base + REG_MMU_INV_SEL);
writel_relaxed(F_ALL_INVLD, data->base + REG_MMU_INVALIDATE);
wmb();
}
static void mtk_iommu_tlb_add_flush_nosync(unsigned long iova, size_t size,
size_t granule, bool leaf,
void *cookie)
{
struct mtk_iommu_data *data = cookie;
writel_relaxed(F_INVLD_EN1 | F_INVLD_EN0, data->base + REG_MMU_INV_SEL);
writel_relaxed(iova, data->base + REG_MMU_INVLD_START_A);
writel_relaxed(iova + size - 1, data->base + REG_MMU_INVLD_END_A);
writel_relaxed(F_MMU_INV_RANGE, data->base + REG_MMU_INVALIDATE);
}
static void mtk_iommu_tlb_sync(void *cookie)
{
struct mtk_iommu_data *data = cookie;
int ret;
u32 tmp;
ret = readl_poll_timeout_atomic(data->base + REG_MMU_CPE_DONE, tmp,
tmp != 0, 10, 100000);
if (ret) {
dev_warn(data->dev,
"Partial TLB flush timed out, falling back to full flush\n");
mtk_iommu_tlb_flush_all(cookie);
}
writel_relaxed(0, data->base + REG_MMU_CPE_DONE);
}
static irqreturn_t mtk_iommu_isr(int irq, void *dev_id)
{
struct mtk_iommu_data *data = dev_id;
struct mtk_iommu_domain *dom = data->m4u_dom;
u32 int_state, regval, fault_iova, fault_pa;
unsigned int fault_larb, fault_port;
bool layer, write;
int_state = readl_relaxed(data->base + REG_MMU_FAULT_ST1);
fault_iova = readl_relaxed(data->base + REG_MMU_FAULT_VA);
layer = fault_iova & F_MMU_FAULT_VA_LAYER_BIT;
write = fault_iova & F_MMU_FAULT_VA_WRITE_BIT;
fault_iova &= F_MMU_FAULT_VA_MSK;
fault_pa = readl_relaxed(data->base + REG_MMU_INVLD_PA);
regval = readl_relaxed(data->base + REG_MMU_INT_ID);
fault_larb = F_MMU0_INT_ID_LARB_ID(regval);
fault_port = F_MMU0_INT_ID_PORT_ID(regval);
if (report_iommu_fault(&dom->domain, data->dev, fault_iova,
write ? IOMMU_FAULT_WRITE : IOMMU_FAULT_READ)) {
dev_err_ratelimited(
data->dev,
"fault type=0x%x iova=0x%x pa=0x%x larb=%d port=%d layer=%d %s\n",
int_state, fault_iova, fault_pa, fault_larb, fault_port,
layer, write ? "write" : "read");
}
regval = readl_relaxed(data->base + REG_MMU_INT_CONTROL0);
regval |= F_INT_CLR_BIT;
writel_relaxed(regval, data->base + REG_MMU_INT_CONTROL0);
mtk_iommu_tlb_flush_all(data);
return IRQ_HANDLED;
}
static void mtk_iommu_config(struct mtk_iommu_data *data,
struct device *dev, bool enable)
{
struct mtk_iommu_client_priv *head, *cur, *next;
struct mtk_smi_larb_iommu *larb_mmu;
unsigned int larbid, portid;
head = dev->archdata.iommu;
list_for_each_entry_safe(cur, next, &head->client, client) {
larbid = MTK_M4U_TO_LARB(cur->mtk_m4u_id);
portid = MTK_M4U_TO_PORT(cur->mtk_m4u_id);
larb_mmu = &data->smi_imu.larb_imu[larbid];
dev_dbg(dev, "%s iommu port: %d\n",
enable ? "enable" : "disable", portid);
if (enable)
larb_mmu->mmu |= MTK_SMI_MMU_EN(portid);
else
larb_mmu->mmu &= ~MTK_SMI_MMU_EN(portid);
}
}
static int mtk_iommu_domain_finalise(struct mtk_iommu_data *data)
{
struct mtk_iommu_domain *dom = data->m4u_dom;
spin_lock_init(&dom->pgtlock);
dom->cfg = (struct io_pgtable_cfg) {
.quirks = IO_PGTABLE_QUIRK_ARM_NS |
IO_PGTABLE_QUIRK_NO_PERMS |
IO_PGTABLE_QUIRK_TLBI_ON_MAP,
.pgsize_bitmap = mtk_iommu_ops.pgsize_bitmap,
.ias = 32,
.oas = 32,
.tlb = &mtk_iommu_gather_ops,
.iommu_dev = data->dev,
};
if (data->enable_4GB)
dom->cfg.quirks |= IO_PGTABLE_QUIRK_ARM_MTK_4GB;
dom->iop = alloc_io_pgtable_ops(ARM_V7S, &dom->cfg, data);
if (!dom->iop) {
dev_err(data->dev, "Failed to alloc io pgtable\n");
return -EINVAL;
}
dom->domain.pgsize_bitmap = dom->cfg.pgsize_bitmap;
writel(data->m4u_dom->cfg.arm_v7s_cfg.ttbr[0],
data->base + REG_MMU_PT_BASE_ADDR);
return 0;
}
static struct iommu_domain *mtk_iommu_domain_alloc(unsigned type)
{
struct mtk_iommu_domain *dom;
if (type != IOMMU_DOMAIN_DMA)
return NULL;
dom = kzalloc(sizeof(*dom), GFP_KERNEL);
if (!dom)
return NULL;
if (iommu_get_dma_cookie(&dom->domain)) {
kfree(dom);
return NULL;
}
dom->domain.geometry.aperture_start = 0;
dom->domain.geometry.aperture_end = DMA_BIT_MASK(32);
dom->domain.geometry.force_aperture = true;
return &dom->domain;
}
static void mtk_iommu_domain_free(struct iommu_domain *domain)
{
iommu_put_dma_cookie(domain);
kfree(to_mtk_domain(domain));
}
static int mtk_iommu_attach_device(struct iommu_domain *domain,
struct device *dev)
{
struct mtk_iommu_domain *dom = to_mtk_domain(domain);
struct mtk_iommu_client_priv *priv = dev->archdata.iommu;
struct mtk_iommu_data *data;
int ret;
if (!priv)
return -ENODEV;
data = dev_get_drvdata(priv->m4udev);
if (!data->m4u_dom) {
data->m4u_dom = dom;
ret = mtk_iommu_domain_finalise(data);
if (ret) {
data->m4u_dom = NULL;
return ret;
}
} else if (data->m4u_dom != dom) {
dev_err(dev, "try to attach into the error iommu domain\n");
return -EPERM;
}
mtk_iommu_config(data, dev, true);
return 0;
}
static void mtk_iommu_detach_device(struct iommu_domain *domain,
struct device *dev)
{
struct mtk_iommu_client_priv *priv = dev->archdata.iommu;
struct mtk_iommu_data *data;
if (!priv)
return;
data = dev_get_drvdata(priv->m4udev);
mtk_iommu_config(data, dev, false);
}
static int mtk_iommu_map(struct iommu_domain *domain, unsigned long iova,
phys_addr_t paddr, size_t size, int prot)
{
struct mtk_iommu_domain *dom = to_mtk_domain(domain);
unsigned long flags;
int ret;
spin_lock_irqsave(&dom->pgtlock, flags);
ret = dom->iop->map(dom->iop, iova, paddr, size, prot);
spin_unlock_irqrestore(&dom->pgtlock, flags);
return ret;
}
static size_t mtk_iommu_unmap(struct iommu_domain *domain,
unsigned long iova, size_t size)
{
struct mtk_iommu_domain *dom = to_mtk_domain(domain);
unsigned long flags;
size_t unmapsz;
spin_lock_irqsave(&dom->pgtlock, flags);
unmapsz = dom->iop->unmap(dom->iop, iova, size);
spin_unlock_irqrestore(&dom->pgtlock, flags);
return unmapsz;
}
static phys_addr_t mtk_iommu_iova_to_phys(struct iommu_domain *domain,
dma_addr_t iova)
{
struct mtk_iommu_domain *dom = to_mtk_domain(domain);
unsigned long flags;
phys_addr_t pa;
spin_lock_irqsave(&dom->pgtlock, flags);
pa = dom->iop->iova_to_phys(dom->iop, iova);
spin_unlock_irqrestore(&dom->pgtlock, flags);
return pa;
}
static int mtk_iommu_add_device(struct device *dev)
{
struct iommu_group *group;
if (!dev->archdata.iommu)
return -ENODEV;
group = iommu_group_get_for_dev(dev);
if (IS_ERR(group))
return PTR_ERR(group);
iommu_group_put(group);
return 0;
}
static void mtk_iommu_remove_device(struct device *dev)
{
struct mtk_iommu_client_priv *head, *cur, *next;
head = dev->archdata.iommu;
if (!head)
return;
list_for_each_entry_safe(cur, next, &head->client, client) {
list_del(&cur->client);
kfree(cur);
}
kfree(head);
dev->archdata.iommu = NULL;
iommu_group_remove_device(dev);
}
static struct iommu_group *mtk_iommu_device_group(struct device *dev)
{
struct mtk_iommu_data *data;
struct mtk_iommu_client_priv *priv;
priv = dev->archdata.iommu;
if (!priv)
return ERR_PTR(-ENODEV);
data = dev_get_drvdata(priv->m4udev);
if (!data->m4u_group) {
data->m4u_group = iommu_group_alloc();
if (IS_ERR(data->m4u_group))
dev_err(dev, "Failed to allocate M4U IOMMU group\n");
}
return data->m4u_group;
}
static int mtk_iommu_of_xlate(struct device *dev, struct of_phandle_args *args)
{
struct mtk_iommu_client_priv *head, *priv, *next;
struct platform_device *m4updev;
if (args->args_count != 1) {
dev_err(dev, "invalid #iommu-cells(%d) property for IOMMU\n",
args->args_count);
return -EINVAL;
}
if (!dev->archdata.iommu) {
m4updev = of_find_device_by_node(args->np);
of_node_put(args->np);
if (WARN_ON(!m4updev))
return -EINVAL;
head = kzalloc(sizeof(*head), GFP_KERNEL);
if (!head)
return -ENOMEM;
dev->archdata.iommu = head;
INIT_LIST_HEAD(&head->client);
head->m4udev = &m4updev->dev;
} else {
head = dev->archdata.iommu;
}
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
goto err_free_mem;
priv->mtk_m4u_id = args->args[0];
list_add_tail(&priv->client, &head->client);
return 0;
err_free_mem:
list_for_each_entry_safe(priv, next, &head->client, client)
kfree(priv);
kfree(head);
dev->archdata.iommu = NULL;
return -ENOMEM;
}
static int mtk_iommu_hw_init(const struct mtk_iommu_data *data)
{
u32 regval;
int ret;
ret = clk_prepare_enable(data->bclk);
if (ret) {
dev_err(data->dev, "Failed to enable iommu bclk(%d)\n", ret);
return ret;
}
regval = F_MMU_PREFETCH_RT_REPLACE_MOD |
F_MMU_TF_PROTECT_SEL(2);
writel_relaxed(regval, data->base + REG_MMU_CTRL_REG);
regval = F_L2_MULIT_HIT_EN |
F_TABLE_WALK_FAULT_INT_EN |
F_PREETCH_FIFO_OVERFLOW_INT_EN |
F_MISS_FIFO_OVERFLOW_INT_EN |
F_PREFETCH_FIFO_ERR_INT_EN |
F_MISS_FIFO_ERR_INT_EN;
writel_relaxed(regval, data->base + REG_MMU_INT_CONTROL0);
regval = F_INT_TRANSLATION_FAULT |
F_INT_MAIN_MULTI_HIT_FAULT |
F_INT_INVALID_PA_FAULT |
F_INT_ENTRY_REPLACEMENT_FAULT |
F_INT_TLB_MISS_FAULT |
F_INT_MISS_TRANSACTION_FIFO_FAULT |
F_INT_PRETETCH_TRANSATION_FIFO_FAULT;
writel_relaxed(regval, data->base + REG_MMU_INT_MAIN_CONTROL);
writel_relaxed(F_MMU_IVRP_PA_SET(data->protect_base, data->enable_4GB),
data->base + REG_MMU_IVRP_PADDR);
writel_relaxed(0, data->base + REG_MMU_DCM_DIS);
writel_relaxed(0, data->base + REG_MMU_STANDARD_AXI_MODE);
if (devm_request_irq(data->dev, data->irq, mtk_iommu_isr, 0,
dev_name(data->dev), (void *)data)) {
writel_relaxed(0, data->base + REG_MMU_PT_BASE_ADDR);
clk_disable_unprepare(data->bclk);
dev_err(data->dev, "Failed @ IRQ-%d Request\n", data->irq);
return -ENODEV;
}
return 0;
}
static int compare_of(struct device *dev, void *data)
{
return dev->of_node == data;
}
static int mtk_iommu_bind(struct device *dev)
{
struct mtk_iommu_data *data = dev_get_drvdata(dev);
return component_bind_all(dev, &data->smi_imu);
}
static void mtk_iommu_unbind(struct device *dev)
{
struct mtk_iommu_data *data = dev_get_drvdata(dev);
component_unbind_all(dev, &data->smi_imu);
}
static int mtk_iommu_probe(struct platform_device *pdev)
{
struct mtk_iommu_data *data;
struct device *dev = &pdev->dev;
struct resource *res;
struct component_match *match = NULL;
void *protect;
int i, larb_nr, ret;
data = devm_kzalloc(dev, sizeof(*data), GFP_KERNEL);
if (!data)
return -ENOMEM;
data->dev = dev;
protect = devm_kzalloc(dev, MTK_PROTECT_PA_ALIGN * 2, GFP_KERNEL);
if (!protect)
return -ENOMEM;
data->protect_base = ALIGN(virt_to_phys(protect), MTK_PROTECT_PA_ALIGN);
data->enable_4GB = !!(max_pfn > (0xffffffffUL >> PAGE_SHIFT));
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->base = devm_ioremap_resource(dev, res);
if (IS_ERR(data->base))
return PTR_ERR(data->base);
data->irq = platform_get_irq(pdev, 0);
if (data->irq < 0)
return data->irq;
data->bclk = devm_clk_get(dev, "bclk");
if (IS_ERR(data->bclk))
return PTR_ERR(data->bclk);
larb_nr = of_count_phandle_with_args(dev->of_node,
"mediatek,larbs", NULL);
if (larb_nr < 0)
return larb_nr;
data->smi_imu.larb_nr = larb_nr;
for (i = 0; i < larb_nr; i++) {
struct device_node *larbnode;
struct platform_device *plarbdev;
larbnode = of_parse_phandle(dev->of_node, "mediatek,larbs", i);
if (!larbnode)
return -EINVAL;
if (!of_device_is_available(larbnode))
continue;
plarbdev = of_find_device_by_node(larbnode);
of_node_put(larbnode);
if (!plarbdev) {
plarbdev = of_platform_device_create(
larbnode, NULL,
platform_bus_type.dev_root);
if (!plarbdev)
return -EPROBE_DEFER;
}
data->smi_imu.larb_imu[i].dev = &plarbdev->dev;
component_match_add(dev, &match, compare_of, larbnode);
}
platform_set_drvdata(pdev, data);
ret = mtk_iommu_hw_init(data);
if (ret)
return ret;
if (!iommu_present(&platform_bus_type))
bus_set_iommu(&platform_bus_type, &mtk_iommu_ops);
return component_master_add_with_match(dev, &mtk_iommu_com_ops, match);
}
static int mtk_iommu_remove(struct platform_device *pdev)
{
struct mtk_iommu_data *data = platform_get_drvdata(pdev);
if (iommu_present(&platform_bus_type))
bus_set_iommu(&platform_bus_type, NULL);
free_io_pgtable_ops(data->m4u_dom->iop);
clk_disable_unprepare(data->bclk);
devm_free_irq(&pdev->dev, data->irq, data);
component_master_del(&pdev->dev, &mtk_iommu_com_ops);
return 0;
}
static int __maybe_unused mtk_iommu_suspend(struct device *dev)
{
struct mtk_iommu_data *data = dev_get_drvdata(dev);
struct mtk_iommu_suspend_reg *reg = &data->reg;
void __iomem *base = data->base;
reg->standard_axi_mode = readl_relaxed(base +
REG_MMU_STANDARD_AXI_MODE);
reg->dcm_dis = readl_relaxed(base + REG_MMU_DCM_DIS);
reg->ctrl_reg = readl_relaxed(base + REG_MMU_CTRL_REG);
reg->int_control0 = readl_relaxed(base + REG_MMU_INT_CONTROL0);
reg->int_main_control = readl_relaxed(base + REG_MMU_INT_MAIN_CONTROL);
return 0;
}
static int __maybe_unused mtk_iommu_resume(struct device *dev)
{
struct mtk_iommu_data *data = dev_get_drvdata(dev);
struct mtk_iommu_suspend_reg *reg = &data->reg;
void __iomem *base = data->base;
writel_relaxed(data->m4u_dom->cfg.arm_v7s_cfg.ttbr[0],
base + REG_MMU_PT_BASE_ADDR);
writel_relaxed(reg->standard_axi_mode,
base + REG_MMU_STANDARD_AXI_MODE);
writel_relaxed(reg->dcm_dis, base + REG_MMU_DCM_DIS);
writel_relaxed(reg->ctrl_reg, base + REG_MMU_CTRL_REG);
writel_relaxed(reg->int_control0, base + REG_MMU_INT_CONTROL0);
writel_relaxed(reg->int_main_control, base + REG_MMU_INT_MAIN_CONTROL);
writel_relaxed(F_MMU_IVRP_PA_SET(data->protect_base, data->enable_4GB),
base + REG_MMU_IVRP_PADDR);
return 0;
}
static int mtk_iommu_init_fn(struct device_node *np)
{
int ret;
struct platform_device *pdev;
pdev = of_platform_device_create(np, NULL, platform_bus_type.dev_root);
if (!pdev)
return -ENOMEM;
ret = platform_driver_register(&mtk_iommu_driver);
if (ret) {
pr_err("%s: Failed to register driver\n", __func__);
return ret;
}
of_iommu_set_ops(np, &mtk_iommu_ops);
return 0;
}
