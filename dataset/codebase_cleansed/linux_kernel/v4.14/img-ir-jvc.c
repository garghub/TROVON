static int img_ir_jvc_scancode(int len, u64 raw, u64 enabled_protocols,
struct img_ir_scancode_req *request)
{
unsigned int cust, data;
if (len != 16)
return -EINVAL;
cust = (raw >> 0) & 0xff;
data = (raw >> 8) & 0xff;
request->protocol = RC_PROTO_JVC;
request->scancode = cust << 8 | data;
return IMG_IR_SCANCODE;
}
static int img_ir_jvc_filter(const struct rc_scancode_filter *in,
struct img_ir_filter *out, u64 protocols)
{
unsigned int cust, data;
unsigned int cust_m, data_m;
cust = (in->data >> 8) & 0xff;
cust_m = (in->mask >> 8) & 0xff;
data = (in->data >> 0) & 0xff;
data_m = (in->mask >> 0) & 0xff;
out->data = cust | data << 8;
out->mask = cust_m | data_m << 8;
return 0;
}
