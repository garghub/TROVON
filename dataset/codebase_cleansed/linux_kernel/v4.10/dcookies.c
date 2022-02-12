static inline int is_live(void)
{
return !(list_empty(&dcookie_users));
}
static inline unsigned long dcookie_value(struct dcookie_struct * dcs)
{
return (unsigned long)dcs->path.dentry;
}
static size_t dcookie_hash(unsigned long dcookie)
{
return (dcookie >> L1_CACHE_SHIFT) & (hash_size - 1);
}
static struct dcookie_struct * find_dcookie(unsigned long dcookie)
{
struct dcookie_struct *found = NULL;
struct dcookie_struct * dcs;
struct list_head * pos;
struct list_head * list;
list = dcookie_hashtable + dcookie_hash(dcookie);
list_for_each(pos, list) {
dcs = list_entry(pos, struct dcookie_struct, hash_list);
if (dcookie_value(dcs) == dcookie) {
found = dcs;
break;
}
}
return found;
}
static void hash_dcookie(struct dcookie_struct * dcs)
{
struct list_head * list = dcookie_hashtable + dcookie_hash(dcookie_value(dcs));
list_add(&dcs->hash_list, list);
}
static struct dcookie_struct *alloc_dcookie(const struct path *path)
{
struct dcookie_struct *dcs = kmem_cache_alloc(dcookie_cache,
GFP_KERNEL);
struct dentry *d;
if (!dcs)
return NULL;
d = path->dentry;
spin_lock(&d->d_lock);
d->d_flags |= DCACHE_COOKIE;
spin_unlock(&d->d_lock);
dcs->path = *path;
path_get(path);
hash_dcookie(dcs);
return dcs;
}
int get_dcookie(const struct path *path, unsigned long *cookie)
{
int err = 0;
struct dcookie_struct * dcs;
mutex_lock(&dcookie_mutex);
if (!is_live()) {
err = -EINVAL;
goto out;
}
if (path->dentry->d_flags & DCACHE_COOKIE) {
dcs = find_dcookie((unsigned long)path->dentry);
} else {
dcs = alloc_dcookie(path);
if (!dcs) {
err = -ENOMEM;
goto out;
}
}
*cookie = dcookie_value(dcs);
out:
mutex_unlock(&dcookie_mutex);
return err;
}
static int dcookie_init(void)
{
struct list_head * d;
unsigned int i, hash_bits;
int err = -ENOMEM;
dcookie_cache = kmem_cache_create("dcookie_cache",
sizeof(struct dcookie_struct),
0, 0, NULL);
if (!dcookie_cache)
goto out;
dcookie_hashtable = kmalloc(PAGE_SIZE, GFP_KERNEL);
if (!dcookie_hashtable)
goto out_kmem;
err = 0;
hash_size = PAGE_SIZE / sizeof(struct list_head);
hash_bits = 0;
do {
hash_bits++;
} while ((hash_size >> hash_bits) != 0);
hash_bits--;
hash_size = 1UL << hash_bits;
d = dcookie_hashtable;
i = hash_size;
do {
INIT_LIST_HEAD(d);
d++;
i--;
} while (i);
out:
return err;
out_kmem:
kmem_cache_destroy(dcookie_cache);
goto out;
}
static void free_dcookie(struct dcookie_struct * dcs)
{
struct dentry *d = dcs->path.dentry;
spin_lock(&d->d_lock);
d->d_flags &= ~DCACHE_COOKIE;
spin_unlock(&d->d_lock);
path_put(&dcs->path);
kmem_cache_free(dcookie_cache, dcs);
}
static void dcookie_exit(void)
{
struct list_head * list;
struct list_head * pos;
struct list_head * pos2;
struct dcookie_struct * dcs;
size_t i;
for (i = 0; i < hash_size; ++i) {
list = dcookie_hashtable + i;
list_for_each_safe(pos, pos2, list) {
dcs = list_entry(pos, struct dcookie_struct, hash_list);
list_del(&dcs->hash_list);
free_dcookie(dcs);
}
}
kfree(dcookie_hashtable);
kmem_cache_destroy(dcookie_cache);
}
struct dcookie_user * dcookie_register(void)
{
struct dcookie_user * user;
mutex_lock(&dcookie_mutex);
user = kmalloc(sizeof(struct dcookie_user), GFP_KERNEL);
if (!user)
goto out;
if (!is_live() && dcookie_init())
goto out_free;
list_add(&user->next, &dcookie_users);
out:
mutex_unlock(&dcookie_mutex);
return user;
out_free:
kfree(user);
user = NULL;
goto out;
}
void dcookie_unregister(struct dcookie_user * user)
{
mutex_lock(&dcookie_mutex);
list_del(&user->next);
kfree(user);
if (!is_live())
dcookie_exit();
mutex_unlock(&dcookie_mutex);
}
