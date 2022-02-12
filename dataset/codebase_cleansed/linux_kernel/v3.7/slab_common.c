static int kmem_cache_sanity_check(const char *name, size_t size)
{
struct kmem_cache *s = NULL;
if (!name || in_interrupt() || size < sizeof(void *) ||
size > KMALLOC_MAX_SIZE) {
pr_err("kmem_cache_create(%s) integrity check failed\n", name);
return -EINVAL;
}
list_for_each_entry(s, &slab_caches, list) {
char tmp;
int res;
res = probe_kernel_address(s->name, tmp);
if (res) {
pr_err("Slab cache with size %d has lost its name\n",
s->object_size);
continue;
}
if (!strcmp(s->name, name)) {
pr_err("%s (%s): Cache name already exists.\n",
__func__, name);
dump_stack();
s = NULL;
return -EINVAL;
}
}
WARN_ON(strchr(name, ' '));
return 0;
}
static inline int kmem_cache_sanity_check(const char *name, size_t size)
{
return 0;
}
struct kmem_cache *kmem_cache_create(const char *name, size_t size, size_t align,
unsigned long flags, void (*ctor)(void *))
{
struct kmem_cache *s = NULL;
int err = 0;
get_online_cpus();
mutex_lock(&slab_mutex);
if (!kmem_cache_sanity_check(name, size) == 0)
goto out_locked;
s = __kmem_cache_alias(name, size, align, flags, ctor);
if (s)
goto out_locked;
s = kmem_cache_zalloc(kmem_cache, GFP_KERNEL);
if (s) {
s->object_size = s->size = size;
s->align = align;
s->ctor = ctor;
s->name = kstrdup(name, GFP_KERNEL);
if (!s->name) {
kmem_cache_free(kmem_cache, s);
err = -ENOMEM;
goto out_locked;
}
err = __kmem_cache_create(s, flags);
if (!err) {
s->refcount = 1;
list_add(&s->list, &slab_caches);
} else {
kfree(s->name);
kmem_cache_free(kmem_cache, s);
}
} else
err = -ENOMEM;
out_locked:
mutex_unlock(&slab_mutex);
put_online_cpus();
if (err) {
if (flags & SLAB_PANIC)
panic("kmem_cache_create: Failed to create slab '%s'. Error %d\n",
name, err);
else {
printk(KERN_WARNING "kmem_cache_create(%s) failed with error %d",
name, err);
dump_stack();
}
return NULL;
}
return s;
}
void kmem_cache_destroy(struct kmem_cache *s)
{
get_online_cpus();
mutex_lock(&slab_mutex);
s->refcount--;
if (!s->refcount) {
list_del(&s->list);
if (!__kmem_cache_shutdown(s)) {
mutex_unlock(&slab_mutex);
if (s->flags & SLAB_DESTROY_BY_RCU)
rcu_barrier();
kfree(s->name);
kmem_cache_free(kmem_cache, s);
} else {
list_add(&s->list, &slab_caches);
mutex_unlock(&slab_mutex);
printk(KERN_ERR "kmem_cache_destroy %s: Slab cache still has objects\n",
s->name);
dump_stack();
}
} else {
mutex_unlock(&slab_mutex);
}
put_online_cpus();
}
int slab_is_available(void)
{
return slab_state >= UP;
}
