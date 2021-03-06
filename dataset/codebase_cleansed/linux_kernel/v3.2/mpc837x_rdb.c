static void mpc837x_rdb_sd_cfg(void)\r\n{\r\nvoid __iomem *im;\r\nim = ioremap(get_immrbase(), 0x1000);\r\nif (!im) {\r\nWARN_ON(1);\r\nreturn;\r\n}\r\nclrsetbits_be32(im + MPC83XX_SICRL_OFFS, MPC837X_SICRL_USBB_MASK,\r\nMPC837X_SICRL_SD);\r\nclrsetbits_be32(im + MPC83XX_SICRH_OFFS, MPC837X_SICRH_SPI_MASK,\r\nMPC837X_SICRH_SD);\r\niounmap(im);\r\n}\r\nstatic void __init mpc837x_rdb_setup_arch(void)\r\n{\r\n#ifdef CONFIG_PCI\r\nstruct device_node *np;\r\n#endif\r\nif (ppc_md.progress)\r\nppc_md.progress("mpc837x_rdb_setup_arch()", 0);\r\n#ifdef CONFIG_PCI\r\nfor_each_compatible_node(np, "pci", "fsl,mpc8349-pci")\r\nmpc83xx_add_bridge(np);\r\nfor_each_compatible_node(np, "pci", "fsl,mpc8314-pcie")\r\nmpc83xx_add_bridge(np);\r\n#endif\r\nmpc837x_usb_cfg();\r\nmpc837x_rdb_sd_cfg();\r\n}\r\nstatic int __init mpc837x_declare_of_platform_devices(void)\r\n{\r\nof_platform_bus_probe(NULL, mpc837x_ids, NULL);\r\nreturn 0;\r\n}\r\nstatic void __init mpc837x_rdb_init_IRQ(void)\r\n{\r\nstruct device_node *np;\r\nnp = of_find_compatible_node(NULL, NULL, "fsl,ipic");\r\nif (!np)\r\nreturn;\r\nipic_init(np, 0);\r\nipic_set_default_priority();\r\n}\r\nstatic int __init mpc837x_rdb_probe(void)\r\n{\r\nreturn of_flat_dt_match(of_get_flat_dt_root(), board);\r\n}
