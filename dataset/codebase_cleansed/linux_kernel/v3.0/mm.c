void __init clps711x_map_io(void)
{
iotable_init(clps711x_io_desc, ARRAY_SIZE(clps711x_io_desc));
}
