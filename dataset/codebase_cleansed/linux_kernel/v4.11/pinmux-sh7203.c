static int __init plat_pinmux_setup(void)\r\n{\r\nreturn sh_pfc_register("pfc-sh7203", sh7203_pfc_resources,\r\nARRAY_SIZE(sh7203_pfc_resources));\r\n}
