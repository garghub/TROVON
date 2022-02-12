static gboolean
h225rassrt_packet(void *phs, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *phi)
{
rtd_data_t* rtd_data = (rtd_data_t*)phs;
rtd_stat_table* rs = &rtd_data->stat_table;
const h225_packet_info *pi=(const h225_packet_info *)phi;
ras_type rasmsg_type = RAS_OTHER;
ras_category rascategory = RAS_OTHERS;
if (pi->msg_type != H225_RAS || pi->msg_tag == -1) {
return FALSE;
}
if (pi->msg_tag < 21) {
rascategory = (ras_category)(pi->msg_tag / 3);
rasmsg_type = (ras_type)(pi->msg_tag % 3);
}
else {
return FALSE;
}
switch(rasmsg_type) {
case RAS_REQUEST:
if(pi->is_duplicate){
rs->time_stats[rascategory].req_dup_num++;
}
else {
rs->time_stats[rascategory].open_req_num++;
}
break;
case RAS_CONFIRM:
case RAS_REJECT:
if(pi->is_duplicate){
rs->time_stats[rascategory].rsp_dup_num++;
}
else if (!pi->request_available) {
rs->time_stats[rascategory].disc_rsp_num++;
}
else {
rs->time_stats[rascategory].open_req_num--;
time_stat_update(&(rs->time_stats[rascategory].rtd[0]),&(pi->delta_time), pinfo);
}
break;
default:
return FALSE;
}
return TRUE;
}
static gint h225ras_call_equal(gconstpointer k1, gconstpointer k2)
{
const h225ras_call_info_key* key1 = (const h225ras_call_info_key*) k1;
const h225ras_call_info_key* key2 = (const h225ras_call_info_key*) k2;
return (key1->reqSeqNum == key2->reqSeqNum &&
key1->conversation == key2->conversation);
}
static guint h225ras_call_hash(gconstpointer k)
{
const h225ras_call_info_key* key = (const h225ras_call_info_key*) k;
return key->reqSeqNum + GPOINTER_TO_UINT(key->conversation);
}
h225ras_call_t * find_h225ras_call(h225ras_call_info_key *h225ras_call_key ,int category)
{
h225ras_call_t *h225ras_call = NULL;
h225ras_call = (h225ras_call_t *)g_hash_table_lookup(ras_calls[category], h225ras_call_key);
return h225ras_call;
}
h225ras_call_t * new_h225ras_call(h225ras_call_info_key *h225ras_call_key, packet_info *pinfo, e_guid_t *guid, int category)
{
h225ras_call_info_key *new_h225ras_call_key;
h225ras_call_t *h225ras_call = NULL;
new_h225ras_call_key = wmem_new(wmem_file_scope(), h225ras_call_info_key);
new_h225ras_call_key->reqSeqNum = h225ras_call_key->reqSeqNum;
new_h225ras_call_key->conversation = h225ras_call_key->conversation;
h225ras_call = wmem_new(wmem_file_scope(), h225ras_call_t);
h225ras_call->req_num = pinfo->num;
h225ras_call->rsp_num = 0;
h225ras_call->requestSeqNum = h225ras_call_key->reqSeqNum;
h225ras_call->responded = FALSE;
h225ras_call->next_call = NULL;
h225ras_call->req_time=pinfo->abs_ts;
h225ras_call->guid=*guid;
g_hash_table_insert(ras_calls[category], new_h225ras_call_key, h225ras_call);
return h225ras_call;
}
h225ras_call_t * append_h225ras_call(h225ras_call_t *prev_call, packet_info *pinfo, e_guid_t *guid, int category _U_)
{
h225ras_call_t *h225ras_call = NULL;
h225ras_call = wmem_new(wmem_file_scope(), h225ras_call_t);
h225ras_call->req_num = pinfo->num;
h225ras_call->rsp_num = 0;
h225ras_call->requestSeqNum = prev_call->requestSeqNum;
h225ras_call->responded = FALSE;
h225ras_call->next_call = NULL;
h225ras_call->req_time=pinfo->abs_ts;
h225ras_call->guid=*guid;
prev_call->next_call = h225ras_call;
return h225ras_call;
}
static void
h225_init_routine(void)
{
int i;
for(i=0;i<7;i++) {
ras_calls[i] = g_hash_table_new(h225ras_call_hash, h225ras_call_equal);
}
}
static void
h225_cleanup_routine(void)
{
int i;
for(i=0;i<7;i++) {
g_hash_table_destroy(ras_calls[i]);
}
}
static int
dissect_h225_H323UserInformation(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *it;
proto_tree *tr;
int offset = 0;
pi_current++;
if(pi_current==5){
pi_current=0;
}
h225_pi=&pi_arr[pi_current];
reset_h225_packet_info(h225_pi);
h225_pi->msg_type = H225_CS;
next_tvb_init(&h245_list);
next_tvb_init(&tp_list);
col_set_str(pinfo->cinfo, COL_PROTOCOL, PSNAME);
col_clear(pinfo->cinfo, COL_INFO);
it=proto_tree_add_protocol_format(tree, proto_h225, tvb, 0, -1, PSNAME" CS");
tr=proto_item_add_subtree(it, ett_h225);
offset = dissect_H323_UserInformation_PDU(tvb, pinfo, tr, NULL);
if (h245_list.count){
col_append_str(pinfo->cinfo, COL_PROTOCOL, "/");
col_set_fence(pinfo->cinfo, COL_PROTOCOL);
}
next_tvb_call(&h245_list, pinfo, tree, h245dg_handle, data_handle);
next_tvb_call(&tp_list, pinfo, tree, NULL, data_handle);
tap_queue_packet(h225_tap, pinfo, h225_pi);
return offset;
}
static int
dissect_h225_h225_RasMessage(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_){
proto_item *it;
proto_tree *tr;
guint32 offset=0;
pi_current++;
if(pi_current==5){
pi_current=0;
}
h225_pi=&pi_arr[pi_current];
reset_h225_packet_info(h225_pi);
h225_pi->msg_type = H225_RAS;
col_set_str(pinfo->cinfo, COL_PROTOCOL, PSNAME);
it=proto_tree_add_protocol_format(tree, proto_h225, tvb, offset, -1, PSNAME" RAS");
tr=proto_item_add_subtree(it, ett_h225);
offset = dissect_RasMessage_PDU(tvb, pinfo, tr, NULL);
ras_call_matching(tvb, pinfo, tr, h225_pi);
tap_queue_packet(h225_tap, pinfo, h225_pi);
return offset;
}
static void h225_stat_init(stat_tap_table_ui* new_stat, new_stat_tap_gui_init_cb gui_callback, void* gui_data)
{
int num_fields = sizeof(h225_stat_fields)/sizeof(stat_tap_table_item);
stat_tap_table* table = new_stat_tap_init_table("H.225 Messages and Message Reasons", num_fields, 0, NULL, gui_callback, gui_data);
int row_idx = 0, msg_idx;
stat_tap_table_item_type items[sizeof(h225_stat_fields)/sizeof(stat_tap_table_item)];
new_stat_tap_add_table(new_stat, table);
items[MESSAGE_TYPE_COLUMN].type = TABLE_ITEM_STRING;
items[COUNT_COLUMN].type = TABLE_ITEM_UINT;
items[COUNT_COLUMN].value.uint_value = 0;
msg_idx = 0;
do
{
items[MESSAGE_TYPE_COLUMN].value.string_value =
h225_RasMessage_vals[msg_idx].strptr
? h225_RasMessage_vals[msg_idx].strptr
: "Unknown RAS message";
ras_msg_idx[msg_idx] = row_idx;
new_stat_tap_init_table_row(table, row_idx, num_fields, items);
row_idx++;
msg_idx++;
} while (h225_RasMessage_vals[msg_idx].strptr);
msg_idx = 0;
do
{
items[MESSAGE_TYPE_COLUMN].value.string_value =
T_h323_message_body_vals[msg_idx].strptr
? T_h323_message_body_vals[msg_idx].strptr
: "Unknown CS message";
cs_msg_idx[msg_idx] = row_idx;
new_stat_tap_init_table_row(table, row_idx, num_fields, items);
row_idx++;
msg_idx++;
} while (T_h323_message_body_vals[msg_idx].strptr);
msg_idx = 0;
do
{
items[MESSAGE_TYPE_COLUMN].value.string_value =
GatekeeperRejectReason_vals[msg_idx].strptr
? GatekeeperRejectReason_vals[msg_idx].strptr
: "Unknown gatekeeper reject reason";
grj_reason_idx[msg_idx] = row_idx;
new_stat_tap_init_table_row(table, row_idx, num_fields, items);
row_idx++;
msg_idx++;
} while (GatekeeperRejectReason_vals[msg_idx].strptr);
msg_idx = 0;
do
{
items[MESSAGE_TYPE_COLUMN].value.string_value =
RegistrationRejectReason_vals[msg_idx].strptr
? RegistrationRejectReason_vals[msg_idx].strptr
: "Unknown registration reject reason";
rrj_reason_idx[msg_idx] = row_idx;
new_stat_tap_init_table_row(table, row_idx, num_fields, items);
row_idx++;
msg_idx++;
} while (RegistrationRejectReason_vals[msg_idx].strptr);
msg_idx = 0;
do
{
items[MESSAGE_TYPE_COLUMN].value.string_value =
UnregRequestReason_vals[msg_idx].strptr
? UnregRequestReason_vals[msg_idx].strptr
: "Unknown unregistration request reason";
urq_reason_idx[msg_idx] = row_idx;
new_stat_tap_init_table_row(table, row_idx, num_fields, items);
row_idx++;
msg_idx++;
} while (UnregRequestReason_vals[msg_idx].strptr);
msg_idx = 0;
do
{
items[MESSAGE_TYPE_COLUMN].value.string_value =
UnregRejectReason_vals[msg_idx].strptr
? UnregRejectReason_vals[msg_idx].strptr
: "Unknown unregistration reject reason";
urj_reason_idx[msg_idx] = row_idx;
new_stat_tap_init_table_row(table, row_idx, num_fields, items);
row_idx++;
msg_idx++;
} while (UnregRejectReason_vals[msg_idx].strptr);
msg_idx = 0;
do
{
items[MESSAGE_TYPE_COLUMN].value.string_value =
AdmissionRejectReason_vals[msg_idx].strptr
? AdmissionRejectReason_vals[msg_idx].strptr
: "Unknown admission reject reason";
arj_reason_idx[msg_idx] = row_idx;
new_stat_tap_init_table_row(table, row_idx, num_fields, items);
row_idx++;
msg_idx++;
} while (AdmissionRejectReason_vals[msg_idx].strptr);
msg_idx = 0;
do
{
items[MESSAGE_TYPE_COLUMN].value.string_value =
BandRejectReason_vals[msg_idx].strptr
? BandRejectReason_vals[msg_idx].strptr
: "Unknown band reject reason";
brj_reason_idx[msg_idx] = row_idx;
new_stat_tap_init_table_row(table, row_idx, num_fields, items);
row_idx++;
msg_idx++;
} while (BandRejectReason_vals[msg_idx].strptr);
msg_idx = 0;
do
{
items[MESSAGE_TYPE_COLUMN].value.string_value =
DisengageReason_vals[msg_idx].strptr
? DisengageReason_vals[msg_idx].strptr
: "Unknown disengage reason";
drq_reason_idx[msg_idx] = row_idx;
new_stat_tap_init_table_row(table, row_idx, num_fields, items);
row_idx++;
msg_idx++;
} while (DisengageReason_vals[msg_idx].strptr);
msg_idx = 0;
do
{
items[MESSAGE_TYPE_COLUMN].value.string_value =
DisengageRejectReason_vals[msg_idx].strptr
? DisengageRejectReason_vals[msg_idx].strptr
: "Unknown disengage reject reason";
drj_reason_idx[msg_idx] = row_idx;
new_stat_tap_init_table_row(table, row_idx, num_fields, items);
row_idx++;
msg_idx++;
} while (DisengageRejectReason_vals[msg_idx].strptr);
msg_idx = 0;
do
{
items[MESSAGE_TYPE_COLUMN].value.string_value =
LocationRejectReason_vals[msg_idx].strptr
? LocationRejectReason_vals[msg_idx].strptr
: "Unknown location reject reason";
lrj_reason_idx[msg_idx] = row_idx;
new_stat_tap_init_table_row(table, row_idx, num_fields, items);
row_idx++;
msg_idx++;
} while (LocationRejectReason_vals[msg_idx].strptr);
msg_idx = 0;
do
{
items[MESSAGE_TYPE_COLUMN].value.string_value =
InfoRequestNakReason_vals[msg_idx].strptr
? InfoRequestNakReason_vals[msg_idx].strptr
: "Unknown info request nak reason";
irqnak_reason_idx[msg_idx] = row_idx;
new_stat_tap_init_table_row(table, row_idx, num_fields, items);
row_idx++;
msg_idx++;
} while (InfoRequestNakReason_vals[msg_idx].strptr);
msg_idx = 0;
do
{
items[MESSAGE_TYPE_COLUMN].value.string_value =
h225_ReleaseCompleteReason_vals[msg_idx].strptr
? h225_ReleaseCompleteReason_vals[msg_idx].strptr
: "Unknown release complete reason";
rel_cmp_reason_idx[msg_idx] = row_idx;
new_stat_tap_init_table_row(table, row_idx, num_fields, items);
row_idx++;
msg_idx++;
} while (h225_ReleaseCompleteReason_vals[msg_idx].strptr);
msg_idx = 0;
do
{
items[MESSAGE_TYPE_COLUMN].value.string_value =
FacilityReason_vals[msg_idx].strptr
? FacilityReason_vals[msg_idx].strptr
: "Unknown facility reason";
facility_reason_idx[msg_idx] = row_idx;
new_stat_tap_init_table_row(table, row_idx, num_fields, items);
row_idx++;
msg_idx++;
} while (FacilityReason_vals[msg_idx].strptr);
items[MESSAGE_TYPE_COLUMN].value.string_value = "Unknown H.225 message";
new_stat_tap_init_table_row(table, row_idx, num_fields, items);
other_idx = row_idx;
}
static gboolean
h225_stat_packet(void *tapdata, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *hpi_ptr)
{
new_stat_data_t* stat_data = (new_stat_data_t*)tapdata;
const h225_packet_info *hpi = (const h225_packet_info *)hpi_ptr;
int tag_idx = -1;
int reason_idx = -1;
if(hpi->msg_tag < 0) {
return FALSE;
}
switch (hpi->msg_type) {
case H225_RAS:
tag_idx = ras_msg_idx[MIN(hpi->msg_tag, (int)RAS_MSG_TYPES-1)];
if(hpi->reason < 0) {
break;
}
switch(hpi->msg_tag) {
case 2:
reason_idx = grj_reason_idx[MIN(hpi->reason, (int)GRJ_REASONS-1)];
break;
case 5:
reason_idx = rrj_reason_idx[MIN(hpi->reason, (int)RRJ_REASONS-1)];
break;
case 6:
reason_idx = urq_reason_idx[MIN(hpi->reason, (int)URQ_REASONS-1)];
break;
case 8:
reason_idx = urj_reason_idx[MIN(hpi->reason, (int)URJ_REASONS-1)];
break;
case 11:
reason_idx = arj_reason_idx[MIN(hpi->reason, (int)ARJ_REASONS-1)];
break;
case 14:
reason_idx = brj_reason_idx[MIN(hpi->reason, (int)BRJ_REASONS-1)];
break;
case 15:
reason_idx = drq_reason_idx[MIN(hpi->reason, (int)DRQ_REASONS-1)];
break;
case 17:
reason_idx = drj_reason_idx[MIN(hpi->reason, (int)DRJ_REASONS-1)];
break;
case 20:
reason_idx = lrj_reason_idx[MIN(hpi->reason, (int)LRJ_REASONS-1)];
break;
case 29:
reason_idx = irqnak_reason_idx[MIN(hpi->reason, (int)IRQNAK_REASONS-1)];
break;
default:
break;
}
break;
case H225_CS:
tag_idx = cs_msg_idx[MIN(hpi->msg_tag, (int)CS_MSG_TYPES-1)];
if(hpi->reason < 0) {
break;
}
switch(hpi->msg_tag) {
case 5:
reason_idx = rel_cmp_reason_idx[MIN(hpi->reason, (int)REL_CMP_REASONS-1)];
break;
case 6:
reason_idx = facility_reason_idx[MIN(hpi->reason, (int)FACILITY_REASONS-1)];
break;
default:
break;
}
break;
case H225_OTHERS:
default:
tag_idx = other_idx;
}
if (tag_idx >= 0) {
stat_tap_table*table = g_array_index(stat_data->stat_tap_data->tables, stat_tap_table*, 0);
stat_tap_table_item_type* msg_data = new_stat_tap_get_field_data(table, tag_idx, COUNT_COLUMN);;
msg_data->value.uint_value++;
new_stat_tap_set_field_data(table, tag_idx, COUNT_COLUMN, msg_data);
if (reason_idx >= 0) {
msg_data = new_stat_tap_get_field_data(table, reason_idx, COUNT_COLUMN);;
msg_data->value.uint_value++;
new_stat_tap_set_field_data(table, reason_idx, COUNT_COLUMN, msg_data);
}
return TRUE;
}
return FALSE;
}
static void
h225_stat_reset(stat_tap_table* table)
{
guint element;
stat_tap_table_item_type* item_data;
for (element = 0; element < table->num_elements; element++)
{
item_data = new_stat_tap_get_field_data(table, element, COUNT_COLUMN);
item_data->value.uint_value = 0;
new_stat_tap_set_field_data(table, element, COUNT_COLUMN, item_data);
}
}
void proto_register_h225(void) {
static hf_register_info hf[] = {
{ &hf_h221Manufacturer,
{ "H.225 Manufacturer", "h225.Manufacturer", FT_UINT32, BASE_HEX,
VALS(H221ManufacturerCode_vals), 0, "h225.H.221 Manufacturer", HFILL }},
{ &hf_h225_ras_req_frame,
{ "RAS Request Frame", "h225.ras.reqframe", FT_FRAMENUM, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_h225_ras_rsp_frame,
{ "RAS Response Frame", "h225.ras.rspframe", FT_FRAMENUM, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_h225_ras_dup,
{ "Duplicate RAS Message", "h225.ras.dup", FT_UINT32, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_h225_ras_deltatime,
{ "RAS Service Response Time", "h225.ras.timedelta", FT_RELATIVE_TIME, BASE_NONE,
NULL, 0, "Timedelta between RAS-Request and RAS-Response", HFILL }},
{ &hf_h225_debug_dissector_try_string,
{ "*** DEBUG dissector_try_string", "h225.debug.dissector_try_string", FT_STRING, BASE_NONE,
NULL, 0, NULL, HFILL }},
#include "packet-h225-hfarr.c"
};
static gint *ett[] = {
&ett_h225,
#include "packet-h225-ettarr.c"
};
static tap_param h225_stat_params[] = {
{ PARAM_FILTER, "filter", "Filter", NULL, TRUE }
};
static stat_tap_table_ui h225_stat_table = {
REGISTER_STAT_GROUP_TELEPHONY,
"H.225",
PFNAME,
"h225,counter",
h225_stat_init,
h225_stat_packet,
h225_stat_reset,
NULL,
NULL,
sizeof(h225_stat_fields)/sizeof(stat_tap_table_item), h225_stat_fields,
sizeof(h225_stat_params)/sizeof(tap_param), h225_stat_params,
NULL
};
module_t *h225_module;
int proto_h225_ras;
proto_h225 = proto_register_protocol(PNAME, PSNAME, PFNAME);
proto_h225_ras = proto_register_protocol("H.225 RAS", "H.225 RAS", "h225_ras");
proto_register_field_array(proto_h225, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
h225_module = prefs_register_protocol(proto_h225, proto_reg_handoff_h225);
prefs_register_uint_preference(h225_module, "tls.port",
"H.225 TLS Port",
"H.225 Server TLS Port",
10, &h225_tls_port);
prefs_register_bool_preference(h225_module, "reassembly",
"Reassemble H.225 messages spanning multiple TCP segments",
"Whether the H.225 dissector should reassemble messages spanning multiple TCP segments."
" To use this option, you must also enable \"Allow subdissectors to reassemble TCP streams\" in the TCP protocol settings.",
&h225_reassembly);
prefs_register_bool_preference(h225_module, "h245_in_tree",
"Display tunnelled H.245 inside H.225.0 tree",
"ON - display tunnelled H.245 inside H.225.0 tree, OFF - display tunnelled H.245 in root tree after H.225.0",
&h225_h245_in_tree);
prefs_register_bool_preference(h225_module, "tp_in_tree",
"Display tunnelled protocols inside H.225.0 tree",
"ON - display tunnelled protocols inside H.225.0 tree, OFF - display tunnelled protocols in root tree after H.225.0",
&h225_tp_in_tree);
register_dissector(PFNAME, dissect_h225_H323UserInformation, proto_h225);
register_dissector("h323ui",dissect_h225_H323UserInformation, proto_h225);
register_dissector("h225.ras", dissect_h225_h225_RasMessage, proto_h225);
nsp_object_dissector_table = register_dissector_table("h225.nsp.object", "H.225 NonStandardParameter (object)", proto_h225, FT_STRING, BASE_NONE, DISSECTOR_TABLE_ALLOW_DUPLICATE);
nsp_h221_dissector_table = register_dissector_table("h225.nsp.h221", "H.225 NonStandardParameter (h221)", proto_h225, FT_UINT32, BASE_HEX, DISSECTOR_TABLE_ALLOW_DUPLICATE);
tp_dissector_table = register_dissector_table("h225.tp", "H.225 TunnelledProtocol", proto_h225, FT_STRING, BASE_NONE, DISSECTOR_TABLE_ALLOW_DUPLICATE);
gef_name_dissector_table = register_dissector_table("h225.gef.name", "H.225 Generic Extensible Framework (names)", proto_h225, FT_STRING, BASE_NONE, DISSECTOR_TABLE_ALLOW_DUPLICATE);
gef_content_dissector_table = register_dissector_table("h225.gef.content", "H.225 Generic Extensible Framework", proto_h225, FT_STRING, BASE_NONE, DISSECTOR_TABLE_ALLOW_DUPLICATE);
register_init_routine(&h225_init_routine);
register_cleanup_routine(&h225_cleanup_routine);
h225_tap = register_tap(PFNAME);
register_rtd_table(proto_h225_ras, PFNAME, NUM_RAS_STATS, 1, ras_message_category, h225rassrt_packet, NULL);
register_stat_tap_table_ui(&h225_stat_table);
oid_add_from_string("Version 1","0.0.8.2250.0.1");
oid_add_from_string("Version 2","0.0.8.2250.0.2");
oid_add_from_string("Version 3","0.0.8.2250.0.3");
oid_add_from_string("Version 4","0.0.8.2250.0.4");
oid_add_from_string("Version 5","0.0.8.2250.0.5");
oid_add_from_string("Version 6","0.0.8.2250.0.6");
}
void
proto_reg_handoff_h225(void)
{
static gboolean h225_prefs_initialized = FALSE;
static dissector_handle_t h225ras_handle, q931_tpkt_handle;
static guint saved_h225_tls_port;
if (!h225_prefs_initialized) {
h225ras_handle=find_dissector("h225.ras");
dissector_add_uint("udp.port", UDP_PORT_RAS1, h225ras_handle);
dissector_add_uint("udp.port", UDP_PORT_RAS2, h225ras_handle);
h245_handle = find_dissector("h245");
h245dg_handle = find_dissector("h245dg");
h4501_handle = find_dissector("h4501");
data_handle = find_dissector("data");
h225_prefs_initialized = TRUE;
q931_tpkt_handle = find_dissector("q931.tpkt");
} else {
ssl_dissector_delete(saved_h225_tls_port, q931_tpkt_handle);
}
saved_h225_tls_port = h225_tls_port;
ssl_dissector_add(saved_h225_tls_port, q931_tpkt_handle);
}
static void reset_h225_packet_info(h225_packet_info *pi)
{
if(pi == NULL) {
return;
}
pi->msg_type = H225_OTHERS;
pi->cs_type = H225_OTHER;
pi->msg_tag = -1;
pi->reason = -1;
pi->requestSeqNum = 0;
memset(&pi->guid,0,sizeof pi->guid);
pi->is_duplicate = FALSE;
pi->request_available = FALSE;
pi->is_faststart = FALSE;
pi->is_h245 = FALSE;
pi->is_h245Tunneling = FALSE;
pi->h245_address = 0;
pi->h245_port = 0;
pi->frame_label[0] = '\0';
pi->dialedDigits[0] = '\0';
pi->is_destinationInfo = FALSE;
}
static void ras_call_matching(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, h225_packet_info *pi)
{
proto_item *hidden_item;
conversation_t* conversation = NULL;
h225ras_call_info_key h225ras_call_key;
h225ras_call_t *h225ras_call = NULL;
nstime_t delta;
guint msg_category;
if(pi->msg_type == H225_RAS && pi->msg_tag < 21) {
msg_category = pi->msg_tag / 3;
if(pi->msg_tag % 3 == 0) {
conversation = find_or_create_conversation(pinfo);
h225ras_call_key.reqSeqNum = pi->requestSeqNum;
h225ras_call_key.conversation = conversation;
h225ras_call = find_h225ras_call(&h225ras_call_key ,msg_category);
if (h225ras_call != NULL) {
do {
if (pinfo->num == h225ras_call->req_num) {
break;
}
if (h225ras_call->next_call == NULL) {
if ( (pinfo->num > h225ras_call->rsp_num && h225ras_call->rsp_num != 0
&& pinfo->abs_ts.secs > (h225ras_call->req_time.secs + THRESHOLD_REPEATED_RESPONDED_CALL) )
||(pinfo->num > h225ras_call->req_num && h225ras_call->rsp_num == 0
&& pinfo->abs_ts.secs > (h225ras_call->req_time.secs + THRESHOLD_REPEATED_NOT_RESPONDED_CALL) ) )
{
h225ras_call = append_h225ras_call(h225ras_call, pinfo, &pi->guid, msg_category);
} else {
pi->is_duplicate = TRUE;
hidden_item = proto_tree_add_uint(tree, hf_h225_ras_dup, tvb, 0,0, pi->requestSeqNum);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
break;
}
h225ras_call = h225ras_call->next_call;
} while (h225ras_call != NULL );
}
else {
h225ras_call = new_h225ras_call(&h225ras_call_key, pinfo, &pi->guid, msg_category);
}
if(h225ras_call && h225ras_call->rsp_num != 0){
proto_item *ti =
proto_tree_add_uint_format(tree, hf_h225_ras_rsp_frame, tvb, 0, 0, h225ras_call->rsp_num,
"The response to this request is in frame %u",
h225ras_call->rsp_num);
PROTO_ITEM_SET_GENERATED(ti);
}
}
else {
conversation = find_conversation(pinfo->num, &pinfo->src,
&pinfo->dst, pinfo->ptype, pinfo->srcport,
pinfo->destport, 0);
if (conversation != NULL) {
h225ras_call_key.reqSeqNum = pi->requestSeqNum;
h225ras_call_key.conversation = conversation;
h225ras_call = find_h225ras_call(&h225ras_call_key ,msg_category);
if(h225ras_call) {
do {
if (pinfo->num == h225ras_call->rsp_num) {
break;
}
if(h225ras_call->next_call == NULL) {
break;
}
h225ras_call = h225ras_call->next_call;
} while (h225ras_call != NULL) ;
if (!h225ras_call) {
return;
}
if (msg_category == 3 || msg_category == 5) {
pi->guid = h225ras_call->guid;
hidden_item = proto_tree_add_guid(tree, hf_h225_guid, tvb, 0, GUID_LEN, &pi->guid);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
if (h225ras_call->rsp_num == 0) {
h225ras_call->rsp_num = pinfo->num;
}
else {
if (h225ras_call->rsp_num != pinfo->num) {
pi->is_duplicate = TRUE;
hidden_item = proto_tree_add_uint(tree, hf_h225_ras_dup, tvb, 0,0, pi->requestSeqNum);
PROTO_ITEM_SET_HIDDEN(hidden_item);
}
}
if(h225ras_call->req_num != 0){
proto_item *ti;
h225ras_call->responded = TRUE;
pi->request_available = TRUE;
ti = proto_tree_add_uint_format(tree, hf_h225_ras_req_frame, tvb, 0, 0, h225ras_call->req_num,
"This is a response to a request in frame %u", h225ras_call->req_num);
PROTO_ITEM_SET_GENERATED(ti);
nstime_delta(&delta, &pinfo->abs_ts, &h225ras_call->req_time);
pi->delta_time = delta;
ti = proto_tree_add_time(tree, hf_h225_ras_deltatime, tvb, 0, 0, &(pi->delta_time));
PROTO_ITEM_SET_GENERATED(ti);
}
}
}
}
}
}
