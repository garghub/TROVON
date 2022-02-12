static inline void pmic_arb_base_write(struct spmi_pmic_arb *pmic_arb,
u32 offset, u32 val)
{
writel_relaxed(val, pmic_arb->wr_base + offset);
}
static inline void pmic_arb_set_rd_cmd(struct spmi_pmic_arb *pmic_arb,
u32 offset, u32 val)
{
writel_relaxed(val, pmic_arb->rd_base + offset);
}
static void
pmic_arb_read_data(struct spmi_pmic_arb *pmic_arb, u8 *buf, u32 reg, u8 bc)
{
u32 data = __raw_readl(pmic_arb->rd_base + reg);
memcpy(buf, &data, (bc & 3) + 1);
}
static void pmic_arb_write_data(struct spmi_pmic_arb *pmic_arb, const u8 *buf,
u32 reg, u8 bc)
{
u32 data = 0;
memcpy(&data, buf, (bc & 3) + 1);
__raw_writel(data, pmic_arb->wr_base + reg);
}
static int pmic_arb_wait_for_done(struct spmi_controller *ctrl,
void __iomem *base, u8 sid, u16 addr,
enum pmic_arb_channel ch_type)
{
struct spmi_pmic_arb *pmic_arb = spmi_controller_get_drvdata(ctrl);
u32 status = 0;
u32 timeout = PMIC_ARB_TIMEOUT_US;
u32 offset;
int rc;
rc = pmic_arb->ver_ops->offset(pmic_arb, sid, addr, ch_type);
if (rc < 0)
return rc;
offset = rc;
offset += PMIC_ARB_STATUS;
while (timeout--) {
status = readl_relaxed(base + offset);
if (status & PMIC_ARB_STATUS_DONE) {
if (status & PMIC_ARB_STATUS_DENIED) {
dev_err(&ctrl->dev, "%s: transaction denied (0x%x)\n",
__func__, status);
return -EPERM;
}
if (status & PMIC_ARB_STATUS_FAILURE) {
dev_err(&ctrl->dev, "%s: transaction failed (0x%x)\n",
__func__, status);
return -EIO;
}
if (status & PMIC_ARB_STATUS_DROPPED) {
dev_err(&ctrl->dev, "%s: transaction dropped (0x%x)\n",
__func__, status);
return -EIO;
}
return 0;
}
udelay(1);
}
dev_err(&ctrl->dev, "%s: timeout, status 0x%x\n",
__func__, status);
return -ETIMEDOUT;
}
static int
pmic_arb_non_data_cmd_v1(struct spmi_controller *ctrl, u8 opc, u8 sid)
{
struct spmi_pmic_arb *pmic_arb = spmi_controller_get_drvdata(ctrl);
unsigned long flags;
u32 cmd;
int rc;
u32 offset;
rc = pmic_arb->ver_ops->offset(pmic_arb, sid, 0, PMIC_ARB_CHANNEL_RW);
if (rc < 0)
return rc;
offset = rc;
cmd = ((opc | 0x40) << 27) | ((sid & 0xf) << 20);
raw_spin_lock_irqsave(&pmic_arb->lock, flags);
pmic_arb_base_write(pmic_arb, offset + PMIC_ARB_CMD, cmd);
rc = pmic_arb_wait_for_done(ctrl, pmic_arb->wr_base, sid, 0,
PMIC_ARB_CHANNEL_RW);
raw_spin_unlock_irqrestore(&pmic_arb->lock, flags);
return rc;
}
static int
pmic_arb_non_data_cmd_v2(struct spmi_controller *ctrl, u8 opc, u8 sid)
{
return -EOPNOTSUPP;
}
static int pmic_arb_cmd(struct spmi_controller *ctrl, u8 opc, u8 sid)
{
struct spmi_pmic_arb *pmic_arb = spmi_controller_get_drvdata(ctrl);
dev_dbg(&ctrl->dev, "cmd op:0x%x sid:%d\n", opc, sid);
if (opc < SPMI_CMD_RESET || opc > SPMI_CMD_WAKEUP)
return -EINVAL;
return pmic_arb->ver_ops->non_data_cmd(ctrl, opc, sid);
}
static int pmic_arb_read_cmd(struct spmi_controller *ctrl, u8 opc, u8 sid,
u16 addr, u8 *buf, size_t len)
{
struct spmi_pmic_arb *pmic_arb = spmi_controller_get_drvdata(ctrl);
unsigned long flags;
u8 bc = len - 1;
u32 cmd;
int rc;
u32 offset;
rc = pmic_arb->ver_ops->offset(pmic_arb, sid, addr,
PMIC_ARB_CHANNEL_OBS);
if (rc < 0)
return rc;
offset = rc;
if (bc >= PMIC_ARB_MAX_TRANS_BYTES) {
dev_err(&ctrl->dev, "pmic-arb supports 1..%d bytes per trans, but:%zu requested",
PMIC_ARB_MAX_TRANS_BYTES, len);
return -EINVAL;
}
if (opc >= 0x60 && opc <= 0x7F)
opc = PMIC_ARB_OP_READ;
else if (opc >= 0x20 && opc <= 0x2F)
opc = PMIC_ARB_OP_EXT_READ;
else if (opc >= 0x38 && opc <= 0x3F)
opc = PMIC_ARB_OP_EXT_READL;
else
return -EINVAL;
cmd = pmic_arb->ver_ops->fmt_cmd(opc, sid, addr, bc);
raw_spin_lock_irqsave(&pmic_arb->lock, flags);
pmic_arb_set_rd_cmd(pmic_arb, offset + PMIC_ARB_CMD, cmd);
rc = pmic_arb_wait_for_done(ctrl, pmic_arb->rd_base, sid, addr,
PMIC_ARB_CHANNEL_OBS);
if (rc)
goto done;
pmic_arb_read_data(pmic_arb, buf, offset + PMIC_ARB_RDATA0,
min_t(u8, bc, 3));
if (bc > 3)
pmic_arb_read_data(pmic_arb, buf + 4, offset + PMIC_ARB_RDATA1,
bc - 4);
done:
raw_spin_unlock_irqrestore(&pmic_arb->lock, flags);
return rc;
}
static int pmic_arb_write_cmd(struct spmi_controller *ctrl, u8 opc, u8 sid,
u16 addr, const u8 *buf, size_t len)
{
struct spmi_pmic_arb *pmic_arb = spmi_controller_get_drvdata(ctrl);
unsigned long flags;
u8 bc = len - 1;
u32 cmd;
int rc;
u32 offset;
rc = pmic_arb->ver_ops->offset(pmic_arb, sid, addr,
PMIC_ARB_CHANNEL_RW);
if (rc < 0)
return rc;
offset = rc;
if (bc >= PMIC_ARB_MAX_TRANS_BYTES) {
dev_err(&ctrl->dev, "pmic-arb supports 1..%d bytes per trans, but:%zu requested",
PMIC_ARB_MAX_TRANS_BYTES, len);
return -EINVAL;
}
if (opc >= 0x40 && opc <= 0x5F)
opc = PMIC_ARB_OP_WRITE;
else if (opc <= 0x0F)
opc = PMIC_ARB_OP_EXT_WRITE;
else if (opc >= 0x30 && opc <= 0x37)
opc = PMIC_ARB_OP_EXT_WRITEL;
else if (opc >= 0x80)
opc = PMIC_ARB_OP_ZERO_WRITE;
else
return -EINVAL;
cmd = pmic_arb->ver_ops->fmt_cmd(opc, sid, addr, bc);
raw_spin_lock_irqsave(&pmic_arb->lock, flags);
pmic_arb_write_data(pmic_arb, buf, offset + PMIC_ARB_WDATA0,
min_t(u8, bc, 3));
if (bc > 3)
pmic_arb_write_data(pmic_arb, buf + 4, offset + PMIC_ARB_WDATA1,
bc - 4);
pmic_arb_base_write(pmic_arb, offset + PMIC_ARB_CMD, cmd);
rc = pmic_arb_wait_for_done(ctrl, pmic_arb->wr_base, sid, addr,
PMIC_ARB_CHANNEL_RW);
raw_spin_unlock_irqrestore(&pmic_arb->lock, flags);
return rc;
}
static void qpnpint_spmi_write(struct irq_data *d, u8 reg, void *buf,
size_t len)
{
struct spmi_pmic_arb *pmic_arb = irq_data_get_irq_chip_data(d);
u8 sid = hwirq_to_sid(d->hwirq);
u8 per = hwirq_to_per(d->hwirq);
if (pmic_arb_write_cmd(pmic_arb->spmic, SPMI_CMD_EXT_WRITEL, sid,
(per << 8) + reg, buf, len))
dev_err_ratelimited(&pmic_arb->spmic->dev, "failed irqchip transaction on %x\n",
d->irq);
}
static void qpnpint_spmi_read(struct irq_data *d, u8 reg, void *buf, size_t len)
{
struct spmi_pmic_arb *pmic_arb = irq_data_get_irq_chip_data(d);
u8 sid = hwirq_to_sid(d->hwirq);
u8 per = hwirq_to_per(d->hwirq);
if (pmic_arb_read_cmd(pmic_arb->spmic, SPMI_CMD_EXT_READL, sid,
(per << 8) + reg, buf, len))
dev_err_ratelimited(&pmic_arb->spmic->dev, "failed irqchip transaction on %x\n",
d->irq);
}
static void cleanup_irq(struct spmi_pmic_arb *pmic_arb, u16 apid, int id)
{
u16 ppid = pmic_arb->apid_data[apid].ppid;
u8 sid = ppid >> 8;
u8 per = ppid & 0xFF;
u8 irq_mask = BIT(id);
writel_relaxed(irq_mask, pmic_arb->ver_ops->irq_clear(pmic_arb, apid));
if (pmic_arb_write_cmd(pmic_arb->spmic, SPMI_CMD_EXT_WRITEL, sid,
(per << 8) + QPNPINT_REG_LATCHED_CLR, &irq_mask, 1))
dev_err_ratelimited(&pmic_arb->spmic->dev, "failed to ack irq_mask = 0x%x for ppid = %x\n",
irq_mask, ppid);
if (pmic_arb_write_cmd(pmic_arb->spmic, SPMI_CMD_EXT_WRITEL, sid,
(per << 8) + QPNPINT_REG_EN_CLR, &irq_mask, 1))
dev_err_ratelimited(&pmic_arb->spmic->dev, "failed to ack irq_mask = 0x%x for ppid = %x\n",
irq_mask, ppid);
}
static void periph_interrupt(struct spmi_pmic_arb *pmic_arb, u16 apid)
{
unsigned int irq;
u32 status;
int id;
u8 sid = (pmic_arb->apid_data[apid].ppid >> 8) & 0xF;
u8 per = pmic_arb->apid_data[apid].ppid & 0xFF;
status = readl_relaxed(pmic_arb->ver_ops->irq_status(pmic_arb, apid));
while (status) {
id = ffs(status) - 1;
status &= ~BIT(id);
irq = irq_find_mapping(pmic_arb->domain,
spec_to_hwirq(sid, per, id, apid));
if (irq == 0) {
cleanup_irq(pmic_arb, apid, id);
continue;
}
generic_handle_irq(irq);
}
}
static void pmic_arb_chained_irq(struct irq_desc *desc)
{
struct spmi_pmic_arb *pmic_arb = irq_desc_get_handler_data(desc);
const struct pmic_arb_ver_ops *ver_ops = pmic_arb->ver_ops;
struct irq_chip *chip = irq_desc_get_chip(desc);
int first = pmic_arb->min_apid >> 5;
int last = pmic_arb->max_apid >> 5;
u8 ee = pmic_arb->ee;
u32 status, enable;
int i, id, apid;
chained_irq_enter(chip, desc);
for (i = first; i <= last; ++i) {
status = readl_relaxed(
ver_ops->owner_acc_status(pmic_arb, ee, i));
while (status) {
id = ffs(status) - 1;
status &= ~BIT(id);
apid = id + i * 32;
enable = readl_relaxed(
ver_ops->acc_enable(pmic_arb, apid));
if (enable & SPMI_PIC_ACC_ENABLE_BIT)
periph_interrupt(pmic_arb, apid);
}
}
chained_irq_exit(chip, desc);
}
static void qpnpint_irq_ack(struct irq_data *d)
{
struct spmi_pmic_arb *pmic_arb = irq_data_get_irq_chip_data(d);
u8 irq = hwirq_to_irq(d->hwirq);
u16 apid = hwirq_to_apid(d->hwirq);
u8 data;
writel_relaxed(BIT(irq), pmic_arb->ver_ops->irq_clear(pmic_arb, apid));
data = BIT(irq);
qpnpint_spmi_write(d, QPNPINT_REG_LATCHED_CLR, &data, 1);
}
static void qpnpint_irq_mask(struct irq_data *d)
{
u8 irq = hwirq_to_irq(d->hwirq);
u8 data = BIT(irq);
qpnpint_spmi_write(d, QPNPINT_REG_EN_CLR, &data, 1);
}
static void qpnpint_irq_unmask(struct irq_data *d)
{
struct spmi_pmic_arb *pmic_arb = irq_data_get_irq_chip_data(d);
const struct pmic_arb_ver_ops *ver_ops = pmic_arb->ver_ops;
u8 irq = hwirq_to_irq(d->hwirq);
u16 apid = hwirq_to_apid(d->hwirq);
u8 buf[2];
writel_relaxed(SPMI_PIC_ACC_ENABLE_BIT,
ver_ops->acc_enable(pmic_arb, apid));
qpnpint_spmi_read(d, QPNPINT_REG_EN_SET, &buf[0], 1);
if (!(buf[0] & BIT(irq))) {
buf[0] = BIT(irq);
buf[1] = BIT(irq);
qpnpint_spmi_write(d, QPNPINT_REG_LATCHED_CLR, &buf, 2);
}
}
static int qpnpint_irq_set_type(struct irq_data *d, unsigned int flow_type)
{
struct spmi_pmic_arb_qpnpint_type type;
irq_flow_handler_t flow_handler;
u8 irq = hwirq_to_irq(d->hwirq);
qpnpint_spmi_read(d, QPNPINT_REG_SET_TYPE, &type, sizeof(type));
if (flow_type & (IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING)) {
type.type |= BIT(irq);
if (flow_type & IRQF_TRIGGER_RISING)
type.polarity_high |= BIT(irq);
if (flow_type & IRQF_TRIGGER_FALLING)
type.polarity_low |= BIT(irq);
flow_handler = handle_edge_irq;
} else {
if ((flow_type & (IRQF_TRIGGER_HIGH)) &&
(flow_type & (IRQF_TRIGGER_LOW)))
return -EINVAL;
type.type &= ~BIT(irq);
if (flow_type & IRQF_TRIGGER_HIGH)
type.polarity_high |= BIT(irq);
else
type.polarity_low |= BIT(irq);
flow_handler = handle_level_irq;
}
qpnpint_spmi_write(d, QPNPINT_REG_SET_TYPE, &type, sizeof(type));
irq_set_handler_locked(d, flow_handler);
return 0;
}
static int qpnpint_irq_set_wake(struct irq_data *d, unsigned int on)
{
struct spmi_pmic_arb *pmic_arb = irq_data_get_irq_chip_data(d);
return irq_set_irq_wake(pmic_arb->irq, on);
}
static int qpnpint_get_irqchip_state(struct irq_data *d,
enum irqchip_irq_state which,
bool *state)
{
u8 irq = hwirq_to_irq(d->hwirq);
u8 status = 0;
if (which != IRQCHIP_STATE_LINE_LEVEL)
return -EINVAL;
qpnpint_spmi_read(d, QPNPINT_REG_RT_STS, &status, 1);
*state = !!(status & BIT(irq));
return 0;
}
static int qpnpint_irq_request_resources(struct irq_data *d)
{
struct spmi_pmic_arb *pmic_arb = irq_data_get_irq_chip_data(d);
u16 periph = hwirq_to_per(d->hwirq);
u16 apid = hwirq_to_apid(d->hwirq);
u16 sid = hwirq_to_sid(d->hwirq);
u16 irq = hwirq_to_irq(d->hwirq);
if (pmic_arb->apid_data[apid].irq_ee != pmic_arb->ee) {
dev_err(&pmic_arb->spmic->dev, "failed to xlate sid = %#x, periph = %#x, irq = %u: ee=%u but owner=%u\n",
sid, periph, irq, pmic_arb->ee,
pmic_arb->apid_data[apid].irq_ee);
return -ENODEV;
}
return 0;
}
static int qpnpint_irq_domain_dt_translate(struct irq_domain *d,
struct device_node *controller,
const u32 *intspec,
unsigned int intsize,
unsigned long *out_hwirq,
unsigned int *out_type)
{
struct spmi_pmic_arb *pmic_arb = d->host_data;
u16 apid, ppid;
int rc;
dev_dbg(&pmic_arb->spmic->dev, "intspec[0] 0x%1x intspec[1] 0x%02x intspec[2] 0x%02x\n",
intspec[0], intspec[1], intspec[2]);
if (irq_domain_get_of_node(d) != controller)
return -EINVAL;
if (intsize != 4)
return -EINVAL;
if (intspec[0] > 0xF || intspec[1] > 0xFF || intspec[2] > 0x7)
return -EINVAL;
ppid = intspec[0] << 8 | intspec[1];
rc = pmic_arb->ver_ops->ppid_to_apid(pmic_arb, ppid);
if (rc < 0) {
dev_err(&pmic_arb->spmic->dev, "failed to xlate sid = %#x, periph = %#x, irq = %u rc = %d\n",
intspec[0], intspec[1], intspec[2], rc);
return rc;
}
apid = rc;
if (apid > pmic_arb->max_apid)
pmic_arb->max_apid = apid;
if (apid < pmic_arb->min_apid)
pmic_arb->min_apid = apid;
*out_hwirq = spec_to_hwirq(intspec[0], intspec[1], intspec[2], apid);
*out_type = intspec[3] & IRQ_TYPE_SENSE_MASK;
dev_dbg(&pmic_arb->spmic->dev, "out_hwirq = %lu\n", *out_hwirq);
return 0;
}
static int qpnpint_irq_domain_map(struct irq_domain *d,
unsigned int virq,
irq_hw_number_t hwirq)
{
struct spmi_pmic_arb *pmic_arb = d->host_data;
dev_dbg(&pmic_arb->spmic->dev, "virq = %u, hwirq = %lu\n", virq, hwirq);
irq_set_chip_and_handler(virq, &pmic_arb_irqchip, handle_level_irq);
irq_set_chip_data(virq, d->host_data);
irq_set_noprobe(virq);
return 0;
}
static int pmic_arb_ppid_to_apid_v1(struct spmi_pmic_arb *pmic_arb, u16 ppid)
{
u32 *mapping_table = pmic_arb->mapping_table;
int index = 0, i;
u16 apid_valid;
u16 apid;
u32 data;
apid_valid = pmic_arb->ppid_to_apid[ppid];
if (apid_valid & PMIC_ARB_APID_VALID) {
apid = apid_valid & ~PMIC_ARB_APID_VALID;
return apid;
}
for (i = 0; i < SPMI_MAPPING_TABLE_TREE_DEPTH; ++i) {
if (!test_and_set_bit(index, pmic_arb->mapping_table_valid))
mapping_table[index] = readl_relaxed(pmic_arb->cnfg +
SPMI_MAPPING_TABLE_REG(index));
data = mapping_table[index];
if (ppid & BIT(SPMI_MAPPING_BIT_INDEX(data))) {
if (SPMI_MAPPING_BIT_IS_1_FLAG(data)) {
index = SPMI_MAPPING_BIT_IS_1_RESULT(data);
} else {
apid = SPMI_MAPPING_BIT_IS_1_RESULT(data);
pmic_arb->ppid_to_apid[ppid]
= apid | PMIC_ARB_APID_VALID;
pmic_arb->apid_data[apid].ppid = ppid;
return apid;
}
} else {
if (SPMI_MAPPING_BIT_IS_0_FLAG(data)) {
index = SPMI_MAPPING_BIT_IS_0_RESULT(data);
} else {
apid = SPMI_MAPPING_BIT_IS_0_RESULT(data);
pmic_arb->ppid_to_apid[ppid]
= apid | PMIC_ARB_APID_VALID;
pmic_arb->apid_data[apid].ppid = ppid;
return apid;
}
}
}
return -ENODEV;
}
static int pmic_arb_offset_v1(struct spmi_pmic_arb *pmic_arb, u8 sid, u16 addr,
enum pmic_arb_channel ch_type)
{
return 0x800 + 0x80 * pmic_arb->channel;
}
static u16 pmic_arb_find_apid(struct spmi_pmic_arb *pmic_arb, u16 ppid)
{
struct apid_data *apidd = &pmic_arb->apid_data[pmic_arb->last_apid];
u32 regval, offset;
u16 id, apid;
for (apid = pmic_arb->last_apid; ; apid++, apidd++) {
offset = pmic_arb->ver_ops->apid_map_offset(apid);
if (offset >= pmic_arb->core_size)
break;
regval = readl_relaxed(pmic_arb->cnfg +
SPMI_OWNERSHIP_TABLE_REG(apid));
apidd->irq_ee = SPMI_OWNERSHIP_PERIPH2OWNER(regval);
apidd->write_ee = apidd->irq_ee;
regval = readl_relaxed(pmic_arb->core + offset);
if (!regval)
continue;
id = (regval >> 8) & PMIC_ARB_PPID_MASK;
pmic_arb->ppid_to_apid[id] = apid | PMIC_ARB_APID_VALID;
apidd->ppid = id;
if (id == ppid) {
apid |= PMIC_ARB_APID_VALID;
break;
}
}
pmic_arb->last_apid = apid & ~PMIC_ARB_APID_VALID;
return apid;
}
static int pmic_arb_ppid_to_apid_v2(struct spmi_pmic_arb *pmic_arb, u16 ppid)
{
u16 apid_valid;
apid_valid = pmic_arb->ppid_to_apid[ppid];
if (!(apid_valid & PMIC_ARB_APID_VALID))
apid_valid = pmic_arb_find_apid(pmic_arb, ppid);
if (!(apid_valid & PMIC_ARB_APID_VALID))
return -ENODEV;
return apid_valid & ~PMIC_ARB_APID_VALID;
}
static int pmic_arb_read_apid_map_v5(struct spmi_pmic_arb *pmic_arb)
{
struct apid_data *apidd = pmic_arb->apid_data;
struct apid_data *prev_apidd;
u16 i, apid, ppid;
bool valid, is_irq_ee;
u32 regval, offset;
for (i = 0; ; i++, apidd++) {
offset = pmic_arb->ver_ops->apid_map_offset(i);
if (offset >= pmic_arb->core_size)
break;
regval = readl_relaxed(pmic_arb->core + offset);
if (!regval)
continue;
ppid = (regval >> 8) & PMIC_ARB_PPID_MASK;
is_irq_ee = PMIC_ARB_CHAN_IS_IRQ_OWNER(regval);
regval = readl_relaxed(pmic_arb->cnfg +
SPMI_OWNERSHIP_TABLE_REG(i));
apidd->write_ee = SPMI_OWNERSHIP_PERIPH2OWNER(regval);
apidd->irq_ee = is_irq_ee ? apidd->write_ee : INVALID_EE;
valid = pmic_arb->ppid_to_apid[ppid] & PMIC_ARB_APID_VALID;
apid = pmic_arb->ppid_to_apid[ppid] & ~PMIC_ARB_APID_VALID;
prev_apidd = &pmic_arb->apid_data[apid];
if (valid && is_irq_ee &&
prev_apidd->write_ee == pmic_arb->ee) {
prev_apidd->irq_ee = apidd->irq_ee;
} else if (!valid || is_irq_ee) {
pmic_arb->ppid_to_apid[ppid] = i | PMIC_ARB_APID_VALID;
}
apidd->ppid = ppid;
pmic_arb->last_apid = i;
}
dev_dbg(&pmic_arb->spmic->dev, "PPID APID Write-EE IRQ-EE\n");
for (ppid = 0; ppid < PMIC_ARB_MAX_PPID; ppid++) {
apid = pmic_arb->ppid_to_apid[ppid];
if (apid & PMIC_ARB_APID_VALID) {
apid &= ~PMIC_ARB_APID_VALID;
apidd = &pmic_arb->apid_data[apid];
dev_dbg(&pmic_arb->spmic->dev, "%#03X %3u %2u %2u\n",
ppid, apid, apidd->write_ee, apidd->irq_ee);
}
}
return 0;
}
static int pmic_arb_ppid_to_apid_v5(struct spmi_pmic_arb *pmic_arb, u16 ppid)
{
if (!(pmic_arb->ppid_to_apid[ppid] & PMIC_ARB_APID_VALID))
return -ENODEV;
return pmic_arb->ppid_to_apid[ppid] & ~PMIC_ARB_APID_VALID;
}
static int pmic_arb_offset_v2(struct spmi_pmic_arb *pmic_arb, u8 sid, u16 addr,
enum pmic_arb_channel ch_type)
{
u16 apid;
u16 ppid;
int rc;
ppid = sid << 8 | ((addr >> 8) & 0xFF);
rc = pmic_arb_ppid_to_apid_v2(pmic_arb, ppid);
if (rc < 0)
return rc;
apid = rc;
return 0x1000 * pmic_arb->ee + 0x8000 * apid;
}
static int pmic_arb_offset_v5(struct spmi_pmic_arb *pmic_arb, u8 sid, u16 addr,
enum pmic_arb_channel ch_type)
{
u16 apid;
int rc;
u32 offset = 0;
u16 ppid = (sid << 8) | (addr >> 8);
rc = pmic_arb_ppid_to_apid_v5(pmic_arb, ppid);
if (rc < 0)
return rc;
apid = rc;
switch (ch_type) {
case PMIC_ARB_CHANNEL_OBS:
offset = 0x10000 * pmic_arb->ee + 0x80 * apid;
break;
case PMIC_ARB_CHANNEL_RW:
offset = 0x10000 * apid;
break;
}
return offset;
}
static u32 pmic_arb_fmt_cmd_v1(u8 opc, u8 sid, u16 addr, u8 bc)
{
return (opc << 27) | ((sid & 0xf) << 20) | (addr << 4) | (bc & 0x7);
}
static u32 pmic_arb_fmt_cmd_v2(u8 opc, u8 sid, u16 addr, u8 bc)
{
return (opc << 27) | ((addr & 0xff) << 4) | (bc & 0x7);
}
static void __iomem *
pmic_arb_owner_acc_status_v1(struct spmi_pmic_arb *pmic_arb, u8 m, u16 n)
{
return pmic_arb->intr + 0x20 * m + 0x4 * n;
}
static void __iomem *
pmic_arb_owner_acc_status_v2(struct spmi_pmic_arb *pmic_arb, u8 m, u16 n)
{
return pmic_arb->intr + 0x100000 + 0x1000 * m + 0x4 * n;
}
static void __iomem *
pmic_arb_owner_acc_status_v3(struct spmi_pmic_arb *pmic_arb, u8 m, u16 n)
{
return pmic_arb->intr + 0x200000 + 0x1000 * m + 0x4 * n;
}
static void __iomem *
pmic_arb_owner_acc_status_v5(struct spmi_pmic_arb *pmic_arb, u8 m, u16 n)
{
return pmic_arb->intr + 0x10000 * m + 0x4 * n;
}
static void __iomem *
pmic_arb_acc_enable_v1(struct spmi_pmic_arb *pmic_arb, u16 n)
{
return pmic_arb->intr + 0x200 + 0x4 * n;
}
static void __iomem *
pmic_arb_acc_enable_v2(struct spmi_pmic_arb *pmic_arb, u16 n)
{
return pmic_arb->intr + 0x1000 * n;
}
static void __iomem *
pmic_arb_acc_enable_v5(struct spmi_pmic_arb *pmic_arb, u16 n)
{
return pmic_arb->wr_base + 0x100 + 0x10000 * n;
}
static void __iomem *
pmic_arb_irq_status_v1(struct spmi_pmic_arb *pmic_arb, u16 n)
{
return pmic_arb->intr + 0x600 + 0x4 * n;
}
static void __iomem *
pmic_arb_irq_status_v2(struct spmi_pmic_arb *pmic_arb, u16 n)
{
return pmic_arb->intr + 0x4 + 0x1000 * n;
}
static void __iomem *
pmic_arb_irq_status_v5(struct spmi_pmic_arb *pmic_arb, u16 n)
{
return pmic_arb->wr_base + 0x104 + 0x10000 * n;
}
static void __iomem *
pmic_arb_irq_clear_v1(struct spmi_pmic_arb *pmic_arb, u16 n)
{
return pmic_arb->intr + 0xA00 + 0x4 * n;
}
static void __iomem *
pmic_arb_irq_clear_v2(struct spmi_pmic_arb *pmic_arb, u16 n)
{
return pmic_arb->intr + 0x8 + 0x1000 * n;
}
static void __iomem *
pmic_arb_irq_clear_v5(struct spmi_pmic_arb *pmic_arb, u16 n)
{
return pmic_arb->wr_base + 0x108 + 0x10000 * n;
}
static u32 pmic_arb_apid_map_offset_v2(u16 n)
{
return 0x800 + 0x4 * n;
}
static u32 pmic_arb_apid_map_offset_v5(u16 n)
{
return 0x900 + 0x4 * n;
}
static int spmi_pmic_arb_probe(struct platform_device *pdev)
{
struct spmi_pmic_arb *pmic_arb;
struct spmi_controller *ctrl;
struct resource *res;
void __iomem *core;
u32 *mapping_table;
u32 channel, ee, hw_ver;
int err;
ctrl = spmi_controller_alloc(&pdev->dev, sizeof(*pmic_arb));
if (!ctrl)
return -ENOMEM;
pmic_arb = spmi_controller_get_drvdata(ctrl);
pmic_arb->spmic = ctrl;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "core");
core = devm_ioremap_resource(&ctrl->dev, res);
if (IS_ERR(core)) {
err = PTR_ERR(core);
goto err_put_ctrl;
}
pmic_arb->core_size = resource_size(res);
pmic_arb->ppid_to_apid = devm_kcalloc(&ctrl->dev, PMIC_ARB_MAX_PPID,
sizeof(*pmic_arb->ppid_to_apid),
GFP_KERNEL);
if (!pmic_arb->ppid_to_apid) {
err = -ENOMEM;
goto err_put_ctrl;
}
hw_ver = readl_relaxed(core + PMIC_ARB_VERSION);
if (hw_ver < PMIC_ARB_VERSION_V2_MIN) {
pmic_arb->ver_ops = &pmic_arb_v1;
pmic_arb->wr_base = core;
pmic_arb->rd_base = core;
} else {
pmic_arb->core = core;
if (hw_ver < PMIC_ARB_VERSION_V3_MIN)
pmic_arb->ver_ops = &pmic_arb_v2;
else if (hw_ver < PMIC_ARB_VERSION_V5_MIN)
pmic_arb->ver_ops = &pmic_arb_v3;
else
pmic_arb->ver_ops = &pmic_arb_v5;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"obsrvr");
pmic_arb->rd_base = devm_ioremap_resource(&ctrl->dev, res);
if (IS_ERR(pmic_arb->rd_base)) {
err = PTR_ERR(pmic_arb->rd_base);
goto err_put_ctrl;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"chnls");
pmic_arb->wr_base = devm_ioremap_resource(&ctrl->dev, res);
if (IS_ERR(pmic_arb->wr_base)) {
err = PTR_ERR(pmic_arb->wr_base);
goto err_put_ctrl;
}
}
dev_info(&ctrl->dev, "PMIC arbiter version %s (0x%x)\n",
pmic_arb->ver_ops->ver_str, hw_ver);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "intr");
pmic_arb->intr = devm_ioremap_resource(&ctrl->dev, res);
if (IS_ERR(pmic_arb->intr)) {
err = PTR_ERR(pmic_arb->intr);
goto err_put_ctrl;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "cnfg");
pmic_arb->cnfg = devm_ioremap_resource(&ctrl->dev, res);
if (IS_ERR(pmic_arb->cnfg)) {
err = PTR_ERR(pmic_arb->cnfg);
goto err_put_ctrl;
}
pmic_arb->irq = platform_get_irq_byname(pdev, "periph_irq");
if (pmic_arb->irq < 0) {
err = pmic_arb->irq;
goto err_put_ctrl;
}
err = of_property_read_u32(pdev->dev.of_node, "qcom,channel", &channel);
if (err) {
dev_err(&pdev->dev, "channel unspecified.\n");
goto err_put_ctrl;
}
if (channel > 5) {
dev_err(&pdev->dev, "invalid channel (%u) specified.\n",
channel);
err = -EINVAL;
goto err_put_ctrl;
}
pmic_arb->channel = channel;
err = of_property_read_u32(pdev->dev.of_node, "qcom,ee", &ee);
if (err) {
dev_err(&pdev->dev, "EE unspecified.\n");
goto err_put_ctrl;
}
if (ee > 5) {
dev_err(&pdev->dev, "invalid EE (%u) specified\n", ee);
err = -EINVAL;
goto err_put_ctrl;
}
pmic_arb->ee = ee;
mapping_table = devm_kcalloc(&ctrl->dev, PMIC_ARB_MAX_PERIPHS,
sizeof(*mapping_table), GFP_KERNEL);
if (!mapping_table) {
err = -ENOMEM;
goto err_put_ctrl;
}
pmic_arb->mapping_table = mapping_table;
pmic_arb->max_apid = 0;
pmic_arb->min_apid = PMIC_ARB_MAX_PERIPHS - 1;
platform_set_drvdata(pdev, ctrl);
raw_spin_lock_init(&pmic_arb->lock);
ctrl->cmd = pmic_arb_cmd;
ctrl->read_cmd = pmic_arb_read_cmd;
ctrl->write_cmd = pmic_arb_write_cmd;
if (hw_ver >= PMIC_ARB_VERSION_V5_MIN) {
err = pmic_arb_read_apid_map_v5(pmic_arb);
if (err) {
dev_err(&pdev->dev, "could not read APID->PPID mapping table, rc= %d\n",
err);
goto err_put_ctrl;
}
}
dev_dbg(&pdev->dev, "adding irq domain\n");
pmic_arb->domain = irq_domain_add_tree(pdev->dev.of_node,
&pmic_arb_irq_domain_ops, pmic_arb);
if (!pmic_arb->domain) {
dev_err(&pdev->dev, "unable to create irq_domain\n");
err = -ENOMEM;
goto err_put_ctrl;
}
irq_set_chained_handler_and_data(pmic_arb->irq, pmic_arb_chained_irq,
pmic_arb);
err = spmi_controller_add(ctrl);
if (err)
goto err_domain_remove;
return 0;
err_domain_remove:
irq_set_chained_handler_and_data(pmic_arb->irq, NULL, NULL);
irq_domain_remove(pmic_arb->domain);
err_put_ctrl:
spmi_controller_put(ctrl);
return err;
}
static int spmi_pmic_arb_remove(struct platform_device *pdev)
{
struct spmi_controller *ctrl = platform_get_drvdata(pdev);
struct spmi_pmic_arb *pmic_arb = spmi_controller_get_drvdata(ctrl);
spmi_controller_remove(ctrl);
irq_set_chained_handler_and_data(pmic_arb->irq, NULL, NULL);
irq_domain_remove(pmic_arb->domain);
spmi_controller_put(ctrl);
return 0;
}
