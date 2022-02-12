static const char *fit_type_name(unsigned char type)
{
struct fit_type_map_t const *mapp;
for (mapp = fit_entry_types; mapp->type != 0xff; mapp++)
if (type == mapp->type)
return mapp->name;
if ((type > FIT_ENTRY_PAL_A) && (type < FIT_ENTRY_UNUSED))
return "OEM type";
if ((type > FIT_ENTRY_PAL_B) && (type < FIT_ENTRY_PAL_A))
return "Reserved";
return "Unknown type";
}
static int
get_fit_entry(unsigned long nasid, int index, unsigned long *fentry,
char *banner, int banlen)
{
return ia64_sn_get_fit_compt(nasid, index, fentry, banner, banlen);
}
static void dump_fit_entry(struct seq_file *m, unsigned long *fentry)
{
unsigned type;
type = FIT_TYPE(fentry[1]);
seq_printf(m, "%02x %-25s %x.%02x %016lx %u\n",
type,
fit_type_name(type),
FIT_MAJOR(fentry[1]), FIT_MINOR(fentry[1]),
fentry[0],
(unsigned)(fentry[1] & 0xffffff) * 16);
}
static int proc_fit_show(struct seq_file *m, void *v)
{
unsigned long nasid = (unsigned long)m->private;
unsigned long fentry[2];
int index;
for (index=0;;index++) {
BUG_ON(index * 60 > PAGE_SIZE);
if (get_fit_entry(nasid, index, fentry, NULL, 0))
break;
dump_fit_entry(m, fentry);
}
return 0;
}
static int proc_fit_open(struct inode *inode, struct file *file)
{
return single_open(file, proc_fit_show, PDE_DATA(inode));
}
static int proc_version_show(struct seq_file *m, void *v)
{
unsigned long nasid = (unsigned long)m->private;
unsigned long fentry[2];
char banner[128];
int index;
for (index = 0; ; index++) {
if (get_fit_entry(nasid, index, fentry, banner,
sizeof(banner)))
return 0;
if (FIT_TYPE(fentry[1]) == FIT_ENTRY_SAL_A)
break;
}
seq_printf(m, "%x.%02x\n", FIT_MAJOR(fentry[1]), FIT_MINOR(fentry[1]));
if (banner[0])
seq_printf(m, "%s\n", banner);
return 0;
}
static int proc_version_open(struct inode *inode, struct file *file)
{
return single_open(file, proc_version_show, PDE_DATA(inode));
}
int __init prominfo_init(void)
{
struct proc_dir_entry *sgi_prominfo_entry;
cnodeid_t cnodeid;
if (!ia64_platform_is("sn2"))
return 0;
sgi_prominfo_entry = proc_mkdir("sgi_prominfo", NULL);
if (!sgi_prominfo_entry)
return -ENOMEM;
for_each_online_node(cnodeid) {
struct proc_dir_entry *dir;
unsigned long nasid;
char name[NODE_NAME_LEN];
sprintf(name, "node%d", cnodeid);
dir = proc_mkdir(name, sgi_prominfo_entry);
if (!dir)
continue;
nasid = cnodeid_to_nasid(cnodeid);
proc_create_data("fit", 0, dir,
&proc_fit_fops, (void *)nasid);
proc_create_data("version", 0, dir,
&proc_version_fops, (void *)nasid);
}
return 0;
}
void __exit prominfo_exit(void)
{
remove_proc_subtree("sgi_prominfo", NULL);
}
