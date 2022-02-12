void gss_stat_oos_record_cli(int behind)
{
atomic_inc(&gss_stat_oos.oos_cli_count);
spin_lock(&gss_stat_oos.oos_lock);
if (behind > gss_stat_oos.oos_cli_behind)
gss_stat_oos.oos_cli_behind = behind;
spin_unlock(&gss_stat_oos.oos_lock);
}
void gss_stat_oos_record_svc(int phase, int replay)
{
LASSERT(phase >= 0 && phase <= 2);
if (replay)
atomic_inc(&gss_stat_oos.oos_svc_replay[phase]);
else
atomic_inc(&gss_stat_oos.oos_svc_pass[phase]);
}
static int gss_proc_oos_seq_show(struct seq_file *m, void *v)
{
return seq_printf(m,
"seqwin: %u\n"
"backwin: %u\n"
"client fall behind seqwin\n"
" occurrence: %d\n"
" max seq behind: %d\n"
"server replay detected:\n"
" phase 0: %d\n"
" phase 1: %d\n"
" phase 2: %d\n"
"server verify ok:\n"
" phase 2: %d\n",
GSS_SEQ_WIN_MAIN,
GSS_SEQ_WIN_BACK,
atomic_read(&gss_stat_oos.oos_cli_count),
gss_stat_oos.oos_cli_behind,
atomic_read(&gss_stat_oos.oos_svc_replay[0]),
atomic_read(&gss_stat_oos.oos_svc_replay[1]),
atomic_read(&gss_stat_oos.oos_svc_replay[2]),
atomic_read(&gss_stat_oos.oos_svc_pass[2]));
}
static int gss_proc_write_secinit(struct file *file, const char *buffer,
size_t count, off_t *off)
{
int rc;
rc = gss_do_ctx_init_rpc((char *) buffer, count);
if (rc) {
LASSERT(rc < 0);
return rc;
}
return count;
}
static int gss_lk_proc_dl_seq_show(struct seq_file *m, void *v)
{
return seq_printf(m, "%u\n", gss_lk_debug_level);
}
static int gss_lk_proc_dl_seq_write(struct file *file, const char *buffer,
size_t count, off_t *off)
{
int val, rc;
rc = lprocfs_write_helper(buffer, count, &val);
if (rc < 0)
return rc;
if (val < 0 || val > 4)
return -ERANGE;
gss_lk_debug_level = val;
return count;
}
void gss_exit_lproc(void)
{
if (gss_proc_lk) {
lprocfs_remove(&gss_proc_lk);
gss_proc_lk = NULL;
}
if (gss_proc_root) {
lprocfs_remove(&gss_proc_root);
gss_proc_root = NULL;
}
}
int gss_init_lproc(void)
{
int rc;
spin_lock_init(&gss_stat_oos.oos_lock);
gss_proc_root = lprocfs_register("gss", sptlrpc_proc_root,
gss_lprocfs_vars, NULL);
if (IS_ERR(gss_proc_root)) {
gss_proc_root = NULL;
GOTO(err_out, rc = PTR_ERR(gss_proc_root));
}
gss_proc_lk = lprocfs_register("lgss_keyring", gss_proc_root,
gss_lk_lprocfs_vars, NULL);
if (IS_ERR(gss_proc_lk)) {
gss_proc_lk = NULL;
GOTO(err_out, rc = PTR_ERR(gss_proc_root));
}
return 0;
err_out:
CERROR("failed to initialize gss lproc entries: %d\n", rc);
gss_exit_lproc();
return rc;
}
