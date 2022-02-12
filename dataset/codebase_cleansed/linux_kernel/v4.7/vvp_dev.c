static void *ll_thread_key_init(const struct lu_context *ctx,
struct lu_context_key *key)
{
struct vvp_thread_info *info;
info = kmem_cache_zalloc(ll_thread_kmem, GFP_NOFS);
if (!info)
info = ERR_PTR(-ENOMEM);
return info;
}
static void ll_thread_key_fini(const struct lu_context *ctx,
struct lu_context_key *key, void *data)
{
struct vvp_thread_info *info = data;
kmem_cache_free(ll_thread_kmem, info);
}
static void *vvp_session_key_init(const struct lu_context *ctx,
struct lu_context_key *key)
{
struct vvp_session *session;
session = kmem_cache_zalloc(vvp_session_kmem, GFP_NOFS);
if (!session)
session = ERR_PTR(-ENOMEM);
return session;
}
static void vvp_session_key_fini(const struct lu_context *ctx,
struct lu_context_key *key, void *data)
{
struct vvp_session *session = data;
kmem_cache_free(vvp_session_kmem, session);
}
void *vvp_thread_key_init(const struct lu_context *ctx,
struct lu_context_key *key)
{
struct vvp_thread_info *vti;
vti = kmem_cache_zalloc(vvp_thread_kmem, GFP_NOFS);
if (!vti)
vti = ERR_PTR(-ENOMEM);
return vti;
}
void vvp_thread_key_fini(const struct lu_context *ctx,
struct lu_context_key *key, void *data)
{
struct vvp_thread_info *vti = data;
kmem_cache_free(vvp_thread_kmem, vti);
}
static struct lu_device *vvp_device_free(const struct lu_env *env,
struct lu_device *d)
{
struct vvp_device *vdv = lu2vvp_dev(d);
struct cl_site *site = lu2cl_site(d->ld_site);
struct lu_device *next = cl2lu_dev(vdv->vdv_next);
if (d->ld_site) {
cl_site_fini(site);
kfree(site);
}
cl_device_fini(lu2cl_dev(d));
kfree(vdv);
return next;
}
static struct lu_device *vvp_device_alloc(const struct lu_env *env,
struct lu_device_type *t,
struct lustre_cfg *cfg)
{
struct vvp_device *vdv;
struct lu_device *lud;
struct cl_site *site;
int rc;
vdv = kzalloc(sizeof(*vdv), GFP_NOFS);
if (!vdv)
return ERR_PTR(-ENOMEM);
lud = &vdv->vdv_cl.cd_lu_dev;
cl_device_init(&vdv->vdv_cl, t);
vvp2lu_dev(vdv)->ld_ops = &vvp_lu_ops;
vdv->vdv_cl.cd_ops = &vvp_cl_ops;
site = kzalloc(sizeof(*site), GFP_NOFS);
if (site) {
rc = cl_site_init(site, &vdv->vdv_cl);
if (rc == 0) {
rc = lu_site_init_finish(&site->cs_lu);
} else {
LASSERT(!lud->ld_site);
CERROR("Cannot init lu_site, rc %d.\n", rc);
kfree(site);
}
} else {
rc = -ENOMEM;
}
if (rc != 0) {
vvp_device_free(env, lud);
lud = ERR_PTR(rc);
}
return lud;
}
static int vvp_device_init(const struct lu_env *env, struct lu_device *d,
const char *name, struct lu_device *next)
{
struct vvp_device *vdv;
int rc;
vdv = lu2vvp_dev(d);
vdv->vdv_next = lu2cl_dev(next);
LASSERT(d->ld_site && next->ld_type);
next->ld_site = d->ld_site;
rc = next->ld_type->ldt_ops->ldto_device_init(env, next,
next->ld_type->ldt_name,
NULL);
if (rc == 0) {
lu_device_get(next);
lu_ref_add(&next->ld_reference, "lu-stack", &lu_site_init);
}
return rc;
}
static struct lu_device *vvp_device_fini(const struct lu_env *env,
struct lu_device *d)
{
return cl2lu_dev(lu2vvp_dev(d)->vdv_next);
}
int vvp_global_init(void)
{
int rc;
rc = lu_kmem_init(vvp_caches);
if (rc != 0)
return rc;
rc = lu_device_type_init(&vvp_device_type);
if (rc != 0)
goto out_kmem;
return 0;
out_kmem:
lu_kmem_fini(vvp_caches);
return rc;
}
void vvp_global_fini(void)
{
lu_device_type_fini(&vvp_device_type);
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
cl2vvp_dev(cl)->vdv_sb = sb;
sbi->ll_cl = cl;
sbi->ll_site = cl2lu_dev(cl)->ld_site;
}
cl_env_put(env, &refcheck);
} else {
rc = PTR_ERR(env);
}
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
if (cld) {
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
if (id->vpi_obj) {
struct lu_object *lu_obj;
lu_obj = lu_object_locate(id->vpi_obj, dev->ld_type);
if (lu_obj) {
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
if (clob) {
struct inode *inode = vvp_object_inode(clob);
struct page *vmpage;
int nr;
nr = find_get_pages_contig(inode->i_mapping,
id.vpi_index, 1, &vmpage);
if (nr > 0) {
id.vpi_index = vmpage->index;
nr = !(vmpage->index > 0xffffffff);
put_page(vmpage);
}
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
struct vvp_page *vpg;
struct page *vmpage;
int has_flags;
vpg = cl2vvp_page(cl_page_at(page, &vvp_device_type));
vmpage = vpg->vpg_page;
seq_printf(seq, " %5i | %p %p %s %s %s %s | %p "DFID"(%p) %lu %u [",
0 ,
vpg, page,
"none",
vpg->vpg_write_queued ? "wq" : "- ",
vpg->vpg_defer_uptodate ? "du" : "- ",
PageWriteback(vmpage) ? "wb" : "-",
vmpage, PFID(ll_inode2fid(vmpage->mapping->host)),
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
struct vvp_pgcache_id id;
int refcheck;
int result;
env = cl_env_get(&refcheck);
if (!IS_ERR(env)) {
pos = *(loff_t *) v;
vvp_pgcache_id_unpack(pos, &id);
sbi = f->private;
clob = vvp_pgcache_obj(env, &sbi->ll_cl->cd_lu_dev, &id);
if (clob) {
struct inode *inode = vvp_object_inode(clob);
struct cl_page *page = NULL;
struct page *vmpage;
result = find_get_pages_contig(inode->i_mapping,
id.vpi_index, 1,
&vmpage);
if (result > 0) {
lock_page(vmpage);
page = cl_vmpage_page(vmpage, clob);
unlock_page(vmpage);
put_page(vmpage);
}
seq_printf(f, "%8x@" DFID ": ", id.vpi_index,
PFID(lu_object_fid(&clob->co_lu)));
if (page) {
vvp_pgcache_page_show(env, f, page);
cl_page_put(env, page);
} else {
seq_puts(f, "missing\n");
}
lu_object_ref_del(&clob->co_lu, "dump", current);
cl_object_put(env, clob);
} else {
seq_printf(f, "%llx missing\n", pos);
}
cl_env_put(env, &refcheck);
result = 0;
} else {
result = PTR_ERR(env);
}
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
