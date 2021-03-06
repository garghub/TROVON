static int ide_setup_pci_baseregs(struct pci_dev *dev, const char *name)
{
u8 progif = 0;
if (pci_read_config_byte(dev, PCI_CLASS_PROG, &progif) ||
(progif & 5) != 5) {
if ((progif & 0xa) != 0xa) {
printk(KERN_INFO "%s %s: device not capable of full "
"native PCI mode\n", name, pci_name(dev));
return -EOPNOTSUPP;
}
printk(KERN_INFO "%s %s: placing both ports into native PCI "
"mode\n", name, pci_name(dev));
(void) pci_write_config_byte(dev, PCI_CLASS_PROG, progif|5);
if (pci_read_config_byte(dev, PCI_CLASS_PROG, &progif) ||
(progif & 5) != 5) {
printk(KERN_ERR "%s %s: rewrite of PROGIF failed, "
"wanted 0x%04x, got 0x%04x\n",
name, pci_name(dev), progif | 5, progif);
return -EOPNOTSUPP;
}
}
return 0;
}
static int ide_pci_clear_simplex(unsigned long dma_base, const char *name)
{
u8 dma_stat = inb(dma_base + 2);
outb(dma_stat & 0x60, dma_base + 2);
dma_stat = inb(dma_base + 2);
return (dma_stat & 0x80) ? 1 : 0;
}
unsigned long ide_pci_dma_base(ide_hwif_t *hwif, const struct ide_port_info *d)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
unsigned long dma_base = 0;
if (hwif->host_flags & IDE_HFLAG_MMIO)
return hwif->dma_base;
if (hwif->mate && hwif->mate->dma_base) {
dma_base = hwif->mate->dma_base - (hwif->channel ? 0 : 8);
} else {
u8 baridx = (d->host_flags & IDE_HFLAG_CS5520) ? 2 : 4;
dma_base = pci_resource_start(dev, baridx);
if (dma_base == 0) {
printk(KERN_ERR "%s %s: DMA base is invalid\n",
d->name, pci_name(dev));
return 0;
}
}
if (hwif->channel)
dma_base += 8;
return dma_base;
}
int ide_pci_check_simplex(ide_hwif_t *hwif, const struct ide_port_info *d)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
u8 dma_stat;
if (d->host_flags & (IDE_HFLAG_MMIO | IDE_HFLAG_CS5520))
goto out;
if (d->host_flags & IDE_HFLAG_CLEAR_SIMPLEX) {
if (ide_pci_clear_simplex(hwif->dma_base, d->name))
printk(KERN_INFO "%s %s: simplex device: DMA forced\n",
d->name, pci_name(dev));
goto out;
}
dma_stat = hwif->dma_ops->dma_sff_read_status(hwif);
if ((dma_stat & 0x80) && hwif->mate && hwif->mate->dma_base) {
printk(KERN_INFO "%s %s: simplex device: DMA disabled\n",
d->name, pci_name(dev));
return -1;
}
out:
return 0;
}
int ide_pci_set_master(struct pci_dev *dev, const char *name)
{
u16 pcicmd;
pci_read_config_word(dev, PCI_COMMAND, &pcicmd);
if ((pcicmd & PCI_COMMAND_MASTER) == 0) {
pci_set_master(dev);
if (pci_read_config_word(dev, PCI_COMMAND, &pcicmd) ||
(pcicmd & PCI_COMMAND_MASTER) == 0) {
printk(KERN_ERR "%s %s: error updating PCICMD\n",
name, pci_name(dev));
return -EIO;
}
}
return 0;
}
void ide_setup_pci_noise(struct pci_dev *dev, const struct ide_port_info *d)
{
printk(KERN_INFO "%s %s: IDE controller (0x%04x:0x%04x rev 0x%02x)\n",
d->name, pci_name(dev),
dev->vendor, dev->device, dev->revision);
}
static int ide_pci_enable(struct pci_dev *dev, int bars,
const struct ide_port_info *d)
{
int ret;
if (pci_enable_device(dev)) {
ret = pci_enable_device_io(dev);
if (ret < 0) {
printk(KERN_WARNING "%s %s: couldn't enable device\n",
d->name, pci_name(dev));
goto out;
}
printk(KERN_WARNING "%s %s: BIOS configuration fixed\n",
d->name, pci_name(dev));
}
ret = dma_set_mask(&dev->dev, DMA_BIT_MASK(32));
if (ret < 0) {
printk(KERN_ERR "%s %s: can't set DMA mask\n",
d->name, pci_name(dev));
goto out;
}
ret = pci_request_selected_regions(dev, bars, d->name);
if (ret < 0)
printk(KERN_ERR "%s %s: can't reserve resources\n",
d->name, pci_name(dev));
out:
return ret;
}
static int ide_pci_configure(struct pci_dev *dev, const struct ide_port_info *d)
{
u16 pcicmd = 0;
if (ide_setup_pci_baseregs(dev, d->name) ||
pci_write_config_word(dev, PCI_COMMAND, pcicmd | PCI_COMMAND_IO)) {
printk(KERN_INFO "%s %s: device disabled (BIOS)\n",
d->name, pci_name(dev));
return -ENODEV;
}
if (pci_read_config_word(dev, PCI_COMMAND, &pcicmd)) {
printk(KERN_ERR "%s %s: error accessing PCI regs\n",
d->name, pci_name(dev));
return -EIO;
}
if (!(pcicmd & PCI_COMMAND_IO)) {
printk(KERN_ERR "%s %s: unable to enable IDE controller\n",
d->name, pci_name(dev));
return -ENXIO;
}
return 0;
}
static int ide_pci_check_iomem(struct pci_dev *dev, const struct ide_port_info *d,
int bar)
{
ulong flags = pci_resource_flags(dev, bar);
if (!flags || pci_resource_len(dev, bar) == 0)
return 0;
if (flags & IORESOURCE_IO)
return 0;
return -EINVAL;
}
static int ide_hw_configure(struct pci_dev *dev, const struct ide_port_info *d,
unsigned int port, struct ide_hw *hw)
{
unsigned long ctl = 0, base = 0;
if ((d->host_flags & IDE_HFLAG_ISA_PORTS) == 0) {
if (ide_pci_check_iomem(dev, d, 2 * port) ||
ide_pci_check_iomem(dev, d, 2 * port + 1)) {
printk(KERN_ERR "%s %s: I/O baseregs (BIOS) are "
"reported as MEM for port %d!\n",
d->name, pci_name(dev), port);
return -EINVAL;
}
ctl = pci_resource_start(dev, 2*port+1);
base = pci_resource_start(dev, 2*port);
} else {
ctl = port ? 0x374 : 0x3f4;
base = port ? 0x170 : 0x1f0;
}
if (!base || !ctl) {
printk(KERN_ERR "%s %s: bad PCI BARs for port %d, skipping\n",
d->name, pci_name(dev), port);
return -EINVAL;
}
memset(hw, 0, sizeof(*hw));
hw->dev = &dev->dev;
ide_std_init_ports(hw, base, ctl | 2);
return 0;
}
int ide_hwif_setup_dma(ide_hwif_t *hwif, const struct ide_port_info *d)
{
struct pci_dev *dev = to_pci_dev(hwif->dev);
if ((d->host_flags & IDE_HFLAG_NO_AUTODMA) == 0 ||
((dev->class >> 8) == PCI_CLASS_STORAGE_IDE &&
(dev->class & 0x80))) {
unsigned long base = ide_pci_dma_base(hwif, d);
if (base == 0)
return -1;
hwif->dma_base = base;
if (hwif->dma_ops == NULL)
hwif->dma_ops = &sff_dma_ops;
if (ide_pci_check_simplex(hwif, d) < 0)
return -1;
if (ide_pci_set_master(dev, d->name) < 0)
return -1;
if (hwif->host_flags & IDE_HFLAG_MMIO)
printk(KERN_INFO " %s: MMIO-DMA\n", hwif->name);
else
printk(KERN_INFO " %s: BM-DMA at 0x%04lx-0x%04lx\n",
hwif->name, base, base + 7);
hwif->extra_base = base + (hwif->channel ? 8 : 16);
if (ide_allocate_dma_engine(hwif))
return -1;
}
return 0;
}
static int ide_setup_pci_controller(struct pci_dev *dev, int bars,
const struct ide_port_info *d, int noisy)
{
int ret;
u16 pcicmd;
if (noisy)
ide_setup_pci_noise(dev, d);
ret = ide_pci_enable(dev, bars, d);
if (ret < 0)
goto out;
ret = pci_read_config_word(dev, PCI_COMMAND, &pcicmd);
if (ret < 0) {
printk(KERN_ERR "%s %s: error accessing PCI regs\n",
d->name, pci_name(dev));
goto out_free_bars;
}
if (!(pcicmd & PCI_COMMAND_IO)) {
ret = ide_pci_configure(dev, d);
if (ret < 0)
goto out_free_bars;
printk(KERN_INFO "%s %s: device enabled (Linux)\n",
d->name, pci_name(dev));
}
goto out;
out_free_bars:
pci_release_selected_regions(dev, bars);
out:
return ret;
}
void ide_pci_setup_ports(struct pci_dev *dev, const struct ide_port_info *d,
struct ide_hw *hw, struct ide_hw **hws)
{
int channels = (d->host_flags & IDE_HFLAG_SINGLE) ? 1 : 2, port;
u8 tmp;
for (port = 0; port < channels; ++port) {
const struct ide_pci_enablebit *e = &d->enablebits[port];
if (e->reg && (pci_read_config_byte(dev, e->reg, &tmp) ||
(tmp & e->mask) != e->val)) {
printk(KERN_INFO "%s %s: IDE port disabled\n",
d->name, pci_name(dev));
continue;
}
if (ide_hw_configure(dev, d, port, hw + port))
continue;
*(hws + port) = hw + port;
}
}
static int do_ide_setup_pci_device(struct pci_dev *dev,
const struct ide_port_info *d,
u8 noisy)
{
int pciirq, ret;
pciirq = dev->irq;
ret = d->init_chipset ? d->init_chipset(dev) : 0;
if (ret < 0)
goto out;
if (ide_pci_is_in_compatibility_mode(dev)) {
if (noisy)
printk(KERN_INFO "%s %s: not 100%% native mode: will "
"probe irqs later\n", d->name, pci_name(dev));
pciirq = 0;
} else if (!pciirq && noisy) {
printk(KERN_WARNING "%s %s: bad irq (%d): will probe later\n",
d->name, pci_name(dev), pciirq);
} else if (noisy) {
printk(KERN_INFO "%s %s: 100%% native mode on irq %d\n",
d->name, pci_name(dev), pciirq);
}
ret = pciirq;
out:
return ret;
}
int ide_pci_init_two(struct pci_dev *dev1, struct pci_dev *dev2,
const struct ide_port_info *d, void *priv)
{
struct pci_dev *pdev[] = { dev1, dev2 };
struct ide_host *host;
int ret, i, n_ports = dev2 ? 4 : 2, bars;
struct ide_hw hw[4], *hws[] = { NULL, NULL, NULL, NULL };
if (d->host_flags & IDE_HFLAG_SINGLE)
bars = (1 << 2) - 1;
else
bars = (1 << 4) - 1;
if ((d->host_flags & IDE_HFLAG_NO_DMA) == 0) {
if (d->host_flags & IDE_HFLAG_CS5520)
bars |= (1 << 2);
else
bars |= (1 << 4);
}
for (i = 0; i < n_ports / 2; i++) {
ret = ide_setup_pci_controller(pdev[i], bars, d, !i);
if (ret < 0) {
if (i == 1)
pci_release_selected_regions(pdev[0], bars);
goto out;
}
ide_pci_setup_ports(pdev[i], d, &hw[i*2], &hws[i*2]);
}
host = ide_host_alloc(d, hws, n_ports);
if (host == NULL) {
ret = -ENOMEM;
goto out_free_bars;
}
host->dev[0] = &dev1->dev;
if (dev2)
host->dev[1] = &dev2->dev;
host->host_priv = priv;
host->irq_flags = IRQF_SHARED;
pci_set_drvdata(pdev[0], host);
if (dev2)
pci_set_drvdata(pdev[1], host);
for (i = 0; i < n_ports / 2; i++) {
ret = do_ide_setup_pci_device(pdev[i], d, !i);
if (ret < 0)
goto out_free_bars;
if (ide_pci_is_in_compatibility_mode(pdev[i])) {
hw[i*2].irq = pci_get_legacy_ide_irq(pdev[i], 0);
hw[i*2 + 1].irq = pci_get_legacy_ide_irq(pdev[i], 1);
} else
hw[i*2 + 1].irq = hw[i*2].irq = ret;
}
ret = ide_host_register(host, d, hws);
if (ret)
ide_host_free(host);
else
goto out;
out_free_bars:
i = n_ports / 2;
while (i--)
pci_release_selected_regions(pdev[i], bars);
out:
return ret;
}
int ide_pci_init_one(struct pci_dev *dev, const struct ide_port_info *d,
void *priv)
{
return ide_pci_init_two(dev, NULL, d, priv);
}
void ide_pci_remove(struct pci_dev *dev)
{
struct ide_host *host = pci_get_drvdata(dev);
struct pci_dev *dev2 = host->dev[1] ? to_pci_dev(host->dev[1]) : NULL;
int bars;
if (host->host_flags & IDE_HFLAG_SINGLE)
bars = (1 << 2) - 1;
else
bars = (1 << 4) - 1;
if ((host->host_flags & IDE_HFLAG_NO_DMA) == 0) {
if (host->host_flags & IDE_HFLAG_CS5520)
bars |= (1 << 2);
else
bars |= (1 << 4);
}
ide_host_remove(host);
if (dev2)
pci_release_selected_regions(dev2, bars);
pci_release_selected_regions(dev, bars);
if (dev2)
pci_disable_device(dev2);
pci_disable_device(dev);
}
int ide_pci_suspend(struct pci_dev *dev, pm_message_t state)
{
pci_save_state(dev);
pci_disable_device(dev);
pci_set_power_state(dev, pci_choose_state(dev, state));
return 0;
}
int ide_pci_resume(struct pci_dev *dev)
{
struct ide_host *host = pci_get_drvdata(dev);
int rc;
pci_set_power_state(dev, PCI_D0);
rc = pci_enable_device(dev);
if (rc)
return rc;
pci_restore_state(dev);
pci_set_master(dev);
if (host->init_chipset)
host->init_chipset(dev);
return 0;
}
