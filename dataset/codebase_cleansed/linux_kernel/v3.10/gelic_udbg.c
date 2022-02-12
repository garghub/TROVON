static void map_dma_mem(int bus_id, int dev_id, void *start, size_t len,
u64 *real_bus_addr)
{
s64 result;
u64 real_addr = ((u64)start) & 0x0fffffffffffffffUL;
u64 real_end = real_addr + len;
u64 map_start = real_addr & ~0xfff;
u64 map_end = (real_end + 0xfff) & ~0xfff;
u64 bus_addr = 0;
u64 flags = 0xf800000000000000UL;
result = lv1_allocate_device_dma_region(bus_id, dev_id,
map_end - map_start, 12, 0,
&bus_addr);
if (result)
lv1_panic(0);
result = lv1_map_device_dma_region(bus_id, dev_id, map_start,
bus_addr, map_end - map_start,
flags);
if (result)
lv1_panic(0);
*real_bus_addr = bus_addr + real_addr - map_start;
}
static int unmap_dma_mem(int bus_id, int dev_id, u64 bus_addr, size_t len)
{
s64 result;
u64 real_bus_addr;
real_bus_addr = bus_addr & ~0xfff;
len += bus_addr - real_bus_addr;
len = (len + 0xfff) & ~0xfff;
result = lv1_unmap_device_dma_region(bus_id, dev_id, real_bus_addr,
len);
if (result)
return result;
return lv1_free_device_dma_region(bus_id, dev_id, real_bus_addr);
}
static void gelic_debug_init(void)
{
s64 result;
u64 v2;
u64 mac;
u64 vlan_id;
result = lv1_open_device(GELIC_BUS_ID, GELIC_DEVICE_ID, 0);
if (result)
lv1_panic(0);
map_dma_mem(GELIC_BUS_ID, GELIC_DEVICE_ID, &dbg, sizeof(dbg),
&bus_addr);
memset(&dbg, 0, sizeof(dbg));
dbg.descr.buf_addr = bus_addr + offsetof(struct debug_block, pkt);
wmb();
result = lv1_net_control(GELIC_BUS_ID, GELIC_DEVICE_ID,
GELIC_LV1_GET_MAC_ADDRESS, 0, 0, 0,
&mac, &v2);
if (result)
lv1_panic(0);
mac <<= 16;
h_eth = (struct ethhdr *)dbg.pkt;
memset(&h_eth->dest, 0xff, 6);
memcpy(&h_eth->src, &mac, 6);
header_size = sizeof(struct ethhdr);
result = lv1_net_control(GELIC_BUS_ID, GELIC_DEVICE_ID,
GELIC_LV1_GET_VLAN_ID,
GELIC_LV1_VLAN_TX_ETHERNET_0, 0, 0,
&vlan_id, &v2);
if (!result) {
h_eth->type = 0x8100;
header_size += sizeof(struct vlantag);
h_vlan = (struct vlantag *)(h_eth + 1);
h_vlan->vlan = vlan_id;
h_vlan->subtype = 0x0800;
h_ip = (struct iphdr *)(h_vlan + 1);
} else {
h_eth->type = 0x0800;
h_ip = (struct iphdr *)(h_eth + 1);
}
header_size += sizeof(struct iphdr);
h_ip->ver_len = 0x45;
h_ip->ttl = 10;
h_ip->proto = 0x11;
h_ip->src = 0x00000000;
h_ip->dest = 0xffffffff;
header_size += sizeof(struct udphdr);
h_udp = (struct udphdr *)(h_ip + 1);
h_udp->src = GELIC_DEBUG_PORT;
h_udp->dest = GELIC_DEBUG_PORT;
pmsgc = pmsg = (char *)(h_udp + 1);
}
static void gelic_debug_shutdown(void)
{
if (bus_addr)
unmap_dma_mem(GELIC_BUS_ID, GELIC_DEVICE_ID,
bus_addr, sizeof(dbg));
lv1_close_device(GELIC_BUS_ID, GELIC_DEVICE_ID);
}
static void gelic_sendbuf(int msgsize)
{
u16 *p;
u32 sum;
int i;
dbg.descr.buf_size = header_size + msgsize;
h_ip->total_length = msgsize + sizeof(struct udphdr) +
sizeof(struct iphdr);
h_udp->len = msgsize + sizeof(struct udphdr);
h_ip->checksum = 0;
sum = 0;
p = (u16 *)h_ip;
for (i = 0; i < 5; i++)
sum += *p++;
h_ip->checksum = ~(sum + (sum >> 16));
dbg.descr.dmac_cmd_status = GELIC_DESCR_DMA_CMD_NO_CHKSUM |
GELIC_DESCR_TX_DMA_FRAME_TAIL;
dbg.descr.result_size = 0;
dbg.descr.data_status = 0;
wmb();
lv1_net_start_tx_dma(GELIC_BUS_ID, GELIC_DEVICE_ID, bus_addr, 0);
while ((dbg.descr.dmac_cmd_status & GELIC_DESCR_DMA_STAT_MASK) ==
GELIC_DESCR_DMA_CARDOWNED)
cpu_relax();
}
static void ps3gelic_udbg_putc(char ch)
{
*pmsgc++ = ch;
if (ch == '\n' || (pmsgc-pmsg) >= GELIC_MAX_MESSAGE_SIZE) {
gelic_sendbuf(pmsgc-pmsg);
pmsgc = pmsg;
}
}
void __init udbg_init_ps3gelic(void)
{
gelic_debug_init();
udbg_putc = ps3gelic_udbg_putc;
}
void udbg_shutdown_ps3gelic(void)
{
udbg_putc = NULL;
gelic_debug_shutdown();
}
