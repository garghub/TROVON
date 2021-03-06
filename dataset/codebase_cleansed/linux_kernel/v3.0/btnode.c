void nilfs_btnode_cache_clear(struct address_space *btnc)
{
invalidate_mapping_pages(btnc, 0, -1);
truncate_inode_pages(btnc, 0);
}
struct buffer_head *
nilfs_btnode_create_block(struct address_space *btnc, __u64 blocknr)
{
struct inode *inode = NILFS_BTNC_I(btnc);
struct buffer_head *bh;
bh = nilfs_grab_buffer(inode, btnc, blocknr, 1 << BH_NILFS_Node);
if (unlikely(!bh))
return NULL;
if (unlikely(buffer_mapped(bh) || buffer_uptodate(bh) ||
buffer_dirty(bh))) {
brelse(bh);
BUG();
}
memset(bh->b_data, 0, 1 << inode->i_blkbits);
bh->b_bdev = inode->i_sb->s_bdev;
bh->b_blocknr = blocknr;
set_buffer_mapped(bh);
set_buffer_uptodate(bh);
unlock_page(bh->b_page);
page_cache_release(bh->b_page);
return bh;
}
int nilfs_btnode_submit_block(struct address_space *btnc, __u64 blocknr,
sector_t pblocknr, int mode,
struct buffer_head **pbh, sector_t *submit_ptr)
{
struct buffer_head *bh;
struct inode *inode = NILFS_BTNC_I(btnc);
struct page *page;
int err;
bh = nilfs_grab_buffer(inode, btnc, blocknr, 1 << BH_NILFS_Node);
if (unlikely(!bh))
return -ENOMEM;
err = -EEXIST;
page = bh->b_page;
if (buffer_uptodate(bh) || buffer_dirty(bh))
goto found;
if (pblocknr == 0) {
pblocknr = blocknr;
if (inode->i_ino != NILFS_DAT_INO) {
struct the_nilfs *nilfs = inode->i_sb->s_fs_info;
err = nilfs_dat_translate(nilfs->ns_dat, blocknr,
&pblocknr);
if (unlikely(err)) {
brelse(bh);
goto out_locked;
}
}
}
if (mode == READA) {
if (pblocknr != *submit_ptr + 1 || !trylock_buffer(bh)) {
err = -EBUSY;
brelse(bh);
goto out_locked;
}
} else {
lock_buffer(bh);
}
if (buffer_uptodate(bh)) {
unlock_buffer(bh);
err = -EEXIST;
goto found;
}
set_buffer_mapped(bh);
bh->b_bdev = inode->i_sb->s_bdev;
bh->b_blocknr = pblocknr;
bh->b_end_io = end_buffer_read_sync;
get_bh(bh);
submit_bh(mode, bh);
bh->b_blocknr = blocknr;
*submit_ptr = pblocknr;
err = 0;
found:
*pbh = bh;
out_locked:
unlock_page(page);
page_cache_release(page);
return err;
}
void nilfs_btnode_delete(struct buffer_head *bh)
{
struct address_space *mapping;
struct page *page = bh->b_page;
pgoff_t index = page_index(page);
int still_dirty;
page_cache_get(page);
lock_page(page);
wait_on_page_writeback(page);
nilfs_forget_buffer(bh);
still_dirty = PageDirty(page);
mapping = page->mapping;
unlock_page(page);
page_cache_release(page);
if (!still_dirty && mapping)
invalidate_inode_pages2_range(mapping, index, index);
}
int nilfs_btnode_prepare_change_key(struct address_space *btnc,
struct nilfs_btnode_chkey_ctxt *ctxt)
{
struct buffer_head *obh, *nbh;
struct inode *inode = NILFS_BTNC_I(btnc);
__u64 oldkey = ctxt->oldkey, newkey = ctxt->newkey;
int err;
if (oldkey == newkey)
return 0;
obh = ctxt->bh;
ctxt->newbh = NULL;
if (inode->i_blkbits == PAGE_CACHE_SHIFT) {
lock_page(obh->b_page);
retry:
err = radix_tree_preload(GFP_NOFS & ~__GFP_HIGHMEM);
if (err)
goto failed_unlock;
if (unlikely(oldkey != obh->b_page->index))
NILFS_PAGE_BUG(obh->b_page,
"invalid oldkey %lld (newkey=%lld)",
(unsigned long long)oldkey,
(unsigned long long)newkey);
spin_lock_irq(&btnc->tree_lock);
err = radix_tree_insert(&btnc->page_tree, newkey, obh->b_page);
spin_unlock_irq(&btnc->tree_lock);
radix_tree_preload_end();
if (!err)
return 0;
else if (err != -EEXIST)
goto failed_unlock;
err = invalidate_inode_pages2_range(btnc, newkey, newkey);
if (!err)
goto retry;
unlock_page(obh->b_page);
}
nbh = nilfs_btnode_create_block(btnc, newkey);
if (!nbh)
return -ENOMEM;
BUG_ON(nbh == obh);
ctxt->newbh = nbh;
return 0;
failed_unlock:
unlock_page(obh->b_page);
return err;
}
void nilfs_btnode_commit_change_key(struct address_space *btnc,
struct nilfs_btnode_chkey_ctxt *ctxt)
{
struct buffer_head *obh = ctxt->bh, *nbh = ctxt->newbh;
__u64 oldkey = ctxt->oldkey, newkey = ctxt->newkey;
struct page *opage;
if (oldkey == newkey)
return;
if (nbh == NULL) {
opage = obh->b_page;
if (unlikely(oldkey != opage->index))
NILFS_PAGE_BUG(opage,
"invalid oldkey %lld (newkey=%lld)",
(unsigned long long)oldkey,
(unsigned long long)newkey);
mark_buffer_dirty(obh);
spin_lock_irq(&btnc->tree_lock);
radix_tree_delete(&btnc->page_tree, oldkey);
radix_tree_tag_set(&btnc->page_tree, newkey,
PAGECACHE_TAG_DIRTY);
spin_unlock_irq(&btnc->tree_lock);
opage->index = obh->b_blocknr = newkey;
unlock_page(opage);
} else {
nilfs_copy_buffer(nbh, obh);
mark_buffer_dirty(nbh);
nbh->b_blocknr = newkey;
ctxt->bh = nbh;
nilfs_btnode_delete(obh);
}
}
void nilfs_btnode_abort_change_key(struct address_space *btnc,
struct nilfs_btnode_chkey_ctxt *ctxt)
{
struct buffer_head *nbh = ctxt->newbh;
__u64 oldkey = ctxt->oldkey, newkey = ctxt->newkey;
if (oldkey == newkey)
return;
if (nbh == NULL) {
spin_lock_irq(&btnc->tree_lock);
radix_tree_delete(&btnc->page_tree, newkey);
spin_unlock_irq(&btnc->tree_lock);
unlock_page(ctxt->bh->b_page);
} else
brelse(nbh);
}
