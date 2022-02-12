static void s3c2412_dma_select(struct s3c2410_dma_chan *chan,
struct s3c24xx_dma_map *map)
{
unsigned long chsel = map->channels[0] & (~DMA_CH_VALID);
writel(chsel | S3C2412_DMAREQSEL_HW,
chan->regs + S3C2412_DMA_DMAREQSEL);
}
static int __init s3c2412_dma_add(struct device *dev,
struct subsys_interface *sif)
{
s3c2410_dma_init();
return s3c24xx_dma_init_map(&s3c2412_dma_sel);
}
static int __init s3c2412_dma_init(void)
{
return subsys_interface_register(&s3c2412_dma_interface);
}
