void *
kmem_zalloc_greedy(size_t *size, size_t minsize, size_t maxsize)
{
void *ptr;
size_t kmsize = maxsize;
while (!(ptr = kmem_zalloc_large(kmsize))) {
if ((kmsize >>= 1) <= minsize)
kmsize = minsize;
}
if (ptr)
*size = kmsize;
return ptr;
}
void *
kmem_alloc(size_t size, unsigned int __nocast flags)
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
"possible memory allocation deadlock in %s (mode:0x%x)",
__func__, lflags);
congestion_wait(BLK_RW_ASYNC, HZ/50);
} while (1);
}
void *
kmem_zalloc(size_t size, unsigned int __nocast flags)
{
void *ptr;
ptr = kmem_alloc(size, flags);
if (ptr)
memset((char *)ptr, 0, (int)size);
return ptr;
}
void
kmem_free(const void *ptr)
{
if (!is_vmalloc_addr(ptr)) {
kfree(ptr);
} else {
vfree(ptr);
}
}
void *
kmem_realloc(const void *ptr, size_t newsize, size_t oldsize,
unsigned int __nocast flags)
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
kmem_zone_alloc(kmem_zone_t *zone, unsigned int __nocast flags)
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
"possible memory allocation deadlock in %s (mode:0x%x)",
__func__, lflags);
congestion_wait(BLK_RW_ASYNC, HZ/50);
} while (1);
}
void *
kmem_zone_zalloc(kmem_zone_t *zone, unsigned int __nocast flags)
{
void *ptr;
ptr = kmem_zone_alloc(zone, flags);
if (ptr)
memset((char *)ptr, 0, kmem_cache_size(zone));
return ptr;
}
