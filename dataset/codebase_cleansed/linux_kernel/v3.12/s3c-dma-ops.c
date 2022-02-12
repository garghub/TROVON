static void s3c_dma_cb(struct s3c2410_dma_chan *channel, void *param,
int size, enum s3c2410_dma_buffresult res)
{
struct cb_data *data = param;
data->fp(data->fp_param);
}
static unsigned s3c_dma_request(enum dma_ch dma_ch,
struct samsung_dma_req *param,
struct device *dev, char *ch_name)
{
struct cb_data *data;
if (s3c2410_dma_request(dma_ch, param->client, NULL) < 0) {
s3c2410_dma_free(dma_ch, param->client);
return 0;
}
if (param->cap == DMA_CYCLIC)
s3c2410_dma_setflags(dma_ch, S3C2410_DMAF_CIRCULAR);
data = kzalloc(sizeof(struct cb_data), GFP_KERNEL);
data->ch = dma_ch;
list_add_tail(&data->node, &dma_list);
return (unsigned)dma_ch;
}
static int s3c_dma_release(unsigned ch, void *param)
{
struct cb_data *data;
list_for_each_entry(data, &dma_list, node)
if (data->ch == ch)
break;
list_del(&data->node);
s3c2410_dma_free(ch, param);
kfree(data);
return 0;
}
static int s3c_dma_config(unsigned ch, struct samsung_dma_config *param)
{
s3c2410_dma_devconfig(ch, param->direction, param->fifo);
s3c2410_dma_config(ch, param->width);
return 0;
}
static int s3c_dma_prepare(unsigned ch, struct samsung_dma_prep *param)
{
struct cb_data *data;
dma_addr_t pos = param->buf;
dma_addr_t end = param->buf + param->len;
list_for_each_entry(data, &dma_list, node)
if (data->ch == ch)
break;
if (!data->fp) {
s3c2410_dma_set_buffdone_fn(ch, s3c_dma_cb);
data->fp = param->fp;
data->fp_param = param->fp_param;
}
if (param->cap != DMA_CYCLIC) {
s3c2410_dma_enqueue(ch, (void *)data, param->buf, param->len);
return 0;
}
while (pos < end) {
s3c2410_dma_enqueue(ch, (void *)data, pos, param->period);
pos += param->period;
}
return 0;
}
static inline int s3c_dma_trigger(unsigned ch)
{
return s3c2410_dma_ctrl(ch, S3C2410_DMAOP_START);
}
static inline int s3c_dma_started(unsigned ch)
{
return s3c2410_dma_ctrl(ch, S3C2410_DMAOP_STARTED);
}
static inline int s3c_dma_flush(unsigned ch)
{
return s3c2410_dma_ctrl(ch, S3C2410_DMAOP_FLUSH);
}
static inline int s3c_dma_stop(unsigned ch)
{
return s3c2410_dma_ctrl(ch, S3C2410_DMAOP_STOP);
}
void *s3c_dma_get_ops(void)
{
return &s3c_dma_ops;
}
