static int ack_ready(struct sdio_func *func)
{
unsigned long start = jiffies;
u8 val;
int ret;
while ((jiffies - start) < HZ) {
val = sdio_readb(func, 0x13, &ret);
if (val & 0x01)
return 1;
schedule();
}
return 0;
}
static int download_image(struct sdio_func *func, char *img_name)
{
int ret = 0, len, size, pno;
struct file *filp = NULL;
struct inode *inode = NULL;
u8 *buf = tx_buf;
loff_t pos = 0;
filp = filp_open(img_name, O_RDONLY | O_LARGEFILE, 0);
if (IS_ERR(filp)) {
printk(KERN_ERR "Can't find %s.\n", img_name);
return -ENOENT;
}
inode = filp->f_dentry->d_inode;
if (!S_ISREG(inode->i_mode)) {
printk(KERN_ERR "Invalid file type: %s\n", img_name);
ret = -EINVAL;
goto out;
}
size = i_size_read(inode->i_mapping->host);
if (size <= 0) {
printk(KERN_ERR "Unable to find file size: %s\n", img_name);
ret = size;
goto out;
}
pno = 0;
while ((len = filp->f_op->read(filp, buf + TYPE_A_HEADER_SIZE,
DOWNLOAD_SIZE, &pos))) {
if (len < 0) {
ret = -1;
goto out;
}
buf[0] = len & 0xff;
buf[1] = (len >> 8) & 0xff;
buf[2] = (len >> 16) & 0xff;
if (pos >= size)
buf[3] = 2;
else
buf[3] = 0;
ret = sdio_memcpy_toio(func, 0, buf, len + TYPE_A_HEADER_SIZE);
if (ret < 0) {
printk(KERN_ERR "gdmwm: send image error: "
"packet number = %d ret = %d\n", pno, ret);
goto out;
}
if (buf[3] == 2)
break;
if (!ack_ready(func)) {
ret = -EIO;
printk(KERN_ERR "gdmwm: Ack is not ready.\n");
goto out;
}
ret = sdio_memcpy_fromio(func, buf, 0, TYPE_A_LOOKAHEAD_SIZE);
if (ret < 0) {
printk(KERN_ERR "gdmwm: receive ack error: "
"packet number = %d ret = %d\n", pno, ret);
goto out;
}
sdio_writeb(func, 0x01, 0x13, &ret);
sdio_writeb(func, 0x00, 0x10, &ret);
pno++;
}
out:
filp_close(filp, NULL);
return ret;
}
int sdio_boot(struct sdio_func *func)
{
static mm_segment_t fs;
int ret;
tx_buf = kmalloc(YMEM0_SIZE, GFP_KERNEL);
if (tx_buf == NULL) {
printk(KERN_ERR "Error: kmalloc: %s %d\n", __func__, __LINE__);
return -ENOMEM;
}
fs = get_fs();
set_fs(get_ds());
ret = download_image(func, KRN_PATH);
if (ret)
goto restore_fs;
printk(KERN_INFO "GCT: Kernel download success.\n");
ret = download_image(func, RFS_PATH);
if (ret)
goto restore_fs;
printk(KERN_INFO "GCT: Filesystem download success.\n");
restore_fs:
set_fs(fs);
kfree(tx_buf);
return ret;
}
