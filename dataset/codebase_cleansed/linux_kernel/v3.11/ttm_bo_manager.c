static int ttm_bo_man_get_node(struct ttm_mem_type_manager *man,
struct ttm_buffer_object *bo,
struct ttm_placement *placement,
struct ttm_mem_reg *mem)
{
struct ttm_range_manager *rman = (struct ttm_range_manager *) man->priv;
struct drm_mm *mm = &rman->mm;
struct drm_mm_node *node = NULL;
unsigned long lpfn;
int ret;
lpfn = placement->lpfn;
if (!lpfn)
lpfn = man->size;
do {
ret = drm_mm_pre_get(mm);
if (unlikely(ret))
return ret;
spin_lock(&rman->lock);
node = drm_mm_search_free_in_range(mm,
mem->num_pages, mem->page_alignment,
placement->fpfn, lpfn, 1);
if (unlikely(node == NULL)) {
spin_unlock(&rman->lock);
return 0;
}
node = drm_mm_get_block_atomic_range(node, mem->num_pages,
mem->page_alignment,
placement->fpfn,
lpfn);
spin_unlock(&rman->lock);
} while (node == NULL);
mem->mm_node = node;
mem->start = node->start;
return 0;
}
static void ttm_bo_man_put_node(struct ttm_mem_type_manager *man,
struct ttm_mem_reg *mem)
{
struct ttm_range_manager *rman = (struct ttm_range_manager *) man->priv;
if (mem->mm_node) {
spin_lock(&rman->lock);
drm_mm_put_block(mem->mm_node);
spin_unlock(&rman->lock);
mem->mm_node = NULL;
}
}
static int ttm_bo_man_init(struct ttm_mem_type_manager *man,
unsigned long p_size)
{
struct ttm_range_manager *rman;
rman = kzalloc(sizeof(*rman), GFP_KERNEL);
if (!rman)
return -ENOMEM;
drm_mm_init(&rman->mm, 0, p_size);
spin_lock_init(&rman->lock);
man->priv = rman;
return 0;
}
static int ttm_bo_man_takedown(struct ttm_mem_type_manager *man)
{
struct ttm_range_manager *rman = (struct ttm_range_manager *) man->priv;
struct drm_mm *mm = &rman->mm;
spin_lock(&rman->lock);
if (drm_mm_clean(mm)) {
drm_mm_takedown(mm);
spin_unlock(&rman->lock);
kfree(rman);
man->priv = NULL;
return 0;
}
spin_unlock(&rman->lock);
return -EBUSY;
}
static void ttm_bo_man_debug(struct ttm_mem_type_manager *man,
const char *prefix)
{
struct ttm_range_manager *rman = (struct ttm_range_manager *) man->priv;
spin_lock(&rman->lock);
drm_mm_debug_table(&rman->mm, prefix);
spin_unlock(&rman->lock);
}
