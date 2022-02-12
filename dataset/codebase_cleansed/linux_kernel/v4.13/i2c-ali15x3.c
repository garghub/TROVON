static int ali15x3_setup(struct pci_dev *ALI15X3_dev)
{
u16 a;
unsigned char temp;
pci_read_config_byte(ALI15X3_dev, SMBATPC, &temp);
if (temp & ALI15X3_LOCK) {
temp &= ~ALI15X3_LOCK;
pci_write_config_byte(ALI15X3_dev, SMBATPC, temp);
}
pci_read_config_word(ALI15X3_dev, SMBBA, &ali15x3_smba);
ali15x3_smba &= (0xffff & ~(ALI15X3_SMB_IOSIZE - 1));
if (ali15x3_smba == 0 && force_addr == 0) {
dev_err(&ALI15X3_dev->dev, "ALI15X3_smb region uninitialized "
"- upgrade BIOS or use force_addr=0xaddr\n");
return -ENODEV;
}
if(force_addr)
ali15x3_smba = force_addr & ~(ALI15X3_SMB_IOSIZE - 1);
if (acpi_check_region(ali15x3_smba, ALI15X3_SMB_IOSIZE,
ali15x3_driver.name))
return -EBUSY;
if (!request_region(ali15x3_smba, ALI15X3_SMB_IOSIZE,
ali15x3_driver.name)) {
dev_err(&ALI15X3_dev->dev,
"ALI15X3_smb region 0x%x already in use!\n",
ali15x3_smba);
return -ENODEV;
}
if(force_addr) {
dev_info(&ALI15X3_dev->dev, "forcing ISA address 0x%04X\n",
ali15x3_smba);
if (PCIBIOS_SUCCESSFUL != pci_write_config_word(ALI15X3_dev,
SMBBA,
ali15x3_smba))
goto error;
if (PCIBIOS_SUCCESSFUL != pci_read_config_word(ALI15X3_dev,
SMBBA, &a))
goto error;
if ((a & ~(ALI15X3_SMB_IOSIZE - 1)) != ali15x3_smba) {
dev_err(&ALI15X3_dev->dev,
"force address failed - not supported?\n");
goto error;
}
}
pci_read_config_byte(ALI15X3_dev, SMBCOM, &temp);
if ((temp & 1) == 0) {
dev_info(&ALI15X3_dev->dev, "enabling SMBus device\n");
pci_write_config_byte(ALI15X3_dev, SMBCOM, temp | 0x01);
}
pci_read_config_byte(ALI15X3_dev, SMBHSTCFG, &temp);
if ((temp & 1) == 0) {
dev_info(&ALI15X3_dev->dev, "enabling SMBus controller\n");
pci_write_config_byte(ALI15X3_dev, SMBHSTCFG, temp | 0x01);
}
pci_write_config_byte(ALI15X3_dev, SMBCLK, 0x20);
pci_read_config_byte(ALI15X3_dev, SMBREV, &temp);
dev_dbg(&ALI15X3_dev->dev, "SMBREV = 0x%X\n", temp);
dev_dbg(&ALI15X3_dev->dev, "iALI15X3_smba = 0x%X\n", ali15x3_smba);
return 0;
error:
release_region(ali15x3_smba, ALI15X3_SMB_IOSIZE);
return -ENODEV;
}
static int ali15x3_transaction(struct i2c_adapter *adap)
{
int temp;
int result = 0;
int timeout = 0;
dev_dbg(&adap->dev, "Transaction (pre): STS=%02x, CNT=%02x, CMD=%02x, "
"ADD=%02x, DAT0=%02x, DAT1=%02x\n", inb_p(SMBHSTSTS),
inb_p(SMBHSTCNT), inb_p(SMBHSTCMD), inb_p(SMBHSTADD),
inb_p(SMBHSTDAT0), inb_p(SMBHSTDAT1));
temp = inb_p(SMBHSTSTS);
if (temp & ALI15X3_STS_BUSY) {
dev_info(&adap->dev, "Resetting entire SMB Bus to "
"clear busy condition (%02x)\n", temp);
outb_p(ALI15X3_T_OUT, SMBHSTCNT);
temp = inb_p(SMBHSTSTS);
}
if (temp & (ALI15X3_STS_ERR | ALI15X3_STS_BUSY)) {
outb_p(0xFF, SMBHSTSTS);
if ((temp = inb_p(SMBHSTSTS)) &
(ALI15X3_STS_ERR | ALI15X3_STS_BUSY)) {
dev_err(&adap->dev, "SMBus reset failed! (0x%02x) - "
"controller or device on bus is probably hung\n",
temp);
return -EBUSY;
}
} else {
if (temp & ALI15X3_STS_DONE) {
outb_p(temp, SMBHSTSTS);
}
}
outb_p(0xFF, SMBHSTSTART);
timeout = 0;
do {
msleep(1);
temp = inb_p(SMBHSTSTS);
} while ((!(temp & (ALI15X3_STS_ERR | ALI15X3_STS_DONE)))
&& (timeout++ < MAX_TIMEOUT));
if (timeout > MAX_TIMEOUT) {
result = -ETIMEDOUT;
dev_err(&adap->dev, "SMBus Timeout!\n");
}
if (temp & ALI15X3_STS_TERM) {
result = -EIO;
dev_dbg(&adap->dev, "Error: Failed bus transaction\n");
}
if (temp & ALI15X3_STS_COLL) {
result = -ENXIO;
dev_dbg(&adap->dev,
"Error: no response or bus collision ADD=%02x\n",
inb_p(SMBHSTADD));
}
if (temp & ALI15X3_STS_DEV) {
result = -EIO;
dev_err(&adap->dev, "Error: device error\n");
}
dev_dbg(&adap->dev, "Transaction (post): STS=%02x, CNT=%02x, CMD=%02x, "
"ADD=%02x, DAT0=%02x, DAT1=%02x\n", inb_p(SMBHSTSTS),
inb_p(SMBHSTCNT), inb_p(SMBHSTCMD), inb_p(SMBHSTADD),
inb_p(SMBHSTDAT0), inb_p(SMBHSTDAT1));
return result;
}
static s32 ali15x3_access(struct i2c_adapter * adap, u16 addr,
unsigned short flags, char read_write, u8 command,
int size, union i2c_smbus_data * data)
{
int i, len;
int temp;
int timeout;
outb_p(0xFF, SMBHSTSTS);
temp = inb_p(SMBHSTSTS);
for (timeout = 0;
(timeout < MAX_TIMEOUT) && !(temp & ALI15X3_STS_IDLE);
timeout++) {
msleep(1);
temp = inb_p(SMBHSTSTS);
}
if (timeout >= MAX_TIMEOUT) {
dev_err(&adap->dev, "Idle wait Timeout! STS=0x%02x\n", temp);
}
switch (size) {
case I2C_SMBUS_QUICK:
outb_p(((addr & 0x7f) << 1) | (read_write & 0x01),
SMBHSTADD);
size = ALI15X3_QUICK;
break;
case I2C_SMBUS_BYTE:
outb_p(((addr & 0x7f) << 1) | (read_write & 0x01),
SMBHSTADD);
if (read_write == I2C_SMBUS_WRITE)
outb_p(command, SMBHSTCMD);
size = ALI15X3_BYTE;
break;
case I2C_SMBUS_BYTE_DATA:
outb_p(((addr & 0x7f) << 1) | (read_write & 0x01),
SMBHSTADD);
outb_p(command, SMBHSTCMD);
if (read_write == I2C_SMBUS_WRITE)
outb_p(data->byte, SMBHSTDAT0);
size = ALI15X3_BYTE_DATA;
break;
case I2C_SMBUS_WORD_DATA:
outb_p(((addr & 0x7f) << 1) | (read_write & 0x01),
SMBHSTADD);
outb_p(command, SMBHSTCMD);
if (read_write == I2C_SMBUS_WRITE) {
outb_p(data->word & 0xff, SMBHSTDAT0);
outb_p((data->word & 0xff00) >> 8, SMBHSTDAT1);
}
size = ALI15X3_WORD_DATA;
break;
case I2C_SMBUS_BLOCK_DATA:
outb_p(((addr & 0x7f) << 1) | (read_write & 0x01),
SMBHSTADD);
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
outb_p(inb_p(SMBHSTCNT) | ALI15X3_BLOCK_CLR, SMBHSTCNT);
for (i = 1; i <= len; i++)
outb_p(data->block[i], SMBBLKDAT);
}
size = ALI15X3_BLOCK_DATA;
break;
default:
dev_warn(&adap->dev, "Unsupported transaction %d\n", size);
return -EOPNOTSUPP;
}
outb_p(size, SMBHSTCNT);
temp = ali15x3_transaction(adap);
if (temp)
return temp;
if ((read_write == I2C_SMBUS_WRITE) || (size == ALI15X3_QUICK))
return 0;
switch (size) {
case ALI15X3_BYTE:
data->byte = inb_p(SMBHSTDAT0);
break;
case ALI15X3_BYTE_DATA:
data->byte = inb_p(SMBHSTDAT0);
break;
case ALI15X3_WORD_DATA:
data->word = inb_p(SMBHSTDAT0) + (inb_p(SMBHSTDAT1) << 8);
break;
case ALI15X3_BLOCK_DATA:
len = inb_p(SMBHSTDAT0);
if (len > 32)
len = 32;
data->block[0] = len;
outb_p(inb_p(SMBHSTCNT) | ALI15X3_BLOCK_CLR, SMBHSTCNT);
for (i = 1; i <= data->block[0]; i++) {
data->block[i] = inb_p(SMBBLKDAT);
dev_dbg(&adap->dev, "Blk: len=%d, i=%d, data=%02x\n",
len, i, data->block[i]);
}
break;
}
return 0;
}
static u32 ali15x3_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_SMBUS_QUICK | I2C_FUNC_SMBUS_BYTE |
I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA |
I2C_FUNC_SMBUS_BLOCK_DATA;
}
static int ali15x3_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
if (ali15x3_setup(dev)) {
dev_err(&dev->dev,
"ALI15X3 not detected, module not inserted.\n");
return -ENODEV;
}
ali15x3_adapter.dev.parent = &dev->dev;
snprintf(ali15x3_adapter.name, sizeof(ali15x3_adapter.name),
"SMBus ALI15X3 adapter at %04x", ali15x3_smba);
return i2c_add_adapter(&ali15x3_adapter);
}
static void ali15x3_remove(struct pci_dev *dev)
{
i2c_del_adapter(&ali15x3_adapter);
release_region(ali15x3_smba, ALI15X3_SMB_IOSIZE);
}
