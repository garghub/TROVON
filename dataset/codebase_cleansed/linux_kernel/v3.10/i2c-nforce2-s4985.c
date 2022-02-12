static s32 nforce2_access_virt0(struct i2c_adapter *adap, u16 addr,
unsigned short flags, char read_write,
u8 command, int size,
union i2c_smbus_data *data)
{
int error;
if ((addr & 0xfc) == 0x50 || (addr & 0xfc) == 0x30
|| addr == 0x18)
return -ENXIO;
mutex_lock(&nforce2_lock);
error = nforce2_smbus->algo->smbus_xfer(adap, addr, flags, read_write,
command, size, data);
mutex_unlock(&nforce2_lock);
return error;
}
static inline s32 nforce2_access_channel(struct i2c_adapter *adap, u16 addr,
unsigned short flags, char read_write,
u8 command, int size,
union i2c_smbus_data *data,
u8 channels)
{
int error;
if ((addr & 0xfc) != 0x50 && (addr & 0xfc) != 0x30)
return -ENXIO;
mutex_lock(&nforce2_lock);
if (last_channels != channels) {
union i2c_smbus_data mplxdata;
mplxdata.byte = channels;
error = nforce2_smbus->algo->smbus_xfer(adap, 0x18, 0,
I2C_SMBUS_WRITE, 0x01,
I2C_SMBUS_BYTE_DATA,
&mplxdata);
if (error)
goto UNLOCK;
last_channels = channels;
}
error = nforce2_smbus->algo->smbus_xfer(adap, addr, flags, read_write,
command, size, data);
UNLOCK:
mutex_unlock(&nforce2_lock);
return error;
}
static s32 nforce2_access_virt1(struct i2c_adapter *adap, u16 addr,
unsigned short flags, char read_write,
u8 command, int size,
union i2c_smbus_data *data)
{
return nforce2_access_channel(adap, addr, flags, read_write, command,
size, data, 0x02);
}
static s32 nforce2_access_virt2(struct i2c_adapter *adap, u16 addr,
unsigned short flags, char read_write,
u8 command, int size,
union i2c_smbus_data *data)
{
return nforce2_access_channel(adap, addr, flags, read_write, command,
size, data, 0x04);
}
static s32 nforce2_access_virt3(struct i2c_adapter *adap, u16 addr,
unsigned short flags, char read_write,
u8 command, int size,
union i2c_smbus_data *data)
{
return nforce2_access_channel(adap, addr, flags, read_write, command,
size, data, 0x08);
}
static s32 nforce2_access_virt4(struct i2c_adapter *adap, u16 addr,
unsigned short flags, char read_write,
u8 command, int size,
union i2c_smbus_data *data)
{
return nforce2_access_channel(adap, addr, flags, read_write, command,
size, data, 0x10);
}
static int __init nforce2_s4985_init(void)
{
int i, error;
union i2c_smbus_data ioconfig;
if (!nforce2_smbus)
return -ENODEV;
ioconfig.byte = 0x00;
error = i2c_smbus_xfer(nforce2_smbus, 0x18, 0, I2C_SMBUS_WRITE, 0x03,
I2C_SMBUS_BYTE_DATA, &ioconfig);
if (error) {
dev_err(&nforce2_smbus->dev, "PCA9556 configuration failed\n");
error = -EIO;
goto ERROR0;
}
i2c_del_adapter(nforce2_smbus);
printk(KERN_INFO "Enabling SMBus multiplexing for Tyan S4985\n");
s4985_adapter = kzalloc(5 * sizeof(struct i2c_adapter), GFP_KERNEL);
if (!s4985_adapter) {
error = -ENOMEM;
goto ERROR1;
}
s4985_algo = kzalloc(5 * sizeof(struct i2c_algorithm), GFP_KERNEL);
if (!s4985_algo) {
error = -ENOMEM;
goto ERROR2;
}
s4985_algo[0] = *(nforce2_smbus->algo);
s4985_algo[0].smbus_xfer = nforce2_access_virt0;
s4985_adapter[0] = *nforce2_smbus;
s4985_adapter[0].algo = s4985_algo;
s4985_adapter[0].dev.parent = nforce2_smbus->dev.parent;
for (i = 1; i < 5; i++) {
s4985_algo[i] = *(nforce2_smbus->algo);
s4985_adapter[i] = *nforce2_smbus;
snprintf(s4985_adapter[i].name, sizeof(s4985_adapter[i].name),
"SMBus nForce2 adapter (CPU%d)", i - 1);
s4985_adapter[i].algo = s4985_algo + i;
s4985_adapter[i].dev.parent = nforce2_smbus->dev.parent;
}
s4985_algo[1].smbus_xfer = nforce2_access_virt1;
s4985_algo[2].smbus_xfer = nforce2_access_virt2;
s4985_algo[3].smbus_xfer = nforce2_access_virt3;
s4985_algo[4].smbus_xfer = nforce2_access_virt4;
for (i = 0; i < 5; i++) {
error = i2c_add_adapter(s4985_adapter + i);
if (error) {
printk(KERN_ERR "i2c-nforce2-s4985: "
"Virtual adapter %d registration "
"failed, module not inserted\n", i);
for (i--; i >= 0; i--)
i2c_del_adapter(s4985_adapter + i);
goto ERROR3;
}
}
return 0;
ERROR3:
kfree(s4985_algo);
s4985_algo = NULL;
ERROR2:
kfree(s4985_adapter);
s4985_adapter = NULL;
ERROR1:
i2c_add_adapter(nforce2_smbus);
ERROR0:
return error;
}
static void __exit nforce2_s4985_exit(void)
{
if (s4985_adapter) {
int i;
for (i = 0; i < 5; i++)
i2c_del_adapter(s4985_adapter+i);
kfree(s4985_adapter);
s4985_adapter = NULL;
}
kfree(s4985_algo);
s4985_algo = NULL;
if (i2c_add_adapter(nforce2_smbus))
printk(KERN_ERR "i2c-nforce2-s4985: "
"Physical bus restoration failed\n");
}
