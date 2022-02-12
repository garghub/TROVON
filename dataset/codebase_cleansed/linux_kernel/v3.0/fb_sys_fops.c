ssize_t fb_sys_read(struct fb_info *info, char __user *buf, size_t count,
loff_t *ppos)
{
unsigned long p = *ppos;
void *src;
int err = 0;
unsigned long total_size;
if (info->state != FBINFO_STATE_RUNNING)
return -EPERM;
total_size = info->screen_size;
if (total_size == 0)
total_size = info->fix.smem_len;
if (p >= total_size)
return 0;
if (count >= total_size)
count = total_size;
if (count + p > total_size)
count = total_size - p;
src = (void __force *)(info->screen_base + p);
if (info->fbops->fb_sync)
info->fbops->fb_sync(info);
if (copy_to_user(buf, src, count))
err = -EFAULT;
if (!err)
*ppos += count;
return (err) ? err : count;
}
ssize_t fb_sys_write(struct fb_info *info, const char __user *buf,
size_t count, loff_t *ppos)
{
unsigned long p = *ppos;
void *dst;
int err = 0;
unsigned long total_size;
if (info->state != FBINFO_STATE_RUNNING)
return -EPERM;
total_size = info->screen_size;
if (total_size == 0)
total_size = info->fix.smem_len;
if (p > total_size)
return -EFBIG;
if (count > total_size) {
err = -EFBIG;
count = total_size;
}
if (count + p > total_size) {
if (!err)
err = -ENOSPC;
count = total_size - p;
}
dst = (void __force *) (info->screen_base + p);
if (info->fbops->fb_sync)
info->fbops->fb_sync(info);
if (copy_from_user(dst, buf, count))
err = -EFAULT;
if (!err)
*ppos += count;
return (err) ? err : count;
}
