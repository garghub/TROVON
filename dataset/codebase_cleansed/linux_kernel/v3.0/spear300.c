void __init spear300_init(struct pmx_mode *pmx_mode, struct pmx_dev **pmx_devs,
u8 pmx_dev_count)
{
int ret = 0;
spear3xx_init();
shirq_ras1.regs.base = ioremap(SPEAR300_TELECOM_BASE, SZ_4K);
if (shirq_ras1.regs.base) {
ret = spear_shirq_register(&shirq_ras1);
if (ret)
printk(KERN_ERR "Error registering Shared IRQ\n");
}
pmx_driver.mode = pmx_mode;
pmx_driver.devs = pmx_devs;
pmx_driver.devs_count = pmx_dev_count;
pmx_driver.base = ioremap(SPEAR300_SOC_CONFIG_BASE, SZ_4K);
if (pmx_driver.base) {
ret = pmx_register(&pmx_driver);
if (ret)
printk(KERN_ERR "padmux: registeration failed. err no"
": %d\n", ret);
iounmap(pmx_driver.base);
}
}
