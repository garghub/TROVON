void dt_txn_callback_add(struct dt_device *dev, struct dt_txn_callback *cb)
{
list_add(&cb->dtc_linkage, &dev->dd_txn_callbacks);
}
void dt_txn_callback_del(struct dt_device *dev, struct dt_txn_callback *cb)
{
list_del_init(&cb->dtc_linkage);
}
int dt_txn_hook_start(const struct lu_env *env,
struct dt_device *dev, struct thandle *th)
{
int rc = 0;
struct dt_txn_callback *cb;
if (th->th_local)
return 0;
list_for_each_entry(cb, &dev->dd_txn_callbacks, dtc_linkage) {
if (cb->dtc_txn_start == NULL ||
!(cb->dtc_tag & env->le_ctx.lc_tags))
continue;
rc = cb->dtc_txn_start(env, th, cb->dtc_cookie);
if (rc < 0)
break;
}
return rc;
}
int dt_txn_hook_stop(const struct lu_env *env, struct thandle *txn)
{
struct dt_device *dev = txn->th_dev;
struct dt_txn_callback *cb;
int rc = 0;
if (txn->th_local)
return 0;
list_for_each_entry(cb, &dev->dd_txn_callbacks, dtc_linkage) {
if (cb->dtc_txn_stop == NULL ||
!(cb->dtc_tag & env->le_ctx.lc_tags))
continue;
rc = cb->dtc_txn_stop(env, txn, cb->dtc_cookie);
if (rc < 0)
break;
}
return rc;
}
void dt_txn_hook_commit(struct thandle *txn)
{
struct dt_txn_callback *cb;
if (txn->th_local)
return;
list_for_each_entry(cb, &txn->th_dev->dd_txn_callbacks,
dtc_linkage) {
if (cb->dtc_txn_commit)
cb->dtc_txn_commit(txn, cb->dtc_cookie);
}
}
int dt_device_init(struct dt_device *dev, struct lu_device_type *t)
{
INIT_LIST_HEAD(&dev->dd_txn_callbacks);
return lu_device_init(&dev->dd_lu_dev, t);
}
void dt_device_fini(struct dt_device *dev)
{
lu_device_fini(&dev->dd_lu_dev);
}
int dt_object_init(struct dt_object *obj,
struct lu_object_header *h, struct lu_device *d)
{
return lu_object_init(&obj->do_lu, h, d);
}
void dt_object_fini(struct dt_object *obj)
{
lu_object_fini(&obj->do_lu);
}
int dt_try_as_dir(const struct lu_env *env, struct dt_object *obj)
{
if (obj->do_index_ops == NULL)
obj->do_ops->do_index_try(env, obj, &dt_directory_features);
return obj->do_index_ops != NULL;
}
enum dt_format_type dt_mode_to_dft(__u32 mode)
{
enum dt_format_type result;
switch (mode & S_IFMT) {
case S_IFDIR:
result = DFT_DIR;
break;
case S_IFREG:
result = DFT_REGULAR;
break;
case S_IFLNK:
result = DFT_SYM;
break;
case S_IFCHR:
case S_IFBLK:
case S_IFIFO:
case S_IFSOCK:
result = DFT_NODE;
break;
default:
LBUG();
break;
}
return result;
}
int dt_lookup_dir(const struct lu_env *env, struct dt_object *dir,
const char *name, struct lu_fid *fid)
{
if (dt_try_as_dir(env, dir))
return dt_lookup(env, dir, (struct dt_rec *)fid,
(const struct dt_key *)name, BYPASS_CAPA);
return -ENOTDIR;
}
struct dt_object *dt_locate_at(const struct lu_env *env,
struct dt_device *dev, const struct lu_fid *fid,
struct lu_device *top_dev)
{
struct lu_object *lo, *n;
lo = lu_object_find_at(env, top_dev, fid, NULL);
if (IS_ERR(lo))
return (void *)lo;
LASSERT(lo != NULL);
list_for_each_entry(n, &lo->lo_header->loh_layers, lo_linkage) {
if (n->lo_dev == &dev->dd_lu_dev)
return container_of0(n, struct dt_object, do_lu);
}
return ERR_PTR(-ENOENT);
}
static int dt_find_entry(const struct lu_env *env, const char *entry, void *data)
{
struct dt_find_hint *dfh = data;
struct dt_device *dt = dfh->dfh_dt;
struct lu_fid *fid = dfh->dfh_fid;
struct dt_object *obj = dfh->dfh_o;
int result;
result = dt_lookup_dir(env, obj, entry, fid);
lu_object_put(env, &obj->do_lu);
if (result == 0) {
obj = dt_locate(env, dt, fid);
if (IS_ERR(obj))
result = PTR_ERR(obj);
}
dfh->dfh_o = obj;
return result;
}
int dt_path_parser(const struct lu_env *env,
char *path, dt_entry_func_t entry_func,
void *data)
{
char *e;
int rc = 0;
while (1) {
e = strsep(&path, "/");
if (e == NULL)
break;
if (e[0] == 0) {
if (!path || path[0] == '\0')
break;
continue;
}
rc = entry_func(env, e, data);
if (rc)
break;
}
return rc;
}
struct dt_object *
dt_store_resolve(const struct lu_env *env, struct dt_device *dt,
const char *path, struct lu_fid *fid)
{
struct dt_thread_info *info = dt_info(env);
struct dt_find_hint *dfh = &info->dti_dfh;
struct dt_object *obj;
char *local = info->dti_buf;
int result;
dfh->dfh_dt = dt;
dfh->dfh_fid = fid;
strncpy(local, path, DT_MAX_PATH);
local[DT_MAX_PATH - 1] = '\0';
result = dt->dd_ops->dt_root_get(env, dt, fid);
if (result == 0) {
obj = dt_locate(env, dt, fid);
if (!IS_ERR(obj)) {
dfh->dfh_o = obj;
result = dt_path_parser(env, local, dt_find_entry, dfh);
if (result != 0)
obj = ERR_PTR(result);
else
obj = dfh->dfh_o;
}
} else {
obj = ERR_PTR(result);
}
return obj;
}
static struct dt_object *dt_reg_open(const struct lu_env *env,
struct dt_device *dt,
struct dt_object *p,
const char *name,
struct lu_fid *fid)
{
struct dt_object *o;
int result;
result = dt_lookup_dir(env, p, name, fid);
if (result == 0){
o = dt_locate(env, dt, fid);
}
else
o = ERR_PTR(result);
return o;
}
struct dt_object *dt_store_open(const struct lu_env *env,
struct dt_device *dt,
const char *dirname,
const char *filename,
struct lu_fid *fid)
{
struct dt_object *file;
struct dt_object *dir;
dir = dt_store_resolve(env, dt, dirname, fid);
if (!IS_ERR(dir)) {
file = dt_reg_open(env, dt, dir,
filename, fid);
lu_object_put(env, &dir->do_lu);
} else {
file = dir;
}
return file;
}
struct dt_object *dt_find_or_create(const struct lu_env *env,
struct dt_device *dt,
const struct lu_fid *fid,
struct dt_object_format *dof,
struct lu_attr *at)
{
struct dt_object *dto;
struct thandle *th;
int rc;
dto = dt_locate(env, dt, fid);
if (IS_ERR(dto))
return dto;
LASSERT(dto != NULL);
if (dt_object_exists(dto))
return dto;
th = dt_trans_create(env, dt);
if (IS_ERR(th))
GOTO(out, rc = PTR_ERR(th));
rc = dt_declare_create(env, dto, at, NULL, dof, th);
if (rc)
GOTO(trans_stop, rc);
rc = dt_trans_start_local(env, dt, th);
if (rc)
GOTO(trans_stop, rc);
dt_write_lock(env, dto, 0);
if (dt_object_exists(dto))
GOTO(unlock, rc = 0);
CDEBUG(D_OTHER, "create new object "DFID"\n", PFID(fid));
rc = dt_create(env, dto, at, NULL, dof, th);
if (rc)
GOTO(unlock, rc);
LASSERT(dt_object_exists(dto));
unlock:
dt_write_unlock(env, dto);
trans_stop:
dt_trans_stop(env, dt, th);
out:
if (rc) {
lu_object_put(env, &dto->do_lu);
return ERR_PTR(rc);
}
return dto;
}
int dt_global_init(void)
{
int result;
LU_CONTEXT_KEY_INIT(&dt_key);
result = lu_context_key_register(&dt_key);
return result;
}
void dt_global_fini(void)
{
lu_context_key_degister(&dt_key);
}
int dt_read(const struct lu_env *env, struct dt_object *dt,
struct lu_buf *buf, loff_t *pos)
{
LASSERTF(dt != NULL, "dt is NULL when we want to read record\n");
return dt->do_body_ops->dbo_read(env, dt, buf, pos, BYPASS_CAPA);
}
int dt_record_read(const struct lu_env *env, struct dt_object *dt,
struct lu_buf *buf, loff_t *pos)
{
int rc;
LASSERTF(dt != NULL, "dt is NULL when we want to read record\n");
rc = dt->do_body_ops->dbo_read(env, dt, buf, pos, BYPASS_CAPA);
if (rc == buf->lb_len)
rc = 0;
else if (rc >= 0)
rc = -EFAULT;
return rc;
}
int dt_record_write(const struct lu_env *env, struct dt_object *dt,
const struct lu_buf *buf, loff_t *pos, struct thandle *th)
{
int rc;
LASSERTF(dt != NULL, "dt is NULL when we want to write record\n");
LASSERT(th != NULL);
LASSERT(dt->do_body_ops);
LASSERT(dt->do_body_ops->dbo_write);
rc = dt->do_body_ops->dbo_write(env, dt, buf, pos, th, BYPASS_CAPA, 1);
if (rc == buf->lb_len)
rc = 0;
else if (rc >= 0)
rc = -EFAULT;
return rc;
}
int dt_declare_version_set(const struct lu_env *env, struct dt_object *o,
struct thandle *th)
{
struct lu_buf vbuf;
char *xname = XATTR_NAME_VERSION;
LASSERT(o);
vbuf.lb_buf = NULL;
vbuf.lb_len = sizeof(dt_obj_version_t);
return dt_declare_xattr_set(env, o, &vbuf, xname, 0, th);
}
void dt_version_set(const struct lu_env *env, struct dt_object *o,
dt_obj_version_t version, struct thandle *th)
{
struct lu_buf vbuf;
char *xname = XATTR_NAME_VERSION;
int rc;
LASSERT(o);
vbuf.lb_buf = &version;
vbuf.lb_len = sizeof(version);
rc = dt_xattr_set(env, o, &vbuf, xname, 0, th, BYPASS_CAPA);
if (rc < 0)
CDEBUG(D_INODE, "Can't set version, rc %d\n", rc);
return;
}
dt_obj_version_t dt_version_get(const struct lu_env *env, struct dt_object *o)
{
struct lu_buf vbuf;
char *xname = XATTR_NAME_VERSION;
dt_obj_version_t version;
int rc;
LASSERT(o);
vbuf.lb_buf = &version;
vbuf.lb_len = sizeof(version);
rc = dt_xattr_get(env, o, &vbuf, xname, BYPASS_CAPA);
if (rc != sizeof(version)) {
CDEBUG(D_INODE, "Can't get version, rc %d\n", rc);
version = 0;
}
return version;
}
static inline const struct dt_index_features *dt_index_feat_select(__u64 seq,
__u32 mode)
{
if (seq == FID_SEQ_QUOTA_GLB) {
if (!S_ISREG(mode))
return ERR_PTR(-ENOENT);
return &dt_quota_glb_features;
} else if (seq == FID_SEQ_QUOTA) {
if (!S_ISREG(mode))
return ERR_PTR(-ENOENT);
return &dt_quota_slv_features;
} else if (seq >= FID_SEQ_NORMAL) {
if (!S_ISDIR(mode))
return ERR_PTR(-ENOTDIR);
return &dt_directory_features;
}
return ERR_PTR(-EOPNOTSUPP);
}
static int dt_index_page_build(const struct lu_env *env, union lu_page *lp,
int nob, const struct dt_it_ops *iops,
struct dt_it *it, __u32 attr, void *arg)
{
struct idx_info *ii = (struct idx_info *)arg;
struct lu_idxpage *lip = &lp->lp_idx;
char *entry;
int rc, size;
LASSERT((ii->ii_flags & II_FL_VARKEY) == 0);
LASSERT((ii->ii_flags & II_FL_VARREC) == 0);
memset(lip, 0, LIP_HDR_SIZE);
lip->lip_magic = LIP_MAGIC;
nob -= LIP_HDR_SIZE;
size = ii->ii_recsize + ii->ii_keysize;
if ((ii->ii_flags & II_FL_NOHASH) == 0)
size += sizeof(__u64);
entry = lip->lip_entries;
do {
char *tmp_entry = entry;
struct dt_key *key;
__u64 hash;
hash = iops->store(env, it);
ii->ii_hash_end = hash;
if (OBD_FAIL_CHECK(OBD_FAIL_OBD_IDX_READ_BREAK)) {
if (lip->lip_nr != 0)
GOTO(out, rc = 0);
}
if (nob < size) {
if (lip->lip_nr == 0)
GOTO(out, rc = -EINVAL);
GOTO(out, rc = 0);
}
if ((ii->ii_flags & II_FL_NOHASH) == 0) {
memcpy(tmp_entry, &hash, sizeof(hash));
tmp_entry += sizeof(hash);
}
LASSERT(iops->key_size(env, it) == ii->ii_keysize);
key = iops->key(env, it);
memcpy(tmp_entry, key, ii->ii_keysize);
tmp_entry += ii->ii_keysize;
rc = iops->rec(env, it, (struct dt_rec *)tmp_entry, attr);
if (rc != -ESTALE) {
if (rc != 0)
GOTO(out, rc);
lip->lip_nr++;
if (unlikely(lip->lip_nr == 1 && ii->ii_count == 0))
ii->ii_hash_start = hash;
entry = tmp_entry + ii->ii_recsize;
nob -= size;
}
do {
rc = iops->next(env, it);
} while (rc == -ESTALE);
} while (rc == 0);
GOTO(out, rc);
out:
if (rc >= 0 && lip->lip_nr > 0)
ii->ii_count++;
if (rc > 0)
ii->ii_hash_end = II_END_OFF;
return rc;
}
int dt_index_walk(const struct lu_env *env, struct dt_object *obj,
const struct lu_rdpg *rdpg, dt_index_page_build_t filler,
void *arg)
{
struct dt_it *it;
const struct dt_it_ops *iops;
unsigned int pageidx, nob, nlupgs = 0;
int rc;
LASSERT(rdpg->rp_pages != NULL);
LASSERT(obj->do_index_ops != NULL);
nob = rdpg->rp_count;
if (nob <= 0)
return -EFAULT;
iops = &obj->do_index_ops->dio_it;
LASSERT(iops != NULL);
it = iops->init(env, obj, rdpg->rp_attrs, BYPASS_CAPA);
if (IS_ERR(it))
return PTR_ERR(it);
rc = iops->load(env, it, rdpg->rp_hash);
if (rc == 0) {
rc = iops->next(env, it);
} else if (rc > 0) {
rc = 0;
}
for (pageidx = 0; rc == 0 && nob > 0; pageidx++) {
union lu_page *lp;
int i;
LASSERT(pageidx < rdpg->rp_npages);
lp = kmap(rdpg->rp_pages[pageidx]);
for (i = 0; i < LU_PAGE_COUNT; i++, lp++, nob -= LU_PAGE_SIZE) {
rc = filler(env, lp, min_t(int, nob, LU_PAGE_SIZE),
iops, it, rdpg->rp_attrs, arg);
if (rc < 0)
break;
nlupgs++;
if (rc > 0)
break;
}
kunmap(rdpg->rp_pages[i]);
}
iops->put(env, it);
iops->fini(env, it);
if (rc >= 0)
rc = min_t(unsigned int, nlupgs * LU_PAGE_SIZE, rdpg->rp_count);
return rc;
}
int dt_index_read(const struct lu_env *env, struct dt_device *dev,
struct idx_info *ii, const struct lu_rdpg *rdpg)
{
const struct dt_index_features *feat;
struct dt_object *obj;
int rc;
if (rdpg->rp_count <= 0 && (rdpg->rp_count & (LU_PAGE_SIZE - 1)) != 0)
return -EFAULT;
if (fid_seq(&ii->ii_fid) >= FID_SEQ_NORMAL)
return -EOPNOTSUPP;
if (!fid_is_quota(&ii->ii_fid))
return -EPERM;
obj = dt_locate(env, dev, &ii->ii_fid);
if (IS_ERR(obj))
return PTR_ERR(obj);
if (dt_object_exists(obj) == 0)
GOTO(out, rc = -ENOENT);
feat = dt_index_feat_select(fid_seq(&ii->ii_fid),
lu_object_attr(&obj->do_lu));
if (IS_ERR(feat))
GOTO(out, rc = PTR_ERR(feat));
if (obj->do_index_ops == NULL) {
rc = obj->do_ops->do_index_try(env, obj, feat);
if (rc)
GOTO(out, rc);
}
ii->ii_flags &= II_FL_NOHASH;
ii->ii_keysize = feat->dif_keysize_max;
if ((feat->dif_flags & DT_IND_VARKEY) != 0) {
ii->ii_flags |= II_FL_VARKEY;
GOTO(out, rc = -EOPNOTSUPP);
}
ii->ii_recsize = feat->dif_recsize_max;
if ((feat->dif_flags & DT_IND_VARREC) != 0) {
ii->ii_flags |= II_FL_VARREC;
GOTO(out, rc = -EOPNOTSUPP);
}
if ((feat->dif_flags & DT_IND_NONUNQ) != 0)
ii->ii_flags |= II_FL_NONUNQ;
dt_read_lock(env, obj, 0);
ii->ii_version = dt_version_get(env, obj);
rc = dt_index_walk(env, obj, rdpg, dt_index_page_build ,ii);
dt_read_unlock(env, obj);
if (rc == 0) {
LASSERT(ii->ii_count == 0);
ii->ii_hash_end = II_END_OFF;
}
GOTO(out, rc);
out:
lu_object_put(env, &obj->do_lu);
return rc;
}
int lprocfs_dt_rd_blksize(char *page, char **start, off_t off,
int count, int *eof, void *data)
{
struct dt_device *dt = data;
struct obd_statfs osfs;
int rc = dt_statfs(NULL, dt, &osfs);
if (rc == 0) {
*eof = 1;
rc = snprintf(page, count, "%u\n",
(unsigned) osfs.os_bsize);
}
return rc;
}
int lprocfs_dt_rd_kbytestotal(char *page, char **start, off_t off,
int count, int *eof, void *data)
{
struct dt_device *dt = data;
struct obd_statfs osfs;
int rc = dt_statfs(NULL, dt, &osfs);
if (rc == 0) {
__u32 blk_size = osfs.os_bsize >> 10;
__u64 result = osfs.os_blocks;
while (blk_size >>= 1)
result <<= 1;
*eof = 1;
rc = snprintf(page, count, LPU64"\n", result);
}
return rc;
}
int lprocfs_dt_rd_kbytesfree(char *page, char **start, off_t off,
int count, int *eof, void *data)
{
struct dt_device *dt = data;
struct obd_statfs osfs;
int rc = dt_statfs(NULL, dt, &osfs);
if (rc == 0) {
__u32 blk_size = osfs.os_bsize >> 10;
__u64 result = osfs.os_bfree;
while (blk_size >>= 1)
result <<= 1;
*eof = 1;
rc = snprintf(page, count, LPU64"\n", result);
}
return rc;
}
int lprocfs_dt_rd_kbytesavail(char *page, char **start, off_t off,
int count, int *eof, void *data)
{
struct dt_device *dt = data;
struct obd_statfs osfs;
int rc = dt_statfs(NULL, dt, &osfs);
if (rc == 0) {
__u32 blk_size = osfs.os_bsize >> 10;
__u64 result = osfs.os_bavail;
while (blk_size >>= 1)
result <<= 1;
*eof = 1;
rc = snprintf(page, count, LPU64"\n", result);
}
return rc;
}
int lprocfs_dt_rd_filestotal(char *page, char **start, off_t off,
int count, int *eof, void *data)
{
struct dt_device *dt = data;
struct obd_statfs osfs;
int rc = dt_statfs(NULL, dt, &osfs);
if (rc == 0) {
*eof = 1;
rc = snprintf(page, count, LPU64"\n", osfs.os_files);
}
return rc;
}
int lprocfs_dt_rd_filesfree(char *page, char **start, off_t off,
int count, int *eof, void *data)
{
struct dt_device *dt = data;
struct obd_statfs osfs;
int rc = dt_statfs(NULL, dt, &osfs);
if (rc == 0) {
*eof = 1;
rc = snprintf(page, count, LPU64"\n", osfs.os_ffree);
}
return rc;
}
