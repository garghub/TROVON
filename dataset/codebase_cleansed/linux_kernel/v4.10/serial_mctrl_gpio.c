void mctrl_gpio_set(struct mctrl_gpios *gpios, unsigned int mctrl)
{
enum mctrl_gpio_idx i;
struct gpio_desc *desc_array[UART_GPIO_MAX];
int value_array[UART_GPIO_MAX];
unsigned int count = 0;
if (gpios == NULL)
return;
for (i = 0; i < UART_GPIO_MAX; i++)
if (gpios->gpio[i] && mctrl_gpios_desc[i].dir_out) {
desc_array[count] = gpios->gpio[i];
value_array[count] = !!(mctrl & mctrl_gpios_desc[i].mctrl);
count++;
}
gpiod_set_array_value(count, desc_array, value_array);
}
struct gpio_desc *mctrl_gpio_to_gpiod(struct mctrl_gpios *gpios,
enum mctrl_gpio_idx gidx)
{
return gpios->gpio[gidx];
}
unsigned int mctrl_gpio_get(struct mctrl_gpios *gpios, unsigned int *mctrl)
{
enum mctrl_gpio_idx i;
if (gpios == NULL)
return *mctrl;
for (i = 0; i < UART_GPIO_MAX; i++) {
if (gpios->gpio[i] && !mctrl_gpios_desc[i].dir_out) {
if (gpiod_get_value(gpios->gpio[i]))
*mctrl |= mctrl_gpios_desc[i].mctrl;
else
*mctrl &= ~mctrl_gpios_desc[i].mctrl;
}
}
return *mctrl;
}
unsigned int
mctrl_gpio_get_outputs(struct mctrl_gpios *gpios, unsigned int *mctrl)
{
enum mctrl_gpio_idx i;
if (gpios == NULL)
return *mctrl;
for (i = 0; i < UART_GPIO_MAX; i++) {
if (gpios->gpio[i] && mctrl_gpios_desc[i].dir_out) {
if (gpiod_get_value(gpios->gpio[i]))
*mctrl |= mctrl_gpios_desc[i].mctrl;
else
*mctrl &= ~mctrl_gpios_desc[i].mctrl;
}
}
return *mctrl;
}
struct mctrl_gpios *mctrl_gpio_init_noauto(struct device *dev, unsigned int idx)
{
struct mctrl_gpios *gpios;
enum mctrl_gpio_idx i;
gpios = devm_kzalloc(dev, sizeof(*gpios), GFP_KERNEL);
if (!gpios)
return ERR_PTR(-ENOMEM);
for (i = 0; i < UART_GPIO_MAX; i++) {
enum gpiod_flags flags;
if (mctrl_gpios_desc[i].dir_out)
flags = GPIOD_OUT_LOW;
else
flags = GPIOD_IN;
gpios->gpio[i] =
devm_gpiod_get_index_optional(dev,
mctrl_gpios_desc[i].name,
idx, flags);
if (IS_ERR(gpios->gpio[i]))
return ERR_CAST(gpios->gpio[i]);
}
return gpios;
}
static irqreturn_t mctrl_gpio_irq_handle(int irq, void *context)
{
struct mctrl_gpios *gpios = context;
struct uart_port *port = gpios->port;
u32 mctrl = gpios->mctrl_prev;
u32 mctrl_diff;
unsigned long flags;
mctrl_gpio_get(gpios, &mctrl);
spin_lock_irqsave(&port->lock, flags);
mctrl_diff = mctrl ^ gpios->mctrl_prev;
gpios->mctrl_prev = mctrl;
if (mctrl_diff & MCTRL_ANY_DELTA && port->state != NULL) {
if ((mctrl_diff & mctrl) & TIOCM_RI)
port->icount.rng++;
if ((mctrl_diff & mctrl) & TIOCM_DSR)
port->icount.dsr++;
if (mctrl_diff & TIOCM_CD)
uart_handle_dcd_change(port, mctrl & TIOCM_CD);
if (mctrl_diff & TIOCM_CTS)
uart_handle_cts_change(port, mctrl & TIOCM_CTS);
wake_up_interruptible(&port->state->port.delta_msr_wait);
}
spin_unlock_irqrestore(&port->lock, flags);
return IRQ_HANDLED;
}
struct mctrl_gpios *mctrl_gpio_init(struct uart_port *port, unsigned int idx)
{
struct mctrl_gpios *gpios;
enum mctrl_gpio_idx i;
gpios = mctrl_gpio_init_noauto(port->dev, idx);
if (IS_ERR(gpios))
return gpios;
gpios->port = port;
for (i = 0; i < UART_GPIO_MAX; ++i) {
int ret;
if (!gpios->gpio[i] || mctrl_gpios_desc[i].dir_out)
continue;
ret = gpiod_to_irq(gpios->gpio[i]);
if (ret <= 0) {
dev_err(port->dev,
"failed to find corresponding irq for %s (idx=%d, err=%d)\n",
mctrl_gpios_desc[i].name, idx, ret);
return ERR_PTR(ret);
}
gpios->irq[i] = ret;
irq_set_status_flags(gpios->irq[i], IRQ_NOAUTOEN);
ret = devm_request_irq(port->dev, gpios->irq[i],
mctrl_gpio_irq_handle,
IRQ_TYPE_EDGE_BOTH, dev_name(port->dev),
gpios);
if (ret) {
dev_err(port->dev,
"failed to request irq for %s (idx=%d, err=%d)\n",
mctrl_gpios_desc[i].name, idx, ret);
return ERR_PTR(ret);
}
}
return gpios;
}
void mctrl_gpio_free(struct device *dev, struct mctrl_gpios *gpios)
{
enum mctrl_gpio_idx i;
if (gpios == NULL)
return;
for (i = 0; i < UART_GPIO_MAX; i++) {
if (gpios->irq[i])
devm_free_irq(gpios->port->dev, gpios->irq[i], gpios);
if (gpios->gpio[i])
devm_gpiod_put(dev, gpios->gpio[i]);
}
devm_kfree(dev, gpios);
}
void mctrl_gpio_enable_ms(struct mctrl_gpios *gpios)
{
enum mctrl_gpio_idx i;
if (gpios == NULL)
return;
if (gpios->mctrl_on)
return;
gpios->mctrl_on = true;
mctrl_gpio_get(gpios, &gpios->mctrl_prev);
for (i = 0; i < UART_GPIO_MAX; ++i) {
if (!gpios->irq[i])
continue;
enable_irq(gpios->irq[i]);
}
}
void mctrl_gpio_disable_ms(struct mctrl_gpios *gpios)
{
enum mctrl_gpio_idx i;
if (gpios == NULL)
return;
if (!gpios->mctrl_on)
return;
gpios->mctrl_on = false;
for (i = 0; i < UART_GPIO_MAX; ++i) {
if (!gpios->irq[i])
continue;
disable_irq(gpios->irq[i]);
}
}
