static irqreturn_t
hfcs_interrupt(int intno, void *dev_id)
{
struct IsdnCardState *cs = dev_id;
u_char val, stat;
u_long flags;
spin_lock_irqsave(&cs->lock, flags);
if ((HFCD_ANYINT | HFCD_BUSY_NBUSY) &
(stat = cs->BC_Read_Reg(cs, HFCD_DATA, HFCD_STAT))) {
val = cs->BC_Read_Reg(cs, HFCD_DATA, HFCD_INT_S1);
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "HFCS: stat(%02x) s1(%02x)", stat, val);
hfc2bds0_interrupt(cs, val);
} else {
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "HFCS: irq_no_irq stat(%02x)", stat);
}
spin_unlock_irqrestore(&cs->lock, flags);
return IRQ_HANDLED;
}
static void
hfcs_Timer(struct IsdnCardState *cs)
{
cs->hw.hfcD.timer.expires = jiffies + 75;
}
static void
release_io_hfcs(struct IsdnCardState *cs)
{
release2bds0(cs);
del_timer(&cs->hw.hfcD.timer);
if (cs->hw.hfcD.addr)
release_region(cs->hw.hfcD.addr, 2);
}
static void
reset_hfcs(struct IsdnCardState *cs)
{
printk(KERN_INFO "HFCS: resetting card\n");
cs->hw.hfcD.cirm = HFCD_RESET;
if (cs->typ == ISDN_CTYPE_TELES3C)
cs->hw.hfcD.cirm |= HFCD_MEM8K;
cs->BC_Write_Reg(cs, HFCD_DATA, HFCD_CIRM, cs->hw.hfcD.cirm);
mdelay(10);
cs->hw.hfcD.cirm = 0;
if (cs->typ == ISDN_CTYPE_TELES3C)
cs->hw.hfcD.cirm |= HFCD_MEM8K;
cs->BC_Write_Reg(cs, HFCD_DATA, HFCD_CIRM, cs->hw.hfcD.cirm);
mdelay(10);
if (cs->typ == ISDN_CTYPE_TELES3C)
cs->hw.hfcD.cirm |= HFCD_INTB;
else if (cs->typ == ISDN_CTYPE_ACERP10)
cs->hw.hfcD.cirm |= HFCD_INTA;
cs->BC_Write_Reg(cs, HFCD_DATA, HFCD_CIRM, cs->hw.hfcD.cirm);
cs->BC_Write_Reg(cs, HFCD_DATA, HFCD_CLKDEL, 0x0e);
cs->BC_Write_Reg(cs, HFCD_DATA, HFCD_TEST, HFCD_AUTO_AWAKE);
cs->hw.hfcD.ctmt = HFCD_TIM25 | HFCD_AUTO_TIMER;
cs->BC_Write_Reg(cs, HFCD_DATA, HFCD_CTMT, cs->hw.hfcD.ctmt);
cs->hw.hfcD.int_m2 = HFCD_IRQ_ENABLE;
cs->hw.hfcD.int_m1 = HFCD_INTS_B1TRANS | HFCD_INTS_B2TRANS |
HFCD_INTS_DTRANS | HFCD_INTS_B1REC | HFCD_INTS_B2REC |
HFCD_INTS_DREC | HFCD_INTS_L1STATE;
cs->BC_Write_Reg(cs, HFCD_DATA, HFCD_INT_M1, cs->hw.hfcD.int_m1);
cs->BC_Write_Reg(cs, HFCD_DATA, HFCD_INT_M2, cs->hw.hfcD.int_m2);
cs->BC_Write_Reg(cs, HFCD_DATA, HFCD_STATES, HFCD_LOAD_STATE | 2);
udelay(10);
cs->BC_Write_Reg(cs, HFCD_DATA, HFCD_STATES, 2);
cs->hw.hfcD.mst_m = HFCD_MASTER;
cs->BC_Write_Reg(cs, HFCD_DATA, HFCD_MST_MODE, cs->hw.hfcD.mst_m);
cs->hw.hfcD.sctrl = 0;
cs->BC_Write_Reg(cs, HFCD_DATA, HFCD_SCTRL, cs->hw.hfcD.sctrl);
}
static int
hfcs_card_msg(struct IsdnCardState *cs, int mt, void *arg)
{
u_long flags;
int delay;
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "HFCS: card_msg %x", mt);
switch (mt) {
case CARD_RESET:
spin_lock_irqsave(&cs->lock, flags);
reset_hfcs(cs);
spin_unlock_irqrestore(&cs->lock, flags);
return (0);
case CARD_RELEASE:
release_io_hfcs(cs);
return (0);
case CARD_INIT:
delay = (75 * HZ) / 100 + 1;
mod_timer(&cs->hw.hfcD.timer, jiffies + delay);
spin_lock_irqsave(&cs->lock, flags);
reset_hfcs(cs);
init2bds0(cs);
spin_unlock_irqrestore(&cs->lock, flags);
delay = (80 * HZ) / 1000 + 1;
msleep(80);
spin_lock_irqsave(&cs->lock, flags);
cs->hw.hfcD.ctmt |= HFCD_TIM800;
cs->BC_Write_Reg(cs, HFCD_DATA, HFCD_CTMT, cs->hw.hfcD.ctmt);
cs->BC_Write_Reg(cs, HFCD_DATA, HFCD_MST_MODE, cs->hw.hfcD.mst_m);
spin_unlock_irqrestore(&cs->lock, flags);
return (0);
case CARD_TEST:
return (0);
}
return (0);
}
int setup_hfcs(struct IsdnCard *card)
{
struct IsdnCardState *cs = card->cs;
char tmp[64];
strcpy(tmp, hfcs_revision);
printk(KERN_INFO "HiSax: HFC-S driver Rev. %s\n", HiSax_getrev(tmp));
#ifdef __ISAPNP__
if (!card->para[1] && isapnp_present()) {
struct pnp_dev *pnp_d;
while (ipid->card_vendor) {
if ((pnp_c = pnp_find_card(ipid->card_vendor,
ipid->card_device, pnp_c))) {
pnp_d = NULL;
if ((pnp_d = pnp_find_dev(pnp_c,
ipid->vendor, ipid->function, pnp_d))) {
int err;
printk(KERN_INFO "HiSax: %s detected\n",
(char *)ipid->driver_data);
pnp_disable_dev(pnp_d);
err = pnp_activate_dev(pnp_d);
if (err < 0) {
printk(KERN_WARNING "%s: pnp_activate_dev ret(%d)\n",
__func__, err);
return (0);
}
card->para[1] = pnp_port_start(pnp_d, 0);
card->para[0] = pnp_irq(pnp_d, 0);
if (!card->para[0] || !card->para[1]) {
printk(KERN_ERR "HFC PnP:some resources are missing %ld/%lx\n",
card->para[0], card->para[1]);
pnp_disable_dev(pnp_d);
return (0);
}
break;
} else {
printk(KERN_ERR "HFC PnP: PnP error card found, no device\n");
}
}
ipid++;
pnp_c = NULL;
}
if (!ipid->card_vendor) {
printk(KERN_INFO "HFC PnP: no ISAPnP card found\n");
return (0);
}
}
#endif
cs->hw.hfcD.addr = card->para[1] & 0xfffe;
cs->irq = card->para[0];
cs->hw.hfcD.cip = 0;
cs->hw.hfcD.int_s1 = 0;
cs->hw.hfcD.send = NULL;
cs->bcs[0].hw.hfc.send = NULL;
cs->bcs[1].hw.hfc.send = NULL;
cs->hw.hfcD.dfifosize = 512;
cs->dc.hfcd.ph_state = 0;
cs->hw.hfcD.fifo = 255;
if (cs->typ == ISDN_CTYPE_TELES3C) {
cs->hw.hfcD.bfifosize = 1024 + 512;
} else if (cs->typ == ISDN_CTYPE_ACERP10) {
cs->hw.hfcD.bfifosize = 7 * 1024 + 512;
} else
return (0);
if (!request_region(cs->hw.hfcD.addr, 2, "HFCS isdn")) {
printk(KERN_WARNING
"HiSax: %s config port %x-%x already in use\n",
CardType[card->typ],
cs->hw.hfcD.addr,
cs->hw.hfcD.addr + 2);
return (0);
}
printk(KERN_INFO
"HFCS: defined at 0x%x IRQ %d HZ %d\n",
cs->hw.hfcD.addr,
cs->irq, HZ);
if (cs->typ == ISDN_CTYPE_TELES3C) {
outb(0x00, cs->hw.hfcD.addr);
outb(0x56, cs->hw.hfcD.addr | 1);
} else if (cs->typ == ISDN_CTYPE_ACERP10) {
outb(0x00, cs->hw.hfcD.addr);
outb(0x57, cs->hw.hfcD.addr | 1);
}
set_cs_func(cs);
cs->hw.hfcD.timer.function = (void *) hfcs_Timer;
cs->hw.hfcD.timer.data = (long) cs;
init_timer(&cs->hw.hfcD.timer);
cs->cardmsg = &hfcs_card_msg;
cs->irq_func = &hfcs_interrupt;
return (1);
}
