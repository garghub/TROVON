static void pmf_gpio_set_hw_reset(struct gpio_runtime *rt, int on)
{
struct pmf_args args = { .count = 1, .u[0].v = !!on };
int rc;
if (unlikely(!rt)) return;
rc = pmf_call_function(rt->node, "hw-reset", &args);
if (rc)
printk(KERN_WARNING "pmf_gpio_set_hw_reset"
" failed, rc: %d\n", rc);
}
static void pmf_gpio_all_amps_off(struct gpio_runtime *rt)
{
int saved;
if (unlikely(!rt)) return;
saved = rt->implementation_private;
pmf_gpio_set_headphone(rt, 0);
pmf_gpio_set_amp(rt, 0);
pmf_gpio_set_lineout(rt, 0);
rt->implementation_private = saved;
}
static void pmf_gpio_all_amps_restore(struct gpio_runtime *rt)
{
int s;
if (unlikely(!rt)) return;
s = rt->implementation_private;
pmf_gpio_set_headphone(rt, (s>>0)&1);
pmf_gpio_set_amp(rt, (s>>1)&1);
pmf_gpio_set_lineout(rt, (s>>2)&1);
}
static void pmf_handle_notify(struct work_struct *work)
{
struct gpio_notification *notif =
container_of(work, struct gpio_notification, work.work);
mutex_lock(&notif->mutex);
if (notif->notify)
notif->notify(notif->data);
mutex_unlock(&notif->mutex);
}
static void pmf_gpio_init(struct gpio_runtime *rt)
{
pmf_gpio_all_amps_off(rt);
rt->implementation_private = 0;
INIT_DELAYED_WORK(&rt->headphone_notify.work, pmf_handle_notify);
INIT_DELAYED_WORK(&rt->line_in_notify.work, pmf_handle_notify);
INIT_DELAYED_WORK(&rt->line_out_notify.work, pmf_handle_notify);
mutex_init(&rt->headphone_notify.mutex);
mutex_init(&rt->line_in_notify.mutex);
mutex_init(&rt->line_out_notify.mutex);
}
static void pmf_gpio_exit(struct gpio_runtime *rt)
{
pmf_gpio_all_amps_off(rt);
rt->implementation_private = 0;
if (rt->headphone_notify.gpio_private)
pmf_unregister_irq_client(rt->headphone_notify.gpio_private);
if (rt->line_in_notify.gpio_private)
pmf_unregister_irq_client(rt->line_in_notify.gpio_private);
if (rt->line_out_notify.gpio_private)
pmf_unregister_irq_client(rt->line_out_notify.gpio_private);
cancel_delayed_work_sync(&rt->headphone_notify.work);
cancel_delayed_work_sync(&rt->line_in_notify.work);
cancel_delayed_work_sync(&rt->line_out_notify.work);
mutex_destroy(&rt->headphone_notify.mutex);
mutex_destroy(&rt->line_in_notify.mutex);
mutex_destroy(&rt->line_out_notify.mutex);
kfree(rt->headphone_notify.gpio_private);
kfree(rt->line_in_notify.gpio_private);
kfree(rt->line_out_notify.gpio_private);
}
static void pmf_handle_notify_irq(void *data)
{
struct gpio_notification *notif = data;
schedule_delayed_work(&notif->work, 0);
}
static int pmf_set_notify(struct gpio_runtime *rt,
enum notify_type type,
notify_func_t notify,
void *data)
{
struct gpio_notification *notif;
notify_func_t old;
struct pmf_irq_client *irq_client;
char *name;
int err = -EBUSY;
switch (type) {
case AOA_NOTIFY_HEADPHONE:
notif = &rt->headphone_notify;
name = "headphone-detect";
break;
case AOA_NOTIFY_LINE_IN:
notif = &rt->line_in_notify;
name = "linein-detect";
break;
case AOA_NOTIFY_LINE_OUT:
notif = &rt->line_out_notify;
name = "lineout-detect";
break;
default:
return -EINVAL;
}
mutex_lock(&notif->mutex);
old = notif->notify;
if (!old && !notify) {
err = 0;
goto out_unlock;
}
if (old && notify) {
if (old == notify && notif->data == data)
err = 0;
goto out_unlock;
}
if (old && !notify) {
irq_client = notif->gpio_private;
pmf_unregister_irq_client(irq_client);
kfree(irq_client);
notif->gpio_private = NULL;
}
if (!old && notify) {
irq_client = kzalloc(sizeof(struct pmf_irq_client),
GFP_KERNEL);
if (!irq_client) {
err = -ENOMEM;
goto out_unlock;
}
irq_client->data = notif;
irq_client->handler = pmf_handle_notify_irq;
irq_client->owner = THIS_MODULE;
err = pmf_register_irq_client(rt->node,
name,
irq_client);
if (err) {
printk(KERN_ERR "snd-aoa: gpio layer failed to"
" register %s irq (%d)\n", name, err);
kfree(irq_client);
goto out_unlock;
}
notif->gpio_private = irq_client;
}
notif->notify = notify;
notif->data = data;
err = 0;
out_unlock:
mutex_unlock(&notif->mutex);
return err;
}
static int pmf_get_detect(struct gpio_runtime *rt,
enum notify_type type)
{
char *name;
int err = -EBUSY, ret;
struct pmf_args args = { .count = 1, .u[0].p = &ret };
switch (type) {
case AOA_NOTIFY_HEADPHONE:
name = "headphone-detect";
break;
case AOA_NOTIFY_LINE_IN:
name = "linein-detect";
break;
case AOA_NOTIFY_LINE_OUT:
name = "lineout-detect";
break;
default:
return -EINVAL;
}
err = pmf_call_function(rt->node, name, &args);
if (err)
return err;
return ret;
}
