static void
setparam (struct zoran *zr,
char *name,
char *sval)
{
int i = 0, reg0, reg, val;
while (zr67[i].name != NULL) {
if (!strncmp(name, zr67[i].name, strlen(zr67[i].name))) {
reg = reg0 = btread(zr67[i].reg);
reg &= ~(zr67[i].mask << zr67[i].bit);
if (!isdigit(sval[0]))
break;
val = simple_strtoul(sval, NULL, 0);
if ((val & ~zr67[i].mask))
break;
reg |= (val & zr67[i].mask) << zr67[i].bit;
dprintk(4,
KERN_INFO
"%s: setparam: setting ZR36067 register 0x%03x: 0x%08x=>0x%08x %s=%d\n",
ZR_DEVNAME(zr), zr67[i].reg, reg0, reg,
zr67[i].name, val);
btwrite(reg, zr67[i].reg);
break;
}
i++;
}
}
static int zoran_show(struct seq_file *p, void *v)
{
struct zoran *zr = p->private;
int i;
seq_printf(p, "ZR36067 registers:\n");
for (i = 0; i < 0x130; i += 16)
seq_printf(p, "%03X %08X %08X %08X %08X \n", i,
btread(i), btread(i+4), btread(i+8), btread(i+12));
return 0;
}
static int zoran_open(struct inode *inode, struct file *file)
{
struct zoran *data = PDE(inode)->data;
return single_open(file, zoran_show, data);
}
static ssize_t zoran_write(struct file *file, const char __user *buffer,
size_t count, loff_t *ppos)
{
struct zoran *zr = PDE(file_inode(file))->data;
char *string, *sp;
char *line, *ldelim, *varname, *svar, *tdelim;
if (count > 32768)
return -EINVAL;
string = sp = vmalloc(count + 1);
if (!string) {
dprintk(1,
KERN_ERR
"%s: write_proc: can not allocate memory\n",
ZR_DEVNAME(zr));
return -ENOMEM;
}
if (copy_from_user(string, buffer, count)) {
vfree (string);
return -EFAULT;
}
string[count] = 0;
dprintk(4, KERN_INFO "%s: write_proc: name=%s count=%zu zr=%p\n",
ZR_DEVNAME(zr), file->f_path.dentry->d_name.name, count, zr);
ldelim = " \t\n";
tdelim = "=";
line = strpbrk(sp, ldelim);
while (line) {
*line = 0;
svar = strpbrk(sp, tdelim);
if (svar) {
*svar = 0;
varname = sp;
svar++;
setparam(zr, varname, svar);
}
sp = line + 1;
line = strpbrk(sp, ldelim);
}
vfree(string);
return count;
}
int
zoran_proc_init (struct zoran *zr)
{
#ifdef CONFIG_PROC_FS
char name[8];
snprintf(name, 7, "zoran%d", zr->id);
zr->zoran_proc = proc_create_data(name, 0, NULL, &zoran_operations, zr);
if (zr->zoran_proc != NULL) {
dprintk(2,
KERN_INFO
"%s: procfs entry /proc/%s allocated. data=%p\n",
ZR_DEVNAME(zr), name, zr->zoran_proc->data);
} else {
dprintk(1, KERN_ERR "%s: Unable to initialise /proc/%s\n",
ZR_DEVNAME(zr), name);
return 1;
}
#endif
return 0;
}
void
zoran_proc_cleanup (struct zoran *zr)
{
#ifdef CONFIG_PROC_FS
char name[8];
snprintf(name, 7, "zoran%d", zr->id);
if (zr->zoran_proc)
remove_proc_entry(name, NULL);
zr->zoran_proc = NULL;
#endif
}
