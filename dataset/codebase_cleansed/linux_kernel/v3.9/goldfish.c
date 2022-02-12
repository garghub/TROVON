static int __init goldfish_init(void)
{
platform_device_register_simple("goldfish_pdev_bus", -1,
goldfish_pdev_bus_resources, 2);
return 0;
}
