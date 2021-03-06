static int
vcs_notifier(struct notifier_block *nb, unsigned long code, void *_param)
{
struct vt_notifier_param *param = _param;
struct vc_data *vc = param->vc;
struct vcs_poll_data *poll =
container_of(nb, struct vcs_poll_data, notifier);
int currcons = poll->cons_num;
if (code != VT_UPDATE)
return NOTIFY_DONE;
if (currcons == 0)
currcons = fg_console;
else
currcons--;
if (currcons != vc->vc_num)
return NOTIFY_DONE;
poll->seen_last_update = false;
wake_up_interruptible(&poll->waitq);
kill_fasync(&poll->fasync, SIGIO, POLL_IN);
return NOTIFY_OK;
}
static void
vcs_poll_data_free(struct vcs_poll_data *poll)
{
unregister_vt_notifier(&poll->notifier);
kfree(poll);
}
static struct vcs_poll_data *
vcs_poll_data_get(struct file *file)
{
struct vcs_poll_data *poll = file->private_data, *kill = NULL;
if (poll)
return poll;
poll = kzalloc(sizeof(*poll), GFP_KERNEL);
if (!poll)
return NULL;
poll->cons_num = iminor(file_inode(file)) & 127;
init_waitqueue_head(&poll->waitq);
poll->notifier.notifier_call = vcs_notifier;
if (register_vt_notifier(&poll->notifier) != 0) {
kfree(poll);
return NULL;
}
spin_lock(&file->f_lock);
if (!file->private_data) {
file->private_data = poll;
} else {
kill = poll;
poll = file->private_data;
}
spin_unlock(&file->f_lock);
if (kill)
vcs_poll_data_free(kill);
return poll;
}
static struct vc_data*
vcs_vc(struct inode *inode, int *viewed)
{
unsigned int currcons = iminor(inode) & 127;
WARN_CONSOLE_UNLOCKED();
if (currcons == 0) {
currcons = fg_console;
if (viewed)
*viewed = 1;
} else {
currcons--;
if (viewed)
*viewed = 0;
}
return vc_cons[currcons].d;
}
static int
vcs_size(struct inode *inode)
{
int size;
int minor = iminor(inode);
struct vc_data *vc;
WARN_CONSOLE_UNLOCKED();
vc = vcs_vc(inode, NULL);
if (!vc)
return -ENXIO;
size = vc->vc_rows * vc->vc_cols;
if (minor & 128)
size = 2*size + HEADER_SIZE;
return size;
}
static loff_t vcs_lseek(struct file *file, loff_t offset, int orig)
{
int size;
console_lock();
size = vcs_size(file_inode(file));
console_unlock();
if (size < 0)
return size;
switch (orig) {
default:
return -EINVAL;
case 2:
offset += size;
break;
case 1:
offset += file->f_pos;
case 0:
break;
}
if (offset < 0 || offset > size) {
return -EINVAL;
}
file->f_pos = offset;
return file->f_pos;
}
static ssize_t
vcs_read(struct file *file, char __user *buf, size_t count, loff_t *ppos)
{
struct inode *inode = file_inode(file);
unsigned int currcons = iminor(inode);
struct vc_data *vc;
struct vcs_poll_data *poll;
long pos;
long attr, read;
int col, maxcol, viewed;
unsigned short *org = NULL;
ssize_t ret;
char *con_buf;
con_buf = (char *) __get_free_page(GFP_KERNEL);
if (!con_buf)
return -ENOMEM;
pos = *ppos;
console_lock();
attr = (currcons & 128);
ret = -ENXIO;
vc = vcs_vc(inode, &viewed);
if (!vc)
goto unlock_out;
ret = -EINVAL;
if (pos < 0)
goto unlock_out;
poll = file->private_data;
if (count && poll)
poll->seen_last_update = true;
read = 0;
ret = 0;
while (count) {
char *con_buf0, *con_buf_start;
long this_round, size;
ssize_t orig_count;
long p = pos;
size = vcs_size(inode);
if (size < 0) {
if (read)
break;
ret = size;
goto unlock_out;
}
if (pos >= size)
break;
if (count > size - pos)
count = size - pos;
this_round = count;
if (this_round > CON_BUF_SIZE)
this_round = CON_BUF_SIZE;
con_buf_start = con_buf0 = con_buf;
orig_count = this_round;
maxcol = vc->vc_cols;
if (!attr) {
org = screen_pos(vc, p, viewed);
col = p % maxcol;
p += maxcol - col;
while (this_round-- > 0) {
*con_buf0++ = (vcs_scr_readw(vc, org++) & 0xff);
if (++col == maxcol) {
org = screen_pos(vc, p, viewed);
col = 0;
p += maxcol;
}
}
} else {
if (p < HEADER_SIZE) {
size_t tmp_count;
con_buf0[0] = (char)vc->vc_rows;
con_buf0[1] = (char)vc->vc_cols;
getconsxy(vc, con_buf0 + 2);
con_buf_start += p;
this_round += p;
if (this_round > CON_BUF_SIZE) {
this_round = CON_BUF_SIZE;
orig_count = this_round - p;
}
tmp_count = HEADER_SIZE;
if (tmp_count > this_round)
tmp_count = this_round;
this_round -= tmp_count;
p = HEADER_SIZE;
con_buf0 = con_buf + HEADER_SIZE;
} else if (p & 1) {
con_buf_start++;
if (this_round < CON_BUF_SIZE)
this_round++;
else
orig_count--;
}
if (this_round > 0) {
unsigned short *tmp_buf = (unsigned short *)con_buf0;
p -= HEADER_SIZE;
p /= 2;
col = p % maxcol;
org = screen_pos(vc, p, viewed);
p += maxcol - col;
this_round = (this_round + 1) >> 1;
while (this_round) {
*tmp_buf++ = vcs_scr_readw(vc, org++);
this_round --;
if (++col == maxcol) {
org = screen_pos(vc, p, viewed);
col = 0;
p += maxcol;
}
}
}
}
console_unlock();
ret = copy_to_user(buf, con_buf_start, orig_count);
console_lock();
if (ret) {
read += (orig_count - ret);
ret = -EFAULT;
break;
}
buf += orig_count;
pos += orig_count;
read += orig_count;
count -= orig_count;
}
*ppos += read;
if (read)
ret = read;
unlock_out:
console_unlock();
free_page((unsigned long) con_buf);
return ret;
}
static ssize_t
vcs_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
struct inode *inode = file_inode(file);
unsigned int currcons = iminor(inode);
struct vc_data *vc;
long pos;
long attr, size, written;
char *con_buf0;
int col, maxcol, viewed;
u16 *org0 = NULL, *org = NULL;
size_t ret;
char *con_buf;
con_buf = (char *) __get_free_page(GFP_KERNEL);
if (!con_buf)
return -ENOMEM;
pos = *ppos;
console_lock();
attr = (currcons & 128);
ret = -ENXIO;
vc = vcs_vc(inode, &viewed);
if (!vc)
goto unlock_out;
size = vcs_size(inode);
ret = -EINVAL;
if (pos < 0 || pos > size)
goto unlock_out;
if (count > size - pos)
count = size - pos;
written = 0;
while (count) {
long this_round = count;
size_t orig_count;
long p;
if (this_round > CON_BUF_SIZE)
this_round = CON_BUF_SIZE;
console_unlock();
ret = copy_from_user(con_buf, buf, this_round);
console_lock();
if (ret) {
this_round -= ret;
if (!this_round) {
if (written)
break;
ret = -EFAULT;
goto unlock_out;
}
}
size = vcs_size(inode);
if (size < 0) {
if (written)
break;
ret = size;
goto unlock_out;
}
if (pos >= size)
break;
if (this_round > size - pos)
this_round = size - pos;
con_buf0 = con_buf;
orig_count = this_round;
maxcol = vc->vc_cols;
p = pos;
if (!attr) {
org0 = org = screen_pos(vc, p, viewed);
col = p % maxcol;
p += maxcol - col;
while (this_round > 0) {
unsigned char c = *con_buf0++;
this_round--;
vcs_scr_writew(vc,
(vcs_scr_readw(vc, org) & 0xff00) | c, org);
org++;
if (++col == maxcol) {
org = screen_pos(vc, p, viewed);
col = 0;
p += maxcol;
}
}
} else {
if (p < HEADER_SIZE) {
char header[HEADER_SIZE];
getconsxy(vc, header + 2);
while (p < HEADER_SIZE && this_round > 0) {
this_round--;
header[p++] = *con_buf0++;
}
if (!viewed)
putconsxy(vc, header + 2);
}
p -= HEADER_SIZE;
col = (p/2) % maxcol;
if (this_round > 0) {
org0 = org = screen_pos(vc, p/2, viewed);
if ((p & 1) && this_round > 0) {
char c;
this_round--;
c = *con_buf0++;
#ifdef __BIG_ENDIAN
vcs_scr_writew(vc, c |
(vcs_scr_readw(vc, org) & 0xff00), org);
#else
vcs_scr_writew(vc, (c << 8) |
(vcs_scr_readw(vc, org) & 0xff), org);
#endif
org++;
p++;
if (++col == maxcol) {
org = screen_pos(vc, p/2, viewed);
col = 0;
}
}
p /= 2;
p += maxcol - col;
}
while (this_round > 1) {
unsigned short w;
w = get_unaligned(((unsigned short *)con_buf0));
vcs_scr_writew(vc, w, org++);
con_buf0 += 2;
this_round -= 2;
if (++col == maxcol) {
org = screen_pos(vc, p, viewed);
col = 0;
p += maxcol;
}
}
if (this_round > 0) {
unsigned char c;
c = *con_buf0++;
#ifdef __BIG_ENDIAN
vcs_scr_writew(vc, (vcs_scr_readw(vc, org) & 0xff) | (c << 8), org);
#else
vcs_scr_writew(vc, (vcs_scr_readw(vc, org) & 0xff00) | c, org);
#endif
}
}
count -= orig_count;
written += orig_count;
buf += orig_count;
pos += orig_count;
if (org0)
update_region(vc, (unsigned long)(org0), org - org0);
}
*ppos += written;
ret = written;
if (written)
vcs_scr_updated(vc);
unlock_out:
console_unlock();
free_page((unsigned long) con_buf);
return ret;
}
static unsigned int
vcs_poll(struct file *file, poll_table *wait)
{
struct vcs_poll_data *poll = vcs_poll_data_get(file);
int ret = DEFAULT_POLLMASK|POLLERR|POLLPRI;
if (poll) {
poll_wait(file, &poll->waitq, wait);
if (poll->seen_last_update)
ret = DEFAULT_POLLMASK;
}
return ret;
}
static int
vcs_fasync(int fd, struct file *file, int on)
{
struct vcs_poll_data *poll = file->private_data;
if (!poll) {
if (!on)
return 0;
poll = vcs_poll_data_get(file);
if (!poll)
return -ENOMEM;
}
return fasync_helper(fd, file, on, &poll->fasync);
}
static int
vcs_open(struct inode *inode, struct file *filp)
{
unsigned int currcons = iminor(inode) & 127;
int ret = 0;
console_lock();
if(currcons && !vc_cons_allocated(currcons-1))
ret = -ENXIO;
console_unlock();
return ret;
}
static int vcs_release(struct inode *inode, struct file *file)
{
struct vcs_poll_data *poll = file->private_data;
if (poll)
vcs_poll_data_free(poll);
return 0;
}
void vcs_make_sysfs(int index)
{
device_create(vc_class, NULL, MKDEV(VCS_MAJOR, index + 1), NULL,
"vcs%u", index + 1);
device_create(vc_class, NULL, MKDEV(VCS_MAJOR, index + 129), NULL,
"vcsa%u", index + 1);
}
void vcs_remove_sysfs(int index)
{
device_destroy(vc_class, MKDEV(VCS_MAJOR, index + 1));
device_destroy(vc_class, MKDEV(VCS_MAJOR, index + 129));
}
int __init vcs_init(void)
{
unsigned int i;
if (register_chrdev(VCS_MAJOR, "vcs", &vcs_fops))
panic("unable to get major %d for vcs device", VCS_MAJOR);
vc_class = class_create(THIS_MODULE, "vc");
device_create(vc_class, NULL, MKDEV(VCS_MAJOR, 0), NULL, "vcs");
device_create(vc_class, NULL, MKDEV(VCS_MAJOR, 128), NULL, "vcsa");
for (i = 0; i < MIN_NR_CONSOLES; i++)
vcs_make_sysfs(i);
return 0;
}
