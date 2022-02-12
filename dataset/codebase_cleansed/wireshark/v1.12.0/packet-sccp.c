static gboolean
sccp_called_calling_looks_valid(guint32 frame_num _U_, tvbuff_t *tvb, guint8 my_mtp3_standard, gboolean is_co)
{
guint8 ai, ri, gti, ssni, pci;
guint8 len_needed = 1;
guint len = tvb_length(tvb);
ai = tvb_get_guint8(tvb, 0);
if ((my_mtp3_standard == ANSI_STANDARD) && ((ai & ANSI_NATIONAL_MASK) == 0))
RETURN_FALSE;
gti = (ai & GTI_MASK) >> GTI_SHIFT;
if (my_mtp3_standard == ANSI_STANDARD) {
if (gti > 2)
RETURN_FALSE;
} else {
if (gti > 4)
RETURN_FALSE;
}
ri = (ai & ROUTING_INDICATOR_MASK) >> ROUTING_INDICATOR_SHIFT;
if (my_mtp3_standard == ANSI_STANDARD) {
pci = ai & ANSI_PC_INDICATOR_MASK;
ssni = ai & ANSI_SSN_INDICATOR_MASK;
} else {
ssni = ai & ITU_SSN_INDICATOR_MASK;
pci = ai & ITU_PC_INDICATOR_MASK;
}
if ((ri == ROUTE_ON_SSN) && (ssni == 0))
RETURN_FALSE;
if ((ri == ROUTE_ON_GT) && (gti == AI_GTI_NO_GT))
RETURN_FALSE;
if ((ri == ROUTE_ON_GT) && is_co)
RETURN_FALSE;
if (ssni)
len_needed += ADDRESS_SSN_LENGTH;
if (pci) {
if (my_mtp3_standard == ANSI_STANDARD ||
my_mtp3_standard == CHINESE_ITU_STANDARD)
len_needed += ANSI_PC_LENGTH;
else
len_needed += ITU_PC_LENGTH;
}
if (gti)
len_needed += 2;
if (len_needed > len)
RETURN_FALSE;
return TRUE;
}
gboolean
looks_like_valid_sccp(guint32 frame_num _U_, tvbuff_t *tvb, guint8 my_mtp3_standard)
{
guint offset;
guint8 msgtype, msg_class, cause;
guint called_ptr = 0;
guint calling_ptr = 0;
guint data_ptr = 0;
guint opt_ptr = 0;
guint8 pointer_length = POINTER_LENGTH;
guint len = tvb_length(tvb);
if (len < 5)
RETURN_FALSE;
msgtype = tvb_get_guint8(tvb, SCCP_MSG_TYPE_OFFSET);
if (!try_val_to_str(msgtype, sccp_message_type_acro_values)) {
RETURN_FALSE;
}
offset = SCCP_MSG_TYPE_LENGTH;
switch (msgtype) {
case SCCP_MSG_TYPE_UDT:
case SCCP_MSG_TYPE_XUDT:
case SCCP_MSG_TYPE_LUDT:
case SCCP_MSG_TYPE_UDTS:
case SCCP_MSG_TYPE_XUDTS:
case SCCP_MSG_TYPE_LUDTS:
{
if (msgtype == SCCP_MSG_TYPE_XUDT || msgtype == SCCP_MSG_TYPE_XUDTS) {
if (SCCP_MSG_TYPE_LENGTH +
PROTOCOL_CLASS_LENGTH +
HOP_COUNTER_LENGTH +
POINTER_LENGTH +
POINTER_LENGTH +
POINTER_LENGTH +
POINTER_LENGTH > len)
RETURN_FALSE;
}
if (msgtype == SCCP_MSG_TYPE_LUDT || msgtype == SCCP_MSG_TYPE_LUDTS) {
if (SCCP_MSG_TYPE_LENGTH +
PROTOCOL_CLASS_LENGTH +
HOP_COUNTER_LENGTH +
POINTER_LENGTH_LONG +
POINTER_LENGTH_LONG +
POINTER_LENGTH_LONG +
POINTER_LENGTH_LONG > len)
RETURN_FALSE;
pointer_length = POINTER_LENGTH_LONG;
}
if (msgtype == SCCP_MSG_TYPE_UDT || msgtype == SCCP_MSG_TYPE_XUDT ||
msgtype == SCCP_MSG_TYPE_LUDT) {
msg_class = tvb_get_guint8(tvb, offset) & CLASS_CLASS_MASK;
if (msg_class > 1)
RETURN_FALSE;
offset += PROTOCOL_CLASS_LENGTH;
}
if (msgtype == SCCP_MSG_TYPE_XUDT || msgtype == SCCP_MSG_TYPE_LUDT)
offset += HOP_COUNTER_LENGTH;
if (msgtype == SCCP_MSG_TYPE_UDTS ||
msgtype == SCCP_MSG_TYPE_XUDTS ||
msgtype == SCCP_MSG_TYPE_LUDTS) {
cause = tvb_get_guint8(tvb, offset);
if (!try_val_to_str(cause, sccp_return_cause_values))
RETURN_FALSE;
offset += RETURN_CAUSE_LENGTH;
}
if (msgtype == SCCP_MSG_TYPE_XUDTS || msgtype == SCCP_MSG_TYPE_LUDTS)
offset += HOP_COUNTER_LENGTH;
if (msgtype == SCCP_MSG_TYPE_LUDT || msgtype == SCCP_MSG_TYPE_LUDTS)
called_ptr = tvb_get_letohs(tvb, offset);
else
called_ptr = tvb_get_guint8(tvb, offset);
if (called_ptr == 0)
RETURN_FALSE;
called_ptr += offset;
offset += pointer_length;
if (msgtype == SCCP_MSG_TYPE_LUDT || msgtype == SCCP_MSG_TYPE_LUDTS)
calling_ptr = tvb_get_letohs(tvb, offset);
else
calling_ptr = tvb_get_guint8(tvb, offset);
if (calling_ptr == 0)
RETURN_FALSE;
calling_ptr += offset;
offset += pointer_length;
if (msgtype == SCCP_MSG_TYPE_LUDT || msgtype == SCCP_MSG_TYPE_LUDTS)
data_ptr = tvb_get_letohs(tvb, offset);
else
data_ptr = tvb_get_guint8(tvb, offset);
if (data_ptr == 0)
RETURN_FALSE;
data_ptr += offset;
offset += pointer_length;
if (msgtype == SCCP_MSG_TYPE_XUDT || msgtype == SCCP_MSG_TYPE_XUDTS) {
opt_ptr = tvb_get_guint8(tvb, offset);
offset += POINTER_LENGTH;
} else if (msgtype == SCCP_MSG_TYPE_LUDT || msgtype == SCCP_MSG_TYPE_LUDTS) {
opt_ptr = tvb_get_letohs(tvb, offset);
offset += POINTER_LENGTH_LONG;
}
if (msgtype == SCCP_MSG_TYPE_LUDT || msgtype == SCCP_MSG_TYPE_LUDTS) {
called_ptr += 1;
calling_ptr += 1;
data_ptr += 1;
if (opt_ptr)
opt_ptr += 1;
}
if (called_ptr > len || calling_ptr > len || data_ptr > len)
RETURN_FALSE;
if (tvb_get_guint8(tvb, called_ptr)+called_ptr > len ||
tvb_get_guint8(tvb, calling_ptr)+calling_ptr > len)
RETURN_FALSE;
if (msgtype == SCCP_MSG_TYPE_LUDT || msgtype == SCCP_MSG_TYPE_LUDTS) {
if (tvb_get_letohs(tvb, data_ptr)+data_ptr > len)
RETURN_FALSE;
} else {
if (tvb_get_guint8(tvb, data_ptr)+data_ptr > len)
RETURN_FALSE;
}
}
break;
case SCCP_MSG_TYPE_CR:
{
if (len < SCCP_MSG_TYPE_LENGTH
+ DESTINATION_LOCAL_REFERENCE_LENGTH
+ PROTOCOL_CLASS_LENGTH
+ POINTER_LENGTH
+ POINTER_LENGTH)
RETURN_FALSE;
offset += DESTINATION_LOCAL_REFERENCE_LENGTH;
msg_class = tvb_get_guint8(tvb, offset);
if (msg_class != 2)
RETURN_FALSE;
offset += PROTOCOL_CLASS_LENGTH;
data_ptr = tvb_get_guint8(tvb, offset);
if (data_ptr == 0)
RETURN_FALSE;
offset += POINTER_LENGTH;
opt_ptr = tvb_get_guint8(tvb, offset);
if (opt_ptr == 0)
RETURN_FALSE;
offset += POINTER_LENGTH;
}
break;
case SCCP_MSG_TYPE_CC:
{
if (len < SCCP_MSG_TYPE_LENGTH
+ DESTINATION_LOCAL_REFERENCE_LENGTH
+ SOURCE_LOCAL_REFERENCE_LENGTH
+ PROTOCOL_CLASS_LENGTH
+ POINTER_LENGTH)
RETURN_FALSE;
offset += DESTINATION_LOCAL_REFERENCE_LENGTH;
offset += SOURCE_LOCAL_REFERENCE_LENGTH;
msg_class = tvb_get_guint8(tvb, offset);
if (msg_class != 2)
RETURN_FALSE;
offset += PROTOCOL_CLASS_LENGTH;
opt_ptr = tvb_get_guint8(tvb, offset);
offset += POINTER_LENGTH;
if (opt_ptr > 1)
RETURN_FALSE;
if ((opt_ptr == 0) && (offset != len))
RETURN_FALSE;
}
break;
case SCCP_MSG_TYPE_CREF:
{
if (len < SCCP_MSG_TYPE_LENGTH
+ DESTINATION_LOCAL_REFERENCE_LENGTH
+ REFUSAL_CAUSE_LENGTH
+ POINTER_LENGTH)
RETURN_FALSE;
offset += DESTINATION_LOCAL_REFERENCE_LENGTH;
cause = tvb_get_guint8(tvb, offset);
if (!try_val_to_str(cause, sccp_refusal_cause_values))
RETURN_FALSE;
offset += REFUSAL_CAUSE_LENGTH;
opt_ptr = tvb_get_guint8(tvb, offset);
offset += POINTER_LENGTH;
if (opt_ptr > 1)
RETURN_FALSE;
if ((opt_ptr == 0) && (offset != len))
RETURN_FALSE;
}
break;
case SCCP_MSG_TYPE_RLSD:
{
if (len < SCCP_MSG_TYPE_LENGTH
+ DESTINATION_LOCAL_REFERENCE_LENGTH
+ SOURCE_LOCAL_REFERENCE_LENGTH
+ RELEASE_CAUSE_LENGTH
+ POINTER_LENGTH)
RETURN_FALSE;
offset += DESTINATION_LOCAL_REFERENCE_LENGTH;
offset += SOURCE_LOCAL_REFERENCE_LENGTH;
cause = tvb_get_guint8(tvb, offset);
if (!try_val_to_str(cause, sccp_release_cause_values))
RETURN_FALSE;
offset += RELEASE_CAUSE_LENGTH;
opt_ptr = tvb_get_guint8(tvb, offset);
offset += POINTER_LENGTH;
if (opt_ptr > 1)
RETURN_FALSE;
if ((opt_ptr == 0) && (offset != len))
RETURN_FALSE;
}
break;
case SCCP_MSG_TYPE_RLC:
{
if (len != SCCP_MSG_TYPE_LENGTH
+ DESTINATION_LOCAL_REFERENCE_LENGTH
+ SOURCE_LOCAL_REFERENCE_LENGTH)
RETURN_FALSE;
}
break;
case SCCP_MSG_TYPE_ERR:
{
if (len != SCCP_MSG_TYPE_LENGTH
+ DESTINATION_LOCAL_REFERENCE_LENGTH
+ ERROR_CAUSE_LENGTH)
RETURN_FALSE;
offset += DESTINATION_LOCAL_REFERENCE_LENGTH;
cause = tvb_get_guint8(tvb, offset);
if (!try_val_to_str(cause, sccp_error_cause_values))
RETURN_FALSE;
}
break;
case SCCP_MSG_TYPE_DT1:
{
if (len < SCCP_MSG_TYPE_LENGTH
+ DESTINATION_LOCAL_REFERENCE_LENGTH
+ SEGMENTING_REASSEMBLING_LENGTH
+ POINTER_LENGTH
+ PARAMETER_LENGTH_LENGTH
+ 1)
RETURN_FALSE;
offset += DESTINATION_LOCAL_REFERENCE_LENGTH;
if (tvb_get_guint8(tvb, offset) & ~SEGMENTING_REASSEMBLING_MASK)
RETURN_FALSE;
offset += SEGMENTING_REASSEMBLING_LENGTH;
data_ptr = tvb_get_guint8(tvb, offset) + offset;
if (data_ptr > len)
RETURN_FALSE;
offset += POINTER_LENGTH;
if (tvb_get_guint8(tvb, data_ptr) + offset + 1U != len)
RETURN_FALSE;
}
break;
case SCCP_MSG_TYPE_IT:
{
if (len < SCCP_MSG_TYPE_LENGTH
+ DESTINATION_LOCAL_REFERENCE_LENGTH
+ SOURCE_LOCAL_REFERENCE_LENGTH
+ PROTOCOL_CLASS_LENGTH
+ SEQUENCING_SEGMENTING_LENGTH
+ CREDIT_LENGTH)
RETURN_FALSE;
offset += DESTINATION_LOCAL_REFERENCE_LENGTH;
offset += SOURCE_LOCAL_REFERENCE_LENGTH;
msg_class = tvb_get_guint8(tvb, offset);
if (msg_class != 2)
RETURN_FALSE;
offset += PROTOCOL_CLASS_LENGTH;
}
break;
case SCCP_MSG_TYPE_AK:
case SCCP_MSG_TYPE_DT2:
case SCCP_MSG_TYPE_EA:
case SCCP_MSG_TYPE_ED:
case SCCP_MSG_TYPE_RSC:
case SCCP_MSG_TYPE_RSR:
RETURN_FALSE;
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
if (called_ptr) {
guint8 param_len = tvb_get_guint8(tvb, called_ptr);
tvbuff_t *param_tvb;
if (param_len == 0)
RETURN_FALSE;
param_tvb = tvb_new_subset(tvb, called_ptr+1, param_len, param_len);
if (!sccp_called_calling_looks_valid(frame_num, param_tvb, my_mtp3_standard, !is_connectionless(msgtype)))
RETURN_FALSE;
}
if (calling_ptr) {
guint8 param_len = tvb_get_guint8(tvb, calling_ptr);
tvbuff_t *param_tvb;
if (param_len == 0)
RETURN_FALSE;
param_tvb = tvb_new_subset(tvb, calling_ptr+1, param_len, param_len);
if (!sccp_called_calling_looks_valid(frame_num, param_tvb, my_mtp3_standard, !is_connectionless(msgtype)))
RETURN_FALSE;
}
if (opt_ptr) {
guint8 opt_param;
opt_ptr += offset-pointer_length;
if (opt_ptr > len)
RETURN_FALSE;
opt_param = tvb_get_guint8(tvb, opt_ptr);
if (!try_val_to_str(opt_param, sccp_parameter_values))
RETURN_FALSE;
if ((opt_param != PARAMETER_END_OF_OPTIONAL_PARAMETERS) &&
((opt_ptr+1U) <= len) &&
((tvb_get_guint8(tvb, opt_ptr+1U)+offset) > len))
RETURN_FALSE;
if ((opt_param == PARAMETER_END_OF_OPTIONAL_PARAMETERS) && ((opt_ptr+1U) != len))
RETURN_FALSE;
}
return TRUE;
}
static sccp_assoc_info_t *
new_assoc(guint32 calling, guint32 called)
{
sccp_assoc_info_t *a = wmem_new0(wmem_file_scope(), sccp_assoc_info_t);
a->id = next_assoc_id++;
a->calling_dpc = calling;
a->called_dpc = called;
a->calling_ssn = INVALID_SSN;
a->called_ssn = INVALID_SSN;
a->msgs = NULL;
a->curr_msg = NULL;
a->payload = SCCP_PLOAD_NONE;
a->calling_party = NULL;
a->called_party = NULL;
a->extra_info = NULL;
return a;
}
void
reset_sccp_assoc(void)
{
assoc = NULL;
}
sccp_assoc_info_t *
get_sccp_assoc(packet_info *pinfo, guint offset, guint32 src_lr, guint32 dst_lr, guint msg_type)
{
guint32 opck, dpck;
address *opc = &(pinfo->src);
address *dpc = &(pinfo->dst);
guint framenum = PINFO_FD_NUM(pinfo);
if (assoc)
return assoc;
opck = opc->type == AT_SS7PC ? mtp3_pc_hash((const mtp3_addr_pc_t *)opc->data) : g_str_hash(address_to_str(wmem_packet_scope(), opc));
dpck = dpc->type == AT_SS7PC ? mtp3_pc_hash((const mtp3_addr_pc_t *)dpc->data) : g_str_hash(address_to_str(wmem_packet_scope(), dpc));
switch (msg_type) {
case SCCP_MSG_TYPE_CR:
{
wmem_tree_key_t bw_key[4];
bw_key[0].length = 1;
bw_key[0].key = &dpck;
bw_key[1].length = 1;
bw_key[1].key = &opck;
bw_key[2].length = 1;
bw_key[2].key = &src_lr;
bw_key[3].length = 0;
bw_key[3].key = NULL;
if (! ( assoc = (sccp_assoc_info_t *)wmem_tree_lookup32_array(assocs, bw_key) ) && ! PINFO_FD_VISITED(pinfo) ) {
assoc = new_assoc(opck, dpck);
wmem_tree_insert32_array(assocs, bw_key, assoc);
assoc->has_bw_key = TRUE;
}
pinfo->p2p_dir = P2P_DIR_SENT;
break;
}
case SCCP_MSG_TYPE_CC:
{
wmem_tree_key_t fw_key[4];
wmem_tree_key_t bw_key[4];
fw_key[0].length = 1;
fw_key[0].key = &dpck;
fw_key[1].length = 1;
fw_key[1].key = &opck;
fw_key[2].length = 1;
fw_key[2].key = &src_lr;
fw_key[3].length = 0;
fw_key[3].key = NULL;
bw_key[0].length = 1;
bw_key[0].key = &opck;
bw_key[1].length = 1;
bw_key[1].key = &dpck;
bw_key[2].length = 1;
bw_key[2].key = &dst_lr;
bw_key[3].length = 0;
bw_key[3].key = NULL;
if ( ( assoc = (sccp_assoc_info_t *)wmem_tree_lookup32_array(assocs, bw_key) ) ) {
goto got_assoc;
}
if ( (assoc = (sccp_assoc_info_t *)wmem_tree_lookup32_array(assocs, fw_key) ) ) {
goto got_assoc;
}
assoc = new_assoc(dpck, opck);
got_assoc:
pinfo->p2p_dir = P2P_DIR_RECV;
if ( ! PINFO_FD_VISITED(pinfo) && ! assoc->has_bw_key ) {
wmem_tree_insert32_array(assocs, bw_key, assoc);
assoc->has_bw_key = TRUE;
}
if ( ! PINFO_FD_VISITED(pinfo) && ! assoc->has_fw_key ) {
wmem_tree_insert32_array(assocs, fw_key, assoc);
assoc->has_fw_key = TRUE;
}
break;
}
case SCCP_MSG_TYPE_RLC:
{
wmem_tree_key_t fw_key[4];
wmem_tree_key_t bw_key[4];
fw_key[0].length = 1;
fw_key[0].key = &dpck;
fw_key[1].length = 1;
fw_key[1].key = &opck;
fw_key[2].length = 1;
fw_key[2].key = &src_lr;
fw_key[3].length = 0;
fw_key[3].key = NULL;
bw_key[0].length = 1;
bw_key[0].key = &opck;
bw_key[1].length = 1;
bw_key[1].key = &dpck;
bw_key[2].length = 1;
bw_key[2].key = &dst_lr;
bw_key[3].length = 0;
bw_key[3].key = NULL;
if ( ( assoc = (sccp_assoc_info_t *)wmem_tree_lookup32_array(assocs, bw_key) ) ) {
goto got_assoc_rlc;
}
if ( (assoc = (sccp_assoc_info_t *)wmem_tree_lookup32_array(assocs, fw_key) ) ) {
goto got_assoc_rlc;
}
assoc = new_assoc(dpck, opck);
got_assoc_rlc:
pinfo->p2p_dir = P2P_DIR_SENT;
if ( ! PINFO_FD_VISITED(pinfo) && ! assoc->has_bw_key ) {
wmem_tree_insert32_array(assocs, bw_key, assoc);
assoc->has_bw_key = TRUE;
}
if ( ! PINFO_FD_VISITED(pinfo) && ! assoc->has_fw_key ) {
wmem_tree_insert32_array(assocs, fw_key, assoc);
assoc->has_fw_key = TRUE;
}
break;
}
default:
{
wmem_tree_key_t key[4];
key[0].length = 1;
key[0].key = &opck;
key[1].length = 1;
key[1].key = &dpck;
key[2].length = 1;
key[2].key = &dst_lr;
key[3].length = 0;
key[3].key = NULL;
assoc = (sccp_assoc_info_t *)wmem_tree_lookup32_array(assocs, key);
if (assoc) {
if (assoc->calling_dpc == dpck) {
pinfo->p2p_dir = P2P_DIR_RECV;
} else {
pinfo->p2p_dir = P2P_DIR_SENT;
}
}
break;
}
}
if (assoc && trace_sccp) {
if ( ! PINFO_FD_VISITED(pinfo)) {
sccp_msg_info_t *msg = wmem_new0(wmem_file_scope(), sccp_msg_info_t);
msg->framenum = framenum;
msg->offset = offset;
msg->data.co.next = NULL;
msg->data.co.assoc = assoc;
msg->data.co.label = NULL;
msg->data.co.comment = NULL;
msg->type = msg_type;
if (assoc->msgs) {
sccp_msg_info_t *m;
for (m = assoc->msgs; m->data.co.next; m = m->data.co.next) ;
m->data.co.next = msg;
} else {
assoc->msgs = msg;
}
assoc->curr_msg = msg;
} else {
sccp_msg_info_t *m;
for (m = assoc->msgs; m; m = m->data.co.next) {
if ((m->framenum == framenum) && (m->offset == offset)) {
assoc->curr_msg = m;
break;
}
}
}
}
return assoc ? assoc : &no_assoc;
}
static void
dissect_sccp_unknown_message(tvbuff_t *message_tvb, proto_tree *sccp_tree)
{
guint32 message_length;
message_length = tvb_length(message_tvb);
proto_tree_add_text(sccp_tree, message_tvb, 0, message_length,
"Unknown message (%u byte%s)",
message_length, plurality(message_length, "", "s"));
}
static void
dissect_sccp_unknown_param(tvbuff_t *tvb, proto_tree *tree, guint8 type, guint length)
{
proto_tree_add_text(tree, tvb, 0, length, "Unknown parameter 0x%x (%u byte%s)",
type, length, plurality(length, "", "s"));
}
static void
dissect_sccp_dlr_param(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint length)
{
proto_item *lr_item;
if (length != 3) {
proto_tree_add_expert_format(tree, pinfo, &ei_sccp_wrong_length, tvb, 0, length,
"Wrong length indicated. Expected 3, got %u", length);
return;
}
dlr = tvb_get_letoh24(tvb, 0);
proto_tree_add_uint(tree, hf_sccp_dlr, tvb, 0, length, dlr);
lr_item = proto_tree_add_uint(tree, hf_sccp_lr, tvb, 0, length, dlr);
PROTO_ITEM_SET_HIDDEN(lr_item);
if (show_key_params)
col_append_fstr(pinfo->cinfo, COL_INFO, "DLR=%d ", dlr);
}
static void
dissect_sccp_slr_param(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint length)
{
proto_item *lr_item;
if (length != 3) {
proto_tree_add_expert_format(tree, pinfo, &ei_sccp_wrong_length, tvb, 0, length,
"Wrong length indicated. Expected 3, got %u", length);
return;
}
slr = tvb_get_letoh24(tvb, 0);
proto_tree_add_uint(tree, hf_sccp_slr, tvb, 0, length, slr);
lr_item = proto_tree_add_uint(tree, hf_sccp_lr, tvb, 0, length, slr);
PROTO_ITEM_SET_HIDDEN(lr_item);
if (show_key_params)
col_append_fstr(pinfo->cinfo, COL_INFO, "SLR=%d ", slr);
}
static proto_tree *
dissect_sccp_gt_address_information(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, guint length,
gboolean even_length, gboolean called,
gboolean route_on_gt)
{
guint offset = 0;
guint8 odd_signal, even_signal;
proto_item *digits_item;
proto_tree *digits_tree;
char *gt_digits;
gt_digits = (char *)wmem_alloc0(wmem_packet_scope(), GT_MAX_SIGNALS+1);
while (offset < length) {
odd_signal = tvb_get_guint8(tvb, offset) & GT_ODD_SIGNAL_MASK;
even_signal = tvb_get_guint8(tvb, offset) & GT_EVEN_SIGNAL_MASK;
even_signal >>= GT_EVEN_SIGNAL_SHIFT;
g_strlcat(gt_digits, val_to_str(odd_signal, sccp_address_signal_values,
"Unknown: %d"), GT_MAX_SIGNALS+1);
if (offset != (length - 1) || even_length == TRUE)
g_strlcat(gt_digits, val_to_str(even_signal, sccp_address_signal_values,
"Unknown: %d"), GT_MAX_SIGNALS+1);
offset += GT_SIGNAL_LENGTH;
}
if (is_connectionless(message_type) && sccp_msg) {
guint8 **gt_ptr = called ? &(sccp_msg->data.ud.called_gt) : &(sccp_msg->data.ud.calling_gt);
*gt_ptr = (guint8 *)wmem_strdup(wmem_packet_scope(), gt_digits);
}
digits_item = proto_tree_add_string(tree, called ? hf_sccp_called_gt_digits
: hf_sccp_calling_gt_digits,
tvb, 0, length, gt_digits);
digits_tree = proto_item_add_subtree(digits_item, called ? ett_sccp_called_gt_digits
: ett_sccp_calling_gt_digits);
if (set_addresses && route_on_gt) {
if (called) {
SET_ADDRESS(&pinfo->dst, AT_STRINGZ, 1+(int)strlen(gt_digits), gt_digits);
} else {
SET_ADDRESS(&pinfo->src, AT_STRINGZ, 1+(int)strlen(gt_digits), gt_digits);
}
}
proto_tree_add_string(digits_tree, hf_sccp_gt_digits, tvb, 0, length, gt_digits);
proto_tree_add_uint(digits_tree, called ? hf_sccp_called_gt_digits_length
: hf_sccp_calling_gt_digits_length,
tvb, 0, length, (guint32)strlen(gt_digits));
return digits_tree;
}
static void
dissect_sccp_global_title(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint length,
guint8 gti, gboolean route_on_gt, gboolean called)
{
proto_item *gt_item;
proto_tree *gt_tree;
proto_tree *digits_tree;
tvbuff_t *signals_tvb;
guint offset = 0;
guint8 odd_even, nai = 0, np = 0, es;
gboolean even = TRUE;
gti >>= GTI_SHIFT;
gt_item = proto_tree_add_text(tree, tvb, offset, length,
"Global Title 0x%x (%u byte%s)",
gti, length, plurality(length,"", "s"));
gt_tree = proto_item_add_subtree(gt_item, called ? ett_sccp_called_gt
: ett_sccp_calling_gt);
if ((gti == AI_GTI_TT) ||
((decode_mtp3_standard != ANSI_STANDARD) &&
((gti == ITU_AI_GTI_TT_NP_ES) || (gti == ITU_AI_GTI_TT_NP_ES_NAI))) ||
((decode_mtp3_standard == ANSI_STANDARD) && (gti == ANSI_AI_GTI_TT_NP_ES))) {
proto_tree_add_item(gt_tree, called ? hf_sccp_called_gt_tt
: hf_sccp_calling_gt_tt,
tvb, offset, GT_TT_LENGTH, ENC_NA);
offset += GT_TT_LENGTH;
}
if (gti == AI_GTI_TT) {
even = TRUE;
}
if (((decode_mtp3_standard != ANSI_STANDARD) &&
((gti == ITU_AI_GTI_TT_NP_ES) || (gti == ITU_AI_GTI_TT_NP_ES_NAI))) ||
((decode_mtp3_standard == ANSI_STANDARD) && (gti == ANSI_AI_GTI_TT_NP_ES))) {
np = tvb_get_guint8(tvb, offset) & GT_NP_MASK;
proto_tree_add_uint(gt_tree, called ? hf_sccp_called_gt_np
: hf_sccp_calling_gt_np,
tvb, offset, GT_NP_ES_LENGTH, np);
es = tvb_get_guint8(tvb, offset) & GT_ES_MASK;
proto_tree_add_uint(gt_tree, called ? hf_sccp_called_gt_es
: hf_sccp_calling_gt_es,
tvb, offset, GT_NP_ES_LENGTH, es);
even = (es == GT_ES_BCD_EVEN) ? TRUE : FALSE;
offset += GT_NP_ES_LENGTH;
}
if ((decode_mtp3_standard != ANSI_STANDARD) &&
((gti == ITU_AI_GTI_NAI) || (gti == ITU_AI_GTI_TT_NP_ES_NAI))) {
if (gti == ITU_AI_GTI_NAI) {
odd_even = tvb_get_guint8(tvb, offset) & GT_OE_MASK;
proto_tree_add_uint(gt_tree, called ? hf_sccp_called_gt_oe
: hf_sccp_calling_gt_oe,
tvb, offset, GT_NAI_LENGTH, odd_even);
even = (odd_even == GT_OE_EVEN) ? TRUE : FALSE;
}
nai = tvb_get_guint8(tvb, offset) & GT_NAI_MASK;
proto_tree_add_uint(gt_tree, called ? hf_sccp_called_gt_nai
: hf_sccp_calling_gt_nai,
tvb, offset, GT_NAI_LENGTH, nai);
offset += GT_NAI_LENGTH;
}
if(length == 0){
expert_add_info(pinfo, gt_item, &ei_sccp_gt_digits_missing);
return;
}
if (length < offset)
return;
signals_tvb = tvb_new_subset(tvb, offset, (length - offset),
(length - offset));
digits_tree = dissect_sccp_gt_address_information(signals_tvb, pinfo, gt_tree,
(length - offset),
even, called, route_on_gt);
switch (np >> GT_NP_SHIFT) {
case GT_NP_ISDN:
case GT_NP_ISDN_MOBILE:
if (nai == GT_NAI_INTERNATIONAL_NUM) {
dissect_e164_cc(signals_tvb, digits_tree, 0, TRUE);
}
break;
case GT_NP_LAND_MOBILE:
dissect_e212_mcc_mnc_in_address(signals_tvb, pinfo, digits_tree, 0);
break;
default:
break;
}
}
static int
dissect_sccp_3byte_pc(tvbuff_t *tvb, proto_tree *call_tree, guint offset,
gboolean called)
{
int hf_pc;
if (decode_mtp3_standard == ANSI_STANDARD)
{
if (called)
hf_pc = hf_sccp_called_ansi_pc;
else
hf_pc = hf_sccp_calling_ansi_pc;
} else {
if (called)
hf_pc = hf_sccp_called_chinese_pc;
else
hf_pc = hf_sccp_calling_chinese_pc;
}
dissect_mtp3_3byte_pc(tvb, offset, call_tree,
called ? ett_sccp_called_pc : ett_sccp_calling_pc,
hf_pc,
called ? hf_sccp_called_pc_network : hf_sccp_calling_pc_network,
called ? hf_sccp_called_pc_cluster : hf_sccp_calling_pc_cluster,
called ? hf_sccp_called_pc_member : hf_sccp_calling_pc_member,
0, 0);
return(offset + ANSI_PC_LENGTH);
}
static void
dissect_sccp_called_calling_param(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo,
guint length, gboolean called)
{
proto_item *call_item = 0, *call_ai_item = 0, *item, *hidden_item, *expert_item;
proto_tree *call_tree = 0, *call_ai_tree = 0;
guint offset;
guint8 national = 0xFFU, routing_ind, gti, pci, ssni, ssn;
tvbuff_t *gt_tvb;
dissector_handle_t ssn_dissector = NULL, tcap_ssn_dissector = NULL;
const char *ssn_dissector_short_name = NULL;
const char *tcap_ssn_dissector_short_name = NULL;
call_item = proto_tree_add_text(tree, tvb, 0, length,
"%s Party address (%u byte%s)",
called ? "Called" : "Calling", length,
plurality(length, "", "s"));
call_tree = proto_item_add_subtree(call_item, called ? ett_sccp_called : ett_sccp_calling);
call_ai_item = proto_tree_add_text(call_tree, tvb, 0,
ADDRESS_INDICATOR_LENGTH,
"Address Indicator");
call_ai_tree = proto_item_add_subtree(call_ai_item, called ? ett_sccp_called_ai : ett_sccp_calling_ai);
if (decode_mtp3_standard == ANSI_STANDARD) {
national = tvb_get_guint8(tvb, 0) & ANSI_NATIONAL_MASK;
expert_item = proto_tree_add_uint(call_ai_tree, called ? hf_sccp_called_ansi_national_indicator
: hf_sccp_calling_ansi_national_indicator,
tvb, 0, ADDRESS_INDICATOR_LENGTH, national);
if (national == 0)
expert_add_info(pinfo, expert_item, &ei_sccp_international_standard_address);
} else {
guint8 natl_use_bit = tvb_get_guint8(tvb, 0) & ITU_RESERVED_MASK;
proto_tree_add_uint(call_ai_tree, called ? hf_sccp_called_itu_natl_use_bit
: hf_sccp_calling_itu_natl_use_bit,
tvb, 0, ADDRESS_INDICATOR_LENGTH, natl_use_bit);
}
routing_ind = tvb_get_guint8(tvb, 0) & ROUTING_INDICATOR_MASK;
proto_tree_add_uint(call_ai_tree, called ? hf_sccp_called_routing_indicator : hf_sccp_calling_routing_indicator,
tvb, 0, ADDRESS_INDICATOR_LENGTH, routing_ind);
routing_ind >>= ROUTING_INDICATOR_SHIFT;
gti = tvb_get_guint8(tvb, 0) & GTI_MASK;
if (decode_mtp3_standard == ITU_STANDARD ||
decode_mtp3_standard == CHINESE_ITU_STANDARD ||
decode_mtp3_standard == JAPAN_STANDARD ||
national == 0) {
proto_tree_add_uint(call_ai_tree,
called ? hf_sccp_called_itu_global_title_indicator : hf_sccp_calling_itu_global_title_indicator,
tvb, 0, ADDRESS_INDICATOR_LENGTH, gti);
ssni = tvb_get_guint8(tvb, 0) & ITU_SSN_INDICATOR_MASK;
expert_item = proto_tree_add_uint(call_ai_tree,
called ? hf_sccp_called_itu_ssn_indicator : hf_sccp_calling_itu_ssn_indicator,
tvb, 0, ADDRESS_INDICATOR_LENGTH, ssni);
if ((routing_ind == ROUTE_ON_SSN) && (ssni == 0)) {
expert_add_info(pinfo, expert_item, &ei_sccp_no_ssn_present);
}
pci = tvb_get_guint8(tvb, 0) & ITU_PC_INDICATOR_MASK;
proto_tree_add_uint(call_ai_tree, called ? hf_sccp_called_itu_point_code_indicator : hf_sccp_calling_itu_point_code_indicator,
tvb, 0, ADDRESS_INDICATOR_LENGTH, pci);
offset = ADDRESS_INDICATOR_LENGTH;
if (pci) {
if (decode_mtp3_standard == ITU_STANDARD || national == 0) {
if (length < offset + ITU_PC_LENGTH) {
proto_tree_add_expert_format(call_tree, pinfo, &ei_sccp_wrong_length, tvb, 0, -1,
"Wrong length indicated (%u) should be at least %u, PC is %u octets",
length, offset + ITU_PC_LENGTH, ITU_PC_LENGTH);
return;
}
proto_tree_add_item(call_tree, called ? hf_sccp_called_itu_pc : hf_sccp_calling_itu_pc,
tvb, offset, ITU_PC_LENGTH, ENC_LITTLE_ENDIAN);
offset += ITU_PC_LENGTH;
} else if (decode_mtp3_standard == JAPAN_STANDARD) {
if (length < offset + JAPAN_PC_LENGTH) {
proto_tree_add_expert_format(call_tree, pinfo, &ei_sccp_wrong_length, tvb, 0, -1,
"Wrong length indicated (%u) should be at least %u, PC is %u octets",
length, offset + JAPAN_PC_LENGTH, JAPAN_PC_LENGTH);
return;
}
proto_tree_add_item(call_tree, called ? hf_sccp_called_japan_pc : hf_sccp_calling_japan_pc,
tvb, offset, JAPAN_PC_LENGTH, ENC_LITTLE_ENDIAN);
offset += JAPAN_PC_LENGTH;
} else {
if (length < offset + ANSI_PC_LENGTH) {
proto_tree_add_expert_format(call_tree, pinfo, &ei_sccp_wrong_length, tvb, 0, -1,
"Wrong length indicated (%u) should be at least %u, PC is %u octets",
length, offset + ANSI_PC_LENGTH, ANSI_PC_LENGTH);
return;
}
offset = dissect_sccp_3byte_pc(tvb, call_tree, offset, called);
}
}
if (ssni) {
ssn = tvb_get_guint8(tvb, offset);
if ((routing_ind == ROUTE_ON_SSN) && (ssn == 0)) {
expert_add_info(pinfo, expert_item, &ei_sccp_ssn_zero);
}
if (called && assoc)
assoc->called_ssn = ssn;
else if (assoc)
assoc->calling_ssn = ssn;
if (is_connectionless(message_type) && sccp_msg) {
guint *ssn_ptr = called ? &(sccp_msg->data.ud.called_ssn) : &(sccp_msg->data.ud.calling_ssn);
*ssn_ptr = ssn;
}
proto_tree_add_uint(call_tree, called ? hf_sccp_called_ssn
: hf_sccp_calling_ssn,
tvb, offset, ADDRESS_SSN_LENGTH, ssn);
hidden_item = proto_tree_add_uint(call_tree, hf_sccp_ssn, tvb, offset,
ADDRESS_SSN_LENGTH, ssn);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset += ADDRESS_SSN_LENGTH;
ssn_dissector = dissector_get_uint_handle(sccp_ssn_dissector_table, ssn);
if (ssn_dissector) {
ssn_dissector_short_name = dissector_handle_get_short_name(ssn_dissector);
if (ssn_dissector_short_name) {
item = proto_tree_add_text(call_tree, tvb, offset - 1, ADDRESS_SSN_LENGTH,
"Linked to %s", ssn_dissector_short_name);
PROTO_ITEM_SET_GENERATED(item);
if (g_ascii_strncasecmp("TCAP", ssn_dissector_short_name, 4)== 0) {
tcap_ssn_dissector = get_itu_tcap_subdissector(ssn);
if (tcap_ssn_dissector) {
tcap_ssn_dissector_short_name = dissector_handle_get_short_name(tcap_ssn_dissector);
proto_item_append_text(item,", TCAP SSN linked to %s", tcap_ssn_dissector_short_name);
}
}
}
}
}
if (gti != AI_GTI_NO_GT) {
if (length < offset)
return;
gt_tvb = tvb_new_subset(tvb, offset, (length - offset),
(length - offset));
dissect_sccp_global_title(gt_tvb, pinfo, call_tree, (length - offset), gti,
(routing_ind == ROUTE_ON_GT), called);
}
} else if (decode_mtp3_standard == ANSI_STANDARD) {
proto_tree_add_uint(call_ai_tree, called ? hf_sccp_called_ansi_global_title_indicator
: hf_sccp_calling_ansi_global_title_indicator,
tvb, 0, ADDRESS_INDICATOR_LENGTH, gti);
pci = tvb_get_guint8(tvb, 0) & ANSI_PC_INDICATOR_MASK;
proto_tree_add_uint(call_ai_tree, called ? hf_sccp_called_ansi_point_code_indicator
: hf_sccp_calling_ansi_point_code_indicator,
tvb, 0, ADDRESS_INDICATOR_LENGTH, pci);
ssni = tvb_get_guint8(tvb, 0) & ANSI_SSN_INDICATOR_MASK;
expert_item = proto_tree_add_uint(call_ai_tree, called ? hf_sccp_called_ansi_ssn_indicator
: hf_sccp_calling_ansi_ssn_indicator,
tvb, 0, ADDRESS_INDICATOR_LENGTH, ssni);
if ((routing_ind == ROUTE_ON_SSN) && (ssni == 0)) {
expert_add_info(pinfo, expert_item, &ei_sccp_no_ssn_present);
}
offset = ADDRESS_INDICATOR_LENGTH;
if (ssni) {
ssn = tvb_get_guint8(tvb, offset);
if ((routing_ind == ROUTE_ON_SSN) && (ssn == 0)) {
expert_add_info(pinfo, expert_item, &ei_sccp_ssn_zero);
}
if (called && assoc) {
assoc->called_ssn = ssn;
} else if (assoc) {
assoc->calling_ssn = ssn;
}
if (is_connectionless(message_type) && sccp_msg) {
guint *ssn_ptr = called ? &(sccp_msg->data.ud.called_ssn) : &(sccp_msg->data.ud.calling_ssn);
*ssn_ptr = ssn;
}
proto_tree_add_uint(call_tree, called ? hf_sccp_called_ssn
: hf_sccp_calling_ssn,
tvb, offset, ADDRESS_SSN_LENGTH, ssn);
hidden_item = proto_tree_add_uint(call_tree, hf_sccp_ssn, tvb, offset,
ADDRESS_SSN_LENGTH, ssn);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset += ADDRESS_SSN_LENGTH;
}
if (pci) {
offset = dissect_sccp_3byte_pc(tvb, call_tree, offset, called);
}
if (gti != AI_GTI_NO_GT) {
if (length < offset)
return;
gt_tvb = tvb_new_subset(tvb, offset, (length - offset),
(length - offset));
dissect_sccp_global_title(gt_tvb, pinfo, call_tree, (length - offset), gti,
(routing_ind == ROUTE_ON_GT), called);
}
}
}
static void
dissect_sccp_called_param(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint length)
{
dissect_sccp_called_calling_param(tvb, tree, pinfo, length, TRUE);
}
static void
dissect_sccp_calling_param(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint length)
{
dissect_sccp_called_calling_param(tvb, tree, pinfo, length, FALSE);
}
static void
dissect_sccp_class_param(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint length)
{
guint8 msg_class;
proto_item *pi;
gboolean invalid_class = FALSE;
if (length != 1) {
proto_tree_add_expert_format(tree, pinfo, &ei_sccp_wrong_length, tvb, 0, length,
"Wrong length indicated. Expected 1, got %u", length);
return;
}
msg_class = tvb_get_guint8(tvb, 0) & CLASS_CLASS_MASK;
pi = proto_tree_add_uint(tree, hf_sccp_class, tvb, 0, length, msg_class);
switch (message_type) {
case SCCP_MSG_TYPE_DT1:
if (msg_class != 2)
invalid_class = TRUE;
break;
case SCCP_MSG_TYPE_DT2:
case SCCP_MSG_TYPE_AK:
case SCCP_MSG_TYPE_ED:
case SCCP_MSG_TYPE_EA:
case SCCP_MSG_TYPE_RSR:
case SCCP_MSG_TYPE_RSC:
if (msg_class != 3)
invalid_class = TRUE;
break;
case SCCP_MSG_TYPE_CR:
case SCCP_MSG_TYPE_CC:
case SCCP_MSG_TYPE_CREF:
case SCCP_MSG_TYPE_RLSD:
case SCCP_MSG_TYPE_RLC:
case SCCP_MSG_TYPE_ERR:
case SCCP_MSG_TYPE_IT:
if ((msg_class != 2) && (msg_class != 3))
invalid_class = TRUE;
break;
case SCCP_MSG_TYPE_UDT:
case SCCP_MSG_TYPE_UDTS:
case SCCP_MSG_TYPE_XUDT:
case SCCP_MSG_TYPE_XUDTS:
case SCCP_MSG_TYPE_LUDT:
case SCCP_MSG_TYPE_LUDTS:
if ((msg_class != 0) && (msg_class != 1))
invalid_class = TRUE;
break;
}
if (invalid_class)
expert_add_info(pinfo, pi, &ei_sccp_class_unexpected);
if (msg_class == 0 || msg_class == 1) {
guint8 handling = tvb_get_guint8(tvb, 0) & CLASS_SPARE_HANDLING_MASK;
pi = proto_tree_add_item(tree, hf_sccp_handling, tvb, 0, length, ENC_NA);
handling >>= CLASS_SPARE_HANDLING_SHIFT;
if (try_val_to_str(handling, sccp_class_handling_values) == NULL) {
expert_add_info(pinfo, pi, &ei_sccp_handling_invalid);
}
}
}
static void
dissect_sccp_segmenting_reassembling_param(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint length)
{
if (length != 1) {
proto_tree_add_expert_format(tree, pinfo, &ei_sccp_wrong_length, tvb, 0, length,
"Wrong length indicated. Expected 1, got %u", length);
return;
}
proto_tree_add_item(tree, hf_sccp_more, tvb, 0, length, ENC_BIG_ENDIAN);
}
static void
dissect_sccp_receive_sequence_number_param(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint length)
{
guint8 rsn;
if (length != 1) {
proto_tree_add_expert_format(tree, pinfo, &ei_sccp_wrong_length, tvb, 0, length,
"Wrong length indicated. Expected 1, got %u", length);
return;
}
rsn = tvb_get_guint8(tvb, 0) >> 1;
proto_tree_add_uint(tree, hf_sccp_rsn, tvb, 0, length, rsn);
}
static void
dissect_sccp_sequencing_segmenting_param(tvbuff_t *tvb, proto_tree *tree, guint length)
{
guint8 rsn, ssn;
proto_item *param_item;
proto_tree *param_tree;
ssn = tvb_get_guint8(tvb, 0) >> 1;
rsn = tvb_get_guint8(tvb, SEQUENCING_SEGMENTING_SSN_LENGTH) >> 1;
param_item = proto_tree_add_text(tree, tvb, 0, length, "%s",
val_to_str(PARAMETER_SEQUENCING_SEGMENTING,
sccp_parameter_values, "Unknown: %d"));
param_tree = proto_item_add_subtree(param_item,
ett_sccp_sequencing_segmenting);
proto_tree_add_uint(param_tree, hf_sccp_sequencing_segmenting_ssn, tvb, 0,
SEQUENCING_SEGMENTING_SSN_LENGTH, ssn);
proto_tree_add_uint(param_tree, hf_sccp_sequencing_segmenting_rsn, tvb,
SEQUENCING_SEGMENTING_SSN_LENGTH,
SEQUENCING_SEGMENTING_RSN_LENGTH, rsn);
proto_tree_add_item(param_tree, hf_sccp_sequencing_segmenting_more, tvb,
SEQUENCING_SEGMENTING_SSN_LENGTH,
SEQUENCING_SEGMENTING_RSN_LENGTH, ENC_NA);
}
static void
dissect_sccp_credit_param(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint length)
{
if (length != 1) {
proto_tree_add_expert_format(tree, pinfo, &ei_sccp_wrong_length, tvb, 0, length,
"Wrong length indicated. Expected 1, got %u", length);
return;
}
proto_tree_add_item(tree, hf_sccp_credit, tvb, 0, length, ENC_NA);
}
static void
dissect_sccp_release_cause_param(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint length)
{
if (length != 1) {
proto_tree_add_expert_format(tree, pinfo, &ei_sccp_wrong_length, tvb, 0, length,
"Wrong length indicated. Expected 1, got %u", length);
return;
}
proto_tree_add_item(tree, hf_sccp_release_cause, tvb, 0, length, ENC_LITTLE_ENDIAN);
if (show_key_params)
col_append_fstr(pinfo->cinfo, COL_INFO, "Cause=%d ", tvb_get_guint8(tvb, 0));
}
static void
dissect_sccp_return_cause_param(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint length)
{
if (length != 1) {
proto_tree_add_expert_format(tree, pinfo, &ei_sccp_wrong_length, tvb, 0, length,
"Wrong length indicated. Expected 1, got %u", length);
return;
}
proto_tree_add_item(tree, hf_sccp_return_cause, tvb, 0, length, ENC_LITTLE_ENDIAN);
if (show_key_params)
col_append_fstr(pinfo->cinfo, COL_INFO, "Cause=%d ", tvb_get_guint8(tvb, 0));
}
static void
dissect_sccp_reset_cause_param(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint length)
{
if (length != 1) {
proto_tree_add_expert_format(tree, pinfo, &ei_sccp_wrong_length, tvb, 0, length,
"Wrong length indicated. Expected 1, got %u", length);
return;
}
proto_tree_add_item(tree, hf_sccp_reset_cause, tvb, 0, length, ENC_LITTLE_ENDIAN);
if (show_key_params)
col_append_fstr(pinfo->cinfo, COL_INFO, "Cause=%d ", tvb_get_guint8(tvb, 0));
}
static void
dissect_sccp_error_cause_param(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint length)
{
if (length != 1) {
proto_tree_add_expert_format(tree, pinfo, &ei_sccp_wrong_length, tvb, 0, length,
"Wrong length indicated. Expected 1, got %u", length);
return;
}
proto_tree_add_item(tree, hf_sccp_error_cause, tvb, 0, length, ENC_LITTLE_ENDIAN);
if (show_key_params)
col_append_fstr(pinfo->cinfo, COL_INFO, "Cause=%d ", tvb_get_guint8(tvb, 0));
}
static void
dissect_sccp_refusal_cause_param(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint length)
{
if (length != 1) {
proto_tree_add_expert_format(tree, pinfo, &ei_sccp_wrong_length, tvb, 0, length,
"Wrong length indicated. Expected 1, got %u", length);
return;
}
proto_tree_add_item(tree, hf_sccp_refusal_cause, tvb, 0, length, ENC_LITTLE_ENDIAN);
if (show_key_params)
col_append_fstr(pinfo->cinfo, COL_INFO, "Cause=%d ", tvb_get_guint8(tvb, 0));
}
static void
dissect_sccp_data_param(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint8 ssn = INVALID_SSN;
guint8 other_ssn = INVALID_SSN;
const mtp3_addr_pc_t *dpc = NULL;
const mtp3_addr_pc_t *opc = NULL;
heur_dtbl_entry_t *hdtbl_entry;
if ((trace_sccp) && (assoc && assoc != &no_assoc)) {
pinfo->sccp_info = assoc->curr_msg;
} else {
pinfo->sccp_info = NULL;
}
if (assoc) {
switch (pinfo->p2p_dir) {
case P2P_DIR_SENT:
ssn = assoc->calling_ssn;
other_ssn = assoc->called_ssn;
dpc = (const mtp3_addr_pc_t*)pinfo->dst.data;
opc = (const mtp3_addr_pc_t*)pinfo->src.data;
break;
case P2P_DIR_RECV:
ssn = assoc->called_ssn;
other_ssn = assoc->calling_ssn;
dpc = (const mtp3_addr_pc_t*)pinfo->src.data;
opc = (const mtp3_addr_pc_t*)pinfo->dst.data;
break;
default:
ssn = assoc->called_ssn;
other_ssn = assoc->calling_ssn;
dpc = (const mtp3_addr_pc_t*)pinfo->dst.data;
opc = (const mtp3_addr_pc_t*)pinfo->src.data;
break;
}
}
if ((num_sccp_users) && (pinfo->src.type == AT_SS7PC)) {
guint i;
dissector_handle_t handle = NULL;
gboolean uses_tcap = FALSE;
for (i=0; i < num_sccp_users; i++) {
sccp_user_t *u = &(sccp_users[i]);
if (!dpc || dpc->ni != u->ni) continue;
if (value_is_in_range(u->called_ssn, ssn) && value_is_in_range(u->called_pc, dpc->pc) ) {
handle = *(u->handlep);
uses_tcap = u->uses_tcap;
break;
} else if (value_is_in_range(u->called_ssn, other_ssn) && opc && value_is_in_range(u->called_pc, opc->pc) ) {
handle = *(u->handlep);
uses_tcap = u->uses_tcap;
break;
}
}
if (handle) {
if (uses_tcap) {
call_tcap_dissector(handle, tvb, pinfo, tree);
} else {
call_dissector(handle, tvb, pinfo, tree);
}
return;
}
}
if ((ssn != INVALID_SSN) && dissector_try_uint(sccp_ssn_dissector_table, ssn, tvb, pinfo, tree)) {
return;
}
if ((other_ssn != INVALID_SSN) && dissector_try_uint(sccp_ssn_dissector_table, other_ssn, tvb, pinfo, tree)) {
return;
}
if (dissector_try_heuristic(heur_subdissector_list, tvb, pinfo, tree, &hdtbl_entry, NULL)) {
return;
}
if (default_handle) {
call_dissector(default_handle, tvb, pinfo, tree);
return;
}
call_dissector(data_handle, tvb, pinfo, tree);
}
static void
dissect_sccp_segmentation_param(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint length)
{
proto_item *param_item;
proto_tree *param_tree;
param_item = proto_tree_add_text(tree, tvb, 0, length, "%s",
val_to_str(PARAMETER_SEGMENTATION,
sccp_parameter_values, "Unknown: %d"));
param_tree = proto_item_add_subtree(param_item, ett_sccp_segmentation);
proto_tree_add_item(param_tree, hf_sccp_segmentation_first, tvb, 0, 1, ENC_NA);
proto_tree_add_item(param_tree, hf_sccp_segmentation_class, tvb, 0, 1, ENC_NA);
proto_tree_add_item(param_tree, hf_sccp_segmentation_remaining, tvb, 0, 1, ENC_NA);
if (length-1 != 3) {
proto_tree_add_expert_format(tree, pinfo, &ei_sccp_wrong_length, tvb, 0, length-1,
"Wrong length indicated. Expected 3, got %u", length-1);
return;
}
proto_tree_add_item(param_tree, hf_sccp_segmentation_slr, tvb, 1, length-1, ENC_LITTLE_ENDIAN);
}
static void
dissect_sccp_hop_counter_param(tvbuff_t *tvb, proto_tree *tree, guint length)
{
guint8 hops;
hops = tvb_get_guint8(tvb, 0);
proto_tree_add_uint(tree, hf_sccp_hop_counter, tvb, 0, length, hops);
}
static void
dissect_sccp_importance_param(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint length)
{
if (length != 1) {
proto_tree_add_expert_format(tree, pinfo, &ei_sccp_wrong_length, tvb, 0, length,
"Wrong length indicated. Expected 1, got %u", length);
return;
}
proto_tree_add_item(tree, hf_sccp_importance, tvb, 0, length, ENC_NA);
}
static void
dissect_sccp_isni_param(tvbuff_t *tvb, proto_tree *tree, guint length)
{
guint8 ti;
guint offset = 0;
proto_item *param_item;
proto_tree *param_tree;
param_item = proto_tree_add_text(tree, tvb, offset, ANSI_ISNI_ROUTING_CONTROL_LENGTH,
"ISNI Routing Control");
param_tree = proto_item_add_subtree(param_item,
ett_sccp_ansi_isni_routing_control);
proto_tree_add_item(param_tree, hf_sccp_ansi_isni_mi, tvb, offset,
ANSI_ISNI_ROUTING_CONTROL_LENGTH, ENC_NA);
proto_tree_add_item(param_tree, hf_sccp_ansi_isni_iri, tvb, offset,
ANSI_ISNI_ROUTING_CONTROL_LENGTH, ENC_NA);
ti = tvb_get_guint8(tvb, offset) & ANSI_ISNI_TI_MASK;
proto_tree_add_uint(param_tree, hf_sccp_ansi_isni_ti, tvb, offset,
ANSI_ISNI_ROUTING_CONTROL_LENGTH, ti);
proto_tree_add_item(param_tree, hf_sccp_ansi_isni_counter, tvb, offset,
ANSI_ISNI_ROUTING_CONTROL_LENGTH, ENC_NA);
offset += ANSI_ISNI_ROUTING_CONTROL_LENGTH;
if ((ti >> ANSI_ISNI_TI_SHIFT) == ANSI_ISNI_TYPE_1) {
proto_tree_add_uint(param_tree, hf_sccp_ansi_isni_netspec, tvb, offset,
ANSI_ISNI_ROUTING_CONTROL_LENGTH, ti);
offset += ANSI_ISNI_ROUTING_CONTROL_LENGTH;
}
while (offset < length) {
proto_tree_add_item(tree, hf_sccp_ansi_isni_network, tvb, offset,
ANSI_NCM_LENGTH, ENC_NA);
offset++;
proto_tree_add_item(tree, hf_sccp_ansi_isni_cluster, tvb, offset,
ANSI_NCM_LENGTH, ENC_NA);
offset++;
}
}
static guint16
dissect_sccp_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *sccp_tree,
proto_tree *tree, guint8 parameter_type, guint16 offset,
guint16 parameter_length)
{
tvbuff_t *parameter_tvb;
switch (parameter_type) {
case PARAMETER_CALLED_PARTY_ADDRESS:
case PARAMETER_CALLING_PARTY_ADDRESS:
case PARAMETER_DATA:
case PARAMETER_LONG_DATA:
case PARAMETER_SOURCE_LOCAL_REFERENCE:
case PARAMETER_DESTINATION_LOCAL_REFERENCE:
case PARAMETER_RELEASE_CAUSE:
case PARAMETER_RETURN_CAUSE:
case PARAMETER_RESET_CAUSE:
case PARAMETER_ERROR_CAUSE:
case PARAMETER_REFUSAL_CAUSE:
break;
default:
if (!sccp_tree) return(parameter_length);
}
parameter_tvb = tvb_new_subset(tvb, offset, parameter_length, parameter_length);
switch (parameter_type) {
case PARAMETER_END_OF_OPTIONAL_PARAMETERS:
proto_tree_add_text(sccp_tree, tvb, offset, parameter_length,
"End of Optional");
break;
case PARAMETER_DESTINATION_LOCAL_REFERENCE:
dissect_sccp_dlr_param(parameter_tvb, pinfo, sccp_tree, parameter_length);
break;
case PARAMETER_SOURCE_LOCAL_REFERENCE:
dissect_sccp_slr_param(parameter_tvb, pinfo, sccp_tree, parameter_length);
break;
case PARAMETER_CALLED_PARTY_ADDRESS:
dissect_sccp_called_param(parameter_tvb, pinfo, sccp_tree, parameter_length);
break;
case PARAMETER_CALLING_PARTY_ADDRESS:
dissect_sccp_calling_param(parameter_tvb, pinfo, sccp_tree, parameter_length);
break;
case PARAMETER_CLASS:
dissect_sccp_class_param(parameter_tvb, pinfo, sccp_tree, parameter_length);
break;
case PARAMETER_SEGMENTING_REASSEMBLING:
dissect_sccp_segmenting_reassembling_param(parameter_tvb, pinfo, sccp_tree,
parameter_length);
break;
case PARAMETER_RECEIVE_SEQUENCE_NUMBER:
dissect_sccp_receive_sequence_number_param(parameter_tvb, pinfo, sccp_tree,
parameter_length);
break;
case PARAMETER_SEQUENCING_SEGMENTING:
dissect_sccp_sequencing_segmenting_param(parameter_tvb, sccp_tree,
parameter_length);
break;
case PARAMETER_CREDIT:
dissect_sccp_credit_param(parameter_tvb, pinfo, sccp_tree, parameter_length);
break;
case PARAMETER_RELEASE_CAUSE:
dissect_sccp_release_cause_param(parameter_tvb, pinfo, sccp_tree, parameter_length);
break;
case PARAMETER_RETURN_CAUSE:
dissect_sccp_return_cause_param(parameter_tvb, pinfo, sccp_tree, parameter_length);
break;
case PARAMETER_RESET_CAUSE:
dissect_sccp_reset_cause_param(parameter_tvb, pinfo, sccp_tree, parameter_length);
break;
case PARAMETER_ERROR_CAUSE:
dissect_sccp_error_cause_param(parameter_tvb, pinfo, sccp_tree, parameter_length);
break;
case PARAMETER_REFUSAL_CAUSE:
dissect_sccp_refusal_cause_param(parameter_tvb, pinfo, sccp_tree, parameter_length);
break;
case PARAMETER_DATA:
dissect_sccp_data_param(parameter_tvb, pinfo, tree);
break;
case PARAMETER_SEGMENTATION:
dissect_sccp_segmentation_param(parameter_tvb, pinfo, sccp_tree, parameter_length);
break;
case PARAMETER_HOP_COUNTER:
dissect_sccp_hop_counter_param(parameter_tvb, sccp_tree, parameter_length);
break;
case PARAMETER_IMPORTANCE:
if (decode_mtp3_standard != ANSI_STANDARD)
dissect_sccp_importance_param(parameter_tvb, pinfo, sccp_tree, parameter_length);
else
dissect_sccp_unknown_param(parameter_tvb, sccp_tree, parameter_type,
parameter_length);
break;
case PARAMETER_LONG_DATA:
dissect_sccp_data_param(parameter_tvb, pinfo, tree);
break;
case PARAMETER_ISNI:
if (decode_mtp3_standard != ANSI_STANDARD)
dissect_sccp_unknown_param(parameter_tvb, sccp_tree, parameter_type,
parameter_length);
else
dissect_sccp_isni_param(parameter_tvb, sccp_tree, parameter_length);
break;
default:
dissect_sccp_unknown_param(parameter_tvb, sccp_tree, parameter_type,
parameter_length);
break;
}
return(parameter_length);
}
static guint16
dissect_sccp_variable_parameter(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *sccp_tree, proto_tree *tree,
guint8 parameter_type, guint16 offset)
{
guint16 parameter_length;
guint8 length_length;
proto_item *pi;
if (parameter_type != PARAMETER_LONG_DATA) {
parameter_length = tvb_get_guint8(tvb, offset);
length_length = PARAMETER_LENGTH_LENGTH;
} else {
parameter_length = tvb_get_letohs(tvb, offset);
length_length = PARAMETER_LONG_DATA_LENGTH_LENGTH;
}
pi = proto_tree_add_uint_format(sccp_tree, hf_sccp_param_length, tvb, offset,
length_length, parameter_length, "%s length: %d",
val_to_str(parameter_type, sccp_parameter_values,
"Unknown: %d"),
parameter_length);
if (!sccp_show_length) {
PROTO_ITEM_SET_HIDDEN(pi);
}
offset += length_length;
dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree, parameter_type, offset,
parameter_length);
return(parameter_length + length_length);
}
static void
dissect_sccp_optional_parameters(tvbuff_t *tvb, packet_info *pinfo,
proto_tree *sccp_tree, proto_tree *tree,
guint16 offset)
{
guint8 parameter_type;
while ((parameter_type = tvb_get_guint8(tvb, offset)) !=
PARAMETER_END_OF_OPTIONAL_PARAMETERS) {
offset += PARAMETER_TYPE_LENGTH;
offset += dissect_sccp_variable_parameter(tvb, pinfo, sccp_tree, tree,
parameter_type, offset);
}
dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree, parameter_type, offset,
END_OF_OPTIONAL_PARAMETERS_LENGTH);
}
static sccp_msg_info_t *
new_ud_msg(packet_info *pinfo, guint32 msg_type _U_)
{
sccp_msg_info_t *m = wmem_new0(wmem_packet_scope(), sccp_msg_info_t);
m->framenum = PINFO_FD_NUM(pinfo);
m->data.ud.calling_gt = NULL;
m->data.ud.called_gt = NULL;
register_frame_end_routine(pinfo, reset_sccp_assoc);
return m;
}
static int
dissect_sccp_message(tvbuff_t *tvb, packet_info *pinfo, proto_tree *sccp_tree,
proto_tree *tree)
{
guint16 variable_pointer1 = 0, variable_pointer2 = 0, variable_pointer3 = 0;
guint16 optional_pointer = 0, orig_opt_ptr = 0;
guint16 offset = 0;
gboolean save_fragmented;
tvbuff_t *new_tvb = NULL;
fragment_head *frag_msg = NULL;
guint32 source_local_ref = 0;
guint8 more;
guint msg_offset = tvb_offset_from_real_beginning(tvb);
#define VARIABLE_POINTER(var, hf_var, ptr_size) \
do { \
if (ptr_size == POINTER_LENGTH) \
var = tvb_get_guint8(tvb, offset); \
else \
var = tvb_get_letohs(tvb, offset); \
proto_tree_add_uint(sccp_tree, hf_var, tvb, \
offset, ptr_size, var); \
var += offset; \
if (ptr_size == POINTER_LENGTH_LONG) \
var += 1; \
offset += ptr_size; \
} while (0)
#define OPTIONAL_POINTER(ptr_size) \
do { \
if (ptr_size == POINTER_LENGTH) \
orig_opt_ptr = optional_pointer = tvb_get_guint8(tvb, offset); \
else \
orig_opt_ptr = optional_pointer = tvb_get_letohs(tvb, offset); \
proto_tree_add_uint(sccp_tree, hf_sccp_optional_pointer, tvb, \
offset, ptr_size, optional_pointer); \
optional_pointer += offset; \
if (ptr_size == POINTER_LENGTH_LONG) \
optional_pointer += 1; \
offset += ptr_size; \
} while (0)
message_type = tvb_get_guint8(tvb, SCCP_MSG_TYPE_OFFSET);
offset = SCCP_MSG_TYPE_LENGTH;
col_add_fstr(pinfo->cinfo, COL_INFO, "%s ",
val_to_str(message_type, sccp_message_type_acro_values, "Unknown: %d"));
if (sccp_tree) {
proto_tree_add_uint(sccp_tree, hf_sccp_message_type, tvb,
SCCP_MSG_TYPE_OFFSET, SCCP_MSG_TYPE_LENGTH, message_type);
};
dlr = INVALID_LR;
slr = INVALID_LR;
assoc = NULL;
no_assoc.calling_dpc = 0;
no_assoc.called_dpc = 0;
no_assoc.calling_ssn = INVALID_SSN;
no_assoc.called_ssn = INVALID_SSN;
no_assoc.has_fw_key = FALSE;
no_assoc.has_bw_key = FALSE;
no_assoc.payload = SCCP_PLOAD_NONE;
no_assoc.called_party = NULL;
no_assoc.calling_party = NULL;
no_assoc.extra_info = NULL;
switch (message_type) {
case SCCP_MSG_TYPE_CR:
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_SOURCE_LOCAL_REFERENCE,
offset, SOURCE_LOCAL_REFERENCE_LENGTH);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_CLASS, offset,
PROTOCOL_CLASS_LENGTH);
assoc = get_sccp_assoc(pinfo, msg_offset, slr, dlr, message_type);
VARIABLE_POINTER(variable_pointer1, hf_sccp_variable_pointer1, POINTER_LENGTH);
OPTIONAL_POINTER(POINTER_LENGTH);
dissect_sccp_variable_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_CALLED_PARTY_ADDRESS,
variable_pointer1);
break;
case SCCP_MSG_TYPE_CC:
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_DESTINATION_LOCAL_REFERENCE,
offset,
DESTINATION_LOCAL_REFERENCE_LENGTH);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_SOURCE_LOCAL_REFERENCE,
offset, SOURCE_LOCAL_REFERENCE_LENGTH);
assoc = get_sccp_assoc(pinfo, msg_offset, slr, dlr, message_type);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_CLASS, offset,
PROTOCOL_CLASS_LENGTH);
OPTIONAL_POINTER(POINTER_LENGTH);
break;
case SCCP_MSG_TYPE_CREF:
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_DESTINATION_LOCAL_REFERENCE,
offset,
DESTINATION_LOCAL_REFERENCE_LENGTH);
assoc = get_sccp_assoc(pinfo, msg_offset, slr, dlr, message_type);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_REFUSAL_CAUSE, offset,
REFUSAL_CAUSE_LENGTH);
OPTIONAL_POINTER(POINTER_LENGTH);
break;
case SCCP_MSG_TYPE_RLSD:
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_DESTINATION_LOCAL_REFERENCE,
offset,
DESTINATION_LOCAL_REFERENCE_LENGTH);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_SOURCE_LOCAL_REFERENCE,
offset, SOURCE_LOCAL_REFERENCE_LENGTH);
assoc = get_sccp_assoc(pinfo, msg_offset, slr, dlr, message_type);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_RELEASE_CAUSE, offset,
RELEASE_CAUSE_LENGTH);
OPTIONAL_POINTER(POINTER_LENGTH);
assoc = get_sccp_assoc(pinfo, msg_offset, slr, dlr, message_type);
break;
case SCCP_MSG_TYPE_RLC:
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_DESTINATION_LOCAL_REFERENCE,
offset,
DESTINATION_LOCAL_REFERENCE_LENGTH);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_SOURCE_LOCAL_REFERENCE,
offset, SOURCE_LOCAL_REFERENCE_LENGTH);
assoc = get_sccp_assoc(pinfo, msg_offset, slr, dlr, message_type);
break;
case SCCP_MSG_TYPE_DT1:
source_local_ref = tvb_get_letoh24(tvb, offset);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_DESTINATION_LOCAL_REFERENCE,
offset,
DESTINATION_LOCAL_REFERENCE_LENGTH);
assoc = get_sccp_assoc(pinfo, msg_offset, slr, dlr, message_type);
more = tvb_get_guint8(tvb, offset) & SEGMENTING_REASSEMBLING_MASK;
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_SEGMENTING_REASSEMBLING,
offset, SEGMENTING_REASSEMBLING_LENGTH);
VARIABLE_POINTER(variable_pointer1, hf_sccp_variable_pointer1, POINTER_LENGTH);
if (!sccp_reassemble) {
proto_tree_add_text(sccp_tree, tvb, variable_pointer1,
tvb_get_guint8(tvb, variable_pointer1)+1,
"Segmented Data");
dissect_sccp_variable_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_DATA, variable_pointer1);
} else {
save_fragmented = pinfo->fragmented;
pinfo->fragmented = TRUE;
frag_msg = fragment_add_seq_next(&sccp_xudt_msg_reassembly_table,
tvb, variable_pointer1 + 1,
pinfo,
source_local_ref,
NULL,
tvb_get_guint8(tvb, variable_pointer1),
more);
new_tvb = process_reassembled_data(tvb, variable_pointer1 + 1, pinfo,
"Reassembled SCCP", frag_msg,
&sccp_xudt_msg_frag_items, NULL,
tree);
if (frag_msg && frag_msg->next) {
col_append_str(pinfo->cinfo, COL_INFO, "(Message reassembled) ");
} else if (more) {
col_append_str(pinfo->cinfo, COL_INFO, "(Message fragment) ");
}
pinfo->fragmented = save_fragmented;
if (new_tvb)
dissect_sccp_data_param(new_tvb, pinfo, tree);
}
break;
case SCCP_MSG_TYPE_DT2:
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_DESTINATION_LOCAL_REFERENCE,
offset,
DESTINATION_LOCAL_REFERENCE_LENGTH);
assoc = get_sccp_assoc(pinfo, msg_offset, slr, dlr, message_type);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_SEQUENCING_SEGMENTING, offset,
SEQUENCING_SEGMENTING_LENGTH);
break;
case SCCP_MSG_TYPE_AK:
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_DESTINATION_LOCAL_REFERENCE,
offset,
DESTINATION_LOCAL_REFERENCE_LENGTH);
assoc = get_sccp_assoc(pinfo, msg_offset, slr, dlr, message_type);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_RECEIVE_SEQUENCE_NUMBER,
offset, RECEIVE_SEQUENCE_NUMBER_LENGTH);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_CREDIT, offset, CREDIT_LENGTH);
break;
case SCCP_MSG_TYPE_UDT:
pinfo->sccp_info = sccp_msg = new_ud_msg(pinfo, message_type);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_CLASS, offset,
PROTOCOL_CLASS_LENGTH);
VARIABLE_POINTER(variable_pointer1, hf_sccp_variable_pointer1, POINTER_LENGTH);
VARIABLE_POINTER(variable_pointer2, hf_sccp_variable_pointer2, POINTER_LENGTH);
VARIABLE_POINTER(variable_pointer3, hf_sccp_variable_pointer3, POINTER_LENGTH);
assoc = get_sccp_assoc(pinfo, msg_offset, slr, dlr, message_type);
dissect_sccp_variable_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_CALLED_PARTY_ADDRESS,
variable_pointer1);
dissect_sccp_variable_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_CALLING_PARTY_ADDRESS,
variable_pointer2);
dissect_sccp_variable_parameter(tvb, pinfo, sccp_tree, tree, PARAMETER_DATA,
variable_pointer3);
break;
case SCCP_MSG_TYPE_UDTS:
{
gboolean save_in_error_pkt = pinfo->flags.in_error_pkt;
pinfo->flags.in_error_pkt = TRUE;
pinfo->sccp_info = sccp_msg = new_ud_msg(pinfo, message_type);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_RETURN_CAUSE, offset,
RETURN_CAUSE_LENGTH);
VARIABLE_POINTER(variable_pointer1, hf_sccp_variable_pointer1, POINTER_LENGTH);
VARIABLE_POINTER(variable_pointer2, hf_sccp_variable_pointer2, POINTER_LENGTH);
VARIABLE_POINTER(variable_pointer3, hf_sccp_variable_pointer3, POINTER_LENGTH);
assoc = get_sccp_assoc(pinfo, msg_offset, slr, dlr, message_type);
dissect_sccp_variable_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_CALLED_PARTY_ADDRESS,
variable_pointer1);
dissect_sccp_variable_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_CALLING_PARTY_ADDRESS,
variable_pointer2);
dissect_sccp_variable_parameter(tvb, pinfo, sccp_tree, tree, PARAMETER_DATA,
variable_pointer3);
pinfo->flags.in_error_pkt = save_in_error_pkt;
break;
}
case SCCP_MSG_TYPE_ED:
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_DESTINATION_LOCAL_REFERENCE,
offset,
DESTINATION_LOCAL_REFERENCE_LENGTH);
assoc = get_sccp_assoc(pinfo, msg_offset, slr, dlr, message_type);
VARIABLE_POINTER(variable_pointer1, hf_sccp_variable_pointer1, POINTER_LENGTH);
dissect_sccp_variable_parameter(tvb, pinfo, sccp_tree, tree, PARAMETER_DATA,
variable_pointer1);
break;
case SCCP_MSG_TYPE_EA:
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_DESTINATION_LOCAL_REFERENCE,
offset,
DESTINATION_LOCAL_REFERENCE_LENGTH);
assoc = get_sccp_assoc(pinfo, msg_offset, slr, dlr, message_type);
break;
case SCCP_MSG_TYPE_RSR:
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_DESTINATION_LOCAL_REFERENCE,
offset,
DESTINATION_LOCAL_REFERENCE_LENGTH);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_SOURCE_LOCAL_REFERENCE,
offset, SOURCE_LOCAL_REFERENCE_LENGTH);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_RESET_CAUSE, offset,
RESET_CAUSE_LENGTH);
assoc = get_sccp_assoc(pinfo, msg_offset, slr, dlr, message_type);
break;
case SCCP_MSG_TYPE_RSC:
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_DESTINATION_LOCAL_REFERENCE,
offset,
DESTINATION_LOCAL_REFERENCE_LENGTH);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_SOURCE_LOCAL_REFERENCE,
offset, SOURCE_LOCAL_REFERENCE_LENGTH);
assoc = get_sccp_assoc(pinfo, msg_offset, slr, dlr, message_type);
break;
case SCCP_MSG_TYPE_ERR:
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_DESTINATION_LOCAL_REFERENCE,
offset,
DESTINATION_LOCAL_REFERENCE_LENGTH);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_ERROR_CAUSE, offset,
ERROR_CAUSE_LENGTH);
assoc = get_sccp_assoc(pinfo, msg_offset, slr, dlr, message_type);
break;
case SCCP_MSG_TYPE_IT:
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_DESTINATION_LOCAL_REFERENCE,
offset,
DESTINATION_LOCAL_REFERENCE_LENGTH);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_SOURCE_LOCAL_REFERENCE,
offset, SOURCE_LOCAL_REFERENCE_LENGTH);
assoc = get_sccp_assoc(pinfo, msg_offset, slr, dlr, message_type);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_CLASS, offset,
PROTOCOL_CLASS_LENGTH);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_SEQUENCING_SEGMENTING,
offset, SEQUENCING_SEGMENTING_LENGTH);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_CREDIT, offset, CREDIT_LENGTH);
break;
case SCCP_MSG_TYPE_XUDT:
pinfo->sccp_info = sccp_msg = new_ud_msg(pinfo, message_type);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_CLASS, offset,
PROTOCOL_CLASS_LENGTH);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_HOP_COUNTER, offset,
HOP_COUNTER_LENGTH);
VARIABLE_POINTER(variable_pointer1, hf_sccp_variable_pointer1, POINTER_LENGTH);
VARIABLE_POINTER(variable_pointer2, hf_sccp_variable_pointer2, POINTER_LENGTH);
VARIABLE_POINTER(variable_pointer3, hf_sccp_variable_pointer3, POINTER_LENGTH);
OPTIONAL_POINTER(POINTER_LENGTH);
assoc = get_sccp_assoc(pinfo, msg_offset, slr, dlr, message_type);
dissect_sccp_variable_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_CALLED_PARTY_ADDRESS,
variable_pointer1);
dissect_sccp_variable_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_CALLING_PARTY_ADDRESS,
variable_pointer2);
if (tvb_get_guint8(tvb, optional_pointer) == PARAMETER_SEGMENTATION) {
if (!sccp_reassemble) {
proto_tree_add_text(sccp_tree, tvb, variable_pointer3, tvb_get_guint8(tvb, variable_pointer3)+1, "Segmented Data");
} else {
guint8 octet;
gboolean more_frag = TRUE;
octet = tvb_get_guint8(tvb, optional_pointer+2);
source_local_ref = tvb_get_letoh24(tvb, optional_pointer+3);
if ((octet & 0x0f) == 0)
more_frag = FALSE;
save_fragmented = pinfo->fragmented;
pinfo->fragmented = TRUE;
frag_msg = fragment_add_seq_next(&sccp_xudt_msg_reassembly_table,
tvb, variable_pointer3 + 1,
pinfo,
source_local_ref,
NULL,
tvb_get_guint8(tvb, variable_pointer3),
more_frag);
if ((octet & 0x80) == 0x80)
fragment_set_tot_len(&sccp_xudt_msg_reassembly_table,
pinfo, source_local_ref, NULL, (octet & 0xf));
new_tvb = process_reassembled_data(tvb, variable_pointer3 + 1,
pinfo, "Reassembled SCCP",
frag_msg,
&sccp_xudt_msg_frag_items,
NULL, tree);
if (frag_msg) {
col_append_str(pinfo->cinfo, COL_INFO,"(Message reassembled) ");
} else {
col_append_str(pinfo->cinfo, COL_INFO,"(Message fragment) ");
}
pinfo->fragmented = save_fragmented;
if (new_tvb)
dissect_sccp_data_param(new_tvb, pinfo, tree);
}
} else {
dissect_sccp_variable_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_DATA, variable_pointer3);
}
break;
case SCCP_MSG_TYPE_XUDTS:
{
gboolean save_in_error_pkt = pinfo->flags.in_error_pkt;
pinfo->flags.in_error_pkt = TRUE;
pinfo->sccp_info = sccp_msg = new_ud_msg(pinfo, message_type);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_RETURN_CAUSE, offset,
RETURN_CAUSE_LENGTH);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_HOP_COUNTER, offset,
HOP_COUNTER_LENGTH);
VARIABLE_POINTER(variable_pointer1, hf_sccp_variable_pointer1, POINTER_LENGTH);
VARIABLE_POINTER(variable_pointer2, hf_sccp_variable_pointer2, POINTER_LENGTH);
VARIABLE_POINTER(variable_pointer3, hf_sccp_variable_pointer3, POINTER_LENGTH);
OPTIONAL_POINTER(POINTER_LENGTH);
assoc = get_sccp_assoc(pinfo, msg_offset, slr, dlr, message_type);
dissect_sccp_variable_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_CALLED_PARTY_ADDRESS,
variable_pointer1);
dissect_sccp_variable_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_CALLING_PARTY_ADDRESS,
variable_pointer2);
if (tvb_get_guint8(tvb, optional_pointer) == PARAMETER_SEGMENTATION) {
if (!sccp_reassemble) {
proto_tree_add_text(sccp_tree, tvb, variable_pointer3, tvb_get_guint8(tvb, variable_pointer3)+1, "Segmented Data");
} else {
guint8 octet;
gboolean more_frag = TRUE;
octet = tvb_get_guint8(tvb, optional_pointer+2);
source_local_ref = tvb_get_letoh24(tvb, optional_pointer+3);
if ((octet & 0x0f) == 0)
more_frag = FALSE;
save_fragmented = pinfo->fragmented;
pinfo->fragmented = TRUE;
frag_msg = fragment_add_seq_next(&sccp_xudt_msg_reassembly_table,
tvb, variable_pointer3 + 1,
pinfo,
source_local_ref,
NULL,
tvb_get_guint8(tvb, variable_pointer3),
more_frag);
if ((octet & 0x80) == 0x80)
fragment_set_tot_len(&sccp_xudt_msg_reassembly_table,
pinfo, source_local_ref, NULL, (octet & 0xf));
new_tvb = process_reassembled_data(tvb, variable_pointer3 + 1,
pinfo, "Reassembled SCCP",
frag_msg,
&sccp_xudt_msg_frag_items,
NULL, tree);
if (frag_msg) {
col_append_str(pinfo->cinfo, COL_INFO, "(Message reassembled) ");
} else {
col_append_str(pinfo->cinfo, COL_INFO, "(Message fragment) ");
}
pinfo->fragmented = save_fragmented;
if (new_tvb)
dissect_sccp_data_param(new_tvb, pinfo, tree);
}
} else {
dissect_sccp_variable_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_DATA, variable_pointer3);
}
pinfo->flags.in_error_pkt = save_in_error_pkt;
break;
}
case SCCP_MSG_TYPE_LUDT:
pinfo->sccp_info = sccp_msg = new_ud_msg(pinfo, message_type);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_CLASS, offset,
PROTOCOL_CLASS_LENGTH);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_HOP_COUNTER, offset,
HOP_COUNTER_LENGTH);
VARIABLE_POINTER(variable_pointer1, hf_sccp_variable_pointer1, POINTER_LENGTH_LONG);
VARIABLE_POINTER(variable_pointer2, hf_sccp_variable_pointer2, POINTER_LENGTH_LONG);
VARIABLE_POINTER(variable_pointer3, hf_sccp_variable_pointer3, POINTER_LENGTH_LONG);
OPTIONAL_POINTER(POINTER_LENGTH_LONG);
assoc = get_sccp_assoc(pinfo, msg_offset, slr, dlr, message_type);
dissect_sccp_variable_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_CALLED_PARTY_ADDRESS,
variable_pointer1);
dissect_sccp_variable_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_CALLING_PARTY_ADDRESS,
variable_pointer2);
dissect_sccp_variable_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_LONG_DATA, variable_pointer3);
break;
case SCCP_MSG_TYPE_LUDTS:
pinfo->sccp_info = sccp_msg = new_ud_msg(pinfo, message_type);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_RETURN_CAUSE, offset,
RETURN_CAUSE_LENGTH);
offset += dissect_sccp_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_HOP_COUNTER, offset,
HOP_COUNTER_LENGTH);
VARIABLE_POINTER(variable_pointer1, hf_sccp_variable_pointer1, POINTER_LENGTH_LONG);
VARIABLE_POINTER(variable_pointer2, hf_sccp_variable_pointer2, POINTER_LENGTH_LONG);
VARIABLE_POINTER(variable_pointer3, hf_sccp_variable_pointer3, POINTER_LENGTH_LONG);
OPTIONAL_POINTER(POINTER_LENGTH_LONG);
assoc = get_sccp_assoc(pinfo, msg_offset, slr, dlr, message_type);
dissect_sccp_variable_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_CALLED_PARTY_ADDRESS,
variable_pointer1);
dissect_sccp_variable_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_CALLING_PARTY_ADDRESS,
variable_pointer2);
dissect_sccp_variable_parameter(tvb, pinfo, sccp_tree, tree,
PARAMETER_LONG_DATA, variable_pointer3);
break;
default:
dissect_sccp_unknown_message(tvb, sccp_tree);
}
if (orig_opt_ptr)
dissect_sccp_optional_parameters(tvb, pinfo, sccp_tree, tree,
optional_pointer);
if (trace_sccp && assoc && (assoc != &no_assoc)) {
proto_item *pi = proto_tree_add_uint(sccp_tree, hf_sccp_assoc_id, tvb, 0, 0, assoc->id);
proto_tree *pt = proto_item_add_subtree(pi, ett_sccp_assoc);
PROTO_ITEM_SET_GENERATED(pi);
if (assoc->msgs) {
sccp_msg_info_t *m;
for(m = assoc->msgs; m ; m = m->data.co.next) {
pi = proto_tree_add_uint(pt, hf_sccp_assoc_msg, tvb, 0, 0, m->framenum);
if (assoc->payload != SCCP_PLOAD_NONE)
proto_item_append_text(pi," %s", val_to_str(assoc->payload, assoc_protos, "Unknown: %d"));
if (m->data.co.label)
proto_item_append_text(pi," %s", m->data.co.label);
if ((m->framenum == PINFO_FD_NUM(pinfo)) && (m->offset == msg_offset) ) {
tap_queue_packet(sccp_tap, pinfo, m);
proto_item_append_text(pi," (current)");
}
PROTO_ITEM_SET_GENERATED(pi);
}
}
}
return offset;
}
static void
dissect_sccp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_item *sccp_item = NULL;
proto_tree *sccp_tree = NULL;
const mtp3_addr_pc_t *mtp3_addr_p;
if ((pinfo->src.type == AT_SS7PC) &&
((mtp3_addr_p = (const mtp3_addr_pc_t *)pinfo->src.data)->type <= CHINESE_ITU_STANDARD)) {
decode_mtp3_standard = mtp3_addr_p->type;
} else {
decode_mtp3_standard = (Standard_Type)mtp3_standard;
}
switch (decode_mtp3_standard) {
case ITU_STANDARD:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SCCP (Int. ITU)");
break;
case ANSI_STANDARD:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SCCP (ANSI)");
break;
case CHINESE_ITU_STANDARD:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SCCP (Chin. ITU)");
break;
case JAPAN_STANDARD:
col_set_str(pinfo->cinfo, COL_PROTOCOL, "SCCP (Japan)");
break;
};
if (tree) {
sccp_item = proto_tree_add_item(tree, proto_sccp, tvb, 0, -1, ENC_NA);
sccp_tree = proto_item_add_subtree(sccp_item, ett_sccp);
}
if (pinfo->src.type == AT_SS7PC) {
mtp3_addr_p = (const mtp3_addr_pc_t *)pinfo->src.data;
if (sccp_source_pc_global == mtp3_addr_p->pc) {
pinfo->p2p_dir = P2P_DIR_SENT;
} else {
mtp3_addr_p = (const mtp3_addr_pc_t *)pinfo->dst.data;
if (sccp_source_pc_global == mtp3_addr_p->pc)
{
pinfo->p2p_dir = P2P_DIR_RECV;
} else {
pinfo->p2p_dir = P2P_DIR_UNKNOWN;
}
}
}
dissect_sccp_message(tvb, pinfo, sccp_tree, tree);
}
static void
sccp_users_update_cb(void *r, const char **err)
{
sccp_user_t *u = (sccp_user_t *)r;
struct _sccp_ul *c;
range_t *empty;
empty = range_empty();
if (ranges_are_equal(u->called_pc, empty)) {
*err = g_strdup("Must specify a PC");
return;
}
if (ranges_are_equal(u->called_ssn, empty)) {
*err = g_strdup("Must specify an SSN");
return;
}
for (c=user_list; c->handlep; c++) {
if (c->id == u->user) {
u->uses_tcap = c->uses_tcap;
u->handlep = c->handlep;
return;
}
}
u->uses_tcap = FALSE;
u->handlep = &data_handle;
}
static void *
sccp_users_copy_cb(void *n, const void *o, size_t siz _U_)
{
const sccp_user_t *u = (const sccp_user_t *)o;
sccp_user_t *un = (sccp_user_t *)n;
un->ni = u->ni;
un->user = u->user;
un->uses_tcap = u->uses_tcap;
un->handlep = u->handlep;
if (u->called_pc)
un->called_pc = range_copy(u->called_pc);
if (u->called_ssn)
un->called_ssn = range_copy(u->called_ssn);
return n;
}
static void
sccp_users_free_cb(void *r)
{
sccp_user_t *u = (sccp_user_t *)r;
if (u->called_pc) g_free(u->called_pc);
if (u->called_ssn) g_free(u->called_ssn);
}
static void
init_sccp(void)
{
next_assoc_id = 1;
reassembly_table_init (&sccp_xudt_msg_reassembly_table,
&addresses_reassembly_table_functions);
}
void
proto_register_sccp(void)
{
static hf_register_info hf[] = {
{ &hf_sccp_message_type,
{ "Message Type", "sccp.message_type",
FT_UINT8, BASE_HEX, VALS(sccp_message_type_values), 0x0,
NULL, HFILL}
},
{ &hf_sccp_variable_pointer1,
{ "Pointer to first Mandatory Variable parameter", "sccp.variable_pointer1",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sccp_variable_pointer2,
{ "Pointer to second Mandatory Variable parameter", "sccp.variable_pointer2",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sccp_variable_pointer3,
{ "Pointer to third Mandatory Variable parameter", "sccp.variable_pointer3",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sccp_optional_pointer,
{ "Pointer to Optional parameter", "sccp.optional_pointer",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sccp_param_length,
{ "Variable parameter length", "sccp.parameter_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sccp_ssn,
{ "Called or Calling SubSystem Number", "sccp.ssn",
FT_UINT8, BASE_DEC, VALS(sccp_ssn_values), 0x0,
NULL, HFILL}
},
{ &hf_sccp_gt_digits,
{ "Called or Calling GT Digits", "sccp.digits",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sccp_called_ansi_national_indicator,
{ "National Indicator", "sccp.called.ni",
FT_UINT8, BASE_HEX, VALS(sccp_ansi_national_indicator_values), ANSI_NATIONAL_MASK,
NULL, HFILL}
},
{ &hf_sccp_called_itu_natl_use_bit,
{ "Reserved for national use", "sccp.called.reserved",
FT_UINT8, BASE_HEX, NULL, ITU_RESERVED_MASK,
NULL, HFILL}
},
{ &hf_sccp_called_routing_indicator,
{ "Routing Indicator", "sccp.called.ri",
FT_UINT8, BASE_HEX, VALS(sccp_routing_indicator_values), ROUTING_INDICATOR_MASK,
NULL, HFILL}
},
{ &hf_sccp_called_itu_global_title_indicator,
{ "Global Title Indicator", "sccp.called.gti",
FT_UINT8, BASE_HEX, VALS(sccp_itu_global_title_indicator_values), GTI_MASK,
NULL, HFILL}
},
{ &hf_sccp_called_ansi_global_title_indicator,
{ "Global Title Indicator", "sccp.called.gti",
FT_UINT8, BASE_HEX, VALS(sccp_ansi_global_title_indicator_values), GTI_MASK,
NULL, HFILL}
},
{ &hf_sccp_called_itu_ssn_indicator,
{ "SubSystem Number Indicator", "sccp.called.ssni",
FT_UINT8, BASE_HEX, VALS(sccp_ai_ssni_values), ITU_SSN_INDICATOR_MASK,
NULL, HFILL}
},
{ &hf_sccp_called_itu_point_code_indicator,
{ "Point Code Indicator", "sccp.called.pci",
FT_UINT8, BASE_HEX, VALS(sccp_ai_pci_values), ITU_PC_INDICATOR_MASK,
NULL, HFILL}
},
{ &hf_sccp_called_ansi_ssn_indicator,
{ "SubSystem Number Indicator", "sccp.called.ssni",
FT_UINT8, BASE_HEX, VALS(sccp_ai_ssni_values), ANSI_SSN_INDICATOR_MASK,
NULL, HFILL}
},
{ &hf_sccp_called_ansi_point_code_indicator,
{ "Point Code Indicator", "sccp.called.pci",
FT_UINT8, BASE_HEX, VALS(sccp_ai_pci_values), ANSI_PC_INDICATOR_MASK,
NULL, HFILL}
},
{ &hf_sccp_called_ssn,
{ "SubSystem Number", "sccp.called.ssn",
FT_UINT8, BASE_DEC, VALS(sccp_ssn_values), 0x0,
NULL, HFILL}
},
{ &hf_sccp_called_itu_pc,
{ "PC", "sccp.called.pc",
FT_UINT16, BASE_DEC, NULL, ITU_PC_MASK,
NULL, HFILL}
},
{ &hf_sccp_called_ansi_pc,
{ "PC", "sccp.called.ansi_pc",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sccp_called_chinese_pc,
{ "PC", "sccp.called.chinese_pc",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sccp_called_japan_pc,
{ "PC", "sccp.called.pc",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sccp_called_pc_network,
{ "PC Network", "sccp.called.network",
FT_UINT24, BASE_DEC, NULL, ANSI_NETWORK_MASK,
NULL, HFILL }
},
{ &hf_sccp_called_pc_cluster,
{ "PC Cluster", "sccp.called.cluster",
FT_UINT24, BASE_DEC, NULL, ANSI_CLUSTER_MASK,
NULL, HFILL }
},
{ &hf_sccp_called_pc_member,
{ "PC Member", "sccp.called.member",
FT_UINT24, BASE_DEC, NULL, ANSI_MEMBER_MASK,
NULL, HFILL }
},
{ &hf_sccp_called_gt_nai,
{ "Nature of Address Indicator", "sccp.called.nai",
FT_UINT8, BASE_HEX, VALS(sccp_nai_values), GT_NAI_MASK,
NULL, HFILL }
},
{ &hf_sccp_called_gt_oe,
{ "Odd/Even Indicator", "sccp.called.oe",
FT_UINT8, BASE_HEX, VALS(sccp_oe_values), GT_OE_MASK,
NULL, HFILL }
},
{ &hf_sccp_called_gt_tt,
{ "Translation Type", "sccp.called.tt",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sccp_called_gt_np,
{ "Numbering Plan", "sccp.called.np",
FT_UINT8, BASE_HEX, VALS(sccp_np_values), GT_NP_MASK,
NULL, HFILL }
},
{ &hf_sccp_called_gt_es,
{ "Encoding Scheme", "sccp.called.es",
FT_UINT8, BASE_HEX, VALS(sccp_es_values), GT_ES_MASK,
NULL, HFILL }
},
{ &hf_sccp_called_gt_digits,
{ "Called Party Digits", "sccp.called.digits",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sccp_called_gt_digits_length,
{ "Number of Called Party Digits", "sccp.called.digits.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sccp_calling_ansi_national_indicator,
{ "National Indicator", "sccp.calling.ni",
FT_UINT8, BASE_HEX, VALS(sccp_ansi_national_indicator_values), ANSI_NATIONAL_MASK,
NULL, HFILL}
},
{ &hf_sccp_calling_itu_natl_use_bit,
{ "Reserved for national use", "sccp.calling.reserved",
FT_UINT8, BASE_HEX, NULL, ITU_RESERVED_MASK,
NULL, HFILL}
},
{ &hf_sccp_calling_routing_indicator,
{ "Routing Indicator", "sccp.calling.ri",
FT_UINT8, BASE_HEX, VALS(sccp_routing_indicator_values), ROUTING_INDICATOR_MASK,
NULL, HFILL}
},
{ &hf_sccp_calling_itu_global_title_indicator,
{ "Global Title Indicator", "sccp.calling.gti",
FT_UINT8, BASE_HEX, VALS(sccp_itu_global_title_indicator_values), GTI_MASK,
NULL, HFILL}
},
{ &hf_sccp_calling_ansi_global_title_indicator,
{ "Global Title Indicator", "sccp.calling.gti",
FT_UINT8, BASE_HEX, VALS(sccp_ansi_global_title_indicator_values), GTI_MASK,
NULL, HFILL}
},
{ &hf_sccp_calling_itu_ssn_indicator,
{ "SubSystem Number Indicator", "sccp.calling.ssni",
FT_UINT8, BASE_HEX, VALS(sccp_ai_ssni_values), ITU_SSN_INDICATOR_MASK,
NULL, HFILL}
},
{ &hf_sccp_calling_itu_point_code_indicator,
{ "Point Code Indicator", "sccp.calling.pci",
FT_UINT8, BASE_HEX, VALS(sccp_ai_pci_values), ITU_PC_INDICATOR_MASK,
NULL, HFILL}
},
{ &hf_sccp_calling_ansi_ssn_indicator,
{ "SubSystem Number Indicator", "sccp.calling.ssni",
FT_UINT8, BASE_HEX, VALS(sccp_ai_ssni_values), ANSI_SSN_INDICATOR_MASK,
NULL, HFILL}
},
{ &hf_sccp_calling_ansi_point_code_indicator,
{ "Point Code Indicator", "sccp.calling.pci",
FT_UINT8, BASE_HEX, VALS(sccp_ai_pci_values), ANSI_PC_INDICATOR_MASK,
NULL, HFILL}
},
{ &hf_sccp_calling_ssn,
{ "SubSystem Number", "sccp.calling.ssn",
FT_UINT8, BASE_DEC, VALS(sccp_ssn_values), 0x0,
NULL, HFILL}
},
{ &hf_sccp_calling_itu_pc,
{ "PC", "sccp.calling.pc",
FT_UINT16, BASE_DEC, NULL, ITU_PC_MASK,
NULL, HFILL}
},
{ &hf_sccp_calling_ansi_pc,
{ "PC", "sccp.calling.ansi_pc",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sccp_calling_chinese_pc,
{ "PC", "sccp.calling.chinese_pc",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sccp_calling_japan_pc,
{ "PC", "sccp.calling.pc",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sccp_calling_pc_network,
{ "PC Network", "sccp.calling.network",
FT_UINT24, BASE_DEC, NULL, ANSI_NETWORK_MASK,
NULL, HFILL }
},
{ &hf_sccp_calling_pc_cluster,
{ "PC Cluster", "sccp.calling.cluster",
FT_UINT24, BASE_DEC, NULL, ANSI_CLUSTER_MASK,
NULL, HFILL }
},
{ &hf_sccp_calling_pc_member,
{ "PC Member", "sccp.calling.member",
FT_UINT24, BASE_DEC, NULL, ANSI_MEMBER_MASK,
NULL, HFILL }
},
{ &hf_sccp_calling_gt_nai,
{ "Nature of Address Indicator", "sccp.calling.nai",
FT_UINT8, BASE_HEX, VALS(sccp_nai_values), GT_NAI_MASK,
NULL, HFILL }
},
{ &hf_sccp_calling_gt_oe,
{ "Odd/Even Indicator", "sccp.calling.oe",
FT_UINT8, BASE_HEX, VALS(sccp_oe_values), GT_OE_MASK,
NULL, HFILL }
},
{ &hf_sccp_calling_gt_tt,
{ "Translation Type", "sccp.calling.tt",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sccp_calling_gt_np,
{ "Numbering Plan", "sccp.calling.np",
FT_UINT8, BASE_HEX, VALS(sccp_np_values), GT_NP_MASK,
NULL, HFILL }
},
{ &hf_sccp_calling_gt_es,
{ "Encoding Scheme", "sccp.calling.es",
FT_UINT8, BASE_HEX, VALS(sccp_es_values), GT_ES_MASK,
NULL, HFILL }
},
{ &hf_sccp_calling_gt_digits,
{ "Calling Party Digits", "sccp.calling.digits",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sccp_calling_gt_digits_length,
{ "Number of Calling Party Digits", "sccp.calling.digits.length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_sccp_dlr,
{ "Destination Local Reference", "sccp.dlr",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sccp_slr,
{ "Source Local Reference", "sccp.slr",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sccp_lr,
{ "Local Reference", "sccp.lr",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sccp_class,
{ "Class", "sccp.class",
FT_UINT8, BASE_HEX, NULL, CLASS_CLASS_MASK,
NULL, HFILL}
},
{ &hf_sccp_handling,
{ "Message handling", "sccp.handling",
FT_UINT8, BASE_HEX, VALS(sccp_class_handling_values), CLASS_SPARE_HANDLING_MASK,
NULL, HFILL}
},
{ &hf_sccp_more,
{ "More data", "sccp.more",
FT_UINT8, BASE_HEX, VALS(sccp_segmenting_reassembling_values), SEGMENTING_REASSEMBLING_MASK,
NULL, HFILL}
},
{ &hf_sccp_rsn,
{ "Receive Sequence Number", "sccp.rsn",
FT_UINT8, BASE_HEX, NULL, RSN_MASK,
NULL, HFILL}
},
{ &hf_sccp_sequencing_segmenting_ssn,
{ "Sequencing Segmenting: Send Sequence Number", "sccp.sequencing_segmenting.ssn",
FT_UINT8, BASE_HEX, NULL, SEND_SEQUENCE_NUMBER_MASK,
NULL, HFILL}
},
{ &hf_sccp_sequencing_segmenting_rsn,
{ "Sequencing Segmenting: Receive Sequence Number", "sccp.sequencing_segmenting.rsn",
FT_UINT8, BASE_HEX, NULL, RECEIVE_SEQUENCE_NUMBER_MASK,
NULL, HFILL}
},
{ &hf_sccp_sequencing_segmenting_more,
{ "Sequencing Segmenting: More", "sccp.sequencing_segmenting.more",
FT_UINT8, BASE_HEX, VALS(sccp_segmenting_reassembling_values), SEQUENCING_SEGMENTING_MORE_MASK,
NULL, HFILL}
},
{ &hf_sccp_credit,
{ "Credit", "sccp.credit",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sccp_release_cause,
{ "Release Cause", "sccp.release_cause",
FT_UINT8, BASE_HEX, VALS(sccp_release_cause_values), 0x0,
NULL, HFILL}
},
{ &hf_sccp_return_cause,
{ "Return Cause", "sccp.return_cause",
FT_UINT8, BASE_HEX, VALS(sccp_return_cause_values), 0x0,
NULL, HFILL}
},
{ &hf_sccp_reset_cause,
{ "Reset Cause", "sccp.reset_cause",
FT_UINT8, BASE_HEX, VALS(sccp_reset_cause_values), 0x0,
NULL, HFILL}
},
{ &hf_sccp_error_cause,
{ "Error Cause", "sccp.error_cause",
FT_UINT8, BASE_HEX, VALS(sccp_error_cause_values), 0x0,
NULL, HFILL}
},
{ &hf_sccp_refusal_cause,
{ "Refusal Cause", "sccp.refusal_cause",
FT_UINT8, BASE_HEX, VALS(sccp_refusal_cause_values), 0x0,
NULL, HFILL}
},
{ &hf_sccp_segmentation_first,
{ "Segmentation: First", "sccp.segmentation.first",
FT_UINT8, BASE_HEX, VALS(sccp_segmentation_first_segment_values), SEGMENTATION_FIRST_SEGMENT_MASK,
NULL, HFILL}
},
{ &hf_sccp_segmentation_class,
{ "Segmentation: Class", "sccp.segmentation.class",
FT_UINT8, BASE_HEX, VALS(sccp_segmentation_class_values), SEGMENTATION_CLASS_MASK,
NULL, HFILL}
},
{ &hf_sccp_segmentation_remaining,
{ "Segmentation: Remaining", "sccp.segmentation.remaining",
FT_UINT8, BASE_HEX, NULL, SEGMENTATION_REMAINING_MASK,
NULL, HFILL}
},
{ &hf_sccp_segmentation_slr,
{ "Segmentation: Source Local Reference", "sccp.segmentation.slr",
FT_UINT24, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sccp_hop_counter,
{ "Hop Counter", "sccp.hops",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sccp_importance,
{ "Importance", "sccp.importance",
FT_UINT8, BASE_HEX, NULL, IMPORTANCE_IMPORTANCE_MASK,
NULL, HFILL}
},
{ &hf_sccp_ansi_isni_mi,
{ "ISNI Mark for Identification Indicator", "sccp.isni.mi",
FT_UINT8, BASE_HEX, VALS(sccp_isni_mark_for_id_values), ANSI_ISNI_MI_MASK,
NULL, HFILL}
},
{ &hf_sccp_ansi_isni_iri,
{ "ISNI Routing Indicator", "sccp.isni.iri",
FT_UINT8, BASE_HEX, VALS(sccp_isni_iri_values), ANSI_ISNI_IRI_MASK,
NULL, HFILL}
},
{ &hf_sccp_ansi_isni_ti,
{ "ISNI Type Indicator", "sccp.isni.ti",
FT_UINT8, BASE_HEX, VALS(sccp_isni_ti_values), ANSI_ISNI_TI_MASK,
NULL, HFILL}
},
{ &hf_sccp_ansi_isni_netspec,
{ "ISNI Network Specific (Type 1)", "sccp.isni.netspec",
FT_UINT8, BASE_HEX, NULL, ANSI_ISNI_NETSPEC_MASK,
NULL, HFILL}
},
{ &hf_sccp_ansi_isni_counter,
{ "ISNI Counter", "sccp.isni.counter",
FT_UINT8, BASE_DEC, NULL, ANSI_ISNI_COUNTER_MASK,
NULL, HFILL}
},
{ &hf_sccp_ansi_isni_network,
{ "Network ID network", "sccp.isni.network",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{ &hf_sccp_ansi_isni_cluster,
{ "Network ID cluster", "sccp.isni.cluster",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_sccp_xudt_msg_fragments,
{ "Message fragments", "sccp.msg.fragments",
FT_NONE, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{&hf_sccp_xudt_msg_fragment,
{ "Message fragment", "sccp.msg.fragment",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{&hf_sccp_xudt_msg_fragment_overlap,
{ "Message fragment overlap", "sccp.msg.fragment.overlap",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_sccp_xudt_msg_fragment_overlap_conflicts,
{ "Message fragment overlapping with conflicting data", "sccp.msg.fragment.overlap.conflicts",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_sccp_xudt_msg_fragment_multiple_tails,
{ "Message has multiple tail fragments", "sccp.msg.fragment.multiple_tails",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_sccp_xudt_msg_fragment_too_long_fragment,
{ "Message fragment too long", "sccp.msg.fragment.too_long_fragment",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{&hf_sccp_xudt_msg_fragment_error,
{ "Message defragmentation error", "sccp.msg.fragment.error",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{&hf_sccp_xudt_msg_fragment_count,
{ "Message fragment count", "sccp.msg.fragment.count",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{&hf_sccp_xudt_msg_reassembled_in,
{ "Reassembled in", "sccp.msg.reassembled.in",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{&hf_sccp_xudt_msg_reassembled_length,
{ "Reassembled SCCP length", "sccp.msg.reassembled.length",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_sccp_assoc_id,
{ "Association ID", "sccp.assoc.id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_sccp_assoc_msg,
{ "Message in frame", "sccp.assoc.msg",
FT_FRAMENUM, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
};
static gint *ett[] = {
&ett_sccp,
&ett_sccp_called,
&ett_sccp_called_ai,
&ett_sccp_called_pc,
&ett_sccp_called_gt,
&ett_sccp_called_gt_digits,
&ett_sccp_calling,
&ett_sccp_calling_ai,
&ett_sccp_calling_pc,
&ett_sccp_calling_gt,
&ett_sccp_calling_gt_digits,
&ett_sccp_sequencing_segmenting,
&ett_sccp_segmentation,
&ett_sccp_ansi_isni_routing_control,
&ett_sccp_xudt_msg_fragment,
&ett_sccp_xudt_msg_fragments,
&ett_sccp_assoc
};
static ei_register_info ei[] = {
{ &ei_sccp_wrong_length, { "sccp.wrong_length", PI_MALFORMED, PI_ERROR, "Wrong length indicated.", EXPFILL }},
{ &ei_sccp_international_standard_address, { "sccp.international_standard_address", PI_MALFORMED, PI_WARN,
"Address is coded to international standards. This doesn't normally happen in ANSI networks.", EXPFILL }},
{ &ei_sccp_no_ssn_present, { "sccp.ssn.not_present", PI_PROTOCOL, PI_WARN, "Message is routed on SSN, but SSN is not present", EXPFILL }},
{ &ei_sccp_ssn_zero, { "sccp.ssn.is_zero", PI_PROTOCOL, PI_WARN, "Message is routed on SSN, but SSN is zero (unspecified)", EXPFILL }},
{ &ei_sccp_class_unexpected, { "sccp.class_unexpected", PI_MALFORMED, PI_ERROR, "Unexpected message class for this message type", EXPFILL }},
{ &ei_sccp_handling_invalid, { "sccp.handling_invalid", PI_MALFORMED, PI_ERROR, "Invalid message handling", EXPFILL }},
{ &ei_sccp_gt_digits_missing, { "sccp.gt_digits_missing", PI_MALFORMED, PI_ERROR, "Address digits missing", EXPFILL }},
};
module_t *sccp_module;
expert_module_t* expert_sccp;
static uat_field_t users_flds[] = {
UAT_FLD_DEC(sccp_users, ni, "Network Indicator", "Network Indicator"),
UAT_FLD_RANGE(sccp_users, called_pc, "Called DPCs", 0xFFFFFF, "DPCs for which this protocol is to be used"),
UAT_FLD_RANGE(sccp_users, called_ssn, "Called SSNs", 255, "Called SSNs for which this protocol is to be used"),
UAT_FLD_VS(sccp_users, user, "User protocol", sccp_users_vals, "The User Protocol"),
UAT_END_FIELDS
};
uat_t *users_uat = uat_new("SCCP Users Table", sizeof(sccp_user_t),
"sccp_users", TRUE, &sccp_users,
&num_sccp_users, UAT_AFFECTS_DISSECTION,
"ChSccpUsers", sccp_users_copy_cb,
sccp_users_update_cb, sccp_users_free_cb,
NULL, users_flds );
proto_sccp = proto_register_protocol("Signalling Connection Control Part",
"SCCP", "sccp");
register_dissector("sccp", dissect_sccp, proto_sccp);
proto_register_field_array(proto_sccp, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_sccp = expert_register_protocol(proto_sccp);
expert_register_field_array(expert_sccp, ei, array_length(ei));
sccp_ssn_dissector_table = register_dissector_table("sccp.ssn", "SCCP SSN", FT_UINT8, BASE_DEC);
register_heur_dissector_list("sccp", &heur_subdissector_list);
sccp_module = prefs_register_protocol(proto_sccp, proto_reg_handoff_sccp);
prefs_register_uint_preference(sccp_module, "source_pc",
"Source PC (in hex)",
"The source point code (usually MSC) (to determine whether message is uplink or downlink)",
16, &sccp_source_pc_global);
prefs_register_bool_preference(sccp_module, "show_length", "Show length",
"Show parameter length in the protocol tree",
&sccp_show_length);
prefs_register_bool_preference(sccp_module, "defragment_xudt",
"Reassemble SCCP messages",
"Whether SCCP messages should be reassembled",
&sccp_reassemble);
prefs_register_bool_preference(sccp_module, "trace_sccp",
"Trace Associations",
"Whether to keep information about messages and their associations",
&trace_sccp);
prefs_register_bool_preference(sccp_module, "show_more_info",
"Show key parameters in Info Column",
"Show SLR, DLR, and CAUSE Parameters in the Information Column of the Summary",
&show_key_params);
prefs_register_uat_preference(sccp_module, "users_table", "Users Table",
"A table that enumerates user protocols to be used against specific PCs and SSNs",
users_uat);
prefs_register_bool_preference(sccp_module, "set_addresses", "Set source and destination GT addresses",
"Set the source and destination addresses to the GT digits (if RI=GT)."
" This may affect TCAP's ability to recognize which messages belong to which TCAP session.",
&set_addresses);
prefs_register_string_preference(sccp_module, "default_payload", "Default Payload",
"The protocol which should be used to dissect the payload if nothing else has claimed it",
&default_payload);
register_init_routine(&init_sccp);
assocs = wmem_tree_new_autoreset(wmem_epan_scope(), wmem_file_scope());
sccp_tap = register_tap("sccp");
}
void
proto_reg_handoff_sccp(void)
{
dissector_handle_t sccp_handle;
static gboolean initialised = FALSE;
if (!initialised) {
sccp_handle = find_dissector("sccp");
dissector_add_uint("wtap_encap", WTAP_ENCAP_SCCP, sccp_handle);
dissector_add_uint("mtp3.service_indicator", MTP_SI_SCCP, sccp_handle);
dissector_add_string("tali.opcode", "sccp", sccp_handle);
data_handle = find_dissector("data");
tcap_handle = find_dissector("tcap");
ranap_handle = find_dissector("ranap");
bssap_handle = find_dissector("bssap");
gsmmap_handle = find_dissector("gsm_map");
camel_handle = find_dissector("camel");
inap_handle = find_dissector("inap");
initialised = TRUE;
}
default_handle = find_dissector(default_payload);
}
