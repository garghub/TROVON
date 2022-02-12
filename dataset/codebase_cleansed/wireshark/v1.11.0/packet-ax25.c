static void
dissect_ax25( tvbuff_t *tvb, packet_info *pinfo, proto_tree *parent_tree )
{
proto_item *ti;
proto_tree *ax25_tree;
int offset;
int via_index;
char *info_buffer;
const char *ax25_version;
int is_response;
const guint8 *src_addr;
const guint8 *dst_addr;
const guint8 *via_addr;
guint8 control;
guint8 pid = AX25_P_NO_L3;
guint8 src_ssid;
guint8 dst_ssid;
void *saved_private_data;
tvbuff_t *next_tvb = NULL;
info_buffer = (char *)wmem_alloc( wmem_packet_scope(), STRLEN );
info_buffer[0] = '\0';
col_set_str( pinfo->cinfo, COL_PROTOCOL, "AX.25" );
col_clear( pinfo->cinfo, COL_INFO );
offset = 0;
ti = proto_tree_add_protocol_format( parent_tree, proto_ax25, tvb, offset, -1, "AX.25");
ax25_tree = proto_item_add_subtree( ti, ett_ax25 );
dst_addr = tvb_get_ptr( tvb, offset, AX25_ADDR_LEN );
proto_tree_add_ax25( ax25_tree, hf_ax25_dst, tvb, offset, AX25_ADDR_LEN, dst_addr );
SET_ADDRESS( &pinfo->dl_dst, AT_AX25, AX25_ADDR_LEN, dst_addr );
SET_ADDRESS( &pinfo->dst, AT_AX25, AX25_ADDR_LEN, dst_addr );
dst_ssid = *(dst_addr + 6);
offset += AX25_ADDR_LEN;
src_addr = tvb_get_ptr( tvb, offset, AX25_ADDR_LEN );
proto_tree_add_ax25( ax25_tree, hf_ax25_src, tvb, offset, AX25_ADDR_LEN, src_addr );
SET_ADDRESS( &pinfo->dl_src, AT_AX25, AX25_ADDR_LEN, src_addr );
SET_ADDRESS( &pinfo->src, AT_AX25, AX25_ADDR_LEN, src_addr );
src_ssid = *(src_addr + 6);
offset += AX25_ADDR_LEN;
proto_item_append_text( ti, ", Src: %s (%s), Dst: %s (%s)",
get_ax25_name( src_addr ),
ax25_to_str( src_addr ),
get_ax25_name( dst_addr ),
ax25_to_str( dst_addr ) );
switch ( ( (dst_ssid >> 6) & 0x02) | ( (src_ssid >> 7) & 0x01 ) )
{
case 1 :
ax25_version = "V2.0+";
is_response = TRUE;
break;
case 2 :
ax25_version = "V2.0+";
is_response = FALSE;
break;
default :
ax25_version = "V?.?";
is_response = FALSE;
break;
}
proto_item_append_text( ti, ", Ver: %s", ax25_version );
via_index = 0;
while ( ( tvb_get_guint8( tvb, offset - 1 ) & 0x01 ) == 0 )
{
if ( via_index < AX25_MAX_DIGIS )
{
via_addr = tvb_get_ptr( tvb, offset, AX25_ADDR_LEN );
proto_tree_add_ax25( ax25_tree, hf_ax25_via[ via_index ], tvb, offset, AX25_ADDR_LEN, via_addr );
via_index++;
}
offset += AX25_ADDR_LEN;
}
control = dissect_xdlc_control( tvb,
offset,
pinfo,
ax25_tree,
hf_ax25_ctl,
ett_ax25_ctl,
&ax25_cf_items,
NULL,
NULL,
NULL,
is_response,
FALSE,
FALSE );
offset += XDLC_CONTROL_LEN(control, FALSE);
if ( XDLC_IS_INFORMATION( control ) )
{
pid = tvb_get_guint8( tvb, offset );
col_append_fstr( pinfo->cinfo, COL_INFO, ", %s", val_to_str(pid, pid_vals, "Unknown (0x%02x)") );
proto_tree_add_uint( ax25_tree, hf_ax25_pid, tvb, offset, 1, pid );
offset += 1;
proto_item_set_end(ti, tvb, offset);
saved_private_data = pinfo->private_data;
next_tvb = tvb_new_subset_remaining(tvb, offset);
if (!dissector_try_uint(ax25_dissector_table, pid, next_tvb, pinfo, parent_tree))
{
call_dissector(data_handle, next_tvb, pinfo, parent_tree);
}
pinfo->private_data = saved_private_data;
}
else
proto_item_set_end(ti, tvb, offset);
}
void
capture_ax25( const guchar *pd, int offset, int len, packet_counts *ld)
{
guint8 control;
guint8 pid;
int l_offset;
if ( ! BYTES_ARE_IN_FRAME( offset, len, AX25_HEADER_SIZE ) )
{
ld->other++;
return;
}
l_offset = offset;
l_offset += AX25_ADDR_LEN;
l_offset += AX25_ADDR_LEN;
while ( ( pd[ l_offset - 1 ] & 0x01 ) == 0 )
l_offset += AX25_ADDR_LEN;
control = pd[ l_offset ];
if ( XDLC_IS_INFORMATION( control ) )
{
l_offset += 1;
pid = pd[ l_offset ];
l_offset += 1;
switch ( pid & 0x0ff )
{
case AX25_P_NETROM : capture_netrom( pd, l_offset, len, ld ); break;
case AX25_P_IP : capture_ip( pd, l_offset, len, ld ); break;
case AX25_P_ARP : ld->arp++; break;
default : ld->other++; break;
}
}
}
void
proto_register_ax25(void)
{
static const true_false_string flags_set_truth =
{
"Set",
"Not set"
};
static hf_register_info hf[] = {
{ &hf_ax25_dst,
{ "Destination", "ax25.dst",
FT_AX25, BASE_NONE, NULL, 0x0,
"Destination callsign", HFILL }
},
{ &hf_ax25_src,
{ "Source", "ax25.src",
FT_AX25, BASE_NONE, NULL, 0x0,
"Source callsign", HFILL }
},
{ &hf_ax25_via[ 0 ],
{ "Via 1", "ax25.via1",
FT_AX25, BASE_NONE, NULL, 0x0,
"Via callsign 1", HFILL }
},
{ &hf_ax25_via[ 1 ],
{ "Via 2", "ax25.via2",
FT_AX25, BASE_NONE, NULL, 0x0,
"Via callsign 2", HFILL }
},
{ &hf_ax25_via[ 2 ],
{ "Via 3", "ax25.via3",
FT_AX25, BASE_NONE, NULL, 0x0,
"Via callsign 3", HFILL }
},
{ &hf_ax25_via[ 3 ],
{ "Via 4", "ax25.via4",
FT_AX25, BASE_NONE, NULL, 0x0,
"Via callsign 4", HFILL }
},
{ &hf_ax25_via[ 4 ],
{ "Via 5", "ax25.via5",
FT_AX25, BASE_NONE, NULL, 0x0,
"Via callsign 5", HFILL }
},
{ &hf_ax25_via[ 5 ],
{ "Via 6", "ax25.via6",
FT_AX25, BASE_NONE, NULL, 0x0,
"Via callsign 6", HFILL }
},
{ &hf_ax25_via[ 6 ],
{ "Via 7", "ax25.via7",
FT_AX25, BASE_NONE, NULL, 0x0,
"Via callsign 7", HFILL }
},
{ &hf_ax25_via[ 7 ],
{ "Via 8", "ax25.via8",
FT_AX25, BASE_NONE, NULL, 0x0,
"Via callsign 8", HFILL }
},
{ &hf_ax25_ctl,
{ "Control", "ax25.ctl",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Control field", HFILL }
},
{ &hf_ax25_n_r,
{ "n(r)", "ax25.ctl.n_r",
FT_UINT8, BASE_DEC, NULL, XDLC_N_R_MASK,
NULL, HFILL }
},
{ &hf_ax25_n_s,
{ "n(s)", "ax25.ctl.n_s",
FT_UINT8, BASE_DEC, NULL, XDLC_N_S_MASK,
NULL, HFILL }
},
{ &hf_ax25_p,
{ "Poll", "ax25.ctl.p",
FT_BOOLEAN, 8, TFS(&flags_set_truth), XDLC_P_F,
NULL, HFILL }
},
{ &hf_ax25_f,
{ "Final", "ax25.ctl.f",
FT_BOOLEAN, 8, TFS(&flags_set_truth), XDLC_P_F,
NULL, HFILL }
},
{ &hf_ax25_ftype_s,
{ "Frame type", "ax25.ctl.ftype_s",
FT_UINT8, BASE_HEX, VALS(stype_vals), XDLC_S_FTYPE_MASK,
NULL, HFILL }
},
{ &hf_ax25_ftype_i,
{ "Frame type", "ax25.ctl.ftype_i",
FT_UINT8, BASE_HEX, VALS(ftype_vals), XDLC_I_MASK,
NULL, HFILL }
},
{ &hf_ax25_ftype_su,
{ "Frame type", "ax25.ctl.ftype_su",
FT_UINT8, BASE_HEX, VALS(ftype_vals), XDLC_S_U_MASK,
NULL, HFILL }
},
{ &hf_ax25_u_cmd,
{ "Frame type", "ax25.ctl.u_cmd",
FT_UINT8, BASE_HEX, VALS(modifier_vals_cmd), XDLC_U_MODIFIER_MASK,
NULL, HFILL }
},
{ &hf_ax25_u_resp,
{ "Frame type", "ax25.ctl.u_resp",
FT_UINT8, BASE_HEX, VALS(modifier_vals_resp), XDLC_U_MODIFIER_MASK,
NULL, HFILL }
},
{ &hf_ax25_pid,
{ "Protocol ID", "ax25.pid",
FT_UINT8, BASE_HEX, VALS(pid_vals), 0x0,
"Protocol identifier", HFILL }
},
};
static gint *ett[] = {
&ett_ax25,
&ett_ax25_ctl,
};
proto_ax25 = proto_register_protocol("Amateur Radio AX.25", "AX.25", "ax25");
ax25_handle = register_dissector( "ax25", dissect_ax25, proto_ax25 );
proto_register_field_array( proto_ax25, hf, array_length(hf ) );
proto_register_subtree_array(ett, array_length(ett ) );
ax25_dissector_table = register_dissector_table("ax25.pid", "AX.25 protocol ID", FT_UINT8, BASE_HEX);
}
void
proto_reg_handoff_ax25(void)
{
dissector_add_uint("wtap_encap", WTAP_ENCAP_AX25, ax25_handle);
dissector_add_uint("ip.proto", IP_PROTO_AX25, ax25_handle);
data_handle = find_dissector( "data" );
}
