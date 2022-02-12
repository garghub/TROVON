xfs_daddr_t
xfs_fsb_to_db(struct xfs_inode *ip, xfs_fsblock_t fsb)
{
return (XFS_IS_REALTIME_INODE(ip) ? \
(xfs_daddr_t)XFS_FSB_TO_BB((ip)->i_mount, (fsb)) : \
XFS_FSB_TO_DADDR((ip)->i_mount, (fsb)));
}
int
xfs_zero_extent(
struct xfs_inode *ip,
xfs_fsblock_t start_fsb,
xfs_off_t count_fsb)
{
struct xfs_mount *mp = ip->i_mount;
xfs_daddr_t sector = xfs_fsb_to_db(ip, start_fsb);
sector_t block = XFS_BB_TO_FSBT(mp, sector);
return blkdev_issue_zeroout(xfs_find_bdev_for_inode(VFS_I(ip)),
block << (mp->m_super->s_blocksize_bits - 9),
count_fsb << (mp->m_super->s_blocksize_bits - 9),
GFP_NOFS, 0);
}
int
xfs_bmap_rtalloc(
struct xfs_bmalloca *ap)
{
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
xfs_ilock(mp->m_rbmip, XFS_ILOCK_EXCL|XFS_ILOCK_RTBITMAP);
xfs_trans_ijoin(ap->tp, mp->m_rbmip, XFS_ILOCK_EXCL);
xfs_ilock(mp->m_rsumip, XFS_ILOCK_EXCL|XFS_ILOCK_RTSUM);
xfs_trans_ijoin(ap->tp, mp->m_rsumip, XFS_ILOCK_EXCL);
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
do_div(ap->blkno, mp->m_sb.sb_rextsize);
rtb = ap->blkno;
ap->length = ralen;
error = xfs_rtallocate_extent(ap->tp, ap->blkno, 1, ap->length,
&ralen, ap->wasdel, prod, &rtb);
if (error)
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
if (ap->datatype & XFS_ALLOC_USERDATA_ZERO) {
error = xfs_zero_extent(ap->ip, ap->blkno, ap->length);
if (error)
return error;
}
} else {
ap->length = 0;
}
return 0;
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
return -EFSCORRUPTED;
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
static int
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
xfs_bmap_count_leaves(ifp, 0, xfs_iext_count(ifp), count);
return 0;
}
block = ifp->if_broot;
level = be16_to_cpu(block->bb_level);
ASSERT(level > 0);
pp = XFS_BMAP_BROOT_PTR_ADDR(mp, block, 1, ifp->if_broot_bytes);
bno = be64_to_cpu(*pp);
ASSERT(bno != NULLFSBLOCK);
ASSERT(XFS_FSB_TO_AGNO(mp, bno) < mp->m_sb.sb_agcount);
ASSERT(XFS_FSB_TO_AGBNO(mp, bno) < mp->m_sb.sb_agblocks);
if (unlikely(xfs_bmap_count_tree(mp, tp, ifp, bno, level, count) < 0)) {
XFS_ERROR_REPORT("xfs_bmap_count_blocks(2)", XFS_ERRLEVEL_LOW,
mp);
return -EFSCORRUPTED;
}
return 0;
}
STATIC int
xfs_getbmapx_fix_eof_hole(
xfs_inode_t *ip,
int whichfork,
struct getbmapx *out,
int prealloced,
__int64_t end,
xfs_fsblock_t startblock,
bool moretocome)
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
ifp = XFS_IFORK_PTR(ip, whichfork);
if (!moretocome &&
xfs_iext_bno_to_ext(ifp, fileblock, &lastx) &&
(lastx == xfs_iext_count(ifp) - 1))
out->bmv_oflags |= BMV_OF_LAST;
}
return 1;
}
STATIC int
xfs_getbmap_adjust_shared(
struct xfs_inode *ip,
int whichfork,
struct xfs_bmbt_irec *map,
struct getbmapx *out,
struct xfs_bmbt_irec *next_map)
{
struct xfs_mount *mp = ip->i_mount;
xfs_agnumber_t agno;
xfs_agblock_t agbno;
xfs_agblock_t ebno;
xfs_extlen_t elen;
xfs_extlen_t nlen;
int error;
next_map->br_startblock = NULLFSBLOCK;
next_map->br_startoff = NULLFILEOFF;
next_map->br_blockcount = 0;
if (!xfs_is_reflink_inode(ip) ||
whichfork != XFS_DATA_FORK ||
!xfs_bmap_is_real_extent(map))
return 0;
agno = XFS_FSB_TO_AGNO(mp, map->br_startblock);
agbno = XFS_FSB_TO_AGBNO(mp, map->br_startblock);
error = xfs_reflink_find_shared(mp, agno, agbno, map->br_blockcount,
&ebno, &elen, true);
if (error)
return error;
if (ebno == NULLAGBLOCK) {
return 0;
} else if (agbno == ebno) {
out->bmv_length = XFS_FSB_TO_BB(mp, elen);
out->bmv_oflags |= BMV_OF_SHARED;
if (elen != map->br_blockcount) {
*next_map = *map;
next_map->br_startblock += elen;
next_map->br_startoff += elen;
next_map->br_blockcount -= elen;
}
map->br_blockcount -= elen;
} else {
*next_map = *map;
nlen = ebno - agbno;
out->bmv_length = XFS_FSB_TO_BB(mp, nlen);
next_map->br_startblock += nlen;
next_map->br_startoff += nlen;
next_map->br_blockcount -= nlen;
map->br_blockcount -= nlen;
}
return 0;
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
int subnex;
int nmap;
struct getbmapx *out;
int whichfork;
int prealloced;
int iflags;
int bmapi_flags;
int cur_ext = 0;
struct xfs_bmbt_irec inject_map;
mp = ip->i_mount;
iflags = bmv->bmv_iflags;
#ifndef DEBUG
if (iflags & BMV_IF_COWFORK)
return -EINVAL;
#endif
if ((iflags & BMV_IF_ATTRFORK) && (iflags & BMV_IF_COWFORK))
return -EINVAL;
if (iflags & BMV_IF_ATTRFORK)
whichfork = XFS_ATTR_FORK;
else if (iflags & BMV_IF_COWFORK)
whichfork = XFS_COW_FORK;
else
whichfork = XFS_DATA_FORK;
switch (whichfork) {
case XFS_ATTR_FORK:
if (XFS_IFORK_Q(ip)) {
if (ip->i_d.di_aformat != XFS_DINODE_FMT_EXTENTS &&
ip->i_d.di_aformat != XFS_DINODE_FMT_BTREE &&
ip->i_d.di_aformat != XFS_DINODE_FMT_LOCAL)
return -EINVAL;
} else if (unlikely(
ip->i_d.di_aformat != 0 &&
ip->i_d.di_aformat != XFS_DINODE_FMT_EXTENTS)) {
XFS_ERROR_REPORT("xfs_getbmap", XFS_ERRLEVEL_LOW,
ip->i_mount);
return -EFSCORRUPTED;
}
prealloced = 0;
fixlen = 1LL << 32;
break;
case XFS_COW_FORK:
if (ip->i_cformat != XFS_DINODE_FMT_EXTENTS)
return -EINVAL;
if (xfs_get_cowextsz_hint(ip)) {
prealloced = 1;
fixlen = mp->m_super->s_maxbytes;
} else {
prealloced = 0;
fixlen = XFS_ISIZE(ip);
}
break;
default:
if (ip->i_d.di_format == XFS_DINODE_FMT_LOCAL) {
bmv->bmv_entries = 0;
return 0;
}
if (ip->i_d.di_format != XFS_DINODE_FMT_EXTENTS &&
ip->i_d.di_format != XFS_DINODE_FMT_BTREE)
return -EINVAL;
if (xfs_get_extsz_hint(ip) ||
ip->i_d.di_flags & (XFS_DIFLAG_PREALLOC|XFS_DIFLAG_APPEND)){
prealloced = 1;
fixlen = mp->m_super->s_maxbytes;
} else {
prealloced = 0;
fixlen = XFS_ISIZE(ip);
}
break;
}
if (bmv->bmv_length == -1) {
fixlen = XFS_FSB_TO_BB(mp, XFS_B_TO_FSB(mp, fixlen));
bmv->bmv_length =
max_t(__int64_t, fixlen - bmv->bmv_offset, 0);
} else if (bmv->bmv_length == 0) {
bmv->bmv_entries = 0;
return 0;
} else if (bmv->bmv_length < 0) {
return -EINVAL;
}
nex = bmv->bmv_count - 1;
if (nex <= 0)
return -EINVAL;
bmvend = bmv->bmv_offset + bmv->bmv_length;
if (bmv->bmv_count > ULONG_MAX / sizeof(struct getbmapx))
return -ENOMEM;
out = kmem_zalloc_large(bmv->bmv_count * sizeof(struct getbmapx), 0);
if (!out)
return -ENOMEM;
xfs_ilock(ip, XFS_IOLOCK_SHARED);
switch (whichfork) {
case XFS_DATA_FORK:
if (!(iflags & BMV_IF_DELALLOC) &&
(ip->i_delayed_blks || XFS_ISIZE(ip) > ip->i_d.di_size)) {
error = filemap_write_and_wait(VFS_I(ip)->i_mapping);
if (error)
goto out_unlock_iolock;
}
lock = xfs_ilock_data_map_shared(ip);
break;
case XFS_COW_FORK:
lock = XFS_ILOCK_SHARED;
xfs_ilock(ip, lock);
break;
case XFS_ATTR_FORK:
lock = xfs_ilock_attr_map_shared(ip);
break;
}
if (nex > XFS_IFORK_NEXTENTS(ip, whichfork) * 2 + 1)
nex = XFS_IFORK_NEXTENTS(ip, whichfork) * 2 + 1;
bmapi_flags = xfs_bmapi_aflag(whichfork);
if (!(iflags & BMV_IF_PREALLOC))
bmapi_flags |= XFS_BMAPI_IGSTATE;
error = -ENOMEM;
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
do {
nmap = (nex> subnex) ? subnex : nex;
error = xfs_bmapi_read(ip, XFS_BB_TO_FSBT(mp, bmv->bmv_offset),
XFS_BB_TO_FSB(mp, bmv->bmv_length),
map, &nmap, bmapi_flags);
if (error)
goto out_free_map;
ASSERT(nmap <= subnex);
for (i = 0; i < nmap && bmv->bmv_length &&
cur_ext < bmv->bmv_count - 1; i++) {
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
map[i].br_startoff < XFS_B_TO_FSB(mp, XFS_ISIZE(ip)))
ASSERT((iflags & BMV_IF_DELALLOC) != 0);
if (map[i].br_startblock == HOLESTARTBLOCK &&
whichfork == XFS_ATTR_FORK) {
out[cur_ext].bmv_oflags |= BMV_OF_LAST;
goto out_free_map;
}
error = xfs_getbmap_adjust_shared(ip, whichfork,
&map[i], &out[cur_ext], &inject_map);
if (error)
goto out_free_map;
if (!xfs_getbmapx_fix_eof_hole(ip, whichfork,
&out[cur_ext], prealloced, bmvend,
map[i].br_startblock,
inject_map.br_startblock != NULLFSBLOCK))
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
if (inject_map.br_startblock != NULLFSBLOCK) {
map[i] = inject_map;
i--;
}
bmv->bmv_entries++;
cur_ext++;
}
} while (nmap && bmv->bmv_length && cur_ext < bmv->bmv_count - 1);
out_free_map:
kmem_free(map);
out_unlock_ilock:
xfs_iunlock(ip, lock);
out_unlock_iolock:
xfs_iunlock(ip, XFS_IOLOCK_SHARED);
for (i = 0; i < cur_ext; i++) {
error = formatter(&arg, &out[i]);
if (error)
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
struct xfs_defer_ops dfops;
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
xfs_defer_init(&dfops, &firstblock);
error = xfs_bunmapi(NULL, ip, start_fsb, 1, 0, 1, &firstblock,
&dfops, &done);
if (error)
break;
ASSERT(!xfs_defer_has_unfinished_work(&dfops));
next_block:
start_fsb++;
remaining--;
} while(remaining > 0);
return error;
}
bool
xfs_can_free_eofblocks(struct xfs_inode *ip, bool force)
{
if (!S_ISREG(VFS_I(ip)->i_mode))
return false;
if (VFS_I(ip)->i_size == 0 &&
VFS_I(ip)->i_mapping->nrpages == 0 &&
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
struct xfs_inode *ip)
{
struct xfs_trans *tp;
int error;
xfs_fileoff_t end_fsb;
xfs_fileoff_t last_fsb;
xfs_filblks_t map_len;
int nimaps;
struct xfs_bmbt_irec imap;
struct xfs_mount *mp = ip->i_mount;
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
inode_dio_wait(VFS_I(ip));
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_itruncate, 0, 0, 0,
&tp);
if (error) {
ASSERT(XFS_FORCED_SHUTDOWN(mp));
return error;
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, 0);
error = xfs_itruncate_extents(&tp, ip, XFS_DATA_FORK,
XFS_ISIZE(ip));
if (error) {
xfs_trans_cancel(tp);
} else {
error = xfs_trans_commit(tp);
if (!error)
xfs_inode_clear_eofblocks_tag(ip);
}
xfs_iunlock(ip, XFS_ILOCK_EXCL);
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
struct xfs_defer_ops dfops;
uint qblocks, resblks, resrtextents;
int error;
trace_xfs_alloc_file_space(ip);
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
error = xfs_qm_dqattach(ip, 0);
if (error)
return error;
if (len <= 0)
return -EINVAL;
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
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_write, resblks,
resrtextents, 0, &tp);
if (error) {
ASSERT(error == -ENOSPC || XFS_FORCED_SHUTDOWN(mp));
break;
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
error = xfs_trans_reserve_quota_nblks(tp, ip, qblocks,
0, quota_flag);
if (error)
goto error1;
xfs_trans_ijoin(tp, ip, 0);
xfs_defer_init(&dfops, &firstfsb);
error = xfs_bmapi_write(tp, ip, startoffset_fsb,
allocatesize_fsb, alloc_type, &firstfsb,
resblks, imapp, &nimaps, &dfops);
if (error)
goto error0;
error = xfs_defer_finish(&tp, &dfops, NULL);
if (error)
goto error0;
error = xfs_trans_commit(tp);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
if (error)
break;
allocated_fsb = imapp->br_blockcount;
if (nimaps == 0) {
error = -ENOSPC;
break;
}
startoffset_fsb += allocated_fsb;
allocatesize_fsb -= allocated_fsb;
}
return error;
error0:
xfs_defer_cancel(&dfops);
xfs_trans_unreserve_quota_nblks(tp, ip, (long)qblocks, 0, quota_flag);
error1:
xfs_trans_cancel(tp);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return error;
}
static int
xfs_unmap_extent(
struct xfs_inode *ip,
xfs_fileoff_t startoffset_fsb,
xfs_filblks_t len_fsb,
int *done)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_trans *tp;
struct xfs_defer_ops dfops;
xfs_fsblock_t firstfsb;
uint resblks = XFS_DIOSTRAT_SPACE_RES(mp, 0);
int error;
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_write, resblks, 0, 0, &tp);
if (error) {
ASSERT(error == -ENOSPC || XFS_FORCED_SHUTDOWN(mp));
return error;
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
error = xfs_trans_reserve_quota(tp, mp, ip->i_udquot, ip->i_gdquot,
ip->i_pdquot, resblks, 0, XFS_QMOPT_RES_REGBLKS);
if (error)
goto out_trans_cancel;
xfs_trans_ijoin(tp, ip, 0);
xfs_defer_init(&dfops, &firstfsb);
error = xfs_bunmapi(tp, ip, startoffset_fsb, len_fsb, 0, 2, &firstfsb,
&dfops, done);
if (error)
goto out_bmap_cancel;
error = xfs_defer_finish(&tp, &dfops, ip);
if (error)
goto out_bmap_cancel;
error = xfs_trans_commit(tp);
out_unlock:
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return error;
out_bmap_cancel:
xfs_defer_cancel(&dfops);
out_trans_cancel:
xfs_trans_cancel(tp);
goto out_unlock;
}
static int
xfs_adjust_extent_unmap_boundaries(
struct xfs_inode *ip,
xfs_fileoff_t *startoffset_fsb,
xfs_fileoff_t *endoffset_fsb)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_bmbt_irec imap;
int nimap, error;
xfs_extlen_t mod = 0;
nimap = 1;
error = xfs_bmapi_read(ip, *startoffset_fsb, 1, &imap, &nimap, 0);
if (error)
return error;
if (nimap && imap.br_startblock != HOLESTARTBLOCK) {
ASSERT(imap.br_startblock != DELAYSTARTBLOCK);
mod = do_mod(imap.br_startblock, mp->m_sb.sb_rextsize);
if (mod)
*startoffset_fsb += mp->m_sb.sb_rextsize - mod;
}
nimap = 1;
error = xfs_bmapi_read(ip, *endoffset_fsb - 1, 1, &imap, &nimap, 0);
if (error)
return error;
if (nimap && imap.br_startblock != HOLESTARTBLOCK) {
ASSERT(imap.br_startblock != DELAYSTARTBLOCK);
mod++;
if (mod && mod != mp->m_sb.sb_rextsize)
*endoffset_fsb -= mod;
}
return 0;
}
static int
xfs_flush_unmap_range(
struct xfs_inode *ip,
xfs_off_t offset,
xfs_off_t len)
{
struct xfs_mount *mp = ip->i_mount;
struct inode *inode = VFS_I(ip);
xfs_off_t rounding, start, end;
int error;
inode_dio_wait(inode);
rounding = max_t(xfs_off_t, 1 << mp->m_sb.sb_blocklog, PAGE_SIZE);
start = round_down(offset, rounding);
end = round_up(offset + len, rounding) - 1;
error = filemap_write_and_wait_range(inode->i_mapping, start, end);
if (error)
return error;
truncate_pagecache_range(inode, start, end);
return 0;
}
int
xfs_free_file_space(
struct xfs_inode *ip,
xfs_off_t offset,
xfs_off_t len)
{
struct xfs_mount *mp = ip->i_mount;
xfs_fileoff_t startoffset_fsb;
xfs_fileoff_t endoffset_fsb;
int done = 0, error;
trace_xfs_free_file_space(ip);
error = xfs_qm_dqattach(ip, 0);
if (error)
return error;
if (len <= 0)
return 0;
error = xfs_flush_unmap_range(ip, offset, len);
if (error)
return error;
startoffset_fsb = XFS_B_TO_FSB(mp, offset);
endoffset_fsb = XFS_B_TO_FSBT(mp, offset + len);
if (XFS_IS_REALTIME_INODE(ip) &&
!xfs_sb_version_hasextflgbit(&mp->m_sb)) {
error = xfs_adjust_extent_unmap_boundaries(ip, &startoffset_fsb,
&endoffset_fsb);
if (error)
return error;
}
if (endoffset_fsb > startoffset_fsb) {
while (!done) {
error = xfs_unmap_extent(ip, startoffset_fsb,
endoffset_fsb - startoffset_fsb, &done);
if (error)
return error;
}
}
if (offset >= XFS_ISIZE(ip))
return 0;
if (offset + len > XFS_ISIZE(ip))
len = XFS_ISIZE(ip) - offset;
return xfs_zero_range(ip, offset, len, NULL);
}
int
xfs_zero_file_space(
struct xfs_inode *ip,
xfs_off_t offset,
xfs_off_t len)
{
struct xfs_mount *mp = ip->i_mount;
uint blksize;
int error;
trace_xfs_zero_file_space(ip);
blksize = 1 << mp->m_sb.sb_blocklog;
error = xfs_free_file_space(ip, offset, len);
if (error)
goto out;
error = xfs_alloc_file_space(ip, round_down(offset, blksize),
round_up(offset + len, blksize) -
round_down(offset, blksize),
XFS_BMAPI_PREALLOC);
out:
return error;
}
static int
xfs_shift_file_space(
struct xfs_inode *ip,
xfs_off_t offset,
xfs_off_t len,
enum shift_direction direction)
{
int done = 0;
struct xfs_mount *mp = ip->i_mount;
struct xfs_trans *tp;
int error;
struct xfs_defer_ops dfops;
xfs_fsblock_t first_block;
xfs_fileoff_t stop_fsb;
xfs_fileoff_t next_fsb;
xfs_fileoff_t shift_fsb;
uint resblks;
ASSERT(direction == SHIFT_LEFT || direction == SHIFT_RIGHT);
if (direction == SHIFT_LEFT) {
resblks = XFS_DIOSTRAT_SPACE_RES(mp, 0);
next_fsb = XFS_B_TO_FSB(mp, offset + len);
stop_fsb = XFS_B_TO_FSB(mp, VFS_I(ip)->i_size);
} else {
resblks = 0;
next_fsb = NULLFSBLOCK;
stop_fsb = XFS_B_TO_FSB(mp, offset);
}
shift_fsb = XFS_B_TO_FSB(mp, len);
if (xfs_can_free_eofblocks(ip, true)) {
error = xfs_free_eofblocks(ip);
if (error)
return error;
}
error = filemap_write_and_wait_range(VFS_I(ip)->i_mapping,
offset, -1);
if (error)
return error;
error = invalidate_inode_pages2_range(VFS_I(ip)->i_mapping,
offset >> PAGE_SHIFT, -1);
if (error)
return error;
if (direction == SHIFT_RIGHT) {
error = xfs_bmap_split_extent(ip, stop_fsb);
if (error)
return error;
}
while (!error && !done) {
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_write, resblks, 0, 0,
&tp);
if (error)
break;
xfs_ilock(ip, XFS_ILOCK_EXCL);
error = xfs_trans_reserve_quota(tp, mp, ip->i_udquot,
ip->i_gdquot, ip->i_pdquot, resblks, 0,
XFS_QMOPT_RES_REGBLKS);
if (error)
goto out_trans_cancel;
xfs_trans_ijoin(tp, ip, XFS_ILOCK_EXCL);
xfs_defer_init(&dfops, &first_block);
error = xfs_bmap_shift_extents(tp, ip, &next_fsb, shift_fsb,
&done, stop_fsb, &first_block, &dfops,
direction, XFS_BMAP_MAX_SHIFT_EXTENTS);
if (error)
goto out_bmap_cancel;
error = xfs_defer_finish(&tp, &dfops, NULL);
if (error)
goto out_bmap_cancel;
error = xfs_trans_commit(tp);
}
return error;
out_bmap_cancel:
xfs_defer_cancel(&dfops);
out_trans_cancel:
xfs_trans_cancel(tp);
return error;
}
int
xfs_collapse_file_space(
struct xfs_inode *ip,
xfs_off_t offset,
xfs_off_t len)
{
int error;
ASSERT(xfs_isilocked(ip, XFS_IOLOCK_EXCL));
trace_xfs_collapse_file_space(ip);
error = xfs_free_file_space(ip, offset, len);
if (error)
return error;
return xfs_shift_file_space(ip, offset, len, SHIFT_LEFT);
}
int
xfs_insert_file_space(
struct xfs_inode *ip,
loff_t offset,
loff_t len)
{
ASSERT(xfs_isilocked(ip, XFS_IOLOCK_EXCL));
trace_xfs_insert_file_space(ip);
return xfs_shift_file_space(ip, offset, len, SHIFT_RIGHT);
}
static int
xfs_swap_extents_check_format(
struct xfs_inode *ip,
struct xfs_inode *tip)
{
if (ip->i_d.di_format == XFS_DINODE_FMT_LOCAL ||
tip->i_d.di_format == XFS_DINODE_FMT_LOCAL)
return -EINVAL;
if (ip->i_d.di_nextents < tip->i_d.di_nextents)
return -EINVAL;
if (xfs_sb_version_hasrmapbt(&ip->i_mount->m_sb))
return 0;
if (ip->i_d.di_format == XFS_DINODE_FMT_EXTENTS &&
tip->i_d.di_format == XFS_DINODE_FMT_BTREE)
return -EINVAL;
if (tip->i_d.di_format == XFS_DINODE_FMT_EXTENTS &&
XFS_IFORK_NEXTENTS(tip, XFS_DATA_FORK) >
XFS_IFORK_MAXEXT(ip, XFS_DATA_FORK))
return -EINVAL;
if (ip->i_d.di_format == XFS_DINODE_FMT_EXTENTS &&
XFS_IFORK_NEXTENTS(ip, XFS_DATA_FORK) >
XFS_IFORK_MAXEXT(tip, XFS_DATA_FORK))
return -EINVAL;
if (tip->i_d.di_format == XFS_DINODE_FMT_BTREE) {
if (XFS_IFORK_BOFF(ip) &&
XFS_BMAP_BMDR_SPACE(tip->i_df.if_broot) > XFS_IFORK_BOFF(ip))
return -EINVAL;
if (XFS_IFORK_NEXTENTS(tip, XFS_DATA_FORK) <=
XFS_IFORK_MAXEXT(ip, XFS_DATA_FORK))
return -EINVAL;
}
if (ip->i_d.di_format == XFS_DINODE_FMT_BTREE) {
if (XFS_IFORK_BOFF(tip) &&
XFS_BMAP_BMDR_SPACE(ip->i_df.if_broot) > XFS_IFORK_BOFF(tip))
return -EINVAL;
if (XFS_IFORK_NEXTENTS(ip, XFS_DATA_FORK) <=
XFS_IFORK_MAXEXT(tip, XFS_DATA_FORK))
return -EINVAL;
}
return 0;
}
static int
xfs_swap_extent_flush(
struct xfs_inode *ip)
{
int error;
error = filemap_write_and_wait(VFS_I(ip)->i_mapping);
if (error)
return error;
truncate_pagecache_range(VFS_I(ip), 0, -1);
if (VFS_I(ip)->i_mapping->nrpages)
return -EINVAL;
return 0;
}
STATIC int
xfs_swap_extent_rmap(
struct xfs_trans **tpp,
struct xfs_inode *ip,
struct xfs_inode *tip)
{
struct xfs_bmbt_irec irec;
struct xfs_bmbt_irec uirec;
struct xfs_bmbt_irec tirec;
xfs_fileoff_t offset_fsb;
xfs_fileoff_t end_fsb;
xfs_filblks_t count_fsb;
xfs_fsblock_t firstfsb;
struct xfs_defer_ops dfops;
int error;
xfs_filblks_t ilen;
xfs_filblks_t rlen;
int nimaps;
__uint64_t tip_flags2;
tip_flags2 = tip->i_d.di_flags2;
if (ip->i_d.di_flags2 & XFS_DIFLAG2_REFLINK)
tip->i_d.di_flags2 |= XFS_DIFLAG2_REFLINK;
offset_fsb = 0;
end_fsb = XFS_B_TO_FSB(ip->i_mount, i_size_read(VFS_I(ip)));
count_fsb = (xfs_filblks_t)(end_fsb - offset_fsb);
while (count_fsb) {
nimaps = 1;
error = xfs_bmapi_read(tip, offset_fsb, count_fsb, &tirec,
&nimaps, 0);
if (error)
goto out;
ASSERT(nimaps == 1);
ASSERT(tirec.br_startblock != DELAYSTARTBLOCK);
trace_xfs_swap_extent_rmap_remap(tip, &tirec);
ilen = tirec.br_blockcount;
while (tirec.br_blockcount) {
xfs_defer_init(&dfops, &firstfsb);
trace_xfs_swap_extent_rmap_remap_piece(tip, &tirec);
nimaps = 1;
error = xfs_bmapi_read(ip, tirec.br_startoff,
tirec.br_blockcount, &irec,
&nimaps, 0);
if (error)
goto out_defer;
ASSERT(nimaps == 1);
ASSERT(tirec.br_startoff == irec.br_startoff);
trace_xfs_swap_extent_rmap_remap_piece(ip, &irec);
uirec = tirec;
uirec.br_blockcount = rlen = min_t(xfs_filblks_t,
tirec.br_blockcount,
irec.br_blockcount);
trace_xfs_swap_extent_rmap_remap_piece(tip, &uirec);
error = xfs_bmap_unmap_extent((*tpp)->t_mountp, &dfops,
tip, &uirec);
if (error)
goto out_defer;
error = xfs_bmap_unmap_extent((*tpp)->t_mountp, &dfops,
ip, &irec);
if (error)
goto out_defer;
error = xfs_bmap_map_extent((*tpp)->t_mountp, &dfops,
ip, &uirec);
if (error)
goto out_defer;
error = xfs_bmap_map_extent((*tpp)->t_mountp, &dfops,
tip, &irec);
if (error)
goto out_defer;
error = xfs_defer_finish(tpp, &dfops, ip);
if (error)
goto out_defer;
tirec.br_startoff += rlen;
if (tirec.br_startblock != HOLESTARTBLOCK &&
tirec.br_startblock != DELAYSTARTBLOCK)
tirec.br_startblock += rlen;
tirec.br_blockcount -= rlen;
}
count_fsb -= ilen;
offset_fsb += ilen;
}
tip->i_d.di_flags2 = tip_flags2;
return 0;
out_defer:
xfs_defer_cancel(&dfops);
out:
trace_xfs_swap_extent_rmap_error(ip, error, _RET_IP_);
tip->i_d.di_flags2 = tip_flags2;
return error;
}
STATIC int
xfs_swap_extent_forks(
struct xfs_trans *tp,
struct xfs_inode *ip,
struct xfs_inode *tip,
int *src_log_flags,
int *target_log_flags)
{
struct xfs_ifork tempifp, *ifp, *tifp;
int aforkblks = 0;
int taforkblks = 0;
xfs_extnum_t nextents;
__uint64_t tmp;
int error;
if ( ((XFS_IFORK_Q(ip) != 0) && (ip->i_d.di_anextents > 0)) &&
(ip->i_d.di_aformat != XFS_DINODE_FMT_LOCAL)) {
error = xfs_bmap_count_blocks(tp, ip, XFS_ATTR_FORK,
&aforkblks);
if (error)
return error;
}
if ( ((XFS_IFORK_Q(tip) != 0) && (tip->i_d.di_anextents > 0)) &&
(tip->i_d.di_aformat != XFS_DINODE_FMT_LOCAL)) {
error = xfs_bmap_count_blocks(tp, tip, XFS_ATTR_FORK,
&taforkblks);
if (error)
return error;
}
if (ip->i_d.di_version == 3 &&
ip->i_d.di_format == XFS_DINODE_FMT_BTREE) {
(*target_log_flags) |= XFS_ILOG_DOWNER;
error = xfs_bmbt_change_owner(tp, ip, XFS_DATA_FORK,
tip->i_ino, NULL);
if (error)
return error;
}
if (tip->i_d.di_version == 3 &&
tip->i_d.di_format == XFS_DINODE_FMT_BTREE) {
(*src_log_flags) |= XFS_ILOG_DOWNER;
error = xfs_bmbt_change_owner(tp, tip, XFS_DATA_FORK,
ip->i_ino, NULL);
if (error)
return error;
}
ifp = &ip->i_df;
tifp = &tip->i_df;
tempifp = *ifp;
*ifp = *tifp;
*tifp = tempifp;
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
nextents = xfs_iext_count(&ip->i_df);
if (nextents <= XFS_INLINE_EXTS)
ifp->if_u1.if_extents = ifp->if_u2.if_inline_ext;
(*src_log_flags) |= XFS_ILOG_DEXT;
break;
case XFS_DINODE_FMT_BTREE:
ASSERT(ip->i_d.di_version < 3 ||
(*src_log_flags & XFS_ILOG_DOWNER));
(*src_log_flags) |= XFS_ILOG_DBROOT;
break;
}
switch (tip->i_d.di_format) {
case XFS_DINODE_FMT_EXTENTS:
nextents = xfs_iext_count(&tip->i_df);
if (nextents <= XFS_INLINE_EXTS)
tifp->if_u1.if_extents = tifp->if_u2.if_inline_ext;
(*target_log_flags) |= XFS_ILOG_DEXT;
break;
case XFS_DINODE_FMT_BTREE:
(*target_log_flags) |= XFS_ILOG_DBROOT;
ASSERT(tip->i_d.di_version < 3 ||
(*target_log_flags & XFS_ILOG_DOWNER));
break;
}
return 0;
}
int
xfs_swap_extents(
struct xfs_inode *ip,
struct xfs_inode *tip,
struct xfs_swapext *sxp)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_trans *tp;
struct xfs_bstat *sbp = &sxp->sx_stat;
int src_log_flags, target_log_flags;
int error = 0;
int lock_flags;
struct xfs_ifork *cowfp;
__uint64_t f;
int resblks;
lock_two_nondirectories(VFS_I(ip), VFS_I(tip));
lock_flags = XFS_MMAPLOCK_EXCL;
xfs_lock_two_inodes(ip, tip, XFS_MMAPLOCK_EXCL);
if ((VFS_I(ip)->i_mode & S_IFMT) != (VFS_I(tip)->i_mode & S_IFMT)) {
error = -EINVAL;
goto out_unlock;
}
if (XFS_IS_REALTIME_INODE(ip) != XFS_IS_REALTIME_INODE(tip)) {
error = -EINVAL;
goto out_unlock;
}
error = xfs_swap_extent_flush(ip);
if (error)
goto out_unlock;
error = xfs_swap_extent_flush(tip);
if (error)
goto out_unlock;
if (xfs_sb_version_hasrmapbt(&mp->m_sb)) {
resblks = XFS_SWAP_RMAP_SPACE_RES(mp,
XFS_IFORK_NEXTENTS(ip, XFS_DATA_FORK),
XFS_DATA_FORK) +
XFS_SWAP_RMAP_SPACE_RES(mp,
XFS_IFORK_NEXTENTS(tip, XFS_DATA_FORK),
XFS_DATA_FORK);
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_write, resblks,
0, 0, &tp);
} else
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_ichange, 0,
0, 0, &tp);
if (error)
goto out_unlock;
xfs_lock_two_inodes(ip, tip, XFS_ILOCK_EXCL);
lock_flags |= XFS_ILOCK_EXCL;
xfs_trans_ijoin(tp, ip, 0);
xfs_trans_ijoin(tp, tip, 0);
if (sxp->sx_offset != 0 ||
sxp->sx_length != ip->i_d.di_size ||
sxp->sx_length != tip->i_d.di_size) {
error = -EFAULT;
goto out_trans_cancel;
}
trace_xfs_swap_extent_before(ip, 0);
trace_xfs_swap_extent_before(tip, 1);
error = xfs_swap_extents_check_format(ip, tip);
if (error) {
xfs_notice(mp,
"%s: inode 0x%llx format is incompatible for exchanging.",
__func__, ip->i_ino);
goto out_trans_cancel;
}
if ((sbp->bs_ctime.tv_sec != VFS_I(ip)->i_ctime.tv_sec) ||
(sbp->bs_ctime.tv_nsec != VFS_I(ip)->i_ctime.tv_nsec) ||
(sbp->bs_mtime.tv_sec != VFS_I(ip)->i_mtime.tv_sec) ||
(sbp->bs_mtime.tv_nsec != VFS_I(ip)->i_mtime.tv_nsec)) {
error = -EBUSY;
goto out_trans_cancel;
}
src_log_flags = XFS_ILOG_CORE;
target_log_flags = XFS_ILOG_CORE;
if (xfs_sb_version_hasrmapbt(&mp->m_sb))
error = xfs_swap_extent_rmap(&tp, ip, tip);
else
error = xfs_swap_extent_forks(tp, ip, tip, &src_log_flags,
&target_log_flags);
if (error)
goto out_trans_cancel;
if ((ip->i_d.di_flags2 & XFS_DIFLAG2_REFLINK) ^
(tip->i_d.di_flags2 & XFS_DIFLAG2_REFLINK)) {
f = ip->i_d.di_flags2 & XFS_DIFLAG2_REFLINK;
ip->i_d.di_flags2 &= ~XFS_DIFLAG2_REFLINK;
ip->i_d.di_flags2 |= tip->i_d.di_flags2 & XFS_DIFLAG2_REFLINK;
tip->i_d.di_flags2 &= ~XFS_DIFLAG2_REFLINK;
tip->i_d.di_flags2 |= f & XFS_DIFLAG2_REFLINK;
cowfp = ip->i_cowfp;
ip->i_cowfp = tip->i_cowfp;
tip->i_cowfp = cowfp;
xfs_inode_set_cowblocks_tag(ip);
xfs_inode_set_cowblocks_tag(tip);
}
xfs_trans_log_inode(tp, ip, src_log_flags);
xfs_trans_log_inode(tp, tip, target_log_flags);
if (mp->m_flags & XFS_MOUNT_WSYNC)
xfs_trans_set_sync(tp);
error = xfs_trans_commit(tp);
trace_xfs_swap_extent_after(ip, 0);
trace_xfs_swap_extent_after(tip, 1);
out_unlock:
xfs_iunlock(ip, lock_flags);
xfs_iunlock(tip, lock_flags);
unlock_two_nondirectories(VFS_I(ip), VFS_I(tip));
return error;
out_trans_cancel:
xfs_trans_cancel(tp);
goto out_unlock;
}
