static void tegra_kbc_report_released_keys(struct input_dev *input,
unsigned short old_keycodes[],
unsigned int old_num_keys,
unsigned short new_keycodes[],
unsigned int new_num_keys)
{
unsigned int i, j;
for (i = 0; i < old_num_keys; i++) {
for (j = 0; j < new_num_keys; j++)
if (old_keycodes[i] == new_keycodes[j])
break;
if (j == new_num_keys)
input_report_key(input, old_keycodes[i], 0);
}
}
static void tegra_kbc_report_pressed_keys(struct input_dev *input,
unsigned char scancodes[],
unsigned short keycodes[],
unsigned int num_pressed_keys)
{
unsigned int i;
for (i = 0; i < num_pressed_keys; i++) {
input_event(input, EV_MSC, MSC_SCAN, scancodes[i]);
input_report_key(input, keycodes[i], 1);
}
}
static void tegra_kbc_report_keys(struct tegra_kbc *kbc)
{
unsigned char scancodes[KBC_MAX_KPENT];
unsigned short keycodes[KBC_MAX_KPENT];
u32 val = 0;
unsigned int i;
unsigned int num_down = 0;
bool fn_keypress = false;
bool key_in_same_row = false;
bool key_in_same_col = false;
for (i = 0; i < KBC_MAX_KPENT; i++) {
if ((i % 4) == 0)
val = readl(kbc->mmio + KBC_KP_ENT0_0 + i);
if (val & 0x80) {
unsigned int col = val & 0x07;
unsigned int row = (val >> 3) & 0x0f;
unsigned char scancode =
MATRIX_SCAN_CODE(row, col, KBC_ROW_SHIFT);
scancodes[num_down] = scancode;
keycodes[num_down] = kbc->keycode[scancode];
if ((keycodes[num_down] == KEY_FN) && kbc->use_fn_map)
fn_keypress = true;
else
num_down++;
}
val >>= 8;
}
if (kbc->use_ghost_filter && num_down >= 3) {
for (i = 0; i < num_down; i++) {
unsigned int j;
u8 curr_col = scancodes[i] & 0x07;
u8 curr_row = scancodes[i] >> KBC_ROW_SHIFT;
for (j = i + 1; j < num_down; j++) {
u8 col = scancodes[j] & 0x07;
u8 row = scancodes[j] >> KBC_ROW_SHIFT;
if (col == curr_col)
key_in_same_col = true;
if (row == curr_row)
key_in_same_row = true;
}
}
}
if (fn_keypress) {
for (i = 0; i < num_down; i++) {
scancodes[i] += kbc->max_keys;
keycodes[i] = kbc->keycode[scancodes[i]];
}
}
if (key_in_same_col && key_in_same_row)
return;
tegra_kbc_report_released_keys(kbc->idev,
kbc->current_keys, kbc->num_pressed_keys,
keycodes, num_down);
tegra_kbc_report_pressed_keys(kbc->idev, scancodes, keycodes, num_down);
input_sync(kbc->idev);
memcpy(kbc->current_keys, keycodes, sizeof(kbc->current_keys));
kbc->num_pressed_keys = num_down;
}
static void tegra_kbc_set_fifo_interrupt(struct tegra_kbc *kbc, bool enable)
{
u32 val;
val = readl(kbc->mmio + KBC_CONTROL_0);
if (enable)
val |= KBC_CONTROL_FIFO_CNT_INT_EN;
else
val &= ~KBC_CONTROL_FIFO_CNT_INT_EN;
writel(val, kbc->mmio + KBC_CONTROL_0);
}
static void tegra_kbc_keypress_timer(unsigned long data)
{
struct tegra_kbc *kbc = (struct tegra_kbc *)data;
unsigned long flags;
u32 val;
unsigned int i;
spin_lock_irqsave(&kbc->lock, flags);
val = (readl(kbc->mmio + KBC_INT_0) >> 4) & 0xf;
if (val) {
unsigned long dly;
tegra_kbc_report_keys(kbc);
dly = (val == 1) ? kbc->repoll_dly : 1;
mod_timer(&kbc->timer, jiffies + msecs_to_jiffies(dly));
} else {
for (i = 0; i < kbc->num_pressed_keys; i++)
input_report_key(kbc->idev, kbc->current_keys[i], 0);
input_sync(kbc->idev);
kbc->num_pressed_keys = 0;
tegra_kbc_set_fifo_interrupt(kbc, true);
}
spin_unlock_irqrestore(&kbc->lock, flags);
}
static irqreturn_t tegra_kbc_isr(int irq, void *args)
{
struct tegra_kbc *kbc = args;
unsigned long flags;
u32 val;
spin_lock_irqsave(&kbc->lock, flags);
val = readl(kbc->mmio + KBC_INT_0);
writel(val, kbc->mmio + KBC_INT_0);
if (val & KBC_INT_FIFO_CNT_INT_STATUS) {
tegra_kbc_set_fifo_interrupt(kbc, false);
mod_timer(&kbc->timer, jiffies + kbc->cp_dly_jiffies);
} else if (val & KBC_INT_KEYPRESS_INT_STATUS) {
kbc->keypress_caused_wake = true;
}
spin_unlock_irqrestore(&kbc->lock, flags);
return IRQ_HANDLED;
}
static void tegra_kbc_setup_wakekeys(struct tegra_kbc *kbc, bool filter)
{
int i;
unsigned int rst_val;
rst_val = (filter && !kbc->wakeup) ? ~0 : 0;
for (i = 0; i < kbc->hw_support->max_rows; i++)
writel(rst_val, kbc->mmio + KBC_ROW0_MASK_0 + i * 4);
}
static void tegra_kbc_config_pins(struct tegra_kbc *kbc)
{
int i;
for (i = 0; i < KBC_MAX_GPIO; i++) {
u32 r_shft = 5 * (i % 6);
u32 c_shft = 4 * (i % 8);
u32 r_mask = 0x1f << r_shft;
u32 c_mask = 0x0f << c_shft;
u32 r_offs = (i / 6) * 4 + KBC_ROW_CFG0_0;
u32 c_offs = (i / 8) * 4 + KBC_COL_CFG0_0;
u32 row_cfg = readl(kbc->mmio + r_offs);
u32 col_cfg = readl(kbc->mmio + c_offs);
row_cfg &= ~r_mask;
col_cfg &= ~c_mask;
switch (kbc->pin_cfg[i].type) {
case PIN_CFG_ROW:
row_cfg |= ((kbc->pin_cfg[i].num << 1) | 1) << r_shft;
break;
case PIN_CFG_COL:
col_cfg |= ((kbc->pin_cfg[i].num << 1) | 1) << c_shft;
break;
case PIN_CFG_IGNORE:
break;
}
writel(row_cfg, kbc->mmio + r_offs);
writel(col_cfg, kbc->mmio + c_offs);
}
}
static int tegra_kbc_start(struct tegra_kbc *kbc)
{
unsigned int debounce_cnt;
u32 val = 0;
clk_prepare_enable(kbc->clk);
tegra_periph_reset_assert(kbc->clk);
udelay(100);
tegra_periph_reset_deassert(kbc->clk);
udelay(100);
tegra_kbc_config_pins(kbc);
tegra_kbc_setup_wakekeys(kbc, false);
writel(kbc->repeat_cnt, kbc->mmio + KBC_RPT_DLY_0);
debounce_cnt = min(kbc->debounce_cnt, KBC_MAX_DEBOUNCE_CNT);
val = KBC_DEBOUNCE_CNT_SHIFT(debounce_cnt);
val |= KBC_FIFO_TH_CNT_SHIFT(1);
val |= KBC_CONTROL_FIFO_CNT_INT_EN;
val |= KBC_CONTROL_KBC_EN;
writel(val, kbc->mmio + KBC_CONTROL_0);
val = readl(kbc->mmio + KBC_INIT_DLY_0);
kbc->cp_dly_jiffies = usecs_to_jiffies((val & 0xfffff) * 32);
kbc->num_pressed_keys = 0;
while (1) {
val = readl(kbc->mmio + KBC_INT_0);
val >>= 4;
if (!val)
break;
val = readl(kbc->mmio + KBC_KP_ENT0_0);
val = readl(kbc->mmio + KBC_KP_ENT1_0);
}
writel(0x7, kbc->mmio + KBC_INT_0);
enable_irq(kbc->irq);
return 0;
}
static void tegra_kbc_stop(struct tegra_kbc *kbc)
{
unsigned long flags;
u32 val;
spin_lock_irqsave(&kbc->lock, flags);
val = readl(kbc->mmio + KBC_CONTROL_0);
val &= ~1;
writel(val, kbc->mmio + KBC_CONTROL_0);
spin_unlock_irqrestore(&kbc->lock, flags);
disable_irq(kbc->irq);
del_timer_sync(&kbc->timer);
clk_disable_unprepare(kbc->clk);
}
static int tegra_kbc_open(struct input_dev *dev)
{
struct tegra_kbc *kbc = input_get_drvdata(dev);
return tegra_kbc_start(kbc);
}
static void tegra_kbc_close(struct input_dev *dev)
{
struct tegra_kbc *kbc = input_get_drvdata(dev);
return tegra_kbc_stop(kbc);
}
static bool tegra_kbc_check_pin_cfg(const struct tegra_kbc *kbc,
unsigned int *num_rows)
{
int i;
*num_rows = 0;
for (i = 0; i < KBC_MAX_GPIO; i++) {
const struct tegra_kbc_pin_cfg *pin_cfg = &kbc->pin_cfg[i];
switch (pin_cfg->type) {
case PIN_CFG_ROW:
if (pin_cfg->num >= kbc->hw_support->max_rows) {
dev_err(kbc->dev,
"pin_cfg[%d]: invalid row number %d\n",
i, pin_cfg->num);
return false;
}
(*num_rows)++;
break;
case PIN_CFG_COL:
if (pin_cfg->num >= kbc->hw_support->max_columns) {
dev_err(kbc->dev,
"pin_cfg[%d]: invalid column number %d\n",
i, pin_cfg->num);
return false;
}
break;
case PIN_CFG_IGNORE:
break;
default:
dev_err(kbc->dev,
"pin_cfg[%d]: invalid entry type %d\n",
pin_cfg->type, pin_cfg->num);
return false;
}
}
return true;
}
static int tegra_kbc_parse_dt(struct tegra_kbc *kbc)
{
struct device_node *np = kbc->dev->of_node;
u32 prop;
int i;
u32 num_rows = 0;
u32 num_cols = 0;
u32 cols_cfg[KBC_MAX_GPIO];
u32 rows_cfg[KBC_MAX_GPIO];
int proplen;
int ret;
if (!of_property_read_u32(np, "nvidia,debounce-delay-ms", &prop))
kbc->debounce_cnt = prop;
if (!of_property_read_u32(np, "nvidia,repeat-delay-ms", &prop))
kbc->repeat_cnt = prop;
if (of_find_property(np, "nvidia,needs-ghost-filter", NULL))
kbc->use_ghost_filter = true;
if (of_find_property(np, "nvidia,wakeup-source", NULL))
kbc->wakeup = true;
if (!of_get_property(np, "nvidia,kbc-row-pins", &proplen)) {
dev_err(kbc->dev, "property nvidia,kbc-row-pins not found\n");
return -ENOENT;
}
num_rows = proplen / sizeof(u32);
if (!of_get_property(np, "nvidia,kbc-col-pins", &proplen)) {
dev_err(kbc->dev, "property nvidia,kbc-col-pins not found\n");
return -ENOENT;
}
num_cols = proplen / sizeof(u32);
if (num_rows > kbc->hw_support->max_rows) {
dev_err(kbc->dev,
"Number of rows is more than supported by hardware\n");
return -EINVAL;
}
if (num_cols > kbc->hw_support->max_columns) {
dev_err(kbc->dev,
"Number of cols is more than supported by hardware\n");
return -EINVAL;
}
if (!of_get_property(np, "linux,keymap", &proplen)) {
dev_err(kbc->dev, "property linux,keymap not found\n");
return -ENOENT;
}
if (!num_rows || !num_cols || ((num_rows + num_cols) > KBC_MAX_GPIO)) {
dev_err(kbc->dev,
"keypad rows/columns not porperly specified\n");
return -EINVAL;
}
for (i = 0; i < kbc->num_rows_and_columns; i++)
kbc->pin_cfg[i].type = PIN_CFG_IGNORE;
ret = of_property_read_u32_array(np, "nvidia,kbc-row-pins",
rows_cfg, num_rows);
if (ret < 0) {
dev_err(kbc->dev, "Rows configurations are not proper\n");
return -EINVAL;
}
ret = of_property_read_u32_array(np, "nvidia,kbc-col-pins",
cols_cfg, num_cols);
if (ret < 0) {
dev_err(kbc->dev, "Cols configurations are not proper\n");
return -EINVAL;
}
for (i = 0; i < num_rows; i++) {
kbc->pin_cfg[rows_cfg[i]].type = PIN_CFG_ROW;
kbc->pin_cfg[rows_cfg[i]].num = i;
}
for (i = 0; i < num_cols; i++) {
kbc->pin_cfg[cols_cfg[i]].type = PIN_CFG_COL;
kbc->pin_cfg[cols_cfg[i]].num = i;
}
return 0;
}
static int tegra_kbc_probe(struct platform_device *pdev)
{
struct tegra_kbc *kbc;
struct resource *res;
int err;
int num_rows = 0;
unsigned int debounce_cnt;
unsigned int scan_time_rows;
unsigned int keymap_rows;
const struct of_device_id *match;
match = of_match_device(of_match_ptr(tegra_kbc_of_match), &pdev->dev);
kbc = devm_kzalloc(&pdev->dev, sizeof(*kbc), GFP_KERNEL);
if (!kbc) {
dev_err(&pdev->dev, "failed to alloc memory for kbc\n");
return -ENOMEM;
}
kbc->dev = &pdev->dev;
kbc->hw_support = match->data;
kbc->max_keys = kbc->hw_support->max_rows *
kbc->hw_support->max_columns;
kbc->num_rows_and_columns = kbc->hw_support->max_rows +
kbc->hw_support->max_columns;
keymap_rows = kbc->max_keys;
spin_lock_init(&kbc->lock);
err = tegra_kbc_parse_dt(kbc);
if (err)
return err;
if (!tegra_kbc_check_pin_cfg(kbc, &num_rows))
return -EINVAL;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "failed to get I/O memory\n");
return -ENXIO;
}
kbc->irq = platform_get_irq(pdev, 0);
if (kbc->irq < 0) {
dev_err(&pdev->dev, "failed to get keyboard IRQ\n");
return -ENXIO;
}
kbc->idev = devm_input_allocate_device(&pdev->dev);
if (!kbc->idev) {
dev_err(&pdev->dev, "failed to allocate input device\n");
return -ENOMEM;
}
setup_timer(&kbc->timer, tegra_kbc_keypress_timer, (unsigned long)kbc);
kbc->mmio = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(kbc->mmio))
return PTR_ERR(kbc->mmio);
kbc->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(kbc->clk)) {
dev_err(&pdev->dev, "failed to get keyboard clock\n");
return PTR_ERR(kbc->clk);
}
debounce_cnt = min(kbc->debounce_cnt, KBC_MAX_DEBOUNCE_CNT);
scan_time_rows = (KBC_ROW_SCAN_TIME + debounce_cnt) * num_rows;
kbc->repoll_dly = KBC_ROW_SCAN_DLY + scan_time_rows + kbc->repeat_cnt;
kbc->repoll_dly = DIV_ROUND_UP(kbc->repoll_dly, KBC_CYCLE_MS);
kbc->idev->name = pdev->name;
kbc->idev->id.bustype = BUS_HOST;
kbc->idev->dev.parent = &pdev->dev;
kbc->idev->open = tegra_kbc_open;
kbc->idev->close = tegra_kbc_close;
if (kbc->keymap_data && kbc->use_fn_map)
keymap_rows *= 2;
err = matrix_keypad_build_keymap(kbc->keymap_data, NULL,
keymap_rows,
kbc->hw_support->max_columns,
kbc->keycode, kbc->idev);
if (err) {
dev_err(&pdev->dev, "failed to setup keymap\n");
return err;
}
__set_bit(EV_REP, kbc->idev->evbit);
input_set_capability(kbc->idev, EV_MSC, MSC_SCAN);
input_set_drvdata(kbc->idev, kbc);
err = devm_request_irq(&pdev->dev, kbc->irq, tegra_kbc_isr,
IRQF_NO_SUSPEND | IRQF_TRIGGER_HIGH, pdev->name, kbc);
if (err) {
dev_err(&pdev->dev, "failed to request keyboard IRQ\n");
return err;
}
disable_irq(kbc->irq);
err = input_register_device(kbc->idev);
if (err) {
dev_err(&pdev->dev, "failed to register input device\n");
return err;
}
platform_set_drvdata(pdev, kbc);
device_init_wakeup(&pdev->dev, kbc->wakeup);
return 0;
}
static void tegra_kbc_set_keypress_interrupt(struct tegra_kbc *kbc, bool enable)
{
u32 val;
val = readl(kbc->mmio + KBC_CONTROL_0);
if (enable)
val |= KBC_CONTROL_KEYPRESS_INT_EN;
else
val &= ~KBC_CONTROL_KEYPRESS_INT_EN;
writel(val, kbc->mmio + KBC_CONTROL_0);
}
static int tegra_kbc_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct tegra_kbc *kbc = platform_get_drvdata(pdev);
mutex_lock(&kbc->idev->mutex);
if (device_may_wakeup(&pdev->dev)) {
disable_irq(kbc->irq);
del_timer_sync(&kbc->timer);
tegra_kbc_set_fifo_interrupt(kbc, false);
writel(0x7, kbc->mmio + KBC_INT_0);
kbc->cp_to_wkup_dly = readl(kbc->mmio + KBC_TO_CNT_0);
writel(0, kbc->mmio + KBC_TO_CNT_0);
tegra_kbc_setup_wakekeys(kbc, true);
msleep(30);
kbc->keypress_caused_wake = false;
tegra_kbc_set_keypress_interrupt(kbc, true);
enable_irq(kbc->irq);
enable_irq_wake(kbc->irq);
} else {
if (kbc->idev->users)
tegra_kbc_stop(kbc);
}
mutex_unlock(&kbc->idev->mutex);
return 0;
}
static int tegra_kbc_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct tegra_kbc *kbc = platform_get_drvdata(pdev);
int err = 0;
mutex_lock(&kbc->idev->mutex);
if (device_may_wakeup(&pdev->dev)) {
disable_irq_wake(kbc->irq);
tegra_kbc_setup_wakekeys(kbc, false);
tegra_kbc_set_keypress_interrupt(kbc, false);
writel(kbc->cp_to_wkup_dly, kbc->mmio + KBC_TO_CNT_0);
tegra_kbc_set_fifo_interrupt(kbc, true);
if (kbc->keypress_caused_wake && kbc->wakeup_key) {
input_report_key(kbc->idev, kbc->wakeup_key, 1);
input_sync(kbc->idev);
input_report_key(kbc->idev, kbc->wakeup_key, 0);
input_sync(kbc->idev);
}
} else {
if (kbc->idev->users)
err = tegra_kbc_start(kbc);
}
mutex_unlock(&kbc->idev->mutex);
return err;
}
