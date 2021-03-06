static unsigned int sfp_gpio_get_state(struct sfp *sfp)
{
unsigned int i, state, v;
for (i = state = 0; i < GPIO_MAX; i++) {
if (gpio_flags[i] != GPIOD_IN || !sfp->gpio[i])
continue;
v = gpiod_get_value_cansleep(sfp->gpio[i]);
if (v)
state |= BIT(i);
}
return state;
}
static void sfp_gpio_set_state(struct sfp *sfp, unsigned int state)
{
if (state & SFP_F_PRESENT) {
if (sfp->gpio[GPIO_TX_DISABLE])
gpiod_direction_output(sfp->gpio[GPIO_TX_DISABLE],
state & SFP_F_TX_DISABLE);
if (state & SFP_F_RATE_SELECT)
gpiod_direction_output(sfp->gpio[GPIO_RATE_SELECT],
state & SFP_F_RATE_SELECT);
} else {
if (sfp->gpio[GPIO_TX_DISABLE])
gpiod_direction_input(sfp->gpio[GPIO_TX_DISABLE]);
if (state & SFP_F_RATE_SELECT)
gpiod_direction_input(sfp->gpio[GPIO_RATE_SELECT]);
}
}
static int sfp__i2c_read(struct i2c_adapter *i2c, u8 bus_addr, u8 dev_addr,
void *buf, size_t len)
{
struct i2c_msg msgs[2];
int ret;
msgs[0].addr = bus_addr;
msgs[0].flags = 0;
msgs[0].len = 1;
msgs[0].buf = &dev_addr;
msgs[1].addr = bus_addr;
msgs[1].flags = I2C_M_RD;
msgs[1].len = len;
msgs[1].buf = buf;
ret = i2c_transfer(i2c, msgs, ARRAY_SIZE(msgs));
if (ret < 0)
return ret;
return ret == ARRAY_SIZE(msgs) ? len : 0;
}
static int sfp_i2c_read(struct sfp *sfp, bool a2, u8 addr, void *buf,
size_t len)
{
return sfp__i2c_read(sfp->i2c, a2 ? 0x51 : 0x50, addr, buf, len);
}
static int sfp_i2c_configure(struct sfp *sfp, struct i2c_adapter *i2c)
{
struct mii_bus *i2c_mii;
int ret;
if (!i2c_check_functionality(i2c, I2C_FUNC_I2C))
return -EINVAL;
sfp->i2c = i2c;
sfp->read = sfp_i2c_read;
i2c_mii = mdio_i2c_alloc(sfp->dev, i2c);
if (IS_ERR(i2c_mii))
return PTR_ERR(i2c_mii);
i2c_mii->name = "SFP I2C Bus";
i2c_mii->phy_mask = ~0;
ret = mdiobus_register(i2c_mii);
if (ret < 0) {
mdiobus_free(i2c_mii);
return ret;
}
sfp->i2c_mii = i2c_mii;
return 0;
}
static unsigned int sfp_get_state(struct sfp *sfp)
{
return sfp->get_state(sfp);
}
static void sfp_set_state(struct sfp *sfp, unsigned int state)
{
sfp->set_state(sfp, state);
}
static int sfp_read(struct sfp *sfp, bool a2, u8 addr, void *buf, size_t len)
{
return sfp->read(sfp, a2, addr, buf, len);
}
static unsigned int sfp_check(void *buf, size_t len)
{
u8 *p, check;
for (p = buf, check = 0; len; p++, len--)
check += *p;
return check;
}
static void sfp_module_tx_disable(struct sfp *sfp)
{
dev_dbg(sfp->dev, "tx disable %u -> %u\n",
sfp->state & SFP_F_TX_DISABLE ? 1 : 0, 1);
sfp->state |= SFP_F_TX_DISABLE;
sfp_set_state(sfp, sfp->state);
}
static void sfp_module_tx_enable(struct sfp *sfp)
{
dev_dbg(sfp->dev, "tx disable %u -> %u\n",
sfp->state & SFP_F_TX_DISABLE ? 1 : 0, 0);
sfp->state &= ~SFP_F_TX_DISABLE;
sfp_set_state(sfp, sfp->state);
}
static void sfp_module_tx_fault_reset(struct sfp *sfp)
{
unsigned int state = sfp->state;
if (state & SFP_F_TX_DISABLE)
return;
sfp_set_state(sfp, state | SFP_F_TX_DISABLE);
udelay(T_RESET_US);
sfp_set_state(sfp, state);
}
static void sfp_sm_set_timer(struct sfp *sfp, unsigned int timeout)
{
if (timeout)
mod_delayed_work(system_power_efficient_wq, &sfp->timeout,
timeout);
else
cancel_delayed_work(&sfp->timeout);
}
static void sfp_sm_next(struct sfp *sfp, unsigned int state,
unsigned int timeout)
{
sfp->sm_state = state;
sfp_sm_set_timer(sfp, timeout);
}
static void sfp_sm_ins_next(struct sfp *sfp, unsigned int state, unsigned int timeout)
{
sfp->sm_mod_state = state;
sfp_sm_set_timer(sfp, timeout);
}
static void sfp_sm_phy_detach(struct sfp *sfp)
{
phy_stop(sfp->mod_phy);
sfp_remove_phy(sfp->sfp_bus);
phy_device_remove(sfp->mod_phy);
phy_device_free(sfp->mod_phy);
sfp->mod_phy = NULL;
}
static void sfp_sm_probe_phy(struct sfp *sfp)
{
struct phy_device *phy;
int err;
msleep(T_PHY_RESET_MS);
phy = mdiobus_scan(sfp->i2c_mii, SFP_PHY_ADDR);
if (IS_ERR(phy)) {
dev_err(sfp->dev, "mdiobus scan returned %ld\n", PTR_ERR(phy));
return;
}
if (!phy) {
dev_info(sfp->dev, "no PHY detected\n");
return;
}
err = sfp_add_phy(sfp->sfp_bus, phy);
if (err) {
phy_device_remove(phy);
phy_device_free(phy);
dev_err(sfp->dev, "sfp_add_phy failed: %d\n", err);
return;
}
sfp->mod_phy = phy;
phy_start(phy);
}
static void sfp_sm_link_up(struct sfp *sfp)
{
sfp_link_up(sfp->sfp_bus);
sfp_sm_next(sfp, SFP_S_LINK_UP, 0);
}
static void sfp_sm_link_down(struct sfp *sfp)
{
sfp_link_down(sfp->sfp_bus);
}
static void sfp_sm_link_check_los(struct sfp *sfp)
{
unsigned int los = sfp->state & SFP_F_LOS;
if (sfp->id.ext.options & SFP_OPTIONS_LOS_INVERTED)
los ^= SFP_F_LOS;
if (los)
sfp_sm_next(sfp, SFP_S_WAIT_LOS, 0);
else
sfp_sm_link_up(sfp);
}
static void sfp_sm_fault(struct sfp *sfp, bool warn)
{
if (sfp->sm_retries && !--sfp->sm_retries) {
dev_err(sfp->dev, "module persistently indicates fault, disabling\n");
sfp_sm_next(sfp, SFP_S_TX_DISABLE, 0);
} else {
if (warn)
dev_err(sfp->dev, "module transmit fault indicated\n");
sfp_sm_next(sfp, SFP_S_TX_FAULT, T_FAULT_RECOVER);
}
}
static void sfp_sm_mod_init(struct sfp *sfp)
{
sfp_module_tx_enable(sfp);
sfp_sm_next(sfp, SFP_S_INIT, T_INIT_JIFFIES);
sfp->sm_retries = 5;
if (sfp->id.base.e1000_base_t ||
sfp->id.base.e100_base_lx ||
sfp->id.base.e100_base_fx)
sfp_sm_probe_phy(sfp);
}
static int sfp_sm_mod_probe(struct sfp *sfp)
{
struct sfp_eeprom_id id;
char vendor[17];
char part[17];
char sn[17];
char date[9];
char rev[5];
u8 check;
int err;
err = sfp_read(sfp, false, 0, &id, sizeof(id));
if (err < 0) {
dev_err(sfp->dev, "failed to read EEPROM: %d\n", err);
return -EAGAIN;
}
if (err != sizeof(id)) {
dev_err(sfp->dev, "EEPROM short read: %d\n", err);
return -EAGAIN;
}
check = sfp_check(&id.base, sizeof(id.base) - 1);
if (check != id.base.cc_base) {
dev_err(sfp->dev,
"EEPROM base structure checksum failure: 0x%02x\n",
check);
print_hex_dump(KERN_ERR, "sfp EE: ", DUMP_PREFIX_OFFSET,
16, 1, &id, sizeof(id.base) - 1, true);
return -EINVAL;
}
check = sfp_check(&id.ext, sizeof(id.ext) - 1);
if (check != id.ext.cc_ext) {
dev_err(sfp->dev,
"EEPROM extended structure checksum failure: 0x%02x\n",
check);
memset(&id.ext, 0, sizeof(id.ext));
}
sfp->id = id;
memcpy(vendor, sfp->id.base.vendor_name, 16);
vendor[16] = '\0';
memcpy(part, sfp->id.base.vendor_pn, 16);
part[16] = '\0';
memcpy(rev, sfp->id.base.vendor_rev, 4);
rev[4] = '\0';
memcpy(sn, sfp->id.ext.vendor_sn, 16);
sn[16] = '\0';
memcpy(date, sfp->id.ext.datecode, 8);
date[8] = '\0';
dev_info(sfp->dev, "module %s %s rev %s sn %s dc %s\n", vendor, part, rev, sn, date);
if (sfp->id.base.phys_id != SFP_PHYS_ID_SFP ||
sfp->id.base.phys_ext_id != SFP_PHYS_EXT_ID_SFP) {
dev_err(sfp->dev, "module is not SFP - phys id 0x%02x 0x%02x\n",
sfp->id.base.phys_id, sfp->id.base.phys_ext_id);
return -EINVAL;
}
return sfp_module_insert(sfp->sfp_bus, &sfp->id);
}
static void sfp_sm_mod_remove(struct sfp *sfp)
{
sfp_module_remove(sfp->sfp_bus);
if (sfp->mod_phy)
sfp_sm_phy_detach(sfp);
sfp_module_tx_disable(sfp);
memset(&sfp->id, 0, sizeof(sfp->id));
dev_info(sfp->dev, "module removed\n");
}
static void sfp_sm_event(struct sfp *sfp, unsigned int event)
{
mutex_lock(&sfp->sm_mutex);
dev_dbg(sfp->dev, "SM: enter %u:%u:%u event %u\n",
sfp->sm_mod_state, sfp->sm_dev_state, sfp->sm_state, event);
switch (sfp->sm_mod_state) {
default:
if (event == SFP_E_INSERT) {
sfp_module_tx_disable(sfp);
sfp_sm_ins_next(sfp, SFP_MOD_PROBE, T_PROBE_INIT);
}
break;
case SFP_MOD_PROBE:
if (event == SFP_E_REMOVE) {
sfp_sm_ins_next(sfp, SFP_MOD_EMPTY, 0);
} else if (event == SFP_E_TIMEOUT) {
int err = sfp_sm_mod_probe(sfp);
if (err == 0)
sfp_sm_ins_next(sfp, SFP_MOD_PRESENT, 0);
else if (err == -EAGAIN)
sfp_sm_set_timer(sfp, T_PROBE_RETRY);
else
sfp_sm_ins_next(sfp, SFP_MOD_ERROR, 0);
}
break;
case SFP_MOD_PRESENT:
case SFP_MOD_ERROR:
if (event == SFP_E_REMOVE) {
sfp_sm_mod_remove(sfp);
sfp_sm_ins_next(sfp, SFP_MOD_EMPTY, 0);
}
break;
}
switch (sfp->sm_dev_state) {
default:
if (event == SFP_E_DEV_UP)
sfp->sm_dev_state = SFP_DEV_UP;
break;
case SFP_DEV_UP:
if (event == SFP_E_DEV_DOWN) {
if (!sfp->mod_phy)
sfp_module_tx_disable(sfp);
sfp->sm_dev_state = SFP_DEV_DOWN;
}
break;
}
if (sfp->sm_state != SFP_S_DOWN &&
(sfp->sm_mod_state != SFP_MOD_PRESENT ||
sfp->sm_dev_state != SFP_DEV_UP)) {
if (sfp->sm_state == SFP_S_LINK_UP &&
sfp->sm_dev_state == SFP_DEV_UP)
sfp_sm_link_down(sfp);
if (sfp->mod_phy)
sfp_sm_phy_detach(sfp);
sfp_sm_next(sfp, SFP_S_DOWN, 0);
mutex_unlock(&sfp->sm_mutex);
return;
}
switch (sfp->sm_state) {
case SFP_S_DOWN:
if (sfp->sm_mod_state == SFP_MOD_PRESENT &&
sfp->sm_dev_state == SFP_DEV_UP)
sfp_sm_mod_init(sfp);
break;
case SFP_S_INIT:
if (event == SFP_E_TIMEOUT && sfp->state & SFP_F_TX_FAULT)
sfp_sm_fault(sfp, true);
else if (event == SFP_E_TIMEOUT || event == SFP_E_TX_CLEAR)
sfp_sm_link_check_los(sfp);
break;
case SFP_S_WAIT_LOS:
if (event == SFP_E_TX_FAULT)
sfp_sm_fault(sfp, true);
else if (event ==
(sfp->id.ext.options & SFP_OPTIONS_LOS_INVERTED ?
SFP_E_LOS_HIGH : SFP_E_LOS_LOW))
sfp_sm_link_up(sfp);
break;
case SFP_S_LINK_UP:
if (event == SFP_E_TX_FAULT) {
sfp_sm_link_down(sfp);
sfp_sm_fault(sfp, true);
} else if (event ==
(sfp->id.ext.options & SFP_OPTIONS_LOS_INVERTED ?
SFP_E_LOS_LOW : SFP_E_LOS_HIGH)) {
sfp_sm_link_down(sfp);
sfp_sm_next(sfp, SFP_S_WAIT_LOS, 0);
}
break;
case SFP_S_TX_FAULT:
if (event == SFP_E_TIMEOUT) {
sfp_module_tx_fault_reset(sfp);
sfp_sm_next(sfp, SFP_S_REINIT, T_INIT_JIFFIES);
}
break;
case SFP_S_REINIT:
if (event == SFP_E_TIMEOUT && sfp->state & SFP_F_TX_FAULT) {
sfp_sm_fault(sfp, false);
} else if (event == SFP_E_TIMEOUT || event == SFP_E_TX_CLEAR) {
dev_info(sfp->dev, "module transmit fault recovered\n");
sfp_sm_link_check_los(sfp);
}
break;
case SFP_S_TX_DISABLE:
break;
}
dev_dbg(sfp->dev, "SM: exit %u:%u:%u\n",
sfp->sm_mod_state, sfp->sm_dev_state, sfp->sm_state);
mutex_unlock(&sfp->sm_mutex);
}
static void sfp_start(struct sfp *sfp)
{
sfp_sm_event(sfp, SFP_E_DEV_UP);
}
static void sfp_stop(struct sfp *sfp)
{
sfp_sm_event(sfp, SFP_E_DEV_DOWN);
}
static int sfp_module_info(struct sfp *sfp, struct ethtool_modinfo *modinfo)
{
if (sfp->id.ext.sff8472_compliance) {
modinfo->type = ETH_MODULE_SFF_8472;
modinfo->eeprom_len = ETH_MODULE_SFF_8472_LEN;
} else {
modinfo->type = ETH_MODULE_SFF_8079;
modinfo->eeprom_len = ETH_MODULE_SFF_8079_LEN;
}
return 0;
}
static int sfp_module_eeprom(struct sfp *sfp, struct ethtool_eeprom *ee,
u8 *data)
{
unsigned int first, last, len;
int ret;
if (ee->len == 0)
return -EINVAL;
first = ee->offset;
last = ee->offset + ee->len;
if (first < ETH_MODULE_SFF_8079_LEN) {
len = min_t(unsigned int, last, ETH_MODULE_SFF_8079_LEN);
len -= first;
ret = sfp->read(sfp, false, first, data, len);
if (ret < 0)
return ret;
first += len;
data += len;
}
if (first >= ETH_MODULE_SFF_8079_LEN &&
first < ETH_MODULE_SFF_8472_LEN) {
len = min_t(unsigned int, last, ETH_MODULE_SFF_8472_LEN);
len -= first;
first -= ETH_MODULE_SFF_8079_LEN;
ret = sfp->read(sfp, true, first, data, len);
if (ret < 0)
return ret;
}
return 0;
}
static void sfp_timeout(struct work_struct *work)
{
struct sfp *sfp = container_of(work, struct sfp, timeout.work);
rtnl_lock();
sfp_sm_event(sfp, SFP_E_TIMEOUT);
rtnl_unlock();
}
static void sfp_check_state(struct sfp *sfp)
{
unsigned int state, i, changed;
state = sfp_get_state(sfp);
changed = state ^ sfp->state;
changed &= SFP_F_PRESENT | SFP_F_LOS | SFP_F_TX_FAULT;
for (i = 0; i < GPIO_MAX; i++)
if (changed & BIT(i))
dev_dbg(sfp->dev, "%s %u -> %u\n", gpio_of_names[i],
!!(sfp->state & BIT(i)), !!(state & BIT(i)));
state |= sfp->state & (SFP_F_TX_DISABLE | SFP_F_RATE_SELECT);
sfp->state = state;
rtnl_lock();
if (changed & SFP_F_PRESENT)
sfp_sm_event(sfp, state & SFP_F_PRESENT ?
SFP_E_INSERT : SFP_E_REMOVE);
if (changed & SFP_F_TX_FAULT)
sfp_sm_event(sfp, state & SFP_F_TX_FAULT ?
SFP_E_TX_FAULT : SFP_E_TX_CLEAR);
if (changed & SFP_F_LOS)
sfp_sm_event(sfp, state & SFP_F_LOS ?
SFP_E_LOS_HIGH : SFP_E_LOS_LOW);
rtnl_unlock();
}
static irqreturn_t sfp_irq(int irq, void *data)
{
struct sfp *sfp = data;
sfp_check_state(sfp);
return IRQ_HANDLED;
}
static void sfp_poll(struct work_struct *work)
{
struct sfp *sfp = container_of(work, struct sfp, poll.work);
sfp_check_state(sfp);
mod_delayed_work(system_wq, &sfp->poll, poll_jiffies);
}
static struct sfp *sfp_alloc(struct device *dev)
{
struct sfp *sfp;
sfp = kzalloc(sizeof(*sfp), GFP_KERNEL);
if (!sfp)
return ERR_PTR(-ENOMEM);
sfp->dev = dev;
mutex_init(&sfp->sm_mutex);
INIT_DELAYED_WORK(&sfp->poll, sfp_poll);
INIT_DELAYED_WORK(&sfp->timeout, sfp_timeout);
return sfp;
}
static void sfp_cleanup(void *data)
{
struct sfp *sfp = data;
cancel_delayed_work_sync(&sfp->poll);
cancel_delayed_work_sync(&sfp->timeout);
if (sfp->i2c_mii) {
mdiobus_unregister(sfp->i2c_mii);
mdiobus_free(sfp->i2c_mii);
}
if (sfp->i2c)
i2c_put_adapter(sfp->i2c);
kfree(sfp);
}
static int sfp_probe(struct platform_device *pdev)
{
struct sfp *sfp;
bool poll = false;
int irq, err, i;
sfp = sfp_alloc(&pdev->dev);
if (IS_ERR(sfp))
return PTR_ERR(sfp);
platform_set_drvdata(pdev, sfp);
err = devm_add_action(sfp->dev, sfp_cleanup, sfp);
if (err < 0)
return err;
if (pdev->dev.of_node) {
struct device_node *node = pdev->dev.of_node;
struct device_node *np;
np = of_parse_phandle(node, "i2c-bus", 0);
if (np) {
struct i2c_adapter *i2c;
i2c = of_find_i2c_adapter_by_node(np);
of_node_put(np);
if (!i2c)
return -EPROBE_DEFER;
err = sfp_i2c_configure(sfp, i2c);
if (err < 0) {
i2c_put_adapter(i2c);
return err;
}
}
for (i = 0; i < GPIO_MAX; i++) {
sfp->gpio[i] = devm_gpiod_get_optional(sfp->dev,
gpio_of_names[i], gpio_flags[i]);
if (IS_ERR(sfp->gpio[i]))
return PTR_ERR(sfp->gpio[i]);
}
sfp->get_state = sfp_gpio_get_state;
sfp->set_state = sfp_gpio_set_state;
}
sfp->sfp_bus = sfp_register_socket(sfp->dev, sfp, &sfp_module_ops);
if (!sfp->sfp_bus)
return -ENOMEM;
sfp->state = sfp_get_state(sfp) | SFP_F_TX_DISABLE;
if (sfp->gpio[GPIO_RATE_SELECT] &&
gpiod_get_value_cansleep(sfp->gpio[GPIO_RATE_SELECT]))
sfp->state |= SFP_F_RATE_SELECT;
sfp_set_state(sfp, sfp->state);
sfp_module_tx_disable(sfp);
rtnl_lock();
if (sfp->state & SFP_F_PRESENT)
sfp_sm_event(sfp, SFP_E_INSERT);
rtnl_unlock();
for (i = 0; i < GPIO_MAX; i++) {
if (gpio_flags[i] != GPIOD_IN || !sfp->gpio[i])
continue;
irq = gpiod_to_irq(sfp->gpio[i]);
if (!irq) {
poll = true;
continue;
}
err = devm_request_threaded_irq(sfp->dev, irq, NULL, sfp_irq,
IRQF_ONESHOT |
IRQF_TRIGGER_RISING |
IRQF_TRIGGER_FALLING,
dev_name(sfp->dev), sfp);
if (err)
poll = true;
}
if (poll)
mod_delayed_work(system_wq, &sfp->poll, poll_jiffies);
return 0;
}
static int sfp_remove(struct platform_device *pdev)
{
struct sfp *sfp = platform_get_drvdata(pdev);
sfp_unregister_socket(sfp->sfp_bus);
return 0;
}
static int sfp_init(void)
{
poll_jiffies = msecs_to_jiffies(100);
return platform_driver_register(&sfp_driver);
}
static void sfp_exit(void)
{
platform_driver_unregister(&sfp_driver);
}
