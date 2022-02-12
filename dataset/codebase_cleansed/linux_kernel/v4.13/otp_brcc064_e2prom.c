void *brcc064_otp_read(struct v4l2_subdev *sd, u8 dev_addr,
u32 start_addr, u32 size)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
unsigned int e2prom_i2c_addr = dev_addr >> 1;
static const unsigned int max_read_size = 30;
int addr;
u32 s_addr = start_addr & E2PROM_ADDR_MASK;
unsigned char *buffer;
buffer = devm_kzalloc(&client->dev, size, GFP_KERNEL);
if (!buffer)
return NULL;
for (addr = s_addr; addr < size; addr += max_read_size) {
struct i2c_msg msg[2];
unsigned int i2c_addr = e2prom_i2c_addr;
u16 addr_buf;
int r;
msg[0].flags = 0;
msg[0].addr = i2c_addr;
addr_buf = cpu_to_be16(addr & 0xFFFF);
msg[0].len = 2;
msg[0].buf = (u8 *)&addr_buf;
msg[1].addr = i2c_addr;
msg[1].flags = I2C_M_RD;
msg[1].len = min(max_read_size, size - addr);
msg[1].buf = &buffer[addr];
r = i2c_transfer(client->adapter, msg, ARRAY_SIZE(msg));
if (r != ARRAY_SIZE(msg)) {
dev_err(&client->dev, "read failed at 0x%03x\n", addr);
return NULL;
}
}
return buffer;
}
