static inline struct mmp_camera *mcam_to_cam(struct mcam_camera *mcam)
{
return container_of(mcam, struct mmp_camera, mcam);
}
static void mmpcam_add_device(struct mmp_camera *cam)
{
mutex_lock(&mmpcam_devices_lock);
list_add(&cam->devlist, &mmpcam_devices);
mutex_unlock(&mmpcam_devices_lock);
}
static void mmpcam_remove_device(struct mmp_camera *cam)
{
mutex_lock(&mmpcam_devices_lock);
list_del(&cam->devlist);
mutex_unlock(&mmpcam_devices_lock);
}
static struct mmp_camera *mmpcam_find_device(struct platform_device *pdev)
{
struct mmp_camera *cam;
mutex_lock(&mmpcam_devices_lock);
list_for_each_entry(cam, &mmpcam_devices, devlist) {
if (cam->pdev == pdev) {
mutex_unlock(&mmpcam_devices_lock);
return cam;
}
}
mutex_unlock(&mmpcam_devices_lock);
return NULL;
}
static void mcam_clk_enable(struct mcam_camera *mcam)
{
unsigned int i;
for (i = 0; i < NR_MCAM_CLK; i++) {
if (!IS_ERR(mcam->clk[i]))
clk_prepare_enable(mcam->clk[i]);
}
}
static void mcam_clk_disable(struct mcam_camera *mcam)
{
int i;
for (i = NR_MCAM_CLK - 1; i >= 0; i--) {
if (!IS_ERR(mcam->clk[i]))
clk_disable_unprepare(mcam->clk[i]);
}
}
static void mmpcam_power_up_ctlr(struct mmp_camera *cam)
{
iowrite32(0x3f, cam->power_regs + REG_CCIC_DCGCR);
iowrite32(0x3805b, cam->power_regs + REG_CCIC_CRCR);
mdelay(1);
}
static int mmpcam_power_up(struct mcam_camera *mcam)
{
struct mmp_camera *cam = mcam_to_cam(mcam);
struct mmp_camera_platform_data *pdata;
mmpcam_power_up_ctlr(cam);
mcam_reg_write(mcam, REG_CLKCTRL, 0x60000002);
pdata = cam->pdev->dev.platform_data;
gpio_set_value(pdata->sensor_power_gpio, 1);
mdelay(5);
mcam_reg_clear_bit(mcam, REG_CTRL1, 0x10000000);
gpio_set_value(pdata->sensor_reset_gpio, 0);
mdelay(5);
gpio_set_value(pdata->sensor_reset_gpio, 1);
mdelay(5);
mcam_clk_enable(mcam);
return 0;
}
static void mmpcam_power_down(struct mcam_camera *mcam)
{
struct mmp_camera *cam = mcam_to_cam(mcam);
struct mmp_camera_platform_data *pdata;
iowrite32(0, cam->power_regs + REG_CCIC_DCGCR);
iowrite32(0, cam->power_regs + REG_CCIC_CRCR);
pdata = cam->pdev->dev.platform_data;
gpio_set_value(pdata->sensor_power_gpio, 0);
gpio_set_value(pdata->sensor_reset_gpio, 0);
mcam_clk_disable(mcam);
}
void mcam_ctlr_reset(struct mcam_camera *mcam)
{
unsigned long val;
struct mmp_camera *cam = mcam_to_cam(mcam);
if (mcam->ccic_id) {
val = ioread32(cam->power_regs + REG_CCIC2_CRCR);
iowrite32(val & ~0x2, cam->power_regs + REG_CCIC2_CRCR);
iowrite32(val | 0x2, cam->power_regs + REG_CCIC2_CRCR);
} else {
val = ioread32(cam->power_regs + REG_CCIC_CRCR);
iowrite32(val & ~0x2, cam->power_regs + REG_CCIC_CRCR);
iowrite32(val | 0x2, cam->power_regs + REG_CCIC_CRCR);
}
}
void mmpcam_calc_dphy(struct mcam_camera *mcam)
{
struct mmp_camera *cam = mcam_to_cam(mcam);
struct mmp_camera_platform_data *pdata = cam->pdev->dev.platform_data;
struct device *dev = &cam->pdev->dev;
unsigned long tx_clk_esc;
switch (pdata->dphy3_algo) {
case DPHY3_ALGO_PXA910:
pdata->dphy[0] =
(((1 + (pdata->lane_clk * 80) / 1000) & 0xff) << 8)
| (1 + pdata->lane_clk * 35 / 1000);
break;
case DPHY3_ALGO_PXA2128:
pdata->dphy[0] =
(((2 + (pdata->lane_clk * 110) / 1000) & 0xff) << 8)
| (1 + pdata->lane_clk * 35 / 1000);
break;
default:
dev_dbg(dev, "camera: use the default CSI2_DPHY3 value\n");
}
if (IS_ERR(cam->mipi_clk))
return;
clk_prepare_enable(cam->mipi_clk);
tx_clk_esc = (clk_get_rate(cam->mipi_clk) / 1000000) / 12;
clk_disable_unprepare(cam->mipi_clk);
pdata->dphy[2] =
((((534 * tx_clk_esc) / 2000 - 1) & 0xff) << 8)
| (((38 * tx_clk_esc) / 1000 - 1) & 0xff);
dev_dbg(dev, "camera: DPHY sets: dphy3=0x%x, dphy5=0x%x, dphy6=0x%x\n",
pdata->dphy[0], pdata->dphy[1], pdata->dphy[2]);
}
static irqreturn_t mmpcam_irq(int irq, void *data)
{
struct mcam_camera *mcam = data;
unsigned int irqs, handled;
spin_lock(&mcam->dev_lock);
irqs = mcam_reg_read(mcam, REG_IRQSTAT);
handled = mccic_irq(mcam, irqs);
spin_unlock(&mcam->dev_lock);
return IRQ_RETVAL(handled);
}
static void mcam_init_clk(struct mcam_camera *mcam)
{
unsigned int i;
for (i = 0; i < NR_MCAM_CLK; i++) {
if (mcam_clks[i] != NULL) {
mcam->clk[i] = devm_clk_get(mcam->dev, mcam_clks[i]);
if (IS_ERR(mcam->clk[i]))
dev_warn(mcam->dev, "Could not get clk: %s\n",
mcam_clks[i]);
}
}
}
static int mmpcam_probe(struct platform_device *pdev)
{
struct mmp_camera *cam;
struct mcam_camera *mcam;
struct resource *res;
struct mmp_camera_platform_data *pdata;
int ret;
pdata = pdev->dev.platform_data;
if (!pdata)
return -ENODEV;
cam = devm_kzalloc(&pdev->dev, sizeof(*cam), GFP_KERNEL);
if (cam == NULL)
return -ENOMEM;
cam->pdev = pdev;
INIT_LIST_HEAD(&cam->devlist);
mcam = &cam->mcam;
mcam->plat_power_up = mmpcam_power_up;
mcam->plat_power_down = mmpcam_power_down;
mcam->ctlr_reset = mcam_ctlr_reset;
mcam->calc_dphy = mmpcam_calc_dphy;
mcam->dev = &pdev->dev;
mcam->use_smbus = 0;
mcam->ccic_id = pdev->id;
mcam->mclk_min = pdata->mclk_min;
mcam->mclk_src = pdata->mclk_src;
mcam->mclk_div = pdata->mclk_div;
mcam->bus_type = pdata->bus_type;
mcam->dphy = pdata->dphy;
if (mcam->bus_type == V4L2_MBUS_CSI2) {
cam->mipi_clk = devm_clk_get(mcam->dev, "mipi");
if ((IS_ERR(cam->mipi_clk) && mcam->dphy[2] == 0))
return PTR_ERR(cam->mipi_clk);
}
mcam->mipi_enabled = false;
mcam->lane = pdata->lane;
mcam->chip_id = MCAM_ARMADA610;
mcam->buffer_mode = B_DMA_sg;
spin_lock_init(&mcam->dev_lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
mcam->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mcam->regs))
return PTR_ERR(mcam->regs);
mcam->regs_size = resource_size(res);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
cam->power_regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(cam->power_regs))
return PTR_ERR(cam->power_regs);
mcam->i2c_adapter = platform_get_drvdata(pdata->i2c_device);
if (mcam->i2c_adapter == NULL) {
dev_err(&pdev->dev, "No i2c adapter\n");
return -ENODEV;
}
ret = devm_gpio_request(&pdev->dev, pdata->sensor_power_gpio,
"cam-power");
if (ret) {
dev_err(&pdev->dev, "Can't get sensor power gpio %d",
pdata->sensor_power_gpio);
return ret;
}
gpio_direction_output(pdata->sensor_power_gpio, 0);
ret = devm_gpio_request(&pdev->dev, pdata->sensor_reset_gpio,
"cam-reset");
if (ret) {
dev_err(&pdev->dev, "Can't get sensor reset gpio %d",
pdata->sensor_reset_gpio);
return ret;
}
gpio_direction_output(pdata->sensor_reset_gpio, 0);
mcam_init_clk(mcam);
ret = mmpcam_power_up(mcam);
if (ret)
return ret;
ret = mccic_register(mcam);
if (ret)
goto out_power_down;
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (res == NULL) {
ret = -ENODEV;
goto out_unregister;
}
cam->irq = res->start;
ret = devm_request_irq(&pdev->dev, cam->irq, mmpcam_irq, IRQF_SHARED,
"mmp-camera", mcam);
if (ret == 0) {
mmpcam_add_device(cam);
return 0;
}
out_unregister:
mccic_shutdown(mcam);
out_power_down:
mmpcam_power_down(mcam);
return ret;
}
static int mmpcam_remove(struct mmp_camera *cam)
{
struct mcam_camera *mcam = &cam->mcam;
mmpcam_remove_device(cam);
mccic_shutdown(mcam);
mmpcam_power_down(mcam);
return 0;
}
static int mmpcam_platform_remove(struct platform_device *pdev)
{
struct mmp_camera *cam = mmpcam_find_device(pdev);
if (cam == NULL)
return -ENODEV;
return mmpcam_remove(cam);
}
static int mmpcam_suspend(struct platform_device *pdev, pm_message_t state)
{
struct mmp_camera *cam = mmpcam_find_device(pdev);
if (state.event != PM_EVENT_SUSPEND)
return 0;
mccic_suspend(&cam->mcam);
return 0;
}
static int mmpcam_resume(struct platform_device *pdev)
{
struct mmp_camera *cam = mmpcam_find_device(pdev);
mmpcam_power_up_ctlr(cam);
return mccic_resume(&cam->mcam);
}
static int __init mmpcam_init_module(void)
{
mutex_init(&mmpcam_devices_lock);
return platform_driver_register(&mmpcam_driver);
}
static void __exit mmpcam_exit_module(void)
{
platform_driver_unregister(&mmpcam_driver);
if (!list_empty(&mmpcam_devices))
printk(KERN_ERR "mmp_camera leaving devices behind\n");
}
