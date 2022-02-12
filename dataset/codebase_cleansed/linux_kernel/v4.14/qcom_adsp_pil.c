static int adsp_load(struct rproc *rproc, const struct firmware *fw)
{
struct qcom_adsp *adsp = (struct qcom_adsp *)rproc->priv;
return qcom_mdt_load(adsp->dev, fw, rproc->firmware, adsp->pas_id,
adsp->mem_region, adsp->mem_phys, adsp->mem_size);
}
static int adsp_start(struct rproc *rproc)
{
struct qcom_adsp *adsp = (struct qcom_adsp *)rproc->priv;
int ret;
ret = clk_prepare_enable(adsp->xo);
if (ret)
return ret;
ret = clk_prepare_enable(adsp->aggre2_clk);
if (ret)
goto disable_xo_clk;
ret = regulator_enable(adsp->cx_supply);
if (ret)
goto disable_aggre2_clk;
ret = regulator_enable(adsp->px_supply);
if (ret)
goto disable_cx_supply;
ret = qcom_scm_pas_auth_and_reset(adsp->pas_id);
if (ret) {
dev_err(adsp->dev,
"failed to authenticate image and release reset\n");
goto disable_px_supply;
}
ret = wait_for_completion_timeout(&adsp->start_done,
msecs_to_jiffies(5000));
if (!ret) {
dev_err(adsp->dev, "start timed out\n");
qcom_scm_pas_shutdown(adsp->pas_id);
ret = -ETIMEDOUT;
goto disable_px_supply;
}
ret = 0;
disable_px_supply:
regulator_disable(adsp->px_supply);
disable_cx_supply:
regulator_disable(adsp->cx_supply);
disable_aggre2_clk:
clk_disable_unprepare(adsp->aggre2_clk);
disable_xo_clk:
clk_disable_unprepare(adsp->xo);
return ret;
}
static int adsp_stop(struct rproc *rproc)
{
struct qcom_adsp *adsp = (struct qcom_adsp *)rproc->priv;
int ret;
qcom_smem_state_update_bits(adsp->state,
BIT(adsp->stop_bit),
BIT(adsp->stop_bit));
ret = wait_for_completion_timeout(&adsp->stop_done,
msecs_to_jiffies(5000));
if (ret == 0)
dev_err(adsp->dev, "timed out on wait\n");
qcom_smem_state_update_bits(adsp->state,
BIT(adsp->stop_bit),
0);
ret = qcom_scm_pas_shutdown(adsp->pas_id);
if (ret)
dev_err(adsp->dev, "failed to shutdown: %d\n", ret);
return ret;
}
static void *adsp_da_to_va(struct rproc *rproc, u64 da, int len)
{
struct qcom_adsp *adsp = (struct qcom_adsp *)rproc->priv;
int offset;
offset = da - adsp->mem_reloc;
if (offset < 0 || offset + len > adsp->mem_size)
return NULL;
return adsp->mem_region + offset;
}
static irqreturn_t adsp_wdog_interrupt(int irq, void *dev)
{
struct qcom_adsp *adsp = dev;
rproc_report_crash(adsp->rproc, RPROC_WATCHDOG);
return IRQ_HANDLED;
}
static irqreturn_t adsp_fatal_interrupt(int irq, void *dev)
{
struct qcom_adsp *adsp = dev;
size_t len;
char *msg;
msg = qcom_smem_get(QCOM_SMEM_HOST_ANY, adsp->crash_reason_smem, &len);
if (!IS_ERR(msg) && len > 0 && msg[0])
dev_err(adsp->dev, "fatal error received: %s\n", msg);
rproc_report_crash(adsp->rproc, RPROC_FATAL_ERROR);
if (!IS_ERR(msg))
msg[0] = '\0';
return IRQ_HANDLED;
}
static irqreturn_t adsp_ready_interrupt(int irq, void *dev)
{
return IRQ_HANDLED;
}
static irqreturn_t adsp_handover_interrupt(int irq, void *dev)
{
struct qcom_adsp *adsp = dev;
complete(&adsp->start_done);
return IRQ_HANDLED;
}
static irqreturn_t adsp_stop_ack_interrupt(int irq, void *dev)
{
struct qcom_adsp *adsp = dev;
complete(&adsp->stop_done);
return IRQ_HANDLED;
}
static int adsp_init_clock(struct qcom_adsp *adsp)
{
int ret;
adsp->xo = devm_clk_get(adsp->dev, "xo");
if (IS_ERR(adsp->xo)) {
ret = PTR_ERR(adsp->xo);
if (ret != -EPROBE_DEFER)
dev_err(adsp->dev, "failed to get xo clock");
return ret;
}
if (adsp->has_aggre2_clk) {
adsp->aggre2_clk = devm_clk_get(adsp->dev, "aggre2");
if (IS_ERR(adsp->aggre2_clk)) {
ret = PTR_ERR(adsp->aggre2_clk);
if (ret != -EPROBE_DEFER)
dev_err(adsp->dev,
"failed to get aggre2 clock");
return ret;
}
}
return 0;
}
static int adsp_init_regulator(struct qcom_adsp *adsp)
{
adsp->cx_supply = devm_regulator_get(adsp->dev, "cx");
if (IS_ERR(adsp->cx_supply))
return PTR_ERR(adsp->cx_supply);
regulator_set_load(adsp->cx_supply, 100000);
adsp->px_supply = devm_regulator_get(adsp->dev, "px");
return PTR_ERR_OR_ZERO(adsp->px_supply);
}
static int adsp_request_irq(struct qcom_adsp *adsp,
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
IRQF_ONESHOT,
"adsp", adsp);
if (ret)
dev_err(&pdev->dev, "request %s IRQ failed\n", name);
return ret;
}
static int adsp_alloc_memory_region(struct qcom_adsp *adsp)
{
struct device_node *node;
struct resource r;
int ret;
node = of_parse_phandle(adsp->dev->of_node, "memory-region", 0);
if (!node) {
dev_err(adsp->dev, "no memory-region specified\n");
return -EINVAL;
}
ret = of_address_to_resource(node, 0, &r);
if (ret)
return ret;
adsp->mem_phys = adsp->mem_reloc = r.start;
adsp->mem_size = resource_size(&r);
adsp->mem_region = devm_ioremap_wc(adsp->dev, adsp->mem_phys, adsp->mem_size);
if (!adsp->mem_region) {
dev_err(adsp->dev, "unable to map memory region: %pa+%zx\n",
&r.start, adsp->mem_size);
return -EBUSY;
}
return 0;
}
static int adsp_probe(struct platform_device *pdev)
{
const struct adsp_data *desc;
struct qcom_adsp *adsp;
struct rproc *rproc;
int ret;
desc = of_device_get_match_data(&pdev->dev);
if (!desc)
return -EINVAL;
if (!qcom_scm_is_available())
return -EPROBE_DEFER;
rproc = rproc_alloc(&pdev->dev, pdev->name, &adsp_ops,
desc->firmware_name, sizeof(*adsp));
if (!rproc) {
dev_err(&pdev->dev, "unable to allocate remoteproc\n");
return -ENOMEM;
}
rproc->fw_ops = &adsp_fw_ops;
adsp = (struct qcom_adsp *)rproc->priv;
adsp->dev = &pdev->dev;
adsp->rproc = rproc;
adsp->pas_id = desc->pas_id;
adsp->crash_reason_smem = desc->crash_reason_smem;
adsp->has_aggre2_clk = desc->has_aggre2_clk;
platform_set_drvdata(pdev, adsp);
init_completion(&adsp->start_done);
init_completion(&adsp->stop_done);
ret = adsp_alloc_memory_region(adsp);
if (ret)
goto free_rproc;
ret = adsp_init_clock(adsp);
if (ret)
goto free_rproc;
ret = adsp_init_regulator(adsp);
if (ret)
goto free_rproc;
ret = adsp_request_irq(adsp, pdev, "wdog", adsp_wdog_interrupt);
if (ret < 0)
goto free_rproc;
adsp->wdog_irq = ret;
ret = adsp_request_irq(adsp, pdev, "fatal", adsp_fatal_interrupt);
if (ret < 0)
goto free_rproc;
adsp->fatal_irq = ret;
ret = adsp_request_irq(adsp, pdev, "ready", adsp_ready_interrupt);
if (ret < 0)
goto free_rproc;
adsp->ready_irq = ret;
ret = adsp_request_irq(adsp, pdev, "handover", adsp_handover_interrupt);
if (ret < 0)
goto free_rproc;
adsp->handover_irq = ret;
ret = adsp_request_irq(adsp, pdev, "stop-ack", adsp_stop_ack_interrupt);
if (ret < 0)
goto free_rproc;
adsp->stop_ack_irq = ret;
adsp->state = qcom_smem_state_get(&pdev->dev, "stop",
&adsp->stop_bit);
if (IS_ERR(adsp->state)) {
ret = PTR_ERR(adsp->state);
goto free_rproc;
}
qcom_add_glink_subdev(rproc, &adsp->glink_subdev);
qcom_add_smd_subdev(rproc, &adsp->smd_subdev);
qcom_add_ssr_subdev(rproc, &adsp->ssr_subdev, desc->ssr_name);
ret = rproc_add(rproc);
if (ret)
goto free_rproc;
return 0;
free_rproc:
rproc_free(rproc);
return ret;
}
static int adsp_remove(struct platform_device *pdev)
{
struct qcom_adsp *adsp = platform_get_drvdata(pdev);
qcom_smem_state_put(adsp->state);
rproc_del(adsp->rproc);
qcom_remove_glink_subdev(adsp->rproc, &adsp->glink_subdev);
qcom_remove_smd_subdev(adsp->rproc, &adsp->smd_subdev);
qcom_remove_ssr_subdev(adsp->rproc, &adsp->ssr_subdev);
rproc_free(adsp->rproc);
return 0;
}
