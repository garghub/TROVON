static int buffer_activate(struct saa7134_dev *dev,
struct saa7134_buf *buf,
struct saa7134_buf *next)
{
dprintk("buffer_activate [%p]",buf);
buf->vb.state = VIDEOBUF_ACTIVE;
buf->top_seen = 0;
if (NULL == next)
next = buf;
if (V4L2_FIELD_TOP == buf->vb.field) {
dprintk("- [top] buf=%p next=%p\n",buf,next);
saa_writel(SAA7134_RS_BA1(5),saa7134_buffer_base(buf));
saa_writel(SAA7134_RS_BA2(5),saa7134_buffer_base(next));
} else {
dprintk("- [bottom] buf=%p next=%p\n",buf,next);
saa_writel(SAA7134_RS_BA1(5),saa7134_buffer_base(next));
saa_writel(SAA7134_RS_BA2(5),saa7134_buffer_base(buf));
}
saa7134_set_dmabits(dev);
mod_timer(&dev->ts_q.timeout, jiffies+TS_BUFFER_TIMEOUT);
if (!dev->ts_started)
saa7134_ts_start(dev);
return 0;
}
static int buffer_prepare(struct videobuf_queue *q, struct videobuf_buffer *vb,
enum v4l2_field field)
{
struct saa7134_dev *dev = q->priv_data;
struct saa7134_buf *buf = container_of(vb,struct saa7134_buf,vb);
unsigned int lines, llength, size;
int err;
dprintk("buffer_prepare [%p,%s]\n",buf,v4l2_field_names[field]);
llength = TS_PACKET_SIZE;
lines = dev->ts.nr_packets;
size = lines * llength;
if (0 != buf->vb.baddr && buf->vb.bsize < size)
return -EINVAL;
if (buf->vb.size != size) {
saa7134_dma_free(q,buf);
}
if (VIDEOBUF_NEEDS_INIT == buf->vb.state) {
struct videobuf_dmabuf *dma=videobuf_to_dma(&buf->vb);
dprintk("buffer_prepare: needs_init\n");
buf->vb.width = llength;
buf->vb.height = lines;
buf->vb.size = size;
buf->pt = &dev->ts.pt_ts;
err = videobuf_iolock(q,&buf->vb,NULL);
if (err)
goto oops;
err = saa7134_pgtable_build(dev->pci,buf->pt,
dma->sglist,
dma->sglen,
saa7134_buffer_startpage(buf));
if (err)
goto oops;
}
buf->vb.state = VIDEOBUF_PREPARED;
buf->activate = buffer_activate;
buf->vb.field = field;
return 0;
oops:
saa7134_dma_free(q,buf);
return err;
}
static int
buffer_setup(struct videobuf_queue *q, unsigned int *count, unsigned int *size)
{
struct saa7134_dev *dev = q->priv_data;
*size = TS_PACKET_SIZE * dev->ts.nr_packets;
if (0 == *count)
*count = dev->ts.nr_bufs;
*count = saa7134_buffer_count(*size,*count);
return 0;
}
static void buffer_queue(struct videobuf_queue *q, struct videobuf_buffer *vb)
{
struct saa7134_dev *dev = q->priv_data;
struct saa7134_buf *buf = container_of(vb,struct saa7134_buf,vb);
saa7134_buffer_queue(dev,&dev->ts_q,buf);
}
static void buffer_release(struct videobuf_queue *q, struct videobuf_buffer *vb)
{
struct saa7134_buf *buf = container_of(vb,struct saa7134_buf,vb);
struct saa7134_dev *dev = q->priv_data;
if (dev->ts_started)
saa7134_ts_stop(dev);
saa7134_dma_free(q,buf);
}
int saa7134_ts_init_hw(struct saa7134_dev *dev)
{
saa_writeb(SAA7134_TS_SERIAL1, 0x00);
saa_writeb(SAA7134_TS_PARALLEL, 0x6c);
saa_writeb(SAA7134_TS_PARALLEL_SERIAL, (TS_PACKET_SIZE-1));
saa_writeb(SAA7134_TS_DMA0, ((dev->ts.nr_packets-1)&0xff));
saa_writeb(SAA7134_TS_DMA1, (((dev->ts.nr_packets-1)>>8)&0xff));
saa_writeb(SAA7134_TS_DMA2,
((((dev->ts.nr_packets-1)>>16)&0x3f) | 0x00));
return 0;
}
int saa7134_ts_init1(struct saa7134_dev *dev)
{
if (tsbufs < 2)
tsbufs = 2;
if (tsbufs > VIDEO_MAX_FRAME)
tsbufs = VIDEO_MAX_FRAME;
if (ts_nr_packets < 4)
ts_nr_packets = 4;
if (ts_nr_packets > 312)
ts_nr_packets = 312;
dev->ts.nr_bufs = tsbufs;
dev->ts.nr_packets = ts_nr_packets;
INIT_LIST_HEAD(&dev->ts_q.queue);
init_timer(&dev->ts_q.timeout);
dev->ts_q.timeout.function = saa7134_buffer_timeout;
dev->ts_q.timeout.data = (unsigned long)(&dev->ts_q);
dev->ts_q.dev = dev;
dev->ts_q.need_two = 1;
dev->ts_started = 0;
saa7134_pgtable_alloc(dev->pci,&dev->ts.pt_ts);
saa7134_ts_init_hw(dev);
return 0;
}
int saa7134_ts_stop(struct saa7134_dev *dev)
{
dprintk("TS stop\n");
BUG_ON(!dev->ts_started);
switch (saa7134_boards[dev->board].ts_type) {
case SAA7134_MPEG_TS_PARALLEL:
saa_writeb(SAA7134_TS_PARALLEL, 0x6c);
dev->ts_started = 0;
break;
case SAA7134_MPEG_TS_SERIAL:
saa_writeb(SAA7134_TS_SERIAL0, 0x40);
dev->ts_started = 0;
break;
}
return 0;
}
int saa7134_ts_start(struct saa7134_dev *dev)
{
dprintk("TS start\n");
BUG_ON(dev->ts_started);
saa_writeb(SAA7134_TS_DMA0, (dev->ts.nr_packets - 1) & 0xff);
saa_writeb(SAA7134_TS_DMA1,
((dev->ts.nr_packets - 1) >> 8) & 0xff);
saa_writeb(SAA7134_TS_DMA2,
(((dev->ts.nr_packets - 1) >> 16) & 0x3f) | 0x00);
saa_writel(SAA7134_RS_PITCH(5), TS_PACKET_SIZE);
saa_writel(SAA7134_RS_CONTROL(5), SAA7134_RS_CONTROL_BURST_16 |
SAA7134_RS_CONTROL_ME |
(dev->ts.pt_ts.dma >> 12));
saa_writeb(SAA7134_TS_SERIAL1, 0x00);
saa_writeb(SAA7134_TS_SERIAL1, 0x03);
saa_writeb(SAA7134_TS_SERIAL1, 0x00);
saa_writeb(SAA7134_TS_SERIAL1, 0x01);
saa_writeb(SAA7134_TS_SERIAL1, 0x00);
switch (saa7134_boards[dev->board].ts_type) {
case SAA7134_MPEG_TS_PARALLEL:
saa_writeb(SAA7134_TS_SERIAL0, 0x40);
saa_writeb(SAA7134_TS_PARALLEL, 0xec |
(saa7134_boards[dev->board].ts_force_val << 4));
break;
case SAA7134_MPEG_TS_SERIAL:
saa_writeb(SAA7134_TS_SERIAL0, 0xd8);
saa_writeb(SAA7134_TS_PARALLEL, 0x6c |
(saa7134_boards[dev->board].ts_force_val << 4));
saa_writeb(SAA7134_TS_PARALLEL_SERIAL, 0xbc);
saa_writeb(SAA7134_TS_SERIAL1, 0x02);
break;
}
dev->ts_started = 1;
return 0;
}
int saa7134_ts_fini(struct saa7134_dev *dev)
{
saa7134_pgtable_free(dev->pci,&dev->ts.pt_ts);
return 0;
}
void saa7134_irq_ts_done(struct saa7134_dev *dev, unsigned long status)
{
enum v4l2_field field;
spin_lock(&dev->slock);
if (dev->ts_q.curr) {
field = dev->ts_q.curr->vb.field;
if (field == V4L2_FIELD_TOP) {
if ((status & 0x100000) != 0x000000)
goto done;
} else {
if ((status & 0x100000) != 0x100000)
goto done;
}
saa7134_buffer_finish(dev,&dev->ts_q,VIDEOBUF_DONE);
}
saa7134_buffer_next(dev,&dev->ts_q);
done:
spin_unlock(&dev->slock);
}
