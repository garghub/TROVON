static inline int property_enable(struct rockchip_usb2phy *rphy,
const struct usb2phy_reg *reg, bool en)
{
unsigned int val, mask, tmp;
tmp = en ? reg->enable : reg->disable;
mask = GENMASK(reg->bitend, reg->bitstart);
val = (tmp << reg->bitstart) | (mask << BIT_WRITEABLE_SHIFT);
return regmap_write(rphy->grf, reg->offset, val);
}
static inline bool property_enabled(struct rockchip_usb2phy *rphy,
const struct usb2phy_reg *reg)
{
int ret;
unsigned int tmp, orig;
unsigned int mask = GENMASK(reg->bitend, reg->bitstart);
ret = regmap_read(rphy->grf, reg->offset, &orig);
if (ret)
return false;
tmp = (orig & mask) >> reg->bitstart;
return tmp == reg->enable;
}
static int rockchip_usb2phy_clk480m_prepare(struct clk_hw *hw)
{
struct rockchip_usb2phy *rphy =
container_of(hw, struct rockchip_usb2phy, clk480m_hw);
int ret;
if (!property_enabled(rphy, &rphy->phy_cfg->clkout_ctl)) {
ret = property_enable(rphy, &rphy->phy_cfg->clkout_ctl, true);
if (ret)
return ret;
usleep_range(1200, 1300);
}
return 0;
}
static void rockchip_usb2phy_clk480m_unprepare(struct clk_hw *hw)
{
struct rockchip_usb2phy *rphy =
container_of(hw, struct rockchip_usb2phy, clk480m_hw);
property_enable(rphy, &rphy->phy_cfg->clkout_ctl, false);
}
static int rockchip_usb2phy_clk480m_prepared(struct clk_hw *hw)
{
struct rockchip_usb2phy *rphy =
container_of(hw, struct rockchip_usb2phy, clk480m_hw);
return property_enabled(rphy, &rphy->phy_cfg->clkout_ctl);
}
static unsigned long
rockchip_usb2phy_clk480m_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return 480000000;
}
static void rockchip_usb2phy_clk480m_unregister(void *data)
{
struct rockchip_usb2phy *rphy = data;
of_clk_del_provider(rphy->dev->of_node);
clk_unregister(rphy->clk480m);
}
static int
rockchip_usb2phy_clk480m_register(struct rockchip_usb2phy *rphy)
{
struct device_node *node = rphy->dev->of_node;
struct clk_init_data init;
const char *clk_name;
int ret;
init.flags = 0;
init.name = "clk_usbphy_480m";
init.ops = &rockchip_usb2phy_clkout_ops;
of_property_read_string(node, "clock-output-names", &init.name);
if (rphy->clk) {
clk_name = __clk_get_name(rphy->clk);
init.parent_names = &clk_name;
init.num_parents = 1;
} else {
init.parent_names = NULL;
init.num_parents = 0;
}
rphy->clk480m_hw.init = &init;
rphy->clk480m = clk_register(rphy->dev, &rphy->clk480m_hw);
if (IS_ERR(rphy->clk480m)) {
ret = PTR_ERR(rphy->clk480m);
goto err_ret;
}
ret = of_clk_add_provider(node, of_clk_src_simple_get, rphy->clk480m);
if (ret < 0)
goto err_clk_provider;
ret = devm_add_action(rphy->dev, rockchip_usb2phy_clk480m_unregister,
rphy);
if (ret < 0)
goto err_unreg_action;
return 0;
err_unreg_action:
of_clk_del_provider(node);
err_clk_provider:
clk_unregister(rphy->clk480m);
err_ret:
return ret;
}
static int rockchip_usb2phy_extcon_register(struct rockchip_usb2phy *rphy)
{
int ret;
struct device_node *node = rphy->dev->of_node;
struct extcon_dev *edev;
if (of_property_read_bool(node, "extcon")) {
edev = extcon_get_edev_by_phandle(rphy->dev, 0);
if (IS_ERR(edev)) {
if (PTR_ERR(edev) != -EPROBE_DEFER)
dev_err(rphy->dev, "Invalid or missing extcon\n");
return PTR_ERR(edev);
}
} else {
edev = devm_extcon_dev_allocate(rphy->dev,
rockchip_usb2phy_extcon_cable);
if (IS_ERR(edev))
return -ENOMEM;
ret = devm_extcon_dev_register(rphy->dev, edev);
if (ret) {
dev_err(rphy->dev, "failed to register extcon device\n");
return ret;
}
}
rphy->edev = edev;
return 0;
}
static int rockchip_usb2phy_init(struct phy *phy)
{
struct rockchip_usb2phy_port *rport = phy_get_drvdata(phy);
struct rockchip_usb2phy *rphy = dev_get_drvdata(phy->dev.parent);
int ret = 0;
mutex_lock(&rport->mutex);
if (rport->port_id == USB2PHY_PORT_OTG) {
if (rport->mode != USB_DR_MODE_HOST) {
ret = property_enable(rphy,
&rport->port_cfg->bvalid_det_clr,
true);
if (ret)
goto out;
ret = property_enable(rphy,
&rport->port_cfg->bvalid_det_en,
true);
if (ret)
goto out;
schedule_delayed_work(&rport->otg_sm_work,
OTG_SCHEDULE_DELAY);
} else {
dev_dbg(&rport->phy->dev, "mode %d\n", rport->mode);
}
} else if (rport->port_id == USB2PHY_PORT_HOST) {
ret = property_enable(rphy, &rport->port_cfg->ls_det_clr, true);
if (ret)
goto out;
ret = property_enable(rphy, &rport->port_cfg->ls_det_en, true);
if (ret)
goto out;
schedule_delayed_work(&rport->sm_work, SCHEDULE_DELAY);
}
out:
mutex_unlock(&rport->mutex);
return ret;
}
static int rockchip_usb2phy_power_on(struct phy *phy)
{
struct rockchip_usb2phy_port *rport = phy_get_drvdata(phy);
struct rockchip_usb2phy *rphy = dev_get_drvdata(phy->dev.parent);
int ret;
dev_dbg(&rport->phy->dev, "port power on\n");
if (!rport->suspended)
return 0;
ret = clk_prepare_enable(rphy->clk480m);
if (ret)
return ret;
ret = property_enable(rphy, &rport->port_cfg->phy_sus, false);
if (ret)
return ret;
rport->suspended = false;
return 0;
}
static int rockchip_usb2phy_power_off(struct phy *phy)
{
struct rockchip_usb2phy_port *rport = phy_get_drvdata(phy);
struct rockchip_usb2phy *rphy = dev_get_drvdata(phy->dev.parent);
int ret;
dev_dbg(&rport->phy->dev, "port power off\n");
if (rport->suspended)
return 0;
ret = property_enable(rphy, &rport->port_cfg->phy_sus, true);
if (ret)
return ret;
rport->suspended = true;
clk_disable_unprepare(rphy->clk480m);
return 0;
}
static int rockchip_usb2phy_exit(struct phy *phy)
{
struct rockchip_usb2phy_port *rport = phy_get_drvdata(phy);
if (rport->port_id == USB2PHY_PORT_OTG &&
rport->mode != USB_DR_MODE_HOST) {
cancel_delayed_work_sync(&rport->otg_sm_work);
cancel_delayed_work_sync(&rport->chg_work);
} else if (rport->port_id == USB2PHY_PORT_HOST)
cancel_delayed_work_sync(&rport->sm_work);
return 0;
}
static void rockchip_usb2phy_otg_sm_work(struct work_struct *work)
{
struct rockchip_usb2phy_port *rport =
container_of(work, struct rockchip_usb2phy_port,
otg_sm_work.work);
struct rockchip_usb2phy *rphy = dev_get_drvdata(rport->phy->dev.parent);
static unsigned int cable;
unsigned long delay;
bool vbus_attach, sch_work, notify_charger;
if (rport->utmi_avalid)
vbus_attach =
property_enabled(rphy, &rport->port_cfg->utmi_avalid);
else
vbus_attach =
property_enabled(rphy, &rport->port_cfg->utmi_bvalid);
sch_work = false;
notify_charger = false;
delay = OTG_SCHEDULE_DELAY;
dev_dbg(&rport->phy->dev, "%s otg sm work\n",
usb_otg_state_string(rport->state));
switch (rport->state) {
case OTG_STATE_UNDEFINED:
rport->state = OTG_STATE_B_IDLE;
if (!vbus_attach)
rockchip_usb2phy_power_off(rport->phy);
case OTG_STATE_B_IDLE:
if (extcon_get_cable_state_(rphy->edev, EXTCON_USB_HOST) > 0) {
dev_dbg(&rport->phy->dev, "usb otg host connect\n");
rport->state = OTG_STATE_A_HOST;
rockchip_usb2phy_power_on(rport->phy);
return;
} else if (vbus_attach) {
dev_dbg(&rport->phy->dev, "vbus_attach\n");
switch (rphy->chg_state) {
case USB_CHG_STATE_UNDEFINED:
schedule_delayed_work(&rport->chg_work, 0);
return;
case USB_CHG_STATE_DETECTED:
switch (rphy->chg_type) {
case POWER_SUPPLY_TYPE_USB:
dev_dbg(&rport->phy->dev,
"sdp cable is connecetd\n");
rockchip_usb2phy_power_on(rport->phy);
rport->state = OTG_STATE_B_PERIPHERAL;
notify_charger = true;
sch_work = true;
cable = EXTCON_CHG_USB_SDP;
break;
case POWER_SUPPLY_TYPE_USB_DCP:
dev_dbg(&rport->phy->dev,
"dcp cable is connecetd\n");
rockchip_usb2phy_power_off(rport->phy);
notify_charger = true;
sch_work = true;
cable = EXTCON_CHG_USB_DCP;
break;
case POWER_SUPPLY_TYPE_USB_CDP:
dev_dbg(&rport->phy->dev,
"cdp cable is connecetd\n");
rockchip_usb2phy_power_on(rport->phy);
rport->state = OTG_STATE_B_PERIPHERAL;
notify_charger = true;
sch_work = true;
cable = EXTCON_CHG_USB_CDP;
break;
default:
break;
}
break;
default:
break;
}
} else {
notify_charger = true;
rphy->chg_state = USB_CHG_STATE_UNDEFINED;
rphy->chg_type = POWER_SUPPLY_TYPE_UNKNOWN;
}
if (rport->vbus_attached != vbus_attach) {
rport->vbus_attached = vbus_attach;
if (notify_charger && rphy->edev)
extcon_set_cable_state_(rphy->edev,
cable, vbus_attach);
}
break;
case OTG_STATE_B_PERIPHERAL:
if (!vbus_attach) {
dev_dbg(&rport->phy->dev, "usb disconnect\n");
rphy->chg_state = USB_CHG_STATE_UNDEFINED;
rphy->chg_type = POWER_SUPPLY_TYPE_UNKNOWN;
rport->state = OTG_STATE_B_IDLE;
delay = 0;
rockchip_usb2phy_power_off(rport->phy);
}
sch_work = true;
break;
case OTG_STATE_A_HOST:
if (extcon_get_cable_state_(rphy->edev, EXTCON_USB_HOST) == 0) {
dev_dbg(&rport->phy->dev, "usb otg host disconnect\n");
rport->state = OTG_STATE_B_IDLE;
rockchip_usb2phy_power_off(rport->phy);
}
break;
default:
break;
}
if (sch_work)
schedule_delayed_work(&rport->otg_sm_work, delay);
}
static const char *chg_to_string(enum power_supply_type chg_type)
{
switch (chg_type) {
case POWER_SUPPLY_TYPE_USB:
return "USB_SDP_CHARGER";
case POWER_SUPPLY_TYPE_USB_DCP:
return "USB_DCP_CHARGER";
case POWER_SUPPLY_TYPE_USB_CDP:
return "USB_CDP_CHARGER";
default:
return "INVALID_CHARGER";
}
}
static void rockchip_chg_enable_dcd(struct rockchip_usb2phy *rphy,
bool en)
{
property_enable(rphy, &rphy->phy_cfg->chg_det.rdm_pdwn_en, en);
property_enable(rphy, &rphy->phy_cfg->chg_det.idp_src_en, en);
}
static void rockchip_chg_enable_primary_det(struct rockchip_usb2phy *rphy,
bool en)
{
property_enable(rphy, &rphy->phy_cfg->chg_det.vdp_src_en, en);
property_enable(rphy, &rphy->phy_cfg->chg_det.idm_sink_en, en);
}
static void rockchip_chg_enable_secondary_det(struct rockchip_usb2phy *rphy,
bool en)
{
property_enable(rphy, &rphy->phy_cfg->chg_det.vdm_src_en, en);
property_enable(rphy, &rphy->phy_cfg->chg_det.idp_sink_en, en);
}
static void rockchip_chg_detect_work(struct work_struct *work)
{
struct rockchip_usb2phy_port *rport =
container_of(work, struct rockchip_usb2phy_port, chg_work.work);
struct rockchip_usb2phy *rphy = dev_get_drvdata(rport->phy->dev.parent);
bool is_dcd, tmout, vout;
unsigned long delay;
dev_dbg(&rport->phy->dev, "chg detection work state = %d\n",
rphy->chg_state);
switch (rphy->chg_state) {
case USB_CHG_STATE_UNDEFINED:
if (!rport->suspended)
rockchip_usb2phy_power_off(rport->phy);
property_enable(rphy, &rphy->phy_cfg->chg_det.opmode, false);
rockchip_chg_enable_dcd(rphy, true);
rphy->chg_state = USB_CHG_STATE_WAIT_FOR_DCD;
rphy->dcd_retries = 0;
delay = CHG_DCD_POLL_TIME;
break;
case USB_CHG_STATE_WAIT_FOR_DCD:
is_dcd = property_enabled(rphy, &rphy->phy_cfg->chg_det.dp_det);
tmout = ++rphy->dcd_retries == CHG_DCD_MAX_RETRIES;
if (is_dcd || tmout) {
rockchip_chg_enable_dcd(rphy, false);
rockchip_chg_enable_primary_det(rphy, true);
delay = CHG_PRIMARY_DET_TIME;
rphy->chg_state = USB_CHG_STATE_DCD_DONE;
} else {
delay = CHG_DCD_POLL_TIME;
}
break;
case USB_CHG_STATE_DCD_DONE:
vout = property_enabled(rphy, &rphy->phy_cfg->chg_det.cp_det);
rockchip_chg_enable_primary_det(rphy, false);
if (vout) {
rockchip_chg_enable_secondary_det(rphy, true);
delay = CHG_SECONDARY_DET_TIME;
rphy->chg_state = USB_CHG_STATE_PRIMARY_DONE;
} else {
if (rphy->dcd_retries == CHG_DCD_MAX_RETRIES) {
rphy->chg_type = POWER_SUPPLY_TYPE_USB_DCP;
rphy->chg_state = USB_CHG_STATE_DETECTED;
delay = 0;
} else {
rphy->chg_type = POWER_SUPPLY_TYPE_USB;
rphy->chg_state = USB_CHG_STATE_DETECTED;
delay = 0;
}
}
break;
case USB_CHG_STATE_PRIMARY_DONE:
vout = property_enabled(rphy, &rphy->phy_cfg->chg_det.dcp_det);
rockchip_chg_enable_secondary_det(rphy, false);
if (vout)
rphy->chg_type = POWER_SUPPLY_TYPE_USB_DCP;
else
rphy->chg_type = POWER_SUPPLY_TYPE_USB_CDP;
case USB_CHG_STATE_SECONDARY_DONE:
rphy->chg_state = USB_CHG_STATE_DETECTED;
delay = 0;
case USB_CHG_STATE_DETECTED:
property_enable(rphy, &rphy->phy_cfg->chg_det.opmode, true);
rockchip_usb2phy_otg_sm_work(&rport->otg_sm_work.work);
dev_info(&rport->phy->dev, "charger = %s\n",
chg_to_string(rphy->chg_type));
return;
default:
return;
}
schedule_delayed_work(&rport->chg_work, delay);
}
static void rockchip_usb2phy_sm_work(struct work_struct *work)
{
struct rockchip_usb2phy_port *rport =
container_of(work, struct rockchip_usb2phy_port, sm_work.work);
struct rockchip_usb2phy *rphy = dev_get_drvdata(rport->phy->dev.parent);
unsigned int sh = rport->port_cfg->utmi_hstdet.bitend -
rport->port_cfg->utmi_hstdet.bitstart + 1;
unsigned int ul, uhd, state;
unsigned int ul_mask, uhd_mask;
int ret;
mutex_lock(&rport->mutex);
ret = regmap_read(rphy->grf, rport->port_cfg->utmi_ls.offset, &ul);
if (ret < 0)
goto next_schedule;
ret = regmap_read(rphy->grf, rport->port_cfg->utmi_hstdet.offset,
&uhd);
if (ret < 0)
goto next_schedule;
uhd_mask = GENMASK(rport->port_cfg->utmi_hstdet.bitend,
rport->port_cfg->utmi_hstdet.bitstart);
ul_mask = GENMASK(rport->port_cfg->utmi_ls.bitend,
rport->port_cfg->utmi_ls.bitstart);
state = ((uhd & uhd_mask) >> rport->port_cfg->utmi_hstdet.bitstart) |
(((ul & ul_mask) >> rport->port_cfg->utmi_ls.bitstart) << sh);
switch (state) {
case PHY_STATE_HS_ONLINE:
dev_dbg(&rport->phy->dev, "HS online\n");
break;
case PHY_STATE_FS_LS_ONLINE:
if (!rport->suspended) {
dev_dbg(&rport->phy->dev, "FS/LS online\n");
break;
}
case PHY_STATE_CONNECT:
if (rport->suspended) {
dev_dbg(&rport->phy->dev, "Connected\n");
rockchip_usb2phy_power_on(rport->phy);
rport->suspended = false;
} else {
dev_dbg(&rport->phy->dev, "FS/LS online\n");
}
break;
case PHY_STATE_DISCONNECT:
if (!rport->suspended) {
dev_dbg(&rport->phy->dev, "Disconnected\n");
rockchip_usb2phy_power_off(rport->phy);
rport->suspended = true;
}
property_enable(rphy, &rport->port_cfg->ls_det_clr, true);
property_enable(rphy, &rport->port_cfg->ls_det_en, true);
mutex_unlock(&rport->mutex);
return;
default:
dev_dbg(&rport->phy->dev, "unknown phy state\n");
break;
}
next_schedule:
mutex_unlock(&rport->mutex);
schedule_delayed_work(&rport->sm_work, SCHEDULE_DELAY);
}
static irqreturn_t rockchip_usb2phy_linestate_irq(int irq, void *data)
{
struct rockchip_usb2phy_port *rport = data;
struct rockchip_usb2phy *rphy = dev_get_drvdata(rport->phy->dev.parent);
if (!property_enabled(rphy, &rport->port_cfg->ls_det_st))
return IRQ_NONE;
mutex_lock(&rport->mutex);
property_enable(rphy, &rport->port_cfg->ls_det_en, false);
property_enable(rphy, &rport->port_cfg->ls_det_clr, true);
mutex_unlock(&rport->mutex);
if (rport->suspended && rport->port_id == USB2PHY_PORT_HOST)
rockchip_usb2phy_sm_work(&rport->sm_work.work);
return IRQ_HANDLED;
}
static irqreturn_t rockchip_usb2phy_bvalid_irq(int irq, void *data)
{
struct rockchip_usb2phy_port *rport = data;
struct rockchip_usb2phy *rphy = dev_get_drvdata(rport->phy->dev.parent);
if (!property_enabled(rphy, &rport->port_cfg->bvalid_det_st))
return IRQ_NONE;
mutex_lock(&rport->mutex);
property_enable(rphy, &rport->port_cfg->bvalid_det_clr, true);
mutex_unlock(&rport->mutex);
rockchip_usb2phy_otg_sm_work(&rport->otg_sm_work.work);
return IRQ_HANDLED;
}
static int rockchip_usb2phy_host_port_init(struct rockchip_usb2phy *rphy,
struct rockchip_usb2phy_port *rport,
struct device_node *child_np)
{
int ret;
rport->port_id = USB2PHY_PORT_HOST;
rport->port_cfg = &rphy->phy_cfg->port_cfgs[USB2PHY_PORT_HOST];
rport->suspended = true;
mutex_init(&rport->mutex);
INIT_DELAYED_WORK(&rport->sm_work, rockchip_usb2phy_sm_work);
rport->ls_irq = of_irq_get_byname(child_np, "linestate");
if (rport->ls_irq < 0) {
dev_err(rphy->dev, "no linestate irq provided\n");
return rport->ls_irq;
}
ret = devm_request_threaded_irq(rphy->dev, rport->ls_irq, NULL,
rockchip_usb2phy_linestate_irq,
IRQF_ONESHOT,
"rockchip_usb2phy", rport);
if (ret) {
dev_err(rphy->dev, "failed to request linestate irq handle\n");
return ret;
}
return 0;
}
static int rockchip_otg_event(struct notifier_block *nb,
unsigned long event, void *ptr)
{
struct rockchip_usb2phy_port *rport =
container_of(nb, struct rockchip_usb2phy_port, event_nb);
schedule_delayed_work(&rport->otg_sm_work, OTG_SCHEDULE_DELAY);
return NOTIFY_DONE;
}
static int rockchip_usb2phy_otg_port_init(struct rockchip_usb2phy *rphy,
struct rockchip_usb2phy_port *rport,
struct device_node *child_np)
{
int ret;
rport->port_id = USB2PHY_PORT_OTG;
rport->port_cfg = &rphy->phy_cfg->port_cfgs[USB2PHY_PORT_OTG];
rport->state = OTG_STATE_UNDEFINED;
rport->suspended = true;
rport->vbus_attached = false;
mutex_init(&rport->mutex);
rport->mode = of_usb_get_dr_mode_by_phy(child_np, -1);
if (rport->mode == USB_DR_MODE_HOST) {
ret = 0;
goto out;
}
INIT_DELAYED_WORK(&rport->chg_work, rockchip_chg_detect_work);
INIT_DELAYED_WORK(&rport->otg_sm_work, rockchip_usb2phy_otg_sm_work);
rport->utmi_avalid =
of_property_read_bool(child_np, "rockchip,utmi-avalid");
rport->bvalid_irq = of_irq_get_byname(child_np, "otg-bvalid");
if (rport->bvalid_irq < 0) {
dev_err(rphy->dev, "no vbus valid irq provided\n");
ret = rport->bvalid_irq;
goto out;
}
ret = devm_request_threaded_irq(rphy->dev, rport->bvalid_irq, NULL,
rockchip_usb2phy_bvalid_irq,
IRQF_ONESHOT,
"rockchip_usb2phy_bvalid", rport);
if (ret) {
dev_err(rphy->dev, "failed to request otg-bvalid irq handle\n");
goto out;
}
if (!IS_ERR(rphy->edev)) {
rport->event_nb.notifier_call = rockchip_otg_event;
ret = extcon_register_notifier(rphy->edev, EXTCON_USB_HOST,
&rport->event_nb);
if (ret)
dev_err(rphy->dev, "register USB HOST notifier failed\n");
}
out:
return ret;
}
static int rockchip_usb2phy_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct device_node *child_np;
struct phy_provider *provider;
struct rockchip_usb2phy *rphy;
const struct rockchip_usb2phy_cfg *phy_cfgs;
const struct of_device_id *match;
unsigned int reg;
int index, ret;
rphy = devm_kzalloc(dev, sizeof(*rphy), GFP_KERNEL);
if (!rphy)
return -ENOMEM;
match = of_match_device(dev->driver->of_match_table, dev);
if (!match || !match->data) {
dev_err(dev, "phy configs are not assigned!\n");
return -EINVAL;
}
if (!dev->parent || !dev->parent->of_node)
return -EINVAL;
rphy->grf = syscon_node_to_regmap(dev->parent->of_node);
if (IS_ERR(rphy->grf))
return PTR_ERR(rphy->grf);
if (of_property_read_u32(np, "reg", &reg)) {
dev_err(dev, "the reg property is not assigned in %s node\n",
np->name);
return -EINVAL;
}
rphy->dev = dev;
phy_cfgs = match->data;
rphy->chg_state = USB_CHG_STATE_UNDEFINED;
rphy->chg_type = POWER_SUPPLY_TYPE_UNKNOWN;
platform_set_drvdata(pdev, rphy);
ret = rockchip_usb2phy_extcon_register(rphy);
if (ret)
return ret;
index = 0;
while (phy_cfgs[index].reg) {
if (phy_cfgs[index].reg == reg) {
rphy->phy_cfg = &phy_cfgs[index];
break;
}
++index;
}
if (!rphy->phy_cfg) {
dev_err(dev, "no phy-config can be matched with %s node\n",
np->name);
return -EINVAL;
}
rphy->clk = of_clk_get_by_name(np, "phyclk");
if (!IS_ERR(rphy->clk)) {
clk_prepare_enable(rphy->clk);
} else {
dev_info(&pdev->dev, "no phyclk specified\n");
rphy->clk = NULL;
}
ret = rockchip_usb2phy_clk480m_register(rphy);
if (ret) {
dev_err(dev, "failed to register 480m output clock\n");
goto disable_clks;
}
index = 0;
for_each_available_child_of_node(np, child_np) {
struct rockchip_usb2phy_port *rport = &rphy->ports[index];
struct phy *phy;
if (of_node_cmp(child_np->name, "host-port") &&
of_node_cmp(child_np->name, "otg-port"))
goto next_child;
phy = devm_phy_create(dev, child_np, &rockchip_usb2phy_ops);
if (IS_ERR(phy)) {
dev_err(dev, "failed to create phy\n");
ret = PTR_ERR(phy);
goto put_child;
}
rport->phy = phy;
phy_set_drvdata(rport->phy, rport);
if (!of_node_cmp(child_np->name, "host-port")) {
ret = rockchip_usb2phy_host_port_init(rphy, rport,
child_np);
if (ret)
goto put_child;
} else {
ret = rockchip_usb2phy_otg_port_init(rphy, rport,
child_np);
if (ret)
goto put_child;
}
next_child:
if (++index >= rphy->phy_cfg->num_ports)
break;
}
provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
return PTR_ERR_OR_ZERO(provider);
put_child:
of_node_put(child_np);
disable_clks:
if (rphy->clk) {
clk_disable_unprepare(rphy->clk);
clk_put(rphy->clk);
}
return ret;
}
