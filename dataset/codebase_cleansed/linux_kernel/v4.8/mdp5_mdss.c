static inline void mdss_write(struct msm_mdss *mdss, u32 reg, u32 data)
{
msm_writel(data, mdss->mmio + reg);
}
static inline u32 mdss_read(struct msm_mdss *mdss, u32 reg)
{
return msm_readl(mdss->mmio + reg);
}
static irqreturn_t mdss_irq(int irq, void *arg)
{
struct msm_mdss *mdss = arg;
u32 intr;
intr = mdss_read(mdss, REG_MDSS_HW_INTR_STATUS);
VERB("intr=%08x", intr);
while (intr) {
irq_hw_number_t hwirq = fls(intr) - 1;
generic_handle_irq(irq_find_mapping(
mdss->irqcontroller.domain, hwirq));
intr &= ~(1 << hwirq);
}
return IRQ_HANDLED;
}
static void mdss_hw_mask_irq(struct irq_data *irqd)
{
struct msm_mdss *mdss = irq_data_get_irq_chip_data(irqd);
smp_mb__before_atomic();
clear_bit(irqd->hwirq, &mdss->irqcontroller.enabled_mask);
smp_mb__after_atomic();
}
static void mdss_hw_unmask_irq(struct irq_data *irqd)
{
struct msm_mdss *mdss = irq_data_get_irq_chip_data(irqd);
smp_mb__before_atomic();
set_bit(irqd->hwirq, &mdss->irqcontroller.enabled_mask);
smp_mb__after_atomic();
}
static int mdss_hw_irqdomain_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hwirq)
{
struct msm_mdss *mdss = d->host_data;
if (!(VALID_IRQS & (1 << hwirq)))
return -EPERM;
irq_set_chip_and_handler(irq, &mdss_hw_irq_chip, handle_level_irq);
irq_set_chip_data(irq, mdss);
return 0;
}
static int mdss_irq_domain_init(struct msm_mdss *mdss)
{
struct device *dev = mdss->dev->dev;
struct irq_domain *d;
d = irq_domain_add_linear(dev->of_node, 32, &mdss_hw_irqdomain_ops,
mdss);
if (!d) {
dev_err(dev, "mdss irq domain add failed\n");
return -ENXIO;
}
mdss->irqcontroller.enabled_mask = 0;
mdss->irqcontroller.domain = d;
return 0;
}
void msm_mdss_destroy(struct drm_device *dev)
{
struct msm_drm_private *priv = dev->dev_private;
struct msm_mdss *mdss = priv->mdss;
if (!mdss)
return;
irq_domain_remove(mdss->irqcontroller.domain);
mdss->irqcontroller.domain = NULL;
regulator_disable(mdss->vdd);
pm_runtime_put_sync(dev->dev);
pm_runtime_disable(dev->dev);
}
int msm_mdss_init(struct drm_device *dev)
{
struct platform_device *pdev = dev->platformdev;
struct msm_drm_private *priv = dev->dev_private;
struct msm_mdss *mdss;
int ret;
DBG("");
if (!of_device_is_compatible(dev->dev->of_node, "qcom,mdss"))
return 0;
mdss = devm_kzalloc(dev->dev, sizeof(*mdss), GFP_KERNEL);
if (!mdss) {
ret = -ENOMEM;
goto fail;
}
mdss->dev = dev;
mdss->mmio = msm_ioremap(pdev, "mdss_phys", "MDSS");
if (IS_ERR(mdss->mmio)) {
ret = PTR_ERR(mdss->mmio);
goto fail;
}
mdss->vbif = msm_ioremap(pdev, "vbif_phys", "VBIF");
if (IS_ERR(mdss->vbif)) {
ret = PTR_ERR(mdss->vbif);
goto fail;
}
mdss->vdd = devm_regulator_get(dev->dev, "vdd");
if (IS_ERR(mdss->vdd)) {
ret = PTR_ERR(mdss->vdd);
goto fail;
}
ret = regulator_enable(mdss->vdd);
if (ret) {
dev_err(dev->dev, "failed to enable regulator vdd: %d\n",
ret);
goto fail;
}
ret = devm_request_irq(dev->dev, platform_get_irq(pdev, 0),
mdss_irq, 0, "mdss_isr", mdss);
if (ret) {
dev_err(dev->dev, "failed to init irq: %d\n", ret);
goto fail_irq;
}
ret = mdss_irq_domain_init(mdss);
if (ret) {
dev_err(dev->dev, "failed to init sub-block irqs: %d\n", ret);
goto fail_irq;
}
priv->mdss = mdss;
pm_runtime_enable(dev->dev);
pm_runtime_get_sync(dev->dev);
return 0;
fail_irq:
regulator_disable(mdss->vdd);
fail:
return ret;
}
