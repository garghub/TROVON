static void s3c_dma_cb(struct s3c2410_dma_chan *channel, void *param,
int size, enum s3c2410_dma_buffresult res)
{
struct cb_data *data = param;
data->fp(data->fp_param);
}
static unsigned s3c_dma_request(enum dma_ch dma_ch,
struct samsung_dma_info *info)
{
struct cb_data *data;
if (s3c2410_dma_request(dma_ch, info->client, NULL) < 0) {
s3c2410_dma_free(dma_ch, info->client);
return 0;
}
data = kzalloc(sizeof(struct cb_data), GFP_KERNEL);
data->ch = dma_ch;
list_add_tail(&data->node, &dma_list);
s3c2410_dma_devconfig(dma_ch, info->direction, info->fifo);
if (info->cap == DMA_CYCLIC)
s3c2410_dma_setflags(dma_ch, S3C2410_DMAF_CIRCULAR);
s3c2410_dma_config(dma_ch, info->width);
return (unsigned)dma_ch;
}
static int s3c_dma_release(unsigned ch, struct s3c2410_dma_client *client)
{
struct cb_data *data;
list_for_each_entry(data, &dma_list, node)
if (data->ch == ch)
break;
list_del(&data->node);
s3c2410_dma_free(ch, client);
kfree(data);
return 0;
}
static int s3c_dma_prepare(unsigned ch, struct samsung_dma_prep_info *info)
{
struct cb_data *data;
int len = (info->cap == DMA_CYCLIC) ? info->period : info->len;
list_for_each_entry(data, &dma_list, node)
if (data->ch == ch)
break;
if (!data->fp) {
s3c2410_dma_set_buffdone_fn(ch, s3c_dma_cb);
data->fp = info->fp;
data->fp_param = info->fp_param;
}
s3c2410_dma_enqueue(ch, (void *)data, info->buf, len);
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
