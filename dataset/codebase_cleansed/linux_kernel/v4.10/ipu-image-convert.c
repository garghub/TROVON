static const struct ipu_image_pixfmt *get_format(u32 fourcc)
{
const struct ipu_image_pixfmt *ret = NULL;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(image_convert_formats); i++) {
if (image_convert_formats[i].fourcc == fourcc) {
ret = &image_convert_formats[i];
break;
}
}
return ret;
}
static void dump_format(struct ipu_image_convert_ctx *ctx,
struct ipu_image_convert_image *ic_image)
{
struct ipu_image_convert_chan *chan = ctx->chan;
struct ipu_image_convert_priv *priv = chan->priv;
dev_dbg(priv->ipu->dev,
"task %u: ctx %p: %s format: %dx%d (%dx%d tiles of size %dx%d), %c%c%c%c\n",
chan->ic_task, ctx,
ic_image->type == IMAGE_CONVERT_OUT ? "Output" : "Input",
ic_image->base.pix.width, ic_image->base.pix.height,
ic_image->num_cols, ic_image->num_rows,
ic_image->tile[0].width, ic_image->tile[0].height,
ic_image->fmt->fourcc & 0xff,
(ic_image->fmt->fourcc >> 8) & 0xff,
(ic_image->fmt->fourcc >> 16) & 0xff,
(ic_image->fmt->fourcc >> 24) & 0xff);
}
int ipu_image_convert_enum_format(int index, u32 *fourcc)
{
const struct ipu_image_pixfmt *fmt;
if (index >= (int)ARRAY_SIZE(image_convert_formats))
return -EINVAL;
fmt = &image_convert_formats[index];
*fourcc = fmt->fourcc;
return 0;
}
static void free_dma_buf(struct ipu_image_convert_priv *priv,
struct ipu_image_convert_dma_buf *buf)
{
if (buf->virt)
dma_free_coherent(priv->ipu->dev,
buf->len, buf->virt, buf->phys);
buf->virt = NULL;
buf->phys = 0;
}
static int alloc_dma_buf(struct ipu_image_convert_priv *priv,
struct ipu_image_convert_dma_buf *buf,
int size)
{
buf->len = PAGE_ALIGN(size);
buf->virt = dma_alloc_coherent(priv->ipu->dev, buf->len, &buf->phys,
GFP_DMA | GFP_KERNEL);
if (!buf->virt) {
dev_err(priv->ipu->dev, "failed to alloc dma buffer\n");
return -ENOMEM;
}
return 0;
}
static inline int num_stripes(int dim)
{
if (dim <= 1024)
return 1;
else if (dim <= 2048)
return 2;
else
return 4;
}
static void calc_tile_dimensions(struct ipu_image_convert_ctx *ctx,
struct ipu_image_convert_image *image)
{
int i;
for (i = 0; i < ctx->num_tiles; i++) {
struct ipu_image_tile *tile = &image->tile[i];
tile->height = image->base.pix.height / image->num_rows;
tile->width = image->base.pix.width / image->num_cols;
tile->size = ((tile->height * image->fmt->bpp) >> 3) *
tile->width;
if (image->fmt->planar) {
tile->stride = tile->width;
tile->rot_stride = tile->height;
} else {
tile->stride =
(image->fmt->bpp * tile->width) >> 3;
tile->rot_stride =
(image->fmt->bpp * tile->height) >> 3;
}
}
}
static int transform_tile_index(struct ipu_image_convert_ctx *ctx,
int src_row, int src_col)
{
struct ipu_image_convert_chan *chan = ctx->chan;
struct ipu_image_convert_priv *priv = chan->priv;
struct ipu_image_convert_image *s_image = &ctx->in;
struct ipu_image_convert_image *d_image = &ctx->out;
int dst_row, dst_col;
if (ctx->rot_mode == IPU_ROTATE_NONE)
return src_row * s_image->num_cols + src_col;
src_row = src_row * 2 - (s_image->num_rows - 1);
src_col = src_col * 2 - (s_image->num_cols - 1);
if (ctx->rot_mode & IPU_ROT_BIT_90) {
dst_col = -src_row;
dst_row = src_col;
} else {
dst_col = src_col;
dst_row = src_row;
}
if (ctx->rot_mode & IPU_ROT_BIT_HFLIP)
dst_col = -dst_col;
if (ctx->rot_mode & IPU_ROT_BIT_VFLIP)
dst_row = -dst_row;
dev_dbg(priv->ipu->dev, "task %u: ctx %p: [%d,%d] --> [%d,%d]\n",
chan->ic_task, ctx, src_col, src_row, dst_col, dst_row);
dst_row += d_image->num_rows - 1;
dst_col += d_image->num_cols - 1;
dst_row /= 2;
dst_col /= 2;
return dst_row * d_image->num_cols + dst_col;
}
static void calc_out_tile_map(struct ipu_image_convert_ctx *ctx)
{
struct ipu_image_convert_image *s_image = &ctx->in;
unsigned int row, col, tile = 0;
for (row = 0; row < s_image->num_rows; row++) {
for (col = 0; col < s_image->num_cols; col++) {
ctx->out_tile_map[tile] =
transform_tile_index(ctx, row, col);
tile++;
}
}
}
static void calc_tile_offsets_planar(struct ipu_image_convert_ctx *ctx,
struct ipu_image_convert_image *image)
{
struct ipu_image_convert_chan *chan = ctx->chan;
struct ipu_image_convert_priv *priv = chan->priv;
const struct ipu_image_pixfmt *fmt = image->fmt;
unsigned int row, col, tile = 0;
u32 H, w, h, y_stride, uv_stride;
u32 uv_row_off, uv_col_off, uv_off, u_off, v_off, tmp;
u32 y_row_off, y_col_off, y_off;
u32 y_size, uv_size;
H = image->base.pix.height;
y_stride = image->stride;
uv_stride = y_stride / fmt->uv_width_dec;
if (fmt->uv_packed)
uv_stride *= 2;
y_size = H * y_stride;
uv_size = y_size / (fmt->uv_width_dec * fmt->uv_height_dec);
for (row = 0; row < image->num_rows; row++) {
w = image->tile[tile].width;
h = image->tile[tile].height;
y_row_off = row * h * y_stride;
uv_row_off = (row * h * uv_stride) / fmt->uv_height_dec;
for (col = 0; col < image->num_cols; col++) {
y_col_off = col * w;
uv_col_off = y_col_off / fmt->uv_width_dec;
if (fmt->uv_packed)
uv_col_off *= 2;
y_off = y_row_off + y_col_off;
uv_off = uv_row_off + uv_col_off;
u_off = y_size - y_off + uv_off;
v_off = (fmt->uv_packed) ? 0 : u_off + uv_size;
if (fmt->uv_swapped) {
tmp = u_off;
u_off = v_off;
v_off = tmp;
}
image->tile[tile].offset = y_off;
image->tile[tile].u_off = u_off;
image->tile[tile++].v_off = v_off;
dev_dbg(priv->ipu->dev,
"task %u: ctx %p: %s@[%d,%d]: y_off %08x, u_off %08x, v_off %08x\n",
chan->ic_task, ctx,
image->type == IMAGE_CONVERT_IN ?
"Input" : "Output", row, col,
y_off, u_off, v_off);
}
}
}
static void calc_tile_offsets_packed(struct ipu_image_convert_ctx *ctx,
struct ipu_image_convert_image *image)
{
struct ipu_image_convert_chan *chan = ctx->chan;
struct ipu_image_convert_priv *priv = chan->priv;
const struct ipu_image_pixfmt *fmt = image->fmt;
unsigned int row, col, tile = 0;
u32 w, h, bpp, stride;
u32 row_off, col_off;
stride = image->stride;
bpp = fmt->bpp;
for (row = 0; row < image->num_rows; row++) {
w = image->tile[tile].width;
h = image->tile[tile].height;
row_off = row * h * stride;
for (col = 0; col < image->num_cols; col++) {
col_off = (col * w * bpp) >> 3;
image->tile[tile].offset = row_off + col_off;
image->tile[tile].u_off = 0;
image->tile[tile++].v_off = 0;
dev_dbg(priv->ipu->dev,
"task %u: ctx %p: %s@[%d,%d]: phys %08x\n",
chan->ic_task, ctx,
image->type == IMAGE_CONVERT_IN ?
"Input" : "Output", row, col,
row_off + col_off);
}
}
}
static void calc_tile_offsets(struct ipu_image_convert_ctx *ctx,
struct ipu_image_convert_image *image)
{
if (image->fmt->planar)
calc_tile_offsets_planar(ctx, image);
else
calc_tile_offsets_packed(ctx, image);
}
static int get_run_count(struct ipu_image_convert_ctx *ctx,
struct list_head *q)
{
struct ipu_image_convert_run *run;
int count = 0;
lockdep_assert_held(&ctx->chan->irqlock);
list_for_each_entry(run, q, list) {
if (run->ctx == ctx)
count++;
}
return count;
}
static void convert_stop(struct ipu_image_convert_run *run)
{
struct ipu_image_convert_ctx *ctx = run->ctx;
struct ipu_image_convert_chan *chan = ctx->chan;
struct ipu_image_convert_priv *priv = chan->priv;
dev_dbg(priv->ipu->dev, "%s: task %u: stopping ctx %p run %p\n",
__func__, chan->ic_task, ctx, run);
ipu_ic_task_disable(chan->ic);
ipu_idmac_disable_channel(chan->in_chan);
ipu_idmac_disable_channel(chan->out_chan);
if (ipu_rot_mode_is_irt(ctx->rot_mode)) {
ipu_idmac_disable_channel(chan->rotation_in_chan);
ipu_idmac_disable_channel(chan->rotation_out_chan);
ipu_idmac_unlink(chan->out_chan, chan->rotation_in_chan);
}
ipu_ic_disable(chan->ic);
}
static void init_idmac_channel(struct ipu_image_convert_ctx *ctx,
struct ipuv3_channel *channel,
struct ipu_image_convert_image *image,
enum ipu_rotate_mode rot_mode,
bool rot_swap_width_height)
{
struct ipu_image_convert_chan *chan = ctx->chan;
unsigned int burst_size;
u32 width, height, stride;
dma_addr_t addr0, addr1 = 0;
struct ipu_image tile_image;
unsigned int tile_idx[2];
if (image->type == IMAGE_CONVERT_OUT) {
tile_idx[0] = ctx->out_tile_map[0];
tile_idx[1] = ctx->out_tile_map[1];
} else {
tile_idx[0] = 0;
tile_idx[1] = 1;
}
if (rot_swap_width_height) {
width = image->tile[0].height;
height = image->tile[0].width;
stride = image->tile[0].rot_stride;
addr0 = ctx->rot_intermediate[0].phys;
if (ctx->double_buffering)
addr1 = ctx->rot_intermediate[1].phys;
} else {
width = image->tile[0].width;
height = image->tile[0].height;
stride = image->stride;
addr0 = image->base.phys0 +
image->tile[tile_idx[0]].offset;
if (ctx->double_buffering)
addr1 = image->base.phys0 +
image->tile[tile_idx[1]].offset;
}
ipu_cpmem_zero(channel);
memset(&tile_image, 0, sizeof(tile_image));
tile_image.pix.width = tile_image.rect.width = width;
tile_image.pix.height = tile_image.rect.height = height;
tile_image.pix.bytesperline = stride;
tile_image.pix.pixelformat = image->fmt->fourcc;
tile_image.phys0 = addr0;
tile_image.phys1 = addr1;
ipu_cpmem_set_image(channel, &tile_image);
if (image->fmt->planar && !rot_swap_width_height)
ipu_cpmem_set_uv_offset(channel,
image->tile[tile_idx[0]].u_off,
image->tile[tile_idx[0]].v_off);
if (rot_mode)
ipu_cpmem_set_rotation(channel, rot_mode);
if (channel == chan->rotation_in_chan ||
channel == chan->rotation_out_chan) {
burst_size = 8;
ipu_cpmem_set_block_mode(channel);
} else
burst_size = (width % 16) ? 8 : 16;
ipu_cpmem_set_burstsize(channel, burst_size);
ipu_ic_task_idma_init(chan->ic, channel, width, height,
burst_size, rot_mode);
ipu_cpmem_set_axi_id(channel, 1);
ipu_idmac_set_double_buffer(channel, ctx->double_buffering);
}
static int convert_start(struct ipu_image_convert_run *run)
{
struct ipu_image_convert_ctx *ctx = run->ctx;
struct ipu_image_convert_chan *chan = ctx->chan;
struct ipu_image_convert_priv *priv = chan->priv;
struct ipu_image_convert_image *s_image = &ctx->in;
struct ipu_image_convert_image *d_image = &ctx->out;
enum ipu_color_space src_cs, dest_cs;
unsigned int dest_width, dest_height;
int ret;
dev_dbg(priv->ipu->dev, "%s: task %u: starting ctx %p run %p\n",
__func__, chan->ic_task, ctx, run);
src_cs = ipu_pixelformat_to_colorspace(s_image->fmt->fourcc);
dest_cs = ipu_pixelformat_to_colorspace(d_image->fmt->fourcc);
if (ipu_rot_mode_is_irt(ctx->rot_mode)) {
dest_width = d_image->tile[0].height;
dest_height = d_image->tile[0].width;
} else {
dest_width = d_image->tile[0].width;
dest_height = d_image->tile[0].height;
}
ret = ipu_ic_task_init(chan->ic,
s_image->tile[0].width,
s_image->tile[0].height,
dest_width,
dest_height,
src_cs, dest_cs);
if (ret) {
dev_err(priv->ipu->dev, "ipu_ic_task_init failed, %d\n", ret);
return ret;
}
init_idmac_channel(ctx, chan->in_chan, s_image,
IPU_ROTATE_NONE, false);
if (ipu_rot_mode_is_irt(ctx->rot_mode)) {
init_idmac_channel(ctx, chan->out_chan, d_image,
IPU_ROTATE_NONE, true);
init_idmac_channel(ctx, chan->rotation_in_chan, d_image,
ctx->rot_mode, true);
init_idmac_channel(ctx, chan->rotation_out_chan, d_image,
IPU_ROTATE_NONE, false);
ipu_idmac_link(chan->out_chan, chan->rotation_in_chan);
} else {
init_idmac_channel(ctx, chan->out_chan, d_image,
ctx->rot_mode, false);
}
ipu_ic_enable(chan->ic);
ipu_idmac_select_buffer(chan->in_chan, 0);
ipu_idmac_select_buffer(chan->out_chan, 0);
if (ipu_rot_mode_is_irt(ctx->rot_mode))
ipu_idmac_select_buffer(chan->rotation_out_chan, 0);
if (ctx->double_buffering) {
ipu_idmac_select_buffer(chan->in_chan, 1);
ipu_idmac_select_buffer(chan->out_chan, 1);
if (ipu_rot_mode_is_irt(ctx->rot_mode))
ipu_idmac_select_buffer(chan->rotation_out_chan, 1);
}
ipu_idmac_enable_channel(chan->in_chan);
ipu_idmac_enable_channel(chan->out_chan);
if (ipu_rot_mode_is_irt(ctx->rot_mode)) {
ipu_idmac_enable_channel(chan->rotation_in_chan);
ipu_idmac_enable_channel(chan->rotation_out_chan);
}
ipu_ic_task_enable(chan->ic);
ipu_cpmem_dump(chan->in_chan);
ipu_cpmem_dump(chan->out_chan);
if (ipu_rot_mode_is_irt(ctx->rot_mode)) {
ipu_cpmem_dump(chan->rotation_in_chan);
ipu_cpmem_dump(chan->rotation_out_chan);
}
ipu_dump(priv->ipu);
return 0;
}
static int do_run(struct ipu_image_convert_run *run)
{
struct ipu_image_convert_ctx *ctx = run->ctx;
struct ipu_image_convert_chan *chan = ctx->chan;
lockdep_assert_held(&chan->irqlock);
ctx->in.base.phys0 = run->in_phys;
ctx->out.base.phys0 = run->out_phys;
ctx->cur_buf_num = 0;
ctx->next_tile = 1;
list_del(&run->list);
chan->current_run = run;
return convert_start(run);
}
static void run_next(struct ipu_image_convert_chan *chan)
{
struct ipu_image_convert_priv *priv = chan->priv;
struct ipu_image_convert_run *run, *tmp;
int ret;
lockdep_assert_held(&chan->irqlock);
list_for_each_entry_safe(run, tmp, &chan->pending_q, list) {
if (run->ctx->aborting) {
dev_dbg(priv->ipu->dev,
"%s: task %u: skipping aborting ctx %p run %p\n",
__func__, chan->ic_task, run->ctx, run);
continue;
}
ret = do_run(run);
if (!ret)
break;
run->status = ret;
list_add_tail(&run->list, &chan->done_q);
chan->current_run = NULL;
}
}
static void empty_done_q(struct ipu_image_convert_chan *chan)
{
struct ipu_image_convert_priv *priv = chan->priv;
struct ipu_image_convert_run *run;
unsigned long flags;
spin_lock_irqsave(&chan->irqlock, flags);
while (!list_empty(&chan->done_q)) {
run = list_entry(chan->done_q.next,
struct ipu_image_convert_run,
list);
list_del(&run->list);
dev_dbg(priv->ipu->dev,
"%s: task %u: completing ctx %p run %p with %d\n",
__func__, chan->ic_task, run->ctx, run, run->status);
spin_unlock_irqrestore(&chan->irqlock, flags);
run->ctx->complete(run, run->ctx->complete_context);
spin_lock_irqsave(&chan->irqlock, flags);
}
spin_unlock_irqrestore(&chan->irqlock, flags);
}
static irqreturn_t do_bh(int irq, void *dev_id)
{
struct ipu_image_convert_chan *chan = dev_id;
struct ipu_image_convert_priv *priv = chan->priv;
struct ipu_image_convert_ctx *ctx;
unsigned long flags;
dev_dbg(priv->ipu->dev, "%s: task %u: enter\n", __func__,
chan->ic_task);
empty_done_q(chan);
spin_lock_irqsave(&chan->irqlock, flags);
list_for_each_entry(ctx, &chan->ctx_list, list) {
if (ctx->aborting) {
dev_dbg(priv->ipu->dev,
"%s: task %u: signaling abort for ctx %p\n",
__func__, chan->ic_task, ctx);
complete(&ctx->aborted);
}
}
spin_unlock_irqrestore(&chan->irqlock, flags);
dev_dbg(priv->ipu->dev, "%s: task %u: exit\n", __func__,
chan->ic_task);
return IRQ_HANDLED;
}
static irqreturn_t do_irq(struct ipu_image_convert_run *run)
{
struct ipu_image_convert_ctx *ctx = run->ctx;
struct ipu_image_convert_chan *chan = ctx->chan;
struct ipu_image_tile *src_tile, *dst_tile;
struct ipu_image_convert_image *s_image = &ctx->in;
struct ipu_image_convert_image *d_image = &ctx->out;
struct ipuv3_channel *outch;
unsigned int dst_idx;
lockdep_assert_held(&chan->irqlock);
outch = ipu_rot_mode_is_irt(ctx->rot_mode) ?
chan->rotation_out_chan : chan->out_chan;
if (ctx->aborting && !ctx->double_buffering) {
convert_stop(run);
run->status = -EIO;
goto done;
}
if (ctx->next_tile == ctx->num_tiles) {
convert_stop(run);
run->status = 0;
goto done;
}
if (!ctx->double_buffering) {
src_tile = &s_image->tile[ctx->next_tile];
dst_idx = ctx->out_tile_map[ctx->next_tile];
dst_tile = &d_image->tile[dst_idx];
ipu_cpmem_set_buffer(chan->in_chan, 0,
s_image->base.phys0 + src_tile->offset);
ipu_cpmem_set_buffer(outch, 0,
d_image->base.phys0 + dst_tile->offset);
if (s_image->fmt->planar)
ipu_cpmem_set_uv_offset(chan->in_chan,
src_tile->u_off,
src_tile->v_off);
if (d_image->fmt->planar)
ipu_cpmem_set_uv_offset(outch,
dst_tile->u_off,
dst_tile->v_off);
ipu_idmac_select_buffer(chan->in_chan, 0);
ipu_idmac_select_buffer(outch, 0);
} else if (ctx->next_tile < ctx->num_tiles - 1) {
src_tile = &s_image->tile[ctx->next_tile + 1];
dst_idx = ctx->out_tile_map[ctx->next_tile + 1];
dst_tile = &d_image->tile[dst_idx];
ipu_cpmem_set_buffer(chan->in_chan, ctx->cur_buf_num,
s_image->base.phys0 + src_tile->offset);
ipu_cpmem_set_buffer(outch, ctx->cur_buf_num,
d_image->base.phys0 + dst_tile->offset);
ipu_idmac_select_buffer(chan->in_chan, ctx->cur_buf_num);
ipu_idmac_select_buffer(outch, ctx->cur_buf_num);
ctx->cur_buf_num ^= 1;
}
ctx->next_tile++;
return IRQ_HANDLED;
done:
list_add_tail(&run->list, &chan->done_q);
chan->current_run = NULL;
run_next(chan);
return IRQ_WAKE_THREAD;
}
static irqreturn_t norotate_irq(int irq, void *data)
{
struct ipu_image_convert_chan *chan = data;
struct ipu_image_convert_ctx *ctx;
struct ipu_image_convert_run *run;
unsigned long flags;
irqreturn_t ret;
spin_lock_irqsave(&chan->irqlock, flags);
run = chan->current_run;
if (!run) {
ret = IRQ_NONE;
goto out;
}
ctx = run->ctx;
if (ipu_rot_mode_is_irt(ctx->rot_mode)) {
spin_unlock_irqrestore(&chan->irqlock, flags);
return IRQ_HANDLED;
}
ret = do_irq(run);
out:
spin_unlock_irqrestore(&chan->irqlock, flags);
return ret;
}
static irqreturn_t rotate_irq(int irq, void *data)
{
struct ipu_image_convert_chan *chan = data;
struct ipu_image_convert_priv *priv = chan->priv;
struct ipu_image_convert_ctx *ctx;
struct ipu_image_convert_run *run;
unsigned long flags;
irqreturn_t ret;
spin_lock_irqsave(&chan->irqlock, flags);
run = chan->current_run;
if (!run) {
ret = IRQ_NONE;
goto out;
}
ctx = run->ctx;
if (!ipu_rot_mode_is_irt(ctx->rot_mode)) {
dev_err(priv->ipu->dev, "Unexpected rotation interrupt\n");
spin_unlock_irqrestore(&chan->irqlock, flags);
return IRQ_HANDLED;
}
ret = do_irq(run);
out:
spin_unlock_irqrestore(&chan->irqlock, flags);
return ret;
}
static void force_abort(struct ipu_image_convert_ctx *ctx)
{
struct ipu_image_convert_chan *chan = ctx->chan;
struct ipu_image_convert_run *run;
unsigned long flags;
spin_lock_irqsave(&chan->irqlock, flags);
run = chan->current_run;
if (run && run->ctx == ctx) {
convert_stop(run);
run->status = -EIO;
list_add_tail(&run->list, &chan->done_q);
chan->current_run = NULL;
run_next(chan);
}
spin_unlock_irqrestore(&chan->irqlock, flags);
empty_done_q(chan);
}
static void release_ipu_resources(struct ipu_image_convert_chan *chan)
{
if (chan->out_eof_irq >= 0)
free_irq(chan->out_eof_irq, chan);
if (chan->rot_out_eof_irq >= 0)
free_irq(chan->rot_out_eof_irq, chan);
if (!IS_ERR_OR_NULL(chan->in_chan))
ipu_idmac_put(chan->in_chan);
if (!IS_ERR_OR_NULL(chan->out_chan))
ipu_idmac_put(chan->out_chan);
if (!IS_ERR_OR_NULL(chan->rotation_in_chan))
ipu_idmac_put(chan->rotation_in_chan);
if (!IS_ERR_OR_NULL(chan->rotation_out_chan))
ipu_idmac_put(chan->rotation_out_chan);
if (!IS_ERR_OR_NULL(chan->ic))
ipu_ic_put(chan->ic);
chan->in_chan = chan->out_chan = chan->rotation_in_chan =
chan->rotation_out_chan = NULL;
chan->out_eof_irq = chan->rot_out_eof_irq = -1;
}
static int get_ipu_resources(struct ipu_image_convert_chan *chan)
{
const struct ipu_image_convert_dma_chan *dma = chan->dma_ch;
struct ipu_image_convert_priv *priv = chan->priv;
int ret;
chan->ic = ipu_ic_get(priv->ipu, chan->ic_task);
if (IS_ERR(chan->ic)) {
dev_err(priv->ipu->dev, "could not acquire IC\n");
ret = PTR_ERR(chan->ic);
goto err;
}
chan->in_chan = ipu_idmac_get(priv->ipu, dma->in);
chan->out_chan = ipu_idmac_get(priv->ipu, dma->out);
if (IS_ERR(chan->in_chan) || IS_ERR(chan->out_chan)) {
dev_err(priv->ipu->dev, "could not acquire idmac channels\n");
ret = -EBUSY;
goto err;
}
chan->rotation_in_chan = ipu_idmac_get(priv->ipu, dma->rot_in);
chan->rotation_out_chan = ipu_idmac_get(priv->ipu, dma->rot_out);
if (IS_ERR(chan->rotation_in_chan) || IS_ERR(chan->rotation_out_chan)) {
dev_err(priv->ipu->dev,
"could not acquire idmac rotation channels\n");
ret = -EBUSY;
goto err;
}
chan->out_eof_irq = ipu_idmac_channel_irq(priv->ipu,
chan->out_chan,
IPU_IRQ_EOF);
ret = request_threaded_irq(chan->out_eof_irq, norotate_irq, do_bh,
0, "ipu-ic", chan);
if (ret < 0) {
dev_err(priv->ipu->dev, "could not acquire irq %d\n",
chan->out_eof_irq);
chan->out_eof_irq = -1;
goto err;
}
chan->rot_out_eof_irq = ipu_idmac_channel_irq(priv->ipu,
chan->rotation_out_chan,
IPU_IRQ_EOF);
ret = request_threaded_irq(chan->rot_out_eof_irq, rotate_irq, do_bh,
0, "ipu-ic", chan);
if (ret < 0) {
dev_err(priv->ipu->dev, "could not acquire irq %d\n",
chan->rot_out_eof_irq);
chan->rot_out_eof_irq = -1;
goto err;
}
return 0;
err:
release_ipu_resources(chan);
return ret;
}
static int fill_image(struct ipu_image_convert_ctx *ctx,
struct ipu_image_convert_image *ic_image,
struct ipu_image *image,
enum ipu_image_convert_type type)
{
struct ipu_image_convert_priv *priv = ctx->chan->priv;
ic_image->base = *image;
ic_image->type = type;
ic_image->fmt = get_format(image->pix.pixelformat);
if (!ic_image->fmt) {
dev_err(priv->ipu->dev, "pixelformat not supported for %s\n",
type == IMAGE_CONVERT_OUT ? "Output" : "Input");
return -EINVAL;
}
if (ic_image->fmt->planar)
ic_image->stride = ic_image->base.pix.width;
else
ic_image->stride = ic_image->base.pix.bytesperline;
calc_tile_dimensions(ctx, ic_image);
calc_tile_offsets(ctx, ic_image);
return 0;
}
static unsigned int clamp_align(unsigned int x, unsigned int min,
unsigned int max, unsigned int align)
{
unsigned int mask = ~((1 << align) - 1);
x = clamp(x, (min + ~mask) & mask, max & mask);
if (align)
x = (x + (1 << (align - 1))) & mask;
return x;
}
static inline u32 tile_width_align(const struct ipu_image_pixfmt *fmt)
{
return fmt->planar ? 8 * fmt->uv_width_dec : 8;
}
static inline u32 tile_height_align(enum ipu_image_convert_type type,
enum ipu_rotate_mode rot_mode)
{
return (type == IMAGE_CONVERT_OUT &&
ipu_rot_mode_is_irt(rot_mode)) ? 8 : 2;
}
void ipu_image_convert_adjust(struct ipu_image *in, struct ipu_image *out,
enum ipu_rotate_mode rot_mode)
{
const struct ipu_image_pixfmt *infmt, *outfmt;
unsigned int num_in_rows, num_in_cols;
unsigned int num_out_rows, num_out_cols;
u32 w_align, h_align;
infmt = get_format(in->pix.pixelformat);
outfmt = get_format(out->pix.pixelformat);
if (!infmt) {
in->pix.pixelformat = V4L2_PIX_FMT_RGB24;
infmt = get_format(V4L2_PIX_FMT_RGB24);
}
if (!outfmt) {
out->pix.pixelformat = V4L2_PIX_FMT_RGB24;
outfmt = get_format(V4L2_PIX_FMT_RGB24);
}
in->pix.field = out->pix.field = V4L2_FIELD_NONE;
if (ipu_rot_mode_is_irt(rot_mode)) {
out->pix.height = max_t(__u32, out->pix.height,
in->pix.width / 4);
out->pix.width = max_t(__u32, out->pix.width,
in->pix.height / 4);
} else {
out->pix.width = max_t(__u32, out->pix.width,
in->pix.width / 4);
out->pix.height = max_t(__u32, out->pix.height,
in->pix.height / 4);
}
num_out_rows = num_stripes(out->pix.height);
num_out_cols = num_stripes(out->pix.width);
if (ipu_rot_mode_is_irt(rot_mode)) {
num_in_rows = num_out_cols;
num_in_cols = num_out_rows;
} else {
num_in_rows = num_out_rows;
num_in_cols = num_out_cols;
}
w_align = ilog2(tile_width_align(infmt) * num_in_cols);
h_align = ilog2(tile_height_align(IMAGE_CONVERT_IN, rot_mode) *
num_in_rows);
in->pix.width = clamp_align(in->pix.width, MIN_W, MAX_W, w_align);
in->pix.height = clamp_align(in->pix.height, MIN_H, MAX_H, h_align);
w_align = ilog2(tile_width_align(outfmt) * num_out_cols);
h_align = ilog2(tile_height_align(IMAGE_CONVERT_OUT, rot_mode) *
num_out_rows);
out->pix.width = clamp_align(out->pix.width, MIN_W, MAX_W, w_align);
out->pix.height = clamp_align(out->pix.height, MIN_H, MAX_H, h_align);
in->pix.bytesperline = (in->pix.width * infmt->bpp) >> 3;
in->pix.sizeimage = in->pix.height * in->pix.bytesperline;
out->pix.bytesperline = (out->pix.width * outfmt->bpp) >> 3;
out->pix.sizeimage = out->pix.height * out->pix.bytesperline;
}
int ipu_image_convert_verify(struct ipu_image *in, struct ipu_image *out,
enum ipu_rotate_mode rot_mode)
{
struct ipu_image testin, testout;
testin = *in;
testout = *out;
ipu_image_convert_adjust(&testin, &testout, rot_mode);
if (testin.pix.width != in->pix.width ||
testin.pix.height != in->pix.height ||
testout.pix.width != out->pix.width ||
testout.pix.height != out->pix.height)
return -EINVAL;
return 0;
}
struct ipu_image_convert_ctx *
ipu_image_convert_prepare(struct ipu_soc *ipu, enum ipu_ic_task ic_task,
struct ipu_image *in, struct ipu_image *out,
enum ipu_rotate_mode rot_mode,
ipu_image_convert_cb_t complete,
void *complete_context)
{
struct ipu_image_convert_priv *priv = ipu->image_convert_priv;
struct ipu_image_convert_image *s_image, *d_image;
struct ipu_image_convert_chan *chan;
struct ipu_image_convert_ctx *ctx;
unsigned long flags;
bool get_res;
int ret;
if (!in || !out || !complete ||
(ic_task != IC_TASK_VIEWFINDER &&
ic_task != IC_TASK_POST_PROCESSOR))
return ERR_PTR(-EINVAL);
ret = ipu_image_convert_verify(in, out, rot_mode);
if (ret) {
dev_err(priv->ipu->dev, "%s: in/out formats invalid\n",
__func__);
return ERR_PTR(ret);
}
chan = &priv->chan[ic_task];
ctx = kzalloc(sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return ERR_PTR(-ENOMEM);
dev_dbg(priv->ipu->dev, "%s: task %u: ctx %p\n", __func__,
chan->ic_task, ctx);
ctx->chan = chan;
init_completion(&ctx->aborted);
s_image = &ctx->in;
d_image = &ctx->out;
d_image->num_rows = num_stripes(out->pix.height);
d_image->num_cols = num_stripes(out->pix.width);
if (ipu_rot_mode_is_irt(rot_mode)) {
s_image->num_rows = d_image->num_cols;
s_image->num_cols = d_image->num_rows;
} else {
s_image->num_rows = d_image->num_rows;
s_image->num_cols = d_image->num_cols;
}
ctx->num_tiles = d_image->num_cols * d_image->num_rows;
ctx->rot_mode = rot_mode;
ret = fill_image(ctx, s_image, in, IMAGE_CONVERT_IN);
if (ret)
goto out_free;
ret = fill_image(ctx, d_image, out, IMAGE_CONVERT_OUT);
if (ret)
goto out_free;
calc_out_tile_map(ctx);
dump_format(ctx, s_image);
dump_format(ctx, d_image);
ctx->complete = complete;
ctx->complete_context = complete_context;
ctx->double_buffering = (ctx->num_tiles > 1 &&
!s_image->fmt->planar &&
!d_image->fmt->planar);
if (ipu_rot_mode_is_irt(ctx->rot_mode)) {
ret = alloc_dma_buf(priv, &ctx->rot_intermediate[0],
d_image->tile[0].size);
if (ret)
goto out_free;
if (ctx->double_buffering) {
ret = alloc_dma_buf(priv,
&ctx->rot_intermediate[1],
d_image->tile[0].size);
if (ret)
goto out_free_dmabuf0;
}
}
spin_lock_irqsave(&chan->irqlock, flags);
get_res = list_empty(&chan->ctx_list);
list_add_tail(&ctx->list, &chan->ctx_list);
spin_unlock_irqrestore(&chan->irqlock, flags);
if (get_res) {
ret = get_ipu_resources(chan);
if (ret)
goto out_free_dmabuf1;
}
return ctx;
out_free_dmabuf1:
free_dma_buf(priv, &ctx->rot_intermediate[1]);
spin_lock_irqsave(&chan->irqlock, flags);
list_del(&ctx->list);
spin_unlock_irqrestore(&chan->irqlock, flags);
out_free_dmabuf0:
free_dma_buf(priv, &ctx->rot_intermediate[0]);
out_free:
kfree(ctx);
return ERR_PTR(ret);
}
int ipu_image_convert_queue(struct ipu_image_convert_run *run)
{
struct ipu_image_convert_chan *chan;
struct ipu_image_convert_priv *priv;
struct ipu_image_convert_ctx *ctx;
unsigned long flags;
int ret = 0;
if (!run || !run->ctx || !run->in_phys || !run->out_phys)
return -EINVAL;
ctx = run->ctx;
chan = ctx->chan;
priv = chan->priv;
dev_dbg(priv->ipu->dev, "%s: task %u: ctx %p run %p\n", __func__,
chan->ic_task, ctx, run);
INIT_LIST_HEAD(&run->list);
spin_lock_irqsave(&chan->irqlock, flags);
if (ctx->aborting) {
ret = -EIO;
goto unlock;
}
list_add_tail(&run->list, &chan->pending_q);
if (!chan->current_run) {
ret = do_run(run);
if (ret)
chan->current_run = NULL;
}
unlock:
spin_unlock_irqrestore(&chan->irqlock, flags);
return ret;
}
void ipu_image_convert_abort(struct ipu_image_convert_ctx *ctx)
{
struct ipu_image_convert_chan *chan = ctx->chan;
struct ipu_image_convert_priv *priv = chan->priv;
struct ipu_image_convert_run *run, *active_run, *tmp;
unsigned long flags;
int run_count, ret;
bool need_abort;
reinit_completion(&ctx->aborted);
spin_lock_irqsave(&chan->irqlock, flags);
list_for_each_entry_safe(run, tmp, &chan->pending_q, list) {
if (run->ctx != ctx)
continue;
run->status = -EIO;
list_move_tail(&run->list, &chan->done_q);
}
run_count = get_run_count(ctx, &chan->done_q);
active_run = (chan->current_run && chan->current_run->ctx == ctx) ?
chan->current_run : NULL;
need_abort = (run_count || active_run);
ctx->aborting = need_abort;
spin_unlock_irqrestore(&chan->irqlock, flags);
if (!need_abort) {
dev_dbg(priv->ipu->dev,
"%s: task %u: no abort needed for ctx %p\n",
__func__, chan->ic_task, ctx);
return;
}
dev_dbg(priv->ipu->dev,
"%s: task %u: wait for completion: %d runs, active run %p\n",
__func__, chan->ic_task, run_count, active_run);
ret = wait_for_completion_timeout(&ctx->aborted,
msecs_to_jiffies(10000));
if (ret == 0) {
dev_warn(priv->ipu->dev, "%s: timeout\n", __func__);
force_abort(ctx);
}
ctx->aborting = false;
}
void ipu_image_convert_unprepare(struct ipu_image_convert_ctx *ctx)
{
struct ipu_image_convert_chan *chan = ctx->chan;
struct ipu_image_convert_priv *priv = chan->priv;
unsigned long flags;
bool put_res;
ipu_image_convert_abort(ctx);
dev_dbg(priv->ipu->dev, "%s: task %u: removing ctx %p\n", __func__,
chan->ic_task, ctx);
spin_lock_irqsave(&chan->irqlock, flags);
list_del(&ctx->list);
put_res = list_empty(&chan->ctx_list);
spin_unlock_irqrestore(&chan->irqlock, flags);
if (put_res)
release_ipu_resources(chan);
free_dma_buf(priv, &ctx->rot_intermediate[1]);
free_dma_buf(priv, &ctx->rot_intermediate[0]);
kfree(ctx);
}
struct ipu_image_convert_run *
ipu_image_convert(struct ipu_soc *ipu, enum ipu_ic_task ic_task,
struct ipu_image *in, struct ipu_image *out,
enum ipu_rotate_mode rot_mode,
ipu_image_convert_cb_t complete,
void *complete_context)
{
struct ipu_image_convert_ctx *ctx;
struct ipu_image_convert_run *run;
int ret;
ctx = ipu_image_convert_prepare(ipu, ic_task, in, out, rot_mode,
complete, complete_context);
if (IS_ERR(ctx))
return ERR_CAST(ctx);
run = kzalloc(sizeof(*run), GFP_KERNEL);
if (!run) {
ipu_image_convert_unprepare(ctx);
return ERR_PTR(-ENOMEM);
}
run->ctx = ctx;
run->in_phys = in->phys0;
run->out_phys = out->phys0;
ret = ipu_image_convert_queue(run);
if (ret) {
ipu_image_convert_unprepare(ctx);
kfree(run);
return ERR_PTR(ret);
}
return run;
}
static void image_convert_sync_complete(struct ipu_image_convert_run *run,
void *data)
{
struct completion *comp = data;
complete(comp);
}
int ipu_image_convert_sync(struct ipu_soc *ipu, enum ipu_ic_task ic_task,
struct ipu_image *in, struct ipu_image *out,
enum ipu_rotate_mode rot_mode)
{
struct ipu_image_convert_run *run;
struct completion comp;
int ret;
init_completion(&comp);
run = ipu_image_convert(ipu, ic_task, in, out, rot_mode,
image_convert_sync_complete, &comp);
if (IS_ERR(run))
return PTR_ERR(run);
ret = wait_for_completion_timeout(&comp, msecs_to_jiffies(10000));
ret = (ret == 0) ? -ETIMEDOUT : 0;
ipu_image_convert_unprepare(run->ctx);
kfree(run);
return ret;
}
int ipu_image_convert_init(struct ipu_soc *ipu, struct device *dev)
{
struct ipu_image_convert_priv *priv;
int i;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
ipu->image_convert_priv = priv;
priv->ipu = ipu;
for (i = 0; i < IC_NUM_TASKS; i++) {
struct ipu_image_convert_chan *chan = &priv->chan[i];
chan->ic_task = i;
chan->priv = priv;
chan->dma_ch = &image_convert_dma_chan[i];
chan->out_eof_irq = -1;
chan->rot_out_eof_irq = -1;
spin_lock_init(&chan->irqlock);
INIT_LIST_HEAD(&chan->ctx_list);
INIT_LIST_HEAD(&chan->pending_q);
INIT_LIST_HEAD(&chan->done_q);
}
return 0;
}
void ipu_image_convert_exit(struct ipu_soc *ipu)
{
}
