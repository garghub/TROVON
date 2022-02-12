static int scu_reg_access(u32 cmd, struct scu_ipc_data *data)
{
unsigned int count = data->count;
if (count == 0 || count == 3 || count > 4)
return -EINVAL;
switch (cmd) {
case INTE_SCU_IPC_REGISTER_READ:
return intel_scu_ipc_readv(data->addr, data->data, count);
case INTE_SCU_IPC_REGISTER_WRITE:
return intel_scu_ipc_writev(data->addr, data->data, count);
case INTE_SCU_IPC_REGISTER_UPDATE:
return intel_scu_ipc_update_register(data->addr[0],
data->data[0], data->mask);
default:
return -ENOTTY;
}
}
static long scu_ipc_ioctl(struct file *fp, unsigned int cmd,
unsigned long arg)
{
int ret;
struct scu_ipc_data data;
void __user *argp = (void __user *)arg;
if (!capable(CAP_SYS_RAWIO))
return -EPERM;
if (copy_from_user(&data, argp, sizeof(struct scu_ipc_data)))
return -EFAULT;
ret = scu_reg_access(cmd, &data);
if (ret < 0)
return ret;
if (copy_to_user(argp, &data, sizeof(struct scu_ipc_data)))
return -EFAULT;
return 0;
}
static int __init ipc_module_init(void)
{
major = register_chrdev(0, "intel_mid_scu", &scu_ipc_fops);
if (major < 0)
return major;
return 0;
}
static void __exit ipc_module_exit(void)
{
unregister_chrdev(major, "intel_mid_scu");
}
