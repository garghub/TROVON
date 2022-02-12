static void
dissect_zbee_zcl_appl_idt(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_)
{
return;
}
void
dissect_zcl_appl_idt_attr_id(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id)
{
proto_tree_add_item(tree, hf_zbee_zcl_appl_idt_attr_id, tvb, *offset, 2, attr_id);
}
void
dissect_zcl_appl_idt_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
proto_item *ti = NULL;
proto_tree *sub_tree = NULL;
guint64 value64;
switch ( attr_id ) {
case ZBEE_ZCL_ATTR_ID_APPL_IDT_BASIC_IDENT:
value64 = tvb_get_letoh56(tvb, *offset);
ti = proto_tree_add_text(tree, tvb, *offset, 8, "Basic Identification: 0x%" G_GINT64_MODIFIER "x", value64);
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_appl_idt_basic);
proto_tree_add_item(sub_tree, hf_zbee_zcl_appl_idt_company_id, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(sub_tree, hf_zbee_zcl_appl_idt_brand_id, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(sub_tree, hf_zbee_zcl_appl_idt_prod_type_id, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
proto_tree_add_item(sub_tree, hf_zbee_zcl_appl_idt_ceced_spec_ver, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
case ZBEE_ZCL_ATTR_ID_APPL_IDT_COMPANY_ID:
proto_tree_add_item(tree, hf_zbee_zcl_appl_idt_company_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_APPL_IDT_BRAND_ID:
proto_tree_add_item(tree, hf_zbee_zcl_appl_idt_brand_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_APPL_IDT_PROD_TYPE_NAME:
proto_tree_add_item(tree, hf_zbee_zcl_appl_idt_string_len, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_appl_idt_prod_type_name, tvb, *offset, 2, ENC_BIG_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_APPL_IDT_PROD_TYPE_ID:
proto_tree_add_item(tree, hf_zbee_zcl_appl_idt_prod_type_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_APPL_IDT_CECED_SPEC_VER:
proto_tree_add_item(tree, hf_zbee_zcl_appl_idt_ceced_spec_ver, tvb, *offset, 1, ENC_NA);
*offset += 1;
break;
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_appl_idt(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_appl_idt_attr_id,
{ "Attribute", "zbee_zcl_ha.applident.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_appl_idt_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_appl_idt_company_id,
{ "Company ID", "zbee_zcl_ha.applident.attr.company.id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_appl_idt_company_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_appl_idt_brand_id,
{ "Brand ID", "zbee_zcl_ha.applident.attr.brand.id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_appl_idt_brand_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_appl_idt_string_len,
{ "Length", "zbee_zcl_ha.applident.string.len", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_appl_idt_prod_type_name,
{ "Product Type Name", "zbee_zcl_ha.applident.attr.prod_type.name", FT_UINT16, BASE_HEX, VALS(zbee_zcl_appl_idt_prod_type_name_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_appl_idt_prod_type_id,
{ "Product Type ID", "zbee_zcl_ha.applident.attr.prod_type.id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_appl_idt_prod_type_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_appl_idt_ceced_spec_ver,
{ "CECED Spec. Version", "zbee_zcl_ha.applident.attr.ceced_spec_ver", FT_UINT8, BASE_HEX, VALS(zbee_zcl_appl_idt_ceced_spec_ver_names),
0x00, NULL, HFILL } }
};
gint *ett[ZBEE_ZCL_APPL_IDT_NUM_ETT];
ett[0] = &ett_zbee_zcl_appl_idt;
ett[1] = &ett_zbee_zcl_appl_idt_basic;
proto_zbee_zcl_appl_idt = proto_register_protocol("ZigBee ZCL Appliance Identification", "ZCL Appliance Identification", ZBEE_PROTOABBREV_ZCL_APPLIDT);
proto_register_field_array(proto_zbee_zcl_appl_idt, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_APPLIDT, dissect_zbee_zcl_appl_idt, proto_zbee_zcl_appl_idt);
}
void
proto_reg_handoff_zbee_zcl_appl_idt(void)
{
zbee_zcl_init_cluster( proto_zbee_zcl_appl_idt,
ett_zbee_zcl_appl_idt,
ZBEE_ZCL_CID_APPLIANCE_IDENTIFICATION,
(zbee_zcl_fn_attr_id)dissect_zcl_appl_idt_attr_id,
(zbee_zcl_fn_attr_data)dissect_zcl_appl_idt_attr_data
);
}
static void
dissect_zbee_zcl_met_idt(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_)
{
return;
}
void
dissect_zcl_met_idt_attr_id(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id)
{
proto_tree_add_item(tree, hf_zbee_zcl_met_idt_attr_id, tvb, *offset, 2, attr_id);
}
void
dissect_zcl_met_idt_attr_data(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id, guint data_type)
{
switch ( attr_id ) {
case ZBEE_ZCL_ATTR_ID_MET_IDT_METER_TYPE_ID:
proto_tree_add_item(tree, hf_zbee_zcl_met_idt_meter_type_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
case ZBEE_ZCL_ATTR_ID_MET_IDT_DATA_QUALITY_ID:
proto_tree_add_item(tree, hf_zbee_zcl_met_idt_data_quality_id, tvb, *offset, 2, ENC_LITTLE_ENDIAN);
*offset += 2;
break;
default:
dissect_zcl_attr_data(tvb, tree, offset, data_type);
break;
}
}
void
proto_register_zbee_zcl_met_idt(void)
{
static hf_register_info hf[] = {
{ &hf_zbee_zcl_met_idt_attr_id,
{ "Attribute", "zbee_zcl_ha.metidt.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_met_idt_attr_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_met_idt_meter_type_id,
{ "Meter Type ID", "zbee_zcl_ha.metidt.attr.meter_type.id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_met_idt_meter_type_names),
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_met_idt_data_quality_id,
{ "Data Quality ID", "zbee_zcl_ha.metidt.attr.data_quality.id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_met_idt_data_quality_names),
0x00, NULL, HFILL } }
};
proto_zbee_zcl_met_idt = proto_register_protocol("ZigBee ZCL Meter Identification", "ZCL Meter Identification", ZBEE_PROTOABBREV_ZCL_METIDT);
proto_register_field_array(proto_zbee_zcl_met_idt, hf, array_length(hf));
register_dissector(ZBEE_PROTOABBREV_ZCL_METIDT, dissect_zbee_zcl_met_idt, proto_zbee_zcl_met_idt);
}
void
proto_reg_handoff_zbee_zcl_met_idt(void)
{
zbee_zcl_init_cluster( proto_zbee_zcl_met_idt,
ett_zbee_zcl_met_idt,
ZBEE_ZCL_CID_METER_IDENTIFICATION,
(zbee_zcl_fn_attr_id)dissect_zcl_met_idt_attr_id,
(zbee_zcl_fn_attr_data)dissect_zcl_met_idt_attr_data
);
}
static void
dissect_zbee_zcl_appl_evtalt(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *payload_root;
proto_tree *payload_tree;
zbee_zcl_packet *zcl = (zbee_zcl_packet *)pinfo->private_data;
guint offset = 0;
guint8 cmd_id = zcl->cmd_id;
gint rem_len;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_appl_evtalt_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_appl_evtalt_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
proto_tree_add_text(tree, tvb, offset, rem_len, "Payload");
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_APPL_EVTALT_GET_ALERTS_CMD:
break;
default:
break;
}
}
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_appl_evtalt_srv_tx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_appl_evtalt_srv_tx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_root = proto_tree_add_text(tree, tvb, offset, rem_len, "Payload");
payload_tree = proto_item_add_subtree(payload_root, ett_zbee_zcl_appl_evtalt);
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_APPL_EVTALT_GET_ALERTS_RSP_CMD:
case ZBEE_ZCL_CMD_ID_APPL_EVTALT_ALERTS_NOTIF_CMD:
dissect_zcl_appl_evtalt_get_alerts_rsp(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_APPL_EVTALT_EVENT_NOTIF_CMD:
dissect_zcl_appl_evtalt_event_notif(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
}
static void
dissect_zcl_appl_evtalt_alerts_struct(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_appl_evtalt_alert_id, tvb, *offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_zbee_zcl_appl_evtalt_category, tvb, *offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_zbee_zcl_appl_evtalt_status, tvb, *offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_zbee_zcl_appl_evtalt_reserved, tvb, *offset, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_zbee_zcl_appl_evtalt_proprietary, tvb, *offset, 3, ENC_BIG_ENDIAN);
*offset += 3;
}
static void
dissect_zcl_appl_evtalt_get_alerts_rsp(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_item *ti = NULL;
proto_tree *sub_tree = NULL;
guint i;
guint8 count;
count = tvb_get_guint8(tvb, *offset) & ZBEE_ZCL_APPL_EVTALT_COUNT_NUM_MASK;
proto_tree_add_text(tree, tvb, *offset, 1, "Alert Count: 0x%02x", count);
proto_tree_add_item(tree, hf_zbee_zcl_appl_evtalt_count_num, tvb, *offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_zbee_zcl_appl_evtalt_count_type, tvb, *offset, 1, ENC_NA);
*offset += 1;
for ( i=0 ; i<count ; i++)
{
ti = proto_tree_add_text(tree, tvb, *offset, 1, "Alerts Structure #%u", i);
sub_tree = proto_item_add_subtree(ti, ett_zbee_zcl_appl_evtalt_alerts_struct[i]);
dissect_zcl_appl_evtalt_alerts_struct(tvb, sub_tree, offset);
}
}
static void
dissect_zcl_appl_evtalt_event_notif(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_appl_evtalt_event_hdr, tvb, *offset, 1, ENC_NA);
*offset += 1;
proto_tree_add_item(tree, hf_zbee_zcl_appl_evtalt_event_id, tvb, *offset, 1, ENC_NA);
*offset += 1;
}
void proto_register_zbee_zcl_appl_evtalt
(
void
)
{
guint i, j;
static hf_register_info hf[] = {
{ &hf_zbee_zcl_appl_evtalt_srv_tx_cmd_id,
{ "Command", "zbee_zcl_ha.applevtalt.cmd.srv_tx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_appl_evtalt_srv_tx_cmd_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_appl_evtalt_srv_rx_cmd_id,
{ "Command", "zbee_zcl_ha.applevtalt.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_appl_evtalt_srv_rx_cmd_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_appl_evtalt_count_num,
{ "Number of Alerts", "zbee_zcl_ha.applevtalt.count.num", FT_UINT8, BASE_DEC, NULL,
ZBEE_ZCL_APPL_EVTALT_COUNT_NUM_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_appl_evtalt_count_type,
{ "Type of Alerts", "zbee_zcl_ha.applevtalt.count.type", FT_UINT8, BASE_DEC, NULL,
ZBEE_ZCL_APPL_EVTALT_COUNT_TYPE_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_appl_evtalt_alert_id,
{ "Alert Id", "zbee_zcl_ha.applevtalt.alert_id", FT_UINT24, BASE_HEX, NULL,
ZBEE_ZCL_APPL_EVTALT_ALERT_ID_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_appl_evtalt_category,
{ "Category", "zbee_zcl_ha.applevtalt.category", FT_UINT24, BASE_HEX, VALS(zbee_zcl_appl_evtalt_category_names),
ZBEE_ZCL_APPL_EVTALT_CATEGORY_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_appl_evtalt_status,
{ "Status", "zbee_zcl_ha.applevtalt.status", FT_UINT24, BASE_HEX, VALS(zbee_zcl_appl_evtalt_status_names),
ZBEE_ZCL_APPL_EVTALT_STATUS_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_appl_evtalt_reserved,
{ "Reserved", "zbee_zcl_ha.applevtalt.reserved", FT_UINT24, BASE_HEX, NULL,
ZBEE_ZCL_APPL_EVTALT_RESERVED_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_appl_evtalt_proprietary,
{ "Proprietary", "zbee_zcl_ha.applevtalt.proprietary", FT_UINT24, BASE_HEX, NULL,
ZBEE_ZCL_APPL_EVTALT_PROPRIETARY_MASK, NULL, HFILL } },
{ &hf_zbee_zcl_appl_evtalt_event_hdr,
{ "Event Header", "zbee_zcl_ha.applevtalt.event.header", FT_UINT8, BASE_HEX, NULL,
0x00, NULL, HFILL } },
{ &hf_zbee_zcl_appl_evtalt_event_id,
{ "Event Id", "zbee_zcl_ha.applevtalt.event.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_appl_evtalt_event_id_names),
0x00, NULL, HFILL } }
};
gint *ett[ZBEE_ZCL_APPL_EVTALT_NUM_ETT];
ett[0] = &ett_zbee_zcl_appl_evtalt;
for ( i = 0, j = ZBEE_ZCL_APPL_EVTALT_NUM_GENERIC_ETT; i < ZBEE_ZCL_APPL_EVTALT_NUM_STRUCT_ETT; i++, j++) {
ett_zbee_zcl_appl_evtalt_alerts_struct[i] = -1;
ett[j] = &ett_zbee_zcl_appl_evtalt_alerts_struct[i];
}
proto_zbee_zcl_appl_evtalt = proto_register_protocol("ZigBee ZCL Appliance Events & Alert", "ZCL Appliance Events & Alert", ZBEE_PROTOABBREV_ZCL_APPLEVTALT);
proto_register_field_array(proto_zbee_zcl_appl_evtalt, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_APPLEVTALT, dissect_zbee_zcl_appl_evtalt, proto_zbee_zcl_appl_evtalt);
}
void
proto_reg_handoff_zbee_zcl_appl_evtalt(void)
{
dissector_handle_t appl_evtalt_handle;
appl_evtalt_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_APPLEVTALT);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_APPLIANCE_EVENTS_AND_ALERT, appl_evtalt_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_appl_evtalt,
ett_zbee_zcl_appl_evtalt,
ZBEE_ZCL_CID_APPLIANCE_EVENTS_AND_ALERT,
NULL,
NULL
);
}
static void
dissect_zbee_zcl_appl_stats (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *payload_root;
proto_tree *payload_tree;
zbee_zcl_packet *zcl = (zbee_zcl_packet *)pinfo->private_data;
guint offset = 0;
guint8 cmd_id = zcl->cmd_id;
gint rem_len;
if (zcl->direction == ZBEE_ZCL_FCF_TO_SERVER) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_appl_stats_srv_rx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_appl_stats_srv_rx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_root = proto_tree_add_text(tree, tvb, offset, rem_len, "Payload");
payload_tree = proto_item_add_subtree(payload_root, ett_zbee_zcl_appl_stats);
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_APPL_STATS_LOG_REQ:
dissect_zcl_appl_stats_log_req(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_APPL_STATS_LOG_QUEUE_REQ:
break;
default:
break;
}
}
}
else {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s, Seq: %u",
val_to_str_const(cmd_id, zbee_zcl_appl_stats_srv_tx_cmd_names, "Unknown Command"),
zcl->tran_seqno);
proto_tree_add_item(tree, hf_zbee_zcl_appl_stats_srv_tx_cmd_id, tvb, offset, 1, cmd_id);
rem_len = tvb_reported_length_remaining(tvb, ++offset);
if (rem_len > 0) {
payload_root = proto_tree_add_text(tree, tvb, offset, rem_len, "Payload");
payload_tree = proto_item_add_subtree(payload_root, ett_zbee_zcl_appl_stats);
switch (cmd_id) {
case ZBEE_ZCL_CMD_ID_APPL_STATS_LOG_NOTIF:
case ZBEE_ZCL_CMD_ID_APPL_STATS_LOG_RSP:
dissect_zcl_appl_stats_log_rsp(tvb, payload_tree, &offset);
break;
case ZBEE_ZCL_CMD_ID_APPL_STATS_LOG_QUEUE_RSP:
case ZBEE_ZCL_CMD_ID_APPL_STATS_STATS_AVAILABLE:
dissect_zcl_appl_stats_log_queue_rsp(tvb, payload_tree, &offset);
break;
default:
break;
}
}
}
}
static void
dissect_zcl_appl_stats_log_req(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
proto_tree_add_item(tree, hf_zbee_zcl_appl_stats_log_id, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
}
static void
dissect_zcl_appl_stats_log_rsp(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
guint32 log_len;
guint8 *log_data;
proto_tree_add_item(tree, hf_zbee_zcl_appl_stats_utc_time, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
proto_tree_add_item(tree, hf_zbee_zcl_appl_stats_log_id, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
log_len = tvb_get_letohl(tvb, *offset);
proto_tree_add_item(tree, hf_zbee_zcl_appl_stats_log_length, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
log_data = tvb_bytes_to_str_punct(tvb, *offset, log_len, ':');
proto_tree_add_string(tree, hf_zbee_zcl_appl_stats_log_payload, tvb, *offset, log_len, log_data);
*offset += log_len;
}
static void
dissect_zcl_appl_stats_log_queue_rsp(tvbuff_t *tvb, proto_tree *tree, guint *offset)
{
gint list_len;
proto_tree_add_item(tree, hf_zbee_zcl_appl_stats_log_queue_size, tvb, *offset, 1, ENC_NA);
*offset += 1;
list_len = tvb_reported_length_remaining(tvb, *offset);
if ( list_len > 0 ) {
while ( *offset < (guint)list_len ) {
proto_tree_add_item(tree, hf_zbee_zcl_appl_stats_log_id, tvb, *offset, 4, ENC_LITTLE_ENDIAN);
*offset += 4;
}
}
}
static void
dissect_zcl_appl_stats_attr_id(proto_tree *tree, tvbuff_t *tvb, guint *offset, guint16 attr_id)
{
proto_tree_add_item(tree, hf_zbee_zcl_appl_stats_attr_id, tvb, *offset, 2, attr_id);
}
static void
decode_zcl_appl_stats_utc_time(gchar *s, guint32 value)
{
if (value == ZBEE_ZCL_APPL_STATS_INVALID_TIME)
g_snprintf(s, ITEM_LABEL_LENGTH, "Invalid UTC Time");
else {
value += ZBEE_ZCL_NSTIME_UTC_OFFSET;
g_snprintf(s, ITEM_LABEL_LENGTH, "%s", abs_time_secs_to_str (value, ABSOLUTE_TIME_LOCAL, TRUE));
}
}
void
proto_register_zbee_zcl_appl_stats(void)
{
guint i, j;
static hf_register_info hf[] = {
{ &hf_zbee_zcl_appl_stats_attr_id,
{ "Attribute", "zbee_zcl_ha.applstats.attr_id", FT_UINT16, BASE_HEX, VALS(zbee_zcl_appl_stats_attr_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_appl_stats_srv_tx_cmd_id,
{ "Command", "zbee_zcl_ha.applstats.cmd.srv_tx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_appl_stats_srv_tx_cmd_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_appl_stats_srv_rx_cmd_id,
{ "Command", "zbee_zcl_ha.applstats.cmd.srv_rx.id", FT_UINT8, BASE_HEX, VALS(zbee_zcl_appl_stats_srv_rx_cmd_names),
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_appl_stats_utc_time,
{ "UTC Time", "zbee_zcl_ha.applstats.utc_time", FT_UINT32, BASE_CUSTOM, decode_zcl_appl_stats_utc_time,
0x0, NULL, HFILL }},
{ &hf_zbee_zcl_appl_stats_log_length,
{ "Log Length", "zbee_zcl_ha.applstats.log.length", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_appl_stats_log_id,
{ "Log ID", "zbee_zcl_ha.applstats.log.id", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_appl_stats_log_queue_size,
{ "Log Queue Size", "zbee_zcl_ha.applstats.log_queue_size", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL } },
{ &hf_zbee_zcl_appl_stats_log_payload,
{ "Log Payload", "zbee_zcl_ha.applstats.log.payload", FT_STRING, BASE_NONE, NULL,
0x00, NULL, HFILL } },
};
static gint *ett[ZBEE_ZCL_APPL_STATS_NUM_ETT];
ett[0] = &ett_zbee_zcl_appl_stats;
for ( i = 0, j = ZBEE_ZCL_APPL_STATS_NUM_GENERIC_ETT; i < ZBEE_ZCL_APPL_STATS_NUM_LOGS_ETT; i++, j++ ) {
ett_zbee_zcl_appl_stats_logs[i] = -1;
ett[j] = &ett_zbee_zcl_appl_stats_logs[i];
}
proto_zbee_zcl_appl_stats = proto_register_protocol("ZigBee ZCL Appliance Statistics", "ZCL Appliance Statistics", ZBEE_PROTOABBREV_ZCL_APPLSTATS);
proto_register_field_array(proto_zbee_zcl_appl_stats, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector(ZBEE_PROTOABBREV_ZCL_APPLSTATS, dissect_zbee_zcl_appl_stats, proto_zbee_zcl_appl_stats);
}
void
proto_reg_handoff_zbee_zcl_appl_stats(void)
{
dissector_handle_t appl_stats_handle;
appl_stats_handle = find_dissector(ZBEE_PROTOABBREV_ZCL_APPLSTATS);
dissector_add_uint("zbee.zcl.cluster", ZBEE_ZCL_CID_APPLIANCE_STATISTICS, appl_stats_handle);
zbee_zcl_init_cluster( proto_zbee_zcl_appl_stats,
ett_zbee_zcl_appl_stats,
ZBEE_ZCL_CID_APPLIANCE_STATISTICS,
(zbee_zcl_fn_attr_id)dissect_zcl_appl_stats_attr_id,
NULL
);
}
