static struct shash_desc *init_desc(char type)
{
long rc;
char *algo;
struct crypto_shash **tfm;
struct shash_desc *desc;
if (type == EVM_XATTR_HMAC) {
tfm = &hmac_tfm;
algo = evm_hmac;
} else {
tfm = &hash_tfm;
algo = evm_hash;
}
if (*tfm == NULL) {
mutex_lock(&mutex);
if (*tfm)
goto out;
*tfm = crypto_alloc_shash(algo, 0, CRYPTO_ALG_ASYNC);
if (IS_ERR(*tfm)) {
rc = PTR_ERR(*tfm);
pr_err("Can not allocate %s (reason: %ld)\n", algo, rc);
*tfm = NULL;
mutex_unlock(&mutex);
return ERR_PTR(rc);
}
if (type == EVM_XATTR_HMAC) {
rc = crypto_shash_setkey(*tfm, evmkey, evmkey_len);
if (rc) {
crypto_free_shash(*tfm);
*tfm = NULL;
mutex_unlock(&mutex);
return ERR_PTR(rc);
}
}
out:
mutex_unlock(&mutex);
}
desc = kmalloc(sizeof(*desc) + crypto_shash_descsize(*tfm),
GFP_KERNEL);
if (!desc)
return ERR_PTR(-ENOMEM);
desc->tfm = *tfm;
desc->flags = CRYPTO_TFM_REQ_MAY_SLEEP;
rc = crypto_shash_init(desc);
if (rc) {
kfree(desc);
return ERR_PTR(rc);
}
return desc;
}
static void hmac_add_misc(struct shash_desc *desc, struct inode *inode,
char *digest)
{
struct h_misc {
unsigned long ino;
__u32 generation;
uid_t uid;
gid_t gid;
umode_t mode;
} hmac_misc;
memset(&hmac_misc, 0, sizeof(hmac_misc));
hmac_misc.ino = inode->i_ino;
hmac_misc.generation = inode->i_generation;
hmac_misc.uid = from_kuid(&init_user_ns, inode->i_uid);
hmac_misc.gid = from_kgid(&init_user_ns, inode->i_gid);
hmac_misc.mode = inode->i_mode;
crypto_shash_update(desc, (const u8 *)&hmac_misc, sizeof(hmac_misc));
if (evm_hmac_version > 1)
crypto_shash_update(desc, inode->i_sb->s_uuid,
sizeof(inode->i_sb->s_uuid));
crypto_shash_final(desc, digest);
}
static int evm_calc_hmac_or_hash(struct dentry *dentry,
const char *req_xattr_name,
const char *req_xattr_value,
size_t req_xattr_value_len,
char type, char *digest)
{
struct inode *inode = dentry->d_inode;
struct shash_desc *desc;
char **xattrname;
size_t xattr_size = 0;
char *xattr_value = NULL;
int error;
int size;
if (!inode->i_op->getxattr)
return -EOPNOTSUPP;
desc = init_desc(type);
if (IS_ERR(desc))
return PTR_ERR(desc);
error = -ENODATA;
for (xattrname = evm_config_xattrnames; *xattrname != NULL; xattrname++) {
if ((req_xattr_name && req_xattr_value)
&& !strcmp(*xattrname, req_xattr_name)) {
error = 0;
crypto_shash_update(desc, (const u8 *)req_xattr_value,
req_xattr_value_len);
continue;
}
size = vfs_getxattr_alloc(dentry, *xattrname,
&xattr_value, xattr_size, GFP_NOFS);
if (size == -ENOMEM) {
error = -ENOMEM;
goto out;
}
if (size < 0)
continue;
error = 0;
xattr_size = size;
crypto_shash_update(desc, (const u8 *)xattr_value, xattr_size);
}
hmac_add_misc(desc, inode, digest);
out:
kfree(xattr_value);
kfree(desc);
return error;
}
int evm_calc_hmac(struct dentry *dentry, const char *req_xattr_name,
const char *req_xattr_value, size_t req_xattr_value_len,
char *digest)
{
return evm_calc_hmac_or_hash(dentry, req_xattr_name, req_xattr_value,
req_xattr_value_len, EVM_XATTR_HMAC, digest);
}
int evm_calc_hash(struct dentry *dentry, const char *req_xattr_name,
const char *req_xattr_value, size_t req_xattr_value_len,
char *digest)
{
return evm_calc_hmac_or_hash(dentry, req_xattr_name, req_xattr_value,
req_xattr_value_len, IMA_XATTR_DIGEST, digest);
}
int evm_update_evmxattr(struct dentry *dentry, const char *xattr_name,
const char *xattr_value, size_t xattr_value_len)
{
struct inode *inode = dentry->d_inode;
struct evm_ima_xattr_data xattr_data;
int rc = 0;
rc = evm_calc_hmac(dentry, xattr_name, xattr_value,
xattr_value_len, xattr_data.digest);
if (rc == 0) {
xattr_data.type = EVM_XATTR_HMAC;
rc = __vfs_setxattr_noperm(dentry, XATTR_NAME_EVM,
&xattr_data,
sizeof(xattr_data), 0);
} else if (rc == -ENODATA && inode->i_op->removexattr) {
rc = inode->i_op->removexattr(dentry, XATTR_NAME_EVM);
}
return rc;
}
int evm_init_hmac(struct inode *inode, const struct xattr *lsm_xattr,
char *hmac_val)
{
struct shash_desc *desc;
desc = init_desc(EVM_XATTR_HMAC);
if (IS_ERR(desc)) {
pr_info("init_desc failed\n");
return PTR_ERR(desc);
}
crypto_shash_update(desc, lsm_xattr->value, lsm_xattr->value_len);
hmac_add_misc(desc, inode, hmac_val);
kfree(desc);
return 0;
}
int evm_init_key(void)
{
struct key *evm_key;
struct encrypted_key_payload *ekp;
int rc = 0;
evm_key = request_key(&key_type_encrypted, EVMKEY, NULL);
if (IS_ERR(evm_key))
return -ENOENT;
down_read(&evm_key->sem);
ekp = evm_key->payload.data;
if (ekp->decrypted_datalen > MAX_KEY_SIZE) {
rc = -EINVAL;
goto out;
}
memcpy(evmkey, ekp->decrypted_data, ekp->decrypted_datalen);
out:
memset(ekp->decrypted_data, 0, ekp->decrypted_datalen);
up_read(&evm_key->sem);
key_put(evm_key);
return rc;
}
