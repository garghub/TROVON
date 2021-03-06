static void
wildfire_update_irq_hw(unsigned int irq)
{
int qbbno = (irq >> 8) & (WILDFIRE_MAX_QBB - 1);
int pcano = (irq >> 6) & (WILDFIRE_PCA_PER_QBB - 1);
wildfire_pca *pca;
volatile unsigned long * enable0;
if (!WILDFIRE_PCA_EXISTS(qbbno, pcano)) {
if (!doing_init_irq_hw) {
printk(KERN_ERR "wildfire_update_irq_hw:"
" got irq %d for non-existent PCA %d"
" on QBB %d.\n",
irq, pcano, qbbno);
}
return;
}
pca = WILDFIRE_pca(qbbno, pcano);
enable0 = (unsigned long *) &pca->pca_int[0].enable;
*enable0 = cached_irq_mask[qbbno * WILDFIRE_PCA_PER_QBB + pcano];
mb();
*enable0;
}
static void __init
wildfire_init_irq_hw(void)
{
#if 0
register wildfire_pca * pca = WILDFIRE_pca(0, 0);
volatile unsigned long * enable0, * enable1, * enable2, *enable3;
volatile unsigned long * target0, * target1, * target2, *target3;
enable0 = (unsigned long *) &pca->pca_int[0].enable;
enable1 = (unsigned long *) &pca->pca_int[1].enable;
enable2 = (unsigned long *) &pca->pca_int[2].enable;
enable3 = (unsigned long *) &pca->pca_int[3].enable;
target0 = (unsigned long *) &pca->pca_int[0].target;
target1 = (unsigned long *) &pca->pca_int[1].target;
target2 = (unsigned long *) &pca->pca_int[2].target;
target3 = (unsigned long *) &pca->pca_int[3].target;
*enable0 = *enable1 = *enable2 = *enable3 = 0;
*target0 = (1UL<<8) | WILDFIRE_QBB(0);
*target1 = *target2 = *target3 = 0;
mb();
*enable0; *enable1; *enable2; *enable3;
*target0; *target1; *target2; *target3;
#else
int i;
doing_init_irq_hw = 1;
for (i = 0; i < WILDFIRE_NR_IRQS; i+=WILDFIRE_IRQ_PER_PCA)
wildfire_update_irq_hw(i);
doing_init_irq_hw = 0;
#endif
}
static void
wildfire_enable_irq(struct irq_data *d)
{
unsigned int irq = d->irq;
if (irq < 16)
i8259a_enable_irq(d);
spin_lock(&wildfire_irq_lock);
set_bit(irq, &cached_irq_mask);
wildfire_update_irq_hw(irq);
spin_unlock(&wildfire_irq_lock);
}
static void
wildfire_disable_irq(struct irq_data *d)
{
unsigned int irq = d->irq;
if (irq < 16)
i8259a_disable_irq(d);
spin_lock(&wildfire_irq_lock);
clear_bit(irq, &cached_irq_mask);
wildfire_update_irq_hw(irq);
spin_unlock(&wildfire_irq_lock);
}
static void
wildfire_mask_and_ack_irq(struct irq_data *d)
{
unsigned int irq = d->irq;
if (irq < 16)
i8259a_mask_and_ack_irq(d);
spin_lock(&wildfire_irq_lock);
clear_bit(irq, &cached_irq_mask);
wildfire_update_irq_hw(irq);
spin_unlock(&wildfire_irq_lock);
}
static void __init
wildfire_init_irq_per_pca(int qbbno, int pcano)
{
int i, irq_bias;
static struct irqaction isa_enable = {
.handler = no_action,
.name = "isa_enable",
};
irq_bias = qbbno * (WILDFIRE_PCA_PER_QBB * WILDFIRE_IRQ_PER_PCA)
+ pcano * WILDFIRE_IRQ_PER_PCA;
#if 0
unsigned long io_bias;
io_bias = WILDFIRE_IO(qbbno, pcano<<1) - WILDFIRE_IO_BIAS;
outb(0, DMA1_RESET_REG + io_bias);
outb(0, DMA2_RESET_REG + io_bias);
outb(DMA_MODE_CASCADE, DMA2_MODE_REG + io_bias);
outb(0, DMA2_MASK_REG + io_bias);
#endif
#if 0
init_i8259a_irqs();
#endif
for (i = 0; i < 16; ++i) {
if (i == 2)
continue;
irq_set_chip_and_handler(i + irq_bias, &wildfire_irq_type,
handle_level_irq);
irq_set_status_flags(i + irq_bias, IRQ_LEVEL);
}
irq_set_chip_and_handler(36 + irq_bias, &wildfire_irq_type,
handle_level_irq);
irq_set_status_flags(36 + irq_bias, IRQ_LEVEL);
for (i = 40; i < 64; ++i) {
irq_set_chip_and_handler(i + irq_bias, &wildfire_irq_type,
handle_level_irq);
irq_set_status_flags(i + irq_bias, IRQ_LEVEL);
}
setup_irq(32+irq_bias, &isa_enable);
}
static void __init
wildfire_init_irq(void)
{
int qbbno, pcano;
#if 1
wildfire_init_irq_hw();
init_i8259a_irqs();
#endif
for (qbbno = 0; qbbno < WILDFIRE_MAX_QBB; qbbno++) {
if (WILDFIRE_QBB_EXISTS(qbbno)) {
for (pcano = 0; pcano < WILDFIRE_PCA_PER_QBB; pcano++) {
if (WILDFIRE_PCA_EXISTS(qbbno, pcano)) {
wildfire_init_irq_per_pca(qbbno, pcano);
}
}
}
}
}
static void
wildfire_device_interrupt(unsigned long vector)
{
int irq;
irq = (vector - 0x800) >> 4;
handle_irq(irq);
return;
}
static int __init
wildfire_map_irq(struct pci_dev *dev, u8 slot, u8 pin)
{
static char irq_tab[8][5] __initdata = {
{ -1, -1, -1, -1, -1},
{ 36, 36, 36+1, 36+2, 36+3},
{ 40, 40, 40+1, 40+2, 40+3},
{ 44, 44, 44+1, 44+2, 44+3},
{ 48, 48, 48+1, 48+2, 48+3},
{ 52, 52, 52+1, 52+2, 52+3},
{ 56, 56, 56+1, 56+2, 56+3},
{ 60, 60, 60+1, 60+2, 60+3},
};
long min_idsel = 0, max_idsel = 7, irqs_per_slot = 5;
struct pci_controller *hose = dev->sysdata;
int irq = COMMON_TABLE_LOOKUP;
if (irq > 0) {
int qbbno = hose->index >> 3;
int pcano = (hose->index >> 1) & 3;
irq += (qbbno << 8) + (pcano << 6);
}
return irq;
}
