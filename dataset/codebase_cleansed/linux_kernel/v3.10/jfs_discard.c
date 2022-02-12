void jfs_issue_discard(struct inode *ip, u64 blkno, u64 nblocks)
{
struct super_block *sb = ip->i_sb;
int r = 0;
r = sb_issue_discard(sb, blkno, nblocks, GFP_NOFS, 0);
if (unlikely(r != 0)) {
jfs_err("JFS: sb_issue_discard" \
"(%p, %llu, %llu, GFP_NOFS, 0) = %d => failed!\n",
sb, (unsigned long long)blkno,
(unsigned long long)nblocks, r);
}
jfs_info("JFS: sb_issue_discard" \
"(%p, %llu, %llu, GFP_NOFS, 0) = %d\n",
sb, (unsigned long long)blkno,
(unsigned long long)nblocks, r);
return;
}
int jfs_ioc_trim(struct inode *ip, struct fstrim_range *range)
{
struct inode *ipbmap = JFS_SBI(ip->i_sb)->ipbmap;
struct bmap *bmp = JFS_SBI(ip->i_sb)->bmap;
struct super_block *sb = ipbmap->i_sb;
int agno, agno_end;
u64 start, end, minlen;
u64 trimmed = 0;
start = range->start >> sb->s_blocksize_bits;
end = start + (range->len >> sb->s_blocksize_bits) - 1;
minlen = range->minlen >> sb->s_blocksize_bits;
if (minlen == 0)
minlen = 1;
if (minlen > bmp->db_agsize ||
start >= bmp->db_mapsize ||
range->len < sb->s_blocksize)
return -EINVAL;
if (end >= bmp->db_mapsize)
end = bmp->db_mapsize - 1;
agno = BLKTOAG(start, JFS_SBI(ip->i_sb));
agno_end = BLKTOAG(end, JFS_SBI(ip->i_sb));
while (agno <= agno_end) {
trimmed += dbDiscardAG(ip, agno, minlen);
agno++;
}
range->len = trimmed << sb->s_blocksize_bits;
return 0;
}
