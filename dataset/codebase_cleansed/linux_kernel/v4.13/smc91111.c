static int __init unit_device_init(void)
{
platform_device_register(&smc91c111_device);
return 0;
}
