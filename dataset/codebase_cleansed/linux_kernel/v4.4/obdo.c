void obdo_set_parent_fid(struct obdo *dst, const struct lu_fid *parent)
{
dst->o_parent_oid = fid_oid(parent);
dst->o_parent_seq = fid_seq(parent);
dst->o_parent_ver = fid_ver(parent);
dst->o_valid |= OBD_MD_FLGENER | OBD_MD_FLFID;
}
void obdo_from_inode(struct obdo *dst, struct inode *src, u32 valid)
{
u32 newvalid = 0;
if (valid & (OBD_MD_FLCTIME | OBD_MD_FLMTIME))
CDEBUG(D_INODE, "valid %x, new time %lu/%lu\n",
valid, LTIME_S(src->i_mtime),
LTIME_S(src->i_ctime));
if (valid & OBD_MD_FLATIME) {
dst->o_atime = LTIME_S(src->i_atime);
newvalid |= OBD_MD_FLATIME;
}
if (valid & OBD_MD_FLMTIME) {
dst->o_mtime = LTIME_S(src->i_mtime);
newvalid |= OBD_MD_FLMTIME;
}
if (valid & OBD_MD_FLCTIME) {
dst->o_ctime = LTIME_S(src->i_ctime);
newvalid |= OBD_MD_FLCTIME;
}
if (valid & OBD_MD_FLSIZE) {
dst->o_size = i_size_read(src);
newvalid |= OBD_MD_FLSIZE;
}
if (valid & OBD_MD_FLBLOCKS) {
dst->o_blocks = src->i_blocks;
newvalid |= OBD_MD_FLBLOCKS;
}
if (valid & OBD_MD_FLBLKSZ) {
dst->o_blksize = 1 << src->i_blkbits;
newvalid |= OBD_MD_FLBLKSZ;
}
if (valid & OBD_MD_FLTYPE) {
dst->o_mode = (dst->o_mode & S_IALLUGO) |
(src->i_mode & S_IFMT);
newvalid |= OBD_MD_FLTYPE;
}
if (valid & OBD_MD_FLMODE) {
dst->o_mode = (dst->o_mode & S_IFMT) |
(src->i_mode & S_IALLUGO);
newvalid |= OBD_MD_FLMODE;
}
if (valid & OBD_MD_FLUID) {
dst->o_uid = from_kuid(&init_user_ns, src->i_uid);
newvalid |= OBD_MD_FLUID;
}
if (valid & OBD_MD_FLGID) {
dst->o_gid = from_kgid(&init_user_ns, src->i_gid);
newvalid |= OBD_MD_FLGID;
}
if (valid & OBD_MD_FLFLAGS) {
dst->o_flags = src->i_flags;
newvalid |= OBD_MD_FLFLAGS;
}
dst->o_valid |= newvalid;
}
void obdo_to_ioobj(struct obdo *oa, struct obd_ioobj *ioobj)
{
ioobj->ioo_oid = oa->o_oi;
if (unlikely(!(oa->o_valid & OBD_MD_FLGROUP)))
ostid_set_seq_mdt0(&ioobj->ioo_oid);
ioobj->ioo_max_brw = 0;
}
static void iattr_from_obdo(struct iattr *attr, struct obdo *oa, u32 valid)
{
valid &= oa->o_valid;
if (valid & (OBD_MD_FLCTIME | OBD_MD_FLMTIME))
CDEBUG(D_INODE, "valid %#llx, new time %llu/%llu\n",
oa->o_valid, oa->o_mtime, oa->o_ctime);
attr->ia_valid = 0;
if (valid & OBD_MD_FLATIME) {
LTIME_S(attr->ia_atime) = oa->o_atime;
attr->ia_valid |= ATTR_ATIME;
}
if (valid & OBD_MD_FLMTIME) {
LTIME_S(attr->ia_mtime) = oa->o_mtime;
attr->ia_valid |= ATTR_MTIME;
}
if (valid & OBD_MD_FLCTIME) {
LTIME_S(attr->ia_ctime) = oa->o_ctime;
attr->ia_valid |= ATTR_CTIME;
}
if (valid & OBD_MD_FLSIZE) {
attr->ia_size = oa->o_size;
attr->ia_valid |= ATTR_SIZE;
}
#if 0
if (valid & OBD_MD_FLTYPE) {
attr->ia_mode = (attr->ia_mode & ~S_IFMT)|(oa->o_mode & S_IFMT);
attr->ia_valid |= ATTR_MODE;
}
#endif
if (valid & OBD_MD_FLMODE) {
attr->ia_mode = (attr->ia_mode & S_IFMT)|(oa->o_mode & ~S_IFMT);
attr->ia_valid |= ATTR_MODE;
if (!in_group_p(make_kgid(&init_user_ns, oa->o_gid)) &&
!capable(CFS_CAP_FSETID))
attr->ia_mode &= ~S_ISGID;
}
if (valid & OBD_MD_FLUID) {
attr->ia_uid = make_kuid(&init_user_ns, oa->o_uid);
attr->ia_valid |= ATTR_UID;
}
if (valid & OBD_MD_FLGID) {
attr->ia_gid = make_kgid(&init_user_ns, oa->o_gid);
attr->ia_valid |= ATTR_GID;
}
}
void md_from_obdo(struct md_op_data *op_data, struct obdo *oa, u32 valid)
{
iattr_from_obdo(&op_data->op_attr, oa, valid);
if (valid & OBD_MD_FLBLOCKS) {
op_data->op_attr_blocks = oa->o_blocks;
op_data->op_attr.ia_valid |= ATTR_BLOCKS;
}
if (valid & OBD_MD_FLFLAGS) {
((struct ll_iattr *)&op_data->op_attr)->ia_attr_flags =
oa->o_flags;
op_data->op_attr.ia_valid |= ATTR_ATTR_FLAG;
}
}
