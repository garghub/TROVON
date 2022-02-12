static inline struct cafe_camera *to_cam(struct v4l2_device *dev)
{
struct mcam_camera *m = container_of(dev, struct mcam_camera, v4l2_dev);
return container_of(m, struct cafe_camera, mcam);
}
static int cafe_smbus_write_done(struct mcam_camera *mcam)
{
unsigned long flags;
int c1;
udelay(20);
spin_lock_irqsave(&mcam->dev_lock, flags);
c1 = mcam_reg_read(mcam, REG_TWSIC1);
spin_unlock_irqrestore(&mcam->dev_lock, flags);
return (c1 & (TWSIC1_WSTAT|TWSIC1_ERROR)) != TWSIC1_WSTAT;
}
static int cafe_smbus_write_data(struct cafe_camera *cam,
u16 addr, u8 command, u8 value)
{
unsigned int rval;
unsigned long flags;
struct mcam_camera *mcam = &cam->mcam;
spin_lock_irqsave(&mcam->dev_lock, flags);
rval = TWSIC0_EN | ((addr << TWSIC0_SID_SHIFT) & TWSIC0_SID);
rval |= TWSIC0_OVMAGIC;
rval |= TWSIC0_CLKDIV;
mcam_reg_write(mcam, REG_TWSIC0, rval);
(void) mcam_reg_read(mcam, REG_TWSIC1);
rval = value | ((command << TWSIC1_ADDR_SHIFT) & TWSIC1_ADDR);
mcam_reg_write(mcam, REG_TWSIC1, rval);
spin_unlock_irqrestore(&mcam->dev_lock, flags);
mdelay(2);
wait_event_timeout(cam->smbus_wait, cafe_smbus_write_done(mcam),
CAFE_SMBUS_TIMEOUT);
spin_lock_irqsave(&mcam->dev_lock, flags);
rval = mcam_reg_read(mcam, REG_TWSIC1);
spin_unlock_irqrestore(&mcam->dev_lock, flags);
if (rval & TWSIC1_WSTAT) {
cam_err(cam, "SMBUS write (%02x/%02x/%02x) timed out\n", addr,
command, value);
return -EIO;
}
if (rval & TWSIC1_ERROR) {
cam_err(cam, "SMBUS write (%02x/%02x/%02x) error\n", addr,
command, value);
return -EIO;
}
return 0;
}
static int cafe_smbus_read_done(struct mcam_camera *mcam)
{
unsigned long flags;
int c1;
udelay(20);
spin_lock_irqsave(&mcam->dev_lock, flags);
c1 = mcam_reg_read(mcam, REG_TWSIC1);
spin_unlock_irqrestore(&mcam->dev_lock, flags);
return c1 & (TWSIC1_RVALID|TWSIC1_ERROR);
}
static int cafe_smbus_read_data(struct cafe_camera *cam,
u16 addr, u8 command, u8 *value)
{
unsigned int rval;
unsigned long flags;
struct mcam_camera *mcam = &cam->mcam;
spin_lock_irqsave(&mcam->dev_lock, flags);
rval = TWSIC0_EN | ((addr << TWSIC0_SID_SHIFT) & TWSIC0_SID);
rval |= TWSIC0_OVMAGIC;
rval |= TWSIC0_CLKDIV;
mcam_reg_write(mcam, REG_TWSIC0, rval);
(void) mcam_reg_read(mcam, REG_TWSIC1);
rval = TWSIC1_READ | ((command << TWSIC1_ADDR_SHIFT) & TWSIC1_ADDR);
mcam_reg_write(mcam, REG_TWSIC1, rval);
spin_unlock_irqrestore(&mcam->dev_lock, flags);
wait_event_timeout(cam->smbus_wait,
cafe_smbus_read_done(mcam), CAFE_SMBUS_TIMEOUT);
spin_lock_irqsave(&mcam->dev_lock, flags);
rval = mcam_reg_read(mcam, REG_TWSIC1);
spin_unlock_irqrestore(&mcam->dev_lock, flags);
if (rval & TWSIC1_ERROR) {
cam_err(cam, "SMBUS read (%02x/%02x) error\n", addr, command);
return -EIO;
}
if (!(rval & TWSIC1_RVALID)) {
cam_err(cam, "SMBUS read (%02x/%02x) timed out\n", addr,
command);
return -EIO;
}
*value = rval & 0xff;
return 0;
}
static int cafe_smbus_xfer(struct i2c_adapter *adapter, u16 addr,
unsigned short flags, char rw, u8 command,
int size, union i2c_smbus_data *data)
{
struct cafe_camera *cam = i2c_get_adapdata(adapter);
int ret = -EINVAL;
if (size != I2C_SMBUS_BYTE_DATA) {
cam_err(cam, "funky xfer size %d\n", size);
return -EINVAL;
}
if (rw == I2C_SMBUS_WRITE)
ret = cafe_smbus_write_data(cam, addr, command, data->byte);
else if (rw == I2C_SMBUS_READ)
ret = cafe_smbus_read_data(cam, addr, command, &data->byte);
return ret;
}
static void cafe_smbus_enable_irq(struct cafe_camera *cam)
{
unsigned long flags;
spin_lock_irqsave(&cam->mcam.dev_lock, flags);
mcam_reg_set_bit(&cam->mcam, REG_IRQMASK, TWSIIRQS);
spin_unlock_irqrestore(&cam->mcam.dev_lock, flags);
}
static u32 cafe_smbus_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_SMBUS_READ_BYTE_DATA |
I2C_FUNC_SMBUS_WRITE_BYTE_DATA;
}
static int cafe_smbus_setup(struct cafe_camera *cam)
{
struct i2c_adapter *adap;
int ret;
adap = kzalloc(sizeof(*adap), GFP_KERNEL);
if (adap == NULL)
return -ENOMEM;
cam->mcam.i2c_adapter = adap;
cafe_smbus_enable_irq(cam);
adap->owner = THIS_MODULE;
adap->algo = &cafe_smbus_algo;
strcpy(adap->name, "cafe_ccic");
adap->dev.parent = &cam->pdev->dev;
i2c_set_adapdata(adap, cam);
ret = i2c_add_adapter(adap);
if (ret)
printk(KERN_ERR "Unable to register cafe i2c adapter\n");
return ret;
}
static void cafe_smbus_shutdown(struct cafe_camera *cam)
{
i2c_del_adapter(cam->mcam.i2c_adapter);
kfree(cam->mcam.i2c_adapter);
}
static void cafe_ctlr_init(struct mcam_camera *mcam)
{
unsigned long flags;
spin_lock_irqsave(&mcam->dev_lock, flags);
mcam_reg_write(mcam, 0x3038, 0x8);
mcam_reg_write(mcam, 0x315c, 0x80008);
mcam_reg_write(mcam, REG_GL_CSR, GCSR_SRS|GCSR_MRS);
mcam_reg_write(mcam, REG_GL_CSR, GCSR_SRC|GCSR_MRC);
mcam_reg_write(mcam, REG_GL_CSR, GCSR_SRC|GCSR_MRS);
spin_unlock_irqrestore(&mcam->dev_lock, flags);
msleep(5);
spin_lock_irqsave(&mcam->dev_lock, flags);
mcam_reg_write(mcam, REG_GL_CSR, GCSR_CCIC_EN|GCSR_SRC|GCSR_MRC);
mcam_reg_set_bit(mcam, REG_GL_IMASK, GIMSK_CCIC_EN);
mcam_reg_write(mcam, REG_IRQMASK, 0);
spin_unlock_irqrestore(&mcam->dev_lock, flags);
}
static int cafe_ctlr_power_up(struct mcam_camera *mcam)
{
mcam_reg_write(mcam, REG_GL_FCR, GFCR_GPIO_ON);
mcam_reg_write(mcam, REG_GL_GPIOR, GGPIO_OUT|GGPIO_VAL);
mcam_reg_write(mcam, REG_GPR, GPR_C1EN|GPR_C0EN);
mcam_reg_write(mcam, REG_GPR, GPR_C1EN|GPR_C0EN|GPR_C0);
return 0;
}
static void cafe_ctlr_power_down(struct mcam_camera *mcam)
{
mcam_reg_write(mcam, REG_GPR, GPR_C1EN|GPR_C0EN|GPR_C1);
mcam_reg_write(mcam, REG_GL_FCR, GFCR_GPIO_ON);
mcam_reg_write(mcam, REG_GL_GPIOR, GGPIO_OUT);
}
static irqreturn_t cafe_irq(int irq, void *data)
{
struct cafe_camera *cam = data;
struct mcam_camera *mcam = &cam->mcam;
unsigned int irqs, handled;
spin_lock(&mcam->dev_lock);
irqs = mcam_reg_read(mcam, REG_IRQSTAT);
handled = cam->registered && mccic_irq(mcam, irqs);
if (irqs & TWSIIRQS) {
mcam_reg_write(mcam, REG_IRQSTAT, TWSIIRQS);
wake_up(&cam->smbus_wait);
handled = 1;
}
spin_unlock(&mcam->dev_lock);
return IRQ_RETVAL(handled);
}
static int cafe_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
int ret;
struct cafe_camera *cam;
struct mcam_camera *mcam;
ret = -ENOMEM;
cam = kzalloc(sizeof(struct cafe_camera), GFP_KERNEL);
if (cam == NULL)
goto out;
cam->pdev = pdev;
mcam = &cam->mcam;
mcam->chip_id = MCAM_CAFE;
spin_lock_init(&mcam->dev_lock);
init_waitqueue_head(&cam->smbus_wait);
mcam->plat_power_up = cafe_ctlr_power_up;
mcam->plat_power_down = cafe_ctlr_power_down;
mcam->dev = &pdev->dev;
mcam->clock_speed = 45;
mcam->use_smbus = 1;
mcam->buffer_mode = B_vmalloc;
ret = pci_enable_device(pdev);
if (ret)
goto out_free;
pci_set_master(pdev);
ret = -EIO;
mcam->regs = pci_iomap(pdev, 0, 0);
if (!mcam->regs) {
printk(KERN_ERR "Unable to ioremap cafe-ccic regs\n");
goto out_disable;
}
mcam->regs_size = pci_resource_len(pdev, 0);
ret = request_irq(pdev->irq, cafe_irq, IRQF_SHARED, "cafe-ccic", cam);
if (ret)
goto out_iounmap;
cafe_ctlr_init(mcam);
cafe_ctlr_power_up(mcam);
ret = cafe_smbus_setup(cam);
if (ret)
goto out_pdown;
ret = mccic_register(mcam);
if (ret == 0) {
cam->registered = 1;
return 0;
}
cafe_smbus_shutdown(cam);
out_pdown:
cafe_ctlr_power_down(mcam);
free_irq(pdev->irq, cam);
out_iounmap:
pci_iounmap(pdev, mcam->regs);
out_disable:
pci_disable_device(pdev);
out_free:
kfree(cam);
out:
return ret;
}
static void cafe_shutdown(struct cafe_camera *cam)
{
mccic_shutdown(&cam->mcam);
cafe_smbus_shutdown(cam);
free_irq(cam->pdev->irq, cam);
pci_iounmap(cam->pdev, cam->mcam.regs);
}
static void cafe_pci_remove(struct pci_dev *pdev)
{
struct v4l2_device *v4l2_dev = dev_get_drvdata(&pdev->dev);
struct cafe_camera *cam = to_cam(v4l2_dev);
if (cam == NULL) {
printk(KERN_WARNING "pci_remove on unknown pdev %p\n", pdev);
return;
}
cafe_shutdown(cam);
kfree(cam);
}
static int cafe_pci_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct v4l2_device *v4l2_dev = dev_get_drvdata(&pdev->dev);
struct cafe_camera *cam = to_cam(v4l2_dev);
int ret;
ret = pci_save_state(pdev);
if (ret)
return ret;
mccic_suspend(&cam->mcam);
pci_disable_device(pdev);
return 0;
}
static int cafe_pci_resume(struct pci_dev *pdev)
{
struct v4l2_device *v4l2_dev = dev_get_drvdata(&pdev->dev);
struct cafe_camera *cam = to_cam(v4l2_dev);
int ret = 0;
pci_restore_state(pdev);
ret = pci_enable_device(pdev);
if (ret) {
cam_warn(cam, "Unable to re-enable device on resume!\n");
return ret;
}
cafe_ctlr_init(&cam->mcam);
return mccic_resume(&cam->mcam);
}
static int __init cafe_init(void)
{
int ret;
printk(KERN_NOTICE "Marvell M88ALP01 'CAFE' Camera Controller version %d\n",
CAFE_VERSION);
ret = pci_register_driver(&cafe_pci_driver);
if (ret) {
printk(KERN_ERR "Unable to register cafe_ccic driver\n");
goto out;
}
ret = 0;
out:
return ret;
}
static void __exit cafe_exit(void)
{
pci_unregister_driver(&cafe_pci_driver);
}
