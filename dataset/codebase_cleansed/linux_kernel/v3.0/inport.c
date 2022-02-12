static irqreturn_t inport_interrupt(int irq, void *dev_id)
{
unsigned char buttons;
outb(INPORT_REG_MODE, INPORT_CONTROL_PORT);
outb(INPORT_MODE_HOLD | INPORT_MODE_IRQ | INPORT_MODE_BASE, INPORT_DATA_PORT);
outb(INPORT_REG_X, INPORT_CONTROL_PORT);
input_report_rel(inport_dev, REL_X, inb(INPORT_DATA_PORT));
outb(INPORT_REG_Y, INPORT_CONTROL_PORT);
input_report_rel(inport_dev, REL_Y, inb(INPORT_DATA_PORT));
outb(INPORT_REG_BTNS, INPORT_CONTROL_PORT);
buttons = inb(INPORT_DATA_PORT);
input_report_key(inport_dev, BTN_MIDDLE, buttons & 1);
input_report_key(inport_dev, BTN_LEFT, buttons & 2);
input_report_key(inport_dev, BTN_RIGHT, buttons & 4);
outb(INPORT_REG_MODE, INPORT_CONTROL_PORT);
outb(INPORT_MODE_IRQ | INPORT_MODE_BASE, INPORT_DATA_PORT);
input_sync(inport_dev);
return IRQ_HANDLED;
}
static int inport_open(struct input_dev *dev)
{
if (request_irq(inport_irq, inport_interrupt, 0, "inport", NULL))
return -EBUSY;
outb(INPORT_REG_MODE, INPORT_CONTROL_PORT);
outb(INPORT_MODE_IRQ | INPORT_MODE_BASE, INPORT_DATA_PORT);
return 0;
}
static void inport_close(struct input_dev *dev)
{
outb(INPORT_REG_MODE, INPORT_CONTROL_PORT);
outb(INPORT_MODE_BASE, INPORT_DATA_PORT);
free_irq(inport_irq, NULL);
}
static int __init inport_init(void)
{
unsigned char a, b, c;
int err;
if (!request_region(INPORT_BASE, INPORT_EXTENT, "inport")) {
printk(KERN_ERR "inport.c: Can't allocate ports at %#x\n", INPORT_BASE);
return -EBUSY;
}
a = inb(INPORT_SIGNATURE_PORT);
b = inb(INPORT_SIGNATURE_PORT);
c = inb(INPORT_SIGNATURE_PORT);
if (a == b || a != c) {
printk(KERN_INFO "inport.c: Didn't find InPort mouse at %#x\n", INPORT_BASE);
err = -ENODEV;
goto err_release_region;
}
inport_dev = input_allocate_device();
if (!inport_dev) {
printk(KERN_ERR "inport.c: Not enough memory for input device\n");
err = -ENOMEM;
goto err_release_region;
}
inport_dev->name = INPORT_NAME;
inport_dev->phys = "isa023c/input0";
inport_dev->id.bustype = BUS_ISA;
inport_dev->id.vendor = INPORT_VENDOR;
inport_dev->id.product = 0x0001;
inport_dev->id.version = 0x0100;
inport_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REL);
inport_dev->keybit[BIT_WORD(BTN_LEFT)] = BIT_MASK(BTN_LEFT) |
BIT_MASK(BTN_MIDDLE) | BIT_MASK(BTN_RIGHT);
inport_dev->relbit[0] = BIT_MASK(REL_X) | BIT_MASK(REL_Y);
inport_dev->open = inport_open;
inport_dev->close = inport_close;
outb(INPORT_RESET, INPORT_CONTROL_PORT);
outb(INPORT_REG_MODE, INPORT_CONTROL_PORT);
outb(INPORT_MODE_BASE, INPORT_DATA_PORT);
err = input_register_device(inport_dev);
if (err)
goto err_free_dev;
return 0;
err_free_dev:
input_free_device(inport_dev);
err_release_region:
release_region(INPORT_BASE, INPORT_EXTENT);
return err;
}
static void __exit inport_exit(void)
{
input_unregister_device(inport_dev);
release_region(INPORT_BASE, INPORT_EXTENT);
}
