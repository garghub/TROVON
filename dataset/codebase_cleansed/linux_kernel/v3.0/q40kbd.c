static irqreturn_t q40kbd_interrupt(int irq, void *dev_id)
{
unsigned long flags;
spin_lock_irqsave(&q40kbd_lock, flags);
if (Q40_IRQ_KEYB_MASK & master_inb(INTERRUPT_REG))
serio_interrupt(q40kbd_port, master_inb(KEYCODE_REG), 0);
master_outb(-1, KEYBOARD_UNLOCK_REG);
spin_unlock_irqrestore(&q40kbd_lock, flags);
return IRQ_HANDLED;
}
static void q40kbd_flush(void)
{
int maxread = 100;
unsigned long flags;
spin_lock_irqsave(&q40kbd_lock, flags);
while (maxread-- && (Q40_IRQ_KEYB_MASK & master_inb(INTERRUPT_REG)))
master_inb(KEYCODE_REG);
spin_unlock_irqrestore(&q40kbd_lock, flags);
}
static int q40kbd_open(struct serio *port)
{
q40kbd_flush();
if (request_irq(Q40_IRQ_KEYBOARD, q40kbd_interrupt, 0, "q40kbd", NULL)) {
printk(KERN_ERR "q40kbd.c: Can't get irq %d.\n", Q40_IRQ_KEYBOARD);
return -EBUSY;
}
master_outb(-1, KEYBOARD_UNLOCK_REG);
master_outb(1, KEY_IRQ_ENABLE_REG);
return 0;
}
static void q40kbd_close(struct serio *port)
{
master_outb(0, KEY_IRQ_ENABLE_REG);
master_outb(-1, KEYBOARD_UNLOCK_REG);
free_irq(Q40_IRQ_KEYBOARD, NULL);
q40kbd_flush();
}
static int __devinit q40kbd_probe(struct platform_device *dev)
{
q40kbd_port = kzalloc(sizeof(struct serio), GFP_KERNEL);
if (!q40kbd_port)
return -ENOMEM;
q40kbd_port->id.type = SERIO_8042;
q40kbd_port->open = q40kbd_open;
q40kbd_port->close = q40kbd_close;
q40kbd_port->dev.parent = &dev->dev;
strlcpy(q40kbd_port->name, "Q40 Kbd Port", sizeof(q40kbd_port->name));
strlcpy(q40kbd_port->phys, "Q40", sizeof(q40kbd_port->phys));
serio_register_port(q40kbd_port);
printk(KERN_INFO "serio: Q40 kbd registered\n");
return 0;
}
static int __devexit q40kbd_remove(struct platform_device *dev)
{
serio_unregister_port(q40kbd_port);
return 0;
}
static int __init q40kbd_init(void)
{
int error;
if (!MACH_IS_Q40)
return -ENODEV;
error = platform_driver_register(&q40kbd_driver);
if (error)
return error;
q40kbd_device = platform_device_alloc("q40kbd", -1);
if (!q40kbd_device)
goto err_unregister_driver;
error = platform_device_add(q40kbd_device);
if (error)
goto err_free_device;
return 0;
err_free_device:
platform_device_put(q40kbd_device);
err_unregister_driver:
platform_driver_unregister(&q40kbd_driver);
return error;
}
static void __exit q40kbd_exit(void)
{
platform_device_unregister(q40kbd_device);
platform_driver_unregister(&q40kbd_driver);
}
