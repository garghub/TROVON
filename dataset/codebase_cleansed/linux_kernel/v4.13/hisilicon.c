static void __init hi3620_map_io(void)
{
debug_ll_io_init();
iotable_init(hi3620_io_desc, ARRAY_SIZE(hi3620_io_desc));
}
