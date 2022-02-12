static inline void crossbar_writel(int irq_no, int cb_no)
{
writel(cb_no, cb->crossbar_base + cb->register_offsets[irq_no]);
}
static inline void crossbar_writew(int irq_no, int cb_no)
{
writew(cb_no, cb->crossbar_base + cb->register_offsets[irq_no]);
}
static inline void crossbar_writeb(int irq_no, int cb_no)
{
writeb(cb_no, cb->crossbar_base + cb->register_offsets[irq_no]);
}
static inline int get_prev_map_irq(int cb_no)
{
int i;
for (i = cb->int_max - 1; i >= 0; i--)
if (cb->irq_map[i] == cb_no)
return i;
return -ENODEV;
}
static inline int allocate_free_irq(int cb_no)
{
int i;
for (i = cb->int_max - 1; i >= 0; i--) {
if (cb->irq_map[i] == IRQ_FREE) {
cb->irq_map[i] = cb_no;
return i;
}
}
return -ENODEV;
}
static inline bool needs_crossbar_write(irq_hw_number_t hw)
{
int cb_no;
if (hw > GIC_IRQ_START) {
cb_no = cb->irq_map[hw - GIC_IRQ_START];
if (cb_no != IRQ_RESERVED && cb_no != IRQ_SKIP)
return true;
}
return false;
}
static int crossbar_domain_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hw)
{
if (needs_crossbar_write(hw))
cb->write(hw - GIC_IRQ_START, cb->irq_map[hw - GIC_IRQ_START]);
return 0;
}
static void crossbar_domain_unmap(struct irq_domain *d, unsigned int irq)
{
irq_hw_number_t hw = irq_get_irq_data(irq)->hwirq;
if (needs_crossbar_write(hw)) {
cb->irq_map[hw - GIC_IRQ_START] = IRQ_FREE;
cb->write(hw - GIC_IRQ_START, cb->safe_map);
}
}
static int crossbar_domain_xlate(struct irq_domain *d,
struct device_node *controller,
const u32 *intspec, unsigned int intsize,
unsigned long *out_hwirq,
unsigned int *out_type)
{
int ret;
int req_num = intspec[1];
int direct_map_num;
if (req_num >= cb->max_crossbar_sources) {
direct_map_num = req_num - cb->max_crossbar_sources;
if (direct_map_num < cb->int_max) {
ret = cb->irq_map[direct_map_num];
if (ret == IRQ_RESERVED || ret == IRQ_SKIP) {
ret = direct_map_num;
goto found;
}
}
pr_err("%s: requested crossbar number %d > max %d\n",
__func__, req_num, cb->max_crossbar_sources);
return -EINVAL;
}
ret = get_prev_map_irq(req_num);
if (ret >= 0)
goto found;
ret = allocate_free_irq(req_num);
if (ret < 0)
return ret;
found:
*out_hwirq = ret + GIC_IRQ_START;
return 0;
}
static int __init crossbar_of_init(struct device_node *node)
{
int i, size, max = 0, reserved = 0, entry;
const __be32 *irqsr;
int ret = -ENOMEM;
cb = kzalloc(sizeof(*cb), GFP_KERNEL);
if (!cb)
return ret;
cb->crossbar_base = of_iomap(node, 0);
if (!cb->crossbar_base)
goto err_cb;
of_property_read_u32(node, "ti,max-crossbar-sources",
&cb->max_crossbar_sources);
if (!cb->max_crossbar_sources) {
pr_err("missing 'ti,max-crossbar-sources' property\n");
ret = -EINVAL;
goto err_base;
}
of_property_read_u32(node, "ti,max-irqs", &max);
if (!max) {
pr_err("missing 'ti,max-irqs' property\n");
ret = -EINVAL;
goto err_base;
}
cb->irq_map = kcalloc(max, sizeof(int), GFP_KERNEL);
if (!cb->irq_map)
goto err_base;
cb->int_max = max;
for (i = 0; i < max; i++)
cb->irq_map[i] = IRQ_FREE;
irqsr = of_get_property(node, "ti,irqs-reserved", &size);
if (irqsr) {
size /= sizeof(__be32);
for (i = 0; i < size; i++) {
of_property_read_u32_index(node,
"ti,irqs-reserved",
i, &entry);
if (entry >= max) {
pr_err("Invalid reserved entry\n");
ret = -EINVAL;
goto err_irq_map;
}
cb->irq_map[entry] = IRQ_RESERVED;
}
}
irqsr = of_get_property(node, "ti,irqs-skip", &size);
if (irqsr) {
size /= sizeof(__be32);
for (i = 0; i < size; i++) {
of_property_read_u32_index(node,
"ti,irqs-skip",
i, &entry);
if (entry >= max) {
pr_err("Invalid skip entry\n");
ret = -EINVAL;
goto err_irq_map;
}
cb->irq_map[entry] = IRQ_SKIP;
}
}
cb->register_offsets = kcalloc(max, sizeof(int), GFP_KERNEL);
if (!cb->register_offsets)
goto err_irq_map;
of_property_read_u32(node, "ti,reg-size", &size);
switch (size) {
case 1:
cb->write = crossbar_writeb;
break;
case 2:
cb->write = crossbar_writew;
break;
case 4:
cb->write = crossbar_writel;
break;
default:
pr_err("Invalid reg-size property\n");
ret = -EINVAL;
goto err_reg_offset;
break;
}
for (i = 0; i < max; i++) {
if (cb->irq_map[i] == IRQ_RESERVED)
continue;
cb->register_offsets[i] = reserved;
reserved += size;
}
of_property_read_u32(node, "ti,irqs-safe-map", &cb->safe_map);
for (i = 0; i < max; i++) {
if (cb->irq_map[i] == IRQ_RESERVED ||
cb->irq_map[i] == IRQ_SKIP)
continue;
cb->write(i, cb->safe_map);
}
register_routable_domain_ops(&routable_irq_domain_ops);
return 0;
err_reg_offset:
kfree(cb->register_offsets);
err_irq_map:
kfree(cb->irq_map);
err_base:
iounmap(cb->crossbar_base);
err_cb:
kfree(cb);
cb = NULL;
return ret;
}
int __init irqcrossbar_init(void)
{
struct device_node *np;
np = of_find_matching_node(NULL, crossbar_match);
if (!np)
return -ENODEV;
crossbar_of_init(np);
return 0;
}
