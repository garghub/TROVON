static void i915_write_hws_pga(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
u32 addr;
addr = dev_priv->status_page_dmah->busaddr;
if (INTEL_INFO(dev)->gen >= 4)
addr |= (dev_priv->status_page_dmah->busaddr >> 28) & 0xf0;
I915_WRITE(HWS_PGA, addr);
}
static int i915_init_phys_hws(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct intel_ring_buffer *ring = LP_RING(dev_priv);
dev_priv->status_page_dmah =
drm_pci_alloc(dev, PAGE_SIZE, PAGE_SIZE);
if (!dev_priv->status_page_dmah) {
DRM_ERROR("Can not allocate hardware status page\n");
return -ENOMEM;
}
ring->status_page.page_addr =
(void __force __iomem *)dev_priv->status_page_dmah->vaddr;
memset_io(ring->status_page.page_addr, 0, PAGE_SIZE);
i915_write_hws_pga(dev);
DRM_DEBUG_DRIVER("Enabled hardware status page\n");
return 0;
}
static void i915_free_hws(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct intel_ring_buffer *ring = LP_RING(dev_priv);
if (dev_priv->status_page_dmah) {
drm_pci_free(dev, dev_priv->status_page_dmah);
dev_priv->status_page_dmah = NULL;
}
if (ring->status_page.gfx_addr) {
ring->status_page.gfx_addr = 0;
drm_core_ioremapfree(&dev_priv->hws_map, dev);
}
I915_WRITE(HWS_PGA, 0x1ffff000);
}
void i915_kernel_lost_context(struct drm_device * dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct drm_i915_master_private *master_priv;
struct intel_ring_buffer *ring = LP_RING(dev_priv);
if (drm_core_check_feature(dev, DRIVER_MODESET))
return;
ring->head = I915_READ_HEAD(ring) & HEAD_ADDR;
ring->tail = I915_READ_TAIL(ring) & TAIL_ADDR;
ring->space = ring->head - (ring->tail + 8);
if (ring->space < 0)
ring->space += ring->size;
if (!dev->primary->master)
return;
master_priv = dev->primary->master->driver_priv;
if (ring->head == ring->tail && master_priv->sarea_priv)
master_priv->sarea_priv->perf_boxes |= I915_BOX_RING_EMPTY;
}
static int i915_dma_cleanup(struct drm_device * dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
int i;
if (dev->irq_enabled)
drm_irq_uninstall(dev);
mutex_lock(&dev->struct_mutex);
for (i = 0; i < I915_NUM_RINGS; i++)
intel_cleanup_ring_buffer(&dev_priv->ring[i]);
mutex_unlock(&dev->struct_mutex);
if (I915_NEED_GFX_HWS(dev))
i915_free_hws(dev);
return 0;
}
static int i915_initialize(struct drm_device * dev, drm_i915_init_t * init)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct drm_i915_master_private *master_priv = dev->primary->master->driver_priv;
int ret;
master_priv->sarea = drm_getsarea(dev);
if (master_priv->sarea) {
master_priv->sarea_priv = (drm_i915_sarea_t *)
((u8 *)master_priv->sarea->handle + init->sarea_priv_offset);
} else {
DRM_DEBUG_DRIVER("sarea not found assuming DRI2 userspace\n");
}
if (init->ring_size != 0) {
if (LP_RING(dev_priv)->obj != NULL) {
i915_dma_cleanup(dev);
DRM_ERROR("Client tried to initialize ringbuffer in "
"GEM mode\n");
return -EINVAL;
}
ret = intel_render_ring_init_dri(dev,
init->ring_start,
init->ring_size);
if (ret) {
i915_dma_cleanup(dev);
return ret;
}
}
dev_priv->cpp = init->cpp;
dev_priv->back_offset = init->back_offset;
dev_priv->front_offset = init->front_offset;
dev_priv->current_page = 0;
if (master_priv->sarea_priv)
master_priv->sarea_priv->pf_current_page = 0;
dev_priv->allow_batchbuffer = 1;
return 0;
}
static int i915_dma_resume(struct drm_device * dev)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
struct intel_ring_buffer *ring = LP_RING(dev_priv);
DRM_DEBUG_DRIVER("%s\n", __func__);
if (ring->map.handle == NULL) {
DRM_ERROR("can not ioremap virtual address for"
" ring buffer\n");
return -ENOMEM;
}
if (!ring->status_page.page_addr) {
DRM_ERROR("Can not find hardware status page\n");
return -EINVAL;
}
DRM_DEBUG_DRIVER("hw status page @ %p\n",
ring->status_page.page_addr);
if (ring->status_page.gfx_addr != 0)
intel_ring_setup_status_page(ring);
else
i915_write_hws_pga(dev);
DRM_DEBUG_DRIVER("Enabled hardware status page\n");
return 0;
}
static int i915_dma_init(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
drm_i915_init_t *init = data;
int retcode = 0;
switch (init->func) {
case I915_INIT_DMA:
retcode = i915_initialize(dev, init);
break;
case I915_CLEANUP_DMA:
retcode = i915_dma_cleanup(dev);
break;
case I915_RESUME_DMA:
retcode = i915_dma_resume(dev);
break;
default:
retcode = -EINVAL;
break;
}
return retcode;
}
static int validate_cmd(int cmd)
{
switch (((cmd >> 29) & 0x7)) {
case 0x0:
switch ((cmd >> 23) & 0x3f) {
case 0x0:
return 1;
case 0x4:
return 1;
default:
return 0;
}
break;
case 0x1:
return 0;
case 0x2:
return (cmd & 0xff) + 2;
case 0x3:
if (((cmd >> 24) & 0x1f) <= 0x18)
return 1;
switch ((cmd >> 24) & 0x1f) {
case 0x1c:
return 1;
case 0x1d:
switch ((cmd >> 16) & 0xff) {
case 0x3:
return (cmd & 0x1f) + 2;
case 0x4:
return (cmd & 0xf) + 2;
default:
return (cmd & 0xffff) + 2;
}
case 0x1e:
if (cmd & (1 << 23))
return (cmd & 0xffff) + 1;
else
return 1;
case 0x1f:
if ((cmd & (1 << 23)) == 0)
return (cmd & 0x1ffff) + 2;
else if (cmd & (1 << 17))
if ((cmd & 0xffff) == 0)
return 0;
else
return (((cmd & 0xffff) + 1) / 2) + 1;
else
return 2;
default:
return 0;
}
default:
return 0;
}
return 0;
}
static int i915_emit_cmds(struct drm_device * dev, int *buffer, int dwords)
{
drm_i915_private_t *dev_priv = dev->dev_private;
int i, ret;
if ((dwords+1) * sizeof(int) >= LP_RING(dev_priv)->size - 8)
return -EINVAL;
for (i = 0; i < dwords;) {
int sz = validate_cmd(buffer[i]);
if (sz == 0 || i + sz > dwords)
return -EINVAL;
i += sz;
}
ret = BEGIN_LP_RING((dwords+1)&~1);
if (ret)
return ret;
for (i = 0; i < dwords; i++)
OUT_RING(buffer[i]);
if (dwords & 1)
OUT_RING(0);
ADVANCE_LP_RING();
return 0;
}
int
i915_emit_box(struct drm_device *dev,
struct drm_clip_rect *box,
int DR1, int DR4)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
if (box->y2 <= box->y1 || box->x2 <= box->x1 ||
box->y2 <= 0 || box->x2 <= 0) {
DRM_ERROR("Bad box %d,%d..%d,%d\n",
box->x1, box->y1, box->x2, box->y2);
return -EINVAL;
}
if (INTEL_INFO(dev)->gen >= 4) {
ret = BEGIN_LP_RING(4);
if (ret)
return ret;
OUT_RING(GFX_OP_DRAWRECT_INFO_I965);
OUT_RING((box->x1 & 0xffff) | (box->y1 << 16));
OUT_RING(((box->x2 - 1) & 0xffff) | ((box->y2 - 1) << 16));
OUT_RING(DR4);
} else {
ret = BEGIN_LP_RING(6);
if (ret)
return ret;
OUT_RING(GFX_OP_DRAWRECT_INFO);
OUT_RING(DR1);
OUT_RING((box->x1 & 0xffff) | (box->y1 << 16));
OUT_RING(((box->x2 - 1) & 0xffff) | ((box->y2 - 1) << 16));
OUT_RING(DR4);
OUT_RING(0);
}
ADVANCE_LP_RING();
return 0;
}
static void i915_emit_breadcrumb(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct drm_i915_master_private *master_priv = dev->primary->master->driver_priv;
dev_priv->counter++;
if (dev_priv->counter > 0x7FFFFFFFUL)
dev_priv->counter = 0;
if (master_priv->sarea_priv)
master_priv->sarea_priv->last_enqueue = dev_priv->counter;
if (BEGIN_LP_RING(4) == 0) {
OUT_RING(MI_STORE_DWORD_INDEX);
OUT_RING(I915_BREADCRUMB_INDEX << MI_STORE_DWORD_INDEX_SHIFT);
OUT_RING(dev_priv->counter);
OUT_RING(0);
ADVANCE_LP_RING();
}
}
static int i915_dispatch_cmdbuffer(struct drm_device * dev,
drm_i915_cmdbuffer_t *cmd,
struct drm_clip_rect *cliprects,
void *cmdbuf)
{
int nbox = cmd->num_cliprects;
int i = 0, count, ret;
if (cmd->sz & 0x3) {
DRM_ERROR("alignment");
return -EINVAL;
}
i915_kernel_lost_context(dev);
count = nbox ? nbox : 1;
for (i = 0; i < count; i++) {
if (i < nbox) {
ret = i915_emit_box(dev, &cliprects[i],
cmd->DR1, cmd->DR4);
if (ret)
return ret;
}
ret = i915_emit_cmds(dev, cmdbuf, cmd->sz / 4);
if (ret)
return ret;
}
i915_emit_breadcrumb(dev);
return 0;
}
static int i915_dispatch_batchbuffer(struct drm_device * dev,
drm_i915_batchbuffer_t * batch,
struct drm_clip_rect *cliprects)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int nbox = batch->num_cliprects;
int i, count, ret;
if ((batch->start | batch->used) & 0x7) {
DRM_ERROR("alignment");
return -EINVAL;
}
i915_kernel_lost_context(dev);
count = nbox ? nbox : 1;
for (i = 0; i < count; i++) {
if (i < nbox) {
ret = i915_emit_box(dev, &cliprects[i],
batch->DR1, batch->DR4);
if (ret)
return ret;
}
if (!IS_I830(dev) && !IS_845G(dev)) {
ret = BEGIN_LP_RING(2);
if (ret)
return ret;
if (INTEL_INFO(dev)->gen >= 4) {
OUT_RING(MI_BATCH_BUFFER_START | (2 << 6) | MI_BATCH_NON_SECURE_I965);
OUT_RING(batch->start);
} else {
OUT_RING(MI_BATCH_BUFFER_START | (2 << 6));
OUT_RING(batch->start | MI_BATCH_NON_SECURE);
}
} else {
ret = BEGIN_LP_RING(4);
if (ret)
return ret;
OUT_RING(MI_BATCH_BUFFER);
OUT_RING(batch->start | MI_BATCH_NON_SECURE);
OUT_RING(batch->start + batch->used - 4);
OUT_RING(0);
}
ADVANCE_LP_RING();
}
if (IS_G4X(dev) || IS_GEN5(dev)) {
if (BEGIN_LP_RING(2) == 0) {
OUT_RING(MI_FLUSH | MI_NO_WRITE_FLUSH | MI_INVALIDATE_ISP);
OUT_RING(MI_NOOP);
ADVANCE_LP_RING();
}
}
i915_emit_breadcrumb(dev);
return 0;
}
static int i915_dispatch_flip(struct drm_device * dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct drm_i915_master_private *master_priv =
dev->primary->master->driver_priv;
int ret;
if (!master_priv->sarea_priv)
return -EINVAL;
DRM_DEBUG_DRIVER("%s: page=%d pfCurrentPage=%d\n",
__func__,
dev_priv->current_page,
master_priv->sarea_priv->pf_current_page);
i915_kernel_lost_context(dev);
ret = BEGIN_LP_RING(10);
if (ret)
return ret;
OUT_RING(MI_FLUSH | MI_READ_FLUSH);
OUT_RING(0);
OUT_RING(CMD_OP_DISPLAYBUFFER_INFO | ASYNC_FLIP);
OUT_RING(0);
if (dev_priv->current_page == 0) {
OUT_RING(dev_priv->back_offset);
dev_priv->current_page = 1;
} else {
OUT_RING(dev_priv->front_offset);
dev_priv->current_page = 0;
}
OUT_RING(0);
OUT_RING(MI_WAIT_FOR_EVENT | MI_WAIT_FOR_PLANE_A_FLIP);
OUT_RING(0);
ADVANCE_LP_RING();
master_priv->sarea_priv->last_enqueue = dev_priv->counter++;
if (BEGIN_LP_RING(4) == 0) {
OUT_RING(MI_STORE_DWORD_INDEX);
OUT_RING(I915_BREADCRUMB_INDEX << MI_STORE_DWORD_INDEX_SHIFT);
OUT_RING(dev_priv->counter);
OUT_RING(0);
ADVANCE_LP_RING();
}
master_priv->sarea_priv->pf_current_page = dev_priv->current_page;
return 0;
}
static int i915_quiescent(struct drm_device *dev)
{
struct intel_ring_buffer *ring = LP_RING(dev->dev_private);
i915_kernel_lost_context(dev);
return intel_wait_ring_idle(ring);
}
static int i915_flush_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
int ret;
RING_LOCK_TEST_WITH_RETURN(dev, file_priv);
mutex_lock(&dev->struct_mutex);
ret = i915_quiescent(dev);
mutex_unlock(&dev->struct_mutex);
return ret;
}
static int i915_batchbuffer(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
struct drm_i915_master_private *master_priv = dev->primary->master->driver_priv;
drm_i915_sarea_t *sarea_priv = (drm_i915_sarea_t *)
master_priv->sarea_priv;
drm_i915_batchbuffer_t *batch = data;
int ret;
struct drm_clip_rect *cliprects = NULL;
if (!dev_priv->allow_batchbuffer) {
DRM_ERROR("Batchbuffer ioctl disabled\n");
return -EINVAL;
}
DRM_DEBUG_DRIVER("i915 batchbuffer, start %x used %d cliprects %d\n",
batch->start, batch->used, batch->num_cliprects);
RING_LOCK_TEST_WITH_RETURN(dev, file_priv);
if (batch->num_cliprects < 0)
return -EINVAL;
if (batch->num_cliprects) {
cliprects = kcalloc(batch->num_cliprects,
sizeof(struct drm_clip_rect),
GFP_KERNEL);
if (cliprects == NULL)
return -ENOMEM;
ret = copy_from_user(cliprects, batch->cliprects,
batch->num_cliprects *
sizeof(struct drm_clip_rect));
if (ret != 0) {
ret = -EFAULT;
goto fail_free;
}
}
mutex_lock(&dev->struct_mutex);
ret = i915_dispatch_batchbuffer(dev, batch, cliprects);
mutex_unlock(&dev->struct_mutex);
if (sarea_priv)
sarea_priv->last_dispatch = READ_BREADCRUMB(dev_priv);
fail_free:
kfree(cliprects);
return ret;
}
static int i915_cmdbuffer(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
struct drm_i915_master_private *master_priv = dev->primary->master->driver_priv;
drm_i915_sarea_t *sarea_priv = (drm_i915_sarea_t *)
master_priv->sarea_priv;
drm_i915_cmdbuffer_t *cmdbuf = data;
struct drm_clip_rect *cliprects = NULL;
void *batch_data;
int ret;
DRM_DEBUG_DRIVER("i915 cmdbuffer, buf %p sz %d cliprects %d\n",
cmdbuf->buf, cmdbuf->sz, cmdbuf->num_cliprects);
RING_LOCK_TEST_WITH_RETURN(dev, file_priv);
if (cmdbuf->num_cliprects < 0)
return -EINVAL;
batch_data = kmalloc(cmdbuf->sz, GFP_KERNEL);
if (batch_data == NULL)
return -ENOMEM;
ret = copy_from_user(batch_data, cmdbuf->buf, cmdbuf->sz);
if (ret != 0) {
ret = -EFAULT;
goto fail_batch_free;
}
if (cmdbuf->num_cliprects) {
cliprects = kcalloc(cmdbuf->num_cliprects,
sizeof(struct drm_clip_rect), GFP_KERNEL);
if (cliprects == NULL) {
ret = -ENOMEM;
goto fail_batch_free;
}
ret = copy_from_user(cliprects, cmdbuf->cliprects,
cmdbuf->num_cliprects *
sizeof(struct drm_clip_rect));
if (ret != 0) {
ret = -EFAULT;
goto fail_clip_free;
}
}
mutex_lock(&dev->struct_mutex);
ret = i915_dispatch_cmdbuffer(dev, cmdbuf, cliprects, batch_data);
mutex_unlock(&dev->struct_mutex);
if (ret) {
DRM_ERROR("i915_dispatch_cmdbuffer failed\n");
goto fail_clip_free;
}
if (sarea_priv)
sarea_priv->last_dispatch = READ_BREADCRUMB(dev_priv);
fail_clip_free:
kfree(cliprects);
fail_batch_free:
kfree(batch_data);
return ret;
}
static int i915_flip_bufs(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
int ret;
DRM_DEBUG_DRIVER("%s\n", __func__);
RING_LOCK_TEST_WITH_RETURN(dev, file_priv);
mutex_lock(&dev->struct_mutex);
ret = i915_dispatch_flip(dev);
mutex_unlock(&dev->struct_mutex);
return ret;
}
static int i915_getparam(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
drm_i915_private_t *dev_priv = dev->dev_private;
drm_i915_getparam_t *param = data;
int value;
if (!dev_priv) {
DRM_ERROR("called with no initialization\n");
return -EINVAL;
}
switch (param->param) {
case I915_PARAM_IRQ_ACTIVE:
value = dev->pdev->irq ? 1 : 0;
break;
case I915_PARAM_ALLOW_BATCHBUFFER:
value = dev_priv->allow_batchbuffer ? 1 : 0;
break;
case I915_PARAM_LAST_DISPATCH:
value = READ_BREADCRUMB(dev_priv);
break;
case I915_PARAM_CHIPSET_ID:
value = dev->pci_device;
break;
case I915_PARAM_HAS_GEM:
value = dev_priv->has_gem;
break;
case I915_PARAM_NUM_FENCES_AVAIL:
value = dev_priv->num_fence_regs - dev_priv->fence_reg_start;
break;
case I915_PARAM_HAS_OVERLAY:
value = dev_priv->overlay ? 1 : 0;
break;
case I915_PARAM_HAS_PAGEFLIPPING:
value = 1;
break;
case I915_PARAM_HAS_EXECBUF2:
value = dev_priv->has_gem;
break;
case I915_PARAM_HAS_BSD:
value = HAS_BSD(dev);
break;
case I915_PARAM_HAS_BLT:
value = HAS_BLT(dev);
break;
case I915_PARAM_HAS_RELAXED_FENCING:
value = 1;
break;
case I915_PARAM_HAS_COHERENT_RINGS:
value = 1;
break;
case I915_PARAM_HAS_EXEC_CONSTANTS:
value = INTEL_INFO(dev)->gen >= 4;
break;
case I915_PARAM_HAS_RELAXED_DELTA:
value = 1;
break;
default:
DRM_DEBUG_DRIVER("Unknown parameter %d\n",
param->param);
return -EINVAL;
}
if (DRM_COPY_TO_USER(param->value, &value, sizeof(int))) {
DRM_ERROR("DRM_COPY_TO_USER failed\n");
return -EFAULT;
}
return 0;
}
static int i915_setparam(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
drm_i915_private_t *dev_priv = dev->dev_private;
drm_i915_setparam_t *param = data;
if (!dev_priv) {
DRM_ERROR("called with no initialization\n");
return -EINVAL;
}
switch (param->param) {
case I915_SETPARAM_USE_MI_BATCHBUFFER_START:
break;
case I915_SETPARAM_TEX_LRU_LOG_GRANULARITY:
dev_priv->tex_lru_log_granularity = param->value;
break;
case I915_SETPARAM_ALLOW_BATCHBUFFER:
dev_priv->allow_batchbuffer = param->value;
break;
case I915_SETPARAM_NUM_USED_FENCES:
if (param->value > dev_priv->num_fence_regs ||
param->value < 0)
return -EINVAL;
dev_priv->fence_reg_start = param->value;
break;
default:
DRM_DEBUG_DRIVER("unknown parameter %d\n",
param->param);
return -EINVAL;
}
return 0;
}
static int i915_set_status_page(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
drm_i915_private_t *dev_priv = dev->dev_private;
drm_i915_hws_addr_t *hws = data;
struct intel_ring_buffer *ring = LP_RING(dev_priv);
if (!I915_NEED_GFX_HWS(dev))
return -EINVAL;
if (!dev_priv) {
DRM_ERROR("called with no initialization\n");
return -EINVAL;
}
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
WARN(1, "tried to set status page when mode setting active\n");
return 0;
}
DRM_DEBUG_DRIVER("set status page addr 0x%08x\n", (u32)hws->addr);
ring->status_page.gfx_addr = hws->addr & (0x1ffff<<12);
dev_priv->hws_map.offset = dev->agp->base + hws->addr;
dev_priv->hws_map.size = 4*1024;
dev_priv->hws_map.type = 0;
dev_priv->hws_map.flags = 0;
dev_priv->hws_map.mtrr = 0;
drm_core_ioremap_wc(&dev_priv->hws_map, dev);
if (dev_priv->hws_map.handle == NULL) {
i915_dma_cleanup(dev);
ring->status_page.gfx_addr = 0;
DRM_ERROR("can not ioremap virtual address for"
" G33 hw status page\n");
return -ENOMEM;
}
ring->status_page.page_addr =
(void __force __iomem *)dev_priv->hws_map.handle;
memset_io(ring->status_page.page_addr, 0, PAGE_SIZE);
I915_WRITE(HWS_PGA, ring->status_page.gfx_addr);
DRM_DEBUG_DRIVER("load hws HWS_PGA with gfx mem 0x%x\n",
ring->status_page.gfx_addr);
DRM_DEBUG_DRIVER("load hws at %p\n",
ring->status_page.page_addr);
return 0;
}
static int i915_get_bridge_dev(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
dev_priv->bridge_dev = pci_get_bus_and_slot(0, PCI_DEVFN(0,0));
if (!dev_priv->bridge_dev) {
DRM_ERROR("bridge device not found\n");
return -1;
}
return 0;
}
static int
intel_alloc_mchbar_resource(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
int reg = INTEL_INFO(dev)->gen >= 4 ? MCHBAR_I965 : MCHBAR_I915;
u32 temp_lo, temp_hi = 0;
u64 mchbar_addr;
int ret;
if (INTEL_INFO(dev)->gen >= 4)
pci_read_config_dword(dev_priv->bridge_dev, reg + 4, &temp_hi);
pci_read_config_dword(dev_priv->bridge_dev, reg, &temp_lo);
mchbar_addr = ((u64)temp_hi << 32) | temp_lo;
#ifdef CONFIG_PNP
if (mchbar_addr &&
pnp_range_reserved(mchbar_addr, mchbar_addr + MCHBAR_SIZE))
return 0;
#endif
dev_priv->mch_res.name = "i915 MCHBAR";
dev_priv->mch_res.flags = IORESOURCE_MEM;
ret = pci_bus_alloc_resource(dev_priv->bridge_dev->bus,
&dev_priv->mch_res,
MCHBAR_SIZE, MCHBAR_SIZE,
PCIBIOS_MIN_MEM,
0, pcibios_align_resource,
dev_priv->bridge_dev);
if (ret) {
DRM_DEBUG_DRIVER("failed bus alloc: %d\n", ret);
dev_priv->mch_res.start = 0;
return ret;
}
if (INTEL_INFO(dev)->gen >= 4)
pci_write_config_dword(dev_priv->bridge_dev, reg + 4,
upper_32_bits(dev_priv->mch_res.start));
pci_write_config_dword(dev_priv->bridge_dev, reg,
lower_32_bits(dev_priv->mch_res.start));
return 0;
}
static void
intel_setup_mchbar(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
int mchbar_reg = INTEL_INFO(dev)->gen >= 4 ? MCHBAR_I965 : MCHBAR_I915;
u32 temp;
bool enabled;
dev_priv->mchbar_need_disable = false;
if (IS_I915G(dev) || IS_I915GM(dev)) {
pci_read_config_dword(dev_priv->bridge_dev, DEVEN_REG, &temp);
enabled = !!(temp & DEVEN_MCHBAR_EN);
} else {
pci_read_config_dword(dev_priv->bridge_dev, mchbar_reg, &temp);
enabled = temp & 1;
}
if (enabled)
return;
if (intel_alloc_mchbar_resource(dev))
return;
dev_priv->mchbar_need_disable = true;
if (IS_I915G(dev) || IS_I915GM(dev)) {
pci_write_config_dword(dev_priv->bridge_dev, DEVEN_REG,
temp | DEVEN_MCHBAR_EN);
} else {
pci_read_config_dword(dev_priv->bridge_dev, mchbar_reg, &temp);
pci_write_config_dword(dev_priv->bridge_dev, mchbar_reg, temp | 1);
}
}
static void
intel_teardown_mchbar(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
int mchbar_reg = INTEL_INFO(dev)->gen >= 4 ? MCHBAR_I965 : MCHBAR_I915;
u32 temp;
if (dev_priv->mchbar_need_disable) {
if (IS_I915G(dev) || IS_I915GM(dev)) {
pci_read_config_dword(dev_priv->bridge_dev, DEVEN_REG, &temp);
temp &= ~DEVEN_MCHBAR_EN;
pci_write_config_dword(dev_priv->bridge_dev, DEVEN_REG, temp);
} else {
pci_read_config_dword(dev_priv->bridge_dev, mchbar_reg, &temp);
temp &= ~1;
pci_write_config_dword(dev_priv->bridge_dev, mchbar_reg, temp);
}
}
if (dev_priv->mch_res.start)
release_resource(&dev_priv->mch_res);
}
static unsigned long i915_stolen_to_phys(struct drm_device *dev, u32 offset)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct pci_dev *pdev = dev_priv->bridge_dev;
u32 base;
#if 0
if (INTEL_INFO(dev)->gen > 3 || IS_G33(dev)) {
pci_read_config_dword(pdev, 0xA4, &base);
} else {
pci_bus_read_config_dword(pdev->bus, 2, 0x5C, &base);
}
#else
if (INTEL_INFO(dev)->gen > 3 || IS_G33(dev)) {
u16 val;
pci_read_config_word(pdev, 0xb0, &val);
base = val >> 4 << 20;
} else {
u8 val;
pci_read_config_byte(pdev, 0x9c, &val);
base = val >> 3 << 27;
}
base -= dev_priv->mm.gtt->stolen_size;
#endif
return base + offset;
}
static void i915_warn_stolen(struct drm_device *dev)
{
DRM_ERROR("not enough stolen space for compressed buffer, disabling\n");
DRM_ERROR("hint: you may be able to increase stolen memory size in the BIOS to avoid this\n");
}
static void i915_setup_compression(struct drm_device *dev, int size)
{
struct drm_i915_private *dev_priv = dev->dev_private;
struct drm_mm_node *compressed_fb, *uninitialized_var(compressed_llb);
unsigned long cfb_base;
unsigned long ll_base = 0;
compressed_fb = drm_mm_search_free(&dev_priv->mm.stolen, size, 4096, 0);
if (compressed_fb)
compressed_fb = drm_mm_get_block(compressed_fb, size, 4096);
if (!compressed_fb)
goto err;
cfb_base = i915_stolen_to_phys(dev, compressed_fb->start);
if (!cfb_base)
goto err_fb;
if (!(IS_GM45(dev) || HAS_PCH_SPLIT(dev))) {
compressed_llb = drm_mm_search_free(&dev_priv->mm.stolen,
4096, 4096, 0);
if (compressed_llb)
compressed_llb = drm_mm_get_block(compressed_llb,
4096, 4096);
if (!compressed_llb)
goto err_fb;
ll_base = i915_stolen_to_phys(dev, compressed_llb->start);
if (!ll_base)
goto err_llb;
}
dev_priv->cfb_size = size;
intel_disable_fbc(dev);
dev_priv->compressed_fb = compressed_fb;
if (HAS_PCH_SPLIT(dev))
I915_WRITE(ILK_DPFC_CB_BASE, compressed_fb->start);
else if (IS_GM45(dev)) {
I915_WRITE(DPFC_CB_BASE, compressed_fb->start);
} else {
I915_WRITE(FBC_CFB_BASE, cfb_base);
I915_WRITE(FBC_LL_BASE, ll_base);
dev_priv->compressed_llb = compressed_llb;
}
DRM_DEBUG_KMS("FBC base 0x%08lx, ll base 0x%08lx, size %dM\n",
cfb_base, ll_base, size >> 20);
return;
err_llb:
drm_mm_put_block(compressed_llb);
err_fb:
drm_mm_put_block(compressed_fb);
err:
dev_priv->no_fbc_reason = FBC_STOLEN_TOO_SMALL;
i915_warn_stolen(dev);
}
static void i915_cleanup_compression(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
drm_mm_put_block(dev_priv->compressed_fb);
if (dev_priv->compressed_llb)
drm_mm_put_block(dev_priv->compressed_llb);
}
static unsigned int i915_vga_set_decode(void *cookie, bool state)
{
struct drm_device *dev = cookie;
intel_modeset_vga_set_state(dev, state);
if (state)
return VGA_RSRC_LEGACY_IO | VGA_RSRC_LEGACY_MEM |
VGA_RSRC_NORMAL_IO | VGA_RSRC_NORMAL_MEM;
else
return VGA_RSRC_NORMAL_IO | VGA_RSRC_NORMAL_MEM;
}
static void i915_switcheroo_set_state(struct pci_dev *pdev, enum vga_switcheroo_state state)
{
struct drm_device *dev = pci_get_drvdata(pdev);
pm_message_t pmm = { .event = PM_EVENT_SUSPEND };
if (state == VGA_SWITCHEROO_ON) {
printk(KERN_INFO "i915: switched on\n");
dev->switch_power_state = DRM_SWITCH_POWER_CHANGING;
pci_set_power_state(dev->pdev, PCI_D0);
i915_resume(dev);
dev->switch_power_state = DRM_SWITCH_POWER_ON;
} else {
printk(KERN_ERR "i915: switched off\n");
dev->switch_power_state = DRM_SWITCH_POWER_CHANGING;
i915_suspend(dev, pmm);
dev->switch_power_state = DRM_SWITCH_POWER_OFF;
}
}
static bool i915_switcheroo_can_switch(struct pci_dev *pdev)
{
struct drm_device *dev = pci_get_drvdata(pdev);
bool can_switch;
spin_lock(&dev->count_lock);
can_switch = (dev->open_count == 0);
spin_unlock(&dev->count_lock);
return can_switch;
}
static int i915_load_gem_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
unsigned long prealloc_size, gtt_size, mappable_size;
int ret;
prealloc_size = dev_priv->mm.gtt->stolen_size;
gtt_size = dev_priv->mm.gtt->gtt_total_entries << PAGE_SHIFT;
mappable_size = dev_priv->mm.gtt->gtt_mappable_entries << PAGE_SHIFT;
drm_mm_init(&dev_priv->mm.stolen, 0, prealloc_size);
i915_gem_do_init(dev, 0, mappable_size, gtt_size - PAGE_SIZE);
mutex_lock(&dev->struct_mutex);
ret = i915_gem_init_ringbuffer(dev);
mutex_unlock(&dev->struct_mutex);
if (ret)
return ret;
if (I915_HAS_FBC(dev) && i915_powersave) {
int cfb_size;
if (prealloc_size > (36*1024*1024))
cfb_size = 32*1024*1024;
else
cfb_size = prealloc_size * 7 / 8;
i915_setup_compression(dev, cfb_size);
}
dev_priv->allow_batchbuffer = 1;
return 0;
}
static int i915_load_modeset_init(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
ret = intel_parse_bios(dev);
if (ret)
DRM_INFO("failed to find VBIOS tables\n");
ret = vga_client_register(dev->pdev, dev, NULL, i915_vga_set_decode);
if (ret && ret != -ENODEV)
goto out;
intel_register_dsm_handler();
ret = vga_switcheroo_register_client(dev->pdev,
i915_switcheroo_set_state,
NULL,
i915_switcheroo_can_switch);
if (ret)
goto cleanup_vga_client;
if (IS_GEN3(dev) && (I915_READ(ECOSKPD) & ECO_FLIP_DONE))
dev_priv->flip_pending_is_done = true;
intel_modeset_init(dev);
ret = i915_load_gem_init(dev);
if (ret)
goto cleanup_vga_switcheroo;
intel_modeset_gem_init(dev);
ret = drm_irq_install(dev);
if (ret)
goto cleanup_gem;
dev->vblank_disable_allowed = 1;
ret = intel_fbdev_init(dev);
if (ret)
goto cleanup_irq;
drm_kms_helper_poll_init(dev);
dev_priv->mm.suspended = 0;
return 0;
cleanup_irq:
drm_irq_uninstall(dev);
cleanup_gem:
mutex_lock(&dev->struct_mutex);
i915_gem_cleanup_ringbuffer(dev);
mutex_unlock(&dev->struct_mutex);
cleanup_vga_switcheroo:
vga_switcheroo_unregister_client(dev->pdev);
cleanup_vga_client:
vga_client_register(dev->pdev, NULL, NULL, NULL);
out:
return ret;
}
int i915_master_create(struct drm_device *dev, struct drm_master *master)
{
struct drm_i915_master_private *master_priv;
master_priv = kzalloc(sizeof(*master_priv), GFP_KERNEL);
if (!master_priv)
return -ENOMEM;
master->driver_priv = master_priv;
return 0;
}
void i915_master_destroy(struct drm_device *dev, struct drm_master *master)
{
struct drm_i915_master_private *master_priv = master->driver_priv;
if (!master_priv)
return;
kfree(master_priv);
master->driver_priv = NULL;
}
static void i915_pineview_get_mem_freq(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
u32 tmp;
tmp = I915_READ(CLKCFG);
switch (tmp & CLKCFG_FSB_MASK) {
case CLKCFG_FSB_533:
dev_priv->fsb_freq = 533;
break;
case CLKCFG_FSB_800:
dev_priv->fsb_freq = 800;
break;
case CLKCFG_FSB_667:
dev_priv->fsb_freq = 667;
break;
case CLKCFG_FSB_400:
dev_priv->fsb_freq = 400;
break;
}
switch (tmp & CLKCFG_MEM_MASK) {
case CLKCFG_MEM_533:
dev_priv->mem_freq = 533;
break;
case CLKCFG_MEM_667:
dev_priv->mem_freq = 667;
break;
case CLKCFG_MEM_800:
dev_priv->mem_freq = 800;
break;
}
tmp = I915_READ(CSHRDDR3CTL);
dev_priv->is_ddr3 = (tmp & CSHRDDR3CTL_DDR3) ? 1 : 0;
}
static void i915_ironlake_get_mem_freq(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
u16 ddrpll, csipll;
ddrpll = I915_READ16(DDRMPLL1);
csipll = I915_READ16(CSIPLL0);
switch (ddrpll & 0xff) {
case 0xc:
dev_priv->mem_freq = 800;
break;
case 0x10:
dev_priv->mem_freq = 1066;
break;
case 0x14:
dev_priv->mem_freq = 1333;
break;
case 0x18:
dev_priv->mem_freq = 1600;
break;
default:
DRM_DEBUG_DRIVER("unknown memory frequency 0x%02x\n",
ddrpll & 0xff);
dev_priv->mem_freq = 0;
break;
}
dev_priv->r_t = dev_priv->mem_freq;
switch (csipll & 0x3ff) {
case 0x00c:
dev_priv->fsb_freq = 3200;
break;
case 0x00e:
dev_priv->fsb_freq = 3733;
break;
case 0x010:
dev_priv->fsb_freq = 4266;
break;
case 0x012:
dev_priv->fsb_freq = 4800;
break;
case 0x014:
dev_priv->fsb_freq = 5333;
break;
case 0x016:
dev_priv->fsb_freq = 5866;
break;
case 0x018:
dev_priv->fsb_freq = 6400;
break;
default:
DRM_DEBUG_DRIVER("unknown fsb frequency 0x%04x\n",
csipll & 0x3ff);
dev_priv->fsb_freq = 0;
break;
}
if (dev_priv->fsb_freq == 3200) {
dev_priv->c_m = 0;
} else if (dev_priv->fsb_freq > 3200 && dev_priv->fsb_freq <= 4800) {
dev_priv->c_m = 1;
} else {
dev_priv->c_m = 2;
}
}
unsigned long i915_chipset_val(struct drm_i915_private *dev_priv)
{
u64 total_count, diff, ret;
u32 count1, count2, count3, m = 0, c = 0;
unsigned long now = jiffies_to_msecs(jiffies), diff1;
int i;
diff1 = now - dev_priv->last_time1;
count1 = I915_READ(DMIEC);
count2 = I915_READ(DDREC);
count3 = I915_READ(CSIEC);
total_count = count1 + count2 + count3;
if (total_count < dev_priv->last_count1) {
diff = ~0UL - dev_priv->last_count1;
diff += total_count;
} else {
diff = total_count - dev_priv->last_count1;
}
for (i = 0; i < ARRAY_SIZE(cparams); i++) {
if (cparams[i].i == dev_priv->c_m &&
cparams[i].t == dev_priv->r_t) {
m = cparams[i].m;
c = cparams[i].c;
break;
}
}
diff = div_u64(diff, diff1);
ret = ((m * diff) + c);
ret = div_u64(ret, 10);
dev_priv->last_count1 = total_count;
dev_priv->last_time1 = now;
return ret;
}
unsigned long i915_mch_val(struct drm_i915_private *dev_priv)
{
unsigned long m, x, b;
u32 tsfs;
tsfs = I915_READ(TSFS);
m = ((tsfs & TSFS_SLOPE_MASK) >> TSFS_SLOPE_SHIFT);
x = I915_READ8(TR1);
b = tsfs & TSFS_INTR_MASK;
return ((m * x) / 127) - b;
}
static u16 pvid_to_extvid(struct drm_i915_private *dev_priv, u8 pxvid)
{
static const struct v_table {
u16 vd;
u16 vm;
} v_table[] = {
{ 0, 0, },
{ 375, 0, },
{ 500, 0, },
{ 625, 0, },
{ 750, 0, },
{ 875, 0, },
{ 1000, 0, },
{ 1125, 0, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4125, 3000, },
{ 4250, 3125, },
{ 4375, 3250, },
{ 4500, 3375, },
{ 4625, 3500, },
{ 4750, 3625, },
{ 4875, 3750, },
{ 5000, 3875, },
{ 5125, 4000, },
{ 5250, 4125, },
{ 5375, 4250, },
{ 5500, 4375, },
{ 5625, 4500, },
{ 5750, 4625, },
{ 5875, 4750, },
{ 6000, 4875, },
{ 6125, 5000, },
{ 6250, 5125, },
{ 6375, 5250, },
{ 6500, 5375, },
{ 6625, 5500, },
{ 6750, 5625, },
{ 6875, 5750, },
{ 7000, 5875, },
{ 7125, 6000, },
{ 7250, 6125, },
{ 7375, 6250, },
{ 7500, 6375, },
{ 7625, 6500, },
{ 7750, 6625, },
{ 7875, 6750, },
{ 8000, 6875, },
{ 8125, 7000, },
{ 8250, 7125, },
{ 8375, 7250, },
{ 8500, 7375, },
{ 8625, 7500, },
{ 8750, 7625, },
{ 8875, 7750, },
{ 9000, 7875, },
{ 9125, 8000, },
{ 9250, 8125, },
{ 9375, 8250, },
{ 9500, 8375, },
{ 9625, 8500, },
{ 9750, 8625, },
{ 9875, 8750, },
{ 10000, 8875, },
{ 10125, 9000, },
{ 10250, 9125, },
{ 10375, 9250, },
{ 10500, 9375, },
{ 10625, 9500, },
{ 10750, 9625, },
{ 10875, 9750, },
{ 11000, 9875, },
{ 11125, 10000, },
{ 11250, 10125, },
{ 11375, 10250, },
{ 11500, 10375, },
{ 11625, 10500, },
{ 11750, 10625, },
{ 11875, 10750, },
{ 12000, 10875, },
{ 12125, 11000, },
{ 12250, 11125, },
{ 12375, 11250, },
{ 12500, 11375, },
{ 12625, 11500, },
{ 12750, 11625, },
{ 12875, 11750, },
{ 13000, 11875, },
{ 13125, 12000, },
{ 13250, 12125, },
{ 13375, 12250, },
{ 13500, 12375, },
{ 13625, 12500, },
{ 13750, 12625, },
{ 13875, 12750, },
{ 14000, 12875, },
{ 14125, 13000, },
{ 14250, 13125, },
{ 14375, 13250, },
{ 14500, 13375, },
{ 14625, 13500, },
{ 14750, 13625, },
{ 14875, 13750, },
{ 15000, 13875, },
{ 15125, 14000, },
{ 15250, 14125, },
{ 15375, 14250, },
{ 15500, 14375, },
{ 15625, 14500, },
{ 15750, 14625, },
{ 15875, 14750, },
{ 16000, 14875, },
{ 16125, 15000, },
};
if (dev_priv->info->is_mobile)
return v_table[pxvid].vm;
else
return v_table[pxvid].vd;
}
void i915_update_gfx_val(struct drm_i915_private *dev_priv)
{
struct timespec now, diff1;
u64 diff;
unsigned long diffms;
u32 count;
getrawmonotonic(&now);
diff1 = timespec_sub(now, dev_priv->last_time2);
diffms = diff1.tv_sec * 1000 + diff1.tv_nsec / 1000000;
if (!diffms)
return;
count = I915_READ(GFXEC);
if (count < dev_priv->last_count2) {
diff = ~0UL - dev_priv->last_count2;
diff += count;
} else {
diff = count - dev_priv->last_count2;
}
dev_priv->last_count2 = count;
dev_priv->last_time2 = now;
diff = diff * 1181;
diff = div_u64(diff, diffms * 10);
dev_priv->gfx_power = diff;
}
unsigned long i915_gfx_val(struct drm_i915_private *dev_priv)
{
unsigned long t, corr, state1, corr2, state2;
u32 pxvid, ext_v;
pxvid = I915_READ(PXVFREQ_BASE + (dev_priv->cur_delay * 4));
pxvid = (pxvid >> 24) & 0x7f;
ext_v = pvid_to_extvid(dev_priv, pxvid);
state1 = ext_v;
t = i915_mch_val(dev_priv);
if (t > 80)
corr = ((t * 2349) + 135940);
else if (t >= 50)
corr = ((t * 964) + 29317);
else
corr = ((t * 301) + 1004);
corr = corr * ((150142 * state1) / 10000 - 78642);
corr /= 100000;
corr2 = (corr * dev_priv->corr);
state2 = (corr2 * state1) / 10000;
state2 /= 100;
i915_update_gfx_val(dev_priv);
return dev_priv->gfx_power + state2;
}
unsigned long i915_read_mch_val(void)
{
struct drm_i915_private *dev_priv;
unsigned long chipset_val, graphics_val, ret = 0;
spin_lock(&mchdev_lock);
if (!i915_mch_dev)
goto out_unlock;
dev_priv = i915_mch_dev;
chipset_val = i915_chipset_val(dev_priv);
graphics_val = i915_gfx_val(dev_priv);
ret = chipset_val + graphics_val;
out_unlock:
spin_unlock(&mchdev_lock);
return ret;
}
bool i915_gpu_raise(void)
{
struct drm_i915_private *dev_priv;
bool ret = true;
spin_lock(&mchdev_lock);
if (!i915_mch_dev) {
ret = false;
goto out_unlock;
}
dev_priv = i915_mch_dev;
if (dev_priv->max_delay > dev_priv->fmax)
dev_priv->max_delay--;
out_unlock:
spin_unlock(&mchdev_lock);
return ret;
}
bool i915_gpu_lower(void)
{
struct drm_i915_private *dev_priv;
bool ret = true;
spin_lock(&mchdev_lock);
if (!i915_mch_dev) {
ret = false;
goto out_unlock;
}
dev_priv = i915_mch_dev;
if (dev_priv->max_delay < dev_priv->min_delay)
dev_priv->max_delay++;
out_unlock:
spin_unlock(&mchdev_lock);
return ret;
}
bool i915_gpu_busy(void)
{
struct drm_i915_private *dev_priv;
bool ret = false;
spin_lock(&mchdev_lock);
if (!i915_mch_dev)
goto out_unlock;
dev_priv = i915_mch_dev;
ret = dev_priv->busy;
out_unlock:
spin_unlock(&mchdev_lock);
return ret;
}
bool i915_gpu_turbo_disable(void)
{
struct drm_i915_private *dev_priv;
bool ret = true;
spin_lock(&mchdev_lock);
if (!i915_mch_dev) {
ret = false;
goto out_unlock;
}
dev_priv = i915_mch_dev;
dev_priv->max_delay = dev_priv->fstart;
if (!ironlake_set_drps(dev_priv->dev, dev_priv->fstart))
ret = false;
out_unlock:
spin_unlock(&mchdev_lock);
return ret;
}
static void
ips_ping_for_i915_load(void)
{
void (*link)(void);
link = symbol_get(ips_link_to_i915_driver);
if (link) {
link();
symbol_put(ips_link_to_i915_driver);
}
}
int i915_driver_load(struct drm_device *dev, unsigned long flags)
{
struct drm_i915_private *dev_priv;
int ret = 0, mmio_bar;
uint32_t agp_size;
dev->counters += 4;
dev->types[6] = _DRM_STAT_IRQ;
dev->types[7] = _DRM_STAT_PRIMARY;
dev->types[8] = _DRM_STAT_SECONDARY;
dev->types[9] = _DRM_STAT_DMA;
dev_priv = kzalloc(sizeof(drm_i915_private_t), GFP_KERNEL);
if (dev_priv == NULL)
return -ENOMEM;
dev->dev_private = (void *)dev_priv;
dev_priv->dev = dev;
dev_priv->info = (struct intel_device_info *) flags;
if (i915_get_bridge_dev(dev)) {
ret = -EIO;
goto free_priv;
}
if (IS_GEN2(dev))
dma_set_coherent_mask(&dev->pdev->dev, DMA_BIT_MASK(30));
if (IS_BROADWATER(dev) || IS_CRESTLINE(dev))
dma_set_coherent_mask(&dev->pdev->dev, DMA_BIT_MASK(32));
mmio_bar = IS_GEN2(dev) ? 1 : 0;
dev_priv->regs = pci_iomap(dev->pdev, mmio_bar, 0);
if (!dev_priv->regs) {
DRM_ERROR("failed to map registers\n");
ret = -EIO;
goto put_bridge;
}
dev_priv->mm.gtt = intel_gtt_get();
if (!dev_priv->mm.gtt) {
DRM_ERROR("Failed to initialize GTT\n");
ret = -ENODEV;
goto out_rmmap;
}
agp_size = dev_priv->mm.gtt->gtt_mappable_entries << PAGE_SHIFT;
dev_priv->mm.gtt_mapping =
io_mapping_create_wc(dev->agp->base, agp_size);
if (dev_priv->mm.gtt_mapping == NULL) {
ret = -EIO;
goto out_rmmap;
}
dev_priv->mm.gtt_mtrr = mtrr_add(dev->agp->base,
agp_size,
MTRR_TYPE_WRCOMB, 1);
if (dev_priv->mm.gtt_mtrr < 0) {
DRM_INFO("MTRR allocation failed. Graphics "
"performance may suffer.\n");
}
dev_priv->wq = alloc_workqueue("i915",
WQ_UNBOUND | WQ_NON_REENTRANT,
1);
if (dev_priv->wq == NULL) {
DRM_ERROR("Failed to create our workqueue.\n");
ret = -ENOMEM;
goto out_mtrrfree;
}
dev_priv->has_gem = 1;
intel_irq_init(dev);
intel_setup_mchbar(dev);
intel_setup_gmbus(dev);
intel_opregion_setup(dev);
intel_setup_bios(dev);
i915_gem_load(dev);
if (!I915_NEED_GFX_HWS(dev)) {
ret = i915_init_phys_hws(dev);
if (ret)
goto out_gem_unload;
}
if (IS_PINEVIEW(dev))
i915_pineview_get_mem_freq(dev);
else if (IS_GEN5(dev))
i915_ironlake_get_mem_freq(dev);
if (!IS_I945G(dev) && !IS_I945GM(dev))
pci_enable_msi(dev->pdev);
spin_lock_init(&dev_priv->irq_lock);
spin_lock_init(&dev_priv->error_lock);
spin_lock_init(&dev_priv->rps_lock);
if (IS_MOBILE(dev) || !IS_GEN2(dev))
dev_priv->num_pipe = 2;
else
dev_priv->num_pipe = 1;
ret = drm_vblank_init(dev, dev_priv->num_pipe);
if (ret)
goto out_gem_unload;
dev_priv->mm.suspended = 1;
intel_detect_pch(dev);
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
ret = i915_load_modeset_init(dev);
if (ret < 0) {
DRM_ERROR("failed to init modeset\n");
goto out_gem_unload;
}
}
intel_opregion_init(dev);
acpi_video_register();
setup_timer(&dev_priv->hangcheck_timer, i915_hangcheck_elapsed,
(unsigned long) dev);
spin_lock(&mchdev_lock);
i915_mch_dev = dev_priv;
dev_priv->mchdev_lock = &mchdev_lock;
spin_unlock(&mchdev_lock);
ips_ping_for_i915_load();
return 0;
out_gem_unload:
if (dev_priv->mm.inactive_shrinker.shrink)
unregister_shrinker(&dev_priv->mm.inactive_shrinker);
if (dev->pdev->msi_enabled)
pci_disable_msi(dev->pdev);
intel_teardown_gmbus(dev);
intel_teardown_mchbar(dev);
destroy_workqueue(dev_priv->wq);
out_mtrrfree:
if (dev_priv->mm.gtt_mtrr >= 0) {
mtrr_del(dev_priv->mm.gtt_mtrr, dev->agp->base,
dev->agp->agp_info.aper_size * 1024 * 1024);
dev_priv->mm.gtt_mtrr = -1;
}
io_mapping_free(dev_priv->mm.gtt_mapping);
out_rmmap:
pci_iounmap(dev->pdev, dev_priv->regs);
put_bridge:
pci_dev_put(dev_priv->bridge_dev);
free_priv:
kfree(dev_priv);
return ret;
}
int i915_driver_unload(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
int ret;
spin_lock(&mchdev_lock);
i915_mch_dev = NULL;
spin_unlock(&mchdev_lock);
if (dev_priv->mm.inactive_shrinker.shrink)
unregister_shrinker(&dev_priv->mm.inactive_shrinker);
mutex_lock(&dev->struct_mutex);
ret = i915_gpu_idle(dev);
if (ret)
DRM_ERROR("failed to idle hardware: %d\n", ret);
mutex_unlock(&dev->struct_mutex);
cancel_delayed_work_sync(&dev_priv->mm.retire_work);
io_mapping_free(dev_priv->mm.gtt_mapping);
if (dev_priv->mm.gtt_mtrr >= 0) {
mtrr_del(dev_priv->mm.gtt_mtrr, dev->agp->base,
dev->agp->agp_info.aper_size * 1024 * 1024);
dev_priv->mm.gtt_mtrr = -1;
}
acpi_video_unregister();
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
intel_fbdev_fini(dev);
intel_modeset_cleanup(dev);
if (dev_priv->child_dev && dev_priv->child_dev_num) {
kfree(dev_priv->child_dev);
dev_priv->child_dev = NULL;
dev_priv->child_dev_num = 0;
}
vga_switcheroo_unregister_client(dev->pdev);
vga_client_register(dev->pdev, NULL, NULL, NULL);
}
del_timer_sync(&dev_priv->hangcheck_timer);
cancel_work_sync(&dev_priv->error_work);
i915_destroy_error_state(dev);
if (dev->pdev->msi_enabled)
pci_disable_msi(dev->pdev);
intel_opregion_fini(dev);
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
flush_workqueue(dev_priv->wq);
mutex_lock(&dev->struct_mutex);
i915_gem_free_all_phys_object(dev);
i915_gem_cleanup_ringbuffer(dev);
mutex_unlock(&dev->struct_mutex);
if (I915_HAS_FBC(dev) && i915_powersave)
i915_cleanup_compression(dev);
drm_mm_takedown(&dev_priv->mm.stolen);
intel_cleanup_overlay(dev);
if (!I915_NEED_GFX_HWS(dev))
i915_free_hws(dev);
}
if (dev_priv->regs != NULL)
pci_iounmap(dev->pdev, dev_priv->regs);
intel_teardown_gmbus(dev);
intel_teardown_mchbar(dev);
destroy_workqueue(dev_priv->wq);
pci_dev_put(dev_priv->bridge_dev);
kfree(dev->dev_private);
return 0;
}
int i915_driver_open(struct drm_device *dev, struct drm_file *file)
{
struct drm_i915_file_private *file_priv;
DRM_DEBUG_DRIVER("\n");
file_priv = kmalloc(sizeof(*file_priv), GFP_KERNEL);
if (!file_priv)
return -ENOMEM;
file->driver_priv = file_priv;
spin_lock_init(&file_priv->mm.lock);
INIT_LIST_HEAD(&file_priv->mm.request_list);
return 0;
}
void i915_driver_lastclose(struct drm_device * dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
if (!dev_priv || drm_core_check_feature(dev, DRIVER_MODESET)) {
intel_fb_restore_mode(dev);
vga_switcheroo_process_delayed_switch();
return;
}
i915_gem_lastclose(dev);
if (dev_priv->agp_heap)
i915_mem_takedown(&(dev_priv->agp_heap));
i915_dma_cleanup(dev);
}
void i915_driver_preclose(struct drm_device * dev, struct drm_file *file_priv)
{
drm_i915_private_t *dev_priv = dev->dev_private;
i915_gem_release(dev, file_priv);
if (!drm_core_check_feature(dev, DRIVER_MODESET))
i915_mem_release(dev, file_priv, dev_priv->agp_heap);
}
void i915_driver_postclose(struct drm_device *dev, struct drm_file *file)
{
struct drm_i915_file_private *file_priv = file->driver_priv;
kfree(file_priv);
}
int i915_driver_device_is_agp(struct drm_device * dev)
{
return 1;
}
