static int twl4030_kpread(struct twl4030_keypad *kp,
u8 *data, u32 reg, u8 num_bytes)
{
int ret = twl_i2c_read(TWL4030_MODULE_KEYPAD, data, reg, num_bytes);
if (ret < 0)
dev_warn(kp->dbg_dev,
"Couldn't read TWL4030: %X - ret %d[%x]\n",
reg, ret, ret);
return ret;
}
static int twl4030_kpwrite_u8(struct twl4030_keypad *kp, u8 data, u32 reg)
{
int ret = twl_i2c_write_u8(TWL4030_MODULE_KEYPAD, data, reg);
if (ret < 0)
dev_warn(kp->dbg_dev,
"Could not write TWL4030: %X - ret %d[%x]\n",
reg, ret, ret);
return ret;
}
static inline u16 twl4030_col_xlate(struct twl4030_keypad *kp, u8 col)
{
if (col == 0xFF)
return 1 << kp->n_cols;
else
return col & ((1 << kp->n_cols) - 1);
}
static int twl4030_read_kp_matrix_state(struct twl4030_keypad *kp, u16 *state)
{
u8 new_state[TWL4030_MAX_ROWS];
int row;
int ret = twl4030_kpread(kp, new_state,
KEYP_FULL_CODE_7_0, kp->n_rows);
if (ret >= 0)
for (row = 0; row < kp->n_rows; row++)
state[row] = twl4030_col_xlate(kp, new_state[row]);
return ret;
}
static bool twl4030_is_in_ghost_state(struct twl4030_keypad *kp, u16 *key_state)
{
int i;
u16 check = 0;
for (i = 0; i < kp->n_rows; i++) {
u16 col = key_state[i];
if ((col & check) && hweight16(col) > 1)
return true;
check |= col;
}
return false;
}
static void twl4030_kp_scan(struct twl4030_keypad *kp, bool release_all)
{
struct input_dev *input = kp->input;
u16 new_state[TWL4030_MAX_ROWS];
int col, row;
if (release_all) {
memset(new_state, 0, sizeof(new_state));
} else {
int ret = twl4030_read_kp_matrix_state(kp, new_state);
if (ret < 0)
return;
if (twl4030_is_in_ghost_state(kp, new_state))
return;
}
for (row = 0; row < kp->n_rows; row++) {
int changed = new_state[row] ^ kp->kp_state[row];
if (!changed)
continue;
for (col = 0; col < kp->n_cols + 1; col++) {
int code;
if (!(changed & (1 << col)))
continue;
dev_dbg(kp->dbg_dev, "key [%d:%d] %s\n", row, col,
(new_state[row] & (1 << col)) ?
"press" : "release");
code = MATRIX_SCAN_CODE(row, col, TWL4030_ROW_SHIFT);
input_event(input, EV_MSC, MSC_SCAN, code);
input_report_key(input, kp->keymap[code],
new_state[row] & (1 << col));
}
kp->kp_state[row] = new_state[row];
}
input_sync(input);
}
static irqreturn_t do_kp_irq(int irq, void *_kp)
{
struct twl4030_keypad *kp = _kp;
u8 reg;
int ret;
ret = twl4030_kpread(kp, &reg, KEYP_ISR1, 1);
if (ret >= 0 && (reg & KEYP_IMR1_KP))
twl4030_kp_scan(kp, false);
else
twl4030_kp_scan(kp, true);
return IRQ_HANDLED;
}
static int twl4030_kp_program(struct twl4030_keypad *kp)
{
u8 reg;
int i;
reg = KEYP_CTRL_SOFT_NRST | KEYP_CTRL_SOFTMODEN
| KEYP_CTRL_TOE_EN | KEYP_CTRL_KBD_ON;
if (twl4030_kpwrite_u8(kp, reg, KEYP_CTRL) < 0)
return -EIO;
reg = KEYP_EDR_KP_BOTH | KEYP_EDR_TO_RISING;
if (twl4030_kpwrite_u8(kp, reg, KEYP_EDR) < 0)
return -EIO;
reg = (PTV_PRESCALER << KEYP_LK_PTV_PTV_SHIFT);
if (twl4030_kpwrite_u8(kp, reg, KEYP_LK_PTV) < 0)
return -EIO;
i = KEYP_PERIOD_US(20000, PTV_PRESCALER);
if (twl4030_kpwrite_u8(kp, i, KEYP_DEB) < 0)
return -EIO;
i = KEYP_PERIOD_US(200000, PTV_PRESCALER);
if (twl4030_kpwrite_u8(kp, (i & 0xFF), KEYP_TIMEOUT_L) < 0)
return -EIO;
if (twl4030_kpwrite_u8(kp, (i >> 8), KEYP_TIMEOUT_H) < 0)
return -EIO;
reg = TWL4030_SIH_CTRL_COR_MASK | TWL4030_SIH_CTRL_PENDDIS_MASK;
if (twl4030_kpwrite_u8(kp, reg, KEYP_SIH_CTRL) < 0)
return -EIO;
if (twl4030_read_kp_matrix_state(kp, kp->kp_state) < 0)
return -EIO;
return 0;
}
static int twl4030_kp_probe(struct platform_device *pdev)
{
struct twl4030_keypad_data *pdata = dev_get_platdata(&pdev->dev);
const struct matrix_keymap_data *keymap_data = NULL;
struct twl4030_keypad *kp;
struct input_dev *input;
u8 reg;
int error;
kp = devm_kzalloc(&pdev->dev, sizeof(*kp), GFP_KERNEL);
if (!kp)
return -ENOMEM;
input = devm_input_allocate_device(&pdev->dev);
if (!input)
return -ENOMEM;
kp->dbg_dev = &pdev->dev;
kp->input = input;
input->name = "TWL4030 Keypad";
input->phys = "twl4030_keypad/input0";
input->id.bustype = BUS_HOST;
input->id.vendor = 0x0001;
input->id.product = 0x0001;
input->id.version = 0x0003;
if (pdata) {
if (!pdata->rows || !pdata->cols || !pdata->keymap_data) {
dev_err(&pdev->dev, "Missing platform_data\n");
return -EINVAL;
}
kp->n_rows = pdata->rows;
kp->n_cols = pdata->cols;
kp->autorepeat = pdata->rep;
keymap_data = pdata->keymap_data;
} else {
error = matrix_keypad_parse_properties(&pdev->dev, &kp->n_rows,
&kp->n_cols);
if (error)
return error;
kp->autorepeat = true;
}
if (kp->n_rows > TWL4030_MAX_ROWS || kp->n_cols > TWL4030_MAX_COLS) {
dev_err(&pdev->dev,
"Invalid rows/cols amount specified in platform/devicetree data\n");
return -EINVAL;
}
kp->irq = platform_get_irq(pdev, 0);
if (!kp->irq) {
dev_err(&pdev->dev, "no keyboard irq assigned\n");
return -EINVAL;
}
error = matrix_keypad_build_keymap(keymap_data, NULL,
TWL4030_MAX_ROWS,
1 << TWL4030_ROW_SHIFT,
kp->keymap, input);
if (error) {
dev_err(kp->dbg_dev, "Failed to build keymap\n");
return error;
}
input_set_capability(input, EV_MSC, MSC_SCAN);
if (kp->autorepeat)
__set_bit(EV_REP, input->evbit);
error = input_register_device(input);
if (error) {
dev_err(kp->dbg_dev,
"Unable to register twl4030 keypad device\n");
return error;
}
error = twl4030_kp_program(kp);
if (error)
return error;
error = devm_request_threaded_irq(&pdev->dev, kp->irq, NULL, do_kp_irq,
0, pdev->name, kp);
if (error) {
dev_info(kp->dbg_dev, "request_irq failed for irq no=%d: %d\n",
kp->irq, error);
return error;
}
reg = (u8) ~(KEYP_IMR1_KP | KEYP_IMR1_TO);
if (twl4030_kpwrite_u8(kp, reg, KEYP_IMR1)) {
(void) twl4030_kpwrite_u8(kp, 0xff, KEYP_IMR1);
return -EIO;
}
return 0;
}
