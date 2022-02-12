unsigned long long sched_clock(void)
{
unsigned long long v = cnt32_to_63(readl(OST_OSCR));
v = ((v & 0x7fffffffffffffffULL) * 2235) >> 5;
return v;
}
static void puv3_cpu_pm_save(unsigned long *sleep_save)
{
}
static void puv3_cpu_pm_restore(unsigned long *sleep_save)
{
}
static int puv3_cpu_pm_prepare(void)
{
writel(virt_to_phys(puv3_cpu_resume), PM_DIVCFG);
return 0;
}
static void puv3_cpu_pm_enter(suspend_state_t state)
{
writel(RESETC_RSSR_HWR | RESETC_RSSR_WDR
| RESETC_RSSR_SMR | RESETC_RSSR_SWR, RESETC_RSSR);
switch (state) {
case PM_SUSPEND_MEM:
puv3_cpu_pm_prepare();
puv3_cpu_suspend(PM_PMCR_SFB);
break;
}
}
static int puv3_cpu_pm_valid(suspend_state_t state)
{
return state == PM_SUSPEND_MEM;
}
static void puv3_cpu_pm_finish(void)
{
}
static void __init puv3_init_pm(void)
{
puv3_cpu_pm_fns = &puv3_cpu_pm_fnss;
}
static inline void puv3_init_pm(void) {}
void puv3_ps2_init(void)
{
struct clk *bclk32;
bclk32 = clk_get(NULL, "BUS32_CLK");
writel(clk_get_rate(bclk32) / 200000, PS2_CNT);
}
void __init puv3_core_init(void)
{
puv3_init_pm();
puv3_ps2_init();
platform_device_register_simple("PKUnity-v3-RTC", -1,
puv3_rtc_resources, ARRAY_SIZE(puv3_rtc_resources));
platform_device_register_simple("PKUnity-v3-UMAL", -1,
puv3_umal_resources, ARRAY_SIZE(puv3_umal_resources));
platform_device_register_simple("PKUnity-v3-MMC", -1,
puv3_mmc_resources, ARRAY_SIZE(puv3_mmc_resources));
platform_device_register_simple("PKUnity-v3-UNIGFX", -1,
puv3_unigfx_resources, ARRAY_SIZE(puv3_unigfx_resources));
platform_device_register_simple("PKUnity-v3-PWM", -1,
puv3_pwm_resources, ARRAY_SIZE(puv3_pwm_resources));
platform_device_register_simple("PKUnity-v3-UART", 0,
puv3_uart0_resources, ARRAY_SIZE(puv3_uart0_resources));
platform_device_register_simple("PKUnity-v3-UART", 1,
puv3_uart1_resources, ARRAY_SIZE(puv3_uart1_resources));
platform_device_register_simple("PKUnity-v3-AC97", -1, NULL, 0);
platform_device_register_resndata(NULL, "musb_hdrc", -1,
puv3_usb_resources, ARRAY_SIZE(puv3_usb_resources),
&puv3_usb_plat, sizeof(puv3_usb_plat));
}
