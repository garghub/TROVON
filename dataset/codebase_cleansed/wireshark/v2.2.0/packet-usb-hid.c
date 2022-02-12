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
proto_tree_add_boolean_format_value(tree, hf_usb_hid_mainitem_bit8, tvb, offset, 0, FALSE, "Buffered bytes (default, no second byte present)");
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
proto_tree_add_uint(tree, hf_usb_hid_localitem_usage, tvb, offset, bSize, usage_page);
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
dissect_usb_hid_report_item(packet_info *pinfo _U_, proto_tree *parent_tree, tvbuff_t *tvb, int offset, usb_conv_info_t *usb_conv_info _U_, const struct usb_hid_global_state *global)
{
proto_item *subitem;
proto_tree *tree, *subtree;
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
subtree = proto_tree_add_subtree_format(parent_tree, tvb, offset, bSize + 1,
ett_usb_hid_item_header, &subitem, "%s item (%s)",
val_to_str(bType, usb_hid_item_bType_vals, "Unknown/%u"),
val_to_str(bTag, usb_hid_cur_bTag_vals, "Unknown/%u tag")
);
tree = proto_tree_add_subtree(subtree, tvb, offset, 1, ett_usb_hid_item_header, NULL, "Header");
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
offset = dissect_usb_hid_report_item(pinfo, subtree, tvb, offset, usb_conv_info, &cur_global);
proto_item_set_len(subitem, offset-old_offset);
} else if (bTag == USBHID_MAINITEM_TAG_ENDCOLLECTION) {
break;
}
}
}
return offset;
}
int
dissect_usb_hid_get_report_descriptor(packet_info *pinfo _U_, proto_tree *parent_tree, tvbuff_t *tvb, int offset, usb_conv_info_t *usb_conv_info)
{
proto_item *item;
proto_tree *tree;
int old_offset=offset;
struct usb_hid_global_state initial_global;
memset(&initial_global, 0, sizeof(struct usb_hid_global_state));
item = proto_tree_add_protocol_format(parent_tree, proto_usb_hid, tvb, offset,
-1, "HID Report");
tree = proto_item_add_subtree(item, ett_usb_hid_report);
offset = dissect_usb_hid_report_item(pinfo, tree, tvb, offset, usb_conv_info, &initial_global);
proto_item_set_len(item, offset-old_offset);
return offset;
}
static void
dissect_usb_hid_get_report(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item;
proto_tree *subtree;
if (!is_request)
return;
item = proto_tree_add_item(tree, hf_usb_hid_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hid_wValue);
proto_tree_add_item(subtree, hf_usb_hid_report_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_usb_hid_report_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_usb_hid_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_hid_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
static void
dissect_usb_hid_set_report(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item;
proto_tree *subtree;
if (!is_request)
return;
item = proto_tree_add_item(tree, hf_usb_hid_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hid_wValue);
proto_tree_add_item(subtree, hf_usb_hid_report_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_usb_hid_report_type, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_usb_hid_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_hid_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
static void
dissect_usb_hid_get_idle(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item;
proto_tree *subtree;
if (!is_request)
return;
item = proto_tree_add_item(tree, hf_usb_hid_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hid_wValue);
proto_tree_add_item(subtree, hf_usb_hid_report_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_usb_hid_zero, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_usb_hid_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_hid_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
static void
dissect_usb_hid_set_idle(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_conv_info_t *usb_conv_info _U_)
{
proto_item *item;
proto_tree *subtree;
if (!is_request)
return;
item = proto_tree_add_item(tree, hf_usb_hid_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_usb_hid_wValue);
proto_tree_add_item(subtree, hf_usb_hid_report_id, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(subtree, hf_usb_hid_duration, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(tree, hf_usb_hid_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_hid_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
static void
dissect_usb_hid_get_protocol(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_conv_info_t *usb_conv_info _U_)
{
if (!is_request)
return;
proto_tree_add_item(tree, hf_usb_hid_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_hid_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_hid_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
static void
dissect_usb_hid_set_protocol(packet_info *pinfo _U_, proto_tree *tree, tvbuff_t *tvb, int offset, gboolean is_request, usb_conv_info_t *usb_conv_info _U_)
{
if (!is_request)
return;
proto_tree_add_item(tree, hf_usb_hid_value, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_hid_index, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_hid_length, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
static gint
dissect_usb_hid_boot_keyboard_input_report(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 0;
gboolean shortcut_helper = FALSE;
guint modifier;
guint keycode;
proto_tree_add_item(tree, hf_usbhid_boot_report_keyboard_modifier_right_gui, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_usbhid_boot_report_keyboard_modifier_right_alt, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_usbhid_boot_report_keyboard_modifier_right_shift, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_usbhid_boot_report_keyboard_modifier_right_ctrl, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_usbhid_boot_report_keyboard_modifier_left_gui, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_usbhid_boot_report_keyboard_modifier_left_alt, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_usbhid_boot_report_keyboard_modifier_left_shift, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_usbhid_boot_report_keyboard_modifier_left_ctrl, tvb, offset, 1, ENC_BIG_ENDIAN);
modifier = tvb_get_guint8(tvb, offset);
col_append_str(pinfo->cinfo, COL_INFO, " - ");
if (modifier & 0x80) {
col_append_str(pinfo->cinfo, COL_INFO, "RIGHT GUI");
shortcut_helper = TRUE;
}
if (modifier & 0x40) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, " + ");
col_append_str(pinfo->cinfo, COL_INFO, "RIGHT ALT");
shortcut_helper = TRUE;
}
if (modifier & 0x20) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, " + ");
col_append_str(pinfo->cinfo, COL_INFO, "RIGHT SHIFT");
shortcut_helper = TRUE;
}
if (modifier & 0x10) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, " + ");
col_append_str(pinfo->cinfo, COL_INFO, "RIGHT CTRL");
shortcut_helper = TRUE;
}
if (modifier & 0x08) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, " + ");
col_append_str(pinfo->cinfo, COL_INFO, "LEFT GUI");
shortcut_helper = TRUE;
}
if (modifier & 0x04) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, " + ");
col_append_str(pinfo->cinfo, COL_INFO, "LEFT ALT");
shortcut_helper = TRUE;
}
if (modifier & 0x02) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, " + ");
col_append_str(pinfo->cinfo, COL_INFO, "LEFT SHIFT");
shortcut_helper = TRUE;
}
if (modifier & 0x01) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, " + ");
col_append_str(pinfo->cinfo, COL_INFO, "LEFT CTRL");
shortcut_helper = TRUE;
}
offset += 1;
proto_tree_add_item(tree, hf_usbhid_boot_report_keyboard_reserved, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usbhid_boot_report_keyboard_keycode_1, tvb, offset, 1, ENC_BIG_ENDIAN);
keycode = tvb_get_guint8(tvb, offset);
offset += 1;
if (keycode) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str_ext(keycode, &keycode_vals_ext, "Unknown"));
shortcut_helper = TRUE;
}
proto_tree_add_item(tree, hf_usbhid_boot_report_keyboard_keycode_2, tvb, offset, 1, ENC_BIG_ENDIAN);
keycode = tvb_get_guint8(tvb, offset);
offset += 1;
if (keycode) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str_ext(keycode, &keycode_vals_ext, "Unknown"));
shortcut_helper = TRUE;
}
proto_tree_add_item(tree, hf_usbhid_boot_report_keyboard_keycode_3, tvb, offset, 1, ENC_BIG_ENDIAN);
keycode = tvb_get_guint8(tvb, offset);
offset += 1;
if (keycode) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str_ext(keycode, &keycode_vals_ext, "Unknown"));
shortcut_helper = TRUE;
}
proto_tree_add_item(tree, hf_usbhid_boot_report_keyboard_keycode_4, tvb, offset, 1, ENC_BIG_ENDIAN);
keycode = tvb_get_guint8(tvb, offset);
offset += 1;
if (keycode) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str_ext(keycode, &keycode_vals_ext, "Unknown"));
shortcut_helper = TRUE;
}
proto_tree_add_item(tree, hf_usbhid_boot_report_keyboard_keycode_5, tvb, offset, 1, ENC_BIG_ENDIAN);
keycode = tvb_get_guint8(tvb, offset);
offset += 1;
if (keycode) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str_ext(keycode, &keycode_vals_ext, "Unknown"));
shortcut_helper = TRUE;
}
proto_tree_add_item(tree, hf_usbhid_boot_report_keyboard_keycode_6, tvb, offset, 1, ENC_BIG_ENDIAN);
keycode = tvb_get_guint8(tvb, offset);
offset += 1;
if (keycode) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, " + ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str_ext(keycode, &keycode_vals_ext, "Unknown"));
shortcut_helper = TRUE;
}
if (shortcut_helper == FALSE) {
col_append_str(pinfo->cinfo, COL_INFO, "<action key up>");
}
return offset;
}
static gint
dissect_usb_hid_boot_keyboard_output_report(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 0;
gboolean shortcut_helper = FALSE;
guint leds;
proto_tree_add_item(tree, hf_usbhid_boot_report_keyboard_leds_constants, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_usbhid_boot_report_keyboard_leds_kana, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_usbhid_boot_report_keyboard_leds_compose, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_usbhid_boot_report_keyboard_leds_scroll_lock, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_usbhid_boot_report_keyboard_leds_caps_lock, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_usbhid_boot_report_keyboard_leds_num_lock, tvb, offset, 1, ENC_BIG_ENDIAN);
leds = tvb_get_guint8(tvb, offset);
col_append_str(pinfo->cinfo, COL_INFO, " - LEDs: ");
if (leds & 0x01) {
col_append_str(pinfo->cinfo, COL_INFO, "NumLock");
shortcut_helper = TRUE;
}
if (leds & 0x02) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, ", ");
col_append_str(pinfo->cinfo, COL_INFO, "CapsLock");
shortcut_helper = TRUE;
}
if (leds & 0x04) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, ", ");
col_append_str(pinfo->cinfo, COL_INFO, "ScrollLock");
shortcut_helper = TRUE;
}
if (leds & 0x08) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, ", ");
col_append_str(pinfo->cinfo, COL_INFO, "Compose");
shortcut_helper = TRUE;
}
if (leds & 0x10) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, ", ");
col_append_str(pinfo->cinfo, COL_INFO, "Kana");
shortcut_helper = TRUE;
}
if (leds & 0x20) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, ", ");
col_append_str(pinfo->cinfo, COL_INFO, "Constant1");
shortcut_helper = TRUE;
}
if (leds & 0x40) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, ", ");
col_append_str(pinfo->cinfo, COL_INFO, "Constant2");
shortcut_helper = TRUE;
}
if (leds & 0x80) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, ", ");
col_append_str(pinfo->cinfo, COL_INFO, "Constant3");
}
if (!leds) {
col_append_str(pinfo->cinfo, COL_INFO, "none");
}
offset += 1;
return offset;
}
static gint
dissect_usb_hid_boot_mouse_input_report(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
gint offset = 0;
gboolean shortcut_helper = FALSE;
guint buttons;
proto_tree_add_item(tree, hf_usbhid_boot_report_mouse_button_8, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_usbhid_boot_report_mouse_button_7, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_usbhid_boot_report_mouse_button_6, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_usbhid_boot_report_mouse_button_5, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_usbhid_boot_report_mouse_button_4, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_usbhid_boot_report_mouse_button_middle, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_usbhid_boot_report_mouse_button_right, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_usbhid_boot_report_mouse_button_left, tvb, offset, 1, ENC_BIG_ENDIAN);
buttons = tvb_get_guint8(tvb, offset);
offset += 1;
if (buttons) col_append_str(pinfo->cinfo, COL_INFO, " - ");
if (buttons & 0x01) {
col_append_str(pinfo->cinfo, COL_INFO, "Button LEFT");
shortcut_helper = TRUE;
}
if (buttons & 0x02) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, " + ");
col_append_str(pinfo->cinfo, COL_INFO, "Button RIGHT");
shortcut_helper = TRUE;
}
if (buttons & 0x04) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, " + ");
col_append_str(pinfo->cinfo, COL_INFO, "Button MIDDLE");
}
if (buttons & 0x08) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, " + ");
col_append_str(pinfo->cinfo, COL_INFO, "Button 4");
shortcut_helper = TRUE;
}
if (buttons & 0x10) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, " + ");
col_append_str(pinfo->cinfo, COL_INFO, "Button 5");
shortcut_helper = TRUE;
}
if (buttons & 0x20) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, " + ");
col_append_str(pinfo->cinfo, COL_INFO, "Button 6");
shortcut_helper = TRUE;
}
if (buttons & 0x40) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, " + ");
col_append_str(pinfo->cinfo, COL_INFO, "Button 7");
shortcut_helper = TRUE;
}
if (buttons & 0x80) {
if (shortcut_helper) col_append_str(pinfo->cinfo, COL_INFO, " + ");
col_append_str(pinfo->cinfo, COL_INFO, "Button 8");
}
proto_tree_add_item(tree, hf_usbhid_boot_report_mouse_x_displacement, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
proto_tree_add_item(tree, hf_usbhid_boot_report_mouse_y_displacement, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
if (tvb_reported_length_remaining(tvb, offset)) {
proto_tree_add_item(tree, hf_usbhid_boot_report_mouse_horizontal_scroll_wheel, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
if (tvb_reported_length_remaining(tvb, offset)) {
proto_tree_add_item(tree, hf_usbhid_boot_report_mouse_vertical_scroll_wheel, tvb, offset, 1, ENC_BIG_ENDIAN);
offset += 1;
}
if (tvb_reported_length_remaining(tvb, offset)) {
proto_tree_add_item(tree, hf_usbhid_data, tvb, offset, -1, ENC_NA);
offset += tvb_captured_length_remaining(tvb, offset);
}
return offset;
}
static gint
dissect_usb_hid_control_std_intf(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, usb_conv_info_t *usb_conv_info)
{
gint offset = 0;
usb_trans_info_t *usb_trans_info;
guint8 req;
usb_trans_info = usb_conv_info->usb_trans_info;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "USBHID");
if (usb_trans_info->request_in == pinfo->num) {
req = tvb_get_guint8(tvb, offset);
if (req != USB_SETUP_GET_DESCRIPTOR)
return offset;
col_clear(pinfo->cinfo, COL_INFO);
col_append_fstr(pinfo->cinfo, COL_INFO, "GET DESCRIPTOR Request");
offset += 1;
proto_tree_add_item(tree, hf_usb_hid_bDescriptorIndex, tvb, offset, 1, ENC_LITTLE_ENDIAN);
usb_trans_info->u.get_descriptor.usb_index = tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(tree, hf_usb_hid_bDescriptorType, tvb, offset, 1, ENC_LITTLE_ENDIAN);
usb_trans_info->u.get_descriptor.type = tvb_get_guint8(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str_ext(usb_trans_info->u.get_descriptor.type,
&hid_descriptor_type_vals_ext, "Unknown type %u"));
offset += 1;
proto_tree_add_item(tree, hf_usb_hid_wInterfaceNumber, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(tree, hf_usb_hid_wDescriptorLength, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
else {
col_clear(pinfo->cinfo, COL_INFO);
col_append_fstr(pinfo->cinfo, COL_INFO, "GET DESCRIPTOR Response");
col_append_fstr(pinfo->cinfo, COL_INFO, " %s",
val_to_str_ext(usb_trans_info->u.get_descriptor.type,
&hid_descriptor_type_vals_ext, "Unknown type %u"));
if (usb_trans_info->u.get_descriptor.type == USB_DT_HID_REPORT) {
offset = dissect_usb_hid_get_report_descriptor(
pinfo, tree, tvb, offset, usb_conv_info);
}
}
return offset;
}
static gint
dissect_usb_hid_control_class_intf(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, usb_conv_info_t *usb_conv_info)
{
usb_trans_info_t *usb_trans_info;
gboolean is_request;
int offset = 0;
usb_setup_dissector dissector = NULL;
const usb_setup_dissector_table_t *tmp;
usb_trans_info = usb_conv_info->usb_trans_info;
is_request = (pinfo->srcport==NO_ENDPOINT);
for (tmp = setup_dissectors; tmp->dissector; tmp++) {
if (tmp->request == usb_trans_info->setup.request) {
dissector = tmp->dissector;
break;
}
}
if (!dissector) {
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "USBHID");
col_add_fstr(pinfo->cinfo, COL_INFO, "%s %s",
val_to_str(usb_trans_info->setup.request, setup_request_names_vals, "Unknown type %x"),
is_request ? "Request" : "Response");
if (is_request) {
proto_tree_add_item(tree, hf_usb_hid_request, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset += 1;
}
dissector(pinfo, tree, tvb, offset, is_request, usb_conv_info);
return tvb_captured_length(tvb);
}
static gint
dissect_usb_hid_control(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
usb_conv_info_t *usb_conv_info;
usb_trans_info_t *usb_trans_info;
guint8 type, recip;
usb_conv_info = (usb_conv_info_t *)data;
if (!usb_conv_info)
return 0;
usb_trans_info = usb_conv_info->usb_trans_info;
if (!usb_trans_info)
return 0;
type = USB_TYPE(usb_trans_info->setup.requesttype);
recip = USB_RECIPIENT(usb_trans_info->setup.requesttype);
if (recip == RQT_SETUP_RECIPIENT_INTERFACE) {
if (type == RQT_SETUP_TYPE_STANDARD) {
return dissect_usb_hid_control_std_intf(
tvb, pinfo, tree, usb_conv_info);
}
else if (type == RQT_SETUP_TYPE_CLASS) {
return dissect_usb_hid_control_class_intf(
tvb, pinfo, tree, usb_conv_info);
}
}
return 0;
}
static gint
dissect_usb_hid_class_descriptors(tvbuff_t *tvb, packet_info *pinfo _U_,
proto_tree *tree, void *data _U_)
{
guint8 type;
gint offset = 0;
proto_item *ti;
proto_tree *desc_tree;
guint8 num_desc;
guint i;
type = tvb_get_guint8(tvb, 1);
if (type != USB_DT_HID)
return 0;
desc_tree = proto_tree_add_subtree(tree, tvb, offset, -1, ett_usb_hid_descriptor, &ti, "HID DESCRIPTOR");
dissect_usb_descriptor_header(desc_tree, tvb, offset,
&hid_descriptor_type_vals_ext);
offset += 2;
proto_tree_add_item(desc_tree, hf_usb_hid_bcdHID,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
proto_tree_add_item(desc_tree, hf_usb_hid_bCountryCode,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
num_desc = tvb_get_guint8(tvb, offset);
proto_tree_add_item(desc_tree, hf_usb_hid_bNumDescriptors,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
for (i=0;i<num_desc;i++) {
proto_tree_add_item(desc_tree, hf_usb_hid_bDescriptorType,
tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
proto_tree_add_item(desc_tree, hf_usb_hid_wDescriptorLength,
tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset += 2;
}
proto_item_set_len(ti, offset);
return offset;
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
NULL, HFILL }},
{ &hf_usb_hid_bcdHID,
{ "bcdHID", "usbhid.descriptor.hid.bcdHID", FT_UINT16, BASE_HEX, NULL, 0x0,
NULL, HFILL }},
{ &hf_usb_hid_bCountryCode,
{ "bCountryCode", "usbhid.descriptor.hid.bCountryCode", FT_UINT8,
BASE_HEX, VALS(hid_country_code_vals), 0x0, NULL, HFILL }},
{ &hf_usb_hid_bNumDescriptors,
{ "bNumDescriptors", "usbhid.descriptor.hid.bNumDescriptors", FT_UINT8,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_usb_hid_bDescriptorIndex,
{ "bDescriptorIndex", "usbhid.descriptor.hid.bDescriptorIndex", FT_UINT8,
BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_usb_hid_bDescriptorType,
{ "bDescriptorType", "usbhid.descriptor.hid.bDescriptorType", FT_UINT8,
BASE_HEX|BASE_EXT_STRING, &hid_descriptor_type_vals_ext,
0x00, NULL, HFILL }},
{ &hf_usb_hid_wInterfaceNumber,
{ "wInterfaceNumber", "usbhid.descriptor.hid.wInterfaceNumber", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_usb_hid_wDescriptorLength,
{ "wDescriptorLength", "usbhid.descriptor.hid.wDescriptorLength", FT_UINT16,
BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_usbhid_boot_report_keyboard_reserved,
{ "Reserved", "usbhid.boot_report.keyboard.reserved",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_keyboard_keycode_1,
{ "Keycode 1", "usbhid.boot_report.keyboard.keycode_1",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &keycode_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_keyboard_keycode_2,
{ "Keycode 2", "usbhid.boot_report.keyboard.keycode_2",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &keycode_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_keyboard_keycode_3,
{ "Keycode 3", "usbhid.boot_report.keyboard.keycode_3",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &keycode_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_keyboard_keycode_4,
{ "Keycode 4", "usbhid.boot_report.keyboard.keycode_4",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &keycode_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_keyboard_keycode_5,
{ "Keycode 5", "usbhid.boot_report.keyboard.keycode_5",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &keycode_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_keyboard_keycode_6,
{ "Keycode 6", "usbhid.boot_report.keyboard.keycode_6",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &keycode_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_keyboard_modifier_right_gui,
{ "Modifier: RIGHT GUI", "usbhid.boot_report.keyboard.modifier.right_gui",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_keyboard_modifier_right_alt,
{ "Modifier: RIGHT ALT", "usbhid.boot_report.keyboard.modifier.right_alt",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_keyboard_modifier_right_shift,
{ "Modifier: RIGHT SHIFT", "usbhid.boot_report.keyboard.modifier.right_shift",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_keyboard_modifier_right_ctrl,
{ "Modifier: RIGHT CTRL", "usbhid.boot_report.keyboard.modifier.right_ctrl",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_keyboard_modifier_left_gui,
{ "Modifier: LEFT GUI", "usbhid.boot_report.keyboard.modifier.left_gui",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_keyboard_modifier_left_alt,
{ "Modifier: LEFT ALT", "usbhid.boot_report.keyboard.modifier.left_alt",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_keyboard_modifier_left_shift,
{ "Modifier: LEFT SHIFT", "usbhid.boot_report.keyboard.modifier.left_shift",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_keyboard_modifier_left_ctrl,
{ "Modifier: LEFT CTRL", "usbhid.boot_report.keyboard.modifier.left_ctrl",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_keyboard_leds_constants,
{ "Constants", "usbhid.boot_report.keyboard.leds.constants",
FT_UINT8, BASE_HEX, NULL, 0xE0,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_keyboard_leds_kana,
{ "KANA", "usbhid.boot_report.keyboard.leds.kana",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_keyboard_leds_compose,
{ "COMPOSE", "usbhid.boot_report.keyboard.leds.compose",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_keyboard_leds_scroll_lock,
{ "SCROLL LOCK", "usbhid.boot_report.keyboard.leds.scroll_lock",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_keyboard_leds_caps_lock,
{ "CAPS LOCK", "usbhid.boot_report.keyboard.leds.caps_lock",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_keyboard_leds_num_lock,
{ "NUM LOCK", "usbhid.boot_report.keyboard.leds.num_lock",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_mouse_button_8,
{ "Button 8", "usbhid.boot_report.mouse.button.8",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_mouse_button_7,
{ "Button 7", "usbhid.boot_report.mouse.button.7",
FT_BOOLEAN, 8, NULL, 0x40,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_mouse_button_6,
{ "Button 6", "usbhid.boot_report.mouse.button.6",
FT_BOOLEAN, 8, NULL, 0x20,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_mouse_button_5,
{ "Button 5", "usbhid.boot_report.mouse.button.5",
FT_BOOLEAN, 8, NULL, 0x10,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_mouse_button_4,
{ "Button 4", "usbhid.boot_report.mouse.button.4",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_mouse_button_middle,
{ "Button Middle", "usbhid.boot_report.mouse.button.middle",
FT_BOOLEAN, 8, NULL, 0x04,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_mouse_button_right,
{ "Button Right", "usbhid.boot_report.mouse.button.right",
FT_BOOLEAN, 8, NULL, 0x02,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_mouse_button_left,
{ "Button Left", "usbhid.boot_report.mouse.button.left",
FT_BOOLEAN, 8, NULL, 0x01,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_mouse_x_displacement,
{ "X Displacement", "usbhid.boot_report.mouse.x_displacement",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_mouse_y_displacement,
{ "Y Displacement", "usbhid.boot_report.mouse.y_displacement",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_mouse_horizontal_scroll_wheel,
{ "Horizontal Scroll Wheel", "usbhid.boot_report.mouse.scroll_wheel.horizontal",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_usbhid_boot_report_mouse_vertical_scroll_wheel,
{ "Vertical Scroll Wheel", "usbhid.boot_report.mouse.scroll_wheel.vertical",
FT_INT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_usbhid_data,
{ "Data", "usbhid.data",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
};
static gint *usb_hid_subtrees[] = {
&ett_usb_hid_report,
&ett_usb_hid_item_header,
&ett_usb_hid_wValue,
&ett_usb_hid_descriptor
};
proto_usb_hid = proto_register_protocol("USB HID", "USBHID", "usbhid");
proto_register_field_array(proto_usb_hid, hf, array_length(hf));
proto_register_subtree_array(usb_hid_subtrees, array_length(usb_hid_subtrees));
register_dissector("usbhid.boot_report.keyboard.input", dissect_usb_hid_boot_keyboard_input_report, proto_usb_hid);
register_dissector("usbhid.boot_report.keyboard.output", dissect_usb_hid_boot_keyboard_output_report, proto_usb_hid);
register_dissector("usbhid.boot_report.mouse.input", dissect_usb_hid_boot_mouse_input_report, proto_usb_hid);
}
void
proto_reg_handoff_usb_hid(void)
{
dissector_handle_t usb_hid_control_handle, usb_hid_descr_handle;
usb_hid_control_handle = create_dissector_handle(
dissect_usb_hid_control, proto_usb_hid);
dissector_add_uint("usb.control", IF_CLASS_HID, usb_hid_control_handle);
dissector_add_for_decode_as("usb.device", usb_hid_control_handle);
usb_hid_descr_handle = create_dissector_handle(
dissect_usb_hid_class_descriptors, proto_usb_hid);
dissector_add_uint("usb.descriptor", IF_CLASS_HID, usb_hid_descr_handle);
}
