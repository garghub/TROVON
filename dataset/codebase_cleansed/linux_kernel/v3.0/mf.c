static void free_pending_event(struct pending_event *ev)
{
if (ev != NULL) {
ev->next = pending_event_avail;
pending_event_avail = ev;
}
}
static int signal_event(struct pending_event *ev)
{
int rc = 0;
unsigned long flags;
int go = 1;
struct pending_event *ev1;
HvLpEvent_Rc hv_rc;
if (ev != NULL) {
ev->next = NULL;
spin_lock_irqsave(&pending_event_spinlock, flags);
if (pending_event_head == NULL)
pending_event_head = ev;
else {
go = 0;
pending_event_tail->next = ev;
}
pending_event_tail = ev;
spin_unlock_irqrestore(&pending_event_spinlock, flags);
}
while (go) {
go = 0;
if (pending_event_head->dma_data_length > 0)
HvCallEvent_dmaToSp(pending_event_head->dma_data,
pending_event_head->remote_address,
pending_event_head->dma_data_length,
HvLpDma_Direction_LocalToRemote);
hv_rc = HvCallEvent_signalLpEvent(
&pending_event_head->event.hp_lp_event);
if (hv_rc != HvLpEvent_Rc_Good) {
printk(KERN_ERR "mf.c: HvCallEvent_signalLpEvent() "
"failed with %d\n", (int)hv_rc);
spin_lock_irqsave(&pending_event_spinlock, flags);
ev1 = pending_event_head;
pending_event_head = pending_event_head->next;
if (pending_event_head != NULL)
go = 1;
spin_unlock_irqrestore(&pending_event_spinlock, flags);
if (ev1 == ev)
rc = -EIO;
else if (ev1->hdlr != NULL)
(*ev1->hdlr)((void *)ev1->event.hp_lp_event.xCorrelationToken, -EIO);
spin_lock_irqsave(&pending_event_spinlock, flags);
free_pending_event(ev1);
spin_unlock_irqrestore(&pending_event_spinlock, flags);
}
}
return rc;
}
static struct pending_event *new_pending_event(void)
{
struct pending_event *ev = NULL;
HvLpIndex primary_lp = HvLpConfig_getPrimaryLpIndex();
unsigned long flags;
struct HvLpEvent *hev;
spin_lock_irqsave(&pending_event_spinlock, flags);
if (pending_event_avail != NULL) {
ev = pending_event_avail;
pending_event_avail = pending_event_avail->next;
}
spin_unlock_irqrestore(&pending_event_spinlock, flags);
if (ev == NULL) {
ev = kmalloc(sizeof(struct pending_event), GFP_ATOMIC);
if (ev == NULL) {
printk(KERN_ERR "mf.c: unable to kmalloc %ld bytes\n",
sizeof(struct pending_event));
return NULL;
}
}
memset(ev, 0, sizeof(struct pending_event));
hev = &ev->event.hp_lp_event;
hev->flags = HV_LP_EVENT_VALID | HV_LP_EVENT_DO_ACK | HV_LP_EVENT_INT;
hev->xType = HvLpEvent_Type_MachineFac;
hev->xSourceLp = HvLpConfig_getLpIndex();
hev->xTargetLp = primary_lp;
hev->xSizeMinus1 = sizeof(ev->event) - 1;
hev->xRc = HvLpEvent_Rc_Good;
hev->xSourceInstanceId = HvCallEvent_getSourceLpInstanceId(primary_lp,
HvLpEvent_Type_MachineFac);
hev->xTargetInstanceId = HvCallEvent_getTargetLpInstanceId(primary_lp,
HvLpEvent_Type_MachineFac);
return ev;
}
static int __maybe_unused
signal_vsp_instruction(struct vsp_cmd_data *vsp_cmd)
{
struct pending_event *ev = new_pending_event();
int rc;
struct vsp_rsp_data response;
if (ev == NULL)
return -ENOMEM;
init_completion(&response.com);
response.response = vsp_cmd;
ev->event.hp_lp_event.xSubtype = 6;
ev->event.hp_lp_event.x.xSubtypeData =
subtype_data('M', 'F', 'V', 'I');
ev->event.data.vsp_cmd.token = (u64)&response;
ev->event.data.vsp_cmd.cmd = vsp_cmd->cmd;
ev->event.data.vsp_cmd.lp_index = HvLpConfig_getLpIndex();
ev->event.data.vsp_cmd.result_code = 0xFF;
ev->event.data.vsp_cmd.reserved = 0;
memcpy(&(ev->event.data.vsp_cmd.sub_data),
&(vsp_cmd->sub_data), sizeof(vsp_cmd->sub_data));
mb();
rc = signal_event(ev);
if (rc == 0)
wait_for_completion(&response.com);
return rc;
}
static int signal_ce_msg(char *ce_msg, struct ce_msg_comp_data *completion)
{
struct pending_event *ev = new_pending_event();
if (ev == NULL)
return -ENOMEM;
ev->event.hp_lp_event.xSubtype = 0;
ev->event.hp_lp_event.x.xSubtypeData =
subtype_data('M', 'F', 'C', 'E');
memcpy(ev->event.data.ce_msg.ce_msg, ce_msg, 12);
ev->event.data.ce_msg.completion = completion;
return signal_event(ev);
}
static int signal_ce_msg_simple(u8 ce_op, struct ce_msg_comp_data *completion)
{
u8 ce_msg[12];
memset(ce_msg, 0, sizeof(ce_msg));
ce_msg[3] = ce_op;
return signal_ce_msg(ce_msg, completion);
}
static int dma_and_signal_ce_msg(char *ce_msg,
struct ce_msg_comp_data *completion, void *dma_data,
unsigned dma_data_length, unsigned remote_address)
{
struct pending_event *ev = new_pending_event();
if (ev == NULL)
return -ENOMEM;
ev->event.hp_lp_event.xSubtype = 0;
ev->event.hp_lp_event.x.xSubtypeData =
subtype_data('M', 'F', 'C', 'E');
memcpy(ev->event.data.ce_msg.ce_msg, ce_msg, 12);
ev->event.data.ce_msg.completion = completion;
memcpy(ev->dma_data, dma_data, dma_data_length);
ev->dma_data_length = dma_data_length;
ev->remote_address = remote_address;
return signal_event(ev);
}
static int shutdown(void)
{
int rc = kill_cad_pid(SIGINT, 1);
if (rc) {
printk(KERN_ALERT "mf.c: SIGINT to init failed (%d), "
"hard shutdown commencing\n", rc);
mf_power_off();
} else
printk(KERN_INFO "mf.c: init has been successfully notified "
"to proceed with shutdown\n");
return rc;
}
static void handle_int(struct io_mf_lp_event *event)
{
struct ce_msg_data *ce_msg_data;
struct ce_msg_data *pce_msg_data;
unsigned long flags;
struct pending_event *pev;
event->hp_lp_event.xRc = HvLpEvent_Rc_Good;
HvCallEvent_ackLpEvent(&event->hp_lp_event);
switch (event->hp_lp_event.xSubtype) {
case 0:
ce_msg_data = &event->data.ce_msg;
switch (ce_msg_data->ce_msg[3]) {
case 0x5B:
if ((ce_msg_data->ce_msg[5] & 0x20) != 0) {
printk(KERN_INFO "mf.c: Commencing partition shutdown\n");
if (shutdown() == 0)
signal_ce_msg_simple(0xDB, NULL);
}
break;
case 0xC0:
spin_lock_irqsave(&pending_event_spinlock, flags);
pev = pending_event_head;
if (pev != NULL)
pending_event_head = pending_event_head->next;
spin_unlock_irqrestore(&pending_event_spinlock, flags);
if (pev == NULL)
break;
pce_msg_data = &pev->event.data.ce_msg;
if (pce_msg_data->ce_msg[3] != 0x40)
break;
if (pce_msg_data->completion != NULL) {
ce_msg_comp_hdlr handler =
pce_msg_data->completion->handler;
void *token = pce_msg_data->completion->token;
if (handler != NULL)
(*handler)(token, ce_msg_data);
}
spin_lock_irqsave(&pending_event_spinlock, flags);
free_pending_event(pev);
spin_unlock_irqrestore(&pending_event_spinlock, flags);
if (pending_event_head != NULL)
signal_event(NULL);
break;
}
break;
case 1:
printk(KERN_INFO "mf.c: Commencing system shutdown\n");
shutdown();
break;
}
}
static void handle_ack(struct io_mf_lp_event *event)
{
unsigned long flags;
struct pending_event *two = NULL;
unsigned long free_it = 0;
struct ce_msg_data *ce_msg_data;
struct ce_msg_data *pce_msg_data;
struct vsp_rsp_data *rsp;
if (pending_event_head == NULL) {
printk(KERN_ERR "mf.c: stack empty for receiving ack\n");
return;
}
switch (event->hp_lp_event.xSubtype) {
case 0:
ce_msg_data = &event->data.ce_msg;
if (ce_msg_data->ce_msg[3] != 0x40) {
free_it = 1;
break;
}
if (ce_msg_data->ce_msg[2] == 0)
break;
free_it = 1;
pce_msg_data = &pending_event_head->event.data.ce_msg;
if (pce_msg_data->completion != NULL) {
ce_msg_comp_hdlr handler =
pce_msg_data->completion->handler;
void *token = pce_msg_data->completion->token;
if (handler != NULL)
(*handler)(token, ce_msg_data);
}
break;
case 4:
case 5:
if (pending_event_head->hdlr != NULL)
(*pending_event_head->hdlr)((void *)event->hp_lp_event.xCorrelationToken, event->data.alloc.count);
free_it = 1;
break;
case 6:
free_it = 1;
rsp = (struct vsp_rsp_data *)event->data.vsp_cmd.token;
if (rsp == NULL) {
printk(KERN_ERR "mf.c: no rsp\n");
break;
}
if (rsp->response != NULL)
memcpy(rsp->response, &event->data.vsp_cmd,
sizeof(event->data.vsp_cmd));
complete(&rsp->com);
break;
}
spin_lock_irqsave(&pending_event_spinlock, flags);
if ((pending_event_head != NULL) && (free_it == 1)) {
struct pending_event *oldHead = pending_event_head;
pending_event_head = pending_event_head->next;
two = pending_event_head;
free_pending_event(oldHead);
}
spin_unlock_irqrestore(&pending_event_spinlock, flags);
if (two != NULL)
signal_event(NULL);
}
static void hv_handler(struct HvLpEvent *event)
{
if ((event != NULL) && (event->xType == HvLpEvent_Type_MachineFac)) {
if (hvlpevent_is_ack(event))
handle_ack((struct io_mf_lp_event *)event);
else
handle_int((struct io_mf_lp_event *)event);
} else
printk(KERN_ERR "mf.c: alien event received\n");
}
void mf_allocate_lp_events(HvLpIndex target_lp, HvLpEvent_Type type,
unsigned size, unsigned count, MFCompleteHandler hdlr,
void *user_token)
{
struct pending_event *ev = new_pending_event();
int rc;
if (ev == NULL) {
rc = -ENOMEM;
} else {
ev->event.hp_lp_event.xSubtype = 4;
ev->event.hp_lp_event.xCorrelationToken = (u64)user_token;
ev->event.hp_lp_event.x.xSubtypeData =
subtype_data('M', 'F', 'M', 'A');
ev->event.data.alloc.target_lp = target_lp;
ev->event.data.alloc.type = type;
ev->event.data.alloc.size = size;
ev->event.data.alloc.count = count;
ev->hdlr = hdlr;
rc = signal_event(ev);
}
if ((rc != 0) && (hdlr != NULL))
(*hdlr)(user_token, rc);
}
void mf_deallocate_lp_events(HvLpIndex target_lp, HvLpEvent_Type type,
unsigned count, MFCompleteHandler hdlr, void *user_token)
{
struct pending_event *ev = new_pending_event();
int rc;
if (ev == NULL)
rc = -ENOMEM;
else {
ev->event.hp_lp_event.xSubtype = 5;
ev->event.hp_lp_event.xCorrelationToken = (u64)user_token;
ev->event.hp_lp_event.x.xSubtypeData =
subtype_data('M', 'F', 'M', 'D');
ev->event.data.alloc.target_lp = target_lp;
ev->event.data.alloc.type = type;
ev->event.data.alloc.count = count;
ev->hdlr = hdlr;
rc = signal_event(ev);
}
if ((rc != 0) && (hdlr != NULL))
(*hdlr)(user_token, rc);
}
void mf_power_off(void)
{
printk(KERN_INFO "mf.c: Down it goes...\n");
signal_ce_msg_simple(0x4d, NULL);
for (;;)
;
}
void mf_reboot(char *cmd)
{
printk(KERN_INFO "mf.c: Preparing to bounce...\n");
signal_ce_msg_simple(0x4e, NULL);
for (;;)
;
}
void mf_display_src(u32 word)
{
u8 ce[12];
memset(ce, 0, sizeof(ce));
ce[3] = 0x4a;
ce[7] = 0x01;
ce[8] = word >> 24;
ce[9] = word >> 16;
ce[10] = word >> 8;
ce[11] = word;
signal_ce_msg(ce, NULL);
}
static __init void mf_display_progress_src(u16 value)
{
u8 ce[12];
u8 src[72];
memcpy(ce, "\x00\x00\x04\x4A\x00\x00\x00\x48\x00\x00\x00\x00", 12);
memcpy(src, "\x01\x00\x00\x01\x00\x00\x00\x00\x00\x00\x00\x00"
"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00"
"\x00\x00\x00\x00PROGxxxx ",
72);
src[6] = value >> 8;
src[7] = value & 255;
src[44] = "0123456789ABCDEF"[(value >> 12) & 15];
src[45] = "0123456789ABCDEF"[(value >> 8) & 15];
src[46] = "0123456789ABCDEF"[(value >> 4) & 15];
src[47] = "0123456789ABCDEF"[value & 15];
dma_and_signal_ce_msg(ce, NULL, src, sizeof(src), 9 * 64 * 1024);
}
static void mf_clear_src(void)
{
signal_ce_msg_simple(0x4b, NULL);
}
void __init mf_display_progress(u16 value)
{
if (!mf_initialized)
return;
if (0xFFFF == value)
mf_clear_src();
else
mf_display_progress_src(value);
}
void __init mf_init(void)
{
int i;
spin_lock_init(&pending_event_spinlock);
for (i = 0; i < PENDING_EVENT_PREALLOC_LEN; i++)
free_pending_event(&pending_event_prealloc[i]);
HvLpEvent_registerHandler(HvLpEvent_Type_MachineFac, &hv_handler);
signal_ce_msg_simple(0x57, NULL);
mf_initialized = 1;
mb();
printk(KERN_NOTICE "mf.c: iSeries Linux LPAR Machine Facilities "
"initialized\n");
}
static void get_rtc_time_complete(void *token, struct ce_msg_data *ce_msg)
{
struct rtc_time_data *rtc = token;
memcpy(&rtc->ce_msg, ce_msg, sizeof(rtc->ce_msg));
rtc->rc = 0;
complete(&rtc->com);
}
static int mf_set_rtc(struct rtc_time *tm)
{
char ce_time[12];
u8 day, mon, hour, min, sec, y1, y2;
unsigned year;
year = 1900 + tm->tm_year;
y1 = year / 100;
y2 = year % 100;
sec = tm->tm_sec;
min = tm->tm_min;
hour = tm->tm_hour;
day = tm->tm_mday;
mon = tm->tm_mon + 1;
sec = bin2bcd(sec);
min = bin2bcd(min);
hour = bin2bcd(hour);
mon = bin2bcd(mon);
day = bin2bcd(day);
y1 = bin2bcd(y1);
y2 = bin2bcd(y2);
memset(ce_time, 0, sizeof(ce_time));
ce_time[3] = 0x41;
ce_time[4] = y1;
ce_time[5] = y2;
ce_time[6] = sec;
ce_time[7] = min;
ce_time[8] = hour;
ce_time[10] = day;
ce_time[11] = mon;
return signal_ce_msg(ce_time, NULL);
}
static int rtc_set_tm(int rc, u8 *ce_msg, struct rtc_time *tm)
{
tm->tm_wday = 0;
tm->tm_yday = 0;
tm->tm_isdst = 0;
if (rc) {
tm->tm_sec = 0;
tm->tm_min = 0;
tm->tm_hour = 0;
tm->tm_mday = 15;
tm->tm_mon = 5;
tm->tm_year = 52;
return rc;
}
if ((ce_msg[2] == 0xa9) ||
(ce_msg[2] == 0xaf)) {
tm->tm_sec = 1;
tm->tm_min = 1;
tm->tm_hour = 1;
tm->tm_mday = 10;
tm->tm_mon = 8;
tm->tm_year = 71;
mf_set_rtc(tm);
}
{
u8 year = ce_msg[5];
u8 sec = ce_msg[6];
u8 min = ce_msg[7];
u8 hour = ce_msg[8];
u8 day = ce_msg[10];
u8 mon = ce_msg[11];
sec = bcd2bin(sec);
min = bcd2bin(min);
hour = bcd2bin(hour);
day = bcd2bin(day);
mon = bcd2bin(mon);
year = bcd2bin(year);
if (year <= 69)
year += 100;
tm->tm_sec = sec;
tm->tm_min = min;
tm->tm_hour = hour;
tm->tm_mday = day;
tm->tm_mon = mon;
tm->tm_year = year;
}
return 0;
}
static int mf_get_rtc(struct rtc_time *tm)
{
struct ce_msg_comp_data ce_complete;
struct rtc_time_data rtc_data;
int rc;
memset(&ce_complete, 0, sizeof(ce_complete));
memset(&rtc_data, 0, sizeof(rtc_data));
init_completion(&rtc_data.com);
ce_complete.handler = &get_rtc_time_complete;
ce_complete.token = &rtc_data;
rc = signal_ce_msg_simple(0x40, &ce_complete);
if (rc)
return rc;
wait_for_completion(&rtc_data.com);
return rtc_set_tm(rtc_data.rc, rtc_data.ce_msg.ce_msg, tm);
}
static void get_boot_rtc_time_complete(void *token, struct ce_msg_data *ce_msg)
{
struct boot_rtc_time_data *rtc = token;
memcpy(&rtc->ce_msg, ce_msg, sizeof(rtc->ce_msg));
rtc->rc = 0;
rtc->busy = 0;
}
static int mf_get_boot_rtc(struct rtc_time *tm)
{
struct ce_msg_comp_data ce_complete;
struct boot_rtc_time_data rtc_data;
int rc;
memset(&ce_complete, 0, sizeof(ce_complete));
memset(&rtc_data, 0, sizeof(rtc_data));
rtc_data.busy = 1;
ce_complete.handler = &get_boot_rtc_time_complete;
ce_complete.token = &rtc_data;
rc = signal_ce_msg_simple(0x40, &ce_complete);
if (rc)
return rc;
while (rtc_data.busy) {
if (hvlpevent_is_pending())
process_hvlpevents();
}
return rtc_set_tm(rtc_data.rc, rtc_data.ce_msg.ce_msg, tm);
}
static int mf_cmdline_proc_show(struct seq_file *m, void *v)
{
char *page, *p;
struct vsp_cmd_data vsp_cmd;
int rc;
dma_addr_t dma_addr;
page = kmalloc(256, GFP_KERNEL);
if (!page)
return -ENOMEM;
dma_addr = iseries_hv_map(page, 256, DMA_FROM_DEVICE);
if (dma_addr == DMA_ERROR_CODE) {
kfree(page);
return -ENOMEM;
}
memset(page, 0, 256);
memset(&vsp_cmd, 0, sizeof(vsp_cmd));
vsp_cmd.cmd = 33;
vsp_cmd.sub_data.kern.token = dma_addr;
vsp_cmd.sub_data.kern.address_type = HvLpDma_AddressType_TceIndex;
vsp_cmd.sub_data.kern.side = (u64)m->private;
vsp_cmd.sub_data.kern.length = 256;
mb();
rc = signal_vsp_instruction(&vsp_cmd);
iseries_hv_unmap(dma_addr, 256, DMA_FROM_DEVICE);
if (rc) {
kfree(page);
return rc;
}
if (vsp_cmd.result_code != 0) {
kfree(page);
return -ENOMEM;
}
p = page;
while (p - page < 256) {
if (*p == '\0' || *p == '\n') {
*p = '\n';
break;
}
p++;
}
seq_write(m, page, p - page);
kfree(page);
return 0;
}
static int mf_cmdline_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, mf_cmdline_proc_show, PDE(inode)->data);
}
static int mf_side_proc_show(struct seq_file *m, void *v)
{
char mf_current_side = ' ';
struct vsp_cmd_data vsp_cmd;
memset(&vsp_cmd, 0, sizeof(vsp_cmd));
vsp_cmd.cmd = 2;
vsp_cmd.sub_data.ipl_type = 0;
mb();
if (signal_vsp_instruction(&vsp_cmd) == 0) {
if (vsp_cmd.result_code == 0) {
switch (vsp_cmd.sub_data.ipl_type) {
case 0: mf_current_side = 'A';
break;
case 1: mf_current_side = 'B';
break;
case 2: mf_current_side = 'C';
break;
default: mf_current_side = 'D';
break;
}
}
}
seq_printf(m, "%c\n", mf_current_side);
return 0;
}
static int mf_side_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, mf_side_proc_show, NULL);
}
static ssize_t mf_side_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *pos)
{
char side;
u64 newSide;
struct vsp_cmd_data vsp_cmd;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
if (count == 0)
return 0;
if (get_user(side, buffer))
return -EFAULT;
switch (side) {
case 'A': newSide = 0;
break;
case 'B': newSide = 1;
break;
case 'C': newSide = 2;
break;
case 'D': newSide = 3;
break;
default:
printk(KERN_ERR "mf_proc.c: proc_mf_change_side: invalid side\n");
return -EINVAL;
}
memset(&vsp_cmd, 0, sizeof(vsp_cmd));
vsp_cmd.sub_data.ipl_type = newSide;
vsp_cmd.cmd = 10;
(void)signal_vsp_instruction(&vsp_cmd);
return count;
}
static int mf_src_proc_show(struct seq_file *m, void *v)
{
return 0;
}
static int mf_src_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, mf_src_proc_show, NULL);
}
static ssize_t mf_src_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *pos)
{
char stkbuf[10];
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
if ((count < 4) && (count != 1)) {
printk(KERN_ERR "mf_proc: invalid src\n");
return -EINVAL;
}
if (count > (sizeof(stkbuf) - 1))
count = sizeof(stkbuf) - 1;
if (copy_from_user(stkbuf, buffer, count))
return -EFAULT;
if ((count == 1) && (*stkbuf == '\0'))
mf_clear_src();
else
mf_display_src(*(u32 *)stkbuf);
return count;
}
static ssize_t mf_cmdline_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *pos)
{
void *data = PDE(file->f_path.dentry->d_inode)->data;
struct vsp_cmd_data vsp_cmd;
dma_addr_t dma_addr;
char *page;
int ret = -EACCES;
if (!capable(CAP_SYS_ADMIN))
goto out;
dma_addr = 0;
page = iseries_hv_alloc(count, &dma_addr, GFP_ATOMIC);
ret = -ENOMEM;
if (page == NULL)
goto out;
ret = -EFAULT;
if (copy_from_user(page, buffer, count))
goto out_free;
memset(&vsp_cmd, 0, sizeof(vsp_cmd));
vsp_cmd.cmd = 31;
vsp_cmd.sub_data.kern.token = dma_addr;
vsp_cmd.sub_data.kern.address_type = HvLpDma_AddressType_TceIndex;
vsp_cmd.sub_data.kern.side = (u64)data;
vsp_cmd.sub_data.kern.length = count;
mb();
(void)signal_vsp_instruction(&vsp_cmd);
ret = count;
out_free:
iseries_hv_free(count, page, dma_addr);
out:
return ret;
}
static ssize_t proc_mf_change_vmlinux(struct file *file,
const char __user *buf,
size_t count, loff_t *ppos)
{
struct proc_dir_entry *dp = PDE(file->f_path.dentry->d_inode);
ssize_t rc;
dma_addr_t dma_addr;
char *page;
struct vsp_cmd_data vsp_cmd;
rc = -EACCES;
if (!capable(CAP_SYS_ADMIN))
goto out;
dma_addr = 0;
page = iseries_hv_alloc(count, &dma_addr, GFP_ATOMIC);
rc = -ENOMEM;
if (page == NULL) {
printk(KERN_ERR "mf.c: couldn't allocate memory to set vmlinux chunk\n");
goto out;
}
rc = -EFAULT;
if (copy_from_user(page, buf, count))
goto out_free;
memset(&vsp_cmd, 0, sizeof(vsp_cmd));
vsp_cmd.cmd = 30;
vsp_cmd.sub_data.kern.token = dma_addr;
vsp_cmd.sub_data.kern.address_type = HvLpDma_AddressType_TceIndex;
vsp_cmd.sub_data.kern.side = (u64)dp->data;
vsp_cmd.sub_data.kern.offset = *ppos;
vsp_cmd.sub_data.kern.length = count;
mb();
rc = signal_vsp_instruction(&vsp_cmd);
if (rc)
goto out_free;
rc = -ENOMEM;
if (vsp_cmd.result_code != 0)
goto out_free;
*ppos += count;
rc = count;
out_free:
iseries_hv_free(count, page, dma_addr);
out:
return rc;
}
static int __init mf_proc_init(void)
{
struct proc_dir_entry *mf_proc_root;
struct proc_dir_entry *ent;
struct proc_dir_entry *mf;
char name[2];
int i;
if (!firmware_has_feature(FW_FEATURE_ISERIES))
return 0;
mf_proc_root = proc_mkdir("iSeries/mf", NULL);
if (!mf_proc_root)
return 1;
name[1] = '\0';
for (i = 0; i < 4; i++) {
name[0] = 'A' + i;
mf = proc_mkdir(name, mf_proc_root);
if (!mf)
return 1;
ent = proc_create_data("cmdline", S_IRUSR|S_IWUSR, mf,
&mf_cmdline_proc_fops, (void *)(long)i);
if (!ent)
return 1;
if (i == 3)
continue;
ent = proc_create_data("vmlinux", S_IFREG|S_IWUSR, mf,
&proc_vmlinux_operations,
(void *)(long)i);
if (!ent)
return 1;
}
ent = proc_create("side", S_IFREG|S_IRUSR|S_IWUSR, mf_proc_root,
&mf_side_proc_fops);
if (!ent)
return 1;
ent = proc_create("src", S_IFREG|S_IRUSR|S_IWUSR, mf_proc_root,
&mf_src_proc_fops);
if (!ent)
return 1;
return 0;
}
void iSeries_get_rtc_time(struct rtc_time *rtc_tm)
{
mf_get_rtc(rtc_tm);
rtc_tm->tm_mon--;
}
int iSeries_set_rtc_time(struct rtc_time *tm)
{
mf_set_rtc(tm);
return 0;
}
unsigned long iSeries_get_boot_time(void)
{
struct rtc_time tm;
mf_get_boot_rtc(&tm);
return mktime(tm.tm_year + 1900, tm.tm_mon, tm.tm_mday,
tm.tm_hour, tm.tm_min, tm.tm_sec);
}
