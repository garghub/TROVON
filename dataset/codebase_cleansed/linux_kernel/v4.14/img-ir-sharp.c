static int img_ir_sharp_scancode(int len, u64 raw, u64 enabled_protocols,
struct img_ir_scancode_req *request)
{
unsigned int addr, cmd, exp, chk;
if (len != 15)
return -EINVAL;
addr = (raw >> 0) & 0x1f;
cmd = (raw >> 5) & 0xff;
exp = (raw >> 13) & 0x1;
chk = (raw >> 14) & 0x1;
if (!exp)
return -EINVAL;
if (chk)
return -EINVAL;
request->protocol = RC_PROTO_SHARP;
request->scancode = addr << 8 | cmd;
return IMG_IR_SCANCODE;
}
static int img_ir_sharp_filter(const struct rc_scancode_filter *in,
struct img_ir_filter *out, u64 protocols)
{
unsigned int addr, cmd, exp = 0, chk = 0;
unsigned int addr_m, cmd_m, exp_m = 0, chk_m = 0;
addr = (in->data >> 8) & 0x1f;
addr_m = (in->mask >> 8) & 0x1f;
cmd = (in->data >> 0) & 0xff;
cmd_m = (in->mask >> 0) & 0xff;
if (cmd_m) {
exp = 1;
exp_m = 1;
chk = 0;
chk_m = 1;
}
out->data = addr |
cmd << 5 |
exp << 13 |
chk << 14;
out->mask = addr_m |
cmd_m << 5 |
exp_m << 13 |
chk_m << 14;
return 0;
}
