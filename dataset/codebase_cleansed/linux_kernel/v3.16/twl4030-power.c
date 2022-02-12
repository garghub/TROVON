static int twl4030_write_script_byte(u8 address, u8 byte)
{
int err;
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, address, R_MEMORY_ADDRESS);
if (err)
goto out;
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, byte, R_MEMORY_DATA);
out:
return err;
}
static int twl4030_write_script_ins(u8 address, u16 pmb_message,
u8 delay, u8 next)
{
int err;
address *= 4;
err = twl4030_write_script_byte(address++, pmb_message >> 8);
if (err)
goto out;
err = twl4030_write_script_byte(address++, pmb_message & 0xff);
if (err)
goto out;
err = twl4030_write_script_byte(address++, delay);
if (err)
goto out;
err = twl4030_write_script_byte(address++, next);
out:
return err;
}
static int twl4030_write_script(u8 address, struct twl4030_ins *script,
int len)
{
int err = -EINVAL;
for (; len; len--, address++, script++) {
if (len == 1) {
err = twl4030_write_script_ins(address,
script->pmb_message,
script->delay,
END_OF_SCRIPT);
if (err)
break;
} else {
err = twl4030_write_script_ins(address,
script->pmb_message,
script->delay,
address + 1);
if (err)
break;
}
}
return err;
}
static int twl4030_config_wakeup3_sequence(u8 address)
{
int err;
u8 data;
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, address, R_SEQ_ADD_S2A3);
if (err)
goto out;
err = twl_i2c_read_u8(TWL_MODULE_PM_MASTER, &data, R_P3_SW_EVENTS);
if (err)
goto out;
data |= PWR_LVL_WAKEUP;
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, data, R_P3_SW_EVENTS);
out:
if (err)
pr_err("TWL4030 wakeup sequence for P3 config error\n");
return err;
}
static int twl4030_config_wakeup12_sequence(u8 address)
{
int err = 0;
u8 data;
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, address, R_SEQ_ADD_S2A12);
if (err)
goto out;
err = twl_i2c_read_u8(TWL_MODULE_PM_MASTER, &data, R_P1_SW_EVENTS);
if (err)
goto out;
data |= PWR_LVL_WAKEUP;
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, data, R_P1_SW_EVENTS);
if (err)
goto out;
err = twl_i2c_read_u8(TWL_MODULE_PM_MASTER, &data, R_P2_SW_EVENTS);
if (err)
goto out;
data |= PWR_LVL_WAKEUP;
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, data, R_P2_SW_EVENTS);
if (err)
goto out;
if (machine_is_omap_3430sdp() || machine_is_omap_ldp()) {
err = twl_i2c_read_u8(TWL_MODULE_PM_MASTER, &data,
R_CFG_P1_TRANSITION);
if (err)
goto out;
data &= ~(1<<1);
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, data,
R_CFG_P1_TRANSITION);
if (err)
goto out;
}
out:
if (err)
pr_err("TWL4030 wakeup sequence for P1 and P2" \
"config error\n");
return err;
}
static int twl4030_config_sleep_sequence(u8 address)
{
int err;
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, address, R_SEQ_ADD_A2S);
if (err)
pr_err("TWL4030 sleep sequence config error\n");
return err;
}
static int twl4030_config_warmreset_sequence(u8 address)
{
int err;
u8 rd_data;
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, address, R_SEQ_ADD_WARM);
if (err)
goto out;
err = twl_i2c_read_u8(TWL_MODULE_PM_MASTER, &rd_data, R_P1_SW_EVENTS);
if (err)
goto out;
rd_data |= PWR_ENABLE_WARMRESET;
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, rd_data, R_P1_SW_EVENTS);
if (err)
goto out;
err = twl_i2c_read_u8(TWL_MODULE_PM_MASTER, &rd_data, R_P2_SW_EVENTS);
if (err)
goto out;
rd_data |= PWR_ENABLE_WARMRESET;
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, rd_data, R_P2_SW_EVENTS);
if (err)
goto out;
err = twl_i2c_read_u8(TWL_MODULE_PM_MASTER, &rd_data, R_P3_SW_EVENTS);
if (err)
goto out;
rd_data |= PWR_ENABLE_WARMRESET;
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, rd_data, R_P3_SW_EVENTS);
out:
if (err)
pr_err("TWL4030 warmreset seq config error\n");
return err;
}
static int twl4030_configure_resource(struct twl4030_resconfig *rconfig)
{
int rconfig_addr;
int err;
u8 type;
u8 grp;
u8 remap;
if (rconfig->resource > TOTAL_RESOURCES) {
pr_err("TWL4030 Resource %d does not exist\n",
rconfig->resource);
return -EINVAL;
}
rconfig_addr = res_config_addrs[rconfig->resource];
err = twl_i2c_read_u8(TWL_MODULE_PM_RECEIVER, &grp,
rconfig_addr + DEV_GRP_OFFSET);
if (err) {
pr_err("TWL4030 Resource %d group could not be read\n",
rconfig->resource);
return err;
}
if (rconfig->devgroup != TWL4030_RESCONFIG_UNDEF) {
grp &= ~DEV_GRP_MASK;
grp |= rconfig->devgroup << DEV_GRP_SHIFT;
err = twl_i2c_write_u8(TWL_MODULE_PM_RECEIVER,
grp, rconfig_addr + DEV_GRP_OFFSET);
if (err < 0) {
pr_err("TWL4030 failed to program devgroup\n");
return err;
}
}
err = twl_i2c_read_u8(TWL_MODULE_PM_RECEIVER, &type,
rconfig_addr + TYPE_OFFSET);
if (err < 0) {
pr_err("TWL4030 Resource %d type could not be read\n",
rconfig->resource);
return err;
}
if (rconfig->type != TWL4030_RESCONFIG_UNDEF) {
type &= ~TYPE_MASK;
type |= rconfig->type << TYPE_SHIFT;
}
if (rconfig->type2 != TWL4030_RESCONFIG_UNDEF) {
type &= ~TYPE2_MASK;
type |= rconfig->type2 << TYPE2_SHIFT;
}
err = twl_i2c_write_u8(TWL_MODULE_PM_RECEIVER,
type, rconfig_addr + TYPE_OFFSET);
if (err < 0) {
pr_err("TWL4030 failed to program resource type\n");
return err;
}
err = twl_i2c_read_u8(TWL_MODULE_PM_RECEIVER, &remap,
rconfig_addr + REMAP_OFFSET);
if (err < 0) {
pr_err("TWL4030 Resource %d remap could not be read\n",
rconfig->resource);
return err;
}
if (rconfig->remap_off != TWL4030_RESCONFIG_UNDEF) {
remap &= ~OFF_STATE_MASK;
remap |= rconfig->remap_off << OFF_STATE_SHIFT;
}
if (rconfig->remap_sleep != TWL4030_RESCONFIG_UNDEF) {
remap &= ~SLEEP_STATE_MASK;
remap |= rconfig->remap_sleep << SLEEP_STATE_SHIFT;
}
err = twl_i2c_write_u8(TWL_MODULE_PM_RECEIVER,
remap,
rconfig_addr + REMAP_OFFSET);
if (err < 0) {
pr_err("TWL4030 failed to program remap\n");
return err;
}
return 0;
}
static int load_twl4030_script(struct twl4030_script *tscript,
u8 address)
{
int err;
static int order;
if ((address + tscript->size) > END_OF_SCRIPT) {
pr_err("TWL4030 scripts too big error\n");
return -EINVAL;
}
err = twl4030_write_script(address, tscript->script, tscript->size);
if (err)
goto out;
if (tscript->flags & TWL4030_WRST_SCRIPT) {
err = twl4030_config_warmreset_sequence(address);
if (err)
goto out;
}
if (tscript->flags & TWL4030_WAKEUP12_SCRIPT) {
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, END_OF_SCRIPT,
R_SEQ_ADD_A2S);
if (err)
goto out;
err = twl4030_config_wakeup12_sequence(address);
if (err)
goto out;
order = 1;
}
if (tscript->flags & TWL4030_WAKEUP3_SCRIPT) {
err = twl4030_config_wakeup3_sequence(address);
if (err)
goto out;
}
if (tscript->flags & TWL4030_SLEEP_SCRIPT) {
if (!order)
pr_warning("TWL4030: Bad order of scripts (sleep "\
"script before wakeup) Leads to boot"\
"failure on some boards\n");
err = twl4030_config_sleep_sequence(address);
}
out:
return err;
}
int twl4030_remove_script(u8 flags)
{
int err = 0;
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, TWL4030_PM_MASTER_KEY_CFG1,
TWL4030_PM_MASTER_PROTECT_KEY);
if (err) {
pr_err("twl4030: unable to unlock PROTECT_KEY\n");
return err;
}
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, TWL4030_PM_MASTER_KEY_CFG2,
TWL4030_PM_MASTER_PROTECT_KEY);
if (err) {
pr_err("twl4030: unable to unlock PROTECT_KEY\n");
return err;
}
if (flags & TWL4030_WRST_SCRIPT) {
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, END_OF_SCRIPT,
R_SEQ_ADD_WARM);
if (err)
return err;
}
if (flags & TWL4030_WAKEUP12_SCRIPT) {
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, END_OF_SCRIPT,
R_SEQ_ADD_S2A12);
if (err)
return err;
}
if (flags & TWL4030_WAKEUP3_SCRIPT) {
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, END_OF_SCRIPT,
R_SEQ_ADD_S2A3);
if (err)
return err;
}
if (flags & TWL4030_SLEEP_SCRIPT) {
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, END_OF_SCRIPT,
R_SEQ_ADD_A2S);
if (err)
return err;
}
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, 0,
TWL4030_PM_MASTER_PROTECT_KEY);
if (err)
pr_err("TWL4030 Unable to relock registers\n");
return err;
}
static int
twl4030_power_configure_scripts(const struct twl4030_power_data *pdata)
{
int err;
int i;
u8 address = twl4030_start_script_address;
for (i = 0; i < pdata->num; i++) {
err = load_twl4030_script(pdata->scripts[i], address);
if (err)
return err;
address += pdata->scripts[i]->size;
}
return 0;
}
static void twl4030_patch_rconfig(struct twl4030_resconfig *common,
struct twl4030_resconfig *board)
{
while (common->resource) {
struct twl4030_resconfig *b = board;
while (b->resource) {
if (b->resource == common->resource) {
*common = *b;
break;
}
b++;
}
common++;
}
}
static int
twl4030_power_configure_resources(const struct twl4030_power_data *pdata)
{
struct twl4030_resconfig *resconfig = pdata->resource_config;
struct twl4030_resconfig *boardconf = pdata->board_config;
int err;
if (resconfig) {
if (boardconf)
twl4030_patch_rconfig(resconfig, boardconf);
while (resconfig->resource) {
err = twl4030_configure_resource(resconfig);
if (err)
return err;
resconfig++;
}
}
return 0;
}
void twl4030_power_off(void)
{
int err;
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, PWR_DEVOFF,
TWL4030_PM_MASTER_P1_SW_EVENTS);
if (err)
pr_err("TWL4030 Unable to power off\n");
}
static bool twl4030_power_use_poweroff(const struct twl4030_power_data *pdata,
struct device_node *node)
{
if (pdata && pdata->use_poweroff)
return true;
if (of_property_read_bool(node, "ti,use_poweroff"))
return true;
return false;
}
static int twl4030_power_probe(struct platform_device *pdev)
{
const struct twl4030_power_data *pdata = dev_get_platdata(&pdev->dev);
struct device_node *node = pdev->dev.of_node;
const struct of_device_id *match;
int err = 0;
int err2 = 0;
u8 val;
if (!pdata && !node) {
dev_err(&pdev->dev, "Platform data is missing\n");
return -EINVAL;
}
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, TWL4030_PM_MASTER_KEY_CFG1,
TWL4030_PM_MASTER_PROTECT_KEY);
err |= twl_i2c_write_u8(TWL_MODULE_PM_MASTER,
TWL4030_PM_MASTER_KEY_CFG2,
TWL4030_PM_MASTER_PROTECT_KEY);
if (err) {
pr_err("TWL4030 Unable to unlock registers\n");
return err;
}
match = of_match_device(of_match_ptr(twl4030_power_of_match),
&pdev->dev);
if (match && match->data)
pdata = match->data;
if (pdata) {
err = twl4030_power_configure_scripts(pdata);
if (err) {
pr_err("TWL4030 failed to load scripts\n");
goto relock;
}
err = twl4030_power_configure_resources(pdata);
if (err) {
pr_err("TWL4030 failed to configure resource\n");
goto relock;
}
}
if (twl4030_power_use_poweroff(pdata, node) && !pm_power_off) {
err = twl_i2c_read_u8(TWL_MODULE_PM_MASTER, &val,
TWL4030_PM_MASTER_CFG_P123_TRANSITION);
if (err) {
pr_warning("TWL4030 Unable to read registers\n");
} else if (!(val & SEQ_OFFSYNC)) {
val |= SEQ_OFFSYNC;
err = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, val,
TWL4030_PM_MASTER_CFG_P123_TRANSITION);
if (err) {
pr_err("TWL4030 Unable to setup SEQ_OFFSYNC\n");
goto relock;
}
}
pm_power_off = twl4030_power_off;
}
relock:
err2 = twl_i2c_write_u8(TWL_MODULE_PM_MASTER, 0,
TWL4030_PM_MASTER_PROTECT_KEY);
if (err2) {
pr_err("TWL4030 Unable to relock registers\n");
return err2;
}
return err;
}
static int twl4030_power_remove(struct platform_device *pdev)
{
return 0;
}
