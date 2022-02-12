inline struct proc_dir_entry *rtw_proc_create_dir(const char *name, struct proc_dir_entry *parent, void *data)
{
struct proc_dir_entry *entry;
entry = proc_mkdir_data(name, S_IRUGO|S_IXUGO, parent, data);
return entry;
}
inline struct proc_dir_entry *rtw_proc_create_entry(const char *name, struct proc_dir_entry *parent,
const struct file_operations *fops, void *data)
{
struct proc_dir_entry *entry;
entry = proc_create_data(name, S_IFREG|S_IRUGO, parent, fops, data);
return entry;
}
static int proc_get_dummy(struct seq_file *m, void *v)
{
return 0;
}
static int proc_get_drv_version(struct seq_file *m, void *v)
{
dump_drv_version(m);
return 0;
}
static int proc_get_log_level(struct seq_file *m, void *v)
{
dump_log_level(m);
return 0;
}
static ssize_t proc_set_log_level(struct file *file, const char __user *buffer, size_t count, loff_t *pos, void *data)
{
char tmp[32];
int log_level;
if (count < 1)
return -EINVAL;
if (buffer && !copy_from_user(tmp, buffer, sizeof(tmp))) {
sscanf(tmp, "%d ", &log_level);
if (log_level >= _drv_always_ && log_level <= _drv_debug_)
{
GlobalDebugLevel = log_level;
printk("%d\n", GlobalDebugLevel);
}
} else {
return -EFAULT;
}
return count;
}
static int rtw_drv_proc_open(struct inode *inode, struct file *file)
{
ssize_t index = (ssize_t)PDE_DATA(inode);
const struct rtw_proc_hdl *hdl = drv_proc_hdls+index;
return single_open(file, hdl->show, NULL);
}
static ssize_t rtw_drv_proc_write(struct file *file, const char __user *buffer, size_t count, loff_t *pos)
{
ssize_t index = (ssize_t)PDE_DATA(file_inode(file));
const struct rtw_proc_hdl *hdl = drv_proc_hdls+index;
ssize_t (*write)(struct file *, const char __user *, size_t, loff_t *, void *) = hdl->write;
if (write)
return write(file, buffer, count, pos, NULL);
return -EROFS;
}
int rtw_drv_proc_init(void)
{
int ret = _FAIL;
ssize_t i;
struct proc_dir_entry *entry = NULL;
if (rtw_proc != NULL) {
rtw_warn_on(1);
goto exit;
}
rtw_proc = rtw_proc_create_dir(RTW_PROC_NAME, get_proc_net, NULL);
if (rtw_proc == NULL) {
rtw_warn_on(1);
goto exit;
}
for (i = 0;i<drv_proc_hdls_num;i++) {
entry = rtw_proc_create_entry(drv_proc_hdls[i].name, rtw_proc, &rtw_drv_proc_fops, (void *)i);
if (!entry) {
rtw_warn_on(1);
goto exit;
}
}
ret = _SUCCESS;
exit:
return ret;
}
void rtw_drv_proc_deinit(void)
{
int i;
if (rtw_proc == NULL)
return;
for (i = 0;i<drv_proc_hdls_num;i++)
remove_proc_entry(drv_proc_hdls[i].name, rtw_proc);
remove_proc_entry(RTW_PROC_NAME, get_proc_net);
rtw_proc = NULL;
}
static int proc_get_sd_f0_reg_dump(struct seq_file *m, void *v)
{
struct net_device *dev = m->private;
struct adapter *adapter = (struct adapter *)rtw_netdev_priv(dev);
sd_f0_reg_dump(m, adapter);
return 0;
}
static int proc_get_mac_reg_dump(struct seq_file *m, void *v)
{
struct net_device *dev = m->private;
struct adapter *adapter = (struct adapter *)rtw_netdev_priv(dev);
mac_reg_dump(m, adapter);
return 0;
}
static int proc_get_bb_reg_dump(struct seq_file *m, void *v)
{
struct net_device *dev = m->private;
struct adapter *adapter = (struct adapter *)rtw_netdev_priv(dev);
bb_reg_dump(m, adapter);
return 0;
}
static int proc_get_rf_reg_dump(struct seq_file *m, void *v)
{
struct net_device *dev = m->private;
struct adapter *adapter = (struct adapter *)rtw_netdev_priv(dev);
rf_reg_dump(m, adapter);
return 0;
}
static int proc_get_linked_info_dump(struct seq_file *m, void *v)
{
struct net_device *dev = m->private;
struct adapter *padapter = (struct adapter *)rtw_netdev_priv(dev);
if (padapter)
DBG_871X_SEL_NL(m, "linked_info_dump :%s\n", (padapter->bLinkInfoDump)?"enable":"disable");
return 0;
}
static ssize_t proc_set_linked_info_dump(struct file *file, const char __user *buffer, size_t count, loff_t *pos, void *data)
{
struct net_device *dev = data;
struct adapter *padapter = (struct adapter *)rtw_netdev_priv(dev);
char tmp[2];
int mode = 0;
if (count < 1)
return -EFAULT;
if (buffer && !copy_from_user(tmp, buffer, sizeof(tmp))) {
if (padapter)
{
linked_info_dump(padapter, mode);
}
}
return count;
}
static int proc_get_rx_info(struct seq_file *m, void *v)
{
struct net_device *dev = m->private;
struct adapter *padapter = (struct adapter *)rtw_netdev_priv(dev);
struct dvobj_priv *psdpriv = padapter->dvobj;
struct debug_priv *pdbgpriv = &psdpriv->drv_dbg;
DBG_871X_SEL_NL(m,"Counts of Packets Whose Seq_Num Less Than Reorder Control Seq_Num: %llu\n", (unsigned long long)pdbgpriv->dbg_rx_ampdu_drop_count);
DBG_871X_SEL_NL(m,"Rx Reorder Time-out Trigger Counts: %llu\n", (unsigned long long)pdbgpriv->dbg_rx_ampdu_forced_indicate_count);
DBG_871X_SEL_NL(m,"Rx Packet Loss Counts: %llu\n", (unsigned long long)pdbgpriv->dbg_rx_ampdu_loss_count);
DBG_871X_SEL_NL(m,"Duplicate Management Frame Drop Count: %llu\n", (unsigned long long)pdbgpriv->dbg_rx_dup_mgt_frame_drop_count);
DBG_871X_SEL_NL(m,"AMPDU BA window shift Count: %llu\n", (unsigned long long)pdbgpriv->dbg_rx_ampdu_window_shift_cnt);
return 0;
}
static ssize_t proc_reset_rx_info(struct file *file, const char __user *buffer, size_t count, loff_t *pos, void *data)
{
struct net_device *dev = data;
struct adapter *padapter = (struct adapter *)rtw_netdev_priv(dev);
struct dvobj_priv *psdpriv = padapter->dvobj;
struct debug_priv *pdbgpriv = &psdpriv->drv_dbg;
char cmd[32];
if (buffer && !copy_from_user(cmd, buffer, sizeof(cmd))) {
if ('0' == cmd[0]) {
pdbgpriv->dbg_rx_ampdu_drop_count = 0;
pdbgpriv->dbg_rx_ampdu_forced_indicate_count = 0;
pdbgpriv->dbg_rx_ampdu_loss_count = 0;
pdbgpriv->dbg_rx_dup_mgt_frame_drop_count = 0;
pdbgpriv->dbg_rx_ampdu_window_shift_cnt = 0;
}
}
return count;
}
static int proc_get_cam(struct seq_file *m, void *v)
{
return 0;
}
static ssize_t proc_set_cam(struct file *file, const char __user *buffer, size_t count, loff_t *pos, void *data)
{
struct net_device *dev = data;
struct adapter *adapter;
char tmp[32];
char cmd[5];
u8 id;
adapter = (struct adapter *)rtw_netdev_priv(dev);
if (!adapter)
return -EFAULT;
if (buffer && !copy_from_user(tmp, buffer, sizeof(tmp))) {
int num = sscanf(tmp, "%4s %hhu", cmd, &id);
if (num < 2)
return count;
if (id >= TOTAL_CAM_ENTRY)
return -EINVAL;
if (strcmp("c", cmd) == 0) {
_clear_cam_entry(adapter, id);
adapter->securitypriv.hw_decrypted = false;
} else if (strcmp("wfc", cmd) == 0) {
write_cam_from_cache(adapter, id);
}
}
return count;
}
static int proc_get_cam_cache(struct seq_file *m, void *v)
{
struct net_device *dev = m->private;
struct adapter *adapter = (struct adapter *)rtw_netdev_priv(dev);
struct dvobj_priv *dvobj = adapter_to_dvobj(adapter);
u8 i;
DBG_871X_SEL_NL(m, "cam bitmap:0x%016llx\n", dvobj->cam_ctl.bitmap);
DBG_871X_SEL_NL(m, "%-2s %-6s %-17s %-32s %-3s %-7s"
"\n"
, "id", "ctrl", "addr", "key", "kid", "type"
);
for (i = 0;i<32;i++) {
if (dvobj->cam_cache[i].ctrl != 0)
DBG_871X_SEL_NL(m, "%2u 0x%04x "MAC_FMT" "KEY_FMT" %3u %-7s"
"\n", i
, dvobj->cam_cache[i].ctrl
, MAC_ARG(dvobj->cam_cache[i].mac)
, KEY_ARG(dvobj->cam_cache[i].key)
, (dvobj->cam_cache[i].ctrl)&0x03
, security_type_str(((dvobj->cam_cache[i].ctrl)>>2)&0x07)
);
}
return 0;
}
static int rtw_adapter_proc_open(struct inode *inode, struct file *file)
{
ssize_t index = (ssize_t)PDE_DATA(inode);
const struct rtw_proc_hdl *hdl = adapter_proc_hdls+index;
return single_open(file, hdl->show, proc_get_parent_data(inode));
}
static ssize_t rtw_adapter_proc_write(struct file *file, const char __user *buffer, size_t count, loff_t *pos)
{
ssize_t index = (ssize_t)PDE_DATA(file_inode(file));
const struct rtw_proc_hdl *hdl = adapter_proc_hdls+index;
ssize_t (*write)(struct file *, const char __user *, size_t, loff_t *, void *) = hdl->write;
if (write)
return write(file, buffer, count, pos, ((struct seq_file *)file->private_data)->private);
return -EROFS;
}
int proc_get_odm_dbg_comp(struct seq_file *m, void *v)
{
struct net_device *dev = m->private;
struct adapter *adapter = (struct adapter *)rtw_netdev_priv(dev);
rtw_odm_dbg_comp_msg(m, adapter);
return 0;
}
ssize_t proc_set_odm_dbg_comp(struct file *file, const char __user *buffer, size_t count, loff_t *pos, void *data)
{
struct net_device *dev = data;
struct adapter *adapter = (struct adapter *)rtw_netdev_priv(dev);
char tmp[32];
u64 dbg_comp;
if (count < 1)
return -EFAULT;
if (buffer && !copy_from_user(tmp, buffer, sizeof(tmp))) {
int num = sscanf(tmp, "%llx", &dbg_comp);
if (num != 1)
return count;
rtw_odm_dbg_comp_set(adapter, dbg_comp);
}
return count;
}
int proc_get_odm_dbg_level(struct seq_file *m, void *v)
{
struct net_device *dev = m->private;
struct adapter *adapter = (struct adapter *)rtw_netdev_priv(dev);
rtw_odm_dbg_level_msg(m, adapter);
return 0;
}
ssize_t proc_set_odm_dbg_level(struct file *file, const char __user *buffer, size_t count, loff_t *pos, void *data)
{
struct net_device *dev = data;
struct adapter *adapter = (struct adapter *)rtw_netdev_priv(dev);
char tmp[32];
u32 dbg_level;
if (count < 1)
return -EFAULT;
if (buffer && !copy_from_user(tmp, buffer, sizeof(tmp))) {
int num = sscanf(tmp, "%u", &dbg_level);
if (num != 1)
return count;
rtw_odm_dbg_level_set(adapter, dbg_level);
}
return count;
}
static int proc_get_odm_ability(struct seq_file *m, void *v)
{
struct net_device *dev = m->private;
struct adapter *adapter = (struct adapter *)rtw_netdev_priv(dev);
rtw_odm_ability_msg(m, adapter);
return 0;
}
static ssize_t proc_set_odm_ability(struct file *file, const char __user *buffer, size_t count, loff_t *pos, void *data)
{
struct net_device *dev = data;
struct adapter *adapter = (struct adapter *)rtw_netdev_priv(dev);
char tmp[32];
u32 ability;
if (count < 1)
return -EFAULT;
if (buffer && !copy_from_user(tmp, buffer, sizeof(tmp))) {
int num = sscanf(tmp, "%x", &ability);
if (num != 1)
return count;
rtw_odm_ability_set(adapter, ability);
}
return count;
}
int proc_get_odm_adaptivity(struct seq_file *m, void *v)
{
struct net_device *dev = m->private;
struct adapter *padapter = (struct adapter *)rtw_netdev_priv(dev);
rtw_odm_adaptivity_parm_msg(m, padapter);
return 0;
}
ssize_t proc_set_odm_adaptivity(struct file *file, const char __user *buffer, size_t count, loff_t *pos, void *data)
{
struct net_device *dev = data;
struct adapter *padapter = (struct adapter *)rtw_netdev_priv(dev);
char tmp[32];
u32 TH_L2H_ini;
s8 TH_EDCCA_HL_diff;
u32 IGI_Base;
int ForceEDCCA;
u8 AdapEn_RSSI;
u8 IGI_LowerBound;
if (count < 1)
return -EFAULT;
if (buffer && !copy_from_user(tmp, buffer, sizeof(tmp))) {
int num = sscanf(tmp, "%x %hhd %x %d %hhu %hhu",
&TH_L2H_ini, &TH_EDCCA_HL_diff, &IGI_Base, &ForceEDCCA, &AdapEn_RSSI, &IGI_LowerBound);
if (num != 6)
return count;
rtw_odm_adaptivity_parm_set(padapter, (s8)TH_L2H_ini, TH_EDCCA_HL_diff, (s8)IGI_Base, (bool)ForceEDCCA, AdapEn_RSSI, IGI_LowerBound);
}
return count;
}
static int rtw_odm_proc_open(struct inode *inode, struct file *file)
{
ssize_t index = (ssize_t)PDE_DATA(inode);
const struct rtw_proc_hdl *hdl = odm_proc_hdls+index;
return single_open(file, hdl->show, proc_get_parent_data(inode));
}
static ssize_t rtw_odm_proc_write(struct file *file, const char __user *buffer, size_t count, loff_t *pos)
{
ssize_t index = (ssize_t)PDE_DATA(file_inode(file));
const struct rtw_proc_hdl *hdl = odm_proc_hdls+index;
ssize_t (*write)(struct file *, const char __user *, size_t, loff_t *, void *) = hdl->write;
if (write)
return write(file, buffer, count, pos, ((struct seq_file *)file->private_data)->private);
return -EROFS;
}
static struct proc_dir_entry *rtw_odm_proc_init(struct net_device *dev)
{
struct proc_dir_entry *dir_odm = NULL;
struct proc_dir_entry *entry = NULL;
struct adapter *adapter = rtw_netdev_priv(dev);
ssize_t i;
if (adapter->dir_dev == NULL) {
rtw_warn_on(1);
goto exit;
}
if (adapter->dir_odm != NULL) {
rtw_warn_on(1);
goto exit;
}
dir_odm = rtw_proc_create_dir("odm", adapter->dir_dev, dev);
if (dir_odm == NULL) {
rtw_warn_on(1);
goto exit;
}
adapter->dir_odm = dir_odm;
for (i = 0;i<odm_proc_hdls_num;i++) {
entry = rtw_proc_create_entry(odm_proc_hdls[i].name, dir_odm, &rtw_odm_proc_fops, (void *)i);
if (!entry) {
rtw_warn_on(1);
goto exit;
}
}
exit:
return dir_odm;
}
static void rtw_odm_proc_deinit(struct adapter *adapter)
{
struct proc_dir_entry *dir_odm = NULL;
int i;
dir_odm = adapter->dir_odm;
if (dir_odm == NULL) {
rtw_warn_on(1);
return;
}
for (i = 0;i<odm_proc_hdls_num;i++)
remove_proc_entry(odm_proc_hdls[i].name, dir_odm);
remove_proc_entry("odm", adapter->dir_dev);
adapter->dir_odm = NULL;
}
struct proc_dir_entry *rtw_adapter_proc_init(struct net_device *dev)
{
struct proc_dir_entry *drv_proc = rtw_proc;
struct proc_dir_entry *dir_dev = NULL;
struct proc_dir_entry *entry = NULL;
struct adapter *adapter = rtw_netdev_priv(dev);
ssize_t i;
if (drv_proc == NULL) {
rtw_warn_on(1);
goto exit;
}
if (adapter->dir_dev != NULL) {
rtw_warn_on(1);
goto exit;
}
dir_dev = rtw_proc_create_dir(dev->name, drv_proc, dev);
if (dir_dev == NULL) {
rtw_warn_on(1);
goto exit;
}
adapter->dir_dev = dir_dev;
for (i = 0;i<adapter_proc_hdls_num;i++) {
entry = rtw_proc_create_entry(adapter_proc_hdls[i].name, dir_dev, &rtw_adapter_proc_fops, (void *)i);
if (!entry) {
rtw_warn_on(1);
goto exit;
}
}
rtw_odm_proc_init(dev);
exit:
return dir_dev;
}
void rtw_adapter_proc_deinit(struct net_device *dev)
{
struct proc_dir_entry *drv_proc = rtw_proc;
struct proc_dir_entry *dir_dev = NULL;
struct adapter *adapter = rtw_netdev_priv(dev);
int i;
dir_dev = adapter->dir_dev;
if (dir_dev == NULL) {
rtw_warn_on(1);
return;
}
for (i = 0;i<adapter_proc_hdls_num;i++)
remove_proc_entry(adapter_proc_hdls[i].name, dir_dev);
rtw_odm_proc_deinit(adapter);
remove_proc_entry(dev->name, drv_proc);
adapter->dir_dev = NULL;
}
void rtw_adapter_proc_replace(struct net_device *dev)
{
struct proc_dir_entry *drv_proc = rtw_proc;
struct proc_dir_entry *dir_dev = NULL;
struct adapter *adapter = rtw_netdev_priv(dev);
int i;
dir_dev = adapter->dir_dev;
if (dir_dev == NULL) {
rtw_warn_on(1);
return;
}
for (i = 0;i<adapter_proc_hdls_num;i++)
remove_proc_entry(adapter_proc_hdls[i].name, dir_dev);
rtw_odm_proc_deinit(adapter);
remove_proc_entry(adapter->old_ifname, drv_proc);
adapter->dir_dev = NULL;
rtw_adapter_proc_init(dev);
}
