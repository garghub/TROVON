static inline u_long
dir_blocks(struct inode *ip)
{
u_long bsize = ip->i_sb->s_blocksize;
return (ip->i_size + bsize - 1) & ~(bsize - 1);
}
static inline int
vxfs_match(int len, const char * const name, struct vxfs_direct *de)
{
if (len != de->d_namelen)
return 0;
if (!de->d_ino)
return 0;
return !memcmp(name, de->d_name, len);
}
static inline struct vxfs_direct *
vxfs_next_entry(struct vxfs_direct *de)
{
return ((struct vxfs_direct *)((char*)de + de->d_reclen));
}
static struct vxfs_direct *
vxfs_find_entry(struct inode *ip, struct dentry *dp, struct page **ppp)
{
u_long npages, page, nblocks, pblocks, block;
u_long bsize = ip->i_sb->s_blocksize;
const char *name = dp->d_name.name;
int namelen = dp->d_name.len;
npages = dir_pages(ip);
nblocks = dir_blocks(ip);
pblocks = VXFS_BLOCK_PER_PAGE(ip->i_sb);
for (page = 0; page < npages; page++) {
caddr_t kaddr;
struct page *pp;
pp = vxfs_get_page(ip->i_mapping, page);
if (IS_ERR(pp))
continue;
kaddr = (caddr_t)page_address(pp);
for (block = 0; block <= nblocks && block <= pblocks; block++) {
caddr_t baddr, limit;
struct vxfs_dirblk *dbp;
struct vxfs_direct *de;
baddr = kaddr + (block * bsize);
limit = baddr + bsize - VXFS_DIRLEN(1);
dbp = (struct vxfs_dirblk *)baddr;
de = (struct vxfs_direct *)(baddr + VXFS_DIRBLKOV(dbp));
for (; (caddr_t)de <= limit; de = vxfs_next_entry(de)) {
if (!de->d_reclen)
break;
if (!de->d_ino)
continue;
if (vxfs_match(namelen, name, de)) {
*ppp = pp;
return (de);
}
}
}
vxfs_put_page(pp);
}
return NULL;
}
static ino_t
vxfs_inode_by_name(struct inode *dip, struct dentry *dp)
{
struct vxfs_direct *de;
struct page *pp;
ino_t ino = 0;
de = vxfs_find_entry(dip, dp, &pp);
if (de) {
ino = de->d_ino;
kunmap(pp);
page_cache_release(pp);
}
return (ino);
}
static struct dentry *
vxfs_lookup(struct inode *dip, struct dentry *dp, unsigned int flags)
{
struct inode *ip = NULL;
ino_t ino;
if (dp->d_name.len > VXFS_NAMELEN)
return ERR_PTR(-ENAMETOOLONG);
ino = vxfs_inode_by_name(dip, dp);
if (ino) {
ip = vxfs_iget(dip->i_sb, ino);
if (IS_ERR(ip))
return ERR_CAST(ip);
}
d_add(dp, ip);
return NULL;
}
static int
vxfs_readdir(struct file *fp, struct dir_context *ctx)
{
struct inode *ip = file_inode(fp);
struct super_block *sbp = ip->i_sb;
u_long bsize = sbp->s_blocksize;
u_long page, npages, block, pblocks, nblocks, offset;
loff_t pos;
if (ctx->pos == 0) {
if (!dir_emit_dot(fp, ctx))
return 0;
ctx->pos = 1;
}
if (ctx->pos == 1) {
if (!dir_emit(ctx, "..", 2, VXFS_INO(ip)->vii_dotdot, DT_DIR))
return 0;
ctx->pos = 2;
}
pos = ctx->pos - 2;
if (pos > VXFS_DIRROUND(ip->i_size))
return 0;
npages = dir_pages(ip);
nblocks = dir_blocks(ip);
pblocks = VXFS_BLOCK_PER_PAGE(sbp);
page = pos >> PAGE_CACHE_SHIFT;
offset = pos & ~PAGE_CACHE_MASK;
block = (u_long)(pos >> sbp->s_blocksize_bits) % pblocks;
for (; page < npages; page++, block = 0) {
char *kaddr;
struct page *pp;
pp = vxfs_get_page(ip->i_mapping, page);
if (IS_ERR(pp))
continue;
kaddr = (char *)page_address(pp);
for (; block <= nblocks && block <= pblocks; block++) {
char *baddr, *limit;
struct vxfs_dirblk *dbp;
struct vxfs_direct *de;
baddr = kaddr + (block * bsize);
limit = baddr + bsize - VXFS_DIRLEN(1);
dbp = (struct vxfs_dirblk *)baddr;
de = (struct vxfs_direct *)
(offset ?
(kaddr + offset) :
(baddr + VXFS_DIRBLKOV(dbp)));
for (; (char *)de <= limit; de = vxfs_next_entry(de)) {
if (!de->d_reclen)
break;
if (!de->d_ino)
continue;
offset = (char *)de - kaddr;
ctx->pos = ((page << PAGE_CACHE_SHIFT) | offset) + 2;
if (!dir_emit(ctx, de->d_name, de->d_namelen,
de->d_ino, DT_UNKNOWN)) {
vxfs_put_page(pp);
return 0;
}
}
offset = 0;
}
vxfs_put_page(pp);
offset = 0;
}
ctx->pos = ((page << PAGE_CACHE_SHIFT) | offset) + 2;
return 0;
}
