static int vmw_gmrid_man_get_node(struct ttm_mem_type_manager *man,
struct ttm_buffer_object *bo,
struct ttm_placement *placement,
struct ttm_mem_reg *mem)
{
struct vmwgfx_gmrid_man *gman =
(struct vmwgfx_gmrid_man *)man->priv;
int ret;
int id;
mem->mm_node = NULL;
do {
if (unlikely(ida_pre_get(&gman->gmr_ida, GFP_KERNEL) == 0))
return -ENOMEM;
spin_lock(&gman->lock);
ret = ida_get_new(&gman->gmr_ida, &id);
if (unlikely(ret == 0 && id >= gman->max_gmr_ids)) {
ida_remove(&gman->gmr_ida, id);
spin_unlock(&gman->lock);
return 0;
}
spin_unlock(&gman->lock);
} while (ret == -EAGAIN);
if (likely(ret == 0)) {
mem->mm_node = gman;
mem->start = id;
}
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
spin_unlock(&gman->lock);
mem->mm_node = NULL;
}
}
static int vmw_gmrid_man_init(struct ttm_mem_type_manager *man,
unsigned long p_size)
{
struct vmwgfx_gmrid_man *gman =
kzalloc(sizeof(*gman), GFP_KERNEL);
if (unlikely(gman == NULL))
return -ENOMEM;
spin_lock_init(&gman->lock);
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
