static int do_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
int err;
err = security_file_ioctl(file, cmd, arg);
if (err)
return err;
return vfs_ioctl(file, cmd, arg);
}
static int w_long(struct file *file,
unsigned int cmd, compat_ulong_t __user *argp)
{
int err;
unsigned long __user *valp = compat_alloc_user_space(sizeof(*valp));
if (valp == NULL)
return -EFAULT;
err = do_ioctl(file, cmd, (unsigned long)valp);
if (err)
return err;
if (convert_in_user(valp, argp))
return -EFAULT;
return 0;
}
static int do_video_get_event(struct file *file,
unsigned int cmd, struct compat_video_event __user *up)
{
struct video_event __user *kevent =
compat_alloc_user_space(sizeof(*kevent));
int err;
if (kevent == NULL)
return -EFAULT;
err = do_ioctl(file, cmd, (unsigned long)kevent);
if (!err) {
err = convert_in_user(&kevent->type, &up->type);
err |= convert_in_user(&kevent->timestamp, &up->timestamp);
err |= convert_in_user(&kevent->u.size.w, &up->u.size.w);
err |= convert_in_user(&kevent->u.size.h, &up->u.size.h);
err |= convert_in_user(&kevent->u.size.aspect_ratio,
&up->u.size.aspect_ratio);
if (err)
err = -EFAULT;
}
return err;
}
static int do_video_stillpicture(struct file *file,
unsigned int cmd, struct compat_video_still_picture __user *up)
{
struct video_still_picture __user *up_native;
compat_uptr_t fp;
int32_t size;
int err;
err = get_user(fp, &up->iFrame);
err |= get_user(size, &up->size);
if (err)
return -EFAULT;
up_native =
compat_alloc_user_space(sizeof(struct video_still_picture));
err = put_user(compat_ptr(fp), &up_native->iFrame);
err |= put_user(size, &up_native->size);
if (err)
return -EFAULT;
err = do_ioctl(file, cmd, (unsigned long) up_native);
return err;
}
static int do_video_set_spu_palette(struct file *file,
unsigned int cmd, struct compat_video_spu_palette __user *up)
{
struct video_spu_palette __user *up_native;
compat_uptr_t palp;
int length, err;
err = get_user(palp, &up->palette);
err |= get_user(length, &up->length);
if (err)
return -EFAULT;
up_native = compat_alloc_user_space(sizeof(struct video_spu_palette));
err = put_user(compat_ptr(palp), &up_native->palette);
err |= put_user(length, &up_native->length);
if (err)
return -EFAULT;
err = do_ioctl(file, cmd, (unsigned long) up_native);
return err;
}
static int sg_build_iovec(sg_io_hdr_t __user *sgio, void __user *dxferp, u16 iovec_count)
{
sg_iovec_t __user *iov = (sg_iovec_t __user *) (sgio + 1);
sg_iovec32_t __user *iov32 = dxferp;
int i;
for (i = 0; i < iovec_count; i++) {
u32 base, len;
if (get_user(base, &iov32[i].iov_base) ||
get_user(len, &iov32[i].iov_len) ||
put_user(compat_ptr(base), &iov[i].iov_base) ||
put_user(len, &iov[i].iov_len))
return -EFAULT;
}
if (put_user(iov, &sgio->dxferp))
return -EFAULT;
return 0;
}
static int sg_ioctl_trans(struct file *file, unsigned int cmd,
sg_io_hdr32_t __user *sgio32)
{
sg_io_hdr_t __user *sgio;
u16 iovec_count;
u32 data;
void __user *dxferp;
int err;
int interface_id;
if (get_user(interface_id, &sgio32->interface_id))
return -EFAULT;
if (interface_id != 'S')
return do_ioctl(file, cmd, (unsigned long)sgio32);
if (get_user(iovec_count, &sgio32->iovec_count))
return -EFAULT;
{
void __user *top = compat_alloc_user_space(0);
void __user *new = compat_alloc_user_space(sizeof(sg_io_hdr_t) +
(iovec_count * sizeof(sg_iovec_t)));
if (new > top)
return -EINVAL;
sgio = new;
}
if (copy_in_user(&sgio->interface_id, &sgio32->interface_id,
(2 * sizeof(int)) +
(2 * sizeof(unsigned char)) +
(1 * sizeof(unsigned short)) +
(1 * sizeof(unsigned int))))
return -EFAULT;
if (get_user(data, &sgio32->dxferp))
return -EFAULT;
dxferp = compat_ptr(data);
if (iovec_count) {
if (sg_build_iovec(sgio, dxferp, iovec_count))
return -EFAULT;
} else {
if (put_user(dxferp, &sgio->dxferp))
return -EFAULT;
}
{
unsigned char __user *cmdp;
unsigned char __user *sbp;
if (get_user(data, &sgio32->cmdp))
return -EFAULT;
cmdp = compat_ptr(data);
if (get_user(data, &sgio32->sbp))
return -EFAULT;
sbp = compat_ptr(data);
if (put_user(cmdp, &sgio->cmdp) ||
put_user(sbp, &sgio->sbp))
return -EFAULT;
}
if (copy_in_user(&sgio->timeout, &sgio32->timeout,
3 * sizeof(int)))
return -EFAULT;
if (get_user(data, &sgio32->usr_ptr))
return -EFAULT;
if (put_user(compat_ptr(data), &sgio->usr_ptr))
return -EFAULT;
err = do_ioctl(file, cmd, (unsigned long) sgio);
if (err >= 0) {
void __user *datap;
if (copy_in_user(&sgio32->pack_id, &sgio->pack_id,
sizeof(int)) ||
get_user(datap, &sgio->usr_ptr) ||
put_user((u32)(unsigned long)datap,
&sgio32->usr_ptr) ||
copy_in_user(&sgio32->status, &sgio->status,
(4 * sizeof(unsigned char)) +
(2 * sizeof(unsigned short)) +
(3 * sizeof(int))))
err = -EFAULT;
}
return err;
}
static int sg_grt_trans(struct file *file,
unsigned int cmd, struct compat_sg_req_info __user *o)
{
int err, i;
sg_req_info_t __user *r;
r = compat_alloc_user_space(sizeof(sg_req_info_t)*SG_MAX_QUEUE);
err = do_ioctl(file, cmd, (unsigned long)r);
if (err < 0)
return err;
for (i = 0; i < SG_MAX_QUEUE; i++) {
void __user *ptr;
int d;
if (copy_in_user(o + i, r + i, offsetof(sg_req_info_t, usr_ptr)) ||
get_user(ptr, &r[i].usr_ptr) ||
get_user(d, &r[i].duration) ||
put_user((u32)(unsigned long)(ptr), &o[i].usr_ptr) ||
put_user(d, &o[i].duration))
return -EFAULT;
}
return err;
}
static int ppp_sock_fprog_ioctl_trans(struct file *file,
unsigned int cmd, struct sock_fprog32 __user *u_fprog32)
{
struct sock_fprog __user *u_fprog64 = compat_alloc_user_space(sizeof(struct sock_fprog));
void __user *fptr64;
u32 fptr32;
u16 flen;
if (get_user(flen, &u_fprog32->len) ||
get_user(fptr32, &u_fprog32->filter))
return -EFAULT;
fptr64 = compat_ptr(fptr32);
if (put_user(flen, &u_fprog64->len) ||
put_user(fptr64, &u_fprog64->filter))
return -EFAULT;
if (cmd == PPPIOCSPASS32)
cmd = PPPIOCSPASS;
else
cmd = PPPIOCSACTIVE;
return do_ioctl(file, cmd, (unsigned long) u_fprog64);
}
static int ppp_gidle(struct file *file, unsigned int cmd,
struct ppp_idle32 __user *idle32)
{
struct ppp_idle __user *idle;
__kernel_time_t xmit, recv;
int err;
idle = compat_alloc_user_space(sizeof(*idle));
err = do_ioctl(file, PPPIOCGIDLE, (unsigned long) idle);
if (!err) {
if (get_user(xmit, &idle->xmit_idle) ||
get_user(recv, &idle->recv_idle) ||
put_user(xmit, &idle32->xmit_idle) ||
put_user(recv, &idle32->recv_idle))
err = -EFAULT;
}
return err;
}
static int ppp_scompress(struct file *file, unsigned int cmd,
struct ppp_option_data32 __user *odata32)
{
struct ppp_option_data __user *odata;
__u32 data;
void __user *datap;
odata = compat_alloc_user_space(sizeof(*odata));
if (get_user(data, &odata32->ptr))
return -EFAULT;
datap = compat_ptr(data);
if (put_user(datap, &odata->ptr))
return -EFAULT;
if (copy_in_user(&odata->length, &odata32->length,
sizeof(__u32) + sizeof(int)))
return -EFAULT;
return do_ioctl(file, PPPIOCSCOMPRESS, (unsigned long) odata);
}
static int mt_ioctl_trans(struct file *file,
unsigned int cmd, void __user *argp)
{
struct mtget __user *get = NULL;
struct mtget32 __user *umget32;
struct mtpos __user *pos = NULL;
struct mtpos32 __user *upos32;
unsigned long kcmd;
void *karg;
int err = 0;
switch(cmd) {
case MTIOCPOS32:
kcmd = MTIOCPOS;
pos = compat_alloc_user_space(sizeof(*pos));
karg = pos;
break;
default:
kcmd = MTIOCGET;
get = compat_alloc_user_space(sizeof(*get));
karg = get;
break;
}
if (karg == NULL)
return -EFAULT;
err = do_ioctl(file, kcmd, (unsigned long)karg);
if (err)
return err;
switch (cmd) {
case MTIOCPOS32:
upos32 = argp;
err = convert_in_user(&pos->mt_blkno, &upos32->mt_blkno);
break;
case MTIOCGET32:
umget32 = argp;
err = convert_in_user(&get->mt_type, &umget32->mt_type);
err |= convert_in_user(&get->mt_resid, &umget32->mt_resid);
err |= convert_in_user(&get->mt_dsreg, &umget32->mt_dsreg);
err |= convert_in_user(&get->mt_gstat, &umget32->mt_gstat);
err |= convert_in_user(&get->mt_erreg, &umget32->mt_erreg);
err |= convert_in_user(&get->mt_fileno, &umget32->mt_fileno);
err |= convert_in_user(&get->mt_blkno, &umget32->mt_blkno);
break;
}
return err ? -EFAULT: 0;
}
static int serial_struct_ioctl(struct file *file,
unsigned cmd, struct serial_struct32 __user *ss32)
{
typedef struct serial_struct32 SS32;
int err;
struct serial_struct __user *ss = compat_alloc_user_space(sizeof(*ss));
__u32 udata;
unsigned int base;
unsigned char *iomem_base;
if (ss == NULL)
return -EFAULT;
if (cmd == TIOCSSERIAL) {
if (copy_in_user(ss, ss32, offsetof(SS32, iomem_base)) ||
get_user(udata, &ss32->iomem_base))
return -EFAULT;
iomem_base = compat_ptr(udata);
if (put_user(iomem_base, &ss->iomem_base) ||
convert_in_user(&ss32->iomem_reg_shift,
&ss->iomem_reg_shift) ||
convert_in_user(&ss32->port_high, &ss->port_high) ||
put_user(0UL, &ss->iomap_base))
return -EFAULT;
}
err = do_ioctl(file, cmd, (unsigned long)ss);
if (cmd == TIOCGSERIAL && err >= 0) {
if (copy_in_user(ss32, ss, offsetof(SS32, iomem_base)) ||
get_user(iomem_base, &ss->iomem_base))
return -EFAULT;
base = (unsigned long)iomem_base >> 32 ?
0xffffffff : (unsigned)(unsigned long)iomem_base;
if (put_user(base, &ss32->iomem_base) ||
convert_in_user(&ss->iomem_reg_shift,
&ss32->iomem_reg_shift) ||
convert_in_user(&ss->port_high, &ss32->port_high))
return -EFAULT;
}
return err;
}
static int do_i2c_rdwr_ioctl(struct file *file,
unsigned int cmd, struct i2c_rdwr_ioctl_data32 __user *udata)
{
struct i2c_rdwr_aligned __user *tdata;
struct i2c_msg __user *tmsgs;
struct i2c_msg32 __user *umsgs;
compat_caddr_t datap;
u32 nmsgs;
int i;
if (get_user(nmsgs, &udata->nmsgs))
return -EFAULT;
if (nmsgs > I2C_RDWR_IOCTL_MAX_MSGS)
return -EINVAL;
if (get_user(datap, &udata->msgs))
return -EFAULT;
umsgs = compat_ptr(datap);
tdata = compat_alloc_user_space(sizeof(*tdata) +
nmsgs * sizeof(struct i2c_msg));
tmsgs = &tdata->msgs[0];
if (put_user(nmsgs, &tdata->cmd.nmsgs) ||
put_user(tmsgs, &tdata->cmd.msgs))
return -EFAULT;
for (i = 0; i < nmsgs; i++) {
if (copy_in_user(&tmsgs[i].addr, &umsgs[i].addr, 3*sizeof(u16)))
return -EFAULT;
if (get_user(datap, &umsgs[i].buf) ||
put_user(compat_ptr(datap), &tmsgs[i].buf))
return -EFAULT;
}
return do_ioctl(file, cmd, (unsigned long)tdata);
}
static int do_i2c_smbus_ioctl(struct file *file,
unsigned int cmd, struct i2c_smbus_ioctl_data32 __user *udata)
{
struct i2c_smbus_ioctl_data __user *tdata;
union {
struct i2c_smbus_ioctl_data32 data32;
struct i2c_smbus_ioctl_data data;
} v;
tdata = compat_alloc_user_space(sizeof(*tdata));
if (tdata == NULL)
return -ENOMEM;
memset(&v, 0, sizeof(v));
if (copy_from_user(&v.data32, udata, sizeof(v.data32)))
return -EFAULT;
v.data.data = compat_ptr(v.data32.data);
if (copy_to_user(tdata, &v.data, sizeof(v.data)))
return -EFAULT;
return do_ioctl(file, cmd, (unsigned long)tdata);
}
static int rtc_ioctl(struct file *file,
unsigned cmd, void __user *argp)
{
unsigned long __user *valp = compat_alloc_user_space(sizeof(*valp));
int ret;
if (valp == NULL)
return -EFAULT;
switch (cmd) {
case RTC_IRQP_READ32:
case RTC_EPOCH_READ32:
ret = do_ioctl(file, (cmd == RTC_IRQP_READ32) ?
RTC_IRQP_READ : RTC_EPOCH_READ,
(unsigned long)valp);
if (ret)
return ret;
return convert_in_user(valp, (unsigned int __user *)argp);
case RTC_IRQP_SET32:
return do_ioctl(file, RTC_IRQP_SET, (unsigned long)argp);
case RTC_EPOCH_SET32:
return do_ioctl(file, RTC_EPOCH_SET, (unsigned long)argp);
}
return -ENOIOCTLCMD;
}
static int compat_ioctl_preallocate(struct file *file,
struct space_resv_32 __user *p32)
{
struct space_resv __user *p = compat_alloc_user_space(sizeof(*p));
if (copy_in_user(&p->l_type, &p32->l_type, sizeof(s16)) ||
copy_in_user(&p->l_whence, &p32->l_whence, sizeof(s16)) ||
copy_in_user(&p->l_start, &p32->l_start, sizeof(s64)) ||
copy_in_user(&p->l_len, &p32->l_len, sizeof(s64)) ||
copy_in_user(&p->l_sysid, &p32->l_sysid, sizeof(s32)) ||
copy_in_user(&p->l_pid, &p32->l_pid, sizeof(u32)) ||
copy_in_user(&p->l_pad, &p32->l_pad, 4*sizeof(u32)))
return -EFAULT;
return ioctl_preallocate(file, p);
}
static long do_ioctl_trans(unsigned int cmd,
unsigned long arg, struct file *file)
{
void __user *argp = compat_ptr(arg);
switch (cmd) {
case PPPIOCGIDLE32:
return ppp_gidle(file, cmd, argp);
case PPPIOCSCOMPRESS32:
return ppp_scompress(file, cmd, argp);
case PPPIOCSPASS32:
case PPPIOCSACTIVE32:
return ppp_sock_fprog_ioctl_trans(file, cmd, argp);
#ifdef CONFIG_BLOCK
case SG_IO:
return sg_ioctl_trans(file, cmd, argp);
case SG_GET_REQUEST_TABLE:
return sg_grt_trans(file, cmd, argp);
case MTIOCGET32:
case MTIOCPOS32:
return mt_ioctl_trans(file, cmd, argp);
#endif
case TIOCGSERIAL:
case TIOCSSERIAL:
return serial_struct_ioctl(file, cmd, argp);
case I2C_FUNCS:
return w_long(file, cmd, argp);
case I2C_RDWR:
return do_i2c_rdwr_ioctl(file, cmd, argp);
case I2C_SMBUS:
return do_i2c_smbus_ioctl(file, cmd, argp);
case RTC_IRQP_READ32:
case RTC_IRQP_SET32:
case RTC_EPOCH_READ32:
case RTC_EPOCH_SET32:
return rtc_ioctl(file, cmd, argp);
case VIDEO_GET_EVENT:
return do_video_get_event(file, cmd, argp);
case VIDEO_STILLPICTURE:
return do_video_stillpicture(file, cmd, argp);
case VIDEO_SET_SPU_PALETTE:
return do_video_set_spu_palette(file, cmd, argp);
}
switch (cmd) {
case TCSBRKP:
case TIOCMIWAIT:
case TIOCSCTTY:
case HOT_REMOVE_DISK:
case HOT_ADD_DISK:
case SET_DISK_FAULTY:
case SET_BITMAP_FILE:
case KDSIGACCEPT:
case KIOCSOUND:
case KDMKTONE:
case KDSETMODE:
case KDSKBMODE:
case KDSKBMETA:
case KDSKBLED:
case KDSETLED:
return vfs_ioctl(file, cmd, arg);
}
return -ENOIOCTLCMD;
}
static int compat_ioctl_check_table(unsigned int xcmd)
{
int i;
const int max = ARRAY_SIZE(ioctl_pointer) - 1;
BUILD_BUG_ON(max >= (1 << 16));
i = ((xcmd >> 16) * max) >> 16;
while (ioctl_pointer[i] < xcmd && i < max)
i++;
while (ioctl_pointer[i] > xcmd && i > 0)
i--;
return ioctl_pointer[i] == xcmd;
}
static int __init init_sys32_ioctl_cmp(const void *p, const void *q)
{
unsigned int a, b;
a = *(unsigned int *)p;
b = *(unsigned int *)q;
if (a > b)
return 1;
if (a < b)
return -1;
return 0;
}
static int __init init_sys32_ioctl(void)
{
sort(ioctl_pointer, ARRAY_SIZE(ioctl_pointer), sizeof(*ioctl_pointer),
init_sys32_ioctl_cmp, NULL);
return 0;
}
