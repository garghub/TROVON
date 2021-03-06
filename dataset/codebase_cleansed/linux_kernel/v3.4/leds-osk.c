static void mistral_setled(void)
{
int red = 0;
int green = 0;
if (hw_led_state & TIMER_LED)
red = 1;
else if (hw_led_state & IDLE_LED)
green = 1;
gpio_set_value(GPIO_LED_GREEN, green);
gpio_set_value(GPIO_LED_RED, red);
}
void osk_leds_event(led_event_t evt)
{
unsigned long flags;
u16 leds;
local_irq_save(flags);
if (!(led_state & LED_STATE_ENABLED) && evt != led_start)
goto done;
leds = hw_led_state;
switch (evt) {
case led_start:
led_state |= LED_STATE_ENABLED;
hw_led_state = 0;
leds = ~0;
break;
case led_halted:
case led_stop:
led_state &= ~LED_STATE_ENABLED;
hw_led_state = 0;
break;
case led_claim:
led_state |= LED_STATE_CLAIMED;
hw_led_state = 0;
leds = ~0;
break;
case led_release:
led_state &= ~LED_STATE_CLAIMED;
hw_led_state = 0;
break;
#ifdef CONFIG_OMAP_OSK_MISTRAL
case led_timer:
hw_led_state ^= TIMER_LED;
mistral_setled();
break;
case led_idle_start:
hw_led_state &= ~IDLE_LED;
mistral_setled();
break;
case led_idle_end:
hw_led_state |= IDLE_LED;
mistral_setled();
break;
#endif
default:
break;
}
leds ^= hw_led_state;
done:
local_irq_restore(flags);
}
