static inline void _mpic_msgr_mer_write(struct mpic_msgr *msgr, u32 value)
{
out_be32(msgr->mer, value);
}
static inline u32 _mpic_msgr_mer_read(struct mpic_msgr *msgr)
{
return in_be32(msgr->mer);
}
static inline void _mpic_msgr_disable(struct mpic_msgr *msgr)
{
u32 mer = _mpic_msgr_mer_read(msgr);
_mpic_msgr_mer_write(msgr, mer & ~(1 << msgr->num));
}
struct mpic_msgr *mpic_msgr_get(unsigned int reg_num)
{
unsigned long flags;
struct mpic_msgr *msgr;
msgr = ERR_PTR(-EBUSY);
if (reg_num >= mpic_msgr_count)
return ERR_PTR(-ENODEV);
raw_spin_lock_irqsave(&msgrs_lock, flags);
msgr = mpic_msgrs[reg_num];
if (msgr->in_use == MSGR_FREE)
msgr->in_use = MSGR_INUSE;
raw_spin_unlock_irqrestore(&msgrs_lock, flags);
return msgr;
}
void mpic_msgr_put(struct mpic_msgr *msgr)
{
unsigned long flags;
raw_spin_lock_irqsave(&msgr->lock, flags);
msgr->in_use = MSGR_FREE;
_mpic_msgr_disable(msgr);
raw_spin_unlock_irqrestore(&msgr->lock, flags);
}
void mpic_msgr_enable(struct mpic_msgr *msgr)
{
unsigned long flags;
u32 mer;
raw_spin_lock_irqsave(&msgr->lock, flags);
mer = _mpic_msgr_mer_read(msgr);
_mpic_msgr_mer_write(msgr, mer | (1 << msgr->num));
raw_spin_unlock_irqrestore(&msgr->lock, flags);
}
void mpic_msgr_disable(struct mpic_msgr *msgr)
{
unsigned long flags;
raw_spin_lock_irqsave(&msgr->lock, flags);
_mpic_msgr_disable(msgr);
raw_spin_unlock_irqrestore(&msgr->lock, flags);
}
static unsigned int mpic_msgr_number_of_blocks(void)
{
unsigned int count;
struct device_node *aliases;
count = 0;
aliases = of_find_node_by_name(NULL, "aliases");
if (aliases) {
char buf[32];
for (;;) {
snprintf(buf, sizeof(buf), "mpic-msgr-block%d", count);
if (!of_find_property(aliases, buf, NULL))
break;
count += 1;
}
}
return count;
}
static unsigned int mpic_msgr_number_of_registers(void)
{
return mpic_msgr_number_of_blocks() * MPIC_MSGR_REGISTERS_PER_BLOCK;
}
static int mpic_msgr_block_number(struct device_node *node)
{
struct device_node *aliases;
unsigned int index, number_of_blocks;
char buf[64];
number_of_blocks = mpic_msgr_number_of_blocks();
aliases = of_find_node_by_name(NULL, "aliases");
if (!aliases)
return -1;
for (index = 0; index < number_of_blocks; ++index) {
struct property *prop;
snprintf(buf, sizeof(buf), "mpic-msgr-block%d", index);
prop = of_find_property(aliases, buf, NULL);
if (node == of_find_node_by_path(prop->value))
break;
}
return index == number_of_blocks ? -1 : index;
}
static int mpic_msgr_probe(struct platform_device *dev)
{
void __iomem *msgr_block_addr;
int block_number;
struct resource rsrc;
unsigned int i;
unsigned int irq_index;
struct device_node *np = dev->dev.of_node;
unsigned int receive_mask;
const unsigned int *prop;
if (!np) {
dev_err(&dev->dev, "Device OF-Node is NULL");
return -EFAULT;
}
if (!mpic_msgrs) {
mpic_msgr_count = mpic_msgr_number_of_registers();
dev_info(&dev->dev, "Found %d message registers\n",
mpic_msgr_count);
mpic_msgrs = kzalloc(sizeof(struct mpic_msgr) * mpic_msgr_count,
GFP_KERNEL);
if (!mpic_msgrs) {
dev_err(&dev->dev,
"No memory for message register blocks\n");
return -ENOMEM;
}
}
dev_info(&dev->dev, "Of-device full name %s\n", np->full_name);
of_address_to_resource(np, 0, &rsrc);
msgr_block_addr = ioremap(rsrc.start, rsrc.end - rsrc.start);
if (!msgr_block_addr) {
dev_err(&dev->dev, "Failed to iomap MPIC message registers");
return -EFAULT;
}
block_number = mpic_msgr_block_number(np);
if (block_number < 0) {
dev_err(&dev->dev,
"Failed to find message register block alias\n");
return -ENODEV;
}
dev_info(&dev->dev, "Setting up message register block %d\n",
block_number);
prop = of_get_property(np, "mpic-msgr-receive-mask", NULL);
receive_mask = (prop) ? *prop : 0xF;
for (i = 0, irq_index = 0; i < MPIC_MSGR_REGISTERS_PER_BLOCK; ++i) {
struct mpic_msgr *msgr;
unsigned int reg_number;
msgr = kzalloc(sizeof(struct mpic_msgr), GFP_KERNEL);
if (!msgr) {
dev_err(&dev->dev, "No memory for message register\n");
return -ENOMEM;
}
reg_number = block_number * MPIC_MSGR_REGISTERS_PER_BLOCK + i;
msgr->base = msgr_block_addr + i * MPIC_MSGR_STRIDE;
msgr->mer = (u32 *)((u8 *)msgr->base + MPIC_MSGR_MER_OFFSET);
msgr->in_use = MSGR_FREE;
msgr->num = i;
raw_spin_lock_init(&msgr->lock);
if (receive_mask & (1 << i)) {
struct resource irq;
if (of_irq_to_resource(np, irq_index, &irq) == NO_IRQ) {
dev_err(&dev->dev,
"Missing interrupt specifier");
kfree(msgr);
return -EFAULT;
}
msgr->irq = irq.start;
irq_index += 1;
} else {
msgr->irq = NO_IRQ;
}
mpic_msgrs[reg_number] = msgr;
mpic_msgr_disable(msgr);
dev_info(&dev->dev, "Register %d initialized: irq %d\n",
reg_number, msgr->irq);
}
return 0;
}
static __init int mpic_msgr_init(void)
{
return platform_driver_register(&mpic_msgr_driver);
}
