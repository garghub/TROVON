int
is_tpkt(tvbuff_t *tvb, int min_len)
{
guint16 pkt_len;
if (!proto_is_protocol_enabled(proto_tpkt_ptr))
return -1;
if (tvb_length(tvb) < 4)
return -1;
if (!(tvb_get_guint8(tvb, 0) == 3 && tvb_get_guint8(tvb, 1) == 0))
return -1;
pkt_len = tvb_get_ntohs(tvb, 2);
if (pkt_len < 4 + min_len)
return -1;
return pkt_len;
}
guint16
is_asciitpkt(tvbuff_t *tvb)
{
guint16 count;
if (!proto_is_protocol_enabled(proto_tpkt_ptr))
return -1;
if (!tvb_bytes_exist(tvb, 0, 8))
return -1;
for (count = 0; count <=7 ; count ++)
{
if(!isalnum(tvb_get_guint8(tvb,count)))
{
return 0;
}
}
return 1;
}
static int
parseLengthText ( guint8* pTpktData )
{
int value = 0;
const guint8 * pData = pTpktData;
int bitvalue = 0, count1 = 3;
int count;
for (count = 0; count <= 3; count++)
{
if (('0' <= *(pData + count)) && (*(pData + count) <= '9'))
bitvalue = *(pData + count) - 48;
else if (('a' <= *(pData + count)) && (*(pData + count) <= 'f' ))
bitvalue = *(pData + count) - 87;
else if (('A' <= *(pData + count)) && (*(pData + count) <= 'F' ))
bitvalue = *(pData + count) - 55;
value += bitvalue << (4*count1);
count1--;
}
return value;
}
static int
parseVersionText ( guint8* pTpktData )
{
int value = 0;
guint8 * pData = pTpktData;
int bitvalue = 0, count1 = 1;
int count;
for (count = 0; count <= 1; count++)
{
if (('0' <= *(pData + count)) && (*(pData + count) <= '9'))
bitvalue = *(pData + count) - 48;
else if (('a' <= *(pData + count)) && (*(pData + count) <= 'f' ))
bitvalue = *(pData + count) - 87;
else if (('A' <= *(pData + count)) && (*(pData + count) <= 'F' ))
bitvalue = *(pData + count) - 55;
value += bitvalue << (4*count1);
count1--;
}
return value;
}
static int
parseReservedText ( guint8* pTpktData )
{
int value = 0;
guint8 * pData = pTpktData;
int bitvalue = 0, count1 = 1;
int count;
for (count = 0; count <= 1; count++)
{
if (('0' <= *(pData + count)) && (*(pData + count) <= '9'))
bitvalue = *(pData + count) - 48;
else if (('a' <= *(pData + count)) && (*(pData + count) <= 'f' ))
bitvalue = *(pData + count) - 87;
else if (('A' <= *(pData + count)) && (*(pData + count) <= 'F' ))
bitvalue = *(pData + count) - 55;
value += bitvalue << (4*count1);
count1--;
}
return value;
}
void
dissect_asciitpkt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
dissector_handle_t subdissector_handle)
{
proto_item *ti = NULL;
proto_tree *tpkt_tree = NULL;
volatile int offset = 0;
int length_remaining;
int data_len;
volatile int mgcp_packet_len = 0;
int mgcp_version = 0;
int mgcp_reserved = 0;
volatile int length;
tvbuff_t *volatile next_tvb;
const char *saved_proto;
guint8 string[4];
void *pd_save;
if (tpkt_desegment)
col_add_str(pinfo->cinfo, COL_INFO, "");
while (tvb_reported_length_remaining(tvb, offset) != 0) {
if (tvb_get_guint8(tvb, offset) != 48) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TPKT");
col_set_str(pinfo->cinfo, COL_INFO, "Continuation");
if (tree) {
ti = proto_tree_add_item(tree, proto_tpkt, tvb,
offset, -1, ENC_NA);
tpkt_tree = proto_item_add_subtree(ti, ett_tpkt);
proto_item_set_text(ti, "TPKT");
proto_tree_add_text(tpkt_tree, tvb, offset, -1,
"Continuation data");
}
return;
}
length_remaining = tvb_length_remaining(tvb, offset);
tvb_memcpy(tvb, (guint8 *)string, offset, 2);
mgcp_version = parseVersionText(string);
tvb_memcpy(tvb, (guint8 *)string, offset +2, 2);
mgcp_reserved = parseReservedText(string);
tvb_memcpy(tvb, (guint8 *)string, offset + 4, 4);
mgcp_packet_len = parseLengthText(string);
data_len = mgcp_packet_len;
saved_proto = pinfo->current_proto;
pinfo->current_proto = "TPKT";
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TPKT");
if (!tpkt_desegment && !pinfo->fragmented) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"TPKT Data length = %u", data_len);
}
if (tree) {
ti = proto_tree_add_item(tree, proto_tpkt, tvb,
offset, 8, ENC_NA);
tpkt_tree = proto_item_add_subtree(ti, ett_tpkt);
proto_item_set_text(ti, "TPKT");
proto_tree_add_uint(tpkt_tree, hf_tpkt_version, tvb,
offset, 2, mgcp_version);
proto_tree_add_uint(tpkt_tree, hf_tpkt_reserved, tvb,
offset + 2, 2, mgcp_reserved);
proto_tree_add_uint(tpkt_tree, hf_tpkt_length, tvb,
offset + 4, 4, mgcp_packet_len);
}
pinfo->current_proto = saved_proto;
offset += TEXT_LAYER_LENGTH;
length = length_remaining - TEXT_LAYER_LENGTH;
if (length > data_len)
length = data_len;
next_tvb = tvb_new_subset(tvb, offset,length, data_len);
pd_save = pinfo->private_data;
TRY {
call_dissector(subdissector_handle, next_tvb, pinfo,
tree);
}
CATCH_NONFATAL_ERRORS {
pinfo->private_data = pd_save;
show_exception(tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
}
ENDTRY;
offset += data_len;
}
}
void
dissect_tpkt_encap(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gboolean desegment, dissector_handle_t subdissector_handle)
{
proto_item *ti = NULL;
proto_tree *tpkt_tree = NULL;
volatile int offset = 0;
int length_remaining;
int data_len;
volatile int length;
tvbuff_t *volatile next_tvb;
const char *saved_proto;
void *pd_save;
if (desegment)
col_set_str(pinfo->cinfo, COL_INFO, "");
while (tvb_reported_length_remaining(tvb, offset) != 0) {
if (tvb_get_guint8(tvb, offset) != 3) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TPKT");
col_set_str(pinfo->cinfo, COL_INFO, "Continuation");
if (tree) {
ti = proto_tree_add_item(tree, proto_tpkt, tvb,
offset, -1, ENC_NA);
tpkt_tree = proto_item_add_subtree(ti, ett_tpkt);
proto_item_set_text(ti, "TPKT");
proto_tree_add_text(tpkt_tree, tvb, offset, -1,
"Continuation data");
}
return;
}
length_remaining = tvb_length_remaining(tvb, offset);
if (desegment && pinfo->can_desegment) {
if (length_remaining < 4) {
pinfo->desegment_offset = offset;
pinfo->desegment_len = DESEGMENT_ONE_MORE_SEGMENT;
return;
}
}
data_len = tvb_get_ntohs(tvb, offset + 2);
if (desegment && pinfo->can_desegment) {
if (length_remaining < data_len) {
pinfo->desegment_offset = offset;
pinfo->desegment_len =
data_len - length_remaining;
return;
}
}
saved_proto = pinfo->current_proto;
pinfo->current_proto = "TPKT";
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TPKT");
if (!desegment && !pinfo->fragmented) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"TPKT Data length = %u", data_len);
}
if (tree) {
ti = proto_tree_add_item(tree, proto_tpkt, tvb,
offset, 4, ENC_NA);
tpkt_tree = proto_item_add_subtree(ti, ett_tpkt);
proto_item_set_text(ti, "TPKT");
proto_tree_add_item(tpkt_tree, hf_tpkt_version, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_item_append_text(ti, ", Version: 3");
proto_tree_add_item(tpkt_tree, hf_tpkt_reserved, tvb,
offset + 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint(tpkt_tree, hf_tpkt_length, tvb,
offset + 2, 2, data_len);
proto_item_append_text(ti, ", Length: %u", data_len);
}
pinfo->current_proto = saved_proto;
offset += 4;
data_len -= 4;
length = length_remaining - 4;
if (length > data_len)
length = data_len;
next_tvb = tvb_new_subset(tvb, offset, length, data_len);
pd_save = pinfo->private_data;
TRY {
call_dissector(subdissector_handle, next_tvb, pinfo,
tree);
}
CATCH_NONFATAL_ERRORS {
pinfo->private_data = pd_save;
show_exception(tvb, pinfo, tree, EXCEPT_CODE, GET_MESSAGE);
}
ENDTRY;
offset += length;
}
}
static void
dissect_tpkt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_tpkt_encap(tvb, pinfo, tree, tpkt_desegment, osi_tp_handle);
}
void
proto_register_tpkt(void)
{
static hf_register_info hf[] =
{
{
&hf_tpkt_version,
{
"Version",
"tpkt.version",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
"Version, only version 3 is defined", HFILL
}
},
{
&hf_tpkt_reserved,
{
"Reserved",
"tpkt.reserved",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
"Reserved, should be 0", HFILL
}
},
{
&hf_tpkt_length,
{
"Length",
"tpkt.length",
FT_UINT16,
BASE_DEC,
NULL,
0x0,
"Length of data unit, including this header", HFILL
}
},
};
static gint *ett[] =
{
&ett_tpkt,
};
module_t *tpkt_module;
proto_tpkt = proto_register_protocol("TPKT - ISO on TCP - RFC1006", "TPKT", "tpkt");
proto_tpkt_ptr = find_protocol_by_id(proto_tpkt);
proto_register_field_array(proto_tpkt, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("tpkt", dissect_tpkt, proto_tpkt);
tpkt_module = prefs_register_protocol(proto_tpkt, NULL);
prefs_register_bool_preference(tpkt_module, "desegment",
"Reassemble TPKT messages spanning multiple TCP segments",
"Whether the TPKT dissector should reassemble messages spanning multiple TCP segments. "
"To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&tpkt_desegment);
}
void
proto_reg_handoff_tpkt(void)
{
dissector_handle_t tpkt_handle;
osi_tp_handle = find_dissector("ositp");
tpkt_handle = find_dissector("tpkt");
dissector_add_uint("tcp.port", TCP_PORT_TPKT, tpkt_handle);
}
