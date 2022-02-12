static ssize_t bL_switcher_write(struct file *file, const char __user *buf,
size_t len, loff_t *pos)
{
unsigned char val[3];
unsigned int cpu, cluster;
int ret;
pr_debug("%s\n", __func__);
if (len < 3)
return -EINVAL;
if (copy_from_user(val, buf, 3))
return -EFAULT;
if (val[0] < '0' || val[0] > '9' ||
val[1] != ',' ||
val[2] < '0' || val[2] > '1')
return -EINVAL;
cpu = val[0] - '0';
cluster = val[2] - '0';
ret = bL_switch_request(cpu, cluster);
return ret ? : len;
}
