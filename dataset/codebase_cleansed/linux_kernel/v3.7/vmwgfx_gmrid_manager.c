static int vmw_gmrid_man_get_node(struct ttm_mem_type_manager *man,
struct ttm_buffer_object *bo,
struct ttm_placement *placement,
struct ttm_mem_reg *mem)
{
struct vmwgfx_gmrid_man *gman =
(struct vmwgfx_gmrid_man *)man->priv;
int ret = 0;
int id;
mem->mm_node = NULL;
spin_lock(&gman->lock);
if (gman->max_gmr_pages > 0) {
gman->used_gmr_pages += bo->num_pages;
if (unlikely(gman->used_gmr_pages > gman->max_gmr_pages))
goto out_err_locked;
}
do {
spin_unlock(&gman->lock);
if (unlikely(ida_pre_get(&gman->gmr_ida, GFP_KERNEL) == 0)) {
ret = -ENOMEM;
goto out_err;
}
spin_lock(&gman->lock);
ret = ida_get_new(&gman->gmr_ida, &id);
if (unlikely(ret == 0 && id >= gman->max_gmr_ids)) {
ida_remove(&gman->gmr_ida, id);
ret = 0;
goto out_err_locked;
}
} while (ret == -EAGAIN);
if (likely(ret == 0)) {
mem->mm_node = gman;
mem->start = id;
mem->num_pages = bo->num_pages;
} else
goto out_err_locked;
spin_unlock(&gman->lock);
return 0;
out_err:
spin_lock(&gman->lock);
out_err_locked:
gman->used_gmr_pages -= bo->num_pages;
spin_unlock(&gman->lock);
return ret;
}
static void vmw_gmrid_man_put_node(struct ttm_mem_type_manager *man,
struct ttm_mem_reg *mem)
{
struct vmwgfx_gmrid_man *gman =
(struct vmwgfx_gmrid_man *)man->priv;
if (mem->mm_node) {
spin_lock(&gman->lock);
ida_remove(&gman->gmr_ida, mem->start);
gman->used_gmr_pages -= mem->num_pages;
spin_unlock(&gman->lock);
mem->mm_node = NULL;
}
}
static int vmw_gmrid_man_init(struct ttm_mem_type_manager *man,
unsigned long p_size)
{
struct vmw_private *dev_priv =
container_of(man->bdev, struct vmw_private, bdev);
struct vmwgfx_gmrid_man *gman =
kzalloc(sizeof(*gman), GFP_KERNEL);
if (unlikely(gman == NULL))
return -ENOMEM;
spin_lock_init(&gman->lock);
gman->max_gmr_pages = dev_priv->max_gmr_pages;
gman->used_gmr_pages = 0;
ida_init(&gman->gmr_ida);
gman->max_gmr_ids = p_size;
man->priv = (void *) gman;
return 0;
}
static int vmw_gmrid_man_takedown(struct ttm_mem_type_manager *man)
{
struct vmwgfx_gmrid_man *gman =
(struct vmwgfx_gmrid_man *)man->priv;
if (gman) {
ida_destroy(&gman->gmr_ida);
kfree(gman);
}
return 0;
}
static void vmw_gmrid_man_debug(struct ttm_mem_type_manager *man,
const char *prefix)
{
printk(KERN_INFO "%s: No debug info available for the GMR "
"id manager.\n", prefix);
}
