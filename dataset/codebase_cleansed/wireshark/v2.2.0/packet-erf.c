static erf_meta_tag_info_ex_t* erf_meta_tag_info_ex_new(wmem_allocator_t *allocator) {
gsize i = 0;
erf_meta_tag_info_ex_t *extra = wmem_new0(allocator, erf_meta_tag_info_ex_t);
extra->ett_value = -1;
for (i = 0; i < array_length(extra->hf_values); i++) {
extra->hf_values[i] = -1;
}
return extra;
}
static erf_meta_tag_info_t* erf_meta_tag_info_new(wmem_allocator_t *allocator, const erf_meta_hf_template_t *section, const erf_meta_hf_template_t *tag) {
erf_meta_tag_info_t *tag_info = wmem_new0(allocator, erf_meta_tag_info_t);
tag_info->code = tag->code;
tag_info->section = section->code;
tag_info->ett = -1;
tag_info->hf_value = -1;
tag_info->tag_template = tag;
tag_info->section_template = section;
tag_info->extra = NULL;
return tag_info;
}
static erf_meta_tag_info_t*
init_section_fields(wmem_array_t *hfri_table, wmem_array_t *ett_table, const erf_meta_hf_template_t *section)
{
erf_meta_tag_info_t *section_info;
gint *ett_tmp;
hf_register_info hfri_tmp[] = {
{ NULL, { "Section ID", NULL, FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ NULL, { "Section Length", NULL, FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ NULL, { "Reserved", NULL, FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL }}
};
section_info = erf_meta_tag_info_new(wmem_epan_scope(), section, section );
section_info->extra = erf_meta_tag_info_ex_new(wmem_epan_scope());
hfri_tmp[0].hfinfo.abbrev = wmem_strconcat(wmem_epan_scope(), "erf.meta.", section->hfinfo.abbrev, ".section_id", NULL);
hfri_tmp[0].p_id = &section_info->hf_value;
hfri_tmp[1].hfinfo.abbrev = wmem_strconcat(wmem_epan_scope(), "erf.meta.", section->hfinfo.abbrev, ".section_len", NULL);
hfri_tmp[1].p_id = &section_info->extra->hf_values[0];
hfri_tmp[2].hfinfo.abbrev = wmem_strconcat(wmem_epan_scope(), "erf.meta.", section->hfinfo.abbrev, ".section_hdr_rsvd", NULL);
hfri_tmp[2].p_id = &section_info->extra->hf_values[1];
wmem_array_append(hfri_table, hfri_tmp, array_length(hfri_tmp));
ett_tmp = &section_info->ett;
wmem_array_append(ett_table, &ett_tmp, 1);
ett_tmp = &section_info->extra->ett_value;
wmem_array_append(ett_table, &ett_tmp, 1);
return section_info;
}
static erf_meta_tag_info_t*
init_tag_value_field(wmem_array_t *hfri_table, erf_meta_tag_info_t *tag_info)
{
hf_register_info hfri_tmp = { NULL, { NULL, NULL, FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }};
hfri_tmp.p_id = &tag_info->hf_value;
hfri_tmp.hfinfo = tag_info->tag_template->hfinfo;
hfri_tmp.hfinfo.abbrev = wmem_strconcat(wmem_epan_scope(), "erf.meta.", tag_info->section_template->hfinfo.abbrev, ".", tag_info->tag_template->hfinfo.abbrev, NULL);
wmem_array_append_one(hfri_table, hfri_tmp);
return tag_info;
}
static erf_meta_tag_info_t*
init_tag_value_subfields(wmem_array_t *hfri_table, erf_meta_tag_info_t *tag_info, const header_field_info *extra_fields, int extra_fields_len)
{
int i = 0;
hf_register_info hfri_tmp = { NULL, { NULL, NULL, FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL }};
if (extra_fields) {
tag_info->extra = erf_meta_tag_info_ex_new(wmem_epan_scope());
for (i = 0; i < extra_fields_len; i++) {
hfri_tmp.p_id = &tag_info->extra->hf_values[i];
hfri_tmp.hfinfo = extra_fields[i];
hfri_tmp.hfinfo.abbrev = wmem_strconcat(wmem_epan_scope(), "erf.meta.", tag_info->section_template->hfinfo.abbrev, ".", tag_info->tag_template->hfinfo.abbrev, ".", extra_fields[i].abbrev, NULL);
wmem_array_append_one(hfri_table, hfri_tmp);
}
}
return tag_info;
}
static erf_meta_tag_info_t*
init_ns_addr_tag_value_fields(wmem_array_t *hfri_table, erf_meta_tag_info_t *tag_info)
{
header_field_info ns_addr_extra_fields[] = {
{ NULL, NULL, FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL },
{ "Name", "name", FT_STRING, BASE_NONE, NULL, 0x0, NULL, HFILL }
};
tag_info->extra = erf_meta_tag_info_ex_new(wmem_epan_scope());
ns_addr_extra_fields[0] = tag_info->tag_template->hfinfo;
ns_addr_extra_fields[0].name = "Address";
ns_addr_extra_fields[0].abbrev = "addr";
init_tag_value_subfields(hfri_table, tag_info, ns_addr_extra_fields, array_length(ns_addr_extra_fields));
return tag_info;
}
static erf_meta_tag_info_t*
init_tag_fields(wmem_array_t *hfri_table, wmem_array_t *ett_table, const erf_meta_hf_template_t *section, const erf_meta_hf_template_t *tag)
{
erf_meta_tag_info_t *tag_info;
gint *ett_tmp;
tag_info = erf_meta_tag_info_new(wmem_epan_scope(), section, tag);
switch (tag->code) {
case ERF_META_TAG_parent_section:
init_tag_value_subfields(hfri_table, tag_info, erf_parent_section, array_length(erf_parent_section));
break;
case ERF_META_TAG_ns_dns_ipv4:
case ERF_META_TAG_ns_dns_ipv6:
case ERF_META_TAG_ns_host_ipv4:
case ERF_META_TAG_ns_host_ipv6:
case ERF_META_TAG_ns_host_mac:
case ERF_META_TAG_ns_host_eui:
case ERF_META_TAG_ns_host_wwn:
case ERF_META_TAG_ns_host_ib_gid:
case ERF_META_TAG_ns_host_ib_lid:
case ERF_META_TAG_ns_host_fc_id:
init_ns_addr_tag_value_fields(hfri_table, tag_info);
break;
default:
init_tag_value_field(hfri_table, tag_info);
break;
}
switch (tag->code) {
case ERF_META_TAG_tunneling_mode:
init_tag_value_subfields(hfri_table, tag_info, erf_tunneling_modes, array_length(erf_tunneling_modes));
break;
case ERF_META_TAG_if_link_status:
init_tag_value_subfields(hfri_table, tag_info, erf_link_status, array_length(erf_link_status));
break;
case ERF_META_TAG_ptp_time_properties:
init_tag_value_subfields(hfri_table, tag_info, erf_ptp_time_properties_flags, array_length(erf_ptp_time_properties_flags));
break;
case ERF_META_TAG_ptp_gm_clock_quality:
init_tag_value_subfields(hfri_table, tag_info, erf_ptp_clock_quality, array_length(erf_ptp_clock_quality));
}
ett_tmp = &tag_info->ett;
wmem_array_append_one(ett_table, ett_tmp);
return tag_info;
}
static void
init_meta_tags(void)
{
unsigned int i, j = 0;
const erf_meta_hf_template_t *section = NULL;
const erf_meta_hf_template_t *tag = NULL;
erf_meta_tag_info_t *tag_info;
value_string vs_tmp = {0, NULL};
erf_meta_index.tag_table = wmem_map_new(wmem_epan_scope(), g_direct_hash, g_direct_equal);
erf_meta_index.vs_list = wmem_array_new(wmem_epan_scope(), sizeof(value_string));
erf_meta_index.vs_abbrev_list = wmem_array_new(wmem_epan_scope(), sizeof(value_string));
erf_meta_index.hfri = wmem_array_new(wmem_epan_scope(), sizeof(hf_register_info));
erf_meta_index.ett = wmem_array_new(wmem_epan_scope(), sizeof(gint*));
for (j = 0; j < array_length(erf_meta_tags); j++) {
tag = &erf_meta_tags[j];
for (i = 0; i < array_length(erf_meta_sections); i++) {
section = &erf_meta_sections[i];
tag_info = init_tag_fields(erf_meta_index.hfri, erf_meta_index.ett, section, tag);
wmem_map_insert(erf_meta_index.tag_table, GUINT_TO_POINTER(ERF_TAG_INFO_KEY(tag_info)), tag_info);
}
vs_tmp.value = tag->code;
vs_tmp.strptr = tag->hfinfo.name;
wmem_array_append_one(erf_meta_index.vs_list, vs_tmp);
vs_tmp.value = tag->code;
vs_tmp.strptr = tag->hfinfo.abbrev;
wmem_array_append_one(erf_meta_index.vs_abbrev_list, vs_tmp);
}
for (i = 1; i < array_length(erf_meta_sections); i++) {
section = &erf_meta_sections[i];
tag_info = init_section_fields(erf_meta_index.hfri, erf_meta_index.ett, section);
if (i != 1) {
wmem_map_insert(erf_meta_index.tag_table, GUINT_TO_POINTER(ERF_TAG_INFO_KEY(tag_info)), tag_info);
vs_tmp.value = section->code;
vs_tmp.strptr = section->hfinfo.name;
wmem_array_append_one(erf_meta_index.vs_list, vs_tmp);
vs_tmp.value = section->code;
vs_tmp.strptr = section->hfinfo.abbrev;
wmem_array_append_one(erf_meta_index.vs_abbrev_list, vs_tmp);
} else {
erf_meta_index.unknown_section_info = tag_info;
}
}
vs_tmp.value = 0;
vs_tmp.strptr = NULL;
wmem_array_append_one(erf_meta_index.vs_list, vs_tmp);
wmem_array_append_one(erf_meta_index.vs_abbrev_list, vs_tmp);
}
static int
erf_source_append(guint64 host_id, guint8 source_id, guint32 num)
{
erf_source_info_t *source_info;
guint64 source_key = ERF_SOURCE_KEY(host_id, source_id);
source_info = (erf_source_info_t*) wmem_map_lookup(erf_state.source_map, &source_key);
if (!source_info) {
guint64 *source_key_ptr = wmem_new(wmem_file_scope(), guint64);
*source_key_ptr = source_key;
source_info = (erf_source_info_t*) wmem_new(wmem_file_scope(), erf_source_info_t);
source_info->meta_tree = wmem_tree_new(wmem_file_scope());
source_info->meta_list = wmem_list_new(wmem_file_scope());
wmem_map_insert(erf_state.source_map, source_key_ptr, source_info);
}
wmem_list_append(source_info->meta_list, GUINT_TO_POINTER(num));
wmem_tree_insert32(source_info->meta_tree, num, wmem_list_tail(source_info->meta_list));
return 0;
}
static guint32
erf_source_find_closest(guint64 host_id, guint8 source_id, guint32 fnum, guint32 *fnum_next_ptr) {
wmem_list_frame_t *list_frame = NULL;
wmem_list_frame_t *list_frame_prev = NULL;
erf_source_info_t *source_info = NULL;
guint64 source_key = ERF_SOURCE_KEY(host_id, source_id);
guint32 fnum_prev = G_MAXUINT32;
guint32 fnum_next = G_MAXUINT32;
source_info = (erf_source_info_t*) wmem_map_lookup(erf_state.source_map, &source_key);
if (source_info) {
list_frame = (wmem_list_frame_t*) wmem_tree_lookup32_le(source_info->meta_tree, fnum);
if (list_frame) {
fnum_prev = GPOINTER_TO_UINT(wmem_list_frame_data(list_frame));
if (fnum_prev == fnum) {
list_frame_prev = wmem_list_frame_prev(list_frame);
fnum_prev = list_frame_prev ? GPOINTER_TO_UINT(wmem_list_frame_data(list_frame_prev)) : G_MAXUINT32;
}
list_frame = wmem_list_frame_next(list_frame);
fnum_next = list_frame ? GPOINTER_TO_UINT(wmem_list_frame_data(list_frame)) : G_MAXUINT32;
} else {
list_frame = wmem_list_head(source_info->meta_list);
fnum_next = list_frame ? GPOINTER_TO_UINT(wmem_list_frame_data(list_frame)) : G_MAXUINT32;
fnum_prev = G_MAXUINT32;
}
}
if (fnum_next_ptr)
*fnum_next_ptr = fnum_next;
return fnum_prev;
}
static void
erf_atm_guess_lane_type(tvbuff_t *tvb, int offset, guint len,
struct atm_phdr *atm_info)
{
if (len >= 2) {
if (tvb_get_ntohs(tvb, offset) == 0xFF00) {
atm_info->subtype = TRAF_ST_LANE_LE_CTRL;
} else {
atm_info->subtype = TRAF_ST_LANE_802_3;
}
}
}
static void
erf_atm_guess_traffic_type(tvbuff_t *tvb, int offset, guint len,
struct atm_phdr *atm_info)
{
atm_info->aal = AAL_5;
atm_info->type = TRAF_UNKNOWN;
atm_info->subtype = TRAF_ST_UNKNOWN;
if (atm_info->vpi == 0) {
switch (atm_info->vci) {
case 5:
atm_info->aal = AAL_SIGNALLING;
return;
case 16:
atm_info->type = TRAF_ILMI;
return;
}
}
if (len >= 3) {
guint8 mtp3b;
if (tvb_get_ntoh24(tvb, offset) == 0xAAAA03) {
atm_info->type = TRAF_LLCMX;
} else if ((atm_info->aal5t_len &&
atm_info->aal5t_len < 16) || len<16) {
atm_info->aal = AAL_SIGNALLING;
} else if (((mtp3b = tvb_get_guint8(tvb, offset)) == 0x83) || (mtp3b == 0x81)) {
atm_info->aal = AAL_SIGNALLING;
} else {
atm_info->type = TRAF_LANE;
erf_atm_guess_lane_type(tvb, offset, len, atm_info);
}
} else {
atm_info->aal = AAL_SIGNALLING;
}
}
static void
dissect_classification_ex_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int idx)
{
if (tree) {
proto_item *flags_item;
proto_tree *flags_tree;
guint64 hdr = pinfo->pseudo_header->erf.ehdr_list[idx].ehdr;
guint32 value = ((guint32)(hdr >> 32)) & EHDR_CLASS_FLAGS_MASK;
flags_item = proto_tree_add_uint(tree, hf_erf_ehdr_class_flags, tvb, 0, 0, value);
flags_tree = proto_item_add_subtree(flags_item, ett_erf_flags);
proto_tree_add_uint(flags_tree, hf_erf_ehdr_class_flags_sh, tvb, 0, 0, value);
proto_tree_add_uint(flags_tree, hf_erf_ehdr_class_flags_shm, tvb, 0, 0, value);
proto_tree_add_uint(flags_tree, hf_erf_ehdr_class_flags_res1, tvb, 0, 0, value);
proto_tree_add_uint(flags_tree, hf_erf_ehdr_class_flags_user, tvb, 0, 0, value);
proto_tree_add_uint(flags_tree, hf_erf_ehdr_class_flags_res2, tvb, 0, 0, value);
proto_tree_add_uint(flags_tree, hf_erf_ehdr_class_flags_drop, tvb, 0, 0, value);
proto_tree_add_uint(flags_tree, hf_erf_ehdr_class_flags_str, tvb, 0, 0, value);
proto_tree_add_uint(tree, hf_erf_ehdr_class_seqnum, tvb, 0, 0, (guint32)hdr);
}
}
static void
dissect_intercept_ex_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int idx)
{
if (tree) {
guint64 hdr = pinfo->pseudo_header->erf.ehdr_list[idx].ehdr;
proto_tree_add_uint(tree, hf_erf_ehdr_int_res1, tvb, 0, 0, (guint8)((hdr >> 48) & 0xFF));
proto_tree_add_uint(tree, hf_erf_ehdr_int_id, tvb, 0, 0, (guint16)((hdr >> 32 ) & 0xFFFF));
proto_tree_add_uint(tree, hf_erf_ehdr_int_res2, tvb, 0, 0, (guint32)hdr);
}
}
static void
dissect_raw_link_ex_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int idx)
{
if (tree) {
guint64 hdr = pinfo->pseudo_header->erf.ehdr_list[idx].ehdr;
proto_tree_add_uint(tree, hf_erf_ehdr_raw_link_res , tvb, 0, 0, (guint32)((hdr >> 32) & 0xFFFFFF));
proto_tree_add_uint(tree, hf_erf_ehdr_raw_link_seqnum , tvb, 0, 0, (guint32)((hdr >> 16) & 0xffff));
proto_tree_add_uint(tree, hf_erf_ehdr_raw_link_rate, tvb, 0, 0, (guint32)((hdr >> 8) & 0x00ff));
proto_tree_add_uint(tree, hf_erf_ehdr_raw_link_type, tvb, 0, 0, (guint32)(hdr & 0x00ff));
}
}
static void
dissect_bfs_ex_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int idx)
{
if (tree) {
guint64 hdr = pinfo->pseudo_header->erf.ehdr_list[idx].ehdr;
proto_tree_add_uint(tree, hf_erf_ehdr_bfs_hash, tvb, 0, 0, (guint32)((hdr >> 48) & 0xFF));
proto_tree_add_uint(tree, hf_erf_ehdr_bfs_color, tvb, 0, 0, (guint32)((hdr >> 32) & 0xFFFF));
proto_tree_add_uint(tree, hf_erf_ehdr_bfs_raw_hash, tvb, 0, 0, (guint32)(hdr & 0xFFFFFFFF));
}
}
static int
channelised_fill_sdh_g707_format(sdh_g707_format_t* in_fmt, guint16 bit_flds, guint8 vc_size, guint8 rate)
{
int i = 0;
if ( (0 == vc_size) || (vc_size > DECHAN_MAX_VC_SIZE) || (rate > DECHAN_MAX_LINE_RATE) )
{
in_fmt->m_vc_size = 0;
in_fmt->m_sdh_line_rate = 0;
memset(&(in_fmt->m_vc_index_array[0]), 0x00, DECHAN_MAX_AUG_INDEX);
return -1;
}
in_fmt->m_vc_size = vc_size;
in_fmt->m_sdh_line_rate = rate;
memset(&(in_fmt->m_vc_index_array[0]), 0xff, DECHAN_MAX_AUG_INDEX);
for (i = (rate - 2); i >= 0; i--)
{
guint8 aug_n_index = 0;
if ( i >= (vc_size - 1))
{
aug_n_index = ((bit_flds >> (2 *i))& 0x3) +1;
}
else
{
aug_n_index = 0;
}
in_fmt->m_vc_index_array[i] = aug_n_index;
}
return 0;
}
static void
channelised_fill_vc_id_string(wmem_strbuf_t* out_string, sdh_g707_format_t* in_fmt)
{
int i;
gboolean is_printed = FALSE;
static const char* g_vc_size_strings[] = {
"unknown",
"VC3",
"VC4",
"VC4-4c",
"VC4-16c",
"VC4-64c", };
wmem_strbuf_truncate(out_string, 0);
if ( (in_fmt->m_vc_size > DECHAN_MAX_VC_SIZE) || (in_fmt->m_sdh_line_rate > DECHAN_MAX_LINE_RATE) )
{
wmem_strbuf_append_printf(out_string, "Malformed");
return;
}
wmem_strbuf_append_printf(out_string, "%s(",
(in_fmt->m_vc_size < array_length(g_vc_size_strings)) ?
g_vc_size_strings[in_fmt->m_vc_size] : g_vc_size_strings[0] );
if (in_fmt->m_sdh_line_rate <= 0 )
{
for (i = (DECHAN_MAX_AUG_INDEX -1); i >= 0; i--)
{
if ((in_fmt->m_vc_index_array[i] > 0) || (is_printed) )
{
wmem_strbuf_append_printf(out_string, "%s%d",
((is_printed)?", ":""),
in_fmt->m_vc_index_array[i]);
is_printed = TRUE;
}
}
}
else
{
for (i = in_fmt->m_sdh_line_rate - 2; i >= 0; i--)
{
wmem_strbuf_append_printf(out_string, "%s%d",
((is_printed)?", ":""),
in_fmt->m_vc_index_array[i]);
is_printed = TRUE;
}
}
if ( ! is_printed )
{
for ( i =0; i < in_fmt->m_vc_size - 2; i++)
{
wmem_strbuf_append_printf(out_string, "%s0",
((is_printed)?", ":""));
is_printed = TRUE;
}
}
wmem_strbuf_append_c(out_string, ')');
return;
}
static void
dissect_channelised_ex_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int idx)
{
guint64 hdr = pinfo->pseudo_header->erf.ehdr_list[idx].ehdr;
guint8 vc_id = (guint8)((hdr >> 24) & 0xFF);
guint8 vc_size = (guint8)((hdr >> 16) & 0xFF);
guint8 line_rate = (guint8)((hdr >> 8) & 0xFF);
sdh_g707_format_t g707_format;
wmem_strbuf_t *vc_id_string = wmem_strbuf_new_label(wmem_packet_scope());
channelised_fill_sdh_g707_format(&g707_format, vc_id, vc_size, line_rate);
channelised_fill_vc_id_string(vc_id_string, &g707_format);
if (tree) {
proto_tree_add_boolean(tree, hf_erf_ehdr_chan_morebits, tvb, 0, 0, (guint8)((hdr >> 63) & 0x1));
proto_tree_add_boolean(tree, hf_erf_ehdr_chan_morefrag, tvb, 0, 0, (guint8)((hdr >> 55) & 0x1));
proto_tree_add_uint(tree, hf_erf_ehdr_chan_seqnum, tvb, 0, 0, (guint16)((hdr >> 40) & 0x7FFF));
proto_tree_add_uint(tree, hf_erf_ehdr_chan_res, tvb, 0, 0, (guint8)((hdr >> 32) & 0xFF));
proto_tree_add_uint_format_value(tree, hf_erf_ehdr_chan_virt_container_id, tvb, 0, 0, vc_id,
"0x%.2x (g.707: %s)", vc_id, wmem_strbuf_get_str(vc_id_string));
proto_tree_add_uint(tree, hf_erf_ehdr_chan_assoc_virt_container_size, tvb, 0, 0, vc_size);
proto_tree_add_uint(tree, hf_erf_ehdr_chan_rate, tvb, 0, 0, line_rate);
proto_tree_add_uint(tree, hf_erf_ehdr_chan_type, tvb, 0, 0, (guint8)((hdr >> 0) & 0xFF));
}
}
static void
dissect_signature_ex_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int idx)
{
if(tree) {
guint64 hdr = pinfo->pseudo_header->erf.ehdr_list[idx].ehdr;
proto_tree_add_uint(tree, hf_erf_ehdr_signature_payload_hash, tvb, 0, 0, (guint32)((hdr >> 32) & 0xFFFFFF));
proto_tree_add_uint(tree, hf_erf_ehdr_signature_color, tvb, 0, 0, (guint8)((hdr >> 24) & 0xFF));
proto_tree_add_uint(tree, hf_erf_ehdr_signature_flow_hash, tvb, 0, 0, (guint32)(hdr & 0xFFFFFF));
}
}
static void
dissect_host_id_ex_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int idx)
{
if(tree) {
guint64 hdr = pinfo->pseudo_header->erf.ehdr_list[idx].ehdr;
proto_tree_add_uint(tree, hf_erf_ehdr_host_id_sourceid, tvb, 0, 0, (guint8)((hdr >> 48) & 0xFF));
proto_tree_add_uint64(tree, hf_erf_ehdr_host_id_hostid, tvb, 0, 0, (hdr & ERF_EHDR_HOST_ID_MASK));
}
}
static void
dissect_flow_id_ex_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int idx)
{
if(tree) {
guint64 hdr = pinfo->pseudo_header->erf.ehdr_list[idx].ehdr;
proto_tree_add_uint(tree, hf_erf_ehdr_flow_id_source_id, tvb, 0, 0, (guint8)((hdr >> 48) & 0xFF));
proto_tree_add_uint(tree, hf_erf_ehdr_flow_id_hash_type, tvb, 0, 0, (guint8)((hdr >> 40) & 0xFF));
proto_tree_add_uint(tree, hf_erf_ehdr_flow_id_stack_type, tvb, 0, 0, (guint8)((hdr >> 32) & 0xFF));
proto_tree_add_uint(tree, hf_erf_ehdr_flow_id_flow_hash, tvb, 0, 0, (guint32)(hdr & 0xFFFFFFFF));
}
}
static guint64
find_host_id(packet_info *pinfo) {
guint64 *hdr = NULL;
hdr = erf_get_ehdr(pinfo, ERF_EXT_HDR_TYPE_HOST_ID, NULL);
return hdr ? (*hdr & ERF_EHDR_HOST_ID_MASK) : 0;
}
static void
dissect_host_id_source_id(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint64 host_id, guint8 source_id)
{
if (tree) {
proto_tree *hostid_tree;
proto_item *pi = NULL;
guint32 fnum_current = G_MAXUINT32;
guint32 fnum = G_MAXUINT32;
guint32 fnum_next = G_MAXUINT32;
fnum = erf_source_find_closest(host_id, source_id, pinfo->num, &fnum_next);
if (fnum != G_MAXUINT32) {
fnum_current = fnum;
} else {
fnum_current = fnum_next;
}
if (fnum_current != G_MAXUINT32) {
pi = proto_tree_add_uint_format(tree, hf_erf_source_current, tvb, 0, 0, fnum_current,
"Host ID: 0x%012" G_GINT64_MODIFIER "x, Source ID: %u", host_id, source_id&0xFF);
hostid_tree = proto_item_add_subtree(pi, ett_erf_source);
} else {
hostid_tree = proto_tree_add_subtree_format(tree, tvb, 0, 0, ett_erf_source, &pi,
"Host ID: 0x%012" G_GINT64_MODIFIER "x, Source ID: %u", host_id, source_id&0xFF);
}
PROTO_ITEM_SET_GENERATED(pi);
pi = proto_tree_add_uint64(hostid_tree, hf_erf_hostid, tvb, 0, 0, host_id);
PROTO_ITEM_SET_GENERATED(pi);
pi = proto_tree_add_uint(hostid_tree, hf_erf_sourceid, tvb, 0, 0, source_id);
PROTO_ITEM_SET_GENERATED(pi);
if (fnum_next != G_MAXUINT32) {
pi = proto_tree_add_uint(hostid_tree, hf_erf_source_next, tvb, 0, 0, fnum_next);
PROTO_ITEM_SET_GENERATED(pi);
}
if (fnum != G_MAXUINT32) {
pi = proto_tree_add_uint(hostid_tree, hf_erf_source_prev, tvb, 0, 0, fnum);
PROTO_ITEM_SET_GENERATED(pi);
}
}
}
static void
dissect_unknown_ex_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int idx)
{
if (tree) {
guint64 hdr = pinfo->pseudo_header->erf.ehdr_list[idx].ehdr;
proto_tree_add_uint64(tree, hf_erf_ehdr_unk, tvb, 0, 0, hdr);
}
}
static void
dissect_mc_hdlc_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (tree) {
proto_item *mc_hdlc_item;
proto_tree *mc_hdlc_tree;
guint32 mc_hdlc;
proto_item *pi;
mc_hdlc_item = proto_tree_add_uint(tree, hf_erf_mc_hdlc, tvb, 0, 0, pinfo->pseudo_header->erf.subhdr.mc_hdr);
mc_hdlc_tree = proto_item_add_subtree(mc_hdlc_item, ett_erf_mc_hdlc);
mc_hdlc = pinfo->pseudo_header->erf.subhdr.mc_hdr;
proto_tree_add_uint(mc_hdlc_tree, hf_erf_mc_hdlc_cn, tvb, 0, 0, mc_hdlc);
proto_tree_add_uint(mc_hdlc_tree, hf_erf_mc_hdlc_res1, tvb, 0, 0, mc_hdlc);
proto_tree_add_uint(mc_hdlc_tree, hf_erf_mc_hdlc_res2, tvb, 0, 0, mc_hdlc);
pi=proto_tree_add_uint(mc_hdlc_tree, hf_erf_mc_hdlc_fcse, tvb, 0, 0, mc_hdlc);
if (mc_hdlc & MC_HDLC_FCSE_MASK)
expert_add_info_format(pinfo, pi, &ei_erf_checksum_error, "ERF MC FCS Error");
pi=proto_tree_add_uint(mc_hdlc_tree, hf_erf_mc_hdlc_sre, tvb, 0, 0, mc_hdlc);
if (mc_hdlc & MC_HDLC_SRE_MASK)
expert_add_info_format(pinfo, pi, &ei_erf_checksum_error, "ERF MC Short Record Error, <5 bytes");
pi=proto_tree_add_uint(mc_hdlc_tree, hf_erf_mc_hdlc_lre, tvb, 0, 0, mc_hdlc);
if (mc_hdlc & MC_HDLC_LRE_MASK)
expert_add_info_format(pinfo, pi, &ei_erf_checksum_error, "ERF MC Long Record Error, >2047 bytes");
pi=proto_tree_add_uint(mc_hdlc_tree, hf_erf_mc_hdlc_afe, tvb, 0, 0, mc_hdlc);
if (mc_hdlc & MC_HDLC_AFE_MASK)
expert_add_info_format(pinfo, pi, &ei_erf_checksum_error, "ERF MC Aborted Frame Error");
pi=proto_tree_add_uint(mc_hdlc_tree, hf_erf_mc_hdlc_oe, tvb, 0, 0, mc_hdlc);
if (mc_hdlc & MC_HDLC_OE_MASK)
expert_add_info_format(pinfo, pi, &ei_erf_checksum_error, "ERF MC Octet Error, the closing flag was not octet aligned after bit unstuffing");
pi=proto_tree_add_uint(mc_hdlc_tree, hf_erf_mc_hdlc_lbe, tvb, 0, 0, mc_hdlc);
if (mc_hdlc & MC_HDLC_LBE_MASK)
expert_add_info_format(pinfo, pi, &ei_erf_checksum_error, "ERF MC Lost Byte Error");
proto_tree_add_uint(mc_hdlc_tree, hf_erf_mc_hdlc_first, tvb, 0, 0, mc_hdlc);
proto_tree_add_uint(mc_hdlc_tree, hf_erf_mc_hdlc_res3, tvb, 0, 0, mc_hdlc);
}
}
static void
dissect_mc_raw_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (tree) {
proto_item *mc_raw_item;
proto_tree *mc_raw_tree;
guint32 mc_raw;
mc_raw_item = proto_tree_add_uint(tree, hf_erf_mc_raw, tvb, 0, 0, pinfo->pseudo_header->erf.subhdr.mc_hdr);
mc_raw_tree = proto_item_add_subtree(mc_raw_item, ett_erf_mc_raw);
mc_raw = pinfo->pseudo_header->erf.subhdr.mc_hdr;
proto_tree_add_uint(mc_raw_tree, hf_erf_mc_raw_int, tvb, 0, 0, mc_raw);
proto_tree_add_uint(mc_raw_tree, hf_erf_mc_raw_res1, tvb, 0, 0, mc_raw);
proto_tree_add_uint(mc_raw_tree, hf_erf_mc_raw_sre, tvb, 0, 0, mc_raw);
proto_tree_add_uint(mc_raw_tree, hf_erf_mc_raw_lre, tvb, 0, 0, mc_raw);
proto_tree_add_uint(mc_raw_tree, hf_erf_mc_raw_res2, tvb, 0, 0, mc_raw);
proto_tree_add_uint(mc_raw_tree, hf_erf_mc_raw_lbe, tvb, 0, 0, mc_raw);
proto_tree_add_uint(mc_raw_tree, hf_erf_mc_raw_first, tvb, 0, 0, mc_raw);
proto_tree_add_uint(mc_raw_tree, hf_erf_mc_raw_res3, tvb, 0, 0, mc_raw);
}
}
static void
dissect_mc_atm_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (tree) {
proto_item *mc_atm_item;
proto_tree *mc_atm_tree;
guint32 mc_atm;
mc_atm_item = proto_tree_add_uint(tree, hf_erf_mc_atm, tvb, 0, 0, pinfo->pseudo_header->erf.subhdr.mc_hdr);
mc_atm_tree = proto_item_add_subtree(mc_atm_item, ett_erf_mc_atm);
mc_atm = pinfo->pseudo_header->erf.subhdr.mc_hdr;
proto_tree_add_uint(mc_atm_tree, hf_erf_mc_atm_cn, tvb, 0, 0, mc_atm);
proto_tree_add_uint(mc_atm_tree, hf_erf_mc_atm_res1, tvb, 0, 0, mc_atm);
proto_tree_add_uint(mc_atm_tree, hf_erf_mc_atm_mul, tvb, 0, 0, mc_atm);
proto_tree_add_uint(mc_atm_tree, hf_erf_mc_atm_port, tvb, 0, 0, mc_atm);
proto_tree_add_uint(mc_atm_tree, hf_erf_mc_atm_res2, tvb, 0, 0, mc_atm);
proto_tree_add_uint(mc_atm_tree, hf_erf_mc_atm_lbe, tvb, 0, 0, mc_atm);
proto_tree_add_uint(mc_atm_tree, hf_erf_mc_atm_hec, tvb, 0, 0, mc_atm);
proto_tree_add_uint(mc_atm_tree, hf_erf_mc_atm_crc10, tvb, 0, 0, mc_atm);
proto_tree_add_uint(mc_atm_tree, hf_erf_mc_atm_oamcell, tvb, 0, 0, mc_atm);
proto_tree_add_uint(mc_atm_tree, hf_erf_mc_atm_first, tvb, 0, 0, mc_atm);
proto_tree_add_uint(mc_atm_tree, hf_erf_mc_atm_res3, tvb, 0, 0, mc_atm);
}
}
static void
dissect_mc_rawlink_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (tree) {
proto_item *mc_rawl_item;
proto_tree *mc_rawl_tree;
guint32 mc_rawl;
mc_rawl_item = proto_tree_add_uint(tree, hf_erf_mc_rawl, tvb, 0, 0, pinfo->pseudo_header->erf.subhdr.mc_hdr);
mc_rawl_tree = proto_item_add_subtree(mc_rawl_item, ett_erf_mc_rawlink);
mc_rawl = pinfo->pseudo_header->erf.subhdr.mc_hdr;
proto_tree_add_uint(mc_rawl_tree, hf_erf_mc_rawl_cn, tvb, 0, 0, mc_rawl);
proto_tree_add_uint(mc_rawl_tree, hf_erf_mc_rawl_res1, tvb, 0, 0, mc_rawl);
proto_tree_add_uint(mc_rawl_tree, hf_erf_mc_rawl_lbe, tvb, 0, 0, mc_rawl);
proto_tree_add_uint(mc_rawl_tree, hf_erf_mc_rawl_first, tvb, 0, 0, mc_rawl);
proto_tree_add_uint(mc_rawl_tree, hf_erf_mc_rawl_res2, tvb, 0, 0, mc_rawl);
}
}
static void
dissect_mc_aal5_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (tree) {
proto_item *mc_aal5_item;
proto_tree *mc_aal5_tree;
guint32 mc_aal5;
mc_aal5_item = proto_tree_add_uint(tree, hf_erf_mc_aal5, tvb, 0, 0, pinfo->pseudo_header->erf.subhdr.mc_hdr);
mc_aal5_tree = proto_item_add_subtree(mc_aal5_item, ett_erf_mc_aal5);
mc_aal5 = pinfo->pseudo_header->erf.subhdr.mc_hdr;
proto_tree_add_uint(mc_aal5_tree, hf_erf_mc_aal5_cn, tvb, 0, 0, mc_aal5);
proto_tree_add_uint(mc_aal5_tree, hf_erf_mc_aal5_res1, tvb, 0, 0, mc_aal5);
proto_tree_add_uint(mc_aal5_tree, hf_erf_mc_aal5_port, tvb, 0, 0, mc_aal5);
proto_tree_add_uint(mc_aal5_tree, hf_erf_mc_aal5_crcck, tvb, 0, 0, mc_aal5);
proto_tree_add_uint(mc_aal5_tree, hf_erf_mc_aal5_crce, tvb, 0, 0, mc_aal5);
proto_tree_add_uint(mc_aal5_tree, hf_erf_mc_aal5_lenck, tvb, 0, 0, mc_aal5);
proto_tree_add_uint(mc_aal5_tree, hf_erf_mc_aal5_lene, tvb, 0, 0, mc_aal5);
proto_tree_add_uint(mc_aal5_tree, hf_erf_mc_aal5_res2, tvb, 0, 0, mc_aal5);
proto_tree_add_uint(mc_aal5_tree, hf_erf_mc_aal5_first, tvb, 0, 0, mc_aal5);
proto_tree_add_uint(mc_aal5_tree, hf_erf_mc_aal5_res3, tvb, 0, 0, mc_aal5);
}
}
static void
dissect_mc_aal2_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (tree) {
proto_item *mc_aal2_item;
proto_tree *mc_aal2_tree;
guint32 mc_aal2;
mc_aal2_item = proto_tree_add_uint(tree, hf_erf_mc_aal2, tvb, 0, 0, pinfo->pseudo_header->erf.subhdr.mc_hdr);
mc_aal2_tree = proto_item_add_subtree(mc_aal2_item, ett_erf_mc_aal2);
mc_aal2 = pinfo->pseudo_header->erf.subhdr.mc_hdr;
proto_tree_add_uint(mc_aal2_tree, hf_erf_mc_aal2_cn, tvb, 0, 0, mc_aal2);
proto_tree_add_uint(mc_aal2_tree, hf_erf_mc_aal2_res1, tvb, 0, 0, mc_aal2);
proto_tree_add_uint(mc_aal2_tree, hf_erf_mc_aal2_res2, tvb, 0, 0, mc_aal2);
proto_tree_add_uint(mc_aal2_tree, hf_erf_mc_aal2_port, tvb, 0, 0, mc_aal2);
proto_tree_add_uint(mc_aal2_tree, hf_erf_mc_aal2_res3, tvb, 0, 0, mc_aal2);
proto_tree_add_uint(mc_aal2_tree, hf_erf_mc_aal2_first, tvb, 0, 0, mc_aal2);
proto_tree_add_uint(mc_aal2_tree, hf_erf_mc_aal2_maale, tvb, 0, 0, mc_aal2);
proto_tree_add_uint(mc_aal2_tree, hf_erf_mc_aal2_lene, tvb, 0, 0, mc_aal2);
proto_tree_add_uint(mc_aal2_tree, hf_erf_mc_aal2_cid, tvb, 0, 0, mc_aal2);
}
}
static void
dissect_aal2_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (tree) {
proto_item *aal2_item;
proto_tree *aal2_tree;
guint32 aal2;
aal2_item = proto_tree_add_uint(tree, hf_erf_aal2, tvb, 0, 0, pinfo->pseudo_header->erf.subhdr.mc_hdr);
aal2_tree = proto_item_add_subtree(aal2_item, ett_erf_aal2);
aal2 = pinfo->pseudo_header->erf.subhdr.aal2_hdr;
proto_tree_add_uint(aal2_tree, hf_erf_aal2_cid, tvb, 0, 0, aal2);
proto_tree_add_uint(aal2_tree, hf_erf_aal2_maale, tvb, 0, 0, aal2);
proto_tree_add_uint(aal2_tree, hf_erf_aal2_maalei, tvb, 0, 0, aal2);
proto_tree_add_uint(aal2_tree, hf_erf_aal2_first, tvb, 0, 0, aal2);
proto_tree_add_uint(aal2_tree, hf_erf_aal2_res1, tvb, 0, 0, aal2);
}
}
static void
dissect_eth_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
if (tree) {
proto_item *eth_item;
proto_tree *eth_tree;
guint8 eth_offset, eth_pad;
eth_item = proto_tree_add_item(tree, hf_erf_eth, tvb, 0, 0, ENC_NA);
eth_tree = proto_item_add_subtree(eth_item, ett_erf_eth);
eth_offset = pinfo->pseudo_header->erf.subhdr.eth_hdr.offset;
eth_pad = pinfo->pseudo_header->erf.subhdr.eth_hdr.pad;
proto_tree_add_uint(eth_tree, hf_erf_eth_off, tvb, 0, 0, eth_offset);
proto_tree_add_uint(eth_tree, hf_erf_eth_pad, tvb, 0, 0, eth_pad);
}
}
static void
dissect_erf_pseudo_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *pi;
proto_item *flags_item, *rectype_item;
proto_tree *flags_tree, *rectype_tree;
proto_tree_add_uint64(tree, hf_erf_ts, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.ts);
rectype_item = proto_tree_add_uint_format_value(tree, hf_erf_rectype, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.type,
"0x%02x (Type %d: %s)",
pinfo->pseudo_header->erf.phdr.type,
pinfo->pseudo_header->erf.phdr.type & ERF_HDR_TYPE_MASK,
val_to_str_const(
pinfo->pseudo_header->erf.phdr.type & ERF_HDR_TYPE_MASK,
erf_type_vals,
"Unknown Type"));
rectype_tree = proto_item_add_subtree(rectype_item, ett_erf_rectype);
proto_tree_add_uint(rectype_tree, hf_erf_type, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.type);
proto_tree_add_uint(rectype_tree, hf_erf_ehdr, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.type);
flags_item=proto_tree_add_uint(tree, hf_erf_flags, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.flags);
flags_tree = proto_item_add_subtree(flags_item, ett_erf_flags);
proto_tree_add_uint(flags_tree, hf_erf_flags_cap, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.flags);
proto_item_append_text(flags_item, " (Capture Interface: %d", pinfo->pseudo_header->erf.phdr.flags & ERF_HDR_CAP_MASK);
proto_tree_add_uint(flags_tree, hf_erf_flags_vlen, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.flags);
pi=proto_tree_add_uint(flags_tree, hf_erf_flags_trunc, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.flags);
if (pinfo->pseudo_header->erf.phdr.flags & ERF_HDR_TRUNC_MASK) {
proto_item_append_text(flags_item, "; ERF Truncation Error");
expert_add_info_format(pinfo, pi, &ei_erf_checksum_error, "ERF Truncation Error");
}
pi=proto_tree_add_uint(flags_tree, hf_erf_flags_rxe, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.flags);
if (pinfo->pseudo_header->erf.phdr.flags & ERF_HDR_RXE_MASK) {
proto_item_append_text(flags_item, "; ERF Rx Error");
expert_add_info_format(pinfo, pi, &ei_erf_checksum_error, "ERF Rx Error");
}
pi=proto_tree_add_uint(flags_tree, hf_erf_flags_dse, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.flags);
if (pinfo->pseudo_header->erf.phdr.flags & ERF_HDR_DSE_MASK) {
proto_item_append_text(flags_item, "; ERF DS Error");
expert_add_info_format(pinfo, pi, &ei_erf_checksum_error, "ERF DS Error");
}
proto_item_append_text(flags_item, ")");
proto_tree_add_uint(flags_tree, hf_erf_flags_res, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.flags);
proto_tree_add_uint(tree, hf_erf_rlen, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.rlen);
pi=proto_tree_add_uint(tree, hf_erf_lctr, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.lctr);
if (pinfo->pseudo_header->erf.phdr.lctr > 0)
expert_add_info(pinfo, pi, &ei_erf_packet_loss);
proto_tree_add_uint(tree, hf_erf_wlen, tvb, 0, 0, pinfo->pseudo_header->erf.phdr.wlen);
}
static void
dissect_erf_pseudo_extension_header(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *pi;
proto_item *ehdr_tree;
guint64 hdr;
guint8 type;
guint8 has_more = pinfo->pseudo_header->erf.phdr.type & 0x80;
int i = 0;
int max = sizeof(pinfo->pseudo_header->erf.ehdr_list)/sizeof(struct erf_ehdr);
guint64 host_id = 0;
guint8 source_id = 0;
guint64 host_id_last = 0;
guint8 source_id_last = 0;
host_id = find_host_id(pinfo);
if (host_id == 0) {
host_id = erf_state.implicit_host_id;
}
while(has_more && (i < max)) {
hdr = pinfo->pseudo_header->erf.ehdr_list[i].ehdr;
type = (guint8) (hdr >> 56);
pi = proto_tree_add_uint(tree, hf_erf_ehdr_t, tvb, 0, 0, (type & 0x7f));
ehdr_tree = proto_item_add_subtree(pi, ett_erf_pseudo_hdr);
switch (type & 0x7f) {
case ERF_EXT_HDR_TYPE_CLASSIFICATION:
dissect_classification_ex_header(tvb, pinfo, ehdr_tree, i);
break;
case ERF_EXT_HDR_TYPE_INTERCEPTID:
dissect_intercept_ex_header(tvb, pinfo, ehdr_tree, i);
break;
case ERF_EXT_HDR_TYPE_RAW_LINK:
dissect_raw_link_ex_header(tvb, pinfo, ehdr_tree, i);
break;
case ERF_EXT_HDR_TYPE_BFS:
dissect_bfs_ex_header(tvb, pinfo, ehdr_tree, i);
break;
case ERF_EXT_HDR_TYPE_CHANNELISED:
dissect_channelised_ex_header(tvb, pinfo, ehdr_tree, i);
break;
case ERF_EXT_HDR_TYPE_SIGNATURE:
dissect_signature_ex_header(tvb, pinfo, ehdr_tree, i);
break;
case ERF_EXT_HDR_TYPE_FLOW_ID:
source_id = (guint8)((hdr >> 48) & 0xFF);
dissect_flow_id_ex_header(tvb, pinfo, ehdr_tree, i);
break;
case ERF_EXT_HDR_TYPE_HOST_ID:
host_id = hdr & ERF_EHDR_HOST_ID_MASK;
source_id = (guint8)((hdr >> 48) & 0xFF);
dissect_host_id_ex_header(tvb, pinfo, ehdr_tree, i);
break;
default:
dissect_unknown_ex_header(tvb, pinfo, ehdr_tree, i);
break;
}
if (source_id != source_id_last || host_id != host_id_last) {
if (!PINFO_FD_VISITED(pinfo)) {
if ((pinfo->pseudo_header->erf.phdr.type & 0x7f) == ERF_TYPE_META) {
if (erf_state.implicit_host_id == 0 && source_id > 0) {
erf_state.implicit_host_id = host_id;
}
erf_source_append(host_id, source_id, pinfo->num);
}
}
dissect_host_id_source_id(tvb, pinfo, tree, host_id, source_id);
}
host_id_last = host_id;
source_id_last = source_id;
has_more = type & 0x80;
i += 1;
}
if (has_more) {
proto_tree_add_expert(tree, pinfo, &ei_erf_extension_headers_not_shown, tvb, 0, 0);
}
}
guint64* erf_get_ehdr(packet_info *pinfo, guint8 hdrtype, gint* afterindex) {
guint8 type;
guint8 has_more;
int max;
int i = afterindex ? *afterindex + 1 : 0;
if (!pinfo)
return NULL;
has_more = pinfo->pseudo_header->erf.phdr.type & 0x80;
max = sizeof(pinfo->pseudo_header->erf.ehdr_list)/sizeof(struct erf_ehdr);
while(has_more && (i < max)) {
type = (guint8) (pinfo->pseudo_header->erf.ehdr_list[i].ehdr >> 56);
if ((type & 0x7f) == (hdrtype & 0x7f)) {
if (afterindex)
*afterindex = i;
return &pinfo->pseudo_header->erf.ehdr_list[i].ehdr;
}
has_more = type & 0x80;
i += 1;
}
return NULL;
}
static void
check_section_length(packet_info *pinfo, proto_item *sectionlen_pi, int offset, int sectionoffset, int sectionlen) {
if (sectionlen_pi) {
if (offset - sectionoffset == sectionlen) {
proto_item_append_text(sectionlen_pi, " [correct]");
} else if (sectionlen != 0) {
proto_item_append_text(sectionlen_pi, " [incorrect, should be %u]", offset - sectionoffset);
expert_add_info(pinfo, sectionlen_pi, &ei_erf_meta_section_len_error);
}
}
}
static proto_item*
dissect_meta_tag_bitfield(proto_item *section_tree, tvbuff_t *tvb, int offset, erf_meta_tag_info_t *tag_info, proto_item **out_tag_tree)
{
proto_item *tag_pi = NULL;
const int* hf_flags[ERF_HF_VALUES_PER_TAG];
int i;
DISSECTOR_ASSERT(tag_info->extra);
for (i = 0; tag_info->extra->hf_values[i] != -1; i++) {
hf_flags[i] = &tag_info->extra->hf_values[i];
}
hf_flags[i] = NULL;
tag_pi = proto_tree_add_bitmask_with_flags(section_tree, tvb, offset + 4, tag_info->hf_value, tag_info->ett, hf_flags, ENC_BIG_ENDIAN, BMT_NO_FLAGS);
if (out_tag_tree) {
*out_tag_tree = proto_item_get_subtree(tag_pi);
}
return tag_pi;
}
static void erf_ts_to_nstime(guint64 timestamp, nstime_t* t, gboolean is_relative) {
guint64 ts = timestamp;
if (is_relative) {
ts = (guint64) ABS((gint64)timestamp);
}
t->secs = (long) (ts >> 32);
ts = ((ts & 0xffffffff) * 1000 * 1000 * 1000);
ts += (ts & 0x80000000) << 1;
t->nsecs = ((int) (ts >> 32));
if (t->nsecs >= NS_PER_S) {
t->nsecs -= NS_PER_S;
t->secs += 1;
}
if (is_relative && (gint64)timestamp < 0) {
t->secs = -(t->secs);
t->nsecs = -(t->nsecs);
}
}
static proto_item *dissect_relative_time(proto_tree *tree, const int hfindex, tvbuff_t *tvb, gint offset, gint length, nstime_t* t) {
proto_item *pi = NULL;
DISSECTOR_ASSERT(t);
if (t->secs == 0 && t->nsecs < 1000000 && t->nsecs > -1000000) {
pi = proto_tree_add_time_format_value(tree, hfindex, tvb, offset, length, t, "%d nanoseconds", t->nsecs);
} else {
pi = proto_tree_add_time(tree, hfindex, tvb, offset, length, t);
}
return pi;
}
static proto_item *dissect_ptp_timeinterval(proto_tree *tree, const int hfindex, tvbuff_t *tvb, gint offset, gint length, gint64 timeinterval) {
nstime_t t;
guint64 ti, ti_ns;
ti = (guint64) ABS(timeinterval);
ti += (ti & 0x8000) << 1;
ti_ns = ti >> 16;
t.secs = ti_ns / NS_PER_S;
t.nsecs = (guint32)(ti_ns % NS_PER_S);
if (t.nsecs >= NS_PER_S) {
t.nsecs -= NS_PER_S;
t.secs += 1;
}
if (timeinterval < 0) {
t.secs = -(t.secs);
t.nsecs = -(t.nsecs);
}
return dissect_relative_time(tree, hfindex, tvb, offset, length, &t);
}
static int
meta_tag_expected_length(erf_meta_tag_info_t *tag_info) {
ftenum_t ftype = tag_info->tag_template->hfinfo.type;
int expected_length = 0;
switch (ftype) {
case FT_ABSOLUTE_TIME:
case FT_RELATIVE_TIME:
expected_length = 8;
break;
default:
expected_length = ftype_length(ftype);
break;
}
switch (tag_info->code) {
case ERF_META_TAG_ptp_current_utc_offset:
expected_length = 4;
break;
case ERF_META_TAG_if_wwn:
case ERF_META_TAG_src_wwn:
case ERF_META_TAG_dest_wwn:
case ERF_META_TAG_ns_host_wwn:
expected_length = 16;
break;
}
return expected_length;
}
static void
dissect_meta_record_tags(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
proto_item *pi = NULL;
proto_item *tag_pi = NULL;
proto_item *tag_tree;
proto_item *section_pi = NULL;
proto_item *section_tree = tree;
proto_item *sectionlen_pi = NULL;
guint16 sectiontype = ERF_META_SECTION_NONE;
guint16 tagtype = 0;
guint16 taglength = 0;
const gchar *tagvalstring = NULL;
erf_meta_tag_info_t *tag_info;
int expected_length = 0;
expert_field *truncated_expert = NULL;
gboolean skip_truncated = FALSE;
erf_meta_hf_template_t tag_template_unknown = { 0, { "Unknown", "unknown",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } };
erf_meta_tag_info_t tag_info_local = { 0, 0, &tag_template_unknown, &tag_template_unknown,
ett_erf_meta_tag, hf_erf_meta_tag_unknown, NULL };
int offset = 0;
int sectionoffset = 0;
guint16 sectionid = 0;
guint16 sectionlen = 0;
int remaining_len = 0;
int captured_length = (int) tvb_captured_length(tvb);
col_set_str(pinfo->cinfo, COL_INFO, "MetaERF Record");
while ((remaining_len = captured_length - offset) >= 4) {
tagtype = tvb_get_ntohs(tvb, offset);
taglength = tvb_get_ntohs(tvb, offset + 2);
tag_tree = NULL;
tag_pi = NULL;
truncated_expert = NULL;
skip_truncated = FALSE;
if (ERF_META_IS_SECTION(tagtype))
sectiontype = tagtype;
tag_info_local.code = tagtype;
tag_info_local.section = sectiontype;
tag_info = (erf_meta_tag_info_t*) wmem_map_lookup(erf_meta_index.tag_table, GUINT_TO_POINTER(ERF_TAG_INFO_KEY(&tag_info_local)));
if (tag_info == NULL)
tag_info = &tag_info_local;
expected_length = meta_tag_expected_length(tag_info);
if (remaining_len < (gint32)taglength + 4 || taglength < expected_length) {
skip_truncated = TRUE;
truncated_expert = &ei_erf_meta_truncated_tag;
}
if (taglength == 0) {
if (!ERF_META_IS_SECTION(tagtype) && tagtype != ERF_META_TAG_padding) {
truncated_expert = &ei_erf_meta_zero_len_tag;
if (expected_length != 0) {
skip_truncated = TRUE;
}
}
}
if (ERF_META_IS_SECTION(tagtype)) {
if (section_pi) {
proto_item_set_len(section_pi, offset - sectionoffset);
if (sectionlen_pi) {
check_section_length(pinfo, sectionlen_pi, offset, sectionoffset, sectionlen);
}
}
sectionoffset = offset;
if (tag_info->tag_template == &tag_template_unknown) {
sectiontype = ERF_META_SECTION_UNKNOWN;
tag_info = erf_meta_index.unknown_section_info;
}
DISSECTOR_ASSERT(tag_info->extra);
tagvalstring = val_to_str(tagtype, VALS(wmem_array_get_raw(erf_meta_index.vs_list)), "Unknown Section (0x%x)");
section_tree = proto_tree_add_subtree_format(tree, tvb, offset, 0, tag_info->extra->ett_value, &section_pi, "MetaERF %s", tagvalstring);
tag_tree = proto_tree_add_subtree_format(section_tree, tvb, offset, MIN(taglength + 4, remaining_len), tag_info->ett, &tag_pi, "%s Header", tagvalstring);
if (taglength >= 4 && !skip_truncated) {
sectionid = tvb_get_ntohs(tvb, offset + 4);
sectionlen = tvb_get_ntohs(tvb, offset + 6);
proto_tree_add_uint(tag_tree, tag_info->hf_value, tvb, offset + 4, 2, sectionid);
if (sectionid != 0)
proto_item_append_text(section_pi, " %u", sectionid);
sectionlen_pi = proto_tree_add_uint(tag_tree, tag_info->extra->hf_values[0], tvb, offset + 6, 2, sectionlen);
if (taglength > 4) {
proto_tree_add_item(tag_tree, tag_info->extra->hf_values[1], tvb, offset + 8, taglength - 4, ENC_NA);
}
} else if (taglength != 0) {
truncated_expert = &ei_erf_meta_truncated_tag;
}
} else if (!skip_truncated) {
enum ftenum tag_ft;
char pi_label[ITEM_LABEL_LENGTH+1];
gboolean dissected = TRUE;
guint32 value32;
guint64 value64;
gchar *tmp = NULL;
tag_ft = tag_info->tag_template->hfinfo.type;
pi_label[0] = '\0';
if (offset == 0) {
section_tree = proto_tree_add_subtree(tree, tvb, offset, 0, ett_erf_meta, &section_pi, "MetaERF No Section");
}
switch (tagtype) {
case ERF_META_TAG_if_speed:
case ERF_META_TAG_if_tx_speed:
value64 = tvb_get_ntoh64(tvb, offset + 4);
tmp = format_size((gint64) value64, (format_size_flags_e)(format_size_unit_bits_s|format_size_prefix_si));
tag_pi = proto_tree_add_uint64_format_value(section_tree, tag_info->hf_value, tvb, offset + 4, taglength, value64, "%s (%" G_GINT64_MODIFIER "u bps)", tmp, value64);
g_free(tmp);
break;
case ERF_META_TAG_if_rx_power:
case ERF_META_TAG_if_tx_power:
value32 = tvb_get_ntohl(tvb, offset + 4);
tag_pi = proto_tree_add_int_format_value(section_tree, tag_info->hf_value, tvb, offset + 4, taglength, (gint32) value32, "%.2fdBm", (float)((gint32) value32)/100.0);
break;
case ERF_META_TAG_loc_lat:
case ERF_META_TAG_loc_long:
value32 = tvb_get_ntohl(tvb, offset + 4);
tag_pi = proto_tree_add_int_format_value(section_tree, tag_info->hf_value, tvb, offset + 4, taglength, (gint32) value32, "%.2f", (double)((gint32) value32)*1000000.0);
break;
case ERF_META_TAG_mask_cidr:
value32 = tvb_get_ntohl(tvb, offset + 4);
tag_pi = proto_tree_add_uint_format_value(section_tree, tag_info->hf_value, tvb, offset + 4, taglength, value32, "/%u", value32);
break;
case ERF_META_TAG_mem:
value64 = tvb_get_ntoh64(tvb, offset + 4);
tmp = format_size((gint64) value64, (format_size_flags_e)(format_size_unit_bytes|format_size_prefix_iec));
tag_pi = proto_tree_add_uint64_format_value(section_tree, tag_info->hf_value, tvb, offset + 4, taglength, value64, "%s (%" G_GINT64_MODIFIER"u bytes)", tmp, value64);
g_free(tmp);
break;
case ERF_META_TAG_parent_section:
DISSECTOR_ASSERT(tag_info->extra);
value32 = tvb_get_ntohs(tvb, offset + 4);
tag_tree = proto_tree_add_subtree_format(section_tree, tvb, offset + 4, taglength, tag_info->ett, &tag_pi, "%s: %s %u", tag_info->tag_template->hfinfo.name,
val_to_str(value32, VALS(wmem_array_get_raw(erf_meta_index.vs_list)), "Unknown Section (%u)"), tvb_get_ntohs(tvb, offset + 4 + 2));
proto_tree_add_uint_format_value(tag_tree, tag_info->extra->hf_values[0], tvb, offset + 4, MIN(2, taglength), value32, "%s (%u)",
val_to_str(value32, VALS(wmem_array_get_raw(erf_meta_index.vs_abbrev_list)), "Unknown"), value32);
proto_tree_add_item(tag_tree, tag_info->extra->hf_values[1], tvb, offset + 6, MIN(2, taglength - 2), ENC_BIG_ENDIAN);
break;
case ERF_META_TAG_reset:
tag_pi = proto_tree_add_item(section_tree, tag_info->hf_value, tvb, offset + 4, taglength, ENC_NA);
expert_add_info(pinfo, tag_pi, &ei_erf_meta_reset);
break;
case ERF_META_TAG_if_link_status:
case ERF_META_TAG_tunneling_mode:
case ERF_META_TAG_ptp_time_properties:
case ERF_META_TAG_ptp_gm_clock_quality:
tag_pi = dissect_meta_tag_bitfield(section_tree, tvb, offset, tag_info, &tag_tree);
break;
case ERF_META_TAG_ns_dns_ipv4:
case ERF_META_TAG_ns_dns_ipv6:
case ERF_META_TAG_ns_host_ipv4:
case ERF_META_TAG_ns_host_ipv6:
case ERF_META_TAG_ns_host_mac:
case ERF_META_TAG_ns_host_eui:
case ERF_META_TAG_ns_host_wwn:
case ERF_META_TAG_ns_host_ib_gid:
case ERF_META_TAG_ns_host_ib_lid:
case ERF_META_TAG_ns_host_fc_id:
{
int addr_len = ftype_length(tag_ft);
DISSECTOR_ASSERT(tag_info->extra);
tag_tree = proto_tree_add_subtree(section_tree, tvb, offset + 4, taglength, tag_info->ett, &tag_pi, tag_info->tag_template->hfinfo.name);
pi = proto_tree_add_item(tag_tree, tag_info->extra->hf_values[0], tvb, offset + 4, MIN(addr_len, taglength), IS_FT_INT(tag_ft) || IS_FT_UINT(tag_ft) ? ENC_BIG_ENDIAN : ENC_NA);
proto_tree_add_item(tag_tree, tag_info->extra->hf_values[1], tvb, offset + 4 + addr_len, taglength - addr_len, ENC_UTF_8);
if (pi) {
proto_item_fill_label(PITEM_FINFO(pi), pi_label);
proto_item_append_text(tag_pi, ": %s, %s",
tvb_get_stringzpad(wmem_packet_scope(), tvb, offset + 4 + addr_len, taglength - addr_len, ENC_UTF_8), pi_label );
}
break;
}
case ERF_META_TAG_ptp_offset_from_master:
case ERF_META_TAG_ptp_mean_path_delay:
value64 = tvb_get_ntoh64(tvb, offset + 4);
tag_pi = dissect_ptp_timeinterval(section_tree, tag_info->hf_value, tvb, offset + 4, taglength, (gint64) value64);
break;
case ERF_META_TAG_ptp_current_utc_offset:
{
nstime_t t;
value32 = tvb_get_ntohl(tvb, offset + 4);
t.secs = (gint32) value32;
t.nsecs = 0;
tag_pi = dissect_relative_time(section_tree, tag_info->hf_value, tvb, offset + 4, taglength, &t);
break;
}
default:
dissected = FALSE;
break;
}
if (!dissected) {
if (IS_FT_INT(tag_ft) || IS_FT_UINT(tag_ft)) {
tag_pi = proto_tree_add_item(section_tree, tag_info->hf_value, tvb, offset + 4, taglength, ENC_BIG_ENDIAN);
} else if (IS_FT_STRING(tag_ft)) {
tag_pi = proto_tree_add_item(section_tree, tag_info->hf_value, tvb, offset + 4, taglength, ENC_UTF_8);
} else if (IS_FT_TIME(tag_ft)) {
nstime_t t;
guint64 ts;
ts = tvb_get_letoh64(tvb, offset + 4);
erf_ts_to_nstime(ts, &t, tag_ft == FT_RELATIVE_TIME);
tag_pi = dissect_relative_time(section_tree, tag_info->hf_value, tvb, offset + 4, taglength, &t);
} else {
tag_pi = proto_tree_add_item(section_tree, tag_info->hf_value, tvb, offset + 4, taglength, ENC_NA);
}
}
}
if (!tag_tree) {
if (tag_pi || !tree) {
tag_tree = proto_item_add_subtree(tag_pi, tag_info->ett);
} else {
tag_tree = proto_tree_add_subtree_format(section_tree, tvb, offset, MIN(taglength + 4, remaining_len), tag_info->ett, &tag_pi, "%s: [Invalid]", tag_info->tag_template->hfinfo.name);
}
}
proto_tree_add_uint_format_value(tag_tree, hf_erf_meta_tag_type, tvb, offset, 2, tagtype, "%s (%u)", val_to_str(tagtype, VALS(wmem_array_get_raw(erf_meta_index.vs_abbrev_list)), "Unknown"), tagtype);
proto_tree_add_uint(tag_tree, hf_erf_meta_tag_len, tvb, offset + 2, 2, taglength);
if (truncated_expert) {
expert_add_info(pinfo, tag_pi, truncated_expert);
}
offset += (((guint32)taglength + 4) + 0x3U) & ~0x3U;
}
if (remaining_len != 0) {
expert_add_info(pinfo, proto_tree_get_parent(tree), &ei_erf_meta_truncated_record);
}
proto_item_set_len(section_pi, offset - sectionoffset);
check_section_length(pinfo, sectionlen_pi, offset, sectionoffset, sectionlen);
}
static int
dissect_erf(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
guint8 flags;
guint8 erf_type;
guint32 atm_hdr = 0;
proto_tree *erf_tree;
proto_item *erf_item;
erf_hdlc_type_vals hdlc_type;
guint8 first_byte;
tvbuff_t *new_tvb;
guint8 aal2_cid;
struct atm_phdr atm_info;
erf_type=pinfo->pseudo_header->erf.phdr.type & 0x7F;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ERF");
col_add_fstr(pinfo->cinfo, COL_INFO, "%s",
val_to_str(erf_type, erf_type_vals, "Unknown type %u"));
erf_item = proto_tree_add_item(tree, proto_erf, tvb, 0, -1, ENC_NA);
erf_tree = proto_item_add_subtree(erf_item, ett_erf);
dissect_erf_pseudo_header(tvb, pinfo, erf_tree);
if (pinfo->pseudo_header->erf.phdr.type & 0x80) {
dissect_erf_pseudo_extension_header(tvb, pinfo, erf_tree);
}
flags = pinfo->pseudo_header->erf.phdr.flags;
pinfo->p2p_dir = ( (flags & 0x01) ? P2P_DIR_RECV : P2P_DIR_SENT);
switch (erf_type) {
case ERF_TYPE_RAW_LINK:
if(sdh_handle) {
call_dissector(sdh_handle, tvb, pinfo, tree);
}
else{
call_data_dissector(tvb, pinfo, tree);
}
break;
case ERF_TYPE_ETH:
case ERF_TYPE_COLOR_ETH:
case ERF_TYPE_DSM_COLOR_ETH:
case ERF_TYPE_COLOR_HASH_ETH:
dissect_eth_header(tvb, pinfo, erf_tree);
case ERF_TYPE_IPV4:
case ERF_TYPE_IPV6:
case ERF_TYPE_INFINIBAND:
case ERF_TYPE_INFINIBAND_LINK:
case ERF_TYPE_OPA_SNC:
case ERF_TYPE_OPA_9B:
if (!dissector_try_uint(erf_dissector_table, erf_type, tvb, pinfo, tree)) {
call_data_dissector(tvb, pinfo, tree);
}
break;
case ERF_TYPE_LEGACY:
case ERF_TYPE_IP_COUNTER:
case ERF_TYPE_TCP_FLOW_COUNTER:
break;
case ERF_TYPE_PAD:
break;
case ERF_TYPE_MC_RAW:
dissect_mc_raw_header(tvb, pinfo, erf_tree);
call_data_dissector(tvb, pinfo, tree);
break;
case ERF_TYPE_MC_RAW_CHANNEL:
dissect_mc_rawlink_header(tvb, pinfo, erf_tree);
call_data_dissector(tvb, pinfo, tree);
break;
case ERF_TYPE_MC_ATM:
dissect_mc_atm_header(tvb, pinfo, erf_tree);
case ERF_TYPE_ATM:
memset(&atm_info, 0, sizeof(atm_info));
atm_hdr = tvb_get_ntohl(tvb, 0);
atm_info.vpi = ((atm_hdr & 0x0ff00000) >> 20);
atm_info.vci = ((atm_hdr & 0x000ffff0) >> 4);
atm_info.channel = (flags & 0x03);
if (erf_rawcell_first) {
new_tvb = tvb_new_subset_remaining(tvb, ATM_HDR_LENGTH);
atm_info.aal = AAL_5;
switch (erf_aal5_type) {
case ERF_AAL5_GUESS:
atm_info.type = TRAF_UNKNOWN;
atm_info.subtype = TRAF_ST_UNKNOWN;
erf_atm_guess_traffic_type(new_tvb, 0, tvb_captured_length(new_tvb), &atm_info);
break;
case ERF_AAL5_LLC:
atm_info.type = TRAF_LLCMX;
atm_info.subtype = TRAF_ST_UNKNOWN;
break;
case ERF_AAL5_UNSPEC:
atm_info.aal = AAL_5;
atm_info.type = TRAF_UNKNOWN;
atm_info.subtype = TRAF_ST_UNKNOWN;
break;
}
call_dissector_with_data(atm_untruncated_handle, new_tvb, pinfo, tree,
&atm_info);
} else {
atm_info.flags |= ATM_RAW_CELL;
atm_info.flags |= ATM_NO_HEC;
atm_info.aal = AAL_UNKNOWN;
call_dissector_with_data(atm_untruncated_handle, tvb, pinfo, tree,
&atm_info);
}
break;
case ERF_TYPE_MC_AAL5:
dissect_mc_aal5_header(tvb, pinfo, erf_tree);
case ERF_TYPE_AAL5:
atm_hdr = tvb_get_ntohl(tvb, 0);
memset(&atm_info, 0, sizeof(atm_info));
atm_info.vpi = ((atm_hdr & 0x0ff00000) >> 20);
atm_info.vci = ((atm_hdr & 0x000ffff0) >> 4);
atm_info.channel = (flags & 0x03);
new_tvb = tvb_new_subset_remaining(tvb, ATM_HDR_LENGTH);
atm_info.aal = AAL_5;
switch (erf_aal5_type) {
case ERF_AAL5_GUESS:
atm_info.type = TRAF_UNKNOWN;
atm_info.subtype = TRAF_ST_UNKNOWN;
erf_atm_guess_traffic_type(new_tvb, 0, tvb_captured_length(new_tvb), &atm_info);
break;
case ERF_AAL5_LLC:
atm_info.type = TRAF_LLCMX;
atm_info.subtype = TRAF_ST_UNKNOWN;
break;
case ERF_AAL5_UNSPEC:
atm_info.aal = AAL_5;
atm_info.type = TRAF_UNKNOWN;
atm_info.subtype = TRAF_ST_UNKNOWN;
break;
}
call_dissector_with_data(atm_untruncated_handle, new_tvb, pinfo, tree,
&atm_info);
break;
case ERF_TYPE_MC_AAL2:
dissect_mc_aal2_header(tvb, pinfo, erf_tree);
atm_hdr = tvb_get_ntohl(tvb, 0);
aal2_cid = (pinfo->pseudo_header->erf.subhdr.mc_hdr & MC_AAL2_CID_MASK) >> MC_AAL2_CID_SHIFT;
memset(&atm_info, 0, sizeof(atm_info));
atm_info.aal = AAL_2;
atm_info.flags |= ATM_AAL2_NOPHDR;
atm_info.vpi = ((atm_hdr & 0x0ff00000) >> 20);
atm_info.vci = ((atm_hdr & 0x000ffff0) >> 4);
atm_info.channel = (flags & 0x03);
atm_info.aal2_cid = aal2_cid;
atm_info.type = TRAF_UNKNOWN;
atm_info.subtype = TRAF_ST_UNKNOWN;
new_tvb = tvb_new_subset_remaining(tvb, ATM_HDR_LENGTH);
call_dissector_with_data(atm_untruncated_handle, new_tvb, pinfo, tree,
&atm_info);
break;
case ERF_TYPE_AAL2:
dissect_aal2_header(tvb, pinfo, erf_tree);
atm_hdr = tvb_get_ntohl(tvb, 0);
aal2_cid = (pinfo->pseudo_header->erf.subhdr.aal2_hdr & AAL2_CID_MASK) >> AAL2_CID_SHIFT;
memset(&atm_info, 0, sizeof(atm_info));
atm_info.aal = AAL_2;
atm_info.flags |= ATM_AAL2_NOPHDR;
atm_info.vpi = ((atm_hdr & 0x0ff00000) >> 20);
atm_info.vci = ((atm_hdr & 0x000ffff0) >> 4);
atm_info.channel = (flags & 0x03);
atm_info.aal2_cid = aal2_cid;
atm_info.type = TRAF_UNKNOWN;
atm_info.subtype = TRAF_ST_UNKNOWN;
new_tvb = tvb_new_subset_remaining(tvb, ATM_HDR_LENGTH);
call_dissector_with_data(atm_untruncated_handle, new_tvb, pinfo, tree,
&atm_info);
break;
case ERF_TYPE_MC_HDLC:
dissect_mc_hdlc_header(tvb, pinfo, erf_tree);
case ERF_TYPE_HDLC_POS:
case ERF_TYPE_COLOR_HDLC_POS:
case ERF_TYPE_DSM_COLOR_HDLC_POS:
case ERF_TYPE_COLOR_MC_HDLC_POS:
case ERF_TYPE_COLOR_HASH_POS:
hdlc_type = (erf_hdlc_type_vals)erf_hdlc_type;
if (hdlc_type == ERF_HDLC_GUESS) {
first_byte = tvb_get_guint8(tvb, 0);
if (first_byte == 0x0f || first_byte == 0x8f)
hdlc_type = ERF_HDLC_CHDLC;
else {
hdlc_type = ERF_HDLC_PPP;
}
}
switch (hdlc_type) {
case ERF_HDLC_CHDLC:
call_dissector(chdlc_handle, tvb, pinfo, tree);
break;
case ERF_HDLC_PPP:
call_dissector(ppp_handle, tvb, pinfo, tree);
break;
case ERF_HDLC_FRELAY:
memset(&pinfo->pseudo_header->x25, 0, sizeof(pinfo->pseudo_header->x25));
call_dissector(frelay_handle, tvb, pinfo, tree);
break;
case ERF_HDLC_MTP2:
memset(&pinfo->pseudo_header->mtp2, 0, sizeof(pinfo->pseudo_header->mtp2));
call_dissector(mtp2_handle, tvb, pinfo, tree);
break;
default:
break;
}
break;
case ERF_TYPE_META:
dissect_meta_record_tags(tvb, pinfo, erf_tree);
break;
default:
call_data_dissector(tvb, pinfo, tree);
break;
}
return tvb_captured_length(tvb);
}
static void erf_init_dissection(void)
{
erf_state.implicit_host_id = 0;
erf_state.source_map = wmem_map_new(wmem_file_scope(), wmem_int64_hash, g_int64_equal);
}
void
proto_register_erf(void)
{
static hf_register_info hf[] = {
{ &hf_erf_ts,
{ "Timestamp", "erf.ts",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_rectype,
{ "Record type", "erf.types",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_type,
{ "Type", "erf.types.type",
FT_UINT8, BASE_DEC, VALS(erf_type_vals), ERF_HDR_TYPE_MASK, NULL, HFILL } },
{ &hf_erf_ehdr,
{ "Extension header present", "erf.types.ext_header",
FT_UINT8, BASE_DEC, NULL, ERF_HDR_EHDR_MASK, NULL, HFILL } },
{ &hf_erf_flags,
{ "Flags", "erf.flags",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_flags_cap,
{ "Capture interface", "erf.flags.cap",
FT_UINT8, BASE_DEC, NULL, ERF_HDR_CAP_MASK, NULL, HFILL } },
{ &hf_erf_flags_vlen,
{ "Varying record length", "erf.flags.vlen",
FT_UINT8, BASE_DEC, NULL, ERF_HDR_VLEN_MASK, NULL, HFILL } },
{ &hf_erf_flags_trunc,
{ "Truncated", "erf.flags.trunc",
FT_UINT8, BASE_DEC, NULL, ERF_HDR_TRUNC_MASK, NULL, HFILL } },
{ &hf_erf_flags_rxe,
{ "RX error", "erf.flags.rxe",
FT_UINT8, BASE_DEC, NULL, ERF_HDR_RXE_MASK, NULL, HFILL } },
{ &hf_erf_flags_dse,
{ "DS error", "erf.flags.dse",
FT_UINT8, BASE_DEC, NULL, ERF_HDR_DSE_MASK, NULL, HFILL } },
{ &hf_erf_flags_res,
{ "Reserved", "erf.flags.res",
FT_UINT8, BASE_HEX, NULL, ERF_HDR_RES_MASK, NULL, HFILL } },
{ &hf_erf_rlen,
{ "Record length", "erf.rlen",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_lctr,
{ "Loss counter", "erf.lctr",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_wlen,
{ "Wire length", "erf.wlen",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_ehdr_t,
{ "Extension Header", "erf.ehdr.types",
FT_UINT8, BASE_DEC, VALS(ehdr_type_vals), 0x0, NULL, HFILL } },
{ &hf_erf_ehdr_int_res1,
{ "Reserved", "erf.ehdr.int.res1",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_ehdr_int_id,
{ "Intercept ID", "erf.ehdr.int.intid",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_ehdr_int_res2,
{ "Reserved", "erf.ehdr.int.res2",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_ehdr_raw_link_res,
{ "Reserved", "erf.ehdr.raw.res",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_ehdr_raw_link_seqnum,
{ "Sequence number", "erf.ehdr.raw.seqnum",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_ehdr_raw_link_rate,
{ "Rate", "erf.ehdr.raw.rate",
FT_UINT8, BASE_DEC, VALS(raw_link_rates), 0x0, NULL, HFILL } },
{ &hf_erf_ehdr_raw_link_type,
{ "Link Type", "erf.ehdr.raw.link_type",
FT_UINT8, BASE_DEC, VALS(raw_link_types), 0x0, NULL, HFILL } },
{ &hf_erf_ehdr_class_flags,
{ "Flags", "erf.ehdr.class.flags",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_ehdr_class_flags_sh,
{ "Search hit", "erf.ehdr.class.flags.sh",
FT_UINT32, BASE_DEC, NULL, EHDR_CLASS_SH_MASK, NULL, HFILL } },
{ &hf_erf_ehdr_class_flags_shm,
{ "Multiple search hits", "erf.ehdr.class.flags.shm",
FT_UINT32, BASE_DEC, NULL, EHDR_CLASS_SHM_MASK, NULL, HFILL } },
{ &hf_erf_ehdr_class_flags_res1,
{ "Reserved", "erf.ehdr.class.flags.res1",
FT_UINT32, BASE_HEX, NULL, EHDR_CLASS_RES1_MASK, NULL, HFILL } },
{ &hf_erf_ehdr_class_flags_user,
{ "User classification", "erf.ehdr.class.flags.user",
FT_UINT32, BASE_DEC, NULL, EHDR_CLASS_USER_MASK, NULL, HFILL } },
{ &hf_erf_ehdr_class_flags_res2,
{ "Reserved", "erf.ehdr.class.flags.res2",
FT_UINT32, BASE_HEX, NULL, EHDR_CLASS_RES2_MASK, NULL, HFILL } },
{ &hf_erf_ehdr_class_flags_drop,
{ "Drop Steering Bit", "erf.ehdr.class.flags.drop",
FT_UINT32, BASE_DEC, NULL, EHDR_CLASS_DROP_MASK, NULL, HFILL } },
{ &hf_erf_ehdr_class_flags_str,
{ "Stream Steering Bits", "erf.ehdr.class.flags.str",
FT_UINT32, BASE_DEC, NULL, EHDR_CLASS_STER_MASK, NULL, HFILL } },
{ &hf_erf_ehdr_class_seqnum,
{ "Sequence number", "erf.ehdr.class.seqnum",
FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_ehdr_bfs_hash,
{ "Hash", "erf.ehdr.bfs.hash",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_bfs_color,
{ "Filter Color", "erf.ehdr.bfs.color",
FT_UINT16, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_bfs_raw_hash,
{ "Raw Hash", "erf.ehdr.bfs.rawhash",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_chan_morebits,
{ "More Bits", "erf.ehdr.chan.morebits",
FT_BOOLEAN, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_chan_morefrag,
{ "More Fragments", "erf.ehdr.chan.morefrag",
FT_BOOLEAN, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_chan_seqnum,
{ "Sequence Number", "erf.ehdr.chan.seqnum",
FT_UINT16, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_chan_res,
{ "Reserved", "erf.ehdr.chan.res",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_chan_virt_container_id,
{ "Virtual Container ID", "erf.ehdr.chan.vcid",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_chan_assoc_virt_container_size,
{ "Associated Virtual Container Size", "erf.ehdr.chan.vcsize",
FT_UINT8, BASE_HEX, VALS(channelised_assoc_virt_container_size), 0, NULL, HFILL } },
{ &hf_erf_ehdr_chan_rate,
{ "Origin Line Type/Rate", "erf.ehdr.chan.rate",
FT_UINT8, BASE_HEX, VALS(channelised_rate), 0, NULL, HFILL } },
{ &hf_erf_ehdr_chan_type,
{ "Frame Part Type", "erf.ehdr.chan.type",
FT_UINT8, BASE_HEX, VALS(channelised_type), 0, NULL, HFILL } },
{ &hf_erf_ehdr_signature_payload_hash,
{ "Payload Hash", "erf.ehdr.signature.payloadhash",
FT_UINT24, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_signature_color,
{ "Filter Color", "erf.ehdr.signature.color",
FT_UINT8, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_signature_flow_hash,
{ "Flow Hash", "erf.ehdr.signature.flowhash",
FT_UINT24, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_flow_id_source_id,
{ "Source ID", "erf.ehdr.flowid.sourceid",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_flow_id_hash_type,
{ "Hash Type", "erf.ehdr.flowid.hashtype",
FT_UINT8, BASE_HEX, VALS(erf_hash_type), 0, NULL, HFILL } },
{ &hf_erf_ehdr_flow_id_stack_type,
{ "Stack Type", "erf.ehdr.flowid.stacktype",
FT_UINT8, BASE_HEX, VALS(erf_stack_type), 0, NULL, HFILL } },
{ &hf_erf_ehdr_flow_id_flow_hash,
{ "Flow Hash", "erf.ehdr.flowid.flowhash",
FT_UINT32, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_host_id_sourceid,
{ "Source ID", "erf.ehdr.hostid.sourceid",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_host_id_hostid,
{ "Host ID", "erf.ehdr.hostid.hostid",
FT_UINT48, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_erf_sourceid,
{ "Source ID", "erf.sourceid",
FT_UINT8, BASE_DEC, NULL, 0, NULL, HFILL } },
{ &hf_erf_hostid,
{ "Host ID", "erf.hostid",
FT_UINT48, BASE_HEX, NULL, 0, NULL, HFILL } },
{ &hf_erf_source_current,
{ "Next Metadata in Source", "erf.source_meta_frame_current",
FT_FRAMENUM, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_erf_source_next,
{ "Next Metadata in Source", "erf.source_meta_frame_next",
FT_FRAMENUM, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_erf_source_prev,
{ "Previous Metadata in Source", "erf.source_meta_frame_prev",
FT_FRAMENUM, BASE_NONE, NULL, 0, NULL, HFILL } },
{ &hf_erf_ehdr_unk,
{ "Data", "erf.ehdr.unknown.data",
FT_UINT64, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_mc_hdlc,
{ "Multi Channel HDLC Header", "erf.mchdlc",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_mc_hdlc_cn,
{ "Connection number", "erf.mchdlc.cn",
FT_UINT32, BASE_DEC, NULL, MC_HDLC_CN_MASK, NULL, HFILL } },
{ &hf_erf_mc_hdlc_res1,
{ "Reserved", "erf.mchdlc.res1",
FT_UINT32, BASE_HEX, NULL, MC_HDLC_RES1_MASK, NULL, HFILL } },
{ &hf_erf_mc_hdlc_res2,
{ "Reserved", "erf.mchdlc.res2",
FT_UINT32, BASE_HEX, NULL, MC_HDLC_RES2_MASK, NULL, HFILL } },
{ &hf_erf_mc_hdlc_fcse,
{ "FCS error", "erf.mchdlc.fcse",
FT_UINT32, BASE_DEC, NULL, MC_HDLC_FCSE_MASK, NULL, HFILL } },
{ &hf_erf_mc_hdlc_sre,
{ "Short record error", "erf.mchdlc.sre",
FT_UINT32, BASE_DEC, NULL, MC_HDLC_SRE_MASK, NULL, HFILL } },
{ &hf_erf_mc_hdlc_lre,
{ "Long record error", "erf.mchdlc.lre",
FT_UINT32, BASE_DEC, NULL, MC_HDLC_LRE_MASK, NULL, HFILL } },
{ &hf_erf_mc_hdlc_afe,
{ "Aborted frame error", "erf.mchdlc.afe",
FT_UINT32, BASE_DEC, NULL, MC_HDLC_AFE_MASK, NULL, HFILL } },
{ &hf_erf_mc_hdlc_oe,
{ "Octet error", "erf.mchdlc.oe",
FT_UINT32, BASE_DEC, NULL, MC_HDLC_OE_MASK, NULL, HFILL } },
{ &hf_erf_mc_hdlc_lbe,
{ "Lost byte error", "erf.mchdlc.lbe",
FT_UINT32, BASE_DEC, NULL, MC_HDLC_LBE_MASK, NULL, HFILL } },
{ &hf_erf_mc_hdlc_first,
{ "First record", "erf.mchdlc.first",
FT_UINT32, BASE_DEC, NULL, MC_HDLC_FIRST_MASK, NULL, HFILL } },
{ &hf_erf_mc_hdlc_res3,
{ "Reserved", "erf.mchdlc.res3",
FT_UINT32, BASE_HEX, NULL, MC_HDLC_RES3_MASK, NULL, HFILL } },
{ &hf_erf_mc_raw,
{ "Multi Channel RAW Header", "erf.mcraw",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_mc_raw_int,
{ "Physical interface", "erf.mcraw.int",
FT_UINT32, BASE_DEC, NULL, MC_RAW_INT_MASK, NULL, HFILL } },
{ &hf_erf_mc_raw_res1,
{ "Reserved", "erf.mcraw.res1",
FT_UINT32, BASE_HEX, NULL, MC_RAW_RES1_MASK, NULL, HFILL } },
{ &hf_erf_mc_raw_sre,
{ "Short record error", "erf.mcraw.sre",
FT_UINT32, BASE_DEC, NULL, MC_RAW_SRE_MASK, NULL, HFILL } },
{ &hf_erf_mc_raw_lre,
{ "Long record error", "erf.mcraw.lre",
FT_UINT32, BASE_DEC, NULL, MC_RAW_LRE_MASK, NULL, HFILL } },
{ &hf_erf_mc_raw_res2,
{ "Reserved", "erf.mcraw.res2",
FT_UINT32, BASE_HEX, NULL, MC_RAW_RES2_MASK, NULL, HFILL } },
{ &hf_erf_mc_raw_lbe,
{ "Lost byte error", "erf.mcraw.lbe",
FT_UINT32, BASE_DEC, NULL, MC_RAW_LBE_MASK, NULL, HFILL } },
{ &hf_erf_mc_raw_first,
{ "First record", "erf.mcraw.first",
FT_UINT32, BASE_DEC, NULL, MC_RAW_FIRST_MASK, NULL, HFILL } },
{ &hf_erf_mc_raw_res3,
{ "Reserved", "erf.mcraw.res3",
FT_UINT32, BASE_HEX, NULL, MC_RAW_RES3_MASK, NULL, HFILL } },
{ &hf_erf_mc_atm,
{ "Multi Channel ATM Header", "erf.mcatm",
FT_UINT32, BASE_HEX, NULL, 0x00, NULL, HFILL } },
{ &hf_erf_mc_atm_cn,
{ "Connection number", "erf.mcatm.cn",
FT_UINT32, BASE_DEC, NULL, MC_ATM_CN_MASK, NULL, HFILL } },
{ &hf_erf_mc_atm_res1,
{ "Reserved", "erf.mcatm.res1",
FT_UINT32, BASE_HEX, NULL, MC_ATM_RES1_MASK, NULL, HFILL } },
{ &hf_erf_mc_atm_mul,
{ "Multiplexed", "erf.mcatm.mul",
FT_UINT32, BASE_DEC, NULL, MC_ATM_MUL_MASK, NULL, HFILL } },
{ &hf_erf_mc_atm_port,
{ "Physical port", "erf.mcatm.port",
FT_UINT32, BASE_DEC, NULL, MC_ATM_PORT_MASK, NULL, HFILL } },
{ &hf_erf_mc_atm_res2,
{ "Reserved", "erf.mcatm.res2",
FT_UINT32, BASE_HEX, NULL, MC_ATM_RES2_MASK, NULL, HFILL } },
{ &hf_erf_mc_atm_lbe,
{ "Lost Byte Error", "erf.mcatm.lbe",
FT_UINT32, BASE_DEC, NULL, MC_ATM_LBE_MASK, NULL, HFILL } },
{ &hf_erf_mc_atm_hec,
{ "HEC corrected", "erf.mcatm.hec",
FT_UINT32, BASE_DEC, NULL, MC_ATM_HEC_MASK, NULL, HFILL } },
{ &hf_erf_mc_atm_crc10,
{ "OAM Cell CRC10 Error (not implemented)", "erf.mcatm.crc10",
FT_UINT32, BASE_DEC, NULL, MC_ATM_CRC10_MASK, NULL, HFILL } },
{ &hf_erf_mc_atm_oamcell,
{ "OAM Cell", "erf.mcatm.oamcell",
FT_UINT32, BASE_DEC, NULL, MC_ATM_OAMCELL_MASK, NULL, HFILL } },
{ &hf_erf_mc_atm_first,
{ "First record", "erf.mcatm.first",
FT_UINT32, BASE_DEC, NULL, MC_ATM_FIRST_MASK, NULL, HFILL } },
{ &hf_erf_mc_atm_res3,
{ "Reserved", "erf.mcatm.res3",
FT_UINT32, BASE_HEX, NULL, MC_ATM_RES3_MASK, NULL, HFILL } },
{ &hf_erf_mc_rawl,
{ "Multi Channel RAW Link Header", "erf.mcrawl",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_mc_rawl_cn,
{ "Connection number", "erf.mcrawl.cn",
FT_UINT32, BASE_DEC, NULL, MC_RAWL_CN_MASK, NULL, HFILL } },
{ &hf_erf_mc_rawl_res1,
{ "Reserved", "erf.mcrawl.res1",
FT_UINT32, BASE_HEX, NULL, MC_RAWL_RES2_MASK, NULL, HFILL } },
{ &hf_erf_mc_rawl_lbe,
{ "Lost byte error", "erf.mcrawl.lbe",
FT_UINT32, BASE_DEC, NULL, MC_RAWL_LBE_MASK, NULL, HFILL } },
{ &hf_erf_mc_rawl_first,
{ "First record", "erf.mcrawl.first",
FT_UINT32, BASE_DEC, NULL, MC_RAWL_FIRST_MASK, NULL, HFILL } },
{ &hf_erf_mc_rawl_res2,
{ "Reserved", "erf.mcrawl.res2",
FT_UINT32, BASE_HEX, NULL, MC_RAWL_RES2_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal5,
{ "Multi Channel AAL5 Header", "erf.mcaal5",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_mc_aal5_cn,
{ "Connection number", "erf.mcaal5.cn",
FT_UINT32, BASE_DEC, NULL, MC_AAL5_CN_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal5_res1,
{ "Reserved", "erf.mcaal5.res1",
FT_UINT32, BASE_HEX, NULL, MC_AAL5_RES1_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal5_port,
{ "Physical port", "erf.mcaal5.port",
FT_UINT32, BASE_DEC, NULL, MC_AAL5_PORT_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal5_crcck,
{ "CRC checked", "erf.mcaal5.crcck",
FT_UINT32, BASE_DEC, NULL, MC_AAL5_CRCCK_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal5_crce,
{ "CRC error", "erf.mcaal5.crce",
FT_UINT32, BASE_DEC, NULL, MC_AAL5_CRCE_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal5_lenck,
{ "Length checked", "erf.mcaal5.lenck",
FT_UINT32, BASE_DEC, NULL, MC_AAL5_LENCK_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal5_lene,
{ "Length error", "erf.mcaal5.lene",
FT_UINT32, BASE_DEC, NULL, MC_AAL5_LENE_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal5_res2,
{ "Reserved", "erf.mcaal5.res2",
FT_UINT32, BASE_HEX, NULL, MC_AAL5_RES2_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal5_first,
{ "First record", "erf.mcaal5.first",
FT_UINT32, BASE_DEC, NULL, MC_AAL5_FIRST_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal5_res3,
{ "Reserved", "erf.mcaal5.res3",
FT_UINT32, BASE_HEX, NULL, MC_AAL5_RES3_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal2,
{ "Multi Channel AAL2 Header", "erf.mcaal2",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_mc_aal2_cn,
{ "Connection number", "erf.mcaal2.cn",
FT_UINT32, BASE_DEC, NULL, MC_AAL2_CN_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal2_res1,
{ "Reserved for extra connection", "erf.mcaal2.res1",
FT_UINT32, BASE_HEX, NULL, MC_AAL2_RES1_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal2_res2,
{ "Reserved for type", "erf.mcaal2.mul",
FT_UINT32, BASE_HEX, NULL, MC_AAL2_RES2_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal2_port,
{ "Physical port", "erf.mcaal2.port",
FT_UINT32, BASE_DEC, NULL, MC_AAL2_PORT_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal2_res3,
{ "Reserved", "erf.mcaal2.res2",
FT_UINT32, BASE_HEX, NULL, MC_AAL2_RES3_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal2_first,
{ "First cell received", "erf.mcaal2.lbe",
FT_UINT32, BASE_DEC, NULL, MC_AAL2_FIRST_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal2_maale,
{ "MAAL error", "erf.mcaal2.hec",
FT_UINT32, BASE_DEC, NULL, MC_AAL2_MAALE_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal2_lene,
{ "Length error", "erf.mcaal2.crc10",
FT_UINT32, BASE_DEC, NULL, MC_AAL2_LENE_MASK, NULL, HFILL } },
{ &hf_erf_mc_aal2_cid,
{ "Channel Identification Number", "erf.mcaal2.cid",
FT_UINT32, BASE_DEC, NULL, MC_AAL2_CID_MASK, NULL, HFILL } },
{ &hf_erf_aal2,
{ "AAL2 Header", "erf.aal2",
FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_aal2_cid,
{ "Channel Identification Number", "erf.aal2.cid",
FT_UINT32, BASE_DEC, NULL, AAL2_CID_MASK, NULL, HFILL } },
{ &hf_erf_aal2_maale,
{ "MAAL error number", "erf.aal2.maale",
FT_UINT32, BASE_DEC, NULL, AAL2_MAALE_MASK, NULL, HFILL } },
{ &hf_erf_aal2_maalei,
{ "MAAL error", "erf.aal2.hec",
FT_UINT32, BASE_DEC, NULL, AAL2_MAALEI_MASK, NULL, HFILL } },
{ &hf_erf_aal2_first,
{ "First cell received", "erf.aal2.lbe",
FT_UINT32, BASE_DEC, NULL, AAL2_FIRST_MASK, NULL, HFILL } },
{ &hf_erf_aal2_res1,
{ "Reserved", "erf.aal2.res1",
FT_UINT32, BASE_HEX, NULL, AAL2_RES1_MASK, NULL, HFILL } },
{ &hf_erf_eth,
{ "Ethernet pad", "erf.eth",
FT_NONE, BASE_NONE, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_eth_off,
{ "Offset", "erf.eth.off",
FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_eth_pad,
{ "Padding", "erf.eth.pad",
FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_meta_tag_type,
{ "Tag Type", "erf.meta.tag.type",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_meta_tag_len,
{ "Tag Length", "erf.meta.tag.len",
FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL } },
{ &hf_erf_meta_tag_unknown,
{ "Unknown Tag", "erf.meta.unknown",
FT_BYTES, BASE_NONE, NULL, 0x0, NULL, HFILL } }
};
static gint *ett[] = {
&ett_erf,
&ett_erf_pseudo_hdr,
&ett_erf_rectype,
&ett_erf_flags,
&ett_erf_mc_hdlc,
&ett_erf_mc_raw,
&ett_erf_mc_atm,
&ett_erf_mc_rawlink,
&ett_erf_mc_aal5,
&ett_erf_mc_aal2,
&ett_erf_aal2,
&ett_erf_eth,
&ett_erf_meta,
&ett_erf_meta_tag,
&ett_erf_source
};
static const enum_val_t erf_hdlc_options[] = {
{ "chdlc", "Cisco HDLC", ERF_HDLC_CHDLC },
{ "ppp", "PPP serial", ERF_HDLC_PPP },
{ "frelay", "Frame Relay", ERF_HDLC_FRELAY },
{ "mtp2", "SS7 MTP2", ERF_HDLC_MTP2 },
{ "guess", "Attempt to guess", ERF_HDLC_GUESS },
{ NULL, NULL, 0 }
};
static const enum_val_t erf_aal5_options[] = {
{ "guess", "Attempt to guess", ERF_AAL5_GUESS },
{ "llc", "LLC multiplexed", ERF_AAL5_LLC },
{ "unspec", "Unspecified", ERF_AAL5_UNSPEC },
{ NULL, NULL, 0 }
};
static ei_register_info ei[] = {
{ &ei_erf_checksum_error, { "erf.checksum.error", PI_CHECKSUM, PI_ERROR, "ERF MC FCS Error", EXPFILL }},
{ &ei_erf_packet_loss, { "erf.packet_loss", PI_SEQUENCE, PI_WARN, "Packet loss occurred between previous and current packet", EXPFILL }},
{ &ei_erf_extension_headers_not_shown, { "erf.ehdr.more_not_shown", PI_SEQUENCE, PI_WARN, "More extension headers were present, not shown", EXPFILL }},
{ &ei_erf_meta_section_len_error, { "erf.meta.section_len.error", PI_PROTOCOL, PI_ERROR, "MetaERF Section Length incorrect", EXPFILL }},
{ &ei_erf_meta_truncated_record, { "erf.meta.truncated_record", PI_MALFORMED, PI_ERROR, "MetaERF truncated record", EXPFILL }},
{ &ei_erf_meta_truncated_tag, { "erf.meta.truncated_tag", PI_PROTOCOL, PI_ERROR, "MetaERF truncated tag", EXPFILL }},
{ &ei_erf_meta_zero_len_tag, { "erf.meta.zero_len_tag", PI_PROTOCOL, PI_NOTE, "MetaERF zero length tag", EXPFILL }},
{ &ei_erf_meta_reset, { "erf.meta.metadata_reset", PI_PROTOCOL, PI_WARN, "MetaERF metadata reset", EXPFILL }}
};
module_t *erf_module;
expert_module_t* expert_erf;
proto_erf = proto_register_protocol("Extensible Record Format", "ERF", "erf");
erf_handle = register_dissector("erf", dissect_erf, proto_erf);
init_meta_tags();
proto_register_field_array(proto_erf, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_erf = expert_register_protocol(proto_erf);
expert_register_field_array(expert_erf, ei, array_length(ei));
proto_register_field_array(proto_erf, (hf_register_info*) wmem_array_get_raw(erf_meta_index.hfri), (int) wmem_array_get_count(erf_meta_index.hfri));
proto_register_subtree_array((gint**) wmem_array_get_raw(erf_meta_index.ett), (int) wmem_array_get_count(erf_meta_index.ett));
erf_module = prefs_register_protocol(proto_erf, NULL);
prefs_register_enum_preference(erf_module, "hdlc_type", "ERF_HDLC Layer 2",
"Protocol encapsulated in HDLC records",
&erf_hdlc_type, erf_hdlc_options, FALSE);
prefs_register_bool_preference(erf_module, "rawcell_first",
"Raw ATM cells are first cell of AAL5 PDU",
"Whether raw ATM cells should be treated as "
"the first cell of an AAL5 PDU",
&erf_rawcell_first);
prefs_register_enum_preference(erf_module, "aal5_type",
"ATM AAL5 packet type",
"Protocol encapsulated in ATM AAL5 packets",
&erf_aal5_type, erf_aal5_options, FALSE);
prefs_register_obsolete_preference(erf_module, "ethfcs");
erf_dissector_table = register_dissector_table("erf.types.type", "Type", proto_erf, FT_UINT8, BASE_DEC);
register_init_routine(erf_init_dissection);
}
void
proto_reg_handoff_erf(void)
{
dissector_add_uint("wtap_encap", WTAP_ENCAP_ERF, erf_handle);
dissector_add_uint("wtap_fts_rec", WTAP_FILE_TYPE_SUBTYPE_ERF, erf_handle);
chdlc_handle = find_dissector_add_dependency("chdlc", proto_erf);
ppp_handle = find_dissector_add_dependency("ppp_hdlc", proto_erf);
frelay_handle = find_dissector_add_dependency("fr", proto_erf);
mtp2_handle = find_dissector_add_dependency("mtp2_with_crc", proto_erf);
atm_untruncated_handle = find_dissector_add_dependency("atm_untruncated", proto_erf);
sdh_handle = find_dissector_add_dependency("sdh", proto_erf);
}
