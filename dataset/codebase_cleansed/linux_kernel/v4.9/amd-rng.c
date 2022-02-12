static int amd_rng_read(struct hwrng *rng, void *buf, size_t max, bool wait)
{
u32 *data = buf;
struct amd768_priv *priv = (struct amd768_priv *)rng->priv;
size_t read = 0;
int timeout = max / 4 + 1;
while (read < max) {
if (ioread32(priv->iobase + RNGDONE) == 0) {
if (wait) {
usleep_range(128, 196);
if (timeout-- == 0)
return read;
} else {
return 0;
}
} else {
*data = ioread32(priv->iobase + RNGDATA);
data++;
read += 4;
}
}
return read;
}
static int amd_rng_init(struct hwrng *rng)
{
struct amd768_priv *priv = (struct amd768_priv *)rng->priv;
u8 rnen;
pci_read_config_byte(priv->pcidev, 0x40, &rnen);
rnen |= BIT(7);
pci_write_config_byte(priv->pcidev, 0x40, rnen);
pci_read_config_byte(priv->pcidev, 0x41, &rnen);
rnen |= BIT(7);
pci_write_config_byte(priv->pcidev, 0x41, rnen);
return 0;
}
static void amd_rng_cleanup(struct hwrng *rng)
{
struct amd768_priv *priv = (struct amd768_priv *)rng->priv;
u8 rnen;
pci_read_config_byte(priv->pcidev, 0x40, &rnen);
rnen &= ~BIT(7);
pci_write_config_byte(priv->pcidev, 0x40, rnen);
}
static int __init mod_init(void)
{
int err = -ENODEV;
struct pci_dev *pdev = NULL;
const struct pci_device_id *ent;
u32 pmbase;
struct amd768_priv *priv;
for_each_pci_dev(pdev) {
ent = pci_match_id(pci_tbl, pdev);
if (ent)
goto found;
}
return -ENODEV;
found:
err = pci_read_config_dword(pdev, 0x58, &pmbase);
if (err)
return err;
pmbase &= 0x0000FF00;
if (pmbase == 0)
return -EIO;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
if (!devm_request_region(&pdev->dev, pmbase + PMBASE_OFFSET,
PMBASE_SIZE, DRV_NAME)) {
dev_err(&pdev->dev, DRV_NAME " region 0x%x already in use!\n",
pmbase + 0xF0);
return -EBUSY;
}
priv->iobase = devm_ioport_map(&pdev->dev, pmbase + PMBASE_OFFSET,
PMBASE_SIZE);
if (!priv->iobase) {
pr_err(DRV_NAME "Cannot map ioport\n");
return -ENOMEM;
}
amd_rng.priv = (unsigned long)priv;
priv->pcidev = pdev;
pr_info(DRV_NAME " detected\n");
return devm_hwrng_register(&pdev->dev, &amd_rng);
}
static void __exit mod_exit(void)
{
}
