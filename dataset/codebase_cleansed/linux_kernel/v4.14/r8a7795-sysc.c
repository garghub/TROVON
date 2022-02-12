static int __init r8a7795_sysc_init(void)\r\n{\r\nif (!soc_device_match(r8a7795es1))\r\nrcar_sysc_nullify(r8a7795_areas, ARRAY_SIZE(r8a7795_areas),\r\nR8A7795_PD_A2VC0);\r\nreturn 0;\r\n}
