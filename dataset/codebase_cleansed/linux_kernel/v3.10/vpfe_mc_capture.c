void mbus_to_pix(const struct v4l2_mbus_framefmt *mbus,
struct v4l2_pix_format *pix)
{
switch (mbus->code) {
case V4L2_MBUS_FMT_UYVY8_2X8:
pix->pixelformat = V4L2_PIX_FMT_UYVY;
pix->bytesperline = pix->width * 2;
break;
case V4L2_MBUS_FMT_YUYV8_2X8:
pix->pixelformat = V4L2_PIX_FMT_YUYV;
pix->bytesperline = pix->width * 2;
break;
case V4L2_MBUS_FMT_YUYV10_1X20:
pix->pixelformat = V4L2_PIX_FMT_UYVY;
pix->bytesperline = pix->width * 2;
break;
case V4L2_MBUS_FMT_SGRBG12_1X12:
pix->pixelformat = V4L2_PIX_FMT_SBGGR16;
pix->bytesperline = pix->width * 2;
break;
case V4L2_MBUS_FMT_SGRBG10_DPCM8_1X8:
pix->pixelformat = V4L2_PIX_FMT_SGRBG10DPCM8;
pix->bytesperline = pix->width;
break;
case V4L2_MBUS_FMT_SGRBG10_ALAW8_1X8:
pix->pixelformat = V4L2_PIX_FMT_SGRBG10ALAW8;
pix->bytesperline = pix->width;
break;
case V4L2_MBUS_FMT_YDYUYDYV8_1X16:
pix->pixelformat = V4L2_PIX_FMT_NV12;
pix->bytesperline = pix->width;
break;
case V4L2_MBUS_FMT_Y8_1X8:
pix->pixelformat = V4L2_PIX_FMT_GREY;
pix->bytesperline = pix->width;
break;
case V4L2_MBUS_FMT_UV8_1X8:
pix->pixelformat = V4L2_PIX_FMT_UV8;
pix->bytesperline = pix->width;
break;
default:
pr_err("Invalid mbus code set\n");
}
pix->bytesperline = ALIGN(pix->bytesperline, 32);
if (pix->pixelformat == V4L2_PIX_FMT_NV12)
pix->sizeimage = pix->bytesperline * pix->height +
((pix->bytesperline * pix->height) >> 1);
else
pix->sizeimage = pix->bytesperline * pix->height;
}
static irqreturn_t vpfe_isr(int irq, void *dev_id)
{
struct vpfe_device *vpfe_dev = dev_id;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_isr\n");
vpfe_isif_buffer_isr(&vpfe_dev->vpfe_isif);
vpfe_resizer_buffer_isr(&vpfe_dev->vpfe_resizer);
return IRQ_HANDLED;
}
static irqreturn_t vpfe_vdint1_isr(int irq, void *dev_id)
{
struct vpfe_device *vpfe_dev = dev_id;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_vdint1_isr\n");
vpfe_isif_vidint1_isr(&vpfe_dev->vpfe_isif);
return IRQ_HANDLED;
}
static irqreturn_t vpfe_imp_dma_isr(int irq, void *dev_id)
{
struct vpfe_device *vpfe_dev = dev_id;
v4l2_dbg(1, debug, &vpfe_dev->v4l2_dev, "vpfe_imp_dma_isr\n");
vpfe_ipipeif_ss_buffer_isr(&vpfe_dev->vpfe_ipipeif);
vpfe_resizer_dma_isr(&vpfe_dev->vpfe_resizer);
return IRQ_HANDLED;
}
static void vpfe_disable_clock(struct vpfe_device *vpfe_dev)
{
struct vpfe_config *vpfe_cfg = vpfe_dev->cfg;
int i;
for (i = 0; i < vpfe_cfg->num_clocks; i++) {
clk_disable_unprepare(vpfe_dev->clks[i]);
clk_put(vpfe_dev->clks[i]);
}
kzfree(vpfe_dev->clks);
v4l2_info(vpfe_dev->pdev->driver, "vpfe capture clocks disabled\n");
}
static int vpfe_enable_clock(struct vpfe_device *vpfe_dev)
{
struct vpfe_config *vpfe_cfg = vpfe_dev->cfg;
int ret = -EFAULT;
int i;
if (!vpfe_cfg->num_clocks)
return 0;
vpfe_dev->clks = kzalloc(vpfe_cfg->num_clocks *
sizeof(struct clock *), GFP_KERNEL);
if (vpfe_dev->clks == NULL) {
v4l2_err(vpfe_dev->pdev->driver, "Memory allocation failed\n");
return -ENOMEM;
}
for (i = 0; i < vpfe_cfg->num_clocks; i++) {
if (vpfe_cfg->clocks[i] == NULL) {
v4l2_err(vpfe_dev->pdev->driver,
"clock %s is not defined in vpfe config\n",
vpfe_cfg->clocks[i]);
goto out;
}
vpfe_dev->clks[i] =
clk_get(vpfe_dev->pdev, vpfe_cfg->clocks[i]);
if (IS_ERR(vpfe_dev->clks[i])) {
v4l2_err(vpfe_dev->pdev->driver,
"Failed to get clock %s\n",
vpfe_cfg->clocks[i]);
goto out;
}
if (clk_prepare_enable(vpfe_dev->clks[i])) {
v4l2_err(vpfe_dev->pdev->driver,
"vpfe clock %s not enabled\n",
vpfe_cfg->clocks[i]);
goto out;
}
v4l2_info(vpfe_dev->pdev->driver, "vpss clock %s enabled",
vpfe_cfg->clocks[i]);
}
return 0;
out:
for (i = 0; i < vpfe_cfg->num_clocks; i++)
if (!IS_ERR(vpfe_dev->clks[i])) {
clk_disable_unprepare(vpfe_dev->clks[i]);
clk_put(vpfe_dev->clks[i]);
}
v4l2_err(vpfe_dev->pdev->driver, "Failed to enable clocks\n");
kzfree(vpfe_dev->clks);
return ret;
}
static void vpfe_detach_irq(struct vpfe_device *vpfe_dev)
{
free_irq(vpfe_dev->ccdc_irq0, vpfe_dev);
free_irq(vpfe_dev->ccdc_irq1, vpfe_dev);
free_irq(vpfe_dev->imp_dma_irq, vpfe_dev);
}
static int vpfe_attach_irq(struct vpfe_device *vpfe_dev)
{
int ret = 0;
ret = request_irq(vpfe_dev->ccdc_irq0, vpfe_isr, IRQF_DISABLED,
"vpfe_capture0", vpfe_dev);
if (ret < 0) {
v4l2_err(&vpfe_dev->v4l2_dev,
"Error: requesting VINT0 interrupt\n");
return ret;
}
ret = request_irq(vpfe_dev->ccdc_irq1, vpfe_vdint1_isr, IRQF_DISABLED,
"vpfe_capture1", vpfe_dev);
if (ret < 0) {
v4l2_err(&vpfe_dev->v4l2_dev,
"Error: requesting VINT1 interrupt\n");
free_irq(vpfe_dev->ccdc_irq0, vpfe_dev);
return ret;
}
ret = request_irq(vpfe_dev->imp_dma_irq, vpfe_imp_dma_isr,
IRQF_DISABLED, "Imp_Sdram_Irq", vpfe_dev);
if (ret < 0) {
v4l2_err(&vpfe_dev->v4l2_dev,
"Error: requesting IMP IRQ interrupt\n");
free_irq(vpfe_dev->ccdc_irq1, vpfe_dev);
free_irq(vpfe_dev->ccdc_irq0, vpfe_dev);
return ret;
}
return 0;
}
static int register_i2c_devices(struct vpfe_device *vpfe_dev)
{
struct vpfe_ext_subdev_info *sdinfo;
struct vpfe_config *vpfe_cfg;
struct i2c_adapter *i2c_adap;
unsigned int num_subdevs;
int ret;
int i;
int k;
vpfe_cfg = vpfe_dev->cfg;
i2c_adap = i2c_get_adapter(1);
num_subdevs = vpfe_cfg->num_subdevs;
vpfe_dev->sd =
kzalloc(sizeof(struct v4l2_subdev *)*num_subdevs, GFP_KERNEL);
if (vpfe_dev->sd == NULL) {
v4l2_err(&vpfe_dev->v4l2_dev,
"unable to allocate memory for subdevice\n");
return -ENOMEM;
}
for (i = 0, k = 0; i < num_subdevs; i++) {
sdinfo = &vpfe_cfg->sub_devs[i];
if (interface == sdinfo->is_camera) {
if (vpfe_cfg->setup_input &&
vpfe_cfg->setup_input(sdinfo->grp_id) < 0) {
ret = -EFAULT;
v4l2_info(&vpfe_dev->v4l2_dev,
"could not setup input for %s\n",
sdinfo->module_name);
goto probe_sd_out;
}
vpfe_dev->sd[k] =
v4l2_i2c_new_subdev_board(&vpfe_dev->v4l2_dev,
i2c_adap, &sdinfo->board_info,
NULL);
if (vpfe_dev->sd[k]) {
v4l2_info(&vpfe_dev->v4l2_dev,
"v4l2 sub device %s registered\n",
sdinfo->module_name);
vpfe_dev->sd[k]->grp_id = sdinfo->grp_id;
k++;
sdinfo->registered = 1;
}
} else {
v4l2_info(&vpfe_dev->v4l2_dev,
"v4l2 sub device %s is not registered\n",
sdinfo->module_name);
}
}
vpfe_dev->num_ext_subdevs = k;
return 0;
probe_sd_out:
kzfree(vpfe_dev->sd);
return ret;
}
static int vpfe_register_entities(struct vpfe_device *vpfe_dev)
{
unsigned int flags = 0;
int ret;
int i;
ret = register_i2c_devices(vpfe_dev);
if (ret)
return ret;
ret = vpfe_isif_register_entities(&vpfe_dev->vpfe_isif,
&vpfe_dev->v4l2_dev);
if (ret)
return ret;
ret = vpfe_ipipeif_register_entities(&vpfe_dev->vpfe_ipipeif,
&vpfe_dev->v4l2_dev);
if (ret)
goto out_isif_register;
ret = vpfe_ipipe_register_entities(&vpfe_dev->vpfe_ipipe,
&vpfe_dev->v4l2_dev);
if (ret)
goto out_ipipeif_register;
ret = vpfe_resizer_register_entities(&vpfe_dev->vpfe_resizer,
&vpfe_dev->v4l2_dev);
if (ret)
goto out_ipipe_register;
for (i = 0; i < vpfe_dev->num_ext_subdevs; i++)
if (vpfe_dev->sd[i]->entity.num_pads) {
ret = media_entity_create_link(&vpfe_dev->sd[i]->entity,
0, &vpfe_dev->vpfe_isif.subdev.entity,
0, flags);
if (ret < 0)
goto out_resizer_register;
}
ret = media_entity_create_link(&vpfe_dev->vpfe_isif.subdev.entity, 1,
&vpfe_dev->vpfe_ipipeif.subdev.entity,
0, flags);
if (ret < 0)
goto out_resizer_register;
ret = media_entity_create_link(&vpfe_dev->vpfe_ipipeif.subdev.entity, 1,
&vpfe_dev->vpfe_ipipe.subdev.entity,
0, flags);
if (ret < 0)
goto out_resizer_register;
ret = media_entity_create_link(&vpfe_dev->vpfe_ipipe.subdev.entity,
1, &vpfe_dev->vpfe_resizer.crop_resizer.subdev.entity,
0, flags);
if (ret < 0)
goto out_resizer_register;
ret = media_entity_create_link(&vpfe_dev->vpfe_ipipeif.subdev.entity, 1,
&vpfe_dev->vpfe_resizer.crop_resizer.subdev.entity,
0, flags);
if (ret < 0)
goto out_resizer_register;
ret = v4l2_device_register_subdev_nodes(&vpfe_dev->v4l2_dev);
if (ret < 0)
goto out_resizer_register;
return 0;
out_resizer_register:
vpfe_resizer_unregister_entities(&vpfe_dev->vpfe_resizer);
out_ipipe_register:
vpfe_ipipe_unregister_entities(&vpfe_dev->vpfe_ipipe);
out_ipipeif_register:
vpfe_ipipeif_unregister_entities(&vpfe_dev->vpfe_ipipeif);
out_isif_register:
vpfe_isif_unregister_entities(&vpfe_dev->vpfe_isif);
return ret;
}
static void vpfe_unregister_entities(struct vpfe_device *vpfe_dev)
{
vpfe_isif_unregister_entities(&vpfe_dev->vpfe_isif);
vpfe_ipipeif_unregister_entities(&vpfe_dev->vpfe_ipipeif);
vpfe_ipipe_unregister_entities(&vpfe_dev->vpfe_ipipe);
vpfe_resizer_unregister_entities(&vpfe_dev->vpfe_resizer);
}
static void vpfe_cleanup_modules(struct vpfe_device *vpfe_dev,
struct platform_device *pdev)
{
vpfe_isif_cleanup(&vpfe_dev->vpfe_isif, pdev);
vpfe_ipipeif_cleanup(&vpfe_dev->vpfe_ipipeif, pdev);
vpfe_ipipe_cleanup(&vpfe_dev->vpfe_ipipe, pdev);
vpfe_resizer_cleanup(&vpfe_dev->vpfe_resizer, pdev);
}
static int vpfe_initialize_modules(struct vpfe_device *vpfe_dev,
struct platform_device *pdev)
{
int ret;
ret = vpfe_isif_init(&vpfe_dev->vpfe_isif, pdev);
if (ret)
return ret;
ret = vpfe_ipipeif_init(&vpfe_dev->vpfe_ipipeif, pdev);
if (ret)
goto out_isif_init;
ret = vpfe_ipipe_init(&vpfe_dev->vpfe_ipipe, pdev);
if (ret)
goto out_ipipeif_init;
ret = vpfe_resizer_init(&vpfe_dev->vpfe_resizer, pdev);
if (ret)
goto out_ipipe_init;
return 0;
out_ipipe_init:
vpfe_ipipe_cleanup(&vpfe_dev->vpfe_ipipe, pdev);
out_ipipeif_init:
vpfe_ipipeif_cleanup(&vpfe_dev->vpfe_ipipeif, pdev);
out_isif_init:
vpfe_isif_cleanup(&vpfe_dev->vpfe_isif, pdev);
return ret;
}
static int vpfe_probe(struct platform_device *pdev)
{
struct vpfe_device *vpfe_dev;
struct resource *res1;
int ret = -ENOMEM;
vpfe_dev = kzalloc(sizeof(*vpfe_dev), GFP_KERNEL);
if (!vpfe_dev) {
v4l2_err(pdev->dev.driver,
"Failed to allocate memory for vpfe_dev\n");
return ret;
}
if (pdev->dev.platform_data == NULL) {
v4l2_err(pdev->dev.driver, "Unable to get vpfe config\n");
ret = -ENOENT;
goto probe_free_dev_mem;
}
vpfe_dev->cfg = pdev->dev.platform_data;
if (vpfe_dev->cfg->card_name == NULL ||
vpfe_dev->cfg->sub_devs == NULL) {
v4l2_err(pdev->dev.driver, "null ptr in vpfe_cfg\n");
ret = -ENOENT;
goto probe_free_dev_mem;
}
res1 = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res1) {
v4l2_err(pdev->dev.driver,
"Unable to get interrupt for VINT0\n");
ret = -ENOENT;
goto probe_free_dev_mem;
}
vpfe_dev->ccdc_irq0 = res1->start;
res1 = platform_get_resource(pdev, IORESOURCE_IRQ, 1);
if (!res1) {
v4l2_err(pdev->dev.driver,
"Unable to get interrupt for VINT1\n");
ret = -ENOENT;
goto probe_free_dev_mem;
}
vpfe_dev->ccdc_irq1 = res1->start;
res1 = platform_get_resource(pdev, IORESOURCE_IRQ, 2);
if (!res1) {
v4l2_err(pdev->dev.driver,
"Unable to get interrupt for DMA\n");
ret = -ENOENT;
goto probe_free_dev_mem;
}
vpfe_dev->imp_dma_irq = res1->start;
vpfe_dev->pdev = &pdev->dev;
ret = vpfe_enable_clock(vpfe_dev);
if (ret)
goto probe_free_dev_mem;
ret = vpfe_initialize_modules(vpfe_dev, pdev);
if (ret)
goto probe_disable_clock;
vpfe_dev->media_dev.dev = vpfe_dev->pdev;
strcpy((char *)&vpfe_dev->media_dev.model, "davinci-media");
ret = media_device_register(&vpfe_dev->media_dev);
if (ret) {
v4l2_err(pdev->dev.driver,
"Unable to register media device.\n");
goto probe_out_entities_cleanup;
}
vpfe_dev->v4l2_dev.mdev = &vpfe_dev->media_dev;
ret = v4l2_device_register(&pdev->dev, &vpfe_dev->v4l2_dev);
if (ret) {
v4l2_err(pdev->dev.driver, "Unable to register v4l2 device.\n");
goto probe_out_media_unregister;
}
v4l2_info(&vpfe_dev->v4l2_dev, "v4l2 device registered\n");
platform_set_drvdata(pdev, vpfe_dev);
ret = vpfe_register_entities(vpfe_dev);
if (ret)
goto probe_out_v4l2_unregister;
ret = vpfe_attach_irq(vpfe_dev);
if (ret)
goto probe_out_entities_unregister;
return 0;
probe_out_entities_unregister:
vpfe_unregister_entities(vpfe_dev);
kzfree(vpfe_dev->sd);
probe_out_v4l2_unregister:
v4l2_device_unregister(&vpfe_dev->v4l2_dev);
probe_out_media_unregister:
media_device_unregister(&vpfe_dev->media_dev);
probe_out_entities_cleanup:
vpfe_cleanup_modules(vpfe_dev, pdev);
probe_disable_clock:
vpfe_disable_clock(vpfe_dev);
probe_free_dev_mem:
kzfree(vpfe_dev);
return ret;
}
static int vpfe_remove(struct platform_device *pdev)
{
struct vpfe_device *vpfe_dev = platform_get_drvdata(pdev);
v4l2_info(pdev->dev.driver, "vpfe_remove\n");
kzfree(vpfe_dev->sd);
vpfe_detach_irq(vpfe_dev);
vpfe_unregister_entities(vpfe_dev);
vpfe_cleanup_modules(vpfe_dev, pdev);
v4l2_device_unregister(&vpfe_dev->v4l2_dev);
media_device_unregister(&vpfe_dev->media_dev);
vpfe_disable_clock(vpfe_dev);
kzfree(vpfe_dev);
return 0;
}
