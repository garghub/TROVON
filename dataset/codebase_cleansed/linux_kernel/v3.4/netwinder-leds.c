static void netwinder_leds_event(led_event_t evt)
{
unsigned long flags;
raw_spin_lock_irqsave(&leds_lock, flags);
switch (evt) {
case led_start:
led_state |= LED_STATE_ENABLED;
hw_led_state = GPIO_GREEN_LED;
break;
case led_stop:
led_state &= ~LED_STATE_ENABLED;
break;
case led_claim:
led_state |= LED_STATE_CLAIMED;
hw_led_state = 0;
break;
case led_release:
led_state &= ~LED_STATE_CLAIMED;
hw_led_state = 0;
break;
#ifdef CONFIG_LEDS_TIMER
case led_timer:
if (!(led_state & LED_STATE_CLAIMED))
hw_led_state ^= GPIO_GREEN_LED;
break;
#endif
#ifdef CONFIG_LEDS_CPU
case led_idle_start:
if (!(led_state & LED_STATE_CLAIMED))
hw_led_state &= ~GPIO_RED_LED;
break;
case led_idle_end:
if (!(led_state & LED_STATE_CLAIMED))
hw_led_state |= GPIO_RED_LED;
break;
#endif
case led_halted:
if (!(led_state & LED_STATE_CLAIMED))
hw_led_state |= GPIO_RED_LED;
break;
case led_green_on:
if (led_state & LED_STATE_CLAIMED)
hw_led_state |= GPIO_GREEN_LED;
break;
case led_green_off:
if (led_state & LED_STATE_CLAIMED)
hw_led_state &= ~GPIO_GREEN_LED;
break;
case led_amber_on:
if (led_state & LED_STATE_CLAIMED)
hw_led_state |= GPIO_GREEN_LED | GPIO_RED_LED;
break;
case led_amber_off:
if (led_state & LED_STATE_CLAIMED)
hw_led_state &= ~(GPIO_GREEN_LED | GPIO_RED_LED);
break;
case led_red_on:
if (led_state & LED_STATE_CLAIMED)
hw_led_state |= GPIO_RED_LED;
break;
case led_red_off:
if (led_state & LED_STATE_CLAIMED)
hw_led_state &= ~GPIO_RED_LED;
break;
default:
break;
}
raw_spin_unlock_irqrestore(&leds_lock, flags);
if (led_state & LED_STATE_ENABLED) {
raw_spin_lock_irqsave(&nw_gpio_lock, flags);
nw_gpio_modify_op(GPIO_RED_LED | GPIO_GREEN_LED, hw_led_state);
raw_spin_unlock_irqrestore(&nw_gpio_lock, flags);
}
}
static int __init leds_init(void)
{
if (machine_is_netwinder())
leds_event = netwinder_leds_event;
leds_event(led_start);
return 0;
}
