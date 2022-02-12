static inline u32 omap_rng_read(struct omap_rng_dev *priv, u16 reg)
{
return __raw_readl(priv->base + priv->pdata->regs[reg]);
}
static inline void omap_rng_write(struct omap_rng_dev *priv, u16 reg,
u32 val)
{
__raw_writel(val, priv->base + priv->pdata->regs[reg]);
}
static int omap_rng_do_read(struct hwrng *rng, void *data, size_t max,
bool wait)
{
struct omap_rng_dev *priv;
int i, present;
priv = (struct omap_rng_dev *)rng->priv;
if (max < priv->pdata->data_size)
return 0;
for (i = 0; i < 20; i++) {
present = priv->pdata->data_present(priv);
if (present || !wait)
break;
udelay(10);
}
if (!present)
return 0;
memcpy_fromio(data, priv->base + priv->pdata->regs[RNG_OUTPUT_0_REG],
priv->pdata->data_size);
if (priv->pdata->regs[RNG_INTACK_REG])
omap_rng_write(priv, RNG_INTACK_REG, RNG_REG_INTACK_RDY_MASK);
return priv->pdata->data_size;
}
static int omap_rng_init(struct hwrng *rng)
{
struct omap_rng_dev *priv;
priv = (struct omap_rng_dev *)rng->priv;
return priv->pdata->init(priv);
}
static void omap_rng_cleanup(struct hwrng *rng)
{
struct omap_rng_dev *priv;
priv = (struct omap_rng_dev *)rng->priv;
priv->pdata->cleanup(priv);
}
static inline u32 omap2_rng_data_present(struct omap_rng_dev *priv)
{
return omap_rng_read(priv, RNG_STATUS_REG) ? 0 : 1;
}
static int omap2_rng_init(struct omap_rng_dev *priv)
{
omap_rng_write(priv, RNG_SYSCONFIG_REG, 0x1);
return 0;
}
static void omap2_rng_cleanup(struct omap_rng_dev *priv)
{
omap_rng_write(priv, RNG_SYSCONFIG_REG, 0x0);
}
static inline u32 omap4_rng_data_present(struct omap_rng_dev *priv)
{
return omap_rng_read(priv, RNG_STATUS_REG) & RNG_REG_STATUS_RDY;
}
static int eip76_rng_init(struct omap_rng_dev *priv)
{
u32 val;
if (omap_rng_read(priv, RNG_CONTROL_REG) & RNG_CONTROL_ENABLE_TRNG_MASK)
return 0;
val = 0x5 << RNG_CONFIG_MIN_REFIL_CYCLES_SHIFT;
val |= RNG_CONFIG_MAX_REFIL_CYCLES << RNG_CONFIG_MAX_REFIL_CYCLES_SHIFT;
omap_rng_write(priv, RNG_CONFIG_REG, val);
omap_rng_write(priv, RNG_FRODETUNE_REG, 0x0);
omap_rng_write(priv, RNG_FROENABLE_REG, RNG_REG_FROENABLE_MASK);
val = RNG_CONTROL_ENABLE_TRNG_MASK;
omap_rng_write(priv, RNG_CONTROL_REG, val);
return 0;
}
static int omap4_rng_init(struct omap_rng_dev *priv)
{
u32 val;
if (omap_rng_read(priv, RNG_CONTROL_REG) & RNG_CONTROL_ENABLE_TRNG_MASK)
return 0;
val = RNG_CONFIG_MIN_REFIL_CYCLES << RNG_CONFIG_MIN_REFIL_CYCLES_SHIFT;
val |= RNG_CONFIG_MAX_REFIL_CYCLES << RNG_CONFIG_MAX_REFIL_CYCLES_SHIFT;
omap_rng_write(priv, RNG_CONFIG_REG, val);
omap_rng_write(priv, RNG_FRODETUNE_REG, 0x0);
omap_rng_write(priv, RNG_FROENABLE_REG, RNG_REG_FROENABLE_MASK);
val = RNG_ALARM_THRESHOLD << RNG_ALARMCNT_ALARM_TH_SHIFT;
val |= RNG_SHUTDOWN_THRESHOLD << RNG_ALARMCNT_SHUTDOWN_TH_SHIFT;
omap_rng_write(priv, RNG_ALARMCNT_REG, val);
val = RNG_CONTROL_STARTUP_CYCLES << RNG_CONTROL_STARTUP_CYCLES_SHIFT;
val |= RNG_CONTROL_ENABLE_TRNG_MASK;
omap_rng_write(priv, RNG_CONTROL_REG, val);
return 0;
}
static void omap4_rng_cleanup(struct omap_rng_dev *priv)
{
int val;
val = omap_rng_read(priv, RNG_CONTROL_REG);
val &= ~RNG_CONTROL_ENABLE_TRNG_MASK;
omap_rng_write(priv, RNG_CONTROL_REG, val);
}
static irqreturn_t omap4_rng_irq(int irq, void *dev_id)
{
struct omap_rng_dev *priv = dev_id;
u32 fro_detune, fro_enable;
omap_rng_write(priv, RNG_ALARMMASK_REG, 0x0);
omap_rng_write(priv, RNG_ALARMSTOP_REG, 0x0);
fro_enable = omap_rng_read(priv, RNG_FROENABLE_REG);
fro_detune = ~fro_enable & RNG_REG_FRODETUNE_MASK;
fro_detune = fro_detune | omap_rng_read(priv, RNG_FRODETUNE_REG);
fro_enable = RNG_REG_FROENABLE_MASK;
omap_rng_write(priv, RNG_FRODETUNE_REG, fro_detune);
omap_rng_write(priv, RNG_FROENABLE_REG, fro_enable);
omap_rng_write(priv, RNG_INTACK_REG, RNG_REG_INTACK_SHUTDOWN_OFLO_MASK);
return IRQ_HANDLED;
}
static int of_get_omap_rng_device_details(struct omap_rng_dev *priv,
struct platform_device *pdev)
{
const struct of_device_id *match;
struct device *dev = &pdev->dev;
int irq, err;
match = of_match_device(of_match_ptr(omap_rng_of_match), dev);
if (!match) {
dev_err(dev, "no compatible OF match\n");
return -EINVAL;
}
priv->pdata = match->data;
if (of_device_is_compatible(dev->of_node, "ti,omap4-rng") ||
of_device_is_compatible(dev->of_node, "inside-secure,safexcel-eip76")) {
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(dev, "%s: error getting IRQ resource - %d\n",
__func__, irq);
return irq;
}
err = devm_request_irq(dev, irq, omap4_rng_irq,
IRQF_TRIGGER_NONE, dev_name(dev), priv);
if (err) {
dev_err(dev, "unable to request irq %d, err = %d\n",
irq, err);
return err;
}
if (priv->pdata->regs[RNG_INTMASK_REG])
omap_rng_write(priv, RNG_INTMASK_REG,
RNG_SHUTDOWN_OFLO_MASK);
else
omap_rng_write(priv, RNG_CONTROL_REG,
RNG_SHUTDOWN_OFLO_MASK);
}
return 0;
}
static int of_get_omap_rng_device_details(struct omap_rng_dev *omap_rng,
struct platform_device *pdev)
{
return -EINVAL;
}
static int get_omap_rng_device_details(struct omap_rng_dev *omap_rng)
{
omap_rng->pdata = &omap2_rng_pdata;
return 0;
}
static int omap_rng_probe(struct platform_device *pdev)
{
struct omap_rng_dev *priv;
struct resource *res;
struct device *dev = &pdev->dev;
int ret;
priv = devm_kzalloc(dev, sizeof(struct omap_rng_dev), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->rng.read = omap_rng_do_read;
priv->rng.init = omap_rng_init;
priv->rng.cleanup = omap_rng_cleanup;
priv->rng.priv = (unsigned long)priv;
platform_set_drvdata(pdev, priv);
priv->dev = dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap_resource(dev, res);
if (IS_ERR(priv->base)) {
ret = PTR_ERR(priv->base);
goto err_ioremap;
}
priv->rng.name = devm_kstrdup(dev, dev_name(dev), GFP_KERNEL);
if (!priv->rng.name) {
ret = -ENOMEM;
goto err_ioremap;
}
pm_runtime_enable(&pdev->dev);
ret = pm_runtime_get_sync(&pdev->dev);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to runtime_get device: %d\n", ret);
pm_runtime_put_noidle(&pdev->dev);
goto err_ioremap;
}
priv->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(priv->clk) && PTR_ERR(priv->clk) == -EPROBE_DEFER)
return -EPROBE_DEFER;
if (!IS_ERR(priv->clk)) {
ret = clk_prepare_enable(priv->clk);
if (ret) {
dev_err(&pdev->dev,
"Unable to enable the clk: %d\n", ret);
goto err_register;
}
}
ret = (dev->of_node) ? of_get_omap_rng_device_details(priv, pdev) :
get_omap_rng_device_details(priv);
if (ret)
goto err_register;
ret = hwrng_register(&priv->rng);
if (ret)
goto err_register;
dev_info(&pdev->dev, "Random Number Generator ver. %02x\n",
omap_rng_read(priv, RNG_REV_REG));
return 0;
err_register:
priv->base = NULL;
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
if (!IS_ERR(priv->clk))
clk_disable_unprepare(priv->clk);
err_ioremap:
dev_err(dev, "initialization failed.\n");
return ret;
}
static int omap_rng_remove(struct platform_device *pdev)
{
struct omap_rng_dev *priv = platform_get_drvdata(pdev);
hwrng_unregister(&priv->rng);
priv->pdata->cleanup(priv);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
if (!IS_ERR(priv->clk))
clk_disable_unprepare(priv->clk);
return 0;
}
static int __maybe_unused omap_rng_suspend(struct device *dev)
{
struct omap_rng_dev *priv = dev_get_drvdata(dev);
priv->pdata->cleanup(priv);
pm_runtime_put_sync(dev);
return 0;
}
static int __maybe_unused omap_rng_resume(struct device *dev)
{
struct omap_rng_dev *priv = dev_get_drvdata(dev);
int ret;
ret = pm_runtime_get_sync(dev);
if (ret < 0) {
dev_err(dev, "Failed to runtime_get device: %d\n", ret);
pm_runtime_put_noidle(dev);
return ret;
}
priv->pdata->init(priv);
return 0;
}
