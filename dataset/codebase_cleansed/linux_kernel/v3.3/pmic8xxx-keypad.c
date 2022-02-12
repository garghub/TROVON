static int pmic8xxx_kp_write_u8(struct pmic8xxx_kp *kp,
u8 data, u16 reg)
{
int rc;
rc = pm8xxx_writeb(kp->dev->parent, reg, data);
return rc;
}
static int pmic8xxx_kp_read(struct pmic8xxx_kp *kp,
u8 *data, u16 reg, unsigned num_bytes)
{
int rc;
rc = pm8xxx_read_buf(kp->dev->parent, reg, data, num_bytes);
return rc;
}
static int pmic8xxx_kp_read_u8(struct pmic8xxx_kp *kp,
u8 *data, u16 reg)
{
int rc;
rc = pmic8xxx_kp_read(kp, data, reg, 1);
return rc;
}
static u8 pmic8xxx_col_state(struct pmic8xxx_kp *kp, u8 col)
{
if (col == 0x00)
return 1 << kp->pdata->num_cols;
else
return col & ((1 << kp->pdata->num_cols) - 1);
}
static int pmic8xxx_chk_sync_read(struct pmic8xxx_kp *kp)
{
int rc;
u8 scan_val;
rc = pmic8xxx_kp_read_u8(kp, &scan_val, KEYP_SCAN);
if (rc < 0) {
dev_err(kp->dev, "Error reading KEYP_SCAN reg, rc=%d\n", rc);
return rc;
}
scan_val |= 0x1;
rc = pmic8xxx_kp_write_u8(kp, scan_val, KEYP_SCAN);
if (rc < 0) {
dev_err(kp->dev, "Error writing KEYP_SCAN reg, rc=%d\n", rc);
return rc;
}
udelay((2 * DIV_ROUND_UP(USEC_PER_SEC, KEYP_CLOCK_FREQ)) + 1);
return rc;
}
static int pmic8xxx_kp_read_data(struct pmic8xxx_kp *kp, u16 *state,
u16 data_reg, int read_rows)
{
int rc, row;
u8 new_data[PM8XXX_MAX_ROWS];
rc = pmic8xxx_kp_read(kp, new_data, data_reg, read_rows);
if (rc)
return rc;
for (row = 0; row < kp->pdata->num_rows; row++) {
dev_dbg(kp->dev, "new_data[%d] = %d\n", row,
new_data[row]);
state[row] = pmic8xxx_col_state(kp, new_data[row]);
}
return rc;
}
static int pmic8xxx_kp_read_matrix(struct pmic8xxx_kp *kp, u16 *new_state,
u16 *old_state)
{
int rc, read_rows;
u8 scan_val;
if (kp->pdata->num_rows < PM8XXX_MIN_ROWS)
read_rows = PM8XXX_MIN_ROWS;
else
read_rows = kp->pdata->num_rows;
pmic8xxx_chk_sync_read(kp);
if (old_state) {
rc = pmic8xxx_kp_read_data(kp, old_state, KEYP_OLD_DATA,
read_rows);
if (rc < 0) {
dev_err(kp->dev,
"Error reading KEYP_OLD_DATA, rc=%d\n", rc);
return rc;
}
}
rc = pmic8xxx_kp_read_data(kp, new_state, KEYP_RECENT_DATA,
read_rows);
if (rc < 0) {
dev_err(kp->dev,
"Error reading KEYP_RECENT_DATA, rc=%d\n", rc);
return rc;
}
udelay((4 * DIV_ROUND_UP(USEC_PER_SEC, KEYP_CLOCK_FREQ)) + 1);
rc = pmic8xxx_kp_read_u8(kp, &scan_val, KEYP_SCAN);
if (rc < 0) {
dev_err(kp->dev, "Error reading KEYP_SCAN reg, rc=%d\n", rc);
return rc;
}
scan_val &= 0xFE;
rc = pmic8xxx_kp_write_u8(kp, scan_val, KEYP_SCAN);
if (rc < 0)
dev_err(kp->dev, "Error writing KEYP_SCAN reg, rc=%d\n", rc);
return rc;
}
static void __pmic8xxx_kp_scan_matrix(struct pmic8xxx_kp *kp, u16 *new_state,
u16 *old_state)
{
int row, col, code;
for (row = 0; row < kp->pdata->num_rows; row++) {
int bits_changed = new_state[row] ^ old_state[row];
if (!bits_changed)
continue;
for (col = 0; col < kp->pdata->num_cols; col++) {
if (!(bits_changed & (1 << col)))
continue;
dev_dbg(kp->dev, "key [%d:%d] %s\n", row, col,
!(new_state[row] & (1 << col)) ?
"pressed" : "released");
code = MATRIX_SCAN_CODE(row, col, PM8XXX_ROW_SHIFT);
input_event(kp->input, EV_MSC, MSC_SCAN, code);
input_report_key(kp->input,
kp->keycodes[code],
!(new_state[row] & (1 << col)));
input_sync(kp->input);
}
}
}
static bool pmic8xxx_detect_ghost_keys(struct pmic8xxx_kp *kp, u16 *new_state)
{
int row, found_first = -1;
u16 check, row_state;
check = 0;
for (row = 0; row < kp->pdata->num_rows; row++) {
row_state = (~new_state[row]) &
((1 << kp->pdata->num_cols) - 1);
if (hweight16(row_state) > 1) {
if (found_first == -1)
found_first = row;
if (check & row_state) {
dev_dbg(kp->dev, "detected ghost key on row[%d]"
" and row[%d]\n", found_first, row);
return true;
}
}
check |= row_state;
}
return false;
}
static int pmic8xxx_kp_scan_matrix(struct pmic8xxx_kp *kp, unsigned int events)
{
u16 new_state[PM8XXX_MAX_ROWS];
u16 old_state[PM8XXX_MAX_ROWS];
int rc;
switch (events) {
case 0x1:
rc = pmic8xxx_kp_read_matrix(kp, new_state, NULL);
if (rc < 0)
return rc;
if (pmic8xxx_detect_ghost_keys(kp, new_state))
return 0;
__pmic8xxx_kp_scan_matrix(kp, new_state, kp->keystate);
memcpy(kp->keystate, new_state, sizeof(new_state));
break;
case 0x3:
rc = pmic8xxx_kp_read_matrix(kp, new_state, old_state);
if (rc < 0)
return rc;
__pmic8xxx_kp_scan_matrix(kp, old_state, kp->keystate);
__pmic8xxx_kp_scan_matrix(kp, new_state, old_state);
memcpy(kp->keystate, new_state, sizeof(new_state));
break;
case 0x2:
dev_dbg(kp->dev, "Some key events were lost\n");
rc = pmic8xxx_kp_read_matrix(kp, new_state, old_state);
if (rc < 0)
return rc;
__pmic8xxx_kp_scan_matrix(kp, old_state, kp->keystate);
__pmic8xxx_kp_scan_matrix(kp, new_state, old_state);
memcpy(kp->keystate, new_state, sizeof(new_state));
break;
default:
rc = -EINVAL;
}
return rc;
}
static irqreturn_t pmic8xxx_kp_stuck_irq(int irq, void *data)
{
u16 new_state[PM8XXX_MAX_ROWS];
u16 old_state[PM8XXX_MAX_ROWS];
int rc;
struct pmic8xxx_kp *kp = data;
rc = pmic8xxx_kp_read_matrix(kp, new_state, old_state);
if (rc < 0) {
dev_err(kp->dev, "failed to read keypad matrix\n");
return IRQ_HANDLED;
}
__pmic8xxx_kp_scan_matrix(kp, new_state, kp->stuckstate);
return IRQ_HANDLED;
}
static irqreturn_t pmic8xxx_kp_irq(int irq, void *data)
{
struct pmic8xxx_kp *kp = data;
u8 ctrl_val, events;
int rc;
rc = pmic8xxx_kp_read(kp, &ctrl_val, KEYP_CTRL, 1);
if (rc < 0) {
dev_err(kp->dev, "failed to read keyp_ctrl register\n");
return IRQ_HANDLED;
}
events = ctrl_val & KEYP_CTRL_EVNTS_MASK;
rc = pmic8xxx_kp_scan_matrix(kp, events);
if (rc < 0)
dev_err(kp->dev, "failed to scan matrix\n");
return IRQ_HANDLED;
}
static int __devinit pmic8xxx_kpd_init(struct pmic8xxx_kp *kp)
{
int bits, rc, cycles;
u8 scan_val = 0, ctrl_val = 0;
static const u8 row_bits[] = {
0, 1, 2, 3, 4, 4, 5, 5, 6, 6, 6, 7, 7, 7,
};
if (kp->pdata->num_cols < KEYP_CTRL_SCAN_COLS_MIN)
bits = 0;
else
bits = kp->pdata->num_cols - KEYP_CTRL_SCAN_COLS_MIN;
ctrl_val = (bits & KEYP_CTRL_SCAN_COLS_BITS) <<
KEYP_CTRL_SCAN_COLS_SHIFT;
if (kp->pdata->num_rows < KEYP_CTRL_SCAN_ROWS_MIN)
bits = 0;
else
bits = row_bits[kp->pdata->num_rows - KEYP_CTRL_SCAN_ROWS_MIN];
ctrl_val |= (bits << KEYP_CTRL_SCAN_ROWS_SHIFT);
rc = pmic8xxx_kp_write_u8(kp, ctrl_val, KEYP_CTRL);
if (rc < 0) {
dev_err(kp->dev, "Error writing KEYP_CTRL reg, rc=%d\n", rc);
return rc;
}
bits = (kp->pdata->debounce_ms / 5) - 1;
scan_val |= (bits << KEYP_SCAN_DBOUNCE_SHIFT);
bits = fls(kp->pdata->scan_delay_ms) - 1;
scan_val |= (bits << KEYP_SCAN_PAUSE_SHIFT);
cycles = (kp->pdata->row_hold_ns * KEYP_CLOCK_FREQ) / NSEC_PER_SEC;
scan_val |= (cycles << KEYP_SCAN_ROW_HOLD_SHIFT);
rc = pmic8xxx_kp_write_u8(kp, scan_val, KEYP_SCAN);
if (rc)
dev_err(kp->dev, "Error writing KEYP_SCAN reg, rc=%d\n", rc);
return rc;
}
static int __devinit pmic8xxx_kp_config_gpio(int gpio_start, int num_gpios,
struct pmic8xxx_kp *kp, struct pm_gpio *gpio_config)
{
int rc, i;
if (gpio_start < 0 || num_gpios < 0)
return -EINVAL;
for (i = 0; i < num_gpios; i++) {
rc = pm8xxx_gpio_config(gpio_start + i, gpio_config);
if (rc) {
dev_err(kp->dev, "%s: FAIL pm8xxx_gpio_config():"
"for PM GPIO [%d] rc=%d.\n",
__func__, gpio_start + i, rc);
return rc;
}
}
return 0;
}
static int pmic8xxx_kp_enable(struct pmic8xxx_kp *kp)
{
int rc;
kp->ctrl_reg |= KEYP_CTRL_KEYP_EN;
rc = pmic8xxx_kp_write_u8(kp, kp->ctrl_reg, KEYP_CTRL);
if (rc < 0)
dev_err(kp->dev, "Error writing KEYP_CTRL reg, rc=%d\n", rc);
return rc;
}
static int pmic8xxx_kp_disable(struct pmic8xxx_kp *kp)
{
int rc;
kp->ctrl_reg &= ~KEYP_CTRL_KEYP_EN;
rc = pmic8xxx_kp_write_u8(kp, kp->ctrl_reg, KEYP_CTRL);
if (rc < 0)
return rc;
return rc;
}
static int pmic8xxx_kp_open(struct input_dev *dev)
{
struct pmic8xxx_kp *kp = input_get_drvdata(dev);
return pmic8xxx_kp_enable(kp);
}
static void pmic8xxx_kp_close(struct input_dev *dev)
{
struct pmic8xxx_kp *kp = input_get_drvdata(dev);
pmic8xxx_kp_disable(kp);
}
static int __devinit pmic8xxx_kp_probe(struct platform_device *pdev)
{
const struct pm8xxx_keypad_platform_data *pdata =
dev_get_platdata(&pdev->dev);
const struct matrix_keymap_data *keymap_data;
struct pmic8xxx_kp *kp;
int rc;
u8 ctrl_val;
struct pm_gpio kypd_drv = {
.direction = PM_GPIO_DIR_OUT,
.output_buffer = PM_GPIO_OUT_BUF_OPEN_DRAIN,
.output_value = 0,
.pull = PM_GPIO_PULL_NO,
.vin_sel = PM_GPIO_VIN_S3,
.out_strength = PM_GPIO_STRENGTH_LOW,
.function = PM_GPIO_FUNC_1,
.inv_int_pol = 1,
};
struct pm_gpio kypd_sns = {
.direction = PM_GPIO_DIR_IN,
.pull = PM_GPIO_PULL_UP_31P5,
.vin_sel = PM_GPIO_VIN_S3,
.out_strength = PM_GPIO_STRENGTH_NO,
.function = PM_GPIO_FUNC_NORMAL,
.inv_int_pol = 1,
};
if (!pdata || !pdata->num_cols || !pdata->num_rows ||
pdata->num_cols > PM8XXX_MAX_COLS ||
pdata->num_rows > PM8XXX_MAX_ROWS ||
pdata->num_cols < PM8XXX_MIN_COLS) {
dev_err(&pdev->dev, "invalid platform data\n");
return -EINVAL;
}
if (!pdata->scan_delay_ms ||
pdata->scan_delay_ms > MAX_SCAN_DELAY ||
pdata->scan_delay_ms < MIN_SCAN_DELAY ||
!is_power_of_2(pdata->scan_delay_ms)) {
dev_err(&pdev->dev, "invalid keypad scan time supplied\n");
return -EINVAL;
}
if (!pdata->row_hold_ns ||
pdata->row_hold_ns > MAX_ROW_HOLD_DELAY ||
pdata->row_hold_ns < MIN_ROW_HOLD_DELAY ||
((pdata->row_hold_ns % MIN_ROW_HOLD_DELAY) != 0)) {
dev_err(&pdev->dev, "invalid keypad row hold time supplied\n");
return -EINVAL;
}
if (!pdata->debounce_ms ||
((pdata->debounce_ms % 5) != 0) ||
pdata->debounce_ms > MAX_DEBOUNCE_TIME ||
pdata->debounce_ms < MIN_DEBOUNCE_TIME) {
dev_err(&pdev->dev, "invalid debounce time supplied\n");
return -EINVAL;
}
keymap_data = pdata->keymap_data;
if (!keymap_data) {
dev_err(&pdev->dev, "no keymap data supplied\n");
return -EINVAL;
}
kp = kzalloc(sizeof(*kp), GFP_KERNEL);
if (!kp)
return -ENOMEM;
platform_set_drvdata(pdev, kp);
kp->pdata = pdata;
kp->dev = &pdev->dev;
kp->input = input_allocate_device();
if (!kp->input) {
dev_err(&pdev->dev, "unable to allocate input device\n");
rc = -ENOMEM;
goto err_alloc_device;
}
kp->key_sense_irq = platform_get_irq(pdev, 0);
if (kp->key_sense_irq < 0) {
dev_err(&pdev->dev, "unable to get keypad sense irq\n");
rc = -ENXIO;
goto err_get_irq;
}
kp->key_stuck_irq = platform_get_irq(pdev, 1);
if (kp->key_stuck_irq < 0) {
dev_err(&pdev->dev, "unable to get keypad stuck irq\n");
rc = -ENXIO;
goto err_get_irq;
}
kp->input->name = pdata->input_name ? : "PMIC8XXX keypad";
kp->input->phys = pdata->input_phys_device ? : "pmic8xxx_keypad/input0";
kp->input->dev.parent = &pdev->dev;
kp->input->id.bustype = BUS_I2C;
kp->input->id.version = 0x0001;
kp->input->id.product = 0x0001;
kp->input->id.vendor = 0x0001;
kp->input->evbit[0] = BIT_MASK(EV_KEY);
if (pdata->rep)
__set_bit(EV_REP, kp->input->evbit);
kp->input->keycode = kp->keycodes;
kp->input->keycodemax = PM8XXX_MATRIX_MAX_SIZE;
kp->input->keycodesize = sizeof(kp->keycodes);
kp->input->open = pmic8xxx_kp_open;
kp->input->close = pmic8xxx_kp_close;
matrix_keypad_build_keymap(keymap_data, PM8XXX_ROW_SHIFT,
kp->input->keycode, kp->input->keybit);
input_set_capability(kp->input, EV_MSC, MSC_SCAN);
input_set_drvdata(kp->input, kp);
memset(kp->keystate, 0xff, sizeof(kp->keystate));
memset(kp->stuckstate, 0xff, sizeof(kp->stuckstate));
rc = pmic8xxx_kpd_init(kp);
if (rc < 0) {
dev_err(&pdev->dev, "unable to initialize keypad controller\n");
goto err_get_irq;
}
rc = pmic8xxx_kp_config_gpio(pdata->cols_gpio_start,
pdata->num_cols, kp, &kypd_sns);
if (rc < 0) {
dev_err(&pdev->dev, "unable to configure keypad sense lines\n");
goto err_gpio_config;
}
rc = pmic8xxx_kp_config_gpio(pdata->rows_gpio_start,
pdata->num_rows, kp, &kypd_drv);
if (rc < 0) {
dev_err(&pdev->dev, "unable to configure keypad drive lines\n");
goto err_gpio_config;
}
rc = request_any_context_irq(kp->key_sense_irq, pmic8xxx_kp_irq,
IRQF_TRIGGER_RISING, "pmic-keypad", kp);
if (rc < 0) {
dev_err(&pdev->dev, "failed to request keypad sense irq\n");
goto err_get_irq;
}
rc = request_any_context_irq(kp->key_stuck_irq, pmic8xxx_kp_stuck_irq,
IRQF_TRIGGER_RISING, "pmic-keypad-stuck", kp);
if (rc < 0) {
dev_err(&pdev->dev, "failed to request keypad stuck irq\n");
goto err_req_stuck_irq;
}
rc = pmic8xxx_kp_read_u8(kp, &ctrl_val, KEYP_CTRL);
if (rc < 0) {
dev_err(&pdev->dev, "failed to read KEYP_CTRL register\n");
goto err_pmic_reg_read;
}
kp->ctrl_reg = ctrl_val;
rc = input_register_device(kp->input);
if (rc < 0) {
dev_err(&pdev->dev, "unable to register keypad input device\n");
goto err_pmic_reg_read;
}
device_init_wakeup(&pdev->dev, pdata->wakeup);
return 0;
err_pmic_reg_read:
free_irq(kp->key_stuck_irq, kp);
err_req_stuck_irq:
free_irq(kp->key_sense_irq, kp);
err_gpio_config:
err_get_irq:
input_free_device(kp->input);
err_alloc_device:
platform_set_drvdata(pdev, NULL);
kfree(kp);
return rc;
}
static int __devexit pmic8xxx_kp_remove(struct platform_device *pdev)
{
struct pmic8xxx_kp *kp = platform_get_drvdata(pdev);
device_init_wakeup(&pdev->dev, 0);
free_irq(kp->key_stuck_irq, kp);
free_irq(kp->key_sense_irq, kp);
input_unregister_device(kp->input);
kfree(kp);
platform_set_drvdata(pdev, NULL);
return 0;
}
static int pmic8xxx_kp_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct pmic8xxx_kp *kp = platform_get_drvdata(pdev);
struct input_dev *input_dev = kp->input;
if (device_may_wakeup(dev)) {
enable_irq_wake(kp->key_sense_irq);
} else {
mutex_lock(&input_dev->mutex);
if (input_dev->users)
pmic8xxx_kp_disable(kp);
mutex_unlock(&input_dev->mutex);
}
return 0;
}
static int pmic8xxx_kp_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct pmic8xxx_kp *kp = platform_get_drvdata(pdev);
struct input_dev *input_dev = kp->input;
if (device_may_wakeup(dev)) {
disable_irq_wake(kp->key_sense_irq);
} else {
mutex_lock(&input_dev->mutex);
if (input_dev->users)
pmic8xxx_kp_enable(kp);
mutex_unlock(&input_dev->mutex);
}
return 0;
}
