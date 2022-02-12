static void st_rproc_mbox_callback(struct device *dev, u32 msg)
{
struct rproc *rproc = dev_get_drvdata(dev);
if (rproc_vq_interrupt(rproc, msg) == IRQ_NONE)
dev_dbg(dev, "no message was found in vqid %d\n", msg);
}
static
void st_rproc_mbox_callback_vq0(struct mbox_client *mbox_client, void *data)
{
st_rproc_mbox_callback(mbox_client->dev, 0);
}
static
void st_rproc_mbox_callback_vq1(struct mbox_client *mbox_client, void *data)
{
st_rproc_mbox_callback(mbox_client->dev, 1);
}
static void st_rproc_kick(struct rproc *rproc, int vqid)
{
struct st_rproc *ddata = rproc->priv;
struct device *dev = rproc->dev.parent;
int ret;
if (WARN_ON(vqid >= ST_RPROC_MAX_VRING))
return;
ret = mbox_send_message(ddata->mbox_chan[vqid * MBOX_MAX + MBOX_TX],
(void *)&vqid);
if (ret < 0)
dev_err(dev, "failed to send message via mbox: %d\n", ret);
}
static int st_rproc_start(struct rproc *rproc)
{
struct st_rproc *ddata = rproc->priv;
int err;
regmap_update_bits(ddata->boot_base, ddata->boot_offset,
ddata->config->bootaddr_mask, rproc->bootaddr);
err = clk_enable(ddata->clk);
if (err) {
dev_err(&rproc->dev, "Failed to enable clock\n");
return err;
}
if (ddata->config->sw_reset) {
err = reset_control_deassert(ddata->sw_reset);
if (err) {
dev_err(&rproc->dev, "Failed to deassert S/W Reset\n");
goto sw_reset_fail;
}
}
if (ddata->config->pwr_reset) {
err = reset_control_deassert(ddata->pwr_reset);
if (err) {
dev_err(&rproc->dev, "Failed to deassert Power Reset\n");
goto pwr_reset_fail;
}
}
dev_info(&rproc->dev, "Started from 0x%x\n", rproc->bootaddr);
return 0;
pwr_reset_fail:
if (ddata->config->pwr_reset)
reset_control_assert(ddata->sw_reset);
sw_reset_fail:
clk_disable(ddata->clk);
return err;
}
static int st_rproc_stop(struct rproc *rproc)
{
struct st_rproc *ddata = rproc->priv;
int sw_err = 0, pwr_err = 0;
if (ddata->config->sw_reset) {
sw_err = reset_control_assert(ddata->sw_reset);
if (sw_err)
dev_err(&rproc->dev, "Failed to assert S/W Reset\n");
}
if (ddata->config->pwr_reset) {
pwr_err = reset_control_assert(ddata->pwr_reset);
if (pwr_err)
dev_err(&rproc->dev, "Failed to assert Power Reset\n");
}
clk_disable(ddata->clk);
return sw_err ?: pwr_err;
}
static int st_rproc_state(struct platform_device *pdev)
{
struct rproc *rproc = platform_get_drvdata(pdev);
struct st_rproc *ddata = rproc->priv;
int reset_sw = 0, reset_pwr = 0;
if (ddata->config->sw_reset)
reset_sw = reset_control_status(ddata->sw_reset);
if (ddata->config->pwr_reset)
reset_pwr = reset_control_status(ddata->pwr_reset);
if (reset_sw < 0 || reset_pwr < 0)
return -EINVAL;
return !reset_sw && !reset_pwr;
}
static int st_rproc_parse_dt(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct rproc *rproc = platform_get_drvdata(pdev);
struct st_rproc *ddata = rproc->priv;
struct device_node *np = dev->of_node;
int err;
if (ddata->config->sw_reset) {
ddata->sw_reset = devm_reset_control_get(dev, "sw_reset");
if (IS_ERR(ddata->sw_reset)) {
dev_err(dev, "Failed to get S/W Reset\n");
return PTR_ERR(ddata->sw_reset);
}
}
if (ddata->config->pwr_reset) {
ddata->pwr_reset = devm_reset_control_get(dev, "pwr_reset");
if (IS_ERR(ddata->pwr_reset)) {
dev_err(dev, "Failed to get Power Reset\n");
return PTR_ERR(ddata->pwr_reset);
}
}
ddata->clk = devm_clk_get(dev, NULL);
if (IS_ERR(ddata->clk)) {
dev_err(dev, "Failed to get clock\n");
return PTR_ERR(ddata->clk);
}
err = of_property_read_u32(np, "clock-frequency", &ddata->clk_rate);
if (err) {
dev_err(dev, "failed to get clock frequency\n");
return err;
}
ddata->boot_base = syscon_regmap_lookup_by_phandle(np, "st,syscfg");
if (IS_ERR(ddata->boot_base)) {
dev_err(dev, "Boot base not found\n");
return PTR_ERR(ddata->boot_base);
}
err = of_property_read_u32_index(np, "st,syscfg", 1,
&ddata->boot_offset);
if (err) {
dev_err(dev, "Boot offset not found\n");
return -EINVAL;
}
err = of_reserved_mem_device_init(dev);
if (err) {
dev_err(dev, "Failed to obtain shared memory\n");
return err;
}
err = clk_prepare(ddata->clk);
if (err)
dev_err(dev, "failed to get clock\n");
return err;
}
static int st_rproc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct of_device_id *match;
struct st_rproc *ddata;
struct device_node *np = dev->of_node;
struct rproc *rproc;
struct mbox_chan *chan;
int enabled;
int ret, i;
match = of_match_device(st_rproc_match, dev);
if (!match || !match->data) {
dev_err(dev, "No device match found\n");
return -ENODEV;
}
rproc = rproc_alloc(dev, np->name, &st_rproc_ops, NULL, sizeof(*ddata));
if (!rproc)
return -ENOMEM;
rproc->has_iommu = false;
ddata = rproc->priv;
ddata->config = (struct st_rproc_config *)match->data;
platform_set_drvdata(pdev, rproc);
ret = st_rproc_parse_dt(pdev);
if (ret)
goto free_rproc;
enabled = st_rproc_state(pdev);
if (enabled < 0) {
ret = enabled;
goto free_clk;
}
if (enabled) {
atomic_inc(&rproc->power);
rproc->state = RPROC_RUNNING;
} else {
clk_set_rate(ddata->clk, ddata->clk_rate);
}
if (of_get_property(np, "mbox-names", NULL)) {
ddata->mbox_client_vq0.dev = dev;
ddata->mbox_client_vq0.tx_done = NULL;
ddata->mbox_client_vq0.tx_block = false;
ddata->mbox_client_vq0.knows_txdone = false;
ddata->mbox_client_vq0.rx_callback = st_rproc_mbox_callback_vq0;
ddata->mbox_client_vq1.dev = dev;
ddata->mbox_client_vq1.tx_done = NULL;
ddata->mbox_client_vq1.tx_block = false;
ddata->mbox_client_vq1.knows_txdone = false;
ddata->mbox_client_vq1.rx_callback = st_rproc_mbox_callback_vq1;
chan = mbox_request_channel_byname(&ddata->mbox_client_vq0, "vq0_rx");
if (IS_ERR(chan)) {
dev_err(&rproc->dev, "failed to request mbox chan 0\n");
ret = PTR_ERR(chan);
goto free_clk;
}
ddata->mbox_chan[ST_RPROC_VQ0 * MBOX_MAX + MBOX_RX] = chan;
chan = mbox_request_channel_byname(&ddata->mbox_client_vq0, "vq0_tx");
if (IS_ERR(chan)) {
dev_err(&rproc->dev, "failed to request mbox chan 0\n");
ret = PTR_ERR(chan);
goto free_mbox;
}
ddata->mbox_chan[ST_RPROC_VQ0 * MBOX_MAX + MBOX_TX] = chan;
chan = mbox_request_channel_byname(&ddata->mbox_client_vq1, "vq1_rx");
if (IS_ERR(chan)) {
dev_err(&rproc->dev, "failed to request mbox chan 1\n");
ret = PTR_ERR(chan);
goto free_mbox;
}
ddata->mbox_chan[ST_RPROC_VQ1 * MBOX_MAX + MBOX_RX] = chan;
chan = mbox_request_channel_byname(&ddata->mbox_client_vq1, "vq1_tx");
if (IS_ERR(chan)) {
dev_err(&rproc->dev, "failed to request mbox chan 1\n");
ret = PTR_ERR(chan);
goto free_mbox;
}
ddata->mbox_chan[ST_RPROC_VQ1 * MBOX_MAX + MBOX_TX] = chan;
}
ret = rproc_add(rproc);
if (ret)
goto free_mbox;
return 0;
free_mbox:
for (i = 0; i < ST_RPROC_MAX_VRING * MBOX_MAX; i++)
mbox_free_channel(ddata->mbox_chan[i]);
free_clk:
clk_unprepare(ddata->clk);
free_rproc:
rproc_free(rproc);
return ret;
}
static int st_rproc_remove(struct platform_device *pdev)
{
struct rproc *rproc = platform_get_drvdata(pdev);
struct st_rproc *ddata = rproc->priv;
int i;
rproc_del(rproc);
clk_disable_unprepare(ddata->clk);
of_reserved_mem_device_release(&pdev->dev);
for (i = 0; i < ST_RPROC_MAX_VRING * MBOX_MAX; i++)
mbox_free_channel(ddata->mbox_chan[i]);
rproc_free(rproc);
return 0;
}
