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
void obdo_to_ioobj(const struct obdo *oa, struct obd_ioobj *ioobj)
{
ioobj->ioo_oid = oa->o_oi;
if (unlikely(!(oa->o_valid & OBD_MD_FLGROUP)))
ostid_set_seq_mdt0(&ioobj->ioo_oid);
ioobj->ioo_max_brw = 0;
}
void lustre_set_wire_obdo(const struct obd_connect_data *ocd,
struct obdo *wobdo, const struct obdo *lobdo)
{
*wobdo = *lobdo;
wobdo->o_flags &= ~OBD_FL_LOCAL_MASK;
if (!ocd)
return;
if (unlikely(!(ocd->ocd_connect_flags & OBD_CONNECT_FID)) &&
fid_seq_is_echo(ostid_seq(&lobdo->o_oi))) {
wobdo->o_oi.oi.oi_id = fid_oid(&lobdo->o_oi.oi_fid);
wobdo->o_oi.oi.oi_seq = fid_seq(&lobdo->o_oi.oi_fid);
}
}
void lustre_get_wire_obdo(const struct obd_connect_data *ocd,
struct obdo *lobdo, const struct obdo *wobdo)
{
u32 local_flags = 0;
if (lobdo->o_valid & OBD_MD_FLFLAGS)
local_flags = lobdo->o_flags & OBD_FL_LOCAL_MASK;
*lobdo = *wobdo;
if (local_flags) {
lobdo->o_valid |= OBD_MD_FLFLAGS;
lobdo->o_flags &= ~OBD_FL_LOCAL_MASK;
lobdo->o_flags |= local_flags;
}
if (!ocd)
return;
if (unlikely(!(ocd->ocd_connect_flags & OBD_CONNECT_FID)) &&
fid_seq_is_echo(wobdo->o_oi.oi.oi_seq)) {
lobdo->o_oi.oi_fid.f_seq = wobdo->o_oi.oi.oi_seq;
lobdo->o_oi.oi_fid.f_oid = wobdo->o_oi.oi.oi_id;
lobdo->o_oi.oi_fid.f_ver = 0;
}
}
