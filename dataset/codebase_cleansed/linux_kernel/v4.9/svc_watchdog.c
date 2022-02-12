static int svc_watchdog_pm_notifier(struct notifier_block *notifier,
unsigned long pm_event, void *unused)
{
struct gb_svc_watchdog *watchdog =
container_of(notifier, struct gb_svc_watchdog, pm_notifier);
switch (pm_event) {
case PM_SUSPEND_PREPARE:
gb_svc_watchdog_disable(watchdog->svc);
break;
case PM_POST_SUSPEND:
gb_svc_watchdog_enable(watchdog->svc);
break;
default:
break;
}
return NOTIFY_DONE;
}
static void greybus_reset(struct work_struct *work)
{
static char start_path[256] = "/system/bin/start";
static char *envp[] = {
"HOME=/",
"PATH=/sbin:/vendor/bin:/system/sbin:/system/bin:/system/xbin",
NULL,
};
static char *argv[] = {
start_path,
"unipro_reset",
NULL,
};
printk(KERN_ERR "svc_watchdog: calling \"%s %s\" to reset greybus network!\n",
argv[0], argv[1]);
call_usermodehelper(start_path, argv, envp, UMH_WAIT_EXEC);
}
static void do_work(struct work_struct *work)
{
struct gb_svc_watchdog *watchdog;
struct gb_svc *svc;
int retval;
watchdog = container_of(work, struct gb_svc_watchdog, work.work);
svc = watchdog->svc;
dev_dbg(&svc->dev, "%s: ping.\n", __func__);
retval = gb_svc_ping(svc);
if (retval) {
dev_err(&svc->dev,
"SVC ping has returned %d, something is wrong!!!\n",
retval);
if (svc->action == GB_SVC_WATCHDOG_BITE_PANIC_KERNEL) {
panic("SVC is not responding\n");
} else if (svc->action == GB_SVC_WATCHDOG_BITE_RESET_UNIPRO) {
dev_err(&svc->dev, "Resetting the greybus network, watch out!!!\n");
INIT_DELAYED_WORK(&reset_work, greybus_reset);
schedule_delayed_work(&reset_work, HZ / 2);
watchdog->enabled = false;
}
}
if (watchdog->enabled)
schedule_delayed_work(&watchdog->work, SVC_WATCHDOG_PERIOD);
}
int gb_svc_watchdog_create(struct gb_svc *svc)
{
struct gb_svc_watchdog *watchdog;
int retval;
if (svc->watchdog)
return 0;
watchdog = kmalloc(sizeof(*watchdog), GFP_KERNEL);
if (!watchdog)
return -ENOMEM;
watchdog->enabled = false;
watchdog->svc = svc;
INIT_DELAYED_WORK(&watchdog->work, do_work);
svc->watchdog = watchdog;
watchdog->pm_notifier.notifier_call = svc_watchdog_pm_notifier;
retval = register_pm_notifier(&watchdog->pm_notifier);
if (retval) {
dev_err(&svc->dev, "error registering pm notifier(%d)\n",
retval);
goto svc_watchdog_create_err;
}
retval = gb_svc_watchdog_enable(svc);
if (retval) {
dev_err(&svc->dev, "error enabling watchdog (%d)\n", retval);
unregister_pm_notifier(&watchdog->pm_notifier);
goto svc_watchdog_create_err;
}
return retval;
svc_watchdog_create_err:
svc->watchdog = NULL;
kfree(watchdog);
return retval;
}
void gb_svc_watchdog_destroy(struct gb_svc *svc)
{
struct gb_svc_watchdog *watchdog = svc->watchdog;
if (!watchdog)
return;
unregister_pm_notifier(&watchdog->pm_notifier);
gb_svc_watchdog_disable(svc);
svc->watchdog = NULL;
kfree(watchdog);
}
bool gb_svc_watchdog_enabled(struct gb_svc *svc)
{
if (!svc || !svc->watchdog)
return false;
return svc->watchdog->enabled;
}
int gb_svc_watchdog_enable(struct gb_svc *svc)
{
struct gb_svc_watchdog *watchdog;
if (!svc->watchdog)
return -ENODEV;
watchdog = svc->watchdog;
if (watchdog->enabled)
return 0;
watchdog->enabled = true;
schedule_delayed_work(&watchdog->work, SVC_WATCHDOG_PERIOD);
return 0;
}
int gb_svc_watchdog_disable(struct gb_svc *svc)
{
struct gb_svc_watchdog *watchdog;
if (!svc->watchdog)
return -ENODEV;
watchdog = svc->watchdog;
if (!watchdog->enabled)
return 0;
watchdog->enabled = false;
cancel_delayed_work_sync(&watchdog->work);
return 0;
}
