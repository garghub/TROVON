static int __init tdfx_init(void)\r\n{\r\nreturn drm_pci_init(&driver, &tdfx_pci_driver);\r\n}\r\nstatic void __exit tdfx_exit(void)\r\n{\r\ndrm_pci_exit(&driver, &tdfx_pci_driver);\r\n}
