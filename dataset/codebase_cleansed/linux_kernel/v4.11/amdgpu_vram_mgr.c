static int amdgpu_vram_mgr_init(struct ttm_mem_type_manager *man,
unsigned long p_size)
{
struct amdgpu_vram_mgr *mgr;
mgr = kzalloc(sizeof(*mgr), GFP_KERNEL);
if (!mgr)
return -ENOMEM;
drm_mm_init(&mgr->mm, 0, p_size);
spin_lock_init(&mgr->lock);
man->priv = mgr;
return 0;
}
static int amdgpu_vram_mgr_fini(struct ttm_mem_type_manager *man)
{
struct amdgpu_vram_mgr *mgr = man->priv;
spin_lock(&mgr->lock);
if (!drm_mm_clean(&mgr->mm)) {
spin_unlock(&mgr->lock);
return -EBUSY;
}
drm_mm_takedown(&mgr->mm);
spin_unlock(&mgr->lock);
kfree(mgr);
man->priv = NULL;
return 0;
}
static int amdgpu_vram_mgr_new(struct ttm_mem_type_manager *man,
struct ttm_buffer_object *tbo,
const struct ttm_place *place,
struct ttm_mem_reg *mem)
{
struct amdgpu_bo *bo = container_of(tbo, struct amdgpu_bo, tbo);
struct amdgpu_vram_mgr *mgr = man->priv;
struct drm_mm *mm = &mgr->mm;
struct drm_mm_node *nodes;
enum drm_mm_insert_mode mode;
unsigned long lpfn, num_nodes, pages_per_node, pages_left;
unsigned i;
int r;
lpfn = place->lpfn;
if (!lpfn)
lpfn = man->size;
if (bo->flags & AMDGPU_GEM_CREATE_VRAM_CONTIGUOUS ||
place->lpfn || amdgpu_vram_page_split == -1) {
pages_per_node = ~0ul;
num_nodes = 1;
} else {
pages_per_node = max((uint32_t)amdgpu_vram_page_split,
mem->page_alignment);
num_nodes = DIV_ROUND_UP(mem->num_pages, pages_per_node);
}
nodes = kcalloc(num_nodes, sizeof(*nodes), GFP_KERNEL);
if (!nodes)
return -ENOMEM;
mode = DRM_MM_INSERT_BEST;
if (place->flags & TTM_PL_FLAG_TOPDOWN)
mode = DRM_MM_INSERT_HIGH;
pages_left = mem->num_pages;
spin_lock(&mgr->lock);
for (i = 0; i < num_nodes; ++i) {
unsigned long pages = min(pages_left, pages_per_node);
uint32_t alignment = mem->page_alignment;
if (pages == pages_per_node)
alignment = pages_per_node;
r = drm_mm_insert_node_in_range(mm, &nodes[i],
pages, alignment, 0,
place->fpfn, lpfn,
mode);
if (unlikely(r))
goto error;
pages_left -= pages;
}
spin_unlock(&mgr->lock);
mem->start = num_nodes == 1 ? nodes[0].start : AMDGPU_BO_INVALID_OFFSET;
mem->mm_node = nodes;
return 0;
error:
while (i--)
drm_mm_remove_node(&nodes[i]);
spin_unlock(&mgr->lock);
kfree(nodes);
return r == -ENOSPC ? 0 : r;
}
static void amdgpu_vram_mgr_del(struct ttm_mem_type_manager *man,
struct ttm_mem_reg *mem)
{
struct amdgpu_vram_mgr *mgr = man->priv;
struct drm_mm_node *nodes = mem->mm_node;
unsigned pages = mem->num_pages;
if (!mem->mm_node)
return;
spin_lock(&mgr->lock);
while (pages) {
pages -= nodes->size;
drm_mm_remove_node(nodes);
++nodes;
}
spin_unlock(&mgr->lock);
kfree(mem->mm_node);
mem->mm_node = NULL;
}
static void amdgpu_vram_mgr_debug(struct ttm_mem_type_manager *man,
const char *prefix)
{
struct amdgpu_vram_mgr *mgr = man->priv;
struct drm_printer p = drm_debug_printer(prefix);
spin_lock(&mgr->lock);
drm_mm_print(&mgr->mm, &p);
spin_unlock(&mgr->lock);
}
