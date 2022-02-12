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
int dwc3_debugfs_init(struct dwc3 *dwc)
{
struct dentry *root;
struct dentry *file;
int ret;
root = debugfs_create_dir(dev_name(dwc->dev), NULL);
if (!root) {
ret = -ENOMEM;
goto err0;
}
dwc->root = root;
dwc->regset = kzalloc(sizeof(*dwc->regset), GFP_KERNEL);
if (!dwc->regset) {
ret = -ENOMEM;
goto err1;
}
dwc->regset->regs = dwc3_regs;
dwc->regset->nregs = ARRAY_SIZE(dwc3_regs);
dwc->regset->base = dwc->regs;
file = debugfs_create_regset32("regdump", S_IRUGO, root, dwc->regset);
if (!file) {
ret = -ENOMEM;
goto err1;
}
if (IS_ENABLED(CONFIG_USB_DWC3_DUAL_ROLE)) {
file = debugfs_create_file("mode", S_IRUGO | S_IWUSR, root,
dwc, &dwc3_mode_fops);
if (!file) {
ret = -ENOMEM;
goto err1;
}
}
if (IS_ENABLED(CONFIG_USB_DWC3_DUAL_ROLE) ||
IS_ENABLED(CONFIG_USB_DWC3_GADGET)) {
file = debugfs_create_file("testmode", S_IRUGO | S_IWUSR, root,
dwc, &dwc3_testmode_fops);
if (!file) {
ret = -ENOMEM;
goto err1;
}
file = debugfs_create_file("link_state", S_IRUGO | S_IWUSR, root,
dwc, &dwc3_link_state_fops);
if (!file) {
ret = -ENOMEM;
goto err1;
}
}
return 0;
err1:
debugfs_remove_recursive(root);
err0:
return ret;
}
void dwc3_debugfs_exit(struct dwc3 *dwc)
{
debugfs_remove_recursive(dwc->root);
dwc->root = NULL;
}
