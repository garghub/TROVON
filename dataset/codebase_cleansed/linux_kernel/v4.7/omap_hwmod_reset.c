int omap_hwmod_aess_preprogram(struct omap_hwmod *oh)
{
void __iomem *va;
va = omap_hwmod_get_mpu_rt_va(oh);
if (!va)
return -EINVAL;
aess_enable_autogating(va);
return 0;
}
static void omap_rtc_wait_not_busy(struct omap_hwmod *oh)
{
int i;
omap_test_timeout(omap_hwmod_read(oh, OMAP_RTC_STATUS_REG)
& OMAP_RTC_STATUS_BUSY, OMAP_RTC_MAX_READY_TIME, i);
}
void omap_hwmod_rtc_unlock(struct omap_hwmod *oh)
{
local_irq_disable();
omap_rtc_wait_not_busy(oh);
omap_hwmod_write(OMAP_RTC_KICK0_VALUE, oh, OMAP_RTC_KICK0_REG);
omap_hwmod_write(OMAP_RTC_KICK1_VALUE, oh, OMAP_RTC_KICK1_REG);
local_irq_enable();
}
void omap_hwmod_rtc_lock(struct omap_hwmod *oh)
{
local_irq_disable();
omap_rtc_wait_not_busy(oh);
omap_hwmod_write(0x0, oh, OMAP_RTC_KICK0_REG);
omap_hwmod_write(0x0, oh, OMAP_RTC_KICK1_REG);
local_irq_enable();
}
