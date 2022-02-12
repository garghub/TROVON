static int __init goldfish_setup(char *str)
{
goldfish_enable = true;
return 0;
}
static int __init goldfish_init(void)
{
if (!goldfish_enable)
return -ENODEV;
platform_device_register_simple("goldfish_pdev_bus", -1,
goldfish_pdev_bus_resources, 2);
return 0;
}
