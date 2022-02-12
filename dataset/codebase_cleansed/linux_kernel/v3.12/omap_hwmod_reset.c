int omap_hwmod_aess_preprogram(struct omap_hwmod *oh)\r\n{\r\nvoid __iomem *va;\r\nva = omap_hwmod_get_mpu_rt_va(oh);\r\nif (!va)\r\nreturn -EINVAL;\r\naess_enable_autogating(va);\r\nreturn 0;\r\n}
