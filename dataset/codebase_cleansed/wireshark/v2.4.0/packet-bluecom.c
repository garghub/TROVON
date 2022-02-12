static void
dissect_bcp_connect_data(proto_tree *bcp_tree, tvbuff_t *tvb,
guint *offset, guint len, gint flags)
{
proto_tree *bcp_subtree = NULL;
guint offset_base = *offset;
if (flags & BCP_PROT_FLG_REQ)
{
bcp_subtree = proto_tree_add_subtree_format(bcp_tree, tvb, *offset, len, ett_bcp_data, NULL,
"BCP Connect Request: Name=%s IpAddr=%s",
tvb_get_string_enc(wmem_packet_scope(), tvb, *offset + 16, BCP_NAME_LEN, ENC_ASCII),
tvb_ip_to_str(tvb, *offset + 12));
proto_tree_add_item(bcp_subtree, hf_bcp_connectreq_lenin, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(bcp_subtree, hf_bcp_connectreq_lenout, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(bcp_subtree, hf_bcp_connectreq_cycletime, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(bcp_subtree, hf_bcp_connectreq_offlinefactor, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(bcp_subtree, hf_bcp_connectreq_ipaddr, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(bcp_subtree, hf_bcp_connectreq_name, tvb, *offset, BCP_NAME_LEN, ENC_ASCII|ENC_NA);
*offset += BCP_NAME_LEN;
proto_tree_add_item(bcp_subtree, hf_bcp_connectreq_ethaddr, tvb, *offset, BCP_ETHADDR_LEN, ENC_NA);
*offset += BCP_ETHADDR_LEN;
if((len-(*offset-offset_base)))
{
proto_tree_add_item(bcp_subtree, hf_bcp_connectreq_ethaddr2, tvb, *offset, BCP_ETHADDR_LEN, ENC_NA);
*offset += BCP_ETHADDR_LEN;
}
}
if (flags & BCP_PROT_FLG_RSP)
{
bcp_subtree = proto_tree_add_subtree_format(bcp_tree, tvb, *offset, len, ett_bcp_data, NULL,
"BCP Connect Response: Error=%d",
tvb_get_ntohl(tvb, *offset));
proto_tree_add_item(bcp_subtree, hf_bcp_connectrsp_error, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(bcp_subtree, hf_bcp_connectrsp_lenin, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(bcp_subtree, hf_bcp_connectrsp_lenout, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
}
*offset = offset_base + len;
}
static void
dissect_bcp_search_data(proto_tree *bcp_tree, tvbuff_t *tvb,
guint *offset, guint len, gint flags)
{
proto_tree *bcp_subtree = NULL;
guint type = 0;
guint offset_base = *offset;
if (flags & BCP_PROT_FLG_REQ)
{
type = tvb_get_ntohl(tvb, *offset);
switch (type)
{
case BCP_SEARCH_IPADDR:
bcp_subtree = proto_tree_add_subtree_format(bcp_tree, tvb, *offset, len, ett_bcp_data, NULL,
"BCP Search Request: IpAddrFirst=%s, IpAddrLast=%s",
tvb_ip_to_str(tvb, *offset + 8),
tvb_ip_to_str(tvb, *offset + 12)
);
break;
case BCP_SEARCH_NAME:
bcp_subtree = proto_tree_add_subtree_format(bcp_tree, tvb, *offset, len, ett_bcp_data, NULL,
"BCP Search Request: Name=%s",
tvb_get_string_enc(wmem_packet_scope(), tvb, *offset + 8, BCP_NAME_LEN, ENC_ASCII)
);
break;
default:
bcp_subtree = proto_tree_add_subtree_format(bcp_tree, tvb, *offset, len, ett_bcp_data, NULL,
"BCP Search Request: Unknown AddrType");
break;
}
proto_tree_add_item(bcp_subtree, hf_bcp_searchreq_addrtype, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(bcp_subtree, hf_bcp_searchreq_reserved, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
switch (type)
{
case BCP_SEARCH_IPADDR:
proto_tree_add_item(bcp_subtree, hf_bcp_searchreq_ipaddrfirst, tvb, *offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(bcp_subtree, hf_bcp_searchreq_ipaddrlast, tvb, *offset + 4, 4, ENC_BIG_ENDIAN);
break;
case BCP_SEARCH_NAME:
proto_tree_add_item(bcp_subtree, hf_bcp_searchreq_name, tvb, *offset, BCP_NAME_LEN, ENC_ASCII|ENC_NA);
break;
default:
proto_tree_add_bytes_format(bcp_subtree, hf_bcp_searchreq_addrdata, tvb, *offset, BCP_NAME_LEN,
NULL, "Unknown Address Data (%u bytes)", BCP_NAME_LEN);
break;
}
*offset += BCP_NAME_LEN;
}
if (flags & BCP_PROT_FLG_RSP)
{
bcp_subtree = proto_tree_add_subtree_format(bcp_tree, tvb, *offset, len, ett_bcp_data, NULL,
"BCP Search Response: Name=%s, IpAddr=%s Error=%d",
tvb_get_string_enc(wmem_packet_scope(), tvb, *offset + 16, BCP_NAME_LEN, ENC_ASCII),
tvb_ip_to_str(tvb, *offset + 12),
tvb_get_letohl(tvb, *offset)
);
proto_tree_add_item(bcp_subtree, hf_bcp_searchrsp_error, tvb, *offset, 4, ENC_NA);
*offset += 4;
proto_tree_add_item(bcp_subtree, hf_bcp_searchrsp_starttime, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(bcp_subtree, hf_bcp_searchrsp_lenin, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(bcp_subtree, hf_bcp_searchrsp_lenout, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(bcp_subtree, hf_bcp_searchrsp_ipaddr, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(bcp_subtree, hf_bcp_searchrsp_name, tvb, *offset, BCP_NAME_LEN, ENC_ASCII|ENC_NA);
*offset += BCP_NAME_LEN;
proto_tree_add_item(bcp_subtree, hf_bcp_searchrsp_ethaddr, tvb, *offset, BCP_ETHADDR_LEN, ENC_NA);
*offset += BCP_ETHADDR_LEN;
if((len-(*offset-offset_base)))
{
proto_tree_add_item(bcp_subtree, hf_bcp_searchrsp_ethaddr2, tvb, *offset, BCP_ETHADDR_LEN, ENC_NA);
*offset += BCP_ETHADDR_LEN;
}
}
*offset = offset_base + len;
}
static void
dissect_bcp_identify_data(proto_tree *bcp_tree, tvbuff_t *tvb,
guint *offset, guint len)
{
proto_tree *bcp_subtree = NULL;
guint offset_base = *offset;
bcp_subtree = proto_tree_add_subtree_format(bcp_tree, tvb, *offset, len, ett_bcp_data, NULL,
"BCP Identify Request: Name=%s, IpAddr=%s",
tvb_get_string_enc(wmem_packet_scope(), tvb, *offset + 12, BCP_NAME_LEN, ENC_ASCII),
tvb_ip_to_str(tvb, *offset + 8)
);
proto_tree_add_item(bcp_subtree, hf_bcp_identify_error, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(bcp_subtree, hf_bcp_identify_starttime, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(bcp_subtree, hf_bcp_identify_ipaddr, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(bcp_subtree, hf_bcp_identify_name, tvb, *offset, BCP_NAME_LEN, ENC_ASCII|ENC_NA);
*offset += BCP_NAME_LEN;
proto_tree_add_item(bcp_subtree, hf_bcp_identify_ethaddr, tvb, *offset, BCP_ETHADDR_LEN, ENC_NA);
*offset += BCP_ETHADDR_LEN;
if((len-(*offset-offset_base)))
{
proto_tree_add_item(bcp_subtree, hf_bcp_identify_ethaddr2, tvb, *offset, BCP_ETHADDR_LEN, ENC_NA);
*offset += BCP_ETHADDR_LEN;
}
*offset = offset_base + len;
}
static void
dissect_bcp_sync_data(proto_tree *bcp_tree, tvbuff_t *tvb,
guint *offset, guint len)
{
proto_tree *bcp_subtree = NULL;
guint offset_base = *offset;
bcp_subtree = proto_tree_add_subtree_format(bcp_tree, tvb, *offset, len, ett_bcp_data, NULL,
"BCP Sync Data: Identify=%s",
BOOLSTR(tvb_get_guint8(tvb, *offset + 9)));
proto_tree_add_item(bcp_subtree, hf_bcp_sync_starttime, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(bcp_subtree, hf_bcp_sync_cycletime, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(bcp_subtree, hf_bcp_sync_dataratio, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
proto_tree_add_item(bcp_subtree, hf_bcp_sync_identify, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
proto_tree_add_item(bcp_subtree, hf_bcp_sync_vlantag, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
if((len-(*offset-offset_base)))
{
proto_tree_add_item(bcp_subtree, hf_bcp_sync_ethaddr, tvb, *offset, BCP_ETHADDR_LEN, ENC_NA);
*offset += BCP_ETHADDR_LEN;
proto_tree_add_item(bcp_subtree, hf_bcp_sync_ethaddr2, tvb, *offset, BCP_ETHADDR_LEN, ENC_NA);
*offset += BCP_ETHADDR_LEN;
}
*offset = offset_base + len;
}
static void
dissect_bcp_data(proto_tree *bcp_tree, packet_info *pinfo, tvbuff_t *tvb,
guint *offset, guint len, gint segcode)
{
dissector_handle_t handle;
tvbuff_t *next_tvb;
handle = dissector_get_uint_handle(bcp_subdissector_table, segcode);
if (handle)
{
next_tvb = tvb_new_subset_length_caplen(tvb, *offset, len, len);
call_dissector(handle, next_tvb, pinfo, bcp_tree);
*offset += len;
}
else
{
proto_tree_add_item(bcp_tree, hf_bcp_userdata, tvb, *offset, len, ENC_NA);
*offset += len;
}
}
static void
dissect_bcp_block_header(proto_tree *bcp_tree, tvbuff_t *tvb, guint *offset,
gint blocknb, gint *cmd, guint *len)
{
proto_tree *bcp_subtree = NULL;
*cmd = tvb_get_guint8(tvb, *offset + 6);
*len = tvb_get_ntohs(tvb, *offset + 12);
bcp_subtree = proto_tree_add_subtree_format(bcp_tree, tvb, *offset, BCP_BLOCK_HDR_LEN, ett_bcp_blockheader, NULL,
"BCP Block Header (%d): Cmd=%s (%d), Len=%d",
blocknb,
val_to_str(*cmd, bcp_cmds, "UNKNOWN"), *cmd,
*len
);
proto_tree_add_item(bcp_subtree, hf_bcp_hdr_sourceid, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(bcp_subtree, hf_bcp_hdr_destid, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(bcp_subtree, hf_bcp_hdr_transid, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(bcp_subtree, hf_bcp_hdr_cmd, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
proto_tree_add_item(bcp_subtree, hf_bcp_hdr_slavestate, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
proto_tree_add_item(bcp_subtree, hf_bcp_hdr_blockflags, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(bcp_subtree, hf_bcp_hdr_len, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(bcp_subtree, hf_bcp_hdr_fragoffset, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(bcp_subtree, hf_bcp_hdr_timestamp, tvb, *offset, 8, ENC_BIG_ENDIAN);
*offset += 8;
}
static void
dissect_bcp_protocol_header(proto_tree *bcp_tree, tvbuff_t *tvb,
guint *offset, gint *flags, gint *blocknb, gint *segcode)
{
proto_tree *bcp_subtree = NULL;
*flags = tvb_get_guint8(tvb, *offset + 2);
*blocknb = tvb_get_guint8(tvb, *offset + 3);
*segcode = tvb_get_ntohs(tvb, *offset + 4);
bcp_subtree = proto_tree_add_subtree_format(bcp_tree, tvb, 0, BCP_PROTOCOL_HDR_LEN, ett_bcp_header, NULL,
"BCP Protocol Header: BlockNb=%d, SegCode=%d",
tvb_get_guint8(tvb, *offset + 3),
tvb_get_ntohs(tvb, *offset + 4));
proto_tree_add_item(bcp_subtree, hf_bcp_hdr_version, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
proto_tree_add_item(bcp_subtree, hf_bcp_hdr_format, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
proto_tree_add_item(bcp_subtree, hf_bcp_hdr_protflags, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
proto_tree_add_item(bcp_subtree, hf_bcp_hdr_blocknb, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
proto_tree_add_item(bcp_subtree, hf_bcp_hdr_segcode, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(bcp_subtree, hf_bcp_hdr_auth, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
}
static int dissect_bluecom(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint cmd, flags, blocknb, segcode=0;
gint data_cnt = 0;
guint len, rlen;
guint offset = 0;
proto_tree *bcp_tree = NULL;
proto_item *bcp_item_base = NULL;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "bluecom");
col_set_str(pinfo->cinfo, COL_INFO, "CMD: ");
bcp_item_base = proto_tree_add_item(tree, proto_bcp, tvb, 0, -1, ENC_NA);
bcp_tree = proto_item_add_subtree(bcp_item_base, ett_bcp);
dissect_bcp_protocol_header(bcp_tree, tvb, &offset, &flags, &blocknb, &segcode);
dissect_bcp_block_header(bcp_tree, tvb, &offset, data_cnt, &cmd, &len);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s (%d) segcode=%d blocks=%d",
val_to_str(cmd, bcp_cmds, "UNKNOWN"), cmd, segcode, blocknb);
proto_item_append_text(bcp_item_base, ", %s (%d) len=%d",
val_to_str(cmd, bcp_cmds, "UNKNOWN"), cmd, tvb_reported_length(tvb));
switch (cmd) {
case BCP_BLK_CMD_SYNC:
dissect_bcp_sync_data(bcp_tree, tvb, &offset, len);
break;
case BCP_BLK_CMD_IDENTIFY:
dissect_bcp_identify_data(bcp_tree, tvb, &offset, len);
rlen = tvb_captured_length_remaining(tvb, offset);
while (rlen >= BCP_BLOCK_HDR_LEN)
{
dissect_bcp_block_header(bcp_tree, tvb, &offset, ++data_cnt, &cmd, &len);
rlen = tvb_captured_length_remaining(tvb, offset);
if (len > rlen)
{
len = rlen;
col_append_fstr(pinfo->cinfo, COL_INFO, " [data len of block %d limited to %d]",
data_cnt, len);
break;
}
dissect_bcp_identify_data(bcp_tree, tvb, &offset, len);
rlen = tvb_captured_length_remaining(tvb, offset);
}
offset += rlen;
break;
case BCP_BLK_CMD_SEARCH:
col_append_str(pinfo->cinfo, COL_INFO, REQRSP(flags));
dissect_bcp_search_data(bcp_tree, tvb, &offset, len, flags);
rlen = tvb_captured_length_remaining(tvb, offset);
while (rlen >= BCP_BLOCK_HDR_LEN)
{
dissect_bcp_block_header(bcp_tree, tvb, &offset, ++data_cnt, &cmd, &len);
rlen = tvb_captured_length_remaining(tvb, offset);
if (len > rlen)
{
len = rlen;
col_append_fstr(pinfo->cinfo, COL_INFO, " [data len of block %d limited to %d]",
data_cnt, len);
break;
}
dissect_bcp_search_data(bcp_tree, tvb, &offset, len, flags);
rlen = tvb_captured_length_remaining(tvb, offset);
}
offset += rlen;
break;
case BCP_BLK_CMD_CONNECT:
col_append_str(pinfo->cinfo, COL_INFO, REQRSP(flags));
dissect_bcp_connect_data(bcp_tree, tvb, &offset, len, flags);
rlen = tvb_captured_length_remaining(tvb, offset);
while (rlen >= BCP_BLOCK_HDR_LEN)
{
dissect_bcp_block_header(bcp_tree, tvb, &offset, ++data_cnt, &cmd, &len);
rlen = tvb_captured_length_remaining(tvb, offset);
if (len > rlen)
{
len = rlen;
col_append_fstr(pinfo->cinfo, COL_INFO, " [data len of block %d limited to %d]",
data_cnt, len);
break;
}
dissect_bcp_connect_data(bcp_tree, tvb, &offset, len, flags);
rlen = tvb_captured_length_remaining(tvb, offset);
}
offset += rlen;
break;
case BCP_BLK_CMD_DATA:
default:
rlen = tvb_captured_length_remaining(tvb, offset);
if (len > rlen)
{
len = rlen;
col_append_fstr(pinfo->cinfo, COL_INFO, " [data len of block %d limited to %d]",
data_cnt, len);
}
dissect_bcp_data(bcp_tree, pinfo, tvb, &offset, len, segcode);
rlen = tvb_captured_length_remaining(tvb, offset);
while (rlen >= BCP_BLOCK_HDR_LEN)
{
dissect_bcp_block_header(bcp_tree, tvb, &offset, ++data_cnt, &cmd, &len);
rlen = tvb_captured_length_remaining(tvb, offset);
if (len > rlen)
{
len = rlen;
col_append_fstr(pinfo->cinfo, COL_INFO, " [data len of block %d limited to %d]",
data_cnt, len);
break;
}
dissect_bcp_data(bcp_tree, pinfo, tvb, &offset, len, segcode);
rlen = tvb_captured_length_remaining(tvb, offset);
}
offset += rlen;
break;
}
return offset;
}
void
proto_register_bluecom(void)
{
static hf_register_info hf_bcp[] = {
{ &hf_bcp_hdr_version, {
"Version", "bluecom.hdr.version", FT_UINT8,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_hdr_format, {
"Format", "bluecom.hdr.format", FT_UINT8,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_hdr_protflags, {
"Flags", "bluecom.hdr.protflags", FT_UINT8,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_hdr_blocknb, {
"BlockNb", "bluecom.hdr.blocknb", FT_UINT8,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_hdr_segcode, {
"SegCode", "bluecom.hdr.segcode", FT_UINT16,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_hdr_auth, {
"Auth", "bluecom.hdr.auth", FT_UINT32,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_hdr_sourceid, {
"SourceId", "bluecom.hdr.sourceid", FT_UINT16,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_hdr_destid, {
"DestId", "bluecom.hdr.destid", FT_UINT16,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_hdr_transid, {
"TransId", "bluecom.hdr.transid", FT_UINT16,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_hdr_cmd, {
"Cmd", "bluecom.hdr.cmd", FT_UINT32,
BASE_HEX, VALS(bcp_cmds), 0, NULL, HFILL }},
{ &hf_bcp_hdr_slavestate, {
"SlaveState", "bluecom.hdr.slavestate", FT_UINT8,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_hdr_blockflags, {
"Flags", "bluecom.hdr.blockflags", FT_UINT8,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_hdr_len, {
"Len", "bluecom.hdr.len", FT_UINT8,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_hdr_fragoffset, {
"FragOffset", "bluecom.hdr.fragoffset", FT_UINT16,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_hdr_timestamp, {
"Timestamp", "bluecom.hdr.timestamp", FT_ABSOLUTE_TIME,
ABSOLUTE_TIME_LOCAL, NULL, 0, NULL, HFILL }},
{ &hf_bcp_sync_starttime, {
"StartTime", "bluecom.sync.blockflags", FT_UINT32,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_sync_cycletime, {
"CycleTime", "bluecom.sync.cycletime", FT_UINT32,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_sync_dataratio, {
"DataRatio", "bluecom.sync.dataratio", FT_UINT8,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_sync_identify, {
"Identify", "bluecom.sync.identify", FT_BOOLEAN,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_sync_vlantag, {
"VlanTag", "bluecom.sync.vlantag", FT_UINT16,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_sync_ethaddr, {
"EthAddr", "bluecom.sync.ethaddr", FT_ETHER,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_bcp_sync_ethaddr2, {
"EthAddr2", "bluecom.sync.ethaddr2", FT_ETHER,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_bcp_identify_error, {
"Error", "bluecom.identify.error", FT_UINT32,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_identify_starttime, {
"StartTime", "bluecom.identify.starttime", FT_UINT32,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_identify_ipaddr, {
"IpAddr", "bluecom.identify.ipaddr", FT_IPv4,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_bcp_identify_name, {
"Name", "bluecom.identify.name", FT_STRING,
STR_ASCII, NULL, 0, NULL, HFILL }},
{ &hf_bcp_identify_ethaddr, {
"EthAddr", "bluecom.identify.ethaddr", FT_ETHER,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_bcp_identify_ethaddr2, {
"EthAddr2", "bluecom.identify.ethaddr2", FT_ETHER,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_bcp_searchreq_addrtype, {
"AddrType", "bluecom.searchreq.addrtype", FT_UINT32,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_searchreq_reserved, {
"Reserved", "bluecom.searchreq.reserved", FT_UINT32,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_searchreq_name, {
"Name", "bluecom.searchreq.name", FT_STRING,
STR_ASCII, NULL, 0, NULL, HFILL }},
{ &hf_bcp_searchreq_ipaddrfirst, {
"IpAddrFirst", "bluecom.searchreq.ipaddrfirst", FT_IPv4,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_bcp_searchreq_ipaddrlast, {
"IpAddrLast", "bluecom.searchreq.ipaddrlast", FT_IPv4,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_bcp_searchreq_addrdata, {
"Data", "bluecom.searchreq.addrdata", FT_BYTES,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_bcp_searchrsp_error, {
"Error", "bluecom.searchrsp.error", FT_UINT32,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_searchrsp_starttime, {
"StartTime", "bluecom.searchrsp.starttime", FT_UINT32,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_searchrsp_lenin, {
"LenIn", "bluecom.searchrsp.lenin", FT_UINT16,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_searchrsp_lenout, {
"LenOut", "bluecom.searchrsp.lenout", FT_UINT16,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_searchrsp_ipaddr, {
"IpAddr", "bluecom.searchrsp.ipaddr", FT_IPv4,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_bcp_searchrsp_name, {
"Name", "bluecom.searchrsp.name", FT_STRING,
STR_ASCII, NULL, 0, NULL, HFILL }},
{ &hf_bcp_searchrsp_ethaddr, {
"EthAddr", "bluecom.searchrsp.ethaddr", FT_ETHER,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_bcp_searchrsp_ethaddr2, {
"EthAddr2", "bluecom.searchrsp.ethaddr2", FT_ETHER,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_bcp_connectreq_lenin, {
"LenIn", "bluecom.connectreq.lenin", FT_UINT16,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_connectreq_lenout, {
"LenOut", "bluecom.connectreq.lenout", FT_UINT16,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_connectreq_cycletime, {
"CycleTime", "bluecom.connectreq.cycletime", FT_UINT32,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_connectreq_offlinefactor, {
"OfflineFactor", "bluecom.connectreq.offlinefactor", FT_UINT16,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_connectreq_ipaddr, {
"IpAddr", "bluecom.connectreq.ipaddr", FT_IPv4,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_bcp_connectreq_name, {
"Name", "bluecom.connectreq.name", FT_STRING,
STR_ASCII, NULL, 0, NULL, HFILL }},
{ &hf_bcp_connectreq_ethaddr, {
"EthAddr", "bluecom.connectreq.ethaddr", FT_ETHER,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_bcp_connectreq_ethaddr2, {
"EthAddr2", "bluecom.connectreq.ethaddr2", FT_ETHER,
BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_bcp_connectrsp_error, {
"Error", "bluecom.connectrsp.error", FT_UINT32,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_connectrsp_lenin, {
"LenIn", "bluecom.connectrsp.lenin", FT_UINT16,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_connectrsp_lenout, {
"LenOut", "bluecom.connectrsp.lenout", FT_UINT16,
BASE_DEC_HEX, NULL, 0, NULL, HFILL }},
{ &hf_bcp_userdata, {
"BCP Userdata", "bluecom.userdata", FT_BYTES,
BASE_NONE, NULL, 0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_bcp,
&ett_bcp_header,
&ett_bcp_blockheader,
&ett_bcp_data,
};
proto_bcp = proto_register_protocol("bluecom Protocol", "bluecom", "bluecom");
proto_register_field_array(proto_bcp, hf_bcp, array_length(hf_bcp));
proto_register_subtree_array(ett, array_length(ett));
bcp_handle = register_dissector("bluecom", dissect_bluecom, proto_bcp);
bcp_subdissector_table = register_dissector_table("bluecomseg", "bluecom SegCode", proto_bcp,
FT_UINT8, BASE_DEC);
}
void
proto_reg_handoff_bluecom(void)
{
dissector_add_uint("ethertype", ETHERTYPE_BLUECOM, bcp_handle);
}
