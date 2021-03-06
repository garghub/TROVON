static int vbi_buffer_setup(struct videobuf_queue *q,
unsigned int *count, unsigned int *size)
{
struct bttv_fh *fh = q->priv_data;
struct bttv *btv = fh->btv;
if (0 == *count)
*count = vbibufs;
*size = IMAGE_SIZE(&fh->vbi_fmt.fmt);
dprintk("setup: samples=%u start=%d,%d count=%u,%u\n",
fh->vbi_fmt.fmt.samples_per_line,
fh->vbi_fmt.fmt.start[0],
fh->vbi_fmt.fmt.start[1],
fh->vbi_fmt.fmt.count[0],
fh->vbi_fmt.fmt.count[1]);
return 0;
}
static int vbi_buffer_prepare(struct videobuf_queue *q,
struct videobuf_buffer *vb,
enum v4l2_field field)
{
struct bttv_fh *fh = q->priv_data;
struct bttv *btv = fh->btv;
struct bttv_buffer *buf = container_of(vb,struct bttv_buffer,vb);
const struct bttv_tvnorm *tvnorm;
unsigned int skip_lines0, skip_lines1, min_vdelay;
int redo_dma_risc;
int rc;
buf->vb.size = IMAGE_SIZE(&fh->vbi_fmt.fmt);
if (0 != buf->vb.baddr && buf->vb.bsize < buf->vb.size)
return -EINVAL;
tvnorm = fh->vbi_fmt.tvnorm;
skip_lines0 = 0;
skip_lines1 = 0;
if (fh->vbi_fmt.fmt.count[0] > 0)
skip_lines0 = max(0, (fh->vbi_fmt.fmt.start[0]
- tvnorm->vbistart[0]));
if (fh->vbi_fmt.fmt.count[1] > 0)
skip_lines1 = max(0, (fh->vbi_fmt.fmt.start[1]
- tvnorm->vbistart[1]));
redo_dma_risc = 0;
if (buf->vbi_skip[0] != skip_lines0 ||
buf->vbi_skip[1] != skip_lines1 ||
buf->vbi_count[0] != fh->vbi_fmt.fmt.count[0] ||
buf->vbi_count[1] != fh->vbi_fmt.fmt.count[1]) {
buf->vbi_skip[0] = skip_lines0;
buf->vbi_skip[1] = skip_lines1;
buf->vbi_count[0] = fh->vbi_fmt.fmt.count[0];
buf->vbi_count[1] = fh->vbi_fmt.fmt.count[1];
redo_dma_risc = 1;
}
if (VIDEOBUF_NEEDS_INIT == buf->vb.state) {
redo_dma_risc = 1;
if (0 != (rc = videobuf_iolock(q, &buf->vb, NULL)))
goto fail;
}
if (redo_dma_risc) {
unsigned int bpl, padding, offset;
struct videobuf_dmabuf *dma=videobuf_to_dma(&buf->vb);
bpl = 2044;
padding = VBI_BPL - bpl;
if (fh->vbi_fmt.fmt.count[0] > 0) {
rc = bttv_risc_packed(btv, &buf->top,
dma->sglist,
0, bpl,
padding, skip_lines0,
fh->vbi_fmt.fmt.count[0]);
if (0 != rc)
goto fail;
}
if (fh->vbi_fmt.fmt.count[1] > 0) {
offset = fh->vbi_fmt.fmt.count[0] * VBI_BPL;
rc = bttv_risc_packed(btv, &buf->bottom,
dma->sglist,
offset, bpl,
padding, skip_lines1,
fh->vbi_fmt.fmt.count[1]);
if (0 != rc)
goto fail;
}
}
min_vdelay = MIN_VDELAY;
if (fh->vbi_fmt.end >= tvnorm->cropcap.bounds.top)
min_vdelay += fh->vbi_fmt.end - tvnorm->cropcap.bounds.top;
buf->geo.vdelay = min_vdelay;
buf->vb.state = VIDEOBUF_PREPARED;
buf->vb.field = field;
dprintk("buf prepare %p: top=%p bottom=%p field=%s\n",
vb, &buf->top, &buf->bottom,
v4l2_field_names[buf->vb.field]);
return 0;
fail:
bttv_dma_free(q,btv,buf);
return rc;
}
static void
vbi_buffer_queue(struct videobuf_queue *q, struct videobuf_buffer *vb)
{
struct bttv_fh *fh = q->priv_data;
struct bttv *btv = fh->btv;
struct bttv_buffer *buf = container_of(vb,struct bttv_buffer,vb);
dprintk("queue %p\n",vb);
buf->vb.state = VIDEOBUF_QUEUED;
list_add_tail(&buf->vb.queue,&btv->vcapture);
if (NULL == btv->cvbi) {
fh->btv->loop_irq |= 4;
bttv_set_dma(btv,0x0c);
}
}
static void vbi_buffer_release(struct videobuf_queue *q, struct videobuf_buffer *vb)
{
struct bttv_fh *fh = q->priv_data;
struct bttv *btv = fh->btv;
struct bttv_buffer *buf = container_of(vb,struct bttv_buffer,vb);
dprintk("free %p\n",vb);
bttv_dma_free(q,fh->btv,buf);
}
static int try_fmt(struct v4l2_vbi_format *f, const struct bttv_tvnorm *tvnorm,
__s32 crop_start)
{
__s32 min_start, max_start, max_end, f2_offset;
unsigned int i;
min_start = tvnorm->vbistart[0];
max_start = (crop_start >> 1) - 1;
max_end = (tvnorm->cropcap.bounds.top
+ tvnorm->cropcap.bounds.height) >> 1;
if (min_start > max_start)
return -EBUSY;
BUG_ON(max_start >= max_end);
f->sampling_rate = tvnorm->Fsc;
f->samples_per_line = VBI_BPL;
f->sample_format = V4L2_PIX_FMT_GREY;
f->offset = VBI_OFFSET;
f2_offset = tvnorm->vbistart[1] - tvnorm->vbistart[0];
for (i = 0; i < 2; ++i) {
if (0 == f->count[i]) {
} else {
s64 start, count;
start = clamp(f->start[i], min_start, max_start);
count = (s64) f->start[i] + f->count[i] - start;
f->start[i] = start;
f->count[i] = clamp(count, (s64) 1,
max_end - start);
}
min_start += f2_offset;
max_start += f2_offset;
max_end += f2_offset;
}
if (0 == (f->count[0] | f->count[1])) {
f->start[0] = tvnorm->vbistart[0];
f->start[1] = tvnorm->vbistart[1];
f->count[0] = 1;
f->count[1] = 1;
}
f->flags = 0;
f->reserved[0] = 0;
f->reserved[1] = 0;
return 0;
}
int bttv_try_fmt_vbi_cap(struct file *file, void *f, struct v4l2_format *frt)
{
struct bttv_fh *fh = f;
struct bttv *btv = fh->btv;
const struct bttv_tvnorm *tvnorm;
__s32 crop_start;
mutex_lock(&btv->lock);
tvnorm = &bttv_tvnorms[btv->tvnorm];
crop_start = btv->crop_start;
mutex_unlock(&btv->lock);
return try_fmt(&frt->fmt.vbi, tvnorm, crop_start);
}
int bttv_s_fmt_vbi_cap(struct file *file, void *f, struct v4l2_format *frt)
{
struct bttv_fh *fh = f;
struct bttv *btv = fh->btv;
const struct bttv_tvnorm *tvnorm;
__s32 start1, end;
int rc;
mutex_lock(&btv->lock);
rc = -EBUSY;
if (fh->resources & RESOURCE_VBI)
goto fail;
tvnorm = &bttv_tvnorms[btv->tvnorm];
rc = try_fmt(&frt->fmt.vbi, tvnorm, btv->crop_start);
if (0 != rc)
goto fail;
start1 = frt->fmt.vbi.start[1] - tvnorm->vbistart[1] +
tvnorm->vbistart[0];
end = max(frt->fmt.vbi.start[0], start1) * 2 + 2;
mutex_lock(&fh->vbi.vb_lock);
fh->vbi_fmt.fmt = frt->fmt.vbi;
fh->vbi_fmt.tvnorm = tvnorm;
fh->vbi_fmt.end = end;
mutex_unlock(&fh->vbi.vb_lock);
rc = 0;
fail:
mutex_unlock(&btv->lock);
return rc;
}
int bttv_g_fmt_vbi_cap(struct file *file, void *f, struct v4l2_format *frt)
{
struct bttv_fh *fh = f;
const struct bttv_tvnorm *tvnorm;
frt->fmt.vbi = fh->vbi_fmt.fmt;
tvnorm = &bttv_tvnorms[fh->btv->tvnorm];
if (tvnorm != fh->vbi_fmt.tvnorm) {
__s32 max_end;
unsigned int i;
max_end = (tvnorm->cropcap.bounds.top
+ tvnorm->cropcap.bounds.height) >> 1;
frt->fmt.vbi.sampling_rate = tvnorm->Fsc;
for (i = 0; i < 2; ++i) {
__s32 new_start;
new_start = frt->fmt.vbi.start[i]
+ tvnorm->vbistart[i]
- fh->vbi_fmt.tvnorm->vbistart[i];
frt->fmt.vbi.start[i] = min(new_start, max_end - 1);
frt->fmt.vbi.count[i] =
min((__s32) frt->fmt.vbi.count[i],
max_end - frt->fmt.vbi.start[i]);
max_end += tvnorm->vbistart[1]
- tvnorm->vbistart[0];
}
}
return 0;
}
void bttv_vbi_fmt_reset(struct bttv_vbi_fmt *f, unsigned int norm)
{
const struct bttv_tvnorm *tvnorm;
unsigned int real_samples_per_line;
unsigned int real_count;
tvnorm = &bttv_tvnorms[norm];
f->fmt.sampling_rate = tvnorm->Fsc;
f->fmt.samples_per_line = VBI_BPL;
f->fmt.sample_format = V4L2_PIX_FMT_GREY;
f->fmt.offset = VBI_OFFSET;
f->fmt.start[0] = tvnorm->vbistart[0];
f->fmt.start[1] = tvnorm->vbistart[1];
f->fmt.count[0] = VBI_DEFLINES;
f->fmt.count[1] = VBI_DEFLINES;
f->fmt.flags = 0;
f->fmt.reserved[0] = 0;
f->fmt.reserved[1] = 0;
real_samples_per_line = 1024 + tvnorm->vbipack * 4;
real_count = ((tvnorm->cropcap.defrect.top >> 1)
- tvnorm->vbistart[0]);
BUG_ON(real_samples_per_line > VBI_BPL);
BUG_ON(real_count > VBI_DEFLINES);
f->tvnorm = tvnorm;
f->end = tvnorm->vbistart[0] * 2 + 2;
}
