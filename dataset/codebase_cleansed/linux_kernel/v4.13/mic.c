static inline u_char
readreg(unsigned int ale, unsigned int adr, u_char off)
{
register u_char ret;
byteout(ale, off);
ret = bytein(adr);
return (ret);
}
static inline void
readfifo(unsigned int ale, unsigned int adr, u_char off, u_char *data, int size)
{
byteout(ale, off);
insb(adr, data, size);
}
static inline void
writereg(unsigned int ale, unsigned int adr, u_char off, u_char data)
{
byteout(ale, off);
byteout(adr, data);
}
static inline void
writefifo(unsigned int ale, unsigned int adr, u_char off, u_char *data, int size)
{
byteout(ale, off);
outsb(adr, data, size);
}
static u_char
ReadISAC(struct IsdnCardState *cs, u_char offset)
{
return (readreg(cs->hw.mic.adr, cs->hw.mic.isac, offset));
}
static void
WriteISAC(struct IsdnCardState *cs, u_char offset, u_char value)
{
writereg(cs->hw.mic.adr, cs->hw.mic.isac, offset, value);
}
static void
ReadISACfifo(struct IsdnCardState *cs, u_char *data, int size)
{
readfifo(cs->hw.mic.adr, cs->hw.mic.isac, 0, data, size);
}
static void
WriteISACfifo(struct IsdnCardState *cs, u_char *data, int size)
{
writefifo(cs->hw.mic.adr, cs->hw.mic.isac, 0, data, size);
}
static u_char
ReadHSCX(struct IsdnCardState *cs, int hscx, u_char offset)
{
return (readreg(cs->hw.mic.adr,
cs->hw.mic.hscx, offset + (hscx ? 0x40 : 0)));
}
static void
WriteHSCX(struct IsdnCardState *cs, int hscx, u_char offset, u_char value)
{
writereg(cs->hw.mic.adr,
cs->hw.mic.hscx, offset + (hscx ? 0x40 : 0), value);
}
static irqreturn_t
mic_interrupt(int intno, void *dev_id)
{
struct IsdnCardState *cs = dev_id;
u_char val;
u_long flags;
spin_lock_irqsave(&cs->lock, flags);
val = readreg(cs->hw.mic.adr, cs->hw.mic.hscx, HSCX_ISTA + 0x40);
Start_HSCX:
if (val)
hscx_int_main(cs, val);
val = readreg(cs->hw.mic.adr, cs->hw.mic.isac, ISAC_ISTA);
Start_ISAC:
if (val)
isac_interrupt(cs, val);
val = readreg(cs->hw.mic.adr, cs->hw.mic.hscx, HSCX_ISTA + 0x40);
if (val) {
if (cs->debug & L1_DEB_HSCX)
debugl1(cs, "HSCX IntStat after IntRoutine");
goto Start_HSCX;
}
val = readreg(cs->hw.mic.adr, cs->hw.mic.isac, ISAC_ISTA);
if (val) {
if (cs->debug & L1_DEB_ISAC)
debugl1(cs, "ISAC IntStat after IntRoutine");
goto Start_ISAC;
}
writereg(cs->hw.mic.adr, cs->hw.mic.hscx, HSCX_MASK, 0xFF);
writereg(cs->hw.mic.adr, cs->hw.mic.hscx, HSCX_MASK + 0x40, 0xFF);
writereg(cs->hw.mic.adr, cs->hw.mic.isac, ISAC_MASK, 0xFF);
writereg(cs->hw.mic.adr, cs->hw.mic.isac, ISAC_MASK, 0x0);
writereg(cs->hw.mic.adr, cs->hw.mic.hscx, HSCX_MASK, 0x0);
writereg(cs->hw.mic.adr, cs->hw.mic.hscx, HSCX_MASK + 0x40, 0x0);
spin_unlock_irqrestore(&cs->lock, flags);
return IRQ_HANDLED;
}
static void
release_io_mic(struct IsdnCardState *cs)
{
int bytecnt = 8;
if (cs->hw.mic.cfg_reg)
release_region(cs->hw.mic.cfg_reg, bytecnt);
}
static int
mic_card_msg(struct IsdnCardState *cs, int mt, void *arg)
{
u_long flags;
switch (mt) {
case CARD_RESET:
return (0);
case CARD_RELEASE:
release_io_mic(cs);
return (0);
case CARD_INIT:
spin_lock_irqsave(&cs->lock, flags);
inithscx(cs);
inithscxisac(cs, 3);
spin_unlock_irqrestore(&cs->lock, flags);
return (0);
case CARD_TEST:
return (0);
}
return (0);
}
int setup_mic(struct IsdnCard *card)
{
int bytecnt;
struct IsdnCardState *cs = card->cs;
char tmp[64];
strcpy(tmp, mic_revision);
printk(KERN_INFO "HiSax: mic driver Rev. %s\n", HiSax_getrev(tmp));
if (cs->typ != ISDN_CTYPE_MIC)
return (0);
bytecnt = 8;
cs->hw.mic.cfg_reg = card->para[1];
cs->irq = card->para[0];
cs->hw.mic.adr = cs->hw.mic.cfg_reg + MIC_ADR;
cs->hw.mic.isac = cs->hw.mic.cfg_reg + MIC_ISAC;
cs->hw.mic.hscx = cs->hw.mic.cfg_reg + MIC_HSCX;
if (!request_region(cs->hw.mic.cfg_reg, bytecnt, "mic isdn")) {
printk(KERN_WARNING
"HiSax: ith mic config port %x-%x already in use\n",
cs->hw.mic.cfg_reg,
cs->hw.mic.cfg_reg + bytecnt);
return (0);
}
printk(KERN_INFO "mic: defined at 0x%x IRQ %d\n",
cs->hw.mic.cfg_reg, cs->irq);
setup_isac(cs);
cs->readisac = &ReadISAC;
cs->writeisac = &WriteISAC;
cs->readisacfifo = &ReadISACfifo;
cs->writeisacfifo = &WriteISACfifo;
cs->BC_Read_Reg = &ReadHSCX;
cs->BC_Write_Reg = &WriteHSCX;
cs->BC_Send_Data = &hscx_fill_fifo;
cs->cardmsg = &mic_card_msg;
cs->irq_func = &mic_interrupt;
ISACVersion(cs, "mic:");
if (HscxVersion(cs, "mic:")) {
printk(KERN_WARNING
"mic: wrong HSCX versions check IO address\n");
release_io_mic(cs);
return (0);
}
return (1);
}
