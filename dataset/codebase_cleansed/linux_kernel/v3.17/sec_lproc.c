static char *sec_flags2str(unsigned long flags, char *buf, int bufsize)
{
buf[0] = '\0';
if (flags & PTLRPC_SEC_FL_REVERSE)
strlcat(buf, "reverse,", bufsize);
if (flags & PTLRPC_SEC_FL_ROOTONLY)
strlcat(buf, "rootonly,", bufsize);
if (flags & PTLRPC_SEC_FL_UDESC)
strlcat(buf, "udesc,", bufsize);
if (flags & PTLRPC_SEC_FL_BULK)
strlcat(buf, "bulk,", bufsize);
if (buf[0] == '\0')
strlcat(buf, "-,", bufsize);
return buf;
}
static int sptlrpc_info_lprocfs_seq_show(struct seq_file *seq, void *v)
{
struct obd_device *dev = seq->private;
struct client_obd *cli = &dev->u.cli;
struct ptlrpc_sec *sec = NULL;
char str[32];
LASSERT(strcmp(dev->obd_type->typ_name, LUSTRE_OSC_NAME) == 0 ||
strcmp(dev->obd_type->typ_name, LUSTRE_MDC_NAME) == 0 ||
strcmp(dev->obd_type->typ_name, LUSTRE_MGC_NAME) == 0);
if (cli->cl_import)
sec = sptlrpc_import_sec_ref(cli->cl_import);
if (sec == NULL)
goto out;
sec_flags2str(sec->ps_flvr.sf_flags, str, sizeof(str));
seq_printf(seq, "rpc flavor: %s\n",
sptlrpc_flavor2name_base(sec->ps_flvr.sf_rpc));
seq_printf(seq, "bulk flavor: %s\n",
sptlrpc_flavor2name_bulk(&sec->ps_flvr, str, sizeof(str)));
seq_printf(seq, "flags: %s\n",
sec_flags2str(sec->ps_flvr.sf_flags, str, sizeof(str)));
seq_printf(seq, "id: %d\n", sec->ps_id);
seq_printf(seq, "refcount: %d\n",
atomic_read(&sec->ps_refcount));
seq_printf(seq, "nctx: %d\n", atomic_read(&sec->ps_nctx));
seq_printf(seq, "gc internal %ld\n", sec->ps_gc_interval);
seq_printf(seq, "gc next %ld\n",
sec->ps_gc_interval ?
sec->ps_gc_next - get_seconds() : 0);
sptlrpc_sec_put(sec);
out:
return 0;
}
static int sptlrpc_ctxs_lprocfs_seq_show(struct seq_file *seq, void *v)
{
struct obd_device *dev = seq->private;
struct client_obd *cli = &dev->u.cli;
struct ptlrpc_sec *sec = NULL;
LASSERT(strcmp(dev->obd_type->typ_name, LUSTRE_OSC_NAME) == 0 ||
strcmp(dev->obd_type->typ_name, LUSTRE_MDC_NAME) == 0 ||
strcmp(dev->obd_type->typ_name, LUSTRE_MGC_NAME) == 0);
if (cli->cl_import)
sec = sptlrpc_import_sec_ref(cli->cl_import);
if (sec == NULL)
goto out;
if (sec->ps_policy->sp_cops->display)
sec->ps_policy->sp_cops->display(sec, seq);
sptlrpc_sec_put(sec);
out:
return 0;
}
int sptlrpc_lprocfs_cliobd_attach(struct obd_device *dev)
{
int rc;
if (strcmp(dev->obd_type->typ_name, LUSTRE_OSC_NAME) != 0 &&
strcmp(dev->obd_type->typ_name, LUSTRE_MDC_NAME) != 0 &&
strcmp(dev->obd_type->typ_name, LUSTRE_MGC_NAME) != 0) {
CERROR("can't register lproc for obd type %s\n",
dev->obd_type->typ_name);
return -EINVAL;
}
rc = lprocfs_obd_seq_create(dev, "srpc_info", 0444,
&sptlrpc_info_lprocfs_fops, dev);
if (rc) {
CERROR("create proc entry srpc_info for %s: %d\n",
dev->obd_name, rc);
return rc;
}
rc = lprocfs_obd_seq_create(dev, "srpc_contexts", 0444,
&sptlrpc_ctxs_lprocfs_fops, dev);
if (rc) {
CERROR("create proc entry srpc_contexts for %s: %d\n",
dev->obd_name, rc);
return rc;
}
return 0;
}
int sptlrpc_lproc_init(void)
{
int rc;
LASSERT(sptlrpc_proc_root == NULL);
sptlrpc_proc_root = lprocfs_register("sptlrpc", proc_lustre_root,
sptlrpc_lprocfs_vars, NULL);
if (IS_ERR(sptlrpc_proc_root)) {
rc = PTR_ERR(sptlrpc_proc_root);
sptlrpc_proc_root = NULL;
return rc;
}
return 0;
}
void sptlrpc_lproc_fini(void)
{
if (sptlrpc_proc_root) {
lprocfs_remove(&sptlrpc_proc_root);
sptlrpc_proc_root = NULL;
}
}
