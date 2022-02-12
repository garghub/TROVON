static int ttm_agp_bind(struct ttm_tt *ttm, struct ttm_mem_reg *bo_mem)
{
struct ttm_agp_backend *agp_be = container_of(ttm, struct ttm_agp_backend, ttm);
struct drm_mm_node *node = bo_mem->mm_node;
struct agp_memory *mem;
int ret, cached = (bo_mem->placement & TTM_PL_FLAG_CACHED);
unsigned i;
mem = agp_allocate_memory(agp_be->bridge, ttm->num_pages, AGP_USER_MEMORY);
if (unlikely(mem == NULL))
return -ENOMEM;
mem->page_count = 0;
for (i = 0; i < ttm->num_pages; i++) {
struct page *page = ttm->pages[i];
if (!page)
page = ttm->dummy_read_page;
mem->pages[mem->page_count++] = page;
}
agp_be->mem = mem;
mem->is_flushed = 1;
mem->type = (cached) ? AGP_USER_CACHED_MEMORY : AGP_USER_MEMORY;
ret = agp_bind_memory(mem, node->start);
if (ret)
pr_err("AGP Bind memory failed\n");
return ret;
}
static int ttm_agp_unbind(struct ttm_tt *ttm)
{
struct ttm_agp_backend *agp_be = container_of(ttm, struct ttm_agp_backend, ttm);
if (agp_be->mem) {
if (agp_be->mem->is_bound)
return agp_unbind_memory(agp_be->mem);
agp_free_memory(agp_be->mem);
agp_be->mem = NULL;
}
return 0;
}
static void ttm_agp_destroy(struct ttm_tt *ttm)
{
struct ttm_agp_backend *agp_be = container_of(ttm, struct ttm_agp_backend, ttm);
if (agp_be->mem)
ttm_agp_unbind(ttm);
ttm_tt_fini(ttm);
kfree(agp_be);
}
struct ttm_tt *ttm_agp_tt_create(struct ttm_bo_device *bdev,
struct agp_bridge_data *bridge,
unsigned long size, uint32_t page_flags,
struct page *dummy_read_page)
{
struct ttm_agp_backend *agp_be;
agp_be = kmalloc(sizeof(*agp_be), GFP_KERNEL);
if (!agp_be)
return NULL;
agp_be->mem = NULL;
agp_be->bridge = bridge;
agp_be->ttm.func = &ttm_agp_func;
if (ttm_tt_init(&agp_be->ttm, bdev, size, page_flags, dummy_read_page)) {
return NULL;
}
return &agp_be->ttm;
}
int ttm_agp_tt_populate(struct ttm_tt *ttm)
{
if (ttm->state != tt_unpopulated)
return 0;
return ttm_pool_populate(ttm);
}
void ttm_agp_tt_unpopulate(struct ttm_tt *ttm)
{
ttm_pool_unpopulate(ttm);
}
