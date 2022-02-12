static int opal_power_control_event(struct notifier_block *nb,
unsigned long msg_type, void *msg)
{
struct opal_msg *power_msg = msg;
uint64_t type;
type = be64_to_cpu(power_msg->params[0]);
switch (type) {
case SOFT_REBOOT:
case SOFT_OFF:
pr_info("OPAL: poweroff requested\n");
orderly_poweroff(true);
break;
default:
pr_err("OPAL: power control type unexpected %016llx\n", type);
}
return 0;
}
static int __init opal_power_control_init(void)
{
int ret;
ret = opal_message_notifier_register(OPAL_MSG_SHUTDOWN,
&opal_power_control_nb);
if (ret) {
pr_err("%s: Can't register OPAL event notifier (%d)\n",
__func__, ret);
return ret;
}
return 0;
}
