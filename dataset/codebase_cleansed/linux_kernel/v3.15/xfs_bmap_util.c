xfs_daddr_t
xfs_fsb_to_db(struct xfs_inode *ip, xfs_fsblock_t fsb)
{
return (XFS_IS_REALTIME_INODE(ip) ? \
(xfs_daddr_t)XFS_FSB_TO_BB((ip)->i_mount, (fsb)) : \
XFS_FSB_TO_DADDR((ip)->i_mount, (fsb)));
}
int
xfs_bmap_finish(
xfs_trans_t **tp,
xfs_bmap_free_t *flist,
int *committed)
{
xfs_efd_log_item_t *efd;
xfs_efi_log_item_t *efi;
int error;
xfs_bmap_free_item_t *free;
struct xfs_trans_res tres;
xfs_mount_t *mp;
xfs_bmap_free_item_t *next;
xfs_trans_t *ntp;
ASSERT((*tp)->t_flags & XFS_TRANS_PERM_LOG_RES);
if (flist->xbf_count == 0) {
*committed = 0;
return 0;
}
ntp = *tp;
efi = xfs_trans_get_efi(ntp, flist->xbf_count);
for (free = flist->xbf_first; free; free = free->xbfi_next)
xfs_trans_log_efi_extent(ntp, efi, free->xbfi_startblock,
free->xbfi_blockcount);
tres.tr_logres = ntp->t_log_res;
tres.tr_logcount = ntp->t_log_count;
tres.tr_logflags = XFS_TRANS_PERM_LOG_RES;
ntp = xfs_trans_dup(*tp);
error = xfs_trans_commit(*tp, 0);
*tp = ntp;
*committed = 1;
if (error)
return error;
xfs_log_ticket_put(ntp->t_ticket);
error = xfs_trans_reserve(ntp, &tres, 0, 0);
if (error)
return error;
efd = xfs_trans_get_efd(ntp, efi, flist->xbf_count);
for (free = flist->xbf_first; free != NULL; free = next) {
next = free->xbfi_next;
if ((error = xfs_free_extent(ntp, free->xbfi_startblock,
free->xbfi_blockcount))) {
mp = ntp->t_mountp;
if (!XFS_FORCED_SHUTDOWN(mp))
xfs_force_shutdown(mp,
(error == EFSCORRUPTED) ?
SHUTDOWN_CORRUPT_INCORE :
SHUTDOWN_META_IO_ERROR);
return error;
}
xfs_trans_log_efd_extent(ntp, efd, free->xbfi_startblock,
free->xbfi_blockcount);
xfs_bmap_del_free(flist, NULL, free);
}
return 0;
}
int
xfs_bmap_rtalloc(
struct xfs_bmalloca *ap)
{
xfs_alloctype_t atype = 0;
int error;
xfs_mount_t *mp;
xfs_extlen_t prod = 0;
xfs_extlen_t ralen = 0;
xfs_extlen_t align;
xfs_rtblock_t rtb;
mp = ap->ip->i_mount;
align = xfs_get_extsz_hint(ap->ip);
prod = align / mp->m_sb.sb_rextsize;
error = xfs_bmap_extsize_align(mp, &ap->got, &ap->prev,
align, 1, ap->eof, 0,
ap->conv, &ap->offset, &ap->length);
if (error)
return error;
ASSERT(ap->length);
ASSERT(ap->length % mp->m_sb.sb_rextsize == 0);
if (do_mod(ap->offset, align) || ap->length % align)
prod = 1;
ralen = ap->length / mp->m_sb.sb_rextsize;
if (ralen * mp->m_sb.sb_rextsize >= MAXEXTLEN)
ralen = MAXEXTLEN / mp->m_sb.sb_rextsize;
xfs_ilock(mp->m_rbmip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(ap->tp, mp->m_rbmip, XFS_ILOCK_EXCL);
if (ap->eof && ap->offset == 0) {
xfs_rtblock_t uninitialized_var(rtx);
error = xfs_rtpick_extent(mp, ap->tp, ralen, &rtx);
if (error)
return error;
ap->blkno = rtx * mp->m_sb.sb_rextsize;
} else {
ap->blkno = 0;
}
xfs_bmap_adjacent(ap);
atype = ap->blkno == 0 ? XFS_ALLOCTYPE_ANY_AG : XFS_ALLOCTYPE_NEAR_BNO;
do_div(ap->blkno, mp->m_sb.sb_rextsize);
rtb = ap->blkno;
ap->length = ralen;
if ((error = xfs_rtallocate_extent(ap->tp, ap->blkno, 1, ap->length,
&ralen, atype, ap->wasdel, prod, &rtb)))
return error;
if (rtb == NULLFSBLOCK && prod > 1 &&
(error = xfs_rtallocate_extent(ap->tp, ap->blkno, 1,
ap->length, &ralen, atype,
ap->wasdel, 1, &rtb)))
return error;
ap->blkno = rtb;
if (ap->blkno != NULLFSBLOCK) {
ap->blkno *= mp->m_sb.sb_rextsize;
ralen *= mp->m_sb.sb_rextsize;
ap->length = ralen;
ap->ip->i_d.di_nblocks += ralen;
xfs_trans_log_inode(ap->tp, ap->ip, XFS_ILOG_CORE);
if (ap->wasdel)
ap->ip->i_delayed_blks -= ralen;
xfs_trans_mod_dquot_byino(ap->tp, ap->ip,
ap->wasdel ? XFS_TRANS_DQ_DELRTBCOUNT :
XFS_TRANS_DQ_RTBCOUNT, (long) ralen);
} else {
ap->length = 0;
}
return 0;
}
static void
xfs_bmapi_allocate_worker(
struct work_struct *work)
{
struct xfs_bmalloca *args = container_of(work,
struct xfs_bmalloca, work);
unsigned long pflags;
current_set_flags_nested(&pflags, PF_FSTRANS);
args->result = __xfs_bmapi_allocate(args);
complete(args->done);
current_restore_flags_nested(&pflags, PF_FSTRANS);
}
int
xfs_bmapi_allocate(
struct xfs_bmalloca *args)
{
DECLARE_COMPLETION_ONSTACK(done);
if (!args->stack_switch)
return __xfs_bmapi_allocate(args);
args->done = &done;
INIT_WORK_ONSTACK(&args->work, xfs_bmapi_allocate_worker);
queue_work(xfs_alloc_wq, &args->work);
wait_for_completion(&done);
destroy_work_on_stack(&args->work);
return args->result;
}
int
xfs_bmap_eof(
struct xfs_inode *ip,
xfs_fileoff_t endoff,
int whichfork,
int *eof)
{
struct xfs_bmbt_irec rec;
int error;
error = xfs_bmap_last_extent(NULL, ip, whichfork, &rec, eof);
if (error || *eof)
return error;
*eof = endoff >= rec.br_startoff + rec.br_blockcount;
return 0;
}
STATIC void
xfs_bmap_count_leaves(
xfs_ifork_t *ifp,
xfs_extnum_t idx,
int numrecs,
int *count)
{
int b;
for (b = 0; b < numrecs; b++) {
xfs_bmbt_rec_host_t *frp = xfs_iext_get_ext(ifp, idx + b);
*count += xfs_bmbt_get_blockcount(frp);
}
}
STATIC void
xfs_bmap_disk_count_leaves(
struct xfs_mount *mp,
struct xfs_btree_block *block,
int numrecs,
int *count)
{
int b;
xfs_bmbt_rec_t *frp;
for (b = 1; b <= numrecs; b++) {
frp = XFS_BMBT_REC_ADDR(mp, block, b);
*count += xfs_bmbt_disk_get_blockcount(frp);
}
}
STATIC int
xfs_bmap_count_tree(
xfs_mount_t *mp,
xfs_trans_t *tp,
xfs_ifork_t *ifp,
xfs_fsblock_t blockno,
int levelin,
int *count)
{
int error;
xfs_buf_t *bp, *nbp;
int level = levelin;
__be64 *pp;
xfs_fsblock_t bno = blockno;
xfs_fsblock_t nextbno;
struct xfs_btree_block *block, *nextblock;
int numrecs;
error = xfs_btree_read_bufl(mp, tp, bno, 0, &bp, XFS_BMAP_BTREE_REF,
&xfs_bmbt_buf_ops);
if (error)
return error;
*count += 1;
block = XFS_BUF_TO_BLOCK(bp);
if (--level) {
nextbno = be64_to_cpu(block->bb_u.l.bb_rightsib);
while (nextbno != NULLFSBLOCK) {
error = xfs_btree_read_bufl(mp, tp, nextbno, 0, &nbp,
XFS_BMAP_BTREE_REF,
&xfs_bmbt_buf_ops);
if (error)
return error;
*count += 1;
nextblock = XFS_BUF_TO_BLOCK(nbp);
nextbno = be64_to_cpu(nextblock->bb_u.l.bb_rightsib);
xfs_trans_brelse(tp, nbp);
}
pp = XFS_BMBT_PTR_ADDR(mp, block, 1, mp->m_bmap_dmxr[1]);
bno = be64_to_cpu(*pp);
if (unlikely((error =
xfs_bmap_count_tree(mp, tp, ifp, bno, level, count)) < 0)) {
xfs_trans_brelse(tp, bp);
XFS_ERROR_REPORT("xfs_bmap_count_tree(1)",
XFS_ERRLEVEL_LOW, mp);
return XFS_ERROR(EFSCORRUPTED);
}
xfs_trans_brelse(tp, bp);
} else {
for (;;) {
nextbno = be64_to_cpu(block->bb_u.l.bb_rightsib);
numrecs = be16_to_cpu(block->bb_numrecs);
xfs_bmap_disk_count_leaves(mp, block, numrecs, count);
xfs_trans_brelse(tp, bp);
if (nextbno == NULLFSBLOCK)
break;
bno = nextbno;
error = xfs_btree_read_bufl(mp, tp, bno, 0, &bp,
XFS_BMAP_BTREE_REF,
&xfs_bmbt_buf_ops);
if (error)
return error;
*count += 1;
block = XFS_BUF_TO_BLOCK(bp);
}
}
return 0;
}
int
xfs_bmap_count_blocks(
xfs_trans_t *tp,
xfs_inode_t *ip,
int whichfork,
int *count)
{
struct xfs_btree_block *block;
xfs_fsblock_t bno;
xfs_ifork_t *ifp;
int level;
xfs_mount_t *mp;
__be64 *pp;
bno = NULLFSBLOCK;
mp = ip->i_mount;
ifp = XFS_IFORK_PTR(ip, whichfork);
if ( XFS_IFORK_FORMAT(ip, whichfork) == XFS_DINODE_FMT_EXTENTS ) {
xfs_bmap_count_leaves(ifp, 0,
ifp->if_bytes / (uint)sizeof(xfs_bmbt_rec_t),
count);
return 0;
}
block = ifp->if_broot;
level = be16_to_cpu(block->bb_level);
ASSERT(level > 0);
pp = XFS_BMAP_BROOT_PTR_ADDR(mp, block, 1, ifp->if_broot_bytes);
bno = be64_to_cpu(*pp);
ASSERT(bno != NULLDFSBNO);
ASSERT(XFS_FSB_TO_AGNO(mp, bno) < mp->m_sb.sb_agcount);
ASSERT(XFS_FSB_TO_AGBNO(mp, bno) < mp->m_sb.sb_agblocks);
if (unlikely(xfs_bmap_count_tree(mp, tp, ifp, bno, level, count) < 0)) {
XFS_ERROR_REPORT("xfs_bmap_count_blocks(2)", XFS_ERRLEVEL_LOW,
mp);
return XFS_ERROR(EFSCORRUPTED);
}
return 0;
}
STATIC int
xfs_getbmapx_fix_eof_hole(
xfs_inode_t *ip,
struct getbmapx *out,
int prealloced,
__int64_t end,
xfs_fsblock_t startblock)
{
__int64_t fixlen;
xfs_mount_t *mp;
xfs_ifork_t *ifp;
xfs_extnum_t lastx;
xfs_fileoff_t fileblock;
if (startblock == HOLESTARTBLOCK) {
mp = ip->i_mount;
out->bmv_block = -1;
fixlen = XFS_FSB_TO_BB(mp, XFS_B_TO_FSB(mp, XFS_ISIZE(ip)));
fixlen -= out->bmv_offset;
if (prealloced && out->bmv_offset + out->bmv_length == end) {
if (fixlen <= 0)
return 0;
out->bmv_length = fixlen;
}
} else {
if (startblock == DELAYSTARTBLOCK)
out->bmv_block = -2;
else
out->bmv_block = xfs_fsb_to_db(ip, startblock);
fileblock = XFS_BB_TO_FSB(ip->i_mount, out->bmv_offset);
ifp = XFS_IFORK_PTR(ip, XFS_DATA_FORK);
if (xfs_iext_bno_to_ext(ifp, fileblock, &lastx) &&
(lastx == (ifp->if_bytes / (uint)sizeof(xfs_bmbt_rec_t))-1))
out->bmv_oflags |= BMV_OF_LAST;
}
return 1;
}
int
xfs_getbmap(
xfs_inode_t *ip,
struct getbmapx *bmv,
xfs_bmap_format_t formatter,
void *arg)
{
__int64_t bmvend;
int error = 0;
__int64_t fixlen;
int i;
int lock;
xfs_bmbt_irec_t *map;
xfs_mount_t *mp;
int nex;
int nexleft;
int subnex;
int nmap;
struct getbmapx *out;
int whichfork;
int prealloced;
int iflags;
int bmapi_flags;
int cur_ext = 0;
mp = ip->i_mount;
iflags = bmv->bmv_iflags;
whichfork = iflags & BMV_IF_ATTRFORK ? XFS_ATTR_FORK : XFS_DATA_FORK;
if (whichfork == XFS_ATTR_FORK) {
if (XFS_IFORK_Q(ip)) {
if (ip->i_d.di_aformat != XFS_DINODE_FMT_EXTENTS &&
ip->i_d.di_aformat != XFS_DINODE_FMT_BTREE &&
ip->i_d.di_aformat != XFS_DINODE_FMT_LOCAL)
return XFS_ERROR(EINVAL);
} else if (unlikely(
ip->i_d.di_aformat != 0 &&
ip->i_d.di_aformat != XFS_DINODE_FMT_EXTENTS)) {
XFS_ERROR_REPORT("xfs_getbmap", XFS_ERRLEVEL_LOW,
ip->i_mount);
return XFS_ERROR(EFSCORRUPTED);
}
prealloced = 0;
fixlen = 1LL << 32;
} else {
if (ip->i_d.di_format != XFS_DINODE_FMT_EXTENTS &&
ip->i_d.di_format != XFS_DINODE_FMT_BTREE &&
ip->i_d.di_format != XFS_DINODE_FMT_LOCAL)
return XFS_ERROR(EINVAL);
if (xfs_get_extsz_hint(ip) ||
ip->i_d.di_flags & (XFS_DIFLAG_PREALLOC|XFS_DIFLAG_APPEND)){
prealloced = 1;
fixlen = mp->m_super->s_maxbytes;
} else {
prealloced = 0;
fixlen = XFS_ISIZE(ip);
}
}
if (bmv->bmv_length == -1) {
fixlen = XFS_FSB_TO_BB(mp, XFS_B_TO_FSB(mp, fixlen));
bmv->bmv_length =
max_t(__int64_t, fixlen - bmv->bmv_offset, 0);
} else if (bmv->bmv_length == 0) {
bmv->bmv_entries = 0;
return 0;
} else if (bmv->bmv_length < 0) {
return XFS_ERROR(EINVAL);
}
nex = bmv->bmv_count - 1;
if (nex <= 0)
return XFS_ERROR(EINVAL);
bmvend = bmv->bmv_offset + bmv->bmv_length;
if (bmv->bmv_count > ULONG_MAX / sizeof(struct getbmapx))
return XFS_ERROR(ENOMEM);
out = kmem_zalloc_large(bmv->bmv_count * sizeof(struct getbmapx), 0);
if (!out)
return XFS_ERROR(ENOMEM);
xfs_ilock(ip, XFS_IOLOCK_SHARED);
if (whichfork == XFS_DATA_FORK) {
if (!(iflags & BMV_IF_DELALLOC) &&
(ip->i_delayed_blks || XFS_ISIZE(ip) > ip->i_d.di_size)) {
error = -filemap_write_and_wait(VFS_I(ip)->i_mapping);
if (error)
goto out_unlock_iolock;
}
lock = xfs_ilock_data_map_shared(ip);
} else {
lock = xfs_ilock_attr_map_shared(ip);
}
if (nex > XFS_IFORK_NEXTENTS(ip, whichfork) * 2 + 1)
nex = XFS_IFORK_NEXTENTS(ip, whichfork) * 2 + 1;
bmapi_flags = xfs_bmapi_aflag(whichfork);
if (!(iflags & BMV_IF_PREALLOC))
bmapi_flags |= XFS_BMAPI_IGSTATE;
error = ENOMEM;
subnex = 16;
map = kmem_alloc(subnex * sizeof(*map), KM_MAYFAIL | KM_NOFS);
if (!map)
goto out_unlock_ilock;
bmv->bmv_entries = 0;
if (XFS_IFORK_NEXTENTS(ip, whichfork) == 0 &&
(whichfork == XFS_ATTR_FORK || !(iflags & BMV_IF_DELALLOC))) {
error = 0;
goto out_free_map;
}
nexleft = nex;
do {
nmap = (nexleft > subnex) ? subnex : nexleft;
error = xfs_bmapi_read(ip, XFS_BB_TO_FSBT(mp, bmv->bmv_offset),
XFS_BB_TO_FSB(mp, bmv->bmv_length),
map, &nmap, bmapi_flags);
if (error)
goto out_free_map;
ASSERT(nmap <= subnex);
for (i = 0; i < nmap && nexleft && bmv->bmv_length; i++) {
out[cur_ext].bmv_oflags = 0;
if (map[i].br_state == XFS_EXT_UNWRITTEN)
out[cur_ext].bmv_oflags |= BMV_OF_PREALLOC;
else if (map[i].br_startblock == DELAYSTARTBLOCK)
out[cur_ext].bmv_oflags |= BMV_OF_DELALLOC;
out[cur_ext].bmv_offset =
XFS_FSB_TO_BB(mp, map[i].br_startoff);
out[cur_ext].bmv_length =
XFS_FSB_TO_BB(mp, map[i].br_blockcount);
out[cur_ext].bmv_unused1 = 0;
out[cur_ext].bmv_unused2 = 0;
if (map[i].br_startblock == DELAYSTARTBLOCK &&
map[i].br_startoff <= XFS_B_TO_FSB(mp, XFS_ISIZE(ip)))
ASSERT((iflags & BMV_IF_DELALLOC) != 0);
if (map[i].br_startblock == HOLESTARTBLOCK &&
whichfork == XFS_ATTR_FORK) {
out[cur_ext].bmv_oflags |= BMV_OF_LAST;
goto out_free_map;
}
if (!xfs_getbmapx_fix_eof_hole(ip, &out[cur_ext],
prealloced, bmvend,
map[i].br_startblock))
goto out_free_map;
bmv->bmv_offset =
out[cur_ext].bmv_offset +
out[cur_ext].bmv_length;
bmv->bmv_length =
max_t(__int64_t, 0, bmvend - bmv->bmv_offset);
if ((iflags & BMV_IF_NO_HOLES) &&
map[i].br_startblock == HOLESTARTBLOCK) {
memset(&out[cur_ext], 0, sizeof(out[cur_ext]));
continue;
}
nexleft--;
bmv->bmv_entries++;
cur_ext++;
}
} while (nmap && nexleft && bmv->bmv_length);
out_free_map:
kmem_free(map);
out_unlock_ilock:
xfs_iunlock(ip, lock);
out_unlock_iolock:
xfs_iunlock(ip, XFS_IOLOCK_SHARED);
for (i = 0; i < cur_ext; i++) {
int full = 0;
error = formatter(&arg, &out[i], &full);
if (error || full)
break;
}
kmem_free(out);
return error;
}
int
xfs_bmap_punch_delalloc_range(
struct xfs_inode *ip,
xfs_fileoff_t start_fsb,
xfs_fileoff_t length)
{
xfs_fileoff_t remaining = length;
int error = 0;
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL));
do {
int done;
xfs_bmbt_irec_t imap;
int nimaps = 1;
xfs_fsblock_t firstblock;
xfs_bmap_free_t flist;
error = xfs_bmapi_read(ip, start_fsb, 1, &imap, &nimaps,
XFS_BMAPI_ENTIRE);
if (error) {
if (!XFS_FORCED_SHUTDOWN(ip->i_mount)) {
xfs_alert(ip->i_mount,
"Failed delalloc mapping lookup ino %lld fsb %lld.",
ip->i_ino, start_fsb);
}
break;
}
if (!nimaps) {
goto next_block;
}
if (imap.br_startblock != DELAYSTARTBLOCK) {
goto next_block;
}
WARN_ON(imap.br_blockcount == 0);
xfs_bmap_init(&flist, &firstblock);
error = xfs_bunmapi(NULL, ip, start_fsb, 1, 0, 1, &firstblock,
&flist, &done);
if (error)
break;
ASSERT(!flist.xbf_count && !flist.xbf_first);
next_block:
start_fsb++;
remaining--;
} while(remaining > 0);
return error;
}
bool
xfs_can_free_eofblocks(struct xfs_inode *ip, bool force)
{
if (!S_ISREG(ip->i_d.di_mode))
return false;
if (VFS_I(ip)->i_size == 0 &&
VN_CACHED(VFS_I(ip)) == 0 &&
ip->i_delayed_blks == 0)
return false;
if (!(ip->i_df.if_flags & XFS_IFEXTENTS))
return false;
if (ip->i_d.di_flags & (XFS_DIFLAG_PREALLOC | XFS_DIFLAG_APPEND))
if (!force || ip->i_delayed_blks == 0)
return false;
return true;
}
int
xfs_free_eofblocks(
xfs_mount_t *mp,
xfs_inode_t *ip,
bool need_iolock)
{
xfs_trans_t *tp;
int error;
xfs_fileoff_t end_fsb;
xfs_fileoff_t last_fsb;
xfs_filblks_t map_len;
int nimaps;
xfs_bmbt_irec_t imap;
end_fsb = XFS_B_TO_FSB(mp, (xfs_ufsize_t)XFS_ISIZE(ip));
last_fsb = XFS_B_TO_FSB(mp, mp->m_super->s_maxbytes);
if (last_fsb <= end_fsb)
return 0;
map_len = last_fsb - end_fsb;
nimaps = 1;
xfs_ilock(ip, XFS_ILOCK_SHARED);
error = xfs_bmapi_read(ip, end_fsb, map_len, &imap, &nimaps, 0);
xfs_iunlock(ip, XFS_ILOCK_SHARED);
if (!error && (nimaps != 0) &&
(imap.br_startblock != HOLESTARTBLOCK ||
ip->i_delayed_blks)) {
error = xfs_qm_dqattach(ip, 0);
if (error)
return error;
tp = xfs_trans_alloc(mp, XFS_TRANS_INACTIVE);
if (need_iolock) {
if (!xfs_ilock_nowait(ip, XFS_IOLOCK_EXCL)) {
xfs_trans_cancel(tp, 0);
return EAGAIN;
}
}
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_itruncate, 0, 0);
if (error) {
ASSERT(XFS_FORCED_SHUTDOWN(mp));
xfs_trans_cancel(tp, 0);
if (need_iolock)
xfs_iunlock(ip, XFS_IOLOCK_EXCL);
return error;
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, 0);
error = xfs_itruncate_extents(&tp, ip, XFS_DATA_FORK,
XFS_ISIZE(ip));
if (error) {
xfs_trans_cancel(tp,
(XFS_TRANS_RELEASE_LOG_RES |
XFS_TRANS_ABORT));
} else {
error = xfs_trans_commit(tp,
XFS_TRANS_RELEASE_LOG_RES);
if (!error)
xfs_inode_clear_eofblocks_tag(ip);
}
xfs_iunlock(ip, XFS_ILOCK_EXCL);
if (need_iolock)
xfs_iunlock(ip, XFS_IOLOCK_EXCL);
}
return error;
}
int
xfs_alloc_file_space(
struct xfs_inode *ip,
xfs_off_t offset,
xfs_off_t len,
int alloc_type)
{
xfs_mount_t *mp = ip->i_mount;
xfs_off_t count;
xfs_filblks_t allocated_fsb;
xfs_filblks_t allocatesize_fsb;
xfs_extlen_t extsz, temp;
xfs_fileoff_t startoffset_fsb;
xfs_fsblock_t firstfsb;
int nimaps;
int quota_flag;
int rt;
xfs_trans_t *tp;
xfs_bmbt_irec_t imaps[1], *imapp;
xfs_bmap_free_t free_list;
uint qblocks, resblks, resrtextents;
int committed;
int error;
trace_xfs_alloc_file_space(ip);
if (XFS_FORCED_SHUTDOWN(mp))
return XFS_ERROR(EIO);
error = xfs_qm_dqattach(ip, 0);
if (error)
return error;
if (len <= 0)
return XFS_ERROR(EINVAL);
rt = XFS_IS_REALTIME_INODE(ip);
extsz = xfs_get_extsz_hint(ip);
count = len;
imapp = &imaps[0];
nimaps = 1;
startoffset_fsb = XFS_B_TO_FSBT(mp, offset);
allocatesize_fsb = XFS_B_TO_FSB(mp, count);
while (allocatesize_fsb && !error) {
xfs_fileoff_t s, e;
if (unlikely(extsz)) {
s = startoffset_fsb;
do_div(s, extsz);
s *= extsz;
e = startoffset_fsb + allocatesize_fsb;
if ((temp = do_mod(startoffset_fsb, extsz)))
e += temp;
if ((temp = do_mod(e, extsz)))
e += extsz - temp;
} else {
s = 0;
e = allocatesize_fsb;
}
resblks = min_t(xfs_fileoff_t, (e - s), (MAXEXTLEN * nimaps));
if (unlikely(rt)) {
resrtextents = qblocks = resblks;
resrtextents /= mp->m_sb.sb_rextsize;
resblks = XFS_DIOSTRAT_SPACE_RES(mp, 0);
quota_flag = XFS_QMOPT_RES_RTBLKS;
} else {
resrtextents = 0;
resblks = qblocks = XFS_DIOSTRAT_SPACE_RES(mp, resblks);
quota_flag = XFS_QMOPT_RES_REGBLKS;
}
tp = xfs_trans_alloc(mp, XFS_TRANS_DIOSTRAT);
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_write,
resblks, resrtextents);
if (error) {
ASSERT(error == ENOSPC || XFS_FORCED_SHUTDOWN(mp));
xfs_trans_cancel(tp, 0);
break;
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
error = xfs_trans_reserve_quota_nblks(tp, ip, qblocks,
0, quota_flag);
if (error)
goto error1;
xfs_trans_ijoin(tp, ip, 0);
xfs_bmap_init(&free_list, &firstfsb);
error = xfs_bmapi_write(tp, ip, startoffset_fsb,
allocatesize_fsb, alloc_type, &firstfsb,
0, imapp, &nimaps, &free_list);
if (error) {
goto error0;
}
error = xfs_bmap_finish(&tp, &free_list, &committed);
if (error) {
goto error0;
}
error = xfs_trans_commit(tp, XFS_TRANS_RELEASE_LOG_RES);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
if (error) {
break;
}
allocated_fsb = imapp->br_blockcount;
if (nimaps == 0) {
error = XFS_ERROR(ENOSPC);
break;
}
startoffset_fsb += allocated_fsb;
allocatesize_fsb -= allocated_fsb;
}
return error;
error0:
xfs_bmap_cancel(&free_list);
xfs_trans_unreserve_quota_nblks(tp, ip, (long)qblocks, 0, quota_flag);
error1:
xfs_trans_cancel(tp, XFS_TRANS_RELEASE_LOG_RES | XFS_TRANS_ABORT);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return error;
}
STATIC int
xfs_zero_remaining_bytes(
xfs_inode_t *ip,
xfs_off_t startoff,
xfs_off_t endoff)
{
xfs_bmbt_irec_t imap;
xfs_fileoff_t offset_fsb;
xfs_off_t lastoffset;
xfs_off_t offset;
xfs_buf_t *bp;
xfs_mount_t *mp = ip->i_mount;
int nimap;
int error = 0;
if (startoff >= XFS_ISIZE(ip))
return 0;
if (endoff > XFS_ISIZE(ip))
endoff = XFS_ISIZE(ip);
bp = xfs_buf_get_uncached(XFS_IS_REALTIME_INODE(ip) ?
mp->m_rtdev_targp : mp->m_ddev_targp,
BTOBB(mp->m_sb.sb_blocksize), 0);
if (!bp)
return XFS_ERROR(ENOMEM);
xfs_buf_unlock(bp);
for (offset = startoff; offset <= endoff; offset = lastoffset + 1) {
uint lock_mode;
offset_fsb = XFS_B_TO_FSBT(mp, offset);
nimap = 1;
lock_mode = xfs_ilock_data_map_shared(ip);
error = xfs_bmapi_read(ip, offset_fsb, 1, &imap, &nimap, 0);
xfs_iunlock(ip, lock_mode);
if (error || nimap < 1)
break;
ASSERT(imap.br_blockcount >= 1);
ASSERT(imap.br_startoff == offset_fsb);
lastoffset = XFS_FSB_TO_B(mp, imap.br_startoff + 1) - 1;
if (lastoffset > endoff)
lastoffset = endoff;
if (imap.br_startblock == HOLESTARTBLOCK)
continue;
ASSERT(imap.br_startblock != DELAYSTARTBLOCK);
if (imap.br_state == XFS_EXT_UNWRITTEN)
continue;
XFS_BUF_UNDONE(bp);
XFS_BUF_UNWRITE(bp);
XFS_BUF_READ(bp);
XFS_BUF_SET_ADDR(bp, xfs_fsb_to_db(ip, imap.br_startblock));
if (XFS_FORCED_SHUTDOWN(mp)) {
error = XFS_ERROR(EIO);
break;
}
xfs_buf_iorequest(bp);
error = xfs_buf_iowait(bp);
if (error) {
xfs_buf_ioerror_alert(bp,
"xfs_zero_remaining_bytes(read)");
break;
}
memset(bp->b_addr +
(offset - XFS_FSB_TO_B(mp, imap.br_startoff)),
0, lastoffset - offset + 1);
XFS_BUF_UNDONE(bp);
XFS_BUF_UNREAD(bp);
XFS_BUF_WRITE(bp);
if (XFS_FORCED_SHUTDOWN(mp)) {
error = XFS_ERROR(EIO);
break;
}
xfs_buf_iorequest(bp);
error = xfs_buf_iowait(bp);
if (error) {
xfs_buf_ioerror_alert(bp,
"xfs_zero_remaining_bytes(write)");
break;
}
}
xfs_buf_free(bp);
return error;
}
int
xfs_free_file_space(
struct xfs_inode *ip,
xfs_off_t offset,
xfs_off_t len)
{
int committed;
int done;
xfs_fileoff_t endoffset_fsb;
int error;
xfs_fsblock_t firstfsb;
xfs_bmap_free_t free_list;
xfs_bmbt_irec_t imap;
xfs_off_t ioffset;
xfs_extlen_t mod=0;
xfs_mount_t *mp;
int nimap;
uint resblks;
xfs_off_t rounding;
int rt;
xfs_fileoff_t startoffset_fsb;
xfs_trans_t *tp;
mp = ip->i_mount;
trace_xfs_free_file_space(ip);
error = xfs_qm_dqattach(ip, 0);
if (error)
return error;
error = 0;
if (len <= 0)
return error;
rt = XFS_IS_REALTIME_INODE(ip);
startoffset_fsb = XFS_B_TO_FSB(mp, offset);
endoffset_fsb = XFS_B_TO_FSBT(mp, offset + len);
inode_dio_wait(VFS_I(ip));
rounding = max_t(xfs_off_t, 1 << mp->m_sb.sb_blocklog, PAGE_CACHE_SIZE);
ioffset = offset & ~(rounding - 1);
error = -filemap_write_and_wait_range(VFS_I(ip)->i_mapping,
ioffset, -1);
if (error)
goto out;
truncate_pagecache_range(VFS_I(ip), ioffset, -1);
if (rt && !xfs_sb_version_hasextflgbit(&mp->m_sb)) {
nimap = 1;
error = xfs_bmapi_read(ip, startoffset_fsb, 1,
&imap, &nimap, 0);
if (error)
goto out;
ASSERT(nimap == 0 || nimap == 1);
if (nimap && imap.br_startblock != HOLESTARTBLOCK) {
xfs_daddr_t block;
ASSERT(imap.br_startblock != DELAYSTARTBLOCK);
block = imap.br_startblock;
mod = do_div(block, mp->m_sb.sb_rextsize);
if (mod)
startoffset_fsb += mp->m_sb.sb_rextsize - mod;
}
nimap = 1;
error = xfs_bmapi_read(ip, endoffset_fsb - 1, 1,
&imap, &nimap, 0);
if (error)
goto out;
ASSERT(nimap == 0 || nimap == 1);
if (nimap && imap.br_startblock != HOLESTARTBLOCK) {
ASSERT(imap.br_startblock != DELAYSTARTBLOCK);
mod++;
if (mod && (mod != mp->m_sb.sb_rextsize))
endoffset_fsb -= mod;
}
}
if ((done = (endoffset_fsb <= startoffset_fsb)))
error = xfs_zero_remaining_bytes(ip, offset, offset + len - 1);
else {
if (offset < XFS_FSB_TO_B(mp, startoffset_fsb))
error = xfs_zero_remaining_bytes(ip, offset,
XFS_FSB_TO_B(mp, startoffset_fsb) - 1);
if (!error &&
XFS_FSB_TO_B(mp, endoffset_fsb) < offset + len)
error = xfs_zero_remaining_bytes(ip,
XFS_FSB_TO_B(mp, endoffset_fsb),
offset + len - 1);
}
resblks = XFS_DIOSTRAT_SPACE_RES(mp, 0);
while (!error && !done) {
tp = xfs_trans_alloc(mp, XFS_TRANS_DIOSTRAT);
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_write, resblks, 0);
if (error) {
ASSERT(error == ENOSPC || XFS_FORCED_SHUTDOWN(mp));
xfs_trans_cancel(tp, 0);
break;
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
error = xfs_trans_reserve_quota(tp, mp,
ip->i_udquot, ip->i_gdquot, ip->i_pdquot,
resblks, 0, XFS_QMOPT_RES_REGBLKS);
if (error)
goto error1;
xfs_trans_ijoin(tp, ip, 0);
xfs_bmap_init(&free_list, &firstfsb);
error = xfs_bunmapi(tp, ip, startoffset_fsb,
endoffset_fsb - startoffset_fsb,
0, 2, &firstfsb, &free_list, &done);
if (error) {
goto error0;
}
error = xfs_bmap_finish(&tp, &free_list, &committed);
if (error) {
goto error0;
}
error = xfs_trans_commit(tp, XFS_TRANS_RELEASE_LOG_RES);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
}
out:
return error;
error0:
xfs_bmap_cancel(&free_list);
error1:
xfs_trans_cancel(tp, XFS_TRANS_RELEASE_LOG_RES | XFS_TRANS_ABORT);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
goto out;
}
int
xfs_zero_file_space(
struct xfs_inode *ip,
xfs_off_t offset,
xfs_off_t len)
{
struct xfs_mount *mp = ip->i_mount;
uint granularity;
xfs_off_t start_boundary;
xfs_off_t end_boundary;
int error;
trace_xfs_zero_file_space(ip);
granularity = max_t(uint, 1 << mp->m_sb.sb_blocklog, PAGE_CACHE_SIZE);
start_boundary = round_up(offset, granularity);
end_boundary = round_down(offset + len, granularity);
ASSERT(start_boundary >= offset);
ASSERT(end_boundary <= offset + len);
if (start_boundary < end_boundary - 1) {
xfs_ilock(ip, XFS_ILOCK_EXCL);
error = xfs_bmap_punch_delalloc_range(ip,
XFS_B_TO_FSBT(mp, start_boundary),
XFS_B_TO_FSB(mp, end_boundary - start_boundary));
xfs_iunlock(ip, XFS_ILOCK_EXCL);
truncate_pagecache_range(VFS_I(ip), start_boundary,
end_boundary - 1);
error = xfs_alloc_file_space(ip, start_boundary,
end_boundary - start_boundary - 1,
XFS_BMAPI_PREALLOC | XFS_BMAPI_CONVERT);
if (error)
goto out;
if (start_boundary != offset) {
error = xfs_iozero(ip, offset, start_boundary - offset);
if (error)
goto out;
}
if (end_boundary != offset + len)
error = xfs_iozero(ip, end_boundary,
offset + len - end_boundary);
} else {
error = xfs_iozero(ip, offset, len);
}
out:
return error;
}
int
xfs_collapse_file_space(
struct xfs_inode *ip,
xfs_off_t offset,
xfs_off_t len)
{
int done = 0;
struct xfs_mount *mp = ip->i_mount;
struct xfs_trans *tp;
int error;
xfs_extnum_t current_ext = 0;
struct xfs_bmap_free free_list;
xfs_fsblock_t first_block;
int committed;
xfs_fileoff_t start_fsb;
xfs_fileoff_t shift_fsb;
ASSERT(xfs_isilocked(ip, XFS_IOLOCK_EXCL));
trace_xfs_collapse_file_space(ip);
start_fsb = XFS_B_TO_FSB(mp, offset + len);
shift_fsb = XFS_B_TO_FSB(mp, len);
error = xfs_free_file_space(ip, offset, len);
if (error)
return error;
while (!error && !done) {
tp = xfs_trans_alloc(mp, XFS_TRANS_DIOSTRAT);
tp->t_flags |= XFS_TRANS_RESERVE;
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_write,
XFS_DIOSTRAT_SPACE_RES(mp, 0), 0);
if (error) {
ASSERT(error == ENOSPC || XFS_FORCED_SHUTDOWN(mp));
xfs_trans_cancel(tp, 0);
break;
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
error = xfs_trans_reserve_quota(tp, mp, ip->i_udquot,
ip->i_gdquot, ip->i_pdquot,
XFS_DIOSTRAT_SPACE_RES(mp, 0), 0,
XFS_QMOPT_RES_REGBLKS);
if (error)
goto out;
xfs_trans_ijoin(tp, ip, 0);
xfs_bmap_init(&free_list, &first_block);
error = xfs_bmap_shift_extents(tp, ip, &done, start_fsb,
shift_fsb, &current_ext,
&first_block, &free_list,
XFS_BMAP_MAX_SHIFT_EXTENTS);
if (error)
goto out;
error = xfs_bmap_finish(&tp, &free_list, &committed);
if (error)
goto out;
error = xfs_trans_commit(tp, XFS_TRANS_RELEASE_LOG_RES);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
}
return error;
out:
xfs_trans_cancel(tp, XFS_TRANS_RELEASE_LOG_RES | XFS_TRANS_ABORT);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return error;
}
static int
xfs_swap_extents_check_format(
xfs_inode_t *ip,
xfs_inode_t *tip)
{
if (ip->i_d.di_format == XFS_DINODE_FMT_LOCAL ||
tip->i_d.di_format == XFS_DINODE_FMT_LOCAL)
return EINVAL;
if (ip->i_d.di_nextents < tip->i_d.di_nextents)
return EINVAL;
if (ip->i_d.di_format == XFS_DINODE_FMT_EXTENTS &&
tip->i_d.di_format == XFS_DINODE_FMT_BTREE)
return EINVAL;
if (tip->i_d.di_format == XFS_DINODE_FMT_EXTENTS &&
XFS_IFORK_NEXTENTS(tip, XFS_DATA_FORK) >
XFS_IFORK_MAXEXT(ip, XFS_DATA_FORK))
return EINVAL;
if (ip->i_d.di_format == XFS_DINODE_FMT_EXTENTS &&
XFS_IFORK_NEXTENTS(ip, XFS_DATA_FORK) >
XFS_IFORK_MAXEXT(tip, XFS_DATA_FORK))
return EINVAL;
if (tip->i_d.di_format == XFS_DINODE_FMT_BTREE) {
if (XFS_IFORK_BOFF(ip) &&
XFS_BMAP_BMDR_SPACE(tip->i_df.if_broot) > XFS_IFORK_BOFF(ip))
return EINVAL;
if (XFS_IFORK_NEXTENTS(tip, XFS_DATA_FORK) <=
XFS_IFORK_MAXEXT(ip, XFS_DATA_FORK))
return EINVAL;
}
if (ip->i_d.di_format == XFS_DINODE_FMT_BTREE) {
if (XFS_IFORK_BOFF(tip) &&
XFS_BMAP_BMDR_SPACE(ip->i_df.if_broot) > XFS_IFORK_BOFF(tip))
return EINVAL;
if (XFS_IFORK_NEXTENTS(ip, XFS_DATA_FORK) <=
XFS_IFORK_MAXEXT(tip, XFS_DATA_FORK))
return EINVAL;
}
return 0;
}
int
xfs_swap_extents(
xfs_inode_t *ip,
xfs_inode_t *tip,
xfs_swapext_t *sxp)
{
xfs_mount_t *mp = ip->i_mount;
xfs_trans_t *tp;
xfs_bstat_t *sbp = &sxp->sx_stat;
xfs_ifork_t *tempifp, *ifp, *tifp;
int src_log_flags, target_log_flags;
int error = 0;
int aforkblks = 0;
int taforkblks = 0;
__uint64_t tmp;
tempifp = kmem_alloc(sizeof(xfs_ifork_t), KM_MAYFAIL);
if (!tempifp) {
error = XFS_ERROR(ENOMEM);
goto out;
}
xfs_lock_two_inodes(ip, tip, XFS_IOLOCK_EXCL);
xfs_lock_two_inodes(ip, tip, XFS_ILOCK_EXCL);
if ((ip->i_d.di_mode & S_IFMT) != (tip->i_d.di_mode & S_IFMT)) {
error = XFS_ERROR(EINVAL);
goto out_unlock;
}
if (XFS_IS_REALTIME_INODE(ip) != XFS_IS_REALTIME_INODE(tip)) {
error = XFS_ERROR(EINVAL);
goto out_unlock;
}
error = -filemap_write_and_wait(VFS_I(tip)->i_mapping);
if (error)
goto out_unlock;
truncate_pagecache_range(VFS_I(tip), 0, -1);
if (VN_CACHED(VFS_I(tip)) != 0) {
error = XFS_ERROR(EINVAL);
goto out_unlock;
}
if (sxp->sx_offset != 0 ||
sxp->sx_length != ip->i_d.di_size ||
sxp->sx_length != tip->i_d.di_size) {
error = XFS_ERROR(EFAULT);
goto out_unlock;
}
trace_xfs_swap_extent_before(ip, 0);
trace_xfs_swap_extent_before(tip, 1);
error = xfs_swap_extents_check_format(ip, tip);
if (error) {
xfs_notice(mp,
"%s: inode 0x%llx format is incompatible for exchanging.",
__func__, ip->i_ino);
goto out_unlock;
}
if ((sbp->bs_ctime.tv_sec != VFS_I(ip)->i_ctime.tv_sec) ||
(sbp->bs_ctime.tv_nsec != VFS_I(ip)->i_ctime.tv_nsec) ||
(sbp->bs_mtime.tv_sec != VFS_I(ip)->i_mtime.tv_sec) ||
(sbp->bs_mtime.tv_nsec != VFS_I(ip)->i_mtime.tv_nsec)) {
error = XFS_ERROR(EBUSY);
goto out_unlock;
}
if (VN_MAPPED(VFS_I(ip))) {
error = XFS_ERROR(EBUSY);
goto out_unlock;
}
xfs_iunlock(ip, XFS_ILOCK_EXCL);
xfs_iunlock(tip, XFS_ILOCK_EXCL);
truncate_pagecache_range(VFS_I(ip), 0, -1);
tp = xfs_trans_alloc(mp, XFS_TRANS_SWAPEXT);
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_ichange, 0, 0);
if (error) {
xfs_iunlock(ip, XFS_IOLOCK_EXCL);
xfs_iunlock(tip, XFS_IOLOCK_EXCL);
xfs_trans_cancel(tp, 0);
goto out;
}
xfs_lock_two_inodes(ip, tip, XFS_ILOCK_EXCL);
if ( ((XFS_IFORK_Q(ip) != 0) && (ip->i_d.di_anextents > 0)) &&
(ip->i_d.di_aformat != XFS_DINODE_FMT_LOCAL)) {
error = xfs_bmap_count_blocks(tp, ip, XFS_ATTR_FORK, &aforkblks);
if (error)
goto out_trans_cancel;
}
if ( ((XFS_IFORK_Q(tip) != 0) && (tip->i_d.di_anextents > 0)) &&
(tip->i_d.di_aformat != XFS_DINODE_FMT_LOCAL)) {
error = xfs_bmap_count_blocks(tp, tip, XFS_ATTR_FORK,
&taforkblks);
if (error)
goto out_trans_cancel;
}
xfs_trans_ijoin(tp, ip, XFS_ILOCK_EXCL | XFS_IOLOCK_EXCL);
xfs_trans_ijoin(tp, tip, XFS_ILOCK_EXCL | XFS_IOLOCK_EXCL);
src_log_flags = XFS_ILOG_CORE;
target_log_flags = XFS_ILOG_CORE;
if (ip->i_d.di_version == 3 &&
ip->i_d.di_format == XFS_DINODE_FMT_BTREE) {
target_log_flags |= XFS_ILOG_DOWNER;
error = xfs_bmbt_change_owner(tp, ip, XFS_DATA_FORK,
tip->i_ino, NULL);
if (error)
goto out_trans_cancel;
}
if (tip->i_d.di_version == 3 &&
tip->i_d.di_format == XFS_DINODE_FMT_BTREE) {
src_log_flags |= XFS_ILOG_DOWNER;
error = xfs_bmbt_change_owner(tp, tip, XFS_DATA_FORK,
ip->i_ino, NULL);
if (error)
goto out_trans_cancel;
}
ifp = &ip->i_df;
tifp = &tip->i_df;
*tempifp = *ifp;
*ifp = *tifp;
*tifp = *tempifp;
tmp = (__uint64_t)ip->i_d.di_nblocks;
ip->i_d.di_nblocks = tip->i_d.di_nblocks - taforkblks + aforkblks;
tip->i_d.di_nblocks = tmp + taforkblks - aforkblks;
tmp = (__uint64_t) ip->i_d.di_nextents;
ip->i_d.di_nextents = tip->i_d.di_nextents;
tip->i_d.di_nextents = tmp;
tmp = (__uint64_t) ip->i_d.di_format;
ip->i_d.di_format = tip->i_d.di_format;
tip->i_d.di_format = tmp;
ASSERT(tip->i_delayed_blks == 0);
tip->i_delayed_blks = ip->i_delayed_blks;
ip->i_delayed_blks = 0;
switch (ip->i_d.di_format) {
case XFS_DINODE_FMT_EXTENTS:
if (ip->i_d.di_nextents <= XFS_INLINE_EXTS) {
ifp->if_u1.if_extents =
ifp->if_u2.if_inline_ext;
}
src_log_flags |= XFS_ILOG_DEXT;
break;
case XFS_DINODE_FMT_BTREE:
ASSERT(ip->i_d.di_version < 3 ||
(src_log_flags & XFS_ILOG_DOWNER));
src_log_flags |= XFS_ILOG_DBROOT;
break;
}
switch (tip->i_d.di_format) {
case XFS_DINODE_FMT_EXTENTS:
if (tip->i_d.di_nextents <= XFS_INLINE_EXTS) {
tifp->if_u1.if_extents =
tifp->if_u2.if_inline_ext;
}
target_log_flags |= XFS_ILOG_DEXT;
break;
case XFS_DINODE_FMT_BTREE:
target_log_flags |= XFS_ILOG_DBROOT;
ASSERT(tip->i_d.di_version < 3 ||
(target_log_flags & XFS_ILOG_DOWNER));
break;
}
xfs_trans_log_inode(tp, ip, src_log_flags);
xfs_trans_log_inode(tp, tip, target_log_flags);
if (mp->m_flags & XFS_MOUNT_WSYNC)
xfs_trans_set_sync(tp);
error = xfs_trans_commit(tp, 0);
trace_xfs_swap_extent_after(ip, 0);
trace_xfs_swap_extent_after(tip, 1);
out:
kmem_free(tempifp);
return error;
out_unlock:
xfs_iunlock(ip, XFS_ILOCK_EXCL | XFS_IOLOCK_EXCL);
xfs_iunlock(tip, XFS_ILOCK_EXCL | XFS_IOLOCK_EXCL);
goto out;
out_trans_cancel:
xfs_trans_cancel(tp, 0);
goto out_unlock;
}
