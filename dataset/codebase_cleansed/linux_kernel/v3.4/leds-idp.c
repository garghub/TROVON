void idp_leds_event(led_event_t evt)
{
unsigned long flags;
local_irq_save(flags);
switch (evt) {
case led_start:
hw_led_state = IDP_HB_LED | IDP_BUSY_LED;
led_state = LED_STATE_ENABLED;
break;
case led_stop:
led_state &= ~LED_STATE_ENABLED;
break;
case led_claim:
led_state |= LED_STATE_CLAIMED;
hw_led_state = IDP_HB_LED | IDP_BUSY_LED;
break;
case led_release:
led_state &= ~LED_STATE_CLAIMED;
hw_led_state = IDP_HB_LED | IDP_BUSY_LED;
break;
#ifdef CONFIG_LEDS_TIMER
case led_timer:
if (!(led_state & LED_STATE_CLAIMED))
hw_led_state ^= IDP_HB_LED;
break;
#endif
#ifdef CONFIG_LEDS_CPU
case led_idle_start:
if (!(led_state & LED_STATE_CLAIMED))
hw_led_state &= ~IDP_BUSY_LED;
break;
case led_idle_end:
if (!(led_state & LED_STATE_CLAIMED))
hw_led_state |= IDP_BUSY_LED;
break;
#endif
case led_halted:
break;
case led_green_on:
if (led_state & LED_STATE_CLAIMED)
hw_led_state |= IDP_HB_LED;
break;
case led_green_off:
if (led_state & LED_STATE_CLAIMED)
hw_led_state &= ~IDP_HB_LED;
break;
case led_amber_on:
break;
case led_amber_off:
break;
case led_red_on:
if (led_state & LED_STATE_CLAIMED)
hw_led_state |= IDP_BUSY_LED;
break;
case led_red_off:
if (led_state & LED_STATE_CLAIMED)
hw_led_state &= ~IDP_BUSY_LED;
break;
default:
break;
}
if (led_state & LED_STATE_ENABLED)
IDP_CPLD_LED_CONTROL = ( (IDP_CPLD_LED_CONTROL | IDP_LEDS_MASK) & ~hw_led_state);
else
IDP_CPLD_LED_CONTROL |= IDP_LEDS_MASK;
local_irq_restore(flags);
}
