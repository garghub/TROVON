static int ir_nec_decode(struct rc_dev *dev, struct ir_raw_event ev)
{
struct nec_dec *data = &dev->raw->nec;
u32 scancode;
u8 address, not_address, command, not_command;
bool send_32bits = false;
if (!is_timing_event(ev)) {
if (ev.reset)
data->state = STATE_INACTIVE;
return 0;
}
IR_dprintk(2, "NEC decode started at state %d (%uus %s)\n",
data->state, TO_US(ev.duration), TO_STR(ev.pulse));
switch (data->state) {
case STATE_INACTIVE:
if (!ev.pulse)
break;
if (eq_margin(ev.duration, NEC_HEADER_PULSE, NEC_UNIT * 2)) {
data->is_nec_x = false;
data->necx_repeat = false;
} else if (eq_margin(ev.duration, NECX_HEADER_PULSE, NEC_UNIT / 2))
data->is_nec_x = true;
else
break;
data->count = 0;
data->state = STATE_HEADER_SPACE;
return 0;
case STATE_HEADER_SPACE:
if (ev.pulse)
break;
if (eq_margin(ev.duration, NEC_HEADER_SPACE, NEC_UNIT)) {
data->state = STATE_BIT_PULSE;
return 0;
} else if (eq_margin(ev.duration, NEC_REPEAT_SPACE, NEC_UNIT / 2)) {
if (!dev->keypressed) {
IR_dprintk(1, "Discarding last key repeat: event after key up\n");
} else {
rc_repeat(dev);
IR_dprintk(1, "Repeat last key\n");
data->state = STATE_TRAILER_PULSE;
}
return 0;
}
break;
case STATE_BIT_PULSE:
if (!ev.pulse)
break;
if (!eq_margin(ev.duration, NEC_BIT_PULSE, NEC_UNIT / 2))
break;
data->state = STATE_BIT_SPACE;
return 0;
case STATE_BIT_SPACE:
if (ev.pulse)
break;
if (data->necx_repeat && data->count == NECX_REPEAT_BITS &&
geq_margin(ev.duration,
NEC_TRAILER_SPACE, NEC_UNIT / 2)) {
IR_dprintk(1, "Repeat last key\n");
rc_repeat(dev);
data->state = STATE_INACTIVE;
return 0;
} else if (data->count > NECX_REPEAT_BITS)
data->necx_repeat = false;
data->bits <<= 1;
if (eq_margin(ev.duration, NEC_BIT_1_SPACE, NEC_UNIT / 2))
data->bits |= 1;
else if (!eq_margin(ev.duration, NEC_BIT_0_SPACE, NEC_UNIT / 2))
break;
data->count++;
if (data->count == NEC_NBITS)
data->state = STATE_TRAILER_PULSE;
else
data->state = STATE_BIT_PULSE;
return 0;
case STATE_TRAILER_PULSE:
if (!ev.pulse)
break;
if (!eq_margin(ev.duration, NEC_TRAILER_PULSE, NEC_UNIT / 2))
break;
data->state = STATE_TRAILER_SPACE;
return 0;
case STATE_TRAILER_SPACE:
if (ev.pulse)
break;
if (!geq_margin(ev.duration, NEC_TRAILER_SPACE, NEC_UNIT / 2))
break;
address = bitrev8((data->bits >> 24) & 0xff);
not_address = bitrev8((data->bits >> 16) & 0xff);
command = bitrev8((data->bits >> 8) & 0xff);
not_command = bitrev8((data->bits >> 0) & 0xff);
if ((command ^ not_command) != 0xff) {
IR_dprintk(1, "NEC checksum error: received 0x%08x\n",
data->bits);
send_32bits = true;
}
if (send_32bits) {
scancode = data->bits;
IR_dprintk(1, "NEC (modified) scancode 0x%08x\n", scancode);
} else if ((address ^ not_address) != 0xff) {
scancode = address << 16 |
not_address << 8 |
command;
IR_dprintk(1, "NEC (Ext) scancode 0x%06x\n", scancode);
} else {
scancode = address << 8 | command;
IR_dprintk(1, "NEC scancode 0x%04x\n", scancode);
}
if (data->is_nec_x)
data->necx_repeat = true;
rc_keydown(dev, RC_TYPE_NEC, scancode, 0);
data->state = STATE_INACTIVE;
return 0;
}
IR_dprintk(1, "NEC decode failed at count %d state %d (%uus %s)\n",
data->count, data->state, TO_US(ev.duration), TO_STR(ev.pulse));
data->state = STATE_INACTIVE;
return -EINVAL;
}
static int __init ir_nec_decode_init(void)
{
ir_raw_handler_register(&nec_handler);
printk(KERN_INFO "IR NEC protocol handler initialized\n");
return 0;
}
static void __exit ir_nec_decode_exit(void)
{
ir_raw_handler_unregister(&nec_handler);
}
