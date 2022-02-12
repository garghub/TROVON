static int __init plat_pinmux_setup(void)\r\n{\r\nreturn sh_pfc_register("pfc-shx3", shx3_pfc_resources,\r\nARRAY_SIZE(shx3_pfc_resources));\r\n}
