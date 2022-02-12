static void vr_nor_destroy_partitions(struct vr_nor_mtd *p)
{
mtd_device_unregister(p->info);
}
static int vr_nor_init_partitions(struct vr_nor_mtd *p)
{
return mtd_device_parse_register(p->info, NULL, NULL, NULL, 0);
}
static void vr_nor_destroy_mtd_setup(struct vr_nor_mtd *p)
{
map_destroy(p->info);
}
static int vr_nor_mtd_setup(struct vr_nor_mtd *p)
{
static const char * const probe_types[] =
{ "cfi_probe", "jedec_probe", NULL };
const char * const *type;
for (type = probe_types; !p->info && *type; type++)
p->info = do_map_probe(*type, &p->map);
if (!p->info)
return -ENODEV;
p->info->owner = THIS_MODULE;
return 0;
}
static void vr_nor_destroy_maps(struct vr_nor_mtd *p)
{
unsigned int exp_timing_cs0;
exp_timing_cs0 = readl(p->csr_base + EXP_TIMING_CS0);
exp_timing_cs0 &= ~TIMING_WR_EN;
writel(exp_timing_cs0, p->csr_base + EXP_TIMING_CS0);
iounmap(p->map.virt);
iounmap(p->csr_base);
}
static int vr_nor_init_maps(struct vr_nor_mtd *p)
{
unsigned long csr_phys, csr_len;
unsigned long win_phys, win_len;
unsigned int exp_timing_cs0;
int err;
csr_phys = pci_resource_start(p->dev, EXP_CSR_MBAR);
csr_len = pci_resource_len(p->dev, EXP_CSR_MBAR);
win_phys = pci_resource_start(p->dev, EXP_WIN_MBAR);
win_len = pci_resource_len(p->dev, EXP_WIN_MBAR);
if (!csr_phys || !csr_len || !win_phys || !win_len)
return -ENODEV;
if (win_len < (CS0_START + CS0_SIZE))
return -ENXIO;
p->csr_base = ioremap_nocache(csr_phys, csr_len);
if (!p->csr_base)
return -ENOMEM;
exp_timing_cs0 = readl(p->csr_base + EXP_TIMING_CS0);
if (!(exp_timing_cs0 & TIMING_CS_EN)) {
dev_warn(&p->dev->dev, "Expansion Bus Chip Select 0 "
"is disabled.\n");
err = -ENODEV;
goto release;
}
if ((exp_timing_cs0 & TIMING_MASK) == TIMING_MASK) {
dev_warn(&p->dev->dev, "Expansion Bus Chip Select 0 "
"is configured for maximally slow access times.\n");
}
p->map.name = DRV_NAME;
p->map.bankwidth = (exp_timing_cs0 & TIMING_BYTE_EN) ? 1 : 2;
p->map.phys = win_phys + CS0_START;
p->map.size = CS0_SIZE;
p->map.virt = ioremap_nocache(p->map.phys, p->map.size);
if (!p->map.virt) {
err = -ENOMEM;
goto release;
}
simple_map_init(&p->map);
exp_timing_cs0 |= TIMING_BOOT_ACCEL_DIS | TIMING_WR_EN;
writel(exp_timing_cs0, p->csr_base + EXP_TIMING_CS0);
return 0;
release:
iounmap(p->csr_base);
return err;
}
static void vr_nor_pci_remove(struct pci_dev *dev)
{
struct vr_nor_mtd *p = pci_get_drvdata(dev);
vr_nor_destroy_partitions(p);
vr_nor_destroy_mtd_setup(p);
vr_nor_destroy_maps(p);
kfree(p);
pci_release_regions(dev);
pci_disable_device(dev);
}
static int vr_nor_pci_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
struct vr_nor_mtd *p = NULL;
unsigned int exp_timing_cs0;
int err;
err = pci_enable_device(dev);
if (err)
goto out;
err = pci_request_regions(dev, DRV_NAME);
if (err)
goto disable_dev;
p = kzalloc(sizeof(*p), GFP_KERNEL);
err = -ENOMEM;
if (!p)
goto release;
p->dev = dev;
err = vr_nor_init_maps(p);
if (err)
goto release;
err = vr_nor_mtd_setup(p);
if (err)
goto destroy_maps;
err = vr_nor_init_partitions(p);
if (err)
goto destroy_mtd_setup;
pci_set_drvdata(dev, p);
return 0;
destroy_mtd_setup:
map_destroy(p->info);
destroy_maps:
exp_timing_cs0 = readl(p->csr_base + EXP_TIMING_CS0);
exp_timing_cs0 &= ~TIMING_WR_EN;
writel(exp_timing_cs0, p->csr_base + EXP_TIMING_CS0);
iounmap(p->map.virt);
iounmap(p->csr_base);
release:
kfree(p);
pci_release_regions(dev);
disable_dev:
pci_disable_device(dev);
out:
return err;
}
