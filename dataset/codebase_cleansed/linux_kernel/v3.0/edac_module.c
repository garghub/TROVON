char *edac_op_state_to_string(int opstate)
{
if (opstate == OP_RUNNING_POLL)
return "POLLED";
else if (opstate == OP_RUNNING_INTERRUPT)
return "INTERRUPT";
else if (opstate == OP_RUNNING_POLL_INTR)
return "POLL-INTR";
else if (opstate == OP_ALLOC)
return "ALLOC";
else if (opstate == OP_OFFLINE)
return "OFFLINE";
return "UNKNOWN";
}
static int edac_workqueue_setup(void)
{
edac_workqueue = create_singlethread_workqueue("edac-poller");
if (edac_workqueue == NULL)
return -ENODEV;
else
return 0;
}
static void edac_workqueue_teardown(void)
{
if (edac_workqueue) {
flush_workqueue(edac_workqueue);
destroy_workqueue(edac_workqueue);
edac_workqueue = NULL;
}
}
static int __init edac_init(void)
{
int err = 0;
edac_printk(KERN_INFO, EDAC_MC, EDAC_VERSION "\n");
edac_pci_clear_parity_errors();
err = edac_sysfs_setup_mc_kset();
if (err)
goto error;
err = edac_workqueue_setup();
if (err) {
edac_printk(KERN_ERR, EDAC_MC, "init WorkQueue failure\n");
goto workq_fail;
}
return 0;
workq_fail:
edac_sysfs_teardown_mc_kset();
error:
return err;
}
static void __exit edac_exit(void)
{
debugf0("%s()\n", __func__);
edac_workqueue_teardown();
edac_sysfs_teardown_mc_kset();
}
