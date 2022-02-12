static int dino_cfg_read(struct pci_bus *bus, unsigned int devfn, int where,
int size, u32 *val)
{
struct dino_device *d = DINO_DEV(parisc_walk_tree(bus->bridge));
u32 local_bus = (bus->parent == NULL) ? 0 : bus->busn_res.start;
u32 v = DINO_CFG_TOK(local_bus, devfn, where & ~3);
void __iomem *base_addr = d->hba.base_addr;
unsigned long flags;
DBG("%s: %p, %d, %d, %d\n", __func__, base_addr, devfn, where,
size);
spin_lock_irqsave(&d->dinosaur_pen, flags);
__raw_writel(v, base_addr + DINO_PCI_ADDR);
if (size == 1) {
*val = readb(base_addr + DINO_CONFIG_DATA + (where & 3));
} else if (size == 2) {
*val = readw(base_addr + DINO_CONFIG_DATA + (where & 2));
} else if (size == 4) {
*val = readl(base_addr + DINO_CONFIG_DATA);
}
spin_unlock_irqrestore(&d->dinosaur_pen, flags);
return 0;
}
static int dino_cfg_write(struct pci_bus *bus, unsigned int devfn, int where,
int size, u32 val)
{
struct dino_device *d = DINO_DEV(parisc_walk_tree(bus->bridge));
u32 local_bus = (bus->parent == NULL) ? 0 : bus->busn_res.start;
u32 v = DINO_CFG_TOK(local_bus, devfn, where & ~3);
void __iomem *base_addr = d->hba.base_addr;
unsigned long flags;
DBG("%s: %p, %d, %d, %d\n", __func__, base_addr, devfn, where,
size);
spin_lock_irqsave(&d->dinosaur_pen, flags);
__raw_writel(v & 0xffffff00, base_addr + DINO_PCI_ADDR);
__raw_readl(base_addr + DINO_CONFIG_DATA);
__raw_writel(v, base_addr + DINO_PCI_ADDR);
if (size == 1) {
writeb(val, base_addr + DINO_CONFIG_DATA + (where & 3));
} else if (size == 2) {
writew(val, base_addr + DINO_CONFIG_DATA + (where & 2));
} else if (size == 4) {
writel(val, base_addr + DINO_CONFIG_DATA);
}
spin_unlock_irqrestore(&d->dinosaur_pen, flags);
return 0;
}
static void dino_mask_irq(struct irq_data *d)
{
struct dino_device *dino_dev = irq_data_get_irq_chip_data(d);
int local_irq = gsc_find_local_irq(d->irq, dino_dev->global_irq, DINO_LOCAL_IRQS);
DBG(KERN_WARNING "%s(0x%p, %d)\n", __func__, dino_dev, d->irq);
dino_dev->imr &= ~(DINO_MASK_IRQ(local_irq));
__raw_writel(dino_dev->imr, dino_dev->hba.base_addr+DINO_IMR);
}
static void dino_unmask_irq(struct irq_data *d)
{
struct dino_device *dino_dev = irq_data_get_irq_chip_data(d);
int local_irq = gsc_find_local_irq(d->irq, dino_dev->global_irq, DINO_LOCAL_IRQS);
u32 tmp;
DBG(KERN_WARNING "%s(0x%p, %d)\n", __func__, dino_dev, d->irq);
__raw_readl(dino_dev->hba.base_addr+DINO_IPR);
dino_dev->imr |= DINO_MASK_IRQ(local_irq);
__raw_writel( dino_dev->imr, dino_dev->hba.base_addr+DINO_IMR);
tmp = __raw_readl(dino_dev->hba.base_addr+DINO_ILR);
if (tmp & DINO_MASK_IRQ(local_irq)) {
DBG(KERN_WARNING "%s(): IRQ asserted! (ILR 0x%x)\n",
__func__, tmp);
gsc_writel(dino_dev->txn_data, dino_dev->txn_addr);
}
}
static irqreturn_t dino_isr(int irq, void *intr_dev)
{
struct dino_device *dino_dev = intr_dev;
u32 mask;
int ilr_loop = 100;
#ifdef DINO_DEBUG
dino_dev->dino_irr0 =
#endif
mask = __raw_readl(dino_dev->hba.base_addr+DINO_IRR0) & DINO_IRR_MASK;
if (mask == 0)
return IRQ_NONE;
ilr_again:
do {
int local_irq = __ffs(mask);
int irq = dino_dev->global_irq[local_irq];
DBG(KERN_DEBUG "%s(%d, %p) mask 0x%x\n",
__func__, irq, intr_dev, mask);
generic_handle_irq(irq);
mask &= ~(1 << local_irq);
} while (mask);
mask = __raw_readl(dino_dev->hba.base_addr+DINO_ILR) & dino_dev->imr;
if (mask) {
if (--ilr_loop > 0)
goto ilr_again;
printk(KERN_ERR "Dino 0x%p: stuck interrupt %d\n",
dino_dev->hba.base_addr, mask);
return IRQ_NONE;
}
return IRQ_HANDLED;
}
static void dino_assign_irq(struct dino_device *dino, int local_irq, int *irqp)
{
int irq = gsc_assign_irq(&dino_interrupt_type, dino);
if (irq == NO_IRQ)
return;
*irqp = irq;
dino->global_irq[local_irq] = irq;
}
static void dino_choose_irq(struct parisc_device *dev, void *ctrl)
{
int irq;
struct dino_device *dino = ctrl;
switch (dev->id.sversion) {
case 0x00084: irq = 8; break;
case 0x0008c: irq = 10; break;
case 0x00096: irq = 8; break;
default: return;
}
dino_assign_irq(dino, irq, &dev->irq);
}
static void __devinit quirk_cirrus_cardbus(struct pci_dev *dev)
{
u8 new_irq = dev->irq - 1;
printk(KERN_INFO "PCI: Cirrus Cardbus IRQ fixup for %s, from %d to %d\n",
pci_name(dev), dev->irq, new_irq);
dev->irq = new_irq;
}
static void __init
dino_bios_init(void)
{
DBG("dino_bios_init\n");
}
static void __init
dino_card_setup(struct pci_bus *bus, void __iomem *base_addr)
{
int i;
struct dino_device *dino_dev = DINO_DEV(parisc_walk_tree(bus->bridge));
struct resource *res;
char name[128];
int size;
res = &dino_dev->hba.lmmio_space;
res->flags = IORESOURCE_MEM;
size = scnprintf(name, sizeof(name), "Dino LMMIO (%s)",
dev_name(bus->bridge));
res->name = kmalloc(size+1, GFP_KERNEL);
if(res->name)
strcpy((char *)res->name, name);
else
res->name = dino_dev->hba.lmmio_space.name;
if (ccio_allocate_resource(dino_dev->hba.dev, res, _8MB,
F_EXTEND(0xf0000000UL) | _8MB,
F_EXTEND(0xffffffffUL) &~ _8MB, _8MB) < 0) {
struct list_head *ln, *tmp_ln;
printk(KERN_ERR "Dino: cannot attach bus %s\n",
dev_name(bus->bridge));
list_for_each_safe(ln, tmp_ln, &bus->devices) {
struct pci_dev *dev = pci_dev_b(ln);
list_del(&dev->bus_list);
}
return;
}
bus->resource[1] = res;
bus->resource[0] = &(dino_dev->hba.io_space);
for (i = 1; i < 31; i++) {
if (res->start == F_EXTEND(0xf0000000UL | (i * _8MB)))
break;
}
DBG("DINO GSC WRITE i=%d, start=%lx, dino addr = %p\n",
i, res->start, base_addr + DINO_IO_ADDR_EN);
__raw_writel(1 << i, base_addr + DINO_IO_ADDR_EN);
}
static void __init
dino_card_fixup(struct pci_dev *dev)
{
u32 irq_pin;
if ((dev->class >> 8) == PCI_CLASS_BRIDGE_PCI) {
panic("Card-Mode Dino: PCI-PCI Bridge not supported\n");
}
dino_cfg_write(dev->bus, dev->devfn,
PCI_CACHE_LINE_SIZE, 2, 0xff00 | L1_CACHE_BYTES/4);
dino_cfg_read(dev->bus, dev->devfn, PCI_INTERRUPT_PIN, 1, &irq_pin);
dev->irq = pci_swizzle_interrupt_pin(dev, irq_pin) - 1;
dino_cfg_write(dev->bus, dev->devfn, PCI_INTERRUPT_LINE, 1, dev->irq);
}
static void __init
dino_fixup_bus(struct pci_bus *bus)
{
struct list_head *ln;
struct pci_dev *dev;
struct dino_device *dino_dev = DINO_DEV(parisc_walk_tree(bus->bridge));
DBG(KERN_WARNING "%s(0x%p) bus %d platform_data 0x%p\n",
__func__, bus, bus->busn_res.start,
bus->bridge->platform_data);
if (is_card_dino(&dino_dev->hba.dev->id)) {
dino_card_setup(bus, dino_dev->hba.base_addr);
} else if (bus->parent) {
int i;
pci_read_bridge_bases(bus);
for(i = PCI_BRIDGE_RESOURCES; i < PCI_NUM_RESOURCES; i++) {
if((bus->self->resource[i].flags &
(IORESOURCE_IO | IORESOURCE_MEM)) == 0)
continue;
if(bus->self->resource[i].flags & IORESOURCE_MEM) {
bus->self->resource[i].end = bus->self->resource[i].end - bus->self->resource[i].start + DINO_BRIDGE_ALIGN;
bus->self->resource[i].start = DINO_BRIDGE_ALIGN;
}
DBG("DEBUG %s assigning %d [0x%lx,0x%lx]\n",
dev_name(&bus->self->dev), i,
bus->self->resource[i].start,
bus->self->resource[i].end);
WARN_ON(pci_assign_resource(bus->self, i));
DBG("DEBUG %s after assign %d [0x%lx,0x%lx]\n",
dev_name(&bus->self->dev), i,
bus->self->resource[i].start,
bus->self->resource[i].end);
}
}
list_for_each(ln, &bus->devices) {
dev = pci_dev_b(ln);
if (is_card_dino(&dino_dev->hba.dev->id))
dino_card_fixup(dev);
if ((dev->class >> 8) == PCI_CLASS_BRIDGE_PCI)
continue;
dev->resource[PCI_ROM_RESOURCE].flags = 0;
if(dev->irq == 255) {
#define DINO_FIX_UNASSIGNED_INTERRUPTS
#ifdef DINO_FIX_UNASSIGNED_INTERRUPTS
u32 irq_pin;
dino_cfg_read(dev->bus, dev->devfn,
PCI_INTERRUPT_PIN, 1, &irq_pin);
irq_pin = pci_swizzle_interrupt_pin(dev, irq_pin) - 1;
printk(KERN_WARNING "Device %s has undefined IRQ, "
"setting to %d\n", pci_name(dev), irq_pin);
dino_cfg_write(dev->bus, dev->devfn,
PCI_INTERRUPT_LINE, 1, irq_pin);
dino_assign_irq(dino_dev, irq_pin, &dev->irq);
#else
dev->irq = 65535;
printk(KERN_WARNING "Device %s has unassigned IRQ\n", pci_name(dev));
#endif
} else {
dino_assign_irq(dino_dev, dev->irq, &dev->irq);
}
}
}
static void __init
dino_card_init(struct dino_device *dino_dev)
{
u32 brdg_feat = 0x00784e05;
unsigned long status;
status = __raw_readl(dino_dev->hba.base_addr+DINO_IO_STATUS);
if (status & 0x0000ff80) {
__raw_writel(0x00000005,
dino_dev->hba.base_addr+DINO_IO_COMMAND);
udelay(1);
}
__raw_writel(0x00000000, dino_dev->hba.base_addr+DINO_GMASK);
__raw_writel(0x00000001, dino_dev->hba.base_addr+DINO_IO_FBB_EN);
__raw_writel(0x00000000, dino_dev->hba.base_addr+DINO_ICR);
#if 1
brdg_feat &= ~0x4;
#endif
__raw_writel( brdg_feat, dino_dev->hba.base_addr+DINO_BRDG_FEAT);
__raw_writel(0x00000000, dino_dev->hba.base_addr+DINO_IO_ADDR_EN);
__raw_writel(0x00000000, dino_dev->hba.base_addr+DINO_DAMODE);
__raw_writel(0x00222222, dino_dev->hba.base_addr+DINO_PCIROR);
__raw_writel(0x00222222, dino_dev->hba.base_addr+DINO_PCIWOR);
__raw_writel(0x00000040, dino_dev->hba.base_addr+DINO_MLTIM);
__raw_writel(0x00000080, dino_dev->hba.base_addr+DINO_IO_CONTROL);
__raw_writel(0x0000008c, dino_dev->hba.base_addr+DINO_TLTIM);
__raw_writel(0x0000007e, dino_dev->hba.base_addr+DINO_PAMR);
__raw_writel(0x0000007f, dino_dev->hba.base_addr+DINO_PAPR);
__raw_writel(0x00000000, dino_dev->hba.base_addr+DINO_PAMR);
__raw_writel(0x0000004f, dino_dev->hba.base_addr+DINO_PCICMD);
mdelay(pci_post_reset_delay);
}
static int __init
dino_bridge_init(struct dino_device *dino_dev, const char *name)
{
unsigned long io_addr;
int result, i, count=0;
struct resource *res, *prevres = NULL;
io_addr = __raw_readl(dino_dev->hba.base_addr + DINO_IO_ADDR_EN);
if (io_addr == 0) {
printk(KERN_WARNING "%s: No PCI devices enabled.\n", name);
return -ENODEV;
}
res = &dino_dev->hba.lmmio_space;
for (i = 0; i < 32; i++) {
unsigned long start, end;
if((io_addr & (1 << i)) == 0)
continue;
start = F_EXTEND(0xf0000000UL) | (i << 23);
end = start + 8 * 1024 * 1024 - 1;
DBG("DINO RANGE %d is at 0x%lx-0x%lx\n", count,
start, end);
if(prevres && prevres->end + 1 == start) {
prevres->end = end;
} else {
if(count >= DINO_MAX_LMMIO_RESOURCES) {
printk(KERN_ERR "%s is out of resource windows for range %d (0x%lx-0x%lx)\n", name, count, start, end);
break;
}
prevres = res;
res->start = start;
res->end = end;
res->flags = IORESOURCE_MEM;
res->name = kmalloc(64, GFP_KERNEL);
if(res->name)
snprintf((char *)res->name, 64, "%s LMMIO %d",
name, count);
res++;
count++;
}
}
res = &dino_dev->hba.lmmio_space;
for(i = 0; i < DINO_MAX_LMMIO_RESOURCES; i++) {
if(res[i].flags == 0)
break;
result = ccio_request_resource(dino_dev->hba.dev, &res[i]);
if (result < 0) {
printk(KERN_ERR "%s: failed to claim PCI Bus address "
"space %d (0x%lx-0x%lx)!\n", name, i,
(unsigned long)res[i].start, (unsigned long)res[i].end);
return result;
}
}
return 0;
}
static int __init dino_common_init(struct parisc_device *dev,
struct dino_device *dino_dev, const char *name)
{
int status;
u32 eim;
struct gsc_irq gsc_irq;
struct resource *res;
pcibios_register_hba(&dino_dev->hba);
pci_bios = &dino_bios_ops;
pci_port = &dino_port_ops;
dev->irq = gsc_alloc_irq(&gsc_irq);
dino_dev->txn_addr = gsc_irq.txn_addr;
dino_dev->txn_data = gsc_irq.txn_data;
eim = ((u32) gsc_irq.txn_addr) | gsc_irq.txn_data;
if (dev->irq < 0) {
printk(KERN_WARNING "%s: gsc_alloc_irq() failed\n", name);
return 1;
}
status = request_irq(dev->irq, dino_isr, 0, name, dino_dev);
if (status) {
printk(KERN_WARNING "%s: request_irq() failed with %d\n",
name, status);
return 1;
}
gsc_fixup_irqs(dev, dino_dev, dino_choose_irq);
__raw_writel(eim, dino_dev->hba.base_addr+DINO_IAR0);
__raw_readl(dino_dev->hba.base_addr+DINO_IRR0);
res = &dino_dev->hba.io_space;
if (!is_cujo(&dev->id)) {
res->name = "Dino I/O Port";
} else {
res->name = "Cujo I/O Port";
}
res->start = HBA_PORT_BASE(dino_dev->hba.hba_num);
res->end = res->start + (HBA_PORT_SPACE_SIZE - 1);
res->flags = IORESOURCE_IO;
if (request_resource(&ioport_resource, res) < 0) {
printk(KERN_ERR "%s: request I/O Port region failed "
"0x%lx/%lx (hpa 0x%p)\n",
name, (unsigned long)res->start, (unsigned long)res->end,
dino_dev->hba.base_addr);
return 1;
}
return 0;
}
static int __init dino_probe(struct parisc_device *dev)
{
struct dino_device *dino_dev;
const char *version = "unknown";
char *name;
int is_cujo = 0;
LIST_HEAD(resources);
struct pci_bus *bus;
unsigned long hpa = dev->hpa.start;
int max;
name = "Dino";
if (is_card_dino(&dev->id)) {
version = "3.x (card mode)";
} else {
if (!is_cujo(&dev->id)) {
if (dev->id.hversion_rev < 4) {
version = dino_vers[dev->id.hversion_rev];
}
} else {
name = "Cujo";
is_cujo = 1;
if (dev->id.hversion_rev < 2) {
version = cujo_vers[dev->id.hversion_rev];
}
}
}
printk("%s version %s found at 0x%lx\n", name, version, hpa);
if (!request_mem_region(hpa, PAGE_SIZE, name)) {
printk(KERN_ERR "DINO: Hey! Someone took my MMIO space (0x%ld)!\n",
hpa);
return 1;
}
if (is_cujo && dev->id.hversion_rev == 1) {
#ifdef CONFIG_IOMMU_CCIO
printk(KERN_WARNING "Enabling Cujo 2.0 bug workaround\n");
if (hpa == (unsigned long)CUJO_RAVEN_ADDR) {
ccio_cujo20_fixup(dev, CUJO_RAVEN_BADPAGE);
} else if (hpa == (unsigned long)CUJO_FIREHAWK_ADDR) {
ccio_cujo20_fixup(dev, CUJO_FIREHAWK_BADPAGE);
} else {
printk("Don't recognise Cujo at address 0x%lx, not enabling workaround\n", hpa);
}
#endif
} else if (!is_cujo && !is_card_dino(&dev->id) &&
dev->id.hversion_rev < 3) {
printk(KERN_WARNING
"The GSCtoPCI (Dino hrev %d) bus converter found may exhibit\n"
"data corruption. See Service Note Numbers: A4190A-01, A4191A-01.\n"
"Systems shipped after Aug 20, 1997 will not exhibit this problem.\n"
"Models affected: C180, C160, C160L, B160L, and B132L workstations.\n\n",
dev->id.hversion_rev);
}
dino_dev = kzalloc(sizeof(struct dino_device), GFP_KERNEL);
if (!dino_dev) {
printk("dino_init_chip - couldn't alloc dino_device\n");
return 1;
}
dino_dev->hba.dev = dev;
dino_dev->hba.base_addr = ioremap_nocache(hpa, 4096);
dino_dev->hba.lmmio_space_offset = 0;
spin_lock_init(&dino_dev->dinosaur_pen);
dino_dev->hba.iommu = ccio_get_iommu(dev);
if (is_card_dino(&dev->id)) {
dino_card_init(dino_dev);
} else {
dino_bridge_init(dino_dev, name);
}
if (dino_common_init(dev, dino_dev, name))
return 1;
dev->dev.platform_data = dino_dev;
pci_add_resource_offset(&resources, &dino_dev->hba.io_space,
HBA_PORT_BASE(dino_dev->hba.hba_num));
if (dino_dev->hba.lmmio_space.flags)
pci_add_resource_offset(&resources, &dino_dev->hba.lmmio_space,
dino_dev->hba.lmmio_space_offset);
if (dino_dev->hba.elmmio_space.flags)
pci_add_resource_offset(&resources, &dino_dev->hba.elmmio_space,
dino_dev->hba.lmmio_space_offset);
if (dino_dev->hba.gmmio_space.flags)
pci_add_resource(&resources, &dino_dev->hba.gmmio_space);
dino_dev->hba.bus_num.start = dino_current_bus;
dino_dev->hba.bus_num.end = 255;
dino_dev->hba.bus_num.flags = IORESOURCE_BUS;
pci_add_resource(&resources, &dino_dev->hba.bus_num);
dino_dev->hba.hba_bus = bus = pci_create_root_bus(&dev->dev,
dino_current_bus, &dino_cfg_ops, NULL, &resources);
if (!bus) {
printk(KERN_ERR "ERROR: failed to scan PCI bus on %s (duplicate bus number %d?)\n",
dev_name(&dev->dev), dino_current_bus);
pci_free_resource_list(&resources);
dino_current_bus++;
return 0;
}
max = pci_scan_child_bus(bus);
pci_bus_update_busn_res_end(bus, max);
dino_current_bus = max + 1;
pci_bus_assign_resources(bus);
pci_bus_add_devices(bus);
return 0;
}
int __init dino_init(void)
{
register_parisc_driver(&dino_driver);
return 0;
}
