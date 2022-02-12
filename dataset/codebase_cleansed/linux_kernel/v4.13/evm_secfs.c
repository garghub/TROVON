static ssize_t evm_read_key(struct file *filp, char __user *buf,
size_t count, loff_t *ppos)
{
char temp[80];
ssize_t rc;
if (*ppos != 0)
return 0;
sprintf(temp, "%d", evm_initialized);
rc = simple_read_from_buffer(buf, count, ppos, temp, strlen(temp));
return rc;
}
static ssize_t evm_write_key(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
char temp[80];
int i;
if (!capable(CAP_SYS_ADMIN) || (evm_initialized & EVM_INIT_HMAC))
return -EPERM;
if (count >= sizeof(temp) || count == 0)
return -EINVAL;
if (copy_from_user(temp, buf, count) != 0)
return -EFAULT;
temp[count] = '\0';
if ((sscanf(temp, "%d", &i) != 1) || (i != 1))
return -EINVAL;
evm_init_key();
return count;
}
int __init evm_init_secfs(void)
{
int error = 0;
evm_init_tpm = securityfs_create_file("evm", S_IRUSR | S_IRGRP,
NULL, NULL, &evm_key_ops);
if (!evm_init_tpm || IS_ERR(evm_init_tpm))
error = -EFAULT;
return error;
}
