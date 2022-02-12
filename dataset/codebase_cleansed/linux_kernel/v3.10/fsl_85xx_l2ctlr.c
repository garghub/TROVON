static int get_cache_sram_params(struct sram_parameters *sram_params)
{
unsigned long long addr;
unsigned int size;
if (!sram_size || (kstrtouint(sram_size, 0, &size) < 0))
return -EINVAL;
if (!sram_offset || (kstrtoull(sram_offset, 0, &addr) < 0))
return -EINVAL;
sram_params->sram_offset = addr;
sram_params->sram_size = size;
return 0;
}
static int __init get_size_from_cmdline(char *str)
{
if (!str)
return 0;
sram_size = str;
return 1;
}
static int __init get_offset_from_cmdline(char *str)
{
if (!str)
return 0;
sram_offset = str;
return 1;
}
static int mpc85xx_l2ctlr_of_probe(struct platform_device *dev)
{
long rval;
unsigned int rem;
unsigned char ways;
const unsigned int *prop;
unsigned int l2cache_size;
struct sram_parameters sram_params;
if (!dev->dev.of_node) {
dev_err(&dev->dev, "Device's OF-node is NULL\n");
return -EINVAL;
}
prop = of_get_property(dev->dev.of_node, "cache-size", NULL);
if (!prop) {
dev_err(&dev->dev, "Missing L2 cache-size\n");
return -EINVAL;
}
l2cache_size = *prop;
if (get_cache_sram_params(&sram_params)) {
dev_err(&dev->dev,
"Entire L2 as cache, provide valid sram offset and size\n");
return -EINVAL;
}
rem = l2cache_size % sram_params.sram_size;
ways = LOCK_WAYS_FULL * sram_params.sram_size / l2cache_size;
if (rem || (ways & (ways - 1))) {
dev_err(&dev->dev, "Illegal cache-sram-size in command line\n");
return -EINVAL;
}
l2ctlr = of_iomap(dev->dev.of_node, 0);
if (!l2ctlr) {
dev_err(&dev->dev, "Can't map L2 controller\n");
return -EINVAL;
}
out_be32(&l2ctlr->srbar0,
lower_32_bits(sram_params.sram_offset) & L2SRAM_BAR_MSK_LO18);
#ifdef CONFIG_PHYS_64BIT
out_be32(&l2ctlr->srbarea0,
upper_32_bits(sram_params.sram_offset) & L2SRAM_BARE_MSK_HI4);
#endif
clrsetbits_be32(&l2ctlr->ctl, L2CR_L2E, L2CR_L2FI);
switch (ways) {
case LOCK_WAYS_EIGHTH:
setbits32(&l2ctlr->ctl,
L2CR_L2E | L2CR_L2FI | L2CR_SRAM_EIGHTH);
break;
case LOCK_WAYS_TWO_EIGHTH:
setbits32(&l2ctlr->ctl,
L2CR_L2E | L2CR_L2FI | L2CR_SRAM_QUART);
break;
case LOCK_WAYS_HALF:
setbits32(&l2ctlr->ctl,
L2CR_L2E | L2CR_L2FI | L2CR_SRAM_HALF);
break;
case LOCK_WAYS_FULL:
default:
setbits32(&l2ctlr->ctl,
L2CR_L2E | L2CR_L2FI | L2CR_SRAM_FULL);
break;
}
eieio();
rval = instantiate_cache_sram(dev, sram_params);
if (rval < 0) {
dev_err(&dev->dev, "Can't instantiate Cache-SRAM\n");
iounmap(l2ctlr);
return -EINVAL;
}
return 0;
}
static int mpc85xx_l2ctlr_of_remove(struct platform_device *dev)
{
BUG_ON(!l2ctlr);
iounmap(l2ctlr);
remove_cache_sram(dev);
dev_info(&dev->dev, "MPC85xx L2 controller unloaded\n");
return 0;
}
static __init int mpc85xx_l2ctlr_of_init(void)
{
return platform_driver_register(&mpc85xx_l2ctlr_of_platform_driver);
}
static void __exit mpc85xx_l2ctlr_of_exit(void)
{
platform_driver_unregister(&mpc85xx_l2ctlr_of_platform_driver);
}
