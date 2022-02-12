static int ricoh_probe(struct sdhci_pci_chip *chip)
{
if (chip->pdev->subsystem_vendor == PCI_VENDOR_ID_SAMSUNG ||
chip->pdev->subsystem_vendor == PCI_VENDOR_ID_SONY)
chip->quirks |= SDHCI_QUIRK_NO_CARD_NO_RESET;
return 0;
}
static int ricoh_mmc_probe_slot(struct sdhci_pci_slot *slot)
{
slot->host->caps =
((0x21 << SDHCI_TIMEOUT_CLK_SHIFT)
& SDHCI_TIMEOUT_CLK_MASK) |
((0x21 << SDHCI_CLOCK_BASE_SHIFT)
& SDHCI_CLOCK_BASE_MASK) |
SDHCI_TIMEOUT_CLK_UNIT |
SDHCI_CAN_VDD_330 |
SDHCI_CAN_DO_HISPD |
SDHCI_CAN_DO_SDMA;
return 0;
}
static int ricoh_mmc_resume(struct sdhci_pci_chip *chip)
{
msleep(500);
return 0;
}
static int mrst_hc_probe_slot(struct sdhci_pci_slot *slot)
{
slot->host->mmc->caps |= MMC_CAP_8_BIT_DATA;
return 0;
}
static int mrst_hc_probe(struct sdhci_pci_chip *chip)
{
chip->num_slots = 1;
return 0;
}
static int pch_hc_probe_slot(struct sdhci_pci_slot *slot)
{
slot->host->mmc->caps |= MMC_CAP_8_BIT_DATA;
return 0;
}
static irqreturn_t sdhci_pci_sd_cd(int irq, void *dev_id)
{
struct sdhci_pci_slot *slot = dev_id;
struct sdhci_host *host = slot->host;
mmc_detect_change(host->mmc, msecs_to_jiffies(200));
return IRQ_HANDLED;
}
static void sdhci_pci_add_own_cd(struct sdhci_pci_slot *slot)
{
int err, irq, gpio = slot->cd_gpio;
slot->cd_gpio = -EINVAL;
slot->cd_irq = -EINVAL;
if (!gpio_is_valid(gpio))
return;
err = gpio_request(gpio, "sd_cd");
if (err < 0)
goto out;
err = gpio_direction_input(gpio);
if (err < 0)
goto out_free;
irq = gpio_to_irq(gpio);
if (irq < 0)
goto out_free;
err = request_irq(irq, sdhci_pci_sd_cd, IRQF_TRIGGER_RISING |
IRQF_TRIGGER_FALLING, "sd_cd", slot);
if (err)
goto out_free;
slot->cd_gpio = gpio;
slot->cd_irq = irq;
return;
out_free:
gpio_free(gpio);
out:
dev_warn(&slot->chip->pdev->dev, "failed to setup card detect wake up\n");
}
static void sdhci_pci_remove_own_cd(struct sdhci_pci_slot *slot)
{
if (slot->cd_irq >= 0)
free_irq(slot->cd_irq, slot);
if (gpio_is_valid(slot->cd_gpio))
gpio_free(slot->cd_gpio);
}
static inline void sdhci_pci_add_own_cd(struct sdhci_pci_slot *slot)
{
}
static inline void sdhci_pci_remove_own_cd(struct sdhci_pci_slot *slot)
{
}
static int mfd_emmc_probe_slot(struct sdhci_pci_slot *slot)
{
slot->host->mmc->caps |= MMC_CAP_8_BIT_DATA | MMC_CAP_NONREMOVABLE;
slot->host->mmc->caps2 |= MMC_CAP2_BOOTPART_NOACC |
MMC_CAP2_HC_ERASE_SZ;
return 0;
}
static int mfd_sdio_probe_slot(struct sdhci_pci_slot *slot)
{
slot->host->mmc->caps |= MMC_CAP_POWER_OFF_CARD | MMC_CAP_NONREMOVABLE;
return 0;
}
static void sdhci_pci_int_hw_reset(struct sdhci_host *host)
{
u8 reg;
reg = sdhci_readb(host, SDHCI_POWER_CONTROL);
reg |= 0x10;
sdhci_writeb(host, reg, SDHCI_POWER_CONTROL);
udelay(9);
reg &= ~0x10;
sdhci_writeb(host, reg, SDHCI_POWER_CONTROL);
usleep_range(300, 1000);
}
static int spt_select_drive_strength(struct sdhci_host *host,
struct mmc_card *card,
unsigned int max_dtr,
int host_drv, int card_drv, int *drv_type)
{
int drive_strength;
if (sdhci_pci_spt_drive_strength > 0)
drive_strength = sdhci_pci_spt_drive_strength & 0xf;
else
drive_strength = 1;
if ((mmc_driver_type_mask(drive_strength) & card_drv) == 0)
drive_strength = 0;
return drive_strength;
}
static void spt_read_drive_strength(struct sdhci_host *host)
{
u32 val, i, t;
u16 m;
if (sdhci_pci_spt_drive_strength)
return;
sdhci_pci_spt_drive_strength = -1;
m = sdhci_readw(host, SDHCI_HOST_CONTROL2) & 0x7;
if (m != 3 && m != 5)
return;
val = sdhci_readl(host, SDHCI_PRESENT_STATE);
if (val & 0x3)
return;
sdhci_writel(host, 0x007f0023, SDHCI_INT_ENABLE);
sdhci_writel(host, 0, SDHCI_SIGNAL_ENABLE);
sdhci_writew(host, 0x10, SDHCI_TRANSFER_MODE);
sdhci_writeb(host, 0xe, SDHCI_TIMEOUT_CONTROL);
sdhci_writew(host, 512, SDHCI_BLOCK_SIZE);
sdhci_writew(host, 1, SDHCI_BLOCK_COUNT);
sdhci_writel(host, 0, SDHCI_ARGUMENT);
sdhci_writew(host, 0x83b, SDHCI_COMMAND);
for (i = 0; i < 1000; i++) {
val = sdhci_readl(host, SDHCI_INT_STATUS);
if (val & 0xffff8000)
return;
if (val & 0x20)
break;
udelay(1);
}
val = sdhci_readl(host, SDHCI_PRESENT_STATE);
if (!(val & 0x800))
return;
for (i = 0; i < 47; i++)
val = sdhci_readl(host, SDHCI_BUFFER);
t = val & 0xf00;
if (t != 0x200 && t != 0x300)
return;
sdhci_pci_spt_drive_strength = 0x10 | ((val >> 12) & 0xf);
}
static int byt_emmc_probe_slot(struct sdhci_pci_slot *slot)
{
slot->host->mmc->caps |= MMC_CAP_8_BIT_DATA | MMC_CAP_NONREMOVABLE |
MMC_CAP_HW_RESET | MMC_CAP_1_8V_DDR |
MMC_CAP_BUS_WIDTH_TEST |
MMC_CAP_WAIT_WHILE_BUSY;
slot->host->mmc->caps2 |= MMC_CAP2_HC_ERASE_SZ;
slot->hw_reset = sdhci_pci_int_hw_reset;
if (slot->chip->pdev->device == PCI_DEVICE_ID_INTEL_BSW_EMMC)
slot->host->timeout_clk = 1000;
if (slot->chip->pdev->device == PCI_DEVICE_ID_INTEL_SPT_EMMC) {
spt_read_drive_strength(slot->host);
slot->select_drive_strength = spt_select_drive_strength;
}
return 0;
}
static int byt_sdio_probe_slot(struct sdhci_pci_slot *slot)
{
slot->host->mmc->caps |= MMC_CAP_POWER_OFF_CARD | MMC_CAP_NONREMOVABLE |
MMC_CAP_BUS_WIDTH_TEST |
MMC_CAP_WAIT_WHILE_BUSY;
return 0;
}
static int byt_sd_probe_slot(struct sdhci_pci_slot *slot)
{
slot->host->mmc->caps |= MMC_CAP_BUS_WIDTH_TEST |
MMC_CAP_WAIT_WHILE_BUSY;
slot->cd_con_id = NULL;
slot->cd_idx = 0;
slot->cd_override_level = true;
return 0;
}
static int intel_mrfl_mmc_probe_slot(struct sdhci_pci_slot *slot)
{
if ((PCI_FUNC(slot->chip->pdev->devfn) != INTEL_MRFL_EMMC_0) &&
(PCI_FUNC(slot->chip->pdev->devfn) != INTEL_MRFL_EMMC_1))
return -ENODEV;
slot->host->mmc->caps |= MMC_CAP_8_BIT_DATA | MMC_CAP_NONREMOVABLE |
MMC_CAP_1_8V_DDR;
return 0;
}
static int jmicron_pmos(struct sdhci_pci_chip *chip, int on)
{
u8 scratch;
int ret;
ret = pci_read_config_byte(chip->pdev, 0xAE, &scratch);
if (ret)
return ret;
if (on)
scratch |= 0x47;
else
scratch &= ~0x47;
return pci_write_config_byte(chip->pdev, 0xAE, scratch);
}
static int jmicron_probe(struct sdhci_pci_chip *chip)
{
int ret;
u16 mmcdev = 0;
if (chip->pdev->revision == 0) {
chip->quirks |= SDHCI_QUIRK_32BIT_DMA_ADDR |
SDHCI_QUIRK_32BIT_DMA_SIZE |
SDHCI_QUIRK_32BIT_ADMA_SIZE |
SDHCI_QUIRK_RESET_AFTER_REQUEST |
SDHCI_QUIRK_BROKEN_SMALL_PIO;
}
if (chip->pdev->device == PCI_DEVICE_ID_JMICRON_JMB38X_SD)
mmcdev = PCI_DEVICE_ID_JMICRON_JMB38X_MMC;
else if (chip->pdev->device == PCI_DEVICE_ID_JMICRON_JMB388_SD)
mmcdev = PCI_DEVICE_ID_JMICRON_JMB388_ESD;
if (mmcdev) {
struct pci_dev *sd_dev;
sd_dev = NULL;
while ((sd_dev = pci_get_device(PCI_VENDOR_ID_JMICRON,
mmcdev, sd_dev)) != NULL) {
if ((PCI_SLOT(chip->pdev->devfn) ==
PCI_SLOT(sd_dev->devfn)) &&
(chip->pdev->bus == sd_dev->bus))
break;
}
if (sd_dev) {
pci_dev_put(sd_dev);
dev_info(&chip->pdev->dev, "Refusing to bind to "
"secondary interface.\n");
return -ENODEV;
}
}
ret = jmicron_pmos(chip, 1);
if (ret) {
dev_err(&chip->pdev->dev, "Failure enabling card power\n");
return ret;
}
if (chip->pdev->device == PCI_DEVICE_ID_JMICRON_JMB388_SD ||
chip->pdev->device == PCI_DEVICE_ID_JMICRON_JMB388_ESD)
chip->quirks |= SDHCI_QUIRK_UNSTABLE_RO_DETECT;
return 0;
}
static void jmicron_enable_mmc(struct sdhci_host *host, int on)
{
u8 scratch;
scratch = readb(host->ioaddr + 0xC0);
if (on)
scratch |= 0x01;
else
scratch &= ~0x01;
writeb(scratch, host->ioaddr + 0xC0);
}
static int jmicron_probe_slot(struct sdhci_pci_slot *slot)
{
if (slot->chip->pdev->revision == 0) {
u16 version;
version = readl(slot->host->ioaddr + SDHCI_HOST_VERSION);
version = (version & SDHCI_VENDOR_VER_MASK) >>
SDHCI_VENDOR_VER_SHIFT;
if (version < 0xAC)
slot->host->quirks |= SDHCI_QUIRK_BROKEN_ADMA;
}
if (slot->chip->pdev->device == PCI_DEVICE_ID_JMICRON_JMB388_ESD) {
slot->host->ocr_avail_sd = MMC_VDD_32_33 | MMC_VDD_33_34 |
MMC_VDD_29_30 | MMC_VDD_30_31 |
MMC_VDD_165_195;
slot->host->ocr_avail_mmc = MMC_VDD_32_33 | MMC_VDD_33_34 |
MMC_VDD_29_30 | MMC_VDD_30_31;
}
if (slot->chip->pdev->device == PCI_DEVICE_ID_JMICRON_JMB38X_MMC ||
slot->chip->pdev->device == PCI_DEVICE_ID_JMICRON_JMB388_ESD)
jmicron_enable_mmc(slot->host, 1);
slot->host->mmc->caps |= MMC_CAP_BUS_WIDTH_TEST;
return 0;
}
static void jmicron_remove_slot(struct sdhci_pci_slot *slot, int dead)
{
if (dead)
return;
if (slot->chip->pdev->device == PCI_DEVICE_ID_JMICRON_JMB38X_MMC ||
slot->chip->pdev->device == PCI_DEVICE_ID_JMICRON_JMB388_ESD)
jmicron_enable_mmc(slot->host, 0);
}
static int jmicron_suspend(struct sdhci_pci_chip *chip)
{
int i;
if (chip->pdev->device == PCI_DEVICE_ID_JMICRON_JMB38X_MMC ||
chip->pdev->device == PCI_DEVICE_ID_JMICRON_JMB388_ESD) {
for (i = 0; i < chip->num_slots; i++)
jmicron_enable_mmc(chip->slots[i]->host, 0);
}
return 0;
}
static int jmicron_resume(struct sdhci_pci_chip *chip)
{
int ret, i;
if (chip->pdev->device == PCI_DEVICE_ID_JMICRON_JMB38X_MMC ||
chip->pdev->device == PCI_DEVICE_ID_JMICRON_JMB388_ESD) {
for (i = 0; i < chip->num_slots; i++)
jmicron_enable_mmc(chip->slots[i]->host, 1);
}
ret = jmicron_pmos(chip, 1);
if (ret) {
dev_err(&chip->pdev->dev, "Failure enabling card power\n");
return ret;
}
return 0;
}
static int syskt_probe(struct sdhci_pci_chip *chip)
{
if ((chip->pdev->class & 0x0000FF) == PCI_SDHCI_IFVENDOR) {
chip->pdev->class &= ~0x0000FF;
chip->pdev->class |= PCI_SDHCI_IFDMA;
}
return 0;
}
static int syskt_probe_slot(struct sdhci_pci_slot *slot)
{
int tm, ps;
u8 board_rev = readb(slot->host->ioaddr + SYSKT_BOARD_REV);
u8 chip_rev = readb(slot->host->ioaddr + SYSKT_CHIP_REV);
dev_info(&slot->chip->pdev->dev, "SysKonnect CardBus2SDIO, "
"board rev %d.%d, chip rev %d.%d\n",
board_rev >> 4, board_rev & 0xf,
chip_rev >> 4, chip_rev & 0xf);
if (chip_rev >= 0x20)
slot->host->quirks |= SDHCI_QUIRK_FORCE_DMA;
writeb(SYSKT_POWER_330, slot->host->ioaddr + SYSKT_POWER_DATA);
writeb(SYSKT_POWER_START, slot->host->ioaddr + SYSKT_POWER_CMD);
udelay(50);
tm = 10;
do {
ps = readw(slot->host->ioaddr + SYSKT_POWER_STATUS);
if (ps & SYSKT_POWER_STATUS_OK)
break;
udelay(100);
} while (--tm);
if (!tm) {
dev_err(&slot->chip->pdev->dev,
"power regulator never stabilized");
writeb(0, slot->host->ioaddr + SYSKT_POWER_CMD);
return -ENODEV;
}
return 0;
}
static int via_probe(struct sdhci_pci_chip *chip)
{
if (chip->pdev->revision == 0x10)
chip->quirks |= SDHCI_QUIRK_DELAY_AFTER_POWER;
return 0;
}
static int rtsx_probe_slot(struct sdhci_pci_slot *slot)
{
slot->host->mmc->caps2 |= MMC_CAP2_HS200;
return 0;
}
static int amd_probe(struct sdhci_pci_chip *chip)
{
struct pci_dev *smbus_dev;
enum amd_chipset_gen gen;
smbus_dev = pci_get_device(PCI_VENDOR_ID_AMD,
PCI_DEVICE_ID_AMD_HUDSON2_SMBUS, NULL);
if (smbus_dev) {
gen = AMD_CHIPSET_BEFORE_ML;
} else {
smbus_dev = pci_get_device(PCI_VENDOR_ID_AMD,
PCI_DEVICE_ID_AMD_KERNCZ_SMBUS, NULL);
if (smbus_dev) {
if (smbus_dev->revision < 0x51)
gen = AMD_CHIPSET_CZ;
else
gen = AMD_CHIPSET_NL;
} else {
gen = AMD_CHIPSET_UNKNOWN;
}
}
if ((gen == AMD_CHIPSET_BEFORE_ML) || (gen == AMD_CHIPSET_CZ)) {
chip->quirks2 |= SDHCI_QUIRK2_CLEAR_TRANSFERMODE_REG_BEFORE_CMD;
chip->quirks2 |= SDHCI_QUIRK2_BROKEN_HS200;
}
return 0;
}
static int sdhci_pci_enable_dma(struct sdhci_host *host)
{
struct sdhci_pci_slot *slot;
struct pci_dev *pdev;
int ret = -1;
slot = sdhci_priv(host);
pdev = slot->chip->pdev;
if (((pdev->class & 0xFFFF00) == (PCI_CLASS_SYSTEM_SDHCI << 8)) &&
((pdev->class & 0x0000FF) != PCI_SDHCI_IFDMA) &&
(host->flags & SDHCI_USE_SDMA)) {
dev_warn(&pdev->dev, "Will use DMA mode even though HW "
"doesn't fully claim to support it.\n");
}
if (host->flags & SDHCI_USE_64_BIT_DMA) {
if (host->quirks2 & SDHCI_QUIRK2_BROKEN_64_BIT_DMA) {
host->flags &= ~SDHCI_USE_64_BIT_DMA;
} else {
ret = pci_set_dma_mask(pdev, DMA_BIT_MASK(64));
if (ret)
dev_warn(&pdev->dev, "Failed to set 64-bit DMA mask\n");
}
}
if (ret)
ret = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (ret)
return ret;
pci_set_master(pdev);
return 0;
}
static void sdhci_pci_set_bus_width(struct sdhci_host *host, int width)
{
u8 ctrl;
ctrl = sdhci_readb(host, SDHCI_HOST_CONTROL);
switch (width) {
case MMC_BUS_WIDTH_8:
ctrl |= SDHCI_CTRL_8BITBUS;
ctrl &= ~SDHCI_CTRL_4BITBUS;
break;
case MMC_BUS_WIDTH_4:
ctrl |= SDHCI_CTRL_4BITBUS;
ctrl &= ~SDHCI_CTRL_8BITBUS;
break;
default:
ctrl &= ~(SDHCI_CTRL_8BITBUS | SDHCI_CTRL_4BITBUS);
break;
}
sdhci_writeb(host, ctrl, SDHCI_HOST_CONTROL);
}
static void sdhci_pci_gpio_hw_reset(struct sdhci_host *host)
{
struct sdhci_pci_slot *slot = sdhci_priv(host);
int rst_n_gpio = slot->rst_n_gpio;
if (!gpio_is_valid(rst_n_gpio))
return;
gpio_set_value_cansleep(rst_n_gpio, 0);
udelay(10);
gpio_set_value_cansleep(rst_n_gpio, 1);
usleep_range(300, 1000);
}
static void sdhci_pci_hw_reset(struct sdhci_host *host)
{
struct sdhci_pci_slot *slot = sdhci_priv(host);
if (slot->hw_reset)
slot->hw_reset(host);
}
static int sdhci_pci_select_drive_strength(struct sdhci_host *host,
struct mmc_card *card,
unsigned int max_dtr, int host_drv,
int card_drv, int *drv_type)
{
struct sdhci_pci_slot *slot = sdhci_priv(host);
if (!slot->select_drive_strength)
return 0;
return slot->select_drive_strength(host, card, max_dtr, host_drv,
card_drv, drv_type);
}
static int sdhci_pci_suspend(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct sdhci_pci_chip *chip;
struct sdhci_pci_slot *slot;
mmc_pm_flag_t slot_pm_flags;
mmc_pm_flag_t pm_flags = 0;
int i, ret;
chip = pci_get_drvdata(pdev);
if (!chip)
return 0;
for (i = 0; i < chip->num_slots; i++) {
slot = chip->slots[i];
if (!slot)
continue;
ret = sdhci_suspend_host(slot->host);
if (ret)
goto err_pci_suspend;
slot_pm_flags = slot->host->mmc->pm_flags;
if (slot_pm_flags & MMC_PM_WAKE_SDIO_IRQ)
sdhci_enable_irq_wakeups(slot->host);
pm_flags |= slot_pm_flags;
}
if (chip->fixes && chip->fixes->suspend) {
ret = chip->fixes->suspend(chip);
if (ret)
goto err_pci_suspend;
}
if (pm_flags & MMC_PM_KEEP_POWER) {
if (pm_flags & MMC_PM_WAKE_SDIO_IRQ)
device_init_wakeup(dev, true);
else
device_init_wakeup(dev, false);
} else
device_init_wakeup(dev, false);
return 0;
err_pci_suspend:
while (--i >= 0)
sdhci_resume_host(chip->slots[i]->host);
return ret;
}
static int sdhci_pci_resume(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct sdhci_pci_chip *chip;
struct sdhci_pci_slot *slot;
int i, ret;
chip = pci_get_drvdata(pdev);
if (!chip)
return 0;
if (chip->fixes && chip->fixes->resume) {
ret = chip->fixes->resume(chip);
if (ret)
return ret;
}
for (i = 0; i < chip->num_slots; i++) {
slot = chip->slots[i];
if (!slot)
continue;
ret = sdhci_resume_host(slot->host);
if (ret)
return ret;
}
return 0;
}
static int sdhci_pci_runtime_suspend(struct device *dev)
{
struct pci_dev *pdev = container_of(dev, struct pci_dev, dev);
struct sdhci_pci_chip *chip;
struct sdhci_pci_slot *slot;
int i, ret;
chip = pci_get_drvdata(pdev);
if (!chip)
return 0;
for (i = 0; i < chip->num_slots; i++) {
slot = chip->slots[i];
if (!slot)
continue;
ret = sdhci_runtime_suspend_host(slot->host);
if (ret)
goto err_pci_runtime_suspend;
}
if (chip->fixes && chip->fixes->suspend) {
ret = chip->fixes->suspend(chip);
if (ret)
goto err_pci_runtime_suspend;
}
return 0;
err_pci_runtime_suspend:
while (--i >= 0)
sdhci_runtime_resume_host(chip->slots[i]->host);
return ret;
}
static int sdhci_pci_runtime_resume(struct device *dev)
{
struct pci_dev *pdev = container_of(dev, struct pci_dev, dev);
struct sdhci_pci_chip *chip;
struct sdhci_pci_slot *slot;
int i, ret;
chip = pci_get_drvdata(pdev);
if (!chip)
return 0;
if (chip->fixes && chip->fixes->resume) {
ret = chip->fixes->resume(chip);
if (ret)
return ret;
}
for (i = 0; i < chip->num_slots; i++) {
slot = chip->slots[i];
if (!slot)
continue;
ret = sdhci_runtime_resume_host(slot->host);
if (ret)
return ret;
}
return 0;
}
static struct sdhci_pci_slot *sdhci_pci_probe_slot(
struct pci_dev *pdev, struct sdhci_pci_chip *chip, int first_bar,
int slotno)
{
struct sdhci_pci_slot *slot;
struct sdhci_host *host;
int ret, bar = first_bar + slotno;
if (!(pci_resource_flags(pdev, bar) & IORESOURCE_MEM)) {
dev_err(&pdev->dev, "BAR %d is not iomem. Aborting.\n", bar);
return ERR_PTR(-ENODEV);
}
if (pci_resource_len(pdev, bar) < 0x100) {
dev_err(&pdev->dev, "Invalid iomem size. You may "
"experience problems.\n");
}
if ((pdev->class & 0x0000FF) == PCI_SDHCI_IFVENDOR) {
dev_err(&pdev->dev, "Vendor specific interface. Aborting.\n");
return ERR_PTR(-ENODEV);
}
if ((pdev->class & 0x0000FF) > PCI_SDHCI_IFVENDOR) {
dev_err(&pdev->dev, "Unknown interface. Aborting.\n");
return ERR_PTR(-ENODEV);
}
host = sdhci_alloc_host(&pdev->dev, sizeof(struct sdhci_pci_slot));
if (IS_ERR(host)) {
dev_err(&pdev->dev, "cannot allocate host\n");
return ERR_CAST(host);
}
slot = sdhci_priv(host);
slot->chip = chip;
slot->host = host;
slot->pci_bar = bar;
slot->rst_n_gpio = -EINVAL;
slot->cd_gpio = -EINVAL;
slot->cd_idx = -1;
if (*sdhci_pci_get_data)
slot->data = sdhci_pci_get_data(pdev, slotno);
if (slot->data) {
if (slot->data->setup) {
ret = slot->data->setup(slot->data);
if (ret) {
dev_err(&pdev->dev, "platform setup failed\n");
goto free;
}
}
slot->rst_n_gpio = slot->data->rst_n_gpio;
slot->cd_gpio = slot->data->cd_gpio;
}
host->hw_name = "PCI";
host->ops = &sdhci_pci_ops;
host->quirks = chip->quirks;
host->quirks2 = chip->quirks2;
host->irq = pdev->irq;
ret = pci_request_region(pdev, bar, mmc_hostname(host->mmc));
if (ret) {
dev_err(&pdev->dev, "cannot request region\n");
goto cleanup;
}
host->ioaddr = pci_ioremap_bar(pdev, bar);
if (!host->ioaddr) {
dev_err(&pdev->dev, "failed to remap registers\n");
ret = -ENOMEM;
goto release;
}
if (chip->fixes && chip->fixes->probe_slot) {
ret = chip->fixes->probe_slot(slot);
if (ret)
goto unmap;
}
if (gpio_is_valid(slot->rst_n_gpio)) {
if (!gpio_request(slot->rst_n_gpio, "eMMC_reset")) {
gpio_direction_output(slot->rst_n_gpio, 1);
slot->host->mmc->caps |= MMC_CAP_HW_RESET;
slot->hw_reset = sdhci_pci_gpio_hw_reset;
} else {
dev_warn(&pdev->dev, "failed to request rst_n_gpio\n");
slot->rst_n_gpio = -EINVAL;
}
}
host->mmc->pm_caps = MMC_PM_KEEP_POWER | MMC_PM_WAKE_SDIO_IRQ;
host->mmc->slotno = slotno;
host->mmc->caps2 |= MMC_CAP2_NO_PRESCAN_POWERUP;
if (slot->cd_idx >= 0 &&
mmc_gpiod_request_cd(host->mmc, slot->cd_con_id, slot->cd_idx,
slot->cd_override_level, 0, NULL)) {
dev_warn(&pdev->dev, "failed to setup card detect gpio\n");
slot->cd_idx = -1;
}
ret = sdhci_add_host(host);
if (ret)
goto remove;
sdhci_pci_add_own_cd(slot);
if (chip->fixes && chip->fixes->own_cd_for_runtime_pm &&
!gpio_is_valid(slot->cd_gpio) && slot->cd_idx < 0)
chip->allow_runtime_pm = false;
return slot;
remove:
if (gpio_is_valid(slot->rst_n_gpio))
gpio_free(slot->rst_n_gpio);
if (chip->fixes && chip->fixes->remove_slot)
chip->fixes->remove_slot(slot, 0);
unmap:
iounmap(host->ioaddr);
release:
pci_release_region(pdev, bar);
cleanup:
if (slot->data && slot->data->cleanup)
slot->data->cleanup(slot->data);
free:
sdhci_free_host(host);
return ERR_PTR(ret);
}
static void sdhci_pci_remove_slot(struct sdhci_pci_slot *slot)
{
int dead;
u32 scratch;
sdhci_pci_remove_own_cd(slot);
dead = 0;
scratch = readl(slot->host->ioaddr + SDHCI_INT_STATUS);
if (scratch == (u32)-1)
dead = 1;
sdhci_remove_host(slot->host, dead);
if (gpio_is_valid(slot->rst_n_gpio))
gpio_free(slot->rst_n_gpio);
if (slot->chip->fixes && slot->chip->fixes->remove_slot)
slot->chip->fixes->remove_slot(slot, dead);
if (slot->data && slot->data->cleanup)
slot->data->cleanup(slot->data);
pci_release_region(slot->chip->pdev, slot->pci_bar);
sdhci_free_host(slot->host);
}
static void sdhci_pci_runtime_pm_allow(struct device *dev)
{
pm_runtime_put_noidle(dev);
pm_runtime_allow(dev);
pm_runtime_set_autosuspend_delay(dev, 50);
pm_runtime_use_autosuspend(dev);
pm_suspend_ignore_children(dev, 1);
}
static void sdhci_pci_runtime_pm_forbid(struct device *dev)
{
pm_runtime_forbid(dev);
pm_runtime_get_noresume(dev);
}
static int sdhci_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct sdhci_pci_chip *chip;
struct sdhci_pci_slot *slot;
u8 slots, first_bar;
int ret, i;
BUG_ON(pdev == NULL);
BUG_ON(ent == NULL);
dev_info(&pdev->dev, "SDHCI controller found [%04x:%04x] (rev %x)\n",
(int)pdev->vendor, (int)pdev->device, (int)pdev->revision);
ret = pci_read_config_byte(pdev, PCI_SLOT_INFO, &slots);
if (ret)
return ret;
slots = PCI_SLOT_INFO_SLOTS(slots) + 1;
dev_dbg(&pdev->dev, "found %d slot(s)\n", slots);
if (slots == 0)
return -ENODEV;
BUG_ON(slots > MAX_SLOTS);
ret = pci_read_config_byte(pdev, PCI_SLOT_INFO, &first_bar);
if (ret)
return ret;
first_bar &= PCI_SLOT_INFO_FIRST_BAR_MASK;
if (first_bar > 5) {
dev_err(&pdev->dev, "Invalid first BAR. Aborting.\n");
return -ENODEV;
}
ret = pci_enable_device(pdev);
if (ret)
return ret;
chip = kzalloc(sizeof(struct sdhci_pci_chip), GFP_KERNEL);
if (!chip) {
ret = -ENOMEM;
goto err;
}
chip->pdev = pdev;
chip->fixes = (const struct sdhci_pci_fixes *)ent->driver_data;
if (chip->fixes) {
chip->quirks = chip->fixes->quirks;
chip->quirks2 = chip->fixes->quirks2;
chip->allow_runtime_pm = chip->fixes->allow_runtime_pm;
}
chip->num_slots = slots;
pci_set_drvdata(pdev, chip);
if (chip->fixes && chip->fixes->probe) {
ret = chip->fixes->probe(chip);
if (ret)
goto free;
}
slots = chip->num_slots;
for (i = 0; i < slots; i++) {
slot = sdhci_pci_probe_slot(pdev, chip, first_bar, i);
if (IS_ERR(slot)) {
for (i--; i >= 0; i--)
sdhci_pci_remove_slot(chip->slots[i]);
ret = PTR_ERR(slot);
goto free;
}
chip->slots[i] = slot;
}
if (chip->allow_runtime_pm)
sdhci_pci_runtime_pm_allow(&pdev->dev);
return 0;
free:
pci_set_drvdata(pdev, NULL);
kfree(chip);
err:
pci_disable_device(pdev);
return ret;
}
static void sdhci_pci_remove(struct pci_dev *pdev)
{
int i;
struct sdhci_pci_chip *chip;
chip = pci_get_drvdata(pdev);
if (chip) {
if (chip->allow_runtime_pm)
sdhci_pci_runtime_pm_forbid(&pdev->dev);
for (i = 0; i < chip->num_slots; i++)
sdhci_pci_remove_slot(chip->slots[i]);
pci_set_drvdata(pdev, NULL);
kfree(chip);
}
pci_disable_device(pdev);
}
