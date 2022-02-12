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
static int dump_fit_entry(char *page, unsigned long *fentry)
{
unsigned type;
type = FIT_TYPE(fentry[1]);
return sprintf(page, "%02x %-25s %x.%02x %016lx %u\n",
type,
fit_type_name(type),
FIT_MAJOR(fentry[1]), FIT_MINOR(fentry[1]),
fentry[0],
(unsigned)(fentry[1] & 0xffffff) * 16);
}
static int
dump_fit(char *page, unsigned long nasid)
{
unsigned long fentry[2];
int index;
char *p;
p = page;
for (index=0;;index++) {
BUG_ON(index * 60 > PAGE_SIZE);
if (get_fit_entry(nasid, index, fentry, NULL, 0))
break;
p += dump_fit_entry(p, fentry);
}
return p - page;
}
static int
dump_version(char *page, unsigned long nasid)
{
unsigned long fentry[2];
char banner[128];
int index;
int len;
for (index = 0; ; index++) {
if (get_fit_entry(nasid, index, fentry, banner,
sizeof(banner)))
return 0;
if (FIT_TYPE(fentry[1]) == FIT_ENTRY_SAL_A)
break;
}
len = sprintf(page, "%x.%02x\n", FIT_MAJOR(fentry[1]),
FIT_MINOR(fentry[1]));
page += len;
if (banner[0])
len += snprintf(page, PAGE_SIZE-len, "%s\n", banner);
return len;
}
static int
proc_calc_metrics(char *page, char **start, off_t off, int count, int *eof,
int len)
{
if (len <= off + count)
*eof = 1;
*start = page + off;
len -= off;
if (len > count)
len = count;
if (len < 0)
len = 0;
return len;
}
static int
read_version_entry(char *page, char **start, off_t off, int count, int *eof,
void *data)
{
int len;
len = dump_version(page, (unsigned long)data);
len = proc_calc_metrics(page, start, off, count, eof, len);
return len;
}
static int
read_fit_entry(char *page, char **start, off_t off, int count, int *eof,
void *data)
{
int len;
len = dump_fit(page, (unsigned long)data);
len = proc_calc_metrics(page, start, off, count, eof, len);
return len;
}
int __init prominfo_init(void)
{
struct proc_dir_entry **entp;
cnodeid_t cnodeid;
unsigned long nasid;
int size;
char name[NODE_NAME_LEN];
if (!ia64_platform_is("sn2"))
return 0;
size = num_online_nodes() * sizeof(struct proc_dir_entry *);
proc_entries = kzalloc(size, GFP_KERNEL);
if (!proc_entries)
return -ENOMEM;
sgi_prominfo_entry = proc_mkdir("sgi_prominfo", NULL);
entp = proc_entries;
for_each_online_node(cnodeid) {
sprintf(name, "node%d", cnodeid);
*entp = proc_mkdir(name, sgi_prominfo_entry);
nasid = cnodeid_to_nasid(cnodeid);
create_proc_read_entry("fit", 0, *entp, read_fit_entry,
(void *)nasid);
create_proc_read_entry("version", 0, *entp,
read_version_entry, (void *)nasid);
entp++;
}
return 0;
}
void __exit prominfo_exit(void)
{
struct proc_dir_entry **entp;
unsigned int cnodeid;
char name[NODE_NAME_LEN];
entp = proc_entries;
for_each_online_node(cnodeid) {
remove_proc_entry("fit", *entp);
remove_proc_entry("version", *entp);
sprintf(name, "node%d", cnodeid);
remove_proc_entry(name, sgi_prominfo_entry);
entp++;
}
remove_proc_entry("sgi_prominfo", NULL);
kfree(proc_entries);
}
