static void remove_files(struct nd_struct *nd)
{
char buf[3];
ID_TO_CHAR(nd->nd_ID, buf);
dgrp_remove_node_class_sysfs_files(nd);
if (nd->nd_net_de)
remove_proc_entry(buf, net_entry_pointer);
if (nd->nd_mon_de)
remove_proc_entry(buf, mon_entry_pointer);
if (nd->nd_dpa_de)
remove_proc_entry(buf, dpa_entry_pointer);
if (nd->nd_ports_de)
remove_proc_entry(buf, ports_entry_pointer);
}
void dgrp_unregister_proc(void)
{
net_entry_pointer = NULL;
mon_entry_pointer = NULL;
dpa_entry_pointer = NULL;
ports_entry_pointer = NULL;
if (dgrp_proc_dir_entry) {
struct nd_struct *nd;
list_for_each_entry(nd, &nd_struct_list, list)
remove_files(nd);
remove_proc_entry("dgrp/config", NULL);
remove_proc_entry("dgrp/info", NULL);
remove_proc_entry("dgrp/nodeinfo", NULL);
remove_proc_entry("dgrp/net", NULL);
remove_proc_entry("dgrp/mon", NULL);
remove_proc_entry("dgrp/dpa", NULL);
remove_proc_entry("dgrp/ports", NULL);
remove_proc_entry("dgrp", NULL);
dgrp_proc_dir_entry = NULL;
}
}
void dgrp_register_proc(void)
{
dgrp_proc_dir_entry = proc_mkdir("dgrp", NULL);
if (!dgrp_proc_dir_entry)
return;
proc_create("dgrp/config", 0644, NULL, &config_proc_file_ops);
proc_create("dgrp/info", 0644, NULL, &info_proc_file_ops);
proc_create("dgrp/nodeinfo", 0644, NULL, &nodeinfo_proc_file_ops);
net_entry_pointer = proc_mkdir_mode("dgrp/net", 0500, NULL);
mon_entry_pointer = proc_mkdir_mode("dgrp/mon", 0500, NULL);
dpa_entry_pointer = proc_mkdir_mode("dgrp/dpa", 0500, NULL);
ports_entry_pointer = proc_mkdir_mode("dgrp/ports", 0500, NULL);
}
static void *dgrp_config_proc_start(struct seq_file *m, loff_t *pos)
{
return seq_list_start_head(&nd_struct_list, *pos);
}
static void *dgrp_config_proc_next(struct seq_file *p, void *v, loff_t *pos)
{
return seq_list_next(v, &nd_struct_list, pos);
}
static void dgrp_config_proc_stop(struct seq_file *m, void *v)
{
}
static int dgrp_config_proc_show(struct seq_file *m, void *v)
{
struct nd_struct *nd;
char tmp_id[4];
if (v == &nd_struct_list) {
seq_puts(m, "#-----------------------------------------------------------------------------\n");
seq_puts(m, "# Avail\n");
seq_puts(m, "# ID Major State Ports\n");
return 0;
}
nd = list_entry(v, struct nd_struct, list);
ID_TO_CHAR(nd->nd_ID, tmp_id);
seq_printf(m, " %-2.2s %-5ld %-10.10s %-5d\n",
tmp_id,
nd->nd_major,
ND_STATE_STR(nd->nd_state),
nd->nd_chan_count);
return 0;
}
static int dgrp_config_proc_open(struct inode *inode, struct file *file)
{
return seq_open(file, &proc_config_ops);
}
static ssize_t dgrp_config_proc_write(struct file *file,
const char __user *buffer,
size_t count, loff_t *pos)
{
ssize_t retval;
char *inbuf, *sp;
char *line, *ldelim;
if (count > 32768)
return -EINVAL;
inbuf = sp = vzalloc(count + 1);
if (!inbuf)
return -ENOMEM;
if (copy_from_user(inbuf, buffer, count)) {
retval = -EFAULT;
goto done;
}
inbuf[count] = 0;
ldelim = "\n";
line = strpbrk(sp, ldelim);
while (line) {
*line = 0;
retval = parse_write_config(sp);
if (retval)
goto done;
sp = line + 1;
line = strpbrk(sp, ldelim);
}
retval = count;
done:
vfree(inbuf);
return retval;
}
static inline char *skip_past_ws(const char *str)
{
while ((*str) && !isspace(*str))
++str;
return skip_spaces(str);
}
static int parse_id(char **c, char *cID)
{
int tmp = **c;
if (isalnum(tmp) || (tmp == '_'))
cID[0] = tmp;
else
return -EINVAL;
(*c)++; tmp = **c;
if (isalnum(tmp) || (tmp == '_')) {
cID[1] = tmp;
(*c)++;
} else
cID[1] = 0;
return 0;
}
static int parse_add_config(char *buf)
{
char *c = buf;
int retval;
char cID[2];
long ID;
c = skip_past_ws(c);
retval = parse_id(&c, cID);
if (retval < 0)
return retval;
ID = CHAR_TO_ID(cID);
c = skip_past_ws(c);
return dgrp_add_id(ID);
}
static int parse_del_config(char *buf)
{
char *c = buf;
int retval;
struct nd_struct *nd;
char cID[2];
long ID;
long major;
c = skip_past_ws(c);
retval = parse_id(&c, cID);
if (retval < 0)
return retval;
ID = CHAR_TO_ID(cID);
c = skip_past_ws(c);
retval = kstrtol(c, 10, &major);
if (retval)
return retval;
nd = nd_struct_get(major);
if (!nd)
return -EINVAL;
if ((nd->nd_major != major) || (nd->nd_ID != ID))
return -EINVAL;
return dgrp_remove_nd(nd);
}
static int parse_chg_config(char *buf)
{
return -EINVAL;
}
static int parse_write_config(char *buf)
{
int retval;
switch (buf[0]) {
case '+':
retval = parse_add_config(buf);
break;
case '-':
retval = parse_del_config(buf);
break;
case '*':
retval = parse_chg_config(buf);
break;
default:
retval = -EINVAL;
}
return retval;
}
static int dgrp_info_proc_show(struct seq_file *m, void *v)
{
seq_printf(m, "version: %s\n", DIGI_VERSION);
seq_puts(m, "register_with_sysfs: 1\n");
seq_printf(m, "pollrate: 0x%08x\t(%d)\n",
dgrp_poll_tick, dgrp_poll_tick);
return 0;
}
static int dgrp_info_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, dgrp_info_proc_show, NULL);
}
static void *dgrp_nodeinfo_start(struct seq_file *m, loff_t *pos)
{
return seq_list_start_head(&nd_struct_list, *pos);
}
static void *dgrp_nodeinfo_next(struct seq_file *p, void *v, loff_t *pos)
{
return seq_list_next(v, &nd_struct_list, pos);
}
static void dgrp_nodeinfo_stop(struct seq_file *m, void *v)
{
}
static int dgrp_nodeinfo_show(struct seq_file *m, void *v)
{
struct nd_struct *nd;
char hwver[8];
char swver[8];
char tmp_id[4];
if (v == &nd_struct_list) {
seq_puts(m, "#-----------------------------------------------------------------------------\n");
seq_puts(m, "# HW HW SW\n");
seq_puts(m, "# ID State Version ID Version Description\n");
return 0;
}
nd = list_entry(v, struct nd_struct, list);
ID_TO_CHAR(nd->nd_ID, tmp_id);
if (nd->nd_state == NS_READY) {
sprintf(hwver, "%d.%d", (nd->nd_hw_ver >> 8) & 0xff,
nd->nd_hw_ver & 0xff);
sprintf(swver, "%d.%d", (nd->nd_sw_ver >> 8) & 0xff,
nd->nd_sw_ver & 0xff);
seq_printf(m, " %-2.2s %-10.10s %-7.7s %-3d %-7.7s %-35.35s\n",
tmp_id,
ND_STATE_STR(nd->nd_state),
hwver,
nd->nd_hw_id,
swver,
nd->nd_ps_desc);
} else {
seq_printf(m, " %-2.2s %-10.10s\n",
tmp_id,
ND_STATE_STR(nd->nd_state));
}
return 0;
}
static int dgrp_nodeinfo_proc_open(struct inode *inode, struct file *file)
{
return seq_open(file, &nodeinfo_ops);
}
static int dgrp_add_id(long id)
{
struct nd_struct *nd;
int ret;
int i;
nd = kzalloc(sizeof(struct nd_struct), GFP_KERNEL);
if (!nd)
return -ENOMEM;
nd->nd_major = 0;
nd->nd_ID = id;
spin_lock_init(&nd->nd_lock);
init_waitqueue_head(&nd->nd_tx_waitq);
init_waitqueue_head(&nd->nd_mon_wqueue);
init_waitqueue_head(&nd->nd_dpa_wqueue);
sema_init(&nd->nd_mon_semaphore, 1);
sema_init(&nd->nd_net_semaphore, 1);
spin_lock_init(&nd->nd_dpa_lock);
nd->nd_state = NS_CLOSED;
for (i = 0; i < SEQ_MAX; i++)
init_waitqueue_head(&nd->nd_seq_wque[i]);
ret = dgrp_tty_init(nd);
if (ret)
goto error_out;
nd->nd_major = nd->nd_serial_ttdriver->major;
ret = nd_struct_add(nd);
if (ret)
goto error_out;
dgrp_create_node_class_sysfs_files(nd);
nd->nd_net_de = add_proc_file(nd, net_entry_pointer, &dgrp_net_ops);
nd->nd_mon_de = add_proc_file(nd, mon_entry_pointer, &dgrp_mon_ops);
nd->nd_dpa_de = add_proc_file(nd, dpa_entry_pointer, &dgrp_dpa_ops);
nd->nd_ports_de = add_proc_file(nd, ports_entry_pointer,
&dgrp_ports_ops);
return 0;
error_out:
kfree(nd);
return ret;
}
static int dgrp_remove_nd(struct nd_struct *nd)
{
int ret;
if (nd->nd_tty_ref_cnt)
return -EBUSY;
remove_files(nd);
dgrp_tty_uninit(nd);
ret = nd_struct_del(nd);
if (ret)
return ret;
kfree(nd);
return 0;
}
static struct proc_dir_entry *add_proc_file(struct nd_struct *node,
struct proc_dir_entry *root,
const struct file_operations *fops)
{
char buf[3];
ID_TO_CHAR(node->nd_ID, buf);
return proc_create_data(buf, 0600, root, fops, node);
}
