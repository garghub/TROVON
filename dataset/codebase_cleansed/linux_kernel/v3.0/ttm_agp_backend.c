static int ttm_agp_populate(struct ttm_backend *backend,
unsigned long num_pages, struct page **pages,
struct page *dummy_read_page,
dma_addr_t *dma_addrs)
{
struct ttm_agp_backend *agp_be =
container_of(backend, struct ttm_agp_backend, backend);
struct page **cur_page, **last_page = pages + num_pages;
struct agp_memory *mem;
mem = agp_allocate_memory(agp_be->bridge, num_pages, AGP_USER_MEMORY);
if (unlikely(mem == NULL))
return -ENOMEM;
mem->page_count = 0;
for (cur_page = pages; cur_page < last_page; ++cur_page) {
struct page *page = *cur_page;
if (!page)
page = dummy_read_page;
mem->pages[mem->page_count++] = page;
}
agp_be->mem = mem;
return 0;
}
static int ttm_agp_bind(struct ttm_backend *backend, struct ttm_mem_reg *bo_mem)
{
struct ttm_agp_backend *agp_be =
container_of(backend, struct ttm_agp_backend, backend);
struct drm_mm_node *node = bo_mem->mm_node;
struct agp_memory *mem = agp_be->mem;
int cached = (bo_mem->placement & TTM_PL_FLAG_CACHED);
int ret;
mem->is_flushed = 1;
mem->type = (cached) ? AGP_USER_CACHED_MEMORY : AGP_USER_MEMORY;
ret = agp_bind_memory(mem, node->start);
if (ret)
printk(KERN_ERR TTM_PFX "AGP Bind memory failed.\n");
return ret;
}
static int ttm_agp_unbind(struct ttm_backend *backend)
{
struct ttm_agp_backend *agp_be =
container_of(backend, struct ttm_agp_backend, backend);
if (agp_be->mem->is_bound)
return agp_unbind_memory(agp_be->mem);
else
return 0;
}
static void ttm_agp_clear(struct ttm_backend *backend)
{
struct ttm_agp_backend *agp_be =
container_of(backend, struct ttm_agp_backend, backend);
struct agp_memory *mem = agp_be->mem;
if (mem) {
ttm_agp_unbind(backend);
agp_free_memory(mem);
}
agp_be->mem = NULL;
}
static void ttm_agp_destroy(struct ttm_backend *backend)
{
struct ttm_agp_backend *agp_be =
container_of(backend, struct ttm_agp_backend, backend);
if (agp_be->mem)
ttm_agp_clear(backend);
kfree(agp_be);
}
struct ttm_backend *ttm_agp_backend_init(struct ttm_bo_device *bdev,
struct agp_bridge_data *bridge)
{
struct ttm_agp_backend *agp_be;
agp_be = kmalloc(sizeof(*agp_be), GFP_KERNEL);
if (!agp_be)
return NULL;
agp_be->mem = NULL;
agp_be->bridge = bridge;
agp_be->backend.func = &ttm_agp_func;
agp_be->backend.bdev = bdev;
return &agp_be->backend;
}
