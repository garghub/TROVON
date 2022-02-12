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
struct sysdev_class *edac_get_sysfs_class(void)
{
int err = 0;
if (atomic_read(&edac_class_valid))
goto out;
err = sysdev_class_register(&edac_class);
if (err) {
printk(KERN_ERR "Error registering toplevel EDAC sysfs dir\n");
return NULL;
}
out:
atomic_inc(&edac_class_valid);
return &edac_class;
}
void edac_put_sysfs_class(void)
{
if (atomic_dec_and_test(&edac_class_valid))
sysdev_class_unregister(&edac_class);
}
