static void simtec_nor_vpp(struct platform_device *pdev, int vpp)
{
unsigned int val;
val = __raw_readb(BAST_VA_CTRL3);
printk(KERN_DEBUG "%s(%d)\n", __func__, vpp);
if (vpp)
val |= BAST_CPLD_CTRL3_ROMWEN;
else
val &= ~BAST_CPLD_CTRL3_ROMWEN;
__raw_writeb(val, BAST_VA_CTRL3);
}
void __init nor_simtec_init(void)
{
int ret;
ret = platform_device_register(&simtec_device_nor);
if (ret < 0)
printk(KERN_ERR "failed to register physmap-flash device\n");
else
simtec_nor_vpp(NULL, 1);
}
