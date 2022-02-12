static inline u32
intel_read_legacy_status_page(struct drm_i915_private *dev_priv, int reg)
{
if (I915_NEED_GFX_HWS(dev_priv->dev))
return ioread32(dev_priv->dri1.gfx_hws_cpu_addr + reg);
else
return intel_read_status_page(LP_RING(dev_priv), reg);
}
void i915_update_dri1_breadcrumb(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct drm_i915_master_private *master_priv;
if (dev->primary->master) {
master_priv = dev->primary->master->driver_priv;
if (master_priv->sarea_priv)
master_priv->sarea_priv->last_dispatch =
READ_BREADCRUMB(dev_priv);
}
}
static void i915_write_hws_pga(struct drm_device *dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
u32 addr;
addr = dev_priv->status_page_dmah->busaddr;
if (INTEL_INFO(dev)->gen >= 4)
addr |= (dev_priv->status_page_dmah->busaddr >> 28) & 0xf0;
I915_WRITE(HWS_PGA, addr);
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
iounmap(dev_priv->dri1.gfx_hws_cpu_addr);
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
ring->space = ring->head - (ring->tail + I915_RING_FREE_SPACE);
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
dev_priv->dri1.cpp = init->cpp;
dev_priv->dri1.back_offset = init->back_offset;
dev_priv->dri1.front_offset = init->front_offset;
dev_priv->dri1.current_page = 0;
if (master_priv->sarea_priv)
master_priv->sarea_priv->pf_current_page = 0;
dev_priv->dri1.allow_batchbuffer = 1;
return 0;
}
static int i915_dma_resume(struct drm_device * dev)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
struct intel_ring_buffer *ring = LP_RING(dev_priv);
DRM_DEBUG_DRIVER("%s\n", __func__);
if (ring->virtual_start == NULL) {
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
if (drm_core_check_feature(dev, DRIVER_MODESET))
return -ENODEV;
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
dev_priv->dri1.counter++;
if (dev_priv->dri1.counter > 0x7FFFFFFFUL)
dev_priv->dri1.counter = 0;
if (master_priv->sarea_priv)
master_priv->sarea_priv->last_enqueue = dev_priv->dri1.counter;
if (BEGIN_LP_RING(4) == 0) {
OUT_RING(MI_STORE_DWORD_INDEX);
OUT_RING(I915_BREADCRUMB_INDEX << MI_STORE_DWORD_INDEX_SHIFT);
OUT_RING(dev_priv->dri1.counter);
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
dev_priv->dri1.current_page,
master_priv->sarea_priv->pf_current_page);
i915_kernel_lost_context(dev);
ret = BEGIN_LP_RING(10);
if (ret)
return ret;
OUT_RING(MI_FLUSH | MI_READ_FLUSH);
OUT_RING(0);
OUT_RING(CMD_OP_DISPLAYBUFFER_INFO | ASYNC_FLIP);
OUT_RING(0);
if (dev_priv->dri1.current_page == 0) {
OUT_RING(dev_priv->dri1.back_offset);
dev_priv->dri1.current_page = 1;
} else {
OUT_RING(dev_priv->dri1.front_offset);
dev_priv->dri1.current_page = 0;
}
OUT_RING(0);
OUT_RING(MI_WAIT_FOR_EVENT | MI_WAIT_FOR_PLANE_A_FLIP);
OUT_RING(0);
ADVANCE_LP_RING();
master_priv->sarea_priv->last_enqueue = dev_priv->dri1.counter++;
if (BEGIN_LP_RING(4) == 0) {
OUT_RING(MI_STORE_DWORD_INDEX);
OUT_RING(I915_BREADCRUMB_INDEX << MI_STORE_DWORD_INDEX_SHIFT);
OUT_RING(dev_priv->dri1.counter);
OUT_RING(0);
ADVANCE_LP_RING();
}
master_priv->sarea_priv->pf_current_page = dev_priv->dri1.current_page;
return 0;
}
static int i915_quiescent(struct drm_device *dev)
{
i915_kernel_lost_context(dev);
return intel_ring_idle(LP_RING(dev->dev_private));
}
static int i915_flush_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
int ret;
if (drm_core_check_feature(dev, DRIVER_MODESET))
return -ENODEV;
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
if (drm_core_check_feature(dev, DRIVER_MODESET))
return -ENODEV;
if (!dev_priv->dri1.allow_batchbuffer) {
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
if (drm_core_check_feature(dev, DRIVER_MODESET))
return -ENODEV;
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
static int i915_emit_irq(struct drm_device * dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
struct drm_i915_master_private *master_priv = dev->primary->master->driver_priv;
i915_kernel_lost_context(dev);
DRM_DEBUG_DRIVER("\n");
dev_priv->dri1.counter++;
if (dev_priv->dri1.counter > 0x7FFFFFFFUL)
dev_priv->dri1.counter = 1;
if (master_priv->sarea_priv)
master_priv->sarea_priv->last_enqueue = dev_priv->dri1.counter;
if (BEGIN_LP_RING(4) == 0) {
OUT_RING(MI_STORE_DWORD_INDEX);
OUT_RING(I915_BREADCRUMB_INDEX << MI_STORE_DWORD_INDEX_SHIFT);
OUT_RING(dev_priv->dri1.counter);
OUT_RING(MI_USER_INTERRUPT);
ADVANCE_LP_RING();
}
return dev_priv->dri1.counter;
}
static int i915_wait_irq(struct drm_device * dev, int irq_nr)
{
drm_i915_private_t *dev_priv = (drm_i915_private_t *) dev->dev_private;
struct drm_i915_master_private *master_priv = dev->primary->master->driver_priv;
int ret = 0;
struct intel_ring_buffer *ring = LP_RING(dev_priv);
DRM_DEBUG_DRIVER("irq_nr=%d breadcrumb=%d\n", irq_nr,
READ_BREADCRUMB(dev_priv));
if (READ_BREADCRUMB(dev_priv) >= irq_nr) {
if (master_priv->sarea_priv)
master_priv->sarea_priv->last_dispatch = READ_BREADCRUMB(dev_priv);
return 0;
}
if (master_priv->sarea_priv)
master_priv->sarea_priv->perf_boxes |= I915_BOX_WAIT;
if (ring->irq_get(ring)) {
DRM_WAIT_ON(ret, ring->irq_queue, 3 * DRM_HZ,
READ_BREADCRUMB(dev_priv) >= irq_nr);
ring->irq_put(ring);
} else if (wait_for(READ_BREADCRUMB(dev_priv) >= irq_nr, 3000))
ret = -EBUSY;
if (ret == -EBUSY) {
DRM_ERROR("EBUSY -- rec: %d emitted: %d\n",
READ_BREADCRUMB(dev_priv), (int)dev_priv->dri1.counter);
}
return ret;
}
static int i915_irq_emit(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
drm_i915_private_t *dev_priv = dev->dev_private;
drm_i915_irq_emit_t *emit = data;
int result;
if (drm_core_check_feature(dev, DRIVER_MODESET))
return -ENODEV;
if (!dev_priv || !LP_RING(dev_priv)->virtual_start) {
DRM_ERROR("called with no initialization\n");
return -EINVAL;
}
RING_LOCK_TEST_WITH_RETURN(dev, file_priv);
mutex_lock(&dev->struct_mutex);
result = i915_emit_irq(dev);
mutex_unlock(&dev->struct_mutex);
if (DRM_COPY_TO_USER(emit->irq_seq, &result, sizeof(int))) {
DRM_ERROR("copy_to_user\n");
return -EFAULT;
}
return 0;
}
static int i915_irq_wait(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
drm_i915_private_t *dev_priv = dev->dev_private;
drm_i915_irq_wait_t *irqwait = data;
if (drm_core_check_feature(dev, DRIVER_MODESET))
return -ENODEV;
if (!dev_priv) {
DRM_ERROR("called with no initialization\n");
return -EINVAL;
}
return i915_wait_irq(dev, irqwait->irq_seq);
}
static int i915_vblank_pipe_get(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
drm_i915_private_t *dev_priv = dev->dev_private;
drm_i915_vblank_pipe_t *pipe = data;
if (drm_core_check_feature(dev, DRIVER_MODESET))
return -ENODEV;
if (!dev_priv) {
DRM_ERROR("called with no initialization\n");
return -EINVAL;
}
pipe->pipe = DRM_I915_VBLANK_PIPE_A | DRM_I915_VBLANK_PIPE_B;
return 0;
}
static int i915_vblank_swap(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
return -EINVAL;
}
static int i915_flip_bufs(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
int ret;
if (drm_core_check_feature(dev, DRIVER_MODESET))
return -ENODEV;
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
value = dev_priv->dri1.allow_batchbuffer ? 1 : 0;
break;
case I915_PARAM_LAST_DISPATCH:
value = READ_BREADCRUMB(dev_priv);
break;
case I915_PARAM_CHIPSET_ID:
value = dev->pci_device;
break;
case I915_PARAM_HAS_GEM:
value = 1;
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
value = 1;
break;
case I915_PARAM_HAS_BSD:
value = intel_ring_initialized(&dev_priv->ring[VCS]);
break;
case I915_PARAM_HAS_BLT:
value = intel_ring_initialized(&dev_priv->ring[BCS]);
break;
case I915_PARAM_HAS_VEBOX:
value = intel_ring_initialized(&dev_priv->ring[VECS]);
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
case I915_PARAM_HAS_GEN7_SOL_RESET:
value = 1;
break;
case I915_PARAM_HAS_LLC:
value = HAS_LLC(dev);
break;
case I915_PARAM_HAS_ALIASING_PPGTT:
value = dev_priv->mm.aliasing_ppgtt ? 1 : 0;
break;
case I915_PARAM_HAS_WAIT_TIMEOUT:
value = 1;
break;
case I915_PARAM_HAS_SEMAPHORES:
value = i915_semaphore_is_enabled(dev);
break;
case I915_PARAM_HAS_PRIME_VMAP_FLUSH:
value = 1;
break;
case I915_PARAM_HAS_SECURE_BATCHES:
value = capable(CAP_SYS_ADMIN);
break;
case I915_PARAM_HAS_PINNED_BATCHES:
value = 1;
break;
case I915_PARAM_HAS_EXEC_NO_RELOC:
value = 1;
break;
case I915_PARAM_HAS_EXEC_HANDLE_LUT:
value = 1;
break;
default:
DRM_DEBUG("Unknown parameter %d\n", param->param);
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
break;
case I915_SETPARAM_ALLOW_BATCHBUFFER:
dev_priv->dri1.allow_batchbuffer = param->value ? 1 : 0;
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
struct intel_ring_buffer *ring;
if (drm_core_check_feature(dev, DRIVER_MODESET))
return -ENODEV;
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
ring = LP_RING(dev_priv);
ring->status_page.gfx_addr = hws->addr & (0x1ffff<<12);
dev_priv->dri1.gfx_hws_cpu_addr =
ioremap_wc(dev_priv->gtt.mappable_base + hws->addr, 4096);
if (dev_priv->dri1.gfx_hws_cpu_addr == NULL) {
i915_dma_cleanup(dev);
ring->status_page.gfx_addr = 0;
DRM_ERROR("can not ioremap virtual address for"
" G33 hw status page\n");
return -ENOMEM;
}
memset_io(dev_priv->dri1.gfx_hws_cpu_addr, 0, PAGE_SIZE);
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
dev_priv->bridge_dev = pci_get_bus_and_slot(0, PCI_DEVFN(0, 0));
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
pr_info("switched on\n");
dev->switch_power_state = DRM_SWITCH_POWER_CHANGING;
pci_set_power_state(dev->pdev, PCI_D0);
i915_resume(dev);
dev->switch_power_state = DRM_SWITCH_POWER_ON;
} else {
pr_err("switched off\n");
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
ret = vga_switcheroo_register_client(dev->pdev, &i915_switcheroo_ops);
if (ret)
goto cleanup_vga_client;
ret = i915_gem_init_stolen(dev);
if (ret)
goto cleanup_vga_switcheroo;
ret = drm_irq_install(dev);
if (ret)
goto cleanup_gem_stolen;
intel_modeset_init(dev);
ret = i915_gem_init(dev);
if (ret)
goto cleanup_irq;
INIT_WORK(&dev_priv->console_resume_work, intel_console_resume);
intel_modeset_gem_init(dev);
dev->vblank_disable_allowed = 1;
if (INTEL_INFO(dev)->num_pipes == 0) {
dev_priv->mm.suspended = 0;
return 0;
}
ret = intel_fbdev_init(dev);
if (ret)
goto cleanup_gem;
intel_hpd_init(dev);
intel_fbdev_initial_config(dev);
dev_priv->enable_hotplug_processing = true;
drm_kms_helper_poll_init(dev);
dev_priv->mm.suspended = 0;
return 0;
cleanup_gem:
mutex_lock(&dev->struct_mutex);
i915_gem_cleanup_ringbuffer(dev);
i915_gem_context_fini(dev);
mutex_unlock(&dev->struct_mutex);
i915_gem_cleanup_aliasing_ppgtt(dev);
drm_mm_takedown(&dev_priv->mm.gtt_space);
cleanup_irq:
drm_irq_uninstall(dev);
cleanup_gem_stolen:
i915_gem_cleanup_stolen(dev);
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
static void i915_kick_out_firmware_fb(struct drm_i915_private *dev_priv)
{
struct apertures_struct *ap;
struct pci_dev *pdev = dev_priv->dev->pdev;
bool primary;
ap = alloc_apertures(1);
if (!ap)
return;
ap->ranges[0].base = dev_priv->gtt.mappable_base;
ap->ranges[0].size = dev_priv->gtt.mappable_end;
primary =
pdev->resource[PCI_ROM_RESOURCE].flags & IORESOURCE_ROM_SHADOW;
remove_conflicting_framebuffers(ap, "inteldrmfb", primary);
kfree(ap);
}
static void i915_dump_device_info(struct drm_i915_private *dev_priv)
{
const struct intel_device_info *info = dev_priv->info;
#define PRINT_S(name) "%s"
#define SEP_EMPTY
#define PRINT_FLAG(name) info->name ? #name "," : ""
#define SEP_COMMA ,
DRM_DEBUG_DRIVER("i915 device info: gen=%i, pciid=0x%04x flags="
DEV_INFO_FOR_EACH_FLAG(PRINT_S, SEP_EMPTY),
info->gen,
dev_priv->dev->pdev->device,
DEV_INFO_FOR_EACH_FLAG(PRINT_FLAG, SEP_COMMA));
#undef PRINT_S
#undef SEP_EMPTY
#undef PRINT_FLAG
#undef SEP_COMMA
}
static void intel_early_sanitize_regs(struct drm_device *dev)
{
struct drm_i915_private *dev_priv = dev->dev_private;
if (HAS_FPGA_DBG_UNCLAIMED(dev))
I915_WRITE_NOTRACE(FPGA_DBG, FPGA_DBG_RM_NOCLAIM);
}
int i915_driver_load(struct drm_device *dev, unsigned long flags)
{
struct drm_i915_private *dev_priv;
struct intel_device_info *info;
int ret = 0, mmio_bar, mmio_size;
uint32_t aperture_size;
info = (struct intel_device_info *) flags;
if (info->gen >= 6 && !drm_core_check_feature(dev, DRIVER_MODESET))
return -ENODEV;
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
dev_priv->info = info;
spin_lock_init(&dev_priv->irq_lock);
spin_lock_init(&dev_priv->gpu_error.lock);
spin_lock_init(&dev_priv->rps.lock);
spin_lock_init(&dev_priv->gt_lock);
spin_lock_init(&dev_priv->backlight.lock);
mutex_init(&dev_priv->dpio_lock);
mutex_init(&dev_priv->rps.hw_lock);
mutex_init(&dev_priv->modeset_restore_lock);
i915_dump_device_info(dev_priv);
if (i915_get_bridge_dev(dev)) {
ret = -EIO;
goto free_priv;
}
mmio_bar = IS_GEN2(dev) ? 1 : 0;
if (info->gen < 5)
mmio_size = 512*1024;
else
mmio_size = 2*1024*1024;
dev_priv->regs = pci_iomap(dev->pdev, mmio_bar, mmio_size);
if (!dev_priv->regs) {
DRM_ERROR("failed to map registers\n");
ret = -EIO;
goto put_bridge;
}
intel_early_sanitize_regs(dev);
ret = i915_gem_gtt_init(dev);
if (ret)
goto put_bridge;
if (drm_core_check_feature(dev, DRIVER_MODESET))
i915_kick_out_firmware_fb(dev_priv);
pci_set_master(dev->pdev);
if (IS_GEN2(dev))
dma_set_coherent_mask(&dev->pdev->dev, DMA_BIT_MASK(30));
if (IS_BROADWATER(dev) || IS_CRESTLINE(dev))
dma_set_coherent_mask(&dev->pdev->dev, DMA_BIT_MASK(32));
aperture_size = dev_priv->gtt.mappable_end;
dev_priv->gtt.mappable =
io_mapping_create_wc(dev_priv->gtt.mappable_base,
aperture_size);
if (dev_priv->gtt.mappable == NULL) {
ret = -EIO;
goto out_rmmap;
}
dev_priv->mm.gtt_mtrr = arch_phys_wc_add(dev_priv->gtt.mappable_base,
aperture_size);
dev_priv->wq = alloc_ordered_workqueue("i915", 0);
if (dev_priv->wq == NULL) {
DRM_ERROR("Failed to create our workqueue.\n");
ret = -ENOMEM;
goto out_mtrrfree;
}
intel_detect_pch(dev);
intel_irq_init(dev);
intel_pm_init(dev);
intel_gt_sanitize(dev);
intel_gt_init(dev);
intel_setup_mchbar(dev);
intel_setup_gmbus(dev);
intel_opregion_setup(dev);
intel_setup_bios(dev);
i915_gem_load(dev);
if (!IS_I945G(dev) && !IS_I945GM(dev))
pci_enable_msi(dev->pdev);
dev_priv->num_plane = 1;
if (IS_VALLEYVIEW(dev))
dev_priv->num_plane = 2;
if (INTEL_INFO(dev)->num_pipes) {
ret = drm_vblank_init(dev, INTEL_INFO(dev)->num_pipes);
if (ret)
goto out_gem_unload;
}
dev_priv->mm.suspended = 1;
if (HAS_POWER_WELL(dev))
i915_init_power_well(dev);
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
ret = i915_load_modeset_init(dev);
if (ret < 0) {
DRM_ERROR("failed to init modeset\n");
goto out_gem_unload;
}
}
i915_setup_sysfs(dev);
if (INTEL_INFO(dev)->num_pipes) {
intel_opregion_init(dev);
acpi_video_register();
}
if (IS_GEN5(dev))
intel_gpu_ips_init(dev_priv);
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
arch_phys_wc_del(dev_priv->mm.gtt_mtrr);
io_mapping_free(dev_priv->gtt.mappable);
dev_priv->gtt.gtt_remove(dev);
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
intel_gpu_ips_teardown();
if (HAS_POWER_WELL(dev))
i915_remove_power_well(dev);
i915_teardown_sysfs(dev);
if (dev_priv->mm.inactive_shrinker.shrink)
unregister_shrinker(&dev_priv->mm.inactive_shrinker);
mutex_lock(&dev->struct_mutex);
ret = i915_gpu_idle(dev);
if (ret)
DRM_ERROR("failed to idle hardware: %d\n", ret);
i915_gem_retire_requests(dev);
mutex_unlock(&dev->struct_mutex);
cancel_delayed_work_sync(&dev_priv->mm.retire_work);
io_mapping_free(dev_priv->gtt.mappable);
arch_phys_wc_del(dev_priv->mm.gtt_mtrr);
acpi_video_unregister();
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
intel_fbdev_fini(dev);
intel_modeset_cleanup(dev);
cancel_work_sync(&dev_priv->console_resume_work);
if (dev_priv->vbt.child_dev && dev_priv->vbt.child_dev_num) {
kfree(dev_priv->vbt.child_dev);
dev_priv->vbt.child_dev = NULL;
dev_priv->vbt.child_dev_num = 0;
}
vga_switcheroo_unregister_client(dev->pdev);
vga_client_register(dev->pdev, NULL, NULL, NULL);
}
del_timer_sync(&dev_priv->gpu_error.hangcheck_timer);
cancel_work_sync(&dev_priv->gpu_error.work);
i915_destroy_error_state(dev);
if (dev->pdev->msi_enabled)
pci_disable_msi(dev->pdev);
intel_opregion_fini(dev);
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
flush_workqueue(dev_priv->wq);
mutex_lock(&dev->struct_mutex);
i915_gem_free_all_phys_object(dev);
i915_gem_cleanup_ringbuffer(dev);
i915_gem_context_fini(dev);
mutex_unlock(&dev->struct_mutex);
i915_gem_cleanup_aliasing_ppgtt(dev);
i915_gem_cleanup_stolen(dev);
if (!I915_NEED_GFX_HWS(dev))
i915_free_hws(dev);
}
drm_mm_takedown(&dev_priv->mm.gtt_space);
if (dev_priv->regs != NULL)
pci_iounmap(dev->pdev, dev_priv->regs);
intel_teardown_gmbus(dev);
intel_teardown_mchbar(dev);
destroy_workqueue(dev_priv->wq);
pm_qos_remove_request(&dev_priv->pm_qos);
dev_priv->gtt.gtt_remove(dev);
if (dev_priv->slab)
kmem_cache_destroy(dev_priv->slab);
pci_dev_put(dev_priv->bridge_dev);
kfree(dev->dev_private);
return 0;
}
int i915_driver_open(struct drm_device *dev, struct drm_file *file)
{
struct drm_i915_file_private *file_priv;
DRM_DEBUG_DRIVER("\n");
file_priv = kzalloc(sizeof(*file_priv), GFP_KERNEL);
if (!file_priv)
return -ENOMEM;
file->driver_priv = file_priv;
spin_lock_init(&file_priv->mm.lock);
INIT_LIST_HEAD(&file_priv->mm.request_list);
idr_init(&file_priv->context_idr);
return 0;
}
void i915_driver_lastclose(struct drm_device * dev)
{
drm_i915_private_t *dev_priv = dev->dev_private;
if (!dev_priv)
return;
if (drm_core_check_feature(dev, DRIVER_MODESET)) {
intel_fb_restore_mode(dev);
vga_switcheroo_process_delayed_switch();
return;
}
i915_gem_lastclose(dev);
i915_dma_cleanup(dev);
}
void i915_driver_preclose(struct drm_device * dev, struct drm_file *file_priv)
{
i915_gem_context_close(dev, file_priv);
i915_gem_release(dev, file_priv);
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
