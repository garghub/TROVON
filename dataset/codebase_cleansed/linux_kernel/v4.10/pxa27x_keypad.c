static int pxa27x_keypad_matrix_key_parse_dt(struct pxa27x_keypad *keypad,
struct pxa27x_keypad_platform_data *pdata)
{
struct input_dev *input_dev = keypad->input_dev;
struct device *dev = input_dev->dev.parent;
u32 rows, cols;
int error;
error = matrix_keypad_parse_of_params(dev, &rows, &cols);
if (error)
return error;
if (rows > MAX_MATRIX_KEY_ROWS || cols > MAX_MATRIX_KEY_COLS) {
dev_err(dev, "rows or cols exceeds maximum value\n");
return -EINVAL;
}
pdata->matrix_key_rows = rows;
pdata->matrix_key_cols = cols;
error = matrix_keypad_build_keymap(NULL, NULL,
pdata->matrix_key_rows,
pdata->matrix_key_cols,
keypad->keycodes, input_dev);
if (error)
return error;
return 0;
}
static int pxa27x_keypad_direct_key_parse_dt(struct pxa27x_keypad *keypad,
struct pxa27x_keypad_platform_data *pdata)
{
struct input_dev *input_dev = keypad->input_dev;
struct device *dev = input_dev->dev.parent;
struct device_node *np = dev->of_node;
const __be16 *prop;
unsigned short code;
unsigned int proplen, size;
int i;
int error;
error = of_property_read_u32(np, "marvell,direct-key-count",
&pdata->direct_key_num);
if (error) {
return error == -EINVAL ? 0 : error;
}
error = of_property_read_u32(np, "marvell,direct-key-mask",
&pdata->direct_key_mask);
if (error) {
if (error != -EINVAL)
return error;
pdata->direct_key_mask = 0;
}
pdata->direct_key_low_active = of_property_read_bool(np,
"marvell,direct-key-low-active");
prop = of_get_property(np, "marvell,direct-key-map", &proplen);
if (!prop)
return -EINVAL;
if (proplen % sizeof(u16))
return -EINVAL;
size = proplen / sizeof(u16);
if (size > MAX_DIRECT_KEY_NUM)
return -EINVAL;
for (i = 0; i < size; i++) {
code = be16_to_cpup(prop + i);
keypad->keycodes[MAX_MATRIX_KEY_NUM + i] = code;
__set_bit(code, input_dev->keybit);
}
return 0;
}
static int pxa27x_keypad_rotary_parse_dt(struct pxa27x_keypad *keypad,
struct pxa27x_keypad_platform_data *pdata)
{
const __be32 *prop;
int i, relkey_ret;
unsigned int code, proplen;
const char *rotaryname[2] = {
"marvell,rotary0", "marvell,rotary1"};
const char relkeyname[] = {"marvell,rotary-rel-key"};
struct input_dev *input_dev = keypad->input_dev;
struct device *dev = input_dev->dev.parent;
struct device_node *np = dev->of_node;
relkey_ret = of_property_read_u32(np, relkeyname, &code);
if (relkey_ret == 0) {
unsigned short relcode;
relcode = code & 0xffff;
pdata->rotary0_rel_code = (code & 0xffff);
__set_bit(relcode, input_dev->relbit);
relcode = code >> 16;
pdata->rotary1_rel_code = relcode;
__set_bit(relcode, input_dev->relbit);
}
for (i = 0; i < 2; i++) {
prop = of_get_property(np, rotaryname[i], &proplen);
if (!prop)
continue;
code = be32_to_cpup(prop);
if ((!(code & 0xffff) || !(code >> 16)) && relkey_ret) {
return relkey_ret;
} else {
unsigned int n = MAX_MATRIX_KEY_NUM + (i << 1);
unsigned short keycode;
keycode = code & 0xffff;
keypad->keycodes[n] = keycode;
__set_bit(keycode, input_dev->keybit);
keycode = code >> 16;
keypad->keycodes[n + 1] = keycode;
__set_bit(keycode, input_dev->keybit);
if (i == 0)
pdata->rotary0_rel_code = -1;
else
pdata->rotary1_rel_code = -1;
}
if (i == 0)
pdata->enable_rotary0 = 1;
else
pdata->enable_rotary1 = 1;
}
keypad->rotary_rel_code[0] = pdata->rotary0_rel_code;
keypad->rotary_rel_code[1] = pdata->rotary1_rel_code;
return 0;
}
static int pxa27x_keypad_build_keycode_from_dt(struct pxa27x_keypad *keypad)
{
struct input_dev *input_dev = keypad->input_dev;
struct device *dev = input_dev->dev.parent;
struct device_node *np = dev->of_node;
struct pxa27x_keypad_platform_data *pdata;
int error;
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata) {
dev_err(dev, "failed to allocate memory for pdata\n");
return -ENOMEM;
}
error = pxa27x_keypad_matrix_key_parse_dt(keypad, pdata);
if (error) {
dev_err(dev, "failed to parse matrix key\n");
return error;
}
error = pxa27x_keypad_direct_key_parse_dt(keypad, pdata);
if (error) {
dev_err(dev, "failed to parse direct key\n");
return error;
}
error = pxa27x_keypad_rotary_parse_dt(keypad, pdata);
if (error) {
dev_err(dev, "failed to parse rotary key\n");
return error;
}
error = of_property_read_u32(np, "marvell,debounce-interval",
&pdata->debounce_interval);
if (error) {
dev_err(dev, "failed to parse debounce-interval\n");
return error;
}
input_dev->keycodemax = ARRAY_SIZE(keypad->keycodes);
keypad->pdata = pdata;
return 0;
}
static int pxa27x_keypad_build_keycode_from_dt(struct pxa27x_keypad *keypad)
{
dev_info(keypad->input_dev->dev.parent, "missing platform data\n");
return -EINVAL;
}
static int pxa27x_keypad_build_keycode(struct pxa27x_keypad *keypad)
{
const struct pxa27x_keypad_platform_data *pdata = keypad->pdata;
struct input_dev *input_dev = keypad->input_dev;
unsigned short keycode;
int i;
int error;
error = matrix_keypad_build_keymap(pdata->matrix_keymap_data, NULL,
pdata->matrix_key_rows,
pdata->matrix_key_cols,
keypad->keycodes, input_dev);
if (error)
return error;
input_dev->keycodemax = ARRAY_SIZE(keypad->keycodes);
for (i = 0; i < pdata->direct_key_num; i++) {
keycode = pdata->direct_key_map[i];
keypad->keycodes[MAX_MATRIX_KEY_NUM + i] = keycode;
__set_bit(keycode, input_dev->keybit);
}
if (pdata->enable_rotary0) {
if (pdata->rotary0_up_key && pdata->rotary0_down_key) {
keycode = pdata->rotary0_up_key;
keypad->keycodes[MAX_MATRIX_KEY_NUM + 0] = keycode;
__set_bit(keycode, input_dev->keybit);
keycode = pdata->rotary0_down_key;
keypad->keycodes[MAX_MATRIX_KEY_NUM + 1] = keycode;
__set_bit(keycode, input_dev->keybit);
keypad->rotary_rel_code[0] = -1;
} else {
keypad->rotary_rel_code[0] = pdata->rotary0_rel_code;
__set_bit(pdata->rotary0_rel_code, input_dev->relbit);
}
}
if (pdata->enable_rotary1) {
if (pdata->rotary1_up_key && pdata->rotary1_down_key) {
keycode = pdata->rotary1_up_key;
keypad->keycodes[MAX_MATRIX_KEY_NUM + 2] = keycode;
__set_bit(keycode, input_dev->keybit);
keycode = pdata->rotary1_down_key;
keypad->keycodes[MAX_MATRIX_KEY_NUM + 3] = keycode;
__set_bit(keycode, input_dev->keybit);
keypad->rotary_rel_code[1] = -1;
} else {
keypad->rotary_rel_code[1] = pdata->rotary1_rel_code;
__set_bit(pdata->rotary1_rel_code, input_dev->relbit);
}
}
__clear_bit(KEY_RESERVED, input_dev->keybit);
return 0;
}
static void pxa27x_keypad_scan_matrix(struct pxa27x_keypad *keypad)
{
const struct pxa27x_keypad_platform_data *pdata = keypad->pdata;
struct input_dev *input_dev = keypad->input_dev;
int row, col, num_keys_pressed = 0;
uint32_t new_state[MAX_MATRIX_KEY_COLS];
uint32_t kpas = keypad_readl(KPAS);
num_keys_pressed = KPAS_MUKP(kpas);
memset(new_state, 0, sizeof(new_state));
if (num_keys_pressed == 0)
goto scan;
if (num_keys_pressed == 1) {
col = KPAS_CP(kpas);
row = KPAS_RP(kpas);
if (col >= pdata->matrix_key_cols ||
row >= pdata->matrix_key_rows)
goto scan;
new_state[col] = (1 << row);
goto scan;
}
if (num_keys_pressed > 1) {
uint32_t kpasmkp0 = keypad_readl(KPASMKP0);
uint32_t kpasmkp1 = keypad_readl(KPASMKP1);
uint32_t kpasmkp2 = keypad_readl(KPASMKP2);
uint32_t kpasmkp3 = keypad_readl(KPASMKP3);
new_state[0] = kpasmkp0 & KPASMKP_MKC_MASK;
new_state[1] = (kpasmkp0 >> 16) & KPASMKP_MKC_MASK;
new_state[2] = kpasmkp1 & KPASMKP_MKC_MASK;
new_state[3] = (kpasmkp1 >> 16) & KPASMKP_MKC_MASK;
new_state[4] = kpasmkp2 & KPASMKP_MKC_MASK;
new_state[5] = (kpasmkp2 >> 16) & KPASMKP_MKC_MASK;
new_state[6] = kpasmkp3 & KPASMKP_MKC_MASK;
new_state[7] = (kpasmkp3 >> 16) & KPASMKP_MKC_MASK;
}
scan:
for (col = 0; col < pdata->matrix_key_cols; col++) {
uint32_t bits_changed;
int code;
bits_changed = keypad->matrix_key_state[col] ^ new_state[col];
if (bits_changed == 0)
continue;
for (row = 0; row < pdata->matrix_key_rows; row++) {
if ((bits_changed & (1 << row)) == 0)
continue;
code = MATRIX_SCAN_CODE(row, col, keypad->row_shift);
input_event(input_dev, EV_MSC, MSC_SCAN, code);
input_report_key(input_dev, keypad->keycodes[code],
new_state[col] & (1 << row));
}
}
input_sync(input_dev);
memcpy(keypad->matrix_key_state, new_state, sizeof(new_state));
}
static inline int rotary_delta(uint32_t kprec)
{
if (kprec & KPREC_OF0)
return (kprec & 0xff) + 0x7f;
else if (kprec & KPREC_UF0)
return (kprec & 0xff) - 0x7f - 0xff;
else
return (kprec & 0xff) - 0x7f;
}
static void report_rotary_event(struct pxa27x_keypad *keypad, int r, int delta)
{
struct input_dev *dev = keypad->input_dev;
if (delta == 0)
return;
if (keypad->rotary_rel_code[r] == -1) {
int code = MAX_MATRIX_KEY_NUM + 2 * r + (delta > 0 ? 0 : 1);
unsigned char keycode = keypad->keycodes[code];
input_event(dev, EV_MSC, MSC_SCAN, code);
input_report_key(dev, keycode, 1);
input_sync(dev);
input_event(dev, EV_MSC, MSC_SCAN, code);
input_report_key(dev, keycode, 0);
input_sync(dev);
} else {
input_report_rel(dev, keypad->rotary_rel_code[r], delta);
input_sync(dev);
}
}
static void pxa27x_keypad_scan_rotary(struct pxa27x_keypad *keypad)
{
const struct pxa27x_keypad_platform_data *pdata = keypad->pdata;
uint32_t kprec;
kprec = keypad_readl(KPREC);
keypad_writel(KPREC, DEFAULT_KPREC);
if (pdata->enable_rotary0)
report_rotary_event(keypad, 0, rotary_delta(kprec));
if (pdata->enable_rotary1)
report_rotary_event(keypad, 1, rotary_delta(kprec >> 16));
}
static void pxa27x_keypad_scan_direct(struct pxa27x_keypad *keypad)
{
const struct pxa27x_keypad_platform_data *pdata = keypad->pdata;
struct input_dev *input_dev = keypad->input_dev;
unsigned int new_state;
uint32_t kpdk, bits_changed;
int i;
kpdk = keypad_readl(KPDK);
if (pdata->enable_rotary0 || pdata->enable_rotary1)
pxa27x_keypad_scan_rotary(keypad);
if (pdata->direct_key_low_active)
new_state = ~KPDK_DK(kpdk) & keypad->direct_key_mask;
else
new_state = KPDK_DK(kpdk) & keypad->direct_key_mask;
bits_changed = keypad->direct_key_state ^ new_state;
if (bits_changed == 0)
return;
for (i = 0; i < pdata->direct_key_num; i++) {
if (bits_changed & (1 << i)) {
int code = MAX_MATRIX_KEY_NUM + i;
input_event(input_dev, EV_MSC, MSC_SCAN, code);
input_report_key(input_dev, keypad->keycodes[code],
new_state & (1 << i));
}
}
input_sync(input_dev);
keypad->direct_key_state = new_state;
}
static void clear_wakeup_event(struct pxa27x_keypad *keypad)
{
const struct pxa27x_keypad_platform_data *pdata = keypad->pdata;
if (pdata->clear_wakeup_event)
(pdata->clear_wakeup_event)();
}
static irqreturn_t pxa27x_keypad_irq_handler(int irq, void *dev_id)
{
struct pxa27x_keypad *keypad = dev_id;
unsigned long kpc = keypad_readl(KPC);
clear_wakeup_event(keypad);
if (kpc & KPC_DI)
pxa27x_keypad_scan_direct(keypad);
if (kpc & KPC_MI)
pxa27x_keypad_scan_matrix(keypad);
return IRQ_HANDLED;
}
static void pxa27x_keypad_config(struct pxa27x_keypad *keypad)
{
const struct pxa27x_keypad_platform_data *pdata = keypad->pdata;
unsigned int mask = 0, direct_key_num = 0;
unsigned long kpc = 0;
keypad_readl(KPC);
if (pdata->matrix_key_rows && pdata->matrix_key_cols) {
kpc |= KPC_ASACT | KPC_MIE | KPC_ME | KPC_MS_ALL;
kpc |= KPC_MKRN(pdata->matrix_key_rows) |
KPC_MKCN(pdata->matrix_key_cols);
}
if (pdata->enable_rotary0) {
mask |= 0x03;
direct_key_num = 2;
kpc |= KPC_REE0;
}
if (pdata->enable_rotary1) {
mask |= 0x0c;
direct_key_num = 4;
kpc |= KPC_REE1;
}
if (pdata->direct_key_num > direct_key_num)
direct_key_num = pdata->direct_key_num;
if (pdata->direct_key_mask)
keypad->direct_key_mask = pdata->direct_key_mask;
else
keypad->direct_key_mask = ((1 << direct_key_num) - 1) & ~mask;
if (direct_key_num)
kpc |= KPC_DE | KPC_DIE | KPC_DKN(direct_key_num);
keypad_writel(KPC, kpc | KPC_RE_ZERO_DEB);
keypad_writel(KPREC, DEFAULT_KPREC);
keypad_writel(KPKDI, pdata->debounce_interval);
}
static int pxa27x_keypad_open(struct input_dev *dev)
{
struct pxa27x_keypad *keypad = input_get_drvdata(dev);
clk_prepare_enable(keypad->clk);
pxa27x_keypad_config(keypad);
return 0;
}
static void pxa27x_keypad_close(struct input_dev *dev)
{
struct pxa27x_keypad *keypad = input_get_drvdata(dev);
clk_disable_unprepare(keypad->clk);
}
static int pxa27x_keypad_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct pxa27x_keypad *keypad = platform_get_drvdata(pdev);
if (device_may_wakeup(&pdev->dev))
enable_irq_wake(keypad->irq);
else
clk_disable_unprepare(keypad->clk);
return 0;
}
static int pxa27x_keypad_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct pxa27x_keypad *keypad = platform_get_drvdata(pdev);
struct input_dev *input_dev = keypad->input_dev;
if (device_may_wakeup(&pdev->dev)) {
disable_irq_wake(keypad->irq);
} else {
mutex_lock(&input_dev->mutex);
if (input_dev->users) {
clk_prepare_enable(keypad->clk);
pxa27x_keypad_config(keypad);
}
mutex_unlock(&input_dev->mutex);
}
return 0;
}
static int pxa27x_keypad_probe(struct platform_device *pdev)
{
const struct pxa27x_keypad_platform_data *pdata =
dev_get_platdata(&pdev->dev);
struct device_node *np = pdev->dev.of_node;
struct pxa27x_keypad *keypad;
struct input_dev *input_dev;
struct resource *res;
int irq, error;
if (!np && !pdata)
return -EINVAL;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "failed to get keypad irq\n");
return -ENXIO;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(&pdev->dev, "failed to get I/O memory\n");
return -ENXIO;
}
keypad = devm_kzalloc(&pdev->dev, sizeof(*keypad),
GFP_KERNEL);
if (!keypad)
return -ENOMEM;
input_dev = devm_input_allocate_device(&pdev->dev);
if (!input_dev)
return -ENOMEM;
keypad->pdata = pdata;
keypad->input_dev = input_dev;
keypad->irq = irq;
keypad->mmio_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(keypad->mmio_base))
return PTR_ERR(keypad->mmio_base);
keypad->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(keypad->clk)) {
dev_err(&pdev->dev, "failed to get keypad clock\n");
return PTR_ERR(keypad->clk);
}
input_dev->name = pdev->name;
input_dev->id.bustype = BUS_HOST;
input_dev->open = pxa27x_keypad_open;
input_dev->close = pxa27x_keypad_close;
input_dev->dev.parent = &pdev->dev;
input_dev->keycode = keypad->keycodes;
input_dev->keycodesize = sizeof(keypad->keycodes[0]);
input_dev->keycodemax = ARRAY_SIZE(keypad->keycodes);
input_set_drvdata(input_dev, keypad);
input_dev->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_REP);
input_set_capability(input_dev, EV_MSC, MSC_SCAN);
if (pdata) {
error = pxa27x_keypad_build_keycode(keypad);
} else {
error = pxa27x_keypad_build_keycode_from_dt(keypad);
pdata = keypad->pdata;
}
if (error) {
dev_err(&pdev->dev, "failed to build keycode\n");
return error;
}
keypad->row_shift = get_count_order(pdata->matrix_key_cols);
if ((pdata->enable_rotary0 && keypad->rotary_rel_code[0] != -1) ||
(pdata->enable_rotary1 && keypad->rotary_rel_code[1] != -1)) {
input_dev->evbit[0] |= BIT_MASK(EV_REL);
}
error = devm_request_irq(&pdev->dev, irq, pxa27x_keypad_irq_handler,
0, pdev->name, keypad);
if (error) {
dev_err(&pdev->dev, "failed to request IRQ\n");
return error;
}
error = input_register_device(input_dev);
if (error) {
dev_err(&pdev->dev, "failed to register input device\n");
return error;
}
platform_set_drvdata(pdev, keypad);
device_init_wakeup(&pdev->dev, 1);
return 0;
}
