static s32 i2c_powermac_smbus_xfer( struct i2c_adapter* adap,
u16 addr,
unsigned short flags,
char read_write,
u8 command,
int size,
union i2c_smbus_data* data)
{
struct pmac_i2c_bus *bus = i2c_get_adapdata(adap);
int rc = 0;
int read = (read_write == I2C_SMBUS_READ);
int addrdir = (addr << 1) | read;
int mode, subsize, len;
u32 subaddr;
u8 *buf;
u8 local[2];
if (size == I2C_SMBUS_QUICK || size == I2C_SMBUS_BYTE) {
mode = pmac_i2c_mode_std;
subsize = 0;
subaddr = 0;
} else {
mode = read ? pmac_i2c_mode_combined : pmac_i2c_mode_stdsub;
subsize = 1;
subaddr = command;
}
switch (size) {
case I2C_SMBUS_QUICK:
buf = NULL;
len = 0;
break;
case I2C_SMBUS_BYTE:
case I2C_SMBUS_BYTE_DATA:
buf = &data->byte;
len = 1;
break;
case I2C_SMBUS_WORD_DATA:
if (!read) {
local[0] = data->word & 0xff;
local[1] = (data->word >> 8) & 0xff;
}
buf = local;
len = 2;
break;
case I2C_SMBUS_BLOCK_DATA:
buf = data->block;
len = data->block[0] + 1;
break;
case I2C_SMBUS_I2C_BLOCK_DATA:
buf = &data->block[1];
len = data->block[0];
break;
default:
return -EINVAL;
}
rc = pmac_i2c_open(bus, 0);
if (rc) {
dev_err(&adap->dev, "Failed to open I2C, err %d\n", rc);
return rc;
}
rc = pmac_i2c_setmode(bus, mode);
if (rc) {
dev_err(&adap->dev, "Failed to set I2C mode %d, err %d\n",
mode, rc);
goto bail;
}
rc = pmac_i2c_xfer(bus, addrdir, subsize, subaddr, buf, len);
if (rc) {
if (rc == -ENXIO)
dev_dbg(&adap->dev,
"I2C transfer at 0x%02x failed, size %d, "
"err %d\n", addrdir >> 1, size, rc);
else
dev_err(&adap->dev,
"I2C transfer at 0x%02x failed, size %d, "
"err %d\n", addrdir >> 1, size, rc);
goto bail;
}
if (size == I2C_SMBUS_WORD_DATA && read) {
data->word = ((u16)local[1]) << 8;
data->word |= local[0];
}
bail:
pmac_i2c_close(bus);
return rc;
}
static int i2c_powermac_master_xfer( struct i2c_adapter *adap,
struct i2c_msg *msgs,
int num)
{
struct pmac_i2c_bus *bus = i2c_get_adapdata(adap);
int rc = 0;
int read;
int addrdir;
if (num != 1) {
dev_err(&adap->dev,
"Multi-message I2C transactions not supported\n");
return -EOPNOTSUPP;
}
if (msgs->flags & I2C_M_TEN)
return -EINVAL;
read = (msgs->flags & I2C_M_RD) != 0;
addrdir = (msgs->addr << 1) | read;
rc = pmac_i2c_open(bus, 0);
if (rc) {
dev_err(&adap->dev, "Failed to open I2C, err %d\n", rc);
return rc;
}
rc = pmac_i2c_setmode(bus, pmac_i2c_mode_std);
if (rc) {
dev_err(&adap->dev, "Failed to set I2C mode %d, err %d\n",
pmac_i2c_mode_std, rc);
goto bail;
}
rc = pmac_i2c_xfer(bus, addrdir, 0, 0, msgs->buf, msgs->len);
if (rc < 0) {
if (rc == -ENXIO)
dev_dbg(&adap->dev, "I2C %s 0x%02x failed, err %d\n",
addrdir & 1 ? "read from" : "write to",
addrdir >> 1, rc);
else
dev_err(&adap->dev, "I2C %s 0x%02x failed, err %d\n",
addrdir & 1 ? "read from" : "write to",
addrdir >> 1, rc);
}
bail:
pmac_i2c_close(bus);
return rc < 0 ? rc : 1;
}
static u32 i2c_powermac_func(struct i2c_adapter * adapter)
{
return I2C_FUNC_SMBUS_QUICK | I2C_FUNC_SMBUS_BYTE |
I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA |
I2C_FUNC_SMBUS_BLOCK_DATA | I2C_FUNC_I2C;
}
static int __devexit i2c_powermac_remove(struct platform_device *dev)
{
struct i2c_adapter *adapter = platform_get_drvdata(dev);
int rc;
rc = i2c_del_adapter(adapter);
if (rc)
printk(KERN_WARNING
"i2c-powermac.c: Failed to remove bus %s !\n",
adapter->name);
platform_set_drvdata(dev, NULL);
memset(adapter, 0, sizeof(*adapter));
return 0;
}
static void __devinit i2c_powermac_register_devices(struct i2c_adapter *adap,
struct pmac_i2c_bus *bus)
{
struct i2c_client *newdev;
struct device_node *node;
for_each_child_of_node(adap->dev.of_node, node) {
struct i2c_board_info info = {};
struct dev_archdata dev_ad = {};
const __be32 *reg;
char tmp[16];
u32 addr;
int len;
reg = of_get_property(node, "reg", &len);
if (!reg || (len < sizeof(int))) {
dev_err(&adap->dev, "i2c-powermac: invalid reg on %s\n",
node->full_name);
continue;
}
addr = be32_to_cpup(reg);
if (!pmac_i2c_match_adapter(node, adap))
continue;
dev_dbg(&adap->dev, "i2c-powermac: register %s\n",
node->full_name);
if (of_modalias_node(node, tmp, sizeof(tmp)) < 0) {
dev_err(&adap->dev, "i2c-powermac: modalias failure"
" on %s\n", node->full_name);
continue;
}
snprintf(info.type, sizeof(info.type), "MAC,%s", tmp);
info.addr = (addr & 0xff) >> 1;
info.irq = irq_of_parse_and_map(node, 0);
info.of_node = of_node_get(node);
info.archdata = &dev_ad;
newdev = i2c_new_device(adap, &info);
if (!newdev) {
dev_err(&adap->dev, "i2c-powermac: Failure to register"
" %s\n", node->full_name);
of_node_put(node);
continue;
}
}
}
static int __devinit i2c_powermac_probe(struct platform_device *dev)
{
struct pmac_i2c_bus *bus = dev->dev.platform_data;
struct device_node *parent = NULL;
struct i2c_adapter *adapter;
const char *basename;
int rc;
if (bus == NULL)
return -EINVAL;
adapter = pmac_i2c_get_adapter(bus);
switch(pmac_i2c_get_type(bus)) {
case pmac_i2c_bus_keywest:
parent = of_get_parent(pmac_i2c_get_controller(bus));
if (parent == NULL)
return -EINVAL;
basename = parent->name;
break;
case pmac_i2c_bus_pmu:
basename = "pmu";
break;
case pmac_i2c_bus_smu:
basename = "smu";
break;
default:
return -EINVAL;
}
snprintf(adapter->name, sizeof(adapter->name), "%s %d", basename,
pmac_i2c_get_channel(bus));
of_node_put(parent);
platform_set_drvdata(dev, adapter);
adapter->algo = &i2c_powermac_algorithm;
i2c_set_adapdata(adapter, bus);
adapter->dev.parent = &dev->dev;
adapter->dev.of_node = dev->dev.of_node;
rc = i2c_add_adapter(adapter);
if (rc) {
printk(KERN_ERR "i2c-powermac: Adapter %s registration "
"failed\n", adapter->name);
memset(adapter, 0, sizeof(*adapter));
}
printk(KERN_INFO "PowerMac i2c bus %s registered\n", adapter->name);
i2c_powermac_register_devices(adapter, bus);
return rc;
}
