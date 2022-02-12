void __init pxa95x_init_irq(void)
{
pxa_init_irq(96, NULL);
}
void __init pxa95x_set_i2c_power_info(struct i2c_pxa_platform_data *info)
{
pxa_register_device(&pxa3xx_device_i2c_power, info);
}
static int __init pxa95x_init(void)
{
int ret = 0, i;
if (cpu_is_pxa95x()) {
mfp_init_base(io_p2v(MFPR_BASE));
mfp_init_addr(pxa95x_mfp_addr_map);
reset_status = ARSR;
ASCR &= ~(ASCR_RDH | ASCR_D1S | ASCR_D2S | ASCR_D3S);
clkdev_add_table(pxa95x_clkregs, ARRAY_SIZE(pxa95x_clkregs));
if ((ret = pxa_init_dma(IRQ_DMA, 32)))
return ret;
register_syscore_ops(&pxa_irq_syscore_ops);
register_syscore_ops(&pxa3xx_clock_syscore_ops);
ret = platform_add_devices(devices, ARRAY_SIZE(devices));
}
return ret;
}
