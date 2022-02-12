static int mpc52xx_pm_valid(suspend_state_t state)
{
switch (state) {
case PM_SUSPEND_STANDBY:
return 1;
default:
return 0;
}
}
int mpc52xx_set_wakeup_gpio(u8 pin, u8 level)
{
u16 tmp;
out_8(&gpiow->wkup_gpioe, in_8(&gpiow->wkup_gpioe) | (1 << pin));
out_8(&gpiow->wkup_ddr, in_8(&gpiow->wkup_ddr) & ~(1 << pin));
out_8(&gpiow->wkup_inten, in_8(&gpiow->wkup_inten) | (1 << pin));
tmp = in_be16(&gpiow->wkup_itype);
tmp &= ~(0x3 << (pin * 2));
tmp |= (!level + 1) << (pin * 2);
out_be16(&gpiow->wkup_itype, tmp);
out_8(&gpiow->wkup_maste, 1);
return 0;
}
int mpc52xx_pm_prepare(void)
{
struct device_node *np;
const struct of_device_id immr_ids[] = {
{ .compatible = "fsl,mpc5200-immr", },
{ .compatible = "fsl,mpc5200b-immr", },
{ .type = "soc", .compatible = "mpc5200", },
{ .type = "builtin", .compatible = "mpc5200", },
{}
};
struct resource res;
np = of_find_matching_node(NULL, immr_ids);
if (of_address_to_resource(np, 0, &res)) {
pr_err("mpc52xx_pm_prepare(): could not get IMMR address\n");
of_node_put(np);
return -ENOSYS;
}
mbar = ioremap(res.start, 0xc000);
of_node_put(np);
if (!mbar) {
pr_err("mpc52xx_pm_prepare(): could not map registers\n");
return -ENOSYS;
}
sdram = mbar + 0x100;
cdm = mbar + 0x200;
intr = mbar + 0x500;
gpiow = mbar + 0xc00;
sram = mbar + 0x8000;
sram_size = 0x4000;
if (mpc52xx_suspend.board_suspend_prepare)
mpc52xx_suspend.board_suspend_prepare(mbar);
else {
printk(KERN_ALERT "%s: %i don't know how to wake up the board\n",
__func__, __LINE__);
goto out_unmap;
}
return 0;
out_unmap:
iounmap(mbar);
return -ENOSYS;
}
int mpc52xx_pm_enter(suspend_state_t state)
{
u32 clk_enables;
u32 msr, hid0;
u32 intr_main_mask;
void __iomem * irq_0x500 = (void __iomem *)CONFIG_KERNEL_START + 0x500;
unsigned long irq_0x500_stop = (unsigned long)irq_0x500 + mpc52xx_ds_cached_size;
char saved_0x500[mpc52xx_ds_cached_size];
intr_main_mask = in_be32(&intr->main_mask);
out_be32(&intr->main_mask, intr_main_mask | 0x1ffff);
mtspr(SPRN_DEC, 0x7fffffff);
memcpy(saved_sram, sram, sram_size);
memcpy(sram, mpc52xx_ds_sram, mpc52xx_ds_sram_size);
out_8(&cdm->ccs_sleep_enable, 1);
out_8(&cdm->osc_sleep_enable, 1);
out_8(&cdm->ccs_qreq_test, 1);
clk_enables = in_be32(&cdm->clk_enables);
out_be32(&cdm->clk_enables, clk_enables & 0x00088000);
msr = mfmsr();
mtmsr(msr & ~MSR_POW);
hid0 = mfspr(SPRN_HID0);
mtspr(SPRN_HID0, (hid0 & ~(HID0_DOZE | HID0_NAP | HID0_DPM)) | HID0_SLEEP);
memcpy(saved_0x500, irq_0x500, mpc52xx_ds_cached_size);
memcpy(irq_0x500, mpc52xx_ds_cached, mpc52xx_ds_cached_size);
flush_icache_range((unsigned long)irq_0x500, irq_0x500_stop);
mpc52xx_deep_sleep(sram, sdram, cdm, intr);
memcpy(irq_0x500, saved_0x500, mpc52xx_ds_cached_size);
flush_icache_range((unsigned long)irq_0x500, irq_0x500_stop);
mtmsr(msr & ~MSR_POW);
mtspr(SPRN_HID0, hid0);
mtmsr(msr);
out_be32(&cdm->clk_enables, clk_enables);
out_8(&cdm->ccs_sleep_enable, 0);
out_8(&cdm->osc_sleep_enable, 0);
memcpy(sram, saved_sram, sram_size);
out_be32(&intr->main_mask, intr_main_mask);
return 0;
}
void mpc52xx_pm_finish(void)
{
if (mpc52xx_suspend.board_resume_finish)
mpc52xx_suspend.board_resume_finish(mbar);
iounmap(mbar);
}
int __init mpc52xx_pm_init(void)
{
suspend_set_ops(&mpc52xx_pm_ops);
return 0;
}
