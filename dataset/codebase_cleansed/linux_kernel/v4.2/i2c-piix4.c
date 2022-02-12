static int piix4_setup(struct pci_dev *PIIX4_dev,
const struct pci_device_id *id)
{
unsigned char temp;
unsigned short piix4_smba;
if ((PIIX4_dev->vendor == PCI_VENDOR_ID_SERVERWORKS) &&
(PIIX4_dev->device == PCI_DEVICE_ID_SERVERWORKS_CSB5))
srvrworks_csb5_delay = 1;
if (dmi_check_system(piix4_dmi_blacklist)) {
dev_err(&PIIX4_dev->dev,
"Accessing the SMBus on this system is unsafe!\n");
return -EPERM;
}
if (dmi_check_system(piix4_dmi_ibm) &&
PIIX4_dev->vendor == PCI_VENDOR_ID_INTEL) {
dev_err(&PIIX4_dev->dev, "IBM system detected; this module "
"may corrupt your serial eeprom! Refusing to load "
"module!\n");
return -EPERM;
}
if (force_addr) {
piix4_smba = force_addr & 0xfff0;
force = 0;
} else {
pci_read_config_word(PIIX4_dev, SMBBA, &piix4_smba);
piix4_smba &= 0xfff0;
if(piix4_smba == 0) {
dev_err(&PIIX4_dev->dev, "SMBus base address "
"uninitialized - upgrade BIOS or use "
"force_addr=0xaddr\n");
return -ENODEV;
}
}
if (acpi_check_region(piix4_smba, SMBIOSIZE, piix4_driver.name))
return -ENODEV;
if (!request_region(piix4_smba, SMBIOSIZE, piix4_driver.name)) {
dev_err(&PIIX4_dev->dev, "SMBus region 0x%x already in use!\n",
piix4_smba);
return -EBUSY;
}
pci_read_config_byte(PIIX4_dev, SMBHSTCFG, &temp);
if (force_addr) {
pci_write_config_byte(PIIX4_dev, SMBHSTCFG, temp & 0xfe);
pci_write_config_word(PIIX4_dev, SMBBA, piix4_smba);
pci_write_config_byte(PIIX4_dev, SMBHSTCFG, temp | 0x01);
dev_info(&PIIX4_dev->dev, "WARNING: SMBus interface set to "
"new address %04x!\n", piix4_smba);
} else if ((temp & 1) == 0) {
if (force) {
pci_write_config_byte(PIIX4_dev, SMBHSTCFG,
temp | 1);
dev_notice(&PIIX4_dev->dev,
"WARNING: SMBus interface has been FORCEFULLY ENABLED!\n");
} else {
dev_err(&PIIX4_dev->dev,
"SMBus Host Controller not enabled!\n");
release_region(piix4_smba, SMBIOSIZE);
return -ENODEV;
}
}
if (((temp & 0x0E) == 8) || ((temp & 0x0E) == 2))
dev_dbg(&PIIX4_dev->dev, "Using IRQ for SMBus\n");
else if ((temp & 0x0E) == 0)
dev_dbg(&PIIX4_dev->dev, "Using SMI# for SMBus\n");
else
dev_err(&PIIX4_dev->dev, "Illegal Interrupt configuration "
"(or code out of date)!\n");
pci_read_config_byte(PIIX4_dev, SMBREV, &temp);
dev_info(&PIIX4_dev->dev,
"SMBus Host Controller at 0x%x, revision %d\n",
piix4_smba, temp);
return piix4_smba;
}
static int piix4_setup_sb800(struct pci_dev *PIIX4_dev,
const struct pci_device_id *id, u8 aux)
{
unsigned short piix4_smba;
unsigned short smba_idx = 0xcd6;
u8 smba_en_lo, smba_en_hi, smb_en, smb_en_status;
u8 i2ccfg, i2ccfg_offset = 0x10;
if (force || force_addr) {
dev_err(&PIIX4_dev->dev, "SMBus does not support "
"forcing address!\n");
return -EINVAL;
}
if ((PIIX4_dev->vendor == PCI_VENDOR_ID_AMD &&
PIIX4_dev->device == PCI_DEVICE_ID_AMD_HUDSON2_SMBUS &&
PIIX4_dev->revision >= 0x41) ||
(PIIX4_dev->vendor == PCI_VENDOR_ID_AMD &&
PIIX4_dev->device == PCI_DEVICE_ID_AMD_KERNCZ_SMBUS &&
PIIX4_dev->revision >= 0x49))
smb_en = 0x00;
else
smb_en = (aux) ? 0x28 : 0x2c;
if (!request_region(smba_idx, 2, "smba_idx")) {
dev_err(&PIIX4_dev->dev, "SMBus base address index region "
"0x%x already in use!\n", smba_idx);
return -EBUSY;
}
outb_p(smb_en, smba_idx);
smba_en_lo = inb_p(smba_idx + 1);
outb_p(smb_en + 1, smba_idx);
smba_en_hi = inb_p(smba_idx + 1);
release_region(smba_idx, 2);
if (!smb_en) {
smb_en_status = smba_en_lo & 0x10;
piix4_smba = smba_en_hi << 8;
if (aux)
piix4_smba |= 0x20;
} else {
smb_en_status = smba_en_lo & 0x01;
piix4_smba = ((smba_en_hi << 8) | smba_en_lo) & 0xffe0;
}
if (!smb_en_status) {
dev_err(&PIIX4_dev->dev,
"SMBus Host Controller not enabled!\n");
return -ENODEV;
}
if (acpi_check_region(piix4_smba, SMBIOSIZE, piix4_driver.name))
return -ENODEV;
if (!request_region(piix4_smba, SMBIOSIZE, piix4_driver.name)) {
dev_err(&PIIX4_dev->dev, "SMBus region 0x%x already in use!\n",
piix4_smba);
return -EBUSY;
}
if (aux) {
dev_info(&PIIX4_dev->dev,
"Auxiliary SMBus Host Controller at 0x%x\n",
piix4_smba);
return piix4_smba;
}
if (!request_region(piix4_smba + i2ccfg_offset, 1, "i2ccfg")) {
dev_err(&PIIX4_dev->dev, "SMBus I2C bus config region "
"0x%x already in use!\n", piix4_smba + i2ccfg_offset);
release_region(piix4_smba, SMBIOSIZE);
return -EBUSY;
}
i2ccfg = inb_p(piix4_smba + i2ccfg_offset);
release_region(piix4_smba + i2ccfg_offset, 1);
if (i2ccfg & 1)
dev_dbg(&PIIX4_dev->dev, "Using IRQ for SMBus\n");
else
dev_dbg(&PIIX4_dev->dev, "Using SMI# for SMBus\n");
dev_info(&PIIX4_dev->dev,
"SMBus Host Controller at 0x%x, revision %d\n",
piix4_smba, i2ccfg >> 4);
return piix4_smba;
}
static int piix4_setup_aux(struct pci_dev *PIIX4_dev,
const struct pci_device_id *id,
unsigned short base_reg_addr)
{
unsigned short piix4_smba;
pci_read_config_word(PIIX4_dev, base_reg_addr, &piix4_smba);
if ((piix4_smba & 1) == 0) {
dev_dbg(&PIIX4_dev->dev,
"Auxiliary SMBus controller not enabled\n");
return -ENODEV;
}
piix4_smba &= 0xfff0;
if (piix4_smba == 0) {
dev_dbg(&PIIX4_dev->dev,
"Auxiliary SMBus base address uninitialized\n");
return -ENODEV;
}
if (acpi_check_region(piix4_smba, SMBIOSIZE, piix4_driver.name))
return -ENODEV;
if (!request_region(piix4_smba, SMBIOSIZE, piix4_driver.name)) {
dev_err(&PIIX4_dev->dev, "Auxiliary SMBus region 0x%x "
"already in use!\n", piix4_smba);
return -EBUSY;
}
dev_info(&PIIX4_dev->dev,
"Auxiliary SMBus Host Controller at 0x%x\n",
piix4_smba);
return piix4_smba;
}
static int piix4_transaction(struct i2c_adapter *piix4_adapter)
{
struct i2c_piix4_adapdata *adapdata = i2c_get_adapdata(piix4_adapter);
unsigned short piix4_smba = adapdata->smba;
int temp;
int result = 0;
int timeout = 0;
dev_dbg(&piix4_adapter->dev, "Transaction (pre): CNT=%02x, CMD=%02x, "
"ADD=%02x, DAT0=%02x, DAT1=%02x\n", inb_p(SMBHSTCNT),
inb_p(SMBHSTCMD), inb_p(SMBHSTADD), inb_p(SMBHSTDAT0),
inb_p(SMBHSTDAT1));
if ((temp = inb_p(SMBHSTSTS)) != 0x00) {
dev_dbg(&piix4_adapter->dev, "SMBus busy (%02x). "
"Resetting...\n", temp);
outb_p(temp, SMBHSTSTS);
if ((temp = inb_p(SMBHSTSTS)) != 0x00) {
dev_err(&piix4_adapter->dev, "Failed! (%02x)\n", temp);
return -EBUSY;
} else {
dev_dbg(&piix4_adapter->dev, "Successful!\n");
}
}
outb_p(inb(SMBHSTCNT) | 0x040, SMBHSTCNT);
if (srvrworks_csb5_delay)
msleep(2);
else
msleep(1);
while ((++timeout < MAX_TIMEOUT) &&
((temp = inb_p(SMBHSTSTS)) & 0x01))
msleep(1);
if (timeout == MAX_TIMEOUT) {
dev_err(&piix4_adapter->dev, "SMBus Timeout!\n");
result = -ETIMEDOUT;
}
if (temp & 0x10) {
result = -EIO;
dev_err(&piix4_adapter->dev, "Error: Failed bus transaction\n");
}
if (temp & 0x08) {
result = -EIO;
dev_dbg(&piix4_adapter->dev, "Bus collision! SMBus may be "
"locked until next hard reset. (sorry!)\n");
}
if (temp & 0x04) {
result = -ENXIO;
dev_dbg(&piix4_adapter->dev, "Error: no response!\n");
}
if (inb_p(SMBHSTSTS) != 0x00)
outb_p(inb(SMBHSTSTS), SMBHSTSTS);
if ((temp = inb_p(SMBHSTSTS)) != 0x00) {
dev_err(&piix4_adapter->dev, "Failed reset at end of "
"transaction (%02x)\n", temp);
}
dev_dbg(&piix4_adapter->dev, "Transaction (post): CNT=%02x, CMD=%02x, "
"ADD=%02x, DAT0=%02x, DAT1=%02x\n", inb_p(SMBHSTCNT),
inb_p(SMBHSTCMD), inb_p(SMBHSTADD), inb_p(SMBHSTDAT0),
inb_p(SMBHSTDAT1));
return result;
}
static s32 piix4_access(struct i2c_adapter * adap, u16 addr,
unsigned short flags, char read_write,
u8 command, int size, union i2c_smbus_data * data)
{
struct i2c_piix4_adapdata *adapdata = i2c_get_adapdata(adap);
unsigned short piix4_smba = adapdata->smba;
int i, len;
int status;
switch (size) {
case I2C_SMBUS_QUICK:
outb_p((addr << 1) | read_write,
SMBHSTADD);
size = PIIX4_QUICK;
break;
case I2C_SMBUS_BYTE:
outb_p((addr << 1) | read_write,
SMBHSTADD);
if (read_write == I2C_SMBUS_WRITE)
outb_p(command, SMBHSTCMD);
size = PIIX4_BYTE;
break;
case I2C_SMBUS_BYTE_DATA:
outb_p((addr << 1) | read_write,
SMBHSTADD);
outb_p(command, SMBHSTCMD);
if (read_write == I2C_SMBUS_WRITE)
outb_p(data->byte, SMBHSTDAT0);
size = PIIX4_BYTE_DATA;
break;
case I2C_SMBUS_WORD_DATA:
outb_p((addr << 1) | read_write,
SMBHSTADD);
outb_p(command, SMBHSTCMD);
if (read_write == I2C_SMBUS_WRITE) {
outb_p(data->word & 0xff, SMBHSTDAT0);
outb_p((data->word & 0xff00) >> 8, SMBHSTDAT1);
}
size = PIIX4_WORD_DATA;
break;
case I2C_SMBUS_BLOCK_DATA:
outb_p((addr << 1) | read_write,
SMBHSTADD);
outb_p(command, SMBHSTCMD);
if (read_write == I2C_SMBUS_WRITE) {
len = data->block[0];
if (len == 0 || len > I2C_SMBUS_BLOCK_MAX)
return -EINVAL;
outb_p(len, SMBHSTDAT0);
i = inb_p(SMBHSTCNT);
for (i = 1; i <= len; i++)
outb_p(data->block[i], SMBBLKDAT);
}
size = PIIX4_BLOCK_DATA;
break;
default:
dev_warn(&adap->dev, "Unsupported transaction %d\n", size);
return -EOPNOTSUPP;
}
outb_p((size & 0x1C) + (ENABLE_INT9 & 1), SMBHSTCNT);
status = piix4_transaction(adap);
if (status)
return status;
if ((read_write == I2C_SMBUS_WRITE) || (size == PIIX4_QUICK))
return 0;
switch (size) {
case PIIX4_BYTE:
case PIIX4_BYTE_DATA:
data->byte = inb_p(SMBHSTDAT0);
break;
case PIIX4_WORD_DATA:
data->word = inb_p(SMBHSTDAT0) + (inb_p(SMBHSTDAT1) << 8);
break;
case PIIX4_BLOCK_DATA:
data->block[0] = inb_p(SMBHSTDAT0);
if (data->block[0] == 0 || data->block[0] > I2C_SMBUS_BLOCK_MAX)
return -EPROTO;
i = inb_p(SMBHSTCNT);
for (i = 1; i <= data->block[0]; i++)
data->block[i] = inb_p(SMBBLKDAT);
break;
}
return 0;
}
static u32 piix4_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_SMBUS_QUICK | I2C_FUNC_SMBUS_BYTE |
I2C_FUNC_SMBUS_BYTE_DATA | I2C_FUNC_SMBUS_WORD_DATA |
I2C_FUNC_SMBUS_BLOCK_DATA;
}
static int piix4_add_adapter(struct pci_dev *dev, unsigned short smba,
struct i2c_adapter **padap)
{
struct i2c_adapter *adap;
struct i2c_piix4_adapdata *adapdata;
int retval;
adap = kzalloc(sizeof(*adap), GFP_KERNEL);
if (adap == NULL) {
release_region(smba, SMBIOSIZE);
return -ENOMEM;
}
adap->owner = THIS_MODULE;
adap->class = I2C_CLASS_HWMON | I2C_CLASS_SPD;
adap->algo = &smbus_algorithm;
adapdata = kzalloc(sizeof(*adapdata), GFP_KERNEL);
if (adapdata == NULL) {
kfree(adap);
release_region(smba, SMBIOSIZE);
return -ENOMEM;
}
adapdata->smba = smba;
adap->dev.parent = &dev->dev;
snprintf(adap->name, sizeof(adap->name),
"SMBus PIIX4 adapter at %04x", smba);
i2c_set_adapdata(adap, adapdata);
retval = i2c_add_adapter(adap);
if (retval) {
dev_err(&dev->dev, "Couldn't register adapter!\n");
kfree(adapdata);
kfree(adap);
release_region(smba, SMBIOSIZE);
return retval;
}
*padap = adap;
return 0;
}
static int piix4_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
int retval;
if ((dev->vendor == PCI_VENDOR_ID_ATI &&
dev->device == PCI_DEVICE_ID_ATI_SBX00_SMBUS &&
dev->revision >= 0x40) ||
dev->vendor == PCI_VENDOR_ID_AMD)
retval = piix4_setup_sb800(dev, id, 0);
else
retval = piix4_setup(dev, id);
if (retval < 0)
return retval;
retval = piix4_add_adapter(dev, retval, &piix4_main_adapter);
if (retval < 0)
return retval;
retval = -ENODEV;
if (dev->vendor == PCI_VENDOR_ID_ATI &&
dev->device == PCI_DEVICE_ID_ATI_SBX00_SMBUS) {
if (dev->revision < 0x40) {
retval = piix4_setup_aux(dev, id, 0x58);
} else {
retval = piix4_setup_sb800(dev, id, 1);
}
}
if (dev->vendor == PCI_VENDOR_ID_AMD &&
dev->device == PCI_DEVICE_ID_AMD_HUDSON2_SMBUS) {
retval = piix4_setup_sb800(dev, id, 1);
}
if (retval > 0) {
piix4_add_adapter(dev, retval, &piix4_aux_adapter);
}
return 0;
}
static void piix4_adap_remove(struct i2c_adapter *adap)
{
struct i2c_piix4_adapdata *adapdata = i2c_get_adapdata(adap);
if (adapdata->smba) {
i2c_del_adapter(adap);
release_region(adapdata->smba, SMBIOSIZE);
kfree(adapdata);
kfree(adap);
}
}
static void piix4_remove(struct pci_dev *dev)
{
if (piix4_main_adapter) {
piix4_adap_remove(piix4_main_adapter);
piix4_main_adapter = NULL;
}
if (piix4_aux_adapter) {
piix4_adap_remove(piix4_aux_adapter);
piix4_aux_adapter = NULL;
}
}
