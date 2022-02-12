int __init am33xx_hwmod_init(void)\r\n{\r\nomap_hwmod_am33xx_reg();\r\nomap_hwmod_init();\r\nreturn omap_hwmod_register_links(am33xx_hwmod_ocp_ifs);\r\n}
