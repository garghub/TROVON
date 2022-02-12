static void
dissect_option_qos( const guchar type, const guchar sub_type, int offset,
guchar len, tvbuff_t *tvb, proto_tree *tree ) {
guchar tmp_type = 0;
proto_item *ti;
proto_tree *osi_qos_tree = NULL;
ti = proto_tree_add_text( tree, tvb, offset, len,
"Quality of service maintenance: %s",
val_to_str( type, osi_opt_qos_vals, "Unknown (0x%x)") );
osi_qos_tree = proto_item_add_subtree( ti, ott_osi_qos );
if ( OSI_OPT_SEC_MASK == type ) {
tmp_type = sub_type & OSI_OPT_QOS_SUB_RSVD;
if ( tmp_type ) {
proto_tree_add_text( osi_qos_tree, tvb, offset, len, "%s",
val_to_str( tmp_type, osi_opt_qos_sub_vals, "Unknown (0x%x)") );
}
tmp_type = sub_type & OSI_OPT_QOS_SUB_SEQ_VS_TRS;
if ( tmp_type ) {
proto_tree_add_text( osi_qos_tree, tvb, offset, len, "%s",
val_to_str( tmp_type, osi_opt_qos_sub_vals, "Unknown (0x%x)") );
}
tmp_type = sub_type &OSI_OPT_QOS_SUB_CONG_EXPED;
if ( tmp_type ) {
proto_tree_add_text( osi_qos_tree, tvb, offset, len, "%s",
val_to_str( tmp_type, osi_opt_qos_sub_vals, "Unknown (0x%x)") );
}
tmp_type = sub_type & OSI_OPT_QOS_SUB_TSD_VS_COST;
if ( tmp_type ) {
proto_tree_add_text( osi_qos_tree, tvb, offset, len, "%s",
val_to_str( tmp_type, osi_opt_qos_sub_vals, "Unknown (0x%x)") );
}
tmp_type = sub_type & OSI_OPT_QOS_SUB_RESERR_TRS;
if ( tmp_type ) {
proto_tree_add_text( osi_qos_tree, tvb, offset, len, "%s",
val_to_str( tmp_type, osi_opt_qos_sub_vals, "Unknown (0x%x)") );
}
tmp_type = sub_type & OSI_OPT_QOS_SUB_RESERR_COST;
if ( tmp_type ) {
proto_tree_add_text( osi_qos_tree, tvb, offset, len, "%s",
val_to_str( tmp_type, osi_opt_qos_sub_vals, "Unknown (0x%x)") );
}
}
}
static void
dissect_option_route( guchar parm_type, int offset, guchar parm_len,
tvbuff_t *tvb, proto_tree *tree ) {
guchar next_hop = 0;
guint16 this_hop = 0;
guchar netl = 0;
guchar last_hop = 0;
guchar cnt_hops = 0;
guchar crr = 0;
proto_item *ti;
proto_tree *osi_route_tree = NULL;
if ( parm_type == OSI_OPT_SOURCE_ROUTING ) {
next_hop = tvb_get_guint8(tvb, offset + 1 );
netl = tvb_get_guint8(tvb, next_hop + 2 );
this_hop = offset + 2;
proto_tree_add_text( tree, tvb, offset + next_hop, netl,
"Source Routing: %s ( Next Hop Highlighted In Data Buffer )",
(tvb_get_guint8(tvb, offset) == 0) ? "Partial Source Routing" :
"Complete Source Routing" );
}
else if ( parm_type == OSI_OPT_RECORD_OF_ROUTE ) {
crr = tvb_get_guint8(tvb, offset );
last_hop = tvb_get_guint8(tvb, offset + 1 );
ti = proto_tree_add_text( tree, tvb, offset , parm_len ,
"Route Recording: %s ",
(crr == 0) ? "Partial Route Recording" :
"Complete Route Recording" );
osi_route_tree = proto_item_add_subtree( ti, ott_osi_route );
if (crr == 0)
proto_tree_add_text( osi_route_tree, tvb, offset , 1,
"Partial Route Recording");
if (crr == 1)
proto_tree_add_text( osi_route_tree, tvb, offset , 1,
"Complete Route Recording");
if (last_hop == 0x03)
proto_tree_add_text( osi_route_tree, tvb, offset + 1, 1,
"No Network Entity Titles Recorded Yet");
if (last_hop == 0xFF)
proto_tree_add_text( osi_route_tree, tvb, offset + 1, 1,
"Recording Terminated : No more space !");
netl = tvb_get_guint8(tvb, this_hop + 2 );
if ( last_hop == 255 || last_hop == 0x03 )
this_hop = parm_len + 1;
else
this_hop = offset + 2;
}
while ( this_hop < offset + last_hop -2 ) {
netl = tvb_get_guint8(tvb, this_hop );
proto_tree_add_text( osi_route_tree, tvb, this_hop , netl + 1,
"Hop #%3u NETL: %2u, NET: %s",
cnt_hops++,
netl,
print_nsap_net( tvb_get_ptr(tvb, this_hop + 1, netl), netl ) );
this_hop += 1 + netl;
}
}
static void
dissect_option_rfd( const guchar error, const guchar field, int offset,
guchar len, tvbuff_t *tvb, proto_tree *tree ) {
guchar error_class = 0;
const char *format_string[] =
{ "Reason for discard {General} : %s, in field %u",
"Reason for discard {Address} : %s, in field %u",
"Reason for discard {Source Routing}: %s, in field %u",
"Reason for discard {Lifetime} : %s, in field %u",
"Reason for discard {PDU discarded} : %s, in field %u",
"Reason for discard {Reassembly} : %s, in field %u"
};
error_class = error & OSI_OPT_RFD_MASK;
tvb_ensure_bytes_exist(tvb, offset + field, 1);
if ( OSI_OPT_RFD_GENERAL == error_class ) {
proto_tree_add_text( tree, tvb, offset + field, 1, format_string[0],
val_to_str( error & OSI_OPT_RFD_SUB_MASK,
osi_opt_rfd_general, "Unknown (0x%x)"), field );
}
else if ( OSI_OPT_RFD_ADDRESS == error_class ) {
proto_tree_add_text( tree, tvb, offset + field, 1, format_string[1],
val_to_str( error & OSI_OPT_RFD_SUB_MASK,
osi_opt_rfd_address, "Unknown (0x%x)"), field );
}
else if ( OSI_OPT_RFD_SOURCE_ROUTING == error_class ) {
proto_tree_add_text( tree, tvb, offset + field, 1, format_string[2],
val_to_str( error & OSI_OPT_RFD_SUB_MASK,
osi_opt_rfd_src_route, "Unknown (0x%x)"), field );
}
else if ( OSI_OPT_RFD_LIFETIME == error_class ) {
proto_tree_add_text( tree, tvb, offset + field, 1, format_string[3],
val_to_str( error & OSI_OPT_RFD_SUB_MASK,
osi_opt_rfd_lifetime, "Unknown (0x%x)"), field );
}
else if ( OSI_OPT_RFD_PDU_DISCARDED == error_class ) {
proto_tree_add_text( tree, tvb, offset + field, 1, format_string[4],
val_to_str( error & OSI_OPT_RFD_SUB_MASK,
osi_opt_rfd_discarded, "Unknown (0x%x)"), field );
}
else if ( OSI_OPT_RFD_REASSEMBLY == error_class ) {
proto_tree_add_text( tree, tvb, offset + field, 1, format_string[5],
val_to_str( error & OSI_OPT_RFD_SUB_MASK,
osi_opt_rfd_reassembly, "Unknown (0x%x)"), field );
}
else {
proto_tree_add_text( tree, tvb, offset, len,
"Reason for discard: UNKNOWN Error Class" );
}
}
void
dissect_osi_options( guchar opt_len, tvbuff_t *tvb,
int offset, proto_tree *tree) {
proto_item *ti;
proto_tree *osi_option_tree = NULL;
guchar parm_len = 0;
guchar parm_type = 0;
guint8 octet;
if (tree) {
if ( 0 == opt_len ) {
proto_tree_add_text( tree, tvb, offset, 0,
"### No Options for this PDU ###" );
return;
}
ti = proto_tree_add_text( tree, tvb, offset, opt_len,
"### Option Section ###" );
osi_option_tree = proto_item_add_subtree( ti, ott_osi_options );
while ( 0 < opt_len ) {
parm_type = (int) tvb_get_guint8(tvb, offset);
offset++;
parm_len = (int) tvb_get_guint8(tvb, offset);
offset++;
switch ( parm_type ) {
case OSI_OPT_QOS_MAINTANANCE:
octet = tvb_get_guint8(tvb, offset);
dissect_option_qos( (guchar) (octet&OSI_OPT_QOS_MASK),
(guchar) (octet&OSI_OPT_QOS_SUB_MASK),
offset, parm_len, tvb, osi_option_tree );
break;
case OSI_OPT_SECURITY:
octet = tvb_get_guint8(tvb, offset);
proto_tree_add_text( osi_option_tree, tvb, offset, parm_len,
"Security type: %s",
val_to_str( octet&OSI_OPT_SEC_MASK,
osi_opt_sec_vals, "Unknown (0x%x)") );
break;
case OSI_OPT_PRIORITY:
octet = tvb_get_guint8(tvb, offset);
if ( OSI_OPT_MAX_PRIORITY >= octet ) {
proto_tree_add_text( osi_option_tree, tvb, offset, parm_len,
"Priority : %u", octet );
}
else {
proto_tree_add_text( osi_option_tree, tvb, offset, parm_len,
"Priority : %u ( Invalid )",
octet );
}
break;
case OSI_OPT_ADDRESS_MASK:
proto_tree_add_text( osi_option_tree, tvb, offset, parm_len,
"Address Mask: %s",
print_area( tvb_get_ptr(tvb, offset, parm_len), parm_len ) );
break;
case OSI_OPT_SNPA_MASK:
proto_tree_add_text( osi_option_tree, tvb, offset, parm_len,
"SNPA Mask : %s",
print_system_id( tvb_get_ptr(tvb, offset, parm_len), parm_len ));
break;
case OSI_OPT_ES_CONFIG_TIMER:
proto_tree_add_text( osi_option_tree, tvb, offset, parm_len,
"ESCT : %u seconds", tvb_get_ntohs( tvb, offset ) );
break;
case OSI_OPT_PADDING:
proto_tree_add_text( osi_option_tree, tvb, offset, parm_len,
"Padding : %u Octets", parm_len ) ;
break;
case OSI_OPT_SOURCE_ROUTING:
case OSI_OPT_RECORD_OF_ROUTE:
dissect_option_route( parm_type,
offset, parm_len, tvb, osi_option_tree );
break;
case OSI_OPT_REASON_OF_DISCARD:
dissect_option_rfd( tvb_get_guint8(tvb, offset),
tvb_get_guint8(tvb, offset + 1),
offset, parm_len, tvb, osi_option_tree );
break;
}
opt_len -= parm_len + 2;
offset += parm_len;
}
}
}
void
proto_register_osi_options(void) {
static gint *ott[] = {
&ott_osi_options,
&ott_osi_qos,
&ott_osi_route,
&ott_osi_redirect,
};
proto_register_subtree_array( ott, array_length(ott));
}
