static void
ouch_tree_add_timestamp(
proto_tree *tree,
const int hf,
tvbuff_t *tvb,
gint offset)
{
guint64 ts = tvb_get_ntoh64(tvb, offset);
char *buf = (char *)wmem_alloc(wmem_packet_scope(), ITEM_LABEL_LENGTH);
guint32 tmp, hours, mins, secs, nsecs;
nsecs = (guint32)(ts % G_GUINT64_CONSTANT(1000000000));
tmp = (guint32)(ts / G_GUINT64_CONSTANT(1000000000));
hours = tmp / 3600;
mins = (tmp % 3600) / 60;
secs = tmp % 60;
g_snprintf(buf, ITEM_LABEL_LENGTH,
"%u:%02u:%02u.%09u",
hours, mins, secs, nsecs);
proto_tree_add_string(tree, hf, tvb, offset, 8, buf);
}
static void
format_bbo_weight_indicator(
gchar *buf,
guint32 value)
{
g_snprintf(buf, ITEM_LABEL_LENGTH,
"%s (%c)",
val_to_str_const(value,
ouch_bbo_weight_indicator_val,
"Unknown"),
value);
}
static void
format_broken_trade_reason(
gchar *buf,
guint32 value)
{
g_snprintf(buf, ITEM_LABEL_LENGTH,
"%s (%c)",
val_to_str_const(value,
ouch_broken_trade_reason_val,
"Unknown"),
value);
}
static void
format_buy_sell_indicator(
gchar *buf,
guint32 value)
{
g_snprintf(buf, ITEM_LABEL_LENGTH,
"%s (%c)",
val_to_str_const(value, ouch_buy_sell_indicator_val, "Unknown"),
value);
}
static void
format_cancel_reason(
gchar *buf,
guint32 value)
{
g_snprintf(buf, ITEM_LABEL_LENGTH,
"%s (%c)",
val_to_str_const(value, ouch_cancel_reason_val, "Unknown"),
value);
}
static void
format_capacity(
char *buf,
guint32 value)
{
g_snprintf(buf, ITEM_LABEL_LENGTH,
"%s (%c)",
val_to_str_const(value, ouch_capacity_val, "Unknown"),
value);
}
static void
format_cross_type(
char *buf,
guint32 value)
{
g_snprintf(buf, ITEM_LABEL_LENGTH,
"%s (%c)",
val_to_str_const(value, ouch_cross_type_val, "Unknown"),
value);
}
static void
format_customer_type(
char *buf,
guint32 value)
{
g_snprintf(buf, ITEM_LABEL_LENGTH,
"%s (%c)",
val_to_str_const(value, ouch_customer_type_val, "Unknown"),
value);
}
static void
format_display(
char *buf,
guint32 value)
{
g_snprintf(buf, ITEM_LABEL_LENGTH,
"%s (%c)",
val_to_str_const(value, ouch_display_val, "Unknown"),
value);
}
static void
format_event_code(
char *buf,
guint32 value)
{
g_snprintf(buf, ITEM_LABEL_LENGTH,
"%s (%c)",
val_to_str_const(value, ouch_event_code_val, "Unknown"),
value);
}
static void
format_iso_eligibility(
char *buf,
guint32 value)
{
g_snprintf(buf, ITEM_LABEL_LENGTH,
"%s (%c)",
val_to_str_const(value, ouch_iso_eligibility_val, "Unknown"),
value);
}
static void
format_liquidity_flag(
char *buf,
guint32 value)
{
g_snprintf(buf, ITEM_LABEL_LENGTH,
"%s (%c)",
val_to_str_const(value, ouch_liquidity_flag_val, "Unknown"),
value);
}
static void
format_order_state(
char *buf,
guint32 value)
{
g_snprintf(buf, ITEM_LABEL_LENGTH,
"%s (%c)",
val_to_str_const(value, ouch_order_state_val, "Unknown"),
value);
}
static void
format_packet_type(
char *buf,
guint32 value)
{
g_snprintf(buf, ITEM_LABEL_LENGTH,
"%s (%c)",
val_to_str_const(value, pkt_type_val, "Unknown"),
value);
}
static void
format_price(
char *buf,
guint32 value)
{
g_snprintf(buf, ITEM_LABEL_LENGTH,
"$%u.%04u",
value / 10000, value % 10000);
}
static void
format_price_correction_reason(
char *buf,
guint32 value)
{
g_snprintf(buf, ITEM_LABEL_LENGTH,
"%s (%c)",
val_to_str_const(value,
ouch_price_correction_reason_val,
"Unknown"),
value);
}
static void
format_reject_reason(
char *buf,
guint32 value)
{
g_snprintf(buf, ITEM_LABEL_LENGTH,
"%s (%c)",
val_to_str_const(value, ouch_reject_reason_val, "Unknown"),
value);
}
static void
format_tif(
gchar *buf,
guint32 value)
{
guint32 hours;
guint32 mins;
guint32 secs;
switch (value) {
case 0:
g_snprintf(buf, ITEM_LABEL_LENGTH, "Immediate Or Cancel (%u)", value);
break;
case 99998:
g_snprintf(buf, ITEM_LABEL_LENGTH, "Market Hours (%u)", value);
break;
case 99999:
g_snprintf(buf, ITEM_LABEL_LENGTH, "System Hours (%u)", value);
break;
default:
hours = value / 3600;
mins = (value % 3600) / 60;
secs = value % 60;
g_snprintf(buf, ITEM_LABEL_LENGTH,
"%uh %02um %02us (%u seconds)",
hours, mins, secs,
value);
break;
}
}
static int
dissect_ouch(
tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
void *data _U_)
{
proto_item *ti;
proto_tree *ouch_tree = NULL;
const char *pkt_name;
guint16 reported_len;
guint8 pkt_type;
int offset = 0;
pkt_type = tvb_get_guint8(tvb, 0);
reported_len = tvb_reported_length(tvb);
if (pkt_type == 'U' && (reported_len == 79 || reported_len == 80)) {
pkt_type = 'R';
}
pkt_name = val_to_str(pkt_type, pkt_type_val, "Unknown (%u)");
col_set_str(pinfo->cinfo, COL_PROTOCOL, "OUCH");
col_add_str(pinfo->cinfo, COL_INFO, pkt_name);
if (tree) {
ti = proto_tree_add_item(tree,
proto_ouch,
tvb, 0, -1, ENC_NA);
ouch_tree = proto_item_add_subtree(ti, ett_ouch);
proto_item_append_text(ti, ", %s", pkt_name);
proto_tree_add_item(ouch_tree,
hf_ouch_packet_type,
tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
switch (pkt_type) {
case 'O':
proto_tree_add_item(ouch_tree,
hf_ouch_order_token,
tvb, offset, 14,
ENC_ASCII|ENC_NA);
offset += 14;
proto_tree_add_item(ouch_tree,
hf_ouch_buy_sell_indicator,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ouch_tree,
hf_ouch_shares,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_stock,
tvb, offset, 8,
ENC_ASCII|ENC_NA);
offset += 8;
proto_tree_add_item(ouch_tree,
hf_ouch_price,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_tif,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_firm,
tvb, offset, 4,
ENC_ASCII|ENC_NA);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_display,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ouch_tree,
hf_ouch_capacity,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ouch_tree,
hf_ouch_iso_eligible,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ouch_tree,
hf_ouch_min_quantity,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_cross_type,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
if (reported_len == 49) {
proto_tree_add_item(ouch_tree,
hf_ouch_customer_type,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
}
break;
case 'A':
ouch_tree_add_timestamp(ouch_tree,
hf_ouch_timestamp,
tvb, offset);
offset += 8;
proto_tree_add_item(ouch_tree,
hf_ouch_order_token,
tvb, offset, 14,
ENC_ASCII|ENC_NA);
offset += 14;
proto_tree_add_item(ouch_tree,
hf_ouch_buy_sell_indicator,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ouch_tree,
hf_ouch_shares,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_stock,
tvb, offset, 8,
ENC_ASCII|ENC_NA);
offset += 8;
proto_tree_add_item(ouch_tree,
hf_ouch_price,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_tif,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_firm,
tvb, offset, 4,
ENC_ASCII|ENC_NA);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_display,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ouch_tree,
hf_ouch_order_reference_number,
tvb, offset, 8,
ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(ouch_tree,
hf_ouch_capacity,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ouch_tree,
hf_ouch_iso_eligible,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ouch_tree,
hf_ouch_min_quantity,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_cross_type,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ouch_tree,
hf_ouch_order_state,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
if (reported_len == 66) {
proto_tree_add_item(ouch_tree,
hf_ouch_bbo_weight_indicator,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
}
break;
case 'U':
proto_tree_add_item(ouch_tree,
hf_ouch_existing_order_token,
tvb, offset, 14,
ENC_ASCII|ENC_NA);
offset += 14;
proto_tree_add_item(ouch_tree,
hf_ouch_replacement_order_token,
tvb, offset, 14,
ENC_ASCII|ENC_NA);
offset += 14;
proto_tree_add_item(ouch_tree,
hf_ouch_shares,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_price,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_tif,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_display,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ouch_tree,
hf_ouch_iso_eligible,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ouch_tree,
hf_ouch_min_quantity,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
break;
case 'X':
proto_tree_add_item(ouch_tree,
hf_ouch_order_token,
tvb, offset, 14,
ENC_ASCII|ENC_NA);
offset += 14;
proto_tree_add_item(ouch_tree,
hf_ouch_shares,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
break;
case 'M':
proto_tree_add_item(ouch_tree,
hf_ouch_order_token,
tvb, offset, 14,
ENC_ASCII|ENC_NA);
offset += 14;
proto_tree_add_item(ouch_tree,
hf_ouch_buy_sell_indicator,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ouch_tree,
hf_ouch_shares,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
break;
case 'S':
ouch_tree_add_timestamp(ouch_tree,
hf_ouch_timestamp,
tvb, offset);
offset += 8;
proto_tree_add_item(ouch_tree,
hf_ouch_event_code,
tvb, offset, 1,
ENC_ASCII);
offset += 1;
break;
case 'R':
ouch_tree_add_timestamp(ouch_tree,
hf_ouch_timestamp,
tvb, offset);
offset += 8;
proto_tree_add_item(ouch_tree,
hf_ouch_replacement_order_token,
tvb, offset, 14,
ENC_ASCII|ENC_NA);
offset += 14;
proto_tree_add_item(ouch_tree,
hf_ouch_buy_sell_indicator,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ouch_tree,
hf_ouch_shares,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_stock,
tvb, offset, 8,
ENC_ASCII|ENC_NA);
offset += 8;
proto_tree_add_item(ouch_tree,
hf_ouch_price,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_tif,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_firm,
tvb, offset, 4,
ENC_ASCII|ENC_NA);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_display,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ouch_tree,
hf_ouch_order_reference_number,
tvb, offset, 8,
ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(ouch_tree,
hf_ouch_capacity,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ouch_tree,
hf_ouch_iso_eligible,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ouch_tree,
hf_ouch_min_quantity,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_cross_type,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ouch_tree,
hf_ouch_order_state,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ouch_tree,
hf_ouch_previous_order_token,
tvb, offset, 14,
ENC_ASCII|ENC_NA);
offset += 14;
if (reported_len == 80) {
proto_tree_add_item(ouch_tree,
hf_ouch_bbo_weight_indicator,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
}
break;
case 'C':
ouch_tree_add_timestamp(ouch_tree,
hf_ouch_timestamp,
tvb, offset);
offset += 8;
proto_tree_add_item(ouch_tree,
hf_ouch_order_token,
tvb, offset, 14,
ENC_ASCII|ENC_NA);
offset += 14;
proto_tree_add_item(ouch_tree,
hf_ouch_decrement_shares,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_cancel_reason,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
break;
case 'D':
ouch_tree_add_timestamp(ouch_tree,
hf_ouch_timestamp,
tvb, offset);
offset += 8;
proto_tree_add_item(ouch_tree,
hf_ouch_order_token,
tvb, offset, 14,
ENC_ASCII|ENC_NA);
offset += 14;
proto_tree_add_item(ouch_tree,
hf_ouch_decrement_shares,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_cancel_reason,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ouch_tree,
hf_ouch_quantity_prevented_from_trading,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_execution_price,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_liquidity_flag,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
break;
case 'E':
ouch_tree_add_timestamp(ouch_tree,
hf_ouch_timestamp,
tvb, offset);
offset += 8;
proto_tree_add_item(ouch_tree,
hf_ouch_order_token,
tvb, offset, 14,
ENC_ASCII|ENC_NA);
offset += 14;
proto_tree_add_item(ouch_tree,
hf_ouch_executed_shares,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_execution_price,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_liquidity_flag,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(ouch_tree,
hf_ouch_match_number,
tvb, offset, 8,
ENC_BIG_ENDIAN);
offset += 8;
break;
case 'B':
ouch_tree_add_timestamp(ouch_tree,
hf_ouch_timestamp,
tvb, offset);
offset += 8;
proto_tree_add_item(ouch_tree,
hf_ouch_order_token,
tvb, offset, 14,
ENC_ASCII|ENC_NA);
offset += 14;
proto_tree_add_item(ouch_tree,
hf_ouch_match_number,
tvb, offset, 8,
ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(ouch_tree,
hf_ouch_broken_trade_reason,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
break;
case 'K':
ouch_tree_add_timestamp(ouch_tree,
hf_ouch_timestamp,
tvb, offset);
offset += 8;
proto_tree_add_item(ouch_tree,
hf_ouch_order_token,
tvb, offset, 14,
ENC_ASCII|ENC_NA);
offset += 14;
proto_tree_add_item(ouch_tree,
hf_ouch_match_number,
tvb, offset, 8,
ENC_BIG_ENDIAN);
offset += 8;
proto_tree_add_item(ouch_tree,
hf_ouch_new_execution_price,
tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(ouch_tree,
hf_ouch_price_correction_reason,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
break;
case 'J':
ouch_tree_add_timestamp(ouch_tree,
hf_ouch_timestamp,
tvb, offset);
offset += 8;
proto_tree_add_item(ouch_tree,
hf_ouch_order_token,
tvb, offset, 14,
ENC_ASCII|ENC_NA);
offset += 14;
proto_tree_add_item(ouch_tree,
hf_ouch_reject_reason,
tvb, offset, 1,
ENC_BIG_ENDIAN);
offset += 1;
break;
case 'P':
ouch_tree_add_timestamp(ouch_tree,
hf_ouch_timestamp,
tvb, offset);
offset += 8;
proto_tree_add_item(ouch_tree,
hf_ouch_order_token,
tvb, offset, 14,
ENC_ASCII|ENC_NA);
offset += 14;
break;
case 'I':
ouch_tree_add_timestamp(ouch_tree,
hf_ouch_timestamp,
tvb, offset);
offset += 8;
proto_tree_add_item(ouch_tree,
hf_ouch_order_token,
tvb, offset, 14,
ENC_ASCII|ENC_NA);
offset += 14;
break;
default:
proto_tree_add_item(tree,
hf_ouch_message,
tvb, offset, -1, ENC_NA);
offset += reported_len - 1;
break;
}
}
return offset;
}
static void
ouch_prefs(void)
{
dissector_delete_uint_range("tcp.port", ouch_range, ouch_handle);
g_free(ouch_range);
ouch_range = range_copy(global_ouch_range);
dissector_add_uint_range("tcp.port", ouch_range, ouch_handle);
}
static gboolean
dissect_ouch_heur(
tvbuff_t *tvb,
packet_info *pinfo,
proto_tree *tree,
void *data _U_)
{
guint8 msg_type = tvb_get_guint8(tvb, 0);
guint msg_len = tvb_reported_length(tvb);
switch (msg_type) {
case 'O':
if (msg_len != 48 && msg_len != 49) {
return FALSE;
}
break;
case 'U':
if (msg_len != 47 && msg_len != 79 && msg_len != 80) {
return FALSE;
}
break;
case 'X':
if (msg_len != 19) {
return FALSE;
}
break;
case 'S':
if (msg_len != 10) {
return FALSE;
}
break;
case 'A':
if (msg_len != 65 && msg_len != 66) {
return FALSE;
}
break;
case 'C':
if (msg_len != 28) {
return FALSE;
}
break;
case 'D':
if (msg_len != 37) {
return FALSE;
}
break;
case 'E':
if (msg_len != 40) {
return FALSE;
}
break;
case 'B':
if (msg_len != 32) {
return FALSE;
}
break;
case 'K':
if (msg_len != 36) {
return FALSE;
}
break;
case 'J':
if (msg_len != 24) {
return FALSE;
}
break;
case 'P':
if (msg_len != 23) {
return FALSE;
}
break;
case 'I':
if (msg_len != 23) {
return FALSE;
}
break;
default:
return FALSE;
}
dissect_ouch(tvb, pinfo, tree, NULL);
return TRUE;
}
void
proto_register_ouch(void)
{
module_t *ouch_module;
static hf_register_info hf[] = {
{ &hf_ouch_bbo_weight_indicator,
{ "BBO Weight Indicator", "ouch.bbo_weight_indicator",
FT_UINT8, BASE_CUSTOM, CF_FUNC(format_bbo_weight_indicator), 0x0,
NULL, HFILL }},
{ &hf_ouch_broken_trade_reason,
{ "Broken Trade Reason", "ouch.broken_trade_reason",
FT_UINT8, BASE_CUSTOM, CF_FUNC(format_broken_trade_reason), 0x0,
NULL, HFILL }},
{ &hf_ouch_buy_sell_indicator,
{ "Buy/Sell Indicator", "ouch.buy_sell_indicator",
FT_UINT8, BASE_CUSTOM, CF_FUNC(format_buy_sell_indicator), 0x0,
NULL, HFILL }},
{ &hf_ouch_cancel_reason,
{ "Cancel Reason", "ouch.cancel_reason",
FT_UINT8, BASE_CUSTOM, CF_FUNC(format_cancel_reason), 0x0,
NULL, HFILL }},
{ &hf_ouch_capacity,
{ "Capacity", "ouch.capacity",
FT_UINT8, BASE_CUSTOM, CF_FUNC(format_capacity), 0x0,
NULL, HFILL }},
{ &hf_ouch_cross_type,
{ "Cross Type", "ouch.cross_type",
FT_UINT8, BASE_CUSTOM, CF_FUNC(format_cross_type), 0x0,
NULL, HFILL }},
{ &hf_ouch_customer_type,
{ "Customer Type", "ouch.customer_type",
FT_UINT8, BASE_CUSTOM, CF_FUNC(format_customer_type), 0x0,
NULL, HFILL }},
{ &hf_ouch_decrement_shares,
{ "Decrement Shares", "ouch.decrement_shares",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ouch_display,
{ "Display", "ouch.display",
FT_UINT8, BASE_CUSTOM, CF_FUNC(format_display), 0x0,
NULL, HFILL }},
{ &hf_ouch_event_code,
{ "Event Code", "ouch.event_code",
FT_UINT8, BASE_CUSTOM, CF_FUNC(format_event_code), 0x0,
NULL, HFILL }},
{ &hf_ouch_executed_shares,
{ "Executed Shares", "ouch.executed_shares",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ouch_execution_price,
{ "Execution Price", "ouch.execution_price",
FT_UINT32, BASE_CUSTOM, CF_FUNC(format_price), 0x0,
NULL, HFILL }},
{ &hf_ouch_existing_order_token,
{ "Existing Order Token", "ouch.existing_order_token",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ouch_firm,
{ "Firm", "ouch.firm",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ouch_iso_eligible,
{ "Intermarket Sweep Eligibility", "ouch.iso_eligible",
FT_UINT8, BASE_CUSTOM, CF_FUNC(format_iso_eligibility), 0x0,
NULL, HFILL }},
{ &hf_ouch_liquidity_flag,
{ "Liquidity Flag", "ouch.liquidity_flag",
FT_UINT8, BASE_CUSTOM, CF_FUNC(format_liquidity_flag), 0x0,
NULL, HFILL }},
{ &hf_ouch_match_number,
{ "Match Number", "ouch.match_number",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ouch_message,
{ "Unknown Message", "ouch.unknown_message",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ouch_min_quantity,
{ "Minimum Quantity", "ouch.min_quantity",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ouch_new_execution_price,
{ "New Execution Price", "ouch.new_execution_price",
FT_UINT32, BASE_CUSTOM, CF_FUNC(format_price), 0x0,
NULL, HFILL }},
{ &hf_ouch_order_reference_number,
{ "Order Reference Number", "ouch.order_reference_number",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ouch_order_state,
{ "Order State", "ouch.order_state",
FT_UINT8, BASE_CUSTOM, CF_FUNC(format_order_state), 0x0,
NULL, HFILL }},
{ &hf_ouch_order_token,
{ "Order Token", "ouch.order_token",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ouch_packet_type,
{ "Packet Type", "ouch.packet_type",
FT_UINT8, BASE_CUSTOM, CF_FUNC(format_packet_type), 0x0,
NULL, HFILL }},
{ &hf_ouch_previous_order_token,
{ "Previous Order Token", "ouch.previous_order_token",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ouch_price,
{ "Price", "ouch.price",
FT_UINT32, BASE_CUSTOM, CF_FUNC(format_price), 0x0,
NULL, HFILL }},
{ &hf_ouch_price_correction_reason,
{ "Price Correction Reason", "ouch.price_correction_reason",
FT_UINT8, BASE_CUSTOM, CF_FUNC(format_price_correction_reason), 0x0,
NULL, HFILL }},
{ &hf_ouch_quantity_prevented_from_trading,
{ "Quantity Prevented from Trading",
"ouch.quantity_prevented_from_trading",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ouch_reject_reason,
{ "Reject Reason", "ouch.reject_reason",
FT_UINT8, BASE_CUSTOM, CF_FUNC(format_reject_reason), 0x0,
NULL, HFILL }},
{ &hf_ouch_replacement_order_token,
{ "Replacement Order Token", "ouch.replacement_order_token",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ouch_shares,
{ "Shares", "ouch.shares",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_ouch_stock,
{ "Stock", "ouch.stock",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_ouch_tif,
{ "Time In Force", "ouch.tif",
FT_UINT32, BASE_CUSTOM, CF_FUNC(format_tif), 0x0,
NULL, HFILL }},
{ &hf_ouch_timestamp,
{ "Timestamp", "ouch.timestamp",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }}
};
static gint *ett[] = {
&ett_ouch
};
proto_ouch = proto_register_protocol("OUCH", "OUCH", "ouch");
proto_register_field_array(proto_ouch, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
ouch_module = prefs_register_protocol(proto_ouch, ouch_prefs);
prefs_register_range_preference(ouch_module,
"tcp.port",
"TCP Ports",
"TCP Ports range",
&global_ouch_range,
65535);
ouch_range = range_empty();
}
void
proto_reg_handoff_ouch(void)
{
ouch_handle = create_dissector_handle(dissect_ouch, proto_ouch);
heur_dissector_add("soupbintcp", dissect_ouch_heur, "OUCH over SoupBinTCP", "ouch_soupbintcp", proto_ouch, HEURISTIC_ENABLE);
}
