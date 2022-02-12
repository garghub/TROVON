int nilfs_gccache_submit_read_data(struct inode *inode, sector_t blkoff,
sector_t pbn, __u64 vbn,
struct buffer_head **out_bh)
{
struct buffer_head *bh;
int err;
bh = nilfs_grab_buffer(inode, inode->i_mapping, blkoff, 0);
if (unlikely(!bh))
return -ENOMEM;
if (buffer_uptodate(bh))
goto out;
if (pbn == 0) {
struct the_nilfs *nilfs = inode->i_sb->s_fs_info;
err = nilfs_dat_translate(nilfs->ns_dat, vbn, &pbn);
if (unlikely(err)) {
brelse(bh);
goto failed;
}
}
lock_buffer(bh);
if (buffer_uptodate(bh)) {
unlock_buffer(bh);
goto out;
}
if (!buffer_mapped(bh)) {
bh->b_bdev = inode->i_sb->s_bdev;
set_buffer_mapped(bh);
}
bh->b_blocknr = pbn;
bh->b_end_io = end_buffer_read_sync;
get_bh(bh);
submit_bh(READ, bh);
if (vbn)
bh->b_blocknr = vbn;
out:
err = 0;
*out_bh = bh;
failed:
unlock_page(bh->b_page);
page_cache_release(bh->b_page);
return err;
}
int nilfs_gccache_submit_read_node(struct inode *inode, sector_t pbn,
__u64 vbn, struct buffer_head **out_bh)
{
int ret;
ret = nilfs_btnode_submit_block(&NILFS_I(inode)->i_btnode_cache,
vbn ? : pbn, pbn, READ, out_bh, &pbn);
if (ret == -EEXIST)
ret = 0;
return ret;
}
int nilfs_gccache_wait_and_mark_dirty(struct buffer_head *bh)
{
wait_on_buffer(bh);
if (!buffer_uptodate(bh))
return -EIO;
if (buffer_dirty(bh))
return -EEXIST;
if (buffer_nilfs_node(bh) && nilfs_btree_broken_node_block(bh)) {
clear_buffer_uptodate(bh);
return -EIO;
}
mark_buffer_dirty(bh);
return 0;
}
int nilfs_init_gcinode(struct inode *inode)
{
struct nilfs_inode_info *ii = NILFS_I(inode);
inode->i_mode = S_IFREG;
mapping_set_gfp_mask(inode->i_mapping, GFP_NOFS);
inode->i_mapping->a_ops = &empty_aops;
ii->i_flags = 0;
nilfs_bmap_init_gc(ii->i_bmap);
return 0;
}
void nilfs_remove_all_gcinodes(struct the_nilfs *nilfs)
{
struct list_head *head = &nilfs->ns_gc_inodes;
struct nilfs_inode_info *ii;
while (!list_empty(head)) {
ii = list_first_entry(head, struct nilfs_inode_info, i_dirty);
list_del_init(&ii->i_dirty);
truncate_inode_pages(&ii->vfs_inode.i_data, 0);
nilfs_btnode_cache_clear(&ii->i_btnode_cache);
iput(&ii->vfs_inode);
}
}
