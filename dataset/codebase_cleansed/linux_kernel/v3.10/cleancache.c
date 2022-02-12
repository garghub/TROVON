struct cleancache_ops *cleancache_register_ops(struct cleancache_ops *ops)
{
struct cleancache_ops *old = cleancache_ops;
int i;
mutex_lock(&poolid_mutex);
for (i = 0; i < MAX_INITIALIZABLE_FS; i++) {
if (fs_poolid_map[i] == FS_NO_BACKEND)
fs_poolid_map[i] = ops->init_fs(PAGE_SIZE);
if (shared_fs_poolid_map[i] == FS_NO_BACKEND)
shared_fs_poolid_map[i] = ops->init_shared_fs
(uuids[i], PAGE_SIZE);
}
barrier();
cleancache_ops = ops;
mutex_unlock(&poolid_mutex);
return old;
}
void __cleancache_init_fs(struct super_block *sb)
{
int i;
mutex_lock(&poolid_mutex);
for (i = 0; i < MAX_INITIALIZABLE_FS; i++) {
if (fs_poolid_map[i] == FS_UNKNOWN) {
sb->cleancache_poolid = i + FAKE_FS_POOLID_OFFSET;
if (cleancache_ops)
fs_poolid_map[i] = cleancache_ops->init_fs(PAGE_SIZE);
else
fs_poolid_map[i] = FS_NO_BACKEND;
break;
}
}
mutex_unlock(&poolid_mutex);
}
void __cleancache_init_shared_fs(char *uuid, struct super_block *sb)
{
int i;
mutex_lock(&poolid_mutex);
for (i = 0; i < MAX_INITIALIZABLE_FS; i++) {
if (shared_fs_poolid_map[i] == FS_UNKNOWN) {
sb->cleancache_poolid = i + FAKE_SHARED_FS_POOLID_OFFSET;
uuids[i] = uuid;
if (cleancache_ops)
shared_fs_poolid_map[i] = cleancache_ops->init_shared_fs
(uuid, PAGE_SIZE);
else
shared_fs_poolid_map[i] = FS_NO_BACKEND;
break;
}
}
mutex_unlock(&poolid_mutex);
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
static int get_poolid_from_fake(int fake_pool_id)
{
if (fake_pool_id >= FAKE_SHARED_FS_POOLID_OFFSET)
return shared_fs_poolid_map[fake_pool_id -
FAKE_SHARED_FS_POOLID_OFFSET];
else if (fake_pool_id >= FAKE_FS_POOLID_OFFSET)
return fs_poolid_map[fake_pool_id - FAKE_FS_POOLID_OFFSET];
return FS_NO_BACKEND;
}
int __cleancache_get_page(struct page *page)
{
int ret = -1;
int pool_id;
int fake_pool_id;
struct cleancache_filekey key = { .u.key = { 0 } };
if (!cleancache_ops) {
cleancache_failed_gets++;
goto out;
}
VM_BUG_ON(!PageLocked(page));
fake_pool_id = page->mapping->host->i_sb->cleancache_poolid;
if (fake_pool_id < 0)
goto out;
pool_id = get_poolid_from_fake(fake_pool_id);
if (cleancache_get_key(page->mapping->host, &key) < 0)
goto out;
if (pool_id >= 0)
ret = cleancache_ops->get_page(pool_id,
key, page->index, page);
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
int fake_pool_id;
struct cleancache_filekey key = { .u.key = { 0 } };
if (!cleancache_ops) {
cleancache_puts++;
return;
}
VM_BUG_ON(!PageLocked(page));
fake_pool_id = page->mapping->host->i_sb->cleancache_poolid;
if (fake_pool_id < 0)
return;
pool_id = get_poolid_from_fake(fake_pool_id);
if (pool_id >= 0 &&
cleancache_get_key(page->mapping->host, &key) >= 0) {
cleancache_ops->put_page(pool_id, key, page->index, page);
cleancache_puts++;
}
}
void __cleancache_invalidate_page(struct address_space *mapping,
struct page *page)
{
int pool_id;
int fake_pool_id = mapping->host->i_sb->cleancache_poolid;
struct cleancache_filekey key = { .u.key = { 0 } };
if (!cleancache_ops)
return;
if (fake_pool_id >= 0) {
pool_id = get_poolid_from_fake(fake_pool_id);
if (pool_id < 0)
return;
VM_BUG_ON(!PageLocked(page));
if (cleancache_get_key(mapping->host, &key) >= 0) {
cleancache_ops->invalidate_page(pool_id,
key, page->index);
cleancache_invalidates++;
}
}
}
void __cleancache_invalidate_inode(struct address_space *mapping)
{
int pool_id;
int fake_pool_id = mapping->host->i_sb->cleancache_poolid;
struct cleancache_filekey key = { .u.key = { 0 } };
if (!cleancache_ops)
return;
if (fake_pool_id < 0)
return;
pool_id = get_poolid_from_fake(fake_pool_id);
if (pool_id >= 0 && cleancache_get_key(mapping->host, &key) >= 0)
cleancache_ops->invalidate_inode(pool_id, key);
}
void __cleancache_invalidate_fs(struct super_block *sb)
{
int index;
int fake_pool_id = sb->cleancache_poolid;
int old_poolid = fake_pool_id;
mutex_lock(&poolid_mutex);
if (fake_pool_id >= FAKE_SHARED_FS_POOLID_OFFSET) {
index = fake_pool_id - FAKE_SHARED_FS_POOLID_OFFSET;
old_poolid = shared_fs_poolid_map[index];
shared_fs_poolid_map[index] = FS_UNKNOWN;
uuids[index] = NULL;
} else if (fake_pool_id >= FAKE_FS_POOLID_OFFSET) {
index = fake_pool_id - FAKE_FS_POOLID_OFFSET;
old_poolid = fs_poolid_map[index];
fs_poolid_map[index] = FS_UNKNOWN;
}
sb->cleancache_poolid = -1;
if (cleancache_ops)
cleancache_ops->invalidate_fs(old_poolid);
mutex_unlock(&poolid_mutex);
}
static int __init init_cleancache(void)
{
int i;
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
for (i = 0; i < MAX_INITIALIZABLE_FS; i++) {
fs_poolid_map[i] = FS_UNKNOWN;
shared_fs_poolid_map[i] = FS_UNKNOWN;
}
return 0;
}
