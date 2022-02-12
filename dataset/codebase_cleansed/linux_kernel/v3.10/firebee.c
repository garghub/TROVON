static int __init init_firebee(void)
{
platform_device_register(&firebee_flash);
return 0;
}
