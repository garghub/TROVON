static int apq8016_lpass_alloc_dma_channel(struct lpass_data *drvdata)
{
struct lpass_variant *v = drvdata->variant;
int chan = find_first_zero_bit(&drvdata->rdma_ch_bit_map,
v->rdma_channels);
if (chan >= v->rdma_channels)
return -EBUSY;
set_bit(chan, &drvdata->rdma_ch_bit_map);
return chan;
}
static int apq8016_lpass_free_dma_channel(struct lpass_data *drvdata, int chan)
{
clear_bit(chan, &drvdata->rdma_ch_bit_map);
return 0;
}
static int apq8016_lpass_init(struct platform_device *pdev)
{
struct lpass_data *drvdata = platform_get_drvdata(pdev);
struct device *dev = &pdev->dev;
int ret;
drvdata->pcnoc_mport_clk = devm_clk_get(dev, "pcnoc-mport-clk");
if (IS_ERR(drvdata->pcnoc_mport_clk)) {
dev_err(&pdev->dev, "%s() error getting pcnoc-mport-clk: %ld\n",
__func__, PTR_ERR(drvdata->pcnoc_mport_clk));
return PTR_ERR(drvdata->pcnoc_mport_clk);
}
ret = clk_prepare_enable(drvdata->pcnoc_mport_clk);
if (ret) {
dev_err(&pdev->dev, "%s() Error enabling pcnoc-mport-clk: %d\n",
__func__, ret);
return ret;
}
drvdata->pcnoc_sway_clk = devm_clk_get(dev, "pcnoc-sway-clk");
if (IS_ERR(drvdata->pcnoc_sway_clk)) {
dev_err(&pdev->dev, "%s() error getting pcnoc-sway-clk: %ld\n",
__func__, PTR_ERR(drvdata->pcnoc_sway_clk));
return PTR_ERR(drvdata->pcnoc_sway_clk);
}
ret = clk_prepare_enable(drvdata->pcnoc_sway_clk);
if (ret) {
dev_err(&pdev->dev, "%s() Error enabling pcnoc_sway_clk: %d\n",
__func__, ret);
return ret;
}
return 0;
}
static int apq8016_lpass_exit(struct platform_device *pdev)
{
struct lpass_data *drvdata = platform_get_drvdata(pdev);
clk_disable_unprepare(drvdata->pcnoc_mport_clk);
clk_disable_unprepare(drvdata->pcnoc_sway_clk);
return 0;
}
