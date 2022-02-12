int host1x04_init(struct host1x *host)
{
host->channel_op = &host1x_channel_ops;
host->cdma_op = &host1x_cdma_ops;
host->cdma_pb_op = &host1x_pushbuffer_ops;
host->syncpt_op = &host1x_syncpt_ops;
host->intr_op = &host1x_intr_ops;
host->debug_op = &host1x_debug_ops;
return 0;
}
