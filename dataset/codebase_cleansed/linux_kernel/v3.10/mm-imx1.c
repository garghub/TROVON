void __init mx1_map_io(void)
{
iotable_init(imx_io_desc, ARRAY_SIZE(imx_io_desc));
}
void __init imx1_init_early(void)
{
mxc_set_cpu_type(MXC_CPU_MX1);
mxc_arch_reset_init(MX1_IO_ADDRESS(MX1_WDT_BASE_ADDR));
imx_iomuxv1_init(MX1_IO_ADDRESS(MX1_GPIO_BASE_ADDR),
MX1_NUM_GPIO_PORT);
}
void __init mx1_init_irq(void)
{
mxc_init_irq(MX1_IO_ADDRESS(MX1_AVIC_BASE_ADDR));
}
void __init imx1_soc_init(void)
{
mxc_device_init();
mxc_register_gpio("imx1-gpio", 0, MX1_GPIO1_BASE_ADDR, SZ_256,
MX1_GPIO_INT_PORTA, 0);
mxc_register_gpio("imx1-gpio", 1, MX1_GPIO2_BASE_ADDR, SZ_256,
MX1_GPIO_INT_PORTB, 0);
mxc_register_gpio("imx1-gpio", 2, MX1_GPIO3_BASE_ADDR, SZ_256,
MX1_GPIO_INT_PORTC, 0);
mxc_register_gpio("imx1-gpio", 3, MX1_GPIO4_BASE_ADDR, SZ_256,
MX1_GPIO_INT_PORTD, 0);
imx_add_imx_dma("imx1-dma", MX1_DMA_BASE_ADDR,
MX1_DMA_INT, MX1_DMA_ERR);
pinctrl_provide_dummies();
}
