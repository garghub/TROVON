static inline unsigned long eisa_permute(unsigned short port)
{
if (port & 0x300) {
return 0xfc000000 | ((port & 0xfc00) >> 6)
| ((port & 0x3f8) << 9) | (port & 7);
} else {
return 0xfc000000 | port;
}
}
unsigned char eisa_in8(unsigned short port)
{
if (EISA_bus)
return gsc_readb(eisa_permute(port));
return 0xff;
}
unsigned short eisa_in16(unsigned short port)
{
if (EISA_bus)
return le16_to_cpu(gsc_readw(eisa_permute(port)));
return 0xffff;
}
unsigned int eisa_in32(unsigned short port)
{
if (EISA_bus)
return le32_to_cpu(gsc_readl(eisa_permute(port)));
return 0xffffffff;
}
void eisa_out8(unsigned char data, unsigned short port)
{
if (EISA_bus)
gsc_writeb(data, eisa_permute(port));
}
void eisa_out16(unsigned short data, unsigned short port)
{
if (EISA_bus)
gsc_writew(cpu_to_le16(data), eisa_permute(port));
}
void eisa_out32(unsigned int data, unsigned short port)
{
if (EISA_bus)
gsc_writel(cpu_to_le32(data), eisa_permute(port));
}
static void eisa_mask_irq(struct irq_data *d)
{
unsigned int irq = d->irq;
unsigned long flags;
EISA_DBG("disable irq %d\n", irq);
spin_lock_irqsave(&eisa_irq_lock, flags);
if (irq & 8) {
slave_mask |= (1 << (irq&7));
eisa_out8(slave_mask, 0xa1);
} else {
master_mask |= (1 << (irq&7));
eisa_out8(master_mask, 0x21);
}
spin_unlock_irqrestore(&eisa_irq_lock, flags);
EISA_DBG("pic0 mask %02x\n", eisa_in8(0x21));
EISA_DBG("pic1 mask %02x\n", eisa_in8(0xa1));
}
static void eisa_unmask_irq(struct irq_data *d)
{
unsigned int irq = d->irq;
unsigned long flags;
EISA_DBG("enable irq %d\n", irq);
spin_lock_irqsave(&eisa_irq_lock, flags);
if (irq & 8) {
slave_mask &= ~(1 << (irq&7));
eisa_out8(slave_mask, 0xa1);
} else {
master_mask &= ~(1 << (irq&7));
eisa_out8(master_mask, 0x21);
}
spin_unlock_irqrestore(&eisa_irq_lock, flags);
EISA_DBG("pic0 mask %02x\n", eisa_in8(0x21));
EISA_DBG("pic1 mask %02x\n", eisa_in8(0xa1));
}
static irqreturn_t eisa_irq(int wax_irq, void *intr_dev)
{
int irq = gsc_readb(0xfc01f000);
unsigned long flags;
spin_lock_irqsave(&eisa_irq_lock, flags);
eisa_out8(0x0a, 0x20);
eisa_out8(0x0a, 0xa0);
EISA_DBG("irq IAR %02x 8259-1 irr %02x 8259-2 irr %02x\n",
irq, eisa_in8(0x20), eisa_in8(0xa0));
eisa_out8(0x0a, 0x20);
eisa_out8(0x0a, 0xa0);
EISA_DBG("irq 8259-1 isr %02x imr %02x 8259-2 isr %02x imr %02x\n",
eisa_in8(0x20), eisa_in8(0x21), eisa_in8(0xa0), eisa_in8(0xa1));
irq &= 0xf;
if (irq & 8) {
slave_mask |= (1 << (irq&7));
eisa_out8(slave_mask, 0xa1);
eisa_out8(0x60 | (irq&7),0xa0);
eisa_out8(0x62, 0x20);
} else {
master_mask |= (1 << (irq&7));
eisa_out8(master_mask, 0x21);
eisa_out8(0x60|irq, 0x20);
}
spin_unlock_irqrestore(&eisa_irq_lock, flags);
generic_handle_irq(irq);
spin_lock_irqsave(&eisa_irq_lock, flags);
if (irq & 8) {
slave_mask &= ~(1 << (irq&7));
eisa_out8(slave_mask, 0xa1);
} else {
master_mask &= ~(1 << (irq&7));
eisa_out8(master_mask, 0x21);
}
spin_unlock_irqrestore(&eisa_irq_lock, flags);
return IRQ_HANDLED;
}
static irqreturn_t dummy_irq2_handler(int _, void *dev)
{
printk(KERN_ALERT "eisa: uhh, irq2?\n");
return IRQ_HANDLED;
}
static void init_eisa_pic(void)
{
unsigned long flags;
spin_lock_irqsave(&eisa_irq_lock, flags);
eisa_out8(0xff, 0x21);
eisa_out8(0xff, 0xa1);
eisa_out8(0x11, 0x20);
eisa_out8(0x00, 0x21);
eisa_out8(0x04, 0x21);
eisa_out8(0x01, 0x21);
eisa_out8(0x40, 0x20);
eisa_out8(0x11, 0xa0);
eisa_out8(0x08, 0xa1);
eisa_out8(0x02, 0xa1);
eisa_out8(0x01, 0xa1);
eisa_out8(0x40, 0xa0);
udelay(100);
slave_mask = 0xff;
master_mask = 0xfb;
eisa_out8(slave_mask, 0xa1);
eisa_out8(master_mask, 0x21);
EISA_DBG("EISA edge/level %04x\n", eisa_irq_level);
eisa_out8(eisa_irq_level&0xff, 0x4d0);
eisa_out8((eisa_irq_level >> 8) & 0xff, 0x4d1);
EISA_DBG("pic0 mask %02x\n", eisa_in8(0x21));
EISA_DBG("pic1 mask %02x\n", eisa_in8(0xa1));
EISA_DBG("pic0 edge/level %02x\n", eisa_in8(0x4d0));
EISA_DBG("pic1 edge/level %02x\n", eisa_in8(0x4d1));
spin_unlock_irqrestore(&eisa_irq_lock, flags);
}
static int __init eisa_probe(struct parisc_device *dev)
{
int i, result;
char *name = is_mongoose(dev) ? "Mongoose" : "Wax";
printk(KERN_INFO "%s EISA Adapter found at 0x%08lx\n",
name, (unsigned long)dev->hpa.start);
eisa_dev.hba.dev = dev;
eisa_dev.hba.iommu = ccio_get_iommu(dev);
eisa_dev.hba.lmmio_space.name = "EISA";
eisa_dev.hba.lmmio_space.start = F_EXTEND(0xfc000000);
eisa_dev.hba.lmmio_space.end = F_EXTEND(0xffbfffff);
eisa_dev.hba.lmmio_space.flags = IORESOURCE_MEM;
result = ccio_request_resource(dev, &eisa_dev.hba.lmmio_space);
if (result < 0) {
printk(KERN_ERR "EISA: failed to claim EISA Bus address space!\n");
return result;
}
eisa_dev.hba.io_space.name = "EISA";
eisa_dev.hba.io_space.start = 0;
eisa_dev.hba.io_space.end = 0xffff;
eisa_dev.hba.lmmio_space.flags = IORESOURCE_IO;
result = request_resource(&ioport_resource, &eisa_dev.hba.io_space);
if (result < 0) {
printk(KERN_ERR "EISA: failed to claim EISA Bus port space!\n");
return result;
}
pcibios_register_hba(&eisa_dev.hba);
result = request_irq(dev->irq, eisa_irq, IRQF_SHARED, "EISA", &eisa_dev);
if (result) {
printk(KERN_ERR "EISA: request_irq failed!\n");
goto error_release;
}
setup_irq(2, &irq2_action);
for (i = 0; i < 16; i++) {
irq_set_chip_and_handler(i, &eisa_interrupt_type,
handle_simple_irq);
}
EISA_bus = 1;
if (dev->num_addrs) {
eisa_dev.eeprom_addr = dev->addr[0];
} else {
if (is_mongoose(dev)) {
eisa_dev.eeprom_addr = SNAKES_EEPROM_BASE_ADDR;
} else {
eisa_dev.eeprom_addr = MIRAGE_EEPROM_BASE_ADDR;
}
}
eisa_eeprom_addr = ioremap_nocache(eisa_dev.eeprom_addr, HPEE_MAX_LENGTH);
if (!eisa_eeprom_addr) {
result = -ENOMEM;
printk(KERN_ERR "EISA: ioremap_nocache failed!\n");
goto error_free_irq;
}
result = eisa_enumerator(eisa_dev.eeprom_addr, &eisa_dev.hba.io_space,
&eisa_dev.hba.lmmio_space);
init_eisa_pic();
if (result >= 0) {
eisa_dev.root.dev = &dev->dev;
dev_set_drvdata(&dev->dev, &eisa_dev.root);
eisa_dev.root.bus_base_addr = 0;
eisa_dev.root.res = &eisa_dev.hba.io_space;
eisa_dev.root.slots = result;
eisa_dev.root.dma_mask = 0xffffffff;
if (eisa_root_register (&eisa_dev.root)) {
printk(KERN_ERR "EISA: Failed to register EISA root\n");
result = -ENOMEM;
goto error_iounmap;
}
}
return 0;
error_iounmap:
iounmap(eisa_eeprom_addr);
error_free_irq:
free_irq(dev->irq, &eisa_dev);
error_release:
release_resource(&eisa_dev.hba.io_space);
return result;
}
void __init eisa_init(void)
{
register_parisc_driver(&eisa_driver);
}
void eisa_make_irq_level(int num)
{
if (eisa_irq_configured& (1<<num)) {
printk(KERN_WARNING
"IRQ %d polarity configured twice (last to level)\n",
num);
}
eisa_irq_level |= (1<<num);
eisa_irq_configured |= (1<<num);
}
void eisa_make_irq_edge(int num)
{
if (eisa_irq_configured& (1<<num)) {
printk(KERN_WARNING
"IRQ %d polarity configured twice (last to edge)\n",
num);
}
eisa_irq_level &= ~(1<<num);
eisa_irq_configured |= (1<<num);
}
static int __init eisa_irq_setup(char *str)
{
char *cur = str;
int val;
EISA_DBG("IRQ setup\n");
while (cur != NULL) {
char *pe;
val = (int) simple_strtoul(cur, &pe, 0);
if (val > 15 || val < 0) {
printk(KERN_ERR "eisa: EISA irq value are 0-15\n");
continue;
}
if (val == 2) {
val = 9;
}
eisa_make_irq_edge(val);
EISA_DBG("setting IRQ %d to edge-triggered mode\n", val);
if ((cur = strchr(cur, ','))) {
cur++;
} else {
break;
}
}
return 1;
}
