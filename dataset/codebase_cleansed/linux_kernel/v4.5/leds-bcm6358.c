static void bcm6358_led_write(void __iomem *reg, unsigned long data)
{
#ifdef CONFIG_CPU_BIG_ENDIAN
iowrite32be(data, reg);
#else
writel(data, reg);
#endif
}
static unsigned long bcm6358_led_read(void __iomem *reg)
{
#ifdef CONFIG_CPU_BIG_ENDIAN
return ioread32be(reg);
#else
return readl(reg);
#endif
}
static unsigned long bcm6358_led_busy(void __iomem *mem)
{
unsigned long val;
while ((val = bcm6358_led_read(mem + BCM6358_REG_CTRL)) &
BCM6358_SLED_BUSY)
udelay(BCM6358_SLED_WAIT);
return val;
}
static void bcm6358_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct bcm6358_led *led =
container_of(led_cdev, struct bcm6358_led, cdev);
unsigned long flags, val;
spin_lock_irqsave(led->lock, flags);
bcm6358_led_busy(led->mem);
val = bcm6358_led_read(led->mem + BCM6358_REG_MODE);
if ((led->active_low && value == LED_OFF) ||
(!led->active_low && value != LED_OFF))
val |= BIT(led->pin);
else
val &= ~(BIT(led->pin));
bcm6358_led_write(led->mem + BCM6358_REG_MODE, val);
spin_unlock_irqrestore(led->lock, flags);
}
static int bcm6358_led(struct device *dev, struct device_node *nc, u32 reg,
void __iomem *mem, spinlock_t *lock)
{
struct bcm6358_led *led;
const char *state;
int rc;
led = devm_kzalloc(dev, sizeof(*led), GFP_KERNEL);
if (!led)
return -ENOMEM;
led->pin = reg;
led->mem = mem;
led->lock = lock;
if (of_property_read_bool(nc, "active-low"))
led->active_low = true;
led->cdev.name = of_get_property(nc, "label", NULL) ? : nc->name;
led->cdev.default_trigger = of_get_property(nc,
"linux,default-trigger",
NULL);
if (!of_property_read_string(nc, "default-state", &state)) {
if (!strcmp(state, "on")) {
led->cdev.brightness = LED_FULL;
} else if (!strcmp(state, "keep")) {
unsigned long val;
val = bcm6358_led_read(led->mem + BCM6358_REG_MODE);
val &= BIT(led->pin);
if ((led->active_low && !val) ||
(!led->active_low && val))
led->cdev.brightness = LED_FULL;
else
led->cdev.brightness = LED_OFF;
} else {
led->cdev.brightness = LED_OFF;
}
} else {
led->cdev.brightness = LED_OFF;
}
bcm6358_led_set(&led->cdev, led->cdev.brightness);
led->cdev.brightness_set = bcm6358_led_set;
rc = led_classdev_register(dev, &led->cdev);
if (rc < 0)
return rc;
dev_dbg(dev, "registered LED %s\n", led->cdev.name);
return 0;
}
static int bcm6358_leds_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = pdev->dev.of_node;
struct device_node *child;
struct resource *mem_r;
void __iomem *mem;
spinlock_t *lock;
unsigned long val;
u32 clk_div;
mem_r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem_r)
return -EINVAL;
mem = devm_ioremap_resource(dev, mem_r);
if (IS_ERR(mem))
return PTR_ERR(mem);
lock = devm_kzalloc(dev, sizeof(*lock), GFP_KERNEL);
if (!lock)
return -ENOMEM;
spin_lock_init(lock);
val = bcm6358_led_busy(mem);
val &= ~(BCM6358_SLED_POLARITY | BCM6358_SLED_CLKDIV_MASK);
if (of_property_read_bool(np, "brcm,clk-dat-low"))
val |= BCM6358_SLED_POLARITY;
of_property_read_u32(np, "brcm,clk-div", &clk_div);
switch (clk_div) {
case 8:
val |= BCM6358_SLED_CLKDIV_8;
break;
case 4:
val |= BCM6358_SLED_CLKDIV_4;
break;
case 2:
val |= BCM6358_SLED_CLKDIV_2;
break;
default:
val |= BCM6358_SLED_CLKDIV_1;
break;
}
bcm6358_led_write(mem + BCM6358_REG_CTRL, val);
for_each_available_child_of_node(np, child) {
int rc;
u32 reg;
if (of_property_read_u32(child, "reg", &reg))
continue;
if (reg >= BCM6358_SLED_MAX_COUNT) {
dev_err(dev, "invalid LED (%u >= %d)\n", reg,
BCM6358_SLED_MAX_COUNT);
continue;
}
rc = bcm6358_led(dev, child, reg, mem, lock);
if (rc < 0) {
of_node_put(child);
return rc;
}
}
return 0;
}
