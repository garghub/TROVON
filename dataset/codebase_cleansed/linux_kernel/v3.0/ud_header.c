void ib_ud_header_init(int payload_bytes,
int lrh_present,
int eth_present,
int vlan_present,
int grh_present,
int immediate_present,
struct ib_ud_header *header)
{
memset(header, 0, sizeof *header);
if (lrh_present) {
u16 packet_length;
header->lrh.link_version = 0;
header->lrh.link_next_header =
grh_present ? IB_LNH_IBA_GLOBAL : IB_LNH_IBA_LOCAL;
packet_length = (IB_LRH_BYTES +
IB_BTH_BYTES +
IB_DETH_BYTES +
(grh_present ? IB_GRH_BYTES : 0) +
payload_bytes +
4 +
3) / 4;
header->lrh.packet_length = cpu_to_be16(packet_length);
}
if (vlan_present)
header->eth.type = cpu_to_be16(ETH_P_8021Q);
if (grh_present) {
header->grh.ip_version = 6;
header->grh.payload_length =
cpu_to_be16((IB_BTH_BYTES +
IB_DETH_BYTES +
payload_bytes +
4 +
3) & ~3);
header->grh.next_header = 0x1b;
}
if (immediate_present)
header->bth.opcode = IB_OPCODE_UD_SEND_ONLY_WITH_IMMEDIATE;
else
header->bth.opcode = IB_OPCODE_UD_SEND_ONLY;
header->bth.pad_count = (4 - payload_bytes) & 3;
header->bth.transport_header_version = 0;
header->lrh_present = lrh_present;
header->eth_present = eth_present;
header->vlan_present = vlan_present;
header->grh_present = grh_present;
header->immediate_present = immediate_present;
}
int ib_ud_header_pack(struct ib_ud_header *header,
void *buf)
{
int len = 0;
if (header->lrh_present) {
ib_pack(lrh_table, ARRAY_SIZE(lrh_table),
&header->lrh, buf + len);
len += IB_LRH_BYTES;
}
if (header->eth_present) {
ib_pack(eth_table, ARRAY_SIZE(eth_table),
&header->eth, buf + len);
len += IB_ETH_BYTES;
}
if (header->vlan_present) {
ib_pack(vlan_table, ARRAY_SIZE(vlan_table),
&header->vlan, buf + len);
len += IB_VLAN_BYTES;
}
if (header->grh_present) {
ib_pack(grh_table, ARRAY_SIZE(grh_table),
&header->grh, buf + len);
len += IB_GRH_BYTES;
}
ib_pack(bth_table, ARRAY_SIZE(bth_table),
&header->bth, buf + len);
len += IB_BTH_BYTES;
ib_pack(deth_table, ARRAY_SIZE(deth_table),
&header->deth, buf + len);
len += IB_DETH_BYTES;
if (header->immediate_present) {
memcpy(buf + len, &header->immediate_data, sizeof header->immediate_data);
len += sizeof header->immediate_data;
}
return len;
}
int ib_ud_header_unpack(void *buf,
struct ib_ud_header *header)
{
ib_unpack(lrh_table, ARRAY_SIZE(lrh_table),
buf, &header->lrh);
buf += IB_LRH_BYTES;
if (header->lrh.link_version != 0) {
printk(KERN_WARNING "Invalid LRH.link_version %d\n",
header->lrh.link_version);
return -EINVAL;
}
switch (header->lrh.link_next_header) {
case IB_LNH_IBA_LOCAL:
header->grh_present = 0;
break;
case IB_LNH_IBA_GLOBAL:
header->grh_present = 1;
ib_unpack(grh_table, ARRAY_SIZE(grh_table),
buf, &header->grh);
buf += IB_GRH_BYTES;
if (header->grh.ip_version != 6) {
printk(KERN_WARNING "Invalid GRH.ip_version %d\n",
header->grh.ip_version);
return -EINVAL;
}
if (header->grh.next_header != 0x1b) {
printk(KERN_WARNING "Invalid GRH.next_header 0x%02x\n",
header->grh.next_header);
return -EINVAL;
}
break;
default:
printk(KERN_WARNING "Invalid LRH.link_next_header %d\n",
header->lrh.link_next_header);
return -EINVAL;
}
ib_unpack(bth_table, ARRAY_SIZE(bth_table),
buf, &header->bth);
buf += IB_BTH_BYTES;
switch (header->bth.opcode) {
case IB_OPCODE_UD_SEND_ONLY:
header->immediate_present = 0;
break;
case IB_OPCODE_UD_SEND_ONLY_WITH_IMMEDIATE:
header->immediate_present = 1;
break;
default:
printk(KERN_WARNING "Invalid BTH.opcode 0x%02x\n",
header->bth.opcode);
return -EINVAL;
}
if (header->bth.transport_header_version != 0) {
printk(KERN_WARNING "Invalid BTH.transport_header_version %d\n",
header->bth.transport_header_version);
return -EINVAL;
}
ib_unpack(deth_table, ARRAY_SIZE(deth_table),
buf, &header->deth);
buf += IB_DETH_BYTES;
if (header->immediate_present)
memcpy(&header->immediate_data, buf, sizeof header->immediate_data);
return 0;
}
