void __iomem *\r\n__ioremap(unsigned long phys_addr, unsigned long size, unsigned long flags)\r\n{\r\nreturn (void *)phys_addr;\r\n}\r\nvoid iounmap(volatile void __iomem *addr)\r\n{\r\n}
