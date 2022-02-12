static int rmi_smb_get_version(struct rmi_smb_xport *rmi_smb)
{
struct i2c_client *client = rmi_smb->client;
int retval;
retval = i2c_smbus_read_byte_data(client, SMB_PROTOCOL_VERSION_ADDRESS);
if (retval < 0) {
dev_err(&client->dev, "failed to get SMBus version number!\n");
return retval;
}
return retval + 1;
}
static int smb_block_write(struct rmi_transport_dev *xport,
u8 commandcode, const void *buf, size_t len)
{
struct rmi_smb_xport *rmi_smb =
container_of(xport, struct rmi_smb_xport, xport);
struct i2c_client *client = rmi_smb->client;
int retval;
retval = i2c_smbus_write_block_data(client, commandcode, len, buf);
rmi_dbg(RMI_DEBUG_XPORT, &client->dev,
"wrote %zd bytes at %#04x: %d (%*ph)\n",
len, commandcode, retval, (int)len, buf);
return retval;
}
static int rmi_smb_get_command_code(struct rmi_transport_dev *xport,
u16 rmiaddr, int bytecount, bool isread, u8 *commandcode)
{
struct rmi_smb_xport *rmi_smb =
container_of(xport, struct rmi_smb_xport, xport);
int i;
int retval;
struct mapping_table_entry mapping_data[1];
mutex_lock(&rmi_smb->mappingtable_mutex);
for (i = 0; i < RMI_SMB2_MAP_SIZE; i++) {
if (rmi_smb->mapping_table[i].rmiaddr == rmiaddr) {
if (isread) {
if (rmi_smb->mapping_table[i].readcount
== bytecount) {
*commandcode = i;
retval = 0;
goto exit;
}
} else {
if (rmi_smb->mapping_table[i].flags &
RMI_SMB2_MAP_FLAGS_WE) {
*commandcode = i;
retval = 0;
goto exit;
}
}
}
}
i = rmi_smb->table_index;
rmi_smb->table_index = (i + 1) % RMI_SMB2_MAP_SIZE;
memset(mapping_data, 0, sizeof(mapping_data));
mapping_data[0].rmiaddr = cpu_to_le16(rmiaddr);
mapping_data[0].readcount = bytecount;
mapping_data[0].flags = !isread ? RMI_SMB2_MAP_FLAGS_WE : 0;
retval = smb_block_write(xport, i + 0x80, mapping_data,
sizeof(mapping_data));
if (retval < 0) {
rmi_smb->mapping_table[i].rmiaddr = 0x0000;
rmi_smb->mapping_table[i].readcount = 0;
rmi_smb->mapping_table[i].flags = 0;
goto exit;
}
rmi_smb->mapping_table[i].rmiaddr = rmiaddr;
rmi_smb->mapping_table[i].readcount = bytecount;
rmi_smb->mapping_table[i].flags = !isread ? RMI_SMB2_MAP_FLAGS_WE : 0;
*commandcode = i;
exit:
mutex_unlock(&rmi_smb->mappingtable_mutex);
return retval;
}
static int rmi_smb_write_block(struct rmi_transport_dev *xport, u16 rmiaddr,
const void *databuff, size_t len)
{
int retval = 0;
u8 commandcode;
struct rmi_smb_xport *rmi_smb =
container_of(xport, struct rmi_smb_xport, xport);
int cur_len = (int)len;
mutex_lock(&rmi_smb->page_mutex);
while (cur_len > 0) {
int block_len = min_t(int, len, SMB_MAX_COUNT);
retval = rmi_smb_get_command_code(xport, rmiaddr, block_len,
false, &commandcode);
if (retval < 0)
goto exit;
retval = smb_block_write(xport, commandcode,
databuff, block_len);
if (retval < 0)
goto exit;
cur_len -= SMB_MAX_COUNT;
databuff += SMB_MAX_COUNT;
rmiaddr += SMB_MAX_COUNT;
}
exit:
mutex_unlock(&rmi_smb->page_mutex);
return retval;
}
static int smb_block_read(struct rmi_transport_dev *xport,
u8 commandcode, void *buf, size_t len)
{
struct rmi_smb_xport *rmi_smb =
container_of(xport, struct rmi_smb_xport, xport);
struct i2c_client *client = rmi_smb->client;
int retval;
retval = i2c_smbus_read_block_data(client, commandcode, buf);
if (retval < 0)
return retval;
return retval;
}
static int rmi_smb_read_block(struct rmi_transport_dev *xport, u16 rmiaddr,
void *databuff, size_t len)
{
struct rmi_smb_xport *rmi_smb =
container_of(xport, struct rmi_smb_xport, xport);
int retval;
u8 commandcode;
int cur_len = (int)len;
mutex_lock(&rmi_smb->page_mutex);
memset(databuff, 0, len);
while (cur_len > 0) {
int block_len = min_t(int, cur_len, SMB_MAX_COUNT);
retval = rmi_smb_get_command_code(xport, rmiaddr, block_len,
true, &commandcode);
if (retval < 0)
goto exit;
retval = smb_block_read(xport, commandcode,
databuff, block_len);
if (retval < 0)
goto exit;
cur_len -= SMB_MAX_COUNT;
databuff += SMB_MAX_COUNT;
rmiaddr += SMB_MAX_COUNT;
}
retval = 0;
exit:
mutex_unlock(&rmi_smb->page_mutex);
return retval;
}
static void rmi_smb_clear_state(struct rmi_smb_xport *rmi_smb)
{
mutex_lock(&rmi_smb->mappingtable_mutex);
memset(rmi_smb->mapping_table, 0, sizeof(rmi_smb->mapping_table));
mutex_unlock(&rmi_smb->mappingtable_mutex);
}
static int rmi_smb_enable_smbus_mode(struct rmi_smb_xport *rmi_smb)
{
int retval;
retval = rmi_smb_get_version(rmi_smb);
if (retval < 0)
return retval;
return 0;
}
static int rmi_smb_reset(struct rmi_transport_dev *xport, u16 reset_addr)
{
struct rmi_smb_xport *rmi_smb =
container_of(xport, struct rmi_smb_xport, xport);
rmi_smb_clear_state(rmi_smb);
return rmi_smb_enable_smbus_mode(rmi_smb);
}
static int rmi_smb_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct rmi_device_platform_data *pdata = dev_get_platdata(&client->dev);
struct rmi_smb_xport *rmi_smb;
int retval;
int smbus_version;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_READ_BLOCK_DATA |
I2C_FUNC_SMBUS_HOST_NOTIFY)) {
dev_err(&client->dev,
"adapter does not support required functionality.\n");
return -ENODEV;
}
if (client->irq <= 0) {
dev_err(&client->dev, "no IRQ provided, giving up.\n");
return client->irq ? client->irq : -ENODEV;
}
rmi_smb = devm_kzalloc(&client->dev, sizeof(struct rmi_smb_xport),
GFP_KERNEL);
if (!rmi_smb)
return -ENOMEM;
if (!pdata) {
dev_err(&client->dev, "no platform data, aborting\n");
return -ENOMEM;
}
rmi_dbg(RMI_DEBUG_XPORT, &client->dev, "Probing %s.\n",
dev_name(&client->dev));
rmi_smb->client = client;
mutex_init(&rmi_smb->page_mutex);
mutex_init(&rmi_smb->mappingtable_mutex);
rmi_smb->xport.dev = &client->dev;
rmi_smb->xport.pdata = *pdata;
rmi_smb->xport.pdata.irq = client->irq;
rmi_smb->xport.proto_name = "smb2";
rmi_smb->xport.ops = &rmi_smb_ops;
retval = rmi_smb_get_version(rmi_smb);
if (retval < 0)
return retval;
smbus_version = retval;
rmi_dbg(RMI_DEBUG_XPORT, &client->dev, "Smbus version is %d",
smbus_version);
if (smbus_version != 2) {
dev_err(&client->dev, "Unrecognized SMB version %d.\n",
smbus_version);
return -ENODEV;
}
i2c_set_clientdata(client, rmi_smb);
retval = rmi_register_transport_device(&rmi_smb->xport);
if (retval) {
dev_err(&client->dev, "Failed to register transport driver at 0x%.2X.\n",
client->addr);
i2c_set_clientdata(client, NULL);
return retval;
}
dev_info(&client->dev, "registered rmi smb driver at %#04x.\n",
client->addr);
return 0;
}
static int rmi_smb_remove(struct i2c_client *client)
{
struct rmi_smb_xport *rmi_smb = i2c_get_clientdata(client);
rmi_unregister_transport_device(&rmi_smb->xport);
return 0;
}
static int __maybe_unused rmi_smb_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct rmi_smb_xport *rmi_smb = i2c_get_clientdata(client);
int ret;
ret = rmi_driver_suspend(rmi_smb->xport.rmi_dev, true);
if (ret)
dev_warn(dev, "Failed to suspend device: %d\n", ret);
return ret;
}
static int __maybe_unused rmi_smb_runtime_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct rmi_smb_xport *rmi_smb = i2c_get_clientdata(client);
int ret;
ret = rmi_driver_suspend(rmi_smb->xport.rmi_dev, false);
if (ret)
dev_warn(dev, "Failed to suspend device: %d\n", ret);
return ret;
}
static int __maybe_unused rmi_smb_resume(struct device *dev)
{
struct i2c_client *client = container_of(dev, struct i2c_client, dev);
struct rmi_smb_xport *rmi_smb = i2c_get_clientdata(client);
struct rmi_device *rmi_dev = rmi_smb->xport.rmi_dev;
int ret;
rmi_smb_reset(&rmi_smb->xport, 0);
rmi_reset(rmi_dev);
ret = rmi_driver_resume(rmi_smb->xport.rmi_dev, true);
if (ret)
dev_warn(dev, "Failed to resume device: %d\n", ret);
return 0;
}
static int __maybe_unused rmi_smb_runtime_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct rmi_smb_xport *rmi_smb = i2c_get_clientdata(client);
int ret;
ret = rmi_driver_resume(rmi_smb->xport.rmi_dev, false);
if (ret)
dev_warn(dev, "Failed to resume device: %d\n", ret);
return 0;
}
