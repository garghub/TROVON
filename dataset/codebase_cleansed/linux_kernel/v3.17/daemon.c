static int cachefiles_daemon_open(struct inode *inode, struct file *file)
{
struct cachefiles_cache *cache;
_enter("");
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
if (xchg(&cachefiles_open, 1) == 1)
return -EBUSY;
cache = kzalloc(sizeof(struct cachefiles_cache), GFP_KERNEL);
if (!cache) {
cachefiles_open = 0;
return -ENOMEM;
}
mutex_init(&cache->daemon_mutex);
cache->active_nodes = RB_ROOT;
rwlock_init(&cache->active_lock);
init_waitqueue_head(&cache->daemon_pollwq);
cache->frun_percent = 7;
cache->fcull_percent = 5;
cache->fstop_percent = 1;
cache->brun_percent = 7;
cache->bcull_percent = 5;
cache->bstop_percent = 1;
file->private_data = cache;
cache->cachefilesd = file;
return 0;
}
static int cachefiles_daemon_release(struct inode *inode, struct file *file)
{
struct cachefiles_cache *cache = file->private_data;
_enter("");
ASSERT(cache);
set_bit(CACHEFILES_DEAD, &cache->flags);
cachefiles_daemon_unbind(cache);
ASSERT(!cache->active_nodes.rb_node);
cache->cachefilesd = NULL;
file->private_data = NULL;
cachefiles_open = 0;
kfree(cache);
_leave("");
return 0;
}
static ssize_t cachefiles_daemon_read(struct file *file, char __user *_buffer,
size_t buflen, loff_t *pos)
{
struct cachefiles_cache *cache = file->private_data;
char buffer[256];
int n;
if (!test_bit(CACHEFILES_READY, &cache->flags))
return 0;
cachefiles_has_space(cache, 0, 0);
clear_bit(CACHEFILES_STATE_CHANGED, &cache->flags);
n = snprintf(buffer, sizeof(buffer),
"cull=%c"
" frun=%llx"
" fcull=%llx"
" fstop=%llx"
" brun=%llx"
" bcull=%llx"
" bstop=%llx",
test_bit(CACHEFILES_CULLING, &cache->flags) ? '1' : '0',
(unsigned long long) cache->frun,
(unsigned long long) cache->fcull,
(unsigned long long) cache->fstop,
(unsigned long long) cache->brun,
(unsigned long long) cache->bcull,
(unsigned long long) cache->bstop
);
if (n > buflen)
return -EMSGSIZE;
if (copy_to_user(_buffer, buffer, n) != 0)
return -EFAULT;
return n;
}
static ssize_t cachefiles_daemon_write(struct file *file,
const char __user *_data,
size_t datalen,
loff_t *pos)
{
const struct cachefiles_daemon_cmd *cmd;
struct cachefiles_cache *cache = file->private_data;
ssize_t ret;
char *data, *args, *cp;
ASSERT(cache);
if (test_bit(CACHEFILES_DEAD, &cache->flags))
return -EIO;
if (datalen < 0 || datalen > PAGE_SIZE - 1)
return -EOPNOTSUPP;
data = kmalloc(datalen + 1, GFP_KERNEL);
if (!data)
return -ENOMEM;
ret = -EFAULT;
if (copy_from_user(data, _data, datalen) != 0)
goto error;
data[datalen] = '\0';
ret = -EINVAL;
if (memchr(data, '\0', datalen))
goto error;
cp = memchr(data, '\n', datalen);
if (cp) {
if (cp == data)
goto error;
*cp = '\0';
}
ret = -EOPNOTSUPP;
for (args = data; *args; args++)
if (isspace(*args))
break;
if (*args) {
if (args == data)
goto error;
*args = '\0';
args = skip_spaces(++args);
}
for (cmd = cachefiles_daemon_cmds; cmd->name[0]; cmd++)
if (strcmp(cmd->name, data) == 0)
goto found_command;
error:
kfree(data);
return ret;
found_command:
mutex_lock(&cache->daemon_mutex);
ret = -EIO;
if (!test_bit(CACHEFILES_DEAD, &cache->flags))
ret = cmd->handler(cache, args);
mutex_unlock(&cache->daemon_mutex);
if (ret == 0)
ret = datalen;
goto error;
}
static unsigned int cachefiles_daemon_poll(struct file *file,
struct poll_table_struct *poll)
{
struct cachefiles_cache *cache = file->private_data;
unsigned int mask;
poll_wait(file, &cache->daemon_pollwq, poll);
mask = 0;
if (test_bit(CACHEFILES_STATE_CHANGED, &cache->flags))
mask |= POLLIN;
if (test_bit(CACHEFILES_CULLING, &cache->flags))
mask |= POLLOUT;
return mask;
}
static int cachefiles_daemon_range_error(struct cachefiles_cache *cache,
char *args)
{
pr_err("Free space limits must be in range 0%%<=stop<cull<run<100%%\n");
return -EINVAL;
}
static int cachefiles_daemon_frun(struct cachefiles_cache *cache, char *args)
{
unsigned long frun;
_enter(",%s", args);
if (!*args)
return -EINVAL;
frun = simple_strtoul(args, &args, 10);
if (args[0] != '%' || args[1] != '\0')
return -EINVAL;
if (frun <= cache->fcull_percent || frun >= 100)
return cachefiles_daemon_range_error(cache, args);
cache->frun_percent = frun;
return 0;
}
static int cachefiles_daemon_fcull(struct cachefiles_cache *cache, char *args)
{
unsigned long fcull;
_enter(",%s", args);
if (!*args)
return -EINVAL;
fcull = simple_strtoul(args, &args, 10);
if (args[0] != '%' || args[1] != '\0')
return -EINVAL;
if (fcull <= cache->fstop_percent || fcull >= cache->frun_percent)
return cachefiles_daemon_range_error(cache, args);
cache->fcull_percent = fcull;
return 0;
}
static int cachefiles_daemon_fstop(struct cachefiles_cache *cache, char *args)
{
unsigned long fstop;
_enter(",%s", args);
if (!*args)
return -EINVAL;
fstop = simple_strtoul(args, &args, 10);
if (args[0] != '%' || args[1] != '\0')
return -EINVAL;
if (fstop < 0 || fstop >= cache->fcull_percent)
return cachefiles_daemon_range_error(cache, args);
cache->fstop_percent = fstop;
return 0;
}
static int cachefiles_daemon_brun(struct cachefiles_cache *cache, char *args)
{
unsigned long brun;
_enter(",%s", args);
if (!*args)
return -EINVAL;
brun = simple_strtoul(args, &args, 10);
if (args[0] != '%' || args[1] != '\0')
return -EINVAL;
if (brun <= cache->bcull_percent || brun >= 100)
return cachefiles_daemon_range_error(cache, args);
cache->brun_percent = brun;
return 0;
}
static int cachefiles_daemon_bcull(struct cachefiles_cache *cache, char *args)
{
unsigned long bcull;
_enter(",%s", args);
if (!*args)
return -EINVAL;
bcull = simple_strtoul(args, &args, 10);
if (args[0] != '%' || args[1] != '\0')
return -EINVAL;
if (bcull <= cache->bstop_percent || bcull >= cache->brun_percent)
return cachefiles_daemon_range_error(cache, args);
cache->bcull_percent = bcull;
return 0;
}
static int cachefiles_daemon_bstop(struct cachefiles_cache *cache, char *args)
{
unsigned long bstop;
_enter(",%s", args);
if (!*args)
return -EINVAL;
bstop = simple_strtoul(args, &args, 10);
if (args[0] != '%' || args[1] != '\0')
return -EINVAL;
if (bstop < 0 || bstop >= cache->bcull_percent)
return cachefiles_daemon_range_error(cache, args);
cache->bstop_percent = bstop;
return 0;
}
static int cachefiles_daemon_dir(struct cachefiles_cache *cache, char *args)
{
char *dir;
_enter(",%s", args);
if (!*args) {
pr_err("Empty directory specified\n");
return -EINVAL;
}
if (cache->rootdirname) {
pr_err("Second cache directory specified\n");
return -EEXIST;
}
dir = kstrdup(args, GFP_KERNEL);
if (!dir)
return -ENOMEM;
cache->rootdirname = dir;
return 0;
}
static int cachefiles_daemon_secctx(struct cachefiles_cache *cache, char *args)
{
char *secctx;
_enter(",%s", args);
if (!*args) {
pr_err("Empty security context specified\n");
return -EINVAL;
}
if (cache->secctx) {
pr_err("Second security context specified\n");
return -EINVAL;
}
secctx = kstrdup(args, GFP_KERNEL);
if (!secctx)
return -ENOMEM;
cache->secctx = secctx;
return 0;
}
static int cachefiles_daemon_tag(struct cachefiles_cache *cache, char *args)
{
char *tag;
_enter(",%s", args);
if (!*args) {
pr_err("Empty tag specified\n");
return -EINVAL;
}
if (cache->tag)
return -EEXIST;
tag = kstrdup(args, GFP_KERNEL);
if (!tag)
return -ENOMEM;
cache->tag = tag;
return 0;
}
static int cachefiles_daemon_cull(struct cachefiles_cache *cache, char *args)
{
struct path path;
const struct cred *saved_cred;
int ret;
_enter(",%s", args);
if (strchr(args, '/'))
goto inval;
if (!test_bit(CACHEFILES_READY, &cache->flags)) {
pr_err("cull applied to unready cache\n");
return -EIO;
}
if (test_bit(CACHEFILES_DEAD, &cache->flags)) {
pr_err("cull applied to dead cache\n");
return -EIO;
}
get_fs_pwd(current->fs, &path);
if (!S_ISDIR(path.dentry->d_inode->i_mode))
goto notdir;
cachefiles_begin_secure(cache, &saved_cred);
ret = cachefiles_cull(cache, path.dentry, args);
cachefiles_end_secure(cache, saved_cred);
path_put(&path);
_leave(" = %d", ret);
return ret;
notdir:
path_put(&path);
pr_err("cull command requires dirfd to be a directory\n");
return -ENOTDIR;
inval:
pr_err("cull command requires dirfd and filename\n");
return -EINVAL;
}
static int cachefiles_daemon_debug(struct cachefiles_cache *cache, char *args)
{
unsigned long mask;
_enter(",%s", args);
mask = simple_strtoul(args, &args, 0);
if (args[0] != '\0')
goto inval;
cachefiles_debug = mask;
_leave(" = 0");
return 0;
inval:
pr_err("debug command requires mask\n");
return -EINVAL;
}
static int cachefiles_daemon_inuse(struct cachefiles_cache *cache, char *args)
{
struct path path;
const struct cred *saved_cred;
int ret;
if (strchr(args, '/'))
goto inval;
if (!test_bit(CACHEFILES_READY, &cache->flags)) {
pr_err("inuse applied to unready cache\n");
return -EIO;
}
if (test_bit(CACHEFILES_DEAD, &cache->flags)) {
pr_err("inuse applied to dead cache\n");
return -EIO;
}
get_fs_pwd(current->fs, &path);
if (!S_ISDIR(path.dentry->d_inode->i_mode))
goto notdir;
cachefiles_begin_secure(cache, &saved_cred);
ret = cachefiles_check_in_use(cache, path.dentry, args);
cachefiles_end_secure(cache, saved_cred);
path_put(&path);
return ret;
notdir:
path_put(&path);
pr_err("inuse command requires dirfd to be a directory\n");
return -ENOTDIR;
inval:
pr_err("inuse command requires dirfd and filename\n");
return -EINVAL;
}
int cachefiles_has_space(struct cachefiles_cache *cache,
unsigned fnr, unsigned bnr)
{
struct kstatfs stats;
struct path path = {
.mnt = cache->mnt,
.dentry = cache->mnt->mnt_root,
};
int ret;
memset(&stats, 0, sizeof(stats));
ret = vfs_statfs(&path, &stats);
if (ret < 0) {
if (ret == -EIO)
cachefiles_io_error(cache, "statfs failed");
_leave(" = %d", ret);
return ret;
}
stats.f_bavail >>= cache->bshift;
if (stats.f_ffree > fnr)
stats.f_ffree -= fnr;
else
stats.f_ffree = 0;
if (stats.f_bavail > bnr)
stats.f_bavail -= bnr;
else
stats.f_bavail = 0;
ret = -ENOBUFS;
if (stats.f_ffree < cache->fstop ||
stats.f_bavail < cache->bstop)
goto begin_cull;
ret = 0;
if (stats.f_ffree < cache->fcull ||
stats.f_bavail < cache->bcull)
goto begin_cull;
if (test_bit(CACHEFILES_CULLING, &cache->flags) &&
stats.f_ffree >= cache->frun &&
stats.f_bavail >= cache->brun &&
test_and_clear_bit(CACHEFILES_CULLING, &cache->flags)
) {
_debug("cease culling");
cachefiles_state_changed(cache);
}
return 0;
begin_cull:
if (!test_and_set_bit(CACHEFILES_CULLING, &cache->flags)) {
_debug("### CULL CACHE ###");
cachefiles_state_changed(cache);
}
_leave(" = %d", ret);
return ret;
}
