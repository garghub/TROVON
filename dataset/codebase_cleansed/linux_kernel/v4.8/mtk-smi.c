static int mtk_smi_enable(const struct mtk_smi *smi)
{
int ret;
ret = pm_runtime_get_sync(smi->dev);
if (ret < 0)
return ret;
ret = clk_prepare_enable(smi->clk_apb);
if (ret)
goto err_put_pm;
ret = clk_prepare_enable(smi->clk_smi);
if (ret)
goto err_disable_apb;
return 0;
err_disable_apb:
clk_disable_unprepare(smi->clk_apb);
err_put_pm:
pm_runtime_put_sync(smi->dev);
return ret;
}
static void mtk_smi_disable(const struct mtk_smi *smi)
{
clk_disable_unprepare(smi->clk_smi);
clk_disable_unprepare(smi->clk_apb);
pm_runtime_put_sync(smi->dev);
}
int mtk_smi_larb_get(struct device *larbdev)
{
struct mtk_smi_larb *larb = dev_get_drvdata(larbdev);
const struct mtk_smi_larb_gen *larb_gen = larb->larb_gen;
struct mtk_smi *common = dev_get_drvdata(larb->smi_common_dev);
int ret;
ret = mtk_smi_enable(common);
if (ret)
return ret;
ret = mtk_smi_enable(&larb->smi);
if (ret) {
mtk_smi_disable(common);
return ret;
}
larb_gen->config_port(larbdev);
return 0;
}
void mtk_smi_larb_put(struct device *larbdev)
{
struct mtk_smi_larb *larb = dev_get_drvdata(larbdev);
struct mtk_smi *common = dev_get_drvdata(larb->smi_common_dev);
mtk_smi_disable(&larb->smi);
mtk_smi_disable(common);
}
static int
mtk_smi_larb_bind(struct device *dev, struct device *master, void *data)
{
struct mtk_smi_larb *larb = dev_get_drvdata(dev);
struct mtk_smi_iommu *smi_iommu = data;
unsigned int i;
for (i = 0; i < smi_iommu->larb_nr; i++) {
if (dev == smi_iommu->larb_imu[i].dev) {
larb->mmu = &smi_iommu->larb_imu[i].mmu;
return 0;
}
}
return -ENODEV;
}
static void mtk_smi_larb_config_port(struct device *dev)
{
struct mtk_smi_larb *larb = dev_get_drvdata(dev);
writel(*larb->mmu, larb->base + SMI_LARB_MMU_EN);
}
static void mtk_smi_larb_config_port_gen1(struct device *dev)
{
struct mtk_smi_larb *larb = dev_get_drvdata(dev);
const struct mtk_smi_larb_gen *larb_gen = larb->larb_gen;
struct mtk_smi *common = dev_get_drvdata(larb->smi_common_dev);
int i, m4u_port_id, larb_port_num;
u32 sec_con_val, reg_val;
m4u_port_id = larb_gen->port_in_larb[larb->larbid];
larb_port_num = larb_gen->port_in_larb[larb->larbid + 1]
- larb_gen->port_in_larb[larb->larbid];
for (i = 0; i < larb_port_num; i++, m4u_port_id++) {
if (*larb->mmu & BIT(i)) {
sec_con_val = SMI_SECUR_CON_VAL_VIRT(m4u_port_id);
} else {
continue;
}
reg_val = readl(common->smi_ao_base
+ REG_SMI_SECUR_CON_ADDR(m4u_port_id));
reg_val &= SMI_SECUR_CON_VAL_MSK(m4u_port_id);
reg_val |= sec_con_val;
reg_val |= SMI_SECUR_CON_VAL_DOMAIN(m4u_port_id);
writel(reg_val,
common->smi_ao_base
+ REG_SMI_SECUR_CON_ADDR(m4u_port_id));
}
}
static void
mtk_smi_larb_unbind(struct device *dev, struct device *master, void *data)
{
}
static int mtk_smi_larb_probe(struct platform_device *pdev)
{
struct mtk_smi_larb *larb;
struct resource *res;
struct device *dev = &pdev->dev;
struct device_node *smi_node;
struct platform_device *smi_pdev;
const struct of_device_id *of_id;
if (!dev->pm_domain)
return -EPROBE_DEFER;
of_id = of_match_node(mtk_smi_larb_of_ids, pdev->dev.of_node);
if (!of_id)
return -EINVAL;
larb = devm_kzalloc(dev, sizeof(*larb), GFP_KERNEL);
if (!larb)
return -ENOMEM;
larb->larb_gen = of_id->data;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
larb->base = devm_ioremap_resource(dev, res);
if (IS_ERR(larb->base))
return PTR_ERR(larb->base);
larb->smi.clk_apb = devm_clk_get(dev, "apb");
if (IS_ERR(larb->smi.clk_apb))
return PTR_ERR(larb->smi.clk_apb);
larb->smi.clk_smi = devm_clk_get(dev, "smi");
if (IS_ERR(larb->smi.clk_smi))
return PTR_ERR(larb->smi.clk_smi);
larb->smi.dev = dev;
smi_node = of_parse_phandle(dev->of_node, "mediatek,smi", 0);
if (!smi_node)
return -EINVAL;
smi_pdev = of_find_device_by_node(smi_node);
of_node_put(smi_node);
if (smi_pdev) {
larb->smi_common_dev = &smi_pdev->dev;
} else {
dev_err(dev, "Failed to get the smi_common device\n");
return -EINVAL;
}
pm_runtime_enable(dev);
platform_set_drvdata(pdev, larb);
return component_add(dev, &mtk_smi_larb_component_ops);
}
static int mtk_smi_larb_remove(struct platform_device *pdev)
{
pm_runtime_disable(&pdev->dev);
component_del(&pdev->dev, &mtk_smi_larb_component_ops);
return 0;
}
static int mtk_smi_common_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct mtk_smi *common;
struct resource *res;
const struct of_device_id *of_id;
enum mtk_smi_gen smi_gen;
if (!dev->pm_domain)
return -EPROBE_DEFER;
common = devm_kzalloc(dev, sizeof(*common), GFP_KERNEL);
if (!common)
return -ENOMEM;
common->dev = dev;
common->clk_apb = devm_clk_get(dev, "apb");
if (IS_ERR(common->clk_apb))
return PTR_ERR(common->clk_apb);
common->clk_smi = devm_clk_get(dev, "smi");
if (IS_ERR(common->clk_smi))
return PTR_ERR(common->clk_smi);
of_id = of_match_node(mtk_smi_common_of_ids, pdev->dev.of_node);
if (!of_id)
return -EINVAL;
smi_gen = (enum mtk_smi_gen)of_id->data;
if (smi_gen == MTK_SMI_GEN1) {
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
common->smi_ao_base = devm_ioremap_resource(dev, res);
if (IS_ERR(common->smi_ao_base))
return PTR_ERR(common->smi_ao_base);
common->clk_async = devm_clk_get(dev, "async");
if (IS_ERR(common->clk_async))
return PTR_ERR(common->clk_async);
clk_prepare_enable(common->clk_async);
}
pm_runtime_enable(dev);
platform_set_drvdata(pdev, common);
return 0;
}
static int mtk_smi_common_remove(struct platform_device *pdev)
{
pm_runtime_disable(&pdev->dev);
return 0;
}
static int __init mtk_smi_init(void)
{
int ret;
ret = platform_driver_register(&mtk_smi_common_driver);
if (ret != 0) {
pr_err("Failed to register SMI driver\n");
return ret;
}
ret = platform_driver_register(&mtk_smi_larb_driver);
if (ret != 0) {
pr_err("Failed to register SMI-LARB driver\n");
goto err_unreg_smi;
}
return ret;
err_unreg_smi:
platform_driver_unregister(&mtk_smi_common_driver);
return ret;
}
