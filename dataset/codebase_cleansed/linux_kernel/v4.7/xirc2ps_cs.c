static void
mii_idle(unsigned int ioaddr)
{
PutByte(XIRCREG2_GPR2, 0x04|0);
udelay(1);
PutByte(XIRCREG2_GPR2, 0x04|1);
udelay(1);
}
static void
mii_putbit(unsigned int ioaddr, unsigned data)
{
#if 1
if (data) {
PutByte(XIRCREG2_GPR2, 0x0c|2|0);
udelay(1);
PutByte(XIRCREG2_GPR2, 0x0c|2|1);
udelay(1);
} else {
PutByte(XIRCREG2_GPR2, 0x0c|0|0);
udelay(1);
PutByte(XIRCREG2_GPR2, 0x0c|0|1);
udelay(1);
}
#else
if (data) {
PutWord(XIRCREG2_GPR2-1, 0x0e0e);
udelay(1);
PutWord(XIRCREG2_GPR2-1, 0x0f0f);
udelay(1);
} else {
PutWord(XIRCREG2_GPR2-1, 0x0c0c);
udelay(1);
PutWord(XIRCREG2_GPR2-1, 0x0d0d);
udelay(1);
}
#endif
}
static int
mii_getbit(unsigned int ioaddr)
{
unsigned d;
PutByte(XIRCREG2_GPR2, 4|0);
udelay(1);
d = GetByte(XIRCREG2_GPR2);
PutByte(XIRCREG2_GPR2, 4|1);
udelay(1);
return d & 0x20;
}
static void
mii_wbits(unsigned int ioaddr, unsigned data, int len)
{
unsigned m = 1 << (len-1);
for (; m; m >>= 1)
mii_putbit(ioaddr, data & m);
}
static unsigned
mii_rd(unsigned int ioaddr, u_char phyaddr, u_char phyreg)
{
int i;
unsigned data=0, m;
SelectPage(2);
for (i=0; i < 32; i++)
mii_putbit(ioaddr, 1);
mii_wbits(ioaddr, 0x06, 4);
mii_wbits(ioaddr, phyaddr, 5);
mii_wbits(ioaddr, phyreg, 5);
mii_idle(ioaddr);
mii_getbit(ioaddr);
for (m = 1<<15; m; m >>= 1)
if (mii_getbit(ioaddr))
data |= m;
mii_idle(ioaddr);
return data;
}
static void
mii_wr(unsigned int ioaddr, u_char phyaddr, u_char phyreg, unsigned data,
int len)
{
int i;
SelectPage(2);
for (i=0; i < 32; i++)
mii_putbit(ioaddr, 1);
mii_wbits(ioaddr, 0x05, 4);
mii_wbits(ioaddr, phyaddr, 5);
mii_wbits(ioaddr, phyreg, 5);
mii_putbit(ioaddr, 1);
mii_putbit(ioaddr, 0);
mii_wbits(ioaddr, data, len);
mii_idle(ioaddr);
}
static int
xirc2ps_probe(struct pcmcia_device *link)
{
struct net_device *dev;
struct local_info *local;
dev_dbg(&link->dev, "attach()\n");
dev = alloc_etherdev(sizeof(struct local_info));
if (!dev)
return -ENOMEM;
local = netdev_priv(dev);
local->dev = dev;
local->p_dev = link;
link->priv = dev;
link->config_index = 1;
dev->netdev_ops = &netdev_ops;
dev->ethtool_ops = &netdev_ethtool_ops;
dev->watchdog_timeo = TX_TIMEOUT;
INIT_WORK(&local->tx_timeout_task, xirc2ps_tx_timeout_task);
return xirc2ps_config(link);
}
static void
xirc2ps_detach(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
dev_dbg(&link->dev, "detach\n");
unregister_netdev(dev);
xirc2ps_release(link);
free_netdev(dev);
}
static int
set_card_type(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
struct local_info *local = netdev_priv(dev);
u8 *buf;
unsigned int cisrev, mediaid, prodid;
size_t len;
len = pcmcia_get_tuple(link, CISTPL_MANFID, &buf);
if (len < 5) {
dev_err(&link->dev, "invalid CIS -- sorry\n");
return 0;
}
cisrev = buf[2];
mediaid = buf[3];
prodid = buf[4];
dev_dbg(&link->dev, "cisrev=%02x mediaid=%02x prodid=%02x\n",
cisrev, mediaid, prodid);
local->mohawk = 0;
local->dingo = 0;
local->modem = 0;
local->card_type = XIR_UNKNOWN;
if (!(prodid & 0x40)) {
pr_notice("Oops: Not a creditcard\n");
return 0;
}
if (!(mediaid & 0x01)) {
pr_notice("Not an Ethernet card\n");
return 0;
}
if (mediaid & 0x10) {
local->modem = 1;
switch(prodid & 15) {
case 1: local->card_type = XIR_CEM ; break;
case 2: local->card_type = XIR_CEM2 ; break;
case 3: local->card_type = XIR_CEM3 ; break;
case 4: local->card_type = XIR_CEM33 ; break;
case 5: local->card_type = XIR_CEM56M;
local->mohawk = 1;
break;
case 6:
case 7:
local->card_type = XIR_CEM56 ;
local->mohawk = 1;
local->dingo = 1;
break;
}
} else {
switch(prodid & 15) {
case 1: local->card_type = has_ce2_string(link)? XIR_CE2 : XIR_CE ;
break;
case 2: local->card_type = XIR_CE2; break;
case 3: local->card_type = XIR_CE3;
local->mohawk = 1;
break;
}
}
if (local->card_type == XIR_CE || local->card_type == XIR_CEM) {
pr_notice("Sorry, this is an old CE card\n");
return 0;
}
if (local->card_type == XIR_UNKNOWN)
pr_notice("unknown card (mediaid=%02x prodid=%02x)\n", mediaid, prodid);
return 1;
}
static int
has_ce2_string(struct pcmcia_device * p_dev)
{
if (p_dev->prod_id[2] && strstr(p_dev->prod_id[2], "CE2"))
return 1;
return 0;
}
static int
xirc2ps_config_modem(struct pcmcia_device *p_dev, void *priv_data)
{
unsigned int ioaddr;
if ((p_dev->resource[0]->start & 0xf) == 8)
return -ENODEV;
p_dev->resource[0]->end = 16;
p_dev->resource[1]->end = 8;
p_dev->resource[0]->flags &= ~IO_DATA_PATH_WIDTH;
p_dev->resource[0]->flags |= IO_DATA_PATH_WIDTH_16;
p_dev->resource[1]->flags &= ~IO_DATA_PATH_WIDTH;
p_dev->resource[1]->flags |= IO_DATA_PATH_WIDTH_8;
p_dev->io_lines = 10;
p_dev->resource[1]->start = p_dev->resource[0]->start;
for (ioaddr = 0x300; ioaddr < 0x400; ioaddr += 0x10) {
p_dev->resource[0]->start = ioaddr;
if (!pcmcia_request_io(p_dev))
return 0;
}
return -ENODEV;
}
static int
xirc2ps_config_check(struct pcmcia_device *p_dev, void *priv_data)
{
int *pass = priv_data;
resource_size_t tmp = p_dev->resource[1]->start;
tmp += (*pass ? (p_dev->config_index & 0x20 ? -24 : 8)
: (p_dev->config_index & 0x20 ? 8 : -24));
if ((p_dev->resource[0]->start & 0xf) == 8)
return -ENODEV;
p_dev->resource[0]->end = 18;
p_dev->resource[1]->end = 8;
p_dev->resource[0]->flags &= ~IO_DATA_PATH_WIDTH;
p_dev->resource[0]->flags |= IO_DATA_PATH_WIDTH_16;
p_dev->resource[1]->flags &= ~IO_DATA_PATH_WIDTH;
p_dev->resource[1]->flags |= IO_DATA_PATH_WIDTH_8;
p_dev->io_lines = 10;
p_dev->resource[1]->start = p_dev->resource[0]->start;
p_dev->resource[0]->start = tmp;
return pcmcia_request_io(p_dev);
}
static int pcmcia_get_mac_ce(struct pcmcia_device *p_dev,
tuple_t *tuple,
void *priv)
{
struct net_device *dev = priv;
int i;
if (tuple->TupleDataLen != 13)
return -EINVAL;
if ((tuple->TupleData[0] != 2) || (tuple->TupleData[1] != 1) ||
(tuple->TupleData[2] != 6))
return -EINVAL;
for (i = 2; i < 6; i++)
dev->dev_addr[i] = tuple->TupleData[i+2];
return 0;
}
static int
xirc2ps_config(struct pcmcia_device * link)
{
struct net_device *dev = link->priv;
struct local_info *local = netdev_priv(dev);
unsigned int ioaddr;
int err;
u8 *buf;
size_t len;
local->dingo_ccr = NULL;
dev_dbg(&link->dev, "config\n");
if (link->has_manf_id == 0) {
pr_notice("manfid not found in CIS\n");
goto failure;
}
switch (link->manf_id) {
case MANFID_XIRCOM:
local->manf_str = "Xircom";
break;
case MANFID_ACCTON:
local->manf_str = "Accton";
break;
case MANFID_COMPAQ:
case MANFID_COMPAQ2:
local->manf_str = "Compaq";
break;
case MANFID_INTEL:
local->manf_str = "Intel";
break;
case MANFID_TOSHIBA:
local->manf_str = "Toshiba";
break;
default:
pr_notice("Unknown Card Manufacturer ID: 0x%04x\n",
(unsigned)link->manf_id);
goto failure;
}
dev_dbg(&link->dev, "found %s card\n", local->manf_str);
if (!set_card_type(link)) {
pr_notice("this card is not supported\n");
goto failure;
}
err = pcmcia_get_mac_from_cis(link, dev);
if (err) {
len = pcmcia_get_tuple(link, 0x89, &buf);
if (buf && len == 8) {
if (*buf == CISTPL_FUNCE_LAN_NODE_ID) {
int i;
for (i = 2; i < 6; i++)
dev->dev_addr[i] = buf[i+2];
} else
err = -1;
}
kfree(buf);
}
if (err)
err = pcmcia_loop_tuple(link, CISTPL_FUNCE, pcmcia_get_mac_ce, dev);
if (err) {
pr_notice("node-id not found in CIS\n");
goto failure;
}
if (local->modem) {
int pass;
link->config_flags |= CONF_AUTO_SET_IO;
if (local->dingo) {
if (!pcmcia_loop_config(link, xirc2ps_config_modem, NULL))
goto port_found;
} else {
for (pass=0; pass < 2; pass++)
if (!pcmcia_loop_config(link, xirc2ps_config_check,
&pass))
goto port_found;
}
pr_notice("no ports available\n");
} else {
link->io_lines = 10;
link->resource[0]->end = 16;
link->resource[0]->flags |= IO_DATA_PATH_WIDTH_16;
for (ioaddr = 0x300; ioaddr < 0x400; ioaddr += 0x10) {
link->resource[0]->start = ioaddr;
if (!(err = pcmcia_request_io(link)))
goto port_found;
}
link->resource[0]->start = 0;
if ((err = pcmcia_request_io(link)))
goto config_error;
}
port_found:
if (err)
goto config_error;
if ((err=pcmcia_request_irq(link, xirc2ps_interrupt)))
goto config_error;
link->config_flags |= CONF_ENABLE_IRQ;
if (do_sound)
link->config_flags |= CONF_ENABLE_SPKR;
if ((err = pcmcia_enable_device(link)))
goto config_error;
if (local->dingo) {
err = pcmcia_write_config_byte(link, CISREG_IOBASE_0, (u8)
link->resource[1]->start & 0xff);
if (err)
goto config_error;
err = pcmcia_write_config_byte(link, CISREG_IOBASE_1,
(link->resource[1]->start >> 8) & 0xff);
if (err)
goto config_error;
link->resource[2]->flags = WIN_DATA_WIDTH_8 | WIN_MEMORY_TYPE_AM |
WIN_ENABLE;
link->resource[2]->start = link->resource[2]->end = 0;
if ((err = pcmcia_request_window(link, link->resource[2], 0)))
goto config_error;
local->dingo_ccr = ioremap(link->resource[2]->start, 0x1000) + 0x0800;
if ((err = pcmcia_map_mem_page(link, link->resource[2], 0)))
goto config_error;
writeb(0x47, local->dingo_ccr + CISREG_COR);
ioaddr = link->resource[0]->start;
writeb(ioaddr & 0xff , local->dingo_ccr + CISREG_IOBASE_0);
writeb((ioaddr >> 8)&0xff , local->dingo_ccr + CISREG_IOBASE_1);
#if 0
{
u_char tmp;
pr_info("ECOR:");
for (i=0; i < 7; i++) {
tmp = readb(local->dingo_ccr + i*2);
pr_cont(" %02x", tmp);
}
pr_cont("\n");
pr_info("DCOR:");
for (i=0; i < 4; i++) {
tmp = readb(local->dingo_ccr + 0x20 + i*2);
pr_cont(" %02x", tmp);
}
pr_cont("\n");
pr_info("SCOR:");
for (i=0; i < 10; i++) {
tmp = readb(local->dingo_ccr + 0x40 + i*2);
pr_cont(" %02x", tmp);
}
pr_cont("\n");
}
#endif
writeb(0x01, local->dingo_ccr + 0x20);
writeb(0x0c, local->dingo_ccr + 0x22);
writeb(0x00, local->dingo_ccr + 0x24);
writeb(0x00, local->dingo_ccr + 0x26);
writeb(0x00, local->dingo_ccr + 0x28);
}
local->probe_port=0;
if (!if_port) {
local->probe_port = dev->if_port = 1;
} else if ((if_port >= 1 && if_port <= 2) ||
(local->mohawk && if_port==4))
dev->if_port = if_port;
else
pr_notice("invalid if_port requested\n");
dev->irq = link->irq;
dev->base_addr = link->resource[0]->start;
if (local->dingo)
do_reset(dev, 1);
SET_NETDEV_DEV(dev, &link->dev);
if ((err=register_netdev(dev))) {
pr_notice("register_netdev() failed\n");
goto config_error;
}
netdev_info(dev, "%s: port %#3lx, irq %d, hwaddr %pM\n",
local->manf_str, (u_long)dev->base_addr, (int)dev->irq,
dev->dev_addr);
return 0;
config_error:
xirc2ps_release(link);
return -ENODEV;
failure:
return -ENODEV;
}
static void
xirc2ps_release(struct pcmcia_device *link)
{
dev_dbg(&link->dev, "release\n");
if (link->resource[2]->end) {
struct net_device *dev = link->priv;
struct local_info *local = netdev_priv(dev);
if (local->dingo)
iounmap(local->dingo_ccr - 0x0800);
}
pcmcia_disable_device(link);
}
static int xirc2ps_suspend(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
if (link->open) {
netif_device_detach(dev);
do_powerdown(dev);
}
return 0;
}
static int xirc2ps_resume(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
if (link->open) {
do_reset(dev,1);
netif_device_attach(dev);
}
return 0;
}
static irqreturn_t
xirc2ps_interrupt(int irq, void *dev_id)
{
struct net_device *dev = (struct net_device *)dev_id;
struct local_info *lp = netdev_priv(dev);
unsigned int ioaddr;
u_char saved_page;
unsigned bytes_rcvd;
unsigned int_status, eth_status, rx_status, tx_status;
unsigned rsr, pktlen;
ulong start_ticks = jiffies;
if (!netif_device_present(dev))
return IRQ_HANDLED;
ioaddr = dev->base_addr;
if (lp->mohawk) {
PutByte(XIRCREG_CR, 0);
}
pr_debug("%s: interrupt %d at %#x.\n", dev->name, irq, ioaddr);
saved_page = GetByte(XIRCREG_PR);
int_status = GetByte(XIRCREG_ISR);
bytes_rcvd = 0;
loop_entry:
if (int_status == 0xff) {
pr_debug("%s: interrupt %d for dead card\n", dev->name, irq);
goto leave;
}
eth_status = GetByte(XIRCREG_ESR);
SelectPage(0x40);
rx_status = GetByte(XIRCREG40_RXST0);
PutByte(XIRCREG40_RXST0, (~rx_status & 0xff));
tx_status = GetByte(XIRCREG40_TXST0);
tx_status |= GetByte(XIRCREG40_TXST1) << 8;
PutByte(XIRCREG40_TXST0, 0);
PutByte(XIRCREG40_TXST1, 0);
pr_debug("%s: ISR=%#2.2x ESR=%#2.2x RSR=%#2.2x TSR=%#4.4x\n",
dev->name, int_status, eth_status, rx_status, tx_status);
SelectPage(0);
while (eth_status & FullPktRcvd) {
rsr = GetByte(XIRCREG0_RSR);
if (bytes_rcvd > maxrx_bytes && (rsr & PktRxOk)) {
dev->stats.rx_dropped++;
pr_debug("%s: RX drop, too much done\n", dev->name);
} else if (rsr & PktRxOk) {
struct sk_buff *skb;
pktlen = GetWord(XIRCREG0_RBC);
bytes_rcvd += pktlen;
pr_debug("rsr=%#02x packet_length=%u\n", rsr, pktlen);
skb = netdev_alloc_skb(dev, pktlen + 3);
if (!skb) {
dev->stats.rx_dropped++;
} else {
skb_reserve(skb, 2);
if (lp->silicon == 0 ) {
unsigned rhsa;
SelectPage(5);
rhsa = GetWord(XIRCREG5_RHSA0);
SelectPage(0);
rhsa += 3;
if (rhsa >= 0x8000)
rhsa = 0;
if (rhsa + pktlen > 0x8000) {
unsigned i;
u_char *buf = skb_put(skb, pktlen);
for (i=0; i < pktlen ; i++, rhsa++) {
buf[i] = GetByte(XIRCREG_EDP);
if (rhsa == 0x8000) {
rhsa = 0;
i--;
}
}
} else {
insw(ioaddr+XIRCREG_EDP,
skb_put(skb, pktlen), (pktlen+1)>>1);
}
}
#if 0
else if (lp->mohawk) {
unsigned i;
u_long *p = skb_put(skb, pktlen);
register u_long a;
unsigned int edpreg = ioaddr+XIRCREG_EDP-2;
for (i=0; i < len ; i += 4, p++) {
a = inl(edpreg);
__asm__("rorl $16,%0\n\t"
:"=q" (a)
: "0" (a));
*p = a;
}
}
#endif
else {
insw(ioaddr+XIRCREG_EDP, skb_put(skb, pktlen),
(pktlen+1)>>1);
}
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += pktlen;
if (!(rsr & PhyPkt))
dev->stats.multicast++;
}
} else {
pr_debug("rsr=%#02x\n", rsr);
}
if (rsr & PktTooLong) {
dev->stats.rx_frame_errors++;
pr_debug("%s: Packet too long\n", dev->name);
}
if (rsr & CRCErr) {
dev->stats.rx_crc_errors++;
pr_debug("%s: CRC error\n", dev->name);
}
if (rsr & AlignErr) {
dev->stats.rx_fifo_errors++;
pr_debug("%s: Alignment error\n", dev->name);
}
PutWord(XIRCREG0_DO, 0x8000);
eth_status = GetByte(XIRCREG_ESR);
}
if (rx_status & 0x10) {
dev->stats.rx_over_errors++;
PutByte(XIRCREG_CR, ClearRxOvrun);
pr_debug("receive overrun cleared\n");
}
if (int_status & PktTxed) {
unsigned n, nn;
n = lp->last_ptr_value;
nn = GetByte(XIRCREG0_PTR);
lp->last_ptr_value = nn;
if (nn < n)
dev->stats.tx_packets += 256 - n;
else if (n == nn) {
pr_debug("PTR not changed?\n");
} else
dev->stats.tx_packets += lp->last_ptr_value - n;
netif_wake_queue(dev);
}
if (tx_status & 0x0002) {
pr_debug("tx restarted due to execssive collissions\n");
PutByte(XIRCREG_CR, RestartTx);
}
if (tx_status & 0x0040)
dev->stats.tx_aborted_errors++;
if (bytes_rcvd > 1000) {
u_long duration = jiffies - start_ticks;
if (duration >= HZ/10) {
maxrx_bytes = (bytes_rcvd * (HZ/10)) / duration;
if (maxrx_bytes < 2000)
maxrx_bytes = 2000;
else if (maxrx_bytes > 22000)
maxrx_bytes = 22000;
pr_debug("set maxrx=%u (rcvd=%u ticks=%lu)\n",
maxrx_bytes, bytes_rcvd, duration);
} else if (!duration && maxrx_bytes < 22000) {
maxrx_bytes += 2000;
if (maxrx_bytes > 22000)
maxrx_bytes = 22000;
pr_debug("set maxrx=%u\n", maxrx_bytes);
}
}
leave:
if (lockup_hack) {
if (int_status != 0xff && (int_status = GetByte(XIRCREG_ISR)) != 0)
goto loop_entry;
}
SelectPage(saved_page);
PutByte(XIRCREG_CR, EnableIntr);
return IRQ_HANDLED;
}
static void
xirc2ps_tx_timeout_task(struct work_struct *work)
{
struct local_info *local =
container_of(work, struct local_info, tx_timeout_task);
struct net_device *dev = local->dev;
do_reset(dev,1);
netif_trans_update(dev);
netif_wake_queue(dev);
}
static void
xirc_tx_timeout(struct net_device *dev)
{
struct local_info *lp = netdev_priv(dev);
dev->stats.tx_errors++;
netdev_notice(dev, "transmit timed out\n");
schedule_work(&lp->tx_timeout_task);
}
static netdev_tx_t
do_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct local_info *lp = netdev_priv(dev);
unsigned int ioaddr = dev->base_addr;
int okay;
unsigned freespace;
unsigned pktlen = skb->len;
pr_debug("do_start_xmit(skb=%p, dev=%p) len=%u\n",
skb, dev, pktlen);
if (pktlen < ETH_ZLEN)
{
if (skb_padto(skb, ETH_ZLEN))
return NETDEV_TX_OK;
pktlen = ETH_ZLEN;
}
netif_stop_queue(dev);
SelectPage(0);
PutWord(XIRCREG0_TRS, (u_short)pktlen+2);
freespace = GetWord(XIRCREG0_TSO);
okay = freespace & 0x8000;
freespace &= 0x7fff;
okay = pktlen +2 < freespace;
pr_debug("%s: avail. tx space=%u%s\n",
dev->name, freespace, okay ? " (okay)":" (not enough)");
if (!okay) {
return NETDEV_TX_BUSY;
}
PutWord(XIRCREG_EDP, (u_short)pktlen);
outsw(ioaddr+XIRCREG_EDP, skb->data, pktlen>>1);
if (pktlen & 1)
PutByte(XIRCREG_EDP, skb->data[pktlen-1]);
if (lp->mohawk)
PutByte(XIRCREG_CR, TransmitPacket|EnableIntr);
dev_kfree_skb (skb);
dev->stats.tx_bytes += pktlen;
netif_start_queue(dev);
return NETDEV_TX_OK;
}
static void set_address(struct set_address_info *sa_info, char *addr)
{
unsigned int ioaddr = sa_info->ioaddr;
int i;
for (i = 0; i < 6; i++) {
if (sa_info->reg_nr > 15) {
sa_info->reg_nr = 8;
sa_info->page_nr++;
SelectPage(sa_info->page_nr);
}
if (sa_info->mohawk)
PutByte(sa_info->reg_nr++, addr[5 - i]);
else
PutByte(sa_info->reg_nr++, addr[i]);
}
}
static void set_addresses(struct net_device *dev)
{
unsigned int ioaddr = dev->base_addr;
struct local_info *lp = netdev_priv(dev);
struct netdev_hw_addr *ha;
struct set_address_info sa_info;
int i;
sa_info.reg_nr = 15 + 1;
sa_info.page_nr = 0x50 - 1;
sa_info.mohawk = lp->mohawk;
sa_info.ioaddr = ioaddr;
set_address(&sa_info, dev->dev_addr);
i = 0;
netdev_for_each_mc_addr(ha, dev) {
if (i++ == 9)
break;
set_address(&sa_info, ha->addr);
}
while (i++ < 9)
set_address(&sa_info, dev->dev_addr);
SelectPage(0);
}
static void
set_multicast_list(struct net_device *dev)
{
unsigned int ioaddr = dev->base_addr;
unsigned value;
SelectPage(0x42);
value = GetByte(XIRCREG42_SWC1) & 0xC0;
if (dev->flags & IFF_PROMISC) {
PutByte(XIRCREG42_SWC1, value | 0x06);
} else if (netdev_mc_count(dev) > 9 || (dev->flags & IFF_ALLMULTI)) {
PutByte(XIRCREG42_SWC1, value | 0x02);
} else if (!netdev_mc_empty(dev)) {
PutByte(XIRCREG42_SWC1, value | 0x01);
SelectPage(0x40);
PutByte(XIRCREG40_CMD0, Offline);
set_addresses(dev);
SelectPage(0x40);
PutByte(XIRCREG40_CMD0, EnableRecv | Online);
} else {
PutByte(XIRCREG42_SWC1, value | 0x00);
}
SelectPage(0);
}
static int
do_config(struct net_device *dev, struct ifmap *map)
{
struct local_info *local = netdev_priv(dev);
pr_debug("do_config(%p)\n", dev);
if (map->port != 255 && map->port != dev->if_port) {
if (map->port > 4)
return -EINVAL;
if (!map->port) {
local->probe_port = 1;
dev->if_port = 1;
} else {
local->probe_port = 0;
dev->if_port = map->port;
}
netdev_info(dev, "switching to %s port\n", if_names[dev->if_port]);
do_reset(dev,1);
}
return 0;
}
static int
do_open(struct net_device *dev)
{
struct local_info *lp = netdev_priv(dev);
struct pcmcia_device *link = lp->p_dev;
dev_dbg(&link->dev, "do_open(%p)\n", dev);
if (!pcmcia_dev_present(link))
return -ENODEV;
link->open++;
netif_start_queue(dev);
do_reset(dev,1);
return 0;
}
static void netdev_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
strlcpy(info->driver, "xirc2ps_cs", sizeof(info->driver));
snprintf(info->bus_info, sizeof(info->bus_info), "PCMCIA 0x%lx",
dev->base_addr);
}
static int
do_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct local_info *local = netdev_priv(dev);
unsigned int ioaddr = dev->base_addr;
struct mii_ioctl_data *data = if_mii(rq);
pr_debug("%s: ioctl(%-.6s, %#04x) %04x %04x %04x %04x\n",
dev->name, rq->ifr_ifrn.ifrn_name, cmd,
data->phy_id, data->reg_num, data->val_in, data->val_out);
if (!local->mohawk)
return -EOPNOTSUPP;
switch(cmd) {
case SIOCGMIIPHY:
data->phy_id = 0;
case SIOCGMIIREG:
data->val_out = mii_rd(ioaddr, data->phy_id & 0x1f,
data->reg_num & 0x1f);
break;
case SIOCSMIIREG:
mii_wr(ioaddr, data->phy_id & 0x1f, data->reg_num & 0x1f, data->val_in,
16);
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static void
hardreset(struct net_device *dev)
{
struct local_info *local = netdev_priv(dev);
unsigned int ioaddr = dev->base_addr;
SelectPage(4);
udelay(1);
PutByte(XIRCREG4_GPR1, 0);
msleep(40);
if (local->mohawk)
PutByte(XIRCREG4_GPR1, 1);
else
PutByte(XIRCREG4_GPR1, 1 | 4);
msleep(20);
}
static void
do_reset(struct net_device *dev, int full)
{
struct local_info *local = netdev_priv(dev);
unsigned int ioaddr = dev->base_addr;
unsigned value;
pr_debug("%s: do_reset(%p,%d)\n", dev? dev->name:"eth?", dev, full);
hardreset(dev);
PutByte(XIRCREG_CR, SoftReset);
msleep(20);
PutByte(XIRCREG_CR, 0);
msleep(40);
if (local->mohawk) {
SelectPage(4);
PutByte(XIRCREG4_GPR0, 0x0e);
}
msleep(500);
local->last_ptr_value = 0;
local->silicon = local->mohawk ? (GetByte(XIRCREG4_BOV) & 0x70) >> 4
: (GetByte(XIRCREG4_BOV) & 0x30) >> 4;
if (local->probe_port) {
if (!local->mohawk) {
SelectPage(4);
PutByte(XIRCREG4_GPR0, 4);
local->probe_port = 0;
}
} else if (dev->if_port == 2) {
SelectPage(0x42);
PutByte(XIRCREG42_SWC1, 0xC0);
} else {
SelectPage(0x42);
PutByte(XIRCREG42_SWC1, 0x80);
}
msleep(40);
#if 0
{
SelectPage(0);
value = GetByte(XIRCREG_ESR);
pr_debug("%s: ESR is: %#02x\n", dev->name, value);
}
#endif
SelectPage(1);
PutByte(XIRCREG1_IMR0, 0xff);
PutByte(XIRCREG1_IMR1, 1 );
value = GetByte(XIRCREG1_ECR);
#if 0
if (local->mohawk)
value |= DisableLinkPulse;
PutByte(XIRCREG1_ECR, value);
#endif
pr_debug("%s: ECR is: %#02x\n", dev->name, value);
SelectPage(0x42);
PutByte(XIRCREG42_SWC0, 0x20);
if (local->silicon != 1) {
SelectPage(2);
PutWord(XIRCREG2_RBS, 0x2000);
}
if (full)
set_addresses(dev);
SelectPage(0);
PutWord(XIRCREG0_DO, 0x2000);
SelectPage(0x40);
PutByte(XIRCREG40_RMASK0, 0xff);
PutByte(XIRCREG40_TMASK0, 0xff);
PutByte(XIRCREG40_TMASK1, 0xb0);
PutByte(XIRCREG40_RXST0, 0x00);
PutByte(XIRCREG40_TXST0, 0x00);
PutByte(XIRCREG40_TXST1, 0x00);
if (full && local->mohawk && init_mii(dev)) {
if (dev->if_port == 4 || local->dingo || local->new_mii) {
netdev_info(dev, "MII selected\n");
SelectPage(2);
PutByte(XIRCREG2_MSR, GetByte(XIRCREG2_MSR) | 0x08);
msleep(20);
} else {
netdev_info(dev, "MII detected; using 10mbs\n");
SelectPage(0x42);
if (dev->if_port == 2)
PutByte(XIRCREG42_SWC1, 0xC0);
else
PutByte(XIRCREG42_SWC1, 0x80);
msleep(40);
}
if (full_duplex)
PutByte(XIRCREG1_ECR, GetByte(XIRCREG1_ECR | FullDuplex));
} else {
SelectPage(0);
value = GetByte(XIRCREG_ESR);
dev->if_port = (value & MediaSelect) ? 1 : 2;
}
SelectPage(2);
if (dev->if_port == 1 || dev->if_port == 4)
PutByte(XIRCREG2_LED, 0x3b);
else
PutByte(XIRCREG2_LED, 0x3a);
if (local->dingo)
PutByte(0x0b, 0x04);
if (full) {
set_multicast_list(dev);
SelectPage(0x40);
PutByte(XIRCREG40_CMD0, EnableRecv | Online);
}
SelectPage(1);
PutByte(XIRCREG1_IMR0, 0xff);
udelay(1);
SelectPage(0);
PutByte(XIRCREG_CR, EnableIntr);
if (local->modem && !local->dingo) {
if (!(GetByte(0x10) & 0x01))
PutByte(0x10, 0x11);
}
if (full)
netdev_info(dev, "media %s, silicon revision %d\n",
if_names[dev->if_port], local->silicon);
SelectPage(0);
}
static int
init_mii(struct net_device *dev)
{
struct local_info *local = netdev_priv(dev);
unsigned int ioaddr = dev->base_addr;
unsigned control, status, linkpartner;
int i;
if (if_port == 4 || if_port == 1) {
dev->if_port = if_port;
local->probe_port = 0;
return 1;
}
status = mii_rd(ioaddr, 0, 1);
if ((status & 0xff00) != 0x7800)
return 0;
local->new_mii = (mii_rd(ioaddr, 0, 2) != 0xffff);
if (local->probe_port)
control = 0x1000;
else if (dev->if_port == 4)
control = 0x2000;
else
control = 0x0000;
mii_wr(ioaddr, 0, 0, control, 16);
udelay(100);
control = mii_rd(ioaddr, 0, 0);
if (control & 0x0400) {
netdev_notice(dev, "can't take PHY out of isolation mode\n");
local->probe_port = 0;
return 0;
}
if (local->probe_port) {
for (i=0; i < 35; i++) {
msleep(100);
status = mii_rd(ioaddr, 0, 1);
if ((status & 0x0020) && (status & 0x0004))
break;
}
if (!(status & 0x0020)) {
netdev_info(dev, "autonegotiation failed; using 10mbs\n");
if (!local->new_mii) {
control = 0x0000;
mii_wr(ioaddr, 0, 0, control, 16);
udelay(100);
SelectPage(0);
dev->if_port = (GetByte(XIRCREG_ESR) & MediaSelect) ? 1 : 2;
}
} else {
linkpartner = mii_rd(ioaddr, 0, 5);
netdev_info(dev, "MII link partner: %04x\n", linkpartner);
if (linkpartner & 0x0080) {
dev->if_port = 4;
} else
dev->if_port = 1;
}
}
return 1;
}
static void
do_powerdown(struct net_device *dev)
{
unsigned int ioaddr = dev->base_addr;
pr_debug("do_powerdown(%p)\n", dev);
SelectPage(4);
PutByte(XIRCREG4_GPR1, 0);
SelectPage(0);
}
static int
do_stop(struct net_device *dev)
{
unsigned int ioaddr = dev->base_addr;
struct local_info *lp = netdev_priv(dev);
struct pcmcia_device *link = lp->p_dev;
dev_dbg(&link->dev, "do_stop(%p)\n", dev);
if (!link)
return -ENODEV;
netif_stop_queue(dev);
SelectPage(0);
PutByte(XIRCREG_CR, 0);
SelectPage(0x01);
PutByte(XIRCREG1_IMR0, 0x00);
SelectPage(4);
PutByte(XIRCREG4_GPR1, 0);
SelectPage(0);
link->open--;
return 0;
}
static int __init setup_xirc2ps_cs(char *str)
{
int ints[10] = { -1 };
str = get_options(str, 9, ints);
#define MAYBE_SET(X,Y) if (ints[0] >= Y && ints[Y] != -1) { X = ints[Y]; }
MAYBE_SET(if_port, 3);
MAYBE_SET(full_duplex, 4);
MAYBE_SET(do_sound, 5);
MAYBE_SET(lockup_hack, 6);
#undef MAYBE_SET
return 1;
}
