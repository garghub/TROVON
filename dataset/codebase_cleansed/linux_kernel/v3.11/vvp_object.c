static int vvp_object_print(const struct lu_env *env, void *cookie,
lu_printer_t p, const struct lu_object *o)
{
struct ccc_object *obj = lu2ccc(o);
struct inode *inode = obj->cob_inode;
struct ll_inode_info *lli;
(*p)(env, cookie, "(%s %d %d) inode: %p ",
list_empty(&obj->cob_pending_list) ? "-" : "+",
obj->cob_transient_pages, atomic_read(&obj->cob_mmap_cnt),
inode);
if (inode) {
lli = ll_i2info(inode);
(*p)(env, cookie, "%lu/%u %o %u %d %p "DFID,
inode->i_ino, inode->i_generation, inode->i_mode,
inode->i_nlink, atomic_read(&inode->i_count),
lli->lli_clob, PFID(&lli->lli_fid));
}
return 0;
}
static int vvp_attr_get(const struct lu_env *env, struct cl_object *obj,
struct cl_attr *attr)
{
struct inode *inode = ccc_object_inode(obj);
attr->cat_size = i_size_read(inode);
attr->cat_mtime = LTIME_S(inode->i_mtime);
attr->cat_atime = LTIME_S(inode->i_atime);
attr->cat_ctime = LTIME_S(inode->i_ctime);
attr->cat_blocks = inode->i_blocks;
attr->cat_uid = inode->i_uid;
attr->cat_gid = inode->i_gid;
return 0;
}
static int vvp_attr_set(const struct lu_env *env, struct cl_object *obj,
const struct cl_attr *attr, unsigned valid)
{
struct inode *inode = ccc_object_inode(obj);
if (valid & CAT_UID)
inode->i_uid = attr->cat_uid;
if (valid & CAT_GID)
inode->i_gid = attr->cat_gid;
if (valid & CAT_ATIME)
LTIME_S(inode->i_atime) = attr->cat_atime;
if (valid & CAT_MTIME)
LTIME_S(inode->i_mtime) = attr->cat_mtime;
if (valid & CAT_CTIME)
LTIME_S(inode->i_ctime) = attr->cat_ctime;
if (0 && valid & CAT_SIZE)
cl_isize_write_nolock(inode, attr->cat_size);
if (0 && valid & (CAT_UID|CAT_GID|CAT_SIZE))
mark_inode_dirty(inode);
return 0;
}
int vvp_conf_set(const struct lu_env *env, struct cl_object *obj,
const struct cl_object_conf *conf)
{
struct ll_inode_info *lli = ll_i2info(conf->coc_inode);
if (conf->coc_opc == OBJECT_CONF_INVALIDATE) {
lli->lli_layout_gen = LL_LAYOUT_GEN_NONE;
return 0;
}
if (conf->coc_opc != OBJECT_CONF_SET)
return 0;
if (conf->u.coc_md != NULL && conf->u.coc_md->lsm != NULL) {
CDEBUG(D_VFSTRACE, "layout lock change: %u -> %u\n",
lli->lli_layout_gen,
conf->u.coc_md->lsm->lsm_layout_gen);
lli->lli_has_smd = true;
lli->lli_layout_gen = conf->u.coc_md->lsm->lsm_layout_gen;
} else {
CDEBUG(D_VFSTRACE, "layout lock destroyed: %u.\n",
lli->lli_layout_gen);
lli->lli_has_smd = false;
lli->lli_layout_gen = LL_LAYOUT_GEN_EMPTY;
}
return 0;
}
struct ccc_object *cl_inode2ccc(struct inode *inode)
{
struct cl_inode_info *lli = cl_i2info(inode);
struct cl_object *obj = lli->lli_clob;
struct lu_object *lu;
LASSERT(obj != NULL);
lu = lu_object_locate(obj->co_lu.lo_header, &vvp_device_type);
LASSERT(lu != NULL);
return lu2ccc(lu);
}
struct lu_object *vvp_object_alloc(const struct lu_env *env,
const struct lu_object_header *hdr,
struct lu_device *dev)
{
return ccc_object_alloc(env, hdr, dev, &vvp_ops, &vvp_lu_obj_ops);
}
