void *
kmem_zalloc_greedy(size_t *size, size_t minsize, size_t maxsize)
{
void *ptr;
size_t kmsize = maxsize;
while (!(ptr = vzalloc(kmsize))) {
if ((kmsize >>= 1) <= minsize)
kmsize = minsize;
}
if (ptr)
*size = kmsize;
return ptr;
}
void *
kmem_alloc(size_t size, xfs_km_flags_t flags)
{
int retries = 0;
gfp_t lflags = kmem_flags_convert(flags);
void *ptr;
do {
ptr = kmalloc(size, lflags);
if (ptr || (flags & (KM_MAYFAIL|KM_NOSLEEP)))
return ptr;
if (!(++retries % 100))
xfs_err(NULL,
"%s(%u) possible memory allocation deadlock size %u in %s (mode:0x%x)",
current->comm, current->pid,
(unsigned int)size, __func__, lflags);
congestion_wait(BLK_RW_ASYNC, HZ/50);
} while (1);
}
void *
kmem_zalloc_large(size_t size, xfs_km_flags_t flags)
{
unsigned noio_flag = 0;
void *ptr;
gfp_t lflags;
ptr = kmem_zalloc(size, flags | KM_MAYFAIL);
if (ptr)
return ptr;
if ((current->flags & PF_FSTRANS) || (flags & KM_NOFS))
noio_flag = memalloc_noio_save();
lflags = kmem_flags_convert(flags);
ptr = __vmalloc(size, lflags | __GFP_HIGHMEM | __GFP_ZERO, PAGE_KERNEL);
if ((current->flags & PF_FSTRANS) || (flags & KM_NOFS))
memalloc_noio_restore(noio_flag);
return ptr;
}
void *
kmem_realloc(const void *ptr, size_t newsize, size_t oldsize,
xfs_km_flags_t flags)
{
void *new;
new = kmem_alloc(newsize, flags);
if (ptr) {
if (new)
memcpy(new, ptr,
((oldsize < newsize) ? oldsize : newsize));
kmem_free(ptr);
}
return new;
}
void *
kmem_zone_alloc(kmem_zone_t *zone, xfs_km_flags_t flags)
{
int retries = 0;
gfp_t lflags = kmem_flags_convert(flags);
void *ptr;
do {
ptr = kmem_cache_alloc(zone, lflags);
if (ptr || (flags & (KM_MAYFAIL|KM_NOSLEEP)))
return ptr;
if (!(++retries % 100))
xfs_err(NULL,
"%s(%u) possible memory allocation deadlock in %s (mode:0x%x)",
current->comm, current->pid,
__func__, lflags);
congestion_wait(BLK_RW_ASYNC, HZ/50);
} while (1);
}
