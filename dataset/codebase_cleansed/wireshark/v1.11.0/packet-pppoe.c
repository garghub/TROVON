static void
dissect_pppoe_subtags_dslf(tvbuff_t *tvb, packet_info *pinfo _U_, int offset, proto_tree *tree,
int payload_length)
{
guint8 poe_tag;
guint8 poe_tag_length;
int tagstart;
proto_tree *pppoe_tree, *ti, *encaps_tree;
if (tree)
{
ti = proto_tree_add_item(tree, hf_pppoed_tag_vspec_tags, tvb, offset, payload_length, ENC_NA);
pppoe_tree = proto_item_add_subtree(ti, ett_pppoed_tags);
tagstart = offset;
while (tagstart <= offset + payload_length-2)
{
poe_tag = tvb_get_guint8(tvb, tagstart);
poe_tag_length = tvb_get_guint8(tvb, tagstart + 1);
if (global_pppoe_show_tags_and_lengths)
{
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_vspec_tag, tvb, tagstart, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_length_8, tvb, tagstart+1, 1, ENC_BIG_ENDIAN);
}
switch (poe_tag)
{
CASE_VSPEC_DSLF_TAG_STRING(PPPOE_TAG_VSPEC_DSLF_CIRCUIT_ID, <=, 63,
hf_pppoed_tag_vspec_circuit_id)
CASE_VSPEC_DSLF_TAG_STRING(PPPOE_TAG_VSPEC_DSLF_REMOTE_ID, <=, 63,
hf_pppoed_tag_vspec_remote_id)
CASE_VSPEC_DSLF_TAG_UINT(PPPOE_TAG_VSPEC_DSLF_ACT_DATA_RATE_UP, ==, 4,
hf_pppoed_tag_vspec_act_data_rate_up)
CASE_VSPEC_DSLF_TAG_UINT(PPPOE_TAG_VSPEC_DSLF_ACT_DATA_RATE_DOWN, ==, 4,
hf_pppoed_tag_vspec_act_data_rate_down)
CASE_VSPEC_DSLF_TAG_UINT(PPPOE_TAG_VSPEC_DSLF_MIN_DATA_RATE_UP, ==, 4,
hf_pppoed_tag_vspec_min_data_rate_up)
CASE_VSPEC_DSLF_TAG_UINT(PPPOE_TAG_VSPEC_DSLF_MIN_DATA_RATE_DOWN, ==, 4,
hf_pppoed_tag_vspec_min_data_rate_down)
CASE_VSPEC_DSLF_TAG_UINT(PPPOE_TAG_VSPEC_DSLF_ATTAINABLE_DATA_RATE_UP, ==, 4,
hf_pppoed_tag_vspec_attainable_data_rate_up)
CASE_VSPEC_DSLF_TAG_UINT(PPPOE_TAG_VSPEC_DSLF_ATTAINABLE_DATA_RATE_DOWN, ==, 4,
hf_pppoed_tag_vspec_attainable_data_rate_down)
CASE_VSPEC_DSLF_TAG_UINT(PPPOE_TAG_VSPEC_DSLF_MAX_DATA_RATE_UP, ==, 4,
hf_pppoed_tag_vspec_max_data_rate_up)
CASE_VSPEC_DSLF_TAG_UINT(PPPOE_TAG_VSPEC_DSLF_MAX_DATA_RATE_DOWN, ==, 4,
hf_pppoed_tag_vspec_max_data_rate_down)
CASE_VSPEC_DSLF_TAG_UINT(PPPOE_TAG_VSPEC_DSLF_MIN_DATA_RATE_UP_LP, ==, 4,
hf_pppoed_tag_vspec_min_data_rate_up_lp)
CASE_VSPEC_DSLF_TAG_UINT(PPPOE_TAG_VSPEC_DSLF_MIN_DATA_RATE_DOWN_LP, ==, 4,
hf_pppoed_tag_vspec_min_data_rate_down_lp)
CASE_VSPEC_DSLF_TAG_UINT(PPPOE_TAG_VSPEC_DSLF_MAX_INT_DELAY_UP, ==, 4,
hf_pppoed_tag_vspec_max_int_delay_up)
CASE_VSPEC_DSLF_TAG_UINT(PPPOE_TAG_VSPEC_DSLF_ACT_INT_DELAY_UP, ==, 4,
hf_pppoed_tag_vspec_act_int_delay_up)
CASE_VSPEC_DSLF_TAG_UINT(PPPOE_TAG_VSPEC_DSLF_MAX_INT_DELAY_DOWN, ==, 4,
hf_pppoed_tag_vspec_max_int_delay_down)
CASE_VSPEC_DSLF_TAG_UINT(PPPOE_TAG_VSPEC_DSLF_ACT_INT_DELAY_DOWN, ==, 4,
hf_pppoed_tag_vspec_act_int_delay_down)
case PPPOE_TAG_VSPEC_DSLF_ACCESS_LOOP_ENCAPSULATION:
ti = proto_tree_add_item(pppoe_tree, hf_pppoed_tag_vspec_access_loop_encapsulation, tvb,
tagstart+2, 3, ENC_NA);
if (poe_tag_length != 3) {
expert_add_info_format(pinfo, ti, &ei_pppoe_tag_length, "%s: Wrong length: %u (expected 3)", val_to_str_const(poe_tag, vspec_tag_vals, "Unknown"), poe_tag_length);
}
encaps_tree = proto_item_add_subtree(ti, ett_pppoed_tag_vspec_dslf_access_loop_encaps);
proto_tree_add_item(encaps_tree, hf_pppoed_tag_vspec_access_loop_encap_data_link,
tvb, tagstart+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(encaps_tree, hf_pppoed_tag_vspec_access_loop_encap_encap_1,
tvb, tagstart+3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(encaps_tree, hf_pppoed_tag_vspec_access_loop_encap_encap_2,
tvb, tagstart+4, 1, ENC_BIG_ENDIAN);
break;
default:
if (poe_tag_length > 0 )
{
if (!global_pppoe_show_tags_and_lengths)
{
proto_tree_add_item(pppoe_tree, hf_pppoed_tag, tvb, tagstart, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_length_8, tvb, tagstart+1, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_unknown_data, tvb,
tagstart+1, poe_tag_length, ENC_NA);
}
}
tagstart += (2 + poe_tag_length);
}
}
}
static void
dissect_pppoe_tags(tvbuff_t *tvb, packet_info *pinfo, int offset, proto_tree *tree,
int payload_length)
{
guint16 poe_tag;
guint16 poe_tag_length;
int tagstart;
guint16 poe_rsv = 0;
proto_tree *pppoe_tree;
proto_item *ti;
proto_item *pppoe_tree_tag_length_item = NULL;
proto_item *item;
if (tree)
{
ti = proto_tree_add_item(tree, hf_pppoed_tags, tvb, offset, payload_length-6, ENC_NA);
pppoe_tree = proto_item_add_subtree(ti, ett_pppoed_tags);
tagstart = offset;
while (tagstart <= payload_length-2)
{
poe_tag = tvb_get_ntohs(tvb, tagstart);
poe_tag_length = tvb_get_ntohs(tvb, tagstart + 2);
if (global_pppoe_show_tags_and_lengths)
{
proto_tree_add_item(pppoe_tree, hf_pppoed_tag, tvb, tagstart, 2, ENC_BIG_ENDIAN);
pppoe_tree_tag_length_item =
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_length, tvb, tagstart+2, 2, ENC_BIG_ENDIAN);
}
switch (poe_tag)
{
case PPPOE_TAG_SVC_NAME:
if (poe_tag_length > 0)
{
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_service_name, tvb,
tagstart+4, poe_tag_length, ENC_ASCII|ENC_NA);
}
break;
case PPPOE_TAG_AC_NAME:
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_ac_name, tvb,
tagstart+4, poe_tag_length, ENC_ASCII|ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, " AC-Name='%s'",
tvb_get_string(wmem_packet_scope(), tvb, tagstart+4, poe_tag_length));
break;
case PPPOE_TAG_HOST_UNIQ:
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_host_uniq, tvb,
tagstart+4, poe_tag_length, ENC_NA);
break;
case PPPOE_TAG_AC_COOKIE:
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_ac_cookie, tvb,
tagstart+4, poe_tag_length, ENC_NA);
break;
case PPPOE_TAG_VENDOR:
if (poe_tag_length >= 4)
{
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_vendor_id, tvb,
tagstart+4, 4, ENC_BIG_ENDIAN);
}
if (poe_tag_length > 4)
{
guint32 vendor_id = tvb_get_ntohl(tvb, tagstart+4);
switch (vendor_id)
{
case PPPOE_VENDOR_ID_DSLF:
dissect_pppoe_subtags_dslf(tvb,pinfo,tagstart+4+4,pppoe_tree,poe_tag_length-4);
break;
default:
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_vendor_unspecified, tvb,
tagstart+4+4, poe_tag_length-4, ENC_NA);
}
}
break;
case PPPOE_TAG_CREDITS:
if (poe_tag_length == 4)
{
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_credits_fcn, tvb,
tagstart+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_credits_bcn, tvb,
tagstart+6, 2, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_credits, tvb,
tagstart+4, poe_tag_length, ENC_NA);
}
break;
case PPPOE_TAG_METRICS:
if (poe_tag_length == 10)
{
poe_rsv = tvb_get_ntohs(tvb, tagstart+4);
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_mdr_units, tvb,
tagstart+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_cdr_units, tvb,
tagstart+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_metrics_r, tvb,
tagstart+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_metrics_rlq, tvb,
tagstart+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_metrics_resource, tvb,
tagstart+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_metrics_latency, tvb,
tagstart+8, 2, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(pppoe_tree, hf_pppoed_tag_metrics_curr_drate, tvb,
tagstart+10, 2, ENC_BIG_ENDIAN);
switch ((poe_rsv & PPPOE_CDR_MASK) >> 1)
{
case (PPPOE_SCALE_KBPS):
proto_item_append_text(ti, " kbps");
break;
case (PPPOE_SCALE_MBPS):
proto_item_append_text(ti, " mbps");
break;
case (PPPOE_SCALE_GBPS):
proto_item_append_text(ti, " gbps");
break;
case (PPPOE_SCALE_TBPS):
proto_item_append_text(ti, " tbps");
break;
}
ti = proto_tree_add_item(pppoe_tree, hf_pppoed_tag_metrics_max_drate, tvb,
tagstart+12, 2, ENC_BIG_ENDIAN);
switch ((poe_rsv & PPPOE_MDR_MASK) >> 3)
{
case (PPPOE_SCALE_KBPS):
proto_item_append_text(ti, " kbps");
break;
case (PPPOE_SCALE_MBPS):
proto_item_append_text(ti, " mbps");
break;
case (PPPOE_SCALE_GBPS):
proto_item_append_text(ti, " gbps");
break;
case (PPPOE_SCALE_TBPS):
proto_item_append_text(ti, " tbps");
break;
}
} else {
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_metrics, tvb,
tagstart+4, poe_tag_length, ENC_NA);
}
break;
case PPPOE_TAG_SEQ_NUM:
if (poe_tag_length == 2) {
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_seq_num, tvb,
tagstart+4, poe_tag_length, ENC_BIG_ENDIAN);
} else {
if (global_pppoe_show_tags_and_lengths) {
proto_item_append_text(pppoe_tree_tag_length_item, " [Wrong: should be 2]");
item = pppoe_tree_tag_length_item;
} else {
item = proto_tree_add_text(pppoe_tree, tvb, tagstart+4, poe_tag_length,
"%s: Wrong length: %u (expected 2)",
proto_registrar_get_name(hf_pppoed_tag_seq_num),
poe_tag_length);
}
expert_add_info_format(pinfo, item, &ei_pppoe_tag_length, "Sequence Number tag: Wrong length: %u (expected 2)", poe_tag_length);
}
break;
case PPPOE_TAG_CRED_SCALE:
if (poe_tag_length == 2) {
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_cred_scale, tvb,
tagstart+4, poe_tag_length, ENC_BIG_ENDIAN);
} else {
if (global_pppoe_show_tags_and_lengths) {
proto_item_append_text(pppoe_tree_tag_length_item, " [Wrong: should be 2]");
item = pppoe_tree_tag_length_item;
} else {
item = proto_tree_add_text(pppoe_tree, tvb, tagstart+4, poe_tag_length,
"%s: Wrong length: %u (expected 2)",
proto_registrar_get_name(hf_pppoed_tag_cred_scale),
poe_tag_length);
}
expert_add_info_format(pinfo, item, &ei_pppoe_tag_length, "Credit Scale Factor tag: Wrong length: %u (expected 2)", poe_tag_length);
}
break;
case PPPOE_TAG_RELAY_ID:
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_relay_session_id, tvb,
tagstart+4, poe_tag_length, ENC_NA);
break;
case PPPOE_TAG_HURL:
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_hurl, tvb,
tagstart+4, poe_tag_length, ENC_NA);
break;
case PPPOE_TAG_MOTM:
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_motm, tvb,
tagstart+4, poe_tag_length, ENC_NA);
break;
case PPPOE_TAG_MAX_PAYLD:
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_max_payload, tvb,
tagstart+4, poe_tag_length, ENC_NA);
break;
case PPPOE_TAG_IP_RT_ADD:
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_ip_route_add, tvb,
tagstart+4, poe_tag_length, ENC_NA);
break;
case PPPOE_TAG_SVC_ERR:
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_service_name_error, tvb,
tagstart+4, poe_tag_length, ENC_ASCII|ENC_NA);
break;
case PPPOE_TAG_AC_ERR:
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_ac_system_error, tvb,
tagstart+4, poe_tag_length, ENC_ASCII|ENC_NA);
break;
case PPPOE_TAG_GENERIC_ERR:
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_generic_error, tvb,
tagstart+4, poe_tag_length, ENC_ASCII|ENC_NA);
break;
case PPPOE_TAG_EOL:
return;
default:
if (poe_tag_length > 0 )
{
if (!global_pppoe_show_tags_and_lengths)
{
proto_tree_add_item(pppoe_tree, hf_pppoed_tag, tvb, tagstart, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_length, tvb, tagstart+2, 2, ENC_BIG_ENDIAN);
}
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_unknown_data, tvb,
tagstart+2, poe_tag_length, ENC_NA);
}
}
tagstart += (4 + poe_tag_length);
}
}
}
static void dissect_pppoed(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 pppoe_code;
guint16 reported_payload_length;
proto_tree *pppoe_tree = NULL;
proto_item *ti;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PPPoED");
col_clear(pinfo->cinfo, COL_INFO);
pppoe_code = tvb_get_guint8(tvb, 1);
col_append_str(pinfo->cinfo, COL_INFO, val_to_str_const(pppoe_code, code_vals, "Unknown"));
reported_payload_length = tvb_get_ntohs(tvb, 4);
if (tree)
{
ti = proto_tree_add_item(tree, proto_pppoed, tvb, 0, reported_payload_length+6, ENC_NA);
pppoe_tree = proto_item_add_subtree(ti, ett_pppoed);
proto_tree_add_item(pppoe_tree, hf_pppoe_version, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pppoe_tree, hf_pppoe_type, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pppoe_tree, hf_pppoe_code, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pppoe_tree, hf_pppoe_session_id, tvb, 2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pppoe_tree, hf_pppoe_payload_length, tvb, 4, 2, ENC_BIG_ENDIAN);
}
if (reported_payload_length > 0)
{
dissect_pppoe_tags(tvb, pinfo, 6, pppoe_tree, 6+reported_payload_length);
}
}
void proto_register_pppoed(void)
{
static hf_register_info hf[] =
{
{ &hf_pppoed_tags,
{ "PPPoE Tags", "pppoed.tags", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag,
{ "Tag", "pppoed.tag", FT_UINT16, BASE_HEX,
VALS(tag_vals), 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_length,
{ "Tag Length", "pppoed.tag_length", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_length_8,
{ "Tag Length", "pppoed.tag_length_8", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_unknown_data,
{ "Unknown Data", "pppoed.tag.unknown_data", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_service_name,
{ "Service-Name", "pppoed.tags.service_name", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_ac_name,
{ "AC-Name", "pppoed.tags.ac_name", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_host_uniq,
{ "Host-Uniq", "pppoed.tags.host_uniq", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_ac_cookie,
{ "AC-Cookie", "pppoed.tags.ac_cookie", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vendor_id,
{ "Vendor id", "pppoed.tags.vendor_id", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vendor_unspecified,
{ "Vendor unspecified", "pppoed.tags.vendor_unspecified", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vspec_tags,
{ "Vendor Specific PPPoE Tags", "pppoed.tags.vendorspecific.tags", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vspec_tag,
{ "Tag", "pppoed.tags.vendorspecific.tag", FT_UINT8, BASE_HEX,
VALS(vspec_tag_vals), 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vspec_circuit_id,
{ "Circuit ID", "pppoed.tags.circuit_id", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vspec_remote_id,
{ "Remote ID", "pppoed.tags.remote_id", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vspec_act_data_rate_up,
{ "Actual Data Rate Upstream", "pppoed.tags.act_data_rate_up", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vspec_act_data_rate_down,
{ "Actual Data Rate Downstream", "pppoed.tags.act_data_rate_down", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vspec_min_data_rate_up,
{ "Minimum Data Rate Upstream", "pppoed.tags.min_data_rate_up", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vspec_min_data_rate_down,
{ "Minimum Data Rate Downstream", "pppoed.tags.min_data_rate_down", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vspec_attainable_data_rate_up,
{ "Attainable DataRate Upstream", "pppoed.tags.attainable_data_rate_up", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vspec_attainable_data_rate_down,
{ "Attainable DataRate Downstream", "pppoed.tags.attainable_data_rate_down", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vspec_max_data_rate_up,
{ "Maximum Data Rate Upstream", "pppoed.tags.max_data_rate_up", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vspec_max_data_rate_down,
{ "Maximum Data Rate Downstream", "pppoed.tags.max_data_rate_down", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vspec_min_data_rate_up_lp,
{ "Min DataRate Upstream in low power state", "pppoed.tags.min_data_rate_up_lp", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vspec_min_data_rate_down_lp,
{ "Minimum Data Rate Downstream in low power state", "pppoed.tags.min_data_rate_down_lp", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vspec_max_int_delay_up,
{ "Max Interleaving Delay Upstream", "pppoed.tags.max_int_delay_up", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vspec_act_int_delay_up,
{ "Actual Interleaving Delay Upstream", "pppoed.tags.act_int_delay_up", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vspec_max_int_delay_down,
{ "Maximum Interleaving Delay Downstream", "pppoed.tags.max_int_delay_down", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vspec_act_int_delay_down,
{ "Actual Interleaving Delay Downstream", "pppoed.tags.act_int_delay_down", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vspec_access_loop_encapsulation,
{ "Access-Loop-Encapsulation", "pppoed.tags.access_loop_encap", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vspec_access_loop_encap_data_link,
{ "Data link", "pppoed.tags.access_loop_encap.data_link", FT_UINT8, BASE_HEX,
VALS(vspec_tag_dslf_access_loop_encap_data_link_vals), 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vspec_access_loop_encap_encap_1,
{ "Encaps 1", "pppoed.tags.access_loop_encap.encap_1", FT_UINT8, BASE_HEX,
VALS(vspec_tag_dslf_access_loop_encap_encap_1_vals), 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_vspec_access_loop_encap_encap_2,
{ "Encaps 1", "pppoed.tags.access_loop_encap.encap_2", FT_UINT8, BASE_HEX,
VALS(vspec_tag_dslf_access_loop_encap_encap_2_vals), 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_credits,
{ "Credits", "pppoed.tags.credits", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_credits_fcn,
{ "FCN", "pppoed.tags.credits.fcn", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_credits_bcn,
{ "BCN", "pppoed.tags.credits.bcn", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_metrics,
{ "Metrics", "pppoed.tags.metrics", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_metrics_r,
{ "Receive Only", "pppoed.tags.metrics.r", FT_BOOLEAN, 16,
NULL, PPPOE_RCV_ONLY_MASK, NULL, HFILL
}
},
{ &hf_pppoed_tag_mdr_units,
{ "MDR Units", "pppoed.tags.metrics.mdr_units", FT_UINT16, BASE_HEX,
VALS(datarate_scale_vals), PPPOE_MDR_MASK, NULL, HFILL
}
},
{ &hf_pppoed_tag_cdr_units,
{ "CDR Units", "pppoed.tags.metrics.cdr_units", FT_UINT16, BASE_HEX,
VALS(datarate_scale_vals), PPPOE_CDR_MASK, NULL, HFILL
}
},
{ &hf_pppoed_tag_metrics_rlq,
{ "Relative Link Quality", "pppoed.tags.metrics.rlq", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_metrics_resource,
{ "Resource", "pppoed.tags.metrics.resource", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_metrics_latency,
{ "Latency", "pppoed.tags.metrics.latency", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_metrics_curr_drate,
{ "Curr. datarate", "pppoed.tags.metrics.curr_drate", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_metrics_max_drate,
{ "Max. datarate", "pppoed.tags.metrics.max_drate", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_seq_num,
{ "Sequence Number", "pppoed.tags.seq_num", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_cred_scale,
{ "Credit Scale Factor", "pppoed.tags.credit_scale", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_relay_session_id,
{ "Relay-Session-Id", "pppoed.tags.relay_session_id", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_hurl,
{ "HURL", "pppoed.tags.hurl", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_motm,
{ "MOTM", "pppoed.tags.motm", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_max_payload,
{ "PPP-Max-Payload", "pppoed.tags.max_payload", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_ip_route_add,
{ "IP Route Add", "pppoed.tags.ip_route_add", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_service_name_error,
{ "Service-Name-Error", "pppoed.tags.service_name_error", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_ac_system_error,
{ "AC-System-Error", "pppoed.tags.ac_system_error", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoed_tag_generic_error,
{ "Generic-Error", "pppoed.tags.generic_error", FT_STRING, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
}
};
static gint *ett[] = {
&ett_pppoed,
&ett_pppoed_tags,
&ett_pppoed_tag_vspec_dslf_access_loop_encaps
};
module_t *pppoed_module;
proto_pppoed = proto_register_protocol("PPP-over-Ethernet Discovery",
"PPPoED", "pppoed");
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_pppoed, hf, array_length(hf));
pppoed_module = prefs_register_protocol(proto_pppoed, NULL);
prefs_register_bool_preference(pppoed_module, "show_tags_and_lengths",
"Show tag values and lengths",
"Show values of tags and lengths of data fields",
&global_pppoe_show_tags_and_lengths);
}
void proto_reg_handoff_pppoed(void)
{
dissector_handle_t pppoed_handle;
pppoed_handle = create_dissector_handle(dissect_pppoed, proto_pppoed);
dissector_add_uint("ethertype", ETHERTYPE_PPPOED, pppoed_handle);
}
static void dissect_pppoes(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 pppoe_code;
guint16 reported_payload_length;
guint16 poe_tag_length;
gint actual_payload_length;
gint length, reported_length;
gint credit_offset = 0, tagstart = 0;
guint16 cp_code;
proto_tree *pppoe_tree;
proto_item *ti = NULL;
tvbuff_t *next_tvb;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PPPoES");
col_clear(pinfo->cinfo, COL_INFO);
pppoe_code = tvb_get_guint8(tvb, 1);
col_add_str(pinfo->cinfo, COL_INFO,
val_to_str_const(pppoe_code, code_vals, "Unknown"));
reported_payload_length = tvb_get_ntohs(tvb, 4);
actual_payload_length = tvb_reported_length_remaining(tvb, 6);
if (tree)
{
ti = proto_tree_add_item(tree, proto_pppoes, tvb, 0, 6, ENC_NA);
pppoe_tree = proto_item_add_subtree(ti, ett_pppoe);
proto_tree_add_item(pppoe_tree, hf_pppoe_version, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pppoe_tree, hf_pppoe_type, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pppoe_tree, hf_pppoe_code, tvb, 1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(pppoe_tree, hf_pppoe_session_id, tvb, 2, 2, ENC_BIG_ENDIAN);
ti = proto_tree_add_item(pppoe_tree, hf_pppoe_payload_length, tvb, 4, 2, ENC_BIG_ENDIAN);
if (PPPOE_TAG_CREDITS == tvb_get_ntohs(tvb, 6))
{
tagstart = 6;
poe_tag_length = tvb_get_ntohs(tvb, tagstart + 2);
ti = proto_tree_add_item(pppoe_tree, hf_pppoes_tags, tvb, tagstart, 8, ENC_NA);
pppoe_tree = proto_item_add_subtree(ti, ett_pppoes_tags);
if (poe_tag_length == 4)
{
proto_tree_add_item(pppoe_tree, hf_pppoes_tag_credits_fcn, tvb,
tagstart+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(pppoe_tree, hf_pppoes_tag_credits_bcn, tvb,
tagstart+6, 2, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(pppoe_tree, hf_pppoed_tag_credits, tvb,
tagstart+4, poe_tag_length, ENC_NA);
}
credit_offset = 8;
}
}
if (tvb_reported_length(tvb) > 46) {
cp_code = tvb_get_ntohs(tvb, 6);
if ((cp_code != PPP_LCP) && (cp_code != PPP_IPCP) &&
(reported_payload_length != actual_payload_length) &&
((reported_payload_length + 4) != actual_payload_length)) {
proto_item_append_text(ti, " [incorrect, should be %u]",
actual_payload_length);
expert_add_info_format(pinfo, ti, &ei_pppoe_payload_length, "Possible bad payload length %u != %u", reported_payload_length, actual_payload_length);
}
}
length = tvb_length_remaining(tvb, 6);
reported_length = tvb_reported_length_remaining(tvb, 6);
DISSECTOR_ASSERT(length >= 0);
DISSECTOR_ASSERT(reported_length >= 0);
if (length > reported_length)
length = reported_length;
if ((guint)length > reported_payload_length)
length = reported_payload_length;
if ((guint)reported_length > reported_payload_length)
reported_length = reported_payload_length;
next_tvb = tvb_new_subset(tvb,(6 + credit_offset),
(length - credit_offset),
(reported_length - credit_offset));
call_dissector(ppp_handle,next_tvb,pinfo,tree);
}
void proto_register_pppoes(void)
{
static hf_register_info hf[] =
{
{ &hf_pppoes_tags,
{ "PPPoE Tags", "pppoes.tags", FT_NONE, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
#if 0
{ &hf_pppoes_tag,
{ "Tag", "pppoes.tag", FT_UINT16, BASE_HEX,
VALS(tag_vals), 0x0, NULL, HFILL
}
},
#endif
#if 0
{ &hf_pppoes_tag_credits,
{ "Credits", "pppoes.tags.credits", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL
}
},
#endif
{ &hf_pppoes_tag_credits_fcn,
{ "FCN", "pppoes.tags.credits.fcn", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoes_tag_credits_bcn,
{ "BCN", "pppoes.tags.credits.bcn", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
}
};
static gint *ett[] = {
&ett_pppoes,
&ett_pppoes_tags
};
proto_pppoes = proto_register_protocol("PPP-over-Ethernet Session", "PPPoES", "pppoes");
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_pppoes, hf, array_length(hf));
}
void proto_register_pppoe(void)
{
static hf_register_info hf[] =
{
{ &hf_pppoe_version,
{ "Version", "pppoe.version", FT_UINT8, BASE_DEC,
NULL, 0xf0, NULL, HFILL
}
},
{ &hf_pppoe_type,
{ "Type", "pppoe.type", FT_UINT8, BASE_DEC,
NULL, 0x0f, NULL, HFILL
}
},
{ &hf_pppoe_code,
{ "Code", "pppoe.code", FT_UINT8, BASE_HEX,
VALS(code_vals), 0x0, NULL, HFILL
}
},
{ &hf_pppoe_session_id,
{ "Session ID", "pppoe.session_id", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL
}
},
{ &hf_pppoe_payload_length,
{ "Payload Length", "pppoe.payload_length", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL
}
}
};
static gint *ett[] = {
&ett_pppoe
};
static ei_register_info ei[] = {
{ &ei_pppoe_tag_length, { "pppoed.tag_length.invalid", PI_MALFORMED, PI_WARN, "Wrong length", EXPFILL }},
{ &ei_pppoe_payload_length, { "pppoe.payload_length.bad", PI_MALFORMED, PI_WARN, "Possible bad payload length", EXPFILL }},
};
expert_module_t* expert_pppoe;
proto_pppoe = proto_register_protocol("PPP-over-Ethernet", "PPPoE", "pppoe");
proto_register_subtree_array(ett, array_length(ett));
proto_register_field_array(proto_pppoe, hf, array_length(hf));
expert_pppoe = expert_register_protocol(proto_pppoe);
expert_register_field_array(expert_pppoe, ei, array_length(ei));
}
void proto_reg_handoff_pppoes(void)
{
dissector_handle_t pppoes_handle =
create_dissector_handle(dissect_pppoes, proto_pppoes);
dissector_add_uint("ethertype", ETHERTYPE_PPPOES, pppoes_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_PPP_ETHER, pppoes_handle);
ppp_handle = find_dissector("ppp");
}
