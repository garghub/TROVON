static int ir_sharp_decode(struct rc_dev *dev, struct ir_raw_event ev)
{
struct sharp_dec *data = &dev->raw->sharp;
u32 msg, echo, address, command, scancode;
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
if ((data->bits & 0x3) != 0x2 &&
(data->bits & 0x3) != 0x0)
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
rc_keydown(dev, RC_PROTO_SHARP, scancode, 0);
data->state = STATE_INACTIVE;
return 0;
}
IR_dprintk(1, "Sharp decode failed at count %d state %d (%uus %s)\n",
data->count, data->state, TO_US(ev.duration),
TO_STR(ev.pulse));
data->state = STATE_INACTIVE;
return -EINVAL;
}
static int ir_sharp_encode(enum rc_proto protocol, u32 scancode,
struct ir_raw_event *events, unsigned int max)
{
struct ir_raw_event *e = events;
int ret;
u32 raw;
raw = (((bitrev8(scancode >> 8) >> 3) << 8) & 0x1f00) |
bitrev8(scancode);
ret = ir_raw_gen_pd(&e, max, &ir_sharp_timings, SHARP_NBITS,
(raw << 2) | 2);
if (ret < 0)
return ret;
max -= ret;
raw = (((bitrev8(scancode >> 8) >> 3) << 8) & 0x1f00) |
bitrev8(~scancode);
ret = ir_raw_gen_pd(&e, max, &ir_sharp_timings, SHARP_NBITS,
(raw << 2) | 1);
if (ret < 0)
return ret;
return e - events;
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
