static void vsc_read(adapter_t *adapter, u32 addr, u32 *val)
{
u32 status, vlo, vhi;
int i;
spin_lock_bh(&adapter->mac_lock);
t1_tpi_read(adapter, (addr << 2) + 4, &vlo);
i = 0;
do {
t1_tpi_read(adapter, (REG_LOCAL_STATUS << 2) + 4, &vlo);
t1_tpi_read(adapter, REG_LOCAL_STATUS << 2, &vhi);
status = (vhi << 16) | vlo;
i++;
} while (((status & 1) == 0) && (i < 50));
if (i == 50)
pr_err("Invalid tpi read from MAC, breaking loop.\n");
t1_tpi_read(adapter, (REG_LOCAL_DATA << 2) + 4, &vlo);
t1_tpi_read(adapter, REG_LOCAL_DATA << 2, &vhi);
*val = (vhi << 16) | vlo;
spin_unlock_bh(&adapter->mac_lock);
}
static void vsc_write(adapter_t *adapter, u32 addr, u32 data)
{
spin_lock_bh(&adapter->mac_lock);
t1_tpi_write(adapter, (addr << 2) + 4, data & 0xFFFF);
t1_tpi_write(adapter, addr << 2, (data >> 16) & 0xFFFF);
spin_unlock_bh(&adapter->mac_lock);
}
static void vsc7326_full_reset(adapter_t* adapter)
{
u32 val;
u32 result = 0xffff;
t1_tpi_read(adapter, A_ELMER0_GPO, &val);
val &= ~1;
t1_tpi_write(adapter, A_ELMER0_GPO, val);
udelay(2);
val |= 0x1;
val |= 0x800;
t1_tpi_write(adapter, A_ELMER0_GPO, val);
mdelay(1);
vsc_write(adapter, REG_SW_RESET, 0x80000001);
do {
mdelay(1);
vsc_read(adapter, REG_SW_RESET, &result);
} while (result != 0x0);
}
static void run_table(adapter_t *adapter, struct init_table *ib, int len)
{
int i;
for (i = 0; i < len; i++) {
if (ib[i].addr == INITBLOCK_SLEEP) {
udelay( ib[i].data );
pr_err("sleep %d us\n",ib[i].data);
} else
vsc_write( adapter, ib[i].addr, ib[i].data );
}
}
static int bist_rd(adapter_t *adapter, int moduleid, int address)
{
int data = 0;
u32 result = 0;
if ((address != 0x0) &&
(address != 0x1) &&
(address != 0x2) &&
(address != 0xd) &&
(address != 0xe))
pr_err("No bist address: 0x%x\n", address);
data = ((0x00 << 24) | ((address & 0xff) << 16) | (0x00 << 8) |
((moduleid & 0xff) << 0));
vsc_write(adapter, REG_RAM_BIST_CMD, data);
udelay(10);
vsc_read(adapter, REG_RAM_BIST_RESULT, &result);
if ((result & (1 << 9)) != 0x0)
pr_err("Still in bist read: 0x%x\n", result);
else if ((result & (1 << 8)) != 0x0)
pr_err("bist read error: 0x%x\n", result);
return result & 0xff;
}
static int bist_wr(adapter_t *adapter, int moduleid, int address, int value)
{
int data = 0;
u32 result = 0;
if ((address != 0x0) &&
(address != 0x1) &&
(address != 0x2) &&
(address != 0xd) &&
(address != 0xe))
pr_err("No bist address: 0x%x\n", address);
if (value > 255)
pr_err("Suspicious write out of range value: 0x%x\n", value);
data = ((0x01 << 24) | ((address & 0xff) << 16) | (value << 8) |
((moduleid & 0xff) << 0));
vsc_write(adapter, REG_RAM_BIST_CMD, data);
udelay(5);
vsc_read(adapter, REG_RAM_BIST_CMD, &result);
if ((result & (1 << 27)) != 0x0)
pr_err("Still in bist write: 0x%x\n", result);
else if ((result & (1 << 26)) != 0x0)
pr_err("bist write error: 0x%x\n", result);
return 0;
}
static int run_bist(adapter_t *adapter, int moduleid)
{
(void) bist_wr(adapter,moduleid, 0x00, 0x02);
(void) bist_wr(adapter,moduleid, 0x01, 0x01);
return 0;
}
static int check_bist(adapter_t *adapter, int moduleid)
{
int result=0;
int column=0;
result = bist_rd(adapter,moduleid, 0x02);
column = ((bist_rd(adapter,moduleid, 0x0e)<<8) +
(bist_rd(adapter,moduleid, 0x0d)));
if ((result & 3) != 0x3)
pr_err("Result: 0x%x BIST error in ram %d, column: 0x%04x\n",
result, moduleid, column);
return 0;
}
static int enable_mem(adapter_t *adapter, int moduleid)
{
(void) bist_wr(adapter,moduleid, 0x00, 0x00);
return 0;
}
static int run_bist_all(adapter_t *adapter)
{
int port = 0;
u32 val = 0;
vsc_write(adapter, REG_MEM_BIST, 0x5);
vsc_read(adapter, REG_MEM_BIST, &val);
for (port = 0; port < 12; port++)
vsc_write(adapter, REG_DEV_SETUP(port), 0x0);
udelay(300);
vsc_write(adapter, REG_SPI4_MISC, 0x00040409);
udelay(300);
(void) run_bist(adapter,13);
(void) run_bist(adapter,14);
(void) run_bist(adapter,20);
(void) run_bist(adapter,21);
mdelay(200);
(void) check_bist(adapter,13);
(void) check_bist(adapter,14);
(void) check_bist(adapter,20);
(void) check_bist(adapter,21);
udelay(100);
(void) enable_mem(adapter,13);
(void) enable_mem(adapter,14);
(void) enable_mem(adapter,20);
(void) enable_mem(adapter,21);
udelay(300);
vsc_write(adapter, REG_SPI4_MISC, 0x60040400);
udelay(300);
for (port = 0; port < 12; port++)
vsc_write(adapter, REG_DEV_SETUP(port), 0x1);
udelay(300);
vsc_write(adapter, REG_MEM_BIST, 0x0);
mdelay(10);
return 0;
}
static int mac_intr_handler(struct cmac *mac)
{
return 0;
}
static int mac_intr_enable(struct cmac *mac)
{
return 0;
}
static int mac_intr_disable(struct cmac *mac)
{
return 0;
}
static int mac_intr_clear(struct cmac *mac)
{
return 0;
}
static int mac_set_address(struct cmac* mac, u8 addr[6])
{
u32 val;
int port = mac->instance->index;
vsc_write(mac->adapter, REG_MAC_LOW_ADDR(port),
(addr[3] << 16) | (addr[4] << 8) | addr[5]);
vsc_write(mac->adapter, REG_MAC_HIGH_ADDR(port),
(addr[0] << 16) | (addr[1] << 8) | addr[2]);
vsc_read(mac->adapter, REG_ING_FFILT_UM_EN, &val);
val &= ~0xf0000000;
vsc_write(mac->adapter, REG_ING_FFILT_UM_EN, val | (port << 28));
vsc_write(mac->adapter, REG_ING_FFILT_MASK0,
0xffff0000 | (addr[4] << 8) | addr[5]);
vsc_write(mac->adapter, REG_ING_FFILT_MASK1,
0xffff0000 | (addr[2] << 8) | addr[3]);
vsc_write(mac->adapter, REG_ING_FFILT_MASK2,
0xffff0000 | (addr[0] << 8) | addr[1]);
return 0;
}
static int mac_get_address(struct cmac *mac, u8 addr[6])
{
u32 addr_lo, addr_hi;
int port = mac->instance->index;
vsc_read(mac->adapter, REG_MAC_LOW_ADDR(port), &addr_lo);
vsc_read(mac->adapter, REG_MAC_HIGH_ADDR(port), &addr_hi);
addr[0] = (u8) (addr_hi >> 16);
addr[1] = (u8) (addr_hi >> 8);
addr[2] = (u8) addr_hi;
addr[3] = (u8) (addr_lo >> 16);
addr[4] = (u8) (addr_lo >> 8);
addr[5] = (u8) addr_lo;
return 0;
}
static int mac_reset(struct cmac *mac)
{
int index = mac->instance->index;
run_table(mac->adapter, vsc7326_portinit[index],
ARRAY_SIZE(vsc7326_portinit[index]));
return 0;
}
static int mac_set_rx_mode(struct cmac *mac, struct t1_rx_mode *rm)
{
u32 v;
int port = mac->instance->index;
vsc_read(mac->adapter, REG_ING_FFILT_UM_EN, &v);
v |= 1 << 12;
if (t1_rx_mode_promisc(rm))
v &= ~(1 << (port + 16));
else
v |= 1 << (port + 16);
vsc_write(mac->adapter, REG_ING_FFILT_UM_EN, v);
return 0;
}
static int mac_set_mtu(struct cmac *mac, int mtu)
{
int port = mac->instance->index;
vsc_write(mac->adapter, REG_MAX_LEN(port), mtu + 14 + 4);
return 0;
}
static int mac_set_speed_duplex_fc(struct cmac *mac, int speed, int duplex,
int fc)
{
u32 v;
int enable, port = mac->instance->index;
if (speed >= 0 && speed != SPEED_10 && speed != SPEED_100 &&
speed != SPEED_1000)
return -1;
if (duplex > 0 && duplex != DUPLEX_FULL)
return -1;
if (speed >= 0) {
vsc_read(mac->adapter, REG_MODE_CFG(port), &v);
enable = v & 3;
v &= ~0xf;
v |= 4;
if (speed == SPEED_1000)
v |= 8;
enable |= v;
vsc_write(mac->adapter, REG_MODE_CFG(port), v);
if (speed == SPEED_1000)
v = 0x82;
else if (speed == SPEED_100)
v = 0x84;
else
v = 0x86;
vsc_write(mac->adapter, REG_DEV_SETUP(port), v | 1);
vsc_write(mac->adapter, REG_DEV_SETUP(port), v);
vsc_read(mac->adapter, REG_DBG(port), &v);
v &= ~0xff00;
if (speed == SPEED_1000)
v |= 0x400;
else if (speed == SPEED_100)
v |= 0x2000;
else
v |= 0xff00;
vsc_write(mac->adapter, REG_DBG(port), v);
vsc_write(mac->adapter, REG_TX_IFG(port),
speed == SPEED_1000 ? 5 : 0x11);
if (duplex == DUPLEX_HALF)
enable = 0x0;
else if (speed == SPEED_1000)
enable = 0xc;
else
enable = 0x4;
enable |= 0x9 << 10;
enable |= 0x6 << 6;
enable |= 0x1 << 4;
enable |= 0x3;
vsc_write(mac->adapter, REG_MODE_CFG(port), enable);
}
vsc_read(mac->adapter, REG_PAUSE_CFG(port), &v);
v &= 0xfff0ffff;
v |= 0x20000;
if (fc & PAUSE_RX)
v |= 0x40000;
if (fc & PAUSE_TX)
v |= 0x80000;
if (fc == (PAUSE_RX | PAUSE_TX))
v |= 0x10000;
vsc_write(mac->adapter, REG_PAUSE_CFG(port), v);
return 0;
}
static int mac_enable(struct cmac *mac, int which)
{
u32 val;
int port = mac->instance->index;
vsc_write(mac->adapter, REG_HIGH_LOW_WM(1,port), WM_ENABLE);
vsc_read(mac->adapter, REG_MODE_CFG(port), &val);
if (which & MAC_DIRECTION_RX)
val |= 0x2;
if (which & MAC_DIRECTION_TX)
val |= 1;
vsc_write(mac->adapter, REG_MODE_CFG(port), val);
return 0;
}
static int mac_disable(struct cmac *mac, int which)
{
u32 val;
int i, port = mac->instance->index;
mac_reset(mac);
vsc_read(mac->adapter, REG_MODE_CFG(port), &val);
if (which & MAC_DIRECTION_RX)
val &= ~0x2;
if (which & MAC_DIRECTION_TX)
val &= ~0x1;
vsc_write(mac->adapter, REG_MODE_CFG(port), val);
vsc_read(mac->adapter, REG_MODE_CFG(port), &val);
for (i = 0; i <= 0x3a; ++i)
vsc_write(mac->adapter, CRA(4, port, i), 0);
memset(&mac->stats, 0, sizeof(struct cmac_statistics));
return 0;
}
static void rmon_update(struct cmac *mac, unsigned int addr, u64 *stat)
{
u32 v, lo;
vsc_read(mac->adapter, addr, &v);
lo = *stat;
*stat = *stat - lo + v;
if (v == 0)
return;
if (v < lo)
*stat += (1ULL << 32);
}
static void port_stats_update(struct cmac *mac)
{
struct {
unsigned int reg;
unsigned int offset;
} hw_stats[] = {
#define HW_STAT(reg, stat_name) \
{ reg, (&((struct cmac_statistics *)NULL)->stat_name) - (u64 *)NULL }
HW_STAT(RxUnicast, RxUnicastFramesOK),
HW_STAT(RxMulticast, RxMulticastFramesOK),
HW_STAT(RxBroadcast, RxBroadcastFramesOK),
HW_STAT(Crc, RxFCSErrors),
HW_STAT(RxAlignment, RxAlignErrors),
HW_STAT(RxOversize, RxFrameTooLongErrors),
HW_STAT(RxPause, RxPauseFrames),
HW_STAT(RxJabbers, RxJabberErrors),
HW_STAT(RxFragments, RxRuntErrors),
HW_STAT(RxUndersize, RxRuntErrors),
HW_STAT(RxSymbolCarrier, RxSymbolErrors),
HW_STAT(RxSize1519ToMax, RxJumboFramesOK),
HW_STAT(TxUnicast, TxUnicastFramesOK),
HW_STAT(TxMulticast, TxMulticastFramesOK),
HW_STAT(TxBroadcast, TxBroadcastFramesOK),
HW_STAT(TxPause, TxPauseFrames),
HW_STAT(TxUnderrun, TxUnderrun),
HW_STAT(TxSize1519ToMax, TxJumboFramesOK),
}, *p = hw_stats;
unsigned int port = mac->instance->index;
u64 *stats = (u64 *)&mac->stats;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(hw_stats); i++)
rmon_update(mac, CRA(0x4, port, p->reg), stats + p->offset);
rmon_update(mac, REG_TX_OK_BYTES(port), &mac->stats.TxOctetsOK);
rmon_update(mac, REG_RX_OK_BYTES(port), &mac->stats.RxOctetsOK);
rmon_update(mac, REG_RX_BAD_BYTES(port), &mac->stats.RxOctetsBad);
}
static const struct cmac_statistics *mac_update_statistics(struct cmac *mac,
int flag)
{
if (flag == MAC_STATS_UPDATE_FULL ||
mac->instance->ticks >= MAJOR_UPDATE_TICKS) {
port_stats_update(mac);
mac->instance->ticks = 0;
} else {
int port = mac->instance->index;
rmon_update(mac, REG_RX_OK_BYTES(port),
&mac->stats.RxOctetsOK);
rmon_update(mac, REG_RX_BAD_BYTES(port),
&mac->stats.RxOctetsBad);
rmon_update(mac, REG_TX_OK_BYTES(port),
&mac->stats.TxOctetsOK);
mac->instance->ticks++;
}
return &mac->stats;
}
static void mac_destroy(struct cmac *mac)
{
kfree(mac);
}
static struct cmac *vsc7326_mac_create(adapter_t *adapter, int index)
{
struct cmac *mac;
u32 val;
int i;
mac = kzalloc(sizeof(*mac) + sizeof(cmac_instance), GFP_KERNEL);
if (!mac)
return NULL;
mac->ops = &vsc7326_ops;
mac->instance = (cmac_instance *)(mac + 1);
mac->adapter = adapter;
mac->instance->index = index;
mac->instance->ticks = 0;
i = 0;
do {
u32 vhi, vlo;
vhi = vlo = 0;
t1_tpi_read(adapter, (REG_LOCAL_STATUS << 2) + 4, &vlo);
udelay(1);
t1_tpi_read(adapter, REG_LOCAL_STATUS << 2, &vhi);
udelay(5);
val = (vhi << 16) | vlo;
} while ((++i < 10000) && (val == 0xffffffff));
return mac;
}
static int vsc7326_mac_reset(adapter_t *adapter)
{
vsc7326_full_reset(adapter);
(void) run_bist_all(adapter);
run_table(adapter, vsc7326_reset, ARRAY_SIZE(vsc7326_reset));
return 0;
}
