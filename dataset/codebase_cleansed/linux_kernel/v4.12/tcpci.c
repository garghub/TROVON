static inline struct tcpci *tcpc_to_tcpci(struct tcpc_dev *tcpc)
{
return container_of(tcpc, struct tcpci, tcpc);
}
static int tcpci_read16(struct tcpci *tcpci, unsigned int reg,
unsigned int *val)
{
return regmap_raw_read(tcpci->regmap, reg, val, sizeof(u16));
}
static int tcpci_write16(struct tcpci *tcpci, unsigned int reg, u16 val)
{
return regmap_raw_write(tcpci->regmap, reg, &val, sizeof(u16));
}
static int tcpci_set_cc(struct tcpc_dev *tcpc, enum typec_cc_status cc)
{
struct tcpci *tcpci = tcpc_to_tcpci(tcpc);
unsigned int reg;
int ret;
switch (cc) {
case TYPEC_CC_RA:
reg = (TCPC_ROLE_CTRL_CC_RA << TCPC_ROLE_CTRL_CC1_SHIFT) |
(TCPC_ROLE_CTRL_CC_RA << TCPC_ROLE_CTRL_CC2_SHIFT);
break;
case TYPEC_CC_RD:
reg = (TCPC_ROLE_CTRL_CC_RD << TCPC_ROLE_CTRL_CC1_SHIFT) |
(TCPC_ROLE_CTRL_CC_RD << TCPC_ROLE_CTRL_CC2_SHIFT);
break;
case TYPEC_CC_RP_DEF:
reg = (TCPC_ROLE_CTRL_CC_RP << TCPC_ROLE_CTRL_CC1_SHIFT) |
(TCPC_ROLE_CTRL_CC_RP << TCPC_ROLE_CTRL_CC2_SHIFT) |
(TCPC_ROLE_CTRL_RP_VAL_DEF <<
TCPC_ROLE_CTRL_RP_VAL_SHIFT);
break;
case TYPEC_CC_RP_1_5:
reg = (TCPC_ROLE_CTRL_CC_RP << TCPC_ROLE_CTRL_CC1_SHIFT) |
(TCPC_ROLE_CTRL_CC_RP << TCPC_ROLE_CTRL_CC2_SHIFT) |
(TCPC_ROLE_CTRL_RP_VAL_1_5 <<
TCPC_ROLE_CTRL_RP_VAL_SHIFT);
break;
case TYPEC_CC_RP_3_0:
reg = (TCPC_ROLE_CTRL_CC_RP << TCPC_ROLE_CTRL_CC1_SHIFT) |
(TCPC_ROLE_CTRL_CC_RP << TCPC_ROLE_CTRL_CC2_SHIFT) |
(TCPC_ROLE_CTRL_RP_VAL_3_0 <<
TCPC_ROLE_CTRL_RP_VAL_SHIFT);
break;
case TYPEC_CC_OPEN:
default:
reg = (TCPC_ROLE_CTRL_CC_OPEN << TCPC_ROLE_CTRL_CC1_SHIFT) |
(TCPC_ROLE_CTRL_CC_OPEN << TCPC_ROLE_CTRL_CC2_SHIFT);
break;
}
ret = regmap_write(tcpci->regmap, TCPC_ROLE_CTRL, reg);
if (ret < 0)
return ret;
return 0;
}
static int tcpci_start_drp_toggling(struct tcpc_dev *tcpc,
enum typec_cc_status cc)
{
struct tcpci *tcpci = tcpc_to_tcpci(tcpc);
unsigned int reg = TCPC_ROLE_CTRL_DRP;
switch (cc) {
default:
case TYPEC_CC_RP_DEF:
reg |= (TCPC_ROLE_CTRL_RP_VAL_DEF <<
TCPC_ROLE_CTRL_RP_VAL_SHIFT);
break;
case TYPEC_CC_RP_1_5:
reg |= (TCPC_ROLE_CTRL_RP_VAL_1_5 <<
TCPC_ROLE_CTRL_RP_VAL_SHIFT);
break;
case TYPEC_CC_RP_3_0:
reg |= (TCPC_ROLE_CTRL_RP_VAL_3_0 <<
TCPC_ROLE_CTRL_RP_VAL_SHIFT);
break;
}
return regmap_write(tcpci->regmap, TCPC_ROLE_CTRL, reg);
}
static enum typec_cc_status tcpci_to_typec_cc(unsigned int cc, bool sink)
{
switch (cc) {
case 0x1:
return sink ? TYPEC_CC_RP_DEF : TYPEC_CC_RA;
case 0x2:
return sink ? TYPEC_CC_RP_1_5 : TYPEC_CC_RD;
case 0x3:
if (sink)
return TYPEC_CC_RP_3_0;
case 0x0:
default:
return TYPEC_CC_OPEN;
}
}
static int tcpci_get_cc(struct tcpc_dev *tcpc,
enum typec_cc_status *cc1, enum typec_cc_status *cc2)
{
struct tcpci *tcpci = tcpc_to_tcpci(tcpc);
unsigned int reg;
int ret;
ret = regmap_read(tcpci->regmap, TCPC_CC_STATUS, &reg);
if (ret < 0)
return ret;
*cc1 = tcpci_to_typec_cc((reg >> TCPC_CC_STATUS_CC1_SHIFT) &
TCPC_CC_STATUS_CC1_MASK,
reg & TCPC_CC_STATUS_TERM);
*cc2 = tcpci_to_typec_cc((reg >> TCPC_CC_STATUS_CC2_SHIFT) &
TCPC_CC_STATUS_CC2_MASK,
reg & TCPC_CC_STATUS_TERM);
return 0;
}
static int tcpci_set_polarity(struct tcpc_dev *tcpc,
enum typec_cc_polarity polarity)
{
struct tcpci *tcpci = tcpc_to_tcpci(tcpc);
int ret;
ret = regmap_write(tcpci->regmap, TCPC_TCPC_CTRL,
(polarity == TYPEC_POLARITY_CC2) ?
TCPC_TCPC_CTRL_ORIENTATION : 0);
if (ret < 0)
return ret;
return 0;
}
static int tcpci_set_vconn(struct tcpc_dev *tcpc, bool enable)
{
struct tcpci *tcpci = tcpc_to_tcpci(tcpc);
int ret;
ret = regmap_write(tcpci->regmap, TCPC_POWER_CTRL,
enable ? TCPC_POWER_CTRL_VCONN_ENABLE : 0);
if (ret < 0)
return ret;
return 0;
}
static int tcpci_set_roles(struct tcpc_dev *tcpc, bool attached,
enum typec_role role, enum typec_data_role data)
{
struct tcpci *tcpci = tcpc_to_tcpci(tcpc);
unsigned int reg;
int ret;
reg = PD_REV20 << TCPC_MSG_HDR_INFO_REV_SHIFT;
if (role == TYPEC_SOURCE)
reg |= TCPC_MSG_HDR_INFO_PWR_ROLE;
if (data == TYPEC_HOST)
reg |= TCPC_MSG_HDR_INFO_DATA_ROLE;
ret = regmap_write(tcpci->regmap, TCPC_MSG_HDR_INFO, reg);
if (ret < 0)
return ret;
return 0;
}
static int tcpci_set_pd_rx(struct tcpc_dev *tcpc, bool enable)
{
struct tcpci *tcpci = tcpc_to_tcpci(tcpc);
unsigned int reg = 0;
int ret;
if (enable)
reg = TCPC_RX_DETECT_SOP | TCPC_RX_DETECT_HARD_RESET;
ret = regmap_write(tcpci->regmap, TCPC_RX_DETECT, reg);
if (ret < 0)
return ret;
return 0;
}
static int tcpci_get_vbus(struct tcpc_dev *tcpc)
{
struct tcpci *tcpci = tcpc_to_tcpci(tcpc);
unsigned int reg;
int ret;
ret = regmap_read(tcpci->regmap, TCPC_POWER_STATUS, &reg);
if (ret < 0)
return ret;
return !!(reg & TCPC_POWER_STATUS_VBUS_PRES);
}
static int tcpci_set_vbus(struct tcpc_dev *tcpc, bool source, bool sink)
{
struct tcpci *tcpci = tcpc_to_tcpci(tcpc);
int ret;
if (!source) {
ret = regmap_write(tcpci->regmap, TCPC_COMMAND,
TCPC_CMD_DISABLE_SRC_VBUS);
if (ret < 0)
return ret;
}
if (!sink) {
ret = regmap_write(tcpci->regmap, TCPC_COMMAND,
TCPC_CMD_DISABLE_SINK_VBUS);
if (ret < 0)
return ret;
}
if (source) {
ret = regmap_write(tcpci->regmap, TCPC_COMMAND,
TCPC_CMD_SRC_VBUS_DEFAULT);
if (ret < 0)
return ret;
}
if (sink) {
ret = regmap_write(tcpci->regmap, TCPC_COMMAND,
TCPC_CMD_SINK_VBUS);
if (ret < 0)
return ret;
}
return 0;
}
static int tcpci_pd_transmit(struct tcpc_dev *tcpc,
enum tcpm_transmit_type type,
const struct pd_message *msg)
{
struct tcpci *tcpci = tcpc_to_tcpci(tcpc);
unsigned int reg, cnt, header;
int ret;
cnt = msg ? pd_header_cnt(msg->header) * 4 : 0;
ret = regmap_write(tcpci->regmap, TCPC_TX_BYTE_CNT, cnt + 2);
if (ret < 0)
return ret;
header = msg ? msg->header : 0;
ret = tcpci_write16(tcpci, TCPC_TX_HDR, header);
if (ret < 0)
return ret;
if (cnt > 0) {
ret = regmap_raw_write(tcpci->regmap, TCPC_TX_DATA,
&msg->payload, cnt);
if (ret < 0)
return ret;
}
reg = (PD_RETRY_COUNT << TCPC_TRANSMIT_RETRY_SHIFT) |
(type << TCPC_TRANSMIT_TYPE_SHIFT);
ret = regmap_write(tcpci->regmap, TCPC_TRANSMIT, reg);
if (ret < 0)
return ret;
return 0;
}
static int tcpci_init(struct tcpc_dev *tcpc)
{
struct tcpci *tcpci = tcpc_to_tcpci(tcpc);
unsigned long timeout = jiffies + msecs_to_jiffies(2000);
unsigned int reg;
int ret;
while (time_before_eq(jiffies, timeout)) {
ret = regmap_read(tcpci->regmap, TCPC_POWER_STATUS, &reg);
if (ret < 0)
return ret;
if (!(reg & TCPC_POWER_STATUS_UNINIT))
break;
usleep_range(10000, 20000);
}
if (time_after(jiffies, timeout))
return -ETIMEDOUT;
ret = tcpci_write16(tcpci, TCPC_ALERT, 0xffff);
if (ret < 0)
return ret;
if (tcpci->controls_vbus)
reg = TCPC_POWER_STATUS_VBUS_PRES;
else
reg = 0;
ret = regmap_write(tcpci->regmap, TCPC_POWER_STATUS_MASK, reg);
if (ret < 0)
return ret;
reg = TCPC_ALERT_TX_SUCCESS | TCPC_ALERT_TX_FAILED |
TCPC_ALERT_TX_DISCARDED | TCPC_ALERT_RX_STATUS |
TCPC_ALERT_RX_HARD_RST | TCPC_ALERT_CC_STATUS;
if (tcpci->controls_vbus)
reg |= TCPC_ALERT_POWER_STATUS;
return tcpci_write16(tcpci, TCPC_ALERT_MASK, reg);
}
static irqreturn_t tcpci_irq(int irq, void *dev_id)
{
struct tcpci *tcpci = dev_id;
unsigned int status, reg;
tcpci_read16(tcpci, TCPC_ALERT, &status);
if (status & ~TCPC_ALERT_RX_STATUS)
tcpci_write16(tcpci, TCPC_ALERT,
status & ~TCPC_ALERT_RX_STATUS);
if (status & TCPC_ALERT_CC_STATUS)
tcpm_cc_change(tcpci->port);
if (status & TCPC_ALERT_POWER_STATUS) {
regmap_read(tcpci->regmap, TCPC_POWER_STATUS_MASK, &reg);
if (reg == 0xff)
tcpm_tcpc_reset(tcpci->port);
else
tcpm_vbus_change(tcpci->port);
}
if (status & TCPC_ALERT_RX_STATUS) {
struct pd_message msg;
unsigned int cnt;
regmap_read(tcpci->regmap, TCPC_RX_BYTE_CNT, &cnt);
tcpci_read16(tcpci, TCPC_RX_HDR, &reg);
msg.header = reg;
if (WARN_ON(cnt > sizeof(msg.payload)))
cnt = sizeof(msg.payload);
if (cnt > 0)
regmap_raw_read(tcpci->regmap, TCPC_RX_DATA,
&msg.payload, cnt);
tcpci_write16(tcpci, TCPC_ALERT, TCPC_ALERT_RX_STATUS);
tcpm_pd_receive(tcpci->port, &msg);
}
if (status & TCPC_ALERT_RX_HARD_RST)
tcpm_pd_hard_reset(tcpci->port);
if (status & TCPC_ALERT_TX_SUCCESS)
tcpm_pd_transmit_complete(tcpci->port, TCPC_TX_SUCCESS);
else if (status & TCPC_ALERT_TX_DISCARDED)
tcpm_pd_transmit_complete(tcpci->port, TCPC_TX_DISCARDED);
else if (status & TCPC_ALERT_TX_FAILED)
tcpm_pd_transmit_complete(tcpci->port, TCPC_TX_FAILED);
return IRQ_HANDLED;
}
static int tcpci_parse_config(struct tcpci *tcpci)
{
tcpci->controls_vbus = true;
tcpci->tcpc.config = &tcpci_tcpc_config;
return 0;
}
static int tcpci_probe(struct i2c_client *client,
const struct i2c_device_id *i2c_id)
{
struct tcpci *tcpci;
int err;
tcpci = devm_kzalloc(&client->dev, sizeof(*tcpci), GFP_KERNEL);
if (!tcpci)
return -ENOMEM;
tcpci->client = client;
tcpci->dev = &client->dev;
i2c_set_clientdata(client, tcpci);
tcpci->regmap = devm_regmap_init_i2c(client, &tcpci_regmap_config);
if (IS_ERR(tcpci->regmap))
return PTR_ERR(tcpci->regmap);
tcpci->tcpc.init = tcpci_init;
tcpci->tcpc.get_vbus = tcpci_get_vbus;
tcpci->tcpc.set_vbus = tcpci_set_vbus;
tcpci->tcpc.set_cc = tcpci_set_cc;
tcpci->tcpc.get_cc = tcpci_get_cc;
tcpci->tcpc.set_polarity = tcpci_set_polarity;
tcpci->tcpc.set_vconn = tcpci_set_vconn;
tcpci->tcpc.start_drp_toggling = tcpci_start_drp_toggling;
tcpci->tcpc.set_pd_rx = tcpci_set_pd_rx;
tcpci->tcpc.set_roles = tcpci_set_roles;
tcpci->tcpc.pd_transmit = tcpci_pd_transmit;
err = tcpci_parse_config(tcpci);
if (err < 0)
return err;
tcpci_write16(tcpci, TCPC_ALERT_MASK, 0);
err = devm_request_threaded_irq(tcpci->dev, client->irq, NULL,
tcpci_irq,
IRQF_ONESHOT | IRQF_TRIGGER_LOW,
dev_name(tcpci->dev), tcpci);
if (err < 0)
return err;
tcpci->port = tcpm_register_port(tcpci->dev, &tcpci->tcpc);
return PTR_ERR_OR_ZERO(tcpci->port);
}
static int tcpci_remove(struct i2c_client *client)
{
struct tcpci *tcpci = i2c_get_clientdata(client);
tcpm_unregister_port(tcpci->port);
return 0;
}
