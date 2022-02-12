int __init omap44xx_hwmod_init(void)\r\n{\r\nomap_hwmod_init();\r\nreturn omap_hwmod_register_links(omap44xx_hwmod_ocp_ifs);\r\n}
