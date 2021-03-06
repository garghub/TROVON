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
static int sh_csi2_g_mbus_config(struct v4l2_subdev *sd,
struct v4l2_mbus_config *cfg)
{
cfg->flags = V4L2_MBUS_PCLK_SAMPLE_RISING |
V4L2_MBUS_HSYNC_ACTIVE_HIGH | V4L2_MBUS_VSYNC_ACTIVE_HIGH |
V4L2_MBUS_MASTER | V4L2_MBUS_DATA_ACTIVE_HIGH;
cfg->type = V4L2_MBUS_PARALLEL;
return 0;
}
static int sh_csi2_s_mbus_config(struct v4l2_subdev *sd,
const struct v4l2_mbus_config *cfg)
{
struct sh_csi2 *priv = container_of(sd, struct sh_csi2, subdev);
struct soc_camera_device *icd = v4l2_get_subdev_hostdata(sd);
struct v4l2_subdev *client_sd = soc_camera_to_subdev(icd);
struct v4l2_mbus_config client_cfg = {.type = V4L2_MBUS_CSI2,
.flags = priv->mipi_flags};
return v4l2_subdev_call(client_sd, video, s_mbus_config, &client_cfg);
}
static void sh_csi2_hwinit(struct sh_csi2 *priv)
{
struct sh_csi2_pdata *pdata = priv->pdev->dev.platform_data;
__u32 tmp = 0x10;
iowrite32(0x00000001, priv->base + SH_CSI2_TREF);
iowrite32(0x00000001, priv->base + SH_CSI2_SRST);
udelay(5);
iowrite32(0x00000000, priv->base + SH_CSI2_SRST);
switch (pdata->type) {
case SH_CSI2C:
if (priv->client->lanes == 1)
tmp |= 1;
else
tmp |= 3;
break;
case SH_CSI2I:
if (!priv->client->lanes || priv->client->lanes > 4)
tmp |= 0xf;
else
tmp |= (1 << priv->client->lanes) - 1;
}
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
static int sh_csi2_client_connect(struct sh_csi2 *priv)
{
struct sh_csi2_pdata *pdata = priv->pdev->dev.platform_data;
struct soc_camera_device *icd = v4l2_get_subdev_hostdata(&priv->subdev);
struct v4l2_subdev *client_sd = soc_camera_to_subdev(icd);
struct device *dev = v4l2_get_subdevdata(&priv->subdev);
struct v4l2_mbus_config cfg;
unsigned long common_flags, csi2_flags;
int i, ret;
if (priv->client)
return -EBUSY;
for (i = 0; i < pdata->num_clients; i++)
if (&pdata->clients[i].pdev->dev == icd->pdev)
break;
dev_dbg(dev, "%s(%p): found #%d\n", __func__, dev, i);
if (i == pdata->num_clients)
return -ENODEV;
csi2_flags = V4L2_MBUS_CSI2_CONTINUOUS_CLOCK | V4L2_MBUS_CSI2_1_LANE;
switch (pdata->type) {
case SH_CSI2C:
if (pdata->clients[i].lanes != 1)
csi2_flags |= V4L2_MBUS_CSI2_2_LANE;
break;
case SH_CSI2I:
switch (pdata->clients[i].lanes) {
default:
csi2_flags |= V4L2_MBUS_CSI2_4_LANE;
case 3:
csi2_flags |= V4L2_MBUS_CSI2_3_LANE;
case 2:
csi2_flags |= V4L2_MBUS_CSI2_2_LANE;
}
}
cfg.type = V4L2_MBUS_CSI2;
ret = v4l2_subdev_call(client_sd, video, g_mbus_config, &cfg);
if (ret == -ENOIOCTLCMD)
common_flags = csi2_flags;
else if (!ret)
common_flags = soc_mbus_config_compatible(&cfg,
csi2_flags);
else
common_flags = 0;
if (!common_flags)
return -EINVAL;
priv->mipi_flags = common_flags;
priv->client = pdata->clients + i;
pm_runtime_get_sync(dev);
sh_csi2_hwinit(priv);
return 0;
}
static void sh_csi2_client_disconnect(struct sh_csi2 *priv)
{
if (!priv->client)
return;
priv->client = NULL;
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
