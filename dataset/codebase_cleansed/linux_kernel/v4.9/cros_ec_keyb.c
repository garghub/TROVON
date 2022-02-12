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
static int cros_ec_keyb_open(struct input_dev *dev)
{
struct cros_ec_keyb *ckdev = input_get_drvdata(dev);
return blocking_notifier_chain_register(&ckdev->ec->event_notifier,
&ckdev->notifier);
}
static void cros_ec_keyb_close(struct input_dev *dev)
{
struct cros_ec_keyb *ckdev = input_get_drvdata(dev);
blocking_notifier_chain_unregister(&ckdev->ec->event_notifier,
&ckdev->notifier);
}
static int cros_ec_keyb_work(struct notifier_block *nb,
unsigned long queued_during_suspend, void *_notify)
{
struct cros_ec_keyb *ckdev = container_of(nb, struct cros_ec_keyb,
notifier);
if (ckdev->ec->event_data.event_type != EC_MKBP_EVENT_KEY_MATRIX)
return NOTIFY_DONE;
if (queued_during_suspend)
return NOTIFY_OK;
if (ckdev->ec->event_size != ckdev->cols) {
dev_err(ckdev->dev,
"Discarded incomplete key matrix event.\n");
return NOTIFY_OK;
}
cros_ec_keyb_process(ckdev, ckdev->ec->event_data.data.key_matrix,
ckdev->ec->event_size);
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
static int cros_ec_keyb_probe(struct platform_device *pdev)
{
struct cros_ec_device *ec = dev_get_drvdata(pdev->dev.parent);
struct device *dev = &pdev->dev;
struct cros_ec_keyb *ckdev;
struct input_dev *idev;
struct device_node *np;
int err;
np = pdev->dev.of_node;
if (!np)
return -ENODEV;
ckdev = devm_kzalloc(dev, sizeof(*ckdev), GFP_KERNEL);
if (!ckdev)
return -ENOMEM;
err = matrix_keypad_parse_of_params(dev, &ckdev->rows, &ckdev->cols);
if (err)
return err;
ckdev->valid_keys = devm_kzalloc(dev, ckdev->cols, GFP_KERNEL);
if (!ckdev->valid_keys)
return -ENOMEM;
ckdev->old_kb_state = devm_kzalloc(dev, ckdev->cols, GFP_KERNEL);
if (!ckdev->old_kb_state)
return -ENOMEM;
idev = devm_input_allocate_device(dev);
if (!idev)
return -ENOMEM;
ckdev->ec = ec;
ckdev->notifier.notifier_call = cros_ec_keyb_work;
ckdev->dev = dev;
dev_set_drvdata(dev, ckdev);
idev->name = CROS_EC_DEV_NAME;
idev->phys = ec->phys_name;
__set_bit(EV_REP, idev->evbit);
idev->id.bustype = BUS_VIRTUAL;
idev->id.version = 1;
idev->id.product = 0;
idev->dev.parent = dev;
idev->open = cros_ec_keyb_open;
idev->close = cros_ec_keyb_close;
ckdev->ghost_filter = of_property_read_bool(np,
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
