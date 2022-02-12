int __init omap2430_hwmod_init(void)\r\n{\r\nomap_hwmod_init();\r\nreturn omap_hwmod_register_links(omap2430_hwmod_ocp_ifs);\r\n}
