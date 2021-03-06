static int
ahd_linux_pci_dev_suspend(struct pci_dev *pdev, pm_message_t mesg)
{
struct ahd_softc *ahd = pci_get_drvdata(pdev);
int rc;
if ((rc = ahd_suspend(ahd)))
return rc;
ahd_pci_suspend(ahd);
pci_save_state(pdev);
pci_disable_device(pdev);
if (mesg.event & PM_EVENT_SLEEP)
pci_set_power_state(pdev, PCI_D3hot);
return rc;
}
static int
ahd_linux_pci_dev_resume(struct pci_dev *pdev)
{
struct ahd_softc *ahd = pci_get_drvdata(pdev);
int rc;
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
if ((rc = pci_enable_device(pdev))) {
dev_printk(KERN_ERR, &pdev->dev,
"failed to enable device after resume (%d)\n", rc);
return rc;
}
pci_set_master(pdev);
ahd_pci_resume(ahd);
ahd_resume(ahd);
return rc;
}
static void
ahd_linux_pci_dev_remove(struct pci_dev *pdev)
{
struct ahd_softc *ahd = pci_get_drvdata(pdev);
u_long s;
if (ahd->platform_data && ahd->platform_data->host)
scsi_remove_host(ahd->platform_data->host);
ahd_lock(ahd, &s);
ahd_intr_enable(ahd, FALSE);
ahd_unlock(ahd, &s);
ahd_free(ahd);
}
static void
ahd_linux_pci_inherit_flags(struct ahd_softc *ahd)
{
struct pci_dev *pdev = ahd->dev_softc, *master_pdev;
unsigned int master_devfn = PCI_DEVFN(PCI_SLOT(pdev->devfn), 0);
master_pdev = pci_get_slot(pdev->bus, master_devfn);
if (master_pdev) {
struct ahd_softc *master = pci_get_drvdata(master_pdev);
if (master) {
ahd->flags &= ~AHD_BIOS_ENABLED;
ahd->flags |= master->flags & AHD_BIOS_ENABLED;
} else
printk(KERN_ERR "aic79xx: no multichannel peer found!\n");
pci_dev_put(master_pdev);
}
}
static int
ahd_linux_pci_dev_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
char buf[80];
struct ahd_softc *ahd;
ahd_dev_softc_t pci;
const struct ahd_pci_identity *entry;
char *name;
int error;
struct device *dev = &pdev->dev;
pci = pdev;
entry = ahd_find_pci_device(pci);
if (entry == NULL)
return (-ENODEV);
sprintf(buf, "ahd_pci:%d:%d:%d",
ahd_get_pci_bus(pci),
ahd_get_pci_slot(pci),
ahd_get_pci_function(pci));
name = kstrdup(buf, GFP_ATOMIC);
if (name == NULL)
return (-ENOMEM);
ahd = ahd_alloc(NULL, name);
if (ahd == NULL)
return (-ENOMEM);
if (pci_enable_device(pdev)) {
ahd_free(ahd);
return (-ENODEV);
}
pci_set_master(pdev);
if (sizeof(dma_addr_t) > 4) {
const u64 required_mask = dma_get_required_mask(dev);
if (required_mask > DMA_BIT_MASK(39) &&
dma_set_mask(dev, DMA_BIT_MASK(64)) == 0)
ahd->flags |= AHD_64BIT_ADDRESSING;
else if (required_mask > DMA_BIT_MASK(32) &&
dma_set_mask(dev, DMA_BIT_MASK(39)) == 0)
ahd->flags |= AHD_39BIT_ADDRESSING;
else
dma_set_mask(dev, DMA_BIT_MASK(32));
} else {
dma_set_mask(dev, DMA_BIT_MASK(32));
}
ahd->dev_softc = pci;
error = ahd_pci_config(ahd, entry);
if (error != 0) {
ahd_free(ahd);
return (-error);
}
if ((ahd->features & AHD_MULTI_FUNC) && PCI_FUNC(pdev->devfn) != 0)
ahd_linux_pci_inherit_flags(ahd);
pci_set_drvdata(pdev, ahd);
ahd_linux_register_host(ahd, &aic79xx_driver_template);
return (0);
}
int
ahd_linux_pci_init(void)
{
return pci_register_driver(&aic79xx_pci_driver);
}
void
ahd_linux_pci_exit(void)
{
pci_unregister_driver(&aic79xx_pci_driver);
}
static int
ahd_linux_pci_reserve_io_regions(struct ahd_softc *ahd, resource_size_t *base,
resource_size_t *base2)
{
*base = pci_resource_start(ahd->dev_softc, 0);
*base2 = pci_resource_start(ahd->dev_softc, 3);
if (*base == 0 || *base2 == 0)
return (ENOMEM);
if (!request_region(*base, 256, "aic79xx"))
return (ENOMEM);
if (!request_region(*base2, 256, "aic79xx")) {
release_region(*base, 256);
return (ENOMEM);
}
return (0);
}
static int
ahd_linux_pci_reserve_mem_region(struct ahd_softc *ahd,
resource_size_t *bus_addr,
uint8_t __iomem **maddr)
{
resource_size_t start;
resource_size_t base_page;
u_long base_offset;
int error = 0;
if (aic79xx_allow_memio == 0)
return (ENOMEM);
if ((ahd->bugs & AHD_PCIX_MMAPIO_BUG) != 0)
return (ENOMEM);
start = pci_resource_start(ahd->dev_softc, 1);
base_page = start & PAGE_MASK;
base_offset = start - base_page;
if (start != 0) {
*bus_addr = start;
if (!request_mem_region(start, 0x1000, "aic79xx"))
error = ENOMEM;
if (!error) {
*maddr = ioremap_nocache(base_page, base_offset + 512);
if (*maddr == NULL) {
error = ENOMEM;
release_mem_region(start, 0x1000);
} else
*maddr += base_offset;
}
} else
error = ENOMEM;
return (error);
}
int
ahd_pci_map_registers(struct ahd_softc *ahd)
{
uint32_t command;
resource_size_t base;
uint8_t __iomem *maddr;
int error;
command = ahd_pci_read_config(ahd->dev_softc, PCIR_COMMAND, 4);
command &= ~(PCIM_CMD_PORTEN|PCIM_CMD_MEMEN);
base = 0;
maddr = NULL;
error = ahd_linux_pci_reserve_mem_region(ahd, &base, &maddr);
if (error == 0) {
ahd->platform_data->mem_busaddr = base;
ahd->tags[0] = BUS_SPACE_MEMIO;
ahd->bshs[0].maddr = maddr;
ahd->tags[1] = BUS_SPACE_MEMIO;
ahd->bshs[1].maddr = maddr + 0x100;
ahd_pci_write_config(ahd->dev_softc, PCIR_COMMAND,
command | PCIM_CMD_MEMEN, 4);
if (ahd_pci_test_register_access(ahd) != 0) {
printk("aic79xx: PCI Device %d:%d:%d "
"failed memory mapped test. Using PIO.\n",
ahd_get_pci_bus(ahd->dev_softc),
ahd_get_pci_slot(ahd->dev_softc),
ahd_get_pci_function(ahd->dev_softc));
iounmap(maddr);
release_mem_region(ahd->platform_data->mem_busaddr,
0x1000);
ahd->bshs[0].maddr = NULL;
maddr = NULL;
} else
command |= PCIM_CMD_MEMEN;
} else if (bootverbose) {
printk("aic79xx: PCI%d:%d:%d MEM region 0x%llx "
"unavailable. Cannot memory map device.\n",
ahd_get_pci_bus(ahd->dev_softc),
ahd_get_pci_slot(ahd->dev_softc),
ahd_get_pci_function(ahd->dev_softc),
(unsigned long long)base);
}
if (maddr == NULL) {
resource_size_t base2;
error = ahd_linux_pci_reserve_io_regions(ahd, &base, &base2);
if (error == 0) {
ahd->tags[0] = BUS_SPACE_PIO;
ahd->tags[1] = BUS_SPACE_PIO;
ahd->bshs[0].ioport = (u_long)base;
ahd->bshs[1].ioport = (u_long)base2;
command |= PCIM_CMD_PORTEN;
} else {
printk("aic79xx: PCI%d:%d:%d IO regions 0x%llx and "
"0x%llx unavailable. Cannot map device.\n",
ahd_get_pci_bus(ahd->dev_softc),
ahd_get_pci_slot(ahd->dev_softc),
ahd_get_pci_function(ahd->dev_softc),
(unsigned long long)base,
(unsigned long long)base2);
}
}
ahd_pci_write_config(ahd->dev_softc, PCIR_COMMAND, command, 4);
return (error);
}
int
ahd_pci_map_int(struct ahd_softc *ahd)
{
int error;
error = request_irq(ahd->dev_softc->irq, ahd_linux_isr,
IRQF_SHARED, "aic79xx", ahd);
if (!error)
ahd->platform_data->irq = ahd->dev_softc->irq;
return (-error);
}
void
ahd_power_state_change(struct ahd_softc *ahd, ahd_power_state new_state)
{
pci_set_power_state(ahd->dev_softc, new_state);
}
