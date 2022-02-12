static int __init arcnet_init(void)
{
int count;
arcnet_debug = debug;
pr_info("arcnet loaded\n");
arc_raw_proto = arc_proto_default = arc_bcast_proto = &arc_proto_null;
for (count = 0; count < 256; count++)
arc_proto_map[count] = arc_proto_default;
if (BUGLVL(D_DURING))
pr_info("struct sizes: %zd %zd %zd %zd %zd\n",
sizeof(struct arc_hardware),
sizeof(struct arc_rfc1201),
sizeof(struct arc_rfc1051),
sizeof(struct arc_eth_encap),
sizeof(struct archdr));
return 0;
}
static void __exit arcnet_exit(void)
{
}
void arcnet_dump_skb(struct net_device *dev,
struct sk_buff *skb, char *desc)
{
char hdr[32];
snprintf(hdr, sizeof(hdr), "%6s:%s skb->data:", dev->name, desc);
print_hex_dump(KERN_DEBUG, hdr, DUMP_PREFIX_OFFSET,
16, 1, skb->data, skb->len, true);
}
static void arcnet_dump_packet(struct net_device *dev, int bufnum,
char *desc, int take_arcnet_lock)
{
struct arcnet_local *lp = netdev_priv(dev);
int i, length;
unsigned long flags = 0;
static uint8_t buf[512];
char hdr[32];
if (take_arcnet_lock)
spin_lock_irqsave(&lp->lock, flags);
lp->hw.copy_from_card(dev, bufnum, 0, buf, 512);
if (take_arcnet_lock)
spin_unlock_irqrestore(&lp->lock, flags);
length = (buf[2] ? 256 : 512);
snprintf(hdr, sizeof(hdr), "%6s:%s packet dump:", dev->name, desc);
print_hex_dump(KERN_DEBUG, hdr, DUMP_PREFIX_OFFSET,
16, 1, buf, length, true);
}
void arcnet_led_event(struct net_device *dev, enum arcnet_led_event event)
{
struct arcnet_local *lp = netdev_priv(dev);
unsigned long led_delay = 350;
unsigned long tx_delay = 50;
switch (event) {
case ARCNET_LED_EVENT_RECON:
led_trigger_blink_oneshot(lp->recon_led_trig,
&led_delay, &led_delay, 0);
break;
case ARCNET_LED_EVENT_OPEN:
led_trigger_event(lp->tx_led_trig, LED_OFF);
led_trigger_event(lp->recon_led_trig, LED_OFF);
break;
case ARCNET_LED_EVENT_STOP:
led_trigger_event(lp->tx_led_trig, LED_OFF);
led_trigger_event(lp->recon_led_trig, LED_OFF);
break;
case ARCNET_LED_EVENT_TX:
led_trigger_blink_oneshot(lp->tx_led_trig,
&tx_delay, &tx_delay, 0);
break;
}
}
static void arcnet_led_release(struct device *gendev, void *res)
{
struct arcnet_local *lp = netdev_priv(to_net_dev(gendev));
led_trigger_unregister_simple(lp->tx_led_trig);
led_trigger_unregister_simple(lp->recon_led_trig);
}
void devm_arcnet_led_init(struct net_device *netdev, int index, int subid)
{
struct arcnet_local *lp = netdev_priv(netdev);
void *res;
res = devres_alloc(arcnet_led_release, 0, GFP_KERNEL);
if (!res) {
netdev_err(netdev, "cannot register LED triggers\n");
return;
}
snprintf(lp->tx_led_trig_name, sizeof(lp->tx_led_trig_name),
"arc%d-%d-tx", index, subid);
snprintf(lp->recon_led_trig_name, sizeof(lp->recon_led_trig_name),
"arc%d-%d-recon", index, subid);
led_trigger_register_simple(lp->tx_led_trig_name,
&lp->tx_led_trig);
led_trigger_register_simple(lp->recon_led_trig_name,
&lp->recon_led_trig);
devres_add(&netdev->dev, res);
}
void arcnet_unregister_proto(struct ArcProto *proto)
{
int count;
if (arc_proto_default == proto)
arc_proto_default = &arc_proto_null;
if (arc_bcast_proto == proto)
arc_bcast_proto = arc_proto_default;
if (arc_raw_proto == proto)
arc_raw_proto = arc_proto_default;
for (count = 0; count < 256; count++) {
if (arc_proto_map[count] == proto)
arc_proto_map[count] = arc_proto_default;
}
}
static void release_arcbuf(struct net_device *dev, int bufnum)
{
struct arcnet_local *lp = netdev_priv(dev);
int i;
lp->buf_queue[lp->first_free_buf++] = bufnum;
lp->first_free_buf %= 5;
if (BUGLVL(D_DURING)) {
arc_printk(D_DURING, dev, "release_arcbuf: freed #%d; buffer queue is now: ",
bufnum);
for (i = lp->next_buf; i != lp->first_free_buf; i = (i + 1) % 5)
arc_cont(D_DURING, "#%d ", lp->buf_queue[i]);
arc_cont(D_DURING, "\n");
}
}
static int get_arcbuf(struct net_device *dev)
{
struct arcnet_local *lp = netdev_priv(dev);
int buf = -1, i;
if (!atomic_dec_and_test(&lp->buf_lock)) {
arc_printk(D_NORMAL, dev, "get_arcbuf: overlap (%d)!\n",
lp->buf_lock.counter);
} else {
if (lp->next_buf >= 5)
lp->next_buf -= 5;
if (lp->next_buf == lp->first_free_buf) {
arc_printk(D_NORMAL, dev, "get_arcbuf: BUG: no buffers are available??\n");
} else {
buf = lp->buf_queue[lp->next_buf++];
lp->next_buf %= 5;
}
}
if (BUGLVL(D_DURING)) {
arc_printk(D_DURING, dev, "get_arcbuf: got #%d; buffer queue is now: ",
buf);
for (i = lp->next_buf; i != lp->first_free_buf; i = (i + 1) % 5)
arc_cont(D_DURING, "#%d ", lp->buf_queue[i]);
arc_cont(D_DURING, "\n");
}
atomic_inc(&lp->buf_lock);
return buf;
}
static int choose_mtu(void)
{
int count, mtu = 65535;
for (count = 0; count < 256; count++) {
if (arc_proto_map[count] != &arc_proto_null &&
arc_proto_map[count]->mtu < mtu) {
mtu = arc_proto_map[count]->mtu;
}
}
return mtu == 65535 ? XMTU : mtu;
}
static void arcdev_setup(struct net_device *dev)
{
dev->type = ARPHRD_ARCNET;
dev->netdev_ops = &arcnet_netdev_ops;
dev->header_ops = &arcnet_header_ops;
dev->hard_header_len = sizeof(struct arc_hardware);
dev->mtu = choose_mtu();
dev->addr_len = ARCNET_ALEN;
dev->tx_queue_len = 100;
dev->broadcast[0] = 0x00;
dev->watchdog_timeo = TX_TIMEOUT;
dev->flags = IFF_BROADCAST;
}
static void arcnet_timer(unsigned long data)
{
struct net_device *dev = (struct net_device *)data;
if (!netif_carrier_ok(dev)) {
netif_carrier_on(dev);
netdev_info(dev, "link up\n");
}
}
struct net_device *alloc_arcdev(const char *name)
{
struct net_device *dev;
dev = alloc_netdev(sizeof(struct arcnet_local),
name && *name ? name : "arc%d", NET_NAME_UNKNOWN,
arcdev_setup);
if (dev) {
struct arcnet_local *lp = netdev_priv(dev);
spin_lock_init(&lp->lock);
init_timer(&lp->timer);
lp->timer.data = (unsigned long) dev;
lp->timer.function = arcnet_timer;
}
return dev;
}
int arcnet_open(struct net_device *dev)
{
struct arcnet_local *lp = netdev_priv(dev);
int count, newmtu, error;
arc_printk(D_INIT, dev, "opened.");
if (!try_module_get(lp->hw.owner))
return -ENODEV;
if (BUGLVL(D_PROTO)) {
arc_printk(D_PROTO, dev, "protocol map (default is '%c'): ",
arc_proto_default->suffix);
for (count = 0; count < 256; count++)
arc_cont(D_PROTO, "%c", arc_proto_map[count]->suffix);
arc_cont(D_PROTO, "\n");
}
arc_printk(D_INIT, dev, "arcnet_open: resetting card.\n");
error = -ENODEV;
if (lp->hw.reset(dev, 0) && lp->hw.reset(dev, 1))
goto out_module_put;
newmtu = choose_mtu();
if (newmtu < dev->mtu)
dev->mtu = newmtu;
arc_printk(D_INIT, dev, "arcnet_open: mtu: %d.\n", dev->mtu);
memset(lp->default_proto, 0, sizeof(lp->default_proto));
for (count = 0; count < 256; count++) {
if (arc_proto_map[count] == arc_bcast_proto) {
lp->default_proto[0] = count;
break;
}
}
atomic_set(&lp->buf_lock, 1);
lp->next_buf = lp->first_free_buf = 0;
release_arcbuf(dev, 0);
release_arcbuf(dev, 1);
release_arcbuf(dev, 2);
release_arcbuf(dev, 3);
lp->cur_tx = lp->next_tx = -1;
lp->cur_rx = -1;
lp->rfc1201.sequence = 1;
if (lp->hw.open)
lp->hw.open(dev);
if (dev->dev_addr[0] == 0)
arc_printk(D_NORMAL, dev, "WARNING! Station address 00 is reserved for broadcasts!\n");
else if (dev->dev_addr[0] == 255)
arc_printk(D_NORMAL, dev, "WARNING! Station address FF may confuse DOS networking programs!\n");
arc_printk(D_DEBUG, dev, "%s: %d: %s\n", __FILE__, __LINE__, __func__);
if (lp->hw.status(dev) & RESETflag) {
arc_printk(D_DEBUG, dev, "%s: %d: %s\n",
__FILE__, __LINE__, __func__);
lp->hw.command(dev, CFLAGScmd | RESETclear);
}
arc_printk(D_DEBUG, dev, "%s: %d: %s\n", __FILE__, __LINE__, __func__);
lp->hw.intmask(dev, 0);
udelay(1);
arc_printk(D_DEBUG, dev, "%s: %d: %s\n", __FILE__, __LINE__, __func__);
lp->intmask = NORXflag | RECONflag;
lp->hw.intmask(dev, lp->intmask);
arc_printk(D_DEBUG, dev, "%s: %d: %s\n", __FILE__, __LINE__, __func__);
netif_carrier_off(dev);
netif_start_queue(dev);
mod_timer(&lp->timer, jiffies + msecs_to_jiffies(1000));
arcnet_led_event(dev, ARCNET_LED_EVENT_OPEN);
return 0;
out_module_put:
module_put(lp->hw.owner);
return error;
}
int arcnet_close(struct net_device *dev)
{
struct arcnet_local *lp = netdev_priv(dev);
arcnet_led_event(dev, ARCNET_LED_EVENT_STOP);
del_timer_sync(&lp->timer);
netif_stop_queue(dev);
netif_carrier_off(dev);
lp->hw.intmask(dev, 0);
lp->hw.command(dev, NOTXcmd);
lp->hw.command(dev, NORXcmd);
mdelay(1);
lp->hw.close(dev);
module_put(lp->hw.owner);
return 0;
}
static int arcnet_header(struct sk_buff *skb, struct net_device *dev,
unsigned short type, const void *daddr,
const void *saddr, unsigned len)
{
const struct arcnet_local *lp = netdev_priv(dev);
uint8_t _daddr, proto_num;
struct ArcProto *proto;
arc_printk(D_DURING, dev,
"create header from %d to %d; protocol %d (%Xh); size %u.\n",
saddr ? *(uint8_t *)saddr : -1,
daddr ? *(uint8_t *)daddr : -1,
type, type, len);
if (skb->len != 0 && len != skb->len)
arc_printk(D_NORMAL, dev, "arcnet_header: Yikes! skb->len(%d) != len(%d)!\n",
skb->len, len);
if (type == ETH_P_ARCNET) {
proto = arc_raw_proto;
arc_printk(D_DEBUG, dev, "arc_raw_proto used. proto='%c'\n",
proto->suffix);
_daddr = daddr ? *(uint8_t *)daddr : 0;
} else if (!daddr) {
*(uint16_t *)skb_push(skb, 2) = type;
if (skb->network_header - skb->mac_header != 2)
arc_printk(D_NORMAL, dev, "arcnet_header: Yikes! diff (%u) is not 2!\n",
skb->network_header - skb->mac_header);
return -2;
} else {
_daddr = *(uint8_t *)daddr;
proto_num = lp->default_proto[_daddr];
proto = arc_proto_map[proto_num];
arc_printk(D_DURING, dev, "building header for %02Xh using protocol '%c'\n",
proto_num, proto->suffix);
if (proto == &arc_proto_null && arc_bcast_proto != proto) {
arc_printk(D_DURING, dev, "actually, let's use '%c' instead.\n",
arc_bcast_proto->suffix);
proto = arc_bcast_proto;
}
}
return proto->build_header(skb, dev, type, _daddr);
}
netdev_tx_t arcnet_send_packet(struct sk_buff *skb,
struct net_device *dev)
{
struct arcnet_local *lp = netdev_priv(dev);
struct archdr *pkt;
struct arc_rfc1201 *soft;
struct ArcProto *proto;
int txbuf;
unsigned long flags;
int retval;
arc_printk(D_DURING, dev,
"transmit requested (status=%Xh, txbufs=%d/%d, len=%d, protocol %x)\n",
lp->hw.status(dev), lp->cur_tx, lp->next_tx, skb->len, skb->protocol);
pkt = (struct archdr *)skb->data;
soft = &pkt->soft.rfc1201;
proto = arc_proto_map[soft->proto];
arc_printk(D_SKB_SIZE, dev, "skb: transmitting %d bytes to %02X\n",
skb->len, pkt->hard.dest);
if (BUGLVL(D_SKB))
arcnet_dump_skb(dev, skb, "tx");
if (skb->len - ARC_HDR_SIZE > XMTU && !proto->continue_tx) {
arc_printk(D_NORMAL, dev, "fixme: packet too large: compensating badly!\n");
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
netif_stop_queue(dev);
spin_lock_irqsave(&lp->lock, flags);
lp->hw.intmask(dev, 0);
if (lp->next_tx == -1)
txbuf = get_arcbuf(dev);
else
txbuf = -1;
if (txbuf != -1) {
if (proto->prepare_tx(dev, pkt, skb->len, txbuf) &&
!proto->ack_tx) {
dev->stats.tx_bytes += skb->len;
dev_kfree_skb(skb);
} else {
lp->outgoing.proto = proto;
lp->outgoing.skb = skb;
lp->outgoing.pkt = pkt;
if (proto->continue_tx &&
proto->continue_tx(dev, txbuf)) {
arc_printk(D_NORMAL, dev,
"bug! continue_tx finished the first time! (proto='%c')\n",
proto->suffix);
}
}
retval = NETDEV_TX_OK;
lp->next_tx = txbuf;
} else {
retval = NETDEV_TX_BUSY;
}
arc_printk(D_DEBUG, dev, "%s: %d: %s, status: %x\n",
__FILE__, __LINE__, __func__, lp->hw.status(dev));
lp->hw.intmask(dev, 0);
arc_printk(D_DEBUG, dev, "%s: %d: %s\n", __FILE__, __LINE__, __func__);
lp->intmask |= TXFREEflag | EXCNAKflag;
lp->hw.intmask(dev, lp->intmask);
arc_printk(D_DEBUG, dev, "%s: %d: %s, status: %x\n",
__FILE__, __LINE__, __func__, lp->hw.status(dev));
arcnet_led_event(dev, ARCNET_LED_EVENT_TX);
spin_unlock_irqrestore(&lp->lock, flags);
return retval;
}
static int go_tx(struct net_device *dev)
{
struct arcnet_local *lp = netdev_priv(dev);
arc_printk(D_DURING, dev, "go_tx: status=%Xh, intmask=%Xh, next_tx=%d, cur_tx=%d\n",
lp->hw.status(dev), lp->intmask, lp->next_tx, lp->cur_tx);
if (lp->cur_tx != -1 || lp->next_tx == -1)
return 0;
if (BUGLVL(D_TX))
arcnet_dump_packet(dev, lp->next_tx, "go_tx", 0);
lp->cur_tx = lp->next_tx;
lp->next_tx = -1;
lp->hw.command(dev, TXcmd | (lp->cur_tx << 3));
dev->stats.tx_packets++;
lp->lasttrans_dest = lp->lastload_dest;
lp->lastload_dest = 0;
lp->excnak_pending = 0;
lp->intmask |= TXFREEflag | EXCNAKflag;
return 1;
}
void arcnet_timeout(struct net_device *dev)
{
unsigned long flags;
struct arcnet_local *lp = netdev_priv(dev);
int status = lp->hw.status(dev);
char *msg;
spin_lock_irqsave(&lp->lock, flags);
if (status & TXFREEflag) {
msg = " - missed IRQ?";
} else {
msg = "";
dev->stats.tx_aborted_errors++;
lp->timed_out = 1;
lp->hw.command(dev, NOTXcmd | (lp->cur_tx << 3));
}
dev->stats.tx_errors++;
lp->hw.intmask(dev, 0);
lp->intmask |= TXFREEflag | EXCNAKflag;
lp->hw.intmask(dev, lp->intmask);
spin_unlock_irqrestore(&lp->lock, flags);
if (time_after(jiffies, lp->last_timeout + 10 * HZ)) {
arc_printk(D_EXTRA, dev, "tx timed out%s (status=%Xh, intmask=%Xh, dest=%02Xh)\n",
msg, status, lp->intmask, lp->lasttrans_dest);
lp->last_timeout = jiffies;
}
if (lp->cur_tx == -1)
netif_wake_queue(dev);
}
irqreturn_t arcnet_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct arcnet_local *lp;
int recbuf, status, diagstatus, didsomething, boguscount;
int retval = IRQ_NONE;
arc_printk(D_DURING, dev, "\n");
arc_printk(D_DURING, dev, "in arcnet_interrupt\n");
lp = netdev_priv(dev);
BUG_ON(!lp);
spin_lock(&lp->lock);
if (!netif_running(dev)) {
if (lp->hw.status(dev) & RESETflag)
lp->hw.command(dev, CFLAGScmd | RESETclear);
lp->hw.intmask(dev, 0);
spin_unlock(&lp->lock);
return retval;
}
arc_printk(D_DURING, dev, "in arcnet_inthandler (status=%Xh, intmask=%Xh)\n",
lp->hw.status(dev), lp->intmask);
boguscount = 5;
do {
status = lp->hw.status(dev);
diagstatus = (status >> 8) & 0xFF;
arc_printk(D_DEBUG, dev, "%s: %d: %s: status=%x\n",
__FILE__, __LINE__, __func__, status);
didsomething = 0;
if (status & RESETflag) {
arc_printk(D_NORMAL, dev, "spurious reset (status=%Xh)\n",
status);
arcnet_close(dev);
arcnet_open(dev);
break;
}
recbuf = -1;
if (status & lp->intmask & NORXflag) {
recbuf = lp->cur_rx;
arc_printk(D_DURING, dev, "Buffer #%d: receive irq (status=%Xh)\n",
recbuf, status);
lp->cur_rx = get_arcbuf(dev);
if (lp->cur_rx != -1) {
arc_printk(D_DURING, dev, "enabling receive to buffer #%d\n",
lp->cur_rx);
lp->hw.command(dev, RXcmd | (lp->cur_rx << 3) | RXbcasts);
}
didsomething++;
}
if ((diagstatus & EXCNAKflag)) {
arc_printk(D_DURING, dev, "EXCNAK IRQ (diagstat=%Xh)\n",
diagstatus);
lp->hw.command(dev, NOTXcmd);
lp->excnak_pending = 1;
lp->hw.command(dev, EXCNAKclear);
lp->intmask &= ~(EXCNAKflag);
didsomething++;
}
if ((status & lp->intmask & TXFREEflag) || lp->timed_out) {
lp->intmask &= ~(TXFREEflag | EXCNAKflag);
arc_printk(D_DURING, dev, "TX IRQ (stat=%Xh)\n",
status);
if (lp->cur_tx != -1 && !lp->timed_out) {
if (!(status & TXACKflag)) {
if (lp->lasttrans_dest != 0) {
arc_printk(D_EXTRA, dev,
"transmit was not acknowledged! (status=%Xh, dest=%02Xh)\n",
status,
lp->lasttrans_dest);
dev->stats.tx_errors++;
dev->stats.tx_carrier_errors++;
} else {
arc_printk(D_DURING, dev,
"broadcast was not acknowledged; that's normal (status=%Xh, dest=%02Xh)\n",
status,
lp->lasttrans_dest);
}
}
if (lp->outgoing.proto &&
lp->outgoing.proto->ack_tx) {
int ackstatus;
if (status & TXACKflag)
ackstatus = 2;
else if (lp->excnak_pending)
ackstatus = 1;
else
ackstatus = 0;
lp->outgoing.proto
->ack_tx(dev, ackstatus);
}
}
if (lp->cur_tx != -1)
release_arcbuf(dev, lp->cur_tx);
lp->cur_tx = -1;
lp->timed_out = 0;
didsomething++;
go_tx(dev);
if (lp->outgoing.proto &&
lp->outgoing.proto->continue_tx) {
int txbuf = get_arcbuf(dev);
if (txbuf != -1) {
if (lp->outgoing.proto->continue_tx(dev, txbuf)) {
dev->stats.tx_bytes += lp->outgoing.skb->len;
if (!lp->outgoing.proto->ack_tx) {
dev_kfree_skb_irq(lp->outgoing.skb);
lp->outgoing.proto = NULL;
}
}
lp->next_tx = txbuf;
}
}
if (lp->cur_tx == -1)
netif_wake_queue(dev);
}
if (recbuf != -1) {
if (BUGLVL(D_RX))
arcnet_dump_packet(dev, recbuf, "rx irq", 0);
arcnet_rx(dev, recbuf);
release_arcbuf(dev, recbuf);
didsomething++;
}
if (status & lp->intmask & RECONflag) {
lp->hw.command(dev, CFLAGScmd | CONFIGclear);
dev->stats.tx_carrier_errors++;
arc_printk(D_RECON, dev, "Network reconfiguration detected (status=%Xh)\n",
status);
if (netif_carrier_ok(dev)) {
netif_carrier_off(dev);
netdev_info(dev, "link down\n");
}
mod_timer(&lp->timer, jiffies + msecs_to_jiffies(1000));
arcnet_led_event(dev, ARCNET_LED_EVENT_RECON);
if (diagstatus & 0x80)
arc_printk(D_RECON, dev, "Put out that recon myself\n");
if (!lp->first_recon || !lp->last_recon ||
time_after(jiffies, lp->last_recon + HZ * 10)) {
if (lp->network_down)
arc_printk(D_NORMAL, dev, "reconfiguration detected: cabling restored?\n");
lp->first_recon = lp->last_recon = jiffies;
lp->num_recons = lp->network_down = 0;
arc_printk(D_DURING, dev, "recon: clearing counters.\n");
} else {
lp->last_recon = jiffies;
lp->num_recons++;
arc_printk(D_DURING, dev, "recon: counter=%d, time=%lds, net=%d\n",
lp->num_recons,
(lp->last_recon - lp->first_recon) / HZ,
lp->network_down);
if (!lp->network_down &&
(lp->last_recon - lp->first_recon) <= HZ * 60 &&
lp->num_recons >= RECON_THRESHOLD) {
lp->network_down = 1;
arc_printk(D_NORMAL, dev, "many reconfigurations detected: cabling problem?\n");
} else if (!lp->network_down &&
lp->last_recon - lp->first_recon > HZ * 60) {
lp->first_recon = lp->last_recon;
lp->num_recons = 1;
}
}
} else if (lp->network_down &&
time_after(jiffies, lp->last_recon + HZ * 10)) {
if (lp->network_down)
arc_printk(D_NORMAL, dev, "cabling restored?\n");
lp->first_recon = lp->last_recon = 0;
lp->num_recons = lp->network_down = 0;
arc_printk(D_DURING, dev, "not recon: clearing counters anyway.\n");
netif_carrier_on(dev);
}
if (didsomething)
retval |= IRQ_HANDLED;
} while (--boguscount && didsomething);
arc_printk(D_DURING, dev, "arcnet_interrupt complete (status=%Xh, count=%d)\n",
lp->hw.status(dev), boguscount);
arc_printk(D_DURING, dev, "\n");
lp->hw.intmask(dev, 0);
udelay(1);
lp->hw.intmask(dev, lp->intmask);
spin_unlock(&lp->lock);
return retval;
}
static void arcnet_rx(struct net_device *dev, int bufnum)
{
struct arcnet_local *lp = netdev_priv(dev);
struct archdr pkt;
struct arc_rfc1201 *soft;
int length, ofs;
soft = &pkt.soft.rfc1201;
lp->hw.copy_from_card(dev, bufnum, 0, &pkt, ARC_HDR_SIZE);
if (pkt.hard.offset[0]) {
ofs = pkt.hard.offset[0];
length = 256 - ofs;
} else {
ofs = pkt.hard.offset[1];
length = 512 - ofs;
}
if (sizeof(pkt.soft) <= length) {
lp->hw.copy_from_card(dev, bufnum, ofs, soft, sizeof(pkt.soft));
} else {
memset(&pkt.soft, 0, sizeof(pkt.soft));
lp->hw.copy_from_card(dev, bufnum, ofs, soft, length);
}
arc_printk(D_DURING, dev, "Buffer #%d: received packet from %02Xh to %02Xh (%d+4 bytes)\n",
bufnum, pkt.hard.source, pkt.hard.dest, length);
dev->stats.rx_packets++;
dev->stats.rx_bytes += length + ARC_HDR_SIZE;
if (arc_proto_map[soft->proto]->is_ip) {
if (BUGLVL(D_PROTO)) {
struct ArcProto
*oldp = arc_proto_map[lp->default_proto[pkt.hard.source]],
*newp = arc_proto_map[soft->proto];
if (oldp != newp) {
arc_printk(D_PROTO, dev,
"got protocol %02Xh; encap for host %02Xh is now '%c' (was '%c')\n",
soft->proto, pkt.hard.source,
newp->suffix, oldp->suffix);
}
}
lp->default_proto[0] = soft->proto;
lp->default_proto[pkt.hard.source] = soft->proto;
}
arc_proto_map[soft->proto]->rx(dev, bufnum, &pkt, length);
}
static void null_rx(struct net_device *dev, int bufnum,
struct archdr *pkthdr, int length)
{
arc_printk(D_PROTO, dev,
"rx: don't know how to deal with proto %02Xh from host %02Xh.\n",
pkthdr->soft.rfc1201.proto, pkthdr->hard.source);
}
static int null_build_header(struct sk_buff *skb, struct net_device *dev,
unsigned short type, uint8_t daddr)
{
struct arcnet_local *lp = netdev_priv(dev);
arc_printk(D_PROTO, dev,
"tx: can't build header for encap %02Xh; load a protocol driver.\n",
lp->default_proto[daddr]);
return 0;
}
static int null_prepare_tx(struct net_device *dev, struct archdr *pkt,
int length, int bufnum)
{
struct arcnet_local *lp = netdev_priv(dev);
struct arc_hardware newpkt;
arc_printk(D_PROTO, dev, "tx: no encap for this host; load a protocol driver.\n");
newpkt.source = newpkt.dest = dev->dev_addr[0];
newpkt.offset[0] = 0xFF;
lp->hw.copy_to_card(dev, bufnum, 0, &newpkt, ARC_HDR_SIZE);
return 1;
}
