short sequoia_read(int addr) {
outw(addr,0x24);
return inw(0x26);
}
void sequoia_write(short value,short addr) {
outw(addr,0x24);
outw(value,0x26);
}
static void sequoia_leds_event(led_event_t evt)
{
unsigned long flags;
spin_lock_irqsave(&leds_lock, flags);
hw_led_state = sequoia_read(0x09);
switch (evt) {
case led_start:
hw_led_state |= SEQUOIA_LED_GREEN;
hw_led_state |= SEQUOIA_LED_AMBER;
#ifdef CONFIG_LEDS_CPU
hw_led_state |= SEQUOIA_LED_BACK;
#else
hw_led_state &= ~SEQUOIA_LED_BACK;
#endif
led_state |= LED_STATE_ENABLED;
break;
case led_stop:
hw_led_state &= ~SEQUOIA_LED_BACK;
hw_led_state |= SEQUOIA_LED_GREEN;
hw_led_state |= SEQUOIA_LED_AMBER;
led_state &= ~LED_STATE_ENABLED;
break;
case led_claim:
led_state |= LED_STATE_CLAIMED;
saved_state = hw_led_state;
hw_led_state &= ~SEQUOIA_LED_BACK;
hw_led_state |= SEQUOIA_LED_GREEN;
hw_led_state |= SEQUOIA_LED_AMBER;
break;
case led_release:
led_state &= ~LED_STATE_CLAIMED;
hw_led_state = saved_state;
break;
#ifdef CONFIG_LEDS_TIMER
case led_timer:
if (!(led_state & LED_STATE_CLAIMED))
hw_led_state ^= SEQUOIA_LED_GREEN;
break;
#endif
#ifdef CONFIG_LEDS_CPU
case led_idle_start:
if (!(led_state & LED_STATE_CLAIMED))
hw_led_state &= ~SEQUOIA_LED_BACK;
break;
case led_idle_end:
if (!(led_state & LED_STATE_CLAIMED))
hw_led_state |= SEQUOIA_LED_BACK;
break;
#endif
case led_green_on:
if (led_state & LED_STATE_CLAIMED)
hw_led_state &= ~SEQUOIA_LED_GREEN;
break;
case led_green_off:
if (led_state & LED_STATE_CLAIMED)
hw_led_state |= SEQUOIA_LED_GREEN;
break;
case led_amber_on:
if (led_state & LED_STATE_CLAIMED)
hw_led_state &= ~SEQUOIA_LED_AMBER;
break;
case led_amber_off:
if (led_state & LED_STATE_CLAIMED)
hw_led_state |= SEQUOIA_LED_AMBER;
break;
case led_red_on:
if (led_state & LED_STATE_CLAIMED)
hw_led_state |= SEQUOIA_LED_BACK;
break;
case led_red_off:
if (led_state & LED_STATE_CLAIMED)
hw_led_state &= ~SEQUOIA_LED_BACK;
break;
default:
break;
}
if (led_state & LED_STATE_ENABLED)
sequoia_write(hw_led_state,0x09);
spin_unlock_irqrestore(&leds_lock, flags);
}
static int __init leds_init(void)
{
extern void (*leds_event)(led_event_t);
short temp;
leds_event = sequoia_leds_event;
request_region(0x24,4,"sequoia");
temp = sequoia_read(0x09);
temp |= 1<<10;
sequoia_write(temp,0x09);
leds_event(led_start);
return 0;
}
