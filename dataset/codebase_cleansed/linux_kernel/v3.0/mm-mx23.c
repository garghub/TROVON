void __init mx23_map_io(void)
{
iotable_init(mx23_io_desc, ARRAY_SIZE(mx23_io_desc));
}
void __init mx23_init_irq(void)
{
icoll_init_irq();
mx23_register_gpios();
}
