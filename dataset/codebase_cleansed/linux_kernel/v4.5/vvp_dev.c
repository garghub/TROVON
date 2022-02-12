static void *vvp_key_init(const struct lu_context *ctx,
struct lu_context_key *key)
{
struct vvp_thread_info *info;
info = kmem_cache_alloc(vvp_thread_kmem, GFP_NOFS | __GFP_ZERO);
if (info == NULL)
info = ERR_PTR(-ENOMEM);
return info;
}
static void vvp_key_fini(const struct lu_context *ctx,
struct lu_context_key *key, void *data)
{
struct vvp_thread_info *info = data;
kmem_cache_free(vvp_thread_kmem, info);
}
static void *vvp_session_key_init(const struct lu_context *ctx,
struct lu_context_key *key)
{
struct vvp_session *session;
session = kmem_cache_alloc(vvp_session_kmem, GFP_NOFS | __GFP_ZERO);
if (session == NULL)
session = ERR_PTR(-ENOMEM);
return session;
}
static void vvp_session_key_fini(const struct lu_context *ctx,
struct lu_context_key *key, void *data)
{
struct vvp_session *session = data;
kmem_cache_free(vvp_session_kmem, session);
}
static struct lu_device *vvp_device_alloc(const struct lu_env *env,
struct lu_device_type *t,
struct lustre_cfg *cfg)
{
return ccc_device_alloc(env, t, cfg, &vvp_lu_ops, &vvp_cl_ops);
}
int vvp_global_init(void)
{
int result;
result = lu_kmem_init(vvp_caches);
if (result == 0) {
result = ccc_global_init(&vvp_device_type);
if (result != 0)
lu_kmem_fini(vvp_caches);
}
return result;
}
void vvp_global_fini(void)
{
ccc_global_fini(&vvp_device_type);
lu_kmem_fini(vvp_caches);
}
int cl_sb_init(struct super_block *sb)
{
struct ll_sb_info *sbi;
struct cl_device *cl;
struct lu_env *env;
int rc = 0;
int refcheck;
sbi = ll_s2sbi(sb);
env = cl_env_get(&refcheck);
if (!IS_ERR(env)) {
cl = cl_type_setup(env, NULL, &vvp_device_type,
sbi->ll_dt_exp->exp_obd->obd_lu_dev);
if (!IS_ERR(cl)) {
cl2ccc_dev(cl)->cdv_sb = sb;
sbi->ll_cl = cl;
sbi->ll_site = cl2lu_dev(cl)->ld_site;
}
cl_env_put(env, &refcheck);
} else
rc = PTR_ERR(env);
return rc;
}
int cl_sb_fini(struct super_block *sb)
{
struct ll_sb_info *sbi;
struct lu_env *env;
struct cl_device *cld;
int refcheck;
int result;
sbi = ll_s2sbi(sb);
env = cl_env_get(&refcheck);
if (!IS_ERR(env)) {
cld = sbi->ll_cl;
if (cld != NULL) {
cl_stack_fini(env, cld);
sbi->ll_cl = NULL;
sbi->ll_site = NULL;
}
cl_env_put(env, &refcheck);
result = 0;
} else {
CERROR("Cannot cleanup cl-stack due to memory shortage.\n");
result = PTR_ERR(env);
}
lu_types_stop();
return result;
}
static void vvp_pgcache_id_unpack(loff_t pos, struct vvp_pgcache_id *id)
{
CLASSERT(sizeof(pos) == sizeof(__u64));
id->vpi_index = pos & 0xffffffff;
id->vpi_depth = (pos >> PGC_DEPTH_SHIFT) & 0xf;
id->vpi_bucket = (unsigned long long)pos >> PGC_OBJ_SHIFT;
}
static loff_t vvp_pgcache_id_pack(struct vvp_pgcache_id *id)
{
return
((__u64)id->vpi_index) |
((__u64)id->vpi_depth << PGC_DEPTH_SHIFT) |
((__u64)id->vpi_bucket << PGC_OBJ_SHIFT);
}
static int vvp_pgcache_obj_get(struct cfs_hash *hs, struct cfs_hash_bd *bd,
struct hlist_node *hnode, void *data)
{
struct vvp_pgcache_id *id = data;
struct lu_object_header *hdr = cfs_hash_object(hs, hnode);
if (id->vpi_curdep-- > 0)
return 0;
if (lu_object_is_dying(hdr))
return 1;
cfs_hash_get(hs, hnode);
id->vpi_obj = hdr;
return 1;
}
static struct cl_object *vvp_pgcache_obj(const struct lu_env *env,
struct lu_device *dev,
struct vvp_pgcache_id *id)
{
LASSERT(lu_device_is_cl(dev));
id->vpi_depth &= 0xf;
id->vpi_obj = NULL;
id->vpi_curdep = id->vpi_depth;
cfs_hash_hlist_for_each(dev->ld_site->ls_obj_hash, id->vpi_bucket,
vvp_pgcache_obj_get, id);
if (id->vpi_obj != NULL) {
struct lu_object *lu_obj;
lu_obj = lu_object_locate(id->vpi_obj, dev->ld_type);
if (lu_obj != NULL) {
lu_object_ref_add(lu_obj, "dump", current);
return lu2cl(lu_obj);
}
lu_object_put(env, lu_object_top(id->vpi_obj));
} else if (id->vpi_curdep > 0) {
id->vpi_depth = 0xf;
}
return NULL;
}
static loff_t vvp_pgcache_find(const struct lu_env *env,
struct lu_device *dev, loff_t pos)
{
struct cl_object *clob;
struct lu_site *site;
struct vvp_pgcache_id id;
site = dev->ld_site;
vvp_pgcache_id_unpack(pos, &id);
while (1) {
if (id.vpi_bucket >= CFS_HASH_NHLIST(site->ls_obj_hash))
return ~0ULL;
clob = vvp_pgcache_obj(env, dev, &id);
if (clob != NULL) {
struct cl_object_header *hdr;
int nr;
struct cl_page *pg;
hdr = cl_object_header(clob);
spin_lock(&hdr->coh_page_guard);
nr = radix_tree_gang_lookup(&hdr->coh_tree,
(void **)&pg,
id.vpi_index, 1);
if (nr > 0) {
id.vpi_index = pg->cp_index;
nr = !(pg->cp_index > 0xffffffff);
}
spin_unlock(&hdr->coh_page_guard);
lu_object_ref_del(&clob->co_lu, "dump", current);
cl_object_put(env, clob);
if (nr > 0)
return vvp_pgcache_id_pack(&id);
}
++id.vpi_depth;
id.vpi_depth &= 0xf;
if (id.vpi_depth == 0 && ++id.vpi_bucket == 0)
return ~0ULL;
id.vpi_index = 0;
}
}
static void vvp_pgcache_page_show(const struct lu_env *env,
struct seq_file *seq, struct cl_page *page)
{
struct ccc_page *cpg;
struct page *vmpage;
int has_flags;
cpg = cl2ccc_page(cl_page_at(page, &vvp_device_type));
vmpage = cpg->cpg_page;
seq_printf(seq, " %5i | %p %p %s %s %s %s | %p %lu/%u(%p) %lu %u [",
0 ,
cpg, page,
"none",
cpg->cpg_write_queued ? "wq" : "- ",
cpg->cpg_defer_uptodate ? "du" : "- ",
PageWriteback(vmpage) ? "wb" : "-",
vmpage, vmpage->mapping->host->i_ino,
vmpage->mapping->host->i_generation,
vmpage->mapping->host, vmpage->index,
page_count(vmpage));
has_flags = 0;
seq_page_flag(seq, vmpage, locked, has_flags);
seq_page_flag(seq, vmpage, error, has_flags);
seq_page_flag(seq, vmpage, referenced, has_flags);
seq_page_flag(seq, vmpage, uptodate, has_flags);
seq_page_flag(seq, vmpage, dirty, has_flags);
seq_page_flag(seq, vmpage, writeback, has_flags);
seq_printf(seq, "%s]\n", has_flags ? "" : "-");
}
static int vvp_pgcache_show(struct seq_file *f, void *v)
{
loff_t pos;
struct ll_sb_info *sbi;
struct cl_object *clob;
struct lu_env *env;
struct cl_page *page;
struct cl_object_header *hdr;
struct vvp_pgcache_id id;
int refcheck;
int result;
env = cl_env_get(&refcheck);
if (!IS_ERR(env)) {
pos = *(loff_t *) v;
vvp_pgcache_id_unpack(pos, &id);
sbi = f->private;
clob = vvp_pgcache_obj(env, &sbi->ll_cl->cd_lu_dev, &id);
if (clob != NULL) {
hdr = cl_object_header(clob);
spin_lock(&hdr->coh_page_guard);
page = cl_page_lookup(hdr, id.vpi_index);
spin_unlock(&hdr->coh_page_guard);
seq_printf(f, "%8x@"DFID": ",
id.vpi_index, PFID(&hdr->coh_lu.loh_fid));
if (page != NULL) {
vvp_pgcache_page_show(env, f, page);
cl_page_put(env, page);
} else
seq_puts(f, "missing\n");
lu_object_ref_del(&clob->co_lu, "dump", current);
cl_object_put(env, clob);
} else
seq_printf(f, "%llx missing\n", pos);
cl_env_put(env, &refcheck);
result = 0;
} else
result = PTR_ERR(env);
return result;
}
static void *vvp_pgcache_start(struct seq_file *f, loff_t *pos)
{
struct ll_sb_info *sbi;
struct lu_env *env;
int refcheck;
sbi = f->private;
env = cl_env_get(&refcheck);
if (!IS_ERR(env)) {
sbi = f->private;
if (sbi->ll_site->ls_obj_hash->hs_cur_bits > 64 - PGC_OBJ_SHIFT)
pos = ERR_PTR(-EFBIG);
else {
*pos = vvp_pgcache_find(env, &sbi->ll_cl->cd_lu_dev,
*pos);
if (*pos == ~0ULL)
pos = NULL;
}
cl_env_put(env, &refcheck);
}
return pos;
}
static void *vvp_pgcache_next(struct seq_file *f, void *v, loff_t *pos)
{
struct ll_sb_info *sbi;
struct lu_env *env;
int refcheck;
env = cl_env_get(&refcheck);
if (!IS_ERR(env)) {
sbi = f->private;
*pos = vvp_pgcache_find(env, &sbi->ll_cl->cd_lu_dev, *pos + 1);
if (*pos == ~0ULL)
pos = NULL;
cl_env_put(env, &refcheck);
}
return pos;
}
static void vvp_pgcache_stop(struct seq_file *f, void *v)
{
}
static int vvp_dump_pgcache_seq_open(struct inode *inode, struct file *filp)
{
struct seq_file *seq;
int rc;
rc = seq_open(filp, &vvp_pgcache_ops);
if (rc)
return rc;
seq = filp->private_data;
seq->private = inode->i_private;
return 0;
}
