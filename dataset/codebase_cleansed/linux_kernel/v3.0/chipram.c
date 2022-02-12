void __init amiga_chip_init(void)
{
if (!AMIGAHW_PRESENT(CHIP_RAM))
return;
chipram_res.end = amiga_chip_size-1;
request_resource(&iomem_resource, &chipram_res);
chipavail = amiga_chip_size;
}
void *amiga_chip_alloc(unsigned long size, const char *name)
{
struct resource *res;
size = PAGE_ALIGN(size);
#ifdef DEBUG
printk("amiga_chip_alloc: allocate %ld bytes\n", size);
#endif
res = kzalloc(sizeof(struct resource), GFP_KERNEL);
if (!res)
return NULL;
res->name = name;
if (allocate_resource(&chipram_res, res, size, 0, UINT_MAX, PAGE_SIZE, NULL, NULL) < 0) {
kfree(res);
return NULL;
}
chipavail -= size;
#ifdef DEBUG
printk("amiga_chip_alloc: returning %lx\n", res->start);
#endif
return (void *)ZTWO_VADDR(res->start);
}
void * __init amiga_chip_alloc_res(unsigned long size, struct resource *res)
{
unsigned long start;
size = PAGE_ALIGN(size);
start = CHIP_PHYSADDR + chipavail - size;
#ifdef DEBUG
printk("amiga_chip_alloc_res: allocate %ld bytes\n", size);
#endif
if (allocate_resource(&chipram_res, res, size, start, UINT_MAX, PAGE_SIZE, NULL, NULL) < 0) {
printk("amiga_chip_alloc_res: first alloc failed!\n");
if (allocate_resource(&chipram_res, res, size, 0, UINT_MAX, PAGE_SIZE, NULL, NULL) < 0)
return NULL;
}
chipavail -= size;
#ifdef DEBUG
printk("amiga_chip_alloc_res: returning %lx\n", res->start);
#endif
return (void *)ZTWO_VADDR(res->start);
}
void amiga_chip_free(void *ptr)
{
unsigned long start = ZTWO_PADDR(ptr);
struct resource **p, *res;
unsigned long size;
for (p = &chipram_res.child; (res = *p); p = &res->sibling) {
if (res->start != start)
continue;
*p = res->sibling;
size = res->end-start;
#ifdef DEBUG
printk("amiga_chip_free: free %ld bytes at %p\n", size, ptr);
#endif
chipavail += size;
kfree(res);
return;
}
printk("amiga_chip_free: trying to free nonexistent region at %p\n", ptr);
}
unsigned long amiga_chip_avail(void)
{
#ifdef DEBUG
printk("amiga_chip_avail : %ld bytes\n", chipavail);
#endif
return chipavail;
}
