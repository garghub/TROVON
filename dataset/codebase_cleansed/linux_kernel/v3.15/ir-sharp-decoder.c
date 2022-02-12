static int ir_sharp_decode(struct rc_dev *dev, struct ir_raw_event ev)
{
struct sharp_dec *data = &dev->raw->sharp;
u32 msg, echo, address, command, scancode;
if (!rc_protocols_enabled(dev, RC_BIT_SHARP))
return 0;
if (!is_timing_event(ev)) {
if (ev.reset)
data->state = STATE_INACTIVE;
return 0;
}
IR_dprintk(2, "Sharp decode started at state %d (%uus %s)\n",
data->state, TO_US(ev.duration), TO_STR(ev.pulse));
switch (data->state) {
case STATE_INACTIVE:
if (!ev.pulse)
break;
if (!eq_margin(ev.duration, SHARP_BIT_PULSE,
SHARP_BIT_PULSE / 2))
break;
data->count = 0;
data->pulse_len = ev.duration;
data->state = STATE_BIT_SPACE;
return 0;
case STATE_BIT_PULSE:
if (!ev.pulse)
break;
if (!eq_margin(ev.duration, SHARP_BIT_PULSE,
SHARP_BIT_PULSE / 2))
break;
data->pulse_len = ev.duration;
data->state = STATE_BIT_SPACE;
return 0;
case STATE_BIT_SPACE:
if (ev.pulse)
break;
data->bits <<= 1;
if (eq_margin(data->pulse_len + ev.duration, SHARP_BIT_1_PERIOD,
SHARP_BIT_PULSE * 2))
data->bits |= 1;
else if (!eq_margin(data->pulse_len + ev.duration,
SHARP_BIT_0_PERIOD, SHARP_BIT_PULSE * 2))
break;
data->count++;
if (data->count == SHARP_NBITS ||
data->count == SHARP_NBITS * 2)
data->state = STATE_TRAILER_PULSE;
else
data->state = STATE_BIT_PULSE;
return 0;
case STATE_TRAILER_PULSE:
if (!ev.pulse)
break;
if (!eq_margin(ev.duration, SHARP_BIT_PULSE,
SHARP_BIT_PULSE / 2))
break;
if (data->count == SHARP_NBITS) {
if ((data->bits & 0x3) != 0x2)
break;
data->state = STATE_ECHO_SPACE;
} else {
data->state = STATE_TRAILER_SPACE;
}
return 0;
case STATE_ECHO_SPACE:
if (ev.pulse)
break;
if (!eq_margin(ev.duration, SHARP_ECHO_SPACE,
SHARP_ECHO_SPACE / 4))
break;
data->state = STATE_BIT_PULSE;
return 0;
case STATE_TRAILER_SPACE:
if (ev.pulse)
break;
if (!geq_margin(ev.duration, SHARP_TRAILER_SPACE,
SHARP_BIT_PULSE / 2))
break;
msg = (data->bits >> 15) & 0x7fff;
echo = data->bits & 0x7fff;
if ((msg ^ echo) != 0x3ff) {
IR_dprintk(1,
"Sharp checksum error: received 0x%04x, 0x%04x\n",
msg, echo);
break;
}
address = bitrev8((msg >> 7) & 0xf8);
command = bitrev8((msg >> 2) & 0xff);
scancode = address << 8 | command;
IR_dprintk(1, "Sharp scancode 0x%04x\n", scancode);
rc_keydown(dev, scancode, 0);
data->state = STATE_INACTIVE;
return 0;
}
IR_dprintk(1, "Sharp decode failed at count %d state %d (%uus %s)\n",
data->count, data->state, TO_US(ev.duration),
TO_STR(ev.pulse));
data->state = STATE_INACTIVE;
return -EINVAL;
}
static int __init ir_sharp_decode_init(void)
{
ir_raw_handler_register(&sharp_handler);
pr_info("IR Sharp protocol handler initialized\n");
return 0;
}
static void __exit ir_sharp_decode_exit(void)
{
ir_raw_handler_unregister(&sharp_handler);
}
