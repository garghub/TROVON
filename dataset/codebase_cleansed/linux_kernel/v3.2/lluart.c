void __init highbank_lluart_map_io(void)
{
iotable_init(&lluart_io_desc, 1);
}
