static inline u32 pmic_arb_base_read(struct spmi_pmic_arb_dev *dev, u32 offset)
{
return readl_relaxed(dev->base + offset);
}
static inline void pmic_arb_base_write(struct spmi_pmic_arb_dev *dev,
u32 offset, u32 val)
{
writel_relaxed(val, dev->base + offset);
}
static void pa_read_data(struct spmi_pmic_arb_dev *dev, u8 *buf, u32 reg, u8 bc)
{
u32 data = pmic_arb_base_read(dev, reg);
memcpy(buf, &data, (bc & 3) + 1);
}
static void
pa_write_data(struct spmi_pmic_arb_dev *dev, const u8 *buf, u32 reg, u8 bc)
{
u32 data = 0;
memcpy(&data, buf, (bc & 3) + 1);
pmic_arb_base_write(dev, reg, data);
}
static int pmic_arb_wait_for_done(struct spmi_controller *ctrl)
{
struct spmi_pmic_arb_dev *dev = spmi_controller_get_drvdata(ctrl);
u32 status = 0;
u32 timeout = PMIC_ARB_TIMEOUT_US;
u32 offset = PMIC_ARB_STATUS(dev->channel);
while (timeout--) {
status = pmic_arb_base_read(dev, offset);
if (status & PMIC_ARB_STATUS_DONE) {
if (status & PMIC_ARB_STATUS_DENIED) {
dev_err(&ctrl->dev,
"%s: transaction denied (0x%x)\n",
__func__, status);
return -EPERM;
}
if (status & PMIC_ARB_STATUS_FAILURE) {
dev_err(&ctrl->dev,
"%s: transaction failed (0x%x)\n",
__func__, status);
return -EIO;
}
if (status & PMIC_ARB_STATUS_DROPPED) {
dev_err(&ctrl->dev,
"%s: transaction dropped (0x%x)\n",
__func__, status);
return -EIO;
}
return 0;
}
udelay(1);
}
dev_err(&ctrl->dev,
"%s: timeout, status 0x%x\n",
__func__, status);
return -ETIMEDOUT;
}
static int pmic_arb_cmd(struct spmi_controller *ctrl, u8 opc, u8 sid)
{
struct spmi_pmic_arb_dev *pmic_arb = spmi_controller_get_drvdata(ctrl);
unsigned long flags;
u32 cmd;
int rc;
if (opc < SPMI_CMD_RESET || opc > SPMI_CMD_WAKEUP)
return -EINVAL;
cmd = ((opc | 0x40) << 27) | ((sid & 0xf) << 20);
raw_spin_lock_irqsave(&pmic_arb->lock, flags);
pmic_arb_base_write(pmic_arb, PMIC_ARB_CMD(pmic_arb->channel), cmd);
rc = pmic_arb_wait_for_done(ctrl);
raw_spin_unlock_irqrestore(&pmic_arb->lock, flags);
return rc;
}
static int pmic_arb_read_cmd(struct spmi_controller *ctrl, u8 opc, u8 sid,
u16 addr, u8 *buf, size_t len)
{
struct spmi_pmic_arb_dev *pmic_arb = spmi_controller_get_drvdata(ctrl);
unsigned long flags;
u8 bc = len - 1;
u32 cmd;
int rc;
if (bc >= PMIC_ARB_MAX_TRANS_BYTES) {
dev_err(&ctrl->dev,
"pmic-arb supports 1..%d bytes per trans, but %d requested",
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
cmd = (opc << 27) | ((sid & 0xf) << 20) | (addr << 4) | (bc & 0x7);
raw_spin_lock_irqsave(&pmic_arb->lock, flags);
pmic_arb_base_write(pmic_arb, PMIC_ARB_CMD(pmic_arb->channel), cmd);
rc = pmic_arb_wait_for_done(ctrl);
if (rc)
goto done;
pa_read_data(pmic_arb, buf, PMIC_ARB_RDATA0(pmic_arb->channel),
min_t(u8, bc, 3));
if (bc > 3)
pa_read_data(pmic_arb, buf + 4,
PMIC_ARB_RDATA1(pmic_arb->channel), bc - 4);
done:
raw_spin_unlock_irqrestore(&pmic_arb->lock, flags);
return rc;
}
static int pmic_arb_write_cmd(struct spmi_controller *ctrl, u8 opc, u8 sid,
u16 addr, const u8 *buf, size_t len)
{
struct spmi_pmic_arb_dev *pmic_arb = spmi_controller_get_drvdata(ctrl);
unsigned long flags;
u8 bc = len - 1;
u32 cmd;
int rc;
if (bc >= PMIC_ARB_MAX_TRANS_BYTES) {
dev_err(&ctrl->dev,
"pmic-arb supports 1..%d bytes per trans, but:%d requested",
PMIC_ARB_MAX_TRANS_BYTES, len);
return -EINVAL;
}
if (opc >= 0x40 && opc <= 0x5F)
opc = PMIC_ARB_OP_WRITE;
else if (opc >= 0x00 && opc <= 0x0F)
opc = PMIC_ARB_OP_EXT_WRITE;
else if (opc >= 0x30 && opc <= 0x37)
opc = PMIC_ARB_OP_EXT_WRITEL;
else if (opc >= 0x80 && opc <= 0xFF)
opc = PMIC_ARB_OP_ZERO_WRITE;
else
return -EINVAL;
cmd = (opc << 27) | ((sid & 0xf) << 20) | (addr << 4) | (bc & 0x7);
raw_spin_lock_irqsave(&pmic_arb->lock, flags);
pa_write_data(pmic_arb, buf, PMIC_ARB_WDATA0(pmic_arb->channel)
, min_t(u8, bc, 3));
if (bc > 3)
pa_write_data(pmic_arb, buf + 4,
PMIC_ARB_WDATA1(pmic_arb->channel), bc - 4);
pmic_arb_base_write(pmic_arb, PMIC_ARB_CMD(pmic_arb->channel), cmd);
rc = pmic_arb_wait_for_done(ctrl);
raw_spin_unlock_irqrestore(&pmic_arb->lock, flags);
return rc;
}
static void qpnpint_spmi_write(struct irq_data *d, u8 reg, void *buf,
size_t len)
{
struct spmi_pmic_arb_dev *pa = irq_data_get_irq_chip_data(d);
u8 sid = d->hwirq >> 24;
u8 per = d->hwirq >> 16;
if (pmic_arb_write_cmd(pa->spmic, SPMI_CMD_EXT_WRITEL, sid,
(per << 8) + reg, buf, len))
dev_err_ratelimited(&pa->spmic->dev,
"failed irqchip transaction on %x\n",
d->irq);
}
static void qpnpint_spmi_read(struct irq_data *d, u8 reg, void *buf, size_t len)
{
struct spmi_pmic_arb_dev *pa = irq_data_get_irq_chip_data(d);
u8 sid = d->hwirq >> 24;
u8 per = d->hwirq >> 16;
if (pmic_arb_read_cmd(pa->spmic, SPMI_CMD_EXT_READL, sid,
(per << 8) + reg, buf, len))
dev_err_ratelimited(&pa->spmic->dev,
"failed irqchip transaction on %x\n",
d->irq);
}
static void periph_interrupt(struct spmi_pmic_arb_dev *pa, u8 apid)
{
unsigned int irq;
u32 status;
int id;
status = readl_relaxed(pa->intr + SPMI_PIC_IRQ_STATUS(apid));
while (status) {
id = ffs(status) - 1;
status &= ~(1 << id);
irq = irq_find_mapping(pa->domain,
pa->apid_to_ppid[apid] << 16
| id << 8
| apid);
generic_handle_irq(irq);
}
}
static void pmic_arb_chained_irq(unsigned int irq, struct irq_desc *desc)
{
struct spmi_pmic_arb_dev *pa = irq_get_handler_data(irq);
struct irq_chip *chip = irq_get_chip(irq);
void __iomem *intr = pa->intr;
int first = pa->min_apid >> 5;
int last = pa->max_apid >> 5;
u32 status;
int i, id;
chained_irq_enter(chip, desc);
for (i = first; i <= last; ++i) {
status = readl_relaxed(intr +
SPMI_PIC_OWNER_ACC_STATUS(pa->ee, i));
while (status) {
id = ffs(status) - 1;
status &= ~(1 << id);
periph_interrupt(pa, id + i * 32);
}
}
chained_irq_exit(chip, desc);
}
static void qpnpint_irq_ack(struct irq_data *d)
{
struct spmi_pmic_arb_dev *pa = irq_data_get_irq_chip_data(d);
u8 irq = d->hwirq >> 8;
u8 apid = d->hwirq;
unsigned long flags;
u8 data;
raw_spin_lock_irqsave(&pa->lock, flags);
writel_relaxed(1 << irq, pa->intr + SPMI_PIC_IRQ_CLEAR(apid));
raw_spin_unlock_irqrestore(&pa->lock, flags);
data = 1 << irq;
qpnpint_spmi_write(d, QPNPINT_REG_LATCHED_CLR, &data, 1);
}
static void qpnpint_irq_mask(struct irq_data *d)
{
struct spmi_pmic_arb_dev *pa = irq_data_get_irq_chip_data(d);
u8 irq = d->hwirq >> 8;
u8 apid = d->hwirq;
unsigned long flags;
u32 status;
u8 data;
raw_spin_lock_irqsave(&pa->lock, flags);
status = readl_relaxed(pa->intr + SPMI_PIC_ACC_ENABLE(apid));
if (status & SPMI_PIC_ACC_ENABLE_BIT) {
status = status & ~SPMI_PIC_ACC_ENABLE_BIT;
writel_relaxed(status, pa->intr + SPMI_PIC_ACC_ENABLE(apid));
}
raw_spin_unlock_irqrestore(&pa->lock, flags);
data = 1 << irq;
qpnpint_spmi_write(d, QPNPINT_REG_EN_CLR, &data, 1);
}
static void qpnpint_irq_unmask(struct irq_data *d)
{
struct spmi_pmic_arb_dev *pa = irq_data_get_irq_chip_data(d);
u8 irq = d->hwirq >> 8;
u8 apid = d->hwirq;
unsigned long flags;
u32 status;
u8 data;
raw_spin_lock_irqsave(&pa->lock, flags);
status = readl_relaxed(pa->intr + SPMI_PIC_ACC_ENABLE(apid));
if (!(status & SPMI_PIC_ACC_ENABLE_BIT)) {
writel_relaxed(status | SPMI_PIC_ACC_ENABLE_BIT,
pa->intr + SPMI_PIC_ACC_ENABLE(apid));
}
raw_spin_unlock_irqrestore(&pa->lock, flags);
data = 1 << irq;
qpnpint_spmi_write(d, QPNPINT_REG_EN_SET, &data, 1);
}
static void qpnpint_irq_enable(struct irq_data *d)
{
u8 irq = d->hwirq >> 8;
u8 data;
qpnpint_irq_unmask(d);
data = 1 << irq;
qpnpint_spmi_write(d, QPNPINT_REG_LATCHED_CLR, &data, 1);
}
static int qpnpint_irq_set_type(struct irq_data *d, unsigned int flow_type)
{
struct spmi_pmic_arb_qpnpint_type type;
u8 irq = d->hwirq >> 8;
qpnpint_spmi_read(d, QPNPINT_REG_SET_TYPE, &type, sizeof(type));
if (flow_type & (IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING)) {
type.type |= 1 << irq;
if (flow_type & IRQF_TRIGGER_RISING)
type.polarity_high |= 1 << irq;
if (flow_type & IRQF_TRIGGER_FALLING)
type.polarity_low |= 1 << irq;
} else {
if ((flow_type & (IRQF_TRIGGER_HIGH)) &&
(flow_type & (IRQF_TRIGGER_LOW)))
return -EINVAL;
type.type &= ~(1 << irq);
if (flow_type & IRQF_TRIGGER_HIGH)
type.polarity_high |= 1 << irq;
else
type.polarity_low |= 1 << irq;
}
qpnpint_spmi_write(d, QPNPINT_REG_SET_TYPE, &type, sizeof(type));
return 0;
}
static int search_mapping_table(struct spmi_pmic_arb_dev *pa,
struct spmi_pmic_arb_irq_spec *spec,
u8 *apid)
{
u16 ppid = spec->slave << 8 | spec->per;
u32 *mapping_table = pa->mapping_table;
int index = 0, i;
u32 data;
for (i = 0; i < SPMI_MAPPING_TABLE_TREE_DEPTH; ++i) {
data = mapping_table[index];
if (ppid & (1 << SPMI_MAPPING_BIT_INDEX(data))) {
if (SPMI_MAPPING_BIT_IS_1_FLAG(data)) {
index = SPMI_MAPPING_BIT_IS_1_RESULT(data);
} else {
*apid = SPMI_MAPPING_BIT_IS_1_RESULT(data);
return 0;
}
} else {
if (SPMI_MAPPING_BIT_IS_0_FLAG(data)) {
index = SPMI_MAPPING_BIT_IS_0_RESULT(data);
} else {
*apid = SPMI_MAPPING_BIT_IS_0_RESULT(data);
return 0;
}
}
}
return -ENODEV;
}
static int qpnpint_irq_domain_dt_translate(struct irq_domain *d,
struct device_node *controller,
const u32 *intspec,
unsigned int intsize,
unsigned long *out_hwirq,
unsigned int *out_type)
{
struct spmi_pmic_arb_dev *pa = d->host_data;
struct spmi_pmic_arb_irq_spec spec;
int err;
u8 apid;
dev_dbg(&pa->spmic->dev,
"intspec[0] 0x%1x intspec[1] 0x%02x intspec[2] 0x%02x\n",
intspec[0], intspec[1], intspec[2]);
if (d->of_node != controller)
return -EINVAL;
if (intsize != 4)
return -EINVAL;
if (intspec[0] > 0xF || intspec[1] > 0xFF || intspec[2] > 0x7)
return -EINVAL;
spec.slave = intspec[0];
spec.per = intspec[1];
spec.irq = intspec[2];
err = search_mapping_table(pa, &spec, &apid);
if (err)
return err;
pa->apid_to_ppid[apid] = spec.slave << 8 | spec.per;
if (apid > pa->max_apid)
pa->max_apid = apid;
if (apid < pa->min_apid)
pa->min_apid = apid;
*out_hwirq = spec.slave << 24
| spec.per << 16
| spec.irq << 8
| apid;
*out_type = intspec[3] & IRQ_TYPE_SENSE_MASK;
dev_dbg(&pa->spmic->dev, "out_hwirq = %lu\n", *out_hwirq);
return 0;
}
static int qpnpint_irq_domain_map(struct irq_domain *d,
unsigned int virq,
irq_hw_number_t hwirq)
{
struct spmi_pmic_arb_dev *pa = d->host_data;
dev_dbg(&pa->spmic->dev, "virq = %u, hwirq = %lu\n", virq, hwirq);
irq_set_chip_and_handler(virq, &pmic_arb_irqchip, handle_level_irq);
irq_set_chip_data(virq, d->host_data);
irq_set_noprobe(virq);
return 0;
}
static int spmi_pmic_arb_probe(struct platform_device *pdev)
{
struct spmi_pmic_arb_dev *pa;
struct spmi_controller *ctrl;
struct resource *res;
u32 channel, ee;
int err, i;
ctrl = spmi_controller_alloc(&pdev->dev, sizeof(*pa));
if (!ctrl)
return -ENOMEM;
pa = spmi_controller_get_drvdata(ctrl);
pa->spmic = ctrl;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "core");
pa->base = devm_ioremap_resource(&ctrl->dev, res);
if (IS_ERR(pa->base)) {
err = PTR_ERR(pa->base);
goto err_put_ctrl;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "intr");
pa->intr = devm_ioremap_resource(&ctrl->dev, res);
if (IS_ERR(pa->intr)) {
err = PTR_ERR(pa->intr);
goto err_put_ctrl;
}
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "cnfg");
pa->cnfg = devm_ioremap_resource(&ctrl->dev, res);
if (IS_ERR(pa->cnfg)) {
err = PTR_ERR(pa->cnfg);
goto err_put_ctrl;
}
pa->irq = platform_get_irq_byname(pdev, "periph_irq");
if (pa->irq < 0) {
err = pa->irq;
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
goto err_put_ctrl;
}
pa->channel = channel;
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
pa->ee = ee;
for (i = 0; i < ARRAY_SIZE(pa->mapping_table); ++i)
pa->mapping_table[i] = readl_relaxed(
pa->cnfg + SPMI_MAPPING_TABLE_REG(i));
pa->max_apid = 0;
pa->min_apid = PMIC_ARB_MAX_PERIPHS - 1;
platform_set_drvdata(pdev, ctrl);
raw_spin_lock_init(&pa->lock);
ctrl->cmd = pmic_arb_cmd;
ctrl->read_cmd = pmic_arb_read_cmd;
ctrl->write_cmd = pmic_arb_write_cmd;
dev_dbg(&pdev->dev, "adding irq domain\n");
pa->domain = irq_domain_add_tree(pdev->dev.of_node,
&pmic_arb_irq_domain_ops, pa);
if (!pa->domain) {
dev_err(&pdev->dev, "unable to create irq_domain\n");
err = -ENOMEM;
goto err_put_ctrl;
}
irq_set_handler_data(pa->irq, pa);
irq_set_chained_handler(pa->irq, pmic_arb_chained_irq);
err = spmi_controller_add(ctrl);
if (err)
goto err_domain_remove;
dev_dbg(&ctrl->dev, "PMIC Arb Version 0x%x\n",
pmic_arb_base_read(pa, PMIC_ARB_VERSION));
return 0;
err_domain_remove:
irq_set_chained_handler(pa->irq, NULL);
irq_set_handler_data(pa->irq, NULL);
irq_domain_remove(pa->domain);
err_put_ctrl:
spmi_controller_put(ctrl);
return err;
}
static int spmi_pmic_arb_remove(struct platform_device *pdev)
{
struct spmi_controller *ctrl = platform_get_drvdata(pdev);
struct spmi_pmic_arb_dev *pa = spmi_controller_get_drvdata(ctrl);
spmi_controller_remove(ctrl);
irq_set_chained_handler(pa->irq, NULL);
irq_set_handler_data(pa->irq, NULL);
irq_domain_remove(pa->domain);
spmi_controller_put(ctrl);
return 0;
}
