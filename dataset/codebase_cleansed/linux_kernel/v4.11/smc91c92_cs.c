static int smc91c92_probe(struct pcmcia_device *link)
{
struct smc_private *smc;
struct net_device *dev;
dev_dbg(&link->dev, "smc91c92_attach()\n");
dev = alloc_etherdev(sizeof(struct smc_private));
if (!dev)
return -ENOMEM;
smc = netdev_priv(dev);
smc->p_dev = link;
link->priv = dev;
spin_lock_init(&smc->lock);
dev->netdev_ops = &smc_netdev_ops;
dev->ethtool_ops = &ethtool_ops;
dev->watchdog_timeo = TX_TIMEOUT;
smc->mii_if.dev = dev;
smc->mii_if.mdio_read = mdio_read;
smc->mii_if.mdio_write = mdio_write;
smc->mii_if.phy_id_mask = 0x1f;
smc->mii_if.reg_num_mask = 0x1f;
return smc91c92_config(link);
}
static void smc91c92_detach(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
dev_dbg(&link->dev, "smc91c92_detach\n");
unregister_netdev(dev);
smc91c92_release(link);
free_netdev(dev);
}
static int cvt_ascii_address(struct net_device *dev, char *s)
{
int i, j, da, c;
if (strlen(s) != 12)
return -1;
for (i = 0; i < 6; i++) {
da = 0;
for (j = 0; j < 2; j++) {
c = *s++;
da <<= 4;
da += ((c >= '0') && (c <= '9')) ?
(c - '0') : ((c & 0x0f) + 9);
}
dev->dev_addr[i] = da;
}
return 0;
}
static int mhz_3288_power(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
struct smc_private *smc = netdev_priv(dev);
u_char tmp;
readb(smc->base+MEGAHERTZ_ISR);
udelay(5);
readb(smc->base+MEGAHERTZ_ISR);
mdelay(200);
tmp = readb(smc->base + link->config_base + CISREG_COR);
udelay(5);
writeb(tmp, smc->base + link->config_base + CISREG_COR);
return 0;
}
static int mhz_mfc_config_check(struct pcmcia_device *p_dev, void *priv_data)
{
int k;
p_dev->io_lines = 16;
p_dev->resource[1]->start = p_dev->resource[0]->start;
p_dev->resource[1]->end = 8;
p_dev->resource[1]->flags &= ~IO_DATA_PATH_WIDTH;
p_dev->resource[1]->flags |= IO_DATA_PATH_WIDTH_8;
p_dev->resource[0]->end = 16;
p_dev->resource[0]->flags &= ~IO_DATA_PATH_WIDTH;
p_dev->resource[0]->flags |= IO_DATA_PATH_WIDTH_AUTO;
for (k = 0; k < 0x400; k += 0x10) {
if (k & 0x80)
continue;
p_dev->resource[0]->start = k ^ 0x300;
if (!pcmcia_request_io(p_dev))
return 0;
}
return -ENODEV;
}
static int mhz_mfc_config(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
struct smc_private *smc = netdev_priv(dev);
unsigned int offset;
int i;
link->config_flags |= CONF_ENABLE_SPKR | CONF_ENABLE_IRQ |
CONF_AUTO_SET_IO;
if (pcmcia_loop_config(link, mhz_mfc_config_check, NULL))
return -ENODEV;
dev->base_addr = link->resource[0]->start;
link->resource[2]->flags = WIN_DATA_WIDTH_8|WIN_MEMORY_TYPE_AM|WIN_ENABLE;
link->resource[2]->start = link->resource[2]->end = 0;
i = pcmcia_request_window(link, link->resource[2], 0);
if (i != 0)
return -ENODEV;
smc->base = ioremap(link->resource[2]->start,
resource_size(link->resource[2]));
offset = (smc->manfid == MANFID_MOTOROLA) ? link->config_base : 0;
i = pcmcia_map_mem_page(link, link->resource[2], offset);
if ((i == 0) &&
(smc->manfid == MANFID_MEGAHERTZ) &&
(smc->cardid == PRODID_MEGAHERTZ_EM3288))
mhz_3288_power(link);
return 0;
}
static int pcmcia_get_versmac(struct pcmcia_device *p_dev,
tuple_t *tuple,
void *priv)
{
struct net_device *dev = priv;
cisparse_t parse;
u8 *buf;
if (pcmcia_parse_tuple(tuple, &parse))
return -EINVAL;
buf = parse.version_1.str + parse.version_1.ofs[3];
if ((parse.version_1.ns > 3) && (cvt_ascii_address(dev, buf) == 0))
return 0;
return -EINVAL;
}
static int mhz_setup(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
size_t len;
u8 *buf;
int rc;
if ((link->prod_id[3]) &&
(cvt_ascii_address(dev, link->prod_id[3]) == 0))
return 0;
if (!pcmcia_loop_tuple(link, CISTPL_VERS_1, pcmcia_get_versmac, dev))
return 0;
rc = -1;
len = pcmcia_get_tuple(link, 0x81, &buf);
if (buf && len >= 13) {
buf[12] = '\0';
if (cvt_ascii_address(dev, buf) == 0)
rc = 0;
}
kfree(buf);
return rc;
}
static void mot_config(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
struct smc_private *smc = netdev_priv(dev);
unsigned int ioaddr = dev->base_addr;
unsigned int iouart = link->resource[1]->start;
writeb(iouart & 0xff, smc->base + MOT_UART + CISREG_IOBASE_0);
writeb((iouart >> 8) & 0xff, smc->base + MOT_UART + CISREG_IOBASE_1);
writeb(MOT_NORMAL, smc->base + MOT_UART + CISREG_COR);
writeb(ioaddr & 0xff, smc->base + MOT_LAN + CISREG_IOBASE_0);
writeb((ioaddr >> 8) & 0xff, smc->base + MOT_LAN + CISREG_IOBASE_1);
writeb(MOT_NORMAL, smc->base + MOT_LAN + CISREG_COR);
mdelay(100);
}
static int mot_setup(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
unsigned int ioaddr = dev->base_addr;
int i, wait, loop;
u_int addr;
for (i = 0; i < 3; i++) {
SMC_SELECT_BANK(2);
outw(MOT_EEPROM + i, ioaddr + POINTER);
SMC_SELECT_BANK(1);
outw((CTL_RELOAD | CTL_EE_SELECT), ioaddr + CONTROL);
for (loop = wait = 0; loop < 200; loop++) {
udelay(10);
wait = ((CTL_RELOAD | CTL_STORE) & inw(ioaddr + CONTROL));
if (wait == 0) break;
}
if (wait)
return -1;
addr = inw(ioaddr + GENERAL);
dev->dev_addr[2*i] = addr & 0xff;
dev->dev_addr[2*i+1] = (addr >> 8) & 0xff;
}
return 0;
}
static int smc_configcheck(struct pcmcia_device *p_dev, void *priv_data)
{
p_dev->resource[0]->end = 16;
p_dev->resource[0]->flags &= ~IO_DATA_PATH_WIDTH;
p_dev->resource[0]->flags |= IO_DATA_PATH_WIDTH_AUTO;
return pcmcia_request_io(p_dev);
}
static int smc_config(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
int i;
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_IO;
i = pcmcia_loop_config(link, smc_configcheck, NULL);
if (!i)
dev->base_addr = link->resource[0]->start;
return i;
}
static int smc_setup(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
if (!pcmcia_get_mac_from_cis(link, dev))
return 0;
if (link->prod_id[2]) {
if (cvt_ascii_address(dev, link->prod_id[2]) == 0)
return 0;
}
return -1;
}
static int osi_config(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
static const unsigned int com[4] = { 0x3f8, 0x2f8, 0x3e8, 0x2e8 };
int i, j;
link->config_flags |= CONF_ENABLE_SPKR | CONF_ENABLE_IRQ;
link->resource[0]->end = 64;
link->resource[1]->flags |= IO_DATA_PATH_WIDTH_8;
link->resource[1]->end = 8;
link->io_lines = 16;
link->config_index = 0x23;
for (i = j = 0; j < 4; j++) {
link->resource[1]->start = com[j];
i = pcmcia_request_io(link);
if (i == 0)
break;
}
if (i != 0) {
link->config_index = 0x03;
link->resource[1]->end = 0;
i = pcmcia_request_io(link);
}
dev->base_addr = link->resource[0]->start + 0x10;
return i;
}
static int osi_load_firmware(struct pcmcia_device *link)
{
const struct firmware *fw;
int i, err;
err = request_firmware(&fw, FIRMWARE_NAME, &link->dev);
if (err) {
pr_err("Failed to load firmware \"%s\"\n", FIRMWARE_NAME);
return err;
}
for (i = 0; i < fw->size; i++) {
outb(fw->data[i], link->resource[0]->start + 2);
udelay(50);
}
release_firmware(fw);
return err;
}
static int pcmcia_osi_mac(struct pcmcia_device *p_dev,
tuple_t *tuple,
void *priv)
{
struct net_device *dev = priv;
int i;
if (tuple->TupleDataLen < 8)
return -EINVAL;
if (tuple->TupleData[0] != 0x04)
return -EINVAL;
for (i = 0; i < 6; i++)
dev->dev_addr[i] = tuple->TupleData[i+2];
return 0;
}
static int osi_setup(struct pcmcia_device *link, u_short manfid, u_short cardid)
{
struct net_device *dev = link->priv;
int rc;
if (pcmcia_loop_tuple(link, 0x90, pcmcia_osi_mac, dev))
return -1;
if (((manfid == MANFID_OSITECH) &&
(cardid == PRODID_OSITECH_SEVEN)) ||
((manfid == MANFID_PSION) &&
(cardid == PRODID_PSION_NET100))) {
rc = osi_load_firmware(link);
if (rc)
return rc;
} else if (manfid == MANFID_OSITECH) {
set_bits(0x300, link->resource[0]->start + OSITECH_AUI_PWR);
set_bits(0x300, link->resource[0]->start + OSITECH_RESET_ISR);
dev_dbg(&link->dev, "AUI/PWR: %4.4x RESET/ISR: %4.4x\n",
inw(link->resource[0]->start + OSITECH_AUI_PWR),
inw(link->resource[0]->start + OSITECH_RESET_ISR));
}
return 0;
}
static int smc91c92_suspend(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
if (link->open)
netif_device_detach(dev);
return 0;
}
static int smc91c92_resume(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
struct smc_private *smc = netdev_priv(dev);
int i;
if ((smc->manfid == MANFID_MEGAHERTZ) &&
(smc->cardid == PRODID_MEGAHERTZ_EM3288))
mhz_3288_power(link);
if (smc->manfid == MANFID_MOTOROLA)
mot_config(link);
if ((smc->manfid == MANFID_OSITECH) &&
(smc->cardid != PRODID_OSITECH_SEVEN)) {
set_bits(0x0300, dev->base_addr-0x10+OSITECH_AUI_PWR);
set_bits(0x0300, dev->base_addr-0x10+OSITECH_RESET_ISR);
}
if (((smc->manfid == MANFID_OSITECH) &&
(smc->cardid == PRODID_OSITECH_SEVEN)) ||
((smc->manfid == MANFID_PSION) &&
(smc->cardid == PRODID_PSION_NET100))) {
i = osi_load_firmware(link);
if (i) {
netdev_err(dev, "Failed to load firmware\n");
return i;
}
}
if (link->open) {
smc_reset(dev);
netif_device_attach(dev);
}
return 0;
}
static int check_sig(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
unsigned int ioaddr = dev->base_addr;
int width;
u_short s;
SMC_SELECT_BANK(1);
if (inw(ioaddr + BANK_SELECT) >> 8 != 0x33) {
outw(0, ioaddr + CONTROL);
mdelay(55);
}
width = (link->resource[0]->flags == IO_DATA_PATH_WIDTH_AUTO);
s = inb(ioaddr + CONFIG);
if (width)
s |= CFG_16BIT;
else
s &= ~CFG_16BIT;
outb(s, ioaddr + CONFIG);
s = inw(ioaddr + BASE_ADDR);
if ((inw(ioaddr + BANK_SELECT) >> 8 == 0x33) &&
((s >> 8) != (s & 0xff))) {
SMC_SELECT_BANK(3);
s = inw(ioaddr + REVISION);
return s & 0xff;
}
if (width) {
netdev_info(dev, "using 8-bit IO window\n");
smc91c92_suspend(link);
pcmcia_fixup_iowidth(link);
smc91c92_resume(link);
return check_sig(link);
}
return -ENODEV;
}
static int smc91c92_config(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
struct smc_private *smc = netdev_priv(dev);
char *name;
int i, rev, j = 0;
unsigned int ioaddr;
u_long mir;
dev_dbg(&link->dev, "smc91c92_config\n");
smc->manfid = link->manf_id;
smc->cardid = link->card_id;
if ((smc->manfid == MANFID_OSITECH) &&
(smc->cardid != PRODID_OSITECH_SEVEN)) {
i = osi_config(link);
} else if ((smc->manfid == MANFID_MOTOROLA) ||
((smc->manfid == MANFID_MEGAHERTZ) &&
((smc->cardid == PRODID_MEGAHERTZ_VARIOUS) ||
(smc->cardid == PRODID_MEGAHERTZ_EM3288)))) {
i = mhz_mfc_config(link);
} else {
i = smc_config(link);
}
if (i)
goto config_failed;
i = pcmcia_request_irq(link, smc_interrupt);
if (i)
goto config_failed;
i = pcmcia_enable_device(link);
if (i)
goto config_failed;
if (smc->manfid == MANFID_MOTOROLA)
mot_config(link);
dev->irq = link->irq;
if ((if_port >= 0) && (if_port <= 2))
dev->if_port = if_port;
else
dev_notice(&link->dev, "invalid if_port requested\n");
switch (smc->manfid) {
case MANFID_OSITECH:
case MANFID_PSION:
i = osi_setup(link, smc->manfid, smc->cardid); break;
case MANFID_SMC:
case MANFID_NEW_MEDIA:
i = smc_setup(link); break;
case 0x128:
case MANFID_MEGAHERTZ:
i = mhz_setup(link); break;
case MANFID_MOTOROLA:
default:
i = mot_setup(link); break;
}
if (i != 0) {
dev_notice(&link->dev, "Unable to find hardware address.\n");
goto config_failed;
}
smc->duplex = 0;
smc->rx_ovrn = 0;
rev = check_sig(link);
name = "???";
if (rev > 0)
switch (rev >> 4) {
case 3: name = "92"; break;
case 4: name = ((rev & 15) >= 6) ? "96" : "94"; break;
case 5: name = "95"; break;
case 7: name = "100"; break;
case 8: name = "100-FD"; break;
case 9: name = "110"; break;
}
ioaddr = dev->base_addr;
if (rev > 0) {
u_long mcr;
SMC_SELECT_BANK(0);
mir = inw(ioaddr + MEMINFO) & 0xff;
if (mir == 0xff) mir++;
mcr = ((rev >> 4) > 3) ? inw(ioaddr + MEMCFG) : 0x0200;
mir *= 128 * (1<<((mcr >> 9) & 7));
SMC_SELECT_BANK(1);
smc->cfg = inw(ioaddr + CONFIG) & ~CFG_AUI_SELECT;
smc->cfg |= CFG_NO_WAIT | CFG_16BIT | CFG_STATIC;
if (smc->manfid == MANFID_OSITECH)
smc->cfg |= CFG_IRQ_SEL_1 | CFG_IRQ_SEL_0;
if ((rev >> 4) >= 7)
smc->cfg |= CFG_MII_SELECT;
} else
mir = 0;
if (smc->cfg & CFG_MII_SELECT) {
SMC_SELECT_BANK(3);
for (i = 0; i < 32; i++) {
j = mdio_read(dev, i, 1);
if ((j != 0) && (j != 0xffff)) break;
}
smc->mii_if.phy_id = (i < 32) ? i : -1;
SMC_SELECT_BANK(0);
}
SET_NETDEV_DEV(dev, &link->dev);
if (register_netdev(dev) != 0) {
dev_err(&link->dev, "register_netdev() failed\n");
goto config_undo;
}
netdev_info(dev, "smc91c%s rev %d: io %#3lx, irq %d, hw_addr %pM\n",
name, (rev & 0x0f), dev->base_addr, dev->irq, dev->dev_addr);
if (rev > 0) {
if (mir & 0x3ff)
netdev_info(dev, " %lu byte", mir);
else
netdev_info(dev, " %lu kb", mir>>10);
pr_cont(" buffer, %s xcvr\n",
(smc->cfg & CFG_MII_SELECT) ? "MII" : if_names[dev->if_port]);
}
if (smc->cfg & CFG_MII_SELECT) {
if (smc->mii_if.phy_id != -1) {
netdev_dbg(dev, " MII transceiver at index %d, status %x\n",
smc->mii_if.phy_id, j);
} else {
netdev_notice(dev, " No MII transceivers found!\n");
}
}
return 0;
config_undo:
unregister_netdev(dev);
config_failed:
smc91c92_release(link);
free_netdev(dev);
return -ENODEV;
}
static void smc91c92_release(struct pcmcia_device *link)
{
dev_dbg(&link->dev, "smc91c92_release\n");
if (link->resource[2]->end) {
struct net_device *dev = link->priv;
struct smc_private *smc = netdev_priv(dev);
iounmap(smc->base);
}
pcmcia_disable_device(link);
}
static void mdio_sync(unsigned int addr)
{
int bits;
for (bits = 0; bits < 32; bits++) {
outb(MDIO_DATA_WRITE1, addr);
outb(MDIO_DATA_WRITE1 | MDIO_SHIFT_CLK, addr);
}
}
static int mdio_read(struct net_device *dev, int phy_id, int loc)
{
unsigned int addr = dev->base_addr + MGMT;
u_int cmd = (0x06<<10)|(phy_id<<5)|loc;
int i, retval = 0;
mdio_sync(addr);
for (i = 13; i >= 0; i--) {
int dat = (cmd&(1<<i)) ? MDIO_DATA_WRITE1 : MDIO_DATA_WRITE0;
outb(dat, addr);
outb(dat | MDIO_SHIFT_CLK, addr);
}
for (i = 19; i > 0; i--) {
outb(0, addr);
retval = (retval << 1) | ((inb(addr) & MDIO_DATA_READ) != 0);
outb(MDIO_SHIFT_CLK, addr);
}
return (retval>>1) & 0xffff;
}
static void mdio_write(struct net_device *dev, int phy_id, int loc, int value)
{
unsigned int addr = dev->base_addr + MGMT;
u_int cmd = (0x05<<28)|(phy_id<<23)|(loc<<18)|(1<<17)|value;
int i;
mdio_sync(addr);
for (i = 31; i >= 0; i--) {
int dat = (cmd&(1<<i)) ? MDIO_DATA_WRITE1 : MDIO_DATA_WRITE0;
outb(dat, addr);
outb(dat | MDIO_SHIFT_CLK, addr);
}
for (i = 1; i >= 0; i--) {
outb(0, addr);
outb(MDIO_SHIFT_CLK, addr);
}
}
static void smc_dump(struct net_device *dev)
{
unsigned int ioaddr = dev->base_addr;
u_short i, w, save;
save = inw(ioaddr + BANK_SELECT);
for (w = 0; w < 4; w++) {
SMC_SELECT_BANK(w);
netdev_dbg(dev, "bank %d: ", w);
for (i = 0; i < 14; i += 2)
pr_cont(" %04x", inw(ioaddr + i));
pr_cont("\n");
}
outw(save, ioaddr + BANK_SELECT);
}
static int smc_open(struct net_device *dev)
{
struct smc_private *smc = netdev_priv(dev);
struct pcmcia_device *link = smc->p_dev;
dev_dbg(&link->dev, "%s: smc_open(%p), ID/Window %4.4x.\n",
dev->name, dev, inw(dev->base_addr + BANK_SELECT));
#ifdef PCMCIA_DEBUG
smc_dump(dev);
#endif
if (!pcmcia_dev_present(link))
return -ENODEV;
if (check_sig(link) < 0) {
netdev_info(dev, "Yikes! Bad chip signature!\n");
return -ENODEV;
}
link->open++;
netif_start_queue(dev);
smc->saved_skb = NULL;
smc->packets_waiting = 0;
smc_reset(dev);
setup_timer(&smc->media, media_check, (u_long)dev);
mod_timer(&smc->media, jiffies + HZ);
return 0;
}
static int smc_close(struct net_device *dev)
{
struct smc_private *smc = netdev_priv(dev);
struct pcmcia_device *link = smc->p_dev;
unsigned int ioaddr = dev->base_addr;
dev_dbg(&link->dev, "%s: smc_close(), status %4.4x.\n",
dev->name, inw(ioaddr + BANK_SELECT));
netif_stop_queue(dev);
SMC_SELECT_BANK(2);
outw(0, ioaddr + INTERRUPT);
SMC_SELECT_BANK(0);
mask_bits(0xff00, ioaddr + RCR);
mask_bits(0xff00, ioaddr + TCR);
SMC_SELECT_BANK(1);
outw(CTL_POWERDOWN, ioaddr + CONTROL );
link->open--;
del_timer_sync(&smc->media);
return 0;
}
static void smc_hardware_send_packet(struct net_device * dev)
{
struct smc_private *smc = netdev_priv(dev);
struct sk_buff *skb = smc->saved_skb;
unsigned int ioaddr = dev->base_addr;
u_char packet_no;
if (!skb) {
netdev_err(dev, "In XMIT with no packet to send\n");
return;
}
packet_no = inw(ioaddr + PNR_ARR) >> 8;
if (packet_no & 0x80) {
netdev_warn(dev, "hardware Tx buffer allocation failed, status %#2.2x\n",
packet_no);
dev_kfree_skb_irq(skb);
smc->saved_skb = NULL;
netif_start_queue(dev);
return;
}
dev->stats.tx_bytes += skb->len;
outw(packet_no, ioaddr + PNR_ARR);
outw(PTR_AUTOINC , ioaddr + POINTER);
{
u_char *buf = skb->data;
u_int length = skb->len;
netdev_dbg(dev, "Trying to xmit packet of length %d\n", length);
outw(0, ioaddr + DATA_1);
outw(length + 6, ioaddr + DATA_1);
outsw(ioaddr + DATA_1, buf, length >> 1);
outw((length & 1) ? 0x2000 | buf[length-1] : 0, ioaddr + DATA_1);
}
outw(((IM_TX_INT|IM_TX_EMPTY_INT)<<8) |
(inw(ioaddr + INTERRUPT) & 0xff00),
ioaddr + INTERRUPT);
outw(MC_ENQUEUE , ioaddr + MMU_CMD);
smc->saved_skb = NULL;
dev_kfree_skb_irq(skb);
netif_trans_update(dev);
netif_start_queue(dev);
}
static void smc_tx_timeout(struct net_device *dev)
{
struct smc_private *smc = netdev_priv(dev);
unsigned int ioaddr = dev->base_addr;
netdev_notice(dev, "transmit timed out, Tx_status %2.2x status %4.4x.\n",
inw(ioaddr)&0xff, inw(ioaddr + 2));
dev->stats.tx_errors++;
smc_reset(dev);
netif_trans_update(dev);
smc->saved_skb = NULL;
netif_wake_queue(dev);
}
static netdev_tx_t smc_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct smc_private *smc = netdev_priv(dev);
unsigned int ioaddr = dev->base_addr;
u_short num_pages;
short time_out, ir;
unsigned long flags;
netif_stop_queue(dev);
netdev_dbg(dev, "smc_start_xmit(length = %d) called, status %04x\n",
skb->len, inw(ioaddr + 2));
if (smc->saved_skb) {
dev->stats.tx_aborted_errors++;
netdev_dbg(dev, "Internal error -- sent packet while busy\n");
return NETDEV_TX_BUSY;
}
smc->saved_skb = skb;
num_pages = skb->len >> 8;
if (num_pages > 7) {
netdev_err(dev, "Far too big packet error: %d pages\n", num_pages);
dev_kfree_skb (skb);
smc->saved_skb = NULL;
dev->stats.tx_dropped++;
return NETDEV_TX_OK;
}
smc->packets_waiting++;
spin_lock_irqsave(&smc->lock, flags);
SMC_SELECT_BANK(2);
if (smc->rx_ovrn) {
outw(MC_RESET, ioaddr + MMU_CMD);
smc->rx_ovrn = 0;
}
outw(MC_ALLOC | num_pages, ioaddr + MMU_CMD);
for (time_out = MEMORY_WAIT_TIME; time_out >= 0; time_out--) {
ir = inw(ioaddr+INTERRUPT);
if (ir & IM_ALLOC_INT) {
outw((ir&0xff00) | IM_ALLOC_INT, ioaddr + INTERRUPT);
smc_hardware_send_packet(dev);
spin_unlock_irqrestore(&smc->lock, flags);
return NETDEV_TX_OK;
}
}
netdev_dbg(dev, "memory allocation deferred.\n");
outw((IM_ALLOC_INT << 8) | (ir & 0xff00), ioaddr + INTERRUPT);
spin_unlock_irqrestore(&smc->lock, flags);
return NETDEV_TX_OK;
}
static void smc_tx_err(struct net_device * dev)
{
struct smc_private *smc = netdev_priv(dev);
unsigned int ioaddr = dev->base_addr;
int saved_packet = inw(ioaddr + PNR_ARR) & 0xff;
int packet_no = inw(ioaddr + FIFO_PORTS) & 0x7f;
int tx_status;
outw(packet_no, ioaddr + PNR_ARR);
outw(PTR_AUTOINC | PTR_READ | 0, ioaddr + POINTER);
tx_status = inw(ioaddr + DATA_1);
dev->stats.tx_errors++;
if (tx_status & TS_LOSTCAR) dev->stats.tx_carrier_errors++;
if (tx_status & TS_LATCOL) dev->stats.tx_window_errors++;
if (tx_status & TS_16COL) {
dev->stats.tx_aborted_errors++;
smc->tx_err++;
}
if (tx_status & TS_SUCCESS) {
netdev_notice(dev, "Successful packet caused error interrupt?\n");
}
SMC_SELECT_BANK(0);
outw(inw(ioaddr + TCR) | TCR_ENABLE | smc->duplex, ioaddr + TCR);
SMC_SELECT_BANK(2);
outw(MC_FREEPKT, ioaddr + MMU_CMD);
smc->packets_waiting--;
outw(saved_packet, ioaddr + PNR_ARR);
}
static void smc_eph_irq(struct net_device *dev)
{
struct smc_private *smc = netdev_priv(dev);
unsigned int ioaddr = dev->base_addr;
u_short card_stats, ephs;
SMC_SELECT_BANK(0);
ephs = inw(ioaddr + EPH);
netdev_dbg(dev, "Ethernet protocol handler interrupt, status %4.4x.\n",
ephs);
card_stats = inw(ioaddr + COUNTER);
dev->stats.collisions += card_stats & 0xF;
card_stats >>= 4;
dev->stats.collisions += card_stats & 0xF;
#if 0
card_stats >>= 4;
card_stats >>= 4;
#endif
outw(inw(ioaddr + TCR) | TCR_ENABLE | smc->duplex, ioaddr + TCR);
SMC_SELECT_BANK(1);
outw(CTL_AUTO_RELEASE | 0x0000, ioaddr + CONTROL);
outw(CTL_AUTO_RELEASE | CTL_TE_ENABLE | CTL_CR_ENABLE,
ioaddr + CONTROL);
SMC_SELECT_BANK(2);
}
static irqreturn_t smc_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct smc_private *smc = netdev_priv(dev);
unsigned int ioaddr;
u_short saved_bank, saved_pointer, mask, status;
unsigned int handled = 1;
char bogus_cnt = INTR_WORK;
if (!netif_device_present(dev))
return IRQ_NONE;
ioaddr = dev->base_addr;
netdev_dbg(dev, "SMC91c92 interrupt %d at %#x.\n",
irq, ioaddr);
spin_lock(&smc->lock);
smc->watchdog = 0;
saved_bank = inw(ioaddr + BANK_SELECT);
if ((saved_bank & 0xff00) != 0x3300) {
netdev_dbg(dev, "SMC91c92 interrupt %d for non-existent/ejected device.\n",
irq);
handled = 0;
goto irq_done;
}
SMC_SELECT_BANK(2);
saved_pointer = inw(ioaddr + POINTER);
mask = inw(ioaddr + INTERRUPT) >> 8;
outw(0, ioaddr + INTERRUPT);
do {
status = inw(ioaddr + INTERRUPT) & 0xff;
netdev_dbg(dev, "Status is %#2.2x (mask %#2.2x).\n",
status, mask);
if ((status & mask) == 0) {
if (bogus_cnt == INTR_WORK)
handled = 0;
break;
}
if (status & IM_RCV_INT) {
smc_rx(dev);
}
if (status & IM_TX_INT) {
smc_tx_err(dev);
outw(IM_TX_INT, ioaddr + INTERRUPT);
}
status &= mask;
if (status & IM_TX_EMPTY_INT) {
outw(IM_TX_EMPTY_INT, ioaddr + INTERRUPT);
mask &= ~IM_TX_EMPTY_INT;
dev->stats.tx_packets += smc->packets_waiting;
smc->packets_waiting = 0;
}
if (status & IM_ALLOC_INT) {
mask &= ~IM_ALLOC_INT;
smc_hardware_send_packet(dev);
mask |= (IM_TX_EMPTY_INT | IM_TX_INT);
netif_wake_queue(dev);
}
if (status & IM_RX_OVRN_INT) {
dev->stats.rx_errors++;
dev->stats.rx_fifo_errors++;
if (smc->duplex)
smc->rx_ovrn = 1;
outw(IM_RX_OVRN_INT, ioaddr + INTERRUPT);
}
if (status & IM_EPH_INT)
smc_eph_irq(dev);
} while (--bogus_cnt);
netdev_dbg(dev, " Restoring saved registers mask %2.2x bank %4.4x pointer %4.4x.\n",
mask, saved_bank, saved_pointer);
outw((mask<<8), ioaddr + INTERRUPT);
outw(saved_pointer, ioaddr + POINTER);
SMC_SELECT_BANK(saved_bank);
netdev_dbg(dev, "Exiting interrupt IRQ%d.\n", irq);
irq_done:
if ((smc->manfid == MANFID_OSITECH) &&
(smc->cardid != PRODID_OSITECH_SEVEN)) {
mask_bits(0x00ff, ioaddr-0x10+OSITECH_RESET_ISR);
set_bits(0x0300, ioaddr-0x10+OSITECH_RESET_ISR);
}
if (smc->manfid == MANFID_MOTOROLA) {
u_char cor;
cor = readb(smc->base + MOT_UART + CISREG_COR);
writeb(cor & ~COR_IREQ_ENA, smc->base + MOT_UART + CISREG_COR);
writeb(cor, smc->base + MOT_UART + CISREG_COR);
cor = readb(smc->base + MOT_LAN + CISREG_COR);
writeb(cor & ~COR_IREQ_ENA, smc->base + MOT_LAN + CISREG_COR);
writeb(cor, smc->base + MOT_LAN + CISREG_COR);
}
if ((smc->base != NULL) &&
(smc->manfid == MANFID_MEGAHERTZ) &&
(smc->cardid == PRODID_MEGAHERTZ_EM3288)) {
u_char tmp;
tmp = readb(smc->base+MEGAHERTZ_ISR);
tmp = readb(smc->base+MEGAHERTZ_ISR);
writeb(tmp, smc->base + MEGAHERTZ_ISR);
writeb(tmp, smc->base + MEGAHERTZ_ISR);
}
spin_unlock(&smc->lock);
return IRQ_RETVAL(handled);
}
static void smc_rx(struct net_device *dev)
{
unsigned int ioaddr = dev->base_addr;
int rx_status;
int packet_length;
if (inw(ioaddr + FIFO_PORTS) & FP_RXEMPTY) {
netdev_err(dev, "smc_rx() with nothing on Rx FIFO\n");
return;
}
outw(PTR_READ | PTR_RCV | PTR_AUTOINC, ioaddr + POINTER);
rx_status = inw(ioaddr + DATA_1);
packet_length = inw(ioaddr + DATA_1) & 0x07ff;
netdev_dbg(dev, "Receive status %4.4x length %d.\n",
rx_status, packet_length);
if (!(rx_status & RS_ERRORS)) {
struct sk_buff *skb;
struct smc_private *smc = netdev_priv(dev);
skb = netdev_alloc_skb(dev, packet_length+2);
if (skb == NULL) {
netdev_dbg(dev, "Low memory, packet dropped.\n");
dev->stats.rx_dropped++;
outw(MC_RELEASE, ioaddr + MMU_CMD);
return;
}
packet_length -= (rx_status & RS_ODDFRAME ? 5 : 6);
skb_reserve(skb, 2);
insw(ioaddr+DATA_1, skb_put(skb, packet_length),
(packet_length+1)>>1);
skb->protocol = eth_type_trans(skb, dev);
netif_rx(skb);
smc->last_rx = jiffies;
dev->stats.rx_packets++;
dev->stats.rx_bytes += packet_length;
if (rx_status & RS_MULTICAST)
dev->stats.multicast++;
} else {
dev->stats.rx_errors++;
if (rx_status & RS_ALGNERR) dev->stats.rx_frame_errors++;
if (rx_status & (RS_TOOSHORT | RS_TOOLONG))
dev->stats.rx_length_errors++;
if (rx_status & RS_BADCRC) dev->stats.rx_crc_errors++;
}
outw(MC_RELEASE, ioaddr + MMU_CMD);
}
static void set_rx_mode(struct net_device *dev)
{
unsigned int ioaddr = dev->base_addr;
struct smc_private *smc = netdev_priv(dev);
unsigned char multicast_table[8];
unsigned long flags;
u_short rx_cfg_setting;
int i;
memset(multicast_table, 0, sizeof(multicast_table));
if (dev->flags & IFF_PROMISC) {
rx_cfg_setting = RxStripCRC | RxEnable | RxPromisc | RxAllMulti;
} else if (dev->flags & IFF_ALLMULTI)
rx_cfg_setting = RxStripCRC | RxEnable | RxAllMulti;
else {
if (!netdev_mc_empty(dev)) {
struct netdev_hw_addr *ha;
netdev_for_each_mc_addr(ha, dev) {
u_int position = ether_crc(6, ha->addr);
multicast_table[position >> 29] |= 1 << ((position >> 26) & 7);
}
}
rx_cfg_setting = RxStripCRC | RxEnable;
}
spin_lock_irqsave(&smc->lock, flags);
SMC_SELECT_BANK(3);
for (i = 0; i < 8; i++)
outb(multicast_table[i], ioaddr + MULTICAST0 + i);
SMC_SELECT_BANK(0);
outw(rx_cfg_setting, ioaddr + RCR);
SMC_SELECT_BANK(2);
spin_unlock_irqrestore(&smc->lock, flags);
}
static int s9k_config(struct net_device *dev, struct ifmap *map)
{
struct smc_private *smc = netdev_priv(dev);
if ((map->port != (u_char)(-1)) && (map->port != dev->if_port)) {
if (smc->cfg & CFG_MII_SELECT)
return -EOPNOTSUPP;
else if (map->port > 2)
return -EINVAL;
dev->if_port = map->port;
netdev_info(dev, "switched to %s port\n", if_names[dev->if_port]);
smc_reset(dev);
}
return 0;
}
static void smc_set_xcvr(struct net_device *dev, int if_port)
{
struct smc_private *smc = netdev_priv(dev);
unsigned int ioaddr = dev->base_addr;
u_short saved_bank;
saved_bank = inw(ioaddr + BANK_SELECT);
SMC_SELECT_BANK(1);
if (if_port == 2) {
outw(smc->cfg | CFG_AUI_SELECT, ioaddr + CONFIG);
if ((smc->manfid == MANFID_OSITECH) &&
(smc->cardid != PRODID_OSITECH_SEVEN))
set_bits(OSI_AUI_PWR, ioaddr - 0x10 + OSITECH_AUI_PWR);
smc->media_status = ((dev->if_port == 0) ? 0x0001 : 0x0002);
} else {
outw(smc->cfg, ioaddr + CONFIG);
if ((smc->manfid == MANFID_OSITECH) &&
(smc->cardid != PRODID_OSITECH_SEVEN))
mask_bits(~OSI_AUI_PWR, ioaddr - 0x10 + OSITECH_AUI_PWR);
smc->media_status = ((dev->if_port == 0) ? 0x0012 : 0x4001);
}
SMC_SELECT_BANK(saved_bank);
}
static void smc_reset(struct net_device *dev)
{
unsigned int ioaddr = dev->base_addr;
struct smc_private *smc = netdev_priv(dev);
int i;
netdev_dbg(dev, "smc91c92 reset called.\n");
SMC_SELECT_BANK(0);
outw(RCR_SOFTRESET, ioaddr + RCR);
udelay(10);
outw(RCR_CLEAR, ioaddr + RCR);
outw(TCR_CLEAR, ioaddr + TCR);
SMC_SELECT_BANK(1);
outw(CTL_AUTO_RELEASE | CTL_TE_ENABLE | CTL_CR_ENABLE,
ioaddr + CONTROL);
smc_set_xcvr(dev, dev->if_port);
if ((smc->manfid == MANFID_OSITECH) &&
(smc->cardid != PRODID_OSITECH_SEVEN))
outw((dev->if_port == 2 ? OSI_AUI_PWR : 0) |
(inw(ioaddr-0x10+OSITECH_AUI_PWR) & 0xff00),
ioaddr - 0x10 + OSITECH_AUI_PWR);
for (i = 0; i < 6; i += 2)
outw((dev->dev_addr[i+1]<<8)+dev->dev_addr[i],
ioaddr + ADDR0 + i);
SMC_SELECT_BANK(2);
outw(MC_RESET, ioaddr + MMU_CMD);
outw(0, ioaddr + INTERRUPT);
SMC_SELECT_BANK(0);
outw(((smc->cfg & CFG_MII_SELECT) ? 0 : TCR_MONCSN) |
TCR_ENABLE | TCR_PAD_EN | smc->duplex, ioaddr + TCR);
set_rx_mode(dev);
if (smc->cfg & CFG_MII_SELECT) {
SMC_SELECT_BANK(3);
mdio_write(dev, smc->mii_if.phy_id, 0, 0x8000);
mdio_write(dev, smc->mii_if.phy_id, 4, 0x01e1);
mdio_write(dev, smc->mii_if.phy_id, 0, 0x0000);
mdio_write(dev, smc->mii_if.phy_id, 0, 0x1200);
}
SMC_SELECT_BANK(2);
outw((IM_EPH_INT | IM_RX_OVRN_INT | IM_RCV_INT) << 8,
ioaddr + INTERRUPT);
}
static void media_check(u_long arg)
{
struct net_device *dev = (struct net_device *) arg;
struct smc_private *smc = netdev_priv(dev);
unsigned int ioaddr = dev->base_addr;
u_short i, media, saved_bank;
u_short link;
unsigned long flags;
spin_lock_irqsave(&smc->lock, flags);
saved_bank = inw(ioaddr + BANK_SELECT);
if (!netif_device_present(dev))
goto reschedule;
SMC_SELECT_BANK(2);
if (smc->rx_ovrn) {
outw(MC_RESET, ioaddr + MMU_CMD);
smc->rx_ovrn = 0;
}
i = inw(ioaddr + INTERRUPT);
SMC_SELECT_BANK(0);
media = inw(ioaddr + EPH) & EPH_LINK_OK;
SMC_SELECT_BANK(1);
media |= (inw(ioaddr + CONFIG) & CFG_AUI_SELECT) ? 2 : 1;
SMC_SELECT_BANK(saved_bank);
spin_unlock_irqrestore(&smc->lock, flags);
if (smc->watchdog++ && ((i>>8) & i)) {
if (!smc->fast_poll)
netdev_info(dev, "interrupt(s) dropped!\n");
local_irq_save(flags);
smc_interrupt(dev->irq, dev);
local_irq_restore(flags);
smc->fast_poll = HZ;
}
if (smc->fast_poll) {
smc->fast_poll--;
smc->media.expires = jiffies + HZ/100;
add_timer(&smc->media);
return;
}
spin_lock_irqsave(&smc->lock, flags);
saved_bank = inw(ioaddr + BANK_SELECT);
if (smc->cfg & CFG_MII_SELECT) {
if (smc->mii_if.phy_id < 0)
goto reschedule;
SMC_SELECT_BANK(3);
link = mdio_read(dev, smc->mii_if.phy_id, 1);
if (!link || (link == 0xffff)) {
netdev_info(dev, "MII is missing!\n");
smc->mii_if.phy_id = -1;
goto reschedule;
}
link &= 0x0004;
if (link != smc->link_status) {
u_short p = mdio_read(dev, smc->mii_if.phy_id, 5);
netdev_info(dev, "%s link beat\n", link ? "found" : "lost");
smc->duplex = (((p & 0x0100) || ((p & 0x1c0) == 0x40))
? TCR_FDUPLX : 0);
if (link) {
netdev_info(dev, "autonegotiation complete: "
"%dbaseT-%cD selected\n",
(p & 0x0180) ? 100 : 10, smc->duplex ? 'F' : 'H');
}
SMC_SELECT_BANK(0);
outw(inw(ioaddr + TCR) | smc->duplex, ioaddr + TCR);
smc->link_status = link;
}
goto reschedule;
}
if (time_after(jiffies, smc->last_rx + HZ)) {
if (smc->tx_err || (smc->media_status & EPH_16COL))
media |= EPH_16COL;
}
smc->tx_err = 0;
if (media != smc->media_status) {
if ((media & smc->media_status & 1) &&
((smc->media_status ^ media) & EPH_LINK_OK))
netdev_info(dev, "%s link beat\n",
smc->media_status & EPH_LINK_OK ? "lost" : "found");
else if ((media & smc->media_status & 2) &&
((smc->media_status ^ media) & EPH_16COL))
netdev_info(dev, "coax cable %s\n",
media & EPH_16COL ? "problem" : "ok");
if (dev->if_port == 0) {
if (media & 1) {
if (media & EPH_LINK_OK)
netdev_info(dev, "flipped to 10baseT\n");
else
smc_set_xcvr(dev, 2);
} else {
if (media & EPH_16COL)
smc_set_xcvr(dev, 1);
else
netdev_info(dev, "flipped to 10base2\n");
}
}
smc->media_status = media;
}
reschedule:
smc->media.expires = jiffies + HZ;
add_timer(&smc->media);
SMC_SELECT_BANK(saved_bank);
spin_unlock_irqrestore(&smc->lock, flags);
}
static int smc_link_ok(struct net_device *dev)
{
unsigned int ioaddr = dev->base_addr;
struct smc_private *smc = netdev_priv(dev);
if (smc->cfg & CFG_MII_SELECT) {
return mii_link_ok(&smc->mii_if);
} else {
SMC_SELECT_BANK(0);
return inw(ioaddr + EPH) & EPH_LINK_OK;
}
}
static int smc_netdev_get_ecmd(struct net_device *dev, struct ethtool_cmd *ecmd)
{
u16 tmp;
unsigned int ioaddr = dev->base_addr;
ecmd->supported = (SUPPORTED_TP | SUPPORTED_AUI |
SUPPORTED_10baseT_Half | SUPPORTED_10baseT_Full);
SMC_SELECT_BANK(1);
tmp = inw(ioaddr + CONFIG);
ecmd->port = (tmp & CFG_AUI_SELECT) ? PORT_AUI : PORT_TP;
ecmd->transceiver = XCVR_INTERNAL;
ethtool_cmd_speed_set(ecmd, SPEED_10);
ecmd->phy_address = ioaddr + MGMT;
SMC_SELECT_BANK(0);
tmp = inw(ioaddr + TCR);
ecmd->duplex = (tmp & TCR_FDUPLX) ? DUPLEX_FULL : DUPLEX_HALF;
return 0;
}
static int smc_netdev_set_ecmd(struct net_device *dev, struct ethtool_cmd *ecmd)
{
u16 tmp;
unsigned int ioaddr = dev->base_addr;
if (ethtool_cmd_speed(ecmd) != SPEED_10)
return -EINVAL;
if (ecmd->duplex != DUPLEX_HALF && ecmd->duplex != DUPLEX_FULL)
return -EINVAL;
if (ecmd->port != PORT_TP && ecmd->port != PORT_AUI)
return -EINVAL;
if (ecmd->transceiver != XCVR_INTERNAL)
return -EINVAL;
if (ecmd->port == PORT_AUI)
smc_set_xcvr(dev, 1);
else
smc_set_xcvr(dev, 0);
SMC_SELECT_BANK(0);
tmp = inw(ioaddr + TCR);
if (ecmd->duplex == DUPLEX_FULL)
tmp |= TCR_FDUPLX;
else
tmp &= ~TCR_FDUPLX;
outw(tmp, ioaddr + TCR);
return 0;
}
static int check_if_running(struct net_device *dev)
{
if (!netif_running(dev))
return -EINVAL;
return 0;
}
static void smc_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
}
static int smc_get_settings(struct net_device *dev, struct ethtool_cmd *ecmd)
{
struct smc_private *smc = netdev_priv(dev);
unsigned int ioaddr = dev->base_addr;
u16 saved_bank = inw(ioaddr + BANK_SELECT);
int ret;
unsigned long flags;
spin_lock_irqsave(&smc->lock, flags);
SMC_SELECT_BANK(3);
if (smc->cfg & CFG_MII_SELECT)
ret = mii_ethtool_gset(&smc->mii_if, ecmd);
else
ret = smc_netdev_get_ecmd(dev, ecmd);
SMC_SELECT_BANK(saved_bank);
spin_unlock_irqrestore(&smc->lock, flags);
return ret;
}
static int smc_set_settings(struct net_device *dev, struct ethtool_cmd *ecmd)
{
struct smc_private *smc = netdev_priv(dev);
unsigned int ioaddr = dev->base_addr;
u16 saved_bank = inw(ioaddr + BANK_SELECT);
int ret;
unsigned long flags;
spin_lock_irqsave(&smc->lock, flags);
SMC_SELECT_BANK(3);
if (smc->cfg & CFG_MII_SELECT)
ret = mii_ethtool_sset(&smc->mii_if, ecmd);
else
ret = smc_netdev_set_ecmd(dev, ecmd);
SMC_SELECT_BANK(saved_bank);
spin_unlock_irqrestore(&smc->lock, flags);
return ret;
}
static u32 smc_get_link(struct net_device *dev)
{
struct smc_private *smc = netdev_priv(dev);
unsigned int ioaddr = dev->base_addr;
u16 saved_bank = inw(ioaddr + BANK_SELECT);
u32 ret;
unsigned long flags;
spin_lock_irqsave(&smc->lock, flags);
SMC_SELECT_BANK(3);
ret = smc_link_ok(dev);
SMC_SELECT_BANK(saved_bank);
spin_unlock_irqrestore(&smc->lock, flags);
return ret;
}
static int smc_nway_reset(struct net_device *dev)
{
struct smc_private *smc = netdev_priv(dev);
if (smc->cfg & CFG_MII_SELECT) {
unsigned int ioaddr = dev->base_addr;
u16 saved_bank = inw(ioaddr + BANK_SELECT);
int res;
SMC_SELECT_BANK(3);
res = mii_nway_restart(&smc->mii_if);
SMC_SELECT_BANK(saved_bank);
return res;
} else
return -EOPNOTSUPP;
}
static int smc_ioctl (struct net_device *dev, struct ifreq *rq, int cmd)
{
struct smc_private *smc = netdev_priv(dev);
struct mii_ioctl_data *mii = if_mii(rq);
int rc = 0;
u16 saved_bank;
unsigned int ioaddr = dev->base_addr;
unsigned long flags;
if (!netif_running(dev))
return -EINVAL;
spin_lock_irqsave(&smc->lock, flags);
saved_bank = inw(ioaddr + BANK_SELECT);
SMC_SELECT_BANK(3);
rc = generic_mii_ioctl(&smc->mii_if, mii, cmd, NULL);
SMC_SELECT_BANK(saved_bank);
spin_unlock_irqrestore(&smc->lock, flags);
return rc;
}
