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
if (audmux_clk) {
ret = clk_prepare_enable(audmux_clk);
if (ret)
return ret;
}
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
for (i = 0; i < MX31_AUDMUX_PORT7_SSI_PINS_7 + 1; i++) {
snprintf(buf, sizeof(buf), "ssi%d", i);
if (!debugfs_create_file(buf, 0444, audmux_debugfs_root,
(void *)i, &audmux_debugfs_fops))
pr_warning("Failed to create AUDMUX port %d debugfs file\n",
i);
}
}
static void audmux_debugfs_remove(void)
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
int ret;
if (audmux_type != IMX31_AUDMUX)
return -EINVAL;
if (!audmux_base)
return -ENOSYS;
if (audmux_clk) {
ret = clk_prepare_enable(audmux_clk);
if (ret)
return ret;
}
writel(ptcr, audmux_base + IMX_AUDMUX_V2_PTCR(port));
writel(pdcr, audmux_base + IMX_AUDMUX_V2_PDCR(port));
if (audmux_clk)
clk_disable_unprepare(audmux_clk);
return 0;
}
static int imx_audmux_parse_dt_defaults(struct platform_device *pdev,
struct device_node *of_node)
{
struct device_node *child;
for_each_available_child_of_node(of_node, child) {
unsigned int port;
unsigned int ptcr = 0;
unsigned int pdcr = 0;
unsigned int pcr = 0;
unsigned int val;
int ret;
int i = 0;
ret = of_property_read_u32(child, "fsl,audmux-port", &port);
if (ret) {
dev_warn(&pdev->dev, "Failed to get fsl,audmux-port of child node \"%s\"\n",
child->full_name);
continue;
}
if (!of_property_read_bool(child, "fsl,port-config")) {
dev_warn(&pdev->dev, "child node \"%s\" does not have property fsl,port-config\n",
child->full_name);
continue;
}
for (i = 0; (ret = of_property_read_u32_index(child,
"fsl,port-config", i, &val)) == 0;
++i) {
if (audmux_type == IMX31_AUDMUX) {
if (i % 2)
pdcr |= val;
else
ptcr |= val;
} else {
pcr |= val;
}
}
if (ret != -EOVERFLOW) {
dev_err(&pdev->dev, "Failed to read u32 at index %d of child %s\n",
i, child->full_name);
continue;
}
if (audmux_type == IMX31_AUDMUX) {
if (i % 2) {
dev_err(&pdev->dev, "One pdcr value is missing in child node %s\n",
child->full_name);
continue;
}
imx_audmux_v2_configure_port(port, ptcr, pdcr);
} else {
imx_audmux_v1_configure_port(port, pcr);
}
}
return 0;
}
static int imx_audmux_probe(struct platform_device *pdev)
{
struct resource *res;
const struct of_device_id *of_id =
of_match_device(imx_audmux_dt_ids, &pdev->dev);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
audmux_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(audmux_base))
return PTR_ERR(audmux_base);
audmux_clk = devm_clk_get(&pdev->dev, "audmux");
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
if (of_id)
imx_audmux_parse_dt_defaults(pdev, pdev->dev.of_node);
return 0;
}
static int imx_audmux_remove(struct platform_device *pdev)
{
if (audmux_type == IMX31_AUDMUX)
audmux_debugfs_remove();
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
