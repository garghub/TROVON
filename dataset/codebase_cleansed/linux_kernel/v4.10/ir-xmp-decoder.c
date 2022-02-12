static int ir_xmp_decode(struct rc_dev *dev, struct ir_raw_event ev)
{
struct xmp_dec *data = &dev->raw->xmp;
if (!is_timing_event(ev)) {
if (ev.reset)
data->state = STATE_INACTIVE;
return 0;
}
IR_dprintk(2, "XMP decode started at state %d %d (%uus %s)\n",
data->state, data->count, TO_US(ev.duration), TO_STR(ev.pulse));
switch (data->state) {
case STATE_INACTIVE:
if (!ev.pulse)
break;
if (eq_margin(ev.duration, XMP_LEADER, XMP_UNIT / 2)) {
data->count = 0;
data->state = STATE_NIBBLE_SPACE;
}
return 0;
case STATE_LEADER_PULSE:
if (!ev.pulse)
break;
if (eq_margin(ev.duration, XMP_LEADER, XMP_UNIT / 2))
data->state = STATE_NIBBLE_SPACE;
return 0;
case STATE_NIBBLE_SPACE:
if (ev.pulse)
break;
if (geq_margin(ev.duration, XMP_TRAILER_SPACE, XMP_NIBBLE_PREFIX)) {
int divider, i;
u8 addr, subaddr, subaddr2, toggle, oem, obc1, obc2, sum1, sum2;
u32 *n;
u32 scancode;
if (data->count != 16) {
IR_dprintk(2, "received TRAILER period at index %d: %u\n",
data->count, ev.duration);
data->state = STATE_INACTIVE;
return -EINVAL;
}
n = data->durations;
divider = (n[3] - XMP_NIBBLE_PREFIX) / 15 - 2000;
if (divider < 50) {
IR_dprintk(2, "divider to small %d.\n", divider);
data->state = STATE_INACTIVE;
return -EINVAL;
}
for (i = 0; i < 16; i++)
n[i] = (n[i] - XMP_NIBBLE_PREFIX) / divider;
sum1 = (15 + n[0] + n[1] + n[2] + n[3] +
n[4] + n[5] + n[6] + n[7]) % 16;
sum2 = (15 + n[8] + n[9] + n[10] + n[11] +
n[12] + n[13] + n[14] + n[15]) % 16;
if (sum1 != 15 || sum2 != 15) {
IR_dprintk(2, "checksum errors sum1=0x%X sum2=0x%X\n",
sum1, sum2);
data->state = STATE_INACTIVE;
return -EINVAL;
}
subaddr = n[0] << 4 | n[2];
subaddr2 = n[8] << 4 | n[11];
oem = n[4] << 4 | n[5];
addr = n[6] << 4 | n[7];
toggle = n[10];
obc1 = n[12] << 4 | n[13];
obc2 = n[14] << 4 | n[15];
if (subaddr != subaddr2) {
IR_dprintk(2, "subaddress nibbles mismatch 0x%02X != 0x%02X\n",
subaddr, subaddr2);
data->state = STATE_INACTIVE;
return -EINVAL;
}
if (oem != 0x44)
IR_dprintk(1, "Warning: OEM nibbles 0x%02X. Expected 0x44\n",
oem);
scancode = addr << 24 | subaddr << 16 |
obc1 << 8 | obc2;
IR_dprintk(1, "XMP scancode 0x%06x\n", scancode);
if (toggle == 0) {
rc_keydown(dev, RC_TYPE_XMP, scancode, 0);
} else {
rc_repeat(dev);
IR_dprintk(1, "Repeat last key\n");
}
data->state = STATE_INACTIVE;
return 0;
} else if (geq_margin(ev.duration, XMP_HALFFRAME_SPACE, XMP_NIBBLE_PREFIX)) {
if (data->count == 16) {
IR_dprintk(2, "received half frame pulse at index %d. Probably a final frame key-up event: %u\n",
data->count, ev.duration);
data->count = 8;
}
else if (data->count != 8)
IR_dprintk(2, "received half frame pulse at index %d: %u\n",
data->count, ev.duration);
data->state = STATE_LEADER_PULSE;
return 0;
} else if (geq_margin(ev.duration, XMP_NIBBLE_PREFIX, XMP_UNIT)) {
if (data->count == 16) {
IR_dprintk(2, "to many pulses (%d) ignoring: %u\n",
data->count, ev.duration);
data->state = STATE_INACTIVE;
return -EINVAL;
}
data->durations[data->count] = ev.duration;
data->count++;
data->state = STATE_LEADER_PULSE;
return 0;
}
break;
}
IR_dprintk(1, "XMP decode failed at count %d state %d (%uus %s)\n",
data->count, data->state, TO_US(ev.duration), TO_STR(ev.pulse));
data->state = STATE_INACTIVE;
return -EINVAL;
}
static int __init ir_xmp_decode_init(void)
{
ir_raw_handler_register(&xmp_handler);
printk(KERN_INFO "IR XMP protocol handler initialized\n");
return 0;
}
static void __exit ir_xmp_decode_exit(void)
{
ir_raw_handler_unregister(&xmp_handler);
}
