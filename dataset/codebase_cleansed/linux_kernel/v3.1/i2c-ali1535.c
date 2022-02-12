static int __devinit ali1535_setup(struct pci_dev *dev)
{
int retval = -ENODEV;
unsigned char temp;
pci_read_config_word(dev, SMBBA, &ali1535_smba);
ali1535_smba &= (0xffff & ~(ALI1535_SMB_IOSIZE - 1));
if (ali1535_smba == 0) {
dev_warn(&dev->dev,
"ALI1535_smb region uninitialized - upgrade BIOS?\n");
goto exit;
}
retval = acpi_check_region(ali1535_smba, ALI1535_SMB_IOSIZE,
ali1535_driver.name);
if (retval)
goto exit;
if (!request_region(ali1535_smba, ALI1535_SMB_IOSIZE,
ali1535_driver.name)) {
dev_err(&dev->dev, "ALI1535_smb region 0x%x already in use!\n",
ali1535_smba);
goto exit;
}
pci_read_config_byte(dev, SMBCFG, &temp);
if ((temp & ALI1535_SMBIO_EN) == 0) {
dev_err(&dev->dev, "SMB device not enabled - upgrade BIOS?\n");
goto exit_free;
}
pci_read_config_byte(dev, SMBHSTCFG, &temp);
if ((temp & 1) == 0) {
dev_err(&dev->dev, "SMBus controller not enabled - upgrade BIOS?\n");
goto exit_free;
}
pci_write_config_byte(dev, SMBCLK, 0x20);
pci_read_config_byte(dev, SMBREV, &temp);
dev_dbg(&dev->dev, "SMBREV = 0x%X\n", temp);
dev_dbg(&dev->dev, "ALI1535_smba = 0x%X\n", ali1535_smba);
retval = 0;
exit:
return retval;
exit_free:
release_region(ali1535_smba, ALI1535_SMB_IOSIZE);
return retval;
}
static int ali1535_transaction(struct i2c_adapter *adap)
{
int temp;
int result = 0;
int timeout = 0;
dev_dbg(&adap->dev, "Transaction (pre): STS=%02x, TYP=%02x, "
"CMD=%02x, ADD=%02x, DAT0=%02x, DAT1=%02x\n",
inb_p(SMBHSTSTS), inb_p(SMBHSTTYP), inb_p(SMBHSTCMD),
inb_p(SMBHSTADD), inb_p(SMBHSTDAT0), inb_p(SMBHSTDAT1));
temp = inb_p(SMBHSTSTS);
if (temp & ALI1535_STS_BUSY) {
dev_info(&adap->dev,
"Resetting entire SMB Bus to clear busy condition (%02x)\n",
temp);
outb_p(ALI1535_T_OUT, SMBHSTTYP);
temp = inb_p(SMBHSTSTS);
}
if (temp & (ALI1535_STS_ERR | ALI1535_STS_BUSY)) {
outb_p(0xFF, SMBHSTSTS);
temp = inb_p(SMBHSTSTS);
if (temp & (ALI1535_STS_ERR | ALI1535_STS_BUSY)) {
dev_err(&adap->dev,
"SMBus reset failed! (0x%02x) - controller or "
"device on bus is probably hung\n", temp);
return -EBUSY;
}
} else {
if (temp & ALI1535_STS_DONE)
outb_p(temp, SMBHSTSTS);
}
outb_p(0xFF, SMBHSTPORT);
timeout = 0;
do {
usleep_range(1000, 2000);
temp = inb_p(SMBHSTSTS);
} while (((temp & ALI1535_STS_BUSY) && !(temp & ALI1535_STS_IDLE))
&& (timeout++ < MAX_TIMEOUT));
if (timeout > MAX_TIMEOUT) {
result = -ETIMEDOUT;
dev_err(&adap->dev, "SMBus Timeout!\n");
}
if (temp & ALI1535_STS_FAIL) {
result = -EIO;
dev_dbg(&adap->dev, "Error: Failed bus transaction\n");
}
if (temp & ALI1535_STS_BUSERR) {
result = -ENXIO;
dev_dbg(&adap->dev,
"Error: no response or bus collision ADD=%02x\n",
inb_p(SMBHSTADD));
}
if (temp & ALI1535_STS_DEV) {
result = -EIO;
dev_err(&adap->dev, "Error: device error\n");
}
if (!(temp & ALI1535_STS_DONE)) {
result = -ETIMEDOUT;
dev_err(&adap->dev, "Error: command never completed\n");
}
dev_dbg(&adap->dev, "Transaction (post): STS=%02x, TYP=%02x, "
"CMD=%02x, ADD=%02x, DAT0=%02x, DAT1=%02x\n",
inb_p(SMBHSTSTS), inb_p(SMBHSTTYP), inb_p(SMBHSTCMD),
inb_p(SMBHSTADD), inb_p(SMBHSTDAT0), inb_p(SMBHSTDAT1));
if (!(temp & ALI1535_STS_DONE)) {
outb_p(ALI1535_KILL, SMBHSTTYP);
outb_p(0xFF, SMBHSTSTS);
} else if (temp & ALI1535_STS_ERR) {
outb_p(ALI1535_T_OUT, SMBHSTTYP);
outb_p(0xFF, SMBHSTSTS);
}
return result;
}
static s32 ali1535_access(struct i2c_adapter *adap, u16 addr,
unsigned short flags, char read_write, u8 command,
int size, union i2c_smbus_data *data)
{
int i, len;
int temp;
int timeout;
s32 result = 0;
temp = inb_p(SMBHSTSTS);
for (timeout = 0;
(timeout < MAX_TIMEOUT) && !(temp & ALI1535_STS_IDLE);
timeout++) {
usleep_range(1000, 2000);
temp = inb_p(SMBHSTSTS);
}
if (timeout >= MAX_TIMEOUT)
dev_warn(&adap->dev, "Idle wait Timeout! STS=0x%02x\n", temp);
outb_p(0xFF, SMBHSTSTS);
switch (size) {
case I2C_SMBUS_QUICK:
outb_p(((addr & 0x7f) << 1) | (read_write & 0x01),
SMBHSTADD);
size = ALI1535_QUICK;
outb_p(size, SMBHSTTYP);
break;
case I2C_SMBUS_BYTE:
outb_p(((addr & 0x7f) << 1) | (read_write & 0x01),
SMBHSTADD);
size = ALI1535_BYTE;
outb_p(size, SMBHSTTYP);
if (read_write == I2C_SMBUS_WRITE)
outb_p(command, SMBHSTCMD);
break;
case I2C_SMBUS_BYTE_DATA:
outb_p(((addr & 0x7f) << 1) | (read_write & 0x01),
SMBHSTADD);
size = ALI1535_BYTE_DATA;
outb_p(size, SMBHSTTYP);
outb_p(command, SMBHSTCMD);
if (read_write == I2C_SMBUS_WRITE)
outb_p(data->byte, SMBHSTDAT0);
break;
case I2C_SMBUS_WORD_DATA:
outb_p(((addr & 0x7f) << 1) | (read_write & 0x01),
SMBHSTADD);
size = ALI1535_WORD_DATA;
outb_p(size, SMBHSTTYP);
outb_p(command, SMBHSTCMD);
if (read_write == I2C_SMBUS_WRITE) {
outb_p(data->word & 0xff, SMBHSTDAT0);
outb_p((data->word & 0xff00) >> 8, SMBHSTDAT1);
}
break;
case I2C_SMBUS_BLOCK_DATA:
outb_p(((addr & 0x7f) << 1) | (read_write & 0x01),
SMBHSTADD);
size = ALI1535_BLOCK_DATA;
outb_p(size, SMBHSTTYP);
outb_p(command, SMBHSTCMD);
if (read_write == I2C_SMBUS_WRITE) {
len = data->block[0];
if (len < 0) {
len = 0;
data->block[0] = len;
}
if (len > 32) {
len = 32;
data->block[0] = len;
}
outb_p(len, SMBHSTDAT0);
outb_p(inb_p(SMBHSTTYP) | ALI1535_BLOCK_CLR, SMBHSTTYP);
for (i = 1; i <= len; i++)
outb_p(data->block[i], SMBBLKDAT);
}
break;
default:
dev_warn(&adap->dev, "Unsupported transaction %d\n", size);
result = -EOPNOTSUPP;
goto EXIT;
}
result = ali1535_transaction(adap);
if (result)
goto EXIT;
if ((read_write == I2C_SMBUS_WRITE) || (size == ALI1535_QUICK)) {
result = 0;
goto EXIT;
}
switch (size) {
case ALI1535_BYTE:
data->byte = inb_p(SMBHSTDAT0);
break;
case ALI1535_BYTE_DATA:
data->byte = inb_p(SMBHSTDAT0);
break;
case ALI1535_WORD_DATA:
data->word = inb_p(SMBHSTDAT0) + (inb_p(SMBHSTDAT1) << 8);
break;
case ALI1535_BLOCK_DATA:
len = inb_p(SMBHSTDAT0);
if (len > 32)
len = 32;
data->block[0] = len;
outb_p(inb_p(SMBHSTTYP) | ALI1535_BLOCK_CLR, SMBHSTTYP);
for (i = 1; i <= data->block[0]; i++) {
data->block[i] = inb_p(SMBBLKDAT);
dev_dbg(&adap->dev, "Blk: len=%d, i=%d, data=%02x\n",
len, i, data->block[i]);
}
break;
}
EXIT:
return result;
}
static u32 ali1535_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_SMBUS_QUICK | I2C_FUNC_SMBUS_BYTE |
I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA |
I2C_FUNC_SMBUS_BLOCK_DATA;
}
static int __devinit ali1535_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
if (ali1535_setup(dev)) {
dev_warn(&dev->dev,
"ALI1535 not detected, module not inserted.\n");
return -ENODEV;
}
ali1535_adapter.dev.parent = &dev->dev;
snprintf(ali1535_adapter.name, sizeof(ali1535_adapter.name),
"SMBus ALI1535 adapter at %04x", ali1535_smba);
return i2c_add_adapter(&ali1535_adapter);
}
static void __devexit ali1535_remove(struct pci_dev *dev)
{
i2c_del_adapter(&ali1535_adapter);
release_region(ali1535_smba, ALI1535_SMB_IOSIZE);
}
static int __init i2c_ali1535_init(void)
{
return pci_register_driver(&ali1535_driver);
}
static void __exit i2c_ali1535_exit(void)
{
pci_unregister_driver(&ali1535_driver);
}
