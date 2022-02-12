static inline int irq_data_to_status_reg(struct wm8994_irq_data *irq_data)
{
return WM8994_INTERRUPT_STATUS_1 - 1 + irq_data->reg;
}
static inline int irq_data_to_mask_reg(struct wm8994_irq_data *irq_data)
{
return WM8994_INTERRUPT_STATUS_1_MASK - 1 + irq_data->reg;
}
static inline struct wm8994_irq_data *irq_to_wm8994_irq(struct wm8994 *wm8994,
int irq)
{
return &wm8994_irqs[irq - wm8994->irq_base];
}
static void wm8994_irq_lock(struct irq_data *data)
{
struct wm8994 *wm8994 = irq_data_get_irq_chip_data(data);
mutex_lock(&wm8994->irq_lock);
}
static void wm8994_irq_sync_unlock(struct irq_data *data)
{
struct wm8994 *wm8994 = irq_data_get_irq_chip_data(data);
int i;
for (i = 0; i < ARRAY_SIZE(wm8994->irq_masks_cur); i++) {
if (wm8994->irq_masks_cur[i] != wm8994->irq_masks_cache[i]) {
wm8994->irq_masks_cache[i] = wm8994->irq_masks_cur[i];
wm8994_reg_write(wm8994,
WM8994_INTERRUPT_STATUS_1_MASK + i,
wm8994->irq_masks_cur[i]);
}
}
mutex_unlock(&wm8994->irq_lock);
}
static void wm8994_irq_enable(struct irq_data *data)
{
struct wm8994 *wm8994 = irq_data_get_irq_chip_data(data);
struct wm8994_irq_data *irq_data = irq_to_wm8994_irq(wm8994,
data->irq);
wm8994->irq_masks_cur[irq_data->reg - 1] &= ~irq_data->mask;
}
static void wm8994_irq_disable(struct irq_data *data)
{
struct wm8994 *wm8994 = irq_data_get_irq_chip_data(data);
struct wm8994_irq_data *irq_data = irq_to_wm8994_irq(wm8994,
data->irq);
wm8994->irq_masks_cur[irq_data->reg - 1] |= irq_data->mask;
}
static irqreturn_t wm8994_irq_thread(int irq, void *data)
{
struct wm8994 *wm8994 = data;
unsigned int i;
u16 status[WM8994_NUM_IRQ_REGS];
int ret;
ret = wm8994_bulk_read(wm8994, WM8994_INTERRUPT_STATUS_1,
WM8994_NUM_IRQ_REGS, status);
if (ret < 0) {
dev_err(wm8994->dev, "Failed to read interrupt status: %d\n",
ret);
return IRQ_NONE;
}
for (i = 0; i < WM8994_NUM_IRQ_REGS; i++) {
status[i] = be16_to_cpu(status[i]);
status[i] &= ~wm8994->irq_masks_cur[i];
}
for (i = 0; i < ARRAY_SIZE(status); i++) {
if (status[i])
wm8994_reg_write(wm8994, WM8994_INTERRUPT_STATUS_1 + i,
status[i]);
}
for (i = 0; i < ARRAY_SIZE(wm8994_irqs); i++) {
if (status[wm8994_irqs[i].reg - 1] & wm8994_irqs[i].mask)
handle_nested_irq(wm8994->irq_base + i);
}
return IRQ_HANDLED;
}
int wm8994_irq_init(struct wm8994 *wm8994)
{
int i, cur_irq, ret;
mutex_init(&wm8994->irq_lock);
for (i = 0; i < ARRAY_SIZE(wm8994->irq_masks_cur); i++) {
wm8994->irq_masks_cur[i] = 0xffff;
wm8994->irq_masks_cache[i] = 0xffff;
wm8994_reg_write(wm8994, WM8994_INTERRUPT_STATUS_1_MASK + i,
0xffff);
}
if (!wm8994->irq) {
dev_warn(wm8994->dev,
"No interrupt specified, no interrupts\n");
wm8994->irq_base = 0;
return 0;
}
if (!wm8994->irq_base) {
dev_err(wm8994->dev,
"No interrupt base specified, no interrupts\n");
return 0;
}
for (cur_irq = wm8994->irq_base;
cur_irq < ARRAY_SIZE(wm8994_irqs) + wm8994->irq_base;
cur_irq++) {
irq_set_chip_data(cur_irq, wm8994);
irq_set_chip_and_handler(cur_irq, &wm8994_irq_chip,
handle_edge_irq);
irq_set_nested_thread(cur_irq, 1);
#ifdef CONFIG_ARM
set_irq_flags(cur_irq, IRQF_VALID);
#else
irq_set_noprobe(cur_irq);
#endif
}
ret = request_threaded_irq(wm8994->irq, NULL, wm8994_irq_thread,
IRQF_TRIGGER_HIGH | IRQF_ONESHOT,
"wm8994", wm8994);
if (ret != 0) {
dev_err(wm8994->dev, "Failed to request IRQ %d: %d\n",
wm8994->irq, ret);
return ret;
}
wm8994_reg_write(wm8994, WM8994_INTERRUPT_CONTROL, 0);
return 0;
}
void wm8994_irq_exit(struct wm8994 *wm8994)
{
if (wm8994->irq)
free_irq(wm8994->irq, wm8994);
}
