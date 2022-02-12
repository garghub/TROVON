static int __init atari_stram_setup(char *arg)
{
if (!MACH_IS_ATARI)
return 0;
pool_size = memparse(arg, NULL);
return 0;
}
void __init atari_stram_init(void)
{
int i;
kernel_in_stram = (m68k_memory[0].addr == 0);
for (i = 0; i < m68k_num_memory; ++i) {
if (m68k_memory[i].addr == 0) {
return;
}
}
panic("atari_stram_init: no ST-RAM found!");
}
void __init atari_stram_reserve_pages(void *start_mem)
{
if (kernel_in_stram) {
pr_debug("atari_stram pool: kernel in ST-RAM, using alloc_bootmem!\n");
stram_pool.start = (resource_size_t)alloc_bootmem_low_pages(pool_size);
stram_pool.end = stram_pool.start + pool_size - 1;
request_resource(&iomem_resource, &stram_pool);
stram_virt_offset = 0;
pr_debug("atari_stram pool: size = %lu bytes, resource = %pR\n",
pool_size, &stram_pool);
pr_debug("atari_stram pool: stram_virt_offset = %lx\n",
stram_virt_offset);
}
}
int __init atari_stram_map_pages(void)
{
if (!kernel_in_stram) {
pr_debug("atari_stram pool: kernel not in ST-RAM, using ioremap!\n");
stram_pool.start = PAGE_SIZE;
stram_pool.end = stram_pool.start + pool_size - 1;
request_resource(&iomem_resource, &stram_pool);
stram_virt_offset = (unsigned long) ioremap(stram_pool.start,
resource_size(&stram_pool)) - stram_pool.start;
pr_debug("atari_stram pool: size = %lu bytes, resource = %pR\n",
pool_size, &stram_pool);
pr_debug("atari_stram pool: stram_virt_offset = %lx\n",
stram_virt_offset);
}
return 0;
}
void *atari_stram_to_virt(unsigned long phys)
{
return (void *)(phys + stram_virt_offset);
}
unsigned long atari_stram_to_phys(void *virt)
{
return (unsigned long)(virt - stram_virt_offset);
}
void *atari_stram_alloc(unsigned long size, const char *owner)
{
struct resource *res;
int error;
pr_debug("atari_stram_alloc: allocate %lu bytes\n", size);
size = PAGE_ALIGN(size);
res = kzalloc(sizeof(struct resource), GFP_KERNEL);
if (!res)
return NULL;
res->name = owner;
error = allocate_resource(&stram_pool, res, size, 0, UINT_MAX,
PAGE_SIZE, NULL, NULL);
if (error < 0) {
pr_err("atari_stram_alloc: allocate_resource() failed %d!\n",
error);
kfree(res);
return NULL;
}
pr_debug("atari_stram_alloc: returning %pR\n", res);
return atari_stram_to_virt(res->start);
}
void atari_stram_free(void *addr)
{
unsigned long start = atari_stram_to_phys(addr);
struct resource *res;
unsigned long size;
res = lookup_resource(&stram_pool, start);
if (!res) {
pr_err("atari_stram_free: trying to free nonexistent region "
"at %p\n", addr);
return;
}
size = resource_size(res);
pr_debug("atari_stram_free: free %lu bytes at %p\n", size, addr);
release_resource(res);
kfree(res);
}
