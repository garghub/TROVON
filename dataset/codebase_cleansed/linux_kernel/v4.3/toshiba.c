static int tosh_fn_status(void)
{
unsigned char scan;
unsigned long flags;
if (tosh_fn!=0) {
scan = inb(tosh_fn);
} else {
local_irq_save(flags);
outb(0x8e, 0xe4);
scan = inb(0xe5);
local_irq_restore(flags);
}
return (int) scan;
}
static int tosh_emulate_fan(SMMRegisters *regs)
{
unsigned long eax,ecx,flags;
unsigned char al;
eax = regs->eax & 0xff00;
ecx = regs->ecx & 0xffff;
if (tosh_id==0xfccb) {
if (eax==0xfe00) {
local_irq_save(flags);
outb(0xbe, 0xe4);
al = inb(0xe5);
local_irq_restore(flags);
regs->eax = 0x00;
regs->ecx = (unsigned int) (al & 0x01);
}
if ((eax==0xff00) && (ecx==0x0000)) {
local_irq_save(flags);
outb(0xbe, 0xe4);
al = inb(0xe5);
outb(0xbe, 0xe4);
outb (al | 0x01, 0xe5);
local_irq_restore(flags);
regs->eax = 0x00;
regs->ecx = 0x00;
}
if ((eax==0xff00) && (ecx==0x0001)) {
local_irq_save(flags);
outb(0xbe, 0xe4);
al = inb(0xe5);
outb(0xbe, 0xe4);
outb(al & 0xfe, 0xe5);
local_irq_restore(flags);
regs->eax = 0x00;
regs->ecx = 0x01;
}
}
if (tosh_id==0xfccc) {
if (eax==0xfe00) {
local_irq_save(flags);
outb(0xe0, 0xe4);
al = inb(0xe5);
local_irq_restore(flags);
regs->eax = 0x00;
regs->ecx = al & 0x01;
}
if ((eax==0xff00) && (ecx==0x0000)) {
local_irq_save(flags);
outb(0xe0, 0xe4);
al = inb(0xe5);
outw(0xe0 | ((al & 0xfe) << 8), 0xe4);
local_irq_restore(flags);
regs->eax = 0x00;
regs->ecx = 0x00;
}
if ((eax==0xff00) && (ecx==0x0001)) {
local_irq_save(flags);
outb(0xe0, 0xe4);
al = inb(0xe5);
outw(0xe0 | ((al | 0x01) << 8), 0xe4);
local_irq_restore(flags);
regs->eax = 0x00;
regs->ecx = 0x01;
}
}
return 0;
}
int tosh_smm(SMMRegisters *regs)
{
int eax;
asm ("# load the values into the registers\n\t" \
"pushl %%eax\n\t" \
"movl 0(%%eax),%%edx\n\t" \
"push %%edx\n\t" \
"movl 4(%%eax),%%ebx\n\t" \
"movl 8(%%eax),%%ecx\n\t" \
"movl 12(%%eax),%%edx\n\t" \
"movl 16(%%eax),%%esi\n\t" \
"movl 20(%%eax),%%edi\n\t" \
"popl %%eax\n\t" \
"# call the System Management mode\n\t" \
"inb $0xb2,%%al\n\t"
"# fill out the memory with the values in the registers\n\t" \
"xchgl %%eax,(%%esp)\n\t"
"movl %%ebx,4(%%eax)\n\t" \
"movl %%ecx,8(%%eax)\n\t" \
"movl %%edx,12(%%eax)\n\t" \
"movl %%esi,16(%%eax)\n\t" \
"movl %%edi,20(%%eax)\n\t" \
"popl %%edx\n\t" \
"movl %%edx,0(%%eax)\n\t" \
"# setup the return value to the carry flag\n\t" \
"lahf\n\t" \
"shrl $8,%%eax\n\t" \
"andl $1,%%eax\n" \
: "=a" (eax)
: "a" (regs)
: "%ebx", "%ecx", "%edx", "%esi", "%edi", "memory");
return eax;
}
static long tosh_ioctl(struct file *fp, unsigned int cmd, unsigned long arg)
{
SMMRegisters regs;
SMMRegisters __user *argp = (SMMRegisters __user *)arg;
unsigned short ax,bx;
int err;
if (!argp)
return -EINVAL;
if (copy_from_user(&regs, argp, sizeof(SMMRegisters)))
return -EFAULT;
switch (cmd) {
case TOSH_SMM:
ax = regs.eax & 0xff00;
bx = regs.ebx & 0xffff;
if (((ax==0xff00) || (ax==0xfe00)) && (bx>0x0069))
return -EINVAL;
mutex_lock(&tosh_mutex);
if (tosh_fan==1) {
if (((ax==0xf300) || (ax==0xf400)) && (bx==0x0004)) {
err = tosh_emulate_fan(&regs);
mutex_unlock(&tosh_mutex);
break;
}
}
err = tosh_smm(&regs);
mutex_unlock(&tosh_mutex);
break;
default:
return -EINVAL;
}
if (copy_to_user(argp, &regs, sizeof(SMMRegisters)))
return -EFAULT;
return (err==0) ? 0:-EINVAL;
}
static int proc_toshiba_show(struct seq_file *m, void *v)
{
int key;
key = tosh_fn_status();
seq_printf(m, "1.1 0x%04x %d.%d %d.%d 0x%04x 0x%02x\n",
tosh_id,
(tosh_sci & 0xff00)>>8,
tosh_sci & 0xff,
(tosh_bios & 0xff00)>>8,
tosh_bios & 0xff,
tosh_date,
key);
return 0;
}
static int proc_toshiba_open(struct inode *inode, struct file *file)
{
return single_open(file, proc_toshiba_show, NULL);
}
static void tosh_set_fn_port(void)
{
switch (tosh_id) {
case 0xfc02: case 0xfc04: case 0xfc09: case 0xfc0a: case 0xfc10:
case 0xfc11: case 0xfc13: case 0xfc15: case 0xfc1a: case 0xfc1b:
case 0xfc5a:
tosh_fn = 0x62;
break;
case 0xfc08: case 0xfc17: case 0xfc1d: case 0xfcd1: case 0xfce0:
case 0xfce2:
tosh_fn = 0x68;
break;
default:
tosh_fn = 0x00;
break;
}
return;
}
static int tosh_get_machine_id(void __iomem *bios)
{
int id;
SMMRegisters regs;
unsigned short bx,cx;
unsigned long address;
id = (0x100*(int) readb(bios+0xfffe))+((int) readb(bios+0xfffa));
if (id==0xfc2f) {
regs.eax = 0xc000;
regs.ebx = 0x0000;
regs.ecx = 0x0000;
tosh_smm(&regs);
bx = (unsigned short) (regs.ebx & 0xffff);
#if TOSH_DEBUG
printk("toshiba: debugging ID ebx=0x%04x\n", regs.ebx);
#endif
bx = 0xe6f5;
address = bx;
cx = readw(bios + address);
address = 9+bx+cx;
cx = readw(bios + address);
address = 0xa+cx;
cx = readw(bios + address);
id = ((cx & 0xff)<<8)+((cx & 0xff00)>>8);
}
return id;
}
static int tosh_probe(void)
{
int i,major,minor,day,year,month,flag;
unsigned char signature[7] = { 0x54,0x4f,0x53,0x48,0x49,0x42,0x41 };
SMMRegisters regs;
void __iomem *bios = ioremap(0xf0000, 0x10000);
if (!bios)
return -ENOMEM;
for (i=0;i<7;i++) {
if (readb(bios+0xe010+i)!=signature[i]) {
printk("toshiba: not a supported Toshiba laptop\n");
iounmap(bios);
return -ENODEV;
}
}
regs.eax = 0xf0f0;
regs.ebx = 0x0000;
regs.ecx = 0x0000;
flag = tosh_smm(&regs);
if ((flag==1) || ((regs.eax & 0xff00)==0x8600)) {
printk("toshiba: not a supported Toshiba laptop\n");
iounmap(bios);
return -ENODEV;
}
tosh_sci = regs.edx & 0xffff;
tosh_id = tosh_get_machine_id(bios);
major = readb(bios+0xe009)-'0';
minor = ((readb(bios+0xe00b)-'0')*10)+(readb(bios+0xe00c)-'0');
tosh_bios = (major*0x100)+minor;
day = ((readb(bios+0xfff5)-'0')*10)+(readb(bios+0xfff6)-'0');
month = ((readb(bios+0xfff8)-'0')*10)+(readb(bios+0xfff9)-'0');
year = ((readb(bios+0xfffb)-'0')*10)+(readb(bios+0xfffc)-'0');
tosh_date = (((year-90) & 0x1f)<<10) | ((month & 0xf)<<6)
| ((day & 0x1f)<<1);
if ((tosh_id==0xfccb) || (tosh_id==0xfccc))
tosh_fan = 1;
iounmap(bios);
return 0;
}
static int __init toshiba_init(void)
{
int retval;
if (tosh_probe())
return -ENODEV;
printk(KERN_INFO "Toshiba System Management Mode driver v" TOSH_VERSION "\n");
if (tosh_fn==0x00)
tosh_set_fn_port();
retval = misc_register(&tosh_device);
if (retval < 0)
return retval;
#ifdef CONFIG_PROC_FS
{
struct proc_dir_entry *pde;
pde = proc_create("toshiba", 0, NULL, &proc_toshiba_fops);
if (!pde) {
misc_deregister(&tosh_device);
return -ENOMEM;
}
}
#endif
return 0;
}
static void __exit toshiba_exit(void)
{
remove_proc_entry("toshiba", NULL);
misc_deregister(&tosh_device);
}
