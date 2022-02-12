static void hdmi_i2c_irq_enable(struct oaktrail_hdmi_dev *hdmi_dev)
{
u32 temp;
temp = HDMI_READ(HDMI_HICR);
temp |= (HDMI_INTR_I2C_ERROR | HDMI_INTR_I2C_FULL | HDMI_INTR_I2C_DONE);
HDMI_WRITE(HDMI_HICR, temp);
HDMI_READ(HDMI_HICR);
}
static void hdmi_i2c_irq_disable(struct oaktrail_hdmi_dev *hdmi_dev)
{
HDMI_WRITE(HDMI_HICR, 0x0);
HDMI_READ(HDMI_HICR);
}
static int xfer_read(struct i2c_adapter *adap, struct i2c_msg *pmsg)
{
struct oaktrail_hdmi_dev *hdmi_dev = i2c_get_adapdata(adap);
struct hdmi_i2c_dev *i2c_dev = hdmi_dev->i2c_dev;
u32 temp;
i2c_dev->status = I2C_STAT_INIT;
i2c_dev->msg = pmsg;
i2c_dev->buf_offset = 0;
INIT_COMPLETION(i2c_dev->complete);
temp = ((pmsg->len) << 20) | HI2C_EDID_READ | HI2C_ENABLE_TRANSACTION;
HDMI_WRITE(HDMI_HI2CHCR, temp);
HDMI_READ(HDMI_HI2CHCR);
while (i2c_dev->status != I2C_TRANSACTION_DONE)
wait_for_completion_interruptible_timeout(&i2c_dev->complete,
10 * HZ);
return 0;
}
static int xfer_write(struct i2c_adapter *adap, struct i2c_msg *pmsg)
{
return 0;
}
static int oaktrail_hdmi_i2c_access(struct i2c_adapter *adap,
struct i2c_msg *pmsg,
int num)
{
struct oaktrail_hdmi_dev *hdmi_dev = i2c_get_adapdata(adap);
struct hdmi_i2c_dev *i2c_dev = hdmi_dev->i2c_dev;
int i;
mutex_lock(&i2c_dev->i2c_lock);
HDMI_WRITE(HDMI_ICRH, 0x00008760);
hdmi_i2c_irq_enable(hdmi_dev);
for (i = 0; i < num; i++) {
if (pmsg->len && pmsg->buf) {
if (pmsg->flags & I2C_M_RD)
xfer_read(adap, pmsg);
else
xfer_write(adap, pmsg);
}
pmsg++;
}
hdmi_i2c_irq_disable(hdmi_dev);
mutex_unlock(&i2c_dev->i2c_lock);
return i;
}
static u32 oaktrail_hdmi_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C | I2C_FUNC_10BIT_ADDR;
}
static void hdmi_i2c_read(struct oaktrail_hdmi_dev *hdmi_dev)
{
struct hdmi_i2c_dev *i2c_dev = hdmi_dev->i2c_dev;
struct i2c_msg *msg = i2c_dev->msg;
u8 *buf = msg->buf;
u32 temp;
int i, offset;
offset = i2c_dev->buf_offset;
for (i = 0; i < 0x10; i++) {
temp = HDMI_READ(HDMI_HI2CRDB0 + (i * 4));
memcpy(buf + (offset + i * 4), &temp, 4);
}
i2c_dev->buf_offset += (0x10 * 4);
temp = HDMI_READ(HDMI_HISR);
HDMI_WRITE(HDMI_HISR, temp | HDMI_INTR_I2C_FULL);
HDMI_READ(HDMI_HISR);
temp = HDMI_READ(HDMI_HI2CHCR);
HDMI_WRITE(HDMI_HI2CHCR, temp | HI2C_READ_CONTINUE);
HDMI_READ(HDMI_HI2CHCR);
i2c_dev->status = I2C_READ_DONE;
return;
}
static void hdmi_i2c_transaction_done(struct oaktrail_hdmi_dev *hdmi_dev)
{
struct hdmi_i2c_dev *i2c_dev = hdmi_dev->i2c_dev;
u32 temp;
temp = HDMI_READ(HDMI_HISR);
HDMI_WRITE(HDMI_HISR, temp | HDMI_INTR_I2C_DONE);
HDMI_READ(HDMI_HISR);
temp = HDMI_READ(HDMI_HI2CHCR);
HDMI_WRITE(HDMI_HI2CHCR, temp & ~HI2C_ENABLE_TRANSACTION);
HDMI_READ(HDMI_HI2CHCR);
i2c_dev->status = I2C_TRANSACTION_DONE;
return;
}
static irqreturn_t oaktrail_hdmi_i2c_handler(int this_irq, void *dev)
{
struct oaktrail_hdmi_dev *hdmi_dev = dev;
struct hdmi_i2c_dev *i2c_dev = hdmi_dev->i2c_dev;
u32 stat;
stat = HDMI_READ(HDMI_HISR);
if (stat & HDMI_INTR_HPD) {
HDMI_WRITE(HDMI_HISR, stat | HDMI_INTR_HPD);
HDMI_READ(HDMI_HISR);
}
if (stat & HDMI_INTR_I2C_FULL)
hdmi_i2c_read(hdmi_dev);
if (stat & HDMI_INTR_I2C_DONE)
hdmi_i2c_transaction_done(hdmi_dev);
complete(&i2c_dev->complete);
return IRQ_HANDLED;
}
static void oaktrail_hdmi_i2c_gpio_fix(void)
{
void __iomem *base;
unsigned int gpio_base = 0xff12c000;
int gpio_len = 0x1000;
u32 temp;
base = ioremap((resource_size_t)gpio_base, gpio_len);
if (base == NULL) {
DRM_ERROR("gpio ioremap fail\n");
return;
}
temp = readl(base + 0x44);
DRM_DEBUG_DRIVER("old gpio val %x\n", temp);
writel((temp | 0x00000a00), (base + 0x44));
temp = readl(base + 0x44);
DRM_DEBUG_DRIVER("new gpio val %x\n", temp);
iounmap(base);
}
int oaktrail_hdmi_i2c_init(struct pci_dev *dev)
{
struct oaktrail_hdmi_dev *hdmi_dev;
struct hdmi_i2c_dev *i2c_dev;
int ret;
hdmi_dev = pci_get_drvdata(dev);
i2c_dev = kzalloc(sizeof(struct hdmi_i2c_dev), GFP_KERNEL);
if (i2c_dev == NULL) {
DRM_ERROR("Can't allocate interface\n");
ret = -ENOMEM;
goto exit;
}
i2c_dev->adap = &oaktrail_hdmi_i2c_adapter;
i2c_dev->status = I2C_STAT_INIT;
init_completion(&i2c_dev->complete);
mutex_init(&i2c_dev->i2c_lock);
i2c_set_adapdata(&oaktrail_hdmi_i2c_adapter, hdmi_dev);
hdmi_dev->i2c_dev = i2c_dev;
oaktrail_hdmi_i2c_gpio_fix();
ret = request_irq(dev->irq, oaktrail_hdmi_i2c_handler, IRQF_SHARED,
oaktrail_hdmi_i2c_adapter.name, hdmi_dev);
if (ret) {
DRM_ERROR("Failed to request IRQ for I2C controller\n");
goto err;
}
ret = i2c_add_numbered_adapter(&oaktrail_hdmi_i2c_adapter);
return ret;
err:
kfree(i2c_dev);
exit:
return ret;
}
void oaktrail_hdmi_i2c_exit(struct pci_dev *dev)
{
struct oaktrail_hdmi_dev *hdmi_dev;
struct hdmi_i2c_dev *i2c_dev;
hdmi_dev = pci_get_drvdata(dev);
i2c_del_adapter(&oaktrail_hdmi_i2c_adapter);
i2c_dev = hdmi_dev->i2c_dev;
kfree(i2c_dev);
free_irq(dev->irq, hdmi_dev);
}
