inline void
vxfs_put_page(struct page *pp)
{
kunmap(pp);
put_page(pp);
}
struct page *
vxfs_get_page(struct address_space *mapping, u_long n)
{
struct page * pp;
pp = read_mapping_page(mapping, n, NULL);
if (!IS_ERR(pp)) {
kmap(pp);
if (PageError(pp))
goto fail;
}
return (pp);
fail:
vxfs_put_page(pp);
return ERR_PTR(-EIO);
}
struct buffer_head *
vxfs_bread(struct inode *ip, int block)
{
struct buffer_head *bp;
daddr_t pblock;
pblock = vxfs_bmap1(ip, block);
bp = sb_bread(ip->i_sb, pblock);
return (bp);
}
static int
vxfs_getblk(struct inode *ip, sector_t iblock,
struct buffer_head *bp, int create)
{
daddr_t pblock;
pblock = vxfs_bmap1(ip, iblock);
if (pblock != 0) {
map_bh(bp, ip->i_sb, pblock);
return 0;
}
return -EIO;
}
static int
vxfs_readpage(struct file *file, struct page *page)
{
return block_read_full_page(page, vxfs_getblk);
}
static sector_t
vxfs_bmap(struct address_space *mapping, sector_t block)
{
return generic_block_bmap(mapping, block, vxfs_getblk);
}
