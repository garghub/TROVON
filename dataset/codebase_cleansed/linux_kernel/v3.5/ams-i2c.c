static s32 ams_i2c_read(u8 reg)
{
return i2c_smbus_read_byte_data(ams_info.i2c_client, reg);
}
static int ams_i2c_write(u8 reg, u8 value)
{
return i2c_smbus_write_byte_data(ams_info.i2c_client, reg, value);
}
static int ams_i2c_cmd(enum ams_i2c_cmd cmd)
{
s32 result;
int count = 3;
ams_i2c_write(AMS_COMMAND, cmd);
msleep(5);
while (count--) {
result = ams_i2c_read(AMS_COMMAND);
if (result == 0 || result & 0x80)
return 0;
schedule_timeout_uninterruptible(HZ / 20);
}
return -1;
}
static void ams_i2c_set_irq(enum ams_irq reg, char enable)
{
if (reg & AMS_IRQ_FREEFALL) {
u8 val = ams_i2c_read(AMS_CTRLX);
if (enable)
val |= 0x80;
else
val &= ~0x80;
ams_i2c_write(AMS_CTRLX, val);
}
if (reg & AMS_IRQ_SHOCK) {
u8 val = ams_i2c_read(AMS_CTRLY);
if (enable)
val |= 0x80;
else
val &= ~0x80;
ams_i2c_write(AMS_CTRLY, val);
}
if (reg & AMS_IRQ_GLOBAL) {
u8 val = ams_i2c_read(AMS_CTRLZ);
if (enable)
val |= 0x80;
else
val &= ~0x80;
ams_i2c_write(AMS_CTRLZ, val);
}
}
static void ams_i2c_clear_irq(enum ams_irq reg)
{
if (reg & AMS_IRQ_FREEFALL)
ams_i2c_write(AMS_FREEFALL, 0);
if (reg & AMS_IRQ_SHOCK)
ams_i2c_write(AMS_SHOCK, 0);
}
static u8 ams_i2c_get_vendor(void)
{
return ams_i2c_read(AMS_VENDOR);
}
static void ams_i2c_get_xyz(s8 *x, s8 *y, s8 *z)
{
*x = ams_i2c_read(AMS_DATAX);
*y = ams_i2c_read(AMS_DATAY);
*z = ams_i2c_read(AMS_DATAZ);
}
static int ams_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int vmaj, vmin;
int result;
if (unlikely(ams_info.has_device))
return -ENODEV;
ams_info.i2c_client = client;
if (ams_i2c_cmd(AMS_CMD_RESET)) {
printk(KERN_INFO "ams: Failed to reset the device\n");
return -ENODEV;
}
if (ams_i2c_cmd(AMS_CMD_START)) {
printk(KERN_INFO "ams: Failed to start the device\n");
return -ENODEV;
}
ams_i2c_write(AMS_CTRL1, 0x02);
ams_i2c_write(AMS_CTRL2, 0x85);
ams_i2c_write(AMS_CTRL3, 0x01);
ams_i2c_cmd(AMS_CMD_READMEM);
vmaj = ams_i2c_read(AMS_DATA1);
vmin = ams_i2c_read(AMS_DATA2);
if (vmaj != 1 || vmin != 52) {
printk(KERN_INFO "ams: Incorrect device version (%d.%d)\n",
vmaj, vmin);
return -ENODEV;
}
ams_i2c_cmd(AMS_CMD_VERSION);
vmaj = ams_i2c_read(AMS_DATA1);
vmin = ams_i2c_read(AMS_DATA2);
if (vmaj != 0 || vmin != 1) {
printk(KERN_INFO "ams: Incorrect firmware version (%d.%d)\n",
vmaj, vmin);
return -ENODEV;
}
ams_i2c_set_irq(AMS_IRQ_ALL, 0);
result = ams_sensor_attach();
if (result < 0)
return result;
ams_i2c_write(AMS_SENSLOW, 0x15);
ams_i2c_write(AMS_SENSHIGH, 0x60);
ams_i2c_write(AMS_CTRLX, 0x08);
ams_i2c_write(AMS_CTRLY, 0x0F);
ams_i2c_write(AMS_CTRLZ, 0x4F);
ams_i2c_write(AMS_UNKNOWN1, 0x14);
ams_i2c_clear_irq(AMS_IRQ_ALL);
ams_info.has_device = 1;
ams_i2c_set_irq(AMS_IRQ_ALL, 1);
printk(KERN_INFO "ams: Found I2C based motion sensor\n");
return 0;
}
static int ams_i2c_remove(struct i2c_client *client)
{
if (ams_info.has_device) {
ams_sensor_detach();
ams_i2c_set_irq(AMS_IRQ_ALL, 0);
ams_i2c_clear_irq(AMS_IRQ_ALL);
printk(KERN_INFO "ams: Unloading\n");
ams_info.has_device = 0;
}
return 0;
}
static void ams_i2c_exit(void)
{
i2c_del_driver(&ams_i2c_driver);
}
int __init ams_i2c_init(struct device_node *np)
{
int result;
ams_info.of_node = np;
ams_info.exit = ams_i2c_exit;
ams_info.get_vendor = ams_i2c_get_vendor;
ams_info.get_xyz = ams_i2c_get_xyz;
ams_info.clear_irq = ams_i2c_clear_irq;
ams_info.bustype = BUS_I2C;
result = i2c_add_driver(&ams_i2c_driver);
return result;
}
