static int
ahc_linux_pci_dev_suspend(struct pci_dev *pdev, pm_message_t mesg)
{
struct ahc_softc *ahc = pci_get_drvdata(pdev);
int rc;
if ((rc = ahc_suspend(ahc)))
return rc;
pci_save_state(pdev);
pci_disable_device(pdev);
if (mesg.event & PM_EVENT_SLEEP)
pci_set_power_state(pdev, PCI_D3hot);
return rc;
}
static int
ahc_linux_pci_dev_resume(struct pci_dev *pdev)
{
struct ahc_softc *ahc = pci_get_drvdata(pdev);
int rc;
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
if ((rc = pci_enable_device(pdev))) {
dev_printk(KERN_ERR, &pdev->dev,
"failed to enable device after resume (%d)\n", rc);
return rc;
}
pci_set_master(pdev);
ahc_pci_resume(ahc);
return (ahc_resume(ahc));
}
static void
ahc_linux_pci_dev_remove(struct pci_dev *pdev)
{
struct ahc_softc *ahc = pci_get_drvdata(pdev);
u_long s;
if (ahc->platform_data && ahc->platform_data->host)
scsi_remove_host(ahc->platform_data->host);
ahc_lock(ahc, &s);
ahc_intr_enable(ahc, FALSE);
ahc_unlock(ahc, &s);
ahc_free(ahc);
}
static void
ahc_linux_pci_inherit_flags(struct ahc_softc *ahc)
{
struct pci_dev *pdev = ahc->dev_softc, *master_pdev;
unsigned int master_devfn = PCI_DEVFN(PCI_SLOT(pdev->devfn), 0);
master_pdev = pci_get_slot(pdev->bus, master_devfn);
if (master_pdev) {
struct ahc_softc *master = pci_get_drvdata(master_pdev);
if (master) {
ahc->flags &= ~AHC_BIOS_ENABLED;
ahc->flags |= master->flags & AHC_BIOS_ENABLED;
ahc->flags &= ~AHC_PRIMARY_CHANNEL;
ahc->flags |= master->flags & AHC_PRIMARY_CHANNEL;
} else
printk(KERN_ERR "aic7xxx: no multichannel peer found!\n");
pci_dev_put(master_pdev);
}
}
static int
ahc_linux_pci_dev_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
char buf[80];
const uint64_t mask_39bit = 0x7FFFFFFFFFULL;
struct ahc_softc *ahc;
ahc_dev_softc_t pci;
const struct ahc_pci_identity *entry;
char *name;
int error;
struct device *dev = &pdev->dev;
pci = pdev;
entry = ahc_find_pci_device(pci);
if (entry == NULL)
return (-ENODEV);
sprintf(buf, "ahc_pci:%d:%d:%d",
ahc_get_pci_bus(pci),
ahc_get_pci_slot(pci),
ahc_get_pci_function(pci));
name = kmalloc(strlen(buf) + 1, GFP_ATOMIC);
if (name == NULL)
return (-ENOMEM);
strcpy(name, buf);
ahc = ahc_alloc(NULL, name);
if (ahc == NULL)
return (-ENOMEM);
if (pci_enable_device(pdev)) {
ahc_free(ahc);
return (-ENODEV);
}
pci_set_master(pdev);
if (sizeof(dma_addr_t) > 4
&& ahc->features & AHC_LARGE_SCBS
&& dma_set_mask(dev, mask_39bit) == 0
&& dma_get_required_mask(dev) > DMA_BIT_MASK(32)) {
ahc->flags |= AHC_39BIT_ADDRESSING;
} else {
if (dma_set_mask(dev, DMA_BIT_MASK(32))) {
ahc_free(ahc);
printk(KERN_WARNING "aic7xxx: No suitable DMA available.\n");
return (-ENODEV);
}
}
ahc->dev_softc = pci;
error = ahc_pci_config(ahc, entry);
if (error != 0) {
ahc_free(ahc);
return (-error);
}
if ((ahc->features & AHC_MULTI_FUNC) && PCI_FUNC(pdev->devfn) != 0)
ahc_linux_pci_inherit_flags(ahc);
pci_set_drvdata(pdev, ahc);
ahc_linux_register_host(ahc, &aic7xxx_driver_template);
return (0);
}
uint32_t
ahc_pci_read_config(ahc_dev_softc_t pci, int reg, int width)
{
switch (width) {
case 1:
{
uint8_t retval;
pci_read_config_byte(pci, reg, &retval);
return (retval);
}
case 2:
{
uint16_t retval;
pci_read_config_word(pci, reg, &retval);
return (retval);
}
case 4:
{
uint32_t retval;
pci_read_config_dword(pci, reg, &retval);
return (retval);
}
default:
panic("ahc_pci_read_config: Read size too big");
return (0);
}
}
void
ahc_pci_write_config(ahc_dev_softc_t pci, int reg, uint32_t value, int width)
{
switch (width) {
case 1:
pci_write_config_byte(pci, reg, value);
break;
case 2:
pci_write_config_word(pci, reg, value);
break;
case 4:
pci_write_config_dword(pci, reg, value);
break;
default:
panic("ahc_pci_write_config: Write size too big");
}
}
int
ahc_linux_pci_init(void)
{
return pci_register_driver(&aic7xxx_pci_driver);
}
void
ahc_linux_pci_exit(void)
{
pci_unregister_driver(&aic7xxx_pci_driver);
}
static int
ahc_linux_pci_reserve_io_region(struct ahc_softc *ahc, resource_size_t *base)
{
if (aic7xxx_allow_memio == 0)
return (ENOMEM);
*base = pci_resource_start(ahc->dev_softc, 0);
if (*base == 0)
return (ENOMEM);
if (!request_region(*base, 256, "aic7xxx"))
return (ENOMEM);
return (0);
}
static int
ahc_linux_pci_reserve_mem_region(struct ahc_softc *ahc,
resource_size_t *bus_addr,
uint8_t __iomem **maddr)
{
resource_size_t start;
int error;
error = 0;
start = pci_resource_start(ahc->dev_softc, 1);
if (start != 0) {
*bus_addr = start;
if (!request_mem_region(start, 0x1000, "aic7xxx"))
error = ENOMEM;
if (error == 0) {
*maddr = ioremap_nocache(start, 256);
if (*maddr == NULL) {
error = ENOMEM;
release_mem_region(start, 0x1000);
}
}
} else
error = ENOMEM;
return (error);
}
int
ahc_pci_map_registers(struct ahc_softc *ahc)
{
uint32_t command;
resource_size_t base;
uint8_t __iomem *maddr;
int error;
command = ahc_pci_read_config(ahc->dev_softc, PCIR_COMMAND, 4);
command &= ~(PCIM_CMD_PORTEN|PCIM_CMD_MEMEN);
base = 0;
maddr = NULL;
error = ahc_linux_pci_reserve_mem_region(ahc, &base, &maddr);
if (error == 0) {
ahc->platform_data->mem_busaddr = base;
ahc->tag = BUS_SPACE_MEMIO;
ahc->bsh.maddr = maddr;
ahc_pci_write_config(ahc->dev_softc, PCIR_COMMAND,
command | PCIM_CMD_MEMEN, 4);
if (ahc_pci_test_register_access(ahc) != 0) {
printk("aic7xxx: PCI Device %d:%d:%d "
"failed memory mapped test. Using PIO.\n",
ahc_get_pci_bus(ahc->dev_softc),
ahc_get_pci_slot(ahc->dev_softc),
ahc_get_pci_function(ahc->dev_softc));
iounmap(maddr);
release_mem_region(ahc->platform_data->mem_busaddr,
0x1000);
ahc->bsh.maddr = NULL;
maddr = NULL;
} else
command |= PCIM_CMD_MEMEN;
} else {
printk("aic7xxx: PCI%d:%d:%d MEM region 0x%llx "
"unavailable. Cannot memory map device.\n",
ahc_get_pci_bus(ahc->dev_softc),
ahc_get_pci_slot(ahc->dev_softc),
ahc_get_pci_function(ahc->dev_softc),
(unsigned long long)base);
}
if (maddr == NULL) {
error = ahc_linux_pci_reserve_io_region(ahc, &base);
if (error == 0) {
ahc->tag = BUS_SPACE_PIO;
ahc->bsh.ioport = (u_long)base;
command |= PCIM_CMD_PORTEN;
} else {
printk("aic7xxx: PCI%d:%d:%d IO region 0x%llx[0..255] "
"unavailable. Cannot map device.\n",
ahc_get_pci_bus(ahc->dev_softc),
ahc_get_pci_slot(ahc->dev_softc),
ahc_get_pci_function(ahc->dev_softc),
(unsigned long long)base);
}
}
ahc_pci_write_config(ahc->dev_softc, PCIR_COMMAND, command, 4);
return (error);
}
int
ahc_pci_map_int(struct ahc_softc *ahc)
{
int error;
error = request_irq(ahc->dev_softc->irq, ahc_linux_isr,
IRQF_SHARED, "aic7xxx", ahc);
if (error == 0)
ahc->platform_data->irq = ahc->dev_softc->irq;
return (-error);
}
