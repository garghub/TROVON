static irqreturn_t mk712_interrupt(int irq, void *dev_id)
{
unsigned char status;
static int debounce = 1;
static unsigned short last_x;
static unsigned short last_y;
spin_lock(&mk712_lock);
status = inb(mk712_io + MK712_STATUS);
if (~status & MK712_CONVERSION_COMPLETE) {
debounce = 1;
goto end;
}
if (~status & MK712_STATUS_TOUCH) {
debounce = 1;
input_report_key(mk712_dev, BTN_TOUCH, 0);
goto end;
}
if (debounce) {
debounce = 0;
goto end;
}
input_report_key(mk712_dev, BTN_TOUCH, 1);
input_report_abs(mk712_dev, ABS_X, last_x);
input_report_abs(mk712_dev, ABS_Y, last_y);
end:
last_x = inw(mk712_io + MK712_X) & 0x0fff;
last_y = inw(mk712_io + MK712_Y) & 0x0fff;
input_sync(mk712_dev);
spin_unlock(&mk712_lock);
return IRQ_HANDLED;
}
static int mk712_open(struct input_dev *dev)
{
unsigned long flags;
spin_lock_irqsave(&mk712_lock, flags);
outb(0, mk712_io + MK712_CONTROL);
outb(MK712_ENABLE_INT | MK712_INT_ON_CONVERSION_COMPLETE |
MK712_INT_ON_CHANGE_IN_TOUCH_STATUS |
MK712_ENABLE_PERIODIC_CONVERSIONS |
MK712_POWERUP, mk712_io + MK712_CONTROL);
outb(10, mk712_io + MK712_RATE);
spin_unlock_irqrestore(&mk712_lock, flags);
return 0;
}
static void mk712_close(struct input_dev *dev)
{
unsigned long flags;
spin_lock_irqsave(&mk712_lock, flags);
outb(0, mk712_io + MK712_CONTROL);
spin_unlock_irqrestore(&mk712_lock, flags);
}
static int __init mk712_init(void)
{
int err;
if (!request_region(mk712_io, 8, "mk712")) {
printk(KERN_WARNING "mk712: unable to get IO region\n");
return -ENODEV;
}
outb(0, mk712_io + MK712_CONTROL);
if ((inw(mk712_io + MK712_X) & 0xf000) ||
(inw(mk712_io + MK712_Y) & 0xf000) ||
(inw(mk712_io + MK712_STATUS) & 0xf333)) {
printk(KERN_WARNING "mk712: device not present\n");
err = -ENODEV;
goto fail1;
}
mk712_dev = input_allocate_device();
if (!mk712_dev) {
printk(KERN_ERR "mk712: not enough memory\n");
err = -ENOMEM;
goto fail1;
}
mk712_dev->name = "ICS MicroClock MK712 TouchScreen";
mk712_dev->phys = "isa0260/input0";
mk712_dev->id.bustype = BUS_ISA;
mk712_dev->id.vendor = 0x0005;
mk712_dev->id.product = 0x0001;
mk712_dev->id.version = 0x0100;
mk712_dev->open = mk712_open;
mk712_dev->close = mk712_close;
mk712_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
mk712_dev->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
input_set_abs_params(mk712_dev, ABS_X, 0, 0xfff, 88, 0);
input_set_abs_params(mk712_dev, ABS_Y, 0, 0xfff, 88, 0);
if (request_irq(mk712_irq, mk712_interrupt, 0, "mk712", mk712_dev)) {
printk(KERN_WARNING "mk712: unable to get IRQ\n");
err = -EBUSY;
goto fail1;
}
err = input_register_device(mk712_dev);
if (err)
goto fail2;
return 0;
fail2: free_irq(mk712_irq, mk712_dev);
fail1: input_free_device(mk712_dev);
release_region(mk712_io, 8);
return err;
}
static void __exit mk712_exit(void)
{
input_unregister_device(mk712_dev);
free_irq(mk712_irq, mk712_dev);
release_region(mk712_io, 8);
}
