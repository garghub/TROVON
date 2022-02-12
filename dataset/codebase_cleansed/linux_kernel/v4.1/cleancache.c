static void cleancache_register_ops_sb(struct super_block *sb, void *unused)
{
switch (sb->cleancache_poolid) {
case CLEANCACHE_NO_BACKEND:
__cleancache_init_fs(sb);
break;
case CLEANCACHE_NO_BACKEND_SHARED:
__cleancache_init_shared_fs(sb);
break;
}
}
int cleancache_register_ops(struct cleancache_ops *ops)
{
if (cmpxchg(&cleancache_ops, NULL, ops))
return -EBUSY;
iterate_supers(cleancache_register_ops_sb, NULL);
return 0;
}
void __cleancache_init_fs(struct super_block *sb)
{
int pool_id = CLEANCACHE_NO_BACKEND;
if (cleancache_ops) {
pool_id = cleancache_ops->init_fs(PAGE_SIZE);
if (pool_id < 0)
pool_id = CLEANCACHE_NO_POOL;
}
sb->cleancache_poolid = pool_id;
}
void __cleancache_init_shared_fs(struct super_block *sb)
{
int pool_id = CLEANCACHE_NO_BACKEND_SHARED;
if (cleancache_ops) {
pool_id = cleancache_ops->init_shared_fs(sb->s_uuid, PAGE_SIZE);
if (pool_id < 0)
pool_id = CLEANCACHE_NO_POOL;
}
sb->cleancache_poolid = pool_id;
}
static int cleancache_get_key(struct inode *inode,
struct cleancache_filekey *key)
{
int (*fhfn)(struct inode *, __u32 *fh, int *, struct inode *);
int len = 0, maxlen = CLEANCACHE_KEY_MAX;
struct super_block *sb = inode->i_sb;
key->u.ino = inode->i_ino;
if (sb->s_export_op != NULL) {
fhfn = sb->s_export_op->encode_fh;
if (fhfn) {
len = (*fhfn)(inode, &key->u.fh[0], &maxlen, NULL);
if (len <= FILEID_ROOT || len == FILEID_INVALID)
return -1;
if (maxlen > CLEANCACHE_KEY_MAX)
return -1;
}
}
return 0;
}
int __cleancache_get_page(struct page *page)
{
int ret = -1;
int pool_id;
struct cleancache_filekey key = { .u.key = { 0 } };
if (!cleancache_ops) {
cleancache_failed_gets++;
goto out;
}
VM_BUG_ON_PAGE(!PageLocked(page), page);
pool_id = page->mapping->host->i_sb->cleancache_poolid;
if (pool_id < 0)
goto out;
if (cleancache_get_key(page->mapping->host, &key) < 0)
goto out;
ret = cleancache_ops->get_page(pool_id, key, page->index, page);
if (ret == 0)
cleancache_succ_gets++;
else
cleancache_failed_gets++;
out:
return ret;
}
void __cleancache_put_page(struct page *page)
{
int pool_id;
struct cleancache_filekey key = { .u.key = { 0 } };
if (!cleancache_ops) {
cleancache_puts++;
return;
}
VM_BUG_ON_PAGE(!PageLocked(page), page);
pool_id = page->mapping->host->i_sb->cleancache_poolid;
if (pool_id >= 0 &&
cleancache_get_key(page->mapping->host, &key) >= 0) {
cleancache_ops->put_page(pool_id, key, page->index, page);
cleancache_puts++;
}
}
void __cleancache_invalidate_page(struct address_space *mapping,
struct page *page)
{
int pool_id = mapping->host->i_sb->cleancache_poolid;
struct cleancache_filekey key = { .u.key = { 0 } };
if (!cleancache_ops)
return;
if (pool_id >= 0) {
VM_BUG_ON_PAGE(!PageLocked(page), page);
if (cleancache_get_key(mapping->host, &key) >= 0) {
cleancache_ops->invalidate_page(pool_id,
key, page->index);
cleancache_invalidates++;
}
}
}
void __cleancache_invalidate_inode(struct address_space *mapping)
{
int pool_id = mapping->host->i_sb->cleancache_poolid;
struct cleancache_filekey key = { .u.key = { 0 } };
if (!cleancache_ops)
return;
if (pool_id >= 0 && cleancache_get_key(mapping->host, &key) >= 0)
cleancache_ops->invalidate_inode(pool_id, key);
}
void __cleancache_invalidate_fs(struct super_block *sb)
{
int pool_id;
pool_id = sb->cleancache_poolid;
sb->cleancache_poolid = CLEANCACHE_NO_POOL;
if (cleancache_ops && pool_id >= 0)
cleancache_ops->invalidate_fs(pool_id);
}
static int __init init_cleancache(void)
{
#ifdef CONFIG_DEBUG_FS
struct dentry *root = debugfs_create_dir("cleancache", NULL);
if (root == NULL)
return -ENXIO;
debugfs_create_u64("succ_gets", S_IRUGO, root, &cleancache_succ_gets);
debugfs_create_u64("failed_gets", S_IRUGO,
root, &cleancache_failed_gets);
debugfs_create_u64("puts", S_IRUGO, root, &cleancache_puts);
debugfs_create_u64("invalidates", S_IRUGO,
root, &cleancache_invalidates);
#endif
return 0;
}
