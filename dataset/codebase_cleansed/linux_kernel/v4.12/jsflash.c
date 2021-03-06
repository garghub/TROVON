static unsigned int jsf_inl(unsigned long addr)
{
unsigned long retval;
__asm__ __volatile__("lda [%1] %2, %0\n\t" :
"=r" (retval) :
"r" (addr), "i" (ASI_M_BYPASS));
return retval;
}
static void jsf_outl(unsigned long addr, __u32 data)
{
__asm__ __volatile__("sta %0, [%1] %2\n\t" : :
"r" (data), "r" (addr), "i" (ASI_M_BYPASS) :
"memory");
}
static void jsf_wait(unsigned long p) {
unsigned int x1, x2;
for (;;) {
x1 = jsf_inl(p);
x2 = jsf_inl(p);
if ((x1 & 0x40404040) == (x2 & 0x40404040)) return;
}
}
static void jsf_write4(unsigned long fa, u32 data) {
jsf_outl(fa, 0xAAAAAAAA);
jsf_outl(fa, 0x55555555);
jsf_outl(fa, 0xA0A0A0A0);
jsf_outl(fa, data);
jsf_wait(fa);
}
static void jsfd_read(char *buf, unsigned long p, size_t togo) {
union byte4 {
char s[4];
unsigned int n;
} b;
while (togo >= 4) {
togo -= 4;
b.n = jsf_inl(p);
memcpy(buf, b.s, 4);
p += 4;
buf += 4;
}
}
static struct request *jsfd_next_request(void)
{
struct request_queue *q;
struct request *rq;
int old_pos = jsfd_queue;
do {
q = jsfd_disk[jsfd_queue]->queue;
if (++jsfd_queue == JSF_MAX)
jsfd_queue = 0;
if (q) {
rq = blk_fetch_request(q);
if (rq)
return rq;
}
} while (jsfd_queue != old_pos);
return NULL;
}
static void jsfd_request(void)
{
struct request *req;
req = jsfd_next_request();
while (req) {
struct jsfd_part *jdp = req->rq_disk->private_data;
unsigned long offset = blk_rq_pos(req) << 9;
size_t len = blk_rq_cur_bytes(req);
int err = -EIO;
if ((offset + len) > jdp->dsize)
goto end;
if (rq_data_dir(req) != READ) {
printk(KERN_ERR "jsfd: write\n");
goto end;
}
if ((jdp->dbase & 0xff000000) != 0x20000000) {
printk(KERN_ERR "jsfd: bad base %x\n", (int)jdp->dbase);
goto end;
}
jsfd_read(bio_data(req->bio), jdp->dbase + offset, len);
err = 0;
end:
if (!__blk_end_request_cur(req, err))
req = jsfd_next_request();
}
}
static void jsfd_do_request(struct request_queue *q)
{
jsfd_request();
}
static loff_t jsf_lseek(struct file * file, loff_t offset, int orig)
{
loff_t ret;
mutex_lock(&jsf_mutex);
switch (orig) {
case 0:
file->f_pos = offset;
ret = file->f_pos;
break;
case 1:
file->f_pos += offset;
ret = file->f_pos;
break;
default:
ret = -EINVAL;
}
mutex_unlock(&jsf_mutex);
return ret;
}
static ssize_t jsf_read(struct file * file, char __user * buf,
size_t togo, loff_t *ppos)
{
unsigned long p = *ppos;
char __user *tmp = buf;
union byte4 {
char s[4];
unsigned int n;
} b;
if (p < JSF_BASE_ALL || p >= JSF_BASE_TOP) {
return 0;
}
if ((p + togo) < p
|| (p + togo) >= JSF_BASE_TOP) {
togo = JSF_BASE_TOP - p;
}
if (p < JSF_BASE_ALL && togo != 0) {
#if 0
size_t x = JSF_BASE_ALL - p;
if (x > togo) x = togo;
clear_user(tmp, x);
tmp += x;
p += x;
togo -= x;
#else
return 0;
#endif
}
while (togo >= 4) {
togo -= 4;
b.n = jsf_inl(p);
if (copy_to_user(tmp, b.s, 4))
return -EFAULT;
tmp += 4;
p += 4;
}
*ppos = p;
return tmp-buf;
}
static ssize_t jsf_write(struct file * file, const char __user * buf,
size_t count, loff_t *ppos)
{
return -ENOSPC;
}
static int jsf_ioctl_erase(unsigned long arg)
{
unsigned long p;
p = 0x20400000;
jsf_outl(p, 0xAAAAAAAA);
jsf_outl(p, 0x55555555);
jsf_outl(p, 0x80808080);
jsf_outl(p, 0xAAAAAAAA);
jsf_outl(p, 0x55555555);
jsf_outl(p, 0x10101010);
#if 0
{
int i;
__u32 x;
for (i = 0; i < 1000000; i++) {
x = jsf_inl(p);
if ((x & 0x80808080) == 0x80808080) break;
}
if ((x & 0x80808080) != 0x80808080) {
printk("jsf0: erase timeout with 0x%08x\n", x);
} else {
printk("jsf0: erase done with 0x%08x\n", x);
}
}
#else
jsf_wait(p);
#endif
return 0;
}
static int jsf_ioctl_program(void __user *arg)
{
struct jsflash_program_arg abuf;
char __user *uptr;
unsigned long p;
unsigned int togo;
union {
unsigned int n;
char s[4];
} b;
if (copy_from_user(&abuf, arg, JSFPRGSZ))
return -EFAULT;
p = abuf.off;
togo = abuf.size;
if ((togo & 3) || (p & 3)) return -EINVAL;
uptr = (char __user *) (unsigned long) abuf.data;
while (togo != 0) {
togo -= 4;
if (copy_from_user(&b.s[0], uptr, 4))
return -EFAULT;
jsf_write4(p, b.n);
p += 4;
uptr += 4;
}
return 0;
}
static long jsf_ioctl(struct file *f, unsigned int cmd, unsigned long arg)
{
mutex_lock(&jsf_mutex);
int error = -ENOTTY;
void __user *argp = (void __user *)arg;
if (!capable(CAP_SYS_ADMIN)) {
mutex_unlock(&jsf_mutex);
return -EPERM;
}
switch (cmd) {
case JSFLASH_IDENT:
if (copy_to_user(argp, &jsf0.id, JSFIDSZ)) {
mutex_unlock(&jsf_mutex);
return -EFAULT;
}
break;
case JSFLASH_ERASE:
error = jsf_ioctl_erase(arg);
break;
case JSFLASH_PROGRAM:
error = jsf_ioctl_program(argp);
break;
}
mutex_unlock(&jsf_mutex);
return error;
}
static int jsf_mmap(struct file * file, struct vm_area_struct * vma)
{
return -ENXIO;
}
static int jsf_open(struct inode * inode, struct file * filp)
{
mutex_lock(&jsf_mutex);
if (jsf0.base == 0) {
mutex_unlock(&jsf_mutex);
return -ENXIO;
}
if (test_and_set_bit(0, (void *)&jsf0.busy) != 0) {
mutex_unlock(&jsf_mutex);
return -EBUSY;
}
mutex_unlock(&jsf_mutex);
return 0;
}
static int jsf_release(struct inode *inode, struct file *file)
{
jsf0.busy = 0;
return 0;
}
static int jsflash_init(void)
{
int rc;
struct jsflash *jsf;
phandle node;
char banner[128];
struct linux_prom_registers reg0;
node = prom_getchild(prom_root_node);
node = prom_searchsiblings(node, "flash-memory");
if (node != 0 && (s32)node != -1) {
if (prom_getproperty(node, "reg",
(char *)&reg0, sizeof(reg0)) == -1) {
printk("jsflash: no \"reg\" property\n");
return -ENXIO;
}
if (reg0.which_io != 0) {
printk("jsflash: bus number nonzero: 0x%x:%x\n",
reg0.which_io, reg0.phys_addr);
return -ENXIO;
}
#if 0
if ((reg0.phys_addr >> 24) != 0x20) {
printk("jsflash: suspicious address: 0x%x:%x\n",
reg0.which_io, reg0.phys_addr);
return -ENXIO;
}
#endif
if ((int)reg0.reg_size <= 0) {
printk("jsflash: bad size 0x%x\n", (int)reg0.reg_size);
return -ENXIO;
}
} else {
printk("jsflash: no /flash-memory node, use PROLL >= 12\n");
prom_getproperty(prom_root_node, "banner-name", banner, 128);
if (strcmp (banner, "JavaStation-NC") != 0 &&
strcmp (banner, "JavaStation-E") != 0) {
return -ENXIO;
}
reg0.which_io = 0;
reg0.phys_addr = 0x20400000;
reg0.reg_size = 0x00800000;
}
if (sparc_cpu_model != sun4m) {
return -ENXIO;
}
if (jsf0.base == 0) {
jsf = &jsf0;
jsf->base = reg0.phys_addr;
jsf->size = reg0.reg_size;
jsf->id.off = JSF_BASE_ALL;
jsf->id.size = 0x01000000;
strcpy(jsf->id.name, "Krups_all");
jsf->dv[0].dbase = jsf->base;
jsf->dv[0].dsize = jsf->size;
jsf->dv[1].dbase = jsf->base + 1024;
jsf->dv[1].dsize = jsf->size - 1024;
jsf->dv[2].dbase = JSF_BASE_ALL;
jsf->dv[2].dsize = 0x01000000;
printk("Espresso Flash @0x%lx [%d MB]\n", jsf->base,
(int) (jsf->size / (1024*1024)));
}
if ((rc = misc_register(&jsf_dev)) != 0) {
printk(KERN_ERR "jsf: unable to get misc minor %d\n",
JSF_MINOR);
jsf0.base = 0;
return rc;
}
return 0;
}
static int jsfd_init(void)
{
static DEFINE_SPINLOCK(lock);
struct jsflash *jsf;
struct jsfd_part *jdp;
int err;
int i;
if (jsf0.base == 0)
return -ENXIO;
err = -ENOMEM;
for (i = 0; i < JSF_MAX; i++) {
struct gendisk *disk = alloc_disk(1);
if (!disk)
goto out;
disk->queue = blk_init_queue(jsfd_do_request, &lock);
if (!disk->queue) {
put_disk(disk);
goto out;
}
jsfd_disk[i] = disk;
}
if (register_blkdev(JSFD_MAJOR, "jsfd")) {
err = -EIO;
goto out;
}
for (i = 0; i < JSF_MAX; i++) {
struct gendisk *disk = jsfd_disk[i];
if ((i & JSF_PART_MASK) >= JSF_NPART) continue;
jsf = &jsf0;
jdp = &jsf->dv[i&JSF_PART_MASK];
disk->major = JSFD_MAJOR;
disk->first_minor = i;
sprintf(disk->disk_name, "jsfd%d", i);
disk->fops = &jsfd_fops;
set_capacity(disk, jdp->dsize >> 9);
disk->private_data = jdp;
add_disk(disk);
set_disk_ro(disk, 1);
}
return 0;
out:
while (i--)
put_disk(jsfd_disk[i]);
return err;
}
static int __init jsflash_init_module(void) {
int rc;
if ((rc = jsflash_init()) == 0) {
jsfd_init();
return 0;
}
return rc;
}
static void __exit jsflash_cleanup_module(void)
{
int i;
for (i = 0; i < JSF_MAX; i++) {
if ((i & JSF_PART_MASK) >= JSF_NPART) continue;
del_gendisk(jsfd_disk[i]);
blk_cleanup_queue(jsfd_disk[i]->queue);
put_disk(jsfd_disk[i]);
}
if (jsf0.busy)
printk("jsf0: cleaning busy unit\n");
jsf0.base = 0;
jsf0.busy = 0;
misc_deregister(&jsf_dev);
unregister_blkdev(JSFD_MAJOR, "jsfd");
}
