static void grgpio_set_imask(struct grgpio_priv *priv, unsigned int offset,
int val)
{
struct gpio_chip *gc = &priv->gc;
unsigned long mask = gc->pin2mask(gc, offset);
if (val)
priv->imask |= mask;
else
priv->imask &= ~mask;
gc->write_reg(priv->regs + GRGPIO_IMASK, priv->imask);
}
static int grgpio_to_irq(struct gpio_chip *gc, unsigned offset)
{
struct grgpio_priv *priv = gpiochip_get_data(gc);
if (offset >= gc->ngpio)
return -ENXIO;
if (priv->lirqs[offset].index < 0)
return -ENXIO;
return irq_create_mapping(priv->domain, offset);
}
static int grgpio_irq_set_type(struct irq_data *d, unsigned int type)
{
struct grgpio_priv *priv = irq_data_get_irq_chip_data(d);
unsigned long flags;
u32 mask = BIT(d->hwirq);
u32 ipol;
u32 iedge;
u32 pol;
u32 edge;
switch (type) {
case IRQ_TYPE_LEVEL_LOW:
pol = 0;
edge = 0;
break;
case IRQ_TYPE_LEVEL_HIGH:
pol = mask;
edge = 0;
break;
case IRQ_TYPE_EDGE_FALLING:
pol = 0;
edge = mask;
break;
case IRQ_TYPE_EDGE_RISING:
pol = mask;
edge = mask;
break;
default:
return -EINVAL;
}
spin_lock_irqsave(&priv->gc.bgpio_lock, flags);
ipol = priv->gc.read_reg(priv->regs + GRGPIO_IPOL) & ~mask;
iedge = priv->gc.read_reg(priv->regs + GRGPIO_IEDGE) & ~mask;
priv->gc.write_reg(priv->regs + GRGPIO_IPOL, ipol | pol);
priv->gc.write_reg(priv->regs + GRGPIO_IEDGE, iedge | edge);
spin_unlock_irqrestore(&priv->gc.bgpio_lock, flags);
return 0;
}
static void grgpio_irq_mask(struct irq_data *d)
{
struct grgpio_priv *priv = irq_data_get_irq_chip_data(d);
int offset = d->hwirq;
unsigned long flags;
spin_lock_irqsave(&priv->gc.bgpio_lock, flags);
grgpio_set_imask(priv, offset, 0);
spin_unlock_irqrestore(&priv->gc.bgpio_lock, flags);
}
static void grgpio_irq_unmask(struct irq_data *d)
{
struct grgpio_priv *priv = irq_data_get_irq_chip_data(d);
int offset = d->hwirq;
unsigned long flags;
spin_lock_irqsave(&priv->gc.bgpio_lock, flags);
grgpio_set_imask(priv, offset, 1);
spin_unlock_irqrestore(&priv->gc.bgpio_lock, flags);
}
static irqreturn_t grgpio_irq_handler(int irq, void *dev)
{
struct grgpio_priv *priv = dev;
int ngpio = priv->gc.ngpio;
unsigned long flags;
int i;
int match = 0;
spin_lock_irqsave(&priv->gc.bgpio_lock, flags);
for (i = 0; i < ngpio; i++) {
struct grgpio_lirq *lirq = &priv->lirqs[i];
if (priv->imask & BIT(i) && lirq->index >= 0 &&
priv->uirqs[lirq->index].uirq == irq) {
generic_handle_irq(lirq->irq);
match = 1;
}
}
spin_unlock_irqrestore(&priv->gc.bgpio_lock, flags);
if (!match)
dev_warn(priv->dev, "No gpio line matched irq %d\n", irq);
return IRQ_HANDLED;
}
static int grgpio_irq_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hwirq)
{
struct grgpio_priv *priv = d->host_data;
struct grgpio_lirq *lirq;
struct grgpio_uirq *uirq;
unsigned long flags;
int offset = hwirq;
int ret = 0;
if (!priv)
return -EINVAL;
lirq = &priv->lirqs[offset];
if (lirq->index < 0)
return -EINVAL;
dev_dbg(priv->dev, "Mapping irq %d for gpio line %d\n",
irq, offset);
spin_lock_irqsave(&priv->gc.bgpio_lock, flags);
lirq->irq = irq;
uirq = &priv->uirqs[lirq->index];
if (uirq->refcnt == 0) {
ret = request_irq(uirq->uirq, grgpio_irq_handler, 0,
dev_name(priv->dev), priv);
if (ret) {
dev_err(priv->dev,
"Could not request underlying irq %d\n",
uirq->uirq);
spin_unlock_irqrestore(&priv->gc.bgpio_lock, flags);
return ret;
}
}
uirq->refcnt++;
spin_unlock_irqrestore(&priv->gc.bgpio_lock, flags);
irq_set_chip_data(irq, priv);
irq_set_chip_and_handler(irq, &grgpio_irq_chip,
handle_simple_irq);
irq_set_noprobe(irq);
return ret;
}
static void grgpio_irq_unmap(struct irq_domain *d, unsigned int irq)
{
struct grgpio_priv *priv = d->host_data;
int index;
struct grgpio_lirq *lirq;
struct grgpio_uirq *uirq;
unsigned long flags;
int ngpio = priv->gc.ngpio;
int i;
irq_set_chip_and_handler(irq, NULL, NULL);
irq_set_chip_data(irq, NULL);
spin_lock_irqsave(&priv->gc.bgpio_lock, flags);
index = -1;
for (i = 0; i < ngpio; i++) {
lirq = &priv->lirqs[i];
if (lirq->irq == irq) {
grgpio_set_imask(priv, i, 0);
lirq->irq = 0;
index = lirq->index;
break;
}
}
WARN_ON(index < 0);
if (index >= 0) {
uirq = &priv->uirqs[lirq->index];
uirq->refcnt--;
if (uirq->refcnt == 0)
free_irq(uirq->uirq, priv);
}
spin_unlock_irqrestore(&priv->gc.bgpio_lock, flags);
}
static int grgpio_probe(struct platform_device *ofdev)
{
struct device_node *np = ofdev->dev.of_node;
void __iomem *regs;
struct gpio_chip *gc;
struct grgpio_priv *priv;
struct resource *res;
int err;
u32 prop;
s32 *irqmap;
int size;
int i;
priv = devm_kzalloc(&ofdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
res = platform_get_resource(ofdev, IORESOURCE_MEM, 0);
regs = devm_ioremap_resource(&ofdev->dev, res);
if (IS_ERR(regs))
return PTR_ERR(regs);
gc = &priv->gc;
err = bgpio_init(gc, &ofdev->dev, 4, regs + GRGPIO_DATA,
regs + GRGPIO_OUTPUT, NULL, regs + GRGPIO_DIR, NULL,
BGPIOF_BIG_ENDIAN_BYTE_ORDER);
if (err) {
dev_err(&ofdev->dev, "bgpio_init() failed\n");
return err;
}
priv->regs = regs;
priv->imask = gc->read_reg(regs + GRGPIO_IMASK);
priv->dev = &ofdev->dev;
gc->of_node = np;
gc->owner = THIS_MODULE;
gc->to_irq = grgpio_to_irq;
gc->label = np->full_name;
gc->base = -1;
err = of_property_read_u32(np, "nbits", &prop);
if (err || prop <= 0 || prop > GRGPIO_MAX_NGPIO) {
gc->ngpio = GRGPIO_MAX_NGPIO;
dev_dbg(&ofdev->dev,
"No or invalid nbits property: assume %d\n", gc->ngpio);
} else {
gc->ngpio = prop;
}
irqmap = (s32 *)of_get_property(np, "irqmap", &size);
if (irqmap) {
if (size < gc->ngpio) {
dev_err(&ofdev->dev,
"irqmap shorter than ngpio (%d < %d)\n",
size, gc->ngpio);
return -EINVAL;
}
priv->domain = irq_domain_add_linear(np, gc->ngpio,
&grgpio_irq_domain_ops,
priv);
if (!priv->domain) {
dev_err(&ofdev->dev, "Could not add irq domain\n");
return -EINVAL;
}
for (i = 0; i < gc->ngpio; i++) {
struct grgpio_lirq *lirq;
int ret;
lirq = &priv->lirqs[i];
lirq->index = irqmap[i];
if (lirq->index < 0)
continue;
ret = platform_get_irq(ofdev, lirq->index);
if (ret <= 0) {
dev_err(priv->dev,
"Failed to get irq for offset %d\n", i);
continue;
}
priv->uirqs[lirq->index].uirq = ret;
}
}
platform_set_drvdata(ofdev, priv);
err = gpiochip_add_data(gc, priv);
if (err) {
dev_err(&ofdev->dev, "Could not add gpiochip\n");
if (priv->domain)
irq_domain_remove(priv->domain);
return err;
}
dev_info(&ofdev->dev, "regs=0x%p, base=%d, ngpio=%d, irqs=%s\n",
priv->regs, gc->base, gc->ngpio, priv->domain ? "on" : "off");
return 0;
}
static int grgpio_remove(struct platform_device *ofdev)
{
struct grgpio_priv *priv = platform_get_drvdata(ofdev);
unsigned long flags;
int i;
int ret = 0;
spin_lock_irqsave(&priv->gc.bgpio_lock, flags);
if (priv->domain) {
for (i = 0; i < GRGPIO_MAX_NGPIO; i++) {
if (priv->uirqs[i].refcnt != 0) {
ret = -EBUSY;
goto out;
}
}
}
gpiochip_remove(&priv->gc);
if (priv->domain)
irq_domain_remove(priv->domain);
out:
spin_unlock_irqrestore(&priv->gc.bgpio_lock, flags);
return ret;
}
