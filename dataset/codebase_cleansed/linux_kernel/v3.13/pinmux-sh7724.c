static int __init plat_pinmux_setup(void)\r\n{\r\nreturn sh_pfc_register("pfc-sh7724", sh7724_pfc_resources,\r\nARRAY_SIZE(sh7724_pfc_resources));\r\n}
