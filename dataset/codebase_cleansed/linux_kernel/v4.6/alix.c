static void __init register_alix(void)
{
platform_add_devices(alix_devs, ARRAY_SIZE(alix_devs));
}
static bool __init alix_present(unsigned long bios_phys,
const char *alix_sig,
size_t alix_sig_len)
{
const size_t bios_len = BIOS_REGION_SIZE;
const char *bios_virt;
const char *scan_end;
const char *p;
char name[64];
if (force) {
printk(KERN_NOTICE "%s: forced to skip BIOS test, "
"assume system is ALIX.2/ALIX.3\n",
KBUILD_MODNAME);
return true;
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
if ((tail[0] == '2' || tail[0] == '3' || tail[0] == '6')) {
printk(KERN_INFO
"%s: system is recognized as \"%s\"\n",
KBUILD_MODNAME, name);
return true;
}
}
return false;
}
static bool __init alix_present_dmi(void)
{
const char *vendor, *product;
vendor = dmi_get_system_info(DMI_SYS_VENDOR);
if (!vendor || strcmp(vendor, "PC Engines"))
return false;
product = dmi_get_system_info(DMI_PRODUCT_NAME);
if (!product || (strcmp(product, "ALIX.2D") && strcmp(product, "ALIX.6")))
return false;
printk(KERN_INFO "%s: system is recognized as \"%s %s\"\n",
KBUILD_MODNAME, vendor, product);
return true;
}
static int __init alix_init(void)
{
const char tinybios_sig[] = "PC Engines ALIX.";
const char coreboot_sig[] = "PC Engines\0ALIX.";
if (!is_geode())
return 0;
if (alix_present(BIOS_SIGNATURE_TINYBIOS, tinybios_sig, sizeof(tinybios_sig) - 1) ||
alix_present(BIOS_SIGNATURE_COREBOOT, coreboot_sig, sizeof(coreboot_sig) - 1) ||
alix_present_dmi())
register_alix();
return 0;
}
