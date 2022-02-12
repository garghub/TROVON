static inline struct wm8350_irq_data *irq_to_wm8350_irq(struct wm8350 *wm8350,
int irq)
{
return &wm8350_irqs[irq - wm8350->irq_base];
}
static irqreturn_t wm8350_irq(int irq, void *irq_data)
{
struct wm8350 *wm8350 = irq_data;
u16 level_one;
u16 sub_reg[WM8350_NUM_IRQ_REGS];
int read_done[WM8350_NUM_IRQ_REGS];
struct wm8350_irq_data *data;
int i;
level_one = wm8350_reg_read(wm8350, WM8350_SYSTEM_INTERRUPTS)
& ~wm8350_reg_read(wm8350, WM8350_SYSTEM_INTERRUPTS_MASK);
if (!level_one)
return IRQ_NONE;
memset(&read_done, 0, sizeof(read_done));
for (i = 0; i < ARRAY_SIZE(wm8350_irqs); i++) {
data = &wm8350_irqs[i];
if (!(level_one & data->primary))
continue;
if (!read_done[data->reg]) {
sub_reg[data->reg] =
wm8350_reg_read(wm8350, WM8350_INT_STATUS_1 +
data->reg);
sub_reg[data->reg] &= ~wm8350->irq_masks[data->reg];
read_done[data->reg] = 1;
}
if (sub_reg[data->reg] & data->mask)
handle_nested_irq(wm8350->irq_base + i);
}
return IRQ_HANDLED;
}
static void wm8350_irq_lock(struct irq_data *data)
{
struct wm8350 *wm8350 = irq_data_get_irq_chip_data(data);
mutex_lock(&wm8350->irq_lock);
}
static void wm8350_irq_sync_unlock(struct irq_data *data)
{
struct wm8350 *wm8350 = irq_data_get_irq_chip_data(data);
int i;
for (i = 0; i < ARRAY_SIZE(wm8350->irq_masks); i++) {
WARN_ON(regmap_update_bits(wm8350->regmap,
WM8350_INT_STATUS_1_MASK + i,
0xffff, wm8350->irq_masks[i]));
}
mutex_unlock(&wm8350->irq_lock);
}
static void wm8350_irq_enable(struct irq_data *data)
{
struct wm8350 *wm8350 = irq_data_get_irq_chip_data(data);
struct wm8350_irq_data *irq_data = irq_to_wm8350_irq(wm8350,
data->irq);
wm8350->irq_masks[irq_data->reg] &= ~irq_data->mask;
}
static void wm8350_irq_disable(struct irq_data *data)
{
struct wm8350 *wm8350 = irq_data_get_irq_chip_data(data);
struct wm8350_irq_data *irq_data = irq_to_wm8350_irq(wm8350,
data->irq);
wm8350->irq_masks[irq_data->reg] |= irq_data->mask;
}
int wm8350_irq_init(struct wm8350 *wm8350, int irq,
struct wm8350_platform_data *pdata)
{
int ret, cur_irq, i;
int flags = IRQF_ONESHOT;
int irq_base = -1;
if (!irq) {
dev_warn(wm8350->dev, "No interrupt support, no core IRQ\n");
return 0;
}
wm8350_reg_write(wm8350, WM8350_SYSTEM_INTERRUPTS_MASK, 0xFFFF);
for (i = 0; i < ARRAY_SIZE(wm8350->irq_masks); i++) {
wm8350_reg_write(wm8350, WM8350_INT_STATUS_1_MASK + i,
0xFFFF);
wm8350->irq_masks[i] =
wm8350_reg_read(wm8350,
WM8350_INT_STATUS_1_MASK + i);
}
mutex_init(&wm8350->irq_lock);
wm8350->chip_irq = irq;
if (pdata && pdata->irq_base > 0)
irq_base = pdata->irq_base;
wm8350->irq_base = irq_alloc_descs(irq_base, 0, ARRAY_SIZE(wm8350_irqs), 0);
if (wm8350->irq_base < 0) {
dev_warn(wm8350->dev, "Allocating irqs failed with %d\n",
wm8350->irq_base);
return 0;
}
if (pdata && pdata->irq_high) {
flags |= IRQF_TRIGGER_HIGH;
wm8350_set_bits(wm8350, WM8350_SYSTEM_CONTROL_1,
WM8350_IRQ_POL);
} else {
flags |= IRQF_TRIGGER_LOW;
wm8350_clear_bits(wm8350, WM8350_SYSTEM_CONTROL_1,
WM8350_IRQ_POL);
}
for (cur_irq = wm8350->irq_base;
cur_irq < ARRAY_SIZE(wm8350_irqs) + wm8350->irq_base;
cur_irq++) {
irq_set_chip_data(cur_irq, wm8350);
irq_set_chip_and_handler(cur_irq, &wm8350_irq_chip,
handle_edge_irq);
irq_set_nested_thread(cur_irq, 1);
#ifdef CONFIG_ARM
set_irq_flags(cur_irq, IRQF_VALID);
#else
irq_set_noprobe(cur_irq);
#endif
}
ret = request_threaded_irq(irq, NULL, wm8350_irq, flags,
"wm8350", wm8350);
if (ret != 0)
dev_err(wm8350->dev, "Failed to request IRQ: %d\n", ret);
wm8350_reg_write(wm8350, WM8350_SYSTEM_INTERRUPTS_MASK, 0);
return ret;
}
int wm8350_irq_exit(struct wm8350 *wm8350)
{
free_irq(wm8350->chip_irq, wm8350);
return 0;
}
