void __init spear310_init(struct pmx_mode *pmx_mode, struct pmx_dev **pmx_devs,
u8 pmx_dev_count)
{
void __iomem *base;
int ret = 0;
spear3xx_init();
base = ioremap(SPEAR310_SOC_CONFIG_BASE, SZ_4K);
if (base) {
shirq_ras1.regs.base = base;
ret = spear_shirq_register(&shirq_ras1);
if (ret)
printk(KERN_ERR "Error registering Shared IRQ 1\n");
shirq_ras2.regs.base = base;
ret = spear_shirq_register(&shirq_ras2);
if (ret)
printk(KERN_ERR "Error registering Shared IRQ 2\n");
shirq_ras3.regs.base = base;
ret = spear_shirq_register(&shirq_ras3);
if (ret)
printk(KERN_ERR "Error registering Shared IRQ 3\n");
shirq_intrcomm_ras.regs.base = base;
ret = spear_shirq_register(&shirq_intrcomm_ras);
if (ret)
printk(KERN_ERR "Error registering Shared IRQ 4\n");
}
pmx_driver.base = base;
pmx_driver.mode = pmx_mode;
pmx_driver.devs = pmx_devs;
pmx_driver.devs_count = pmx_dev_count;
ret = pmx_register(&pmx_driver);
if (ret)
printk(KERN_ERR "padmux: registration failed. err no: %d\n",
ret);
}
