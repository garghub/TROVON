static int __init plat_pinmux_setup(void)\r\n{\r\nreturn sh_pfc_register("pfc-sh7786", sh7786_pfc_resources,\r\nARRAY_SIZE(sh7786_pfc_resources));\r\n}
