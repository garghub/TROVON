static struct lu_buf *seq_store_buf(struct seq_thread_info *info)
{
struct lu_buf *buf;
buf = &info->sti_buf;
buf->lb_buf = &info->sti_space;
buf->lb_len = sizeof(info->sti_space);
return buf;
}
void seq_update_cb(struct lu_env *env, struct thandle *th,
struct dt_txn_commit_cb *cb, int err)
{
struct seq_update_callback *ccb;
ccb = container_of0(cb, struct seq_update_callback, suc_cb);
LASSERT(ccb->suc_seq != NULL);
ccb->suc_seq->lss_need_sync = 0;
OBD_FREE_PTR(ccb);
}
int seq_update_cb_add(struct thandle *th, struct lu_server_seq *seq)
{
struct seq_update_callback *ccb;
struct dt_txn_commit_cb *dcb;
int rc;
OBD_ALLOC_PTR(ccb);
if (ccb == NULL)
return -ENOMEM;
ccb->suc_seq = seq;
seq->lss_need_sync = 1;
dcb = &ccb->suc_cb;
dcb->dcb_func = seq_update_cb;
INIT_LIST_HEAD(&dcb->dcb_linkage);
strncpy(dcb->dcb_name, "seq_update_cb", MAX_COMMIT_CB_STR_LEN);
dcb->dcb_name[MAX_COMMIT_CB_STR_LEN - 1] = '\0';
rc = dt_trans_cb_add(th, dcb);
if (rc)
OBD_FREE_PTR(ccb);
return rc;
}
int seq_store_update(const struct lu_env *env, struct lu_server_seq *seq,
struct lu_seq_range *out, int sync)
{
struct dt_device *dt_dev = lu2dt_dev(seq->lss_obj->do_lu.lo_dev);
struct seq_thread_info *info;
struct thandle *th;
loff_t pos = 0;
int rc;
info = lu_context_key_get(&env->le_ctx, &seq_thread_key);
LASSERT(info != NULL);
th = dt_trans_create(env, dt_dev);
if (IS_ERR(th))
RETURN(PTR_ERR(th));
rc = dt_declare_record_write(env, seq->lss_obj,
sizeof(struct lu_seq_range), 0, th);
if (rc)
GOTO(exit, rc);
if (out != NULL) {
rc = fld_declare_server_create(env,
seq->lss_site->ss_server_fld,
out, th);
if (rc)
GOTO(exit, rc);
}
rc = dt_trans_start_local(env, dt_dev, th);
if (rc)
GOTO(exit, rc);
range_cpu_to_le(&info->sti_space, &seq->lss_space);
rc = dt_record_write(env, seq->lss_obj, seq_store_buf(info), &pos, th);
if (rc) {
CERROR("%s: Can't write space data, rc %d\n",
seq->lss_name, rc);
GOTO(exit, rc);
} else if (out != NULL) {
rc = fld_server_create(env, seq->lss_site->ss_server_fld, out,
th);
if (rc) {
CERROR("%s: Can't Update fld database, rc %d\n",
seq->lss_name, rc);
GOTO(exit, rc);
}
}
if (!sync)
sync = !!seq_update_cb_add(th, seq);
th->th_sync |= sync;
exit:
dt_trans_stop(env, dt_dev, th);
return rc;
}
int seq_store_read(struct lu_server_seq *seq,
const struct lu_env *env)
{
struct seq_thread_info *info;
loff_t pos = 0;
int rc;
ENTRY;
info = lu_context_key_get(&env->le_ctx, &seq_thread_key);
LASSERT(info != NULL);
rc = seq->lss_obj->do_body_ops->dbo_read(env, seq->lss_obj,
seq_store_buf(info),
&pos, BYPASS_CAPA);
if (rc == sizeof(info->sti_space)) {
range_le_to_cpu(&seq->lss_space, &info->sti_space);
CDEBUG(D_INFO, "%s: Space - "DRANGE"\n",
seq->lss_name, PRANGE(&seq->lss_space));
rc = 0;
} else if (rc == 0) {
rc = -ENODATA;
} else if (rc > 0) {
CERROR("%s: Read only %d bytes of %d\n", seq->lss_name,
rc, (int)sizeof(info->sti_space));
rc = -EIO;
}
RETURN(rc);
}
int seq_store_init(struct lu_server_seq *seq,
const struct lu_env *env,
struct dt_device *dt)
{
struct dt_object *dt_obj;
struct lu_fid fid;
struct lu_attr attr;
struct dt_object_format dof;
const char *name;
int rc;
ENTRY;
name = seq->lss_type == LUSTRE_SEQ_SERVER ?
LUSTRE_SEQ_SRV_NAME : LUSTRE_SEQ_CTL_NAME;
if (seq->lss_type == LUSTRE_SEQ_SERVER)
lu_local_obj_fid(&fid, FID_SEQ_SRV_OID);
else
lu_local_obj_fid(&fid, FID_SEQ_CTL_OID);
memset(&attr, 0, sizeof(attr));
attr.la_valid = LA_MODE;
attr.la_mode = S_IFREG | 0666;
dof.dof_type = DFT_REGULAR;
dt_obj = dt_find_or_create(env, dt, &fid, &dof, &attr);
if (!IS_ERR(dt_obj)) {
seq->lss_obj = dt_obj;
rc = 0;
} else {
CERROR("%s: Can't find \"%s\" obj %d\n",
seq->lss_name, name, (int)PTR_ERR(dt_obj));
rc = PTR_ERR(dt_obj);
}
RETURN(rc);
}
void seq_store_fini(struct lu_server_seq *seq,
const struct lu_env *env)
{
ENTRY;
if (seq->lss_obj != NULL) {
if (!IS_ERR(seq->lss_obj))
lu_object_put(env, &seq->lss_obj->do_lu);
seq->lss_obj = NULL;
}
EXIT;
}
