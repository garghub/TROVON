static int
befs_readpage(struct file *file, struct page *page)
{
return block_read_full_page(page, befs_get_block);
}
static sector_t
befs_bmap(struct address_space *mapping, sector_t block)
{
return generic_block_bmap(mapping, block, befs_get_block);
}
static int
befs_get_block(struct inode *inode, sector_t block,
struct buffer_head *bh_result, int create)
{
struct super_block *sb = inode->i_sb;
befs_data_stream *ds = &BEFS_I(inode)->i_data.ds;
befs_block_run run = BAD_IADDR;
int res = 0;
ulong disk_off;
befs_debug(sb, "---> befs_get_block() for inode %lu, block %ld",
(unsigned long)inode->i_ino, (long)block);
if (create) {
befs_error(sb, "befs_get_block() was asked to write to "
"block %ld in inode %lu", (long)block,
(unsigned long)inode->i_ino);
return -EPERM;
}
res = befs_fblock2brun(sb, ds, block, &run);
if (res != BEFS_OK) {
befs_error(sb,
"<--- %s for inode %lu, block %ld ERROR",
__func__, (unsigned long)inode->i_ino,
(long)block);
return -EFBIG;
}
disk_off = (ulong) iaddr2blockno(sb, &run);
map_bh(bh_result, inode->i_sb, disk_off);
befs_debug(sb, "<--- %s for inode %lu, block %ld, disk address %lu",
__func__, (unsigned long)inode->i_ino, (long)block,
(unsigned long)disk_off);
return 0;
}
static struct dentry *
befs_lookup(struct inode *dir, struct dentry *dentry, unsigned int flags)
{
struct inode *inode;
struct super_block *sb = dir->i_sb;
const befs_data_stream *ds = &BEFS_I(dir)->i_data.ds;
befs_off_t offset;
int ret;
int utfnamelen;
char *utfname;
const char *name = dentry->d_name.name;
befs_debug(sb, "---> %s name %pd inode %ld", __func__,
dentry, dir->i_ino);
if (BEFS_SB(sb)->nls) {
ret =
befs_nls2utf(sb, name, strlen(name), &utfname, &utfnamelen);
if (ret < 0) {
befs_debug(sb, "<--- %s ERROR", __func__);
return ERR_PTR(ret);
}
ret = befs_btree_find(sb, ds, utfname, &offset);
kfree(utfname);
} else {
ret = befs_btree_find(sb, ds, dentry->d_name.name, &offset);
}
if (ret == BEFS_BT_NOT_FOUND) {
befs_debug(sb, "<--- %s %pd not found", __func__, dentry);
return ERR_PTR(-ENOENT);
} else if (ret != BEFS_OK || offset == 0) {
befs_warning(sb, "<--- %s Error", __func__);
return ERR_PTR(-ENODATA);
}
inode = befs_iget(dir->i_sb, (ino_t) offset);
if (IS_ERR(inode))
return ERR_CAST(inode);
d_add(dentry, inode);
befs_debug(sb, "<--- %s", __func__);
return NULL;
}
static int
befs_readdir(struct file *file, struct dir_context *ctx)
{
struct inode *inode = file_inode(file);
struct super_block *sb = inode->i_sb;
const befs_data_stream *ds = &BEFS_I(inode)->i_data.ds;
befs_off_t value;
int result;
size_t keysize;
unsigned char d_type;
char keybuf[BEFS_NAME_LEN + 1];
befs_debug(sb, "---> %s name %pD, inode %ld, ctx->pos %lld",
__func__, file, inode->i_ino, ctx->pos);
more:
result = befs_btree_read(sb, ds, ctx->pos, BEFS_NAME_LEN + 1,
keybuf, &keysize, &value);
if (result == BEFS_ERR) {
befs_debug(sb, "<--- %s ERROR", __func__);
befs_error(sb, "IO error reading %pD (inode %lu)",
file, inode->i_ino);
return -EIO;
} else if (result == BEFS_BT_END) {
befs_debug(sb, "<--- %s END", __func__);
return 0;
} else if (result == BEFS_BT_EMPTY) {
befs_debug(sb, "<--- %s Empty directory", __func__);
return 0;
}
d_type = DT_UNKNOWN;
if (BEFS_SB(sb)->nls) {
char *nlsname;
int nlsnamelen;
result =
befs_utf2nls(sb, keybuf, keysize, &nlsname, &nlsnamelen);
if (result < 0) {
befs_debug(sb, "<--- %s ERROR", __func__);
return result;
}
if (!dir_emit(ctx, nlsname, nlsnamelen,
(ino_t) value, d_type)) {
kfree(nlsname);
return 0;
}
kfree(nlsname);
} else {
if (!dir_emit(ctx, keybuf, keysize,
(ino_t) value, d_type))
return 0;
}
ctx->pos++;
goto more;
}
static struct inode *
befs_alloc_inode(struct super_block *sb)
{
struct befs_inode_info *bi;
bi = kmem_cache_alloc(befs_inode_cachep, GFP_KERNEL);
if (!bi)
return NULL;
return &bi->vfs_inode;
}
static void befs_i_callback(struct rcu_head *head)
{
struct inode *inode = container_of(head, struct inode, i_rcu);
kmem_cache_free(befs_inode_cachep, BEFS_I(inode));
}
static void befs_destroy_inode(struct inode *inode)
{
call_rcu(&inode->i_rcu, befs_i_callback);
}
static void init_once(void *foo)
{
struct befs_inode_info *bi = (struct befs_inode_info *) foo;
inode_init_once(&bi->vfs_inode);
}
static struct inode *befs_iget(struct super_block *sb, unsigned long ino)
{
struct buffer_head *bh;
befs_inode *raw_inode;
struct befs_sb_info *befs_sb = BEFS_SB(sb);
struct befs_inode_info *befs_ino;
struct inode *inode;
long ret = -EIO;
befs_debug(sb, "---> %s inode = %lu", __func__, ino);
inode = iget_locked(sb, ino);
if (!inode)
return ERR_PTR(-ENOMEM);
if (!(inode->i_state & I_NEW))
return inode;
befs_ino = BEFS_I(inode);
befs_ino->i_inode_num = blockno2iaddr(sb, inode->i_ino);
befs_debug(sb, " real inode number [%u, %hu, %hu]",
befs_ino->i_inode_num.allocation_group,
befs_ino->i_inode_num.start, befs_ino->i_inode_num.len);
bh = befs_bread(sb, inode->i_ino);
if (!bh) {
befs_error(sb, "unable to read inode block - "
"inode = %lu", inode->i_ino);
goto unacquire_none;
}
raw_inode = (befs_inode *) bh->b_data;
befs_dump_inode(sb, raw_inode);
if (befs_check_inode(sb, raw_inode, inode->i_ino) != BEFS_OK) {
befs_error(sb, "Bad inode: %lu", inode->i_ino);
goto unacquire_bh;
}
inode->i_mode = (umode_t) fs32_to_cpu(sb, raw_inode->mode);
inode->i_uid = befs_sb->mount_opts.use_uid ?
befs_sb->mount_opts.uid :
make_kuid(&init_user_ns, fs32_to_cpu(sb, raw_inode->uid));
inode->i_gid = befs_sb->mount_opts.use_gid ?
befs_sb->mount_opts.gid :
make_kgid(&init_user_ns, fs32_to_cpu(sb, raw_inode->gid));
set_nlink(inode, 1);
inode->i_mtime.tv_sec =
fs64_to_cpu(sb, raw_inode->last_modified_time) >> 16;
inode->i_mtime.tv_nsec = 0;
inode->i_ctime = inode->i_mtime;
inode->i_atime = inode->i_mtime;
befs_ino->i_inode_num = fsrun_to_cpu(sb, raw_inode->inode_num);
befs_ino->i_parent = fsrun_to_cpu(sb, raw_inode->parent);
befs_ino->i_attribute = fsrun_to_cpu(sb, raw_inode->attributes);
befs_ino->i_flags = fs32_to_cpu(sb, raw_inode->flags);
if (S_ISLNK(inode->i_mode) && !(befs_ino->i_flags & BEFS_LONG_SYMLINK)){
inode->i_size = 0;
inode->i_blocks = befs_sb->block_size / VFS_BLOCK_SIZE;
strlcpy(befs_ino->i_data.symlink, raw_inode->data.symlink,
BEFS_SYMLINK_LEN);
} else {
int num_blks;
befs_ino->i_data.ds =
fsds_to_cpu(sb, &raw_inode->data.datastream);
num_blks = befs_count_blocks(sb, &befs_ino->i_data.ds);
inode->i_blocks =
num_blks * (befs_sb->block_size / VFS_BLOCK_SIZE);
inode->i_size = befs_ino->i_data.ds.size;
}
inode->i_mapping->a_ops = &befs_aops;
if (S_ISREG(inode->i_mode)) {
inode->i_fop = &generic_ro_fops;
} else if (S_ISDIR(inode->i_mode)) {
inode->i_op = &befs_dir_inode_operations;
inode->i_fop = &befs_dir_operations;
} else if (S_ISLNK(inode->i_mode)) {
if (befs_ino->i_flags & BEFS_LONG_SYMLINK) {
inode->i_op = &page_symlink_inode_operations;
inode_nohighmem(inode);
inode->i_mapping->a_ops = &befs_symlink_aops;
} else {
inode->i_link = befs_ino->i_data.symlink;
inode->i_op = &simple_symlink_inode_operations;
}
} else {
befs_error(sb, "Inode %lu is not a regular file, "
"directory or symlink. THAT IS WRONG! BeFS has no "
"on disk special files", inode->i_ino);
goto unacquire_bh;
}
brelse(bh);
befs_debug(sb, "<--- %s", __func__);
unlock_new_inode(inode);
return inode;
unacquire_bh:
brelse(bh);
unacquire_none:
iget_failed(inode);
befs_debug(sb, "<--- %s - Bad inode", __func__);
return ERR_PTR(ret);
}
static int __init
befs_init_inodecache(void)
{
befs_inode_cachep = kmem_cache_create("befs_inode_cache",
sizeof (struct befs_inode_info),
0, (SLAB_RECLAIM_ACCOUNT|
SLAB_MEM_SPREAD|SLAB_ACCOUNT),
init_once);
if (befs_inode_cachep == NULL) {
pr_err("%s: Couldn't initialize inode slabcache\n", __func__);
return -ENOMEM;
}
return 0;
}
static void
befs_destroy_inodecache(void)
{
rcu_barrier();
kmem_cache_destroy(befs_inode_cachep);
}
static int befs_symlink_readpage(struct file *unused, struct page *page)
{
struct inode *inode = page->mapping->host;
struct super_block *sb = inode->i_sb;
struct befs_inode_info *befs_ino = BEFS_I(inode);
befs_data_stream *data = &befs_ino->i_data.ds;
befs_off_t len = data->size;
char *link = page_address(page);
if (len == 0 || len > PAGE_SIZE) {
befs_error(sb, "Long symlink with illegal length");
goto fail;
}
befs_debug(sb, "Follow long symlink");
if (befs_read_lsymlink(sb, data, link, len) != len) {
befs_error(sb, "Failed to read entire long symlink");
goto fail;
}
link[len - 1] = '\0';
SetPageUptodate(page);
unlock_page(page);
return 0;
fail:
SetPageError(page);
unlock_page(page);
return -EIO;
}
static int
befs_utf2nls(struct super_block *sb, const char *in,
int in_len, char **out, int *out_len)
{
struct nls_table *nls = BEFS_SB(sb)->nls;
int i, o;
unicode_t uni;
int unilen, utflen;
char *result;
int maxlen = in_len + 1;
befs_debug(sb, "---> %s", __func__);
if (!nls) {
befs_error(sb, "%s called with no NLS table loaded", __func__);
return -EINVAL;
}
*out = result = kmalloc(maxlen, GFP_NOFS);
if (!*out) {
befs_error(sb, "%s cannot allocate memory", __func__);
*out_len = 0;
return -ENOMEM;
}
for (i = o = 0; i < in_len; i += utflen, o += unilen) {
utflen = utf8_to_utf32(&in[i], in_len - i, &uni);
if (utflen < 0)
goto conv_err;
if (uni > MAX_WCHAR_T)
goto conv_err;
unilen = nls->uni2char(uni, &result[o], in_len - o);
if (unilen < 0)
goto conv_err;
}
result[o] = '\0';
*out_len = o;
befs_debug(sb, "<--- %s", __func__);
return o;
conv_err:
befs_error(sb, "Name using character set %s contains a character that "
"cannot be converted to unicode.", nls->charset);
befs_debug(sb, "<--- %s", __func__);
kfree(result);
return -EILSEQ;
}
static int
befs_nls2utf(struct super_block *sb, const char *in,
int in_len, char **out, int *out_len)
{
struct nls_table *nls = BEFS_SB(sb)->nls;
int i, o;
wchar_t uni;
int unilen, utflen;
char *result;
int maxlen = (3 * in_len) + 1;
befs_debug(sb, "---> %s\n", __func__);
if (!nls) {
befs_error(sb, "%s called with no NLS table loaded.",
__func__);
return -EINVAL;
}
*out = result = kmalloc(maxlen, GFP_NOFS);
if (!*out) {
befs_error(sb, "%s cannot allocate memory", __func__);
*out_len = 0;
return -ENOMEM;
}
for (i = o = 0; i < in_len; i += unilen, o += utflen) {
unilen = nls->char2uni(&in[i], in_len - i, &uni);
if (unilen < 0)
goto conv_err;
utflen = utf32_to_utf8(uni, &result[o], 3);
if (utflen <= 0)
goto conv_err;
}
result[o] = '\0';
*out_len = o;
befs_debug(sb, "<--- %s", __func__);
return i;
conv_err:
befs_error(sb, "Name using charecter set %s contains a charecter that "
"cannot be converted to unicode.", nls->charset);
befs_debug(sb, "<--- %s", __func__);
kfree(result);
return -EILSEQ;
}
static int
parse_options(char *options, struct befs_mount_options *opts)
{
char *p;
substring_t args[MAX_OPT_ARGS];
int option;
kuid_t uid;
kgid_t gid;
opts->uid = GLOBAL_ROOT_UID;
opts->gid = GLOBAL_ROOT_GID;
opts->use_uid = 0;
opts->use_gid = 0;
opts->iocharset = NULL;
opts->debug = 0;
if (!options)
return 1;
while ((p = strsep(&options, ",")) != NULL) {
int token;
if (!*p)
continue;
token = match_token(p, befs_tokens, args);
switch (token) {
case Opt_uid:
if (match_int(&args[0], &option))
return 0;
uid = INVALID_UID;
if (option >= 0)
uid = make_kuid(current_user_ns(), option);
if (!uid_valid(uid)) {
pr_err("Invalid uid %d, "
"using default\n", option);
break;
}
opts->uid = uid;
opts->use_uid = 1;
break;
case Opt_gid:
if (match_int(&args[0], &option))
return 0;
gid = INVALID_GID;
if (option >= 0)
gid = make_kgid(current_user_ns(), option);
if (!gid_valid(gid)) {
pr_err("Invalid gid %d, "
"using default\n", option);
break;
}
opts->gid = gid;
opts->use_gid = 1;
break;
case Opt_charset:
kfree(opts->iocharset);
opts->iocharset = match_strdup(&args[0]);
if (!opts->iocharset) {
pr_err("allocation failure for "
"iocharset string\n");
return 0;
}
break;
case Opt_debug:
opts->debug = 1;
break;
default:
pr_err("Unrecognized mount option \"%s\" "
"or missing value\n", p);
return 0;
}
}
return 1;
}
static void
befs_put_super(struct super_block *sb)
{
kfree(BEFS_SB(sb)->mount_opts.iocharset);
BEFS_SB(sb)->mount_opts.iocharset = NULL;
unload_nls(BEFS_SB(sb)->nls);
kfree(sb->s_fs_info);
sb->s_fs_info = NULL;
}
static int
befs_fill_super(struct super_block *sb, void *data, int silent)
{
struct buffer_head *bh;
struct befs_sb_info *befs_sb;
befs_super_block *disk_sb;
struct inode *root;
long ret = -EINVAL;
const unsigned long sb_block = 0;
const off_t x86_sb_off = 512;
save_mount_options(sb, data);
sb->s_fs_info = kzalloc(sizeof(*befs_sb), GFP_KERNEL);
if (sb->s_fs_info == NULL) {
pr_err("(%s): Unable to allocate memory for private "
"portion of superblock. Bailing.\n", sb->s_id);
goto unacquire_none;
}
befs_sb = BEFS_SB(sb);
if (!parse_options((char *) data, &befs_sb->mount_opts)) {
befs_error(sb, "cannot parse mount options");
goto unacquire_priv_sbp;
}
befs_debug(sb, "---> %s", __func__);
if (!(sb->s_flags & MS_RDONLY)) {
befs_warning(sb,
"No write support. Marking filesystem read-only");
sb->s_flags |= MS_RDONLY;
}
sb_min_blocksize(sb, 1024);
if (!(bh = sb_bread(sb, sb_block))) {
befs_error(sb, "unable to read superblock");
goto unacquire_priv_sbp;
}
disk_sb = (befs_super_block *) bh->b_data;
if ((disk_sb->magic1 == BEFS_SUPER_MAGIC1_LE) ||
(disk_sb->magic1 == BEFS_SUPER_MAGIC1_BE)) {
befs_debug(sb, "Using PPC superblock location");
} else {
befs_debug(sb, "Using x86 superblock location");
disk_sb =
(befs_super_block *) ((void *) bh->b_data + x86_sb_off);
}
if ((befs_load_sb(sb, disk_sb) != BEFS_OK) ||
(befs_check_sb(sb) != BEFS_OK))
goto unacquire_bh;
befs_dump_super_block(sb, disk_sb);
brelse(bh);
if( befs_sb->num_blocks > ~((sector_t)0) ) {
befs_error(sb, "blocks count: %llu "
"is larger than the host can use",
befs_sb->num_blocks);
goto unacquire_priv_sbp;
}
sb->s_magic = BEFS_SUPER_MAGIC;
sb_set_blocksize(sb, (ulong) befs_sb->block_size);
sb->s_op = &befs_sops;
root = befs_iget(sb, iaddr2blockno(sb, &(befs_sb->root_dir)));
if (IS_ERR(root)) {
ret = PTR_ERR(root);
goto unacquire_priv_sbp;
}
sb->s_root = d_make_root(root);
if (!sb->s_root) {
befs_error(sb, "get root inode failed");
goto unacquire_priv_sbp;
}
if (befs_sb->mount_opts.iocharset) {
befs_debug(sb, "Loading nls: %s",
befs_sb->mount_opts.iocharset);
befs_sb->nls = load_nls(befs_sb->mount_opts.iocharset);
if (!befs_sb->nls) {
befs_warning(sb, "Cannot load nls %s"
" loading default nls",
befs_sb->mount_opts.iocharset);
befs_sb->nls = load_nls_default();
}
} else {
befs_debug(sb, "Loading default nls");
befs_sb->nls = load_nls_default();
}
return 0;
unacquire_bh:
brelse(bh);
unacquire_priv_sbp:
kfree(befs_sb->mount_opts.iocharset);
kfree(sb->s_fs_info);
unacquire_none:
sb->s_fs_info = NULL;
return ret;
}
static int
befs_remount(struct super_block *sb, int *flags, char *data)
{
sync_filesystem(sb);
if (!(*flags & MS_RDONLY))
return -EINVAL;
return 0;
}
static int
befs_statfs(struct dentry *dentry, struct kstatfs *buf)
{
struct super_block *sb = dentry->d_sb;
u64 id = huge_encode_dev(sb->s_bdev->bd_dev);
befs_debug(sb, "---> %s", __func__);
buf->f_type = BEFS_SUPER_MAGIC;
buf->f_bsize = sb->s_blocksize;
buf->f_blocks = BEFS_SB(sb)->num_blocks;
buf->f_bfree = BEFS_SB(sb)->num_blocks - BEFS_SB(sb)->used_blocks;
buf->f_bavail = buf->f_bfree;
buf->f_files = 0;
buf->f_ffree = 0;
buf->f_fsid.val[0] = (u32)id;
buf->f_fsid.val[1] = (u32)(id >> 32);
buf->f_namelen = BEFS_NAME_LEN;
befs_debug(sb, "<--- %s", __func__);
return 0;
}
static struct dentry *
befs_mount(struct file_system_type *fs_type, int flags, const char *dev_name,
void *data)
{
return mount_bdev(fs_type, flags, dev_name, data, befs_fill_super);
}
static int __init
init_befs_fs(void)
{
int err;
pr_info("version: %s\n", BEFS_VERSION);
err = befs_init_inodecache();
if (err)
goto unacquire_none;
err = register_filesystem(&befs_fs_type);
if (err)
goto unacquire_inodecache;
return 0;
unacquire_inodecache:
befs_destroy_inodecache();
unacquire_none:
return err;
}
static void __exit
exit_befs_fs(void)
{
befs_destroy_inodecache();
unregister_filesystem(&befs_fs_type);
}
