static int qcom_scm_clk_enable(void)
{
int ret;
ret = clk_prepare_enable(__scm->core_clk);
if (ret)
goto bail;
ret = clk_prepare_enable(__scm->iface_clk);
if (ret)
goto disable_core;
ret = clk_prepare_enable(__scm->bus_clk);
if (ret)
goto disable_iface;
return 0;
disable_iface:
clk_disable_unprepare(__scm->iface_clk);
disable_core:
clk_disable_unprepare(__scm->core_clk);
bail:
return ret;
}
static void qcom_scm_clk_disable(void)
{
clk_disable_unprepare(__scm->core_clk);
clk_disable_unprepare(__scm->iface_clk);
clk_disable_unprepare(__scm->bus_clk);
}
int qcom_scm_set_cold_boot_addr(void *entry, const cpumask_t *cpus)
{
return __qcom_scm_set_cold_boot_addr(entry, cpus);
}
int qcom_scm_set_warm_boot_addr(void *entry, const cpumask_t *cpus)
{
return __qcom_scm_set_warm_boot_addr(__scm->dev, entry, cpus);
}
void qcom_scm_cpu_power_down(u32 flags)
{
__qcom_scm_cpu_power_down(flags);
}
bool qcom_scm_hdcp_available(void)
{
int ret = qcom_scm_clk_enable();
if (ret)
return ret;
ret = __qcom_scm_is_call_available(__scm->dev, QCOM_SCM_SVC_HDCP,
QCOM_SCM_CMD_HDCP);
qcom_scm_clk_disable();
return ret > 0 ? true : false;
}
int qcom_scm_hdcp_req(struct qcom_scm_hdcp_req *req, u32 req_cnt, u32 *resp)
{
int ret = qcom_scm_clk_enable();
if (ret)
return ret;
ret = __qcom_scm_hdcp_req(__scm->dev, req, req_cnt, resp);
qcom_scm_clk_disable();
return ret;
}
bool qcom_scm_pas_supported(u32 peripheral)
{
int ret;
ret = __qcom_scm_is_call_available(__scm->dev, QCOM_SCM_SVC_PIL,
QCOM_SCM_PAS_IS_SUPPORTED_CMD);
if (ret <= 0)
return false;
return __qcom_scm_pas_supported(__scm->dev, peripheral);
}
int qcom_scm_pas_init_image(u32 peripheral, const void *metadata, size_t size)
{
dma_addr_t mdata_phys;
void *mdata_buf;
int ret;
mdata_buf = dma_alloc_coherent(__scm->dev, size, &mdata_phys,
GFP_KERNEL);
if (!mdata_buf) {
dev_err(__scm->dev, "Allocation of metadata buffer failed.\n");
return -ENOMEM;
}
memcpy(mdata_buf, metadata, size);
ret = qcom_scm_clk_enable();
if (ret)
goto free_metadata;
ret = __qcom_scm_pas_init_image(__scm->dev, peripheral, mdata_phys);
qcom_scm_clk_disable();
free_metadata:
dma_free_coherent(__scm->dev, size, mdata_buf, mdata_phys);
return ret;
}
int qcom_scm_pas_mem_setup(u32 peripheral, phys_addr_t addr, phys_addr_t size)
{
int ret;
ret = qcom_scm_clk_enable();
if (ret)
return ret;
ret = __qcom_scm_pas_mem_setup(__scm->dev, peripheral, addr, size);
qcom_scm_clk_disable();
return ret;
}
int qcom_scm_pas_auth_and_reset(u32 peripheral)
{
int ret;
ret = qcom_scm_clk_enable();
if (ret)
return ret;
ret = __qcom_scm_pas_auth_and_reset(__scm->dev, peripheral);
qcom_scm_clk_disable();
return ret;
}
int qcom_scm_pas_shutdown(u32 peripheral)
{
int ret;
ret = qcom_scm_clk_enable();
if (ret)
return ret;
ret = __qcom_scm_pas_shutdown(__scm->dev, peripheral);
qcom_scm_clk_disable();
return ret;
}
static int qcom_scm_pas_reset_assert(struct reset_controller_dev *rcdev,
unsigned long idx)
{
if (idx != 0)
return -EINVAL;
return __qcom_scm_pas_mss_reset(__scm->dev, 1);
}
static int qcom_scm_pas_reset_deassert(struct reset_controller_dev *rcdev,
unsigned long idx)
{
if (idx != 0)
return -EINVAL;
return __qcom_scm_pas_mss_reset(__scm->dev, 0);
}
int qcom_scm_restore_sec_cfg(u32 device_id, u32 spare)
{
return __qcom_scm_restore_sec_cfg(__scm->dev, device_id, spare);
}
int qcom_scm_iommu_secure_ptbl_size(u32 spare, size_t *size)
{
return __qcom_scm_iommu_secure_ptbl_size(__scm->dev, spare, size);
}
int qcom_scm_iommu_secure_ptbl_init(u64 addr, u32 size, u32 spare)
{
return __qcom_scm_iommu_secure_ptbl_init(__scm->dev, addr, size, spare);
}
bool qcom_scm_is_available(void)
{
return !!__scm;
}
int qcom_scm_set_remote_state(u32 state, u32 id)
{
return __qcom_scm_set_remote_state(__scm->dev, state, id);
}
static int qcom_scm_probe(struct platform_device *pdev)
{
struct qcom_scm *scm;
unsigned long clks;
int ret;
scm = devm_kzalloc(&pdev->dev, sizeof(*scm), GFP_KERNEL);
if (!scm)
return -ENOMEM;
clks = (unsigned long)of_device_get_match_data(&pdev->dev);
if (clks & SCM_HAS_CORE_CLK) {
scm->core_clk = devm_clk_get(&pdev->dev, "core");
if (IS_ERR(scm->core_clk)) {
if (PTR_ERR(scm->core_clk) != -EPROBE_DEFER)
dev_err(&pdev->dev,
"failed to acquire core clk\n");
return PTR_ERR(scm->core_clk);
}
}
if (clks & SCM_HAS_IFACE_CLK) {
scm->iface_clk = devm_clk_get(&pdev->dev, "iface");
if (IS_ERR(scm->iface_clk)) {
if (PTR_ERR(scm->iface_clk) != -EPROBE_DEFER)
dev_err(&pdev->dev,
"failed to acquire iface clk\n");
return PTR_ERR(scm->iface_clk);
}
}
if (clks & SCM_HAS_BUS_CLK) {
scm->bus_clk = devm_clk_get(&pdev->dev, "bus");
if (IS_ERR(scm->bus_clk)) {
if (PTR_ERR(scm->bus_clk) != -EPROBE_DEFER)
dev_err(&pdev->dev,
"failed to acquire bus clk\n");
return PTR_ERR(scm->bus_clk);
}
}
scm->reset.ops = &qcom_scm_pas_reset_ops;
scm->reset.nr_resets = 1;
scm->reset.of_node = pdev->dev.of_node;
ret = devm_reset_controller_register(&pdev->dev, &scm->reset);
if (ret)
return ret;
ret = clk_set_rate(scm->core_clk, INT_MAX);
if (ret)
return ret;
__scm = scm;
__scm->dev = &pdev->dev;
__qcom_scm_init();
return 0;
}
static int __init qcom_scm_init(void)
{
struct device_node *np, *fw_np;
int ret;
fw_np = of_find_node_by_name(NULL, "firmware");
if (!fw_np)
return -ENODEV;
np = of_find_matching_node(fw_np, qcom_scm_dt_match);
if (!np) {
of_node_put(fw_np);
return -ENODEV;
}
of_node_put(np);
ret = of_platform_populate(fw_np, qcom_scm_dt_match, NULL, NULL);
of_node_put(fw_np);
if (ret)
return ret;
return platform_driver_register(&qcom_scm_driver);
}
