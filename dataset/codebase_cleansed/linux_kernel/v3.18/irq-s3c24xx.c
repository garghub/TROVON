static void s3c_irq_mask(struct irq_data *data)
{
struct s3c_irq_data *irq_data = irq_data_get_irq_chip_data(data);
struct s3c_irq_intc *intc = irq_data->intc;
struct s3c_irq_intc *parent_intc = intc->parent;
struct s3c_irq_data *parent_data;
unsigned long mask;
unsigned int irqno;
mask = __raw_readl(intc->reg_mask);
mask |= (1UL << irq_data->offset);
__raw_writel(mask, intc->reg_mask);
if (parent_intc) {
parent_data = &parent_intc->irqs[irq_data->parent_irq];
if ((mask & parent_data->sub_bits) == parent_data->sub_bits) {
irqno = irq_find_mapping(parent_intc->domain,
irq_data->parent_irq);
s3c_irq_mask(irq_get_irq_data(irqno));
}
}
}
static void s3c_irq_unmask(struct irq_data *data)
{
struct s3c_irq_data *irq_data = irq_data_get_irq_chip_data(data);
struct s3c_irq_intc *intc = irq_data->intc;
struct s3c_irq_intc *parent_intc = intc->parent;
unsigned long mask;
unsigned int irqno;
mask = __raw_readl(intc->reg_mask);
mask &= ~(1UL << irq_data->offset);
__raw_writel(mask, intc->reg_mask);
if (parent_intc) {
irqno = irq_find_mapping(parent_intc->domain,
irq_data->parent_irq);
s3c_irq_unmask(irq_get_irq_data(irqno));
}
}
static inline void s3c_irq_ack(struct irq_data *data)
{
struct s3c_irq_data *irq_data = irq_data_get_irq_chip_data(data);
struct s3c_irq_intc *intc = irq_data->intc;
unsigned long bitval = 1UL << irq_data->offset;
__raw_writel(bitval, intc->reg_pending);
if (intc->reg_intpnd)
__raw_writel(bitval, intc->reg_intpnd);
}
static int s3c_irq_type(struct irq_data *data, unsigned int type)
{
switch (type) {
case IRQ_TYPE_NONE:
break;
case IRQ_TYPE_EDGE_RISING:
case IRQ_TYPE_EDGE_FALLING:
case IRQ_TYPE_EDGE_BOTH:
irq_set_handler(data->irq, handle_edge_irq);
break;
case IRQ_TYPE_LEVEL_LOW:
case IRQ_TYPE_LEVEL_HIGH:
irq_set_handler(data->irq, handle_level_irq);
break;
default:
pr_err("No such irq type %d", type);
return -EINVAL;
}
return 0;
}
static int s3c_irqext_type_set(void __iomem *gpcon_reg,
void __iomem *extint_reg,
unsigned long gpcon_offset,
unsigned long extint_offset,
unsigned int type)
{
unsigned long newvalue = 0, value;
value = __raw_readl(gpcon_reg);
value = (value & ~(3 << gpcon_offset)) | (0x02 << gpcon_offset);
__raw_writel(value, gpcon_reg);
switch (type)
{
case IRQ_TYPE_NONE:
pr_warn("No edge setting!\n");
break;
case IRQ_TYPE_EDGE_RISING:
newvalue = S3C2410_EXTINT_RISEEDGE;
break;
case IRQ_TYPE_EDGE_FALLING:
newvalue = S3C2410_EXTINT_FALLEDGE;
break;
case IRQ_TYPE_EDGE_BOTH:
newvalue = S3C2410_EXTINT_BOTHEDGE;
break;
case IRQ_TYPE_LEVEL_LOW:
newvalue = S3C2410_EXTINT_LOWLEV;
break;
case IRQ_TYPE_LEVEL_HIGH:
newvalue = S3C2410_EXTINT_HILEV;
break;
default:
pr_err("No such irq type %d", type);
return -EINVAL;
}
value = __raw_readl(extint_reg);
value = (value & ~(7 << extint_offset)) | (newvalue << extint_offset);
__raw_writel(value, extint_reg);
return 0;
}
static int s3c_irqext_type(struct irq_data *data, unsigned int type)
{
void __iomem *extint_reg;
void __iomem *gpcon_reg;
unsigned long gpcon_offset, extint_offset;
if ((data->hwirq >= 4) && (data->hwirq <= 7)) {
gpcon_reg = S3C2410_GPFCON;
extint_reg = S3C24XX_EXTINT0;
gpcon_offset = (data->hwirq) * 2;
extint_offset = (data->hwirq) * 4;
} else if ((data->hwirq >= 8) && (data->hwirq <= 15)) {
gpcon_reg = S3C2410_GPGCON;
extint_reg = S3C24XX_EXTINT1;
gpcon_offset = (data->hwirq - 8) * 2;
extint_offset = (data->hwirq - 8) * 4;
} else if ((data->hwirq >= 16) && (data->hwirq <= 23)) {
gpcon_reg = S3C2410_GPGCON;
extint_reg = S3C24XX_EXTINT2;
gpcon_offset = (data->hwirq - 8) * 2;
extint_offset = (data->hwirq - 16) * 4;
} else {
return -EINVAL;
}
return s3c_irqext_type_set(gpcon_reg, extint_reg, gpcon_offset,
extint_offset, type);
}
static int s3c_irqext0_type(struct irq_data *data, unsigned int type)
{
void __iomem *extint_reg;
void __iomem *gpcon_reg;
unsigned long gpcon_offset, extint_offset;
if ((data->hwirq >= 0) && (data->hwirq <= 3)) {
gpcon_reg = S3C2410_GPFCON;
extint_reg = S3C24XX_EXTINT0;
gpcon_offset = (data->hwirq) * 2;
extint_offset = (data->hwirq) * 4;
} else {
return -EINVAL;
}
return s3c_irqext_type_set(gpcon_reg, extint_reg, gpcon_offset,
extint_offset, type);
}
static void s3c_irq_demux(unsigned int irq, struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
struct s3c_irq_data *irq_data = irq_desc_get_chip_data(desc);
struct s3c_irq_intc *intc = irq_data->intc;
struct s3c_irq_intc *sub_intc = irq_data->sub_intc;
unsigned long src;
unsigned long msk;
unsigned int n;
unsigned int offset;
offset = (intc->domain->of_node) ? 32 : 0;
chained_irq_enter(chip, desc);
src = __raw_readl(sub_intc->reg_pending);
msk = __raw_readl(sub_intc->reg_mask);
src &= ~msk;
src &= irq_data->sub_bits;
while (src) {
n = __ffs(src);
src &= ~(1 << n);
irq = irq_find_mapping(sub_intc->domain, offset + n);
generic_handle_irq(irq);
}
chained_irq_exit(chip, desc);
}
static inline int s3c24xx_handle_intc(struct s3c_irq_intc *intc,
struct pt_regs *regs, int intc_offset)
{
int pnd;
int offset;
pnd = __raw_readl(intc->reg_intpnd);
if (!pnd)
return false;
if (!intc->domain->of_node)
intc_offset = 0;
offset = __raw_readl(intc->reg_intpnd + 4);
if (!(pnd & (1 << offset)))
offset = __ffs(pnd);
handle_domain_irq(intc->domain, intc_offset + offset, regs);
return true;
}
asmlinkage void __exception_irq_entry s3c24xx_handle_irq(struct pt_regs *regs)
{
do {
if (likely(s3c_intc[0]))
if (s3c24xx_handle_intc(s3c_intc[0], regs, 0))
continue;
if (s3c_intc[2])
if (s3c24xx_handle_intc(s3c_intc[2], regs, 64))
continue;
break;
} while (1);
}
int s3c24xx_set_fiq(unsigned int irq, bool on)
{
u32 intmod;
unsigned offs;
if (on) {
offs = irq - FIQ_START;
if (offs > 31)
return -EINVAL;
intmod = 1 << offs;
} else {
intmod = 0;
}
__raw_writel(intmod, S3C2410_INTMOD);
return 0;
}
static int s3c24xx_irq_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
struct s3c_irq_intc *intc = h->host_data;
struct s3c_irq_data *irq_data = &intc->irqs[hw];
struct s3c_irq_intc *parent_intc;
struct s3c_irq_data *parent_irq_data;
unsigned int irqno;
irq_data->intc = intc;
irq_data->offset = hw;
parent_intc = intc->parent;
switch (irq_data->type) {
case S3C_IRQTYPE_NONE:
return 0;
case S3C_IRQTYPE_EINT:
if (parent_intc && (!soc_is_s3c2412() || hw >= 4))
irq_set_chip_and_handler(virq, &s3c_irqext_chip,
handle_edge_irq);
else
irq_set_chip_and_handler(virq, &s3c_irq_eint0t4,
handle_edge_irq);
break;
case S3C_IRQTYPE_EDGE:
if (parent_intc || intc->reg_pending == S3C2416_SRCPND2)
irq_set_chip_and_handler(virq, &s3c_irq_level_chip,
handle_edge_irq);
else
irq_set_chip_and_handler(virq, &s3c_irq_chip,
handle_edge_irq);
break;
case S3C_IRQTYPE_LEVEL:
if (parent_intc)
irq_set_chip_and_handler(virq, &s3c_irq_level_chip,
handle_level_irq);
else
irq_set_chip_and_handler(virq, &s3c_irq_chip,
handle_level_irq);
break;
default:
pr_err("irq-s3c24xx: unsupported irqtype %d\n", irq_data->type);
return -EINVAL;
}
irq_set_chip_data(virq, irq_data);
set_irq_flags(virq, IRQF_VALID);
if (parent_intc && irq_data->type != S3C_IRQTYPE_NONE) {
if (irq_data->parent_irq > 31) {
pr_err("irq-s3c24xx: parent irq %lu is out of range\n",
irq_data->parent_irq);
goto err;
}
parent_irq_data = &parent_intc->irqs[irq_data->parent_irq];
parent_irq_data->sub_intc = intc;
parent_irq_data->sub_bits |= (1UL << hw);
irqno = irq_find_mapping(parent_intc->domain,
irq_data->parent_irq);
if (!irqno) {
pr_err("irq-s3c24xx: could not find mapping for parent irq %lu\n",
irq_data->parent_irq);
goto err;
}
irq_set_chained_handler(irqno, s3c_irq_demux);
}
return 0;
err:
set_irq_flags(virq, 0);
return -EINVAL;
}
static void s3c24xx_clear_intc(struct s3c_irq_intc *intc)
{
void __iomem *reg_source;
unsigned long pend;
unsigned long last;
int i;
reg_source = intc->reg_intpnd ? intc->reg_intpnd : intc->reg_pending;
last = 0;
for (i = 0; i < 4; i++) {
pend = __raw_readl(reg_source);
if (pend == 0 || pend == last)
break;
__raw_writel(pend, intc->reg_pending);
if (intc->reg_intpnd)
__raw_writel(pend, intc->reg_intpnd);
pr_info("irq: clearing pending status %08x\n", (int)pend);
last = pend;
}
}
static struct s3c_irq_intc * __init s3c24xx_init_intc(struct device_node *np,
struct s3c_irq_data *irq_data,
struct s3c_irq_intc *parent,
unsigned long address)
{
struct s3c_irq_intc *intc;
void __iomem *base = (void *)0xf6000000;
int irq_num;
int irq_start;
int ret;
intc = kzalloc(sizeof(struct s3c_irq_intc), GFP_KERNEL);
if (!intc)
return ERR_PTR(-ENOMEM);
intc->irqs = irq_data;
if (parent)
intc->parent = parent;
switch (address) {
case 0x4a000000:
pr_debug("irq: found main intc\n");
intc->reg_pending = base;
intc->reg_mask = base + 0x08;
intc->reg_intpnd = base + 0x10;
irq_num = 32;
irq_start = S3C2410_IRQ(0);
break;
case 0x4a000018:
pr_debug("irq: found subintc\n");
intc->reg_pending = base + 0x18;
intc->reg_mask = base + 0x1c;
irq_num = 29;
irq_start = S3C2410_IRQSUB(0);
break;
case 0x4a000040:
pr_debug("irq: found intc2\n");
intc->reg_pending = base + 0x40;
intc->reg_mask = base + 0x48;
intc->reg_intpnd = base + 0x50;
irq_num = 8;
irq_start = S3C2416_IRQ(0);
break;
case 0x560000a4:
pr_debug("irq: found eintc\n");
base = (void *)0xfd000000;
intc->reg_mask = base + 0xa4;
intc->reg_pending = base + 0xa8;
irq_num = 24;
irq_start = S3C2410_IRQ(32);
break;
default:
pr_err("irq: unsupported controller address\n");
ret = -EINVAL;
goto err;
}
s3c24xx_clear_intc(intc);
intc->domain = irq_domain_add_legacy(np, irq_num, irq_start,
0, &s3c24xx_irq_ops,
intc);
if (!intc->domain) {
pr_err("irq: could not create irq-domain\n");
ret = -EINVAL;
goto err;
}
set_handle_irq(s3c24xx_handle_irq);
return intc;
err:
kfree(intc);
return ERR_PTR(ret);
}
void __init s3c2410_init_irq(void)
{
#ifdef CONFIG_FIQ
init_FIQ(FIQ_START);
#endif
s3c_intc[0] = s3c24xx_init_intc(NULL, &init_s3c2410base[0], NULL,
0x4a000000);
if (IS_ERR(s3c_intc[0])) {
pr_err("irq: could not create main interrupt controller\n");
return;
}
s3c_intc[1] = s3c24xx_init_intc(NULL, &init_s3c2410subint[0],
s3c_intc[0], 0x4a000018);
s3c24xx_init_intc(NULL, &init_eint[0], s3c_intc[0], 0x560000a4);
}
void __init s3c2412_init_irq(void)
{
pr_info("S3C2412: IRQ Support\n");
#ifdef CONFIG_FIQ
init_FIQ(FIQ_START);
#endif
s3c_intc[0] = s3c24xx_init_intc(NULL, &init_s3c2412base[0], NULL,
0x4a000000);
if (IS_ERR(s3c_intc[0])) {
pr_err("irq: could not create main interrupt controller\n");
return;
}
s3c24xx_init_intc(NULL, &init_s3c2412eint[0], s3c_intc[0], 0x560000a4);
s3c_intc[1] = s3c24xx_init_intc(NULL, &init_s3c2412subint[0],
s3c_intc[0], 0x4a000018);
}
void __init s3c2416_init_irq(void)
{
pr_info("S3C2416: IRQ Support\n");
#ifdef CONFIG_FIQ
init_FIQ(FIQ_START);
#endif
s3c_intc[0] = s3c24xx_init_intc(NULL, &init_s3c2416base[0], NULL,
0x4a000000);
if (IS_ERR(s3c_intc[0])) {
pr_err("irq: could not create main interrupt controller\n");
return;
}
s3c24xx_init_intc(NULL, &init_eint[0], s3c_intc[0], 0x560000a4);
s3c_intc[1] = s3c24xx_init_intc(NULL, &init_s3c2416subint[0],
s3c_intc[0], 0x4a000018);
s3c_intc[2] = s3c24xx_init_intc(NULL, &init_s3c2416_second[0],
NULL, 0x4a000040);
}
void __init s3c2440_init_irq(void)
{
pr_info("S3C2440: IRQ Support\n");
#ifdef CONFIG_FIQ
init_FIQ(FIQ_START);
#endif
s3c_intc[0] = s3c24xx_init_intc(NULL, &init_s3c2440base[0], NULL,
0x4a000000);
if (IS_ERR(s3c_intc[0])) {
pr_err("irq: could not create main interrupt controller\n");
return;
}
s3c24xx_init_intc(NULL, &init_eint[0], s3c_intc[0], 0x560000a4);
s3c_intc[1] = s3c24xx_init_intc(NULL, &init_s3c2440subint[0],
s3c_intc[0], 0x4a000018);
}
void __init s3c2442_init_irq(void)
{
pr_info("S3C2442: IRQ Support\n");
#ifdef CONFIG_FIQ
init_FIQ(FIQ_START);
#endif
s3c_intc[0] = s3c24xx_init_intc(NULL, &init_s3c2442base[0], NULL,
0x4a000000);
if (IS_ERR(s3c_intc[0])) {
pr_err("irq: could not create main interrupt controller\n");
return;
}
s3c24xx_init_intc(NULL, &init_eint[0], s3c_intc[0], 0x560000a4);
s3c_intc[1] = s3c24xx_init_intc(NULL, &init_s3c2442subint[0],
s3c_intc[0], 0x4a000018);
}
void __init s3c2443_init_irq(void)
{
pr_info("S3C2443: IRQ Support\n");
#ifdef CONFIG_FIQ
init_FIQ(FIQ_START);
#endif
s3c_intc[0] = s3c24xx_init_intc(NULL, &init_s3c2443base[0], NULL,
0x4a000000);
if (IS_ERR(s3c_intc[0])) {
pr_err("irq: could not create main interrupt controller\n");
return;
}
s3c24xx_init_intc(NULL, &init_eint[0], s3c_intc[0], 0x560000a4);
s3c_intc[1] = s3c24xx_init_intc(NULL, &init_s3c2443subint[0],
s3c_intc[0], 0x4a000018);
}
static int s3c24xx_irq_map_of(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
unsigned int ctrl_num = hw / 32;
unsigned int intc_hw = hw % 32;
struct s3c_irq_intc *intc = s3c_intc[ctrl_num];
struct s3c_irq_intc *parent_intc = intc->parent;
struct s3c_irq_data *irq_data = &intc->irqs[intc_hw];
irq_data->intc = intc;
irq_data->offset = intc_hw;
if (!parent_intc)
irq_set_chip_and_handler(virq, &s3c_irq_chip, handle_edge_irq);
else
irq_set_chip_and_handler(virq, &s3c_irq_level_chip,
handle_edge_irq);
irq_set_chip_data(virq, irq_data);
set_irq_flags(virq, IRQF_VALID);
return 0;
}
static int s3c24xx_irq_xlate_of(struct irq_domain *d, struct device_node *n,
const u32 *intspec, unsigned int intsize,
irq_hw_number_t *out_hwirq, unsigned int *out_type)
{
struct s3c_irq_intc *intc;
struct s3c_irq_intc *parent_intc;
struct s3c_irq_data *irq_data;
struct s3c_irq_data *parent_irq_data;
int irqno;
if (WARN_ON(intsize < 4))
return -EINVAL;
if (intspec[0] > 2 || !s3c_intc[intspec[0]]) {
pr_err("controller number %d invalid\n", intspec[0]);
return -EINVAL;
}
intc = s3c_intc[intspec[0]];
*out_hwirq = intspec[0] * 32 + intspec[2];
*out_type = intspec[3] & IRQ_TYPE_SENSE_MASK;
parent_intc = intc->parent;
if (parent_intc) {
irq_data = &intc->irqs[intspec[2]];
irq_data->parent_irq = intspec[1];
parent_irq_data = &parent_intc->irqs[irq_data->parent_irq];
parent_irq_data->sub_intc = intc;
parent_irq_data->sub_bits |= (1UL << intspec[2]);
irqno = irq_create_mapping(parent_intc->domain, intspec[1]);
if (irqno < 0) {
pr_err("irq: could not map parent interrupt\n");
return irqno;
}
irq_set_chained_handler(irqno, s3c_irq_demux);
}
return 0;
}
static int __init s3c_init_intc_of(struct device_node *np,
struct device_node *interrupt_parent,
struct s3c24xx_irq_of_ctrl *s3c_ctrl, int num_ctrl)
{
struct s3c_irq_intc *intc;
struct s3c24xx_irq_of_ctrl *ctrl;
struct irq_domain *domain;
void __iomem *reg_base;
int i;
reg_base = of_iomap(np, 0);
if (!reg_base) {
pr_err("irq-s3c24xx: could not map irq registers\n");
return -EINVAL;
}
domain = irq_domain_add_linear(np, num_ctrl * 32,
&s3c24xx_irq_ops_of, NULL);
if (!domain) {
pr_err("irq: could not create irq-domain\n");
return -EINVAL;
}
for (i = 0; i < num_ctrl; i++) {
ctrl = &s3c_ctrl[i];
pr_debug("irq: found controller %s\n", ctrl->name);
intc = kzalloc(sizeof(struct s3c_irq_intc), GFP_KERNEL);
if (!intc)
return -ENOMEM;
intc->domain = domain;
intc->irqs = kzalloc(sizeof(struct s3c_irq_data) * 32,
GFP_KERNEL);
if (!intc->irqs) {
kfree(intc);
return -ENOMEM;
}
if (ctrl->parent) {
intc->reg_pending = reg_base + ctrl->offset;
intc->reg_mask = reg_base + ctrl->offset + 0x4;
if (*(ctrl->parent)) {
intc->parent = *(ctrl->parent);
} else {
pr_warn("irq: parent of %s missing\n",
ctrl->name);
kfree(intc->irqs);
kfree(intc);
continue;
}
} else {
intc->reg_pending = reg_base + ctrl->offset;
intc->reg_mask = reg_base + ctrl->offset + 0x08;
intc->reg_intpnd = reg_base + ctrl->offset + 0x10;
}
s3c24xx_clear_intc(intc);
s3c_intc[i] = intc;
}
set_handle_irq(s3c24xx_handle_irq);
return 0;
}
int __init s3c2410_init_intc_of(struct device_node *np,
struct device_node *interrupt_parent)
{
return s3c_init_intc_of(np, interrupt_parent,
s3c2410_ctrl, ARRAY_SIZE(s3c2410_ctrl));
}
int __init s3c2416_init_intc_of(struct device_node *np,
struct device_node *interrupt_parent)
{
return s3c_init_intc_of(np, interrupt_parent,
s3c2416_ctrl, ARRAY_SIZE(s3c2416_ctrl));
}
