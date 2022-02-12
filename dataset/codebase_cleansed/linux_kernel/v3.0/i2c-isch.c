static int sch_transaction(void)
{
int temp;
int result = 0;
int timeout = 0;
dev_dbg(&sch_adapter.dev, "Transaction (pre): CNT=%02x, CMD=%02x, "
"ADD=%02x, DAT0=%02x, DAT1=%02x\n", inb(SMBHSTCNT),
inb(SMBHSTCMD), inb(SMBHSTADD), inb(SMBHSTDAT0),
inb(SMBHSTDAT1));
temp = inb(SMBHSTSTS) & 0x0f;
if (temp) {
if (temp & 0x01) {
dev_dbg(&sch_adapter.dev, "Completion (%02x). "
"Clear...\n", temp);
}
if (temp & 0x06) {
dev_dbg(&sch_adapter.dev, "SMBus error (%02x). "
"Resetting...\n", temp);
}
outb(temp, SMBHSTSTS);
temp = inb(SMBHSTSTS) & 0x0f;
if (temp) {
dev_err(&sch_adapter.dev,
"SMBus is not ready: (%02x)\n", temp);
return -EAGAIN;
}
}
outb(inb(SMBHSTCNT) | 0x10, SMBHSTCNT);
do {
msleep(1);
temp = inb(SMBHSTSTS) & 0x0f;
} while ((temp & 0x08) && (timeout++ < MAX_TIMEOUT));
if (timeout > MAX_TIMEOUT) {
dev_err(&sch_adapter.dev, "SMBus Timeout!\n");
result = -ETIMEDOUT;
}
if (temp & 0x04) {
result = -EIO;
dev_dbg(&sch_adapter.dev, "Bus collision! SMBus may be "
"locked until next hard reset. (sorry!)\n");
} else if (temp & 0x02) {
result = -EIO;
dev_err(&sch_adapter.dev, "Error: no response!\n");
} else if (temp & 0x01) {
dev_dbg(&sch_adapter.dev, "Post complete!\n");
outb(temp, SMBHSTSTS);
temp = inb(SMBHSTSTS) & 0x07;
if (temp & 0x06) {
dev_dbg(&sch_adapter.dev, "Failed reset at end of "
"transaction (%02x), Bus error!\n", temp);
}
} else {
result = -ENXIO;
dev_dbg(&sch_adapter.dev, "No such address.\n");
}
dev_dbg(&sch_adapter.dev, "Transaction (post): CNT=%02x, CMD=%02x, "
"ADD=%02x, DAT0=%02x, DAT1=%02x\n", inb(SMBHSTCNT),
inb(SMBHSTCMD), inb(SMBHSTADD), inb(SMBHSTDAT0),
inb(SMBHSTDAT1));
return result;
}
static s32 sch_access(struct i2c_adapter *adap, u16 addr,
unsigned short flags, char read_write,
u8 command, int size, union i2c_smbus_data *data)
{
int i, len, temp, rc;
temp = inb(SMBHSTSTS) & 0x0f;
if (temp & 0x08) {
dev_dbg(&sch_adapter.dev, "SMBus busy (%02x)\n", temp);
return -EAGAIN;
}
dev_dbg(&sch_adapter.dev, "access size: %d %s\n", size,
(read_write)?"READ":"WRITE");
switch (size) {
case I2C_SMBUS_QUICK:
outb((addr << 1) | read_write, SMBHSTADD);
size = SCH_QUICK;
break;
case I2C_SMBUS_BYTE:
outb((addr << 1) | read_write, SMBHSTADD);
if (read_write == I2C_SMBUS_WRITE)
outb(command, SMBHSTCMD);
size = SCH_BYTE;
break;
case I2C_SMBUS_BYTE_DATA:
outb((addr << 1) | read_write, SMBHSTADD);
outb(command, SMBHSTCMD);
if (read_write == I2C_SMBUS_WRITE)
outb(data->byte, SMBHSTDAT0);
size = SCH_BYTE_DATA;
break;
case I2C_SMBUS_WORD_DATA:
outb((addr << 1) | read_write, SMBHSTADD);
outb(command, SMBHSTCMD);
if (read_write == I2C_SMBUS_WRITE) {
outb(data->word & 0xff, SMBHSTDAT0);
outb((data->word & 0xff00) >> 8, SMBHSTDAT1);
}
size = SCH_WORD_DATA;
break;
case I2C_SMBUS_BLOCK_DATA:
outb((addr << 1) | read_write, SMBHSTADD);
outb(command, SMBHSTCMD);
if (read_write == I2C_SMBUS_WRITE) {
len = data->block[0];
if (len == 0 || len > I2C_SMBUS_BLOCK_MAX)
return -EINVAL;
outb(len, SMBHSTDAT0);
for (i = 1; i <= len; i++)
outb(data->block[i], SMBBLKDAT+i-1);
}
size = SCH_BLOCK_DATA;
break;
default:
dev_warn(&adap->dev, "Unsupported transaction %d\n", size);
return -EOPNOTSUPP;
}
dev_dbg(&sch_adapter.dev, "write size %d to 0x%04x\n", size, SMBHSTCNT);
outb((inb(SMBHSTCNT) & 0xb0) | (size & 0x7), SMBHSTCNT);
rc = sch_transaction();
if (rc)
return rc;
if ((read_write == I2C_SMBUS_WRITE) || (size == SCH_QUICK))
return 0;
switch (size) {
case SCH_BYTE:
case SCH_BYTE_DATA:
data->byte = inb(SMBHSTDAT0);
break;
case SCH_WORD_DATA:
data->word = inb(SMBHSTDAT0) + (inb(SMBHSTDAT1) << 8);
break;
case SCH_BLOCK_DATA:
data->block[0] = inb(SMBHSTDAT0);
if (data->block[0] == 0 || data->block[0] > I2C_SMBUS_BLOCK_MAX)
return -EPROTO;
for (i = 1; i <= data->block[0]; i++)
data->block[i] = inb(SMBBLKDAT+i-1);
break;
}
return 0;
}
static u32 sch_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_SMBUS_QUICK | I2C_FUNC_SMBUS_BYTE |
I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA |
I2C_FUNC_SMBUS_BLOCK_DATA;
}
static int __devinit smbus_sch_probe(struct platform_device *dev)
{
struct resource *res;
int retval;
res = platform_get_resource(dev, IORESOURCE_IO, 0);
if (!res)
return -EBUSY;
if (!request_region(res->start, resource_size(res), dev->name)) {
dev_err(&dev->dev, "SMBus region 0x%x already in use!\n",
sch_smba);
return -EBUSY;
}
sch_smba = res->start;
dev_dbg(&dev->dev, "SMBA = 0x%X\n", sch_smba);
sch_adapter.dev.parent = &dev->dev;
snprintf(sch_adapter.name, sizeof(sch_adapter.name),
"SMBus SCH adapter at %04x", sch_smba);
retval = i2c_add_adapter(&sch_adapter);
if (retval) {
dev_err(&dev->dev, "Couldn't register adapter!\n");
release_region(res->start, resource_size(res));
sch_smba = 0;
}
return retval;
}
static int __devexit smbus_sch_remove(struct platform_device *pdev)
{
struct resource *res;
if (sch_smba) {
i2c_del_adapter(&sch_adapter);
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
release_region(res->start, resource_size(res));
sch_smba = 0;
}
return 0;
}
static int __init i2c_sch_init(void)
{
return platform_driver_register(&smbus_sch_driver);
}
static void __exit i2c_sch_exit(void)
{
platform_driver_unregister(&smbus_sch_driver);
}
