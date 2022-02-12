static void __init init_net5501(void)
{
platform_device_register(&net5501_leds_dev);
}
static int __init soekris_init(void)
{
int i;
unsigned char *rombase, *bios;
if (!is_geode())
return 0;
rombase = ioremap(0xffff0000, 0xffff);
if (!rombase) {
printk(KERN_INFO "Soekris net5501 LED driver failed to get rombase");
return 0;
}
bios = rombase + 0x20;
if (strncmp(bios, "comBIOS", 7))
goto unmap;
for (i = 0; i < ARRAY_SIZE(boards); i++) {
unsigned char *model = rombase + boards[i].offset;
if (strncmp(model, boards[i].sig, boards[i].len) == 0) {
printk(KERN_INFO "Soekris %s: %s\n", model, bios);
if (boards[i].init)
boards[i].init();
break;
}
}
unmap:
iounmap(rombase);
return 0;
}
