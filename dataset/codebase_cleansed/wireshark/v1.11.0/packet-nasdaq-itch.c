static int
order_ref_number(tvbuff_t *tvb, packet_info *pinfo, proto_tree *nasdaq_itch_tree, int offset)
{
const char *str_value = tvb_get_string(wmem_packet_scope(), tvb, offset, 9);
guint32 value = (guint32)strtoul(str_value, NULL, 10);
proto_tree_add_uint(nasdaq_itch_tree, hf_nasdaq_itch_order_reference, tvb, offset, 9, value);
col_append_fstr(pinfo->cinfo, COL_INFO, "%u ", value);
return offset+9;
}
static int
time_stamp(tvbuff_t *tvb, proto_tree *nasdaq_itch_tree, int id, int offset, int size)
{
if (nasdaq_itch_tree) {
guint32 ms, val;
const char *display = "";
const char *str_value = tvb_get_string(wmem_packet_scope(), tvb, offset, size);
ms = val = (guint32)strtoul(str_value, NULL, 10);
switch (size) {
case 3:
display = wmem_strdup_printf(wmem_packet_scope(), " %03u" , val);
break;
case 5:
ms = val *1000;
case 8:
display = wmem_strdup_printf(wmem_packet_scope(), " %u (%02u:%02u:%02u.%03u)", val,
ms/3600000, (ms % 3600000)/60000, (ms % 60000)/1000, ms %1000);
break;
}
proto_tree_add_uint_format_value(nasdaq_itch_tree, id, tvb, offset, size, val, "%s", display);
}
return offset+size;
}
static int
number_of_shares(tvbuff_t *tvb, packet_info *pinfo, proto_tree *nasdaq_itch_tree, int id, int offset, int big)
{
gint size = (big)?10:6;
const char *str_value = tvb_get_string(wmem_packet_scope(), tvb, offset, size);
guint32 value = (guint32)strtoul(str_value, NULL, 10);
proto_tree_add_uint(nasdaq_itch_tree, id, tvb, offset, size, value);
col_append_fstr(pinfo->cinfo, COL_INFO, "qty %u ", value);
return offset +size;
}
static int
price(tvbuff_t *tvb, packet_info *pinfo, proto_tree *nasdaq_itch_tree, int id, int offset, int big)
{
gint size = (big)?19:10;
const char *str_value = tvb_get_string(wmem_packet_scope(), tvb, offset, size);
gdouble value = guint64_to_gdouble(g_ascii_strtoull(str_value, NULL, 10))/((big)?1000000.0:10000.0);
proto_tree_add_double(nasdaq_itch_tree, id, tvb, offset, size, value);
col_append_fstr(pinfo->cinfo, COL_INFO, "price %g ", value);
return offset+size;
}
static int
stock(tvbuff_t *tvb, packet_info *pinfo, proto_tree *nasdaq_itch_tree, int offset)
{
char *stock_p = tvb_get_string(wmem_packet_scope(), tvb, offset, 6);
proto_tree_add_item(nasdaq_itch_tree, hf_nasdaq_itch_stock, tvb, offset, 6, ENC_ASCII|ENC_NA);
col_append_fstr(pinfo->cinfo, COL_INFO, "<%s> ", stock_p);
return offset+6;
}
static int
order(tvbuff_t *tvb, packet_info *pinfo, proto_tree *nasdaq_itch_tree, int offset, int big)
{
guint8 value;
offset = order_ref_number(tvb, pinfo, nasdaq_itch_tree, offset);
value = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, "%c ", value);
proto_tree_add_item(nasdaq_itch_tree, hf_nasdaq_itch_buy_sell, tvb, offset, 1, ENC_ASCII|ENC_NA);
offset += 1;
offset = number_of_shares(tvb, pinfo, nasdaq_itch_tree, hf_nasdaq_itch_shares, offset, big);
offset = stock(tvb, pinfo, nasdaq_itch_tree, offset);
offset = price(tvb, pinfo, nasdaq_itch_tree, hf_nasdaq_itch_price, offset, big);
return offset;
}
static int
executed(tvbuff_t *tvb, packet_info *pinfo, proto_tree *nasdaq_itch_tree, int offset, int big)
{
offset = order_ref_number(tvb, pinfo, nasdaq_itch_tree, offset);
offset = number_of_shares(tvb, pinfo, nasdaq_itch_tree, hf_nasdaq_itch_executed, offset, big);
proto_tree_add_item(nasdaq_itch_tree, hf_nasdaq_itch_match, tvb, offset, 9, ENC_ASCII|ENC_NA);
offset += 9;
return offset;
}
static void
dissect_nasdaq_itch(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *ti;
proto_tree *nasdaq_itch_tree = NULL;
guint8 nasdaq_itch_type;
int offset = 0;
int version = 3;
int big = 0;
const gchar *rep;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Nasdaq-ITCH");
nasdaq_itch_type = tvb_get_guint8(tvb, offset);
if (nasdaq_itch_type >= '0' && nasdaq_itch_type <= '9') {
version = 2;
nasdaq_itch_type = tvb_get_guint8(tvb, offset +8);
}
if ((!nasdaq_itch_chi_x || version == 3) && strchr(chix_msg, nasdaq_itch_type)) {
nasdaq_itch_type = 0;
}
rep = val_to_str(nasdaq_itch_type, message_types_val, "Unknown packet type (0x%02x) ");
col_clear(pinfo->cinfo, COL_INFO);
col_add_str(pinfo->cinfo, COL_INFO, rep);
if (tree) {
proto_item *item;
ti = proto_tree_add_protocol_format(tree, proto_nasdaq_itch, tvb, offset, -1, "Nasdaq TotalView-ITCH %s, %s",
version == 2?"2.0":"3.0", rep);
nasdaq_itch_tree = proto_item_add_subtree(ti, ett_nasdaq_itch);
item=proto_tree_add_uint(nasdaq_itch_tree, hf_nasdaq_itch_version, tvb, 0, 0, version);
PROTO_ITEM_SET_GENERATED(item);
}
if (version == 2) {
offset = time_stamp (tvb, nasdaq_itch_tree, hf_nasdaq_itch_millisecond, offset, 8);
}
proto_tree_add_item(nasdaq_itch_tree, hf_nasdaq_itch_message_type, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
if (version == 3) {
switch (nasdaq_itch_type) {
case 'T':
time_stamp (tvb, nasdaq_itch_tree, hf_nasdaq_itch_second, offset, 5);
return;
case 'M':
time_stamp (tvb, nasdaq_itch_tree, hf_nasdaq_itch_millisecond, offset, 3);
return;
}
}
switch (nasdaq_itch_type) {
case 'S':
proto_tree_add_item(nasdaq_itch_tree, hf_nasdaq_itch_system_event, tvb, offset, 1, ENC_BIG_ENDIAN);
offset++;
break;
case 'R':
offset = stock(tvb, pinfo, nasdaq_itch_tree, offset);
proto_tree_add_item(nasdaq_itch_tree, hf_nasdaq_itch_market_category, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nasdaq_itch_tree, hf_nasdaq_itch_financial_status, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(nasdaq_itch_tree, hf_nasdaq_itch_round_lot_size, tvb, offset, 6, ENC_ASCII|ENC_NA);
offset += 6;
proto_tree_add_item(nasdaq_itch_tree, hf_nasdaq_itch_round_lots_only, tvb, offset, 1, ENC_BIG_ENDIAN);
break;
case 'H':
offset = stock(tvb, pinfo, nasdaq_itch_tree, offset);
proto_tree_add_item(nasdaq_itch_tree, hf_nasdaq_itch_trading_state, tvb, offset, 1, ENC_ASCII|ENC_NA);
offset += 1;
proto_tree_add_item(nasdaq_itch_tree, hf_nasdaq_itch_reserved, tvb, offset, 1, ENC_ASCII|ENC_NA);
offset += 1;
proto_tree_add_item(nasdaq_itch_tree, hf_nasdaq_itch_reason, tvb, offset, 4, ENC_ASCII|ENC_NA);
break;
case 'a' :
big = 1;
case 'A':
offset = order(tvb, pinfo, nasdaq_itch_tree, offset, big);
if (version == 2) {
proto_tree_add_item(nasdaq_itch_tree, hf_nasdaq_itch_printable, tvb, offset, 1, ENC_ASCII|ENC_NA);
}
break;
case 'F':
offset = order(tvb, pinfo, nasdaq_itch_tree, offset, big);
proto_tree_add_item(nasdaq_itch_tree, hf_nasdaq_itch_attribution, tvb, offset, 4, ENC_ASCII|ENC_NA);
break;
case 'e' :
big = 1;
case 'E' :
executed(tvb, pinfo, nasdaq_itch_tree, offset, big);
break;
case 'C' :
offset = executed(tvb, pinfo, nasdaq_itch_tree, offset, big);
proto_tree_add_item(nasdaq_itch_tree, hf_nasdaq_itch_printable, tvb, offset, 1, ENC_ASCII|ENC_NA);
offset += 1;
price(tvb, pinfo, nasdaq_itch_tree, hf_nasdaq_itch_execution_price, offset, big);
break;
case 'x' :
big = 1;
case 'X' :
offset = order_ref_number(tvb, pinfo, nasdaq_itch_tree, offset);
number_of_shares(tvb, pinfo, nasdaq_itch_tree, hf_nasdaq_itch_canceled, offset, big);
break;
case 'D' :
order_ref_number(tvb, pinfo, nasdaq_itch_tree, offset);
break;
case 'p' :
big = 1;
case 'P' :
offset = order(tvb, pinfo, nasdaq_itch_tree, offset, big);
proto_tree_add_item(nasdaq_itch_tree, hf_nasdaq_itch_match, tvb, offset, 9, ENC_ASCII|ENC_NA);
break;
case 'Q' :
offset = number_of_shares(tvb, pinfo, nasdaq_itch_tree, hf_nasdaq_itch_shares, offset, big);
offset = stock(tvb, pinfo, nasdaq_itch_tree, offset);
offset = price(tvb, pinfo, nasdaq_itch_tree, hf_nasdaq_itch_price, offset, big);
proto_tree_add_item(nasdaq_itch_tree, hf_nasdaq_itch_match, tvb, offset, 9, ENC_ASCII|ENC_NA);
offset += 9;
proto_tree_add_item(nasdaq_itch_tree, hf_nasdaq_itch_cross, tvb, offset, 1, ENC_ASCII|ENC_NA);
break;
case 'B' :
proto_tree_add_item(nasdaq_itch_tree, hf_nasdaq_itch_match, tvb, offset, 9, ENC_ASCII|ENC_NA);
break;
case 'I':
offset = stock(tvb, pinfo, nasdaq_itch_tree, offset);
proto_tree_add_item(nasdaq_itch_tree, hf_nasdaq_itch_cross, tvb, offset, 1, ENC_ASCII|ENC_NA);
break;
default:
proto_tree_add_item(nasdaq_itch_tree, hf_nasdaq_itch_message, tvb, offset, -1, ENC_ASCII|ENC_NA);
break;
}
}
void
proto_register_nasdaq_itch(void)
{
static hf_register_info hf[] = {
{ &hf_nasdaq_itch_version,
{ "Version", "nasdaq-itch.version",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_nasdaq_itch_message_type,
{ "Message Type", "nasdaq-itch.message_type",
FT_UINT8, BASE_DEC, VALS(message_types_val), 0x0,
NULL, HFILL }},
{ &hf_nasdaq_itch_second,
{ "Second", "nasdaq-itch.second",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_nasdaq_itch_millisecond,
{ "Millisecond", "nasdaq-itch.millisecond",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_nasdaq_itch_system_event,
{ "System Event", "nasdaq-itch.system_event",
FT_UINT8, BASE_DEC, VALS(system_event_val), 0x0,
NULL, HFILL }},
{ &hf_nasdaq_itch_market_category,
{ "Market Category", "nasdaq-itch.market_category",
FT_UINT8, BASE_DEC, VALS(market_category_val), 0x0,
NULL, HFILL }},
{ &hf_nasdaq_itch_financial_status,
{ "Financial Status Indicator", "nasdaq-itch.financial_status",
FT_UINT8, BASE_DEC, VALS(financial_status_val), 0x0,
NULL, HFILL }},
{ &hf_nasdaq_itch_stock,
{ "Stock", "nasdaq-itch.stock",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_nasdaq_itch_round_lot_size,
{ "Round Lot Size", "nasdaq-itch.round_lot_size",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_nasdaq_itch_round_lots_only,
{ "Round Lots Only", "nasdaq-itch.round_lots_only",
FT_UINT8, BASE_DEC, VALS(round_lots_only_val), 0x0,
NULL, HFILL }},
{ &hf_nasdaq_itch_trading_state,
{ "Trading State", "nasdaq-itch.trading_state",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_nasdaq_itch_reserved,
{ "Reserved", "nasdaq-itch.reserved",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_nasdaq_itch_reason,
{ "Reason", "nasdaq-itch.reason",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_nasdaq_itch_order_reference,
{ "Order Reference", "nasdaq-itch.order_reference",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Order reference number", HFILL }},
{ &hf_nasdaq_itch_buy_sell,
{ "Buy/Sell", "nasdaq-itch.buy_sell",
FT_STRING, BASE_NONE, NULL, 0x0,
"Buy/Sell indicator", HFILL }},
{ &hf_nasdaq_itch_shares,
{ "Shares", "nasdaq-itch.shares",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of shares", HFILL }},
{ &hf_nasdaq_itch_price,
{ "Price", "nasdaq-itch.price",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_nasdaq_itch_attribution,
{ "Attribution", "nasdaq-itch.attribution",
FT_STRING, BASE_NONE, NULL, 0x0,
"Market participant identifier", HFILL }},
{ &hf_nasdaq_itch_executed,
{ "Executed Shares", "nasdaq-itch.executed",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of shares executed", HFILL }},
{ &hf_nasdaq_itch_match,
{ "Matched", "nasdaq-itch.match",
FT_STRING, BASE_NONE, NULL, 0x0,
"Match number", HFILL }},
{ &hf_nasdaq_itch_printable,
{ "Printable", "nasdaq-itch.printable",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_nasdaq_itch_execution_price,
{ "Execution Price", "nasdaq-itch.execution_price",
FT_DOUBLE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_nasdaq_itch_canceled,
{ "Canceled Shares", "nasdaq-itch.canceled",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Number of shares to be removed", HFILL }},
{ &hf_nasdaq_itch_cross,
{ "Cross Type", "nasdaq-itch.cross",
FT_STRING, BASE_NONE, NULL, 0x0,
"Cross trade type", HFILL }},
{ &hf_nasdaq_itch_message,
{ "Message", "nasdaq-itch.message",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }}
};
static gint *ett[] = {
&ett_nasdaq_itch
};
module_t *nasdaq_itch_module;
proto_nasdaq_itch = proto_register_protocol("Nasdaq TotalView-ITCH", "NASDAQ-ITCH", "nasdaq_itch");
proto_register_field_array(proto_nasdaq_itch, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
nasdaq_itch_module = prefs_register_protocol(proto_nasdaq_itch, NULL);
prefs_register_bool_preference(nasdaq_itch_module, "chi_x", "Decode Chi X extensions",
"Whether the Nasdaq ITCH dissector should decode Chi X extensions.",
&nasdaq_itch_chi_x);
register_dissector("nasdaq-itch", dissect_nasdaq_itch, proto_nasdaq_itch);
}
void
proto_reg_handoff_nasdaq_itch(void)
{
}
