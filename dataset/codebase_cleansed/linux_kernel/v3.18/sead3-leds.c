static int __init led_init(void)
{
platform_device_register(&pled_device);
return platform_device_register(&fled_device);
}
