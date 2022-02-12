void mctrl_gpio_set(struct mctrl_gpios *gpios, unsigned int mctrl)
{
enum mctrl_gpio_idx i;
struct gpio_desc *desc_array[UART_GPIO_MAX];
int value_array[UART_GPIO_MAX];
unsigned int count = 0;
if (IS_ERR_OR_NULL(gpios))
return;
for (i = 0; i < UART_GPIO_MAX; i++)
if (!IS_ERR_OR_NULL(gpios->gpio[i]) &&
mctrl_gpios_desc[i].dir_out) {
desc_array[count] = gpios->gpio[i];
value_array[count] = !!(mctrl & mctrl_gpios_desc[i].mctrl);
count++;
}
gpiod_set_array(count, desc_array, value_array);
}
struct gpio_desc *mctrl_gpio_to_gpiod(struct mctrl_gpios *gpios,
enum mctrl_gpio_idx gidx)
{
if (!IS_ERR_OR_NULL(gpios) && !IS_ERR_OR_NULL(gpios->gpio[gidx]))
return gpios->gpio[gidx];
else
return NULL;
}
unsigned int mctrl_gpio_get(struct mctrl_gpios *gpios, unsigned int *mctrl)
{
enum mctrl_gpio_idx i;
if (IS_ERR_OR_NULL(gpios))
return *mctrl;
for (i = 0; i < UART_GPIO_MAX; i++) {
if (!IS_ERR_OR_NULL(gpios->gpio[i]) &&
!mctrl_gpios_desc[i].dir_out) {
if (gpiod_get_value(gpios->gpio[i]))
*mctrl |= mctrl_gpios_desc[i].mctrl;
else
*mctrl &= ~mctrl_gpios_desc[i].mctrl;
}
}
return *mctrl;
}
struct mctrl_gpios *mctrl_gpio_init(struct device *dev, unsigned int idx)
{
struct mctrl_gpios *gpios;
enum mctrl_gpio_idx i;
int err;
gpios = devm_kzalloc(dev, sizeof(*gpios), GFP_KERNEL);
if (!gpios)
return ERR_PTR(-ENOMEM);
for (i = 0; i < UART_GPIO_MAX; i++) {
gpios->gpio[i] = devm_gpiod_get_index(dev,
mctrl_gpios_desc[i].name,
idx);
if (IS_ERR_OR_NULL(gpios->gpio[i]))
continue;
if (mctrl_gpios_desc[i].dir_out)
err = gpiod_direction_output(gpios->gpio[i], 0);
else
err = gpiod_direction_input(gpios->gpio[i]);
if (err) {
dev_dbg(dev, "Unable to set direction for %s GPIO",
mctrl_gpios_desc[i].name);
devm_gpiod_put(dev, gpios->gpio[i]);
gpios->gpio[i] = NULL;
}
}
return gpios;
}
void mctrl_gpio_free(struct device *dev, struct mctrl_gpios *gpios)
{
enum mctrl_gpio_idx i;
if (IS_ERR_OR_NULL(gpios))
return;
for (i = 0; i < UART_GPIO_MAX; i++)
if (!IS_ERR_OR_NULL(gpios->gpio[i]))
devm_gpiod_put(dev, gpios->gpio[i]);
devm_kfree(dev, gpios);
}
