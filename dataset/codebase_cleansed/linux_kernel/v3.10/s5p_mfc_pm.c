int s5p_mfc_init_pm(struct s5p_mfc_dev *dev)
{
int ret = 0;
pm = &dev->pm;
p_dev = dev;
pm->clock_gate = clk_get(&dev->plat_dev->dev, MFC_GATE_CLK_NAME);
if (IS_ERR(pm->clock_gate)) {
mfc_err("Failed to get clock-gating control\n");
ret = PTR_ERR(pm->clock_gate);
goto err_g_ip_clk;
}
ret = clk_prepare(pm->clock_gate);
if (ret) {
mfc_err("Failed to prepare clock-gating control\n");
goto err_p_ip_clk;
}
atomic_set(&pm->power, 0);
#ifdef CONFIG_PM_RUNTIME
pm->device = &dev->plat_dev->dev;
pm_runtime_enable(pm->device);
#endif
#ifdef CLK_DEBUG
atomic_set(&clk_ref, 0);
#endif
return 0;
err_p_ip_clk:
clk_put(pm->clock_gate);
err_g_ip_clk:
return ret;
}
void s5p_mfc_final_pm(struct s5p_mfc_dev *dev)
{
clk_unprepare(pm->clock_gate);
clk_put(pm->clock_gate);
#ifdef CONFIG_PM_RUNTIME
pm_runtime_disable(pm->device);
#endif
}
int s5p_mfc_clock_on(void)
{
int ret;
#ifdef CLK_DEBUG
atomic_inc(&clk_ref);
mfc_debug(3, "+ %d\n", atomic_read(&clk_ref));
#endif
ret = clk_enable(pm->clock_gate);
return ret;
}
void s5p_mfc_clock_off(void)
{
#ifdef CLK_DEBUG
atomic_dec(&clk_ref);
mfc_debug(3, "- %d\n", atomic_read(&clk_ref));
#endif
clk_disable(pm->clock_gate);
}
int s5p_mfc_power_on(void)
{
#ifdef CONFIG_PM_RUNTIME
return pm_runtime_get_sync(pm->device);
#else
atomic_set(&pm->power, 1);
return 0;
#endif
}
int s5p_mfc_power_off(void)
{
#ifdef CONFIG_PM_RUNTIME
return pm_runtime_put_sync(pm->device);
#else
atomic_set(&pm->power, 0);
return 0;
#endif
}
