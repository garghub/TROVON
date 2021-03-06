static int sh_csi2_try_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct sh_csi2 *priv = container_of(sd, struct sh_csi2, subdev);
struct sh_csi2_pdata *pdata = priv->pdev->dev.platform_data;
if (mf->width > 8188)
mf->width = 8188;
else if (mf->width & 1)
mf->width &= ~1;
switch (pdata->type) {
case SH_CSI2C:
switch (mf->code) {
case V4L2_MBUS_FMT_UYVY8_2X8:
case V4L2_MBUS_FMT_YUYV8_1_5X8:
case V4L2_MBUS_FMT_Y8_1X8:
case V4L2_MBUS_FMT_SBGGR8_1X8:
case V4L2_MBUS_FMT_SGRBG8_1X8:
break;
default:
mf->code = V4L2_MBUS_FMT_YUYV8_2X8;
}
break;
case SH_CSI2I:
switch (mf->code) {
case V4L2_MBUS_FMT_Y8_1X8:
case V4L2_MBUS_FMT_SBGGR8_1X8:
case V4L2_MBUS_FMT_SGRBG8_1X8:
case V4L2_MBUS_FMT_SBGGR10_1X10:
case V4L2_MBUS_FMT_SBGGR12_1X12:
break;
default:
mf->code = V4L2_MBUS_FMT_SBGGR8_1X8;
}
break;
}
return 0;
}
static int sh_csi2_s_fmt(struct v4l2_subdev *sd,
struct v4l2_mbus_framefmt *mf)
{
struct sh_csi2 *priv = container_of(sd, struct sh_csi2, subdev);
u32 tmp = (priv->client->channel & 3) << 8;
dev_dbg(sd->v4l2_dev->dev, "%s(%u)\n", __func__, mf->code);
if (mf->width > 8188 || mf->width & 1)
return -EINVAL;
switch (mf->code) {
case V4L2_MBUS_FMT_UYVY8_2X8:
tmp |= 0x1e;
break;
case V4L2_MBUS_FMT_YUYV8_1_5X8:
tmp |= 0x18;
break;
case V4L2_MBUS_FMT_RGB555_2X8_PADHI_BE:
tmp |= 0x21;
break;
case V4L2_MBUS_FMT_RGB565_2X8_BE:
tmp |= 0x22;
break;
case V4L2_MBUS_FMT_Y8_1X8:
case V4L2_MBUS_FMT_SBGGR8_1X8:
case V4L2_MBUS_FMT_SGRBG8_1X8:
tmp |= 0x2a;
break;
default:
return -EINVAL;
}
iowrite32(tmp, priv->base + SH_CSI2_VCDT);
return 0;
}
static void sh_csi2_hwinit(struct sh_csi2 *priv)
{
struct sh_csi2_pdata *pdata = priv->pdev->dev.platform_data;
__u32 tmp = 0x10;
iowrite32(0x00000001, priv->base + SH_CSI2_TREF);
iowrite32(0x00000001, priv->base + SH_CSI2_SRST);
udelay(5);
iowrite32(0x00000000, priv->base + SH_CSI2_SRST);
if (priv->client->lanes & 3)
tmp |= priv->client->lanes & 3;
else
tmp |= 3;
if (priv->client->phy == SH_CSI2_PHY_MAIN)
tmp |= 0x8000;
iowrite32(tmp, priv->base + SH_CSI2_PHYCNT);
tmp = 0;
if (pdata->flags & SH_CSI2_ECC)
tmp |= 2;
if (pdata->flags & SH_CSI2_CRC)
tmp |= 1;
iowrite32(tmp, priv->base + SH_CSI2_CHKSUM);
}
static int sh_csi2_set_bus_param(struct soc_camera_device *icd,
unsigned long flags)
{
return 0;
}
static unsigned long sh_csi2_query_bus_param(struct soc_camera_device *icd)
{
struct soc_camera_link *icl = to_soc_camera_link(icd);
const unsigned long flags = SOCAM_PCLK_SAMPLE_RISING |
SOCAM_HSYNC_ACTIVE_HIGH | SOCAM_VSYNC_ACTIVE_HIGH |
SOCAM_MASTER | SOCAM_DATAWIDTH_8 | SOCAM_DATA_ACTIVE_HIGH;
return soc_camera_apply_sensor_flags(icl, flags);
}
static int sh_csi2_client_connect(struct sh_csi2 *priv)
{
struct sh_csi2_pdata *pdata = priv->pdev->dev.platform_data;
struct v4l2_subdev *sd, *csi2_sd = &priv->subdev;
struct soc_camera_device *icd = NULL;
struct device *dev = v4l2_get_subdevdata(&priv->subdev);
int i;
v4l2_device_for_each_subdev(sd, csi2_sd->v4l2_dev)
if (sd->grp_id) {
icd = (struct soc_camera_device *)sd->grp_id;
break;
}
if (!icd)
return -EINVAL;
for (i = 0; i < pdata->num_clients; i++)
if (&pdata->clients[i].pdev->dev == icd->pdev)
break;
dev_dbg(dev, "%s(%p): found #%d\n", __func__, dev, i);
if (i == pdata->num_clients)
return -ENODEV;
priv->client = pdata->clients + i;
priv->set_bus_param = icd->ops->set_bus_param;
priv->query_bus_param = icd->ops->query_bus_param;
icd->ops->set_bus_param = sh_csi2_set_bus_param;
icd->ops->query_bus_param = sh_csi2_query_bus_param;
csi2_sd->grp_id = (long)icd;
pm_runtime_get_sync(dev);
sh_csi2_hwinit(priv);
return 0;
}
static void sh_csi2_client_disconnect(struct sh_csi2 *priv)
{
struct soc_camera_device *icd = (struct soc_camera_device *)priv->subdev.grp_id;
priv->client = NULL;
priv->subdev.grp_id = 0;
icd->ops->set_bus_param = priv->set_bus_param;
icd->ops->query_bus_param = priv->query_bus_param;
priv->set_bus_param = NULL;
priv->query_bus_param = NULL;
pm_runtime_put(v4l2_get_subdevdata(&priv->subdev));
}
static int sh_csi2_s_power(struct v4l2_subdev *sd, int on)
{
struct sh_csi2 *priv = container_of(sd, struct sh_csi2, subdev);
if (on)
return sh_csi2_client_connect(priv);
sh_csi2_client_disconnect(priv);
return 0;
}
static __devinit int sh_csi2_probe(struct platform_device *pdev)
{
struct resource *res;
unsigned int irq;
int ret;
struct sh_csi2 *priv;
struct sh_csi2_pdata *pdata = pdev->dev.platform_data;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (!res || (int)irq <= 0 || !pdata) {
dev_err(&pdev->dev, "Not enough CSI2 platform resources.\n");
return -ENODEV;
}
if (pdata->type != SH_CSI2C) {
dev_err(&pdev->dev, "Only CSI2C supported ATM.\n");
return -EINVAL;
}
priv = kzalloc(sizeof(struct sh_csi2), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->irq = irq;
if (!request_mem_region(res->start, resource_size(res), pdev->name)) {
dev_err(&pdev->dev, "CSI2 register region already claimed\n");
ret = -EBUSY;
goto ereqreg;
}
priv->base = ioremap(res->start, resource_size(res));
if (!priv->base) {
ret = -ENXIO;
dev_err(&pdev->dev, "Unable to ioremap CSI2 registers.\n");
goto eremap;
}
priv->pdev = pdev;
platform_set_drvdata(pdev, priv);
v4l2_subdev_init(&priv->subdev, &sh_csi2_subdev_ops);
v4l2_set_subdevdata(&priv->subdev, &pdev->dev);
snprintf(priv->subdev.name, V4L2_SUBDEV_NAME_SIZE, "%s.mipi-csi",
dev_name(pdata->v4l2_dev->dev));
ret = v4l2_device_register_subdev(pdata->v4l2_dev, &priv->subdev);
dev_dbg(&pdev->dev, "%s(%p): ret(register_subdev) = %d\n", __func__, priv, ret);
if (ret < 0)
goto esdreg;
pm_runtime_enable(&pdev->dev);
dev_dbg(&pdev->dev, "CSI2 probed.\n");
return 0;
esdreg:
iounmap(priv->base);
eremap:
release_mem_region(res->start, resource_size(res));
ereqreg:
kfree(priv);
return ret;
}
static __devexit int sh_csi2_remove(struct platform_device *pdev)
{
struct sh_csi2 *priv = platform_get_drvdata(pdev);
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
v4l2_device_unregister_subdev(&priv->subdev);
pm_runtime_disable(&pdev->dev);
iounmap(priv->base);
release_mem_region(res->start, resource_size(res));
platform_set_drvdata(pdev, NULL);
kfree(priv);
return 0;
}
static int __init sh_csi2_init(void)
{
return platform_driver_register(&sh_csi2_pdrv);
}
static void __exit sh_csi2_exit(void)
{
platform_driver_unregister(&sh_csi2_pdrv);
}
