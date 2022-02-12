void mainstone_leds_event(led_event_t evt)
{
unsigned long flags;
local_irq_save(flags);
switch (evt) {
case led_start:
hw_led_state = 0;
led_state = LED_STATE_ENABLED;
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
hw_led_state ^= D26;
break;
#endif
#ifdef CONFIG_LEDS_CPU
case led_idle_start:
hw_led_state &= ~D27;
break;
case led_idle_end:
hw_led_state |= D27;
break;
#endif
case led_halted:
break;
case led_green_on:
hw_led_state |= D21;
break;
case led_green_off:
hw_led_state &= ~D21;
break;
case led_amber_on:
hw_led_state |= D22;
break;
case led_amber_off:
hw_led_state &= ~D22;
break;
case led_red_on:
hw_led_state |= D23;
break;
case led_red_off:
hw_led_state &= ~D23;
break;
default:
break;
}
if (led_state & LED_STATE_ENABLED)
MST_LEDCTRL = (MST_LEDCTRL | 0xff) & ~hw_led_state;
else
MST_LEDCTRL |= 0xff;
local_irq_restore(flags);
}
