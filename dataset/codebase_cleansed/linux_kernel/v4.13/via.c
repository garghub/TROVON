void __init via_init(void)
{
switch(macintosh_config->via_type) {
case MAC_VIA_IICI:
via1 = (void *) VIA1_BASE;
if (macintosh_config->ident == MAC_MODEL_IIFX) {
via2 = NULL;
rbv_present = 0;
oss_present = 1;
} else {
via2 = (void *) RBV_BASE;
rbv_present = 1;
oss_present = 0;
}
if (macintosh_config->ident == MAC_MODEL_LCIII) {
rbv_clear = 0x00;
} else {
rbv_clear = 0x80;
}
gIER = rIER;
gIFR = rIFR;
gBufA = rSIFR;
gBufB = rBufB;
break;
case MAC_VIA_QUADRA:
case MAC_VIA_II:
via1 = (void *) VIA1_BASE;
via2 = (void *) VIA2_BASE;
rbv_present = 0;
oss_present = 0;
rbv_clear = 0x00;
gIER = vIER;
gIFR = vIFR;
gBufA = vBufA;
gBufB = vBufB;
break;
default:
panic("UNKNOWN VIA TYPE");
}
printk(KERN_INFO "VIA1 at %p is a 6522 or clone\n", via1);
printk(KERN_INFO "VIA2 at %p is ", via2);
if (rbv_present) {
printk("an RBV\n");
} else if (oss_present) {
printk("an OSS\n");
} else {
printk("a 6522 or clone\n");
}
#ifdef DEBUG_VIA
via_debug_dump();
#endif
via1[vIER] = 0x7F;
via1[vIFR] = 0x7F;
via1[vT1LL] = 0;
via1[vT1LH] = 0;
via1[vT1CL] = 0;
via1[vT1CH] = 0;
via1[vT2CL] = 0;
via1[vT2CH] = 0;
via1[vACR] &= ~0xC0;
via1[vACR] &= ~0x03;
if (macintosh_config->ident == MAC_MODEL_SE30) {
via1[vDirB] |= 0x40;
via1[vBufB] |= 0x40;
}
via1[vDirB] |= (VIA1B_vRTCEnb | VIA1B_vRTCClk | VIA1B_vRTCData);
via1[vBufB] |= (VIA1B_vRTCEnb | VIA1B_vRTCClk);
if (oss_present)
return;
if ((macintosh_config->via_type == MAC_VIA_QUADRA) &&
(macintosh_config->adb_type != MAC_ADB_PB1) &&
(macintosh_config->adb_type != MAC_ADB_PB2) &&
(macintosh_config->ident != MAC_MODEL_C660) &&
(macintosh_config->ident != MAC_MODEL_Q840)) {
via_alt_mapping = 1;
via1[vDirB] |= 0x40;
via1[vBufB] &= ~0x40;
} else {
via_alt_mapping = 0;
}
via2[gIER] = 0x7F;
via2[gIFR] = 0x7F | rbv_clear;
if (!rbv_present) {
via2[vT1LL] = 0;
via2[vT1LH] = 0;
via2[vT1CL] = 0;
via2[vT1CH] = 0;
via2[vT2CL] = 0;
via2[vT2CH] = 0;
via2[vACR] &= ~0xC0;
via2[vACR] &= ~0x03;
}
if (rbv_present)
return;
pr_debug("VIA2 vPCR is 0x%02X\n", via2[vPCR]);
if (macintosh_config->via_type == MAC_VIA_II) {
via2[vPCR] = 0x66;
} else {
via2[vPCR] = 0x22;
}
}
void __init via_init_clock(irq_handler_t func)
{
via1[vACR] |= 0x40;
via1[vT1LL] = MAC_CLOCK_LOW;
via1[vT1LH] = MAC_CLOCK_HIGH;
via1[vT1CL] = MAC_CLOCK_LOW;
via1[vT1CH] = MAC_CLOCK_HIGH;
if (request_irq(IRQ_MAC_TIMER_1, func, 0, "timer", func))
pr_err("Couldn't register %s interrupt\n", "timer");
}
void via_debug_dump(void)
{
printk(KERN_DEBUG "VIA1: DDRA = 0x%02X DDRB = 0x%02X ACR = 0x%02X\n",
(uint) via1[vDirA], (uint) via1[vDirB], (uint) via1[vACR]);
printk(KERN_DEBUG " PCR = 0x%02X IFR = 0x%02X IER = 0x%02X\n",
(uint) via1[vPCR], (uint) via1[vIFR], (uint) via1[vIER]);
if (oss_present) {
printk(KERN_DEBUG "VIA2: <OSS>\n");
} else if (rbv_present) {
printk(KERN_DEBUG "VIA2: IFR = 0x%02X IER = 0x%02X\n",
(uint) via2[rIFR], (uint) via2[rIER]);
printk(KERN_DEBUG " SIFR = 0x%02X SIER = 0x%02X\n",
(uint) via2[rSIFR], (uint) via2[rSIER]);
} else {
printk(KERN_DEBUG "VIA2: DDRA = 0x%02X DDRB = 0x%02X ACR = 0x%02X\n",
(uint) via2[vDirA], (uint) via2[vDirB],
(uint) via2[vACR]);
printk(KERN_DEBUG " PCR = 0x%02X IFR = 0x%02X IER = 0x%02X\n",
(uint) via2[vPCR],
(uint) via2[vIFR], (uint) via2[vIER]);
}
}
u32 mac_gettimeoffset(void)
{
unsigned long ticks, offset = 0;
ticks = via1[vT1CL] | (via1[vT1CH] << 8);
if (ticks > MAC_CLOCK_TICK - MAC_CLOCK_TICK / 50)
if (via1[vIFR] & 0x40) offset = TICK_SIZE;
ticks = MAC_CLOCK_TICK - ticks;
ticks = ticks * 10000L / MAC_CLOCK_TICK;
return (ticks + offset) * 1000;
}
void via_flush_cache(void)
{
via2[gBufB] &= ~VIA2B_vMode32;
via2[gBufB] |= VIA2B_vMode32;
}
int via_get_cache_disable(void)
{
if (!via2) {
printk(KERN_ERR "via_get_cache_disable called on a non-VIA machine!\n");
return 1;
}
return (int) via2[gBufB] & VIA2B_vCDis;
}
void __init via_nubus_init(void)
{
if ((macintosh_config->adb_type != MAC_ADB_PB1) &&
(macintosh_config->adb_type != MAC_ADB_PB2)) {
if (!rbv_present)
via2[vDirB] |= 0x02;
via2[gBufB] |= 0x02;
}
switch (macintosh_config->via_type) {
case MAC_VIA_II:
case MAC_VIA_QUADRA:
pr_debug("VIA2 vDirA is 0x%02X\n", via2[vDirA]);
break;
case MAC_VIA_IICI:
via2[rSIER] = 0x7F;
break;
}
}
void via_nubus_irq_startup(int irq)
{
int irq_idx = IRQ_IDX(irq);
switch (macintosh_config->via_type) {
case MAC_VIA_II:
case MAC_VIA_QUADRA:
if (macintosh_config->via_type == MAC_VIA_II) {
via2[vDirA] &= 0xC0 | ~(1 << irq_idx);
} else {
via2[vDirA] &= 0x80 | ~(1 << irq_idx);
}
case MAC_VIA_IICI:
via_irq_enable(irq);
break;
}
}
void via_nubus_irq_shutdown(int irq)
{
switch (macintosh_config->via_type) {
case MAC_VIA_II:
case MAC_VIA_QUADRA:
via_irq_enable(irq);
break;
case MAC_VIA_IICI:
via_irq_disable(irq);
break;
}
}
void via1_irq(struct irq_desc *desc)
{
int irq_num;
unsigned char irq_bit, events;
events = via1[vIFR] & via1[vIER] & 0x7F;
if (!events)
return;
irq_num = VIA1_SOURCE_BASE;
irq_bit = 1;
do {
if (events & irq_bit) {
via1[vIFR] = irq_bit;
generic_handle_irq(irq_num);
}
++irq_num;
irq_bit <<= 1;
} while (events >= irq_bit);
}
static void via2_irq(struct irq_desc *desc)
{
int irq_num;
unsigned char irq_bit, events;
events = via2[gIFR] & via2[gIER] & 0x7F;
if (!events)
return;
irq_num = VIA2_SOURCE_BASE;
irq_bit = 1;
do {
if (events & irq_bit) {
via2[gIFR] = irq_bit | rbv_clear;
generic_handle_irq(irq_num);
}
++irq_num;
irq_bit <<= 1;
} while (events >= irq_bit);
}
static void via_nubus_irq(struct irq_desc *desc)
{
int slot_irq;
unsigned char slot_bit, events;
events = ~via2[gBufA] & 0x7F;
if (rbv_present)
events &= via2[rSIER];
else
events &= ~via2[vDirA];
if (!events)
return;
do {
slot_irq = IRQ_NUBUS_F;
slot_bit = 0x40;
do {
if (events & slot_bit) {
events &= ~slot_bit;
generic_handle_irq(slot_irq);
}
--slot_irq;
slot_bit >>= 1;
} while (events);
via2[gIFR] = 0x02 | rbv_clear;
events = ~via2[gBufA] & 0x7F;
if (rbv_present)
events &= via2[rSIER];
else
events &= ~via2[vDirA];
} while (events);
}
void __init via_register_interrupts(void)
{
if (via_alt_mapping) {
irq_set_chained_handler(IRQ_AUTO_1, via1_irq);
irq_set_chained_handler(IRQ_AUTO_6, via1_irq);
} else {
irq_set_chained_handler(IRQ_AUTO_1, via1_irq);
}
irq_set_chained_handler(IRQ_AUTO_2, via2_irq);
irq_set_chained_handler(IRQ_MAC_NUBUS, via_nubus_irq);
}
void via_irq_enable(int irq) {
int irq_src = IRQ_SRC(irq);
int irq_idx = IRQ_IDX(irq);
if (irq_src == 1) {
via1[vIER] = IER_SET_BIT(irq_idx);
} else if (irq_src == 2) {
if (irq != IRQ_MAC_NUBUS || nubus_disabled == 0)
via2[gIER] = IER_SET_BIT(irq_idx);
} else if (irq_src == 7) {
switch (macintosh_config->via_type) {
case MAC_VIA_II:
case MAC_VIA_QUADRA:
nubus_disabled &= ~(1 << irq_idx);
if (!nubus_disabled)
via2[gIER] = IER_SET_BIT(1);
break;
case MAC_VIA_IICI:
via2[rSIER] = IER_SET_BIT(irq_idx);
break;
}
}
}
void via_irq_disable(int irq) {
int irq_src = IRQ_SRC(irq);
int irq_idx = IRQ_IDX(irq);
if (irq_src == 1) {
via1[vIER] = IER_CLR_BIT(irq_idx);
} else if (irq_src == 2) {
via2[gIER] = IER_CLR_BIT(irq_idx);
} else if (irq_src == 7) {
switch (macintosh_config->via_type) {
case MAC_VIA_II:
case MAC_VIA_QUADRA:
nubus_disabled |= 1 << irq_idx;
if (nubus_disabled)
via2[gIER] = IER_CLR_BIT(1);
break;
case MAC_VIA_IICI:
via2[rSIER] = IER_CLR_BIT(irq_idx);
break;
}
}
}
void via1_set_head(int head)
{
if (head == 0)
via1[vBufA] &= ~VIA1A_vHeadSel;
else
via1[vBufA] |= VIA1A_vHeadSel;
}
int via2_scsi_drq_pending(void)
{
return via2[gIFR] & (1 << IRQ_IDX(IRQ_MAC_SCSIDRQ));
}
