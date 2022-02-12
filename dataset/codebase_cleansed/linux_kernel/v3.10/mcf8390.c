static int __init mcf8390_platform_init(void)
{
platform_device_register_simple("mcf8390", -1, mcf8390_resources,
ARRAY_SIZE(mcf8390_resources));
return 0;
}
