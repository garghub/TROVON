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
static void mmpcam_power_up_ctlr(struct mmp_camera *cam)
{
iowrite32(0x3f, cam->power_regs + REG_CCIC_DCGCR);
iowrite32(0x3805b, cam->power_regs + REG_CCIC_CRCR);
mdelay(1);
}
static void mmpcam_power_up(struct mcam_camera *mcam)
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
static int mmpcam_probe(struct platform_device *pdev)
{
struct mmp_camera *cam;
struct mcam_camera *mcam;
struct resource *res;
struct mmp_camera_platform_data *pdata;
int ret;
cam = kzalloc(sizeof(*cam), GFP_KERNEL);
if (cam == NULL)
return -ENOMEM;
cam->pdev = pdev;
INIT_LIST_HEAD(&cam->devlist);
mcam = &cam->mcam;
mcam->plat_power_up = mmpcam_power_up;
mcam->plat_power_down = mmpcam_power_down;
mcam->dev = &pdev->dev;
mcam->use_smbus = 0;
mcam->chip_id = MCAM_ARMADA610;
mcam->buffer_mode = B_DMA_sg;
spin_lock_init(&mcam->dev_lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(&pdev->dev, "no iomem resource!\n");
ret = -ENODEV;
goto out_free;
}
mcam->regs = ioremap(res->start, resource_size(res));
if (mcam->regs == NULL) {
dev_err(&pdev->dev, "MMIO ioremap fail\n");
ret = -ENODEV;
goto out_free;
}
mcam->regs_size = resource_size(res);
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (res == NULL) {
dev_err(&pdev->dev, "no power resource!\n");
ret = -ENODEV;
goto out_unmap1;
}
cam->power_regs = ioremap(res->start, resource_size(res));
if (cam->power_regs == NULL) {
dev_err(&pdev->dev, "power MMIO ioremap fail\n");
ret = -ENODEV;
goto out_unmap1;
}
pdata = pdev->dev.platform_data;
mcam->i2c_adapter = platform_get_drvdata(pdata->i2c_device);
if (mcam->i2c_adapter == NULL) {
ret = -ENODEV;
dev_err(&pdev->dev, "No i2c adapter\n");
goto out_unmap2;
}
ret = gpio_request(pdata->sensor_power_gpio, "cam-power");
if (ret) {
dev_err(&pdev->dev, "Can't get sensor power gpio %d",
pdata->sensor_power_gpio);
goto out_unmap2;
}
gpio_direction_output(pdata->sensor_power_gpio, 0);
ret = gpio_request(pdata->sensor_reset_gpio, "cam-reset");
if (ret) {
dev_err(&pdev->dev, "Can't get sensor reset gpio %d",
pdata->sensor_reset_gpio);
goto out_gpio;
}
gpio_direction_output(pdata->sensor_reset_gpio, 0);
mmpcam_power_up(mcam);
ret = mccic_register(mcam);
if (ret)
goto out_gpio2;
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (res == NULL) {
ret = -ENODEV;
goto out_unregister;
}
cam->irq = res->start;
ret = request_irq(cam->irq, mmpcam_irq, IRQF_SHARED,
"mmp-camera", mcam);
if (ret == 0) {
mmpcam_add_device(cam);
return 0;
}
out_unregister:
mccic_shutdown(mcam);
out_gpio2:
mmpcam_power_down(mcam);
gpio_free(pdata->sensor_reset_gpio);
out_gpio:
gpio_free(pdata->sensor_power_gpio);
out_unmap2:
iounmap(cam->power_regs);
out_unmap1:
iounmap(mcam->regs);
out_free:
kfree(cam);
return ret;
}
static int mmpcam_remove(struct mmp_camera *cam)
{
struct mcam_camera *mcam = &cam->mcam;
struct mmp_camera_platform_data *pdata;
mmpcam_remove_device(cam);
free_irq(cam->irq, mcam);
mccic_shutdown(mcam);
mmpcam_power_down(mcam);
pdata = cam->pdev->dev.platform_data;
gpio_free(pdata->sensor_reset_gpio);
gpio_free(pdata->sensor_power_gpio);
iounmap(cam->power_regs);
iounmap(mcam->regs);
kfree(cam);
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
