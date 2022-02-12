static void call_bios(struct regs *regs)
{
unsigned long flags;
preempt_disable();
local_irq_save(flags);
asm volatile ("pushl %%ebp;"
"movl %7, %%ebp;"
"call *%6;"
"popl %%ebp"
: "=a" (regs->eax), "=b" (regs->ebx), "=c" (regs->ecx)
: "0" (regs->eax), "1" (regs->ebx), "2" (regs->ecx),
"m" (bios_entry_point), "m" (bios_data_map_base)
: "edx", "edi", "esi", "memory");
local_irq_restore(flags);
preempt_enable();
}
static ssize_t __init locate_wistron_bios(void __iomem *base)
{
static unsigned char __initdata signature[] =
{ 0x42, 0x21, 0x55, 0x30 };
ssize_t offset;
for (offset = 0; offset < 0x10000; offset += 0x10) {
if (check_signature(base + offset, signature,
sizeof(signature)) != 0)
return offset;
}
return -1;
}
static int __init map_bios(void)
{
void __iomem *base;
ssize_t offset;
u32 entry_point;
base = ioremap(0xF0000, 0x10000);
offset = locate_wistron_bios(base);
if (offset < 0) {
printk(KERN_ERR "wistron_btns: BIOS entry point not found\n");
iounmap(base);
return -ENODEV;
}
entry_point = readl(base + offset + 5);
printk(KERN_DEBUG
"wistron_btns: BIOS signature found at %p, entry point %08X\n",
base + offset, entry_point);
if (entry_point >= 0xF0000) {
bios_code_map_base = base;
bios_entry_point = bios_code_map_base + (entry_point & 0xFFFF);
} else {
iounmap(base);
bios_code_map_base = ioremap(entry_point & ~0x3FFF, 0x4000);
if (bios_code_map_base == NULL) {
printk(KERN_ERR
"wistron_btns: Can't map BIOS code at %08X\n",
entry_point & ~0x3FFF);
goto err;
}
bios_entry_point = bios_code_map_base + (entry_point & 0x3FFF);
}
bios_data_map_base = ioremap(0x400, 0xc00);
if (bios_data_map_base == NULL) {
printk(KERN_ERR "wistron_btns: Can't map BIOS data\n");
goto err_code;
}
return 0;
err_code:
iounmap(bios_code_map_base);
err:
return -ENOMEM;
}
static inline void unmap_bios(void)
{
iounmap(bios_code_map_base);
iounmap(bios_data_map_base);
}
static u16 bios_pop_queue(void)
{
struct regs regs;
memset(&regs, 0, sizeof (regs));
regs.eax = 0x9610;
regs.ebx = 0x061C;
regs.ecx = 0x0000;
call_bios(&regs);
return regs.eax;
}
static void bios_attach(void)
{
struct regs regs;
memset(&regs, 0, sizeof (regs));
regs.eax = 0x9610;
regs.ebx = 0x012E;
call_bios(&regs);
}
static void bios_detach(void)
{
struct regs regs;
memset(&regs, 0, sizeof (regs));
regs.eax = 0x9610;
regs.ebx = 0x002E;
call_bios(&regs);
}
static u8 bios_get_cmos_address(void)
{
struct regs regs;
memset(&regs, 0, sizeof (regs));
regs.eax = 0x9610;
regs.ebx = 0x051C;
call_bios(&regs);
return regs.ecx;
}
static u16 bios_get_default_setting(u8 subsys)
{
struct regs regs;
memset(&regs, 0, sizeof (regs));
regs.eax = 0x9610;
regs.ebx = 0x0200 | subsys;
call_bios(&regs);
return regs.eax;
}
static void bios_set_state(u8 subsys, int enable)
{
struct regs regs;
memset(&regs, 0, sizeof (regs));
regs.eax = 0x9610;
regs.ebx = (enable ? 0x0100 : 0x0000) | subsys;
call_bios(&regs);
}
static int __init dmi_matched(const struct dmi_system_id *dmi)
{
const struct key_entry *key;
keymap = dmi->driver_data;
for (key = keymap; key->type != KE_END; key++) {
if (key->type == KE_WIFI)
have_wifi = true;
else if (key->type == KE_BLUETOOTH)
have_bluetooth = true;
}
leds_present = key->code & (FE_MAIL_LED | FE_WIFI_LED);
return 1;
}
static int __init copy_keymap(void)
{
const struct key_entry *key;
struct key_entry *new_keymap;
unsigned int length = 1;
for (key = keymap; key->type != KE_END; key++)
length++;
new_keymap = kmemdup(keymap, length * sizeof(struct key_entry),
GFP_KERNEL);
if (!new_keymap)
return -ENOMEM;
keymap = new_keymap;
return 0;
}
static int __init select_keymap(void)
{
dmi_check_system(dmi_ids);
if (keymap_name != NULL) {
if (strcmp (keymap_name, "1557/MS2141") == 0)
keymap = keymap_wistron_ms2141;
else if (strcmp (keymap_name, "aopen1557") == 0)
keymap = keymap_aopen_1557;
else if (strcmp (keymap_name, "prestigio") == 0)
keymap = keymap_prestigio;
else if (strcmp (keymap_name, "generic") == 0)
keymap = keymap_wistron_generic;
else {
printk(KERN_ERR "wistron_btns: Keymap unknown\n");
return -EINVAL;
}
}
if (keymap == NULL) {
if (!force) {
printk(KERN_ERR "wistron_btns: System unknown\n");
return -ENODEV;
}
keymap = keymap_empty;
}
return copy_keymap();
}
static void wistron_mail_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
bios_set_state(MAIL_LED, (value != LED_OFF) ? 1 : 0);
}
static void wistron_wifi_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
bios_set_state(WIFI, (value != LED_OFF) ? 1 : 0);
}
static void wistron_led_init(struct device *parent)
{
if (leds_present & FE_WIFI_LED) {
u16 wifi = bios_get_default_setting(WIFI);
if (wifi & 1) {
wistron_wifi_led.brightness = (wifi & 2) ? LED_FULL : LED_OFF;
if (led_classdev_register(parent, &wistron_wifi_led))
leds_present &= ~FE_WIFI_LED;
else
bios_set_state(WIFI, wistron_wifi_led.brightness);
} else
leds_present &= ~FE_WIFI_LED;
}
if (leds_present & FE_MAIL_LED) {
wistron_mail_led.brightness = LED_OFF;
if (led_classdev_register(parent, &wistron_mail_led))
leds_present &= ~FE_MAIL_LED;
else
bios_set_state(MAIL_LED, wistron_mail_led.brightness);
}
}
static void wistron_led_remove(void)
{
if (leds_present & FE_MAIL_LED)
led_classdev_unregister(&wistron_mail_led);
if (leds_present & FE_WIFI_LED)
led_classdev_unregister(&wistron_wifi_led);
}
static inline void wistron_led_suspend(void)
{
if (leds_present & FE_MAIL_LED)
led_classdev_suspend(&wistron_mail_led);
if (leds_present & FE_WIFI_LED)
led_classdev_suspend(&wistron_wifi_led);
}
static inline void wistron_led_resume(void)
{
if (leds_present & FE_MAIL_LED)
led_classdev_resume(&wistron_mail_led);
if (leds_present & FE_WIFI_LED)
led_classdev_resume(&wistron_wifi_led);
}
static void handle_key(u8 code)
{
const struct key_entry *key =
sparse_keymap_entry_from_scancode(wistron_idev->input, code);
if (key) {
switch (key->type) {
case KE_WIFI:
if (have_wifi) {
wifi_enabled = !wifi_enabled;
bios_set_state(WIFI, wifi_enabled);
}
break;
case KE_BLUETOOTH:
if (have_bluetooth) {
bluetooth_enabled = !bluetooth_enabled;
bios_set_state(BLUETOOTH, bluetooth_enabled);
}
break;
default:
sparse_keymap_report_entry(wistron_idev->input,
key, 1, true);
break;
}
jiffies_last_press = jiffies;
} else
printk(KERN_NOTICE
"wistron_btns: Unknown key code %02X\n", code);
}
static void poll_bios(bool discard)
{
u8 qlen;
u16 val;
for (;;) {
qlen = CMOS_READ(cmos_address);
if (qlen == 0)
break;
val = bios_pop_queue();
if (val != 0 && !discard)
handle_key((u8)val);
}
}
static void wistron_flush(struct input_polled_dev *dev)
{
poll_bios(true);
}
static void wistron_poll(struct input_polled_dev *dev)
{
poll_bios(false);
if (time_before(jiffies, jiffies_last_press + 2 * HZ))
dev->poll_interval = POLL_INTERVAL_BURST;
else
dev->poll_interval = POLL_INTERVAL_DEFAULT;
}
static int wistron_setup_keymap(struct input_dev *dev,
struct key_entry *entry)
{
switch (entry->type) {
case KE_WIFI:
if (!have_wifi) {
entry->type = KE_KEY;
entry->keycode = KEY_WLAN;
}
break;
case KE_BLUETOOTH:
if (!have_bluetooth) {
entry->type = KE_KEY;
entry->keycode = KEY_BLUETOOTH;
}
break;
case KE_END:
if (entry->code & FE_UNTESTED)
printk(KERN_WARNING "Untested laptop multimedia keys, "
"please report success or failure to "
"eric.piel@tremplin-utc.net\n");
break;
}
return 0;
}
static int setup_input_dev(void)
{
struct input_dev *input_dev;
int error;
wistron_idev = input_allocate_polled_device();
if (!wistron_idev)
return -ENOMEM;
wistron_idev->open = wistron_flush;
wistron_idev->poll = wistron_poll;
wistron_idev->poll_interval = POLL_INTERVAL_DEFAULT;
input_dev = wistron_idev->input;
input_dev->name = "Wistron laptop buttons";
input_dev->phys = "wistron/input0";
input_dev->id.bustype = BUS_HOST;
input_dev->dev.parent = &wistron_device->dev;
error = sparse_keymap_setup(input_dev, keymap, wistron_setup_keymap);
if (error)
goto err_free_dev;
error = input_register_polled_device(wistron_idev);
if (error)
goto err_free_dev;
return 0;
err_free_dev:
input_free_polled_device(wistron_idev);
return error;
}
static int wistron_probe(struct platform_device *dev)
{
int err;
bios_attach();
cmos_address = bios_get_cmos_address();
if (have_wifi) {
u16 wifi = bios_get_default_setting(WIFI);
if (wifi & 1)
wifi_enabled = wifi & 2;
else
have_wifi = 0;
if (have_wifi)
bios_set_state(WIFI, wifi_enabled);
}
if (have_bluetooth) {
u16 bt = bios_get_default_setting(BLUETOOTH);
if (bt & 1)
bluetooth_enabled = bt & 2;
else
have_bluetooth = false;
if (have_bluetooth)
bios_set_state(BLUETOOTH, bluetooth_enabled);
}
wistron_led_init(&dev->dev);
err = setup_input_dev();
if (err) {
bios_detach();
return err;
}
return 0;
}
static int wistron_remove(struct platform_device *dev)
{
wistron_led_remove();
input_unregister_polled_device(wistron_idev);
input_free_polled_device(wistron_idev);
bios_detach();
return 0;
}
static int wistron_suspend(struct device *dev)
{
if (have_wifi)
bios_set_state(WIFI, 0);
if (have_bluetooth)
bios_set_state(BLUETOOTH, 0);
wistron_led_suspend();
return 0;
}
static int wistron_resume(struct device *dev)
{
if (have_wifi)
bios_set_state(WIFI, wifi_enabled);
if (have_bluetooth)
bios_set_state(BLUETOOTH, bluetooth_enabled);
wistron_led_resume();
poll_bios(true);
return 0;
}
static int __init wb_module_init(void)
{
int err;
err = select_keymap();
if (err)
return err;
err = map_bios();
if (err)
goto err_free_keymap;
err = platform_driver_register(&wistron_driver);
if (err)
goto err_unmap_bios;
wistron_device = platform_device_alloc("wistron-bios", -1);
if (!wistron_device) {
err = -ENOMEM;
goto err_unregister_driver;
}
err = platform_device_add(wistron_device);
if (err)
goto err_free_device;
return 0;
err_free_device:
platform_device_put(wistron_device);
err_unregister_driver:
platform_driver_unregister(&wistron_driver);
err_unmap_bios:
unmap_bios();
err_free_keymap:
kfree(keymap);
return err;
}
static void __exit wb_module_exit(void)
{
platform_device_unregister(wistron_device);
platform_driver_unregister(&wistron_driver);
unmap_bios();
kfree(keymap);
}
