static struct scsi_dev_info_list_table *scsi_devinfo_lookup_by_key(int key)
{
struct scsi_dev_info_list_table *devinfo_table;
int found = 0;
list_for_each_entry(devinfo_table, &scsi_dev_info_list, node)
if (devinfo_table->key == key) {
found = 1;
break;
}
if (!found)
return ERR_PTR(-EINVAL);
return devinfo_table;
}
static void scsi_strcpy_devinfo(char *name, char *to, size_t to_length,
char *from, int compatible)
{
size_t from_length;
from_length = strlen(from);
strncpy(to, from, min(to_length, from_length));
if (from_length < to_length) {
if (compatible) {
to[from_length] = '\0';
} else {
strncpy(&to[from_length], spaces,
to_length - from_length);
}
}
if (from_length > to_length)
printk(KERN_WARNING "%s: %s string '%s' is too long\n",
__func__, name, from);
}
static int scsi_dev_info_list_add(int compatible, char *vendor, char *model,
char *strflags, int flags)
{
return scsi_dev_info_list_add_keyed(compatible, vendor, model,
strflags, flags,
SCSI_DEVINFO_GLOBAL);
}
int scsi_dev_info_list_add_keyed(int compatible, char *vendor, char *model,
char *strflags, int flags, int key)
{
struct scsi_dev_info_list *devinfo;
struct scsi_dev_info_list_table *devinfo_table =
scsi_devinfo_lookup_by_key(key);
if (IS_ERR(devinfo_table))
return PTR_ERR(devinfo_table);
devinfo = kmalloc(sizeof(*devinfo), GFP_KERNEL);
if (!devinfo) {
printk(KERN_ERR "%s: no memory\n", __func__);
return -ENOMEM;
}
scsi_strcpy_devinfo("vendor", devinfo->vendor, sizeof(devinfo->vendor),
vendor, compatible);
scsi_strcpy_devinfo("model", devinfo->model, sizeof(devinfo->model),
model, compatible);
if (strflags)
devinfo->flags = simple_strtoul(strflags, NULL, 0);
else
devinfo->flags = flags;
devinfo->compatible = compatible;
if (compatible)
list_add_tail(&devinfo->dev_info_list,
&devinfo_table->scsi_dev_info_list);
else
list_add(&devinfo->dev_info_list,
&devinfo_table->scsi_dev_info_list);
return 0;
}
static struct scsi_dev_info_list *scsi_dev_info_list_find(const char *vendor,
const char *model, int key)
{
struct scsi_dev_info_list *devinfo;
struct scsi_dev_info_list_table *devinfo_table =
scsi_devinfo_lookup_by_key(key);
size_t vmax, mmax;
const char *vskip, *mskip;
if (IS_ERR(devinfo_table))
return (struct scsi_dev_info_list *) devinfo_table;
vmax = 8;
vskip = vendor;
while (vmax > 0 && *vskip == ' ') {
vmax--;
vskip++;
}
while (vmax > 0 && vskip[vmax - 1] == ' ')
--vmax;
mmax = 16;
mskip = model;
while (mmax > 0 && *mskip == ' ') {
mmax--;
mskip++;
}
while (mmax > 0 && mskip[mmax - 1] == ' ')
--mmax;
list_for_each_entry(devinfo, &devinfo_table->scsi_dev_info_list,
dev_info_list) {
if (devinfo->compatible) {
if (memcmp(devinfo->vendor, vskip, vmax) ||
devinfo->vendor[vmax])
continue;
if (memcmp(devinfo->model, mskip, mmax) ||
devinfo->model[mmax])
continue;
return devinfo;
} else {
if (!memcmp(devinfo->vendor, vendor,
sizeof(devinfo->vendor)) &&
!memcmp(devinfo->model, model,
sizeof(devinfo->model)))
return devinfo;
}
}
return ERR_PTR(-ENOENT);
}
int scsi_dev_info_list_del_keyed(char *vendor, char *model, int key)
{
struct scsi_dev_info_list *found;
found = scsi_dev_info_list_find(vendor, model, key);
if (IS_ERR(found))
return PTR_ERR(found);
list_del(&found->dev_info_list);
kfree(found);
return 0;
}
static int scsi_dev_info_list_add_str(char *dev_list)
{
char *vendor, *model, *strflags, *next;
char *next_check;
int res = 0;
next = dev_list;
if (next && next[0] == '"') {
next++;
next_check = ",\"";
} else {
next_check = ",";
}
for (vendor = strsep(&next, ":"); vendor && (vendor[0] != '\0')
&& (res == 0); vendor = strsep(&next, ":")) {
strflags = NULL;
model = strsep(&next, ":");
if (model)
strflags = strsep(&next, next_check);
if (!model || !strflags) {
printk(KERN_ERR "%s: bad dev info string '%s' '%s'"
" '%s'\n", __func__, vendor, model,
strflags);
res = -EINVAL;
} else
res = scsi_dev_info_list_add(0 , vendor,
model, strflags, 0);
}
return res;
}
int scsi_get_device_flags(struct scsi_device *sdev,
const unsigned char *vendor,
const unsigned char *model)
{
return scsi_get_device_flags_keyed(sdev, vendor, model,
SCSI_DEVINFO_GLOBAL);
}
int scsi_get_device_flags_keyed(struct scsi_device *sdev,
const unsigned char *vendor,
const unsigned char *model,
int key)
{
struct scsi_dev_info_list *devinfo;
int err;
devinfo = scsi_dev_info_list_find(vendor, model, key);
if (!IS_ERR(devinfo))
return devinfo->flags;
err = PTR_ERR(devinfo);
if (err != -ENOENT)
return err;
if (key != SCSI_DEVINFO_GLOBAL)
return 0;
if (sdev->sdev_bflags)
return sdev->sdev_bflags;
return scsi_default_dev_flags;
}
static int devinfo_seq_show(struct seq_file *m, void *v)
{
struct double_list *dl = v;
struct scsi_dev_info_list_table *devinfo_table =
list_entry(dl->top, struct scsi_dev_info_list_table, node);
struct scsi_dev_info_list *devinfo =
list_entry(dl->bottom, struct scsi_dev_info_list,
dev_info_list);
if (devinfo_table->scsi_dev_info_list.next == dl->bottom &&
devinfo_table->name)
seq_printf(m, "[%s]:\n", devinfo_table->name);
seq_printf(m, "'%.8s' '%.16s' 0x%x\n",
devinfo->vendor, devinfo->model, devinfo->flags);
return 0;
}
static void *devinfo_seq_start(struct seq_file *m, loff_t *ppos)
{
struct double_list *dl = kmalloc(sizeof(*dl), GFP_KERNEL);
loff_t pos = *ppos;
if (!dl)
return NULL;
list_for_each(dl->top, &scsi_dev_info_list) {
struct scsi_dev_info_list_table *devinfo_table =
list_entry(dl->top, struct scsi_dev_info_list_table,
node);
list_for_each(dl->bottom, &devinfo_table->scsi_dev_info_list)
if (pos-- == 0)
return dl;
}
kfree(dl);
return NULL;
}
static void *devinfo_seq_next(struct seq_file *m, void *v, loff_t *ppos)
{
struct double_list *dl = v;
struct scsi_dev_info_list_table *devinfo_table =
list_entry(dl->top, struct scsi_dev_info_list_table, node);
++*ppos;
dl->bottom = dl->bottom->next;
while (&devinfo_table->scsi_dev_info_list == dl->bottom) {
dl->top = dl->top->next;
if (dl->top == &scsi_dev_info_list) {
kfree(dl);
return NULL;
}
devinfo_table = list_entry(dl->top,
struct scsi_dev_info_list_table,
node);
dl->bottom = devinfo_table->scsi_dev_info_list.next;
}
return dl;
}
static void devinfo_seq_stop(struct seq_file *m, void *v)
{
kfree(v);
}
static int proc_scsi_devinfo_open(struct inode *inode, struct file *file)
{
return seq_open(file, &scsi_devinfo_seq_ops);
}
static ssize_t proc_scsi_devinfo_write(struct file *file,
const char __user *buf,
size_t length, loff_t *ppos)
{
char *buffer;
ssize_t err = length;
if (!buf || length>PAGE_SIZE)
return -EINVAL;
if (!(buffer = (char *) __get_free_page(GFP_KERNEL)))
return -ENOMEM;
if (copy_from_user(buffer, buf, length)) {
err =-EFAULT;
goto out;
}
if (length < PAGE_SIZE)
buffer[length] = '\0';
else if (buffer[PAGE_SIZE-1]) {
err = -EINVAL;
goto out;
}
scsi_dev_info_list_add_str(buffer);
out:
free_page((unsigned long)buffer);
return err;
}
void scsi_exit_devinfo(void)
{
#ifdef CONFIG_SCSI_PROC_FS
remove_proc_entry("scsi/device_info", NULL);
#endif
scsi_dev_info_remove_list(SCSI_DEVINFO_GLOBAL);
}
int scsi_dev_info_add_list(int key, const char *name)
{
struct scsi_dev_info_list_table *devinfo_table =
scsi_devinfo_lookup_by_key(key);
if (!IS_ERR(devinfo_table))
return -EEXIST;
devinfo_table = kmalloc(sizeof(*devinfo_table), GFP_KERNEL);
if (!devinfo_table)
return -ENOMEM;
INIT_LIST_HEAD(&devinfo_table->node);
INIT_LIST_HEAD(&devinfo_table->scsi_dev_info_list);
devinfo_table->name = name;
devinfo_table->key = key;
list_add_tail(&devinfo_table->node, &scsi_dev_info_list);
return 0;
}
int scsi_dev_info_remove_list(int key)
{
struct list_head *lh, *lh_next;
struct scsi_dev_info_list_table *devinfo_table =
scsi_devinfo_lookup_by_key(key);
if (IS_ERR(devinfo_table))
return -EINVAL;
list_del(&devinfo_table->node);
list_for_each_safe(lh, lh_next, &devinfo_table->scsi_dev_info_list) {
struct scsi_dev_info_list *devinfo;
devinfo = list_entry(lh, struct scsi_dev_info_list,
dev_info_list);
kfree(devinfo);
}
kfree(devinfo_table);
return 0;
}
int __init scsi_init_devinfo(void)
{
#ifdef CONFIG_SCSI_PROC_FS
struct proc_dir_entry *p;
#endif
int error, i;
error = scsi_dev_info_add_list(SCSI_DEVINFO_GLOBAL, NULL);
if (error)
return error;
error = scsi_dev_info_list_add_str(scsi_dev_flags);
if (error)
goto out;
for (i = 0; scsi_static_device_list[i].vendor; i++) {
error = scsi_dev_info_list_add(1 ,
scsi_static_device_list[i].vendor,
scsi_static_device_list[i].model,
NULL,
scsi_static_device_list[i].flags);
if (error)
goto out;
}
#ifdef CONFIG_SCSI_PROC_FS
p = proc_create("scsi/device_info", 0, NULL, &scsi_devinfo_proc_fops);
if (!p) {
error = -ENOMEM;
goto out;
}
#endif
out:
if (error)
scsi_exit_devinfo();
return error;
}
