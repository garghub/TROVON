static void trout_process_mddi_table(struct msm_mddi_client_data *client_data,
struct mddi_table *table, size_t count)
{
int i;
for (i = 0; i < count; i++) {
uint32_t reg = table[i].reg;
uint32_t value = table[i].value;
if (reg == 0)
udelay(value);
else if (reg == 1)
msleep(value);
else
client_data->remote_write(client_data, value, reg);
}
}
static int trout_mddi_toshiba_client_init(
struct msm_mddi_bridge_platform_data *bridge_data,
struct msm_mddi_client_data *client_data)
{
int panel_id;
client_data->auto_hibernate(client_data, 0);
trout_process_mddi_table(client_data, mddi_toshiba_init_table,
ARRAY_SIZE(mddi_toshiba_init_table));
client_data->auto_hibernate(client_data, 1);
panel_id = (client_data->remote_read(client_data, GPIODATA) >> 4) & 3;
if (panel_id > 1) {
printk(KERN_WARNING "unknown panel id at mddi_enable\n");
return -1;
}
return 0;
}
static int trout_mddi_toshiba_client_uninit(
struct msm_mddi_bridge_platform_data *bridge_data,
struct msm_mddi_client_data *client_data)
{
return 0;
}
int __init trout_init_panel(void)
{
int rc;
if (!machine_is_trout())
return 0;
vreg_mddi_1v5 = vreg_get(0, "gp2");
if (IS_ERR(vreg_mddi_1v5))
return PTR_ERR(vreg_mddi_1v5);
vreg_lcm_2v85 = vreg_get(0, "gp4");
if (IS_ERR(vreg_lcm_2v85))
return PTR_ERR(vreg_lcm_2v85);
trout_new_backlight = system_rev >= 5;
if (trout_new_backlight) {
uint32_t config = PCOM_GPIO_CFG(27, 0, GPIO_OUTPUT,
GPIO_NO_PULL, GPIO_8MA);
msm_proc_comm(PCOM_RPC_GPIO_TLMM_CONFIG_EX, &config, 0);
} else {
uint32_t config = PCOM_GPIO_CFG(27, 1, GPIO_OUTPUT,
GPIO_NO_PULL, GPIO_8MA);
uint32_t id = P_GP_CLK;
uint32_t rate = 19200000;
msm_proc_comm(PCOM_RPC_GPIO_TLMM_CONFIG_EX, &config, 0);
msm_proc_comm(PCOM_CLKCTL_RPC_SET_RATE, &id, &rate);
if (id < 0)
pr_err("trout_init_panel: set clock rate failed\n");
}
rc = platform_device_register(&msm_device_mdp);
if (rc)
return rc;
msm_device_mddi0.dev.platform_data = &mddi_pdata;
return platform_device_register(&msm_device_mddi0);
}
