static void set_col_gpio_val(struct omap_kp *omap_kp, u8 value)
{
int col;
for (col = 0; col < omap_kp->cols; col++)
gpio_set_value(col_gpios[col], value & (1 << col));
}
static u8 get_row_gpio_val(struct omap_kp *omap_kp)
{
int row;
u8 value = 0;
for (row = 0; row < omap_kp->rows; row++) {
if (gpio_get_value(row_gpios[row]))
value |= (1 << row);
}
return value;
}
static irqreturn_t omap_kp_interrupt(int irq, void *dev_id)
{
struct omap_kp *omap_kp = dev_id;
if (cpu_is_omap24xx()) {
int i;
for (i = 0; i < omap_kp->rows; i++) {
int gpio_irq = gpio_to_irq(row_gpios[i]);
if (gpio_irq == irq)
disable_irq_nosync(gpio_irq);
else
disable_irq(gpio_irq);
}
} else
omap_writew(1, OMAP1_MPUIO_BASE + OMAP_MPUIO_KBD_MASKIT);
tasklet_schedule(&kp_tasklet);
return IRQ_HANDLED;
}
static void omap_kp_timer(unsigned long data)
{
tasklet_schedule(&kp_tasklet);
}
static void omap_kp_scan_keypad(struct omap_kp *omap_kp, unsigned char *state)
{
int col = 0;
if (cpu_is_omap24xx()) {
for (col = 0; col < omap_kp->cols; col++) {
set_col_gpio_val(omap_kp, ~(1 << col));
state[col] = ~(get_row_gpio_val(omap_kp)) & 0xff;
}
set_col_gpio_val(omap_kp, 0);
} else {
omap_writew(1, OMAP1_MPUIO_BASE + OMAP_MPUIO_KBD_MASKIT);
omap_writew(0xff, OMAP1_MPUIO_BASE + OMAP_MPUIO_KBC);
for (col = 0; col < omap_kp->cols; col++) {
omap_writew(~(1 << col) & 0xff,
OMAP1_MPUIO_BASE + OMAP_MPUIO_KBC);
udelay(omap_kp->delay);
state[col] = ~omap_readw(OMAP1_MPUIO_BASE +
OMAP_MPUIO_KBR_LATCH) & 0xff;
}
omap_writew(0x00, OMAP1_MPUIO_BASE + OMAP_MPUIO_KBC);
udelay(2);
}
}
static void omap_kp_tasklet(unsigned long data)
{
struct omap_kp *omap_kp_data = (struct omap_kp *) data;
unsigned short *keycodes = omap_kp_data->input->keycode;
unsigned int row_shift = get_count_order(omap_kp_data->cols);
unsigned char new_state[8], changed, key_down = 0;
int col, row;
int spurious = 0;
omap_kp_scan_keypad(omap_kp_data, new_state);
for (col = 0; col < omap_kp_data->cols; col++) {
changed = new_state[col] ^ keypad_state[col];
key_down |= new_state[col];
if (changed == 0)
continue;
for (row = 0; row < omap_kp_data->rows; row++) {
int key;
if (!(changed & (1 << row)))
continue;
#ifdef NEW_BOARD_LEARNING_MODE
printk(KERN_INFO "omap-keypad: key %d-%d %s\n", col,
row, (new_state[col] & (1 << row)) ?
"pressed" : "released");
#else
key = keycodes[MATRIX_SCAN_CODE(row, col, row_shift)];
if (key < 0) {
printk(KERN_WARNING
"omap-keypad: Spurious key event %d-%d\n",
col, row);
spurious = 1;
continue;
}
if (!(kp_cur_group == (key & GROUP_MASK) ||
kp_cur_group == -1))
continue;
kp_cur_group = key & GROUP_MASK;
input_report_key(omap_kp_data->input, key & ~GROUP_MASK,
new_state[col] & (1 << row));
#endif
}
}
input_sync(omap_kp_data->input);
memcpy(keypad_state, new_state, sizeof(keypad_state));
if (key_down) {
int delay = HZ / 20;
if (spurious)
delay = 2 * HZ;
mod_timer(&omap_kp_data->timer, jiffies + delay);
} else {
if (cpu_is_omap24xx()) {
int i;
for (i = 0; i < omap_kp_data->rows; i++)
enable_irq(gpio_to_irq(row_gpios[i]));
} else {
omap_writew(0, OMAP1_MPUIO_BASE + OMAP_MPUIO_KBD_MASKIT);
kp_cur_group = -1;
}
}
}
static ssize_t omap_kp_enable_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf, "%u\n", kp_enable);
}
static ssize_t omap_kp_enable_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int state;
if (sscanf(buf, "%u", &state) != 1)
return -EINVAL;
if ((state != 1) && (state != 0))
return -EINVAL;
mutex_lock(&kp_enable_mutex);
if (state != kp_enable) {
if (state)
enable_irq(INT_KEYBOARD);
else
disable_irq(INT_KEYBOARD);
kp_enable = state;
}
mutex_unlock(&kp_enable_mutex);
return strnlen(buf, count);
}
static int omap_kp_suspend(struct platform_device *dev, pm_message_t state)
{
return 0;
}
static int omap_kp_resume(struct platform_device *dev)
{
return 0;
}
static int __devinit omap_kp_probe(struct platform_device *pdev)
{
struct omap_kp *omap_kp;
struct input_dev *input_dev;
struct omap_kp_platform_data *pdata = pdev->dev.platform_data;
int i, col_idx, row_idx, irq_idx, ret;
unsigned int row_shift, keycodemax;
if (!pdata->rows || !pdata->cols || !pdata->keymap_data) {
printk(KERN_ERR "No rows, cols or keymap_data from pdata\n");
return -EINVAL;
}
row_shift = get_count_order(pdata->cols);
keycodemax = pdata->rows << row_shift;
omap_kp = kzalloc(sizeof(struct omap_kp) +
keycodemax * sizeof(unsigned short), GFP_KERNEL);
input_dev = input_allocate_device();
if (!omap_kp || !input_dev) {
kfree(omap_kp);
input_free_device(input_dev);
return -ENOMEM;
}
platform_set_drvdata(pdev, omap_kp);
omap_kp->input = input_dev;
if (!cpu_is_omap24xx())
omap_writew(1, OMAP1_MPUIO_BASE + OMAP_MPUIO_KBD_MASKIT);
if (pdata->delay)
omap_kp->delay = pdata->delay;
if (pdata->row_gpios && pdata->col_gpios) {
row_gpios = pdata->row_gpios;
col_gpios = pdata->col_gpios;
}
omap_kp->rows = pdata->rows;
omap_kp->cols = pdata->cols;
if (cpu_is_omap24xx()) {
for (col_idx = 0; col_idx < omap_kp->cols; col_idx++) {
if (gpio_request(col_gpios[col_idx], "omap_kp_col") < 0) {
printk(KERN_ERR "Failed to request"
"GPIO%d for keypad\n",
col_gpios[col_idx]);
goto err1;
}
gpio_direction_output(col_gpios[col_idx], 0);
}
for (row_idx = 0; row_idx < omap_kp->rows; row_idx++) {
if (gpio_request(row_gpios[row_idx], "omap_kp_row") < 0) {
printk(KERN_ERR "Failed to request"
"GPIO%d for keypad\n",
row_gpios[row_idx]);
goto err2;
}
gpio_direction_input(row_gpios[row_idx]);
}
} else {
col_idx = 0;
row_idx = 0;
}
setup_timer(&omap_kp->timer, omap_kp_timer, (unsigned long)omap_kp);
tasklet_enable(&kp_tasklet);
kp_tasklet.data = (unsigned long) omap_kp;
ret = device_create_file(&pdev->dev, &dev_attr_enable);
if (ret < 0)
goto err2;
input_dev->name = "omap-keypad";
input_dev->phys = "omap-keypad/input0";
input_dev->dev.parent = &pdev->dev;
input_dev->id.bustype = BUS_HOST;
input_dev->id.vendor = 0x0001;
input_dev->id.product = 0x0001;
input_dev->id.version = 0x0100;
if (pdata->rep)
__set_bit(EV_REP, input_dev->evbit);
ret = matrix_keypad_build_keymap(pdata->keymap_data, NULL,
pdata->rows, pdata->cols,
omap_kp->keymap, input_dev);
if (ret < 0)
goto err3;
ret = input_register_device(omap_kp->input);
if (ret < 0) {
printk(KERN_ERR "Unable to register omap-keypad input device\n");
goto err3;
}
if (pdata->dbounce)
omap_writew(0xff, OMAP1_MPUIO_BASE + OMAP_MPUIO_GPIO_DEBOUNCING);
omap_kp_scan_keypad(omap_kp, keypad_state);
if (!cpu_is_omap24xx()) {
omap_kp->irq = platform_get_irq(pdev, 0);
if (omap_kp->irq >= 0) {
if (request_irq(omap_kp->irq, omap_kp_interrupt, 0,
"omap-keypad", omap_kp) < 0)
goto err4;
}
omap_writew(0, OMAP1_MPUIO_BASE + OMAP_MPUIO_KBD_MASKIT);
} else {
for (irq_idx = 0; irq_idx < omap_kp->rows; irq_idx++) {
if (request_irq(gpio_to_irq(row_gpios[irq_idx]),
omap_kp_interrupt,
IRQF_TRIGGER_FALLING,
"omap-keypad", omap_kp) < 0)
goto err5;
}
}
return 0;
err5:
for (i = irq_idx - 1; i >=0; i--)
free_irq(row_gpios[i], omap_kp);
err4:
input_unregister_device(omap_kp->input);
input_dev = NULL;
err3:
device_remove_file(&pdev->dev, &dev_attr_enable);
err2:
for (i = row_idx - 1; i >=0; i--)
gpio_free(row_gpios[i]);
err1:
for (i = col_idx - 1; i >=0; i--)
gpio_free(col_gpios[i]);
kfree(omap_kp);
input_free_device(input_dev);
return -EINVAL;
}
static int __devexit omap_kp_remove(struct platform_device *pdev)
{
struct omap_kp *omap_kp = platform_get_drvdata(pdev);
tasklet_disable(&kp_tasklet);
if (cpu_is_omap24xx()) {
int i;
for (i = 0; i < omap_kp->cols; i++)
gpio_free(col_gpios[i]);
for (i = 0; i < omap_kp->rows; i++) {
gpio_free(row_gpios[i]);
free_irq(gpio_to_irq(row_gpios[i]), omap_kp);
}
} else {
omap_writew(1, OMAP1_MPUIO_BASE + OMAP_MPUIO_KBD_MASKIT);
free_irq(omap_kp->irq, omap_kp);
}
del_timer_sync(&omap_kp->timer);
tasklet_kill(&kp_tasklet);
input_unregister_device(omap_kp->input);
kfree(omap_kp);
return 0;
}
