static int ir_rc5_decode(struct rc_dev *dev, struct ir_raw_event ev)
{
struct rc5_dec *data = &dev->raw->rc5;
u8 toggle;
u32 scancode;
enum rc_type protocol;
if (!(dev->enabled_protocols & (RC_BIT_RC5 | RC_BIT_RC5X | RC_BIT_RC5_SZ)))
return 0;
if (!is_timing_event(ev)) {
if (ev.reset)
data->state = STATE_INACTIVE;
return 0;
}
if (!geq_margin(ev.duration, RC5_UNIT, RC5_UNIT / 2))
goto out;
again:
IR_dprintk(2, "RC5(x/sz) decode started at state %i (%uus %s)\n",
data->state, TO_US(ev.duration), TO_STR(ev.pulse));
if (!geq_margin(ev.duration, RC5_UNIT, RC5_UNIT / 2))
return 0;
switch (data->state) {
case STATE_INACTIVE:
if (!ev.pulse)
break;
data->state = STATE_BIT_START;
data->count = 1;
decrease_duration(&ev, RC5_BIT_START);
goto again;
case STATE_BIT_START:
if (!ev.pulse && geq_margin(ev.duration, RC5_TRAILER, RC5_UNIT / 2)) {
data->state = STATE_FINISHED;
goto again;
}
if (!eq_margin(ev.duration, RC5_BIT_START, RC5_UNIT / 2))
break;
data->bits <<= 1;
if (!ev.pulse)
data->bits |= 1;
data->count++;
data->state = STATE_BIT_END;
return 0;
case STATE_BIT_END:
if (!is_transition(&ev, &dev->raw->prev_ev))
break;
if (data->count == CHECK_RC5X_NBITS)
data->state = STATE_CHECK_RC5X;
else
data->state = STATE_BIT_START;
decrease_duration(&ev, RC5_BIT_END);
goto again;
case STATE_CHECK_RC5X:
if (!ev.pulse && geq_margin(ev.duration, RC5X_SPACE, RC5_UNIT / 2)) {
data->is_rc5x = true;
decrease_duration(&ev, RC5X_SPACE);
} else
data->is_rc5x = false;
data->state = STATE_BIT_START;
goto again;
case STATE_FINISHED:
if (ev.pulse)
break;
if (data->is_rc5x && data->count == RC5X_NBITS) {
u8 xdata, command, system;
if (!(dev->enabled_protocols & RC_BIT_RC5X)) {
data->state = STATE_INACTIVE;
return 0;
}
xdata = (data->bits & 0x0003F) >> 0;
command = (data->bits & 0x00FC0) >> 6;
system = (data->bits & 0x1F000) >> 12;
toggle = (data->bits & 0x20000) ? 1 : 0;
command += (data->bits & 0x01000) ? 0 : 0x40;
scancode = system << 16 | command << 8 | xdata;
protocol = RC_TYPE_RC5X;
} else if (!data->is_rc5x && data->count == RC5_NBITS) {
u8 command, system;
if (!(dev->enabled_protocols & RC_BIT_RC5)) {
data->state = STATE_INACTIVE;
return 0;
}
command = (data->bits & 0x0003F) >> 0;
system = (data->bits & 0x007C0) >> 6;
toggle = (data->bits & 0x00800) ? 1 : 0;
command += (data->bits & 0x01000) ? 0 : 0x40;
scancode = system << 8 | command;
protocol = RC_TYPE_RC5;
} else if (!data->is_rc5x && data->count == RC5_SZ_NBITS) {
u8 command, system;
if (!(dev->enabled_protocols & RC_BIT_RC5_SZ)) {
data->state = STATE_INACTIVE;
return 0;
}
command = (data->bits & 0x0003F) >> 0;
system = (data->bits & 0x02FC0) >> 6;
toggle = (data->bits & 0x01000) ? 1 : 0;
scancode = system << 6 | command;
protocol = RC_TYPE_RC5_SZ;
} else
break;
IR_dprintk(1, "RC5(x/sz) scancode 0x%06x (p: %u, t: %u)\n",
scancode, protocol, toggle);
rc_keydown(dev, protocol, scancode, toggle);
data->state = STATE_INACTIVE;
return 0;
}
out:
IR_dprintk(1, "RC5(x/sz) decode failed at state %i count %d (%uus %s)\n",
data->state, data->count, TO_US(ev.duration), TO_STR(ev.pulse));
data->state = STATE_INACTIVE;
return -EINVAL;
}
static int __init ir_rc5_decode_init(void)
{
ir_raw_handler_register(&rc5_handler);
printk(KERN_INFO "IR RC5(x/sz) protocol handler initialized\n");
return 0;
}
static void __exit ir_rc5_decode_exit(void)
{
ir_raw_handler_unregister(&rc5_handler);
}
