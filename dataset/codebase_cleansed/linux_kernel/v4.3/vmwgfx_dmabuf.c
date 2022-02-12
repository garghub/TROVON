int vmw_dmabuf_pin_in_placement(struct vmw_private *dev_priv,
struct vmw_dma_buffer *buf,
struct ttm_placement *placement,
bool interruptible)
{
struct ttm_buffer_object *bo = &buf->base;
int ret;
ret = ttm_write_lock(&dev_priv->reservation_sem, interruptible);
if (unlikely(ret != 0))
return ret;
vmw_execbuf_release_pinned_bo(dev_priv);
ret = ttm_bo_reserve(bo, interruptible, false, false, NULL);
if (unlikely(ret != 0))
goto err;
ret = ttm_bo_validate(bo, placement, interruptible, false);
if (!ret)
vmw_bo_pin_reserved(buf, true);
ttm_bo_unreserve(bo);
err:
ttm_write_unlock(&dev_priv->reservation_sem);
return ret;
}
int vmw_dmabuf_pin_in_vram_or_gmr(struct vmw_private *dev_priv,
struct vmw_dma_buffer *buf,
bool interruptible)
{
struct ttm_buffer_object *bo = &buf->base;
int ret;
ret = ttm_write_lock(&dev_priv->reservation_sem, interruptible);
if (unlikely(ret != 0))
return ret;
vmw_execbuf_release_pinned_bo(dev_priv);
ret = ttm_bo_reserve(bo, interruptible, false, false, NULL);
if (unlikely(ret != 0))
goto err;
ret = ttm_bo_validate(bo, &vmw_vram_gmr_placement, interruptible,
false);
if (likely(ret == 0) || ret == -ERESTARTSYS)
goto out_unreserve;
ret = ttm_bo_validate(bo, &vmw_vram_placement, interruptible, false);
out_unreserve:
if (!ret)
vmw_bo_pin_reserved(buf, true);
ttm_bo_unreserve(bo);
err:
ttm_write_unlock(&dev_priv->reservation_sem);
return ret;
}
int vmw_dmabuf_pin_in_vram(struct vmw_private *dev_priv,
struct vmw_dma_buffer *buf,
bool interruptible)
{
return vmw_dmabuf_pin_in_placement(dev_priv, buf, &vmw_vram_placement,
interruptible);
}
int vmw_dmabuf_pin_in_start_of_vram(struct vmw_private *dev_priv,
struct vmw_dma_buffer *buf,
bool interruptible)
{
struct ttm_buffer_object *bo = &buf->base;
struct ttm_placement placement;
struct ttm_place place;
int ret = 0;
place = vmw_vram_placement.placement[0];
place.lpfn = bo->num_pages;
placement.num_placement = 1;
placement.placement = &place;
placement.num_busy_placement = 1;
placement.busy_placement = &place;
ret = ttm_write_lock(&dev_priv->reservation_sem, interruptible);
if (unlikely(ret != 0))
return ret;
vmw_execbuf_release_pinned_bo(dev_priv);
ret = ttm_bo_reserve(bo, interruptible, false, false, NULL);
if (unlikely(ret != 0))
goto err_unlock;
if (bo->mem.mem_type == TTM_PL_VRAM &&
bo->mem.start < bo->num_pages &&
bo->mem.start > 0)
(void) ttm_bo_validate(bo, &vmw_sys_placement, false, false);
ret = ttm_bo_validate(bo, &placement, interruptible, false);
WARN_ON(ret == 0 && bo->offset != 0);
if (!ret)
vmw_bo_pin_reserved(buf, true);
ttm_bo_unreserve(bo);
err_unlock:
ttm_write_unlock(&dev_priv->reservation_sem);
return ret;
}
int vmw_dmabuf_unpin(struct vmw_private *dev_priv,
struct vmw_dma_buffer *buf,
bool interruptible)
{
struct ttm_buffer_object *bo = &buf->base;
int ret;
ret = ttm_read_lock(&dev_priv->reservation_sem, interruptible);
if (unlikely(ret != 0))
return ret;
ret = ttm_bo_reserve(bo, interruptible, false, false, NULL);
if (unlikely(ret != 0))
goto err;
vmw_bo_pin_reserved(buf, false);
ttm_bo_unreserve(bo);
err:
ttm_read_unlock(&dev_priv->reservation_sem);
return ret;
}
void vmw_bo_get_guest_ptr(const struct ttm_buffer_object *bo,
SVGAGuestPtr *ptr)
{
if (bo->mem.mem_type == TTM_PL_VRAM) {
ptr->gmrId = SVGA_GMR_FRAMEBUFFER;
ptr->offset = bo->offset;
} else {
ptr->gmrId = bo->mem.start;
ptr->offset = 0;
}
}
void vmw_bo_pin_reserved(struct vmw_dma_buffer *vbo, bool pin)
{
struct ttm_place pl;
struct ttm_placement placement;
struct ttm_buffer_object *bo = &vbo->base;
uint32_t old_mem_type = bo->mem.mem_type;
int ret;
lockdep_assert_held(&bo->resv->lock.base);
if (pin) {
if (vbo->pin_count++ > 0)
return;
} else {
WARN_ON(vbo->pin_count <= 0);
if (--vbo->pin_count > 0)
return;
}
pl.fpfn = 0;
pl.lpfn = 0;
pl.flags = TTM_PL_FLAG_VRAM | VMW_PL_FLAG_GMR | VMW_PL_FLAG_MOB
| TTM_PL_FLAG_SYSTEM | TTM_PL_FLAG_CACHED;
if (pin)
pl.flags |= TTM_PL_FLAG_NO_EVICT;
memset(&placement, 0, sizeof(placement));
placement.num_placement = 1;
placement.placement = &pl;
ret = ttm_bo_validate(bo, &placement, false, true);
BUG_ON(ret != 0 || bo->mem.mem_type != old_mem_type);
}
