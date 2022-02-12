static void __init register_net5501(void)
{
platform_add_devices(net5501_devs, ARRAY_SIZE(net5501_devs));
}
static bool __init net5501_present(void)
{
int i;
unsigned char *rombase, *bios;
bool found = false;
rombase = ioremap(BIOS_REGION_BASE, BIOS_REGION_SIZE - 1);
if (!rombase) {
printk(KERN_ERR "%s: failed to get rombase\n", KBUILD_MODNAME);
return found;
}
bios = rombase + 0x20;
if (memcmp(bios, "comBIOS", 7))
goto unmap;
for (i = 0; i < ARRAY_SIZE(boards); i++) {
unsigned char *model = rombase + boards[i].offset;
if (!memcmp(model, boards[i].sig, boards[i].len)) {
printk(KERN_INFO "%s: system is recognized as \"%s\"\n",
KBUILD_MODNAME, model);
found = true;
break;
}
}
unmap:
iounmap(rombase);
return found;
}
static int __init net5501_init(void)
{
if (!is_geode())
return 0;
if (!net5501_present())
return 0;
register_net5501();
return 0;
}
