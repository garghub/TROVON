void __init imx_lluart_map_io(void)
{
if (imx_lluart_desc.virtual)
iotable_init(&imx_lluart_desc, 1);
}
