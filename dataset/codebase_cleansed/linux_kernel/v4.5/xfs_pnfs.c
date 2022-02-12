int
xfs_break_layouts(
struct inode *inode,
uint *iolock,
bool with_imutex)
{
struct xfs_inode *ip = XFS_I(inode);
int error;
ASSERT(xfs_isilocked(ip, XFS_IOLOCK_SHARED|XFS_IOLOCK_EXCL));
while ((error = break_layout(inode, false) == -EWOULDBLOCK)) {
xfs_iunlock(ip, *iolock);
if (with_imutex && (*iolock & XFS_IOLOCK_EXCL))
inode_unlock(inode);
error = break_layout(inode, true);
*iolock = XFS_IOLOCK_EXCL;
if (with_imutex)
inode_lock(inode);
xfs_ilock(ip, *iolock);
}
return error;
}
int
xfs_fs_get_uuid(
struct super_block *sb,
u8 *buf,
u32 *len,
u64 *offset)
{
struct xfs_mount *mp = XFS_M(sb);
printk_once(KERN_NOTICE
"XFS (%s): using experimental pNFS feature, use at your own risk!\n",
mp->m_fsname);
if (*len < sizeof(uuid_t))
return -EINVAL;
memcpy(buf, &mp->m_sb.sb_uuid, sizeof(uuid_t));
*len = sizeof(uuid_t);
*offset = offsetof(struct xfs_dsb, sb_uuid);
return 0;
}
static void
xfs_bmbt_to_iomap(
struct xfs_inode *ip,
struct iomap *iomap,
struct xfs_bmbt_irec *imap)
{
struct xfs_mount *mp = ip->i_mount;
if (imap->br_startblock == HOLESTARTBLOCK) {
iomap->blkno = IOMAP_NULL_BLOCK;
iomap->type = IOMAP_HOLE;
} else if (imap->br_startblock == DELAYSTARTBLOCK) {
iomap->blkno = IOMAP_NULL_BLOCK;
iomap->type = IOMAP_DELALLOC;
} else {
iomap->blkno =
XFS_FSB_TO_DADDR(ip->i_mount, imap->br_startblock);
if (imap->br_state == XFS_EXT_UNWRITTEN)
iomap->type = IOMAP_UNWRITTEN;
else
iomap->type = IOMAP_MAPPED;
}
iomap->offset = XFS_FSB_TO_B(mp, imap->br_startoff);
iomap->length = XFS_FSB_TO_B(mp, imap->br_blockcount);
}
int
xfs_fs_map_blocks(
struct inode *inode,
loff_t offset,
u64 length,
struct iomap *iomap,
bool write,
u32 *device_generation)
{
struct xfs_inode *ip = XFS_I(inode);
struct xfs_mount *mp = ip->i_mount;
struct xfs_bmbt_irec imap;
xfs_fileoff_t offset_fsb, end_fsb;
loff_t limit;
int bmapi_flags = XFS_BMAPI_ENTIRE;
int nimaps = 1;
uint lock_flags;
int error = 0;
if (XFS_FORCED_SHUTDOWN(mp))
return -EIO;
if (XFS_IS_REALTIME_INODE(ip))
return -ENXIO;
xfs_ilock(ip, XFS_IOLOCK_EXCL);
error = -EINVAL;
limit = mp->m_super->s_maxbytes;
if (!write)
limit = max(limit, round_up(i_size_read(inode),
inode->i_sb->s_blocksize));
if (offset > limit)
goto out_unlock;
if (offset > limit - length)
length = limit - offset;
error = filemap_write_and_wait(inode->i_mapping);
if (error)
goto out_unlock;
error = invalidate_inode_pages2(inode->i_mapping);
if (WARN_ON_ONCE(error))
return error;
end_fsb = XFS_B_TO_FSB(mp, (xfs_ufsize_t)offset + length);
offset_fsb = XFS_B_TO_FSBT(mp, offset);
lock_flags = xfs_ilock_data_map_shared(ip);
error = xfs_bmapi_read(ip, offset_fsb, end_fsb - offset_fsb,
&imap, &nimaps, bmapi_flags);
xfs_iunlock(ip, lock_flags);
if (error)
goto out_unlock;
if (write) {
enum xfs_prealloc_flags flags = 0;
ASSERT(imap.br_startblock != DELAYSTARTBLOCK);
if (!nimaps || imap.br_startblock == HOLESTARTBLOCK) {
xfs_ilock(ip, XFS_ILOCK_SHARED);
error = xfs_iomap_write_direct(ip, offset, length,
&imap, nimaps);
if (error)
goto out_unlock;
flags |= XFS_PREALLOC_SET | XFS_PREALLOC_SYNC;
}
error = xfs_update_prealloc_flags(ip, flags);
if (error)
goto out_unlock;
}
xfs_iunlock(ip, XFS_IOLOCK_EXCL);
xfs_bmbt_to_iomap(ip, iomap, &imap);
*device_generation = mp->m_generation;
return error;
out_unlock:
xfs_iunlock(ip, XFS_IOLOCK_EXCL);
return error;
}
static int
xfs_pnfs_validate_isize(
struct xfs_inode *ip,
xfs_off_t isize)
{
struct xfs_bmbt_irec imap;
int nimaps = 1;
int error = 0;
xfs_ilock(ip, XFS_ILOCK_SHARED);
error = xfs_bmapi_read(ip, XFS_B_TO_FSBT(ip->i_mount, isize - 1), 1,
&imap, &nimaps, 0);
xfs_iunlock(ip, XFS_ILOCK_SHARED);
if (error)
return error;
if (imap.br_startblock == HOLESTARTBLOCK ||
imap.br_startblock == DELAYSTARTBLOCK ||
imap.br_state == XFS_EXT_UNWRITTEN)
return -EIO;
return 0;
}
int
xfs_fs_commit_blocks(
struct inode *inode,
struct iomap *maps,
int nr_maps,
struct iattr *iattr)
{
struct xfs_inode *ip = XFS_I(inode);
struct xfs_mount *mp = ip->i_mount;
struct xfs_trans *tp;
bool update_isize = false;
int error, i;
loff_t size;
ASSERT(iattr->ia_valid & (ATTR_ATIME|ATTR_CTIME|ATTR_MTIME));
xfs_ilock(ip, XFS_IOLOCK_EXCL);
size = i_size_read(inode);
if ((iattr->ia_valid & ATTR_SIZE) && iattr->ia_size > size) {
update_isize = true;
size = iattr->ia_size;
}
for (i = 0; i < nr_maps; i++) {
u64 start, length, end;
start = maps[i].offset;
if (start > size)
continue;
end = start + maps[i].length;
if (end > size)
end = size;
length = end - start;
if (!length)
continue;
error = invalidate_inode_pages2_range(inode->i_mapping,
start >> PAGE_CACHE_SHIFT,
(end - 1) >> PAGE_CACHE_SHIFT);
WARN_ON_ONCE(error);
error = xfs_iomap_write_unwritten(ip, start, length);
if (error)
goto out_drop_iolock;
}
if (update_isize) {
error = xfs_pnfs_validate_isize(ip, size);
if (error)
goto out_drop_iolock;
}
tp = xfs_trans_alloc(mp, XFS_TRANS_SETATTR_NOT_SIZE);
error = xfs_trans_reserve(tp, &M_RES(mp)->tr_ichange, 0, 0);
if (error) {
xfs_trans_cancel(tp);
goto out_drop_iolock;
}
xfs_ilock(ip, XFS_ILOCK_EXCL);
xfs_trans_ijoin(tp, ip, XFS_ILOCK_EXCL);
xfs_trans_log_inode(tp, ip, XFS_ILOG_CORE);
xfs_setattr_time(ip, iattr);
if (update_isize) {
i_size_write(inode, iattr->ia_size);
ip->i_d.di_size = iattr->ia_size;
}
xfs_trans_set_sync(tp);
error = xfs_trans_commit(tp);
out_drop_iolock:
xfs_iunlock(ip, XFS_IOLOCK_EXCL);
return error;
}
