static __inline__ void tx_add_log(struct happy_meal *hp, unsigned int a, unsigned int s)
{
struct hme_tx_logent *tlp;
unsigned long flags;
local_irq_save(flags);
tlp = &tx_log[txlog_cur_entry];
tlp->tstamp = (unsigned int)jiffies;
tlp->tx_new = hp->tx_new;
tlp->tx_old = hp->tx_old;
tlp->action = a;
tlp->status = s;
txlog_cur_entry = (txlog_cur_entry + 1) & (TX_LOG_LEN - 1);
local_irq_restore(flags);
}
static __inline__ void tx_dump_log(void)
{
int i, this;
this = txlog_cur_entry;
for (i = 0; i < TX_LOG_LEN; i++) {
printk("TXLOG[%d]: j[%08x] tx[N(%d)O(%d)] action[%08x] stat[%08x]\n", i,
tx_log[this].tstamp,
tx_log[this].tx_new, tx_log[this].tx_old,
tx_log[this].action, tx_log[this].status);
this = (this + 1) & (TX_LOG_LEN - 1);
}
}
static __inline__ void tx_dump_ring(struct happy_meal *hp)
{
struct hmeal_init_block *hb = hp->happy_block;
struct happy_meal_txd *tp = &hb->happy_meal_txd[0];
int i;
for (i = 0; i < TX_RING_SIZE; i+=4) {
printk("TXD[%d..%d]: [%08x:%08x] [%08x:%08x] [%08x:%08x] [%08x:%08x]\n",
i, i + 4,
le32_to_cpu(tp[i].tx_flags), le32_to_cpu(tp[i].tx_addr),
le32_to_cpu(tp[i + 1].tx_flags), le32_to_cpu(tp[i + 1].tx_addr),
le32_to_cpu(tp[i + 2].tx_flags), le32_to_cpu(tp[i + 2].tx_addr),
le32_to_cpu(tp[i + 3].tx_flags), le32_to_cpu(tp[i + 3].tx_addr));
}
}
static void sbus_hme_write32(void __iomem *reg, u32 val)
{
sbus_writel(val, reg);
}
static u32 sbus_hme_read32(void __iomem *reg)
{
return sbus_readl(reg);
}
static void sbus_hme_write_rxd(struct happy_meal_rxd *rxd, u32 flags, u32 addr)
{
rxd->rx_addr = (__force hme32)addr;
wmb();
rxd->rx_flags = (__force hme32)flags;
}
static void sbus_hme_write_txd(struct happy_meal_txd *txd, u32 flags, u32 addr)
{
txd->tx_addr = (__force hme32)addr;
wmb();
txd->tx_flags = (__force hme32)flags;
}
static u32 sbus_hme_read_desc32(hme32 *p)
{
return (__force u32)*p;
}
static void pci_hme_write32(void __iomem *reg, u32 val)
{
writel(val, reg);
}
static u32 pci_hme_read32(void __iomem *reg)
{
return readl(reg);
}
static void pci_hme_write_rxd(struct happy_meal_rxd *rxd, u32 flags, u32 addr)
{
rxd->rx_addr = (__force hme32)cpu_to_le32(addr);
wmb();
rxd->rx_flags = (__force hme32)cpu_to_le32(flags);
}
static void pci_hme_write_txd(struct happy_meal_txd *txd, u32 flags, u32 addr)
{
txd->tx_addr = (__force hme32)cpu_to_le32(addr);
wmb();
txd->tx_flags = (__force hme32)cpu_to_le32(flags);
}
static u32 pci_hme_read_desc32(hme32 *p)
{
return le32_to_cpup((__le32 *)p);
}
static inline u32 hme_read_desc32(struct happy_meal *hp, hme32 *p)
{
return le32_to_cpup((__le32 *)p);
}
static void BB_PUT_BIT(struct happy_meal *hp, void __iomem *tregs, int bit)
{
hme_write32(hp, tregs + TCVR_BBDATA, bit);
hme_write32(hp, tregs + TCVR_BBCLOCK, 0);
hme_write32(hp, tregs + TCVR_BBCLOCK, 1);
}
static u32 BB_GET_BIT2(struct happy_meal *hp, void __iomem *tregs, int internal)
{
u32 retval;
hme_write32(hp, tregs + TCVR_BBCLOCK, 0);
udelay(1);
retval = hme_read32(hp, tregs + TCVR_CFG);
if (internal)
retval &= TCV_CFG_MDIO0;
else
retval &= TCV_CFG_MDIO1;
hme_write32(hp, tregs + TCVR_BBCLOCK, 1);
return retval;
}
static int happy_meal_bb_read(struct happy_meal *hp,
void __iomem *tregs, int reg)
{
u32 tmp;
int retval = 0;
int i;
ASD(("happy_meal_bb_read: reg=%d ", reg));
hme_write32(hp, tregs + TCVR_BBOENAB, 1);
for (i = 0; i < 32; i++)
BB_PUT_BIT(hp, tregs, 1);
BB_PUT_BIT(hp, tregs, 0);
BB_PUT_BIT(hp, tregs, 1);
BB_PUT_BIT(hp, tregs, 1);
BB_PUT_BIT(hp, tregs, 0);
tmp = hp->paddr & 0xff;
for (i = 4; i >= 0; i--)
BB_PUT_BIT(hp, tregs, ((tmp >> i) & 1));
tmp = (reg & 0xff);
for (i = 4; i >= 0; i--)
BB_PUT_BIT(hp, tregs, ((tmp >> i) & 1));
hme_write32(hp, tregs + TCVR_BBOENAB, 0);
(void) BB_GET_BIT2(hp, tregs, (hp->tcvr_type == internal));
for (i = 15; i >= 0; i--)
retval |= BB_GET_BIT2(hp, tregs, (hp->tcvr_type == internal));
(void) BB_GET_BIT2(hp, tregs, (hp->tcvr_type == internal));
(void) BB_GET_BIT2(hp, tregs, (hp->tcvr_type == internal));
(void) BB_GET_BIT2(hp, tregs, (hp->tcvr_type == internal));
ASD(("value=%x\n", retval));
return retval;
}
static void happy_meal_bb_write(struct happy_meal *hp,
void __iomem *tregs, int reg,
unsigned short value)
{
u32 tmp;
int i;
ASD(("happy_meal_bb_write: reg=%d value=%x\n", reg, value));
hme_write32(hp, tregs + TCVR_BBOENAB, 1);
for (i = 0; i < 32; i++)
BB_PUT_BIT(hp, tregs, 1);
BB_PUT_BIT(hp, tregs, 0);
BB_PUT_BIT(hp, tregs, 1);
BB_PUT_BIT(hp, tregs, 0);
BB_PUT_BIT(hp, tregs, 1);
tmp = (hp->paddr & 0xff);
for (i = 4; i >= 0; i--)
BB_PUT_BIT(hp, tregs, ((tmp >> i) & 1));
tmp = (reg & 0xff);
for (i = 4; i >= 0; i--)
BB_PUT_BIT(hp, tregs, ((tmp >> i) & 1));
BB_PUT_BIT(hp, tregs, 1);
BB_PUT_BIT(hp, tregs, 0);
for (i = 15; i >= 0; i--)
BB_PUT_BIT(hp, tregs, ((value >> i) & 1));
hme_write32(hp, tregs + TCVR_BBOENAB, 0);
}
static int happy_meal_tcvr_read(struct happy_meal *hp,
void __iomem *tregs, int reg)
{
int tries = TCVR_READ_TRIES;
int retval;
ASD(("happy_meal_tcvr_read: reg=0x%02x ", reg));
if (hp->tcvr_type == none) {
ASD(("no transceiver, value=TCVR_FAILURE\n"));
return TCVR_FAILURE;
}
if (!(hp->happy_flags & HFLAG_FENABLE)) {
ASD(("doing bit bang\n"));
return happy_meal_bb_read(hp, tregs, reg);
}
hme_write32(hp, tregs + TCVR_FRAME,
(FRAME_READ | (hp->paddr << 23) | ((reg & 0xff) << 18)));
while (!(hme_read32(hp, tregs + TCVR_FRAME) & 0x10000) && --tries)
udelay(20);
if (!tries) {
printk(KERN_ERR "happy meal: Aieee, transceiver MIF read bolixed\n");
return TCVR_FAILURE;
}
retval = hme_read32(hp, tregs + TCVR_FRAME) & 0xffff;
ASD(("value=%04x\n", retval));
return retval;
}
static void happy_meal_tcvr_write(struct happy_meal *hp,
void __iomem *tregs, int reg,
unsigned short value)
{
int tries = TCVR_WRITE_TRIES;
ASD(("happy_meal_tcvr_write: reg=0x%02x value=%04x\n", reg, value));
if (!(hp->happy_flags & HFLAG_FENABLE)) {
happy_meal_bb_write(hp, tregs, reg, value);
return;
}
hme_write32(hp, tregs + TCVR_FRAME,
(FRAME_WRITE | (hp->paddr << 23) |
((reg & 0xff) << 18) | (value & 0xffff)));
while (!(hme_read32(hp, tregs + TCVR_FRAME) & 0x10000) && --tries)
udelay(20);
if (!tries)
printk(KERN_ERR "happy meal: Aieee, transceiver MIF write bolixed\n");
}
static int try_next_permutation(struct happy_meal *hp, void __iomem *tregs)
{
hp->sw_bmcr = happy_meal_tcvr_read(hp, tregs, MII_BMCR);
if (hp->sw_bmcr & BMCR_FULLDPLX) {
hp->sw_bmcr &= ~(BMCR_FULLDPLX);
happy_meal_tcvr_write(hp, tregs, MII_BMCR, hp->sw_bmcr);
return 0;
}
if (hp->sw_bmcr & BMCR_SPEED100) {
hp->sw_bmcr &= ~(BMCR_SPEED100);
happy_meal_tcvr_write(hp, tregs, MII_BMCR, hp->sw_bmcr);
return 0;
}
return -1;
}
static void display_link_mode(struct happy_meal *hp, void __iomem *tregs)
{
printk(KERN_INFO "%s: Link is up using ", hp->dev->name);
if (hp->tcvr_type == external)
printk("external ");
else
printk("internal ");
printk("transceiver at ");
hp->sw_lpa = happy_meal_tcvr_read(hp, tregs, MII_LPA);
if (hp->sw_lpa & (LPA_100HALF | LPA_100FULL)) {
if (hp->sw_lpa & LPA_100FULL)
printk("100Mb/s, Full Duplex.\n");
else
printk("100Mb/s, Half Duplex.\n");
} else {
if (hp->sw_lpa & LPA_10FULL)
printk("10Mb/s, Full Duplex.\n");
else
printk("10Mb/s, Half Duplex.\n");
}
}
static void display_forced_link_mode(struct happy_meal *hp, void __iomem *tregs)
{
printk(KERN_INFO "%s: Link has been forced up using ", hp->dev->name);
if (hp->tcvr_type == external)
printk("external ");
else
printk("internal ");
printk("transceiver at ");
hp->sw_bmcr = happy_meal_tcvr_read(hp, tregs, MII_BMCR);
if (hp->sw_bmcr & BMCR_SPEED100)
printk("100Mb/s, ");
else
printk("10Mb/s, ");
if (hp->sw_bmcr & BMCR_FULLDPLX)
printk("Full Duplex.\n");
else
printk("Half Duplex.\n");
}
static int set_happy_link_modes(struct happy_meal *hp, void __iomem *tregs)
{
int full;
if (hp->timer_state == arbwait) {
hp->sw_lpa = happy_meal_tcvr_read(hp, tregs, MII_LPA);
if (!(hp->sw_lpa & (LPA_10HALF | LPA_10FULL | LPA_100HALF | LPA_100FULL)))
goto no_response;
if (hp->sw_lpa & LPA_100FULL)
full = 1;
else if (hp->sw_lpa & LPA_100HALF)
full = 0;
else if (hp->sw_lpa & LPA_10FULL)
full = 1;
else
full = 0;
} else {
hp->sw_bmcr = happy_meal_tcvr_read(hp, tregs, MII_BMCR);
if (hp->sw_bmcr & BMCR_FULLDPLX)
full = 1;
else
full = 0;
}
hme_write32(hp, hp->bigmacregs + BMAC_TXCFG,
hme_read32(hp, hp->bigmacregs + BMAC_TXCFG) &
~(BIGMAC_TXCFG_ENABLE));
while (hme_read32(hp, hp->bigmacregs + BMAC_TXCFG) & BIGMAC_TXCFG_ENABLE)
barrier();
if (full) {
hp->happy_flags |= HFLAG_FULL;
hme_write32(hp, hp->bigmacregs + BMAC_TXCFG,
hme_read32(hp, hp->bigmacregs + BMAC_TXCFG) |
BIGMAC_TXCFG_FULLDPLX);
} else {
hp->happy_flags &= ~(HFLAG_FULL);
hme_write32(hp, hp->bigmacregs + BMAC_TXCFG,
hme_read32(hp, hp->bigmacregs + BMAC_TXCFG) &
~(BIGMAC_TXCFG_FULLDPLX));
}
hme_write32(hp, hp->bigmacregs + BMAC_TXCFG,
hme_read32(hp, hp->bigmacregs + BMAC_TXCFG) |
BIGMAC_TXCFG_ENABLE);
return 0;
no_response:
return 1;
}
static int is_lucent_phy(struct happy_meal *hp)
{
void __iomem *tregs = hp->tcvregs;
unsigned short mr2, mr3;
int ret = 0;
mr2 = happy_meal_tcvr_read(hp, tregs, 2);
mr3 = happy_meal_tcvr_read(hp, tregs, 3);
if ((mr2 & 0xffff) == 0x0180 &&
((mr3 & 0xffff) >> 10) == 0x1d)
ret = 1;
return ret;
}
static void happy_meal_timer(unsigned long data)
{
struct happy_meal *hp = (struct happy_meal *) data;
void __iomem *tregs = hp->tcvregs;
int restart_timer = 0;
spin_lock_irq(&hp->happy_lock);
hp->timer_ticks++;
switch(hp->timer_state) {
case arbwait:
if (hp->timer_ticks >= 10) {
do_force_mode:
hp->sw_bmcr = happy_meal_tcvr_read(hp, tregs, MII_BMCR);
printk(KERN_NOTICE "%s: Auto-Negotiation unsuccessful, trying force link mode\n",
hp->dev->name);
hp->sw_bmcr = BMCR_SPEED100;
happy_meal_tcvr_write(hp, tregs, MII_BMCR, hp->sw_bmcr);
if (!is_lucent_phy(hp)) {
hp->sw_csconfig = happy_meal_tcvr_read(hp, tregs, DP83840_CSCONFIG);
hp->sw_csconfig &= ~(CSCONFIG_TCVDISAB);
happy_meal_tcvr_write(hp, tregs, DP83840_CSCONFIG, hp->sw_csconfig);
}
hp->timer_state = ltrywait;
hp->timer_ticks = 0;
restart_timer = 1;
} else {
hp->sw_bmsr = happy_meal_tcvr_read(hp, tregs, MII_BMSR);
if (hp->sw_bmsr & BMSR_ANEGCOMPLETE) {
int ret;
ret = set_happy_link_modes(hp, tregs);
if (ret) {
goto do_force_mode;
}
hp->timer_state = lupwait;
restart_timer = 1;
} else {
restart_timer = 1;
}
}
break;
case lupwait:
hp->sw_bmsr = happy_meal_tcvr_read(hp, tregs, MII_BMSR);
if (hp->sw_bmsr & BMSR_LSTATUS) {
display_link_mode(hp, tregs);
hp->timer_state = asleep;
restart_timer = 0;
} else {
if (hp->timer_ticks >= 10) {
printk(KERN_NOTICE "%s: Auto negotiation successful, link still "
"not completely up.\n", hp->dev->name);
hp->timer_ticks = 0;
restart_timer = 1;
} else {
restart_timer = 1;
}
}
break;
case ltrywait:
hp->sw_bmsr = happy_meal_tcvr_read(hp, tregs, MII_BMSR);
hp->sw_csconfig = happy_meal_tcvr_read(hp, tregs, DP83840_CSCONFIG);
if (hp->timer_ticks == 1) {
if (!is_lucent_phy(hp)) {
hp->sw_csconfig |= CSCONFIG_TCVDISAB;
happy_meal_tcvr_write(hp, tregs,
DP83840_CSCONFIG, hp->sw_csconfig);
}
restart_timer = 1;
break;
}
if (hp->timer_ticks == 2) {
if (!is_lucent_phy(hp)) {
hp->sw_csconfig &= ~(CSCONFIG_TCVDISAB);
happy_meal_tcvr_write(hp, tregs,
DP83840_CSCONFIG, hp->sw_csconfig);
}
restart_timer = 1;
break;
}
if (hp->sw_bmsr & BMSR_LSTATUS) {
display_forced_link_mode(hp, tregs);
set_happy_link_modes(hp, tregs);
hp->timer_state = asleep;
restart_timer = 0;
} else {
if (hp->timer_ticks >= 4) {
int ret;
ret = try_next_permutation(hp, tregs);
if (ret == -1) {
printk(KERN_NOTICE "%s: Link down, cable problem?\n",
hp->dev->name);
ret = happy_meal_init(hp);
if (ret) {
printk(KERN_ERR "%s: Error, cannot re-init the "
"Happy Meal.\n", hp->dev->name);
}
goto out;
}
if (!is_lucent_phy(hp)) {
hp->sw_csconfig = happy_meal_tcvr_read(hp, tregs,
DP83840_CSCONFIG);
hp->sw_csconfig |= CSCONFIG_TCVDISAB;
happy_meal_tcvr_write(hp, tregs,
DP83840_CSCONFIG, hp->sw_csconfig);
}
hp->timer_ticks = 0;
restart_timer = 1;
} else {
restart_timer = 1;
}
}
break;
case asleep:
default:
printk(KERN_ERR "%s: Aieee, link timer is asleep but we got one anyways!\n",
hp->dev->name);
restart_timer = 0;
hp->timer_ticks = 0;
hp->timer_state = asleep;
break;
}
if (restart_timer) {
hp->happy_timer.expires = jiffies + ((12 * HZ)/10);
add_timer(&hp->happy_timer);
}
out:
spin_unlock_irq(&hp->happy_lock);
}
static void happy_meal_tx_reset(struct happy_meal *hp, void __iomem *bregs)
{
int tries = TX_RESET_TRIES;
HMD(("happy_meal_tx_reset: reset, "));
hme_write32(hp, bregs + BMAC_TXSWRESET, 0);
while ((hme_read32(hp, bregs + BMAC_TXSWRESET) & 1) && --tries)
udelay(20);
if (!tries)
printk(KERN_ERR "happy meal: Transceiver BigMac ATTACK!");
HMD(("done\n"));
}
static void happy_meal_rx_reset(struct happy_meal *hp, void __iomem *bregs)
{
int tries = RX_RESET_TRIES;
HMD(("happy_meal_rx_reset: reset, "));
hme_write32(hp, bregs + BMAC_RXSWRESET, 0);
while ((hme_read32(hp, bregs + BMAC_RXSWRESET) & 1) && --tries)
udelay(20);
if (!tries)
printk(KERN_ERR "happy meal: Receiver BigMac ATTACK!");
HMD(("done\n"));
}
static void happy_meal_stop(struct happy_meal *hp, void __iomem *gregs)
{
int tries = STOP_TRIES;
HMD(("happy_meal_stop: reset, "));
hme_write32(hp, gregs + GREG_SWRESET, GREG_RESET_ALL);
while (hme_read32(hp, gregs + GREG_SWRESET) && --tries)
udelay(20);
if (!tries)
printk(KERN_ERR "happy meal: Fry guys.");
HMD(("done\n"));
}
static void happy_meal_get_counters(struct happy_meal *hp, void __iomem *bregs)
{
struct net_device_stats *stats = &hp->net_stats;
stats->rx_crc_errors += hme_read32(hp, bregs + BMAC_RCRCECTR);
hme_write32(hp, bregs + BMAC_RCRCECTR, 0);
stats->rx_frame_errors += hme_read32(hp, bregs + BMAC_UNALECTR);
hme_write32(hp, bregs + BMAC_UNALECTR, 0);
stats->rx_length_errors += hme_read32(hp, bregs + BMAC_GLECTR);
hme_write32(hp, bregs + BMAC_GLECTR, 0);
stats->tx_aborted_errors += hme_read32(hp, bregs + BMAC_EXCTR);
stats->collisions +=
(hme_read32(hp, bregs + BMAC_EXCTR) +
hme_read32(hp, bregs + BMAC_LTCTR));
hme_write32(hp, bregs + BMAC_EXCTR, 0);
hme_write32(hp, bregs + BMAC_LTCTR, 0);
}
static void happy_meal_poll_stop(struct happy_meal *hp, void __iomem *tregs)
{
ASD(("happy_meal_poll_stop: "));
if ((hp->happy_flags & (HFLAG_POLLENABLE | HFLAG_POLL)) !=
(HFLAG_POLLENABLE | HFLAG_POLL)) {
HMD(("not polling, return\n"));
return;
}
ASD(("were polling, mif ints off, "));
hme_write32(hp, tregs + TCVR_IMASK, 0xffff);
ASD(("polling off, "));
hme_write32(hp, tregs + TCVR_CFG,
hme_read32(hp, tregs + TCVR_CFG) & ~(TCV_CFG_PENABLE));
hp->happy_flags &= ~(HFLAG_POLL);
udelay(200);
ASD(("done\n"));
}
static int happy_meal_tcvr_reset(struct happy_meal *hp, void __iomem *tregs)
{
u32 tconfig;
int result, tries = TCVR_RESET_TRIES;
tconfig = hme_read32(hp, tregs + TCVR_CFG);
ASD(("happy_meal_tcvr_reset: tcfg<%08lx> ", tconfig));
if (hp->tcvr_type == external) {
ASD(("external<"));
hme_write32(hp, tregs + TCVR_CFG, tconfig & ~(TCV_CFG_PSELECT));
hp->tcvr_type = internal;
hp->paddr = TCV_PADDR_ITX;
ASD(("ISOLATE,"));
happy_meal_tcvr_write(hp, tregs, MII_BMCR,
(BMCR_LOOPBACK|BMCR_PDOWN|BMCR_ISOLATE));
result = happy_meal_tcvr_read(hp, tregs, MII_BMCR);
if (result == TCVR_FAILURE) {
ASD(("phyread_fail>\n"));
return -1;
}
ASD(("phyread_ok,PSELECT>"));
hme_write32(hp, tregs + TCVR_CFG, tconfig | TCV_CFG_PSELECT);
hp->tcvr_type = external;
hp->paddr = TCV_PADDR_ETX;
} else {
if (tconfig & TCV_CFG_MDIO1) {
ASD(("internal<PSELECT,"));
hme_write32(hp, tregs + TCVR_CFG, (tconfig | TCV_CFG_PSELECT));
ASD(("ISOLATE,"));
happy_meal_tcvr_write(hp, tregs, MII_BMCR,
(BMCR_LOOPBACK|BMCR_PDOWN|BMCR_ISOLATE));
result = happy_meal_tcvr_read(hp, tregs, MII_BMCR);
if (result == TCVR_FAILURE) {
ASD(("phyread_fail>\n"));
return -1;
}
ASD(("phyread_ok,~PSELECT>"));
hme_write32(hp, tregs + TCVR_CFG, (tconfig & ~(TCV_CFG_PSELECT)));
hp->tcvr_type = internal;
hp->paddr = TCV_PADDR_ITX;
}
}
ASD(("BMCR_RESET "));
happy_meal_tcvr_write(hp, tregs, MII_BMCR, BMCR_RESET);
while (--tries) {
result = happy_meal_tcvr_read(hp, tregs, MII_BMCR);
if (result == TCVR_FAILURE)
return -1;
hp->sw_bmcr = result;
if (!(result & BMCR_RESET))
break;
udelay(20);
}
if (!tries) {
ASD(("BMCR RESET FAILED!\n"));
return -1;
}
ASD(("RESET_OK\n"));
hp->sw_bmsr = happy_meal_tcvr_read(hp, tregs, MII_BMSR);
hp->sw_physid1 = happy_meal_tcvr_read(hp, tregs, MII_PHYSID1);
hp->sw_physid2 = happy_meal_tcvr_read(hp, tregs, MII_PHYSID2);
hp->sw_advertise = happy_meal_tcvr_read(hp, tregs, MII_ADVERTISE);
ASD(("UNISOLATE"));
hp->sw_bmcr &= ~(BMCR_ISOLATE);
happy_meal_tcvr_write(hp, tregs, MII_BMCR, hp->sw_bmcr);
tries = TCVR_UNISOLATE_TRIES;
while (--tries) {
result = happy_meal_tcvr_read(hp, tregs, MII_BMCR);
if (result == TCVR_FAILURE)
return -1;
if (!(result & BMCR_ISOLATE))
break;
udelay(20);
}
if (!tries) {
ASD((" FAILED!\n"));
return -1;
}
ASD((" SUCCESS and CSCONFIG_DFBYPASS\n"));
if (!is_lucent_phy(hp)) {
result = happy_meal_tcvr_read(hp, tregs,
DP83840_CSCONFIG);
happy_meal_tcvr_write(hp, tregs,
DP83840_CSCONFIG, (result | CSCONFIG_DFBYPASS));
}
return 0;
}
static void happy_meal_transceiver_check(struct happy_meal *hp, void __iomem *tregs)
{
unsigned long tconfig = hme_read32(hp, tregs + TCVR_CFG);
ASD(("happy_meal_transceiver_check: tcfg=%08lx ", tconfig));
if (hp->happy_flags & HFLAG_POLL) {
ASD(("<polling> "));
if (hp->tcvr_type == internal) {
if (tconfig & TCV_CFG_MDIO1) {
ASD(("<internal> <poll stop> "));
happy_meal_poll_stop(hp, tregs);
hp->paddr = TCV_PADDR_ETX;
hp->tcvr_type = external;
ASD(("<external>\n"));
tconfig &= ~(TCV_CFG_PENABLE);
tconfig |= TCV_CFG_PSELECT;
hme_write32(hp, tregs + TCVR_CFG, tconfig);
}
} else {
if (hp->tcvr_type == external) {
ASD(("<external> "));
if (!(hme_read32(hp, tregs + TCVR_STATUS) >> 16)) {
ASD(("<poll stop> "));
happy_meal_poll_stop(hp, tregs);
hp->paddr = TCV_PADDR_ITX;
hp->tcvr_type = internal;
ASD(("<internal>\n"));
hme_write32(hp, tregs + TCVR_CFG,
hme_read32(hp, tregs + TCVR_CFG) &
~(TCV_CFG_PSELECT));
}
ASD(("\n"));
} else {
ASD(("<none>\n"));
}
}
} else {
u32 reread = hme_read32(hp, tregs + TCVR_CFG);
ASD(("<not polling> "));
if (reread & TCV_CFG_MDIO1) {
hme_write32(hp, tregs + TCVR_CFG, tconfig | TCV_CFG_PSELECT);
hp->paddr = TCV_PADDR_ETX;
hp->tcvr_type = external;
ASD(("<external>\n"));
} else {
if (reread & TCV_CFG_MDIO0) {
hme_write32(hp, tregs + TCVR_CFG,
tconfig & ~(TCV_CFG_PSELECT));
hp->paddr = TCV_PADDR_ITX;
hp->tcvr_type = internal;
ASD(("<internal>\n"));
} else {
printk(KERN_ERR "happy meal: Transceiver and a coke please.");
hp->tcvr_type = none;
ASD(("<none>\n"));
}
}
}
}
static void happy_meal_clean_rings(struct happy_meal *hp)
{
int i;
for (i = 0; i < RX_RING_SIZE; i++) {
if (hp->rx_skbs[i] != NULL) {
struct sk_buff *skb = hp->rx_skbs[i];
struct happy_meal_rxd *rxd;
u32 dma_addr;
rxd = &hp->happy_block->happy_meal_rxd[i];
dma_addr = hme_read_desc32(hp, &rxd->rx_addr);
dma_unmap_single(hp->dma_dev, dma_addr,
RX_BUF_ALLOC_SIZE, DMA_FROM_DEVICE);
dev_kfree_skb_any(skb);
hp->rx_skbs[i] = NULL;
}
}
for (i = 0; i < TX_RING_SIZE; i++) {
if (hp->tx_skbs[i] != NULL) {
struct sk_buff *skb = hp->tx_skbs[i];
struct happy_meal_txd *txd;
u32 dma_addr;
int frag;
hp->tx_skbs[i] = NULL;
for (frag = 0; frag <= skb_shinfo(skb)->nr_frags; frag++) {
txd = &hp->happy_block->happy_meal_txd[i];
dma_addr = hme_read_desc32(hp, &txd->tx_addr);
if (!frag)
dma_unmap_single(hp->dma_dev, dma_addr,
(hme_read_desc32(hp, &txd->tx_flags)
& TXFLAG_SIZE),
DMA_TO_DEVICE);
else
dma_unmap_page(hp->dma_dev, dma_addr,
(hme_read_desc32(hp, &txd->tx_flags)
& TXFLAG_SIZE),
DMA_TO_DEVICE);
if (frag != skb_shinfo(skb)->nr_frags)
i++;
}
dev_kfree_skb_any(skb);
}
}
}
static void happy_meal_init_rings(struct happy_meal *hp)
{
struct hmeal_init_block *hb = hp->happy_block;
int i;
HMD(("happy_meal_init_rings: counters to zero, "));
hp->rx_new = hp->rx_old = hp->tx_new = hp->tx_old = 0;
HMD(("clean, "));
happy_meal_clean_rings(hp);
HMD(("init rxring, "));
for (i = 0; i < RX_RING_SIZE; i++) {
struct sk_buff *skb;
skb = happy_meal_alloc_skb(RX_BUF_ALLOC_SIZE, GFP_ATOMIC);
if (!skb) {
hme_write_rxd(hp, &hb->happy_meal_rxd[i], 0, 0);
continue;
}
hp->rx_skbs[i] = skb;
skb_put(skb, (ETH_FRAME_LEN + RX_OFFSET + 4));
hme_write_rxd(hp, &hb->happy_meal_rxd[i],
(RXFLAG_OWN | ((RX_BUF_ALLOC_SIZE - RX_OFFSET) << 16)),
dma_map_single(hp->dma_dev, skb->data, RX_BUF_ALLOC_SIZE,
DMA_FROM_DEVICE));
skb_reserve(skb, RX_OFFSET);
}
HMD(("init txring, "));
for (i = 0; i < TX_RING_SIZE; i++)
hme_write_txd(hp, &hb->happy_meal_txd[i], 0, 0);
HMD(("done\n"));
}
static void happy_meal_begin_auto_negotiation(struct happy_meal *hp,
void __iomem *tregs,
struct ethtool_cmd *ep)
{
int timeout;
hp->sw_bmsr = happy_meal_tcvr_read(hp, tregs, MII_BMSR);
hp->sw_bmcr = happy_meal_tcvr_read(hp, tregs, MII_BMCR);
hp->sw_physid1 = happy_meal_tcvr_read(hp, tregs, MII_PHYSID1);
hp->sw_physid2 = happy_meal_tcvr_read(hp, tregs, MII_PHYSID2);
hp->sw_advertise = happy_meal_tcvr_read(hp, tregs, MII_ADVERTISE);
if (ep == NULL || ep->autoneg == AUTONEG_ENABLE) {
if (hp->sw_bmsr & BMSR_10HALF)
hp->sw_advertise |= (ADVERTISE_10HALF);
else
hp->sw_advertise &= ~(ADVERTISE_10HALF);
if (hp->sw_bmsr & BMSR_10FULL)
hp->sw_advertise |= (ADVERTISE_10FULL);
else
hp->sw_advertise &= ~(ADVERTISE_10FULL);
if (hp->sw_bmsr & BMSR_100HALF)
hp->sw_advertise |= (ADVERTISE_100HALF);
else
hp->sw_advertise &= ~(ADVERTISE_100HALF);
if (hp->sw_bmsr & BMSR_100FULL)
hp->sw_advertise |= (ADVERTISE_100FULL);
else
hp->sw_advertise &= ~(ADVERTISE_100FULL);
happy_meal_tcvr_write(hp, tregs, MII_ADVERTISE, hp->sw_advertise);
#ifdef AUTO_SWITCH_DEBUG
ASD(("%s: Advertising [ ", hp->dev->name));
if (hp->sw_advertise & ADVERTISE_10HALF)
ASD(("10H "));
if (hp->sw_advertise & ADVERTISE_10FULL)
ASD(("10F "));
if (hp->sw_advertise & ADVERTISE_100HALF)
ASD(("100H "));
if (hp->sw_advertise & ADVERTISE_100FULL)
ASD(("100F "));
#endif
hp->sw_bmcr |= BMCR_ANENABLE;
happy_meal_tcvr_write(hp, tregs, MII_BMCR, hp->sw_bmcr);
hp->sw_bmcr |= BMCR_ANRESTART;
happy_meal_tcvr_write(hp, tregs, MII_BMCR, hp->sw_bmcr);
timeout = 64;
while (--timeout) {
hp->sw_bmcr = happy_meal_tcvr_read(hp, tregs, MII_BMCR);
if (!(hp->sw_bmcr & BMCR_ANRESTART))
break;
udelay(10);
}
if (!timeout) {
printk(KERN_ERR "%s: Happy Meal would not start auto negotiation "
"BMCR=0x%04x\n", hp->dev->name, hp->sw_bmcr);
printk(KERN_NOTICE "%s: Performing force link detection.\n",
hp->dev->name);
goto force_link;
} else {
hp->timer_state = arbwait;
}
} else {
force_link:
if (ep == NULL || ep->autoneg == AUTONEG_ENABLE) {
hp->sw_bmcr = BMCR_SPEED100;
} else {
if (ethtool_cmd_speed(ep) == SPEED_100)
hp->sw_bmcr = BMCR_SPEED100;
else
hp->sw_bmcr = 0;
if (ep->duplex == DUPLEX_FULL)
hp->sw_bmcr |= BMCR_FULLDPLX;
}
happy_meal_tcvr_write(hp, tregs, MII_BMCR, hp->sw_bmcr);
if (!is_lucent_phy(hp)) {
hp->sw_csconfig = happy_meal_tcvr_read(hp, tregs,
DP83840_CSCONFIG);
hp->sw_csconfig &= ~(CSCONFIG_TCVDISAB);
happy_meal_tcvr_write(hp, tregs, DP83840_CSCONFIG,
hp->sw_csconfig);
}
hp->timer_state = ltrywait;
}
hp->timer_ticks = 0;
hp->happy_timer.expires = jiffies + (12 * HZ)/10;
hp->happy_timer.data = (unsigned long) hp;
hp->happy_timer.function = happy_meal_timer;
add_timer(&hp->happy_timer);
}
static int happy_meal_init(struct happy_meal *hp)
{
void __iomem *gregs = hp->gregs;
void __iomem *etxregs = hp->etxregs;
void __iomem *erxregs = hp->erxregs;
void __iomem *bregs = hp->bigmacregs;
void __iomem *tregs = hp->tcvregs;
u32 regtmp, rxcfg;
unsigned char *e = &hp->dev->dev_addr[0];
del_timer(&hp->happy_timer);
HMD(("happy_meal_init: happy_flags[%08x] ",
hp->happy_flags));
if (!(hp->happy_flags & HFLAG_INIT)) {
HMD(("set HFLAG_INIT, "));
hp->happy_flags |= HFLAG_INIT;
happy_meal_get_counters(hp, bregs);
}
HMD(("to happy_meal_poll_stop\n"));
happy_meal_poll_stop(hp, tregs);
HMD(("happy_meal_init: to happy_meal_stop\n"));
happy_meal_stop(hp, gregs);
HMD(("happy_meal_init: to happy_meal_init_rings\n"));
happy_meal_init_rings(hp);
HMD(("happy_meal_init: Disable all MIF irqs (old[%08x]), ",
hme_read32(hp, tregs + TCVR_IMASK)));
hme_write32(hp, tregs + TCVR_IMASK, 0xffff);
if (hp->happy_flags & HFLAG_FENABLE) {
HMD(("use frame old[%08x], ",
hme_read32(hp, tregs + TCVR_CFG)));
hme_write32(hp, tregs + TCVR_CFG,
hme_read32(hp, tregs + TCVR_CFG) & ~(TCV_CFG_BENABLE));
} else {
HMD(("use bitbang old[%08x], ",
hme_read32(hp, tregs + TCVR_CFG)));
hme_write32(hp, tregs + TCVR_CFG,
hme_read32(hp, tregs + TCVR_CFG) | TCV_CFG_BENABLE);
}
HMD(("to happy_meal_transceiver_check\n"));
happy_meal_transceiver_check(hp, tregs);
HMD(("happy_meal_init: "));
switch(hp->tcvr_type) {
case none:
HMD(("AAIEEE no transceiver type, EAGAIN"));
return -EAGAIN;
case internal:
HMD(("internal, using MII, "));
hme_write32(hp, bregs + BMAC_XIFCFG, 0);
break;
case external:
HMD(("external, disable MII, "));
hme_write32(hp, bregs + BMAC_XIFCFG, BIGMAC_XCFG_MIIDISAB);
break;
}
if (happy_meal_tcvr_reset(hp, tregs))
return -EAGAIN;
HMD(("tx/rx reset, "));
happy_meal_tx_reset(hp, bregs);
happy_meal_rx_reset(hp, bregs);
HMD(("jsize/ipg1/ipg2, "));
hme_write32(hp, bregs + BMAC_JSIZE, DEFAULT_JAMSIZE);
hme_write32(hp, bregs + BMAC_IGAP1, DEFAULT_IPG1);
hme_write32(hp, bregs + BMAC_IGAP2, DEFAULT_IPG2);
HMD(("rseed/macaddr, "));
hme_write32(hp, bregs + BMAC_RSEED, ((e[5] | e[4]<<8)&0x3ff));
hme_write32(hp, bregs + BMAC_MACADDR2, ((e[4] << 8) | e[5]));
hme_write32(hp, bregs + BMAC_MACADDR1, ((e[2] << 8) | e[3]));
hme_write32(hp, bregs + BMAC_MACADDR0, ((e[0] << 8) | e[1]));
HMD(("htable, "));
if ((hp->dev->flags & IFF_ALLMULTI) ||
(netdev_mc_count(hp->dev) > 64)) {
hme_write32(hp, bregs + BMAC_HTABLE0, 0xffff);
hme_write32(hp, bregs + BMAC_HTABLE1, 0xffff);
hme_write32(hp, bregs + BMAC_HTABLE2, 0xffff);
hme_write32(hp, bregs + BMAC_HTABLE3, 0xffff);
} else if ((hp->dev->flags & IFF_PROMISC) == 0) {
u16 hash_table[4];
struct netdev_hw_addr *ha;
u32 crc;
memset(hash_table, 0, sizeof(hash_table));
netdev_for_each_mc_addr(ha, hp->dev) {
crc = ether_crc_le(6, ha->addr);
crc >>= 26;
hash_table[crc >> 4] |= 1 << (crc & 0xf);
}
hme_write32(hp, bregs + BMAC_HTABLE0, hash_table[0]);
hme_write32(hp, bregs + BMAC_HTABLE1, hash_table[1]);
hme_write32(hp, bregs + BMAC_HTABLE2, hash_table[2]);
hme_write32(hp, bregs + BMAC_HTABLE3, hash_table[3]);
} else {
hme_write32(hp, bregs + BMAC_HTABLE3, 0);
hme_write32(hp, bregs + BMAC_HTABLE2, 0);
hme_write32(hp, bregs + BMAC_HTABLE1, 0);
hme_write32(hp, bregs + BMAC_HTABLE0, 0);
}
HMD(("ring ptrs rxr[%08x] txr[%08x]\n",
((__u32)hp->hblock_dvma + hblock_offset(happy_meal_rxd, 0)),
((__u32)hp->hblock_dvma + hblock_offset(happy_meal_txd, 0))));
hme_write32(hp, erxregs + ERX_RING,
((__u32)hp->hblock_dvma + hblock_offset(happy_meal_rxd, 0)));
hme_write32(hp, etxregs + ETX_RING,
((__u32)hp->hblock_dvma + hblock_offset(happy_meal_txd, 0)));
if (hme_read32(hp, erxregs + ERX_RING) !=
((__u32)hp->hblock_dvma + hblock_offset(happy_meal_rxd, 0)))
hme_write32(hp, erxregs + ERX_RING,
((__u32)hp->hblock_dvma + hblock_offset(happy_meal_rxd, 0))
| 0x4);
HMD(("happy_meal_init: old[%08x] bursts<",
hme_read32(hp, gregs + GREG_CFG)));
#ifndef CONFIG_SPARC
hme_write32(hp, gregs + GREG_CFG, GREG_CFG_BURST64);
#else
if ((hp->happy_bursts & DMA_BURST64) &&
((hp->happy_flags & HFLAG_PCI) != 0
#ifdef CONFIG_SBUS
|| sbus_can_burst64()
#endif
|| 0)) {
u32 gcfg = GREG_CFG_BURST64;
#ifdef CONFIG_SBUS
if ((hp->happy_flags & HFLAG_PCI) == 0) {
struct platform_device *op = hp->happy_dev;
if (sbus_can_dma_64bit()) {
sbus_set_sbus64(&op->dev,
hp->happy_bursts);
gcfg |= GREG_CFG_64BIT;
}
}
#endif
HMD(("64>"));
hme_write32(hp, gregs + GREG_CFG, gcfg);
} else if (hp->happy_bursts & DMA_BURST32) {
HMD(("32>"));
hme_write32(hp, gregs + GREG_CFG, GREG_CFG_BURST32);
} else if (hp->happy_bursts & DMA_BURST16) {
HMD(("16>"));
hme_write32(hp, gregs + GREG_CFG, GREG_CFG_BURST16);
} else {
HMD(("XXX>"));
hme_write32(hp, gregs + GREG_CFG, 0);
}
#endif
HMD((", enable global interrupts, "));
hme_write32(hp, gregs + GREG_IMASK,
(GREG_IMASK_GOTFRAME | GREG_IMASK_RCNTEXP |
GREG_IMASK_SENTFRAME | GREG_IMASK_TXPERR));
HMD(("tx rsize=%d oreg[%08x], ", (int)TX_RING_SIZE,
hme_read32(hp, etxregs + ETX_RSIZE)));
hme_write32(hp, etxregs + ETX_RSIZE, (TX_RING_SIZE >> ETX_RSIZE_SHIFT) - 1);
HMD(("tx dma enable old[%08x], ",
hme_read32(hp, etxregs + ETX_CFG)));
hme_write32(hp, etxregs + ETX_CFG,
hme_read32(hp, etxregs + ETX_CFG) | ETX_CFG_DMAENABLE);
HMD(("erx regs bug old[%08x]\n",
hme_read32(hp, erxregs + ERX_CFG)));
hme_write32(hp, erxregs + ERX_CFG, ERX_CFG_DEFAULT(RX_OFFSET));
regtmp = hme_read32(hp, erxregs + ERX_CFG);
hme_write32(hp, erxregs + ERX_CFG, ERX_CFG_DEFAULT(RX_OFFSET));
if (hme_read32(hp, erxregs + ERX_CFG) != ERX_CFG_DEFAULT(RX_OFFSET)) {
printk(KERN_ERR "happy meal: Eieee, rx config register gets greasy fries.\n");
printk(KERN_ERR "happy meal: Trying to set %08x, reread gives %08x\n",
ERX_CFG_DEFAULT(RX_OFFSET), regtmp);
}
HMD(("happy_meal_init: enable hash rx_cfg_old[%08x], ",
hme_read32(hp, bregs + BMAC_RXCFG)));
rxcfg = BIGMAC_RXCFG_HENABLE | BIGMAC_RXCFG_REJME;
if (hp->dev->flags & IFF_PROMISC)
rxcfg |= BIGMAC_RXCFG_PMISC;
hme_write32(hp, bregs + BMAC_RXCFG, rxcfg);
udelay(10);
HMD(("BIGMAC init, "));
regtmp = 0;
if (hp->happy_flags & HFLAG_FULL)
regtmp |= BIGMAC_TXCFG_FULLDPLX;
hme_write32(hp, bregs + BMAC_TXCFG, regtmp );
hme_write32(hp, bregs + BMAC_ALIMIT, 16);
regtmp = BIGMAC_XCFG_ODENABLE;
if (hp->happy_flags & HFLAG_LANCE)
regtmp |= (DEFAULT_IPG0 << 5) | BIGMAC_XCFG_LANCE;
if (hp->tcvr_type == external)
regtmp |= BIGMAC_XCFG_MIIDISAB;
HMD(("XIF config old[%08x], ",
hme_read32(hp, bregs + BMAC_XIFCFG)));
hme_write32(hp, bregs + BMAC_XIFCFG, regtmp);
HMD(("tx old[%08x] and rx [%08x] ON!\n",
hme_read32(hp, bregs + BMAC_TXCFG),
hme_read32(hp, bregs + BMAC_RXCFG)));
hme_write32(hp, bregs + BMAC_TXMAX, ETH_FRAME_LEN + 8);
hme_write32(hp, bregs + BMAC_RXMAX, ETH_FRAME_LEN + 8);
hme_write32(hp, bregs + BMAC_TXCFG,
hme_read32(hp, bregs + BMAC_TXCFG) | BIGMAC_TXCFG_ENABLE);
hme_write32(hp, bregs + BMAC_RXCFG,
hme_read32(hp, bregs + BMAC_RXCFG) | BIGMAC_RXCFG_ENABLE);
happy_meal_begin_auto_negotiation(hp, tregs, NULL);
return 0;
}
static void happy_meal_set_initial_advertisement(struct happy_meal *hp)
{
void __iomem *tregs = hp->tcvregs;
void __iomem *bregs = hp->bigmacregs;
void __iomem *gregs = hp->gregs;
happy_meal_stop(hp, gregs);
hme_write32(hp, tregs + TCVR_IMASK, 0xffff);
if (hp->happy_flags & HFLAG_FENABLE)
hme_write32(hp, tregs + TCVR_CFG,
hme_read32(hp, tregs + TCVR_CFG) & ~(TCV_CFG_BENABLE));
else
hme_write32(hp, tregs + TCVR_CFG,
hme_read32(hp, tregs + TCVR_CFG) | TCV_CFG_BENABLE);
happy_meal_transceiver_check(hp, tregs);
switch(hp->tcvr_type) {
case none:
return;
case internal:
hme_write32(hp, bregs + BMAC_XIFCFG, 0);
break;
case external:
hme_write32(hp, bregs + BMAC_XIFCFG, BIGMAC_XCFG_MIIDISAB);
break;
}
if (happy_meal_tcvr_reset(hp, tregs))
return;
hp->sw_bmsr = happy_meal_tcvr_read(hp, tregs, MII_BMSR);
hp->sw_advertise = happy_meal_tcvr_read(hp, tregs, MII_ADVERTISE);
if (hp->sw_bmsr & BMSR_10HALF)
hp->sw_advertise |= (ADVERTISE_10HALF);
else
hp->sw_advertise &= ~(ADVERTISE_10HALF);
if (hp->sw_bmsr & BMSR_10FULL)
hp->sw_advertise |= (ADVERTISE_10FULL);
else
hp->sw_advertise &= ~(ADVERTISE_10FULL);
if (hp->sw_bmsr & BMSR_100HALF)
hp->sw_advertise |= (ADVERTISE_100HALF);
else
hp->sw_advertise &= ~(ADVERTISE_100HALF);
if (hp->sw_bmsr & BMSR_100FULL)
hp->sw_advertise |= (ADVERTISE_100FULL);
else
hp->sw_advertise &= ~(ADVERTISE_100FULL);
happy_meal_tcvr_write(hp, tregs, MII_ADVERTISE, hp->sw_advertise);
}
static int happy_meal_is_not_so_happy(struct happy_meal *hp, u32 status)
{
int reset = 0;
if (status & (GREG_STAT_STSTERR | GREG_STAT_TFIFO_UND |
GREG_STAT_MAXPKTERR | GREG_STAT_RXERR |
GREG_STAT_RXPERR | GREG_STAT_RXTERR | GREG_STAT_EOPERR |
GREG_STAT_MIFIRQ | GREG_STAT_TXEACK | GREG_STAT_TXLERR |
GREG_STAT_TXPERR | GREG_STAT_TXTERR | GREG_STAT_SLVERR |
GREG_STAT_SLVPERR))
printk(KERN_ERR "%s: Error interrupt for happy meal, status = %08x\n",
hp->dev->name, status);
if (status & GREG_STAT_RFIFOVF) {
printk(KERN_DEBUG "%s: Happy Meal receive FIFO overflow.\n", hp->dev->name);
}
if (status & GREG_STAT_STSTERR) {
printk(KERN_ERR "%s: Happy Meal BigMAC SQE test failed.\n", hp->dev->name);
reset = 1;
}
if (status & GREG_STAT_TFIFO_UND) {
printk(KERN_ERR "%s: Happy Meal transmitter FIFO underrun, DMA error.\n",
hp->dev->name);
reset = 1;
}
if (status & GREG_STAT_MAXPKTERR) {
printk(KERN_ERR "%s: Happy Meal MAX Packet size error.\n", hp->dev->name);
reset = 1;
}
if (status & GREG_STAT_NORXD) {
printk(KERN_INFO "%s: Happy Meal out of receive "
"descriptors, packet dropped.\n",
hp->dev->name);
}
if (status & (GREG_STAT_RXERR|GREG_STAT_RXPERR|GREG_STAT_RXTERR)) {
printk(KERN_ERR "%s: Happy Meal rx DMA errors [ ", hp->dev->name);
if (status & GREG_STAT_RXERR)
printk("GenericError ");
if (status & GREG_STAT_RXPERR)
printk("ParityError ");
if (status & GREG_STAT_RXTERR)
printk("RxTagBotch ");
printk("]\n");
reset = 1;
}
if (status & GREG_STAT_EOPERR) {
printk(KERN_ERR "%s: EOP not set in happy meal transmit descriptor!\n",
hp->dev->name);
reset = 1;
}
if (status & GREG_STAT_MIFIRQ) {
printk(KERN_ERR "%s: Happy Meal MIF interrupt.\n", hp->dev->name);
}
if (status &
(GREG_STAT_TXEACK|GREG_STAT_TXLERR|GREG_STAT_TXPERR|GREG_STAT_TXTERR)) {
printk(KERN_ERR "%s: Happy Meal tx DMA errors [ ", hp->dev->name);
if (status & GREG_STAT_TXEACK)
printk("GenericError ");
if (status & GREG_STAT_TXLERR)
printk("LateError ");
if (status & GREG_STAT_TXPERR)
printk("ParityErro ");
if (status & GREG_STAT_TXTERR)
printk("TagBotch ");
printk("]\n");
reset = 1;
}
if (status & (GREG_STAT_SLVERR|GREG_STAT_SLVPERR)) {
printk(KERN_ERR "%s: Happy Meal register access SBUS slave (%s) error.\n",
hp->dev->name,
(status & GREG_STAT_SLVPERR) ? "parity" : "generic");
reset = 1;
}
if (reset) {
printk(KERN_NOTICE "%s: Resetting...\n", hp->dev->name);
happy_meal_init(hp);
return 1;
}
return 0;
}
static void happy_meal_mif_interrupt(struct happy_meal *hp)
{
void __iomem *tregs = hp->tcvregs;
printk(KERN_INFO "%s: Link status change.\n", hp->dev->name);
hp->sw_bmcr = happy_meal_tcvr_read(hp, tregs, MII_BMCR);
hp->sw_lpa = happy_meal_tcvr_read(hp, tregs, MII_LPA);
if (hp->sw_lpa & LPA_100FULL) {
printk(KERN_INFO "%s: Switching to 100Mbps at full duplex.", hp->dev->name);
hp->sw_bmcr |= (BMCR_FULLDPLX | BMCR_SPEED100);
} else if (hp->sw_lpa & LPA_100HALF) {
printk(KERN_INFO "%s: Switching to 100MBps at half duplex.", hp->dev->name);
hp->sw_bmcr |= BMCR_SPEED100;
} else if (hp->sw_lpa & LPA_10FULL) {
printk(KERN_INFO "%s: Switching to 10MBps at full duplex.", hp->dev->name);
hp->sw_bmcr |= BMCR_FULLDPLX;
} else {
printk(KERN_INFO "%s: Using 10Mbps at half duplex.", hp->dev->name);
}
happy_meal_tcvr_write(hp, tregs, MII_BMCR, hp->sw_bmcr);
happy_meal_poll_stop(hp, tregs);
}
static void happy_meal_tx(struct happy_meal *hp)
{
struct happy_meal_txd *txbase = &hp->happy_block->happy_meal_txd[0];
struct happy_meal_txd *this;
struct net_device *dev = hp->dev;
int elem;
elem = hp->tx_old;
TXD(("TX<"));
while (elem != hp->tx_new) {
struct sk_buff *skb;
u32 flags, dma_addr, dma_len;
int frag;
TXD(("[%d]", elem));
this = &txbase[elem];
flags = hme_read_desc32(hp, &this->tx_flags);
if (flags & TXFLAG_OWN)
break;
skb = hp->tx_skbs[elem];
if (skb_shinfo(skb)->nr_frags) {
int last;
last = elem + skb_shinfo(skb)->nr_frags;
last &= (TX_RING_SIZE - 1);
flags = hme_read_desc32(hp, &txbase[last].tx_flags);
if (flags & TXFLAG_OWN)
break;
}
hp->tx_skbs[elem] = NULL;
hp->net_stats.tx_bytes += skb->len;
for (frag = 0; frag <= skb_shinfo(skb)->nr_frags; frag++) {
dma_addr = hme_read_desc32(hp, &this->tx_addr);
dma_len = hme_read_desc32(hp, &this->tx_flags);
dma_len &= TXFLAG_SIZE;
if (!frag)
dma_unmap_single(hp->dma_dev, dma_addr, dma_len, DMA_TO_DEVICE);
else
dma_unmap_page(hp->dma_dev, dma_addr, dma_len, DMA_TO_DEVICE);
elem = NEXT_TX(elem);
this = &txbase[elem];
}
dev_kfree_skb_irq(skb);
hp->net_stats.tx_packets++;
}
hp->tx_old = elem;
TXD((">"));
if (netif_queue_stopped(dev) &&
TX_BUFFS_AVAIL(hp) > (MAX_SKB_FRAGS + 1))
netif_wake_queue(dev);
}
static void happy_meal_rx(struct happy_meal *hp, struct net_device *dev)
{
struct happy_meal_rxd *rxbase = &hp->happy_block->happy_meal_rxd[0];
struct happy_meal_rxd *this;
int elem = hp->rx_new, drops = 0;
u32 flags;
RXD(("RX<"));
this = &rxbase[elem];
while (!((flags = hme_read_desc32(hp, &this->rx_flags)) & RXFLAG_OWN)) {
struct sk_buff *skb;
int len = flags >> 16;
u16 csum = flags & RXFLAG_CSUM;
u32 dma_addr = hme_read_desc32(hp, &this->rx_addr);
RXD(("[%d ", elem));
if ((len < ETH_ZLEN) || (flags & RXFLAG_OVERFLOW)) {
RXD(("ERR(%08x)]", flags));
hp->net_stats.rx_errors++;
if (len < ETH_ZLEN)
hp->net_stats.rx_length_errors++;
if (len & (RXFLAG_OVERFLOW >> 16)) {
hp->net_stats.rx_over_errors++;
hp->net_stats.rx_fifo_errors++;
}
drop_it:
hp->net_stats.rx_dropped++;
hme_write_rxd(hp, this,
(RXFLAG_OWN|((RX_BUF_ALLOC_SIZE-RX_OFFSET)<<16)),
dma_addr);
goto next;
}
skb = hp->rx_skbs[elem];
if (len > RX_COPY_THRESHOLD) {
struct sk_buff *new_skb;
new_skb = happy_meal_alloc_skb(RX_BUF_ALLOC_SIZE, GFP_ATOMIC);
if (new_skb == NULL) {
drops++;
goto drop_it;
}
dma_unmap_single(hp->dma_dev, dma_addr, RX_BUF_ALLOC_SIZE, DMA_FROM_DEVICE);
hp->rx_skbs[elem] = new_skb;
skb_put(new_skb, (ETH_FRAME_LEN + RX_OFFSET + 4));
hme_write_rxd(hp, this,
(RXFLAG_OWN|((RX_BUF_ALLOC_SIZE-RX_OFFSET)<<16)),
dma_map_single(hp->dma_dev, new_skb->data, RX_BUF_ALLOC_SIZE,
DMA_FROM_DEVICE));
skb_reserve(new_skb, RX_OFFSET);
skb_trim(skb, len);
} else {
struct sk_buff *copy_skb = netdev_alloc_skb(dev, len + 2);
if (copy_skb == NULL) {
drops++;
goto drop_it;
}
skb_reserve(copy_skb, 2);
skb_put(copy_skb, len);
dma_sync_single_for_cpu(hp->dma_dev, dma_addr, len, DMA_FROM_DEVICE);
skb_copy_from_linear_data(skb, copy_skb->data, len);
dma_sync_single_for_device(hp->dma_dev, dma_addr, len, DMA_FROM_DEVICE);
hme_write_rxd(hp, this,
(RXFLAG_OWN|((RX_BUF_ALLOC_SIZE-RX_OFFSET)<<16)),
dma_addr);
skb = copy_skb;
}
skb->csum = csum_unfold(~(__force __sum16)htons(csum));
skb->ip_summed = CHECKSUM_COMPLETE;
RXD(("len=%d csum=%4x]", len, csum));
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
hp->net_stats.rx_packets++;
hp->net_stats.rx_bytes += len;
next:
elem = NEXT_RX(elem);
this = &rxbase[elem];
}
hp->rx_new = elem;
if (drops)
printk(KERN_INFO "%s: Memory squeeze, deferring packet.\n", hp->dev->name);
RXD((">"));
}
static irqreturn_t happy_meal_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct happy_meal *hp = netdev_priv(dev);
u32 happy_status = hme_read32(hp, hp->gregs + GREG_STAT);
HMD(("happy_meal_interrupt: status=%08x ", happy_status));
spin_lock(&hp->happy_lock);
if (happy_status & GREG_STAT_ERRORS) {
HMD(("ERRORS "));
if (happy_meal_is_not_so_happy(hp, happy_status))
goto out;
}
if (happy_status & GREG_STAT_MIFIRQ) {
HMD(("MIFIRQ "));
happy_meal_mif_interrupt(hp);
}
if (happy_status & GREG_STAT_TXALL) {
HMD(("TXALL "));
happy_meal_tx(hp);
}
if (happy_status & GREG_STAT_RXTOHOST) {
HMD(("RXTOHOST "));
happy_meal_rx(hp, dev);
}
HMD(("done\n"));
out:
spin_unlock(&hp->happy_lock);
return IRQ_HANDLED;
}
static irqreturn_t quattro_sbus_interrupt(int irq, void *cookie)
{
struct quattro *qp = (struct quattro *) cookie;
int i;
for (i = 0; i < 4; i++) {
struct net_device *dev = qp->happy_meals[i];
struct happy_meal *hp = netdev_priv(dev);
u32 happy_status = hme_read32(hp, hp->gregs + GREG_STAT);
HMD(("quattro_interrupt: status=%08x ", happy_status));
if (!(happy_status & (GREG_STAT_ERRORS |
GREG_STAT_MIFIRQ |
GREG_STAT_TXALL |
GREG_STAT_RXTOHOST)))
continue;
spin_lock(&hp->happy_lock);
if (happy_status & GREG_STAT_ERRORS) {
HMD(("ERRORS "));
if (happy_meal_is_not_so_happy(hp, happy_status))
goto next;
}
if (happy_status & GREG_STAT_MIFIRQ) {
HMD(("MIFIRQ "));
happy_meal_mif_interrupt(hp);
}
if (happy_status & GREG_STAT_TXALL) {
HMD(("TXALL "));
happy_meal_tx(hp);
}
if (happy_status & GREG_STAT_RXTOHOST) {
HMD(("RXTOHOST "));
happy_meal_rx(hp, dev);
}
next:
spin_unlock(&hp->happy_lock);
}
HMD(("done\n"));
return IRQ_HANDLED;
}
static int happy_meal_open(struct net_device *dev)
{
struct happy_meal *hp = netdev_priv(dev);
int res;
HMD(("happy_meal_open: "));
if ((hp->happy_flags & (HFLAG_QUATTRO|HFLAG_PCI)) != HFLAG_QUATTRO) {
res = request_irq(hp->irq, happy_meal_interrupt, IRQF_SHARED,
dev->name, dev);
if (res) {
HMD(("EAGAIN\n"));
printk(KERN_ERR "happy_meal(SBUS): Can't order irq %d to go.\n",
hp->irq);
return -EAGAIN;
}
}
HMD(("to happy_meal_init\n"));
spin_lock_irq(&hp->happy_lock);
res = happy_meal_init(hp);
spin_unlock_irq(&hp->happy_lock);
if (res && ((hp->happy_flags & (HFLAG_QUATTRO|HFLAG_PCI)) != HFLAG_QUATTRO))
free_irq(hp->irq, dev);
return res;
}
static int happy_meal_close(struct net_device *dev)
{
struct happy_meal *hp = netdev_priv(dev);
spin_lock_irq(&hp->happy_lock);
happy_meal_stop(hp, hp->gregs);
happy_meal_clean_rings(hp);
del_timer(&hp->happy_timer);
spin_unlock_irq(&hp->happy_lock);
if ((hp->happy_flags & (HFLAG_QUATTRO|HFLAG_PCI)) != HFLAG_QUATTRO)
free_irq(hp->irq, dev);
return 0;
}
static void happy_meal_tx_timeout(struct net_device *dev)
{
struct happy_meal *hp = netdev_priv(dev);
printk (KERN_ERR "%s: transmit timed out, resetting\n", dev->name);
tx_dump_log();
printk (KERN_ERR "%s: Happy Status %08x TX[%08x:%08x]\n", dev->name,
hme_read32(hp, hp->gregs + GREG_STAT),
hme_read32(hp, hp->etxregs + ETX_CFG),
hme_read32(hp, hp->bigmacregs + BMAC_TXCFG));
spin_lock_irq(&hp->happy_lock);
happy_meal_init(hp);
spin_unlock_irq(&hp->happy_lock);
netif_wake_queue(dev);
}
static netdev_tx_t happy_meal_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct happy_meal *hp = netdev_priv(dev);
int entry;
u32 tx_flags;
tx_flags = TXFLAG_OWN;
if (skb->ip_summed == CHECKSUM_PARTIAL) {
const u32 csum_start_off = skb_checksum_start_offset(skb);
const u32 csum_stuff_off = csum_start_off + skb->csum_offset;
tx_flags = (TXFLAG_OWN | TXFLAG_CSENABLE |
((csum_start_off << 14) & TXFLAG_CSBUFBEGIN) |
((csum_stuff_off << 20) & TXFLAG_CSLOCATION));
}
spin_lock_irq(&hp->happy_lock);
if (TX_BUFFS_AVAIL(hp) <= (skb_shinfo(skb)->nr_frags + 1)) {
netif_stop_queue(dev);
spin_unlock_irq(&hp->happy_lock);
printk(KERN_ERR "%s: BUG! Tx Ring full when queue awake!\n",
dev->name);
return NETDEV_TX_BUSY;
}
entry = hp->tx_new;
SXD(("SX<l[%d]e[%d]>", len, entry));
hp->tx_skbs[entry] = skb;
if (skb_shinfo(skb)->nr_frags == 0) {
u32 mapping, len;
len = skb->len;
mapping = dma_map_single(hp->dma_dev, skb->data, len, DMA_TO_DEVICE);
tx_flags |= (TXFLAG_SOP | TXFLAG_EOP);
hme_write_txd(hp, &hp->happy_block->happy_meal_txd[entry],
(tx_flags | (len & TXFLAG_SIZE)),
mapping);
entry = NEXT_TX(entry);
} else {
u32 first_len, first_mapping;
int frag, first_entry = entry;
first_len = skb_headlen(skb);
first_mapping = dma_map_single(hp->dma_dev, skb->data, first_len,
DMA_TO_DEVICE);
entry = NEXT_TX(entry);
for (frag = 0; frag < skb_shinfo(skb)->nr_frags; frag++) {
const skb_frag_t *this_frag = &skb_shinfo(skb)->frags[frag];
u32 len, mapping, this_txflags;
len = skb_frag_size(this_frag);
mapping = skb_frag_dma_map(hp->dma_dev, this_frag,
0, len, DMA_TO_DEVICE);
this_txflags = tx_flags;
if (frag == skb_shinfo(skb)->nr_frags - 1)
this_txflags |= TXFLAG_EOP;
hme_write_txd(hp, &hp->happy_block->happy_meal_txd[entry],
(this_txflags | (len & TXFLAG_SIZE)),
mapping);
entry = NEXT_TX(entry);
}
hme_write_txd(hp, &hp->happy_block->happy_meal_txd[first_entry],
(tx_flags | TXFLAG_SOP | (first_len & TXFLAG_SIZE)),
first_mapping);
}
hp->tx_new = entry;
if (TX_BUFFS_AVAIL(hp) <= (MAX_SKB_FRAGS + 1))
netif_stop_queue(dev);
hme_write32(hp, hp->etxregs + ETX_PENDING, ETX_TP_DMAWAKEUP);
spin_unlock_irq(&hp->happy_lock);
tx_add_log(hp, TXLOG_ACTION_TXMIT, 0);
return NETDEV_TX_OK;
}
static struct net_device_stats *happy_meal_get_stats(struct net_device *dev)
{
struct happy_meal *hp = netdev_priv(dev);
spin_lock_irq(&hp->happy_lock);
happy_meal_get_counters(hp, hp->bigmacregs);
spin_unlock_irq(&hp->happy_lock);
return &hp->net_stats;
}
static void happy_meal_set_multicast(struct net_device *dev)
{
struct happy_meal *hp = netdev_priv(dev);
void __iomem *bregs = hp->bigmacregs;
struct netdev_hw_addr *ha;
u32 crc;
spin_lock_irq(&hp->happy_lock);
if ((dev->flags & IFF_ALLMULTI) || (netdev_mc_count(dev) > 64)) {
hme_write32(hp, bregs + BMAC_HTABLE0, 0xffff);
hme_write32(hp, bregs + BMAC_HTABLE1, 0xffff);
hme_write32(hp, bregs + BMAC_HTABLE2, 0xffff);
hme_write32(hp, bregs + BMAC_HTABLE3, 0xffff);
} else if (dev->flags & IFF_PROMISC) {
hme_write32(hp, bregs + BMAC_RXCFG,
hme_read32(hp, bregs + BMAC_RXCFG) | BIGMAC_RXCFG_PMISC);
} else {
u16 hash_table[4];
memset(hash_table, 0, sizeof(hash_table));
netdev_for_each_mc_addr(ha, dev) {
crc = ether_crc_le(6, ha->addr);
crc >>= 26;
hash_table[crc >> 4] |= 1 << (crc & 0xf);
}
hme_write32(hp, bregs + BMAC_HTABLE0, hash_table[0]);
hme_write32(hp, bregs + BMAC_HTABLE1, hash_table[1]);
hme_write32(hp, bregs + BMAC_HTABLE2, hash_table[2]);
hme_write32(hp, bregs + BMAC_HTABLE3, hash_table[3]);
}
spin_unlock_irq(&hp->happy_lock);
}
static int hme_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct happy_meal *hp = netdev_priv(dev);
u32 speed;
cmd->supported =
(SUPPORTED_10baseT_Half | SUPPORTED_10baseT_Full |
SUPPORTED_100baseT_Half | SUPPORTED_100baseT_Full |
SUPPORTED_Autoneg | SUPPORTED_TP | SUPPORTED_MII);
cmd->port = PORT_TP;
cmd->transceiver = XCVR_INTERNAL;
cmd->phy_address = 0;
spin_lock_irq(&hp->happy_lock);
hp->sw_bmcr = happy_meal_tcvr_read(hp, hp->tcvregs, MII_BMCR);
hp->sw_lpa = happy_meal_tcvr_read(hp, hp->tcvregs, MII_LPA);
spin_unlock_irq(&hp->happy_lock);
if (hp->sw_bmcr & BMCR_ANENABLE) {
cmd->autoneg = AUTONEG_ENABLE;
speed = ((hp->sw_lpa & (LPA_100HALF | LPA_100FULL)) ?
SPEED_100 : SPEED_10);
if (speed == SPEED_100)
cmd->duplex =
(hp->sw_lpa & (LPA_100FULL)) ?
DUPLEX_FULL : DUPLEX_HALF;
else
cmd->duplex =
(hp->sw_lpa & (LPA_10FULL)) ?
DUPLEX_FULL : DUPLEX_HALF;
} else {
cmd->autoneg = AUTONEG_DISABLE;
speed = (hp->sw_bmcr & BMCR_SPEED100) ? SPEED_100 : SPEED_10;
cmd->duplex =
(hp->sw_bmcr & BMCR_FULLDPLX) ?
DUPLEX_FULL : DUPLEX_HALF;
}
ethtool_cmd_speed_set(cmd, speed);
return 0;
}
static int hme_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct happy_meal *hp = netdev_priv(dev);
if (cmd->autoneg != AUTONEG_ENABLE &&
cmd->autoneg != AUTONEG_DISABLE)
return -EINVAL;
if (cmd->autoneg == AUTONEG_DISABLE &&
((ethtool_cmd_speed(cmd) != SPEED_100 &&
ethtool_cmd_speed(cmd) != SPEED_10) ||
(cmd->duplex != DUPLEX_HALF &&
cmd->duplex != DUPLEX_FULL)))
return -EINVAL;
spin_lock_irq(&hp->happy_lock);
del_timer(&hp->happy_timer);
happy_meal_begin_auto_negotiation(hp, hp->tcvregs, cmd);
spin_unlock_irq(&hp->happy_lock);
return 0;
}
static void hme_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
struct happy_meal *hp = netdev_priv(dev);
strlcpy(info->driver, "sunhme", sizeof(info->driver));
strlcpy(info->version, "2.02", sizeof(info->version));
if (hp->happy_flags & HFLAG_PCI) {
struct pci_dev *pdev = hp->happy_dev;
strlcpy(info->bus_info, pci_name(pdev), sizeof(info->bus_info));
}
#ifdef CONFIG_SBUS
else {
const struct linux_prom_registers *regs;
struct platform_device *op = hp->happy_dev;
regs = of_get_property(op->dev.of_node, "regs", NULL);
if (regs)
snprintf(info->bus_info, sizeof(info->bus_info),
"SBUS:%d",
regs->which_io);
}
#endif
}
static u32 hme_get_link(struct net_device *dev)
{
struct happy_meal *hp = netdev_priv(dev);
spin_lock_irq(&hp->happy_lock);
hp->sw_bmcr = happy_meal_tcvr_read(hp, hp->tcvregs, MII_BMCR);
spin_unlock_irq(&hp->happy_lock);
return hp->sw_bmsr & BMSR_LSTATUS;
}
static struct quattro *quattro_sbus_find(struct platform_device *child)
{
struct device *parent = child->dev.parent;
struct platform_device *op;
struct quattro *qp;
op = to_platform_device(parent);
qp = dev_get_drvdata(&op->dev);
if (qp)
return qp;
qp = kmalloc(sizeof(struct quattro), GFP_KERNEL);
if (qp != NULL) {
int i;
for (i = 0; i < 4; i++)
qp->happy_meals[i] = NULL;
qp->quattro_dev = child;
qp->next = qfe_sbus_list;
qfe_sbus_list = qp;
dev_set_drvdata(&op->dev, qp);
}
return qp;
}
static int __init quattro_sbus_register_irqs(void)
{
struct quattro *qp;
for (qp = qfe_sbus_list; qp != NULL; qp = qp->next) {
struct platform_device *op = qp->quattro_dev;
int err, qfe_slot, skip = 0;
for (qfe_slot = 0; qfe_slot < 4; qfe_slot++) {
if (!qp->happy_meals[qfe_slot])
skip = 1;
}
if (skip)
continue;
err = request_irq(op->archdata.irqs[0],
quattro_sbus_interrupt,
IRQF_SHARED, "Quattro",
qp);
if (err != 0) {
printk(KERN_ERR "Quattro HME: IRQ registration "
"error %d.\n", err);
return err;
}
}
return 0;
}
static void quattro_sbus_free_irqs(void)
{
struct quattro *qp;
for (qp = qfe_sbus_list; qp != NULL; qp = qp->next) {
struct platform_device *op = qp->quattro_dev;
int qfe_slot, skip = 0;
for (qfe_slot = 0; qfe_slot < 4; qfe_slot++) {
if (!qp->happy_meals[qfe_slot])
skip = 1;
}
if (skip)
continue;
free_irq(op->archdata.irqs[0], qp);
}
}
static struct quattro *quattro_pci_find(struct pci_dev *pdev)
{
struct pci_dev *bdev = pdev->bus->self;
struct quattro *qp;
if (!bdev) return NULL;
for (qp = qfe_pci_list; qp != NULL; qp = qp->next) {
struct pci_dev *qpdev = qp->quattro_dev;
if (qpdev == bdev)
return qp;
}
qp = kmalloc(sizeof(struct quattro), GFP_KERNEL);
if (qp != NULL) {
int i;
for (i = 0; i < 4; i++)
qp->happy_meals[i] = NULL;
qp->quattro_dev = bdev;
qp->next = qfe_pci_list;
qfe_pci_list = qp;
qp->nranges = 0;
}
return qp;
}
static int happy_meal_sbus_probe_one(struct platform_device *op, int is_qfe)
{
struct device_node *dp = op->dev.of_node, *sbus_dp;
struct quattro *qp = NULL;
struct happy_meal *hp;
struct net_device *dev;
int i, qfe_slot = -1;
int err = -ENODEV;
sbus_dp = op->dev.parent->of_node;
if (strcmp(sbus_dp->name, "sbus") && strcmp(sbus_dp->name, "sbi"))
return err;
if (is_qfe) {
qp = quattro_sbus_find(op);
if (qp == NULL)
goto err_out;
for (qfe_slot = 0; qfe_slot < 4; qfe_slot++)
if (qp->happy_meals[qfe_slot] == NULL)
break;
if (qfe_slot == 4)
goto err_out;
}
err = -ENOMEM;
dev = alloc_etherdev(sizeof(struct happy_meal));
if (!dev)
goto err_out;
SET_NETDEV_DEV(dev, &op->dev);
if (hme_version_printed++ == 0)
printk(KERN_INFO "%s", version);
for (i = 0; i < 6; i++) {
if (macaddr[i] != 0)
break;
}
if (i < 6) {
for (i = 0; i < 6; i++)
dev->dev_addr[i] = macaddr[i];
macaddr[5]++;
} else {
const unsigned char *addr;
int len;
addr = of_get_property(dp, "local-mac-address", &len);
if (qfe_slot != -1 && addr && len == 6)
memcpy(dev->dev_addr, addr, 6);
else
memcpy(dev->dev_addr, idprom->id_ethaddr, 6);
}
hp = netdev_priv(dev);
hp->happy_dev = op;
hp->dma_dev = &op->dev;
spin_lock_init(&hp->happy_lock);
err = -ENODEV;
if (qp != NULL) {
hp->qfe_parent = qp;
hp->qfe_ent = qfe_slot;
qp->happy_meals[qfe_slot] = dev;
}
hp->gregs = of_ioremap(&op->resource[0], 0,
GREG_REG_SIZE, "HME Global Regs");
if (!hp->gregs) {
printk(KERN_ERR "happymeal: Cannot map global registers.\n");
goto err_out_free_netdev;
}
hp->etxregs = of_ioremap(&op->resource[1], 0,
ETX_REG_SIZE, "HME TX Regs");
if (!hp->etxregs) {
printk(KERN_ERR "happymeal: Cannot map MAC TX registers.\n");
goto err_out_iounmap;
}
hp->erxregs = of_ioremap(&op->resource[2], 0,
ERX_REG_SIZE, "HME RX Regs");
if (!hp->erxregs) {
printk(KERN_ERR "happymeal: Cannot map MAC RX registers.\n");
goto err_out_iounmap;
}
hp->bigmacregs = of_ioremap(&op->resource[3], 0,
BMAC_REG_SIZE, "HME BIGMAC Regs");
if (!hp->bigmacregs) {
printk(KERN_ERR "happymeal: Cannot map BIGMAC registers.\n");
goto err_out_iounmap;
}
hp->tcvregs = of_ioremap(&op->resource[4], 0,
TCVR_REG_SIZE, "HME Tranceiver Regs");
if (!hp->tcvregs) {
printk(KERN_ERR "happymeal: Cannot map TCVR registers.\n");
goto err_out_iounmap;
}
hp->hm_revision = of_getintprop_default(dp, "hm-rev", 0xff);
if (hp->hm_revision == 0xff)
hp->hm_revision = 0xa0;
if (hp->hm_revision == 0x20 || hp->hm_revision == 0x21)
hp->happy_flags = HFLAG_20_21;
else if (hp->hm_revision != 0xa0)
hp->happy_flags = HFLAG_NOT_A0;
if (qp != NULL)
hp->happy_flags |= HFLAG_QUATTRO;
hp->happy_bursts = of_getintprop_default(sbus_dp,
"burst-sizes", 0x00);
hp->happy_block = dma_alloc_coherent(hp->dma_dev,
PAGE_SIZE,
&hp->hblock_dvma,
GFP_ATOMIC);
err = -ENOMEM;
if (!hp->happy_block) {
printk(KERN_ERR "happymeal: Cannot allocate descriptors.\n");
goto err_out_iounmap;
}
hp->linkcheck = 0;
hp->timer_state = asleep;
hp->timer_ticks = 0;
init_timer(&hp->happy_timer);
hp->dev = dev;
dev->netdev_ops = &hme_netdev_ops;
dev->watchdog_timeo = 5*HZ;
dev->ethtool_ops = &hme_ethtool_ops;
dev->hw_features = NETIF_F_SG | NETIF_F_HW_CSUM;
dev->features |= dev->hw_features | NETIF_F_RXCSUM;
hp->irq = op->archdata.irqs[0];
#if defined(CONFIG_SBUS) && defined(CONFIG_PCI)
hp->read_desc32 = sbus_hme_read_desc32;
hp->write_txd = sbus_hme_write_txd;
hp->write_rxd = sbus_hme_write_rxd;
hp->read32 = sbus_hme_read32;
hp->write32 = sbus_hme_write32;
#endif
spin_lock_irq(&hp->happy_lock);
happy_meal_set_initial_advertisement(hp);
spin_unlock_irq(&hp->happy_lock);
err = register_netdev(hp->dev);
if (err) {
printk(KERN_ERR "happymeal: Cannot register net device, "
"aborting.\n");
goto err_out_free_coherent;
}
dev_set_drvdata(&op->dev, hp);
if (qfe_slot != -1)
printk(KERN_INFO "%s: Quattro HME slot %d (SBUS) 10/100baseT Ethernet ",
dev->name, qfe_slot);
else
printk(KERN_INFO "%s: HAPPY MEAL (SBUS) 10/100baseT Ethernet ",
dev->name);
printk("%pM\n", dev->dev_addr);
return 0;
err_out_free_coherent:
dma_free_coherent(hp->dma_dev,
PAGE_SIZE,
hp->happy_block,
hp->hblock_dvma);
err_out_iounmap:
if (hp->gregs)
of_iounmap(&op->resource[0], hp->gregs, GREG_REG_SIZE);
if (hp->etxregs)
of_iounmap(&op->resource[1], hp->etxregs, ETX_REG_SIZE);
if (hp->erxregs)
of_iounmap(&op->resource[2], hp->erxregs, ERX_REG_SIZE);
if (hp->bigmacregs)
of_iounmap(&op->resource[3], hp->bigmacregs, BMAC_REG_SIZE);
if (hp->tcvregs)
of_iounmap(&op->resource[4], hp->tcvregs, TCVR_REG_SIZE);
if (qp)
qp->happy_meals[qfe_slot] = NULL;
err_out_free_netdev:
free_netdev(dev);
err_out:
return err;
}
static int is_quattro_p(struct pci_dev *pdev)
{
struct pci_dev *busdev = pdev->bus->self;
struct pci_dev *this_pdev;
int n_hmes;
if (busdev == NULL ||
busdev->vendor != PCI_VENDOR_ID_DEC ||
busdev->device != PCI_DEVICE_ID_DEC_21153)
return 0;
n_hmes = 0;
list_for_each_entry(this_pdev, &pdev->bus->devices, bus_list) {
if (this_pdev->vendor == PCI_VENDOR_ID_SUN &&
this_pdev->device == PCI_DEVICE_ID_SUN_HAPPYMEAL)
n_hmes++;
}
if (n_hmes != 4)
return 0;
return 1;
}
static int find_eth_addr_in_vpd(void __iomem *rom_base, int len, int index, unsigned char *dev_addr)
{
int this_offset;
for (this_offset = 0x20; this_offset < len; this_offset++) {
void __iomem *p = rom_base + this_offset;
if (readb(p + 0) != 0x90 ||
readb(p + 1) != 0x00 ||
readb(p + 2) != 0x09 ||
readb(p + 3) != 0x4e ||
readb(p + 4) != 0x41 ||
readb(p + 5) != 0x06)
continue;
this_offset += 6;
p += 6;
if (index == 0) {
int i;
for (i = 0; i < 6; i++)
dev_addr[i] = readb(p + i);
return 1;
}
index--;
}
return 0;
}
static void get_hme_mac_nonsparc(struct pci_dev *pdev, unsigned char *dev_addr)
{
size_t size;
void __iomem *p = pci_map_rom(pdev, &size);
if (p) {
int index = 0;
int found;
if (is_quattro_p(pdev))
index = PCI_SLOT(pdev->devfn);
found = readb(p) == 0x55 &&
readb(p + 1) == 0xaa &&
find_eth_addr_in_vpd(p, (64 * 1024), index, dev_addr);
pci_unmap_rom(pdev, p);
if (found)
return;
}
dev_addr[0] = 0x08;
dev_addr[1] = 0x00;
dev_addr[2] = 0x20;
get_random_bytes(&dev_addr[3], 3);
}
static int happy_meal_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct quattro *qp = NULL;
#ifdef CONFIG_SPARC
struct device_node *dp;
#endif
struct happy_meal *hp;
struct net_device *dev;
void __iomem *hpreg_base;
unsigned long hpreg_res;
int i, qfe_slot = -1;
char prom_name[64];
int err;
#ifdef CONFIG_SPARC
dp = pci_device_to_OF_node(pdev);
strcpy(prom_name, dp->name);
#else
if (is_quattro_p(pdev))
strcpy(prom_name, "SUNW,qfe");
else
strcpy(prom_name, "SUNW,hme");
#endif
err = -ENODEV;
if (pci_enable_device(pdev))
goto err_out;
pci_set_master(pdev);
if (!strcmp(prom_name, "SUNW,qfe") || !strcmp(prom_name, "qfe")) {
qp = quattro_pci_find(pdev);
if (qp == NULL)
goto err_out;
for (qfe_slot = 0; qfe_slot < 4; qfe_slot++)
if (qp->happy_meals[qfe_slot] == NULL)
break;
if (qfe_slot == 4)
goto err_out;
}
dev = alloc_etherdev(sizeof(struct happy_meal));
err = -ENOMEM;
if (!dev)
goto err_out;
SET_NETDEV_DEV(dev, &pdev->dev);
if (hme_version_printed++ == 0)
printk(KERN_INFO "%s", version);
hp = netdev_priv(dev);
hp->happy_dev = pdev;
hp->dma_dev = &pdev->dev;
spin_lock_init(&hp->happy_lock);
if (qp != NULL) {
hp->qfe_parent = qp;
hp->qfe_ent = qfe_slot;
qp->happy_meals[qfe_slot] = dev;
}
hpreg_res = pci_resource_start(pdev, 0);
err = -ENODEV;
if ((pci_resource_flags(pdev, 0) & IORESOURCE_IO) != 0) {
printk(KERN_ERR "happymeal(PCI): Cannot find proper PCI device base address.\n");
goto err_out_clear_quattro;
}
if (pci_request_regions(pdev, DRV_NAME)) {
printk(KERN_ERR "happymeal(PCI): Cannot obtain PCI resources, "
"aborting.\n");
goto err_out_clear_quattro;
}
if ((hpreg_base = ioremap(hpreg_res, 0x8000)) == NULL) {
printk(KERN_ERR "happymeal(PCI): Unable to remap card memory.\n");
goto err_out_free_res;
}
for (i = 0; i < 6; i++) {
if (macaddr[i] != 0)
break;
}
if (i < 6) {
for (i = 0; i < 6; i++)
dev->dev_addr[i] = macaddr[i];
macaddr[5]++;
} else {
#ifdef CONFIG_SPARC
const unsigned char *addr;
int len;
if (qfe_slot != -1 &&
(addr = of_get_property(dp, "local-mac-address", &len))
!= NULL &&
len == 6) {
memcpy(dev->dev_addr, addr, 6);
} else {
memcpy(dev->dev_addr, idprom->id_ethaddr, 6);
}
#else
get_hme_mac_nonsparc(pdev, &dev->dev_addr[0]);
#endif
}
hp->gregs = (hpreg_base + 0x0000UL);
hp->etxregs = (hpreg_base + 0x2000UL);
hp->erxregs = (hpreg_base + 0x4000UL);
hp->bigmacregs = (hpreg_base + 0x6000UL);
hp->tcvregs = (hpreg_base + 0x7000UL);
#ifdef CONFIG_SPARC
hp->hm_revision = of_getintprop_default(dp, "hm-rev", 0xff);
if (hp->hm_revision == 0xff)
hp->hm_revision = 0xc0 | (pdev->revision & 0x0f);
#else
hp->hm_revision = 0x20;
#endif
if (hp->hm_revision == 0x20 || hp->hm_revision == 0x21)
hp->happy_flags = HFLAG_20_21;
else if (hp->hm_revision != 0xa0 && hp->hm_revision != 0xc0)
hp->happy_flags = HFLAG_NOT_A0;
if (qp != NULL)
hp->happy_flags |= HFLAG_QUATTRO;
hp->happy_flags |= HFLAG_PCI;
#ifdef CONFIG_SPARC
hp->happy_bursts = DMA_BURSTBITS;
#endif
hp->happy_block = (struct hmeal_init_block *)
dma_alloc_coherent(&pdev->dev, PAGE_SIZE, &hp->hblock_dvma, GFP_KERNEL);
err = -ENODEV;
if (!hp->happy_block) {
printk(KERN_ERR "happymeal(PCI): Cannot get hme init block.\n");
goto err_out_iounmap;
}
hp->linkcheck = 0;
hp->timer_state = asleep;
hp->timer_ticks = 0;
init_timer(&hp->happy_timer);
hp->irq = pdev->irq;
hp->dev = dev;
dev->netdev_ops = &hme_netdev_ops;
dev->watchdog_timeo = 5*HZ;
dev->ethtool_ops = &hme_ethtool_ops;
dev->hw_features = NETIF_F_SG | NETIF_F_HW_CSUM;
dev->features |= dev->hw_features | NETIF_F_RXCSUM;
#if defined(CONFIG_SBUS) && defined(CONFIG_PCI)
hp->read_desc32 = pci_hme_read_desc32;
hp->write_txd = pci_hme_write_txd;
hp->write_rxd = pci_hme_write_rxd;
hp->read32 = pci_hme_read32;
hp->write32 = pci_hme_write32;
#endif
spin_lock_irq(&hp->happy_lock);
happy_meal_set_initial_advertisement(hp);
spin_unlock_irq(&hp->happy_lock);
err = register_netdev(hp->dev);
if (err) {
printk(KERN_ERR "happymeal(PCI): Cannot register net device, "
"aborting.\n");
goto err_out_iounmap;
}
dev_set_drvdata(&pdev->dev, hp);
if (!qfe_slot) {
struct pci_dev *qpdev = qp->quattro_dev;
prom_name[0] = 0;
if (!strncmp(dev->name, "eth", 3)) {
int i = simple_strtoul(dev->name + 3, NULL, 10);
sprintf(prom_name, "-%d", i + 3);
}
printk(KERN_INFO "%s%s: Quattro HME (PCI/CheerIO) 10/100baseT Ethernet ", dev->name, prom_name);
if (qpdev->vendor == PCI_VENDOR_ID_DEC &&
qpdev->device == PCI_DEVICE_ID_DEC_21153)
printk("DEC 21153 PCI Bridge\n");
else
printk("unknown bridge %04x.%04x\n",
qpdev->vendor, qpdev->device);
}
if (qfe_slot != -1)
printk(KERN_INFO "%s: Quattro HME slot %d (PCI/CheerIO) 10/100baseT Ethernet ",
dev->name, qfe_slot);
else
printk(KERN_INFO "%s: HAPPY MEAL (PCI/CheerIO) 10/100BaseT Ethernet ",
dev->name);
printk("%pM\n", dev->dev_addr);
return 0;
err_out_iounmap:
iounmap(hp->gregs);
err_out_free_res:
pci_release_regions(pdev);
err_out_clear_quattro:
if (qp != NULL)
qp->happy_meals[qfe_slot] = NULL;
free_netdev(dev);
err_out:
return err;
}
static void happy_meal_pci_remove(struct pci_dev *pdev)
{
struct happy_meal *hp = dev_get_drvdata(&pdev->dev);
struct net_device *net_dev = hp->dev;
unregister_netdev(net_dev);
dma_free_coherent(hp->dma_dev, PAGE_SIZE,
hp->happy_block, hp->hblock_dvma);
iounmap(hp->gregs);
pci_release_regions(hp->happy_dev);
free_netdev(net_dev);
dev_set_drvdata(&pdev->dev, NULL);
}
static int __init happy_meal_pci_init(void)
{
return pci_register_driver(&hme_pci_driver);
}
static void happy_meal_pci_exit(void)
{
pci_unregister_driver(&hme_pci_driver);
while (qfe_pci_list) {
struct quattro *qfe = qfe_pci_list;
struct quattro *next = qfe->next;
kfree(qfe);
qfe_pci_list = next;
}
}
static int hme_sbus_probe(struct platform_device *op)
{
const struct of_device_id *match;
struct device_node *dp = op->dev.of_node;
const char *model = of_get_property(dp, "model", NULL);
int is_qfe;
match = of_match_device(hme_sbus_match, &op->dev);
if (!match)
return -EINVAL;
is_qfe = (match->data != NULL);
if (!is_qfe && model && !strcmp(model, "SUNW,sbus-qfe"))
is_qfe = 1;
return happy_meal_sbus_probe_one(op, is_qfe);
}
static int hme_sbus_remove(struct platform_device *op)
{
struct happy_meal *hp = dev_get_drvdata(&op->dev);
struct net_device *net_dev = hp->dev;
unregister_netdev(net_dev);
of_iounmap(&op->resource[0], hp->gregs, GREG_REG_SIZE);
of_iounmap(&op->resource[1], hp->etxregs, ETX_REG_SIZE);
of_iounmap(&op->resource[2], hp->erxregs, ERX_REG_SIZE);
of_iounmap(&op->resource[3], hp->bigmacregs, BMAC_REG_SIZE);
of_iounmap(&op->resource[4], hp->tcvregs, TCVR_REG_SIZE);
dma_free_coherent(hp->dma_dev,
PAGE_SIZE,
hp->happy_block,
hp->hblock_dvma);
free_netdev(net_dev);
dev_set_drvdata(&op->dev, NULL);
return 0;
}
static int __init happy_meal_sbus_init(void)
{
int err;
err = platform_driver_register(&hme_sbus_driver);
if (!err)
err = quattro_sbus_register_irqs();
return err;
}
static void happy_meal_sbus_exit(void)
{
platform_driver_unregister(&hme_sbus_driver);
quattro_sbus_free_irqs();
while (qfe_sbus_list) {
struct quattro *qfe = qfe_sbus_list;
struct quattro *next = qfe->next;
kfree(qfe);
qfe_sbus_list = next;
}
}
static int __init happy_meal_probe(void)
{
int err = 0;
#ifdef CONFIG_SBUS
err = happy_meal_sbus_init();
#endif
#ifdef CONFIG_PCI
if (!err) {
err = happy_meal_pci_init();
#ifdef CONFIG_SBUS
if (err)
happy_meal_sbus_exit();
#endif
}
#endif
return err;
}
static void __exit happy_meal_exit(void)
{
#ifdef CONFIG_SBUS
happy_meal_sbus_exit();
#endif
#ifdef CONFIG_PCI
happy_meal_pci_exit();
#endif
}
