void irda_notify_init(notify_t *notify)
{
notify->data_indication = NULL;
notify->udata_indication = NULL;
notify->connect_confirm = NULL;
notify->connect_indication = NULL;
notify->disconnect_indication = NULL;
notify->flow_indication = NULL;
notify->status_indication = NULL;
notify->instance = NULL;
strlcpy(notify->name, "Unknown", sizeof(notify->name));
}
static int __init irda_init(void)
{
int ret = 0;
IRDA_DEBUG(0, "%s()\n", __func__);
irlmp_init();
irlap_init();
irda_device_init();
iriap_init();
irttp_init();
ret = irsock_init();
if (ret < 0)
goto out_err_1;
dev_add_pack(&irda_packet_type);
#ifdef CONFIG_PROC_FS
irda_proc_register();
#endif
#ifdef CONFIG_SYSCTL
ret = irda_sysctl_register();
if (ret < 0)
goto out_err_2;
#endif
ret = irda_nl_register();
if (ret < 0)
goto out_err_3;
return 0;
out_err_3:
#ifdef CONFIG_SYSCTL
irda_sysctl_unregister();
out_err_2:
#endif
#ifdef CONFIG_PROC_FS
irda_proc_unregister();
#endif
dev_remove_pack(&irda_packet_type);
irsock_cleanup();
out_err_1:
irttp_cleanup();
iriap_cleanup();
irda_device_cleanup();
irlap_cleanup();
irlmp_cleanup();
return ret;
}
static void __exit irda_cleanup(void)
{
irda_nl_unregister();
#ifdef CONFIG_SYSCTL
irda_sysctl_unregister();
#endif
#ifdef CONFIG_PROC_FS
irda_proc_unregister();
#endif
dev_remove_pack(&irda_packet_type);
irsock_cleanup();
irttp_cleanup();
iriap_cleanup();
irda_device_cleanup();
irlap_cleanup();
irlmp_cleanup();
}
