int wimax_reset(struct wimax_dev *wimax_dev)
{
int result = -EINVAL;
struct device *dev = wimax_dev_to_dev(wimax_dev);
enum wimax_st state;
might_sleep();
d_fnstart(3, dev, "(wimax_dev %p)\n", wimax_dev);
mutex_lock(&wimax_dev->mutex);
dev_hold(wimax_dev->net_dev);
state = wimax_dev->state;
mutex_unlock(&wimax_dev->mutex);
if (state >= WIMAX_ST_DOWN) {
mutex_lock(&wimax_dev->mutex_reset);
result = wimax_dev->op_reset(wimax_dev);
mutex_unlock(&wimax_dev->mutex_reset);
}
dev_put(wimax_dev->net_dev);
d_fnend(3, dev, "(wimax_dev %p) = %d\n", wimax_dev, result);
return result;
}
int wimax_gnl_doit_reset(struct sk_buff *skb, struct genl_info *info)
{
int result, ifindex;
struct wimax_dev *wimax_dev;
d_fnstart(3, NULL, "(skb %p info %p)\n", skb, info);
result = -ENODEV;
if (info->attrs[WIMAX_GNL_RESET_IFIDX] == NULL) {
printk(KERN_ERR "WIMAX_GNL_OP_RFKILL: can't find IFIDX "
"attribute\n");
goto error_no_wimax_dev;
}
ifindex = nla_get_u32(info->attrs[WIMAX_GNL_RESET_IFIDX]);
wimax_dev = wimax_dev_get_by_genl_info(info, ifindex);
if (wimax_dev == NULL)
goto error_no_wimax_dev;
result = wimax_reset(wimax_dev);
dev_put(wimax_dev->net_dev);
error_no_wimax_dev:
d_fnend(3, NULL, "(skb %p info %p) = %d\n", skb, info, result);
return result;
}
