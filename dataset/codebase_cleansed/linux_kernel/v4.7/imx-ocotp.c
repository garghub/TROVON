static int imx_ocotp_read(void *context, unsigned int offset,
void *val, size_t bytes)
{
struct ocotp_priv *priv = context;
unsigned int count;
u32 *buf = val;
int i;
u32 index;
index = offset >> 2;
count = bytes >> 2;
if (count > (priv->nregs - index))
count = priv->nregs - index;
for (i = index; i < (index + count); i++)
*buf++ = readl(priv->base + 0x400 + i * 0x10);
return 0;
}
static int imx_ocotp_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id;
struct device *dev = &pdev->dev;
struct resource *res;
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
imx_ocotp_nvmem_config.size = 4 * priv->nregs;
imx_ocotp_nvmem_config.dev = dev;
imx_ocotp_nvmem_config.priv = priv;
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
