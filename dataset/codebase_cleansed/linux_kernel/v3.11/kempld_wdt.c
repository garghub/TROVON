static int kempld_wdt_set_stage_action(struct kempld_wdt_data *wdt_data,
struct kempld_wdt_stage *stage,
u8 action)
{
struct kempld_device_data *pld = wdt_data->pld;
u8 stage_cfg;
if (!stage || !stage->mask)
return -EINVAL;
kempld_get_mutex(pld);
stage_cfg = kempld_read8(pld, KEMPLD_WDT_STAGE_CFG(stage->id));
stage_cfg &= ~STAGE_CFG_ACTION_MASK;
stage_cfg |= (action & STAGE_CFG_ACTION_MASK);
if (action == ACTION_RESET)
stage_cfg |= STAGE_CFG_ASSERT;
else
stage_cfg &= ~STAGE_CFG_ASSERT;
kempld_write8(pld, KEMPLD_WDT_STAGE_CFG(stage->id), stage_cfg);
kempld_release_mutex(pld);
return 0;
}
static int kempld_wdt_set_stage_timeout(struct kempld_wdt_data *wdt_data,
struct kempld_wdt_stage *stage,
unsigned int timeout)
{
struct kempld_device_data *pld = wdt_data->pld;
u32 prescaler = kempld_prescaler[PRESCALER_21];
u64 stage_timeout64;
u32 stage_timeout;
u32 remainder;
u8 stage_cfg;
if (!stage)
return -EINVAL;
stage_timeout64 = (u64)timeout * pld->pld_clock;
remainder = do_div(stage_timeout64, prescaler);
if (remainder)
stage_timeout64++;
if (stage_timeout64 > stage->mask)
return -EINVAL;
stage_timeout = stage_timeout64 & stage->mask;
kempld_get_mutex(pld);
stage_cfg = kempld_read8(pld, KEMPLD_WDT_STAGE_CFG(stage->id));
stage_cfg &= ~STAGE_CFG_PRESCALER_MASK;
stage_cfg |= STAGE_CFG_SET_PRESCALER(prescaler);
kempld_write8(pld, KEMPLD_WDT_STAGE_CFG(stage->id), stage_cfg);
kempld_write32(pld, KEMPLD_WDT_STAGE_TIMEOUT(stage->id),
stage_timeout);
kempld_release_mutex(pld);
return 0;
}
static unsigned int kempld_wdt_get_timeout(struct kempld_wdt_data *wdt_data,
struct kempld_wdt_stage *stage)
{
struct kempld_device_data *pld = wdt_data->pld;
unsigned int timeout;
u64 stage_timeout;
u32 prescaler;
u32 remainder;
u8 stage_cfg;
if (!stage->mask)
return 0;
stage_cfg = kempld_read8(pld, KEMPLD_WDT_STAGE_CFG(stage->id));
stage_timeout = kempld_read32(pld, KEMPLD_WDT_STAGE_TIMEOUT(stage->id));
prescaler = kempld_prescaler[STAGE_CFG_GET_PRESCALER(stage_cfg)];
stage_timeout = (stage_timeout & stage->mask) * prescaler;
remainder = do_div(stage_timeout, pld->pld_clock);
if (remainder)
stage_timeout++;
timeout = stage_timeout;
WARN_ON_ONCE(timeout != stage_timeout);
return timeout;
}
static int kempld_wdt_set_timeout(struct watchdog_device *wdd,
unsigned int timeout)
{
struct kempld_wdt_data *wdt_data = watchdog_get_drvdata(wdd);
struct kempld_wdt_stage *pretimeout_stage;
struct kempld_wdt_stage *timeout_stage;
int ret;
timeout_stage = &wdt_data->stage[STAGE_TIMEOUT];
pretimeout_stage = &wdt_data->stage[STAGE_PRETIMEOUT];
if (pretimeout_stage->mask && wdt_data->pretimeout > 0)
timeout = wdt_data->pretimeout;
ret = kempld_wdt_set_stage_action(wdt_data, timeout_stage,
ACTION_RESET);
if (ret)
return ret;
ret = kempld_wdt_set_stage_timeout(wdt_data, timeout_stage,
timeout);
if (ret)
return ret;
wdd->timeout = timeout;
return 0;
}
static int kempld_wdt_set_pretimeout(struct watchdog_device *wdd,
unsigned int pretimeout)
{
struct kempld_wdt_data *wdt_data = watchdog_get_drvdata(wdd);
struct kempld_wdt_stage *pretimeout_stage;
u8 action = ACTION_NONE;
int ret;
pretimeout_stage = &wdt_data->stage[STAGE_PRETIMEOUT];
if (!pretimeout_stage->mask)
return -ENXIO;
if (pretimeout > wdd->timeout)
return -EINVAL;
if (pretimeout > 0)
action = ACTION_NMI;
ret = kempld_wdt_set_stage_action(wdt_data, pretimeout_stage,
action);
if (ret)
return ret;
ret = kempld_wdt_set_stage_timeout(wdt_data, pretimeout_stage,
wdd->timeout - pretimeout);
if (ret)
return ret;
wdt_data->pretimeout = pretimeout;
return 0;
}
static void kempld_wdt_update_timeouts(struct kempld_wdt_data *wdt_data)
{
struct kempld_device_data *pld = wdt_data->pld;
struct kempld_wdt_stage *pretimeout_stage;
struct kempld_wdt_stage *timeout_stage;
unsigned int pretimeout, timeout;
pretimeout_stage = &wdt_data->stage[STAGE_PRETIMEOUT];
timeout_stage = &wdt_data->stage[STAGE_TIMEOUT];
kempld_get_mutex(pld);
pretimeout = kempld_wdt_get_timeout(wdt_data, pretimeout_stage);
timeout = kempld_wdt_get_timeout(wdt_data, timeout_stage);
kempld_release_mutex(pld);
if (pretimeout)
wdt_data->pretimeout = timeout;
else
wdt_data->pretimeout = 0;
wdt_data->wdd.timeout = pretimeout + timeout;
}
static int kempld_wdt_start(struct watchdog_device *wdd)
{
struct kempld_wdt_data *wdt_data = watchdog_get_drvdata(wdd);
struct kempld_device_data *pld = wdt_data->pld;
u8 status;
int ret;
ret = kempld_wdt_set_timeout(wdd, wdd->timeout);
if (ret)
return ret;
kempld_get_mutex(pld);
status = kempld_read8(pld, KEMPLD_WDT_CFG);
status |= KEMPLD_WDT_CFG_ENABLE;
kempld_write8(pld, KEMPLD_WDT_CFG, status);
status = kempld_read8(pld, KEMPLD_WDT_CFG);
kempld_release_mutex(pld);
if (!(status & KEMPLD_WDT_CFG_ENABLE))
return -EACCES;
return 0;
}
static int kempld_wdt_stop(struct watchdog_device *wdd)
{
struct kempld_wdt_data *wdt_data = watchdog_get_drvdata(wdd);
struct kempld_device_data *pld = wdt_data->pld;
u8 status;
kempld_get_mutex(pld);
status = kempld_read8(pld, KEMPLD_WDT_CFG);
status &= ~KEMPLD_WDT_CFG_ENABLE;
kempld_write8(pld, KEMPLD_WDT_CFG, status);
status = kempld_read8(pld, KEMPLD_WDT_CFG);
kempld_release_mutex(pld);
if (status & KEMPLD_WDT_CFG_ENABLE)
return -EACCES;
return 0;
}
static int kempld_wdt_keepalive(struct watchdog_device *wdd)
{
struct kempld_wdt_data *wdt_data = watchdog_get_drvdata(wdd);
struct kempld_device_data *pld = wdt_data->pld;
kempld_get_mutex(pld);
kempld_write8(pld, KEMPLD_WDT_KICK, 'K');
kempld_release_mutex(pld);
return 0;
}
static long kempld_wdt_ioctl(struct watchdog_device *wdd, unsigned int cmd,
unsigned long arg)
{
struct kempld_wdt_data *wdt_data = watchdog_get_drvdata(wdd);
void __user *argp = (void __user *)arg;
int ret = -ENOIOCTLCMD;
int __user *p = argp;
int new_value;
switch (cmd) {
case WDIOC_SETPRETIMEOUT:
if (get_user(new_value, p))
return -EFAULT;
ret = kempld_wdt_set_pretimeout(wdd, new_value);
if (ret)
return ret;
ret = kempld_wdt_keepalive(wdd);
break;
case WDIOC_GETPRETIMEOUT:
ret = put_user(wdt_data->pretimeout, (int *)arg);
break;
}
return ret;
}
static int kempld_wdt_probe_stages(struct watchdog_device *wdd)
{
struct kempld_wdt_data *wdt_data = watchdog_get_drvdata(wdd);
struct kempld_device_data *pld = wdt_data->pld;
struct kempld_wdt_stage *pretimeout_stage;
struct kempld_wdt_stage *timeout_stage;
u8 index, data, data_orig;
u32 mask;
int i, j;
pretimeout_stage = &wdt_data->stage[STAGE_PRETIMEOUT];
timeout_stage = &wdt_data->stage[STAGE_TIMEOUT];
pretimeout_stage->mask = 0;
timeout_stage->mask = 0;
for (i = 0; i < 3; i++) {
index = KEMPLD_WDT_STAGE_TIMEOUT(i);
mask = 0;
kempld_get_mutex(pld);
for (j = 0; j < 4; j++) {
data_orig = kempld_read8(pld, index + j);
kempld_write8(pld, index + j, 0x00);
data = kempld_read8(pld, index + j);
if (data != 0x00)
break;
kempld_write8(pld, index + j, data_orig);
mask |= 0xff << (j * 8);
}
kempld_release_mutex(pld);
if (!timeout_stage->mask) {
timeout_stage->mask = mask;
timeout_stage->id = i;
} else {
if (pld->feature_mask & KEMPLD_FEATURE_BIT_NMI) {
pretimeout_stage->mask = timeout_stage->mask;
timeout_stage->mask = mask;
pretimeout_stage->id = timeout_stage->id;
timeout_stage->id = i;
}
break;
}
}
if (!timeout_stage->mask)
return -ENODEV;
return 0;
}
static int kempld_wdt_probe(struct platform_device *pdev)
{
struct kempld_device_data *pld = dev_get_drvdata(pdev->dev.parent);
struct kempld_wdt_data *wdt_data;
struct device *dev = &pdev->dev;
struct watchdog_device *wdd;
u8 status;
int ret = 0;
wdt_data = devm_kzalloc(dev, sizeof(*wdt_data), GFP_KERNEL);
if (!wdt_data)
return -ENOMEM;
wdt_data->pld = pld;
wdd = &wdt_data->wdd;
wdd->parent = dev;
kempld_get_mutex(pld);
status = kempld_read8(pld, KEMPLD_WDT_CFG);
kempld_release_mutex(pld);
if (status & (KEMPLD_WDT_CFG_ENABLE_LOCK |
KEMPLD_WDT_CFG_GLOBAL_LOCK)) {
if (!nowayout)
dev_warn(dev,
"Forcing nowayout - watchdog lock enabled!\n");
nowayout = true;
}
wdd->info = &kempld_wdt_info;
wdd->ops = &kempld_wdt_ops;
watchdog_set_drvdata(wdd, wdt_data);
watchdog_set_nowayout(wdd, nowayout);
ret = kempld_wdt_probe_stages(wdd);
if (ret)
return ret;
kempld_wdt_set_timeout(wdd, timeout);
kempld_wdt_set_pretimeout(wdd, pretimeout);
if (status & KEMPLD_WDT_CFG_ENABLE) {
kempld_wdt_update_timeouts(wdt_data);
dev_info(dev, "Watchdog was already enabled\n");
}
platform_set_drvdata(pdev, wdt_data);
ret = watchdog_register_device(wdd);
if (ret)
return ret;
dev_info(dev, "Watchdog registered with %ds timeout\n", wdd->timeout);
return 0;
}
static void kempld_wdt_shutdown(struct platform_device *pdev)
{
struct kempld_wdt_data *wdt_data = platform_get_drvdata(pdev);
kempld_wdt_stop(&wdt_data->wdd);
}
static int kempld_wdt_remove(struct platform_device *pdev)
{
struct kempld_wdt_data *wdt_data = platform_get_drvdata(pdev);
struct watchdog_device *wdd = &wdt_data->wdd;
int ret = 0;
if (!nowayout)
ret = kempld_wdt_stop(wdd);
watchdog_unregister_device(wdd);
return ret;
}
static int kempld_wdt_suspend(struct platform_device *pdev,
pm_message_t message)
{
struct kempld_wdt_data *wdt_data = platform_get_drvdata(pdev);
struct kempld_device_data *pld = wdt_data->pld;
struct watchdog_device *wdd = &wdt_data->wdd;
kempld_get_mutex(pld);
wdt_data->pm_status_store = kempld_read8(pld, KEMPLD_WDT_CFG);
kempld_release_mutex(pld);
kempld_wdt_update_timeouts(wdt_data);
if (wdt_data->pm_status_store & KEMPLD_WDT_CFG_ENABLE)
return kempld_wdt_stop(wdd);
return 0;
}
static int kempld_wdt_resume(struct platform_device *pdev)
{
struct kempld_wdt_data *wdt_data = platform_get_drvdata(pdev);
struct watchdog_device *wdd = &wdt_data->wdd;
if (wdt_data->pm_status_store & KEMPLD_WDT_CFG_ENABLE)
return kempld_wdt_start(wdd);
else
return kempld_wdt_stop(wdd);
}
