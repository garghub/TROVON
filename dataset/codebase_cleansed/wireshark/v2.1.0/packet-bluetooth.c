static void bluetooth_uuid_prompt(packet_info *pinfo, gchar* result)
{
gchar *value_data;
value_data = (gchar *) p_get_proto_data(pinfo->pool, pinfo, proto_bluetooth, PROTO_DATA_BLUETOOTH_SERVICE_UUID);
if (value_data)
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "BT Service UUID %s as", (gchar *) value_data);
else
g_snprintf(result, MAX_DECODE_AS_PROMPT_LEN, "Unknown BT Service UUID");
}
static gpointer bluetooth_uuid_value(packet_info *pinfo)
{
gchar *value_data;
value_data = (gchar *) p_get_proto_data(pinfo->pool, pinfo, proto_bluetooth, PROTO_DATA_BLUETOOTH_SERVICE_UUID);
if (value_data)
return (gpointer) value_data;
return NULL;
}
gint
dissect_bd_addr(gint hf_bd_addr, packet_info *pinfo, proto_tree *tree,
tvbuff_t *tvb, gint offset, gboolean is_local_bd_addr,
guint32 interface_id, guint32 adapter_id, guint8 *bdaddr)
{
guint8 bd_addr[6];
bd_addr[5] = tvb_get_guint8(tvb, offset);
bd_addr[4] = tvb_get_guint8(tvb, offset + 1);
bd_addr[3] = tvb_get_guint8(tvb, offset + 2);
bd_addr[2] = tvb_get_guint8(tvb, offset + 3);
bd_addr[1] = tvb_get_guint8(tvb, offset + 4);
bd_addr[0] = tvb_get_guint8(tvb, offset + 5);
proto_tree_add_ether(tree, hf_bd_addr, tvb, offset, 6, bd_addr);
offset += 6;
if (have_tap_listener(bluetooth_device_tap)) {
bluetooth_device_tap_t *tap_device;
tap_device = wmem_new(wmem_packet_scope(), bluetooth_device_tap_t);
tap_device->interface_id = interface_id;
tap_device->adapter_id = adapter_id;
memcpy(tap_device->bd_addr, bd_addr, 6);
tap_device->has_bd_addr = TRUE;
tap_device->is_local = is_local_bd_addr;
tap_device->type = BLUETOOTH_DEVICE_BD_ADDR;
tap_queue_packet(bluetooth_device_tap, pinfo, tap_device);
}
if (bdaddr)
memcpy(bdaddr, bd_addr, 6);
return offset;
}
void
save_local_device_name_from_eir_ad(tvbuff_t *tvb, gint offset, packet_info *pinfo,
guint8 size, bluetooth_data_t *bluetooth_data)
{
gint i = 0;
guint8 length;
wmem_tree_key_t key[4];
guint32 k_interface_id;
guint32 k_adapter_id;
guint32 k_frame_number;
gchar *name;
localhost_name_entry_t *localhost_name_entry;
if (!(!pinfo->fd->flags.visited && bluetooth_data)) return;
while (i < size) {
length = tvb_get_guint8(tvb, offset + i);
if (length == 0) break;
switch(tvb_get_guint8(tvb, offset + i + 1)) {
case 0x08:
case 0x09:
name = tvb_get_string_enc(wmem_packet_scope(), tvb, offset + i + 2, length - 1, ENC_ASCII);
k_interface_id = bluetooth_data->interface_id;
k_adapter_id = bluetooth_data->adapter_id;
k_frame_number = pinfo->num;
key[0].length = 1;
key[0].key = &k_interface_id;
key[1].length = 1;
key[1].key = &k_adapter_id;
key[2].length = 1;
key[2].key = &k_frame_number;
key[3].length = 0;
key[3].key = NULL;
localhost_name_entry = (localhost_name_entry_t *) wmem_new(wmem_file_scope(), localhost_name_entry_t);
localhost_name_entry->interface_id = k_interface_id;
localhost_name_entry->adapter_id = k_adapter_id;
localhost_name_entry->name = wmem_strdup(wmem_file_scope(), name);
wmem_tree_insert32_array(bluetooth_data->localhost_name, key, localhost_name_entry);
break;
}
i += length + 1;
}
}
static const char* bluetooth_conv_get_filter_type(conv_item_t* conv, conv_filter_type_e filter)
{
if (filter == CONV_FT_SRC_ADDRESS) {
if (conv->src_address.type == AT_ETHER)
return "bluetooth.src";
else if (conv->src_address.type == AT_STRINGZ)
return "bluetooth.src_str";
}
if (filter == CONV_FT_DST_ADDRESS) {
if (conv->dst_address.type == AT_ETHER)
return "bluetooth.dst";
else if (conv->dst_address.type == AT_STRINGZ)
return "bluetooth.dst_str";
}
if (filter == CONV_FT_ANY_ADDRESS) {
if (conv->src_address.type == AT_ETHER && conv->dst_address.type == AT_ETHER)
return "bluetooth.addr";
else if (conv->src_address.type == AT_STRINGZ && conv->dst_address.type == AT_STRINGZ)
return "bluetooth.addr_str";
}
return CONV_FILTER_INVALID;
}
static const char* bluetooth_get_filter_type(hostlist_talker_t* host, conv_filter_type_e filter)
{
if (filter == CONV_FT_ANY_ADDRESS) {
if (host->myaddress.type == AT_ETHER)
return "bluetooth.addr";
else if (host->myaddress.type == AT_STRINGZ)
return "bluetooth.addr_str";
}
return CONV_FILTER_INVALID;
}
static int
bluetooth_conversation_packet(void *pct, packet_info *pinfo,
epan_dissect_t *edt _U_, const void *vip _U_)
{
conv_hash_t *hash = (conv_hash_t*) pct;
add_conversation_table_data(hash, &pinfo->dl_src, &pinfo->dl_dst, 0, 0, 1,
pinfo->fd->pkt_len, &pinfo->rel_ts, &pinfo->abs_ts,
&bluetooth_ct_dissector_info, PT_NONE);
return 1;
}
static int
bluetooth_hostlist_packet(void *pit, packet_info *pinfo,
epan_dissect_t *edt _U_, const void *vip _U_)
{
conv_hash_t *hash = (conv_hash_t*) pit;
add_hostlist_table_data(hash, &pinfo->dl_src, 0, TRUE, 1, pinfo->fd->pkt_len, &bluetooth_dissector_info, PT_NONE);
add_hostlist_table_data(hash, &pinfo->dl_dst, 0, FALSE, 1, pinfo->fd->pkt_len, &bluetooth_dissector_info, PT_NONE);
return 1;
}
static conversation_t *
get_conversation(packet_info *pinfo,
address *src_addr, address *dst_addr,
guint32 src_endpoint, guint32 dst_endpoint)
{
conversation_t *conversation;
conversation = find_conversation(pinfo->num,
src_addr, dst_addr,
pinfo->ptype,
src_endpoint, dst_endpoint, 0);
if (conversation) {
return conversation;
}
conversation = conversation_new(pinfo->num,
src_addr, dst_addr,
pinfo->ptype,
src_endpoint, dst_endpoint, 0);
return conversation;
}
bluetooth_uuid_t
get_uuid(tvbuff_t *tvb, gint offset, gint size)
{
bluetooth_uuid_t uuid;
memset(&uuid, 0, sizeof(uuid));
if (size != 2 && size != 16) {
return uuid;
}
uuid.size = size;
if (size == 2) {
uuid.data[0] = tvb_get_guint8(tvb, offset + 1);
uuid.data[1] = tvb_get_guint8(tvb, offset);
} else if (size == 16) {
uuid.data[0] = tvb_get_guint8(tvb, offset + 15);
uuid.data[1] = tvb_get_guint8(tvb, offset + 14);
uuid.data[2] = tvb_get_guint8(tvb, offset + 13);
uuid.data[3] = tvb_get_guint8(tvb, offset + 12);
uuid.data[4] = tvb_get_guint8(tvb, offset + 11);
uuid.data[5] = tvb_get_guint8(tvb, offset + 10);
uuid.data[6] = tvb_get_guint8(tvb, offset + 9);
uuid.data[7] = tvb_get_guint8(tvb, offset + 8);
uuid.data[8] = tvb_get_guint8(tvb, offset + 7);
uuid.data[9] = tvb_get_guint8(tvb, offset + 6);
uuid.data[10] = tvb_get_guint8(tvb, offset + 5);
uuid.data[11] = tvb_get_guint8(tvb, offset + 4);
uuid.data[12] = tvb_get_guint8(tvb, offset + 3);
uuid.data[13] = tvb_get_guint8(tvb, offset + 2);
uuid.data[14] = tvb_get_guint8(tvb, offset + 1);
uuid.data[15] = tvb_get_guint8(tvb, offset);
}
if (size == 2) {
uuid.bt_uuid = uuid.data[1] | uuid.data[0] << 8;
} else {
if (uuid.data[0] == 0x00 && uuid.data[1] == 0x00 &&
uuid.data[4] == 0x00 && uuid.data[5] == 0x00 && uuid.data[6] == 0x10 &&
uuid.data[7] == 0x00 && uuid.data[8] == 0x80 && uuid.data[9] == 0x00 &&
uuid.data[10] == 0x00 && uuid.data[11] == 0x80 && uuid.data[12] == 0x5F &&
uuid.data[13] == 0x9B && uuid.data[14] == 0x34 && uuid.data[15] == 0xFB)
uuid.bt_uuid = uuid.data[2] | uuid.data[3] << 8;
}
return uuid;
}
const gchar *
print_numeric_uuid(bluetooth_uuid_t *uuid)
{
if (!(uuid && uuid->size > 0))
return NULL;
if (uuid->size != 16) {
return bytes_to_str(wmem_packet_scope(), uuid->data, uuid->size);
} else {
gchar *text;
text = (gchar *) wmem_alloc(wmem_packet_scope(), 38);
bytes_to_hexstr(&text[0], uuid->data, 4);
text[8] = '-';
bytes_to_hexstr(&text[9], uuid->data + 4, 2);
text[13] = '-';
bytes_to_hexstr(&text[14], uuid->data + 4 + 2 * 1, 2);
text[18] = '-';
bytes_to_hexstr(&text[19], uuid->data + 4 + 2 * 2, 2);
text[23] = '-';
bytes_to_hexstr(&text[24], uuid->data + 4 + 2 * 3, 6);
text[36] = '\0';
return text;
}
return NULL;
}
const gchar *
print_uuid(bluetooth_uuid_t *uuid)
{
const gchar *description;
if (uuid->bt_uuid) {
const gchar *name;
name = try_val_to_str_ext(uuid->bt_uuid, &bluetooth_uuid_vals_ext);
if (name != NULL) {
return name;
}
}
description = print_numeric_uuid(uuid);
if (description) {
description = (const gchar *) wmem_tree_lookup_string(bluetooth_uuids, description, 0);
if (description)
return description;
}
return "Unknown";
}
static bluetooth_data_t *
dissect_bluetooth_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *main_item;
proto_tree *main_tree;
proto_item *sub_item;
bluetooth_data_t *bluetooth_data;
address *src;
address *dst;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Bluetooth");
switch (pinfo->p2p_dir) {
case P2P_DIR_SENT:
col_add_fstr(pinfo->cinfo, COL_INFO, "Sent ");
break;
case P2P_DIR_RECV:
col_add_fstr(pinfo->cinfo, COL_INFO, "Rcvd ");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "UnknownDirection ");
break;
}
pinfo->ptype = PT_BLUETOOTH;
get_conversation(pinfo, &pinfo->dl_src, &pinfo->dl_dst, pinfo->srcport, pinfo->destport);
main_item = proto_tree_add_item(tree, proto_bluetooth, tvb, 0, tvb_captured_length(tvb), ENC_NA);
main_tree = proto_item_add_subtree(main_item, ett_bluetooth);
bluetooth_data = (bluetooth_data_t *) wmem_new(wmem_packet_scope(), bluetooth_data_t);
if (pinfo->phdr->presence_flags & WTAP_HAS_INTERFACE_ID)
bluetooth_data->interface_id = pinfo->phdr->interface_id;
else
bluetooth_data->interface_id = HCI_INTERFACE_DEFAULT;
bluetooth_data->adapter_id = HCI_ADAPTER_DEFAULT;
bluetooth_data->adapter_disconnect_in_frame = &max_disconnect_in_frame;
bluetooth_data->chandle_sessions = chandle_sessions;
bluetooth_data->chandle_to_bdaddr = chandle_to_bdaddr;
bluetooth_data->chandle_to_mode = chandle_to_mode;
bluetooth_data->bdaddr_to_name = bdaddr_to_name;
bluetooth_data->bdaddr_to_role = bdaddr_to_role;
bluetooth_data->localhost_bdaddr = localhost_bdaddr;
bluetooth_data->localhost_name = localhost_name;
bluetooth_data->hci_vendors = hci_vendors;
if (have_tap_listener(bluetooth_tap)) {
bluetooth_tap_data_t *bluetooth_tap_data;
bluetooth_tap_data = wmem_new(wmem_packet_scope(), bluetooth_tap_data_t);
bluetooth_tap_data->interface_id = bluetooth_data->interface_id;
bluetooth_tap_data->adapter_id = bluetooth_data->adapter_id;
tap_queue_packet(bluetooth_tap, pinfo, bluetooth_tap_data);
}
src = (address *) p_get_proto_data(wmem_file_scope(), pinfo, proto_bluetooth, BLUETOOTH_DATA_SRC);
dst = (address *) p_get_proto_data(wmem_file_scope(), pinfo, proto_bluetooth, BLUETOOTH_DATA_DST);
if (src && src->type == AT_STRINGZ) {
sub_item = proto_tree_add_string(main_tree, hf_bluetooth_addr_str, tvb, 0, 0, (const char *) src->data);
PROTO_ITEM_SET_HIDDEN(sub_item);
sub_item = proto_tree_add_string(main_tree, hf_bluetooth_src_str, tvb, 0, 0, (const char *) src->data);
PROTO_ITEM_SET_GENERATED(sub_item);
} else if (src && src->type == AT_ETHER) {
sub_item = proto_tree_add_ether(main_tree, hf_bluetooth_addr, tvb, 0, 0, (const guint8 *) src->data);
PROTO_ITEM_SET_HIDDEN(sub_item);
sub_item = proto_tree_add_ether(main_tree, hf_bluetooth_src, tvb, 0, 0, (const guint8 *) src->data);
PROTO_ITEM_SET_GENERATED(sub_item);
}
if (dst && dst->type == AT_STRINGZ) {
sub_item = proto_tree_add_string(main_tree, hf_bluetooth_addr_str, tvb, 0, 0, (const char *) dst->data);
PROTO_ITEM_SET_HIDDEN(sub_item);
sub_item = proto_tree_add_string(main_tree, hf_bluetooth_dst_str, tvb, 0, 0, (const char *) dst->data);
PROTO_ITEM_SET_GENERATED(sub_item);
} else if (dst && dst->type == AT_ETHER) {
sub_item = proto_tree_add_ether(main_tree, hf_bluetooth_addr, tvb, 0, 0, (const guint8 *) dst->data);
PROTO_ITEM_SET_HIDDEN(sub_item);
sub_item = proto_tree_add_ether(main_tree, hf_bluetooth_dst, tvb, 0, 0, (const guint8 *) dst->data);
PROTO_ITEM_SET_GENERATED(sub_item);
}
return bluetooth_data;
}
static gint
dissect_bluetooth(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
bluetooth_data_t *bluetooth_data;
bluetooth_data = dissect_bluetooth_common(tvb, pinfo, tree);
bluetooth_data->previous_protocol_data_type = BT_PD_NONE;
bluetooth_data->previous_protocol_data.none = NULL;
if (!dissector_try_uint_new(bluetooth_table, pinfo->phdr->pkt_encap, tvb, pinfo, tree, TRUE, bluetooth_data)) {
call_data_dissector(tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
static gint
dissect_bluetooth_bthci(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
bluetooth_data_t *bluetooth_data;
bluetooth_data = dissect_bluetooth_common(tvb, pinfo, tree);
bluetooth_data->previous_protocol_data_type = BT_PD_BTHCI;
bluetooth_data->previous_protocol_data.bthci = (struct bthci_phdr *)data;
if (!dissector_try_uint_new(bluetooth_table, pinfo->phdr->pkt_encap, tvb, pinfo, tree, TRUE, bluetooth_data)) {
call_data_dissector(tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
static gint
dissect_bluetooth_btmon(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
bluetooth_data_t *bluetooth_data;
bluetooth_data = dissect_bluetooth_common(tvb, pinfo, tree);
bluetooth_data->previous_protocol_data_type = BT_PD_BTMON;
bluetooth_data->previous_protocol_data.btmon = (struct btmon_phdr *)data;
if (!dissector_try_uint_new(bluetooth_table, pinfo->phdr->pkt_encap, tvb, pinfo, tree, TRUE, bluetooth_data)) {
call_data_dissector(tvb, pinfo, tree);
}
return tvb_captured_length(tvb);
}
static gint
dissect_bluetooth_usb(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
bluetooth_data_t *bluetooth_data;
bluetooth_data = dissect_bluetooth_common(tvb, pinfo, tree);
bluetooth_data->previous_protocol_data_type = BT_PD_USB_CONV_INFO;
bluetooth_data->previous_protocol_data.usb_conv_info = (usb_conv_info_t *)data;
return call_dissector_with_data(hci_usb_handle, tvb, pinfo, tree, bluetooth_data);
}
static gint
dissect_bluetooth_ubertooth(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
bluetooth_data_t *bluetooth_data;
bluetooth_data = dissect_bluetooth_common(tvb, pinfo, tree);
bluetooth_data->previous_protocol_data_type = BT_PD_UBERTOOTH_DATA;
bluetooth_data->previous_protocol_data.ubertooth_data = (ubertooth_data_t *)data;
call_dissector(btle_handle, tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
void
proto_register_bluetooth(void)
{
static hf_register_info hf[] = {
{ &hf_bluetooth_src,
{ "Source", "bluetooth.src",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bluetooth_dst,
{ "Destination", "bluetooth.dst",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bluetooth_addr,
{ "Source or Destination", "bluetooth.addr",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bluetooth_src_str,
{ "Source", "bluetooth.src_str",
FT_STRING, STR_ASCII, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bluetooth_dst_str,
{ "Destination", "bluetooth.dst_str",
FT_STRING, STR_ASCII, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bluetooth_addr_str,
{ "Source or Destination", "bluetooth.addr_str",
FT_STRING, STR_ASCII, NULL, 0x0,
NULL, HFILL }
},
};
static hf_register_info oui_hf[] = {
{ &hf_llc_bluetooth_pid,
{ "PID", "llc.bluetooth_pid",
FT_UINT16, BASE_HEX, VALS(bluetooth_pid_vals), 0x0,
"Protocol ID", HFILL }
}
};
static gint *ett[] = {
&ett_bluetooth,
};
static build_valid_func bluetooth_uuid_da_build_value[1] = {bluetooth_uuid_value};
static decode_as_value_t bluetooth_uuid_da_values = {bluetooth_uuid_prompt, 1, bluetooth_uuid_da_build_value};
static decode_as_t bluetooth_uuid_da = {"bluetooth", "BT Service UUID", "bluetooth.uuid", 1, 0, &bluetooth_uuid_da_values, NULL, NULL,
decode_as_default_populate_list, decode_as_default_reset, decode_as_default_change, NULL};
proto_bluetooth = proto_register_protocol("Bluetooth",
"Bluetooth", "bluetooth");
register_dissector("bluetooth_ubertooth", dissect_bluetooth_ubertooth, proto_bluetooth);
proto_register_field_array(proto_bluetooth, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
bluetooth_table = register_dissector_table("bluetooth.encap",
"Bluetooth Encapsulation", proto_bluetooth, FT_UINT32, BASE_HEX, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
chandle_sessions = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
chandle_to_bdaddr = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
chandle_to_mode = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
bdaddr_to_name = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
bdaddr_to_role = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
localhost_bdaddr = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
localhost_name = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
hci_vendors = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
hci_vendor_table = register_dissector_table("bluetooth.vendor", "HCI Vendor", proto_bluetooth, FT_UINT16, BASE_HEX, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
bluetooth_uuids = wmem_tree_new(wmem_epan_scope());
bluetooth_tap = register_tap("bluetooth");
bluetooth_device_tap = register_tap("bluetooth.device");
bluetooth_hci_summary_tap = register_tap("bluetooth.hci_summary");
bluetooth_uuid_table = register_dissector_table("bluetooth.uuid", "BT Service UUID", proto_bluetooth, FT_STRING, BASE_NONE, DISSECTOR_TABLE_NOT_ALLOW_DUPLICATE);
llc_add_oui(OUI_BLUETOOTH, "llc.bluetooth_pid", "LLC Bluetooth OUI PID", oui_hf, proto_bluetooth);
register_conversation_table(proto_bluetooth, TRUE, bluetooth_conversation_packet, bluetooth_hostlist_packet);
register_decode_as(&bluetooth_uuid_da);
}
void
proto_reg_handoff_bluetooth(void)
{
dissector_handle_t bluetooth_handle = create_dissector_handle(dissect_bluetooth, proto_bluetooth);
dissector_handle_t bluetooth_bthci_handle = create_dissector_handle(dissect_bluetooth_bthci, proto_bluetooth);
dissector_handle_t bluetooth_btmon_handle = create_dissector_handle(dissect_bluetooth_btmon, proto_bluetooth);
dissector_handle_t bluetooth_usb_handle = create_dissector_handle(dissect_bluetooth_usb, proto_bluetooth);
dissector_handle_t eapol_handle;
dissector_handle_t btl2cap_handle;
btle_handle = find_dissector_add_dependency("btle", proto_bluetooth);
hci_usb_handle = find_dissector_add_dependency("hci_usb", proto_bluetooth);
dissector_add_uint("wtap_encap", WTAP_ENCAP_BLUETOOTH_HCI, bluetooth_bthci_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_BLUETOOTH_H4, bluetooth_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_BLUETOOTH_H4_WITH_PHDR, bluetooth_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_BLUETOOTH_LINUX_MONITOR, bluetooth_btmon_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_PACKETLOGGER, bluetooth_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_BLUETOOTH_LE_LL, bluetooth_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_BLUETOOTH_LE_LL_WITH_PHDR, bluetooth_handle);
dissector_add_uint("wtap_encap", WTAP_ENCAP_BLUETOOTH_BREDR_BB, bluetooth_handle);
dissector_add_uint("usb.product", (0x0a5c << 16) | 0x21e8, bluetooth_usb_handle);
dissector_add_uint("usb.product", (0x1131 << 16) | 0x1001, bluetooth_usb_handle);
dissector_add_uint("usb.product", (0x050d << 16) | 0x0081, bluetooth_usb_handle);
dissector_add_uint("usb.product", (0x0a5c << 16) | 0x2198, bluetooth_usb_handle);
dissector_add_uint("usb.product", (0x0a5c << 16) | 0x21e8, bluetooth_usb_handle);
dissector_add_uint("usb.product", (0x04bf << 16) | 0x0320, bluetooth_usb_handle);
dissector_add_uint("usb.product", (0x13d3 << 16) | 0x3375, bluetooth_usb_handle);
dissector_add_uint("usb.protocol", 0xE00101, bluetooth_usb_handle);
dissector_add_uint("usb.protocol", 0xE00104, bluetooth_usb_handle);
dissector_add_for_decode_as("usb.device", bluetooth_usb_handle);
wmem_tree_insert_string(bluetooth_uuids, "00000001-0000-1000-8000-0002EE000002", "SyncML Server", 0);
wmem_tree_insert_string(bluetooth_uuids, "00000002-0000-1000-8000-0002EE000002", "SyncML Client", 0);
eapol_handle = find_dissector("eapol");
btl2cap_handle = find_dissector("btl2cap");
dissector_add_uint("llc.bluetooth_pid", AMP_C_SECURITY_FRAME, eapol_handle);
dissector_add_uint("llc.bluetooth_pid", AMP_U_L2CAP, btl2cap_handle);
}
