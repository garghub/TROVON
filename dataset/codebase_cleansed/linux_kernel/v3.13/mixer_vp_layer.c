static void mxr_vp_layer_release(struct mxr_layer *layer)
{
mxr_base_layer_unregister(layer);
mxr_base_layer_release(layer);
}
static void mxr_vp_buffer_set(struct mxr_layer *layer,
struct mxr_buffer *buf)
{
dma_addr_t luma_addr[2] = {0, 0};
dma_addr_t chroma_addr[2] = {0, 0};
if (buf == NULL) {
mxr_reg_vp_buffer(layer->mdev, luma_addr, chroma_addr);
return;
}
luma_addr[0] = vb2_dma_contig_plane_dma_addr(&buf->vb, 0);
if (layer->fmt->num_subframes == 2) {
chroma_addr[0] = vb2_dma_contig_plane_dma_addr(&buf->vb, 1);
} else {
chroma_addr[0] = luma_addr[0] + mxr_get_plane_size(
&layer->fmt->plane[0], layer->geo.src.full_width,
layer->geo.src.full_height);
}
if (layer->fmt->cookie & VP_MODE_MEM_TILED) {
luma_addr[1] = luma_addr[0] + 0x40;
chroma_addr[1] = chroma_addr[0] + 0x40;
} else {
luma_addr[1] = luma_addr[0] + layer->geo.src.full_width;
chroma_addr[1] = chroma_addr[0];
}
mxr_reg_vp_buffer(layer->mdev, luma_addr, chroma_addr);
}
static void mxr_vp_stream_set(struct mxr_layer *layer, int en)
{
mxr_reg_vp_layer_stream(layer->mdev, en);
}
static void mxr_vp_format_set(struct mxr_layer *layer)
{
mxr_reg_vp_format(layer->mdev, layer->fmt, &layer->geo);
}
static inline unsigned int do_center(unsigned int center,
unsigned int size, unsigned int upper, unsigned int flags)
{
unsigned int lower;
if (flags & MXR_NO_OFFSET)
return 0;
lower = center - min(center, size / 2);
return min(lower, upper - size);
}
static void mxr_vp_fix_geometry(struct mxr_layer *layer,
enum mxr_geometry_stage stage, unsigned long flags)
{
struct mxr_geometry *geo = &layer->geo;
struct mxr_crop *src = &geo->src;
struct mxr_crop *dst = &geo->dst;
unsigned long x_center, y_center;
switch (stage) {
case MXR_GEOMETRY_SINK:
case MXR_GEOMETRY_COMPOSE:
x_center = dst->x_offset + dst->width / 2;
y_center = dst->y_offset + dst->height / 2;
dst->width = clamp(dst->width, 8U, 16 * src->full_width);
dst->height = clamp(dst->height, 1U, 16 * src->full_height);
dst->x_offset = do_center(x_center, dst->width,
dst->full_width, flags);
dst->y_offset = do_center(y_center, dst->height,
dst->full_height, flags);
flags = 0;
case MXR_GEOMETRY_CROP:
x_center = src->x_offset + src->width / 2;
y_center = src->y_offset + src->height / 2;
src->width = clamp(src->width, round_up(dst->width / 16, 4),
dst->width * 4);
src->height = clamp(src->height, round_up(dst->height / 16, 4),
dst->height * 4);
src->width = clamp(src->width, 32U, 2047U);
src->height = clamp(src->height, 4U, 2047U);
src->x_offset = do_center(x_center, src->width,
src->full_width, flags);
src->y_offset = do_center(y_center, src->height,
src->full_height, flags);
geo->x_ratio = (src->width << 16) / dst->width;
geo->y_ratio = (src->height << 16) / dst->height;
case MXR_GEOMETRY_SOURCE:
src->full_width = clamp(src->full_width,
ALIGN(src->width + src->x_offset, 8), 8192U);
src->full_height = clamp(src->full_height,
src->height + src->y_offset, 8192U);
}
}
struct mxr_layer *mxr_vp_layer_create(struct mxr_device *mdev, int idx)
{
struct mxr_layer *layer;
int ret;
struct mxr_layer_ops ops = {
.release = mxr_vp_layer_release,
.buffer_set = mxr_vp_buffer_set,
.stream_set = mxr_vp_stream_set,
.format_set = mxr_vp_format_set,
.fix_geometry = mxr_vp_fix_geometry,
};
char name[32];
sprintf(name, "video%d", idx);
layer = mxr_base_layer_create(mdev, idx, name, &ops);
if (layer == NULL) {
mxr_err(mdev, "failed to initialize layer(%d) base\n", idx);
goto fail;
}
layer->fmt_array = mxr_video_format;
layer->fmt_array_size = ARRAY_SIZE(mxr_video_format);
ret = mxr_base_layer_register(layer);
if (ret)
goto fail_layer;
return layer;
fail_layer:
mxr_base_layer_release(layer);
fail:
return NULL;
}
