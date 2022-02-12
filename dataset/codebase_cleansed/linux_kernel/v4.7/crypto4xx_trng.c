static int ppc4xx_trng_data_present(struct hwrng *rng, int wait)
{
struct crypto4xx_device *dev = (void *)rng->priv;
int busy, i, present = 0;
for (i = 0; i < 20; i++) {
busy = (in_le32(dev->trng_base + PPC4XX_TRNG_STAT) &
PPC4XX_TRNG_STAT_B);
if (!busy || !wait) {
present = 1;
break;
}
udelay(10);
}
return present;
}
static int ppc4xx_trng_data_read(struct hwrng *rng, u32 *data)
{
struct crypto4xx_device *dev = (void *)rng->priv;
*data = in_le32(dev->trng_base + PPC4XX_TRNG_DATA);
return 4;
}
static void ppc4xx_trng_enable(struct crypto4xx_device *dev, bool enable)
{
u32 device_ctrl;
device_ctrl = readl(dev->ce_base + CRYPTO4XX_DEVICE_CTRL);
if (enable)
device_ctrl |= PPC4XX_TRNG_EN;
else
device_ctrl &= ~PPC4XX_TRNG_EN;
writel(device_ctrl, dev->ce_base + CRYPTO4XX_DEVICE_CTRL);
}
void ppc4xx_trng_probe(struct crypto4xx_core_device *core_dev)
{
struct crypto4xx_device *dev = core_dev->dev;
struct device_node *trng = NULL;
struct hwrng *rng = NULL;
int err;
trng = of_find_matching_node(NULL, ppc4xx_trng_match);
if (!trng || !of_device_is_available(trng))
return;
dev->trng_base = of_iomap(trng, 0);
of_node_put(trng);
if (!dev->trng_base)
goto err_out;
rng = kzalloc(sizeof(*rng), GFP_KERNEL);
if (!rng)
goto err_out;
rng->name = MODULE_NAME;
rng->data_present = ppc4xx_trng_data_present;
rng->data_read = ppc4xx_trng_data_read;
rng->priv = (unsigned long) dev;
core_dev->trng = rng;
ppc4xx_trng_enable(dev, true);
out_le32(dev->trng_base + PPC4XX_TRNG_CTRL, PPC4XX_TRNG_CTRL_DALM);
err = devm_hwrng_register(core_dev->device, core_dev->trng);
if (err) {
ppc4xx_trng_enable(dev, false);
dev_err(core_dev->device, "failed to register hwrng (%d).\n",
err);
goto err_out;
}
return;
err_out:
of_node_put(trng);
iounmap(dev->trng_base);
kfree(rng);
dev->trng_base = NULL;
core_dev->trng = NULL;
}
void ppc4xx_trng_remove(struct crypto4xx_core_device *core_dev)
{
if (core_dev && core_dev->trng) {
struct crypto4xx_device *dev = core_dev->dev;
devm_hwrng_unregister(core_dev->device, core_dev->trng);
ppc4xx_trng_enable(dev, false);
iounmap(dev->trng_base);
kfree(core_dev->trng);
}
}
