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
scancodes[i] += KBC_MAX_KEY;
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
const struct tegra_kbc_platform_data *pdata = kbc->pdata;
int i;
unsigned int rst_val;
rst_val = (filter && !pdata->wakeup) ? ~0 : 0;
for (i = 0; i < KBC_MAX_ROW; i++)
writel(rst_val, kbc->mmio + KBC_ROW0_MASK_0 + i * 4);
}
static void tegra_kbc_config_pins(struct tegra_kbc *kbc)
{
const struct tegra_kbc_platform_data *pdata = kbc->pdata;
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
switch (pdata->pin_cfg[i].type) {
case PIN_CFG_ROW:
row_cfg |= ((pdata->pin_cfg[i].num << 1) | 1) << r_shft;
break;
case PIN_CFG_COL:
col_cfg |= ((pdata->pin_cfg[i].num << 1) | 1) << c_shft;
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
const struct tegra_kbc_platform_data *pdata = kbc->pdata;
unsigned int debounce_cnt;
u32 val = 0;
clk_enable(kbc->clk);
tegra_periph_reset_assert(kbc->clk);
udelay(100);
tegra_periph_reset_deassert(kbc->clk);
udelay(100);
tegra_kbc_config_pins(kbc);
tegra_kbc_setup_wakekeys(kbc, false);
writel(pdata->repeat_cnt, kbc->mmio + KBC_RPT_DLY_0);
debounce_cnt = min(pdata->debounce_cnt, KBC_MAX_DEBOUNCE_CNT);
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
clk_disable(kbc->clk);
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
static bool __devinit
tegra_kbc_check_pin_cfg(const struct tegra_kbc_platform_data *pdata,
struct device *dev, unsigned int *num_rows)
{
int i;
*num_rows = 0;
for (i = 0; i < KBC_MAX_GPIO; i++) {
const struct tegra_kbc_pin_cfg *pin_cfg = &pdata->pin_cfg[i];
switch (pin_cfg->type) {
case PIN_CFG_ROW:
if (pin_cfg->num >= KBC_MAX_ROW) {
dev_err(dev,
"pin_cfg[%d]: invalid row number %d\n",
i, pin_cfg->num);
return false;
}
(*num_rows)++;
break;
case PIN_CFG_COL:
if (pin_cfg->num >= KBC_MAX_COL) {
dev_err(dev,
"pin_cfg[%d]: invalid column number %d\n",
i, pin_cfg->num);
return false;
}
break;
case PIN_CFG_IGNORE:
break;
default:
dev_err(dev,
"pin_cfg[%d]: invalid entry type %d\n",
pin_cfg->type, pin_cfg->num);
return false;
}
}
return true;
}
static struct tegra_kbc_platform_data * __devinit
tegra_kbc_dt_parse_pdata(struct platform_device *pdev)
{
struct tegra_kbc_platform_data *pdata;
struct device_node *np = pdev->dev.of_node;
u32 prop;
int i;
if (!np)
return NULL;
pdata = kzalloc(sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return NULL;
if (!of_property_read_u32(np, "nvidia,debounce-delay-ms", &prop))
pdata->debounce_cnt = prop;
if (!of_property_read_u32(np, "nvidia,repeat-delay-ms", &prop))
pdata->repeat_cnt = prop;
if (of_find_property(np, "nvidia,needs-ghost-filter", NULL))
pdata->use_ghost_filter = true;
if (of_find_property(np, "nvidia,wakeup-source", NULL))
pdata->wakeup = true;
for (i = 0; i < KBC_MAX_ROW; i++) {
pdata->pin_cfg[i].num = i;
pdata->pin_cfg[i].type = PIN_CFG_ROW;
}
for (i = 0; i < KBC_MAX_COL; i++) {
pdata->pin_cfg[KBC_MAX_ROW + i].num = i;
pdata->pin_cfg[KBC_MAX_ROW + i].type = PIN_CFG_COL;
}
pdata->keymap_data = matrix_keyboard_of_fill_keymap(np, "linux,keymap");
return pdata;
}
static inline struct tegra_kbc_platform_data *tegra_kbc_dt_parse_pdata(
struct platform_device *pdev)
{
return NULL;
}
static int __devinit tegra_kbc_probe(struct platform_device *pdev)
{
const struct tegra_kbc_platform_data *pdata = pdev->dev.platform_data;
const struct matrix_keymap_data *keymap_data;
struct tegra_kbc *kbc;
struct input_dev *input_dev;
struct resource *res;
int irq;
int err;
int num_rows = 0;
unsigned int debounce_cnt;
unsigned int scan_time_rows;
if (!pdata)
pdata = tegra_kbc_dt_parse_pdata(pdev);
if (!pdata)
return -EINVAL;
if (!tegra_kbc_check_pin_cfg(pdata, &pdev->dev, &num_rows)) {
err = -EINVAL;
goto err_free_pdata;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "failed to get I/O memory\n");
err = -ENXIO;
goto err_free_pdata;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "failed to get keyboard IRQ\n");
err = -ENXIO;
goto err_free_pdata;
}
kbc = kzalloc(sizeof(*kbc), GFP_KERNEL);
input_dev = input_allocate_device();
if (!kbc || !input_dev) {
err = -ENOMEM;
goto err_free_mem;
}
kbc->pdata = pdata;
kbc->idev = input_dev;
kbc->irq = irq;
spin_lock_init(&kbc->lock);
setup_timer(&kbc->timer, tegra_kbc_keypress_timer, (unsigned long)kbc);
res = request_mem_region(res->start, resource_size(res), pdev->name);
if (!res) {
dev_err(&pdev->dev, "failed to request I/O memory\n");
err = -EBUSY;
goto err_free_mem;
}
kbc->mmio = ioremap(res->start, resource_size(res));
if (!kbc->mmio) {
dev_err(&pdev->dev, "failed to remap I/O memory\n");
err = -ENXIO;
goto err_free_mem_region;
}
kbc->clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(kbc->clk)) {
dev_err(&pdev->dev, "failed to get keyboard clock\n");
err = PTR_ERR(kbc->clk);
goto err_iounmap;
}
debounce_cnt = min(pdata->debounce_cnt, KBC_MAX_DEBOUNCE_CNT);
scan_time_rows = (KBC_ROW_SCAN_TIME + debounce_cnt) * num_rows;
kbc->repoll_dly = KBC_ROW_SCAN_DLY + scan_time_rows + pdata->repeat_cnt;
kbc->repoll_dly = DIV_ROUND_UP(kbc->repoll_dly, KBC_CYCLE_MS);
input_dev->name = pdev->name;
input_dev->id.bustype = BUS_HOST;
input_dev->dev.parent = &pdev->dev;
input_dev->open = tegra_kbc_open;
input_dev->close = tegra_kbc_close;
input_set_drvdata(input_dev, kbc);
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REP);
input_set_capability(input_dev, EV_MSC, MSC_SCAN);
input_dev->keycode = kbc->keycode;
input_dev->keycodesize = sizeof(kbc->keycode[0]);
input_dev->keycodemax = KBC_MAX_KEY;
if (pdata->use_fn_map)
input_dev->keycodemax *= 2;
kbc->use_fn_map = pdata->use_fn_map;
kbc->use_ghost_filter = pdata->use_ghost_filter;
keymap_data = pdata->keymap_data ?: &tegra_kbc_default_keymap_data;
matrix_keypad_build_keymap(keymap_data, KBC_ROW_SHIFT,
input_dev->keycode, input_dev->keybit);
kbc->wakeup_key = pdata->wakeup_key;
err = request_irq(kbc->irq, tegra_kbc_isr,
IRQF_NO_SUSPEND | IRQF_TRIGGER_HIGH, pdev->name, kbc);
if (err) {
dev_err(&pdev->dev, "failed to request keyboard IRQ\n");
goto err_put_clk;
}
disable_irq(kbc->irq);
err = input_register_device(kbc->idev);
if (err) {
dev_err(&pdev->dev, "failed to register input device\n");
goto err_free_irq;
}
platform_set_drvdata(pdev, kbc);
device_init_wakeup(&pdev->dev, pdata->wakeup);
if (!pdev->dev.platform_data)
matrix_keyboard_of_free_keymap(pdata->keymap_data);
return 0;
err_free_irq:
free_irq(kbc->irq, pdev);
err_put_clk:
clk_put(kbc->clk);
err_iounmap:
iounmap(kbc->mmio);
err_free_mem_region:
release_mem_region(res->start, resource_size(res));
err_free_mem:
input_free_device(input_dev);
kfree(kbc);
err_free_pdata:
if (!pdev->dev.platform_data) {
matrix_keyboard_of_free_keymap(pdata->keymap_data);
kfree(pdata);
}
return err;
}
static int __devexit tegra_kbc_remove(struct platform_device *pdev)
{
struct tegra_kbc *kbc = platform_get_drvdata(pdev);
struct resource *res;
platform_set_drvdata(pdev, NULL);
free_irq(kbc->irq, pdev);
clk_put(kbc->clk);
input_unregister_device(kbc->idev);
iounmap(kbc->mmio);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(res->start, resource_size(res));
if (!pdev->dev.platform_data)
kfree(kbc->pdata);
kfree(kbc);
return 0;
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
