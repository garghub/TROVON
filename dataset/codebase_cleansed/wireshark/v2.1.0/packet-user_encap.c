static void export_pdu(tvbuff_t *tvb, packet_info* pinfo, char *proto_name)
{
if (have_tap_listener(exported_pdu_tap)) {
exp_pdu_data_t *exp_pdu_data;
guint8 exp_pdu_data_tag;
exp_pdu_data_tag = EXP_PDU_TAG_ORIG_FNO_BIT;
exp_pdu_data = load_export_pdu_tags(pinfo, EXP_PDU_TAG_PROTO_NAME, proto_name, &exp_pdu_data_tag, 1);
exp_pdu_data->tvb_captured_length = tvb_captured_length(tvb);
exp_pdu_data->tvb_reported_length = tvb_reported_length(tvb);
exp_pdu_data->pdu_tvb = tvb;
tap_queue_packet(exported_pdu_tap, pinfo, exp_pdu_data);
}
}
static int dissect_user(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, void* data _U_) {
user_encap_t* encap = NULL;
tvbuff_t* payload_tvb;
proto_item* item;
gint len, reported_len;
guint i;
for (i = 0; i < num_encaps; i++) {
if (encaps[i].encap == pinfo->match_uint) {
encap = &(encaps[i]);
break;
}
}
item = proto_tree_add_item(tree,proto_user_encap,tvb,0,-1,ENC_NA);
if (!encap && pinfo->match_uint == WTAP_ENCAP_USER2) {
encap = &user2_encap;
}
if (!encap) {
char* msg = wmem_strdup_printf(wmem_packet_scope(),
"User encapsulation not handled: DLT=%d, "
"check your Preferences->Protocols->DLT_USER",
pinfo->match_uint + 147 - WTAP_ENCAP_USER0);
proto_item_set_text(item,"%s",msg);
expert_add_info_format(pinfo, item, &ei_user_encap_not_handled, "%s", msg);
call_data_dissector(tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
if (encap->payload_proto == NULL) {
char* msg = wmem_strdup_printf(wmem_packet_scope(),
"User encapsulation's protocol %s not found: "
"DLT=%d, check your Preferences->Protocols->DLT_USER",
encap->payload_proto_name,
pinfo->match_uint + 147 - WTAP_ENCAP_USER0);
proto_item_set_text(item,"%s",msg);
expert_add_info_format(pinfo, item, &ei_user_encap_not_handled, "%s", msg);
call_data_dissector(tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
proto_item_set_text(item,"DLT: %d",pinfo->match_uint + 147 - WTAP_ENCAP_USER0);
if (encap->header_size) {
tvbuff_t* hdr_tvb = tvb_new_subset_length(tvb, 0, encap->header_size);
export_pdu(hdr_tvb, pinfo, encap->header_proto_name);
call_dissector(encap->header_proto, hdr_tvb, pinfo, tree);
if (encap->header_proto_name) {
const char *proto_name = dissector_handle_get_long_name(find_dissector(encap->header_proto_name));
if (proto_name) {
proto_item_append_text(item, ", Header: %s (%s)", encap->header_proto_name, proto_name);
}
}
}
len = tvb_captured_length(tvb) - (encap->header_size + encap->trailer_size);
reported_len = tvb_reported_length(tvb) - (encap->header_size + encap->trailer_size);
payload_tvb = tvb_new_subset(tvb, encap->header_size, len, reported_len);
export_pdu(payload_tvb, pinfo, encap->payload_proto_name);
call_dissector(encap->payload_proto, payload_tvb, pinfo, tree);
if (encap->payload_proto_name) {
const char *proto_name = dissector_handle_get_long_name(find_dissector(encap->payload_proto_name));
if (proto_name) {
proto_item_append_text(item, ", Payload: %s (%s)", encap->payload_proto_name, proto_name);
}
}
if (encap->trailer_size) {
tvbuff_t* trailer_tvb = tvb_new_subset_length(tvb, encap->header_size + len, encap->trailer_size);
export_pdu(trailer_tvb, pinfo, encap->trailer_proto_name);
call_dissector(encap->trailer_proto, trailer_tvb, pinfo, tree);
if (encap->trailer_proto_name) {
const char *proto_name = dissector_handle_get_long_name(find_dissector(encap->trailer_proto_name));
if (proto_name) {
proto_item_append_text(item, ", Trailer: %s (%s)", encap->trailer_proto_name, proto_name);
}
}
}
return tvb_captured_length(tvb);
}
static void* user_copy_cb(void* dest, const void* orig, size_t len _U_)
{
const user_encap_t *o = (const user_encap_t *)orig;
user_encap_t *d = (user_encap_t *)dest;
d->payload_proto_name = g_strdup(o->payload_proto_name);
d->header_proto_name = g_strdup(o->header_proto_name);
d->trailer_proto_name = g_strdup(o->trailer_proto_name);
return d;
}
static void user_free_cb(void* record)
{
user_encap_t *u = (user_encap_t *)record;
g_free(u->payload_proto_name);
g_free(u->header_proto_name);
g_free(u->trailer_proto_name);
}
void proto_reg_handoff_user_encap(void)
{
dissector_handle_t user_encap_handle;
guint i;
user_encap_handle = find_dissector("user_dlt");
user2_encap.encap = WTAP_ENCAP_USER2;
user2_encap.payload_proto_name = g_strdup("pktap");
user2_encap.payload_proto = find_dissector("pktap");
user2_encap.header_proto_name = g_strdup("");
user2_encap.header_proto = NULL;
user2_encap.trailer_proto_name = g_strdup("");
user2_encap.trailer_proto = NULL;
user2_encap.header_size = 0;
user2_encap.trailer_size = 0;
for (i = WTAP_ENCAP_USER0 ; i <= WTAP_ENCAP_USER15; i++)
dissector_add_uint("wtap_encap", i, user_encap_handle);
}
void proto_register_user_encap(void)
{
module_t *module;
expert_module_t* expert_user_encap;
static uat_field_t user_flds[] = {
UAT_FLD_VS(user_encap,encap,"DLT",user_dlts,"The DLT"),
UAT_FLD_PROTO(user_encap,payload_proto,"Payload protocol",
"Protocol to be used for the payload of this DLT"),
UAT_FLD_DEC(user_encap,header_size,"Header size",
"Size of an eventual header that precedes the actual payload, 0 means none"),
UAT_FLD_PROTO(user_encap,header_proto,"Header protocol",
"Protocol to be used for the header (empty = data)"),
UAT_FLD_DEC(user_encap,trailer_size,"Trailer size",
"Size of an eventual trailer that follows the actual payload, 0 means none"),
UAT_FLD_PROTO(user_encap,trailer_proto,"Trailer protocol",
"Protocol to be used for the trailer (empty = data)"),
UAT_END_FIELDS
};
static ei_register_info ei[] = {
{ &ei_user_encap_not_handled, { "user_dlt.not_handled", PI_UNDECODED, PI_WARN, "Formatted text", EXPFILL }},
};
proto_user_encap = proto_register_protocol("DLT User","DLT_USER","user_dlt");
expert_user_encap = expert_register_protocol(proto_user_encap);
expert_register_field_array(expert_user_encap, ei, array_length(ei));
module = prefs_register_protocol(proto_user_encap, NULL);
encaps_uat = uat_new("User DLTs Table",
sizeof(user_encap_t),
"user_dlts",
TRUE,
&encaps,
&num_encaps,
UAT_AFFECTS_DISSECTION,
"ChUserDLTsSection",
user_copy_cb,
NULL,
user_free_cb,
NULL,
user_flds );
prefs_register_uat_preference(module,
"encaps_table",
"Encapsulations Table",
"A table that enumerates the various protocols to be used against a certain user DLT",
encaps_uat);
register_dissector("user_dlt",dissect_user,proto_user_encap);
exported_pdu_tap = register_export_pdu_tap("DLT User");
}
