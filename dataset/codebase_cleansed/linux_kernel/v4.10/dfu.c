int i1480_rceb_check(const struct i1480 *i1480, const struct uwb_rceb *rceb,
const char *cmd, u8 context, u8 expected_type,
unsigned expected_event)
{
int result = 0;
struct device *dev = i1480->dev;
if (rceb->bEventContext != context) {
if (cmd)
dev_err(dev, "%s: unexpected context id 0x%02x "
"(expected 0x%02x)\n", cmd,
rceb->bEventContext, context);
result = -EINVAL;
}
if (rceb->bEventType != expected_type) {
if (cmd)
dev_err(dev, "%s: unexpected event type 0x%02x "
"(expected 0x%02x)\n", cmd,
rceb->bEventType, expected_type);
result = -EINVAL;
}
if (le16_to_cpu(rceb->wEvent) != expected_event) {
if (cmd)
dev_err(dev, "%s: unexpected event 0x%04x "
"(expected 0x%04x)\n", cmd,
le16_to_cpu(rceb->wEvent), expected_event);
result = -EINVAL;
}
return result;
}
ssize_t i1480_cmd(struct i1480 *i1480, const char *cmd_name, size_t cmd_size,
size_t reply_size)
{
ssize_t result;
struct uwb_rceb *reply = i1480->evt_buf;
struct uwb_rccb *cmd = i1480->cmd_buf;
u16 expected_event = reply->wEvent;
u8 expected_type = reply->bEventType;
u8 context;
init_completion(&i1480->evt_complete);
i1480->evt_result = -EINPROGRESS;
do {
get_random_bytes(&context, 1);
} while (context == 0x00 || context == 0xff);
cmd->bCommandContext = context;
result = i1480->cmd(i1480, cmd_name, cmd_size);
if (result < 0)
goto error;
result = wait_for_completion_interruptible_timeout(
&i1480->evt_complete, HZ);
if (result == 0) {
result = -ETIMEDOUT;
goto error;
}
if (result < 0)
goto error;
result = i1480->evt_result;
if (result < 0) {
dev_err(i1480->dev, "%s: command reply reception failed: %zd\n",
cmd_name, result);
goto error;
}
if (i1480_rceb_check(i1480, i1480->evt_buf, NULL,
0, 0xfd, 0x0022) == 0) {
result = i1480->wait_init_done(i1480);
if (result < 0)
goto error;
result = i1480->evt_result;
}
if (result != reply_size) {
dev_err(i1480->dev, "%s returned only %zu bytes, %zu expected\n",
cmd_name, result, reply_size);
result = -EINVAL;
goto error;
}
result = i1480_rceb_check(i1480, i1480->evt_buf, cmd_name, context,
expected_type, expected_event);
error:
return result;
}
static
int i1480_print_state(struct i1480 *i1480)
{
int result;
u32 *buf = (u32 *) i1480->cmd_buf;
result = i1480->read(i1480, 0x80080000, 2 * sizeof(*buf));
if (result < 0) {
dev_err(i1480->dev, "cannot read U & L states: %d\n", result);
goto error;
}
dev_info(i1480->dev, "state U 0x%08x, L 0x%08x\n", buf[0], buf[1]);
error:
return result;
}
int i1480_fw_upload(struct i1480 *i1480)
{
int result;
result = i1480_pre_fw_upload(i1480);
if (result < 0 && result != -ENOENT) {
i1480_print_state(i1480);
goto error;
}
result = i1480_mac_fw_upload(i1480);
if (result < 0) {
if (result == -ENOENT)
dev_err(i1480->dev, "Cannot locate MAC FW file '%s'\n",
i1480->mac_fw_name);
else
i1480_print_state(i1480);
goto error;
}
result = i1480_phy_fw_upload(i1480);
if (result < 0 && result != -ENOENT) {
i1480_print_state(i1480);
goto error_rc_release;
}
dev_info(i1480->dev, "firmware uploaded successfully\n");
error_rc_release:
if (i1480->rc_release)
i1480->rc_release(i1480);
result = 0;
error:
return result;
}
