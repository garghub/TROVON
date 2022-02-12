void __init edb7211_map_io(void)
{
clps711x_map_io();
iotable_init(edb7211_io_desc, ARRAY_SIZE(edb7211_io_desc));
}
