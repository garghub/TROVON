static inline struct ab8500_usb *phy_to_ab(struct usb_phy *x)
{
return container_of(x, struct ab8500_usb, phy);
}
static void ab8500_usb_wd_workaround(struct ab8500_usb *ab)
{
abx500_set_register_interruptible(ab->dev,
AB8500_SYS_CTRL2_BLOCK,
AB8500_MAIN_WD_CTRL_REG,
AB8500_BIT_WD_CTRL_ENABLE);
udelay(AB8500_WD_KICK_DELAY_US);
abx500_set_register_interruptible(ab->dev,
AB8500_SYS_CTRL2_BLOCK,
AB8500_MAIN_WD_CTRL_REG,
(AB8500_BIT_WD_CTRL_ENABLE
| AB8500_BIT_WD_CTRL_KICK));
udelay(AB8500_WD_V11_DISABLE_DELAY_US);
abx500_set_register_interruptible(ab->dev,
AB8500_SYS_CTRL2_BLOCK,
AB8500_MAIN_WD_CTRL_REG,
0);
}
static void ab8500_usb_regulator_enable(struct ab8500_usb *ab)
{
int ret, volt;
ret = regulator_enable(ab->v_ape);
if (ret)
dev_err(ab->dev, "Failed to enable v-ape\n");
if (ab->flags & AB8500_USB_FLAG_REGULATOR_SET_VOLTAGE) {
ab->saved_v_ulpi = regulator_get_voltage(ab->v_ulpi);
if (ab->saved_v_ulpi < 0)
dev_err(ab->dev, "Failed to get v_ulpi voltage\n");
ret = regulator_set_voltage(ab->v_ulpi, 1300000, 1350000);
if (ret < 0)
dev_err(ab->dev, "Failed to set the Vintcore to 1.3V, ret=%d\n",
ret);
ret = regulator_set_optimum_mode(ab->v_ulpi, 28000);
if (ret < 0)
dev_err(ab->dev, "Failed to set optimum mode (ret=%d)\n",
ret);
}
ret = regulator_enable(ab->v_ulpi);
if (ret)
dev_err(ab->dev, "Failed to enable vddulpivio18\n");
if (ab->flags & AB8500_USB_FLAG_REGULATOR_SET_VOLTAGE) {
volt = regulator_get_voltage(ab->v_ulpi);
if ((volt != 1300000) && (volt != 1350000))
dev_err(ab->dev, "Vintcore is not set to 1.3V volt=%d\n",
volt);
}
ret = regulator_enable(ab->v_musb);
if (ret)
dev_err(ab->dev, "Failed to enable musb_1v8\n");
}
static void ab8500_usb_regulator_disable(struct ab8500_usb *ab)
{
int ret;
regulator_disable(ab->v_musb);
regulator_disable(ab->v_ulpi);
if (ab->flags & AB8500_USB_FLAG_REGULATOR_SET_VOLTAGE) {
if (ab->saved_v_ulpi > 0) {
ret = regulator_set_voltage(ab->v_ulpi,
ab->saved_v_ulpi, ab->saved_v_ulpi);
if (ret < 0)
dev_err(ab->dev, "Failed to set the Vintcore to %duV, ret=%d\n",
ab->saved_v_ulpi, ret);
}
ret = regulator_set_optimum_mode(ab->v_ulpi, 0);
if (ret < 0)
dev_err(ab->dev, "Failed to set optimum mode (ret=%d)\n",
ret);
}
regulator_disable(ab->v_ape);
}
static void ab8500_usb_wd_linkstatus(struct ab8500_usb *ab, u8 bit)
{
if (is_ab8500_2p0(ab->ab8500)) {
abx500_mask_and_set_register_interruptible(ab->dev,
AB8500_USB, AB8500_USB_PHY_CTRL_REG,
bit, bit);
udelay(AB8500_V20_31952_DISABLE_DELAY_US);
}
}
static void ab8500_usb_phy_enable(struct ab8500_usb *ab, bool sel_host)
{
u8 bit;
bit = sel_host ? AB8500_BIT_PHY_CTRL_HOST_EN :
AB8500_BIT_PHY_CTRL_DEVICE_EN;
ab->pinctrl = pinctrl_get_select(ab->dev, PINCTRL_STATE_DEFAULT);
if (IS_ERR(ab->pinctrl))
dev_err(ab->dev, "could not get/set default pinstate\n");
if (clk_prepare_enable(ab->sysclk))
dev_err(ab->dev, "can't prepare/enable clock\n");
ab8500_usb_regulator_enable(ab);
abx500_mask_and_set_register_interruptible(ab->dev,
AB8500_USB, AB8500_USB_PHY_CTRL_REG,
bit, bit);
if (ab->flags & AB8500_USB_FLAG_USE_VBUS_HOST_QUIRK) {
if (sel_host)
abx500_set_register_interruptible(ab->dev,
AB8500_USB, AB8540_USB_OTG_CTL_REG,
AB8540_BIT_OTG_CTL_VBUS_VALID_ENA |
AB8540_BIT_OTG_CTL_ID_HOST_ENA |
AB8540_BIT_OTG_CTL_ID_DEV_ENA);
}
}
static void ab8500_usb_phy_disable(struct ab8500_usb *ab, bool sel_host)
{
u8 bit;
bit = sel_host ? AB8500_BIT_PHY_CTRL_HOST_EN :
AB8500_BIT_PHY_CTRL_DEVICE_EN;
ab8500_usb_wd_linkstatus(ab, bit);
abx500_mask_and_set_register_interruptible(ab->dev,
AB8500_USB, AB8500_USB_PHY_CTRL_REG,
bit, 0);
ab8500_usb_wd_workaround(ab);
clk_disable_unprepare(ab->sysclk);
ab8500_usb_regulator_disable(ab);
if (!IS_ERR(ab->pinctrl)) {
ab->pins_sleep = pinctrl_lookup_state(ab->pinctrl,
PINCTRL_STATE_SLEEP);
if (IS_ERR(ab->pins_sleep))
dev_dbg(ab->dev, "could not get sleep pinstate\n");
else if (pinctrl_select_state(ab->pinctrl, ab->pins_sleep))
dev_err(ab->dev, "could not set pins to sleep state\n");
pinctrl_put(ab->pinctrl);
}
}
static int ab9540_usb_link_status_update(struct ab8500_usb *ab,
enum ab9540_usb_link_status lsts)
{
enum ux500_musb_vbus_id_status event = 0;
dev_dbg(ab->dev, "ab9540_usb_link_status_update %d\n", lsts);
if (ab->previous_link_status_state == USB_LINK_HM_IDGND_9540 &&
(lsts == USB_LINK_STD_HOST_C_NS_9540 ||
lsts == USB_LINK_STD_HOST_NC_9540))
return 0;
if (ab->previous_link_status_state == USB_LINK_ACA_RID_A_9540 &&
(lsts == USB_LINK_STD_HOST_NC_9540))
return 0;
ab->previous_link_status_state = lsts;
switch (lsts) {
case USB_LINK_ACA_RID_B_9540:
event = UX500_MUSB_RIDB;
case USB_LINK_NOT_CONFIGURED_9540:
case USB_LINK_RESERVED0_9540:
case USB_LINK_RESERVED1_9540:
case USB_LINK_RESERVED2_9540:
case USB_LINK_RESERVED3_9540:
if (ab->mode == USB_PERIPHERAL)
atomic_notifier_call_chain(&ab->phy.notifier,
UX500_MUSB_CLEAN, &ab->vbus_draw);
ab->mode = USB_IDLE;
ab->phy.otg->default_a = false;
ab->vbus_draw = 0;
if (event != UX500_MUSB_RIDB)
event = UX500_MUSB_NONE;
ab->phy.state = OTG_STATE_B_IDLE;
break;
case USB_LINK_ACA_RID_C_NM_9540:
event = UX500_MUSB_RIDC;
case USB_LINK_STD_HOST_NC_9540:
case USB_LINK_STD_HOST_C_NS_9540:
case USB_LINK_STD_HOST_C_S_9540:
case USB_LINK_CDP_9540:
if (ab->mode == USB_HOST) {
ab->mode = USB_PERIPHERAL;
ab8500_usb_host_phy_dis(ab);
ab8500_usb_peri_phy_en(ab);
atomic_notifier_call_chain(&ab->phy.notifier,
UX500_MUSB_PREPARE, &ab->vbus_draw);
}
if (ab->mode == USB_IDLE) {
ab->mode = USB_PERIPHERAL;
ab8500_usb_peri_phy_en(ab);
atomic_notifier_call_chain(&ab->phy.notifier,
UX500_MUSB_PREPARE, &ab->vbus_draw);
}
if (event != UX500_MUSB_RIDC)
event = UX500_MUSB_VBUS;
break;
case USB_LINK_ACA_RID_A_9540:
event = UX500_MUSB_RIDA;
case USB_LINK_HM_IDGND_9540:
case USB_LINK_STD_UPSTREAM_9540:
if (ab->mode == USB_PERIPHERAL) {
ab->mode = USB_HOST;
ab8500_usb_peri_phy_dis(ab);
ab8500_usb_host_phy_en(ab);
atomic_notifier_call_chain(&ab->phy.notifier,
UX500_MUSB_PREPARE, &ab->vbus_draw);
}
if (ab->mode == USB_IDLE) {
ab->mode = USB_HOST;
ab8500_usb_host_phy_en(ab);
atomic_notifier_call_chain(&ab->phy.notifier,
UX500_MUSB_PREPARE, &ab->vbus_draw);
}
ab->phy.otg->default_a = true;
if (event != UX500_MUSB_RIDA)
event = UX500_MUSB_ID;
atomic_notifier_call_chain(&ab->phy.notifier,
event, &ab->vbus_draw);
break;
case USB_LINK_DEDICATED_CHG_9540:
ab->mode = USB_DEDICATED_CHG;
event = UX500_MUSB_CHARGER;
atomic_notifier_call_chain(&ab->phy.notifier,
event, &ab->vbus_draw);
break;
case USB_LINK_PHYEN_NO_VBUS_NO_IDGND_9540:
case USB_LINK_STD_UPSTREAM_NO_IDGNG_VBUS_9540:
if (!(is_ab9540_2p0_or_earlier(ab->ab8500))) {
event = UX500_MUSB_NONE;
if (ab->mode == USB_HOST) {
ab->phy.otg->default_a = false;
ab->vbus_draw = 0;
atomic_notifier_call_chain(&ab->phy.notifier,
event, &ab->vbus_draw);
ab8500_usb_host_phy_dis(ab);
ab->mode = USB_IDLE;
}
if (ab->mode == USB_PERIPHERAL) {
atomic_notifier_call_chain(&ab->phy.notifier,
event, &ab->vbus_draw);
ab8500_usb_peri_phy_dis(ab);
atomic_notifier_call_chain(&ab->phy.notifier,
UX500_MUSB_CLEAN,
&ab->vbus_draw);
ab->mode = USB_IDLE;
ab->phy.otg->default_a = false;
ab->vbus_draw = 0;
}
}
break;
default:
break;
}
return 0;
}
static int ab8540_usb_link_status_update(struct ab8500_usb *ab,
enum ab8540_usb_link_status lsts)
{
enum ux500_musb_vbus_id_status event = 0;
dev_dbg(ab->dev, "ab8540_usb_link_status_update %d\n", lsts);
if (ab->enabled_charging_detection) {
abx500_mask_and_set_register_interruptible(ab->dev,
AB8500_USB, AB8540_VBUS_CTRL_REG,
AB8540_BIT_VBUS_CTRL_CHARG_DET_ENA, 0x00);
ab->enabled_charging_detection = false;
}
if (ab->previous_link_status_state == USB_LINK_HM_IDGND_8540 &&
(lsts == USB_LINK_STD_HOST_C_NS_8540 ||
lsts == USB_LINK_STD_HOST_NC_8540))
return 0;
if (ab->previous_link_status_state == USB_LINK_ACA_RID_A_8540 &&
(lsts == USB_LINK_STD_HOST_NC_8540))
return 0;
ab->previous_link_status_state = lsts;
switch (lsts) {
case USB_LINK_ACA_RID_B_8540:
event = UX500_MUSB_RIDB;
case USB_LINK_NOT_CONFIGURED_8540:
case USB_LINK_RESERVED0_8540:
case USB_LINK_RESERVED1_8540:
case USB_LINK_RESERVED2_8540:
case USB_LINK_RESERVED3_8540:
ab->mode = USB_IDLE;
ab->phy.otg->default_a = false;
ab->vbus_draw = 0;
if (event != UX500_MUSB_RIDB)
event = UX500_MUSB_NONE;
ab->phy.state = OTG_STATE_B_IDLE;
break;
case USB_LINK_ACA_RID_C_NM_8540:
event = UX500_MUSB_RIDC;
case USB_LINK_STD_HOST_NC_8540:
case USB_LINK_STD_HOST_C_NS_8540:
case USB_LINK_STD_HOST_C_S_8540:
case USB_LINK_CDP_8540:
if (ab->mode == USB_IDLE) {
ab->mode = USB_PERIPHERAL;
ab8500_usb_peri_phy_en(ab);
atomic_notifier_call_chain(&ab->phy.notifier,
UX500_MUSB_PREPARE, &ab->vbus_draw);
}
if (event != UX500_MUSB_RIDC)
event = UX500_MUSB_VBUS;
break;
case USB_LINK_ACA_RID_A_8540:
case USB_LINK_ACA_DOCK_CHGR_8540:
event = UX500_MUSB_RIDA;
case USB_LINK_HM_IDGND_8540:
case USB_LINK_STD_UPSTREAM_8540:
if (ab->mode == USB_IDLE) {
ab->mode = USB_HOST;
ab8500_usb_host_phy_en(ab);
atomic_notifier_call_chain(&ab->phy.notifier,
UX500_MUSB_PREPARE, &ab->vbus_draw);
}
ab->phy.otg->default_a = true;
if (event != UX500_MUSB_RIDA)
event = UX500_MUSB_ID;
atomic_notifier_call_chain(&ab->phy.notifier,
event, &ab->vbus_draw);
break;
case USB_LINK_DEDICATED_CHG_8540:
ab->mode = USB_DEDICATED_CHG;
event = UX500_MUSB_CHARGER;
atomic_notifier_call_chain(&ab->phy.notifier,
event, &ab->vbus_draw);
break;
case USB_LINK_PHYEN_NO_VBUS_NO_IDGND_8540:
case USB_LINK_STD_UPSTREAM_NO_IDGNG_VBUS_8540:
event = UX500_MUSB_NONE;
if (ab->mode == USB_HOST) {
ab->phy.otg->default_a = false;
ab->vbus_draw = 0;
atomic_notifier_call_chain(&ab->phy.notifier,
event, &ab->vbus_draw);
ab8500_usb_host_phy_dis(ab);
ab->mode = USB_IDLE;
}
if (ab->mode == USB_PERIPHERAL) {
atomic_notifier_call_chain(&ab->phy.notifier,
event, &ab->vbus_draw);
ab8500_usb_peri_phy_dis(ab);
atomic_notifier_call_chain(&ab->phy.notifier,
UX500_MUSB_CLEAN, &ab->vbus_draw);
ab->mode = USB_IDLE;
ab->phy.otg->default_a = false;
ab->vbus_draw = 0;
}
break;
default:
event = UX500_MUSB_NONE;
break;
}
return 0;
}
static int ab8505_usb_link_status_update(struct ab8500_usb *ab,
enum ab8505_usb_link_status lsts)
{
enum ux500_musb_vbus_id_status event = 0;
dev_dbg(ab->dev, "ab8505_usb_link_status_update %d\n", lsts);
if (ab->previous_link_status_state == USB_LINK_ACA_RID_A_8505 &&
(lsts == USB_LINK_STD_HOST_NC_8505))
return 0;
ab->previous_link_status_state = lsts;
switch (lsts) {
case USB_LINK_ACA_RID_B_8505:
event = UX500_MUSB_RIDB;
case USB_LINK_NOT_CONFIGURED_8505:
case USB_LINK_RESERVED0_8505:
case USB_LINK_RESERVED1_8505:
case USB_LINK_RESERVED2_8505:
case USB_LINK_RESERVED3_8505:
ab->mode = USB_IDLE;
ab->phy.otg->default_a = false;
ab->vbus_draw = 0;
if (event != UX500_MUSB_RIDB)
event = UX500_MUSB_NONE;
ab->phy.state = OTG_STATE_B_IDLE;
break;
case USB_LINK_ACA_RID_C_NM_8505:
event = UX500_MUSB_RIDC;
case USB_LINK_STD_HOST_NC_8505:
case USB_LINK_STD_HOST_C_NS_8505:
case USB_LINK_STD_HOST_C_S_8505:
case USB_LINK_CDP_8505:
if (ab->mode == USB_IDLE) {
ab->mode = USB_PERIPHERAL;
ab8500_usb_peri_phy_en(ab);
atomic_notifier_call_chain(&ab->phy.notifier,
UX500_MUSB_PREPARE, &ab->vbus_draw);
}
if (event != UX500_MUSB_RIDC)
event = UX500_MUSB_VBUS;
break;
case USB_LINK_ACA_RID_A_8505:
case USB_LINK_ACA_DOCK_CHGR_8505:
event = UX500_MUSB_RIDA;
case USB_LINK_HM_IDGND_8505:
if (ab->mode == USB_IDLE) {
ab->mode = USB_HOST;
ab8500_usb_host_phy_en(ab);
atomic_notifier_call_chain(&ab->phy.notifier,
UX500_MUSB_PREPARE, &ab->vbus_draw);
}
ab->phy.otg->default_a = true;
if (event != UX500_MUSB_RIDA)
event = UX500_MUSB_ID;
atomic_notifier_call_chain(&ab->phy.notifier,
event, &ab->vbus_draw);
break;
case USB_LINK_DEDICATED_CHG_8505:
ab->mode = USB_DEDICATED_CHG;
event = UX500_MUSB_CHARGER;
atomic_notifier_call_chain(&ab->phy.notifier,
event, &ab->vbus_draw);
break;
default:
break;
}
return 0;
}
static int ab8500_usb_link_status_update(struct ab8500_usb *ab,
enum ab8500_usb_link_status lsts)
{
enum ux500_musb_vbus_id_status event = 0;
dev_dbg(ab->dev, "ab8500_usb_link_status_update %d\n", lsts);
if (ab->previous_link_status_state == USB_LINK_HM_IDGND_8500 &&
(lsts == USB_LINK_STD_HOST_C_NS_8500 ||
lsts == USB_LINK_STD_HOST_NC_8500))
return 0;
if (ab->previous_link_status_state == USB_LINK_ACA_RID_A_8500 &&
lsts == USB_LINK_STD_HOST_NC_8500)
return 0;
ab->previous_link_status_state = lsts;
switch (lsts) {
case USB_LINK_ACA_RID_B_8500:
event = UX500_MUSB_RIDB;
case USB_LINK_NOT_CONFIGURED_8500:
case USB_LINK_NOT_VALID_LINK_8500:
ab->mode = USB_IDLE;
ab->phy.otg->default_a = false;
ab->vbus_draw = 0;
if (event != UX500_MUSB_RIDB)
event = UX500_MUSB_NONE;
ab->phy.state = OTG_STATE_B_IDLE;
break;
case USB_LINK_ACA_RID_C_NM_8500:
case USB_LINK_ACA_RID_C_HS_8500:
case USB_LINK_ACA_RID_C_HS_CHIRP_8500:
event = UX500_MUSB_RIDC;
case USB_LINK_STD_HOST_NC_8500:
case USB_LINK_STD_HOST_C_NS_8500:
case USB_LINK_STD_HOST_C_S_8500:
case USB_LINK_HOST_CHG_NM_8500:
case USB_LINK_HOST_CHG_HS_8500:
case USB_LINK_HOST_CHG_HS_CHIRP_8500:
if (ab->mode == USB_IDLE) {
ab->mode = USB_PERIPHERAL;
ab8500_usb_peri_phy_en(ab);
atomic_notifier_call_chain(&ab->phy.notifier,
UX500_MUSB_PREPARE, &ab->vbus_draw);
}
if (event != UX500_MUSB_RIDC)
event = UX500_MUSB_VBUS;
break;
case USB_LINK_ACA_RID_A_8500:
event = UX500_MUSB_RIDA;
case USB_LINK_HM_IDGND_8500:
if (ab->mode == USB_IDLE) {
ab->mode = USB_HOST;
ab8500_usb_host_phy_en(ab);
atomic_notifier_call_chain(&ab->phy.notifier,
UX500_MUSB_PREPARE, &ab->vbus_draw);
}
ab->phy.otg->default_a = true;
if (event != UX500_MUSB_RIDA)
event = UX500_MUSB_ID;
atomic_notifier_call_chain(&ab->phy.notifier,
event, &ab->vbus_draw);
break;
case USB_LINK_DEDICATED_CHG_8500:
ab->mode = USB_DEDICATED_CHG;
event = UX500_MUSB_CHARGER;
atomic_notifier_call_chain(&ab->phy.notifier,
event, &ab->vbus_draw);
break;
case USB_LINK_RESERVED_8500:
break;
}
return 0;
}
static int abx500_usb_link_status_update(struct ab8500_usb *ab)
{
u8 reg;
int ret = 0;
if (is_ab8500(ab->ab8500)) {
enum ab8500_usb_link_status lsts;
abx500_get_register_interruptible(ab->dev,
AB8500_USB, AB8500_USB_LINE_STAT_REG, &reg);
lsts = (reg >> 3) & 0x0F;
ret = ab8500_usb_link_status_update(ab, lsts);
} else if (is_ab8505(ab->ab8500)) {
enum ab8505_usb_link_status lsts;
abx500_get_register_interruptible(ab->dev,
AB8500_USB, AB8505_USB_LINE_STAT_REG, &reg);
lsts = (reg >> 3) & 0x1F;
ret = ab8505_usb_link_status_update(ab, lsts);
} else if (is_ab8540(ab->ab8500)) {
enum ab8540_usb_link_status lsts;
abx500_get_register_interruptible(ab->dev,
AB8500_USB, AB8540_USB_LINK_STAT_REG, &reg);
lsts = (reg >> 3) & 0xFF;
ret = ab8540_usb_link_status_update(ab, lsts);
} else if (is_ab9540(ab->ab8500)) {
enum ab9540_usb_link_status lsts;
abx500_get_register_interruptible(ab->dev,
AB8500_USB, AB9540_USB_LINK_STAT_REG, &reg);
lsts = (reg >> 3) & 0xFF;
ret = ab9540_usb_link_status_update(ab, lsts);
}
return ret;
}
static irqreturn_t ab8500_usb_disconnect_irq(int irq, void *data)
{
struct ab8500_usb *ab = (struct ab8500_usb *) data;
enum usb_phy_events event = UX500_MUSB_NONE;
if (ab->mode == USB_HOST) {
ab->phy.otg->default_a = false;
ab->vbus_draw = 0;
atomic_notifier_call_chain(&ab->phy.notifier,
event, &ab->vbus_draw);
ab8500_usb_host_phy_dis(ab);
ab->mode = USB_IDLE;
}
if (ab->mode == USB_PERIPHERAL) {
atomic_notifier_call_chain(&ab->phy.notifier,
event, &ab->vbus_draw);
ab8500_usb_peri_phy_dis(ab);
atomic_notifier_call_chain(&ab->phy.notifier,
UX500_MUSB_CLEAN, &ab->vbus_draw);
ab->mode = USB_IDLE;
ab->phy.otg->default_a = false;
ab->vbus_draw = 0;
}
if (is_ab8500_2p0(ab->ab8500)) {
if (ab->mode == USB_DEDICATED_CHG) {
ab8500_usb_wd_linkstatus(ab,
AB8500_BIT_PHY_CTRL_DEVICE_EN);
abx500_mask_and_set_register_interruptible(ab->dev,
AB8500_USB, AB8500_USB_PHY_CTRL_REG,
AB8500_BIT_PHY_CTRL_DEVICE_EN, 0);
}
}
return IRQ_HANDLED;
}
static irqreturn_t ab8500_usb_link_status_irq(int irq, void *data)
{
struct ab8500_usb *ab = (struct ab8500_usb *)data;
abx500_usb_link_status_update(ab);
return IRQ_HANDLED;
}
static void ab8500_usb_phy_disable_work(struct work_struct *work)
{
struct ab8500_usb *ab = container_of(work, struct ab8500_usb,
phy_dis_work);
if (!ab->phy.otg->host)
ab8500_usb_host_phy_dis(ab);
if (!ab->phy.otg->gadget)
ab8500_usb_peri_phy_dis(ab);
}
static bool ab8500_usb_check_vbus_status(struct ab8500_usb *ab)
{
u8 isource2;
u8 reg;
enum ab8540_usb_link_status lsts;
abx500_get_register_interruptible(ab->dev,
AB8500_INTERRUPT, AB8500_IT_SOURCE2_REG,
&isource2);
if (!(isource2 & AB8500_BIT_SOURCE2_VBUSDET))
return false;
abx500_get_register_interruptible(ab->dev,
AB8500_USB, AB8540_USB_LINK_STAT_REG,
&reg);
lsts = (reg >> 3) & 0xFF;
if (lsts)
return false;
return true;
}
static void ab8500_usb_vbus_turn_on_event_work(struct work_struct *work)
{
struct ab8500_usb *ab = container_of(work, struct ab8500_usb,
vbus_event_work);
if (ab->mode != USB_IDLE)
return;
abx500_set_register_interruptible(ab->dev,
AB8500_SYS_CTRL2_BLOCK, AB8500_MAIN_WD_CTRL_REG,
AB8500_BIT_WD_CTRL_ENABLE);
udelay(100);
abx500_set_register_interruptible(ab->dev,
AB8500_SYS_CTRL2_BLOCK, AB8500_MAIN_WD_CTRL_REG,
AB8500_BIT_WD_CTRL_ENABLE | AB8500_BIT_WD_CTRL_KICK);
udelay(100);
abx500_set_register_interruptible(ab->dev,
AB8500_SYS_CTRL2_BLOCK, AB8500_MAIN_WD_CTRL_REG,
0x0);
abx500_mask_and_set_register_interruptible(ab->dev,
AB8500_USB, AB8540_VBUS_CTRL_REG,
AB8540_BIT_VBUS_CTRL_CHARG_DET_ENA,
AB8540_BIT_VBUS_CTRL_CHARG_DET_ENA);
ab->enabled_charging_detection = true;
}
static unsigned ab8500_eyediagram_workaroud(struct ab8500_usb *ab, unsigned mA)
{
if (is_ab8500_2p0_or_earlier(ab->ab8500))
if (mA > 100)
mA = 100;
return mA;
}
static int ab8500_usb_set_power(struct usb_phy *phy, unsigned mA)
{
struct ab8500_usb *ab;
if (!phy)
return -ENODEV;
ab = phy_to_ab(phy);
mA = ab8500_eyediagram_workaroud(ab, mA);
ab->vbus_draw = mA;
atomic_notifier_call_chain(&ab->phy.notifier,
UX500_MUSB_VBUS, &ab->vbus_draw);
return 0;
}
static int ab8500_usb_set_suspend(struct usb_phy *x, int suspend)
{
return 0;
}
static int ab8500_usb_set_peripheral(struct usb_otg *otg,
struct usb_gadget *gadget)
{
struct ab8500_usb *ab;
if (!otg)
return -ENODEV;
ab = phy_to_ab(otg->phy);
ab->phy.otg->gadget = gadget;
if ((ab->mode != USB_IDLE) && !gadget) {
ab->mode = USB_IDLE;
schedule_work(&ab->phy_dis_work);
}
return 0;
}
static int ab8500_usb_set_host(struct usb_otg *otg, struct usb_bus *host)
{
struct ab8500_usb *ab;
if (!otg)
return -ENODEV;
ab = phy_to_ab(otg->phy);
ab->phy.otg->host = host;
if ((ab->mode != USB_IDLE) && !host) {
ab->mode = USB_IDLE;
schedule_work(&ab->phy_dis_work);
}
return 0;
}
static void ab8500_usb_restart_phy(struct ab8500_usb *ab)
{
abx500_mask_and_set_register_interruptible(ab->dev,
AB8500_USB, AB8500_USB_PHY_CTRL_REG,
AB8500_BIT_PHY_CTRL_DEVICE_EN,
AB8500_BIT_PHY_CTRL_DEVICE_EN);
udelay(100);
abx500_mask_and_set_register_interruptible(ab->dev,
AB8500_USB, AB8500_USB_PHY_CTRL_REG,
AB8500_BIT_PHY_CTRL_DEVICE_EN,
0);
abx500_mask_and_set_register_interruptible(ab->dev,
AB8500_USB, AB8500_USB_PHY_CTRL_REG,
AB8500_BIT_PHY_CTRL_HOST_EN,
AB8500_BIT_PHY_CTRL_HOST_EN);
udelay(100);
abx500_mask_and_set_register_interruptible(ab->dev,
AB8500_USB, AB8500_USB_PHY_CTRL_REG,
AB8500_BIT_PHY_CTRL_HOST_EN,
0);
}
static int ab8500_usb_regulator_get(struct ab8500_usb *ab)
{
int err;
ab->v_ape = devm_regulator_get(ab->dev, "v-ape");
if (IS_ERR(ab->v_ape)) {
dev_err(ab->dev, "Could not get v-ape supply\n");
err = PTR_ERR(ab->v_ape);
return err;
}
ab->v_ulpi = devm_regulator_get(ab->dev, "vddulpivio18");
if (IS_ERR(ab->v_ulpi)) {
dev_err(ab->dev, "Could not get vddulpivio18 supply\n");
err = PTR_ERR(ab->v_ulpi);
return err;
}
ab->v_musb = devm_regulator_get(ab->dev, "musb_1v8");
if (IS_ERR(ab->v_musb)) {
dev_err(ab->dev, "Could not get musb_1v8 supply\n");
err = PTR_ERR(ab->v_musb);
return err;
}
return 0;
}
static int ab8500_usb_irq_setup(struct platform_device *pdev,
struct ab8500_usb *ab)
{
int err;
int irq;
if (ab->flags & AB8500_USB_FLAG_USE_LINK_STATUS_IRQ) {
irq = platform_get_irq_byname(pdev, "USB_LINK_STATUS");
if (irq < 0) {
dev_err(&pdev->dev, "Link status irq not found\n");
return irq;
}
err = devm_request_threaded_irq(&pdev->dev, irq, NULL,
ab8500_usb_link_status_irq,
IRQF_NO_SUSPEND | IRQF_SHARED,
"usb-link-status", ab);
if (err < 0) {
dev_err(ab->dev, "request_irq failed for link status irq\n");
return err;
}
}
if (ab->flags & AB8500_USB_FLAG_USE_ID_WAKEUP_IRQ) {
irq = platform_get_irq_byname(pdev, "ID_WAKEUP_F");
if (irq < 0) {
dev_err(&pdev->dev, "ID fall irq not found\n");
return irq;
}
err = devm_request_threaded_irq(&pdev->dev, irq, NULL,
ab8500_usb_disconnect_irq,
IRQF_NO_SUSPEND | IRQF_SHARED,
"usb-id-fall", ab);
if (err < 0) {
dev_err(ab->dev, "request_irq failed for ID fall irq\n");
return err;
}
}
if (ab->flags & AB8500_USB_FLAG_USE_VBUS_DET_IRQ) {
irq = platform_get_irq_byname(pdev, "VBUS_DET_F");
if (irq < 0) {
dev_err(&pdev->dev, "VBUS fall irq not found\n");
return irq;
}
err = devm_request_threaded_irq(&pdev->dev, irq, NULL,
ab8500_usb_disconnect_irq,
IRQF_NO_SUSPEND | IRQF_SHARED,
"usb-vbus-fall", ab);
if (err < 0) {
dev_err(ab->dev, "request_irq failed for Vbus fall irq\n");
return err;
}
}
return 0;
}
static void ab8500_usb_set_ab8500_tuning_values(struct ab8500_usb *ab)
{
int err;
err = abx500_set_register_interruptible(ab->dev,
AB8500_DEVELOPMENT, AB8500_BANK12_ACCESS, 0x01);
if (err < 0)
dev_err(ab->dev, "Failed to enable bank12 access err=%d\n",
err);
err = abx500_set_register_interruptible(ab->dev,
AB8500_DEBUG, AB8500_USB_PHY_TUNE1, 0xC8);
if (err < 0)
dev_err(ab->dev, "Failed to set PHY_TUNE1 register err=%d\n",
err);
err = abx500_set_register_interruptible(ab->dev,
AB8500_DEBUG, AB8500_USB_PHY_TUNE2, 0x00);
if (err < 0)
dev_err(ab->dev, "Failed to set PHY_TUNE2 register err=%d\n",
err);
err = abx500_set_register_interruptible(ab->dev,
AB8500_DEBUG, AB8500_USB_PHY_TUNE3, 0x78);
if (err < 0)
dev_err(ab->dev, "Failed to set PHY_TUNE3 regester err=%d\n",
err);
err = abx500_set_register_interruptible(ab->dev,
AB8500_DEVELOPMENT, AB8500_BANK12_ACCESS, 0x00);
if (err < 0)
dev_err(ab->dev, "Failed to switch bank12 access err=%d\n",
err);
}
static void ab8500_usb_set_ab8505_tuning_values(struct ab8500_usb *ab)
{
int err;
err = abx500_mask_and_set_register_interruptible(ab->dev,
AB8500_DEVELOPMENT, AB8500_BANK12_ACCESS,
0x01, 0x01);
if (err < 0)
dev_err(ab->dev, "Failed to enable bank12 access err=%d\n",
err);
err = abx500_mask_and_set_register_interruptible(ab->dev,
AB8500_DEBUG, AB8500_USB_PHY_TUNE1,
0xC8, 0xC8);
if (err < 0)
dev_err(ab->dev, "Failed to set PHY_TUNE1 register err=%d\n",
err);
err = abx500_mask_and_set_register_interruptible(ab->dev,
AB8500_DEBUG, AB8500_USB_PHY_TUNE2,
0x60, 0x60);
if (err < 0)
dev_err(ab->dev, "Failed to set PHY_TUNE2 register err=%d\n",
err);
err = abx500_mask_and_set_register_interruptible(ab->dev,
AB8500_DEBUG, AB8500_USB_PHY_TUNE3,
0xFC, 0x80);
if (err < 0)
dev_err(ab->dev, "Failed to set PHY_TUNE3 regester err=%d\n",
err);
err = abx500_mask_and_set_register_interruptible(ab->dev,
AB8500_DEVELOPMENT, AB8500_BANK12_ACCESS,
0x00, 0x00);
if (err < 0)
dev_err(ab->dev, "Failed to switch bank12 access err=%d\n",
err);
}
static void ab8500_usb_set_ab8540_tuning_values(struct ab8500_usb *ab)
{
int err;
err = abx500_set_register_interruptible(ab->dev,
AB8540_DEBUG, AB8500_USB_PHY_TUNE1, 0xCC);
if (err < 0)
dev_err(ab->dev, "Failed to set PHY_TUNE1 register ret=%d\n",
err);
err = abx500_set_register_interruptible(ab->dev,
AB8540_DEBUG, AB8500_USB_PHY_TUNE2, 0x60);
if (err < 0)
dev_err(ab->dev, "Failed to set PHY_TUNE2 register ret=%d\n",
err);
err = abx500_set_register_interruptible(ab->dev,
AB8540_DEBUG, AB8500_USB_PHY_TUNE3, 0x90);
if (err < 0)
dev_err(ab->dev, "Failed to set PHY_TUNE3 regester ret=%d\n",
err);
}
static void ab8500_usb_set_ab9540_tuning_values(struct ab8500_usb *ab)
{
int err;
err = abx500_set_register_interruptible(ab->dev,
AB8500_DEVELOPMENT, AB8500_BANK12_ACCESS, 0x01);
if (err < 0)
dev_err(ab->dev, "Failed to enable bank12 access err=%d\n",
err);
err = abx500_set_register_interruptible(ab->dev,
AB8500_DEBUG, AB8500_USB_PHY_TUNE1, 0xC8);
if (err < 0)
dev_err(ab->dev, "Failed to set PHY_TUNE1 register err=%d\n",
err);
err = abx500_set_register_interruptible(ab->dev,
AB8500_DEBUG, AB8500_USB_PHY_TUNE2, 0x60);
if (err < 0)
dev_err(ab->dev, "Failed to set PHY_TUNE2 register err=%d\n",
err);
err = abx500_set_register_interruptible(ab->dev,
AB8500_DEBUG, AB8500_USB_PHY_TUNE3, 0x80);
if (err < 0)
dev_err(ab->dev, "Failed to set PHY_TUNE3 regester err=%d\n",
err);
err = abx500_set_register_interruptible(ab->dev,
AB8500_DEVELOPMENT, AB8500_BANK12_ACCESS, 0x00);
if (err < 0)
dev_err(ab->dev, "Failed to switch bank12 access err=%d\n",
err);
}
static int ab8500_usb_probe(struct platform_device *pdev)
{
struct ab8500_usb *ab;
struct ab8500 *ab8500;
struct usb_otg *otg;
int err;
int rev;
ab8500 = dev_get_drvdata(pdev->dev.parent);
rev = abx500_get_chip_id(&pdev->dev);
if (is_ab8500_1p1_or_earlier(ab8500)) {
dev_err(&pdev->dev, "Unsupported AB8500 chip rev=%d\n", rev);
return -ENODEV;
}
ab = devm_kzalloc(&pdev->dev, sizeof(*ab), GFP_KERNEL);
if (!ab)
return -ENOMEM;
otg = devm_kzalloc(&pdev->dev, sizeof(*otg), GFP_KERNEL);
if (!otg)
return -ENOMEM;
ab->dev = &pdev->dev;
ab->ab8500 = ab8500;
ab->phy.dev = ab->dev;
ab->phy.otg = otg;
ab->phy.label = "ab8500";
ab->phy.set_suspend = ab8500_usb_set_suspend;
ab->phy.set_power = ab8500_usb_set_power;
ab->phy.state = OTG_STATE_UNDEFINED;
otg->phy = &ab->phy;
otg->set_host = ab8500_usb_set_host;
otg->set_peripheral = ab8500_usb_set_peripheral;
if (is_ab8500(ab->ab8500)) {
ab->flags |= AB8500_USB_FLAG_USE_LINK_STATUS_IRQ |
AB8500_USB_FLAG_USE_ID_WAKEUP_IRQ |
AB8500_USB_FLAG_USE_VBUS_DET_IRQ |
AB8500_USB_FLAG_REGULATOR_SET_VOLTAGE;
} else if (is_ab8505(ab->ab8500)) {
ab->flags |= AB8500_USB_FLAG_USE_LINK_STATUS_IRQ |
AB8500_USB_FLAG_USE_ID_WAKEUP_IRQ |
AB8500_USB_FLAG_USE_VBUS_DET_IRQ |
AB8500_USB_FLAG_REGULATOR_SET_VOLTAGE;
} else if (is_ab8540(ab->ab8500)) {
ab->flags |= AB8500_USB_FLAG_USE_LINK_STATUS_IRQ |
AB8500_USB_FLAG_USE_CHECK_VBUS_STATUS |
AB8500_USB_FLAG_USE_VBUS_HOST_QUIRK |
AB8500_USB_FLAG_REGULATOR_SET_VOLTAGE;
} else if (is_ab9540(ab->ab8500)) {
ab->flags |= AB8500_USB_FLAG_USE_LINK_STATUS_IRQ |
AB8500_USB_FLAG_REGULATOR_SET_VOLTAGE;
if (is_ab9540_2p0_or_earlier(ab->ab8500))
ab->flags |= AB8500_USB_FLAG_USE_ID_WAKEUP_IRQ |
AB8500_USB_FLAG_USE_VBUS_DET_IRQ;
}
if (is_ab8500_2p0_or_earlier(ab->ab8500))
ab->flags &= ~AB8500_USB_FLAG_REGULATOR_SET_VOLTAGE;
platform_set_drvdata(pdev, ab);
ATOMIC_INIT_NOTIFIER_HEAD(&ab->phy.notifier);
INIT_WORK(&ab->phy_dis_work, ab8500_usb_phy_disable_work);
INIT_WORK(&ab->vbus_event_work, ab8500_usb_vbus_turn_on_event_work);
err = ab8500_usb_regulator_get(ab);
if (err)
return err;
ab->sysclk = devm_clk_get(ab->dev, "sysclk");
if (IS_ERR(ab->sysclk)) {
dev_err(ab->dev, "Could not get sysclk.\n");
return PTR_ERR(ab->sysclk);
}
err = ab8500_usb_irq_setup(pdev, ab);
if (err < 0)
return err;
err = usb_add_phy(&ab->phy, USB_PHY_TYPE_USB2);
if (err) {
dev_err(&pdev->dev, "Can't register transceiver\n");
return err;
}
if (is_ab8500(ab->ab8500) && !is_ab8500_2p0_or_earlier(ab->ab8500))
ab8500_usb_set_ab8500_tuning_values(ab);
else if (is_ab8505(ab->ab8500))
ab8500_usb_set_ab8505_tuning_values(ab);
else if (is_ab8540(ab->ab8500))
ab8500_usb_set_ab8540_tuning_values(ab);
else if (is_ab9540(ab->ab8500))
ab8500_usb_set_ab9540_tuning_values(ab);
ab8500_usb_wd_workaround(ab);
ab8500_usb_restart_phy(ab);
if (ab->flags & AB8500_USB_FLAG_USE_CHECK_VBUS_STATUS) {
if (ab8500_usb_check_vbus_status(ab))
schedule_work(&ab->vbus_event_work);
}
abx500_usb_link_status_update(ab);
dev_info(&pdev->dev, "revision 0x%2x driver initialized\n", rev);
return 0;
}
static int ab8500_usb_remove(struct platform_device *pdev)
{
struct ab8500_usb *ab = platform_get_drvdata(pdev);
cancel_work_sync(&ab->phy_dis_work);
cancel_work_sync(&ab->vbus_event_work);
usb_remove_phy(&ab->phy);
if (ab->mode == USB_HOST)
ab8500_usb_host_phy_dis(ab);
else if (ab->mode == USB_PERIPHERAL)
ab8500_usb_peri_phy_dis(ab);
return 0;
}
static int __init ab8500_usb_init(void)
{
return platform_driver_register(&ab8500_usb_driver);
}
static void __exit ab8500_usb_exit(void)
{
platform_driver_unregister(&ab8500_usb_driver);
}
