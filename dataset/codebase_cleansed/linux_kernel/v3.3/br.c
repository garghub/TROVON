static int __init br_init(void)
{
int err;
err = stp_proto_register(&br_stp_proto);
if (err < 0) {
pr_err("bridge: can't register sap for STP\n");
return err;
}
err = br_fdb_init();
if (err)
goto err_out;
err = register_pernet_subsys(&br_net_ops);
if (err)
goto err_out1;
err = br_netfilter_init();
if (err)
goto err_out2;
err = register_netdevice_notifier(&br_device_notifier);
if (err)
goto err_out3;
err = br_netlink_init();
if (err)
goto err_out4;
brioctl_set(br_ioctl_deviceless_stub);
#if IS_ENABLED(CONFIG_ATM_LANE)
br_fdb_test_addr_hook = br_fdb_test_addr;
#endif
return 0;
err_out4:
unregister_netdevice_notifier(&br_device_notifier);
err_out3:
br_netfilter_fini();
err_out2:
unregister_pernet_subsys(&br_net_ops);
err_out1:
br_fdb_fini();
err_out:
stp_proto_unregister(&br_stp_proto);
return err;
}
static void __exit br_deinit(void)
{
stp_proto_unregister(&br_stp_proto);
br_netlink_fini();
unregister_netdevice_notifier(&br_device_notifier);
brioctl_set(NULL);
unregister_pernet_subsys(&br_net_ops);
rcu_barrier();
br_netfilter_fini();
#if IS_ENABLED(CONFIG_ATM_LANE)
br_fdb_test_addr_hook = NULL;
#endif
br_fdb_fini();
}
