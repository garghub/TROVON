static unsigned samsung_dmadev_request(enum dma_ch dma_ch,
struct samsung_dma_req *param)
{
dma_cap_mask_t mask;
void *filter_param;
dma_cap_zero(mask);
dma_cap_set(param->cap, mask);
filter_param = (dma_ch == DMACH_DT_PROP) ?
(void *)param->dt_dmach_prop : (void *)dma_ch;
return (unsigned)dma_request_channel(mask, pl330_filter, filter_param);
}
static int samsung_dmadev_release(unsigned ch, void *param)
{
dma_release_channel((struct dma_chan *)ch);
return 0;
}
static int samsung_dmadev_config(unsigned ch,
struct samsung_dma_config *param)
{
struct dma_chan *chan = (struct dma_chan *)ch;
struct dma_slave_config slave_config;
if (param->direction == DMA_DEV_TO_MEM) {
memset(&slave_config, 0, sizeof(struct dma_slave_config));
slave_config.direction = param->direction;
slave_config.src_addr = param->fifo;
slave_config.src_addr_width = param->width;
slave_config.src_maxburst = 1;
dmaengine_slave_config(chan, &slave_config);
} else if (param->direction == DMA_MEM_TO_DEV) {
memset(&slave_config, 0, sizeof(struct dma_slave_config));
slave_config.direction = param->direction;
slave_config.dst_addr = param->fifo;
slave_config.dst_addr_width = param->width;
slave_config.dst_maxburst = 1;
dmaengine_slave_config(chan, &slave_config);
} else {
pr_warn("unsupported direction\n");
return -EINVAL;
}
return 0;
}
static int samsung_dmadev_prepare(unsigned ch,
struct samsung_dma_prep *param)
{
struct scatterlist sg;
struct dma_chan *chan = (struct dma_chan *)ch;
struct dma_async_tx_descriptor *desc;
switch (param->cap) {
case DMA_SLAVE:
sg_init_table(&sg, 1);
sg_dma_len(&sg) = param->len;
sg_set_page(&sg, pfn_to_page(PFN_DOWN(param->buf)),
param->len, offset_in_page(param->buf));
sg_dma_address(&sg) = param->buf;
desc = dmaengine_prep_slave_sg(chan,
&sg, 1, param->direction, DMA_PREP_INTERRUPT);
break;
case DMA_CYCLIC:
desc = dmaengine_prep_dma_cyclic(chan, param->buf,
param->len, param->period, param->direction,
DMA_PREP_INTERRUPT | DMA_CTRL_ACK);
break;
default:
dev_err(&chan->dev->device, "unsupported format\n");
return -EFAULT;
}
if (!desc) {
dev_err(&chan->dev->device, "cannot prepare cyclic dma\n");
return -EFAULT;
}
desc->callback = param->fp;
desc->callback_param = param->fp_param;
dmaengine_submit((struct dma_async_tx_descriptor *)desc);
return 0;
}
static inline int samsung_dmadev_trigger(unsigned ch)
{
dma_async_issue_pending((struct dma_chan *)ch);
return 0;
}
static inline int samsung_dmadev_flush(unsigned ch)
{
return dmaengine_terminate_all((struct dma_chan *)ch);
}
void *samsung_dmadev_get_ops(void)
{
return &dmadev_ops;
}
