static int ipq806x_lpass_alloc_dma_channel(struct lpass_data *drvdata)
{
return IPQ806X_LPAIF_RDMA_CHAN_MI2S;
}
static int ipq806x_lpass_free_dma_channel(struct lpass_data *drvdata, int chan)
{
return 0;
}
