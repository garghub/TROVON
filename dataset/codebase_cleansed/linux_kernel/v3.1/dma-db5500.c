void __init db5500_dma_init(void)\r\n{\r\nint ret;\r\nret = platform_device_register(&dma40_device);\r\nif (ret)\r\ndev_err(&dma40_device.dev, "unable to register device: %d\n", ret);\r\n}
