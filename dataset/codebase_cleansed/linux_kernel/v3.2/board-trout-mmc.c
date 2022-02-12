static void config_gpio_table(uint32_t *table, int len)
{
int n;
unsigned id;
for(n = 0; n < len; n++) {
id = table[n];
msm_proc_comm(PCOM_RPC_GPIO_TLMM_CONFIG_EX, &id, 0);
}
}
static int __init trout_disablesdcard_setup(char *str)
{
int cal = simple_strtol(str, NULL, 0);
opt_disable_sdcard = cal;
return 1;
}
static uint32_t trout_sdslot_switchvdd(struct device *dev, unsigned int vdd)
{
int i, rc;
BUG_ON(!vreg_sdslot);
if (vdd == sdslot_vdd)
return 0;
sdslot_vdd = vdd;
if (vdd == 0) {
#if DEBUG_SDSLOT_VDD
printk("%s: Disabling SD slot power\n", __func__);
#endif
config_gpio_table(sdcard_off_gpio_table,
ARRAY_SIZE(sdcard_off_gpio_table));
vreg_disable(vreg_sdslot);
sdslot_vreg_enabled = 0;
return 0;
}
if (!sdslot_vreg_enabled) {
rc = vreg_enable(vreg_sdslot);
if (rc) {
printk(KERN_ERR "%s: Error enabling vreg (%d)\n",
__func__, rc);
}
config_gpio_table(sdcard_on_gpio_table,
ARRAY_SIZE(sdcard_on_gpio_table));
sdslot_vreg_enabled = 1;
}
for (i = 0; i < ARRAY_SIZE(mmc_vdd_table); i++) {
if (mmc_vdd_table[i].mask == (1 << vdd)) {
#if DEBUG_SDSLOT_VDD
printk("%s: Setting level to %u\n",
__func__, mmc_vdd_table[i].level);
#endif
rc = vreg_set_level(vreg_sdslot,
mmc_vdd_table[i].level);
if (rc) {
printk(KERN_ERR
"%s: Error setting vreg level (%d)\n",
__func__, rc);
}
return 0;
}
}
printk(KERN_ERR "%s: Invalid VDD %d specified\n", __func__, vdd);
return 0;
}
static unsigned int trout_sdslot_status(struct device *dev)
{
unsigned int status;
status = (unsigned int) gpio_get_value(TROUT_GPIO_SDMC_CD_N);
return (!status);
}
int __init trout_init_mmc(unsigned int sys_rev)
{
sdslot_vreg_enabled = 0;
vreg_sdslot = vreg_get(0, "gp6");
if (IS_ERR(vreg_sdslot))
return PTR_ERR(vreg_sdslot);
irq_set_irq_wake(TROUT_GPIO_TO_INT(TROUT_GPIO_SDMC_CD_N), 1);
if (!opt_disable_sdcard)
msm_add_sdcc(2, &trout_sdslot_data,
TROUT_GPIO_TO_INT(TROUT_GPIO_SDMC_CD_N), 0);
else
printk(KERN_INFO "trout: SD-Card interface disabled\n");
return 0;
}
