static inline int irq_data_to_status_reg(struct wm831x_irq_data *irq_data)
{
return WM831X_INTERRUPT_STATUS_1 - 1 + irq_data->reg;
}
static inline struct wm831x_irq_data *irq_to_wm831x_irq(struct wm831x *wm831x,
int irq)
{
return &wm831x_irqs[irq - wm831x->irq_base];
}
static void wm831x_irq_lock(struct irq_data *data)
{
struct wm831x *wm831x = irq_data_get_irq_chip_data(data);
mutex_lock(&wm831x->irq_lock);
}
static void wm831x_irq_sync_unlock(struct irq_data *data)
{
struct wm831x *wm831x = irq_data_get_irq_chip_data(data);
int i;
for (i = 0; i < ARRAY_SIZE(wm831x->gpio_update); i++) {
if (wm831x->gpio_update[i]) {
wm831x_set_bits(wm831x, WM831X_GPIO1_CONTROL + i,
WM831X_GPN_INT_MODE | WM831X_GPN_POL,
wm831x->gpio_update[i]);
wm831x->gpio_update[i] = 0;
}
}
for (i = 0; i < ARRAY_SIZE(wm831x->irq_masks_cur); i++) {
if (wm831x->irq_masks_cur[i] != wm831x->irq_masks_cache[i]) {
dev_dbg(wm831x->dev, "IRQ mask sync: %x = %x\n",
WM831X_INTERRUPT_STATUS_1_MASK + i,
wm831x->irq_masks_cur[i]);
wm831x->irq_masks_cache[i] = wm831x->irq_masks_cur[i];
wm831x_reg_write(wm831x,
WM831X_INTERRUPT_STATUS_1_MASK + i,
wm831x->irq_masks_cur[i]);
}
}
mutex_unlock(&wm831x->irq_lock);
}
static void wm831x_irq_enable(struct irq_data *data)
{
struct wm831x *wm831x = irq_data_get_irq_chip_data(data);
struct wm831x_irq_data *irq_data = irq_to_wm831x_irq(wm831x,
data->irq);
wm831x->irq_masks_cur[irq_data->reg - 1] &= ~irq_data->mask;
}
static void wm831x_irq_disable(struct irq_data *data)
{
struct wm831x *wm831x = irq_data_get_irq_chip_data(data);
struct wm831x_irq_data *irq_data = irq_to_wm831x_irq(wm831x,
data->irq);
wm831x->irq_masks_cur[irq_data->reg - 1] |= irq_data->mask;
}
static int wm831x_irq_set_type(struct irq_data *data, unsigned int type)
{
struct wm831x *wm831x = irq_data_get_irq_chip_data(data);
int irq;
irq = data->irq - wm831x->irq_base;
if (irq < WM831X_IRQ_GPIO_1 || irq > WM831X_IRQ_GPIO_11) {
if (irq >= 0 && irq < WM831X_NUM_IRQS)
return 0;
else
return -EINVAL;
}
irq -= WM831X_IRQ_GPIO_1;
switch (type) {
case IRQ_TYPE_EDGE_BOTH:
wm831x->gpio_update[irq] = 0x10000 | WM831X_GPN_INT_MODE;
wm831x->gpio_level[irq] = false;
break;
case IRQ_TYPE_EDGE_RISING:
wm831x->gpio_update[irq] = 0x10000 | WM831X_GPN_POL;
wm831x->gpio_level[irq] = false;
break;
case IRQ_TYPE_EDGE_FALLING:
wm831x->gpio_update[irq] = 0x10000;
wm831x->gpio_level[irq] = false;
break;
case IRQ_TYPE_LEVEL_HIGH:
wm831x->gpio_update[irq] = 0x10000 | WM831X_GPN_POL;
wm831x->gpio_level[irq] = true;
break;
default:
return -EINVAL;
}
return 0;
}
static irqreturn_t wm831x_irq_thread(int irq, void *data)
{
struct wm831x *wm831x = data;
unsigned int i;
int primary, status_addr, ret;
int status_regs[WM831X_NUM_IRQ_REGS] = { 0 };
int read[WM831X_NUM_IRQ_REGS] = { 0 };
int *status;
primary = wm831x_reg_read(wm831x, WM831X_SYSTEM_INTERRUPTS);
if (primary < 0) {
dev_err(wm831x->dev, "Failed to read system interrupt: %d\n",
primary);
goto out;
}
if (primary & WM831X_TCHPD_INT)
handle_nested_irq(wm831x->irq_base + WM831X_IRQ_TCHPD);
if (primary & WM831X_TCHDATA_INT)
handle_nested_irq(wm831x->irq_base + WM831X_IRQ_TCHDATA);
primary &= ~(WM831X_TCHDATA_EINT | WM831X_TCHPD_EINT);
for (i = 0; i < ARRAY_SIZE(wm831x_irqs); i++) {
int offset = wm831x_irqs[i].reg - 1;
if (!(primary & wm831x_irqs[i].primary))
continue;
status = &status_regs[offset];
if (!read[offset]) {
status_addr = irq_data_to_status_reg(&wm831x_irqs[i]);
*status = wm831x_reg_read(wm831x, status_addr);
if (*status < 0) {
dev_err(wm831x->dev,
"Failed to read IRQ status: %d\n",
*status);
goto out;
}
read[offset] = 1;
*status &= ~wm831x->irq_masks_cur[offset];
wm831x_reg_write(wm831x, status_addr, *status);
}
if (*status & wm831x_irqs[i].mask)
handle_nested_irq(wm831x->irq_base + i);
if (primary == WM831X_GP_INT &&
wm831x->gpio_level[i - WM831X_IRQ_GPIO_1]) {
ret = wm831x_reg_read(wm831x, WM831X_GPIO_LEVEL);
while (ret & 1 << (i - WM831X_IRQ_GPIO_1)) {
handle_nested_irq(wm831x->irq_base + i);
ret = wm831x_reg_read(wm831x,
WM831X_GPIO_LEVEL);
}
}
}
out:
return IRQ_HANDLED;
}
int wm831x_irq_init(struct wm831x *wm831x, int irq)
{
struct wm831x_pdata *pdata = wm831x->dev->platform_data;
int i, cur_irq, ret;
mutex_init(&wm831x->irq_lock);
for (i = 0; i < ARRAY_SIZE(wm831x->irq_masks_cur); i++) {
wm831x->irq_masks_cur[i] = 0xffff;
wm831x->irq_masks_cache[i] = 0xffff;
wm831x_reg_write(wm831x, WM831X_INTERRUPT_STATUS_1_MASK + i,
0xffff);
}
if (!pdata || !pdata->irq_base)
wm831x->irq_base = -1;
else
wm831x->irq_base = pdata->irq_base;
wm831x->irq_base = irq_alloc_descs(wm831x->irq_base, 0,
WM831X_NUM_IRQS, 0);
if (wm831x->irq_base < 0) {
dev_warn(wm831x->dev, "Failed to allocate IRQs: %d\n",
wm831x->irq_base);
wm831x->irq_base = 0;
return 0;
}
if (pdata && pdata->irq_cmos)
i = 0;
else
i = WM831X_IRQ_OD;
wm831x_set_bits(wm831x, WM831X_IRQ_CONFIG,
WM831X_IRQ_OD, i);
ret = enable_irq_wake(irq);
if (ret != 0) {
dev_warn(wm831x->dev, "Can't enable IRQ as wake source: %d\n",
ret);
}
wm831x->irq = irq;
for (cur_irq = wm831x->irq_base;
cur_irq < ARRAY_SIZE(wm831x_irqs) + wm831x->irq_base;
cur_irq++) {
irq_set_chip_data(cur_irq, wm831x);
irq_set_chip_and_handler(cur_irq, &wm831x_irq_chip,
handle_edge_irq);
irq_set_nested_thread(cur_irq, 1);
#ifdef CONFIG_ARM
set_irq_flags(cur_irq, IRQF_VALID);
#else
irq_set_noprobe(cur_irq);
#endif
}
if (irq) {
ret = request_threaded_irq(irq, NULL, wm831x_irq_thread,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
"wm831x", wm831x);
if (ret != 0) {
dev_err(wm831x->dev, "Failed to request IRQ %d: %d\n",
irq, ret);
return ret;
}
} else {
dev_warn(wm831x->dev,
"No interrupt specified - functionality limited\n");
}
wm831x_reg_write(wm831x, WM831X_SYSTEM_INTERRUPTS_MASK, 0);
return 0;
}
void wm831x_irq_exit(struct wm831x *wm831x)
{
if (wm831x->irq)
free_irq(wm831x->irq, wm831x);
}
