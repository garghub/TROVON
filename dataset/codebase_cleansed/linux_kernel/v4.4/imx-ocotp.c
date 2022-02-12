static int imx_ocotp_read(void *context, const void *reg, size_t reg_size,
void *val, size_t val_size)
{
struct ocotp_priv *priv = context;
unsigned int offset = *(u32 *)reg;
unsigned int count;
int i;
u32 index;
index = offset >> 2;
count = val_size >> 2;
if (count > (priv->nregs - index))
count = priv->nregs - index;
for (i = index; i < (index + count); i++) {
*(u32 *)val = readl(priv->base + 0x400 + i * 0x10);
val += 4;
}
return (i - index) * 4;
}
static int imx_ocotp_write(void *context, const void *data, size_t count)
{
return 0;
}
static bool imx_ocotp_writeable_reg(struct device *dev, unsigned int reg)
{
return false;
}
static int imx_ocotp_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id;
struct device *dev = &pdev->dev;
struct resource *res;
struct regmap *regmap;
struct ocotp_priv *priv;
struct nvmem_device *nvmem;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap_resource(dev, res);
if (IS_ERR(priv->base))
return PTR_ERR(priv->base);
of_id = of_match_device(imx_ocotp_dt_ids, dev);
priv->nregs = (unsigned int)of_id->data;
imx_ocotp_regmap_config.max_register = 4 * priv->nregs - 4;
regmap = devm_regmap_init(dev, &imx_ocotp_bus, priv,
&imx_ocotp_regmap_config);
if (IS_ERR(regmap)) {
dev_err(dev, "regmap init failed\n");
return PTR_ERR(regmap);
}
imx_ocotp_nvmem_config.dev = dev;
nvmem = nvmem_register(&imx_ocotp_nvmem_config);
if (IS_ERR(nvmem))
return PTR_ERR(nvmem);
platform_set_drvdata(pdev, nvmem);
return 0;
}
static int imx_ocotp_remove(struct platform_device *pdev)
{
struct nvmem_device *nvmem = platform_get_drvdata(pdev);
return nvmem_unregister(nvmem);
}
