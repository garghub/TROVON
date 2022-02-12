static int sun4v_wdt_stop(struct watchdog_device *wdd)
{
sun4v_mach_set_watchdog(0, NULL);
return 0;
}
static int sun4v_wdt_ping(struct watchdog_device *wdd)
{
int hverr;
hverr = sun4v_mach_set_watchdog(wdd->timeout * 1000, NULL);
if (hverr == HV_EINVAL)
return -EINVAL;
return 0;
}
static int sun4v_wdt_set_timeout(struct watchdog_device *wdd,
unsigned int timeout)
{
wdd->timeout = timeout;
return 0;
}
static int __init sun4v_wdt_init(void)
{
struct mdesc_handle *handle;
u64 node;
const u64 *value;
int err = 0;
unsigned long major = 1, minor = 1;
handle = mdesc_grab();
if (!handle)
return -ENODEV;
node = mdesc_node_by_name(handle, MDESC_NODE_NULL, "platform");
err = -ENODEV;
if (node == MDESC_NODE_NULL)
goto out_release;
if (sun4v_hvapi_register(HV_GRP_CORE, major, &minor))
goto out_hv_unreg;
value = mdesc_get_property(handle, node, "watchdog-resolution", NULL);
err = -EINVAL;
if (value) {
if (*value == 0 ||
*value > WDT_DEFAULT_RESOLUTION_MS)
goto out_hv_unreg;
}
value = mdesc_get_property(handle, node, "watchdog-max-timeout", NULL);
if (value) {
if (*value < wdd.min_timeout * 1000)
goto out_hv_unreg;
if (*value < wdd.max_timeout * 1000)
wdd.max_timeout = *value / 1000;
}
watchdog_init_timeout(&wdd, timeout, NULL);
watchdog_set_nowayout(&wdd, nowayout);
err = watchdog_register_device(&wdd);
if (err)
goto out_hv_unreg;
pr_info("initialized (timeout=%ds, nowayout=%d)\n",
wdd.timeout, nowayout);
mdesc_release(handle);
return 0;
out_hv_unreg:
sun4v_hvapi_unregister(HV_GRP_CORE);
out_release:
mdesc_release(handle);
return err;
}
static void __exit sun4v_wdt_exit(void)
{
sun4v_hvapi_unregister(HV_GRP_CORE);
watchdog_unregister_device(&wdd);
}
