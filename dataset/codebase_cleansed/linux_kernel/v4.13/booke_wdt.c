static unsigned long long period_to_sec(unsigned int period)
{
unsigned long long tmp = 1ULL << (64 - period);
unsigned long tmp2 = ppc_tb_freq;
tmp2 = tmp2 / 5 * 2;
do_div(tmp, tmp2);
return tmp;
}
static unsigned int sec_to_period(unsigned int secs)
{
unsigned int period;
for (period = 63; period > 0; period--) {
if (period_to_sec(period) >= secs)
return period;
}
return 0;
}
static unsigned long long period_to_sec(unsigned int period)
{
return period;
}
static unsigned int sec_to_period(unsigned int secs)
{
return secs;
}
static void __booke_wdt_set(void *data)
{
u32 val;
struct watchdog_device *wdog = data;
val = mfspr(SPRN_TCR);
val &= ~WDTP_MASK;
val |= WDTP(sec_to_period(wdog->timeout));
mtspr(SPRN_TCR, val);
}
static void booke_wdt_set(void *data)
{
on_each_cpu(__booke_wdt_set, data, 0);
}
static void __booke_wdt_ping(void *data)
{
mtspr(SPRN_TSR, TSR_ENW|TSR_WIS);
}
static int booke_wdt_ping(struct watchdog_device *wdog)
{
on_each_cpu(__booke_wdt_ping, NULL, 0);
return 0;
}
static void __booke_wdt_enable(void *data)
{
u32 val;
struct watchdog_device *wdog = data;
__booke_wdt_ping(NULL);
val = mfspr(SPRN_TCR);
val &= ~WDTP_MASK;
val |= (TCR_WIE|TCR_WRC(WRC_CHIP)|WDTP(sec_to_period(wdog->timeout)));
mtspr(SPRN_TCR, val);
}
static void __booke_wdt_disable(void *data)
{
u32 val;
val = mfspr(SPRN_TCR);
val &= ~(TCR_WIE | WDTP_MASK);
mtspr(SPRN_TCR, val);
__booke_wdt_ping(NULL);
}
static int booke_wdt_start(struct watchdog_device *wdog)
{
on_each_cpu(__booke_wdt_enable, wdog, 0);
pr_debug("watchdog enabled (timeout = %u sec)\n", wdog->timeout);
return 0;
}
static int booke_wdt_stop(struct watchdog_device *wdog)
{
on_each_cpu(__booke_wdt_disable, NULL, 0);
pr_debug("watchdog disabled\n");
return 0;
}
static int booke_wdt_set_timeout(struct watchdog_device *wdt_dev,
unsigned int timeout)
{
wdt_dev->timeout = timeout;
booke_wdt_set(wdt_dev);
return 0;
}
static void __exit booke_wdt_exit(void)
{
watchdog_unregister_device(&booke_wdt_dev);
}
static int __init booke_wdt_init(void)
{
int ret = 0;
bool nowayout = WATCHDOG_NOWAYOUT;
pr_info("powerpc book-e watchdog driver loaded\n");
booke_wdt_info.firmware_version = cur_cpu_spec->pvr_value;
booke_wdt_set_timeout(&booke_wdt_dev,
period_to_sec(booke_wdt_period));
watchdog_set_nowayout(&booke_wdt_dev, nowayout);
booke_wdt_dev.max_timeout = MAX_WDT_TIMEOUT;
if (booke_wdt_enabled)
booke_wdt_start(&booke_wdt_dev);
ret = watchdog_register_device(&booke_wdt_dev);
return ret;
}
