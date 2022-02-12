static int q6v5_regulator_init(struct q6v5 *qproc)
{
int ret;
qproc->supply[Q6V5_SUPPLY_CX].supply = "cx";
qproc->supply[Q6V5_SUPPLY_MX].supply = "mx";
qproc->supply[Q6V5_SUPPLY_MSS].supply = "mss";
qproc->supply[Q6V5_SUPPLY_PLL].supply = "pll";
ret = devm_regulator_bulk_get(qproc->dev,
ARRAY_SIZE(qproc->supply), qproc->supply);
if (ret < 0) {
dev_err(qproc->dev, "failed to get supplies\n");
return ret;
}
regulator_set_load(qproc->supply[Q6V5_SUPPLY_CX].consumer, 100000);
regulator_set_load(qproc->supply[Q6V5_SUPPLY_MSS].consumer, 100000);
regulator_set_load(qproc->supply[Q6V5_SUPPLY_PLL].consumer, 10000);
return 0;
}
static int q6v5_regulator_enable(struct q6v5 *qproc)
{
struct regulator *mss = qproc->supply[Q6V5_SUPPLY_MSS].consumer;
struct regulator *mx = qproc->supply[Q6V5_SUPPLY_MX].consumer;
int ret;
ret = regulator_set_voltage(mx, 1050000, INT_MAX);
if (ret)
return ret;
regulator_set_voltage(mss, 1000000, 1150000);
return regulator_bulk_enable(ARRAY_SIZE(qproc->supply), qproc->supply);
}
static void q6v5_regulator_disable(struct q6v5 *qproc)
{
struct regulator *mss = qproc->supply[Q6V5_SUPPLY_MSS].consumer;
struct regulator *mx = qproc->supply[Q6V5_SUPPLY_MX].consumer;
regulator_bulk_disable(ARRAY_SIZE(qproc->supply), qproc->supply);
regulator_set_voltage(mx, 0, INT_MAX);
regulator_set_voltage(mss, 0, 1150000);
}
static int q6v5_load(struct rproc *rproc, const struct firmware *fw)
{
struct q6v5 *qproc = rproc->priv;
memcpy(qproc->mba_region, fw->data, fw->size);
return 0;
}
static int q6v5_rmb_pbl_wait(struct q6v5 *qproc, int ms)
{
unsigned long timeout;
s32 val;
timeout = jiffies + msecs_to_jiffies(ms);
for (;;) {
val = readl(qproc->rmb_base + RMB_PBL_STATUS_REG);
if (val)
break;
if (time_after(jiffies, timeout))
return -ETIMEDOUT;
msleep(1);
}
return val;
}
static int q6v5_rmb_mba_wait(struct q6v5 *qproc, u32 status, int ms)
{
unsigned long timeout;
s32 val;
timeout = jiffies + msecs_to_jiffies(ms);
for (;;) {
val = readl(qproc->rmb_base + RMB_MBA_STATUS_REG);
if (val < 0)
break;
if (!status && val)
break;
else if (status && val == status)
break;
if (time_after(jiffies, timeout))
return -ETIMEDOUT;
msleep(1);
}
return val;
}
static int q6v5proc_reset(struct q6v5 *qproc)
{
u32 val;
int ret;
val = readl(qproc->reg_base + QDSP6SS_RESET_REG);
val |= (Q6SS_CORE_ARES | Q6SS_BUS_ARES_ENABLE | Q6SS_STOP_CORE);
writel(val, qproc->reg_base + QDSP6SS_RESET_REG);
val = readl(qproc->reg_base + QDSP6SS_PWR_CTL_REG);
val |= QDSS_BHS_ON | QDSS_LDO_BYP;
writel(val, qproc->reg_base + QDSP6SS_PWR_CTL_REG);
udelay(1);
val = readl(qproc->reg_base + QDSP6SS_PWR_CTL_REG);
val |= Q6SS_SLP_RET_N | Q6SS_L2TAG_SLP_NRET_N |
Q6SS_ETB_SLP_NRET_N | Q6SS_L2DATA_STBY_N;
writel(val, qproc->reg_base + QDSP6SS_PWR_CTL_REG);
val |= Q6SS_L2DATA_SLP_NRET_N_2;
writel(val, qproc->reg_base + QDSP6SS_PWR_CTL_REG);
val |= Q6SS_L2DATA_SLP_NRET_N_1;
writel(val, qproc->reg_base + QDSP6SS_PWR_CTL_REG);
val |= Q6SS_L2DATA_SLP_NRET_N_0;
writel(val, qproc->reg_base + QDSP6SS_PWR_CTL_REG);
val &= ~Q6SS_CLAMP_IO;
writel(val, qproc->reg_base + QDSP6SS_PWR_CTL_REG);
val = readl(qproc->reg_base + QDSP6SS_RESET_REG);
val &= ~Q6SS_CORE_ARES;
writel(val, qproc->reg_base + QDSP6SS_RESET_REG);
val = readl(qproc->reg_base + QDSP6SS_GFMUX_CTL_REG);
val |= Q6SS_CLK_ENABLE;
writel(val, qproc->reg_base + QDSP6SS_GFMUX_CTL_REG);
val = readl(qproc->reg_base + QDSP6SS_RESET_REG);
val &= ~Q6SS_STOP_CORE;
writel(val, qproc->reg_base + QDSP6SS_RESET_REG);
ret = q6v5_rmb_pbl_wait(qproc, 1000);
if (ret == -ETIMEDOUT) {
dev_err(qproc->dev, "PBL boot timed out\n");
} else if (ret != RMB_PBL_SUCCESS) {
dev_err(qproc->dev, "PBL returned unexpected status %d\n", ret);
ret = -EINVAL;
} else {
ret = 0;
}
return ret;
}
static void q6v5proc_halt_axi_port(struct q6v5 *qproc,
struct regmap *halt_map,
u32 offset)
{
unsigned long timeout;
unsigned int val;
int ret;
ret = regmap_read(halt_map, offset + AXI_IDLE_REG, &val);
if (!ret && val)
return;
regmap_write(halt_map, offset + AXI_HALTREQ_REG, 1);
timeout = jiffies + msecs_to_jiffies(HALT_ACK_TIMEOUT_MS);
for (;;) {
ret = regmap_read(halt_map, offset + AXI_HALTACK_REG, &val);
if (ret || val || time_after(jiffies, timeout))
break;
msleep(1);
}
ret = regmap_read(halt_map, offset + AXI_IDLE_REG, &val);
if (ret || !val)
dev_err(qproc->dev, "port failed halt\n");
regmap_write(halt_map, offset + AXI_HALTREQ_REG, 0);
}
static int q6v5_mpss_init_image(struct q6v5 *qproc, const struct firmware *fw)
{
unsigned long dma_attrs = DMA_ATTR_FORCE_CONTIGUOUS;
dma_addr_t phys;
void *ptr;
int ret;
ptr = dma_alloc_attrs(qproc->dev, fw->size, &phys, GFP_KERNEL, dma_attrs);
if (!ptr) {
dev_err(qproc->dev, "failed to allocate mdt buffer\n");
return -ENOMEM;
}
memcpy(ptr, fw->data, fw->size);
writel(phys, qproc->rmb_base + RMB_PMI_META_DATA_REG);
writel(RMB_CMD_META_DATA_READY, qproc->rmb_base + RMB_MBA_COMMAND_REG);
ret = q6v5_rmb_mba_wait(qproc, RMB_MBA_META_DATA_AUTH_SUCCESS, 1000);
if (ret == -ETIMEDOUT)
dev_err(qproc->dev, "MPSS header authentication timed out\n");
else if (ret < 0)
dev_err(qproc->dev, "MPSS header authentication failed: %d\n", ret);
dma_free_attrs(qproc->dev, fw->size, ptr, phys, dma_attrs);
return ret < 0 ? ret : 0;
}
static int q6v5_mpss_validate(struct q6v5 *qproc, const struct firmware *fw)
{
const struct elf32_phdr *phdrs;
const struct elf32_phdr *phdr;
struct elf32_hdr *ehdr;
phys_addr_t boot_addr;
phys_addr_t fw_addr;
bool relocate;
size_t size;
int ret;
int i;
ret = qcom_mdt_parse(fw, &fw_addr, NULL, &relocate);
if (ret) {
dev_err(qproc->dev, "failed to parse mdt header\n");
return ret;
}
if (relocate)
boot_addr = qproc->mpss_phys;
else
boot_addr = fw_addr;
ehdr = (struct elf32_hdr *)fw->data;
phdrs = (struct elf32_phdr *)(ehdr + 1);
for (i = 0; i < ehdr->e_phnum; i++, phdr++) {
phdr = &phdrs[i];
if (phdr->p_type != PT_LOAD)
continue;
if ((phdr->p_flags & QCOM_MDT_TYPE_MASK) == QCOM_MDT_TYPE_HASH)
continue;
if (!phdr->p_memsz)
continue;
size = readl(qproc->rmb_base + RMB_PMI_CODE_LENGTH_REG);
if (!size) {
writel(boot_addr, qproc->rmb_base + RMB_PMI_CODE_START_REG);
writel(RMB_CMD_LOAD_READY, qproc->rmb_base + RMB_MBA_COMMAND_REG);
}
size += phdr->p_memsz;
writel(size, qproc->rmb_base + RMB_PMI_CODE_LENGTH_REG);
}
ret = q6v5_rmb_mba_wait(qproc, RMB_MBA_AUTH_COMPLETE, 10000);
if (ret == -ETIMEDOUT)
dev_err(qproc->dev, "MPSS authentication timed out\n");
else if (ret < 0)
dev_err(qproc->dev, "MPSS authentication failed: %d\n", ret);
return ret < 0 ? ret : 0;
}
static int q6v5_mpss_load(struct q6v5 *qproc)
{
const struct firmware *fw;
phys_addr_t fw_addr;
bool relocate;
int ret;
ret = request_firmware(&fw, MPSS_FIRMWARE_NAME, qproc->dev);
if (ret < 0) {
dev_err(qproc->dev, "unable to load " MPSS_FIRMWARE_NAME "\n");
return ret;
}
ret = qcom_mdt_parse(fw, &fw_addr, NULL, &relocate);
if (ret) {
dev_err(qproc->dev, "failed to parse mdt header\n");
goto release_firmware;
}
if (relocate)
qproc->mpss_reloc = fw_addr;
writel(0, qproc->rmb_base + RMB_PMI_CODE_LENGTH_REG);
ret = q6v5_mpss_init_image(qproc, fw);
if (ret)
goto release_firmware;
ret = qcom_mdt_load(qproc->rproc, fw, MPSS_FIRMWARE_NAME);
if (ret)
goto release_firmware;
ret = q6v5_mpss_validate(qproc, fw);
release_firmware:
release_firmware(fw);
return ret < 0 ? ret : 0;
}
static int q6v5_start(struct rproc *rproc)
{
struct q6v5 *qproc = (struct q6v5 *)rproc->priv;
int ret;
ret = q6v5_regulator_enable(qproc);
if (ret) {
dev_err(qproc->dev, "failed to enable supplies\n");
return ret;
}
ret = reset_control_deassert(qproc->mss_restart);
if (ret) {
dev_err(qproc->dev, "failed to deassert mss restart\n");
goto disable_vdd;
}
ret = clk_prepare_enable(qproc->ahb_clk);
if (ret)
goto assert_reset;
ret = clk_prepare_enable(qproc->axi_clk);
if (ret)
goto disable_ahb_clk;
ret = clk_prepare_enable(qproc->rom_clk);
if (ret)
goto disable_axi_clk;
writel(qproc->mba_phys, qproc->rmb_base + RMB_MBA_IMAGE_REG);
ret = q6v5proc_reset(qproc);
if (ret)
goto halt_axi_ports;
ret = q6v5_rmb_mba_wait(qproc, 0, 5000);
if (ret == -ETIMEDOUT) {
dev_err(qproc->dev, "MBA boot timed out\n");
goto halt_axi_ports;
} else if (ret != RMB_MBA_XPU_UNLOCKED &&
ret != RMB_MBA_XPU_UNLOCKED_SCRIBBLED) {
dev_err(qproc->dev, "MBA returned unexpected status %d\n", ret);
ret = -EINVAL;
goto halt_axi_ports;
}
dev_info(qproc->dev, "MBA booted, loading mpss\n");
ret = q6v5_mpss_load(qproc);
if (ret)
goto halt_axi_ports;
ret = wait_for_completion_timeout(&qproc->start_done,
msecs_to_jiffies(5000));
if (ret == 0) {
dev_err(qproc->dev, "start timed out\n");
ret = -ETIMEDOUT;
goto halt_axi_ports;
}
qproc->running = true;
return 0;
halt_axi_ports:
q6v5proc_halt_axi_port(qproc, qproc->halt_map, qproc->halt_q6);
q6v5proc_halt_axi_port(qproc, qproc->halt_map, qproc->halt_modem);
q6v5proc_halt_axi_port(qproc, qproc->halt_map, qproc->halt_nc);
clk_disable_unprepare(qproc->rom_clk);
disable_axi_clk:
clk_disable_unprepare(qproc->axi_clk);
disable_ahb_clk:
clk_disable_unprepare(qproc->ahb_clk);
assert_reset:
reset_control_assert(qproc->mss_restart);
disable_vdd:
q6v5_regulator_disable(qproc);
return ret;
}
static int q6v5_stop(struct rproc *rproc)
{
struct q6v5 *qproc = (struct q6v5 *)rproc->priv;
int ret;
qproc->running = false;
qcom_smem_state_update_bits(qproc->state,
BIT(qproc->stop_bit), BIT(qproc->stop_bit));
ret = wait_for_completion_timeout(&qproc->stop_done,
msecs_to_jiffies(5000));
if (ret == 0)
dev_err(qproc->dev, "timed out on wait\n");
qcom_smem_state_update_bits(qproc->state, BIT(qproc->stop_bit), 0);
q6v5proc_halt_axi_port(qproc, qproc->halt_map, qproc->halt_q6);
q6v5proc_halt_axi_port(qproc, qproc->halt_map, qproc->halt_modem);
q6v5proc_halt_axi_port(qproc, qproc->halt_map, qproc->halt_nc);
reset_control_assert(qproc->mss_restart);
clk_disable_unprepare(qproc->rom_clk);
clk_disable_unprepare(qproc->axi_clk);
clk_disable_unprepare(qproc->ahb_clk);
q6v5_regulator_disable(qproc);
return 0;
}
static void *q6v5_da_to_va(struct rproc *rproc, u64 da, int len)
{
struct q6v5 *qproc = rproc->priv;
int offset;
offset = da - qproc->mpss_reloc;
if (offset < 0 || offset + len > qproc->mpss_size)
return NULL;
return qproc->mpss_region + offset;
}
static irqreturn_t q6v5_wdog_interrupt(int irq, void *dev)
{
struct q6v5 *qproc = dev;
size_t len;
char *msg;
if (!qproc->running) {
complete(&qproc->stop_done);
return IRQ_HANDLED;
}
msg = qcom_smem_get(QCOM_SMEM_HOST_ANY, MPSS_CRASH_REASON_SMEM, &len);
if (!IS_ERR(msg) && len > 0 && msg[0])
dev_err(qproc->dev, "watchdog received: %s\n", msg);
else
dev_err(qproc->dev, "watchdog without message\n");
rproc_report_crash(qproc->rproc, RPROC_WATCHDOG);
if (!IS_ERR(msg))
msg[0] = '\0';
return IRQ_HANDLED;
}
static irqreturn_t q6v5_fatal_interrupt(int irq, void *dev)
{
struct q6v5 *qproc = dev;
size_t len;
char *msg;
msg = qcom_smem_get(QCOM_SMEM_HOST_ANY, MPSS_CRASH_REASON_SMEM, &len);
if (!IS_ERR(msg) && len > 0 && msg[0])
dev_err(qproc->dev, "fatal error received: %s\n", msg);
else
dev_err(qproc->dev, "fatal error without message\n");
rproc_report_crash(qproc->rproc, RPROC_FATAL_ERROR);
if (!IS_ERR(msg))
msg[0] = '\0';
return IRQ_HANDLED;
}
static irqreturn_t q6v5_handover_interrupt(int irq, void *dev)
{
struct q6v5 *qproc = dev;
complete(&qproc->start_done);
return IRQ_HANDLED;
}
static irqreturn_t q6v5_stop_ack_interrupt(int irq, void *dev)
{
struct q6v5 *qproc = dev;
complete(&qproc->stop_done);
return IRQ_HANDLED;
}
static int q6v5_init_mem(struct q6v5 *qproc, struct platform_device *pdev)
{
struct of_phandle_args args;
struct resource *res;
int ret;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "qdsp6");
qproc->reg_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(qproc->reg_base))
return PTR_ERR(qproc->reg_base);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "rmb");
qproc->rmb_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(qproc->rmb_base))
return PTR_ERR(qproc->rmb_base);
ret = of_parse_phandle_with_fixed_args(pdev->dev.of_node,
"qcom,halt-regs", 3, 0, &args);
if (ret < 0) {
dev_err(&pdev->dev, "failed to parse qcom,halt-regs\n");
return -EINVAL;
}
qproc->halt_map = syscon_node_to_regmap(args.np);
of_node_put(args.np);
if (IS_ERR(qproc->halt_map))
return PTR_ERR(qproc->halt_map);
qproc->halt_q6 = args.args[0];
qproc->halt_modem = args.args[1];
qproc->halt_nc = args.args[2];
return 0;
}
static int q6v5_init_clocks(struct q6v5 *qproc)
{
qproc->ahb_clk = devm_clk_get(qproc->dev, "iface");
if (IS_ERR(qproc->ahb_clk)) {
dev_err(qproc->dev, "failed to get iface clock\n");
return PTR_ERR(qproc->ahb_clk);
}
qproc->axi_clk = devm_clk_get(qproc->dev, "bus");
if (IS_ERR(qproc->axi_clk)) {
dev_err(qproc->dev, "failed to get bus clock\n");
return PTR_ERR(qproc->axi_clk);
}
qproc->rom_clk = devm_clk_get(qproc->dev, "mem");
if (IS_ERR(qproc->rom_clk)) {
dev_err(qproc->dev, "failed to get mem clock\n");
return PTR_ERR(qproc->rom_clk);
}
return 0;
}
static int q6v5_init_reset(struct q6v5 *qproc)
{
qproc->mss_restart = devm_reset_control_get(qproc->dev, NULL);
if (IS_ERR(qproc->mss_restart)) {
dev_err(qproc->dev, "failed to acquire mss restart\n");
return PTR_ERR(qproc->mss_restart);
}
return 0;
}
static int q6v5_request_irq(struct q6v5 *qproc,
struct platform_device *pdev,
const char *name,
irq_handler_t thread_fn)
{
int ret;
ret = platform_get_irq_byname(pdev, name);
if (ret < 0) {
dev_err(&pdev->dev, "no %s IRQ defined\n", name);
return ret;
}
ret = devm_request_threaded_irq(&pdev->dev, ret,
NULL, thread_fn,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
"q6v5", qproc);
if (ret)
dev_err(&pdev->dev, "request %s IRQ failed\n", name);
return ret;
}
static int q6v5_alloc_memory_region(struct q6v5 *qproc)
{
struct device_node *child;
struct device_node *node;
struct resource r;
int ret;
child = of_get_child_by_name(qproc->dev->of_node, "mba");
node = of_parse_phandle(child, "memory-region", 0);
ret = of_address_to_resource(node, 0, &r);
if (ret) {
dev_err(qproc->dev, "unable to resolve mba region\n");
return ret;
}
qproc->mba_phys = r.start;
qproc->mba_size = resource_size(&r);
qproc->mba_region = devm_ioremap_wc(qproc->dev, qproc->mba_phys, qproc->mba_size);
if (!qproc->mba_region) {
dev_err(qproc->dev, "unable to map memory region: %pa+%zx\n",
&r.start, qproc->mba_size);
return -EBUSY;
}
child = of_get_child_by_name(qproc->dev->of_node, "mpss");
node = of_parse_phandle(child, "memory-region", 0);
ret = of_address_to_resource(node, 0, &r);
if (ret) {
dev_err(qproc->dev, "unable to resolve mpss region\n");
return ret;
}
qproc->mpss_phys = qproc->mpss_reloc = r.start;
qproc->mpss_size = resource_size(&r);
qproc->mpss_region = devm_ioremap_wc(qproc->dev, qproc->mpss_phys, qproc->mpss_size);
if (!qproc->mpss_region) {
dev_err(qproc->dev, "unable to map memory region: %pa+%zx\n",
&r.start, qproc->mpss_size);
return -EBUSY;
}
return 0;
}
static int q6v5_probe(struct platform_device *pdev)
{
struct q6v5 *qproc;
struct rproc *rproc;
int ret;
rproc = rproc_alloc(&pdev->dev, pdev->name, &q6v5_ops,
MBA_FIRMWARE_NAME, sizeof(*qproc));
if (!rproc) {
dev_err(&pdev->dev, "failed to allocate rproc\n");
return -ENOMEM;
}
rproc->fw_ops = &q6v5_fw_ops;
qproc = (struct q6v5 *)rproc->priv;
qproc->dev = &pdev->dev;
qproc->rproc = rproc;
platform_set_drvdata(pdev, qproc);
init_completion(&qproc->start_done);
init_completion(&qproc->stop_done);
ret = q6v5_init_mem(qproc, pdev);
if (ret)
goto free_rproc;
ret = q6v5_alloc_memory_region(qproc);
if (ret)
goto free_rproc;
ret = q6v5_init_clocks(qproc);
if (ret)
goto free_rproc;
ret = q6v5_regulator_init(qproc);
if (ret)
goto free_rproc;
ret = q6v5_init_reset(qproc);
if (ret)
goto free_rproc;
ret = q6v5_request_irq(qproc, pdev, "wdog", q6v5_wdog_interrupt);
if (ret < 0)
goto free_rproc;
ret = q6v5_request_irq(qproc, pdev, "fatal", q6v5_fatal_interrupt);
if (ret < 0)
goto free_rproc;
ret = q6v5_request_irq(qproc, pdev, "handover", q6v5_handover_interrupt);
if (ret < 0)
goto free_rproc;
ret = q6v5_request_irq(qproc, pdev, "stop-ack", q6v5_stop_ack_interrupt);
if (ret < 0)
goto free_rproc;
qproc->state = qcom_smem_state_get(&pdev->dev, "stop", &qproc->stop_bit);
if (IS_ERR(qproc->state)) {
ret = PTR_ERR(qproc->state);
goto free_rproc;
}
ret = rproc_add(rproc);
if (ret)
goto free_rproc;
return 0;
free_rproc:
rproc_free(rproc);
return ret;
}
static int q6v5_remove(struct platform_device *pdev)
{
struct q6v5 *qproc = platform_get_drvdata(pdev);
rproc_del(qproc->rproc);
rproc_free(qproc->rproc);
return 0;
}
