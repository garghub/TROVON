static bool cros_ec_keyb_row_has_ghosting(struct cros_ec_keyb *ckdev,
uint8_t *buf, int row)
{
int pressed_in_row = 0;
int row_has_teeth = 0;
int col, mask;
mask = 1 << row;
for (col = 0; col < ckdev->cols; col++) {
if (buf[col] & mask) {
pressed_in_row++;
row_has_teeth |= buf[col] & ~mask;
if (pressed_in_row > 1 && row_has_teeth) {
dev_dbg(ckdev->dev,
"ghost found at: r%d c%d, pressed %d, teeth 0x%x\n",
row, col, pressed_in_row,
row_has_teeth);
return true;
}
}
}
return false;
}
static bool cros_ec_keyb_has_ghosting(struct cros_ec_keyb *ckdev, uint8_t *buf)
{
int row;
for (row = 0; row < ckdev->rows; row++)
if (cros_ec_keyb_row_has_ghosting(ckdev, buf, row))
return true;
return false;
}
static void cros_ec_keyb_process(struct cros_ec_keyb *ckdev,
uint8_t *kb_state, int len)
{
struct input_dev *idev = ckdev->idev;
int col, row;
int new_state;
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
int code;
code = keycodes[pos];
new_state = kb_state[col] & (1 << row);
if (!!new_state != test_bit(code, idev->key)) {
dev_dbg(ckdev->dev,
"changed: [r%d c%d]: byte %02x\n",
row, col, new_state);
input_report_key(idev, code, new_state);
}
}
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
static int cros_ec_keyb_get_state(struct cros_ec_keyb *ckdev, uint8_t *kb_state)
{
return ckdev->ec->command_recv(ckdev->ec, EC_CMD_MKBP_STATE,
kb_state, ckdev->cols);
}
static int cros_ec_keyb_work(struct notifier_block *nb,
unsigned long state, void *_notify)
{
int ret;
struct cros_ec_keyb *ckdev = container_of(nb, struct cros_ec_keyb,
notifier);
uint8_t kb_state[ckdev->cols];
ret = cros_ec_keyb_get_state(ckdev, kb_state);
if (ret >= 0)
cros_ec_keyb_process(ckdev, kb_state, ret);
return NOTIFY_DONE;
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
idev = devm_input_allocate_device(&pdev->dev);
if (!idev)
return -ENOMEM;
ckdev->ec = ec;
ckdev->notifier.notifier_call = cros_ec_keyb_work;
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
