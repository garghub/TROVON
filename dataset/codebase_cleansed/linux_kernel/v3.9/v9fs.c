static int get_cache_mode(char *s)
{
int version = -EINVAL;
if (!strcmp(s, "loose")) {
version = CACHE_LOOSE;
p9_debug(P9_DEBUG_9P, "Cache mode: loose\n");
} else if (!strcmp(s, "fscache")) {
version = CACHE_FSCACHE;
p9_debug(P9_DEBUG_9P, "Cache mode: fscache\n");
} else if (!strcmp(s, "none")) {
version = CACHE_NONE;
p9_debug(P9_DEBUG_9P, "Cache mode: none\n");
} else
pr_info("Unknown Cache mode %s\n", s);
return version;
}
static int v9fs_parse_options(struct v9fs_session_info *v9ses, char *opts)
{
char *options, *tmp_options;
substring_t args[MAX_OPT_ARGS];
char *p;
int option = 0;
char *s, *e;
int ret = 0;
v9ses->afid = ~0;
v9ses->debug = 0;
v9ses->cache = CACHE_NONE;
#ifdef CONFIG_9P_FSCACHE
v9ses->cachetag = NULL;
#endif
if (!opts)
return 0;
tmp_options = kstrdup(opts, GFP_KERNEL);
if (!tmp_options) {
ret = -ENOMEM;
goto fail_option_alloc;
}
options = tmp_options;
while ((p = strsep(&options, ",")) != NULL) {
int token, r;
if (!*p)
continue;
token = match_token(p, tokens, args);
switch (token) {
case Opt_debug:
r = match_int(&args[0], &option);
if (r < 0) {
p9_debug(P9_DEBUG_ERROR,
"integer field, but no integer?\n");
ret = r;
continue;
}
v9ses->debug = option;
#ifdef CONFIG_NET_9P_DEBUG
p9_debug_level = option;
#endif
break;
case Opt_dfltuid:
r = match_int(&args[0], &option);
if (r < 0) {
p9_debug(P9_DEBUG_ERROR,
"integer field, but no integer?\n");
ret = r;
continue;
}
v9ses->dfltuid = make_kuid(current_user_ns(), option);
if (!uid_valid(v9ses->dfltuid)) {
p9_debug(P9_DEBUG_ERROR,
"uid field, but not a uid?\n");
ret = -EINVAL;
continue;
}
break;
case Opt_dfltgid:
r = match_int(&args[0], &option);
if (r < 0) {
p9_debug(P9_DEBUG_ERROR,
"integer field, but no integer?\n");
ret = r;
continue;
}
v9ses->dfltgid = make_kgid(current_user_ns(), option);
if (!gid_valid(v9ses->dfltgid)) {
p9_debug(P9_DEBUG_ERROR,
"gid field, but not a gid?\n");
ret = -EINVAL;
continue;
}
break;
case Opt_afid:
r = match_int(&args[0], &option);
if (r < 0) {
p9_debug(P9_DEBUG_ERROR,
"integer field, but no integer?\n");
ret = r;
continue;
}
v9ses->afid = option;
break;
case Opt_uname:
kfree(v9ses->uname);
v9ses->uname = match_strdup(&args[0]);
if (!v9ses->uname) {
ret = -ENOMEM;
goto free_and_return;
}
break;
case Opt_remotename:
kfree(v9ses->aname);
v9ses->aname = match_strdup(&args[0]);
if (!v9ses->aname) {
ret = -ENOMEM;
goto free_and_return;
}
break;
case Opt_nodevmap:
v9ses->nodev = 1;
break;
case Opt_cache_loose:
v9ses->cache = CACHE_LOOSE;
break;
case Opt_fscache:
v9ses->cache = CACHE_FSCACHE;
break;
case Opt_cachetag:
#ifdef CONFIG_9P_FSCACHE
v9ses->cachetag = match_strdup(&args[0]);
#endif
break;
case Opt_cache:
s = match_strdup(&args[0]);
if (!s) {
ret = -ENOMEM;
p9_debug(P9_DEBUG_ERROR,
"problem allocating copy of cache arg\n");
goto free_and_return;
}
ret = get_cache_mode(s);
if (ret == -EINVAL) {
kfree(s);
goto free_and_return;
}
v9ses->cache = ret;
kfree(s);
break;
case Opt_access:
s = match_strdup(&args[0]);
if (!s) {
ret = -ENOMEM;
p9_debug(P9_DEBUG_ERROR,
"problem allocating copy of access arg\n");
goto free_and_return;
}
v9ses->flags &= ~V9FS_ACCESS_MASK;
if (strcmp(s, "user") == 0)
v9ses->flags |= V9FS_ACCESS_USER;
else if (strcmp(s, "any") == 0)
v9ses->flags |= V9FS_ACCESS_ANY;
else if (strcmp(s, "client") == 0) {
v9ses->flags |= V9FS_ACCESS_CLIENT;
} else {
uid_t uid;
v9ses->flags |= V9FS_ACCESS_SINGLE;
uid = simple_strtoul(s, &e, 10);
if (*e != '\0') {
ret = -EINVAL;
pr_info("Unknown access argument %s\n",
s);
kfree(s);
goto free_and_return;
}
v9ses->uid = make_kuid(current_user_ns(), uid);
if (!uid_valid(v9ses->uid)) {
ret = -EINVAL;
pr_info("Uknown uid %s\n", s);
kfree(s);
goto free_and_return;
}
}
kfree(s);
break;
case Opt_posixacl:
#ifdef CONFIG_9P_FS_POSIX_ACL
v9ses->flags |= V9FS_POSIX_ACL;
#else
p9_debug(P9_DEBUG_ERROR,
"Not defined CONFIG_9P_FS_POSIX_ACL. Ignoring posixacl option\n");
#endif
break;
default:
continue;
}
}
free_and_return:
kfree(tmp_options);
fail_option_alloc:
return ret;
}
struct p9_fid *v9fs_session_init(struct v9fs_session_info *v9ses,
const char *dev_name, char *data)
{
int retval = -EINVAL;
struct p9_fid *fid;
int rc;
v9ses->uname = kstrdup(V9FS_DEFUSER, GFP_KERNEL);
if (!v9ses->uname)
return ERR_PTR(-ENOMEM);
v9ses->aname = kstrdup(V9FS_DEFANAME, GFP_KERNEL);
if (!v9ses->aname) {
kfree(v9ses->uname);
return ERR_PTR(-ENOMEM);
}
init_rwsem(&v9ses->rename_sem);
rc = bdi_setup_and_register(&v9ses->bdi, "9p", BDI_CAP_MAP_COPY);
if (rc) {
kfree(v9ses->aname);
kfree(v9ses->uname);
return ERR_PTR(rc);
}
spin_lock(&v9fs_sessionlist_lock);
list_add(&v9ses->slist, &v9fs_sessionlist);
spin_unlock(&v9fs_sessionlist_lock);
v9ses->uid = INVALID_UID;
v9ses->dfltuid = V9FS_DEFUID;
v9ses->dfltgid = V9FS_DEFGID;
v9ses->clnt = p9_client_create(dev_name, data);
if (IS_ERR(v9ses->clnt)) {
retval = PTR_ERR(v9ses->clnt);
v9ses->clnt = NULL;
p9_debug(P9_DEBUG_ERROR, "problem initializing 9p client\n");
goto error;
}
v9ses->flags = V9FS_ACCESS_USER;
if (p9_is_proto_dotl(v9ses->clnt)) {
v9ses->flags = V9FS_ACCESS_CLIENT;
v9ses->flags |= V9FS_PROTO_2000L;
} else if (p9_is_proto_dotu(v9ses->clnt)) {
v9ses->flags |= V9FS_PROTO_2000U;
}
rc = v9fs_parse_options(v9ses, data);
if (rc < 0) {
retval = rc;
goto error;
}
v9ses->maxdata = v9ses->clnt->msize - P9_IOHDRSZ;
if (!v9fs_proto_dotl(v9ses) &&
((v9ses->flags & V9FS_ACCESS_MASK) == V9FS_ACCESS_CLIENT)) {
v9ses->flags &= ~V9FS_ACCESS_MASK;
v9ses->flags |= V9FS_ACCESS_USER;
}
if (!(v9fs_proto_dotu(v9ses) || v9fs_proto_dotl(v9ses)) &&
((v9ses->flags&V9FS_ACCESS_MASK) == V9FS_ACCESS_USER)) {
v9ses->flags &= ~V9FS_ACCESS_MASK;
v9ses->flags |= V9FS_ACCESS_ANY;
v9ses->uid = INVALID_UID;
}
if (!v9fs_proto_dotl(v9ses) ||
!((v9ses->flags & V9FS_ACCESS_MASK) == V9FS_ACCESS_CLIENT)) {
v9ses->flags &= ~V9FS_ACL_MASK;
}
fid = p9_client_attach(v9ses->clnt, NULL, v9ses->uname, INVALID_UID,
v9ses->aname);
if (IS_ERR(fid)) {
retval = PTR_ERR(fid);
fid = NULL;
p9_debug(P9_DEBUG_ERROR, "cannot attach\n");
goto error;
}
if ((v9ses->flags & V9FS_ACCESS_MASK) == V9FS_ACCESS_SINGLE)
fid->uid = v9ses->uid;
else
fid->uid = INVALID_UID;
#ifdef CONFIG_9P_FSCACHE
v9fs_cache_session_get_cookie(v9ses);
#endif
return fid;
error:
bdi_destroy(&v9ses->bdi);
return ERR_PTR(retval);
}
void v9fs_session_close(struct v9fs_session_info *v9ses)
{
if (v9ses->clnt) {
p9_client_destroy(v9ses->clnt);
v9ses->clnt = NULL;
}
#ifdef CONFIG_9P_FSCACHE
if (v9ses->fscache) {
v9fs_cache_session_put_cookie(v9ses);
kfree(v9ses->cachetag);
}
#endif
kfree(v9ses->uname);
kfree(v9ses->aname);
bdi_destroy(&v9ses->bdi);
spin_lock(&v9fs_sessionlist_lock);
list_del(&v9ses->slist);
spin_unlock(&v9fs_sessionlist_lock);
}
void v9fs_session_cancel(struct v9fs_session_info *v9ses) {
p9_debug(P9_DEBUG_ERROR, "cancel session %p\n", v9ses);
p9_client_disconnect(v9ses->clnt);
}
void v9fs_session_begin_cancel(struct v9fs_session_info *v9ses)
{
p9_debug(P9_DEBUG_ERROR, "begin cancel session %p\n", v9ses);
p9_client_begin_disconnect(v9ses->clnt);
}
static ssize_t caches_show(struct kobject *kobj,
struct kobj_attribute *attr,
char *buf)
{
ssize_t n = 0, count = 0, limit = PAGE_SIZE;
struct v9fs_session_info *v9ses;
spin_lock(&v9fs_sessionlist_lock);
list_for_each_entry(v9ses, &v9fs_sessionlist, slist) {
if (v9ses->cachetag) {
n = snprintf(buf, limit, "%s\n", v9ses->cachetag);
if (n < 0) {
count = n;
break;
}
count += n;
limit -= n;
}
}
spin_unlock(&v9fs_sessionlist_lock);
return count;
}
static int v9fs_sysfs_init(void)
{
v9fs_kobj = kobject_create_and_add("9p", fs_kobj);
if (!v9fs_kobj)
return -ENOMEM;
if (sysfs_create_group(v9fs_kobj, &v9fs_attr_group)) {
kobject_put(v9fs_kobj);
return -ENOMEM;
}
return 0;
}
static void v9fs_sysfs_cleanup(void)
{
sysfs_remove_group(v9fs_kobj, &v9fs_attr_group);
kobject_put(v9fs_kobj);
}
static void v9fs_inode_init_once(void *foo)
{
struct v9fs_inode *v9inode = (struct v9fs_inode *)foo;
#ifdef CONFIG_9P_FSCACHE
v9inode->fscache = NULL;
#endif
memset(&v9inode->qid, 0, sizeof(v9inode->qid));
inode_init_once(&v9inode->vfs_inode);
}
static int v9fs_init_inode_cache(void)
{
v9fs_inode_cache = kmem_cache_create("v9fs_inode_cache",
sizeof(struct v9fs_inode),
0, (SLAB_RECLAIM_ACCOUNT|
SLAB_MEM_SPREAD),
v9fs_inode_init_once);
if (!v9fs_inode_cache)
return -ENOMEM;
return 0;
}
static void v9fs_destroy_inode_cache(void)
{
rcu_barrier();
kmem_cache_destroy(v9fs_inode_cache);
}
static int v9fs_cache_register(void)
{
int ret;
ret = v9fs_init_inode_cache();
if (ret < 0)
return ret;
#ifdef CONFIG_9P_FSCACHE
return fscache_register_netfs(&v9fs_cache_netfs);
#else
return ret;
#endif
}
static void v9fs_cache_unregister(void)
{
v9fs_destroy_inode_cache();
#ifdef CONFIG_9P_FSCACHE
fscache_unregister_netfs(&v9fs_cache_netfs);
#endif
}
static int __init init_v9fs(void)
{
int err;
pr_info("Installing v9fs 9p2000 file system support\n");
err = v9fs_cache_register();
if (err < 0) {
pr_err("Failed to register v9fs for caching\n");
return err;
}
err = v9fs_sysfs_init();
if (err < 0) {
pr_err("Failed to register with sysfs\n");
goto out_cache;
}
err = register_filesystem(&v9fs_fs_type);
if (err < 0) {
pr_err("Failed to register filesystem\n");
goto out_sysfs_cleanup;
}
return 0;
out_sysfs_cleanup:
v9fs_sysfs_cleanup();
out_cache:
v9fs_cache_unregister();
return err;
}
static void __exit exit_v9fs(void)
{
v9fs_sysfs_cleanup();
v9fs_cache_unregister();
unregister_filesystem(&v9fs_fs_type);
}
