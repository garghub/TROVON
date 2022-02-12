static int s5pv210_spi_cfg_gpio(struct platform_device *pdev)
{
unsigned int base;
switch (pdev->id) {
case 0:
base = S5PV210_GPB(0);
break;
case 1:
base = S5PV210_GPB(4);
break;
default:
dev_err(&pdev->dev, "Invalid SPI Controller number!");
return -EINVAL;
}
s3c_gpio_cfgall_range(base, 3,
S3C_GPIO_SFN(2), S3C_GPIO_PULL_UP);
return 0;
}
void __init s5pv210_spi_set_info(int cntrlr, int src_clk_nr, int num_cs)
{
struct s3c64xx_spi_info *pd;
if (!num_cs || src_clk_nr < 0
|| src_clk_nr > S5PV210_SPI_SRCCLK_SCLK) {
printk(KERN_ERR "%s: Invalid SPI configuration\n", __func__);
return;
}
switch (cntrlr) {
case 0:
pd = &s5pv210_spi0_pdata;
break;
case 1:
pd = &s5pv210_spi1_pdata;
break;
default:
printk(KERN_ERR "%s: Invalid SPI controller(%d)\n",
__func__, cntrlr);
return;
}
pd->num_cs = num_cs;
pd->src_clk_nr = src_clk_nr;
pd->src_clk_name = spi_src_clks[src_clk_nr];
}
