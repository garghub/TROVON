static gboolean ts2_standard_find_fragments(tvbuff_t *tvb, guint32 *last_inorder_frame, guint32 *frag_size, guint32 *frag_num, gboolean *outoforder)
{
guint32 frag_count;
gboolean ret;
frag_count=tvb_get_letohs(tvb, 18);
ret=FALSE;
*outoforder=FALSE;
if(*last_inorder_frame==0)
{
*last_inorder_frame=tvb_get_letohl(tvb, 12);
*frag_size=tvb_get_letohs(tvb, 18);
*frag_num=0;
if(*frag_size>0)
ret=TRUE;
else
ret=FALSE;
}
else if(*last_inorder_frame==tvb_get_letohl(tvb, 12)-1)
{
if(*frag_size>0)
{
*frag_num=*frag_size-frag_count;
if(frag_count==0)
{
*frag_size=0;
}
ret=TRUE;
}
else
{
*frag_size=tvb_get_letohs(tvb, 18);
*frag_num=*frag_size-frag_count;
if(*frag_size>0)
ret=TRUE;
else
ret=FALSE;
}
*last_inorder_frame=tvb_get_letohl(tvb, 12);
}
else
*outoforder=TRUE;
return ret;
}
static void ts2_standard_dissect(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ts2_tree, ts2_conversation *conversation_data)
{
guint8 save_fragmented;
tvbuff_t *new_tvb, *next_tvb;
fragment_head *frag_msg ;
guint16 fragment_number;
ts2_frag *frag;
gboolean outoforder;
guint16 type = tvb_get_letohs(tvb, 2);
proto_tree_add_item(ts2_tree, hf_ts2_seqnum, tvb, 12, 4, ENC_LITTLE_ENDIAN);
if ( ! ( frag = (ts2_frag *)p_get_proto_data(wmem_file_scope(), pinfo, proto_ts2, 0) ) ) {
frag = wmem_new(wmem_file_scope(), ts2_frag);
frag->frag_num=0;
}
if(!(pinfo->fd->flags.visited))
{
if(conversation_data->server_port == pinfo->srcport)
{
frag->fragmented = ts2_standard_find_fragments(tvb, &conversation_data->last_inorder_server_frame, &conversation_data->server_frag_size, &conversation_data->server_frag_num, &outoforder);
frag->frag_num=conversation_data->server_frag_num;
frag->frag_size=conversation_data->server_frag_size;
}
else
{
frag->fragmented = ts2_standard_find_fragments(tvb, &conversation_data->last_inorder_client_frame, &conversation_data->client_frag_size, &conversation_data->client_frag_num, &outoforder);
frag->frag_num=conversation_data->client_frag_num;
frag->frag_size=conversation_data->client_frag_size;
}
frag->outoforder=outoforder;
p_add_proto_data(wmem_file_scope(), pinfo, proto_ts2, 0, frag);
}
frag = (ts2_frag *)p_get_proto_data(wmem_file_scope(), pinfo, proto_ts2, 0);
proto_tree_add_item(ts2_tree, hf_ts2_resend_count, tvb, 16, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ts2_tree, hf_ts2_fragmentnumber, tvb, 18, 2, ENC_LITTLE_ENDIAN);
ts2_add_checked_crc32(ts2_tree, hf_ts2_crc32, tvb, 20, tvb_get_letohl(tvb, 20));
new_tvb = NULL;
if(frag && frag->fragmented)
{
save_fragmented = pinfo->fragmented;
frag_msg = NULL;
pinfo->fragmented = TRUE;
fragment_number = tvb_get_letohs(tvb, 18);
frag_msg = fragment_add_seq_check(&msg_reassembly_table, tvb, 24, pinfo, type, NULL, frag->frag_num, tvb_length_remaining(tvb, 24), fragment_number);
new_tvb = process_reassembled_data(tvb, 24, pinfo,"Reassembled TeamSpeak2", frag_msg, &msg_frag_items, NULL, ts2_tree);
if (frag_msg)
{
col_append_str(pinfo->cinfo, COL_INFO, " (Message Reassembled)");
}
else
{
col_append_fstr(pinfo->cinfo, COL_INFO," (Message fragment %u)", frag->frag_num);
}
if (new_tvb)
next_tvb = new_tvb;
else
next_tvb = tvb_new_subset_remaining(tvb, 24);
pinfo->fragmented = save_fragmented;
}
else
next_tvb = tvb_new_subset_remaining(tvb, 24);
if((new_tvb || (frag && !frag->fragmented)) && !frag->outoforder)
{
switch(type)
{
case TS2T_LOGINPART2:
ts2_parse_loginpart2(next_tvb, ts2_tree);
break;
case TS2T_CHANNELLIST:
ts2_parse_channellist(next_tvb, ts2_tree);
break;
case TS2T_PLAYERLIST:
ts2_parse_playerlist(next_tvb, ts2_tree);
break;
case TS2T_NEWPLAYERJOINED:
ts2_parse_newplayerjoined(next_tvb, ts2_tree);
break;
case TS2T_KNOWNPLAYERUPDATE:
ts2_parse_knownplayerupdate(next_tvb, ts2_tree);
break;
case TS2T_PLAYERLEFT:
ts2_parse_playerleft(next_tvb, ts2_tree);
break;
case TS2T_PLAYERKICKED:
ts2_parse_playerleft(next_tvb, ts2_tree);
break;
case TS2T_LOGINEND:
ts2_parse_loginend(next_tvb, ts2_tree);
break;
case TS2T_CHANGESTATUS:
ts2_parse_changestatus(next_tvb, ts2_tree);
break;
case TS2T_SWITCHCHANNEL:
ts2_parse_switchchannel(next_tvb, ts2_tree);
break;
case TS2T_CHANNELCHANGE:
ts2_parse_channelchange(next_tvb, ts2_tree);
break;
}
}
if(frag && frag->outoforder)
col_append_str(pinfo->cinfo, COL_INFO, " (Out Of Order, ignored)");
}
static void ts2_parse_newplayerjoined(tvbuff_t *tvb, proto_tree *ts2_tree)
{
gint32 offset;
offset=0;
proto_tree_add_item(ts2_tree, hf_ts2_player_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(ts2_tree, hf_ts2_channel_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(ts2_tree, hf_ts2_unknown, tvb, offset, 6, ENC_NA);
offset+=6;
proto_tree_add_item(ts2_tree, hf_ts2_nick, tvb, offset, 1, ENC_ASCII|ENC_BIG_ENDIAN);
}
static void ts2_parse_loginend(tvbuff_t *tvb, proto_tree *ts2_tree)
{
gint32 offset;
offset=0;
proto_tree_add_item(ts2_tree, hf_ts2_unknown, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
}
static void ts2_parse_knownplayerupdate(tvbuff_t *tvb, proto_tree *ts2_tree)
{
gint32 offset;
offset=0;
proto_tree_add_item(ts2_tree, hf_ts2_player_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(ts2_tree, hf_ts2_player_status_flags, tvb, offset, 2, ENC_LITTLE_ENDIAN);
ts2_add_statusflags(tvb, ts2_tree, offset);
}
static void ts2_parse_switchchannel(tvbuff_t *tvb, proto_tree *ts2_tree)
{
gint32 offset;
offset=0;
proto_tree_add_item(ts2_tree, hf_ts2_channel_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(ts2_tree, hf_ts2_password, tvb, offset, 1, ENC_ASCII|ENC_BIG_ENDIAN);
}
static void ts2_parse_channelchange(tvbuff_t *tvb, proto_tree *ts2_tree)
{
gint32 offset;
offset=0;
proto_tree_add_item(ts2_tree, hf_ts2_player_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(ts2_tree, hf_ts2_channel_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(ts2_tree, hf_ts2_channel_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(ts2_tree, hf_ts2_unknown, tvb, offset, 2, ENC_NA);
}
static void ts2_parse_changestatus(tvbuff_t *tvb, proto_tree *ts2_tree)
{
gint32 offset;
offset=0;
proto_tree_add_item(ts2_tree, hf_ts2_player_status_flags, tvb, offset, 2, ENC_LITTLE_ENDIAN);
ts2_add_statusflags(tvb, ts2_tree, offset);
}
static void ts2_parse_playerleft(tvbuff_t *tvb, proto_tree *ts2_tree)
{
gint32 offset;
offset=0;
proto_tree_add_item(ts2_tree, hf_ts2_player_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(ts2_tree, hf_ts2_unknown, tvb, offset, 4, ENC_NA);
offset+=4;
proto_tree_add_item(ts2_tree, hf_ts2_unknown, tvb, offset, 4, ENC_NA);
offset+=4;
proto_tree_add_item(ts2_tree, hf_ts2_unknown, tvb, offset, tvb_length_remaining(tvb, offset), ENC_NA);
}
static void ts2_parse_loginpart2(tvbuff_t *tvb, proto_tree *ts2_tree)
{
gint32 offset;
offset=0;
proto_tree_add_item(ts2_tree, hf_ts2_unknown, tvb, 0, 2, ENC_NA);
offset+=2;
proto_tree_add_item(ts2_tree, hf_ts2_channel, tvb, offset, 1, ENC_ASCII|ENC_BIG_ENDIAN);
offset+=30;
proto_tree_add_item(ts2_tree, hf_ts2_subchannel, tvb, offset, 1, ENC_ASCII|ENC_BIG_ENDIAN);
offset+=30;
proto_tree_add_item(ts2_tree, hf_ts2_channelpassword, tvb, offset, 1, ENC_ASCII|ENC_BIG_ENDIAN);
offset+=30;
proto_tree_add_item(ts2_tree, hf_ts2_unknown, tvb, offset, 4, ENC_NA);
}
static void ts2_parse_channellist(tvbuff_t *tvb, proto_tree *ts2_tree)
{
gint32 offset;
guint32 string_len;
proto_tree *subtree;
proto_item *item;
offset=0;
proto_tree_add_item(ts2_tree, hf_ts2_number_of_channels, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
while(offset<tvb_length_remaining(tvb, 0))
{
proto_tree_add_item(ts2_tree, hf_ts2_channel_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
item = proto_tree_add_item(ts2_tree, hf_ts2_channel_flags, tvb, offset, 1, ENC_LITTLE_ENDIAN);
subtree = proto_item_add_subtree(item, ett_ts2_channel_flags);
proto_tree_add_item(subtree, hf_ts2_channel_unregistered, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ts2_channel_moderated, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ts2_channel_password, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ts2_channel_subchannels, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_ts2_channel_default, tvb, offset, 1, ENC_BIG_ENDIAN);
offset+=1;
proto_tree_add_item(ts2_tree, hf_ts2_unknown, tvb, offset, 1, ENC_NA);
offset+=1;
proto_tree_add_item(ts2_tree, hf_ts2_codec, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(ts2_tree, hf_ts2_parent_channel_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(ts2_tree, hf_ts2_channel_order, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
proto_tree_add_item(ts2_tree, hf_ts2_max_users, tvb, offset, 2, ENC_LITTLE_ENDIAN);
offset+=2;
tvb_get_stringz_enc(wmem_packet_scope(), tvb, offset, &string_len, ENC_ASCII);
proto_tree_add_item(ts2_tree, hf_ts2_channel_name, tvb, offset,string_len , ENC_ASCII|ENC_NA);
offset+=string_len;
tvb_get_stringz_enc(wmem_packet_scope(), tvb, offset, &string_len, ENC_ASCII);
proto_tree_add_item(ts2_tree, hf_ts2_channel_topic, tvb, offset,string_len ,ENC_ASCII|ENC_NA);
offset+=string_len;
tvb_get_stringz_enc(wmem_packet_scope(), tvb, offset, &string_len, ENC_ASCII);
proto_tree_add_item(ts2_tree, hf_ts2_channel_description, tvb, offset,string_len , ENC_ASCII|ENC_NA);
offset+=string_len;
}
}
static void ts2_add_statusflags(tvbuff_t *tvb, proto_tree *ts2_tree, guint32 offset)
{
proto_tree_add_item(ts2_tree, hf_ts2_status_channelcommander, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ts2_tree, hf_ts2_status_blockwhispers, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ts2_tree, hf_ts2_status_away, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ts2_tree, hf_ts2_status_mutemicrophone, tvb, offset, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ts2_tree, hf_ts2_status_mute, tvb, offset, 2, ENC_LITTLE_ENDIAN);
}
static void ts2_parse_playerlist(tvbuff_t *tvb, proto_tree *ts2_tree)
{
gint32 offset;
gint32 number_of_players;
gint32 x;
offset=0;
x=0;
proto_tree_add_item(ts2_tree, hf_ts2_number_of_players, tvb, offset, 4, ENC_LITTLE_ENDIAN);
number_of_players = tvb_get_letohl(tvb, 0);
offset+=4;
while(offset<tvb_length_remaining(tvb, 0) && x<number_of_players)
{
proto_tree_add_item(ts2_tree, hf_ts2_player_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(ts2_tree, hf_ts2_channel_id, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset+=4;
proto_tree_add_item(ts2_tree, hf_ts2_unknown, tvb, offset, 4, ENC_NA);
offset+=4;
proto_tree_add_item(ts2_tree, hf_ts2_player_status_flags, tvb, offset, 2, ENC_LITTLE_ENDIAN);
ts2_add_statusflags(tvb, ts2_tree, offset);
offset+=2;
proto_tree_add_item(ts2_tree, hf_ts2_nick, tvb, offset, 1, ENC_ASCII|ENC_BIG_ENDIAN);
offset+=30;
x++;
}
proto_tree_add_item(ts2_tree, hf_ts2_emptyspace, tvb, offset, tvb_length_remaining(tvb, 0), ENC_NA);
}
static ts2_conversation* ts2_get_conversation(packet_info *pinfo)
{
conversation_t *conversation;
ts2_conversation *conversation_data;
conversation = find_or_create_conversation(pinfo);
conversation_data = (ts2_conversation*)conversation_get_proto_data(conversation, proto_ts2);
if (conversation_data == NULL)
{
conversation_data = wmem_new(wmem_file_scope(), ts2_conversation);
conversation_data->last_inorder_server_frame=0;
conversation_data->last_inorder_client_frame=0;
conversation_data->server_port=pinfo->srcport;
conversation_data->server_frag_size=0;
conversation_data->server_frag_num=0;
conversation_data->client_frag_size=0;
conversation_data->client_frag_num=0;
conversation_add_proto_data(conversation, proto_ts2, (void *)conversation_data);
}
return conversation_data;
}
static void dissect_ts2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
ts2_conversation *conversation_data;
guint16 type = tvb_get_letohs(tvb, 2);
guint16 klass = tvb_get_letohs(tvb, 0);
conversation_data = ts2_get_conversation(pinfo);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TS2");
if(klass==TS2C_ACK)
col_add_fstr(pinfo->cinfo, COL_INFO, "Class: %s", val_to_str(klass, classnames, "Unknown (0x%02x)"));
else
col_add_fstr(pinfo->cinfo, COL_INFO, "Type: %s, Class: %s", val_to_str(type, typenames, "Unknown (0x%02x)"), val_to_str(klass, classnames, "Unknown (0x%02x)"));
if (!tree) {
switch(klass) {
case TS2C_CONNECTION:
switch(type) {
case TS2T_LOGINREQUEST:
conversation_data->server_port=pinfo->destport;
conversation_data->server_addr=pinfo->dst;
break;
}
break;
case TS2C_STANDARD:
ts2_standard_dissect(tvb, pinfo, tree, conversation_data);
break;
}
}
if (tree) {
proto_item *ti = NULL;
proto_tree *ts2_tree = NULL;
ti = proto_tree_add_item(tree, proto_ts2, tvb, 0, -1, ENC_NA);
ts2_tree = proto_item_add_subtree(ti, ett_ts2);
proto_tree_add_item(ts2_tree, hf_ts2_class, tvb, 0, 2, ENC_LITTLE_ENDIAN);
if(klass==TS2C_ACK)
proto_tree_add_item(ts2_tree, hf_ts2_resend_count, tvb, 2, 2, ENC_LITTLE_ENDIAN);
else
proto_tree_add_item(ts2_tree, hf_ts2_type, tvb, 2, 2, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ts2_tree, hf_ts2_sessionkey, tvb, 4, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ts2_tree, hf_ts2_clientid, tvb, 8, 4, ENC_LITTLE_ENDIAN);
switch(klass)
{
case TS2C_CONNECTION:
proto_tree_add_item(ts2_tree, hf_ts2_seqnum, tvb, 12, 4, ENC_LITTLE_ENDIAN);
ts2_add_checked_crc32(ts2_tree, hf_ts2_crc32, tvb, 16, tvb_get_letohl(tvb, 16));
switch(type)
{
case TS2T_PING:
break;
case TS2T_PINGREPLY:
proto_tree_add_item(ts2_tree, hf_ts2_ackto, tvb, 20, 4, ENC_LITTLE_ENDIAN);
break;
case TS2T_LOGINREQUEST:
proto_tree_add_item(ts2_tree, hf_ts2_protocol_string, tvb, 20, 1, ENC_ASCII|ENC_BIG_ENDIAN);
proto_tree_add_item(ts2_tree, hf_ts2_platform_string, tvb, 50, 1, ENC_ASCII|ENC_BIG_ENDIAN);
proto_tree_add_item(ts2_tree, hf_ts2_unknown, tvb, 80, 9, ENC_NA);
proto_tree_add_item(ts2_tree, hf_ts2_registeredlogin, tvb, 90, 1, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ts2_tree, hf_ts2_name, tvb, 90, 1, ENC_ASCII|ENC_BIG_ENDIAN);
proto_tree_add_item(ts2_tree, hf_ts2_password, tvb, 120, 1, ENC_ASCII|ENC_BIG_ENDIAN);
proto_tree_add_item(ts2_tree, hf_ts2_nick, tvb, 150, 1, ENC_ASCII|ENC_BIG_ENDIAN);
conversation_data->server_port=pinfo->destport;
conversation_data->server_addr=pinfo->dst;
break;
case TS2T_LOGINREPLY:
proto_tree_add_item(ts2_tree, hf_ts2_server_name, tvb, 20, 1, ENC_ASCII|ENC_BIG_ENDIAN);
proto_tree_add_item(ts2_tree, hf_ts2_platform_string, tvb, 50, 1, ENC_ASCII|ENC_BIG_ENDIAN);
proto_tree_add_item(ts2_tree, hf_ts2_unknown, tvb, 80, 9, ENC_NA);
proto_tree_add_item(ts2_tree, hf_ts2_badlogin, tvb, 89, 3, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ts2_tree, hf_ts2_unknown, tvb, 92, 80, ENC_NA);
proto_tree_add_item(ts2_tree, hf_ts2_sessionkey, tvb, 172, 4, ENC_LITTLE_ENDIAN);
proto_tree_add_item(ts2_tree, hf_ts2_unknown, tvb, 178, 3, ENC_NA);
proto_tree_add_item(ts2_tree, hf_ts2_server_welcome_message, tvb, 180, 1, ENC_ASCII|ENC_BIG_ENDIAN);
break;
}
break;
case TS2C_ACK:
proto_tree_add_item(ts2_tree, hf_ts2_seqnum, tvb, 12, 4, ENC_LITTLE_ENDIAN);
break;
case TS2C_STANDARD:
ts2_standard_dissect(tvb, pinfo, ts2_tree, conversation_data);
break;
}
}
}
static gboolean ts2_add_checked_crc32(proto_tree *tree, int hf_item, tvbuff_t *tvb, guint16 offset, guint32 icrc32 )
{
guint8 *zero;
gint len;
guint32 ocrc32;
zero = (guint8 *)wmem_alloc0(wmem_packet_scope(), 4);
ocrc32 = crc32_ccitt_tvb(tvb, offset);
ocrc32 = crc32_ccitt_seed(zero, 4, 0xffffffff-ocrc32);
len = tvb_reported_length_remaining(tvb, offset+4);
if (len<0)
return FALSE;
ocrc32 = crc32_ccitt_tvb_offset_seed(tvb, offset+4, (guint)len, 0xffffffff-ocrc32);
if(icrc32==ocrc32)
{
proto_tree_add_uint_format(tree, hf_item, tvb, offset, 4, tvb_get_letohl(tvb, 16), "crc32: 0x%04x [correct]", tvb_get_letohl(tvb, offset));
return TRUE;
}
else
{
proto_tree_add_uint_format(tree, hf_item, tvb, offset, 4, tvb_get_letohl(tvb,16), "crc32: 0x%04x [incorrect, should be 0x%04x]", tvb_get_letohl(tvb, offset),ocrc32);
return FALSE;
}
}
static void ts2_init(void)
{
reassembly_table_init(&msg_reassembly_table,
&addresses_reassembly_table_functions);
}
void proto_register_ts2(void)
{
static hf_register_info hf[] = {
{ &hf_ts2_class,
{ "Class", "ts2.class",
FT_UINT16, BASE_HEX,
VALS(classnames), 0x0,
NULL, HFILL }
},
{ &hf_ts2_type,
{ "Type", "ts2.type",
FT_UINT16, BASE_HEX,
VALS(typenames), 0x0,
NULL, HFILL }
},
{ &hf_ts2_clientid,
{ "Client id", "ts2.clientid",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_sessionkey,
{ "Session Key", "ts2.sessionkey",
FT_UINT32, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_ackto,
{ "Ping Reply To", "ts2.ping_ackto",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_crc32,
{ "CRC32 Checksum", "ts2.crc32",
FT_UINT32, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_seqnum,
{ "Sequence Number", "ts2.sequencenum",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_protocol_string,
{ "Protocol String", "ts2.protocolstring",
FT_UINT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
#if 0
{ &hf_ts2_string,
{ "String", "ts2.string",
FT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
#endif
{ &hf_ts2_registeredlogin,
{ "Registered Login", "ts2.registeredlogin",
FT_BOOLEAN, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_name,
{ "Name", "ts2.name",
FT_UINT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_password,
{ "Password", "ts2.password",
FT_UINT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_nick,
{ "Nick", "ts2.nick",
FT_UINT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_badlogin,
{ "Bad Login", "ts2.badlogin",
FT_BOOLEAN, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_unknown,
{ "Unknown", "ts2.unknown",
FT_BYTES, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_channel,
{ "Channel", "ts2.channel",
FT_UINT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_subchannel,
{ "Sub-Channel", "ts2.subchannel",
FT_UINT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_channelpassword,
{ "Channel Password", "ts2.channelpassword",
FT_UINT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_emptyspace,
{ "Empty Space", "ts2.emptyspace",
FT_NONE, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_fragmentnumber,
{ "Fragment Number", "ts2.fragmentnumber",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_platform_string,
{ "Platform String", "ts2.platformstring",
FT_UINT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_server_name,
{ "Server Name", "ts2.servername",
FT_UINT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_server_welcome_message,
{ "Server Welcome Message", "ts2.serverwelcomemessage",
FT_UINT_STRING, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_parent_channel_id,
{ "Parent Channel ID", "ts2.parentchannelid",
FT_UINT32, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_codec,
{ "Codec", "ts2.codec",
FT_UINT16, BASE_HEX,
VALS(codecnames), 0x0,
NULL, HFILL }
},
{ &hf_ts2_channel_flags,
{ "Channel Flags", "ts2.channelflags",
FT_UINT8, BASE_HEX,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_channel_id,
{ "Channel Id", "ts2.chanelid",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_channel_name,
{ "Channel Name", "ts2.chanelname",
FT_STRINGZ, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_channel_topic,
{ "Channel Topic", "ts2.chaneltopic",
FT_STRINGZ, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_channel_description,
{ "Channel Description", "ts2.chaneldescription",
FT_STRINGZ, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_player_id,
{ "Player Id", "ts2.playerid",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_player_status_flags,
{ "Player Status Flags", "ts2.playerstatusflags",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_number_of_players,
{ "Number Of Players", "ts2.numberofplayers",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_number_of_channels,
{ "Number Of Channels", "ts2.numberofchannels",
FT_UINT32, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_resend_count,
{ "Resend Count", "ts2.resendcount",
FT_UINT16, BASE_DEC,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_ts2_status_channelcommander,
{ "Channel Commander", "ts2.playerstatusflags.channelcommander",
FT_BOOLEAN, 8,
NULL, TS2_STATUS_CHANNELCOMMANDER,
NULL, HFILL }
},
{ &hf_ts2_status_blockwhispers,
{ "Block Whispers", "ts2.playerstatusflags.blockwhispers",
FT_BOOLEAN, 8,
NULL, TS2_STATUS_BLOCKWHISPERS,
NULL, HFILL }
},
{ &hf_ts2_status_away,
{ "Away", "ts2.playerstatusflags.away",
FT_BOOLEAN, 8,
NULL, TS2_STATUS_AWAY,
NULL, HFILL }
},
{ &hf_ts2_status_mutemicrophone,
{ "Mute Microphone", "ts2.playerstatusflags.mutemicrophone",
FT_BOOLEAN, 8,
NULL, TS2_STATUS_MUTEMICROPHONE,
NULL, HFILL }
},
{ &hf_ts2_status_mute,
{ "Mute", "ts2.playerstatusflags.mute",
FT_BOOLEAN, 8,
NULL, TS2_STATUS_MUTE,
NULL, HFILL }
},
{ &hf_msg_fragments,
{"Message fragments", "ts2.fragments",
FT_NONE, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_msg_fragment,
{"Message fragment", "ts2.fragment",
FT_FRAMENUM, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_msg_fragment_overlap,
{"Message fragment overlap", "ts2.fragment.overlap",
FT_BOOLEAN, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_msg_fragment_overlap_conflicts,
{"Message fragment overlapping with conflicting data",
"ts2.fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_msg_fragment_multiple_tails,
{"Message has multiple tail fragments",
"ts2.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_msg_fragment_too_long_fragment,
{"Message fragment too long", "ts2.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE,
NULL, 0x0,
NULL, HFILL }
},
{ &hf_msg_fragment_error,
{"Message defragmentation error", "ts2.fragment.error",
FT_FRAMENUM, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_msg_fragment_count,
{"Message fragment count", "ts2.fragment.count",
FT_UINT32, BASE_DEC,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_msg_reassembled_in,
{"Reassembled in", "ts2.reassembled.in",
FT_FRAMENUM, BASE_NONE,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_msg_reassembled_length,
{"Reassembled TeamSpeak2 length", "ts2.reassembled.length",
FT_UINT32, BASE_DEC,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_ts2_channel_unregistered,
{ "Unregistered", "ts2.channelflags.unregistered",
FT_BOOLEAN, 8,
NULL, 0x01,
NULL, HFILL }
},
{ &hf_ts2_channel_moderated,
{ "Moderated", "ts2.channelflags.moderated",
FT_BOOLEAN, 8,
NULL, 0x02,
NULL, HFILL }
},
{ &hf_ts2_channel_password,
{ "Has password", "ts2.channelflags.has_password",
FT_BOOLEAN, 8,
NULL, 0x04,
NULL, HFILL }
},
{ &hf_ts2_channel_subchannels,
{ "Has subchannels", "ts2.channelflags.has_subchannels",
FT_BOOLEAN, 8,
NULL, 0x08,
NULL, HFILL }
},
{ &hf_ts2_channel_default,
{ "Default", "ts2.channelflags.default",
FT_BOOLEAN, 8,
NULL, 0x10,
NULL, HFILL }
},
{ &hf_ts2_channel_order,
{ "Channel order", "ts2.channelorder",
FT_UINT16, BASE_DEC,
NULL, 0x00,
NULL, HFILL }
},
{ &hf_ts2_max_users,
{ "Max users", "ts2.maxusers",
FT_UINT16, BASE_DEC,
NULL, 0x00,
NULL, HFILL }
}
};
static gint *ett[] = {
&ett_ts2,
&ett_msg_fragment,
&ett_msg_fragments,
&ett_ts2_channel_flags
};
proto_ts2 = proto_register_protocol (
"Teamspeak2 Protocol",
"TeamSpeak2",
"ts2"
);
proto_register_field_array(proto_ts2, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_init_routine(ts2_init);
}
void proto_reg_handoff_ts2(void)
{
dissector_handle_t ts2_handle;
ts2_handle = create_dissector_handle(dissect_ts2, proto_ts2);
dissector_add_uint("udp.port", TS2_PORT, ts2_handle);
}
