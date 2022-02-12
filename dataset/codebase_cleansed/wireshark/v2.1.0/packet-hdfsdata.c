static int
decode_vint_size (gint8 value) {
if (value >= -112) {
return 1;
} else if (value < -120) {
return -119 - value;
}
return -111 - value;
}
static guint
dissect_variable_length_long (tvbuff_t *tvb, proto_tree *hdfsdata_tree, int* offset)
{
int byte_count = 1;
int idx = 0;
guint i = 0;
gint8 first_byte = tvb_get_guint8(tvb, *offset);
guint size = 0;
int len = decode_vint_size(first_byte);
if (len == 1) {
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_clientlen, tvb, *offset, byte_count, ENC_BIG_ENDIAN);
*offset = (*offset) + byte_count;
return first_byte;
}
for (idx = 0; idx < len-1; idx++) {
char b = tvb_get_guint8(tvb, *offset + byte_count);
byte_count++;
i = i << 8;
i = i | (b & 0xFF);
}
size = ((first_byte < -120 || (first_byte >= -112 && first_byte < 0)) ? (i ^ 0xFFFFFFFF) : i);
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_clientlen, tvb, *offset, byte_count, ENC_BIG_ENDIAN);
*offset = (*offset) + byte_count;
return size;
}
static void
dissect_variable_int_string(tvbuff_t *tvb, proto_tree *hdfsdata_tree, int *offset)
{
int len = dissect_variable_length_long (tvb, hdfsdata_tree, offset);
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_clientid, tvb, *offset, len, ENC_ASCII|ENC_NA);
*offset += len;
}
static void
dissect_access_tokens(tvbuff_t *tvb, proto_tree *hdfsdata_tree, int *offset)
{
int len = 0;
len = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_tokenlen, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_tokenid, tvb, *offset, len, ENC_ASCII|ENC_NA);
*offset += len;
len = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_tokenlen, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_tokenpassword, tvb, *offset, len, ENC_ASCII|ENC_NA);
*offset += len;
len = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_tokenlen, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_tokentype, tvb, *offset, len, ENC_ASCII|ENC_NA);
*offset += len;
len = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_tokenlen, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_tokenservice, tvb, *offset, len, ENC_ASCII|ENC_NA);
*offset += len;
}
static void
dissect_read_response(tvbuff_t *tvb, proto_tree *hdfsdata_tree, int offset)
{
int len = 0;
guint32 chunksize;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_datalength, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_inblockoffset, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_seqnum, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_last, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_datalen, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
chunksize = tvb_get_ntohl(tvb, CHUNKSIZE_START);
if (chunksize == 0)
return;
if (tvb_get_guint8(tvb, 2) == CRC) {
len = (int)(CRC_SIZE * tvb_get_ntohl(tvb, offset - 4) *
tvb_get_ntohl(tvb, offset - 8) / chunksize);
}
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_crc32, tvb, offset, len, ENC_BIG_ENDIAN);
}
static void
dissect_read_response_start(tvbuff_t *tvb, proto_tree *hdfsdata_tree, int offset) {
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_status, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_checksumtype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_chunksize, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_chunkoffset, tvb, offset, 8, ENC_BIG_ENDIAN);
}
static void
dissect_read_request(tvbuff_t *tvb, proto_tree *hdfsdata_tree, int *offset)
{
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_startoffset, tvb, *offset, 8, ENC_BIG_ENDIAN);
*offset += 8;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_blocklen, tvb, *offset, 8, ENC_BIG_ENDIAN);
*offset += 8;
}
static void
dissect_write_request(tvbuff_t *tvb, proto_tree *hdfsdata_tree, int *offset)
{
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_pipelinenum, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_recovery, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
}
static void
dissect_write_request_end(tvbuff_t *tvb, proto_tree *hdfsdata_tree, int *offset)
{
int i = 0;
int len = 0;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_sourcenode, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
len = tvb_get_ntohl(tvb, *offset);
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_currentpipeline, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
for (i = 0; i < len; i++) {
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_node, tvb, *offset, 4, ENC_BIG_ENDIAN);
*offset += 4;
}
}
static int
dissect_header(tvbuff_t *tvb, proto_tree *hdfsdata_tree, int* offset){
int command = 0;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_version, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
command = tvb_get_guint8(tvb, *offset);
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_cmd, tvb, *offset, 1, ENC_BIG_ENDIAN);
*offset += 1;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_blockid, tvb, *offset, 8, ENC_BIG_ENDIAN);
*offset += 8;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_timestamp, tvb, *offset, 8, ENC_BIG_ENDIAN);
*offset += 8;
return command;
}
static void
dissect_write_response(tvbuff_t *tvb, proto_tree *hdfsdata_tree, int offset)
{
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_packetsize, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_startoffset, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_seqnum, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_last, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_chunklength, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_crc64, tvb, offset, 8, ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_rest, tvb, offset, (tvb_reported_length(tvb)) - offset, ENC_ASCII|ENC_NA);
}
static guint
get_hdfsdata_message_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset, void *data _U_)
{
if (tvb_reported_length(tvb) <= 4 || tvb_reported_length(tvb) == END_PACKET_LEN
|| tvb_get_ntohl(tvb, 0) == tvb_reported_length(tvb) - WRITE_RESP_HEAD_LEN
|| (tvb_reported_length(tvb) >= MIN_READ_REQ && tvb_get_guint8(tvb, 2) == READ_OP)
|| (tvb_reported_length(tvb) >= MIN_WRITE_REQ && tvb_get_guint8(tvb, 2) == WRITE_OP)) {
return tvb_reported_length(tvb);
}
return tvb_get_ntohl(tvb, offset + FIRST_READ_FRAGMENT_LEN) +
FIRST_READ_FRAGMENT_LEN + SECOND_READ_FRAGMENT_LEN - LAST_READ_FRAGMENT_LEN;
}
static int
dissect_hdfsdata_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
int offset = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HDFSDATA");
col_set_str(pinfo->cinfo, COL_INFO, "HDFS Data");
if (tree) {
proto_item *ti = NULL;
proto_tree *hdfsdata_tree = NULL;
ti = proto_tree_add_item(tree, proto_hdfsdata, tvb, offset, -1, ENC_NA);
hdfsdata_tree = proto_item_add_subtree(ti, ett_hdfsdata);
if ((tvb_reported_length(tvb)) == PIPELINE_LEN) {
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_pipelinestatus, tvb, offset, PIPELINE_LEN, ENC_BIG_ENDIAN);
} else if ((tvb_reported_length(tvb)) == STATUS_LEN) {
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_status, tvb, offset, STATUS_LEN, ENC_BIG_ENDIAN);
} else if ((tvb_reported_length(tvb)) == FINISH_REQ_LEN) {
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_end, tvb, offset, 4, ENC_BIG_ENDIAN);
} else if (tvb_reported_length(tvb) >= READ_RESP_HEAD_LEN && tvb_reported_length(tvb) ==
tvb_get_ntohl(tvb, FIRST_READ_FRAGMENT_LEN) +
FIRST_READ_FRAGMENT_LEN + SECOND_READ_FRAGMENT_LEN - LAST_READ_FRAGMENT_LEN){
dissect_read_response_start(tvb, hdfsdata_tree, offset);
offset += FIRST_READ_FRAGMENT_LEN;
dissect_read_response(tvb, hdfsdata_tree, offset);
offset+= SECOND_READ_FRAGMENT_LEN;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_rest, tvb, offset, (tvb_reported_length(tvb)) - offset, ENC_ASCII|ENC_NA);
} else {
guint8 op = tvb_get_guint8(tvb, 2);
if ((tvb_reported_length(tvb)) >= MIN_READ_REQ && op == READ_OP) {
dissect_header(tvb, hdfsdata_tree, &offset);
dissect_read_request(tvb, hdfsdata_tree, &offset);
dissect_variable_int_string(tvb, hdfsdata_tree, &offset);
dissect_access_tokens(tvb, hdfsdata_tree, &offset);
} else if ((tvb_reported_length(tvb)) >= MIN_WRITE_REQ && op == WRITE_OP) {
dissect_header(tvb, hdfsdata_tree, &offset);
dissect_write_request(tvb, hdfsdata_tree, &offset);
dissect_variable_int_string(tvb, hdfsdata_tree, &offset);
dissect_write_request_end(tvb, hdfsdata_tree, &offset);
dissect_access_tokens(tvb, hdfsdata_tree, &offset);
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_checksumtype, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_chunksize, tvb, offset, 4, ENC_BIG_ENDIAN);
} else if (tvb_reported_length(tvb) >= 4 && tvb_get_ntohl(tvb, 0) ==
tvb_reported_length(tvb) - WRITE_RESP_HEAD_LEN) {
dissect_write_response(tvb, hdfsdata_tree, offset);
} else {
proto_tree_add_item(hdfsdata_tree, hf_hdfsdata_rest, tvb, offset, (tvb_reported_length(tvb)), ENC_ASCII|ENC_NA);
}
}
}
return tvb_captured_length(tvb);
}
static int
dissect_hdfsdata(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
int frame_header_len = 0;
gboolean need_reassemble = FALSE;
guint8 op = 0;
gboolean only_packet = tvb_reported_length(tvb) == 1 || (tvb_reported_length(tvb) == 2 &&
tvb_get_ntohs(tvb, 0) == STATUS_SUCCESS);
if (tvb_reported_length(tvb) >= 3)
op = tvb_get_guint8(tvb, 2);
if (!only_packet && tvb_reported_length(tvb) != 4 && !(tvb_reported_length(tvb) >= MIN_READ_REQ && op == READ_OP) &&
!(tvb_reported_length(tvb) >= MIN_WRITE_REQ && op == WRITE_OP) && !(tvb_reported_length(tvb) == END_PACKET_LEN &&
!tvb_get_ntohl(tvb, 0) && !tvb_get_ntohl(tvb, 4))) {
need_reassemble = TRUE;
}
if (only_packet || tvb_reported_length(tvb) == END_PACKET_LEN) {
frame_header_len = tvb_reported_length(tvb);
} else if (tvb_reported_length(tvb) == FIRST_READ_FRAGMENT_LEN ||(tvb_reported_length(tvb) >= MIN_READ_REQ &&
op == READ_OP && !((tvb_reported_length(tvb)) == 2 && !tvb_get_ntohs(tvb, 0)))) {
frame_header_len = READ_RESP_HEAD_LEN;
} else if (tvb_reported_length(tvb) >= MIN_WRITE_REQ && op == WRITE_OP) {
frame_header_len = WRITE_REQ_HEAD_LEN;
}
tcp_dissect_pdus(tvb, pinfo, tree, need_reassemble, frame_header_len, get_hdfsdata_message_len, dissect_hdfsdata_message, data);
return tvb_captured_length(tvb);
}
void
proto_register_hdfsdata(void)
{
static hf_register_info hf[] = {
{ &hf_hdfsdata_version,
{ "HDFSDATA protocol version", "hdfsdata.version",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_cmd,
{ "HDFSDATA command", "hdfsdata.cmd",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_blockid,
{ "HDFSDATA block id", "hdfsdata.blockid",
FT_UINT64, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_timestamp,
{ "HDFSDATA timestamp", "hdfsdata.timestamp",
FT_UINT64, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_startoffset,
{ "HDFSDATA start offset" , "hdfsdata.startoffset",
FT_UINT64, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_blocklen,
{ "HDFSDATA block length", "hdfsdata.blocklen",
FT_UINT64, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_pipelinenum,
{ "HDFSDATA number in pipeline", "hdfsdata.pipelinenum",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_recovery,
{ "HDFSDATA recovery boolean", "hdfsdata.recovery",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_sourcenode,
{ "HDFSDATA source node", "hdfsdata.sourcenode",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_currentpipeline,
{ "HDFSDATA current number of nodes in the pipeline", "hdfsdata.currentpipline",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_node,
{ "HDFSDATA node object", "hdfsdata.node",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_clientlen,
{ "HDFSDATA client id length", "hdfsdata.clientlen",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_clientid,
{ "HDFSDATA client id", "hdfsdata.clientid",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_end,
{ "HDFSDATA end data request", "hdfsdata.end",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_tokenlen,
{ "HDFSDATA access token length", "hdfsdata.tokenlen",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_tokenid,
{ "HDFSDATA access token ID", "hdfsdata.tokenid",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_tokenpassword,
{ "HDFSDATA access token password", "hdfsdata.tokenpassword",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_tokentype,
{ "HDFSDATA access token type", "hdfsdata.tokentype",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_tokenservice,
{ "HDFSDATA access token service", "hdfsdata.tokenservice",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_status,
{ "HDFSDATA status code", "hdfsdata.status",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_checksumtype,
{ "HDFSDATA checksum type", "hdfsdata.checksumtype",
FT_UINT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_chunksize,
{ "HDFSDATA chunk size", "hdfsdata.chunksize",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_chunkoffset,
{ "HDFSDATA chunk offset", "hdfsdata.chunkoffset",
FT_UINT64, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_datalength,
{ "HDFSDATA length of data", "hdfsdata.datalength",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_inblockoffset,
{ "HDFSDATA in block offset", "hdfsdata.inblockoffset",
FT_UINT64, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_seqnum,
{ "HDFSDATA sequence number", "hdfsdata.seqnum",
FT_UINT64, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_last,
{ "HDFSDATA last packet in block", "hdfsdata.last",
FT_INT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_datalen,
{ "HDFSDATA length of data", "hdfsdata.datalen",
FT_INT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_crc32,
{ "HDFSDATA crc32 checksum", "hdfsdata.crc32",
FT_INT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_rest,
{ "HDFSDATA data", "hdfsdata.rest",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_packetsize,
{ "HDFSDATA packet size", "hdfsdata.packetsize",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_chunklength,
{ "HDFSDATA chunk length", "hdfsdata.chunklength",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_crc64,
{ "HDFSDATA crc64 checksum", "hdfsdata.crc64",
FT_INT64, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_hdfsdata_pipelinestatus,
{ "HDFSDATA pipeline status", "hdfsdata.pipelinestatus",
FT_INT8, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_hdfsdata
};
module_t *hdfsdata_module;
proto_hdfsdata = proto_register_protocol (
"HDFSDATA Protocol",
"HDFSDATA",
"hdfsdata"
);
proto_register_field_array(proto_hdfsdata, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
hdfsdata_module = prefs_register_protocol(proto_hdfsdata, proto_reg_handoff_hdfsdata);
prefs_register_uint_preference(hdfsdata_module,
"tcp.port",
"TCP port for HDFSDATA",
"Set the TCP port for HDFSDATA",
10,
&tcp_port);
hdfsdata_handle = register_dissector("hdfsdata", dissect_hdfsdata, proto_hdfsdata);
}
void
proto_reg_handoff_hdfsdata(void)
{
static gboolean initialized = FALSE;
static guint saved_tcp_port;
if (!initialized) {
dissector_add_for_decode_as("tcp.port", hdfsdata_handle);
initialized = TRUE;
} else if (saved_tcp_port != 0) {
dissector_delete_uint("tcp.port", saved_tcp_port, hdfsdata_handle);
}
if (tcp_port != 0) {
dissector_add_uint("tcp.port", tcp_port, hdfsdata_handle);
}
saved_tcp_port = tcp_port;
}
