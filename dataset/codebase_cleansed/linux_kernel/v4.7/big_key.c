static inline int big_key_gen_enckey(u8 *key)
{
return crypto_rng_get_bytes(big_key_rng, key, ENC_KEY_SIZE);
}
static int big_key_crypt(enum big_key_op op, u8 *data, size_t datalen, u8 *key)
{
int ret = -EINVAL;
struct scatterlist sgio;
struct blkcipher_desc desc;
if (crypto_blkcipher_setkey(big_key_blkcipher, key, ENC_KEY_SIZE)) {
ret = -EAGAIN;
goto error;
}
desc.flags = 0;
desc.tfm = big_key_blkcipher;
sg_init_one(&sgio, data, datalen);
if (op == BIG_KEY_ENC)
ret = crypto_blkcipher_encrypt(&desc, &sgio, &sgio, datalen);
else
ret = crypto_blkcipher_decrypt(&desc, &sgio, &sgio, datalen);
error:
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
size_t enclen = ALIGN(datalen, crypto_blkcipher_blocksize(big_key_blkcipher));
data = kmalloc(enclen, GFP_KERNEL);
if (!data)
return -ENOMEM;
memcpy(data, prep->data, datalen);
memset(data + datalen, 0x00, enclen - datalen);
enckey = kmalloc(ENC_KEY_SIZE, GFP_KERNEL);
if (!enckey) {
ret = -ENOMEM;
goto error;
}
ret = big_key_gen_enckey(enckey);
if (ret)
goto err_enckey;
ret = big_key_crypt(BIG_KEY_ENC, data, enclen, enckey);
if (ret)
goto err_enckey;
file = shmem_kernel_file_setup("", enclen, 0);
if (IS_ERR(file)) {
ret = PTR_ERR(file);
goto err_enckey;
}
written = kernel_write(file, data, enclen, 0);
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
kfree(data);
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
kfree(enckey);
error:
kfree(data);
return ret;
}
void big_key_free_preparse(struct key_preparsed_payload *prep)
{
if (prep->datalen > BIG_KEY_FILE_THRESHOLD) {
struct path *path = (struct path *)&prep->payload.data[big_key_path];
path_put(path);
}
kfree(prep->payload.data[big_key_data]);
}
void big_key_revoke(struct key *key)
{
struct path *path = (struct path *)&key->payload.data[big_key_path];
key_payload_reserve(key, 0);
if (key_is_instantiated(key) &&
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
kfree(key->payload.data[big_key_data]);
key->payload.data[big_key_data] = NULL;
}
void big_key_describe(const struct key *key, struct seq_file *m)
{
size_t datalen = (size_t)key->payload.data[big_key_len];
seq_puts(m, key->description);
if (key_is_instantiated(key))
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
size_t enclen = ALIGN(datalen, crypto_blkcipher_blocksize(big_key_blkcipher));
data = kmalloc(enclen, GFP_KERNEL);
if (!data)
return -ENOMEM;
file = dentry_open(path, O_RDONLY, current_cred());
if (IS_ERR(file)) {
ret = PTR_ERR(file);
goto error;
}
ret = kernel_read(file, 0, data, enclen);
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
kfree(data);
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
return register_key_type(&key_type_big_key);
}
static int __init big_key_crypto_init(void)
{
int ret = -EINVAL;
big_key_rng = crypto_alloc_rng(big_key_rng_name, 0, 0);
if (IS_ERR(big_key_rng)) {
big_key_rng = NULL;
return -EFAULT;
}
ret = crypto_rng_reset(big_key_rng, NULL, crypto_rng_seedsize(big_key_rng));
if (ret)
goto error;
big_key_blkcipher = crypto_alloc_blkcipher(big_key_alg_name, 0, 0);
if (IS_ERR(big_key_blkcipher)) {
big_key_blkcipher = NULL;
ret = -EFAULT;
goto error;
}
return 0;
error:
crypto_free_rng(big_key_rng);
big_key_rng = NULL;
return ret;
}
