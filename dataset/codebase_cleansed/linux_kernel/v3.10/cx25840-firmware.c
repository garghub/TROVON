static void start_fw_load(struct i2c_client *client)
{
cx25840_write(client, 0x800, 0x00);
cx25840_write(client, 0x801, 0x00);
cx25840_write(client, 0x803, 0x0b);
cx25840_write(client, 0x000, 0x20);
}
static void end_fw_load(struct i2c_client *client)
{
cx25840_write(client, 0x000, 0x00);
cx25840_write(client, 0x803, 0x03);
}
static const char *get_fw_name(struct i2c_client *client)
{
struct cx25840_state *state = to_state(i2c_get_clientdata(client));
if (firmware[0])
return firmware;
if (is_cx2388x(state))
return CX2388x_FIRMWARE;
if (is_cx231xx(state))
return CX231xx_FIRMWARE;
return CX25840_FIRMWARE;
}
static int check_fw_load(struct i2c_client *client, int size)
{
int s = cx25840_read(client, 0x801) << 8;
s |= cx25840_read(client, 0x800);
if (size != s) {
v4l_err(client, "firmware %s load failed\n",
get_fw_name(client));
return -EINVAL;
}
v4l_info(client, "loaded %s firmware (%d bytes)\n",
get_fw_name(client), size);
return 0;
}
static int fw_write(struct i2c_client *client, const u8 *data, int size)
{
if (i2c_master_send(client, data, size) < size) {
v4l_err(client, "firmware load i2c failure\n");
return -ENOSYS;
}
return 0;
}
int cx25840_loadfw(struct i2c_client *client)
{
struct cx25840_state *state = to_state(i2c_get_clientdata(client));
const struct firmware *fw = NULL;
u8 buffer[FWSEND];
const u8 *ptr;
const char *fwname = get_fw_name(client);
int size, retval;
int MAX_BUF_SIZE = FWSEND;
u32 gpio_oe = 0, gpio_da = 0;
if (is_cx2388x(state)) {
gpio_oe = cx25840_read(client, 0x160);
gpio_da = cx25840_read(client, 0x164);
}
if (is_cx231xx(state) && MAX_BUF_SIZE > 16) {
v4l_err(client, " Firmware download size changed to 16 bytes max length\n");
MAX_BUF_SIZE = 16;
}
if (request_firmware(&fw, fwname, FWDEV(client)) != 0) {
v4l_err(client, "unable to open firmware %s\n", fwname);
return -EINVAL;
}
start_fw_load(client);
buffer[0] = 0x08;
buffer[1] = 0x02;
size = fw->size;
ptr = fw->data;
while (size > 0) {
int len = min(MAX_BUF_SIZE - 2, size);
memcpy(buffer + 2, ptr, len);
retval = fw_write(client, buffer, len + 2);
if (retval < 0) {
release_firmware(fw);
return retval;
}
size -= len;
ptr += len;
}
end_fw_load(client);
size = fw->size;
release_firmware(fw);
if (is_cx2388x(state)) {
cx25840_write(client, 0x160, gpio_oe);
cx25840_write(client, 0x164, gpio_da);
}
return check_fw_load(client, size);
}
