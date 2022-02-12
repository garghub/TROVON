static int l3_handle_target(struct omap_l3 *l3, void __iomem *base,
struct l3_flagmux_data *flag_mux, int err_src)
{
int k;
u32 std_err_main, clear, masterid;
u8 op_code, m_req_info;
void __iomem *l3_targ_base;
void __iomem *l3_targ_stderr, *l3_targ_slvofslsb, *l3_targ_mstaddr;
void __iomem *l3_targ_hdr, *l3_targ_info;
struct l3_target_data *l3_targ_inst;
struct l3_masters_data *master;
char *target_name, *master_name = "UN IDENTIFIED";
char *err_description;
char err_string[30] = { 0 };
char info_string[60] = { 0 };
BUG_ON(err_src > MAX_CLKDM_TARGETS);
if (err_src < flag_mux->num_targ_data) {
l3_targ_inst = &flag_mux->l3_targ[err_src];
target_name = l3_targ_inst->name;
l3_targ_base = base + l3_targ_inst->offset;
} else {
target_name = L3_TARGET_NOT_SUPPORTED;
}
if (target_name == L3_TARGET_NOT_SUPPORTED)
return -ENODEV;
l3_targ_stderr = l3_targ_base + L3_TARG_STDERRLOG_MAIN;
l3_targ_slvofslsb = l3_targ_base + L3_TARG_STDERRLOG_SLVOFSLSB;
std_err_main = readl_relaxed(l3_targ_stderr);
switch (std_err_main & CUSTOM_ERROR) {
case STANDARD_ERROR:
err_description = "Standard";
snprintf(err_string, sizeof(err_string),
": At Address: 0x%08X ",
readl_relaxed(l3_targ_slvofslsb));
l3_targ_mstaddr = l3_targ_base + L3_TARG_STDERRLOG_MSTADDR;
l3_targ_hdr = l3_targ_base + L3_TARG_STDERRLOG_HDR;
l3_targ_info = l3_targ_base + L3_TARG_STDERRLOG_INFO;
break;
case CUSTOM_ERROR:
err_description = "Custom";
l3_targ_mstaddr = l3_targ_base +
L3_TARG_STDERRLOG_CINFO_MSTADDR;
l3_targ_hdr = l3_targ_base + L3_TARG_STDERRLOG_CINFO_OPCODE;
l3_targ_info = l3_targ_base + L3_TARG_STDERRLOG_CINFO_INFO;
break;
default:
return 0;
}
masterid = (readl_relaxed(l3_targ_mstaddr) &
l3->mst_addr_mask) >> __ffs(l3->mst_addr_mask);
for (k = 0, master = l3->l3_masters; k < l3->num_masters;
k++, master++) {
if (masterid == master->id) {
master_name = master->name;
break;
}
}
op_code = readl_relaxed(l3_targ_hdr) & 0x7;
m_req_info = readl_relaxed(l3_targ_info) & 0xF;
snprintf(info_string, sizeof(info_string),
": %s in %s mode during %s access",
(m_req_info & BIT(0)) ? "Opcode Fetch" : "Data Access",
(m_req_info & BIT(1)) ? "Supervisor" : "User",
(m_req_info & BIT(3)) ? "Debug" : "Functional");
WARN(true,
"%s:L3 %s Error: MASTER %s TARGET %s (%s)%s%s\n",
dev_name(l3->dev),
err_description,
master_name, target_name,
l3_transaction_type[op_code],
err_string, info_string);
clear = std_err_main | CLEAR_STDERR_LOG;
writel_relaxed(clear, l3_targ_stderr);
return 0;
}
static irqreturn_t l3_interrupt_handler(int irq, void *_l3)
{
struct omap_l3 *l3 = _l3;
int inttype, i, ret;
int err_src = 0;
u32 err_reg, mask_val;
void __iomem *base, *mask_reg;
struct l3_flagmux_data *flag_mux;
inttype = irq == l3->app_irq ? L3_APPLICATION_ERROR : L3_DEBUG_ERROR;
for (i = 0; i < l3->num_modules; i++) {
base = l3->l3_base[i];
flag_mux = l3->l3_flagmux[i];
err_reg = readl_relaxed(base + flag_mux->offset +
L3_FLAGMUX_REGERR0 + (inttype << 3));
err_reg &= ~(inttype ? flag_mux->mask_app_bits :
flag_mux->mask_dbg_bits);
if (err_reg) {
err_src = __ffs(err_reg);
ret = l3_handle_target(l3, base, flag_mux, err_src);
if (ret) {
dev_err(l3->dev,
"L3 %s error: target %d mod:%d %s\n",
inttype ? "debug" : "application",
err_src, i, "(unclearable)");
mask_reg = base + flag_mux->offset +
L3_FLAGMUX_MASK0 + (inttype << 3);
mask_val = readl_relaxed(mask_reg);
mask_val &= ~(1 << err_src);
writel_relaxed(mask_val, mask_reg);
if (inttype)
flag_mux->mask_app_bits |= 1 << err_src;
else
flag_mux->mask_dbg_bits |= 1 << err_src;
}
return IRQ_HANDLED;
}
}
dev_err(l3->dev, "L3 %s IRQ not handled!!\n",
inttype ? "debug" : "application");
return IRQ_NONE;
}
static int omap_l3_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id;
static struct omap_l3 *l3;
int ret, i, res_idx;
of_id = of_match_device(l3_noc_match, &pdev->dev);
if (!of_id) {
dev_err(&pdev->dev, "OF data missing\n");
return -EINVAL;
}
l3 = devm_kzalloc(&pdev->dev, sizeof(*l3), GFP_KERNEL);
if (!l3)
return -ENOMEM;
memcpy(l3, of_id->data, sizeof(*l3));
l3->dev = &pdev->dev;
platform_set_drvdata(pdev, l3);
for (i = 0, res_idx = 0; i < l3->num_modules; i++) {
struct resource *res;
if (l3->l3_base[i] == L3_BASE_IS_SUBMODULE) {
BUG_ON(i == 0);
l3->l3_base[i] = l3->l3_base[i - 1];
continue;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, res_idx);
l3->l3_base[i] = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(l3->l3_base[i])) {
dev_err(l3->dev, "ioremap %d failed\n", i);
return PTR_ERR(l3->l3_base[i]);
}
res_idx++;
}
l3->debug_irq = platform_get_irq(pdev, 0);
ret = devm_request_irq(l3->dev, l3->debug_irq, l3_interrupt_handler,
IRQF_DISABLED, "l3-dbg-irq", l3);
if (ret) {
dev_err(l3->dev, "request_irq failed for %d\n",
l3->debug_irq);
return ret;
}
l3->app_irq = platform_get_irq(pdev, 1);
ret = devm_request_irq(l3->dev, l3->app_irq, l3_interrupt_handler,
IRQF_DISABLED, "l3-app-irq", l3);
if (ret)
dev_err(l3->dev, "request_irq failed for %d\n", l3->app_irq);
return ret;
}
static int l3_resume_noirq(struct device *dev)
{
struct omap_l3 *l3 = dev_get_drvdata(dev);
int i;
struct l3_flagmux_data *flag_mux;
void __iomem *base, *mask_regx = NULL;
u32 mask_val;
for (i = 0; i < l3->num_modules; i++) {
base = l3->l3_base[i];
flag_mux = l3->l3_flagmux[i];
if (!flag_mux->mask_app_bits && !flag_mux->mask_dbg_bits)
continue;
mask_regx = base + flag_mux->offset + L3_FLAGMUX_MASK0 +
(L3_APPLICATION_ERROR << 3);
mask_val = readl_relaxed(mask_regx);
mask_val &= ~(flag_mux->mask_app_bits);
writel_relaxed(mask_val, mask_regx);
mask_regx = base + flag_mux->offset + L3_FLAGMUX_MASK0 +
(L3_DEBUG_ERROR << 3);
mask_val = readl_relaxed(mask_regx);
mask_val &= ~(flag_mux->mask_dbg_bits);
writel_relaxed(mask_val, mask_regx);
}
if (mask_regx)
(void)readl(mask_regx);
return 0;
}
static int __init omap_l3_init(void)
{
return platform_driver_register(&omap_l3_driver);
}
static void __exit omap_l3_exit(void)
{
platform_driver_unregister(&omap_l3_driver);
}
