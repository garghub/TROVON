static inline void locomokbd_charge_all(unsigned long membase)
{
locomo_writel(0x00FF, membase + LOCOMO_KSC);
}
static inline void locomokbd_activate_all(unsigned long membase)
{
unsigned long r;
locomo_writel(0, membase + LOCOMO_KSC);
r = locomo_readl(membase + LOCOMO_KIC);
r &= 0xFEFF;
locomo_writel(r, membase + LOCOMO_KIC);
}
static inline void locomokbd_activate_col(unsigned long membase, int col)
{
unsigned short nset;
unsigned short nbset;
nset = 0xFF & ~(1 << col);
nbset = (nset << 8) + nset;
locomo_writel(nbset, membase + LOCOMO_KSC);
}
static inline void locomokbd_reset_col(unsigned long membase, int col)
{
unsigned short nbset;
nbset = ((0xFF & ~(1 << col)) << 8) + 0xFF;
locomo_writel(nbset, membase + LOCOMO_KSC);
}
static void locomokbd_scankeyboard(struct locomokbd *locomokbd)
{
unsigned int row, col, rowd;
unsigned long flags;
unsigned int num_pressed;
unsigned long membase = locomokbd->base;
spin_lock_irqsave(&locomokbd->lock, flags);
locomokbd_charge_all(membase);
num_pressed = 0;
for (col = 0; col < KB_COLS; col++) {
locomokbd_activate_col(membase, col);
udelay(KB_DELAY);
rowd = ~locomo_readl(membase + LOCOMO_KIB);
for (row = 0; row < KB_ROWS; row++) {
unsigned int scancode, pressed, key;
scancode = SCANCODE(col, row);
pressed = rowd & KB_ROWMASK(row);
key = locomokbd->keycode[scancode];
input_report_key(locomokbd->input, key, pressed);
if (likely(!pressed))
continue;
num_pressed++;
if (unlikely(key == KEY_ESC)) {
if (!time_after(jiffies,
locomokbd->suspend_jiffies + HZ))
continue;
if (locomokbd->count_cancel++
!= (HZ/SCAN_INTERVAL + 1))
continue;
input_event(locomokbd->input, EV_PWR,
KEY_SUSPEND, 1);
locomokbd->suspend_jiffies = jiffies;
} else
locomokbd->count_cancel = 0;
}
locomokbd_reset_col(membase, col);
}
locomokbd_activate_all(membase);
input_sync(locomokbd->input);
if (num_pressed)
mod_timer(&locomokbd->timer, jiffies + SCAN_INTERVAL);
else
locomokbd->count_cancel = 0;
spin_unlock_irqrestore(&locomokbd->lock, flags);
}
static irqreturn_t locomokbd_interrupt(int irq, void *dev_id)
{
struct locomokbd *locomokbd = dev_id;
u16 r;
r = locomo_readl(locomokbd->base + LOCOMO_KIC);
if ((r & 0x0001) == 0)
return IRQ_HANDLED;
locomo_writel(r & ~0x0100, locomokbd->base + LOCOMO_KIC);
udelay(100);
locomokbd_scankeyboard(locomokbd);
return IRQ_HANDLED;
}
static void locomokbd_timer_callback(unsigned long data)
{
struct locomokbd *locomokbd = (struct locomokbd *) data;
locomokbd_scankeyboard(locomokbd);
}
static int locomokbd_open(struct input_dev *dev)
{
struct locomokbd *locomokbd = input_get_drvdata(dev);
u16 r;
r = locomo_readl(locomokbd->base + LOCOMO_KIC) | 0x0010;
locomo_writel(r, locomokbd->base + LOCOMO_KIC);
return 0;
}
static void locomokbd_close(struct input_dev *dev)
{
struct locomokbd *locomokbd = input_get_drvdata(dev);
u16 r;
r = locomo_readl(locomokbd->base + LOCOMO_KIC) & ~0x0010;
locomo_writel(r, locomokbd->base + LOCOMO_KIC);
}
static int locomokbd_probe(struct locomo_dev *dev)
{
struct locomokbd *locomokbd;
struct input_dev *input_dev;
int i, err;
locomokbd = kzalloc(sizeof(struct locomokbd), GFP_KERNEL);
input_dev = input_allocate_device();
if (!locomokbd || !input_dev) {
err = -ENOMEM;
goto err_free_mem;
}
if (!request_mem_region((unsigned long) dev->mapbase,
dev->length,
LOCOMO_DRIVER_NAME(dev))) {
err = -EBUSY;
printk(KERN_ERR "locomokbd: Can't acquire access to io memory for keyboard\n");
goto err_free_mem;
}
locomo_set_drvdata(dev, locomokbd);
locomokbd->base = (unsigned long) dev->mapbase;
spin_lock_init(&locomokbd->lock);
init_timer(&locomokbd->timer);
locomokbd->timer.function = locomokbd_timer_callback;
locomokbd->timer.data = (unsigned long) locomokbd;
locomokbd->suspend_jiffies = jiffies;
locomokbd->input = input_dev;
strcpy(locomokbd->phys, "locomokbd/input0");
input_dev->name = "LoCoMo keyboard";
input_dev->phys = locomokbd->phys;
input_dev->id.bustype = BUS_HOST;
input_dev->id.vendor = 0x0001;
input_dev->id.product = 0x0001;
input_dev->id.version = 0x0100;
input_dev->open = locomokbd_open;
input_dev->close = locomokbd_close;
input_dev->dev.parent = &dev->dev;
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REP) |
BIT_MASK(EV_PWR);
input_dev->keycode = locomokbd->keycode;
input_dev->keycodesize = sizeof(locomokbd_keycode[0]);
input_dev->keycodemax = ARRAY_SIZE(locomokbd_keycode);
input_set_drvdata(input_dev, locomokbd);
memcpy(locomokbd->keycode, locomokbd_keycode, sizeof(locomokbd->keycode));
for (i = 0; i < LOCOMOKBD_NUMKEYS; i++)
set_bit(locomokbd->keycode[i], input_dev->keybit);
clear_bit(0, input_dev->keybit);
err = request_irq(dev->irq[0], locomokbd_interrupt, 0, "locomokbd", locomokbd);
if (err) {
printk(KERN_ERR "locomokbd: Can't get irq for keyboard\n");
goto err_release_region;
}
err = input_register_device(locomokbd->input);
if (err)
goto err_free_irq;
return 0;
err_free_irq:
free_irq(dev->irq[0], locomokbd);
err_release_region:
release_mem_region((unsigned long) dev->mapbase, dev->length);
locomo_set_drvdata(dev, NULL);
err_free_mem:
input_free_device(input_dev);
kfree(locomokbd);
return err;
}
static int locomokbd_remove(struct locomo_dev *dev)
{
struct locomokbd *locomokbd = locomo_get_drvdata(dev);
free_irq(dev->irq[0], locomokbd);
del_timer_sync(&locomokbd->timer);
input_unregister_device(locomokbd->input);
locomo_set_drvdata(dev, NULL);
release_mem_region((unsigned long) dev->mapbase, dev->length);
kfree(locomokbd);
return 0;
}
static int __init locomokbd_init(void)
{
return locomo_driver_register(&keyboard_driver);
}
static void __exit locomokbd_exit(void)
{
locomo_driver_unregister(&keyboard_driver);
}
