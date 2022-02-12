int nfs_cache_upcall(struct cache_detail *cd, char *entry_name)
{
static char *envp[] = { "HOME=/",
"TERM=linux",
"PATH=/sbin:/usr/sbin:/bin:/usr/bin",
NULL
};
char *argv[] = {
nfs_cache_getent_prog,
cd->name,
entry_name,
NULL
};
int ret = -EACCES;
if (nfs_cache_getent_prog[0] == '\0')
goto out;
ret = call_usermodehelper(argv[0], argv, envp, UMH_WAIT_EXEC);
if (ret == -ENOENT || ret == -EACCES)
nfs_cache_getent_prog[0] = '\0';
out:
return ret > 0 ? 0 : ret;
}
void nfs_cache_defer_req_put(struct nfs_cache_defer_req *dreq)
{
if (atomic_dec_and_test(&dreq->count))
kfree(dreq);
}
static void nfs_dns_cache_revisit(struct cache_deferred_req *d, int toomany)
{
struct nfs_cache_defer_req *dreq;
dreq = container_of(d, struct nfs_cache_defer_req, deferred_req);
complete_all(&dreq->completion);
nfs_cache_defer_req_put(dreq);
}
static struct cache_deferred_req *nfs_dns_cache_defer(struct cache_req *req)
{
struct nfs_cache_defer_req *dreq;
dreq = container_of(req, struct nfs_cache_defer_req, req);
dreq->deferred_req.revisit = nfs_dns_cache_revisit;
atomic_inc(&dreq->count);
return &dreq->deferred_req;
}
struct nfs_cache_defer_req *nfs_cache_defer_req_alloc(void)
{
struct nfs_cache_defer_req *dreq;
dreq = kzalloc(sizeof(*dreq), GFP_KERNEL);
if (dreq) {
init_completion(&dreq->completion);
atomic_set(&dreq->count, 1);
dreq->req.defer = nfs_dns_cache_defer;
}
return dreq;
}
int nfs_cache_wait_for_upcall(struct nfs_cache_defer_req *dreq)
{
if (wait_for_completion_timeout(&dreq->completion,
nfs_cache_getent_timeout * HZ) == 0)
return -ETIMEDOUT;
return 0;
}
int nfs_cache_register(struct cache_detail *cd)
{
struct vfsmount *mnt;
struct path path;
int ret;
mnt = rpc_get_mount();
if (IS_ERR(mnt))
return PTR_ERR(mnt);
ret = vfs_path_lookup(mnt->mnt_root, mnt, "/cache", 0, &path);
if (ret)
goto err;
ret = sunrpc_cache_register_pipefs(path.dentry, cd->name, 0600, cd);
path_put(&path);
if (!ret)
return ret;
err:
rpc_put_mount();
return ret;
}
void nfs_cache_unregister(struct cache_detail *cd)
{
sunrpc_cache_unregister_pipefs(cd);
rpc_put_mount();
}
