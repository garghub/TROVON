static int ipq806x_lpass_alloc_dma_channel(struct lpass_data *drvdata, int dir)
{
if (dir == SNDRV_PCM_STREAM_PLAYBACK)
return IPQ806X_LPAIF_RDMA_CHAN_MI2S;
else
return -EINVAL;
}
static int ipq806x_lpass_free_dma_channel(struct lpass_data *drvdata, int chan)
{
return 0;
}
