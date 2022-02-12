void
xfs_validate_extents(
xfs_ifork_t *ifp,
int nrecs,
xfs_exntfmt_t fmt)
{
xfs_bmbt_irec_t irec;
xfs_bmbt_rec_host_t rec;
int i;
for (i = 0; i < nrecs; i++) {
xfs_bmbt_rec_host_t *ep = xfs_iext_get_ext(ifp, i);
rec.l0 = get_unaligned(&ep->l0);
rec.l1 = get_unaligned(&ep->l1);
xfs_bmbt_get_all(&rec, &irec);
if (fmt == XFS_EXTFMT_NOSTATE)
ASSERT(irec.br_state == XFS_EXT_NORM);
}
}
int
xfs_iformat_fork(
xfs_inode_t *ip,
xfs_dinode_t *dip)
{
xfs_attr_shortform_t *atp;
int size;
int error = 0;
xfs_fsize_t di_size;
if (unlikely(be32_to_cpu(dip->di_nextents) +
be16_to_cpu(dip->di_anextents) >
be64_to_cpu(dip->di_nblocks))) {
xfs_warn(ip->i_mount,
"corrupt dinode %Lu, extent total = %d, nblocks = %Lu.",
(unsigned long long)ip->i_ino,
(int)(be32_to_cpu(dip->di_nextents) +
be16_to_cpu(dip->di_anextents)),
(unsigned long long)
be64_to_cpu(dip->di_nblocks));
XFS_CORRUPTION_ERROR("xfs_iformat(1)", XFS_ERRLEVEL_LOW,
ip->i_mount, dip);
return -EFSCORRUPTED;
}
if (unlikely(dip->di_forkoff > ip->i_mount->m_sb.sb_inodesize)) {
xfs_warn(ip->i_mount, "corrupt dinode %Lu, forkoff = 0x%x.",
(unsigned long long)ip->i_ino,
dip->di_forkoff);
XFS_CORRUPTION_ERROR("xfs_iformat(2)", XFS_ERRLEVEL_LOW,
ip->i_mount, dip);
return -EFSCORRUPTED;
}
if (unlikely((ip->i_d.di_flags & XFS_DIFLAG_REALTIME) &&
!ip->i_mount->m_rtdev_targp)) {
xfs_warn(ip->i_mount,
"corrupt dinode %Lu, has realtime flag set.",
ip->i_ino);
XFS_CORRUPTION_ERROR("xfs_iformat(realtime)",
XFS_ERRLEVEL_LOW, ip->i_mount, dip);
return -EFSCORRUPTED;
}
if (unlikely(xfs_is_reflink_inode(ip) &&
(VFS_I(ip)->i_mode & S_IFMT) != S_IFREG)) {
xfs_warn(ip->i_mount,
"corrupt dinode %llu, wrong file type for reflink.",
ip->i_ino);
XFS_CORRUPTION_ERROR("xfs_iformat(reflink)",
XFS_ERRLEVEL_LOW, ip->i_mount, dip);
return -EFSCORRUPTED;
}
if (unlikely(xfs_is_reflink_inode(ip) &&
(ip->i_d.di_flags & XFS_DIFLAG_REALTIME))) {
xfs_warn(ip->i_mount,
"corrupt dinode %llu, has reflink+realtime flag set.",
ip->i_ino);
XFS_CORRUPTION_ERROR("xfs_iformat(reflink)",
XFS_ERRLEVEL_LOW, ip->i_mount, dip);
return -EFSCORRUPTED;
}
switch (VFS_I(ip)->i_mode & S_IFMT) {
case S_IFIFO:
case S_IFCHR:
case S_IFBLK:
case S_IFSOCK:
if (unlikely(dip->di_format != XFS_DINODE_FMT_DEV)) {
XFS_CORRUPTION_ERROR("xfs_iformat(3)", XFS_ERRLEVEL_LOW,
ip->i_mount, dip);
return -EFSCORRUPTED;
}
ip->i_d.di_size = 0;
ip->i_df.if_u2.if_rdev = xfs_dinode_get_rdev(dip);
break;
case S_IFREG:
case S_IFLNK:
case S_IFDIR:
switch (dip->di_format) {
case XFS_DINODE_FMT_LOCAL:
if (unlikely(S_ISREG(be16_to_cpu(dip->di_mode)))) {
xfs_warn(ip->i_mount,
"corrupt inode %Lu (local format for regular file).",
(unsigned long long) ip->i_ino);
XFS_CORRUPTION_ERROR("xfs_iformat(4)",
XFS_ERRLEVEL_LOW,
ip->i_mount, dip);
return -EFSCORRUPTED;
}
di_size = be64_to_cpu(dip->di_size);
if (unlikely(di_size < 0 ||
di_size > XFS_DFORK_DSIZE(dip, ip->i_mount))) {
xfs_warn(ip->i_mount,
"corrupt inode %Lu (bad size %Ld for local inode).",
(unsigned long long) ip->i_ino,
(long long) di_size);
XFS_CORRUPTION_ERROR("xfs_iformat(5)",
XFS_ERRLEVEL_LOW,
ip->i_mount, dip);
return -EFSCORRUPTED;
}
size = (int)di_size;
error = xfs_iformat_local(ip, dip, XFS_DATA_FORK, size);
break;
case XFS_DINODE_FMT_EXTENTS:
error = xfs_iformat_extents(ip, dip, XFS_DATA_FORK);
break;
case XFS_DINODE_FMT_BTREE:
error = xfs_iformat_btree(ip, dip, XFS_DATA_FORK);
break;
default:
XFS_ERROR_REPORT("xfs_iformat(6)", XFS_ERRLEVEL_LOW,
ip->i_mount);
return -EFSCORRUPTED;
}
break;
default:
XFS_ERROR_REPORT("xfs_iformat(7)", XFS_ERRLEVEL_LOW, ip->i_mount);
return -EFSCORRUPTED;
}
if (error)
return error;
if (xfs_is_reflink_inode(ip)) {
ASSERT(ip->i_cowfp == NULL);
xfs_ifork_init_cow(ip);
}
if (!XFS_DFORK_Q(dip))
return 0;
ASSERT(ip->i_afp == NULL);
ip->i_afp = kmem_zone_zalloc(xfs_ifork_zone, KM_SLEEP | KM_NOFS);
switch (dip->di_aformat) {
case XFS_DINODE_FMT_LOCAL:
atp = (xfs_attr_shortform_t *)XFS_DFORK_APTR(dip);
size = be16_to_cpu(atp->hdr.totsize);
if (unlikely(size < sizeof(struct xfs_attr_sf_hdr))) {
xfs_warn(ip->i_mount,
"corrupt inode %Lu (bad attr fork size %Ld).",
(unsigned long long) ip->i_ino,
(long long) size);
XFS_CORRUPTION_ERROR("xfs_iformat(8)",
XFS_ERRLEVEL_LOW,
ip->i_mount, dip);
error = -EFSCORRUPTED;
break;
}
error = xfs_iformat_local(ip, dip, XFS_ATTR_FORK, size);
break;
case XFS_DINODE_FMT_EXTENTS:
error = xfs_iformat_extents(ip, dip, XFS_ATTR_FORK);
break;
case XFS_DINODE_FMT_BTREE:
error = xfs_iformat_btree(ip, dip, XFS_ATTR_FORK);
break;
default:
error = -EFSCORRUPTED;
break;
}
if (error) {
kmem_zone_free(xfs_ifork_zone, ip->i_afp);
ip->i_afp = NULL;
if (ip->i_cowfp)
kmem_zone_free(xfs_ifork_zone, ip->i_cowfp);
ip->i_cowfp = NULL;
xfs_idestroy_fork(ip, XFS_DATA_FORK);
}
return error;
}
void
xfs_init_local_fork(
struct xfs_inode *ip,
int whichfork,
const void *data,
int size)
{
struct xfs_ifork *ifp = XFS_IFORK_PTR(ip, whichfork);
int mem_size = size, real_size = 0;
bool zero_terminate;
zero_terminate = S_ISLNK(VFS_I(ip)->i_mode);
if (zero_terminate)
mem_size++;
if (size == 0)
ifp->if_u1.if_data = NULL;
else if (mem_size <= sizeof(ifp->if_u2.if_inline_data))
ifp->if_u1.if_data = ifp->if_u2.if_inline_data;
else {
real_size = roundup(mem_size, 4);
ifp->if_u1.if_data = kmem_alloc(real_size, KM_SLEEP | KM_NOFS);
}
if (size) {
memcpy(ifp->if_u1.if_data, data, size);
if (zero_terminate)
ifp->if_u1.if_data[size] = '\0';
}
ifp->if_bytes = size;
ifp->if_real_bytes = real_size;
ifp->if_flags &= ~(XFS_IFEXTENTS | XFS_IFBROOT);
ifp->if_flags |= XFS_IFINLINE;
}
STATIC int
xfs_iformat_local(
xfs_inode_t *ip,
xfs_dinode_t *dip,
int whichfork,
int size)
{
if (unlikely(size > XFS_DFORK_SIZE(dip, ip->i_mount, whichfork))) {
xfs_warn(ip->i_mount,
"corrupt inode %Lu (bad size %d for local fork, size = %d).",
(unsigned long long) ip->i_ino, size,
XFS_DFORK_SIZE(dip, ip->i_mount, whichfork));
XFS_CORRUPTION_ERROR("xfs_iformat_local", XFS_ERRLEVEL_LOW,
ip->i_mount, dip);
return -EFSCORRUPTED;
}
xfs_init_local_fork(ip, whichfork, XFS_DFORK_PTR(dip, whichfork), size);
return 0;
}
STATIC int
xfs_iformat_extents(
xfs_inode_t *ip,
xfs_dinode_t *dip,
int whichfork)
{
xfs_bmbt_rec_t *dp;
xfs_ifork_t *ifp;
int nex;
int size;
int i;
ifp = XFS_IFORK_PTR(ip, whichfork);
nex = XFS_DFORK_NEXTENTS(dip, whichfork);
size = nex * (uint)sizeof(xfs_bmbt_rec_t);
if (unlikely(size < 0 || size > XFS_DFORK_SIZE(dip, ip->i_mount, whichfork))) {
xfs_warn(ip->i_mount, "corrupt inode %Lu ((a)extents = %d).",
(unsigned long long) ip->i_ino, nex);
XFS_CORRUPTION_ERROR("xfs_iformat_extents(1)", XFS_ERRLEVEL_LOW,
ip->i_mount, dip);
return -EFSCORRUPTED;
}
ifp->if_real_bytes = 0;
if (nex == 0)
ifp->if_u1.if_extents = NULL;
else if (nex <= XFS_INLINE_EXTS)
ifp->if_u1.if_extents = ifp->if_u2.if_inline_ext;
else
xfs_iext_add(ifp, 0, nex);
ifp->if_bytes = size;
if (size) {
dp = (xfs_bmbt_rec_t *) XFS_DFORK_PTR(dip, whichfork);
xfs_validate_extents(ifp, nex, XFS_EXTFMT_INODE(ip));
for (i = 0; i < nex; i++, dp++) {
xfs_bmbt_rec_host_t *ep = xfs_iext_get_ext(ifp, i);
ep->l0 = get_unaligned_be64(&dp->l0);
ep->l1 = get_unaligned_be64(&dp->l1);
}
XFS_BMAP_TRACE_EXLIST(ip, nex, whichfork);
if (whichfork != XFS_DATA_FORK ||
XFS_EXTFMT_INODE(ip) == XFS_EXTFMT_NOSTATE)
if (unlikely(xfs_check_nostate_extents(
ifp, 0, nex))) {
XFS_ERROR_REPORT("xfs_iformat_extents(2)",
XFS_ERRLEVEL_LOW,
ip->i_mount);
return -EFSCORRUPTED;
}
}
ifp->if_flags |= XFS_IFEXTENTS;
return 0;
}
STATIC int
xfs_iformat_btree(
xfs_inode_t *ip,
xfs_dinode_t *dip,
int whichfork)
{
struct xfs_mount *mp = ip->i_mount;
xfs_bmdr_block_t *dfp;
xfs_ifork_t *ifp;
int nrecs;
int size;
ifp = XFS_IFORK_PTR(ip, whichfork);
dfp = (xfs_bmdr_block_t *)XFS_DFORK_PTR(dip, whichfork);
size = XFS_BMAP_BROOT_SPACE(mp, dfp);
nrecs = be16_to_cpu(dfp->bb_numrecs);
if (unlikely(XFS_IFORK_NEXTENTS(ip, whichfork) <=
XFS_IFORK_MAXEXT(ip, whichfork) ||
XFS_BMDR_SPACE_CALC(nrecs) >
XFS_DFORK_SIZE(dip, mp, whichfork) ||
XFS_IFORK_NEXTENTS(ip, whichfork) > ip->i_d.di_nblocks)) {
xfs_warn(mp, "corrupt inode %Lu (btree).",
(unsigned long long) ip->i_ino);
XFS_CORRUPTION_ERROR("xfs_iformat_btree", XFS_ERRLEVEL_LOW,
mp, dip);
return -EFSCORRUPTED;
}
ifp->if_broot_bytes = size;
ifp->if_broot = kmem_alloc(size, KM_SLEEP | KM_NOFS);
ASSERT(ifp->if_broot != NULL);
xfs_bmdr_to_bmbt(ip, dfp, XFS_DFORK_SIZE(dip, ip->i_mount, whichfork),
ifp->if_broot, size);
ifp->if_flags &= ~XFS_IFEXTENTS;
ifp->if_flags |= XFS_IFBROOT;
return 0;
}
int
xfs_iread_extents(
xfs_trans_t *tp,
xfs_inode_t *ip,
int whichfork)
{
int error;
xfs_ifork_t *ifp;
xfs_extnum_t nextents;
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
if (unlikely(XFS_IFORK_FORMAT(ip, whichfork) != XFS_DINODE_FMT_BTREE)) {
XFS_ERROR_REPORT("xfs_iread_extents", XFS_ERRLEVEL_LOW,
ip->i_mount);
return -EFSCORRUPTED;
}
nextents = XFS_IFORK_NEXTENTS(ip, whichfork);
ifp = XFS_IFORK_PTR(ip, whichfork);
ifp->if_bytes = ifp->if_real_bytes = 0;
ifp->if_flags |= XFS_IFEXTENTS;
xfs_iext_add(ifp, 0, nextents);
error = xfs_bmap_read_extents(tp, ip, whichfork);
if (error) {
xfs_iext_destroy(ifp);
ifp->if_flags &= ~XFS_IFEXTENTS;
return error;
}
xfs_validate_extents(ifp, nextents, XFS_EXTFMT_INODE(ip));
return 0;
}
void
xfs_iroot_realloc(
xfs_inode_t *ip,
int rec_diff,
int whichfork)
{
struct xfs_mount *mp = ip->i_mount;
int cur_max;
xfs_ifork_t *ifp;
struct xfs_btree_block *new_broot;
int new_max;
size_t new_size;
char *np;
char *op;
if (rec_diff == 0) {
return;
}
ifp = XFS_IFORK_PTR(ip, whichfork);
if (rec_diff > 0) {
if (ifp->if_broot_bytes == 0) {
new_size = XFS_BMAP_BROOT_SPACE_CALC(mp, rec_diff);
ifp->if_broot = kmem_alloc(new_size, KM_SLEEP | KM_NOFS);
ifp->if_broot_bytes = (int)new_size;
return;
}
cur_max = xfs_bmbt_maxrecs(mp, ifp->if_broot_bytes, 0);
new_max = cur_max + rec_diff;
new_size = XFS_BMAP_BROOT_SPACE_CALC(mp, new_max);
ifp->if_broot = kmem_realloc(ifp->if_broot, new_size,
KM_SLEEP | KM_NOFS);
op = (char *)XFS_BMAP_BROOT_PTR_ADDR(mp, ifp->if_broot, 1,
ifp->if_broot_bytes);
np = (char *)XFS_BMAP_BROOT_PTR_ADDR(mp, ifp->if_broot, 1,
(int)new_size);
ifp->if_broot_bytes = (int)new_size;
ASSERT(XFS_BMAP_BMDR_SPACE(ifp->if_broot) <=
XFS_IFORK_SIZE(ip, whichfork));
memmove(np, op, cur_max * (uint)sizeof(xfs_fsblock_t));
return;
}
ASSERT((ifp->if_broot != NULL) && (ifp->if_broot_bytes > 0));
cur_max = xfs_bmbt_maxrecs(mp, ifp->if_broot_bytes, 0);
new_max = cur_max + rec_diff;
ASSERT(new_max >= 0);
if (new_max > 0)
new_size = XFS_BMAP_BROOT_SPACE_CALC(mp, new_max);
else
new_size = 0;
if (new_size > 0) {
new_broot = kmem_alloc(new_size, KM_SLEEP | KM_NOFS);
memcpy(new_broot, ifp->if_broot,
XFS_BMBT_BLOCK_LEN(ip->i_mount));
} else {
new_broot = NULL;
ifp->if_flags &= ~XFS_IFBROOT;
}
if (new_max > 0) {
op = (char *)XFS_BMBT_REC_ADDR(mp, ifp->if_broot, 1);
np = (char *)XFS_BMBT_REC_ADDR(mp, new_broot, 1);
memcpy(np, op, new_max * (uint)sizeof(xfs_bmbt_rec_t));
op = (char *)XFS_BMAP_BROOT_PTR_ADDR(mp, ifp->if_broot, 1,
ifp->if_broot_bytes);
np = (char *)XFS_BMAP_BROOT_PTR_ADDR(mp, new_broot, 1,
(int)new_size);
memcpy(np, op, new_max * (uint)sizeof(xfs_fsblock_t));
}
kmem_free(ifp->if_broot);
ifp->if_broot = new_broot;
ifp->if_broot_bytes = (int)new_size;
if (ifp->if_broot)
ASSERT(XFS_BMAP_BMDR_SPACE(ifp->if_broot) <=
XFS_IFORK_SIZE(ip, whichfork));
return;
}
void
xfs_idata_realloc(
xfs_inode_t *ip,
int byte_diff,
int whichfork)
{
xfs_ifork_t *ifp;
int new_size;
int real_size;
if (byte_diff == 0) {
return;
}
ifp = XFS_IFORK_PTR(ip, whichfork);
new_size = (int)ifp->if_bytes + byte_diff;
ASSERT(new_size >= 0);
if (new_size == 0) {
if (ifp->if_u1.if_data != ifp->if_u2.if_inline_data) {
kmem_free(ifp->if_u1.if_data);
}
ifp->if_u1.if_data = NULL;
real_size = 0;
} else if (new_size <= sizeof(ifp->if_u2.if_inline_data)) {
if (ifp->if_u1.if_data == NULL) {
ifp->if_u1.if_data = ifp->if_u2.if_inline_data;
} else if (ifp->if_u1.if_data != ifp->if_u2.if_inline_data) {
ASSERT(ifp->if_real_bytes != 0);
memcpy(ifp->if_u2.if_inline_data, ifp->if_u1.if_data,
new_size);
kmem_free(ifp->if_u1.if_data);
ifp->if_u1.if_data = ifp->if_u2.if_inline_data;
}
real_size = 0;
} else {
real_size = roundup(new_size, 4);
if (ifp->if_u1.if_data == NULL) {
ASSERT(ifp->if_real_bytes == 0);
ifp->if_u1.if_data = kmem_alloc(real_size,
KM_SLEEP | KM_NOFS);
} else if (ifp->if_u1.if_data != ifp->if_u2.if_inline_data) {
if (ifp->if_real_bytes != real_size) {
ifp->if_u1.if_data =
kmem_realloc(ifp->if_u1.if_data,
real_size,
KM_SLEEP | KM_NOFS);
}
} else {
ASSERT(ifp->if_real_bytes == 0);
ifp->if_u1.if_data = kmem_alloc(real_size,
KM_SLEEP | KM_NOFS);
memcpy(ifp->if_u1.if_data, ifp->if_u2.if_inline_data,
ifp->if_bytes);
}
}
ifp->if_real_bytes = real_size;
ifp->if_bytes = new_size;
ASSERT(ifp->if_bytes <= XFS_IFORK_SIZE(ip, whichfork));
}
void
xfs_idestroy_fork(
xfs_inode_t *ip,
int whichfork)
{
xfs_ifork_t *ifp;
ifp = XFS_IFORK_PTR(ip, whichfork);
if (ifp->if_broot != NULL) {
kmem_free(ifp->if_broot);
ifp->if_broot = NULL;
}
if (XFS_IFORK_FORMAT(ip, whichfork) == XFS_DINODE_FMT_LOCAL) {
if ((ifp->if_u1.if_data != ifp->if_u2.if_inline_data) &&
(ifp->if_u1.if_data != NULL)) {
ASSERT(ifp->if_real_bytes != 0);
kmem_free(ifp->if_u1.if_data);
ifp->if_u1.if_data = NULL;
ifp->if_real_bytes = 0;
}
} else if ((ifp->if_flags & XFS_IFEXTENTS) &&
((ifp->if_flags & XFS_IFEXTIREC) ||
((ifp->if_u1.if_extents != NULL) &&
(ifp->if_u1.if_extents != ifp->if_u2.if_inline_ext)))) {
ASSERT(ifp->if_real_bytes != 0);
xfs_iext_destroy(ifp);
}
ASSERT(ifp->if_u1.if_extents == NULL ||
ifp->if_u1.if_extents == ifp->if_u2.if_inline_ext);
ASSERT(ifp->if_real_bytes == 0);
if (whichfork == XFS_ATTR_FORK) {
kmem_zone_free(xfs_ifork_zone, ip->i_afp);
ip->i_afp = NULL;
} else if (whichfork == XFS_COW_FORK) {
kmem_zone_free(xfs_ifork_zone, ip->i_cowfp);
ip->i_cowfp = NULL;
}
}
xfs_extnum_t
xfs_iext_count(struct xfs_ifork *ifp)
{
return ifp->if_bytes / (uint)sizeof(xfs_bmbt_rec_t);
}
int
xfs_iextents_copy(
xfs_inode_t *ip,
xfs_bmbt_rec_t *dp,
int whichfork)
{
int copied;
int i;
xfs_ifork_t *ifp;
int nrecs;
xfs_fsblock_t start_block;
ifp = XFS_IFORK_PTR(ip, whichfork);
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL|XFS_ILOCK_SHARED));
ASSERT(ifp->if_bytes > 0);
nrecs = xfs_iext_count(ifp);
XFS_BMAP_TRACE_EXLIST(ip, nrecs, whichfork);
ASSERT(nrecs > 0);
copied = 0;
for (i = 0; i < nrecs; i++) {
xfs_bmbt_rec_host_t *ep = xfs_iext_get_ext(ifp, i);
start_block = xfs_bmbt_get_startblock(ep);
if (isnullstartblock(start_block)) {
continue;
}
put_unaligned_be64(ep->l0, &dp->l0);
put_unaligned_be64(ep->l1, &dp->l1);
dp++;
copied++;
}
ASSERT(copied != 0);
xfs_validate_extents(ifp, copied, XFS_EXTFMT_INODE(ip));
return (copied * (uint)sizeof(xfs_bmbt_rec_t));
}
void
xfs_iflush_fork(
xfs_inode_t *ip,
xfs_dinode_t *dip,
xfs_inode_log_item_t *iip,
int whichfork)
{
char *cp;
xfs_ifork_t *ifp;
xfs_mount_t *mp;
static const short brootflag[2] =
{ XFS_ILOG_DBROOT, XFS_ILOG_ABROOT };
static const short dataflag[2] =
{ XFS_ILOG_DDATA, XFS_ILOG_ADATA };
static const short extflag[2] =
{ XFS_ILOG_DEXT, XFS_ILOG_AEXT };
if (!iip)
return;
ifp = XFS_IFORK_PTR(ip, whichfork);
if (!ifp) {
ASSERT(whichfork == XFS_ATTR_FORK);
return;
}
cp = XFS_DFORK_PTR(dip, whichfork);
mp = ip->i_mount;
switch (XFS_IFORK_FORMAT(ip, whichfork)) {
case XFS_DINODE_FMT_LOCAL:
if ((iip->ili_fields & dataflag[whichfork]) &&
(ifp->if_bytes > 0)) {
ASSERT(ifp->if_u1.if_data != NULL);
ASSERT(ifp->if_bytes <= XFS_IFORK_SIZE(ip, whichfork));
memcpy(cp, ifp->if_u1.if_data, ifp->if_bytes);
}
break;
case XFS_DINODE_FMT_EXTENTS:
ASSERT((ifp->if_flags & XFS_IFEXTENTS) ||
!(iip->ili_fields & extflag[whichfork]));
if ((iip->ili_fields & extflag[whichfork]) &&
(ifp->if_bytes > 0)) {
ASSERT(xfs_iext_get_ext(ifp, 0));
ASSERT(XFS_IFORK_NEXTENTS(ip, whichfork) > 0);
(void)xfs_iextents_copy(ip, (xfs_bmbt_rec_t *)cp,
whichfork);
}
break;
case XFS_DINODE_FMT_BTREE:
if ((iip->ili_fields & brootflag[whichfork]) &&
(ifp->if_broot_bytes > 0)) {
ASSERT(ifp->if_broot != NULL);
ASSERT(XFS_BMAP_BMDR_SPACE(ifp->if_broot) <=
XFS_IFORK_SIZE(ip, whichfork));
xfs_bmbt_to_bmdr(mp, ifp->if_broot, ifp->if_broot_bytes,
(xfs_bmdr_block_t *)cp,
XFS_DFORK_SIZE(dip, mp, whichfork));
}
break;
case XFS_DINODE_FMT_DEV:
if (iip->ili_fields & XFS_ILOG_DEV) {
ASSERT(whichfork == XFS_DATA_FORK);
xfs_dinode_put_rdev(dip, ip->i_df.if_u2.if_rdev);
}
break;
case XFS_DINODE_FMT_UUID:
if (iip->ili_fields & XFS_ILOG_UUID) {
ASSERT(whichfork == XFS_DATA_FORK);
memcpy(XFS_DFORK_DPTR(dip),
&ip->i_df.if_u2.if_uuid,
sizeof(uuid_t));
}
break;
default:
ASSERT(0);
break;
}
}
xfs_bmbt_rec_host_t *
xfs_iext_get_ext(
xfs_ifork_t *ifp,
xfs_extnum_t idx)
{
ASSERT(idx >= 0);
ASSERT(idx < xfs_iext_count(ifp));
if ((ifp->if_flags & XFS_IFEXTIREC) && (idx == 0)) {
return ifp->if_u1.if_ext_irec->er_extbuf;
} else if (ifp->if_flags & XFS_IFEXTIREC) {
xfs_ext_irec_t *erp;
int erp_idx = 0;
xfs_extnum_t page_idx = idx;
erp = xfs_iext_idx_to_irec(ifp, &page_idx, &erp_idx, 0);
return &erp->er_extbuf[page_idx];
} else if (ifp->if_bytes) {
return &ifp->if_u1.if_extents[idx];
} else {
return NULL;
}
}
struct xfs_ifork *
xfs_iext_state_to_fork(
struct xfs_inode *ip,
int state)
{
if (state & BMAP_COWFORK)
return ip->i_cowfp;
else if (state & BMAP_ATTRFORK)
return ip->i_afp;
return &ip->i_df;
}
void
xfs_iext_insert(
xfs_inode_t *ip,
xfs_extnum_t idx,
xfs_extnum_t count,
xfs_bmbt_irec_t *new,
int state)
{
xfs_ifork_t *ifp = xfs_iext_state_to_fork(ip, state);
xfs_extnum_t i;
trace_xfs_iext_insert(ip, idx, new, state, _RET_IP_);
ASSERT(ifp->if_flags & XFS_IFEXTENTS);
xfs_iext_add(ifp, idx, count);
for (i = idx; i < idx + count; i++, new++)
xfs_bmbt_set_all(xfs_iext_get_ext(ifp, i), new);
}
void
xfs_iext_add(
xfs_ifork_t *ifp,
xfs_extnum_t idx,
int ext_diff)
{
int byte_diff;
int new_size;
xfs_extnum_t nextents;
nextents = xfs_iext_count(ifp);
ASSERT((idx >= 0) && (idx <= nextents));
byte_diff = ext_diff * sizeof(xfs_bmbt_rec_t);
new_size = ifp->if_bytes + byte_diff;
if (nextents + ext_diff <= XFS_INLINE_EXTS) {
if (idx < nextents) {
memmove(&ifp->if_u2.if_inline_ext[idx + ext_diff],
&ifp->if_u2.if_inline_ext[idx],
(nextents - idx) * sizeof(xfs_bmbt_rec_t));
memset(&ifp->if_u2.if_inline_ext[idx], 0, byte_diff);
}
ifp->if_u1.if_extents = ifp->if_u2.if_inline_ext;
ifp->if_real_bytes = 0;
}
else if (nextents + ext_diff <= XFS_LINEAR_EXTS) {
xfs_iext_realloc_direct(ifp, new_size);
if (idx < nextents) {
memmove(&ifp->if_u1.if_extents[idx + ext_diff],
&ifp->if_u1.if_extents[idx],
(nextents - idx) * sizeof(xfs_bmbt_rec_t));
memset(&ifp->if_u1.if_extents[idx], 0, byte_diff);
}
}
else {
xfs_ext_irec_t *erp;
int erp_idx = 0;
int page_idx = idx;
ASSERT(nextents + ext_diff > XFS_LINEAR_EXTS);
if (ifp->if_flags & XFS_IFEXTIREC) {
erp = xfs_iext_idx_to_irec(ifp, &page_idx, &erp_idx, 1);
} else {
xfs_iext_irec_init(ifp);
ASSERT(ifp->if_flags & XFS_IFEXTIREC);
erp = ifp->if_u1.if_ext_irec;
}
if (erp && erp->er_extcount + ext_diff <= XFS_LINEAR_EXTS) {
if (page_idx < erp->er_extcount) {
memmove(&erp->er_extbuf[page_idx + ext_diff],
&erp->er_extbuf[page_idx],
(erp->er_extcount - page_idx) *
sizeof(xfs_bmbt_rec_t));
memset(&erp->er_extbuf[page_idx], 0, byte_diff);
}
erp->er_extcount += ext_diff;
xfs_iext_irec_update_extoffs(ifp, erp_idx + 1, ext_diff);
}
else if (erp) {
xfs_iext_add_indirect_multi(ifp,
erp_idx, page_idx, ext_diff);
}
else {
uint count = ext_diff;
while (count) {
erp = xfs_iext_irec_new(ifp, erp_idx);
erp->er_extcount = min(count, XFS_LINEAR_EXTS);
count -= erp->er_extcount;
if (count)
erp_idx++;
}
}
}
ifp->if_bytes = new_size;
}
void
xfs_iext_add_indirect_multi(
xfs_ifork_t *ifp,
int erp_idx,
xfs_extnum_t idx,
int count)
{
int byte_diff;
xfs_ext_irec_t *erp;
xfs_extnum_t ext_diff;
xfs_extnum_t ext_cnt;
xfs_extnum_t nex2;
xfs_bmbt_rec_t *nex2_ep = NULL;
int nlists;
ASSERT(ifp->if_flags & XFS_IFEXTIREC);
erp = &ifp->if_u1.if_ext_irec[erp_idx];
nex2 = erp->er_extcount - idx;
nlists = ifp->if_real_bytes / XFS_IEXT_BUFSZ;
if (nex2) {
byte_diff = nex2 * sizeof(xfs_bmbt_rec_t);
nex2_ep = (xfs_bmbt_rec_t *) kmem_alloc(byte_diff, KM_NOFS);
memmove(nex2_ep, &erp->er_extbuf[idx], byte_diff);
erp->er_extcount -= nex2;
xfs_iext_irec_update_extoffs(ifp, erp_idx + 1, -nex2);
memset(&erp->er_extbuf[idx], 0, byte_diff);
}
ext_cnt = count;
ext_diff = MIN(ext_cnt, (int)XFS_LINEAR_EXTS - erp->er_extcount);
if (ext_diff) {
erp->er_extcount += ext_diff;
xfs_iext_irec_update_extoffs(ifp, erp_idx + 1, ext_diff);
ext_cnt -= ext_diff;
}
while (ext_cnt) {
erp_idx++;
erp = xfs_iext_irec_new(ifp, erp_idx);
ext_diff = MIN(ext_cnt, (int)XFS_LINEAR_EXTS);
erp->er_extcount = ext_diff;
xfs_iext_irec_update_extoffs(ifp, erp_idx + 1, ext_diff);
ext_cnt -= ext_diff;
}
if (nex2) {
xfs_extnum_t ext_avail;
int i;
byte_diff = nex2 * sizeof(xfs_bmbt_rec_t);
ext_avail = XFS_LINEAR_EXTS - erp->er_extcount;
i = 0;
if (nex2 <= ext_avail) {
i = erp->er_extcount;
}
else if ((erp_idx < nlists - 1) &&
(nex2 <= (ext_avail = XFS_LINEAR_EXTS -
ifp->if_u1.if_ext_irec[erp_idx+1].er_extcount))) {
erp_idx++;
erp++;
memmove(&erp->er_extbuf[nex2], erp->er_extbuf,
erp->er_extcount * sizeof(xfs_bmbt_rec_t));
}
else {
erp_idx++;
erp = xfs_iext_irec_new(ifp, erp_idx);
}
memmove(&erp->er_extbuf[i], nex2_ep, byte_diff);
kmem_free(nex2_ep);
erp->er_extcount += nex2;
xfs_iext_irec_update_extoffs(ifp, erp_idx + 1, nex2);
}
}
void
xfs_iext_remove(
xfs_inode_t *ip,
xfs_extnum_t idx,
int ext_diff,
int state)
{
xfs_ifork_t *ifp = xfs_iext_state_to_fork(ip, state);
xfs_extnum_t nextents;
int new_size;
trace_xfs_iext_remove(ip, idx, state, _RET_IP_);
ASSERT(ext_diff > 0);
nextents = xfs_iext_count(ifp);
new_size = (nextents - ext_diff) * sizeof(xfs_bmbt_rec_t);
if (new_size == 0) {
xfs_iext_destroy(ifp);
} else if (ifp->if_flags & XFS_IFEXTIREC) {
xfs_iext_remove_indirect(ifp, idx, ext_diff);
} else if (ifp->if_real_bytes) {
xfs_iext_remove_direct(ifp, idx, ext_diff);
} else {
xfs_iext_remove_inline(ifp, idx, ext_diff);
}
ifp->if_bytes = new_size;
}
void
xfs_iext_remove_inline(
xfs_ifork_t *ifp,
xfs_extnum_t idx,
int ext_diff)
{
int nextents;
ASSERT(!(ifp->if_flags & XFS_IFEXTIREC));
ASSERT(idx < XFS_INLINE_EXTS);
nextents = xfs_iext_count(ifp);
ASSERT(((nextents - ext_diff) > 0) &&
(nextents - ext_diff) < XFS_INLINE_EXTS);
if (idx + ext_diff < nextents) {
memmove(&ifp->if_u2.if_inline_ext[idx],
&ifp->if_u2.if_inline_ext[idx + ext_diff],
(nextents - (idx + ext_diff)) *
sizeof(xfs_bmbt_rec_t));
memset(&ifp->if_u2.if_inline_ext[nextents - ext_diff],
0, ext_diff * sizeof(xfs_bmbt_rec_t));
} else {
memset(&ifp->if_u2.if_inline_ext[idx], 0,
ext_diff * sizeof(xfs_bmbt_rec_t));
}
}
void
xfs_iext_remove_direct(
xfs_ifork_t *ifp,
xfs_extnum_t idx,
int ext_diff)
{
xfs_extnum_t nextents;
int new_size;
ASSERT(!(ifp->if_flags & XFS_IFEXTIREC));
new_size = ifp->if_bytes -
(ext_diff * sizeof(xfs_bmbt_rec_t));
nextents = xfs_iext_count(ifp);
if (new_size == 0) {
xfs_iext_destroy(ifp);
return;
}
if (idx + ext_diff < nextents) {
memmove(&ifp->if_u1.if_extents[idx],
&ifp->if_u1.if_extents[idx + ext_diff],
(nextents - (idx + ext_diff)) *
sizeof(xfs_bmbt_rec_t));
}
memset(&ifp->if_u1.if_extents[nextents - ext_diff],
0, ext_diff * sizeof(xfs_bmbt_rec_t));
xfs_iext_realloc_direct(ifp, new_size);
ifp->if_bytes = new_size;
}
void
xfs_iext_remove_indirect(
xfs_ifork_t *ifp,
xfs_extnum_t idx,
int count)
{
xfs_ext_irec_t *erp;
int erp_idx = 0;
xfs_extnum_t ext_cnt;
xfs_extnum_t ext_diff;
xfs_extnum_t nex1;
xfs_extnum_t nex2;
int page_idx = idx;
ASSERT(ifp->if_flags & XFS_IFEXTIREC);
erp = xfs_iext_idx_to_irec(ifp, &page_idx, &erp_idx, 0);
ASSERT(erp != NULL);
nex1 = page_idx;
ext_cnt = count;
while (ext_cnt) {
nex2 = MAX((erp->er_extcount - (nex1 + ext_cnt)), 0);
ext_diff = MIN(ext_cnt, (erp->er_extcount - nex1));
if (ext_diff == erp->er_extcount) {
xfs_iext_irec_remove(ifp, erp_idx);
ext_cnt -= ext_diff;
nex1 = 0;
if (ext_cnt) {
ASSERT(erp_idx < ifp->if_real_bytes /
XFS_IEXT_BUFSZ);
erp = &ifp->if_u1.if_ext_irec[erp_idx];
nex1 = 0;
continue;
} else {
break;
}
}
if (nex2) {
memmove(&erp->er_extbuf[nex1],
&erp->er_extbuf[nex1 + ext_diff],
nex2 * sizeof(xfs_bmbt_rec_t));
}
memset(&erp->er_extbuf[nex1 + nex2], 0, (XFS_IEXT_BUFSZ -
((nex1 + nex2) * sizeof(xfs_bmbt_rec_t))));
erp->er_extcount -= ext_diff;
xfs_iext_irec_update_extoffs(ifp, erp_idx + 1, -ext_diff);
ext_cnt -= ext_diff;
nex1 = 0;
erp_idx++;
erp++;
}
ifp->if_bytes -= count * sizeof(xfs_bmbt_rec_t);
xfs_iext_irec_compact(ifp);
}
void
xfs_iext_realloc_direct(
xfs_ifork_t *ifp,
int new_size)
{
int rnew_size;
rnew_size = new_size;
ASSERT(!(ifp->if_flags & XFS_IFEXTIREC) ||
((new_size >= 0) && (new_size <= XFS_IEXT_BUFSZ) &&
(new_size != ifp->if_real_bytes)));
if (new_size == 0) {
xfs_iext_destroy(ifp);
}
else if (ifp->if_real_bytes) {
if (new_size <= XFS_INLINE_EXTS * sizeof(xfs_bmbt_rec_t)) {
xfs_iext_direct_to_inline(ifp, new_size /
(uint)sizeof(xfs_bmbt_rec_t));
ifp->if_bytes = new_size;
return;
}
if (!is_power_of_2(new_size)){
rnew_size = roundup_pow_of_two(new_size);
}
if (rnew_size != ifp->if_real_bytes) {
ifp->if_u1.if_extents =
kmem_realloc(ifp->if_u1.if_extents,
rnew_size, KM_NOFS);
}
if (rnew_size > ifp->if_real_bytes) {
memset(&ifp->if_u1.if_extents[ifp->if_bytes /
(uint)sizeof(xfs_bmbt_rec_t)], 0,
rnew_size - ifp->if_real_bytes);
}
}
else {
if (!is_power_of_2(new_size)) {
rnew_size = roundup_pow_of_two(new_size);
}
xfs_iext_inline_to_direct(ifp, rnew_size);
}
ifp->if_real_bytes = rnew_size;
ifp->if_bytes = new_size;
}
void
xfs_iext_direct_to_inline(
xfs_ifork_t *ifp,
xfs_extnum_t nextents)
{
ASSERT(ifp->if_flags & XFS_IFEXTENTS);
ASSERT(nextents <= XFS_INLINE_EXTS);
memcpy(ifp->if_u2.if_inline_ext, ifp->if_u1.if_extents,
nextents * sizeof(xfs_bmbt_rec_t));
kmem_free(ifp->if_u1.if_extents);
ifp->if_u1.if_extents = ifp->if_u2.if_inline_ext;
ifp->if_real_bytes = 0;
}
void
xfs_iext_inline_to_direct(
xfs_ifork_t *ifp,
int new_size)
{
ifp->if_u1.if_extents = kmem_alloc(new_size, KM_NOFS);
memset(ifp->if_u1.if_extents, 0, new_size);
if (ifp->if_bytes) {
memcpy(ifp->if_u1.if_extents, ifp->if_u2.if_inline_ext,
ifp->if_bytes);
memset(ifp->if_u2.if_inline_ext, 0, XFS_INLINE_EXTS *
sizeof(xfs_bmbt_rec_t));
}
ifp->if_real_bytes = new_size;
}
STATIC void
xfs_iext_realloc_indirect(
xfs_ifork_t *ifp,
int new_size)
{
int nlists;
int size;
ASSERT(ifp->if_flags & XFS_IFEXTIREC);
nlists = ifp->if_real_bytes / XFS_IEXT_BUFSZ;
size = nlists * sizeof(xfs_ext_irec_t);
ASSERT(ifp->if_real_bytes);
ASSERT((new_size >= 0) && (new_size != size));
if (new_size == 0) {
xfs_iext_destroy(ifp);
} else {
ifp->if_u1.if_ext_irec =
kmem_realloc(ifp->if_u1.if_ext_irec, new_size, KM_NOFS);
}
}
STATIC void
xfs_iext_indirect_to_direct(
xfs_ifork_t *ifp)
{
xfs_bmbt_rec_host_t *ep;
xfs_extnum_t nextents;
int size;
ASSERT(ifp->if_flags & XFS_IFEXTIREC);
nextents = xfs_iext_count(ifp);
ASSERT(nextents <= XFS_LINEAR_EXTS);
size = nextents * sizeof(xfs_bmbt_rec_t);
xfs_iext_irec_compact_pages(ifp);
ASSERT(ifp->if_real_bytes == XFS_IEXT_BUFSZ);
ep = ifp->if_u1.if_ext_irec->er_extbuf;
kmem_free(ifp->if_u1.if_ext_irec);
ifp->if_flags &= ~XFS_IFEXTIREC;
ifp->if_u1.if_extents = ep;
ifp->if_bytes = size;
if (nextents < XFS_LINEAR_EXTS) {
xfs_iext_realloc_direct(ifp, size);
}
}
STATIC void
xfs_iext_irec_remove_all(
struct xfs_ifork *ifp)
{
int nlists;
int i;
ASSERT(ifp->if_flags & XFS_IFEXTIREC);
nlists = ifp->if_real_bytes / XFS_IEXT_BUFSZ;
for (i = 0; i < nlists; i++)
kmem_free(ifp->if_u1.if_ext_irec[i].er_extbuf);
kmem_free(ifp->if_u1.if_ext_irec);
ifp->if_flags &= ~XFS_IFEXTIREC;
}
void
xfs_iext_destroy(
xfs_ifork_t *ifp)
{
if (ifp->if_flags & XFS_IFEXTIREC) {
xfs_iext_irec_remove_all(ifp);
} else if (ifp->if_real_bytes) {
kmem_free(ifp->if_u1.if_extents);
} else if (ifp->if_bytes) {
memset(ifp->if_u2.if_inline_ext, 0, XFS_INLINE_EXTS *
sizeof(xfs_bmbt_rec_t));
}
ifp->if_u1.if_extents = NULL;
ifp->if_real_bytes = 0;
ifp->if_bytes = 0;
}
xfs_bmbt_rec_host_t *
xfs_iext_bno_to_ext(
xfs_ifork_t *ifp,
xfs_fileoff_t bno,
xfs_extnum_t *idxp)
{
xfs_bmbt_rec_host_t *base;
xfs_filblks_t blockcount = 0;
xfs_bmbt_rec_host_t *ep = NULL;
xfs_ext_irec_t *erp = NULL;
int high;
xfs_extnum_t idx = 0;
int low;
xfs_extnum_t nextents;
xfs_fileoff_t startoff = 0;
nextents = xfs_iext_count(ifp);
if (nextents == 0) {
*idxp = 0;
return NULL;
}
low = 0;
if (ifp->if_flags & XFS_IFEXTIREC) {
int erp_idx = 0;
erp = xfs_iext_bno_to_irec(ifp, bno, &erp_idx);
base = erp->er_extbuf;
high = erp->er_extcount - 1;
} else {
base = ifp->if_u1.if_extents;
high = nextents - 1;
}
while (low <= high) {
idx = (low + high) >> 1;
ep = base + idx;
startoff = xfs_bmbt_get_startoff(ep);
blockcount = xfs_bmbt_get_blockcount(ep);
if (bno < startoff) {
high = idx - 1;
} else if (bno >= startoff + blockcount) {
low = idx + 1;
} else {
if (ifp->if_flags & XFS_IFEXTIREC) {
idx += erp->er_extoff;
}
*idxp = idx;
return ep;
}
}
if (ifp->if_flags & XFS_IFEXTIREC) {
idx += erp->er_extoff;
}
if (bno >= startoff + blockcount) {
if (++idx == nextents) {
ep = NULL;
} else {
ep = xfs_iext_get_ext(ifp, idx);
}
}
*idxp = idx;
return ep;
}
xfs_ext_irec_t *
xfs_iext_bno_to_irec(
xfs_ifork_t *ifp,
xfs_fileoff_t bno,
int *erp_idxp)
{
xfs_ext_irec_t *erp = NULL;
xfs_ext_irec_t *erp_next;
int erp_idx;
int nlists;
int high;
int low;
ASSERT(ifp->if_flags & XFS_IFEXTIREC);
nlists = ifp->if_real_bytes / XFS_IEXT_BUFSZ;
erp_idx = 0;
low = 0;
high = nlists - 1;
while (low <= high) {
erp_idx = (low + high) >> 1;
erp = &ifp->if_u1.if_ext_irec[erp_idx];
erp_next = erp_idx < nlists - 1 ? erp + 1 : NULL;
if (bno < xfs_bmbt_get_startoff(erp->er_extbuf)) {
high = erp_idx - 1;
} else if (erp_next && bno >=
xfs_bmbt_get_startoff(erp_next->er_extbuf)) {
low = erp_idx + 1;
} else {
break;
}
}
*erp_idxp = erp_idx;
return erp;
}
xfs_ext_irec_t *
xfs_iext_idx_to_irec(
xfs_ifork_t *ifp,
xfs_extnum_t *idxp,
int *erp_idxp,
int realloc)
{
xfs_ext_irec_t *prev;
xfs_ext_irec_t *erp = NULL;
int erp_idx;
int nlists;
int high;
int low;
xfs_extnum_t page_idx = *idxp;
ASSERT(ifp->if_flags & XFS_IFEXTIREC);
ASSERT(page_idx >= 0);
ASSERT(page_idx <= xfs_iext_count(ifp));
ASSERT(page_idx < xfs_iext_count(ifp) || realloc);
nlists = ifp->if_real_bytes / XFS_IEXT_BUFSZ;
erp_idx = 0;
low = 0;
high = nlists - 1;
while (low <= high) {
erp_idx = (low + high) >> 1;
erp = &ifp->if_u1.if_ext_irec[erp_idx];
prev = erp_idx > 0 ? erp - 1 : NULL;
if (page_idx < erp->er_extoff || (page_idx == erp->er_extoff &&
realloc && prev && prev->er_extcount < XFS_LINEAR_EXTS)) {
high = erp_idx - 1;
} else if (page_idx > erp->er_extoff + erp->er_extcount ||
(page_idx == erp->er_extoff + erp->er_extcount &&
!realloc)) {
low = erp_idx + 1;
} else if (page_idx == erp->er_extoff + erp->er_extcount &&
erp->er_extcount == XFS_LINEAR_EXTS) {
ASSERT(realloc);
page_idx = 0;
erp_idx++;
erp = erp_idx < nlists ? erp + 1 : NULL;
break;
} else {
page_idx -= erp->er_extoff;
break;
}
}
*idxp = page_idx;
*erp_idxp = erp_idx;
return erp;
}
void
xfs_iext_irec_init(
xfs_ifork_t *ifp)
{
xfs_ext_irec_t *erp;
xfs_extnum_t nextents;
ASSERT(!(ifp->if_flags & XFS_IFEXTIREC));
nextents = xfs_iext_count(ifp);
ASSERT(nextents <= XFS_LINEAR_EXTS);
erp = kmem_alloc(sizeof(xfs_ext_irec_t), KM_NOFS);
if (nextents == 0) {
ifp->if_u1.if_extents = kmem_alloc(XFS_IEXT_BUFSZ, KM_NOFS);
} else if (!ifp->if_real_bytes) {
xfs_iext_inline_to_direct(ifp, XFS_IEXT_BUFSZ);
} else if (ifp->if_real_bytes < XFS_IEXT_BUFSZ) {
xfs_iext_realloc_direct(ifp, XFS_IEXT_BUFSZ);
}
erp->er_extbuf = ifp->if_u1.if_extents;
erp->er_extcount = nextents;
erp->er_extoff = 0;
ifp->if_flags |= XFS_IFEXTIREC;
ifp->if_real_bytes = XFS_IEXT_BUFSZ;
ifp->if_bytes = nextents * sizeof(xfs_bmbt_rec_t);
ifp->if_u1.if_ext_irec = erp;
return;
}
xfs_ext_irec_t *
xfs_iext_irec_new(
xfs_ifork_t *ifp,
int erp_idx)
{
xfs_ext_irec_t *erp;
int i;
int nlists;
ASSERT(ifp->if_flags & XFS_IFEXTIREC);
nlists = ifp->if_real_bytes / XFS_IEXT_BUFSZ;
xfs_iext_realloc_indirect(ifp, ++nlists *
sizeof(xfs_ext_irec_t));
erp = ifp->if_u1.if_ext_irec;
for (i = nlists - 1; i > erp_idx; i--) {
memmove(&erp[i], &erp[i-1], sizeof(xfs_ext_irec_t));
}
ASSERT(i == erp_idx);
erp = ifp->if_u1.if_ext_irec;
erp[erp_idx].er_extbuf = kmem_alloc(XFS_IEXT_BUFSZ, KM_NOFS);
ifp->if_real_bytes = nlists * XFS_IEXT_BUFSZ;
memset(erp[erp_idx].er_extbuf, 0, XFS_IEXT_BUFSZ);
erp[erp_idx].er_extcount = 0;
erp[erp_idx].er_extoff = erp_idx > 0 ?
erp[erp_idx-1].er_extoff + erp[erp_idx-1].er_extcount : 0;
return (&erp[erp_idx]);
}
void
xfs_iext_irec_remove(
xfs_ifork_t *ifp,
int erp_idx)
{
xfs_ext_irec_t *erp;
int i;
int nlists;
ASSERT(ifp->if_flags & XFS_IFEXTIREC);
nlists = ifp->if_real_bytes / XFS_IEXT_BUFSZ;
erp = &ifp->if_u1.if_ext_irec[erp_idx];
if (erp->er_extbuf) {
xfs_iext_irec_update_extoffs(ifp, erp_idx + 1,
-erp->er_extcount);
kmem_free(erp->er_extbuf);
}
erp = ifp->if_u1.if_ext_irec;
for (i = erp_idx; i < nlists - 1; i++) {
memmove(&erp[i], &erp[i+1], sizeof(xfs_ext_irec_t));
}
if (--nlists) {
xfs_iext_realloc_indirect(ifp,
nlists * sizeof(xfs_ext_irec_t));
} else {
kmem_free(ifp->if_u1.if_ext_irec);
}
ifp->if_real_bytes = nlists * XFS_IEXT_BUFSZ;
}
void
xfs_iext_irec_compact(
xfs_ifork_t *ifp)
{
xfs_extnum_t nextents;
int nlists;
ASSERT(ifp->if_flags & XFS_IFEXTIREC);
nlists = ifp->if_real_bytes / XFS_IEXT_BUFSZ;
nextents = xfs_iext_count(ifp);
if (nextents == 0) {
xfs_iext_destroy(ifp);
} else if (nextents <= XFS_INLINE_EXTS) {
xfs_iext_indirect_to_direct(ifp);
xfs_iext_direct_to_inline(ifp, nextents);
} else if (nextents <= XFS_LINEAR_EXTS) {
xfs_iext_indirect_to_direct(ifp);
} else if (nextents < (nlists * XFS_LINEAR_EXTS) >> 1) {
xfs_iext_irec_compact_pages(ifp);
}
}
void
xfs_iext_irec_compact_pages(
xfs_ifork_t *ifp)
{
xfs_ext_irec_t *erp, *erp_next;
int erp_idx = 0;
int nlists;
ASSERT(ifp->if_flags & XFS_IFEXTIREC);
nlists = ifp->if_real_bytes / XFS_IEXT_BUFSZ;
while (erp_idx < nlists - 1) {
erp = &ifp->if_u1.if_ext_irec[erp_idx];
erp_next = erp + 1;
if (erp_next->er_extcount <=
(XFS_LINEAR_EXTS - erp->er_extcount)) {
memcpy(&erp->er_extbuf[erp->er_extcount],
erp_next->er_extbuf, erp_next->er_extcount *
sizeof(xfs_bmbt_rec_t));
erp->er_extcount += erp_next->er_extcount;
kmem_free(erp_next->er_extbuf);
erp_next->er_extbuf = NULL;
xfs_iext_irec_remove(ifp, erp_idx + 1);
nlists = ifp->if_real_bytes / XFS_IEXT_BUFSZ;
} else {
erp_idx++;
}
}
}
void
xfs_iext_irec_update_extoffs(
xfs_ifork_t *ifp,
int erp_idx,
int ext_diff)
{
int i;
int nlists;
ASSERT(ifp->if_flags & XFS_IFEXTIREC);
nlists = ifp->if_real_bytes / XFS_IEXT_BUFSZ;
for (i = erp_idx; i < nlists; i++) {
ifp->if_u1.if_ext_irec[i].er_extoff += ext_diff;
}
}
void
xfs_ifork_init_cow(
struct xfs_inode *ip)
{
if (ip->i_cowfp)
return;
ip->i_cowfp = kmem_zone_zalloc(xfs_ifork_zone,
KM_SLEEP | KM_NOFS);
ip->i_cowfp->if_flags = XFS_IFEXTENTS;
ip->i_cformat = XFS_DINODE_FMT_EXTENTS;
ip->i_cnextents = 0;
}
bool
xfs_iext_lookup_extent(
struct xfs_inode *ip,
struct xfs_ifork *ifp,
xfs_fileoff_t bno,
xfs_extnum_t *idxp,
struct xfs_bmbt_irec *gotp)
{
struct xfs_bmbt_rec_host *ep;
XFS_STATS_INC(ip->i_mount, xs_look_exlist);
ep = xfs_iext_bno_to_ext(ifp, bno, idxp);
if (!ep)
return false;
xfs_bmbt_get_all(ep, gotp);
return true;
}
bool
xfs_iext_get_extent(
struct xfs_ifork *ifp,
xfs_extnum_t idx,
struct xfs_bmbt_irec *gotp)
{
if (idx < 0 || idx >= xfs_iext_count(ifp))
return false;
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, idx), gotp);
return true;
}
