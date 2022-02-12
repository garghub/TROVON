static int geode_rng_data_read(struct hwrng *rng, u32 *data)
{
void __iomem *mem = (void __iomem *)rng->priv;
*data = readl(mem + GEODE_RNG_DATA_REG);
return 4;
}
static int geode_rng_data_present(struct hwrng *rng, int wait)
{
void __iomem *mem = (void __iomem *)rng->priv;
int data, i;
for (i = 0; i < 20; i++) {
data = !!(readl(mem + GEODE_RNG_STATUS_REG));
if (data || !wait)
break;
udelay(10);
}
return data;
}
static int __init mod_init(void)
{
int err = -ENODEV;
struct pci_dev *pdev = NULL;
const struct pci_device_id *ent;
void __iomem *mem;
unsigned long rng_base;
for_each_pci_dev(pdev) {
ent = pci_match_id(pci_tbl, pdev);
if (ent)
goto found;
}
goto out;
found:
rng_base = pci_resource_start(pdev, 0);
if (rng_base == 0)
goto out;
err = -ENOMEM;
mem = ioremap(rng_base, 0x58);
if (!mem)
goto out;
geode_rng.priv = (unsigned long)mem;
printk(KERN_INFO "AMD Geode RNG detected\n");
err = hwrng_register(&geode_rng);
if (err) {
printk(KERN_ERR PFX "RNG registering failed (%d)\n",
err);
goto err_unmap;
}
out:
return err;
err_unmap:
iounmap(mem);
goto out;
}
static void __exit mod_exit(void)
{
void __iomem *mem = (void __iomem *)geode_rng.priv;
hwrng_unregister(&geode_rng);
iounmap(mem);
}
