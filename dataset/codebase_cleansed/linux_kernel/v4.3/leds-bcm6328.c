static void bcm6328_led_write(void __iomem *reg, unsigned long data)
{
iowrite32be(data, reg);
}
static unsigned long bcm6328_led_read(void __iomem *reg)
{
return ioread32be(reg);
}
static unsigned long bcm6328_pin2shift(unsigned long pin)
{
if (pin < 8)
return pin + 16;
else
return pin - 8;
}
static void bcm6328_led_mode(struct bcm6328_led *led, unsigned long value)
{
void __iomem *mode;
unsigned long val, shift;
shift = bcm6328_pin2shift(led->pin);
if (shift / 16)
mode = led->mem + BCM6328_REG_MODE_HI;
else
mode = led->mem + BCM6328_REG_MODE_LO;
val = bcm6328_led_read(mode);
val &= ~(BCM6328_LED_MODE_MASK << BCM6328_LED_SHIFT(shift % 16));
val |= (value << BCM6328_LED_SHIFT(shift % 16));
bcm6328_led_write(mode, val);
}
static void bcm6328_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct bcm6328_led *led =
container_of(led_cdev, struct bcm6328_led, cdev);
unsigned long flags;
spin_lock_irqsave(led->lock, flags);
*(led->blink_leds) &= ~BIT(led->pin);
if ((led->active_low && value == LED_OFF) ||
(!led->active_low && value != LED_OFF))
bcm6328_led_mode(led, BCM6328_LED_MODE_OFF);
else
bcm6328_led_mode(led, BCM6328_LED_MODE_ON);
spin_unlock_irqrestore(led->lock, flags);
}
static int bcm6328_blink_set(struct led_classdev *led_cdev,
unsigned long *delay_on, unsigned long *delay_off)
{
struct bcm6328_led *led =
container_of(led_cdev, struct bcm6328_led, cdev);
unsigned long delay, flags;
if (!*delay_on)
*delay_on = BCM6328_LED_DEF_DELAY;
if (!*delay_off)
*delay_off = BCM6328_LED_DEF_DELAY;
if (*delay_on != *delay_off) {
dev_dbg(led_cdev->dev,
"fallback to soft blinking (delay_on != delay_off)\n");
return -EINVAL;
}
delay = *delay_on / BCM6328_LED_INTERVAL_MS;
if (delay == 0)
delay = 1;
else if (delay > BCM6328_LED_INTV_MASK) {
dev_dbg(led_cdev->dev,
"fallback to soft blinking (delay > %ums)\n",
BCM6328_LED_INTV_MASK * BCM6328_LED_INTERVAL_MS);
return -EINVAL;
}
spin_lock_irqsave(led->lock, flags);
if (*(led->blink_leds) == 0 ||
*(led->blink_leds) == BIT(led->pin) ||
*(led->blink_delay) == delay) {
unsigned long val;
*(led->blink_leds) |= BIT(led->pin);
*(led->blink_delay) = delay;
val = bcm6328_led_read(led->mem + BCM6328_REG_INIT);
val &= ~BCM6328_LED_FAST_INTV_MASK;
val |= (delay << BCM6328_LED_FAST_INTV_SHIFT);
bcm6328_led_write(led->mem + BCM6328_REG_INIT, val);
bcm6328_led_mode(led, BCM6328_LED_MODE_BLINK);
spin_unlock_irqrestore(led->lock, flags);
} else {
spin_unlock_irqrestore(led->lock, flags);
dev_dbg(led_cdev->dev,
"fallback to soft blinking (delay already set)\n");
return -EINVAL;
}
return 0;
}
static int bcm6328_hwled(struct device *dev, struct device_node *nc, u32 reg,
void __iomem *mem, spinlock_t *lock)
{
int i, cnt;
unsigned long flags, val;
spin_lock_irqsave(lock, flags);
val = bcm6328_led_read(mem + BCM6328_REG_HWDIS);
val &= ~BIT(reg);
bcm6328_led_write(mem + BCM6328_REG_HWDIS, val);
spin_unlock_irqrestore(lock, flags);
if (reg >= 8)
return 0;
cnt = of_property_count_elems_of_size(nc, "brcm,link-signal-sources",
sizeof(u32));
for (i = 0; i < cnt; i++) {
u32 sel;
void __iomem *addr;
if (reg < 4)
addr = mem + BCM6328_REG_LNKACTSEL_LO;
else
addr = mem + BCM6328_REG_LNKACTSEL_HI;
of_property_read_u32_index(nc, "brcm,link-signal-sources", i,
&sel);
if (reg / 4 != sel / 4) {
dev_warn(dev, "invalid link signal source\n");
continue;
}
spin_lock_irqsave(lock, flags);
val = bcm6328_led_read(addr);
val |= (BIT(reg) << (((sel % 4) * 4) + 16));
bcm6328_led_write(addr, val);
spin_unlock_irqrestore(lock, flags);
}
cnt = of_property_count_elems_of_size(nc,
"brcm,activity-signal-sources",
sizeof(u32));
for (i = 0; i < cnt; i++) {
u32 sel;
void __iomem *addr;
if (reg < 4)
addr = mem + BCM6328_REG_LNKACTSEL_LO;
else
addr = mem + BCM6328_REG_LNKACTSEL_HI;
of_property_read_u32_index(nc, "brcm,activity-signal-sources",
i, &sel);
if (reg / 4 != sel / 4) {
dev_warn(dev, "invalid activity signal source\n");
continue;
}
spin_lock_irqsave(lock, flags);
val = bcm6328_led_read(addr);
val |= (BIT(reg) << ((sel % 4) * 4));
bcm6328_led_write(addr, val);
spin_unlock_irqrestore(lock, flags);
}
return 0;
}
static int bcm6328_led(struct device *dev, struct device_node *nc, u32 reg,
void __iomem *mem, spinlock_t *lock,
unsigned long *blink_leds, unsigned long *blink_delay)
{
struct bcm6328_led *led;
unsigned long flags;
const char *state;
int rc;
led = devm_kzalloc(dev, sizeof(*led), GFP_KERNEL);
if (!led)
return -ENOMEM;
led->pin = reg;
led->mem = mem;
led->lock = lock;
led->blink_leds = blink_leds;
led->blink_delay = blink_delay;
if (of_property_read_bool(nc, "active-low"))
led->active_low = true;
led->cdev.name = of_get_property(nc, "label", NULL) ? : nc->name;
led->cdev.default_trigger = of_get_property(nc,
"linux,default-trigger",
NULL);
if (!of_property_read_string(nc, "default-state", &state)) {
spin_lock_irqsave(lock, flags);
if (!strcmp(state, "on")) {
led->cdev.brightness = LED_FULL;
bcm6328_led_mode(led, BCM6328_LED_MODE_ON);
} else if (!strcmp(state, "keep")) {
void __iomem *mode;
unsigned long val, shift;
shift = bcm6328_pin2shift(led->pin);
if (shift / 16)
mode = mem + BCM6328_REG_MODE_HI;
else
mode = mem + BCM6328_REG_MODE_LO;
val = bcm6328_led_read(mode) >> (shift % 16);
val &= BCM6328_LED_MODE_MASK;
if (val == BCM6328_LED_MODE_ON)
led->cdev.brightness = LED_FULL;
else {
led->cdev.brightness = LED_OFF;
bcm6328_led_mode(led, BCM6328_LED_MODE_OFF);
}
} else {
led->cdev.brightness = LED_OFF;
bcm6328_led_mode(led, BCM6328_LED_MODE_OFF);
}
spin_unlock_irqrestore(lock, flags);
}
led->cdev.brightness_set = bcm6328_led_set;
led->cdev.blink_set = bcm6328_blink_set;
rc = led_classdev_register(dev, &led->cdev);
if (rc < 0)
return rc;
dev_dbg(dev, "registered LED %s\n", led->cdev.name);
return 0;
}
static int bcm6328_leds_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = pdev->dev.of_node;
struct device_node *child;
struct resource *mem_r;
void __iomem *mem;
spinlock_t *lock;
unsigned long val, *blink_leds, *blink_delay;
mem_r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem_r)
return -EINVAL;
mem = devm_ioremap_resource(dev, mem_r);
if (IS_ERR(mem))
return PTR_ERR(mem);
lock = devm_kzalloc(dev, sizeof(*lock), GFP_KERNEL);
if (!lock)
return -ENOMEM;
blink_leds = devm_kzalloc(dev, sizeof(*blink_leds), GFP_KERNEL);
if (!blink_leds)
return -ENOMEM;
blink_delay = devm_kzalloc(dev, sizeof(*blink_delay), GFP_KERNEL);
if (!blink_delay)
return -ENOMEM;
spin_lock_init(lock);
bcm6328_led_write(mem + BCM6328_REG_HWDIS, ~0);
bcm6328_led_write(mem + BCM6328_REG_LNKACTSEL_HI, 0);
bcm6328_led_write(mem + BCM6328_REG_LNKACTSEL_LO, 0);
val = bcm6328_led_read(mem + BCM6328_REG_INIT);
val &= ~BCM6328_SERIAL_LED_EN;
if (of_property_read_bool(np, "brcm,serial-leds"))
val |= BCM6328_SERIAL_LED_EN;
bcm6328_led_write(mem + BCM6328_REG_INIT, val);
for_each_available_child_of_node(np, child) {
int rc;
u32 reg;
if (of_property_read_u32(child, "reg", &reg))
continue;
if (reg >= BCM6328_LED_MAX_COUNT) {
dev_err(dev, "invalid LED (>= %d)\n",
BCM6328_LED_MAX_COUNT);
continue;
}
if (of_property_read_bool(child, "brcm,hardware-controlled"))
rc = bcm6328_hwled(dev, child, reg, mem, lock);
else
rc = bcm6328_led(dev, child, reg, mem, lock,
blink_leds, blink_delay);
if (rc < 0)
return rc;
}
return 0;
}
