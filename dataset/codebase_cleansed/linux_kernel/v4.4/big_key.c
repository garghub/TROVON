int big_key_preparse(struct key_preparsed_payload *prep)
{
struct path *path = (struct path *)&prep->payload.data[big_key_path];
struct file *file;
ssize_t written;
size_t datalen = prep->datalen;
int ret;
ret = -EINVAL;
if (datalen <= 0 || datalen > 1024 * 1024 || !prep->data)
goto error;
prep->quotalen = 16;
prep->payload.data[big_key_len] = (void *)(unsigned long)datalen;
if (datalen > BIG_KEY_FILE_THRESHOLD) {
file = shmem_kernel_file_setup("", datalen, 0);
if (IS_ERR(file)) {
ret = PTR_ERR(file);
goto error;
}
written = kernel_write(file, prep->data, prep->datalen, 0);
if (written != datalen) {
ret = written;
if (written >= 0)
ret = -ENOMEM;
goto err_fput;
}
*path = file->f_path;
path_get(path);
fput(file);
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
error:
return ret;
}
void big_key_free_preparse(struct key_preparsed_payload *prep)
{
if (prep->datalen > BIG_KEY_FILE_THRESHOLD) {
struct path *path = (struct path *)&prep->payload.data[big_key_path];
path_put(path);
} else {
kfree(prep->payload.data[big_key_data]);
}
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
if (datalen) {
struct path *path = (struct path *)&key->payload.data[big_key_path];
path_put(path);
path->mnt = NULL;
path->dentry = NULL;
} else {
kfree(key->payload.data[big_key_data]);
key->payload.data[big_key_data] = NULL;
}
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
loff_t pos;
file = dentry_open(path, O_RDONLY, current_cred());
if (IS_ERR(file))
return PTR_ERR(file);
pos = 0;
ret = vfs_read(file, buffer, datalen, &pos);
fput(file);
if (ret >= 0 && ret != datalen)
ret = -EIO;
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
static void __exit big_key_cleanup(void)
{
unregister_key_type(&key_type_big_key);
}
