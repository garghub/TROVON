static guint32 crc_calc(guint32 fcs, tvbuff_t *tvb, guint len)
{
const guchar *cp;
cp = tvb_get_ptr(tvb, 0, len);
while (len--)
fcs = (fcs >> 8) ^ tbl_crc24[(fcs ^ *cp++) & 0xff];
return fcs;
}
static void
llc_gprs_dissect_xid(tvbuff_t *tvb, packet_info *pinfo, proto_item *llcgprs_tree)
{
guint8 xid_param_len = 0, byte1 = 0, byte2 = 0, tmp = 0;
guint item_len = 0;
guint location = 0;
guint loop_counter = 0;
proto_tree *uinfo_tree = NULL;
proto_tree *xid_tree = NULL;
guint info_len;
info_len = tvb_reported_length(tvb);
xid_tree = proto_tree_add_subtree_format(llcgprs_tree, tvb, 0, info_len,
ett_llcgprs_ui, NULL, "Information Field: Length = %u", info_len);
while (location < info_len)
{
byte1 = tvb_get_guint8(tvb, location);
if (byte1 & 0x80)
{
guint8 xid_param_len_high = 0;
guint8 xid_param_len_low = 0;
byte2 = tvb_get_guint8(tvb, location + 1);
xid_param_len_high = byte1 & 0x03;
xid_param_len_low = byte2 & 0xFC;
xid_param_len_low = xid_param_len_low >> 2;
xid_param_len_low = xid_param_len_low & 0x3F;
xid_param_len_high = xid_param_len_high << 6;
xid_param_len_high = xid_param_len_high & 0xC0;
xid_param_len = xid_param_len_high | xid_param_len_low;
item_len = xid_param_len + 2;
}
else
{
xid_param_len = byte1 & 0x3;
item_len = xid_param_len + 1;
}
tmp = byte1 & 0x7C;
tmp = tmp >> 2;
if (tmp == 0xB)
{
tvbuff_t *sndcp_xid_tvb;
guint8 sndcp_xid_offset;
uinfo_tree = proto_tree_add_subtree(xid_tree, tvb, location, item_len,
ett_llcgprs_ui, NULL, "XID parameter Type: L3 parameters");
proto_tree_add_uint(uinfo_tree, hf_llcgprs_xid_xl, tvb, location, 1, byte1);
proto_tree_add_uint(uinfo_tree, hf_llcgprs_xid_type, tvb, location, 1, byte1);
proto_tree_add_uint(uinfo_tree, hf_llcgprs_xid_len1, tvb, location, 1, byte1);
if (byte1 & 0x80) {
proto_tree_add_uint(uinfo_tree, hf_llcgprs_xid_len2, tvb, location+1, 1, byte2);
proto_tree_add_uint(uinfo_tree, hf_llcgprs_xid_spare, tvb, location+1, 1, byte2);
sndcp_xid_offset = 2;
}
else
{
sndcp_xid_offset = 1;
}
if (xid_param_len) {
sndcp_xid_tvb = tvb_new_subset_length (tvb, location+sndcp_xid_offset, xid_param_len);
if(sndcp_xid_handle)
{
call_dissector(sndcp_xid_handle, sndcp_xid_tvb, pinfo, uinfo_tree);
}
}
location += item_len;
}
else
{
if (( xid_param_len > 0 ) && ( xid_param_len <=4 ))
{
guint32 value = 0;
guint8 i;
for (i=1;i<=xid_param_len;i++)
{
value <<= 8;
value |= (guint32)tvb_get_guint8(tvb, location+i );
}
uinfo_tree = proto_tree_add_subtree_format(xid_tree, tvb, location, item_len,
ett_llcgprs_ui, NULL, "XID Parameter Type: %s - Value: %u",
val_to_str_ext_const(tmp, &xid_param_type_str_ext, "Reserved Type:%X"), value);
}
else
{
uinfo_tree = proto_tree_add_subtree_format(xid_tree, tvb, location, item_len,
ett_llcgprs_ui, NULL, "XID Parameter Type: %s",
val_to_str_ext_const(tmp, &xid_param_type_str_ext, "Reserved Type:%X"));
}
proto_tree_add_uint(uinfo_tree, hf_llcgprs_xid_xl, tvb, location,
1, byte1);
proto_tree_add_uint(uinfo_tree, hf_llcgprs_xid_type, tvb, location,
1, byte1);
proto_tree_add_uint(uinfo_tree, hf_llcgprs_xid_len1, tvb, location,
1, byte1);
if (byte1 & 0x80) {
proto_tree_add_uint(uinfo_tree, hf_llcgprs_xid_len2, tvb, location,
1, byte2);
proto_tree_add_uint(uinfo_tree, hf_llcgprs_xid_spare, tvb, location,
1, byte2);
location++;
}
location++;
for (loop_counter = 0; loop_counter < xid_param_len; loop_counter++)
{
byte2 = tvb_get_guint8(tvb, location);
proto_tree_add_uint(uinfo_tree, hf_llcgprs_xid_byte, tvb, location,
1, byte2);
location++;
}
}
}
}
static int
dissect_llcgprs(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint offset = 0;
guint8 addr_fld=0, sapi=0, ctrl_fld_fb=0, frame_format, tmp=0;
guint16 epm = 0, nu=0, ctrl_fld_ui_s=0;
proto_item *ti, *addres_field_item;
proto_tree *llcgprs_tree=NULL , *ad_f_tree =NULL, *ctrl_f_tree=NULL, *ui_tree=NULL;
tvbuff_t *next_tvb;
guint length, captured_length;
guint crc_length = 0, llc_data_length;
guint32 fcs=0;
guint32 fcs_calc=0;
fcs_status_t fcs_status;
guint16 ns = 0;
guint16 nr = 0;
guint8 k = 0;
guint8 m_bits = 0;
guint info_len;
proto_tree *uinfo_tree = NULL;
gboolean ciphered_ui_frame = FALSE;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "GPRS-LLC");
llc_data_length = length = tvb_reported_length(tvb);
if (length >= CRC_LENGTH) {
llc_data_length -= CRC_LENGTH;
}
else
{
llc_data_length = 0;
}
captured_length = tvb_captured_length(tvb);
addr_fld = tvb_get_guint8(tvb, offset);
offset++;
if (addr_fld > 128 )
{
col_set_str(pinfo->cinfo, COL_INFO, "Invalid packet - Protocol Discriminator bit is set to 1");
return offset;
}
sapi = addr_fld & 0xF;
col_add_fstr(pinfo->cinfo, COL_INFO, "SAPI: %s", val_to_str_ext_const(sapi, &sapi_abrv_ext, "Unknown (%d)"));
if (tree)
{
ti = proto_tree_add_protocol_format(tree, proto_llcgprs, tvb, 0, -1,
"MS-SGSN LLC (Mobile Station - Serving GPRS Support Node Logical Link Control) SAPI: %s",
val_to_str_ext_const(sapi, &sapi_t_ext, "Unknown (%u)"));
llcgprs_tree = proto_item_add_subtree(ti, ett_llcgprs);
addres_field_item = proto_tree_add_uint_format(llcgprs_tree, hf_llcgprs_sapi,
tvb, 0, 1, sapi, "Address field SAPI: %s", val_to_str_ext_const(sapi, &sapi_abrv_ext, "Unknown (%d)"));
ad_f_tree = proto_item_add_subtree(addres_field_item, ett_llcgprs_adf);
proto_tree_add_boolean(ad_f_tree, hf_llcgprs_pd, tvb, 0, 1, addr_fld );
proto_tree_add_boolean(ad_f_tree, hf_llcgprs_cr, tvb, 0, 1, addr_fld );
proto_tree_add_uint(ad_f_tree, hf_llcgprs_sapib, tvb, 0, 1, addr_fld );
}
ctrl_fld_fb = tvb_get_guint8(tvb, offset);
if (ctrl_fld_fb < 0xC0)
{
frame_format = (ctrl_fld_fb < 0x80)? I_FORMAT : S_FORMAT;
}
else
{
frame_format = (ctrl_fld_fb < 0xe0 )? UI_FORMAT : U_FORMAT;
}
switch (frame_format)
{
case I_FORMAT:
col_append_str(pinfo->cinfo, COL_INFO, ", I, ");
ns = tvb_get_ntohs(tvb, offset);
ns = (ns >> 4)& 0x01FF;
nr = ctrl_fld_ui_s = tvb_get_ntohs(tvb, offset + 1);
nr = (nr >> 2) & 0x01FF;
epm = ctrl_fld_ui_s & 0x3;
col_append_str(pinfo->cinfo, COL_INFO, val_to_str(epm, cr_formats_ipluss, "Unknown (%d)"));
col_append_fstr(pinfo->cinfo, COL_INFO, ", N(S) = %u", ns);
col_append_fstr(pinfo->cinfo, COL_INFO, ", N(R) = %u", nr);
if (tree)
{
guint32 tmpx;
ctrl_f_tree = proto_tree_add_subtree_format(llcgprs_tree, tvb, offset,
3, ett_llcgprs_sframe, NULL, "Information format: %s: N(S) = %u, N(R) = %u",
val_to_str(epm, cr_formats_ipluss, "Unknown (%d)"), ns, nr);
tmpx = tvb_get_ntohs(tvb, offset) << 16;
proto_tree_add_uint(ctrl_f_tree, hf_llcgprs_ifmt, tvb, offset, 3, tmpx);
proto_tree_add_boolean(ctrl_f_tree, hf_llcgprs_Ai, tvb, offset, 3, tmpx);
proto_tree_add_uint(ctrl_f_tree, hf_llcgprs_izerobit, tvb, offset, 3, tmpx);
tmpx = ns << 12;
proto_tree_add_uint(ctrl_f_tree, hf_llcgprs_isack_ns, tvb, offset, 3, tmpx);
tmpx = nr << 2;
proto_tree_add_uint(ctrl_f_tree, hf_llcgprs_isack_nr, tvb, offset, 3, tmpx);
proto_tree_add_uint(ctrl_f_tree, hf_llcgprs_isack_sfb, tvb, offset, 3, ctrl_fld_ui_s);
}
offset += 3;
if (epm == 0x03)
{
guint8 kmask;
k = kmask = tvb_get_guint8(tvb, offset);
k = k & 0x1F;
offset++;
k++;
col_append_fstr(pinfo->cinfo, COL_INFO, ", k = %u", k);
if (tree)
{
guint8 loop_count = 0;
guint8 r_byte = 0;
guint location = offset;
ctrl_f_tree = proto_tree_add_subtree_format(llcgprs_tree, tvb, (offset-1),
(k+1), ett_llcgprs_sframe, NULL, "SACK FRAME: k = %u", k);
proto_tree_add_uint(ctrl_f_tree, hf_llcgprs_kmask, tvb, offset-1, 1, kmask);
proto_tree_add_uint(ctrl_f_tree, hf_llcgprs_k, tvb, offset-1, 1, k);
for (loop_count = 0; loop_count < k; loop_count++)
{
r_byte = tvb_get_guint8(tvb, location);
proto_tree_add_uint(ctrl_f_tree, hf_llcgprs_rbyte, tvb, location, 1, r_byte);
location++;
}
}
offset += k;
}
crc_length = llc_data_length;
break;
case S_FORMAT:
col_append_str(pinfo->cinfo, COL_INFO, ", S, ");
nu = ctrl_fld_ui_s = tvb_get_ntohs(tvb, offset);
epm = ctrl_fld_ui_s & 0x3;
nu = (nu >>2)&0x01FF;
col_append_str(pinfo->cinfo, COL_INFO, val_to_str(epm, cr_formats_ipluss, "Unknown (%d)"));
col_append_fstr(pinfo->cinfo, COL_INFO, ", N(R) = %u", nu);
if (tree)
{
static const int * s_formats[] = {
&hf_llcgprs_S_fmt,
&hf_llcgprs_As,
&hf_llcgprs_sspare,
&hf_llcgprs_NR,
&hf_llcgprs_sjsd,
NULL
};
proto_tree_add_bitmask_text(llcgprs_tree, tvb, offset, 2,
"Supervisory format: ", NULL, ett_llcgprs_sframe, s_formats, ENC_BIG_ENDIAN, 0);
}
offset += 2;
if ((ctrl_fld_ui_s & 0x03) == 0x03)
{
guint32 sack_length = llc_data_length - offset;
if (tree)
{
guint loop_count;
guint8 r_byte;
guint16 location = offset;
ctrl_f_tree = proto_tree_add_subtree_format(llcgprs_tree, tvb, offset, sack_length,
ett_llcgprs_sframe, NULL, "SACK FRAME: length = %u", sack_length);
for (loop_count = 0; loop_count < sack_length; loop_count++)
{
r_byte = tvb_get_guint8(tvb, location);
proto_tree_add_uint(ctrl_f_tree, hf_llcgprs_rbyte, tvb,
location, 1, r_byte);
location++;
}
offset += sack_length;
}
}
crc_length = llc_data_length;
break;
case UI_FORMAT:
col_append_str(pinfo->cinfo, COL_INFO, ", UI, ");
nu = ctrl_fld_ui_s = tvb_get_ntohs(tvb, offset);
epm = ctrl_fld_ui_s & 0x3;
nu = (nu >>2)&0x01FF;
if (epm & UI_MASK_E)
{
ciphered_ui_frame = TRUE;
}
if ((epm & UI_MASK_PM)== 0)
{
crc_length = MIN(UI_HDR_LENGTH + N202, llc_data_length);
}
else
{
crc_length = llc_data_length;
}
col_append_str(pinfo->cinfo, COL_INFO, val_to_str(epm, pme, "Unknown (%d)"));
col_append_fstr(pinfo->cinfo, COL_INFO, ", N(U) = %u", nu);
if (tree)
{
static const int * i_formats[] = {
&hf_llcgprs_U_fmt,
&hf_llcgprs_sp_bits,
&hf_llcgprs_NU,
&hf_llcgprs_E_bit,
&hf_llcgprs_PM_bit,
NULL
};
proto_tree_add_bitmask_text(llcgprs_tree, tvb, offset, 2,
"Unconfirmed Information format - UI: ", NULL, ett_llcgprs_ctrlf, i_formats, ENC_BIG_ENDIAN, 0);
}
offset += 2;
break;
case U_FORMAT:
col_append_str(pinfo->cinfo, COL_INFO, ", U, ");
tmp = ctrl_fld_fb & 0xf;
col_append_str(pinfo->cinfo, COL_INFO,
val_to_str(tmp, cr_formats_unnumb, "Unknown/invalid code:%X"));
ui_tree = proto_tree_add_subtree_format(llcgprs_tree, tvb, offset, (llc_data_length-1),
ett_llcgprs_ui, NULL, "Unnumbered frame: %s",
val_to_str(tmp, cr_formats_unnumb, "Unknown/invalid code:%X"));
proto_tree_add_uint(ui_tree, hf_llcgprs_Un, tvb, offset, 1, ctrl_fld_fb);
proto_tree_add_boolean(ui_tree, hf_llcgprs_PF, tvb, offset, 1, ctrl_fld_fb);
proto_tree_add_uint(ui_tree, hf_llcgprs_ucom, tvb, offset, 1, ctrl_fld_fb);
offset += 1;
crc_length = llc_data_length;
break;
}
if (captured_length >= length && length >= CRC_LENGTH)
{
fcs_calc = crc_calc ( INIT_CRC24 , tvb, crc_length );
fcs_calc = ~fcs_calc;
fcs_calc &= 0xffffff;
fcs = tvb_get_letoh24(tvb, llc_data_length);
if ( fcs_calc == fcs )
{
fcs_status = FCS_VALID;
proto_tree_add_uint_format_value(llcgprs_tree, hf_llcgprs_fcs, tvb, llc_data_length, CRC_LENGTH,
fcs_calc&0xffffff, "0x%06x (correct)", fcs_calc&0xffffff);
}
else
{
if (ciphered_ui_frame)
{
fcs_status = FCS_NOT_VALID_DUE_TO_CIPHERING;
proto_tree_add_uint_format_value(llcgprs_tree, hf_llcgprs_fcs, tvb, llc_data_length, CRC_LENGTH,
fcs, "0x%06x (incorrect, maybe due to ciphering, calculated 0x%06x)", fcs, fcs_calc );
}
else
{
fcs_status = FCS_NOT_VALID;
proto_tree_add_uint_format_value(llcgprs_tree, hf_llcgprs_fcs, tvb, llc_data_length, CRC_LENGTH,
fcs, "0x%06x (incorrect, should be 0x%06x)", fcs, fcs_calc );
}
}
}
else
{
fcs_status = FCS_NOT_COMPUTED;
proto_tree_add_uint_format_value(llcgprs_tree, hf_llcgprs_fcs, tvb, 0, 0, 0,
"FCS: Not enough data to compute the FCS");
}
switch (frame_format)
{
case I_FORMAT:
if ((sapi == SAPI_TOM2) || (sapi == SAPI_TOM8))
{
if (tree)
{
guint8 tom_byte = 0;
guint8 remaining_length = 0;
guint8 tom_pd = 0;
int loop_counter = 0;
tom_byte = tvb_get_guint8(tvb, offset);
remaining_length = (tom_byte >> 4) & 0x0F;
tom_pd = tom_byte & 0x0F;
ctrl_f_tree = proto_tree_add_subtree_format(llcgprs_tree, tvb, offset,
(llc_data_length-offset), ett_llcgprs_sframe, NULL,
"TOM Envelope - Protocol: %s",
val_to_str(tom_pd, tompd_formats, "Unknown (%d)"));
proto_tree_add_uint(ctrl_f_tree, hf_llcgprs_tom_rl, tvb, offset, 1, tom_byte);
proto_tree_add_uint(ctrl_f_tree, hf_llcgprs_tom_pd, tvb, offset, 1, tom_byte);
offset++;
if (remaining_length != 0x0F)
{
for (loop_counter = 0; loop_counter < remaining_length; loop_counter++)
{
tom_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(ctrl_f_tree, hf_llcgprs_tom_header, tvb,
offset, 1, tom_byte);
offset++;
}
remaining_length = llc_data_length - offset;
for (loop_counter = 0; loop_counter < remaining_length; loop_counter++)
{
tom_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(ctrl_f_tree, hf_llcgprs_tom_data, tvb,
offset, 1, tom_byte);
offset++;
}
}
}
}
else
{
next_tvb = tvb_new_subset_length(tvb, offset, (llc_data_length-offset));
if (!dissector_try_uint(llcgprs_subdissector_table, sapi, next_tvb, pinfo, tree))
{
call_data_dissector(next_tvb, pinfo, tree);
}
}
break;
case S_FORMAT:
if ((sapi == SAPI_TOM2) || (sapi == SAPI_TOM8))
{
if (tree)
{
guint8 tom_byte = 0;
guint8 remaining_length = 0;
guint8 tom_pd = 0;
int loop_counter = 0;
tom_byte = tvb_get_guint8(tvb, offset);
remaining_length = (tom_byte >> 4) & 0x0F;
tom_pd = tom_byte & 0x0F;
ctrl_f_tree = proto_tree_add_subtree_format(llcgprs_tree, tvb, offset,
(llc_data_length-offset), ett_llcgprs_sframe, NULL,
"TOM Envelope - Protocol: %s",
val_to_str(tom_pd, tompd_formats, "Unknown (%d)"));
proto_tree_add_uint(ctrl_f_tree, hf_llcgprs_tom_rl, tvb, offset, 1, tom_byte);
proto_tree_add_uint(ctrl_f_tree, hf_llcgprs_tom_pd, tvb, offset, 1, tom_byte);
offset++;
if (remaining_length != 0x0F)
{
for (loop_counter = 0; loop_counter < remaining_length; loop_counter++)
{
tom_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(ctrl_f_tree, hf_llcgprs_tom_header, tvb,
offset, 1, tom_byte);
offset++;
}
remaining_length = llc_data_length - offset;
for (loop_counter = 0; loop_counter < remaining_length; loop_counter++)
{
tom_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(ctrl_f_tree, hf_llcgprs_tom_data, tvb,
offset, 1, tom_byte);
offset++;
}
}
}
}
else if (llc_data_length>offset)
{
next_tvb = tvb_new_subset_length(tvb, offset, (llc_data_length-offset));
if (!dissector_try_uint(llcgprs_subdissector_table, sapi, next_tvb, pinfo, tree))
{
call_data_dissector(next_tvb, pinfo, tree);
}
}
break;
case UI_FORMAT:
next_tvb = tvb_new_subset_length(tvb, offset, (llc_data_length-offset));
if ((ignore_cipher_bit && (fcs_status == FCS_VALID)) || !(epm & 0x2))
{
if ((sapi == SAPI_TOM2) || (sapi == SAPI_TOM8))
{
if (tree)
{
guint8 tom_byte = 0;
guint8 remaining_length = 0;
guint8 tom_pd = 0;
int loop_counter = 0;
tom_byte = tvb_get_guint8(tvb, offset);
remaining_length = (tom_byte >> 4) & 0x0F;
tom_pd = tom_byte & 0x0F;
ctrl_f_tree = proto_tree_add_subtree_format(llcgprs_tree, tvb, offset,
(llc_data_length-offset), ett_llcgprs_sframe, NULL,
"TOM Envelope - Protocol: %s",
val_to_str(tom_pd, tompd_formats, "Unknown (%d)"));
proto_tree_add_uint(ctrl_f_tree, hf_llcgprs_tom_rl, tvb, offset, 1, tom_byte);
proto_tree_add_uint(ctrl_f_tree, hf_llcgprs_tom_pd, tvb, offset, 1, tom_byte);
offset++;
if (remaining_length != 0x0F)
{
for (loop_counter = 0; loop_counter < remaining_length; loop_counter++)
{
tom_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(ctrl_f_tree, hf_llcgprs_tom_header, tvb,
offset, 1, tom_byte);
offset++;
}
remaining_length = llc_data_length - offset;
for (loop_counter = 0; loop_counter < remaining_length; loop_counter++)
{
tom_byte = tvb_get_guint8(tvb, offset);
proto_tree_add_uint(ctrl_f_tree, hf_llcgprs_tom_data, tvb,
offset, 1, tom_byte);
offset++;
}
}
}
}
else if (llc_data_length>offset)
{
if (!dissector_try_uint(llcgprs_subdissector_table, sapi, next_tvb, pinfo, tree))
{
call_data_dissector(next_tvb, pinfo, tree);
}
}
}
else
{
call_data_dissector(next_tvb, pinfo, tree);
}
break;
case U_FORMAT:
m_bits = ctrl_fld_fb & 0x0F;
info_len = llc_data_length - offset;
switch (m_bits)
{
case U_DM:
case U_DISC:
case U_NULL:
proto_tree_add_expert(llcgprs_tree, pinfo, &ei_llcgprs_no_info_field, tvb, offset, (llc_data_length-2));
break;
case U_UA:
if (tree)
{
tvbuff_t *xid_tvb;
xid_tvb = tvb_new_subset_length (tvb, offset, info_len);
llc_gprs_dissect_xid(xid_tvb, pinfo, llcgprs_tree);
}
break;
case U_SABM:
case U_XID:
if (tree)
{
tvbuff_t *xid_tvb;
xid_tvb = tvb_new_subset_length (tvb, offset, info_len);
llc_gprs_dissect_xid(xid_tvb, pinfo, llcgprs_tree);
}
break;
case U_FRMR:
if (tree)
{
guint32 fld_vars = 0;
guint16 cf_byte = 0;
int loop_counter = 0;
int location = 0;
ui_tree = proto_tree_add_subtree_format(llcgprs_tree, tvb, offset, (llc_data_length-2),
ett_llcgprs_ui, NULL, "Information Field: Length = %u", info_len);
uinfo_tree = proto_tree_add_subtree(ui_tree, tvb, offset, 6,
ett_llcgprs_ui, NULL, "Rejected Frame Control Field");
location = offset;
for (loop_counter = 0; loop_counter < 3; loop_counter++)
{
cf_byte = tvb_get_ntohs(tvb, location);
proto_tree_add_uint(uinfo_tree, hf_llcgprs_frmr_cf, tvb, location,
2, cf_byte);
location += 2;
}
uinfo_tree = proto_tree_add_subtree(ui_tree, tvb, location, 4,
ett_llcgprs_ui, NULL, "Information Field Data");
fld_vars = tvb_get_ntohl(tvb, location);
proto_tree_add_uint(uinfo_tree, hf_llcgprs_frmr_spare, tvb, location,
4, fld_vars);
proto_tree_add_uint(uinfo_tree, hf_llcgprs_frmr_vs, tvb, location,
2, fld_vars);
proto_tree_add_uint(uinfo_tree, hf_llcgprs_frmr_vr, tvb, (location + 1),
2, fld_vars);
proto_tree_add_uint(uinfo_tree, hf_llcgprs_frmr_cr, tvb, (location + 2),
1, fld_vars);
proto_tree_add_uint(uinfo_tree, hf_llcgprs_frmr_w4, tvb, (location + 3),
1, fld_vars);
proto_tree_add_uint(uinfo_tree, hf_llcgprs_frmr_w3, tvb, (location + 3),
1, fld_vars);
proto_tree_add_uint(uinfo_tree, hf_llcgprs_frmr_w2, tvb, (location + 3),
1, fld_vars);
proto_tree_add_uint(uinfo_tree, hf_llcgprs_frmr_w1, tvb, (location + 3),
1, fld_vars);
}
break;
default:
break;
}
break;
}
return tvb_captured_length(tvb);
}
void
proto_register_llcgprs(void)
{
static hf_register_info hf[] = {
{ &hf_llcgprs_sapi,
{ "SAPI", "llcgprs.sapi", FT_UINT8, BASE_DEC|BASE_EXT_STRING,
&sapi_abrv_ext, 0x0, "Service Access Point Identifier", HFILL }},
{ &hf_llcgprs_pd,
{ "Protocol Discriminator_bit", "llcgprs.pd", FT_BOOLEAN, 8,
TFS(&pd_bit), 0x80, "Protocol Discriminator bit (should be 0)", HFILL }},
{ &hf_llcgprs_fcs,
{ "FCS", "llcgprs.fcs", FT_UINT24, BASE_HEX,
NULL, 0, NULL, HFILL }},
{ &hf_llcgprs_sjsd,
{ "Supervisory function bits", "llcgprs.s1s2", FT_UINT16, BASE_HEX,
VALS(cr_formats_ipluss), 0x3, NULL, HFILL }},
{ &hf_llcgprs_cr,
{ "Command/Response bit", "llcgprs.cr", FT_BOOLEAN, 8,
TFS(&cr_bit), 0x40, NULL, HFILL }},
{ &hf_llcgprs_sapib,
{ "SAPI", "llcgprs.sapib", FT_UINT8, BASE_DEC|BASE_EXT_STRING ,
&sapi_t_ext, 0xf, "Service Access Point Identifier", HFILL }},
{ &hf_llcgprs_U_fmt,
{ "UI format", "llcgprs.ui", FT_UINT16, BASE_HEX,
NULL, UI_MASK_FMT, "UI frame format", HFILL }},
{ &hf_llcgprs_Un,
{ "U format", "llcgprs.u", FT_UINT8, BASE_HEX,
NULL, 0xe0, "U frame format", HFILL }},
{ &hf_llcgprs_sp_bits,
{ "Spare bits", "llcgprs.ui_sp_bit", FT_UINT16, BASE_HEX,
NULL, UI_MASK_SPB, NULL, HFILL }},
{ &hf_llcgprs_NU,
{ "N(U)", "llcgprs.nu", FT_UINT16, BASE_DEC,
NULL, UI_MASK_NU, "Transmitted unconfirmed sequence number", HFILL }},
{ &hf_llcgprs_E_bit,
{ "E bit", "llcgprs.e", FT_BOOLEAN, 16,
TFS(&e_bit), UI_MASK_E, "Encryption mode bit", HFILL }},
{ &hf_llcgprs_PM_bit,
{ "PM bit", "llcgprs.pm", FT_BOOLEAN, 16,
TFS(&pm_bit), UI_MASK_PM, "Protected mode bit", HFILL }},
{ &hf_llcgprs_As,
{ "Ackn request bit", "llcgprs.as", FT_BOOLEAN, 16,
TFS(&a_bit), 0x2000 , "Acknowledgement request bit A", HFILL }},
{ &hf_llcgprs_PF,
{ "P/F bit", "llcgprs.pf", FT_BOOLEAN, 8,
NULL, 0x10, "Poll/Final bit", HFILL }},
{ &hf_llcgprs_ucom,
{ "Command/Response", "llcgprs.ucom", FT_UINT8, BASE_HEX,
VALS(cr_formats_unnumb), 0xf, "Commands and Responses", HFILL }},
{ &hf_llcgprs_NR,
{ "Receive sequence number", "llcgprs.nr", FT_UINT16, BASE_DEC,
NULL, UI_MASK_NU, "Receive sequence number N(R)", HFILL }},
{ &hf_llcgprs_S_fmt,
{ "S format", "llcgprs.s", FT_UINT16, BASE_HEX,
NULL, 0xc000, "Supervisory format S", HFILL }},
{ &hf_llcgprs_kmask,
{ "ignored", "llcgprs.kmask", FT_UINT8, BASE_DEC,
NULL, 0xE0, NULL, HFILL }},
{ &hf_llcgprs_k,
{ "k", "llcgprs.k", FT_UINT8, BASE_DEC,
NULL, 0x1F, "k counter", HFILL }},
{ &hf_llcgprs_isack_ns,
{ "N(S)", "llcgprs.sackns", FT_UINT24, BASE_DEC,
NULL, 0x1FF000, NULL, HFILL }},
{ &hf_llcgprs_isack_nr,
{ "N(R)", "llcgprs.sacknr", FT_UINT24, BASE_DEC,
NULL, 0x0007FC, NULL, HFILL }},
{ &hf_llcgprs_isack_sfb,
{ "Supervisory function bits", "llcgprs.sacksfb", FT_UINT24, BASE_HEX,
VALS(cr_formats_ipluss), 0x000003, NULL, HFILL }},
{ &hf_llcgprs_ifmt,
{ "I Format", "llcgprs.ifmt", FT_UINT24, BASE_HEX,
NULL, 0x800000, "I Fmt Bit", HFILL }},
{ &hf_llcgprs_Ai,
{ "Ackn request bit", "llcgprs.ai", FT_BOOLEAN, 24,
TFS(&a_bit), 0x400000, "Acknowledgement request bit A", HFILL }},
{ &hf_llcgprs_izerobit,
{ "Spare", "llcgprs.iignore", FT_UINT24, BASE_DEC,
NULL, 0x200000, "Ignore Bit", HFILL }},
{ &hf_llcgprs_sspare,
{ "Spare", "llcgprs.sspare", FT_UINT16, BASE_DEC,
NULL, 0x1800, "Ignore Bit", HFILL }},
{ &hf_llcgprs_rbyte,
{ "R Bitmap Bits", "llcgprs.sackrbits", FT_UINT8, BASE_HEX,
NULL, 0xFF, "R Bitmap", HFILL }},
{ &hf_llcgprs_xid_xl,
{ "XL Bit", "llcgprs.xidxl", FT_UINT8, BASE_HEX,
NULL, 0x80, "XL", HFILL }},
{ &hf_llcgprs_xid_type,
{ "Type", "llcgprs.xidtype", FT_UINT8, BASE_DEC,
NULL, 0x7C, NULL, HFILL }},
{ &hf_llcgprs_xid_len1,
{ "Length", "llcgprs.xidlen1", FT_UINT8, BASE_DEC,
NULL, 0x03, NULL, HFILL }},
{ &hf_llcgprs_xid_len2,
{ "Length continued", "llcgprs.xidlen2", FT_UINT8, BASE_DEC,
NULL, 0xFC, NULL, HFILL }},
{ &hf_llcgprs_xid_spare,
{ "Spare", "llcgprs.xidspare", FT_UINT8, BASE_HEX,
NULL, 0x03, "Ignore", HFILL }},
{ &hf_llcgprs_xid_byte,
{ "Parameter Byte", "llcgprs.xidbyte", FT_UINT8, BASE_HEX,
NULL, 0xFF, "Data", HFILL }},
{ &hf_llcgprs_frmr_cf,
{ "Control Field Octet", "llcgprs.frmrrfcf", FT_UINT16, BASE_DEC,
NULL, 0xFFFF, "Rejected Frame CF", HFILL }},
{ &hf_llcgprs_frmr_spare,
{ "X", "llcgprs.frmrspare", FT_UINT32, BASE_HEX,
NULL, 0xF00400F0, "Filler", HFILL }},
{ &hf_llcgprs_frmr_vs,
{ "V(S)", "llcgprs.frmrvs", FT_UINT32, BASE_DEC,
NULL, 0x0FF80000, "Current send state variable", HFILL }},
{ &hf_llcgprs_frmr_vr,
{ "V(R)", "llcgprs.frmrvr", FT_UINT32, BASE_DEC,
NULL, 0x0003FE00, "Current receive state variable", HFILL }},
{ &hf_llcgprs_frmr_cr,
{ "C/R", "llcgprs.frmrcr", FT_UINT32, BASE_DEC,
NULL, 0x00000100, "Rejected command response", HFILL }},
{ &hf_llcgprs_frmr_w4,
{ "W4", "llcgprs.frmrw4", FT_UINT32, BASE_DEC,
NULL, 0x00000008, "LLE was in ABM when rejecting", HFILL }},
{ &hf_llcgprs_frmr_w3,
{ "W3", "llcgprs.frmrw3", FT_UINT32, BASE_DEC,
NULL, 0x00000004, "Undefined control field", HFILL }},
{ &hf_llcgprs_frmr_w2,
{ "W2", "llcgprs.frmrw2", FT_UINT32, BASE_DEC,
NULL, 0x00000002, "Info exceeded N201", HFILL }},
{ &hf_llcgprs_frmr_w1,
{ "W1", "llcgprs.frmrw1", FT_UINT32, BASE_DEC,
NULL, 0x00000001, "Invalid - info not permitted", HFILL }},
{ &hf_llcgprs_tom_rl,
{ "Remaining Length of TOM Protocol Header", "llcgprs.romrl", FT_UINT8, BASE_DEC,
NULL, 0xF0, "RL", HFILL }},
{ &hf_llcgprs_tom_pd,
{ "TOM Protocol Discriminator", "llcgprs.tompd", FT_UINT8, BASE_HEX,
NULL, 0x0F, "TPD", HFILL }},
{ &hf_llcgprs_tom_header,
{ "TOM Header Byte", "llcgprs.tomhead", FT_UINT8, BASE_HEX,
NULL, 0xFF, "thb", HFILL }},
{ &hf_llcgprs_tom_data,
{ "TOM Message Capsule Byte", "llcgprs.tomdata", FT_UINT8, BASE_HEX,
NULL, 0xFF, "tdb", HFILL }},
};
static gint *ett[] = {
&ett_llcgprs,
&ett_llcgprs_adf,
&ett_llcgprs_ctrlf,
&ett_llcgprs_ui,
&ett_llcgprs_sframe,
};
static ei_register_info ei[] = {
{ &ei_llcgprs_no_info_field, { "llcgprs.no_info_field", PI_PROTOCOL, PI_WARN, "No Information Field", EXPFILL }},
};
module_t *llcgprs_module;
expert_module_t* expert_llcgprs;
proto_llcgprs = proto_register_protocol("Logical Link Control GPRS",
"GPRS-LLC", "llcgprs");
llcgprs_subdissector_table = register_dissector_table("llcgprs.sapi", "GPRS LLC SAPI", proto_llcgprs, FT_UINT8, BASE_HEX);
proto_register_field_array(proto_llcgprs, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_llcgprs = expert_register_protocol(proto_llcgprs);
expert_register_field_array(expert_llcgprs, ei, array_length(ei));
register_dissector("llcgprs", dissect_llcgprs, proto_llcgprs);
llcgprs_module = prefs_register_protocol ( proto_llcgprs, NULL );
prefs_register_bool_preference ( llcgprs_module, "autodetect_cipher_bit",
"Autodetect cipher bit",
"Whether to autodetect the cipher bit (because it might be set on unciphered data)",
&ignore_cipher_bit );
}
void
proto_reg_handoff_llcgprs(void)
{
dissector_handle_t gprs_llc_handle;
gprs_llc_handle = find_dissector("llcgprs");
dissector_add_uint("wtap_encap", WTAP_ENCAP_GPRS_LLC, gprs_llc_handle);
sndcp_xid_handle = find_dissector_add_dependency("sndcpxid", proto_llcgprs);
}
