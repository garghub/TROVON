static int rpckbd_write(struct serio *port, unsigned char val)
{
while (!(iomd_readb(IOMD_KCTRL) & (1 << 7)))
cpu_relax();
iomd_writeb(val, IOMD_KARTTX);
return 0;
}
static irqreturn_t rpckbd_rx(int irq, void *dev_id)
{
struct serio *port = dev_id;
unsigned int byte;
int handled = IRQ_NONE;
while (iomd_readb(IOMD_KCTRL) & (1 << 5)) {
byte = iomd_readb(IOMD_KARTRX);
serio_interrupt(port, byte, 0);
handled = IRQ_HANDLED;
}
return handled;
}
static irqreturn_t rpckbd_tx(int irq, void *dev_id)
{
return IRQ_HANDLED;
}
static int rpckbd_open(struct serio *port)
{
iomd_writeb(0, IOMD_KCTRL);
iomd_writeb(8, IOMD_KCTRL);
iomd_readb(IOMD_KARTRX);
if (request_irq(IRQ_KEYBOARDRX, rpckbd_rx, 0, "rpckbd", port) != 0) {
printk(KERN_ERR "rpckbd.c: Could not allocate keyboard receive IRQ\n");
return -EBUSY;
}
if (request_irq(IRQ_KEYBOARDTX, rpckbd_tx, 0, "rpckbd", port) != 0) {
printk(KERN_ERR "rpckbd.c: Could not allocate keyboard transmit IRQ\n");
free_irq(IRQ_KEYBOARDRX, port);
return -EBUSY;
}
return 0;
}
static void rpckbd_close(struct serio *port)
{
free_irq(IRQ_KEYBOARDRX, port);
free_irq(IRQ_KEYBOARDTX, port);
}
static int __devinit rpckbd_probe(struct platform_device *dev)
{
struct serio *serio;
serio = kzalloc(sizeof(struct serio), GFP_KERNEL);
if (!serio)
return -ENOMEM;
serio->id.type = SERIO_8042;
serio->write = rpckbd_write;
serio->open = rpckbd_open;
serio->close = rpckbd_close;
serio->dev.parent = &dev->dev;
strlcpy(serio->name, "RiscPC PS/2 kbd port", sizeof(serio->name));
strlcpy(serio->phys, "rpckbd/serio0", sizeof(serio->phys));
platform_set_drvdata(dev, serio);
serio_register_port(serio);
return 0;
}
static int __devexit rpckbd_remove(struct platform_device *dev)
{
struct serio *serio = platform_get_drvdata(dev);
serio_unregister_port(serio);
return 0;
}
static int __init rpckbd_init(void)
{
return platform_driver_register(&rpckbd_driver);
}
static void __exit rpckbd_exit(void)
{
platform_driver_unregister(&rpckbd_driver);
}
