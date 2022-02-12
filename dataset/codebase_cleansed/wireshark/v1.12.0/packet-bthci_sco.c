static gint
dissect_bthci_sco(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void *data)
{
proto_item *ti;
proto_tree *bthci_sco_tree;
gint offset = 0;
guint16 flags;
hci_data_t *hci_data;
wmem_tree_key_t key[5];
guint32 k_connection_handle;
guint32 k_frame_number;
guint32 k_interface_id;
guint32 k_adapter_id;
remote_bdaddr_t *remote_bdaddr;
const gchar *localhost_name;
guint8 localhost_bdaddr[6];
const gchar *localhost_ether_addr;
gchar *localhost_addr_name;
gint localhost_length;
localhost_bdaddr_entry_t *localhost_bdaddr_entry;
localhost_name_entry_t *localhost_name_entry;
ti = proto_tree_add_item(tree, proto_bthci_sco, tvb, offset, -1, ENC_NA);
bthci_sco_tree = proto_item_add_subtree(ti, ett_bthci_sco);
switch (pinfo->p2p_dir) {
case P2P_DIR_SENT:
col_set_str(pinfo->cinfo, COL_INFO, "Sent ");
break;
case P2P_DIR_RECV:
col_set_str(pinfo->cinfo, COL_INFO, "Rcvd ");
break;
default:
col_add_fstr(pinfo->cinfo, COL_INFO, "Unknown direction %d ",
pinfo->p2p_dir);
break;
}
proto_tree_add_item(bthci_sco_tree, hf_bthci_sco_chandle, tvb, offset, 2, ENC_LITTLE_ENDIAN);
flags = tvb_get_letohs(tvb, offset);
offset += 2;
proto_tree_add_item(bthci_sco_tree, hf_bthci_sco_length, tvb, offset, 1, ENC_LITTLE_ENDIAN);
offset++;
hci_data = (hci_data_t *) data;
DISSECTOR_ASSERT(hci_data);
k_interface_id = hci_data->interface_id;
k_adapter_id = hci_data->adapter_id;
k_connection_handle = flags & 0x0fff;
k_frame_number = pinfo->fd->num;
key[0].length = 1;
key[0].key = &k_interface_id;
key[1].length = 1;
key[1].key = &k_adapter_id;
key[2].length = 1;
key[2].key = &k_connection_handle;
key[3].length = 1;
key[3].key = &k_frame_number;
key[4].length = 0;
key[4].key = NULL;
remote_bdaddr = (remote_bdaddr_t *)wmem_tree_lookup32_array_le(hci_data->chandle_to_bdaddr_table, key);
if (remote_bdaddr && remote_bdaddr->interface_id == hci_data->interface_id &&
remote_bdaddr->adapter_id == hci_data->adapter_id &&
remote_bdaddr->chandle == (flags & 0x0fff)) {
guint32 k_bd_addr_oui;
guint32 k_bd_addr_id;
guint32 bd_addr_oui;
guint32 bd_addr_id;
device_name_t *device_name;
const gchar *remote_name;
const gchar *remote_ether_addr;
gchar *remote_addr_name;
gint remote_length;
bd_addr_oui = remote_bdaddr->bd_addr[0] << 16 | remote_bdaddr->bd_addr[1] << 8 | remote_bdaddr->bd_addr[2];
bd_addr_id = remote_bdaddr->bd_addr[3] << 16 | remote_bdaddr->bd_addr[4] << 8 | remote_bdaddr->bd_addr[5];
k_bd_addr_oui = bd_addr_oui;
k_bd_addr_id = bd_addr_id;
k_frame_number = pinfo->fd->num;
key[0].length = 1;
key[0].key = &k_bd_addr_id;
key[1].length = 1;
key[1].key = &k_bd_addr_oui;
key[2].length = 1;
key[2].key = &k_frame_number;
key[3].length = 0;
key[3].key = NULL;
device_name = (device_name_t *)wmem_tree_lookup32_array_le(hci_data->bdaddr_to_name_table, key);
if (device_name && device_name->bd_addr_oui == bd_addr_oui && device_name->bd_addr_id == bd_addr_id)
remote_name = device_name->name;
else
remote_name = "";
remote_ether_addr = get_ether_name(remote_bdaddr->bd_addr);
remote_length = (gint)(strlen(remote_ether_addr) + 3 + strlen(remote_name) + 1);
remote_addr_name = (gchar *)wmem_alloc(pinfo->pool, remote_length);
g_snprintf(remote_addr_name, remote_length, "%s (%s)", remote_ether_addr, remote_name);
if (pinfo->p2p_dir == P2P_DIR_RECV) {
SET_ADDRESS(&pinfo->net_src, AT_STRINGZ, (int)strlen(remote_name) + 1, remote_name);
SET_ADDRESS(&pinfo->dl_src, AT_ETHER, 6, remote_bdaddr->bd_addr);
SET_ADDRESS(&pinfo->src, AT_STRINGZ, (int)strlen(remote_addr_name) + 1, remote_addr_name);
} else if (pinfo->p2p_dir == P2P_DIR_SENT) {
SET_ADDRESS(&pinfo->net_dst, AT_STRINGZ, (int)strlen(remote_name) + 1, remote_name);
SET_ADDRESS(&pinfo->dl_dst, AT_ETHER, 6, remote_bdaddr->bd_addr);
SET_ADDRESS(&pinfo->dst, AT_STRINGZ, (int)strlen(remote_addr_name) + 1, remote_addr_name);
}
} else {
if (pinfo->p2p_dir == P2P_DIR_RECV) {
SET_ADDRESS(&pinfo->net_src, AT_STRINGZ, 1, "");
SET_ADDRESS(&pinfo->dl_src, AT_STRINGZ, 1, "");
SET_ADDRESS(&pinfo->src, AT_STRINGZ, 10, "remote ()");
} else if (pinfo->p2p_dir == P2P_DIR_SENT) {
SET_ADDRESS(&pinfo->net_dst, AT_STRINGZ, 1, "");
SET_ADDRESS(&pinfo->dl_dst, AT_STRINGZ, 1, "");
SET_ADDRESS(&pinfo->dst, AT_STRINGZ, 10, "remote ()");
}
}
k_interface_id = hci_data->interface_id;
k_adapter_id = hci_data->adapter_id;
k_frame_number = pinfo->fd->num;
key[0].length = 1;
key[0].key = &k_interface_id;
key[1].length = 1;
key[1].key = &k_adapter_id;
key[2].length = 1;
key[2].key = &k_frame_number;
key[3].length = 0;
key[3].key = NULL;
localhost_bdaddr_entry = (localhost_bdaddr_entry_t *)wmem_tree_lookup32_array_le(hci_data->localhost_bdaddr, key);
if (localhost_bdaddr_entry && localhost_bdaddr_entry->interface_id == hci_data->interface_id &&
localhost_bdaddr_entry->adapter_id == hci_data->adapter_id) {
localhost_ether_addr = get_ether_name(localhost_bdaddr_entry->bd_addr);
memcpy(localhost_bdaddr, localhost_bdaddr_entry->bd_addr, 6);
} else {
localhost_ether_addr = "localhost";
memset(localhost_bdaddr, 0, 6);
}
localhost_name_entry = (localhost_name_entry_t *)wmem_tree_lookup32_array_le(hci_data->localhost_name, key);
if (localhost_name_entry && localhost_name_entry->interface_id == hci_data->interface_id &&
localhost_name_entry->adapter_id == hci_data->adapter_id)
localhost_name = localhost_name_entry->name;
else
localhost_name = "";
localhost_length = (gint)(strlen(localhost_ether_addr) + 3 + strlen(localhost_name) + 1);
localhost_addr_name = (gchar *)wmem_alloc(pinfo->pool, localhost_length);
g_snprintf(localhost_addr_name, localhost_length, "%s (%s)", localhost_ether_addr, localhost_name);
if (pinfo->p2p_dir == P2P_DIR_RECV) {
SET_ADDRESS(&pinfo->net_dst, AT_STRINGZ, (int)strlen(localhost_name) + 1, localhost_name);
SET_ADDRESS(&pinfo->dl_dst, AT_ETHER, 6, localhost_bdaddr);
SET_ADDRESS(&pinfo->dst, AT_STRINGZ, (int)strlen(localhost_addr_name) + 1, localhost_addr_name);
} else if (pinfo->p2p_dir == P2P_DIR_SENT) {
SET_ADDRESS(&pinfo->net_src, AT_STRINGZ, (int)strlen(localhost_name) + 1, localhost_name);
SET_ADDRESS(&pinfo->dl_src, AT_ETHER, 6, localhost_bdaddr);
SET_ADDRESS(&pinfo->src, AT_STRINGZ, (int)strlen(localhost_addr_name) + 1, localhost_addr_name);
}
proto_tree_add_item(bthci_sco_tree, hf_bthci_sco_data, tvb, offset, -1, ENC_NA);
return tvb_length(tvb);
}
void
proto_register_bthci_sco(void)
{
static hf_register_info hf[] = {
{ &hf_bthci_sco_chandle,
{ "Connection Handle", "bthci_sco.chandle",
FT_UINT16, BASE_HEX, NULL, 0x0FFF,
NULL, HFILL }
},
{ &hf_bthci_sco_length,
{ "Data Total Length", "bthci_sco.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_bthci_sco_data,
{ "Data", "bthci_sco.data",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_bthci_sco
};
proto_bthci_sco = proto_register_protocol("Bluetooth HCI SCO Packet", "HCI_SCO", "bthci_sco");
bthci_sco_handle = new_register_dissector("bthci_sco", dissect_bthci_sco, proto_bthci_sco);
proto_register_field_array(proto_bthci_sco, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_bthci_sco(void)
{
dissector_add_uint("hci_h4.type", HCI_H4_TYPE_SCO, bthci_sco_handle);
dissector_add_uint("hci_h1.type", BTHCI_CHANNEL_SCO, bthci_sco_handle);
}
