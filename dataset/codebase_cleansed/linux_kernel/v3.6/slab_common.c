struct kmem_cache *kmem_cache_create(const char *name, size_t size, size_t align,
unsigned long flags, void (*ctor)(void *))
{
struct kmem_cache *s = NULL;
#ifdef CONFIG_DEBUG_VM
if (!name || in_interrupt() || size < sizeof(void *) ||
size > KMALLOC_MAX_SIZE) {
printk(KERN_ERR "kmem_cache_create(%s) integrity check"
" failed\n", name);
goto out;
}
#endif
get_online_cpus();
mutex_lock(&slab_mutex);
#ifdef CONFIG_DEBUG_VM
list_for_each_entry(s, &slab_caches, list) {
char tmp;
int res;
res = probe_kernel_address(s->name, tmp);
if (res) {
printk(KERN_ERR
"Slab cache with size %d has lost its name\n",
s->object_size);
continue;
}
if (!strcmp(s->name, name)) {
printk(KERN_ERR "kmem_cache_create(%s): Cache name"
" already exists.\n",
name);
dump_stack();
s = NULL;
goto oops;
}
}
WARN_ON(strchr(name, ' '));
#endif
s = __kmem_cache_create(name, size, align, flags, ctor);
#ifdef CONFIG_DEBUG_VM
oops:
#endif
mutex_unlock(&slab_mutex);
put_online_cpus();
#ifdef CONFIG_DEBUG_VM
out:
#endif
if (!s && (flags & SLAB_PANIC))
panic("kmem_cache_create: Failed to create slab '%s'\n", name);
return s;
}
int slab_is_available(void)
{
return slab_state >= UP;
}
