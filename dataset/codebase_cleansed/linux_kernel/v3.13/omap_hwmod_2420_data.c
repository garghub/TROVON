int __init omap2420_hwmod_init(void)\r\n{\r\nomap_hwmod_init();\r\nreturn omap_hwmod_register_links(omap2420_hwmod_ocp_ifs);\r\n}
