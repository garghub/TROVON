static irqreturn_t ps2_rxint(int irq, void *dev_id)
{
struct ps2if *ps2if = dev_id;
unsigned int scancode, flag, status;
status = sa1111_readl(ps2if->base + SA1111_PS2STAT);
while (status & PS2STAT_RXF) {
if (status & PS2STAT_STP)
sa1111_writel(PS2STAT_STP, ps2if->base + SA1111_PS2STAT);
flag = (status & PS2STAT_STP ? SERIO_FRAME : 0) |
(status & PS2STAT_RXP ? 0 : SERIO_PARITY);
scancode = sa1111_readl(ps2if->base + SA1111_PS2DATA) & 0xff;
if (hweight8(scancode) & 1)
flag ^= SERIO_PARITY;
serio_interrupt(ps2if->io, scancode, flag);
status = sa1111_readl(ps2if->base + SA1111_PS2STAT);
}
return IRQ_HANDLED;
}
static irqreturn_t ps2_txint(int irq, void *dev_id)
{
struct ps2if *ps2if = dev_id;
unsigned int status;
spin_lock(&ps2if->lock);
status = sa1111_readl(ps2if->base + SA1111_PS2STAT);
if (ps2if->head == ps2if->tail) {
disable_irq_nosync(irq);
} else if (status & PS2STAT_TXE) {
sa1111_writel(ps2if->buf[ps2if->tail], ps2if->base + SA1111_PS2DATA);
ps2if->tail = (ps2if->tail + 1) & (sizeof(ps2if->buf) - 1);
}
spin_unlock(&ps2if->lock);
return IRQ_HANDLED;
}
static int ps2_write(struct serio *io, unsigned char val)
{
struct ps2if *ps2if = io->port_data;
unsigned long flags;
unsigned int head;
spin_lock_irqsave(&ps2if->lock, flags);
if (sa1111_readl(ps2if->base + SA1111_PS2STAT) & PS2STAT_TXE) {
sa1111_writel(val, ps2if->base + SA1111_PS2DATA);
} else {
if (ps2if->head == ps2if->tail)
enable_irq(ps2if->dev->irq[1]);
head = (ps2if->head + 1) & (sizeof(ps2if->buf) - 1);
if (head != ps2if->tail) {
ps2if->buf[ps2if->head] = val;
ps2if->head = head;
}
}
spin_unlock_irqrestore(&ps2if->lock, flags);
return 0;
}
static int ps2_open(struct serio *io)
{
struct ps2if *ps2if = io->port_data;
int ret;
sa1111_enable_device(ps2if->dev);
ret = request_irq(ps2if->dev->irq[0], ps2_rxint, 0,
SA1111_DRIVER_NAME(ps2if->dev), ps2if);
if (ret) {
printk(KERN_ERR "sa1111ps2: could not allocate IRQ%d: %d\n",
ps2if->dev->irq[0], ret);
return ret;
}
ret = request_irq(ps2if->dev->irq[1], ps2_txint, 0,
SA1111_DRIVER_NAME(ps2if->dev), ps2if);
if (ret) {
printk(KERN_ERR "sa1111ps2: could not allocate IRQ%d: %d\n",
ps2if->dev->irq[1], ret);
free_irq(ps2if->dev->irq[0], ps2if);
return ret;
}
ps2if->open = 1;
enable_irq_wake(ps2if->dev->irq[0]);
sa1111_writel(PS2CR_ENA, ps2if->base + SA1111_PS2CR);
return 0;
}
static void ps2_close(struct serio *io)
{
struct ps2if *ps2if = io->port_data;
sa1111_writel(0, ps2if->base + SA1111_PS2CR);
disable_irq_wake(ps2if->dev->irq[0]);
ps2if->open = 0;
free_irq(ps2if->dev->irq[1], ps2if);
free_irq(ps2if->dev->irq[0], ps2if);
sa1111_disable_device(ps2if->dev);
}
static void __devinit ps2_clear_input(struct ps2if *ps2if)
{
int maxread = 100;
while (maxread--) {
if ((sa1111_readl(ps2if->base + SA1111_PS2DATA) & 0xff) == 0xff)
break;
}
}
static unsigned int __devinit ps2_test_one(struct ps2if *ps2if,
unsigned int mask)
{
unsigned int val;
sa1111_writel(PS2CR_ENA | mask, ps2if->base + SA1111_PS2CR);
udelay(2);
val = sa1111_readl(ps2if->base + SA1111_PS2STAT);
return val & (PS2STAT_KBC | PS2STAT_KBD);
}
static int __devinit ps2_test(struct ps2if *ps2if)
{
unsigned int stat;
int ret = 0;
stat = ps2_test_one(ps2if, PS2CR_FKC);
if (stat != PS2STAT_KBD) {
printk("PS/2 interface test failed[1]: %02x\n", stat);
ret = -ENODEV;
}
stat = ps2_test_one(ps2if, 0);
if (stat != (PS2STAT_KBC | PS2STAT_KBD)) {
printk("PS/2 interface test failed[2]: %02x\n", stat);
ret = -ENODEV;
}
stat = ps2_test_one(ps2if, PS2CR_FKD);
if (stat != PS2STAT_KBC) {
printk("PS/2 interface test failed[3]: %02x\n", stat);
ret = -ENODEV;
}
sa1111_writel(0, ps2if->base + SA1111_PS2CR);
return ret;
}
static int __devinit ps2_probe(struct sa1111_dev *dev)
{
struct ps2if *ps2if;
struct serio *serio;
int ret;
ps2if = kzalloc(sizeof(struct ps2if), GFP_KERNEL);
serio = kzalloc(sizeof(struct serio), GFP_KERNEL);
if (!ps2if || !serio) {
ret = -ENOMEM;
goto free;
}
serio->id.type = SERIO_8042;
serio->write = ps2_write;
serio->open = ps2_open;
serio->close = ps2_close;
strlcpy(serio->name, dev_name(&dev->dev), sizeof(serio->name));
strlcpy(serio->phys, dev_name(&dev->dev), sizeof(serio->phys));
serio->port_data = ps2if;
serio->dev.parent = &dev->dev;
ps2if->io = serio;
ps2if->dev = dev;
sa1111_set_drvdata(dev, ps2if);
spin_lock_init(&ps2if->lock);
if (!request_mem_region(dev->res.start,
dev->res.end - dev->res.start + 1,
SA1111_DRIVER_NAME(dev))) {
ret = -EBUSY;
goto free;
}
ps2if->base = dev->mapbase;
sa1111_enable_device(ps2if->dev);
sa1111_writel(0, ps2if->base + SA1111_PS2CLKDIV);
sa1111_writel(127, ps2if->base + SA1111_PS2PRECNT);
ps2_clear_input(ps2if);
ret = ps2_test(ps2if);
if (ret)
goto out;
ps2_clear_input(ps2if);
sa1111_disable_device(ps2if->dev);
serio_register_port(ps2if->io);
return 0;
out:
sa1111_disable_device(ps2if->dev);
release_mem_region(dev->res.start, resource_size(&dev->res));
free:
sa1111_set_drvdata(dev, NULL);
kfree(ps2if);
kfree(serio);
return ret;
}
static int __devexit ps2_remove(struct sa1111_dev *dev)
{
struct ps2if *ps2if = sa1111_get_drvdata(dev);
serio_unregister_port(ps2if->io);
release_mem_region(dev->res.start, resource_size(&dev->res));
sa1111_set_drvdata(dev, NULL);
kfree(ps2if);
return 0;
}
static int __init ps2_init(void)
{
return sa1111_driver_register(&ps2_driver);
}
static void __exit ps2_exit(void)
{
sa1111_driver_unregister(&ps2_driver);
}
