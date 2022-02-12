static int qeth_card_hw_is_reachable(struct qeth_card *card)
{
return (card->state == CARD_STATE_SOFTSETUP) ||
(card->state == CARD_STATE_UP);
}
static ssize_t qeth_bridge_port_role_state_show(struct device *dev,
struct device_attribute *attr, char *buf,
int show_state)
{
struct qeth_card *card = dev_get_drvdata(dev);
enum qeth_sbp_states state = QETH_SBP_STATE_INACTIVE;
int rc = 0;
char *word;
if (!card)
return -EINVAL;
mutex_lock(&card->conf_mutex);
if (qeth_card_hw_is_reachable(card) &&
card->options.sbp.supported_funcs)
rc = qeth_bridgeport_query_ports(card,
&card->options.sbp.role, &state);
if (!rc) {
if (show_state)
switch (state) {
case QETH_SBP_STATE_INACTIVE:
word = "inactive"; break;
case QETH_SBP_STATE_STANDBY:
word = "standby"; break;
case QETH_SBP_STATE_ACTIVE:
word = "active"; break;
default:
rc = -EIO;
}
else
switch (card->options.sbp.role) {
case QETH_SBP_ROLE_NONE:
word = "none"; break;
case QETH_SBP_ROLE_PRIMARY:
word = "primary"; break;
case QETH_SBP_ROLE_SECONDARY:
word = "secondary"; break;
default:
rc = -EIO;
}
if (rc)
QETH_CARD_TEXT_(card, 2, "SBP%02x:%02x",
card->options.sbp.role, state);
else
rc = sprintf(buf, "%s\n", word);
}
mutex_unlock(&card->conf_mutex);
return rc;
}
static ssize_t qeth_bridge_port_role_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return qeth_bridge_port_role_state_show(dev, attr, buf, 0);
}
static ssize_t qeth_bridge_port_role_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct qeth_card *card = dev_get_drvdata(dev);
int rc = 0;
enum qeth_sbp_roles role;
if (!card)
return -EINVAL;
if (sysfs_streq(buf, "primary"))
role = QETH_SBP_ROLE_PRIMARY;
else if (sysfs_streq(buf, "secondary"))
role = QETH_SBP_ROLE_SECONDARY;
else if (sysfs_streq(buf, "none"))
role = QETH_SBP_ROLE_NONE;
else
return -EINVAL;
mutex_lock(&card->conf_mutex);
if (qeth_card_hw_is_reachable(card)) {
rc = qeth_bridgeport_setrole(card, role);
if (!rc)
card->options.sbp.role = role;
} else
card->options.sbp.role = role;
mutex_unlock(&card->conf_mutex);
return rc ? rc : count;
}
static ssize_t qeth_bridge_port_state_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return qeth_bridge_port_role_state_show(dev, attr, buf, 1);
}
static ssize_t qeth_bridgeport_hostnotification_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct qeth_card *card = dev_get_drvdata(dev);
int enabled;
if (!card)
return -EINVAL;
mutex_lock(&card->conf_mutex);
enabled = card->options.sbp.hostnotification;
mutex_unlock(&card->conf_mutex);
return sprintf(buf, "%d\n", enabled);
}
static ssize_t qeth_bridgeport_hostnotification_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct qeth_card *card = dev_get_drvdata(dev);
int rc = 0;
int enable;
if (!card)
return -EINVAL;
if (sysfs_streq(buf, "0"))
enable = 0;
else if (sysfs_streq(buf, "1"))
enable = 1;
else
return -EINVAL;
mutex_lock(&card->conf_mutex);
if (qeth_card_hw_is_reachable(card)) {
rc = qeth_bridgeport_an_set(card, enable);
if (!rc)
card->options.sbp.hostnotification = enable;
} else
card->options.sbp.hostnotification = enable;
mutex_unlock(&card->conf_mutex);
return rc ? rc : count;
}
int qeth_l2_create_device_attributes(struct device *dev)
{
return sysfs_create_group(&dev->kobj, &qeth_l2_bridgeport_attr_group);
}
void qeth_l2_remove_device_attributes(struct device *dev)
{
sysfs_remove_group(&dev->kobj, &qeth_l2_bridgeport_attr_group);
}
void qeth_l2_setup_bridgeport_attrs(struct qeth_card *card)
{
int rc;
if (!card)
return;
if (!card->options.sbp.supported_funcs)
return;
if (card->options.sbp.role != QETH_SBP_ROLE_NONE) {
qeth_bridgeport_setrole(card, card->options.sbp.role);
qeth_bridgeport_query_ports(card,
&card->options.sbp.role, NULL);
}
if (card->options.sbp.hostnotification) {
rc = qeth_bridgeport_an_set(card, 1);
if (rc)
card->options.sbp.hostnotification = 0;
} else
qeth_bridgeport_an_set(card, 0);
}
