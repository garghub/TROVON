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
luma_addr[0] = vb2_dma_contig_plane_paddr(&buf->vb, 0);
if (layer->fmt->num_subframes == 2) {
chroma_addr[0] = vb2_dma_contig_plane_paddr(&buf->vb, 1);
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
static void mxr_vp_fix_geometry(struct mxr_layer *layer)
{
struct mxr_geometry *geo = &layer->geo;
geo->src.full_width = ALIGN(geo->src.full_width, 8);
geo->src.full_width = clamp_val(geo->src.full_width, 8, 8192);
geo->src.full_height = clamp_val(geo->src.full_height, 1, 8192);
geo->src.width = clamp_val(geo->src.width, 32, geo->src.full_width);
geo->src.width = min(geo->src.width, 2047U);
geo->src.height = clamp_val(geo->src.height, 4, geo->src.full_height);
geo->src.height = min(geo->src.height, 2047U);
geo->dst.width = clamp_val(geo->dst.width, 8, geo->dst.full_width);
geo->dst.height = clamp_val(geo->dst.height, 1, geo->dst.full_height);
if (geo->src.width >= 4 * geo->dst.width)
geo->src.width = 4 * geo->dst.width;
if (geo->dst.width >= 16 * geo->src.width)
geo->dst.width = 16 * geo->src.width;
if (geo->src.height >= 4 * geo->dst.height)
geo->src.height = 4 * geo->dst.height;
if (geo->dst.height >= 16 * geo->src.height)
geo->dst.height = 16 * geo->src.height;
geo->x_ratio = (geo->src.width << 16) / geo->dst.width;
geo->y_ratio = (geo->src.height << 16) / geo->dst.height;
geo->src.x_offset = min(geo->src.x_offset,
geo->src.full_width - geo->src.width);
geo->src.y_offset = min(geo->src.y_offset,
geo->src.full_height - geo->src.height);
geo->dst.x_offset = min(geo->dst.x_offset,
geo->dst.full_width - geo->dst.width);
geo->dst.y_offset = min(geo->dst.y_offset,
geo->dst.full_height - geo->dst.height);
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
