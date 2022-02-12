static int __init ozwpan_init(void)
{
oz_event_init();
oz_cdev_register();
oz_protocol_init(g_net_dev);
oz_app_enable(OZ_APPID_USB, 1);
oz_apps_init();
return 0;
}
static void __exit ozwpan_exit(void)
{
oz_protocol_term();
oz_apps_term();
oz_cdev_deregister();
oz_event_term();
}
