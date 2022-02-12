int gpio_register_callback(unsigned gpio, int (*func)(void *arg), void *data)
{
if (gpio_pin[gpio].callback)
dev_warn(gpiodev, "%s: WARNING: callback already "
"registered for gpio pin#%d\n", __func__, gpio);
gpio_pin[gpio].callback = func;
gpio_pin[gpio].data = data;
return 0;
}
int gpio_unregister_callback(unsigned gpio)
{
if (!gpio_pin[gpio].callback)
dev_warn(gpiodev, "%s: WARNING: callback already "
"unregistered for gpio pin#%d\n", __func__, gpio);
gpio_pin[gpio].callback = NULL;
gpio_pin[gpio].data = NULL;
return 0;
}
int gpio_is_valid(int number)
{
if (number >= 0 &&
number < (U300_GPIO_NUM_PORTS * U300_GPIO_PINS_PER_PORT))
return 1;
return 0;
}
int gpio_request(unsigned gpio, const char *label)
{
if (gpio_pin[gpio].users)
return -EINVAL;
else
gpio_pin[gpio].users++;
gpio_users++;
return 0;
}
void gpio_free(unsigned gpio)
{
gpio_users--;
gpio_pin[gpio].users--;
if (unlikely(gpio_pin[gpio].users < 0)) {
dev_warn(gpiodev, "warning: gpio#%d release mismatch\n",
gpio);
gpio_pin[gpio].users = 0;
}
return;
}
int gpio_get_value(unsigned gpio)
{
return readl(virtbase + U300_GPIO_PXPDIR +
PIN_TO_PORT(gpio) * U300_GPIO_PORTX_SPACING) & (1 << (gpio & 0x07));
}
void gpio_set_value(unsigned gpio, int value)
{
u32 val;
unsigned long flags;
local_irq_save(flags);
if (value) {
val = readl(virtbase + U300_GPIO_PXPDOR +
PIN_TO_PORT(gpio) * U300_GPIO_PORTX_SPACING)
& (1 << (gpio & 0x07));
writel(val | (1 << (gpio & 0x07)), virtbase +
U300_GPIO_PXPDOR +
PIN_TO_PORT(gpio) * U300_GPIO_PORTX_SPACING);
} else {
val = readl(virtbase + U300_GPIO_PXPDOR +
PIN_TO_PORT(gpio) * U300_GPIO_PORTX_SPACING)
& (1 << (gpio & 0x07));
writel(val & ~(1 << (gpio & 0x07)), virtbase +
U300_GPIO_PXPDOR +
PIN_TO_PORT(gpio) * U300_GPIO_PORTX_SPACING);
}
local_irq_restore(flags);
}
int gpio_direction_input(unsigned gpio)
{
unsigned long flags;
u32 val;
if (gpio > U300_GPIO_MAX)
return -EINVAL;
local_irq_save(flags);
val = readl(virtbase + U300_GPIO_PXPCR + PIN_TO_PORT(gpio) *
U300_GPIO_PORTX_SPACING);
val &= ~(U300_GPIO_PXPCR_PIN_MODE_MASK << ((gpio & 0x07) << 1));
writel(val, virtbase + U300_GPIO_PXPCR + PIN_TO_PORT(gpio) *
U300_GPIO_PORTX_SPACING);
local_irq_restore(flags);
return 0;
}
int gpio_direction_output(unsigned gpio, int value)
{
unsigned long flags;
u32 val;
if (gpio > U300_GPIO_MAX)
return -EINVAL;
local_irq_save(flags);
val = readl(virtbase + U300_GPIO_PXPCR + PIN_TO_PORT(gpio) *
U300_GPIO_PORTX_SPACING);
val &= ~(U300_GPIO_PXPCR_PIN_MODE_MASK << ((gpio & 0x07) << 1));
val |= (U300_GPIO_PXPCR_PIN_MODE_OUTPUT_PUSH_PULL
<< ((gpio & 0x07) << 1));
writel(val, virtbase + U300_GPIO_PXPCR + PIN_TO_PORT(gpio) *
U300_GPIO_PORTX_SPACING);
gpio_set_value(gpio, value);
local_irq_restore(flags);
return 0;
}
void enable_irq_on_gpio_pin(unsigned gpio, int edge)
{
u32 val;
unsigned long flags;
local_irq_save(flags);
val = readl(virtbase + U300_GPIO_PXIEN + PIN_TO_PORT(gpio) *
U300_GPIO_PORTX_SPACING);
val |= (1 << (gpio & 0x07));
writel(val, virtbase + U300_GPIO_PXIEN + PIN_TO_PORT(gpio) *
U300_GPIO_PORTX_SPACING);
val = readl(virtbase + U300_GPIO_PXICR + PIN_TO_PORT(gpio) *
U300_GPIO_PORTX_SPACING);
if (edge)
val |= (1 << (gpio & 0x07));
else
val &= ~(1 << (gpio & 0x07));
writel(val, virtbase + U300_GPIO_PXICR + PIN_TO_PORT(gpio) *
U300_GPIO_PORTX_SPACING);
local_irq_restore(flags);
}
void disable_irq_on_gpio_pin(unsigned gpio)
{
u32 val;
unsigned long flags;
local_irq_save(flags);
val = readl(virtbase + U300_GPIO_PXIEN + PIN_TO_PORT(gpio) *
U300_GPIO_PORTX_SPACING);
val &= ~(1 << (gpio & 0x07));
writel(val, virtbase + U300_GPIO_PXIEN + PIN_TO_PORT(gpio) *
U300_GPIO_PORTX_SPACING);
local_irq_restore(flags);
}
void gpio_pullup(unsigned gpio, int value)
{
u32 val;
unsigned long flags;
local_irq_save(flags);
if (value) {
val = readl(virtbase + U300_GPIO_PXPER + PIN_TO_PORT(gpio) *
U300_GPIO_PORTX_SPACING);
writel(val | (1 << (gpio & 0x07)), virtbase + U300_GPIO_PXPER +
PIN_TO_PORT(gpio) * U300_GPIO_PORTX_SPACING);
} else {
val = readl(virtbase + U300_GPIO_PXPER + PIN_TO_PORT(gpio) *
U300_GPIO_PORTX_SPACING);
writel(val & ~(1 << (gpio & 0x07)), virtbase + U300_GPIO_PXPER +
PIN_TO_PORT(gpio) * U300_GPIO_PORTX_SPACING);
}
local_irq_restore(flags);
}
static irqreturn_t gpio_irq_handler(int irq, void *dev_id)
{
struct u300_gpio_port *port = dev_id;
u32 val;
int pin;
val = readl(virtbase + U300_GPIO_PXIEV + port->number *
U300_GPIO_PORTX_SPACING);
val &= readl(virtbase + U300_GPIO_PXIEV + port->number *
U300_GPIO_PORTX_SPACING);
val &= U300_GPIO_PXIEV_ALL_IRQ_EVENT_MASK;
writel(val, virtbase + U300_GPIO_PXIEV + port->number *
U300_GPIO_PORTX_SPACING);
while (val != 0) {
unsigned gpio;
pin = __ffs(val);
val &= ~(1 << pin);
gpio = (port->number << 3) + pin;
if (gpio_pin[gpio].callback)
(void)gpio_pin[gpio].callback(gpio_pin[gpio].data);
else
dev_dbg(gpiodev, "stray GPIO IRQ on line %d\n",
gpio);
}
return IRQ_HANDLED;
}
static void gpio_set_initial_values(void)
{
#ifdef U300_COH901571_3
int i, j;
unsigned long flags;
u32 val;
for (i = 0; i < U300_GPIO_NUM_PORTS; i++) {
val = 0;
for (j = 0; j < 8; j++)
val |= (u32) (u300_gpio_config[i][j].default_output_value != DEFAULT_OUTPUT_LOW) << j;
local_irq_save(flags);
writel(val, virtbase + U300_GPIO_PXPDOR + i * U300_GPIO_PORTX_SPACING);
local_irq_restore(flags);
}
for (i = 0; i < U300_GPIO_NUM_PORTS; i++) {
for (j = 0; j < U300_GPIO_PINS_PER_PORT; j++) {
local_irq_save(flags);
val = readl(virtbase + U300_GPIO_PXPCR +
i * U300_GPIO_PORTX_SPACING);
val &= ~(U300_GPIO_PXPCR_PIN_MODE_MASK << (j << 1));
if (u300_gpio_config[i][j].pin_usage != GPIO_IN)
val |= (U300_GPIO_PXPCR_PIN_MODE_OUTPUT_PUSH_PULL << (j << 1));
writel(val, virtbase + U300_GPIO_PXPCR +
i * U300_GPIO_PORTX_SPACING);
local_irq_restore(flags);
}
}
for (i = 0; i < U300_GPIO_MAX; i++) {
val = 0;
for (j = 0; j < 8; j++)
val |= (u32)((u300_gpio_config[i][j].pull_up == DISABLE_PULL_UP) << j);
local_irq_save(flags);
writel(val, virtbase + U300_GPIO_PXPER + i * U300_GPIO_PORTX_SPACING);
local_irq_restore(flags);
}
#endif
}
static int __init gpio_probe(struct platform_device *pdev)
{
u32 val;
int err = 0;
int i;
int num_irqs;
gpiodev = &pdev->dev;
memset(gpio_pin, 0, sizeof(gpio_pin));
clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(clk)) {
err = PTR_ERR(clk);
dev_err(gpiodev, "could not get GPIO clock\n");
goto err_no_clk;
}
err = clk_enable(clk);
if (err) {
dev_err(gpiodev, "could not enable GPIO clock\n");
goto err_no_clk_enable;
}
memres = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!memres)
goto err_no_resource;
if (!request_mem_region(memres->start, resource_size(memres),
"GPIO Controller")) {
err = -ENODEV;
goto err_no_ioregion;
}
virtbase = ioremap(memres->start, resource_size(memres));
if (!virtbase) {
err = -ENOMEM;
goto err_no_ioremap;
}
dev_info(gpiodev, "remapped 0x%08x to %p\n",
memres->start, virtbase);
#ifdef U300_COH901335
dev_info(gpiodev, "initializing GPIO Controller COH 901 335\n");
writel(U300_GPIO_CR_BLOCK_CLOCK_ENABLE, virtbase + U300_GPIO_CR);
#endif
#ifdef U300_COH901571_3
dev_info(gpiodev, "initializing GPIO Controller COH 901 571/3\n");
val = readl(virtbase + U300_GPIO_CR);
dev_info(gpiodev, "COH901571/3 block version: %d, " \
"number of cores: %d\n",
((val & 0x0000FE00) >> 9),
((val & 0x000001FC) >> 2));
writel(U300_GPIO_CR_BLOCK_CLKRQ_ENABLE, virtbase + U300_GPIO_CR);
#endif
gpio_set_initial_values();
for (num_irqs = 0 ; num_irqs < U300_GPIO_NUM_PORTS; num_irqs++) {
gpio_ports[num_irqs].irq =
platform_get_irq_byname(pdev,
gpio_ports[num_irqs].name);
err = request_irq(gpio_ports[num_irqs].irq,
gpio_irq_handler, IRQF_DISABLED,
gpio_ports[num_irqs].name,
&gpio_ports[num_irqs]);
if (err) {
dev_err(gpiodev, "cannot allocate IRQ for %s!\n",
gpio_ports[num_irqs].name);
goto err_no_irq;
}
writel(0x0, virtbase + U300_GPIO_PXIFR +
num_irqs * U300_GPIO_PORTX_SPACING);
}
return 0;
err_no_irq:
for (i = 0; i < num_irqs; i++)
free_irq(gpio_ports[i].irq, &gpio_ports[i]);
iounmap(virtbase);
err_no_ioremap:
release_mem_region(memres->start, resource_size(memres));
err_no_ioregion:
err_no_resource:
clk_disable(clk);
err_no_clk_enable:
clk_put(clk);
err_no_clk:
dev_info(gpiodev, "module ERROR:%d\n", err);
return err;
}
static int __exit gpio_remove(struct platform_device *pdev)
{
int i;
writel(0x00000000U, virtbase + U300_GPIO_CR);
for (i = 0 ; i < U300_GPIO_NUM_PORTS; i++)
free_irq(gpio_ports[i].irq, &gpio_ports[i]);
iounmap(virtbase);
release_mem_region(memres->start, resource_size(memres));
clk_disable(clk);
clk_put(clk);
return 0;
}
static int __init u300_gpio_init(void)
{
return platform_driver_probe(&gpio_driver, gpio_probe);
}
static void __exit u300_gpio_exit(void)
{
platform_driver_unregister(&gpio_driver);
}
