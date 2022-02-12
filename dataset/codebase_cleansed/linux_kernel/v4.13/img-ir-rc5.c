static int img_ir_rc5_scancode(int len, u64 raw, u64 enabled_protocols,
struct img_ir_scancode_req *request)
{
unsigned int addr, cmd, tgl, start;
raw >>= 2;
start = (raw >> 13) & 0x01;
tgl = (raw >> 11) & 0x01;
addr = (raw >> 6) & 0x1f;
cmd = raw & 0x3f;
cmd += ((raw >> 12) & 0x01) ? 0 : 0x40;
if (!start)
return -EINVAL;
request->protocol = RC_TYPE_RC5;
request->scancode = addr << 8 | cmd;
request->toggle = tgl;
return IMG_IR_SCANCODE;
}
static int img_ir_rc5_filter(const struct rc_scancode_filter *in,
struct img_ir_filter *out, u64 protocols)
{
return -EINVAL;
}
