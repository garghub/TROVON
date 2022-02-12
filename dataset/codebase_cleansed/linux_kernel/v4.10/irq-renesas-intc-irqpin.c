static unsigned long intc_irqpin_read32(void __iomem *iomem)
{
return ioread32(iomem);
}
static unsigned long intc_irqpin_read8(void __iomem *iomem)
{
return ioread8(iomem);
}
static void intc_irqpin_write32(void __iomem *iomem, unsigned long data)
{
iowrite32(data, iomem);
}
static void intc_irqpin_write8(void __iomem *iomem, unsigned long data)
{
iowrite8(data, iomem);
}
static inline unsigned long intc_irqpin_read(struct intc_irqpin_priv *p,
int reg)
{
struct intc_irqpin_iomem *i = &p->iomem[reg];
return i->read(i->iomem);
}
static inline void intc_irqpin_write(struct intc_irqpin_priv *p,
int reg, unsigned long data)
{
struct intc_irqpin_iomem *i = &p->iomem[reg];
i->write(i->iomem, data);
}
static inline unsigned long intc_irqpin_hwirq_mask(struct intc_irqpin_priv *p,
int reg, int hw_irq)
{
return BIT((p->iomem[reg].width - 1) - hw_irq);
}
static inline void intc_irqpin_irq_write_hwirq(struct intc_irqpin_priv *p,
int reg, int hw_irq)
{
intc_irqpin_write(p, reg, intc_irqpin_hwirq_mask(p, reg, hw_irq));
}
static void intc_irqpin_read_modify_write(struct intc_irqpin_priv *p,
int reg, int shift,
int width, int value)
{
unsigned long flags;
unsigned long tmp;
raw_spin_lock_irqsave(&intc_irqpin_lock, flags);
tmp = intc_irqpin_read(p, reg);
tmp &= ~(((1 << width) - 1) << shift);
tmp |= value << shift;
intc_irqpin_write(p, reg, tmp);
raw_spin_unlock_irqrestore(&intc_irqpin_lock, flags);
}
static void intc_irqpin_mask_unmask_prio(struct intc_irqpin_priv *p,
int irq, int do_mask)
{
int bitfield_width = 4;
int shift = 32 - (irq + 1) * bitfield_width;
intc_irqpin_read_modify_write(p, INTC_IRQPIN_REG_PRIO,
shift, bitfield_width,
do_mask ? 0 : (1 << bitfield_width) - 1);
}
static int intc_irqpin_set_sense(struct intc_irqpin_priv *p, int irq, int value)
{
int bitfield_width = p->sense_bitfield_width;
int shift = 32 - (irq + 1) * bitfield_width;
dev_dbg(&p->pdev->dev, "sense irq = %d, mode = %d\n", irq, value);
if (value >= (1 << bitfield_width))
return -EINVAL;
intc_irqpin_read_modify_write(p, INTC_IRQPIN_REG_SENSE, shift,
bitfield_width, value);
return 0;
}
static void intc_irqpin_dbg(struct intc_irqpin_irq *i, char *str)
{
dev_dbg(&i->p->pdev->dev, "%s (%d:%d:%d)\n",
str, i->requested_irq, i->hw_irq, i->domain_irq);
}
static void intc_irqpin_irq_enable(struct irq_data *d)
{
struct intc_irqpin_priv *p = irq_data_get_irq_chip_data(d);
int hw_irq = irqd_to_hwirq(d);
intc_irqpin_dbg(&p->irq[hw_irq], "enable");
intc_irqpin_irq_write_hwirq(p, INTC_IRQPIN_REG_CLEAR, hw_irq);
}
static void intc_irqpin_irq_disable(struct irq_data *d)
{
struct intc_irqpin_priv *p = irq_data_get_irq_chip_data(d);
int hw_irq = irqd_to_hwirq(d);
intc_irqpin_dbg(&p->irq[hw_irq], "disable");
intc_irqpin_irq_write_hwirq(p, INTC_IRQPIN_REG_MASK, hw_irq);
}
static void intc_irqpin_shared_irq_enable(struct irq_data *d)
{
struct intc_irqpin_priv *p = irq_data_get_irq_chip_data(d);
int hw_irq = irqd_to_hwirq(d);
intc_irqpin_dbg(&p->irq[hw_irq], "shared enable");
intc_irqpin_irq_write_hwirq(p, INTC_IRQPIN_REG_CLEAR, hw_irq);
p->shared_irq_mask &= ~BIT(hw_irq);
}
static void intc_irqpin_shared_irq_disable(struct irq_data *d)
{
struct intc_irqpin_priv *p = irq_data_get_irq_chip_data(d);
int hw_irq = irqd_to_hwirq(d);
intc_irqpin_dbg(&p->irq[hw_irq], "shared disable");
intc_irqpin_irq_write_hwirq(p, INTC_IRQPIN_REG_MASK, hw_irq);
p->shared_irq_mask |= BIT(hw_irq);
}
static void intc_irqpin_irq_enable_force(struct irq_data *d)
{
struct intc_irqpin_priv *p = irq_data_get_irq_chip_data(d);
int irq = p->irq[irqd_to_hwirq(d)].requested_irq;
intc_irqpin_irq_enable(d);
irq_get_chip(irq)->irq_unmask(irq_get_irq_data(irq));
}
static void intc_irqpin_irq_disable_force(struct irq_data *d)
{
struct intc_irqpin_priv *p = irq_data_get_irq_chip_data(d);
int irq = p->irq[irqd_to_hwirq(d)].requested_irq;
irq_get_chip(irq)->irq_mask(irq_get_irq_data(irq));
intc_irqpin_irq_disable(d);
}
static int intc_irqpin_irq_set_type(struct irq_data *d, unsigned int type)
{
unsigned char value = intc_irqpin_sense[type & IRQ_TYPE_SENSE_MASK];
struct intc_irqpin_priv *p = irq_data_get_irq_chip_data(d);
if (!(value & INTC_IRQ_SENSE_VALID))
return -EINVAL;
return intc_irqpin_set_sense(p, irqd_to_hwirq(d),
value ^ INTC_IRQ_SENSE_VALID);
}
static int intc_irqpin_irq_set_wake(struct irq_data *d, unsigned int on)
{
struct intc_irqpin_priv *p = irq_data_get_irq_chip_data(d);
int hw_irq = irqd_to_hwirq(d);
irq_set_irq_wake(p->irq[hw_irq].requested_irq, on);
if (!p->clk)
return 0;
if (on)
clk_enable(p->clk);
else
clk_disable(p->clk);
return 0;
}
static irqreturn_t intc_irqpin_irq_handler(int irq, void *dev_id)
{
struct intc_irqpin_irq *i = dev_id;
struct intc_irqpin_priv *p = i->p;
unsigned long bit;
intc_irqpin_dbg(i, "demux1");
bit = intc_irqpin_hwirq_mask(p, INTC_IRQPIN_REG_SOURCE, i->hw_irq);
if (intc_irqpin_read(p, INTC_IRQPIN_REG_SOURCE) & bit) {
intc_irqpin_write(p, INTC_IRQPIN_REG_SOURCE, ~bit);
intc_irqpin_dbg(i, "demux2");
generic_handle_irq(i->domain_irq);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static irqreturn_t intc_irqpin_shared_irq_handler(int irq, void *dev_id)
{
struct intc_irqpin_priv *p = dev_id;
unsigned int reg_source = intc_irqpin_read(p, INTC_IRQPIN_REG_SOURCE);
irqreturn_t status = IRQ_NONE;
int k;
for (k = 0; k < 8; k++) {
if (reg_source & BIT(7 - k)) {
if (BIT(k) & p->shared_irq_mask)
continue;
status |= intc_irqpin_irq_handler(irq, &p->irq[k]);
}
}
return status;
}
static int intc_irqpin_irq_domain_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
struct intc_irqpin_priv *p = h->host_data;
p->irq[hw].domain_irq = virq;
p->irq[hw].hw_irq = hw;
intc_irqpin_dbg(&p->irq[hw], "map");
irq_set_chip_data(virq, h->host_data);
irq_set_lockdep_class(virq, &intc_irqpin_irq_lock_class);
irq_set_chip_and_handler(virq, &p->irq_chip, handle_level_irq);
return 0;
}
static int intc_irqpin_probe(struct platform_device *pdev)
{
const struct intc_irqpin_config *config = NULL;
struct device *dev = &pdev->dev;
const struct of_device_id *of_id;
struct intc_irqpin_priv *p;
struct intc_irqpin_iomem *i;
struct resource *io[INTC_IRQPIN_REG_NR];
struct resource *irq;
struct irq_chip *irq_chip;
void (*enable_fn)(struct irq_data *d);
void (*disable_fn)(struct irq_data *d);
const char *name = dev_name(dev);
bool control_parent;
unsigned int nirqs;
int ref_irq;
int ret;
int k;
p = devm_kzalloc(dev, sizeof(*p), GFP_KERNEL);
if (!p) {
dev_err(dev, "failed to allocate driver data\n");
return -ENOMEM;
}
of_property_read_u32(dev->of_node, "sense-bitfield-width",
&p->sense_bitfield_width);
control_parent = of_property_read_bool(dev->of_node, "control-parent");
if (!p->sense_bitfield_width)
p->sense_bitfield_width = 4;
p->pdev = pdev;
platform_set_drvdata(pdev, p);
of_id = of_match_device(intc_irqpin_dt_ids, dev);
if (of_id && of_id->data) {
config = of_id->data;
p->needs_clk = config->needs_clk;
}
p->clk = devm_clk_get(dev, NULL);
if (IS_ERR(p->clk)) {
if (p->needs_clk) {
dev_err(dev, "unable to get clock\n");
ret = PTR_ERR(p->clk);
goto err0;
}
p->clk = NULL;
}
pm_runtime_enable(dev);
pm_runtime_get_sync(dev);
memset(io, 0, sizeof(io));
for (k = 0; k < INTC_IRQPIN_REG_NR; k++) {
io[k] = platform_get_resource(pdev, IORESOURCE_MEM, k);
if (!io[k] && k < INTC_IRQPIN_REG_NR_MANDATORY) {
dev_err(dev, "not enough IOMEM resources\n");
ret = -EINVAL;
goto err0;
}
}
for (k = 0; k < INTC_IRQPIN_MAX; k++) {
irq = platform_get_resource(pdev, IORESOURCE_IRQ, k);
if (!irq)
break;
p->irq[k].p = p;
p->irq[k].requested_irq = irq->start;
}
nirqs = k;
if (nirqs < 1) {
dev_err(dev, "not enough IRQ resources\n");
ret = -EINVAL;
goto err0;
}
for (k = 0; k < INTC_IRQPIN_REG_NR; k++) {
i = &p->iomem[k];
if (!io[k])
continue;
switch (resource_size(io[k])) {
case 1:
i->width = 8;
i->read = intc_irqpin_read8;
i->write = intc_irqpin_write8;
break;
case 4:
i->width = 32;
i->read = intc_irqpin_read32;
i->write = intc_irqpin_write32;
break;
default:
dev_err(dev, "IOMEM size mismatch\n");
ret = -EINVAL;
goto err0;
}
i->iomem = devm_ioremap_nocache(dev, io[k]->start,
resource_size(io[k]));
if (!i->iomem) {
dev_err(dev, "failed to remap IOMEM\n");
ret = -ENXIO;
goto err0;
}
}
if (config && config->needs_irlm) {
if (io[INTC_IRQPIN_REG_IRLM])
intc_irqpin_read_modify_write(p, INTC_IRQPIN_REG_IRLM,
config->irlm_bit, 1, 1);
else
dev_warn(dev, "unable to select IRLM mode\n");
}
for (k = 0; k < nirqs; k++)
intc_irqpin_mask_unmask_prio(p, k, 1);
intc_irqpin_write(p, INTC_IRQPIN_REG_SOURCE, 0x0);
ref_irq = p->irq[0].requested_irq;
p->shared_irqs = 1;
for (k = 1; k < nirqs; k++) {
if (ref_irq != p->irq[k].requested_irq) {
p->shared_irqs = 0;
break;
}
}
if (control_parent) {
enable_fn = intc_irqpin_irq_enable_force;
disable_fn = intc_irqpin_irq_disable_force;
} else if (!p->shared_irqs) {
enable_fn = intc_irqpin_irq_enable;
disable_fn = intc_irqpin_irq_disable;
} else {
enable_fn = intc_irqpin_shared_irq_enable;
disable_fn = intc_irqpin_shared_irq_disable;
}
irq_chip = &p->irq_chip;
irq_chip->name = name;
irq_chip->irq_mask = disable_fn;
irq_chip->irq_unmask = enable_fn;
irq_chip->irq_set_type = intc_irqpin_irq_set_type;
irq_chip->irq_set_wake = intc_irqpin_irq_set_wake;
irq_chip->flags = IRQCHIP_MASK_ON_SUSPEND;
p->irq_domain = irq_domain_add_simple(dev->of_node, nirqs, 0,
&intc_irqpin_irq_domain_ops, p);
if (!p->irq_domain) {
ret = -ENXIO;
dev_err(dev, "cannot initialize irq domain\n");
goto err0;
}
if (p->shared_irqs) {
if (devm_request_irq(dev, p->irq[0].requested_irq,
intc_irqpin_shared_irq_handler,
IRQF_SHARED, name, p)) {
dev_err(dev, "failed to request low IRQ\n");
ret = -ENOENT;
goto err1;
}
} else {
for (k = 0; k < nirqs; k++) {
if (devm_request_irq(dev, p->irq[k].requested_irq,
intc_irqpin_irq_handler, 0, name,
&p->irq[k])) {
dev_err(dev, "failed to request low IRQ\n");
ret = -ENOENT;
goto err1;
}
}
}
for (k = 0; k < nirqs; k++)
intc_irqpin_mask_unmask_prio(p, k, 0);
dev_info(dev, "driving %d irqs\n", nirqs);
return 0;
err1:
irq_domain_remove(p->irq_domain);
err0:
pm_runtime_put(dev);
pm_runtime_disable(dev);
return ret;
}
static int intc_irqpin_remove(struct platform_device *pdev)
{
struct intc_irqpin_priv *p = platform_get_drvdata(pdev);
irq_domain_remove(p->irq_domain);
pm_runtime_put(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int __init intc_irqpin_init(void)
{
return platform_driver_register(&intc_irqpin_device_driver);
}
static void __exit intc_irqpin_exit(void)
{
platform_driver_unregister(&intc_irqpin_device_driver);
}
