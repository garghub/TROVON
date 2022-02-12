struct memregion *
visor_memregion_create(HOSTADDRESS physaddr, ulong nbytes)
{
struct memregion *rc = NULL;
struct memregion *memregion;
memregion = kzalloc(sizeof(*memregion), GFP_KERNEL | __GFP_NORETRY);
if (memregion == NULL)
return NULL;
memregion->physaddr = physaddr;
memregion->nbytes = nbytes;
memregion->overlapped = FALSE;
if (!mapit(memregion)) {
rc = NULL;
goto cleanup;
}
rc = memregion;
cleanup:
if (rc == NULL) {
visor_memregion_destroy(memregion);
memregion = NULL;
}
return rc;
}
struct memregion *
visor_memregion_create_overlapped(struct memregion *parent, ulong offset,
ulong nbytes)
{
struct memregion *memregion = NULL;
if (parent == NULL)
return NULL;
if (parent->mapped == NULL)
return NULL;
if ((offset >= parent->nbytes) ||
((offset + nbytes) >= parent->nbytes))
return NULL;
memregion = kzalloc(sizeof(*memregion), GFP_KERNEL|__GFP_NORETRY);
if (memregion == NULL)
return NULL;
memregion->physaddr = parent->physaddr + offset;
memregion->nbytes = nbytes;
memregion->mapped = ((u8 __iomem *)(parent->mapped)) + offset;
memregion->requested = FALSE;
memregion->overlapped = TRUE;
return memregion;
}
static BOOL
mapit(struct memregion *memregion)
{
ulong physaddr = (ulong)(memregion->physaddr);
ulong nbytes = memregion->nbytes;
memregion->requested = FALSE;
if (request_mem_region(physaddr, nbytes, MYDRVNAME))
memregion->requested = TRUE;
memregion->mapped = ioremap_cache(physaddr, nbytes);
if (!memregion->mapped)
return FALSE;
return TRUE;
}
static void
unmapit(struct memregion *memregion)
{
if (memregion->mapped != NULL) {
iounmap(memregion->mapped);
memregion->mapped = NULL;
}
if (memregion->requested) {
release_mem_region((ulong)(memregion->physaddr),
memregion->nbytes);
memregion->requested = FALSE;
}
}
HOSTADDRESS
visor_memregion_get_physaddr(struct memregion *memregion)
{
return memregion->physaddr;
}
ulong
visor_memregion_get_nbytes(struct memregion *memregion)
{
return memregion->nbytes;
}
void __iomem *
visor_memregion_get_pointer(struct memregion *memregion)
{
return memregion->mapped;
}
int
visor_memregion_resize(struct memregion *memregion, ulong newsize)
{
if (newsize == memregion->nbytes)
return 0;
if (memregion->overlapped)
memregion->nbytes = newsize;
else {
unmapit(memregion);
memregion->nbytes = newsize;
if (!mapit(memregion))
return -1;
}
return 0;
}
static int
memregion_readwrite(BOOL is_write,
struct memregion *memregion, ulong offset,
void *local, ulong nbytes)
{
if (offset + nbytes > memregion->nbytes)
return -EIO;
if (is_write)
memcpy_toio(memregion->mapped + offset, local, nbytes);
else
memcpy_fromio(local, memregion->mapped + offset, nbytes);
return 0;
}
int
visor_memregion_read(struct memregion *memregion, ulong offset, void *dest,
ulong nbytes)
{
return memregion_readwrite(FALSE, memregion, offset, dest, nbytes);
}
int
visor_memregion_write(struct memregion *memregion, ulong offset, void *src,
ulong nbytes)
{
return memregion_readwrite(TRUE, memregion, offset, src, nbytes);
}
void
visor_memregion_destroy(struct memregion *memregion)
{
if (memregion == NULL)
return;
if (!memregion->overlapped)
unmapit(memregion);
kfree(memregion);
}
