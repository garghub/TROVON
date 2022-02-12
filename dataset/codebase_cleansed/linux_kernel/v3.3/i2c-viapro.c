static void vt596_dump_regs(const char *msg, u8 size)
{
dev_dbg(&vt596_adapter.dev, "%s: STS=%02x CNT=%02x CMD=%02x ADD=%02x "
"DAT=%02x,%02x\n", msg, inb_p(SMBHSTSTS), inb_p(SMBHSTCNT),
inb_p(SMBHSTCMD), inb_p(SMBHSTADD), inb_p(SMBHSTDAT0),
inb_p(SMBHSTDAT1));
if (size == VT596_BLOCK_DATA
|| size == VT596_I2C_BLOCK_DATA) {
int i;
dev_dbg(&vt596_adapter.dev, "BLK=");
for (i = 0; i < I2C_SMBUS_BLOCK_MAX / 2; i++)
printk("%02x,", inb_p(SMBBLKDAT));
printk("\n");
dev_dbg(&vt596_adapter.dev, " ");
for (; i < I2C_SMBUS_BLOCK_MAX - 1; i++)
printk("%02x,", inb_p(SMBBLKDAT));
printk("%02x\n", inb_p(SMBBLKDAT));
}
}
static inline void vt596_dump_regs(const char *msg, u8 size) { }
static int vt596_transaction(u8 size)
{
int temp;
int result = 0;
int timeout = 0;
vt596_dump_regs("Transaction (pre)", size);
if ((temp = inb_p(SMBHSTSTS)) & 0x1F) {
dev_dbg(&vt596_adapter.dev, "SMBus busy (0x%02x). "
"Resetting...\n", temp);
outb_p(temp, SMBHSTSTS);
if ((temp = inb_p(SMBHSTSTS)) & 0x1F) {
dev_err(&vt596_adapter.dev, "SMBus reset failed! "
"(0x%02x)\n", temp);
return -EBUSY;
}
}
outb_p(0x40 | size, SMBHSTCNT);
do {
msleep(1);
temp = inb_p(SMBHSTSTS);
} while ((temp & 0x01) && (++timeout < MAX_TIMEOUT));
if (timeout == MAX_TIMEOUT) {
result = -ETIMEDOUT;
dev_err(&vt596_adapter.dev, "SMBus timeout!\n");
}
if (temp & 0x10) {
result = -EIO;
dev_err(&vt596_adapter.dev, "Transaction failed (0x%02x)\n",
size);
}
if (temp & 0x08) {
result = -EIO;
dev_err(&vt596_adapter.dev, "SMBus collision!\n");
}
if (temp & 0x04) {
result = -ENXIO;
dev_dbg(&vt596_adapter.dev, "No response\n");
}
if (temp & 0x1F)
outb_p(temp, SMBHSTSTS);
vt596_dump_regs("Transaction (post)", size);
return result;
}
static s32 vt596_access(struct i2c_adapter *adap, u16 addr,
unsigned short flags, char read_write, u8 command,
int size, union i2c_smbus_data *data)
{
int i;
int status;
switch (size) {
case I2C_SMBUS_QUICK:
size = VT596_QUICK;
break;
case I2C_SMBUS_BYTE:
if (read_write == I2C_SMBUS_WRITE)
outb_p(command, SMBHSTCMD);
size = VT596_BYTE;
break;
case I2C_SMBUS_BYTE_DATA:
outb_p(command, SMBHSTCMD);
if (read_write == I2C_SMBUS_WRITE)
outb_p(data->byte, SMBHSTDAT0);
size = VT596_BYTE_DATA;
break;
case I2C_SMBUS_WORD_DATA:
outb_p(command, SMBHSTCMD);
if (read_write == I2C_SMBUS_WRITE) {
outb_p(data->word & 0xff, SMBHSTDAT0);
outb_p((data->word & 0xff00) >> 8, SMBHSTDAT1);
}
size = VT596_WORD_DATA;
break;
case I2C_SMBUS_PROC_CALL:
outb_p(command, SMBHSTCMD);
outb_p(data->word & 0xff, SMBHSTDAT0);
outb_p((data->word & 0xff00) >> 8, SMBHSTDAT1);
size = VT596_PROC_CALL;
break;
case I2C_SMBUS_I2C_BLOCK_DATA:
if (!(vt596_features & FEATURE_I2CBLOCK))
goto exit_unsupported;
if (read_write == I2C_SMBUS_READ)
outb_p(data->block[0], SMBHSTDAT0);
case I2C_SMBUS_BLOCK_DATA:
outb_p(command, SMBHSTCMD);
if (read_write == I2C_SMBUS_WRITE) {
u8 len = data->block[0];
if (len > I2C_SMBUS_BLOCK_MAX)
len = I2C_SMBUS_BLOCK_MAX;
outb_p(len, SMBHSTDAT0);
inb_p(SMBHSTCNT);
for (i = 1; i <= len; i++)
outb_p(data->block[i], SMBBLKDAT);
}
size = (size == I2C_SMBUS_I2C_BLOCK_DATA) ?
VT596_I2C_BLOCK_DATA : VT596_BLOCK_DATA;
break;
default:
goto exit_unsupported;
}
outb_p(((addr & 0x7f) << 1) | read_write, SMBHSTADD);
status = vt596_transaction(size);
if (status)
return status;
if (size == VT596_PROC_CALL)
read_write = I2C_SMBUS_READ;
if ((read_write == I2C_SMBUS_WRITE) || (size == VT596_QUICK))
return 0;
switch (size) {
case VT596_BYTE:
case VT596_BYTE_DATA:
data->byte = inb_p(SMBHSTDAT0);
break;
case VT596_WORD_DATA:
case VT596_PROC_CALL:
data->word = inb_p(SMBHSTDAT0) + (inb_p(SMBHSTDAT1) << 8);
break;
case VT596_I2C_BLOCK_DATA:
case VT596_BLOCK_DATA:
data->block[0] = inb_p(SMBHSTDAT0);
if (data->block[0] > I2C_SMBUS_BLOCK_MAX)
data->block[0] = I2C_SMBUS_BLOCK_MAX;
inb_p(SMBHSTCNT);
for (i = 1; i <= data->block[0]; i++)
data->block[i] = inb_p(SMBBLKDAT);
break;
}
return 0;
exit_unsupported:
dev_warn(&vt596_adapter.dev, "Unsupported transaction %d\n",
size);
return -EOPNOTSUPP;
}
static u32 vt596_func(struct i2c_adapter *adapter)
{
u32 func = I2C_FUNC_SMBUS_QUICK | I2C_FUNC_SMBUS_BYTE |
I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA |
I2C_SMBUS_PROC_CALL | I2C_FUNC_SMBUS_BLOCK_DATA;
if (vt596_features & FEATURE_I2CBLOCK)
func |= I2C_FUNC_SMBUS_I2C_BLOCK;
return func;
}
static int __devinit vt596_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
unsigned char temp;
int error;
if (force_addr) {
vt596_smba = force_addr & 0xfff0;
force = 0;
goto found;
}
if ((pci_read_config_word(pdev, id->driver_data, &vt596_smba)) ||
!(vt596_smba & 0x0001)) {
if (id->device == PCI_DEVICE_ID_VIA_82C596_3 &&
!pci_read_config_word(pdev, SMBBA2, &vt596_smba) &&
(vt596_smba & 0x0001)) {
SMBHSTCFG = 0x84;
} else {
dev_err(&pdev->dev, "Cannot configure "
"SMBus I/O Base address\n");
return -ENODEV;
}
}
vt596_smba &= 0xfff0;
if (vt596_smba == 0) {
dev_err(&pdev->dev, "SMBus base address "
"uninitialized - upgrade BIOS or use "
"force_addr=0xaddr\n");
return -ENODEV;
}
found:
error = acpi_check_region(vt596_smba, 8, vt596_driver.name);
if (error)
return -ENODEV;
if (!request_region(vt596_smba, 8, vt596_driver.name)) {
dev_err(&pdev->dev, "SMBus region 0x%x already in use!\n",
vt596_smba);
return -ENODEV;
}
pci_read_config_byte(pdev, SMBHSTCFG, &temp);
if (force_addr) {
pci_write_config_byte(pdev, SMBHSTCFG, temp & 0xfe);
pci_write_config_word(pdev, id->driver_data, vt596_smba);
pci_write_config_byte(pdev, SMBHSTCFG, temp | 0x01);
dev_warn(&pdev->dev, "WARNING: SMBus interface set to new "
"address 0x%04x!\n", vt596_smba);
} else if (!(temp & 0x01)) {
if (force) {
pci_write_config_byte(pdev, SMBHSTCFG, temp | 0x01);
dev_info(&pdev->dev, "Enabling SMBus device\n");
} else {
dev_err(&pdev->dev, "SMBUS: Error: Host SMBus "
"controller not enabled! - upgrade BIOS or "
"use force=1\n");
error = -ENODEV;
goto release_region;
}
}
dev_dbg(&pdev->dev, "VT596_smba = 0x%X\n", vt596_smba);
switch (pdev->device) {
case PCI_DEVICE_ID_VIA_CX700:
case PCI_DEVICE_ID_VIA_VX800:
case PCI_DEVICE_ID_VIA_VX855:
case PCI_DEVICE_ID_VIA_8251:
case PCI_DEVICE_ID_VIA_8237:
case PCI_DEVICE_ID_VIA_8237A:
case PCI_DEVICE_ID_VIA_8237S:
case PCI_DEVICE_ID_VIA_8235:
case PCI_DEVICE_ID_VIA_8233A:
case PCI_DEVICE_ID_VIA_8233_0:
vt596_features |= FEATURE_I2CBLOCK;
break;
case PCI_DEVICE_ID_VIA_82C686_4:
if (pdev->revision >= 0x40)
vt596_features |= FEATURE_I2CBLOCK;
break;
}
vt596_adapter.dev.parent = &pdev->dev;
snprintf(vt596_adapter.name, sizeof(vt596_adapter.name),
"SMBus Via Pro adapter at %04x", vt596_smba);
vt596_pdev = pci_dev_get(pdev);
error = i2c_add_adapter(&vt596_adapter);
if (error) {
pci_dev_put(vt596_pdev);
vt596_pdev = NULL;
goto release_region;
}
return -ENODEV;
release_region:
release_region(vt596_smba, 8);
return error;
}
static int __init i2c_vt596_init(void)
{
return pci_register_driver(&vt596_driver);
}
static void __exit i2c_vt596_exit(void)
{
pci_unregister_driver(&vt596_driver);
if (vt596_pdev != NULL) {
i2c_del_adapter(&vt596_adapter);
release_region(vt596_smba, 8);
pci_dev_put(vt596_pdev);
vt596_pdev = NULL;
}
}
