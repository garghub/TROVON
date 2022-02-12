static void memset16(void *_ptr, unsigned short val, unsigned count)
{
unsigned short *ptr = _ptr;
count >>= 1;
while (count--)
*ptr++ = val;
}
int load_565rle_image(char *filename)
{
struct fb_info *info;
int fd, err = 0;
unsigned count, max;
unsigned short *data, *bits, *ptr;
info = registered_fb[0];
if (!info) {
printk(KERN_WARNING "%s: Can not access framebuffer\n",
__func__);
return -ENODEV;
}
fd = sys_open(filename, O_RDONLY, 0);
if (fd < 0) {
printk(KERN_WARNING "%s: Can not open %s\n",
__func__, filename);
return -ENOENT;
}
count = (unsigned)sys_lseek(fd, (off_t)0, 2);
if (count == 0) {
sys_close(fd);
err = -EIO;
goto err_logo_close_file;
}
sys_lseek(fd, (off_t)0, 0);
data = kmalloc(count, GFP_KERNEL);
if (!data) {
printk(KERN_WARNING "%s: Can not alloc data\n", __func__);
err = -ENOMEM;
goto err_logo_close_file;
}
if ((unsigned)sys_read(fd, (char *)data, count) != count) {
err = -EIO;
goto err_logo_free_data;
}
max = fb_width(info) * fb_height(info);
ptr = data;
bits = (unsigned short *)(info->screen_base);
while (count > 3) {
unsigned n = ptr[0];
if (n > max)
break;
memset16(bits, ptr[1], n << 1);
bits += n;
max -= n;
ptr += 2;
count -= 4;
}
err_logo_free_data:
kfree(data);
err_logo_close_file:
sys_close(fd);
return err;
}
