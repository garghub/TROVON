int\r\nnv04_fb_init(struct drm_device *dev)\r\n{\r\nnv_wr32(dev, NV04_PFB_CFG0, 0x1114);\r\nreturn 0;\r\n}\r\nvoid\r\nnv04_fb_takedown(struct drm_device *dev)\r\n{\r\n}
