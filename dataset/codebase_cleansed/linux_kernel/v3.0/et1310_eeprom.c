static int eeprom_wait_ready(struct pci_dev *pdev, u32 *status)
{
u32 reg;
int i;
for (i = 0; i < MAX_NUM_REGISTER_POLLS; i++) {
if (pci_read_config_dword(pdev, LBCIF_DWORD1_GROUP, &reg))
return -EIO;
if ((reg & 0x3000) == 0x3000) {
if (status)
*status = reg;
return reg & 0xFF;
}
}
return -ETIMEDOUT;
}
static int eeprom_write(struct et131x_adapter *etdev, u32 addr, u8 data)
{
struct pci_dev *pdev = etdev->pdev;
int index = 0;
int retries;
int err = 0;
int i2c_wack = 0;
int writeok = 0;
u32 status;
u32 val = 0;
err = eeprom_wait_ready(pdev, NULL);
if (err)
return err;
if (pci_write_config_byte(pdev, LBCIF_CONTROL_REGISTER,
LBCIF_CONTROL_LBCIF_ENABLE | LBCIF_CONTROL_I2C_WRITE))
return -EIO;
i2c_wack = 1;
for (retries = 0; retries < MAX_NUM_WRITE_RETRIES; retries++) {
if (pci_write_config_dword(pdev, LBCIF_ADDRESS_REGISTER, addr))
break;
if (pci_write_config_byte(pdev, LBCIF_DATA_REGISTER, data))
break;
err = eeprom_wait_ready(pdev, &status);
if (err < 0)
return 0;
if ((status & LBCIF_STATUS_GENERAL_ERROR)
&& etdev->pdev->revision == 0)
break;
if (status & LBCIF_STATUS_ACK_ERROR) {
udelay(10);
continue;
}
writeok = 1;
break;
}
udelay(10);
while (i2c_wack) {
if (pci_write_config_byte(pdev, LBCIF_CONTROL_REGISTER,
LBCIF_CONTROL_LBCIF_ENABLE))
writeok = 0;
do {
pci_write_config_dword(pdev,
LBCIF_ADDRESS_REGISTER,
addr);
do {
pci_read_config_dword(pdev,
LBCIF_DATA_REGISTER, &val);
} while ((val & 0x00010000) == 0);
} while (val & 0x00040000);
if ((val & 0xFF00) != 0xC000 || index == 10000)
break;
index++;
}
return writeok ? 0 : -EIO;
}
static int eeprom_read(struct et131x_adapter *etdev, u32 addr, u8 *pdata)
{
struct pci_dev *pdev = etdev->pdev;
int err;
u32 status;
err = eeprom_wait_ready(pdev, NULL);
if (err)
return err;
if (pci_write_config_byte(pdev, LBCIF_CONTROL_REGISTER,
LBCIF_CONTROL_LBCIF_ENABLE))
return -EIO;
if (pci_write_config_dword(pdev, LBCIF_ADDRESS_REGISTER, addr))
return -EIO;
err = eeprom_wait_ready(pdev, &status);
if (err < 0)
return err;
*pdata = err;
return (status & LBCIF_STATUS_ACK_ERROR) ? -EIO : 0;
}
int et131x_init_eeprom(struct et131x_adapter *etdev)
{
struct pci_dev *pdev = etdev->pdev;
u8 eestatus;
pci_read_config_byte(pdev, ET1310_PCI_EEPROM_STATUS,
&eestatus);
if (pci_read_config_byte(pdev, ET1310_PCI_EEPROM_STATUS, &eestatus)) {
dev_err(&pdev->dev,
"Could not read PCI config space for EEPROM Status\n");
return -EIO;
}
if (eestatus & 0x4C) {
int write_failed = 0;
if (pdev->revision == 0x01) {
int i;
static const u8 eedata[4] = { 0xFE, 0x13, 0x10, 0xFF };
for (i = 0; i < 3; i++)
if (eeprom_write(etdev, i, eedata[i]) < 0)
write_failed = 1;
}
if (pdev->revision != 0x01 || write_failed) {
dev_err(&pdev->dev,
"Fatal EEPROM Status Error - 0x%04x\n", eestatus);
etdev->has_eeprom = 0;
return -EIO;
}
}
etdev->has_eeprom = 1;
eeprom_read(etdev, 0x70, &etdev->eeprom_data[0]);
eeprom_read(etdev, 0x71, &etdev->eeprom_data[1]);
if (etdev->eeprom_data[0] != 0xcd)
etdev->eeprom_data[1] = 0x00;
return 0;
}
