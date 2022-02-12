int\r\nnv50_mc_init(struct drm_device *dev)\r\n{\r\nnv_wr32(dev, NV03_PMC_ENABLE, 0xFFFFFFFF);\r\nreturn 0;\r\n}\r\nvoid nv50_mc_takedown(struct drm_device *dev)\r\n{\r\n}
