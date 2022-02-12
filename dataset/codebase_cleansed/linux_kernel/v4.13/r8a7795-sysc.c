static int __init r8a7795_sysc_init(void)
{
if (!soc_device_match(r8a7795es1))
rcar_sysc_nullify(r8a7795_areas, ARRAY_SIZE(r8a7795_areas),
R8A7795_PD_A2VC0);
return 0;
}
