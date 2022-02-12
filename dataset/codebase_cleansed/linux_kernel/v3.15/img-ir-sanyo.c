static int img_ir_sanyo_scancode(int len, u64 raw, int *scancode, u64 protocols)
{
unsigned int addr, addr_inv, data, data_inv;
if (!len)
return IMG_IR_REPEATCODE;
if (len != 42)
return -EINVAL;
addr = (raw >> 0) & 0x1fff;
addr_inv = (raw >> 13) & 0x1fff;
data = (raw >> 26) & 0xff;
data_inv = (raw >> 34) & 0xff;
if ((data_inv ^ data) != 0xff)
return -EINVAL;
if ((addr_inv ^ addr) != 0x1fff)
return -EINVAL;
*scancode = addr << 8 | data;
return IMG_IR_SCANCODE;
}
static int img_ir_sanyo_filter(const struct rc_scancode_filter *in,
struct img_ir_filter *out, u64 protocols)
{
unsigned int addr, addr_inv, data, data_inv;
unsigned int addr_m, data_m;
data = in->data & 0xff;
data_m = in->mask & 0xff;
data_inv = data ^ 0xff;
if (in->data & 0xff700000)
return -EINVAL;
addr = (in->data >> 8) & 0x1fff;
addr_m = (in->mask >> 8) & 0x1fff;
addr_inv = addr ^ 0x1fff;
out->data = (u64)data_inv << 34 |
(u64)data << 26 |
addr_inv << 13 |
addr;
out->mask = (u64)data_m << 34 |
(u64)data_m << 26 |
addr_m << 13 |
addr_m;
return 0;
}
