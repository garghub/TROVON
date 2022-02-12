void __init mx28_map_io(void)
{
iotable_init(mx28_io_desc, ARRAY_SIZE(mx28_io_desc));
}
void __init mx28_init_irq(void)
{
icoll_init_irq();
}
