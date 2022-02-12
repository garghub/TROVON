static int __init uart8250_init(void)
{
return platform_device_register(&uart8250_device);
}
