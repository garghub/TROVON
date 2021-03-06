static enum rc6_mode rc6_mode(struct rc6_dec *data)
{
switch (data->header & RC6_MODE_MASK) {
case 0:
return RC6_MODE_0;
case 6:
if (!data->toggle)
return RC6_MODE_6A;
default:
return RC6_MODE_UNKNOWN;
}
}
static int ir_rc6_decode(struct rc_dev *dev, struct ir_raw_event ev)
{
struct rc6_dec *data = &dev->raw->rc6;
u32 scancode;
u8 toggle;
if (!(dev->raw->enabled_protocols & RC_TYPE_RC6))
return 0;
if (!is_timing_event(ev)) {
if (ev.reset)
data->state = STATE_INACTIVE;
return 0;
}
if (!geq_margin(ev.duration, RC6_UNIT, RC6_UNIT / 2))
goto out;
again:
IR_dprintk(2, "RC6 decode started at state %i (%uus %s)\n",
data->state, TO_US(ev.duration), TO_STR(ev.pulse));
if (!geq_margin(ev.duration, RC6_UNIT, RC6_UNIT / 2))
return 0;
switch (data->state) {
case STATE_INACTIVE:
if (!ev.pulse)
break;
if (!eq_margin(ev.duration, RC6_PREFIX_PULSE, RC6_UNIT))
break;
data->state = STATE_PREFIX_SPACE;
data->count = 0;
return 0;
case STATE_PREFIX_SPACE:
if (ev.pulse)
break;
if (!eq_margin(ev.duration, RC6_PREFIX_SPACE, RC6_UNIT / 2))
break;
data->state = STATE_HEADER_BIT_START;
return 0;
case STATE_HEADER_BIT_START:
if (!eq_margin(ev.duration, RC6_BIT_START, RC6_UNIT / 2))
break;
data->header <<= 1;
if (ev.pulse)
data->header |= 1;
data->count++;
data->state = STATE_HEADER_BIT_END;
return 0;
case STATE_HEADER_BIT_END:
if (!is_transition(&ev, &dev->raw->prev_ev))
break;
if (data->count == RC6_HEADER_NBITS)
data->state = STATE_TOGGLE_START;
else
data->state = STATE_HEADER_BIT_START;
decrease_duration(&ev, RC6_BIT_END);
goto again;
case STATE_TOGGLE_START:
if (!eq_margin(ev.duration, RC6_TOGGLE_START, RC6_UNIT / 2))
break;
data->toggle = ev.pulse;
data->state = STATE_TOGGLE_END;
return 0;
case STATE_TOGGLE_END:
if (!is_transition(&ev, &dev->raw->prev_ev) ||
!geq_margin(ev.duration, RC6_TOGGLE_END, RC6_UNIT / 2))
break;
if (!(data->header & RC6_STARTBIT_MASK)) {
IR_dprintk(1, "RC6 invalid start bit\n");
break;
}
data->state = STATE_BODY_BIT_START;
decrease_duration(&ev, RC6_TOGGLE_END);
data->count = 0;
switch (rc6_mode(data)) {
case RC6_MODE_0:
data->wanted_bits = RC6_0_NBITS;
break;
case RC6_MODE_6A:
if ((!ev.pulse && !geq_margin(ev.duration, RC6_UNIT, RC6_UNIT / 2)) ||
geq_margin(ev.duration, RC6_UNIT, RC6_UNIT / 2))
data->wanted_bits = RC6_6A_LARGE_NBITS;
else
data->wanted_bits = RC6_6A_SMALL_NBITS;
break;
default:
IR_dprintk(1, "RC6 unknown mode\n");
goto out;
}
goto again;
case STATE_BODY_BIT_START:
if (!eq_margin(ev.duration, RC6_BIT_START, RC6_UNIT / 2))
break;
data->body <<= 1;
if (ev.pulse)
data->body |= 1;
data->count++;
data->state = STATE_BODY_BIT_END;
return 0;
case STATE_BODY_BIT_END:
if (!is_transition(&ev, &dev->raw->prev_ev))
break;
if (data->count == data->wanted_bits)
data->state = STATE_FINISHED;
else
data->state = STATE_BODY_BIT_START;
decrease_duration(&ev, RC6_BIT_END);
goto again;
case STATE_FINISHED:
if (ev.pulse)
break;
switch (rc6_mode(data)) {
case RC6_MODE_0:
scancode = data->body & 0xffff;
toggle = data->toggle;
IR_dprintk(1, "RC6(0) scancode 0x%04x (toggle: %u)\n",
scancode, toggle);
break;
case RC6_MODE_6A:
if (data->wanted_bits == RC6_6A_LARGE_NBITS) {
toggle = data->body & RC6_6A_MCE_TOGGLE_MASK ? 1 : 0;
scancode = data->body & ~RC6_6A_MCE_TOGGLE_MASK;
} else {
toggle = 0;
scancode = data->body & 0xffffff;
}
IR_dprintk(1, "RC6(6A) scancode 0x%08x (toggle: %u)\n",
scancode, toggle);
break;
default:
IR_dprintk(1, "RC6 unknown mode\n");
goto out;
}
rc_keydown(dev, scancode, toggle);
data->state = STATE_INACTIVE;
return 0;
}
out:
IR_dprintk(1, "RC6 decode failed at state %i (%uus %s)\n",
data->state, TO_US(ev.duration), TO_STR(ev.pulse));
data->state = STATE_INACTIVE;
return -EINVAL;
}
static int __init ir_rc6_decode_init(void)
{
ir_raw_handler_register(&rc6_handler);
printk(KERN_INFO "IR RC6 protocol handler initialized\n");
return 0;
}
static void __exit ir_rc6_decode_exit(void)
{
ir_raw_handler_unregister(&rc6_handler);
}
