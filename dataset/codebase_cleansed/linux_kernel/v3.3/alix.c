static void __init register_alix(void)
{
platform_device_register(&alix_leds_dev);
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
"assume system is ALIX.2/ALIX.3\n",
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
static int __init alix_init(void)
{
const char tinybios_sig[] = "PC Engines ALIX.";
const char coreboot_sig[] = "PC Engines\0ALIX.";
if (!is_geode())
return 0;
if (alix_present(0xf0000, tinybios_sig, sizeof(tinybios_sig) - 1) ||
alix_present(0x500, coreboot_sig, sizeof(coreboot_sig) - 1))
register_alix();
return 0;
}
