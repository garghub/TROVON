static int dwc3_mode_show(struct seq_file *s, void *unused)
{
struct dwc3 *dwc = s->private;
unsigned long flags;
u32 reg;
spin_lock_irqsave(&dwc->lock, flags);
reg = dwc3_readl(dwc->regs, DWC3_GCTL);
spin_unlock_irqrestore(&dwc->lock, flags);
switch (DWC3_GCTL_PRTCAP(reg)) {
case DWC3_GCTL_PRTCAP_HOST:
seq_printf(s, "host\n");
break;
case DWC3_GCTL_PRTCAP_DEVICE:
seq_printf(s, "device\n");
break;
case DWC3_GCTL_PRTCAP_OTG:
seq_printf(s, "OTG\n");
break;
default:
seq_printf(s, "UNKNOWN %08x\n", DWC3_GCTL_PRTCAP(reg));
}
return 0;
}
static int dwc3_mode_open(struct inode *inode, struct file *file)
{
return single_open(file, dwc3_mode_show, inode->i_private);
}
static ssize_t dwc3_mode_write(struct file *file,
const char __user *ubuf, size_t count, loff_t *ppos)
{
struct seq_file *s = file->private_data;
struct dwc3 *dwc = s->private;
unsigned long flags;
u32 mode = 0;
char buf[32];
if (copy_from_user(&buf, ubuf, min_t(size_t, sizeof(buf) - 1, count)))
return -EFAULT;
if (!strncmp(buf, "host", 4))
mode |= DWC3_GCTL_PRTCAP_HOST;
if (!strncmp(buf, "device", 6))
mode |= DWC3_GCTL_PRTCAP_DEVICE;
if (!strncmp(buf, "otg", 3))
mode |= DWC3_GCTL_PRTCAP_OTG;
if (mode) {
spin_lock_irqsave(&dwc->lock, flags);
dwc3_set_mode(dwc, mode);
spin_unlock_irqrestore(&dwc->lock, flags);
}
return count;
}
static int dwc3_testmode_show(struct seq_file *s, void *unused)
{
struct dwc3 *dwc = s->private;
unsigned long flags;
u32 reg;
spin_lock_irqsave(&dwc->lock, flags);
reg = dwc3_readl(dwc->regs, DWC3_DCTL);
reg &= DWC3_DCTL_TSTCTRL_MASK;
reg >>= 1;
spin_unlock_irqrestore(&dwc->lock, flags);
switch (reg) {
case 0:
seq_printf(s, "no test\n");
break;
case TEST_J:
seq_printf(s, "test_j\n");
break;
case TEST_K:
seq_printf(s, "test_k\n");
break;
case TEST_SE0_NAK:
seq_printf(s, "test_se0_nak\n");
break;
case TEST_PACKET:
seq_printf(s, "test_packet\n");
break;
case TEST_FORCE_EN:
seq_printf(s, "test_force_enable\n");
break;
default:
seq_printf(s, "UNKNOWN %d\n", reg);
}
return 0;
}
static int dwc3_testmode_open(struct inode *inode, struct file *file)
{
return single_open(file, dwc3_testmode_show, inode->i_private);
}
static ssize_t dwc3_testmode_write(struct file *file,
const char __user *ubuf, size_t count, loff_t *ppos)
{
struct seq_file *s = file->private_data;
struct dwc3 *dwc = s->private;
unsigned long flags;
u32 testmode = 0;
char buf[32];
if (copy_from_user(&buf, ubuf, min_t(size_t, sizeof(buf) - 1, count)))
return -EFAULT;
if (!strncmp(buf, "test_j", 6))
testmode = TEST_J;
else if (!strncmp(buf, "test_k", 6))
testmode = TEST_K;
else if (!strncmp(buf, "test_se0_nak", 12))
testmode = TEST_SE0_NAK;
else if (!strncmp(buf, "test_packet", 11))
testmode = TEST_PACKET;
else if (!strncmp(buf, "test_force_enable", 17))
testmode = TEST_FORCE_EN;
else
testmode = 0;
spin_lock_irqsave(&dwc->lock, flags);
dwc3_gadget_set_test_mode(dwc, testmode);
spin_unlock_irqrestore(&dwc->lock, flags);
return count;
}
static int dwc3_link_state_show(struct seq_file *s, void *unused)
{
struct dwc3 *dwc = s->private;
unsigned long flags;
enum dwc3_link_state state;
u32 reg;
spin_lock_irqsave(&dwc->lock, flags);
reg = dwc3_readl(dwc->regs, DWC3_DSTS);
state = DWC3_DSTS_USBLNKST(reg);
spin_unlock_irqrestore(&dwc->lock, flags);
switch (state) {
case DWC3_LINK_STATE_U0:
seq_printf(s, "U0\n");
break;
case DWC3_LINK_STATE_U1:
seq_printf(s, "U1\n");
break;
case DWC3_LINK_STATE_U2:
seq_printf(s, "U2\n");
break;
case DWC3_LINK_STATE_U3:
seq_printf(s, "U3\n");
break;
case DWC3_LINK_STATE_SS_DIS:
seq_printf(s, "SS.Disabled\n");
break;
case DWC3_LINK_STATE_RX_DET:
seq_printf(s, "Rx.Detect\n");
break;
case DWC3_LINK_STATE_SS_INACT:
seq_printf(s, "SS.Inactive\n");
break;
case DWC3_LINK_STATE_POLL:
seq_printf(s, "Poll\n");
break;
case DWC3_LINK_STATE_RECOV:
seq_printf(s, "Recovery\n");
break;
case DWC3_LINK_STATE_HRESET:
seq_printf(s, "HRESET\n");
break;
case DWC3_LINK_STATE_CMPLY:
seq_printf(s, "Compliance\n");
break;
case DWC3_LINK_STATE_LPBK:
seq_printf(s, "Loopback\n");
break;
case DWC3_LINK_STATE_RESET:
seq_printf(s, "Reset\n");
break;
case DWC3_LINK_STATE_RESUME:
seq_printf(s, "Resume\n");
break;
default:
seq_printf(s, "UNKNOWN %d\n", state);
}
return 0;
}
static int dwc3_link_state_open(struct inode *inode, struct file *file)
{
return single_open(file, dwc3_link_state_show, inode->i_private);
}
static ssize_t dwc3_link_state_write(struct file *file,
const char __user *ubuf, size_t count, loff_t *ppos)
{
struct seq_file *s = file->private_data;
struct dwc3 *dwc = s->private;
unsigned long flags;
enum dwc3_link_state state = 0;
char buf[32];
if (copy_from_user(&buf, ubuf, min_t(size_t, sizeof(buf) - 1, count)))
return -EFAULT;
if (!strncmp(buf, "SS.Disabled", 11))
state = DWC3_LINK_STATE_SS_DIS;
else if (!strncmp(buf, "Rx.Detect", 9))
state = DWC3_LINK_STATE_RX_DET;
else if (!strncmp(buf, "SS.Inactive", 11))
state = DWC3_LINK_STATE_SS_INACT;
else if (!strncmp(buf, "Recovery", 8))
state = DWC3_LINK_STATE_RECOV;
else if (!strncmp(buf, "Compliance", 10))
state = DWC3_LINK_STATE_CMPLY;
else if (!strncmp(buf, "Loopback", 8))
state = DWC3_LINK_STATE_LPBK;
else
return -EINVAL;
spin_lock_irqsave(&dwc->lock, flags);
dwc3_gadget_set_link_state(dwc, state);
spin_unlock_irqrestore(&dwc->lock, flags);
return count;
}
static int dwc3_tx_fifo_queue_show(struct seq_file *s, void *unused)
{
struct dwc3_ep *dep = s->private;
struct dwc3 *dwc = dep->dwc;
unsigned long flags;
u32 val;
spin_lock_irqsave(&dwc->lock, flags);
val = dwc3_core_fifo_space(dep, DWC3_TXFIFOQ);
seq_printf(s, "%u\n", val);
spin_unlock_irqrestore(&dwc->lock, flags);
return 0;
}
static int dwc3_rx_fifo_queue_show(struct seq_file *s, void *unused)
{
struct dwc3_ep *dep = s->private;
struct dwc3 *dwc = dep->dwc;
unsigned long flags;
u32 val;
spin_lock_irqsave(&dwc->lock, flags);
val = dwc3_core_fifo_space(dep, DWC3_RXFIFOQ);
seq_printf(s, "%u\n", val);
spin_unlock_irqrestore(&dwc->lock, flags);
return 0;
}
static int dwc3_tx_request_queue_show(struct seq_file *s, void *unused)
{
struct dwc3_ep *dep = s->private;
struct dwc3 *dwc = dep->dwc;
unsigned long flags;
u32 val;
spin_lock_irqsave(&dwc->lock, flags);
val = dwc3_core_fifo_space(dep, DWC3_TXREQQ);
seq_printf(s, "%u\n", val);
spin_unlock_irqrestore(&dwc->lock, flags);
return 0;
}
static int dwc3_rx_request_queue_show(struct seq_file *s, void *unused)
{
struct dwc3_ep *dep = s->private;
struct dwc3 *dwc = dep->dwc;
unsigned long flags;
u32 val;
spin_lock_irqsave(&dwc->lock, flags);
val = dwc3_core_fifo_space(dep, DWC3_RXREQQ);
seq_printf(s, "%u\n", val);
spin_unlock_irqrestore(&dwc->lock, flags);
return 0;
}
static int dwc3_rx_info_queue_show(struct seq_file *s, void *unused)
{
struct dwc3_ep *dep = s->private;
struct dwc3 *dwc = dep->dwc;
unsigned long flags;
u32 val;
spin_lock_irqsave(&dwc->lock, flags);
val = dwc3_core_fifo_space(dep, DWC3_RXINFOQ);
seq_printf(s, "%u\n", val);
spin_unlock_irqrestore(&dwc->lock, flags);
return 0;
}
static int dwc3_descriptor_fetch_queue_show(struct seq_file *s, void *unused)
{
struct dwc3_ep *dep = s->private;
struct dwc3 *dwc = dep->dwc;
unsigned long flags;
u32 val;
spin_lock_irqsave(&dwc->lock, flags);
val = dwc3_core_fifo_space(dep, DWC3_DESCFETCHQ);
seq_printf(s, "%u\n", val);
spin_unlock_irqrestore(&dwc->lock, flags);
return 0;
}
static int dwc3_event_queue_show(struct seq_file *s, void *unused)
{
struct dwc3_ep *dep = s->private;
struct dwc3 *dwc = dep->dwc;
unsigned long flags;
u32 val;
spin_lock_irqsave(&dwc->lock, flags);
val = dwc3_core_fifo_space(dep, DWC3_EVENTQ);
seq_printf(s, "%u\n", val);
spin_unlock_irqrestore(&dwc->lock, flags);
return 0;
}
static int dwc3_ep_transfer_type_show(struct seq_file *s, void *unused)
{
struct dwc3_ep *dep = s->private;
struct dwc3 *dwc = dep->dwc;
unsigned long flags;
spin_lock_irqsave(&dwc->lock, flags);
if (!(dep->flags & DWC3_EP_ENABLED) ||
!dep->endpoint.desc) {
seq_printf(s, "--\n");
goto out;
}
switch (usb_endpoint_type(dep->endpoint.desc)) {
case USB_ENDPOINT_XFER_CONTROL:
seq_printf(s, "control\n");
break;
case USB_ENDPOINT_XFER_ISOC:
seq_printf(s, "isochronous\n");
break;
case USB_ENDPOINT_XFER_BULK:
seq_printf(s, "bulk\n");
break;
case USB_ENDPOINT_XFER_INT:
seq_printf(s, "interrupt\n");
break;
default:
seq_printf(s, "--\n");
}
out:
spin_unlock_irqrestore(&dwc->lock, flags);
return 0;
}
static inline const char *dwc3_trb_type_string(struct dwc3_trb *trb)
{
switch (DWC3_TRBCTL_TYPE(trb->ctrl)) {
case DWC3_TRBCTL_NORMAL:
return "normal";
case DWC3_TRBCTL_CONTROL_SETUP:
return "control-setup";
case DWC3_TRBCTL_CONTROL_STATUS2:
return "control-status2";
case DWC3_TRBCTL_CONTROL_STATUS3:
return "control-status3";
case DWC3_TRBCTL_CONTROL_DATA:
return "control-data";
case DWC3_TRBCTL_ISOCHRONOUS_FIRST:
return "isoc-first";
case DWC3_TRBCTL_ISOCHRONOUS:
return "isoc";
case DWC3_TRBCTL_LINK_TRB:
return "link";
default:
return "UNKNOWN";
}
}
static int dwc3_ep_trb_ring_show(struct seq_file *s, void *unused)
{
struct dwc3_ep *dep = s->private;
struct dwc3 *dwc = dep->dwc;
unsigned long flags;
int i;
spin_lock_irqsave(&dwc->lock, flags);
if (dep->number <= 1) {
seq_printf(s, "--\n");
goto out;
}
seq_printf(s, "enqueue pointer %d\n", dep->trb_enqueue);
seq_printf(s, "dequeue pointer %d\n", dep->trb_dequeue);
seq_printf(s, "\n--------------------------------------------------\n\n");
seq_printf(s, "buffer_addr,size,type,ioc,isp_imi,csp,chn,lst,hwo\n");
for (i = 0; i < DWC3_TRB_NUM; i++) {
struct dwc3_trb *trb = &dep->trb_pool[i];
seq_printf(s, "%08x%08x,%d,%s,%d,%d,%d,%d,%d,%d\n",
trb->bph, trb->bpl, trb->size,
dwc3_trb_type_string(trb),
!!(trb->ctrl & DWC3_TRB_CTRL_IOC),
!!(trb->ctrl & DWC3_TRB_CTRL_ISP_IMI),
!!(trb->ctrl & DWC3_TRB_CTRL_CSP),
!!(trb->ctrl & DWC3_TRB_CTRL_CHN),
!!(trb->ctrl & DWC3_TRB_CTRL_LST),
!!(trb->ctrl & DWC3_TRB_CTRL_HWO));
}
out:
spin_unlock_irqrestore(&dwc->lock, flags);
return 0;
}
static int dwc3_endpoint_open(struct inode *inode, struct file *file)
{
const char *file_name = file_dentry(file)->d_iname;
struct dwc3_ep_file_map *f_map;
int i;
for (i = 0; i < ARRAY_SIZE(map); i++) {
f_map = &map[i];
if (strcmp(f_map->name, file_name) == 0)
break;
}
return single_open(file, f_map->show, inode->i_private);
}
static void dwc3_debugfs_create_endpoint_file(struct dwc3_ep *dep,
struct dentry *parent, int type)
{
struct dentry *file;
struct dwc3_ep_file_map *ep_file = &map[type];
file = debugfs_create_file(ep_file->name, S_IRUGO, parent, dep,
&dwc3_endpoint_fops);
}
static void dwc3_debugfs_create_endpoint_files(struct dwc3_ep *dep,
struct dentry *parent)
{
int i;
for (i = 0; i < ARRAY_SIZE(map); i++)
dwc3_debugfs_create_endpoint_file(dep, parent, i);
}
static void dwc3_debugfs_create_endpoint_dir(struct dwc3_ep *dep,
struct dentry *parent)
{
struct dentry *dir;
dir = debugfs_create_dir(dep->name, parent);
if (IS_ERR_OR_NULL(dir))
return;
dwc3_debugfs_create_endpoint_files(dep, dir);
}
static void dwc3_debugfs_create_endpoint_dirs(struct dwc3 *dwc,
struct dentry *parent)
{
int i;
for (i = 0; i < dwc->num_in_eps; i++) {
u8 epnum = (i << 1) | 1;
struct dwc3_ep *dep = dwc->eps[epnum];
if (!dep)
continue;
dwc3_debugfs_create_endpoint_dir(dep, parent);
}
for (i = 0; i < dwc->num_out_eps; i++) {
u8 epnum = (i << 1);
struct dwc3_ep *dep = dwc->eps[epnum];
if (!dep)
continue;
dwc3_debugfs_create_endpoint_dir(dep, parent);
}
}
void dwc3_debugfs_init(struct dwc3 *dwc)
{
struct dentry *root;
struct dentry *file;
root = debugfs_create_dir(dev_name(dwc->dev), NULL);
if (IS_ERR_OR_NULL(root)) {
if (!root)
dev_err(dwc->dev, "Can't create debugfs root\n");
return;
}
dwc->root = root;
dwc->regset = kzalloc(sizeof(*dwc->regset), GFP_KERNEL);
if (!dwc->regset) {
debugfs_remove_recursive(root);
return;
}
dwc->regset->regs = dwc3_regs;
dwc->regset->nregs = ARRAY_SIZE(dwc3_regs);
dwc->regset->base = dwc->regs - DWC3_GLOBALS_REGS_START;
file = debugfs_create_regset32("regdump", S_IRUGO, root, dwc->regset);
if (!file)
dev_dbg(dwc->dev, "Can't create debugfs regdump\n");
if (IS_ENABLED(CONFIG_USB_DWC3_DUAL_ROLE)) {
file = debugfs_create_file("mode", S_IRUGO | S_IWUSR, root,
dwc, &dwc3_mode_fops);
if (!file)
dev_dbg(dwc->dev, "Can't create debugfs mode\n");
}
if (IS_ENABLED(CONFIG_USB_DWC3_DUAL_ROLE) ||
IS_ENABLED(CONFIG_USB_DWC3_GADGET)) {
file = debugfs_create_file("testmode", S_IRUGO | S_IWUSR, root,
dwc, &dwc3_testmode_fops);
if (!file)
dev_dbg(dwc->dev, "Can't create debugfs testmode\n");
file = debugfs_create_file("link_state", S_IRUGO | S_IWUSR,
root, dwc, &dwc3_link_state_fops);
if (!file)
dev_dbg(dwc->dev, "Can't create debugfs link_state\n");
dwc3_debugfs_create_endpoint_dirs(dwc, root);
}
}
void dwc3_debugfs_exit(struct dwc3 *dwc)
{
debugfs_remove_recursive(dwc->root);
kfree(dwc->regset);
}
