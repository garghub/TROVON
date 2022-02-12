void lprocfs_echo_init_vars(struct lprocfs_static_vars *lvars)
{
lvars->module_vars = lprocfs_echo_module_vars;
lvars->obd_vars = lprocfs_echo_obd_vars;
}
