int
xfs_reflink_find_shared(
struct xfs_mount *mp,
xfs_agnumber_t agno,
xfs_agblock_t agbno,
xfs_extlen_t aglen,
xfs_agblock_t *fbno,
xfs_extlen_t *flen,
bool find_end_of_shared)
{
struct xfs_buf *agbp;
struct xfs_btree_cur *cur;
int error;
error = xfs_alloc_read_agf(mp, NULL, agno, 0, &agbp);
if (error)
return error;
cur = xfs_refcountbt_init_cursor(mp, NULL, agbp, agno, NULL);
error = xfs_refcount_find_shared(cur, agbno, aglen, fbno, flen,
find_end_of_shared);
xfs_btree_del_cursor(cur, error ? XFS_BTREE_ERROR : XFS_BTREE_NOERROR);
xfs_buf_relse(agbp);
return error;
}
int
xfs_reflink_trim_around_shared(
struct xfs_inode *ip,
struct xfs_bmbt_irec *irec,
bool *shared,
bool *trimmed)
{
xfs_agnumber_t agno;
xfs_agblock_t agbno;
xfs_extlen_t aglen;
xfs_agblock_t fbno;
xfs_extlen_t flen;
int error = 0;
if (!xfs_is_reflink_inode(ip) ||
ISUNWRITTEN(irec) ||
irec->br_startblock == HOLESTARTBLOCK ||
irec->br_startblock == DELAYSTARTBLOCK ||
isnullstartblock(irec->br_startblock)) {
*shared = false;
return 0;
}
trace_xfs_reflink_trim_around_shared(ip, irec);
agno = XFS_FSB_TO_AGNO(ip->i_mount, irec->br_startblock);
agbno = XFS_FSB_TO_AGBNO(ip->i_mount, irec->br_startblock);
aglen = irec->br_blockcount;
error = xfs_reflink_find_shared(ip->i_mount, agno, agbno,
aglen, &fbno, &flen, true);
if (error)
return error;
*shared = *trimmed = false;
if (fbno == NULLAGBLOCK) {
return 0;
} else if (fbno == agbno) {
irec->br_blockcount = flen;
*shared = true;
if (flen != aglen)
*trimmed = true;
return 0;
} else {
irec->br_blockcount = fbno - agbno;
*trimmed = true;
return 0;
}
}
int
xfs_reflink_reserve_cow(
struct xfs_inode *ip,
struct xfs_bmbt_irec *imap,
bool *shared)
{
struct xfs_bmbt_irec got, prev;
xfs_fileoff_t end_fsb, orig_end_fsb;
int eof = 0, error = 0;
bool trimmed;
xfs_extnum_t idx;
xfs_extlen_t align;
xfs_bmap_search_extents(ip, imap->br_startoff, XFS_COW_FORK, &eof, &idx,
&got, &prev);
if (!eof && got.br_startoff <= imap->br_startoff) {
trace_xfs_reflink_cow_found(ip, imap);
xfs_trim_extent(imap, got.br_startoff, got.br_blockcount);
*shared = true;
return 0;
}
error = xfs_reflink_trim_around_shared(ip, imap, shared, &trimmed);
if (error)
return error;
if (!*shared)
return 0;
error = xfs_qm_dqattach_locked(ip, 0);
if (error)
return error;
end_fsb = orig_end_fsb = imap->br_startoff + imap->br_blockcount;
align = xfs_eof_alignment(ip, xfs_get_cowextsz_hint(ip));
if (align)
end_fsb = roundup_64(end_fsb, align);
retry:
error = xfs_bmapi_reserve_delalloc(ip, XFS_COW_FORK, imap->br_startoff,
end_fsb - imap->br_startoff, &got, &prev, &idx, eof);
switch (error) {
case 0:
break;
case -ENOSPC:
case -EDQUOT:
trace_xfs_reflink_cow_enospc(ip, imap);
if (end_fsb != orig_end_fsb) {
end_fsb = orig_end_fsb;
goto retry;
}
default:
return error;
}
if (end_fsb != orig_end_fsb)
xfs_inode_set_cowblocks_tag(ip);
trace_xfs_reflink_cow_alloc(ip, &got);
return 0;
}
static int
__xfs_reflink_allocate_cow(
struct xfs_inode *ip,
xfs_fileoff_t *offset_fsb,
xfs_fileoff_t end_fsb)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_bmbt_irec imap;
struct xfs_defer_ops dfops;
struct xfs_trans *tp;
xfs_fsblock_t first_block;
int nimaps = 1, error;
bool shared;
xfs_defer_init(&dfops, &first_block);
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_write, 0, 0,
XFS_TRANS_RESERVE, &tp);
if (error)
return error;
xfs_ilock(ip, XFS_ILOCK_EXCL);
nimaps = 1;
error = xfs_bmapi_read(ip, *offset_fsb, end_fsb - *offset_fsb,
&imap, &nimaps, 0);
if (error)
goto out_unlock;
ASSERT(nimaps == 1);
error = xfs_reflink_reserve_cow(ip, &imap, &shared);
if (error)
goto out_trans_cancel;
if (!shared) {
*offset_fsb = imap.br_startoff + imap.br_blockcount;
goto out_trans_cancel;
}
xfs_trans_ijoin(tp, ip, 0);
error = xfs_bmapi_write(tp, ip, imap.br_startoff, imap.br_blockcount,
XFS_BMAPI_COWFORK, &first_block,
XFS_EXTENTADD_SPACE_RES(mp, XFS_DATA_FORK),
&imap, &nimaps, &dfops);
if (error)
goto out_trans_cancel;
error = xfs_defer_finish(&tp, &dfops, NULL);
if (error)
goto out_trans_cancel;
error = xfs_trans_commit(tp);
*offset_fsb = imap.br_startoff + imap.br_blockcount;
out_unlock:
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return error;
out_trans_cancel:
xfs_defer_cancel(&dfops);
xfs_trans_cancel(tp);
goto out_unlock;
}
int
xfs_reflink_allocate_cow_range(
struct xfs_inode *ip,
xfs_off_t offset,
xfs_off_t count)
{
struct xfs_mount *mp = ip->i_mount;
xfs_fileoff_t offset_fsb = XFS_B_TO_FSBT(mp, offset);
xfs_fileoff_t end_fsb = XFS_B_TO_FSB(mp, offset + count);
int error;
ASSERT(xfs_is_reflink_inode(ip));
trace_xfs_reflink_allocate_cow_range(ip, offset, count);
error = xfs_qm_dqattach(ip, 0);
if (error)
return error;
while (offset_fsb < end_fsb) {
error = __xfs_reflink_allocate_cow(ip, &offset_fsb, end_fsb);
if (error) {
trace_xfs_reflink_allocate_cow_range_error(ip, error,
_RET_IP_);
break;
}
}
return error;
}
bool
xfs_reflink_find_cow_mapping(
struct xfs_inode *ip,
xfs_off_t offset,
struct xfs_bmbt_irec *imap,
bool *need_alloc)
{
struct xfs_bmbt_irec irec;
struct xfs_ifork *ifp;
struct xfs_bmbt_rec_host *gotp;
xfs_fileoff_t bno;
xfs_extnum_t idx;
ASSERT(xfs_isilocked(ip, XFS_ILOCK_EXCL | XFS_ILOCK_SHARED));
ASSERT(xfs_is_reflink_inode(ip));
ifp = XFS_IFORK_PTR(ip, XFS_COW_FORK);
bno = XFS_B_TO_FSBT(ip->i_mount, offset);
gotp = xfs_iext_bno_to_ext(ifp, bno, &idx);
if (!gotp)
return false;
xfs_bmbt_get_all(gotp, &irec);
if (bno >= irec.br_startoff + irec.br_blockcount ||
bno < irec.br_startoff)
return false;
trace_xfs_reflink_find_cow_mapping(ip, offset, 1, XFS_IO_OVERWRITE,
&irec);
*imap = irec;
*need_alloc = !!(isnullstartblock(irec.br_startblock));
return true;
}
int
xfs_reflink_trim_irec_to_next_cow(
struct xfs_inode *ip,
xfs_fileoff_t offset_fsb,
struct xfs_bmbt_irec *imap)
{
struct xfs_bmbt_irec irec;
struct xfs_ifork *ifp;
struct xfs_bmbt_rec_host *gotp;
xfs_extnum_t idx;
if (!xfs_is_reflink_inode(ip))
return 0;
ifp = XFS_IFORK_PTR(ip, XFS_COW_FORK);
gotp = xfs_iext_bno_to_ext(ifp, offset_fsb, &idx);
if (!gotp)
return 0;
xfs_bmbt_get_all(gotp, &irec);
if (irec.br_startoff < offset_fsb) {
idx++;
if (idx >= ifp->if_bytes / sizeof(xfs_bmbt_rec_t))
return 0;
gotp = xfs_iext_get_ext(ifp, idx);
xfs_bmbt_get_all(gotp, &irec);
}
if (irec.br_startoff >= imap->br_startoff + imap->br_blockcount)
return 0;
imap->br_blockcount = irec.br_startoff - imap->br_startoff;
trace_xfs_reflink_trim_irec(ip, imap);
return 0;
}
int
xfs_reflink_cancel_cow_blocks(
struct xfs_inode *ip,
struct xfs_trans **tpp,
xfs_fileoff_t offset_fsb,
xfs_fileoff_t end_fsb)
{
struct xfs_ifork *ifp = XFS_IFORK_PTR(ip, XFS_COW_FORK);
struct xfs_bmbt_irec got, prev, del;
xfs_extnum_t idx;
xfs_fsblock_t firstfsb;
struct xfs_defer_ops dfops;
int error = 0, eof = 0;
if (!xfs_is_reflink_inode(ip))
return 0;
xfs_bmap_search_extents(ip, offset_fsb, XFS_COW_FORK, &eof, &idx,
&got, &prev);
if (eof)
return 0;
while (got.br_startoff < end_fsb) {
del = got;
xfs_trim_extent(&del, offset_fsb, end_fsb - offset_fsb);
trace_xfs_reflink_cancel_cow(ip, &del);
if (isnullstartblock(del.br_startblock)) {
error = xfs_bmap_del_extent_delay(ip, XFS_COW_FORK,
&idx, &got, &del);
if (error)
break;
} else {
xfs_trans_ijoin(*tpp, ip, 0);
xfs_defer_init(&dfops, &firstfsb);
error = xfs_refcount_free_cow_extent(ip->i_mount,
&dfops, del.br_startblock,
del.br_blockcount);
if (error)
break;
xfs_bmap_add_free(ip->i_mount, &dfops,
del.br_startblock, del.br_blockcount,
NULL);
xfs_trans_mod_dquot_byino(*tpp, ip, XFS_TRANS_DQ_BCOUNT,
-(long)del.br_blockcount);
error = xfs_defer_finish(tpp, &dfops, ip);
if (error) {
xfs_defer_cancel(&dfops);
break;
}
xfs_bmap_del_extent_cow(ip, &idx, &got, &del);
}
if (++idx >= ifp->if_bytes / sizeof(struct xfs_bmbt_rec))
break;
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, idx), &got);
}
if (!ifp->if_bytes)
xfs_inode_clear_cowblocks_tag(ip);
return error;
}
int
xfs_reflink_cancel_cow_range(
struct xfs_inode *ip,
xfs_off_t offset,
xfs_off_t count)
{
struct xfs_trans *tp;
xfs_fileoff_t offset_fsb;
xfs_fileoff_t end_fsb;
int error;
trace_xfs_reflink_cancel_cow_range(ip, offset, count);
ASSERT(xfs_is_reflink_inode(ip));
offset_fsb = XFS_B_TO_FSBT(ip->i_mount, offset);
if (count == NULLFILEOFF)
end_fsb = NULLFILEOFF;
else
end_fsb = XFS_B_TO_FSB(ip->i_mount, offset + count);
error = xfs_trans_alloc(ip->i_mount, &M_RES(ip->i_mount)->tr_write,
0, 0, 0, &tp);
if (error)
goto out;
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, 0);
error = xfs_reflink_cancel_cow_blocks(ip, &tp, offset_fsb, end_fsb);
if (error)
goto out_cancel;
error = xfs_trans_commit(tp);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return error;
out_cancel:
xfs_trans_cancel(tp);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
out:
trace_xfs_reflink_cancel_cow_range_error(ip, error, _RET_IP_);
return error;
}
int
xfs_reflink_end_cow(
struct xfs_inode *ip,
xfs_off_t offset,
xfs_off_t count)
{
struct xfs_ifork *ifp = XFS_IFORK_PTR(ip, XFS_COW_FORK);
struct xfs_bmbt_irec got, prev, del;
struct xfs_trans *tp;
xfs_fileoff_t offset_fsb;
xfs_fileoff_t end_fsb;
xfs_fsblock_t firstfsb;
struct xfs_defer_ops dfops;
int error, eof = 0;
unsigned int resblks;
xfs_filblks_t rlen;
xfs_extnum_t idx;
trace_xfs_reflink_end_cow(ip, offset, count);
if (ifp->if_bytes == 0)
return 0;
offset_fsb = XFS_B_TO_FSBT(ip->i_mount, offset);
end_fsb = XFS_B_TO_FSB(ip->i_mount, offset + count);
resblks = XFS_EXTENTADD_SPACE_RES(ip->i_mount, XFS_DATA_FORK);
error = xfs_trans_alloc(ip->i_mount, &M_RES(ip->i_mount)->tr_write,
resblks, 0, 0, &tp);
if (error)
goto out;
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, 0);
xfs_bmap_search_extents(ip, end_fsb - 1, XFS_COW_FORK, &eof, &idx,
&got, &prev);
if (eof || got.br_startoff > end_fsb) {
ASSERT(idx > 0);
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, --idx), &got);
}
while (got.br_startoff + got.br_blockcount > offset_fsb) {
del = got;
xfs_trim_extent(&del, offset_fsb, end_fsb - offset_fsb);
if (!del.br_blockcount) {
idx--;
goto next_extent;
}
ASSERT(!isnullstartblock(got.br_startblock));
xfs_defer_init(&dfops, &firstfsb);
rlen = del.br_blockcount;
error = __xfs_bunmapi(tp, ip, del.br_startoff, &rlen, 0, 1,
&firstfsb, &dfops);
if (error)
goto out_defer;
if (rlen) {
xfs_trim_extent(&del, del.br_startoff + rlen,
del.br_blockcount - rlen);
}
trace_xfs_reflink_cow_remap(ip, &del);
error = xfs_refcount_free_cow_extent(tp->t_mountp, &dfops,
del.br_startblock, del.br_blockcount);
if (error)
goto out_defer;
error = xfs_bmap_map_extent(tp->t_mountp, &dfops, ip, &del);
if (error)
goto out_defer;
xfs_bmap_del_extent_cow(ip, &idx, &got, &del);
error = xfs_defer_finish(&tp, &dfops, ip);
if (error)
goto out_defer;
next_extent:
if (idx < 0)
break;
xfs_bmbt_get_all(xfs_iext_get_ext(ifp, idx), &got);
}
error = xfs_trans_commit(tp);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
if (error)
goto out;
return 0;
out_defer:
xfs_defer_cancel(&dfops);
xfs_trans_cancel(tp);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
out:
trace_xfs_reflink_end_cow_error(ip, error, _RET_IP_);
return error;
}
int
xfs_reflink_recover_cow(
struct xfs_mount *mp)
{
xfs_agnumber_t agno;
int error = 0;
if (!xfs_sb_version_hasreflink(&mp->m_sb))
return 0;
for (agno = 0; agno < mp->m_sb.sb_agcount; agno++) {
error = xfs_refcount_recover_cow_leftovers(mp, agno);
if (error)
break;
}
return error;
}
STATIC int
xfs_reflink_set_inode_flag(
struct xfs_inode *src,
struct xfs_inode *dest)
{
struct xfs_mount *mp = src->i_mount;
int error;
struct xfs_trans *tp;
if (xfs_is_reflink_inode(src) && xfs_is_reflink_inode(dest))
return 0;
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_ichange, 0, 0, 0, &tp);
if (error)
goto out_error;
if (src->i_ino == dest->i_ino)
xfs_ilock(src, XFS_ILOCK_EXCL);
else
xfs_lock_two_inodes(src, dest, XFS_ILOCK_EXCL);
if (!xfs_is_reflink_inode(src)) {
trace_xfs_reflink_set_inode_flag(src);
xfs_trans_ijoin(tp, src, XFS_ILOCK_EXCL);
src->i_d.di_flags2 |= XFS_DIFLAG2_REFLINK;
xfs_trans_log_inode(tp, src, XFS_ILOG_CORE);
xfs_ifork_init_cow(src);
} else
xfs_iunlock(src, XFS_ILOCK_EXCL);
if (src->i_ino == dest->i_ino)
goto commit_flags;
if (!xfs_is_reflink_inode(dest)) {
trace_xfs_reflink_set_inode_flag(dest);
xfs_trans_ijoin(tp, dest, XFS_ILOCK_EXCL);
dest->i_d.di_flags2 |= XFS_DIFLAG2_REFLINK;
xfs_trans_log_inode(tp, dest, XFS_ILOG_CORE);
xfs_ifork_init_cow(dest);
} else
xfs_iunlock(dest, XFS_ILOCK_EXCL);
commit_flags:
error = xfs_trans_commit(tp);
if (error)
goto out_error;
return error;
out_error:
trace_xfs_reflink_set_inode_flag_error(dest, error, _RET_IP_);
return error;
}
STATIC int
xfs_reflink_update_dest(
struct xfs_inode *dest,
xfs_off_t newlen,
xfs_extlen_t cowextsize)
{
struct xfs_mount *mp = dest->i_mount;
struct xfs_trans *tp;
int error;
if (newlen <= i_size_read(VFS_I(dest)) && cowextsize == 0)
return 0;
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_ichange, 0, 0, 0, &tp);
if (error)
goto out_error;
xfs_ilock(dest, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, dest, XFS_ILOCK_EXCL);
if (newlen > i_size_read(VFS_I(dest))) {
trace_xfs_reflink_update_inode_size(dest, newlen);
i_size_write(VFS_I(dest), newlen);
dest->i_d.di_size = newlen;
}
if (cowextsize) {
dest->i_d.di_cowextsize = cowextsize;
dest->i_d.di_flags2 |= XFS_DIFLAG2_COWEXTSIZE;
}
xfs_trans_log_inode(tp, dest, XFS_ILOG_CORE);
error = xfs_trans_commit(tp);
if (error)
goto out_error;
return error;
out_error:
trace_xfs_reflink_update_inode_size_error(dest, error, _RET_IP_);
return error;
}
static int
xfs_reflink_ag_has_free_space(
struct xfs_mount *mp,
xfs_agnumber_t agno)
{
struct xfs_perag *pag;
int error = 0;
if (!xfs_sb_version_hasrmapbt(&mp->m_sb))
return 0;
pag = xfs_perag_get(mp, agno);
if (xfs_ag_resv_critical(pag, XFS_AG_RESV_AGFL) ||
xfs_ag_resv_critical(pag, XFS_AG_RESV_METADATA))
error = -ENOSPC;
xfs_perag_put(pag);
return error;
}
STATIC int
xfs_reflink_remap_extent(
struct xfs_inode *ip,
struct xfs_bmbt_irec *irec,
xfs_fileoff_t destoff,
xfs_off_t new_isize)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_trans *tp;
xfs_fsblock_t firstfsb;
unsigned int resblks;
struct xfs_defer_ops dfops;
struct xfs_bmbt_irec uirec;
bool real_extent;
xfs_filblks_t rlen;
xfs_filblks_t unmap_len;
xfs_off_t newlen;
int error;
unmap_len = irec->br_startoff + irec->br_blockcount - destoff;
trace_xfs_reflink_punch_range(ip, destoff, unmap_len);
real_extent = (irec->br_startblock != HOLESTARTBLOCK &&
irec->br_startblock != DELAYSTARTBLOCK &&
!ISUNWRITTEN(irec));
if (real_extent) {
error = xfs_reflink_ag_has_free_space(mp,
XFS_FSB_TO_AGNO(mp, irec->br_startblock));
if (error)
goto out;
}
resblks = XFS_EXTENTADD_SPACE_RES(ip->i_mount, XFS_DATA_FORK);
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_write, resblks, 0, 0, &tp);
if (error)
goto out;
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, 0);
if (real_extent) {
error = xfs_trans_reserve_quota_nblks(tp, ip,
irec->br_blockcount, 0, XFS_QMOPT_RES_REGBLKS);
if (error)
goto out_cancel;
}
trace_xfs_reflink_remap(ip, irec->br_startoff,
irec->br_blockcount, irec->br_startblock);
rlen = unmap_len;
while (rlen) {
xfs_defer_init(&dfops, &firstfsb);
error = __xfs_bunmapi(tp, ip, destoff, &rlen, 0, 1,
&firstfsb, &dfops);
if (error)
goto out_defer;
uirec.br_startblock = irec->br_startblock + rlen;
uirec.br_startoff = irec->br_startoff + rlen;
uirec.br_blockcount = unmap_len - rlen;
unmap_len = rlen;
if (!real_extent || uirec.br_blockcount == 0)
goto next_extent;
trace_xfs_reflink_remap(ip, uirec.br_startoff,
uirec.br_blockcount, uirec.br_startblock);
error = xfs_refcount_increase_extent(mp, &dfops, &uirec);
if (error)
goto out_defer;
error = xfs_bmap_map_extent(mp, &dfops, ip, &uirec);
if (error)
goto out_defer;
xfs_trans_mod_dquot_byino(tp, ip, XFS_TRANS_DQ_BCOUNT,
uirec.br_blockcount);
newlen = XFS_FSB_TO_B(mp,
uirec.br_startoff + uirec.br_blockcount);
newlen = min_t(xfs_off_t, newlen, new_isize);
if (newlen > i_size_read(VFS_I(ip))) {
trace_xfs_reflink_update_inode_size(ip, newlen);
i_size_write(VFS_I(ip), newlen);
ip->i_d.di_size = newlen;
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
}
next_extent:
error = xfs_defer_finish(&tp, &dfops, ip);
if (error)
goto out_defer;
}
error = xfs_trans_commit(tp);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
if (error)
goto out;
return 0;
out_defer:
xfs_defer_cancel(&dfops);
out_cancel:
xfs_trans_cancel(tp);
xfs_iunlock(ip, XFS_ILOCK_EXCL);
out:
trace_xfs_reflink_remap_extent_error(ip, error, _RET_IP_);
return error;
}
STATIC int
xfs_reflink_remap_blocks(
struct xfs_inode *src,
xfs_fileoff_t srcoff,
struct xfs_inode *dest,
xfs_fileoff_t destoff,
xfs_filblks_t len,
xfs_off_t new_isize)
{
struct xfs_bmbt_irec imap;
int nimaps;
int error = 0;
xfs_filblks_t range_len;
while (len) {
trace_xfs_reflink_remap_blocks_loop(src, srcoff, len,
dest, destoff);
nimaps = 1;
xfs_ilock(src, XFS_ILOCK_EXCL);
error = xfs_bmapi_read(src, srcoff, len, &imap, &nimaps, 0);
xfs_iunlock(src, XFS_ILOCK_EXCL);
if (error)
goto err;
ASSERT(nimaps == 1);
trace_xfs_reflink_remap_imap(src, srcoff, len, XFS_IO_OVERWRITE,
&imap);
range_len = imap.br_startoff + imap.br_blockcount - srcoff;
imap.br_startoff += destoff - srcoff;
error = xfs_reflink_remap_extent(dest, &imap, destoff,
new_isize);
if (error)
goto err;
if (fatal_signal_pending(current)) {
error = -EINTR;
goto err;
}
srcoff += range_len;
destoff += range_len;
len -= range_len;
}
return 0;
err:
trace_xfs_reflink_remap_blocks_error(dest, error, _RET_IP_);
return error;
}
static struct page *
xfs_get_page(
struct inode *inode,
xfs_off_t offset)
{
struct address_space *mapping;
struct page *page;
pgoff_t n;
n = offset >> PAGE_SHIFT;
mapping = inode->i_mapping;
page = read_mapping_page(mapping, n, NULL);
if (IS_ERR(page))
return page;
if (!PageUptodate(page)) {
put_page(page);
return ERR_PTR(-EIO);
}
lock_page(page);
return page;
}
static int
xfs_compare_extents(
struct inode *src,
xfs_off_t srcoff,
struct inode *dest,
xfs_off_t destoff,
xfs_off_t len,
bool *is_same)
{
xfs_off_t src_poff;
xfs_off_t dest_poff;
void *src_addr;
void *dest_addr;
struct page *src_page;
struct page *dest_page;
xfs_off_t cmp_len;
bool same;
int error;
error = -EINVAL;
same = true;
while (len) {
src_poff = srcoff & (PAGE_SIZE - 1);
dest_poff = destoff & (PAGE_SIZE - 1);
cmp_len = min(PAGE_SIZE - src_poff,
PAGE_SIZE - dest_poff);
cmp_len = min(cmp_len, len);
ASSERT(cmp_len > 0);
trace_xfs_reflink_compare_extents(XFS_I(src), srcoff, cmp_len,
XFS_I(dest), destoff);
src_page = xfs_get_page(src, srcoff);
if (IS_ERR(src_page)) {
error = PTR_ERR(src_page);
goto out_error;
}
dest_page = xfs_get_page(dest, destoff);
if (IS_ERR(dest_page)) {
error = PTR_ERR(dest_page);
unlock_page(src_page);
put_page(src_page);
goto out_error;
}
src_addr = kmap_atomic(src_page);
dest_addr = kmap_atomic(dest_page);
flush_dcache_page(src_page);
flush_dcache_page(dest_page);
if (memcmp(src_addr + src_poff, dest_addr + dest_poff, cmp_len))
same = false;
kunmap_atomic(dest_addr);
kunmap_atomic(src_addr);
unlock_page(dest_page);
unlock_page(src_page);
put_page(dest_page);
put_page(src_page);
if (!same)
break;
srcoff += cmp_len;
destoff += cmp_len;
len -= cmp_len;
}
*is_same = same;
return 0;
out_error:
trace_xfs_reflink_compare_extents_error(XFS_I(dest), error, _RET_IP_);
return error;
}
int
xfs_reflink_remap_range(
struct file *file_in,
loff_t pos_in,
struct file *file_out,
loff_t pos_out,
u64 len,
bool is_dedupe)
{
struct inode *inode_in = file_inode(file_in);
struct xfs_inode *src = XFS_I(inode_in);
struct inode *inode_out = file_inode(file_out);
struct xfs_inode *dest = XFS_I(inode_out);
struct xfs_mount *mp = src->i_mount;
loff_t bs = inode_out->i_sb->s_blocksize;
bool same_inode = (inode_in == inode_out);
xfs_fileoff_t sfsbno, dfsbno;
xfs_filblks_t fsblen;
xfs_extlen_t cowextsize;
loff_t isize;
ssize_t ret;
loff_t blen;
if (!xfs_sb_version_hasreflink(&mp->m_sb))
return -EOPNOTSUPP;
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
if (same_inode) {
xfs_ilock(src, XFS_IOLOCK_EXCL);
xfs_ilock(src, XFS_MMAPLOCK_EXCL);
} else {
xfs_lock_two_inodes(src, dest, XFS_IOLOCK_EXCL);
xfs_lock_two_inodes(src, dest, XFS_MMAPLOCK_EXCL);
}
ret = -EPERM;
if (IS_IMMUTABLE(inode_out))
goto out_unlock;
ret = -ETXTBSY;
if (IS_SWAPFILE(inode_in) || IS_SWAPFILE(inode_out))
goto out_unlock;
ret = -EISDIR;
if (S_ISDIR(inode_in->i_mode) || S_ISDIR(inode_out->i_mode))
goto out_unlock;
ret = -EINVAL;
if (S_ISFIFO(inode_in->i_mode) || S_ISFIFO(inode_out->i_mode))
goto out_unlock;
if (!S_ISREG(inode_in->i_mode) || !S_ISREG(inode_out->i_mode))
goto out_unlock;
if (XFS_IS_REALTIME_INODE(src) || XFS_IS_REALTIME_INODE(dest))
goto out_unlock;
if (IS_DAX(inode_in) || IS_DAX(inode_out))
goto out_unlock;
isize = i_size_read(inode_in);
if (isize == 0) {
ret = 0;
goto out_unlock;
}
if (len == 0)
len = isize - pos_in;
if (pos_in + len < pos_in || pos_out + len < pos_out ||
pos_in + len > isize)
goto out_unlock;
if (is_dedupe) {
loff_t disize;
disize = i_size_read(inode_out);
if (pos_out >= disize || pos_out + len > disize)
goto out_unlock;
}
if (pos_in + len == isize)
blen = ALIGN(isize, bs) - pos_in;
else
blen = len;
if (!IS_ALIGNED(pos_in, bs) || !IS_ALIGNED(pos_in + blen, bs) ||
!IS_ALIGNED(pos_out, bs) || !IS_ALIGNED(pos_out + blen, bs))
goto out_unlock;
if (same_inode) {
if (pos_out + blen > pos_in && pos_out < pos_in + blen)
goto out_unlock;
}
inode_dio_wait(inode_in);
if (!same_inode)
inode_dio_wait(inode_out);
ret = filemap_write_and_wait_range(inode_in->i_mapping,
pos_in, pos_in + len - 1);
if (ret)
goto out_unlock;
ret = filemap_write_and_wait_range(inode_out->i_mapping,
pos_out, pos_out + len - 1);
if (ret)
goto out_unlock;
trace_xfs_reflink_remap_range(src, pos_in, len, dest, pos_out);
if (is_dedupe) {
bool is_same = false;
ret = xfs_compare_extents(inode_in, pos_in, inode_out, pos_out,
len, &is_same);
if (ret)
goto out_unlock;
if (!is_same) {
ret = -EBADE;
goto out_unlock;
}
}
ret = xfs_reflink_set_inode_flag(src, dest);
if (ret)
goto out_unlock;
truncate_inode_pages_range(&inode_out->i_data, pos_out,
PAGE_ALIGN(pos_out + len) - 1);
dfsbno = XFS_B_TO_FSBT(mp, pos_out);
sfsbno = XFS_B_TO_FSBT(mp, pos_in);
fsblen = XFS_B_TO_FSB(mp, len);
ret = xfs_reflink_remap_blocks(src, sfsbno, dest, dfsbno, fsblen,
pos_out + len);
if (ret)
goto out_unlock;
cowextsize = 0;
if (pos_in == 0 && len == i_size_read(inode_in) &&
(src->i_d.di_flags2 & XFS_DIFLAG2_COWEXTSIZE) &&
pos_out == 0 && len >= i_size_read(inode_out) &&
!(dest->i_d.di_flags2 & XFS_DIFLAG2_COWEXTSIZE))
cowextsize = src->i_d.di_cowextsize;
ret = xfs_reflink_update_dest(dest, pos_out + len, cowextsize);
out_unlock:
xfs_iunlock(src, XFS_MMAPLOCK_EXCL);
xfs_iunlock(src, XFS_IOLOCK_EXCL);
if (src->i_ino != dest->i_ino) {
xfs_iunlock(dest, XFS_MMAPLOCK_EXCL);
xfs_iunlock(dest, XFS_IOLOCK_EXCL);
}
if (ret)
trace_xfs_reflink_remap_range_error(dest, ret, _RET_IP_);
return ret;
}
STATIC int
xfs_reflink_dirty_extents(
struct xfs_inode *ip,
xfs_fileoff_t fbno,
xfs_filblks_t end,
xfs_off_t isize)
{
struct xfs_mount *mp = ip->i_mount;
xfs_agnumber_t agno;
xfs_agblock_t agbno;
xfs_extlen_t aglen;
xfs_agblock_t rbno;
xfs_extlen_t rlen;
xfs_off_t fpos;
xfs_off_t flen;
struct xfs_bmbt_irec map[2];
int nmaps;
int error = 0;
while (end - fbno > 0) {
nmaps = 1;
error = xfs_bmapi_read(ip, fbno, end - fbno, map, &nmaps, 0);
if (error)
goto out;
if (nmaps == 0)
break;
if (map[0].br_startblock == HOLESTARTBLOCK ||
map[0].br_startblock == DELAYSTARTBLOCK ||
ISUNWRITTEN(&map[0]))
goto next;
map[1] = map[0];
while (map[1].br_blockcount) {
agno = XFS_FSB_TO_AGNO(mp, map[1].br_startblock);
agbno = XFS_FSB_TO_AGBNO(mp, map[1].br_startblock);
aglen = map[1].br_blockcount;
error = xfs_reflink_find_shared(mp, agno, agbno, aglen,
&rbno, &rlen, true);
if (error)
goto out;
if (rbno == NULLAGBLOCK)
break;
xfs_iunlock(ip, XFS_ILOCK_EXCL);
fpos = XFS_FSB_TO_B(mp, map[1].br_startoff +
(rbno - agbno));
flen = XFS_FSB_TO_B(mp, rlen);
if (fpos + flen > isize)
flen = isize - fpos;
error = iomap_file_dirty(VFS_I(ip), fpos, flen,
&xfs_iomap_ops);
xfs_ilock(ip, XFS_ILOCK_EXCL);
if (error)
goto out;
map[1].br_blockcount -= (rbno - agbno + rlen);
map[1].br_startoff += (rbno - agbno + rlen);
map[1].br_startblock += (rbno - agbno + rlen);
}
next:
fbno = map[0].br_startoff + map[0].br_blockcount;
}
out:
return error;
}
int
xfs_reflink_clear_inode_flag(
struct xfs_inode *ip,
struct xfs_trans **tpp)
{
struct xfs_mount *mp = ip->i_mount;
xfs_fileoff_t fbno;
xfs_filblks_t end;
xfs_agnumber_t agno;
xfs_agblock_t agbno;
xfs_extlen_t aglen;
xfs_agblock_t rbno;
xfs_extlen_t rlen;
struct xfs_bmbt_irec map;
int nmaps;
int error = 0;
ASSERT(xfs_is_reflink_inode(ip));
fbno = 0;
end = XFS_B_TO_FSB(mp, i_size_read(VFS_I(ip)));
while (end - fbno > 0) {
nmaps = 1;
error = xfs_bmapi_read(ip, fbno, end - fbno, &map, &nmaps, 0);
if (error)
return error;
if (nmaps == 0)
break;
if (map.br_startblock == HOLESTARTBLOCK ||
map.br_startblock == DELAYSTARTBLOCK ||
ISUNWRITTEN(&map))
goto next;
agno = XFS_FSB_TO_AGNO(mp, map.br_startblock);
agbno = XFS_FSB_TO_AGBNO(mp, map.br_startblock);
aglen = map.br_blockcount;
error = xfs_reflink_find_shared(mp, agno, agbno, aglen,
&rbno, &rlen, false);
if (error)
return error;
if (rbno != NULLAGBLOCK)
return 0;
next:
fbno = map.br_startoff + map.br_blockcount;
}
error = xfs_reflink_cancel_cow_blocks(ip, tpp, 0, NULLFILEOFF);
if (error)
return error;
trace_xfs_reflink_unset_inode_flag(ip);
ip->i_d.di_flags2 &= ~XFS_DIFLAG2_REFLINK;
xfs_inode_clear_cowblocks_tag(ip);
xfs_trans_ijoin(*tpp, ip, 0);
xfs_trans_log_inode(*tpp, ip, XFS_ILOG_CORE);
return error;
}
STATIC int
xfs_reflink_try_clear_inode_flag(
struct xfs_inode *ip)
{
struct xfs_mount *mp = ip->i_mount;
struct xfs_trans *tp;
int error = 0;
error = xfs_trans_alloc(mp, &M_RES(mp)->tr_write, 0, 0, 0, &tp);
if (error)
return error;
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, 0);
error = xfs_reflink_clear_inode_flag(ip, &tp);
if (error)
goto cancel;
error = xfs_trans_commit(tp);
if (error)
goto out;
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return 0;
cancel:
xfs_trans_cancel(tp);
out:
xfs_iunlock(ip, XFS_ILOCK_EXCL);
return error;
}
int
xfs_reflink_unshare(
struct xfs_inode *ip,
xfs_off_t offset,
xfs_off_t len)
{
struct xfs_mount *mp = ip->i_mount;
xfs_fileoff_t fbno;
xfs_filblks_t end;
xfs_off_t isize;
int error;
if (!xfs_is_reflink_inode(ip))
return 0;
trace_xfs_reflink_unshare(ip, offset, len);
inode_dio_wait(VFS_I(ip));
xfs_ilock(ip, XFS_ILOCK_EXCL);
fbno = XFS_B_TO_FSBT(mp, offset);
isize = i_size_read(VFS_I(ip));
end = XFS_B_TO_FSB(mp, offset + len);
error = xfs_reflink_dirty_extents(ip, fbno, end, isize);
if (error)
goto out_unlock;
xfs_iunlock(ip, XFS_ILOCK_EXCL);
error = filemap_write_and_wait(VFS_I(ip)->i_mapping);
if (error)
goto out;
error = xfs_reflink_try_clear_inode_flag(ip);
if (error)
goto out;
return 0;
out_unlock:
xfs_iunlock(ip, XFS_ILOCK_EXCL);
out:
trace_xfs_reflink_unshare_error(ip, error, _RET_IP_);
return error;
}
bool
xfs_reflink_has_real_cow_blocks(
struct xfs_inode *ip)
{
struct xfs_bmbt_irec irec;
struct xfs_ifork *ifp;
struct xfs_bmbt_rec_host *gotp;
xfs_extnum_t idx;
if (!xfs_is_reflink_inode(ip))
return false;
ifp = XFS_IFORK_PTR(ip, XFS_COW_FORK);
gotp = xfs_iext_bno_to_ext(ifp, 0, &idx);
while (gotp) {
xfs_bmbt_get_all(gotp, &irec);
if (!isnullstartblock(irec.br_startblock))
return true;
idx++;
if (idx >= ifp->if_bytes / sizeof(xfs_bmbt_rec_t))
break;
gotp = xfs_iext_get_ext(ifp, idx);
}
return false;
}
