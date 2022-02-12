struct dpram_blk *ft1000_get_buffer(struct list_head *bufflist)
{
unsigned long flags;
struct dpram_blk *ptr;
spin_lock_irqsave(&free_buff_lock, flags);
if (list_empty(bufflist)) {
DEBUG("ft1000_get_buffer: No more buffer - %d\n", numofmsgbuf);
ptr = NULL;
} else {
numofmsgbuf--;
ptr = list_entry(bufflist->next, struct dpram_blk, list);
list_del(&ptr->list);
}
spin_unlock_irqrestore(&free_buff_lock, flags);
return ptr;
}
void ft1000_free_buffer(struct dpram_blk *pdpram_blk, struct list_head *plist)
{
unsigned long flags;
spin_lock_irqsave(&free_buff_lock, flags);
list_add_tail(&pdpram_blk->list, plist);
numofmsgbuf++;
spin_unlock_irqrestore(&free_buff_lock, flags);
}
int ft1000_create_dev(struct ft1000_usb *dev)
{
int result;
int i;
struct dentry *dir, *file;
struct ft1000_debug_dirs *tmp;
sprintf(dev->DeviceName, "%s%d", "FT1000_", dev->CardNumber);
DEBUG("%s: number of instance = %d\n", __func__, ft1000_flarion_cnt);
DEBUG("DeviceCreated = %x\n", dev->DeviceCreated);
if (dev->DeviceCreated) {
DEBUG("%s: \"%s\" already registered\n", __func__, dev->DeviceName);
return -EIO;
}
DEBUG("%s: \"%s\" debugfs device registration\n", __func__, dev->DeviceName);
tmp = kmalloc(sizeof(struct ft1000_debug_dirs), GFP_KERNEL);
if (tmp == NULL) {
result = -1;
goto fail;
}
dir = debugfs_create_dir(dev->DeviceName, NULL);
if (IS_ERR(dir)) {
result = PTR_ERR(dir);
goto debug_dir_fail;
}
file = debugfs_create_file("device", S_IRUGO | S_IWUSR, dir,
dev, &ft1000fops);
if (IS_ERR(file)) {
result = PTR_ERR(file);
goto debug_file_fail;
}
tmp->dent = dir;
tmp->file = file;
tmp->int_number = dev->CardNumber;
list_add(&(tmp->list), &(dev->nodes.list));
DEBUG("%s: registered debugfs directory \"%s\"\n", __func__, dev->DeviceName);
dev->appcnt = 0;
for (i=0; i<MAX_NUM_APP; i++) {
dev->app_info[i].nTxMsg = 0;
dev->app_info[i].nRxMsg = 0;
dev->app_info[i].nTxMsgReject = 0;
dev->app_info[i].nRxMsgMiss = 0;
dev->app_info[i].fileobject = NULL;
dev->app_info[i].app_id = i+1;
dev->app_info[i].DspBCMsgFlag = 0;
dev->app_info[i].NumOfMsg = 0;
init_waitqueue_head(&dev->app_info[i].wait_dpram_msg);
INIT_LIST_HEAD(&dev->app_info[i].app_sqlist);
}
dev->DeviceCreated = TRUE;
ft1000_flarion_cnt++;
return 0;
debug_file_fail:
debugfs_remove(dir);
debug_dir_fail:
kfree(tmp);
fail:
return result;
}
void ft1000_destroy_dev(struct net_device *netdev)
{
struct ft1000_info *info = netdev_priv(netdev);
struct ft1000_usb *dev = info->priv;
int i;
struct dpram_blk *pdpram_blk;
struct dpram_blk *ptr;
struct list_head *pos, *q;
struct ft1000_debug_dirs *dir;
DEBUG("%s called\n", __func__);
if (dev->DeviceCreated) {
ft1000_flarion_cnt--;
list_for_each_safe(pos, q, &dev->nodes.list) {
dir = list_entry(pos, struct ft1000_debug_dirs, list);
if (dir->int_number == dev->CardNumber) {
debugfs_remove(dir->file);
debugfs_remove(dir->dent);
list_del(pos);
kfree(dir);
}
}
DEBUG("%s: unregistered device \"%s\"\n", __func__,
dev->DeviceName);
for (i=0; i<MAX_NUM_APP; i++) {
while (list_empty(&dev->app_info[i].app_sqlist) == 0) {
pdpram_blk = list_entry(dev->app_info[i].app_sqlist.next, struct dpram_blk, list);
list_del(&pdpram_blk->list);
ft1000_free_buffer(pdpram_blk, &freercvpool);
}
wake_up_interruptible(&dev->app_info[i].wait_dpram_msg);
}
if (ft1000_flarion_cnt == 0) {
while (list_empty(&freercvpool) == 0) {
ptr = list_entry(freercvpool.next, struct dpram_blk, list);
list_del(&ptr->list);
kfree(ptr->pbuffer);
kfree(ptr);
}
}
dev->DeviceCreated = FALSE;
}
}
static int ft1000_open(struct inode *inode, struct file *file)
{
struct ft1000_info *info;
struct ft1000_usb *dev = (struct ft1000_usb *)inode->i_private;
int i,num;
DEBUG("%s called\n", __func__);
num = (MINOR(inode->i_rdev) & 0xf);
DEBUG("ft1000_open: minor number=%d\n", num);
info = file->private_data = netdev_priv(dev->net);
DEBUG("f_owner = %p number of application = %d\n", (&file->f_owner), dev->appcnt);
if (dev->appcnt > MAX_NUM_APP) {
DEBUG("Maximum number of application exceeded\n");
return -EACCES;
}
for (i=0; i<MAX_NUM_APP; i++) {
if ((dev->app_info[i].fileobject == NULL)) {
break;
}
}
if (i == MAX_NUM_APP) {
DEBUG("Could not find an application info block\n");
return -EACCES;
}
dev->appcnt++;
dev->app_info[i].fileobject = &file->f_owner;
dev->app_info[i].nTxMsg = 0;
dev->app_info[i].nRxMsg = 0;
dev->app_info[i].nTxMsgReject = 0;
dev->app_info[i].nRxMsgMiss = 0;
nonseekable_open(inode, file);
return 0;
}
static unsigned int ft1000_poll_dev(struct file *file, poll_table *wait)
{
struct net_device *netdev = file->private_data;
struct ft1000_info *info = netdev_priv(netdev);
struct ft1000_usb *dev = info->priv;
int i;
if (ft1000_flarion_cnt == 0) {
DEBUG("FT1000:ft1000_poll_dev called when ft1000_flarion_cnt is zero\n");
return (-EBADF);
}
for (i=0; i<MAX_NUM_APP; i++) {
if (dev->app_info[i].fileobject == &file->f_owner) {
break;
}
}
if (i == MAX_NUM_APP) {
DEBUG("FT1000:ft1000_ioctl:Could not find application info block\n");
return (-EACCES);
}
if (list_empty(&dev->app_info[i].app_sqlist) == 0) {
DEBUG("FT1000:ft1000_poll_dev:Message detected in slow queue\n");
return(POLLIN | POLLRDNORM | POLLPRI);
}
poll_wait(file, &dev->app_info[i].wait_dpram_msg, wait);
return (0);
}
static long ft1000_ioctl(struct file *file, unsigned int command,
unsigned long argument)
{
void __user *argp = (void __user *)argument;
struct ft1000_info *info;
struct ft1000_usb *ft1000dev;
int result=0;
int cmd;
int i;
u16 tempword;
unsigned long flags;
struct timeval tv;
struct IOCTL_GET_VER get_ver_data;
struct IOCTL_GET_DSP_STAT get_stat_data;
u8 ConnectionMsg[] = {0x00,0x44,0x10,0x20,0x80,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x93,0x64,
0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x0a,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x12,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x02,0x37,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x01,0x00,0x01,0x7f,0x00,
0x00,0x01,0x00,0x00};
unsigned short ledStat=0;
unsigned short conStat=0;
if (ft1000_flarion_cnt == 0) {
DEBUG("FT1000:ft1000_ioctl called when ft1000_flarion_cnt is zero\n");
return (-EBADF);
}
info = file->private_data;
ft1000dev = info->priv;
cmd = _IOC_NR(command);
switch (cmd) {
case IOCTL_REGISTER_CMD:
DEBUG("FT1000:ft1000_ioctl: IOCTL_FT1000_REGISTER called\n");
result = get_user(tempword, (__u16 __user*)argp);
if (result) {
DEBUG("result = %d failed to get_user\n", result);
break;
}
if (tempword == DSPBCMSGID) {
for (i=0; i<MAX_NUM_APP; i++) {
if (ft1000dev->app_info[i].fileobject == &file->f_owner) {
ft1000dev->app_info[i].DspBCMsgFlag = 1;
DEBUG("FT1000:ft1000_ioctl:Registered for broadcast messages\n");
break;
}
}
}
break;
case IOCTL_GET_VER_CMD:
DEBUG("FT1000:ft1000_ioctl: IOCTL_FT1000_GET_VER called\n");
get_ver_data.drv_ver = FT1000_DRV_VER;
if (copy_to_user(argp, &get_ver_data, sizeof(get_ver_data))) {
DEBUG("FT1000:ft1000_ioctl: copy fault occurred\n");
result = -EFAULT;
break;
}
DEBUG("FT1000:ft1000_ioctl:driver version = 0x%x\n",(unsigned int)get_ver_data.drv_ver);
break;
case IOCTL_CONNECT:
DEBUG("FT1000:ft1000_ioctl: IOCTL_FT1000_CONNECT\n");
ConnectionMsg[79] = 0xfc;
result = card_send_command(ft1000dev, (unsigned short *)ConnectionMsg, 0x4c);
break;
case IOCTL_DISCONNECT:
DEBUG("FT1000:ft1000_ioctl: IOCTL_FT1000_DISCONNECT\n");
ConnectionMsg[79] = 0xfd;
result = card_send_command(ft1000dev, (unsigned short *)ConnectionMsg, 0x4c);
break;
case IOCTL_GET_DSP_STAT_CMD:
memset(&get_stat_data, 0, sizeof(get_stat_data));
memcpy(get_stat_data.DspVer, info->DspVer, DSPVERSZ);
memcpy(get_stat_data.HwSerNum, info->HwSerNum, HWSERNUMSZ);
memcpy(get_stat_data.Sku, info->Sku, SKUSZ);
memcpy(get_stat_data.eui64, info->eui64, EUISZ);
if (info->ProgConStat != 0xFF) {
ft1000_read_dpram16(ft1000dev, FT1000_MAG_DSP_LED, (u8 *)&ledStat, FT1000_MAG_DSP_LED_INDX);
get_stat_data.LedStat = ntohs(ledStat);
DEBUG("FT1000:ft1000_ioctl: LedStat = 0x%x\n", get_stat_data.LedStat);
ft1000_read_dpram16(ft1000dev, FT1000_MAG_DSP_CON_STATE, (u8 *)&conStat, FT1000_MAG_DSP_CON_STATE_INDX);
get_stat_data.ConStat = ntohs(conStat);
DEBUG("FT1000:ft1000_ioctl: ConStat = 0x%x\n", get_stat_data.ConStat);
} else {
get_stat_data.ConStat = 0x0f;
}
get_stat_data.nTxPkts = info->stats.tx_packets;
get_stat_data.nRxPkts = info->stats.rx_packets;
get_stat_data.nTxBytes = info->stats.tx_bytes;
get_stat_data.nRxBytes = info->stats.rx_bytes;
do_gettimeofday(&tv);
get_stat_data.ConTm = (u32)(tv.tv_sec - info->ConTm);
DEBUG("Connection Time = %d\n", (int)get_stat_data.ConTm);
if (copy_to_user(argp, &get_stat_data, sizeof(get_stat_data))) {
DEBUG("FT1000:ft1000_ioctl: copy fault occurred\n");
result = -EFAULT;
break;
}
DEBUG("ft1000_chioctl: GET_DSP_STAT succeed\n");
break;
case IOCTL_SET_DPRAM_CMD:
{
struct IOCTL_DPRAM_BLK *dpram_data = NULL;
u16 qtype;
u16 msgsz;
struct pseudo_hdr *ppseudo_hdr;
u16 *pmsg;
u16 total_len;
u16 app_index;
u16 status;
if (ft1000_flarion_cnt == 0) {
return (-EBADF);
}
if (ft1000dev->DrvMsgPend) {
return (-ENOTTY);
}
if (ft1000dev->fProvComplete == 0) {
return (-EACCES);
}
ft1000dev->fAppMsgPend = 1;
if (info->CardReady) {
result = get_user(msgsz, (__u16 __user *)argp);
if (result)
break;
msgsz = ntohs(msgsz);
if (msgsz > MAX_CMD_SQSIZE) {
DEBUG("FT1000:ft1000_ioctl: bad message length = %d\n", msgsz);
result = -EINVAL;
break;
}
result = -ENOMEM;
dpram_data = kmalloc(msgsz + 2, GFP_KERNEL);
if (!dpram_data)
break;
if (copy_from_user(dpram_data, argp, msgsz+2)) {
DEBUG("FT1000:ft1000_ChIoctl: copy fault occurred\n");
result = -EFAULT;
} else {
for (i=0; i<MAX_NUM_APP; i++) {
if (ft1000dev->app_info[i].fileobject == &file->f_owner) {
break;
}
}
if (i==MAX_NUM_APP) {
DEBUG("FT1000:No matching application fileobject\n");
result = -EINVAL;
kfree(dpram_data);
break;
}
app_index = i;
qtype = ntohs(dpram_data->pseudohdr.qos_class) & 0xff;
if (qtype) {
} else {
status = ft1000_read_register(ft1000dev, &tempword, FT1000_REG_DOORBELL);
if (tempword & FT1000_DB_DPRAM_TX) {
mdelay(2);
status = ft1000_read_register(ft1000dev, &tempword, FT1000_REG_DOORBELL);
if (tempword & FT1000_DB_DPRAM_TX) {
mdelay(1);
status = ft1000_read_register(ft1000dev, &tempword, FT1000_REG_DOORBELL);
if (tempword & FT1000_DB_DPRAM_TX) {
status = ft1000_read_register(ft1000dev, &tempword, FT1000_REG_DOORBELL);
if (tempword & FT1000_DB_DPRAM_TX) {
mdelay(3);
status = ft1000_read_register(ft1000dev, &tempword, FT1000_REG_DOORBELL);
if (tempword & FT1000_DB_DPRAM_TX) {
DEBUG("FT1000:ft1000_ioctl:Doorbell not available\n");
result = -ENOTTY;
kfree(dpram_data);
break;
}
}
}
}
}
if ((msgsz < MAX_CMD_SQSIZE) && (msgsz > PSEUDOSZ)) {
pmsg = (u16 *)&dpram_data->pseudohdr;
ppseudo_hdr = (struct pseudo_hdr *)pmsg;
total_len = msgsz+2;
if (total_len & 0x1) {
total_len++;
}
ppseudo_hdr->seq_num = info->squeseqnum++;
ppseudo_hdr->portsrc = ft1000dev->app_info[app_index].app_id;
ppseudo_hdr->checksum = *pmsg++;
for (i=1; i<7; i++) {
ppseudo_hdr->checksum ^= *pmsg++;
}
pmsg++;
ppseudo_hdr = (struct pseudo_hdr *)pmsg;
result = card_send_command(ft1000dev,(unsigned short*)dpram_data,total_len+2);
ft1000dev->app_info[app_index].nTxMsg++;
} else {
result = -EINVAL;
}
}
}
} else {
DEBUG("FT1000:ft1000_ioctl: Card not ready take messages\n");
result = -EACCES;
}
kfree(dpram_data);
}
break;
case IOCTL_GET_DPRAM_CMD:
{
struct dpram_blk *pdpram_blk;
struct IOCTL_DPRAM_BLK __user *pioctl_dpram;
int msglen;
if (ft1000_flarion_cnt == 0) {
return (-EBADF);
}
for (i=0; i<MAX_NUM_APP; i++) {
if (ft1000dev->app_info[i].fileobject == &file->f_owner) {
break;
}
}
if (i == MAX_NUM_APP) {
DEBUG("FT1000:ft1000_ioctl:Could not find application info block\n");
result = -EBADF;
break;
}
result = 0;
pioctl_dpram = argp;
if (list_empty(&ft1000dev->app_info[i].app_sqlist) == 0) {
spin_lock_irqsave(&free_buff_lock, flags);
pdpram_blk = list_entry(ft1000dev->app_info[i].app_sqlist.next, struct dpram_blk, list);
list_del(&pdpram_blk->list);
ft1000dev->app_info[i].NumOfMsg--;
spin_unlock_irqrestore(&free_buff_lock, flags);
msglen = ntohs(*(u16 *)pdpram_blk->pbuffer) + PSEUDOSZ;
result = get_user(msglen, &pioctl_dpram->total_len);
if (result)
break;
msglen = htons(msglen);
if (copy_to_user (&pioctl_dpram->pseudohdr, pdpram_blk->pbuffer, msglen)) {
DEBUG("FT1000:ft1000_ioctl: copy fault occurred\n");
result = -EFAULT;
break;
}
ft1000_free_buffer(pdpram_blk, &freercvpool);
result = msglen;
}
}
break;
default:
DEBUG("FT1000:ft1000_ioctl:unknown command: 0x%x\n", command);
result = -ENOTTY;
break;
}
ft1000dev->fAppMsgPend = 0;
return result;
}
static int ft1000_release(struct inode *inode, struct file *file)
{
struct ft1000_info *info;
struct net_device *dev;
struct ft1000_usb *ft1000dev;
int i;
struct dpram_blk *pdpram_blk;
DEBUG("ft1000_release called\n");
dev = file->private_data;
info = netdev_priv(dev);
ft1000dev = info->priv;
if (ft1000_flarion_cnt == 0) {
ft1000dev->appcnt--;
return (-EBADF);
}
for (i=0; i<MAX_NUM_APP; i++) {
if (ft1000dev->app_info[i].fileobject == &file->f_owner) {
break;
}
}
if (i==MAX_NUM_APP)
return 0;
while (list_empty(&ft1000dev->app_info[i].app_sqlist) == 0) {
DEBUG("Remove and free memory queue up on slow queue\n");
pdpram_blk = list_entry(ft1000dev->app_info[i].app_sqlist.next, struct dpram_blk, list);
list_del(&pdpram_blk->list);
ft1000_free_buffer(pdpram_blk, &freercvpool);
}
ft1000dev->appcnt--;
DEBUG("ft1000_chdev:%s:appcnt = %d\n", __func__, ft1000dev->appcnt);
ft1000dev->app_info[i].fileobject = NULL;
return 0;
}
