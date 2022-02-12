static int i2c_atmel_send(struct tpm_chip *chip, u8 *buf, size_t len)
{
struct priv_data *priv = chip->vendor.priv;
struct i2c_client *client = to_i2c_client(chip->dev);
s32 status;
priv->len = 0;
if (len <= 2)
return -EIO;
status = i2c_master_send(client, buf, len);
dev_dbg(chip->dev,
"%s(buf=%*ph len=%0zx) -> sts=%d\n", __func__,
(int)min_t(size_t, 64, len), buf, len, status);
return status;
}
static int i2c_atmel_recv(struct tpm_chip *chip, u8 *buf, size_t count)
{
struct priv_data *priv = chip->vendor.priv;
struct i2c_client *client = to_i2c_client(chip->dev);
struct tpm_output_header *hdr =
(struct tpm_output_header *)priv->buffer;
u32 expected_len;
int rc;
if (priv->len == 0)
return -EIO;
expected_len = be32_to_cpu(hdr->length);
if (expected_len > count)
return -ENOMEM;
if (priv->len >= expected_len) {
dev_dbg(chip->dev,
"%s early(buf=%*ph count=%0zx) -> ret=%d\n", __func__,
(int)min_t(size_t, 64, expected_len), buf, count,
expected_len);
memcpy(buf, priv->buffer, expected_len);
return expected_len;
}
rc = i2c_master_recv(client, buf, expected_len);
dev_dbg(chip->dev,
"%s reread(buf=%*ph count=%0zx) -> ret=%d\n", __func__,
(int)min_t(size_t, 64, expected_len), buf, count,
expected_len);
return rc;
}
static void i2c_atmel_cancel(struct tpm_chip *chip)
{
dev_err(chip->dev, "TPM operation cancellation was requested, but is not supported");
}
static u8 i2c_atmel_read_status(struct tpm_chip *chip)
{
struct priv_data *priv = chip->vendor.priv;
struct i2c_client *client = to_i2c_client(chip->dev);
int rc;
priv->len = 0;
memset(priv->buffer, 0, sizeof(priv->buffer));
rc = i2c_master_recv(client, priv->buffer, sizeof(priv->buffer));
dev_dbg(chip->dev,
"%s: sts=%d", __func__, rc);
if (rc <= 0)
return 0;
priv->len = rc;
return ATMEL_STS_OK;
}
static bool i2c_atmel_req_canceled(struct tpm_chip *chip, u8 status)
{
return false;
}
static int i2c_atmel_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int rc;
struct tpm_chip *chip;
struct device *dev = &client->dev;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
return -ENODEV;
chip = tpm_register_hardware(dev, &i2c_atmel);
if (!chip) {
dev_err(dev, "%s() error in tpm_register_hardware\n", __func__);
return -ENODEV;
}
chip->vendor.priv = devm_kzalloc(dev, sizeof(struct priv_data),
GFP_KERNEL);
chip->vendor.timeout_a = msecs_to_jiffies(TPM_I2C_SHORT_TIMEOUT);
chip->vendor.timeout_b = msecs_to_jiffies(TPM_I2C_LONG_TIMEOUT);
chip->vendor.timeout_c = msecs_to_jiffies(TPM_I2C_SHORT_TIMEOUT);
chip->vendor.timeout_d = msecs_to_jiffies(TPM_I2C_SHORT_TIMEOUT);
chip->vendor.irq = 0;
if (tpm_get_timeouts(chip)) {
rc = -ENODEV;
goto out_err;
}
if (tpm_do_selftest(chip)) {
rc = -ENODEV;
goto out_err;
}
return 0;
out_err:
tpm_dev_vendor_release(chip);
tpm_remove_hardware(chip->dev);
return rc;
}
static int i2c_atmel_remove(struct i2c_client *client)
{
struct device *dev = &(client->dev);
struct tpm_chip *chip = dev_get_drvdata(dev);
if (chip)
tpm_dev_vendor_release(chip);
tpm_remove_hardware(dev);
kfree(chip);
return 0;
}
