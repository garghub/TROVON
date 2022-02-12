void h2p2_dbg_leds_event(led_event_t evt)
{
unsigned long flags;
static struct h2p2_dbg_fpga __iomem *fpga;
static u16 led_state, hw_led_state;
local_irq_save(flags);
if (!(led_state & LED_STATE_ENABLED) && evt != led_start)
goto done;
switch (evt) {
case led_start:
if (!fpga)
fpga = ioremap(H2P2_DBG_FPGA_START,
H2P2_DBG_FPGA_SIZE);
if (fpga) {
led_state |= LED_STATE_ENABLED;
__raw_writew(~0, &fpga->leds);
}
break;
case led_stop:
case led_halted:
if (! machine_is_omap_perseus2()) {
gpio_set_value(GPIO_TIMER, 0);
gpio_set_value(GPIO_IDLE, 0);
}
__raw_writew(~0, &fpga->leds);
led_state &= ~LED_STATE_ENABLED;
if (evt == led_halted) {
iounmap(fpga);
fpga = NULL;
}
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
if (machine_is_omap_perseus2())
hw_led_state ^= H2P2_DBG_FPGA_P2_LED_TIMER;
else {
gpio_set_value(GPIO_TIMER, led_state & LED_TIMER_ON);
goto done;
}
break;
#endif
#ifdef CONFIG_LEDS_CPU
case led_idle_start:
if (machine_is_omap_perseus2())
hw_led_state |= H2P2_DBG_FPGA_P2_LED_IDLE;
else {
gpio_set_value(GPIO_IDLE, 1);
goto done;
}
break;
case led_idle_end:
if (machine_is_omap_perseus2())
hw_led_state &= ~H2P2_DBG_FPGA_P2_LED_IDLE;
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
local_irq_restore(flags);
}
