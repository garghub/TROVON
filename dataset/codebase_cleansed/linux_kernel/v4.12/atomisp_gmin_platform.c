const struct atomisp_camera_caps *atomisp_get_default_camera_caps(void)
{
static const struct atomisp_camera_caps caps = {
.sensor_num = 1,
.sensor = {
{ .stream_num = 1, },
},
};
return &caps;
}
const struct atomisp_platform_data *atomisp_get_platform_data(void)
{
return &pdata;
}
static int af_power_ctrl(struct v4l2_subdev *subdev, int flag)
{
struct gmin_subdev *gs = find_gmin_subdev(subdev);
if (gs && gs->v2p8_vcm_on == flag)
return 0;
gs->v2p8_vcm_on = flag;
if (gs->v2p8_vcm_reg) {
if (flag)
return regulator_enable(gs->v2p8_vcm_reg);
else
return regulator_disable(gs->v2p8_vcm_reg);
}
return 0;
}
const struct camera_af_platform_data *camera_get_af_platform_data(void)
{
static struct camera_af_platform_data afpd = {
.power_ctrl = af_power_ctrl,
};
return &afpd;
}
int atomisp_register_i2c_module(struct v4l2_subdev *subdev,
struct camera_sensor_platform_data *plat_data,
enum intel_v4l2_subdev_type type)
{
int i;
struct i2c_board_info *bi;
struct gmin_subdev *gs;
struct i2c_client *client = v4l2_get_subdevdata(subdev);
struct acpi_device *adev;
dev_info(&client->dev, "register atomisp i2c module type %d\n", type);
adev = ACPI_COMPANION(&client->dev);
if (adev)
adev->power.flags.power_resources = 0;
for (i=0; i < MAX_SUBDEVS; i++)
if (!pdata.subdevs[i].type)
break;
if (pdata.subdevs[i].type)
return -ENOMEM;
gs = find_gmin_subdev(subdev);
pdata.subdevs[i].type = type;
pdata.subdevs[i].port = gs->csi_port;
pdata.subdevs[i].subdev = subdev;
pdata.subdevs[i].v4l2_subdev.i2c_adapter_id = client->adapter->nr;
bi = &pdata.subdevs[i].v4l2_subdev.board_info;
memcpy(bi->type, client->name, I2C_NAME_SIZE);
bi->flags = client->flags;
bi->addr = client->addr;
bi->irq = client->irq;
bi->platform_data = plat_data;
return 0;
}
struct v4l2_subdev *atomisp_gmin_find_subdev(struct i2c_adapter *adapter,
struct i2c_board_info *board_info)
{
int i;
for (i=0; i < MAX_SUBDEVS && pdata.subdevs[i].type; i++) {
struct intel_v4l2_subdev_table *sd = &pdata.subdevs[i];
if (sd->v4l2_subdev.i2c_adapter_id == adapter->nr &&
sd->v4l2_subdev.board_info.addr == board_info->addr)
return sd->subdev;
}
return NULL;
}
int atomisp_gmin_remove_subdev(struct v4l2_subdev *sd)
{
int i, j;
if (!sd)
return 0;
for (i = 0; i < MAX_SUBDEVS; i++) {
if (pdata.subdevs[i].subdev == sd) {
for (j = i + 1; j <= MAX_SUBDEVS; j++)
pdata.subdevs[j - 1] = pdata.subdevs[j];
}
if (gmin_subdevs[i].subdev == sd) {
if (gmin_subdevs[i].gpio0)
gpiod_put(gmin_subdevs[i].gpio0);
gmin_subdevs[i].gpio0 = NULL;
if (gmin_subdevs[i].gpio1)
gpiod_put(gmin_subdevs[i].gpio1);
gmin_subdevs[i].gpio1 = NULL;
if (pmic_id == PMIC_REGULATOR) {
regulator_put(gmin_subdevs[i].v1p8_reg);
regulator_put(gmin_subdevs[i].v2p8_reg);
regulator_put(gmin_subdevs[i].v1p2_reg);
regulator_put(gmin_subdevs[i].v2p8_vcm_reg);
}
gmin_subdevs[i].subdev = NULL;
}
}
return 0;
}
static int gmin_platform_init(struct i2c_client *client)
{
return 0;
}
static int gmin_platform_deinit(void)
{
return 0;
}
static struct gmin_subdev *gmin_subdev_add(struct v4l2_subdev *subdev)
{
int i, ret;
struct device *dev;
struct i2c_client *client = v4l2_get_subdevdata(subdev);
if (!pmic_id) {
pmic_id = PMIC_REGULATOR;
}
if (!client)
return NULL;
dev = &client->dev;
for (i=0; i < MAX_SUBDEVS && gmin_subdevs[i].subdev; i++)
;
if (i >= MAX_SUBDEVS)
return NULL;
dev_info(dev,
"gmin: initializing atomisp module subdev data.PMIC ID %d\n",
pmic_id);
gmin_subdevs[i].subdev = subdev;
gmin_subdevs[i].clock_num = gmin_get_var_int(dev, "CamClk", 0);
gmin_subdevs[i].clock_src = gmin_get_var_int(dev, "ClkSrc",
VLV2_CLK_PLL_19P2MHZ);
gmin_subdevs[i].csi_port = gmin_get_var_int(dev, "CsiPort", 0);
gmin_subdevs[i].csi_lanes = gmin_get_var_int(dev, "CsiLanes", 1);
gmin_subdevs[i].gpio0 = gpiod_get_index(dev, NULL, 0, GPIOD_OUT_LOW);
gmin_subdevs[i].gpio1 = gpiod_get_index(dev, NULL, 1, GPIOD_OUT_LOW);
if (!IS_ERR(gmin_subdevs[i].gpio0)) {
ret = gpiod_direction_output(gmin_subdevs[i].gpio0, 0);
if (ret)
dev_err(dev, "gpio0 set output failed: %d\n", ret);
} else {
gmin_subdevs[i].gpio0 = NULL;
}
if (!IS_ERR(gmin_subdevs[i].gpio1)) {
ret = gpiod_direction_output(gmin_subdevs[i].gpio1, 0);
if (ret)
dev_err(dev, "gpio1 set output failed: %d\n", ret);
} else {
gmin_subdevs[i].gpio1 = NULL;
}
if (pmic_id == PMIC_REGULATOR) {
gmin_subdevs[i].v1p8_reg = regulator_get(dev, "V1P8SX");
gmin_subdevs[i].v2p8_reg = regulator_get(dev, "V2P8SX");
gmin_subdevs[i].v1p2_reg = regulator_get(dev, "V1P2A");
gmin_subdevs[i].v2p8_vcm_reg = regulator_get(dev, "VPROG4B");
}
return &gmin_subdevs[i];
}
static struct gmin_subdev *find_gmin_subdev(struct v4l2_subdev *subdev)
{
int i;
for (i=0; i < MAX_SUBDEVS; i++)
if (gmin_subdevs[i].subdev == subdev)
return &gmin_subdevs[i];
return gmin_subdev_add(subdev);
}
static int gmin_gpio0_ctrl(struct v4l2_subdev *subdev, int on)
{
struct gmin_subdev *gs = find_gmin_subdev(subdev);
if (gs && gs->gpio0) {
gpiod_set_value(gs->gpio0, on);
return 0;
}
return -EINVAL;
}
static int gmin_gpio1_ctrl(struct v4l2_subdev *subdev, int on)
{
struct gmin_subdev *gs = find_gmin_subdev(subdev);
if (gs && gs->gpio1) {
gpiod_set_value(gs->gpio1, on);
return 0;
}
return -EINVAL;
}
int gmin_v1p2_ctrl(struct v4l2_subdev *subdev, int on)
{
struct gmin_subdev *gs = find_gmin_subdev(subdev);
if (gs && gs->v1p2_on == on)
return 0;
gs->v1p2_on = on;
if (gs->v1p2_reg) {
if (on)
return regulator_enable(gs->v1p2_reg);
else
return regulator_disable(gs->v1p2_reg);
}
return -EINVAL;
}
int gmin_v1p8_ctrl(struct v4l2_subdev *subdev, int on)
{
struct gmin_subdev *gs = find_gmin_subdev(subdev);
int ret;
if (v1p8_gpio == V1P8_GPIO_UNSET) {
v1p8_gpio = gmin_get_var_int(NULL, "V1P8GPIO", V1P8_GPIO_NONE);
if (v1p8_gpio != V1P8_GPIO_NONE) {
pr_info("atomisp_gmin_platform: 1.8v power on GPIO %d\n",
v1p8_gpio);
ret = gpio_request(v1p8_gpio, "camera_v1p8_en");
if (!ret)
ret = gpio_direction_output(v1p8_gpio, 0);
if (ret)
pr_err("V1P8 GPIO initialization failed\n");
}
}
if (gs && gs->v1p8_on == on)
return 0;
gs->v1p8_on = on;
if (v1p8_gpio >= 0)
gpio_set_value(v1p8_gpio, on);
if (gs->v1p8_reg) {
regulator_set_voltage(gs->v1p8_reg, 1800000, 1800000);
if (on)
return regulator_enable(gs->v1p8_reg);
else
return regulator_disable(gs->v1p8_reg);
}
return -EINVAL;
}
int gmin_v2p8_ctrl(struct v4l2_subdev *subdev, int on)
{
struct gmin_subdev *gs = find_gmin_subdev(subdev);
int ret;
if (v2p8_gpio == V2P8_GPIO_UNSET) {
v2p8_gpio = gmin_get_var_int(NULL, "V2P8GPIO", V2P8_GPIO_NONE);
if (v2p8_gpio != V2P8_GPIO_NONE) {
pr_info("atomisp_gmin_platform: 2.8v power on GPIO %d\n",
v2p8_gpio);
ret = gpio_request(v2p8_gpio, "camera_v2p8");
if (!ret)
ret = gpio_direction_output(v2p8_gpio, 0);
if (ret)
pr_err("V2P8 GPIO initialization failed\n");
}
}
if (gs && gs->v2p8_on == on)
return 0;
gs->v2p8_on = on;
if (v2p8_gpio >= 0)
gpio_set_value(v2p8_gpio, on);
if (gs->v2p8_reg) {
regulator_set_voltage(gs->v2p8_reg, 2900000, 2900000);
if (on)
return regulator_enable(gs->v2p8_reg);
else
return regulator_disable(gs->v2p8_reg);
}
return -EINVAL;
}
int gmin_flisclk_ctrl(struct v4l2_subdev *subdev, int on)
{
int ret = 0;
struct gmin_subdev *gs = find_gmin_subdev(subdev);
if (on)
ret = vlv2_plat_set_clock_freq(gs->clock_num, gs->clock_src);
if (ret)
return ret;
return vlv2_plat_configure_clock(gs->clock_num,
on ? VLV2_CLK_ON : VLV2_CLK_OFF);
}
static int gmin_csi_cfg(struct v4l2_subdev *sd, int flag)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct gmin_subdev *gs = find_gmin_subdev(sd);
if (!client || !gs)
return -ENODEV;
return camera_sensor_csi(sd, gs->csi_port, gs->csi_lanes,
gs->csi_fmt, gs->csi_bayer, flag);
}
static struct camera_vcm_control *gmin_get_vcm_ctrl(struct v4l2_subdev *subdev,
char *camera_module)
{
struct i2c_client *client = v4l2_get_subdevdata(subdev);
struct gmin_subdev *gs = find_gmin_subdev(subdev);
struct camera_vcm_control *vcm;
if (client == NULL || gs == NULL)
return NULL;
if (!camera_module)
return NULL;
mutex_lock(&vcm_lock);
list_for_each_entry(vcm, &vcm_devices, list) {
if (!strcmp(camera_module, vcm->camera_module)) {
mutex_unlock(&vcm_lock);
return vcm;
}
}
mutex_unlock(&vcm_lock);
return NULL;
}
struct camera_sensor_platform_data *gmin_camera_platform_data(
struct v4l2_subdev *subdev,
enum atomisp_input_format csi_format,
enum atomisp_bayer_order csi_bayer)
{
struct gmin_subdev *gs = find_gmin_subdev(subdev);
gs->csi_fmt = csi_format;
gs->csi_bayer = csi_bayer;
return &gmin_plat;
}
int atomisp_gmin_register_vcm_control(struct camera_vcm_control *vcmCtrl)
{
if (!vcmCtrl)
return -EINVAL;
mutex_lock(&vcm_lock);
list_add_tail(&vcmCtrl->list, &vcm_devices);
mutex_unlock(&vcm_lock);
return 0;
}
int gmin_get_config_var(struct device *dev, const char *var, char *out, size_t *out_len)
{
char var8[CFG_VAR_NAME_MAX];
efi_char16_t var16[CFG_VAR_NAME_MAX];
struct efivar_entry *ev;
u32 efiattr_dummy;
int i, j, ret;
unsigned long efilen;
if (dev && ACPI_COMPANION(dev))
dev = &ACPI_COMPANION(dev)->dev;
if (dev)
ret = snprintf(var8, sizeof(var8), "%s_%s", dev_name(dev), var);
else
ret = snprintf(var8, sizeof(var8), "gmin_%s", var);
if (ret < 0 || ret >= sizeof(var8) - 1)
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(hard_vars); i++) {
if (dmi_match(DMI_BOARD_NAME, hard_vars[i].dmi_board_name)) {
for (j = 0; hard_vars[i].vars[j].name; j++) {
size_t vl;
const struct gmin_cfg_var *gv;
gv = &hard_vars[i].vars[j];
vl = strlen(gv->val);
if (strcmp(var8, gv->name))
continue;
if (vl > *out_len - 1)
return -ENOSPC;
memcpy(out, gv->val, min(*out_len, vl+1));
out[*out_len-1] = 0;
*out_len = vl;
return 0;
}
}
}
memset(var16, 0, sizeof(var16));
for (i = 0; i < sizeof(var8) && var8[i]; i++)
var16[i] = var8[i];
if (*out_len > ULONG_MAX)
return -EINVAL;
ev = kzalloc(sizeof(*ev), GFP_KERNEL);
if (!ev)
return -ENOMEM;
memcpy(&ev->var.VariableName, var16, sizeof(var16));
ev->var.VendorGuid = GMIN_CFG_VAR_EFI_GUID;
efilen = *out_len;
ret = efivar_entry_get(ev, &efiattr_dummy, &efilen, out);
kfree(ev);
*out_len = efilen;
if (ret)
dev_warn(dev, "Failed to find gmin variable %s\n", var8);
return ret;
}
int gmin_get_var_int(struct device *dev, const char *var, int def)
{
char val[CFG_VAR_NAME_MAX];
size_t len = sizeof(val);
long result;
int ret;
ret = gmin_get_config_var(dev, var, val, &len);
if (!ret) {
val[len] = 0;
ret = kstrtol(val, 0, &result);
}
return ret ? def : result;
}
int camera_sensor_csi(struct v4l2_subdev *sd, u32 port,
u32 lanes, u32 format, u32 bayer_order, int flag)
{
struct i2c_client *client = v4l2_get_subdevdata(sd);
struct camera_mipi_info *csi = NULL;
if (flag) {
csi = kzalloc(sizeof(*csi), GFP_KERNEL);
if (!csi) {
dev_err(&client->dev, "out of memory\n");
return -ENOMEM;
}
csi->port = port;
csi->num_lanes = lanes;
csi->input_format = format;
csi->raw_bayer_order = bayer_order;
v4l2_set_subdev_hostdata(sd, (void *)csi);
csi->metadata_format = ATOMISP_INPUT_FORMAT_EMBEDDED;
csi->metadata_effective_width = NULL;
dev_info(&client->dev,
"camera pdata: port: %d lanes: %d order: %8.8x\n",
port, lanes, bayer_order);
} else {
csi = v4l2_get_subdev_hostdata(sd);
kfree(csi);
}
return 0;
}
static void isp_pm_cap_fixup(struct pci_dev *dev)
{
dev_info(&dev->dev, "Disabling PCI power management on camera ISP\n");
dev->pm_cap = 0;
}
