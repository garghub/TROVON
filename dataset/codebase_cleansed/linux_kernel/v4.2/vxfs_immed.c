static int
vxfs_immed_readpage(struct file *fp, struct page *pp)
{
struct vxfs_inode_info *vip = VXFS_INO(pp->mapping->host);
u_int64_t offset = (u_int64_t)pp->index << PAGE_CACHE_SHIFT;
caddr_t kaddr;
kaddr = kmap(pp);
memcpy(kaddr, vip->vii_immed.vi_immed + offset, PAGE_CACHE_SIZE);
kunmap(pp);
flush_dcache_page(pp);
SetPageUptodate(pp);
unlock_page(pp);
return 0;
}
