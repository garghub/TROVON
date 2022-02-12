static int
dissect_usb_hid_report_mainitem_data(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, unsigned int bSize, unsigned int bTag)
{
switch (bTag) {
case USBHID_MAINITEM_TAG_INPUT:
case USBHID_MAINITEM_TAG_OUTPUT:
case USBHID_MAINITEM_TAG_FEATURE:
proto_tree_add_item(tree, hf_usb_hid_mainitem_bit0, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_hid_mainitem_bit1, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_hid_mainitem_bit2, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_hid_mainitem_bit3, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_hid_mainitem_bit4, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_hid_mainitem_bit5, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_hid_mainitem_bit6, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
if (bTag == USBHID_MAINITEM_TAG_INPUT) {
proto_tree_add_item(tree, hf_usb_hid_mainitem_bit7_input, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_item(tree, hf_usb_hid_mainitem_bit7, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
}
if (bSize > 1) {
proto_tree_add_item(tree, hf_usb_hid_mainitem_bit8, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
} else {
proto_tree_add_text(tree, tvb, offset, 0, "Bits or bytes: Buffered bytes (default, no second byte present)");
}
break;
case USBHID_MAINITEM_TAG_COLLECTION:
proto_tree_add_item(tree, hf_usb_hid_mainitem_colltype, tvb, offset, 1, ENC_LITTLE_ENDIAN);
break;
case USBHID_MAINITEM_TAG_ENDCOLLECTION:
break;
default:
proto_tree_add_item(tree, hf_usb_hid_item_unk_data, tvb, offset, bSize, ENC_NA);
break;
}
offset += bSize;
return offset;
}
static int
dissect_usb_hid_report_globalitem_data(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, unsigned int bSize, unsigned int bTag, struct usb_hid_global_state *global)
{
switch (bTag) {
case USBHID_GLOBALITEM_TAG_USAGE_PAGE:
switch (bSize) {
case 1: global->usage_page = tvb_get_guint8(tvb, offset); break;
case 2: global->usage_page = tvb_get_letohs(tvb, offset); break;
case 3: global->usage_page = tvb_get_letoh24(tvb, offset); break;
case 4: global->usage_page = tvb_get_letohl(tvb, offset); break;
default: global->usage_page = 0; break;
}
proto_tree_add_item(tree, hf_usb_hid_globalitem_usage, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
break;
case USBHID_GLOBALITEM_TAG_LOG_MIN:
proto_tree_add_item(tree, hf_usb_hid_globalitem_log_min, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
break;
case USBHID_GLOBALITEM_TAG_LOG_MAX:
proto_tree_add_item(tree, hf_usb_hid_globalitem_log_max, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
break;
case USBHID_GLOBALITEM_TAG_PHY_MIN:
proto_tree_add_item(tree, hf_usb_hid_globalitem_phy_min, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
break;
case USBHID_GLOBALITEM_TAG_PHY_MAX:
proto_tree_add_item(tree, hf_usb_hid_globalitem_phy_max, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
break;
case USBHID_GLOBALITEM_TAG_UNIT_EXP:
proto_tree_add_item(tree, hf_usb_hid_globalitem_unit_exp, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
break;
case USBHID_GLOBALITEM_TAG_UNIT:
proto_tree_add_item(tree, hf_usb_hid_globalitem_unit_sys, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_hid_globalitem_unit_len, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_hid_globalitem_unit_mass, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_hid_globalitem_unit_time, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_hid_globalitem_unit_temp, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_hid_globalitem_unit_current, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_hid_globalitem_unit_brightness, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
break;
case USBHID_GLOBALITEM_TAG_REPORT_SIZE:
proto_tree_add_item(tree, hf_usb_hid_globalitem_report_size, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
break;
case USBHID_GLOBALITEM_TAG_REPORT_ID:
proto_tree_add_item(tree, hf_usb_hid_globalitem_report_id, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
break;
case USBHID_GLOBALITEM_TAG_REPORT_COUNT:
proto_tree_add_item(tree, hf_usb_hid_globalitem_report_count, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
break;
case USBHID_GLOBALITEM_TAG_PUSH:
proto_tree_add_item(tree, hf_usb_hid_globalitem_push, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
break;
case USBHID_GLOBALITEM_TAG_POP:
proto_tree_add_item(tree, hf_usb_hid_globalitem_pop, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
break;
default:
proto_tree_add_item(tree, hf_usb_hid_item_unk_data, tvb, offset, bSize, ENC_NA);
break;
}
offset += bSize;
return offset;
}
static int
dissect_usb_hid_report_localitem_data(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, unsigned int bSize, unsigned int bTag, struct usb_hid_global_state *global)
{
unsigned int usage_page = 0xffffffff;
switch (bTag) {
case USBHID_LOCALITEM_TAG_USAGE_PAGE:
if (bSize > 2) {
proto_tree_add_item(tree, hf_usb_hid_localitem_usage, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
} else {
if (bSize == 1)
usage_page = (global->usage_page & 0xFFFFFF00) | tvb_get_guint8(tvb, offset);
else if (bSize == 2)
usage_page = (global->usage_page & 0xFFFF0000) | tvb_get_ntohs(tvb, offset);
proto_tree_add_text(tree, tvb, offset, bSize, "Usage: %s (0x%08x)",
rval_to_str(usage_page, usb_hid_item_usage_vals, "[Unknown page!]"),
usage_page);
}
break;
case USBHID_LOCALITEM_TAG_USAGE_MIN:
proto_tree_add_item(tree, hf_usb_hid_localitem_usage_min, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
break;
case USBHID_LOCALITEM_TAG_USAGE_MAX:
proto_tree_add_item(tree, hf_usb_hid_localitem_usage, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
break;
case USBHID_LOCALITEM_TAG_DESIG_INDEX:
proto_tree_add_item(tree, hf_usb_hid_localitem_desig_index, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
break;
case USBHID_LOCALITEM_TAG_DESIG_MIN:
proto_tree_add_item(tree, hf_usb_hid_localitem_desig_min, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
break;
case USBHID_LOCALITEM_TAG_DESIG_MAX:
proto_tree_add_item(tree, hf_usb_hid_localitem_desig_max, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
break;
case USBHID_LOCALITEM_TAG_STRING_INDEX:
proto_tree_add_item(tree, hf_usb_hid_localitem_string_index, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
break;
case USBHID_LOCALITEM_TAG_STRING_MIN:
proto_tree_add_item(tree, hf_usb_hid_localitem_string_min, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
break;
case USBHID_LOCALITEM_TAG_STRING_MAX:
proto_tree_add_item(tree, hf_usb_hid_localitem_string_max, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
break;
case USBHID_LOCALITEM_TAG_DELIMITER:
proto_tree_add_item(tree, hf_usb_hid_localitem_delimiter, tvb, offset, bSize, ENC_LITTLE_ENDIAN);
break;
default:
proto_tree_add_item(tree, hf_usb_hid_item_unk_data, tvb, offset, bSize, ENC_NA);
break;
}
offset += bSize;
return offset;
}
static int
dissect_usb_hid_report_item(packet_info *pinfo _U_, proto_tree *parent_tree, tvbuff_t *tvb, int offset, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_, const struct usb_hid_global_state *global)
{
proto_item *item=NULL, *subitem=NULL;
proto_tree *tree=NULL, *subtree=NULL;
int old_offset;
unsigned int tmp;
unsigned int bSize, bType, bTag;
const value_string *usb_hid_cur_bTag_vals;
int hf_usb_hid_curitem_bTag;
struct usb_hid_global_state cur_global;
memcpy(&cur_global, global, sizeof(struct usb_hid_global_state));
while (tvb_reported_length_remaining(tvb, offset) > 0)
{
old_offset=offset;
tmp = tvb_get_guint8(tvb, offset);
bSize = tmp & USBHID_SIZE_MASK;
if (bSize == 3) bSize++;
bType = (tmp & USBHID_TYPE_MASK) >> 2;
bTag = (tmp & USBHID_TAG_MASK) >> 4;
switch (bType) {
case USBHID_ITEMTYPE_MAIN:
hf_usb_hid_curitem_bTag = hf_usb_hid_mainitem_bTag;
usb_hid_cur_bTag_vals = usb_hid_mainitem_bTag_vals;
break;
case USBHID_ITEMTYPE_GLOBAL:
hf_usb_hid_curitem_bTag = hf_usb_hid_globalitem_bTag;
usb_hid_cur_bTag_vals = usb_hid_globalitem_bTag_vals;
break;
case USBHID_ITEMTYPE_LOCAL:
hf_usb_hid_curitem_bTag = hf_usb_hid_localitem_bTag;
usb_hid_cur_bTag_vals = usb_hid_localitem_bTag_vals;
break;
default:
hf_usb_hid_curitem_bTag = hf_usb_hid_longitem_bTag;
usb_hid_cur_bTag_vals = usb_hid_longitem_bTag_vals;
break;
}
subitem = proto_tree_add_text(parent_tree, tvb, offset, bSize + 1, "%s item (%s)",
val_to_str(bType, usb_hid_item_bType_vals, "Unknown/%u"),
val_to_str(bTag, usb_hid_cur_bTag_vals, "Unknown/%u tag")
);
subtree = proto_item_add_subtree(subitem, ett_usb_hid_item_header);
item = proto_tree_add_text(subtree, tvb, offset, 1, "Header");
tree = proto_item_add_subtree(item, ett_usb_hid_item_header);
proto_tree_add_item(tree, hf_usb_hid_item_bSize, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_hid_item_bType, tvb, offset, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(tree, hf_usb_hid_curitem_bTag, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
if ((bType == 3) && (bTag == 16)) {
bSize = tvb_get_guint8(tvb, offset);
proto_tree_add_item(subtree, hf_usb_hid_item_bDataSize, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_usb_hid_item_bLongItemTag, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_usb_hid_item_unk_data, tvb, offset, bSize, ENC_NA);
offset += bSize;
} else {
switch (bType) {
case USBHID_ITEMTYPE_MAIN:
offset = dissect_usb_hid_report_mainitem_data(pinfo, subtree, tvb, offset, bSize, bTag);
break;
case USBHID_ITEMTYPE_GLOBAL:
offset = dissect_usb_hid_report_globalitem_data(pinfo, subtree, tvb, offset, bSize, bTag, &cur_global);
break;
case USBHID_ITEMTYPE_LOCAL:
offset = dissect_usb_hid_report_localitem_data(pinfo, subtree, tvb, offset, bSize, bTag, &cur_global);
break;
default:
proto_tree_add_item(subtree, hf_usb_hid_item_unk_data, tvb, offset, bSize, ENC_NA);
offset += bSize;
break;
}
}
if (bType == USBHID_ITEMTYPE_MAIN) {
if (bTag == USBHID_MAINITEM_TAG_COLLECTION) {
offset = dissect_usb_hid_report_item(pinfo, subtree, tvb, offset, usb_trans_info, usb_conv_info, &cur_global);
proto_item_set_len(subitem, offset-old_offset);
} else if (bTag == USBHID_MAINITEM_TAG_ENDCOLLECTION) {
break;
}
}
}
return offset;
}
int
dissect_usb_hid_get_report_descriptor(packet_info *pinfo _U_, proto_tree *parent_tree, tvbuff_t *tvb, int offset, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item=NULL;
proto_tree *tree=NULL;
int old_offset=offset;
struct usb_hid_global_state initial_global;
memset(&initial_global, 0, sizeof(struct usb_hid_global_state));
if (parent_tree) {
item = proto_tree_add_protocol_format(parent_tree, proto_usb_hid, tvb, offset,
-1, "HID Report");
tree = proto_item_add_subtree(item, ett_usb_hid_report);
offset = dissect_usb_hid_report_item(pinfo, tree, tvb, offset, usb_trans_info, usb_conv_info, &initial_global);
proto_item_set_len(item, offset-old_offset);
}
return offset;
}
static void
dissect_usb_hid_get_report(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item = NULL;
proto_tree *subtree = NULL;
if (is_request) {
item = proto_tree_add_item(tree, hf_usb_hid_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hid_wValue);
proto_tree_add_item(subtree, hf_usb_hid_report_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_usb_hid_report_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_usb_hid_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_hid_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
}
}
static void
dissect_usb_hid_set_report(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item = NULL;
proto_tree *subtree = NULL;
if (is_request) {
item = proto_tree_add_item(tree, hf_usb_hid_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hid_wValue);
proto_tree_add_item(subtree, hf_usb_hid_report_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_usb_hid_report_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_usb_hid_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_hid_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
}
}
static void
dissect_usb_hid_get_idle(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item = NULL;
proto_tree *subtree = NULL;
if (is_request) {
item = proto_tree_add_item(tree, hf_usb_hid_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hid_wValue);
proto_tree_add_item(subtree, hf_usb_hid_report_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_usb_hid_zero, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_usb_hid_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_hid_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
}
}
static void
dissect_usb_hid_set_idle(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item = NULL;
proto_tree *subtree = NULL;
if (is_request) {
item = proto_tree_add_item(tree, hf_usb_hid_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hid_wValue);
proto_tree_add_item(subtree, hf_usb_hid_report_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_usb_hid_duration, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_usb_hid_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_hid_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
}
}
static void
dissect_usb_hid_get_protocol(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
if (is_request) {
proto_tree_add_item(tree, hf_usb_hid_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_hid_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_hid_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
}
}
static void
dissect_usb_hid_set_protocol(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_trans_info_t *usb_trans_info _U_, usb_conv_info_t *usb_conv_info _U_)
{
if (is_request) {
proto_tree_add_item(tree, hf_usb_hid_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_hid_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_hid_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
} else {
}
}
static gint
dissect_usb_hid_control(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gboolean is_request;
usb_conv_info_t *usb_conv_info;
usb_trans_info_t *usb_trans_info;
int offset = 0;
usb_setup_dissector dissector;
const usb_setup_dissector_table_t *tmp;
is_request = (pinfo->srcport==NO_ENDPOINT);
usb_conv_info = (usb_conv_info_t *)pinfo->usb_conv_info;
usb_trans_info = usb_conv_info->usb_trans_info;
dissector = NULL;
if ((usb_trans_info->setup.requesttype & 0x7F) ==
((RQT_SETUP_TYPE_CLASS << 5) | RQT_SETUP_RECIPIENT_INTERFACE)) {
for (tmp = setup_dissectors; tmp->dissector; tmp++) {
if (tmp->request == usb_trans_info->setup.request) {
dissector = tmp->dissector;
break;
}
}
}
if (!dissector) {
return FALSE;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "USBHID");
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s %s",
val_to_str(usb_trans_info->setup.request, setup_request_names_vals, "Unknown type %x"),
is_request ? "Request" : "Response");
}
if (is_request) {
proto_tree_add_item(tree, hf_usb_hid_request, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
}
dissector(pinfo, tree, tvb, offset, is_request, usb_trans_info, usb_conv_info);
return TRUE;
}
void
proto_register_usb_hid(void)
{
static hf_register_info hf[] = {
{ &hf_usb_hid_item_bSize,
{ "bSize", "usbhid.item.bSize", FT_UINT8, BASE_DEC,
VALS(usb_hid_item_bSize_vals), USBHID_SIZE_MASK, NULL, HFILL }},
{ &hf_usb_hid_item_bType,
{ "bType", "usbhid.item.bType", FT_UINT8, BASE_DEC,
VALS(usb_hid_item_bType_vals), USBHID_TYPE_MASK, NULL, HFILL }},
{ &hf_usb_hid_mainitem_bTag,
{ "bTag", "usbhid.item.bTag", FT_UINT8, BASE_HEX,
VALS(usb_hid_mainitem_bTag_vals), USBHID_TAG_MASK, NULL, HFILL }},
{ &hf_usb_hid_globalitem_bTag,
{ "bTag", "usbhid.item.bTag", FT_UINT8, BASE_HEX,
VALS(usb_hid_globalitem_bTag_vals), USBHID_TAG_MASK, NULL, HFILL }},
{ &hf_usb_hid_localitem_bTag,
{ "bTag", "usbhid.item.bTag", FT_UINT8, BASE_HEX,
VALS(usb_hid_localitem_bTag_vals), USBHID_TAG_MASK, NULL, HFILL }},
{ &hf_usb_hid_longitem_bTag,
{ "bTag", "usbhid.item.bTag", FT_UINT8, BASE_HEX,
VALS(usb_hid_longitem_bTag_vals), USBHID_TAG_MASK, NULL, HFILL }},
{ &hf_usb_hid_item_bDataSize,
{ "bDataSize", "usbhid.item.bDataSize", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_hid_item_bLongItemTag,
{ "bTag", "usbhid.item.bLongItemTag", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_hid_mainitem_bit0,
{ "Data/constant", "usbhid.item.main.readonly", FT_BOOLEAN, 9,
TFS(&tfs_mainitem_bit0), 1<<0, NULL, HFILL }},
{ &hf_usb_hid_mainitem_bit1,
{ "Data type", "usbhid.item.main.variable", FT_BOOLEAN, 9,
TFS(&tfs_mainitem_bit1), 1<<1, NULL, HFILL }},
{ &hf_usb_hid_mainitem_bit2,
{ "Coordinates", "usbhid.item.main.relative", FT_BOOLEAN, 9,
TFS(&tfs_mainitem_bit2), 1<<2, NULL, HFILL }},
{ &hf_usb_hid_mainitem_bit3,
{ "Min/max wraparound", "usbhid.item.main.wrap", FT_BOOLEAN, 9,
TFS(&tfs_mainitem_bit3), 1<<3, NULL, HFILL }},
{ &hf_usb_hid_mainitem_bit4,
{ "Physical relationship to data", "usbhid.item.main.nonlinear", FT_BOOLEAN, 9,
TFS(&tfs_mainitem_bit4), 1<<4, NULL, HFILL }},
{ &hf_usb_hid_mainitem_bit5,
{ "Preferred state", "usbhid.item.main.no_preferred_state", FT_BOOLEAN, 9,
TFS(&tfs_mainitem_bit5), 1<<5, NULL, HFILL }},
{ &hf_usb_hid_mainitem_bit6,
{ "Has null position", "usbhid.item.main.nullstate", FT_BOOLEAN, 9,
TFS(&tfs_mainitem_bit6), 1<<6, NULL, HFILL }},
{ &hf_usb_hid_mainitem_bit7,
{ "(Non)-volatile", "usbhid.item.main.volatile", FT_BOOLEAN, 9,
TFS(&tfs_mainitem_bit7), 1<<7, NULL, HFILL }},
{ &hf_usb_hid_mainitem_bit7_input,
{ "[Reserved]", "usbhid.item.main.volatile", FT_BOOLEAN, 9,
NULL, 1<<7, NULL, HFILL }},
{ &hf_usb_hid_mainitem_bit8,
{ "Bits or bytes", "usbhid.item.main.buffered_bytes", FT_BOOLEAN, 9,
TFS(&tfs_mainitem_bit8), 1<<8, NULL, HFILL }},
{ &hf_usb_hid_mainitem_colltype,
{ "Collection type", "usbhid.item.main.colltype", FT_UINT8, BASE_RANGE_STRING|BASE_HEX,
RVALS(usb_hid_mainitem_colltype_vals), 0, NULL, HFILL }},
{ &hf_usb_hid_globalitem_usage,
{ "Usage page", "usbhid.item.global.usage", FT_UINT8, BASE_RANGE_STRING|BASE_HEX,
RVALS(usb_hid_item_usage_vals), 0, NULL, HFILL }},
{ &hf_usb_hid_globalitem_log_min,
{ "Logical minimum", "usbhid.item.global.log_min", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_hid_globalitem_log_max,
{ "Logical maximum", "usbhid.item.global.log_max", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_hid_globalitem_phy_min,
{ "Physical minimum", "usbhid.item.global.phy_min", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_hid_globalitem_phy_max,
{ "Physical maximum", "usbhid.item.global.phy_max", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_hid_globalitem_unit_exp,
{ "Unit exponent", "usbhid.item.global.unit_exp", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_hid_globalitem_unit_sys,
{ "System", "usbhid.item.global.unit.system", FT_UINT32, BASE_HEX,
VALS(usb_hid_globalitem_unit_exp_vals), 0x0000000F, NULL, HFILL }},
{ &hf_usb_hid_globalitem_unit_len,
{ "Length", "usbhid.item.global.unit.length", FT_UINT32, BASE_HEX,
VALS(usb_hid_globalitem_unit_exp_vals), 0x000000F0, NULL, HFILL }},
{ &hf_usb_hid_globalitem_unit_mass,
{ "Mass", "usbhid.item.global.unit.mass", FT_UINT32, BASE_HEX,
VALS(usb_hid_globalitem_unit_exp_vals), 0x00000F00, NULL, HFILL }},
{ &hf_usb_hid_globalitem_unit_time,
{ "Time", "usbhid.item.global.unit.time", FT_UINT32, BASE_HEX,
VALS(usb_hid_globalitem_unit_exp_vals), 0x0000F000, NULL, HFILL }},
{ &hf_usb_hid_globalitem_unit_temp,
{ "Temperature", "usbhid.item.global.unit.temperature", FT_UINT32, BASE_HEX,
VALS(usb_hid_globalitem_unit_exp_vals), 0x000F0000, NULL, HFILL }},
{ &hf_usb_hid_globalitem_unit_current,
{ "Current", "usbhid.item.global.unit.current", FT_UINT32, BASE_HEX,
VALS(usb_hid_globalitem_unit_exp_vals), 0x00F00000, NULL, HFILL }},
{ &hf_usb_hid_globalitem_unit_brightness,
{ "Luminous intensity", "usbhid.item.global.unit.brightness", FT_UINT32, BASE_HEX,
VALS(usb_hid_globalitem_unit_exp_vals), 0x0F000000, NULL, HFILL }},
{ &hf_usb_hid_globalitem_report_size,
{ "Report size", "usbhid.item.global.report_size", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_hid_globalitem_report_id,
{ "Report ID", "usbhid.item.global.report_id", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_hid_globalitem_report_count,
{ "Report count", "usbhid.item.global.report_count", FT_UINT8, BASE_DEC,
NULL, 0, NULL, HFILL }},
{ &hf_usb_hid_globalitem_push,
{ "Push", "usbhid.item.global.push", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_hid_globalitem_pop,
{ "Pop", "usbhid.item.global.pop", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_hid_localitem_usage,
{ "Usage", "usbhid.item.local.usage", FT_UINT8, BASE_RANGE_STRING|BASE_HEX,
RVALS(usb_hid_item_usage_vals), 0, NULL, HFILL }},
{ &hf_usb_hid_localitem_usage_min,
{ "Usage minimum", "usbhid.item.local.usage_min", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
#if 0
{ &hf_usb_hid_localitem_usage_max,
{ "Usage maximum", "usbhid.item.local.usage_max", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
#endif
{ &hf_usb_hid_localitem_desig_index,
{ "Designator index", "usbhid.item.local.desig_index", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_hid_localitem_desig_min,
{ "Designator minimum", "usbhid.item.local.desig_min", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_hid_localitem_desig_max,
{ "Designator maximum", "usbhid.item.local.desig_max", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_hid_localitem_string_index,
{ "String index", "usbhid.item.local.string_index", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_hid_localitem_string_min,
{ "String minimum", "usbhid.item.local.string_min", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_hid_localitem_string_max,
{ "String maximum", "usbhid.item.local.string_max", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_hid_localitem_delimiter,
{ "Delimiter", "usbhid.item.local.delimiter", FT_UINT8, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_usb_hid_item_unk_data,
{ "Item data", "usbhid.item.data", FT_BYTES, BASE_NONE,
NULL, 0, NULL, HFILL }},
{ &hf_usb_hid_request,
{ "bRequest", "usbhid.setup.bRequest", FT_UINT8, BASE_HEX, VALS(setup_request_names_vals), 0x0,
NULL, HFILL }},
{ &hf_usb_hid_value,
{ "wValue", "usbhid.setup.wValue", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_hid_index,
{ "wIndex", "usbhid.setup.wIndex", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_hid_length,
{ "wLength", "usbhid.setup.wLength", FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_hid_report_type,
{ "ReportType", "usbhid.setup.ReportType", FT_UINT8, BASE_DEC,
VALS(usb_hid_report_type_vals), 0x0,
NULL, HFILL }},
{ &hf_usb_hid_report_id,
{ "ReportID", "usbhid.setup.ReportID", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_hid_duration,
{ "Duration", "usbhid.setup.Duration", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_hid_zero,
{ "(zero)", "usbhid.setup.zero", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }}
};
static gint *usb_hid_subtrees[] = {
&ett_usb_hid_report,
&ett_usb_hid_item_header,
&ett_usb_hid_wValue
};
proto_usb_hid = proto_register_protocol("USB HID", "USBHID", "usbhid");
proto_register_field_array(proto_usb_hid, hf, array_length(hf));
proto_register_subtree_array(usb_hid_subtrees, array_length(usb_hid_subtrees));
}
void
proto_reg_handoff_usb_hid(void) {
dissector_handle_t usb_hid_control_handle;
usb_hid_control_handle = new_create_dissector_handle(dissect_usb_hid_control, proto_usb_hid);
dissector_add_uint("usb.control", IF_CLASS_HID, usb_hid_control_handle);
}
