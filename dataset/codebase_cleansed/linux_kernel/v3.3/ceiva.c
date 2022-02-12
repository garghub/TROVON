static void __init ceiva_map_io(void)
{
clps711x_map_io();
iotable_init(ceiva_io_desc, ARRAY_SIZE(ceiva_io_desc));
}
