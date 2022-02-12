static u8 sis5595_read(u8 reg)
{
outb(reg, sis5595_base + SMB_INDEX);
return inb(sis5595_base + SMB_DAT);
}
static void sis5595_write(u8 reg, u8 data)
{
outb(reg, sis5595_base + SMB_INDEX);
outb(data, sis5595_base + SMB_DAT);
}
static int __devinit sis5595_setup(struct pci_dev *SIS5595_dev)
{
u16 a;
u8 val;
int *i;
int retval;
for (i = blacklist; *i != 0; i++) {
struct pci_dev *dev;
dev = pci_get_device(PCI_VENDOR_ID_SI, *i, NULL);
if (dev) {
dev_err(&SIS5595_dev->dev, "Looked for SIS5595 but found unsupported device %.4x\n", *i);
pci_dev_put(dev);
return -ENODEV;
}
}
pci_read_config_word(SIS5595_dev, ACPI_BASE, &sis5595_base);
if (sis5595_base == 0 && force_addr == 0) {
dev_err(&SIS5595_dev->dev, "ACPI base address uninitialized - upgrade BIOS or use force_addr=0xaddr\n");
return -ENODEV;
}
if (force_addr)
sis5595_base = force_addr & ~(SIS5595_EXTENT - 1);
dev_dbg(&SIS5595_dev->dev, "ACPI Base address: %04x\n", sis5595_base);
retval = acpi_check_region(sis5595_base + SMB_INDEX, 2,
sis5595_driver.name);
if (retval)
return retval;
if (!request_region(sis5595_base + SMB_INDEX, 2,
sis5595_driver.name)) {
dev_err(&SIS5595_dev->dev, "SMBus registers 0x%04x-0x%04x already in use!\n",
sis5595_base + SMB_INDEX, sis5595_base + SMB_INDEX + 1);
return -ENODEV;
}
if (force_addr) {
dev_info(&SIS5595_dev->dev, "forcing ISA address 0x%04X\n", sis5595_base);
if (pci_write_config_word(SIS5595_dev, ACPI_BASE, sis5595_base)
!= PCIBIOS_SUCCESSFUL)
goto error;
if (pci_read_config_word(SIS5595_dev, ACPI_BASE, &a)
!= PCIBIOS_SUCCESSFUL)
goto error;
if ((a & ~(SIS5595_EXTENT - 1)) != sis5595_base) {
dev_err(&SIS5595_dev->dev, "force address failed - not supported?\n");
goto error;
}
}
if (pci_read_config_byte(SIS5595_dev, SIS5595_ENABLE_REG, &val)
!= PCIBIOS_SUCCESSFUL)
goto error;
if ((val & 0x80) == 0) {
dev_info(&SIS5595_dev->dev, "enabling ACPI\n");
if (pci_write_config_byte(SIS5595_dev, SIS5595_ENABLE_REG, val | 0x80)
!= PCIBIOS_SUCCESSFUL)
goto error;
if (pci_read_config_byte(SIS5595_dev, SIS5595_ENABLE_REG, &val)
!= PCIBIOS_SUCCESSFUL)
goto error;
if ((val & 0x80) == 0) {
dev_err(&SIS5595_dev->dev, "ACPI enable failed - not supported?\n");
goto error;
}
}
return 0;
error:
release_region(sis5595_base + SMB_INDEX, 2);
return -ENODEV;
}
static int sis5595_transaction(struct i2c_adapter *adap)
{
int temp;
int result = 0;
int timeout = 0;
temp = sis5595_read(SMB_STS_LO) + (sis5595_read(SMB_STS_HI) << 8);
if (temp != 0x00) {
dev_dbg(&adap->dev, "SMBus busy (%04x). Resetting...\n", temp);
sis5595_write(SMB_STS_LO, temp & 0xff);
sis5595_write(SMB_STS_HI, temp >> 8);
if ((temp = sis5595_read(SMB_STS_LO) + (sis5595_read(SMB_STS_HI) << 8)) != 0x00) {
dev_dbg(&adap->dev, "Failed! (%02x)\n", temp);
return -EBUSY;
} else {
dev_dbg(&adap->dev, "Successful!\n");
}
}
sis5595_write(SMB_CTL_LO, sis5595_read(SMB_CTL_LO) | 0x10);
do {
msleep(1);
temp = sis5595_read(SMB_STS_LO);
} while (!(temp & 0x40) && (timeout++ < MAX_TIMEOUT));
if (timeout > MAX_TIMEOUT) {
dev_dbg(&adap->dev, "SMBus Timeout!\n");
result = -ETIMEDOUT;
}
if (temp & 0x10) {
dev_dbg(&adap->dev, "Error: Failed bus transaction\n");
result = -ENXIO;
}
if (temp & 0x20) {
dev_err(&adap->dev, "Bus collision! SMBus may be locked until "
"next hard reset (or not...)\n");
result = -EIO;
}
temp = sis5595_read(SMB_STS_LO) + (sis5595_read(SMB_STS_HI) << 8);
if (temp != 0x00) {
sis5595_write(SMB_STS_LO, temp & 0xff);
sis5595_write(SMB_STS_HI, temp >> 8);
}
temp = sis5595_read(SMB_STS_LO) + (sis5595_read(SMB_STS_HI) << 8);
if (temp != 0x00)
dev_dbg(&adap->dev, "Failed reset at end of transaction (%02x)\n", temp);
return result;
}
static s32 sis5595_access(struct i2c_adapter *adap, u16 addr,
unsigned short flags, char read_write,
u8 command, int size, union i2c_smbus_data *data)
{
int status;
switch (size) {
case I2C_SMBUS_QUICK:
sis5595_write(SMB_ADDR, ((addr & 0x7f) << 1) | (read_write & 0x01));
size = SIS5595_QUICK;
break;
case I2C_SMBUS_BYTE:
sis5595_write(SMB_ADDR, ((addr & 0x7f) << 1) | (read_write & 0x01));
if (read_write == I2C_SMBUS_WRITE)
sis5595_write(SMB_CMD, command);
size = SIS5595_BYTE;
break;
case I2C_SMBUS_BYTE_DATA:
sis5595_write(SMB_ADDR, ((addr & 0x7f) << 1) | (read_write & 0x01));
sis5595_write(SMB_CMD, command);
if (read_write == I2C_SMBUS_WRITE)
sis5595_write(SMB_BYTE, data->byte);
size = SIS5595_BYTE_DATA;
break;
case I2C_SMBUS_PROC_CALL:
case I2C_SMBUS_WORD_DATA:
sis5595_write(SMB_ADDR, ((addr & 0x7f) << 1) | (read_write & 0x01));
sis5595_write(SMB_CMD, command);
if (read_write == I2C_SMBUS_WRITE) {
sis5595_write(SMB_BYTE, data->word & 0xff);
sis5595_write(SMB_BYTE + 1,
(data->word & 0xff00) >> 8);
}
size = (size == I2C_SMBUS_PROC_CALL) ? SIS5595_PROC_CALL : SIS5595_WORD_DATA;
break;
default:
dev_warn(&adap->dev, "Unsupported transaction %d\n", size);
return -EOPNOTSUPP;
}
sis5595_write(SMB_CTL_LO, ((size & 0x0E)));
status = sis5595_transaction(adap);
if (status)
return status;
if ((size != SIS5595_PROC_CALL) &&
((read_write == I2C_SMBUS_WRITE) || (size == SIS5595_QUICK)))
return 0;
switch (size) {
case SIS5595_BYTE:
case SIS5595_BYTE_DATA:
data->byte = sis5595_read(SMB_BYTE);
break;
case SIS5595_WORD_DATA:
case SIS5595_PROC_CALL:
data->word = sis5595_read(SMB_BYTE) + (sis5595_read(SMB_BYTE + 1) << 8);
break;
}
return 0;
}
static u32 sis5595_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_SMBUS_QUICK | I2C_FUNC_SMBUS_BYTE |
I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA |
I2C_FUNC_SMBUS_PROC_CALL;
}
static int __devinit sis5595_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
int err;
if (sis5595_setup(dev)) {
dev_err(&dev->dev, "SIS5595 not detected, module not inserted.\n");
return -ENODEV;
}
sis5595_adapter.dev.parent = &dev->dev;
snprintf(sis5595_adapter.name, sizeof(sis5595_adapter.name),
"SMBus SIS5595 adapter at %04x", sis5595_base + SMB_INDEX);
err = i2c_add_adapter(&sis5595_adapter);
if (err) {
release_region(sis5595_base + SMB_INDEX, 2);
return err;
}
sis5595_pdev = pci_dev_get(dev);
return -ENODEV;
}
static int __init i2c_sis5595_init(void)
{
return pci_register_driver(&sis5595_driver);
}
static void __exit i2c_sis5595_exit(void)
{
pci_unregister_driver(&sis5595_driver);
if (sis5595_pdev) {
i2c_del_adapter(&sis5595_adapter);
release_region(sis5595_base + SMB_INDEX, 2);
pci_dev_put(sis5595_pdev);
sis5595_pdev = NULL;
}
}
