static int __init edac_report_setup(char *str)
{
if (!str)
return -EINVAL;
if (!strncmp(str, "on", 2))
set_edac_report_status(EDAC_REPORTING_ENABLED);
else if (!strncmp(str, "off", 3))
set_edac_report_status(EDAC_REPORTING_DISABLED);
else if (!strncmp(str, "force", 5))
set_edac_report_status(EDAC_REPORTING_FORCE);
return 0;
}
int edac_handler_set(void)
{
if (edac_op_state == EDAC_OPSTATE_POLL)
return 0;
return atomic_read(&edac_handlers);
}
void edac_atomic_assert_error(void)
{
edac_err_assert++;
}
struct bus_type *edac_get_sysfs_subsys(void)
{
int err = 0;
if (atomic_read(&edac_subsys_valid))
goto out;
err = subsys_system_register(&edac_subsys, NULL);
if (err) {
printk(KERN_ERR "Error registering toplevel EDAC sysfs dir\n");
return NULL;
}
out:
atomic_inc(&edac_subsys_valid);
return &edac_subsys;
}
void edac_put_sysfs_subsys(void)
{
if (atomic_dec_and_test(&edac_subsys_valid))
bus_unregister(&edac_subsys);
}
