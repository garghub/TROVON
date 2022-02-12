static void dc_scan_kbd(struct dc_kbd *kbd)
{
struct input_dev *dev = kbd->dev;
void *ptr;
int code, keycode;
int i;
for (i = 0; i < 8; i++) {
code = i + 224;
keycode = kbd->keycode[code];
input_event(dev, EV_MSC, MSC_SCAN, code);
input_report_key(dev, keycode, (kbd->new[0] >> i) & 1);
}
for (i = 2; i < 8; i++) {
ptr = memchr(kbd->new + 2, kbd->old[i], 6);
code = kbd->old[i];
if (code > 3 && ptr == NULL) {
keycode = kbd->keycode[code];
if (keycode) {
input_event(dev, EV_MSC, MSC_SCAN, code);
input_report_key(dev, keycode, 0);
} else
dev_dbg(&dev->dev,
"Unknown key (scancode %#x) released.",
code);
}
ptr = memchr(kbd->old + 2, kbd->new[i], 6);
code = kbd->new[i];
if (code > 3 && ptr) {
keycode = kbd->keycode[code];
if (keycode) {
input_event(dev, EV_MSC, MSC_SCAN, code);
input_report_key(dev, keycode, 1);
} else
dev_dbg(&dev->dev,
"Unknown key (scancode %#x) pressed.",
code);
}
}
input_sync(dev);
memcpy(kbd->old, kbd->new, 8);
}
static void dc_kbd_callback(struct mapleq *mq)
{
struct maple_device *mapledev = mq->dev;
struct dc_kbd *kbd = maple_get_drvdata(mapledev);
unsigned long *buf = (unsigned long *)(mq->recvbuf->buf);
if (likely(mutex_trylock(&maple_keyb_mutex))) {
if (buf[1] == mapledev->function) {
memcpy(kbd->new, buf + 2, 8);
dc_scan_kbd(kbd);
}
mutex_unlock(&maple_keyb_mutex);
}
}
static int probe_maple_kbd(struct device *dev)
{
struct maple_device *mdev;
struct maple_driver *mdrv;
int i, error;
struct dc_kbd *kbd;
struct input_dev *idev;
mdev = to_maple_dev(dev);
mdrv = to_maple_driver(dev->driver);
kbd = kzalloc(sizeof(struct dc_kbd), GFP_KERNEL);
if (!kbd) {
error = -ENOMEM;
goto fail;
}
idev = input_allocate_device();
if (!idev) {
error = -ENOMEM;
goto fail_idev_alloc;
}
kbd->dev = idev;
memcpy(kbd->keycode, dc_kbd_keycode, sizeof(kbd->keycode));
idev->name = mdev->product_name;
idev->evbit[0] = BIT(EV_KEY) | BIT(EV_REP);
idev->keycode = kbd->keycode;
idev->keycodesize = sizeof(unsigned short);
idev->keycodemax = ARRAY_SIZE(kbd->keycode);
idev->id.bustype = BUS_HOST;
idev->dev.parent = &mdev->dev;
for (i = 0; i < NR_SCANCODES; i++)
__set_bit(dc_kbd_keycode[i], idev->keybit);
__clear_bit(KEY_RESERVED, idev->keybit);
input_set_capability(idev, EV_MSC, MSC_SCAN);
input_set_drvdata(idev, kbd);
error = input_register_device(idev);
if (error)
goto fail_register;
maple_getcond_callback(mdev, dc_kbd_callback, HZ/50,
MAPLE_FUNC_KEYBOARD);
mdev->driver = mdrv;
maple_set_drvdata(mdev, kbd);
return error;
fail_register:
maple_set_drvdata(mdev, NULL);
input_free_device(idev);
fail_idev_alloc:
kfree(kbd);
fail:
return error;
}
static int remove_maple_kbd(struct device *dev)
{
struct maple_device *mdev = to_maple_dev(dev);
struct dc_kbd *kbd = maple_get_drvdata(mdev);
mutex_lock(&maple_keyb_mutex);
input_unregister_device(kbd->dev);
kfree(kbd);
maple_set_drvdata(mdev, NULL);
mutex_unlock(&maple_keyb_mutex);
return 0;
}
static int __init dc_kbd_init(void)
{
return maple_driver_register(&dc_kbd_driver);
}
static void __exit dc_kbd_exit(void)
{
maple_driver_unregister(&dc_kbd_driver);
}
