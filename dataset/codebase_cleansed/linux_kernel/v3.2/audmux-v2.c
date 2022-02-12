static int audmux_open_file(struct inode *inode, struct file *file)
{
file->private_data = inode->i_private;
return 0;
}
static const char *audmux_port_string(int port)
{
switch (port) {
case MX31_AUDMUX_PORT1_SSI0:
return "imx-ssi.0";
case MX31_AUDMUX_PORT2_SSI1:
return "imx-ssi.1";
case MX31_AUDMUX_PORT3_SSI_PINS_3:
return "SSI3";
case MX31_AUDMUX_PORT4_SSI_PINS_4:
return "SSI4";
case MX31_AUDMUX_PORT5_SSI_PINS_5:
return "SSI5";
case MX31_AUDMUX_PORT6_SSI_PINS_6:
return "SSI6";
default:
return "UNKNOWN";
}
}
static ssize_t audmux_read_file(struct file *file, char __user *user_buf,
size_t count, loff_t *ppos)
{
ssize_t ret;
char *buf = kmalloc(PAGE_SIZE, GFP_KERNEL);
int port = (int)file->private_data;
u32 pdcr, ptcr;
if (!buf)
return -ENOMEM;
if (audmux_clk)
clk_enable(audmux_clk);
ptcr = readl(audmux_base + MXC_AUDMUX_V2_PTCR(port));
pdcr = readl(audmux_base + MXC_AUDMUX_V2_PDCR(port));
if (audmux_clk)
clk_disable(audmux_clk);
ret = snprintf(buf, PAGE_SIZE, "PDCR: %08x\nPTCR: %08x\n",
pdcr, ptcr);
if (ptcr & MXC_AUDMUX_V2_PTCR_TFSDIR)
ret += snprintf(buf + ret, PAGE_SIZE - ret,
"TxFS output from %s, ",
audmux_port_string((ptcr >> 27) & 0x7));
else
ret += snprintf(buf + ret, PAGE_SIZE - ret,
"TxFS input, ");
if (ptcr & MXC_AUDMUX_V2_PTCR_TCLKDIR)
ret += snprintf(buf + ret, PAGE_SIZE - ret,
"TxClk output from %s",
audmux_port_string((ptcr >> 22) & 0x7));
else
ret += snprintf(buf + ret, PAGE_SIZE - ret,
"TxClk input");
ret += snprintf(buf + ret, PAGE_SIZE - ret, "\n");
if (ptcr & MXC_AUDMUX_V2_PTCR_SYN) {
ret += snprintf(buf + ret, PAGE_SIZE - ret,
"Port is symmetric");
} else {
if (ptcr & MXC_AUDMUX_V2_PTCR_RFSDIR)
ret += snprintf(buf + ret, PAGE_SIZE - ret,
"RxFS output from %s, ",
audmux_port_string((ptcr >> 17) & 0x7));
else
ret += snprintf(buf + ret, PAGE_SIZE - ret,
"RxFS input, ");
if (ptcr & MXC_AUDMUX_V2_PTCR_RCLKDIR)
ret += snprintf(buf + ret, PAGE_SIZE - ret,
"RxClk output from %s",
audmux_port_string((ptcr >> 12) & 0x7));
else
ret += snprintf(buf + ret, PAGE_SIZE - ret,
"RxClk input");
}
ret += snprintf(buf + ret, PAGE_SIZE - ret,
"\nData received from %s\n",
audmux_port_string((pdcr >> 13) & 0x7));
ret = simple_read_from_buffer(user_buf, count, ppos, buf, ret);
kfree(buf);
return ret;
}
static void audmux_debugfs_init(void)
{
int i;
char buf[20];
audmux_debugfs_root = debugfs_create_dir("audmux", NULL);
if (!audmux_debugfs_root) {
pr_warning("Failed to create AUDMUX debugfs root\n");
return;
}
for (i = 1; i < 8; i++) {
snprintf(buf, sizeof(buf), "ssi%d", i);
if (!debugfs_create_file(buf, 0444, audmux_debugfs_root,
(void *)i, &audmux_debugfs_fops))
pr_warning("Failed to create AUDMUX port %d debugfs file\n",
i);
}
}
static inline void audmux_debugfs_init(void)
{
}
int mxc_audmux_v2_configure_port(unsigned int port, unsigned int ptcr,
unsigned int pdcr)
{
if (!audmux_base)
return -ENOSYS;
if (audmux_clk)
clk_enable(audmux_clk);
writel(ptcr, audmux_base + MXC_AUDMUX_V2_PTCR(port));
writel(pdcr, audmux_base + MXC_AUDMUX_V2_PDCR(port));
if (audmux_clk)
clk_disable(audmux_clk);
return 0;
}
static int mxc_audmux_v2_init(void)
{
int ret;
if (cpu_is_mx51()) {
audmux_base = MX51_IO_ADDRESS(MX51_AUDMUX_BASE_ADDR);
} else if (cpu_is_mx31()) {
audmux_base = MX31_IO_ADDRESS(MX31_AUDMUX_BASE_ADDR);
} else if (cpu_is_mx35()) {
audmux_clk = clk_get(NULL, "audmux");
if (IS_ERR(audmux_clk)) {
ret = PTR_ERR(audmux_clk);
printk(KERN_ERR "%s: cannot get clock: %d\n", __func__,
ret);
return ret;
}
audmux_base = MX35_IO_ADDRESS(MX35_AUDMUX_BASE_ADDR);
} else if (cpu_is_mx25()) {
audmux_clk = clk_get(NULL, "audmux");
if (IS_ERR(audmux_clk)) {
ret = PTR_ERR(audmux_clk);
printk(KERN_ERR "%s: cannot get clock: %d\n", __func__,
ret);
return ret;
}
audmux_base = MX25_IO_ADDRESS(MX25_AUDMUX_BASE_ADDR);
}
audmux_debugfs_init();
return 0;
}
