static int mgc_ir_state_seq_show(struct seq_file *m, void *v)
{
return lprocfs_mgc_rd_ir_state(m, m->private);
}
void lprocfs_mgc_init_vars(struct lprocfs_static_vars *lvars)
{
lvars->module_vars = lprocfs_mgc_module_vars;
lvars->obd_vars = lprocfs_mgc_obd_vars;
}
