int fld_declare_index_create(const struct lu_env *env,
struct lu_server_fld *fld,
const struct lu_seq_range *new_range,
struct thandle *th)
{
struct lu_seq_range *tmp;
struct lu_seq_range *range;
struct fld_thread_info *info;
int rc = 0;
ENTRY;
info = lu_context_key_get(&env->le_ctx, &fld_thread_key);
range = &info->fti_lrange;
tmp = &info->fti_irange;
memset(range, 0, sizeof(*range));
rc = fld_index_lookup(env, fld, new_range->lsr_start, range);
if (rc == 0) {
LASSERT((range_compare_loc(new_range, range) == 0));
GOTO(out, rc = -EEXIST);
}
if (rc != -ENOENT) {
CERROR("%s: lookup range "DRANGE" error: rc = %d\n",
fld->lsf_name, PRANGE(range), rc);
GOTO(out, rc);
}
if (new_range->lsr_start == range->lsr_end && range->lsr_end != 0 &&
range_compare_loc(new_range, range) == 0) {
range_cpu_to_be(tmp, range);
rc = dt_declare_delete(env, fld->lsf_obj,
(struct dt_key *)&tmp->lsr_start, th);
if (rc) {
CERROR("%s: declare record "DRANGE" failed: rc = %d\n",
fld->lsf_name, PRANGE(range), rc);
GOTO(out, rc);
}
memcpy(tmp, new_range, sizeof(*new_range));
tmp->lsr_start = range->lsr_start;
} else {
memcpy(tmp, new_range, sizeof(*new_range));
}
range_cpu_to_be(tmp, tmp);
rc = dt_declare_insert(env, fld->lsf_obj, (struct dt_rec *)tmp,
(struct dt_key *)&tmp->lsr_start, th);
out:
RETURN(rc);
}
int fld_index_create(const struct lu_env *env, struct lu_server_fld *fld,
const struct lu_seq_range *new_range, struct thandle *th)
{
struct lu_seq_range *range;
struct lu_seq_range *tmp;
struct fld_thread_info *info;
int rc = 0;
int deleted = 0;
struct fld_cache_entry *flde;
ENTRY;
info = lu_context_key_get(&env->le_ctx, &fld_thread_key);
LASSERT(mutex_is_locked(&fld->lsf_lock));
range = &info->fti_lrange;
memset(range, 0, sizeof(*range));
tmp = &info->fti_irange;
rc = fld_index_lookup(env, fld, new_range->lsr_start, range);
if (rc != -ENOENT) {
rc = rc == 0 ? -EEXIST : rc;
GOTO(out, rc);
}
if (new_range->lsr_start == range->lsr_end && range->lsr_end != 0 &&
range_compare_loc(new_range, range) == 0) {
range_cpu_to_be(tmp, range);
rc = dt_delete(env, fld->lsf_obj,
(struct dt_key *)&tmp->lsr_start, th,
BYPASS_CAPA);
if (rc != 0)
GOTO(out, rc);
memcpy(tmp, new_range, sizeof(*new_range));
tmp->lsr_start = range->lsr_start;
deleted = 1;
} else {
memcpy(tmp, new_range, sizeof(*new_range));
}
range_cpu_to_be(tmp, tmp);
rc = dt_insert(env, fld->lsf_obj, (struct dt_rec *)tmp,
(struct dt_key *)&tmp->lsr_start, th, BYPASS_CAPA, 1);
if (rc != 0) {
CERROR("%s: insert range "DRANGE" failed: rc = %d\n",
fld->lsf_name, PRANGE(new_range), rc);
GOTO(out, rc);
}
flde = fld_cache_entry_create(new_range);
if (IS_ERR(flde))
GOTO(out, rc = PTR_ERR(flde));
write_lock(&fld->lsf_cache->fci_lock);
if (deleted)
fld_cache_delete_nolock(fld->lsf_cache, new_range);
rc = fld_cache_insert_nolock(fld->lsf_cache, flde);
write_unlock(&fld->lsf_cache->fci_lock);
if (rc)
OBD_FREE_PTR(flde);
out:
RETURN(rc);
}
int fld_index_lookup(const struct lu_env *env, struct lu_server_fld *fld,
seqno_t seq, struct lu_seq_range *range)
{
struct lu_seq_range *fld_rec;
struct fld_thread_info *info;
int rc;
ENTRY;
info = lu_context_key_get(&env->le_ctx, &fld_thread_key);
fld_rec = &info->fti_rec;
rc = fld_cache_lookup(fld->lsf_cache, seq, fld_rec);
if (rc == 0) {
*range = *fld_rec;
if (range_within(range, seq))
rc = 0;
else
rc = -ENOENT;
}
CDEBUG(D_INFO, "%s: lookup seq = "LPX64" range : "DRANGE" rc = %d\n",
fld->lsf_name, seq, PRANGE(range), rc);
RETURN(rc);
}
int fld_insert_entry(const struct lu_env *env,
struct lu_server_fld *fld,
const struct lu_seq_range *range)
{
struct thandle *th;
int rc;
ENTRY;
th = dt_trans_create(env, lu2dt_dev(fld->lsf_obj->do_lu.lo_dev));
if (IS_ERR(th))
RETURN(PTR_ERR(th));
rc = fld_declare_index_create(env, fld, range, th);
if (rc != 0) {
if (rc == -EEXIST)
rc = 0;
GOTO(out, rc);
}
rc = dt_trans_start_local(env, lu2dt_dev(fld->lsf_obj->do_lu.lo_dev),
th);
if (rc)
GOTO(out, rc);
rc = fld_index_create(env, fld, range, th);
if (rc == -EEXIST)
rc = 0;
out:
dt_trans_stop(env, lu2dt_dev(fld->lsf_obj->do_lu.lo_dev), th);
RETURN(rc);
}
static int fld_insert_special_entries(const struct lu_env *env,
struct lu_server_fld *fld)
{
int rc;
rc = fld_insert_entry(env, fld, &IGIF_FLD_RANGE);
if (rc != 0)
RETURN(rc);
rc = fld_insert_entry(env, fld, &DOT_LUSTRE_FLD_RANGE);
if (rc != 0)
RETURN(rc);
rc = fld_insert_entry(env, fld, &ROOT_FLD_RANGE);
RETURN(rc);
}
int fld_index_init(const struct lu_env *env, struct lu_server_fld *fld,
struct dt_device *dt)
{
struct dt_object *dt_obj = NULL;
struct lu_fid fid;
struct lu_attr *attr = NULL;
struct lu_seq_range *range = NULL;
struct fld_thread_info *info;
struct dt_object_format dof;
struct dt_it *it;
const struct dt_it_ops *iops;
int rc;
ENTRY;
info = lu_context_key_get(&env->le_ctx, &fld_thread_key);
LASSERT(info != NULL);
lu_local_obj_fid(&fid, FLD_INDEX_OID);
OBD_ALLOC_PTR(attr);
if (attr == NULL)
RETURN(-ENOMEM);
memset(attr, 0, sizeof(*attr));
attr->la_valid = LA_MODE;
attr->la_mode = S_IFREG | 0666;
dof.dof_type = DFT_INDEX;
dof.u.dof_idx.di_feat = &fld_index_features;
dt_obj = dt_find_or_create(env, dt, &fid, &dof, attr);
if (IS_ERR(dt_obj)) {
rc = PTR_ERR(dt_obj);
CERROR("%s: Can't find \"%s\" obj %d\n", fld->lsf_name,
fld_index_name, rc);
dt_obj = NULL;
GOTO(out, rc);
}
fld->lsf_obj = dt_obj;
rc = dt_obj->do_ops->do_index_try(env, dt_obj, &fld_index_features);
if (rc != 0) {
CERROR("%s: File \"%s\" is not an index: rc = %d!\n",
fld->lsf_name, fld_index_name, rc);
GOTO(out, rc);
}
range = &info->fti_rec;
iops = &dt_obj->do_index_ops->dio_it;
it = iops->init(env, dt_obj, 0, NULL);
if (IS_ERR(it))
GOTO(out, rc = PTR_ERR(it));
rc = iops->load(env, it, 0);
if (rc < 0)
GOTO(out_it_fini, rc);
if (rc > 0) {
do {
rc = iops->rec(env, it, (struct dt_rec *)range, 0);
if (rc != 0)
GOTO(out_it_put, rc);
LASSERT(range != NULL);
range_be_to_cpu(range, range);
rc = fld_cache_insert(fld->lsf_cache, range);
if (rc != 0)
GOTO(out_it_put, rc);
rc = iops->next(env, it);
} while (rc == 0);
}
mutex_lock(&fld->lsf_lock);
rc = fld_insert_special_entries(env, fld);
mutex_unlock(&fld->lsf_lock);
if (rc != 0) {
CERROR("%s: insert special entries failed!: rc = %d\n",
fld->lsf_name, rc);
GOTO(out_it_put, rc);
}
out_it_put:
iops->put(env, it);
out_it_fini:
iops->fini(env, it);
out:
if (attr != NULL)
OBD_FREE_PTR(attr);
if (rc != 0) {
if (dt_obj != NULL)
lu_object_put(env, &dt_obj->do_lu);
fld->lsf_obj = NULL;
}
RETURN(rc);
}
void fld_index_fini(const struct lu_env *env, struct lu_server_fld *fld)
{
ENTRY;
if (fld->lsf_obj != NULL) {
if (!IS_ERR(fld->lsf_obj))
lu_object_put(env, &fld->lsf_obj->do_lu);
fld->lsf_obj = NULL;
}
EXIT;
}
