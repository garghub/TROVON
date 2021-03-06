static struct proc_dir_entry *proc_getdir(char *name,
struct proc_dir_entry *proc_dir)
{
struct proc_dir_entry *pde = proc_dir;
for (pde = pde->subdir; pde; pde = pde->next) {
if (pde->namelen && (strcmp(name, pde->name) == 0)) {
break;
}
}
if (pde == (struct proc_dir_entry *)0) {
pde = create_proc_entry(name, S_IFDIR, proc_dir);
if (pde == (struct proc_dir_entry *)0) {
return (pde);
}
}
return (pde);
}
int
bypass_proc_create_entry_sd(struct pfs_unit *pfs_unit_curr,
char *proc_name,
write_proc_t * write_proc,
read_proc_t * read_proc,
struct proc_dir_entry *parent_pfs, void *data)
{
strcpy(pfs_unit_curr->proc_name, proc_name);
pfs_unit_curr->proc_entry = create_proc_entry(pfs_unit_curr->proc_name,
S_IFREG | S_IRUSR |
S_IWUSR | S_IRGRP |
S_IROTH, parent_pfs);
if (pfs_unit_curr->proc_entry == 0) {
return -1;
}
pfs_unit_curr->proc_entry->read_proc = read_proc;
pfs_unit_curr->proc_entry->write_proc = write_proc;
pfs_unit_curr->proc_entry->data = data;
return 0;
}
int
get_bypass_info_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0;
len += sprintf(page, "Name\t\t\t%s\n", pbp_device_block->bp_name);
len +=
sprintf(page + len, "Firmware version\t0x%x\n",
pbp_device_block->bp_fw_ver);
*eof = 1;
return len;
}
int
get_bypass_slave_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
struct pci_dev *pci_slave_dev = pbp_device_block->bp_slave;
struct net_device *net_slave_dev;
int len = 0;
if (is_bypass_fn(pbp_device_block)) {
net_slave_dev = pci_get_drvdata(pci_slave_dev);
if (net_slave_dev)
len = sprintf(page, "%s\n", net_slave_dev->name);
else
len = sprintf(page, "fail\n");
} else
len = sprintf(page, "fail\n");
*eof = 1;
return len;
}
int
get_bypass_caps_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0;
ret = get_bypass_caps_fn(pbp_device_block);
if (ret == BP_NOT_CAP)
len = sprintf(page, "-1\n");
else
len = sprintf(page, "0x%x\n", ret);
*eof = 1;
return len;
}
int
get_wd_set_caps_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0;
ret = get_wd_set_caps_fn(pbp_device_block);
if (ret == BP_NOT_CAP)
len = sprintf(page, "-1\n");
else
len = sprintf(page, "0x%x\n", ret);
*eof = 1;
return len;
}
int
set_bypass_pfs(struct file *file, const char *buffer,
unsigned long count, void *data)
{
char kbuf[256];
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int bypass_param = 0, length = 0;
if (count > (sizeof(kbuf) - 1))
return -1;
if (copy_from_user(&kbuf, buffer, count)) {
return -1;
}
kbuf[count] = '\0';
length = strlen(kbuf);
if (kbuf[length - 1] == '\n')
kbuf[--length] = '\0';
if (strcmp(kbuf, "on") == 0)
bypass_param = 1;
else if (strcmp(kbuf, "off") == 0)
bypass_param = 0;
set_bypass_fn(pbp_device_block, bypass_param);
return count;
}
int
set_tap_pfs(struct file *file, const char *buffer,
unsigned long count, void *data)
{
char kbuf[256];
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int tap_param = 0, length = 0;
if (count > (sizeof(kbuf) - 1))
return -1;
if (copy_from_user(&kbuf, buffer, count)) {
return -1;
}
kbuf[count] = '\0';
length = strlen(kbuf);
if (kbuf[length - 1] == '\n')
kbuf[--length] = '\0';
if (strcmp(kbuf, "on") == 0)
tap_param = 1;
else if (strcmp(kbuf, "off") == 0)
tap_param = 0;
set_tap_fn(pbp_device_block, tap_param);
return count;
}
int
set_disc_pfs(struct file *file, const char *buffer,
unsigned long count, void *data)
{
char kbuf[256];
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int tap_param = 0, length = 0;
if (count > (sizeof(kbuf) - 1))
return -1;
if (copy_from_user(&kbuf, buffer, count)) {
return -1;
}
kbuf[count] = '\0';
length = strlen(kbuf);
if (kbuf[length - 1] == '\n')
kbuf[--length] = '\0';
if (strcmp(kbuf, "on") == 0)
tap_param = 1;
else if (strcmp(kbuf, "off") == 0)
tap_param = 0;
set_disc_fn(pbp_device_block, tap_param);
return count;
}
int
get_bypass_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0;
ret = get_bypass_fn(pbp_device_block);
if (ret == BP_NOT_CAP)
len = sprintf(page, "fail\n");
else if (ret == 1)
len = sprintf(page, "on\n");
else if (ret == 0)
len = sprintf(page, "off\n");
*eof = 1;
return len;
}
int
get_tap_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0;
ret = get_tap_fn(pbp_device_block);
if (ret == BP_NOT_CAP)
len = sprintf(page, "fail\n");
else if (ret == 1)
len = sprintf(page, "on\n");
else if (ret == 0)
len = sprintf(page, "off\n");
*eof = 1;
return len;
}
int
get_disc_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0;
ret = get_disc_fn(pbp_device_block);
if (ret == BP_NOT_CAP)
len = sprintf(page, "fail\n");
else if (ret == 1)
len = sprintf(page, "on\n");
else if (ret == 0)
len = sprintf(page, "off\n");
*eof = 1;
return len;
}
int
get_bypass_change_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0;
ret = get_bypass_change_fn(pbp_device_block);
if (ret == 1)
len = sprintf(page, "on\n");
else if (ret == 0)
len = sprintf(page, "off\n");
else
len = sprintf(page, "fail\n");
*eof = 1;
return len;
}
int
get_tap_change_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0;
ret = get_tap_change_fn(pbp_device_block);
if (ret == 1)
len = sprintf(page, "on\n");
else if (ret == 0)
len = sprintf(page, "off\n");
else
len = sprintf(page, "fail\n");
*eof = 1;
return len;
}
int
get_disc_change_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0;
ret = get_disc_change_fn(pbp_device_block);
if (ret == 1)
len = sprintf(page, "on\n");
else if (ret == 0)
len = sprintf(page, "off\n");
else
len = sprintf(page, "fail\n");
*eof = 1;
return len;
}
int
set_bypass_wd_pfs(struct file *file, const char *buffer,
unsigned long count, void *data)
{
char kbuf[256];
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
unsigned int timeout = 0;
char *timeout_ptr = kbuf;
if (copy_from_user(&kbuf, buffer, count)) {
return -1;
}
timeout_ptr = kbuf;
timeout = atoi(&timeout_ptr);
set_bypass_wd_fn(pbp_device_block, timeout);
return count;
}
int
get_bypass_wd_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0, timeout = 0;
ret = get_bypass_wd_fn(pbp_device_block, &timeout);
if (ret == BP_NOT_CAP)
len = sprintf(page, "fail\n");
else if (timeout == -1)
len = sprintf(page, "unknown\n");
else if (timeout == 0)
len = sprintf(page, "disable\n");
else
len = sprintf(page, "%d\n", timeout);
*eof = 1;
return len;
}
int
get_wd_expire_time_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0, timeout = 0;
ret = get_wd_expire_time_fn(pbp_device_block, &timeout);
if (ret == BP_NOT_CAP)
len = sprintf(page, "fail\n");
else if (timeout == -1)
len = sprintf(page, "expire\n");
else if (timeout == 0)
len = sprintf(page, "disable\n");
else
len = sprintf(page, "%d\n", timeout);
*eof = 1;
return len;
}
int
get_tpl_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0;
ret = get_tpl_fn(pbp_device_block);
if (ret == BP_NOT_CAP)
len = sprintf(page, "fail\n");
else if (ret == 1)
len = sprintf(page, "on\n");
else if (ret == 0)
len = sprintf(page, "off\n");
*eof = 1;
return len;
}
int
get_wait_at_pwup_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0;
ret = get_bp_wait_at_pwup_fn(pbp_device_block);
if (ret == BP_NOT_CAP)
len = sprintf(page, "fail\n");
else if (ret == 1)
len = sprintf(page, "on\n");
else if (ret == 0)
len = sprintf(page, "off\n");
*eof = 1;
return len;
}
int
get_hw_reset_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0;
ret = get_bp_hw_reset_fn(pbp_device_block);
if (ret == BP_NOT_CAP)
len = sprintf(page, "fail\n");
else if (ret == 1)
len = sprintf(page, "on\n");
else if (ret == 0)
len = sprintf(page, "off\n");
*eof = 1;
return len;
}
int
reset_bypass_wd_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0;
ret = reset_bypass_wd_timer_fn(pbp_device_block);
if (ret == BP_NOT_CAP)
len = sprintf(page, "fail\n");
else if (ret == 0)
len = sprintf(page, "disable\n");
else if (ret == 1)
len = sprintf(page, "success\n");
*eof = 1;
return len;
}
int
set_dis_bypass_pfs(struct file *file, const char *buffer,
unsigned long count, void *data)
{
char kbuf[256];
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int bypass_param = 0, length = 0;
if (copy_from_user(&kbuf, buffer, count)) {
return -1;
}
kbuf[count] = '\0';
length = strlen(kbuf);
if (kbuf[length - 1] == '\n')
kbuf[--length] = '\0';
if (strcmp(kbuf, "on") == 0)
bypass_param = 1;
else if (strcmp(kbuf, "off") == 0)
bypass_param = 0;
set_dis_bypass_fn(pbp_device_block, bypass_param);
return count;
}
int
set_dis_tap_pfs(struct file *file, const char *buffer,
unsigned long count, void *data)
{
char kbuf[256];
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int tap_param = 0, length = 0;
if (copy_from_user(&kbuf, buffer, count)) {
return -1;
}
kbuf[count] = '\0';
length = strlen(kbuf);
if (kbuf[length - 1] == '\n')
kbuf[--length] = '\0';
if (strcmp(kbuf, "on") == 0)
tap_param = 1;
else if (strcmp(kbuf, "off") == 0)
tap_param = 0;
set_dis_tap_fn(pbp_device_block, tap_param);
return count;
}
int
set_dis_disc_pfs(struct file *file, const char *buffer,
unsigned long count, void *data)
{
char kbuf[256];
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int tap_param = 0, length = 0;
if (copy_from_user(&kbuf, buffer, count)) {
return -1;
}
kbuf[count] = '\0';
length = strlen(kbuf);
if (kbuf[length - 1] == '\n')
kbuf[--length] = '\0';
if (strcmp(kbuf, "on") == 0)
tap_param = 1;
else if (strcmp(kbuf, "off") == 0)
tap_param = 0;
set_dis_disc_fn(pbp_device_block, tap_param);
return count;
}
int
get_dis_bypass_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0;
ret = get_dis_bypass_fn(pbp_device_block);
if (ret == BP_NOT_CAP)
len = sprintf(page, "fail\n");
else if (ret == 0)
len = sprintf(page, "off\n");
else
len = sprintf(page, "on\n");
*eof = 1;
return len;
}
int
get_dis_tap_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0;
ret = get_dis_tap_fn(pbp_device_block);
if (ret == BP_NOT_CAP)
len = sprintf(page, "fail\n");
else if (ret == 0)
len = sprintf(page, "off\n");
else
len = sprintf(page, "on\n");
*eof = 1;
return len;
}
int
get_dis_disc_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0;
ret = get_dis_disc_fn(pbp_device_block);
if (ret == BP_NOT_CAP)
len = sprintf(page, "fail\n");
else if (ret == 0)
len = sprintf(page, "off\n");
else
len = sprintf(page, "on\n");
*eof = 1;
return len;
}
int
set_bypass_pwup_pfs(struct file *file, const char *buffer,
unsigned long count, void *data)
{
char kbuf[256];
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int bypass_param = 0, length = 0;
if (copy_from_user(&kbuf, buffer, count)) {
return -1;
}
kbuf[count] = '\0';
length = strlen(kbuf);
if (kbuf[length - 1] == '\n')
kbuf[--length] = '\0';
if (strcmp(kbuf, "on") == 0)
bypass_param = 1;
else if (strcmp(kbuf, "off") == 0)
bypass_param = 0;
set_bypass_pwup_fn(pbp_device_block, bypass_param);
return count;
}
int
set_bypass_pwoff_pfs(struct file *file, const char *buffer,
unsigned long count, void *data)
{
char kbuf[256];
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int bypass_param = 0, length = 0;
if (copy_from_user(&kbuf, buffer, count)) {
return -1;
}
kbuf[count] = '\0';
length = strlen(kbuf);
if (kbuf[length - 1] == '\n')
kbuf[--length] = '\0';
if (strcmp(kbuf, "on") == 0)
bypass_param = 1;
else if (strcmp(kbuf, "off") == 0)
bypass_param = 0;
set_bypass_pwoff_fn(pbp_device_block, bypass_param);
return count;
}
int
set_tap_pwup_pfs(struct file *file, const char *buffer,
unsigned long count, void *data)
{
char kbuf[256];
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int tap_param = 0, length = 0;
if (copy_from_user(&kbuf, buffer, count)) {
return -1;
}
kbuf[count] = '\0';
length = strlen(kbuf);
if (kbuf[length - 1] == '\n')
kbuf[--length] = '\0';
if (strcmp(kbuf, "on") == 0)
tap_param = 1;
else if (strcmp(kbuf, "off") == 0)
tap_param = 0;
set_tap_pwup_fn(pbp_device_block, tap_param);
return count;
}
int
set_disc_pwup_pfs(struct file *file, const char *buffer,
unsigned long count, void *data)
{
char kbuf[256];
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int tap_param = 0, length = 0;
if (copy_from_user(&kbuf, buffer, count)) {
return -1;
}
kbuf[count] = '\0';
length = strlen(kbuf);
if (kbuf[length - 1] == '\n')
kbuf[--length] = '\0';
if (strcmp(kbuf, "on") == 0)
tap_param = 1;
else if (strcmp(kbuf, "off") == 0)
tap_param = 0;
set_disc_pwup_fn(pbp_device_block, tap_param);
return count;
}
int
get_bypass_pwup_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0;
ret = get_bypass_pwup_fn(pbp_device_block);
if (ret == BP_NOT_CAP)
len = sprintf(page, "fail\n");
else if (ret == 0)
len = sprintf(page, "off\n");
else
len = sprintf(page, "on\n");
*eof = 1;
return len;
}
int
get_bypass_pwoff_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0;
ret = get_bypass_pwoff_fn(pbp_device_block);
if (ret == BP_NOT_CAP)
len = sprintf(page, "fail\n");
else if (ret == 0)
len = sprintf(page, "off\n");
else
len = sprintf(page, "on\n");
*eof = 1;
return len;
}
int
get_tap_pwup_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0;
ret = get_tap_pwup_fn(pbp_device_block);
if (ret == BP_NOT_CAP)
len = sprintf(page, "fail\n");
else if (ret == 0)
len = sprintf(page, "off\n");
else
len = sprintf(page, "on\n");
*eof = 1;
return len;
}
int
get_disc_pwup_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0;
ret = get_disc_pwup_fn(pbp_device_block);
if (ret == BP_NOT_CAP)
len = sprintf(page, "fail\n");
else if (ret == 0)
len = sprintf(page, "off\n");
else
len = sprintf(page, "on\n");
*eof = 1;
return len;
}
int
set_std_nic_pfs(struct file *file, const char *buffer,
unsigned long count, void *data)
{
char kbuf[256];
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int bypass_param = 0, length = 0;
if (copy_from_user(&kbuf, buffer, count)) {
return -1;
}
kbuf[count] = '\0';
length = strlen(kbuf);
if (kbuf[length - 1] == '\n')
kbuf[--length] = '\0';
if (strcmp(kbuf, "on") == 0)
bypass_param = 1;
else if (strcmp(kbuf, "off") == 0)
bypass_param = 0;
set_std_nic_fn(pbp_device_block, bypass_param);
return count;
}
int
get_std_nic_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0;
ret = get_std_nic_fn(pbp_device_block);
if (ret == BP_NOT_CAP)
len = sprintf(page, "fail\n");
else if (ret == 0)
len = sprintf(page, "off\n");
else
len = sprintf(page, "on\n");
*eof = 1;
return len;
}
int
get_wd_exp_mode_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0;
ret = get_wd_exp_mode_fn(pbp_device_block);
if (ret == 1)
len = sprintf(page, "tap\n");
else if (ret == 0)
len = sprintf(page, "bypass\n");
else if (ret == 2)
len = sprintf(page, "disc\n");
else
len = sprintf(page, "fail\n");
*eof = 1;
return len;
}
int
set_wd_exp_mode_pfs(struct file *file, const char *buffer,
unsigned long count, void *data)
{
char kbuf[256];
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int bypass_param = 0, length = 0;
if (count > (sizeof(kbuf) - 1))
return -1;
if (copy_from_user(&kbuf, buffer, count)) {
return -1;
}
kbuf[count] = '\0';
length = strlen(kbuf);
if (kbuf[length - 1] == '\n')
kbuf[--length] = '\0';
if (strcmp(kbuf, "tap") == 0)
bypass_param = 1;
else if (strcmp(kbuf, "bypass") == 0)
bypass_param = 0;
else if (strcmp(kbuf, "disc") == 0)
bypass_param = 2;
set_wd_exp_mode_fn(pbp_device_block, bypass_param);
return count;
}
int
get_wd_autoreset_pfs(char *page, char **start, off_t off, int count,
int *eof, void *data)
{
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int len = 0, ret = 0;
ret = get_wd_autoreset_fn(pbp_device_block);
if (ret >= 0)
len = sprintf(page, "%d\n", ret);
else
len = sprintf(page, "fail\n");
*eof = 1;
return len;
}
int
set_wd_autoreset_pfs(struct file *file, const char *buffer,
unsigned long count, void *data)
{
char kbuf[256];
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
u32 timeout = 0;
char *timeout_ptr = kbuf;
if (copy_from_user(&kbuf, buffer, count)) {
return -1;
}
timeout_ptr = kbuf;
timeout = atoi(&timeout_ptr);
set_wd_autoreset_fn(pbp_device_block, timeout);
return count;
}
int
set_tpl_pfs(struct file *file, const char *buffer,
unsigned long count, void *data)
{
char kbuf[256];
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int tpl_param = 0, length = 0;
if (count > (sizeof(kbuf) - 1))
return -1;
if (copy_from_user(&kbuf, buffer, count)) {
return -1;
}
kbuf[count] = '\0';
length = strlen(kbuf);
if (kbuf[length - 1] == '\n')
kbuf[--length] = '\0';
if (strcmp(kbuf, "on") == 0)
tpl_param = 1;
else if (strcmp(kbuf, "off") == 0)
tpl_param = 0;
set_tpl_fn(pbp_device_block, tpl_param);
return count;
}
int
set_wait_at_pwup_pfs(struct file *file, const char *buffer,
unsigned long count, void *data)
{
char kbuf[256];
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int tpl_param = 0, length = 0;
if (count > (sizeof(kbuf) - 1))
return -1;
if (copy_from_user(&kbuf, buffer, count)) {
return -1;
}
kbuf[count] = '\0';
length = strlen(kbuf);
if (kbuf[length - 1] == '\n')
kbuf[--length] = '\0';
if (strcmp(kbuf, "on") == 0)
tpl_param = 1;
else if (strcmp(kbuf, "off") == 0)
tpl_param = 0;
set_bp_wait_at_pwup_fn(pbp_device_block, tpl_param);
return count;
}
int
set_hw_reset_pfs(struct file *file, const char *buffer,
unsigned long count, void *data)
{
char kbuf[256];
bpctl_dev_t *pbp_device_block = (bpctl_dev_t *) data;
int tpl_param = 0, length = 0;
if (count > (sizeof(kbuf) - 1))
return -1;
if (copy_from_user(&kbuf, buffer, count)) {
return -1;
}
kbuf[count] = '\0';
length = strlen(kbuf);
if (kbuf[length - 1] == '\n')
kbuf[--length] = '\0';
if (strcmp(kbuf, "on") == 0)
tpl_param = 1;
else if (strcmp(kbuf, "off") == 0)
tpl_param = 0;
set_bp_hw_reset_fn(pbp_device_block, tpl_param);
return count;
}
int bypass_proc_create_dev_sd(bpctl_dev_t * pbp_device_block)
{
struct bypass_pfs_sd *current_pfs = &(pbp_device_block->bypass_pfs_set);
static struct proc_dir_entry *procfs_dir = NULL;
int ret = 0;
sprintf(current_pfs->dir_name, "bypass_%s", dev->name);
if (!bp_procfs_dir)
return -1;
procfs_dir = proc_getdir(current_pfs->dir_name, bp_procfs_dir);
if (procfs_dir == 0) {
printk(KERN_DEBUG "Could not create procfs directory %s\n",
current_pfs->dir_name);
return -1;
}
current_pfs->bypass_entry = procfs_dir;
if (bypass_proc_create_entry(&(current_pfs->bypass_info), BYPASS_INFO_ENTRY_SD, NULL,
get_bypass_info_pfs,
procfs_dir, pbp_device_block))
ret = -1;
if (pbp_device_block->bp_caps & SW_CTL_CAP) {
if (bypass_proc_create_entry_sd(&(current_pfs->bypass_slave), BYPASS_SLAVE_ENTRY_SD, NULL,
get_bypass_slave_pfs,
procfs_dir, pbp_device_block))
ret = -1;
if (bypass_proc_create_entry_sd(&(current_pfs->bypass_caps), BYPASS_CAPS_ENTRY_SD, NULL,
get_bypass_caps_pfs,
procfs_dir, pbp_device_block))
ret = -1;
if (bypass_proc_create_entry_sd(&(current_pfs->wd_set_caps), WD_SET_CAPS_ENTRY_SD, NULL,
get_wd_set_caps_pfs,
procfs_dir, pbp_device_block))
ret = -1;
if (bypass_proc_create_entry_sd(&(current_pfs->bypass_wd), BYPASS_WD_ENTRY_SD, set_bypass_wd_pfs,
get_bypass_wd_pfs,
procfs_dir, pbp_device_block))
ret = -1;
if (bypass_proc_create_entry_sd(&(current_pfs->wd_expire_time), WD_EXPIRE_TIME_ENTRY_SD, NULL,
get_wd_expire_time_pfs,
procfs_dir, pbp_device_block))
ret = -1;
if (bypass_proc_create_entry_sd(&(current_pfs->reset_bypass_wd), RESET_BYPASS_WD_ENTRY_SD, NULL,
reset_bypass_wd_pfs,
procfs_dir, pbp_device_block))
ret = -1;
if (bypass_proc_create_entry_sd(&(current_pfs->std_nic), STD_NIC_ENTRY_SD, set_std_nic_pfs,
get_std_nic_pfs,
procfs_dir, pbp_device_block))
ret = -1;
if (pbp_device_block->bp_caps & BP_CAP) {
if (bypass_proc_create_entry_sd(&(current_pfs->bypass), BYPASS_ENTRY_SD, set_bypass_pfs,
get_bypass_pfs,
procfs_dir,
pbp_device_block))
ret = -1;
if (bypass_proc_create_entry_sd(&(current_pfs->dis_bypass), DIS_BYPASS_ENTRY_SD, set_dis_bypass_pfs,
get_dis_bypass_pfs,
procfs_dir,
pbp_device_block))
ret = -1;
if (bypass_proc_create_entry_sd(&(current_pfs->bypass_pwup), BYPASS_PWUP_ENTRY_SD, set_bypass_pwup_pfs,
get_bypass_pwup_pfs,
procfs_dir,
pbp_device_block))
ret = -1;
if (bypass_proc_create_entry_sd(&(current_pfs->bypass_pwoff), BYPASS_PWOFF_ENTRY_SD, set_bypass_pwoff_pfs,
get_bypass_pwoff_pfs,
procfs_dir,
pbp_device_block))
ret = -1;
if (bypass_proc_create_entry_sd(&(current_pfs->bypass_change), BYPASS_CHANGE_ENTRY_SD, NULL,
get_bypass_change_pfs,
procfs_dir,
pbp_device_block))
ret = -1;
}
if (pbp_device_block->bp_caps & TAP_CAP) {
if (bypass_proc_create_entry_sd(&(current_pfs->tap), TAP_ENTRY_SD, set_tap_pfs,
get_tap_pfs,
procfs_dir,
pbp_device_block))
ret = -1;
if (bypass_proc_create_entry_sd(&(current_pfs->dis_tap), DIS_TAP_ENTRY_SD, set_dis_tap_pfs,
get_dis_tap_pfs,
procfs_dir,
pbp_device_block))
ret = -1;
if (bypass_proc_create_entry_sd(&(current_pfs->tap_pwup), TAP_PWUP_ENTRY_SD, set_tap_pwup_pfs,
get_tap_pwup_pfs,
procfs_dir,
pbp_device_block))
ret = -1;
if (bypass_proc_create_entry_sd(&(current_pfs->tap_change), TAP_CHANGE_ENTRY_SD, NULL,
get_tap_change_pfs,
procfs_dir,
pbp_device_block))
ret = -1;
}
if (pbp_device_block->bp_caps & DISC_CAP) {
if (bypass_proc_create_entry_sd(&(current_pfs->tap), DISC_ENTRY_SD, set_disc_pfs,
get_disc_pfs,
procfs_dir,
pbp_device_block))
ret = -1;
#if 1
if (bypass_proc_create_entry_sd(&(current_pfs->dis_tap), DIS_DISC_ENTRY_SD, set_dis_disc_pfs,
get_dis_disc_pfs,
procfs_dir,
pbp_device_block))
ret = -1;
#endif
if (bypass_proc_create_entry_sd(&(current_pfs->tap_pwup), DISC_PWUP_ENTRY_SD, set_disc_pwup_pfs,
get_disc_pwup_pfs,
procfs_dir,
pbp_device_block))
ret = -1;
if (bypass_proc_create_entry_sd(&(current_pfs->tap_change), DISC_CHANGE_ENTRY_SD, NULL,
get_disc_change_pfs,
procfs_dir,
pbp_device_block))
ret = -1;
}
if (bypass_proc_create_entry_sd(&(current_pfs->wd_exp_mode), WD_EXP_MODE_ENTRY_SD, set_wd_exp_mode_pfs,
get_wd_exp_mode_pfs,
procfs_dir, pbp_device_block))
ret = -1;
if (bypass_proc_create_entry_sd(&(current_pfs->wd_autoreset), WD_AUTORESET_ENTRY_SD, set_wd_autoreset_pfs,
get_wd_autoreset_pfs,
procfs_dir, pbp_device_block))
ret = -1;
if (bypass_proc_create_entry_sd(&(current_pfs->tpl), TPL_ENTRY_SD, set_tpl_pfs,
get_tpl_pfs,
procfs_dir, pbp_device_block))
ret = -1;
#ifdef PMC_FIX_FLAG
if (bypass_proc_create_entry_sd(&(current_pfs->tpl), WAIT_AT_PWUP_ENTRY_SD, set_wait_at_pwup_pfs,
get_wait_at_pwup_pfs,
procfs_dir, pbp_device_block))
ret = -1;
if (bypass_proc_create_entry_sd(&(current_pfs->tpl), HW_RESET_ENTRY_SD, set_hw_reset_pfs,
get_hw_reset_pfs,
procfs_dir, pbp_device_block))
ret = -1;
#endif
}
if (ret < 0)
printk(KERN_DEBUG "Create proc entry failed\n");
return ret;
}
int bypass_proc_remove_dev_sd(bpctl_dev_t * pbp_device_block)
{
struct bypass_pfs_sd *current_pfs = &pbp_device_block->bypass_pfs_set;
struct proc_dir_entry *pde = current_pfs->bypass_entry, *pde_curr =
NULL;
char name[256];
for (pde = pde->subdir; pde;) {
strcpy(name, pde->name);
pde_curr = pde;
pde = pde->next;
remove_proc_entry(name, current_pfs->bypass_entry);
}
if (!pde)
remove_proc_entry(current_pfs->dir_name, bp_procfs_dir);
return 0;
}
