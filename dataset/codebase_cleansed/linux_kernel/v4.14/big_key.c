static int big_key_crypt(enum big_key_op op, u8 *data, size_t datalen, u8 *key)
{
int ret;
struct scatterlist sgio;
struct aead_request *aead_req;
u8 zero_nonce[crypto_aead_ivsize(big_key_aead)];
aead_req = aead_request_alloc(big_key_aead, GFP_KERNEL);
if (!aead_req)
return -ENOMEM;
memset(zero_nonce, 0, sizeof(zero_nonce));
sg_init_one(&sgio, data, datalen + (op == BIG_KEY_ENC ? ENC_AUTHTAG_SIZE : 0));
aead_request_set_crypt(aead_req, &sgio, &sgio, datalen, zero_nonce);
aead_request_set_callback(aead_req, CRYPTO_TFM_REQ_MAY_SLEEP, NULL, NULL);
aead_request_set_ad(aead_req, 0);
mutex_lock(&big_key_aead_lock);
if (crypto_aead_setkey(big_key_aead, key, ENC_KEY_SIZE)) {
ret = -EAGAIN;
goto error;
}
if (op == BIG_KEY_ENC)
ret = crypto_aead_encrypt(aead_req);
else
ret = crypto_aead_decrypt(aead_req);
error:
mutex_unlock(&big_key_aead_lock);
aead_request_free(aead_req);
return ret;
}
int big_key_preparse(struct key_preparsed_payload *prep)
{
struct path *path = (struct path *)&prep->payload.data[big_key_path];
struct file *file;
u8 *enckey;
u8 *data = NULL;
ssize_t written;
size_t datalen = prep->datalen;
int ret;
ret = -EINVAL;
if (datalen <= 0 || datalen > 1024 * 1024 || !prep->data)
goto error;
prep->quotalen = 16;
prep->payload.data[big_key_len] = (void *)(unsigned long)datalen;
if (datalen > BIG_KEY_FILE_THRESHOLD) {
size_t enclen = datalen + ENC_AUTHTAG_SIZE;
loff_t pos = 0;
data = kmalloc(enclen, GFP_KERNEL);
if (!data)
return -ENOMEM;
memcpy(data, prep->data, datalen);
enckey = kmalloc(ENC_KEY_SIZE, GFP_KERNEL);
if (!enckey) {
ret = -ENOMEM;
goto error;
}
ret = get_random_bytes_wait(enckey, ENC_KEY_SIZE);
if (unlikely(ret))
goto err_enckey;
ret = big_key_crypt(BIG_KEY_ENC, data, datalen, enckey);
if (ret)
goto err_enckey;
file = shmem_kernel_file_setup("", enclen, 0);
if (IS_ERR(file)) {
ret = PTR_ERR(file);
goto err_enckey;
}
written = kernel_write(file, data, enclen, &pos);
if (written != enclen) {
ret = written;
if (written >= 0)
ret = -ENOMEM;
goto err_fput;
}
prep->payload.data[big_key_data] = enckey;
*path = file->f_path;
path_get(path);
fput(file);
kzfree(data);
} else {
void *data = kmalloc(datalen, GFP_KERNEL);
if (!data)
return -ENOMEM;
prep->payload.data[big_key_data] = data;
memcpy(data, prep->data, prep->datalen);
}
return 0;
err_fput:
fput(file);
err_enckey:
kzfree(enckey);
error:
kzfree(data);
return ret;
}
void big_key_free_preparse(struct key_preparsed_payload *prep)
{
if (prep->datalen > BIG_KEY_FILE_THRESHOLD) {
struct path *path = (struct path *)&prep->payload.data[big_key_path];
path_put(path);
}
kzfree(prep->payload.data[big_key_data]);
}
void big_key_revoke(struct key *key)
{
struct path *path = (struct path *)&key->payload.data[big_key_path];
key_payload_reserve(key, 0);
if (key_is_positive(key) &&
(size_t)key->payload.data[big_key_len] > BIG_KEY_FILE_THRESHOLD)
vfs_truncate(path, 0);
}
void big_key_destroy(struct key *key)
{
size_t datalen = (size_t)key->payload.data[big_key_len];
if (datalen > BIG_KEY_FILE_THRESHOLD) {
struct path *path = (struct path *)&key->payload.data[big_key_path];
path_put(path);
path->mnt = NULL;
path->dentry = NULL;
}
kzfree(key->payload.data[big_key_data]);
key->payload.data[big_key_data] = NULL;
}
void big_key_describe(const struct key *key, struct seq_file *m)
{
size_t datalen = (size_t)key->payload.data[big_key_len];
seq_puts(m, key->description);
if (key_is_positive(key))
seq_printf(m, ": %zu [%s]",
datalen,
datalen > BIG_KEY_FILE_THRESHOLD ? "file" : "buff");
}
long big_key_read(const struct key *key, char __user *buffer, size_t buflen)
{
size_t datalen = (size_t)key->payload.data[big_key_len];
long ret;
if (!buffer || buflen < datalen)
return datalen;
if (datalen > BIG_KEY_FILE_THRESHOLD) {
struct path *path = (struct path *)&key->payload.data[big_key_path];
struct file *file;
u8 *data;
u8 *enckey = (u8 *)key->payload.data[big_key_data];
size_t enclen = datalen + ENC_AUTHTAG_SIZE;
loff_t pos = 0;
data = kmalloc(enclen, GFP_KERNEL);
if (!data)
return -ENOMEM;
file = dentry_open(path, O_RDONLY, current_cred());
if (IS_ERR(file)) {
ret = PTR_ERR(file);
goto error;
}
ret = kernel_read(file, data, enclen, &pos);
if (ret >= 0 && ret != enclen) {
ret = -EIO;
goto err_fput;
}
ret = big_key_crypt(BIG_KEY_DEC, data, enclen, enckey);
if (ret)
goto err_fput;
ret = datalen;
if (copy_to_user(buffer, data, datalen) != 0)
ret = -EFAULT;
err_fput:
fput(file);
error:
kzfree(data);
} else {
ret = datalen;
if (copy_to_user(buffer, key->payload.data[big_key_data],
datalen) != 0)
ret = -EFAULT;
}
return ret;
}
static int __init big_key_init(void)
{
int ret;
big_key_aead = crypto_alloc_aead(big_key_alg_name, 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(big_key_aead)) {
ret = PTR_ERR(big_key_aead);
pr_err("Can't alloc crypto: %d\n", ret);
return ret;
}
ret = crypto_aead_setauthsize(big_key_aead, ENC_AUTHTAG_SIZE);
if (ret < 0) {
pr_err("Can't set crypto auth tag len: %d\n", ret);
goto free_aead;
}
ret = register_key_type(&key_type_big_key);
if (ret < 0) {
pr_err("Can't register type: %d\n", ret);
goto free_aead;
}
return 0;
free_aead:
crypto_free_aead(big_key_aead);
return ret;
}
