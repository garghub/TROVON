static void h2p2_dbg_leds_event(led_event_t evt)
{
unsigned long flags;
spin_lock_irqsave(&lock, flags);
if (!(led_state & LED_STATE_ENABLED) && evt != led_start)
goto done;
switch (evt) {
case led_start:
if (fpga)
led_state |= LED_STATE_ENABLED;
break;
case led_stop:
case led_halted:
if (!(machine_is_omap_perseus2() || machine_is_omap_h4())) {
gpio_set_value(GPIO_TIMER, 0);
gpio_set_value(GPIO_IDLE, 0);
}
__raw_writew(~0, &fpga->leds);
led_state &= ~LED_STATE_ENABLED;
goto done;
case led_claim:
led_state |= LED_STATE_CLAIMED;
hw_led_state = 0;
break;
case led_release:
led_state &= ~LED_STATE_CLAIMED;
break;
#ifdef CONFIG_LEDS_TIMER
case led_timer:
led_state ^= LED_TIMER_ON;
if (machine_is_omap_perseus2() || machine_is_omap_h4())
hw_led_state ^= H2P2_DBG_FPGA_P2_LED_TIMER;
else {
gpio_set_value(GPIO_TIMER,
led_state & LED_TIMER_ON);
goto done;
}
break;
#endif
#ifdef CONFIG_LEDS_CPU
case led_idle_start:
if (machine_is_omap_perseus2() || machine_is_omap_h4())
hw_led_state &= ~H2P2_DBG_FPGA_P2_LED_IDLE;
else {
gpio_set_value(GPIO_IDLE, 1);
goto done;
}
break;
case led_idle_end:
if (machine_is_omap_perseus2() || machine_is_omap_h4())
hw_led_state |= H2P2_DBG_FPGA_P2_LED_IDLE;
else {
gpio_set_value(GPIO_IDLE, 0);
goto done;
}
break;
#endif
case led_green_on:
hw_led_state |= H2P2_DBG_FPGA_LED_GREEN;
break;
case led_green_off:
hw_led_state &= ~H2P2_DBG_FPGA_LED_GREEN;
break;
case led_amber_on:
hw_led_state |= H2P2_DBG_FPGA_LED_AMBER;
break;
case led_amber_off:
hw_led_state &= ~H2P2_DBG_FPGA_LED_AMBER;
break;
case led_red_on:
hw_led_state |= H2P2_DBG_FPGA_LED_RED;
break;
case led_red_off:
hw_led_state &= ~H2P2_DBG_FPGA_LED_RED;
break;
case led_blue_on:
hw_led_state |= H2P2_DBG_FPGA_LED_BLUE;
break;
case led_blue_off:
hw_led_state &= ~H2P2_DBG_FPGA_LED_BLUE;
break;
default:
break;
}
if (led_state & LED_STATE_ENABLED)
__raw_writew(~hw_led_state, &fpga->leds);
done:
spin_unlock_irqrestore(&lock, flags);
}
static void
fpga_led_set(struct led_classdev *cdev, enum led_brightness value)
{
struct dbg_led *led = container_of(cdev, struct dbg_led, cdev);
unsigned long flags;
spin_lock_irqsave(&lock, flags);
if (value == LED_OFF)
hw_led_state &= ~led->mask;
else
hw_led_state |= led->mask;
__raw_writew(~hw_led_state, &fpga->leds);
spin_unlock_irqrestore(&lock, flags);
}
static void __init newled_init(struct device *dev)
{
unsigned i;
struct dbg_led *led;
int status;
for (i = 0, led = dbg_leds; i < ARRAY_SIZE(dbg_leds); i++, led++) {
led->cdev.brightness_set = fpga_led_set;
status = led_classdev_register(dev, &led->cdev);
if (status < 0)
break;
}
return;
}
static int fpga_probe(struct platform_device *pdev)
{
struct resource *iomem;
spin_lock_init(&lock);
iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!iomem)
return -ENODEV;
fpga = ioremap(iomem->start, H2P2_DBG_FPGA_SIZE);
__raw_writew(~0, &fpga->leds);
#ifdef CONFIG_LEDS
leds_event = h2p2_dbg_leds_event;
leds_event(led_start);
#endif
if (new_led_api()) {
newled_init(&pdev->dev);
}
return 0;
}
static int fpga_suspend_noirq(struct device *dev)
{
__raw_writew(~0, &fpga->leds);
return 0;
}
static int fpga_resume_noirq(struct device *dev)
{
__raw_writew(~hw_led_state, &fpga->leds);
return 0;
}
static int __init fpga_init(void)
{
if (machine_is_omap_h4()
|| machine_is_omap_h3()
|| machine_is_omap_h2()
|| machine_is_omap_perseus2()
)
return platform_driver_register(&led_driver);
return 0;
}
