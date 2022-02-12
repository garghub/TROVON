void lprocfs_echo_init_vars(struct lprocfs_static_vars *lvars)\r\n{\r\nlvars->module_vars = lprocfs_echo_module_vars;\r\nlvars->obd_vars = lprocfs_echo_obd_vars;\r\n}
