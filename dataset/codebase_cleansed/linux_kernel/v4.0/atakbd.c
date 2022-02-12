static void atakbd_interrupt(unsigned char scancode, char down)
{
if (scancode < 0x72) {
scancode = atakbd_keycode[scancode];
if (scancode == KEY_CAPSLOCK) {
input_report_key(atakbd_dev, scancode, 1);
input_report_key(atakbd_dev, scancode, 0);
input_sync(atakbd_dev);
} else {
input_report_key(atakbd_dev, scancode, down);
input_sync(atakbd_dev);
}
} else
printk(KERN_INFO "atakbd: unhandled scancode %x\n", scancode);
return;
}
static int __init atakbd_init(void)
{
int i, error;
if (!MACH_IS_ATARI || !ATARIHW_PRESENT(ST_MFP))
return -ENODEV;
error = atari_keyb_init();
if (error)
return error;
atakbd_dev = input_allocate_device();
if (!atakbd_dev)
return -ENOMEM;
atakbd_dev->name = "Atari Keyboard";
atakbd_dev->phys = "atakbd/input0";
atakbd_dev->id.bustype = BUS_HOST;
atakbd_dev->id.vendor = 0x0001;
atakbd_dev->id.product = 0x0001;
atakbd_dev->id.version = 0x0100;
atakbd_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REP);
atakbd_dev->keycode = atakbd_keycode;
atakbd_dev->keycodesize = sizeof(unsigned char);
atakbd_dev->keycodemax = ARRAY_SIZE(atakbd_keycode);
for (i = 1; i < 0x72; i++) {
set_bit(atakbd_keycode[i], atakbd_dev->keybit);
}
error = input_register_device(atakbd_dev);
if (error) {
input_free_device(atakbd_dev);
return error;
}
atari_input_keyboard_interrupt_hook = atakbd_interrupt;
return 0;
}
static void __exit atakbd_exit(void)
{
atari_input_keyboard_interrupt_hook = NULL;
input_unregister_device(atakbd_dev);
}
