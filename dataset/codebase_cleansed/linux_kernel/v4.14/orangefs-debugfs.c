int orangefs_debugfs_init(int debug_mask)
{
int rc = -ENOMEM;
orangefs_gossip_debug_mask = (unsigned long long)debug_mask;
debug_mask_to_string(&orangefs_gossip_debug_mask, 0);
debug_string_to_mask(kernel_debug_string, &orangefs_gossip_debug_mask,
0);
if (orangefs_gossip_debug_mask != 0)
kernel_mask_set_mod_init = true;
pr_info("%s: called with debug mask: :%s: :%llx:\n",
__func__,
kernel_debug_string,
(unsigned long long)orangefs_gossip_debug_mask);
debug_dir = debugfs_create_dir("orangefs", NULL);
if (!debug_dir) {
pr_info("%s: debugfs_create_dir failed.\n", __func__);
goto out;
}
help_file_dentry = debugfs_create_file(ORANGEFS_KMOD_DEBUG_HELP_FILE,
0444,
debug_dir,
debug_help_string,
&debug_help_fops);
if (!help_file_dentry) {
pr_info("%s: debugfs_create_file failed.\n", __func__);
goto out;
}
orangefs_debug_disabled = 0;
rc = orangefs_kernel_debug_init();
out:
return rc;
}
static int orangefs_kernel_debug_init(void)
{
int rc = -ENOMEM;
struct dentry *ret;
char *k_buffer = NULL;
gossip_debug(GOSSIP_DEBUGFS_DEBUG, "%s: start\n", __func__);
k_buffer = kzalloc(ORANGEFS_MAX_DEBUG_STRING_LEN, GFP_KERNEL);
if (!k_buffer)
goto out;
if (strlen(kernel_debug_string) + 1 < ORANGEFS_MAX_DEBUG_STRING_LEN) {
strcpy(k_buffer, kernel_debug_string);
strcat(k_buffer, "\n");
} else {
strcpy(k_buffer, "none\n");
pr_info("%s: overflow 1!\n", __func__);
}
ret = debugfs_create_file(ORANGEFS_KMOD_DEBUG_FILE,
0444,
debug_dir,
k_buffer,
&kernel_debug_fops);
if (!ret) {
pr_info("%s: failed to create %s.\n",
__func__,
ORANGEFS_KMOD_DEBUG_FILE);
goto out;
}
rc = 0;
out:
gossip_debug(GOSSIP_DEBUGFS_DEBUG, "%s: rc:%d:\n", __func__, rc);
return rc;
}
void orangefs_debugfs_cleanup(void)
{
debugfs_remove_recursive(debug_dir);
}
static int orangefs_debug_help_open(struct inode *inode, struct file *file)
{
int rc = -ENODEV;
int ret;
gossip_debug(GOSSIP_DEBUGFS_DEBUG,
"orangefs_debug_help_open: start\n");
if (orangefs_debug_disabled)
goto out;
ret = seq_open(file, &help_debug_ops);
if (ret)
goto out;
((struct seq_file *)(file->private_data))->private = inode->i_private;
rc = 0;
out:
gossip_debug(GOSSIP_DEBUGFS_DEBUG,
"orangefs_debug_help_open: rc:%d:\n",
rc);
return rc;
}
static void *help_start(struct seq_file *m, loff_t *pos)
{
void *payload = NULL;
gossip_debug(GOSSIP_DEBUGFS_DEBUG, "help_start: start\n");
mutex_lock(&orangefs_help_file_lock);
if (*pos == 0)
payload = m->private;
return payload;
}
static void *help_next(struct seq_file *m, void *v, loff_t *pos)
{
gossip_debug(GOSSIP_DEBUGFS_DEBUG, "help_next: start\n");
return NULL;
}
static void help_stop(struct seq_file *m, void *p)
{
gossip_debug(GOSSIP_DEBUGFS_DEBUG, "help_stop: start\n");
mutex_unlock(&orangefs_help_file_lock);
}
static int help_show(struct seq_file *m, void *v)
{
gossip_debug(GOSSIP_DEBUGFS_DEBUG, "help_show: start\n");
seq_puts(m, v);
return 0;
}
int orangefs_client_debug_init(void)
{
int rc = -ENOMEM;
char *c_buffer = NULL;
gossip_debug(GOSSIP_DEBUGFS_DEBUG, "%s: start\n", __func__);
c_buffer = kzalloc(ORANGEFS_MAX_DEBUG_STRING_LEN, GFP_KERNEL);
if (!c_buffer)
goto out;
if (strlen(client_debug_string) + 1 < ORANGEFS_MAX_DEBUG_STRING_LEN) {
strcpy(c_buffer, client_debug_string);
strcat(c_buffer, "\n");
} else {
strcpy(c_buffer, "none\n");
pr_info("%s: overflow! 2\n", __func__);
}
client_debug_dentry = debugfs_create_file(ORANGEFS_CLIENT_DEBUG_FILE,
0444,
debug_dir,
c_buffer,
&kernel_debug_fops);
if (!client_debug_dentry) {
pr_info("%s: failed to create updated %s.\n",
__func__,
ORANGEFS_CLIENT_DEBUG_FILE);
goto out;
}
rc = 0;
out:
gossip_debug(GOSSIP_DEBUGFS_DEBUG, "%s: rc:%d:\n", __func__, rc);
return rc;
}
static int orangefs_debug_open(struct inode *inode, struct file *file)
{
int rc = -ENODEV;
gossip_debug(GOSSIP_DEBUGFS_DEBUG,
"%s: orangefs_debug_disabled: %d\n",
__func__,
orangefs_debug_disabled);
if (orangefs_debug_disabled)
goto out;
rc = 0;
mutex_lock(&orangefs_debug_lock);
file->private_data = inode->i_private;
mutex_unlock(&orangefs_debug_lock);
out:
gossip_debug(GOSSIP_DEBUGFS_DEBUG,
"orangefs_debug_open: rc: %d\n",
rc);
return rc;
}
static ssize_t orangefs_debug_read(struct file *file,
char __user *ubuf,
size_t count,
loff_t *ppos)
{
char *buf;
int sprintf_ret;
ssize_t read_ret = -ENOMEM;
gossip_debug(GOSSIP_DEBUGFS_DEBUG, "orangefs_debug_read: start\n");
buf = kmalloc(ORANGEFS_MAX_DEBUG_STRING_LEN, GFP_KERNEL);
if (!buf)
goto out;
mutex_lock(&orangefs_debug_lock);
sprintf_ret = sprintf(buf, "%s", (char *)file->private_data);
mutex_unlock(&orangefs_debug_lock);
read_ret = simple_read_from_buffer(ubuf, count, ppos, buf, sprintf_ret);
kfree(buf);
out:
gossip_debug(GOSSIP_DEBUGFS_DEBUG,
"orangefs_debug_read: ret: %zu\n",
read_ret);
return read_ret;
}
static ssize_t orangefs_debug_write(struct file *file,
const char __user *ubuf,
size_t count,
loff_t *ppos)
{
char *buf;
int rc = -EFAULT;
size_t silly = 0;
char *debug_string;
struct orangefs_kernel_op_s *new_op = NULL;
struct client_debug_mask c_mask = { NULL, 0, 0 };
char *s;
gossip_debug(GOSSIP_DEBUGFS_DEBUG,
"orangefs_debug_write: %pD\n",
file);
if (count == 0)
return 0;
if (count > ORANGEFS_MAX_DEBUG_STRING_LEN + 1) {
silly = count;
count = ORANGEFS_MAX_DEBUG_STRING_LEN + 1;
}
buf = kzalloc(ORANGEFS_MAX_DEBUG_STRING_LEN, GFP_KERNEL);
if (!buf)
goto out;
if (copy_from_user(buf, ubuf, count - 1)) {
gossip_debug(GOSSIP_DEBUGFS_DEBUG,
"%s: copy_from_user failed!\n",
__func__);
goto out;
}
if (!strcmp(file->f_path.dentry->d_name.name,
ORANGEFS_KMOD_DEBUG_FILE)) {
debug_string_to_mask(buf, &orangefs_gossip_debug_mask, 0);
debug_mask_to_string(&orangefs_gossip_debug_mask, 0);
debug_string = kernel_debug_string;
gossip_debug(GOSSIP_DEBUGFS_DEBUG,
"New kernel debug string is %s\n",
kernel_debug_string);
} else {
if (is_daemon_in_service()) {
pr_info("%s: Client not running :%d:\n",
__func__,
is_daemon_in_service());
goto out;
}
debug_string_to_mask(buf, &c_mask, 1);
debug_mask_to_string(&c_mask, 1);
debug_string = client_debug_string;
new_op = op_alloc(ORANGEFS_VFS_OP_PARAM);
if (!new_op) {
pr_info("%s: op_alloc failed!\n", __func__);
goto out;
}
new_op->upcall.req.param.op =
ORANGEFS_PARAM_REQUEST_OP_TWO_MASK_VALUES;
new_op->upcall.req.param.type = ORANGEFS_PARAM_REQUEST_SET;
memset(new_op->upcall.req.param.s_value,
0,
ORANGEFS_MAX_DEBUG_STRING_LEN);
sprintf(new_op->upcall.req.param.s_value,
"%llx %llx\n",
c_mask.mask1,
c_mask.mask2);
rc = service_operation(new_op,
"orangefs_param",
ORANGEFS_OP_INTERRUPTIBLE);
if (rc)
gossip_debug(GOSSIP_DEBUGFS_DEBUG,
"%s: service_operation failed! rc:%d:\n",
__func__,
rc);
op_release(new_op);
}
mutex_lock(&orangefs_debug_lock);
s = file_inode(file)->i_private;
memset(s, 0, ORANGEFS_MAX_DEBUG_STRING_LEN);
sprintf(s, "%s\n", debug_string);
mutex_unlock(&orangefs_debug_lock);
*ppos += count;
if (silly)
rc = silly;
else
rc = count;
out:
gossip_debug(GOSSIP_DEBUGFS_DEBUG,
"orangefs_debug_write: rc: %d\n",
rc);
kfree(buf);
return rc;
}
static int orangefs_prepare_cdm_array(char *debug_array_string)
{
int i;
int rc = -EINVAL;
char *cds_head = NULL;
char *cds_delimiter = NULL;
int keyword_len = 0;
gossip_debug(GOSSIP_UTILS_DEBUG, "%s: start\n", __func__);
for (i = 0; i < strlen(debug_array_string); i++)
if (debug_array_string[i] == '\n')
cdm_element_count++;
if (!cdm_element_count) {
pr_info("No elements in client debug array string!\n");
goto out;
}
cdm_array = kcalloc(cdm_element_count, sizeof(*cdm_array), GFP_KERNEL);
if (!cdm_array) {
rc = -ENOMEM;
goto out;
}
cds_head = debug_array_string;
for (i = 0; i < cdm_element_count; i++) {
cds_delimiter = strchr(cds_head, '\n');
*cds_delimiter = '\0';
keyword_len = strcspn(cds_head, " ");
cdm_array[i].keyword = kzalloc(keyword_len + 1, GFP_KERNEL);
if (!cdm_array[i].keyword) {
rc = -ENOMEM;
goto out;
}
sscanf(cds_head,
"%s %llx %llx",
cdm_array[i].keyword,
(unsigned long long *)&(cdm_array[i].mask1),
(unsigned long long *)&(cdm_array[i].mask2));
if (!strcmp(cdm_array[i].keyword, ORANGEFS_VERBOSE))
client_verbose_index = i;
if (!strcmp(cdm_array[i].keyword, ORANGEFS_ALL))
client_all_index = i;
cds_head = cds_delimiter + 1;
}
rc = cdm_element_count;
gossip_debug(GOSSIP_UTILS_DEBUG, "%s: rc:%d:\n", __func__, rc);
out:
return rc;
}
int orangefs_prepare_debugfs_help_string(int at_boot)
{
char *client_title = "Client Debug Keywords:\n";
char *kernel_title = "Kernel Debug Keywords:\n";
size_t string_size = DEBUG_HELP_STRING_SIZE;
size_t result_size;
size_t i;
char *new;
int rc = -EINVAL;
gossip_debug(GOSSIP_UTILS_DEBUG, "%s: start\n", __func__);
if (at_boot)
client_title = HELP_STRING_UNINITIALIZED;
new = kzalloc(DEBUG_HELP_STRING_SIZE, GFP_KERNEL);
if (!new) {
rc = -ENOMEM;
goto out;
}
strlcat(new, client_title, string_size);
if (!at_boot) {
cdm_element_count =
orangefs_prepare_cdm_array(client_debug_array_string);
if (cdm_element_count <= 0) {
kfree(new);
goto out;
}
for (i = 0; i < cdm_element_count; i++) {
strlcat(new, "\t", string_size);
strlcat(new, cdm_array[i].keyword, string_size);
strlcat(new, "\n", string_size);
}
}
strlcat(new, "\n", string_size);
strlcat(new, kernel_title, string_size);
for (i = 0; i < num_kmod_keyword_mask_map; i++) {
strlcat(new, "\t", string_size);
strlcat(new, s_kmod_keyword_mask_map[i].keyword, string_size);
result_size = strlcat(new, "\n", string_size);
}
if (result_size >= string_size) {
kfree(new);
goto out;
}
if (at_boot) {
debug_help_string = new;
} else {
mutex_lock(&orangefs_help_file_lock);
memset(debug_help_string, 0, DEBUG_HELP_STRING_SIZE);
strlcat(debug_help_string, new, string_size);
mutex_unlock(&orangefs_help_file_lock);
}
rc = 0;
out: return rc;
}
static void debug_mask_to_string(void *mask, int type)
{
int i;
int len = 0;
char *debug_string;
int element_count = 0;
gossip_debug(GOSSIP_UTILS_DEBUG, "%s: start\n", __func__);
if (type) {
debug_string = client_debug_string;
element_count = cdm_element_count;
} else {
debug_string = kernel_debug_string;
element_count = num_kmod_keyword_mask_map;
}
memset(debug_string, 0, ORANGEFS_MAX_DEBUG_STRING_LEN);
if (check_amalgam_keyword(mask, type))
goto out;
for (i = 0; i < element_count; i++)
if (type)
do_c_string(mask, i);
else
do_k_string(mask, i);
len = strlen(debug_string);
if ((len) && (type))
client_debug_string[len - 1] = '\0';
else if (len)
kernel_debug_string[len - 1] = '\0';
else if (type)
strcpy(client_debug_string, "none");
else
strcpy(kernel_debug_string, "none");
out:
gossip_debug(GOSSIP_UTILS_DEBUG, "%s: string:%s:\n", __func__, debug_string);
return;
}
static void do_k_string(void *k_mask, int index)
{
__u64 *mask = (__u64 *) k_mask;
if (keyword_is_amalgam((char *) s_kmod_keyword_mask_map[index].keyword))
goto out;
if (*mask & s_kmod_keyword_mask_map[index].mask_val) {
if ((strlen(kernel_debug_string) +
strlen(s_kmod_keyword_mask_map[index].keyword))
< ORANGEFS_MAX_DEBUG_STRING_LEN - 1) {
strcat(kernel_debug_string,
s_kmod_keyword_mask_map[index].keyword);
strcat(kernel_debug_string, ",");
} else {
gossip_err("%s: overflow!\n", __func__);
strcpy(kernel_debug_string, ORANGEFS_ALL);
goto out;
}
}
out:
return;
}
static void do_c_string(void *c_mask, int index)
{
struct client_debug_mask *mask = (struct client_debug_mask *) c_mask;
if (keyword_is_amalgam(cdm_array[index].keyword))
goto out;
if ((mask->mask1 & cdm_array[index].mask1) ||
(mask->mask2 & cdm_array[index].mask2)) {
if ((strlen(client_debug_string) +
strlen(cdm_array[index].keyword) + 1)
< ORANGEFS_MAX_DEBUG_STRING_LEN - 2) {
strcat(client_debug_string,
cdm_array[index].keyword);
strcat(client_debug_string, ",");
} else {
gossip_err("%s: overflow!\n", __func__);
strcpy(client_debug_string, ORANGEFS_ALL);
goto out;
}
}
out:
return;
}
static int keyword_is_amalgam(char *keyword)
{
int rc = 0;
if ((!strcmp(keyword, ORANGEFS_ALL)) || (!strcmp(keyword, ORANGEFS_VERBOSE)))
rc = 1;
return rc;
}
static int check_amalgam_keyword(void *mask, int type)
{
__u64 *k_mask;
struct client_debug_mask *c_mask;
int k_all_index = num_kmod_keyword_mask_map - 1;
int rc = 0;
if (type) {
c_mask = (struct client_debug_mask *) mask;
if ((c_mask->mask1 == cdm_array[client_all_index].mask1) &&
(c_mask->mask2 == cdm_array[client_all_index].mask2)) {
strcpy(client_debug_string, ORANGEFS_ALL);
rc = 1;
goto out;
}
if ((c_mask->mask1 == cdm_array[client_verbose_index].mask1) &&
(c_mask->mask2 == cdm_array[client_verbose_index].mask2)) {
strcpy(client_debug_string, ORANGEFS_VERBOSE);
rc = 1;
goto out;
}
} else {
k_mask = (__u64 *) mask;
if (*k_mask >= s_kmod_keyword_mask_map[k_all_index].mask_val) {
strcpy(kernel_debug_string, ORANGEFS_ALL);
rc = 1;
goto out;
}
}
out:
return rc;
}
static void debug_string_to_mask(char *debug_string, void *mask, int type)
{
char *unchecked_keyword;
int i;
char *strsep_fodder = kstrdup(debug_string, GFP_KERNEL);
char *original_pointer;
int element_count = 0;
struct client_debug_mask *c_mask = NULL;
__u64 *k_mask = NULL;
gossip_debug(GOSSIP_UTILS_DEBUG, "%s: start\n", __func__);
if (type) {
c_mask = (struct client_debug_mask *)mask;
element_count = cdm_element_count;
} else {
k_mask = (__u64 *)mask;
*k_mask = 0;
element_count = num_kmod_keyword_mask_map;
}
original_pointer = strsep_fodder;
while ((unchecked_keyword = strsep(&strsep_fodder, ",")))
if (strlen(unchecked_keyword)) {
for (i = 0; i < element_count; i++)
if (type)
do_c_mask(i,
unchecked_keyword,
&c_mask);
else
do_k_mask(i,
unchecked_keyword,
&k_mask);
}
kfree(original_pointer);
}
static void do_c_mask(int i, char *unchecked_keyword,
struct client_debug_mask **sane_mask)
{
if (!strcmp(cdm_array[i].keyword, unchecked_keyword)) {
(**sane_mask).mask1 = (**sane_mask).mask1 | cdm_array[i].mask1;
(**sane_mask).mask2 = (**sane_mask).mask2 | cdm_array[i].mask2;
}
}
static void do_k_mask(int i, char *unchecked_keyword, __u64 **sane_mask)
{
if (!strcmp(s_kmod_keyword_mask_map[i].keyword, unchecked_keyword))
**sane_mask = (**sane_mask) |
s_kmod_keyword_mask_map[i].mask_val;
}
int orangefs_debugfs_new_client_mask(void __user *arg)
{
struct dev_mask2_info_s mask2_info = {0};
int ret;
ret = copy_from_user(&mask2_info,
(void __user *)arg,
sizeof(struct dev_mask2_info_s));
if (ret != 0)
return -EIO;
client_debug_mask.mask1 = mask2_info.mask1_value;
client_debug_mask.mask2 = mask2_info.mask2_value;
pr_info("%s: client debug mask has been been received "
":%llx: :%llx:\n",
__func__,
(unsigned long long)client_debug_mask.mask1,
(unsigned long long)client_debug_mask.mask2);
return ret;
}
int orangefs_debugfs_new_client_string(void __user *arg)
{
int ret;
ret = copy_from_user(&client_debug_array_string,
(void __user *)arg,
ORANGEFS_MAX_DEBUG_STRING_LEN);
if (ret != 0) {
pr_info("%s: CLIENT_STRING: copy_from_user failed\n",
__func__);
return -EFAULT;
}
client_debug_array_string[ORANGEFS_MAX_DEBUG_STRING_LEN - 1] =
'\0';
pr_info("%s: client debug array string has been received.\n",
__func__);
if (!help_string_initialized) {
ret = orangefs_prepare_debugfs_help_string(0);
if (ret) {
gossip_err("%s: no debug help string \n",
__func__);
return ret;
}
}
debug_mask_to_string(&client_debug_mask, 1);
debugfs_remove(client_debug_dentry);
orangefs_client_debug_init();
help_string_initialized++;
return 0;
}
int orangefs_debugfs_new_debug(void __user *arg)
{
struct dev_mask_info_s mask_info = {0};
int ret;
ret = copy_from_user(&mask_info,
(void __user *)arg,
sizeof(mask_info));
if (ret != 0)
return -EIO;
if (mask_info.mask_type == KERNEL_MASK) {
if ((mask_info.mask_value == 0)
&& (kernel_mask_set_mod_init)) {
return 0;
}
debug_mask_to_string(&mask_info.mask_value,
mask_info.mask_type);
orangefs_gossip_debug_mask = mask_info.mask_value;
pr_info("%s: kernel debug mask has been modified to "
":%s: :%llx:\n",
__func__,
kernel_debug_string,
(unsigned long long)orangefs_gossip_debug_mask);
} else if (mask_info.mask_type == CLIENT_MASK) {
debug_mask_to_string(&mask_info.mask_value,
mask_info.mask_type);
pr_info("%s: client debug mask has been modified to"
":%s: :%llx:\n",
__func__,
client_debug_string,
llu(mask_info.mask_value));
} else {
gossip_lerr("Invalid mask type....\n");
return -EINVAL;
}
return ret;
}
