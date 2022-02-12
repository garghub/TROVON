static s32 amd756_access_virt0(struct i2c_adapter * adap, u16 addr,
unsigned short flags, char read_write,
u8 command, int size,
union i2c_smbus_data * data)
{
int error;
if (addr == 0x4c || (addr & 0xfc) == 0x50 || (addr & 0xfc) == 0x30
|| addr == 0x18)
return -ENXIO;
mutex_lock(&amd756_lock);
error = amd756_smbus.algo->smbus_xfer(adap, addr, flags, read_write,
command, size, data);
mutex_unlock(&amd756_lock);
return error;
}
static inline s32 amd756_access_channel(struct i2c_adapter * adap, u16 addr,
unsigned short flags, char read_write,
u8 command, int size,
union i2c_smbus_data * data,
u8 channels)
{
int error;
if (addr != 0x4c && (addr & 0xfc) != 0x50 && (addr & 0xfc) != 0x30)
return -ENXIO;
mutex_lock(&amd756_lock);
if (last_channels != channels) {
union i2c_smbus_data mplxdata;
mplxdata.byte = channels;
error = amd756_smbus.algo->smbus_xfer(adap, 0x18, 0,
I2C_SMBUS_WRITE, 0x01,
I2C_SMBUS_BYTE_DATA,
&mplxdata);
if (error)
goto UNLOCK;
last_channels = channels;
}
error = amd756_smbus.algo->smbus_xfer(adap, addr, flags, read_write,
command, size, data);
UNLOCK:
mutex_unlock(&amd756_lock);
return error;
}
static s32 amd756_access_virt1(struct i2c_adapter * adap, u16 addr,
unsigned short flags, char read_write,
u8 command, int size,
union i2c_smbus_data * data)
{
return amd756_access_channel(adap, addr, flags, read_write, command,
size, data, 0x03);
}
static s32 amd756_access_virt2(struct i2c_adapter * adap, u16 addr,
unsigned short flags, char read_write,
u8 command, int size,
union i2c_smbus_data * data)
{
return amd756_access_channel(adap, addr, flags, read_write, command,
size, data, 0x24);
}
static s32 amd756_access_virt3(struct i2c_adapter * adap, u16 addr,
unsigned short flags, char read_write,
u8 command, int size,
union i2c_smbus_data * data)
{
return amd756_access_channel(adap, addr, flags, read_write, command,
size, data, 0x48);
}
static s32 amd756_access_virt4(struct i2c_adapter * adap, u16 addr,
unsigned short flags, char read_write,
u8 command, int size,
union i2c_smbus_data * data)
{
return amd756_access_channel(adap, addr, flags, read_write, command,
size, data, 0x90);
}
static int __init amd756_s4882_init(void)
{
int i, error;
union i2c_smbus_data ioconfig;
if (!amd756_smbus.dev.parent)
return -ENODEV;
ioconfig.byte = 0x00;
error = i2c_smbus_xfer(&amd756_smbus, 0x18, 0, I2C_SMBUS_WRITE, 0x03,
I2C_SMBUS_BYTE_DATA, &ioconfig);
if (error) {
dev_err(&amd756_smbus.dev, "PCA9556 configuration failed\n");
error = -EIO;
goto ERROR0;
}
error = i2c_del_adapter(&amd756_smbus);
if (error) {
dev_err(&amd756_smbus.dev, "Physical bus removal failed\n");
goto ERROR0;
}
printk(KERN_INFO "Enabling SMBus multiplexing for Tyan S4882\n");
if (!(s4882_adapter = kzalloc(5 * sizeof(struct i2c_adapter),
GFP_KERNEL))) {
error = -ENOMEM;
goto ERROR1;
}
if (!(s4882_algo = kzalloc(5 * sizeof(struct i2c_algorithm),
GFP_KERNEL))) {
error = -ENOMEM;
goto ERROR2;
}
s4882_algo[0] = *(amd756_smbus.algo);
s4882_algo[0].smbus_xfer = amd756_access_virt0;
s4882_adapter[0] = amd756_smbus;
s4882_adapter[0].algo = s4882_algo;
s4882_adapter[0].dev.parent = amd756_smbus.dev.parent;
for (i = 1; i < 5; i++) {
s4882_algo[i] = *(amd756_smbus.algo);
s4882_adapter[i] = amd756_smbus;
snprintf(s4882_adapter[i].name, sizeof(s4882_adapter[i].name),
"SMBus 8111 adapter (CPU%d)", i-1);
s4882_adapter[i].algo = s4882_algo+i;
s4882_adapter[i].dev.parent = amd756_smbus.dev.parent;
}
s4882_algo[1].smbus_xfer = amd756_access_virt1;
s4882_algo[2].smbus_xfer = amd756_access_virt2;
s4882_algo[3].smbus_xfer = amd756_access_virt3;
s4882_algo[4].smbus_xfer = amd756_access_virt4;
for (i = 0; i < 5; i++) {
error = i2c_add_adapter(s4882_adapter+i);
if (error) {
printk(KERN_ERR "i2c-amd756-s4882: "
"Virtual adapter %d registration "
"failed, module not inserted\n", i);
for (i--; i >= 0; i--)
i2c_del_adapter(s4882_adapter+i);
goto ERROR3;
}
}
return 0;
ERROR3:
kfree(s4882_algo);
s4882_algo = NULL;
ERROR2:
kfree(s4882_adapter);
s4882_adapter = NULL;
ERROR1:
i2c_add_adapter(&amd756_smbus);
ERROR0:
return error;
}
static void __exit amd756_s4882_exit(void)
{
if (s4882_adapter) {
int i;
for (i = 0; i < 5; i++)
i2c_del_adapter(s4882_adapter+i);
kfree(s4882_adapter);
s4882_adapter = NULL;
}
kfree(s4882_algo);
s4882_algo = NULL;
if (i2c_add_adapter(&amd756_smbus))
printk(KERN_ERR "i2c-amd756-s4882: "
"Physical bus restoration failed\n");
}
