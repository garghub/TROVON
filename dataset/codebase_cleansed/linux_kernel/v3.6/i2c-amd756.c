static int amd756_transaction(struct i2c_adapter *adap)
{
int temp;
int result = 0;
int timeout = 0;
dev_dbg(&adap->dev, "Transaction (pre): GS=%04x, GE=%04x, ADD=%04x, "
"DAT=%04x\n", inw_p(SMB_GLOBAL_STATUS),
inw_p(SMB_GLOBAL_ENABLE), inw_p(SMB_HOST_ADDRESS),
inb_p(SMB_HOST_DATA));
if ((temp = inw_p(SMB_GLOBAL_STATUS)) & (GS_HST_STS | GS_SMB_STS)) {
dev_dbg(&adap->dev, "SMBus busy (%04x). Waiting...\n", temp);
do {
msleep(1);
temp = inw_p(SMB_GLOBAL_STATUS);
} while ((temp & (GS_HST_STS | GS_SMB_STS)) &&
(timeout++ < MAX_TIMEOUT));
if (timeout > MAX_TIMEOUT) {
dev_dbg(&adap->dev, "Busy wait timeout (%04x)\n", temp);
goto abort;
}
timeout = 0;
}
outw_p(inw(SMB_GLOBAL_ENABLE) | GE_HOST_STC, SMB_GLOBAL_ENABLE);
do {
msleep(1);
temp = inw_p(SMB_GLOBAL_STATUS);
} while ((temp & GS_HST_STS) && (timeout++ < MAX_TIMEOUT));
if (timeout > MAX_TIMEOUT) {
dev_dbg(&adap->dev, "Completion timeout!\n");
goto abort;
}
if (temp & GS_PRERR_STS) {
result = -ENXIO;
dev_dbg(&adap->dev, "SMBus Protocol error (no response)!\n");
}
if (temp & GS_COL_STS) {
result = -EIO;
dev_warn(&adap->dev, "SMBus collision!\n");
}
if (temp & GS_TO_STS) {
result = -ETIMEDOUT;
dev_dbg(&adap->dev, "SMBus protocol timeout!\n");
}
if (temp & GS_HCYC_STS)
dev_dbg(&adap->dev, "SMBus protocol success!\n");
outw_p(GS_CLEAR_STS, SMB_GLOBAL_STATUS);
#ifdef DEBUG
if (((temp = inw_p(SMB_GLOBAL_STATUS)) & GS_CLEAR_STS) != 0x00) {
dev_dbg(&adap->dev,
"Failed reset at end of transaction (%04x)\n", temp);
}
#endif
dev_dbg(&adap->dev,
"Transaction (post): GS=%04x, GE=%04x, ADD=%04x, DAT=%04x\n",
inw_p(SMB_GLOBAL_STATUS), inw_p(SMB_GLOBAL_ENABLE),
inw_p(SMB_HOST_ADDRESS), inb_p(SMB_HOST_DATA));
return result;
abort:
dev_warn(&adap->dev, "Sending abort\n");
outw_p(inw(SMB_GLOBAL_ENABLE) | GE_ABORT, SMB_GLOBAL_ENABLE);
msleep(100);
outw_p(GS_CLEAR_STS, SMB_GLOBAL_STATUS);
return -EIO;
}
static s32 amd756_access(struct i2c_adapter * adap, u16 addr,
unsigned short flags, char read_write,
u8 command, int size, union i2c_smbus_data * data)
{
int i, len;
int status;
switch (size) {
case I2C_SMBUS_QUICK:
outw_p(((addr & 0x7f) << 1) | (read_write & 0x01),
SMB_HOST_ADDRESS);
size = AMD756_QUICK;
break;
case I2C_SMBUS_BYTE:
outw_p(((addr & 0x7f) << 1) | (read_write & 0x01),
SMB_HOST_ADDRESS);
if (read_write == I2C_SMBUS_WRITE)
outb_p(command, SMB_HOST_DATA);
size = AMD756_BYTE;
break;
case I2C_SMBUS_BYTE_DATA:
outw_p(((addr & 0x7f) << 1) | (read_write & 0x01),
SMB_HOST_ADDRESS);
outb_p(command, SMB_HOST_COMMAND);
if (read_write == I2C_SMBUS_WRITE)
outw_p(data->byte, SMB_HOST_DATA);
size = AMD756_BYTE_DATA;
break;
case I2C_SMBUS_WORD_DATA:
outw_p(((addr & 0x7f) << 1) | (read_write & 0x01),
SMB_HOST_ADDRESS);
outb_p(command, SMB_HOST_COMMAND);
if (read_write == I2C_SMBUS_WRITE)
outw_p(data->word, SMB_HOST_DATA);
size = AMD756_WORD_DATA;
break;
case I2C_SMBUS_BLOCK_DATA:
outw_p(((addr & 0x7f) << 1) | (read_write & 0x01),
SMB_HOST_ADDRESS);
outb_p(command, SMB_HOST_COMMAND);
if (read_write == I2C_SMBUS_WRITE) {
len = data->block[0];
if (len < 0)
len = 0;
if (len > 32)
len = 32;
outw_p(len, SMB_HOST_DATA);
for (i = 1; i <= len; i++)
outb_p(data->block[i],
SMB_HOST_BLOCK_DATA);
}
size = AMD756_BLOCK_DATA;
break;
default:
dev_warn(&adap->dev, "Unsupported transaction %d\n", size);
return -EOPNOTSUPP;
}
outw_p(size & GE_CYC_TYPE_MASK, SMB_GLOBAL_ENABLE);
status = amd756_transaction(adap);
if (status)
return status;
if ((read_write == I2C_SMBUS_WRITE) || (size == AMD756_QUICK))
return 0;
switch (size) {
case AMD756_BYTE:
data->byte = inw_p(SMB_HOST_DATA);
break;
case AMD756_BYTE_DATA:
data->byte = inw_p(SMB_HOST_DATA);
break;
case AMD756_WORD_DATA:
data->word = inw_p(SMB_HOST_DATA);
break;
case AMD756_BLOCK_DATA:
data->block[0] = inw_p(SMB_HOST_DATA) & 0x3f;
if(data->block[0] > 32)
data->block[0] = 32;
for (i = 1; i <= data->block[0]; i++)
data->block[i] = inb_p(SMB_HOST_BLOCK_DATA);
break;
}
return 0;
}
static u32 amd756_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_SMBUS_QUICK | I2C_FUNC_SMBUS_BYTE |
I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA |
I2C_FUNC_SMBUS_BLOCK_DATA;
}
static int __devinit amd756_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
int nforce = (id->driver_data == NFORCE);
int error;
u8 temp;
if (amd756_ioport) {
dev_err(&pdev->dev, "Only one device supported "
"(you have a strange motherboard, btw)\n");
return -ENODEV;
}
if (nforce) {
if (PCI_FUNC(pdev->devfn) != 1)
return -ENODEV;
pci_read_config_word(pdev, SMBBANFORCE, &amd756_ioport);
amd756_ioport &= 0xfffc;
} else {
if (PCI_FUNC(pdev->devfn) != 3)
return -ENODEV;
pci_read_config_byte(pdev, SMBGCFG, &temp);
if ((temp & 128) == 0) {
dev_err(&pdev->dev,
"Error: SMBus controller I/O not enabled!\n");
return -ENODEV;
}
pci_read_config_word(pdev, SMBBA, &amd756_ioport);
amd756_ioport &= 0xff00;
amd756_ioport += SMB_ADDR_OFFSET;
}
error = acpi_check_region(amd756_ioport, SMB_IOSIZE,
amd756_driver.name);
if (error)
return -ENODEV;
if (!request_region(amd756_ioport, SMB_IOSIZE, amd756_driver.name)) {
dev_err(&pdev->dev, "SMB region 0x%x already in use!\n",
amd756_ioport);
return -ENODEV;
}
pci_read_config_byte(pdev, SMBREV, &temp);
dev_dbg(&pdev->dev, "SMBREV = 0x%X\n", temp);
dev_dbg(&pdev->dev, "AMD756_smba = 0x%X\n", amd756_ioport);
amd756_smbus.dev.parent = &pdev->dev;
snprintf(amd756_smbus.name, sizeof(amd756_smbus.name),
"SMBus %s adapter at %04x", chipname[id->driver_data],
amd756_ioport);
error = i2c_add_adapter(&amd756_smbus);
if (error) {
dev_err(&pdev->dev,
"Adapter registration failed, module not inserted\n");
goto out_err;
}
return 0;
out_err:
release_region(amd756_ioport, SMB_IOSIZE);
return error;
}
static void __devexit amd756_remove(struct pci_dev *dev)
{
i2c_del_adapter(&amd756_smbus);
release_region(amd756_ioport, SMB_IOSIZE);
}
