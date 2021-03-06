static unsigned long psycho_pcislot_imap_offset(unsigned long ino)
{
unsigned int bus = (ino & 0x10) >> 4;
unsigned int slot = (ino & 0x0c) >> 2;
if (bus == 0)
return PSYCHO_IMAP_A_SLOT0 + (slot * 8);
else
return PSYCHO_IMAP_B_SLOT0 + (slot * 8);
}
static unsigned int psycho_irq_build(struct device_node *dp,
unsigned int ino,
void *_data)
{
unsigned long controller_regs = (unsigned long) _data;
unsigned long imap, iclr;
unsigned long imap_off, iclr_off;
int inofixup = 0;
ino &= 0x3f;
if (ino < PSYCHO_ONBOARD_IRQ_BASE) {
imap_off = psycho_pcislot_imap_offset(ino);
} else {
imap_off = psycho_onboard_imap_offset(ino);
}
imap = controller_regs + imap_off;
iclr_off = psycho_iclr_offset(ino);
iclr = controller_regs + iclr_off;
if ((ino & 0x20) == 0)
inofixup = ino & 0x03;
return build_irq(inofixup, iclr, imap);
}
static void __init psycho_irq_trans_init(struct device_node *dp)
{
const struct linux_prom64_registers *regs;
dp->irq_trans = prom_early_alloc(sizeof(struct of_irq_controller));
dp->irq_trans->irq_build = psycho_irq_build;
regs = of_get_property(dp, "reg", NULL);
dp->irq_trans->data = (void *) regs[2].phys_addr;
}
static void sabre_wsync_handler(unsigned int ino, void *_arg1, void *_arg2)
{
unsigned int phys_hi = (unsigned int) (unsigned long) _arg1;
struct sabre_irq_data *irq_data = _arg2;
unsigned long controller_regs = irq_data->controller_regs;
unsigned long sync_reg = controller_regs + SABRE_WRSYNC;
unsigned long config_space = controller_regs + SABRE_CONFIGSPACE;
unsigned int bus, devfn;
u16 _unused;
config_space = SABRE_CONFIG_BASE(config_space);
bus = (phys_hi >> 16) & 0xff;
devfn = (phys_hi >> 8) & 0xff;
config_space |= SABRE_CONFIG_ENCODE(bus, devfn, 0x00);
__asm__ __volatile__("membar #Sync\n\t"
"lduha [%1] %2, %0\n\t"
"membar #Sync"
: "=r" (_unused)
: "r" ((u16 *) config_space),
"i" (ASI_PHYS_BYPASS_EC_E_L)
: "memory");
sabre_read(sync_reg);
}
static unsigned long sabre_pcislot_imap_offset(unsigned long ino)
{
unsigned int bus = (ino & 0x10) >> 4;
unsigned int slot = (ino & 0x0c) >> 2;
if (bus == 0)
return SABRE_IMAP_A_SLOT0 + (slot * 8);
else
return SABRE_IMAP_B_SLOT0 + (slot * 8);
}
static int sabre_device_needs_wsync(struct device_node *dp)
{
struct device_node *parent = dp->parent;
const char *parent_model, *parent_compat;
while (parent) {
if (!strcmp(parent->type, "pci"))
break;
parent = parent->parent;
}
if (!parent)
return 0;
parent_model = of_get_property(parent,
"model", NULL);
if (parent_model &&
(!strcmp(parent_model, "SUNW,sabre") ||
!strcmp(parent_model, "SUNW,simba")))
return 0;
parent_compat = of_get_property(parent,
"compatible", NULL);
if (parent_compat &&
(!strcmp(parent_compat, "pci108e,a000") ||
!strcmp(parent_compat, "pci108e,a001")))
return 0;
return 1;
}
static unsigned int sabre_irq_build(struct device_node *dp,
unsigned int ino,
void *_data)
{
struct sabre_irq_data *irq_data = _data;
unsigned long controller_regs = irq_data->controller_regs;
const struct linux_prom_pci_registers *regs;
unsigned long imap, iclr;
unsigned long imap_off, iclr_off;
int inofixup = 0;
int irq;
ino &= 0x3f;
if (ino < SABRE_ONBOARD_IRQ_BASE) {
imap_off = sabre_pcislot_imap_offset(ino);
} else {
imap_off = sabre_onboard_imap_offset(ino);
}
imap = controller_regs + imap_off;
iclr_off = sabre_iclr_offset(ino);
iclr = controller_regs + iclr_off;
if ((ino & 0x20) == 0)
inofixup = ino & 0x03;
irq = build_irq(inofixup, iclr, imap);
regs = of_get_property(dp, "reg", NULL);
if (regs && sabre_device_needs_wsync(dp)) {
irq_install_pre_handler(irq,
sabre_wsync_handler,
(void *) (long) regs->phys_hi,
(void *) irq_data);
}
return irq;
}
static void __init sabre_irq_trans_init(struct device_node *dp)
{
const struct linux_prom64_registers *regs;
struct sabre_irq_data *irq_data;
const u32 *busrange;
dp->irq_trans = prom_early_alloc(sizeof(struct of_irq_controller));
dp->irq_trans->irq_build = sabre_irq_build;
irq_data = prom_early_alloc(sizeof(struct sabre_irq_data));
regs = of_get_property(dp, "reg", NULL);
irq_data->controller_regs = regs[0].phys_addr;
busrange = of_get_property(dp, "bus-range", NULL);
irq_data->pci_first_busno = busrange[0];
dp->irq_trans->data = irq_data;
}
static unsigned long schizo_imap_offset(unsigned long ino)
{
return SCHIZO_IMAP_BASE + (ino * 8UL);
}
static unsigned long schizo_iclr_offset(unsigned long ino)
{
return SCHIZO_ICLR_BASE + (ino * 8UL);
}
static unsigned long schizo_ino_to_iclr(unsigned long pbm_regs,
unsigned int ino)
{
return pbm_regs + schizo_iclr_offset(ino);
}
static unsigned long schizo_ino_to_imap(unsigned long pbm_regs,
unsigned int ino)
{
return pbm_regs + schizo_imap_offset(ino);
}
static void tomatillo_wsync_handler(unsigned int ino, void *_arg1, void *_arg2)
{
unsigned long sync_reg = (unsigned long) _arg2;
u64 mask = 1UL << (ino & IMAP_INO);
u64 val;
int limit;
schizo_write(sync_reg, mask);
limit = 100000;
val = 0;
while (--limit) {
val = schizo_read(sync_reg);
if (!(val & mask))
break;
}
if (limit <= 0) {
printk("tomatillo_wsync_handler: DMA won't sync [%llx:%llx]\n",
val, mask);
}
if (_arg1) {
static unsigned char cacheline[64]
__attribute__ ((aligned (64)));
__asm__ __volatile__("rd %%fprs, %0\n\t"
"or %0, %4, %1\n\t"
"wr %1, 0x0, %%fprs\n\t"
"stda %%f0, [%5] %6\n\t"
"wr %0, 0x0, %%fprs\n\t"
"membar #Sync"
: "=&r" (mask), "=&r" (val)
: "0" (mask), "1" (val),
"i" (FPRS_FEF), "r" (&cacheline[0]),
"i" (ASI_BLK_COMMIT_P));
}
}
static unsigned int schizo_irq_build(struct device_node *dp,
unsigned int ino,
void *_data)
{
struct schizo_irq_data *irq_data = _data;
unsigned long pbm_regs = irq_data->pbm_regs;
unsigned long imap, iclr;
int ign_fixup;
int irq;
int is_tomatillo;
ino &= 0x3f;
imap = schizo_ino_to_imap(pbm_regs, ino);
iclr = schizo_ino_to_iclr(pbm_regs, ino);
ign_fixup = 0;
is_tomatillo = (irq_data->sync_reg != 0UL);
if (is_tomatillo) {
if (irq_data->portid & 1)
ign_fixup = (1 << 6);
}
irq = build_irq(ign_fixup, iclr, imap);
if (is_tomatillo) {
irq_install_pre_handler(irq,
tomatillo_wsync_handler,
((irq_data->chip_version <= 4) ?
(void *) 1 : (void *) 0),
(void *) irq_data->sync_reg);
}
return irq;
}
static void __init __schizo_irq_trans_init(struct device_node *dp,
int is_tomatillo)
{
const struct linux_prom64_registers *regs;
struct schizo_irq_data *irq_data;
dp->irq_trans = prom_early_alloc(sizeof(struct of_irq_controller));
dp->irq_trans->irq_build = schizo_irq_build;
irq_data = prom_early_alloc(sizeof(struct schizo_irq_data));
regs = of_get_property(dp, "reg", NULL);
dp->irq_trans->data = irq_data;
irq_data->pbm_regs = regs[0].phys_addr;
if (is_tomatillo)
irq_data->sync_reg = regs[3].phys_addr + 0x1a18UL;
else
irq_data->sync_reg = 0UL;
irq_data->portid = of_getintprop_default(dp, "portid", 0);
irq_data->chip_version = of_getintprop_default(dp, "version#", 0);
}
static void __init schizo_irq_trans_init(struct device_node *dp)
{
__schizo_irq_trans_init(dp, 0);
}
static void __init tomatillo_irq_trans_init(struct device_node *dp)
{
__schizo_irq_trans_init(dp, 1);
}
static unsigned int pci_sun4v_irq_build(struct device_node *dp,
unsigned int devino,
void *_data)
{
u32 devhandle = (u32) (unsigned long) _data;
return sun4v_build_irq(devhandle, devino);
}
static void __init pci_sun4v_irq_trans_init(struct device_node *dp)
{
const struct linux_prom64_registers *regs;
dp->irq_trans = prom_early_alloc(sizeof(struct of_irq_controller));
dp->irq_trans->irq_build = pci_sun4v_irq_build;
regs = of_get_property(dp, "reg", NULL);
dp->irq_trans->data = (void *) (unsigned long)
((regs->phys_addr >> 32UL) & 0x0fffffff);
}
static unsigned long fire_imap_offset(unsigned long ino)
{
return FIRE_IMAP_BASE + (ino * 8UL);
}
static unsigned long fire_iclr_offset(unsigned long ino)
{
return FIRE_ICLR_BASE + (ino * 8UL);
}
static unsigned long fire_ino_to_iclr(unsigned long pbm_regs,
unsigned int ino)
{
return pbm_regs + fire_iclr_offset(ino);
}
static unsigned long fire_ino_to_imap(unsigned long pbm_regs,
unsigned int ino)
{
return pbm_regs + fire_imap_offset(ino);
}
static unsigned int fire_irq_build(struct device_node *dp,
unsigned int ino,
void *_data)
{
struct fire_irq_data *irq_data = _data;
unsigned long pbm_regs = irq_data->pbm_regs;
unsigned long imap, iclr;
unsigned long int_ctrlr;
ino &= 0x3f;
imap = fire_ino_to_imap(pbm_regs, ino);
iclr = fire_ino_to_iclr(pbm_regs, ino);
int_ctrlr = 1 << 6;
upa_writeq(int_ctrlr, imap);
ino |= (irq_data->portid << 6);
ino -= int_ctrlr;
return build_irq(ino, iclr, imap);
}
static void __init fire_irq_trans_init(struct device_node *dp)
{
const struct linux_prom64_registers *regs;
struct fire_irq_data *irq_data;
dp->irq_trans = prom_early_alloc(sizeof(struct of_irq_controller));
dp->irq_trans->irq_build = fire_irq_build;
irq_data = prom_early_alloc(sizeof(struct fire_irq_data));
regs = of_get_property(dp, "reg", NULL);
dp->irq_trans->data = irq_data;
irq_data->pbm_regs = regs[0].phys_addr;
irq_data->portid = of_getintprop_default(dp, "portid", 0);
}
static unsigned long sysio_imap_to_iclr(unsigned long imap)
{
unsigned long diff = SYSIO_ICLR_UNUSED0 - SYSIO_IMAP_SLOT0;
return imap + diff;
}
static unsigned int sbus_of_build_irq(struct device_node *dp,
unsigned int ino,
void *_data)
{
unsigned long reg_base = (unsigned long) _data;
const struct linux_prom_registers *regs;
unsigned long imap, iclr;
int sbus_slot = 0;
int sbus_level = 0;
ino &= 0x3f;
regs = of_get_property(dp, "reg", NULL);
if (regs)
sbus_slot = regs->which_io;
if (ino < 0x20)
ino += (sbus_slot * 8);
imap = sysio_irq_offsets[ino];
if (imap == ((unsigned long)-1)) {
prom_printf("get_irq_translations: Bad SYSIO INO[%x]\n",
ino);
prom_halt();
}
imap += reg_base;
if (ino >= 0x20) {
iclr = sysio_imap_to_iclr(imap);
} else {
sbus_level = ino & 0x7;
switch(sbus_slot) {
case 0:
iclr = reg_base + SYSIO_ICLR_SLOT0;
break;
case 1:
iclr = reg_base + SYSIO_ICLR_SLOT1;
break;
case 2:
iclr = reg_base + SYSIO_ICLR_SLOT2;
break;
default:
case 3:
iclr = reg_base + SYSIO_ICLR_SLOT3;
break;
}
iclr += ((unsigned long)sbus_level - 1UL) * 8UL;
}
return build_irq(sbus_level, iclr, imap);
}
static void __init sbus_irq_trans_init(struct device_node *dp)
{
const struct linux_prom64_registers *regs;
dp->irq_trans = prom_early_alloc(sizeof(struct of_irq_controller));
dp->irq_trans->irq_build = sbus_of_build_irq;
regs = of_get_property(dp, "reg", NULL);
dp->irq_trans->data = (void *) (unsigned long) regs->phys_addr;
}
static unsigned int central_build_irq(struct device_node *dp,
unsigned int ino,
void *_data)
{
struct device_node *central_dp = _data;
struct platform_device *central_op = of_find_device_by_node(central_dp);
struct resource *res;
unsigned long imap, iclr;
u32 tmp;
if (!strcmp(dp->name, "eeprom")) {
res = &central_op->resource[5];
} else if (!strcmp(dp->name, "zs")) {
res = &central_op->resource[4];
} else if (!strcmp(dp->name, "clock-board")) {
res = &central_op->resource[3];
} else {
return ino;
}
imap = res->start + 0x00UL;
iclr = res->start + 0x10UL;
upa_writel(0, iclr);
upa_readl(iclr);
tmp = upa_readl(imap);
tmp &= ~0x80000000;
upa_writel(tmp, imap);
return build_irq(0, iclr, imap);
}
static void __init central_irq_trans_init(struct device_node *dp)
{
dp->irq_trans = prom_early_alloc(sizeof(struct of_irq_controller));
dp->irq_trans->irq_build = central_build_irq;
dp->irq_trans->data = dp;
}
static unsigned int sun4v_vdev_irq_build(struct device_node *dp,
unsigned int devino,
void *_data)
{
u32 devhandle = (u32) (unsigned long) _data;
return sun4v_build_irq(devhandle, devino);
}
static void __init sun4v_vdev_irq_trans_init(struct device_node *dp)
{
const struct linux_prom64_registers *regs;
dp->irq_trans = prom_early_alloc(sizeof(struct of_irq_controller));
dp->irq_trans->irq_build = sun4v_vdev_irq_build;
regs = of_get_property(dp, "reg", NULL);
dp->irq_trans->data = (void *) (unsigned long)
((regs->phys_addr >> 32UL) & 0x0fffffff);
}
void __init irq_trans_init(struct device_node *dp)
{
#ifdef CONFIG_PCI
const char *model;
int i;
#endif
#ifdef CONFIG_PCI
model = of_get_property(dp, "model", NULL);
if (!model)
model = of_get_property(dp, "compatible", NULL);
if (model) {
for (i = 0; i < ARRAY_SIZE(pci_irq_trans_table); i++) {
struct irq_trans *t = &pci_irq_trans_table[i];
if (!strcmp(model, t->name)) {
t->init(dp);
return;
}
}
}
#endif
#ifdef CONFIG_SBUS
if (!strcmp(dp->name, "sbus") ||
!strcmp(dp->name, "sbi")) {
sbus_irq_trans_init(dp);
return;
}
#endif
if (!strcmp(dp->name, "fhc") &&
!strcmp(dp->parent->name, "central")) {
central_irq_trans_init(dp);
return;
}
if (!strcmp(dp->name, "virtual-devices") ||
!strcmp(dp->name, "niu")) {
sun4v_vdev_irq_trans_init(dp);
return;
}
}
