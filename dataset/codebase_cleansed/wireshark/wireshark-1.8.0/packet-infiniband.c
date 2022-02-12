guint
g_int64_hash (gconstpointer v)
{
return (guint) *(const gint64*) v;
}
gboolean
g_int64_equal (gconstpointer v1,
gconstpointer v2)
{
return *((const gint64*) v1) == *((const gint64*) v2);
}
void table_destroy_notify(gpointer data) {
g_free(data);
}
static void
dissect_roce(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_infiniband_common(tvb, pinfo, tree, TRUE);
}
static void
dissect_infiniband(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_infiniband_common(tvb, pinfo, tree, FALSE);
}
static void
dissect_infiniband_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, gboolean starts_with_grh)
{
proto_item *infiniband_packet;
proto_tree *all_headers_tree;
proto_item *local_route_header_item;
proto_tree *local_route_header_tree;
proto_item *RAWDATA_header_item;
guint8 lnh_val;
gint offset = 0;
gboolean bthFollows = FALSE;
guint8 opCode = 0;
gint32 nextHeaderSequence = -1;
guint8 nxtHdr = 0;
guint16 packetLength = 0;
struct e_in6_addr SRCgid;
struct e_in6_addr DSTgid;
gint crc_length = 0;
if (!src_addr)
src_addr = se_alloc(ADDR_MAX_LEN);
if (!dst_addr)
dst_addr = se_alloc(ADDR_MAX_LEN);
pinfo->srcport = pinfo->destport = 0xffffffff;
if (!pinfo->fd->flags.visited)
{
pinfo->ptype = PT_IBQP;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "InfiniBand");
col_clear(pinfo->cinfo, COL_INFO);
if (tree && tree->parent)
{
tree = tree->parent;
top_tree = tree;
}
if (0 && !tree)
{
dissect_general_info(tvb, offset, pinfo, starts_with_grh);
return;
}
infiniband_packet = proto_tree_add_item(tree, proto_infiniband, tvb, offset, -1, ENC_NA);
all_headers_tree = proto_item_add_subtree(infiniband_packet, ett_all_headers);
if (starts_with_grh) {
lnh_val = IBA_GLOBAL;
packetLength = tvb_get_ntohs(tvb, 4);
goto skip_lrh;
}
local_route_header_item = proto_tree_add_item(all_headers_tree, hf_infiniband_LRH, tvb, offset, 8, ENC_NA);
proto_item_set_text(local_route_header_item, "%s", "Local Route Header");
local_route_header_tree = proto_item_add_subtree(local_route_header_item, ett_lrh);
proto_tree_add_item(local_route_header_tree, hf_infiniband_virtual_lane, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(local_route_header_tree, hf_infiniband_link_version, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(local_route_header_tree, hf_infiniband_service_level, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(local_route_header_tree, hf_infiniband_reserved2, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(local_route_header_tree, hf_infiniband_link_next_header, tvb, offset, 1, ENC_BIG_ENDIAN);
lnh_val = tvb_get_guint8(tvb, offset);
lnh_val = lnh_val & 0x03;
offset += 1;
proto_tree_add_item(local_route_header_tree, hf_infiniband_destination_local_id, tvb, offset, 2, ENC_BIG_ENDIAN);
*((guint16*) dst_addr) = tvb_get_ntohs(tvb, offset);
SET_ADDRESS(&pinfo->dst, AT_IB, sizeof(guint16), dst_addr);
offset += 2;
proto_tree_add_item(local_route_header_tree, hf_infiniband_reserved5, tvb, offset, 2, ENC_BIG_ENDIAN);
packetLength = tvb_get_ntohs(tvb, offset);
packetLength = packetLength & 0x07FF;
packetLength = packetLength * 4;
proto_tree_add_item(local_route_header_tree, hf_infiniband_packet_length, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(local_route_header_tree, hf_infiniband_source_local_id, tvb, offset, 2, ENC_BIG_ENDIAN);
*((guint16*) src_addr) = tvb_get_ntohs(tvb, offset);
SET_ADDRESS(&pinfo->src, AT_IB, sizeof(guint16), src_addr);
offset += 2;
packetLength -= 8;
skip_lrh:
switch (lnh_val)
{
case IBA_GLOBAL: {
proto_item *global_route_header_item;
proto_tree *global_route_header_tree;
global_route_header_item = proto_tree_add_item(all_headers_tree, hf_infiniband_GRH, tvb, offset, 40, ENC_NA);
proto_item_set_text(global_route_header_item, "%s", "Global Route Header");
global_route_header_tree = proto_item_add_subtree(global_route_header_item, ett_grh);
proto_tree_add_item(global_route_header_tree, hf_infiniband_ip_version, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(global_route_header_tree, hf_infiniband_traffic_class, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(global_route_header_tree, hf_infiniband_flow_label, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
proto_tree_add_item(global_route_header_tree, hf_infiniband_payload_length, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
nxtHdr = tvb_get_guint8(tvb, offset);
proto_tree_add_item(global_route_header_tree, hf_infiniband_next_header, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(global_route_header_tree, hf_infiniband_hop_limit, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(global_route_header_tree, hf_infiniband_source_gid, tvb, offset, 16, ENC_NA);
tvb_get_ipv6(tvb, offset, &SRCgid);
memcpy(src_addr, &SRCgid, GID_SIZE);
SET_ADDRESS(&pinfo->src, AT_IB, GID_SIZE, src_addr);
offset += 16;
proto_tree_add_item(global_route_header_tree, hf_infiniband_destination_gid, tvb, offset, 16, ENC_NA);
tvb_get_ipv6(tvb, offset, &DSTgid);
memcpy(dst_addr, &DSTgid, GID_SIZE);
SET_ADDRESS(&pinfo->dst, AT_IB, GID_SIZE, dst_addr);
offset += 16;
packetLength -= 40;
if (nxtHdr != 0x1B)
{
break;
}
}
case IBA_LOCAL: {
proto_item *base_transport_header_item;
proto_tree *base_transport_header_tree;
bthFollows = TRUE;
base_transport_header_item = proto_tree_add_item(all_headers_tree, hf_infiniband_BTH, tvb, offset, 12, ENC_NA);
proto_item_set_text(base_transport_header_item, "%s", "Base Transport Header");
base_transport_header_tree = proto_item_add_subtree(base_transport_header_item, ett_bth);
proto_tree_add_item(base_transport_header_tree, hf_infiniband_opcode, tvb, offset, 1, ENC_BIG_ENDIAN);
opCode = tvb_get_guint8(tvb, offset);
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const((guint32)opCode, OpCodeMap, "Unknown OpCode"));
offset += 1;
proto_tree_add_item(base_transport_header_tree, hf_infiniband_solicited_event, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(base_transport_header_tree, hf_infiniband_migreq, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(base_transport_header_tree, hf_infiniband_pad_count, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(base_transport_header_tree, hf_infiniband_transport_header_version, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(base_transport_header_tree, hf_infiniband_partition_key, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(base_transport_header_tree, hf_infiniband_reserved8, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(base_transport_header_tree, hf_infiniband_destination_qp, tvb, offset, 3, ENC_BIG_ENDIAN);
pinfo->destport = tvb_get_ntoh24(tvb, offset); offset += 3;
proto_tree_add_item(base_transport_header_tree, hf_infiniband_acknowledge_request, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(base_transport_header_tree, hf_infiniband_reserved7, tvb, offset, 1, ENC_BIG_ENDIAN); offset += 1;
proto_tree_add_item(base_transport_header_tree, hf_infiniband_packet_sequence_number, tvb, offset, 3, ENC_BIG_ENDIAN); offset += 3;
packetLength -= 12;
}
break;
case IP_NON_IBA:
g_snprintf(dst_addr, ADDR_MAX_LEN, "IPv6 over IB Packet");
SET_ADDRESS(&pinfo->dst, AT_STRINGZ, (int)strlen(dst_addr)+1, dst_addr);
parse_IPvSix(all_headers_tree, tvb, &offset, pinfo);
break;
case RAW:
parse_RWH(all_headers_tree, tvb, &offset, pinfo);
break;
default:
RAWDATA_header_item = proto_tree_add_item(all_headers_tree, hf_infiniband_raw_data, tvb, offset, -1, ENC_NA);
proto_item_set_text(RAWDATA_header_item, "%s", "Unknown Raw Data - IB Encapsulated");
break;
}
if (bthFollows)
{
transport_type = (opCode & 0xE0) >> 5;
nextHeaderSequence = find_next_header_sequence((guint32) opCode);
switch (nextHeaderSequence)
{
case RDETH_DETH_PAYLD:
parse_RDETH(all_headers_tree, tvb, &offset);
parse_DETH(all_headers_tree, pinfo, tvb, &offset);
packetLength -= 4;
packetLength -= 8;
parse_PAYLOAD(all_headers_tree, pinfo, tvb, &offset, packetLength);
break;
case RDETH_DETH_RETH_PAYLD:
parse_RDETH(all_headers_tree, tvb, &offset);
parse_DETH(all_headers_tree, pinfo, tvb, &offset);
parse_RETH(all_headers_tree, tvb, &offset);
packetLength -= 4;
packetLength -= 8;
packetLength -= 16;
parse_PAYLOAD(all_headers_tree, pinfo, tvb, &offset, packetLength);
break;
case RDETH_DETH_IMMDT_PAYLD:
parse_RDETH(all_headers_tree, tvb, &offset);
parse_DETH(all_headers_tree, pinfo, tvb, &offset);
parse_IMMDT(all_headers_tree, tvb, &offset);
packetLength -= 4;
packetLength -= 8;
packetLength -= 4;
parse_PAYLOAD(all_headers_tree, pinfo, tvb, &offset, packetLength);
break;
case RDETH_DETH_RETH_IMMDT_PAYLD:
parse_RDETH(all_headers_tree, tvb, &offset);
parse_DETH(all_headers_tree, pinfo, tvb, &offset);
parse_RETH(all_headers_tree, tvb, &offset);
parse_IMMDT(all_headers_tree, tvb, &offset);
packetLength -= 4;
packetLength -= 8;
packetLength -= 16;
packetLength -= 4;
parse_PAYLOAD(all_headers_tree, pinfo, tvb, &offset, packetLength);
break;
case RDETH_DETH_RETH:
parse_RDETH(all_headers_tree, tvb, &offset);
parse_DETH(all_headers_tree, pinfo, tvb, &offset);
parse_RETH(all_headers_tree, tvb, &offset);
break;
case RDETH_AETH_PAYLD:
parse_RDETH(all_headers_tree, tvb, &offset);
parse_AETH(all_headers_tree, tvb, &offset);
packetLength -= 4;
packetLength -= 4;
parse_PAYLOAD(all_headers_tree, pinfo, tvb, &offset, packetLength);
break;
case RDETH_PAYLD:
parse_RDETH(all_headers_tree, tvb, &offset);
packetLength -= 4;
parse_PAYLOAD(all_headers_tree, pinfo, tvb, &offset, packetLength);
break;
case RDETH_AETH:
parse_AETH(all_headers_tree, tvb, &offset);
break;
case RDETH_AETH_ATOMICACKETH:
parse_RDETH(all_headers_tree, tvb, &offset);
parse_AETH(all_headers_tree, tvb, &offset);
parse_ATOMICACKETH(all_headers_tree, tvb, &offset);
break;
case RDETH_DETH_ATOMICETH:
parse_RDETH(all_headers_tree, tvb, &offset);
parse_DETH(all_headers_tree, pinfo, tvb, &offset);
parse_ATOMICETH(all_headers_tree, tvb, &offset);
break;
case RDETH_DETH:
parse_RDETH(all_headers_tree, tvb, &offset);
parse_DETH(all_headers_tree, pinfo, tvb, &offset);
break;
case DETH_PAYLD:
parse_DETH(all_headers_tree, pinfo, tvb, &offset);
packetLength -= 8;
parse_PAYLOAD(all_headers_tree, pinfo, tvb, &offset, packetLength);
break;
case PAYLD:
parse_PAYLOAD(all_headers_tree, pinfo, tvb, &offset, packetLength);
break;
case IMMDT_PAYLD:
parse_IMMDT(all_headers_tree, tvb, &offset);
packetLength -= 4;
parse_PAYLOAD(all_headers_tree, pinfo, tvb, &offset, packetLength);
break;
case RETH_PAYLD:
parse_RETH(all_headers_tree, tvb, &offset);
packetLength -= 16;
parse_PAYLOAD(all_headers_tree, pinfo, tvb, &offset, packetLength);
break;
case RETH:
parse_RETH(all_headers_tree, tvb, &offset);
break;
case AETH_PAYLD:
parse_AETH(all_headers_tree, tvb, &offset);
packetLength -= 4;
parse_PAYLOAD(all_headers_tree, pinfo, tvb, &offset, packetLength);
break;
case AETH:
parse_AETH(all_headers_tree, tvb, &offset);
break;
case AETH_ATOMICACKETH:
parse_AETH(all_headers_tree, tvb, &offset);
parse_ATOMICACKETH(all_headers_tree, tvb, &offset);
break;
case ATOMICETH:
parse_ATOMICETH(all_headers_tree, tvb, &offset);
break;
case IETH_PAYLD:
parse_IETH(all_headers_tree, tvb, &offset);
packetLength -= 4;
parse_PAYLOAD(all_headers_tree, pinfo, tvb, &offset, packetLength);
break;
case DETH_IMMDT_PAYLD:
parse_DETH(all_headers_tree, pinfo, tvb, &offset);
parse_IMMDT(all_headers_tree, tvb, &offset);
packetLength -= 8;
packetLength -= 4;
parse_PAYLOAD(all_headers_tree, pinfo, tvb, &offset, packetLength);
break;
default:
parse_VENDOR(all_headers_tree, tvb, &offset);
break;
}
}
crc_length = tvb_reported_length_remaining(tvb, offset);
if (crc_length == 6)
{
proto_tree_add_item(all_headers_tree, hf_infiniband_invariant_crc, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
proto_tree_add_item(all_headers_tree, hf_infiniband_variant_crc, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
}
else if (crc_length == 4)
{
proto_tree_add_item(all_headers_tree, hf_infiniband_invariant_crc, tvb, offset, 4, ENC_BIG_ENDIAN); offset += 4;
}
else if (crc_length == 2)
{
proto_tree_add_item(all_headers_tree, hf_infiniband_variant_crc, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
}
}
static void
dissect_infiniband_link(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *infiniband_link_packet;
proto_tree *link_tree;
proto_item *operand_item;
gint offset = 0;
guint8 operand;
if (!src_addr)
src_addr = se_alloc(ADDR_MAX_LEN);
if (!dst_addr)
dst_addr = se_alloc(ADDR_MAX_LEN);
operand = tvb_get_guint8(tvb, offset);
operand = (operand & 0xF0) >> 4;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "InfiniBand Link");
col_clear(pinfo->cinfo, COL_INFO);
col_add_fstr(pinfo->cinfo, COL_INFO, "%s",
val_to_str(operand, Operand_Description, "Unknown (0x%1x)"));
if (tree && tree->parent)
{
tree = tree->parent;
top_tree = tree;
}
if (!tree)
{
dissect_general_info(tvb, offset, pinfo, FALSE);
return;
}
infiniband_link_packet = proto_tree_add_item(tree, proto_infiniband_link, tvb, offset, -1, ENC_NA);
link_tree = proto_item_add_subtree(infiniband_link_packet, ett_link);
operand_item = proto_tree_add_item(link_tree, hf_infiniband_link_op, tvb, offset, 2, ENC_BIG_ENDIAN);
if (operand > 1) {
proto_item_set_text(operand_item, "%s", "Reserved");
call_dissector(data_handle, tvb, pinfo, link_tree);
} else {
proto_tree_add_item(link_tree, hf_infiniband_link_fctbs, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(link_tree, hf_infiniband_link_vl, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(link_tree, hf_infiniband_link_fccl, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(link_tree, hf_infiniband_link_lpcrc, tvb, offset, 2, ENC_BIG_ENDIAN);
}
}
static gint32
find_next_header_sequence(guint32 OpCode)
{
if (contains(OpCode, &opCode_PAYLD[0], (gint32)array_length(opCode_PAYLD)))
return PAYLD;
if (contains(OpCode, &opCode_IMMDT_PAYLD[0], (gint32)array_length(opCode_IMMDT_PAYLD)))
return IMMDT_PAYLD;
if (contains(OpCode, &opCode_RDETH_DETH_PAYLD[0], (gint32)array_length(opCode_RDETH_DETH_PAYLD)))
return RDETH_DETH_PAYLD;
if (contains(OpCode, &opCode_RETH_PAYLD[0], (gint32)array_length(opCode_RETH_PAYLD)))
return RETH_PAYLD;
if (contains(OpCode, &opCode_RDETH_AETH_PAYLD[0], (gint32)array_length(opCode_RDETH_AETH_PAYLD)))
return RDETH_AETH_PAYLD;
if (contains(OpCode, &opCode_AETH_PAYLD[0], (gint32)array_length(opCode_AETH_PAYLD)))
return AETH_PAYLD;
if (contains(OpCode, &opCode_RDETH_DETH_IMMDT_PAYLD[0], (gint32)array_length(opCode_RDETH_DETH_IMMDT_PAYLD)))
return RDETH_DETH_IMMDT_PAYLD;
if (contains(OpCode, &opCode_RETH_IMMDT_PAYLD[0], (gint32)array_length(opCode_RETH_IMMDT_PAYLD)))
return RETH_IMMDT_PAYLD;
if (contains(OpCode, &opCode_RDETH_DETH_RETH_PAYLD[0], (gint32)array_length(opCode_RDETH_DETH_RETH_PAYLD)))
return RDETH_DETH_RETH_PAYLD;
if (contains(OpCode, &opCode_ATOMICETH[0], (gint32)array_length(opCode_ATOMICETH)))
return ATOMICETH;
if (contains(OpCode, &opCode_IETH_PAYLD[0], (gint32)array_length(opCode_IETH_PAYLD)))
return IETH_PAYLD;
if (contains(OpCode, &opCode_RDETH_DETH_ATOMICETH[0], (gint32)array_length(opCode_RDETH_DETH_ATOMICETH)))
return RDETH_DETH_ATOMICETH;
if ((OpCode ^ RC_ACKNOWLEDGE) == 0)
return AETH;
if ((OpCode ^ RC_RDMA_READ_REQUEST) == 0)
return RETH;
if ((OpCode ^ RC_ATOMIC_ACKNOWLEDGE) == 0)
return AETH_ATOMICACKETH;
if ((OpCode ^ RD_RDMA_READ_RESPONSE_MIDDLE) == 0)
return RDETH_PAYLD;
if ((OpCode ^ RD_ACKNOWLEDGE) == 0)
return RDETH_AETH;
if ((OpCode ^ RD_ATOMIC_ACKNOWLEDGE) == 0)
return RDETH_AETH_ATOMICACKETH;
if ((OpCode ^ RD_RDMA_WRITE_ONLY_IMM) == 0)
return RDETH_DETH_RETH_IMMDT_PAYLD;
if ((OpCode ^ RD_RDMA_READ_REQUEST) == 0)
return RDETH_DETH_RETH;
if ((OpCode ^ RD_RESYNC) == 0)
return RDETH_DETH;
if ((OpCode ^ UD_SEND_ONLY) == 0)
return DETH_PAYLD;
if ((OpCode ^ UD_SEND_ONLY_IMM) == 0)
return DETH_IMMDT_PAYLD;
return -1;
}
static gboolean
contains(guint32 OpCode, guint32* Codes, gint32 length)
{
gint32 i;
for (i = 0; i < length; i++)
{
if ((OpCode ^ Codes[i]) == 0)
return TRUE;
}
return FALSE;
}
static void
parse_RDETH(proto_tree * parentTree, tvbuff_t *tvb, gint *offset)
{
gint local_offset = *offset;
proto_item *RDETH_header_item;
proto_tree *RDETH_header_tree;
RDETH_header_item = proto_tree_add_item(parentTree, hf_infiniband_RDETH, tvb, local_offset, 4, ENC_NA);
proto_item_set_text(RDETH_header_item, "%s", "RDETH - Reliable Datagram Extended Transport Header");
RDETH_header_tree = proto_item_add_subtree(RDETH_header_item, ett_rdeth);
proto_tree_add_item(RDETH_header_tree, hf_infiniband_reserved8_RDETH, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(RDETH_header_tree, hf_infiniband_ee_context, tvb, local_offset, 3, ENC_BIG_ENDIAN); local_offset += 3;
*offset = local_offset;
}
static void
parse_DETH(proto_tree *parentTree, packet_info *pinfo, tvbuff_t *tvb, gint *offset)
{
gint local_offset = *offset;
proto_item *DETH_header_item;
proto_tree *DETH_header_tree;
DETH_header_item = proto_tree_add_item(parentTree, hf_infiniband_DETH, tvb, local_offset, 8, ENC_NA);
proto_item_set_text(DETH_header_item, "%s", "DETH - Datagram Extended Transport Header");
DETH_header_tree = proto_item_add_subtree(DETH_header_item, ett_deth);
proto_tree_add_item(DETH_header_tree, hf_infiniband_queue_key, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(DETH_header_tree, hf_infiniband_reserved8_DETH, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(DETH_header_tree, hf_infiniband_source_qp, tvb, local_offset, 3, ENC_BIG_ENDIAN);
pinfo->srcport = tvb_get_ntoh24(tvb, local_offset); local_offset += 3;
*offset = local_offset;
}
static void
parse_RETH(proto_tree * parentTree, tvbuff_t *tvb, gint *offset)
{
gint local_offset = *offset;
proto_item *RETH_header_item;
proto_tree *RETH_header_tree;
RETH_header_item = proto_tree_add_item(parentTree, hf_infiniband_RETH, tvb, local_offset, 16, ENC_NA);
proto_item_set_text(RETH_header_item, "%s", "RETH - RDMA Extended Transport Header");
RETH_header_tree = proto_item_add_subtree(RETH_header_item, ett_reth);
proto_tree_add_item(RETH_header_tree, hf_infiniband_virtual_address, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(RETH_header_tree, hf_infiniband_remote_key, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(RETH_header_tree, hf_infiniband_dma_length, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
*offset = local_offset;
}
static void
parse_ATOMICETH(proto_tree * parentTree, tvbuff_t *tvb, gint *offset)
{
gint local_offset = *offset;
proto_item *ATOMICETH_header_item;
proto_tree *ATOMICETH_header_tree;
ATOMICETH_header_item = proto_tree_add_item(parentTree, hf_infiniband_AtomicETH, tvb, local_offset, 28, ENC_NA);
proto_item_set_text(ATOMICETH_header_item, "%s", "AtomicETH - Atomic Extended Transport Header");
ATOMICETH_header_tree = proto_item_add_subtree(ATOMICETH_header_item, ett_atomiceth);
proto_tree_add_item(ATOMICETH_header_tree, hf_infiniband_virtual_address, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(ATOMICETH_header_tree, hf_infiniband_remote_key, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(ATOMICETH_header_tree, hf_infiniband_swap_or_add_data, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(ATOMICETH_header_tree, hf_infiniband_compare_data, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
*offset = local_offset;
}
static void
parse_AETH(proto_tree * parentTree, tvbuff_t *tvb, gint *offset)
{
gint local_offset = *offset;
proto_item *AETH_header_item;
proto_tree *AETH_header_tree;
AETH_header_item = proto_tree_add_item(parentTree, hf_infiniband_AETH, tvb, local_offset, 4, ENC_NA);
proto_item_set_text(AETH_header_item, "%s", "AETH - ACK Extended Transport Header");
AETH_header_tree = proto_item_add_subtree(AETH_header_item, ett_aeth);
proto_tree_add_item(AETH_header_tree, hf_infiniband_syndrome, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(AETH_header_tree, hf_infiniband_message_sequence_number, tvb, local_offset, 3, ENC_BIG_ENDIAN); local_offset += 3;
*offset = local_offset;
}
static void
parse_ATOMICACKETH(proto_tree * parentTree, tvbuff_t *tvb, gint *offset)
{
gint local_offset = *offset;
proto_item *ATOMICACKETH_header_item;
proto_tree *ATOMICACKETH_header_tree;
ATOMICACKETH_header_item = proto_tree_add_item(parentTree, hf_infiniband_AtomicAckETH, tvb, local_offset, 8, ENC_NA);
proto_item_set_text(ATOMICACKETH_header_item, "%s", "ATOMICACKETH - Atomic ACK Extended Transport Header");
ATOMICACKETH_header_tree = proto_item_add_subtree(ATOMICACKETH_header_item, ett_atomicacketh);
proto_tree_add_item(ATOMICACKETH_header_tree, hf_infiniband_original_remote_data, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
*offset = local_offset;
}
static void
parse_IMMDT(proto_tree * parentTree, tvbuff_t *tvb, gint *offset)
{
gint local_offset = *offset;
proto_item *IMMDT_header_item;
proto_tree *IMMDT_header_tree;
IMMDT_header_item = proto_tree_add_item(parentTree, hf_infiniband_IMMDT, tvb, local_offset, 4, ENC_NA);
proto_item_set_text(IMMDT_header_item, "%s", "IMMDT - Immediate Data Extended Transport Header");
IMMDT_header_tree = proto_item_add_subtree(IMMDT_header_item, ett_immdt);
proto_tree_add_item(IMMDT_header_tree, hf_infiniband_IMMDT, tvb, local_offset, 4, ENC_NA); local_offset += 4;
*offset = local_offset;
}
static void
parse_IETH(proto_tree * parentTree, tvbuff_t *tvb, gint *offset)
{
gint local_offset = *offset;
proto_item *IETH_header_item;
proto_tree *IETH_header_tree;
IETH_header_item = proto_tree_add_item(parentTree, hf_infiniband_IETH, tvb, local_offset, 4, ENC_NA);
proto_item_set_text(IETH_header_item, "%s", "IETH - Invalidate Extended Transport Header");
IETH_header_tree = proto_item_add_subtree(IETH_header_item, ett_ieth);
proto_tree_add_item(IETH_header_tree, hf_infiniband_IETH, tvb, local_offset, 4, ENC_NA); local_offset += 4;
*offset = local_offset;
}
static void parse_PAYLOAD(proto_tree *parentTree, packet_info *pinfo, tvbuff_t *tvb, gint *offset, gint length)
{
gint local_offset = *offset;
guint8 management_class;
tvbuff_t *volatile next_tvb;
gint captured_length, reported_length;
guint16 etype, reserved;
const char *saved_proto;
volatile gboolean dissector_found = FALSE;
if (!tvb_bytes_exist(tvb, *offset, length))
{
col_set_str(pinfo->cinfo, COL_INFO, "Invalid Packet Length from LRH! [Malformed Packet]");
col_set_fence(pinfo->cinfo, COL_INFO);
return;
}
if (pinfo->srcport == 0 || pinfo->srcport == 1 || pinfo->destport == 0 || pinfo->destport == 1)
{
management_class = tvb_get_guint8(tvb, (*offset) + 1);
if (((management_class >= (guint8)VENDOR_1_START) && (management_class <= (guint8)VENDOR_1_END))
|| ((management_class >= (guint8)VENDOR_2_START) && (management_class <= (guint8)VENDOR_2_END)))
{
parse_VENDOR_MANAGEMENT(parentTree, tvb, offset);
}
else if ((management_class >= (guint8)APPLICATION_START) && (management_class <= (guint8)APPLICATION_END))
{
parse_APPLICATION_MANAGEMENT(parentTree, tvb, offset);
}
else if (((management_class == (guint8)0x00) || (management_class == (guint8)0x02))
|| ((management_class >= (guint8)0x50) && (management_class <= (guint8)0x80))
|| ((management_class >= (guint8)0x82)))
{
parse_RESERVED_MANAGEMENT(parentTree, tvb, offset);
}
else
{
switch (management_class)
{
case SUBN_LID_ROUTED:
parse_SUBN_LID_ROUTED(parentTree, pinfo, tvb, &local_offset);
break;
case SUBN_DIRECTED_ROUTE:
parse_SUBN_DIRECTED_ROUTE(parentTree, pinfo, tvb, &local_offset);
break;
case SUBNADMN:
parse_SUBNADMN(parentTree, pinfo, tvb, &local_offset);
break;
case PERF:
parse_PERF(parentTree, tvb, pinfo, &local_offset);
break;
case BM:
parse_BM(parentTree, tvb, &local_offset);
break;
case DEV_MGT:
parse_DEV_MGT(parentTree, tvb, &local_offset);
break;
case COM_MGT:
parse_COM_MGT(parentTree, pinfo, tvb, &local_offset);
break;
case SNMP:
parse_SNMP(parentTree, tvb, &local_offset);
break;
default:
break;
}
}
}
else
{
etype = tvb_get_ntohs(tvb, local_offset);
reserved = tvb_get_ntohs(tvb, local_offset + 2);
if (pref_dissect_eoib &&
(transport_type == TRANSPORT_UD) &&
(tvb_get_bits8(tvb, local_offset*8, 4) == 0xC)) {
dissector_found = parse_EoIB(parentTree, tvb, local_offset, pinfo);
}
if (!dissector_found && pref_identify_iba_payload && (reserved == 0)) {
void *pd_save;
captured_length = tvb_length_remaining(tvb, local_offset+4);
reported_length = tvb_reported_length_remaining(tvb, local_offset+4);
next_tvb = tvb_new_subset(tvb, local_offset+4, captured_length, reported_length);
pinfo->ethertype = etype;
saved_proto = pinfo->current_proto;
pd_save = pinfo->private_data;
TRY {
dissector_found = dissector_try_uint(ethertype_dissector_table,
etype, next_tvb, pinfo, top_tree);
}
CATCH(BoundsError) {
RETHROW;
}
CATCH(OutOfMemoryError) {
RETHROW;
}
CATCH_ALL {
pinfo->private_data = pd_save;
show_exception(next_tvb, pinfo, top_tree, EXCEPT_CODE, GET_MESSAGE);
dissector_found = TRUE;
pinfo->current_proto = saved_proto;
}
ENDTRY;
if (dissector_found) {
proto_item *PAYLOAD_header_item;
proto_tree *PAYLOAD_header_tree;
PAYLOAD_header_item = proto_tree_add_item(parentTree, hf_infiniband_payload, tvb, local_offset, tvb_reported_length_remaining(tvb, local_offset)-6, ENC_NA);
proto_item_set_text(PAYLOAD_header_item, "%s", "IBA Payload - appears to be EtherType encapsulated");
PAYLOAD_header_tree = proto_item_add_subtree(PAYLOAD_header_item, ett_payload);
proto_tree_add_uint(PAYLOAD_header_tree, hf_infiniband_etype, tvb,
local_offset, 2, tvb_get_ntohs(tvb, local_offset));
local_offset += 2;
proto_tree_add_uint(PAYLOAD_header_tree, hf_infiniband_reserved16_RWH, tvb,
local_offset, 2, tvb_get_ntohs(tvb, local_offset));
}
}
captured_length = tvb_length_remaining(tvb, local_offset);
reported_length = tvb_reported_length_remaining(tvb,
local_offset);
if (reported_length >= 6)
reported_length -= 6;
if (captured_length > reported_length)
captured_length = reported_length;
next_tvb = tvb_new_subset(tvb, local_offset,
captured_length,
reported_length);
if (!dissector_found) {
dissector_found = dissector_try_heuristic(heur_dissectors_payload, next_tvb, pinfo, parentTree);
}
if (!dissector_found) {
call_dissector(data_handle, next_tvb, pinfo, top_tree);
}
local_offset = tvb_reported_length(tvb) - 6;
}
*offset = local_offset;
}
static void parse_VENDOR(proto_tree * parentTree, tvbuff_t *tvb, gint *offset)
{
gint local_offset = *offset;
proto_item *VENDOR_header_item;
proto_tree *VENDOR_header_tree;
VENDOR_header_item = proto_tree_add_item(parentTree, hf_infiniband_vendor, tvb, local_offset, 4, ENC_NA);
proto_item_set_text(VENDOR_header_item, "%s", "Vendor Specific or Unknown Header Sequence");
VENDOR_header_tree = proto_item_add_subtree(VENDOR_header_item, ett_vendor);
proto_tree_add_item(VENDOR_header_tree, hf_infiniband_vendor, tvb, local_offset, -1, ENC_NA);
*offset = local_offset;
}
static void parse_IPvSix(proto_tree *parentTree, tvbuff_t *tvb, gint *offset, packet_info *pinfo)
{
tvbuff_t *ipv6_tvb;
ipv6_tvb = tvb_new_subset(tvb, *offset,
tvb_length_remaining(tvb, *offset) - 2,
tvb_reported_length_remaining(tvb, *offset) - 2);
call_dissector(ipv6_handle, ipv6_tvb, pinfo, parentTree);
*offset = tvb_reported_length(tvb) - 2;
proto_tree_add_item(parentTree, hf_infiniband_variant_crc, tvb, *offset, 2, ENC_BIG_ENDIAN);
}
static void parse_RWH(proto_tree *ah_tree, tvbuff_t *tvb, gint *offset, packet_info *pinfo)
{
guint16 ether_type;
tvbuff_t *next_tvb;
proto_item *RWH_header_item;
proto_tree *RWH_header_tree;
gint captured_length, reported_length;
RWH_header_item = proto_tree_add_item(ah_tree, hf_infiniband_RWH, tvb, *offset, 4, ENC_NA);
proto_item_set_text(RWH_header_item, "%s", "RWH - Raw Header");
RWH_header_tree = proto_item_add_subtree(RWH_header_item, ett_rwh);
proto_tree_add_item(RWH_header_tree, hf_infiniband_reserved16_RWH, tvb,
*offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
ether_type = tvb_get_ntohs(tvb, *offset);
proto_tree_add_uint(RWH_header_tree, hf_infiniband_etype, tvb, *offset, 2,
ether_type);
*offset += 2;
captured_length = tvb_length_remaining(tvb, *offset);
reported_length = tvb_reported_length_remaining(tvb, *offset);
if ((captured_length >= 0) && (reported_length >= 0)) {
if (reported_length >= 2)
reported_length -= 2;
if (captured_length > reported_length)
captured_length = reported_length;
}
next_tvb = tvb_new_subset(tvb, *offset, captured_length, reported_length);
if (!dissector_try_uint(ethertype_dissector_table, ether_type,
next_tvb, pinfo, top_tree))
call_dissector(data_handle, next_tvb, pinfo, top_tree);
*offset = tvb_reported_length(tvb) - 2;
proto_tree_add_item(ah_tree, hf_infiniband_variant_crc, tvb, *offset, 2, ENC_BIG_ENDIAN);
}
static gboolean parse_EoIB(proto_tree *tree, tvbuff_t *tvb, gint offset, packet_info *pinfo)
{
proto_item *header_item;
proto_tree *header_subtree;
gboolean ms;
gint8 seg_offset;
tvbuff_t *encap_tvb;
int encap_size = tvb_reported_length_remaining(tvb, offset) - 6;
if (encap_size < 4) {
return FALSE;
}
encap_tvb = tvb_new_subset(tvb, offset + 4, tvb_length_remaining(tvb, offset + 4), encap_size - 4);
header_item = proto_tree_add_item(tree, hf_infiniband_EOIB, tvb, offset, 4, ENC_NA);
header_subtree = proto_item_add_subtree(header_item, ett_eoib);
proto_tree_add_item(header_subtree, hf_infiniband_ver, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(header_subtree, hf_infiniband_tcp_chk, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(header_subtree, hf_infiniband_ip_chk, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(header_subtree, hf_infiniband_fcs, tvb, offset, 2, ENC_BIG_ENDIAN);
ms = tvb_get_bits8(tvb, (offset + 1)*8 + 2, 1);
seg_offset = tvb_get_bits8(tvb, (offset + 1)*8 + 3, 5);
proto_tree_add_item(header_subtree, hf_infiniband_ms, tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(header_subtree, hf_infiniband_seg_off, tvb, offset, 2, ENC_BIG_ENDIAN); offset += 2;
proto_tree_add_item(header_subtree, hf_infiniband_seg_id, tvb, offset, 2, ENC_BIG_ENDIAN);
if (seg_offset || ms) {
call_dissector(data_handle, encap_tvb, pinfo, top_tree);
} else {
call_dissector(eth_handle, encap_tvb, pinfo, top_tree);
}
return TRUE;
}
static void parse_SUBN_LID_ROUTED(proto_tree *parentTree, packet_info *pinfo, tvbuff_t *tvb, gint *offset)
{
MAD_Data MadData;
gint local_offset;
proto_item *SUBN_LID_ROUTED_header_item;
proto_tree *SUBN_LID_ROUTED_header_tree;
if (!parse_MAD_Common(parentTree, tvb, offset, &MadData))
{
return;
}
local_offset = *offset;
SUBN_LID_ROUTED_header_item = proto_tree_add_item(parentTree, hf_infiniband_SMP_LID, tvb, local_offset - 24, 256, ENC_NA);
proto_item_set_text(SUBN_LID_ROUTED_header_item, "%s", "SMP (LID Routed) ");
SUBN_LID_ROUTED_header_tree = proto_item_add_subtree(SUBN_LID_ROUTED_header_item, ett_subn_lid_routed);
proto_tree_add_item(SUBN_LID_ROUTED_header_tree, hf_infiniband_m_key, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(SUBN_LID_ROUTED_header_tree, hf_infiniband_reserved256, tvb, local_offset, 32, ENC_NA); local_offset += 32;
label_SUBM_Method(SUBN_LID_ROUTED_header_item, &MadData, pinfo);
label_SUBM_Attribute(SUBN_LID_ROUTED_header_item, &MadData, pinfo);
if (!parse_SUBM_Attribute(SUBN_LID_ROUTED_header_tree, tvb, &local_offset, &MadData))
{
proto_tree_add_item(SUBN_LID_ROUTED_header_tree, hf_infiniband_smp_data, tvb, local_offset, 64, ENC_NA); local_offset += 64;
}
proto_tree_add_item(SUBN_LID_ROUTED_header_tree, hf_infiniband_reserved1024, tvb, local_offset, 128, ENC_NA); local_offset += 128;
*offset = local_offset;
}
static void parse_SUBN_DIRECTED_ROUTE(proto_tree *parentTree, packet_info *pinfo, tvbuff_t *tvb, gint *offset)
{
MAD_Data MadData;
gint local_offset;
proto_item *SUBN_DIRECTED_ROUTE_header_item;
proto_tree *SUBN_DIRECTED_ROUTE_header_tree;
if (!parse_MAD_Common(parentTree, tvb, offset, &MadData))
{
return;
}
local_offset = *offset;
SUBN_DIRECTED_ROUTE_header_item = proto_tree_add_item(parentTree, hf_infiniband_SMP_DIRECTED, tvb, local_offset - 24, 256, ENC_NA);
proto_item_set_text(SUBN_DIRECTED_ROUTE_header_item, "%s", "SMP (Directed Route) ");
SUBN_DIRECTED_ROUTE_header_tree = proto_item_add_subtree(SUBN_DIRECTED_ROUTE_header_item, ett_subn_directed_route);
label_SUBM_Method(SUBN_DIRECTED_ROUTE_header_item, &MadData, pinfo);
label_SUBM_Attribute(SUBN_DIRECTED_ROUTE_header_item, &MadData, pinfo);
local_offset -= 20;
proto_tree_add_item(SUBN_DIRECTED_ROUTE_header_tree, hf_infiniband_d, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(SUBN_DIRECTED_ROUTE_header_tree, hf_infiniband_smp_status, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(SUBN_DIRECTED_ROUTE_header_tree, hf_infiniband_hop_pointer, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(SUBN_DIRECTED_ROUTE_header_tree, hf_infiniband_hop_count, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
local_offset += 16;
proto_tree_add_item(SUBN_DIRECTED_ROUTE_header_tree, hf_infiniband_m_key, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(SUBN_DIRECTED_ROUTE_header_tree, hf_infiniband_dr_slid, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(SUBN_DIRECTED_ROUTE_header_tree, hf_infiniband_dr_dlid, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(SUBN_DIRECTED_ROUTE_header_tree, hf_infiniband_reserved28, tvb, local_offset, 28, ENC_NA); local_offset += 28;
if (!parse_SUBM_Attribute(SUBN_DIRECTED_ROUTE_header_tree, tvb, &local_offset, &MadData))
{
proto_tree_add_item(SUBN_DIRECTED_ROUTE_header_tree, hf_infiniband_smp_data, tvb, local_offset, 64, ENC_NA); local_offset += 64;
}
proto_tree_add_item(SUBN_DIRECTED_ROUTE_header_tree, hf_infiniband_initial_path, tvb, local_offset, 64, ENC_NA); local_offset += 64;
proto_tree_add_item(SUBN_DIRECTED_ROUTE_header_tree, hf_infiniband_return_path, tvb, local_offset, 64, ENC_NA); local_offset += 64;
*offset = local_offset;
}
static void parse_SUBNADMN(proto_tree *parentTree, packet_info *pinfo, tvbuff_t *tvb, gint *offset)
{
MAD_Data MadData;
gint local_offset;
proto_item *SUBNADMN_header_item;
proto_tree *SUBNADMN_header_tree;
if (!parse_MAD_Common(parentTree, tvb, offset, &MadData))
{
return;
}
if (!parse_RMPP(parentTree, tvb, offset))
{
return;
}
local_offset = *offset;
SUBNADMN_header_item = proto_tree_add_item(parentTree, hf_infiniband_SA, tvb, local_offset - 36, 256, ENC_NA);
proto_item_set_text(SUBNADMN_header_item, "%s", "SMA");
SUBNADMN_header_tree = proto_item_add_subtree(SUBNADMN_header_item, ett_subnadmin);
proto_tree_add_item(SUBNADMN_header_tree, hf_infiniband_sm_key, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(SUBNADMN_header_tree, hf_infiniband_attribute_offset, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(SUBNADMN_header_tree, hf_infiniband_reserved16, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(SUBNADMN_header_tree, hf_infiniband_component_mask, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
label_SUBA_Method(SUBNADMN_header_item, &MadData, pinfo);
label_SUBA_Attribute(SUBNADMN_header_item, &MadData, pinfo);
if (!parse_SUBA_Attribute(SUBNADMN_header_tree, tvb, &local_offset, &MadData))
{
proto_tree_add_item(SUBNADMN_header_tree, hf_infiniband_subnet_admin_data, tvb, local_offset, 200, ENC_NA); local_offset += 200;
}
*offset = local_offset;
}
static void parse_PERF(proto_tree *parentTree, tvbuff_t *tvb, packet_info *pinfo, gint *offset)
{
MAD_Data MadData;
gint local_offset;
proto_item *PERF_header_item;
if (!parse_MAD_Common(parentTree, tvb, offset, &MadData))
{
return;
}
local_offset = *offset;
switch (MadData.attributeID) {
case ATTR_PORT_COUNTERS:
parse_PERF_PortCounters(parentTree, tvb, pinfo, &local_offset);
break;
case ATTR_PORT_COUNTERS_EXT:
parse_PERF_PortCountersExtended(parentTree, tvb, pinfo, &local_offset);
break;
default:
PERF_header_item = proto_tree_add_item(parentTree, hf_infiniband_smp_data, tvb, local_offset, MAD_DATA_SIZE, ENC_NA); local_offset += MAD_DATA_SIZE;
proto_item_set_text(PERF_header_item, "%s", "PERF - Performance Management MAD (Dissector Not Implemented)");
break;
}
*offset = local_offset;
}
static void parse_BM(proto_tree *parentTree, tvbuff_t *tvb, gint *offset)
{
MAD_Data MadData;
gint local_offset;
proto_item *PERF_header_item;
if (!parse_MAD_Common(parentTree, tvb, offset, &MadData))
{
return;
}
local_offset = *offset;
PERF_header_item = proto_tree_add_item(parentTree, hf_infiniband_smp_data, tvb, local_offset, MAD_DATA_SIZE, ENC_NA); local_offset += MAD_DATA_SIZE;
proto_item_set_text(PERF_header_item, "%s", "BM - Baseboard Management MAD (Dissector Not Implemented)");
*offset = local_offset;
}
static void parse_DEV_MGT(proto_tree *parentTree, tvbuff_t *tvb, gint *offset)
{
MAD_Data MadData;
gint local_offset;
proto_item *PERF_header_item;
if (!parse_MAD_Common(parentTree, tvb, offset, &MadData))
{
return;
}
local_offset = *offset;
PERF_header_item = proto_tree_add_item(parentTree, hf_infiniband_smp_data, tvb, local_offset, MAD_DATA_SIZE, ENC_NA); local_offset += MAD_DATA_SIZE;
proto_item_set_text(PERF_header_item, "%s", "DEV_MGT - Device Management MAD (Dissector Not Implemented)");
*offset = local_offset;
}
static void parse_COM_MGT(proto_tree *parentTree, packet_info *pinfo, tvbuff_t *tvb, gint *offset)
{
MAD_Data MadData;
gint local_offset;
guint8 *local_gid, *remote_gid;
const char *label;
proto_item *CM_header_item;
proto_tree *CM_header_tree;
tvbuff_t *next_tvb;
local_gid = ep_alloc(GID_SIZE);
remote_gid = ep_alloc(GID_SIZE);
if (!parse_MAD_Common(parentTree, tvb, offset, &MadData))
{
return;
}
local_offset = *offset;
CM_header_item = proto_tree_add_item(parentTree, hf_infiniband_smp_data, tvb, local_offset, 140, ENC_NA);
label = val_to_str_const(MadData.attributeID, CM_Attributes, "(Unknown CM Attribute)");
proto_item_set_text(CM_header_item, "CM %s", label);
col_clear(pinfo->cinfo, COL_INFO);
col_append_fstr(pinfo->cinfo, COL_INFO, "CM: %s", label);
CM_header_tree = proto_item_add_subtree(CM_header_item, ett_cm);
switch (MadData.attributeID) {
case ATTR_CM_REQ: {
guint32 local_qpn;
guint32 local_lid;
guint32 remote_lid;
guint64 serviceid;
proto_tree_add_item(CM_header_tree, hf_cm_req_local_comm_id, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
local_offset += 4;
proto_tree_add_item(CM_header_tree, hf_cm_req_service_id, tvb, local_offset, 8, ENC_BIG_ENDIAN);
serviceid = tvb_get_ntoh64(tvb, local_offset); local_offset += 8;
proto_tree_add_item(CM_header_tree, hf_cm_req_local_ca_guid, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
local_offset += 4;
proto_tree_add_item(CM_header_tree, hf_cm_req_local_qkey, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(CM_header_tree, hf_cm_req_local_qpn, tvb, local_offset, 3, ENC_BIG_ENDIAN);
local_qpn = tvb_get_ntoh24(tvb, local_offset); local_offset += 3;
proto_tree_add_item(CM_header_tree, hf_cm_req_respo_res, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_req_local_eecn, tvb, local_offset, 3, ENC_BIG_ENDIAN); local_offset += 3;
proto_tree_add_item(CM_header_tree, hf_cm_req_init_depth, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_req_remote_eecn, tvb, local_offset, 3, ENC_BIG_ENDIAN); local_offset += 3;
proto_tree_add_item(CM_header_tree, hf_cm_req_remote_cm_resp_to, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(CM_header_tree, hf_cm_req_transp_serv_type, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(CM_header_tree, hf_cm_req_e2e_flow_ctrl, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_req_start_psn, tvb, local_offset, 3, ENC_BIG_ENDIAN); local_offset += 3;
proto_tree_add_item(CM_header_tree, hf_cm_req_local_cm_resp_to, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(CM_header_tree, hf_cm_req_retry_count, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_req_pkey, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(CM_header_tree, hf_cm_req_path_pp_mtu, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(CM_header_tree, hf_cm_req_rdc_exists, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(CM_header_tree, hf_cm_req_rnr_retry_count, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_req_max_cm_retries, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(CM_header_tree, hf_cm_req_srq, tvb, local_offset, 1, ENC_BIG_ENDIAN);
local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_req_primary_local_lid, tvb, local_offset, 2, ENC_BIG_ENDIAN);
local_lid = tvb_get_ntohs(tvb, local_offset); local_offset += 2;
proto_tree_add_item(CM_header_tree, hf_cm_req_primary_remote_lid, tvb, local_offset, 2, ENC_BIG_ENDIAN);
remote_lid = tvb_get_ntohs(tvb, local_offset); local_offset += 2;
proto_tree_add_item(CM_header_tree, hf_cm_req_primary_local_gid, tvb, local_offset, 16, ENC_NA);
tvb_get_ipv6(tvb, local_offset, (struct e_in6_addr*)local_gid); local_offset += 16;
proto_tree_add_item(CM_header_tree, hf_cm_req_primary_remote_gid, tvb, local_offset, 16, ENC_NA);
tvb_get_ipv6(tvb, local_offset, (struct e_in6_addr*)remote_gid); local_offset += 16;
proto_tree_add_item(CM_header_tree, hf_cm_req_primary_flow_label, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_req_primary_packet_rate, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_req_primary_traffic_class, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_req_primary_hop_limit, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_req_primary_sl, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(CM_header_tree, hf_cm_req_primary_subnet_local, tvb, local_offset, 1, ENC_BIG_ENDIAN);
local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_req_primary_local_ack_to, tvb, local_offset, 1, ENC_BIG_ENDIAN);
local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_req_alt_local_lid, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(CM_header_tree, hf_cm_req_alt_remote_lid, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(CM_header_tree, hf_cm_req_alt_local_gid, tvb, local_offset, 16, ENC_NA); local_offset += 16;
proto_tree_add_item(CM_header_tree, hf_cm_req_alt_remote_gid, tvb, local_offset, 16, ENC_NA); local_offset += 16;
proto_tree_add_item(CM_header_tree, hf_cm_req_flow_label, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_req_packet_rate, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_req_alt_traffic_class, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_req_alt_hop_limit, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_req_SL, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(CM_header_tree, hf_cm_req_subnet_local, tvb, local_offset, 1, ENC_BIG_ENDIAN);
local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_req_local_ACK_timeout, tvb, local_offset, 1, ENC_BIG_ENDIAN);
local_offset += 1;
if (!pinfo->fd->flags.visited)
{
connection_context *connection;
conversation_infiniband_data *proto_data;
conversation_t *conv;
guint64 *hash_key = g_malloc(sizeof(guint64));
connection = g_malloc(sizeof(connection_context));
memcpy(&(connection->req_gid), local_gid, GID_SIZE);
memcpy(&(connection->resp_gid), remote_gid, GID_SIZE);
connection->req_lid = local_lid;
connection->resp_lid = remote_lid;
connection->req_qp = local_qpn;
connection->resp_qp = 0;
connection->service_id = serviceid;
*hash_key = MadData.transactionID;
ADD_ADDRESS_TO_HASH(*hash_key, &pinfo->src);
g_hash_table_replace(CM_context_table, hash_key, connection);
proto_data = se_alloc(sizeof(conversation_infiniband_data));
proto_data->service_id = connection->service_id;
conv = conversation_new(pinfo->fd->num, &pinfo->src, &pinfo->dst,
PT_IBQP, pinfo->srcport, pinfo->destport, 0);
conversation_add_proto_data(conv, proto_infiniband, proto_data);
}
next_tvb = tvb_new_subset(tvb, local_offset, 92, -1);
if (! dissector_try_heuristic(heur_dissectors_cm_private, next_tvb, pinfo, parentTree) )
proto_tree_add_item(CM_header_tree, hf_cm_req_private_data, tvb, local_offset, 92, ENC_NA);
local_offset += 92;
}
break;
case ATTR_CM_REP: {
guint32 remote_qpn;
proto_tree_add_item(CM_header_tree, hf_cm_rep_localcommid, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(CM_header_tree, hf_cm_rep_remotecommid, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(CM_header_tree, hf_cm_rep_localqkey, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(CM_header_tree, hf_cm_rep_localqpn, tvb, local_offset, 3, ENC_BIG_ENDIAN);
remote_qpn = tvb_get_ntoh24(tvb, local_offset); local_offset += 3;
local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_rep_localeecontnum, tvb, local_offset, 3, ENC_BIG_ENDIAN); local_offset += 3;
local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_rep_startingpsn, tvb, local_offset, 3, ENC_BIG_ENDIAN); local_offset += 3;
local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_rep_responderres, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_rep_initiatordepth, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_rep_tgtackdelay, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(CM_header_tree, hf_cm_rep_failoveracc, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(CM_header_tree, hf_cm_rep_e2eflowctl, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_rep_rnrretrycount, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(CM_header_tree, hf_cm_rep_srq, tvb, local_offset, 1, ENC_BIG_ENDIAN);
local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_rep_localcaguid, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
if (!pinfo->fd->flags.visited)
{
connection_context *connection;
guint64 hash_key;
hash_key = MadData.transactionID;
ADD_ADDRESS_TO_HASH(hash_key, &pinfo->dst);
connection = g_hash_table_lookup(CM_context_table, &hash_key);
if (connection)
{
address req_addr,
resp_addr;
conversation_t *conv;
conversation_infiniband_data *proto_data = NULL;
connection->resp_qp = remote_qpn;
proto_data = se_alloc(sizeof(conversation_infiniband_data));
proto_data->service_id = connection->service_id;
SET_ADDRESS(&req_addr, AT_IB, GID_SIZE, connection->req_gid);
SET_ADDRESS(&resp_addr, AT_IB, GID_SIZE, connection->resp_gid);
conv = conversation_new(pinfo->fd->num, &req_addr, &req_addr,
PT_IBQP, connection->req_qp, connection->req_qp, NO_ADDR2|NO_PORT2);
conversation_add_proto_data(conv, proto_infiniband, proto_data);
conv = conversation_new(pinfo->fd->num, &resp_addr, &resp_addr,
PT_IBQP, connection->resp_qp, connection->resp_qp, NO_ADDR2|NO_PORT2);
conversation_add_proto_data(conv, proto_infiniband, proto_data);
SET_ADDRESS(&req_addr, AT_IB, sizeof(guint16), &(connection->req_lid));
SET_ADDRESS(&resp_addr, AT_IB, sizeof(guint16), &(connection->resp_lid));
conv = conversation_new(pinfo->fd->num, &req_addr, &req_addr,
PT_IBQP, connection->req_qp, connection->req_qp, NO_ADDR2|NO_PORT2);
conversation_add_proto_data(conv, proto_infiniband, proto_data);
conv = conversation_new(pinfo->fd->num, &resp_addr, &resp_addr,
PT_IBQP, connection->resp_qp, connection->resp_qp, NO_ADDR2|NO_PORT2);
conversation_add_proto_data(conv, proto_infiniband, proto_data);
g_hash_table_remove(CM_context_table, &hash_key);
}
}
next_tvb = tvb_new_subset(tvb, local_offset, 196, -1);
if (! dissector_try_heuristic(heur_dissectors_cm_private, next_tvb, pinfo, parentTree) )
proto_tree_add_item(CM_header_tree, hf_cm_rep_privatedata, tvb, local_offset, 196, ENC_NA);
local_offset += 196;
}
break;
case ATTR_CM_RTU:
proto_tree_add_item(CM_header_tree, hf_cm_rtu_localcommid, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(CM_header_tree, hf_cm_rtu_remotecommid, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(CM_header_tree, hf_cm_rtu_privatedata, tvb, local_offset, 224, ENC_NA); local_offset += 224;
break;
case ATTR_CM_REJ:
proto_tree_add_item(CM_header_tree, hf_cm_rej_local_commid, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(CM_header_tree, hf_cm_rej_remote_commid, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(CM_header_tree, hf_cm_rej_msg_rej, tvb, local_offset, 1, ENC_BIG_ENDIAN);
local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_rej_rej_info_len, tvb, local_offset, 1, ENC_BIG_ENDIAN);
local_offset += 1;
proto_tree_add_item(CM_header_tree, hf_cm_rej_reason, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(CM_header_tree, hf_cm_rej_add_rej_info, tvb, local_offset, 72, ENC_NA); local_offset += 72;
proto_tree_add_item(CM_header_tree, hf_cm_rej_private_data, tvb, local_offset, 148, ENC_NA); local_offset += 148;
break;
default:
proto_item_append_text(CM_header_item, " (Dissector Not Implemented)"); local_offset += MAD_DATA_SIZE;
break;
}
*offset = local_offset;
}
static void parse_SNMP(proto_tree *parentTree, tvbuff_t *tvb, gint *offset)
{
MAD_Data MadData;
gint local_offset;
proto_item *PERF_header_item;
if (!parse_MAD_Common(parentTree, tvb, offset, &MadData))
{
return;
}
local_offset = *offset;
PERF_header_item = proto_tree_add_item(parentTree, hf_infiniband_smp_data, tvb, local_offset, MAD_DATA_SIZE, ENC_NA); local_offset += MAD_DATA_SIZE;
proto_item_set_text(PERF_header_item, "%s", "SNMP - SNMP Tunneling MAD (Dissector Not Implemented)");
*offset = local_offset;
}
static void parse_VENDOR_MANAGEMENT(proto_tree *parentTree, tvbuff_t *tvb, gint *offset)
{
MAD_Data MadData;
gint local_offset;
proto_item *PERF_header_item;
if (!parse_MAD_Common(parentTree, tvb, offset, &MadData))
{
return;
}
local_offset = *offset;
PERF_header_item = proto_tree_add_item(parentTree, hf_infiniband_smp_data, tvb, local_offset, MAD_DATA_SIZE, ENC_NA); local_offset += MAD_DATA_SIZE;
proto_item_set_text(PERF_header_item, "%s", "VENDOR - Vendor Specific Management MAD (Dissector Not Implemented)");
*offset = local_offset;
}
static void parse_APPLICATION_MANAGEMENT(proto_tree *parentTree, tvbuff_t *tvb, gint *offset)
{
MAD_Data MadData;
gint local_offset;
proto_item *PERF_header_item;
if (!parse_MAD_Common(parentTree, tvb, offset, &MadData))
{
return;
}
local_offset = *offset;
PERF_header_item = proto_tree_add_item(parentTree, hf_infiniband_smp_data, tvb, local_offset, MAD_DATA_SIZE, ENC_NA); local_offset += MAD_DATA_SIZE;
proto_item_set_text(PERF_header_item, "%s", "APP - Application Specific MAD (Dissector Not Implemented)");
*offset = local_offset;
}
static void parse_RESERVED_MANAGEMENT(proto_tree *parentTree, tvbuff_t *tvb, gint *offset)
{
MAD_Data MadData;
gint local_offset;
proto_item *PERF_header_item;
if (!parse_MAD_Common(parentTree, tvb, offset, &MadData))
{
return;
}
local_offset = *offset;
PERF_header_item = proto_tree_add_item(parentTree, hf_infiniband_smp_data, tvb, local_offset, 256, ENC_NA); local_offset += 256;
proto_item_set_text(PERF_header_item, "%s", "RESERVED - Reserved MAD Type (Possible Device Error)");
*offset = local_offset;
}
static gboolean parse_MAD_Common(proto_tree *parentTree, tvbuff_t *tvb, gint *offset, MAD_Data* MadData)
{
gint local_offset = *offset;
proto_item *MAD_header_item;
proto_tree *MAD_header_tree;
if (MadData == NULL)
return FALSE;
if (!tvb_bytes_exist(tvb, *offset, 256))
return FALSE;
MadData->managementClass = tvb_get_guint8(tvb, local_offset + 1);
MadData->classVersion = tvb_get_guint8(tvb, local_offset + 2);
MadData->method = tvb_get_guint8(tvb, local_offset + 3);
MadData->status = tvb_get_guint8(tvb, local_offset + 4);
MadData->classSpecific = tvb_get_ntohs(tvb, local_offset + 6);
MadData->transactionID = tvb_get_ntoh64(tvb, local_offset + 8);
MadData->attributeID = tvb_get_ntohs(tvb, local_offset + 16);
MadData->attributeModifier = tvb_get_ntohl(tvb, local_offset + 20);
tvb_memcpy(tvb, MadData->data, local_offset + 24, MAD_DATA_SIZE);
MAD_header_item = proto_tree_add_item(parentTree, hf_infiniband_MAD, tvb, local_offset, 256, ENC_NA);
proto_item_set_text(MAD_header_item, "%s", "MAD Header - Common Management Datagram");
MAD_header_tree = proto_item_add_subtree(MAD_header_item, ett_mad);
proto_tree_add_item(MAD_header_tree, hf_infiniband_base_version, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(MAD_header_tree, hf_infiniband_mgmt_class, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(MAD_header_tree, hf_infiniband_class_version, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(MAD_header_tree, hf_infiniband_method, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(MAD_header_tree, hf_infiniband_status, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(MAD_header_tree, hf_infiniband_class_specific, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(MAD_header_tree, hf_infiniband_transaction_id, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(MAD_header_tree, hf_infiniband_attribute_id, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(MAD_header_tree, hf_infiniband_reserved16, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(MAD_header_tree, hf_infiniband_attribute_modifier, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(MAD_header_tree, hf_infiniband_data, tvb, local_offset, MAD_DATA_SIZE, ENC_NA);
*offset = local_offset;
return TRUE;
}
static gboolean parse_RMPP(proto_tree *parentTree, tvbuff_t *tvb, gint *offset)
{
gint local_offset = *offset;
guint8 RMPP_Type = tvb_get_guint8(tvb, local_offset + 1);
proto_item *RMPP_header_item;
proto_tree *RMPP_header_tree;
RMPP_header_item = proto_tree_add_item(parentTree, hf_infiniband_RMPP, tvb, local_offset, 12, ENC_NA);
proto_item_set_text(RMPP_header_item, "%s", val_to_str(RMPP_Type, RMPP_Packet_Types, "Reserved RMPP Type! (0x%02x)"));
RMPP_header_tree = proto_item_add_subtree(RMPP_header_item, ett_rmpp);
proto_tree_add_item(RMPP_header_tree, hf_infiniband_rmpp_version, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(RMPP_header_tree, hf_infiniband_rmpp_type, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(RMPP_header_tree, hf_infiniband_r_resp_time, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(RMPP_header_tree, hf_infiniband_rmpp_flags, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(RMPP_header_tree, hf_infiniband_rmpp_status, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
switch (RMPP_Type)
{
case RMPP_ILLEGAL:
proto_tree_add_item(RMPP_header_tree, hf_infiniband_rmpp_data1, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(RMPP_header_tree, hf_infiniband_rmpp_data2, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
break;
case RMPP_DATA:
proto_tree_add_item(RMPP_header_tree, hf_infiniband_segment_number, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(RMPP_header_tree, hf_infiniband_payload_length32, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(RMPP_header_tree, hf_infiniband_transferred_data, tvb, local_offset, 220, ENC_NA);
break;
case RMPP_ACK:
proto_tree_add_item(RMPP_header_tree, hf_infiniband_segment_number, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(RMPP_header_tree, hf_infiniband_new_window_last, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(RMPP_header_tree, hf_infiniband_reserved220, tvb, local_offset, 220, ENC_NA);
break;
case RMPP_STOP:
case RMPP_ABORT:
proto_tree_add_item(RMPP_header_tree, hf_infiniband_reserved32, tvb, local_offset, 4, ENC_NA); local_offset += 4;
proto_tree_add_item(RMPP_header_tree, hf_infiniband_reserved32, tvb, local_offset, 4, ENC_NA); local_offset += 4;
proto_tree_add_item(RMPP_header_tree, hf_infiniband_optional_extended_error_data, tvb, local_offset, 220, ENC_NA);
break;
default:
break;
}
*offset = local_offset;
return TRUE;
}
static void label_SUBM_Method(proto_item *SubMItem, MAD_Data *MadHeader, packet_info *pinfo)
{
const char *label = val_to_str_const(MadHeader->method, SUBM_Methods, "(Unknown SubManagement Method!)");
proto_item_append_text(SubMItem, "%s", label);
col_append_str(pinfo->cinfo, COL_INFO, label);
}
static void label_SUBA_Method(proto_item *SubAItem, MAD_Data *MadHeader, packet_info *pinfo)
{
const char *label = val_to_str_const(MadHeader->method, SUBA_Methods, "(Unknown SubAdministration Method!)");
proto_item_append_text(SubAItem, "%s", label);
col_append_str(pinfo->cinfo, COL_INFO, label);
}
static void label_SUBM_Attribute(proto_item *SubMItem, MAD_Data *MadHeader, packet_info *pinfo)
{
const char *label = val_to_str_const(MadHeader->attributeID, SUBM_Attributes, "(Unknown SubManagement Attribute!)");
proto_item_append_text(SubMItem, "%s", &label[11]);
col_append_str(pinfo->cinfo, COL_INFO, &label[11]);
}
static void label_SUBA_Attribute(proto_item *SubAItem, MAD_Data *MadHeader, packet_info *pinfo)
{
const char *label = val_to_str_const(MadHeader->attributeID, SUBA_Attributes, "(Unknown SubAdministration Attribute!)");
proto_item_append_text(SubAItem, "%s", &label[11]);
col_append_str(pinfo->cinfo, COL_INFO, &label[11]);
}
static gboolean parse_SUBM_Attribute(proto_tree *parentTree, tvbuff_t *tvb, gint *offset, MAD_Data *MadHeader)
{
guint16 attributeID = MadHeader->attributeID;
proto_item *SUBM_Attribute_header_item;
proto_tree *SUBM_Attribute_header_tree;
SUBM_Attribute_header_item = proto_tree_add_item(parentTree, hf_infiniband_smp_data, tvb, *offset, 64, ENC_NA);
proto_item_set_text(SUBM_Attribute_header_item, "%s", val_to_str(attributeID, SUBM_Attributes, "Unknown Attribute Type! (0x%02x)"));
SUBM_Attribute_header_tree = proto_item_add_subtree(SUBM_Attribute_header_item, ett_subm_attribute);
switch (attributeID)
{
case 0x0002:
parse_NoticesAndTraps(SUBM_Attribute_header_tree , tvb, offset);
break;
case 0x0010:
parse_NodeDescription(SUBM_Attribute_header_tree , tvb, offset);
break;
case 0x0011:
parse_NodeInfo(SUBM_Attribute_header_tree , tvb, offset);
break;
case 0x0012:
parse_SwitchInfo(SUBM_Attribute_header_tree , tvb, offset);
break;
case 0x0014:
parse_GUIDInfo(SUBM_Attribute_header_tree , tvb, offset);
break;
case 0x0015:
parse_PortInfo(SUBM_Attribute_header_tree , tvb, offset);
break;
case 0x0016:
parse_P_KeyTable(SUBM_Attribute_header_tree , tvb, offset);
break;
case 0x0017:
parse_SLtoVLMappingTable(SUBM_Attribute_header_tree , tvb, offset);
break;
case 0x0018:
parse_VLArbitrationTable(SUBM_Attribute_header_tree , tvb, offset);
break;
case 0x0019:
parse_LinearForwardingTable(SUBM_Attribute_header_tree , tvb, offset);
break;
case 0x001A:
parse_RandomForwardingTable(SUBM_Attribute_header_tree , tvb, offset);
break;
case 0x001B:
parse_MulticastForwardingTable(SUBM_Attribute_header_tree , tvb, offset);
break;
case 0x001C:
parse_SMInfo(SUBM_Attribute_header_tree , tvb, offset);
break;
case 0x0020:
parse_VendorDiag(SUBM_Attribute_header_tree , tvb, offset);
break;
case 0x0030:
parse_LedInfo(SUBM_Attribute_header_tree , tvb, offset);
break;
case 0x0031:
parse_LinkSpeedWidthPairsTable(SUBM_Attribute_header_tree , tvb, offset);
break;
default:
break;
}
*offset += 64;
return TRUE;
}
static gboolean parse_SUBA_Attribute(proto_tree *parentTree, tvbuff_t *tvb, gint *offset, MAD_Data *MadHeader)
{
guint16 attributeID = MadHeader->attributeID;
proto_item *SUBA_Attribute_header_item;
proto_tree *SUBA_Attribute_header_tree;
SUBA_Attribute_header_item = proto_tree_add_item(parentTree, hf_infiniband_SA, tvb, *offset, 200, ENC_NA);
proto_item_set_text(SUBA_Attribute_header_item, "%s", val_to_str(attributeID, SUBA_Attributes, "Unknown Attribute Type! (0x%02x)"));
SUBA_Attribute_header_tree = proto_item_add_subtree(SUBA_Attribute_header_item, ett_suba_attribute);
parse_RID(SUBA_Attribute_header_tree, tvb, offset, MadHeader);
switch (MadHeader->attributeID)
{
case 0x0001:
parse_PortInfo(SUBA_Attribute_header_tree, tvb, offset);
break;
case 0x0002:
parse_NoticesAndTraps(SUBA_Attribute_header_tree, tvb, offset);
break;
case 0x0003:
parse_InformInfo(SUBA_Attribute_header_tree, tvb, offset);
break;
case 0x0011:
parse_NodeInfo(SUBA_Attribute_header_tree, tvb, offset);
*offset += 40;
parse_NodeDescription(SUBA_Attribute_header_tree, tvb, offset);
break;
case 0x0012:
parse_PortInfo(SUBA_Attribute_header_tree, tvb, offset);
break;
case 0x0013:
parse_SLtoVLMappingTable(SUBA_Attribute_header_tree, tvb, offset);
break;
case 0x0014:
parse_SwitchInfo(SUBA_Attribute_header_tree, tvb, offset);
break;
case 0x0015:
parse_LinearForwardingTable(SUBA_Attribute_header_tree, tvb, offset);
break;
case 0x0016:
parse_RandomForwardingTable(SUBA_Attribute_header_tree, tvb, offset);
break;
case 0x0017:
parse_MulticastForwardingTable(SUBA_Attribute_header_tree, tvb, offset);
break;
case 0x0018:
parse_SMInfo(SUBA_Attribute_header_tree, tvb, offset);
break;
case 0x0019:
parse_LinkSpeedWidthPairsTable(SUBA_Attribute_header_tree, tvb, offset);
break;
case 0x00F3:
parse_InformInfo(SUBA_Attribute_header_tree, tvb, offset);
break;
case 0x0020:
parse_LinkRecord(SUBA_Attribute_header_tree, tvb, offset);
break;
case 0x0030:
parse_GUIDInfo(SUBA_Attribute_header_tree, tvb, offset);
break;
case 0x0031:
parse_ServiceRecord(SUBA_Attribute_header_tree, tvb, offset);
break;
case 0x0033:
parse_P_KeyTable(SUBA_Attribute_header_tree, tvb, offset);
break;
case 0x0035:
parse_PathRecord(SUBA_Attribute_header_tree, tvb, offset);
break;
case 0x0036:
parse_VLArbitrationTable(SUBA_Attribute_header_tree, tvb, offset);
break;
case 0x0038:
parse_MCMemberRecord(SUBA_Attribute_header_tree, tvb, offset);
break;
case 0x0039:
parse_TraceRecord(SUBA_Attribute_header_tree, tvb, offset);
break;
case 0x003A:
parse_MultiPathRecord(SUBA_Attribute_header_tree, tvb, offset);
break;
case 0x003B:
parse_ServiceAssociationRecord(SUBA_Attribute_header_tree, tvb, offset);
break;
default:
break;
}
*offset += 200;
return TRUE;
}
static gint parse_NoticeDataDetails(proto_tree* parentTree, tvbuff_t* tvb, gint *offset, guint16 trapNumber)
{
gint local_offset = *offset;
proto_item *DataDetails_header_item;
proto_tree *DataDetails_header_tree;
if (!parentTree)
return 0;
DataDetails_header_item = proto_tree_add_item(parentTree, hf_infiniband_smp_data, tvb, local_offset, 54, ENC_NA);
DataDetails_header_tree = proto_item_add_subtree(DataDetails_header_item, ett_datadetails);
switch (trapNumber)
{
case 64:
proto_item_set_text(DataDetails_header_item, "%s", "Trap 64 DataDetails");
local_offset += 6;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_GIDADDR, tvb, local_offset, 16, ENC_NA); local_offset += 16;
break;
case 65:
proto_item_set_text(DataDetails_header_item, "%s", "Trap 65 DataDetails");
local_offset += 6;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_GIDADDR, tvb, local_offset, 16, ENC_NA); local_offset += 16;
break;
case 66:
proto_item_set_text(DataDetails_header_item, "%s", "Trap 66 DataDetails");
local_offset += 6;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_GIDADDR, tvb, local_offset, 16, ENC_NA); local_offset += 16;
break;
case 67:
proto_item_set_text(DataDetails_header_item, "%s", "Trap 67 DataDetails");
local_offset += 6;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_GIDADDR, tvb, local_offset, 16, ENC_NA); local_offset += 16;
break;
case 68:
proto_item_set_text(DataDetails_header_item, "%s", "Trap 68 DataDetails");
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_COMP_MASK, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_WAIT_FOR_REPATH, tvb, local_offset, 1, ENC_BIG_ENDIAN);
break;
case 69:
proto_item_set_text(DataDetails_header_item, "%s", "Trap 69 DataDetails");
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_COMP_MASK, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_WAIT_FOR_REPATH, tvb, local_offset, 1, ENC_BIG_ENDIAN);
break;
case 128:
proto_item_set_text(DataDetails_header_item, "%s", "Trap 128 DataDetails");
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_LIDADDR, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
break;
case 129:
proto_item_set_text(DataDetails_header_item, "%s", "Trap 129 DataDetails");
local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_LIDADDR, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_PORTNO, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
break;
case 130:
proto_item_set_text(DataDetails_header_item, "%s", "Trap 130 DataDetails");
local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_LIDADDR, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_PORTNO, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
break;
case 131:
proto_item_set_text(DataDetails_header_item, "%s", "Trap 131 DataDetails");
local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_LIDADDR, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_PORTNO, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
break;
case 144:
proto_item_set_text(DataDetails_header_item, "%s", "Trap 144 DataDetails");
local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_LIDADDR, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
local_offset += 1;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_OtherLocalChanges, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_CAPABILITYMASK, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
local_offset += 1;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_LinkSpeecEnabledChange, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_LinkWidthEnabledChange, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_NodeDescriptionChange, tvb, local_offset, 1, ENC_BIG_ENDIAN);
break;
case 145:
proto_item_set_text(DataDetails_header_item, "%s", "Trap 145 DataDetails");
local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_LIDADDR, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_SYSTEMIMAGEGUID, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
break;
case 256:
proto_item_set_text(DataDetails_header_item, "%s", "Trap 256 DataDetails");
local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_LIDADDR, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_DRSLID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_METHOD, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
local_offset += 1;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_ATTRIBUTEID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_ATTRIBUTEMODIFIER, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_MKEY, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
local_offset += 1;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_DRNotice, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_DRPathTruncated, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_DRHopCount, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_DRNoticeReturnPath, tvb, local_offset, 30, ENC_NA); local_offset += 30;
break;
case 257:
proto_item_set_text(DataDetails_header_item, "%s", "Trap 257 DataDetails");
local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_LIDADDR1, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_LIDADDR2, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_KEY, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_SL, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_QP1, tvb, local_offset, 3, ENC_BIG_ENDIAN); local_offset += 3;
local_offset += 1;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_QP2, tvb, local_offset, 3, ENC_BIG_ENDIAN); local_offset += 3;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_GIDADDR1, tvb, local_offset, 16, ENC_NA); local_offset += 16;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_GIDADDR2, tvb, local_offset, 16, ENC_NA); local_offset += 16;
break;
case 258:
proto_item_set_text(DataDetails_header_item, "%s", "Trap 258 DataDetails");
local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_LIDADDR1, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_LIDADDR2, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_KEY, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_SL, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_QP1, tvb, local_offset, 3, ENC_BIG_ENDIAN); local_offset += 3;
local_offset += 1;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_QP2, tvb, local_offset, 3, ENC_BIG_ENDIAN); local_offset += 3;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_GIDADDR1, tvb, local_offset, 16, ENC_NA); local_offset += 16;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_GIDADDR2, tvb, local_offset, 16, ENC_NA); local_offset += 16;
break;
case 259:
proto_item_set_text(DataDetails_header_item, "%s", "Trap 259 DataDetails");
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_DataValid, tvb, local_offset, 2, ENC_NA); local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_LIDADDR1, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_LIDADDR2, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_PKEY, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_SL, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_QP1, tvb, local_offset, 3, ENC_BIG_ENDIAN); local_offset += 3;
local_offset += 1;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_QP2, tvb, local_offset, 3, ENC_BIG_ENDIAN); local_offset += 3;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_GIDADDR1, tvb, local_offset, 16, ENC_NA); local_offset += 16;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_GIDADDR2, tvb, local_offset, 16, ENC_NA); local_offset += 16;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_SWLIDADDR, tvb, local_offset, 2, ENC_NA); local_offset += 2;
proto_tree_add_item(DataDetails_header_tree, hf_infiniband_Trap_PORTNO, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
break;
default:
proto_item_set_text(DataDetails_header_item, "%s", "Vendor Specific Subnet Management Trap"); local_offset += 54;
break;
}
return local_offset;
}
static void parse_NoticesAndTraps(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint local_offset = *offset;
proto_item *NoticesAndTraps_header_item;
proto_tree *NoticesAndTraps_header_tree;
guint16 trapNumber = tvb_get_ntohs(tvb, local_offset + 4);
if (!parentTree)
return;
NoticesAndTraps_header_item = proto_tree_add_item(parentTree, hf_infiniband_smp_data, tvb, local_offset, 64, ENC_NA);
proto_item_set_text(NoticesAndTraps_header_item, "%s", val_to_str(trapNumber, Trap_Description, "Unknown or Vendor Specific Trap Number! (0x%02x)"));
NoticesAndTraps_header_tree = proto_item_add_subtree(NoticesAndTraps_header_item, ett_noticestraps);
proto_tree_add_item(NoticesAndTraps_header_tree, hf_infiniband_Notice_IsGeneric, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(NoticesAndTraps_header_tree, hf_infiniband_Notice_Type, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(NoticesAndTraps_header_tree, hf_infiniband_Notice_ProducerTypeVendorID, tvb, local_offset, 3, ENC_BIG_ENDIAN); local_offset += 3;
proto_tree_add_item(NoticesAndTraps_header_tree, hf_infiniband_Notice_TrapNumberDeviceID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(NoticesAndTraps_header_tree, hf_infiniband_Notice_IssuerLID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(NoticesAndTraps_header_tree, hf_infiniband_Notice_NoticeToggle, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(NoticesAndTraps_header_tree, hf_infiniband_Notice_NoticeCount, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
parse_NoticeDataDetails(NoticesAndTraps_header_tree, tvb, &local_offset, trapNumber);
proto_tree_add_item(NoticesAndTraps_header_tree, hf_infiniband_Notice_DataDetails, tvb, local_offset, 54, ENC_NA); local_offset += 54;
#if 0
*proto_tree_add_item(NoticesAndTraps_header_tree, hf_infiniband_Notice_IssuerGID, tvb, local_offset, 16, ENC_NA); local_offset += 16;
*proto_tree_add_item(NoticesAndTraps_header_tree, hf_infiniband_Notice_ClassTrapSpecificData, tvb, local_offset, 1, ENC_NA); local_offset += 1;
#endif
}
static void parse_NodeDescription(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint local_offset = *offset;
proto_tree *NodeDescription_header_tree;
if (!parentTree)
return;
NodeDescription_header_tree = parentTree;
proto_tree_add_item(NodeDescription_header_tree, hf_infiniband_NodeDescription_NodeString, tvb, local_offset, 64, ENC_ASCII|ENC_NA);
}
static int parse_NodeInfo(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint local_offset = *offset;
proto_tree *NodeInfo_header_tree;
if (!parentTree)
return *offset;
NodeInfo_header_tree = parentTree;
proto_tree_add_item(NodeInfo_header_tree, hf_infiniband_NodeInfo_BaseVersion, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(NodeInfo_header_tree, hf_infiniband_NodeInfo_ClassVersion, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(NodeInfo_header_tree, hf_infiniband_NodeInfo_NodeType, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(NodeInfo_header_tree, hf_infiniband_NodeInfo_NumPorts, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(NodeInfo_header_tree, hf_infiniband_NodeInfo_SystemImageGUID, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(NodeInfo_header_tree, hf_infiniband_NodeInfo_NodeGUID, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(NodeInfo_header_tree, hf_infiniband_NodeInfo_PortGUID, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(NodeInfo_header_tree, hf_infiniband_NodeInfo_PartitionCap, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(NodeInfo_header_tree, hf_infiniband_NodeInfo_DeviceID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(NodeInfo_header_tree, hf_infiniband_NodeInfo_Revision, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(NodeInfo_header_tree, hf_infiniband_NodeInfo_LocalPortNum, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(NodeInfo_header_tree, hf_infiniband_NodeInfo_VendorID, tvb, local_offset, 3, ENC_BIG_ENDIAN); local_offset += 3;
return local_offset;
}
static int parse_SwitchInfo(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint local_offset = *offset;
proto_tree *SwitchInfo_header_tree;
if (!parentTree)
return *offset;
SwitchInfo_header_tree = parentTree;
proto_tree_add_item(SwitchInfo_header_tree, hf_infiniband_SwitchInfo_LinearFDBCap, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(SwitchInfo_header_tree, hf_infiniband_SwitchInfo_RandomFDBCap, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(SwitchInfo_header_tree, hf_infiniband_SwitchInfo_MulticastFDBCap, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(SwitchInfo_header_tree, hf_infiniband_SwitchInfo_LinearFDBTop, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(SwitchInfo_header_tree, hf_infiniband_SwitchInfo_DefaultPort, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(SwitchInfo_header_tree, hf_infiniband_SwitchInfo_DefaultMulticastPrimaryPort, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(SwitchInfo_header_tree, hf_infiniband_SwitchInfo_DefaultMulticastNotPrimaryPort, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(SwitchInfo_header_tree, hf_infiniband_SwitchInfo_LifeTimeValue, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(SwitchInfo_header_tree, hf_infiniband_SwitchInfo_PortStateChange, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(SwitchInfo_header_tree, hf_infiniband_SwitchInfo_OptimizedSLtoVLMappingProgramming, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(SwitchInfo_header_tree, hf_infiniband_SwitchInfo_LIDsPerPort, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(SwitchInfo_header_tree, hf_infiniband_SwitchInfo_PartitionEnforcementCap, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(SwitchInfo_header_tree, hf_infiniband_SwitchInfo_InboundEnforcementCap, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(SwitchInfo_header_tree, hf_infiniband_SwitchInfo_OutboundEnforcementCap, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(SwitchInfo_header_tree, hf_infiniband_SwitchInfo_FilterRawInboundCap, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(SwitchInfo_header_tree, hf_infiniband_SwitchInfo_FilterRawOutboundCap, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(SwitchInfo_header_tree, hf_infiniband_SwitchInfo_EnhancedPortZero, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
return local_offset;
}
static int parse_GUIDInfo(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint local_offset = *offset;
proto_tree *GUIDInfo_header_tree;
proto_item *tempItemLow;
gint i;
if (!parentTree)
return *offset;
GUIDInfo_header_tree = parentTree;
for (i = 0; i < 8; i++)
{
tempItemLow = proto_tree_add_item(GUIDInfo_header_tree, hf_infiniband_GUIDInfo_GUID, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_item_append_text(tempItemLow, "(%u)", i);
}
return local_offset;
}
static int parse_PortInfo(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint local_offset = *offset;
proto_tree *PortInfo_header_tree;
proto_item *PortInfo_CapabilityMask_item;
proto_tree *PortInfo_CapabilityMask_tree;
proto_item *temp_item;
guint16 temp_val;
if (!parentTree)
return *offset;
PortInfo_header_tree = parentTree;
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_M_Key, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_GidPrefix, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_LID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_MasterSMLID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
PortInfo_CapabilityMask_item = proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_CapabilityMask, tvb, local_offset, 4, ENC_BIG_ENDIAN);
PortInfo_CapabilityMask_tree = proto_item_add_subtree(PortInfo_CapabilityMask_item, ett_portinfo_capmask);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_SM, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_NoticeSupported, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_TrapSupported, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_OptionalPDSupported, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_AutomaticMigrationSupported, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_SLMappingSupported, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_MKeyNVRAM, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_PKeyNVRAM, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_LEDInfoSupported, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_SMdisabled, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_SystemImageGUIDSupported, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_PKeySwitchExternalPortTrapSupported, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_CommunicationsManagementSupported, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_SNMPTunnelingSupported, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_ReinitSupported, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_DeviceManagementSupported, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_VendorClassSupported, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_DRNoticeSupported, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_CapabilityMaskNoticeSupported, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_BootManagementSupported, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_LinkRoundTripLatencySupported, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_ClientRegistrationSupported, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_OtherLocalChangesNoticeSupported, tvb, local_offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_CapabilityMask_tree, hf_infiniband_PortInfo_CapabilityMask_LinkSpeedWIdthPairsTableSupported, tvb, local_offset, 4, ENC_BIG_ENDIAN);
local_offset += 4;
temp_item = proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_DiagCode, tvb, local_offset, 2, ENC_BIG_ENDIAN);
temp_val = tvb_get_ntohs(tvb, local_offset);
proto_item_append_text(temp_item, ", %s", val_to_str_const(temp_val, DiagCode, "Reserved DiagCode! Possible Error"));
local_offset += 2;
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_M_KeyLeasePeriod, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_LocalPortNum, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
temp_item = proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_LinkWidthEnabled, tvb, local_offset, 1, ENC_BIG_ENDIAN);
temp_val = (guint16)tvb_get_guint8(tvb, local_offset);
proto_item_append_text(temp_item, ", %s", val_to_str_const(temp_val, LinkWidthEnabled, "Reserved LinkWidthEnabled Value! Possible Error"));
local_offset += 1;
temp_item = proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_LinkWidthSupported, tvb, local_offset, 1, ENC_BIG_ENDIAN);
temp_val = (guint16)tvb_get_guint8(tvb, local_offset);
proto_item_append_text(temp_item, ", %s", val_to_str_const(temp_val, LinkWidthSupported, "Reserved LinkWidthSupported Value! Possible Error"));
local_offset += 1;
temp_item = proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_LinkWidthActive, tvb, local_offset, 1, ENC_BIG_ENDIAN);
temp_val = (guint16)tvb_get_guint8(tvb, local_offset);
proto_item_append_text(temp_item, ", %s", val_to_str_const(temp_val, LinkWidthActive, "Reserved LinkWidthActive Value! Possible Error"));
local_offset += 1;
temp_item = proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_LinkSpeedSupported, tvb, local_offset, 1, ENC_BIG_ENDIAN);
temp_val = (guint16)tvb_get_guint8(tvb, local_offset);
temp_val = temp_val & 0x00F0;
temp_val = temp_val >> 4;
proto_item_append_text(temp_item, ", %s", val_to_str_const(temp_val, LinkSpeedSupported, "Reserved LinkWidthSupported Value! Possible Error"));
temp_item = proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_PortState, tvb, local_offset, 1, ENC_BIG_ENDIAN);
temp_val = (guint16)tvb_get_guint8(tvb, local_offset);
temp_val = temp_val & 0x000F;
proto_item_append_text(temp_item, ", %s", val_to_str_const(temp_val, PortState, "Reserved PortState Value! Possible Error"));
local_offset += 1;
temp_item = proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_PortPhysicalState, tvb, local_offset, 1, ENC_BIG_ENDIAN);
temp_val = (guint16)tvb_get_guint8(tvb, local_offset);
temp_val = temp_val & 0x00F0;
temp_val = temp_val >> 4;
proto_item_append_text(temp_item, ", %s", val_to_str_const(temp_val, PortPhysicalState, "Reserved PortPhysicalState Value! Possible Error"));
temp_item = proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_LinkDownDefaultState, tvb, local_offset, 1, ENC_BIG_ENDIAN);
temp_val = (guint16)tvb_get_guint8(tvb, local_offset);
temp_val = temp_val & 0x000F;
proto_item_append_text(temp_item, ", %s", val_to_str_const(temp_val, LinkDownDefaultState, "Reserved LinkDownDefaultState Value! Possible Error"));
local_offset += 1;
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_M_KeyProtectBits, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_LMC, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
temp_item = proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_LinkSpeedActive, tvb, local_offset, 1, ENC_BIG_ENDIAN);
temp_val = (guint16)tvb_get_guint8(tvb, local_offset);
temp_val = temp_val & 0x00F0;
temp_val = temp_val >> 4;
proto_item_append_text(temp_item, ", %s", val_to_str_const(temp_val, LinkSpeedActive, "Reserved LinkSpeedActive Value! Possible Error"));
temp_item = proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_LinkSpeedEnabled, tvb, local_offset, 1, ENC_BIG_ENDIAN);
temp_val = (guint16)tvb_get_guint8(tvb, local_offset);
temp_val = temp_val & 0x000F;
proto_item_append_text(temp_item, ", %s", val_to_str_const(temp_val, LinkSpeedEnabled, "Reserved LinkSpeedEnabled Value! Possible Error"));
local_offset += 1;
temp_item = proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_NeighborMTU, tvb, local_offset, 1, ENC_BIG_ENDIAN);
temp_val = (guint16)tvb_get_guint8(tvb, local_offset);
temp_val = temp_val & 0x00F0;
temp_val = temp_val >> 4;
proto_item_append_text(temp_item, ", %s", val_to_str_const(temp_val, NeighborMTU, "Reserved NeighborMTU Value! Possible Error"));
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_MasterSMSL, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
temp_item = proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_VLCap, tvb, local_offset, 1, ENC_BIG_ENDIAN);
temp_val = (guint16)tvb_get_guint8(tvb, local_offset);
temp_val = temp_val & 0x00F0;
temp_val = temp_val >> 4;
proto_item_append_text(temp_item, ", %s", val_to_str_const(temp_val, VLCap, "Reserved VLCap Value! Possible Error"));
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_InitType, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_VLHighLimit, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_VLArbitrationHighCap, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_VLArbitrationLowCap, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_InitTypeReply, tvb, local_offset, 1, ENC_BIG_ENDIAN);
temp_item = proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_MTUCap, tvb, local_offset, 1, ENC_BIG_ENDIAN);
temp_val = (guint16)tvb_get_guint8(tvb, local_offset);
temp_val = temp_val & 0x000F;
proto_item_append_text(temp_item, ", %s", val_to_str_const(temp_val, MTUCap, "Reserved MTUCap Value! Possible Error"));
local_offset += 1;
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_VLStallCount, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_HOQLife, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
temp_item = proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_OperationalVLs, tvb, local_offset, 1, ENC_BIG_ENDIAN);
temp_val = (guint16)tvb_get_guint8(tvb, local_offset);
temp_val = temp_val & 0x00F0;
temp_val = temp_val >> 4;
proto_item_append_text(temp_item, ", %s", val_to_str_const(temp_val, OperationalVLs, "Reserved OperationalVLs Value! Possible Error"));
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_PartitionEnforcementInbound, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_PartitionEnforcementOutbound, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_FilterRawInbound, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_FilterRawOutbound, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_M_KeyViolations, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_P_KeyViolations, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_Q_KeyViolations, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_GUIDCap, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_ClientReregister, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_SubnetTimeOut, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_RespTimeValue, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_LocalPhyErrors, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_OverrunErrors, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_MaxCreditHint, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 3;
proto_tree_add_item(PortInfo_header_tree, hf_infiniband_PortInfo_LinkRoundTripLatency, tvb, local_offset, 3, ENC_BIG_ENDIAN); local_offset += 3;
return local_offset;
}
static void parse_P_KeyTable(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint local_offset = *offset;
gint i;
proto_item *P_KeyTable_header_item;
proto_tree *P_KeyTable_header_tree;
proto_item *tempItemLow;
proto_item *tempItemHigh;
if (!parentTree)
return;
P_KeyTable_header_item = proto_tree_add_item(parentTree, hf_infiniband_P_KeyTable_P_KeyTableBlock, tvb, local_offset, 64, ENC_NA);
proto_item_set_text(P_KeyTable_header_item, "%s", "P_KeyTable");
P_KeyTable_header_tree = proto_item_add_subtree(P_KeyTable_header_item, ett_pkeytable);
for (i = 0; i < 32; i++)
{
tempItemLow = proto_tree_add_item(P_KeyTable_header_tree, hf_infiniband_P_KeyTable_MembershipType, tvb, local_offset, 1, ENC_BIG_ENDIAN);
tempItemHigh = proto_tree_add_item(P_KeyTable_header_tree, hf_infiniband_P_KeyTable_P_KeyBase, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_item_append_text(tempItemLow, "(%u)", i);
proto_item_append_text(tempItemHigh, "(%u)", i+1);
}
}
static void parse_SLtoVLMappingTable(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint local_offset = *offset;
proto_item *SLtoVLMappingTable_header_item;
proto_tree *SLtoVLMappingTable_header_tree;
proto_item *tempItemLow;
proto_item *tempItemHigh;
gint i;
if (!parentTree)
return;
SLtoVLMappingTable_header_item = proto_tree_add_item(parentTree, hf_infiniband_smp_data, tvb, local_offset, 64, ENC_NA);
proto_item_set_text(SLtoVLMappingTable_header_item, "%s", "SLtoVLMappingTable");
SLtoVLMappingTable_header_tree = proto_item_add_subtree(SLtoVLMappingTable_header_item, ett_sltovlmapping);
for (i = 0; i < 8; i++)
{
tempItemLow = proto_tree_add_item(SLtoVLMappingTable_header_tree, hf_infiniband_SLtoVLMappingTable_SLtoVL_HighBits, tvb, local_offset, 1, ENC_BIG_ENDIAN);
tempItemHigh = proto_tree_add_item(SLtoVLMappingTable_header_tree, hf_infiniband_SLtoVLMappingTable_SLtoVL_LowBits, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_item_append_text(tempItemLow, "(%u)", i);
proto_item_append_text(tempItemHigh, "(%u)", i+1);
}
}
static void parse_VLArbitrationTable(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint local_offset = *offset;
gint i;
proto_item *VLArbitrationTable_header_item;
proto_tree *VLArbitrationTable_header_tree;
proto_item *tempItemLow;
proto_item *tempItemHigh;
if (!parentTree)
return;
VLArbitrationTable_header_item = proto_tree_add_item(parentTree, hf_infiniband_smp_data, tvb, local_offset, 64, ENC_NA);
proto_item_set_text(VLArbitrationTable_header_item, "%s", "VLArbitrationTable");
VLArbitrationTable_header_tree = proto_item_add_subtree(VLArbitrationTable_header_item, ett_vlarbitrationtable);
for (i = 0; i < 32; i++)
{
tempItemLow = proto_tree_add_item(VLArbitrationTable_header_tree, hf_infiniband_VLArbitrationTable_VL, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
tempItemHigh = proto_tree_add_item(VLArbitrationTable_header_tree, hf_infiniband_VLArbitrationTable_Weight, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_item_append_text(tempItemLow, "(%u)", i);
proto_item_append_text(tempItemHigh, "(%u)", i);
}
}
static void parse_LinearForwardingTable(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint i;
gint local_offset = *offset;
proto_item *LinearForwardingTable_header_item;
proto_tree *LinearForwardingTable_header_tree;
proto_item *tempItemLow;
if (!parentTree)
return;
LinearForwardingTable_header_item = proto_tree_add_item(parentTree, hf_infiniband_smp_data, tvb, local_offset, 64, ENC_NA);
proto_item_set_text(LinearForwardingTable_header_item, "%s", "LinearForwardingTable");
LinearForwardingTable_header_tree = proto_item_add_subtree(LinearForwardingTable_header_item, ett_linearforwardingtable);
for (i = 0; i < 64; i++)
{
tempItemLow = proto_tree_add_item(LinearForwardingTable_header_tree, hf_infiniband_LinearForwardingTable_Port, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_item_append_text(tempItemLow, "(%u)", i);
}
}
static void parse_RandomForwardingTable(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint i;
gint local_offset = *offset;
proto_item *RandomForwardingTable_header_item;
proto_tree *RandomForwardingTable_header_tree;
proto_item *tempItemLow;
if (!parentTree)
return;
RandomForwardingTable_header_item = proto_tree_add_item(parentTree, hf_infiniband_smp_data, tvb, local_offset, 64, ENC_NA);
proto_item_set_text(RandomForwardingTable_header_item, "%s", "RandomForwardingTable");
RandomForwardingTable_header_tree = proto_item_add_subtree(RandomForwardingTable_header_item, ett_randomforwardingtable);
for (i = 0; i < 16; i++)
{
tempItemLow = proto_tree_add_item(RandomForwardingTable_header_tree, hf_infiniband_RandomForwardingTable_LID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_item_append_text(tempItemLow, "(%u)", i);
tempItemLow = proto_tree_add_item(RandomForwardingTable_header_tree, hf_infiniband_RandomForwardingTable_Valid, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(tempItemLow, "(%u)", i);
tempItemLow = proto_tree_add_item(RandomForwardingTable_header_tree, hf_infiniband_RandomForwardingTable_LMC, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_item_append_text(tempItemLow, "(%u)", i);
tempItemLow = proto_tree_add_item(RandomForwardingTable_header_tree, hf_infiniband_RandomForwardingTable_Port, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_item_append_text(tempItemLow, "(%u)", i);
}
}
static void parse_MulticastForwardingTable(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint i;
gint local_offset = *offset;
proto_item *MulticastForwardingTable_header_item;
proto_tree *MulticastForwardingTable_header_tree;
proto_item *tempItemLow;
if (!parentTree)
return;
MulticastForwardingTable_header_item = proto_tree_add_item(parentTree, hf_infiniband_smp_data, tvb, local_offset, 64, ENC_NA);
proto_item_set_text(MulticastForwardingTable_header_item, "%s", "MulticastForwardingTable");
MulticastForwardingTable_header_tree = proto_item_add_subtree(MulticastForwardingTable_header_item, ett_multicastforwardingtable);
for (i = 0; i < 16; i++)
{
tempItemLow = proto_tree_add_item(MulticastForwardingTable_header_tree, hf_infiniband_MulticastForwardingTable_PortMask, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_item_append_text(tempItemLow, "(%u)", i);
}
}
static int parse_SMInfo(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint local_offset = *offset;
proto_item *SMInfo_header_item;
proto_tree *SMInfo_header_tree;
if (!parentTree)
return *offset;
SMInfo_header_item = proto_tree_add_item(parentTree, hf_infiniband_smp_data, tvb, local_offset, 64, ENC_NA);
proto_item_set_text(SMInfo_header_item, "%s", "SMInfo");
SMInfo_header_tree = proto_item_add_subtree(SMInfo_header_item, ett_sminfo);
proto_tree_add_item(SMInfo_header_tree, hf_infiniband_SMInfo_GUID, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(SMInfo_header_tree, hf_infiniband_SMInfo_SM_Key, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(SMInfo_header_tree, hf_infiniband_SMInfo_ActCount, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(SMInfo_header_tree, hf_infiniband_SMInfo_Priority, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(SMInfo_header_tree, hf_infiniband_SMInfo_SMState, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
return local_offset;
}
static int parse_VendorDiag(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint local_offset = *offset;
proto_item *VendorDiag_header_item;
proto_tree *VendorDiag_header_tree;
if (!parentTree)
return *offset;
VendorDiag_header_item = proto_tree_add_item(parentTree, hf_infiniband_smp_data, tvb, local_offset, 64, ENC_NA);
proto_item_set_text(VendorDiag_header_item, "%s", "VendorDiag");
VendorDiag_header_tree = proto_item_add_subtree(VendorDiag_header_item, ett_vendordiag);
proto_tree_add_item(VendorDiag_header_tree, hf_infiniband_VendorDiag_NextIndex, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(VendorDiag_header_tree, hf_infiniband_VendorDiag_DiagData, tvb, local_offset, 62, ENC_NA); local_offset += 62;
return local_offset;
}
static void parse_LedInfo(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint local_offset = *offset;
proto_item *LedInfo_header_item;
proto_tree *LedInfo_header_tree;
if (!parentTree)
return;
LedInfo_header_item = proto_tree_add_item(parentTree, hf_infiniband_smp_data, tvb, local_offset, 64, ENC_NA);
proto_item_set_text(LedInfo_header_item, "%s", "LedInfo");
LedInfo_header_tree = proto_item_add_subtree(LedInfo_header_item, ett_ledinfo);
proto_tree_add_item(LedInfo_header_tree, hf_infiniband_LedInfo_LedMask, tvb, local_offset, 1, ENC_BIG_ENDIAN);
}
static int parse_LinkSpeedWidthPairsTable(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint local_offset = *offset;
proto_item *LinkSpeedWidthPairsTable_header_item;
proto_tree *LinkSpeedWidthPairsTable_header_tree;
if (!parentTree)
return *offset;
LinkSpeedWidthPairsTable_header_item = proto_tree_add_item(parentTree, hf_infiniband_smp_data, tvb, local_offset, 64, ENC_NA);
proto_item_set_text(LinkSpeedWidthPairsTable_header_item, "%s", "LinkSpeedWidthPairsTable");
LinkSpeedWidthPairsTable_header_tree = proto_item_add_subtree(LinkSpeedWidthPairsTable_header_item, ett_linkspeedwidthpairs);
proto_tree_add_item(LinkSpeedWidthPairsTable_header_tree, hf_infiniband_LinkSpeedWidthPairsTable_NumTables, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(LinkSpeedWidthPairsTable_header_tree, hf_infiniband_LinkSpeedWidthPairsTable_PortMask, tvb, local_offset, 32, ENC_NA); local_offset += 32;
proto_tree_add_item(LinkSpeedWidthPairsTable_header_tree, hf_infiniband_LinkSpeedWidthPairsTable_SpeedTwoFive, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(LinkSpeedWidthPairsTable_header_tree, hf_infiniband_LinkSpeedWidthPairsTable_SpeedFive, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(LinkSpeedWidthPairsTable_header_tree, hf_infiniband_LinkSpeedWidthPairsTable_SpeedTen, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
return local_offset;
}
static void parse_RID(proto_tree* SA_header_tree, tvbuff_t* tvb, gint *offset, MAD_Data* MadHeader)
{
gint local_offset = *offset;
if (!SA_header_tree)
{
return;
}
switch (MadHeader->attributeID)
{
case 0x0011:
proto_tree_add_item(SA_header_tree, hf_infiniband_SA_LID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
local_offset += 2;
break;
case 0x0012:
proto_tree_add_item(SA_header_tree, hf_infiniband_SA_EndportLID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(SA_header_tree, hf_infiniband_SA_PortNum, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
local_offset += 1;
break;
case 0x0013:
proto_tree_add_item(SA_header_tree, hf_infiniband_SA_LID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(SA_header_tree, hf_infiniband_SA_InputPortNum, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(SA_header_tree, hf_infiniband_SA_OutputPortNum, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
local_offset += 4;
break;
case 0x0014:
proto_tree_add_item(SA_header_tree, hf_infiniband_SA_LID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
local_offset += 2;
break;
case 0x0015:
proto_tree_add_item(SA_header_tree, hf_infiniband_SA_LID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(SA_header_tree, hf_infiniband_SA_BlockNum_SixteenBit, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
local_offset += 4;
break;
case 0x0016:
proto_tree_add_item(SA_header_tree, hf_infiniband_SA_LID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(SA_header_tree, hf_infiniband_SA_BlockNum_SixteenBit, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
local_offset += 4;
break;
case 0x0017:
proto_tree_add_item(SA_header_tree, hf_infiniband_SA_LID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(SA_header_tree, hf_infiniband_SA_Position, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(SA_header_tree, hf_infiniband_SA_BlockNum_NineBit, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
local_offset += 4;
break;
case 0x0036:
proto_tree_add_item(SA_header_tree, hf_infiniband_SA_LID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(SA_header_tree, hf_infiniband_SA_OutputPortNum, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(SA_header_tree, hf_infiniband_SA_BlockNum_EightBit, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
local_offset += 4;
break;
case 0x0018:
proto_tree_add_item(SA_header_tree, hf_infiniband_SA_LID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
local_offset += 2;
break;
case 0x0033:
proto_tree_add_item(SA_header_tree, hf_infiniband_SA_LID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(SA_header_tree, hf_infiniband_SA_BlockNum_SixteenBit, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(SA_header_tree, hf_infiniband_SA_PortNum, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
local_offset += 3;
break;
case 0x00F3:
proto_tree_add_item(SA_header_tree, hf_infiniband_InformInfoRecord_SubscriberGID, tvb, local_offset, 16, ENC_NA); local_offset += 16;
proto_tree_add_item(SA_header_tree, hf_infiniband_InformInfoRecord_Enum, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
local_offset += 6;
break;
case 0x0020:
proto_tree_add_item(SA_header_tree, hf_infiniband_LinkRecord_FromLID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(SA_header_tree, hf_infiniband_LinkRecord_FromPort, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
break;
case 0x0031:
proto_tree_add_item(SA_header_tree, hf_infiniband_ServiceRecord_ServiceID, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(SA_header_tree, hf_infiniband_ServiceRecord_ServiceGID, tvb, local_offset, 16, ENC_NA); local_offset += 16;
proto_tree_add_item(SA_header_tree, hf_infiniband_ServiceRecord_ServiceP_Key, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
local_offset += 2;
break;
case 0x0038:
proto_tree_add_item(SA_header_tree, hf_infiniband_MCMemberRecord_MGID, tvb, local_offset, 16, ENC_NA); local_offset += 16;
proto_tree_add_item(SA_header_tree, hf_infiniband_MCMemberRecord_PortGID, tvb, local_offset, 16, ENC_NA); local_offset += 16;
break;
case 0x0030:
proto_tree_add_item(SA_header_tree, hf_infiniband_SA_LID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(SA_header_tree, hf_infiniband_SA_BlockNum_EightBit, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 2;
local_offset += 4;
break;
default:
break;
}
*offset = local_offset;
}
static int parse_InformInfo(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint local_offset = *offset;
proto_item *InformInfo_header_item;
proto_tree *InformInfo_header_tree;
if (!parentTree)
{
return *offset;
}
InformInfo_header_item = proto_tree_add_item(parentTree, hf_infiniband_SA, tvb, local_offset, 36, ENC_NA);
proto_item_set_text(InformInfo_header_item, "%s", "InformInfo");
InformInfo_header_tree = proto_item_add_subtree(InformInfo_header_item, ett_informinfo);
proto_tree_add_item(InformInfo_header_tree, hf_infiniband_InformInfo_GID, tvb, local_offset, 16, ENC_NA); local_offset += 16;
proto_tree_add_item(InformInfo_header_tree, hf_infiniband_InformInfo_LIDRangeBegin, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(InformInfo_header_tree, hf_infiniband_InformInfo_LIDRangeEnd, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
local_offset += 2;
proto_tree_add_item(InformInfo_header_tree, hf_infiniband_InformInfo_IsGeneric, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(InformInfo_header_tree, hf_infiniband_InformInfo_Subscribe, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(InformInfo_header_tree, hf_infiniband_InformInfo_Type, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(InformInfo_header_tree, hf_infiniband_InformInfo_TrapNumberDeviceID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(InformInfo_header_tree, hf_infiniband_InformInfo_QPN, tvb, local_offset, 3, ENC_BIG_ENDIAN); local_offset += 3;
proto_tree_add_item(InformInfo_header_tree, hf_infiniband_InformInfo_RespTimeValue, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
local_offset += 1;
proto_tree_add_item(InformInfo_header_tree, hf_infiniband_InformInfo_ProducerTypeVendorID, tvb, local_offset, 3, ENC_BIG_ENDIAN); local_offset += 3;
return local_offset;
}
static int parse_LinkRecord(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint local_offset = *offset;
proto_item *LinkRecord_header_item;
proto_tree *LinkRecord_header_tree;
if (!parentTree)
{
return *offset;
}
LinkRecord_header_item = proto_tree_add_item(parentTree, hf_infiniband_SA, tvb, local_offset, 3, ENC_NA);
proto_item_set_text(LinkRecord_header_item, "%s", "LinkRecord");
LinkRecord_header_tree = proto_item_add_subtree(LinkRecord_header_item, ett_linkrecord);
proto_tree_add_item(LinkRecord_header_tree, hf_infiniband_LinkRecord_ToPort, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(LinkRecord_header_tree, hf_infiniband_LinkRecord_ToLID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
return local_offset;
}
static int parse_ServiceRecord(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint local_offset = *offset;
proto_item *ServiceRecord_header_item;
proto_tree *ServiceRecord_header_tree;
proto_item *tempData;
if (!parentTree)
{
return *offset;
}
ServiceRecord_header_item = proto_tree_add_item(parentTree, hf_infiniband_SA, tvb, local_offset, 176, ENC_NA);
proto_item_set_text(ServiceRecord_header_item, "%s", "ServiceRecord");
ServiceRecord_header_tree = proto_item_add_subtree(ServiceRecord_header_item, ett_servicerecord);
proto_tree_add_item(ServiceRecord_header_tree, hf_infiniband_ServiceRecord_ServiceLease, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(ServiceRecord_header_tree, hf_infiniband_ServiceRecord_ServiceKey, tvb, local_offset, 16, ENC_NA); local_offset += 16;
proto_tree_add_item(ServiceRecord_header_tree, hf_infiniband_ServiceRecord_ServiceName, tvb, local_offset, 64, ENC_NA); local_offset += 64;
tempData = proto_tree_add_item(ServiceRecord_header_tree, hf_infiniband_ServiceRecord_ServiceData, tvb, local_offset, 16, ENC_NA); local_offset += 16;
proto_item_append_text(tempData, "%s", "(ServiceData 8.1, 8.16)");
tempData = proto_tree_add_item(ServiceRecord_header_tree, hf_infiniband_ServiceRecord_ServiceData, tvb, local_offset, 16, ENC_NA); local_offset += 16;
proto_item_append_text(tempData, "%s", "(ServiceData 16.1, 16.8)");
tempData = proto_tree_add_item(ServiceRecord_header_tree, hf_infiniband_ServiceRecord_ServiceData, tvb, local_offset, 16, ENC_NA); local_offset += 16;
proto_item_append_text(tempData, "%s", "(ServiceData 32.1, 32.4)");
tempData = proto_tree_add_item(ServiceRecord_header_tree, hf_infiniband_ServiceRecord_ServiceData, tvb, local_offset, 16, ENC_NA); local_offset += 16;
proto_item_append_text(tempData, "%s", "(ServiceData 64.1, 64.2)");
return local_offset;
}
static int parse_PathRecord(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint local_offset = *offset;
proto_item *PathRecord_header_item;
proto_tree *PathRecord_header_tree;
if (!parentTree)
{
return *offset;
}
PathRecord_header_item = proto_tree_add_item(parentTree, hf_infiniband_SA, tvb, local_offset, 64, ENC_NA);
proto_item_set_text(PathRecord_header_item, "%s", "PathRecord");
PathRecord_header_tree = proto_item_add_subtree(PathRecord_header_item, ett_pathrecord);
local_offset += 8;
proto_tree_add_item(PathRecord_header_tree, hf_infiniband_PathRecord_DGID, tvb, local_offset, 16, ENC_NA); local_offset += 16;
proto_tree_add_item(PathRecord_header_tree, hf_infiniband_PathRecord_SGID, tvb, local_offset, 16, ENC_NA); local_offset += 16;
proto_tree_add_item(PathRecord_header_tree, hf_infiniband_PathRecord_DLID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(PathRecord_header_tree, hf_infiniband_PathRecord_SLID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(PathRecord_header_tree, hf_infiniband_PathRecord_RawTraffic, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(PathRecord_header_tree, hf_infiniband_PathRecord_FlowLabel, tvb, local_offset, 3, ENC_BIG_ENDIAN); local_offset += 3;
proto_tree_add_item(PathRecord_header_tree, hf_infiniband_PathRecord_HopLimit, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(PathRecord_header_tree, hf_infiniband_PathRecord_TClass, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(PathRecord_header_tree, hf_infiniband_PathRecord_Reversible, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(PathRecord_header_tree, hf_infiniband_PathRecord_NumbPath, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(PathRecord_header_tree, hf_infiniband_PathRecord_P_Key, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(PathRecord_header_tree, hf_infiniband_PathRecord_SL, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(PathRecord_header_tree, hf_infiniband_PathRecord_MTUSelector, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(PathRecord_header_tree, hf_infiniband_PathRecord_MTU, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(PathRecord_header_tree, hf_infiniband_PathRecord_RateSelector, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(PathRecord_header_tree, hf_infiniband_PathRecord_Rate, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(PathRecord_header_tree, hf_infiniband_PathRecord_PacketLifeTimeSelector, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(PathRecord_header_tree, hf_infiniband_PathRecord_PacketLifeTime, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(PathRecord_header_tree, hf_infiniband_PathRecord_Preference, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
return local_offset;
}
static int parse_MCMemberRecord(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint local_offset = *offset;
proto_item *MCMemberRecord_header_item;
proto_tree *MCMemberRecord_header_tree;
if (!parentTree)
{
return *offset;
}
MCMemberRecord_header_item = proto_tree_add_item(parentTree, hf_infiniband_SA, tvb, local_offset, 64, ENC_NA);
proto_item_set_text(MCMemberRecord_header_item, "%s", "MCMemberRecord");
MCMemberRecord_header_tree = proto_item_add_subtree(MCMemberRecord_header_item, ett_mcmemberrecord);
proto_tree_add_item(MCMemberRecord_header_tree, hf_infiniband_MCMemberRecord_Q_Key, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(MCMemberRecord_header_tree, hf_infiniband_MCMemberRecord_MLID, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(MCMemberRecord_header_tree, hf_infiniband_MCMemberRecord_MTUSelector, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(MCMemberRecord_header_tree, hf_infiniband_MCMemberRecord_MTU, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(MCMemberRecord_header_tree, hf_infiniband_MCMemberRecord_TClass, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(MCMemberRecord_header_tree, hf_infiniband_MCMemberRecord_P_Key, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(MCMemberRecord_header_tree, hf_infiniband_MCMemberRecord_RateSelector, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(MCMemberRecord_header_tree, hf_infiniband_MCMemberRecord_Rate, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(MCMemberRecord_header_tree, hf_infiniband_MCMemberRecord_PacketLifeTimeSelector, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(MCMemberRecord_header_tree, hf_infiniband_MCMemberRecord_PacketLifeTime, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(MCMemberRecord_header_tree, hf_infiniband_MCMemberRecord_SL, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(MCMemberRecord_header_tree, hf_infiniband_MCMemberRecord_FlowLabel, tvb, local_offset, 3, ENC_BIG_ENDIAN); local_offset += 3;
proto_tree_add_item(MCMemberRecord_header_tree, hf_infiniband_MCMemberRecord_HopLimit, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(MCMemberRecord_header_tree, hf_infiniband_MCMemberRecord_Scope, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(MCMemberRecord_header_tree, hf_infiniband_MCMemberRecord_JoinState, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(MCMemberRecord_header_tree, hf_infiniband_MCMemberRecord_ProxyJoin, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 3;
return local_offset;
}
static int parse_TraceRecord(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint local_offset = *offset;
proto_item *TraceRecord_header_item;
proto_tree *TraceRecord_header_tree;
if (!parentTree)
{
return *offset;
}
TraceRecord_header_item = proto_tree_add_item(parentTree, hf_infiniband_SA, tvb, local_offset, 46, ENC_NA);
proto_item_set_text(TraceRecord_header_item, "%s", "TraceRecord");
TraceRecord_header_tree = proto_item_add_subtree(TraceRecord_header_item, ett_tracerecord);
proto_tree_add_item(TraceRecord_header_tree, hf_infiniband_TraceRecord_GIDPrefix, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(TraceRecord_header_tree, hf_infiniband_TraceRecord_IDGeneration, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
local_offset += 1;
proto_tree_add_item(TraceRecord_header_tree, hf_infiniband_TraceRecord_NodeType, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(TraceRecord_header_tree, hf_infiniband_TraceRecord_NodeID, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(TraceRecord_header_tree, hf_infiniband_TraceRecord_ChassisID, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(TraceRecord_header_tree, hf_infiniband_TraceRecord_EntryPortID, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(TraceRecord_header_tree, hf_infiniband_TraceRecord_ExitPortID, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(TraceRecord_header_tree, hf_infiniband_TraceRecord_EntryPort, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(TraceRecord_header_tree, hf_infiniband_TraceRecord_ExitPort, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
return local_offset;
}
static int parse_MultiPathRecord(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint local_offset = *offset;
proto_item *MultiPathRecord_header_item;
proto_tree *MultiPathRecord_header_tree;
proto_item *SDGID;
guint8 SDGIDCount;
guint8 DGIDCount;
guint32 i;
if (!parentTree)
{
return *offset;
}
MultiPathRecord_header_item = proto_tree_add_item(parentTree, hf_infiniband_SA, tvb, local_offset, 200, ENC_NA);
proto_item_set_text(MultiPathRecord_header_item, "%s", "MultiPathRecord");
MultiPathRecord_header_tree = proto_item_add_subtree(MultiPathRecord_header_item, ett_multipathrecord);
proto_tree_add_item(MultiPathRecord_header_tree, hf_infiniband_MultiPathRecord_RawTraffic, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(MultiPathRecord_header_tree, hf_infiniband_MultiPathRecord_FlowLabel, tvb, local_offset, 3, ENC_BIG_ENDIAN); local_offset += 3;
proto_tree_add_item(MultiPathRecord_header_tree, hf_infiniband_MultiPathRecord_HopLimit, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(MultiPathRecord_header_tree, hf_infiniband_MultiPathRecord_TClass, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(MultiPathRecord_header_tree, hf_infiniband_MultiPathRecord_Reversible, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(MultiPathRecord_header_tree, hf_infiniband_MultiPathRecord_NumbPath, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(MultiPathRecord_header_tree, hf_infiniband_MultiPathRecord_P_Key, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(MultiPathRecord_header_tree, hf_infiniband_MultiPathRecord_SL, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(MultiPathRecord_header_tree, hf_infiniband_MultiPathRecord_MTUSelector, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(MultiPathRecord_header_tree, hf_infiniband_MultiPathRecord_MTU, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(MultiPathRecord_header_tree, hf_infiniband_MultiPathRecord_RateSelector, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(MultiPathRecord_header_tree, hf_infiniband_MultiPathRecord_Rate, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(MultiPathRecord_header_tree, hf_infiniband_MultiPathRecord_PacketLifeTimeSelector, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(MultiPathRecord_header_tree, hf_infiniband_MultiPathRecord_PacketLifeTime, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
local_offset += 1;
proto_tree_add_item(MultiPathRecord_header_tree, hf_infiniband_MultiPathRecord_IndependenceSelector, tvb, local_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(MultiPathRecord_header_tree, hf_infiniband_MultiPathRecord_GIDScope, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
SDGIDCount = tvb_get_guint8(tvb, local_offset);
proto_tree_add_item(MultiPathRecord_header_tree, hf_infiniband_MultiPathRecord_SGIDCount, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
DGIDCount = tvb_get_guint8(tvb, local_offset);
proto_tree_add_item(MultiPathRecord_header_tree, hf_infiniband_MultiPathRecord_DGIDCount, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
local_offset += 7;
for (i = 0; i < SDGIDCount; i++)
{
SDGID = proto_tree_add_item(MultiPathRecord_header_tree, hf_infiniband_MultiPathRecord_SDGID, tvb, local_offset, 16, ENC_NA); local_offset += 16;
proto_item_set_text(SDGID, "(%s%u)", "SGID", i);
}
for (i = 0; i < DGIDCount; i++)
{
SDGID = proto_tree_add_item(MultiPathRecord_header_tree, hf_infiniband_MultiPathRecord_SDGID, tvb, local_offset, 16, ENC_NA); local_offset += 16;
proto_item_set_text(SDGID, "(%s%u)", "DGID", i);
}
return local_offset;
}
static int parse_ServiceAssociationRecord(proto_tree* parentTree, tvbuff_t* tvb, gint *offset)
{
gint local_offset = *offset;
proto_item *ServiceAssociationRecord_header_item;
proto_tree *ServiceAssociationRecord_header_tree;
if (!parentTree)
{
return *offset;
}
ServiceAssociationRecord_header_item = proto_tree_add_item(parentTree, hf_infiniband_SA, tvb, local_offset, 80, ENC_NA);
proto_item_set_text(ServiceAssociationRecord_header_item, "%s", "ServiceAssociationRecord");
ServiceAssociationRecord_header_tree = proto_item_add_subtree(ServiceAssociationRecord_header_item, ett_serviceassocrecord);
proto_tree_add_item(ServiceAssociationRecord_header_tree, hf_infiniband_ServiceAssociationRecord_ServiceKey, tvb, local_offset, 16, ENC_NA); local_offset += 16;
proto_tree_add_item(ServiceAssociationRecord_header_tree, hf_infiniband_ServiceAssociationRecord_ServiceName, tvb, local_offset, 64, ENC_ASCII|ENC_NA); local_offset += 64;
return local_offset;
}
static int parse_PERF_PortCounters(proto_tree* parentTree, tvbuff_t* tvb, packet_info *pinfo, gint *offset)
{
proto_item *perf_item;
proto_tree *perf_tree;
gint local_offset = *offset;
col_set_str(pinfo->cinfo, COL_INFO, "PERF (PortCounters)");
perf_item = proto_tree_add_item(parentTree, hf_infiniband_PortCounters, tvb, local_offset, 40, ENC_NA);
perf_tree = proto_item_add_subtree(perf_item, ett_perfclass);
local_offset += 40;
local_offset += 1;
proto_tree_add_item(perf_tree, hf_infiniband_PortCounters_PortSelect, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(perf_tree, hf_infiniband_PortCounters_CounterSelect, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(perf_tree, hf_infiniband_PortCounters_SymbolErrorCounter, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(perf_tree, hf_infiniband_PortCounters_LinkErrorRecoveryCounter, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(perf_tree, hf_infiniband_PortCounters_LinkDownedCounter, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(perf_tree, hf_infiniband_PortCounters_PortRcvErrors, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(perf_tree, hf_infiniband_PortCounters_PortRcvRemotePhysicalErrors, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(perf_tree, hf_infiniband_PortCounters_PortRcvSwitchRelayErrors, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(perf_tree, hf_infiniband_PortCounters_PortXmitDiscards, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(perf_tree, hf_infiniband_PortCounters_PortXmitConstraintErrors, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(perf_tree, hf_infiniband_PortCounters_PortRcvConstraintErrors, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
local_offset += 1;
proto_tree_add_bits_item(perf_tree, hf_infiniband_PortCounters_LocalLinkIntegrityErrors, tvb, local_offset*8, 4, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(perf_tree, hf_infiniband_PortCounters_ExcessiveBufferOverrunErrors, tvb, local_offset*8 + 4, 4, ENC_BIG_ENDIAN); local_offset += 1;
local_offset += 2;
proto_tree_add_item(perf_tree, hf_infiniband_PortCounters_VL15Dropped, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
proto_tree_add_item(perf_tree, hf_infiniband_PortCounters_PortXmitData, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(perf_tree, hf_infiniband_PortCounters_PortRcvData, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(perf_tree, hf_infiniband_PortCounters_PortXmitPkts, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
proto_tree_add_item(perf_tree, hf_infiniband_PortCounters_PortRcvPkts, tvb, local_offset, 4, ENC_BIG_ENDIAN); local_offset += 4;
*offset = local_offset;
return local_offset;
}
static int parse_PERF_PortCountersExtended(proto_tree* parentTree, tvbuff_t* tvb, packet_info *pinfo, gint *offset)
{
proto_item *perf_item;
proto_tree *perf_tree;
gint local_offset = *offset;
col_set_str(pinfo->cinfo, COL_INFO, "PERF (PortCountersExtended)");
perf_item = proto_tree_add_item(parentTree, hf_infiniband_PortCountersExt, tvb, local_offset, 72, ENC_NA);
perf_tree = proto_item_add_subtree(perf_item, ett_perfclass);
local_offset += 40;
local_offset += 1;
proto_tree_add_item(perf_tree, hf_infiniband_PortCountersExt_PortSelect, tvb, local_offset, 1, ENC_BIG_ENDIAN); local_offset += 1;
proto_tree_add_item(perf_tree, hf_infiniband_PortCountersExt_CounterSelect, tvb, local_offset, 2, ENC_BIG_ENDIAN); local_offset += 2;
local_offset += 4;
proto_tree_add_item(perf_tree, hf_infiniband_PortCountersExt_PortXmitData, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(perf_tree, hf_infiniband_PortCountersExt_PortRcvData, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(perf_tree, hf_infiniband_PortCountersExt_PortXmitPkts, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(perf_tree, hf_infiniband_PortCountersExt_PortRcvPkts, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(perf_tree, hf_infiniband_PortCountersExt_PortUnicastXmitPkts, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(perf_tree, hf_infiniband_PortCountersExt_PortUnicastRcvPkts, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(perf_tree, hf_infiniband_PortCountersExt_PortMulticastXmitPkts, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
proto_tree_add_item(perf_tree, hf_infiniband_PortCountersExt_PortMulticastRcvPkts, tvb, local_offset, 8, ENC_BIG_ENDIAN); local_offset += 8;
*offset = local_offset;
return local_offset;
}
static void dissect_general_info(tvbuff_t *tvb, gint offset, packet_info *pinfo, gboolean starts_with_grh)
{
guint8 lnh_val = 0;
gboolean bthFollows = FALSE;
guint8 virtualLane = 0;
guint8 opCode = 0;
gint32 nextHeaderSequence = -1;
guint8 nxtHdr = 0;
struct e_in6_addr SRCgid;
struct e_in6_addr DSTgid;
guint8 management_class = 0;
MAD_Data MadData;
if (starts_with_grh) {
lnh_val = IBA_GLOBAL;
goto skip_lrh;
}
virtualLane = tvb_get_guint8(tvb, offset);
virtualLane = virtualLane & 0xF0;
offset += 1;
lnh_val = tvb_get_guint8(tvb, offset);
lnh_val = lnh_val & 0x03;
offset += 1;
*((guint16*) dst_addr) = tvb_get_ntohs(tvb, offset);
SET_ADDRESS(&pinfo->dst, AT_IB, sizeof(guint16), dst_addr);
offset += 4;
*((guint16*) src_addr) = tvb_get_ntohs(tvb, offset);
SET_ADDRESS(&pinfo->src, AT_IB, sizeof(guint16), src_addr);
offset += 2;
skip_lrh:
switch (lnh_val)
{
case IBA_GLOBAL:
offset += 6;
nxtHdr = tvb_get_guint8(tvb, offset);
offset += 2;
tvb_get_ipv6(tvb, offset, &SRCgid);
memcpy(src_addr, &SRCgid, GID_SIZE);
SET_ADDRESS(&pinfo->src, AT_IB, GID_SIZE, src_addr);
offset += 16;
tvb_get_ipv6(tvb, offset, &DSTgid);
memcpy(dst_addr, &DSTgid, GID_SIZE);
SET_ADDRESS(&pinfo->dst, AT_IB, GID_SIZE, dst_addr);
offset += 16;
if (nxtHdr != 0x1B)
{
break;
}
case IBA_LOCAL:
bthFollows = TRUE;
opCode = tvb_get_guint8(tvb, offset);
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const((guint32)opCode, OpCodeMap, "Unknown OpCode"));
offset += 12;
break;
case IP_NON_IBA:
g_snprintf(dst_addr, ADDR_MAX_LEN, "IPv6 over IB Packet");
SET_ADDRESS(&pinfo->dst, AT_STRINGZ, (int)strlen(dst_addr)+1, dst_addr);
break;
case RAW:
break;
default:
break;
}
if (bthFollows)
{
nextHeaderSequence = find_next_header_sequence((guint32) opCode);
switch (nextHeaderSequence)
{
case RDETH_DETH_PAYLD:
offset += 4;
offset += 8;
break;
case RDETH_DETH_RETH_PAYLD:
offset += 4;
offset += 8;
offset += 16;
break;
case RDETH_DETH_IMMDT_PAYLD:
offset += 4;
offset += 8;
offset += 4;
break;
case RDETH_DETH_RETH_IMMDT_PAYLD:
offset += 4;
offset += 8;
offset += 16;
offset += 4;
break;
case RDETH_DETH_RETH:
offset += 4;
offset += 8;
offset += 16;
break;
case RDETH_AETH_PAYLD:
offset += 4;
offset += 4;
break;
case RDETH_PAYLD:
offset += 4;
break;
case RDETH_AETH:
offset += 4;
offset += 4;
break;
case RDETH_AETH_ATOMICACKETH:
offset += 4;
offset += 4;
offset += 8;
break;
case RDETH_DETH_ATOMICETH:
offset += 4;
offset += 8;
offset += 28;
break;
case RDETH_DETH:
offset += 4;
offset += 8;
break;
case DETH_PAYLD:
offset += 8;
break;
case PAYLD:
break;
case IMMDT_PAYLD:
offset += 4;
break;
case RETH_PAYLD:
offset += 16;
break;
case RETH:
offset += 16;
break;
case AETH_PAYLD:
offset += 4;
break;
case AETH:
offset += 4;
break;
case AETH_ATOMICACKETH:
offset += 4;
offset += 8;
break;
case ATOMICETH:
offset += 28;
break;
case IETH_PAYLD:
offset += 4;
break;
case DETH_IMMDT_PAYLD:
offset += 8;
offset += 4;
break;
default:
break;
}
}
if (virtualLane == 0xF0)
{
management_class = tvb_get_guint8(tvb, offset + 1);
if (((management_class >= (guint8)VENDOR_1_START) && (management_class <= (guint8)VENDOR_1_END))
|| ((management_class >= (guint8)VENDOR_2_START) && (management_class <= (guint8)VENDOR_2_END)))
{
return;
}
else if ((management_class >= (guint8)APPLICATION_START) && (management_class <= (guint8)APPLICATION_END))
{
return;
}
else if (((management_class == (guint8)0x00) || (management_class == (guint8)0x02))
|| ((management_class >= (guint8)0x50) && (management_class <= (guint8)0x80))
|| ((management_class >= (guint8)0x82)))
{
return;
}
else
{
if (parse_MAD_Common(NULL, tvb, &offset, &MadData)) {
label_SUBM_Method(NULL, &MadData, pinfo);
label_SUBM_Attribute(NULL, &MadData, pinfo);
}
}
}
return;
}
static void proto_init_infiniband(void)
{
src_addr = dst_addr = NULL;
}
void proto_register_infiniband(void)
{
module_t *infiniband_module;
static const value_string mad_method_str[] = {
{ 0x01, "Get()" },
{ 0x02, "Set()" },
{ 0x81, "GetResp()" },
{ 0x03, "Send()" },
{ 0x05, "Trap()" },
{ 0x06, "Report()" },
{ 0x86, "ReportResp()" },
{ 0x07, "TrapRepress()" },
{ 0, NULL }
};
static hf_register_info hf[] = {
{ &hf_infiniband_LRH, {
"Local Route Header", "infiniband.lrh",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_virtual_lane, {
"Virtual Lane", "infiniband.lrh.vl",
FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL}
},
{ &hf_infiniband_link_version, {
"Link Version", "infiniband.lrh.lver",
FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL}
},
{ &hf_infiniband_service_level, {
"Service Level", "infiniband.lrh.sl",
FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL}
},
{ &hf_infiniband_reserved2, {
"Reserved (2 bits)", "infiniband.lrh.reserved2",
FT_UINT8, BASE_DEC, NULL, 0x0C, NULL, HFILL}
},
{ &hf_infiniband_link_next_header, {
"Link Next Header", "infiniband.lrh.lnh",
FT_UINT8, BASE_HEX, NULL, 0x03, NULL, HFILL}
},
{ &hf_infiniband_destination_local_id, {
"Destination Local ID", "infiniband.lrh.dlid",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_reserved5, {
"Reserved (5 bits)", "infiniband.lrh.reserved5",
FT_UINT16, BASE_DEC, NULL, 0xF800, NULL, HFILL}
},
{ &hf_infiniband_packet_length, {
"Packet Length", "infiniband.lrh.pktlen",
FT_UINT16, BASE_DEC, NULL, 0x07FF, NULL, HFILL}
},
{ &hf_infiniband_source_local_id, {
"Source Local ID", "infiniband.lrh.slid",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_GRH, {
"Global Route Header", "infiniband.grh",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_ip_version, {
"IP Version", "infiniband.grh.ipver",
FT_UINT8, BASE_DEC, NULL, 0xF0, NULL, HFILL}
},
{ &hf_infiniband_traffic_class, {
"Traffic Class", "infiniband.grh.tclass",
FT_UINT16, BASE_DEC, NULL, 0x0FF0, NULL, HFILL}
},
{ &hf_infiniband_flow_label, {
"Flow Label", "infiniband.grh.flowlabel",
FT_UINT32, BASE_DEC, NULL, 0x000FFFFF, NULL, HFILL}
},
{ &hf_infiniband_payload_length, {
"Payload Length", "infiniband.grh.paylen",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_next_header, {
"Next Header", "infiniband.grh.nxthdr",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_hop_limit, {
"Hop Limit", "infiniband.grh.hoplmt",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_source_gid, {
"Source GID", "infiniband.grh.sgid",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_destination_gid, {
"Destination GID", "infiniband.grh.dgid",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_BTH, {
"Base Transport Header", "infiniband.bth",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_opcode, {
"Opcode", "infiniband.bth.opcode",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_solicited_event, {
"Solicited Event", "infiniband.bth.se",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL}
},
{ &hf_infiniband_migreq, {
"MigReq", "infiniband.bth.m",
FT_BOOLEAN, 8, NULL, 0x40, NULL, HFILL}
},
{ &hf_infiniband_pad_count, {
"Pad Count", "infiniband.bth.padcnt",
FT_UINT8, BASE_DEC, NULL, 0x30, NULL, HFILL}
},
{ &hf_infiniband_transport_header_version, {
"Header Version", "infiniband.bth.tver",
FT_UINT8, BASE_DEC, NULL, 0x0F, NULL, HFILL}
},
{ &hf_infiniband_partition_key, {
"Partition Key", "infiniband.bth.p_key",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_reserved8, {
"Reserved (8 bits)", "infiniband.bth.reserved8",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_destination_qp, {
"Destination Queue Pair", "infiniband.bth.destqp",
FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_acknowledge_request, {
"Acknowledge Request", "infiniband.bth.a",
FT_BOOLEAN, 8, NULL, 0x80, NULL, HFILL}
},
{ &hf_infiniband_reserved7, {
"Reserved (7 bits)", "infiniband.bth.reserved7",
FT_UINT8, BASE_DEC, NULL, 0x7F, NULL, HFILL}
},
{ &hf_infiniband_packet_sequence_number, {
"Packet Sequence Number", "infiniband.bth.psn",
FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_RWH, {
"Raw Header", "infiniband.rwh",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_reserved16_RWH, {
"Reserved (16 bits)", "infiniband.rwh.reserved",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_etype, {
"Ethertype", "infiniband.rwh.etype",
FT_UINT16, BASE_HEX, NULL , 0x0, "Type", HFILL }
},
{ &hf_infiniband_RDETH, {
"Reliable Datagram Extended Transport Header", "infiniband.rdeth",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_reserved8_RDETH, {
"Reserved (8 bits)", "infiniband.rdeth.reserved8",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_ee_context, {
"E2E Context", "infiniband.rdeth.eecnxt",
FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_DETH, {
"Datagram Extended Transport Header", "infiniband.deth",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_queue_key, {
"Queue Key", "infiniband.deth.q_key",
FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_reserved8_DETH, {
"Reserved (8 bits)", "infiniband.deth.reserved8",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_source_qp, {
"Source Queue Pair", "infiniband.deth.srcqp",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_RETH, {
"RDMA Extended Transport Header", "infiniband.reth",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_virtual_address, {
"Virtual Address", "infiniband.reth.va",
FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_remote_key, {
"Remote Key", "infiniband.reth.r_key",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_dma_length, {
"DMA Length", "infiniband.reth.dmalen",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_AtomicETH, {
"Atomic Extended Transport Header", "infiniband.atomiceth",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
#if 0
{ &hf_infiniband_virtual_address_AtomicETH, {
"Virtual Address", "infiniband.atomiceth.va",
FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_remote_key_AtomicETH, {
"Remote Key", "infiniband.atomiceth.r_key",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
#endif
{ &hf_infiniband_swap_or_add_data, {
"Swap (Or Add) Data", "infiniband.atomiceth.swapdt",
FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_compare_data, {
"Compare Data", "infiniband.atomiceth.cmpdt",
FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_AETH, {
"ACK Extended Transport Header", "infiniband.aeth",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_syndrome, {
"Syndrome", "infiniband.aeth.syndrome",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_message_sequence_number, {
"Message Sequence Number", "infiniband.aeth.msn",
FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_AtomicAckETH, {
"Atomic ACK Extended Transport Header", "infiniband.atomicacketh",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_original_remote_data, {
"Original Remote Data", "infiniband.atomicacketh.origremdt",
FT_UINT64, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_IMMDT, {
"Immediate Data", "infiniband.immdt",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_IETH, {
"RKey", "infiniband.ieth",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_payload, {
"Payload", "infiniband.payload",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_invariant_crc, {
"Invariant CRC", "infiniband.invariant.crc",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_variant_crc, {
"Variant CRC", "infiniband.variant.crc",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_raw_data, {
"Raw Data", "infiniband.rawdata",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_vendor, {
"Unknown/Vendor Specific Data", "infiniband.vendor",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_local_comm_id, {
"Local Communication ID", "infiniband.cm.req",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_service_id, {
"ServiceID", "infiniband.cm.req.serviceid",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_local_ca_guid, {
"Local CA GUID", "infiniband.cm.req.localcaguid",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_local_qkey, {
"Local Q_Key", "infiniband.cm.req.localqkey",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_local_qpn, {
"Local QPN", "infiniband.cm.req.localqpn",
FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_respo_res, {
"Responder Resources", "infiniband.cm.req.responderres",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_local_eecn, {
"Local EECN", "infiniband.cm.req.localeecn",
FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_init_depth, {
"Initiator Depth", "infiniband.cm.req.initdepth",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_remote_eecn, {
"Remote EECN", "infiniband.cm.req.remoteeecn",
FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_remote_cm_resp_to, {
"Remote CM Response Timeout", "infiniband.cm.req.remoteresptout",
FT_UINT8, BASE_HEX, NULL, 0x1f, NULL, HFILL}
},
{&hf_cm_req_transp_serv_type, {
"Transport Service Type", "infiniband.cm.req.transpsvctype",
FT_UINT8, BASE_HEX, NULL, 0x60, NULL, HFILL}
},
{&hf_cm_req_e2e_flow_ctrl, {
"End-to-End Flow Control", "infiniband.cm.req.e2eflowctrl",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL}
},
{&hf_cm_req_start_psn, {
"Starting PSN", "infiniband.cm.req.startpsn",
FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_local_cm_resp_to, {
"Local CM Response Timeout", "infiniband.cm.req.localresptout",
FT_UINT8, BASE_HEX, NULL, 0x1f, NULL, HFILL}
},
{&hf_cm_req_retry_count, {
"Retry Count", "infiniband.cm.req.retrcount",
FT_UINT8, BASE_HEX, NULL, 0xe0, NULL, HFILL}
},
{&hf_cm_req_pkey, {
"Partition Key", "infiniband.cm.req.pkey",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_path_pp_mtu, {
"Path Packet Payload MTU", "infiniband.cm.req.pppmtu",
FT_UINT8, BASE_HEX, NULL, 0xf, NULL, HFILL}
},
{&hf_cm_req_rdc_exists, {
"RDC Exists", "infiniband.cm.req.rdcexist",
FT_UINT8, BASE_HEX, NULL, 0x10, NULL, HFILL}
},
{&hf_cm_req_rnr_retry_count, {
"RNR Retry Count", "infiniband.cm.req.rnrretrcount",
FT_UINT8, BASE_HEX, NULL, 0xe0, NULL, HFILL}
},
{&hf_cm_req_max_cm_retries, {
"Max CM Retries", "infiniband.cm.req.maxcmretr",
FT_UINT8, BASE_HEX, NULL, 0xf, NULL, HFILL}
},
{&hf_cm_req_srq, {
"SRQ", "infiniband.cm.req.srq",
FT_UINT8, BASE_HEX, NULL, 0x10, NULL, HFILL}
},
{&hf_cm_req_primary_local_lid, {
"Primary Local Port LID", "infiniband.cm.req.prim_locallid",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_primary_remote_lid, {
"Primary Remote Port LID", "infiniband.cm.req.prim_remotelid",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_primary_local_gid, {
"Primary Local Port GID", "infiniband.cm.req.prim_localgid",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_primary_remote_gid, {
"Primary Remote Port GID", "infiniband.cm.req.prim_remotegid",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_primary_flow_label, {
"Primary Flow Label", "infiniband.cm.req.prim_flowlabel",
FT_UINT24, BASE_HEX, NULL, 0xfffff, NULL, HFILL}
},
{&hf_cm_req_primary_packet_rate, {
"Primary Packet Rate", "infiniband.cm.req.prim_pktrate",
FT_UINT8, BASE_HEX, NULL, 0xfc, NULL, HFILL}
},
{&hf_cm_req_primary_traffic_class, {
"Primary Traffic Class", "infiniband.cm.req.prim_tfcclass",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_primary_hop_limit, {
"Primary Hop Limit", "infiniband.cm.req.prim_hoplim",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_primary_sl, {
"Primary SL", "infiniband.cm.req.prim_sl",
FT_UINT8, BASE_HEX, NULL, 0xf, NULL, HFILL}
},
{&hf_cm_req_primary_subnet_local, {
"Primary Subnet Local", "infiniband.cm.req.prim_subnetlocal",
FT_UINT8, BASE_HEX, NULL, 0x10, NULL, HFILL}
},
{&hf_cm_req_primary_local_ack_to, {
"Primary Local ACK Timeout", "infiniband.cm.req.prim_localacktout",
FT_UINT8, BASE_HEX, NULL, 0x1f, NULL, HFILL}
},
{&hf_cm_req_alt_local_lid, {
"Alternate Local Port LID", "infiniband.cm.req.alt_locallid",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_alt_remote_lid, {
"Alternate Remote Port LID", "infiniband.cm.req.alt_remotelid",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_alt_local_gid, {
"Alternate Local Port GID", "infiniband.cm.req.alt_localgid",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_alt_remote_gid, {
"Alternate Remote Port GID", "infiniband.cm.req.alt_remotegid",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_flow_label, {
"Alternate Flow Label", "infiniband.cm.req.alt_flowlabel",
FT_UINT24, BASE_HEX, NULL, 0xfffff, NULL, HFILL}
},
{&hf_cm_req_packet_rate, {
"Alternate Packet Rate", "infiniband.cm.req.alt_pktrate",
FT_UINT8, BASE_HEX, NULL, 0xfc, NULL, HFILL}
},
{&hf_cm_req_alt_traffic_class, {
"Alternate Traffic Class", "infiniband.cm.req.alt_tfcclass",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_alt_hop_limit, {
"Alternate Hop Limit", "infiniband.cm.req.alt_hoplim",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_req_SL, {
"Alternate SL", "infiniband.cm.req.alt_sl",
FT_UINT8, BASE_HEX, NULL, 0xf, NULL, HFILL}
},
{&hf_cm_req_subnet_local, {
"Alternate Subnet Local", "infiniband.cm.req.alt_subnetlocal",
FT_UINT8, BASE_HEX, NULL, 0x10, NULL, HFILL}
},
{&hf_cm_req_local_ACK_timeout, {
"Alternate Local ACK Timeout", "infiniband.cm.req.alt_localacktout",
FT_UINT8, BASE_HEX, NULL, 0x1f, NULL, HFILL}
},
{&hf_cm_req_private_data, {
"PrivateData", "infiniband.cm.req.private",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_rep_localcommid, {
"Local Communication ID", "infiniband.cm.rep",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_rep_remotecommid, {
"Remote Communication ID", "infiniband.cm.rep.remotecommid",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_rep_localqkey, {
"Local Q_Key", "infiniband.cm.rep.localqkey",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_rep_localqpn, {
"Local QPN", "infiniband.cm.rep.localqpn",
FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_rep_localeecontnum, {
"Local EE Context Number", "infiniband.cm.rep.localeecn",
FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_rep_startingpsn, {
"Starting PSN", "infiniband.cm.rep.startpsn",
FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_rep_responderres, {
"Responder Resources", "infiniband.cm.rep.respres",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_rep_initiatordepth, {
"Initiator Depth", "infiniband.cm.rep.initdepth",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_rep_tgtackdelay, {
"Target ACK Delay", "infiniband.cm.rep.tgtackdelay",
FT_UINT8, BASE_HEX, NULL, 0x1f, NULL, HFILL}
},
{&hf_cm_rep_failoveracc, {
"Failover Accepted", "infiniband.cm.rep.failoveracc",
FT_UINT8, BASE_HEX, NULL, 0x60, NULL, HFILL}
},
{&hf_cm_rep_e2eflowctl, {
"End-To-End Flow Control", "infiniband.cm.rep.e2eflowctrl",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL}
},
{&hf_cm_rep_rnrretrycount, {
"RNR Retry Count", "infiniband.cm.rep.rnrretrcount",
FT_UINT8, BASE_HEX, NULL, 0x7, NULL, HFILL}
},
{&hf_cm_rep_srq, {
"SRQ", "infiniband.cm.rep.srq",
FT_UINT8, BASE_HEX, NULL, 0x8, NULL, HFILL}
},
{&hf_cm_rep_localcaguid, {
"Local CA GUID", "infiniband.cm.rep.localcaguid",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_rep_privatedata, {
"PrivateData", "infiniband.cm.rep.private",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_rtu_localcommid, {
"Local Communication ID", "infiniband.cm.rtu.localcommid",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_rtu_remotecommid, {
"Remote Communication ID", "infiniband.cm.rtu.remotecommid",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_rtu_privatedata, {
"PrivateData", "infiniband.cm.rtu.private",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_rej_local_commid, {
"Local Communication ID", "infiniband.cm.rej.localcommid",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_rej_remote_commid, {
"Remote Communication ID", "infiniband.cm.rej.remotecommid",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_rej_msg_rej, {
"Message REJected", "infiniband.cm.rej.msgrej",
FT_UINT8, BASE_HEX, NULL, 0x3, NULL, HFILL}
},
{&hf_cm_rej_rej_info_len, {
"Reject Info Length", "infiniband.cm.rej.rejinfolen",
FT_UINT8, BASE_HEX, NULL, 0x7f, NULL, HFILL}
},
{&hf_cm_rej_reason, {
"Reason", "infiniband.cm.rej.reason",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_rej_add_rej_info, {
"Additional Reject Information (ARI)", "infiniband.cm.rej.ari",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{&hf_cm_rej_private_data, {
"PrivateData", "infiniband.cm.rej.private",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_MAD, {
"MAD (Management Datagram) Common Header", "infiniband.mad",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_base_version, {
"Base Version", "infiniband.mad.baseversion",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_mgmt_class, {
"Management Class", "infiniband.mad.mgmtclass",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_class_version, {
"Class Version", "infiniband.mad.classversion",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
#if 0
{ &hf_infiniband_reserved1, {
"Reserved", "infiniband.mad.reserved1",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL}
},
#endif
{ &hf_infiniband_method, {
"Method", "infiniband.mad.method",
FT_UINT8, BASE_HEX, VALS(mad_method_str), 0x0, NULL, HFILL}
},
{ &hf_infiniband_status, {
"Status", "infiniband.mad.status",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_class_specific, {
"Class Specific", "infiniband.mad.classspecific",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_transaction_id, {
"Transaction ID", "infiniband.mad.transactionid",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_attribute_id, {
"Attribute ID", "infiniband.mad.attributeid",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_reserved16, {
"Reserved", "infiniband.mad.reserved16",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_attribute_modifier, {
"Attribute Modifier", "infiniband.mad.attributemodifier",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_data, {
"MAD Data Payload", "infiniband.mad.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_RMPP, {
"RMPP (Reliable Multi-Packet Transaction Protocol)", "infiniband.rmpp",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_rmpp_version, {
"RMPP Type", "infiniband.rmpp.rmppversion",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_rmpp_type, {
"RMPP Type", "infiniband.rmpp.rmpptype",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_r_resp_time, {
"R Resp Time", "infiniband.rmpp.rresptime",
FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL}
},
{ &hf_infiniband_rmpp_flags, {
"RMPP Flags", "infiniband.rmpp.rmppflags",
FT_UINT8, BASE_HEX, VALS(RMPP_Flags), 0x0F, NULL, HFILL}
},
{ &hf_infiniband_rmpp_status, {
"RMPP Status", "infiniband.rmpp.rmppstatus",
FT_UINT8, BASE_HEX, VALS(RMPP_Status), 0x0, NULL, HFILL}
},
{ &hf_infiniband_rmpp_data1, {
"RMPP Data 1", "infiniband.rmpp.data1",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_rmpp_data2, {
"RMPP Data 2", "infiniband.rmpp.data2",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
#if 0
{ &hf_infiniband_RMPP_DATA, {
"RMPP Data (Reliable Multi-Packet Transaction Protocol)", "infiniband.rmpp.data",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
#endif
{ &hf_infiniband_segment_number, {
"Segment Number", "infiniband.rmpp.segmentnumber",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_payload_length32, {
"Payload Length", "infiniband.rmpp.payloadlength",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_transferred_data, {
"Transferred Data", "infiniband.rmpp.transferreddata",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_new_window_last, {
"New Window Last", "infiniband.rmpp.newwindowlast",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_reserved220, {
"Segment Number", "infiniband.rmpp.reserved220",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_reserved32, {
"Reserved (32 bits)", "infiniband.rmpp.reserved32",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_optional_extended_error_data, {
"Optional Extended Error Data", "infiniband.rmpp.extendederrordata",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SMP_LID, {
"Subnet Management Packet (LID Routed)", "infiniband.smplid",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_m_key, {
"M_Key", "infiniband.smplid.mkey",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_smp_data, {
"SMP Data", "infiniband.smplid.smpdata",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_reserved1024, {
"Reserved (1024 bits)", "infiniband.smplid.reserved1024",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_reserved256, {
"Reserved (256 bits)", "infiniband.smplid.reserved256",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SMP_DIRECTED, {
"Subnet Management Packet (Directed Route)", "infiniband.smpdirected",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_smp_status, {
"Status", "infiniband.smpdirected.smpstatus",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_hop_pointer, {
"Hop Pointer", "infiniband.smpdirected.hoppointer",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_hop_count, {
"Hop Count", "infiniband.smpdirected.hopcount",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_dr_slid, {
"DrSLID", "infiniband.smpdirected.drslid",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_dr_dlid, {
"DrDLID", "infiniband.smpdirected.drdlid",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_reserved28, {
"Reserved (224 bits)", "infiniband.smpdirected.reserved28",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_d, {
"D (Direction Bit)", "infiniband.smpdirected.d",
FT_UINT64, BASE_HEX, NULL, 0x8000, NULL, HFILL}
},
{ &hf_infiniband_initial_path, {
"Initial Path", "infiniband.smpdirected.initialpath",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_return_path, {
"Return Path", "infiniband.smpdirected.returnpath",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SA, {
"SA Packet (Subnet Administration)", "infiniband.sa.drdlid",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_sm_key, {
"SM_Key (Verification Key)", "infiniband.sa.smkey",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_attribute_offset, {
"Attribute Offset", "infiniband.sa.attributeoffset",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_component_mask, {
"Component Mask", "infiniband.sa.componentmask",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_subnet_admin_data, {
"Subnet Admin Data", "infiniband.sa.subnetadmindata",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_EOIB, {
"Mellanox EoIB Encapsulation Header", "infiniband.eoib",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_ver, {
"Version", "infiniband.eoib.version",
FT_UINT16, BASE_HEX, NULL, 0x3000, NULL, HFILL}
},
{ &hf_infiniband_tcp_chk, {
"TCP Checksum", "infiniband.eoib.tcp_chk",
FT_UINT16, BASE_HEX, NULL, 0x0c00, NULL, HFILL}
},
{ &hf_infiniband_ip_chk, {
"IP Checksum", "infiniband.eoib.ip_chk",
FT_UINT16, BASE_HEX, NULL, 0x0300, NULL, HFILL}
},
{ &hf_infiniband_fcs, {
"FCS Field Present", "infiniband.eoib.fcs",
FT_BOOLEAN, 16, NULL, 0x0040, NULL, HFILL}
},
{ &hf_infiniband_ms, {
"More Segments to Follow", "infiniband.eoib.ms",
FT_BOOLEAN, 16, NULL, 0x0020, NULL, HFILL}
},
{ &hf_infiniband_seg_off, {
"Segment Offset", "infiniband.eoib.ip_seg_offset",
FT_UINT16, BASE_DEC, NULL, 0x001f, NULL, HFILL}
},
{ &hf_infiniband_seg_id, {
"Segment ID", "infiniband.eoib.ip_seg_id",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_NodeDescription_NodeString, {
"NodeString", "infiniband.nodedescription.nodestring",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_NodeInfo_BaseVersion, {
"BaseVersion", "infiniband.nodeinfo.baseversion",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_NodeInfo_ClassVersion, {
"ClassVersion", "infiniband.nodeinfo.classversion",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_NodeInfo_NodeType, {
"NodeType", "infiniband.nodeinfo.nodetype",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_NodeInfo_NumPorts, {
"NumPorts", "infiniband.nodeinfo.numports",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_NodeInfo_SystemImageGUID, {
"SystemImageGUID", "infiniband.nodeinfo.systemimageguid",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_NodeInfo_NodeGUID, {
"NodeGUID", "infiniband.nodeinfo.nodeguid",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_NodeInfo_PortGUID, {
"PortGUID", "infiniband.nodeinfo.portguid",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_NodeInfo_PartitionCap, {
"PartitionCap", "infiniband.nodeinfo.partitioncap",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_NodeInfo_DeviceID, {
"DeviceID", "infiniband.nodeinfo.deviceid",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_NodeInfo_Revision, {
"Revision", "infiniband.nodeinfo.revision",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_NodeInfo_LocalPortNum, {
"LocalPortNum", "infiniband.nodeinfo.localportnum",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_NodeInfo_VendorID, {
"VendorID", "infiniband.nodeinfo.vendorid",
FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SwitchInfo_LinearFDBCap, {
"LinearFDBCap", "infiniband.switchinfo.linearfdbcap",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SwitchInfo_RandomFDBCap, {
"RandomFDBCap", "infiniband.switchinfo.randomfdbcap",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SwitchInfo_MulticastFDBCap, {
"MulticastFDBCap", "infiniband.switchinfo.multicastfdbcap",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SwitchInfo_LinearFDBTop, {
"LinearFDBTop", "infiniband.switchinfo.linearfdbtop",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SwitchInfo_DefaultPort, {
"DefaultPort", "infiniband.switchinfo.defaultport",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SwitchInfo_DefaultMulticastPrimaryPort, {
"DefaultMulticastPrimaryPort", "infiniband.switchinfo.defaultmulticastprimaryport",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SwitchInfo_DefaultMulticastNotPrimaryPort, {
"DefaultMulticastNotPrimaryPort", "infiniband.switchinfo.defaultmulticastnotprimaryport",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SwitchInfo_LifeTimeValue, {
"LifeTimeValue", "infiniband.switchinfo.lifetimevalue",
FT_UINT8, BASE_HEX, NULL, 0xF8, NULL, HFILL}
},
{ &hf_infiniband_SwitchInfo_PortStateChange, {
"PortStateChange", "infiniband.switchinfo.portstatechange",
FT_UINT8, BASE_HEX, NULL, 0x04, NULL, HFILL}
},
{ &hf_infiniband_SwitchInfo_OptimizedSLtoVLMappingProgramming, {
"OptimizedSLtoVLMappingProgramming", "infiniband.switchinfo.optimizedsltovlmappingprogramming",
FT_UINT8, BASE_HEX, NULL, 0x03, NULL, HFILL}
},
{ &hf_infiniband_SwitchInfo_LIDsPerPort, {
"LIDsPerPort", "infiniband.switchinfo.lidsperport",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SwitchInfo_PartitionEnforcementCap, {
"PartitionEnforcementCap", "infiniband.switchinfo.partitionenforcementcap",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SwitchInfo_InboundEnforcementCap, {
"InboundEnforcementCap", "infiniband.switchinfo.inboundenforcementcap",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL}
},
{ &hf_infiniband_SwitchInfo_OutboundEnforcementCap, {
"OutboundEnforcementCap", "infiniband.switchinfo.outboundenforcementcap",
FT_UINT8, BASE_HEX, NULL, 0x40, NULL, HFILL}
},
{ &hf_infiniband_SwitchInfo_FilterRawInboundCap, {
"FilterRawInboundCap", "infiniband.switchinfo.filterrawinboundcap",
FT_UINT8, BASE_HEX, NULL, 0x20, NULL, HFILL}
},
{ &hf_infiniband_SwitchInfo_FilterRawOutboundCap, {
"FilterRawOutboundCap", "infiniband.switchinfo.filterrawoutboundcap",
FT_UINT8, BASE_HEX, NULL, 0x10, NULL, HFILL}
},
{ &hf_infiniband_SwitchInfo_EnhancedPortZero, {
"EnhancedPortZero", "infiniband.switchinfo.enhancedportzero",
FT_UINT8, BASE_HEX, NULL, 0x08, NULL, HFILL}
},
#if 0
{ &hf_infiniband_GUIDInfo_GUIDBlock, {
"GUIDBlock", "infiniband.switchinfo.guidblock",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
#endif
{ &hf_infiniband_GUIDInfo_GUID, {
"GUID", "infiniband.switchinfo.guid",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_M_Key, {
"M_Key", "infiniband.portinfo.m_key",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_GidPrefix, {
"GidPrefix", "infiniband.portinfo.guid",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_LID, {
"LID", "infiniband.portinfo.lid",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_MasterSMLID, {
"MasterSMLID", "infiniband.portinfo.mastersmlid",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask, {
"CapabilityMask", "infiniband.portinfo.capabilitymask",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_SM, {
"SM", "infiniband.portinfo.capabilitymask.issm",
FT_UINT32, BASE_HEX, NULL, 0x00000002, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_NoticeSupported, {
"NoticeSupported", "infiniband.portinfo.capabilitymask.noticesupported",
FT_UINT32, BASE_HEX, NULL, 0x00000004, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_TrapSupported, {
"TrapSupported", "infiniband.portinfo.capabilitymask.trapsupported",
FT_UINT32, BASE_HEX, NULL, 0x00000008, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_OptionalPDSupported, {
"OptionalPDSupported", "infiniband.portinfo.capabilitymask.optionalpdsupported",
FT_UINT32, BASE_HEX, NULL, 0x00000010, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_AutomaticMigrationSupported, {
"AutomaticMigrationSupported", "infiniband.portinfo.capabilitymask.automaticmigrationsupported",
FT_UINT32, BASE_HEX, NULL, 0x00000020, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_SLMappingSupported, {
"SLMappingSupported", "infiniband.portinfo.capabilitymask.slmappingsupported",
FT_UINT32, BASE_HEX, NULL, 0x00000040, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_MKeyNVRAM, {
"MKeyNVRAM", "infiniband.portinfo.capabilitymask.mkeynvram",
FT_UINT32, BASE_HEX, NULL, 0x00000080, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_PKeyNVRAM, {
"PKeyNVRAM", "infiniband.portinfo.capabilitymask.pkeynvram",
FT_UINT32, BASE_HEX, NULL, 0x00000100, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_LEDInfoSupported, {
"LEDInfoSupported", "infiniband.portinfo.capabilitymask.ledinfosupported",
FT_UINT32, BASE_HEX, NULL, 0x00000200, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_SMdisabled, {
"SMdisabled", "infiniband.portinfo.capabilitymask.smdisabled",
FT_UINT32, BASE_HEX, NULL, 0x00000400, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_SystemImageGUIDSupported, {
"SystemImageGUIDSupported", "infiniband.portinfo.capabilitymask.systemimageguidsupported",
FT_UINT32, BASE_HEX, NULL, 0x00000800, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_PKeySwitchExternalPortTrapSupported, {
"PKeySwitchExternalPortTrapSupported", "infiniband.portinfo.capabilitymask.pkeyswitchexternalporttrapsupported",
FT_UINT32, BASE_HEX, NULL, 0x00001000, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_CommunicationsManagementSupported, {
"CommunicationsManagementSupported", "infiniband.portinfo.capabilitymask.communicationsmanagementsupported",
FT_UINT32, BASE_HEX, NULL, 0x00010000, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_SNMPTunnelingSupported, {
"SNMPTunnelingSupported", "infiniband.portinfo.capabilitymask.snmptunnelingsupported",
FT_UINT32, BASE_HEX, NULL, 0x00020000, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_ReinitSupported, {
"ReinitSupported", "infiniband.portinfo.capabilitymask.reinitsupported",
FT_UINT32, BASE_HEX, NULL, 0x00040000, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_DeviceManagementSupported, {
"DeviceManagementSupported", "infiniband.portinfo.capabilitymask.devicemanagementsupported",
FT_UINT32, BASE_HEX, NULL, 0x00080000, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_VendorClassSupported, {
"VendorClassSupported", "infiniband.portinfo.capabilitymask.vendorclasssupported",
FT_UINT32, BASE_HEX, NULL, 0x00100000, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_DRNoticeSupported, {
"DRNoticeSupported", "infiniband.portinfo.capabilitymask.drnoticesupported",
FT_UINT32, BASE_HEX, NULL, 0x00200000, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_CapabilityMaskNoticeSupported, {
"CapabilityMaskNoticeSupported", "infiniband.portinfo.capabilitymask.capabilitymasknoticesupported",
FT_UINT32, BASE_HEX, NULL, 0x00400000, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_BootManagementSupported, {
"BootManagementSupported", "infiniband.portinfo.capabilitymask.bootmanagementsupported",
FT_UINT32, BASE_HEX, NULL, 0x00800000, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_LinkRoundTripLatencySupported, {
"LinkRoundTripLatencySupported", "infiniband.portinfo.capabilitymask.linkroundtriplatencysupported",
FT_UINT32, BASE_HEX, NULL, 0x01000000, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_ClientRegistrationSupported, {
"ClientRegistrationSupported", "infiniband.portinfo.capabilitymask.clientregistrationsupported",
FT_UINT32, BASE_HEX, NULL, 0x02000000, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_OtherLocalChangesNoticeSupported, {
"OtherLocalChangesNoticeSupported", "infiniband.portinfo.capabilitymask.otherlocalchangesnoticesupported",
FT_UINT32, BASE_HEX, NULL, 0x04000000, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_CapabilityMask_LinkSpeedWIdthPairsTableSupported, {
"LinkSpeedWIdthPairsTableSupported", "infiniband.portinfo.capabilitymask.linkspeedwidthpairstablesupported",
FT_UINT32, BASE_HEX, NULL, 0x08000000, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_DiagCode, {
"DiagCode", "infiniband.portinfo.diagcode",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_M_KeyLeasePeriod, {
"M_KeyLeasePeriod", "infiniband.portinfo.m_keyleaseperiod",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_LocalPortNum, {
"LocalPortNum", "infiniband.portinfo.localportnum",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_LinkWidthEnabled, {
"LinkWidthEnabled", "infiniband.portinfo.linkwidthenabled",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_LinkWidthSupported, {
"LinkWidthSupported", "infiniband.portinfo.linkwidthsupported",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_LinkWidthActive, {
"LinkWidthActive", "infiniband.portinfo.linkwidthactive",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_LinkSpeedSupported, {
"LinkSpeedSupported", "infiniband.portinfo.linkspeedsupported",
FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_PortState, {
"PortState", "infiniband.portinfo.portstate",
FT_UINT8, BASE_HEX, NULL, 0x0F, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_PortPhysicalState, {
"PortPhysicalState", "infiniband.portinfo.portphysicalstate",
FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_LinkDownDefaultState, {
"LinkDownDefaultState", "infiniband.portinfo.linkdowndefaultstate",
FT_UINT8, BASE_HEX, NULL, 0x0F, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_M_KeyProtectBits, {
"M_KeyProtectBits", "infiniband.portinfo.m_keyprotectbits",
FT_UINT8, BASE_HEX, NULL, 0xC0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_LMC, {
"LMC", "infiniband.portinfo.lmc",
FT_UINT8, BASE_HEX, NULL, 0x07, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_LinkSpeedActive, {
"LinkSpeedActive", "infiniband.portinfo.linkspeedactive",
FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_LinkSpeedEnabled, {
"LinkSpeedEnabled", "infiniband.portinfo.linkspeedenabled",
FT_UINT8, BASE_HEX, NULL, 0x0F, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_NeighborMTU, {
"NeighborMTU", "infiniband.portinfo.neighbormtu",
FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_MasterSMSL, {
"MasterSMSL", "infiniband.portinfo.mastersmsl",
FT_UINT8, BASE_HEX, NULL, 0x0F, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_VLCap, {
"VLCap", "infiniband.portinfo.vlcap",
FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_InitType, {
"InitType", "infiniband.portinfo.inittype",
FT_UINT8, BASE_HEX, NULL, 0x0F, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_VLHighLimit, {
"VLHighLimit", "infiniband.portinfo.vlhighlimit",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_VLArbitrationHighCap, {
"VLArbitrationHighCap", "infiniband.portinfo.vlarbitrationhighcap",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_VLArbitrationLowCap, {
"VLArbitrationLowCap", "infiniband.portinfo.vlarbitrationlowcap",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_InitTypeReply, {
"InitTypeReply", "infiniband.portinfo.inittypereply",
FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_MTUCap, {
"MTUCap", "infiniband.portinfo.mtucap",
FT_UINT8, BASE_HEX, NULL, 0x0F, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_VLStallCount, {
"VLStallCount", "infiniband.portinfo.vlstallcount",
FT_UINT8, BASE_HEX, NULL, 0xE0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_HOQLife, {
"HOQLife", "infiniband.portinfo.hoqlife",
FT_UINT8, BASE_HEX, NULL, 0x1F, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_OperationalVLs, {
"OperationalVLs", "infiniband.portinfo.operationalvls",
FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_PartitionEnforcementInbound, {
"PartitionEnforcementInbound", "infiniband.portinfo.partitionenforcementinbound",
FT_UINT8, BASE_HEX, NULL, 0x08, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_PartitionEnforcementOutbound, {
"PartitionEnforcementOutbound", "infiniband.portinfo.partitionenforcementoutbound",
FT_UINT8, BASE_HEX, NULL, 0x04, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_FilterRawInbound, {
"FilterRawInbound", "infiniband.portinfo.filterrawinbound",
FT_UINT8, BASE_HEX, NULL, 0x02, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_FilterRawOutbound, {
"FilterRawOutbound", "infiniband.portinfo.filterrawoutbound",
FT_UINT8, BASE_HEX, NULL, 0x01, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_M_KeyViolations, {
"M_KeyViolations", "infiniband.portinfo.m_keyviolations",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_P_KeyViolations, {
"P_KeyViolations", "infiniband.portinfo.p_keyviolations",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_Q_KeyViolations, {
"Q_KeyViolations", "infiniband.portinfo.q_keyviolations",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_GUIDCap, {
"GUIDCap", "infiniband.portinfo.guidcap",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_ClientReregister, {
"ClientReregister", "infiniband.portinfo.clientreregister",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_SubnetTimeOut, {
"SubnetTimeOut", "infiniband.portinfo.subnettimeout",
FT_UINT8, BASE_HEX, NULL, 0x1F, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_RespTimeValue, {
"RespTimeValue", "infiniband.portinfo.resptimevalue",
FT_UINT8, BASE_HEX, NULL, 0x1F, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_LocalPhyErrors, {
"LocalPhyErrors", "infiniband.portinfo.localphyerrors",
FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_OverrunErrors, {
"OverrunErrors", "infiniband.portinfo.overrunerrors",
FT_UINT8, BASE_HEX, NULL, 0x0F, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_MaxCreditHint, {
"MaxCreditHint", "infiniband.portinfo.maxcredithint",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PortInfo_LinkRoundTripLatency, {
"LinkRoundTripLatency", "infiniband.portinfo.linkroundtriplatency",
FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_P_KeyTable_P_KeyTableBlock, {
"P_KeyTableBlock", "infiniband.p_keytable.p_keytableblock",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_P_KeyTable_MembershipType, {
"MembershipType", "infiniband.p_keytable.membershiptype",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL}
},
{ &hf_infiniband_P_KeyTable_P_KeyBase, {
"P_KeyBase", "infiniband.p_keytable.p_keybase",
FT_UINT16, BASE_HEX, NULL, 0x7FFF, NULL, HFILL}
},
{ &hf_infiniband_SLtoVLMappingTable_SLtoVL_HighBits, {
"SL(x)toVL", "infiniband.sltovlmappingtable.sltovlhighbits",
FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL}
},
{ &hf_infiniband_SLtoVLMappingTable_SLtoVL_LowBits, {
"SL(x)toVL", "infiniband.sltovlmappingtable.sltovllowbits",
FT_UINT8, BASE_HEX, NULL, 0x0F, NULL, HFILL}
},
#if 0
{ &hf_infiniband_VLArbitrationTable_VLWeightPairs, {
"VLWeightPairs", "infiniband.vlarbitrationtable.vlweightpairs",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
#endif
{ &hf_infiniband_VLArbitrationTable_VL, {
"VL", "infiniband.vlarbitrationtable.vl",
FT_UINT8, BASE_HEX, NULL, 0x0F, NULL, HFILL}
},
{ &hf_infiniband_VLArbitrationTable_Weight, {
"Weight", "infiniband.vlarbitrationtable.weight",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
#if 0
{ &hf_infiniband_LinearForwardingTable_LinearForwardingTableBlock, {
"LinearForwardingTableBlock", "infiniband.linearforwardingtable.linearforwardingtableblock",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
#endif
{ &hf_infiniband_LinearForwardingTable_Port, {
"Port", "infiniband.linearforwardingtable.port",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
#if 0
{ &hf_infiniband_RandomForwardingTable_RandomForwardingTableBlock, {
"RandomForwardingTableBlock", "infiniband.randomforwardingtable.randomforwardingtableblock",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
#endif
{ &hf_infiniband_RandomForwardingTable_LID, {
"LID", "infiniband.randomforwardingtable.lid",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_RandomForwardingTable_Valid, {
"Valid", "infiniband.randomforwardingtable.valid",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL}
},
{ &hf_infiniband_RandomForwardingTable_LMC, {
"LMC", "infiniband.randomforwardingtable.lmc",
FT_UINT8, BASE_HEX, NULL, 0x70, NULL, HFILL}
},
{ &hf_infiniband_RandomForwardingTable_Port, {
"Port", "infiniband.randomforwardingtable.port",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
#if 0
{ &hf_infiniband_MulticastForwardingTable_MulticastForwardingTableBlock , {
"MulticastForwardingTableBlock", "infiniband.multicastforwardingtable.multicastforwardingtableblock",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
#endif
{ &hf_infiniband_MulticastForwardingTable_PortMask, {
"PortMask", "infiniband.multicastforwardingtable.portmask",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SMInfo_GUID, {
"GUID", "infiniband.sminfo.guid",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SMInfo_SM_Key, {
"SM_Key", "infiniband.sminfo.sm_key",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SMInfo_ActCount, {
"ActCount", "infiniband.sminfo.actcount",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SMInfo_Priority, {
"Priority", "infiniband.sminfo.priority",
FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL}
},
{ &hf_infiniband_SMInfo_SMState, {
"SMState", "infiniband.sminfo.smstate",
FT_UINT8, BASE_HEX, NULL, 0x0F, NULL, HFILL}
},
{ &hf_infiniband_VendorDiag_NextIndex, {
"NextIndex", "infiniband.vendordiag.nextindex",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_VendorDiag_DiagData, {
"DiagData", "infiniband.vendordiag.diagdata",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_LedInfo_LedMask, {
"LedMask", "infiniband.ledinfo.ledmask",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL}
},
{ &hf_infiniband_LinkSpeedWidthPairsTable_NumTables, {
"NumTables", "infiniband.linkspeedwidthpairstable.numtables",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_LinkSpeedWidthPairsTable_PortMask, {
"PortMask", "infiniband.linkspeedwidthpairstable.portmask",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_LinkSpeedWidthPairsTable_SpeedTwoFive, {
"Speed 2.5 Gbps", "infiniband.linkspeedwidthpairstable.speedtwofive",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL}
},
{ &hf_infiniband_LinkSpeedWidthPairsTable_SpeedFive, {
"Speed 5 Gbps", "infiniband.linkspeedwidthpairstable.speedfive",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL}
},
{ &hf_infiniband_LinkSpeedWidthPairsTable_SpeedTen, {
"Speed 10 Gbps", "infiniband.linkspeedwidthpairstable.speedten",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL}
},
{ &hf_infiniband_SA_LID, {
"LID", "infiniband.sa.lid",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SA_EndportLID, {
"EndportLID", "infiniband.sa.endportlid",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SA_PortNum, {
"PortNum", "infiniband.sa.portnum",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SA_InputPortNum , {
"InputPortNum", "infiniband.sa.inputportnum",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SA_OutputPortNum, {
"OutputPortNum", "infiniband.sa.outputportnum",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SA_BlockNum_EightBit, {
"BlockNum_EightBit", "infiniband.sa.blocknum_eightbit",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SA_BlockNum_NineBit, {
"BlockNum_NineBit", "infiniband.sa.blocknum_ninebit",
FT_UINT16, BASE_HEX, NULL, 0x01FF, NULL, HFILL}
},
{ &hf_infiniband_SA_BlockNum_SixteenBit, {
"BlockNum_SixteenBit", "infiniband.sa.blocknum_sixteenbit",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_SA_Position, {
"Position", "infiniband.sa.position",
FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL}
},
#if 0
{ &hf_infiniband_SA_Index, {
"Index", "infiniband.sa.index",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
#endif
{ &hf_infiniband_InformInfoRecord_SubscriberGID, {
"SubscriberGID", "infiniband.informinforecord.subscribergid",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_InformInfoRecord_Enum, {
"Enum", "infiniband.informinforecord.enum",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_InformInfo_GID, {
"GID", "infiniband.informinfo.gid",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_InformInfo_LIDRangeBegin, {
"LIDRangeBegin", "infiniband.informinfo.lidrangebegin",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_InformInfo_LIDRangeEnd, {
"LIDRangeEnd", "infiniband.informinfo.lidrangeend",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_InformInfo_IsGeneric, {
"IsGeneric", "infiniband.informinfo.isgeneric",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_InformInfo_Subscribe, {
"Subscribe", "infiniband.informinfo.subscribe",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_InformInfo_Type, {
"Type", "infiniband.informinfo.type",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_InformInfo_TrapNumberDeviceID, {
"TrapNumberDeviceID", "infiniband.informinfo.trapnumberdeviceid",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_InformInfo_QPN, {
"QPN", "infiniband.informinfo.qpn",
FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_InformInfo_RespTimeValue, {
"RespTimeValue", "infiniband.informinfo.resptimevalue",
FT_UINT8, BASE_HEX, NULL, 0x1F, NULL, HFILL}
},
{ &hf_infiniband_InformInfo_ProducerTypeVendorID, {
"ProducerTypeVendorID", "infiniband.informinfo.producertypevendorid",
FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_LinkRecord_FromLID, {
"FromLID", "infiniband.linkrecord.fromlid",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_LinkRecord_FromPort, {
"FromPort", "infiniband.linkrecord.fromport",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_LinkRecord_ToPort, {
"ToPort", "infiniband.linkrecord.toport",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_LinkRecord_ToLID, {
"ToLID", "infiniband.linkrecord.tolid",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_ServiceRecord_ServiceID, {
"ServiceID", "infiniband.linkrecord.serviceid",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_ServiceRecord_ServiceGID, {
"ServiceGID", "infiniband.linkrecord.servicegid",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_ServiceRecord_ServiceP_Key, {
"ServiceP_Key", "infiniband.linkrecord.servicep_key",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_ServiceRecord_ServiceLease, {
"ServiceLease", "infiniband.linkrecord.servicelease",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_ServiceRecord_ServiceKey, {
"ServiceKey", "infiniband.linkrecord.servicekey",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_ServiceRecord_ServiceName, {
"ServiceName", "infiniband.linkrecord.servicename",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_ServiceRecord_ServiceData, {
"ServiceData", "infiniband.linkrecord.servicedata",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_ServiceAssociationRecord_ServiceKey, {
"ServiceKey", "infiniband.serviceassociationrecord.servicekey",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_ServiceAssociationRecord_ServiceName, {
"ServiceName", "infiniband.serviceassociationrecord.servicename",
FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PathRecord_DGID, {
"DGID", "infiniband.pathrecord.dgid",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PathRecord_SGID, {
"SGID", "infiniband.pathrecord.sgid",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PathRecord_DLID, {
"DLID", "infiniband.pathrecord.dlid",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PathRecord_SLID, {
"SLID", "infiniband.pathrecord.slid",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PathRecord_RawTraffic, {
"RawTraffic", "infiniband.pathrecord.rawtraffic",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL}
},
{ &hf_infiniband_PathRecord_FlowLabel, {
"FlowLabel", "infiniband.pathrecord.flowlabel",
FT_UINT24, BASE_HEX, NULL, 0x0FFFFF, NULL, HFILL}
},
{ &hf_infiniband_PathRecord_HopLimit, {
"HopLimit", "infiniband.pathrecord.hoplimit",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PathRecord_TClass, {
"TClass", "infiniband.pathrecord.tclass",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PathRecord_Reversible, {
"Reversible", "infiniband.pathrecord.reversible",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL}
},
{ &hf_infiniband_PathRecord_NumbPath, {
"NumbPath", "infiniband.pathrecord.numbpath",
FT_UINT8, BASE_HEX, NULL, 0x7F, NULL, HFILL}
},
{ &hf_infiniband_PathRecord_P_Key, {
"P_Key", "infiniband.pathrecord.p_key",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PathRecord_SL, {
"SL", "infiniband.pathrecord.sl",
FT_UINT16, BASE_HEX, NULL, 0x000F, NULL, HFILL}
},
{ &hf_infiniband_PathRecord_MTUSelector, {
"MTUSelector", "infiniband.pathrecord.mtuselector",
FT_UINT8, BASE_HEX, NULL, 0xC0, NULL, HFILL}
},
{ &hf_infiniband_PathRecord_MTU, {
"MTU", "infiniband.pathrecord.mtu",
FT_UINT8, BASE_HEX, NULL, 0x3F, NULL, HFILL}
},
{ &hf_infiniband_PathRecord_RateSelector, {
"RateSelector", "infiniband.pathrecord.rateselector",
FT_UINT8, BASE_HEX, NULL, 0xC0, NULL, HFILL}
},
{ &hf_infiniband_PathRecord_Rate, {
"Rate", "infiniband.pathrecord.rate",
FT_UINT8, BASE_HEX, NULL, 0x3F, NULL, HFILL}
},
{ &hf_infiniband_PathRecord_PacketLifeTimeSelector, {
"PacketLifeTimeSelector", "infiniband.pathrecord.packetlifetimeselector",
FT_UINT8, BASE_HEX, NULL, 0xC0, NULL, HFILL}
},
{ &hf_infiniband_PathRecord_PacketLifeTime, {
"PacketLifeTime", "infiniband.pathrecord.packetlifetime",
FT_UINT8, BASE_HEX, NULL, 0x3F, NULL, HFILL}
},
{ &hf_infiniband_PathRecord_Preference, {
"Preference", "infiniband.pathrecord.preference",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_MCMemberRecord_MGID, {
"MGID", "infiniband.mcmemberrecord.mgid",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_MCMemberRecord_PortGID, {
"PortGID", "infiniband.mcmemberrecord.portgid",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_MCMemberRecord_Q_Key, {
"Q_Key", "infiniband.mcmemberrecord.q_key",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_MCMemberRecord_MLID, {
"MLID", "infiniband.mcmemberrecord.mlid",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_MCMemberRecord_MTUSelector, {
"MTUSelector", "infiniband.mcmemberrecord.mtuselector",
FT_UINT8, BASE_HEX, NULL, 0xC0, NULL, HFILL}
},
{ &hf_infiniband_MCMemberRecord_MTU, {
"MTU", "infiniband.mcmemberrecord.mtu",
FT_UINT8, BASE_HEX, NULL, 0x3F, NULL, HFILL}
},
{ &hf_infiniband_MCMemberRecord_TClass, {
"TClass", "infiniband.mcmemberrecord.tclass",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_MCMemberRecord_P_Key, {
"P_Key", "infiniband.mcmemberrecord.p_key",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_MCMemberRecord_RateSelector, {
"RateSelector", "infiniband.mcmemberrecord.rateselector",
FT_UINT8, BASE_HEX, NULL, 0xC0, NULL, HFILL}
},
{ &hf_infiniband_MCMemberRecord_Rate, {
"Rate", "infiniband.mcmemberrecord.rate",
FT_UINT8, BASE_HEX, NULL, 0x3F, NULL, HFILL}
},
{ &hf_infiniband_MCMemberRecord_PacketLifeTimeSelector, {
"PacketLifeTimeSelector", "infiniband.mcmemberrecord.packetlifetimeselector",
FT_UINT8, BASE_HEX, NULL, 0xC0, NULL, HFILL}
},
{ &hf_infiniband_MCMemberRecord_PacketLifeTime, {
"PacketLifeTime", "infiniband.mcmemberrecord.packetlifetime",
FT_UINT8, BASE_HEX, NULL, 0x3F, NULL, HFILL}
},
{ &hf_infiniband_MCMemberRecord_SL, {
"SL", "infiniband.mcmemberrecord.sl",
FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL}
},
{ &hf_infiniband_MCMemberRecord_FlowLabel, {
"FlowLabel", "infiniband.mcmemberrecord.flowlabel",
FT_UINT24, BASE_HEX, NULL, 0x0FFFFF, NULL, HFILL}
},
{ &hf_infiniband_MCMemberRecord_HopLimit, {
"HopLimit", "infiniband.mcmemberrecord.hoplimit",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_MCMemberRecord_Scope, {
"Scope", "infiniband.mcmemberrecord.scope",
FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL}
},
{ &hf_infiniband_MCMemberRecord_JoinState, {
"JoinState", "infiniband.mcmemberrecord.joinstate",
FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL}
},
{ &hf_infiniband_MCMemberRecord_ProxyJoin, {
"ProxyJoin", "infiniband.mcmemberrecord.proxyjoin",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL}
},
{ &hf_infiniband_TraceRecord_GIDPrefix, {
"GidPrefix", "infiniband.tracerecord.gidprefix",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_TraceRecord_IDGeneration, {
"IDGeneration", "infiniband.tracerecord.idgeneration",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_TraceRecord_NodeType, {
"NodeType", "infiniband.tracerecord.nodetype",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_TraceRecord_NodeID, {
"NodeID", "infiniband.tracerecord.nodeid",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_TraceRecord_ChassisID, {
"ChassisID", "infiniband.tracerecord.chassisid",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_TraceRecord_EntryPortID, {
"EntryPortID", "infiniband.tracerecord.entryportid",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_TraceRecord_ExitPortID, {
"ExitPortID", "infiniband.tracerecord.exitportid",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_TraceRecord_EntryPort, {
"EntryPort", "infiniband.tracerecord.entryport",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_TraceRecord_ExitPort, {
"ExitPort", "infiniband.tracerecord.exitport",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_MultiPathRecord_RawTraffic, {
"RawTraffic", "infiniband.multipathrecord.rawtraffic",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL}
},
{ &hf_infiniband_MultiPathRecord_FlowLabel, {
"FlowLabel", "infiniband.multipathrecord.flowlabel",
FT_UINT24, BASE_HEX, NULL, 0x0FFFFF, NULL, HFILL}
},
{ &hf_infiniband_MultiPathRecord_HopLimit, {
"HopLimit", "infiniband.multipathrecord.hoplimit",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_MultiPathRecord_TClass, {
"TClass", "infiniband.multipathrecord.tclass",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_MultiPathRecord_Reversible, {
"Reversible", "infiniband.multipathrecord.reversible",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL}
},
{ &hf_infiniband_MultiPathRecord_NumbPath, {
"NumbPath", "infiniband.multipathrecord.numbpath",
FT_UINT8, BASE_HEX, NULL, 0x7F, NULL, HFILL}
},
{ &hf_infiniband_MultiPathRecord_P_Key, {
"P_Key", "infiniband.multipathrecord.p_key",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_MultiPathRecord_SL, {
"SL", "infiniband.multipathrecord.sl",
FT_UINT8, BASE_HEX, NULL, 0x0F, NULL, HFILL}
},
{ &hf_infiniband_MultiPathRecord_MTUSelector, {
"MTUSelector", "infiniband.multipathrecord.mtuselector",
FT_UINT8, BASE_HEX, NULL, 0xC0, NULL, HFILL}
},
{ &hf_infiniband_MultiPathRecord_MTU, {
"MTU", "infiniband.multipathrecord.mtu",
FT_UINT8, BASE_HEX, NULL, 0x3F, NULL, HFILL}
},
{ &hf_infiniband_MultiPathRecord_RateSelector, {
"RateSelector", "infiniband.multipathrecord.rateselector",
FT_UINT8, BASE_HEX, NULL, 0xC0, NULL, HFILL}
},
{ &hf_infiniband_MultiPathRecord_Rate, {
"Rate", "infiniband.multipathrecord.rate",
FT_UINT8, BASE_HEX, NULL, 0x3F, NULL, HFILL}
},
{ &hf_infiniband_MultiPathRecord_PacketLifeTimeSelector, {
"PacketLifeTimeSelector", "infiniband.multipathrecord.packetlifetimeselector",
FT_UINT8, BASE_HEX, NULL, 0xC0, NULL, HFILL}
},
{ &hf_infiniband_MultiPathRecord_PacketLifeTime, {
"PacketLifeTime", "infiniband.multipathrecord.packetlifetime",
FT_UINT8, BASE_HEX, NULL, 0x3F, NULL, HFILL}
},
{ &hf_infiniband_MultiPathRecord_IndependenceSelector, {
"IndependenceSelector", "infiniband.multipathrecord.independenceselector",
FT_UINT8, BASE_HEX, NULL, 0xC0, NULL, HFILL}
},
{ &hf_infiniband_MultiPathRecord_GIDScope, {
"GIDScope", "infiniband.multipathrecord.gidscope",
FT_UINT8, BASE_HEX, NULL, 0x3F, NULL, HFILL}
},
{ &hf_infiniband_MultiPathRecord_SGIDCount, {
"SGIDCount", "infiniband.multipathrecord.sgidcount",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_MultiPathRecord_DGIDCount, {
"DGIDCount", "infiniband.multipathrecord.dgidcount",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_MultiPathRecord_SDGID, {
"SDGID", "infiniband.multipathrecord.sdgid",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Notice_IsGeneric, {
"IsGeneric", "infiniband.notice.isgeneric",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL}
},
{ &hf_infiniband_Notice_Type, {
"Type", "infiniband.notice.type",
FT_UINT8, BASE_HEX, NULL, 0x7F, NULL, HFILL}
},
{ &hf_infiniband_Notice_ProducerTypeVendorID, {
"ProducerTypeVendorID", "infiniband.notice.producertypevendorid",
FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Notice_TrapNumberDeviceID, {
"TrapNumberDeviceID", "infiniband.notice.trapnumberdeviceid",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Notice_IssuerLID, {
"IssuerLID", "infiniband.notice.issuerlid",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Notice_NoticeToggle, {
"NoticeToggle", "infiniband.notice.noticetoggle",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL}
},
{ &hf_infiniband_Notice_NoticeCount, {
"NoticeCount", "infiniband.notice.noticecount",
FT_UINT16, BASE_HEX, NULL, 0x7FFF, NULL, HFILL}
},
{ &hf_infiniband_Notice_DataDetails, {
"DataDetails", "infiniband.notice.datadetails",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
#if 0
{ &hf_infiniband_Notice_IssuerGID, {
"IssuerGID", "infiniband.notice.issuergid",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Notice_ClassTrapSpecificData, {
"ClassTrapSpecificData", "infiniband.notice.classtrapspecificdata",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
#endif
{ &hf_infiniband_Trap_GIDADDR, {
"GIDADDR", "infiniband.trap.gidaddr",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Trap_COMP_MASK, {
"COMP_MASK", "infiniband.trap.comp_mask",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Trap_WAIT_FOR_REPATH, {
"WAIT_FOR_REPATH", "infiniband.trap.wait_for_repath",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL}
},
#if 0
{ &hf_infiniband_Trap_PATH_REC, {
"PATH_REC", "infiniband.trap.path_rec",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
#endif
{ &hf_infiniband_Trap_LIDADDR, {
"LIDADDR", "infiniband.trap.lidaddr",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Trap_PORTNO, {
"PORTNO", "infiniband.trap.portno",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Trap_OtherLocalChanges, {
"OtherLocalChanges", "infiniband.trap.otherlocalchanges",
FT_UINT8, BASE_HEX, NULL, 0x01, NULL, HFILL}
},
{ &hf_infiniband_Trap_CAPABILITYMASK, {
"CAPABILITYMASK", "infiniband.trap.capabilitymask",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Trap_LinkSpeecEnabledChange, {
"LinkSpeecEnabledChange", "infiniband.trap.linkspeecenabledchange",
FT_UINT8, BASE_HEX, NULL, 0x04, NULL, HFILL}
},
{ &hf_infiniband_Trap_LinkWidthEnabledChange, {
"LinkWidthEnabledChange", "infiniband.trap.linkwidthenabledchange",
FT_UINT8, BASE_HEX, NULL, 0x02, NULL, HFILL}
},
{ &hf_infiniband_Trap_NodeDescriptionChange, {
"NodeDescriptionChange", "infiniband.trap.nodedescriptionchange",
FT_UINT8, BASE_HEX, NULL, 0x01, NULL, HFILL}
},
{ &hf_infiniband_Trap_SYSTEMIMAGEGUID, {
"SYSTEMIMAGEGUID", "infiniband.trap.systemimageguid",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Trap_DRSLID, {
"DRSLID", "infiniband.trap.drslid",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Trap_METHOD, {
"METHOD", "infiniband.trap.method",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Trap_ATTRIBUTEID, {
"ATTRIBUTEID", "infiniband.trap.attributeid",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Trap_ATTRIBUTEMODIFIER, {
"ATTRIBUTEMODIFIER", "infiniband.trap.attributemodifier",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Trap_MKEY, {
"MKEY", "infiniband.trap.mkey",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Trap_DRNotice, {
"DRNotice", "infiniband.trap.drnotice",
FT_UINT8, BASE_HEX, NULL, 0x80, NULL, HFILL}
},
{ &hf_infiniband_Trap_DRPathTruncated, {
"DRPathTruncated", "infiniband.trap.drpathtruncated",
FT_UINT8, BASE_HEX, NULL, 0x40, NULL, HFILL}
},
{ &hf_infiniband_Trap_DRHopCount, {
"DRHopCount", "infiniband.trap.drhopcount",
FT_UINT8, BASE_HEX, NULL, 0x3F, NULL, HFILL}
},
{ &hf_infiniband_Trap_DRNoticeReturnPath, {
"DRNoticeReturnPath", "infiniband.trap.drnoticereturnpath",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Trap_LIDADDR1, {
"LIDADDR1", "infiniband.trap.lidaddr1",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Trap_LIDADDR2, {
"LIDADDR2", "infiniband.trap.lidaddr2",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Trap_KEY, {
"KEY", "infiniband.trap.key",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Trap_SL, {
"SL", "infiniband.trap.sl",
FT_UINT8, BASE_HEX, NULL, 0xF0, NULL, HFILL}
},
{ &hf_infiniband_Trap_QP1, {
"QP1", "infiniband.trap.qp1",
FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Trap_QP2, {
"QP2", "infiniband.trap.qp2",
FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Trap_GIDADDR1, {
"GIDADDR1", "infiniband.trap.gidaddr1",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Trap_GIDADDR2, {
"GIDADDR2", "infiniband.trap.gidaddr2",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Trap_DataValid, {
"DataValid", "infiniband.trap.datavalid",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Trap_PKEY, {
"PKEY", "infiniband.trap.pkey",
FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_Trap_SWLIDADDR, {
"SWLIDADDR", "infiniband.trap.swlidaddr",
FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL}
},
{ &hf_infiniband_PortCounters, {
"Port Counters (Performance Management MAD)", "infiniband.portcounters",
FT_NONE, BASE_NONE, NULL, 0x0,
"Performance class PortCounters packet", HFILL}
},
{ &hf_infiniband_PortCounters_PortSelect, {
"PortSelect", "infiniband.portcounters.portselect",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Selects the port that will be accessed", HFILL}
},
{ &hf_infiniband_PortCounters_CounterSelect, {
"CounterSelect", "infiniband.portcounters.counterselect",
FT_UINT16, BASE_HEX, NULL, 0x0,
"When writing, selects which counters are affected by the operation", HFILL}
},
{ &hf_infiniband_PortCounters_SymbolErrorCounter, {
"SymbolErrorCounter", "infiniband.portcounters.symbolerrorcounter",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Total number of minor link errors", HFILL}
},
{ &hf_infiniband_PortCounters_LinkErrorRecoveryCounter, {
"LinkErrorRecoveryCounter", "infiniband.portcounters.linkerrorrecoverycounter",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Total number of times successfully completed link error recovery process", HFILL}
},
{ &hf_infiniband_PortCounters_LinkDownedCounter, {
"LinkDownedCounter", "infiniband.portcounters.linkdownedcounter",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Total number of times failed link error recovery process", HFILL}
},
{ &hf_infiniband_PortCounters_PortRcvErrors, {
"PortRcvErrors", "infiniband.portcounters.portrcverrors",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Total number of packets containing an error received", HFILL}
},
{ &hf_infiniband_PortCounters_PortRcvRemotePhysicalErrors, {
"PortRcvRemotePhysicalErrors", "infiniband.portcounters.portrcvremotephysicalerrors",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Total number of packets marked with EBP delimiter received", HFILL}
},
{ &hf_infiniband_PortCounters_PortRcvSwitchRelayErrors, {
"PortRcvSwitchRelayErrors", "infiniband.portcounters.portrcvswitchrelayerrors",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Total number of packets discarded because they could not be forwarded by switch relay",
HFILL}
},
{ &hf_infiniband_PortCounters_PortXmitDiscards, {
"PortXmitDiscards", "infiniband.portcounters.portxmitdiscards",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Total number of outbound packets discarded", HFILL}
},
{ &hf_infiniband_PortCounters_PortXmitConstraintErrors, {
"PortXmitConstraintErrors", "infiniband.portcounters.portxmitconstrainterrors",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Total number of packets not transmitted from the switch physical port", HFILL}
},
{ &hf_infiniband_PortCounters_PortRcvConstraintErrors, {
"PortRcvConstraintErrors", "infiniband.portcounters.portrcvconstrainterrors",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Total number of packets received on the switch physical port that are discarded", HFILL}
},
{ &hf_infiniband_PortCounters_LocalLinkIntegrityErrors, {
"LocalLinkIntegrityErrors", "infiniband.portcounters.locallinkintegrityerrors",
FT_UINT8, BASE_DEC, NULL, 0x0,
"The number of times the count of local physical errors exceeded the threshold specified by LocalPhyErrors",
HFILL}
},
{ &hf_infiniband_PortCounters_ExcessiveBufferOverrunErrors, {
"ExcessiveBufferOverrunErrors", "infiniband.portcounters.excessivebufferoverrunerrors",
FT_UINT8, BASE_DEC, NULL, 0x0,
"The number of times that OverrunErrors consecutive flow control update periods occured",
HFILL}
},
{ &hf_infiniband_PortCounters_VL15Dropped, {
"VL15Dropped", "infiniband.portcounters.vl15dropped",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Number of incoming VL15 packets dropped", HFILL}
},
{ &hf_infiniband_PortCounters_PortXmitData, {
"PortXmitData", "infiniband.portcounters.portxmitdata",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Total number of data octets, divided by 4, transmitted on all VLs from the port", HFILL}
},
{ &hf_infiniband_PortCounters_PortRcvData, {
"PortRcvData", "infiniband.portcounters.portrcvdata",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Total number of data octets, divided by 4, received on all VLs at the port", HFILL}
},
{ &hf_infiniband_PortCounters_PortXmitPkts, {
"PortXmitPkts", "infiniband.portcounters.portxmitpkts",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Total number of packets transmitted on all VLs from the port", HFILL}
},
{ &hf_infiniband_PortCounters_PortRcvPkts, {
"PortRcvPkts", "infiniband.portcounters.portrcvpkts",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Total number of packets received from all VLs on the port", HFILL}
},
{ &hf_infiniband_PortCountersExt, {
"Port Counters Extended (Performance Management MAD)", "infiniband.portcounters_ext",
FT_NONE, BASE_NONE, NULL, 0x0,
"Performance class PortCountersExtended packet", HFILL}
},
{ &hf_infiniband_PortCountersExt_PortSelect, {
"PortSelect", "infiniband.portcounters_ext.portselect",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Selects the port that will be accessed", HFILL}
},
{ &hf_infiniband_PortCountersExt_CounterSelect, {
"CounterSelect", "infiniband.portcounters_ext.counterselect",
FT_UINT16, BASE_HEX, NULL, 0x0,
"When writing, selects which counters are affected by the operation", HFILL}
},
{ &hf_infiniband_PortCountersExt_PortXmitData, {
"PortXmitData", "infiniband.portcounters_ext.portxmitdata",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Total number of data octets, divided by 4, transmitted on all VLs from the port", HFILL}
},
{ &hf_infiniband_PortCountersExt_PortRcvData, {
"PortRcvData", "infiniband.portcounters_ext.portrcvdata",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Total number of data octets, divided by 4, received on all VLs at the port", HFILL}
},
{ &hf_infiniband_PortCountersExt_PortXmitPkts, {
"PortXmitPkts", "infiniband.portcounters_ext.portxmitpkts",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Total number of packets transmitted on all VLs from the port", HFILL}
},
{ &hf_infiniband_PortCountersExt_PortRcvPkts, {
"PortRcvPkts", "infiniband.portcounters_ext.portrcvpkts",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Total number of packets received from all VLs on the port", HFILL}
},
{ &hf_infiniband_PortCountersExt_PortUnicastXmitPkts, {
"PortUnicastXmitPkts", "infiniband.portcounters_ext.portunicastxmitpkts",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Total number of unicast packets transmitted on all VLs from the port", HFILL}
},
{ &hf_infiniband_PortCountersExt_PortUnicastRcvPkts, {
"PortUnicastRcvPkts", "infiniband.portcounters_ext.portunicastrcvpkts",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Total number of unicast packets received from all VLs on the port", HFILL}
},
{ &hf_infiniband_PortCountersExt_PortMulticastXmitPkts, {
"PortMulticastXmitPkts", "infiniband.portcounters_ext.portmulticastxmitpkts",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Total number of multicast packets transmitted on all VLs from the port", HFILL}
},
{ &hf_infiniband_PortCountersExt_PortMulticastRcvPkts, {
"PortMulticastRcvPkts", "infiniband.portcounters_ext.portmulticastrcvpkts",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Total number of multicast packets received from all VLs on the port", HFILL}
}
};
static gint *ett[] = {
&ett_all_headers,
&ett_lrh,
&ett_grh,
&ett_bth,
&ett_rwh,
&ett_rdeth,
&ett_deth,
&ett_reth,
&ett_atomiceth,
&ett_aeth,
&ett_atomicacketh,
&ett_immdt,
&ett_ieth,
&ett_payload,
&ett_vendor,
&ett_subn_lid_routed,
&ett_subn_directed_route,
&ett_subnadmin,
&ett_cm,
&ett_mad,
&ett_rmpp,
&ett_subm_attribute,
&ett_suba_attribute,
&ett_datadetails,
&ett_noticestraps,
&ett_portinfo_capmask,
&ett_pkeytable,
&ett_sltovlmapping,
&ett_vlarbitrationtable,
&ett_linearforwardingtable,
&ett_randomforwardingtable,
&ett_multicastforwardingtable,
&ett_sminfo,
&ett_vendordiag,
&ett_ledinfo,
&ett_linkspeedwidthpairs,
&ett_informinfo,
&ett_linkrecord,
&ett_servicerecord,
&ett_pathrecord,
&ett_mcmemberrecord,
&ett_tracerecord,
&ett_multipathrecord,
&ett_serviceassocrecord,
&ett_perfclass,
&ett_eoib
};
static hf_register_info hf_link[] = {
{ &hf_infiniband_link_op, {
"Operand", "infiniband_link.op",
FT_UINT16, BASE_DEC, VALS(Operand_Description), 0xF000, NULL, HFILL}
},
{ &hf_infiniband_link_fctbs, {
"Flow Control Total Blocks Sent", "infiniband_link.fctbs",
FT_UINT16, BASE_DEC, NULL, 0x0FFF, NULL, HFILL}
},
{ &hf_infiniband_link_vl, {
"Virtual Lane", "infiniband_link.vl",
FT_UINT16, BASE_DEC, NULL, 0xF000, NULL, HFILL}
},
{ &hf_infiniband_link_fccl, {
"Flow Control Credit Limit", "infiniband_link.fccl",
FT_UINT16, BASE_DEC, NULL, 0x0FFF, NULL, HFILL}
},
{ &hf_infiniband_link_lpcrc, {
"Link Packet CRC", "infiniband_link.lpcrc",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL}
}
};
static gint *ett_link_array[] = {
&ett_link
};
proto_infiniband = proto_register_protocol("InfiniBand", "InfiniBand", "infiniband");
register_dissector("infiniband", dissect_infiniband, proto_infiniband);
proto_register_field_array(proto_infiniband, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_heur_dissector_list("infiniband.payload", &heur_dissectors_payload);
register_heur_dissector_list("infiniband.mad.cm.private", &heur_dissectors_cm_private);
infiniband_module = prefs_register_protocol(proto_infiniband, NULL);
prefs_register_bool_preference(infiniband_module, "identify_payload",
"Attempt to identify and parse encapsulated IBA payloads",
"When set, dissector will attempt to identify unknown IBA payloads "
"as containing an encapsulated ethertype, and parse them accordingly",
&pref_identify_iba_payload);
prefs_register_bool_preference(infiniband_module, "dissect_eoib",
"Attempt to identify and parse Mellanox EoIB packets",
"When set, dissector will attempt to identify and parse "
"Mellanox Ethernet-over-InfiniBand packets",
&pref_dissect_eoib);
proto_infiniband_link = proto_register_protocol("InfiniBand Link", "InfiniBand Link", "infiniband_link");
register_dissector("infiniband_link", dissect_infiniband_link, proto_infiniband_link);
proto_register_field_array(proto_infiniband_link, hf_link, array_length(hf_link));
proto_register_subtree_array(ett_link_array, array_length(ett_link_array));
register_init_routine(proto_init_infiniband);
CM_context_table = g_hash_table_new_full(g_int64_hash, g_int64_equal,
table_destroy_notify, table_destroy_notify);
}
void proto_reg_handoff_infiniband(void)
{
dissector_handle_t roce_handle;
ipv6_handle = find_dissector("ipv6");
data_handle = find_dissector("data");
eth_handle = find_dissector("eth");
ethertype_dissector_table = find_dissector_table("ethertype");
roce_handle = create_dissector_handle(dissect_roce, proto_infiniband);
dissector_add_uint("ethertype", ETHERTYPE_ROCE, roce_handle);
}
