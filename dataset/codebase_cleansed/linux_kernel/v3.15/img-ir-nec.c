static int img_ir_nec_scancode(int len, u64 raw, int *scancode, u64 protocols)
{
unsigned int addr, addr_inv, data, data_inv;
if (!len)
return IMG_IR_REPEATCODE;
if (len != 32)
return -EINVAL;
addr = (raw >> 0) & 0xff;
addr_inv = (raw >> 8) & 0xff;
data = (raw >> 16) & 0xff;
data_inv = (raw >> 24) & 0xff;
if ((data_inv ^ data) != 0xff) {
*scancode = bitrev8(addr) << 24 |
bitrev8(addr_inv) << 16 |
bitrev8(data) << 8 |
bitrev8(data_inv);
} else if ((addr_inv ^ addr) != 0xff) {
*scancode = addr << 16 |
addr_inv << 8 |
data;
} else {
*scancode = addr << 8 |
data;
}
return IMG_IR_SCANCODE;
}
static int img_ir_nec_filter(const struct rc_scancode_filter *in,
struct img_ir_filter *out, u64 protocols)
{
unsigned int addr, addr_inv, data, data_inv;
unsigned int addr_m, addr_inv_m, data_m, data_inv_m;
data = in->data & 0xff;
data_m = in->mask & 0xff;
if ((in->data | in->mask) & 0xff000000) {
addr = bitrev8(in->data >> 24);
addr_m = bitrev8(in->mask >> 24);
addr_inv = bitrev8(in->data >> 16);
addr_inv_m = bitrev8(in->mask >> 16);
data = bitrev8(in->data >> 8);
data_m = bitrev8(in->mask >> 8);
data_inv = bitrev8(in->data >> 0);
data_inv_m = bitrev8(in->mask >> 0);
} else if ((in->data | in->mask) & 0x00ff0000) {
addr = (in->data >> 16) & 0xff;
addr_m = (in->mask >> 16) & 0xff;
addr_inv = (in->data >> 8) & 0xff;
addr_inv_m = (in->mask >> 8) & 0xff;
data_inv = data ^ 0xff;
data_inv_m = data_m;
} else {
addr = (in->data >> 8) & 0xff;
addr_m = (in->mask >> 8) & 0xff;
addr_inv = addr ^ 0xff;
addr_inv_m = addr_m;
data_inv = data ^ 0xff;
data_inv_m = data_m;
}
out->data = data_inv << 24 |
data << 16 |
addr_inv << 8 |
addr;
out->mask = data_inv_m << 24 |
data_m << 16 |
addr_inv_m << 8 |
addr_m;
return 0;
}
