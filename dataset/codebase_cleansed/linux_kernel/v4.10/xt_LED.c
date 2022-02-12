static unsigned int
led_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_led_info *ledinfo = par->targinfo;
struct xt_led_info_internal *ledinternal = ledinfo->internal_data;
unsigned long led_delay = XT_LED_BLINK_DELAY;
if ((ledinfo->delay > 0) && ledinfo->always_blink &&
timer_pending(&ledinternal->timer))
led_trigger_blink_oneshot(&ledinternal->netfilter_led_trigger,
&led_delay, &led_delay, 1);
else
led_trigger_event(&ledinternal->netfilter_led_trigger, LED_FULL);
if (ledinfo->delay > 0) {
mod_timer(&ledinternal->timer,
jiffies + msecs_to_jiffies(ledinfo->delay));
} else if (ledinfo->delay == 0) {
led_trigger_event(&ledinternal->netfilter_led_trigger, LED_OFF);
}
return XT_CONTINUE;
}
static void led_timeout_callback(unsigned long data)
{
struct xt_led_info_internal *ledinternal = (struct xt_led_info_internal *)data;
led_trigger_event(&ledinternal->netfilter_led_trigger, LED_OFF);
}
static struct xt_led_info_internal *led_trigger_lookup(const char *name)
{
struct xt_led_info_internal *ledinternal;
list_for_each_entry(ledinternal, &xt_led_triggers, list) {
if (!strcmp(name, ledinternal->netfilter_led_trigger.name)) {
return ledinternal;
}
}
return NULL;
}
static int led_tg_check(const struct xt_tgchk_param *par)
{
struct xt_led_info *ledinfo = par->targinfo;
struct xt_led_info_internal *ledinternal;
int err;
if (ledinfo->id[0] == '\0') {
pr_info("No 'id' parameter given.\n");
return -EINVAL;
}
mutex_lock(&xt_led_mutex);
ledinternal = led_trigger_lookup(ledinfo->id);
if (ledinternal) {
ledinternal->refcnt++;
goto out;
}
err = -ENOMEM;
ledinternal = kzalloc(sizeof(struct xt_led_info_internal), GFP_KERNEL);
if (!ledinternal)
goto exit_mutex_only;
ledinternal->trigger_id = kstrdup(ledinfo->id, GFP_KERNEL);
if (!ledinternal->trigger_id)
goto exit_internal_alloc;
ledinternal->refcnt = 1;
ledinternal->netfilter_led_trigger.name = ledinternal->trigger_id;
err = led_trigger_register(&ledinternal->netfilter_led_trigger);
if (err) {
pr_err("Trigger name is already in use.\n");
goto exit_alloc;
}
if (ledinfo->delay > 0)
setup_timer(&ledinternal->timer, led_timeout_callback,
(unsigned long)ledinternal);
list_add_tail(&ledinternal->list, &xt_led_triggers);
out:
mutex_unlock(&xt_led_mutex);
ledinfo->internal_data = ledinternal;
return 0;
exit_alloc:
kfree(ledinternal->trigger_id);
exit_internal_alloc:
kfree(ledinternal);
exit_mutex_only:
mutex_unlock(&xt_led_mutex);
return err;
}
static void led_tg_destroy(const struct xt_tgdtor_param *par)
{
const struct xt_led_info *ledinfo = par->targinfo;
struct xt_led_info_internal *ledinternal = ledinfo->internal_data;
mutex_lock(&xt_led_mutex);
if (--ledinternal->refcnt) {
mutex_unlock(&xt_led_mutex);
return;
}
list_del(&ledinternal->list);
if (ledinfo->delay > 0)
del_timer_sync(&ledinternal->timer);
led_trigger_unregister(&ledinternal->netfilter_led_trigger);
mutex_unlock(&xt_led_mutex);
kfree(ledinternal->trigger_id);
kfree(ledinternal);
}
static int __init led_tg_init(void)
{
return xt_register_target(&led_tg_reg);
}
static void __exit led_tg_exit(void)
{
xt_unregister_target(&led_tg_reg);
}
