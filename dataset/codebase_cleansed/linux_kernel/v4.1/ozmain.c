static int __init ozwpan_init(void)
{
int err;
err = oz_cdev_register();
if (err)
return err;
err = oz_protocol_init(g_net_dev);
if (err)
goto err_protocol;
oz_app_enable(OZ_APPID_USB, 1);
oz_apps_init();
return 0;
err_protocol:
oz_cdev_deregister();
return err;
}
static void __exit ozwpan_exit(void)
{
oz_protocol_term();
oz_apps_term();
oz_cdev_deregister();
}
