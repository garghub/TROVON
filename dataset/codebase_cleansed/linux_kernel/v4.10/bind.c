int cachefiles_daemon_bind(struct cachefiles_cache *cache, char *args)
{
_enter("{%u,%u,%u,%u,%u,%u},%s",
cache->frun_percent,
cache->fcull_percent,
cache->fstop_percent,
cache->brun_percent,
cache->bcull_percent,
cache->bstop_percent,
args);
ASSERT(cache->fstop_percent >= 0 &&
cache->fstop_percent < cache->fcull_percent &&
cache->fcull_percent < cache->frun_percent &&
cache->frun_percent < 100);
ASSERT(cache->bstop_percent >= 0 &&
cache->bstop_percent < cache->bcull_percent &&
cache->bcull_percent < cache->brun_percent &&
cache->brun_percent < 100);
if (*args) {
pr_err("'bind' command doesn't take an argument\n");
return -EINVAL;
}
if (!cache->rootdirname) {
pr_err("No cache directory specified\n");
return -EINVAL;
}
if (test_bit(CACHEFILES_READY, &cache->flags)) {
pr_err("Cache already bound\n");
return -EBUSY;
}
if (!cache->tag) {
cache->tag = kstrdup("CacheFiles", GFP_KERNEL);
if (!cache->tag)
return -ENOMEM;
}
return cachefiles_daemon_add_cache(cache);
}
static int cachefiles_daemon_add_cache(struct cachefiles_cache *cache)
{
struct cachefiles_object *fsdef;
struct path path;
struct kstatfs stats;
struct dentry *graveyard, *cachedir, *root;
const struct cred *saved_cred;
int ret;
_enter("");
ret = cachefiles_get_security_ID(cache);
if (ret < 0)
return ret;
cachefiles_begin_secure(cache, &saved_cred);
ret = -ENOMEM;
fsdef = kmem_cache_alloc(cachefiles_object_jar, GFP_KERNEL);
if (!fsdef)
goto error_root_object;
ASSERTCMP(fsdef->backer, ==, NULL);
atomic_set(&fsdef->usage, 1);
fsdef->type = FSCACHE_COOKIE_TYPE_INDEX;
_debug("- fsdef %p", fsdef);
ret = kern_path(cache->rootdirname, LOOKUP_DIRECTORY, &path);
if (ret < 0)
goto error_open_root;
cache->mnt = path.mnt;
root = path.dentry;
ret = -EOPNOTSUPP;
if (d_is_negative(root) ||
!d_backing_inode(root)->i_op->lookup ||
!d_backing_inode(root)->i_op->mkdir ||
!(d_backing_inode(root)->i_opflags & IOP_XATTR) ||
!root->d_sb->s_op->statfs ||
!root->d_sb->s_op->sync_fs)
goto error_unsupported;
ret = -EROFS;
if (root->d_sb->s_flags & MS_RDONLY)
goto error_unsupported;
ret = cachefiles_determine_cache_security(cache, root, &saved_cred);
if (ret < 0)
goto error_unsupported;
ret = vfs_statfs(&path, &stats);
if (ret < 0)
goto error_unsupported;
ret = -ERANGE;
if (stats.f_bsize <= 0)
goto error_unsupported;
ret = -EOPNOTSUPP;
if (stats.f_bsize > PAGE_SIZE)
goto error_unsupported;
cache->bsize = stats.f_bsize;
cache->bshift = 0;
if (stats.f_bsize < PAGE_SIZE)
cache->bshift = PAGE_SHIFT - ilog2(stats.f_bsize);
_debug("blksize %u (shift %u)",
cache->bsize, cache->bshift);
_debug("size %llu, avail %llu",
(unsigned long long) stats.f_blocks,
(unsigned long long) stats.f_bavail);
do_div(stats.f_files, 100);
cache->fstop = stats.f_files * cache->fstop_percent;
cache->fcull = stats.f_files * cache->fcull_percent;
cache->frun = stats.f_files * cache->frun_percent;
_debug("limits {%llu,%llu,%llu} files",
(unsigned long long) cache->frun,
(unsigned long long) cache->fcull,
(unsigned long long) cache->fstop);
stats.f_blocks >>= cache->bshift;
do_div(stats.f_blocks, 100);
cache->bstop = stats.f_blocks * cache->bstop_percent;
cache->bcull = stats.f_blocks * cache->bcull_percent;
cache->brun = stats.f_blocks * cache->brun_percent;
_debug("limits {%llu,%llu,%llu} blocks",
(unsigned long long) cache->brun,
(unsigned long long) cache->bcull,
(unsigned long long) cache->bstop);
cachedir = cachefiles_get_directory(cache, root, "cache");
if (IS_ERR(cachedir)) {
ret = PTR_ERR(cachedir);
goto error_unsupported;
}
fsdef->dentry = cachedir;
fsdef->fscache.cookie = NULL;
ret = cachefiles_check_object_type(fsdef);
if (ret < 0)
goto error_unsupported;
graveyard = cachefiles_get_directory(cache, root, "graveyard");
if (IS_ERR(graveyard)) {
ret = PTR_ERR(graveyard);
goto error_unsupported;
}
cache->graveyard = graveyard;
fscache_init_cache(&cache->cache,
&cachefiles_cache_ops,
"%s",
fsdef->dentry->d_sb->s_id);
fscache_object_init(&fsdef->fscache, NULL, &cache->cache);
ret = fscache_add_cache(&cache->cache, &fsdef->fscache, cache->tag);
if (ret < 0)
goto error_add_cache;
set_bit(CACHEFILES_READY, &cache->flags);
dput(root);
pr_info("File cache on %s registered\n", cache->cache.identifier);
cachefiles_has_space(cache, 0, 0);
cachefiles_end_secure(cache, saved_cred);
return 0;
error_add_cache:
dput(cache->graveyard);
cache->graveyard = NULL;
error_unsupported:
mntput(cache->mnt);
cache->mnt = NULL;
dput(fsdef->dentry);
fsdef->dentry = NULL;
dput(root);
error_open_root:
kmem_cache_free(cachefiles_object_jar, fsdef);
error_root_object:
cachefiles_end_secure(cache, saved_cred);
pr_err("Failed to register: %d\n", ret);
return ret;
}
void cachefiles_daemon_unbind(struct cachefiles_cache *cache)
{
_enter("");
if (test_bit(CACHEFILES_READY, &cache->flags)) {
pr_info("File cache on %s unregistering\n",
cache->cache.identifier);
fscache_withdraw_cache(&cache->cache);
}
dput(cache->graveyard);
mntput(cache->mnt);
kfree(cache->rootdirname);
kfree(cache->secctx);
kfree(cache->tag);
_leave("");
}
