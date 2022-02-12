static int i2c_atmel_send(struct tpm_chip *chip, u8 *buf, size_t len)
{
struct priv_data *priv = dev_get_drvdata(&chip->dev);
struct i2c_client *client = to_i2c_client(chip->dev.parent);
s32 status;
priv->len = 0;
if (len <= 2)
return -EIO;
status = i2c_master_send(client, buf, len);
dev_dbg(&chip->dev,
"%s(buf=%*ph len=%0zx) -> sts=%d\n", __func__,
(int)min_t(size_t, 64, len), buf, len, status);
return status;
}
static int i2c_atmel_recv(struct tpm_chip *chip, u8 *buf, size_t count)
{
struct priv_data *priv = dev_get_drvdata(&chip->dev);
struct i2c_client *client = to_i2c_client(chip->dev.parent);
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
dev_dbg(&chip->dev,
"%s early(buf=%*ph count=%0zx) -> ret=%d\n", __func__,
(int)min_t(size_t, 64, expected_len), buf, count,
expected_len);
memcpy(buf, priv->buffer, expected_len);
return expected_len;
}
rc = i2c_master_recv(client, buf, expected_len);
dev_dbg(&chip->dev,
"%s reread(buf=%*ph count=%0zx) -> ret=%d\n", __func__,
(int)min_t(size_t, 64, expected_len), buf, count,
expected_len);
return rc;
}
static void i2c_atmel_cancel(struct tpm_chip *chip)
{
dev_err(&chip->dev, "TPM operation cancellation was requested, but is not supported");
}
static u8 i2c_atmel_read_status(struct tpm_chip *chip)
{
struct priv_data *priv = dev_get_drvdata(&chip->dev);
struct i2c_client *client = to_i2c_client(chip->dev.parent);
int rc;
priv->len = 0;
memset(priv->buffer, 0, sizeof(priv->buffer));
rc = i2c_master_recv(client, priv->buffer, sizeof(priv->buffer));
dev_dbg(&chip->dev,
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
struct tpm_chip *chip;
struct device *dev = &client->dev;
struct priv_data *priv;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C))
return -ENODEV;
chip = tpmm_chip_alloc(dev, &i2c_atmel);
if (IS_ERR(chip))
return PTR_ERR(chip);
priv = devm_kzalloc(dev, sizeof(struct priv_data), GFP_KERNEL);
if (!priv)
return -ENOMEM;
chip->timeout_a = msecs_to_jiffies(TPM_I2C_SHORT_TIMEOUT);
chip->timeout_b = msecs_to_jiffies(TPM_I2C_LONG_TIMEOUT);
chip->timeout_c = msecs_to_jiffies(TPM_I2C_SHORT_TIMEOUT);
chip->timeout_d = msecs_to_jiffies(TPM_I2C_SHORT_TIMEOUT);
dev_set_drvdata(&chip->dev, priv);
return tpm_chip_register(chip);
}
static int i2c_atmel_remove(struct i2c_client *client)
{
struct device *dev = &(client->dev);
struct tpm_chip *chip = dev_get_drvdata(dev);
tpm_chip_unregister(chip);
return 0;
}
