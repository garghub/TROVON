static void alix_led_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
struct alix_led *led_dev =
container_of(led_cdev, struct alix_led, cdev);
if (brightness)
outl(led_dev->on_value, gpio_base + led_dev->port);
else
outl(led_dev->off_value, gpio_base + led_dev->port);
}
static int __init alix_led_probe(struct platform_device *pdev)
{
int i;
int ret;
for (i = 0; i < ARRAY_SIZE(alix_leds); i++) {
alix_leds[i].cdev.flags |= LED_CORE_SUSPENDRESUME;
ret = led_classdev_register(&pdev->dev, &alix_leds[i].cdev);
if (ret < 0)
goto fail;
}
return 0;
fail:
while (--i >= 0)
led_classdev_unregister(&alix_leds[i].cdev);
return ret;
}
static int alix_led_remove(struct platform_device *pdev)
{
int i;
for (i = 0; i < ARRAY_SIZE(alix_leds); i++)
led_classdev_unregister(&alix_leds[i].cdev);
return 0;
}
static int __init alix_present(unsigned long bios_phys,
const char *alix_sig,
size_t alix_sig_len)
{
const size_t bios_len = 0x00010000;
const char *bios_virt;
const char *scan_end;
const char *p;
char name[64];
if (force) {
printk(KERN_NOTICE "%s: forced to skip BIOS test, "
"assume system has ALIX.2 style LEDs\n",
KBUILD_MODNAME);
return 1;
}
bios_virt = phys_to_virt(bios_phys);
scan_end = bios_virt + bios_len - (alix_sig_len + 2);
for (p = bios_virt; p < scan_end; p++) {
const char *tail;
char *a;
if (memcmp(p, alix_sig, alix_sig_len) != 0)
continue;
memcpy(name, p, sizeof(name));
a = strchr(name, '\0');
if (a)
*a = ' ';
a = strchr(name, '\r');
if (a)
*a = '\0';
tail = p + alix_sig_len;
if ((tail[0] == '2' || tail[0] == '3')) {
printk(KERN_INFO
"%s: system is recognized as \"%s\"\n",
KBUILD_MODNAME, name);
return 1;
}
}
return 0;
}
static int __init alix_pci_led_init(void)
{
u32 low, hi;
if (pci_dev_present(divil_pci) == 0) {
printk(KERN_WARNING KBUILD_MODNAME": DIVIL not found\n");
return -ENODEV;
}
rdmsr(MSR_LBAR_GPIO, low, hi);
if (hi != 0x0000f001) {
printk(KERN_WARNING KBUILD_MODNAME": GPIO not enabled\n");
return -ENODEV;
}
gpio_base = low & 0x0000ff00;
if (!request_region(gpio_base, CS5535_GPIO_SIZE, KBUILD_MODNAME)) {
printk(KERN_ERR KBUILD_MODNAME": can't allocate I/O for GPIO\n");
return -ENODEV;
}
outl(1 << 6, gpio_base + 0x04);
outl(1 << 9, gpio_base + 0x84);
outl(1 << 11, gpio_base + 0x84);
return 0;
}
static int __init alix_led_init(void)
{
int ret = -ENODEV;
const char tinybios_sig[] = "PC Engines ALIX.";
const char coreboot_sig[] = "PC Engines\0ALIX.";
if (alix_present(0xf0000, tinybios_sig, sizeof(tinybios_sig) - 1) ||
alix_present(0x500, coreboot_sig, sizeof(coreboot_sig) - 1))
ret = alix_pci_led_init();
if (ret < 0)
return ret;
pdev = platform_device_register_simple(KBUILD_MODNAME, -1, NULL, 0);
if (!IS_ERR(pdev)) {
ret = platform_driver_probe(&alix_led_driver, alix_led_probe);
if (ret)
platform_device_unregister(pdev);
} else
ret = PTR_ERR(pdev);
return ret;
}
static void __exit alix_led_exit(void)
{
platform_device_unregister(pdev);
platform_driver_unregister(&alix_led_driver);
release_region(gpio_base, CS5535_GPIO_SIZE);
}
