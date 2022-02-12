int __fscache_register_netfs(struct fscache_netfs *netfs)
{
struct fscache_netfs *ptr;
struct fscache_cookie *cookie;
int ret;
_enter("{%s}", netfs->name);
INIT_LIST_HEAD(&netfs->link);
cookie = kmem_cache_zalloc(fscache_cookie_jar, GFP_KERNEL);
if (!cookie) {
_leave(" = -ENOMEM");
return -ENOMEM;
}
atomic_set(&cookie->usage, 1);
atomic_set(&cookie->n_children, 0);
atomic_set(&cookie->n_active, 1);
cookie->def = &fscache_fsdef_netfs_def;
cookie->parent = &fscache_fsdef_index;
cookie->netfs_data = netfs;
cookie->flags = 1 << FSCACHE_COOKIE_ENABLED;
spin_lock_init(&cookie->lock);
INIT_HLIST_HEAD(&cookie->backing_objects);
down_write(&fscache_addremove_sem);
ret = -EEXIST;
list_for_each_entry(ptr, &fscache_netfs_list, link) {
if (strcmp(ptr->name, netfs->name) == 0)
goto already_registered;
}
atomic_inc(&cookie->parent->usage);
atomic_inc(&cookie->parent->n_children);
netfs->primary_index = cookie;
list_add(&netfs->link, &fscache_netfs_list);
ret = 0;
pr_notice("Netfs '%s' registered for caching\n", netfs->name);
already_registered:
up_write(&fscache_addremove_sem);
if (ret < 0)
kmem_cache_free(fscache_cookie_jar, cookie);
_leave(" = %d", ret);
return ret;
}
void __fscache_unregister_netfs(struct fscache_netfs *netfs)
{
_enter("{%s.%u}", netfs->name, netfs->version);
down_write(&fscache_addremove_sem);
list_del(&netfs->link);
fscache_relinquish_cookie(netfs->primary_index, 0);
up_write(&fscache_addremove_sem);
pr_notice("Netfs '%s' unregistered from caching\n",
netfs->name);
_leave("");
}
