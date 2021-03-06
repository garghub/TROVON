static void __init search_IAR(void)
{
unsigned ivg, irq_pos = 0;
for (ivg = 0; ivg <= IVG13 - IVG7; ivg++) {
int irqN;
ivg7_13[ivg].istop = ivg7_13[ivg].ifirst = &ivg_table[irq_pos];
for (irqN = 0; irqN < NR_PERI_INTS; irqN += 4) {
int irqn;
u32 iar =
bfin_read32((unsigned long *)SIC_IAR0 +
#if defined(CONFIG_BF51x) || defined(CONFIG_BF52x) || \
defined(CONFIG_BF538) || defined(CONFIG_BF539)
((irqN % 32) >> 3) + ((irqN / 32) * ((SIC_IAR4 - SIC_IAR0) / 4))
#else
(irqN >> 3)
#endif
);
for (irqn = irqN; irqn < irqN + 4; ++irqn) {
int iar_shift = (irqn & 7) * 4;
if (ivg == (0xf & (iar >> iar_shift))) {
ivg_table[irq_pos].irqno = IVG7 + irqn;
ivg_table[irq_pos].isrflag = 1 << (irqn % 32);
ivg7_13[ivg].istop++;
irq_pos++;
}
}
}
}
}
void bfin_ack_noop(struct irq_data *d)
{
}
static void bfin_core_mask_irq(struct irq_data *d)
{
bfin_irq_flags &= ~(1 << d->irq);
if (!hard_irqs_disabled())
hard_local_irq_enable();
}
static void bfin_core_unmask_irq(struct irq_data *d)
{
bfin_irq_flags |= 1 << d->irq;
if (!hard_irqs_disabled())
hard_local_irq_enable();
return;
}
void bfin_internal_mask_irq(unsigned int irq)
{
unsigned long flags = hard_local_irq_save();
#ifndef CONFIG_BF60x
#ifdef SIC_IMASK0
unsigned mask_bank = SIC_SYSIRQ(irq) / 32;
unsigned mask_bit = SIC_SYSIRQ(irq) % 32;
bfin_write_SIC_IMASK(mask_bank, bfin_read_SIC_IMASK(mask_bank) &
~(1 << mask_bit));
# if defined(CONFIG_SMP) || defined(CONFIG_ICC)
bfin_write_SICB_IMASK(mask_bank, bfin_read_SICB_IMASK(mask_bank) &
~(1 << mask_bit));
# endif
#else
bfin_write_SIC_IMASK(bfin_read_SIC_IMASK() &
~(1 << SIC_SYSIRQ(irq)));
#endif
#endif
hard_local_irq_restore(flags);
}
static void bfin_internal_mask_irq_chip(struct irq_data *d)
{
bfin_internal_mask_irq(d->irq);
}
static void bfin_sec_preflow_handler(struct irq_data *d)
{
unsigned long flags = hard_local_irq_save();
unsigned int sid = SIC_SYSIRQ(d->irq);
bfin_write_SEC_SCI(0, SEC_CSID, sid);
hard_local_irq_restore(flags);
}
static void bfin_sec_mask_ack_irq(struct irq_data *d)
{
unsigned long flags = hard_local_irq_save();
unsigned int sid = SIC_SYSIRQ(d->irq);
bfin_write_SEC_SCI(0, SEC_CSID, sid);
hard_local_irq_restore(flags);
}
static void bfin_sec_unmask_irq(struct irq_data *d)
{
unsigned long flags = hard_local_irq_save();
unsigned int sid = SIC_SYSIRQ(d->irq);
bfin_write32(SEC_END, sid);
hard_local_irq_restore(flags);
}
static void bfin_sec_enable_ssi(unsigned int sid)
{
unsigned long flags = hard_local_irq_save();
uint32_t reg_sctl = bfin_read_SEC_SCTL(sid);
reg_sctl |= SEC_SCTL_SRC_EN;
bfin_write_SEC_SCTL(sid, reg_sctl);
hard_local_irq_restore(flags);
}
static void bfin_sec_disable_ssi(unsigned int sid)
{
unsigned long flags = hard_local_irq_save();
uint32_t reg_sctl = bfin_read_SEC_SCTL(sid);
reg_sctl &= ((uint32_t)~SEC_SCTL_SRC_EN);
bfin_write_SEC_SCTL(sid, reg_sctl);
hard_local_irq_restore(flags);
}
static void bfin_sec_set_ssi_coreid(unsigned int sid, unsigned int coreid)
{
unsigned long flags = hard_local_irq_save();
uint32_t reg_sctl = bfin_read_SEC_SCTL(sid);
reg_sctl &= ((uint32_t)~SEC_SCTL_CTG);
bfin_write_SEC_SCTL(sid, reg_sctl | ((coreid << 20) & SEC_SCTL_CTG));
hard_local_irq_restore(flags);
}
static void bfin_sec_enable_sci(unsigned int sid)
{
unsigned long flags = hard_local_irq_save();
uint32_t reg_sctl = bfin_read_SEC_SCTL(sid);
if (sid == SIC_SYSIRQ(IRQ_WATCH0))
reg_sctl |= SEC_SCTL_FAULT_EN;
else
reg_sctl |= SEC_SCTL_INT_EN;
bfin_write_SEC_SCTL(sid, reg_sctl);
hard_local_irq_restore(flags);
}
static void bfin_sec_disable_sci(unsigned int sid)
{
unsigned long flags = hard_local_irq_save();
uint32_t reg_sctl = bfin_read_SEC_SCTL(sid);
reg_sctl &= ((uint32_t)~SEC_SCTL_INT_EN);
bfin_write_SEC_SCTL(sid, reg_sctl);
hard_local_irq_restore(flags);
}
static void bfin_sec_enable(struct irq_data *d)
{
unsigned long flags = hard_local_irq_save();
unsigned int sid = SIC_SYSIRQ(d->irq);
bfin_sec_enable_sci(sid);
bfin_sec_enable_ssi(sid);
hard_local_irq_restore(flags);
}
static void bfin_sec_disable(struct irq_data *d)
{
unsigned long flags = hard_local_irq_save();
unsigned int sid = SIC_SYSIRQ(d->irq);
bfin_sec_disable_sci(sid);
bfin_sec_disable_ssi(sid);
hard_local_irq_restore(flags);
}
static void bfin_sec_raise_irq(unsigned int sid)
{
unsigned long flags = hard_local_irq_save();
bfin_write32(SEC_RAISE, sid);
hard_local_irq_restore(flags);
}
static void init_software_driven_irq(void)
{
bfin_sec_set_ssi_coreid(34, 0);
bfin_sec_set_ssi_coreid(35, 1);
bfin_sec_set_ssi_coreid(36, 0);
bfin_sec_set_ssi_coreid(37, 1);
}
void bfin_sec_resume(void)
{
bfin_write_SEC_SCI(0, SEC_CCTL, SEC_CCTL_RESET);
udelay(100);
bfin_write_SEC_GCTL(SEC_GCTL_EN);
bfin_write_SEC_SCI(0, SEC_CCTL, SEC_CCTL_EN | SEC_CCTL_NMI_EN);
}
void handle_sec_sfi_fault(uint32_t gstat)
{
}
void handle_sec_sci_fault(uint32_t gstat)
{
uint32_t core_id;
uint32_t cstat;
core_id = gstat & SEC_GSTAT_SCI;
cstat = bfin_read_SEC_SCI(core_id, SEC_CSTAT);
if (cstat & SEC_CSTAT_ERR) {
switch (cstat & SEC_CSTAT_ERRC) {
case SEC_CSTAT_ACKERR:
printk(KERN_DEBUG "sec ack err\n");
break;
default:
printk(KERN_DEBUG "sec sci unknow err\n");
}
}
}
void handle_sec_ssi_fault(uint32_t gstat)
{
uint32_t sid;
uint32_t sstat;
sid = gstat & SEC_GSTAT_SID;
sstat = bfin_read_SEC_SSTAT(sid);
}
void handle_sec_fault(unsigned int irq, struct irq_desc *desc)
{
uint32_t sec_gstat;
raw_spin_lock(&desc->lock);
sec_gstat = bfin_read32(SEC_GSTAT);
if (sec_gstat & SEC_GSTAT_ERR) {
switch (sec_gstat & SEC_GSTAT_ERRC) {
case 0:
handle_sec_sfi_fault(sec_gstat);
break;
case SEC_GSTAT_SCIERR:
handle_sec_sci_fault(sec_gstat);
break;
case SEC_GSTAT_SSIERR:
handle_sec_ssi_fault(sec_gstat);
break;
}
}
raw_spin_unlock(&desc->lock);
}
static int sec_suspend(void)
{
return 0;
}
static void sec_resume(void)
{
bfin_write_SEC_SCI(0, SEC_CCTL, SEC_CCTL_RESET);
udelay(100);
bfin_write_SEC_GCTL(SEC_GCTL_EN);
bfin_write_SEC_SCI(0, SEC_CCTL, SEC_CCTL_EN | SEC_CCTL_NMI_EN);
}
static void bfin_internal_unmask_irq_chip(struct irq_data *d)
{
bfin_internal_unmask_irq_affinity(d->irq, d->affinity);
}
static int bfin_internal_set_affinity(struct irq_data *d,
const struct cpumask *mask, bool force)
{
bfin_internal_mask_irq(d->irq);
bfin_internal_unmask_irq_affinity(d->irq, mask);
return 0;
}
static void bfin_internal_unmask_irq_chip(struct irq_data *d)
{
bfin_internal_unmask_irq(d->irq);
}
int bfin_internal_set_wake(unsigned int irq, unsigned int state)
{
u32 bank, bit, wakeup = 0;
unsigned long flags;
bank = SIC_SYSIRQ(irq) / 32;
bit = SIC_SYSIRQ(irq) % 32;
switch (irq) {
#ifdef IRQ_RTC
case IRQ_RTC:
wakeup |= WAKE;
break;
#endif
#ifdef IRQ_CAN0_RX
case IRQ_CAN0_RX:
wakeup |= CANWE;
break;
#endif
#ifdef IRQ_CAN1_RX
case IRQ_CAN1_RX:
wakeup |= CANWE;
break;
#endif
#ifdef IRQ_USB_INT0
case IRQ_USB_INT0:
wakeup |= USBWE;
break;
#endif
#ifdef CONFIG_BF54x
case IRQ_CNT:
wakeup |= ROTWE;
break;
#endif
default:
break;
}
flags = hard_local_irq_save();
if (state) {
bfin_sic_iwr[bank] |= (1 << bit);
vr_wakeup |= wakeup;
} else {
bfin_sic_iwr[bank] &= ~(1 << bit);
vr_wakeup &= ~wakeup;
}
hard_local_irq_restore(flags);
return 0;
}
static int bfin_internal_set_wake_chip(struct irq_data *d, unsigned int state)
{
return bfin_internal_set_wake(d->irq, state);
}
void bfin_handle_irq(unsigned irq)
{
#ifdef CONFIG_IPIPE
struct pt_regs regs;
ipipe_trace_irq_entry(irq);
__ipipe_handle_irq(irq, &regs);
ipipe_trace_irq_exit(irq);
#else
generic_handle_irq(irq);
#endif
}
static void bfin_mac_status_ack_irq(unsigned int irq)
{
switch (irq) {
case IRQ_MAC_MMCINT:
bfin_write_EMAC_MMC_TIRQS(
bfin_read_EMAC_MMC_TIRQE() &
bfin_read_EMAC_MMC_TIRQS());
bfin_write_EMAC_MMC_RIRQS(
bfin_read_EMAC_MMC_RIRQE() &
bfin_read_EMAC_MMC_RIRQS());
break;
case IRQ_MAC_RXFSINT:
bfin_write_EMAC_RX_STKY(
bfin_read_EMAC_RX_IRQE() &
bfin_read_EMAC_RX_STKY());
break;
case IRQ_MAC_TXFSINT:
bfin_write_EMAC_TX_STKY(
bfin_read_EMAC_TX_IRQE() &
bfin_read_EMAC_TX_STKY());
break;
case IRQ_MAC_WAKEDET:
bfin_write_EMAC_WKUP_CTL(
bfin_read_EMAC_WKUP_CTL() | MPKS | RWKS);
break;
default:
bfin_write_EMAC_SYSTAT(1L << (irq - IRQ_MAC_PHYINT));
break;
}
}
static void bfin_mac_status_mask_irq(struct irq_data *d)
{
unsigned int irq = d->irq;
mac_stat_int_mask &= ~(1L << (irq - IRQ_MAC_PHYINT));
#ifdef BF537_FAMILY
switch (irq) {
case IRQ_MAC_PHYINT:
bfin_write_EMAC_SYSCTL(bfin_read_EMAC_SYSCTL() & ~PHYIE);
break;
default:
break;
}
#else
if (!mac_stat_int_mask)
bfin_internal_mask_irq(IRQ_MAC_ERROR);
#endif
bfin_mac_status_ack_irq(irq);
}
static void bfin_mac_status_unmask_irq(struct irq_data *d)
{
unsigned int irq = d->irq;
#ifdef BF537_FAMILY
switch (irq) {
case IRQ_MAC_PHYINT:
bfin_write_EMAC_SYSCTL(bfin_read_EMAC_SYSCTL() | PHYIE);
break;
default:
break;
}
#else
if (!mac_stat_int_mask)
bfin_internal_unmask_irq(IRQ_MAC_ERROR);
#endif
mac_stat_int_mask |= 1L << (irq - IRQ_MAC_PHYINT);
}
int bfin_mac_status_set_wake(struct irq_data *d, unsigned int state)
{
#ifdef BF537_FAMILY
return bfin_internal_set_wake(IRQ_GENERIC_ERROR, state);
#else
return bfin_internal_set_wake(IRQ_MAC_ERROR, state);
#endif
}
void bfin_demux_mac_status_irq(unsigned int int_err_irq,
struct irq_desc *inta_desc)
{
int i, irq = 0;
u32 status = bfin_read_EMAC_SYSTAT();
for (i = 0; i <= (IRQ_MAC_STMDONE - IRQ_MAC_PHYINT); i++)
if (status & (1L << i)) {
irq = IRQ_MAC_PHYINT + i;
break;
}
if (irq) {
if (mac_stat_int_mask & (1L << (irq - IRQ_MAC_PHYINT))) {
bfin_handle_irq(irq);
} else {
bfin_mac_status_ack_irq(irq);
pr_debug("IRQ %d:"
" MASKED MAC ERROR INTERRUPT ASSERTED\n",
irq);
}
} else
printk(KERN_ERR
"%s : %s : LINE %d :\nIRQ ?: MAC ERROR"
" INTERRUPT ASSERTED BUT NO SOURCE FOUND"
"(EMAC_SYSTAT=0x%X)\n",
__func__, __FILE__, __LINE__, status);
}
static inline void bfin_set_irq_handler(unsigned irq, irq_flow_handler_t handle)
{
#ifdef CONFIG_IPIPE
handle = handle_level_irq;
#endif
__irq_set_handler_locked(irq, handle);
}
static void bfin_gpio_ack_irq(struct irq_data *d)
{
set_gpio_data(irq_to_gpio(d->irq), 0);
}
static void bfin_gpio_mask_ack_irq(struct irq_data *d)
{
unsigned int irq = d->irq;
u32 gpionr = irq_to_gpio(irq);
if (!irqd_is_level_type(d))
set_gpio_data(gpionr, 0);
set_gpio_maska(gpionr, 0);
}
static void bfin_gpio_mask_irq(struct irq_data *d)
{
set_gpio_maska(irq_to_gpio(d->irq), 0);
}
static void bfin_gpio_unmask_irq(struct irq_data *d)
{
set_gpio_maska(irq_to_gpio(d->irq), 1);
}
static unsigned int bfin_gpio_irq_startup(struct irq_data *d)
{
u32 gpionr = irq_to_gpio(d->irq);
if (__test_and_set_bit(gpionr, gpio_enabled))
bfin_gpio_irq_prepare(gpionr);
bfin_gpio_unmask_irq(d);
return 0;
}
static void bfin_gpio_irq_shutdown(struct irq_data *d)
{
u32 gpionr = irq_to_gpio(d->irq);
bfin_gpio_mask_irq(d);
__clear_bit(gpionr, gpio_enabled);
bfin_gpio_irq_free(gpionr);
}
static int bfin_gpio_irq_type(struct irq_data *d, unsigned int type)
{
unsigned int irq = d->irq;
int ret;
char buf[16];
u32 gpionr = irq_to_gpio(irq);
if (type == IRQ_TYPE_PROBE) {
if (test_bit(gpionr, gpio_enabled))
return 0;
type = IRQ_TYPE_EDGE_RISING | IRQ_TYPE_EDGE_FALLING;
}
if (type & (IRQ_TYPE_EDGE_RISING | IRQ_TYPE_EDGE_FALLING |
IRQ_TYPE_LEVEL_HIGH | IRQ_TYPE_LEVEL_LOW)) {
snprintf(buf, 16, "gpio-irq%d", irq);
ret = bfin_gpio_irq_request(gpionr, buf);
if (ret)
return ret;
if (__test_and_set_bit(gpionr, gpio_enabled))
bfin_gpio_irq_prepare(gpionr);
} else {
__clear_bit(gpionr, gpio_enabled);
return 0;
}
set_gpio_inen(gpionr, 0);
set_gpio_dir(gpionr, 0);
if ((type & (IRQ_TYPE_EDGE_RISING | IRQ_TYPE_EDGE_FALLING))
== (IRQ_TYPE_EDGE_RISING | IRQ_TYPE_EDGE_FALLING))
set_gpio_both(gpionr, 1);
else
set_gpio_both(gpionr, 0);
if ((type & (IRQ_TYPE_EDGE_FALLING | IRQ_TYPE_LEVEL_LOW)))
set_gpio_polar(gpionr, 1);
else
set_gpio_polar(gpionr, 0);
if (type & (IRQ_TYPE_EDGE_RISING | IRQ_TYPE_EDGE_FALLING)) {
set_gpio_edge(gpionr, 1);
set_gpio_inen(gpionr, 1);
set_gpio_data(gpionr, 0);
} else {
set_gpio_edge(gpionr, 0);
set_gpio_inen(gpionr, 1);
}
if (type & (IRQ_TYPE_EDGE_RISING | IRQ_TYPE_EDGE_FALLING))
bfin_set_irq_handler(irq, handle_edge_irq);
else
bfin_set_irq_handler(irq, handle_level_irq);
return 0;
}
static int bfin_gpio_set_wake(struct irq_data *d, unsigned int state)
{
return gpio_pm_wakeup_ctrl(irq_to_gpio(d->irq), state);
}
static void bfin_demux_gpio_block(unsigned int irq)
{
unsigned int gpio, mask;
gpio = irq_to_gpio(irq);
mask = get_gpiop_data(gpio) & get_gpiop_maska(gpio);
while (mask) {
if (mask & 1)
bfin_handle_irq(irq);
irq++;
mask >>= 1;
}
}
void bfin_demux_gpio_irq(unsigned int inta_irq,
struct irq_desc *desc)
{
unsigned int irq;
switch (inta_irq) {
#if defined(BF537_FAMILY)
case IRQ_PF_INTA_PG_INTA:
bfin_demux_gpio_block(IRQ_PF0);
irq = IRQ_PG0;
break;
case IRQ_PH_INTA_MAC_RX:
irq = IRQ_PH0;
break;
#elif defined(BF533_FAMILY)
case IRQ_PROG_INTA:
irq = IRQ_PF0;
break;
#elif defined(BF538_FAMILY)
case IRQ_PORTF_INTA:
irq = IRQ_PF0;
break;
#elif defined(CONFIG_BF52x) || defined(CONFIG_BF51x)
case IRQ_PORTF_INTA:
irq = IRQ_PF0;
break;
case IRQ_PORTG_INTA:
irq = IRQ_PG0;
break;
case IRQ_PORTH_INTA:
irq = IRQ_PH0;
break;
#elif defined(CONFIG_BF561)
case IRQ_PROG0_INTA:
irq = IRQ_PF0;
break;
case IRQ_PROG1_INTA:
irq = IRQ_PF16;
break;
case IRQ_PROG2_INTA:
irq = IRQ_PF32;
break;
#endif
default:
BUG();
return;
}
bfin_demux_gpio_block(irq);
}
inline unsigned int get_irq_base(u32 bank, u8 bmap)
{
unsigned int irq_base;
if (bank < 2) {
irq_base = IRQ_PA0 + bmap * 16;
} else {
irq_base = IRQ_PC0 + bmap * 16;
}
return irq_base;
}
inline unsigned int get_irq_base(u32 bank, u8 bmap)
{
unsigned int irq_base;
irq_base = IRQ_PA0 + bank * 16 + bmap * 16;
return irq_base;
}
void init_pint_lut(void)
{
u16 bank, bit, irq_base, bit_pos;
u32 pint_assign;
u8 bmap;
memset(irq2pint_lut, IRQ_NOT_AVAIL, sizeof(irq2pint_lut));
for (bank = 0; bank < NR_PINT_SYS_IRQS; bank++) {
pint_assign = pint[bank]->assign;
for (bit = 0; bit < NR_PINT_BITS; bit++) {
bmap = (pint_assign >> ((bit / 8) * 8)) & 0xFF;
irq_base = get_irq_base(bank, bmap);
irq_base += (bit % 8) + ((bit / 8) & 1 ? 8 : 0);
bit_pos = bit + bank * NR_PINT_BITS;
pint2irq_lut[bit_pos] = irq_base - SYS_IRQS;
irq2pint_lut[irq_base - SYS_IRQS] = bit_pos;
}
}
}
static void bfin_gpio_ack_irq(struct irq_data *d)
{
u32 pint_val = irq2pint_lut[d->irq - SYS_IRQS];
u32 pintbit = PINT_BIT(pint_val);
u32 bank = PINT_2_BANK(pint_val);
if (irqd_get_trigger_type(d) == IRQ_TYPE_EDGE_BOTH) {
if (pint[bank]->invert_set & pintbit)
pint[bank]->invert_clear = pintbit;
else
pint[bank]->invert_set = pintbit;
}
pint[bank]->request = pintbit;
}
static void bfin_gpio_mask_ack_irq(struct irq_data *d)
{
u32 pint_val = irq2pint_lut[d->irq - SYS_IRQS];
u32 pintbit = PINT_BIT(pint_val);
u32 bank = PINT_2_BANK(pint_val);
if (irqd_get_trigger_type(d) == IRQ_TYPE_EDGE_BOTH) {
if (pint[bank]->invert_set & pintbit)
pint[bank]->invert_clear = pintbit;
else
pint[bank]->invert_set = pintbit;
}
pint[bank]->request = pintbit;
pint[bank]->mask_clear = pintbit;
}
static void bfin_gpio_mask_irq(struct irq_data *d)
{
u32 pint_val = irq2pint_lut[d->irq - SYS_IRQS];
pint[PINT_2_BANK(pint_val)]->mask_clear = PINT_BIT(pint_val);
}
static void bfin_gpio_unmask_irq(struct irq_data *d)
{
u32 pint_val = irq2pint_lut[d->irq - SYS_IRQS];
u32 pintbit = PINT_BIT(pint_val);
u32 bank = PINT_2_BANK(pint_val);
pint[bank]->mask_set = pintbit;
}
static unsigned int bfin_gpio_irq_startup(struct irq_data *d)
{
unsigned int irq = d->irq;
u32 gpionr = irq_to_gpio(irq);
u32 pint_val = irq2pint_lut[irq - SYS_IRQS];
if (pint_val == IRQ_NOT_AVAIL) {
printk(KERN_ERR
"GPIO IRQ %d :Not in PINT Assign table "
"Reconfigure Interrupt to Port Assignemt\n", irq);
return -ENODEV;
}
if (__test_and_set_bit(gpionr, gpio_enabled))
bfin_gpio_irq_prepare(gpionr);
bfin_gpio_unmask_irq(d);
return 0;
}
static void bfin_gpio_irq_shutdown(struct irq_data *d)
{
u32 gpionr = irq_to_gpio(d->irq);
bfin_gpio_mask_irq(d);
__clear_bit(gpionr, gpio_enabled);
bfin_gpio_irq_free(gpionr);
}
static int bfin_gpio_irq_type(struct irq_data *d, unsigned int type)
{
unsigned int irq = d->irq;
int ret;
char buf[16];
u32 gpionr = irq_to_gpio(irq);
u32 pint_val = irq2pint_lut[irq - SYS_IRQS];
u32 pintbit = PINT_BIT(pint_val);
u32 bank = PINT_2_BANK(pint_val);
if (pint_val == IRQ_NOT_AVAIL)
return -ENODEV;
if (type == IRQ_TYPE_PROBE) {
if (test_bit(gpionr, gpio_enabled))
return 0;
type = IRQ_TYPE_EDGE_RISING | IRQ_TYPE_EDGE_FALLING;
}
if (type & (IRQ_TYPE_EDGE_RISING | IRQ_TYPE_EDGE_FALLING |
IRQ_TYPE_LEVEL_HIGH | IRQ_TYPE_LEVEL_LOW)) {
snprintf(buf, 16, "gpio-irq%d", irq);
ret = bfin_gpio_irq_request(gpionr, buf);
if (ret)
return ret;
if (__test_and_set_bit(gpionr, gpio_enabled))
bfin_gpio_irq_prepare(gpionr);
} else {
__clear_bit(gpionr, gpio_enabled);
return 0;
}
if ((type & (IRQ_TYPE_EDGE_FALLING | IRQ_TYPE_LEVEL_LOW)))
pint[bank]->invert_set = pintbit;
else
pint[bank]->invert_clear = pintbit;
if ((type & (IRQ_TYPE_EDGE_RISING | IRQ_TYPE_EDGE_FALLING))
== (IRQ_TYPE_EDGE_RISING | IRQ_TYPE_EDGE_FALLING)) {
if (gpio_get_value(gpionr))
pint[bank]->invert_set = pintbit;
else
pint[bank]->invert_clear = pintbit;
}
if (type & (IRQ_TYPE_EDGE_RISING | IRQ_TYPE_EDGE_FALLING)) {
pint[bank]->edge_set = pintbit;
bfin_set_irq_handler(irq, handle_edge_irq);
} else {
pint[bank]->edge_clear = pintbit;
bfin_set_irq_handler(irq, handle_level_irq);
}
return 0;
}
static int bfin_gpio_set_wake(struct irq_data *d, unsigned int state)
{
u32 pint_irq;
u32 pint_val = irq2pint_lut[d->irq - SYS_IRQS];
u32 bank = PINT_2_BANK(pint_val);
switch (bank) {
case 0:
pint_irq = IRQ_PINT0;
break;
case 2:
pint_irq = IRQ_PINT2;
break;
case 3:
pint_irq = IRQ_PINT3;
break;
case 1:
pint_irq = IRQ_PINT1;
break;
#ifdef CONFIG_BF60x
case 4:
pint_irq = IRQ_PINT4;
break;
case 5:
pint_irq = IRQ_PINT5;
break;
#endif
default:
return -EINVAL;
}
bfin_internal_set_wake(pint_irq, state);
return 0;
}
void bfin_demux_gpio_irq(unsigned int inta_irq,
struct irq_desc *desc)
{
u32 bank, pint_val;
u32 request, irq;
u32 level_mask;
int umask = 0;
struct irq_chip *chip = irq_desc_get_chip(desc);
if (chip->irq_mask_ack) {
chip->irq_mask_ack(&desc->irq_data);
} else {
chip->irq_mask(&desc->irq_data);
if (chip->irq_ack)
chip->irq_ack(&desc->irq_data);
}
switch (inta_irq) {
case IRQ_PINT0:
bank = 0;
break;
case IRQ_PINT2:
bank = 2;
break;
case IRQ_PINT3:
bank = 3;
break;
case IRQ_PINT1:
bank = 1;
break;
#ifdef CONFIG_BF60x
case IRQ_PINT4:
bank = 4;
break;
case IRQ_PINT5:
bank = 5;
break;
#endif
default:
return;
}
pint_val = bank * NR_PINT_BITS;
request = pint[bank]->request;
level_mask = pint[bank]->edge_set & request;
while (request) {
if (request & 1) {
irq = pint2irq_lut[pint_val] + SYS_IRQS;
if (level_mask & PINT_BIT(pint_val)) {
umask = 1;
chip->irq_unmask(&desc->irq_data);
}
bfin_handle_irq(irq);
}
pint_val++;
request >>= 1;
}
if (!umask)
chip->irq_unmask(&desc->irq_data);
}
void __cpuinit init_exception_vectors(void)
{
bfin_write_EVT2(evt_nmi);
bfin_write_EVT3(trap);
bfin_write_EVT5(evt_ivhw);
bfin_write_EVT6(evt_timer);
bfin_write_EVT7(evt_evt7);
bfin_write_EVT8(evt_evt8);
bfin_write_EVT9(evt_evt9);
bfin_write_EVT10(evt_evt10);
bfin_write_EVT11(evt_evt11);
bfin_write_EVT12(evt_evt12);
bfin_write_EVT13(evt_evt13);
bfin_write_EVT14(evt_evt14);
bfin_write_EVT15(evt_system_call);
CSYNC();
}
int __init init_arch_irq(void)
{
int irq;
unsigned long ilat = 0;
#ifndef CONFIG_BF60x
#ifdef SIC_IMASK0
bfin_write_SIC_IMASK0(SIC_UNMASK_ALL);
bfin_write_SIC_IMASK1(SIC_UNMASK_ALL);
# ifdef SIC_IMASK2
bfin_write_SIC_IMASK2(SIC_UNMASK_ALL);
# endif
# if defined(CONFIG_SMP) || defined(CONFIG_ICC)
bfin_write_SICB_IMASK0(SIC_UNMASK_ALL);
bfin_write_SICB_IMASK1(SIC_UNMASK_ALL);
# endif
#else
bfin_write_SIC_IMASK(SIC_UNMASK_ALL);
#endif
#else
bfin_write_SEC_GCTL(SEC_GCTL_RESET);
#endif
local_irq_disable();
#if BFIN_GPIO_PINT
# ifdef CONFIG_PINTx_REASSIGN
pint[0]->assign = CONFIG_PINT0_ASSIGN;
pint[1]->assign = CONFIG_PINT1_ASSIGN;
pint[2]->assign = CONFIG_PINT2_ASSIGN;
pint[3]->assign = CONFIG_PINT3_ASSIGN;
# ifdef CONFIG_BF60x
pint[4]->assign = CONFIG_PINT4_ASSIGN;
pint[5]->assign = CONFIG_PINT5_ASSIGN;
# endif
# endif
init_pint_lut();
#endif
for (irq = 0; irq <= SYS_IRQS; irq++) {
if (irq <= IRQ_CORETMR)
irq_set_chip(irq, &bfin_core_irqchip);
else
irq_set_chip(irq, &bfin_internal_irqchip);
switch (irq) {
#ifndef CONFIG_BF60x
#if BFIN_GPIO_PINT
case IRQ_PINT0:
case IRQ_PINT1:
case IRQ_PINT2:
case IRQ_PINT3:
#elif defined(BF537_FAMILY)
case IRQ_PH_INTA_MAC_RX:
case IRQ_PF_INTA_PG_INTA:
#elif defined(BF533_FAMILY)
case IRQ_PROG_INTA:
#elif defined(CONFIG_BF52x) || defined(CONFIG_BF51x)
case IRQ_PORTF_INTA:
case IRQ_PORTG_INTA:
case IRQ_PORTH_INTA:
#elif defined(CONFIG_BF561)
case IRQ_PROG0_INTA:
case IRQ_PROG1_INTA:
case IRQ_PROG2_INTA:
#elif defined(BF538_FAMILY)
case IRQ_PORTF_INTA:
#endif
irq_set_chained_handler(irq, bfin_demux_gpio_irq);
break;
#if defined(CONFIG_BFIN_MAC) || defined(CONFIG_BFIN_MAC_MODULE)
case IRQ_MAC_ERROR:
irq_set_chained_handler(irq,
bfin_demux_mac_status_irq);
break;
#endif
#if defined(CONFIG_SMP) || defined(CONFIG_ICC)
case IRQ_SUPPLE_0:
case IRQ_SUPPLE_1:
irq_set_handler(irq, handle_percpu_irq);
break;
#endif
#endif
#ifdef CONFIG_TICKSOURCE_CORETMR
case IRQ_CORETMR:
# ifdef CONFIG_SMP
irq_set_handler(irq, handle_percpu_irq);
# else
irq_set_handler(irq, handle_simple_irq);
# endif
break;
#endif
#ifdef CONFIG_TICKSOURCE_GPTMR0
case IRQ_TIMER0:
irq_set_handler(irq, handle_simple_irq);
break;
#endif
default:
#ifdef CONFIG_IPIPE
irq_set_handler(irq, handle_level_irq);
#else
irq_set_handler(irq, handle_simple_irq);
#endif
break;
}
}
init_mach_irq();
#ifndef CONFIG_BF60x
#if (defined(CONFIG_BFIN_MAC) || defined(CONFIG_BFIN_MAC_MODULE)) && !defined(CONFIG_BF60x)
for (irq = IRQ_MAC_PHYINT; irq <= IRQ_MAC_STMDONE; irq++)
irq_set_chip_and_handler(irq, &bfin_mac_status_irqchip,
handle_level_irq);
#endif
for (irq = GPIO_IRQ_BASE;
irq < (GPIO_IRQ_BASE + MAX_BLACKFIN_GPIOS); irq++)
irq_set_chip_and_handler(irq, &bfin_gpio_irqchip,
handle_level_irq);
#else
for (irq = BFIN_IRQ(0); irq <= SYS_IRQS; irq++) {
if (irq < CORE_IRQS) {
irq_set_chip(irq, &bfin_sec_irqchip);
__irq_set_handler(irq, handle_sec_fault, 0, NULL);
} else if (irq >= BFIN_IRQ(21) && irq <= BFIN_IRQ(26)) {
irq_set_chip(irq, &bfin_sec_irqchip);
irq_set_chained_handler(irq, bfin_demux_gpio_irq);
} else if (irq >= BFIN_IRQ(34) && irq <= BFIN_IRQ(37)) {
irq_set_chip(irq, &bfin_sec_irqchip);
irq_set_handler(irq, handle_percpu_irq);
} else {
irq_set_chip_and_handler(irq, &bfin_sec_irqchip,
handle_fasteoi_irq);
__irq_set_preflow_handler(irq, bfin_sec_preflow_handler);
}
}
for (irq = GPIO_IRQ_BASE;
irq < (GPIO_IRQ_BASE + MAX_BLACKFIN_GPIOS); irq++)
irq_set_chip_and_handler(irq, &bfin_gpio_irqchip,
handle_level_irq);
#endif
bfin_write_IMASK(0);
CSYNC();
ilat = bfin_read_ILAT();
CSYNC();
bfin_write_ILAT(ilat);
CSYNC();
printk(KERN_INFO "Configuring Blackfin Priority Driven Interrupts\n");
#ifndef CONFIG_BF60x
program_IAR();
search_IAR();
bfin_irq_flags |= IMASK_IVG15 |
IMASK_IVG14 | IMASK_IVG13 | IMASK_IVG12 | IMASK_IVG11 |
IMASK_IVG10 | IMASK_IVG9 | IMASK_IVG8 | IMASK_IVG7 | IMASK_IVGHW;
bfin_sti(bfin_irq_flags);
#ifdef SIC_IWR0
bfin_write_SIC_IWR0(IWR_DISABLE_ALL);
# ifdef SIC_IWR1
if (ANOMALY_05000435)
bfin_write_SIC_IWR1(IWR_ENABLE(10) | IWR_ENABLE(11));
else
bfin_write_SIC_IWR1(IWR_DISABLE_ALL);
# endif
# ifdef SIC_IWR2
bfin_write_SIC_IWR2(IWR_DISABLE_ALL);
# endif
#else
bfin_write_SIC_IWR(IWR_DISABLE_ALL);
#endif
#else
bfin_irq_flags |= IMASK_IVG15 |
IMASK_IVG14 | IMASK_IVG13 | IMASK_IVG12 | IMASK_IVG11 |
IMASK_IVG10 | IMASK_IVG9 | IMASK_IVG8 | IMASK_IVG7 | IMASK_IVGHW;
bfin_write_SEC_FCTL(SEC_FCTL_EN | SEC_FCTL_SYSRST_EN | SEC_FCTL_FLTIN_EN);
bfin_sec_enable_sci(SIC_SYSIRQ(IRQ_WATCH0));
bfin_sec_enable_ssi(SIC_SYSIRQ(IRQ_WATCH0));
bfin_write_SEC_SCI(0, SEC_CCTL, SEC_CCTL_RESET);
udelay(100);
bfin_write_SEC_GCTL(SEC_GCTL_EN);
bfin_write_SEC_SCI(0, SEC_CCTL, SEC_CCTL_EN | SEC_CCTL_NMI_EN);
init_software_driven_irq();
register_syscore_ops(&sec_pm_syscore_ops);
#endif
return 0;
}
static int vec_to_irq(int vec)
{
#ifndef CONFIG_BF60x
struct ivgx *ivg = ivg7_13[vec - IVG7].ifirst;
struct ivgx *ivg_stop = ivg7_13[vec - IVG7].istop;
unsigned long sic_status[3];
#endif
if (likely(vec == EVT_IVTMR_P))
return IRQ_CORETMR;
#ifndef CONFIG_BF60x
#ifdef SIC_ISR
sic_status[0] = bfin_read_SIC_IMASK() & bfin_read_SIC_ISR();
#else
if (smp_processor_id()) {
# ifdef SICB_ISR0
sic_status[0] = bfin_read_SICB_ISR0() & bfin_read_SICB_IMASK0();
sic_status[1] = bfin_read_SICB_ISR1() & bfin_read_SICB_IMASK1();
# endif
} else {
sic_status[0] = bfin_read_SIC_ISR0() & bfin_read_SIC_IMASK0();
sic_status[1] = bfin_read_SIC_ISR1() & bfin_read_SIC_IMASK1();
}
#endif
#ifdef SIC_ISR2
sic_status[2] = bfin_read_SIC_ISR2() & bfin_read_SIC_IMASK2();
#endif
for (;; ivg++) {
if (ivg >= ivg_stop)
return -1;
#ifdef SIC_ISR
if (sic_status[0] & ivg->isrflag)
#else
if (sic_status[(ivg->irqno - IVG7) / 32] & ivg->isrflag)
#endif
return ivg->irqno;
}
#else
return BFIN_IRQ(bfin_read_SEC_SCI(0, SEC_CSID));
#endif
}
void do_irq(int vec, struct pt_regs *fp)
{
int irq = vec_to_irq(vec);
if (irq == -1)
return;
asm_do_IRQ(irq, fp);
}
int __ipipe_get_irq_priority(unsigned irq)
{
int ient, prio;
if (irq <= IRQ_CORETMR)
return irq;
for (ient = 0; ient < NR_PERI_INTS; ient++) {
struct ivgx *ivg = ivg_table + ient;
if (ivg->irqno == irq) {
for (prio = 0; prio <= IVG13-IVG7; prio++) {
if (ivg7_13[prio].ifirst <= ivg &&
ivg7_13[prio].istop > ivg)
return IVG7 + prio;
}
}
}
return IVG15;
}
asmlinkage int __ipipe_grab_irq(int vec, struct pt_regs *regs)
{
struct ipipe_percpu_domain_data *p = ipipe_root_cpudom_ptr();
struct ipipe_domain *this_domain = __ipipe_current_domain;
struct ivgx *ivg_stop = ivg7_13[vec-IVG7].istop;
struct ivgx *ivg = ivg7_13[vec-IVG7].ifirst;
int irq, s = 0;
irq = vec_to_irq(vec);
if (irq == -1)
return 0;
if (irq == IRQ_SYSTMR) {
#if !defined(CONFIG_GENERIC_CLOCKEVENTS) || defined(CONFIG_TICKSOURCE_GPTMR0)
bfin_write_TIMER_STATUS(1);
#endif
__raw_get_cpu_var(__ipipe_tick_regs).ipend = regs->ipend;
__raw_get_cpu_var(__ipipe_tick_regs).pc = regs->pc;
if (this_domain != ipipe_root_domain)
__raw_get_cpu_var(__ipipe_tick_regs).ipend &= ~0x10;
else
__raw_get_cpu_var(__ipipe_tick_regs).ipend |= 0x10;
}
if (this_domain == ipipe_root_domain) {
s = __test_and_set_bit(IPIPE_SYNCDEFER_FLAG, &p->status);
barrier();
}
ipipe_trace_irq_entry(irq);
__ipipe_handle_irq(irq, regs);
ipipe_trace_irq_exit(irq);
if (user_mode(regs) &&
!ipipe_test_foreign_stack() &&
(current->ipipe_flags & PF_EVTRET) != 0) {
current->ipipe_flags &= ~PF_EVTRET;
__ipipe_dispatch_event(IPIPE_EVENT_RETURN, regs);
}
if (this_domain == ipipe_root_domain) {
set_thread_flag(TIF_IRQ_SYNC);
if (!s) {
__clear_bit(IPIPE_SYNCDEFER_FLAG, &p->status);
return !test_bit(IPIPE_STALL_FLAG, &p->status);
}
}
return 0;
}
