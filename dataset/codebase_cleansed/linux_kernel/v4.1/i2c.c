static int write8_reg(void *phy_id, u8 tpm_register, u8 *tpm_data, int tpm_size)
{
struct st33zp24_i2c_phy *phy = phy_id;
phy->buf[0] = tpm_register;
memcpy(phy->buf + 1, tpm_data, tpm_size);
return i2c_master_send(phy->client, phy->buf, tpm_size + 1);
}
static int read8_reg(void *phy_id, u8 tpm_register, u8 *tpm_data, int tpm_size)
{
struct st33zp24_i2c_phy *phy = phy_id;
u8 status = 0;
u8 data;
data = TPM_DUMMY_BYTE;
status = write8_reg(phy, tpm_register, &data, 1);
if (status == 2)
status = i2c_master_recv(phy->client, tpm_data, tpm_size);
return status;
}
static int st33zp24_i2c_send(void *phy_id, u8 tpm_register, u8 *tpm_data,
int tpm_size)
{
return write8_reg(phy_id, tpm_register | TPM_WRITE_DIRECTION, tpm_data,
tpm_size);
}
static int st33zp24_i2c_recv(void *phy_id, u8 tpm_register, u8 *tpm_data,
int tpm_size)
{
return read8_reg(phy_id, tpm_register, tpm_data, tpm_size);
}
static int st33zp24_i2c_of_request_resources(struct st33zp24_i2c_phy *phy)
{
struct device_node *pp;
struct i2c_client *client = phy->client;
int gpio;
int ret;
pp = client->dev.of_node;
if (!pp) {
dev_err(&client->dev, "No platform data\n");
return -ENODEV;
}
gpio = of_get_named_gpio(pp, "lpcpd-gpios", 0);
if (gpio < 0) {
dev_err(&client->dev,
"Failed to retrieve lpcpd-gpios from dts.\n");
phy->io_lpcpd = -1;
return 0;
}
ret = devm_gpio_request_one(&client->dev, gpio,
GPIOF_OUT_INIT_HIGH, "TPM IO LPCPD");
if (ret) {
dev_err(&client->dev, "Failed to request lpcpd pin\n");
return -ENODEV;
}
phy->io_lpcpd = gpio;
return 0;
}
static int st33zp24_i2c_of_request_resources(struct st33zp24_i2c_phy *phy)
{
return -ENODEV;
}
static int st33zp24_i2c_request_resources(struct i2c_client *client,
struct st33zp24_i2c_phy *phy)
{
struct st33zp24_platform_data *pdata;
int ret;
pdata = client->dev.platform_data;
if (!pdata) {
dev_err(&client->dev, "No platform data\n");
return -ENODEV;
}
phy->io_lpcpd = pdata->io_lpcpd;
if (gpio_is_valid(pdata->io_lpcpd)) {
ret = devm_gpio_request_one(&client->dev,
pdata->io_lpcpd, GPIOF_OUT_INIT_HIGH,
"TPM IO_LPCPD");
if (ret) {
dev_err(&client->dev, "Failed to request lpcpd pin\n");
return ret;
}
}
return 0;
}
static int st33zp24_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret;
struct st33zp24_platform_data *pdata;
struct st33zp24_i2c_phy *phy;
if (!client) {
pr_info("%s: i2c client is NULL. Device not accessible.\n",
__func__);
return -ENODEV;
}
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
dev_info(&client->dev, "client not i2c capable\n");
return -ENODEV;
}
phy = devm_kzalloc(&client->dev, sizeof(struct st33zp24_i2c_phy),
GFP_KERNEL);
if (!phy)
return -ENOMEM;
phy->client = client;
pdata = client->dev.platform_data;
if (!pdata && client->dev.of_node) {
ret = st33zp24_i2c_of_request_resources(phy);
if (ret)
return ret;
} else if (pdata) {
ret = st33zp24_i2c_request_resources(client, phy);
if (ret)
return ret;
}
return st33zp24_probe(phy, &i2c_phy_ops, &client->dev, client->irq,
phy->io_lpcpd);
}
static int st33zp24_i2c_remove(struct i2c_client *client)
{
struct tpm_chip *chip = i2c_get_clientdata(client);
return st33zp24_remove(chip);
}
