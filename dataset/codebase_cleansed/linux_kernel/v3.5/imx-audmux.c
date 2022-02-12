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
if (!audmux_base)
return -ENOSYS;
if (audmux_clk)
clk_prepare_enable(audmux_clk);
ptcr = readl(audmux_base + IMX_AUDMUX_V2_PTCR(port));
pdcr = readl(audmux_base + IMX_AUDMUX_V2_PDCR(port));
if (audmux_clk)
clk_disable_unprepare(audmux_clk);
ret = snprintf(buf, PAGE_SIZE, "PDCR: %08x\nPTCR: %08x\n",
pdcr, ptcr);
if (ptcr & IMX_AUDMUX_V2_PTCR_TFSDIR)
ret += snprintf(buf + ret, PAGE_SIZE - ret,
"TxFS output from %s, ",
audmux_port_string((ptcr >> 27) & 0x7));
else
ret += snprintf(buf + ret, PAGE_SIZE - ret,
"TxFS input, ");
if (ptcr & IMX_AUDMUX_V2_PTCR_TCLKDIR)
ret += snprintf(buf + ret, PAGE_SIZE - ret,
"TxClk output from %s",
audmux_port_string((ptcr >> 22) & 0x7));
else
ret += snprintf(buf + ret, PAGE_SIZE - ret,
"TxClk input");
ret += snprintf(buf + ret, PAGE_SIZE - ret, "\n");
if (ptcr & IMX_AUDMUX_V2_PTCR_SYN) {
ret += snprintf(buf + ret, PAGE_SIZE - ret,
"Port is symmetric");
} else {
if (ptcr & IMX_AUDMUX_V2_PTCR_RFSDIR)
ret += snprintf(buf + ret, PAGE_SIZE - ret,
"RxFS output from %s, ",
audmux_port_string((ptcr >> 17) & 0x7));
else
ret += snprintf(buf + ret, PAGE_SIZE - ret,
"RxFS input, ");
if (ptcr & IMX_AUDMUX_V2_PTCR_RCLKDIR)
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
static void __init audmux_debugfs_init(void)
{
int i;
char buf[20];
audmux_debugfs_root = debugfs_create_dir("audmux", NULL);
if (!audmux_debugfs_root) {
pr_warning("Failed to create AUDMUX debugfs root\n");
return;
}
for (i = 0; i < MX31_AUDMUX_PORT6_SSI_PINS_6 + 1; i++) {
snprintf(buf, sizeof(buf), "ssi%d", i);
if (!debugfs_create_file(buf, 0444, audmux_debugfs_root,
(void *)i, &audmux_debugfs_fops))
pr_warning("Failed to create AUDMUX port %d debugfs file\n",
i);
}
}
static void __devexit audmux_debugfs_remove(void)
{
debugfs_remove_recursive(audmux_debugfs_root);
}
static inline void audmux_debugfs_init(void)
{
}
static inline void audmux_debugfs_remove(void)
{
}
int imx_audmux_v1_configure_port(unsigned int port, unsigned int pcr)
{
if (audmux_type != IMX21_AUDMUX)
return -EINVAL;
if (!audmux_base)
return -ENOSYS;
if (port >= ARRAY_SIZE(port_mapping))
return -EINVAL;
writel(pcr, audmux_base + port_mapping[port]);
return 0;
}
int imx_audmux_v2_configure_port(unsigned int port, unsigned int ptcr,
unsigned int pdcr)
{
if (audmux_type != IMX31_AUDMUX)
return -EINVAL;
if (!audmux_base)
return -ENOSYS;
if (audmux_clk)
clk_prepare_enable(audmux_clk);
writel(ptcr, audmux_base + IMX_AUDMUX_V2_PTCR(port));
writel(pdcr, audmux_base + IMX_AUDMUX_V2_PDCR(port));
if (audmux_clk)
clk_disable_unprepare(audmux_clk);
return 0;
}
static int __devinit imx_audmux_probe(struct platform_device *pdev)
{
struct resource *res;
struct pinctrl *pinctrl;
const struct of_device_id *of_id =
of_match_device(imx_audmux_dt_ids, &pdev->dev);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
audmux_base = devm_request_and_ioremap(&pdev->dev, res);
if (!audmux_base)
return -EADDRNOTAVAIL;
pinctrl = devm_pinctrl_get_select_default(&pdev->dev);
if (IS_ERR(pinctrl)) {
dev_err(&pdev->dev, "setup pinctrl failed!");
return PTR_ERR(pinctrl);
}
audmux_clk = clk_get(&pdev->dev, "audmux");
if (IS_ERR(audmux_clk)) {
dev_dbg(&pdev->dev, "cannot get clock: %ld\n",
PTR_ERR(audmux_clk));
audmux_clk = NULL;
}
if (of_id)
pdev->id_entry = of_id->data;
audmux_type = pdev->id_entry->driver_data;
if (audmux_type == IMX31_AUDMUX)
audmux_debugfs_init();
return 0;
}
static int __devexit imx_audmux_remove(struct platform_device *pdev)
{
if (audmux_type == IMX31_AUDMUX)
audmux_debugfs_remove();
clk_put(audmux_clk);
return 0;
}
static int __init imx_audmux_init(void)
{
return platform_driver_register(&imx_audmux_driver);
}
static void __exit imx_audmux_exit(void)
{
platform_driver_unregister(&imx_audmux_driver);
}
