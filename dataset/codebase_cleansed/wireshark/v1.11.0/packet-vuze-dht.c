static int
dissect_vuze_dht_address(tvbuff_t *tvb, packet_info _U_*pinfo, proto_tree *tree, int offset, const char* addr_name)
{
guint8 ip_length;
proto_tree *sub_tree;
proto_item *ti;
address addr;
ip_length = tvb_get_guint8(tvb,offset);
ti = proto_tree_add_none_format(tree, hf_vuze_dht_address, tvb, offset, ip_length+3, "%s: ", addr_name );
sub_tree = proto_item_add_subtree(ti, ett_vuze_dht_address);
proto_tree_add_item(sub_tree, hf_vuze_dht_address_len, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN);
offset += TL_BYTE;
switch(ip_length)
{
case TL_IPv4:
proto_tree_add_item(sub_tree, hf_vuze_dht_address_v4, tvb, offset, ip_length, ENC_BIG_ENDIAN);
TVB_SET_ADDRESS( &addr, AT_IPv4, tvb, offset, ip_length);
break;
case TL_IPv6:
proto_tree_add_item(sub_tree, hf_vuze_dht_address_v6, tvb, offset, ip_length, ENC_NA);
TVB_SET_ADDRESS( &addr, AT_IPv6, tvb, offset, ip_length);
break;
default:
addr.type = AT_NONE;
break;
}
offset += ip_length;
proto_tree_add_item(sub_tree, hf_vuze_dht_address_port, tvb, offset, TL_SHORT, ENC_BIG_ENDIAN);
proto_item_append_text( ti, "%s:%d", ep_address_to_str( &addr ), tvb_get_ntohs(tvb,offset) );
offset += TL_SHORT;
return offset;
}
static int
dissect_vuze_dht_contact(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset)
{
proto_item *ti;
proto_tree *sub_tree;
ti = proto_tree_add_none_format( tree, hf_vuze_dht_contact, tvb, offset, tvb_get_guint8(tvb,offset+2)+5,
"%s contact, version %d",
val_to_str_const( tvb_get_guint8(tvb, offset), vuze_dht_contact_type_vals, "Unknown"),
tvb_get_guint8(tvb, offset+1) );
sub_tree = proto_item_add_subtree(ti, ett_vuze_dht_contact);
proto_tree_add_item(sub_tree, hf_vuze_dht_contact_type, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN);
offset += TL_BYTE;
proto_tree_add_item(sub_tree, hf_vuze_dht_proto_ver, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN);
offset += TL_BYTE;
offset = dissect_vuze_dht_address( tvb, pinfo, sub_tree, offset, "Contact Address" );
return offset;
}
static int
dissect_vuze_dht_contacts(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int contacts_count)
{
proto_item *ti;
proto_tree *sub_tree;
int i;
ti = proto_tree_add_none_format( tree, hf_vuze_dht_contacts, tvb, offset, 0, "%d contacts", contacts_count );
sub_tree = proto_item_add_subtree(ti, ett_vuze_dht_contacts);
for( i=0; i<contacts_count; i++ )
offset = dissect_vuze_dht_contact( tvb, pinfo, sub_tree, offset );
return offset;
}
static int
dissect_vuze_dht_key(tvbuff_t *tvb, packet_info _U_*pinfo, proto_tree *tree, int offset)
{
proto_item *ti;
proto_tree *sub_tree;
guint key_len;
key_len = tvb_get_guint8( tvb, offset );
ti = proto_tree_add_item( tree, hf_vuze_dht_key, tvb, offset, key_len+1, ENC_NA );
sub_tree = proto_item_add_subtree(ti, ett_vuze_dht_key);
proto_tree_add_item( sub_tree, hf_vuze_dht_key_len, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN );
offset += TL_BYTE;
proto_tree_add_item( sub_tree, hf_vuze_dht_key_data, tvb, offset, key_len, ENC_NA );
proto_item_append_text( ti, ": %d bytes ( %s )", key_len, tvb_bytes_to_str(tvb, offset, key_len ) );
offset += key_len;
return offset;
}
static int
dissect_vuze_dht_keys(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int keys_count)
{
proto_item *ti;
proto_tree *sub_tree;
int i;
ti = proto_tree_add_none_format( tree, hf_vuze_dht_keys, tvb, offset, 0, "%d keys", keys_count );
sub_tree = proto_item_add_subtree(ti, ett_vuze_dht_keys);
for( i=0; i<keys_count; i++ )
offset = dissect_vuze_dht_key( tvb, pinfo, sub_tree, offset );
return offset;
}
static int
dissect_vuze_dht_value(tvbuff_t *tvb, packet_info _U_*pinfo, proto_tree *tree, int offset, int ver )
{
proto_item *ti;
proto_tree *sub_tree;
int value_ver = -1;
ti = proto_tree_add_item( tree, hf_vuze_dht_value, tvb, offset, 0, ENC_NA );
sub_tree = proto_item_add_subtree(ti, ett_vuze_dht_value);
if( ver >= PV_REMOVE_DIST_ADD_VER )
{
proto_tree_add_item(sub_tree, hf_vuze_dht_value_ver, tvb, offset, TL_INT, ENC_BIG_ENDIAN);
value_ver = tvb_get_ntohl( tvb, offset );
offset += TL_INT;
}
if( value_ver==0 )
{
proto_item_append_text( ti,
" (reply to STATS): %d values for the key, out of %d in total...",
tvb_get_ntohl(tvb, offset), tvb_get_ntohl(tvb, offset+TL_INT) );
proto_tree_add_item(tree, hf_vuze_dht_values_num, tvb, offset, TL_INT, ENC_BIG_ENDIAN);
offset += TL_INT;
proto_tree_add_item(tree, hf_vuze_dht_values_total, tvb, offset, TL_INT, ENC_BIG_ENDIAN);
offset += TL_INT;
proto_tree_add_item(tree, hf_vuze_dht_reads_per_min, tvb, offset, TL_INT, ENC_BIG_ENDIAN);
offset += TL_INT;
proto_tree_add_item(tree, hf_vuze_dht_diversification_type, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN);
offset += TL_BYTE;
}
else
{
int value_bytes_count;
proto_tree_add_item(sub_tree, hf_vuze_dht_value_created, tvb, offset, TL_LONG, ENC_BIG_ENDIAN);
offset += TL_LONG;
proto_tree_add_item(sub_tree, hf_vuze_dht_value_bytes_count, tvb, offset, TL_SHORT, ENC_BIG_ENDIAN);
value_bytes_count = tvb_get_ntohs(tvb, offset);
offset += TL_SHORT;
proto_tree_add_item(sub_tree, hf_vuze_dht_value_bytes, tvb, offset, value_bytes_count, ENC_NA);
proto_item_append_text( ti, ": %d bytes ( %s )", value_bytes_count, tvb_bytes_to_str(tvb, offset, value_bytes_count ) );
offset += value_bytes_count;
offset = dissect_vuze_dht_contact( tvb, pinfo, sub_tree, offset );
proto_tree_add_item(sub_tree, hf_vuze_dht_value_flags, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN);
offset += TL_BYTE;
proto_tree_add_item(sub_tree, hf_vuze_dht_value_life_hours, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN);
offset += TL_BYTE;
proto_tree_add_item(sub_tree, hf_vuze_dht_value_replication_factor, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN);
offset += TL_BYTE;
}
return offset;
}
static int
dissect_vuze_dht_value_group(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int ver)
{
proto_item *ti;
proto_tree *sub_tree;
int values_count;
int i;
values_count = tvb_get_ntohs( tvb, offset );
ti = proto_tree_add_none_format( tree, hf_vuze_dht_value_group, tvb, offset, 0, "%d values", values_count );
sub_tree = proto_item_add_subtree(ti, ett_vuze_dht_value_group);
proto_tree_add_item( sub_tree, hf_vuze_dht_values_count, tvb, offset, TL_SHORT, ENC_BIG_ENDIAN );
offset += TL_SHORT;
for( i=0; i<values_count; i++ )
offset = dissect_vuze_dht_value( tvb, pinfo, sub_tree, offset, ver );
return offset;
}
static int
dissect_vuze_dht_value_groups(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int value_groups_count, int ver)
{
proto_item *ti;
proto_tree *sub_tree;
int i;
ti = proto_tree_add_none_format( tree, hf_vuze_dht_value_groups, tvb, offset, 0, "%d value groups", value_groups_count );
sub_tree = proto_item_add_subtree(ti, ett_vuze_dht_value_groups);
for( i=0; i<value_groups_count; i++ )
offset = dissect_vuze_dht_value_group( tvb, pinfo, sub_tree, offset, ver );
return offset;
}
static int
dissect_vuze_dht_network_coordinate(tvbuff_t *tvb, packet_info _U_*pinfo, proto_tree *tree, int offset)
{
proto_item *ti;
proto_tree *sub_tree;
guint coordinate_size;
coordinate_size = tvb_get_guint8( tvb, offset+1 );
ti = proto_tree_add_item( tree, hf_vuze_dht_network_coordinate, tvb, offset, coordinate_size+2, ENC_NA );
sub_tree = proto_item_add_subtree(ti, ett_vuze_dht_network_coordinate);
proto_item_append_text( ti, ": type %d, length %d ( %s )",
tvb_get_guint8(tvb,offset), tvb_get_guint8(tvb,offset+TL_BYTE), tvb_bytes_to_str(tvb, offset+TL_BYTE+TL_BYTE, coordinate_size ) );
proto_tree_add_item( sub_tree, hf_vuze_dht_network_coordinate_type, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN );
offset += TL_BYTE;
proto_tree_add_item( sub_tree, hf_vuze_dht_network_coordinate_size, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN );
offset += TL_BYTE;
proto_tree_add_item( sub_tree, hf_vuze_dht_network_coordinate_data, tvb, offset, coordinate_size, ENC_NA );
offset += coordinate_size;
return offset;
}
static int
dissect_vuze_dht_network_coordinates(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int ver)
{
proto_item *ti;
proto_tree *sub_tree;
guint i;
guint network_coordinates_count;
if( ver >= PV_GENERIC_NETPOS )
{
proto_tree_add_item(tree, hf_vuze_dht_network_coordinates_count, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN);
network_coordinates_count = tvb_get_guint8( tvb, offset );
offset += TL_BYTE;
ti = proto_tree_add_none_format( tree, hf_vuze_dht_network_coordinates, tvb, offset, 0, "%d network coordinates", network_coordinates_count );
sub_tree = proto_item_add_subtree(ti, ett_vuze_dht_network_coordinates);
for( i=0; i<network_coordinates_count; i++ )
offset = dissect_vuze_dht_network_coordinate( tvb, pinfo, sub_tree, offset );
}
return offset;
}
static int
dissect_vuze_dht_request_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int *action, int *ver )
{
proto_tree_add_item(tree, hf_vuze_dht_connection_id, tvb, offset, TL_LONG, ENC_BIG_ENDIAN);
offset += TL_LONG;
proto_tree_add_item(tree, hf_vuze_dht_action, tvb, offset, TL_INT, ENC_BIG_ENDIAN);
*action = tvb_get_ntohl(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " Action: %s", val_to_str_const( *action, vuze_dht_action_type_vals, "Unknown") );
offset += TL_INT;
proto_tree_add_item(tree, hf_vuze_dht_transaction_id, tvb, offset, TL_INT, ENC_BIG_ENDIAN);
offset += TL_INT;
proto_tree_add_item(tree, hf_vuze_dht_proto_ver, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN);
*ver = tvb_get_guint8( tvb, offset );
offset += TL_BYTE;
if( *ver >= PV_VENDOR_ID )
{
proto_tree_add_item(tree, hf_vuze_dht_vendor_id, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN);
offset += TL_BYTE;
}
if( *ver > PV_NETWORKS )
{
proto_tree_add_item(tree, hf_vuze_dht_network_id, tvb, offset, TL_INT, ENC_BIG_ENDIAN);
offset += TL_INT;
}
if( *ver > PV_FIX_ORIGINATOR )
{
proto_tree_add_item(tree, hf_vuze_dht_local_proto_ver, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN);
offset += TL_BYTE;
}
offset = dissect_vuze_dht_address(tvb, pinfo, tree, offset, "Local Address");
proto_tree_add_item(tree, hf_vuze_dht_instance_id, tvb, offset, TL_INT, ENC_BIG_ENDIAN);
offset += TL_INT;
proto_tree_add_item(tree, hf_vuze_dht_time, tvb, offset, TL_LONG, ENC_BIG_ENDIAN);
offset += TL_LONG;
return offset;
}
static int
dissect_vuze_dht_reply_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int *action, int *ver )
{
proto_tree_add_item(tree, hf_vuze_dht_action, tvb, offset, TL_INT, ENC_BIG_ENDIAN);
*action = tvb_get_ntohl(tvb, offset);
col_append_fstr(pinfo->cinfo, COL_INFO, " Action: %s", val_to_str_const( *action, vuze_dht_action_type_vals, "Unknown") );
offset += TL_INT;
proto_tree_add_item(tree, hf_vuze_dht_transaction_id, tvb, offset, TL_INT, ENC_BIG_ENDIAN);
offset += TL_INT;
proto_tree_add_item(tree, hf_vuze_dht_connection_id, tvb, offset, TL_LONG, ENC_BIG_ENDIAN);
offset += TL_LONG;
proto_tree_add_item(tree, hf_vuze_dht_proto_ver, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN);
*ver = tvb_get_guint8( tvb, offset );
offset += TL_BYTE;
if( *ver >= PV_VENDOR_ID )
{
proto_tree_add_item(tree, hf_vuze_dht_vendor_id, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN);
offset += TL_BYTE;
}
if( *ver > PV_NETWORKS )
{
proto_tree_add_item(tree, hf_vuze_dht_network_id, tvb, offset, TL_INT, ENC_BIG_ENDIAN);
offset += TL_INT;
}
proto_tree_add_item(tree, hf_vuze_dht_instance_id, tvb, offset, TL_INT, ENC_BIG_ENDIAN);
offset += TL_INT;
return offset;
}
static int
dissect_vuze_dht_reply_ping(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int ver )
{
if( ver >= PV_VIVALDI )
{
offset = dissect_vuze_dht_network_coordinates( tvb, pinfo, tree, offset, ver );
}
return offset;
}
static int
dissect_vuze_dht_request_store(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int ver )
{
guint8 keys_count, value_groups_count;
if( ver >= PV_ANTI_SPOOF )
{
proto_tree_add_item(tree, hf_vuze_dht_spoof_id, tvb, offset, TL_INT, ENC_BIG_ENDIAN);
offset += TL_INT;
}
proto_tree_add_item(tree, hf_vuze_dht_keys_count, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN);
keys_count = tvb_get_guint8( tvb, offset );
offset += TL_BYTE;
offset = dissect_vuze_dht_keys( tvb, pinfo, tree, offset, keys_count );
proto_tree_add_item(tree, hf_vuze_dht_value_groups_count, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN);
value_groups_count = tvb_get_guint8( tvb, offset );
offset += TL_BYTE;
offset = dissect_vuze_dht_value_groups( tvb, pinfo, tree, offset, value_groups_count, ver );
return offset;
}
static int
dissect_vuze_dht_reply_store(tvbuff_t *tvb, packet_info _U_*pinfo, proto_tree *tree, int offset, int ver )
{
if( ver >= PV_DIV_AND_CONT )
{
guint diversifications_len;
proto_tree_add_item(tree, hf_vuze_dht_diversifications_len, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN);
diversifications_len = tvb_get_guint8( tvb, offset );
offset += TL_BYTE;
proto_tree_add_item(tree, hf_vuze_dht_diversifications, tvb, offset, diversifications_len, ENC_NA);
offset += diversifications_len;
}
return offset;
}
static int
dissect_vuze_dht_request_find_node(tvbuff_t *tvb, packet_info _U_*pinfo, proto_tree *tree, int offset, int ver )
{
guint id_len;
proto_tree_add_item(tree, hf_vuze_dht_id_len, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN);
id_len = tvb_get_guint8( tvb, offset );
offset += TL_BYTE;
proto_tree_add_item(tree, hf_vuze_dht_id, tvb, offset, id_len, ENC_NA);
offset += id_len;
if( ver >= PV_MORE_NODE_STATUS )
{
proto_tree_add_item(tree, hf_vuze_dht_node_status, tvb, offset, TL_INT, ENC_BIG_ENDIAN);
offset += TL_INT;
proto_tree_add_item(tree, hf_vuze_dht_size, tvb, offset, TL_INT, ENC_BIG_ENDIAN);
offset += TL_INT;
}
return offset;
}
static int
dissect_vuze_dht_reply_find_node(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int ver )
{
guint contacts_count;
if( ver >= PV_ANTI_SPOOF )
{
proto_tree_add_item(tree, hf_vuze_dht_spoof_id, tvb, offset, TL_INT, ENC_BIG_ENDIAN);
offset += TL_INT;
}
if( ver >= PV_XFER_STATUS )
{
proto_tree_add_item(tree, hf_vuze_dht_node_type, tvb, offset, TL_INT, ENC_BIG_ENDIAN);
offset += TL_INT;
}
if( ver >= PV_SIZE_ESTIMATE )
{
proto_tree_add_item(tree, hf_vuze_dht_size, tvb, offset, TL_INT, ENC_BIG_ENDIAN);
offset += TL_INT;
}
if( ver >= PV_VIVALDI )
{
offset = dissect_vuze_dht_network_coordinates( tvb, pinfo, tree, offset, ver );
}
proto_tree_add_item(tree, hf_vuze_dht_contacts_count, tvb, offset, TL_SHORT, ENC_BIG_ENDIAN);
contacts_count = tvb_get_ntohs( tvb, offset );
offset += TL_SHORT;
offset = dissect_vuze_dht_contacts( tvb, pinfo, tree, offset, contacts_count );
return offset;
}
static int
dissect_vuze_dht_request_find_value(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int ver _U_ )
{
offset = dissect_vuze_dht_key( tvb, pinfo, tree, offset );
proto_tree_add_item(tree, hf_vuze_dht_flags, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN);
offset += TL_BYTE;
proto_tree_add_item(tree, hf_vuze_dht_max_values, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN);
offset += TL_BYTE;
return offset;
}
static int
dissect_vuze_dht_reply_find_value(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int ver )
{
guint8 has_values;
guint contacts_count;
if( ver >= PV_DIV_AND_CONT )
{
proto_tree_add_item(tree, hf_vuze_dht_has_continuation, tvb, offset, TL_BOOL, ENC_BIG_ENDIAN);
offset += TL_BOOL;
}
proto_tree_add_item(tree, hf_vuze_dht_has_values, tvb, offset, TL_BOOL, ENC_BIG_ENDIAN);
has_values = tvb_get_guint8( tvb, offset );
offset += TL_BOOL;
if( has_values )
{
proto_tree_add_item(tree, hf_vuze_dht_contacts_count, tvb, offset, TL_SHORT, ENC_BIG_ENDIAN);
contacts_count = tvb_get_ntohs( tvb, offset );
offset += TL_SHORT;
offset = dissect_vuze_dht_contacts( tvb, pinfo, tree, offset, contacts_count );
if( ver >= PV_VIVALDI_FINDVALUE )
{
offset = dissect_vuze_dht_network_coordinates( tvb, pinfo, tree, offset, ver );
}
if( ver >= PV_DIV_AND_CONT )
{
proto_tree_add_item(tree, hf_vuze_dht_diversification_type, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN);
offset += TL_BYTE;
}
offset = dissect_vuze_dht_value_group( tvb, pinfo, tree, offset, ver );
}
return offset;
}
static int
dissect_vuze_dht_reply_error(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int ver _U_ )
{
guint error_type;
guint8 key_block_request_len;
guint signature_len;
proto_tree_add_item(tree, hf_vuze_dht_error_type, tvb, offset, TL_INT, ENC_BIG_ENDIAN);
error_type = tvb_get_ntohl( tvb, offset );
col_append_fstr(pinfo->cinfo, COL_INFO, " Error: %s", val_to_str_const( error_type, vuze_dht_error_type_vals, "Unknown") );
offset += TL_INT;
switch(error_type)
{
case ET_WRONG_ADDRESS:
offset = dissect_vuze_dht_address( tvb, pinfo, tree, offset, "Sender Address" );
break;
case ET_KEY_BLOCKED:
proto_tree_add_item(tree, hf_vuze_dht_key_block_request_len, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN);
key_block_request_len = tvb_get_guint8( tvb, offset );
offset += TL_BYTE;
proto_tree_add_item(tree, hf_vuze_dht_key_block_request, tvb, offset, key_block_request_len, ENC_NA);
offset += key_block_request_len;
proto_tree_add_item(tree, hf_vuze_dht_signature_len, tvb, offset, TL_SHORT, ENC_BIG_ENDIAN);
signature_len = tvb_get_ntohs( tvb, offset );
offset += TL_SHORT;
proto_tree_add_item(tree, hf_vuze_dht_signature, tvb, offset, signature_len, ENC_NA);
offset += signature_len;
break;
default:
break;
}
return offset;
}
static int
dissect_vuze_dht_request_key_block(tvbuff_t *tvb, packet_info _U_*pinfo, proto_tree *tree, int offset, int ver _U_ )
{
guint8 key_block_request_len;
guint signature_len;
proto_tree_add_item(tree, hf_vuze_dht_spoof_id, tvb, offset, TL_INT, ENC_BIG_ENDIAN);
offset += TL_INT;
proto_tree_add_item(tree, hf_vuze_dht_key_block_request_len, tvb, offset, TL_BYTE, ENC_BIG_ENDIAN);
key_block_request_len = tvb_get_guint8( tvb, offset );
offset += TL_BYTE;
proto_tree_add_item(tree, hf_vuze_dht_key_block_request, tvb, offset, key_block_request_len, ENC_NA);
offset += key_block_request_len;
proto_tree_add_item(tree, hf_vuze_dht_signature_len, tvb, offset, TL_SHORT, ENC_BIG_ENDIAN);
signature_len = tvb_get_ntohs( tvb, offset );
offset += TL_SHORT;
proto_tree_add_item(tree, hf_vuze_dht_signature, tvb, offset, signature_len, ENC_NA);
offset += signature_len;
return offset;
}
static int
dissect_vuze_dht(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
proto_item *ti;
proto_tree *sub_tree;
int action, proto_ver;
int decoded_length = 0;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "Vuze-DHT");
col_clear( pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_vuze_dht, tvb, 0, -1, ENC_NA);
sub_tree = proto_item_add_subtree(ti, ett_vuze_dht);
if( tvb_get_guint8(tvb,0) & 0x80 )
{
decoded_length = dissect_vuze_dht_request_header(tvb, pinfo, sub_tree, decoded_length, &action, &proto_ver );
}
else
{
decoded_length = dissect_vuze_dht_reply_header(tvb, pinfo, sub_tree, decoded_length, &action, &proto_ver );
}
switch( action )
{
case AT_PING_REQUEST:
break;
case AT_PING_REPLY:
decoded_length = dissect_vuze_dht_reply_ping(tvb, pinfo, sub_tree, decoded_length, proto_ver );
break;
case AT_STORE_REQUEST:
decoded_length = dissect_vuze_dht_request_store(tvb, pinfo, sub_tree, decoded_length, proto_ver );
break;
case AT_STORE_REPLY:
decoded_length = dissect_vuze_dht_reply_store(tvb, pinfo, sub_tree, decoded_length, proto_ver );
break;
case AT_FIND_NODE_REQUEST:
decoded_length = dissect_vuze_dht_request_find_node(tvb, pinfo, sub_tree, decoded_length, proto_ver );
break;
case AT_FIND_NODE_REPLY:
decoded_length = dissect_vuze_dht_reply_find_node(tvb, pinfo, sub_tree, decoded_length, proto_ver );
break;
case AT_FIND_VALUE_REQUEST:
decoded_length = dissect_vuze_dht_request_find_value(tvb, pinfo, sub_tree, decoded_length, proto_ver );
break;
case AT_FIND_VALUE_REPLY:
decoded_length = dissect_vuze_dht_reply_find_value(tvb, pinfo, sub_tree, decoded_length, proto_ver );
break;
case AT_ERROR_REPLY:
decoded_length = dissect_vuze_dht_reply_error(tvb, pinfo, sub_tree, decoded_length, proto_ver );
break;
case AT_KEY_BLOCK_REQUEST:
decoded_length = dissect_vuze_dht_request_key_block(tvb, pinfo, sub_tree, decoded_length, proto_ver );
break;
default:
break;
}
return decoded_length;
}
void
proto_register_vuze_dht(void)
{
static hf_register_info hf[] = {
{ &hf_vuze_dht_address,
{ "Address", "vuze-dht.address",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_address_len,
{ "Address Length", "vuze-dht.address.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_address_v4,
{ "IPv4 Address", "vuze-dht.address.ipv4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_address_v6,
{ "IPv6 Address", "vuze-dht.address.ipv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_address_port,
{ "Port", "vuze-dht.address.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_contact,
{ "Contact", "vuze-dht.contact",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_contact_type,
{ "Contact Type", "vuze-dht.contact.type",
FT_UINT8, BASE_DEC, VALS(vuze_dht_contact_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_proto_ver,
{ "Protocol Version", "vuze-dht.proto_ver",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_value,
{ "Value", "vuze-dht.value",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_value_ver,
{ "Value Version", "vuze-dht.value.ver",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_value_created,
{ "Value Creation Time", "vuze-dht.value.creation_time",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_value_bytes_count,
{ "Value Bytes Count", "vuze-dht.value.bytes_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_value_bytes,
{ "Value Bytes", "vuze-dht.value.bytes",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_value_flags,
{ "Value Flags", "vuze-dht.value.flags",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_value_life_hours,
{ "Value Life Hours", "vuze-dht.value.life_hours",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_value_replication_factor,
{ "Value Replication Factor", "vuze-dht.value.replication_factor",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_connection_id,
{ "Connection ID", "vuze-dht.connection_id",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_action,
{ "Action", "vuze-dht.action",
FT_UINT32, BASE_DEC, VALS(vuze_dht_action_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_transaction_id,
{ "Transaction ID", "vuze-dht.transaction_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_vendor_id,
{ "Vendor ID", "vuze-dht.vendor_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_network_id,
{ "Network ID", "vuze-dht.network_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_local_proto_ver,
{ "Local Protocol Version", "vuze-dht.local_proto_ver",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_instance_id,
{ "Instance ID", "vuze-dht.instance_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_time,
{ "Time", "vuze-dht.time",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_network_coordinates_count,
{ "Network Coordinates Count", "vuze-dht.network_coordinates_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_network_coordinates,
{ "Network Coordinates", "vuze-dht.network_coordinates",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_network_coordinate,
{ "Network Coordinate", "vuze-dht.network_coordinate",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_network_coordinate_type,
{ "Network Coordinate Type", "vuze-dht.network_coordinate.type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_network_coordinate_size,
{ "Network Coordinate Size", "vuze-dht.network_coordinate.size",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_network_coordinate_data,
{ "Network Coordinate Data", "vuze-dht.network_coordinate.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_spoof_id,
{ "Spoof ID", "vuze-dht.spoof_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_keys_count,
{ "Keys Count", "vuze-dht.keys_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_keys,
{ "Keys", "vuze-dht.keys",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_key,
{ "Key", "vuze-dht.key",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_key_len,
{ "Key Length", "vuze-dht.key.len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_key_data,
{ "Key Data", "vuze-dht.key.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_values_count,
{ "Values Count", "vuze-dht.values_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_value_groups_count,
{ "Value Groups Count", "vuze-dht.value_groups_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_value_group,
{ "Values", "vuze-dht.values",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_value_groups,
{ "Value Groups", "vuze-dht.value_groups",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_diversifications_len,
{ "Diversifications Length", "vuze-dht.diversifications_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_diversifications,
{ "Diversifications", "vuze-dht.diversifications",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_id_len,
{ "ID Length", "vuze-dht.id_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_id,
{ "ID", "vuze-dht.id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_node_status,
{ "Node Status", "vuze-dht.node_status",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_size,
{ "DHT Size", "vuze-dht.dht_size",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_node_type,
{ "Node Type", "vuze-dht.node_type",
FT_UINT32, BASE_DEC, VALS(vuze_dht_node_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_contacts_count,
{ "Contacts Count", "vuze-dht.contacts_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_contacts,
{ "Contacts", "vuze-dht.contacts",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_flags,
{ "Flags", "vuze-dht.flags",
FT_UINT8, BASE_DEC, VALS(vuze_dht_flag_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_values_num,
{ "Values Num", "vuze-dht.stats.values_num",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_values_total,
{ "Values Total", "vuze-dht.stats.values_total",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_reads_per_min,
{ "Reads Per Minute", "vuze-dht.stats.reads_per_min",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_diversification_type,
{ "Diversification Type", "vuze-dht.stats.diversification_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_max_values,
{ "Max values", "vuze-dht.max_values",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_has_continuation,
{ "Has Continuation", "vuze-dht.has_continuation",
FT_UINT8, BASE_DEC, VALS(vuze_dht_bool_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_has_values,
{ "Has Values", "vuze-dht.has_values",
FT_UINT8, BASE_DEC, VALS(vuze_dht_bool_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_error_type,
{ "Error Type", "vuze-dht.error_type",
FT_UINT32, BASE_DEC, VALS(vuze_dht_error_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_key_block_request_len,
{ "Key Block Request Length", "vuze-dht.key_block_request_len",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_key_block_request,
{ "Key Block Request", "vuze-dht.key_block_request",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_signature_len,
{ "Signature Length", "vuze-dht.signature_len",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_vuze_dht_signature,
{ "Signature", "vuze-dht.signature",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_vuze_dht,
&ett_vuze_dht_address,
&ett_vuze_dht_contacts,
&ett_vuze_dht_contact,
&ett_vuze_dht_keys,
&ett_vuze_dht_key,
&ett_vuze_dht_value_groups,
&ett_vuze_dht_value_group,
&ett_vuze_dht_value,
&ett_vuze_dht_network_coordinates,
&ett_vuze_dht_network_coordinate
};
module_t *vuze_dht_module;
proto_vuze_dht = proto_register_protocol (
"Vuze DHT Protocol",
"Vuze-DHT",
"vuze-dht"
);
proto_register_field_array(proto_vuze_dht, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
vuze_dht_handle = new_register_dissector("vuze-dht", dissect_vuze_dht, proto_vuze_dht);
vuze_dht_module = prefs_register_protocol(proto_vuze_dht, proto_reg_handoff_vuze_dht);
prefs_register_uint_preference(vuze_dht_module, "udp_port",
"Vuze DHT Protocol UDP port",
"Set the UDP port for Vuze DHT Protocol.",
10, &global_vuze_dht_udp_port);
}
void
proto_reg_handoff_vuze_dht(void)
{
static gboolean vuze_dht_prefs_initialized = FALSE;
static guint vuze_dht_udp_port;
if (!vuze_dht_prefs_initialized)
{
vuze_dht_prefs_initialized = TRUE;
}
else
{
dissector_delete_uint("udp.port", vuze_dht_udp_port, vuze_dht_handle);
}
vuze_dht_udp_port = global_vuze_dht_udp_port;
dissector_add_uint("udp.port", global_vuze_dht_udp_port, vuze_dht_handle);
}
