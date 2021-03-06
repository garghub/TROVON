int ssi_power_mgr_runtime_suspend(struct device *dev)
{
struct ssi_drvdata *drvdata =
(struct ssi_drvdata *)dev_get_drvdata(dev);
int rc;
SSI_LOG_DEBUG("set HOST_POWER_DOWN_EN\n");
WRITE_REGISTER(drvdata->cc_base + CC_REG_OFFSET(HOST_RGF, HOST_POWER_DOWN_EN), POWER_DOWN_ENABLE);
rc = ssi_request_mgr_runtime_suspend_queue(drvdata);
if (rc != 0) {
SSI_LOG_ERR("ssi_request_mgr_runtime_suspend_queue (%x)\n", rc);
return rc;
}
fini_cc_regs(drvdata);
cc_clk_off(drvdata);
return 0;
}
int ssi_power_mgr_runtime_resume(struct device *dev)
{
int rc;
struct ssi_drvdata *drvdata =
(struct ssi_drvdata *)dev_get_drvdata(dev);
SSI_LOG_DEBUG("unset HOST_POWER_DOWN_EN\n");
WRITE_REGISTER(drvdata->cc_base + CC_REG_OFFSET(HOST_RGF, HOST_POWER_DOWN_EN), POWER_DOWN_DISABLE);
rc = cc_clk_on(drvdata);
if (rc) {
SSI_LOG_ERR("failed getting clock back on. We're toast.\n");
return rc;
}
rc = init_cc_regs(drvdata, false);
if (rc != 0) {
SSI_LOG_ERR("init_cc_regs (%x)\n", rc);
return rc;
}
rc = ssi_request_mgr_runtime_resume_queue(drvdata);
if (rc != 0) {
SSI_LOG_ERR("ssi_request_mgr_runtime_resume_queue (%x)\n", rc);
return rc;
}
ssi_hash_init_sram_digest_consts(drvdata);
ssi_ivgen_init_sram_pool(drvdata);
return 0;
}
int ssi_power_mgr_runtime_get(struct device *dev)
{
int rc = 0;
if (ssi_request_mgr_is_queue_runtime_suspend(
(struct ssi_drvdata *)dev_get_drvdata(dev))) {
rc = pm_runtime_get_sync(dev);
} else {
pm_runtime_get_noresume(dev);
}
return rc;
}
int ssi_power_mgr_runtime_put_suspend(struct device *dev)
{
int rc = 0;
if (!ssi_request_mgr_is_queue_runtime_suspend(
(struct ssi_drvdata *)dev_get_drvdata(dev))) {
pm_runtime_mark_last_busy(dev);
rc = pm_runtime_put_autosuspend(dev);
} else {
BUG();
}
return rc;
}
int ssi_power_mgr_init(struct ssi_drvdata *drvdata)
{
int rc = 0;
#if defined(CONFIG_PM_RUNTIME) || defined(CONFIG_PM_SLEEP)
struct platform_device *plat_dev = drvdata->plat_dev;
pm_runtime_set_autosuspend_delay(&plat_dev->dev, SSI_SUSPEND_TIMEOUT);
pm_runtime_use_autosuspend(&plat_dev->dev);
rc = pm_runtime_set_active(&plat_dev->dev);
if (rc != 0)
return rc;
pm_runtime_enable(&plat_dev->dev);
#endif
return rc;
}
void ssi_power_mgr_fini(struct ssi_drvdata *drvdata)
{
#if defined(CONFIG_PM_RUNTIME) || defined(CONFIG_PM_SLEEP)
struct platform_device *plat_dev = drvdata->plat_dev;
pm_runtime_disable(&plat_dev->dev);
#endif
}
