static guint16
de_gmm_add_upd_type(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset, bit_offset;
curr_offset = offset;
bit_offset = (curr_offset<<3)+4;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_tree_add_bits_item(tree, hf_gsm_a_gm_add_upd_type, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return (curr_offset - offset);
}
static guint16
de_gmm_attach_res(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_item(tree, hf_gsm_a_gm_fop, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gm_res_of_attach, tvb, offset, 1, ENC_BIG_ENDIAN);
return (1);
}
static guint16
de_gmm_attach_type(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_item(tree, hf_gsm_a_gm_for, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gm_type_of_attach, tvb, offset, 1, ENC_BIG_ENDIAN);
return (1);
}
static guint16
de_gmm_ciph_alg(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (offset << 3) + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gm_type_of_ciph_alg, tvb, offset, 1, ENC_BIG_ENDIAN);
return (1);
}
static guint16
de_gmm_tmsi_stat(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (offset << 3) + 4, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gm_tmsi_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
return (1);
}
static guint16
de_gmm_detach_type(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
if (pinfo->p2p_dir == P2P_DIR_RECV) {
proto_tree_add_item(tree, hf_gsm_a_gm_power_off, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gm_type_of_detach_mo, tvb, offset, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (offset << 3) + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gm_type_of_detach_mt, tvb, offset, 1, ENC_BIG_ENDIAN);
}
curr_offset++;
return (curr_offset - offset);
}
guint16
de_gmm_drx_param(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_gmm_split_pg_cycle_code, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_gsm_a_gmm_cn_spec_drx_cycle_len_coef, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gmm_split_on_ccch, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gmm_non_drx_timer, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return (curr_offset - offset);
}
static guint16
de_gmm_ftostby(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 bit_offset;
bit_offset = (offset << 3) + 4;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_gm_force_to_standby, tvb, bit_offset + 1, 3, ENC_BIG_ENDIAN);
return (1);
}
static guint16
de_gmm_ftostby_h(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 bit_offset;
bit_offset = offset << 3;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_gm_force_to_standby, tvb, bit_offset + 1, 3, ENC_BIG_ENDIAN);
return (1);
}
static guint16
de_gmm_ptmsi_sig(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
proto_item *curr_item;
curr_offset = offset;
curr_item= proto_tree_add_item(tree, hf_gsm_a_gmm_ptmsi_sig, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
proto_item_append_text(curr_item, "%s", add_string ? add_string : "");
curr_offset += 3;
return (curr_offset - offset);
}
static guint16
de_gmm_ptmsi_sig2(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string, int string_len _U_)
{
guint32 curr_offset;
proto_item *curr_item;
curr_offset = offset;
curr_item= proto_tree_add_item(tree, hf_gsm_a_gmm_ptmsi_sig2, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
proto_item_append_text(curr_item, "%s", add_string ? add_string : "");
curr_offset += 3;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_gm_extraneous_data);
return (curr_offset - offset);
}
static guint16
de_gmm_ident_type2(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (offset << 3) + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gm_type_of_identity, tvb, offset, 1, ENC_BIG_ENDIAN);
return (1);
}
static guint16
de_gmm_imeisv_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 bit_offset;
bit_offset = offset << 3;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_gm_imeisv_req, tvb, bit_offset + 1, 3, ENC_BIG_ENDIAN);
return (1);
}
static guint16
de_gmm_rec_npdu_lst(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint curr_len;
curr_len = len;
curr_offset = offset;
if (len == 0) return 0;
do
{
guint32 oct;
oct = tvb_get_guint8(tvb, curr_offset);
oct <<= 8;
oct |= tvb_get_guint8(tvb, curr_offset+1);
curr_len -= 2;
oct <<= 8;
proto_tree_add_uint_format(tree, hf_gsm_a_gm_nsapi, tvb, curr_offset, 2, (oct>>12)&0xff, "NSAPI %d: 0x%02x (%u)", oct>>20, (oct>>12)&0xff, (oct>>12)&0xff);
curr_offset += 2;
if (curr_len > 2)
{
oct |= tvb_get_guint8(tvb, curr_offset+2);
curr_len--;
oct <<= 12;
proto_tree_add_uint_format(tree, hf_gsm_a_gm_nsapi, tvb, curr_offset-1, 2, (oct>>12)&0xff, "NSAPI %d: 0x%02x (%u)", oct>>20, (oct>>12)&0xff, (oct>>12)&0xff);
curr_offset++;
}
} while (curr_len > 1);
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_gm_extraneous_data);
return (curr_offset - offset);
}
guint16
de_gmm_ms_net_cap(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
proto_tree *subtree;
proto_item *item;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_gmm_net_cap_gea1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gmm_net_cap_smdch, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gmm_net_cap_smgprs, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gmm_net_cap_ucs2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gmm_net_cap_ss_scr_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gmm_net_cap_solsa, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gmm_net_cap_rev, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_gsm_a_gmm_net_cap_pfc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
item = proto_tree_add_item(tree, hf_gsm_a_gmm_net_cap_ext_gea_bits, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
subtree = proto_item_add_subtree(item, ett_gmm_network_cap);
proto_tree_add_item(subtree, hf_gsm_a_gmm_net_cap_gea2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_gmm_net_cap_gea3, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_gmm_net_cap_gea4, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_gmm_net_cap_gea5, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_gmm_net_cap_gea6, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_gmm_net_cap_gea7, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gmm_net_cap_lcs, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_gsm_a_gmm_net_cap_ps_irat_iu, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gmm_net_cap_ps_irat_s1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gmm_net_cap_comb_proc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gmm_net_cap_isr, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gmm_net_cap_srvcc_to_geran, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gmm_net_cap_epc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gmm_net_cap_nf, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gmm_net_geran_net_sharing, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_gm_extraneous_data);
return (curr_offset - offset);
}
static void
gsm_a_gm_dlmc_max_nb_dl_ts_fmt(gchar *s, guint32 v)
{
if (v < 0x3E)
g_snprintf(s, ITEM_LABEL_LENGTH, "%u TS supported (%u)",
2*v + 6, v);
else
g_snprintf(s, ITEM_LABEL_LENGTH, "Reserved (%u)", v);
}
guint16
de_gmm_ms_radio_acc_cap(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint curr_len;
int bit_offset;
proto_item *tf = NULL, *mc_item = NULL, *ti;
proto_tree *tf_tree = NULL, *mc_tree = NULL;
guint32 oct;
guchar bits_in_oct;
guchar bits_needed;
guint bits_length;
guint add_octets;
guint curr_bits_length;
guchar acc_type;
guint value;
const gchar *str;
guint indx = 0;
guchar dtm_gprs_mslot = 0;
guchar dtm_egprs_mslot = 4;
gboolean finished = TRUE;
curr_len = len;
curr_offset = offset;
bit_offset = offset<<3;
bits_in_oct = 0;
oct = 0;
do
{
if ((curr_len*8 + bits_in_oct) < 11)
break;
curr_bits_length = 11;
if (curr_len != len)
{
bits_needed = 1;
GET_DATA;
if ((oct>>(32-bits_needed)) != 1)
{
break;
}
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bit_offset++;
if ((curr_len*8 + bits_in_oct) < 11)
break;
curr_bits_length = 11;
}
indx++;
tf_tree = proto_tree_add_subtree_format(tree,
tvb, curr_offset, 1,
ett_gmm_radio_cap, &tf, "MS RA capability %d", indx);
bits_needed = 4;
GET_DATA;
acc_type = oct>>(32-bits_needed);
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_acc_tech_type, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 7;
GET_DATA;
bits_length = curr_bits_length = oct>>(32-bits_needed);
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_acc_cap_struct_len, tvb, bit_offset, 7, ENC_BIG_ENDIAN);
proto_item_set_len(tf, (bits_length>>3)+1);
bit_offset += 7;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
if (acc_type == 0x0f)
{
do
{
finished = TRUE;
bits_needed = 1;
GET_DATA;
switch (oct>>(32-bits_needed))
{
case 0x00: str = "Not Present"; finished = TRUE; break;
case 0x01: str = "Present"; finished = FALSE; break;
default: str = "This should not happen";
}
proto_tree_add_uint_format_value(tf_tree, hf_gsm_a_gm_presence, tvb, curr_offset-1-add_octets, 1+add_octets, oct>>(32-bits_needed), "%s (%u)", str, oct>>(32-bits_needed));
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
if (finished)
{
while (curr_bits_length > 0)
{
if (curr_bits_length > 8)
bits_needed = 8;
else
bits_needed = curr_bits_length;
GET_DATA;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bit_offset += bits_needed;
}
continue;
}
bits_needed = 4;
GET_DATA;
acc_type = oct>>(32-bits_needed);
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_acc_tech_type, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 3;
GET_DATA;
value = tvb_get_bits8(tvb, bit_offset, 3);
if (acc_type == 0x04)
{
switch (value)
{
case 0x01: str = "1 W (30 dBm)"; break;
case 0x02: str = "0,25 W (24 dBm)"; break;
case 0x03: str = "2 W (33 dBm)"; break;
default: str = "Not specified";
}
}
else if (acc_type == 0x03)
{
switch (value)
{
case 0x01: str = "1 W (30 dBm)"; break;
case 0x02: str = "0,25 W (24 dBm)"; break;
case 0x03: str = "4 W (36 dBm)"; break;
default: str = "Not specified";
}
}
else if (acc_type <= 0x08)
{
switch (value)
{
case 0x02: str = "8 W (39 dBm)"; break;
case 0x03: str = "5 W (37 dBm)"; break;
case 0x04: str = "2 W (33 dBm)"; break;
case 0x05: str = "0,8 W (29 dBm)"; break;
default: str = "Not specified";
}
}
else
str = "Not specified??";
proto_tree_add_uint_format(tf_tree, hf_gsm_a_gm_rf_power_capability, tvb, curr_offset-1-add_octets, 1+add_octets, value,
"%s RF Power Capability, GMSK Power Class: %s (%u)", decode_bits_in_field(bit_offset, 3, value), str, value);
bit_offset += 3;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 2;
GET_DATA;
value = tvb_get_bits8(tvb, bit_offset, 2);
proto_tree_add_uint(tf_tree, hf_gsm_a_gm_8psk_power_class, tvb, curr_offset-1-add_octets, 1+add_octets, value);
bit_offset += 2;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
} while (!finished);
continue;
}
bits_needed = 3;
GET_DATA;
value = tvb_get_bits8(tvb, bit_offset, 3);
if (acc_type == 0x04)
{
switch (value)
{
case 0x01: str = "1 W (30 dBm)"; break;
case 0x02: str = "0,25 W (24 dBm)"; break;
case 0x03: str = "2 W (33 dBm)"; break;
default: str = "Not specified";
}
}
else if (acc_type == 0x03)
{
switch (value)
{
case 0x01: str = "1 W (30 dBm)"; break;
case 0x02: str = "0,25 W (24 dBm)"; break;
case 0x03: str = "4 W (36 dBm)"; break;
default: str = "Not specified";
}
}
else if (acc_type <= 0x08)
{
switch (value)
{
case 0x02: str = "8 W (39 dBm)"; break;
case 0x03: str = "5 W (37 dBm)"; break;
case 0x04: str = "2 W (33 dBm)"; break;
case 0x05: str = "0,8 W (29 dBm)"; break;
default: str = "Not specified";
}
}
else
str = "Not specified??";
proto_tree_add_uint_format(tf_tree, hf_gsm_a_gm_rf_power_capability, tvb, curr_offset-1-add_octets, 1+add_octets, value,
"%s RF Power Capability, GMSK Power Class: %s (%u)", decode_bits_in_field(bit_offset, 3, value), str, value);
bit_offset += 3;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
if ((oct>>(32-bits_needed)) == 0)
{
proto_tree_add_uint_format_value(tf_tree, hf_gsm_a_gm_a5_bits, tvb, curr_offset-1-add_octets, 1+add_octets, oct>>(32-bits_needed),
"Same values apply for parameters as in the immediately preceding Access capabilities field within this IE (%u)",
oct>>(32-bits_needed));
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
else
{
int i;
proto_tree_add_uint_format_value(tf_tree, hf_gsm_a_gm_a5_bits, tvb, curr_offset-1-add_octets, 1+add_octets, oct>>(32-bits_needed), "A5 bits follow (%u)", oct>>(32-bits_needed));
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
for (i=1; i<=7 ; i++)
{
bits_needed = 1;
GET_DATA;
switch (oct>>(32-bits_needed))
{
case 0x00: str = "encryption algorithm not available"; break;
case 0x01: str = "encryption algorithm available"; break;
default: str = "This should not happen";
}
proto_tree_add_uint_format(tf_tree, hf_gsm_a_gm_a5_bits, tvb, curr_offset-1-add_octets, 1+add_octets, oct>>(32-bits_needed), "A5/%d: %s (%u)", i, str, oct>>(32-bits_needed));
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
}
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_ctrled_early_cm_sending, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_pseudo_sync, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_vgcs, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_vbs, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
value = oct>>(32-bits_needed);
mc_item = proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_multislot_capability, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
if (value == 1)
{
mc_tree = proto_item_add_subtree(mc_item, ett_gsm_a_gm_msrac_multislot_capability);
bits_needed = 1;
GET_DATA;
if ((oct>>(32-bits_needed)) == 0)
{
proto_tree_add_uint_format_value(mc_tree, hf_gsm_a_gm_rac_hscsd_multi_slot_class, tvb, curr_offset-1-add_octets, 1+add_octets, 0xFF,
"Bits are not available (%u)", oct>>(32-bits_needed));
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
else
{
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bit_offset++;
bits_needed = 5;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_hscsd_multi_slot_class, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
bit_offset += 5;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
bits_needed = 1;
GET_DATA;
if ((oct>>(32-bits_needed)) == 0)
{
proto_tree_add_uint_format_value(mc_tree, hf_gsm_a_gm_rac_gprs_multi_slot_class, tvb, curr_offset-1-add_octets, 1+add_octets, 0xFF,
"Bits are not available (%u)", oct>>(32-bits_needed));
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
else
{
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bit_offset++;
bits_needed = 5;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_gprs_multi_slot_class, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
bit_offset += 5;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_gprs_ext_dyn_alloc_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
bits_needed = 1;
GET_DATA;
if ((oct>>(32-bits_needed)) == 0)
{
proto_tree_add_uint_format_value(mc_tree, hf_gsm_a_gm_sms_value, tvb, curr_offset-1-add_octets, 1+add_octets, 0xFF,
"Bits are not available (%u)", oct>>(32-bits_needed));
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
else
{
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bit_offset++;
bits_needed = 4;
GET_DATA;
proto_tree_add_bits_item(mc_tree, hf_gsm_a_gm_sms_value, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 4;
GET_DATA;
proto_tree_add_bits_item(mc_tree, hf_gsm_a_gm_sm_value, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
bits_needed = 1;
GET_DATA;
if ((oct>>(32-bits_needed)) == 0)
{
proto_tree_add_uint_format_value(mc_tree, hf_gsm_a_gm_rac_ecsd_multi_slot_class, tvb, curr_offset-1-add_octets, 1+add_octets, 0xFF,
"Bits are not available (%u)", oct>>(32-bits_needed));
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
else
{
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bit_offset++;
bits_needed = 5;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_ecsd_multi_slot_class, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
bit_offset += 5;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
bits_needed = 1;
GET_DATA;
if ((oct>>(32-bits_needed)) == 0)
{
proto_tree_add_uint_format_value(mc_tree, hf_gsm_a_gm_rac_egprs_multi_slot_class, tvb, curr_offset-1-add_octets, 1+add_octets, 0xFF,
"Bits are not available (%u)", oct>>(32-bits_needed));
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bit_offset++;
}
else
{
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bit_offset++;
bits_needed = 5;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_egprs_multi_slot_class, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
bit_offset += 5;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_egprs_ext_dyn_alloc_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
bits_needed = 1;
GET_DATA;
if ((oct>>(32-bits_needed)) == 0)
{
proto_tree_add_uint_format_value(mc_tree, hf_gsm_a_gm_rac_dtm_gprs_multi_slot_class, tvb, curr_offset-1-add_octets, 1+add_octets, 0xFF,
"Bits are not available (%u)", oct>>(32-bits_needed));
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
else
{
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bit_offset++;
bits_needed = 2;
GET_DATA;
dtm_gprs_mslot = oct>>(32-bits_needed);
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_dtm_gprs_multi_slot_class, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(mc_tree, hf_gsm_a_gm_rac_single_slt_dtm, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
dtm_egprs_mslot = oct>>(32-bits_needed);
proto_tree_add_bits_item(mc_tree, hf_gsm_a_gm_rac_dtm_egprs_multi_slot_cls_pres, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
if ((oct>>(32-bits_needed)) == 1)
{
bits_needed = 2;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_dtm_egprs_multi_slot_class, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
}
}
bits_needed = 1;
GET_DATA;
value = oct>>(32-bits_needed);
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_8psk_pow_cap_pres, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
if (value == 1)
{
bits_needed = 2;
GET_DATA;
proto_tree_add_uint(tf_tree, hf_gsm_a_gm_8psk_power_capability, tvb, curr_offset-1-add_octets, 1+add_octets, oct>>(32-bits_needed));
bit_offset += 2;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_comp_int_meas_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rel_lev_ind, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_umts_fdd_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_umts_384_tdd_ra_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_cdma2000_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_umts_128_tdd_ra_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_geran_feat_pkg, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
if ((oct>>(32-bits_needed)) == 0)
{
proto_tree_add_uint_format_value(tf_tree, hf_gsm_a_gm_extended_dtm_egprs_multi_slot_class, tvb, curr_offset-1-add_octets, 1+add_octets, 0xFF, "Bits are not available (%u)", oct>>(32-bits_needed));
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bit_offset++;
}
else
{
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bit_offset++;
bits_needed = 2;
GET_DATA;
proto_tree_add_uint(tf_tree, hf_gsm_a_gm_extended_dtm_gprs_multi_slot_class, tvb, curr_offset-1-add_octets, 1+add_octets, (oct>>(32-bits_needed))|(dtm_gprs_mslot<<4));
bit_offset += 2;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
if (dtm_egprs_mslot <= 3)
{
bits_needed = 2;
GET_DATA;
proto_tree_add_uint(tf_tree, hf_gsm_a_gm_extended_dtm_egprs_multi_slot_class, tvb, curr_offset-1-add_octets, 1+add_octets, (oct>>(32-bits_needed))|(dtm_egprs_mslot<<4));
bit_offset += 2;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
}
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_mod_based_multi_slot_class_support, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
if ((oct>>(32-bits_needed)) == 0)
{
proto_tree_add_uint_format_value(tf_tree, hf_gsm_a_gm_high_multislot_capability, tvb, curr_offset-1-add_octets, 1+add_octets, 0xFF, "Bits are not available (%u)", oct>>(32-bits_needed));
bit_offset++;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
else
{
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bit_offset++;
bits_needed = 2;
GET_DATA;
ti = proto_tree_add_uint(tf_tree, hf_gsm_a_gm_high_multislot_capability, tvb, curr_offset-1-add_octets, 1+add_octets, oct>>(32-bits_needed));
proto_item_append_text(ti, " - This field effect all other multislot fields."
" To understand the value please read TS 24.008 5.6.0"
" Release 5 Chap 10.5.5.12 Page 406");
bit_offset += 2;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
bits_needed = 1;
GET_DATA;
value = tvb_get_bits8(tvb, bit_offset, 1);
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_geran_iu_mode_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
if (value)
{
bits_needed = 4;
GET_DATA;
value = tvb_get_bits8(tvb, bit_offset, 4);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
if (value)
{
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_flo_iu_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
value--;
bit_offset += value;
curr_bits_length -= value;
oct <<= value;
bits_in_oct -= value;
}
}
bits_needed = 2;
GET_DATA;
proto_tree_add_uint(tf_tree, hf_gsm_a_gm_gmsk_multislot_power_profile, tvb, curr_offset-1-add_octets, 1+add_octets, oct>>(32-bits_needed));
bit_offset += 2;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 2;
GET_DATA;
proto_tree_add_uint(tf_tree, hf_gsm_a_gm_8psk_multislot_power_profile, tvb, curr_offset-1-add_octets, 1+add_octets, oct>>(32-bits_needed));
bit_offset += 2;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_mult_tbf_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 2;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_down_adv_rec_perf, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_ext_rlc_mac_ctrl_msg_seg_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_dtm_enh_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
if ((oct>>(32-bits_needed)) == 0)
{
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
else
{
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 3;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_dtm_gprs_high_multi_slot_class, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
if ((oct>>(32-bits_needed)) == 0)
{
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
else
{
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 3;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_dtm_egprs_high_multi_slot_class, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
}
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_ps_ho_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_dtm_ho_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
if ((oct>>(32-bits_needed)) == 0)
{
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
else
{
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 3;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_multi_slot_cap_red_down_dual_carrier, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_down_dual_carrier_dtm_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_flex_ts_assign, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_gan_ps_ho_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_rlc_non_pers_mode, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_reduced_lat_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 2;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_ul_egprs2, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 2;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_dl_egprs2, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_eutra_fdd_support, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_eutra_tdd_support, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 2;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_geran_to_eutra_support_in_geran_ptm, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_prio_based_resel_support, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
if ((oct>>(32-bits_needed)) == 0)
{
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
else
{
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 4;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_alt_efta_multi_slot_class, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 3;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_efta_multi_slot_cap_red_down_dual_carrier, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_ind_up_layer_pdu_start_cap_for_rlc_um, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_emst_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_mtti_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_utra_csg_cell_report, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_eutra_csg_cell_report, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_dtr_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_emsr_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_fast_down_freq_switch_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 2;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_tighter_cap, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_fanr_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_ipa_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_geran_nw_sharing_support, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_eutra_wb_rsrq_support, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_utra_mfbi_support, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_eutra_mfbi_support, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
if ((oct>>(32-bits_needed)) == 0)
{
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
else
{
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
if ((oct>>(32-bits_needed)) == 0)
{
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
else
{
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 2;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_dlmc_non_contig_intra_band_recep, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_dlmc_inter_band_recep, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
bits_needed = 2;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_dlmc_max_bandwidth, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 6;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_dlmc_max_nb_dl_ts, tvb, bit_offset, 6, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 3;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_dlmc_max_nb_dl_carriers, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_ext_tsc_set_cap_support, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
bits_needed = 1;
GET_DATA;
proto_tree_add_bits_item(tf_tree, hf_gsm_a_gm_rac_ext_earfcn_value_range, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += bits_needed;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
while (curr_bits_length > 0)
{
if (curr_bits_length > 8)
bits_needed = 8;
else
bits_needed = curr_bits_length;
GET_DATA;
curr_bits_length -= bits_needed;
oct <<= bits_needed;
bits_in_oct -= bits_needed;
}
} while (1);
curr_offset += curr_len;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_gm_extraneous_data);
return (curr_offset - offset);
}
static guint16
de_gmm_cause(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_gm_cause, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return (curr_offset - offset);
}
guint16
de_gmm_rai(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree *subtree;
guint32 mcc;
guint32 mnc;
guint32 lac;
guint32 rac;
guint32 curr_offset;
curr_offset = offset;
mcc = (tvb_get_guint8(tvb, curr_offset) & 0x0f) <<8;
mcc |= (tvb_get_guint8(tvb, curr_offset) & 0xf0);
mcc |= (tvb_get_guint8(tvb, curr_offset+1) & 0x0f);
mnc = (tvb_get_guint8(tvb, curr_offset+2) & 0x0f) <<8;
mnc |= (tvb_get_guint8(tvb, curr_offset+2) & 0xf0);
mnc |= (tvb_get_guint8(tvb, curr_offset+1) & 0xf0) >>4;
if ((mnc&0x000f) == 0x000f)
mnc = mnc>>4;
lac = tvb_get_ntohs(tvb, curr_offset+3);
rac = tvb_get_guint8(tvb, curr_offset+5);
subtree = proto_tree_add_subtree_format(tree,
tvb, curr_offset, 6, ett_gmm_rai, NULL,
"Routing area identification: %x-%x-%u-%u",
mcc, mnc, lac, rac);
dissect_e212_mcc_mnc(tvb, pinfo, subtree, offset, E212_RAI, TRUE);
proto_tree_add_item(subtree, hf_gsm_a_lac, tvb, curr_offset+3, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_gm_rac, tvb, curr_offset+5, 1, ENC_BIG_ENDIAN);
curr_offset += 6;
if (add_string)
{
if (add_string[0] == '\0')
{
g_snprintf(add_string, string_len, " - RAI: %x-%x-%u-%u", mcc, mnc, lac, rac);
}
}
return (curr_offset - offset);
}
static guint16
de_gmm_rai2(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
return de_gmm_rai(tvb, tree, pinfo, offset, len, add_string, string_len);
}
static guint16
de_gmm_update_res(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_gm_update_result, tvb, curr_offset, 1, ENC_NA);
curr_offset++;
return (curr_offset - offset);
}
static guint16
de_gmm_update_type(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_item(tree, hf_gsm_a_gm_for, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gm_update_type, tvb, offset, 1, ENC_BIG_ENDIAN);
return (1);
}
static guint16
de_gmm_ac_ref_nr(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_bits_item(tree, hf_gsm_a_gm_ac_ref_nr, tvb, (offset << 3) + 4, 4, ENC_BIG_ENDIAN);
return (1);
}
static guint16
de_gmm_ac_ref_nr_h(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_bits_item(tree, hf_gsm_a_gm_ac_ref_nr, tvb, offset << 3, 4, ENC_BIG_ENDIAN);
return (1);
}
static guint16
de_gmm_service_type(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 bit_offset;
bit_offset = offset << 3;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_gsm_a_gm_serv_type, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
return (1);
}
static guint16
de_gmm_ps_lcs_cap(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, curr_offset << 3, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gm_apc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gm_otd_a, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gm_otd_b, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gm_gps_a, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gm_gps_b, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gm_gps_c, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_gm_extraneous_data);
return (curr_offset - offset);
}
static guint16
de_gmm_net_feat_supp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_gm_lcs_molr, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gm_mbms, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gm_ims_vops, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gm_emc_bs, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return (curr_offset - offset);
}
static guint16
de_gmm_add_net_feat_supp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, curr_offset << 3, 7, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_gm_gprs_sms, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return (curr_offset - offset);
}
static guint16
de_gmm_rat_info_container(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
tvbuff_t *rrc_irat_ho_info_tvb;
curr_offset = offset;
rrc_irat_ho_info_tvb = tvb_new_subset_length(tvb, curr_offset, len);
if (rrc_irat_ho_info_handle)
call_dissector(rrc_irat_ho_info_handle, rrc_irat_ho_info_tvb, pinfo, tree);
else
proto_tree_add_expert_format(tree, pinfo, &ei_gsm_a_gm_undecoded, tvb, curr_offset, len, "INTER RAT HANDOVER INFO - Not decoded");
return len;
}
static guint16
de_gmm_req_ms_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint32 bit_offset;
curr_offset = offset;
bit_offset = (curr_offset<<3)+4;
proto_tree_add_bits_item(tree, hf_gsm_a_gm_req_ms_info_irat, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_gsm_a_gm_req_ms_info_irat2, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
return len;
}
static guint16
de_gmm_eutran_irat_info_container(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
tvbuff_t *lte_rrc_ue_eutra_cap_tvb;
curr_offset = offset;
lte_rrc_ue_eutra_cap_tvb = tvb_new_subset_length(tvb, curr_offset, len);
if (lte_rrc_ue_eutra_cap_handle)
call_dissector(lte_rrc_ue_eutra_cap_handle, lte_rrc_ue_eutra_cap_tvb, pinfo, tree);
else
proto_tree_add_expert_format(tree, pinfo, &ei_gsm_a_gm_undecoded, tvb, curr_offset, len, "E-UTRAN Inter RAT information container - Not decoded");
return len;
}
guint16
de_gmm_voice_domain_pref(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint32 bit_offset;
curr_offset = offset;
bit_offset = curr_offset<<3;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
bit_offset += 5;
proto_tree_add_bits_item(tree, hf_gsm_a_gm_ue_usage_setting, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_gsm_a_gm_voice_domain_pref_for_eutran, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
return len;
}
static guint16
de_gmm_ptmsi_type(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset, bit_offset;
curr_offset = offset;
bit_offset = (curr_offset<<3)+4;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_tree_add_bits_item(tree, hf_gsm_a_gm_ptmsi_type, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return (curr_offset - offset);
}
static guint16
de_gmm_lai_2(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string, int string_len)
{
return de_lai(tvb, tree, pinfo, offset, len, add_string, string_len);
}
static guint16
de_gmm_net_res_id_cont(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint32 bit_offset;
curr_offset = offset;
bit_offset = curr_offset<<3;
proto_tree_add_item(tree, hf_gsm_a_gm_nri_cont, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 10;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, bit_offset, 6, ENC_BIG_ENDIAN);
return len;
}
static guint16
de_gc_context_stat(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint8 oct;
guint16 pdp_nr;
guint32 curr_offset;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
for (pdp_nr=0; pdp_nr<16; pdp_nr++)
{
if (pdp_nr == 8)
{
curr_offset++;
oct = tvb_get_guint8(tvb, curr_offset);
}
proto_tree_add_uint_format(tree, hf_gsm_a_gm_nsapi, tvb, curr_offset, 1, oct&1, "NSAPI %d: %s (%u)", pdp_nr, pdp_str[oct&1], oct&1);
oct>>=1;
}
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_gm_extraneous_data);
return (curr_offset - offset);
}
static guint16
de_gc_radio_prio(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_gm_radio_priority_pdp, tvb, curr_offset, 1, ENC_NA);
curr_offset++;
return (curr_offset - offset);
}
static guint16
de_gc_timer(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint8 oct;
guint16 val;
const gchar *str;
proto_item *item = NULL;
proto_tree *subtree;
oct = tvb_get_guint8(tvb, offset);
val = oct&0x1f;
switch (oct>>5)
{
case 0:
str = "sec"; val*=2;
break;
case 1:
str = "min";
break;
case 2:
str = "min"; val*=6;
break;
case 7:
str = "";
item = proto_tree_add_uint_format_value(tree, hf_gsm_a_gm_gprs_timer, tvb, offset, 1, val, "timer is deactivated");
break;
default: str = "min";
}
if (item == NULL) {
item = proto_tree_add_uint_format_value(tree, hf_gsm_a_gm_gprs_timer, tvb, offset, 1, val, "%u %s", val, str);
}
subtree = proto_item_add_subtree(item, ett_gmm_gprs_timer);
proto_tree_add_item(subtree, hf_gsm_a_gm_gprs_timer_unit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_gm_gprs_timer_value, tvb, offset, 1, ENC_BIG_ENDIAN);
return (1);
}
static guint16
de_gc_timer2(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string, int string_len _U_)
{
guint8 oct;
guint16 val;
guint32 curr_offset;
const gchar *str = NULL;
proto_tree *subtree;
proto_item *item = NULL;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
val = oct&0x1f;
switch (oct>>5)
{
case 0:
str = "sec"; val*=2;
break;
case 1:
str = "min";
break;
case 2:
str = "min"; val*=6;
break;
case 7:
item = proto_tree_add_uint_format_value(tree, hf_gsm_a_gm_gprs_timer2, tvb, curr_offset, 1, val, "timer is deactivated");
break;
default: str = "min";
}
if (item == NULL) {
item = proto_tree_add_uint_format_value(tree, hf_gsm_a_gm_gprs_timer2, tvb, curr_offset, 1, val, "%u %s %s", val, str, add_string ? add_string : "");
}
subtree = proto_item_add_subtree(item, ett_gmm_gprs_timer);
proto_tree_add_item(subtree, hf_gsm_a_gm_gprs_timer2_unit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_gm_gprs_timer2_value, tvb, offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return (curr_offset - offset);
}
static guint16
de_gc_timer3(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint8 oct;
guint16 val;
guint32 curr_offset;
const gchar *str = NULL;
proto_tree *subtree;
proto_item *item = NULL;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
val = oct&0x1f;
switch (oct>>5)
{
case 0: str = "min"; val*=10; break;
case 1: str = "hr"; break;
case 2: str = "hr"; val*=10; break;
case 3: str = "sec"; val*=2; break;
case 4: str = "sec"; val*=30; break;
case 5: str = "min"; break;
case 7:
item = proto_tree_add_uint_format_value(tree, hf_gsm_a_gm_gprs_timer3, tvb, curr_offset, 1, val, "timer is deactivated");
break;
default: str = "hr";
}
if (item == NULL) {
item = proto_tree_add_uint_format_value(tree, hf_gsm_a_gm_gprs_timer3, tvb, curr_offset, 1, val, "%u %s", val, str);
}
subtree = proto_item_add_subtree(item, ett_gmm_gprs_timer);
proto_tree_add_item(subtree, hf_gsm_a_gm_gprs_timer3_unit, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_gm_gprs_timer3_value, tvb, offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return (curr_offset - offset);
}
static guint16
de_gc_radio_prio2(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_gm_radio_priority_tom8, tvb, curr_offset, 1, ENC_NA);
curr_offset++;
return (curr_offset - offset);
}
static guint16
de_gc_mbms_context_stat(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint i;
guint8 oct, j;
curr_offset = offset;
for (i=0; i<len; i++)
{
oct = tvb_get_guint8(tvb, curr_offset);
for (j=0; j<8; j++)
{
proto_tree_add_uint_format(tree, hf_gsm_a_gm_nsapi, tvb, curr_offset, 1, oct&1, "NSAPI %d: %s (%u)", 128+i*8+j, pdp_str[oct&1], oct&1);
oct>>=1;
}
curr_offset++;
}
return (len);
}
static guint16
de_gc_uplink_data_stat(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint32 bit_offset;
curr_offset = offset;
bit_offset = curr_offset<<3;
proto_tree_add_bits_item(tree, hf_gsm_a_gm_nsapi_7_ul_stat, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_gsm_a_gm_nsapi_6_ul_stat, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_gsm_a_gm_nsapi_5_ul_stat, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
bit_offset += 5;
curr_offset++;
proto_tree_add_bits_item(tree, hf_gsm_a_gm_nsapi_15_ul_stat, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_gsm_a_gm_nsapi_14_ul_stat, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_gsm_a_gm_nsapi_13_ul_stat, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_gsm_a_gm_nsapi_12_ul_stat, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_gsm_a_gm_nsapi_11_ul_stat, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_gsm_a_gm_nsapi_10_ul_stat, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_gsm_a_gm_nsapi_9_ul_stat, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset++;
proto_tree_add_bits_item(tree, hf_gsm_a_gm_nsapi_8_ul_stat, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
return (len);
}
static guint16
de_gc_device_properties(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint32 bit_offset;
curr_offset = offset;
bit_offset = (curr_offset<<3)+4;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_tree_add_bits_item(tree, hf_gsm_a_gm_device_prop_low_prio, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return (curr_offset - offset);
}
guint16
de_sm_apn(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint curr_len;
guint8 str[MAX_APN_LENGTH+1];
curr_offset = offset;
memset(str, 0, MAX_APN_LENGTH+1);
tvb_memcpy(tvb, str, offset, len<MAX_APN_LENGTH?len:MAX_APN_LENGTH);
curr_len = 0;
while ((curr_len < len) && (curr_len < MAX_APN_LENGTH))
{
guint step = str[curr_len];
str[curr_len] = '.';
curr_len += step+1;
}
proto_tree_add_string(tree, hf_gsm_a_gm_apn, tvb, curr_offset, len, str+1);
curr_offset += len;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_gm_extraneous_data);
return (curr_offset - offset);
}
static guint16
de_sm_nsapi(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string, int string_len _U_)
{
guint8 oct;
guint32 curr_offset;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_uint_format_value(tree, hf_gsm_a_gm_nsapi, tvb, curr_offset, 1, oct&0x0f, "0x%02x (%u) %s", oct&0x0f, oct&0x0f, add_string ? add_string : "");
curr_offset++;
return (curr_offset - offset);
}
guint16
de_sm_pco(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
proto_item *generated_item;
guint32 curr_offset;
guint curr_len;
guchar oct;
int link_dir;
proto_item *pco_item;
proto_tree *pco_tree;
curr_len = len;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
link_dir = pinfo->link_dir;
generated_item = proto_tree_add_int(tree, hf_gsm_a_gm_link_dir, tvb, curr_offset, 0, link_dir);
PROTO_ITEM_SET_GENERATED(generated_item);
proto_tree_add_item(tree, hf_gsm_a_sm_ext, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_uint_format_value(tree, hf_gsm_a_gm_configuration_protocol, tvb, curr_offset, 1, oct&0x07, "PPP for use with IP PDP type or IP PDN type (%u)", oct&0x07);
curr_len--;
curr_offset++;
while (curr_len > 0)
{
guchar e_len;
guint16 prot;
tvbuff_t *l3_tvb;
prot = tvb_get_ntohs(tvb, curr_offset);
pco_item = proto_tree_add_uint_format_value(tree, hf_gsm_a_gm_pco_pid, tvb, curr_offset, 2, (guint32)prot,
"%s (0x%04x)",
link_dir ?
rval_to_str_const((guint32)prot, gsm_a_sm_pco_net2ms_prot_vals, val_to_str_ext_const(prot, &ppp_vals_ext, "Unknown")) :
rval_to_str_const((guint32)prot, gsm_a_sm_pco_ms2net_prot_vals, val_to_str_ext_const(prot, &ppp_vals_ext, "Unknown")),
(guint32)prot);
pco_tree = proto_item_add_subtree(pco_item, ett_sm_pco);
curr_len -= 2;
curr_offset += 2;
e_len = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(pco_tree, hf_gsm_a_gm_sm_pco_length, tvb, curr_offset, 1, ENC_NA);
curr_len -= 1;
curr_offset += 1;
switch (prot)
{
case 0x0001:
case 0x0003:
case 0x0007:
if ((link_dir == P2P_DIR_DL) && (e_len > 0)) {
proto_tree_add_item(pco_tree, hf_gsm_a_gm_sm_pco_ipv6, tvb, curr_offset, 16, ENC_NA);
}
break;
case 0x0002:
case 0x0006:
case 0x000A:
case 0x000B:
case 0x000F:
case 0x0011:
break;
case 0x0004:
if ((link_dir == P2P_DIR_DL) && (e_len == 1)) {
proto_tree_add_item(pco_tree, hf_gsm_a_gm_sm_pco_reject_code, tvb, curr_offset, 1, ENC_NA);
}
break;
case 0x0005:
if ((link_dir == P2P_DIR_DL) && (e_len == 1)) {
proto_tree_add_item(pco_tree, hf_gsm_a_gm_sm_pco_sel_bearer_ctrl_mode, tvb, curr_offset, 1, ENC_NA);
}
break;
case 0x0008:
if ((link_dir == P2P_DIR_DL) && (e_len > 0)) {
proto_tree_add_item(pco_tree, hf_gsm_a_gm_sm_pco_ipv6, tvb, curr_offset, 16, ENC_NA);
proto_tree_add_item(pco_tree, hf_gsm_a_gm_sm_pco_prefix_length, tvb, curr_offset+16, 1, ENC_NA);
}
break;
case 0x0009:
case 0x000C:
case 0x000D:
if ((link_dir == P2P_DIR_DL) && (e_len > 0)) {
proto_tree_add_item(pco_tree, hf_gsm_a_gm_sm_pco_ipv4, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
}
break;
case 0x000E:
if ((link_dir == P2P_DIR_DL) && (e_len > 0)) {
l3_tvb = tvb_new_subset_length(tvb, curr_offset, e_len);
dissect_gsm_map_msisdn(l3_tvb, pinfo, pco_tree);
}
break;
case 0x0010:
if ((link_dir == P2P_DIR_DL) && (e_len == 2)) {
guint16 word = tvb_get_ntohs(tvb, curr_offset);
proto_tree_add_uint_format_value(pco_tree, hf_gsm_a_gm_sm_pco_ipv4_link_mtu_size, tvb, curr_offset, 2, word, "%u octets", word);
}
break;
default:
{
if (e_len > 0) {
if (prot >= 0xff00) {
dissect_e212_mcc_mnc(tvb, pinfo, pco_tree, curr_offset, E212_NONE, TRUE);
if ((e_len - 3) > 0) {
proto_tree_add_item(pco_tree, hf_gsm_a_gm_pco_app_spec_info, tvb, curr_offset+3, e_len-3, ENC_NA);
}
} else {
dissector_handle_t handle;
handle = dissector_get_uint_handle (gprs_sm_pco_subdissector_table, prot);
l3_tvb = tvb_new_subset_length(tvb, curr_offset, e_len);
if (handle != NULL)
{
col_set_writable(pinfo->cinfo, FALSE);
call_dissector(handle, l3_tvb, pinfo, pco_tree);
col_set_writable(pinfo->cinfo, TRUE);
}
else
{
call_dissector(data_handle, l3_tvb, pinfo, pco_tree);
}
}
}
}
}
curr_len -= e_len;
curr_offset += e_len;
}
curr_offset += curr_len;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_gm_extraneous_data);
return (curr_offset - offset);
}
static guint16
de_sm_pdp_addr(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
const gchar *str;
guchar pdp_type_org, pdp_type_num;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset << 3), 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_sm_pdp_type_org, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
pdp_type_org = tvb_get_guint8(tvb, curr_offset) & 0x0f;
curr_offset += 1;
pdp_type_num = tvb_get_guint8(tvb, curr_offset);
if (pdp_type_org == 0)
{
switch (pdp_type_num)
{
case 0x00: str = "Reserved, used in earlier version of this protocol"; break;
case 0x01: str = "PDP-type PPP"; break;
default: str = "reserved";
}
}
else if (pdp_type_org == 1)
{
switch (pdp_type_num)
{
case 0x21: str = "IPv4 address"; break;
case 0x57: str = "IPv6 address"; break;
case 0x8d: str = "IPv4v6 address"; break;
default: str = "Unknown, interpreted as IPv4 address";
}
}
else if ((pdp_type_num == 0) && (pdp_type_org == 0x0f))
str = "Empty";
else
str = "Not specified";
proto_tree_add_uint_format_value(tree, hf_gsm_a_sm_pdp_type_number, tvb, curr_offset, 1, pdp_type_num, "%s (%u)", str, pdp_type_num);
if ((len == 2) && ((pdp_type_num == 0x21) || (pdp_type_num == 0x57) || (pdp_type_num == 0x8d)))
{
proto_tree_add_uint_format(tree, hf_gsm_a_sm_pdp_address, tvb, curr_offset, 1, pdp_type_num, "Dynamic addressing");
curr_offset += 1;
return (curr_offset - offset);
}
else if (len == 2)
{
proto_tree_add_uint_format(tree, hf_gsm_a_sm_pdp_address, tvb, curr_offset, 1, 0, "No PDP address is included");
curr_offset += 1;
return (curr_offset - offset);
}
curr_offset += 1;
if (pdp_type_org == 1)
switch (pdp_type_num)
{
case 0x57:
proto_tree_add_item(tree, hf_gsm_a_sm_ip6_address, tvb, curr_offset, 16, ENC_NA);
curr_offset += 16;
break;
case 0x8d:
proto_tree_add_item(tree, hf_gsm_a_sm_ip4_address, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
curr_offset += 4;
proto_tree_add_item(tree, hf_gsm_a_sm_ip6_address, tvb, curr_offset, 16, ENC_NA);
curr_offset += 16;
break;
default:
proto_tree_add_item(tree, hf_gsm_a_sm_ip4_address, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
curr_offset += 4;
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_gm_extraneous_data);
return (curr_offset - offset);
}
static guint32
qos_calc_bitrate(guint8 oct)
{
if (oct <= 0x3f)
return oct;
if (oct <= 0x7f)
return 64 + (oct-0x40) * 8;
return 576 + (oct-0x80) * 64;
}
static guint32
qos_calc_ext_bitrate(guint8 oct)
{
if (oct <= 0x4a)
return 8600 + oct * 100;
if (oct <= 0xba)
return 16000 + (oct-0x4a) * 1000;
return 128000 + (oct - 0xba) * 2000;
}
static guint32
qos_calc_ext2_bitrate(guint8 oct)
{
if (oct <= 0x3d)
return (256 + oct * 4);
if (oct <= 0xa1)
return (500 + (oct-0x3d) * 10);
if (oct <= 0xf6)
return (1500 + (oct-0xa1) * 100);
return 10000;
}
guint16
de_sm_qos(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guchar oct, tmp_oct;
const gchar *str;
guint32 temp32;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset << 3), 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_sm_qos_delay_cls, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_sm_qos_reliability_cls, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
proto_tree_add_item(tree, hf_gsm_a_sm_qos_peak_thr, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset << 3) + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_sm_qos_prec_class, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset << 3), 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_sm_qos_mean_thr, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_gsm_a_sm_qos_traffic_cls, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_sm_qos_del_order, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_sm_qos_del_of_err_sdu, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
NO_MORE_DATA_CHECK(len);
oct = tvb_get_guint8(tvb, curr_offset);
switch (oct)
{
case 0x00: str = "Subscribed maximum SDU size/reserved"; break;
case 0x97: str = "1502 octets"; break;
case 0x98: str = "1510 octets"; break;
case 0x99: str = "1520 octets"; break;
case 0xff: str = "Reserved"; break;
default: str = "Unspecified";
}
if ((oct >= 1) && (oct <= 0x96))
proto_tree_add_uint_format_value(tree, hf_gsm_a_sm_qos_maximum_sdu_size, tvb, curr_offset, 1, oct, "%u octets (%u)", oct*10, oct);
else
proto_tree_add_uint_format_value(tree, hf_gsm_a_sm_qos_maximum_sdu_size, tvb, curr_offset, 1, oct, "%s (%u)", str, oct);
curr_offset += 1;
NO_MORE_DATA_CHECK(len);
oct = tvb_get_guint8(tvb, curr_offset);
switch (oct)
{
case 0x00: str = "Subscribed maximum bit rate for uplink/reserved"; break;
case 0xff: str = "0 kbps"; break;
default: str = wmem_strdup_printf(wmem_packet_scope(), "%u kbps", qos_calc_bitrate(oct));
}
proto_tree_add_uint_format_value(tree, hf_gsm_a_sm_qos_max_bitrate_upl, tvb,
curr_offset, 1, oct, "%s (%u)", str, oct);
curr_offset += 1;
NO_MORE_DATA_CHECK(len);
oct = tvb_get_guint8(tvb, curr_offset);
switch (oct)
{
case 0x00: str = "Subscribed maximum bit rate for downlink/reserved"; break;
case 0xff: str = "0 kbps"; break;
default: str = wmem_strdup_printf(wmem_packet_scope(), "%u kbps", qos_calc_bitrate(oct));
}
proto_tree_add_uint_format_value(tree, hf_gsm_a_sm_qos_max_bitrate_downl, tvb,
curr_offset, 1, oct, "%s (%u)", str, oct);
curr_offset += 1;
NO_MORE_DATA_CHECK(len);
proto_tree_add_item(tree, hf_gsm_a_sm_qos_ber, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_sm_qos_sdu_err_rat, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
NO_MORE_DATA_CHECK(len);
oct = tvb_get_guint8(tvb, curr_offset);
tmp_oct = oct>>2;
switch (tmp_oct)
{
case 0x00: str = "Subscribed transfer delay/reserved"; break;
case 0x3f: str = "Reserved"; break;
default:
if (tmp_oct <= 0x0f)
temp32 = tmp_oct * 10;
else if (tmp_oct <= 0x1f)
temp32 = (tmp_oct - 0x10) * 50 + 200;
else
temp32 = (tmp_oct - 0x20) * 100 + 1000;
str = wmem_strdup_printf(wmem_packet_scope(), "%u ms", temp32);
}
proto_tree_add_uint_format_value(tree, hf_gsm_a_sm_qos_trans_delay, tvb,
curr_offset, 1, oct, "%s (%u)", str, tmp_oct);
proto_tree_add_item(tree, hf_gsm_a_sm_qos_traff_hdl_pri, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
NO_MORE_DATA_CHECK(len);
oct = tvb_get_guint8(tvb, curr_offset);
switch (oct)
{
case 0x00: str = "Subscribed guaranteed bit rate for uplink/reserved"; break;
case 0xff: str = "0 kbps"; break;
default: str = wmem_strdup_printf(wmem_packet_scope(), "%u kbps", qos_calc_bitrate(oct));
}
proto_tree_add_uint_format_value(tree, hf_gsm_a_sm_qos_guar_bitrate_upl, tvb,
curr_offset, 1, oct, "%s (%u)", str, oct);
curr_offset += 1;
NO_MORE_DATA_CHECK(len);
oct = tvb_get_guint8(tvb, curr_offset);
switch (oct)
{
case 0x00: str = "Subscribed guaranteed bit rate for downlink/reserved"; break;
case 0xff: str = "0 kbps"; break;
default: str = wmem_strdup_printf(wmem_packet_scope(), "%u kbps", qos_calc_bitrate(oct));
}
proto_tree_add_uint_format_value(tree, hf_gsm_a_sm_qos_guar_bitrate_downl, tvb,
curr_offset, 1, oct, "%s (%u)", str, oct);
curr_offset += 1;
NO_MORE_DATA_CHECK(len);
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset << 3), 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_sm_qos_signalling_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
tmp_oct = oct & 7;
if (tmp_oct == 0x01)
str = "speech";
else
str = "unknown";
proto_tree_add_uint_format_value(tree, hf_gsm_a_sm_qos_source_stat_desc, tvb,
curr_offset, 1, oct, "%s (%u)", str, tmp_oct);
curr_offset += 1;
NO_MORE_DATA_CHECK(len);
oct = tvb_get_guint8(tvb, curr_offset);
if (oct == 0x00)
str = "Use the value indicated by the Maximum bit rate for downlink";
else
{
temp32 = qos_calc_ext_bitrate(oct);
if (temp32 % 1000 == 0)
str = wmem_strdup_printf(wmem_packet_scope(), "%u Mbps", temp32 / 1000);
else
str = wmem_strdup_printf(wmem_packet_scope(), "%u kbps", temp32);
}
proto_tree_add_uint_format_value(tree, hf_gsm_a_sm_qos_max_bitrate_downl_ext, tvb,
curr_offset, 1, oct, "%s (%u)", str, oct);
curr_offset += 1;
NO_MORE_DATA_CHECK(len);
oct = tvb_get_guint8(tvb, curr_offset);
if (oct == 0x00)
str = "Use the value indicated by the Guaranteed bit rate for downlink";
else
{
temp32 = qos_calc_ext_bitrate(oct);
if (temp32 % 1000 == 0)
str = wmem_strdup_printf(wmem_packet_scope(), "%u Mbps", temp32 / 1000);
else
str = wmem_strdup_printf(wmem_packet_scope(), "%u kbps", temp32);
}
proto_tree_add_uint_format_value(tree, hf_gsm_a_sm_qos_guar_bitrate_downl_ext, tvb,
curr_offset, 1, oct, "%s (%u)", str, oct);
curr_offset += 1;
NO_MORE_DATA_CHECK(len);
oct = tvb_get_guint8(tvb, curr_offset);
if (oct == 0x00)
str = "Use the value indicated by the Maximum bit rate for uplink";
else
{
temp32 = qos_calc_ext_bitrate(oct);
if (temp32 % 1000 == 0)
str = wmem_strdup_printf(wmem_packet_scope(), "%u Mbps", temp32 / 1000);
else
str = wmem_strdup_printf(wmem_packet_scope(), "%u kbps", temp32);
}
proto_tree_add_uint_format_value(tree, hf_gsm_a_sm_qos_max_bitrate_upl_ext, tvb,
curr_offset, 1, oct, "%s (%u)", str, oct);
curr_offset += 1;
NO_MORE_DATA_CHECK(len);
oct = tvb_get_guint8(tvb, curr_offset);
if (oct == 0x00)
str = "Use the value indicated by the Guaranteed bit rate for uplink";
else
{
temp32 = qos_calc_ext_bitrate(oct);
if (temp32 % 1000 == 0)
str = wmem_strdup_printf(wmem_packet_scope(), "%u Mbps", temp32 / 1000);
else
str = wmem_strdup_printf(wmem_packet_scope(), "%u kbps", temp32);
}
proto_tree_add_uint_format_value(tree, hf_gsm_a_sm_qos_guar_bitrate_upl_ext, tvb,
curr_offset, 1, oct, "%s (%u)", str, oct);
curr_offset += 1;
NO_MORE_DATA_CHECK(len);
oct = tvb_get_guint8(tvb, curr_offset);
if (oct == 0x00)
str = "Use the value indicated by the Maximum bit rate for downlink";
else
{
temp32 = qos_calc_ext2_bitrate(oct);
str = wmem_strdup_printf(wmem_packet_scope(), "%u Mbps", temp32);
}
proto_tree_add_uint_format_value(tree, hf_gsm_a_sm_qos_max_bitrate_downl_ext2, tvb,
curr_offset, 1, oct, "%s (%u)", str, oct);
curr_offset += 1;
NO_MORE_DATA_CHECK(len);
oct = tvb_get_guint8(tvb, curr_offset);
if (oct == 0x00)
str = "Use the value indicated by the Guaranteed bit rate for downlink";
else
{
temp32 = qos_calc_ext2_bitrate(oct);
str = wmem_strdup_printf(wmem_packet_scope(), "%u Mbps", temp32);
}
proto_tree_add_uint_format_value(tree, hf_gsm_a_sm_qos_guar_bitrate_downl_ext2, tvb,
curr_offset, 1, oct, "%s (%u)", str, oct);
curr_offset += 1;
NO_MORE_DATA_CHECK(len);
oct = tvb_get_guint8(tvb, curr_offset);
if (oct == 0x00)
str = "Use the value indicated by the Maximum bit rate for uplink";
else
{
temp32 = qos_calc_ext2_bitrate(oct);
str = wmem_strdup_printf(wmem_packet_scope(), "%u Mbps", temp32);
}
proto_tree_add_uint_format_value(tree, hf_gsm_a_sm_qos_max_bitrate_upl_ext2, tvb,
curr_offset, 1, oct, "%s (%u)", str, oct);
curr_offset += 1;
NO_MORE_DATA_CHECK(len);
oct = tvb_get_guint8(tvb, curr_offset);
if (oct == 0x00)
str = "Use the value indicated by the Guaranteed bit rate for uplink";
else
{
temp32 = qos_calc_ext2_bitrate(oct);
str = wmem_strdup_printf(wmem_packet_scope(), "%u Mbps", temp32);
}
proto_tree_add_uint_format_value(tree, hf_gsm_a_sm_qos_guar_bitrate_upl_ext2, tvb,
curr_offset, 1, oct, "%s (%u)", str, oct);
curr_offset += 1;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_gm_extraneous_data);
return (curr_offset - offset);
}
static guint16
de_sm_re_attempt_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, offset << 3, 7, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_sm_ratc, tvb, offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_gm_extraneous_data);
return len;
}
static guint16
de_sm_cause(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint8 oct;
const gchar *str;
oct = tvb_get_guint8(tvb, offset);
str = val_to_str_ext_const(oct, &gsm_a_sm_cause_vals_ext,
"Protocol error, unspecified / Service option temporarily out of order");
proto_tree_add_uint_format_value(tree, hf_gsm_a_sm_cause, tvb,
offset, 1, oct, "%s (%u)", str, oct);
return (1);
}
static guint16
de_sm_cause_2(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint8 oct;
const gchar *str;
oct = tvb_get_guint8(tvb, offset);
str = val_to_str_ext_const(oct, &gsm_a_sm_cause_vals_ext,
"Service option temporarily out of order");
proto_tree_add_uint_format_value(tree, hf_gsm_a_sm_cause_2, tvb,
offset, 1, oct, "%s (%u)", str, oct);
return (1);
}
static guint16
de_sm_linked_ti(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint curr_len;
gchar oct;
curr_len = len;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(tree, hf_gsm_a_sm_ti_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
if (curr_len > 1)
{
curr_offset++;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_uint(tree, hf_gsm_a_gm_ti_value, tvb, curr_offset, 1, oct&0x7f);
proto_tree_add_item(tree, hf_gsm_a_sm_ext, tvb, offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
}
else
{
proto_tree_add_uint(tree, hf_gsm_a_gm_ti_value, tvb, curr_offset, 1, (oct>>4)&7);
curr_offset++;
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_gm_extraneous_data);
return (curr_offset - offset);
}
static guint16
de_sm_sapi(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, offset << 3, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_sm_llc_sapi, tvb, offset, 1, ENC_BIG_ENDIAN);
return (1);
}
static guint16
de_sm_tear_down(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (offset << 3) + 4, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_sm_tdi, tvb, offset, 1, ENC_BIG_ENDIAN);
return (1);
}
guint16
de_sm_pflow_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint value;
curr_offset = offset;
value = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, curr_offset << 3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_sm_packet_flow_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
if (add_string)
g_snprintf(add_string, string_len, " - %s", rval_to_str(value, gsm_a_sm_packet_flow_id_vals, "Unknown"));
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_gm_extraneous_data);
return (curr_offset - offset);
}
guint16
de_sm_tflow_temp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset, prev_offset;
guint curr_len;
guint8 op_code;
guint8 pkt_fil_count;
guint8 e_bit;
guint8 count;
guint8 oct;
gint pf_length;
gint i;
gint pack_component_type;
gint param;
curr_len = len;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
op_code = oct>>5;
pkt_fil_count = oct&0x0f;
e_bit = (oct>>4)&1;
proto_tree_add_item(tree, hf_gsm_a_sm_tft_op_code, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_sm_tft_e_bit, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_sm_tft_pkt_flt, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
curr_len--;
count = 0;
if (op_code == 2)
count = pkt_fil_count;
while (count < pkt_fil_count)
{
proto_item *tf_pf;
proto_tree *tf_tree;
prev_offset = curr_offset;
tf_pf = proto_tree_add_uint(tree, hf_gsm_a_sm_tft_packet_filter, tvb, curr_offset, 1, count);
tf_tree = proto_item_add_subtree(tf_pf, ett_sm_tft);
if ((curr_offset-offset)<1) {
proto_tree_add_expert(tf_tree, pinfo, &ei_gsm_a_gm_not_enough_data, tvb, curr_offset, 1);
return (len);
}
if (op_code == 5)
{
proto_tree_add_bits_item(tf_tree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3), 4, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset) & 0x0f;
proto_tree_add_uint_format_value(tf_tree, hf_gsm_a_sm_tft_pkt_flt_id, tvb, curr_offset, 1, oct, "%d (%d)", oct+1, oct);
curr_offset++;
curr_len--;
count++;
}
else
{
proto_tree_add_bits_item(tf_tree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3), 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tf_tree, hf_gsm_a_sm_tft_pkt_flt_dir, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = tvb_get_guint8(tvb, curr_offset) & 0x0f;
proto_tree_add_uint_format_value(tf_tree, hf_gsm_a_sm_tft_pkt_flt_id, tvb, curr_offset, 1, oct, "%d (%d)", oct+1, oct);
curr_offset++;
curr_len--;
if ((curr_offset-offset) < 1) {
proto_tree_add_expert(tf_tree, pinfo, &ei_gsm_a_gm_not_enough_data, tvb, curr_offset, 1);
return (len);
}
proto_tree_add_item(tf_tree, hf_gsm_a_sm_tft_packet_evaluation_precedence, tvb, curr_offset, 1, ENC_NA);
curr_offset++;
curr_len--;
if ((curr_offset-offset)<1) {
proto_tree_add_expert(tf_tree, pinfo, &ei_gsm_a_gm_not_enough_data, tvb, curr_offset, 1);
return (len);
}
pf_length = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(tf_tree, hf_gsm_a_sm_tft_packet_filter_length, tvb, curr_offset, 1, ENC_NA);
curr_offset++;
curr_len--;
while (pf_length > 0) {
proto_item *tf;
proto_tree *comp_tree;
if ((curr_offset-offset) < 1) {
proto_tree_add_expert(tf_tree, pinfo, &ei_gsm_a_gm_not_enough_data, tvb, curr_offset, 1);
return (len);
}
pack_component_type = tvb_get_guint8(tvb, curr_offset);
tf = proto_tree_add_item(tf_tree, hf_gsm_a_sm_tft_packet_filter_component_type_id, tvb, curr_offset, 1, ENC_NA);
comp_tree = proto_item_add_subtree(tf, ett_sm_tft);
curr_offset++;
curr_len--;
pf_length--;
switch (pack_component_type) {
case 0x10:
proto_tree_add_item(comp_tree, hf_gsm_a_sm_ip4_address, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
curr_offset += 4;
curr_len -= 4;
proto_tree_add_item(comp_tree, hf_gsm_a_sm_ip4_mask, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
curr_offset += 4;
curr_len -= 4;
pf_length -= 8;
break;
case 0x11:
proto_tree_add_item(comp_tree, hf_gsm_a_sm_ip4_address, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
curr_offset += 4;
curr_len -= 4;
proto_tree_add_item(comp_tree, hf_gsm_a_sm_ip4_mask, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
curr_offset += 4;
curr_len -= 4;
pf_length -= 8;
break;
case 0x20:
proto_tree_add_item(comp_tree, hf_gsm_a_sm_ip6_address, tvb, curr_offset, 16, ENC_NA);
curr_offset += 16;
curr_len -= 16;
proto_tree_add_item(comp_tree, hf_gsm_a_sm_ip6_mask, tvb, curr_offset, 16, ENC_NA);
curr_offset += 16;
curr_len -= 16;
pf_length -= 32;
break;
case 0x21:
proto_tree_add_item(comp_tree, hf_gsm_a_sm_ip6_address, tvb, curr_offset, 16, ENC_NA);
curr_offset += 16;
curr_len -= 16;
proto_tree_add_item(comp_tree, hf_gsm_a_sm_ip6_prefix_length, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
curr_len -= 1;
pf_length -= 17;
break;
case 0x23:
proto_tree_add_item(comp_tree, hf_gsm_a_sm_ip6_address, tvb, curr_offset, 16, ENC_NA);
curr_offset += 16;
curr_len -= 16;
proto_tree_add_item(comp_tree, hf_gsm_a_sm_ip6_prefix_length, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
curr_len -= 1;
pf_length -= 17;
break;
case 0x30:
proto_tree_add_item(comp_tree, hf_gsm_a_sm_tft_protocol_header, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
curr_len -= 1;
pf_length -= 1;
break;
case 0x40:
proto_tree_add_item(comp_tree, hf_gsm_a_sm_tft_port, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
curr_len -= 2;
pf_length -= 2;
break;
case 0x41:
proto_tree_add_item(comp_tree, hf_gsm_a_sm_tft_port_low, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
proto_tree_add_item(comp_tree, hf_gsm_a_sm_tft_port_high, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
curr_len -= 4;
pf_length -= 4;
break;
case 0x50:
proto_tree_add_item(comp_tree, hf_gsm_a_sm_tft_port, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
curr_len -= 2;
pf_length -= 2;
break;
case 0x51:
proto_tree_add_item(comp_tree, hf_gsm_a_sm_tft_port_low, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
proto_tree_add_item(comp_tree, hf_gsm_a_sm_tft_port_high, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset += 2;
curr_len -= 4;
pf_length -= 4;
break;
case 0x60:
proto_tree_add_item(comp_tree, hf_gsm_a_sm_tft_security, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
curr_offset += 4;
curr_len -= 4;
pf_length -= 4;
break;
case 0x70:
proto_tree_add_item(comp_tree, hf_gsm_a_sm_tft_traffic_class, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(comp_tree, hf_gsm_a_sm_tft_traffic_mask, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
curr_len-=2;
pf_length-=2;
break;
case 0x80:
proto_tree_add_bits_item(comp_tree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3), 4, ENC_BIG_ENDIAN);
proto_tree_add_item(comp_tree, hf_gsm_a_sm_tft_flow_label_type, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
curr_offset += 3;
curr_len -= 3;
pf_length -= 3;
break;
default:
curr_offset += pf_length;
curr_len -= pf_length;
pf_length = 0;
}
}
count++;
}
proto_item_set_len(tf_pf, curr_offset - prev_offset);
}
if ((e_bit == 1) && curr_len) {
count = 0;
while (curr_len) {
proto_tree *tf_tree;
pf_length = tvb_get_guint8(tvb, curr_offset+1);
tf_tree = proto_tree_add_subtree_format(tree, tvb, curr_offset, pf_length+2, ett_sm_tft, NULL, "Parameter %d", count);
param = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(tf_tree, hf_gsm_a_sm_tft_param_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 2;
curr_len -= 2;
switch (param) {
case 0x01:
proto_tree_add_item(tf_tree, hf_gsm_a_sm_tft_authorization_token_value, tvb, curr_offset, pf_length, ENC_NA);
break;
case 0x02:
proto_tree_add_item(tf_tree, hf_gsm_a_sm_tft_media_component_number_value, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(tf_tree, hf_gsm_a_sm_tft_ip_flow_number, tvb, curr_offset+2, 2, ENC_BIG_ENDIAN);
break;
case 0x03:
for (i=0; i<pf_length; i++) {
oct = tvb_get_guint8(tvb, curr_offset+i) & 0x0f;
proto_tree_add_uint_format(tf_tree, hf_gsm_a_sm_tft_packet_filter_identifier, tvb, curr_offset+i, 1, oct+1, "Packet filter identifier %d: %d (%d)", i, oct+1, oct);
}
break;
default:
proto_tree_add_item(tf_tree, hf_gsm_a_sm_tft_parameter_content, tvb, curr_offset, pf_length, ENC_NA);
break;
}
curr_offset += pf_length;
curr_len -= pf_length;
count++;
}
}
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_gm_extraneous_data);
return (len);
}
static guint16
de_sm_tmgi(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_sm_tmgi, tvb, curr_offset, 3, ENC_BIG_ENDIAN);
curr_offset += 3;
NO_MORE_DATA_CHECK(len);
curr_offset = dissect_e212_mcc_mnc(tvb, pinfo, tree, curr_offset, E212_NONE, TRUE);
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_gm_extraneous_data);
return (curr_offset - offset);
}
static guint16
de_sm_mbms_bearer_cap(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset, temp32;
guint8 oct;
const gchar *str;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
switch (oct)
{
case 0x00: str = "Subscribed maximum bit rate for downlink/reserved"; break;
case 0xff: str = "0 kbps"; break;
default: str = wmem_strdup_printf(wmem_packet_scope(), "%u kbps", qos_calc_bitrate(oct));
}
proto_tree_add_uint_format_value(tree, hf_gsm_a_sm_qos_max_bitrate_downl, tvb,
curr_offset, 1, oct, "%s (%u)", str, oct);
curr_offset += 1;
NO_MORE_DATA_CHECK(len);
oct = tvb_get_guint8(tvb, curr_offset);
if (oct == 0x00)
str = "Use the value indicated by the Maximum bit rate for downlink";
else
{
temp32 = qos_calc_ext_bitrate(oct);
if (temp32 % 1000 == 0)
str = wmem_strdup_printf(wmem_packet_scope(), "%u Mbps", temp32 / 1000);
else
str = wmem_strdup_printf(wmem_packet_scope(), "%u kbps", temp32);
}
proto_tree_add_uint_format_value(tree, hf_gsm_a_sm_qos_max_bitrate_downl_ext, tvb,
curr_offset, 1, oct, "%s (%u)", str, oct);
curr_offset += 1;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_gm_extraneous_data);
return (curr_offset - offset);
}
static guint16
de_sm_mbms_prot_conf_opt(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (curr_offset<<3), 8, ENC_BIG_ENDIAN);
curr_offset++;
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset, pinfo, &ei_gsm_a_gm_extraneous_data);
return (curr_offset - offset);
}
static guint16
de_sm_enh_nsapi(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint8 oct;
const gchar *str;
oct = tvb_get_guint8(tvb, offset);
if(oct < 0x80)
str = "Reserved";
else if (oct < 0xff)
str = wmem_strdup_printf(wmem_packet_scope(), "NSAPI %u for Multimedia Broadcast/Multicast Service (MBMS) Multicast mode", oct);
else
str = "Reserved for use by lower layers in the p2p radio bearer allocation message for MBMS Broadcast mode";
proto_tree_add_uint_format_value(tree, hf_gsm_a_sm_enh_nsapi, tvb,
offset, 1, oct, "%s (%u)", str, oct);
return (1);
}
static guint16
de_sm_req_type(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (offset<<3) + 4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_sm_req_type, tvb, offset, 1, ENC_BIG_ENDIAN);
return (1);
}
static guint16
de_sm_notif_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_sm_notif_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
return (len);
}
static guint16
de_sm_connectivity_type(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_item(tree, hf_gsm_a_sm_connectivity_type, tvb, offset, 1, ENC_BIG_ENDIAN);
return (len);
}
static guint16
de_sm_wlan_offload_accept(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_bits_item(tree, hf_gsm_a_spare_bits, tvb, (offset<<3)+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_sm_wlan_utran_offload_accept, tvb, (offset<<3)+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_sm_wlan_eutran_offload_accept, tvb, (offset<<3)+7, 1, ENC_BIG_ENDIAN);
return (len);
}
static void
dtap_gmm_attach_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_RECV;
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_MS_NET_CAP, NULL);
ELEM_MAND_VV_SHORT(GSM_A_PDU_TYPE_GM, DE_ATTACH_TYPE, GSM_A_PDU_TYPE_COMMON, DE_CIPH_KEY_SEQ_NUM);
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_DRX_PARAM, NULL);
ELEM_MAND_LV( GSM_A_PDU_TYPE_COMMON, DE_MID, NULL);
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_RAI, " - Old routing area identification");
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_MS_RAD_ACC_CAP, NULL);
ELEM_OPT_TV( 0x19, GSM_A_PDU_TYPE_GM, DE_P_TMSI_SIG, " - Old P-TMSI Signature");
ELEM_OPT_TV( 0x17, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER, " - Ready Timer");
ELEM_OPT_TV_SHORT( 0x90, GSM_A_PDU_TYPE_GM, DE_TMSI_STAT, NULL);
ELEM_OPT_TLV( 0x33, GSM_A_PDU_TYPE_GM, DE_PS_LCS_CAP, NULL);
ELEM_OPT_TLV( 0x11, GSM_A_PDU_TYPE_COMMON, DE_MS_CM_2, NULL);
ELEM_OPT_TLV( 0x20, GSM_A_PDU_TYPE_COMMON, DE_MS_CM_3, NULL);
ELEM_OPT_TLV( 0x40, GSM_A_PDU_TYPE_DTAP, DE_SUP_CODEC_LIST, NULL);
ELEM_OPT_TLV( 0x58, NAS_PDU_TYPE_EMM, DE_EMM_UE_NET_CAP, NULL);
ELEM_OPT_TLV( 0x1A, GSM_A_PDU_TYPE_COMMON, DE_MID, " - Additional mobile identity");
ELEM_OPT_TLV( 0x1B, GSM_A_PDU_TYPE_GM, DE_RAI_2, " - Additional old routing area identification");
ELEM_OPT_TLV( 0x5D, GSM_A_PDU_TYPE_GM, DE_VOICE_DOMAIN_PREF, NULL);
ELEM_OPT_TV_SHORT(0xD0, GSM_A_PDU_TYPE_GM, DE_DEVICE_PROPERTIES, NULL);
ELEM_OPT_TV_SHORT(0xE0, GSM_A_PDU_TYPE_GM, DE_PTMSI_TYPE, NULL);
ELEM_OPT_TV_SHORT(0xC0, GSM_A_PDU_TYPE_COMMON, DE_MS_NET_FEAT_SUP, NULL);
ELEM_OPT_TLV(0x14, GSM_A_PDU_TYPE_GM, DE_LAI_2, " - Old location area identification");
ELEM_OPT_TV_SHORT(0xF0, GSM_A_PDU_TYPE_GM, DE_ADD_UPD_TYPE, NULL);
ELEM_OPT_TLV(0x10, GSM_A_PDU_TYPE_GM, DE_NET_RES_ID_CONT, " - TMSI based NRI container");
ELEM_OPT_TLV(0x6A, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3324 value");
ELEM_OPT_TLV(0x39, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_3, " - T3312 extended value");
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_gmm_attach_acc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_SENT;
ELEM_MAND_VV_SHORT(GSM_A_PDU_TYPE_GM, DE_ATTACH_RES, GSM_A_PDU_TYPE_GM, DE_FORCE_TO_STAND_H);
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER, NULL);
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_RAD_PRIO_2, " - Radio priority for TOM8");
curr_len++;
curr_offset--;
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_RAD_PRIO, " - Radio priority for SMS");
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_RAI, NULL);
ELEM_OPT_TV( 0x19, GSM_A_PDU_TYPE_GM, DE_P_TMSI_SIG, NULL);
ELEM_OPT_TV( 0x17, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER, " - Negotiated Ready Timer");
ELEM_OPT_TLV( 0x18, GSM_A_PDU_TYPE_COMMON, DE_MID, " - Allocated P-TMSI");
ELEM_OPT_TLV( 0x23, GSM_A_PDU_TYPE_COMMON, DE_MID, NULL);
ELEM_OPT_TV( 0x25, GSM_A_PDU_TYPE_GM, DE_GMM_CAUSE, NULL);
ELEM_OPT_TLV( 0x2A, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3302 value");
ELEM_OPT_T( 0x8C, GSM_A_PDU_TYPE_GM, DE_CELL_NOT, NULL);
ELEM_OPT_TLV( 0x4A, GSM_A_PDU_TYPE_COMMON, DE_PLMN_LIST, NULL);
ELEM_OPT_TV_SHORT( 0xB0, GSM_A_PDU_TYPE_GM, DE_NET_FEAT_SUP, NULL);
ELEM_OPT_TLV( 0x34, GSM_A_PDU_TYPE_DTAP, DE_EMERGENCY_NUM_LIST, NULL);
ELEM_OPT_TV_SHORT( 0xA0, GSM_A_PDU_TYPE_GM, DE_REQ_MS_INFO, NULL);
ELEM_OPT_TLV( 0x37, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3319 value");
ELEM_OPT_TLV( 0x38, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3323 value" );
ELEM_OPT_TLV(0x39, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_3, " - T3312 extended value");
ELEM_OPT_TLV(0x66, GSM_A_PDU_TYPE_GM, DE_ADD_NET_FEAT_SUP, NULL);
ELEM_OPT_TLV(0x6A, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3324 value");
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_gmm_attach_com(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_RECV;
ELEM_OPT_TLV( 0x27, GSM_A_PDU_TYPE_GM, DE_RAT_INFO_CONTAINER, " - Inter RAT handover information");
ELEM_OPT_TLV( 0x2B, GSM_A_PDU_TYPE_GM, DE_EUTRAN_IRAT_INFO_CONTAINER, " - E-UTRAN inter RAT handover information");
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_gmm_attach_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_SENT;
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_GMM_CAUSE, NULL);
ELEM_OPT_TLV( 0x2A, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3302 value" );
ELEM_OPT_TLV(0x3A, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3346 value");
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_gmm_detach_req_MT(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_SENT;
ELEM_MAND_VV_SHORT(GSM_A_PDU_TYPE_GM, DE_DETACH_TYPE, GSM_A_PDU_TYPE_GM, DE_FORCE_TO_STAND_H);
ELEM_OPT_TV( 0x25, GSM_A_PDU_TYPE_GM, DE_GMM_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_gmm_detach_req_MO(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_RECV;
ELEM_MAND_VV_SHORT(GSM_A_PDU_TYPE_GM, DE_DETACH_TYPE, GSM_A_PDU_TYPE_COMMON, DE_SPARE_NIBBLE);
ELEM_OPT_TLV( 0x18, GSM_A_PDU_TYPE_COMMON, DE_MID, NULL);
ELEM_OPT_TLV( 0x19, GSM_A_PDU_TYPE_GM, DE_P_TMSI_SIG_2, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_gmm_detach_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
if (pinfo->link_dir == P2P_DIR_UL) {
dtap_gmm_detach_req_MO(tvb, tree, pinfo, offset, len);
return;
}else if (pinfo->link_dir == P2P_DIR_DL) {
dtap_gmm_detach_req_MT(tvb, tree, pinfo, offset, len);
return;
} else {
if (len > 5) {
dtap_gmm_detach_req_MO(tvb, tree, pinfo, offset, len);
} else {
dtap_gmm_detach_req_MT(tvb, tree, pinfo, offset, len);
}
}
}
static void
dtap_gmm_detach_acc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_RECV;
if (curr_len == 0) {
return;
}
ELEM_MAND_VV_SHORT(GSM_A_PDU_TYPE_GM, DE_FORCE_TO_STAND, GSM_A_PDU_TYPE_COMMON, DE_SPARE_NIBBLE);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_gmm_ptmsi_realloc_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_SENT;
ELEM_MAND_LV( GSM_A_PDU_TYPE_COMMON, DE_MID, " - Allocated P-TMSI" );
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_RAI, NULL);
ELEM_MAND_VV_SHORT(GSM_A_PDU_TYPE_GM, DE_FORCE_TO_STAND, GSM_A_PDU_TYPE_COMMON, DE_SPARE_NIBBLE);
ELEM_OPT_TV( 0x19, GSM_A_PDU_TYPE_GM, DE_P_TMSI_SIG, " - P-TMSI Signature" );
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_gmm_ptmsi_realloc_com(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_RECV;
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_gmm_auth_ciph_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_SENT;
ELEM_MAND_VV_SHORT(GSM_A_PDU_TYPE_GM, DE_CIPH_ALG, GSM_A_PDU_TYPE_GM, DE_IMEISV_REQ);
ELEM_MAND_VV_SHORT(GSM_A_PDU_TYPE_GM, DE_FORCE_TO_STAND, GSM_A_PDU_TYPE_GM, DE_AC_REF_NUM_H);
ELEM_OPT_TV( 0x21, GSM_A_PDU_TYPE_DTAP, DE_AUTH_PARAM_RAND, NULL);
ELEM_OPT_TV_SHORT( 0x80, GSM_A_PDU_TYPE_COMMON, DE_CIPH_KEY_SEQ_NUM, NULL);
ELEM_OPT_TLV( 0x28, GSM_A_PDU_TYPE_DTAP, DE_AUTH_PARAM_AUTN, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_gmm_auth_ciph_resp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_RECV;
ELEM_MAND_VV_SHORT(GSM_A_PDU_TYPE_GM, DE_AC_REF_NUM, GSM_A_PDU_TYPE_COMMON, DE_SPARE_NIBBLE);
ELEM_OPT_TV( 0x22, GSM_A_PDU_TYPE_DTAP, DE_AUTH_RESP_PARAM, NULL);
ELEM_OPT_TLV( 0x23, GSM_A_PDU_TYPE_COMMON, DE_MID, " - IMEISV" );
ELEM_OPT_TLV( 0x29, GSM_A_PDU_TYPE_DTAP, DE_AUTH_RESP_PARAM_EXT, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_gmm_auth_ciph_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_SENT;
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_gmm_auth_ciph_fail(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_RECV;
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_GMM_CAUSE, NULL);
ELEM_OPT_TLV( 0x30, GSM_A_PDU_TYPE_DTAP, DE_AUTH_FAIL_PARAM, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_gmm_ident_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_SENT;
ELEM_MAND_VV_SHORT(GSM_A_PDU_TYPE_GM, DE_ID_TYPE_2, GSM_A_PDU_TYPE_GM, DE_FORCE_TO_STAND_H);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_gmm_ident_res(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_RECV;
ELEM_MAND_LV( GSM_A_PDU_TYPE_COMMON, DE_MID, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_gmm_rau_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_RECV;
ELEM_MAND_VV_SHORT(GSM_A_PDU_TYPE_GM, DE_UPD_TYPE, GSM_A_PDU_TYPE_COMMON, DE_CIPH_KEY_SEQ_NUM);
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_RAI, " - Old routing area identification");
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_MS_RAD_ACC_CAP, NULL);
ELEM_OPT_TV( 0x19, GSM_A_PDU_TYPE_GM, DE_P_TMSI_SIG, " - Old P-TMSI Signature" );
ELEM_OPT_TV( 0x17, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER, " - Requested Ready Timer" );
ELEM_OPT_TV( 0x27, GSM_A_PDU_TYPE_GM, DE_DRX_PARAM, NULL);
ELEM_OPT_TV_SHORT( 0x90, GSM_A_PDU_TYPE_GM, DE_TMSI_STAT, NULL);
ELEM_OPT_TLV( 0x18, GSM_A_PDU_TYPE_COMMON, DE_MID, " - P-TMSI" );
ELEM_OPT_TLV( 0x31, GSM_A_PDU_TYPE_GM, DE_MS_NET_CAP, NULL);
ELEM_OPT_TLV( 0x32, GSM_A_PDU_TYPE_GM, DE_PDP_CONTEXT_STAT, NULL);
ELEM_OPT_TLV( 0x33, GSM_A_PDU_TYPE_GM, DE_PS_LCS_CAP, NULL);
ELEM_OPT_TLV( 0x35, GSM_A_PDU_TYPE_GM, DE_MBMS_CTX_STATUS, NULL);
ELEM_OPT_TLV( 0x58, NAS_PDU_TYPE_EMM, DE_EMM_UE_NET_CAP, NULL);
ELEM_OPT_TLV( 0x1A, GSM_A_PDU_TYPE_COMMON, DE_MID, " - Additional mobile identity");
ELEM_OPT_TLV( 0x1B, GSM_A_PDU_TYPE_GM, DE_RAI_2, " - Additional old routing area identification");
ELEM_OPT_TLV( 0x11, GSM_A_PDU_TYPE_COMMON, DE_MS_CM_2, NULL);
ELEM_OPT_TLV( 0x20, GSM_A_PDU_TYPE_COMMON, DE_MS_CM_3, NULL);
ELEM_OPT_TLV( 0x40, GSM_A_PDU_TYPE_DTAP, DE_SUP_CODEC_LIST, NULL);
ELEM_OPT_TLV( 0x5D, GSM_A_PDU_TYPE_GM, DE_VOICE_DOMAIN_PREF, NULL);
ELEM_OPT_TV_SHORT(0xE0, GSM_A_PDU_TYPE_GM, DE_PTMSI_TYPE, NULL);
ELEM_OPT_TV_SHORT(0xD0, GSM_A_PDU_TYPE_GM, DE_DEVICE_PROPERTIES, NULL);
ELEM_OPT_TV_SHORT(0xC0, GSM_A_PDU_TYPE_COMMON, DE_MS_NET_FEAT_SUP, NULL);
ELEM_OPT_TLV(0x14, GSM_A_PDU_TYPE_GM, DE_LAI_2, " - Old location area identification");
ELEM_OPT_TV_SHORT(0xF0, GSM_A_PDU_TYPE_GM, DE_ADD_UPD_TYPE, NULL);
ELEM_OPT_TLV(0x10, GSM_A_PDU_TYPE_GM, DE_NET_RES_ID_CONT, " - TMSI based NRI container");
ELEM_OPT_TLV(0x6A, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3324 value");
ELEM_OPT_TLV(0x39, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_3, " - T3312 extended value");
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_gmm_rau_acc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_SENT;
ELEM_MAND_VV_SHORT(GSM_A_PDU_TYPE_GM, DE_FORCE_TO_STAND, GSM_A_PDU_TYPE_GM, DE_UPD_RES);
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER, " - Periodic RA update timer");
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_RAI, NULL);
ELEM_OPT_TV( 0x19, GSM_A_PDU_TYPE_GM, DE_P_TMSI_SIG, NULL);
ELEM_OPT_TLV( 0x18, GSM_A_PDU_TYPE_COMMON, DE_MID, " - Allocated P-TMSI");
ELEM_OPT_TLV( 0x23, GSM_A_PDU_TYPE_COMMON, DE_MID, " - MS identity");
ELEM_OPT_TLV( 0x26, GSM_A_PDU_TYPE_GM, DE_REC_N_PDU_NUM_LIST, NULL);
ELEM_OPT_TV( 0x17, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER, " - Negotiated Ready Timer" );
ELEM_OPT_TV( 0x25, GSM_A_PDU_TYPE_GM, DE_GMM_CAUSE, NULL);
ELEM_OPT_TLV( 0x2A, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3302 value" );
ELEM_OPT_T( 0x8C, GSM_A_PDU_TYPE_GM, DE_CELL_NOT, NULL);
ELEM_OPT_TLV( 0x4A, GSM_A_PDU_TYPE_COMMON, DE_PLMN_LIST, NULL);
ELEM_OPT_TLV( 0x32, GSM_A_PDU_TYPE_GM, DE_PDP_CONTEXT_STAT, NULL);
ELEM_OPT_TV_SHORT( 0xB0, GSM_A_PDU_TYPE_GM, DE_NET_FEAT_SUP, NULL);
ELEM_OPT_TLV( 0x34, GSM_A_PDU_TYPE_DTAP, DE_EMERGENCY_NUM_LIST, NULL);
ELEM_OPT_TLV( 0x35, GSM_A_PDU_TYPE_GM, DE_MBMS_CTX_STATUS, NULL);
ELEM_OPT_TV_SHORT( 0xA0, GSM_A_PDU_TYPE_GM, DE_REQ_MS_INFO, NULL);
ELEM_OPT_TLV( 0x37, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3319 value");
ELEM_OPT_TLV( 0x38, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3323 value");
ELEM_OPT_TLV(0x39, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_3, " - T3312 extended value");
ELEM_OPT_TLV(0x66, GSM_A_PDU_TYPE_GM, DE_ADD_NET_FEAT_SUP, NULL);
ELEM_OPT_TLV(0x6A, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3324 value");
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_gmm_rau_com(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_RECV;
ELEM_OPT_TLV( 0x26, GSM_A_PDU_TYPE_GM, DE_REC_N_PDU_NUM_LIST, NULL);
ELEM_OPT_TLV( 0x27, GSM_A_PDU_TYPE_GM, DE_RAT_INFO_CONTAINER, " - Inter RAT handover information");
ELEM_OPT_TLV( 0x2B, GSM_A_PDU_TYPE_GM, DE_EUTRAN_IRAT_INFO_CONTAINER, " - E-UTRAN inter RAT handover information");
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_gmm_rau_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_SENT;
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_GMM_CAUSE, NULL);
ELEM_MAND_VV_SHORT(GSM_A_PDU_TYPE_GM, DE_FORCE_TO_STAND, GSM_A_PDU_TYPE_COMMON, DE_SPARE_NIBBLE);
ELEM_OPT_TLV(0x2A, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3302 value");
ELEM_OPT_TLV(0x3A, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3346 value");
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_gmm_status(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_GMM_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_gmm_information(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_SENT;
ELEM_OPT_TLV( 0x43, GSM_A_PDU_TYPE_DTAP, DE_NETWORK_NAME, " - Full Name" );
ELEM_OPT_TLV( 0x45, GSM_A_PDU_TYPE_DTAP, DE_NETWORK_NAME, " - Short Name" );
ELEM_OPT_TV( 0x46, GSM_A_PDU_TYPE_DTAP, DE_TIME_ZONE, NULL);
ELEM_OPT_TV( 0x47, GSM_A_PDU_TYPE_DTAP, DE_TIME_ZONE_TIME, NULL);
ELEM_OPT_TLV( 0x48, GSM_A_PDU_TYPE_DTAP, DE_LSA_ID, NULL);
ELEM_OPT_TLV( 0x49, GSM_A_PDU_TYPE_DTAP, DE_DAY_SAVING_TIME, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_gmm_service_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_RECV;
ELEM_MAND_VV_SHORT(GSM_A_PDU_TYPE_COMMON, DE_CIPH_KEY_SEQ_NUM, GSM_A_PDU_TYPE_GM, DE_SRVC_TYPE);
ELEM_MAND_LV( GSM_A_PDU_TYPE_COMMON, DE_MID, NULL);
ELEM_OPT_TLV( 0x32, GSM_A_PDU_TYPE_GM, DE_PDP_CONTEXT_STAT, NULL);
ELEM_OPT_TLV( 0x35, GSM_A_PDU_TYPE_GM, DE_MBMS_CTX_STATUS, NULL);
ELEM_OPT_TLV( 0x36, GSM_A_PDU_TYPE_GM, DE_UPLINK_DATA_STATUS, NULL);
ELEM_OPT_TV_SHORT(0xD0, GSM_A_PDU_TYPE_GM, DE_DEVICE_PROPERTIES, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_gmm_service_acc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_SENT;
ELEM_OPT_TLV( 0x32, GSM_A_PDU_TYPE_GM, DE_PDP_CONTEXT_STAT, NULL);
ELEM_OPT_TLV( 0x35, GSM_A_PDU_TYPE_GM, DE_MBMS_CTX_STATUS, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_gmm_service_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_SENT;
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_GMM_CAUSE, NULL);
ELEM_OPT_TLV(0x3A, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_2, " - T3346 value");
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_act_pdp_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_NET_SAPI, " - Requested NSAPI");
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_LLC_SAPI, " - Requested LLC SAPI");
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_QOS, " - Requested QoS" );
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_PD_PRO_ADDR, " - Requested PDP address" );
ELEM_OPT_TLV( 0x28, GSM_A_PDU_TYPE_GM, DE_ACC_POINT_NAME, NULL);
ELEM_OPT_TLV( 0x27, GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT, NULL);
ELEM_OPT_TV_SHORT( 0xA0, GSM_A_PDU_TYPE_GM, DE_REQ_TYPE, NULL);
ELEM_OPT_TV_SHORT(0xC0, GSM_A_PDU_TYPE_GM, DE_DEVICE_PROPERTIES, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_act_pdp_acc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_LLC_SAPI, " - Negotiated LLC SAPI");
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_QOS, " - Negotiated QoS" );
#if 0
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_SPARE, NULL);
curr_offset--;
curr_len++;
#endif
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_RAD_PRIO, NULL);
ELEM_OPT_TLV( 0x2B, GSM_A_PDU_TYPE_GM, DE_PD_PRO_ADDR, " - PDP address");
ELEM_OPT_TLV( 0x27, GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT, NULL);
ELEM_OPT_TLV( 0x34, GSM_A_PDU_TYPE_GM, DE_PACKET_FLOW_ID, NULL);
ELEM_OPT_TLV( 0x39, GSM_A_PDU_TYPE_GM, DE_SM_CAUSE_2, " - SM cause");
ELEM_OPT_TV_SHORT(0xB0 , GSM_A_PDU_TYPE_GM, DE_SM_CONNECTIVITY_TYPE, NULL);
ELEM_OPT_TV_SHORT(0xC0 , GSM_A_PDU_TYPE_GM, DE_SM_WLAN_OFFLOAD_ACCEPT, " - WLAN offload indication");
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_act_pdp_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_SM_CAUSE, NULL);
ELEM_OPT_TLV( 0x27, GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT, NULL);
ELEM_OPT_TLV(0x37, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_3, " - Back-off timer value");
ELEM_OPT_TLV(0x6B, GSM_A_PDU_TYPE_GM, DE_RE_ATTEMPT_IND, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_act_sec_pdp_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_NET_SAPI, " - Requested NSAPI");
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_LLC_SAPI, " - Requested LLC SAPI");
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_QOS, " - Requested QoS" );
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_LINKED_TI, NULL);
ELEM_OPT_TLV( 0x36, GSM_A_PDU_TYPE_GM, DE_TRAFFIC_FLOW_TEMPLATE, NULL);
ELEM_OPT_TLV( 0x27, GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT, NULL);
ELEM_OPT_TV_SHORT(0xC0, GSM_A_PDU_TYPE_GM, DE_DEVICE_PROPERTIES, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_act_sec_pdp_acc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_LLC_SAPI, " - Negotiated LLC SAPI");
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_QOS, " - Negotiated QoS" );
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_RAD_PRIO, NULL);
#if 0
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_SPARE, NULL);
curr_offset--;
curr_len++;
#endif
ELEM_OPT_TLV( 0x34, GSM_A_PDU_TYPE_GM, DE_PACKET_FLOW_ID, NULL);
ELEM_OPT_TLV( 0x27, GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT, NULL);
ELEM_OPT_TV_SHORT(0xC0 , GSM_A_PDU_TYPE_GM, DE_SM_WLAN_OFFLOAD_ACCEPT, " - WLAN offload indication");
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_act_sec_pdp_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_SM_CAUSE, NULL);
ELEM_OPT_TLV( 0x27, GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT, NULL);
ELEM_OPT_TLV(0x37, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_3, " - Back-off timer value");
ELEM_OPT_TLV(0x6B, GSM_A_PDU_TYPE_GM, DE_RE_ATTEMPT_IND, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_req_pdp_act(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_PD_PRO_ADDR, " - Offered PDP address" );
ELEM_OPT_TLV( 0x28, GSM_A_PDU_TYPE_GM, DE_ACC_POINT_NAME, NULL);
ELEM_OPT_TLV( 0x27, GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_req_pdp_act_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_SM_CAUSE, NULL);
ELEM_OPT_TLV( 0x27, GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_mod_pdp_req_net(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_RAD_PRIO, NULL);
#if 0
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_SPARE, NULL);
curr_offset--;
curr_len++;
#endif
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_LLC_SAPI, " - Requested LLC SAPI");
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_QOS, " - New QoS" );
ELEM_OPT_TLV( 0x2B, GSM_A_PDU_TYPE_GM, DE_PD_PRO_ADDR, " - PDP address");
ELEM_OPT_TLV( 0x34, GSM_A_PDU_TYPE_GM, DE_PACKET_FLOW_ID, NULL);
ELEM_OPT_TLV( 0x27, GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT, NULL);
ELEM_OPT_TLV( 0x36, GSM_A_PDU_TYPE_GM, DE_TRAFFIC_FLOW_TEMPLATE, NULL);
ELEM_OPT_TV_SHORT(0xC0 , GSM_A_PDU_TYPE_GM, DE_SM_WLAN_OFFLOAD_ACCEPT, " - WLAN offload indication");
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_mod_pdp_req_ms(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
pinfo->link_dir = P2P_DIR_UL;
ELEM_OPT_TV( 0x32, GSM_A_PDU_TYPE_GM, DE_LLC_SAPI, " - Requested LLC SAPI" );
ELEM_OPT_TLV( 0x30, GSM_A_PDU_TYPE_GM, DE_QOS, " - Requested new QoS" );
ELEM_OPT_TLV( 0x31, GSM_A_PDU_TYPE_GM, DE_TRAFFIC_FLOW_TEMPLATE, " - New TFT" );
ELEM_OPT_TLV( 0x27, GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT, NULL);
ELEM_OPT_TV_SHORT(0xC0, GSM_A_PDU_TYPE_GM, DE_DEVICE_PROPERTIES, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_mod_pdp_acc_ms(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
pinfo->link_dir = P2P_DIR_UL;
ELEM_OPT_TLV( 0x27, GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_mod_pdp_acc_net(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
pinfo->link_dir = P2P_DIR_DL;
ELEM_OPT_TLV( 0x30, GSM_A_PDU_TYPE_GM, DE_QOS, " - Negotiated QoS" );
ELEM_OPT_TV( 0x32, GSM_A_PDU_TYPE_GM, DE_LLC_SAPI, " - Negotiated LLC SAPI" );
ELEM_OPT_TV_SHORT ( 0x80, GSM_A_PDU_TYPE_GM, DE_RAD_PRIO, " - New radio priority" );
ELEM_OPT_TLV( 0x34, GSM_A_PDU_TYPE_GM, DE_PACKET_FLOW_ID, NULL);
ELEM_OPT_TLV( 0x27, GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT, NULL);
ELEM_OPT_TV_SHORT(0xC0 , GSM_A_PDU_TYPE_GM, DE_SM_WLAN_OFFLOAD_ACCEPT, " - WLAN offload indication");
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_mod_pdp_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
pinfo->link_dir = LINK_DIR_UNKNOWN;
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_SM_CAUSE, NULL);
ELEM_OPT_TLV( 0x27, GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT, NULL);
ELEM_OPT_TLV(0x37, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_3, " - Back-off timer value");
ELEM_OPT_TLV(0x6B, GSM_A_PDU_TYPE_GM, DE_RE_ATTEMPT_IND, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_deact_pdp_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
pinfo->link_dir = LINK_DIR_UNKNOWN;
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_SM_CAUSE, NULL);
ELEM_OPT_TV_SHORT( 0x90, GSM_A_PDU_TYPE_GM, DE_TEAR_DOWN_IND, NULL);
ELEM_OPT_TLV( 0x27, GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT, NULL);
ELEM_OPT_TLV( 0x35, GSM_A_PDU_TYPE_GM, DE_MBMS_PROT_CONF_OPT, NULL);
ELEM_OPT_TLV(0x37, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_3, " - T3396 value");
ELEM_OPT_TV_SHORT(0xC0 , GSM_A_PDU_TYPE_GM, DE_SM_WLAN_OFFLOAD_ACCEPT, " - WLAN offload indication");
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_deact_pdp_acc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
pinfo->link_dir = LINK_DIR_UNKNOWN;
ELEM_OPT_TLV( 0x27, GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT, NULL);
ELEM_OPT_TLV( 0x35, GSM_A_PDU_TYPE_GM, DE_MBMS_PROT_CONF_OPT, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_req_sec_pdp_act(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_QOS, " - Required QoS");
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_LINKED_TI, NULL);
ELEM_OPT_TLV( 0x36, GSM_A_PDU_TYPE_GM, DE_TRAFFIC_FLOW_TEMPLATE, NULL);
ELEM_OPT_TLV( 0x27, GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT, NULL);
ELEM_OPT_TV_SHORT(0xC0 , GSM_A_PDU_TYPE_GM, DE_SM_WLAN_OFFLOAD_ACCEPT, " - WLAN offload indication");
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_req_sec_pdp_act_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
pinfo->link_dir = P2P_DIR_UL;
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_SM_CAUSE, NULL);
ELEM_OPT_TLV( 0x27, GSM_A_PDU_TYPE_GM, DE_PRO_CONF_OPT, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_notif(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
pinfo->link_dir = P2P_DIR_DL;
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_SM_NOTIF_IND, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_status(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
pinfo->link_dir = LINK_DIR_UNKNOWN;
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_SM_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_act_mbms_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_RECV;
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_ENH_NSAPI, " - Requested MBMS NSAPI");
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_LLC_SAPI, " - Requested LLC SAPI");
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_MBMS_BEARER_CAP, NULL );
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_PD_PRO_ADDR, " - Requested multicast address" );
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_ACC_POINT_NAME, NULL );
ELEM_OPT_TLV( 0x35, GSM_A_PDU_TYPE_GM, DE_MBMS_PROT_CONF_OPT, NULL);
ELEM_OPT_TV_SHORT(0xC0, GSM_A_PDU_TYPE_GM, DE_DEVICE_PROPERTIES, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_act_mbms_acc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_SENT;
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_TMGI, NULL);
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_LLC_SAPI, " - Negotiated LLC SAPI");
ELEM_OPT_TLV( 0x35, GSM_A_PDU_TYPE_GM, DE_MBMS_PROT_CONF_OPT, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_act_mbms_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_SENT;
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_SM_CAUSE, NULL);
ELEM_OPT_TLV( 0x35, GSM_A_PDU_TYPE_GM, DE_MBMS_PROT_CONF_OPT, NULL);
ELEM_OPT_TLV(0x37, GSM_A_PDU_TYPE_GM, DE_GPRS_TIMER_3, " - T3396 value");
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_req_mbms_act(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_SENT;
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_NET_SAPI, " - Linked NSAPI");
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_PD_PRO_ADDR, " - Offered multicast address" );
ELEM_MAND_LV( GSM_A_PDU_TYPE_GM, DE_ACC_POINT_NAME, NULL );
ELEM_OPT_TLV( 0x35, GSM_A_PDU_TYPE_GM, DE_MBMS_PROT_CONF_OPT, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
static void
dtap_sm_req_mbms_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
pinfo->p2p_dir = P2P_DIR_RECV;
ELEM_MAND_V( GSM_A_PDU_TYPE_GM, DE_SM_CAUSE, NULL);
ELEM_OPT_TLV( 0x35, GSM_A_PDU_TYPE_GM, DE_MBMS_PROT_CONF_OPT, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0, pinfo, &ei_gsm_a_gm_extraneous_data);
}
void
get_gmm_msg_params(guint8 oct, const gchar **msg_str, int *ett_tree, int *hf_idx, msg_fcn *dtap_msg_fcn)
{
gint idx;
*msg_str = try_val_to_str_idx_ext((guint32) (oct & DTAP_GMM_IEI_MASK), &gsm_a_dtap_msg_gmm_strings_ext, &idx);
*hf_idx = hf_gsm_a_dtap_msg_gmm_type;
if (*msg_str != NULL) {
*ett_tree = ett_gsm_dtap_msg_gmm[idx];
*dtap_msg_fcn = dtap_msg_gmm_fcn[idx];
}
return;
}
void
get_sm_msg_params(guint8 oct, const gchar **msg_str, int *ett_tree, int *hf_idx, msg_fcn *dtap_msg_fcn)
{
gint idx;
*msg_str = try_val_to_str_idx_ext((guint32) (oct & DTAP_SM_IEI_MASK), &gsm_a_dtap_msg_sm_strings_ext, &idx);
*hf_idx = hf_gsm_a_dtap_msg_sm_type;
if (*msg_str != NULL) {
*ett_tree = ett_gsm_dtap_msg_sm[idx];
*dtap_msg_fcn = dtap_msg_sm_fcn[idx];
}
return;
}
void
proto_register_gsm_a_gm(void)
{
guint i;
guint last_offset;
static hf_register_info hf[] = {
{ &hf_gsm_a_dtap_msg_gmm_type,
{ "DTAP GPRS Mobility Management Message Type", "gsm_a.dtap.msg_gmm_type",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &gsm_a_dtap_msg_gmm_strings_ext, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_dtap_msg_sm_type,
{ "DTAP GPRS Session Management Message Type", "gsm_a.dtap.msg_sm_type",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &gsm_a_dtap_msg_sm_strings_ext, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_elem_id,
{ "Element ID", "gsm_a.gm.elem_id",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_delay_cls,
{ "Quality of Service Delay class", "gsm_a.gm.sm.qos.delay_cls",
FT_UINT8, BASE_DEC, VALS(gsm_a_sm_qos_delay_cls_vals), 0x38,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_reliability_cls,
{ "Reliability class", "gsm_a.gm.sm.qos.reliability_cls",
FT_UINT8, BASE_DEC, VALS(gsm_a_sm_qos_reliability_vals), 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_traffic_cls,
{ "Traffic class", "gsm_a.gm.sm.qos.traffic_cls",
FT_UINT8, BASE_DEC, VALS(gsm_a_sm_qos_traffic_cls_vals), 0xe0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_del_order,
{ "Delivery order", "gsm_a.gm.sm.qos.del_order",
FT_UINT8, BASE_DEC, VALS(gsm_a_sm_qos_del_order_vals), 0x18,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_del_of_err_sdu,
{ "Delivery of erroneous SDUs", "gsm_a.gm.sm.qos.del_of_err_sdu",
FT_UINT8, BASE_DEC, VALS(gsm_a_sm_qos_del_of_err_sdu_vals), 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_ber,
{ "Residual Bit Error Rate (BER)", "gsm_a.gm.sm.qos.ber",
FT_UINT8, BASE_DEC, VALS(gsm_a_sm_qos_ber_vals), 0xf0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_sdu_err_rat,
{ "SDU error ratio", "gsm_a.gm.sm.qos.sdu_err_rat",
FT_UINT8, BASE_DEC, VALS(gsm_a_sm_qos_sdu_err_rat_vals), 0x0f,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_traff_hdl_pri,
{ "Traffic handling priority", "gsm_a.gm.sm.qos.traff_hdl_pri",
FT_UINT8, BASE_DEC, VALS(gsm_a_sm_qos_traff_hdl_pri_vals), 0x03,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_split_pg_cycle_code,
{ "SPLIT PG CYCLE CODE", "gsm_a.gm.gmm.split_pg_cycle_code",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &gsm_a_gmm_split_pg_cycle_code_strings_ext, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_split_on_ccch,
{ "SPLIT on CCCH", "gsm_a.gm.gmm.split_on_ccch",
FT_BOOLEAN, 8, TFS(&gsm_a_gmm_split_on_ccch_value), 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_non_drx_timer,
{ "Non-DRX timer", "gsm_a.gm.gmm.non_drx_timer",
FT_UINT8, BASE_DEC, VALS(gsm_a_gmm_non_drx_timer_strings), 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_cn_spec_drx_cycle_len_coef,
{ "CN Specific DRX cycle length coefficient", "gsm_a.gm.gmm.cn_spec_drx_cycle_len_coef",
FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(gsm_a_gmm_cn_spec_drx_cycle_len_coef_strings), 0xf0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_tft_op_code,
{ "TFT operation code", "gsm_a.gm.sm.tft.op_code",
FT_UINT8, BASE_DEC, VALS(gsm_a_sm_tft_op_code_vals), 0xe0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_tft_e_bit,
{ "E bit", "gsm_a.gm.sm.tft.e_bit",
FT_BOOLEAN, 8, TFS(&gsm_a_sm_tft_e_bit), 0x10,
NULL, HFILL }
},
{ &hf_gsm_a_sm_tft_pkt_flt,
{ "Number of packet filters", "gsm_a.gm.sm.tft.pkt_flt",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_gsm_a_sm_tft_pkt_flt_dir,
{ "Packet filter direction", "gsm_a.gm.sm.tft.pkt_flt_dir",
FT_UINT8, BASE_DEC, VALS(gsm_a_sm_tft_pkt_flt_dir_vals), 0x30,
NULL, HFILL }
},
{ &hf_gsm_a_sm_tft_pkt_flt_id,
{ "Packet filter identifier", "gsm_a.gm.sm.tft.pkt_flt_id",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_gsm_a_sm_ip4_address,
{ "IPv4 address", "gsm_a.gm.sm.ip4_address",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_ip4_mask,
{ "IPv4 address mask", "gsm_a.gm.sm.ip4_mask",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_ip6_address,
{ "IPv6 address", "gsm_a.gm.sm.ip6_address",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_ip6_mask,
{ "IPv6 address mask", "gsm_a.gm.sm.ip6_mask",
FT_IPv6, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_ip6_prefix_length,
{ "IPv6 prefix length", "gsm_a.gm.sm.ip6_prefix_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_tft_protocol_header,
{ "Protocol/header", "gsm_a.gm.sm.tft.protocol_header",
FT_UINT8, BASE_HEX|BASE_EXT_STRING, &ipproto_val_ext, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_tft_port,
{ "Port", "gsm_a.gm.sm.tft.port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_tft_port_low,
{ "Low limit port", "gsm_a.gm.sm.tft.port_low",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_tft_port_high,
{ "High limit port", "gsm_a.gm.sm.tft.port_high",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_tft_security,
{ "IPSec security parameter index", "gsm_a.gm.sm.tft.security",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_tft_traffic_class,
{ "Type of service/Traffic class field", "gsm_a.gm.sm.tft.traffic_class",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_tft_traffic_mask,
{ "Mask field", "gsm_a.gm.sm.tft.traffic_mask",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_tft_flow_label_type,
{ "Flow Label Type", "gsm_a.gm.sm.tft.flow_label_type",
FT_UINT24, BASE_HEX, NULL, 0x0FFFFF,
NULL, HFILL }
},
{ &hf_gsm_a_sm_tft_param_id,
{ "Parameter identifier", "gsm_a.gm.sm.tft.param_id",
FT_UINT8, BASE_DEC, VALS(gsm_a_sm_tft_param_id_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_ptmsi_sig,
{ "P-TMSI Signature", "gsm_a.gm.gmm.ptmsi_sig",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_ptmsi_sig2,
{ "P-TMSI Signature 2", "gsm_a.gm.gmm.ptmsi_sig2",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_acc_tech_type,
{ "Access Technology Type", "gsm_a.gm.gmm.acc_tech_type",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_acc_tech_type_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_acc_cap_struct_len,
{ "Length in bits", "gsm_a.gm.gmm.acc_cap_struct_len",
FT_UINT8, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_sms_value,
{ "SMS_VALUE (Switch-Measure-Switch)", "gsm_a.gm.gmm.sms",
FT_UINT8, BASE_DEC, VALS(gsm_a_sms_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_sm_value,
{ "(SM_VALUE) Switch-Measure", "gsm_a.gm.gmm.sm",
FT_UINT8, BASE_DEC, VALS(gsm_a_sms_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_link_dir,
{ "Link direction", "gsm_a.gm.sm.link_dir",
FT_INT32, BASE_DEC, VALS(gsm_a_gm_link_dir_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_cause,
{ "GMM Cause", "gsm_a.gm.gmm.cause",
FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(gmm_cause_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_add_upd_type,
{ "Additional update type", "gsm_a.gm.gmm.add_upd_type",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_gm_add_upd_type_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_fop,
{ "Follow-on proceed", "gsm_a.gm.gmm.fop",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_gm_res_of_attach,
{ "Result of attach", "gsm_a.gm.gmm.res_of_attach",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_res_of_attach_vals), 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_gm_type_of_ciph_alg,
{ "Type of ciphering algorithm", "gsm_a.gm.gmm.type_of_ciph_alg",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_type_of_ciph_alg_vals), 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_gm_imeisv_req,
{ "IMEISV request", "gsm_a.gm.gmm.imeisv_req",
FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(gsm_a_gm_imeisv_req_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_gm_nsapi,
{ "NSAPI", "gsm_a.gm.gmm.nsapi",
FT_UINT16, BASE_HEX_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_ac_ref_nr,
{ "A&C reference number", "gsm_a.gm.gmm.ac_ref_nr",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_force_to_standby,
{ "Force to standby", "gsm_a.gm.gmm.force_to_standby",
FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(gsm_a_gm_force_to_standby_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_gm_serv_type,
{ "Service type", "gsm_a.gm.gmm.serv_type",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_serv_type_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_gm_for,
{ "Follow-on request pending", "gsm_a.gm.gmm.for",
FT_BOOLEAN, 8, NULL, 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_gm_type_of_attach,
{ "Type of attach", "gsm_a.gm.gmm.type_of_attach",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_type_of_attach_vals), 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_gm_tmsi_flag,
{ "TMSI flag", "gsm_a.gm.gmm.tmsi_flag",
FT_BOOLEAN, 8, TFS(&gsm_a_gm_tmsi_flag_value), 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_gm_power_off,
{ "Power off", "gsm_a.gm.gmm.power_off",
FT_BOOLEAN, 8, TFS(&gsm_a_gm_power_off_value), 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_gm_type_of_detach_mo,
{ "Type of detach", "gsm_a.gm.gmm.type_of_detach",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_type_of_detach_mo_vals), 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_gm_type_of_detach_mt,
{ "Type of detach", "gsm_a.gm.gmm.type_of_detach",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_type_of_detach_mt_vals), 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_gm_update_type,
{ "Update type", "gsm_a.gm.gmm.update_type",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_update_type_vals), 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_gm_gprs_timer,
{ "GPRS Timer", "gsm_a.gm.gmm.gprs_timer",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_gprs_timer_unit,
{ "Unit", "gsm_a.gm.gmm.gprs_timer_unit",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_gprs_timer_unit_vals), 0xe0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_gprs_timer_value,
{ "Timer value", "gsm_a.gm.gmm.gprs_timer_value",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_gsm_a_gm_gprs_timer2,
{ "GPRS Timer", "gsm_a.gm.gmm.gprs_timer2",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_gprs_timer2_unit,
{ "Unit", "gsm_a.gm.gmm.gprs_timer2_unit",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_gprs_timer_unit_vals), 0xe0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_gprs_timer2_value,
{ "Timer value", "gsm_a.gm.gmm.gprs_timer2_value",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_gsm_a_gm_gprs_timer3,
{ "GPRS Timer", "gsm_a.gm.gmm.gprs_timer3",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_gprs_timer3_unit,
{ "Unit", "gsm_a.gm.gmm.gprs_timer3_unit",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_gprs_timer3_unit_vals), 0xe0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_gprs_timer3_value,
{ "Timer value", "gsm_a.gm.gmm.gprs_timer3_value",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_gsm_a_gm_nsapi_5_ul_stat,
{ "NSAPI(5) uplink status", "gsm_a.gm.gmm.nsapi_5_ul_stat",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_gm_nsapi_ul_stat_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_nsapi_6_ul_stat,
{ "NSAPI(6) uplink status", "gsm_a.gm.gmm.nsapi_6_ul_stat",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_gm_nsapi_ul_stat_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_nsapi_7_ul_stat,
{ "NSAPI(7) uplink status", "gsm_a.gm.gmm.nsapi_7_ul_stat",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_gm_nsapi_ul_stat_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_nsapi_8_ul_stat,
{ "NSAPI(8) uplink status", "gsm_a.gm.gmm.nsapi_8_ul_stat",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_gm_nsapi_ul_stat_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_nsapi_9_ul_stat,
{ "NSAPI(9) uplink status", "gsm_a.gm.gmm.nsapi_9_ul_stat",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_gm_nsapi_ul_stat_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_nsapi_10_ul_stat,
{ "NSAPI(10) uplink status", "gsm_a.gm.gmm.nsapi_10_ul_stat",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_gm_nsapi_ul_stat_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_nsapi_11_ul_stat,
{ "NSAPI(11) uplink status", "gsm_a.gm.gmm.nsapi_11_ul_stat",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_gm_nsapi_ul_stat_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_nsapi_12_ul_stat,
{ "NSAPI(12) uplink status", "gsm_a.gm.gmm.nsapi_12_ul_stat",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_gm_nsapi_ul_stat_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_nsapi_13_ul_stat,
{ "NSAPI(13) uplink status", "gsm_a.gm.gmm.nsapi_13_ul_stat",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_gm_nsapi_ul_stat_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_nsapi_14_ul_stat,
{ "NSAPI(14) uplink status", "gsm_a.gm.gmm.nsapi_14_ul_stat",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_gm_nsapi_ul_stat_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_nsapi_15_ul_stat,
{ "NSAPI(15) uplink status", "gsm_a.gm.gmm.nsapi_15_ul_stat",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_gm_nsapi_ul_stat_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_device_prop_low_prio,
{ "Low priority", "gsm_a.gm.gmm.device_prop_low_prio",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_gm_device_prop_low_prio_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_apn,
{ "APN", "gsm_a.gm.sm.apn",
FT_STRING,BASE_NONE, NULL,0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_pco_pid,
{ "Protocol or Container ID", "gsm_a.gm.sm.pco_pid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_pco_app_spec_info,
{ "Application specific information", "gsm_a.gm.sm.app_spec_info",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_type_of_identity,
{ "Type of identity", "gsm_a.gm.gmm.type_of_identity",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_type_of_identity_vals), 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac,
{ "Routing Area Code (RAC)", "gsm_a.gm.gmm.rac",
FT_UINT8, BASE_HEX_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_gm_apc,
{ "APC", "gsm_a.gm.gmm.apc",
FT_BOOLEAN, 8, TFS(&gsm_a_gm_apc_vals), 0x20,
NULL, HFILL }
},
{ &hf_gsm_a_gm_otd_a,
{ "OTD-A", "gsm_a.gm.gmm.otd_a",
FT_BOOLEAN, 8, TFS(&gsm_a_gm_otd_a_vals), 0x10,
NULL, HFILL }
},
{ &hf_gsm_a_gm_otd_b,
{ "OTD-B", "gsm_a.gm.gmm.otd_b",
FT_BOOLEAN, 8, TFS(&gsm_a_gm_otd_b_vals), 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_gm_gps_a,
{ "GPS-A", "gsm_a.gm.gmm.gps_a",
FT_BOOLEAN, 8, TFS(&gsm_a_gm_gps_a_vals), 0x04,
NULL, HFILL }
},
{ &hf_gsm_a_gm_gps_b,
{ "GPS-B", "gsm_a.gm.gmm.gps_b",
FT_BOOLEAN, 8, TFS(&gsm_a_gm_gps_b_vals), 0x02,
NULL, HFILL }
},
{ &hf_gsm_a_gm_gps_c,
{ "GPS-C", "gsm_a.gm.gmm.gps_c",
FT_BOOLEAN, 8, TFS(&gsm_a_gm_gps_c_vals), 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_gm_lcs_molr,
{ "LCS-MOLR", "gsm_a.gm.gmm.lcs_molr",
FT_BOOLEAN, 8, TFS(&gsm_a_gm_lcs_molr_value), 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_gm_mbms,
{ "MBMS", "gsm_a.gm.gmm.mbms",
FT_BOOLEAN, 8, TFS(&tfs_supported_not_supported), 0x04,
NULL, HFILL }
},
{ &hf_gsm_a_gm_ims_vops,
{ "IMS VoPS", "gsm_a.gm.gmm.ims_vops",
FT_BOOLEAN, 8, TFS(&gsm_a_gm_ims_vops_value), 0x02,
"IMS voice over PS session indicator", HFILL }
},
{ &hf_gsm_a_gm_emc_bs,
{ "EMC BS", "gsm_a.gm.gmm.emc_bs",
FT_BOOLEAN, 8, TFS(&gsm_a_gm_emc_bs_value), 0x01,
"Emergency bearer services indicator", HFILL }
},
{ &hf_gsm_a_gm_gprs_sms,
{ "GPRS-SMS", "gsm_a.gm.gmm.gprs_sms",
FT_BOOLEAN, 8, TFS(&gsm_a_gm_gprs_sms_value), 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_gm_req_ms_info_irat,
{ "I-RAT", "gsm_a.gm.gmm.req_ms_info_irat",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_gm_req_ms_info_irat_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_req_ms_info_irat2,
{ "I-RAT2", "gsm_a.gm.gmm.req_ms_info_irat2",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_gm_req_ms_info_irat2_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_ue_usage_setting,
{ "UE's usage setting", "gsm_a.gm.gmm.ue_usage_setting",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_gm_ue_usage_setting_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_voice_domain_pref_for_eutran,
{ "Voice domain preference for E-UTRAN", "gsm_a.gm.gmm.voice_domain_pref_for_eutran",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_voice_domain_pref_for_eutran_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_ptmsi_type,
{ "P-TMSI type", "gsm_a.gm.gmm.ptmsi_type",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_gm_ptmsi_type_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_nri_cont,
{ "NRI container value", "gsm_a.gm.gmm.nri_cont_value",
FT_UINT16, BASE_HEX, NULL, 0xffc0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_pdp_type_org,
{ "PDP type organization", "gsm_a.gm.sm.pdp_type_org",
FT_UINT8, BASE_DEC, VALS(gsm_a_sm_pdp_type_org_vals), 0x0f,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_mean_thr,
{ "Mean throughput", "gsm_a.gm.sm.qos.mean_throughput",
FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(gsm_a_sm_qos_mean_thr_vals), 0x1f,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_peak_thr,
{ "Peak throughput", "gsm_a.gm.sm.qos.peak_throughput",
FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(gsm_a_sm_qos_peak_thr_vals), 0xf0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_prec_class,
{ "Precedence class", "gsm_a.gm.sm.qos.prec_class",
FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(gsm_a_sm_qos_prec_class_vals), 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_trans_delay,
{ "Transfer delay", "gsm_a.gm.sm.qos.trans_delay",
FT_UINT8, BASE_DEC, NULL, 0xfc,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_signalling_ind,
{ "Signalling indication", "gsm_a.gm.sm.qos.signalling_ind",
FT_BOOLEAN, 8, TFS(&gsm_a_sm_qos_signalling_ind_value), 0x10,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_source_stat_desc,
{ "Source statistics description", "gsm_a.gm.sm.qos.source_stat_desc",
FT_UINT8, BASE_DEC, NULL, 0x0f,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_max_bitrate_upl,
{ "Maximum bitrate for uplink", "gsm_a.gm.sm.qos.max_bitrate_upl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_max_bitrate_downl,
{ "Maximum bitrate for downlink", "gsm_a.gm.sm.qos.max_bitrate_downl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_guar_bitrate_upl,
{ "Guaranteed bitrate for uplink", "gsm_a.gm.sm.qos.guar_bitrate_upl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_guar_bitrate_downl,
{ "Guaranteed bitrate for downlink", "gsm_a.gm.sm.qos.guar_bitrate_downl",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_max_bitrate_upl_ext,
{ "Maximum bitrate for uplink (extended)", "gsm_a.gm.sm.qos.max_bitrate_upl_ext",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_max_bitrate_downl_ext,
{ "Maximum bitrate for downlink (extended)", "gsm_a.gm.sm.qos.max_bitrate_downl_ext",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_guar_bitrate_upl_ext,
{ "Guaranteed bitrate for uplink (extended)", "gsm_a.gm.sm.qos.guar_bitrate_upl_ext",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_guar_bitrate_downl_ext,
{ "Guaranteed bitrate for downlink (extended)", "gsm_a.gm.sm.qos.guar_bitrate_downl_ext",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_max_bitrate_upl_ext2,
{ "Maximum bitrate for uplink (extended-2)", "gsm_a.gm.sm.qos.max_bitrate_upl_ext2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_max_bitrate_downl_ext2,
{ "Maximum bitrate for downlink (extended-2)", "gsm_a.gm.sm.qos.max_bitrate_downl_ext2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_guar_bitrate_upl_ext2,
{ "Guaranteed bitrate for uplink (extended-2)", "gsm_a.gm.sm.qos.guar_bitrate_upl_ext2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_qos_guar_bitrate_downl_ext2,
{ "Guaranteed bitrate for downlink (extended-2)", "gsm_a.gm.sm.qos.guar_bitrate_downl_ext2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_ratc,
{ "RATC", "gsm_a.gm.sm.re_attempt_ind.ratc",
FT_BOOLEAN, 8, TFS(&gsm_a_gm_ratc_value), 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_sm_cause,
{ "SM Cause", "gsm_a.gm.sm.cause",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_cause_2,
{ "SM Cause 2", "gsm_a.gm.sm.cause_2",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_llc_sapi,
{ "LLC SAPI", "gsm_a.gm.sm.llc_sapi",
FT_UINT8, BASE_DEC, VALS(gsm_a_sm_llc_sapi_vals), 0x0f,
NULL, HFILL }
},
{ &hf_gsm_a_sm_tdi,
{ "Tear Down Indicator (TDI)", "gsm_a.gm.sm.tdi",
FT_BOOLEAN, 8, TFS(&gsm_a_sm_tdi_value), 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_sm_packet_flow_id,
{ "Packet Flow Identifier (PFI)", "gsm_a.gm.sm.packet_flow_id",
FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(gsm_a_sm_packet_flow_id_vals), 0x7f,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_cap_gea1,
{ "GEA/1", "gsm_a.gm.gmm.net_cap.gea1",
FT_BOOLEAN, 8, TFS(&gsm_a_gmm_net_cap_gea_vals), 0x80,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_cap_smdch,
{ "SM capabilities via dedicated channels", "gsm_a.gm.gmm.net_cap.smdch",
FT_BOOLEAN, 8, TFS(&gsm_a_gmm_net_cap_smdch_vals), 0x40,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_cap_smgprs,
{ "SM capabilities via GPRS channels", "gsm_a.gm.gmm.net_cap.smgprs",
FT_BOOLEAN, 8, TFS(&gsm_a_gmm_net_cap_smgprs_vals), 0x20,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_cap_ucs2,
{ "UCS2 support", "gsm_a.gm.gmm.net_cap.ucs2",
FT_BOOLEAN, 8, TFS(&gsm_a_gmm_net_cap_ucs2_vals), 0x10,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_cap_ss_scr_ind,
{ "SS Screening Indicator", "gsm_a.gm.gmm.net_cap.ss_scr_ind",
FT_UINT8, BASE_HEX, VALS(gsm_a_gmm_net_cap_ss_scr_ind_vals), 0x0c,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_cap_solsa,
{ "SoLSA Capability", "gsm_a.gm.gmm.net_cap.solsa",
FT_BOOLEAN, 8, TFS(&gsm_a_gmm_net_cap_solsa_vals), 0x02,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_cap_rev,
{ "Revision level indicator", "gsm_a.gm.gmm.net_cap.rev",
FT_BOOLEAN, 8, TFS(&gsm_a_gmm_net_cap_rev_vals), 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_cap_pfc,
{ "PFC feature mode", "gsm_a.gm.gmm.net_cap.pfc",
FT_BOOLEAN, 8, TFS(&gsm_a_gmm_net_cap_pfc_vals), 0x80,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_cap_ext_gea_bits,
{ "Extended GEA bits", "gsm_a.gm.gmm.net_cap.ext_gea_bits",
FT_UINT8, BASE_HEX, NULL, 0x7e,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_cap_gea2,
{ "GEA/2", "gsm_a.gm.gmm.net_cap.gea2",
FT_BOOLEAN, 8, TFS(&gsm_a_gmm_net_cap_gea_vals), 0x40,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_cap_gea3,
{ "GEA/3", "gsm_a.gm.gmm.net_cap.gea3",
FT_BOOLEAN, 8, TFS(&gsm_a_gmm_net_cap_gea_vals), 0x20,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_cap_gea4,
{ "GEA/4", "gsm_a.gm.gmm.net_cap.gea4",
FT_BOOLEAN, 8, TFS(&gsm_a_gmm_net_cap_gea_vals), 0x10,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_cap_gea5,
{ "GEA/5", "gsm_a.gm.gmm.net_cap.gea5",
FT_BOOLEAN, 8, TFS(&gsm_a_gmm_net_cap_gea_vals), 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_cap_gea6,
{ "GEA/6", "gsm_a.gm.gmm.net_cap.gea6",
FT_BOOLEAN, 8, TFS(&gsm_a_gmm_net_cap_gea_vals), 0x04,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_cap_gea7,
{ "GEA/7", "gsm_a.gm.gmm.net_cap.gea7",
FT_BOOLEAN, 8, TFS(&gsm_a_gmm_net_cap_gea_vals), 0x02,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_cap_lcs,
{ "LCS VA capability", "gsm_a.gm.gmm.net_cap.lcs",
FT_BOOLEAN, 8, TFS(&gsm_a_gmm_net_cap_lcs_vals), 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_cap_ps_irat_iu,
{ "PS inter-RAT HO from GERAN to UTRAN Iu mode capability", "gsm_a.gm.gmm.net_cap.ps_irat_iu",
FT_BOOLEAN, 8, TFS(&gsm_a_gmm_net_cap_ps_irat_iu_vals), 0x80,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_cap_ps_irat_s1,
{ "PS inter-RAT HO from GERAN to E-UTRAN S1 mode capability", "gsm_a.gm.gmm.net_cap.ps_irat_s1",
FT_BOOLEAN, 8, TFS(&gsm_a_gmm_net_cap_ps_irat_s1_vals), 0x40,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_cap_comb_proc,
{ "EMM Combined procedures capability", "gsm_a.gm.gmm.net_cap.comb_proc",
FT_BOOLEAN, 8, TFS(&gsm_a_gmm_net_cap_comb_proc_vals), 0x20,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_cap_isr,
{ "ISR support", "gsm_a.gm.gmm.net_cap.isr",
FT_BOOLEAN, 8, TFS(&gsm_a_gmm_net_cap_isr_vals), 0x10,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_cap_srvcc_to_geran,
{ "SRVCC to GERAN/UTRAN capability", "gsm_a.gm.gmm.net_cap.srvcc_to_geran",
FT_BOOLEAN, 8, TFS(&gsm_a_gmm_net_cap_srvcc_to_geran_vals), 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_cap_epc,
{ "EPC capability", "gsm_a.gm.gmm.net_cap.epc",
FT_BOOLEAN, 8, TFS(&gsm_a_gmm_net_cap_epc_vals), 0x04,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_cap_nf,
{ "NF capability", "gsm_a.gm.gmm.net_cap.nf",
FT_BOOLEAN, 8, TFS(&gsm_a_gmm_net_cap_nf_vals), 0x02,
NULL, HFILL }
},
{ &hf_gsm_a_gmm_net_geran_net_sharing,
{ "GERAN network sharing capability", "gsm_a.gm.gmm.net_cap.geran_net_sharing",
FT_BOOLEAN, 8, TFS(&gsm_a_gmm_net_geran_net_vals), 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_sm_tmgi,
{ "Temporary Mobile Group Identity (TMGI)", "gsm_a.gm.sm.tmgi",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_enh_nsapi,
{ "Enhanced NSAPI", "gsm_a.gm.sm.enh_nsapi",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_req_type,
{ "Request type", "gsm_a.gm.sm.req_type",
FT_UINT8, BASE_DEC, VALS(gsm_a_sm_req_type_vals), 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_sm_notif_ind,
{ "Notification indicator", "gsm_a.gm.sm.notif_ind",
FT_UINT8, BASE_DEC, VALS(gsm_a_sm_notif_ind_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_connectivity_type,
{ "Connectivity type", "gsm_a.gm.sm.connectivity_type",
FT_UINT8, BASE_DEC|BASE_RANGE_STRING, RVALS(gsm_a_sm_connectivity_type_vals), 0x0F,
NULL, HFILL }
},
{ &hf_gsm_a_sm_wlan_utran_offload_accept,
{ "WLAN UTRAN offload acceptability", "gsm_a.gm.sm.wlan_utran_offload_accept",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_sm_wlan_utran_offload_accept_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_wlan_eutran_offload_accept,
{ "WLAN E-UTRAN offload acceptability", "gsm_a.gm.sm.wlan_eutran_offload_accept",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_sm_wlan_eutran_offload_accept_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_ctrled_early_cm_sending,
{ "Controlled early Classmark Sending", "gsm_a.gm.gmm.rac.ctrled_early_cm_sending",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_implemented_not_implemented), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_pseudo_sync,
{ "Pseudo Synchronisation", "gsm_a.gm.gmm.rac.pseudo_sync",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_present_not_present), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_vgcs,
{ "Voice Group Call Service", "gsm_a.gm.gmm.rac.vgcs",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_gm_vgcs), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_vbs,
{ "Voice Broadcast Service", "gsm_a.gm.gmm.rac.vbs",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_gm_vbs), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_multislot_capability,
{ "Multislot capability struct", "gsm_a.gm.gmm.rac.multislot_capability",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_present_not_present), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_hscsd_multi_slot_class,
{ "HSCSD multislot class", "gsm_a.gm.gmm.rac.hscsd_multi_slot_class",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_multi_slot_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_gprs_multi_slot_class,
{ "GPRS multislot class", "gsm_a.gm.gmm.rac.gprs_multi_slot_class",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_multi_slot_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_gprs_ext_dyn_alloc_cap,
{ "GPRS Extended Dynamic Allocation Capability", "gsm_a.gm.gmm.rac.gprs_ext_dyn_alloc_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_implemented_not_implemented), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_ecsd_multi_slot_class,
{ "ECSD multislot class", "gsm_a.gm.gmm.rac.ecsd_multi_slot_class",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_multi_slot_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_egprs_multi_slot_class,
{ "EGPRS multislot class", "gsm_a.gm.gmm.rac.egprs_multi_slot_class",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_multi_slot_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_egprs_ext_dyn_alloc_cap,
{ "EGPRS Extended Dynamic Allocation Capability", "gsm_a.gm.gmm.rac.egprs_ext_dyn_alloc_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_implemented_not_implemented), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_dtm_gprs_multi_slot_class,
{ "DTM GPRS Multi Slot Class", "gsm_a.gm.gmm.rac.dtm_gprs_multi_slot_class",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_dtm_gprs_multi_slot_class_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_single_slt_dtm,
{ "Single Slot DTM", "gsm_a.gm.gmm.rac.single_slt_dtm",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_dtm_egprs_multi_slot_cls_pres,
{ "DTM EGPRS Multi Slot Class", "gsm_a.gm.gmm.rac.dtm_egprs_multi_slot_cls_pres",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_present_not_present), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_dtm_egprs_multi_slot_class,
{ "DTM EGPRS Multi Slot Class", "gsm_a.gm.gmm.rac.dtm_egprs_multi_slot_class",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_dtm_gprs_multi_slot_class_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_8psk_pow_cap_pres,
{ "8PSK Power Capability Bits", "gsm_a.gm.gmm.rac.8psk_pow_cap_pres",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_present_not_present), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_comp_int_meas_cap,
{ "COMPACT Interference Measurement Capability", "gsm_a.gm.gmm.rac.comp_int_meas_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_implemented_not_implemented), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rel_lev_ind,
{ "Revision Level Indicator", "gsm_a.gm.gmm.rel_lev_ind",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_gm_revision_level_indicator), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_umts_fdd_cap,
{ "UMTS FDD Radio Access Technology Capability", "gsm_a.gm.gmm.rac.umts_fdd_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_umts_384_tdd_ra_cap,
{ "UMTS 3.84 Mcps TDD Radio Access Technology Capability", "gsm_a.gm.gmm.rac.umts_384_tdd_ra_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_cdma2000_cap,
{ "CDMA 2000 Radio Access Technology Capability", "gsm_a.gm.gmm.rac.cdma2000_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_umts_128_tdd_ra_cap,
{ "UMTS 1.28 Mcps TDD Radio Access Technology Capability", "gsm_a.gm.gmm.rac.umts_128_tdd_ra_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_geran_feat_pkg,
{ "GERAN Feature Package 1", "gsm_a.gm.gmm.rac.geran_feat_pkg",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_mod_based_multi_slot_class_support,
{ "Modulation based multislot class support", "gsm_a.gm.gmm.rac.mod_based_multi_slot_class_support",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_geran_iu_mode_cap,
{ "GERAN Iu mode", "gsm_a.gm.gmm.rac.geran_iu_mode_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_flo_iu_cap,
{ "FLO Iu Capability", "gsm_a.gm.gmm.rac.flo_iu_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_mult_tbf_cap,
{ "Multiple TBF Capability", "gsm_a.gm.gmm.rac.mult_tbf_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_down_adv_rec_perf,
{ "Downlink Advanced Receiver Performance", "gsm_a.gm.gmm.rac.down_adv_rec_perf",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_down_adv_rec_perf_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_ext_rlc_mac_ctrl_msg_seg_cap,
{ "Extended RLC/MAC Control Message Segmentation Capability", "gsm_a.gm.gmm.rac.ext_rlc_mac_ctrl_msg_seg_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_dtm_enh_cap,
{ "DTM Enhancements Capability", "gsm_a.gm.gmm.rac.dtm_enh_cap",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_gm_dtm_enh_cap), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_dtm_gprs_high_multi_slot_class,
{ "DTM GPRS High Multi Slot Class", "gsm_a.gm.gmm.rac.dtm_gprs_high_multi_slot_class",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_dtm_gprs_high_multi_slot_class_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_dtm_egprs_high_multi_slot_class,
{ "DTM EGPRS High Multi Slot Class", "gsm_a.gm.gmm.rac.dtm_egprs_high_multi_slot_class",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_dtm_gprs_high_multi_slot_class_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_ps_ho_cap,
{ "PS Handover Capability", "gsm_a.gm.gmm.rac.ps_ho_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_dtm_ho_cap,
{ "DTM Handover Capability", "gsm_a.gm.gmm.rac.dtm_ho_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_multi_slot_cap_red_down_dual_carrier,
{ "Multislot Capability Reduction for Downlink Dual Carrier", "gsm_a.gm.gmm.rac.multi_slot_cap_red_down_dual_carrier",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_multi_slot_cap_red_down_dual_carrier_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_down_dual_carrier_dtm_cap,
{ "Downlink Dual Carrier for DTM Capability", "gsm_a.gm.gmm.rac.down_dual_carrier_dtm_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_flex_ts_assign,
{ "Flexible Timeslot Assignment", "gsm_a.gm.gmm.rac.flex_ts_assign",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_gan_ps_ho_cap,
{ "GAN PS Handover Capability", "gsm_a.gm.gmm.rac.gan_ps_ho_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_rlc_non_pers_mode,
{ "RLC Non-persistent Mode", "gsm_a.gm.gmm.rac.rlc_non_pers_mode",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_reduced_lat_cap,
{ "Reduced Latency Capability", "gsm_a.gm.gmm.rac.reduced_lat_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_ul_egprs2,
{ "Uplink EGPRS2", "gsm_a.gm.gmm.rac.ul_egprs2",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_ul_egprs2_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_dl_egprs2,
{ "Downlink EGPRS2", "gsm_a.gm.gmm.rac.dl_egprs2",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_dl_egprs2_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_eutra_fdd_support,
{ "E-UTRA FDD support", "gsm_a.gm.gmm.rac.eutra_fdd_support",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_eutra_tdd_support,
{ "E-UTRA TDD support", "gsm_a.gm.gmm.rac.eutra_tdd_support",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_geran_to_eutra_support_in_geran_ptm,
{ "GERAN to E-UTRA support in GERAN packet transfer mode", "gsm_a.gm.gmm.rac.geran_to_eutra_support_in_geran_ptm",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_geran_to_eutra_support_in_geran_ptm_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_prio_based_resel_support,
{ "Priority-based reselection support", "gsm_a.gm.gmm.rac.prio_based_resel_support",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_alt_efta_multi_slot_class,
{ "Alternative EFTA Multislot Class", "gsm_a.gm.gmm.rac.alt_efta_multi_slot_class",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_alt_efta_multi_slot_class_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_efta_multi_slot_cap_red_down_dual_carrier,
{ "EFTA Multislot Capability Reduction for Downlink Dual Carrier", "gsm_a.gm.gmm.rac.efta_multi_slot_cap_red_down_dual_carrier",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_multi_slot_cap_red_down_dual_carrier_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_ind_up_layer_pdu_start_cap_for_rlc_um,
{ "Indication of Upper Layer PDU Start Capability for RLC UM", "gsm_a.gm.gmm.rac.ind_up_layer_pdu_start_cap_for_rlc_um",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_emst_cap,
{ "Enhanced Multiplexing for Single TBF Capability", "gsm_a.gm.gmm.rac.emst_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_mtti_cap,
{ "Multiple TTI Capability", "gsm_a.gm.gmm.rac.mtti_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_utra_csg_cell_report,
{ "Reporting of UTRAN CSG cells in packet transfer mode", "gsm_a.gm.gmm.rac.utra_csg_cell_report",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_eutra_csg_cell_report,
{ "Reporting of E-UTRAN CSG cells in packet transfer mode", "gsm_a.gm.gmm.rac.eutra_csg_cell_report",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_dtr_cap,
{ "Dynamic Timeslot Reduction Capability", "gsm_a.gm.gmm.rac.dtr_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_emsr_cap,
{ "Enhanced Multiplexing for Single RLC Entity Capability", "gsm_a.gm.gmm.rac.emsr_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_fast_down_freq_switch_cap,
{ "Fast Downlink Frequency Switching Capability", "gsm_a.gm.gmm.rac.fast_down_freq_switch_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_tighter_cap,
{ "TIGHTER Capability", "gsm_a.gm.gmm.rac.tighter_cap",
FT_UINT8, BASE_DEC, VALS(tighter_cap_level_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_fanr_cap,
{ "Fast Ack/Nack Reporting Capability", "gsm_a.gm.gmm.rac.fanr_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_ipa_cap,
{ "Immediate Packet Assignment Capability", "gsm_a.gm.gmm.rac.ipa_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_geran_nw_sharing_support,
{ "GERAN Network Sharing support", "gsm_a.gm.gmm.rac.geran_nw_sharing_support",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_eutra_wb_rsrq_support,
{ "E-UTRA Wideband RSRQ measurements support", "gsm_a.gm.gmm.rac.eutra_wb_rsrq_support",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_utra_mfbi_support,
{ "UTRA Multiple Frequency Band Indicators support", "gsm_a.gm.gmm.rac.utra_mfbi_support",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_eutra_mfbi_support,
{ "E-UTRA Multiple Frequency Band Indicators support", "gsm_a.gm.gmm.rac.eutra_mfbi_support",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_dlmc_non_contig_intra_band_recep,
{ "DLMC - Non-contiguous intra-band reception", "gsm_a.gm.gmm.rac.dlmc.non_contig_intra_band_recep",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_dlmc_non_contig_intra_band_recep_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_dlmc_inter_band_recep,
{ "DLMC - Inter-band reception", "gsm_a.gm.gmm.rac.dlmc.inter_band_recep",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_gm_dlmc_inter_band_recep_val), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_dlmc_max_bandwidth,
{ "DLMC - Maximum Bandwidth", "gsm_a.gm.gmm.rac.dlmc.max_bandwidth",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_dlmc_max_bandwidth_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_dlmc_max_nb_dl_ts,
{ "DLMC - Maximum Number of Downlink Timeslots", "gsm_a.gm.gmm.rac.dlmc.max_nb_dl_ts",
FT_UINT8, BASE_CUSTOM, CF_FUNC(gsm_a_gm_dlmc_max_nb_dl_ts_fmt), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_dlmc_max_nb_dl_carriers,
{ "DLMC - Maximum Number of Downlink Carriers", "gsm_a.gm.gmm.rac.dlmc.max_nb_dl_carriers",
FT_UINT8, BASE_DEC, VALS(gsm_a_gm_dlmc_max_nb_dl_carriers_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_ext_tsc_set_cap_support,
{ "Extended TSC Set Capability support", "gsm_a.gm.gmm.rac.ext_tsc_set_cap_support",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_yes_no), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_gm_rac_ext_earfcn_value_range,
{ "Extended EARFCN value range", "gsm_a.gm.gmm.rac.ext_earfcn_value_range",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_sm_ti_flag,
{ "TI Flag", "gsm_a.gm.sm.ti_flag",
FT_BOOLEAN, 8, TFS(&gsm_a_sm_ti_flag_vals), 0x80,
NULL, HFILL }
},
{ &hf_gsm_a_sm_ext,
{ "Extension", "gsm_a.gm.sm.ext",
FT_BOOLEAN, 8, NULL, 0x80,
NULL, HFILL }
},
{ &hf_gsm_a_gm_presence, { "Presence", "gsm_a.gm.gmm.presence", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_gm_8psk_power_class, { "8PSK Power Class", "gsm_a.gm.8psk_power_class", FT_UINT8, BASE_DEC, VALS(gsm_a_gm_8psk_power_class_vals), 0x0, NULL, HFILL }},
{ &hf_gsm_a_gm_rf_power_capability, { "RF Power Capability", "gsm_a.gm.rf_power_capability", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_gm_a5_bits, { "A5 Bits", "gsm_a.gm.a5_bits", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_gm_8psk_power_capability, { "8PSK Power Capability", "gsm_a.gm.8psk_power_capability", FT_UINT8, BASE_DEC, VALS(gsm_a_gm_8psk_power_cap_vals), 0x0, NULL, HFILL }},
{ &hf_gsm_a_gm_extended_dtm_gprs_multi_slot_class, { "Extended DTM GPRS Multi Slot Class", "gsm_a.gm.extended_dtm_gprs_multi_slot_class", FT_UINT8, BASE_DEC, VALS(gsm_a_gm_extended_dtm_gprs_multi_slot_class_vals), 0x0, NULL, HFILL }},
{ &hf_gsm_a_gm_extended_dtm_egprs_multi_slot_class, { "Extended DTM EGPRS Multi Slot Class", "gsm_a.gm.extended_dtm_egprs_multi_slot_class", FT_UINT8, BASE_DEC, VALS(gsm_a_gm_extended_dtm_gprs_multi_slot_class_vals), 0x0, NULL, HFILL }},
{ &hf_gsm_a_gm_high_multislot_capability, { "High Multislot Capability", "gsm_a.gm.high_multislot_capability", FT_UINT8, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_gm_gmsk_multislot_power_profile, { "GMSK Multislot Power Profile", "gsm_a.gm.gmsk_multislot_power_profile", FT_UINT8, BASE_DEC, VALS(gsm_a_gm_gmsk_multislot_power_profile_vals), 0x0, NULL, HFILL }},
{ &hf_gsm_a_gm_8psk_multislot_power_profile, { "8-PSK Multislot Power Profile", "gsm_a.gm.8psk_multislot_power_profile", FT_UINT8, BASE_DEC, VALS(gsm_a_gm_8psk_multislot_power_profile_vals), 0x0, NULL, HFILL }},
{ &hf_gsm_a_gm_update_result, { "Update Result", "gsm_a.gm.gmm.update_result", FT_UINT8, BASE_DEC, VALS(gsm_a_gm_update_res_vals), 0x70, NULL, HFILL }},
{ &hf_gsm_a_gm_radio_priority_pdp, { "Radio Priority (PDP or SMS)", "gsm_a.gm.radio_priority_pdp", FT_UINT8, BASE_DEC, VALS(gsm_a_gm_radio_prio_vals), 0x07, NULL, HFILL }},
{ &hf_gsm_a_gm_radio_priority_tom8, { "Radio Priority (TOM8)", "gsm_a.gm.radio_priority_tom8", FT_UINT8, BASE_DEC, VALS(gsm_a_gm_radio_prio_vals), 0x70, NULL, HFILL }},
{ &hf_gsm_a_gm_configuration_protocol, { "Configuration Protocol", "gsm_a.gm.configuration_protocol", FT_UINT8, BASE_DEC, NULL, 0x7, NULL, HFILL }},
{ &hf_gsm_a_gm_sm_pco_length, { "Length", "gsm_a.gm.sm.pco.length", FT_UINT8, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_gm_sm_pco_ipv6, { "IPv6", "gsm_a.gm.sm.pco.ipv6", FT_IPv6, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_gm_sm_pco_reject_code, { "Reject Code", "gsm_a.gm.sm.pco.reject_code", FT_UINT8, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_gm_sm_pco_prefix_length, { "Prefix length", "gsm_a.gm.sm.pco.ipv6_prefix_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_gm_sm_pco_ipv4, { "IPv4", "gsm_a.gm.sm.pco.ipv4", FT_IPv4, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_gm_sm_pco_ipv4_link_mtu_size, { "IPv4 link MTU size", "gsm_a.gm.sm.pco.ipv4_link_mtu_size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_gm_sm_pco_sel_bearer_ctrl_mode, { "Selected Bearer Control Mode", "gsm_a.gm.sm.pco.sel_bearer_ctrl_mode", FT_UINT8, BASE_DEC, VALS(gsm_a_gm_sel_bearer_ctrl_mode_vals), 0x0, NULL, HFILL }},
{ &hf_gsm_a_sm_pdp_type_number, { "PDP type number", "gsm_a.gm.sm.pdp_type_number", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_sm_pdp_address, { "PDP address", "gsm_a.gm.sm.pdp_address", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_sm_qos_maximum_sdu_size, { "Maximum SDU size", "gsm_a.gm.sm.qos.maximum_sdu_size", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_gm_ti_value, { "TI value", "gsm_a.gm.ti_value", FT_UINT8, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_sm_tft_packet_filter, { "Packet filter", "gsm_a.gm.sm.tft.packet_filter", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_sm_tft_packet_evaluation_precedence, { "Packet evaluation precedence", "gsm_a.gm.sm.tft.packet_evaluation_precedence", FT_UINT8, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_sm_tft_packet_filter_length, { "Packet filter length", "gsm_a.gm.sm.tft.packet_filter_length", FT_UINT8, BASE_HEX_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_sm_tft_authorization_token_value, { "Authorization token value", "gsm_a.gm.sm.tft.authorization_token_value", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_sm_tft_media_component_number_value, { "Media Component number value", "gsm_a.gm.sm.tft.media_component_number_value", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_sm_tft_ip_flow_number, { "IP flow number", "gsm_a.gm.sm.tft.ip_flow_number", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_sm_tft_packet_filter_identifier, { "Packet filter identifier", "gsm_a.gm.sm.tft.packet_filter_identifier", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_sm_tft_parameter_content, { "Parameter content", "gsm_a.gm.sm.tft.parameter_content", FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_gsm_a_sm_tft_packet_filter_component_type_id, { "Packet filter component type identifier", "gsm_a.gm.sm.tft.packet_filter_component_type_id", FT_UINT8, BASE_DEC, VALS(packet_filter_component_type_vals), 0x0, NULL, HFILL }},
};
static ei_register_info ei[] = {
{ &ei_gsm_a_gm_extraneous_data, { "gsm_a.gm.extraneous_data", PI_PROTOCOL, PI_NOTE, "Extraneous Data, dissector bug or later version spec(report to wireshark.org)", EXPFILL }},
{ &ei_gsm_a_gm_not_enough_data, { "gsm_a.gm.not_enough_data", PI_PROTOCOL, PI_WARN, "Not enough data", EXPFILL }},
{ &ei_gsm_a_gm_undecoded, { "gsm_a.gm.undecoded", PI_UNDECODED, PI_WARN, "Not decoded", EXPFILL }},
};
expert_module_t* expert_gsm_a_gm;
#define NUM_INDIVIDUAL_ELEMS 7
gint *ett[NUM_INDIVIDUAL_ELEMS +
NUM_GSM_DTAP_MSG_GMM + NUM_GSM_DTAP_MSG_SM +
NUM_GSM_GM_ELEM];
ett[0] = &ett_gmm_radio_cap;
ett[1] = &ett_gmm_rai;
ett[2] = &ett_sm_tft;
ett[3] = &ett_gmm_gprs_timer;
ett[4] = &ett_gmm_network_cap;
ett[5] = &ett_gsm_a_gm_msrac_multislot_capability;
ett[6] = &ett_sm_pco;
last_offset = NUM_INDIVIDUAL_ELEMS;
for (i=0; i<NUM_GSM_DTAP_MSG_GMM; i++, last_offset++)
{
ett_gsm_dtap_msg_gmm[i] = -1;
ett[last_offset] = &ett_gsm_dtap_msg_gmm[i];
}
for (i=0; i<NUM_GSM_DTAP_MSG_SM; i++, last_offset++)
{
ett_gsm_dtap_msg_sm[i] = -1;
ett[last_offset] = &ett_gsm_dtap_msg_sm[i];
}
for (i=0; i<NUM_GSM_GM_ELEM; i++, last_offset++)
{
ett_gsm_gm_elem[i] = -1;
ett[last_offset] = &ett_gsm_gm_elem[i];
}
proto_a_gm =
proto_register_protocol("GSM A-I/F GPRS Mobility and Session Management", "GSM Management", "gsm_a.gm");
proto_register_field_array(proto_a_gm, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_gsm_a_gm = expert_register_protocol(proto_a_gm);
expert_register_field_array(expert_gsm_a_gm, ei, array_length(ei));
gprs_sm_pco_subdissector_table = register_dissector_table("sm_pco.protocol",
"GPRS SM PCO PPP protocol", FT_UINT16, BASE_HEX);
}
void
proto_reg_handoff_gsm_a_gm(void)
{
data_handle = find_dissector("data");
rrc_irat_ho_info_handle = find_dissector("rrc.irat.irat_ho_info");
lte_rrc_ue_eutra_cap_handle = find_dissector("lte-rrc.ue_eutra_cap");
}
