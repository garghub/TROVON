int squashfs_readpage_block(struct page *page, u64 block, int bsize)
{
struct inode *i = page->mapping->host;
struct squashfs_cache_entry *buffer = squashfs_get_datablock(i->i_sb,
block, bsize);
int res = buffer->error;
if (res)
ERROR("Unable to read page, block %llx, size %x\n", block,
bsize);
else
squashfs_copy_cache(page, buffer, buffer->length, 0);
squashfs_cache_put(buffer);
return res;
}
