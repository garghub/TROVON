void wimax_report_rfkill_hw(struct wimax_dev *wimax_dev,
enum wimax_rf_state state)
{
int result;
struct device *dev = wimax_dev_to_dev(wimax_dev);
enum wimax_st wimax_state;
d_fnstart(3, dev, "(wimax_dev %p state %u)\n", wimax_dev, state);
BUG_ON(state == WIMAX_RF_QUERY);
BUG_ON(state != WIMAX_RF_ON && state != WIMAX_RF_OFF);
mutex_lock(&wimax_dev->mutex);
result = wimax_dev_is_ready(wimax_dev);
if (result < 0)
goto error_not_ready;
if (state != wimax_dev->rf_hw) {
wimax_dev->rf_hw = state;
if (wimax_dev->rf_hw == WIMAX_RF_ON &&
wimax_dev->rf_sw == WIMAX_RF_ON)
wimax_state = WIMAX_ST_READY;
else
wimax_state = WIMAX_ST_RADIO_OFF;
result = rfkill_set_hw_state(wimax_dev->rfkill,
state == WIMAX_RF_OFF);
__wimax_state_change(wimax_dev, wimax_state);
}
error_not_ready:
mutex_unlock(&wimax_dev->mutex);
d_fnend(3, dev, "(wimax_dev %p state %u) = void [%d]\n",
wimax_dev, state, result);
}
void wimax_report_rfkill_sw(struct wimax_dev *wimax_dev,
enum wimax_rf_state state)
{
int result;
struct device *dev = wimax_dev_to_dev(wimax_dev);
enum wimax_st wimax_state;
d_fnstart(3, dev, "(wimax_dev %p state %u)\n", wimax_dev, state);
BUG_ON(state == WIMAX_RF_QUERY);
BUG_ON(state != WIMAX_RF_ON && state != WIMAX_RF_OFF);
mutex_lock(&wimax_dev->mutex);
result = wimax_dev_is_ready(wimax_dev);
if (result < 0)
goto error_not_ready;
if (state != wimax_dev->rf_sw) {
wimax_dev->rf_sw = state;
if (wimax_dev->rf_hw == WIMAX_RF_ON &&
wimax_dev->rf_sw == WIMAX_RF_ON)
wimax_state = WIMAX_ST_READY;
else
wimax_state = WIMAX_ST_RADIO_OFF;
__wimax_state_change(wimax_dev, wimax_state);
rfkill_set_sw_state(wimax_dev->rfkill, state == WIMAX_RF_OFF);
}
error_not_ready:
mutex_unlock(&wimax_dev->mutex);
d_fnend(3, dev, "(wimax_dev %p state %u) = void [%d]\n",
wimax_dev, state, result);
}
static
int __wimax_rf_toggle_radio(struct wimax_dev *wimax_dev,
enum wimax_rf_state state)
{
int result = 0;
struct device *dev = wimax_dev_to_dev(wimax_dev);
enum wimax_st wimax_state;
might_sleep();
d_fnstart(3, dev, "(wimax_dev %p state %u)\n", wimax_dev, state);
if (wimax_dev->rf_sw == state)
goto out_no_change;
if (wimax_dev->op_rfkill_sw_toggle != NULL)
result = wimax_dev->op_rfkill_sw_toggle(wimax_dev, state);
else if (state == WIMAX_RF_OFF)
result = -ENXIO;
else
result = 0;
if (result >= 0) {
result = 0;
wimax_dev->rf_sw = state;
wimax_state = state == WIMAX_RF_ON ?
WIMAX_ST_READY : WIMAX_ST_RADIO_OFF;
__wimax_state_change(wimax_dev, wimax_state);
}
out_no_change:
d_fnend(3, dev, "(wimax_dev %p state %u) = %d\n",
wimax_dev, state, result);
return result;
}
static int wimax_rfkill_set_radio_block(void *data, bool blocked)
{
int result;
struct wimax_dev *wimax_dev = data;
struct device *dev = wimax_dev_to_dev(wimax_dev);
enum wimax_rf_state rf_state;
d_fnstart(3, dev, "(wimax_dev %p blocked %u)\n", wimax_dev, blocked);
rf_state = WIMAX_RF_ON;
if (blocked)
rf_state = WIMAX_RF_OFF;
mutex_lock(&wimax_dev->mutex);
if (wimax_dev->state <= __WIMAX_ST_QUIESCING)
result = 0;
else
result = __wimax_rf_toggle_radio(wimax_dev, rf_state);
mutex_unlock(&wimax_dev->mutex);
d_fnend(3, dev, "(wimax_dev %p blocked %u) = %d\n",
wimax_dev, blocked, result);
return result;
}
int wimax_rfkill(struct wimax_dev *wimax_dev, enum wimax_rf_state state)
{
int result;
struct device *dev = wimax_dev_to_dev(wimax_dev);
d_fnstart(3, dev, "(wimax_dev %p state %u)\n", wimax_dev, state);
mutex_lock(&wimax_dev->mutex);
result = wimax_dev_is_ready(wimax_dev);
if (result < 0) {
if (result == -ENOMEDIUM && state == WIMAX_RF_QUERY)
result = WIMAX_RF_OFF << 1 | WIMAX_RF_OFF;
goto error_not_ready;
}
switch (state) {
case WIMAX_RF_ON:
case WIMAX_RF_OFF:
result = __wimax_rf_toggle_radio(wimax_dev, state);
if (result < 0)
goto error;
rfkill_set_sw_state(wimax_dev->rfkill, state == WIMAX_RF_OFF);
break;
case WIMAX_RF_QUERY:
break;
default:
result = -EINVAL;
goto error;
}
result = wimax_dev->rf_sw << 1 | wimax_dev->rf_hw;
error:
error_not_ready:
mutex_unlock(&wimax_dev->mutex);
d_fnend(3, dev, "(wimax_dev %p state %u) = %d\n",
wimax_dev, state, result);
return result;
}
int wimax_rfkill_add(struct wimax_dev *wimax_dev)
{
int result;
struct rfkill *rfkill;
struct device *dev = wimax_dev_to_dev(wimax_dev);
d_fnstart(3, dev, "(wimax_dev %p)\n", wimax_dev);
result = -ENOMEM;
rfkill = rfkill_alloc(wimax_dev->name, dev, RFKILL_TYPE_WIMAX,
&wimax_rfkill_ops, wimax_dev);
if (rfkill == NULL)
goto error_rfkill_allocate;
d_printf(1, dev, "rfkill %p\n", rfkill);
wimax_dev->rfkill = rfkill;
rfkill_init_sw_state(rfkill, 1);
result = rfkill_register(wimax_dev->rfkill);
if (result < 0)
goto error_rfkill_register;
if (wimax_dev->op_rfkill_sw_toggle == NULL)
wimax_dev->rf_sw = WIMAX_RF_ON;
d_fnend(3, dev, "(wimax_dev %p) = 0\n", wimax_dev);
return 0;
error_rfkill_register:
rfkill_destroy(wimax_dev->rfkill);
error_rfkill_allocate:
d_fnend(3, dev, "(wimax_dev %p) = %d\n", wimax_dev, result);
return result;
}
void wimax_rfkill_rm(struct wimax_dev *wimax_dev)
{
struct device *dev = wimax_dev_to_dev(wimax_dev);
d_fnstart(3, dev, "(wimax_dev %p)\n", wimax_dev);
rfkill_unregister(wimax_dev->rfkill);
rfkill_destroy(wimax_dev->rfkill);
d_fnend(3, dev, "(wimax_dev %p)\n", wimax_dev);
}
static
int wimax_gnl_doit_rfkill(struct sk_buff *skb, struct genl_info *info)
{
int result, ifindex;
struct wimax_dev *wimax_dev;
struct device *dev;
enum wimax_rf_state new_state;
d_fnstart(3, NULL, "(skb %p info %p)\n", skb, info);
result = -ENODEV;
if (info->attrs[WIMAX_GNL_RFKILL_IFIDX] == NULL) {
printk(KERN_ERR "WIMAX_GNL_OP_RFKILL: can't find IFIDX "
"attribute\n");
goto error_no_wimax_dev;
}
ifindex = nla_get_u32(info->attrs[WIMAX_GNL_RFKILL_IFIDX]);
wimax_dev = wimax_dev_get_by_genl_info(info, ifindex);
if (wimax_dev == NULL)
goto error_no_wimax_dev;
dev = wimax_dev_to_dev(wimax_dev);
result = -EINVAL;
if (info->attrs[WIMAX_GNL_RFKILL_STATE] == NULL) {
dev_err(dev, "WIMAX_GNL_RFKILL: can't find RFKILL_STATE "
"attribute\n");
goto error_no_pid;
}
new_state = nla_get_u32(info->attrs[WIMAX_GNL_RFKILL_STATE]);
result = wimax_rfkill(wimax_dev, new_state);
error_no_pid:
dev_put(wimax_dev->net_dev);
error_no_wimax_dev:
d_fnend(3, NULL, "(skb %p info %p) = %d\n", skb, info, result);
return result;
}
