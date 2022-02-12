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
void *stram_start;
stram_start = phys_to_virt(0);
kernel_in_stram = (stram_start == 0);
for (i = 0; i < m68k_num_memory; ++i) {
if (m68k_memory[i].addr == 0) {
return;
}
}
panic("atari_stram_init: no ST-RAM found!");
}
void __init atari_stram_reserve_pages(void *start_mem)
{
if (!kernel_in_stram)
reserve_bootmem(0, PAGE_SIZE, BOOTMEM_DEFAULT);
stram_pool.start = (resource_size_t)alloc_bootmem_low_pages(pool_size);
stram_pool.end = stram_pool.start + pool_size - 1;
request_resource(&iomem_resource, &stram_pool);
pr_debug("atari_stram pool: size = %lu bytes, resource = %pR\n",
pool_size, &stram_pool);
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
return (void *)res->start;
}
void atari_stram_free(void *addr)
{
unsigned long start = (unsigned long)addr;
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
