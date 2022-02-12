static void s3c2440_dma_select(struct s3c2410_dma_chan *chan,
struct s3c24xx_dma_map *map)
{
chan->dcon = map->channels[chan->number] & ~DMA_CH_VALID;
}
static int __init s3c2440_dma_add(struct device *dev,
struct subsys_interface *sif)
{
s3c2410_dma_init();
s3c24xx_dma_order_set(&s3c2440_dma_order);
return s3c24xx_dma_init_map(&s3c2440_dma_sel);
}
static int __init s3c2440_dma_init(void)
{
return subsys_interface_register(&s3c2440_dma_interface);
}
