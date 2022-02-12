void fsl_dcu_fbdev_init(struct drm_device *dev)\r\n{\r\nstruct fsl_dcu_drm_device *fsl_dev = dev_get_drvdata(dev->dev);\r\nfsl_dev->fbdev = drm_fbdev_cma_init(dev, 24, 1, 1);\r\n}
