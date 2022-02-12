static int ir_jvc_decode(struct rc_dev *dev, struct ir_raw_event ev)
{
struct jvc_dec *data = &dev->raw->jvc;
if (!(dev->raw->enabled_protocols & RC_TYPE_JVC))
return 0;
if (!is_timing_event(ev)) {
if (ev.reset)
data->state = STATE_INACTIVE;
return 0;
}
if (!geq_margin(ev.duration, JVC_UNIT, JVC_UNIT / 2))
goto out;
IR_dprintk(2, "JVC decode started at state %d (%uus %s)\n",
data->state, TO_US(ev.duration), TO_STR(ev.pulse));
again:
switch (data->state) {
case STATE_INACTIVE:
if (!ev.pulse)
break;
if (!eq_margin(ev.duration, JVC_HEADER_PULSE, JVC_UNIT / 2))
break;
data->count = 0;
data->first = true;
data->toggle = !data->toggle;
data->state = STATE_HEADER_SPACE;
return 0;
case STATE_HEADER_SPACE:
if (ev.pulse)
break;
if (!eq_margin(ev.duration, JVC_HEADER_SPACE, JVC_UNIT / 2))
break;
data->state = STATE_BIT_PULSE;
return 0;
case STATE_BIT_PULSE:
if (!ev.pulse)
break;
if (!eq_margin(ev.duration, JVC_BIT_PULSE, JVC_UNIT / 2))
break;
data->state = STATE_BIT_SPACE;
return 0;
case STATE_BIT_SPACE:
if (ev.pulse)
break;
data->bits <<= 1;
if (eq_margin(ev.duration, JVC_BIT_1_SPACE, JVC_UNIT / 2)) {
data->bits |= 1;
decrease_duration(&ev, JVC_BIT_1_SPACE);
} else if (eq_margin(ev.duration, JVC_BIT_0_SPACE, JVC_UNIT / 2))
decrease_duration(&ev, JVC_BIT_0_SPACE);
else
break;
data->count++;
if (data->count == JVC_NBITS)
data->state = STATE_TRAILER_PULSE;
else
data->state = STATE_BIT_PULSE;
return 0;
case STATE_TRAILER_PULSE:
if (!ev.pulse)
break;
if (!eq_margin(ev.duration, JVC_TRAILER_PULSE, JVC_UNIT / 2))
break;
data->state = STATE_TRAILER_SPACE;
return 0;
case STATE_TRAILER_SPACE:
if (ev.pulse)
break;
if (!geq_margin(ev.duration, JVC_TRAILER_SPACE, JVC_UNIT / 2))
break;
if (data->first) {
u32 scancode;
scancode = (bitrev8((data->bits >> 8) & 0xff) << 8) |
(bitrev8((data->bits >> 0) & 0xff) << 0);
IR_dprintk(1, "JVC scancode 0x%04x\n", scancode);
rc_keydown(dev, scancode, data->toggle);
data->first = false;
data->old_bits = data->bits;
} else if (data->bits == data->old_bits) {
IR_dprintk(1, "JVC repeat\n");
rc_repeat(dev);
} else {
IR_dprintk(1, "JVC invalid repeat msg\n");
break;
}
data->count = 0;
data->state = STATE_CHECK_REPEAT;
return 0;
case STATE_CHECK_REPEAT:
if (!ev.pulse)
break;
if (eq_margin(ev.duration, JVC_HEADER_PULSE, JVC_UNIT / 2))
data->state = STATE_INACTIVE;
else
data->state = STATE_BIT_PULSE;
goto again;
}
out:
IR_dprintk(1, "JVC decode failed at state %d (%uus %s)\n",
data->state, TO_US(ev.duration), TO_STR(ev.pulse));
data->state = STATE_INACTIVE;
return -EINVAL;
}
static int __init ir_jvc_decode_init(void)
{
ir_raw_handler_register(&jvc_handler);
printk(KERN_INFO "IR JVC protocol handler initialized\n");
return 0;
}
static void __exit ir_jvc_decode_exit(void)
{
ir_raw_handler_unregister(&jvc_handler);
}
