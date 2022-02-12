static int amd_rng_data_present(struct hwrng *rng, int wait)
{
u32 pmbase = (u32)rng->priv;
int data, i;
for (i = 0; i < 20; i++) {
data = !!(inl(pmbase + 0xF4) & 1);
if (data || !wait)
break;
udelay(10);
}
return data;
}
static int amd_rng_data_read(struct hwrng *rng, u32 *data)
{
u32 pmbase = (u32)rng->priv;
*data = inl(pmbase + 0xF0);
return 4;
}
static int amd_rng_init(struct hwrng *rng)
{
u8 rnen;
pci_read_config_byte(amd_pdev, 0x40, &rnen);
rnen |= (1 << 7);
pci_write_config_byte(amd_pdev, 0x40, rnen);
pci_read_config_byte(amd_pdev, 0x41, &rnen);
rnen |= (1 << 7);
pci_write_config_byte(amd_pdev, 0x41, rnen);
return 0;
}
static void amd_rng_cleanup(struct hwrng *rng)
{
u8 rnen;
pci_read_config_byte(amd_pdev, 0x40, &rnen);
rnen &= ~(1 << 7);
pci_write_config_byte(amd_pdev, 0x40, rnen);
}
static int __init mod_init(void)
{
int err = -ENODEV;
struct pci_dev *pdev = NULL;
const struct pci_device_id *ent;
u32 pmbase;
for_each_pci_dev(pdev) {
ent = pci_match_id(pci_tbl, pdev);
if (ent)
goto found;
}
goto out;
found:
err = pci_read_config_dword(pdev, 0x58, &pmbase);
if (err)
goto out;
err = -EIO;
pmbase &= 0x0000FF00;
if (pmbase == 0)
goto out;
if (!request_region(pmbase + 0xF0, 8, "AMD HWRNG")) {
dev_err(&pdev->dev, "AMD HWRNG region 0x%x already in use!\n",
pmbase + 0xF0);
err = -EBUSY;
goto out;
}
amd_rng.priv = (unsigned long)pmbase;
amd_pdev = pdev;
pr_info("AMD768 RNG detected\n");
err = hwrng_register(&amd_rng);
if (err) {
pr_err(PFX "RNG registering failed (%d)\n",
err);
release_region(pmbase + 0xF0, 8);
goto out;
}
out:
return err;
}
static void __exit mod_exit(void)
{
u32 pmbase = (unsigned long)amd_rng.priv;
release_region(pmbase + 0xF0, 8);
hwrng_unregister(&amd_rng);
}
