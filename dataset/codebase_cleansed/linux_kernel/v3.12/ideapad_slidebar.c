static u8 slidebar_pos_get(void)
{
u8 res;
unsigned long flags;
spin_lock_irqsave(&io_lock, flags);
outb(0xf4, 0xff29);
outb(0xbf, 0xff2a);
res = inb(0xff2b);
spin_unlock_irqrestore(&io_lock, flags);
return res;
}
static u8 slidebar_mode_get(void)
{
u8 res;
unsigned long flags;
spin_lock_irqsave(&io_lock, flags);
outb(0xf7, 0xff29);
outb(0x8b, 0xff2a);
res = inb(0xff2b);
spin_unlock_irqrestore(&io_lock, flags);
return res;
}
static void slidebar_mode_set(u8 mode)
{
unsigned long flags;
spin_lock_irqsave(&io_lock, flags);
outb(0xf7, 0xff29);
outb(0x8b, 0xff2a);
outb(mode, 0xff2b);
spin_unlock_irqrestore(&io_lock, flags);
}
static bool slidebar_i8042_filter(unsigned char data, unsigned char str,
struct serio *port)
{
static bool extended = false;
if (str & I8042_STR_AUXDATA)
return false;
if (data == 0xe0) {
extended = true;
return true;
}
if (!extended)
return false;
extended = false;
if (likely((data & 0x7f) != 0x3b)) {
serio_interrupt(port, 0xe0, 0);
return false;
}
if (data & 0x80) {
input_report_key(slidebar_input_dev, BTN_TOUCH, 0);
} else {
input_report_key(slidebar_input_dev, BTN_TOUCH, 1);
input_report_abs(slidebar_input_dev, ABS_X, slidebar_pos_get());
}
input_sync(slidebar_input_dev);
return true;
}
static ssize_t show_slidebar_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
return sprintf(buf, "%x\n", slidebar_mode_get());
}
static ssize_t store_slidebar_mode(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
u8 mode;
int error;
error = kstrtou8(buf, 0, &mode);
if (error)
return error;
slidebar_mode_set(mode);
return count;
}
static int __init ideapad_probe(struct platform_device* pdev)
{
int err;
if (!request_region(IDEAPAD_BASE, 3, "ideapad_slidebar")) {
dev_err(&pdev->dev, "IO ports are busy\n");
return -EBUSY;
}
slidebar_input_dev = input_allocate_device();
if (!slidebar_input_dev) {
dev_err(&pdev->dev, "Failed to allocate input device\n");
err = -ENOMEM;
goto err_release_ports;
}
slidebar_input_dev->name = "IdeaPad Slidebar";
slidebar_input_dev->id.bustype = BUS_HOST;
slidebar_input_dev->dev.parent = &pdev->dev;
input_set_capability(slidebar_input_dev, EV_KEY, BTN_TOUCH);
input_set_capability(slidebar_input_dev, EV_ABS, ABS_X);
input_set_abs_params(slidebar_input_dev, ABS_X, 0, 0xff, 0, 0);
err = i8042_install_filter(slidebar_i8042_filter);
if (err) {
dev_err(&pdev->dev,
"Failed to install i8042 filter: %d\n", err);
goto err_free_dev;
}
err = input_register_device(slidebar_input_dev);
if (err) {
dev_err(&pdev->dev,
"Failed to register input device: %d\n", err);
goto err_remove_filter;
}
return 0;
err_remove_filter:
i8042_remove_filter(slidebar_i8042_filter);
err_free_dev:
input_free_device(slidebar_input_dev);
err_release_ports:
release_region(IDEAPAD_BASE, 3);
return err;
}
static int ideapad_remove(struct platform_device *pdev)
{
i8042_remove_filter(slidebar_i8042_filter);
input_unregister_device(slidebar_input_dev);
release_region(IDEAPAD_BASE, 3);
return 0;
}
static int __init ideapad_dmi_check(const struct dmi_system_id *id)
{
pr_info("Laptop model '%s'\n", id->ident);
return 1;
}
static int __init slidebar_init(void)
{
int err;
if (!force && !dmi_check_system(ideapad_dmi)) {
pr_err("DMI does not match\n");
return -ENODEV;
}
slidebar_platform_dev = platform_device_alloc("ideapad_slidebar", -1);
if (!slidebar_platform_dev) {
pr_err("Not enough memory\n");
return -ENOMEM;
}
slidebar_platform_dev->dev.groups = ideapad_attr_groups;
err = platform_device_add(slidebar_platform_dev);
if (err) {
pr_err("Failed to register platform device\n");
goto err_free_dev;
}
err = platform_driver_probe(&slidebar_drv, ideapad_probe);
if (err) {
pr_err("Failed to register platform driver\n");
goto err_delete_dev;
}
return 0;
err_delete_dev:
platform_device_del(slidebar_platform_dev);
err_free_dev:
platform_device_put(slidebar_platform_dev);
return err;
}
static void __exit slidebar_exit(void)
{
platform_device_unregister(slidebar_platform_dev);
platform_driver_unregister(&slidebar_drv);
}
