static guint32 get_uint_parameter(guint8 *parameter_stream, gint parameter_length)
{
guint32 value;
guint8 *val;
val = (guint8 *) wmem_alloc(wmem_packet_scope(), parameter_length + 1);
memcpy(val, parameter_stream, parameter_length);
val[parameter_length] = '\0';
value = (guint32) g_ascii_strtoull(val, NULL, 10);
return value;
}
static gboolean check_biev(gint role, guint16 type) {
if (role == ROLE_HS && type == TYPE_ACTION) return TRUE;
return FALSE;
}
static gboolean check_bind(gint role, guint16 type) {
if (role == ROLE_HS && (type == TYPE_ACTION || type == TYPE_READ || type == TYPE_TEST)) return TRUE;
if (role == ROLE_AG && type == TYPE_RESPONSE) return TRUE;
return FALSE;
}
static gboolean check_bac(gint role, guint16 type) {
if (role == ROLE_HS && type == TYPE_ACTION) return TRUE;
return FALSE;
}
static gboolean check_bcs(gint role, guint16 type) {
if (role == ROLE_HS && type == TYPE_ACTION) return TRUE;
if (role == ROLE_AG && type == TYPE_RESPONSE) return TRUE;
return FALSE;
}
static gboolean check_bcc(gint role, guint16 type) {
if (role == ROLE_HS && type == TYPE_ACTION_SIMPLY) return TRUE;
return FALSE;
}
static gboolean check_bia(gint role, guint16 type) {
if (role == ROLE_HS && type == TYPE_ACTION) return TRUE;
return FALSE;
}
static gboolean check_binp(gint role, guint16 type) {
if (role == ROLE_HS && type == TYPE_ACTION) return TRUE;
if (role == ROLE_AG && type == TYPE_RESPONSE) return TRUE;
return FALSE;
}
static gboolean check_bldn(gint role, guint16 type) {
if (role == ROLE_HS && type == TYPE_ACTION_SIMPLY) return TRUE;
return FALSE;
}
static gboolean check_bvra(gint role, guint16 type) {
if (role == ROLE_HS && type == TYPE_ACTION) return TRUE;
if (role == ROLE_AG && type == TYPE_RESPONSE) return TRUE;
return FALSE;
}
static gboolean check_brsf(gint role, guint16 type) {
if (role == ROLE_HS && type == TYPE_ACTION) return TRUE;
if (role == ROLE_AG && type == TYPE_RESPONSE) return TRUE;
return FALSE;
}
static gboolean check_nrec(gint role, guint16 type) {
if (role == ROLE_HS && type == TYPE_ACTION) return TRUE;
return FALSE;
}
static gboolean check_vgs(gint role, guint16 type) {
if (role == ROLE_HS && type == TYPE_ACTION) return TRUE;
if (role == ROLE_AG && type == TYPE_RESPONSE) return TRUE;
return FALSE;
}
static gboolean check_vgm(gint role, guint16 type) {
if (role == ROLE_HS && type == TYPE_ACTION) return TRUE;
if (role == ROLE_AG && type == TYPE_RESPONSE) return TRUE;
return FALSE;
}
static gboolean check_bsir(gint role, guint16 type) {
if (role == ROLE_AG && type == TYPE_RESPONSE) return TRUE;
return FALSE;
}
static gboolean check_btrh(gint role, guint16 type) {
if (role == ROLE_HS && (type == TYPE_READ || type == TYPE_ACTION)) return TRUE;
if (role == ROLE_AG && type == TYPE_RESPONSE) return TRUE;
return FALSE;
}
static gboolean check_only_ag_role(gint role, guint16 type) {
if (role == ROLE_AG && type == TYPE_RESPONSE_ACK) return TRUE;
return FALSE;
}
static gboolean check_only_hs_role(gint role, guint16 type) {
if (role == ROLE_HS && type == TYPE_ACTION_SIMPLY) return TRUE;
return FALSE;
}
static gboolean check_ccwa(gint role, guint16 type) {
if (role == ROLE_HS && (type == TYPE_ACTION || type == TYPE_READ || type == TYPE_TEST)) return TRUE;
if (role == ROLE_AG && type == TYPE_RESPONSE) return TRUE;
return FALSE;
}
static gboolean check_chld(gint role, guint16 type) {
if (role == ROLE_HS && (type == TYPE_ACTION || type == TYPE_TEST)) return TRUE;
if (role == ROLE_AG && type == TYPE_RESPONSE) return TRUE;
return FALSE;
}
static gboolean check_chup(gint role, guint16 type) {
if (role == ROLE_HS && (type == TYPE_ACTION_SIMPLY || type == TYPE_TEST)) return TRUE;
return FALSE;
}
static gboolean check_clcc(gint role, guint16 type) {
if (role == ROLE_HS && (type == TYPE_ACTION_SIMPLY || type == TYPE_TEST)) return TRUE;
if (role == ROLE_AG && type == TYPE_RESPONSE) return TRUE;
return FALSE;
}
static gboolean check_cind(gint role, guint16 type) {
if (role == ROLE_HS && (type == TYPE_READ || type == TYPE_TEST)) return TRUE;
if (role == ROLE_AG && type == TYPE_RESPONSE) return TRUE;
return FALSE;
}
static gboolean check_cmer(gint role, guint16 type) {
if (role == ROLE_HS && (type == TYPE_ACTION || type == TYPE_READ || type == TYPE_TEST)) return TRUE;
if (role == ROLE_AG && type == TYPE_RESPONSE) return TRUE;
return FALSE;
}
static gboolean check_cops(gint role, guint16 type) {
if (role == ROLE_HS && (type == TYPE_ACTION || type == TYPE_READ)) return TRUE;
if (role == ROLE_AG && type == TYPE_RESPONSE) return TRUE;
return FALSE;
}
static gboolean check_cmee(gint role, guint16 type) {
if (role == ROLE_HS && type == TYPE_ACTION) return TRUE;
return FALSE;
}
static gboolean check_cme(gint role, guint16 type) {
if (role == ROLE_AG && type == TYPE_RESPONSE) return TRUE;
return FALSE;
}
static gboolean check_clip(gint role, guint16 type) {
if (role == ROLE_HS && (type == TYPE_ACTION || type == TYPE_READ || type == TYPE_TEST)) return TRUE;
if (role == ROLE_AG && type == TYPE_RESPONSE) return TRUE;
return FALSE;
}
static gboolean check_ciev(gint role, guint16 type) {
if (role == ROLE_AG && type == TYPE_RESPONSE) return TRUE;
return FALSE;
}
static gboolean check_vts(gint role, guint16 type) {
if (role == ROLE_HS && (type == TYPE_ACTION || type == TYPE_TEST)) return TRUE;
if (role == ROLE_AG && type == TYPE_RESPONSE) return TRUE;
return FALSE;
}
static gboolean check_cnum(gint role, guint16 type) {
if (role == ROLE_HS && type == TYPE_ACTION_SIMPLY) return TRUE;
if (role == ROLE_AG && type == TYPE_RESPONSE) return TRUE;
return FALSE;
}
static gboolean
dissect_brsf_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number, gint parameter_length, void **data _U_)
{
proto_item *pitem;
guint32 value;
if (!((role == ROLE_HS && type == TYPE_ACTION) ||
(role == ROLE_AG && type == TYPE_RESPONSE))) {
return FALSE;
}
if (parameter_number > 0) return FALSE;
value = get_uint_parameter(parameter_stream, parameter_length);
if (role == ROLE_HS) {
static const int * hs[] = {
&hf_brsf_hs_ec_nr_function,
&hf_brsf_hs_call_waiting_or_tree_way,
&hf_brsf_hs_cli_presentation,
&hf_brsf_hs_voice_recognition_activation,
&hf_brsf_hs_remote_volume_control,
&hf_brsf_hs_enhanced_call_status,
&hf_brsf_hs_enhanced_call_control,
&hf_brsf_hs_codec_negotiation,
&hf_brsf_hs_hf_indicators,
&hf_brsf_hs_esco_s4_t2_settings_support,
&hf_brsf_hs_reserved,
NULL
};
pitem = proto_tree_add_bitmask_value_with_flags(tree, tvb, offset, hf_brsf_hs, ett_bthfp_brsf_hf, hs, value, BMT_NO_APPEND);
if (value >> 8) {
expert_add_info(pinfo, pitem, &ei_brfs_hs_reserved_bits);
}
} else {
static const int * ag[] = {
&hf_brsf_ag_three_way_calling,
&hf_brsf_ag_ec_nr_function,
&hf_brsf_ag_voice_recognition_function,
&hf_brsf_ag_inband_ring_tone,
&hf_brsf_ag_attach_number_to_voice_tag,
&hf_brsf_ag_ability_to_reject_a_call,
&hf_brsf_ag_enhanced_call_status,
&hf_brsf_ag_enhanced_call_control,
&hf_brsf_ag_extended_error_result_codes,
&hf_brsf_ag_codec_negotiation,
&hf_brsf_ag_hf_indicators,
&hf_brsf_ag_esco_s4_t2_settings_support,
&hf_brsf_ag_reserved,
NULL
};
pitem = proto_tree_add_bitmask_value_with_flags(tree, tvb, offset, hf_brsf_ag, ett_bthfp_brsf_ag, ag, value, BMT_NO_APPEND);
if (value >> 10) {
expert_add_info(pinfo, pitem, &ei_brfs_ag_reserved_bits);
}
}
return TRUE;
}
static gint
dissect_vgs_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number, gint parameter_length, void **data _U_)
{
proto_item *pitem;
guint32 value;
if (!((role == ROLE_HS && type == TYPE_ACTION) ||
(role == ROLE_AG && type == TYPE_RESPONSE))) {
return FALSE;
}
if (parameter_number > 0) return FALSE;
value = get_uint_parameter(parameter_stream, parameter_length);
pitem = proto_tree_add_uint(tree, hf_vgs, tvb, offset, parameter_length, value);
proto_item_append_text(pitem, "/15");
if (value > 15) {
expert_add_info(pinfo, pitem, &ei_vgs_gain);
}
return TRUE;
}
static gint
dissect_vgm_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number, gint parameter_length, void **data _U_)
{
proto_item *pitem;
guint32 value;
if (!((role == ROLE_HS && type == TYPE_ACTION) ||
(role == ROLE_AG && type == TYPE_RESPONSE))) {
return FALSE;
}
if (parameter_number > 0) return FALSE;
value = get_uint_parameter(parameter_stream, parameter_length);
pitem = proto_tree_add_uint(tree, hf_vgm, tvb, offset, parameter_length, value);
proto_item_append_text(pitem, "/15");
if (value > 15) {
expert_add_info(pinfo, pitem, &ei_vgm_gain);
}
return TRUE;
}
static gint
dissect_nrec_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number, gint parameter_length, void **data _U_)
{
proto_item *pitem;
guint32 value;
if (!((role == ROLE_HS && type == TYPE_ACTION) ||
(role == ROLE_AG && type == TYPE_RESPONSE))) {
return FALSE;
}
if (parameter_number > 0) return FALSE;
value = get_uint_parameter(parameter_stream, parameter_length);
pitem = proto_tree_add_uint(tree, hf_nrec, tvb, offset, parameter_length, value);
if (value != 0) {
expert_add_info(pinfo, pitem, &ei_nrec);
}
return TRUE;
}
static gint
dissect_bvra_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number, gint parameter_length, void **data _U_)
{
proto_item *pitem;
guint32 value;
if (!((role == ROLE_HS && type == TYPE_ACTION) ||
(role == ROLE_AG && type == TYPE_RESPONSE))) {
return FALSE;
}
if (parameter_number > 0) return FALSE;
value = get_uint_parameter(parameter_stream, parameter_length);
pitem = proto_tree_add_uint(tree, hf_bvra_vrect, tvb, offset, parameter_length, value);
if (value > 1) {
expert_add_info(pinfo, pitem, &ei_bvra);
}
return TRUE;
}
static gint
dissect_bcs_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number, gint parameter_length, void **data _U_)
{
proto_item *pitem;
guint32 value;
if (!check_bcs(role, type)) {
return FALSE;
}
if (parameter_number > 0) return FALSE;
value = get_uint_parameter(parameter_stream, parameter_length);
pitem = proto_tree_add_uint(tree, hf_bcs_codec, tvb, offset, parameter_length, value);
if (value < 1 || value > 2) {
expert_add_info(pinfo, pitem, &ei_bcs);
}
return TRUE;
}
static gint
dissect_bac_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number _U_, gint parameter_length, void **data _U_)
{
proto_item *pitem;
guint32 value;
if (!check_bac(role, type)) {
return FALSE;
}
value = get_uint_parameter(parameter_stream, parameter_length);
pitem = proto_tree_add_uint(tree, hf_bac_codec, tvb, offset, parameter_length, value);
if (value < 1 || value > 2) {
expert_add_info(pinfo, pitem, &ei_bac);
}
return TRUE;
}
static gint
dissect_bind_parameter(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number, gint parameter_length, void **data _U_)
{
guint32 value;
if (!check_bind(role, type)) return FALSE;
if (parameter_number < 20) {
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_bind_parameter, tvb, offset,
parameter_length, value);
return TRUE;
}
return FALSE;
}
static gint
dissect_biev_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number, gint parameter_length, void **data _U_)
{
proto_item *pitem;
guint32 value;
if (!check_biev(role, type)) return FALSE;
if (parameter_number == 0) {
value = get_uint_parameter(parameter_stream, parameter_length);
pitem = proto_tree_add_uint(tree, hf_biev_assigned_number, tvb, offset,
parameter_length, value);
if (value > 65535) {
expert_add_info(pinfo, pitem, &ei_biev_assigned_number);
} else if (value > 1) {
expert_add_info(pinfo, pitem, &ei_biev_assigned_number_no);
}
} else if (parameter_number == 1) {
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_biev_value, tvb, offset,
parameter_length, value);
} else return FALSE;
return TRUE;
}
static gint
dissect_no_parameter(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_,
gint offset _U_, gint role _U_, guint16 type _U_, guint8 *parameter_stream _U_,
guint parameter_number _U_, gint parameter_length _U_, void **data _U_)
{
return FALSE;
}
static gint
dissect_bsir_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number, gint parameter_length, void **data _U_)
{
proto_item *pitem;
guint32 value;
if (!(role == ROLE_AG && type == TYPE_RESPONSE)) {
return FALSE;
}
if (parameter_number > 0) return FALSE;
value = get_uint_parameter(parameter_stream, parameter_length);
pitem = proto_tree_add_uint(tree, hf_bsir, tvb, offset, parameter_length, value);
if (value > 1) {
expert_add_info(pinfo, pitem, &ei_bsir);
}
return TRUE;
}
static gint
dissect_btrh_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number, gint parameter_length, void **data _U_)
{
proto_item *pitem;
guint32 value;
if (!((role == ROLE_HS && type == TYPE_ACTION) ||
(role == ROLE_AG && type == TYPE_RESPONSE))) {
return FALSE;
}
if (parameter_number > 0) return FALSE;
value = get_uint_parameter(parameter_stream, parameter_length);
pitem = proto_tree_add_uint(tree, hf_btrh, tvb, offset, parameter_length, value);
if (value != 0) {
expert_add_info(pinfo, pitem, &ei_btrh);
}
return TRUE;
}
static gint
dissect_binp_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number, gint parameter_length, void **data _U_)
{
proto_item *pitem;
guint32 value;
if (!((role == ROLE_HS && type == TYPE_ACTION) ||
(role == ROLE_AG && type == TYPE_RESPONSE))) {
return FALSE;
}
if (role == ROLE_HS && type == TYPE_ACTION) {
if (parameter_number == 0) {
value = get_uint_parameter(parameter_stream, parameter_length);
pitem = proto_tree_add_uint(tree, hf_binp_request, tvb, offset,
parameter_length, value);
if (value != 1) {
expert_add_info(pinfo, pitem, &ei_binp);
}
} else return FALSE;
} else {
proto_tree_add_item(tree, hf_binp_response, tvb, offset,
parameter_length, ENC_NA | ENC_ASCII);
}
return TRUE;
}
static gint
dissect_bia_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number, gint parameter_length, void **data _U_)
{
proto_item *pitem;
guint32 value;
if (!((role == ROLE_HS && type == TYPE_ACTION))) return FALSE;
if (parameter_number > 19) return FALSE;
value = get_uint_parameter(parameter_stream, parameter_length);
pitem = proto_tree_add_uint(tree, hf_bia_indicator[parameter_number], tvb,
offset, parameter_length, value);
if (value > 1) {
expert_add_info(pinfo, pitem, &ei_bia);
}
return TRUE;
}
static gint
dissect_cind_parameter(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream _U_,
guint parameter_number, gint parameter_length, void **data _U_)
{
if (!check_cind(role, type)) return FALSE;
if (parameter_number > 19) return FALSE;
proto_tree_add_item(tree, hf_indicator[parameter_number], tvb, offset,
parameter_length, ENC_NA | ENC_ASCII);
return TRUE;
}
static gint
dissect_chld_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number, gint parameter_length, void **data _U_)
{
guint32 value;
if (!check_chld(role, type)) return FALSE;
if (role == ROLE_HS && type == TYPE_ACTION && parameter_number == 0) {
value = get_uint_parameter(parameter_stream, 1);
if (parameter_length >= 2) {
if (tvb_get_guint8(tvb, offset + 1) == 'x') {
if (value == 1)
proto_tree_add_item(tree, hf_chld_mode_1x, tvb, offset, parameter_length, ENC_NA | ENC_ASCII);
else if (value == 2)
proto_tree_add_item(tree, hf_chld_mode_2x, tvb, offset, parameter_length, ENC_NA | ENC_ASCII);
}
if (tvb_get_guint8(tvb, offset + 1) != 'x' || value > 4) {
proto_tree_add_expert(tree, pinfo, &ei_chld_mode, tvb, offset, parameter_length);
}
}
proto_tree_add_uint(tree, hf_chld_mode, tvb, offset, parameter_length, value);
return TRUE;
}
proto_tree_add_item(tree, hf_chld_supported_modes, tvb, offset,
parameter_length, ENC_NA | ENC_ASCII);
return TRUE;
}
static gint
dissect_ccwa_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number, gint parameter_length, void **data _U_)
{
proto_item *pitem;
guint32 value;
if (!check_ccwa(role, type)) return FALSE;
if (role == ROLE_HS && parameter_number > 2) return FALSE;
if (role == ROLE_AG && parameter_number > 7) return FALSE;
if (role == ROLE_HS) switch (parameter_number) {
case 0:
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_ccwa_show_result_code, tvb, offset, parameter_length, value);
break;
case 1:
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_ccwa_mode, tvb, offset, parameter_length, value);
break;
case 2:
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_ccwa_class, tvb, offset, parameter_length, value);
break;
}
if (role == ROLE_AG) switch (parameter_number) {
case 0:
proto_tree_add_item(tree, hf_at_number, tvb, offset, parameter_length, ENC_NA | ENC_ASCII);
break;
case 1:
value = get_uint_parameter(parameter_stream, parameter_length);
pitem = proto_tree_add_uint(tree, hf_at_type, tvb, offset, parameter_length, value);
if (value < 128 || value > 175)
expert_add_info(pinfo, pitem, &ei_at_type);
break;
case 2:
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_ccwa_class, tvb, offset, parameter_length, value);
break;
case 3:
proto_tree_add_item(tree, hf_at_alpha, tvb, offset, parameter_length, ENC_NA | ENC_ASCII);
break;
case 4:
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_at_cli_validity, tvb, offset, parameter_length, value);
break;
case 5:
proto_tree_add_item(tree, hf_at_subaddress, tvb, offset, parameter_length, ENC_NA | ENC_ASCII);
break;
case 6:
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_at_subaddress_type, tvb, offset, parameter_length, value);
break;
case 7:
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_at_priority, tvb, offset, parameter_length, value);
break;
}
return TRUE;
}
static gint
dissect_cmer_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number, gint parameter_length, void **data _U_)
{
proto_item *pitem;
guint32 value;
if (!((role == ROLE_HS && type == TYPE_ACTION))) {
return FALSE;
}
if (parameter_number > 4) return FALSE;
value = get_uint_parameter(parameter_stream, parameter_length);
switch (parameter_number) {
case 0:
pitem = proto_tree_add_uint(tree, hf_cmer_mode, tvb, offset, parameter_length, value);
if (value != 3)
expert_add_info(pinfo, pitem, &ei_cmer_mode);
break;
case 1:
pitem = proto_tree_add_uint(tree, hf_cmer_keyp, tvb, offset, parameter_length, value);
if (value != 0)
expert_add_info(pinfo, pitem, &ei_cmer_keyp);
break;
case 2:
pitem = proto_tree_add_uint(tree, hf_cmer_disp, tvb, offset, parameter_length, value);
if (value != 0)
expert_add_info(pinfo, pitem, &ei_cmer_disp);
break;
case 3:
pitem = proto_tree_add_uint(tree, hf_cmer_ind, tvb, offset, parameter_length, value);
if (value > 1)
expert_add_info(pinfo, pitem, &ei_cmer_ind);
break;
case 4:
pitem = proto_tree_add_uint(tree, hf_cmer_bfr, tvb, offset, parameter_length, value);
if (value != 0)
expert_add_info(pinfo, pitem, &ei_cmer_btr);
break;
}
return TRUE;
}
static gint
dissect_clip_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number, gint parameter_length, void **data _U_)
{
proto_item *pitem;
guint32 value;
if (!check_clip(role, type))
return FALSE;
if (role == ROLE_HS && type == TYPE_ACTION && parameter_number > 1)
return FALSE;
else if (role == ROLE_AG && parameter_number > 5)
return FALSE;
if (role == ROLE_HS && type == TYPE_ACTION) switch (parameter_number) {
case 0:
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_clip_mode, tvb, offset, parameter_length, value);
break;
case 1:
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_clip_status, tvb, offset, parameter_length, value);
break;
} else {
switch (parameter_number) {
case 0:
proto_tree_add_item(tree, hf_at_number, tvb, offset, parameter_length, ENC_NA | ENC_ASCII);
break;
case 1:
value = get_uint_parameter(parameter_stream, parameter_length);
pitem = proto_tree_add_uint(tree, hf_at_type, tvb, offset, parameter_length, value);
if (value < 128 || value > 175)
expert_add_info(pinfo, pitem, &ei_at_type);
break;
case 2:
proto_tree_add_item(tree, hf_at_subaddress, tvb, offset, parameter_length, ENC_NA | ENC_ASCII);
break;
case 3:
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_at_subaddress_type, tvb, offset, parameter_length, value);
break;
case 4:
proto_tree_add_item(tree, hf_at_alpha, tvb, offset, parameter_length, ENC_NA | ENC_ASCII);
break;
case 5:
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_at_cli_validity, tvb, offset, parameter_length, value);
break;
}
}
return TRUE;
}
static gint
dissect_cmee_parameter(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number, gint parameter_length, void **data _U_)
{
guint32 value;
if (!(role == ROLE_HS && type == TYPE_ACTION)) {
return FALSE;
}
if (parameter_number > 0) return FALSE;
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_cmee, tvb, offset, parameter_length, value);
return TRUE;
}
static gint
dissect_cops_parameter(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number, gint parameter_length, void **data _U_)
{
guint32 value;
if (!((role == ROLE_HS && (type == TYPE_ACTION || type == TYPE_READ)) ||
(role == ROLE_AG && type == TYPE_RESPONSE))) {
return FALSE;
}
if (parameter_number > 3) return FALSE;
switch (parameter_number) {
case 0:
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_cops_mode, tvb, offset, parameter_length, value);
break;
case 1:
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_cops_format, tvb, offset, parameter_length, value);
break;
case 2:
proto_tree_add_item(tree, hf_cops_operator, tvb, offset, parameter_length, ENC_NA | ENC_ASCII);
break;
case 3:
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_cops_act, tvb, offset, parameter_length, value);
break;
}
return TRUE;
}
static gint
dissect_clcc_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number, gint parameter_length, void **data _U_)
{
proto_item *pitem;
guint32 value;
if (!((role == ROLE_HS && type == TYPE_ACTION_SIMPLY) ||
(role == ROLE_AG && type == TYPE_RESPONSE))) {
return FALSE;
}
if (parameter_number > 8) return FALSE;
switch (parameter_number) {
case 0:
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_clcc_id, tvb, offset, parameter_length, value);
break;
case 1:
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_clcc_dir, tvb, offset, parameter_length, value);
break;
case 2:
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_clcc_stat, tvb, offset, parameter_length, value);
break;
case 3:
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_clcc_mode, tvb, offset, parameter_length, value);
break;
case 4:
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_clcc_mpty, tvb, offset, parameter_length, value);
break;
case 5:
proto_tree_add_item(tree, hf_at_number, tvb, offset, parameter_length, ENC_NA | ENC_ASCII);
break;
case 6:
value = get_uint_parameter(parameter_stream, parameter_length);
pitem = proto_tree_add_uint(tree, hf_at_type, tvb, offset, parameter_length, value);
if (value < 128 || value > 175)
expert_add_info(pinfo, pitem, &ei_at_type);
break;
case 7:
proto_tree_add_item(tree, hf_at_alpha, tvb, offset, parameter_length, ENC_NA | ENC_ASCII);
break;
case 8:
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_at_priority, tvb, offset, parameter_length, value);
break;
}
return TRUE;
}
static gint
dissect_cme_error_parameter(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number, gint parameter_length, void **data _U_)
{
guint32 value;
if (!(role == ROLE_AG && type == TYPE_RESPONSE)) {
return FALSE;
}
if (parameter_number > 0) return FALSE;
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_cme_error, tvb, offset, parameter_length, value);
return TRUE;
}
static gint
dissect_cnum_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number, gint parameter_length, void **data _U_)
{
proto_item *pitem;
guint32 value;
if (!(role == ROLE_AG && type == TYPE_RESPONSE)) return TRUE;
if (parameter_number > 5) return FALSE;
switch (parameter_number) {
case 0:
pitem = proto_tree_add_item(tree, hf_at_alpha, tvb, offset, parameter_length, ENC_NA | ENC_ASCII);
if (parameter_length > 0)
expert_add_info(pinfo, pitem, &ei_parameter_blank);
break;
case 1:
proto_tree_add_item(tree, hf_at_number, tvb, offset, parameter_length, ENC_NA | ENC_ASCII);
break;
case 2:
value = get_uint_parameter(parameter_stream, parameter_length);
pitem = proto_tree_add_uint(tree, hf_at_type, tvb, offset, parameter_length, value);
if (value < 128 || value > 175)
expert_add_info(pinfo, pitem, &ei_at_type);
break;
case 3:
value = get_uint_parameter(parameter_stream, parameter_length);
pitem = proto_tree_add_uint(tree, hf_cnum_speed, tvb, offset, parameter_length, value);
if (parameter_length > 0)
expert_add_info(pinfo, pitem, &ei_parameter_blank);
break;
case 4:
value = get_uint_parameter(parameter_stream, parameter_length);
pitem = proto_tree_add_uint(tree, hf_cnum_service, tvb, offset, parameter_length, value);
if (value > 5)
expert_add_info(pinfo, pitem, &ei_cnum_service);
break;
case 5:
value = get_uint_parameter(parameter_stream, parameter_length);
pitem = proto_tree_add_uint(tree, hf_cnum_itc, tvb, offset, parameter_length, value);
if (value > 1)
expert_add_info(pinfo, pitem, &ei_cnum_itc);
break;
}
return TRUE;
}
static gint
dissect_vts_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number, gint parameter_length, void **data _U_)
{
proto_item *pitem;
guint32 value;
if (!(role == ROLE_HS && type == TYPE_ACTION)) return TRUE;
if (parameter_number > 1) return FALSE;
switch (parameter_number) {
case 0:
pitem = proto_tree_add_item(tree, hf_vts_dtmf, tvb, offset, parameter_length, ENC_NA | ENC_ASCII);
if (parameter_length != 1)
expert_add_info(pinfo, pitem, &ei_vts_dtmf);
break;
case 1:
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_vts_duration, tvb, offset, parameter_length, value);
break;
}
return TRUE;
}
static gint
dissect_ciev_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, gint role, guint16 type, guint8 *parameter_stream,
guint parameter_number, gint parameter_length, void **data)
{
guint32 value;
guint indicator_index;
if (!(role == ROLE_AG && type == TYPE_RESPONSE)) return TRUE;
if (parameter_number > 1) return FALSE;
switch (parameter_number) {
case 0:
value = get_uint_parameter(parameter_stream, parameter_length);
proto_tree_add_uint(tree, hf_ciev_indicator_index, tvb, offset, parameter_length, value);
*data = wmem_alloc(wmem_packet_scope(), sizeof(guint));
*((guint *) *data) = value;
break;
case 1:
indicator_index = *((guint *) *data) - 1;
if (indicator_index > 19) {
proto_tree_add_expert(tree, pinfo, &ei_ciev_indicator, tvb, offset, parameter_length);
} else {
proto_tree_add_item(tree, hf_indicator[indicator_index], tvb, offset, parameter_length, ENC_NA | ENC_ASCII);
}
break;
}
return TRUE;
}
static gint
dissect_at_command(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
gint offset, guint32 role, gint command_number)
{
proto_item *pitem;
proto_tree *command_item = NULL;
proto_item *command_tree = NULL;
proto_tree *parameters_item = NULL;
proto_item *parameters_tree = NULL;
guint8 *col_str = NULL;
guint8 *at_stream;
guint8 *at_command = NULL;
gint i_char = 0;
guint i_char_fix = 0;
gint length;
const at_cmd_t *i_at_cmd;
gint parameter_length;
guint parameter_number = 0;
gint first_parameter_offset = offset;
gint last_parameter_offset = offset;
guint16 type = TYPE_UNKNOWN;
guint32 brackets;
gboolean quotation;
gboolean next;
void *data;
length = tvb_reported_length_remaining(tvb, offset);
if (length <= 0)
return tvb_reported_length(tvb);
if (!command_number) {
proto_tree_add_item(tree, hf_data, tvb, offset, length, ENC_NA | ENC_ASCII);
col_str = (guint8 *) wmem_alloc(wmem_packet_scope(), length + 1);
tvb_memcpy(tvb, col_str, offset, length);
col_str[length] = '\0';
}
at_stream = (guint8 *) wmem_alloc(wmem_packet_scope(), length + 1);
tvb_memcpy(tvb, at_stream, offset, length);
at_stream[length] = '\0';
while (at_stream[i_char]) {
at_stream[i_char] = g_ascii_toupper(at_stream[i_char]);
if (!command_number) {
col_str[i_char] = g_ascii_toupper(col_str[i_char]);
if (!g_ascii_isgraph(col_str[i_char])) col_str[i_char] = ' ';
}
i_char += 1;
}
if (!command_number) col_append_fstr(pinfo->cinfo, COL_INFO, "%s", col_str);
if (role == ROLE_HS) {
if (command_number) {
at_command = at_stream;
i_char = 0;
} else {
at_command = g_strstr_len(at_stream, length, "AT");
if (at_command) {
command_item = proto_tree_add_none_format(tree, hf_command, tvb,
offset, 0, "Command %u", command_number);
command_tree = proto_item_add_subtree(command_item, ett_bthfp_command);
i_char = (guint) (at_command - at_stream);
if (i_char) {
proto_tree_add_item(command_tree, hf_at_ignored, tvb, offset,
i_char, ENC_NA | ENC_ASCII);
offset += i_char;
}
proto_tree_add_item(command_tree, hf_at_command_line_prefix,
tvb, offset, 2, ENC_NA | ENC_ASCII);
offset += 2;
i_char += 2;
at_command = at_stream;
at_command += i_char;
length -= i_char;
i_char_fix += i_char;
i_char = 0;
}
}
} else if (at_stream[0] == '\r' && at_stream[1] == '\n') {
command_item = proto_tree_add_none_format(tree, hf_command, tvb,
offset, 0, "Command %u", command_number);
command_tree = proto_item_add_subtree(command_item, ett_bthfp_command);
at_command = at_stream;
i_char = 0;
while (i_char <= length &&
(at_command[i_char] == '\r' || at_command[i_char] == '\n' ||
at_command[i_char] == ' ' || at_command[i_char] == '\t')) {
i_char += 1;
}
offset += i_char;
at_command += i_char;
length -= i_char;
i_char_fix += i_char;
i_char = 0;
}
if (at_command) {
while (i_char < length &&
(at_command[i_char] != '\r' && at_command[i_char] != '=' &&
at_command[i_char] != ';' && at_command[i_char] != '?' &&
at_command[i_char] != ':')) {
i_char += 1;
}
i_at_cmd = at_cmds;
if (at_command[0] == '\r') {
pitem = proto_tree_add_item(command_tree, hf_at_cmd, tvb, offset - 2,
2, ENC_NA | ENC_ASCII);
i_at_cmd = NULL;
} else {
pitem = NULL;
while (i_at_cmd->name) {
if (g_str_has_prefix(&at_command[0], i_at_cmd->name)) {
pitem = proto_tree_add_item(command_tree, hf_at_cmd, tvb, offset,
(gint) strlen(i_at_cmd->name), ENC_NA | ENC_ASCII);
proto_item_append_text(pitem, " (%s)", i_at_cmd->long_name);
break;
}
i_at_cmd += 1;
}
if (!pitem) {
pitem = proto_tree_add_item(command_tree, hf_at_cmd, tvb, offset,
i_char, ENC_NA | ENC_ASCII);
}
}
if (i_at_cmd && i_at_cmd->name == NULL) {
char *name;
name = (char *) wmem_alloc(wmem_packet_scope(), i_char + 2);
g_strlcpy(name, at_command, i_char + 1);
name[i_char + 1] = '\0';
proto_item_append_text(command_item, ": %s (Unknown)", name);
proto_item_append_text(pitem, " (Unknown - Non-Standard HFP Command)");
expert_add_info(pinfo, pitem, &ei_non_mandatory_command);
} else if (i_at_cmd == NULL) {
proto_item_append_text(command_item, ": AT");
} else {
proto_item_append_text(command_item, ": %s", i_at_cmd->name);
}
offset += i_char;
if (i_at_cmd && g_strcmp0(i_at_cmd->name, "D")) {
if (length >= 2 && at_command[i_char] == '=' && at_command[i_char + 1] == '?') {
type = at_command[i_char] << 8 | at_command[i_char + 1];
proto_tree_add_uint(command_tree, hf_at_cmd_type, tvb, offset, 2, type);
offset += 2;
i_char += 2;
} else if (role == ROLE_AG && length >= 2 && at_command[i_char] == '\r' && at_command[i_char + 1] == '\n') {
type = at_command[i_char] << 8 | at_command[i_char + 1];
proto_tree_add_uint(command_tree, hf_at_cmd_type, tvb, offset, 2, type);
offset += 2;
i_char += 2;
} else if (length >= 1 && (at_command[i_char] == '=' ||
at_command[i_char] == '\r' ||
at_command[i_char] == ':' ||
at_command[i_char] == '?')) {
type = at_command[i_char];
proto_tree_add_uint(command_tree, hf_at_cmd_type, tvb, offset, 1, type);
offset += 1;
i_char += 1;
}
}
if (i_at_cmd && i_at_cmd->check_command && !i_at_cmd->check_command(role, type)) {
expert_add_info(pinfo, command_item, &ei_invalid_usage);
}
parameters_item = proto_tree_add_none_format(command_tree, hf_parameters, tvb,
offset, 0, "Parameters");
parameters_tree = proto_item_add_subtree(parameters_item, ett_bthfp_parameters);
data = NULL;
while (i_char < length) {
while (at_command[i_char] == ' ' || at_command[i_char] == '\t') {
offset += 1;
i_char += 1;
}
parameter_length = 0;
brackets = 0;
quotation = FALSE;
next = FALSE;
if (at_command[i_char + parameter_length] != '\r') {
while (i_char + parameter_length < length &&
at_command[i_char + parameter_length] != '\r') {
if (at_command[i_char + parameter_length] == ';') {
next = TRUE;
break;
}
if (at_command[i_char + parameter_length] == '"') {
quotation = quotation ? FALSE : TRUE;
}
if (quotation == TRUE) {
parameter_length += 1;
continue;
}
if (at_command[i_char + parameter_length] == '(') {
brackets += 1;
}
if (at_command[i_char + parameter_length] == ')') {
brackets -= 1;
}
if (brackets == 0 && at_command[i_char + parameter_length] == ',') {
break;
}
parameter_length += 1;
}
first_parameter_offset = offset;
if (type == TYPE_ACTION || type == TYPE_RESPONSE) {
if (i_at_cmd && (i_at_cmd->dissect_parameter != NULL &&
!i_at_cmd->dissect_parameter(tvb, pinfo, parameters_tree, offset, role,
type, &at_command[i_char], parameter_number, parameter_length, &data) )) {
pitem = proto_tree_add_item(parameters_tree,
hf_unknown_parameter, tvb, offset,
parameter_length, ENC_NA | ENC_ASCII);
expert_add_info(pinfo, pitem, &ei_unknown_parameter);
} else if (i_at_cmd && i_at_cmd->dissect_parameter == NULL) {
proto_tree_add_item(parameters_tree, hf_parameter, tvb, offset,
parameter_length, ENC_NA | ENC_ASCII);
}
}
}
if (type != TYPE_ACTION_SIMPLY && type != TYPE_RESPONSE_ACK && type != TYPE_TEST && type != TYPE_READ)
parameter_number += 1;
i_char += parameter_length;
offset += parameter_length;
last_parameter_offset = offset;
if (role == ROLE_AG &&
i_char + 1 <= length &&
at_command[i_char] == '\r' &&
at_command[i_char + 1] == '\n') {
offset += 2;
i_char += 2;
break;
} else if (at_command[i_char] == ',' ||
at_command[i_char] == '\r' ||
at_command[i_char] == ';') {
i_char += 1;
offset += 1;
}
if (next) break;
}
i_char += i_char_fix;
proto_item_set_len(command_item, i_char);
} else {
length = tvb_reported_length_remaining(tvb, offset);
if (length < 0)
length = 0;
offset += length;
}
if (parameter_number > 0 && last_parameter_offset - first_parameter_offset > 0)
proto_item_set_len(parameters_item, last_parameter_offset - first_parameter_offset);
else
proto_item_append_text(parameters_item, ": No");
return offset;
}
static gint
dissect_bthfp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
proto_item *main_item;
proto_tree *main_tree;
proto_item *pitem;
gint offset = 0;
guint32 role = ROLE_UNKNOWN;
wmem_tree_key_t key[10];
guint32 interface_id;
guint32 adapter_id;
guint32 chandle;
guint32 dlci;
guint32 frame_number;
guint32 direction;
guint32 bd_addr_oui;
guint32 bd_addr_id;
fragment_t *fragment;
fragment_t *previous_fragment;
fragment_t *i_fragment;
guint8 *at_stream;
gint length;
gint command_number;
gint i_length;
tvbuff_t *reassembled_tvb = NULL;
guint reassemble_start_offset = 0;
guint reassemble_end_offset = 0;
gint previous_proto;
previous_proto = (GPOINTER_TO_INT(wmem_list_frame_data(wmem_list_frame_prev(wmem_list_tail(pinfo->layers)))));
if (data && previous_proto == proto_btrfcomm) {
btrfcomm_data_t *rfcomm_data;
rfcomm_data = (btrfcomm_data_t *) data;
interface_id = rfcomm_data->interface_id;
adapter_id = rfcomm_data->adapter_id;
chandle = rfcomm_data->chandle;
dlci = rfcomm_data->dlci;
direction = (rfcomm_data->is_local_psm) ? P2P_DIR_SENT : P2P_DIR_RECV;
if (direction == P2P_DIR_RECV) {
bd_addr_oui = rfcomm_data->remote_bd_addr_oui;
bd_addr_id = rfcomm_data->remote_bd_addr_id;
} else {
bd_addr_oui = 0;
bd_addr_id = 0;
}
} else {
interface_id = HCI_INTERFACE_DEFAULT;
adapter_id = HCI_ADAPTER_DEFAULT;
chandle = 0;
dlci = 0;
direction = P2P_DIR_UNKNOWN;
bd_addr_oui = 0;
bd_addr_id = 0;
}
main_item = proto_tree_add_item(tree, proto_bthfp, tvb, 0, tvb_captured_length(tvb), ENC_NA);
main_tree = proto_item_add_subtree(main_item, ett_bthfp);
col_set_str(pinfo->cinfo, COL_PROTOCOL, "HFP");
switch (pinfo->p2p_dir) {
case P2P_DIR_SENT:
col_set_str(pinfo->cinfo, COL_INFO, "Sent ");
break;
case P2P_DIR_RECV:
col_set_str(pinfo->cinfo, COL_INFO, "Rcvd ");
break;
default:
col_set_str(pinfo->cinfo, COL_INFO, "UnknownDirection ");
break;
}
if ((hfp_role == ROLE_AG && pinfo->p2p_dir == P2P_DIR_SENT) ||
(hfp_role == ROLE_HS && pinfo->p2p_dir == P2P_DIR_RECV)) {
role = ROLE_AG;
} else if (hfp_role != ROLE_UNKNOWN) {
role = ROLE_HS;
}
if (role == ROLE_UNKNOWN) {
guint32 sdp_psm;
guint32 service_type;
guint32 service_channel;
service_info_t *service_info;
sdp_psm = SDP_PSM_DEFAULT;
service_type = BTSDP_RFCOMM_PROTOCOL_UUID;
service_channel = dlci >> 1;
frame_number = pinfo->num;
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &sdp_psm;
key[3].length = 1;
key[3].key = &direction;
key[4].length = 1;
key[4].key = &bd_addr_oui;
key[5].length = 1;
key[5].key = &bd_addr_id;
key[6].length = 1;
key[6].key = &service_type;
key[7].length = 1;
key[7].key = &service_channel;
key[8].length = 1;
key[8].key = &frame_number;
key[9].length = 0;
key[9].key = NULL;
service_info = btsdp_get_service_info(key);
if (service_info && service_info->interface_id == interface_id &&
service_info->adapter_id == adapter_id &&
service_info->sdp_psm == SDP_PSM_DEFAULT &&
((service_info->direction == P2P_DIR_RECV &&
service_info->bd_addr_oui == bd_addr_oui &&
service_info->bd_addr_id == bd_addr_id) ||
(service_info->direction != P2P_DIR_RECV &&
service_info->bd_addr_oui == 0 &&
service_info->bd_addr_id == 0)) &&
service_info->type == BTSDP_RFCOMM_PROTOCOL_UUID &&
service_info->channel == (dlci >> 1)) {
if ((service_info->uuid.bt_uuid == BTSDP_HFP_GW_SERVICE_UUID && service_info->direction == P2P_DIR_RECV && pinfo->p2p_dir == P2P_DIR_SENT) ||
(service_info->uuid.bt_uuid == BTSDP_HFP_GW_SERVICE_UUID && service_info->direction == P2P_DIR_SENT && pinfo->p2p_dir == P2P_DIR_RECV) ||
(service_info->uuid.bt_uuid == BTSDP_HFP_SERVICE_UUID && service_info->direction == P2P_DIR_RECV && pinfo->p2p_dir == P2P_DIR_RECV) ||
(service_info->uuid.bt_uuid == BTSDP_HFP_SERVICE_UUID && service_info->direction == P2P_DIR_SENT && pinfo->p2p_dir == P2P_DIR_SENT)) {
role = ROLE_HS;
} else {
role = ROLE_AG;
}
}
}
pitem = proto_tree_add_uint(main_tree, hf_role, tvb, 0, 0, role);
PROTO_ITEM_SET_GENERATED(pitem);
if (role == ROLE_UNKNOWN) {
col_append_fstr(pinfo->cinfo, COL_INFO, "Data: %s",
tvb_format_text(tvb, 0, tvb_reported_length(tvb)));
proto_tree_add_item(main_tree, hf_data, tvb, 0, tvb_captured_length(tvb), ENC_NA | ENC_ASCII);
return tvb_reported_length(tvb);
}
if (!pinfo->fd->flags.visited) {
frame_number = pinfo->num - 1;
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &chandle;
key[3].length = 1;
key[3].key = &dlci;
key[4].length = 1;
key[4].key = &role;
key[5].length = 1;
key[5].key = &frame_number;
key[6].length = 0;
key[6].key = NULL;
previous_fragment = (fragment_t *) wmem_tree_lookup32_array_le(fragments, key);
if (!(previous_fragment && previous_fragment->interface_id == interface_id &&
previous_fragment->adapter_id == adapter_id &&
previous_fragment->chandle == chandle &&
previous_fragment->dlci == dlci &&
previous_fragment->role == role &&
previous_fragment->reassemble_state != REASSEMBLE_DONE)) {
previous_fragment = NULL;
}
frame_number = pinfo->num;
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &chandle;
key[3].length = 1;
key[3].key = &dlci;
key[4].length = 1;
key[4].key = &role;
key[5].length = 1;
key[5].key = &frame_number;
key[6].length = 0;
key[6].key = NULL;
fragment = wmem_new(wmem_file_scope(), fragment_t);
fragment->interface_id = interface_id;
fragment->adapter_id = adapter_id;
fragment->chandle = chandle;
fragment->dlci = dlci;
fragment->role = role;
fragment->idx = previous_fragment ? previous_fragment->idx + previous_fragment->length : 0;
fragment->reassemble_state = REASSEMBLE_FRAGMENT;
fragment->length = tvb_reported_length(tvb);
fragment->data = (guint8 *) wmem_alloc(wmem_file_scope(), fragment->length);
fragment->previous_fragment = previous_fragment;
tvb_memcpy(tvb, fragment->data, offset, fragment->length);
wmem_tree_insert32_array(fragments, key, fragment);
length = tvb_reported_length(tvb);
at_stream = tvb_get_string_enc(wmem_packet_scope(), tvb, 0, length, ENC_ASCII);
reassemble_start_offset = 0;
for (i_length = 0; i_length < length; i_length += 1) {
if (!((role == ROLE_HS && at_stream[i_length] == '\r') ||
(role == ROLE_AG && at_stream[i_length] == '\n'))) {
continue;
}
if (role == ROLE_HS && at_stream[i_length] == '\r') {
reassemble_start_offset = i_length + 1;
if (reassemble_end_offset == 0) reassemble_end_offset = i_length + 1;
}
if (role == ROLE_AG && at_stream[i_length] == '\n') {
reassemble_start_offset = i_length + 1;
}
frame_number = pinfo->num;
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &chandle;
key[3].length = 1;
key[3].key = &dlci;
key[4].length = 1;
key[4].key = &role;
key[5].length = 1;
key[5].key = &frame_number;
key[6].length = 0;
key[6].key = NULL;
fragment = (fragment_t *) wmem_tree_lookup32_array_le(fragments, key);
if (fragment && fragment->interface_id == interface_id &&
fragment->adapter_id == adapter_id &&
fragment->chandle == chandle &&
fragment->dlci == dlci &&
fragment->role == role) {
i_fragment = fragment;
while (i_fragment && i_fragment->idx > 0) {
i_fragment = i_fragment->previous_fragment;
}
if (i_length + 1 == length &&
role == ROLE_HS &&
at_stream[i_length] == '\r') {
fragment->reassemble_state = REASSEMBLE_DONE;
} else if (i_length + 1 == length &&
role == ROLE_AG &&
i_length >= 4 &&
at_stream[i_length] == '\n' &&
at_stream[i_length - 1] == '\r' &&
at_stream[0] == '\r' &&
at_stream[1] == '\n') {
fragment->reassemble_state = REASSEMBLE_DONE;
} else if (i_length + 1 == length &&
role == ROLE_AG &&
i_length >= 2 &&
at_stream[i_length] == '\n' &&
at_stream[i_length - 1] == '\r' &&
i_fragment &&
i_fragment->reassemble_state == REASSEMBLE_FRAGMENT &&
i_fragment->length >= 2 &&
i_fragment->data[0] == '\r' &&
i_fragment->data[1] == '\n') {
fragment->reassemble_state = REASSEMBLE_DONE;
} else if (role == ROLE_HS) {
}
fragment->reassemble_start_offset = reassemble_start_offset;
fragment->reassemble_end_offset = reassemble_end_offset;
}
}
}
frame_number = pinfo->num;
key[0].length = 1;
key[0].key = &interface_id;
key[1].length = 1;
key[1].key = &adapter_id;
key[2].length = 1;
key[2].key = &chandle;
key[3].length = 1;
key[3].key = &dlci;
key[4].length = 1;
key[4].key = &role;
key[5].length = 1;
key[5].key = &frame_number;
key[6].length = 0;
key[6].key = NULL;
fragment = (fragment_t *) wmem_tree_lookup32_array_le(fragments, key);
if (fragment && fragment->interface_id == interface_id &&
fragment->adapter_id == adapter_id &&
fragment->chandle == chandle &&
fragment->dlci == dlci &&
fragment->role == role &&
fragment->reassemble_state != REASSEMBLE_FRAGMENT) {
guint8 *at_data;
guint i_data_offset;
i_data_offset = fragment->idx + fragment->length;
at_data = (guint8 *) wmem_alloc(pinfo->pool, fragment->idx + fragment->length);
i_fragment = fragment;
if (i_fragment && i_fragment->reassemble_state == REASSEMBLE_PARTIALLY) {
i_data_offset -= i_fragment->reassemble_end_offset;
memcpy(at_data + i_data_offset, i_fragment->data, i_fragment->reassemble_end_offset);
i_fragment = i_fragment->previous_fragment;
}
if (i_fragment) {
while (i_fragment && i_fragment->idx > 0) {
i_data_offset -= i_fragment->length;
memcpy(at_data + i_data_offset, i_fragment->data, i_fragment->length);
i_fragment = i_fragment->previous_fragment;
}
if (i_fragment && i_fragment->reassemble_state == REASSEMBLE_PARTIALLY) {
i_data_offset -= (i_fragment->length - i_fragment->reassemble_start_offset);
memcpy(at_data + i_data_offset, i_fragment->data + i_fragment->reassemble_start_offset,
i_fragment->length - i_fragment->reassemble_start_offset);
} else if (i_fragment) {
i_data_offset -= i_fragment->length;
memcpy(at_data + i_data_offset, i_fragment->data, i_fragment->length);
}
}
if (fragment->idx > 0 && fragment->length > 0) {
proto_tree_add_item(main_tree, hf_fragment, tvb, offset,
tvb_captured_length_remaining(tvb, offset), ENC_ASCII | ENC_NA);
reassembled_tvb = tvb_new_child_real_data(tvb, at_data,
fragment->idx + fragment->length, fragment->idx + fragment->length);
add_new_data_source(pinfo, reassembled_tvb, "Reassembled HFP");
}
command_number = 0;
if (reassembled_tvb) {
guint reassembled_offset = 0;
while (tvb_reported_length(reassembled_tvb) > reassembled_offset) {
reassembled_offset = dissect_at_command(reassembled_tvb,
pinfo, main_tree, reassembled_offset, role, command_number);
command_number += 1;
}
offset = tvb_captured_length(tvb);
} else {
while (tvb_reported_length(tvb) > (guint) offset) {
offset = dissect_at_command(tvb, pinfo, main_tree, offset, role, command_number);
command_number += 1;
}
}
} else {
col_append_fstr(pinfo->cinfo, COL_INFO, "Fragment: %s",
tvb_format_text_wsp(tvb, offset, tvb_captured_length_remaining(tvb, offset)));
pitem = proto_tree_add_item(main_tree, hf_fragmented, tvb, 0, 0, ENC_NA);
PROTO_ITEM_SET_GENERATED(pitem);
proto_tree_add_item(main_tree, hf_fragment, tvb, offset,
tvb_captured_length_remaining(tvb, offset), ENC_ASCII | ENC_NA);
offset = tvb_captured_length(tvb);
}
return offset;
}
void
proto_register_bthfp(void)
{
module_t *module;
expert_module_t *expert_bthfp;
static hf_register_info hf[] = {
{ &hf_command,
{ "Command", "bthfp.command",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_parameters,
{ "Parameters", "bthfp.parameters",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_data,
{ "AT Stream", "bthfp.data",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_fragment,
{ "Fragment", "bthfp.fragment",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_fragmented,
{ "Fragmented", "bthfp.fragmented",
FT_NONE, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_at_ignored,
{ "Ignored", "bthfp.ignored",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_at_cmd,
{ "Command", "bthfp.at_cmd",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_at_cmd_type,
{ "Type", "bthfp.at_cmd.type",
FT_UINT16, BASE_HEX, VALS(at_cmd_type_vals), 0,
NULL, HFILL}
},
{ &hf_at_command_line_prefix,
{ "Command Line Prefix", "bthfp.command_line_prefix",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_parameter,
{ "Parameter", "bthfp.parameter",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_unknown_parameter,
{ "Unknown Parameter", "bthfp.unknown_parameter",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_role,
{ "Role", "bthfp.role",
FT_UINT8, BASE_DEC, VALS(role_vals), 0,
NULL, HFILL}
},
{ &hf_brsf_hs,
{ "HS supported features bitmask", "bthfp.brsf.hs.features",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_brsf_hs_ec_nr_function,
{ "EC and/or NR function", "bthfp.brsf.hs.ec_nr_function",
FT_BOOLEAN, 32, NULL, 0x00000001,
NULL, HFILL}
},
{ &hf_brsf_hs_call_waiting_or_tree_way,
{ "Call waiting or 3-way calling", "bthfp.brsf.hs.call_waiting_or_tree_way",
FT_BOOLEAN, 32, NULL, 0x00000002,
NULL, HFILL}
},
{ &hf_brsf_hs_cli_presentation,
{ "CLI Presentation", "bthfp.brsf.hs.cli_presentation",
FT_BOOLEAN, 32, NULL, 0x00000004,
NULL, HFILL}
},
{ &hf_brsf_hs_voice_recognition_activation,
{ "Voice Recognition Activation", "bthfp.brsf.hs.voice_recognition_activation",
FT_BOOLEAN, 32, NULL, 0x00000008,
NULL, HFILL}
},
{ &hf_brsf_hs_remote_volume_control,
{ "Remote Volume Control", "bthfp.brsf.hs.remote_volume_control",
FT_BOOLEAN, 32, NULL, 0x00000010,
NULL, HFILL}
},
{ &hf_brsf_hs_enhanced_call_status,
{ "Enhanced Call Status", "bthfp.brsf.hs.enhanced_call_status",
FT_BOOLEAN, 32, NULL, 0x00000020,
NULL, HFILL}
},
{ &hf_brsf_hs_enhanced_call_control,
{ "Enhanced Call Control", "bthfp.brsf.hs.enhanced_call_control",
FT_BOOLEAN, 32, NULL, 0x00000040,
NULL, HFILL}
},
{ &hf_brsf_hs_codec_negotiation,
{ "Codec Negotiation", "bthfp.brsf.hs.codec_negotiation",
FT_BOOLEAN, 32, NULL, 0x00000080,
NULL, HFILL}
},
{ &hf_brsf_hs_hf_indicators,
{ "HF Indicators", "bthfp.brsf.hs.hf_indicators",
FT_BOOLEAN, 32, NULL, 0x00000100,
NULL, HFILL}
},
{ &hf_brsf_hs_esco_s4_t2_settings_support,
{ "eSCO S4 (and T2) Settings Support","bthfp.brsf.hs.esco_s4_t2_settings_support",
FT_BOOLEAN, 32, NULL, 0x00000200,
NULL, HFILL}
},
{ &hf_brsf_hs_reserved,
{ "Reserved", "bthfp.brsf.hs.reserved",
FT_UINT32, BASE_HEX, NULL, 0xFFFFFC00,
NULL, HFILL}
},
{ &hf_brsf_ag,
{ "AG supported features bitmask", "bthfp.brsf.ag.features",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_brsf_ag_three_way_calling,
{ "Three Way Calling", "bthfp.brsf.ag.three_way_calling",
FT_BOOLEAN, 32, NULL, 0x00000001,
NULL, HFILL}
},
{ &hf_brsf_ag_ec_nr_function,
{ "EC and/or NR function", "bthfp.brsf.ag.ec_nr_function",
FT_BOOLEAN, 32, NULL, 0x00000002,
NULL, HFILL}
},
{ &hf_brsf_ag_voice_recognition_function,
{ "Voice Recognition Function", "bthfp.brsf.ag.voice_recognition_function",
FT_BOOLEAN, 32, NULL, 0x00000004,
NULL, HFILL}
},
{ &hf_brsf_ag_inband_ring_tone,
{ "In-band Ring Tone", "bthfp.brsf.ag.inband_ring_tone",
FT_BOOLEAN, 32, NULL, 0x00000008,
NULL, HFILL}
},
{ &hf_brsf_ag_attach_number_to_voice_tag,
{ "Attach Number to Voice Tag", "bthfp.brsf.ag.attach_number_to_voice_tag",
FT_BOOLEAN, 32, NULL, 0x00000010,
NULL, HFILL}
},
{ &hf_brsf_ag_ability_to_reject_a_call,
{ "Ability to Reject a Call", "bthfp.brsf.ag.ability_to_reject_a_call",
FT_BOOLEAN, 32, NULL, 0x00000020,
NULL, HFILL}
},
{ &hf_brsf_ag_enhanced_call_status,
{ "Enhanced Call Status", "bthfp.brsf.ag.enhanced_call_status",
FT_BOOLEAN, 32, NULL, 0x00000040,
NULL, HFILL}
},
{ &hf_brsf_ag_enhanced_call_control,
{ "Enhanced Call Control", "bthfp.brsf.ag.enhanced_call_control",
FT_BOOLEAN, 32, NULL, 0x00000080,
NULL, HFILL}
},
{ &hf_brsf_ag_extended_error_result_codes,
{ "Extended Error Result Codes", "bthfp.brsf.ag.extended_error_result_codes",
FT_BOOLEAN, 32, NULL, 0x00000100,
NULL, HFILL}
},
{ &hf_brsf_ag_codec_negotiation,
{ "Codec Negotiation", "bthfp.brsf.ag.codec_negotiation",
FT_BOOLEAN, 32, NULL, 0x00000200,
NULL, HFILL}
},
{ &hf_brsf_ag_hf_indicators,
{ "HF Indicators", "bthfp.brsf.ag.hf_indicators",
FT_BOOLEAN, 32, NULL, 0x00000400,
NULL, HFILL}
},
{ &hf_brsf_ag_esco_s4_t2_settings_support,
{ "eSCO S4 (and T2) Settings Support","bthfp.brsf.ag.esco_s4_t2_settings_support",
FT_BOOLEAN, 32, NULL, 0x00000800,
NULL, HFILL}
},
{ &hf_brsf_ag_reserved,
{ "Reserved", "bthfp.brsf.ag.reserved",
FT_UINT32, BASE_HEX, NULL, 0xFFFFF000,
NULL, HFILL}
},
{ &hf_vgs,
{ "Gain", "bthfp.vgs",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_vgm,
{ "Gain", "bthfp.vgm",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_nrec,
{ "Noise Reduction", "bthfp.nrec",
FT_UINT8, BASE_DEC, VALS(nrec_vals), 0,
NULL, HFILL}
},
{ &hf_bvra_vrect,
{ "Voice Recognition", "bthfp.bvra.vrect",
FT_UINT8, BASE_DEC, VALS(bvra_vrect_vals), 0,
NULL, HFILL}
},
{ &hf_bsir,
{ "Feature", "bthfp.bsir",
FT_UINT8, BASE_DEC, VALS(bsir_vals), 0,
NULL, HFILL}
},
{ &hf_btrh,
{ "Feature", "bthfp.btrh",
FT_UINT8, BASE_DEC, VALS(btrh_vals), 0,
NULL, HFILL}
},
{ &hf_cmer_mode,
{ "Mode", "bthfp.cmer.mode",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_cmer_keyp,
{ "Keypad", "bthfp.cmer.keyp",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_cmer_disp,
{ "Display", "bthfp.cmer.disp",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_cmer_ind,
{ "Indicator", "bthfp.cmer.ind",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_cmer_bfr,
{ "Buffer", "bthfp.cmer.bfr",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_bac_codec,
{ "Codec", "bthfp.bac.codec",
FT_UINT8, BASE_DEC, VALS(codecs_vals), 0,
NULL, HFILL}
},
{ &hf_bcs_codec,
{ "Codec", "bthfp.bcs.codec",
FT_UINT8, BASE_DEC, VALS(codecs_vals), 0,
NULL, HFILL}
},
{ &hf_binp_request,
{ "Request", "bthfp.binp.request",
FT_UINT8, BASE_DEC, VALS(binp_request_vals), 0,
NULL, HFILL}
},
{ &hf_binp_response,
{ "Response", "bthfp.binp.response",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_cme_error,
{ "CME Error", "bthfp.cme_error",
FT_UINT8, BASE_DEC, VALS(cme_error_vals), 0,
NULL, HFILL}
},
{ &hf_cmee,
{ "Mode", "bthfp.cmee",
FT_UINT8, BASE_DEC, VALS(cmee_vals), 0,
NULL, HFILL}
},
{ &hf_chld_mode,
{ "Mode", "bthfp.chld.mode_value",
FT_UINT8, BASE_DEC, VALS(chld_vals), 0,
NULL, HFILL}
},
{ &hf_chld_mode_1x,
{ "Mode: Releases specified active call only", "bthfp.chld.mode",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_chld_mode_2x,
{ "Mode: Request private consultation mode with specified call - place all calls on hold EXCEPT the call indicated by x", "bthfp.chld.mode",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_chld_supported_modes,
{ "Supported Modes", "bthfp.chld.supported_modes",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_ciev_indicator_index,
{ "Indicator Index", "bthfp.ciev.indicator_index",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_vts_dtmf,
{ "DTMF", "bthfp.vts.dtmf",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_vts_duration,
{ "Duration", "bthfp.vts.duration",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_cops_mode,
{ "Mode", "bthfp.cops.mode",
FT_UINT8, BASE_DEC, VALS(cops_mode_vals), 0,
NULL, HFILL}
},
{ &hf_cops_format,
{ "Format", "bthfp.cops.format",
FT_UINT8, BASE_DEC, VALS(cops_format_vals), 0,
NULL, HFILL}
},
{ &hf_cops_operator,
{ "Operator", "bthfp.cops.operator",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_cops_act,
{ "AcT", "bthfp.cops.act",
FT_UINT8, BASE_DEC, VALS(cops_act_vals), 0,
NULL, HFILL}
},
{ &hf_clip_mode,
{ "Mode", "bthfp.clip.mode",
FT_UINT8, BASE_DEC, VALS(clip_mode_vals), 0,
NULL, HFILL}
},
{ &hf_clip_status,
{ "Status", "bthfp.clip.status",
FT_UINT8, BASE_DEC, VALS(clip_status_vals), 0,
NULL, HFILL}
},
{ &hf_at_number,
{ "Number", "bthfp.at.number",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_at_type,
{ "Number", "bthfp.at.type",
FT_UINT8, BASE_DEC | BASE_RANGE_STRING, RVALS(at_type_vals), 0,
NULL, HFILL}
},
{ &hf_at_subaddress,
{ "Subaddress", "bthfp.at.subaddress",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_at_subaddress_type,
{ "Subaddress Type", "bthfp.at.subaddress_type",
FT_UINT8, BASE_DEC | BASE_RANGE_STRING, RVALS(at_type_vals), 0,
NULL, HFILL}
},
{ &hf_cnum_speed,
{ "Speed", "bthfp.cnum.speed",
FT_UINT8, BASE_DEC | BASE_EXT_STRING, &csd_data_rate_vals_ext, 0,
NULL, HFILL}
},
{ &hf_cnum_service,
{ "Service", "bthfp.cnum.service",
FT_UINT8, BASE_DEC, VALS(cnum_service_vals), 0,
NULL, HFILL}
},
{ &hf_cnum_itc,
{ "Information Transfer Capability", "bthfp.cnum.itc",
FT_UINT8, BASE_DEC, VALS(cnum_itc_vals), 0,
NULL, HFILL}
},
{ &hf_at_alpha,
{ "Alpha", "bthfp.at.alpha",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_at_cli_validity,
{ "CLI Validity", "bthfp.at.cli_validity",
FT_UINT8, BASE_DEC, VALS(cli_validity_vals), 0,
NULL, HFILL}
},
{ &hf_at_priority,
{ "Priority", "bthfp.at.priority",
FT_UINT8, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_clcc_id,
{ "ID", "bthfp.clcc.id",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_clcc_dir,
{ "Direction", "bthfp.clcc.dir",
FT_UINT32, BASE_DEC, VALS(clcc_dir_vals), 0,
NULL, HFILL}
},
{ &hf_clcc_stat,
{ "State", "bthfp.clcc.stat",
FT_UINT32, BASE_DEC, VALS(clcc_stat_vals), 0,
NULL, HFILL}
},
{ &hf_clcc_mode,
{ "Mode", "bthfp.clcc.mode",
FT_UINT32, BASE_DEC, VALS(clcc_mode_vals), 0,
NULL, HFILL}
},
{ &hf_clcc_mpty,
{ "Mpty", "bthfp.clcc.mpty",
FT_UINT32, BASE_DEC, VALS(clcc_mpty_vals), 0,
NULL, HFILL}
},
{ &hf_ccwa_show_result_code,
{ "Show Result Code Presentation Status", "bthfp.ccwa.presentaion_status",
FT_UINT32, BASE_DEC, VALS(ccwa_show_result_code_vals), 0,
NULL, HFILL}
},
{ &hf_ccwa_mode,
{ "Mode", "bthfp.ccwa.mode",
FT_UINT32, BASE_DEC, VALS(ccwa_mode_vals), 0,
NULL, HFILL}
},
{ &hf_ccwa_class,
{ "Class", "bthfp.ccwa.class",
FT_UINT32, BASE_DEC, VALS(ccwa_class_vals), 0,
NULL, HFILL}
},
{ &hf_biev_assigned_number,
{ "Assigned Number", "bthfp.biev.assigned_number",
FT_UINT16, BASE_DEC, VALS(biev_assigned_number_vals), 0,
NULL, HFILL}
},
{ &hf_bind_parameter,
{ "Parameter", "bthfp.bind.parameter",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_biev_value,
{ "Value", "bthfp.biev.value",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL}
},
{ &hf_bia_indicator[0],
{ "Indicator 1", "bthfp.bia.indicator.1",
FT_UINT8, BASE_DEC, VALS(indicator_vals), 0,
NULL, HFILL}
},
{ &hf_bia_indicator[1],
{ "Indicator 2", "bthfp.bia.indicator.2",
FT_UINT8, BASE_DEC, VALS(indicator_vals), 0,
NULL, HFILL}
},
{ &hf_bia_indicator[2],
{ "Indicator 3", "bthfp.bia.indicator.3",
FT_UINT8, BASE_DEC, VALS(indicator_vals), 0,
NULL, HFILL}
},
{ &hf_bia_indicator[3],
{ "Indicator 4", "bthfp.bia.indicator.4",
FT_UINT8, BASE_DEC, VALS(indicator_vals), 0,
NULL, HFILL}
},
{ &hf_bia_indicator[4],
{ "Indicator 5", "bthfp.bia.indicator.5",
FT_UINT8, BASE_DEC, VALS(indicator_vals), 0,
NULL, HFILL}
},
{ &hf_bia_indicator[5],
{ "Indicator 6", "bthfp.bia.indicator.6",
FT_UINT8, BASE_DEC, VALS(indicator_vals), 0,
NULL, HFILL}
},
{ &hf_bia_indicator[6],
{ "Indicator 7", "bthfp.bia.indicator.7",
FT_UINT8, BASE_DEC, VALS(indicator_vals), 0,
NULL, HFILL}
},
{ &hf_bia_indicator[7],
{ "Indicator 8", "bthfp.bia.indicator.8",
FT_UINT8, BASE_DEC, VALS(indicator_vals), 0,
NULL, HFILL}
},
{ &hf_bia_indicator[8],
{ "Indicator 9", "bthfp.bia.indicator.9",
FT_UINT8, BASE_DEC, VALS(indicator_vals), 0,
NULL, HFILL}
},
{ &hf_bia_indicator[9],
{ "Indicator 10", "bthfp.bia.indicator.10",
FT_UINT8, BASE_DEC, VALS(indicator_vals), 0,
NULL, HFILL}
},
{ &hf_bia_indicator[10],
{ "Indicator 11", "bthfp.bia.indicator.11",
FT_UINT8, BASE_DEC, VALS(indicator_vals), 0,
NULL, HFILL}
},
{ &hf_bia_indicator[11],
{ "Indicator 12", "bthfp.bia.indicator.12",
FT_UINT8, BASE_DEC, VALS(indicator_vals), 0,
NULL, HFILL}
},
{ &hf_bia_indicator[12],
{ "Indicator 13", "bthfp.bia.indicator.13",
FT_UINT8, BASE_DEC, VALS(indicator_vals), 0,
NULL, HFILL}
},
{ &hf_bia_indicator[13],
{ "Indicator 14", "bthfp.bia.indicator.14",
FT_UINT8, BASE_DEC, VALS(indicator_vals), 0,
NULL, HFILL}
},
{ &hf_bia_indicator[14],
{ "Indicator 15", "bthfp.bia.indicator.15",
FT_UINT8, BASE_DEC, VALS(indicator_vals), 0,
NULL, HFILL}
},
{ &hf_bia_indicator[15],
{ "Indicator 16", "bthfp.bia.indicator.16",
FT_UINT8, BASE_DEC, VALS(indicator_vals), 0,
NULL, HFILL}
},
{ &hf_bia_indicator[16],
{ "Indicator 17", "bthfp.bia.indicator.17",
FT_UINT8, BASE_DEC, VALS(indicator_vals), 0,
NULL, HFILL}
},
{ &hf_bia_indicator[17],
{ "Indicator 18", "bthfp.bia.indicator.18",
FT_UINT8, BASE_DEC, VALS(indicator_vals), 0,
NULL, HFILL}
},
{ &hf_bia_indicator[18],
{ "Indicator 19", "bthfp.bia.indicator.19",
FT_UINT8, BASE_DEC, VALS(indicator_vals), 0,
NULL, HFILL}
},
{ &hf_bia_indicator[19],
{ "Indicator 20", "bthfp.bia.indicator.20",
FT_UINT8, BASE_DEC, VALS(indicator_vals), 0,
NULL, HFILL}
},
{ &hf_indicator[0],
{ "Indicator 1", "bthfp.indicator.1",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_indicator[1],
{ "Indicator 2", "bthfp.indicator.2",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_indicator[2],
{ "Indicator 3", "bthfp.indicator.3",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_indicator[3],
{ "Indicator 4", "bthfp.indicator.4",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_indicator[4],
{ "Indicator 5", "bthfp.indicator.5",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_indicator[5],
{ "Indicator 6", "bthfp.indicator.6",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_indicator[6],
{ "Indicator 7", "bthfp.indicator.7",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_indicator[7],
{ "Indicator 8", "bthfp.indicator.8",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_indicator[8],
{ "Indicator 9", "bthfp.indicator.9",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_indicator[9],
{ "Indicator 10", "bthfp.indicator.10",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_indicator[10],
{ "Indicator 11", "bthfp.indicator.11",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_indicator[11],
{ "Indicator 12", "bthfp.indicator.12",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_indicator[12],
{ "Indicator 13", "bthfp.indicator.13",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_indicator[13],
{ "Indicator 14", "bthfp.indicator.14",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_indicator[14],
{ "Indicator 15", "bthfp.indicator.15",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_indicator[15],
{ "Indicator 16", "bthfp.indicator.16",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_indicator[16],
{ "Indicator 17", "bthfp.indicator.17",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_indicator[17],
{ "Indicator 18", "bthfp.indicator.18",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_indicator[18],
{ "Indicator 19", "bthfp.indicator.19",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
},
{ &hf_indicator[19],
{ "Indicator 20", "bthfp.indicator.20",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL}
}
};
static ei_register_info ei[] = {
{ &ei_non_mandatory_command, { "bthfp.expert.non_mandatory_command", PI_PROTOCOL, PI_NOTE, "Non-mandatory command in HFP", EXPFILL }},
{ &ei_invalid_usage, { "bthfp.expert.invalid_usage", PI_PROTOCOL, PI_WARN, "Non mandatory type or command in this role", EXPFILL }},
{ &ei_unknown_parameter, { "bthfp.expert.unknown_parameter", PI_PROTOCOL, PI_WARN, "Unknown parameter", EXPFILL }},
{ &ei_brfs_hs_reserved_bits, { "bthfp.expert.brsf.hs.reserved_bits", PI_PROTOCOL, PI_WARN, "The reserved bits [8-31] shall be initialized to Zero", EXPFILL }},
{ &ei_brfs_ag_reserved_bits, { "bthfp.expert.brsf.ag.reserved_bits", PI_PROTOCOL, PI_WARN, "The reserved bits [10-31] shall be initialized to Zero", EXPFILL }},
{ &ei_vgm_gain, { "bthfp.expert.vgm", PI_PROTOCOL, PI_WARN, "Gain of microphone exceeds range 0-15", EXPFILL }},
{ &ei_vgs_gain, { "bthfp.expert.vgs", PI_PROTOCOL, PI_WARN, "Gain of speaker exceeds range 0-15", EXPFILL }},
{ &ei_nrec, { "bthfp.expert.nrec", PI_PROTOCOL, PI_WARN, "Only 0 is valid", EXPFILL }},
{ &ei_bvra, { "bthfp.expert.bvra", PI_PROTOCOL, PI_WARN, "Only 0-1 is valid", EXPFILL }},
{ &ei_bcs, { "bthfp.expert.bcs", PI_PROTOCOL, PI_NOTE, "Reserved value", EXPFILL }},
{ &ei_bac, { "bthfp.expert.bac", PI_PROTOCOL, PI_NOTE, "Reserved value", EXPFILL }},
{ &ei_bsir, { "bthfp.expert.bsir", PI_PROTOCOL, PI_WARN, "Only 0-1 is valid", EXPFILL }},
{ &ei_btrh, { "bthfp.expert.btrh", PI_PROTOCOL, PI_WARN, "Only 0-2 is valid", EXPFILL }},
{ &ei_binp, { "bthfp.expert.binp", PI_PROTOCOL, PI_WARN, "Only 1 is valid", EXPFILL }},
{ &ei_bia, { "bthfp.expert.bia", PI_PROTOCOL, PI_WARN, "Only 0-1 is valid", EXPFILL }},
{ &ei_biev_assigned_number, { "bthfp.expert.biev.assigned_number", PI_PROTOCOL, PI_WARN, "Only 0-65535 is valid", EXPFILL }},
{ &ei_biev_assigned_number_no, { "bthfp.expert.biev.assigned_number.not_assigned", PI_PROTOCOL, PI_WARN, "Value is unknown for Assign Numbers", EXPFILL }},
{ &ei_cmer_mode, { "bthfp.expert.cmer.mode", PI_PROTOCOL, PI_NOTE, "Only 3 is valid for HFP", EXPFILL }},
{ &ei_cmer_disp, { "bthfp.expert.cmer.disp", PI_PROTOCOL, PI_WARN, "Value is ignored for HFP", EXPFILL }},
{ &ei_cmer_keyp, { "bthfp.expert.cmer.keyp", PI_PROTOCOL, PI_WARN, "Value is ignored for HFP", EXPFILL }},
{ &ei_cmer_ind, { "bthfp.expert.cmer.ind", PI_PROTOCOL, PI_NOTE, "Only 0-1 is valid for HFP", EXPFILL }},
{ &ei_cmer_btr, { "bthfp.expert.cmer.btr", PI_PROTOCOL, PI_WARN, "Value is ignored for HFP", EXPFILL }},
{ &ei_chld_mode, { "bthfp.expert.chld.mode", PI_PROTOCOL, PI_WARN, "Invalid value for HFP", EXPFILL }},
{ &ei_ciev_indicator, { "bthfp.expert.ciev.indicator", PI_PROTOCOL, PI_WARN, "Unknown indicator", EXPFILL }},
{ &ei_vts_dtmf, { "bthfp.expert.vts.dtmf", PI_PROTOCOL, PI_WARN, "DTMF should be single character", EXPFILL }},
{ &ei_at_type, { "bthfp.expert.at.type", PI_PROTOCOL, PI_WARN, "Unknown type value", EXPFILL }},
{ &ei_parameter_blank, { "bthfp.expert.parameter_blank", PI_PROTOCOL, PI_WARN, "Should be blank for HFP", EXPFILL }},
{ &ei_cnum_service, { "bthfp.expert.cnum.service", PI_PROTOCOL, PI_WARN, "Only 0-5 is valid", EXPFILL }},
{ &ei_cnum_itc, { "bthfp.expert.cnum.itc", PI_PROTOCOL, PI_WARN, "Only 0-1 is valid", EXPFILL }},
};
static gint *ett[] = {
&ett_bthfp,
&ett_bthfp_brsf_hf,
&ett_bthfp_brsf_ag,
&ett_bthfp_command,
&ett_bthfp_parameters
};
fragments = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
proto_bthfp = proto_register_protocol("Bluetooth HFP Profile", "BT HFP", "bthfp");
bthfp_handle = register_dissector("bthfp", dissect_bthfp, proto_bthfp);
proto_register_field_array(proto_bthfp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
module = prefs_register_protocol(proto_bthfp, NULL);
prefs_register_static_text_preference(module, "hfp.version",
"Bluetooth Profile HFP version: 1.7",
"Version of profile supported by this dissector.");
prefs_register_enum_preference(module, "hfp.hfp_role",
"Force treat packets as AG or HS role",
"Force treat packets as AG or HS role",
&hfp_role, pref_hfp_role, TRUE);
expert_bthfp = expert_register_protocol(proto_bthfp);
expert_register_field_array(expert_bthfp, ei, array_length(ei));
}
void
proto_reg_handoff_bthfp(void)
{
dissector_add_string("bluetooth.uuid", "111e", bthfp_handle);
dissector_add_string("bluetooth.uuid", "111f", bthfp_handle);
dissector_add_for_decode_as("btrfcomm.dlci", bthfp_handle);
}
