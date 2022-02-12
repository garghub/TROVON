static int fsa9480_write_reg(struct i2c_client *client,
int reg, int value)
{
int ret;
ret = i2c_smbus_write_byte_data(client, reg, value);
if (ret < 0)
dev_err(&client->dev, "%s: err %d\n", __func__, ret);
return ret;
}
static int fsa9480_read_reg(struct i2c_client *client, int reg)
{
int ret;
ret = i2c_smbus_read_byte_data(client, reg);
if (ret < 0)
dev_err(&client->dev, "%s: err %d\n", __func__, ret);
return ret;
}
static int fsa9480_read_irq(struct i2c_client *client, int *value)
{
int ret;
ret = i2c_smbus_read_i2c_block_data(client,
FSA9480_REG_INT1, 2, (u8 *)value);
*value &= 0xffff;
if (ret < 0)
dev_err(&client->dev, "%s: err %d\n", __func__, ret);
return ret;
}
static void fsa9480_set_switch(const char *buf)
{
struct fsa9480_usbsw *usbsw = chip;
struct i2c_client *client = usbsw->client;
unsigned int value;
unsigned int path = 0;
value = fsa9480_read_reg(client, FSA9480_REG_CTRL);
if (!strncmp(buf, "VAUDIO", 6)) {
path = SW_VAUDIO;
value &= ~CON_MANUAL_SW;
} else if (!strncmp(buf, "UART", 4)) {
path = SW_UART;
value &= ~CON_MANUAL_SW;
} else if (!strncmp(buf, "AUDIO", 5)) {
path = SW_AUDIO;
value &= ~CON_MANUAL_SW;
} else if (!strncmp(buf, "DHOST", 5)) {
path = SW_DHOST;
value &= ~CON_MANUAL_SW;
} else if (!strncmp(buf, "AUTO", 4)) {
path = SW_AUTO;
value |= CON_MANUAL_SW;
} else {
printk(KERN_ERR "Wrong command\n");
return;
}
usbsw->mansw = path;
fsa9480_write_reg(client, FSA9480_REG_MANSW1, path);
fsa9480_write_reg(client, FSA9480_REG_CTRL, value);
}
static ssize_t fsa9480_get_switch(char *buf)
{
struct fsa9480_usbsw *usbsw = chip;
struct i2c_client *client = usbsw->client;
unsigned int value;
value = fsa9480_read_reg(client, FSA9480_REG_MANSW1);
if (value == SW_VAUDIO)
return sprintf(buf, "VAUDIO\n");
else if (value == SW_UART)
return sprintf(buf, "UART\n");
else if (value == SW_AUDIO)
return sprintf(buf, "AUDIO\n");
else if (value == SW_DHOST)
return sprintf(buf, "DHOST\n");
else if (value == SW_AUTO)
return sprintf(buf, "AUTO\n");
else
return sprintf(buf, "%x", value);
}
static ssize_t fsa9480_show_device(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct fsa9480_usbsw *usbsw = dev_get_drvdata(dev);
struct i2c_client *client = usbsw->client;
int dev1, dev2;
dev1 = fsa9480_read_reg(client, FSA9480_REG_DEV_T1);
dev2 = fsa9480_read_reg(client, FSA9480_REG_DEV_T2);
if (!dev1 && !dev2)
return sprintf(buf, "NONE\n");
if (dev1 & DEV_T1_USB_MASK || dev2 & DEV_T2_USB_MASK)
return sprintf(buf, "USB\n");
if (dev1 & DEV_T1_UART_MASK || dev2 & DEV_T2_UART_MASK)
return sprintf(buf, "UART\n");
if (dev1 & DEV_T1_CHARGER_MASK)
return sprintf(buf, "CHARGER\n");
if (dev2 & DEV_T2_JIG_MASK)
return sprintf(buf, "JIG\n");
return sprintf(buf, "UNKNOWN\n");
}
static ssize_t fsa9480_show_manualsw(struct device *dev,
struct device_attribute *attr, char *buf)
{
return fsa9480_get_switch(buf);
}
static ssize_t fsa9480_set_manualsw(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
fsa9480_set_switch(buf);
return count;
}
static void fsa9480_detect_dev(struct fsa9480_usbsw *usbsw, int intr)
{
int val1, val2, ctrl;
struct fsa9480_platform_data *pdata = usbsw->pdata;
struct i2c_client *client = usbsw->client;
val1 = fsa9480_read_reg(client, FSA9480_REG_DEV_T1);
val2 = fsa9480_read_reg(client, FSA9480_REG_DEV_T2);
ctrl = fsa9480_read_reg(client, FSA9480_REG_CTRL);
dev_info(&client->dev, "intr: 0x%x, dev1: 0x%x, dev2: 0x%x\n",
intr, val1, val2);
if (!intr)
goto out;
if (intr & INT_ATTACH) {
if (val1 & DEV_T1_USB_MASK || val2 & DEV_T2_USB_MASK) {
if (pdata->usb_cb)
pdata->usb_cb(FSA9480_ATTACHED);
if (usbsw->mansw) {
fsa9480_write_reg(client,
FSA9480_REG_MANSW1, usbsw->mansw);
}
}
if (val1 & DEV_T1_UART_MASK || val2 & DEV_T2_UART_MASK) {
if (pdata->uart_cb)
pdata->uart_cb(FSA9480_ATTACHED);
if (!(ctrl & CON_MANUAL_SW)) {
fsa9480_write_reg(client,
FSA9480_REG_MANSW1, SW_UART);
}
}
if (val1 & DEV_T1_CHARGER_MASK) {
if (pdata->charger_cb)
pdata->charger_cb(FSA9480_ATTACHED);
}
if (val2 & DEV_T2_JIG_MASK) {
if (pdata->jig_cb)
pdata->jig_cb(FSA9480_ATTACHED);
}
} else if (intr & INT_DETACH) {
if (usbsw->dev1 & DEV_T1_USB_MASK ||
usbsw->dev2 & DEV_T2_USB_MASK) {
if (pdata->usb_cb)
pdata->usb_cb(FSA9480_DETACHED);
}
if (usbsw->dev1 & DEV_T1_UART_MASK ||
usbsw->dev2 & DEV_T2_UART_MASK) {
if (pdata->uart_cb)
pdata->uart_cb(FSA9480_DETACHED);
}
if (usbsw->dev1 & DEV_T1_CHARGER_MASK) {
if (pdata->charger_cb)
pdata->charger_cb(FSA9480_DETACHED);
}
if (usbsw->dev2 & DEV_T2_JIG_MASK) {
if (pdata->jig_cb)
pdata->jig_cb(FSA9480_DETACHED);
}
}
usbsw->dev1 = val1;
usbsw->dev2 = val2;
out:
ctrl &= ~CON_INT_MASK;
fsa9480_write_reg(client, FSA9480_REG_CTRL, ctrl);
}
static irqreturn_t fsa9480_irq_handler(int irq, void *data)
{
struct fsa9480_usbsw *usbsw = data;
struct i2c_client *client = usbsw->client;
int intr;
fsa9480_read_irq(client, &intr);
fsa9480_detect_dev(usbsw, intr);
return IRQ_HANDLED;
}
static int fsa9480_irq_init(struct fsa9480_usbsw *usbsw)
{
struct fsa9480_platform_data *pdata = usbsw->pdata;
struct i2c_client *client = usbsw->client;
int ret;
int intr;
unsigned int ctrl = CON_MASK;
fsa9480_read_irq(client, &intr);
fsa9480_write_reg(client, FSA9480_REG_INT1_MASK, 0xfc);
fsa9480_write_reg(client, FSA9480_REG_INT2_MASK, 0x1f);
usbsw->mansw = fsa9480_read_reg(client, FSA9480_REG_MANSW1);
if (usbsw->mansw)
ctrl &= ~CON_MANUAL_SW;
fsa9480_write_reg(client, FSA9480_REG_CTRL, ctrl);
if (pdata && pdata->cfg_gpio)
pdata->cfg_gpio();
if (client->irq) {
ret = request_threaded_irq(client->irq, NULL,
fsa9480_irq_handler,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"fsa9480 micro USB", usbsw);
if (ret) {
dev_err(&client->dev, "failed to reqeust IRQ\n");
return ret;
}
if (pdata)
device_init_wakeup(&client->dev, pdata->wakeup);
}
return 0;
}
static int fsa9480_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct i2c_adapter *adapter = to_i2c_adapter(client->dev.parent);
struct fsa9480_usbsw *usbsw;
int ret = 0;
if (!i2c_check_functionality(adapter, I2C_FUNC_SMBUS_BYTE_DATA))
return -EIO;
usbsw = kzalloc(sizeof(struct fsa9480_usbsw), GFP_KERNEL);
if (!usbsw) {
dev_err(&client->dev, "failed to allocate driver data\n");
return -ENOMEM;
}
usbsw->client = client;
usbsw->pdata = client->dev.platform_data;
chip = usbsw;
i2c_set_clientdata(client, usbsw);
ret = fsa9480_irq_init(usbsw);
if (ret)
goto fail1;
ret = sysfs_create_group(&client->dev.kobj, &fsa9480_group);
if (ret) {
dev_err(&client->dev,
"failed to create fsa9480 attribute group\n");
goto fail2;
}
fsa9480_write_reg(client, FSA9480_REG_TIMING1, 0x6);
if (chip->pdata->reset_cb)
chip->pdata->reset_cb();
fsa9480_detect_dev(usbsw, INT_ATTACH);
pm_runtime_set_active(&client->dev);
return 0;
fail2:
if (client->irq)
free_irq(client->irq, usbsw);
fail1:
kfree(usbsw);
return ret;
}
static int fsa9480_remove(struct i2c_client *client)
{
struct fsa9480_usbsw *usbsw = i2c_get_clientdata(client);
if (client->irq)
free_irq(client->irq, usbsw);
sysfs_remove_group(&client->dev.kobj, &fsa9480_group);
device_init_wakeup(&client->dev, 0);
kfree(usbsw);
return 0;
}
static int fsa9480_suspend(struct i2c_client *client, pm_message_t state)
{
struct fsa9480_usbsw *usbsw = i2c_get_clientdata(client);
struct fsa9480_platform_data *pdata = usbsw->pdata;
if (device_may_wakeup(&client->dev) && client->irq)
enable_irq_wake(client->irq);
if (pdata->usb_power)
pdata->usb_power(0);
return 0;
}
static int fsa9480_resume(struct i2c_client *client)
{
struct fsa9480_usbsw *usbsw = i2c_get_clientdata(client);
int dev1, dev2;
if (device_may_wakeup(&client->dev) && client->irq)
disable_irq_wake(client->irq);
fsa9480_read_reg(client, FSA9480_REG_INT1);
fsa9480_read_reg(client, FSA9480_REG_INT2);
dev1 = fsa9480_read_reg(client, FSA9480_REG_DEV_T1);
dev2 = fsa9480_read_reg(client, FSA9480_REG_DEV_T2);
fsa9480_detect_dev(usbsw, (dev1 || dev2) ? INT_ATTACH : INT_DETACH);
return 0;
}
