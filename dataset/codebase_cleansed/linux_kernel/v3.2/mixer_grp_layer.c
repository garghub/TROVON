static void mxr_graph_layer_release(struct mxr_layer *layer)
{
mxr_base_layer_unregister(layer);
mxr_base_layer_release(layer);
}
static void mxr_graph_buffer_set(struct mxr_layer *layer,
struct mxr_buffer *buf)
{
dma_addr_t addr = 0;
if (buf)
addr = vb2_dma_contig_plane_dma_addr(&buf->vb, 0);
mxr_reg_graph_buffer(layer->mdev, layer->idx, addr);
}
static void mxr_graph_stream_set(struct mxr_layer *layer, int en)
{
mxr_reg_graph_layer_stream(layer->mdev, layer->idx, en);
}
static void mxr_graph_format_set(struct mxr_layer *layer)
{
mxr_reg_graph_format(layer->mdev, layer->idx,
layer->fmt, &layer->geo);
}
static void mxr_graph_fix_geometry(struct mxr_layer *layer)
{
struct mxr_geometry *geo = &layer->geo;
geo->src.full_width = clamp_val(geo->src.full_width, 1, 32767);
geo->src.full_height = clamp_val(geo->src.full_height, 1, 2047);
geo->src.width = clamp_val(geo->src.width, 1, geo->src.full_width);
geo->src.width = min(geo->src.width, 2047U);
geo->src.y_offset = min(geo->src.y_offset, geo->src.full_height - 1);
geo->src.height = geo->src.full_height - geo->src.y_offset;
geo->src.x_offset = min(geo->src.x_offset,
geo->src.full_width - geo->src.width);
geo->dst.width = min(geo->dst.width, geo->dst.full_width);
geo->dst.height = min(geo->dst.height, geo->dst.full_height);
if (geo->dst.width >= 2 * geo->src.width) {
geo->x_ratio = 1;
geo->dst.width = 2 * geo->src.width;
} else {
geo->x_ratio = 0;
geo->dst.width = geo->src.width;
}
if (geo->dst.height >= 2 * geo->src.height) {
geo->y_ratio = 1;
geo->dst.height = 2 * geo->src.height;
} else {
geo->y_ratio = 0;
geo->dst.height = geo->src.height;
}
geo->dst.x_offset = min(geo->dst.x_offset,
geo->dst.full_width - geo->dst.width);
geo->dst.y_offset = min(geo->dst.y_offset,
geo->dst.full_height - geo->dst.height);
}
struct mxr_layer *mxr_graph_layer_create(struct mxr_device *mdev, int idx)
{
struct mxr_layer *layer;
int ret;
struct mxr_layer_ops ops = {
.release = mxr_graph_layer_release,
.buffer_set = mxr_graph_buffer_set,
.stream_set = mxr_graph_stream_set,
.format_set = mxr_graph_format_set,
.fix_geometry = mxr_graph_fix_geometry,
};
char name[32];
sprintf(name, "graph%d", idx);
layer = mxr_base_layer_create(mdev, idx, name, &ops);
if (layer == NULL) {
mxr_err(mdev, "failed to initialize layer(%d) base\n", idx);
goto fail;
}
layer->fmt_array = mxr_graph_format;
layer->fmt_array_size = ARRAY_SIZE(mxr_graph_format);
ret = mxr_base_layer_register(layer);
if (ret)
goto fail_layer;
return layer;
fail_layer:
mxr_base_layer_release(layer);
fail:
return NULL;
}
