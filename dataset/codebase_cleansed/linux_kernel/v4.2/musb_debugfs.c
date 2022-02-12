static int musb_regdump_show(struct seq_file *s, void *unused)
{
struct musb *musb = s->private;
unsigned i;
seq_printf(s, "MUSB (M)HDRC Register Dump\n");
for (i = 0; i < ARRAY_SIZE(musb_regmap); i++) {
switch (musb_regmap[i].size) {
case 8:
seq_printf(s, "%-12s: %02x\n", musb_regmap[i].name,
musb_readb(musb->mregs, musb_regmap[i].offset));
break;
case 16:
seq_printf(s, "%-12s: %04x\n", musb_regmap[i].name,
musb_readw(musb->mregs, musb_regmap[i].offset));
break;
case 32:
seq_printf(s, "%-12s: %08x\n", musb_regmap[i].name,
musb_readl(musb->mregs, musb_regmap[i].offset));
break;
}
}
return 0;
}
static int musb_regdump_open(struct inode *inode, struct file *file)
{
return single_open(file, musb_regdump_show, inode->i_private);
}
static int musb_test_mode_show(struct seq_file *s, void *unused)
{
struct musb *musb = s->private;
unsigned test;
test = musb_readb(musb->mregs, MUSB_TESTMODE);
if (test & MUSB_TEST_FORCE_HOST)
seq_printf(s, "force host\n");
if (test & MUSB_TEST_FIFO_ACCESS)
seq_printf(s, "fifo access\n");
if (test & MUSB_TEST_FORCE_FS)
seq_printf(s, "force full-speed\n");
if (test & MUSB_TEST_FORCE_HS)
seq_printf(s, "force high-speed\n");
if (test & MUSB_TEST_PACKET)
seq_printf(s, "test packet\n");
if (test & MUSB_TEST_K)
seq_printf(s, "test K\n");
if (test & MUSB_TEST_J)
seq_printf(s, "test J\n");
if (test & MUSB_TEST_SE0_NAK)
seq_printf(s, "test SE0 NAK\n");
return 0;
}
static int musb_test_mode_open(struct inode *inode, struct file *file)
{
return single_open(file, musb_test_mode_show, inode->i_private);
}
static ssize_t musb_test_mode_write(struct file *file,
const char __user *ubuf, size_t count, loff_t *ppos)
{
struct seq_file *s = file->private_data;
struct musb *musb = s->private;
u8 test;
char buf[18];
test = musb_readb(musb->mregs, MUSB_TESTMODE);
if (test) {
dev_err(musb->controller, "Error: test mode is already set. "
"Please do USB Bus Reset to start a new test.\n");
return count;
}
memset(buf, 0x00, sizeof(buf));
if (copy_from_user(buf, ubuf, min_t(size_t, sizeof(buf) - 1, count)))
return -EFAULT;
if (strstarts(buf, "force host"))
test = MUSB_TEST_FORCE_HOST;
if (strstarts(buf, "fifo access"))
test = MUSB_TEST_FIFO_ACCESS;
if (strstarts(buf, "force full-speed"))
test = MUSB_TEST_FORCE_FS;
if (strstarts(buf, "force high-speed"))
test = MUSB_TEST_FORCE_HS;
if (strstarts(buf, "test packet")) {
test = MUSB_TEST_PACKET;
musb_load_testpacket(musb);
}
if (strstarts(buf, "test K"))
test = MUSB_TEST_K;
if (strstarts(buf, "test J"))
test = MUSB_TEST_J;
if (strstarts(buf, "test SE0 NAK"))
test = MUSB_TEST_SE0_NAK;
musb_writeb(musb->mregs, MUSB_TESTMODE, test);
return count;
}
static int musb_softconnect_show(struct seq_file *s, void *unused)
{
struct musb *musb = s->private;
u8 reg;
int connect;
switch (musb->xceiv->otg->state) {
case OTG_STATE_A_HOST:
case OTG_STATE_A_WAIT_BCON:
reg = musb_readb(musb->mregs, MUSB_DEVCTL);
connect = reg & MUSB_DEVCTL_SESSION ? 1 : 0;
break;
default:
connect = -1;
}
seq_printf(s, "%d\n", connect);
return 0;
}
static int musb_softconnect_open(struct inode *inode, struct file *file)
{
return single_open(file, musb_softconnect_show, inode->i_private);
}
static ssize_t musb_softconnect_write(struct file *file,
const char __user *ubuf, size_t count, loff_t *ppos)
{
struct seq_file *s = file->private_data;
struct musb *musb = s->private;
char buf[2];
u8 reg;
memset(buf, 0x00, sizeof(buf));
if (copy_from_user(&buf, ubuf, min_t(size_t, sizeof(buf) - 1, count)))
return -EFAULT;
if (!strncmp(buf, "0", 1)) {
switch (musb->xceiv->otg->state) {
case OTG_STATE_A_HOST:
musb_root_disconnect(musb);
reg = musb_readb(musb->mregs, MUSB_DEVCTL);
reg &= ~MUSB_DEVCTL_SESSION;
musb_writeb(musb->mregs, MUSB_DEVCTL, reg);
break;
default:
break;
}
} else if (!strncmp(buf, "1", 1)) {
switch (musb->xceiv->otg->state) {
case OTG_STATE_A_WAIT_BCON:
musb->context.devctl |= MUSB_DEVCTL_SESSION;
reg = musb_readb(musb->mregs, MUSB_DEVCTL);
reg |= MUSB_DEVCTL_SESSION;
musb_writeb(musb->mregs, MUSB_DEVCTL, reg);
break;
default:
break;
}
}
return count;
}
int musb_init_debugfs(struct musb *musb)
{
struct dentry *root;
struct dentry *file;
int ret;
root = debugfs_create_dir(dev_name(musb->controller), NULL);
if (!root) {
ret = -ENOMEM;
goto err0;
}
file = debugfs_create_file("regdump", S_IRUGO, root, musb,
&musb_regdump_fops);
if (!file) {
ret = -ENOMEM;
goto err1;
}
file = debugfs_create_file("testmode", S_IRUGO | S_IWUSR,
root, musb, &musb_test_mode_fops);
if (!file) {
ret = -ENOMEM;
goto err1;
}
file = debugfs_create_file("softconnect", S_IRUGO | S_IWUSR,
root, musb, &musb_softconnect_fops);
if (!file) {
ret = -ENOMEM;
goto err1;
}
musb->debugfs_root = root;
return 0;
err1:
debugfs_remove_recursive(root);
err0:
return ret;
}
void musb_exit_debugfs(struct musb *musb)
{
debugfs_remove_recursive(musb->debugfs_root);
}
