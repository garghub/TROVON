static void s3c2443_dma_select(struct s3c2410_dma_chan *chan,
struct s3c24xx_dma_map *map)
{
writel(map->channels[0] | S3C2443_DMAREQSEL_HW,
chan->regs + S3C2443_DMA_DMAREQSEL);
}
static int __init s3c2443_dma_add(struct sys_device *sysdev)
{
s3c24xx_dma_init(6, IRQ_S3C2443_DMA0, 0x100);
return s3c24xx_dma_init_map(&s3c2443_dma_sel);
}
static int __init s3c2443_dma_init(void)
{
return sysdev_driver_register(&s3c2443_sysclass, &s3c2443_dma_driver);
}
