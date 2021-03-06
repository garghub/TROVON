static void ebsa285_leds_event(led_event_t evt)
{
unsigned long flags;
spin_lock_irqsave(&leds_lock, flags);
switch (evt) {
case led_start:
hw_led_state = XBUS_LED_RED | XBUS_LED_GREEN;
#ifndef CONFIG_LEDS_CPU
hw_led_state |= XBUS_LED_AMBER;
#endif
led_state |= LED_STATE_ENABLED;
break;
case led_stop:
led_state &= ~LED_STATE_ENABLED;
break;
case led_claim:
led_state |= LED_STATE_CLAIMED;
hw_led_state = XBUS_LED_RED | XBUS_LED_GREEN | XBUS_LED_AMBER;
break;
case led_release:
led_state &= ~LED_STATE_CLAIMED;
hw_led_state = XBUS_LED_RED | XBUS_LED_GREEN | XBUS_LED_AMBER;
break;
#ifdef CONFIG_LEDS_TIMER
case led_timer:
if (!(led_state & LED_STATE_CLAIMED))
hw_led_state ^= XBUS_LED_GREEN;
break;
#endif
#ifdef CONFIG_LEDS_CPU
case led_idle_start:
if (!(led_state & LED_STATE_CLAIMED))
hw_led_state |= XBUS_LED_AMBER;
break;
case led_idle_end:
if (!(led_state & LED_STATE_CLAIMED))
hw_led_state &= ~XBUS_LED_AMBER;
break;
#endif
case led_halted:
if (!(led_state & LED_STATE_CLAIMED))
hw_led_state &= ~XBUS_LED_RED;
break;
case led_green_on:
if (led_state & LED_STATE_CLAIMED)
hw_led_state &= ~XBUS_LED_GREEN;
break;
case led_green_off:
if (led_state & LED_STATE_CLAIMED)
hw_led_state |= XBUS_LED_GREEN;
break;
case led_amber_on:
if (led_state & LED_STATE_CLAIMED)
hw_led_state &= ~XBUS_LED_AMBER;
break;
case led_amber_off:
if (led_state & LED_STATE_CLAIMED)
hw_led_state |= XBUS_LED_AMBER;
break;
case led_red_on:
if (led_state & LED_STATE_CLAIMED)
hw_led_state &= ~XBUS_LED_RED;
break;
case led_red_off:
if (led_state & LED_STATE_CLAIMED)
hw_led_state |= XBUS_LED_RED;
break;
default:
break;
}
if (led_state & LED_STATE_ENABLED)
*XBUS_LEDS = hw_led_state;
spin_unlock_irqrestore(&leds_lock, flags);
}
static int __init leds_init(void)
{
if (machine_is_ebsa285())
leds_event = ebsa285_leds_event;
leds_event(led_start);
return 0;
}
