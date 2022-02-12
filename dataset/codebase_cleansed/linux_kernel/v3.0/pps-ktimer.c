static void pps_ktimer_event(unsigned long ptr)
{
struct pps_event_time ts;
pps_get_ts(&ts);
pps_event(pps, &ts, PPS_CAPTUREASSERT, NULL);
mod_timer(&ktimer, jiffies + HZ);
}
static void pps_ktimer_echo(struct pps_device *pps, int event, void *data)
{
dev_info(pps->dev, "echo %s %s\n",
event & PPS_CAPTUREASSERT ? "assert" : "",
event & PPS_CAPTURECLEAR ? "clear" : "");
}
static void __exit pps_ktimer_exit(void)
{
dev_info(pps->dev, "ktimer PPS source unregistered\n");
del_timer_sync(&ktimer);
pps_unregister_source(pps);
}
static int __init pps_ktimer_init(void)
{
pps = pps_register_source(&pps_ktimer_info,
PPS_CAPTUREASSERT | PPS_OFFSETASSERT);
if (pps == NULL) {
pr_err("cannot register PPS source\n");
return -ENOMEM;
}
setup_timer(&ktimer, pps_ktimer_event, 0);
mod_timer(&ktimer, jiffies + HZ);
dev_info(pps->dev, "ktimer PPS source registered\n");
return 0;
}
