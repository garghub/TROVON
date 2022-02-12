static gint
fcels_equal(gconstpointer v, gconstpointer w)
{
const fcels_conv_key_t *v1 = (const fcels_conv_key_t *)v;
const fcels_conv_key_t *v2 = (const fcels_conv_key_t *)w;
return (v1->conv_idx == v2->conv_idx);
}
static guint
fcels_hash (gconstpointer v)
{
const fcels_conv_key_t *key = (const fcels_conv_key_t *)v;
guint val;
val = key->conv_idx;
return val;
}
static void
fcels_init_protocol(void)
{
fcels_req_hash = g_hash_table_new(fcels_hash, fcels_equal);
}
static void
fcels_cleanup_protocol(void)
{
g_hash_table_destroy(fcels_req_hash);
}
static void
dissect_cmnsvc (proto_tree *parent_tree, tvbuff_t *tvb, int offset, guint16 flags, guint8 opcode)
{
static const int * common_flags[] = {
&hf_fcels_cmn_cios,
&hf_fcels_cmn_rro,
&hf_fcels_cmn_vvv,
&hf_fcels_cmn_b2b,
&hf_fcels_cmn_multicast,
&hf_fcels_cmn_broadcast,
&hf_fcels_cmn_security,
&hf_fcels_cmn_clk,
&hf_fcels_cmn_dhd,
&hf_fcels_cmn_payload,
NULL
};
static const int * pflags[] = {
&hf_fcels_cmn_cios,
&hf_fcels_cmn_rro,
&hf_fcels_cmn_vvv,
&hf_fcels_cmn_b2b,
&hf_fcels_cmn_e_d_tov,
&hf_fcels_cmn_simplex,
&hf_fcels_cmn_multicast,
&hf_fcels_cmn_broadcast,
&hf_fcels_cmn_security,
&hf_fcels_cmn_clk,
&hf_fcels_cmn_dhd,
&hf_fcels_cmn_seqcnt,
&hf_fcels_cmn_payload,
NULL
};
if ((opcode == FC_ELS_PLOGI) || (opcode == FC_ELS_PDISC)) {
proto_tree_add_bitmask_value_with_flags(parent_tree, tvb, offset, hf_fcels_cmnfeatures,
ett_fcels_cmnfeatures, pflags, flags, 0);
} else {
proto_tree_add_bitmask_value_with_flags(parent_tree, tvb, offset, hf_fcels_cmnfeatures,
ett_fcels_cmnfeatures, common_flags, flags, 0);
}
}
static void
dissect_clssvc_flags (proto_tree *parent_tree, tvbuff_t *tvb, int offset, guint16 flags, guint8 opcode)
{
static const int * common_flags[] = {
&hf_fcels_cls_cns,
&hf_fcels_cls_prio,
NULL
};
static const int * pflags[] = {
&hf_fcels_cls_cns,
&hf_fcels_cls_sdr,
&hf_fcels_cls_prio,
&hf_fcels_cls_nzctl,
NULL
};
if ((opcode == FC_ELS_FLOGI) || (opcode == FC_ELS_FDISC)) {
proto_tree_add_bitmask_value_with_flags(parent_tree, tvb, offset, hf_fcels_clsflags,
ett_fcels_clsflags, pflags, flags, 0);
} else {
proto_tree_add_bitmask_value_with_flags(parent_tree, tvb, offset, hf_fcels_clsflags,
ett_fcels_clsflags, common_flags, flags, 0);
}
}
static void
dissect_fcp_flags (proto_tree *parent_tree, tvbuff_t *tvb, int offset, guint32 flags, guint8 isreq)
{
static const int * req_flags[] = {
&hf_fcels_fcpflags_trireq,
&hf_fcels_fcpflags_retry,
&hf_fcels_fcpflags_ccomp,
&hf_fcels_fcpflags_datao,
&hf_fcels_fcpflags_initiator,
&hf_fcels_fcpflags_target,
&hf_fcels_fcpflags_rdxr,
&hf_fcels_fcpflags_wrxr,
NULL
};
static const int * rep_flags[] = {
&hf_fcels_fcpflags_trirep,
&hf_fcels_fcpflags_retry,
&hf_fcels_fcpflags_ccomp,
&hf_fcels_fcpflags_datao,
&hf_fcels_fcpflags_initiator,
&hf_fcels_fcpflags_target,
&hf_fcels_fcpflags_rdxr,
&hf_fcels_fcpflags_wrxr,
NULL
};
if (isreq) {
proto_tree_add_bitmask_value_with_flags(parent_tree, tvb, offset, hf_fcels_fcpflags,
ett_fcels_fcpflags, req_flags, flags, BMT_NO_FALSE);
} else {
proto_tree_add_bitmask_value_with_flags(parent_tree, tvb, offset, hf_fcels_fcpflags,
ett_fcels_fcpflags, rep_flags, flags, BMT_NO_FALSE);
}
}
static void
dissect_speed_flags (proto_tree *parent_tree, tvbuff_t *tvb, int offset, guint32 flags, int port)
{
proto_item *item;
static const int * speed_flags[] = {
&hf_fcels_speedflags_1gb,
&hf_fcels_speedflags_2gb,
&hf_fcels_speedflags_4gb,
&hf_fcels_speedflags_10gb,
NULL
};
item = proto_tree_add_bitmask_value_with_flags(parent_tree, tvb, offset, hf_fcels_speedflags,
ett_fcels_speedflags, speed_flags, flags, BMT_NO_FALSE|BMT_NO_TFS);
proto_item_set_text(item, "Port Speed Capabilities (Port %u): 0x%04x", port, flags);
}
static void
dissect_prlilo_flags (proto_tree *parent_tree, tvbuff_t *tvb, int offset, int flags, guint8 opcode)
{
static const int * tprlo_flags[] = {
&hf_fcels_tprloflags_opav,
&hf_fcels_tprloflags_rpav,
&hf_fcels_tprloflags_npv,
&hf_fcels_tprloflags_gprlo,
NULL
};
static const int * prli_flags[] = {
&hf_fcels_prliloflags_opav,
&hf_fcels_tprloflags_rpav,
&hf_fcels_prliloflags_ipe,
NULL
};
static const int * not_prli_flags[] = {
&hf_fcels_prliloflags_opav,
&hf_fcels_tprloflags_rpav,
&hf_fcels_prliloflags_eip,
NULL
};
if (opcode == FC_ELS_TPRLO) {
proto_tree_add_bitmask_value_with_flags(parent_tree, tvb, offset, hf_fcels_prliloflags,
ett_fcels_prliloflags, tprlo_flags, flags, BMT_NO_FALSE|BMT_NO_TFS);
} else {
if (opcode == FC_ELS_PRLI) {
proto_tree_add_bitmask_value_with_flags(parent_tree, tvb, offset, hf_fcels_prliloflags,
ett_fcels_prliloflags, prli_flags, flags, BMT_NO_FALSE);
} else {
proto_tree_add_bitmask_value_with_flags(parent_tree, tvb, offset, hf_fcels_prliloflags,
ett_fcels_prliloflags, not_prli_flags, flags, BMT_NO_FALSE);
}
}
}
static void
dissect_initctl_flags (proto_tree *parent_tree, tvbuff_t *tvb, int offset, guint16 flags, guint8 opcode)
{
static const int * plogi_flags[] = {
&hf_fcels_initctl_initial_pa,
&hf_fcels_initctl_ack0,
&hf_fcels_initctl_ackgaa,
&hf_fcels_initctl_sync,
NULL
};
static const int * not_plogi_flags[] = {
&hf_fcels_initctl_sync,
NULL
};
if ((opcode == FC_ELS_PLOGI) || (opcode == FC_ELS_PDISC)) {
proto_tree_add_bitmask_value_with_flags(parent_tree, tvb, offset, hf_fcels_initctl,
ett_fcels_initctl, plogi_flags, flags, BMT_NO_FALSE);
} else {
proto_tree_add_bitmask_value_with_flags(parent_tree, tvb, offset, hf_fcels_initctl,
ett_fcels_initctl, not_plogi_flags, flags, BMT_NO_FALSE);
}
}
static void
dissect_rcptctl_flags (proto_tree *parent_tree, tvbuff_t *tvb, int offset, guint16 flags, guint8 opcode)
{
static const int * plogi_flags[] = {
&hf_fcels_rcptctl_ack0,
&hf_fcels_rcptctl_interlock,
&hf_fcels_rcptctl_policy,
&hf_fcels_rcptctl_category,
&hf_fcels_rcptctl_sync,
NULL
};
static const int * not_plogi_flags[] = {
&hf_fcels_rcptctl_sync,
NULL
};
if ((opcode == FC_ELS_PLOGI) || (opcode == FC_ELS_PDISC)) {
proto_tree_add_bitmask_value_with_flags(parent_tree, tvb, offset, hf_fcels_rcptctl,
ett_fcels_rcptctl, plogi_flags, flags, BMT_NO_FALSE);
} else {
proto_tree_add_bitmask_value_with_flags(parent_tree, tvb, offset, hf_fcels_rcptctl,
ett_fcels_rcptctl, not_plogi_flags, flags, BMT_NO_FALSE);
}
}
static void
dissect_fcels_logi (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
proto_item *ti, guint8 opcode)
{
int offset = 0,
svcvld = 0,
svcclass;
proto_tree *logi_tree, *cmnsvc_tree;
guint16 flag;
if (tree) {
logi_tree = proto_item_add_subtree (ti, ett_fcels_logi);
proto_tree_add_item (logi_tree, hf_fcels_opcode, tvb, offset, 1, ENC_BIG_ENDIAN);
cmnsvc_tree = proto_tree_add_subtree(logi_tree, tvb, offset+4, 16, ett_fcels_logi_cmnsvc, NULL, "Common Svc Parameters");
proto_tree_add_item (cmnsvc_tree, hf_fcels_b2b, tvb, offset+6, 2, ENC_BIG_ENDIAN);
flag = tvb_get_ntohs (tvb, offset+8);
if (flag & 0x0001) {
svcvld = 1;
}
dissect_cmnsvc (cmnsvc_tree, tvb, offset+8, flag, opcode);
proto_tree_add_item (cmnsvc_tree, hf_fcels_bbscnum, tvb, offset+10, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (cmnsvc_tree, hf_fcels_rcvsize, tvb, offset+10, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (cmnsvc_tree, hf_fcels_maxconseq, tvb, offset+12, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (cmnsvc_tree, hf_fcels_reloffset, tvb, offset+14, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (cmnsvc_tree, hf_fcels_edtov, tvb, offset+16, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (cmnsvc_tree, hf_fcels_npname, tvb, offset+20, 8, ENC_NA);
proto_tree_add_item (cmnsvc_tree, hf_fcels_fnname, tvb, offset+28, 8, ENC_NA);
offset = 36;
for (svcclass = 1; svcclass < 5; svcclass++) {
cmnsvc_tree = proto_tree_add_subtree_format(logi_tree, tvb, offset, 16,
ett_fcels_logi_cmnsvc, NULL, "Class %d Svc Parameters", svcclass);
flag = tvb_get_ntohs (tvb, offset);
dissect_clssvc_flags (cmnsvc_tree, tvb, offset, flag, opcode);
if (flag & 0x8000) {
flag = tvb_get_ntohs (tvb, offset+2);
dissect_initctl_flags (cmnsvc_tree, tvb, offset+2, flag, opcode);
flag = tvb_get_ntohs (tvb, offset+4);
dissect_rcptctl_flags (cmnsvc_tree, tvb, offset+4, flag, opcode);
proto_tree_add_item (cmnsvc_tree, hf_fcels_clsrcvsize, tvb,
offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (cmnsvc_tree, hf_fcels_conseq, tvb,
offset+8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (cmnsvc_tree, hf_fcels_e2e, tvb,
offset+10, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (cmnsvc_tree, hf_fcels_openseq, tvb,
offset+12, 2, ENC_BIG_ENDIAN);
}
offset += 16;
}
proto_tree_add_item (logi_tree, hf_fcels_vendorvers, tvb, offset, 16, ENC_NA);
if (svcvld) {
proto_tree_add_item (logi_tree, hf_fcels_svcavail, tvb, offset+32, 8, ENC_NA);
}
}
}
static void
dissect_fcels_plogi (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 isreq _U_, proto_item *ti)
{
dissect_fcels_logi (tvb, pinfo, tree, ti, FC_ELS_PLOGI);
}
static void
dissect_fcels_flogi (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 isreq _U_, proto_item *ti)
{
dissect_fcels_logi (tvb, pinfo, tree, ti, FC_ELS_FLOGI);
}
static void
dissect_fcels_logout (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint8 isreq, proto_item *ti)
{
int offset = 5;
proto_tree *logo_tree;
if (tree) {
logo_tree = proto_item_add_subtree (ti, ett_fcels_logo);
proto_tree_add_item (logo_tree, hf_fcels_opcode, tvb, offset-5, 1, ENC_BIG_ENDIAN);
if (!isreq) {
return;
}
proto_tree_add_item (logo_tree, hf_fcels_nportid, tvb, offset, 3, ENC_NA);
proto_tree_add_item (logo_tree, hf_fcels_npname, tvb, offset+3, 6, ENC_NA);
}
}
static void
dissect_fcels_abtx (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint8 isreq, proto_item *ti)
{
int offset = 0;
proto_tree *abtx_tree;
if (tree) {
abtx_tree = proto_item_add_subtree (ti, ett_fcels_abtx);
proto_tree_add_item (abtx_tree, hf_fcels_opcode, tvb, offset, 1, ENC_BIG_ENDIAN);
if (!isreq) {
return;
}
proto_tree_add_item(abtx_tree, hf_fcels_recovery_qualifier_status, tvb, offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (abtx_tree, hf_fcels_nportid, tvb, offset+5, 3, ENC_NA);
proto_tree_add_item (abtx_tree, hf_fcels_oxid, tvb, offset+8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (abtx_tree, hf_fcels_rxid, tvb, offset+10, 2, ENC_BIG_ENDIAN);
}
}
static void
dissect_fcels_rsi (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint8 isreq, proto_item *ti)
{
int offset = 4;
proto_tree *rsi_tree;
if (tree) {
rsi_tree = proto_item_add_subtree (ti, ett_fcels_rsi);
proto_tree_add_item (rsi_tree, hf_fcels_opcode, tvb, offset-4, 1, ENC_BIG_ENDIAN);
if (!isreq)
return;
proto_tree_add_item (rsi_tree, hf_fcels_recovqual, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (rsi_tree, hf_fcels_nportid, tvb, offset+1, 3, ENC_NA);
proto_tree_add_item (rsi_tree, hf_fcels_rxid, tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (rsi_tree, hf_fcels_oxid, tvb, offset+6, 2, ENC_BIG_ENDIAN);
}
}
static void
dissect_fcels_rrq (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint8 isreq, proto_item *ti)
{
int offset = 0;
proto_tree *rrq_tree;
if (tree) {
rrq_tree = proto_item_add_subtree (ti, ett_fcels_rrq);
proto_tree_add_item (rrq_tree, hf_fcels_opcode, tvb, offset, 1, ENC_BIG_ENDIAN);
if (!isreq)
return;
proto_tree_add_item (rrq_tree, hf_fcels_nportid, tvb, offset+5, 3, ENC_NA);
proto_tree_add_item (rrq_tree, hf_fcels_oxid, tvb, offset+8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (rrq_tree, hf_fcels_rxid, tvb, offset+10, 2, ENC_BIG_ENDIAN);
}
}
static void
dissect_fcels_rec (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint8 isreq, proto_item *ti)
{
int offset = 0;
proto_tree *rec_tree;
if (tree) {
rec_tree = proto_item_add_subtree (ti, ett_fcels_rec);
proto_tree_add_item (rec_tree, hf_fcels_opcode, tvb, offset, 1, ENC_BIG_ENDIAN);
if (isreq) {
proto_tree_add_item (rec_tree, hf_fcels_nportid, tvb,
offset+5, 3, ENC_NA);
proto_tree_add_item (rec_tree, hf_fcels_oxid, tvb,
offset+8, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (rec_tree, hf_fcels_rxid, tvb,
offset+10, 2, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item (rec_tree, hf_fcels_oxid, tvb,
offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (rec_tree, hf_fcels_rxid, tvb,
offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (rec_tree, hf_fcels_nportid, tvb,
offset+9, 3, ENC_NA);
proto_tree_add_item (rec_tree, hf_fcels_resportid, tvb,
offset+13, 3, ENC_NA);
proto_tree_add_item (rec_tree, hf_fcels_rec_fc4, tvb,
offset+16, 4, ENC_BIG_ENDIAN);
proto_tree_add_bitmask (rec_tree, tvb, offset+20, hf_fcels_estat,
ett_fcels_estat, hf_fcels_estat_fields,
ENC_BIG_ENDIAN);
}
}
}
static void
dissect_fcels_pdisc (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 isreq _U_, proto_item *ti)
{
dissect_fcels_logi (tvb, pinfo, tree, ti, FC_ELS_PDISC);
}
static void
dissect_fcels_fdisc (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 isreq _U_, proto_item *ti)
{
dissect_fcels_logi (tvb, pinfo, tree, ti, FC_ELS_FDISC);
}
static void
dissect_fcels_adisc (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint8 isreq _U_, proto_item *ti)
{
int offset = 5;
proto_tree *adisc_tree;
if (tree) {
adisc_tree = proto_item_add_subtree (ti, ett_fcels_adisc);
proto_tree_add_item (adisc_tree, hf_fcels_opcode, tvb, offset-5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (adisc_tree, hf_fcels_hardaddr, tvb, offset, 3, ENC_NA);
proto_tree_add_item (adisc_tree, hf_fcels_npname, tvb, offset+3, 8, ENC_NA);
proto_tree_add_item (adisc_tree, hf_fcels_fnname, tvb, offset+11, 8, ENC_NA);
proto_tree_add_item (adisc_tree, hf_fcels_nportid, tvb, offset+20, 3, ENC_NA);
}
}
static void
dissect_fcels_farp (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
proto_item *ti)
{
int offset = 4;
proto_tree *farp_tree;
if (tree) {
farp_tree = proto_item_add_subtree (ti, ett_fcels_farp);
proto_tree_add_item (farp_tree, hf_fcels_opcode, tvb, offset-4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (farp_tree, hf_fcels_farp_matchcodept,
tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (farp_tree, hf_fcels_nportid, tvb, offset+1,
3, ENC_NA);
proto_tree_add_item (farp_tree, hf_fcels_farp_respaction, tvb,
offset+4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (farp_tree, hf_fcels_resportid, tvb, offset+5,
3, ENC_NA);
proto_tree_add_item (farp_tree, hf_fcels_npname, tvb, offset+8, 8, ENC_NA);
proto_tree_add_item (farp_tree, hf_fcels_fnname, tvb, offset+16, 8, ENC_NA);
proto_tree_add_item (farp_tree, hf_fcels_respname, tvb, offset+24,
8, ENC_NA);
proto_tree_add_item (farp_tree, hf_fcels_respnname, tvb, offset+32,
8, ENC_NA);
proto_tree_add_item (farp_tree, hf_fcels_reqipaddr, tvb, offset+40,
16, ENC_NA);
proto_tree_add_item (farp_tree, hf_fcels_respipaddr, tvb, offset+56,
16, ENC_NA);
}
}
static void
dissect_fcels_farp_req (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 isreq _U_, proto_item *ti)
{
dissect_fcels_farp (tvb, pinfo, tree, ti);
}
static void
dissect_fcels_farp_rply (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 isreq _U_, proto_item *ti)
{
dissect_fcels_farp (tvb, pinfo, tree, ti);
}
static void
dissect_fcels_rps (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint8 isreq, proto_item *ti)
{
int offset = 3;
guint8 flag;
proto_tree *rps_tree;
flag = tvb_get_guint8 (tvb, offset);
if (tree) {
rps_tree = proto_item_add_subtree (ti, ett_fcels_rps);
if (isreq) {
proto_tree_add_item (rps_tree, hf_fcels_rps_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (rps_tree, hf_fcels_opcode, tvb, offset-3, 1, ENC_BIG_ENDIAN);
if (flag & 0x2) {
proto_tree_add_item (rps_tree, hf_fcels_npname, tvb, offset+1, 8, ENC_NA);
}
else if (flag & 0x1) {
proto_tree_add_item (rps_tree, hf_fcels_rps_portnum, tvb,
offset+5, 3, ENC_BIG_ENDIAN);
}
}
else {
proto_tree_add_item (rps_tree, hf_fcels_rps_flag, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (rps_tree, hf_fcels_rps_portstatus, tvb,
offset+3, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rps_tree, hf_fcels_link_failure_count, tvb, offset+5, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rps_tree, hf_fcels_loss_of_sync_count, tvb, offset+9, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rps_tree, hf_fcels_loss_of_signal_count, tvb, offset+13, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rps_tree, hf_fcels_primitive_seq_protocol_err, tvb, offset+17, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rps_tree, hf_fcels_invalid_xmission_word, tvb, offset+21, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rps_tree, hf_fcels_invalid_crc_count, tvb, offset+25, 4, ENC_BIG_ENDIAN);
if (flag & 0x01) {
proto_tree_add_item(rps_tree, hf_fcels_l_port_status, tvb, offset+31, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rps_tree, hf_fcels_lip_al_ps, tvb, offset+36, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rps_tree, hf_fcels_lip_f7_initiated_count, tvb, offset+37, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rps_tree, hf_fcels_lip_f7_received_count, tvb, offset+41, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rps_tree, hf_fcels_lip_f8_initiated_count, tvb, offset+45, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rps_tree, hf_fcels_lip_f8_received_count, tvb, offset+49, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rps_tree, hf_fcels_lip_reset_initiated_count, tvb, offset+53, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(rps_tree, hf_fcels_lip_reset_received_count, tvb, offset+57, 4, ENC_BIG_ENDIAN);
}
}
}
}
static void
dissect_fcels_rpl (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint8 isreq, proto_item *ti)
{
int offset = 0;
proto_tree *rpl_tree, *pb_tree;
int loop;
if (tree) {
rpl_tree = proto_item_add_subtree (ti, ett_fcels_rpl);
proto_tree_add_item (rpl_tree, hf_fcels_opcode, tvb, offset, 1, ENC_BIG_ENDIAN);
if (isreq) {
proto_tree_add_item(rpl_tree, hf_fcels_rpl_max_size, tvb, offset+6, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rpl_tree, hf_fcels_rpl_index, tvb, offset+9, 3, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_item(rpl_tree, hf_fcels_rpl_payload_length, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rpl_tree, hf_fcels_rpl_list_length, tvb, offset+5, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(rpl_tree, hf_fcels_rpl_index_of_i_port_block, tvb, offset+9, 3, ENC_BIG_ENDIAN);
offset = 12;
for (loop = tvb_get_ntoh24 (tvb, 5); loop > 0; loop--) {
pb_tree = proto_tree_add_subtree_format(rpl_tree, tvb, offset+12, 16,
ett_fcels_rplpb, NULL, "Port Block %u", loop);
proto_tree_add_item(pb_tree, hf_fcels_rpl_physical_port, tvb, offset, 4, ENC_BIG_ENDIAN);
proto_tree_add_item(pb_tree, hf_fcels_rpl_port_identifier, tvb, offset+5, 3, ENC_NA);
proto_tree_add_item(pb_tree, hf_fcels_rpl_port_name, tvb, offset+8, 8, ENC_NA);
offset += 16;
}
}
}
}
static void
dissect_fcels_fan (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint8 isreq _U_, proto_item *ti)
{
int offset = 5;
proto_tree *fan_tree;
if (tree) {
fan_tree = proto_item_add_subtree (ti, ett_fcels_fan);
proto_tree_add_item (fan_tree, hf_fcels_opcode, tvb, offset-5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (fan_tree, hf_fcels_fabricaddr, tvb, offset, 3, ENC_NA);
proto_tree_add_item (fan_tree, hf_fcels_fabricpname, tvb, offset+3,
8, ENC_NA);
proto_tree_add_item (fan_tree, hf_fcels_fnname, tvb, offset+11, 8, ENC_NA);
}
}
static void
dissect_fcels_rscn (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint8 isreq, proto_item *ti)
{
int offset = 1;
proto_tree *rscn_tree, *rectree;
int numrec, plen, i;
if (tree) {
rscn_tree = proto_item_add_subtree (ti, ett_fcels_rscn);
proto_tree_add_item (rscn_tree, hf_fcels_opcode, tvb, offset-1, 1, ENC_BIG_ENDIAN);
if (!isreq)
return;
proto_tree_add_item(rscn_tree, hf_fcels_rscn_page_len, tvb, offset, 1, ENC_BIG_ENDIAN);
plen = tvb_get_ntohs (tvb, offset+1);
proto_tree_add_item(rscn_tree, hf_fcels_rscn_payload_len, tvb, offset+1, 2, ENC_BIG_ENDIAN);
numrec = (plen - 4)/4;
offset = 4;
for (i = 0; i < numrec; i++) {
rectree = proto_tree_add_subtree_format(rscn_tree, tvb, offset, 4,
ett_fcels_rscn_rec, NULL, "Affected N_Port Page %u", i);
proto_tree_add_item (rectree, hf_fcels_rscn_evqual, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_item (rectree, hf_fcels_rscn_addrfmt, tvb, offset,
1, ENC_BIG_ENDIAN);
proto_tree_add_item (rectree, hf_fcels_rscn_domain, tvb, offset+1,
1, ENC_BIG_ENDIAN);
proto_tree_add_item (rectree, hf_fcels_rscn_area, tvb, offset+2,
1, ENC_BIG_ENDIAN);
proto_tree_add_item (rectree, hf_fcels_rscn_port, tvb, offset+3,
1, ENC_BIG_ENDIAN);
offset += 4;
}
}
}
static void
dissect_fcels_scr (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint8 isreq, proto_item *ti)
{
int offset = 7;
proto_tree *scr_tree;
if (tree) {
scr_tree = proto_item_add_subtree (ti, ett_fcels_scr);
proto_tree_add_item (scr_tree, hf_fcels_opcode, tvb, offset-7, 1, ENC_BIG_ENDIAN);
if (isreq)
proto_tree_add_item (scr_tree, hf_fcels_scrregn, tvb, offset, 1, ENC_BIG_ENDIAN);
}
}
static void
dissect_fcels_rnft (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint8 isreq, proto_item *ti)
{
int offset = 0;
guint16 numrec, i;
proto_tree *rnft_tree, *fc4_tree;
if (tree) {
rnft_tree = proto_item_add_subtree (ti, ett_fcels_rnft);
proto_tree_add_item (rnft_tree, hf_fcels_opcode, tvb, offset, 1, ENC_BIG_ENDIAN);
if (isreq) {
proto_tree_add_item(rnft_tree, hf_fcels_rnft_max_size, tvb, offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(rnft_tree, hf_fcels_rnft_index, tvb, offset+7, 1, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_item(rnft_tree, hf_fcels_rnft_payload_len, tvb, offset+2, 2, ENC_BIG_ENDIAN);
numrec = tvb_get_guint8 (tvb, offset+5);
proto_tree_add_item(rnft_tree, hf_fcels_rnft_list_length, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(rnft_tree, hf_fcels_rnft_index_of_first_rec_in_list, tvb, offset+7, 1, ENC_BIG_ENDIAN);
offset = 8;
for (i = 0; i < numrec; i++) {
fc4_tree = proto_tree_add_subtree_format(rnft_tree, tvb, offset, 4,
ett_fcels_rnft_fc4, NULL, "FC-4 Entry #%u", i);
proto_tree_add_item (fc4_tree, hf_fcels_rnft_fc4type, tvb,
offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fc4_tree, hf_fcels_rnft_fc4_qualifier, tvb, offset+1, 3, ENC_BIG_ENDIAN);
offset += 4;
}
}
}
}
static void
dissect_fcels_lsts (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint8 isreq, proto_item *ti)
{
int offset = 5;
proto_tree *lsts_tree;
if (tree) {
lsts_tree = proto_item_add_subtree (ti, ett_fcels_lsts);
proto_tree_add_item (lsts_tree, hf_fcels_opcode, tvb, offset-5, 1, ENC_BIG_ENDIAN);
if (isreq) {
return;
}
proto_tree_add_item (lsts_tree, hf_fcels_failedrcvr, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (lsts_tree, hf_fcels_flacompliance, tvb, offset+1,
1, ENC_BIG_ENDIAN);
proto_tree_add_item (lsts_tree, hf_fcels_loopstate, tvb, offset+2, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (lsts_tree, hf_fcels_publicloop_bmap, tvb, offset+3,
16, ENC_NA);
proto_tree_add_item (lsts_tree, hf_fcels_pvtloop_bmap, tvb, offset+19,
16, ENC_NA);
proto_tree_add_item (lsts_tree, hf_fcels_alpa_map, tvb, offset+35,
128, ENC_NA);
}
}
static void
dissect_fcels_prlilo_payload (tvbuff_t *tvb, packet_info *pinfo _U_,
guint8 isreq, proto_item *ti, guint8 opcode)
{
int offset = 0;
guint8 type;
proto_tree *prli_tree, *svcpg_tree;
int num_svcpg, payload_len, i, flag;
prli_tree = proto_item_add_subtree (ti, ett_fcels_prli);
proto_tree_add_item (prli_tree, hf_fcels_opcode, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(prli_tree, hf_fcels_prlilo_page_length, tvb, offset+1, 1, ENC_BIG_ENDIAN);
payload_len = tvb_get_ntohs (tvb, offset+2);
proto_tree_add_item(prli_tree, hf_fcels_prlilo_payload_length, tvb, offset+2, 2, ENC_BIG_ENDIAN);
num_svcpg = payload_len/16;
offset = 4;
for (i = 0; i < num_svcpg; i++) {
svcpg_tree = proto_tree_add_subtree_format(prli_tree, tvb, offset, 16,
ett_fcels_prli_svcpg, NULL, "Service Parameter Page %u", i);
type = tvb_get_guint8 (tvb, offset);
proto_tree_add_item(svcpg_tree, hf_fcels_prlilo_type, tvb, offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(svcpg_tree, hf_fcels_prlilo_type_code_extension, tvb, offset+1, 1, ENC_BIG_ENDIAN);
flag = tvb_get_guint8 (tvb, offset+2);
dissect_prlilo_flags (svcpg_tree, tvb, offset+2, flag, opcode);
if (!isreq && (opcode != FC_ELS_TPRLO)) {
proto_tree_add_item(svcpg_tree, hf_fcels_prlilo_response_code, tvb, offset+2, 1, ENC_BIG_ENDIAN);
}
if (opcode != FC_ELS_TPRLO) {
proto_tree_add_item(svcpg_tree, hf_fcels_prlilo_originator_pa, tvb, offset+4, 4, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_item(svcpg_tree, hf_fcels_prlilo_3rd_party_originator_pa, tvb, offset+4, 4, ENC_BIG_ENDIAN);
}
proto_tree_add_item(svcpg_tree, hf_fcels_prlilo_responder_pa, tvb, offset+8, 4, ENC_BIG_ENDIAN);
if (type == FC_TYPE_SCSI) {
flag = tvb_get_ntohs (tvb, offset+14);
dissect_fcp_flags (svcpg_tree, tvb, offset+12, flag, isreq);
}
else if ((opcode == FC_ELS_PRLI) && !isreq) {
proto_tree_add_item(svcpg_tree, hf_fcels_prlilo_service_parameter_response, tvb, offset+12, 4, ENC_BIG_ENDIAN);
}
else if (opcode == FC_ELS_TPRLO) {
proto_tree_add_item(svcpg_tree, hf_fcels_prlilo_3rd_party_n_port_id, tvb, offset+13, 3, ENC_NA);
}
}
}
static void
dissect_fcels_prli (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 isreq, proto_item *ti)
{
if (tree) {
dissect_fcels_prlilo_payload (tvb, pinfo, isreq, ti, FC_ELS_PRLI);
}
}
static void
dissect_fcels_prlo (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 isreq, proto_item *ti)
{
if (tree) {
dissect_fcels_prlilo_payload (tvb, pinfo, isreq, ti, FC_ELS_PRLO);
}
}
static void
dissect_fcels_tprlo (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
guint8 isreq, proto_item *ti)
{
if (tree) {
dissect_fcels_prlilo_payload (tvb, pinfo, isreq, ti, FC_ELS_TPRLO);
}
}
static void
dissect_fcels_lirr (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint8 isreq _U_, proto_item *ti)
{
int offset = 4;
proto_tree *lirr_tree;
guint8 lirr_fmt;
if (tree) {
lirr_tree = proto_item_add_subtree (ti, ett_fcels_lirr);
proto_tree_add_item (lirr_tree, hf_fcels_opcode, tvb, offset-4, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(lirr_tree, hf_fcels_lirr_regn_function, tvb, offset, 1, ENC_BIG_ENDIAN);
lirr_fmt = tvb_get_guint8 (tvb, offset+1);
if (!lirr_fmt) {
proto_tree_add_uint_format_value(lirr_tree, hf_fcels_lirr_regn_format, tvb, offset, 1, 0, "Common Format");
}
else {
proto_tree_add_item(lirr_tree, hf_fcels_lirr_regn_format, tvb, offset, 1, ENC_BIG_ENDIAN);
}
}
}
static void
dissect_fcels_srl (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint8 isreq, proto_item *ti)
{
int offset = 4;
proto_tree *srl_tree;
if (tree) {
srl_tree = proto_item_add_subtree (ti, ett_fcels_srl);
proto_tree_add_item (srl_tree, hf_fcels_opcode, tvb, offset-4, 1, ENC_BIG_ENDIAN);
if (!isreq)
return;
proto_tree_add_item(srl_tree, hf_fcels_srl_flag, tvb, offset, 1, ENC_NA);
proto_tree_add_item(srl_tree, hf_fcels_srl_fl_port_addr, tvb, offset+1, 3, ENC_NA);
}
}
static void
dissect_fcels_rpsc (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint8 isreq, proto_item *ti)
{
int offset = 2;
int num_entries, i, cap;
proto_tree *rpsc_tree;
if (tree) {
rpsc_tree = proto_item_add_subtree (ti, ett_fcels_rpsc);
proto_tree_add_item (rpsc_tree, hf_fcels_opcode, tvb, offset-2, 1, ENC_BIG_ENDIAN);
if (isreq)
return;
num_entries = tvb_get_ntohs (tvb, offset);
proto_tree_add_item(rpsc_tree, hf_fcels_rpsc_number_of_entries, tvb, offset, 2, ENC_BIG_ENDIAN);
offset = 4;
for (i = 0; i < num_entries; i++, offset+=4) {
cap = tvb_get_ntohs (tvb, offset);
dissect_speed_flags (rpsc_tree, tvb, offset, cap, i);
proto_tree_add_item(rpsc_tree, hf_fcels_rpsc_port_oper_speed, tvb, offset+2, 2, ENC_BIG_ENDIAN);
}
}
}
static void
dissect_fcels_cbind (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
proto_item *ti)
{
int offset = 0;
proto_tree *cbind_tree=NULL;
if (tree) {
cbind_tree = proto_item_add_subtree (ti, ett_fcels_cbind);
proto_tree_add_item (cbind_tree, hf_fcels_opcode, tvb, offset, 1, ENC_BIG_ENDIAN);
}
col_set_str(pinfo->cinfo, COL_INFO, "CBIND ");
proto_tree_add_item (cbind_tree, hf_fcels_cbind_liveness, tvb, offset+4, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (cbind_tree, hf_fcels_cbind_addr_mode, tvb, offset+6, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (cbind_tree, hf_fcels_cbind_ifcp_version, tvb, offset+7, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (cbind_tree, hf_fcels_cbind_userinfo, tvb, offset+8, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (cbind_tree, hf_fcels_cbind_snpname, tvb, offset+12, 8, ENC_NA);
proto_tree_add_item (cbind_tree, hf_fcels_cbind_dnpname, tvb, offset+20, 8, ENC_NA);
switch(tvb_reported_length(tvb)){
case 32:
col_append_str (pinfo->cinfo, COL_INFO, "Request");
break;
case 40:
col_append_str (pinfo->cinfo, COL_INFO, "Response");
proto_tree_add_item (cbind_tree, hf_fcels_cbind_status, tvb, offset+30, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (cbind_tree, hf_fcels_chandle, tvb, offset+34, 2, ENC_BIG_ENDIAN);
break;
}
}
static void
dissect_fcels_unbind (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
proto_item *ti)
{
int offset = 0;
proto_tree *cbind_tree=NULL;
if (tree) {
cbind_tree = proto_item_add_subtree (ti, ett_fcels_cbind);
proto_tree_add_item (cbind_tree, hf_fcels_opcode, tvb, offset, 1, ENC_BIG_ENDIAN);
}
col_set_str(pinfo->cinfo, COL_INFO, "UNBIND ");
proto_tree_add_item (cbind_tree, hf_fcels_cbind_userinfo, tvb, offset+4, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (cbind_tree, hf_fcels_chandle, tvb, offset+10, 2, ENC_BIG_ENDIAN);
switch(tvb_reported_length(tvb)){
case 24:
col_append_str (pinfo->cinfo, COL_INFO, "Request");
break;
case 28:
col_append_str (pinfo->cinfo, COL_INFO, "Response");
proto_tree_add_item (cbind_tree, hf_fcels_unbind_status, tvb, offset+22, 2, ENC_BIG_ENDIAN);
break;
}
}
static void
dissect_fcels_rnid (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint8 isreq, proto_item *ti)
{
int offset = 0;
int clen;
proto_tree *rnid_tree;
if (tree) {
rnid_tree = proto_item_add_subtree (ti, ett_fcels_rnid);
proto_tree_add_item (rnid_tree, hf_fcels_opcode, tvb, offset, 1, ENC_BIG_ENDIAN);
if (isreq) {
proto_tree_add_item (rnid_tree, hf_fcels_nodeidfmt, tvb, offset+4,
1, ENC_BIG_ENDIAN);
}
else {
proto_tree_add_item (rnid_tree, hf_fcels_nodeidfmt, tvb, offset+4,
1, ENC_BIG_ENDIAN);
clen = tvb_get_guint8 (tvb, offset+5);
proto_tree_add_item(rnid_tree, hf_fcels_common_identification_data_length, tvb, offset+5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (rnid_tree, hf_fcels_spidlen, tvb, offset+7,
1, ENC_BIG_ENDIAN);
if (clen) {
proto_tree_add_item (rnid_tree, hf_fcels_npname, tvb,
offset+8, 8, ENC_NA);
proto_tree_add_item (rnid_tree, hf_fcels_fnname, tvb,
offset+16, 8, ENC_NA);
}
if (tvb_get_guint8 (tvb, offset+4) == 0xDF) {
proto_tree_add_item (rnid_tree, hf_fcels_vendoruniq, tvb,
offset+24, 16, ENC_NA);
proto_tree_add_item (rnid_tree, hf_fcels_asstype, tvb,
offset+40, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (rnid_tree, hf_fcels_physport, tvb,
offset+44, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (rnid_tree, hf_fcels_attnodes, tvb,
offset+48, 4, ENC_BIG_ENDIAN);
proto_tree_add_item (rnid_tree, hf_fcels_nodemgmt, tvb,
offset+52, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (rnid_tree, hf_fcels_ipvers, tvb,
offset+53, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (rnid_tree, hf_fcels_tcpport, tvb,
offset+54, 2, ENC_BIG_ENDIAN);
proto_tree_add_item (rnid_tree, hf_fcels_ip, tvb, offset+56,
16, ENC_NA);
proto_tree_add_item (rnid_tree, hf_fcels_vendorsp, tvb,
offset+74, 2, ENC_BIG_ENDIAN);
}
}
}
}
static void
dissect_fcels_rlir (tvbuff_t *tvb _U_, packet_info *pinfo _U_,
proto_tree *tree, guint8 isreq _U_,
proto_item *ti _U_)
{
if (tree) {
}
}
static void
dissect_fcels_lsrjt (tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree,
guint8 isreq _U_, proto_item *ti)
{
int offset = 5;
proto_tree *lsrjt_tree;
if (tree) {
lsrjt_tree = proto_item_add_subtree (ti, ett_fcels_lsrjt);
proto_tree_add_item (lsrjt_tree, hf_fcels_opcode, tvb, offset-5, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (lsrjt_tree, hf_fcels_rjtcode, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (lsrjt_tree, hf_fcels_rjtdetcode, tvb, offset++, 1, ENC_BIG_ENDIAN);
proto_tree_add_item (lsrjt_tree, hf_fcels_vnduniq, tvb, offset, 1, ENC_BIG_ENDIAN);
}
}
static int
dissect_fcels (tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data)
{
proto_item *ti = NULL;
proto_tree *acc_tree;
guint8 isreq = FC_ELS_REQ;
int offset = 0;
guint8 opcode,
failed_opcode = 0;
conversation_t *conversation;
fcels_conv_data_t *cdata;
fcels_conv_key_t ckey, *req_key;
guint options;
address dstaddr;
guint8 addrdata[3];
fc_hdr *fchdr;
if (data == NULL)
return 0;
fchdr = (fc_hdr *)data;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "FC ELS");
opcode = tvb_get_guint8 (tvb, 0);
if (tree) {
ti = proto_tree_add_protocol_format (tree, proto_fcels, tvb, 0,
-1, "FC ELS");
}
if ((opcode != FC_ELS_LSRJT) && (opcode != FC_ELS_ACC)) {
if (opcode == FC_ELS_FLOGI) {
const guint8 *srcfc;
if (pinfo->src.type != AT_FC) {
expert_add_info_format(pinfo, ti, &ei_fcels_src_unknown,
"Unknown source address type: %u",
pinfo->src.type);
return 0;
}
srcfc = (const guint8 *)pinfo->src.data;
if (srcfc[2]) {
options = NO_PORT2;
}
else {
options = NO_PORT2 | NO_ADDR2;
}
}
else {
options = NO_PORT2;
}
conversation = find_conversation (pinfo->fd->num, &pinfo->dst, &pinfo->src,
pinfo->ptype, fchdr->oxid,
fchdr->rxid, options);
if (!conversation) {
conversation = conversation_new (pinfo->fd->num, &pinfo->dst, &pinfo->src,
pinfo->ptype, fchdr->oxid,
fchdr->rxid, options);
}
ckey.conv_idx = conversation->index;
cdata = (fcels_conv_data_t *)g_hash_table_lookup (fcels_req_hash,
&ckey);
if (cdata) {
cdata->opcode = opcode;
}
else {
req_key = wmem_new(wmem_file_scope(), fcels_conv_key_t);
req_key->conv_idx = conversation->index;
cdata = wmem_new(wmem_file_scope(), fcels_conv_data_t);
cdata->opcode = opcode;
g_hash_table_insert (fcels_req_hash, req_key, cdata);
}
}
else {
isreq = FC_ELS_RPLY;
options = NO_PORT2;
conversation = find_conversation (pinfo->fd->num, &pinfo->dst, &pinfo->src,
pinfo->ptype, fchdr->oxid,
fchdr->rxid, options);
if (!conversation) {
const guint8 *dstfc;
if (pinfo->dst.type != AT_FC) {
expert_add_info_format(pinfo, ti, &ei_fcels_dst_unknown,
"Unknown destination address type: %u",
pinfo->dst.type);
return 0;
}
dstfc = (const guint8 *)pinfo->dst.data;
addrdata[0] = addrdata[1] = 0;
addrdata[2] = dstfc[2];
SET_ADDRESS (&dstaddr, AT_FC, 3, addrdata);
conversation = find_conversation (pinfo->fd->num, &dstaddr, &pinfo->src,
pinfo->ptype, fchdr->oxid,
fchdr->rxid, options);
}
if (!conversation) {
options = NO_ADDR2 | NO_PORT2;
conversation = find_conversation (pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, fchdr->oxid,
fchdr->rxid, options);
if (!conversation) {
if (tree && (opcode == FC_ELS_ACC)) {
acc_tree = proto_item_add_subtree (ti, ett_fcels_acc);
proto_tree_add_expert(acc_tree, pinfo, &ei_fcels_no_record_of_exchange, tvb, offset, -1);
return 0;
}
failed_opcode = 0;
}
}
if (conversation) {
ckey.conv_idx = conversation->index;
cdata = (fcels_conv_data_t *)g_hash_table_lookup (fcels_req_hash, &ckey);
if (cdata != NULL) {
if ((options & NO_ADDR2) && (cdata->opcode != FC_ELS_FLOGI)) {
if (tree && (opcode == FC_ELS_ACC)) {
acc_tree = proto_item_add_subtree (ti,
ett_fcels_acc);
proto_tree_add_expert(acc_tree, pinfo, &ei_fcels_no_record_of_exchange, tvb, offset, -1);
return 0;
}
}
if (opcode == FC_ELS_ACC)
opcode = cdata->opcode;
else
failed_opcode = cdata->opcode;
}
if (tree) {
if ((cdata == NULL) && (opcode != FC_ELS_LSRJT)) {
acc_tree = proto_item_add_subtree (ti, ett_fcels_acc);
proto_tree_add_expert(acc_tree, pinfo, &ei_fcels_no_record_of_els_req, tvb, offset, -1);
return 0;
}
}
}
}
if (isreq == FC_ELS_REQ) {
col_add_str (pinfo->cinfo, COL_INFO,
val_to_str_ext (opcode, &fc_els_proto_val_ext, "0x%x"));
}
else if (opcode == FC_ELS_LSRJT) {
col_add_fstr (pinfo->cinfo, COL_INFO, "LS_RJT (%s)",
val_to_str_ext (failed_opcode, &fc_els_proto_val_ext, "0x%x"));
}
else {
col_add_fstr (pinfo->cinfo, COL_INFO, "ACC (%s)",
val_to_str_ext (opcode, &fc_els_proto_val_ext, "0x%x"));
}
switch (opcode) {
case FC_ELS_LSRJT:
dissect_fcels_lsrjt (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_PLOGI:
dissect_fcels_plogi (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_FLOGI:
dissect_fcels_flogi (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_LOGOUT:
dissect_fcels_logout (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_ABTX:
dissect_fcels_abtx (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_RSI:
dissect_fcels_rsi (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_RRQ:
dissect_fcels_rrq (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_REC:
dissect_fcels_rec (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_PRLI:
dissect_fcels_prli (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_PRLO:
dissect_fcels_prlo (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_TPRLO:
dissect_fcels_tprlo (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_PDISC:
dissect_fcels_pdisc (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_FDISC:
dissect_fcels_fdisc (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_ADISC:
dissect_fcels_adisc (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_FARP_REQ:
dissect_fcels_farp_req (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_FARP_RPLY:
dissect_fcels_farp_rply (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_RPS:
dissect_fcels_rps (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_RPL:
dissect_fcels_rpl (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_FAN:
dissect_fcels_fan (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_RSCN:
dissect_fcels_rscn (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_SCR:
dissect_fcels_scr (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_RNFT:
dissect_fcels_rnft (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_LSTS:
dissect_fcels_lsts (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_RNID:
dissect_fcels_rnid (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_RLIR:
dissect_fcels_rlir (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_LIRR:
dissect_fcels_lirr (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_SRL:
dissect_fcels_srl (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_RPSC:
dissect_fcels_rpsc (tvb, pinfo, tree, isreq, ti);
break;
case FC_ELS_AUTH:
if (isreq && fcsp_handle)
call_dissector (fcsp_handle, tvb, pinfo, tree);
break;
case FC_ELS_CBIND:
dissect_fcels_cbind (tvb, pinfo, tree, ti);
break;
case FC_ELS_UNBIND:
dissect_fcels_unbind (tvb, pinfo, tree, ti);
break;
default:
call_dissector (data_handle, tvb, pinfo, tree);
break;
}
return tvb_reported_length(tvb);
}
void
proto_register_fcels (void)
{
static hf_register_info hf[] = {
{ &hf_fcels_opcode,
{"Cmd Code", "fcels.opcode", FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&fc_els_proto_val_ext, 0x0, NULL, HFILL}},
{ &hf_fcels_rjtcode,
{"Reason Code", "fcels.rjt.reason", FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&fc_els_rjt_val_ext, 0x0, NULL, HFILL}},
{ &hf_fcels_rjtdetcode,
{"Reason Explanation", "fcels.rjt.detail", FT_UINT8, BASE_HEX | BASE_EXT_STRING,
&fc_els_rjt_det_val_ext, 0x0, NULL, HFILL}},
{ &hf_fcels_vnduniq,
{"Vendor Unique", "fcels.rjt.vnduniq", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL}},
{ &hf_fcels_b2b,
{"B2B Credit", "fcels.logi.b2b", FT_UINT8, BASE_DEC, NULL, 0x0, NULL,
HFILL}},
{ &hf_fcels_cmnfeatures,
{"Common Svc Parameters", "fcels.logi.cmnfeatures", FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL}},
{ &hf_fcels_bbscnum,
{"BB_SC Number", "fcels.logi.bbscnum", FT_UINT8, BASE_DEC, NULL, 0xF0, NULL,
HFILL}},
{ &hf_fcels_rcvsize,
{"Receive Size", "fcels.logi.rcvsize", FT_UINT16, BASE_DEC, NULL, 0x0FFF, NULL,
HFILL}},
{ &hf_fcels_maxconseq,
{"Max Concurrent Seq", "fcels.logi.maxconseq", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL}},
{ &hf_fcels_reloffset,
{"Relative Offset By Info Cat", "fcels.logi.reloff", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_edtov,
{"E_D_TOV", "fcels.edtov", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_npname,
{"N_Port Port_Name", "fcels.npname", FT_FCWWN, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcels_fnname,
{"Fabric/Node Name", "fcels.fnname", FT_FCWWN, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
#if 0
{ &hf_fcels_cls1param,
{"Class 1 Svc Param", "fcels.logi.cls1param", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcels_cls2param,
{"Class 2 Svc Param", "fcels.logi.cls2param", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcels_cls3param,
{"Class 3 Svc Param", "fcels.logi.cls3param", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcels_cls4param,
{"Class 4 Svc Param", "fcels.logi.cls4param", FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
#endif
{ &hf_fcels_vendorvers,
{"Vendor Version", "fcels.logi.vendvers", FT_BYTES, BASE_NONE, NULL, 0x0, NULL,
HFILL}},
{ &hf_fcels_svcavail,
{"Services Availability", "fcels.logi.svcavail", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_fcels_clsflags,
{"Service Options", "fcels.logi.clsflags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL,
HFILL}},
{ &hf_fcels_clsrcvsize,
{"Class Recv Size", "fcels.logi.clsrcvsize", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL}},
{ &hf_fcels_conseq,
{"Total Concurrent Seq", "fcels.logi.totconseq", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL}},
{ &hf_fcels_e2e,
{"End2End Credit", "fcels.logi.e2e", FT_UINT16, BASE_DEC, NULL, 0x0, NULL,
HFILL}},
{ &hf_fcels_openseq,
{"Open Seq Per Exchg", "fcels.logi.openseq", FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcels_nportid,
{"Originator S_ID", "fcels.portid", FT_BYTES, SEP_DOT, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcels_oxid,
{"OXID", "fcels.oxid", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_rxid,
{"RXID", "fcels.rxid", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_recovqual,
{"Recovery Qualifier", "fcels.rcovqual", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL}},
{ &hf_fcels_fabricaddr,
{"Fabric Address", "fcels.faddr", FT_BYTES, SEP_DOT, NULL, 0x0, NULL,
HFILL}},
{ &hf_fcels_fabricpname,
{"Fabric Port Name", "fcels.fpname", FT_FCWWN, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcels_failedrcvr,
{"Failed Receiver AL_PA", "fcels.faildrcvr", FT_UINT8, BASE_HEX, NULL,
0x0, NULL, HFILL}},
{ &hf_fcels_flacompliance,
{"FC-FLA Compliance", "fcels.flacompliance", FT_UINT8, BASE_HEX,
VALS (fc_els_flacompliance_val), 0x0, NULL, HFILL}},
{ &hf_fcels_loopstate,
{"Loop State", "fcels.loopstate", FT_UINT8, BASE_HEX,
VALS (fc_els_loopstate_val), 0x0, NULL, HFILL}},
{ &hf_fcels_publicloop_bmap,
{"Public Loop Device Bitmap", "fcels.pubdev_bmap", FT_BYTES, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_pvtloop_bmap,
{"Private Loop Device Bitmap", "fcels.pvtdev_bmap", FT_BYTES,
BASE_NONE, NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_alpa_map,
{"AL_PA Map", "fcels.alpa", FT_BYTES, BASE_NONE, NULL, 0x0, NULL,
HFILL}},
{ &hf_fcels_scrregn,
{"Registration Function", "fcels.scr.regn", FT_UINT8, BASE_HEX,
VALS (fc_els_scr_reg_val), 0x0, NULL, HFILL}},
{ &hf_fcels_farp_matchcodept,
{"Match Address Code Points", "fcels.matchcp", FT_UINT8, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_farp_respaction,
{"Responder Action", "fcels.respaction", FT_UINT8, BASE_HEX,
VALS (fc_els_farp_respaction_val), 0x0, NULL, HFILL}},
{ &hf_fcels_resportid,
{"Responding Port ID", "fcels.resportid", FT_BYTES, SEP_DOT,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_respname,
{"Responding Port Name", "fcels.respname", FT_FCWWN, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_respnname,
{"Responding Node Name", "fcels.respnname", FT_FCWWN, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_reqipaddr,
{"Requesting IP Address", "fcels.reqipaddr", FT_IPv6, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_respipaddr,
{"Responding IP Address", "fcels.respipaddr", FT_IPv6, BASE_NONE,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_hardaddr,
{"Hard Address of Originator", "fcels.hrdaddr", FT_BYTES, SEP_DOT,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_rps_flag,
{"Flag", "fcels.flag", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_rps_portnum,
{"Physical Port Number", "fcels.portnum", FT_UINT32, BASE_HEX, NULL,
0x0, NULL, HFILL}},
{ &hf_fcels_rps_portstatus,
{"Port Status", "fcels.portstatus", FT_UINT16, BASE_HEX | BASE_EXT_STRING,
&fc_els_portstatus_val_ext, 0x0, NULL, HFILL}},
{ &hf_fcels_rnft_fc4type,
{"FC-4 Type", "fcels.rnft.fc4type", FT_UINT8, BASE_HEX,
VALS (fc_fc4_val), 0x0, NULL, HFILL}},
{ &hf_fcels_rscn_evqual,
{"Event Qualifier", "fcels.rscn.evqual", FT_UINT8, BASE_HEX,
VALS (fc_els_rscn_evqual_val), 0x3C, NULL, HFILL}},
{ &hf_fcels_rscn_addrfmt,
{"Address Format", "fcels.rscn.addrfmt", FT_UINT8, BASE_HEX,
VALS (fc_els_rscn_addrfmt_val), 0x03, NULL, HFILL}},
{ &hf_fcels_rscn_domain,
{"Affected Domain", "fcels.rscn.domain", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_rscn_area,
{"Affected Area", "fcels.rscn.area", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_rscn_port,
{"Affected Port", "fcels.rscn.port", FT_UINT8, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_rec_fc4,
{"FC4 value", "fcels.rec.fc4value", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_estat,
{"Exchange Status", "fcels.estat", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_estat_resp,
{"Sequence Responder", "fcels.estat.resp", FT_BOOLEAN, 32,
TFS(&tfs_fcels_estat_resp),
FC_ESB_ST_RESP, "Seq responder?", HFILL}},
{ &hf_fcels_estat_seq_init,
{"Sequence Initiative", "fcels.estat.seq_init", FT_BOOLEAN, 32,
TFS(&tfs_fcels_estat_seq_init),
FC_ESB_ST_SEQ_INIT, "Responder has Sequence Initiative?", HFILL}},
{ &hf_fcels_estat_compl,
{"Exchange Complete", "fcels.estat.complete", FT_BOOLEAN, 32,
TFS(&tfs_complete_incomplete),
FC_ESB_ST_COMPLETE, "Exchange complete?", HFILL}},
{ &hf_fcels_nodeidfmt,
{"Node Identification Format", "fcels.rnid.nodeidfmt", FT_UINT8,
BASE_HEX, VALS (fc_els_nodeid_val), 0x0, NULL, HFILL}},
{ &hf_fcels_spidlen,
{"Specific Id Length", "fcels.rnid.spidlen", FT_UINT8, BASE_DEC, NULL,
0x0, NULL, HFILL}},
{ &hf_fcels_vendoruniq,
{"Vendor Unique", "fcels.rnid.vendoruniq", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_fcels_vendorsp,
{"Vendor Specific", "fcels.rnid.vendorsp", FT_UINT16, BASE_HEX, NULL,
0x0, NULL, HFILL}},
{ &hf_fcels_asstype,
{"Associated Type", "fcels.rnid.asstype", FT_UINT32, BASE_HEX | BASE_EXT_STRING,
&fc_els_rnid_asstype_val_ext, 0x0, NULL, HFILL}},
{ &hf_fcels_physport,
{"Physical Port Number", "fcels.rnid.physport", FT_UINT32, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_attnodes,
{"Number of Attached Nodes", "fcels.rnid.attnodes", FT_UINT32,
BASE_HEX, NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_nodemgmt,
{"Node Management", "fcels.rnid.nodemgmt", FT_UINT8, BASE_HEX,
VALS (fc_els_rnid_mgmt_val), 0x0, NULL, HFILL}},
{ &hf_fcels_ipvers,
{"IP Version", "fcels.rnid.ipvers", FT_UINT8, BASE_HEX,
VALS (fc_els_rnid_ipvers_val), 0x0, NULL, HFILL}},
{ &hf_fcels_tcpport,
{"TCP/UDP Port Number", "fcels.rnid.tcpport", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_ip,
{"IP Address", "fcels.rnid.ip", FT_IPv6, BASE_NONE, NULL, 0x0, NULL,
HFILL}},
{ &hf_fcels_cbind_liveness,
{"Liveness Test Interval", "fcels.cbind.liveness", FT_UINT16, BASE_DEC,
NULL, 0x0, "Liveness Test Interval in seconds", HFILL}},
{ &hf_fcels_cbind_addr_mode,
{"Addressing Mode", "fcels.cbind.addr_mode", FT_UINT8, BASE_HEX,
VALS (cbind_addr_mode_vals), 0x0, NULL, HFILL}},
{ &hf_fcels_cbind_ifcp_version,
{"iFCP version", "fcels.cbind.ifcp_version", FT_UINT8, BASE_DEC,
NULL, 0x0, "Version of iFCP protocol", HFILL}},
{ &hf_fcels_cbind_userinfo,
{"UserInfo", "fcels.cbind.userinfo", FT_UINT32, BASE_HEX,
NULL, 0x0, "Userinfo token", HFILL}},
{ &hf_fcels_cbind_snpname,
{"Source N_Port Port_Name", "fcels.cbind.snpname", FT_FCWWN, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcels_cbind_dnpname,
{"Destination N_Port Port_Name", "fcels.cbind.dnpname", FT_FCWWN, BASE_NONE, NULL, 0x0,
NULL, HFILL}},
{ &hf_fcels_cbind_status,
{"Status", "fcels.cbind.status", FT_UINT16, BASE_DEC,
VALS (cbind_status_vals), 0x0, "Cbind status", HFILL}},
{ &hf_fcels_chandle,
{"Connection Handle", "fcels.cbind.handle", FT_UINT16, BASE_HEX,
NULL, 0x0, "Cbind/Unbind connection handle", HFILL}},
{ &hf_fcels_unbind_status,
{"Status", "fcels.unbind.status", FT_UINT16, BASE_DEC,
VALS (unbind_status_vals), 0x0, "Unbind status", HFILL}},
{ &hf_fcels_cmn_cios,
{"Cont. Incr. Offset Supported", "fcels.cmn.cios", FT_BOOLEAN, 16,
TFS(&tfs_supported_not_supported), 0x8000, NULL, HFILL}},
{ &hf_fcels_cmn_rro,
{"RRO Supported", "fcels.cmn.rro", FT_BOOLEAN, 16,
TFS(&tfs_supported_not_supported), 0x4000, NULL, HFILL}},
{ &hf_fcels_cmn_vvv,
{"Valid Vendor Version", "fcels.cmn.vvv", FT_BOOLEAN, 16,
TFS(&tfs_valid_invalid), 0x2000, NULL, HFILL}},
{ &hf_fcels_cmn_b2b,
{"B2B Credit Mgmt", "fcels.cmn.bbb", FT_BOOLEAN, 16,
TFS(&tfs_fc_fcels_cmn_b2b), 0x0800, NULL, HFILL}},
{ &hf_fcels_cmn_e_d_tov,
{"E_D_TOV", "fcels.cmn.e_d_tov", FT_BOOLEAN, 16,
TFS(&tfs_fc_fcels_cmn_e_d_tov), 0x0400, NULL, HFILL}},
{ &hf_fcels_cmn_simplex,
{"Simplex", "fcels.cmn.simplex", FT_BOOLEAN, 16,
TFS(&tfs_supported_not_supported), 0x0040, NULL, HFILL}},
{ &hf_fcels_cmn_multicast,
{"Multicast", "fcels.cmn.multicast", FT_BOOLEAN, 16,
TFS(&tfs_supported_not_supported), 0x0200, NULL, HFILL}},
{ &hf_fcels_cmn_broadcast,
{"Broadcast", "fcels.cmn.broadcast", FT_BOOLEAN, 16,
TFS(&tfs_supported_not_supported), 0x0100, NULL, HFILL}},
{ &hf_fcels_cmn_security,
{"Security", "fcels.cmn.security", FT_BOOLEAN, 16,
TFS(&tfs_set_notset), 0x0020, NULL, HFILL}},
{ &hf_fcels_cmn_clk,
{"Clk Sync", "fcels.cmn.clk", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), 0x0010, NULL, HFILL}},
{ &hf_fcels_cmn_dhd,
{"DHD Capable", "fcels.cmn.dhd", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), 0x0004, NULL, HFILL}},
{ &hf_fcels_cmn_seqcnt,
{"SEQCNT", "fcels.cmn.seqcnt", FT_BOOLEAN, 16,
TFS(&tfs_fc_fcels_cmn_seqcnt), 0x0002, NULL, HFILL}},
{ &hf_fcels_cmn_payload,
{"Payload Len", "fcels.cmn.payload", FT_BOOLEAN, 16,
TFS(&tfs_fc_fcels_cmn_payload), 0x0001, NULL, HFILL}},
{ &hf_fcels_cls_cns,
{"Class Supported", "fcels.cls.cns", FT_BOOLEAN, 16,
TFS(&tfs_supported_not_supported), 0x8000, NULL, HFILL}},
{ &hf_fcels_cls_sdr,
{"Delivery Mode", "fcels.cls.sdr", FT_BOOLEAN, 16,
TFS(&tfs_fc_fcels_cls_sdr), 0x0800, NULL, HFILL}},
{ &hf_fcels_cls_prio,
{"Priority", "fcels.cls.prio", FT_BOOLEAN, 16,
TFS(&tfs_supported_not_supported), 0x0080, NULL, HFILL}},
{ &hf_fcels_cls_nzctl,
{"Non-zero CS_CTL", "fcels.cls.nzctl", FT_BOOLEAN, 16,
TFS(&tfs_fc_fcels_cls_nzctl), 0x0040, NULL, HFILL}},
{ &hf_fcels_initctl,
{"Initiator Ctl", "fcels.logi.initctl", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_initctl_initial_pa,
{"Initial P_A", "fcels.logi.initctl.initial_pa", FT_UINT16, BASE_HEX,
VALS (initial_pa_vals), 0x3000, NULL, HFILL}},
{ &hf_fcels_initctl_ack0,
{"ACK0 Capable", "fcels.logi.initctl.ack0", FT_BOOLEAN, 16,
TFS(&tfs_capable_not_capable), 0x0800, NULL, HFILL}},
{ &hf_fcels_initctl_ackgaa,
{"ACK GAA", "fcels.logi.initctl.ackgaa", FT_BOOLEAN, 16,
TFS(&tfs_fc_fcels_initctl_ackgaa), 0x0200, NULL, HFILL}},
{ &hf_fcels_initctl_sync,
{"Clock Sync", "fcels.logi.initctl.sync", FT_BOOLEAN, 16,
TFS(&tfs_supported_not_supported), 0x0010, NULL, HFILL}},
{ &hf_fcels_rcptctl,
{"Recipient Ctl", "fcels.logi.rcptctl", FT_UINT16, BASE_HEX,
NULL, 0x0, NULL, HFILL}},
{ &hf_fcels_rcptctl_ack0,
{"ACK0", "fcels.logi.rcptctl.ack", FT_BOOLEAN, 16,
TFS(&tfs_supported_not_supported), 0x8000, NULL, HFILL}},
{ &hf_fcels_rcptctl_interlock,
{"X_ID Interlock", "fcels.logi.rcptctl.interlock", FT_BOOLEAN, 16,
TFS(&tfs_requested_not_requested), 0x2000, NULL, HFILL}},
{ &hf_fcels_rcptctl_policy,
{"Policy", "fcels.logi.rcptctl.policy", FT_UINT16, BASE_HEX,
VALS (rcptctl_policy_vals), 0x1800, NULL, HFILL}},
{ &hf_fcels_rcptctl_category,
{"Category", "fcels.logi.rcptctl.category", FT_UINT16, BASE_HEX,
VALS (rcptctl_category_vals), 0x0030, NULL, HFILL}},
{ &hf_fcels_rcptctl_sync,
{"Clock Sync", "fcels.logi.rcptctl.sync", FT_BOOLEAN, 16,
TFS(&tfs_supported_not_supported), 0x0008, NULL, HFILL}},
{ &hf_fcels_fcpflags,
{"FCP Flags", "fcels.fcpflags", FT_UINT32, BASE_HEX, NULL, 0x0, NULL,
HFILL}},
{ &hf_fcels_fcpflags_trireq,
{"Task Retry Ident", "fcels.fcpflags.trireq", FT_BOOLEAN, 32,
TFS(&tfs_requested_not_requested), 1 << 9, NULL, HFILL}},
{ &hf_fcels_fcpflags_trirep,
{"Task Retry Ident", "fcels.fcpflags.trirep", FT_BOOLEAN, 32,
TFS(&tfs_accepted_not_accepted), 1 << 9, NULL, HFILL}},
{ &hf_fcels_fcpflags_retry,
{"Retry", "fcels.fcpflags.retry", FT_BOOLEAN, 32,
TFS(&tfs_fc_fcels_fcpflags_retry), 1 << 8, NULL, HFILL}},
{ &hf_fcels_fcpflags_ccomp,
{"Comp", "fcels.fcpflags.ccomp", FT_BOOLEAN, 32,
TFS(&tfs_fc_fcels_fcpflags_ccomp), 0x0080, NULL, HFILL}},
{ &hf_fcels_fcpflags_datao,
{"Data Overlay", "fcels.fcpflags.datao", FT_BOOLEAN, 32,
TFS(&tfs_fc_fcels_fcpflags_datao), 0x0040, NULL, HFILL}},
{ &hf_fcels_fcpflags_initiator,
{"Initiator", "fcels.fcpflags.initiator", FT_BOOLEAN, 32,
TFS(&tfs_fc_fcels_fcpflags_initiator), 0x0020, NULL, HFILL}},
{ &hf_fcels_fcpflags_target,
{"Target", "fcels.fcpflags.target", FT_BOOLEAN, 32,
TFS(&tfs_fc_fcels_fcpflags_target), 0x0010, NULL, HFILL}},
{ &hf_fcels_fcpflags_rdxr,
{"Rd Xfer_Rdy Dis", "fcels.fcpflags.rdxr", FT_BOOLEAN, 32,
TFS(&tfs_fc_fcels_fcpflags_rdxr), 0x0002, NULL, HFILL}},
{ &hf_fcels_fcpflags_wrxr,
{"Wr Xfer_Rdy Dis", "fcels.fcpflags.wrxr", FT_BOOLEAN, 32,
TFS(&tfs_fc_fcels_fcpflags_wrxr), 0x0001, NULL, HFILL}},
{ &hf_fcels_prliloflags,
{"PRLILO Flags", "fcels.prliloflags", FT_UINT8, BASE_HEX, NULL, 0x0, NULL,
HFILL}},
{ &hf_fcels_tprloflags_opav,
{"3rd Party Orig PA Valid", "fcels.tprloflags.opav", FT_BOOLEAN, 8,
TFS(&tfs_valid_not_valid), 0x80, NULL, HFILL}},
{ &hf_fcels_tprloflags_rpav,
{"Resp PA Valid", "fcels.tprloflags.rpav", FT_BOOLEAN, 8,
TFS(&tfs_valid_not_valid), 0x40, NULL, HFILL}},
{ &hf_fcels_tprloflags_npv,
{"3rd Party N_Port Valid", "fcels.tprloflags.npv", FT_BOOLEAN, 8,
TFS(&tfs_valid_not_valid), 0x20, NULL, HFILL}},
{ &hf_fcels_tprloflags_gprlo,
{"Global PRLO", "fcels.tprloflags.gprlo", FT_BOOLEAN, 8,
TFS(&tfs_fc_fcels_tprloflags_gprlo), 0x10, NULL, HFILL}},
{ &hf_fcels_speedflags,
{"Port Speed Capabilities", "fcels.speedflags", FT_UINT16, BASE_HEX, NULL, 0x0, NULL,
HFILL}},
{ &hf_fcels_speedflags_1gb,
{"1Gb Support", "fcels.speedflags.1gb", FT_BOOLEAN, 16,
TFS(&tfs_supported_not_supported), 0x8000, NULL, HFILL}},
{ &hf_fcels_speedflags_2gb,
{"2Gb Support", "fcels.speedflags.2gb", FT_BOOLEAN, 16,
TFS(&tfs_supported_not_supported), 0x4000, NULL, HFILL}},
{ &hf_fcels_speedflags_4gb,
{"4Gb Support", "fcels.speedflags.4gb", FT_BOOLEAN, 16,
TFS(&tfs_supported_not_supported), 0x2000, NULL, HFILL}},
{ &hf_fcels_speedflags_10gb,
{"10Gb Support", "fcels.speedflags.10gb", FT_BOOLEAN, 16,
TFS(&tfs_supported_not_supported), 0x1000, NULL, HFILL}},
{ &hf_fcels_prliloflags_opav,
{"Orig PA Valid", "fcels.prliloflags.opav", FT_BOOLEAN, 8,
TFS(&tfs_valid_not_valid), 0x80, NULL, HFILL}},
{ &hf_fcels_prliloflags_ipe,
{"Image Pair Estd", "fcels.prliloflags.ipe", FT_BOOLEAN, 8,
TFS(&tfs_fc_fcels_prliloflags_ipe), 0x20, NULL, HFILL}},
{ &hf_fcels_prliloflags_eip,
{"Est Image Pair", "fcels.prliloflags.eip", FT_BOOLEAN, 8,
TFS(&tfs_fc_fcels_prliloflags_eip), 0x20, NULL, HFILL}},
{ &hf_fcels_recovery_qualifier_status, { "Recovery Qualifier Status", "fcels.recovery_qualifier_status", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_link_failure_count, { "Link Failure Count", "fcels.link_failure_count", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_loss_of_sync_count, { "Loss of Sync Count", "fcels.loss_of_sync_count", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_loss_of_signal_count, { "Loss of Signal Count", "fcels.loss_of_signal_count", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_primitive_seq_protocol_err, { "Primitive Seq Protocol Err", "fcels.primitive_seq_protocol_err", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_invalid_xmission_word, { "Invalid Xmission Word", "fcels.invalid_xmission_word", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_invalid_crc_count, { "Invalid CRC Count", "fcels.invalid_crc_count", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_l_port_status, { "L_Port Status", "fcels.l_port_status", FT_UINT16, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_lip_al_ps, { "LIP AL_PS", "fcels.lip.al_ps", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_lip_f7_initiated_count, { "LIP F7 Initiated Count", "fcels.lip.f7_initiated_count", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_lip_f7_received_count, { "LIP F7 Received Count", "fcels.lip.f7_received_count", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_lip_f8_initiated_count, { "LIP F8 Initiated Count", "fcels.lip.f8_initiated_count", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_lip_f8_received_count, { "LIP F8 Received Count", "fcels.lip.f8_received_count", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_lip_reset_initiated_count, { "LIP Reset Initiated Count", "fcels.lip.reset_initiated_count", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_lip_reset_received_count, { "LIP Reset Received Count", "fcels.lip.reset_received_count", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_rpl_max_size, { "Max Size", "fcels.rpl.max_size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_rpl_index, { "Index", "fcels.rpl.index", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_rpl_payload_length, { "Payload Length", "fcels.rpl.payload_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_rpl_list_length, { "List Length", "fcels.rpl.list_length", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_rpl_index_of_i_port_block, { "Index of I Port Block", "fcels.rpl.index_of_i_port_block", FT_UINT24, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_rpl_physical_port, { "Physical Port #", "fcels.rpl.physical_port", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_rpl_port_identifier, { "Port Identifier", "fcels.rpl.port_identifier", FT_BYTES, SEP_DOT, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_rpl_port_name, { "Port Name", "fcels.rpl.port_name", FT_FCWWN, BASE_NONE, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_rscn_page_len, { "Page Len", "fcels.rscn.page_len", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_rscn_payload_len, { "Payload Len", "fcels.rscn.payload_len", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_rnft_max_size, { "Max Size", "fcels.rnft.max_size", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_rnft_index, { "Index", "fcels.rnft.index", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_rnft_payload_len, { "Payload Len", "fcels.rnft.payload_len", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_rnft_list_length, { "List Length", "fcels.rnft.list_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_rnft_index_of_first_rec_in_list, { "Index of First Rec in List", "fcels.rnft.index_of_first_rec_in_list", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_rnft_fc4_qualifier, { "FC-4 Qualifier", "fcels.rnft.fc_4_qualifier", FT_UINT24, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_prlilo_page_length, { "Page Length", "fcels.prlilo.page_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_prlilo_payload_length, { "Payload Length", "fcels.prlilo.payload_length", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_prlilo_type, { "TYPE", "fcels.prlilo.type", FT_UINT8, BASE_DEC, VALS(fc_prli_fc4_val), 0x0, NULL, HFILL }},
{ &hf_fcels_prlilo_type_code_extension, { "TYPE Code Extension", "fcels.prlilo.type_code_extension", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_prlilo_response_code, { "Response Code", "fcels.prlilo.response_code", FT_UINT8, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_prlilo_originator_pa, { "Originator PA", "fcels.prlilo.originator_pa", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_prlilo_3rd_party_originator_pa, { "3rd Party Originator PA", "fcels.prlilo.3rd_party_originator_pa", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_prlilo_responder_pa, { "Responder PA", "fcels.prlilo.responder_pa", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_prlilo_service_parameter_response, { "Service Parameter Response", "fcels.prlilo.service_parameter_response", FT_UINT32, BASE_HEX, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_prlilo_3rd_party_n_port_id, { "3rd Party N_Port Id", "fcels.prlilo.3rd_party_n_port_id", FT_BYTES, SEP_DOT, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_lirr_regn_function, { "Regn. Function", "fcels.lirr.regn_function", FT_UINT8, BASE_HEX, VALS(fc_els_lirr_regfunc_val), 0x0, NULL, HFILL }},
{ &hf_fcels_lirr_regn_format, { "Regn. Format", "fcels.lirr.regn_format", FT_UINT8, BASE_HEX, VALS(fc_fc4_val), 0x0, NULL, HFILL }},
{ &hf_fcels_srl_flag, { "Flag", "fcels.srl.flag", FT_BOOLEAN, 8, TFS(&tfs_srl_flag), 0x01, NULL, HFILL }},
{ &hf_fcels_srl_fl_port_addr, { "FL_Port Addr", "fcels.srl.fl_port_addr", FT_BYTES, SEP_DOT, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_rpsc_number_of_entries, { "Number of Entries", "fcels.rpsc.number_of_entries", FT_UINT16, BASE_DEC, NULL, 0x0, NULL, HFILL }},
{ &hf_fcels_rpsc_port_oper_speed, { "Port Oper Speed", "fcels.rpsc.port_oper_speed", FT_UINT16, BASE_HEX, VALS(fc_els_portspeed_val), 0x0, NULL, HFILL }},
{ &hf_fcels_common_identification_data_length, { "Common Identification Data Length", "fcels.common_identification_data_length", FT_UINT8, BASE_DEC, NULL, 0x0, NULL, HFILL }},
};
static gint *ett[] = {
&ett_fcels,
&ett_fcels_lsrjt,
&ett_fcels_acc,
&ett_fcels_logi,
&ett_fcels_logi_cmnsvc,
&ett_fcels_logi_clssvc,
&ett_fcels_logo,
&ett_fcels_abtx,
&ett_fcels_rsi,
&ett_fcels_rrq,
&ett_fcels_rec,
&ett_fcels_prli,
&ett_fcels_prli_svcpg,
&ett_fcels_adisc,
&ett_fcels_farp,
&ett_fcels_rps,
&ett_fcels_rpl,
&ett_fcels_rplpb,
&ett_fcels_fan,
&ett_fcels_rscn,
&ett_fcels_rscn_rec,
&ett_fcels_estat,
&ett_fcels_scr,
&ett_fcels_rnft,
&ett_fcels_rnft_fc4,
&ett_fcels_lsts,
&ett_fcels_rnid,
&ett_fcels_rlir,
&ett_fcels_lirr,
&ett_fcels_srl,
&ett_fcels_rpsc,
&ett_fcels_cbind,
&ett_fcels_cmnfeatures,
&ett_fcels_clsflags,
&ett_fcels_initctl,
&ett_fcels_rcptctl,
&ett_fcels_fcpflags,
&ett_fcels_prliloflags,
&ett_fcels_speedflags,
};
static ei_register_info ei[] = {
{ &ei_fcels_src_unknown, { "fcels.src.type.unknown", PI_PROTOCOL, PI_WARN, "Unknown source address type", EXPFILL }},
{ &ei_fcels_dst_unknown, { "fcels.dst.type.unknown", PI_PROTOCOL, PI_WARN, "Unknown destination address type", EXPFILL }},
{ &ei_fcels_no_record_of_exchange, { "fcels.no_record_of_exchange", PI_UNDECODED, PI_WARN, "No record of Exchange. Unable to decode ACC", EXPFILL }},
{ &ei_fcels_no_record_of_els_req, { "fcels.no_record_of_els_req", PI_UNDECODED, PI_WARN, "No record of ELS Req. Unable to decode ACC", EXPFILL }},
};
expert_module_t* expert_fcels;
proto_fcels = proto_register_protocol("FC Extended Link Svc", "FC ELS", "fcels");
proto_register_field_array(proto_fcels, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
expert_fcels = expert_register_protocol(proto_fcels);
expert_register_field_array(expert_fcels, ei, array_length(ei));
register_init_routine (&fcels_init_protocol);
register_cleanup_routine (&fcels_cleanup_protocol);
}
void
proto_reg_handoff_fcels (void)
{
dissector_handle_t els_handle;
els_handle = new_create_dissector_handle (dissect_fcels, proto_fcels);
dissector_add_uint("fc.ftype", FC_FTYPE_ELS, els_handle);
data_handle = find_dissector ("data");
fcsp_handle = find_dissector ("fcsp");
}
