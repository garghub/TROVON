static void pca_isa_writebyte(void *pd, int reg, int val)
{
#ifdef DEBUG_IO
static char *names[] = { "T/O", "DAT", "ADR", "CON" };
printk(KERN_DEBUG "*** write %s at %#lx <= %#04x\n", names[reg],
base+reg, val);
#endif
outb(val, base+reg);
}
static int pca_isa_readbyte(void *pd, int reg)
{
int res = inb(base+reg);
#ifdef DEBUG_IO
{
static char *names[] = { "STA", "DAT", "ADR", "CON" };
printk(KERN_DEBUG "*** read %s => %#04x\n", names[reg], res);
}
#endif
return res;
}
static int pca_isa_waitforcompletion(void *pd)
{
unsigned long timeout;
long ret;
if (irq > -1) {
ret = wait_event_timeout(pca_wait,
pca_isa_readbyte(pd, I2C_PCA_CON)
& I2C_PCA_CON_SI, pca_isa_ops.timeout);
} else {
timeout = jiffies + pca_isa_ops.timeout;
do {
ret = time_before(jiffies, timeout);
if (pca_isa_readbyte(pd, I2C_PCA_CON)
& I2C_PCA_CON_SI)
break;
udelay(100);
} while (ret);
}
return ret > 0;
}
static void pca_isa_resetchip(void *pd)
{
printk(KERN_WARNING DRIVER ": Haven't figured out how to do a reset yet\n");
}
static irqreturn_t pca_handler(int this_irq, void *dev_id) {
wake_up(&pca_wait);
return IRQ_HANDLED;
}
static int pca_isa_match(struct device *dev, unsigned int id)
{
int match = base != 0;
if (match) {
if (irq <= -1)
dev_warn(dev, "Using polling mode (specify irq)\n");
} else
dev_err(dev, "Please specify I/O base\n");
return match;
}
static int pca_isa_probe(struct device *dev, unsigned int id)
{
init_waitqueue_head(&pca_wait);
dev_info(dev, "i/o base %#08lx. irq %d\n", base, irq);
#ifdef CONFIG_PPC
if (check_legacy_ioport(base)) {
dev_err(dev, "I/O address %#08lx is not available\n", base);
goto out;
}
#endif
if (!request_region(base, IO_SIZE, "i2c-pca-isa")) {
dev_err(dev, "I/O address %#08lx is in use\n", base);
goto out;
}
if (irq > -1) {
if (request_irq(irq, pca_handler, 0, "i2c-pca-isa", &pca_isa_ops) < 0) {
dev_err(dev, "Request irq%d failed\n", irq);
goto out_region;
}
}
pca_isa_data.i2c_clock = clock;
if (i2c_pca_add_bus(&pca_isa_ops) < 0) {
dev_err(dev, "Failed to add i2c bus\n");
goto out_irq;
}
return 0;
out_irq:
if (irq > -1)
free_irq(irq, &pca_isa_ops);
out_region:
release_region(base, IO_SIZE);
out:
return -ENODEV;
}
static int pca_isa_remove(struct device *dev, unsigned int id)
{
i2c_del_adapter(&pca_isa_ops);
if (irq > -1) {
disable_irq(irq);
free_irq(irq, &pca_isa_ops);
}
release_region(base, IO_SIZE);
return 0;
}
static int __init pca_isa_init(void)
{
return isa_register_driver(&pca_isa_driver, 1);
}
static void __exit pca_isa_exit(void)
{
isa_unregister_driver(&pca_isa_driver);
}
