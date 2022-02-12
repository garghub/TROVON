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
void obdo_cpy_md(struct obdo *dst, struct obdo *src, u32 valid)
{
CDEBUG(D_INODE, "src obdo "DOSTID" valid %#llx, dst obdo "DOSTID"\n",
POSTID(&src->o_oi), src->o_valid, POSTID(&dst->o_oi));
if (valid & OBD_MD_FLATIME)
dst->o_atime = src->o_atime;
if (valid & OBD_MD_FLMTIME)
dst->o_mtime = src->o_mtime;
if (valid & OBD_MD_FLCTIME)
dst->o_ctime = src->o_ctime;
if (valid & OBD_MD_FLSIZE)
dst->o_size = src->o_size;
if (valid & OBD_MD_FLBLOCKS)
dst->o_blocks = src->o_blocks;
if (valid & OBD_MD_FLBLKSZ)
dst->o_blksize = src->o_blksize;
if (valid & OBD_MD_FLTYPE)
dst->o_mode = (dst->o_mode & ~S_IFMT) | (src->o_mode & S_IFMT);
if (valid & OBD_MD_FLMODE)
dst->o_mode = (dst->o_mode & S_IFMT) | (src->o_mode & ~S_IFMT);
if (valid & OBD_MD_FLUID)
dst->o_uid = src->o_uid;
if (valid & OBD_MD_FLGID)
dst->o_gid = src->o_gid;
if (valid & OBD_MD_FLFLAGS)
dst->o_flags = src->o_flags;
if (valid & OBD_MD_FLFID) {
dst->o_parent_seq = src->o_parent_seq;
dst->o_parent_ver = src->o_parent_ver;
}
if (valid & OBD_MD_FLGENER)
dst->o_parent_oid = src->o_parent_oid;
if (valid & OBD_MD_FLHANDLE)
dst->o_handle = src->o_handle;
if (valid & OBD_MD_FLCOOKIE)
dst->o_lcookie = src->o_lcookie;
dst->o_valid |= valid;
}
int obdo_cmp_md(struct obdo *dst, struct obdo *src, u32 compare)
{
int res = 0;
if (compare & OBD_MD_FLATIME)
res |= dst->o_atime != src->o_atime;
if (compare & OBD_MD_FLMTIME)
res |= dst->o_mtime != src->o_mtime;
if (compare & OBD_MD_FLCTIME)
res |= dst->o_ctime != src->o_ctime;
if (compare & OBD_MD_FLSIZE)
res |= dst->o_size != src->o_size;
if (compare & OBD_MD_FLBLOCKS)
res |= dst->o_blocks != src->o_blocks;
if (compare & OBD_MD_FLBLKSZ)
res |= dst->o_blksize != src->o_blksize;
if (compare & OBD_MD_FLTYPE)
res |= ((dst->o_mode ^ src->o_mode) & S_IFMT) != 0;
if (compare & OBD_MD_FLMODE)
res |= ((dst->o_mode ^ src->o_mode) & ~S_IFMT) != 0;
if (compare & OBD_MD_FLUID)
res |= dst->o_uid != src->o_uid;
if (compare & OBD_MD_FLGID)
res |= dst->o_gid != src->o_gid;
if (compare & OBD_MD_FLFLAGS)
res |= dst->o_flags != src->o_flags;
if (compare & OBD_MD_FLNLINK)
res |= dst->o_nlink != src->o_nlink;
if (compare & OBD_MD_FLFID) {
res |= dst->o_parent_seq != src->o_parent_seq;
res |= dst->o_parent_ver != src->o_parent_ver;
}
if (compare & OBD_MD_FLGENER)
res |= dst->o_parent_oid != src->o_parent_oid;
return res;
}
void obdo_to_ioobj(struct obdo *oa, struct obd_ioobj *ioobj)
{
ioobj->ioo_oid = oa->o_oi;
if (unlikely(!(oa->o_valid & OBD_MD_FLGROUP)))
ostid_set_seq_mdt0(&ioobj->ioo_oid);
ioobj->ioo_max_brw = 0;
}
void obdo_from_iattr(struct obdo *oa, struct iattr *attr, unsigned int ia_valid)
{
if (ia_valid & ATTR_ATIME) {
oa->o_atime = LTIME_S(attr->ia_atime);
oa->o_valid |= OBD_MD_FLATIME;
}
if (ia_valid & ATTR_MTIME) {
oa->o_mtime = LTIME_S(attr->ia_mtime);
oa->o_valid |= OBD_MD_FLMTIME;
}
if (ia_valid & ATTR_CTIME) {
oa->o_ctime = LTIME_S(attr->ia_ctime);
oa->o_valid |= OBD_MD_FLCTIME;
}
if (ia_valid & ATTR_SIZE) {
oa->o_size = attr->ia_size;
oa->o_valid |= OBD_MD_FLSIZE;
}
if (ia_valid & ATTR_MODE) {
oa->o_mode = attr->ia_mode;
oa->o_valid |= OBD_MD_FLTYPE | OBD_MD_FLMODE;
if (!in_group_p(make_kgid(&init_user_ns, oa->o_gid)) &&
!capable(CFS_CAP_FSETID))
oa->o_mode &= ~S_ISGID;
}
if (ia_valid & ATTR_UID) {
oa->o_uid = from_kuid(&init_user_ns, attr->ia_uid);
oa->o_valid |= OBD_MD_FLUID;
}
if (ia_valid & ATTR_GID) {
oa->o_gid = from_kgid(&init_user_ns, attr->ia_gid);
oa->o_valid |= OBD_MD_FLGID;
}
}
void iattr_from_obdo(struct iattr *attr, struct obdo *oa, u32 valid)
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
void obdo_from_md(struct obdo *oa, struct md_op_data *op_data,
unsigned int valid)
{
obdo_from_iattr(oa, &op_data->op_attr, valid);
if (valid & ATTR_BLOCKS) {
oa->o_blocks = op_data->op_attr_blocks;
oa->o_valid |= OBD_MD_FLBLOCKS;
}
if (valid & ATTR_ATTR_FLAG) {
oa->o_flags =
((struct ll_iattr *)&op_data->op_attr)->ia_attr_flags;
oa->o_valid |= OBD_MD_FLFLAGS;
}
}
void obdo_cpu_to_le(struct obdo *dobdo, struct obdo *sobdo)
{
dobdo->o_size = cpu_to_le64(sobdo->o_size);
dobdo->o_mtime = cpu_to_le64(sobdo->o_mtime);
dobdo->o_atime = cpu_to_le64(sobdo->o_atime);
dobdo->o_ctime = cpu_to_le64(sobdo->o_ctime);
dobdo->o_blocks = cpu_to_le64(sobdo->o_blocks);
dobdo->o_mode = cpu_to_le32(sobdo->o_mode);
dobdo->o_uid = cpu_to_le32(sobdo->o_uid);
dobdo->o_gid = cpu_to_le32(sobdo->o_gid);
dobdo->o_flags = cpu_to_le32(sobdo->o_flags);
dobdo->o_nlink = cpu_to_le32(sobdo->o_nlink);
dobdo->o_blksize = cpu_to_le32(sobdo->o_blksize);
dobdo->o_valid = cpu_to_le64(sobdo->o_valid);
}
void obdo_le_to_cpu(struct obdo *dobdo, struct obdo *sobdo)
{
dobdo->o_size = le64_to_cpu(sobdo->o_size);
dobdo->o_mtime = le64_to_cpu(sobdo->o_mtime);
dobdo->o_atime = le64_to_cpu(sobdo->o_atime);
dobdo->o_ctime = le64_to_cpu(sobdo->o_ctime);
dobdo->o_blocks = le64_to_cpu(sobdo->o_blocks);
dobdo->o_mode = le32_to_cpu(sobdo->o_mode);
dobdo->o_uid = le32_to_cpu(sobdo->o_uid);
dobdo->o_gid = le32_to_cpu(sobdo->o_gid);
dobdo->o_flags = le32_to_cpu(sobdo->o_flags);
dobdo->o_nlink = le32_to_cpu(sobdo->o_nlink);
dobdo->o_blksize = le32_to_cpu(sobdo->o_blksize);
dobdo->o_valid = le64_to_cpu(sobdo->o_valid);
}
