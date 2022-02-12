static inline struct pcnet_dev *PRIV(struct net_device *dev)
{
char *p = netdev_priv(dev);
return (struct pcnet_dev *)(p + sizeof(struct ei_device));
}
static int pcnet_probe(struct pcmcia_device *link)
{
struct pcnet_dev *info;
struct net_device *dev;
dev_dbg(&link->dev, "pcnet_attach()\n");
dev = __alloc_ei_netdev(sizeof(struct pcnet_dev));
if (!dev) return -ENOMEM;
info = PRIV(dev);
info->p_dev = link;
link->priv = dev;
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_IO;
dev->netdev_ops = &pcnet_netdev_ops;
return pcnet_config(link);
}
static void pcnet_detach(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
dev_dbg(&link->dev, "pcnet_detach\n");
unregister_netdev(dev);
pcnet_release(link);
free_netdev(dev);
}
static struct hw_info *get_hwinfo(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
u_char __iomem *base, *virt;
int i, j;
link->resource[2]->flags |= WIN_DATA_WIDTH_8|WIN_MEMORY_TYPE_AM|WIN_ENABLE;
link->resource[2]->start = 0; link->resource[2]->end = 0;
i = pcmcia_request_window(link, link->resource[2], 0);
if (i != 0)
return NULL;
virt = ioremap(link->resource[2]->start,
resource_size(link->resource[2]));
for (i = 0; i < NR_INFO; i++) {
pcmcia_map_mem_page(link, link->resource[2],
hw_info[i].offset & ~(resource_size(link->resource[2])-1));
base = &virt[hw_info[i].offset & (resource_size(link->resource[2])-1)];
if ((readb(base+0) == hw_info[i].a0) &&
(readb(base+2) == hw_info[i].a1) &&
(readb(base+4) == hw_info[i].a2)) {
for (j = 0; j < 6; j++)
dev->dev_addr[j] = readb(base + (j<<1));
break;
}
}
iounmap(virt);
j = pcmcia_release_window(link, link->resource[2]);
return (i < NR_INFO) ? hw_info+i : NULL;
}
static struct hw_info *get_prom(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
unsigned int ioaddr = dev->base_addr;
u_char prom[32];
int i, j;
struct {
u_char value, offset;
} program_seq[] = {
{E8390_NODMA+E8390_PAGE0+E8390_STOP, E8390_CMD},
{0x48, EN0_DCFG},
{0x00, EN0_RCNTLO},
{0x00, EN0_RCNTHI},
{0x00, EN0_IMR},
{0xFF, EN0_ISR},
{E8390_RXOFF, EN0_RXCR},
{E8390_TXOFF, EN0_TXCR},
{32, EN0_RCNTLO},
{0x00, EN0_RCNTHI},
{0x00, EN0_RSARLO},
{0x00, EN0_RSARHI},
{E8390_RREAD+E8390_START, E8390_CMD},
};
pcnet_reset_8390(dev);
mdelay(10);
for (i = 0; i < ARRAY_SIZE(program_seq); i++)
outb_p(program_seq[i].value, ioaddr + program_seq[i].offset);
for (i = 0; i < 32; i++)
prom[i] = inb(ioaddr + PCNET_DATAPORT);
for (i = 0; i < NR_INFO; i++) {
if ((prom[0] == hw_info[i].a0) &&
(prom[2] == hw_info[i].a1) &&
(prom[4] == hw_info[i].a2))
break;
}
if ((i < NR_INFO) || ((prom[28] == 0x57) && (prom[30] == 0x57))) {
for (j = 0; j < 6; j++)
dev->dev_addr[j] = prom[j<<1];
return (i < NR_INFO) ? hw_info+i : &default_info;
}
return NULL;
}
static struct hw_info *get_dl10019(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
int i;
u_char sum;
for (sum = 0, i = 0x14; i < 0x1c; i++)
sum += inb_p(dev->base_addr + i);
if (sum != 0xff)
return NULL;
for (i = 0; i < 6; i++)
dev->dev_addr[i] = inb_p(dev->base_addr + 0x14 + i);
i = inb(dev->base_addr + 0x1f);
return ((i == 0x91)||(i == 0x99)) ? &dl10022_info : &dl10019_info;
}
static struct hw_info *get_ax88190(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
unsigned int ioaddr = dev->base_addr;
int i, j;
if (link->config_base != 0x03c0)
return NULL;
outb_p(0x01, ioaddr + EN0_DCFG);
outb_p(0x00, ioaddr + EN0_RSARLO);
outb_p(0x04, ioaddr + EN0_RSARHI);
outb_p(E8390_RREAD+E8390_START, ioaddr + E8390_CMD);
for (i = 0; i < 6; i += 2) {
j = inw(ioaddr + PCNET_DATAPORT);
dev->dev_addr[i] = j & 0xff;
dev->dev_addr[i+1] = j >> 8;
}
return NULL;
}
static struct hw_info *get_hwired(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
int i;
for (i = 0; i < 6; i++)
if (hw_addr[i] != 0) break;
if (i == 6)
return NULL;
for (i = 0; i < 6; i++)
dev->dev_addr[i] = hw_addr[i];
return &default_info;
}
static int try_io_port(struct pcmcia_device *link)
{
int j, ret;
link->resource[0]->flags &= ~IO_DATA_PATH_WIDTH;
link->resource[1]->flags &= ~IO_DATA_PATH_WIDTH;
if (link->resource[0]->end == 32) {
link->resource[0]->flags |= IO_DATA_PATH_WIDTH_AUTO;
if (link->resource[1]->end > 0) {
link->resource[1]->flags |= IO_DATA_PATH_WIDTH_8;
}
} else {
link->resource[0]->flags |= IO_DATA_PATH_WIDTH_8;
link->resource[1]->flags |= IO_DATA_PATH_WIDTH_16;
}
if (link->resource[0]->start == 0) {
for (j = 0; j < 0x400; j += 0x20) {
link->resource[0]->start = j ^ 0x300;
link->resource[1]->start = (j ^ 0x300) + 0x10;
link->io_lines = 16;
ret = pcmcia_request_io(link);
if (ret == 0)
return ret;
}
return ret;
} else {
return pcmcia_request_io(link);
}
}
static int pcnet_confcheck(struct pcmcia_device *p_dev, void *priv_data)
{
int *priv = priv_data;
int try = (*priv & 0x1);
*priv &= (p_dev->resource[2]->end >= 0x4000) ? 0x10 : ~0x10;
if (p_dev->config_index == 0)
return -EINVAL;
if (p_dev->resource[0]->end + p_dev->resource[1]->end < 32)
return -EINVAL;
if (try)
p_dev->io_lines = 16;
return try_io_port(p_dev);
}
static struct hw_info *pcnet_try_config(struct pcmcia_device *link,
int *has_shmem, int try)
{
struct net_device *dev = link->priv;
struct hw_info *local_hw_info;
struct pcnet_dev *info = PRIV(dev);
int priv = try;
int ret;
ret = pcmcia_loop_config(link, pcnet_confcheck, &priv);
if (ret) {
dev_warn(&link->dev, "no useable port range found\n");
return NULL;
}
*has_shmem = (priv & 0x10);
if (!link->irq)
return NULL;
if (resource_size(link->resource[1]) == 8)
link->config_flags |= CONF_ENABLE_SPKR;
if ((link->manf_id == MANFID_IBM) &&
(link->card_id == PRODID_IBM_HOME_AND_AWAY))
link->config_index |= 0x10;
ret = pcmcia_enable_device(link);
if (ret)
return NULL;
dev->irq = link->irq;
dev->base_addr = link->resource[0]->start;
if (info->flags & HAS_MISC_REG) {
if ((if_port == 1) || (if_port == 2))
dev->if_port = if_port;
else
dev_notice(&link->dev, "invalid if_port requested\n");
} else
dev->if_port = 0;
if ((link->config_base == 0x03c0) &&
(link->manf_id == 0x149) && (link->card_id == 0xc1ab)) {
dev_info(&link->dev,
"this is an AX88190 card - use axnet_cs instead.\n");
return NULL;
}
local_hw_info = get_hwinfo(link);
if (!local_hw_info)
local_hw_info = get_prom(link);
if (!local_hw_info)
local_hw_info = get_dl10019(link);
if (!local_hw_info)
local_hw_info = get_ax88190(link);
if (!local_hw_info)
local_hw_info = get_hwired(link);
return local_hw_info;
}
static int pcnet_config(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
struct pcnet_dev *info = PRIV(dev);
int start_pg, stop_pg, cm_offset;
int has_shmem = 0;
struct hw_info *local_hw_info;
struct ei_device *ei_local;
dev_dbg(&link->dev, "pcnet_config\n");
local_hw_info = pcnet_try_config(link, &has_shmem, 0);
if (!local_hw_info) {
pcmcia_disable_device(link);
local_hw_info = pcnet_try_config(link, &has_shmem, 1);
if (local_hw_info == NULL) {
dev_notice(&link->dev, "unable to read hardware net"
" address for io base %#3lx\n", dev->base_addr);
goto failed;
}
}
info->flags = local_hw_info->flags;
info->flags |= (delay_output) ? DELAY_OUTPUT : 0;
if ((link->manf_id == MANFID_SOCKET) &&
((link->card_id == PRODID_SOCKET_LPE) ||
(link->card_id == PRODID_SOCKET_LPE_CF) ||
(link->card_id == PRODID_SOCKET_EIO)))
info->flags &= ~USE_BIG_BUF;
if (!use_big_buf)
info->flags &= ~USE_BIG_BUF;
if (info->flags & USE_BIG_BUF) {
start_pg = SOCKET_START_PG;
stop_pg = SOCKET_STOP_PG;
cm_offset = 0x10000;
} else {
start_pg = PCNET_START_PG;
stop_pg = PCNET_STOP_PG;
cm_offset = 0;
}
if ((use_shmem == 0) || (!has_shmem && (use_shmem == -1)) ||
(setup_shmem_window(link, start_pg, stop_pg, cm_offset) != 0))
setup_dma_config(link, start_pg, stop_pg);
ei_status.name = "NE2000";
ei_status.word16 = 1;
ei_status.reset_8390 = pcnet_reset_8390;
if (info->flags & (IS_DL10019|IS_DL10022))
mii_phy_probe(dev);
SET_NETDEV_DEV(dev, &link->dev);
ei_local = netdev_priv(dev);
ei_local->msg_enable = pcnet_msg_enable;
if (register_netdev(dev) != 0) {
pr_notice("register_netdev() failed\n");
goto failed;
}
if (info->flags & (IS_DL10019|IS_DL10022)) {
u_char id = inb(dev->base_addr + 0x1a);
netdev_info(dev, "NE2000 (DL100%d rev %02x): ",
(info->flags & IS_DL10022) ? 22 : 19, id);
if (info->pna_phy)
pr_cont("PNA, ");
} else {
netdev_info(dev, "NE2000 Compatible: ");
}
pr_cont("io %#3lx, irq %d,", dev->base_addr, dev->irq);
if (info->flags & USE_SHMEM)
pr_cont(" mem %#5lx,", dev->mem_start);
if (info->flags & HAS_MISC_REG)
pr_cont(" %s xcvr,", if_names[dev->if_port]);
pr_cont(" hw_addr %pM\n", dev->dev_addr);
return 0;
failed:
pcnet_release(link);
return -ENODEV;
}
static void pcnet_release(struct pcmcia_device *link)
{
struct pcnet_dev *info = PRIV(link->priv);
dev_dbg(&link->dev, "pcnet_release\n");
if (info->flags & USE_SHMEM)
iounmap(info->base);
pcmcia_disable_device(link);
}
static int pcnet_suspend(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
if (link->open)
netif_device_detach(dev);
return 0;
}
static int pcnet_resume(struct pcmcia_device *link)
{
struct net_device *dev = link->priv;
if (link->open) {
pcnet_reset_8390(dev);
NS8390_init(dev, 1);
netif_device_attach(dev);
}
return 0;
}
static void mdio_sync(unsigned int addr)
{
int bits, mask = inb(addr) & MDIO_MASK;
for (bits = 0; bits < 32; bits++) {
outb(mask | MDIO_DATA_WRITE1, addr);
outb(mask | MDIO_DATA_WRITE1 | MDIO_SHIFT_CLK, addr);
}
}
static int mdio_read(unsigned int addr, int phy_id, int loc)
{
u_int cmd = (0x06<<10)|(phy_id<<5)|loc;
int i, retval = 0, mask = inb(addr) & MDIO_MASK;
mdio_sync(addr);
for (i = 13; i >= 0; i--) {
int dat = (cmd&(1<<i)) ? MDIO_DATA_WRITE1 : MDIO_DATA_WRITE0;
outb(mask | dat, addr);
outb(mask | dat | MDIO_SHIFT_CLK, addr);
}
for (i = 19; i > 0; i--) {
outb(mask, addr);
retval = (retval << 1) | ((inb(addr) & MDIO_DATA_READ) != 0);
outb(mask | MDIO_SHIFT_CLK, addr);
}
return (retval>>1) & 0xffff;
}
static void mdio_write(unsigned int addr, int phy_id, int loc, int value)
{
u_int cmd = (0x05<<28)|(phy_id<<23)|(loc<<18)|(1<<17)|value;
int i, mask = inb(addr) & MDIO_MASK;
mdio_sync(addr);
for (i = 31; i >= 0; i--) {
int dat = (cmd&(1<<i)) ? MDIO_DATA_WRITE1 : MDIO_DATA_WRITE0;
outb(mask | dat, addr);
outb(mask | dat | MDIO_SHIFT_CLK, addr);
}
for (i = 1; i >= 0; i--) {
outb(mask, addr);
outb(mask | MDIO_SHIFT_CLK, addr);
}
}
static int read_eeprom(unsigned int ioaddr, int location)
{
int i, retval = 0;
unsigned int ee_addr = ioaddr + DLINK_EEPROM;
int read_cmd = location | (EE_READ_CMD << 8);
outb(0, ee_addr);
outb(EE_EEP|EE_CS, ee_addr);
for (i = 10; i >= 0; i--) {
short dataval = (read_cmd & (1 << i)) ? EE_DO : 0;
outb_p(EE_EEP|EE_CS|dataval, ee_addr);
outb_p(EE_EEP|EE_CS|dataval|EE_CK, ee_addr);
}
outb(EE_EEP|EE_CS, ee_addr);
for (i = 16; i > 0; i--) {
outb_p(EE_EEP|EE_CS | EE_CK, ee_addr);
retval = (retval << 1) | ((inb(ee_addr) & EE_DI) ? 1 : 0);
outb_p(EE_EEP|EE_CS, ee_addr);
}
outb(0, ee_addr);
return retval;
}
static void write_asic(unsigned int ioaddr, int location, short asic_data)
{
int i;
unsigned int ee_addr = ioaddr + DLINK_EEPROM;
short dataval;
int read_cmd = location | (EE_READ_CMD << 8);
asic_data |= read_eeprom(ioaddr, location);
outb(0, ee_addr);
outb(EE_ASIC|EE_CS|EE_DI, ee_addr);
read_cmd = read_cmd >> 1;
for (i = 9; i >= 0; i--) {
dataval = (read_cmd & (1 << i)) ? EE_DO : 0;
outb_p(EE_ASIC|EE_CS|EE_DI|dataval, ee_addr);
outb_p(EE_ASIC|EE_CS|EE_DI|dataval|EE_CK, ee_addr);
outb_p(EE_ASIC|EE_CS|EE_DI|dataval, ee_addr);
}
outb(EE_ASIC|EE_CS, ee_addr);
outb(EE_ASIC|EE_CS|EE_CK, ee_addr);
outb(EE_ASIC|EE_CS, ee_addr);
for (i = 15; i >= 0; i--) {
dataval = (asic_data & (1 << i)) ? EE_ADOT : 0;
outb_p(EE_ASIC|EE_CS|dataval, ee_addr);
outb_p(EE_ASIC|EE_CS|dataval|EE_CK, ee_addr);
outb_p(EE_ASIC|EE_CS|dataval, ee_addr);
}
outb(EE_ASIC|EE_DI, ee_addr);
outb(EE_ASIC|EE_DI| EE_CK, ee_addr);
outb(EE_ASIC|EE_DI, ee_addr);
outb(0, ee_addr);
}
static void set_misc_reg(struct net_device *dev)
{
unsigned int nic_base = dev->base_addr;
struct pcnet_dev *info = PRIV(dev);
u_char tmp;
if (info->flags & HAS_MISC_REG) {
tmp = inb_p(nic_base + PCNET_MISC) & ~3;
if (dev->if_port == 2)
tmp |= 1;
if (info->flags & USE_BIG_BUF)
tmp |= 2;
if (info->flags & HAS_IBM_MISC)
tmp |= 8;
outb_p(tmp, nic_base + PCNET_MISC);
}
if (info->flags & IS_DL10022) {
if (info->flags & HAS_MII) {
mdio_write(nic_base + DLINK_GPIO, info->eth_phy, 4, 0x01e1);
mdio_write(nic_base + DLINK_GPIO, info->eth_phy, 0, 0x0000);
mdio_write(nic_base + DLINK_GPIO, info->eth_phy, 0, 0x1200);
info->mii_reset = jiffies;
} else {
outb(full_duplex ? 4 : 0, nic_base + DLINK_DIAG);
}
} else if (info->flags & IS_DL10019) {
mdio_write(nic_base + DLINK_GPIO, info->eth_phy, 4, 0x01e1);
mdio_write(nic_base + DLINK_GPIO, info->eth_phy, 0, 0x0000);
mdio_write(nic_base + DLINK_GPIO, info->eth_phy, 0, 0x1200);
}
}
static void mii_phy_probe(struct net_device *dev)
{
struct pcnet_dev *info = PRIV(dev);
unsigned int mii_addr = dev->base_addr + DLINK_GPIO;
int i;
u_int tmp, phyid;
for (i = 31; i >= 0; i--) {
tmp = mdio_read(mii_addr, i, 1);
if ((tmp == 0) || (tmp == 0xffff))
continue;
tmp = mdio_read(mii_addr, i, MII_PHYID_REG1);
phyid = tmp << 16;
phyid |= mdio_read(mii_addr, i, MII_PHYID_REG2);
phyid &= MII_PHYID_REV_MASK;
netdev_dbg(dev, "MII at %d is 0x%08x\n", i, phyid);
if (phyid == AM79C9XX_HOME_PHY) {
info->pna_phy = i;
} else if (phyid != AM79C9XX_ETH_PHY) {
info->eth_phy = i;
}
}
}
static int pcnet_open(struct net_device *dev)
{
int ret;
struct pcnet_dev *info = PRIV(dev);
struct pcmcia_device *link = info->p_dev;
unsigned int nic_base = dev->base_addr;
dev_dbg(&link->dev, "pcnet_open('%s')\n", dev->name);
if (!pcmcia_dev_present(link))
return -ENODEV;
set_misc_reg(dev);
outb_p(0xFF, nic_base + EN0_ISR);
ret = request_irq(dev->irq, ei_irq_wrapper, IRQF_SHARED, dev->name, dev);
if (ret)
return ret;
link->open++;
info->phy_id = info->eth_phy;
info->link_status = 0x00;
init_timer(&info->watchdog);
info->watchdog.function = ei_watchdog;
info->watchdog.data = (u_long)dev;
info->watchdog.expires = jiffies + HZ;
add_timer(&info->watchdog);
return ei_open(dev);
}
static int pcnet_close(struct net_device *dev)
{
struct pcnet_dev *info = PRIV(dev);
struct pcmcia_device *link = info->p_dev;
dev_dbg(&link->dev, "pcnet_close('%s')\n", dev->name);
ei_close(dev);
free_irq(dev->irq, dev);
link->open--;
netif_stop_queue(dev);
del_timer_sync(&info->watchdog);
return 0;
}
static void pcnet_reset_8390(struct net_device *dev)
{
unsigned int nic_base = dev->base_addr;
int i;
ei_status.txing = ei_status.dmaing = 0;
outb_p(E8390_NODMA+E8390_PAGE0+E8390_STOP, nic_base + E8390_CMD);
outb(inb(nic_base + PCNET_RESET), nic_base + PCNET_RESET);
for (i = 0; i < 100; i++) {
if ((inb_p(nic_base+EN0_ISR) & ENISR_RESET) != 0)
break;
udelay(100);
}
outb_p(ENISR_RESET, nic_base + EN0_ISR);
if (i == 100)
netdev_err(dev, "pcnet_reset_8390() did not complete.\n");
set_misc_reg(dev);
}
static int set_config(struct net_device *dev, struct ifmap *map)
{
struct pcnet_dev *info = PRIV(dev);
if ((map->port != (u_char)(-1)) && (map->port != dev->if_port)) {
if (!(info->flags & HAS_MISC_REG))
return -EOPNOTSUPP;
else if ((map->port < 1) || (map->port > 2))
return -EINVAL;
dev->if_port = map->port;
netdev_info(dev, "switched to %s port\n", if_names[dev->if_port]);
NS8390_init(dev, 1);
}
return 0;
}
static irqreturn_t ei_irq_wrapper(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct pcnet_dev *info;
irqreturn_t ret = ei_interrupt(irq, dev_id);
if (ret == IRQ_HANDLED) {
info = PRIV(dev);
info->stale = 0;
}
return ret;
}
static void ei_watchdog(u_long arg)
{
struct net_device *dev = (struct net_device *)arg;
struct pcnet_dev *info = PRIV(dev);
unsigned int nic_base = dev->base_addr;
unsigned int mii_addr = nic_base + DLINK_GPIO;
u_short link;
if (!netif_device_present(dev)) goto reschedule;
if (info->stale++ && (inb_p(nic_base + EN0_ISR) & ENISR_ALL)) {
if (!info->fast_poll)
netdev_info(dev, "interrupt(s) dropped!\n");
ei_irq_wrapper(dev->irq, dev);
info->fast_poll = HZ;
}
if (info->fast_poll) {
info->fast_poll--;
info->watchdog.expires = jiffies + 1;
add_timer(&info->watchdog);
return;
}
if (!(info->flags & HAS_MII))
goto reschedule;
mdio_read(mii_addr, info->phy_id, 1);
link = mdio_read(mii_addr, info->phy_id, 1);
if (!link || (link == 0xffff)) {
if (info->eth_phy) {
info->phy_id = info->eth_phy = 0;
} else {
netdev_info(dev, "MII is missing!\n");
info->flags &= ~HAS_MII;
}
goto reschedule;
}
link &= 0x0004;
if (link != info->link_status) {
u_short p = mdio_read(mii_addr, info->phy_id, 5);
netdev_info(dev, "%s link beat\n", link ? "found" : "lost");
if (link && (info->flags & IS_DL10022)) {
outb((p & 0x0140) ? 4 : 0, nic_base + DLINK_DIAG);
} else if (link && (info->flags & IS_DL10019)) {
write_asic(dev->base_addr, 4, (p & 0x140) ? DL19FDUPLX : 0);
}
if (link) {
if (info->phy_id == info->eth_phy) {
if (p)
netdev_info(dev, "autonegotiation complete: "
"%sbaseT-%cD selected\n",
((p & 0x0180) ? "100" : "10"),
((p & 0x0140) ? 'F' : 'H'));
else
netdev_info(dev, "link partner did not autonegotiate\n");
}
NS8390_init(dev, 1);
}
info->link_status = link;
}
if (info->pna_phy && time_after(jiffies, info->mii_reset + 6*HZ)) {
link = mdio_read(mii_addr, info->eth_phy, 1) & 0x0004;
if (((info->phy_id == info->pna_phy) && link) ||
((info->phy_id != info->pna_phy) && !link)) {
mdio_write(mii_addr, info->phy_id, 0, 0x0400);
info->phy_id ^= info->pna_phy ^ info->eth_phy;
netdev_info(dev, "switched to %s transceiver\n",
(info->phy_id == info->eth_phy) ? "ethernet" : "PNA");
mdio_write(mii_addr, info->phy_id, 0,
(info->phy_id == info->eth_phy) ? 0x1000 : 0);
info->link_status = 0;
info->mii_reset = jiffies;
}
}
reschedule:
info->watchdog.expires = jiffies + HZ;
add_timer(&info->watchdog);
}
static int ei_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
struct pcnet_dev *info = PRIV(dev);
struct mii_ioctl_data *data = if_mii(rq);
unsigned int mii_addr = dev->base_addr + DLINK_GPIO;
if (!(info->flags & (IS_DL10019|IS_DL10022)))
return -EINVAL;
switch (cmd) {
case SIOCGMIIPHY:
data->phy_id = info->phy_id;
case SIOCGMIIREG:
data->val_out = mdio_read(mii_addr, data->phy_id, data->reg_num & 0x1f);
return 0;
case SIOCSMIIREG:
mdio_write(mii_addr, data->phy_id, data->reg_num & 0x1f, data->val_in);
return 0;
}
return -EOPNOTSUPP;
}
static void dma_get_8390_hdr(struct net_device *dev,
struct e8390_pkt_hdr *hdr,
int ring_page)
{
unsigned int nic_base = dev->base_addr;
if (ei_status.dmaing) {
netdev_err(dev, "DMAing conflict in dma_block_input."
"[DMAstat:%1x][irqlock:%1x]\n",
ei_status.dmaing, ei_status.irqlock);
return;
}
ei_status.dmaing |= 0x01;
outb_p(E8390_NODMA+E8390_PAGE0+E8390_START, nic_base + PCNET_CMD);
outb_p(sizeof(struct e8390_pkt_hdr), nic_base + EN0_RCNTLO);
outb_p(0, nic_base + EN0_RCNTHI);
outb_p(0, nic_base + EN0_RSARLO);
outb_p(ring_page, nic_base + EN0_RSARHI);
outb_p(E8390_RREAD+E8390_START, nic_base + PCNET_CMD);
insw(nic_base + PCNET_DATAPORT, hdr,
sizeof(struct e8390_pkt_hdr)>>1);
hdr->count = le16_to_cpu(hdr->count);
outb_p(ENISR_RDC, nic_base + EN0_ISR);
ei_status.dmaing &= ~0x01;
}
static void dma_block_input(struct net_device *dev, int count,
struct sk_buff *skb, int ring_offset)
{
unsigned int nic_base = dev->base_addr;
int xfer_count = count;
char *buf = skb->data;
struct ei_device *ei_local = netdev_priv(dev);
if ((netif_msg_rx_status(ei_local)) && (count != 4))
netdev_dbg(dev, "[bi=%d]\n", count+4);
if (ei_status.dmaing) {
netdev_err(dev, "DMAing conflict in dma_block_input."
"[DMAstat:%1x][irqlock:%1x]\n",
ei_status.dmaing, ei_status.irqlock);
return;
}
ei_status.dmaing |= 0x01;
outb_p(E8390_NODMA+E8390_PAGE0+E8390_START, nic_base + PCNET_CMD);
outb_p(count & 0xff, nic_base + EN0_RCNTLO);
outb_p(count >> 8, nic_base + EN0_RCNTHI);
outb_p(ring_offset & 0xff, nic_base + EN0_RSARLO);
outb_p(ring_offset >> 8, nic_base + EN0_RSARHI);
outb_p(E8390_RREAD+E8390_START, nic_base + PCNET_CMD);
insw(nic_base + PCNET_DATAPORT,buf,count>>1);
if (count & 0x01)
buf[count-1] = inb(nic_base + PCNET_DATAPORT), xfer_count++;
#ifdef PCMCIA_DEBUG
if (netif_msg_rx_status(ei_local)) {
int addr, tries = 20;
do {
int high = inb_p(nic_base + EN0_RSARHI);
int low = inb_p(nic_base + EN0_RSARLO);
addr = (high << 8) + low;
if (((ring_offset + xfer_count) & 0xff) == (addr & 0xff))
break;
} while (--tries > 0);
if (tries <= 0)
netdev_notice(dev, "RX transfer address mismatch,"
"%#4.4x (expected) vs. %#4.4x (actual).\n",
ring_offset + xfer_count, addr);
}
#endif
outb_p(ENISR_RDC, nic_base + EN0_ISR);
ei_status.dmaing &= ~0x01;
}
static void dma_block_output(struct net_device *dev, int count,
const u_char *buf, const int start_page)
{
unsigned int nic_base = dev->base_addr;
struct pcnet_dev *info = PRIV(dev);
#ifdef PCMCIA_DEBUG
int retries = 0;
struct ei_device *ei_local = netdev_priv(dev);
#endif
u_long dma_start;
#ifdef PCMCIA_DEBUG
netif_dbg(ei_local, tx_queued, dev, "[bo=%d]\n", count);
#endif
if (count & 0x01)
count++;
if (ei_status.dmaing) {
netdev_err(dev, "DMAing conflict in dma_block_output."
"[DMAstat:%1x][irqlock:%1x]\n",
ei_status.dmaing, ei_status.irqlock);
return;
}
ei_status.dmaing |= 0x01;
outb_p(E8390_PAGE0+E8390_START+E8390_NODMA, nic_base+PCNET_CMD);
#ifdef PCMCIA_DEBUG
retry:
#endif
outb_p(ENISR_RDC, nic_base + EN0_ISR);
outb_p(count & 0xff, nic_base + EN0_RCNTLO);
outb_p(count >> 8, nic_base + EN0_RCNTHI);
outb_p(0x00, nic_base + EN0_RSARLO);
outb_p(start_page, nic_base + EN0_RSARHI);
outb_p(E8390_RWRITE+E8390_START, nic_base + PCNET_CMD);
outsw(nic_base + PCNET_DATAPORT, buf, count>>1);
dma_start = jiffies;
#ifdef PCMCIA_DEBUG
if (netif_msg_tx_queued(ei_local)) {
int addr, tries = 20;
do {
int high = inb_p(nic_base + EN0_RSARHI);
int low = inb_p(nic_base + EN0_RSARLO);
addr = (high << 8) + low;
if ((start_page << 8) + count == addr)
break;
} while (--tries > 0);
if (tries <= 0) {
netdev_notice(dev, "Tx packet transfer address mismatch,"
"%#4.4x (expected) vs. %#4.4x (actual).\n",
(start_page << 8) + count, addr);
if (retries++ == 0)
goto retry;
}
}
#endif
while ((inb_p(nic_base + EN0_ISR) & ENISR_RDC) == 0)
if (time_after(jiffies, dma_start + PCNET_RDC_TIMEOUT)) {
netdev_warn(dev, "timeout waiting for Tx RDC.\n");
pcnet_reset_8390(dev);
NS8390_init(dev, 1);
break;
}
outb_p(ENISR_RDC, nic_base + EN0_ISR);
if (info->flags & DELAY_OUTPUT)
udelay((long)delay_time);
ei_status.dmaing &= ~0x01;
}
static int setup_dma_config(struct pcmcia_device *link, int start_pg,
int stop_pg)
{
struct net_device *dev = link->priv;
ei_status.tx_start_page = start_pg;
ei_status.rx_start_page = start_pg + TX_PAGES;
ei_status.stop_page = stop_pg;
ei_status.get_8390_hdr = dma_get_8390_hdr;
ei_status.block_input = dma_block_input;
ei_status.block_output = dma_block_output;
return 0;
}
static void copyin(void *dest, void __iomem *src, int c)
{
u_short *d = dest;
u_short __iomem *s = src;
int odd;
if (c <= 0)
return;
odd = (c & 1); c >>= 1;
if (c) {
do { *d++ = __raw_readw(s++); } while (--c);
}
if (odd)
*((u_char *)d) = readw(s) & 0xff;
}
static void copyout(void __iomem *dest, const void *src, int c)
{
u_short __iomem *d = dest;
const u_short *s = src;
int odd;
if (c <= 0)
return;
odd = (c & 1); c >>= 1;
if (c) {
do { __raw_writew(*s++, d++); } while (--c);
}
if (odd)
writew((readw(d) & 0xff00) | *(u_char *)s, d);
}
static void shmem_get_8390_hdr(struct net_device *dev,
struct e8390_pkt_hdr *hdr,
int ring_page)
{
void __iomem *xfer_start = ei_status.mem + (TX_PAGES<<8)
+ (ring_page << 8)
- (ei_status.rx_start_page << 8);
copyin(hdr, xfer_start, sizeof(struct e8390_pkt_hdr));
hdr->count = le16_to_cpu(hdr->count);
}
static void shmem_block_input(struct net_device *dev, int count,
struct sk_buff *skb, int ring_offset)
{
void __iomem *base = ei_status.mem;
unsigned long offset = (TX_PAGES<<8) + ring_offset
- (ei_status.rx_start_page << 8);
char *buf = skb->data;
if (offset + count > ei_status.priv) {
int semi_count = ei_status.priv - offset;
copyin(buf, base + offset, semi_count);
buf += semi_count;
offset = TX_PAGES<<8;
count -= semi_count;
}
copyin(buf, base + offset, count);
}
static void shmem_block_output(struct net_device *dev, int count,
const u_char *buf, const int start_page)
{
void __iomem *shmem = ei_status.mem + (start_page << 8);
shmem -= ei_status.tx_start_page << 8;
copyout(shmem, buf, count);
}
static int setup_shmem_window(struct pcmcia_device *link, int start_pg,
int stop_pg, int cm_offset)
{
struct net_device *dev = link->priv;
struct pcnet_dev *info = PRIV(dev);
int i, window_size, offset, ret;
window_size = (stop_pg - start_pg) << 8;
if (window_size > 32 * 1024)
window_size = 32 * 1024;
window_size = roundup_pow_of_two(window_size);
link->resource[3]->flags |= WIN_DATA_WIDTH_16|WIN_MEMORY_TYPE_CM|WIN_ENABLE;
link->resource[3]->flags |= WIN_USE_WAIT;
link->resource[3]->start = 0; link->resource[3]->end = window_size;
ret = pcmcia_request_window(link, link->resource[3], mem_speed);
if (ret)
goto failed;
offset = (start_pg << 8) + cm_offset;
offset -= offset % window_size;
ret = pcmcia_map_mem_page(link, link->resource[3], offset);
if (ret)
goto failed;
info->base = ioremap(link->resource[3]->start,
resource_size(link->resource[3]));
for (i = 0; i < (TX_PAGES<<8); i += 2)
__raw_writew((i>>1), info->base+offset+i);
udelay(100);
for (i = 0; i < (TX_PAGES<<8); i += 2)
if (__raw_readw(info->base+offset+i) != (i>>1)) break;
pcnet_reset_8390(dev);
if (i != (TX_PAGES<<8)) {
iounmap(info->base);
pcmcia_release_window(link, link->resource[3]);
info->base = NULL;
goto failed;
}
ei_status.mem = info->base + offset;
ei_status.priv = resource_size(link->resource[3]);
dev->mem_start = (u_long)ei_status.mem;
dev->mem_end = dev->mem_start + resource_size(link->resource[3]);
ei_status.tx_start_page = start_pg;
ei_status.rx_start_page = start_pg + TX_PAGES;
ei_status.stop_page = start_pg + (
(resource_size(link->resource[3]) - offset) >> 8);
ei_status.get_8390_hdr = shmem_get_8390_hdr;
ei_status.block_input = shmem_block_input;
ei_status.block_output = shmem_block_output;
info->flags |= USE_SHMEM;
return 0;
failed:
return 1;
}
