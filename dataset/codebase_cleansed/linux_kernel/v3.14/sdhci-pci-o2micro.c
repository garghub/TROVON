void sdhci_pci_o2_fujin2_pci_init(struct sdhci_pci_chip *chip)
{
u32 scratch_32;
int ret;
ret = pci_read_config_dword(chip->pdev, O2_SD_DEV_CTRL, &scratch_32);
if (ret)
return;
scratch_32 &= ~((1 << 12) | (1 << 13) | (1 << 14));
pci_write_config_dword(chip->pdev, O2_SD_DEV_CTRL, scratch_32);
ret = pci_read_config_dword(chip->pdev, O2_SD_MISC_REG5, &scratch_32);
if (ret)
return;
scratch_32 &= ~((1 << 19) | (1 << 11));
scratch_32 |= (1 << 10);
pci_write_config_dword(chip->pdev, O2_SD_MISC_REG5, scratch_32);
ret = pci_read_config_dword(chip->pdev, O2_SD_TEST_REG, &scratch_32);
if (ret)
return;
scratch_32 |= (1 << 4);
pci_write_config_dword(chip->pdev, O2_SD_TEST_REG, scratch_32);
pci_write_config_dword(chip->pdev, O2_SD_DELAY_CTRL, 0x00002492);
ret = pci_read_config_dword(chip->pdev, O2_SD_LD0_CTRL, &scratch_32);
if (ret)
return;
scratch_32 &= ~(3 << 12);
pci_write_config_dword(chip->pdev, O2_SD_LD0_CTRL, scratch_32);
ret = pci_read_config_dword(chip->pdev, O2_SD_CAP_REG0, &scratch_32);
if (ret)
return;
scratch_32 &= ~(0x01FE);
scratch_32 |= 0x00CC;
pci_write_config_dword(chip->pdev, O2_SD_CAP_REG0, scratch_32);
ret = pci_read_config_dword(chip->pdev,
O2_SD_TUNING_CTRL, &scratch_32);
if (ret)
return;
scratch_32 &= ~(0x000000FF);
scratch_32 |= 0x00000066;
pci_write_config_dword(chip->pdev, O2_SD_TUNING_CTRL, scratch_32);
ret = pci_read_config_dword(chip->pdev,
O2_SD_UHS2_L1_CTRL, &scratch_32);
if (ret)
return;
scratch_32 &= ~(0x000000FC);
scratch_32 |= 0x00000084;
pci_write_config_dword(chip->pdev, O2_SD_UHS2_L1_CTRL, scratch_32);
ret = pci_read_config_dword(chip->pdev, O2_SD_FUNC_REG3, &scratch_32);
if (ret)
return;
scratch_32 &= ~((1 << 21) | (1 << 30));
scratch_32 |= ((1 << 29) | (1 << 28));
pci_write_config_dword(chip->pdev, O2_SD_FUNC_REG3, scratch_32);
ret = pci_read_config_dword(chip->pdev, O2_SD_CAPS, &scratch_32);
if (ret)
return;
scratch_32 &= ~(0xf0000000);
scratch_32 |= 0x30000000;
pci_write_config_dword(chip->pdev, O2_SD_CAPS, scratch_32);
ret = pci_read_config_dword(chip->pdev,
O2_SD_MISC_CTRL4, &scratch_32);
if (ret)
return;
scratch_32 &= ~(0x000f0000);
scratch_32 |= 0x00080000;
pci_write_config_dword(chip->pdev, O2_SD_MISC_CTRL4, scratch_32);
}
int sdhci_pci_o2_probe_slot(struct sdhci_pci_slot *slot)
{
struct sdhci_pci_chip *chip;
struct sdhci_host *host;
u32 reg;
chip = slot->chip;
host = slot->host;
switch (chip->pdev->device) {
case PCI_DEVICE_ID_O2_SDS0:
case PCI_DEVICE_ID_O2_SEABIRD0:
case PCI_DEVICE_ID_O2_SEABIRD1:
case PCI_DEVICE_ID_O2_SDS1:
case PCI_DEVICE_ID_O2_FUJIN2:
reg = sdhci_readl(host, O2_SD_VENDOR_SETTING);
if (reg & 0x1)
host->quirks |= SDHCI_QUIRK_MULTIBLOCK_READ_ACMD12;
if (chip->pdev->device != PCI_DEVICE_ID_O2_FUJIN2)
break;
reg = sdhci_readl(host, O2_SD_VENDOR_SETTING2);
reg |= (1 << 12);
sdhci_writel(host, reg, O2_SD_VENDOR_SETTING2);
break;
default:
break;
}
return 0;
}
int sdhci_pci_o2_probe(struct sdhci_pci_chip *chip)
{
int ret;
u8 scratch;
u32 scratch_32;
switch (chip->pdev->device) {
case PCI_DEVICE_ID_O2_8220:
case PCI_DEVICE_ID_O2_8221:
case PCI_DEVICE_ID_O2_8320:
case PCI_DEVICE_ID_O2_8321:
ret = pci_read_config_byte(chip->pdev,
O2_SD_LOCK_WP, &scratch);
if (ret)
return ret;
scratch &= 0x7f;
pci_write_config_byte(chip->pdev, O2_SD_LOCK_WP, scratch);
pci_write_config_byte(chip->pdev, O2_SD_MULTI_VCC3V, 0x08);
ret = pci_read_config_byte(chip->pdev,
O2_SD_CLKREQ, &scratch);
if (ret)
return ret;
scratch |= 0x20;
pci_write_config_byte(chip->pdev, O2_SD_CLKREQ, scratch);
ret = pci_read_config_byte(chip->pdev, O2_SD_CAPS, &scratch);
if (ret)
return ret;
scratch |= 0x01;
pci_write_config_byte(chip->pdev, O2_SD_CAPS, scratch);
pci_write_config_byte(chip->pdev, O2_SD_CAPS, 0x73);
pci_write_config_byte(chip->pdev, O2_SD_ADMA1, 0x39);
pci_write_config_byte(chip->pdev, O2_SD_ADMA2, 0x08);
ret = pci_read_config_byte(chip->pdev,
O2_SD_INF_MOD, &scratch);
if (ret)
return ret;
scratch |= 0x08;
pci_write_config_byte(chip->pdev, O2_SD_INF_MOD, scratch);
ret = pci_read_config_byte(chip->pdev,
O2_SD_LOCK_WP, &scratch);
if (ret)
return ret;
scratch |= 0x80;
pci_write_config_byte(chip->pdev, O2_SD_LOCK_WP, scratch);
break;
case PCI_DEVICE_ID_O2_SDS0:
case PCI_DEVICE_ID_O2_SDS1:
case PCI_DEVICE_ID_O2_FUJIN2:
ret = pci_read_config_byte(chip->pdev,
O2_SD_LOCK_WP, &scratch);
if (ret)
return ret;
scratch &= 0x7f;
pci_write_config_byte(chip->pdev, O2_SD_LOCK_WP, scratch);
ret = pci_read_config_dword(chip->pdev,
O2_SD_CLK_SETTING, &scratch_32);
if (ret)
return ret;
scratch_32 &= ~(0xFF00);
scratch_32 |= 0x07E0C800;
pci_write_config_dword(chip->pdev,
O2_SD_CLK_SETTING, scratch_32);
ret = pci_read_config_dword(chip->pdev,
O2_SD_CLKREQ, &scratch_32);
if (ret)
return ret;
scratch_32 |= 0x3;
pci_write_config_dword(chip->pdev, O2_SD_CLKREQ, scratch_32);
ret = pci_read_config_dword(chip->pdev,
O2_SD_PLL_SETTING, &scratch_32);
if (ret)
return ret;
scratch_32 &= ~(0x1F3F070E);
scratch_32 |= 0x18270106;
pci_write_config_dword(chip->pdev,
O2_SD_PLL_SETTING, scratch_32);
ret = pci_read_config_dword(chip->pdev,
O2_SD_CAP_REG2, &scratch_32);
if (ret)
return ret;
scratch_32 &= ~(0xE0);
pci_write_config_dword(chip->pdev,
O2_SD_CAP_REG2, scratch_32);
if (chip->pdev->device == PCI_DEVICE_ID_O2_FUJIN2)
sdhci_pci_o2_fujin2_pci_init(chip);
ret = pci_read_config_byte(chip->pdev,
O2_SD_LOCK_WP, &scratch);
if (ret)
return ret;
scratch |= 0x80;
pci_write_config_byte(chip->pdev, O2_SD_LOCK_WP, scratch);
break;
case PCI_DEVICE_ID_O2_SEABIRD0:
case PCI_DEVICE_ID_O2_SEABIRD1:
ret = pci_read_config_byte(chip->pdev,
O2_SD_LOCK_WP, &scratch);
if (ret)
return ret;
scratch &= 0x7f;
pci_write_config_byte(chip->pdev, O2_SD_LOCK_WP, scratch);
ret = pci_read_config_dword(chip->pdev,
O2_SD_FUNC_REG0, &scratch_32);
if ((scratch_32 & 0xff000000) == 0x01000000) {
scratch_32 &= 0x0000FFFF;
scratch_32 |= 0x1F340000;
pci_write_config_dword(chip->pdev,
O2_SD_PLL_SETTING, scratch_32);
} else {
scratch_32 &= 0x0000FFFF;
scratch_32 |= 0x2c280000;
pci_write_config_dword(chip->pdev,
O2_SD_PLL_SETTING, scratch_32);
ret = pci_read_config_dword(chip->pdev,
O2_SD_FUNC_REG4,
&scratch_32);
scratch_32 |= (1 << 22);
pci_write_config_dword(chip->pdev,
O2_SD_FUNC_REG4, scratch_32);
}
ret = pci_read_config_byte(chip->pdev,
O2_SD_LOCK_WP, &scratch);
if (ret)
return ret;
scratch |= 0x80;
pci_write_config_byte(chip->pdev, O2_SD_LOCK_WP, scratch);
break;
}
return 0;
}
int sdhci_pci_o2_resume(struct sdhci_pci_chip *chip)
{
sdhci_pci_o2_probe(chip);
return 0;
}
