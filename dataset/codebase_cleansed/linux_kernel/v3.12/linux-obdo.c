void obdo_from_la(struct obdo *dst, struct lu_attr *la, __u64 valid)
{
obd_flag newvalid = 0;
if (valid & LA_ATIME) {
dst->o_atime = la->la_atime;
newvalid |= OBD_MD_FLATIME;
}
if (valid & LA_MTIME) {
dst->o_mtime = la->la_mtime;
newvalid |= OBD_MD_FLMTIME;
}
if (valid & LA_CTIME) {
dst->o_ctime = la->la_ctime;
newvalid |= OBD_MD_FLCTIME;
}
if (valid & LA_SIZE) {
dst->o_size = la->la_size;
newvalid |= OBD_MD_FLSIZE;
}
if (valid & LA_BLOCKS) {
dst->o_blocks = la->la_blocks;
newvalid |= OBD_MD_FLBLOCKS;
}
if (valid & LA_TYPE) {
dst->o_mode = (dst->o_mode & S_IALLUGO) |
(la->la_mode & S_IFMT);
newvalid |= OBD_MD_FLTYPE;
}
if (valid & LA_MODE) {
dst->o_mode = (dst->o_mode & S_IFMT) |
(la->la_mode & S_IALLUGO);
newvalid |= OBD_MD_FLMODE;
}
if (valid & LA_UID) {
dst->o_uid = la->la_uid;
newvalid |= OBD_MD_FLUID;
}
if (valid & LA_GID) {
dst->o_gid = la->la_gid;
newvalid |= OBD_MD_FLGID;
}
dst->o_valid |= newvalid;
}
void la_from_obdo(struct lu_attr *dst, struct obdo *obdo, obd_flag valid)
{
__u64 newvalid = 0;
valid &= obdo->o_valid;
if (valid & OBD_MD_FLATIME) {
dst->la_atime = obdo->o_atime;
newvalid |= LA_ATIME;
}
if (valid & OBD_MD_FLMTIME) {
dst->la_mtime = obdo->o_mtime;
newvalid |= LA_MTIME;
}
if (valid & OBD_MD_FLCTIME) {
dst->la_ctime = obdo->o_ctime;
newvalid |= LA_CTIME;
}
if (valid & OBD_MD_FLSIZE) {
dst->la_size = obdo->o_size;
newvalid |= LA_SIZE;
}
if (valid & OBD_MD_FLBLOCKS) {
dst->la_blocks = obdo->o_blocks;
newvalid |= LA_BLOCKS;
}
if (valid & OBD_MD_FLTYPE) {
dst->la_mode = (dst->la_mode & S_IALLUGO) |
(obdo->o_mode & S_IFMT);
newvalid |= LA_TYPE;
}
if (valid & OBD_MD_FLMODE) {
dst->la_mode = (dst->la_mode & S_IFMT) |
(obdo->o_mode & S_IALLUGO);
newvalid |= LA_MODE;
}
if (valid & OBD_MD_FLUID) {
dst->la_uid = obdo->o_uid;
newvalid |= LA_UID;
}
if (valid & OBD_MD_FLGID) {
dst->la_gid = obdo->o_gid;
newvalid |= LA_GID;
}
dst->la_valid = newvalid;
}
void obdo_refresh_inode(struct inode *dst, struct obdo *src, obd_flag valid)
{
valid &= src->o_valid;
if (valid & (OBD_MD_FLCTIME | OBD_MD_FLMTIME))
CDEBUG(D_INODE,
"valid "LPX64", cur time %lu/%lu, new "LPU64"/"LPU64"\n",
src->o_valid, LTIME_S(dst->i_mtime),
LTIME_S(dst->i_ctime), src->o_mtime, src->o_ctime);
if (valid & OBD_MD_FLATIME && src->o_atime > LTIME_S(dst->i_atime))
LTIME_S(dst->i_atime) = src->o_atime;
if (valid & OBD_MD_FLMTIME && src->o_mtime > LTIME_S(dst->i_mtime))
LTIME_S(dst->i_mtime) = src->o_mtime;
if (valid & OBD_MD_FLCTIME && src->o_ctime > LTIME_S(dst->i_ctime))
LTIME_S(dst->i_ctime) = src->o_ctime;
if (valid & OBD_MD_FLSIZE)
i_size_write(dst, src->o_size);
if (valid & OBD_MD_FLBLKSZ && src->o_blksize > (1 << dst->i_blkbits))
dst->i_blkbits = ffs(src->o_blksize) - 1;
if (dst->i_blkbits < PAGE_CACHE_SHIFT)
dst->i_blkbits = PAGE_CACHE_SHIFT;
if (valid & OBD_MD_FLBLOCKS && src->o_blocks > dst->i_blocks)
dst->i_blocks = src->o_blocks;
}
void obdo_to_inode(struct inode *dst, struct obdo *src, obd_flag valid)
{
valid &= src->o_valid;
LASSERTF(!(valid & (OBD_MD_FLTYPE | OBD_MD_FLGENER | OBD_MD_FLFID |
OBD_MD_FLID | OBD_MD_FLGROUP)),
"object "DOSTID", valid %x\n", POSTID(&src->o_oi), valid);
if (valid & (OBD_MD_FLCTIME | OBD_MD_FLMTIME))
CDEBUG(D_INODE,
"valid "LPX64", cur time %lu/%lu, new "LPU64"/"LPU64"\n",
src->o_valid, LTIME_S(dst->i_mtime),
LTIME_S(dst->i_ctime), src->o_mtime, src->o_ctime);
if (valid & OBD_MD_FLATIME)
LTIME_S(dst->i_atime) = src->o_atime;
if (valid & OBD_MD_FLMTIME)
LTIME_S(dst->i_mtime) = src->o_mtime;
if (valid & OBD_MD_FLCTIME && src->o_ctime > LTIME_S(dst->i_ctime))
LTIME_S(dst->i_ctime) = src->o_ctime;
if (valid & OBD_MD_FLSIZE)
i_size_write(dst, src->o_size);
if (valid & OBD_MD_FLBLOCKS) {
dst->i_blocks = src->o_blocks;
if (dst->i_blocks < src->o_blocks)
dst->i_blocks = -1;
}
if (valid & OBD_MD_FLBLKSZ)
dst->i_blkbits = ffs(src->o_blksize)-1;
if (valid & OBD_MD_FLMODE)
dst->i_mode = (dst->i_mode & S_IFMT) | (src->o_mode & ~S_IFMT);
if (valid & OBD_MD_FLUID)
dst->i_uid = make_kuid(&init_user_ns, src->o_uid);
if (valid & OBD_MD_FLGID)
dst->i_gid = make_kgid(&init_user_ns, src->o_gid);
if (valid & OBD_MD_FLFLAGS)
dst->i_flags = src->o_flags;
}
