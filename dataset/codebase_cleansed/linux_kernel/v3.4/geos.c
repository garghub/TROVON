static void __init register_geos(void)
{
platform_add_devices(geos_devs, ARRAY_SIZE(geos_devs));
}
static int __init geos_init(void)
{
const char *vendor, *product;
if (!is_geode())
return 0;
vendor = dmi_get_system_info(DMI_SYS_VENDOR);
if (!vendor || strcmp(vendor, "Traverse Technologies"))
return 0;
product = dmi_get_system_info(DMI_PRODUCT_NAME);
if (!product || strcmp(product, "Geos"))
return 0;
printk(KERN_INFO "%s: system is recognized as \"%s %s\"\n",
KBUILD_MODNAME, vendor, product);
register_geos();
return 0;
}
