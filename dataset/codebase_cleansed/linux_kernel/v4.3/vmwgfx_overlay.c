static inline struct vmw_overlay *vmw_overlay(struct drm_device *dev)
{
struct vmw_private *dev_priv = vmw_priv(dev);
return dev_priv ? dev_priv->overlay_priv : NULL;
}
static inline void fill_escape(struct vmw_escape_header *header,
uint32_t size)
{
header->cmd = SVGA_CMD_ESCAPE;
header->body.nsid = SVGA_ESCAPE_NSID_VMWARE;
header->body.size = size;
}
static inline void fill_flush(struct vmw_escape_video_flush *cmd,
uint32_t stream_id)
{
fill_escape(&cmd->escape, sizeof(cmd->flush));
cmd->flush.cmdType = SVGA_ESCAPE_VMWARE_VIDEO_FLUSH;
cmd->flush.streamId = stream_id;
}
static int vmw_overlay_send_put(struct vmw_private *dev_priv,
struct vmw_dma_buffer *buf,
struct drm_vmw_control_stream_arg *arg,
bool interruptible)
{
struct vmw_escape_video_flush *flush;
size_t fifo_size;
bool have_so = (dev_priv->active_display_unit == vmw_du_screen_object);
int i, num_items;
SVGAGuestPtr ptr;
struct {
struct vmw_escape_header escape;
struct {
uint32_t cmdType;
uint32_t streamId;
} header;
} *cmds;
struct {
uint32_t registerId;
uint32_t value;
} *items;
if (have_so)
num_items = SVGA_VIDEO_DST_SCREEN_ID + 1;
else
num_items = SVGA_VIDEO_PITCH_3 + 1;
fifo_size = sizeof(*cmds) + sizeof(*flush) + sizeof(*items) * num_items;
cmds = vmw_fifo_reserve(dev_priv, fifo_size);
if (!cmds)
return -ENOMEM;
items = (typeof(items))&cmds[1];
flush = (struct vmw_escape_video_flush *)&items[num_items];
fill_escape(&cmds->escape, sizeof(*items) * (num_items + 1));
cmds->header.cmdType = SVGA_ESCAPE_VMWARE_VIDEO_SET_REGS;
cmds->header.streamId = arg->stream_id;
for (i = 0; i < num_items; i++)
items[i].registerId = i;
vmw_bo_get_guest_ptr(&buf->base, &ptr);
ptr.offset += arg->offset;
items[SVGA_VIDEO_ENABLED].value = true;
items[SVGA_VIDEO_FLAGS].value = arg->flags;
items[SVGA_VIDEO_DATA_OFFSET].value = ptr.offset;
items[SVGA_VIDEO_FORMAT].value = arg->format;
items[SVGA_VIDEO_COLORKEY].value = arg->color_key;
items[SVGA_VIDEO_SIZE].value = arg->size;
items[SVGA_VIDEO_WIDTH].value = arg->width;
items[SVGA_VIDEO_HEIGHT].value = arg->height;
items[SVGA_VIDEO_SRC_X].value = arg->src.x;
items[SVGA_VIDEO_SRC_Y].value = arg->src.y;
items[SVGA_VIDEO_SRC_WIDTH].value = arg->src.w;
items[SVGA_VIDEO_SRC_HEIGHT].value = arg->src.h;
items[SVGA_VIDEO_DST_X].value = arg->dst.x;
items[SVGA_VIDEO_DST_Y].value = arg->dst.y;
items[SVGA_VIDEO_DST_WIDTH].value = arg->dst.w;
items[SVGA_VIDEO_DST_HEIGHT].value = arg->dst.h;
items[SVGA_VIDEO_PITCH_1].value = arg->pitch[0];
items[SVGA_VIDEO_PITCH_2].value = arg->pitch[1];
items[SVGA_VIDEO_PITCH_3].value = arg->pitch[2];
if (have_so) {
items[SVGA_VIDEO_DATA_GMRID].value = ptr.gmrId;
items[SVGA_VIDEO_DST_SCREEN_ID].value = SVGA_ID_INVALID;
}
fill_flush(flush, arg->stream_id);
vmw_fifo_commit(dev_priv, fifo_size);
return 0;
}
static int vmw_overlay_send_stop(struct vmw_private *dev_priv,
uint32_t stream_id,
bool interruptible)
{
struct {
struct vmw_escape_header escape;
SVGAEscapeVideoSetRegs body;
struct vmw_escape_video_flush flush;
} *cmds;
int ret;
for (;;) {
cmds = vmw_fifo_reserve(dev_priv, sizeof(*cmds));
if (cmds)
break;
ret = vmw_fallback_wait(dev_priv, false, true, 0,
interruptible, 3*HZ);
if (interruptible && ret == -ERESTARTSYS)
return ret;
else
BUG_ON(ret != 0);
}
fill_escape(&cmds->escape, sizeof(cmds->body));
cmds->body.header.cmdType = SVGA_ESCAPE_VMWARE_VIDEO_SET_REGS;
cmds->body.header.streamId = stream_id;
cmds->body.items[0].registerId = SVGA_VIDEO_ENABLED;
cmds->body.items[0].value = false;
fill_flush(&cmds->flush, stream_id);
vmw_fifo_commit(dev_priv, sizeof(*cmds));
return 0;
}
static int vmw_overlay_move_buffer(struct vmw_private *dev_priv,
struct vmw_dma_buffer *buf,
bool pin, bool inter)
{
if (!pin)
return vmw_dmabuf_unpin(dev_priv, buf, inter);
if (dev_priv->active_display_unit == vmw_du_legacy)
return vmw_dmabuf_pin_in_vram(dev_priv, buf, inter);
return vmw_dmabuf_pin_in_vram_or_gmr(dev_priv, buf, inter);
}
static int vmw_overlay_stop(struct vmw_private *dev_priv,
uint32_t stream_id, bool pause,
bool interruptible)
{
struct vmw_overlay *overlay = dev_priv->overlay_priv;
struct vmw_stream *stream = &overlay->stream[stream_id];
int ret;
if (!stream->buf)
return 0;
if (!stream->paused) {
ret = vmw_overlay_send_stop(dev_priv, stream_id,
interruptible);
if (ret)
return ret;
ret = vmw_overlay_move_buffer(dev_priv, stream->buf, false,
interruptible);
if (interruptible && ret == -ERESTARTSYS)
return ret;
else
BUG_ON(ret != 0);
}
if (!pause) {
vmw_dmabuf_unreference(&stream->buf);
stream->paused = false;
} else {
stream->paused = true;
}
return 0;
}
static int vmw_overlay_update_stream(struct vmw_private *dev_priv,
struct vmw_dma_buffer *buf,
struct drm_vmw_control_stream_arg *arg,
bool interruptible)
{
struct vmw_overlay *overlay = dev_priv->overlay_priv;
struct vmw_stream *stream = &overlay->stream[arg->stream_id];
int ret = 0;
if (!buf)
return -EINVAL;
DRM_DEBUG(" %s: old %p, new %p, %spaused\n", __func__,
stream->buf, buf, stream->paused ? "" : "not ");
if (stream->buf != buf) {
ret = vmw_overlay_stop(dev_priv, arg->stream_id,
false, interruptible);
if (ret)
return ret;
} else if (!stream->paused) {
ret = vmw_overlay_send_put(dev_priv, buf, arg, interruptible);
if (ret == 0)
stream->saved = *arg;
else
BUG_ON(!interruptible);
return ret;
}
ret = vmw_overlay_move_buffer(dev_priv, buf, true, interruptible);
if (ret)
return ret;
ret = vmw_overlay_send_put(dev_priv, buf, arg, interruptible);
if (ret) {
BUG_ON(vmw_overlay_move_buffer(dev_priv, buf, false, false)
!= 0);
return ret;
}
if (stream->buf != buf)
stream->buf = vmw_dmabuf_reference(buf);
stream->saved = *arg;
stream->paused = false;
return 0;
}
int vmw_overlay_stop_all(struct vmw_private *dev_priv)
{
struct vmw_overlay *overlay = dev_priv->overlay_priv;
int i, ret;
if (!overlay)
return 0;
mutex_lock(&overlay->mutex);
for (i = 0; i < VMW_MAX_NUM_STREAMS; i++) {
struct vmw_stream *stream = &overlay->stream[i];
if (!stream->buf)
continue;
ret = vmw_overlay_stop(dev_priv, i, false, false);
WARN_ON(ret != 0);
}
mutex_unlock(&overlay->mutex);
return 0;
}
int vmw_overlay_resume_all(struct vmw_private *dev_priv)
{
struct vmw_overlay *overlay = dev_priv->overlay_priv;
int i, ret;
if (!overlay)
return 0;
mutex_lock(&overlay->mutex);
for (i = 0; i < VMW_MAX_NUM_STREAMS; i++) {
struct vmw_stream *stream = &overlay->stream[i];
if (!stream->paused)
continue;
ret = vmw_overlay_update_stream(dev_priv, stream->buf,
&stream->saved, false);
if (ret != 0)
DRM_INFO("%s: *warning* failed to resume stream %i\n",
__func__, i);
}
mutex_unlock(&overlay->mutex);
return 0;
}
int vmw_overlay_pause_all(struct vmw_private *dev_priv)
{
struct vmw_overlay *overlay = dev_priv->overlay_priv;
int i, ret;
if (!overlay)
return 0;
mutex_lock(&overlay->mutex);
for (i = 0; i < VMW_MAX_NUM_STREAMS; i++) {
if (overlay->stream[i].paused)
DRM_INFO("%s: *warning* stream %i already paused\n",
__func__, i);
ret = vmw_overlay_stop(dev_priv, i, true, false);
WARN_ON(ret != 0);
}
mutex_unlock(&overlay->mutex);
return 0;
}
static bool vmw_overlay_available(const struct vmw_private *dev_priv)
{
return (dev_priv->overlay_priv != NULL &&
((dev_priv->fifo.capabilities & VMW_OVERLAY_CAP_MASK) ==
VMW_OVERLAY_CAP_MASK));
}
int vmw_overlay_ioctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct ttm_object_file *tfile = vmw_fpriv(file_priv)->tfile;
struct vmw_private *dev_priv = vmw_priv(dev);
struct vmw_overlay *overlay = dev_priv->overlay_priv;
struct drm_vmw_control_stream_arg *arg =
(struct drm_vmw_control_stream_arg *)data;
struct vmw_dma_buffer *buf;
struct vmw_resource *res;
int ret;
if (!vmw_overlay_available(dev_priv))
return -ENOSYS;
ret = vmw_user_stream_lookup(dev_priv, tfile, &arg->stream_id, &res);
if (ret)
return ret;
mutex_lock(&overlay->mutex);
if (!arg->enabled) {
ret = vmw_overlay_stop(dev_priv, arg->stream_id, false, true);
goto out_unlock;
}
ret = vmw_user_dmabuf_lookup(tfile, arg->handle, &buf, NULL);
if (ret)
goto out_unlock;
ret = vmw_overlay_update_stream(dev_priv, buf, arg, true);
vmw_dmabuf_unreference(&buf);
out_unlock:
mutex_unlock(&overlay->mutex);
vmw_resource_unreference(&res);
return ret;
}
int vmw_overlay_num_overlays(struct vmw_private *dev_priv)
{
if (!vmw_overlay_available(dev_priv))
return 0;
return VMW_MAX_NUM_STREAMS;
}
int vmw_overlay_num_free_overlays(struct vmw_private *dev_priv)
{
struct vmw_overlay *overlay = dev_priv->overlay_priv;
int i, k;
if (!vmw_overlay_available(dev_priv))
return 0;
mutex_lock(&overlay->mutex);
for (i = 0, k = 0; i < VMW_MAX_NUM_STREAMS; i++)
if (!overlay->stream[i].claimed)
k++;
mutex_unlock(&overlay->mutex);
return k;
}
int vmw_overlay_claim(struct vmw_private *dev_priv, uint32_t *out)
{
struct vmw_overlay *overlay = dev_priv->overlay_priv;
int i;
if (!overlay)
return -ENOSYS;
mutex_lock(&overlay->mutex);
for (i = 0; i < VMW_MAX_NUM_STREAMS; i++) {
if (overlay->stream[i].claimed)
continue;
overlay->stream[i].claimed = true;
*out = i;
mutex_unlock(&overlay->mutex);
return 0;
}
mutex_unlock(&overlay->mutex);
return -ESRCH;
}
int vmw_overlay_unref(struct vmw_private *dev_priv, uint32_t stream_id)
{
struct vmw_overlay *overlay = dev_priv->overlay_priv;
BUG_ON(stream_id >= VMW_MAX_NUM_STREAMS);
if (!overlay)
return -ENOSYS;
mutex_lock(&overlay->mutex);
WARN_ON(!overlay->stream[stream_id].claimed);
vmw_overlay_stop(dev_priv, stream_id, false, false);
overlay->stream[stream_id].claimed = false;
mutex_unlock(&overlay->mutex);
return 0;
}
int vmw_overlay_init(struct vmw_private *dev_priv)
{
struct vmw_overlay *overlay;
int i;
if (dev_priv->overlay_priv)
return -EINVAL;
overlay = kzalloc(sizeof(*overlay), GFP_KERNEL);
if (!overlay)
return -ENOMEM;
mutex_init(&overlay->mutex);
for (i = 0; i < VMW_MAX_NUM_STREAMS; i++) {
overlay->stream[i].buf = NULL;
overlay->stream[i].paused = false;
overlay->stream[i].claimed = false;
}
dev_priv->overlay_priv = overlay;
return 0;
}
int vmw_overlay_close(struct vmw_private *dev_priv)
{
struct vmw_overlay *overlay = dev_priv->overlay_priv;
bool forgotten_buffer = false;
int i;
if (!overlay)
return -ENOSYS;
for (i = 0; i < VMW_MAX_NUM_STREAMS; i++) {
if (overlay->stream[i].buf) {
forgotten_buffer = true;
vmw_overlay_stop(dev_priv, i, false, false);
}
}
WARN_ON(forgotten_buffer);
dev_priv->overlay_priv = NULL;
kfree(overlay);
return 0;
}
