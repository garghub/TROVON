static int srm_env_proc_show(struct seq_file *m, void *v)
{
unsigned long ret;
srm_env_t *entry;
char *page;
entry = m->private;
page = (char *)__get_free_page(GFP_USER);
if (!page)
return -ENOMEM;
ret = callback_getenv(entry->id, page, PAGE_SIZE);
if ((ret >> 61) == 0) {
seq_write(m, page, ret);
ret = 0;
} else
ret = -EFAULT;
free_page((unsigned long)page);
return ret;
}
static int srm_env_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, srm_env_proc_show, PDE(inode)->data);
}
static ssize_t srm_env_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *pos)
{
int res;
srm_env_t *entry = PDE(file->f_path.dentry->d_inode)->data;
char *buf = (char *) __get_free_page(GFP_USER);
unsigned long ret1, ret2;
if (!buf)
return -ENOMEM;
res = -EINVAL;
if (count >= PAGE_SIZE)
goto out;
res = -EFAULT;
if (copy_from_user(buf, buffer, count))
goto out;
buf[count] = '\0';
ret1 = callback_setenv(entry->id, buf, count);
if ((ret1 >> 61) == 0) {
do
ret2 = callback_save_env();
while((ret2 >> 61) == 1);
res = (int) ret1;
}
out:
free_page((unsigned long)buf);
return res;
}
static void
srm_env_cleanup(void)
{
srm_env_t *entry;
unsigned long var_num;
if (base_dir) {
if (named_dir) {
entry = srm_named_entries;
while (entry->name != NULL && entry->id != 0) {
if (entry->proc_entry) {
remove_proc_entry(entry->name,
named_dir);
entry->proc_entry = NULL;
}
entry++;
}
remove_proc_entry(NAMED_DIR, base_dir);
}
if (numbered_dir) {
for (var_num = 0; var_num <= 255; var_num++) {
entry = &srm_numbered_entries[var_num];
if (entry->proc_entry) {
remove_proc_entry(entry->name,
numbered_dir);
entry->proc_entry = NULL;
entry->name = NULL;
}
}
remove_proc_entry(NUMBERED_DIR, base_dir);
}
remove_proc_entry(BASE_DIR, NULL);
}
return;
}
static int __init
srm_env_init(void)
{
srm_env_t *entry;
unsigned long var_num;
if (!alpha_using_srm) {
printk(KERN_INFO "%s: This Alpha system doesn't "
"know about SRM (or you've booted "
"SRM->MILO->Linux, which gets "
"misdetected)...\n", __func__);
return -ENODEV;
}
for (var_num = 0; var_num <= 255; var_num++)
sprintf(number[var_num], "%ld", var_num);
base_dir = proc_mkdir(BASE_DIR, NULL);
if (!base_dir) {
printk(KERN_ERR "Couldn't create base dir /proc/%s\n",
BASE_DIR);
goto cleanup;
}
named_dir = proc_mkdir(NAMED_DIR, base_dir);
if (!named_dir) {
printk(KERN_ERR "Couldn't create dir /proc/%s/%s\n",
BASE_DIR, NAMED_DIR);
goto cleanup;
}
numbered_dir = proc_mkdir(NUMBERED_DIR, base_dir);
if (!numbered_dir) {
printk(KERN_ERR "Couldn't create dir /proc/%s/%s\n",
BASE_DIR, NUMBERED_DIR);
goto cleanup;
}
entry = srm_named_entries;
while (entry->name && entry->id) {
entry->proc_entry = proc_create_data(entry->name, 0644, named_dir,
&srm_env_proc_fops, entry);
if (!entry->proc_entry)
goto cleanup;
entry++;
}
for (var_num = 0; var_num <= 255; var_num++) {
entry = &srm_numbered_entries[var_num];
entry->name = number[var_num];
entry->proc_entry = proc_create_data(entry->name, 0644, numbered_dir,
&srm_env_proc_fops, entry);
if (!entry->proc_entry)
goto cleanup;
entry->id = var_num;
}
printk(KERN_INFO "%s: version %s loaded successfully\n", NAME,
VERSION);
return 0;
cleanup:
srm_env_cleanup();
return -ENOMEM;
}
static void __exit
srm_env_exit(void)
{
srm_env_cleanup();
printk(KERN_INFO "%s: unloaded successfully\n", NAME);
return;
}
