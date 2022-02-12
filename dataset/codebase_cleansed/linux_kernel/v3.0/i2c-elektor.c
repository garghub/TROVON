static void pcf_isa_setbyte(void *data, int ctl, int val)
{
u8 __iomem *address = ctl ? (base_iomem + 1) : base_iomem;
if (ctl && irq && (val & I2C_PCF_ESO)) {
val |= I2C_PCF_ENI;
}
pr_debug("%s: Write %p 0x%02X\n", pcf_isa_ops.name, address, val);
iowrite8(val, address);
#ifdef __alpha__
iowrite8(val, address);
#endif
}
static int pcf_isa_getbyte(void *data, int ctl)
{
u8 __iomem *address = ctl ? (base_iomem + 1) : base_iomem;
int val = ioread8(address);
pr_debug("%s: Read %p 0x%02X\n", pcf_isa_ops.name, address, val);
return (val);
}
static int pcf_isa_getown(void *data)
{
return (own);
}
static int pcf_isa_getclock(void *data)
{
return (clock);
}
static void pcf_isa_waitforpin(void *data)
{
DEFINE_WAIT(wait);
int timeout = 2;
unsigned long flags;
if (irq > 0) {
spin_lock_irqsave(&lock, flags);
if (pcf_pending == 0) {
spin_unlock_irqrestore(&lock, flags);
prepare_to_wait(&pcf_wait, &wait, TASK_INTERRUPTIBLE);
if (schedule_timeout(timeout*HZ)) {
spin_lock_irqsave(&lock, flags);
if (pcf_pending == 1) {
pcf_pending = 0;
}
spin_unlock_irqrestore(&lock, flags);
}
finish_wait(&pcf_wait, &wait);
} else {
pcf_pending = 0;
spin_unlock_irqrestore(&lock, flags);
}
} else {
udelay(100);
}
}
static irqreturn_t pcf_isa_handler(int this_irq, void *dev_id) {
spin_lock(&lock);
pcf_pending = 1;
spin_unlock(&lock);
wake_up_interruptible(&pcf_wait);
return IRQ_HANDLED;
}
static int pcf_isa_init(void)
{
spin_lock_init(&lock);
if (!mmapped) {
if (!request_region(base, 2, pcf_isa_ops.name)) {
printk(KERN_ERR "%s: requested I/O region (%#x:2) is "
"in use\n", pcf_isa_ops.name, base);
return -ENODEV;
}
base_iomem = ioport_map(base, 2);
if (!base_iomem) {
printk(KERN_ERR "%s: remap of I/O region %#x failed\n",
pcf_isa_ops.name, base);
release_region(base, 2);
return -ENODEV;
}
} else {
if (!request_mem_region(base, 2, pcf_isa_ops.name)) {
printk(KERN_ERR "%s: requested memory region (%#x:2) "
"is in use\n", pcf_isa_ops.name, base);
return -ENODEV;
}
base_iomem = ioremap(base, 2);
if (base_iomem == NULL) {
printk(KERN_ERR "%s: remap of memory region %#x "
"failed\n", pcf_isa_ops.name, base);
release_mem_region(base, 2);
return -ENODEV;
}
}
pr_debug("%s: registers %#x remapped to %p\n", pcf_isa_ops.name, base,
base_iomem);
if (irq > 0) {
if (request_irq(irq, pcf_isa_handler, 0, pcf_isa_ops.name,
NULL) < 0) {
printk(KERN_ERR "%s: Request irq%d failed\n",
pcf_isa_ops.name, irq);
irq = 0;
} else
enable_irq(irq);
}
return 0;
}
static int __devinit elektor_match(struct device *dev, unsigned int id)
{
#ifdef __alpha__
if (base == 0) {
struct pci_dev *cy693_dev;
cy693_dev = pci_get_device(PCI_VENDOR_ID_CONTAQ,
PCI_DEVICE_ID_CONTAQ_82C693, NULL);
if (cy693_dev) {
unsigned char config;
if (!pci_read_config_byte(cy693_dev, 0x47, &config)) {
dev_dbg(dev, "found cy82c693, config "
"register 0x47 = 0x%02x\n", config);
if ((config & 0x7f) == 0x61) {
base = 0xe0000;
mmapped = 1;
clock = I2C_PCF_CLK | I2C_PCF_TRNS90;
dev_info(dev, "found API UP2000 like "
"board, will probe PCF8584 "
"later\n");
}
}
pci_dev_put(cy693_dev);
}
}
#endif
if (mmapped && base < 0xc8000) {
dev_err(dev, "incorrect base address (%#x) specified "
"for mmapped I/O\n", base);
return 0;
}
if (base == 0) {
base = DEFAULT_BASE;
}
return 1;
}
static int __devinit elektor_probe(struct device *dev, unsigned int id)
{
init_waitqueue_head(&pcf_wait);
if (pcf_isa_init())
return -ENODEV;
pcf_isa_ops.dev.parent = dev;
if (i2c_pcf_add_bus(&pcf_isa_ops) < 0)
goto fail;
dev_info(dev, "found device at %#x\n", base);
return 0;
fail:
if (irq > 0) {
disable_irq(irq);
free_irq(irq, NULL);
}
if (!mmapped) {
ioport_unmap(base_iomem);
release_region(base, 2);
} else {
iounmap(base_iomem);
release_mem_region(base, 2);
}
return -ENODEV;
}
static int __devexit elektor_remove(struct device *dev, unsigned int id)
{
i2c_del_adapter(&pcf_isa_ops);
if (irq > 0) {
disable_irq(irq);
free_irq(irq, NULL);
}
if (!mmapped) {
ioport_unmap(base_iomem);
release_region(base, 2);
} else {
iounmap(base_iomem);
release_mem_region(base, 2);
}
return 0;
}
static int __init i2c_pcfisa_init(void)
{
return isa_register_driver(&i2c_elektor_driver, 1);
}
static void __exit i2c_pcfisa_exit(void)
{
isa_unregister_driver(&i2c_elektor_driver);
}
