void __init da830_init(void)
{
davinci_common_init(&davinci_soc_info_da830);
da8xx_syscfg0_base = ioremap(DA8XX_SYSCFG0_BASE, SZ_4K);
WARN(!da8xx_syscfg0_base, "Unable to map syscfg0 module");
}
