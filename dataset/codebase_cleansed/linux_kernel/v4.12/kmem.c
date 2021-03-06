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
unsigned nofs_flag = 0;
void *ptr;
gfp_t lflags;
ptr = kmem_zalloc(size, flags | KM_MAYFAIL);
if (ptr)
return ptr;
if (flags & KM_NOFS)
nofs_flag = memalloc_nofs_save();
lflags = kmem_flags_convert(flags);
ptr = __vmalloc(size, lflags | __GFP_ZERO, PAGE_KERNEL);
if (flags & KM_NOFS)
memalloc_nofs_restore(nofs_flag);
return ptr;
}
void *
kmem_realloc(const void *old, size_t newsize, xfs_km_flags_t flags)
{
int retries = 0;
gfp_t lflags = kmem_flags_convert(flags);
void *ptr;
do {
ptr = krealloc(old, newsize, lflags);
if (ptr || (flags & (KM_MAYFAIL|KM_NOSLEEP)))
return ptr;
if (!(++retries % 100))
xfs_err(NULL,
"%s(%u) possible memory allocation deadlock size %zu in %s (mode:0x%x)",
current->comm, current->pid,
newsize, __func__, lflags);
congestion_wait(BLK_RW_ASYNC, HZ/50);
} while (1);
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
