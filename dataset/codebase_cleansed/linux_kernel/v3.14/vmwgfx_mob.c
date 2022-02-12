static int vmw_setup_otable_base(struct vmw_private *dev_priv,
SVGAOTableType type,
unsigned long offset,
struct vmw_otable *otable)
{
struct {
SVGA3dCmdHeader header;
SVGA3dCmdSetOTableBase64 body;
} *cmd;
struct vmw_mob *mob;
const struct vmw_sg_table *vsgt;
struct vmw_piter iter;
int ret;
BUG_ON(otable->page_table != NULL);
vsgt = vmw_bo_sg_table(dev_priv->otable_bo);
vmw_piter_start(&iter, vsgt, offset >> PAGE_SHIFT);
WARN_ON(!vmw_piter_next(&iter));
mob = vmw_mob_create(otable->size >> PAGE_SHIFT);
if (unlikely(mob == NULL)) {
DRM_ERROR("Failed creating OTable page table.\n");
return -ENOMEM;
}
if (otable->size <= PAGE_SIZE) {
mob->pt_level = VMW_MOBFMT_PTDEPTH_0;
mob->pt_root_page = vmw_piter_dma_addr(&iter);
} else if (vsgt->num_regions == 1) {
mob->pt_level = SVGA3D_MOBFMT_RANGE;
mob->pt_root_page = vmw_piter_dma_addr(&iter);
} else {
ret = vmw_mob_pt_populate(dev_priv, mob);
if (unlikely(ret != 0))
goto out_no_populate;
vmw_mob_pt_setup(mob, iter, otable->size >> PAGE_SHIFT);
mob->pt_level += VMW_MOBFMT_PTDEPTH_1 - SVGA3D_MOBFMT_PTDEPTH_1;
}
cmd = vmw_fifo_reserve(dev_priv, sizeof(*cmd));
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for OTable setup.\n");
ret = -ENOMEM;
goto out_no_fifo;
}
memset(cmd, 0, sizeof(*cmd));
cmd->header.id = SVGA_3D_CMD_SET_OTABLE_BASE64;
cmd->header.size = sizeof(cmd->body);
cmd->body.type = type;
cmd->body.baseAddress = cpu_to_le64(mob->pt_root_page >> PAGE_SHIFT);
cmd->body.sizeInBytes = otable->size;
cmd->body.validSizeInBytes = 0;
cmd->body.ptDepth = mob->pt_level;
BUG_ON(mob->pt_level == VMW_MOBFMT_PTDEPTH_2);
vmw_fifo_commit(dev_priv, sizeof(*cmd));
otable->page_table = mob;
return 0;
out_no_fifo:
out_no_populate:
vmw_mob_destroy(mob);
return ret;
}
static void vmw_takedown_otable_base(struct vmw_private *dev_priv,
SVGAOTableType type,
struct vmw_otable *otable)
{
struct {
SVGA3dCmdHeader header;
SVGA3dCmdSetOTableBase body;
} *cmd;
struct ttm_buffer_object *bo;
if (otable->page_table == NULL)
return;
bo = otable->page_table->pt_bo;
cmd = vmw_fifo_reserve(dev_priv, sizeof(*cmd));
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for OTable "
"takedown.\n");
} else {
memset(cmd, 0, sizeof(*cmd));
cmd->header.id = SVGA_3D_CMD_SET_OTABLE_BASE;
cmd->header.size = sizeof(cmd->body);
cmd->body.type = type;
cmd->body.baseAddress = 0;
cmd->body.sizeInBytes = 0;
cmd->body.validSizeInBytes = 0;
cmd->body.ptDepth = SVGA3D_MOBFMT_INVALID;
vmw_fifo_commit(dev_priv, sizeof(*cmd));
}
if (bo) {
int ret;
ret = ttm_bo_reserve(bo, false, true, false, NULL);
BUG_ON(ret != 0);
vmw_fence_single_bo(bo, NULL);
ttm_bo_unreserve(bo);
}
vmw_mob_destroy(otable->page_table);
otable->page_table = NULL;
}
int vmw_otables_setup(struct vmw_private *dev_priv)
{
unsigned long offset;
unsigned long bo_size;
struct vmw_otable *otables;
SVGAOTableType i;
int ret;
otables = kzalloc(SVGA_OTABLE_DX9_MAX * sizeof(*otables),
GFP_KERNEL);
if (unlikely(otables == NULL)) {
DRM_ERROR("Failed to allocate space for otable "
"metadata.\n");
return -ENOMEM;
}
otables[SVGA_OTABLE_MOB].size =
VMWGFX_NUM_MOB * SVGA3D_OTABLE_MOB_ENTRY_SIZE;
otables[SVGA_OTABLE_SURFACE].size =
VMWGFX_NUM_GB_SURFACE * SVGA3D_OTABLE_SURFACE_ENTRY_SIZE;
otables[SVGA_OTABLE_CONTEXT].size =
VMWGFX_NUM_GB_CONTEXT * SVGA3D_OTABLE_CONTEXT_ENTRY_SIZE;
otables[SVGA_OTABLE_SHADER].size =
VMWGFX_NUM_GB_SHADER * SVGA3D_OTABLE_SHADER_ENTRY_SIZE;
otables[SVGA_OTABLE_SCREEN_TARGET].size =
VMWGFX_NUM_GB_SCREEN_TARGET *
SVGA3D_OTABLE_SCREEN_TARGET_ENTRY_SIZE;
bo_size = 0;
for (i = 0; i < SVGA_OTABLE_DX9_MAX; ++i) {
otables[i].size =
(otables[i].size + PAGE_SIZE - 1) & PAGE_MASK;
bo_size += otables[i].size;
}
ret = ttm_bo_create(&dev_priv->bdev, bo_size,
ttm_bo_type_device,
&vmw_sys_ne_placement,
0, false, NULL,
&dev_priv->otable_bo);
if (unlikely(ret != 0))
goto out_no_bo;
ret = ttm_bo_reserve(dev_priv->otable_bo, false, true, false, NULL);
BUG_ON(ret != 0);
ret = vmw_bo_driver.ttm_tt_populate(dev_priv->otable_bo->ttm);
if (unlikely(ret != 0))
goto out_unreserve;
ret = vmw_bo_map_dma(dev_priv->otable_bo);
if (unlikely(ret != 0))
goto out_unreserve;
ttm_bo_unreserve(dev_priv->otable_bo);
offset = 0;
for (i = 0; i < SVGA_OTABLE_DX9_MAX - VMW_OTABLE_SETUP_SUB; ++i) {
ret = vmw_setup_otable_base(dev_priv, i, offset,
&otables[i]);
if (unlikely(ret != 0))
goto out_no_setup;
offset += otables[i].size;
}
dev_priv->otables = otables;
return 0;
out_unreserve:
ttm_bo_unreserve(dev_priv->otable_bo);
out_no_setup:
for (i = 0; i < SVGA_OTABLE_DX9_MAX - VMW_OTABLE_SETUP_SUB; ++i)
vmw_takedown_otable_base(dev_priv, i, &otables[i]);
ttm_bo_unref(&dev_priv->otable_bo);
out_no_bo:
kfree(otables);
return ret;
}
void vmw_otables_takedown(struct vmw_private *dev_priv)
{
SVGAOTableType i;
struct ttm_buffer_object *bo = dev_priv->otable_bo;
int ret;
for (i = 0; i < SVGA_OTABLE_DX9_MAX - VMW_OTABLE_SETUP_SUB; ++i)
vmw_takedown_otable_base(dev_priv, i,
&dev_priv->otables[i]);
ret = ttm_bo_reserve(bo, false, true, false, NULL);
BUG_ON(ret != 0);
vmw_fence_single_bo(bo, NULL);
ttm_bo_unreserve(bo);
ttm_bo_unref(&dev_priv->otable_bo);
kfree(dev_priv->otables);
dev_priv->otables = NULL;
}
static unsigned long vmw_mob_calculate_pt_pages(unsigned long data_pages)
{
unsigned long data_size = data_pages * PAGE_SIZE;
unsigned long tot_size = 0;
while (likely(data_size > PAGE_SIZE)) {
data_size = DIV_ROUND_UP(data_size, PAGE_SIZE);
data_size *= VMW_PPN_SIZE;
tot_size += (data_size + PAGE_SIZE - 1) & PAGE_MASK;
}
return tot_size >> PAGE_SHIFT;
}
struct vmw_mob *vmw_mob_create(unsigned long data_pages)
{
struct vmw_mob *mob = kzalloc(sizeof(*mob), GFP_KERNEL);
if (unlikely(mob == NULL))
return NULL;
mob->num_pages = vmw_mob_calculate_pt_pages(data_pages);
return mob;
}
static int vmw_mob_pt_populate(struct vmw_private *dev_priv,
struct vmw_mob *mob)
{
int ret;
BUG_ON(mob->pt_bo != NULL);
ret = ttm_bo_create(&dev_priv->bdev, mob->num_pages * PAGE_SIZE,
ttm_bo_type_device,
&vmw_sys_ne_placement,
0, false, NULL, &mob->pt_bo);
if (unlikely(ret != 0))
return ret;
ret = ttm_bo_reserve(mob->pt_bo, false, true, false, NULL);
BUG_ON(ret != 0);
ret = vmw_bo_driver.ttm_tt_populate(mob->pt_bo->ttm);
if (unlikely(ret != 0))
goto out_unreserve;
ret = vmw_bo_map_dma(mob->pt_bo);
if (unlikely(ret != 0))
goto out_unreserve;
ttm_bo_unreserve(mob->pt_bo);
return 0;
out_unreserve:
ttm_bo_unreserve(mob->pt_bo);
ttm_bo_unref(&mob->pt_bo);
return ret;
}
static void vmw_mob_assign_ppn(__le32 **addr, dma_addr_t val)
{
*((__le64 *) *addr) = cpu_to_le64(val >> PAGE_SHIFT);
*addr += 2;
}
static void vmw_mob_assign_ppn(__le32 **addr, dma_addr_t val)
{
*(*addr)++ = cpu_to_le32(val >> PAGE_SHIFT);
}
static unsigned long vmw_mob_build_pt(struct vmw_piter *data_iter,
unsigned long num_data_pages,
struct vmw_piter *pt_iter)
{
unsigned long pt_size = num_data_pages * VMW_PPN_SIZE;
unsigned long num_pt_pages = DIV_ROUND_UP(pt_size, PAGE_SIZE);
unsigned long pt_page;
__le32 *addr, *save_addr;
unsigned long i;
struct page *page;
for (pt_page = 0; pt_page < num_pt_pages; ++pt_page) {
page = vmw_piter_page(pt_iter);
save_addr = addr = kmap_atomic(page);
for (i = 0; i < PAGE_SIZE / VMW_PPN_SIZE; ++i) {
vmw_mob_assign_ppn(&addr,
vmw_piter_dma_addr(data_iter));
if (unlikely(--num_data_pages == 0))
break;
WARN_ON(!vmw_piter_next(data_iter));
}
kunmap_atomic(save_addr);
vmw_piter_next(pt_iter);
}
return num_pt_pages;
}
static void vmw_mob_pt_setup(struct vmw_mob *mob,
struct vmw_piter data_iter,
unsigned long num_data_pages)
{
unsigned long num_pt_pages = 0;
struct ttm_buffer_object *bo = mob->pt_bo;
struct vmw_piter save_pt_iter;
struct vmw_piter pt_iter;
const struct vmw_sg_table *vsgt;
int ret;
ret = ttm_bo_reserve(bo, false, true, false, NULL);
BUG_ON(ret != 0);
vsgt = vmw_bo_sg_table(bo);
vmw_piter_start(&pt_iter, vsgt, 0);
BUG_ON(!vmw_piter_next(&pt_iter));
mob->pt_level = 0;
while (likely(num_data_pages > 1)) {
++mob->pt_level;
BUG_ON(mob->pt_level > 2);
save_pt_iter = pt_iter;
num_pt_pages = vmw_mob_build_pt(&data_iter, num_data_pages,
&pt_iter);
data_iter = save_pt_iter;
num_data_pages = num_pt_pages;
}
mob->pt_root_page = vmw_piter_dma_addr(&save_pt_iter);
ttm_bo_unreserve(bo);
}
void vmw_mob_destroy(struct vmw_mob *mob)
{
if (mob->pt_bo)
ttm_bo_unref(&mob->pt_bo);
kfree(mob);
}
void vmw_mob_unbind(struct vmw_private *dev_priv,
struct vmw_mob *mob)
{
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDestroyGBMob body;
} *cmd;
int ret;
struct ttm_buffer_object *bo = mob->pt_bo;
if (bo) {
ret = ttm_bo_reserve(bo, false, true, false, NULL);
BUG_ON(ret != 0);
}
cmd = vmw_fifo_reserve(dev_priv, sizeof(*cmd));
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for Memory "
"Object unbinding.\n");
} else {
cmd->header.id = SVGA_3D_CMD_DESTROY_GB_MOB;
cmd->header.size = sizeof(cmd->body);
cmd->body.mobid = mob->id;
vmw_fifo_commit(dev_priv, sizeof(*cmd));
}
if (bo) {
vmw_fence_single_bo(bo, NULL);
ttm_bo_unreserve(bo);
}
vmw_3d_resource_dec(dev_priv, false);
}
int vmw_mob_bind(struct vmw_private *dev_priv,
struct vmw_mob *mob,
const struct vmw_sg_table *vsgt,
unsigned long num_data_pages,
int32_t mob_id)
{
int ret;
bool pt_set_up = false;
struct vmw_piter data_iter;
struct {
SVGA3dCmdHeader header;
SVGA3dCmdDefineGBMob64 body;
} *cmd;
mob->id = mob_id;
vmw_piter_start(&data_iter, vsgt, 0);
if (unlikely(!vmw_piter_next(&data_iter)))
return 0;
if (likely(num_data_pages == 1)) {
mob->pt_level = VMW_MOBFMT_PTDEPTH_0;
mob->pt_root_page = vmw_piter_dma_addr(&data_iter);
} else if (vsgt->num_regions == 1) {
mob->pt_level = SVGA3D_MOBFMT_RANGE;
mob->pt_root_page = vmw_piter_dma_addr(&data_iter);
} else if (unlikely(mob->pt_bo == NULL)) {
ret = vmw_mob_pt_populate(dev_priv, mob);
if (unlikely(ret != 0))
return ret;
vmw_mob_pt_setup(mob, data_iter, num_data_pages);
pt_set_up = true;
mob->pt_level += VMW_MOBFMT_PTDEPTH_1 - SVGA3D_MOBFMT_PTDEPTH_1;
}
(void) vmw_3d_resource_inc(dev_priv, false);
cmd = vmw_fifo_reserve(dev_priv, sizeof(*cmd));
if (unlikely(cmd == NULL)) {
DRM_ERROR("Failed reserving FIFO space for Memory "
"Object binding.\n");
goto out_no_cmd_space;
}
cmd->header.id = SVGA_3D_CMD_DEFINE_GB_MOB64;
cmd->header.size = sizeof(cmd->body);
cmd->body.mobid = mob_id;
cmd->body.ptDepth = mob->pt_level;
cmd->body.base = cpu_to_le64(mob->pt_root_page >> PAGE_SHIFT);
cmd->body.sizeInBytes = num_data_pages * PAGE_SIZE;
vmw_fifo_commit(dev_priv, sizeof(*cmd));
return 0;
out_no_cmd_space:
vmw_3d_resource_dec(dev_priv, false);
if (pt_set_up)
ttm_bo_unref(&mob->pt_bo);
return -ENOMEM;
}
