static void spiderpci_io_flush(struct iowa_bus *bus)
{
struct spiderpci_iowa_private *priv;
u32 val;
priv = bus->private;
val = in_be32(priv->regs + SPIDER_PCI_DUMMY_READ);
iosync();
}
static void spiderpci_memcpy_fromio(void *dest, const PCI_IO_ADDR src,
unsigned long n)
{
__do_memcpy_fromio(dest, src, n);
spiderpci_io_flush(iowa_mem_find_bus(src));
}
static int __init spiderpci_pci_setup_chip(struct pci_controller *phb,
void __iomem *regs)
{
void *dummy_page_va;
dma_addr_t dummy_page_da;
#ifdef SPIDER_PCI_DISABLE_PREFETCH
u32 val = in_be32(regs + SPIDER_PCI_VCI_CNTL_STAT);
pr_debug("SPIDER_IOWA:PVCI_Control_Status was 0x%08x\n", val);
out_be32(regs + SPIDER_PCI_VCI_CNTL_STAT, val | 0x8);
#endif
dummy_page_va = kmalloc(PAGE_SIZE, GFP_KERNEL);
if (!dummy_page_va) {
pr_err("SPIDERPCI-IOWA:Alloc dummy_page_va failed.\n");
return -1;
}
dummy_page_da = dma_map_single(phb->parent, dummy_page_va,
PAGE_SIZE, DMA_FROM_DEVICE);
if (dma_mapping_error(phb->parent, dummy_page_da)) {
pr_err("SPIDER-IOWA:Map dummy page filed.\n");
kfree(dummy_page_va);
return -1;
}
out_be32(regs + SPIDER_PCI_DUMMY_READ_BASE, dummy_page_da);
return 0;
}
int __init spiderpci_iowa_init(struct iowa_bus *bus, void *data)
{
void __iomem *regs = NULL;
struct spiderpci_iowa_private *priv;
struct device_node *np = bus->phb->dn;
struct resource r;
unsigned long offset = (unsigned long)data;
pr_debug("SPIDERPCI-IOWA:Bus initialize for spider(%pOF)\n",
np);
priv = kzalloc(sizeof(struct spiderpci_iowa_private), GFP_KERNEL);
if (!priv) {
pr_err("SPIDERPCI-IOWA:"
"Can't allocate struct spiderpci_iowa_private");
return -1;
}
if (of_address_to_resource(np, 0, &r)) {
pr_err("SPIDERPCI-IOWA:Can't get resource.\n");
goto error;
}
regs = ioremap(r.start + offset, SPIDER_PCI_REG_SIZE);
if (!regs) {
pr_err("SPIDERPCI-IOWA:ioremap failed.\n");
goto error;
}
priv->regs = regs;
bus->private = priv;
if (spiderpci_pci_setup_chip(bus->phb, regs))
goto error;
return 0;
error:
kfree(priv);
bus->private = NULL;
if (regs)
iounmap(regs);
return -1;
}
