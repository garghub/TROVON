static bool cros_ec_keyb_has_ghosting(struct cros_ec_keyb *ckdev, uint8_t *buf)
{
int col1, col2, buf1, buf2;
struct device *dev = ckdev->dev;
uint8_t *valid_keys = ckdev->valid_keys;
for (col1 = 0; col1 < ckdev->cols; col1++) {
buf1 = buf[col1] & valid_keys[col1];
for (col2 = col1 + 1; col2 < ckdev->cols; col2++) {
buf2 = buf[col2] & valid_keys[col2];
if (hweight8(buf1 & buf2) > 1) {
dev_dbg(dev, "ghost found at: B[%02d]:0x%02x & B[%02d]:0x%02x",
col1, buf1, col2, buf2);
return true;
}
}
}
return false;
}
static void cros_ec_keyb_process(struct cros_ec_keyb *ckdev,
uint8_t *kb_state, int len)
{
struct input_dev *idev = ckdev->idev;
int col, row;
int new_state;
int old_state;
int num_cols;
num_cols = len;
if (ckdev->ghost_filter && cros_ec_keyb_has_ghosting(ckdev, kb_state)) {
dev_dbg(ckdev->dev, "ghosting found\n");
return;
}
for (col = 0; col < ckdev->cols; col++) {
for (row = 0; row < ckdev->rows; row++) {
int pos = MATRIX_SCAN_CODE(row, col, ckdev->row_shift);
const unsigned short *keycodes = idev->keycode;
new_state = kb_state[col] & (1 << row);
old_state = ckdev->old_kb_state[col] & (1 << row);
if (new_state != old_state) {
dev_dbg(ckdev->dev,
"changed: [r%d c%d]: byte %02x\n",
row, col, new_state);
input_report_key(idev, keycodes[pos],
new_state);
}
}
ckdev->old_kb_state[col] = kb_state[col];
}
input_sync(ckdev->idev);
}
static void cros_ec_keyb_report_bs(struct cros_ec_keyb *ckdev,
unsigned int ev_type, u32 mask)
{
struct input_dev *idev = ckdev->bs_idev;
int i;
for (i = 0; i < ARRAY_SIZE(cros_ec_keyb_bs); i++) {
const struct cros_ec_bs_map *map = &cros_ec_keyb_bs[i];
if (map->ev_type != ev_type)
continue;
input_event(idev, ev_type, map->code,
!!(mask & BIT(map->bit)) ^ map->inverted);
}
input_sync(idev);
}
static int cros_ec_keyb_work(struct notifier_block *nb,
unsigned long queued_during_suspend, void *_notify)
{
struct cros_ec_keyb *ckdev = container_of(nb, struct cros_ec_keyb,
notifier);
u32 val;
unsigned int ev_type;
switch (ckdev->ec->event_data.event_type) {
case EC_MKBP_EVENT_KEY_MATRIX:
if (queued_during_suspend)
return NOTIFY_OK;
if (ckdev->ec->event_size != ckdev->cols) {
dev_err(ckdev->dev,
"Discarded incomplete key matrix event.\n");
return NOTIFY_OK;
}
cros_ec_keyb_process(ckdev,
ckdev->ec->event_data.data.key_matrix,
ckdev->ec->event_size);
break;
case EC_MKBP_EVENT_BUTTON:
case EC_MKBP_EVENT_SWITCH:
if (queued_during_suspend)
return NOTIFY_OK;
if (ckdev->ec->event_data.event_type == EC_MKBP_EVENT_BUTTON) {
val = get_unaligned_le32(
&ckdev->ec->event_data.data.buttons);
ev_type = EV_KEY;
} else {
val = get_unaligned_le32(
&ckdev->ec->event_data.data.switches);
ev_type = EV_SW;
}
cros_ec_keyb_report_bs(ckdev, ev_type, val);
break;
default:
return NOTIFY_DONE;
}
return NOTIFY_OK;
}
static void cros_ec_keyb_compute_valid_keys(struct cros_ec_keyb *ckdev)
{
int row, col;
int row_shift = ckdev->row_shift;
unsigned short *keymap = ckdev->idev->keycode;
unsigned short code;
BUG_ON(ckdev->idev->keycodesize != sizeof(*keymap));
for (col = 0; col < ckdev->cols; col++) {
for (row = 0; row < ckdev->rows; row++) {
code = keymap[MATRIX_SCAN_CODE(row, col, row_shift)];
if (code && (code != KEY_BATTERY))
ckdev->valid_keys[col] |= 1 << row;
}
dev_dbg(ckdev->dev, "valid_keys[%02d] = 0x%02x\n",
col, ckdev->valid_keys[col]);
}
}
static int cros_ec_keyb_info(struct cros_ec_device *ec_dev,
enum ec_mkbp_info_type info_type,
enum ec_mkbp_event event_type,
union ec_response_get_next_data *result,
size_t result_size)
{
struct ec_params_mkbp_info *params;
struct cros_ec_command *msg;
int ret;
msg = kzalloc(sizeof(*msg) + max_t(size_t, result_size,
sizeof(*params)), GFP_KERNEL);
if (!msg)
return -ENOMEM;
msg->command = EC_CMD_MKBP_INFO;
msg->version = 1;
msg->outsize = sizeof(*params);
msg->insize = result_size;
params = (struct ec_params_mkbp_info *)msg->data;
params->info_type = info_type;
params->event_type = event_type;
ret = cros_ec_cmd_xfer(ec_dev, msg);
if (ret < 0) {
dev_warn(ec_dev->dev, "Transfer error %d/%d: %d\n",
(int)info_type, (int)event_type, ret);
} else if (msg->result == EC_RES_INVALID_VERSION) {
memset(result, 0, result_size);
ret = 0;
} else if (msg->result != EC_RES_SUCCESS) {
dev_warn(ec_dev->dev, "Error getting info %d/%d: %d\n",
(int)info_type, (int)event_type, msg->result);
ret = -EPROTO;
} else if (ret != result_size) {
dev_warn(ec_dev->dev, "Wrong size %d/%d: %d != %zu\n",
(int)info_type, (int)event_type,
ret, result_size);
ret = -EPROTO;
} else {
memcpy(result, msg->data, result_size);
ret = 0;
}
kfree(msg);
return ret;
}
static int cros_ec_keyb_query_switches(struct cros_ec_keyb *ckdev)
{
struct cros_ec_device *ec_dev = ckdev->ec;
union ec_response_get_next_data event_data = {};
int ret;
ret = cros_ec_keyb_info(ec_dev, EC_MKBP_INFO_CURRENT,
EC_MKBP_EVENT_SWITCH, &event_data,
sizeof(event_data.switches));
if (ret)
return ret;
cros_ec_keyb_report_bs(ckdev, EV_SW,
get_unaligned_le32(&event_data.switches));
return 0;
}
static __maybe_unused int cros_ec_keyb_resume(struct device *dev)
{
struct cros_ec_keyb *ckdev = dev_get_drvdata(dev);
if (ckdev->bs_idev)
return cros_ec_keyb_query_switches(ckdev);
return 0;
}
static int cros_ec_keyb_register_bs(struct cros_ec_keyb *ckdev)
{
struct cros_ec_device *ec_dev = ckdev->ec;
struct device *dev = ckdev->dev;
struct input_dev *idev;
union ec_response_get_next_data event_data = {};
const char *phys;
u32 buttons;
u32 switches;
int ret;
int i;
ret = cros_ec_keyb_info(ec_dev, EC_MKBP_INFO_SUPPORTED,
EC_MKBP_EVENT_BUTTON, &event_data,
sizeof(event_data.buttons));
if (ret)
return ret;
buttons = get_unaligned_le32(&event_data.buttons);
ret = cros_ec_keyb_info(ec_dev, EC_MKBP_INFO_SUPPORTED,
EC_MKBP_EVENT_SWITCH, &event_data,
sizeof(event_data.switches));
if (ret)
return ret;
switches = get_unaligned_le32(&event_data.switches);
if (!buttons && !switches)
return 0;
phys = devm_kasprintf(dev, GFP_KERNEL, "%s/input1", ec_dev->phys_name);
if (!phys)
return -ENOMEM;
idev = devm_input_allocate_device(dev);
if (!idev)
return -ENOMEM;
idev->name = "cros_ec_buttons";
idev->phys = phys;
__set_bit(EV_REP, idev->evbit);
idev->id.bustype = BUS_VIRTUAL;
idev->id.version = 1;
idev->id.product = 0;
idev->dev.parent = dev;
input_set_drvdata(idev, ckdev);
ckdev->bs_idev = idev;
for (i = 0; i < ARRAY_SIZE(cros_ec_keyb_bs); i++) {
const struct cros_ec_bs_map *map = &cros_ec_keyb_bs[i];
if (buttons & BIT(map->bit))
input_set_capability(idev, map->ev_type, map->code);
}
ret = cros_ec_keyb_query_switches(ckdev);
if (ret) {
dev_err(dev, "cannot query switches\n");
return ret;
}
ret = input_register_device(ckdev->bs_idev);
if (ret) {
dev_err(dev, "cannot register input device\n");
return ret;
}
return 0;
}
static int cros_ec_keyb_register_matrix(struct cros_ec_keyb *ckdev)
{
struct cros_ec_device *ec_dev = ckdev->ec;
struct device *dev = ckdev->dev;
struct input_dev *idev;
const char *phys;
int err;
err = matrix_keypad_parse_properties(dev, &ckdev->rows, &ckdev->cols);
if (err)
return err;
ckdev->valid_keys = devm_kzalloc(dev, ckdev->cols, GFP_KERNEL);
if (!ckdev->valid_keys)
return -ENOMEM;
ckdev->old_kb_state = devm_kzalloc(dev, ckdev->cols, GFP_KERNEL);
if (!ckdev->old_kb_state)
return -ENOMEM;
phys = devm_kasprintf(dev, GFP_KERNEL, "%s/input0", ec_dev->phys_name);
if (!phys)
return -ENOMEM;
idev = devm_input_allocate_device(dev);
if (!idev)
return -ENOMEM;
idev->name = CROS_EC_DEV_NAME;
idev->phys = phys;
__set_bit(EV_REP, idev->evbit);
idev->id.bustype = BUS_VIRTUAL;
idev->id.version = 1;
idev->id.product = 0;
idev->dev.parent = dev;
ckdev->ghost_filter = of_property_read_bool(dev->of_node,
"google,needs-ghost-filter");
err = matrix_keypad_build_keymap(NULL, NULL, ckdev->rows, ckdev->cols,
NULL, idev);
if (err) {
dev_err(dev, "cannot build key matrix\n");
return err;
}
ckdev->row_shift = get_count_order(ckdev->cols);
input_set_capability(idev, EV_MSC, MSC_SCAN);
input_set_drvdata(idev, ckdev);
ckdev->idev = idev;
cros_ec_keyb_compute_valid_keys(ckdev);
err = input_register_device(ckdev->idev);
if (err) {
dev_err(dev, "cannot register input device\n");
return err;
}
return 0;
}
static int cros_ec_keyb_probe(struct platform_device *pdev)
{
struct cros_ec_device *ec = dev_get_drvdata(pdev->dev.parent);
struct device *dev = &pdev->dev;
struct cros_ec_keyb *ckdev;
int err;
if (!dev->of_node)
return -ENODEV;
ckdev = devm_kzalloc(dev, sizeof(*ckdev), GFP_KERNEL);
if (!ckdev)
return -ENOMEM;
ckdev->ec = ec;
ckdev->dev = dev;
dev_set_drvdata(dev, ckdev);
err = cros_ec_keyb_register_matrix(ckdev);
if (err) {
dev_err(dev, "cannot register matrix inputs: %d\n", err);
return err;
}
err = cros_ec_keyb_register_bs(ckdev);
if (err) {
dev_err(dev, "cannot register non-matrix inputs: %d\n", err);
return err;
}
ckdev->notifier.notifier_call = cros_ec_keyb_work;
err = blocking_notifier_chain_register(&ckdev->ec->event_notifier,
&ckdev->notifier);
if (err) {
dev_err(dev, "cannot register notifier: %d\n", err);
return err;
}
return 0;
}
static int cros_ec_keyb_remove(struct platform_device *pdev)
{
struct cros_ec_keyb *ckdev = dev_get_drvdata(&pdev->dev);
blocking_notifier_chain_unregister(&ckdev->ec->event_notifier,
&ckdev->notifier);
return 0;
}
