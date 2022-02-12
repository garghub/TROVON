static struct vxfs_direct *
vxfs_find_entry(struct inode *ip, struct dentry *dp, struct page **ppp)
{
u_long bsize = ip->i_sb->s_blocksize;
const char *name = dp->d_name.name;
int namelen = dp->d_name.len;
loff_t limit = VXFS_DIRROUND(ip->i_size);
struct vxfs_direct *de_exit = NULL;
loff_t pos = 0;
struct vxfs_sb_info *sbi = VXFS_SBI(ip->i_sb);
while (pos < limit) {
struct page *pp;
char *kaddr;
int pg_ofs = pos & ~PAGE_MASK;
pp = vxfs_get_page(ip->i_mapping, pos >> PAGE_SHIFT);
if (IS_ERR(pp))
return NULL;
kaddr = (char *)page_address(pp);
while (pg_ofs < PAGE_SIZE && pos < limit) {
struct vxfs_direct *de;
if ((pos & (bsize - 1)) < 4) {
struct vxfs_dirblk *dbp =
(struct vxfs_dirblk *)
(kaddr + (pos & ~PAGE_MASK));
int overhead = VXFS_DIRBLKOV(sbi, dbp);
pos += overhead;
pg_ofs += overhead;
}
de = (struct vxfs_direct *)(kaddr + pg_ofs);
if (!de->d_reclen) {
pos += bsize - 1;
pos &= ~(bsize - 1);
break;
}
pg_ofs += fs16_to_cpu(sbi, de->d_reclen);
pos += fs16_to_cpu(sbi, de->d_reclen);
if (!de->d_ino)
continue;
if (namelen != fs16_to_cpu(sbi, de->d_namelen))
continue;
if (!memcmp(name, de->d_name, namelen)) {
*ppp = pp;
de_exit = de;
break;
}
}
if (!de_exit)
vxfs_put_page(pp);
else
break;
}
return de_exit;
}
static ino_t
vxfs_inode_by_name(struct inode *dip, struct dentry *dp)
{
struct vxfs_direct *de;
struct page *pp;
ino_t ino = 0;
de = vxfs_find_entry(dip, dp, &pp);
if (de) {
ino = fs32_to_cpu(VXFS_SBI(dip->i_sb), de->d_ino);
kunmap(pp);
put_page(pp);
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
loff_t pos, limit;
struct vxfs_sb_info *sbi = VXFS_SBI(sbp);
if (ctx->pos == 0) {
if (!dir_emit_dot(fp, ctx))
goto out;
ctx->pos++;
}
if (ctx->pos == 1) {
if (!dir_emit(ctx, "..", 2, VXFS_INO(ip)->vii_dotdot, DT_DIR))
goto out;
ctx->pos++;
}
limit = VXFS_DIRROUND(ip->i_size);
if (ctx->pos > limit)
goto out;
pos = ctx->pos & ~3L;
while (pos < limit) {
struct page *pp;
char *kaddr;
int pg_ofs = pos & ~PAGE_MASK;
int rc = 0;
pp = vxfs_get_page(ip->i_mapping, pos >> PAGE_SHIFT);
if (IS_ERR(pp))
return -ENOMEM;
kaddr = (char *)page_address(pp);
while (pg_ofs < PAGE_SIZE && pos < limit) {
struct vxfs_direct *de;
if ((pos & (bsize - 1)) < 4) {
struct vxfs_dirblk *dbp =
(struct vxfs_dirblk *)
(kaddr + (pos & ~PAGE_MASK));
int overhead = VXFS_DIRBLKOV(sbi, dbp);
pos += overhead;
pg_ofs += overhead;
}
de = (struct vxfs_direct *)(kaddr + pg_ofs);
if (!de->d_reclen) {
pos += bsize - 1;
pos &= ~(bsize - 1);
break;
}
pg_ofs += fs16_to_cpu(sbi, de->d_reclen);
pos += fs16_to_cpu(sbi, de->d_reclen);
if (!de->d_ino)
continue;
rc = dir_emit(ctx, de->d_name,
fs16_to_cpu(sbi, de->d_namelen),
fs32_to_cpu(sbi, de->d_ino),
DT_UNKNOWN);
if (!rc) {
pos -= fs16_to_cpu(sbi, de->d_reclen);
break;
}
}
vxfs_put_page(pp);
if (!rc)
break;
}
ctx->pos = pos | 2;
out:
return 0;
}
