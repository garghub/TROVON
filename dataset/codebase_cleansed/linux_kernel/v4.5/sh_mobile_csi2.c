static int sh_csi2_set_fmt(struct v4l2_subdev *sd,
struct v4l2_subdev_pad_config *cfg,
struct v4l2_subdev_format *format)
{
struct sh_csi2 *priv = container_of(sd, struct sh_csi2, subdev);
struct sh_csi2_pdata *pdata = priv->pdev->dev.platform_data;
struct v4l2_mbus_framefmt *mf = &format->format;
u32 tmp = (priv->client->channel & 3) << 8;
if (format->pad)
return -EINVAL;
if (mf->width > 8188)
mf->width = 8188;
else if (mf->width & 1)
mf->width &= ~1;
switch (pdata->type) {
case SH_CSI2C:
switch (mf->code) {
case MEDIA_BUS_FMT_UYVY8_2X8:
case MEDIA_BUS_FMT_YUYV8_1_5X8:
case MEDIA_BUS_FMT_Y8_1X8:
case MEDIA_BUS_FMT_SBGGR8_1X8:
case MEDIA_BUS_FMT_SGRBG8_1X8:
break;
default:
mf->code = MEDIA_BUS_FMT_YUYV8_2X8;
}
break;
case SH_CSI2I:
switch (mf->code) {
case MEDIA_BUS_FMT_Y8_1X8:
case MEDIA_BUS_FMT_SBGGR8_1X8:
case MEDIA_BUS_FMT_SGRBG8_1X8:
case MEDIA_BUS_FMT_SBGGR10_1X10:
case MEDIA_BUS_FMT_SBGGR12_1X12:
break;
default:
mf->code = MEDIA_BUS_FMT_SBGGR8_1X8;
}
break;
}
if (format->which == V4L2_SUBDEV_FORMAT_TRY) {
cfg->try_fmt = *mf;
return 0;
}
if (mf->width > 8188 || mf->width & 1)
return -EINVAL;
switch (mf->code) {
case MEDIA_BUS_FMT_UYVY8_2X8:
tmp |= 0x1e;
break;
case MEDIA_BUS_FMT_YUYV8_1_5X8:
tmp |= 0x18;
break;
case MEDIA_BUS_FMT_RGB555_2X8_PADHI_BE:
tmp |= 0x21;
break;
case MEDIA_BUS_FMT_RGB565_2X8_BE:
tmp |= 0x22;
break;
case MEDIA_BUS_FMT_Y8_1X8:
case MEDIA_BUS_FMT_SBGGR8_1X8:
case MEDIA_BUS_FMT_SGRBG8_1X8:
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
struct sh_csi2 *priv = container_of(sd, struct sh_csi2, subdev);
if (!priv->mipi_flags) {
struct soc_camera_device *icd = v4l2_get_subdev_hostdata(sd);
struct v4l2_subdev *client_sd = soc_camera_to_subdev(icd);
struct sh_csi2_pdata *pdata = priv->pdev->dev.platform_data;
unsigned long common_flags, csi2_flags;
struct v4l2_mbus_config client_cfg = {.type = V4L2_MBUS_CSI2,};
int ret;
csi2_flags = V4L2_MBUS_CSI2_CONTINUOUS_CLOCK |
V4L2_MBUS_CSI2_1_LANE;
switch (pdata->type) {
case SH_CSI2C:
if (priv->client->lanes != 1)
csi2_flags |= V4L2_MBUS_CSI2_2_LANE;
break;
case SH_CSI2I:
switch (priv->client->lanes) {
default:
csi2_flags |= V4L2_MBUS_CSI2_4_LANE;
case 3:
csi2_flags |= V4L2_MBUS_CSI2_3_LANE;
case 2:
csi2_flags |= V4L2_MBUS_CSI2_2_LANE;
}
}
ret = v4l2_subdev_call(client_sd, video, g_mbus_config, &client_cfg);
if (ret == -ENOIOCTLCMD)
common_flags = csi2_flags;
else if (!ret)
common_flags = soc_mbus_config_compatible(&client_cfg,
csi2_flags);
else
common_flags = 0;
if (!common_flags)
return -EINVAL;
priv->mipi_flags = common_flags;
}
if (cfg) {
cfg->flags = V4L2_MBUS_PCLK_SAMPLE_RISING |
V4L2_MBUS_HSYNC_ACTIVE_HIGH | V4L2_MBUS_VSYNC_ACTIVE_HIGH |
V4L2_MBUS_MASTER | V4L2_MBUS_DATA_ACTIVE_HIGH;
cfg->type = V4L2_MBUS_PARALLEL;
}
return 0;
}
static int sh_csi2_s_mbus_config(struct v4l2_subdev *sd,
const struct v4l2_mbus_config *cfg)
{
struct sh_csi2 *priv = container_of(sd, struct sh_csi2, subdev);
struct soc_camera_device *icd = v4l2_get_subdev_hostdata(sd);
struct v4l2_subdev *client_sd = soc_camera_to_subdev(icd);
struct v4l2_mbus_config client_cfg = {.type = V4L2_MBUS_CSI2,};
int ret = sh_csi2_g_mbus_config(sd, NULL);
if (ret < 0)
return ret;
pm_runtime_get_sync(&priv->pdev->dev);
sh_csi2_hwinit(priv);
client_cfg.flags = priv->mipi_flags;
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
struct device *dev = v4l2_get_subdevdata(&priv->subdev);
struct sh_csi2_pdata *pdata = dev->platform_data;
struct soc_camera_device *icd = v4l2_get_subdev_hostdata(&priv->subdev);
int i;
if (priv->client)
return -EBUSY;
for (i = 0; i < pdata->num_clients; i++)
if ((pdata->clients[i].pdev &&
&pdata->clients[i].pdev->dev == icd->pdev) ||
(icd->control &&
strcmp(pdata->clients[i].name, dev_name(icd->control))))
break;
dev_dbg(dev, "%s(%p): found #%d\n", __func__, dev, i);
if (i == pdata->num_clients)
return -ENODEV;
priv->client = pdata->clients + i;
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
static int sh_csi2_probe(struct platform_device *pdev)
{
struct resource *res;
unsigned int irq;
int ret;
struct sh_csi2 *priv;
struct sh_csi2_pdata *pdata = pdev->dev.platform_data;
if (!pdata)
return -EINVAL;
priv = devm_kzalloc(&pdev->dev, sizeof(struct sh_csi2), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
irq = platform_get_irq(pdev, 0);
if (!res || (int)irq <= 0) {
dev_err(&pdev->dev, "Not enough CSI2 platform resources.\n");
return -ENODEV;
}
if (pdata->type != SH_CSI2C) {
dev_err(&pdev->dev, "Only CSI2C supported ATM.\n");
return -EINVAL;
}
priv->irq = irq;
priv->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(priv->base))
return PTR_ERR(priv->base);
priv->pdev = pdev;
priv->subdev.owner = THIS_MODULE;
priv->subdev.dev = &pdev->dev;
platform_set_drvdata(pdev, &priv->subdev);
v4l2_subdev_init(&priv->subdev, &sh_csi2_subdev_ops);
v4l2_set_subdevdata(&priv->subdev, &pdev->dev);
snprintf(priv->subdev.name, V4L2_SUBDEV_NAME_SIZE, "%s.mipi-csi",
dev_name(&pdev->dev));
ret = v4l2_async_register_subdev(&priv->subdev);
if (ret < 0)
return ret;
pm_runtime_enable(&pdev->dev);
dev_dbg(&pdev->dev, "CSI2 probed.\n");
return 0;
}
static int sh_csi2_remove(struct platform_device *pdev)
{
struct v4l2_subdev *subdev = platform_get_drvdata(pdev);
struct sh_csi2 *priv = container_of(subdev, struct sh_csi2, subdev);
v4l2_async_unregister_subdev(&priv->subdev);
pm_runtime_disable(&pdev->dev);
return 0;
}
