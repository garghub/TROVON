unsigned char __nvram_read_byte(int i)
{
return CMOS_READ(NVRAM_FIRST_BYTE + i);
}
unsigned char nvram_read_byte(int i)
{
unsigned long flags;
unsigned char c;
spin_lock_irqsave(&rtc_lock, flags);
c = __nvram_read_byte(i);
spin_unlock_irqrestore(&rtc_lock, flags);
return c;
}
void __nvram_write_byte(unsigned char c, int i)
{
CMOS_WRITE(c, NVRAM_FIRST_BYTE + i);
}
void nvram_write_byte(unsigned char c, int i)
{
unsigned long flags;
spin_lock_irqsave(&rtc_lock, flags);
__nvram_write_byte(c, i);
spin_unlock_irqrestore(&rtc_lock, flags);
}
int __nvram_check_checksum(void)
{
return mach_check_checksum();
}
int nvram_check_checksum(void)
{
unsigned long flags;
int rv;
spin_lock_irqsave(&rtc_lock, flags);
rv = __nvram_check_checksum();
spin_unlock_irqrestore(&rtc_lock, flags);
return rv;
}
static void __nvram_set_checksum(void)
{
mach_set_checksum();
}
static loff_t nvram_llseek(struct file *file, loff_t offset, int origin)
{
return generic_file_llseek_size(file, offset, origin, MAX_LFS_FILESIZE,
NVRAM_BYTES);
}
static ssize_t nvram_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
unsigned char contents[NVRAM_BYTES];
unsigned i = *ppos;
unsigned char *tmp;
spin_lock_irq(&rtc_lock);
if (!__nvram_check_checksum())
goto checksum_err;
for (tmp = contents; count-- > 0 && i < NVRAM_BYTES; ++i, ++tmp)
*tmp = __nvram_read_byte(i);
spin_unlock_irq(&rtc_lock);
if (copy_to_user(buf, contents, tmp - contents))
return -EFAULT;
*ppos = i;
return tmp - contents;
checksum_err:
spin_unlock_irq(&rtc_lock);
return -EIO;
}
static ssize_t nvram_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
unsigned char contents[NVRAM_BYTES];
unsigned i = *ppos;
unsigned char *tmp;
if (i >= NVRAM_BYTES)
return 0;
if (count > NVRAM_BYTES - i)
count = NVRAM_BYTES - i;
if (count > NVRAM_BYTES)
return -EFAULT;
if (copy_from_user(contents, buf, count))
return -EFAULT;
spin_lock_irq(&rtc_lock);
if (!__nvram_check_checksum())
goto checksum_err;
for (tmp = contents; count--; ++i, ++tmp)
__nvram_write_byte(*tmp, i);
__nvram_set_checksum();
spin_unlock_irq(&rtc_lock);
*ppos = i;
return tmp - contents;
checksum_err:
spin_unlock_irq(&rtc_lock);
return -EIO;
}
static long nvram_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
int i;
switch (cmd) {
case NVRAM_INIT:
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
mutex_lock(&nvram_mutex);
spin_lock_irq(&rtc_lock);
for (i = 0; i < NVRAM_BYTES; ++i)
__nvram_write_byte(0, i);
__nvram_set_checksum();
spin_unlock_irq(&rtc_lock);
mutex_unlock(&nvram_mutex);
return 0;
case NVRAM_SETCKS:
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
mutex_lock(&nvram_mutex);
spin_lock_irq(&rtc_lock);
__nvram_set_checksum();
spin_unlock_irq(&rtc_lock);
mutex_unlock(&nvram_mutex);
return 0;
default:
return -ENOTTY;
}
}
static int nvram_open(struct inode *inode, struct file *file)
{
spin_lock(&nvram_state_lock);
if ((nvram_open_cnt && (file->f_flags & O_EXCL)) ||
(nvram_open_mode & NVRAM_EXCL) ||
((file->f_mode & FMODE_WRITE) && (nvram_open_mode & NVRAM_WRITE))) {
spin_unlock(&nvram_state_lock);
return -EBUSY;
}
if (file->f_flags & O_EXCL)
nvram_open_mode |= NVRAM_EXCL;
if (file->f_mode & FMODE_WRITE)
nvram_open_mode |= NVRAM_WRITE;
nvram_open_cnt++;
spin_unlock(&nvram_state_lock);
return 0;
}
static int nvram_release(struct inode *inode, struct file *file)
{
spin_lock(&nvram_state_lock);
nvram_open_cnt--;
if (nvram_open_mode & NVRAM_EXCL)
nvram_open_mode &= ~NVRAM_EXCL;
if (file->f_mode & FMODE_WRITE)
nvram_open_mode &= ~NVRAM_WRITE;
spin_unlock(&nvram_state_lock);
return 0;
}
static int nvram_add_proc_fs(void)
{
return 0;
}
static int nvram_proc_read(struct seq_file *seq, void *offset)
{
unsigned char contents[NVRAM_BYTES];
int i = 0;
spin_lock_irq(&rtc_lock);
for (i = 0; i < NVRAM_BYTES; ++i)
contents[i] = __nvram_read_byte(i);
spin_unlock_irq(&rtc_lock);
mach_proc_infos(contents, seq, offset);
return 0;
}
static int nvram_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, nvram_proc_read, NULL);
}
static int nvram_add_proc_fs(void)
{
if (!proc_create("driver/nvram", 0, NULL, &nvram_proc_fops))
return -ENOMEM;
return 0;
}
static int __init nvram_init(void)
{
int ret;
if (!CHECK_DRIVER_INIT())
return -ENODEV;
ret = misc_register(&nvram_dev);
if (ret) {
printk(KERN_ERR "nvram: can't misc_register on minor=%d\n",
NVRAM_MINOR);
goto out;
}
ret = nvram_add_proc_fs();
if (ret) {
printk(KERN_ERR "nvram: can't create /proc/driver/nvram\n");
goto outmisc;
}
ret = 0;
printk(KERN_INFO "Non-volatile memory driver v" NVRAM_VERSION "\n");
out:
return ret;
outmisc:
misc_deregister(&nvram_dev);
goto out;
}
static void __exit nvram_cleanup_module(void)
{
remove_proc_entry("driver/nvram", NULL);
misc_deregister(&nvram_dev);
}
static int pc_check_checksum(void)
{
int i;
unsigned short sum = 0;
unsigned short expect;
for (i = PC_CKS_RANGE_START; i <= PC_CKS_RANGE_END; ++i)
sum += __nvram_read_byte(i);
expect = __nvram_read_byte(PC_CKS_LOC)<<8 |
__nvram_read_byte(PC_CKS_LOC+1);
return (sum & 0xffff) == expect;
}
static void pc_set_checksum(void)
{
int i;
unsigned short sum = 0;
for (i = PC_CKS_RANGE_START; i <= PC_CKS_RANGE_END; ++i)
sum += __nvram_read_byte(i);
__nvram_write_byte(sum >> 8, PC_CKS_LOC);
__nvram_write_byte(sum & 0xff, PC_CKS_LOC + 1);
}
static void pc_proc_infos(unsigned char *nvram, struct seq_file *seq,
void *offset)
{
int checksum;
int type;
spin_lock_irq(&rtc_lock);
checksum = __nvram_check_checksum();
spin_unlock_irq(&rtc_lock);
seq_printf(seq, "Checksum status: %svalid\n", checksum ? "" : "not ");
seq_printf(seq, "# floppies : %d\n",
(nvram[6] & 1) ? (nvram[6] >> 6) + 1 : 0);
seq_printf(seq, "Floppy 0 type : ");
type = nvram[2] >> 4;
if (type < ARRAY_SIZE(floppy_types))
seq_printf(seq, "%s\n", floppy_types[type]);
else
seq_printf(seq, "%d (unknown)\n", type);
seq_printf(seq, "Floppy 1 type : ");
type = nvram[2] & 0x0f;
if (type < ARRAY_SIZE(floppy_types))
seq_printf(seq, "%s\n", floppy_types[type]);
else
seq_printf(seq, "%d (unknown)\n", type);
seq_printf(seq, "HD 0 type : ");
type = nvram[4] >> 4;
if (type)
seq_printf(seq, "%02x\n", type == 0x0f ? nvram[11] : type);
else
seq_printf(seq, "none\n");
seq_printf(seq, "HD 1 type : ");
type = nvram[4] & 0x0f;
if (type)
seq_printf(seq, "%02x\n", type == 0x0f ? nvram[12] : type);
else
seq_printf(seq, "none\n");
seq_printf(seq, "HD type 48 data: %d/%d/%d C/H/S, precomp %d, lz %d\n",
nvram[18] | (nvram[19] << 8),
nvram[20], nvram[25],
nvram[21] | (nvram[22] << 8), nvram[23] | (nvram[24] << 8));
seq_printf(seq, "HD type 49 data: %d/%d/%d C/H/S, precomp %d, lz %d\n",
nvram[39] | (nvram[40] << 8),
nvram[41], nvram[46],
nvram[42] | (nvram[43] << 8), nvram[44] | (nvram[45] << 8));
seq_printf(seq, "DOS base memory: %d kB\n", nvram[7] | (nvram[8] << 8));
seq_printf(seq, "Extended memory: %d kB (configured), %d kB (tested)\n",
nvram[9] | (nvram[10] << 8), nvram[34] | (nvram[35] << 8));
seq_printf(seq, "Gfx adapter : %s\n",
gfx_types[(nvram[6] >> 4) & 3]);
seq_printf(seq, "FPU : %sinstalled\n",
(nvram[6] & 2) ? "" : "not ");
return;
}
static int atari_check_checksum(void)
{
int i;
unsigned char sum = 0;
for (i = ATARI_CKS_RANGE_START; i <= ATARI_CKS_RANGE_END; ++i)
sum += __nvram_read_byte(i);
return (__nvram_read_byte(ATARI_CKS_LOC) == (~sum & 0xff)) &&
(__nvram_read_byte(ATARI_CKS_LOC + 1) == (sum & 0xff));
}
static void atari_set_checksum(void)
{
int i;
unsigned char sum = 0;
for (i = ATARI_CKS_RANGE_START; i <= ATARI_CKS_RANGE_END; ++i)
sum += __nvram_read_byte(i);
__nvram_write_byte(~sum, ATARI_CKS_LOC);
__nvram_write_byte(sum, ATARI_CKS_LOC + 1);
}
static void atari_proc_infos(unsigned char *nvram, struct seq_file *seq,
void *offset)
{
int checksum = nvram_check_checksum();
int i;
unsigned vmode;
seq_printf(seq, "Checksum status : %svalid\n", checksum ? "" : "not ");
seq_printf(seq, "Boot preference : ");
for (i = ARRAY_SIZE(boot_prefs) - 1; i >= 0; --i) {
if (nvram[1] == boot_prefs[i].val) {
seq_printf(seq, "%s\n", boot_prefs[i].name);
break;
}
}
if (i < 0)
seq_printf(seq, "0x%02x (undefined)\n", nvram[1]);
seq_printf(seq, "SCSI arbitration : %s\n",
(nvram[16] & 0x80) ? "on" : "off");
seq_printf(seq, "SCSI host ID : ");
if (nvram[16] & 0x80)
seq_printf(seq, "%d\n", nvram[16] & 7);
else
seq_printf(seq, "n/a\n");
if ((atari_mch_cookie >> 16) != ATARI_MCH_FALCON)
return;
seq_printf(seq, "OS language : ");
if (nvram[6] < ARRAY_SIZE(languages))
seq_printf(seq, "%s\n", languages[nvram[6]]);
else
seq_printf(seq, "%u (undefined)\n", nvram[6]);
seq_printf(seq, "Keyboard language: ");
if (nvram[7] < ARRAY_SIZE(languages))
seq_printf(seq, "%s\n", languages[nvram[7]]);
else
seq_printf(seq, "%u (undefined)\n", nvram[7]);
seq_printf(seq, "Date format : ");
seq_printf(seq, dateformat[nvram[8] & 7],
nvram[9] ? nvram[9] : '/', nvram[9] ? nvram[9] : '/');
seq_printf(seq, ", %dh clock\n", nvram[8] & 16 ? 24 : 12);
seq_printf(seq, "Boot delay : ");
if (nvram[10] == 0)
seq_printf(seq, "default");
else
seq_printf(seq, "%ds%s\n", nvram[10],
nvram[10] < 8 ? ", no memory test" : "");
vmode = (nvram[14] << 8) | nvram[15];
seq_printf(seq,
"Video mode : %s colors, %d columns, %s %s monitor\n",
colors[vmode & 7],
vmode & 8 ? 80 : 40,
vmode & 16 ? "VGA" : "TV", vmode & 32 ? "PAL" : "NTSC");
seq_printf(seq, " %soverscan, compat. mode %s%s\n",
vmode & 64 ? "" : "no ",
vmode & 128 ? "on" : "off",
vmode & 256 ?
(vmode & 16 ? ", line doubling" : ", half screen") : "");
return;
}
