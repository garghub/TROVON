static int __init evm_set_fixmode(char *str)
{
if (strncmp(str, "fix", 3) == 0)
evm_fixmode = 1;
return 0;
}
static enum integrity_status evm_verify_hmac(struct dentry *dentry,
const char *xattr_name,
char *xattr_value,
size_t xattr_value_len,
struct integrity_iint_cache *iint)
{
struct evm_ima_xattr_data xattr_data;
enum integrity_status evm_status = INTEGRITY_PASS;
int rc;
if (iint && iint->evm_status == INTEGRITY_PASS)
return iint->evm_status;
rc = evm_calc_hmac(dentry, xattr_name, xattr_value,
xattr_value_len, xattr_data.digest);
if (rc < 0) {
evm_status = (rc == -ENODATA)
? INTEGRITY_NOXATTRS : INTEGRITY_FAIL;
goto out;
}
xattr_data.type = EVM_XATTR_HMAC;
rc = vfs_xattr_cmp(dentry, XATTR_NAME_EVM, (u8 *)&xattr_data,
sizeof xattr_data, GFP_NOFS);
if (rc < 0)
evm_status = (rc == -ENODATA)
? INTEGRITY_NOLABEL : INTEGRITY_FAIL;
out:
if (iint)
iint->evm_status = evm_status;
return evm_status;
}
static int evm_protected_xattr(const char *req_xattr_name)
{
char **xattrname;
int namelen;
int found = 0;
namelen = strlen(req_xattr_name);
for (xattrname = evm_config_xattrnames; *xattrname != NULL; xattrname++) {
if ((strlen(*xattrname) == namelen)
&& (strncmp(req_xattr_name, *xattrname, namelen) == 0)) {
found = 1;
break;
}
if (strncmp(req_xattr_name,
*xattrname + XATTR_SECURITY_PREFIX_LEN,
strlen(req_xattr_name)) == 0) {
found = 1;
break;
}
}
return found;
}
enum integrity_status evm_verifyxattr(struct dentry *dentry,
const char *xattr_name,
void *xattr_value, size_t xattr_value_len,
struct integrity_iint_cache *iint)
{
if (!evm_initialized || !evm_protected_xattr(xattr_name))
return INTEGRITY_UNKNOWN;
if (!iint) {
iint = integrity_iint_find(dentry->d_inode);
if (!iint)
return INTEGRITY_UNKNOWN;
}
return evm_verify_hmac(dentry, xattr_name, xattr_value,
xattr_value_len, iint);
}
static enum integrity_status evm_verify_current_integrity(struct dentry *dentry)
{
struct inode *inode = dentry->d_inode;
if (!evm_initialized || !S_ISREG(inode->i_mode) || evm_fixmode)
return 0;
return evm_verify_hmac(dentry, NULL, NULL, 0, NULL);
}
static int evm_protect_xattr(struct dentry *dentry, const char *xattr_name,
const void *xattr_value, size_t xattr_value_len)
{
enum integrity_status evm_status;
if (strcmp(xattr_name, XATTR_NAME_EVM) == 0) {
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
} else if (!evm_protected_xattr(xattr_name)) {
if (!posix_xattr_acl(xattr_name))
return 0;
evm_status = evm_verify_current_integrity(dentry);
if ((evm_status == INTEGRITY_PASS) ||
(evm_status == INTEGRITY_NOXATTRS))
return 0;
return -EPERM;
}
evm_status = evm_verify_current_integrity(dentry);
return evm_status == INTEGRITY_PASS ? 0 : -EPERM;
}
int evm_inode_setxattr(struct dentry *dentry, const char *xattr_name,
const void *xattr_value, size_t xattr_value_len)
{
return evm_protect_xattr(dentry, xattr_name, xattr_value,
xattr_value_len);
}
int evm_inode_removexattr(struct dentry *dentry, const char *xattr_name)
{
return evm_protect_xattr(dentry, xattr_name, NULL, 0);
}
void evm_inode_post_setxattr(struct dentry *dentry, const char *xattr_name,
const void *xattr_value, size_t xattr_value_len)
{
if (!evm_initialized || (!evm_protected_xattr(xattr_name)
&& !posix_xattr_acl(xattr_name)))
return;
evm_update_evmxattr(dentry, xattr_name, xattr_value, xattr_value_len);
return;
}
void evm_inode_post_removexattr(struct dentry *dentry, const char *xattr_name)
{
struct inode *inode = dentry->d_inode;
if (!evm_initialized || !evm_protected_xattr(xattr_name))
return;
mutex_lock(&inode->i_mutex);
evm_update_evmxattr(dentry, xattr_name, NULL, 0);
mutex_unlock(&inode->i_mutex);
return;
}
int evm_inode_setattr(struct dentry *dentry, struct iattr *attr)
{
unsigned int ia_valid = attr->ia_valid;
enum integrity_status evm_status;
if (!(ia_valid & (ATTR_MODE | ATTR_UID | ATTR_GID)))
return 0;
evm_status = evm_verify_current_integrity(dentry);
if ((evm_status == INTEGRITY_PASS) ||
(evm_status == INTEGRITY_NOXATTRS))
return 0;
return -EPERM;
}
void evm_inode_post_setattr(struct dentry *dentry, int ia_valid)
{
if (!evm_initialized)
return;
if (ia_valid & (ATTR_MODE | ATTR_UID | ATTR_GID))
evm_update_evmxattr(dentry, NULL, NULL, 0);
return;
}
int evm_inode_init_security(struct inode *inode,
const struct xattr *lsm_xattr,
struct xattr *evm_xattr)
{
struct evm_ima_xattr_data *xattr_data;
int rc;
if (!evm_initialized || !evm_protected_xattr(lsm_xattr->name))
return 0;
xattr_data = kzalloc(sizeof(*xattr_data), GFP_NOFS);
if (!xattr_data)
return -ENOMEM;
xattr_data->type = EVM_XATTR_HMAC;
rc = evm_init_hmac(inode, lsm_xattr, xattr_data->digest);
if (rc < 0)
goto out;
evm_xattr->value = xattr_data;
evm_xattr->value_len = sizeof(*xattr_data);
evm_xattr->name = kstrdup(XATTR_EVM_SUFFIX, GFP_NOFS);
return 0;
out:
kfree(xattr_data);
return rc;
}
static int __init init_evm(void)
{
int error;
error = evm_init_secfs();
if (error < 0) {
printk(KERN_INFO "EVM: Error registering secfs\n");
goto err;
}
err:
return error;
}
static void __exit cleanup_evm(void)
{
evm_cleanup_secfs();
if (hmac_tfm)
crypto_free_shash(hmac_tfm);
}
static int __init evm_display_config(void)
{
char **xattrname;
for (xattrname = evm_config_xattrnames; *xattrname != NULL; xattrname++)
printk(KERN_INFO "EVM: %s\n", *xattrname);
return 0;
}
