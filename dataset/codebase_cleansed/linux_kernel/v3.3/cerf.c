static void __init cerf_init_irq(void)
{
sa1100_init_irq();
irq_set_irq_type(CERF_ETH_IRQ, IRQ_TYPE_EDGE_RISING);
}
static void __init cerf_map_io(void)
{
sa1100_map_io();
iotable_init(cerf_io_desc, ARRAY_SIZE(cerf_io_desc));
sa1100_register_uart(0, 3);
sa1100_register_uart(1, 2);
sa1100_register_uart(2, 1);
GPDR |= CERF_GPIO_CF_RESET;
}
static void __init cerf_init(void)
{
platform_add_devices(cerf_devices, ARRAY_SIZE(cerf_devices));
sa11x0_register_mtd(&cerf_flash_data, &cerf_flash_resource, 1);
sa11x0_register_mcp(&cerf_mcp_data);
}
