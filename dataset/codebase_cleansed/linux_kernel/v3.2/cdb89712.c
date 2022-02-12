static void __init cdb89712_map_io(void)
{
clps711x_map_io();
iotable_init(cdb89712_io_desc, ARRAY_SIZE(cdb89712_io_desc));
}
