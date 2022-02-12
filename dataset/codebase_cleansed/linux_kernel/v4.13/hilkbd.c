static void poll_finished(void)
{
int down;
int key;
unsigned char scode;
switch (hil_dev.data[0]) {
case 0x40:
down = (hil_dev.data[1] & 1) == 0;
scode = hil_dev.data[1] >> 1;
key = hphilkeyb_keycode[scode];
input_report_key(hil_dev.dev, key, down);
break;
}
hil_dev.curdev = 0;
}
static inline void handle_status(unsigned char s, unsigned char c)
{
if (c & 0x8) {
if (c & 0x10)
poll_finished();
} else {
if (c & 0x10) {
if (hil_dev.curdev)
poll_finished();
hil_dev.curdev = c & 7;
hil_dev.ptr = 0;
}
}
}
static inline void handle_data(unsigned char s, unsigned char c)
{
if (hil_dev.curdev) {
hil_dev.data[hil_dev.ptr++] = c;
hil_dev.ptr &= 15;
}
}
static irqreturn_t hil_interrupt(int irq, void *handle)
{
unsigned char s, c;
s = hil_status();
c = hil_read_data();
switch (s >> 4) {
case 0x5:
handle_status(s, c);
break;
case 0x6:
handle_data(s, c);
break;
case 0x4:
hil_dev.s = s;
hil_dev.c = c;
mb();
hil_dev.valid = 1;
break;
}
return IRQ_HANDLED;
}
static void hil_do(unsigned char cmd, unsigned char *data, unsigned int len)
{
unsigned long flags;
spin_lock_irqsave(&hil_dev.lock, flags);
while (hil_busy())
;
hil_command(cmd);
while (len--) {
while (hil_busy())
;
hil_write_data(*(data++));
}
spin_unlock_irqrestore(&hil_dev.lock, flags);
}
static int hil_keyb_init(void)
{
unsigned char c;
unsigned int i, kbid;
wait_queue_head_t hil_wait;
int err;
if (hil_dev.dev)
return -ENODEV;
init_waitqueue_head(&hil_wait);
spin_lock_init(&hil_dev.lock);
hil_dev.dev = input_allocate_device();
if (!hil_dev.dev)
return -ENOMEM;
err = request_irq(HIL_IRQ, hil_interrupt, 0, "hil", hil_dev.dev_id);
if (err) {
printk(KERN_ERR "HIL: Can't get IRQ\n");
goto err1;
}
hil_do(HIL_INTON, NULL, 0);
hil_dev.valid = 0;
hil_do(HIL_READKBDSADR, NULL, 0);
wait_event_interruptible_timeout(hil_wait, hil_dev.valid, 3 * HZ);
if (!hil_dev.valid)
printk(KERN_WARNING "HIL: timed out, assuming no keyboard present\n");
c = hil_dev.c;
hil_dev.valid = 0;
if (c == 0) {
kbid = -1;
printk(KERN_WARNING "HIL: no keyboard present\n");
} else {
kbid = ffz(~c);
printk(KERN_INFO "HIL: keyboard found at id %d\n", kbid);
}
c = 0;
hil_do(HIL_WRITEKBDSADR, &c, 1);
for (i = 0; i < HIL_KEYCODES_SET1_TBLSIZE; i++)
if (hphilkeyb_keycode[i] != KEY_RESERVED)
__set_bit(hphilkeyb_keycode[i], hil_dev.dev->keybit);
hil_dev.dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REP);
hil_dev.dev->ledbit[0] = BIT_MASK(LED_NUML) | BIT_MASK(LED_CAPSL) |
BIT_MASK(LED_SCROLLL);
hil_dev.dev->keycodemax = HIL_KEYCODES_SET1_TBLSIZE;
hil_dev.dev->keycodesize= sizeof(hphilkeyb_keycode[0]);
hil_dev.dev->keycode = hphilkeyb_keycode;
hil_dev.dev->name = "HIL keyboard";
hil_dev.dev->phys = "hpkbd/input0";
hil_dev.dev->id.bustype = BUS_HIL;
hil_dev.dev->id.vendor = PCI_VENDOR_ID_HP;
hil_dev.dev->id.product = 0x0001;
hil_dev.dev->id.version = 0x0010;
err = input_register_device(hil_dev.dev);
if (err) {
printk(KERN_ERR "HIL: Can't register device\n");
goto err2;
}
printk(KERN_INFO "input: %s, ID %d at 0x%08lx (irq %d) found and attached\n",
hil_dev.dev->name, kbid, HILBASE, HIL_IRQ);
return 0;
err2:
hil_do(HIL_INTOFF, NULL, 0);
free_irq(HIL_IRQ, hil_dev.dev_id);
err1:
input_free_device(hil_dev.dev);
hil_dev.dev = NULL;
return err;
}
static void hil_keyb_exit(void)
{
if (HIL_IRQ)
free_irq(HIL_IRQ, hil_dev.dev_id);
hil_do(HIL_INTOFF, NULL, 0);
input_unregister_device(hil_dev.dev);
hil_dev.dev = NULL;
}
static int hil_probe_chip(struct parisc_device *dev)
{
if (hil_dev.dev)
return -ENODEV;
if (!dev->irq) {
printk(KERN_WARNING "HIL: IRQ not found for HIL bus at 0x%p\n",
(void *)dev->hpa.start);
return -ENODEV;
}
hil_base = dev->hpa.start;
hil_irq = dev->irq;
hil_dev.dev_id = dev;
printk(KERN_INFO "Found HIL bus at 0x%08lx, IRQ %d\n", hil_base, hil_irq);
return hil_keyb_init();
}
static int hil_remove_chip(struct parisc_device *dev)
{
hil_keyb_exit();
return 0;
}
static int __init hil_init(void)
{
return register_parisc_driver(&hil_driver);
}
static void __exit hil_exit(void)
{
unregister_parisc_driver(&hil_driver);
}
static int __init hil_init(void)
{
int error;
if (hil_dev.dev)
return -EBUSY;
if (!MACH_IS_HP300)
return -ENODEV;
if (!hwreg_present((void *)(HILBASE + HIL_DATA))) {
printk(KERN_ERR "HIL: hardware register was not found\n");
return -ENODEV;
}
if (!request_region(HILBASE + HIL_DATA, 2, "hil")) {
printk(KERN_ERR "HIL: IOPORT region already used\n");
return -EIO;
}
error = hil_keyb_init();
if (error) {
release_region(HILBASE + HIL_DATA, 2);
return error;
}
return 0;
}
static void __exit hil_exit(void)
{
hil_keyb_exit();
release_region(HILBASE + HIL_DATA, 2);
}
