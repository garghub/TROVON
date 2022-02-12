static int efs_symlink_readpage(struct file *file, struct page *page)
{
char *link = page_address(page);
struct buffer_head * bh;
struct inode * inode = page->mapping->host;
efs_block_t size = inode->i_size;
int err;
err = -ENAMETOOLONG;
if (size > 2 * EFS_BLOCKSIZE)
goto fail;
err = -EIO;
bh = sb_bread(inode->i_sb, efs_bmap(inode, 0));
if (!bh)
goto fail;
memcpy(link, bh->b_data, (size > EFS_BLOCKSIZE) ? EFS_BLOCKSIZE : size);
brelse(bh);
if (size > EFS_BLOCKSIZE) {
bh = sb_bread(inode->i_sb, efs_bmap(inode, 1));
if (!bh)
goto fail;
memcpy(link + EFS_BLOCKSIZE, bh->b_data, size - EFS_BLOCKSIZE);
brelse(bh);
}
link[size] = '\0';
SetPageUptodate(page);
unlock_page(page);
return 0;
fail:
SetPageError(page);
unlock_page(page);
return err;
}
