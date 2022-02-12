void ddk750_set_mmio(void __iomem *addr, unsigned short devId, char revId)\r\n{\r\nmmio750 = addr;\r\ndevId750 = devId;\r\nrevId750 = revId;\r\nif (revId == 0xfe)\r\nprintk("found sm750le\n");\r\n}
