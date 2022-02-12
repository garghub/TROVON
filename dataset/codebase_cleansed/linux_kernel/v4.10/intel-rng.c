static inline u8 hwstatus_get(void __iomem *mem)
{
return readb(mem + INTEL_RNG_HW_STATUS);
}
static inline u8 hwstatus_set(void __iomem *mem,
u8 hw_status)
{
writeb(hw_status, mem + INTEL_RNG_HW_STATUS);
return hwstatus_get(mem);
}
static int intel_rng_data_present(struct hwrng *rng, int wait)
{
void __iomem *mem = (void __iomem *)rng->priv;
int data, i;
for (i = 0; i < 20; i++) {
data = !!(readb(mem + INTEL_RNG_STATUS) &
INTEL_RNG_DATA_PRESENT);
if (data || !wait)
break;
udelay(10);
}
return data;
}
static int intel_rng_data_read(struct hwrng *rng, u32 *data)
{
void __iomem *mem = (void __iomem *)rng->priv;
*data = readb(mem + INTEL_RNG_DATA);
return 1;
}
static int intel_rng_init(struct hwrng *rng)
{
void __iomem *mem = (void __iomem *)rng->priv;
u8 hw_status;
int err = -EIO;
hw_status = hwstatus_get(mem);
if ((hw_status & INTEL_RNG_ENABLED) == 0)
hw_status = hwstatus_set(mem, hw_status | INTEL_RNG_ENABLED);
if ((hw_status & INTEL_RNG_ENABLED) == 0) {
pr_err(PFX "cannot enable RNG, aborting\n");
goto out;
}
err = 0;
out:
return err;
}
static void intel_rng_cleanup(struct hwrng *rng)
{
void __iomem *mem = (void __iomem *)rng->priv;
u8 hw_status;
hw_status = hwstatus_get(mem);
if (hw_status & INTEL_RNG_ENABLED)
hwstatus_set(mem, hw_status & ~INTEL_RNG_ENABLED);
else
pr_warn(PFX "unusual: RNG already disabled\n");
}
static int __init intel_rng_hw_init(void *_intel_rng_hw)
{
struct intel_rng_hw *intel_rng_hw = _intel_rng_hw;
u8 mfc, dvc;
if (!(intel_rng_hw->fwh_dec_en1_val & FWH_F8_EN_MASK))
pci_write_config_byte(intel_rng_hw->dev,
intel_rng_hw->fwh_dec_en1_off,
intel_rng_hw->fwh_dec_en1_val |
FWH_F8_EN_MASK);
if (!(intel_rng_hw->bios_cntl_val & BIOS_CNTL_WRITE_ENABLE_MASK))
pci_write_config_byte(intel_rng_hw->dev,
intel_rng_hw->bios_cntl_off,
intel_rng_hw->bios_cntl_val |
BIOS_CNTL_WRITE_ENABLE_MASK);
writeb(INTEL_FWH_RESET_CMD, intel_rng_hw->mem);
writeb(INTEL_FWH_READ_ID_CMD, intel_rng_hw->mem);
mfc = readb(intel_rng_hw->mem + INTEL_FWH_MANUFACTURER_CODE_ADDRESS);
dvc = readb(intel_rng_hw->mem + INTEL_FWH_DEVICE_CODE_ADDRESS);
writeb(INTEL_FWH_RESET_CMD, intel_rng_hw->mem);
if (!(intel_rng_hw->bios_cntl_val &
(BIOS_CNTL_LOCK_ENABLE_MASK|BIOS_CNTL_WRITE_ENABLE_MASK)))
pci_write_config_byte(intel_rng_hw->dev,
intel_rng_hw->bios_cntl_off,
intel_rng_hw->bios_cntl_val);
if (!(intel_rng_hw->fwh_dec_en1_val & FWH_F8_EN_MASK))
pci_write_config_byte(intel_rng_hw->dev,
intel_rng_hw->fwh_dec_en1_off,
intel_rng_hw->fwh_dec_en1_val);
if (mfc != INTEL_FWH_MANUFACTURER_CODE ||
(dvc != INTEL_FWH_DEVICE_CODE_8M &&
dvc != INTEL_FWH_DEVICE_CODE_4M)) {
pr_notice(PFX "FWH not detected\n");
return -ENODEV;
}
return 0;
}
static int __init intel_init_hw_struct(struct intel_rng_hw *intel_rng_hw,
struct pci_dev *dev)
{
intel_rng_hw->bios_cntl_val = 0xff;
intel_rng_hw->fwh_dec_en1_val = 0xff;
intel_rng_hw->dev = dev;
if (dev->device < 0x2640) {
intel_rng_hw->fwh_dec_en1_off = FWH_DEC_EN1_REG_OLD;
intel_rng_hw->bios_cntl_off = BIOS_CNTL_REG_OLD;
} else {
intel_rng_hw->fwh_dec_en1_off = FWH_DEC_EN1_REG_NEW;
intel_rng_hw->bios_cntl_off = BIOS_CNTL_REG_NEW;
}
pci_read_config_byte(dev, intel_rng_hw->fwh_dec_en1_off,
&intel_rng_hw->fwh_dec_en1_val);
pci_read_config_byte(dev, intel_rng_hw->bios_cntl_off,
&intel_rng_hw->bios_cntl_val);
if ((intel_rng_hw->bios_cntl_val &
(BIOS_CNTL_LOCK_ENABLE_MASK|BIOS_CNTL_WRITE_ENABLE_MASK))
== BIOS_CNTL_LOCK_ENABLE_MASK) {
static __initdata char warning[] =
PFX "Firmware space is locked read-only. If you can't or\n"
PFX "don't want to disable this in firmware setup, and if\n"
PFX "you are certain that your system has a functional\n"
PFX "RNG, try using the 'no_fwh_detect' option.\n";
if (no_fwh_detect)
return -ENODEV;
pr_warn("%s", warning);
return -EBUSY;
}
intel_rng_hw->mem = ioremap_nocache(INTEL_FWH_ADDR, INTEL_FWH_ADDR_LEN);
if (intel_rng_hw->mem == NULL)
return -EBUSY;
return 0;
}
static int __init mod_init(void)
{
int err = -ENODEV;
int i;
struct pci_dev *dev = NULL;
void __iomem *mem = mem;
u8 hw_status;
struct intel_rng_hw *intel_rng_hw;
for (i = 0; !dev && pci_tbl[i].vendor; ++i)
dev = pci_get_device(pci_tbl[i].vendor, pci_tbl[i].device,
NULL);
if (!dev)
goto out;
if (no_fwh_detect < 0) {
pci_dev_put(dev);
goto fwh_done;
}
intel_rng_hw = kmalloc(sizeof(*intel_rng_hw), GFP_KERNEL);
if (!intel_rng_hw) {
pci_dev_put(dev);
goto out;
}
err = intel_init_hw_struct(intel_rng_hw, dev);
if (err) {
pci_dev_put(dev);
kfree(intel_rng_hw);
if (err == -ENODEV)
goto fwh_done;
goto out;
}
err = stop_machine(intel_rng_hw_init, intel_rng_hw, NULL);
pci_dev_put(dev);
iounmap(intel_rng_hw->mem);
kfree(intel_rng_hw);
if (err)
goto out;
fwh_done:
err = -ENOMEM;
mem = ioremap(INTEL_RNG_ADDR, INTEL_RNG_ADDR_LEN);
if (!mem)
goto out;
intel_rng.priv = (unsigned long)mem;
err = -ENODEV;
hw_status = hwstatus_get(mem);
if ((hw_status & INTEL_RNG_PRESENT) == 0) {
iounmap(mem);
goto out;
}
pr_info("Intel 82802 RNG detected\n");
err = hwrng_register(&intel_rng);
if (err) {
pr_err(PFX "RNG registering failed (%d)\n",
err);
iounmap(mem);
}
out:
return err;
}
static void __exit mod_exit(void)
{
void __iomem *mem = (void __iomem *)intel_rng.priv;
hwrng_unregister(&intel_rng);
iounmap(mem);
}
