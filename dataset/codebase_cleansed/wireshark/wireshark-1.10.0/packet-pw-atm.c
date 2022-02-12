static int
pw_cell_size(const pwatm_mode_t mode, const pwatm_submode_t submode)
{
switch (mode)
{
case PWATM_MODE_N1_NOCW:
case PWATM_MODE_N1_CW:
return SIZEOF_N1_PW_CELL;
case PWATM_MODE_11_VCC:
return SIZEOF_11_VCC_PW_CELL;
case PWATM_MODE_11_VPC:
return SIZEOF_11_VPC_PW_CELL;
case PWATM_MODE_AAL5_PDU:
return SIZEOF_ATM_CELL_PAYLOAD;
case PWATM_MODE_AAL5_SDU:
if (PWATM_SUBMODE_ADMIN_CELL == submode)
{
return SIZEOF_N1_PW_CELL;
}
else
{
DISSECTOR_ASSERT_NOT_REACHED();
return 0;
}
default:
DISSECTOR_ASSERT_NOT_REACHED();
return 0;
}
}
static int
pw_cell_header_size(const pwatm_mode_t mode, const pwatm_submode_t submode)
{
switch (mode)
{
case PWATM_MODE_N1_NOCW:
case PWATM_MODE_N1_CW:
return SIZEOF_N1_PW_CELL_HEADER;
case PWATM_MODE_11_VCC:
return SIZEOF_11_VCC_PW_CELL_HEADER;
case PWATM_MODE_11_VPC:
return SIZEOF_11_VPC_PW_CELL_HEADER;
case PWATM_MODE_AAL5_SDU:
if (PWATM_SUBMODE_ADMIN_CELL == submode)
{
return SIZEOF_N1_PW_CELL_HEADER;
}
else
{
DISSECTOR_ASSERT_NOT_REACHED();
return 0;
}
case PWATM_MODE_AAL5_PDU:
default:
DISSECTOR_ASSERT_NOT_REACHED();
return 0;
}
}
static int
number_of_cells(const pwatm_mode_t mode
,const pwatm_submode_t submode
,const gint payload_size
,gint* const remainder_size)
{
int cells;
DISSECTOR_ASSERT(payload_size >= 0);
switch (mode)
{
case PWATM_MODE_N1_NOCW:
case PWATM_MODE_N1_CW:
case PWATM_MODE_11_VCC:
case PWATM_MODE_11_VPC:
case PWATM_MODE_AAL5_PDU:
cells = payload_size / pw_cell_size(mode, submode);
*remainder_size = payload_size - (cells * pw_cell_size(mode, submode));
return cells;
case PWATM_MODE_AAL5_SDU:
if (PWATM_SUBMODE_ADMIN_CELL == submode)
{
cells = payload_size / pw_cell_size(mode, submode);
if (cells > 1) cells = 1;
*remainder_size = payload_size - (cells * pw_cell_size(mode, submode));
return cells;
}
else
{
}
default:
DISSECTOR_ASSERT_NOT_REACHED();
*remainder_size = payload_size;
return 0;
}
}
static void
col_append_pw_info(packet_info * pinfo
,const int payload_size
,const int cells
,const int padding_size)
{
pwatm_private_data_t * pd;
DISSECTOR_ASSERT(pinfo != NULL);
pd = (pwatm_private_data_t *)pinfo->private_data;
DISSECTOR_ASSERT(pd != NULL);
if (pd->props & PWC_ANYOF_CW_BAD)
{
col_append_str(pinfo->cinfo, COL_INFO, "CW:Bad");
}
if (pd->props & PWC_PAY_SIZE_BAD)
{
if (pd->props & PWC_ANYOF_CW_BAD)
{
col_append_str(pinfo->cinfo, COL_INFO, ", ");
}
col_append_str(pinfo->cinfo, COL_INFO, "Payload size:Bad, ");
col_append_fstr(pinfo->cinfo, COL_INFO, "%d byte%s"
,(int)payload_size
,plurality(payload_size, "", "s"));
}
if (pd->props == 0)
{
if (cells >=0)
col_append_fstr(pinfo->cinfo, COL_INFO, "%d ATM cell%s"
,cells
,plurality(cells, "", "s"));
if (pd->cumulative.vpi >= 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", VPI:%.4d", pd->cumulative.vpi);
if (pd->cumulative.vci >= 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", VCI:%.5d", pd->cumulative.vci);
if (pd->cumulative.pti >= 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", PTI:%.1d", pd->cumulative.pti);
if (pd->cumulative.clp >= 0)
col_append_fstr(pinfo->cinfo, COL_INFO, ", CLP:%.1d", pd->cumulative.clp);
}
if (padding_size != 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, ", %d padding"
,(int)padding_size);
}
}
static void
prepare_pseudo_header_atm(
union wtap_pseudo_header * const ph,
const pwatm_private_data_t * const pdata,
const guint aal)
{
DISSECTOR_ASSERT(NULL != pdata);
DISSECTOR_ASSERT(NULL != ph);
memset(ph, 0 , sizeof(*ph));
ph->atm.flags = 0;
ph->atm.aal = aal;
ph->atm.type = TRAF_UNKNOWN;
ph->atm.subtype = TRAF_ST_UNKNOWN;
ph->atm.vpi = (pdata->vpi >= 0) ? pdata->vpi : 0 ;
ph->atm.vci = (pdata->vci >= 0) ? pdata->vci : 0 ;
ph->atm.aal2_cid = 0;
ph->atm.channel = 0;
ph->atm.cells = 0;
ph->atm.aal5t_u2u = 0;
if (pdata->aal5_sdu_frame_relay_cr_bit)
{
ph->atm.aal5t_u2u |= (1<<8);
}
ph->atm.aal5t_len = 0;
ph->atm.aal5t_chksum = 0;
return;
}
static void
dissect_payload_and_padding(
tvbuff_t * tvb
,packet_info * pinfo
,proto_tree * tree
,const gint payload_size
,const gint padding_size)
{
int dissected;
tvbuff_t * tvb_2;
pwatm_private_data_t * pd;
DISSECTOR_ASSERT(NULL != pinfo);
pd = (pwatm_private_data_t *)pinfo->private_data;
DISSECTOR_ASSERT(NULL != pd);
for(dissected = 0, pd->pw_cell_number = 0;
payload_size > dissected;
++(pd->pw_cell_number))
{
tvb_2 = tvb_new_subset_remaining(tvb, dissected);
dissected += call_dissector(dh_cell_header, tvb_2, pinfo, tree);
tvb_2 = tvb_new_subset_remaining(tvb, dissected);
if ((pd->vci >= 0) && (pd->pti >=0))
{
if (atm_is_oam_cell(pd->vci, pd->pti))
{
pd->cell_mode_oam = TRUE;
}
}
if (pd->cell_mode_oam)
{
union wtap_pseudo_header * pseudo_header_save;
union wtap_pseudo_header ph;
tvbuff_t* tvb_3;
int bytes_to_dissect;
if ((payload_size - dissected) >= SIZEOF_ATM_CELL_PAYLOAD)
bytes_to_dissect = SIZEOF_ATM_CELL_PAYLOAD;
else
bytes_to_dissect = (payload_size - dissected);
tvb_3 = tvb_new_subset(tvb_2, 0, bytes_to_dissect, -1);
if (pd->mode == PWATM_MODE_AAL5_SDU && (pd->pw_cell_number > 0))
{
pd->enable_fill_columns_by_atm_dissector = FALSE;
}
pseudo_header_save = pinfo->pseudo_header;
pinfo->pseudo_header = &ph;
prepare_pseudo_header_atm(&ph, pd, AAL_OAMCELL);
call_dissector(dh_atm_oam_cell, tvb_3, pinfo, tree);
dissected += bytes_to_dissect;
pinfo->pseudo_header = pseudo_header_save;
}
else
{
dissected += call_dissector(dh_cell, tvb_2, pinfo, tree);
}
}
if (padding_size != 0)
{
tvb_2 = tvb_new_subset_remaining(tvb, -padding_size);
call_dissector(dh_padding, tvb_2, pinfo, tree);
}
return;
}
static gboolean
too_small_packet_or_notpw(tvbuff_t * tvb
,packet_info * pinfo
,proto_tree * tree
,const int proto_handler
,const char * const proto_name_column)
{
gint packet_size;
packet_size = tvb_reported_length_remaining(tvb, 0);
if (packet_size < 4)
{
proto_item * item;
item = proto_tree_add_item(tree, proto_handler, tvb, 0, -1, ENC_NA);
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR,
"PW packet size (%d) is too small to carry sensible information"
,(int)packet_size);
col_set_str(pinfo->cinfo, COL_PROTOCOL, proto_name_column);
col_set_str(pinfo->cinfo, COL_INFO, "Malformed: PW packet is too small");
return TRUE;
}
if (dissect_try_cw_first_nibble(tvb, pinfo, tree))
{
return TRUE;
}
return FALSE;
}
static void
dissect_11_or_aal5_pdu(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
const char * proto_name_column;
const char * proto_name_tree = NULL;
gint payload_size;
int cells;
pwatm_private_data_t pd = PWATM_PRIVATE_DATA_T_INITIALIZER;
void * pd_save = pinfo->private_data;
pinfo->private_data = &pd;
proto_name_column = &shortname_11_or_aal5_pdu[0];
if (too_small_packet_or_notpw(tvb, pinfo, tree, proto_11_or_aal5_pdu, proto_name_column))
{
return;
}
pd.packet_size = tvb_reported_length_remaining(tvb, 0);
{
guint8 third_byte;
third_byte = tvb_get_guint8(tvb, 3);
if (0 == (third_byte & 0x80 ))
{
if (0 != (third_byte & 0x40 ))
{
pd.mode = PWATM_MODE_11_VPC;
proto_name_column = &shortname_11_vpc[0];
proto_name_tree = &longname_pw_atm_11_vpc[0];
}
else
{
pd.mode = PWATM_MODE_11_VCC;
proto_name_column = &shortname_11_vcc[0];
proto_name_tree = &longname_pw_atm_11_vcc[0];
}
}
else
{
pd.mode = PWATM_MODE_AAL5_PDU;
proto_name_column = &shortname_aal5_pdu[0];
proto_name_tree = &longname_pw_atm_aal5_pdu[0];
}
}
pd.props = PWC_PACKET_PROPERTIES_T_INITIALIZER;
if (0 != (tvb_get_guint8(tvb, 0) & 0xf0 ))
{
pd.props |= PWC_CW_BAD_BITS03;
}
if (0 != (tvb_get_guint8(tvb, 0) & 0x0f ))
{
pd.props |= PWC_CW_BAD_RSV;
}
if (MODE_11(pd.mode))
{
gint bad_padding_size;
payload_size = pd.packet_size - (PWC_SIZEOF_CW-1);
cells = number_of_cells(pd.mode, pd.submode, payload_size, &bad_padding_size);
if ((0 == cells) || (0 != bad_padding_size))
{
pd.props |= PWC_PAY_SIZE_BAD;
}
}
else
{
gint bad_padding_size;
payload_size = pd.packet_size - PWC_SIZEOF_CW;
cells = number_of_cells(pd.mode, pd.submode, payload_size, &bad_padding_size);
if ((1 > cells) || (0 != bad_padding_size))
{
pd.props |= PWC_PAY_SIZE_BAD;
}
cells = -1;
}
if (PWATM_MODE_AAL5_PDU == pd.mode)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, proto_name_column);
if (check_col(pinfo->cinfo, COL_INFO))
{
col_clear(pinfo->cinfo, COL_INFO);
col_append_pw_info(pinfo, payload_size, cells, 0);
}
}
{
proto_item* item;
item = proto_tree_add_item(tree, proto_11_or_aal5_pdu, tvb, 0, -1, ENC_NA);
proto_item_set_text(item, proto_name_tree, 0);
pwc_item_append_text_n_items(item, cells, "good ATM cell");
{
proto_tree* tree2;
tree2 = proto_item_add_subtree(item, ett_encaps);
{
proto_item* item2;
item2 = proto_tree_add_boolean(tree2
,VALUE_SELECTOR_VPC_VCC_PDU(pd.mode
,hf_pw_type_11_vpc
,hf_pw_type_11_vcc
,hf_pw_type_aal5_pdu)
,tvb, 0, 0, TRUE);
PROTO_ITEM_SET_GENERATED(item2);
if (MODE_11(pd.mode))
{
item2 = proto_tree_add_int(tree2, hf_11_ncells, tvb, 0, 0, cells);
PROTO_ITEM_SET_GENERATED(item2);
}
}
}
if (pd.props & PWC_PAY_SIZE_BAD)
{
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR
,"PW payload size (%d) must be <> 0 and multiple of %d"
,(int)payload_size, pw_cell_size(pd.mode, pd.submode));
if ((payload_size != 0) && MODE_11(pd.mode))
{
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_NOTE,
"PW ATM cell [%.3d] is broken", (int)cells);
}
}
}
{
tvbuff_t* tvb_2;
tvb_2 = tvb_new_subset(tvb, 0, PWC_SIZEOF_CW, PWC_SIZEOF_CW);
call_dissector(dh_control_word, tvb_2, pinfo, tree);
tvb_2 = tvb_new_subset_remaining(tvb, (PWC_SIZEOF_CW-1));
if (MODE_11(pd.mode))
{
dissect_payload_and_padding(tvb_2, pinfo, tree, payload_size, 0);
}
else
{
if (payload_size != 0)
{
tvbuff_t* tvb_3;
union wtap_pseudo_header* pseudo_header_save;
union wtap_pseudo_header ph;
tvb_3 = tvb_new_subset_remaining(tvb_2, 1);
pseudo_header_save = pinfo->pseudo_header;
pinfo->pseudo_header = &ph;
prepare_pseudo_header_atm(&ph, &pd, AAL_5);
call_dissector(dh_atm_untruncated, tvb_3, pinfo, tree);
pinfo->pseudo_header = pseudo_header_save;
}
}
}
if (MODE_11(pd.mode))
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, proto_name_column);
if (check_col(pinfo->cinfo, COL_INFO))
{
col_clear(pinfo->cinfo, COL_INFO);
col_append_pw_info(pinfo, payload_size, cells, 0);
}
}
pinfo->private_data = pd_save;
return;
}
static void
dissect_aal5_sdu(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
const char * proto_name_column;
gint payload_size;
gint padding_size;
int cells;
pwatm_private_data_t pd = PWATM_PRIVATE_DATA_T_INITIALIZER;
void * pd_save = pinfo->private_data;
pinfo->private_data = &pd;
pd.mode = PWATM_MODE_AAL5_SDU;
proto_name_column = &shortname_aal5_sdu[0];
if (too_small_packet_or_notpw(tvb, pinfo, tree, proto_aal5_sdu, proto_name_column))
{
return;
}
pd.packet_size = tvb_reported_length_remaining(tvb, 0);
if (0 != (tvb_get_guint8(tvb, 0) & 0xf0 ))
{
pd.props |= PWC_CW_BAD_BITS03;
}
pd.submode = PWATM_SUBMODE_DEFAULT;
if (0 != (tvb_get_guint8(tvb, 0) & 0x08 ))
{
pd.submode = PWATM_SUBMODE_ADMIN_CELL;
}
if (! pref_aal5_sdu_extend_cw_length_with_rsvd)
{
if (0 != (tvb_get_guint8(tvb, 1) & 0xc0 ))
{
pd.props |= PWC_CW_BAD_RSV;
}
}
{
gint payload_size_from_packet;
int cw_len;
payload_size_from_packet = pd.packet_size - PWC_SIZEOF_CW;
if (pref_aal5_sdu_extend_cw_length_with_rsvd)
{
cw_len = tvb_get_guint8(tvb, 1) & 0xff;
}
else
{
cw_len = tvb_get_guint8(tvb, 1) & 0x3f;
}
payload_size = payload_size_from_packet;
padding_size = 0;
if (0 == cw_len)
{
}
else if (!pref_aal5_sdu_allow_cw_length_nonzero
&& (PWATM_SUBMODE_ADMIN_CELL == pd.submode))
{
pd.props |= PWC_CW_BAD_LEN_MUST_BE_0;
}
else
{
gint payload_size_from_cw;
payload_size_from_cw = cw_len - PWC_SIZEOF_CW;
if (payload_size_from_cw <= 0)
{
pd.props |= PWC_CW_BAD_PAYLEN_LE_0;
}
else if (payload_size_from_cw > payload_size_from_packet)
{
pd.props |= PWC_CW_BAD_PAYLEN_GT_PACKET;
}
else
{
payload_size = payload_size_from_cw;
padding_size = payload_size_from_packet - payload_size_from_cw;
if (padding_size != 0)
{
if (PWATM_SUBMODE_ADMIN_CELL == pd.submode)
{
pd.props |= PWC_CW_BAD_PADDING_NE_0;
payload_size = payload_size_from_packet;
padding_size = 0;
}
}
}
}
if (PWATM_SUBMODE_ADMIN_CELL == pd.submode)
{
gint bad_padding_size;
cells = number_of_cells(pd.mode, pd.submode, payload_size, &bad_padding_size);
if ((1 != cells) || (0 != bad_padding_size))
{
pd.props |= PWC_PAY_SIZE_BAD;
}
}
else
{
cells = -1;
}
}
if (check_col(pinfo->cinfo, COL_PROTOCOL))
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, proto_name_column);
if (PWATM_SUBMODE_ADMIN_CELL == pd.submode)
{
col_append_str(pinfo->cinfo, COL_PROTOCOL, ", OAM cell");
}
}
if (check_col(pinfo->cinfo, COL_INFO))
{
col_clear(pinfo->cinfo, COL_INFO);
col_append_pw_info(pinfo, payload_size, cells, padding_size);
}
{
proto_item* item;
item = proto_tree_add_item(tree, proto_aal5_sdu, tvb, 0, -1, ENC_NA);
{
proto_tree* tree2;
tree2 = proto_item_add_subtree(item, ett_encaps);
{
item = proto_tree_add_boolean(tree2, hf_pw_type_aal5_sdu, tvb, 0, 0, TRUE);
PROTO_ITEM_SET_GENERATED(item);
}
}
if (pd.props & PWC_PAY_SIZE_BAD)
{
DISSECTOR_ASSERT(PWATM_SUBMODE_ADMIN_CELL == pd.submode);
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR
,"In ATM admin cell mode,"
" PW payload size (%d) must be == %d (exactly 1 admin cell)"
,(int)payload_size, (int)SIZEOF_N1_PW_CELL);
}
}
{
tvbuff_t* tvb_2;
tvb_2 = tvb_new_subset(tvb, 0, PWC_SIZEOF_CW, PWC_SIZEOF_CW);
call_dissector(dh_control_word, tvb_2, pinfo, tree);
tvb_2 = tvb_new_subset_remaining(tvb, PWC_SIZEOF_CW);
if (PWATM_SUBMODE_ADMIN_CELL == pd.submode)
{
dissect_payload_and_padding(tvb_2, pinfo, tree, payload_size, padding_size);
}
else
{
if (payload_size != 0)
{
tvbuff_t* tvb_3;
union wtap_pseudo_header* pseudo_header_save;
union wtap_pseudo_header ph;
tvb_3 = tvb_new_subset(tvb_2, 0, payload_size, payload_size);
pseudo_header_save = pinfo->pseudo_header;
pinfo->pseudo_header = &ph;
prepare_pseudo_header_atm(&ph, &pd, AAL_5);
call_dissector(dh_atm_truncated, tvb_3, pinfo, tree);
pinfo->pseudo_header = pseudo_header_save;
}
if (padding_size != 0)
{
tvbuff_t* tvb_3;
tvb_3 = tvb_new_subset(tvb_2, payload_size, padding_size, -1);
call_dissector(dh_padding, tvb_3, pinfo, tree);
}
}
}
pinfo->private_data = pd_save;
return;
}
static void
dissect_n1_cw(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
const char * proto_name_column;
gint payload_size;
gint padding_size;
int cells;
pwatm_private_data_t pd = PWATM_PRIVATE_DATA_T_INITIALIZER;
void * pd_save = pinfo->private_data;
pinfo->private_data = &pd;
pd.mode = PWATM_MODE_N1_CW;
proto_name_column = &shortname_n1_cw[0];
if (too_small_packet_or_notpw(tvb, pinfo, tree, proto_n1_cw, proto_name_column))
{
return;
}
pd.packet_size = tvb_reported_length_remaining(tvb, 0);
pd.props = PWC_PACKET_PROPERTIES_T_INITIALIZER;
if (0 != (tvb_get_guint8(tvb, 0) & 0xf0 ))
{
pd.props |= PWC_CW_BAD_BITS03;
}
if (0 != (tvb_get_guint8(tvb, 0) & 0x0f ))
{
pd.props |= PWC_CW_BAD_FLAGS;
}
if (! pref_n1_cw_extend_cw_length_with_rsvd)
{
if (0 != (tvb_get_guint8(tvb, 1) & 0xc0 ))
{
pd.props |= PWC_CW_BAD_RSV;
}
}
{
gint payload_size_from_packet;
int cw_len;
payload_size_from_packet = pd.packet_size - PWC_SIZEOF_CW;
if (pref_n1_cw_extend_cw_length_with_rsvd)
{
cw_len = tvb_get_guint8(tvb, 1) & 0xff;
}
else
{
cw_len = tvb_get_guint8(tvb, 1) & 0x3f;
}
payload_size = payload_size_from_packet;
padding_size = 0;
if (0 == cw_len)
{
}
else if (!pref_n1_cw_allow_cw_length_nonzero)
{
pd.props |= PWC_CW_BAD_LEN_MUST_BE_0;
}
else
{
gint payload_size_from_cw;
payload_size_from_cw = cw_len - PWC_SIZEOF_CW;
if (payload_size_from_cw <= 0)
{
pd.props |= PWC_CW_BAD_PAYLEN_LE_0;
}
else if (payload_size_from_cw > payload_size_from_packet)
{
pd.props |= PWC_CW_BAD_PAYLEN_GT_PACKET;
}
else
{
payload_size = payload_size_from_cw;
padding_size = payload_size_from_packet - payload_size_from_cw;
if (padding_size != 0)
{
pd.props |= PWC_CW_BAD_PADDING_NE_0;
payload_size = payload_size_from_packet;
padding_size = 0;
}
}
}
{
gint bad_padding_size;
cells = number_of_cells(pd.mode, pd.submode, payload_size, &bad_padding_size);
if ((0 == cells) || (0 != bad_padding_size))
{
pd.props |= PWC_PAY_SIZE_BAD;
}
}
}
{
proto_item* item;
item = proto_tree_add_item(tree, proto_n1_cw, tvb, 0, -1, ENC_NA);
pwc_item_append_text_n_items(item, cells, "good ATM cell");
{
proto_tree* tree2;
tree2 = proto_item_add_subtree(item, ett_encaps);
{
proto_item* item2;
item2 = proto_tree_add_boolean(tree2, hf_pw_type_n1_cw, tvb, 0, 0, TRUE);
PROTO_ITEM_SET_GENERATED(item2);
item2 = proto_tree_add_int(tree2, hf_n1_cw_ncells, tvb, 0, 0, cells);
PROTO_ITEM_SET_GENERATED(item2);
}
}
if (pd.props & PWC_PAY_SIZE_BAD)
{
if (payload_size != 0)
{
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR,
"PW ATM cell [%.3d] is broken", (int)cells);
}
expert_add_info_format(pinfo, item, PI_MALFORMED
, (payload_size == 0) ? PI_ERROR : PI_NOTE
,"PW payload size (%d) must be <>0 and multiple of %d"
,(int)payload_size, (int)SIZEOF_N1_PW_CELL);
}
}
{
tvbuff_t* tvb_2;
tvb_2 = tvb_new_subset(tvb, 0, PWC_SIZEOF_CW, PWC_SIZEOF_CW);
call_dissector(dh_control_word, tvb_2, pinfo, tree);
tvb_2 = tvb_new_subset_remaining(tvb, PWC_SIZEOF_CW);
dissect_payload_and_padding(tvb_2, pinfo, tree, payload_size, padding_size);
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, proto_name_column);
if (check_col(pinfo->cinfo, COL_INFO))
{
col_clear(pinfo->cinfo, COL_INFO);
col_append_pw_info(pinfo, payload_size, cells, padding_size);
}
pinfo->private_data = pd_save;
return;
}
static void
dissect_n1_nocw(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
const char * proto_name_column = &shortname_n1_nocw[0];
gint payload_size;
int cells;
pwatm_private_data_t pd = PWATM_PRIVATE_DATA_T_INITIALIZER;
void * pd_save = pinfo->private_data;
pinfo->private_data = &pd;
pd.mode = PWATM_MODE_N1_NOCW;
pd.packet_size = tvb_reported_length_remaining(tvb, 0);
pd.props = PWC_PACKET_PROPERTIES_T_INITIALIZER;
payload_size = pd.packet_size;
{
gint bad_padding_size;
cells = number_of_cells(pd.mode, pd.submode, pd.packet_size, &bad_padding_size);
if ((cells == 0) || (bad_padding_size != 0))
{
pd.props |= PWC_PAY_SIZE_BAD;
}
}
{
proto_item* item;
item = proto_tree_add_item(tree, proto_n1_nocw, tvb, 0, -1, ENC_NA);
pwc_item_append_text_n_items(item, cells, "ATM cell");
{
proto_tree* tree2;
tree2 = proto_item_add_subtree(item, ett_encaps);
{
proto_item* item2;
item2 = proto_tree_add_boolean(tree2, hf_pw_type_n1_nocw, tvb, 0, 0, TRUE);
PROTO_ITEM_SET_GENERATED(item2);
item2 = proto_tree_add_int(tree2, hf_n1_nocw_ncells, tvb, 0, 0, cells);
PROTO_ITEM_SET_GENERATED(item2);
}
}
if (pd.props & PWC_PAY_SIZE_BAD)
{
if (payload_size != 0)
{
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR,
"Last PW ATM cell [%.3d] is broken", (int)cells);
}
expert_add_info_format(pinfo, item, PI_MALFORMED
, (payload_size == 0) ? PI_ERROR : PI_NOTE
,"PW payload size (%d) must be <>0 and multiple of %d"
,(int)payload_size, (int)SIZEOF_N1_PW_CELL);
}
}
dissect_payload_and_padding(tvb, pinfo, tree, payload_size, 0);
col_set_str(pinfo->cinfo, COL_PROTOCOL, proto_name_column);
if (check_col(pinfo->cinfo, COL_INFO))
{
col_clear(pinfo->cinfo, COL_INFO);
col_append_pw_info(pinfo, payload_size, cells, 0);
}
pinfo->private_data = pd_save;
return;
}
static void
proto_item_append_text_cwb3_fields(proto_item * item, const pwatm_private_data_t * const pd)
{
if (NULL == item) return;
DISSECTOR_ASSERT(NULL != pd);
if (pd->cwb3.m >= 0)
proto_item_append_text(item, "M:%.1u " , (unsigned)(pd->cwb3.m));
if (pd->cwb3.v >= 0)
proto_item_append_text(item, "V:%.1u " , (unsigned)(pd->cwb3.v));
if (pd->cwb3.rsv >= 0)
proto_item_append_text(item, "RSV:%.1u ", (unsigned)(pd->cwb3.rsv));
if (pd->cwb3.u >= 0)
proto_item_append_text(item, "U:%.1u " , (unsigned)(pd->cwb3.u));
if (pd->cwb3.e >= 0)
proto_item_append_text(item, "EFCI:%.1u ",(unsigned)(pd->cwb3.e));
if (pd->cwb3.clp >= 0)
proto_item_append_text(item, "CLP:%.1u ", (unsigned)(pd->cwb3.clp));
return;
}
static void
dissect_control_word(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree)
{
pwatm_private_data_t* pd;
pd = (pwatm_private_data_t *)pinfo->private_data;
DISSECTOR_ASSERT(pd != NULL);
{
gint size;
size = tvb_reported_length_remaining(tvb, 0);
if (size < PWC_SIZEOF_CW)
{
proto_item *item;
item = proto_tree_add_item(tree, proto_control_word, tvb, 0, -1, ENC_NA);
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR,
"Packet (size: %d) is too small to carry MPLS PW Control Word"
,(int)size);
return;
}
}
{
proto_item* item_top;
proto_tree* tree2;
proto_item* item;
item_top = proto_tree_add_item(tree, proto_control_word, tvb, 0, -1, ENC_NA);
pwc_item_append_cw(item_top, tvb_get_ntohl(tvb, 0), FALSE);
tree2 = proto_item_add_subtree(item_top, ett_cw);
item = proto_tree_add_item(tree2, hf_cw_bits03, tvb, 0, 1, ENC_BIG_ENDIAN);
if (pd->props & PWC_CW_BAD_BITS03)
{
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR
,"Bits 0..3 of Control Word must be 0");
}
else
{
PROTO_ITEM_SET_HIDDEN(item);
}
if (MODE_N1(pd->mode))
{
item = proto_tree_add_item(tree2, hf_pref_cw_flags, tvb, 0, 1, ENC_BIG_ENDIAN);
if (pd->props & PWC_CW_BAD_FLAGS)
{
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR
,"Flags must be 0 for PW ATM N:1 encapsulation");
}
}
if (pd->mode == PWATM_MODE_AAL5_SDU)
{
proto_tree_add_item(tree2, hf_pref_cw_a5s_t, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree2, hf_pref_cw_a5s_e, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree2, hf_pref_cw_a5s_c, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree2, hf_pref_cw_a5s_u, tvb, 0, 1, ENC_BIG_ENDIAN);
pd->aal5_sdu_frame_relay_cr_bit =
(0 == (tvb_get_guint8(tvb, 0) & 0x01 ))
? FALSE : TRUE;
}
if (MODE_11_OR_AAL5_PDU(pd->mode)
|| (MODE_N1(pd->mode) && !pref_n1_cw_extend_cw_length_with_rsvd)
|| ((pd->mode == PWATM_MODE_AAL5_SDU) && !pref_aal5_sdu_extend_cw_length_with_rsvd)
)
{
if (MODE_11_OR_AAL5_PDU(pd->mode))
{
item = proto_tree_add_item(tree2
,hf_generic_cw_rsv, tvb, 0, 1, ENC_BIG_ENDIAN);
}
else
{
item = proto_tree_add_item(tree2
,hf_pref_cw_rsv, tvb, 1, 1, ENC_BIG_ENDIAN);
}
if (pd->props & PWC_CW_BAD_RSV)
{
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR
,"Reserved bits in Control Word must be 0");
}
else
{
PROTO_ITEM_SET_HIDDEN(item);
}
}
if (MODE_N1(pd->mode)
|| (PWATM_MODE_AAL5_SDU == pd->mode))
{
{
int hf_len = hf_pref_cw_len;
if (MODE_N1(pd->mode))
{
if (pref_n1_cw_extend_cw_length_with_rsvd)
hf_len = hf_pref_cw_rsvlen;
}
else
{
if (pref_aal5_sdu_extend_cw_length_with_rsvd)
hf_len = hf_pref_cw_rsvlen;
}
item = proto_tree_add_item(tree2, hf_len, tvb, 1, 1, ENC_BIG_ENDIAN);
}
if (pd->props & PWC_CW_BAD_LEN_MUST_BE_0)
{
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR
,"Bad Length: must be 0 for this encapsulation");
}
if (pd->props & PWC_CW_BAD_PAYLEN_LE_0)
{
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR
,"Bad Length: too small, must be >= %d"
,(int)(PWC_SIZEOF_CW+SIZEOF_N1_PW_CELL));
}
if (pd->props & PWC_CW_BAD_PAYLEN_GT_PACKET)
{
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR
,"Bad Length: must be <= than PSN packet size (%d)"
,(int)pd->packet_size);
}
if (pd->props & PWC_CW_BAD_PADDING_NE_0)
{
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR
,"Bad Length: must be == PSN packet size (%d), no padding allowed"
,(int)pd->packet_size);
}
}
proto_tree_add_item(tree2, hf_cw_seq, tvb
,MODE_11_OR_AAL5_PDU(pd->mode) ? 1 : 2, 2, ENC_BIG_ENDIAN);
if (MODE_11(pd->mode))
{
proto_tree_add_item(tree2, hf_gen_cw_atmbyte, tvb, 3, 1, ENC_BIG_ENDIAN);
item = proto_tree_add_text(tree2, tvb, 3, 1
,"ATM-specific byte of CW is fully dissected below as %s%s"
,(PWATM_MODE_11_VPC == pd->mode) ? "a part of " : ""
,"PW ATM Cell Header [000]");
PROTO_ITEM_SET_GENERATED(item);
}
if (PWATM_MODE_AAL5_PDU == pd->mode)
{
tvbuff_t* tvb_2;
tvb_2 = tvb_new_subset_remaining(tvb, (PWC_SIZEOF_CW-1));
call_dissector(dh_cell_header, tvb_2, pinfo, tree2);
proto_item_append_text(item_top, ", ");
proto_item_append_text_cwb3_fields(item_top, pd);
}
}
return;
}
static int
dissect_cell_header(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void * data _U_)
{
pwatm_private_data_t * pd;
gboolean is_enough_data;
int dissect_size;
pd = (pwatm_private_data_t *)pinfo->private_data;
DISSECTOR_ASSERT (NULL != pd);
pd->vpi = pd->vci = pd->pti = -1;
pd->cwb3.clp = pd->cwb3.m = pd->cwb3.v = pd->cwb3.rsv = pd->cwb3.u = pd->cwb3.e = -1;
if (PWATM_MODE_AAL5_PDU == pd->mode)
{
if (tvb_reported_length_remaining(tvb, 0) < 1)
{
is_enough_data = FALSE;
dissect_size = 0;
}
else
{
is_enough_data = TRUE;
dissect_size = 1;
}
}
else
{
gint size;
size = tvb_reported_length_remaining(tvb, 0);
if (size < pw_cell_header_size(pd->mode, pd->submode))
{
is_enough_data = FALSE;
dissect_size = size;
}
else
{
is_enough_data = TRUE;
dissect_size = pw_cell_header_size(pd->mode, pd->submode);
}
}
if (is_enough_data)
{
guint8 tmp8;
switch (pd->mode)
{
case PWATM_MODE_AAL5_SDU:
DISSECTOR_ASSERT(pd->submode == PWATM_SUBMODE_ADMIN_CELL);
case PWATM_MODE_N1_CW:
case PWATM_MODE_N1_NOCW:
pd->vpi = (tvb_get_ntohs (tvb, 0) >> 4);
pd->vci = (tvb_get_ntoh24(tvb, 1) >> 4) & 0xffff;
tmp8 = (tvb_get_guint8(tvb, 3));
pd->pti = (tmp8 >> 1) & 0x07;
pd->cwb3.clp = (tmp8 >> 0) & 0x01;
UPDATE_CUMULATIVE_VALUE(pd->cumulative.vpi, pd->vpi);
UPDATE_CUMULATIVE_VALUE(pd->cumulative.vci, pd->vci);
UPDATE_CUMULATIVE_VALUE(pd->cumulative.pti, pd->pti);
UPDATE_CUMULATIVE_VALUE(pd->cumulative.clp, pd->cwb3.clp);
pd->cell_mode_oam =
((pd->mode == PWATM_MODE_AAL5_SDU) && (pd->submode == PWATM_SUBMODE_ADMIN_CELL))
|| PTI_IS_ADMIN(pd->pti);
break;
case PWATM_MODE_11_VPC:
pd->vci = tvb_get_ntohs(tvb, 1);
UPDATE_CUMULATIVE_VALUE(pd->cumulative.vci, pd->vci);
case PWATM_MODE_11_VCC:
tmp8 = (tvb_get_guint8(tvb, 0));
pd->cwb3.m = (tmp8 >> 7) & 0x1;
pd->cwb3.v = (tmp8 >> 6) & 0x1;
pd->cwb3.rsv = (tmp8 >> 4) & 0x3;
pd->pti = (tmp8 >> 1) & 0x7;
pd->cwb3.clp = (tmp8 >> 0) & 0x1;
UPDATE_CUMULATIVE_VALUE(pd->cumulative.pti, pd->pti);
UPDATE_CUMULATIVE_VALUE(pd->cumulative.clp, pd->cwb3.clp);
pd->cell_mode_oam = PTI_IS_ADMIN(pd->pti) && (pd->cwb3.m == 0);
break;
case PWATM_MODE_AAL5_PDU:
tmp8 = (tvb_get_guint8(tvb, 0));
pd->cwb3.m = (tmp8 >> 7) & 0x1;
pd->cwb3.v = (tmp8 >> 6) & 0x1;
pd->cwb3.rsv = (tmp8 >> 3) & 0x7;
pd->cwb3.u = (tmp8 >> 2) & 0x1;
pd->cwb3.e = (tmp8 >> 1) & 0x1;
pd->cwb3.clp = (tmp8 >> 0) & 0x1;
UPDATE_CUMULATIVE_VALUE(pd->cumulative.clp, pd->cwb3.clp);
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
break;
}
}
{
proto_item* item;
item = proto_tree_add_item(tree, proto_cell_header, tvb
,0
,dissect_size
,ENC_NA);
if (PWATM_MODE_AAL5_PDU == pd->mode)
{
proto_item_set_text(item, "Third byte of Control Word");
}
else
{
proto_item_append_text(item, " [%.3d]", pd->pw_cell_number);
proto_item_append_text(item, ", ");
if (pd->vpi >= 0)
proto_item_append_text(item, "VPI:%.4u ", (unsigned)(pd->vpi));
if (pd->vci >= 0)
proto_item_append_text(item, "VCI:%.5u ", (unsigned)(pd->vci));
if (pd->pti >= 0)
proto_item_append_text(item, "PTI:%.1u ", (unsigned)(pd->pti));
proto_item_append_text_cwb3_fields(item, pd);
}
{
proto_tree* tree2;
tree2 = proto_item_add_subtree(item, ett_cell_header);
if (is_enough_data)
{
proto_item* item2;
if (MODE_N1(pd->mode)
|| ((pd->mode == PWATM_MODE_AAL5_SDU) && (pd->submode == PWATM_SUBMODE_ADMIN_CELL)))
{
proto_tree_add_uint(tree2, hf_cell_h_vpi, tvb, 0, 2, (unsigned)pd->vpi);
proto_tree_add_uint(tree2, hf_cell_h_vci, tvb, 1, 3, (unsigned)pd->vci);
item2 = proto_tree_add_item(tree2, hf_cell_h_pti, tvb, 3, 1, ENC_BIG_ENDIAN);
if (NULL == try_val_to_str(pd->pti, atm_pt_vals))
{
expert_add_info_format(pinfo, item2, PI_UNDECODED, PI_WARN,
"Unknown value of PTI field (%d) in the ATM cell header",
pd->pti);
}
else if ((pd->mode == PWATM_MODE_AAL5_SDU) && !PTI_IS_ADMIN(pd->pti))
{
expert_add_info_format(pinfo, item2, PI_MALFORMED, PI_ERROR,
"ATM admin cell is transerred;"
" PTI field (%d) should be 4, 5 or 6.",
pd->pti);
}
proto_tree_add_item(tree2, hf_cell_h_clp, tvb, 3, 1, ENC_BIG_ENDIAN);
}
else if (MODE_11_OR_AAL5_PDU(pd->mode))
{
item2 = proto_tree_add_item(tree2, hf_cell_h_m , tvb, 0, 1, ENC_BIG_ENDIAN);
if ((0 != pd->cwb3.m) && MODE_11(pd->mode))
{
expert_add_info_format(pinfo, item2, PI_MALFORMED, PI_ERROR
,"1:1 mode:"
" M bit must be 0 to distinguish from AAL5 PDU mode");
}
item2 = proto_tree_add_item(tree2, hf_cell_h_v , tvb, 0, 1, ENC_BIG_ENDIAN);
if ((0 == pd->cwb3.v) && (PWATM_MODE_11_VPC == pd->mode))
{
expert_add_info_format(pinfo, item2, PI_MALFORMED, PI_ERROR
,"1:1 VPC mode:"
" V bit must be 1 to indicate that VCI is present");
}
if ((0 != pd->cwb3.v) && (PWATM_MODE_11_VCC == pd->mode))
{
expert_add_info_format(pinfo, item2, PI_MALFORMED, PI_ERROR
,"1:1 VCC mode:"
" V bit must be 0 to indicate that VCI is absent");
}
if ((0 != pd->cwb3.v) && (PWATM_MODE_AAL5_PDU == pd->mode))
{
expert_add_info_format(pinfo, item2, PI_MALFORMED, PI_ERROR
,"AAL5 PDU mode:"
" V bit must be 0 to indicate that VCI is absent");
}
item2 = proto_tree_add_item(tree2
,(PWATM_MODE_AAL5_PDU == pd->mode)
? hf_aal5_pdu_rsv
: hf_cell_h_rsv
,tvb, 0, 1, ENC_BIG_ENDIAN);
if (0 != pd->cwb3.rsv)
{
expert_add_info_format(pinfo, item2, PI_MALFORMED, PI_ERROR
,"Reserved bits in the 3rd byte of CW must be 0");
}
else
{
PROTO_ITEM_SET_HIDDEN(item2);
}
if (MODE_11(pd->mode))
{
item2 = proto_tree_add_item(tree2, hf_cell_h_pti, tvb, 0, 1, ENC_BIG_ENDIAN);
if (NULL == try_val_to_str(pd->pti, atm_pt_vals))
{
expert_add_info_format(pinfo, item2, PI_UNDECODED, PI_WARN,
"Unknown value of PTI field (%d) in the atm-specific byte"
,pd->pti);
}
}
else
{
proto_tree_add_item(tree2, hf_aal5_pdu_u, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree2, hf_aal5_pdu_e, tvb, 0, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tree2, hf_cell_h_clp, tvb, 0, 1, ENC_BIG_ENDIAN);
if (PWATM_MODE_11_VPC == pd->mode)
{
proto_tree_add_uint(tree2, hf_cell_h_vci, tvb, 1, 2
,(unsigned)pd->vci);
}
}
else
{
DISSECTOR_ASSERT_NOT_REACHED();
}
}
else
{
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR
,"Not enough data (size: %d), impossible to decode"
,(int)dissect_size);
}
}
}
return dissect_size;
}
static int
dissect_cell(tvbuff_t * tvb, packet_info * pinfo, proto_tree * tree, void * data _U_)
{
gboolean is_enough_data;
int dissect_size;
{
gint size;
size = tvb_reported_length_remaining(tvb, 0);
if (size < SIZEOF_ATM_CELL_PAYLOAD)
{
is_enough_data = FALSE;
dissect_size = size;
}
else
{
is_enough_data = TRUE;
dissect_size = SIZEOF_ATM_CELL_PAYLOAD;
}
}
{
proto_item* item;
item = proto_tree_add_item(tree, proto_cell, tvb, 0, dissect_size, ENC_NA);
{
pwatm_private_data_t * pd;
pd = (pwatm_private_data_t *)pinfo->private_data;
if (NULL != pd)
{
proto_item_append_text(item, " [%.3d]", pd->pw_cell_number);
}
}
pwc_item_append_text_n_items(item, dissect_size, "byte");
if (!is_enough_data)
{
expert_add_info_format(pinfo, item, PI_MALFORMED, PI_ERROR
,"Bad length of cell payload: must be == %d"
,(int)SIZEOF_ATM_CELL_PAYLOAD);
}
{
proto_tree* tree2;
tvbuff_t* tvb_d;
tree2 = proto_item_add_subtree(item, ett_cell);
tvb_d = tvb_new_subset(tvb, 0, dissect_size, -1);
call_dissector(dh_data, tvb_d, pinfo, tree2);
item = proto_tree_add_int(tree2, hf_cell_payload_len, tvb, 0, 0, dissect_size);
PROTO_ITEM_SET_HIDDEN(item);
}
}
return dissect_size;
}
void
proto_register_pw_atm_ata(void)
{
static const value_string clp_vals[] = {
{ 0, "High priority" },
{ 1, "Low priority" },
{ 0, NULL }
};
static const value_string m_vals[] = {
{ 0, "ATM cell" },
{ 1, "AAL5 payload" },
{ 0, NULL }
};
static const value_string u_vals[] = {
{ 0, "This frame does not contain the last cell of AAL5 PDU" },
{ 1, "This frame contains the last cell of AAL5 PDU" },
{ 0, NULL }
};
static const value_string e_vals[] = {
{ 0, "Congestion is not experienced" },
{ 1, "Congestion is experienced for one or more ATM AAL5 cells" },
{ 0, NULL }
};
static hf_register_info hfa_cell_header[] = {
{ &hf_cell_h_vpi ,{"VPI" ,"atm.vpi"
,FT_UINT16 ,BASE_DEC ,NULL ,0
,NULL ,HFILL }},
{ &hf_cell_h_vci ,{"VCI" ,"atm.vci"
,FT_UINT16 ,BASE_DEC ,NULL ,0
,NULL ,HFILL }},
{ &hf_cell_h_pti ,{"Payload Type" ,"atm.pti"
,FT_UINT8 ,BASE_DEC ,VALS(atm_pt_vals),0x0e
,"The 3-bit Payload Type Identifier (PTI) incorporates ATM Layer"
" PTI coding of the cell. These bits are set to the value of the"
" PTI of the encapsulated ATM cell."
,HFILL }},
{ &hf_cell_h_clp ,{"Cell Loss Priority" ,"atm.clp"
,FT_UINT8 ,BASE_DEC ,VALS(clp_vals) ,0x01
,"The Cell Loss Priority (CLP) field indicates CLP value"
" of the encapsulated cell."
,HFILL }},
{ &hf_cell_h_m ,{"Transport Mode" ,"atm.pw_control_byte.m"
,FT_UINT8 ,BASE_DEC ,VALS(m_vals) ,0x80
,"Bit (M) of the control byte indicates whether the packet"
" contains an ATM cell or a frame payload. If set to 0,"
" the packet contains an ATM cell. If set to 1, the PDU"
" contains an AAL5 payload."
,HFILL }},
{ &hf_cell_h_v ,{"VCI Present" ,"atm.pw_control_byte.v"
,FT_BOOLEAN ,8 ,TFS(&tfs_yes_no),0x40
,"Bit (V) of the control byte indicates whether the VCI field"
" is present in the packet. If set to 1, the VCI field is present"
" for the cell. If set to 0, no VCI field is present."
,HFILL }},
{ &hf_cell_h_rsv ,{"Reserved bits" ,"atm.pw_control_byte.rsv"
,FT_UINT8 ,BASE_DEC ,NULL ,0x30
,"The reserved bits should be set to 0 at the transmitter and"
" ignored upon reception."
,HFILL }},
{ &hf_aal5_pdu_rsv ,{"Reserved bits" ,"atm.pw_control_byte.rsv"
,FT_UINT8 ,BASE_DEC ,NULL ,0x38
,"The reserved bits should be set to 0 at the transmitter and"
" ignored upon reception."
,HFILL }},
{ &hf_aal5_pdu_u ,{"U bit" ,"atm.pw_control_byte.u"
,FT_UINT8 ,BASE_DEC ,VALS(u_vals) ,0x04
,"Indicates whether this frame contains the last cell of"
" an AAL5 PDU and represents the value of the ATM User-to-User"
" bit for the last ATM cell of the PSN frame. Note: The ATM"
" User-to-User bit is the least significant bit of the PTI"
" in the ATM header."
,HFILL }},
{ &hf_aal5_pdu_e ,{"EFCI" ,"atm.pw_control_byte.efci"
,FT_UINT8 ,BASE_DEC ,VALS(e_vals) ,0x02
,"EFCI is set to the EFCI state of the last cell of the"
" AAL5 PDU or AAL5 fragment. Note: The EFCI state is"
" indicated in the middle bit of each ATM cell's PTI."
,HFILL }}
};
static hf_register_info hfa_cell[] = {
{&hf_cell_payload_len ,{"Length" ,"atm.cell.len"
,FT_INT32 ,BASE_DEC ,NULL ,0
,NULL ,HFILL }}
};
#define HF_INITIALIZER_NCELLS(hf_handle) \
{ &hf_handle ,{"Number of good encapsulated cells","pw.atm.cells" \
,FT_INT32 ,BASE_DEC ,NULL ,0 \
,NULL ,HFILL }}
#define HF_INITIALIZER_PWTYPE(hf_handle,name) \
{ &hf_handle ,{name ,name \
,FT_BOOLEAN ,0 ,NULL ,0x0 \
,"Identifies type of ATM PW. May be used for filtering.",HFILL}}
static hf_register_info hfa_n1_nocw[] = {
HF_INITIALIZER_NCELLS(hf_n1_nocw_ncells)
,HF_INITIALIZER_PWTYPE(hf_pw_type_n1_nocw,"pw.type.atm.n1nocw")
};
static hf_register_info hfa_n1_cw[] = {
HF_INITIALIZER_NCELLS(hf_n1_cw_ncells)
,HF_INITIALIZER_PWTYPE(hf_pw_type_n1_cw,"pw.type.atm.n1cw")
};
static hf_register_info hfa_11_aal5pdu[] = {
HF_INITIALIZER_NCELLS(hf_11_ncells)
,HF_INITIALIZER_PWTYPE(hf_pw_type_11_vcc,"pw.type.atm.11vcc")
,HF_INITIALIZER_PWTYPE(hf_pw_type_11_vpc,"pw.type.atm.11vpc")
,HF_INITIALIZER_PWTYPE(hf_pw_type_aal5_pdu,"pw.type.atm.aal5pdu")
};
static hf_register_info hfa_aal5_sdu[] = {
HF_INITIALIZER_PWTYPE(hf_pw_type_aal5_sdu,"pw.type.atm.aal5sdu")
};
static const value_string a5s_t_vals[] = {
{ 0, "AAL5 payload" },
{ 1, "ATM admin cell" },
{ 0, NULL }
};
static const value_string a5s_e_vals[] = {
{ 0, "No congestion" },
{ 1, "Congestion experienced" },
{ 0, NULL }
};
static hf_register_info hfa_cw[] = {
{ &hf_cw_bits03 ,{"Bits 0 to 3" ,"pw.cw.bits03"
,FT_UINT8 ,BASE_HEX ,NULL ,0xf0
,NULL ,HFILL }},
{ &hf_pref_cw_flags ,{"Flags" ,"pw.cw.flags"
,FT_UINT8 ,BASE_HEX ,NULL ,0x0f
,NULL ,HFILL }},
{ &hf_pref_cw_a5s_t ,{"Payload type" ,"atm.pt"
,FT_UINT8 ,BASE_DEC ,VALS(a5s_t_vals),0x08
,"Bit (T) of the control word indicates whether the packet contains"
" an ATM admin cell or an AAL5 payload. If T = 1, the packet"
" contains an ATM admin cell, encapsulated according to the N:1"
" cell relay encapsulation. If not set, the PDU"
" contains an AAL5 payload."
,HFILL }},
{ &hf_pref_cw_a5s_e ,{"EFCI bit" ,"atm.efci"
,FT_UINT8 ,BASE_DEC ,VALS(a5s_e_vals),0x04
,"The ingress router sets this bit to 1 if the EFCI bit"
" of the final cell of those that transported the AAL5 CPCS-SDU is"
" set to 1, or if the EFCI bit of the single ATM cell to be"
" transported in the packet is set to 1. Otherwise, this bit"
" is set to 0."
,HFILL }},
{ &hf_pref_cw_a5s_c ,{"CLP bit" ,"atm.clp"
,FT_UINT8 ,BASE_DEC ,VALS(clp_vals) ,0x02
,"The ingress router sets this bit to 1 if the CLP bit"
" of any of the ATM cells that transported the AAL5 CPCS-SDU is set"
" to 1, or if the CLP bit of the single ATM cell to be transported"
" in the packet is set to 1. Otherwise this bit is set to 0."
,HFILL }},
{ &hf_pref_cw_a5s_u ,{"U bit (Command/Response)" ,"pw.cw.aal5sdu.u"
,FT_UINT8 ,BASE_DEC ,NULL ,0x01
,"When FRF.8.1 Frame Relay/ATM PVC Service Interworking [RFC3916]"
" traffic is being transported, the Least-Significant Bit of CPCS-UU"
" of the AAL5 CPCS-PDU may contain the Frame Relay C/R bit."
" The ingress router copies this bit here."
,HFILL }},
{ &hf_pref_cw_rsv ,{"Reserved bits" ,"pw.cw.rsv"
,FT_UINT8 ,BASE_DEC ,NULL ,0xc0
,NULL ,HFILL }},
{ &hf_generic_cw_rsv ,{"Reserved bits" ,"pw.cw.rsv"
,FT_UINT8 ,BASE_DEC ,NULL ,0x0f
,NULL ,HFILL }},
{ &hf_pref_cw_len ,{"Length" ,"pw.cw.length"
,FT_UINT8 ,BASE_DEC ,NULL ,0x3f
,NULL ,HFILL }},
{ &hf_pref_cw_rsvlen ,{"Length (extended)" ,"pw.cw.length"
,FT_UINT8 ,BASE_DEC ,NULL ,0xff
,NULL ,HFILL }},
{ &hf_cw_seq ,{"Sequence number" ,"pw.cw.seqno"
,FT_UINT16 ,BASE_DEC ,NULL ,0
,NULL ,HFILL }},
{ &hf_gen_cw_atmbyte ,{"ATM-specific byte" ,"pw.cw.3rd_byte"
,FT_UINT8 ,BASE_HEX ,NULL ,0xFF
,NULL ,HFILL }}
};
static gint *ett_array[] = {
&ett_encaps
,&ett_cw
,&ett_cell_header
,&ett_cell
};
proto_n1_cw =
proto_register_protocol(pwc_longname_pw_atm_n1_cw
,shortname_n1_cw
,"mplspwatmn1cw");
proto_11_or_aal5_pdu =
proto_register_protocol(pwc_longname_pw_atm_11_or_aal5_pdu
,shortname_11_or_aal5_pdu
,"mplspwatm11_or_aal5pdu");
proto_aal5_sdu =
proto_register_protocol(pwc_longname_pw_atm_aal5_sdu
,shortname_aal5_sdu
,"mplspwatmaal5sdu");
proto_n1_nocw =
proto_register_protocol(pwc_longname_pw_atm_n1_nocw
,shortname_n1_nocw
,"mplspwatmn1nocw");
proto_control_word =
proto_register_protocol("MPLS PW ATM Control Word"
,"MPLS PW ATM Control Word"
,"mplspwatmcontrolword");
proto_cell_header =
proto_register_protocol("MPLS PW ATM Cell Header"
,"MPLS PW ATM Cell Header"
,"mplspwatmcellheader");
proto_cell =
proto_register_protocol("ATM Cell"
,"ATM Cell"
,"mplspwatmcell");
proto_register_field_array( proto_cell ,hfa_cell ,array_length(hfa_cell));
proto_register_field_array( proto_cell_header ,hfa_cell_header,array_length(hfa_cell_header));
proto_register_field_array( proto_control_word ,hfa_cw ,array_length(hfa_cw));
proto_register_field_array( proto_n1_nocw ,hfa_n1_nocw ,array_length(hfa_n1_nocw));
proto_register_field_array( proto_n1_cw ,hfa_n1_cw ,array_length(hfa_n1_cw));
proto_register_field_array( proto_11_or_aal5_pdu ,hfa_11_aal5pdu ,array_length(hfa_11_aal5pdu));
proto_register_field_array( proto_aal5_sdu ,hfa_aal5_sdu ,array_length(hfa_aal5_sdu));
proto_register_subtree_array(ett_array, array_length(ett_array));
register_dissector("mpls_pw_atm_aal5_sdu" ,dissect_aal5_sdu ,proto_aal5_sdu);
register_dissector("mpls_pw_atm_11_or_aal5_pdu" ,dissect_11_or_aal5_pdu ,proto_11_or_aal5_pdu);
register_dissector("mpls_pw_atm_n1_cw" ,dissect_n1_cw ,proto_n1_cw);
register_dissector("mpls_pw_atm_n1_nocw" ,dissect_n1_nocw ,proto_n1_nocw);
register_dissector("mpls_pw_atm_control_word" ,dissect_control_word ,proto_control_word);
new_register_dissector("mpls_pw_atm_cell" ,dissect_cell ,proto_cell);
new_register_dissector("mpls_pw_atm_cell_header",dissect_cell_header ,proto_cell_header);
{
static const char description_allow_cw_length_nonzero[] =
"Enable to allow non-zero Length in Control Word."
" This may be needed to correctly decode traffic from some legacy devices"
" which generate non-zero Length even if there is no padding in the packet."
" Note that Length should have proper value (dissector checks this anyway)."
"\n\n"
"Disable to blame all packets with CW.Length <> 0. This conforms to RFC4717."
;
static const char description_extend_cw_length_with_rsvd[] =
"Enable to use reserved bits (8..9) of Control Word as an extension of CW.Length."
" This may be needed to correctly decode traffic from some legacy devices"
" which uses reserved bits as extension of Length"
"\n\n"
"Disable to blame all packets with CW.Reserved <> 0. This conforms to RFC4717."
;
module_t * module_n1_cw;
module_t * module_aal5_sdu;
module_n1_cw = prefs_register_protocol(proto_n1_cw,NULL);
prefs_register_bool_preference(module_n1_cw
,"allow_cw_length_nonzero"
,"Allow CW.Length <> 0"
,&description_allow_cw_length_nonzero[0]
,&pref_n1_cw_allow_cw_length_nonzero);
prefs_register_bool_preference(module_n1_cw
,"extend_cw_length_with_rsvd"
,"Use CW.Reserved as extension of CW.Length"
,&description_extend_cw_length_with_rsvd[0]
,&pref_n1_cw_extend_cw_length_with_rsvd);
module_aal5_sdu = prefs_register_protocol(proto_aal5_sdu,NULL);
prefs_register_bool_preference(module_aal5_sdu
,"allow_cw_length_nonzero_aal5"
,"Allow CW.Length <> 0"
,&description_allow_cw_length_nonzero[0]
,&pref_aal5_sdu_allow_cw_length_nonzero);
prefs_register_bool_preference(module_aal5_sdu
,"extend_cw_length_with_rsvd_aal5"
,"Use CW.Reserved as extension of CW.Length"
,&description_extend_cw_length_with_rsvd[0]
,&pref_aal5_sdu_extend_cw_length_with_rsvd);
}
}
void
proto_reg_handoff_pw_atm_ata(void)
{
dissector_handle_t h;
h = find_dissector("mpls_pw_atm_n1_cw");
dissector_add_uint( "mpls.label", MPLS_LABEL_INVALID, h );
h = find_dissector("mpls_pw_atm_n1_nocw");
dissector_add_uint( "mpls.label", MPLS_LABEL_INVALID, h );
h = find_dissector("mpls_pw_atm_11_or_aal5_pdu");
dissector_add_uint( "mpls.label", MPLS_LABEL_INVALID, h );
h = find_dissector("mpls_pw_atm_aal5_sdu");
dissector_add_uint( "mpls.label", MPLS_LABEL_INVALID, h );
dh_cell = find_dissector("mpls_pw_atm_cell");
dh_cell_header = find_dissector("mpls_pw_atm_cell_header");
dh_control_word = find_dissector("mpls_pw_atm_control_word");
dh_atm_truncated = find_dissector("atm_truncated");
dh_atm_untruncated = find_dissector("atm_untruncated");
dh_atm_oam_cell = find_dissector("atm_oam_cell");
dh_padding = find_dissector("pw_padding");
dh_data = find_dissector("data");
}
