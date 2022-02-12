static int hfs_get_last_session(struct super_block *sb,
sector_t *start, sector_t *size)
{
struct cdrom_multisession ms_info;
struct cdrom_tocentry te;
int res;
*start = 0;
*size = sb->s_bdev->bd_inode->i_size >> 9;
if (HFS_SB(sb)->session >= 0) {
te.cdte_track = HFS_SB(sb)->session;
te.cdte_format = CDROM_LBA;
res = ioctl_by_bdev(sb->s_bdev, CDROMREADTOCENTRY, (unsigned long)&te);
if (!res && (te.cdte_ctrl & CDROM_DATA_TRACK) == 4) {
*start = (sector_t)te.cdte_addr.lba << 2;
return 0;
}
pr_err("invalid session number or type of track\n");
return -EINVAL;
}
ms_info.addr_format = CDROM_LBA;
res = ioctl_by_bdev(sb->s_bdev, CDROMMULTISESSION, (unsigned long)&ms_info);
if (!res && ms_info.xa_flag)
*start = (sector_t)ms_info.addr.lba << 2;
return 0;
}
int hfs_mdb_get(struct super_block *sb)
{
struct buffer_head *bh;
struct hfs_mdb *mdb, *mdb2;
unsigned int block;
char *ptr;
int off2, len, size, sect;
sector_t part_start, part_size;
loff_t off;
__be16 attrib;
size = sb_min_blocksize(sb, HFS_SECTOR_SIZE);
if (!size)
return -EINVAL;
if (hfs_get_last_session(sb, &part_start, &part_size))
return -EINVAL;
while (1) {
bh = sb_bread512(sb, part_start + HFS_MDB_BLK, mdb);
if (!bh)
goto out;
if (mdb->drSigWord == cpu_to_be16(HFS_SUPER_MAGIC))
break;
brelse(bh);
if (hfs_part_find(sb, &part_start, &part_size))
goto out;
}
HFS_SB(sb)->alloc_blksz = size = be32_to_cpu(mdb->drAlBlkSiz);
if (!size || (size & (HFS_SECTOR_SIZE - 1))) {
pr_err("bad allocation block size %d\n", size);
goto out_bh;
}
size = min(HFS_SB(sb)->alloc_blksz, (u32)PAGE_SIZE);
while (size & (size - 1))
size -= HFS_SECTOR_SIZE;
sect = be16_to_cpu(mdb->drAlBlSt) + part_start;
while (sect & ((size - 1) >> HFS_SECTOR_SIZE_BITS))
size >>= 1;
while (HFS_SB(sb)->alloc_blksz & (size - 1))
size >>= 1;
brelse(bh);
if (!sb_set_blocksize(sb, size)) {
pr_err("unable to set blocksize to %u\n", size);
goto out;
}
bh = sb_bread512(sb, part_start + HFS_MDB_BLK, mdb);
if (!bh)
goto out;
if (mdb->drSigWord != cpu_to_be16(HFS_SUPER_MAGIC))
goto out_bh;
HFS_SB(sb)->mdb_bh = bh;
HFS_SB(sb)->mdb = mdb;
HFS_SB(sb)->part_start = part_start;
HFS_SB(sb)->fs_ablocks = be16_to_cpu(mdb->drNmAlBlks);
HFS_SB(sb)->fs_div = HFS_SB(sb)->alloc_blksz >> sb->s_blocksize_bits;
HFS_SB(sb)->clumpablks = be32_to_cpu(mdb->drClpSiz) /
HFS_SB(sb)->alloc_blksz;
if (!HFS_SB(sb)->clumpablks)
HFS_SB(sb)->clumpablks = 1;
HFS_SB(sb)->fs_start = (be16_to_cpu(mdb->drAlBlSt) + part_start) >>
(sb->s_blocksize_bits - HFS_SECTOR_SIZE_BITS);
HFS_SB(sb)->free_ablocks = be16_to_cpu(mdb->drFreeBks);
HFS_SB(sb)->next_id = be32_to_cpu(mdb->drNxtCNID);
HFS_SB(sb)->root_files = be16_to_cpu(mdb->drNmFls);
HFS_SB(sb)->root_dirs = be16_to_cpu(mdb->drNmRtDirs);
HFS_SB(sb)->file_count = be32_to_cpu(mdb->drFilCnt);
HFS_SB(sb)->folder_count = be32_to_cpu(mdb->drDirCnt);
sect = part_start + part_size - 2;
bh = sb_bread512(sb, sect, mdb2);
if (bh) {
if (mdb2->drSigWord == cpu_to_be16(HFS_SUPER_MAGIC)) {
HFS_SB(sb)->alt_mdb_bh = bh;
HFS_SB(sb)->alt_mdb = mdb2;
} else
brelse(bh);
}
if (!HFS_SB(sb)->alt_mdb) {
pr_warn("unable to locate alternate MDB\n");
pr_warn("continuing without an alternate MDB\n");
}
HFS_SB(sb)->bitmap = kmalloc(8192, GFP_KERNEL);
if (!HFS_SB(sb)->bitmap)
goto out;
block = be16_to_cpu(mdb->drVBMSt) + part_start;
off = (loff_t)block << HFS_SECTOR_SIZE_BITS;
size = (HFS_SB(sb)->fs_ablocks + 8) / 8;
ptr = (u8 *)HFS_SB(sb)->bitmap;
while (size) {
bh = sb_bread(sb, off >> sb->s_blocksize_bits);
if (!bh) {
pr_err("unable to read volume bitmap\n");
goto out;
}
off2 = off & (sb->s_blocksize - 1);
len = min((int)sb->s_blocksize - off2, size);
memcpy(ptr, bh->b_data + off2, len);
brelse(bh);
ptr += len;
off += len;
size -= len;
}
HFS_SB(sb)->ext_tree = hfs_btree_open(sb, HFS_EXT_CNID, hfs_ext_keycmp);
if (!HFS_SB(sb)->ext_tree) {
pr_err("unable to open extent tree\n");
goto out;
}
HFS_SB(sb)->cat_tree = hfs_btree_open(sb, HFS_CAT_CNID, hfs_cat_keycmp);
if (!HFS_SB(sb)->cat_tree) {
pr_err("unable to open catalog tree\n");
goto out;
}
attrib = mdb->drAtrb;
if (!(attrib & cpu_to_be16(HFS_SB_ATTRIB_UNMNT))) {
pr_warn("filesystem was not cleanly unmounted, running fsck.hfs is recommended. mounting read-only.\n");
sb->s_flags |= MS_RDONLY;
}
if ((attrib & cpu_to_be16(HFS_SB_ATTRIB_SLOCK))) {
pr_warn("filesystem is marked locked, mounting read-only.\n");
sb->s_flags |= MS_RDONLY;
}
if (!(sb->s_flags & MS_RDONLY)) {
attrib &= cpu_to_be16(~HFS_SB_ATTRIB_UNMNT);
attrib |= cpu_to_be16(HFS_SB_ATTRIB_INCNSTNT);
mdb->drAtrb = attrib;
be32_add_cpu(&mdb->drWrCnt, 1);
mdb->drLsMod = hfs_mtime();
mark_buffer_dirty(HFS_SB(sb)->mdb_bh);
sync_dirty_buffer(HFS_SB(sb)->mdb_bh);
}
return 0;
out_bh:
brelse(bh);
out:
hfs_mdb_put(sb);
return -EIO;
}
void hfs_mdb_commit(struct super_block *sb)
{
struct hfs_mdb *mdb = HFS_SB(sb)->mdb;
if (sb->s_flags & MS_RDONLY)
return;
lock_buffer(HFS_SB(sb)->mdb_bh);
if (test_and_clear_bit(HFS_FLG_MDB_DIRTY, &HFS_SB(sb)->flags)) {
mdb->drLsMod = hfs_mtime();
mdb->drFreeBks = cpu_to_be16(HFS_SB(sb)->free_ablocks);
mdb->drNxtCNID = cpu_to_be32(HFS_SB(sb)->next_id);
mdb->drNmFls = cpu_to_be16(HFS_SB(sb)->root_files);
mdb->drNmRtDirs = cpu_to_be16(HFS_SB(sb)->root_dirs);
mdb->drFilCnt = cpu_to_be32(HFS_SB(sb)->file_count);
mdb->drDirCnt = cpu_to_be32(HFS_SB(sb)->folder_count);
mark_buffer_dirty(HFS_SB(sb)->mdb_bh);
}
if (test_and_clear_bit(HFS_FLG_ALT_MDB_DIRTY, &HFS_SB(sb)->flags) &&
HFS_SB(sb)->alt_mdb) {
hfs_inode_write_fork(HFS_SB(sb)->ext_tree->inode, mdb->drXTExtRec,
&mdb->drXTFlSize, NULL);
hfs_inode_write_fork(HFS_SB(sb)->cat_tree->inode, mdb->drCTExtRec,
&mdb->drCTFlSize, NULL);
lock_buffer(HFS_SB(sb)->alt_mdb_bh);
memcpy(HFS_SB(sb)->alt_mdb, HFS_SB(sb)->mdb, HFS_SECTOR_SIZE);
HFS_SB(sb)->alt_mdb->drAtrb |= cpu_to_be16(HFS_SB_ATTRIB_UNMNT);
HFS_SB(sb)->alt_mdb->drAtrb &= cpu_to_be16(~HFS_SB_ATTRIB_INCNSTNT);
unlock_buffer(HFS_SB(sb)->alt_mdb_bh);
mark_buffer_dirty(HFS_SB(sb)->alt_mdb_bh);
sync_dirty_buffer(HFS_SB(sb)->alt_mdb_bh);
}
if (test_and_clear_bit(HFS_FLG_BITMAP_DIRTY, &HFS_SB(sb)->flags)) {
struct buffer_head *bh;
sector_t block;
char *ptr;
int off, size, len;
block = be16_to_cpu(HFS_SB(sb)->mdb->drVBMSt) + HFS_SB(sb)->part_start;
off = (block << HFS_SECTOR_SIZE_BITS) & (sb->s_blocksize - 1);
block >>= sb->s_blocksize_bits - HFS_SECTOR_SIZE_BITS;
size = (HFS_SB(sb)->fs_ablocks + 7) / 8;
ptr = (u8 *)HFS_SB(sb)->bitmap;
while (size) {
bh = sb_bread(sb, block);
if (!bh) {
pr_err("unable to read volume bitmap\n");
break;
}
len = min((int)sb->s_blocksize - off, size);
lock_buffer(bh);
memcpy(bh->b_data + off, ptr, len);
unlock_buffer(bh);
mark_buffer_dirty(bh);
brelse(bh);
block++;
off = 0;
ptr += len;
size -= len;
}
}
unlock_buffer(HFS_SB(sb)->mdb_bh);
}
void hfs_mdb_close(struct super_block *sb)
{
if (sb->s_flags & MS_RDONLY)
return;
HFS_SB(sb)->mdb->drAtrb |= cpu_to_be16(HFS_SB_ATTRIB_UNMNT);
HFS_SB(sb)->mdb->drAtrb &= cpu_to_be16(~HFS_SB_ATTRIB_INCNSTNT);
mark_buffer_dirty(HFS_SB(sb)->mdb_bh);
}
void hfs_mdb_put(struct super_block *sb)
{
if (!HFS_SB(sb))
return;
hfs_btree_close(HFS_SB(sb)->ext_tree);
hfs_btree_close(HFS_SB(sb)->cat_tree);
brelse(HFS_SB(sb)->mdb_bh);
brelse(HFS_SB(sb)->alt_mdb_bh);
unload_nls(HFS_SB(sb)->nls_io);
unload_nls(HFS_SB(sb)->nls_disk);
kfree(HFS_SB(sb)->bitmap);
kfree(HFS_SB(sb));
sb->s_fs_info = NULL;
}
