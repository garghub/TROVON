static ssize_t bfin_otp_read(struct file *file, char __user *buff, size_t count, loff_t *pos)
{
ssize_t bytes_done;
u32 page, flags, ret;
u64 content;
stampit();
if (count % sizeof(u64))
return -EMSGSIZE;
if (mutex_lock_interruptible(&bfin_otp_lock))
return -ERESTARTSYS;
bytes_done = 0;
page = *pos / (sizeof(u64) * 2);
while (bytes_done < count) {
flags = (*pos % (sizeof(u64) * 2) ? OTP_UPPER_HALF : OTP_LOWER_HALF);
stamp("processing page %i (0x%x:%s)", page, flags,
(flags & OTP_UPPER_HALF ? "upper" : "lower"));
ret = bfrom_OtpRead(page, flags, &content);
if (ret & OTP_MASTER_ERROR) {
stamp("error from otp: 0x%x", ret);
bytes_done = -EIO;
break;
}
if (copy_to_user(buff + bytes_done, &content, sizeof(content))) {
bytes_done = -EFAULT;
break;
}
if (flags & OTP_UPPER_HALF)
++page;
bytes_done += sizeof(content);
*pos += sizeof(content);
}
mutex_unlock(&bfin_otp_lock);
return bytes_done;
}
static u32 bfin_otp_init_timing(void)
{
u32 tp1, tp2, tp3, timing;
tp1 = get_sclk() / 1000000;
tp2 = (2 * get_sclk() / 10000000) << 8;
tp3 = (0x1401) << 15;
timing = tp1 | tp2 | tp3;
if (bfrom_OtpCommand(OTP_INIT, timing))
return 0;
return timing;
}
static void bfin_otp_deinit_timing(u32 timing)
{
bfrom_OtpCommand(OTP_CLOSE, 0);
bfrom_OtpCommand(OTP_INIT, timing & ~(-1 << 15));
bfrom_OtpCommand(OTP_CLOSE, 0);
}
static ssize_t bfin_otp_write(struct file *filp, const char __user *buff, size_t count, loff_t *pos)
{
ssize_t bytes_done;
u32 timing, page, base_flags, flags, ret;
u64 content;
if (!allow_writes)
return -EACCES;
if (count % sizeof(u64))
return -EMSGSIZE;
if (mutex_lock_interruptible(&bfin_otp_lock))
return -ERESTARTSYS;
stampit();
timing = bfin_otp_init_timing();
if (timing == 0) {
mutex_unlock(&bfin_otp_lock);
return -EIO;
}
base_flags = OTP_CHECK_FOR_PREV_WRITE;
bytes_done = 0;
page = *pos / (sizeof(u64) * 2);
while (bytes_done < count) {
flags = base_flags | (*pos % (sizeof(u64) * 2) ? OTP_UPPER_HALF : OTP_LOWER_HALF);
stamp("processing page %i (0x%x:%s) from %p", page, flags,
(flags & OTP_UPPER_HALF ? "upper" : "lower"), buff + bytes_done);
if (copy_from_user(&content, buff + bytes_done, sizeof(content))) {
bytes_done = -EFAULT;
break;
}
ret = bfrom_OtpWrite(page, flags, &content);
if (ret & OTP_MASTER_ERROR) {
stamp("error from otp: 0x%x", ret);
bytes_done = -EIO;
break;
}
if (flags & OTP_UPPER_HALF)
++page;
bytes_done += sizeof(content);
*pos += sizeof(content);
}
bfin_otp_deinit_timing(timing);
mutex_unlock(&bfin_otp_lock);
return bytes_done;
}
static long bfin_otp_ioctl(struct file *filp, unsigned cmd, unsigned long arg)
{
stampit();
switch (cmd) {
case OTPLOCK: {
u32 timing;
int ret = -EIO;
if (!allow_writes)
return -EACCES;
if (mutex_lock_interruptible(&bfin_otp_lock))
return -ERESTARTSYS;
timing = bfin_otp_init_timing();
if (timing) {
u32 otp_result = bfrom_OtpWrite(arg, OTP_LOCK, NULL);
stamp("locking page %lu resulted in 0x%x", arg, otp_result);
if (!(otp_result & OTP_MASTER_ERROR))
ret = 0;
bfin_otp_deinit_timing(timing);
}
mutex_unlock(&bfin_otp_lock);
return ret;
}
case MEMLOCK:
allow_writes = false;
return 0;
case MEMUNLOCK:
allow_writes = true;
return 0;
}
return -EINVAL;
}
