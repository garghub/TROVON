static u16 atmel_ecc_crc16(u16 crc, const u8 *buffer, size_t len)
{
return cpu_to_le16(bitrev16(crc16(crc, buffer, len)));
}
static void atmel_ecc_checksum(struct atmel_ecc_cmd *cmd)
{
u8 *data = &cmd->count;
size_t len = cmd->count - CRC_SIZE;
u16 *crc16 = (u16 *)(data + len);
*crc16 = atmel_ecc_crc16(0, data, len);
}
static void atmel_ecc_init_read_cmd(struct atmel_ecc_cmd *cmd)
{
cmd->word_addr = COMMAND;
cmd->opcode = OPCODE_READ;
cmd->param1 = CONFIG_ZONE;
cmd->param2 = DEVICE_LOCK_ADDR;
cmd->count = READ_COUNT;
atmel_ecc_checksum(cmd);
cmd->msecs = MAX_EXEC_TIME_READ;
cmd->rxsize = READ_RSP_SIZE;
}
static void atmel_ecc_init_genkey_cmd(struct atmel_ecc_cmd *cmd, u16 keyid)
{
cmd->word_addr = COMMAND;
cmd->count = GENKEY_COUNT;
cmd->opcode = OPCODE_GENKEY;
cmd->param1 = GENKEY_MODE_PRIVATE;
cmd->param2 = cpu_to_le16(keyid);
atmel_ecc_checksum(cmd);
cmd->msecs = MAX_EXEC_TIME_GENKEY;
cmd->rxsize = GENKEY_RSP_SIZE;
}
static int atmel_ecc_init_ecdh_cmd(struct atmel_ecc_cmd *cmd,
struct scatterlist *pubkey)
{
size_t copied;
cmd->word_addr = COMMAND;
cmd->count = ECDH_COUNT;
cmd->opcode = OPCODE_ECDH;
cmd->param1 = ECDH_PREFIX_MODE;
cmd->param2 = cpu_to_le16(DATA_SLOT_2);
copied = sg_copy_to_buffer(pubkey, 1, cmd->data, ATMEL_ECC_PUBKEY_SIZE);
if (copied != ATMEL_ECC_PUBKEY_SIZE)
return -EINVAL;
atmel_ecc_checksum(cmd);
cmd->msecs = MAX_EXEC_TIME_ECDH;
cmd->rxsize = ECDH_RSP_SIZE;
return 0;
}
static int atmel_ecc_status(struct device *dev, u8 *status)
{
size_t err_list_len = ARRAY_SIZE(error_list);
int i;
u8 err_id = status[1];
if (*status != STATUS_SIZE)
return 0;
if (err_id == STATUS_WAKE_SUCCESSFUL || err_id == STATUS_NOERR)
return 0;
for (i = 0; i < err_list_len; i++)
if (error_list[i].value == err_id)
break;
if (i != err_list_len) {
dev_err(dev, "%02x: %s:\n", err_id, error_list[i].error_text);
return err_id;
}
return 0;
}
static int atmel_ecc_wakeup(struct i2c_client *client)
{
struct atmel_ecc_i2c_client_priv *i2c_priv = i2c_get_clientdata(client);
u8 status[STATUS_RSP_SIZE];
int ret;
i2c_master_send(client, i2c_priv->wake_token, i2c_priv->wake_token_sz);
usleep_range(TWHI_MIN, TWHI_MAX);
ret = i2c_master_recv(client, status, STATUS_SIZE);
if (ret < 0)
return ret;
return atmel_ecc_status(&client->dev, status);
}
static int atmel_ecc_sleep(struct i2c_client *client)
{
u8 sleep = SLEEP_TOKEN;
return i2c_master_send(client, &sleep, 1);
}
static void atmel_ecdh_done(struct atmel_ecc_work_data *work_data, void *areq,
int status)
{
struct kpp_request *req = areq;
struct atmel_ecdh_ctx *ctx = work_data->ctx;
struct atmel_ecc_cmd *cmd = &work_data->cmd;
size_t copied;
size_t n_sz = ctx->n_sz;
if (status)
goto free_work_data;
copied = sg_copy_from_buffer(req->dst, 1, &cmd->data[RSP_DATA_IDX],
n_sz);
if (copied != n_sz)
status = -EINVAL;
free_work_data:
kzfree(work_data);
kpp_request_complete(req, status);
}
static int atmel_ecc_send_receive(struct i2c_client *client,
struct atmel_ecc_cmd *cmd)
{
struct atmel_ecc_i2c_client_priv *i2c_priv = i2c_get_clientdata(client);
int ret;
mutex_lock(&i2c_priv->lock);
ret = atmel_ecc_wakeup(client);
if (ret)
goto err;
ret = i2c_master_send(client, (u8 *)cmd, cmd->count + WORD_ADDR_SIZE);
if (ret < 0)
goto err;
msleep(cmd->msecs);
ret = i2c_master_recv(client, cmd->data, cmd->rxsize);
if (ret < 0)
goto err;
ret = atmel_ecc_sleep(client);
if (ret < 0)
goto err;
mutex_unlock(&i2c_priv->lock);
return atmel_ecc_status(&client->dev, cmd->data);
err:
mutex_unlock(&i2c_priv->lock);
return ret;
}
static void atmel_ecc_work_handler(struct work_struct *work)
{
struct atmel_ecc_work_data *work_data =
container_of(work, struct atmel_ecc_work_data, work);
struct atmel_ecc_cmd *cmd = &work_data->cmd;
struct i2c_client *client = work_data->ctx->client;
int status;
status = atmel_ecc_send_receive(client, cmd);
work_data->cbk(work_data, work_data->areq, status);
}
static void atmel_ecc_enqueue(struct atmel_ecc_work_data *work_data,
void (*cbk)(struct atmel_ecc_work_data *work_data,
void *areq, int status),
void *areq)
{
work_data->cbk = (void *)cbk;
work_data->areq = areq;
INIT_WORK(&work_data->work, atmel_ecc_work_handler);
schedule_work(&work_data->work);
}
static unsigned int atmel_ecdh_supported_curve(unsigned int curve_id)
{
if (curve_id == ECC_CURVE_NIST_P256)
return ATMEL_ECC_NIST_P256_N_SIZE;
return 0;
}
static int atmel_ecdh_set_secret(struct crypto_kpp *tfm, const void *buf,
unsigned int len)
{
struct atmel_ecdh_ctx *ctx = kpp_tfm_ctx(tfm);
struct atmel_ecc_cmd *cmd;
void *public_key;
struct ecdh params;
int ret = -ENOMEM;
kfree(ctx->public_key);
ctx->public_key = NULL;
if (crypto_ecdh_decode_key(buf, len, &params) < 0) {
dev_err(&ctx->client->dev, "crypto_ecdh_decode_key failed\n");
return -EINVAL;
}
ctx->n_sz = atmel_ecdh_supported_curve(params.curve_id);
if (!ctx->n_sz || params.key_size) {
ctx->do_fallback = true;
return crypto_kpp_set_secret(ctx->fallback, buf, len);
}
cmd = kmalloc(sizeof(*cmd), GFP_KERNEL);
if (!cmd)
return -ENOMEM;
public_key = kmalloc(ATMEL_ECC_PUBKEY_SIZE, GFP_KERNEL);
if (!public_key)
goto free_cmd;
ctx->do_fallback = false;
ctx->curve_id = params.curve_id;
atmel_ecc_init_genkey_cmd(cmd, DATA_SLOT_2);
ret = atmel_ecc_send_receive(ctx->client, cmd);
if (ret)
goto free_public_key;
memcpy(public_key, &cmd->data[RSP_DATA_IDX], ATMEL_ECC_PUBKEY_SIZE);
ctx->public_key = public_key;
kfree(cmd);
return 0;
free_public_key:
kfree(public_key);
free_cmd:
kfree(cmd);
return ret;
}
static int atmel_ecdh_generate_public_key(struct kpp_request *req)
{
struct crypto_kpp *tfm = crypto_kpp_reqtfm(req);
struct atmel_ecdh_ctx *ctx = kpp_tfm_ctx(tfm);
size_t copied;
int ret = 0;
if (ctx->do_fallback) {
kpp_request_set_tfm(req, ctx->fallback);
return crypto_kpp_generate_public_key(req);
}
copied = sg_copy_from_buffer(req->dst, 1, ctx->public_key,
ATMEL_ECC_PUBKEY_SIZE);
if (copied != ATMEL_ECC_PUBKEY_SIZE)
ret = -EINVAL;
return ret;
}
static int atmel_ecdh_compute_shared_secret(struct kpp_request *req)
{
struct crypto_kpp *tfm = crypto_kpp_reqtfm(req);
struct atmel_ecdh_ctx *ctx = kpp_tfm_ctx(tfm);
struct atmel_ecc_work_data *work_data;
gfp_t gfp;
int ret;
if (ctx->do_fallback) {
kpp_request_set_tfm(req, ctx->fallback);
return crypto_kpp_compute_shared_secret(req);
}
gfp = (req->base.flags & CRYPTO_TFM_REQ_MAY_SLEEP) ? GFP_KERNEL :
GFP_ATOMIC;
work_data = kmalloc(sizeof(*work_data), gfp);
if (!work_data)
return -ENOMEM;
work_data->ctx = ctx;
ret = atmel_ecc_init_ecdh_cmd(&work_data->cmd, req->src);
if (ret)
goto free_work_data;
atmel_ecc_enqueue(work_data, atmel_ecdh_done, req);
return -EINPROGRESS;
free_work_data:
kfree(work_data);
return ret;
}
static struct i2c_client *atmel_ecc_i2c_client_alloc(void)
{
struct atmel_ecc_i2c_client_priv *i2c_priv, *min_i2c_priv = NULL;
struct i2c_client *client = ERR_PTR(-ENODEV);
int min_tfm_cnt = INT_MAX;
int tfm_cnt;
spin_lock(&driver_data.i2c_list_lock);
if (list_empty(&driver_data.i2c_client_list)) {
spin_unlock(&driver_data.i2c_list_lock);
return ERR_PTR(-ENODEV);
}
list_for_each_entry(i2c_priv, &driver_data.i2c_client_list,
i2c_client_list_node) {
tfm_cnt = atomic_read(&i2c_priv->tfm_count);
if (tfm_cnt < min_tfm_cnt) {
min_tfm_cnt = tfm_cnt;
min_i2c_priv = i2c_priv;
}
if (!min_tfm_cnt)
break;
}
if (min_i2c_priv) {
atomic_inc(&min_i2c_priv->tfm_count);
client = min_i2c_priv->client;
}
spin_unlock(&driver_data.i2c_list_lock);
return client;
}
static void atmel_ecc_i2c_client_free(struct i2c_client *client)
{
struct atmel_ecc_i2c_client_priv *i2c_priv = i2c_get_clientdata(client);
atomic_dec(&i2c_priv->tfm_count);
}
static int atmel_ecdh_init_tfm(struct crypto_kpp *tfm)
{
const char *alg = kpp_alg_name(tfm);
struct crypto_kpp *fallback;
struct atmel_ecdh_ctx *ctx = kpp_tfm_ctx(tfm);
ctx->client = atmel_ecc_i2c_client_alloc();
if (IS_ERR(ctx->client)) {
pr_err("tfm - i2c_client binding failed\n");
return PTR_ERR(ctx->client);
}
fallback = crypto_alloc_kpp(alg, 0, CRYPTO_ALG_NEED_FALLBACK);
if (IS_ERR(fallback)) {
dev_err(&ctx->client->dev, "Failed to allocate transformation for '%s': %ld\n",
alg, PTR_ERR(fallback));
return PTR_ERR(fallback);
}
crypto_kpp_set_flags(fallback, crypto_kpp_get_flags(tfm));
dev_info(&ctx->client->dev, "Using '%s' as fallback implementation.\n",
crypto_tfm_alg_driver_name(crypto_kpp_tfm(fallback)));
ctx->fallback = fallback;
return 0;
}
static void atmel_ecdh_exit_tfm(struct crypto_kpp *tfm)
{
struct atmel_ecdh_ctx *ctx = kpp_tfm_ctx(tfm);
kfree(ctx->public_key);
crypto_free_kpp(ctx->fallback);
atmel_ecc_i2c_client_free(ctx->client);
}
static unsigned int atmel_ecdh_max_size(struct crypto_kpp *tfm)
{
struct atmel_ecdh_ctx *ctx = kpp_tfm_ctx(tfm);
if (ctx->fallback)
return crypto_kpp_maxsize(ctx->fallback);
return ATMEL_ECC_PUBKEY_SIZE;
}
static inline size_t atmel_ecc_wake_token_sz(u32 bus_clk_rate)
{
u32 no_of_bits = DIV_ROUND_UP(TWLO_USEC * bus_clk_rate, USEC_PER_SEC);
return DIV_ROUND_UP(no_of_bits, 8);
}
static int device_sanity_check(struct i2c_client *client)
{
struct atmel_ecc_cmd *cmd;
int ret;
cmd = kmalloc(sizeof(*cmd), GFP_KERNEL);
if (!cmd)
return -ENOMEM;
atmel_ecc_init_read_cmd(cmd);
ret = atmel_ecc_send_receive(client, cmd);
if (ret)
goto free_cmd;
if (cmd->data[LOCK_CONFIG_IDX] || cmd->data[LOCK_VALUE_IDX]) {
dev_err(&client->dev, "Configuration or Data and OTP zones are unlocked!\n");
ret = -ENOTSUPP;
}
free_cmd:
kfree(cmd);
return ret;
}
static int atmel_ecc_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct atmel_ecc_i2c_client_priv *i2c_priv;
struct device *dev = &client->dev;
int ret;
u32 bus_clk_rate;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
dev_err(dev, "I2C_FUNC_I2C not supported\n");
return -ENODEV;
}
ret = of_property_read_u32(client->adapter->dev.of_node,
"clock-frequency", &bus_clk_rate);
if (ret) {
dev_err(dev, "of: failed to read clock-frequency property\n");
return ret;
}
if (bus_clk_rate > 1000000L) {
dev_err(dev, "%d exceeds maximum supported clock frequency (1MHz)\n",
bus_clk_rate);
return -EINVAL;
}
i2c_priv = devm_kmalloc(dev, sizeof(*i2c_priv), GFP_KERNEL);
if (!i2c_priv)
return -ENOMEM;
i2c_priv->client = client;
mutex_init(&i2c_priv->lock);
i2c_priv->wake_token_sz = atmel_ecc_wake_token_sz(bus_clk_rate);
memset(i2c_priv->wake_token, 0, sizeof(i2c_priv->wake_token));
atomic_set(&i2c_priv->tfm_count, 0);
i2c_set_clientdata(client, i2c_priv);
ret = device_sanity_check(client);
if (ret)
return ret;
spin_lock(&driver_data.i2c_list_lock);
list_add_tail(&i2c_priv->i2c_client_list_node,
&driver_data.i2c_client_list);
spin_unlock(&driver_data.i2c_list_lock);
ret = crypto_register_kpp(&atmel_ecdh);
if (ret) {
spin_lock(&driver_data.i2c_list_lock);
list_del(&i2c_priv->i2c_client_list_node);
spin_unlock(&driver_data.i2c_list_lock);
dev_err(dev, "%s alg registration failed\n",
atmel_ecdh.base.cra_driver_name);
} else {
dev_info(dev, "atmel ecc algorithms registered in /proc/crypto\n");
}
return ret;
}
static int atmel_ecc_remove(struct i2c_client *client)
{
struct atmel_ecc_i2c_client_priv *i2c_priv = i2c_get_clientdata(client);
if (atomic_read(&i2c_priv->tfm_count)) {
dev_err(&client->dev, "Device is busy\n");
return -EBUSY;
}
crypto_unregister_kpp(&atmel_ecdh);
spin_lock(&driver_data.i2c_list_lock);
list_del(&i2c_priv->i2c_client_list_node);
spin_unlock(&driver_data.i2c_list_lock);
return 0;
}
static int __init atmel_ecc_init(void)
{
spin_lock_init(&driver_data.i2c_list_lock);
INIT_LIST_HEAD(&driver_data.i2c_client_list);
return i2c_add_driver(&atmel_ecc_driver);
}
static void __exit atmel_ecc_exit(void)
{
flush_scheduled_work();
i2c_del_driver(&atmel_ecc_driver);
}
