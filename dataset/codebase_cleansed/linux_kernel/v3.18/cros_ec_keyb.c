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
static int cros_ec_keyb_get_state(struct cros_ec_keyb *ckdev, uint8_t *kb_state)
{
struct cros_ec_command msg = {
.version = 0,
.command = EC_CMD_MKBP_STATE,
.outdata = NULL,
.outsize = 0,
.indata = kb_state,
.insize = ckdev->cols,
};
return cros_ec_cmd_xfer(ckdev->ec, &msg);
}
static irqreturn_t cros_ec_keyb_irq(int irq, void *data)
{
struct cros_ec_keyb *ckdev = data;
struct cros_ec_device *ec = ckdev->ec;
int ret;
uint8_t kb_state[ckdev->cols];
if (device_may_wakeup(ec->dev))
pm_wakeup_event(ec->dev, 0);
ret = cros_ec_keyb_get_state(ckdev, kb_state);
if (ret >= 0)
cros_ec_keyb_process(ckdev, kb_state, ret);
else
dev_err(ec->dev, "failed to get keyboard state: %d\n", ret);
return IRQ_HANDLED;
}
static int cros_ec_keyb_open(struct input_dev *dev)
{
struct cros_ec_keyb *ckdev = input_get_drvdata(dev);
struct cros_ec_device *ec = ckdev->ec;
return request_threaded_irq(ec->irq, NULL, cros_ec_keyb_irq,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
"cros_ec_keyb", ckdev);
}
static void cros_ec_keyb_close(struct input_dev *dev)
{
struct cros_ec_keyb *ckdev = input_get_drvdata(dev);
struct cros_ec_device *ec = ckdev->ec;
free_irq(ec->irq, ckdev);
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
struct device *dev = ec->dev;
struct cros_ec_keyb *ckdev;
struct input_dev *idev;
struct device_node *np;
int err;
np = pdev->dev.of_node;
if (!np)
return -ENODEV;
ckdev = devm_kzalloc(&pdev->dev, sizeof(*ckdev), GFP_KERNEL);
if (!ckdev)
return -ENOMEM;
err = matrix_keypad_parse_of_params(&pdev->dev, &ckdev->rows,
&ckdev->cols);
if (err)
return err;
ckdev->valid_keys = devm_kzalloc(&pdev->dev, ckdev->cols, GFP_KERNEL);
if (!ckdev->valid_keys)
return -ENOMEM;
ckdev->old_kb_state = devm_kzalloc(&pdev->dev, ckdev->cols, GFP_KERNEL);
if (!ckdev->old_kb_state)
return -ENOMEM;
idev = devm_input_allocate_device(&pdev->dev);
if (!idev)
return -ENOMEM;
if (!ec->irq) {
dev_err(dev, "no EC IRQ specified\n");
return -EINVAL;
}
ckdev->ec = ec;
ckdev->dev = dev;
dev_set_drvdata(&pdev->dev, ckdev);
idev->name = ec->ec_name;
idev->phys = ec->phys_name;
__set_bit(EV_REP, idev->evbit);
idev->id.bustype = BUS_VIRTUAL;
idev->id.version = 1;
idev->id.product = 0;
idev->dev.parent = &pdev->dev;
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
static void cros_ec_keyb_clear_keyboard(struct cros_ec_keyb *ckdev)
{
uint8_t old_state[ckdev->cols];
uint8_t new_state[ckdev->cols];
unsigned long duration;
int i, ret;
duration = jiffies;
ret = cros_ec_keyb_get_state(ckdev, new_state);
for (i = 1; !ret && i < 32; i++) {
memcpy(old_state, new_state, sizeof(old_state));
ret = cros_ec_keyb_get_state(ckdev, new_state);
if (0 == memcmp(old_state, new_state, sizeof(old_state)))
break;
}
duration = jiffies - duration;
dev_info(ckdev->dev, "Discarded %d keyscan(s) in %dus\n", i,
jiffies_to_usecs(duration));
}
static int cros_ec_keyb_resume(struct device *dev)
{
struct cros_ec_keyb *ckdev = dev_get_drvdata(dev);
if (ckdev->ec->was_wake_device)
cros_ec_keyb_clear_keyboard(ckdev);
return 0;
}
