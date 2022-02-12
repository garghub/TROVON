static proto_item *
proto_tree_add_mpls_label(proto_tree *pdutree, tvbuff_t *tvb, int offset, int length, int level)
{
proto_item *ti;
if( length == 3) {
guint8 b0 = tvb_get_guint8(tvb, offset);
guint8 b1 = tvb_get_guint8(tvb, offset + 1);
guint8 b2 = tvb_get_guint8(tvb, offset + 2);
ti = proto_tree_add_text(pdutree, tvb, offset, length,
"MPLS-Label%d: %u exp-bits: %u %s", level,
((b0<<12)+(b1<<4)+(b2>>4)),
((b2>>1)&0x7),
((b2&0x1)?"top-of-stack":""));
} else {
ti = proto_tree_add_text(pdutree, tvb, offset, length,
"MPLS-Label%d: bad length %d", level, length);
}
return ti;
}
static void
nbar_fmt_id(gchar *result, guint32 nbar_id)
{
guint32 nbar_id_type = (nbar_id>>24)&0xFF;
nbar_id &= 0xFFFFFF;
g_snprintf(result, ITEM_LABEL_LENGTH,
"NBAR Application ID: %d:%d (type:id)", nbar_id_type, nbar_id);
}
static int
pen_to_type_hf_list (guint32 pen) {
switch (pen) {
case VENDOR_PLIXER:
return TF_PLIXER;
case VENDOR_NTOP:
return TF_NTOP;
default:
return TF_NO_VENDOR_INFO;
}
}
static int
dissect_netflow(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *netflow_tree = NULL;
proto_tree *ti;
proto_item *timeitem, *pduitem;
proto_tree *timetree, *pdutree;
unsigned int pduret, ver, pdus, x;
hdrinfo_t hdrinfo;
gint flow_len = -1;
guint available, pdusize, offset = 0;
nstime_t ts;
dissect_pdu_t *pduptr;
ipfix_debug0("dissect_netflow: start");
ver = tvb_get_ntohs(tvb, offset);
ipfix_debug1("dissect_netflow: found version %d", ver);
switch (ver) {
case 1:
pdusize = V1PDU_SIZE;
pduptr = &dissect_pdu;
break;
case 5:
pdusize = V5PDU_SIZE;
pduptr = &dissect_pdu;
break;
case 7:
pdusize = V7PDU_SIZE;
pduptr = &dissect_pdu;
break;
case 8:
pdusize = -1;
pduptr = &dissect_v8_aggpdu;
break;
case 9:
case 10:
pdusize = -1;
pduptr = &dissect_v9_v10_flowset;
break;
default:
return 0;
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "CFLOW");
col_clear(pinfo->cinfo, COL_INFO);
ipfix_debug0("dissect_netflow: column cleared");
if (tree) {
ti = proto_tree_add_item(tree, proto_netflow, tvb, offset, -1, ENC_NA);
netflow_tree = proto_item_add_subtree(ti, ett_netflow);
}
ipfix_debug0("dissect_netflow: tree added");
hdrinfo.vspec = ver;
hdrinfo.src_id = 0;
if (tree)
proto_tree_add_uint(netflow_tree, hf_cflow_version, tvb, offset, 2, ver);
offset += 2;
pdus = tvb_get_ntohs(tvb, offset);
if (tree) {
if(ver == 10) {
proto_tree_add_uint(netflow_tree, hf_cflow_len, tvb, offset, 2, pdus);
flow_len = pdus;
} else {
proto_tree_add_uint(netflow_tree, hf_cflow_count, tvb, offset, 2, pdus);
flow_len = -1;
}
}
offset += 2;
if (check_col(pinfo->cinfo, COL_INFO)) {
if (ver == 9) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"total: %u (v%u) record%s", pdus, ver,
plurality(pdus, "", "s"));
} else if (ver == 10) {
gint remaining = tvb_reported_length_remaining(tvb, offset)+4;
if(remaining == flow_len)
col_add_fstr(pinfo->cinfo, COL_INFO, "IPFIX flow (%d bytes)", flow_len);
else
col_add_fstr(pinfo->cinfo, COL_INFO,
"IPFIX partial flow (%u/%u bytes)",
remaining, flow_len);
} else {
col_add_fstr(pinfo->cinfo, COL_INFO,
"total: %u (v%u) flow%s", pdus, ver,
plurality(pdus, "", "s"));
}
}
if ( (ver != 9) && (ver != 10) && !tree )
return tvb_reported_length(tvb);
if(ver != 10) {
proto_tree_add_item(netflow_tree, hf_cflow_sysuptime, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
ts.secs = tvb_get_ntohl(tvb, offset);
hdrinfo.export_time_secs = ts.secs;
if ((ver != 9) && (ver != 10)) {
ts.nsecs = tvb_get_ntohl(tvb, offset + 4);
timeitem = proto_tree_add_time(netflow_tree,
hf_cflow_timestamp, tvb, offset,
8, &ts);
} else {
ts.nsecs = 0;
timeitem = proto_tree_add_time(netflow_tree,
hf_cflow_timestamp, tvb, offset,
4, &ts);
}
timetree = proto_item_add_subtree(timeitem, ett_unixtime);
proto_tree_add_item(timetree,
(ver == 10) ? hf_cflow_exporttime : hf_cflow_unix_secs,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
if ((ver != 9) && (ver != 10)) {
proto_tree_add_item(timetree, hf_cflow_unix_nsecs, tvb,
offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
if (ver == 5 || ver == 7 || ver == 8 || ver == 9 || ver == 10) {
proto_tree_add_item(netflow_tree, hf_cflow_sequence,
tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
}
if (ver == 5 || ver == 8) {
proto_tree_add_item(netflow_tree, hf_cflow_engine_type,
tvb, offset++, 1, ENC_NA);
proto_tree_add_item(netflow_tree, hf_cflow_engine_id,
tvb, offset++, 1, ENC_NA);
} else if ((ver == 9) || (ver == 10)) {
proto_tree_add_item(netflow_tree,
(ver == 9) ? hf_cflow_source_id : hf_cflow_od_id,
tvb, offset, 4, ENC_BIG_ENDIAN);
hdrinfo.src_id = tvb_get_ntohl(tvb, offset);
offset += 4;
}
if (ver == 8) {
hdrinfo.vspec = tvb_get_guint8(tvb, offset);
switch (hdrinfo.vspec) {
case V8PDU_AS_METHOD:
pdusize = V8PDU_AS_SIZE;
break;
case V8PDU_PROTO_METHOD:
pdusize = V8PDU_PROTO_SIZE;
break;
case V8PDU_SPREFIX_METHOD:
pdusize = V8PDU_SPREFIX_SIZE;
break;
case V8PDU_DPREFIX_METHOD:
pdusize = V8PDU_DPREFIX_SIZE;
break;
case V8PDU_MATRIX_METHOD:
pdusize = V8PDU_MATRIX_SIZE;
break;
case V8PDU_DESTONLY_METHOD:
pdusize = V8PDU_DESTONLY_SIZE;
pduptr = &dissect_v8_flowpdu;
break;
case V8PDU_SRCDEST_METHOD:
pdusize = V8PDU_SRCDEST_SIZE;
pduptr = &dissect_v8_flowpdu;
break;
case V8PDU_FULL_METHOD:
pdusize = V8PDU_FULL_SIZE;
pduptr = &dissect_v8_flowpdu;
break;
case V8PDU_TOSAS_METHOD:
pdusize = V8PDU_TOSAS_SIZE;
break;
case V8PDU_TOSPROTOPORT_METHOD:
pdusize = V8PDU_TOSPROTOPORT_SIZE;
break;
case V8PDU_TOSSRCPREFIX_METHOD:
pdusize = V8PDU_TOSSRCPREFIX_SIZE;
break;
case V8PDU_TOSDSTPREFIX_METHOD:
pdusize = V8PDU_TOSDSTPREFIX_SIZE;
break;
case V8PDU_TOSMATRIX_METHOD:
pdusize = V8PDU_TOSMATRIX_SIZE;
break;
case V8PDU_PREPORTPROTOCOL_METHOD:
pdusize = V8PDU_PREPORTPROTOCOL_SIZE;
break;
default:
pdusize = -1;
hdrinfo.vspec = 0;
break;
}
proto_tree_add_uint(netflow_tree, hf_cflow_aggmethod,
tvb, offset++, 1, hdrinfo.vspec);
proto_tree_add_item(netflow_tree, hf_cflow_aggversion,
tvb, offset++, 1, ENC_NA);
}
if (ver == 7 || ver == 8)
offset = flow_process_textfield(netflow_tree, tvb, offset, 4, "reserved");
else if (ver == 5) {
proto_tree_add_item(netflow_tree, hf_cflow_samplingmode,
tvb, offset, 2, ENC_BIG_ENDIAN);
proto_tree_add_item(netflow_tree, hf_cflow_samplerate,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
if (pdus == 0) {
proto_tree_add_text(netflow_tree, tvb, offset, tvb_reported_length_remaining(tvb, offset),
"FlowSets impossible - PDU Count is %d", pdus);
return tvb_reported_length(tvb);
}
available = tvb_reported_length_remaining(tvb, offset);
for (x = 1; ((ver != 10) && (x < pdus + 1)) || ((ver == 10) && ((available - pdusize) > 0)); x++) {
available = tvb_reported_length_remaining(tvb, offset);
if(((ver == 9) || (ver == 10)) && available >= 4) {
pdusize = tvb_get_ntohs(tvb, offset + 2);
}
if (available < pdusize)
break;
if ((ver == 9) || (ver == 10)) {
pduitem = proto_tree_add_text(netflow_tree, tvb,
offset, pdusize,
(ver == 9) ? "FlowSet %u" : "Set %u", x);
} else {
pduitem = proto_tree_add_text(netflow_tree, tvb,
offset, pdusize, "pdu %u/%u", x, pdus);
}
pdutree = proto_item_add_subtree(pduitem, ett_flow);
pduret = pduptr(tvb, pinfo, pdutree, offset, &hdrinfo);
if (pduret < pdusize) pduret = pdusize;
if ((pduret == pdusize) && (pduret != 0))
offset += pduret;
else
break;
}
return tvb_reported_length(tvb);
}
static int
flow_process_ints(proto_tree *pdutree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(pdutree, hf_cflow_inputint, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(pdutree, hf_cflow_outputint, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static int
flow_process_ports(proto_tree *pdutree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(pdutree, hf_cflow_srcport, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(pdutree, hf_cflow_dstport, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static int
flow_process_timeperiod(proto_tree *pdutree, tvbuff_t *tvb, int offset)
{
nstime_t ts_start, ts_end;
int offset_s, offset_e;
nstime_t ts_delta;
guint32 msec_start, msec_end;
guint32 msec_delta;
proto_tree *timetree;
proto_item *timeitem;
msec_start = tvb_get_ntohl(tvb, offset);
ts_start.secs = msec_start / 1000;
ts_start.nsecs = (msec_start % 1000) * 1000000;
offset_s = offset;
offset += 4;
msec_end = tvb_get_ntohl(tvb, offset);
ts_end.secs = msec_end / 1000;
ts_end.nsecs = (msec_end % 1000) * 1000000;
offset_e = offset;
offset += 4;
msec_delta = msec_end - msec_start;
ts_delta.secs = msec_delta / 1000;
ts_delta.nsecs = (msec_delta % 1000) * 1000000;
timeitem = proto_tree_add_time(pdutree, hf_cflow_timedelta, tvb,
offset_s, 8, &ts_delta);
PROTO_ITEM_SET_GENERATED(timeitem);
timetree = proto_item_add_subtree(timeitem, ett_flowtime);
proto_tree_add_time(timetree, hf_cflow_timestart, tvb, offset_s, 4,
&ts_start);
proto_tree_add_time(timetree, hf_cflow_timeend, tvb, offset_e, 4,
&ts_end);
return offset;
}
static int
flow_process_aspair(proto_tree *pdutree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(pdutree, hf_cflow_srcas, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(pdutree, hf_cflow_dstas, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
return offset;
}
static int
flow_process_sizecount(proto_tree *pdutree, tvbuff_t *tvb, int offset)
{
proto_tree_add_item(pdutree, hf_cflow_packets, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
proto_tree_add_item(pdutree, hf_cflow_octets, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
return offset;
}
static int
flow_process_textfield(proto_tree *pdutree, tvbuff_t *tvb, int offset, int bytes, const char *text)
{
proto_tree_add_text(pdutree, tvb, offset, bytes, "%s", text);
offset += bytes;
return offset;
}
static int
dissect_v8_flowpdu(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *pdutree, int offset,
hdrinfo_t *hdrinfo_p)
{
int startoffset = offset;
guint8 verspec;
proto_tree_add_item(pdutree, hf_cflow_dstaddr, tvb, offset, 4, ENC_NA);
offset += 4;
verspec = hdrinfo_p->vspec;
if (verspec != V8PDU_DESTONLY_METHOD) {
proto_tree_add_item(pdutree, hf_cflow_srcaddr, tvb, offset, 4,
ENC_BIG_ENDIAN);
offset += 4;
}
if (verspec == V8PDU_FULL_METHOD) {
proto_tree_add_item(pdutree, hf_cflow_dstport, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(pdutree, hf_cflow_srcport, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
}
offset = flow_process_sizecount(pdutree, tvb, offset);
offset = flow_process_timeperiod(pdutree, tvb, offset);
proto_tree_add_item(pdutree, hf_cflow_outputint, tvb, offset, 2,
ENC_BIG_ENDIAN);
offset += 2;
if (verspec != V8PDU_DESTONLY_METHOD) {
proto_tree_add_item(pdutree, hf_cflow_inputint, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
}
proto_tree_add_item(pdutree, hf_cflow_tos, tvb, offset++, 1, ENC_NA);
if (verspec == V8PDU_FULL_METHOD)
proto_tree_add_item(pdutree, hf_cflow_prot, tvb, offset++, 1, ENC_NA);
offset = flow_process_textfield(pdutree, tvb, offset, 1, "marked tos");
if (verspec == V8PDU_SRCDEST_METHOD)
offset = flow_process_textfield(pdutree, tvb, offset, 2, "reserved");
else if (verspec == V8PDU_FULL_METHOD)
offset = flow_process_textfield(pdutree, tvb, offset, 1, "padding");
offset = flow_process_textfield(pdutree, tvb, offset, 4, "extra packets");
proto_tree_add_item(pdutree, hf_cflow_routersc, tvb, offset, 4, ENC_NA);
offset += 4;
return (offset - startoffset);
}
static int
dissect_v8_aggpdu(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *pdutree, int offset,
hdrinfo_t *hdrinfo_p)
{
int startoffset = offset;
guint8 verspec;
int local_cflow_as;
int local_cflow_net;
int local_cflow_int;
int local_cflow_mask;
proto_tree_add_item(pdutree, hf_cflow_flows, tvb, offset, 4, ENC_BIG_ENDIAN);
offset += 4;
offset = flow_process_sizecount(pdutree, tvb, offset);
offset = flow_process_timeperiod(pdutree, tvb, offset);
verspec = hdrinfo_p->vspec;
switch (verspec) {
case V8PDU_AS_METHOD:
case V8PDU_TOSAS_METHOD:
offset = flow_process_aspair(pdutree, tvb, offset);
if (verspec == V8PDU_TOSAS_METHOD) {
proto_tree_add_item(pdutree, hf_cflow_tos, tvb,
offset++, 1, ENC_NA);
offset = flow_process_textfield(pdutree, tvb, offset, 1, "padding");
offset = flow_process_textfield(pdutree, tvb, offset, 2, "reserved");
}
offset = flow_process_ints(pdutree, tvb, offset);
break;
case V8PDU_PROTO_METHOD:
case V8PDU_TOSPROTOPORT_METHOD:
proto_tree_add_item(pdutree, hf_cflow_prot, tvb, offset++, 1, ENC_NA);
if (verspec == V8PDU_PROTO_METHOD)
offset = flow_process_textfield(pdutree, tvb, offset, 1, "padding");
else if (verspec == V8PDU_TOSPROTOPORT_METHOD)
proto_tree_add_item(pdutree, hf_cflow_tos, tvb, offset++, 1, ENC_NA);
offset = flow_process_textfield(pdutree, tvb, offset, 2, "reserved");
offset = flow_process_ports(pdutree, tvb, offset);
if (verspec == V8PDU_TOSPROTOPORT_METHOD)
offset = flow_process_ints(pdutree, tvb, offset);
break;
case V8PDU_SPREFIX_METHOD:
case V8PDU_DPREFIX_METHOD:
case V8PDU_TOSSRCPREFIX_METHOD:
case V8PDU_TOSDSTPREFIX_METHOD:
switch (verspec) {
case V8PDU_SPREFIX_METHOD:
case V8PDU_TOSSRCPREFIX_METHOD:
local_cflow_net = hf_cflow_srcnet;
local_cflow_mask = hf_cflow_srcmask;
local_cflow_as = hf_cflow_srcas;
local_cflow_int = hf_cflow_inputint;
break;
case V8PDU_DPREFIX_METHOD:
case V8PDU_TOSDSTPREFIX_METHOD:
default:
local_cflow_net = hf_cflow_dstnet;
local_cflow_mask = hf_cflow_dstmask;
local_cflow_as = hf_cflow_dstas;
local_cflow_int = hf_cflow_outputint;
break;
}
proto_tree_add_item(pdutree, local_cflow_net, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(pdutree, local_cflow_mask, tvb, offset++, 1, ENC_NA);
if ((verspec == V8PDU_SPREFIX_METHOD) || (verspec == V8PDU_DPREFIX_METHOD))
offset = flow_process_textfield(pdutree, tvb, offset, 1, "padding");
else if ((verspec == V8PDU_TOSSRCPREFIX_METHOD) || (verspec == V8PDU_TOSDSTPREFIX_METHOD))
proto_tree_add_item(pdutree, hf_cflow_tos, tvb, offset++, 1, ENC_NA);
proto_tree_add_item(pdutree, local_cflow_as, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(pdutree, local_cflow_int, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
offset = flow_process_textfield(pdutree, tvb, offset, 2, "reserved");
break;
case V8PDU_MATRIX_METHOD:
case V8PDU_TOSMATRIX_METHOD:
case V8PDU_PREPORTPROTOCOL_METHOD:
proto_tree_add_item(pdutree, hf_cflow_srcnet, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(pdutree, hf_cflow_dstnet, tvb, offset, 4, ENC_NA);
offset += 4;
proto_tree_add_item(pdutree, hf_cflow_srcmask, tvb, offset++, 1, ENC_NA);
proto_tree_add_item(pdutree, hf_cflow_dstmask, tvb, offset++, 1, ENC_NA);
if ((verspec == V8PDU_TOSMATRIX_METHOD) ||
(verspec == V8PDU_PREPORTPROTOCOL_METHOD)) {
proto_tree_add_item(pdutree, hf_cflow_tos, tvb, offset++, 1, ENC_NA);
if (verspec == V8PDU_TOSMATRIX_METHOD) {
offset = flow_process_textfield(pdutree, tvb, offset, 1, "padding");
} else if (verspec == V8PDU_PREPORTPROTOCOL_METHOD) {
proto_tree_add_item(pdutree, hf_cflow_prot, tvb, offset++, 1, ENC_NA);
}
} else {
offset = flow_process_textfield(pdutree, tvb, offset, 2, "reserved");
}
if ((verspec == V8PDU_MATRIX_METHOD)
|| (verspec == V8PDU_TOSMATRIX_METHOD)) {
offset = flow_process_aspair(pdutree, tvb, offset);
} else if (verspec == V8PDU_PREPORTPROTOCOL_METHOD) {
offset = flow_process_ports(pdutree, tvb, offset);
}
offset = flow_process_ints(pdutree, tvb, offset);
break;
}
return (offset - startoffset);
}
static int
dissect_v9_v10_flowset(tvbuff_t *tvb, packet_info *pinfo, proto_tree *pdutree, int offset, hdrinfo_t *hdrinfo_p)
{
int length;
guint16 flowset_id;
guint8 ver;
ver = hdrinfo_p->vspec;
if ((ver != 9) && (ver != 10))
return (0);
flowset_id = tvb_get_ntohs(tvb, offset);
length = tvb_get_ntohs(tvb, offset + 2);
if (length < 4) {
expert_add_info_format(pinfo, NULL, PI_MALFORMED, PI_WARN,
"Length (%u) too short", length);
return tvb_reported_length_remaining(tvb, offset);
}
proto_tree_add_item(pdutree, hf_cflow_flowset_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
proto_tree_add_item(pdutree, hf_cflow_flowset_length, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
switch (flowset_id) {
case FLOWSET_ID_V9_DATA_TEMPLATE:
case FLOWSET_ID_V10_DATA_TEMPLATE:
dissect_v9_v10_data_template(tvb, pinfo, pdutree, offset, length - 4, hdrinfo_p, flowset_id);
break;
case FLOWSET_ID_V9_OPTIONS_TEMPLATE:
case FLOWSET_ID_V10_OPTIONS_TEMPLATE:
dissect_v9_v10_options_template(tvb, pinfo, pdutree, offset, length - 4, hdrinfo_p, flowset_id);
break;
default:
if (flowset_id >= FLOWSET_ID_DATA_MIN) {
dissect_v9_v10_data(tvb, pinfo, pdutree, offset, flowset_id, (guint)length - 4, hdrinfo_p);
}
break;
}
return (length);
}
static int
dissect_v9_v10_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *pdutree, int offset,
guint16 id, guint length, hdrinfo_t *hdrinfo_p)
{
v9_v10_tmplt_t *tmplt_p;
v9_v10_tmplt_t tmplt_key;
proto_tree *data_tree;
proto_item *data_item;
guint pdu_len;
if (length == 0) {
expert_add_info_format(pinfo, pdutree, PI_MALFORMED,
PI_WARN, "No flow information");
}
v9_v10_tmplt_build_key(&tmplt_key, pinfo, hdrinfo_p->src_id, id);
tmplt_p = g_hash_table_lookup(v9_v10_tmplt_table, &tmplt_key);
if ((tmplt_p != NULL) && (tmplt_p->length != 0)) {
int count = 1;
while (length >= tmplt_p->length) {
data_item = proto_tree_add_text(pdutree, tvb,
offset, tmplt_p->length, "Flow %d", count++);
data_tree = proto_item_add_subtree(data_item, ett_dataflowset);
pdu_len = dissect_v9_v10_pdu(tvb, pinfo, data_tree, offset, tmplt_p, hdrinfo_p);
offset += pdu_len;
length -= (pdu_len < length) ? pdu_len : length;
}
if (length != 0) {
proto_tree_add_text(pdutree, tvb, offset, length,
"Padding (%u byte%s)",
length, plurality(length, "", "s"));
}
} else {
proto_tree_add_text(pdutree, tvb, offset, length,
"Data (%u byte%s), no template found",
length, plurality(length, "", "s"));
}
return (0);
}
static guint
dissect_v9_v10_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *pdutree, int offset,
v9_v10_tmplt_t *tmplt_p, hdrinfo_t *hdrinfo_p)
{
int orig_offset = offset;
if ((tmplt_p->fields_p[TF_SCOPES] != NULL)
&& (tmplt_p->field_count[TF_SCOPES] > 0)) {
if (hdrinfo_p->vspec == 9) {
offset += dissect_v9_pdu_scope(tvb, pinfo, pdutree, offset, tmplt_p);
} else if (hdrinfo_p->vspec == 10) {
offset += dissect_v9_v10_pdu_data(tvb, pinfo, pdutree, offset, tmplt_p, hdrinfo_p, TF_SCOPES);
}
}
offset += dissect_v9_v10_pdu_data(tvb, pinfo, pdutree, offset, tmplt_p, hdrinfo_p, TF_ENTRIES);
return (guint) (offset - orig_offset);
}
static guint
dissect_v9_pdu_scope(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *pdutree, int offset,
v9_v10_tmplt_t *tmplt_p)
{
int orig_offset;
int i;
DISSECTOR_ASSERT(tmplt_p->fields_p[TF_SCOPES] != NULL);
orig_offset = offset;
for(i = 0; i < tmplt_p->field_count[TF_SCOPES]; i++) {
guint16 type = tmplt_p->fields_p[TF_SCOPES][i].type;
guint16 length = tmplt_p->fields_p[TF_SCOPES][i].length;
if (length == 0) {
continue;
}
switch (type) {
case 1:
proto_tree_add_item(pdutree, hf_cflow_scope_system,
tvb, offset, length, ENC_NA);
break;
case 2:
proto_tree_add_item(pdutree, hf_cflow_scope_interface,
tvb, offset, length, ENC_NA);
break;
case 3:
proto_tree_add_item(pdutree, hf_cflow_scope_linecard,
tvb, offset, length, ENC_NA);
break;
case 4:
proto_tree_add_item(pdutree, hf_cflow_scope_cache,
tvb, offset, length, ENC_NA);
break;
case 5:
proto_tree_add_item(pdutree, hf_cflow_scope_template,
tvb, offset, length, ENC_NA);
break;
default:
proto_tree_add_item(pdutree, hf_cflow_unknown_field_type,
tvb, offset, length, ENC_NA);
break;
}
offset += length;
}
return (guint) (offset - orig_offset);
}
static guint
dissect_v9_v10_pdu_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *pdutree, int offset,
v9_v10_tmplt_t *tmplt_p, hdrinfo_t *hdrinfo_p, v9_v10_tmplt_fields_type_t fields_type)
{
int orig_offset;
int rev;
nstime_t ts_start[2], ts_end[2];
int offset_s[2], offset_e[2];
nstime_t ts;
guint32 msec_start[2], msec_end[2];
guint32 msec_delta;
nstime_t ts_delta;
guint32 usec;
int i;
address local_addr, remote_addr;
guint16 local_port = 0, remote_port = 0;
guint32 uid = 0, pid = 0;
int uname_len;
gchar *uname_str = NULL;
int cmd_len;
gchar *cmd_str = NULL;
guint16 got_flags = 0;
int string_len_short = 0;
int string_len_long = 0;
proto_tree *string_tree;
gchar *gen_str = NULL;
int gen_str_offset = 0;
proto_item *ti;
guint16 count;
v9_v10_tmplt_entry_t *entries_p;
proto_tree *fwdstattree;
entries_p = tmplt_p->fields_p[fields_type];
if (entries_p == NULL) {
return 0;
}
orig_offset = offset;
count = tmplt_p->field_count[fields_type];
offset_s[0] = offset_s[1] = offset_e[0] = offset_e[1] = 0;
msec_start[0] = msec_start[1] = msec_end[0] = msec_end[1] = 0;
for (i = 0; i < count; i++) {
guint64 pen_type;
guint16 type;
guint16 masked_type;
guint16 length;
guint32 pen;
const gchar *pen_str;
int vstr_len;
type = entries_p[i].type;
length = entries_p[i].length;
pen = entries_p[i].pen;
pen_str = entries_p[i].pen_str;
if (length == 0) {
continue;
}
vstr_len = 0;
if (length == VARIABLE_LENGTH) {
vstr_len = 1;
string_len_short = length = tvb_get_guint8(tvb, offset);
if (length == 255) {
vstr_len = 3;
string_len_long = length = tvb_get_ntohs(tvb, offset+1);
}
offset += vstr_len;
gen_str_offset = offset;
}
pen_type = masked_type = type;
rev = 0;
if ((hdrinfo_p->vspec == 10) && (type & 0x8000)) {
pen_type = masked_type = type & 0x7fff;
if (pen == REVPEN) {
rev = 1;
} else if (pen == 0) {
pen_type = (0xffff << 16) | pen_type;
} else {
pen_type = (pen << 16) | pen_type;
}
}
ti = NULL;
switch (pen_type) {
case 1:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_octets,
tvb, offset, length, ENC_BIG_ENDIAN);
} else if (length == 8) {
ti = proto_tree_add_item(pdutree, hf_cflow_octets64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"Octets: length %u", length);
}
break;
case 2:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_packets,
tvb, offset, length, ENC_BIG_ENDIAN);
} else if (length == 8) {
ti = proto_tree_add_item(pdutree, hf_cflow_packets64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"Packets: length %u", length);
}
break;
case 163:
case 3:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_flows,
tvb, offset, length, ENC_BIG_ENDIAN);
} else if (length == 8) {
ti = proto_tree_add_item(pdutree, hf_cflow_flows64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"Flows: length %u", length);
}
break;
case 4:
ti = proto_tree_add_item(pdutree, hf_cflow_prot,
tvb, offset, length, ENC_NA);
break;
case 5:
ti = proto_tree_add_item(pdutree, hf_cflow_tos,
tvb, offset, length, ENC_NA);
break;
case 6:
ti = proto_tree_add_item(pdutree, hf_cflow_tcpflags,
tvb, offset, length, ENC_NA);
break;
case 7:
case 180:
case 182:
ti = proto_tree_add_item(pdutree, hf_cflow_srcport,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 8:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_srcaddr,
tvb, offset, length, ENC_NA);
} else if (length == 16) {
ti = proto_tree_add_item(pdutree, hf_cflow_srcaddr_v6,
tvb, offset, length, ENC_NA);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"SrcAddr: length %u", length);
}
break;
case 9:
ti = proto_tree_add_item(pdutree, hf_cflow_srcmask,
tvb, offset, length, ENC_NA);
break;
case 10:
ti = proto_tree_add_item(pdutree, hf_cflow_inputint,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 11:
case 181:
case 183:
ti = proto_tree_add_item(pdutree, hf_cflow_dstport,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 12:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_dstaddr,
tvb, offset, length, ENC_NA);
} else if (length == 16) {
ti = proto_tree_add_item(pdutree, hf_cflow_dstaddr_v6,
tvb, offset, length, ENC_NA);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"DstAddr: length %u", length);
}
break;
case 13:
ti = proto_tree_add_item(pdutree, hf_cflow_dstmask,
tvb, offset, length, ENC_NA);
break;
case 14:
ti = proto_tree_add_item(pdutree, hf_cflow_outputint,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 15:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_nexthop,
tvb, offset, length, ENC_NA);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"NextHop: length %u", length);
}
break;
case 16:
ti = proto_tree_add_item(pdutree, hf_cflow_srcas,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 17:
ti = proto_tree_add_item(pdutree, hf_cflow_dstas,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 18:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_bgpnexthop,
tvb, offset, length, ENC_NA);
} else if (length == 16) {
ti = proto_tree_add_item(pdutree, hf_cflow_bgpnexthop_v6,
tvb, offset, length, ENC_NA);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"BGPNextHop: length %u", length);
}
break;
case 19:
ti = proto_tree_add_item(pdutree, hf_cflow_mulpackets,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 20:
ti = proto_tree_add_item(pdutree, hf_cflow_muloctets,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 21:
offset_e[rev] = offset;
msec_end[rev] = tvb_get_ntohl(tvb, offset);
ts_end[rev].secs = msec_end[rev] / 1000;
ts_end[rev].nsecs = (msec_end[rev] % 1000) * 1000000;
goto timestamp_common;
break;
case 22:
offset_s[rev] = offset;
msec_start[rev] = tvb_get_ntohl(tvb, offset);
ts_start[rev].secs = msec_start[rev] / 1000;
ts_start[rev].nsecs = (msec_start[rev] % 1000) * 1000000;
goto timestamp_common;
break;
case 150:
offset_s[rev] = offset;
ts_start[rev].secs = tvb_get_ntohl(tvb, offset);
ts_start[rev].nsecs = 0;
goto timestamp_common;
break;
case 151:
offset_e[rev] = offset;
ts_end[rev].secs = tvb_get_ntohl(tvb, offset);
ts_end[rev].nsecs = 0;
goto timestamp_common;
break;
case 152:
offset_s[rev] = offset;
ts_start[rev].secs = tvb_get_ntoh64(tvb, offset)/1000;
ts_start[rev].nsecs = (int)(tvb_get_ntoh64(tvb, offset)%1000) * 1000000;
goto timestamp_common;
break;
case 153:
offset_e[rev] = offset;
ts_end[rev].secs = (tvb_get_ntoh64(tvb, offset)/1000);
ts_end[rev].nsecs = (int)(tvb_get_ntoh64(tvb, offset)%1000) * 1000000;
goto timestamp_common;
break;
case 154:
offset_s[rev] = offset;
ntp_to_nstime(tvb, offset, &ts_start[rev]);
goto timestamp_common;
break;
case 155:
offset_e[rev] = offset;
ntp_to_nstime(tvb, offset, &ts_end[rev]);
goto timestamp_common;
break;
case 156:
offset_s[rev] = offset;
ntp_to_nstime(tvb, offset, &ts_start[rev]);
goto timestamp_common;
break;
case 157:
offset_e[rev] = offset;
ntp_to_nstime(tvb, offset, &ts_end[rev]);
goto timestamp_common;
break;
case 158:
offset_s[rev] = offset;
usec = tvb_get_ntohl(tvb, offset);
ts_start[rev].secs = (((guint64)(hdrinfo_p->export_time_secs)*1000000 - usec) / 1000000);
ts_start[rev].nsecs = (int)(((guint64)(hdrinfo_p->export_time_secs)*1000000 - usec) % 1000000) * 1000;
goto timestamp_common;
break;
case 159:
offset_e[rev] = offset;
usec = tvb_get_ntohl(tvb, offset);
ts_end[rev].secs = (((guint64)(hdrinfo_p->export_time_secs)*1000000 - usec) / 1000000);
ts_end[rev].nsecs = (int)(((guint64)(hdrinfo_p->export_time_secs)*1000000 - usec) % 1000000) * 1000;
timestamp_common:
if(offset_s[rev] && offset_e[rev]) {
proto_tree *timetree;
proto_item *timeitem;
nstime_delta(&ts_delta, &ts_end[rev], &ts_start[rev]);
timeitem =
proto_tree_add_time(pdutree, hf_cflow_timedelta, tvb,
offset_s[rev], 0, &ts_delta);
PROTO_ITEM_SET_GENERATED(timeitem);
timetree = proto_item_add_subtree(timeitem, ett_flowtime);
if (msec_start[rev]) {
proto_tree_add_time(timetree, hf_cflow_timestart, tvb,
offset_s[rev], length, &ts_start[rev]);
} else {
proto_tree_add_time(timetree, hf_cflow_abstimestart, tvb,
offset_s[rev], length, &ts_start[rev]);
}
if (msec_end[rev]) {
proto_tree_add_time(timetree, hf_cflow_timeend, tvb,
offset_e[rev], length, &ts_end[rev]);
} else {
proto_tree_add_time(timetree, hf_cflow_abstimeend, tvb,
offset_e[rev], length, &ts_end[rev]);
}
}
break;
case 23:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_post_octets,
tvb, offset, length, ENC_BIG_ENDIAN);
} else if (length == 8) {
ti = proto_tree_add_item(pdutree, hf_cflow_post_octets64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"Post Octets: length %u", length);
}
break;
case 24:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_post_packets,
tvb, offset, length, ENC_BIG_ENDIAN);
} else if (length == 8) {
ti = proto_tree_add_item(pdutree, hf_cflow_post_packets64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"Post Packets: length %u", length);
}
break;
case 25:
ti = proto_tree_add_item(pdutree, hf_cflow_length_min,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 26:
ti = proto_tree_add_item(pdutree, hf_cflow_length_max,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 27:
ti = proto_tree_add_item(pdutree, hf_cflow_srcaddr_v6,
tvb, offset, length, ENC_NA);
break;
case 28:
ti = proto_tree_add_item(pdutree, hf_cflow_dstaddr_v6,
tvb, offset, length, ENC_NA);
break;
case 29:
ti = proto_tree_add_item(pdutree, hf_cflow_srcmask_v6,
tvb, offset, length, ENC_NA);
break;
case 30:
ti = proto_tree_add_item(pdutree, hf_cflow_dstmask_v6,
tvb, offset, length, ENC_NA);
break;
case 31:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_ipv6_flowlabel,
tvb, offset, length, ENC_BIG_ENDIAN);
}
else if (length == 3) {
ti = proto_tree_add_item(pdutree, hf_cflow_ipv6_flowlabel24,
tvb, offset, length, ENC_BIG_ENDIAN);
}
break;
case 32:
ti = proto_tree_add_item(pdutree, hf_cflow_icmp_type,
tvb, offset, length, ENC_NA);
break;
case 33:
ti = proto_tree_add_item(pdutree, hf_cflow_igmp_type,
tvb, offset, length, ENC_NA);
break;
case 34:
ti = proto_tree_add_item(pdutree, hf_cflow_sampling_interval,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 35:
ti = proto_tree_add_item(pdutree, hf_cflow_sampling_algorithm,
tvb, offset, length, ENC_NA);
break;
case 36:
ti = proto_tree_add_item(pdutree, hf_cflow_flow_active_timeout,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 37:
ti = proto_tree_add_item(pdutree, hf_cflow_flow_inactive_timeout,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 38:
ti = proto_tree_add_item(pdutree, hf_cflow_engine_type,
tvb, offset, length, ENC_NA);
break;
case 39:
ti = proto_tree_add_item(pdutree, hf_cflow_engine_id,
tvb, offset, length, ENC_NA);
break;
case 40:
if( length == 8 ) {
ti = proto_tree_add_item(pdutree, hf_cflow_octets_exp64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else if( length == 4 ) {
ti = proto_tree_add_item(pdutree, hf_cflow_octets_exp,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree, tvb, offset, length,
"BytesExported: length %u", length);
}
break;
case 41:
if( length == 8 ) {
ti = proto_tree_add_item(pdutree, hf_cflow_packets_exp64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else if( length == 4 ) {
ti = proto_tree_add_item(pdutree, hf_cflow_packets_exp,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree, tvb, offset, length,
"PacketsExported: length %u", length);
}
break;
case 42:
if( length == 8 ) {
ti = proto_tree_add_item(pdutree, hf_cflow_flows_exp64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else if( length == 4 ) {
ti = proto_tree_add_item(pdutree, hf_cflow_flows_exp,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree, tvb, offset, length,
"FlowsExported: length %u", length);
}
break;
case 44:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_srcprefix,
tvb, offset, length, ENC_NA);
} else {
ti = proto_tree_add_text(pdutree, tvb, offset, length,
"SrcPrefix: length %u", length);
}
break;
case 45:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_dstprefix,
tvb, offset, length, ENC_NA);
} else {
ti = proto_tree_add_text(pdutree, tvb, offset, length,
"DstPrefix: length %u", length);
}
break;
case 46:
ti = proto_tree_add_item(pdutree, hf_cflow_mpls_top_label_type,
tvb, offset, length, ENC_NA);
break;
case 47:
ti = proto_tree_add_item(pdutree, hf_cflow_mpls_pe_addr,
tvb, offset, length, ENC_NA);
break;
case 48:
#if 0
ti = proto_tree_add_text(pdutree, tvb, offset, length,
"FlowSamplerID: %d", tvb_get_guint8(tvb, offset));
#endif
ti = proto_tree_add_item(pdutree, hf_cflow_sampler_id,
tvb, offset, length, ENC_NA);
break;
case 49:
ti = proto_tree_add_item(pdutree, hf_cflow_sampler_mode,
tvb, offset, length, ENC_NA);
break;
case 50:
ti = proto_tree_add_item(pdutree, hf_cflow_sampler_random_interval,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 51:
ti = proto_tree_add_item(pdutree, hf_cflow_flow_class,
tvb, offset, length, ENC_NA);
break;
case 52:
ti = proto_tree_add_item(pdutree, hf_cflow_ttl_minimum,
tvb, offset, length, ENC_NA);
break;
case 53:
ti = proto_tree_add_item(pdutree, hf_cflow_ttl_maximum,
tvb, offset, length, ENC_NA);
break;
case 54:
ti = proto_tree_add_item(pdutree, hf_cflow_ipv4_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 55:
ti = proto_tree_add_item(pdutree, hf_cflow_post_tos,
tvb, offset, length, ENC_NA);
break;
case 56:
ti = proto_tree_add_item(pdutree, hf_cflow_srcmac,
tvb, offset, length, ENC_NA);
break;
case 57:
ti = proto_tree_add_item(pdutree, hf_cflow_post_dstmac,
tvb, offset, length, ENC_NA);
break;
case 58:
ti = proto_tree_add_item(pdutree, hf_cflow_vlanid,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 59:
ti = proto_tree_add_item(pdutree, hf_cflow_post_vlanid,
tvb, offset, length, ENC_NA);
break;
case 60:
ti = proto_tree_add_item(pdutree, hf_cflow_ip_version,
tvb, offset, length, ENC_NA);
break;
case 61:
ti = proto_tree_add_item(pdutree, hf_cflow_direction,
tvb, offset, length, ENC_NA);
break;
case 62:
if (length == 16) {
ti = proto_tree_add_item(pdutree, hf_cflow_nexthop_v6,
tvb, offset, length, ENC_NA);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"NextHop: length %u", length);
}
break;
case 63:
if (length == 16) {
ti = proto_tree_add_item(pdutree, hf_cflow_bgpnexthop_v6,
tvb, offset, length, ENC_NA);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"BGPNextHop: length %u", length);
}
break;
case 64:
ti = proto_tree_add_item(pdutree, hf_cflow_ipv6_exthdr,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 70:
ti = proto_tree_add_mpls_label(pdutree, tvb, offset, length, 1);
break;
case 71:
ti = proto_tree_add_mpls_label(pdutree, tvb, offset, length, 2);
break;
case 72:
ti = proto_tree_add_mpls_label(pdutree, tvb, offset, length, 3);
break;
case 73:
ti = proto_tree_add_mpls_label(pdutree, tvb, offset, length, 4);
break;
case 74:
ti = proto_tree_add_mpls_label(pdutree, tvb, offset, length, 5);
break;
case 75:
ti = proto_tree_add_mpls_label(pdutree, tvb, offset, length, 6);
break;
case 76:
ti = proto_tree_add_mpls_label(pdutree, tvb, offset, length, 7);
break;
case 77:
ti = proto_tree_add_mpls_label(pdutree, tvb, offset, length, 8);
break;
case 78:
ti = proto_tree_add_mpls_label(pdutree, tvb, offset, length, 9);
break;
case 79:
ti = proto_tree_add_mpls_label(pdutree, tvb, offset, length, 10);
break;
case 80:
ti = proto_tree_add_item(pdutree, hf_cflow_dstmac,
tvb, offset, length, ENC_NA);
break;
case 81:
ti = proto_tree_add_item(pdutree, hf_cflow_post_srcmac,
tvb, offset, length, ENC_NA);
break;
case 82:
ti = proto_tree_add_item(pdutree, hf_cflow_if_name,
tvb, offset, length, ENC_ASCII|ENC_NA);
break;
case 83:
ti = proto_tree_add_item(pdutree, hf_cflow_if_descr,
tvb, offset, length, ENC_ASCII|ENC_NA);
break;
case 84:
ti = proto_tree_add_item(pdutree, hf_cflow_sampler_name,
tvb, offset, length, ENC_ASCII|ENC_NA);
break;
case 85:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_permanent_octets,
tvb, offset, length, ENC_BIG_ENDIAN);
} else if (length == 8) {
ti = proto_tree_add_item(pdutree, hf_cflow_permanent_octets64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"Running Octets: length %u", length);
}
break;
case 86:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_permanent_packets,
tvb, offset, length, ENC_BIG_ENDIAN);
} else if (length == 8) {
ti = proto_tree_add_item(pdutree, hf_cflow_permanent_packets64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"Running Packets: length %u", length);
}
break;
case 88:
ti = proto_tree_add_item(pdutree, hf_cflow_fragment_offset,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 89: {
guint8 forwarding_status;
const value_string *x_vs;
int x_hf;
ti = proto_tree_add_text(pdutree, tvb, offset, length, "Forwarding Status");
fwdstattree = proto_item_add_subtree(ti, ett_fwdstat);
forwarding_status = tvb_get_guint8(tvb, offset)>>6;
switch(forwarding_status) {
default:
case FORWARDING_STATUS_UNKNOWN:
x_vs = v9_forwarding_status_unknown_code;
x_hf = hf_cflow_forwarding_status_unknown_code;
break;
case FORWARDING_STATUS_FORWARD:
x_vs = v9_forwarding_status_forward_code;
x_hf = hf_cflow_forwarding_status_forward_code;
break;
case FORWARDING_STATUS_DROP:
x_vs = v9_forwarding_status_drop_code;
x_hf = hf_cflow_forwarding_status_drop_code;
break;
case FORWARDING_STATUS_CONSUME:
x_vs = v9_forwarding_status_consume_code;
x_hf = hf_cflow_forwarding_status_consume_code;
break;
}
proto_tree_add_item(fwdstattree, hf_cflow_forwarding_status,
tvb, offset, length, ENC_NA);
proto_tree_add_item(fwdstattree, x_hf,
tvb, offset, length, ENC_NA);
if (length==1) {
proto_item_append_text(ti, ": %s", val_to_str_const(forwarding_status,
v9_forwarding_status, "(Unknown)"));
proto_item_append_text(ti, ": %s", val_to_str_const((tvb_get_guint8(tvb, offset)&0x3F),
x_vs, "(Unknown)"));
};
}
break;
case 90:
ti = proto_tree_add_item(pdutree, hf_cflow_mpls_vpn_rd,
tvb, offset, length, ENC_NA);
break;
case 91:
ti = proto_tree_add_item(pdutree, hf_cflow_mpls_top_label_prefix_length,
tvb, offset, length, ENC_NA);
break;
case 94:
ti = proto_tree_add_item(pdutree, hf_cflow_nbar_appl_desc,
tvb, offset, length, ENC_ASCII|ENC_NA);
break;
case 95:
ti = proto_tree_add_item(pdutree, hf_cflow_nbar_appl_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 96:
ti = proto_tree_add_item(pdutree, hf_cflow_nbar_appl_name,
tvb, offset, length, ENC_ASCII|ENC_NA);
break;
case 98:
ti = proto_tree_add_item(pdutree, hf_cflow_post_ip_diff_serv_code_point,
tvb, offset, length, ENC_NA);
break;
case 99:
ti = proto_tree_add_item(pdutree, hf_cflow_multicast_replication_factor,
tvb, offset, length, ENC_NA);
break;
case 128:
ti = proto_tree_add_item(pdutree, hf_cflow_peer_dstas,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 129:
ti = proto_tree_add_item(pdutree, hf_cflow_peer_srcas,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 130:
ti = proto_tree_add_item(pdutree, hf_cflow_exporter_addr,
tvb, offset, length, ENC_NA);
break;
case 131:
ti = proto_tree_add_item(pdutree,
hf_cflow_exporter_addr_v6,
tvb, offset, length, ENC_NA);
break;
case 132:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_drop_octets,
tvb, offset, length, ENC_BIG_ENDIAN);
} else if (length == 8) {
ti = proto_tree_add_item(pdutree, hf_cflow_drop_octets64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree, tvb, offset, length,
"Dropped Octets: length %u",
length);
}
break;
case 133:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_drop_packets,
tvb, offset, length, ENC_BIG_ENDIAN);
} else if (length == 8) {
ti = proto_tree_add_item(pdutree, hf_cflow_drop_packets64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree, tvb, offset, length,
"Dropped Packets: length %u",
length);
}
break;
case 134:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_drop_total_octets,
tvb, offset, length, ENC_BIG_ENDIAN);
} else if (length == 8) {
ti = proto_tree_add_item(pdutree, hf_cflow_drop_total_octets64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree, tvb, offset, length,
"Dropped Total Octets: length %u", length);
}
break;
case 135:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_drop_total_packets,
tvb, offset, length, ENC_BIG_ENDIAN);
} else if (length == 8) {
ti = proto_tree_add_item(pdutree, hf_cflow_drop_total_packets64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree, tvb, offset, length,
"Dropped Total Packets: length %u", length);
}
break;
case 136:
ti = proto_tree_add_item(pdutree, hf_cflow_flow_end_reason,
tvb, offset, length, ENC_NA);
break;
case 137:
ti = proto_tree_add_item(pdutree, hf_cflow_common_properties_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 138:
ti = proto_tree_add_item(pdutree, hf_cflow_observation_point_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 139:
proto_tree_add_item(pdutree, hf_cflow_icmp_ipv6_type,
tvb, offset, 1, ENC_NA);
ti = proto_tree_add_item(pdutree, hf_cflow_icmp_ipv6_code,
tvb, offset + 1, 1, ENC_NA);
break;
case 140:
if (length == 16) {
ti = proto_tree_add_item(pdutree,
hf_cflow_mpls_pe_addr_v6,
tvb, offset, length, ENC_NA);
} else {
ti = proto_tree_add_text(pdutree, tvb, offset, length,
"mplsTopLabelIPv6Addr: length %u",
length);
}
break;
case 141:
ti = proto_tree_add_item(pdutree, hf_cflow_scope_linecard,
tvb, offset, length, ENC_NA);
break;
case 142:
ti = proto_tree_add_item(pdutree, hf_cflow_port_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 143:
ti = proto_tree_add_item(pdutree, hf_cflow_mp_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 144:
ti = proto_tree_add_item(pdutree, hf_cflow_flow_exporter,
tvb, offset, length, ENC_NA);
break;
case 145:
ti = proto_tree_add_item(pdutree, hf_cflow_template_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 146:
ti = proto_tree_add_item(pdutree, hf_cflow_wlan_channel_id,
tvb, offset, length, ENC_NA);
break;
case 147:
ti = proto_tree_add_item(pdutree, hf_cflow_wlan_ssid,
tvb, offset, length, ENC_ASCII|ENC_NA);
break;
case 148:
ti = proto_tree_add_item(pdutree, hf_cflow_flow_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 149:
ti = proto_tree_add_item(pdutree, hf_cflow_od_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 160:
ts.secs = (tvb_get_ntoh64(tvb, offset)/1000);
ts.nsecs = (int)(tvb_get_ntoh64(tvb, offset)%1000) *1000000;
ti = proto_tree_add_time(pdutree,
hf_cflow_sys_init_time,
tvb, offset, length, &ts);
break;
case 161:
msec_delta = tvb_get_ntohl(tvb, offset);
ts_delta.secs = msec_delta / 1000;
ts_delta.nsecs = (msec_delta % 1000) * 1000000;
ti = proto_tree_add_time(pdutree, hf_cflow_timedelta, tvb,
offset, length, &ts_delta);
break;
case 162:
msec_delta = tvb_get_ntohl(tvb, offset);
ts_delta.secs = msec_delta / 1000000;
ts_delta.nsecs = (msec_delta % 1000000) * 1000000;
ti = proto_tree_add_time(pdutree, hf_cflow_timedelta, tvb,
offset, length, &ts_delta);
break;
case 164:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_ignore_packets,
tvb, offset, length, ENC_BIG_ENDIAN);
} else if (length == 8) {
ti = proto_tree_add_item(pdutree, hf_cflow_ignore_packets64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"Ignored Packets: length %u", length);
}
break;
case 165:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_ignore_octets,
tvb, offset, length, ENC_BIG_ENDIAN);
} else if (length == 8) {
ti = proto_tree_add_item(pdutree, hf_cflow_ignore_octets64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"Ignored Octets: length %u", length);
}
break;
case 166:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_notsent_flows,
tvb, offset, length, ENC_BIG_ENDIAN);
} else if (length == 8) {
ti = proto_tree_add_item(pdutree, hf_cflow_notsent_flows64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"Not Sent Flows: length %u", length);
}
break;
case 167:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_notsent_packets,
tvb, offset, length, ENC_BIG_ENDIAN);
} else if (length == 8) {
ti = proto_tree_add_item(pdutree, hf_cflow_notsent_packets64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"Not Sent Packets: length %u", length);
}
break;
case 168:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_notsent_octets,
tvb, offset, length, ENC_BIG_ENDIAN);
} else if (length == 8) {
ti = proto_tree_add_item(pdutree, hf_cflow_notsent_octets64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"Not Sent Packets: length %u", length);
}
break;
case 169:
if (length == 16) {
ti = proto_tree_add_item(pdutree, hf_cflow_dstnet_v6,
tvb, offset, length, ENC_NA);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"DstPrefix: length %u", length);
}
break;
case 170:
if (length == 16) {
ti = proto_tree_add_item(pdutree, hf_cflow_srcnet_v6,
tvb, offset, length, ENC_NA);
} else if (length != 4 && length != 16) {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"SrcPrefix: length %u", length);
}
break;
case 171:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_post_total_octets,
tvb, offset, length, ENC_BIG_ENDIAN);
} else if (length == 8) {
ti = proto_tree_add_item(pdutree, hf_cflow_post_total_octets64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"Post Total Octets: length %u", length);
}
break;
case 172:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_post_total_packets,
tvb, offset, length, ENC_BIG_ENDIAN);
} else if (length == 8) {
ti = proto_tree_add_item(pdutree, hf_cflow_post_total_packets64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"Post Total Packets: length %u", length);
}
break;
case 173:
ti = proto_tree_add_item(pdutree, hf_cflow_key,
tvb, offset, length, ENC_NA);
break;
case 174:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_post_total_mulpackets,
tvb, offset, length, ENC_BIG_ENDIAN);
} else if (length == 8) {
ti = proto_tree_add_item(pdutree, hf_cflow_post_total_mulpackets64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"Post Total Multicast Packets: length %u", length);
}
break;
case 175:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_post_total_muloctets,
tvb, offset, length, ENC_BIG_ENDIAN);
} else if (length == 8) {
ti = proto_tree_add_item(pdutree, hf_cflow_post_total_muloctets64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"Post Total Multicast Octets: length %u", length);
}
break;
case 176:
ti = proto_tree_add_item(pdutree, hf_cflow_icmp_ipv4_type,
tvb, offset, length, ENC_NA);
break;
case 177:
ti = proto_tree_add_item(pdutree, hf_cflow_icmp_ipv4_code,
tvb, offset, length, ENC_NA);
break;
case 178:
ti = proto_tree_add_item(pdutree, hf_cflow_icmp_ipv6_type,
tvb, offset, length, ENC_NA);
break;
case 179:
ti = proto_tree_add_item(pdutree, hf_cflow_icmp_ipv6_code,
tvb, offset, length, ENC_NA);
break;
case 184:
ti = proto_tree_add_item(pdutree, hf_cflow_tcp_seq_num,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 185:
ti = proto_tree_add_item(pdutree, hf_cflow_tcp_ack_num,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 186:
ti = proto_tree_add_item(pdutree, hf_cflow_tcp_window_size,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 187:
ti = proto_tree_add_item(pdutree, hf_cflow_tcp_urg_ptr,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 188:
ti = proto_tree_add_item(pdutree, hf_cflow_tcp_header_length,
tvb, offset, length, ENC_NA);
break;
case 189:
ti = proto_tree_add_item(pdutree, hf_cflow_ip_header_length,
tvb, offset, length, ENC_NA);
break;
case 190:
ti = proto_tree_add_item(pdutree, hf_cflow_ipv4_total_length,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 191:
ti = proto_tree_add_item(pdutree, hf_cflow_ipv6_payload_length,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 192:
ti = proto_tree_add_item(pdutree, hf_cflow_ip_ttl,
tvb, offset, length, ENC_NA);
break;
case 193:
ti = proto_tree_add_item(pdutree, hf_cflow_ipv6_next_hdr,
tvb, offset, length, ENC_NA);
break;
case 194:
ti = proto_tree_add_item(pdutree, hf_cflow_ip_tos,
tvb, offset, length, ENC_NA);
break;
case 195:
ti = proto_tree_add_item(pdutree, hf_cflow_ip_dscp,
tvb, offset, length, ENC_NA);
break;
case 196:
ti = proto_tree_add_item(pdutree, hf_cflow_ip_precedence,
tvb, offset, length, ENC_NA);
break;
case 197:
ti = proto_tree_add_item(pdutree, hf_cflow_ip_fragment_flags,
tvb, offset, length, ENC_NA);
break;
case 198:
case 199:
if( length == 8 ) {
ti = proto_tree_add_item(pdutree, hf_cflow_octets_squared64,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree, tvb, offset, length,
"Bytes Squared: length %u", length);
}
break;
case 200:
ti = proto_tree_add_item(pdutree, hf_cflow_mpls_top_label_ttl,
tvb, offset, length, ENC_NA);
break;
case 201:
ti = proto_tree_add_item(pdutree, hf_cflow_mpls_label_length,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 202:
ti = proto_tree_add_item(pdutree, hf_cflow_mpls_label_depth,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 203:
ti = proto_tree_add_item(pdutree, hf_cflow_mpls_top_label_exp,
tvb, offset, length, ENC_NA);
break;
case 204:
ti = proto_tree_add_item(pdutree, hf_cflow_ip_payload_length,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 205:
ti = proto_tree_add_item(pdutree, hf_cflow_udp_length,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 206:
ti = proto_tree_add_item(pdutree, hf_cflow_is_multicast,
tvb, offset, length, ENC_NA);
break;
case 207:
ti = proto_tree_add_item(pdutree, hf_cflow_ip_header_words,
tvb, offset, length, ENC_NA);
break;
case 208:
ti = proto_tree_add_item(pdutree, hf_cflow_option_map,
tvb, offset, length, ENC_NA);
break;
case 209:
ti = proto_tree_add_item(pdutree, hf_cflow_tcp_option_map,
tvb, offset, length, ENC_NA);
break;
case 210:
ti = proto_tree_add_text(pdutree, tvb, offset, length,
"Padding (%u byte%s)",
length, plurality(length, "", "s"));
break;
case 211:
ti = proto_tree_add_item(pdutree, hf_cflow_collector_addr,
tvb, offset, length, ENC_NA);
break;
case 212:
ti = proto_tree_add_item(pdutree, hf_cflow_collector_addr_v6,
tvb, offset, length, ENC_NA);
break;
case 213:
if (length == 4) {
ti = proto_tree_add_item(pdutree, hf_cflow_export_interface,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_text(pdutree,
tvb, offset, length,
"exportInterface: invalid size %d", length );
}
break;
case 214:
ti = proto_tree_add_item(pdutree, hf_cflow_export_protocol_version,
tvb, offset, length, ENC_NA);
break;
case 215:
ti = proto_tree_add_item(pdutree, hf_cflow_export_prot,
tvb, offset, length, ENC_NA);
break;
case 216:
ti = proto_tree_add_item(pdutree, hf_cflow_collector_port,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 217:
ti = proto_tree_add_item(pdutree, hf_cflow_exporter_port,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 218:
ti = proto_tree_add_item(pdutree, hf_cflow_total_tcp_syn,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 219:
ti = proto_tree_add_item(pdutree, hf_cflow_total_tcp_fin,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 220:
ti = proto_tree_add_item(pdutree, hf_cflow_total_tcp_rst,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 221:
ti = proto_tree_add_item(pdutree, hf_cflow_total_tcp_psh,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 222:
ti = proto_tree_add_item(pdutree, hf_cflow_total_tcp_ack,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 223:
ti = proto_tree_add_item(pdutree, hf_cflow_total_tcp_urg,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 224:
ti = proto_tree_add_item(pdutree, hf_cflow_ip_total_length,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 225:
case 40001:
ti = proto_tree_add_item(pdutree, hf_cflow_post_natsource_ipv4_address,
tvb, offset, length, ENC_NA);
break;
case 226:
case 40002:
ti = proto_tree_add_item(pdutree, hf_cflow_post_natdestination_ipv4_address,
tvb, offset, length, ENC_NA);
break;
case 227:
case 40003:
ti = proto_tree_add_item(pdutree, hf_cflow_post_naptsource_transport_port,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 228:
case 40004:
ti = proto_tree_add_item(pdutree, hf_cflow_post_naptdestination_transport_port,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 229:
ti = proto_tree_add_item(pdutree, hf_cflow_nat_originating_address_realm,
tvb, offset, length, ENC_NA);
break;
case 230:
ti = proto_tree_add_item(pdutree, hf_cflow_nat_event,
tvb, offset, length, ENC_NA);
break;
case 231:
ti = proto_tree_add_item(pdutree, hf_cflow_initiator_octets,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 232:
ti = proto_tree_add_item(pdutree, hf_cflow_responder_octets,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 233:
case 40005:
ti = proto_tree_add_item(pdutree, hf_cflow_firewall_event,
tvb, offset, length, ENC_NA);
break;
case 234:
ti = proto_tree_add_item(pdutree, hf_cflow_ingress_vrfid,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 235:
ti = proto_tree_add_item(pdutree, hf_cflow_egress_vrfid,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 236:
ti = proto_tree_add_item(pdutree, hf_cflow_vrfname,
tvb, offset, length, ENC_ASCII|ENC_NA);
break;
case 237:
ti = proto_tree_add_item(pdutree, hf_cflow_post_mpls_top_label_exp,
tvb, offset, length, ENC_NA);
break;
case 238:
ti = proto_tree_add_item(pdutree, hf_cflow_tcp_window_scale,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 239:
ti = proto_tree_add_item(pdutree, hf_cflow_biflow_direction,
tvb, offset, length, ENC_NA);
break;
case 240:
ti = proto_tree_add_item(pdutree, hf_cflow_ethernet_header_length,
tvb, offset, length, ENC_NA);
break;
case 241:
ti = proto_tree_add_item(pdutree, hf_cflow_ethernet_payload_length,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 242:
ti = proto_tree_add_item(pdutree, hf_cflow_ethernet_total_length,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 243:
ti = proto_tree_add_item(pdutree, hf_cflow_dot1q_vlan_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 244:
ti = proto_tree_add_item(pdutree, hf_cflow_dot1q_priority,
tvb, offset, length, ENC_NA);
break;
case 245:
ti = proto_tree_add_item(pdutree, hf_cflow_dot1q_customer_vlan_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 246:
ti = proto_tree_add_item(pdutree, hf_cflow_dot1q_customer_priority,
tvb, offset, length, ENC_NA);
break;
case 247:
ti = proto_tree_add_item(pdutree, hf_cflow_metro_evc_id,
tvb, offset, length, ENC_ASCII|ENC_NA);
break;
case 248:
ti = proto_tree_add_item(pdutree, hf_cflow_metro_evc_type,
tvb, offset, length, ENC_NA);
break;
case 249:
ti = proto_tree_add_item(pdutree, hf_cflow_pseudo_wire_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 250:
ti = proto_tree_add_item(pdutree, hf_cflow_pseudo_wire_type,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 251:
ti = proto_tree_add_item(pdutree, hf_cflow_pseudo_wire_control_word,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 252:
ti = proto_tree_add_item(pdutree, hf_cflow_ingress_physical_interface,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 253:
ti = proto_tree_add_item(pdutree, hf_cflow_egress_physical_interface,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 254:
ti = proto_tree_add_item(pdutree, hf_cflow_post_dot1q_vlan_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 255:
ti = proto_tree_add_item(pdutree, hf_cflow_post_dot1q_customer_vlan_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 256:
ti = proto_tree_add_item(pdutree, hf_cflow_ethernet_type,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 257:
ti = proto_tree_add_item(pdutree, hf_cflow_post_ip_precedence,
tvb, offset, length, ENC_NA);
break;
case 258:
ts.secs = (tvb_get_ntoh64(tvb, offset)/1000);
ts.nsecs = (int)(tvb_get_ntoh64(tvb, offset)%1000) *1000000;
ti = proto_tree_add_time(pdutree,
hf_cflow_collection_time_milliseconds,
tvb, offset, length, &ts);
break;
case 259:
ti = proto_tree_add_item(pdutree, hf_cflow_export_sctp_stream_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 260:
ts.secs = tvb_get_ntohl(tvb, offset);
ts.nsecs = 0;
ti = proto_tree_add_time(pdutree, hf_cflow_max_export_seconds,
tvb, offset, length, &ts);
break;
case 261:
ts.secs = tvb_get_ntohl(tvb, offset);
ts.nsecs = 0;
ti = proto_tree_add_time(pdutree, hf_cflow_max_flow_end_seconds,
tvb, offset, length, &ts);
break;
case 262:
ti = proto_tree_add_item(pdutree, hf_cflow_message_md5_checksum,
tvb, offset, length, ENC_NA);
break;
case 263:
ti = proto_tree_add_item(pdutree, hf_cflow_message_scope,
tvb, offset, length, ENC_NA);
break;
case 264:
ts.secs = tvb_get_ntohl(tvb, offset);
ts.nsecs = 0;
ti = proto_tree_add_time(pdutree, hf_cflow_min_export_seconds,
tvb, offset, length, &ts);
break;
case 265:
ts.secs = tvb_get_ntohl(tvb, offset);
ts.nsecs = 0;
ti = proto_tree_add_time(pdutree, hf_cflow_min_flow_start_seconds,
tvb, offset, length, &ts);
break;
case 266:
ti = proto_tree_add_item(pdutree, hf_cflow_opaque_octets,
tvb, offset, length, ENC_NA);
break;
case 267:
ti = proto_tree_add_item(pdutree, hf_cflow_session_scope,
tvb, offset, length, ENC_NA);
break;
case 268:
ti = proto_tree_add_item(pdutree, hf_cflow_max_flow_end_microseconds,
tvb, offset, length, ENC_TIME_NTP|ENC_BIG_ENDIAN);
break;
case 269:
ts.secs = (tvb_get_ntoh64(tvb, offset)/1000);
ts.nsecs = (int)(tvb_get_ntoh64(tvb, offset)%1000) * 1000000;
ti = proto_tree_add_time(pdutree, hf_cflow_max_flow_end_milliseconds,
tvb, offset, length, &ts);
break;
case 270:
ti = proto_tree_add_item(pdutree, hf_cflow_max_flow_end_nanoseconds,
tvb, offset, length, ENC_TIME_NTP|ENC_BIG_ENDIAN);
break;
case 271:
ti = proto_tree_add_item(pdutree, hf_cflow_min_flow_start_microseconds,
tvb, offset, length, ENC_TIME_NTP|ENC_BIG_ENDIAN);
break;
case 272:
ts.secs = (tvb_get_ntohl(tvb, offset)/1000);
ts.nsecs = (tvb_get_ntohl(tvb, offset)%1000) * 1000000;
ti = proto_tree_add_time(pdutree, hf_cflow_min_flow_start_milliseconds,
tvb, offset, length, &ts);
break;
case 273:
ti = proto_tree_add_item(pdutree, hf_cflow_min_flow_start_nanoseconds,
tvb, offset, length, ENC_TIME_NTP|ENC_BIG_ENDIAN);
break;
case 274:
ti = proto_tree_add_item(pdutree, hf_cflow_collector_certificate,
tvb, offset, length, ENC_NA);
break;
case 275:
ti = proto_tree_add_item(pdutree, hf_cflow_exporter_certificate,
tvb, offset, length, ENC_NA);
break;
case 301:
ti = proto_tree_add_item(pdutree, hf_cflow_selection_sequence_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 302:
ti = proto_tree_add_item(pdutree, hf_cflow_selector_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 303:
ti = proto_tree_add_item(pdutree, hf_cflow_information_element_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 304:
ti = proto_tree_add_item(pdutree, hf_cflow_selector_algorithm,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 305:
ti = proto_tree_add_item(pdutree, hf_cflow_sampling_packet_interval,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 306:
ti = proto_tree_add_item(pdutree, hf_cflow_sampling_packet_space,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 307:
ti = proto_tree_add_item(pdutree, hf_cflow_sampling_time_interval,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 308:
ti = proto_tree_add_item(pdutree, hf_cflow_sampling_time_space,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 309:
ti = proto_tree_add_item(pdutree, hf_cflow_sampling_size,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 310:
ti = proto_tree_add_item(pdutree, hf_cflow_sampling_population,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 311:
ti = proto_tree_add_item(pdutree, hf_cflow_sampling_probability,
tvb, offset, length, ENC_NA);
break;
case 313:
ti = proto_tree_add_item(pdutree, hf_cflow_section_header,
tvb, offset, length, ENC_NA);
break;
case 314:
ti = proto_tree_add_item(pdutree, hf_cflow_section_payload,
tvb, offset, length, ENC_NA);
break;
case 316:
ti = proto_tree_add_item(pdutree, hf_cflow_mpls_label_stack_section,
tvb, offset, length, ENC_NA);
break;
case 317:
ti = proto_tree_add_item(pdutree, hf_cflow_mpls_payload_packet_section,
tvb, offset, length, ENC_NA);
break;
case 318:
ti = proto_tree_add_item(pdutree, hf_cflow_selector_id_total_pkts_observed,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 319:
ti = proto_tree_add_item(pdutree, hf_cflow_selector_id_total_pkts_selected,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 320:
ti = proto_tree_add_item(pdutree, hf_cflow_absolute_error,
tvb, offset, length, ENC_NA);
break;
case 321:
ti = proto_tree_add_item(pdutree, hf_cflow_relative_error,
tvb, offset, length, ENC_NA);
break;
case 322:
ts.secs = tvb_get_ntohl(tvb, offset);
ts.nsecs = 0;
ti = proto_tree_add_time(pdutree, hf_cflow_observation_time_seconds,
tvb, offset, length, &ts);
break;
case 323:
ts.secs = (tvb_get_ntoh64(tvb, offset)/1000);
ts.nsecs = (int)(tvb_get_ntoh64(tvb, offset)%1000) * 1000000;
ti = proto_tree_add_time(pdutree, hf_cflow_observation_time_milliseconds,
tvb, offset, length, &ts);
break;
case 324:
ti = proto_tree_add_item(pdutree, hf_cflow_observation_time_microseconds,
tvb, offset, length, ENC_TIME_NTP|ENC_BIG_ENDIAN);
break;
case 325:
ti = proto_tree_add_item(pdutree, hf_cflow_observation_time_nanoseconds,
tvb, offset, length, ENC_TIME_NTP|ENC_BIG_ENDIAN);
break;
case 326:
ti = proto_tree_add_item(pdutree, hf_cflow_digest_hash_value,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 327:
ti = proto_tree_add_item(pdutree, hf_cflow_hash_ippayload_offset,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 328:
ti = proto_tree_add_item(pdutree, hf_cflow_hash_ippayload_size,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 329:
ti = proto_tree_add_item(pdutree, hf_cflow_hash_output_range_min,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 330:
ti = proto_tree_add_item(pdutree, hf_cflow_hash_output_range_max,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 331:
ti = proto_tree_add_item(pdutree, hf_cflow_hash_selected_range_min,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 332:
ti = proto_tree_add_item(pdutree, hf_cflow_hash_selected_range_max,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 333:
ti = proto_tree_add_item(pdutree, hf_cflow_hash_digest_output,
tvb, offset, length, ENC_NA);
break;
case 334:
ti = proto_tree_add_item(pdutree, hf_cflow_hash_initialiser_value,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 335:
ti = proto_tree_add_item(pdutree, hf_cflow_selector_name,
tvb, offset, length, ENC_ASCII|ENC_NA);
break;
case 336:
ti = proto_tree_add_item(pdutree, hf_cflow_upper_cilimit,
tvb, offset, length, ENC_NA);
break;
case 337:
ti = proto_tree_add_item(pdutree, hf_cflow_lower_cilimit,
tvb, offset, length, ENC_NA);
break;
case 338:
ti = proto_tree_add_item(pdutree, hf_cflow_confidence_level,
tvb, offset, length, ENC_NA);
break;
case 339:
ti = proto_tree_add_item(pdutree, hf_cflow_information_element_data_type,
tvb, offset, length, ENC_NA);
break;
case 340:
ti = proto_tree_add_item(pdutree, hf_cflow_information_element_description,
tvb, offset, length, ENC_ASCII|ENC_NA);
break;
case 341:
ti = proto_tree_add_item(pdutree, hf_cflow_information_element_name,
tvb, offset, length, ENC_ASCII|ENC_NA);
break;
case 342:
ti = proto_tree_add_item(pdutree, hf_cflow_information_element_range_begin,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 343:
ti = proto_tree_add_item(pdutree, hf_cflow_information_element_range_end,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 344:
ti = proto_tree_add_item(pdutree, hf_cflow_information_element_semantics,
tvb, offset, length, ENC_NA);
break;
case 345:
ti = proto_tree_add_item(pdutree, hf_cflow_information_element_units,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 346:
ti = proto_tree_add_item(pdutree, hf_cflow_private_enterprise_number,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 37000:
ti = proto_tree_add_item(pdutree, hf_cflow_packets_dropped,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 37003:
ti = proto_tree_add_item(pdutree, hf_cflow_byte_rate,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 37004:
ti = proto_tree_add_item(pdutree, hf_cflow_application_media_bytes,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 37006:
ti = proto_tree_add_item(pdutree, hf_cflow_application_media_byte_rate,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 37007:
ti = proto_tree_add_item(pdutree, hf_cflow_application_media_packets,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 37009:
ti = proto_tree_add_item(pdutree, hf_cflow_application_media_packet_rate,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 37011:
ti = proto_tree_add_item(pdutree, hf_cflow_application_media_event,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 37012:
ti = proto_tree_add_item(pdutree, hf_cflow_monitor_event,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 37013:
ti = proto_tree_add_item(pdutree, hf_cflow_timestamp_interval,
tvb, offset, length, ENC_TIME_TIMESPEC|ENC_BIG_ENDIAN);
break;
case 37014:
ti = proto_tree_add_item(pdutree, hf_cflow_transport_packets_expected,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 37016:
if (tvb_get_ntohl(tvb,offset)== 0xFFFFFFFF ) {
ti = proto_tree_add_item(pdutree, hf_cflow_transport_round_trip_time_string,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ts.secs =0;
ts.nsecs= tvb_get_ntohl(tvb,offset) * 1000;
ti = proto_tree_add_time(pdutree, hf_cflow_transport_round_trip_time,
tvb, offset, length, &ts);
}
break;
case 37017:
ti = proto_tree_add_item(pdutree, hf_cflow_transport_event_packet_loss,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 37019:
if (tvb_get_ntohl(tvb,offset)== 0xFFFFFFFF ) {
ti = proto_tree_add_item(pdutree, hf_cflow_transport_packets_lost_string,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_item(pdutree, hf_cflow_transport_packets_lost,
tvb, offset, length, ENC_BIG_ENDIAN);
}
break;
case 37021:
if (tvb_get_ntohl(tvb,offset)== 0xFFFF ) {
ti = proto_tree_add_item(pdutree, hf_cflow_transport_packets_lost_rate_string,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_item(pdutree, hf_cflow_transport_packets_lost_rate,
tvb, offset, length, ENC_BIG_ENDIAN);
}
break;
case 37022:
ti = proto_tree_add_item(pdutree, hf_cflow_transport_rtp_ssrc,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 37023:
if (tvb_get_ntohl(tvb,offset)== 0xFFFFFFFF ) {
ti = proto_tree_add_item(pdutree, hf_cflow_transport_rtp_jitter_mean_string,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ts.secs =0;
ts.nsecs= tvb_get_ntohl(tvb,offset) * 1000;
ti = proto_tree_add_time(pdutree, hf_cflow_transport_rtp_jitter_mean,
tvb, offset, length, &ts);
}
break;
case 37024:
if (tvb_get_ntohl(tvb,offset)== 0xFFFFFFFF ) {
ti = proto_tree_add_item(pdutree, hf_cflow_transport_rtp_jitter_min_string,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ts.secs =0;
ts.nsecs= tvb_get_ntohl(tvb,offset) * 1000;
ti = proto_tree_add_time(pdutree, hf_cflow_transport_rtp_jitter_min,
tvb, offset, length, &ts);
}
break;
case 37025:
if (tvb_get_ntohl(tvb,offset)== 0xFFFFFFFF ) {
ti = proto_tree_add_item(pdutree, hf_cflow_transport_rtp_jitter_max_string,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ts.secs =0;
ts.nsecs= tvb_get_ntohl(tvb,offset) * 1000;
ti = proto_tree_add_time(pdutree, hf_cflow_transport_rtp_jitter_max,
tvb, offset, length, &ts);
}
break;
case 37041:
if (tvb_get_guint8(tvb,offset)== 0xFF) {
ti = proto_tree_add_item(pdutree, hf_cflow_transport_rtp_payload_type_string,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_item(pdutree, hf_cflow_transport_rtp_payload_type,
tvb, offset, length, ENC_BIG_ENDIAN);
}
break;
case 37071:
if (tvb_get_ntoh64(tvb,offset)== G_GINT64_CONSTANT(0xFFFFFFFFFFFFFFFF)) {
proto_tree_add_text(pdutree, tvb, offset, 8,
"Transport Bytes Out of Order: Not Measured (0x%"G_GINT64_MODIFIER"x)",
tvb_get_ntoh64(tvb,offset));
ti = proto_tree_add_item(pdutree, hf_cflow_transport_bytes_out_of_order,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_item(pdutree, hf_cflow_transport_bytes_out_of_order,
tvb, offset, length, ENC_BIG_ENDIAN);
}
break;
case 37074:
if (tvb_get_ntohl(tvb,offset)== 0xFFFFFFFF) {
ti = proto_tree_add_item(pdutree, hf_cflow_transport_packets_out_of_order_string,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_item(pdutree, hf_cflow_transport_bytes_out_of_order,
tvb, offset, length, ENC_BIG_ENDIAN);
}
break;
case 37083:
if (tvb_get_ntohl(tvb,offset)== 0xFFFFFFFF) {
ti = proto_tree_add_item(pdutree, hf_cflow_transport_tcp_window_size_min_string,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_item(pdutree, hf_cflow_transport_tcp_window_size_min,
tvb, offset, length, ENC_BIG_ENDIAN);
}
break;
case 37084:
if (tvb_get_ntohl(tvb,offset)== 0xFFFFFFFF) {
ti = proto_tree_add_item(pdutree, hf_cflow_transport_tcp_window_size_max_string,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_item(pdutree, hf_cflow_transport_tcp_window_size_max,
tvb, offset, length, ENC_BIG_ENDIAN);
}
break;
case 37085:
if (tvb_get_ntohl(tvb,offset)== 0xFFFFFFFF) {
ti = proto_tree_add_item(pdutree, hf_cflow_transport_tcp_window_size_mean_string,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_item(pdutree, hf_cflow_transport_tcp_window_size_mean,
tvb, offset, length, ENC_BIG_ENDIAN);
}
break;
case 37086:
if (tvb_get_ntohs(tvb,offset)== 0xFFFF) {
ti = proto_tree_add_item(pdutree, hf_cflow_transport_tcp_maximum_segment_size_string,
tvb, offset, length, ENC_BIG_ENDIAN);
} else {
ti = proto_tree_add_item(pdutree, hf_cflow_transport_tcp_maximum_segment_size,
tvb, offset, length, ENC_BIG_ENDIAN);
}
break;
case 24628:
ti = proto_tree_add_item(pdutree, hf_cflow_nat_context_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 24629:
ti = proto_tree_add_item(pdutree, hf_cflow_nat_context_name,
tvb, offset, length, ENC_UTF_8|ENC_NA);
break;
case 24630:
ts.secs = tvb_get_ntohl(tvb, offset);
ts.nsecs = 0;
ti = proto_tree_add_time(pdutree, hf_cflow_nat_assign_time,
tvb, offset, length, &ts);
break;
case 24631:
ts.secs = tvb_get_ntohl(tvb, offset);
ts.nsecs = 0;
ti = proto_tree_add_time(pdutree, hf_cflow_nat_unassign_time,
tvb, offset, length, &ts);
break;
case 24632:
ti = proto_tree_add_item(pdutree, hf_cflow_nat_int_addr,
tvb, offset, length, ENC_NA);
break;
case 24633:
ti = proto_tree_add_item(pdutree, hf_cflow_nat_ext_addr,
tvb, offset, length, ENC_NA);
break;
case 24634:
ti = proto_tree_add_item(pdutree, hf_cflow_nat_ext_port_first,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 24635:
ti = proto_tree_add_item(pdutree, hf_cflow_nat_ext_port_last,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 33000:
proto_tree_add_item(pdutree, hf_cflow_ingress_acl_id,
tvb, offset, length, ENC_NA);
break;
case 33001:
proto_tree_add_item(pdutree, hf_cflow_egress_acl_id,
tvb, offset, length, ENC_NA);
break;
case 33002:
proto_tree_add_item(pdutree, hf_cflow_fw_ext_event,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case 40000:
proto_tree_add_item(pdutree, hf_cflow_aaa_username,
tvb, offset, length, ENC_ASCII|ENC_NA);
break;
case VENDOR_CACE << 16 | 0:
ti = proto_tree_add_item(pdutree, hf_pie_cace_local_ipv4_address,
tvb, offset, length, ENC_NA);
SET_ADDRESS(&local_addr, AT_IPv4, 4, tvb_get_ptr(tvb, offset, 4));
got_flags |= GOT_LOCAL_ADDR;
break;
case VENDOR_CACE << 16 | 1:
ti = proto_tree_add_item(pdutree, hf_pie_cace_remote_ipv4_address,
tvb, offset, length, ENC_NA);
SET_ADDRESS(&remote_addr, AT_IPv4, 4, tvb_get_ptr(tvb, offset, 4));
got_flags |= GOT_REMOTE_ADDR;
break;
case VENDOR_CACE << 16 | 2:
ti = proto_tree_add_item(pdutree, hf_pie_cace_local_ipv6_address,
tvb, offset, length, ENC_NA);
SET_ADDRESS(&local_addr, AT_IPv6, 16, tvb_get_ptr(tvb, offset, 16));
got_flags |= GOT_LOCAL_ADDR;
break;
case VENDOR_CACE << 16 | 3:
ti = proto_tree_add_item(pdutree, hf_pie_cace_remote_ipv6_address,
tvb, offset, length, ENC_NA);
SET_ADDRESS(&remote_addr, AT_IPv6, 16, tvb_get_ptr(tvb, offset, 16));
got_flags |= GOT_REMOTE_ADDR;
break;
case VENDOR_CACE << 16 | 4:
ti = proto_tree_add_item(pdutree, hf_pie_cace_local_port,
tvb, offset, length, ENC_BIG_ENDIAN);
local_port = tvb_get_ntohs(tvb, offset);
got_flags |= GOT_LOCAL_PORT;
break;
case VENDOR_CACE << 16 | 5:
ti = proto_tree_add_item(pdutree, hf_pie_cace_remote_port,
tvb, offset, length, ENC_BIG_ENDIAN);
remote_port = tvb_get_ntohs(tvb, offset);
got_flags |= GOT_REMOTE_PORT;
break;
case VENDOR_CACE << 16 | 6:
ti = proto_tree_add_item(pdutree, hf_pie_cace_local_ipv4_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case VENDOR_CACE << 16 | 7:
ti = proto_tree_add_item(pdutree, hf_pie_cace_local_icmp_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case VENDOR_CACE << 16 | 8:
ti = proto_tree_add_item(pdutree, hf_pie_cace_local_uid,
tvb, offset, length, ENC_BIG_ENDIAN);
uid = tvb_get_ntohl(tvb, offset);
got_flags |= GOT_UID;
break;
case VENDOR_CACE << 16 | 9:
ti = proto_tree_add_item(pdutree, hf_pie_cace_local_pid,
tvb, offset, length, ENC_BIG_ENDIAN);
pid = tvb_get_ntohl(tvb, offset);
got_flags |= GOT_PID;
break;
case VENDOR_CACE << 16 | 10:
uname_len = tvb_get_guint8(tvb, offset);
uname_str = tvb_format_text(tvb, offset+1, uname_len);
proto_tree_add_item(pdutree, hf_pie_cace_local_username_len,
tvb, offset, 1, ENC_NA);
ti = proto_tree_add_string(pdutree, hf_pie_cace_local_username,
tvb, offset+1, uname_len, uname_str);
length = uname_len + 1;
got_flags |= GOT_USERNAME;
break;
case VENDOR_CACE << 16 | 11:
cmd_len = tvb_get_guint8(tvb, offset);
cmd_str = tvb_format_text(tvb, offset+1, cmd_len);
proto_tree_add_item(pdutree, hf_pie_cace_local_cmd_len,
tvb, offset, 1, ENC_NA);
ti = proto_tree_add_string(pdutree, hf_pie_cace_local_cmd,
tvb, offset+1, cmd_len, cmd_str);
length = cmd_len + 1;
got_flags |= GOT_COMMAND;
break;
case (NTOP_BASE + 80):
case ((VENDOR_NTOP << 16) | 80):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_fragmented,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 81):
case ((VENDOR_NTOP << 16) | 81):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_fingerprint,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 82):
case ((VENDOR_NTOP << 16) | 82):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_client_nw_delay_sec,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 83):
case ((VENDOR_NTOP << 16) | 83):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_client_nw_delay_usec,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 84):
case ((VENDOR_NTOP << 16) | 84):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_server_nw_delay_sec,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 85):
case ((VENDOR_NTOP << 16) | 85):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_server_nw_delay_usec,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 86):
case ((VENDOR_NTOP << 16) | 86):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_appl_latency_sec,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 87):
case ((VENDOR_NTOP << 16) | 87):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_appl_latency_sec,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 98):
case ((VENDOR_NTOP << 16) | 98):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_icmp_flags,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 101):
case ((VENDOR_NTOP << 16) | 101):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_src_ip_country,
tvb, offset, length, ENC_ASCII|ENC_NA);
break;
case (NTOP_BASE + 102):
case ((VENDOR_NTOP << 16) | 102):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_src_ip_city,
tvb, offset, length, ENC_ASCII|ENC_NA);
break;
case (NTOP_BASE + 103):
case ((VENDOR_NTOP << 16) | 103):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_dst_ip_country,
tvb, offset, length, ENC_ASCII|ENC_NA);
break;
case (NTOP_BASE + 104):
case ((VENDOR_NTOP << 16) | 104):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_dst_ip_city,
tvb, offset, length, ENC_ASCII|ENC_NA);
break;
case (NTOP_BASE + 105):
case ((VENDOR_NTOP << 16) | 105):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_flow_proto_port,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 106):
case ((VENDOR_NTOP << 16) | 106):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_tunnel_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 107):
case ((VENDOR_NTOP << 16) | 107):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_longest_flow_pkt,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 108):
case ((VENDOR_NTOP << 16) | 108):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_shortest_flow_pkt,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 109):
case ((VENDOR_NTOP << 16) | 109):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_retransmitted_in_pkts,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 110):
case ((VENDOR_NTOP << 16) | 110):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_retransmitted_out_pkts,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 111):
case ((VENDOR_NTOP << 16) | 111):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_ooorder_in_pkts,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 112):
case ((VENDOR_NTOP << 16) | 112):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_ooorder_out_pkts,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 113):
case ((VENDOR_NTOP << 16) | 113):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_untunneled_protocol,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 114):
case ((VENDOR_NTOP << 16) | 114):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_untunneled_ipv4_src_addr,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 115):
case ((VENDOR_NTOP << 16) | 115):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_untunneled_l4_src_port,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 116):
case ((VENDOR_NTOP << 16) | 116):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_untunneled_ipv4_dst_addr,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 117):
case ((VENDOR_NTOP << 16) | 117):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_untunneled_l4_dst_port,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 120):
case ((VENDOR_NTOP << 16) | 120):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_dump_path,
tvb, offset, length, ENC_ASCII|ENC_NA);
break;
case (NTOP_BASE + 130):
case ((VENDOR_NTOP << 16) | 130):
gen_str = tvb_format_text(tvb, offset, length);
ti = proto_tree_add_string(pdutree, hf_pie_ntop_sip_call_id,
tvb, offset, length, gen_str);
break;
case (NTOP_BASE + 131):
case ((VENDOR_NTOP << 16) | 131):
gen_str = tvb_format_text(tvb, offset, length);
ti = proto_tree_add_string(pdutree, hf_pie_ntop_sip_calling_party,
tvb, offset, length, gen_str);
break;
case (NTOP_BASE + 132):
case ((VENDOR_NTOP << 16) | 132):
gen_str = tvb_format_text(tvb, offset, length);
ti = proto_tree_add_string(pdutree, hf_pie_ntop_sip_called_party,
tvb, offset, length, gen_str);
break;
case (NTOP_BASE + 133):
case ((VENDOR_NTOP << 16) | 133):
gen_str = tvb_format_text(tvb, offset, length);
ti = proto_tree_add_string(pdutree, hf_pie_ntop_sip_rtp_codecs,
tvb, offset, length, gen_str);
break;
case (NTOP_BASE + 134):
case ((VENDOR_NTOP << 16) | 134):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_sip_invite_time,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 135):
case ((VENDOR_NTOP << 16) | 135):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_sip_trying_time,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 136):
case ((VENDOR_NTOP << 16) | 136):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_sip_ringing_time,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 137):
case ((VENDOR_NTOP << 16) | 137):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_sip_ok_time,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 138):
case ((VENDOR_NTOP << 16) | 138):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_sip_bye_time,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 139):
case ((VENDOR_NTOP << 16) | 139):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_sip_rtp_src_ip,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 140):
case ((VENDOR_NTOP << 16) | 140):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_sip_rtp_src_port,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 141):
case ((VENDOR_NTOP << 16) | 141):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_sip_rtp_dst_ip,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 142):
case ((VENDOR_NTOP << 16) | 142):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_sip_rtp_dst_port,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 150):
case ((VENDOR_NTOP << 16) | 150):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_rtp_first_ssrc,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 151):
case ((VENDOR_NTOP << 16) | 151):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_rtp_first_ts,
tvb, offset, length, ENC_TIME_TIMESPEC|ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 152):
case ((VENDOR_NTOP << 16) | 152):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_rtp_last_ssrc,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 153):
case ((VENDOR_NTOP << 16) | 153):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_rtp_last_ts,
tvb, offset, length, ENC_TIME_TIMESPEC|ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 154):
case ((VENDOR_NTOP << 16) | 154):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_rtp_in_jitter,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 155):
case ((VENDOR_NTOP << 16) | 155):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_rtp_out_jitter,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 156):
case ((VENDOR_NTOP << 16) | 156):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_rtp_in_pkt_lost,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 157):
case ((VENDOR_NTOP << 16) | 157):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_rtp_out_pkt_lost,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 158):
case ((VENDOR_NTOP << 16) | 158):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_rtp_out_payload_type,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 159):
case ((VENDOR_NTOP << 16) | 159):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_rtp_in_max_delta,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 160):
case ((VENDOR_NTOP << 16) | 160):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_rtp_out_max_delta,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 168):
case ((VENDOR_NTOP << 16) | 168):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_proc_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 169):
case ((VENDOR_NTOP << 16) | 169):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_proc_name,
tvb, offset, length, ENC_ASCII|ENC_NA);
break;
case (NTOP_BASE + 180):
case ((VENDOR_NTOP << 16) | 180):
gen_str = tvb_format_text(tvb, offset, length);
ti = proto_tree_add_string(pdutree, hf_pie_ntop_http_url,
tvb, offset, length, gen_str);
break;
case (NTOP_BASE + 181):
case ((VENDOR_NTOP << 16) | 181):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_http_ret_code,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 182):
case ((VENDOR_NTOP << 16) | 182):
break;
case (NTOP_BASE + 183):
case ((VENDOR_NTOP << 16) | 183):
break;
case (NTOP_BASE + 184):
case ((VENDOR_NTOP << 16) | 184):
break;
case (NTOP_BASE + 185):
case ((VENDOR_NTOP << 16) | 185):
gen_str = tvb_format_text(tvb, offset, length);
ti = proto_tree_add_string(pdutree, hf_pie_ntop_smtp_mail_from,
tvb, offset, length, gen_str);
break;
case (NTOP_BASE + 186):
case ((VENDOR_NTOP << 16) | 186):
gen_str = tvb_format_text(tvb, offset, length);
ti = proto_tree_add_string(pdutree, hf_pie_ntop_smtp_rcpt_to,
tvb, offset, length, gen_str);
break;
case (NTOP_BASE + 190):
case ((VENDOR_NTOP << 16) | 190):
ti = proto_tree_add_item(pdutree, hf_cflow_flow_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case (NTOP_BASE + 195):
case ((VENDOR_NTOP << 16) | 195):
gen_str = tvb_format_text(tvb, offset, length);
ti = proto_tree_add_string(pdutree, hf_pie_ntop_mysql_server_version,
tvb, offset, length, gen_str);
break;
case (NTOP_BASE + 196):
case ((VENDOR_NTOP << 16) | 196):
gen_str = tvb_format_text(tvb, offset, length);
ti = proto_tree_add_string(pdutree, hf_pie_ntop_mysql_username,
tvb, offset, length, gen_str);
break;
case (NTOP_BASE + 197):
case ((VENDOR_NTOP << 16) | 197):
gen_str = tvb_format_text(tvb, offset, length);
ti = proto_tree_add_string(pdutree, hf_pie_ntop_mysql_db,
tvb, offset, length, gen_str);
break;
case (NTOP_BASE + 198):
case ((VENDOR_NTOP << 16) | 198):
gen_str = tvb_format_text(tvb, offset, length);
ti = proto_tree_add_string(pdutree, hf_pie_ntop_mysql_query,
tvb, offset, length, gen_str);
break;
case (NTOP_BASE + 199):
case ((VENDOR_NTOP << 16) | 199):
ti = proto_tree_add_item(pdutree, hf_pie_ntop_mysql_response,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case ((VENDOR_PLIXER << 16) | 100):
ti = proto_tree_add_item(pdutree, hf_pie_plixer_client_ip_v4,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case ((VENDOR_PLIXER << 16) | 101):
gen_str = tvb_format_text(tvb, offset, length);
ti = proto_tree_add_string(pdutree, hf_pie_plixer_client_hostname,
tvb, offset, length, gen_str);
break;
case ((VENDOR_PLIXER << 16) | 102):
gen_str = tvb_format_text(tvb, offset, length);
ti = proto_tree_add_string(pdutree, hf_pie_plixer_partner_name,
tvb, offset, length, gen_str);
break;
case ((VENDOR_PLIXER << 16) | 103):
gen_str = tvb_format_text(tvb, offset, length);
ti = proto_tree_add_string(pdutree, hf_pie_plixer_server_hostname,
tvb, offset, length, gen_str);
break;
case ((VENDOR_PLIXER << 16) | 104):
ti = proto_tree_add_item(pdutree, hf_pie_plixer_server_ip_v4,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case ((VENDOR_PLIXER << 16) | 105):
gen_str = tvb_format_text(tvb, offset, length);
ti = proto_tree_add_string(pdutree, hf_pie_plixer_recipient_address,
tvb, offset, length, gen_str);
break;
case ((VENDOR_PLIXER << 16) | 106):
ti = proto_tree_add_item(pdutree, hf_pie_plixer_event_id,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case ((VENDOR_PLIXER << 16) | 107):
gen_str = tvb_format_text(tvb, offset, length);
ti = proto_tree_add_string(pdutree, hf_pie_plixer_msgid,
tvb, offset, length, gen_str);
break;
case ((VENDOR_PLIXER << 16) | 108):
ti = proto_tree_add_item(pdutree, hf_pie_plixer_priority,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case ((VENDOR_PLIXER << 16) | 109):
ti = proto_tree_add_item(pdutree, hf_pie_plixer_recipient_report_status,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case ((VENDOR_PLIXER << 16) | 110):
ti = proto_tree_add_item(pdutree, hf_pie_plixer_number_recipients,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case ((VENDOR_PLIXER << 16) | 111):
ti = proto_tree_add_item(pdutree, hf_pie_plixer_origination_time,
tvb, offset, length, ENC_TIME_TIMESPEC|ENC_BIG_ENDIAN);
break;
case ((VENDOR_PLIXER << 16) | 112):
ti = proto_tree_add_item(pdutree, hf_pie_plixer_encryption,
tvb, offset, length, ENC_BIG_ENDIAN);
break;
case ((VENDOR_PLIXER << 16) | 113):
gen_str = tvb_format_text(tvb, offset, length);
ti = proto_tree_add_string(pdutree, hf_pie_plixer_service_version,
tvb, offset, length, gen_str);
break;
case ((VENDOR_PLIXER << 16) | 114):
gen_str = tvb_format_text(tvb, offset, length);
ti = proto_tree_add_string(pdutree, hf_pie_plixer_linked_msgid,
tvb, offset, length, gen_str);
break;
case ((VENDOR_PLIXER << 16) | 115):
gen_str = tvb_format_text(tvb, offset, length);
ti = proto_tree_add_string(pdutree, hf_pie_plixer_message_subject,
tvb, offset, length, gen_str);
break;
case ((VENDOR_PLIXER << 16) | 116):
gen_str = tvb_format_text(tvb, offset, length);
ti = proto_tree_add_string(pdutree, hf_pie_plixer_sender_address,
tvb, offset, length, gen_str);
break;
case ((VENDOR_PLIXER << 16) | 117):
ti = proto_tree_add_item(pdutree, hf_pie_plixer_date_time,
tvb, offset, length, ENC_TIME_TIMESPEC|ENC_BIG_ENDIAN);
break;
default:
if ((hdrinfo_p->vspec == 9) || (pen == REVPEN)) {
ti = proto_tree_add_bytes_format_value(pdutree, hf_cflow_unknown_field_type,
tvb, offset, length, NULL,
"Type %u: Value (hex bytes): %s",
masked_type,
tvb_bytes_to_str_punct(tvb, offset, length, ' '));
} else {
ti = proto_tree_add_bytes_format_value(pdutree, hf_ipfix_enterprise_private_entry,
tvb, offset, length, NULL,
"(%s) Type %u: Value (hex bytes): %s",
pen_str ? pen_str : "(null)",
masked_type,
tvb_bytes_to_str_punct(tvb, offset, length, ' '));
}
break;
}
if (ti && (vstr_len != 0)) {
proto_item_append_text(ti, " (Variable Length)");
PROTO_ITEM_SET_GENERATED(ti);
string_tree = proto_item_add_subtree(ti, ett_str_len);
proto_tree_add_uint(string_tree, hf_string_len_short, tvb,
gen_str_offset-vstr_len, 1, string_len_short);
if (vstr_len == 3) {
proto_tree_add_uint(string_tree, hf_string_len_long, tvb,
gen_str_offset-2, 2, string_len_long);
}
}
if (ti && (pen == REVPEN)) {
proto_item_append_text(ti, " (Reverse Type %u %s)",
masked_type,
val_to_str_ext_const(masked_type, &v9_v10_template_types_ext,"Unknown"));
}
offset += length;
}
for (i = 0; i < 2; i++) {
if (!(offset_s[i] && offset_e[i])) {
if (offset_s[i]) {
if (msec_start[i]) {
proto_tree_add_time(pdutree, hf_cflow_timestart, tvb,
offset_s[i], 4, &ts_start[i]);
} else {
proto_tree_add_time(pdutree, hf_cflow_abstimestart, tvb,
offset_s[i], 4, &ts_start[i]);
}
}
if (offset_e[i]) {
if (msec_end[i]) {
proto_tree_add_time(pdutree, hf_cflow_timeend, tvb,
offset_e[i], 4, &ts_end[i]);
} else {
proto_tree_add_time(pdutree, hf_cflow_abstimeend, tvb,
offset_s[i], 4, &ts_start[i]);
}
}
}
}
if (got_flags == GOT_TCP_UDP && (tmplt_p->tmplt_id == 256 || tmplt_p->tmplt_id == 258)) {
add_tcp_process_info(pinfo->fd->num, &local_addr, &remote_addr, local_port, remote_port, uid, pid, uname_str, cmd_str);
}
if (got_flags == GOT_TCP_UDP && (tmplt_p->tmplt_id == 257 || tmplt_p->tmplt_id == 259)) {
add_udp_process_info(pinfo->fd->num, &local_addr, &remote_addr, local_port, remote_port, uid, pid, uname_str, cmd_str);
}
return (guint) (offset - orig_offset);
}
static int
dissect_v9_v10_template_fields(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tmplt_tree, int offset,
hdrinfo_t *hdrinfo_p,
v9_v10_tmplt_t *tmplt_p,
v9_v10_tmplt_fields_type_t fields_type)
{
int ver;
int count;
int i;
DISSECTOR_ASSERT((fields_type==TF_SCOPES) || (fields_type==TF_ENTRIES));
ver = hdrinfo_p->vspec;
DISSECTOR_ASSERT((ver==9) || (ver==10));
count = tmplt_p->field_count[fields_type];
for(i=0; i<count; i++) {
guint16 type;
guint16 length;
guint32 pen;
const gchar *pen_str;
proto_tree *field_tree;
proto_item *field_item;
proto_item *ti;
pen = 0;
pen_str = NULL;
type = tvb_get_ntohs(tvb, offset);
length = tvb_get_ntohs(tvb,offset+2);
if ((ver == 10) && (type & 0x8000)) {
pen = tvb_get_ntohl(tvb,offset+4);
pen_str = val_to_str_ext_const(pen, &sminmpec_values_ext, "(Unknown)");
}
if (tmplt_p->fields_p[fields_type] != NULL) {
DISSECTOR_ASSERT (i < count);
tmplt_p->fields_p[fields_type][i].type = type;
tmplt_p->fields_p[fields_type][i].length = length;
tmplt_p->fields_p[fields_type][i].pen = pen;
tmplt_p->fields_p[fields_type][i].pen_str = pen_str;
if (length != VARIABLE_LENGTH) {
tmplt_p->length += length;
}
}
field_item = proto_tree_add_text(tmplt_tree, tvb, offset, 4+((pen_str!=NULL)?4:0), "Field (%u/%u)", i+1, count);
field_tree = proto_item_add_subtree(field_item, ett_field);
if (fields_type == TF_SCOPES) {
proto_item_append_text(field_item, " [Scope]");
}
if (ver == 9) {
proto_tree_add_item(field_tree, *v9_template_type_hf_list[fields_type],
tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(field_item, ": %s",
val_to_str_ext(type, v9_template_type_vse_list[fields_type], "Unknown(%d)"));
} else {
proto_tree_add_item(field_tree, hf_cflow_template_ipfix_pen_provided,
tvb, offset, 2, ENC_BIG_ENDIAN);
if ( !(type & 0x8000) || (pen == REVPEN)) {
proto_item *rp_ti;
rp_ti = proto_tree_add_item(field_tree, *v10_template_type_hf_list[fields_type],
tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(field_item, ": %s",
val_to_str_ext(type&0x7fff, v10_template_type_vse_list[fields_type], "Unknown(%d)"));
if (pen == REVPEN) {
proto_item_append_text(rp_ti, " [Reverse]");
proto_item_append_text(field_item, " [Reverse]");
}
} else {
int fields_type_pen = pen_to_type_hf_list(pen);
if (fields_type_pen != TF_NO_VENDOR_INFO) {
proto_tree_add_item(field_tree, *v10_template_type_hf_list[fields_type_pen],
tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(field_item, ": %s",
val_to_str_ext(type&0x7fff, v10_template_type_vse_list[fields_type_pen], "Unknown(%d)"));
} else {
proto_item *pen_ti;
pen_ti = proto_tree_add_item(field_tree, hf_cflow_template_ipfix_field_type_enterprise,
tvb, offset, 2, ENC_BIG_ENDIAN);
proto_item_append_text(pen_ti, " [pen: %s]", pen_str);
proto_item_append_text(field_item, ": %3u [pen: %s]", type&0x7fff, pen_str);
}
}
}
offset += 2;
ti = proto_tree_add_item(field_tree, hf_cflow_template_field_length, tvb,
offset, 2, ENC_BIG_ENDIAN);
if (length == VARIABLE_LENGTH) {
proto_item_append_text(ti, " [i.e.: \"Variable Length\"]");
}
offset += 2;
if ((ver == 10) && (type & 0x8000)) {
proto_tree_add_uint_format_value(field_tree, hf_cflow_template_ipfix_field_pen, tvb, offset, 4,
pen, "%s (%u)", pen_str, pen);
offset += 4;
}
}
return offset;
}
static int
dissect_v9_v10_options_template(tvbuff_t *tvb, packet_info *pinfo, proto_tree *pdutree, int offset, int length,
hdrinfo_t *hdrinfo_p, guint16 flowset_id)
{
int remaining;
remaining = length;
while (remaining > 3) {
v9_v10_tmplt_t *tmplt_p;
v9_v10_tmplt_t tmplt;
proto_tree *tmplt_tree;
proto_item *tmplt_item;
proto_item *ti;
guint16 id;
guint16 option_scope_field_count;
guint16 option_field_count;
int orig_offset;
orig_offset = offset;
id = tvb_get_ntohs(tvb, offset);
tmplt_item = proto_tree_add_text(pdutree, tvb, offset, -1, "Options Template (Id = %u)", id);
tmplt_tree = proto_item_add_subtree(tmplt_item, ett_template);
proto_tree_add_item(tmplt_tree, hf_cflow_template_id, tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (flowset_id == FLOWSET_ID_V9_OPTIONS_TEMPLATE) {
option_scope_field_count = tvb_get_ntohs(tvb, offset)/4;
proto_tree_add_item(tmplt_tree,
hf_cflow_option_scope_length,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
option_field_count = tvb_get_ntohs(tvb, offset)/4;
ti = proto_tree_add_item(tmplt_tree,
hf_cflow_option_length,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
} else {
guint16 option_total_field_count;
option_total_field_count = tvb_get_ntohs(tvb, offset);
proto_tree_add_item(tmplt_tree,
hf_cflow_template_ipfix_total_field_count,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
option_scope_field_count = tvb_get_ntohs(tvb, offset);
ti = proto_tree_add_item(tmplt_tree,
hf_cflow_template_ipfix_scope_field_count,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
option_field_count = option_total_field_count - option_scope_field_count;
if (option_scope_field_count == 0) {
expert_add_info_format(pinfo, ti, PI_MALFORMED, PI_WARN,
"No scope fields");
return 0;
}
if (option_scope_field_count > option_total_field_count) {
expert_add_info_format(pinfo, ti, PI_MALFORMED, PI_WARN,
"More scope fields (%u) than fields (%u)",
option_scope_field_count, option_total_field_count);
return 0;
}
}
proto_item_append_text(tmplt_item,
" (Scope Count = %u; Data Count = %u)",
option_scope_field_count, option_field_count);
proto_item_set_len(tmplt_item, 6 +4*(option_scope_field_count+option_field_count));
if (v9_tmplt_max_fields &&
(option_field_count > v9_tmplt_max_fields)) {
expert_add_info_format(pinfo, ti, PI_UNDECODED, PI_WARN,
"More options (%u) than we can handle."
" Maximum value can be adjusted in the protocol preferences.",
option_field_count);
}
if (v9_tmplt_max_fields &&
(option_scope_field_count > v9_tmplt_max_fields)) {
expert_add_info_format(pinfo, ti, PI_UNDECODED, PI_WARN,
"More scopes (%u) than we can handle [template won't be used]."
" Maximum value can be adjusted in the protocol preferences.",
option_scope_field_count);
}
memset(&tmplt, 0, sizeof(tmplt));
v9_v10_tmplt_build_key(&tmplt, pinfo, hdrinfo_p->src_id, id);
tmplt.field_count[TF_SCOPES] = option_scope_field_count;
tmplt.field_count[TF_ENTRIES] = option_field_count;
tmplt_p = g_hash_table_lookup(v9_v10_tmplt_table, &tmplt);
if (!pinfo->fd->flags.visited) {
do {
if ((option_scope_field_count == 0) ||
(v9_tmplt_max_fields &&
((option_scope_field_count > v9_tmplt_max_fields)
|| (option_field_count > v9_tmplt_max_fields)))) {
break;
}
if (tmplt_p != NULL) {
break;
}
tmplt.fields_p[TF_SCOPES] = se_alloc0(option_scope_field_count *sizeof(v9_v10_tmplt_entry_t));
tmplt.fields_p[TF_ENTRIES] = se_alloc0(option_field_count *sizeof(v9_v10_tmplt_entry_t));
break;
} while (FALSE);
}
offset = dissect_v9_v10_template_fields(tvb, pinfo, tmplt_tree, offset,
hdrinfo_p, &tmplt, TF_SCOPES);
offset = dissect_v9_v10_template_fields(tvb, pinfo, tmplt_tree, offset,
hdrinfo_p, &tmplt, TF_ENTRIES);
if ((tmplt_p == NULL) && (tmplt.fields_p[TF_SCOPES] || tmplt.fields_p[TF_ENTRIES])) {
tmplt_p = se_memdup(&tmplt, sizeof(tmplt));
SE_COPY_ADDRESS(&tmplt_p->src_addr, &pinfo->net_src);
SE_COPY_ADDRESS(&tmplt_p->dst_addr, &pinfo->net_dst);
g_hash_table_insert(v9_v10_tmplt_table, tmplt_p, tmplt_p);
}
remaining -= offset - orig_offset;
}
if (remaining > 0)
flow_process_textfield(pdutree, tvb, offset, remaining, "[Padding]");
return length;
}
static int
dissect_v9_v10_data_template(tvbuff_t *tvb, packet_info *pinfo, proto_tree *pdutree, int offset, int length,
hdrinfo_t *hdrinfo_p, guint16 flowset_id _U_)
{
int remaining;
remaining = length;
while (remaining > 3) {
v9_v10_tmplt_t *tmplt_p;
v9_v10_tmplt_t tmplt;
proto_tree *tmplt_tree;
proto_item *tmplt_item;
proto_item *ti;
guint16 id;
guint16 count;
int orig_offset;
orig_offset = offset;
id = tvb_get_ntohs(tvb, offset);
count = tvb_get_ntohs(tvb, offset + 2);
tmplt_item = proto_tree_add_text(pdutree, tvb, offset,
4 + 4 * count ,
"Template (Id = %u, Count = %u)", id, count);
tmplt_tree = proto_item_add_subtree(tmplt_item, ett_template);
proto_tree_add_item(tmplt_tree, hf_cflow_template_id, tvb,
offset, 2, ENC_BIG_ENDIAN);
offset += 2;
ti = proto_tree_add_item(tmplt_tree, hf_cflow_template_field_count,
tvb, offset, 2, ENC_BIG_ENDIAN);
offset += 2;
if (v9_tmplt_max_fields && (count > v9_tmplt_max_fields)) {
expert_add_info_format(pinfo, ti, PI_UNDECODED, PI_WARN,
"More entries (%u) than we can handle [template won't be used]."
" Maximum value can be adjusted in the protocol preferences.",
count);
}
memset(&tmplt, 0, sizeof(tmplt));
v9_v10_tmplt_build_key(&tmplt, pinfo, hdrinfo_p->src_id, id);
tmplt.field_count[TF_ENTRIES] = count;
tmplt_p = g_hash_table_lookup(v9_v10_tmplt_table, &tmplt);
if (!pinfo->fd->flags.visited) {
do {
if ((count == 0) ||
(v9_tmplt_max_fields && (count > v9_tmplt_max_fields))) {
break;
}
if (tmplt_p != NULL) {
break;
}
tmplt.fields_p[TF_ENTRIES] = se_alloc0(count * sizeof(v9_v10_tmplt_entry_t));
break;
} while (FALSE);
}
offset = dissect_v9_v10_template_fields(tvb, pinfo, tmplt_tree, offset,
hdrinfo_p, &tmplt, TF_ENTRIES);
if ((tmplt_p == NULL) && tmplt.fields_p[TF_ENTRIES]) {
tmplt_p = se_memdup(&tmplt, sizeof(tmplt));
SE_COPY_ADDRESS(&tmplt_p->src_addr, &pinfo->net_src);
SE_COPY_ADDRESS(&tmplt_p->dst_addr, &pinfo->net_dst);
g_hash_table_insert(v9_v10_tmplt_table, tmplt_p, tmplt_p);
}
remaining -= offset - orig_offset;
}
if (remaining > 0)
flow_process_textfield(pdutree, tvb, offset, remaining, "[Padding]");
return length;
}
static v9_v10_tmplt_t *v9_v10_tmplt_build_key(v9_v10_tmplt_t *tmplt_p, packet_info *pinfo, guint32 src_id, guint16 tmplt_id)
{
SET_ADDRESS(&tmplt_p->src_addr, pinfo->net_src.type, pinfo->net_src.len, pinfo->net_src.data);
tmplt_p->src_port = pinfo->srcport;
SET_ADDRESS(&tmplt_p->dst_addr, pinfo->net_dst.type, pinfo->net_dst.len, pinfo->net_dst.data);
tmplt_p->dst_port = pinfo->destport;
tmplt_p->src_id = src_id;
tmplt_p->tmplt_id = tmplt_id;
return tmplt_p;
}
static gboolean
v9_v10_tmplt_table_equal(gconstpointer k1, gconstpointer k2)
{
const v9_v10_tmplt_t *ta = k1;
const v9_v10_tmplt_t *tb = k2;
return (
(CMP_ADDRESS(&ta->src_addr, &tb->src_addr) == 0) &&
(ta->src_port == tb->src_port) &&
(CMP_ADDRESS(&ta->dst_addr, &tb->dst_addr) == 0) &&
(ta->dst_port == tb->dst_port) &&
(ta->src_id == tb->src_id) &&
(ta->tmplt_id == tb->tmplt_id)
);
}
static guint
v9_v10_tmplt_table_hash(gconstpointer k)
{
const v9_v10_tmplt_t *tmplt_p = k;
guint32 val;
val = tmplt_p->src_id + (tmplt_p->tmplt_id << 9) + tmplt_p->src_port + tmplt_p->dst_port;
ADD_ADDRESS_TO_HASH(val, &tmplt_p->src_addr);
ADD_ADDRESS_TO_HASH(val, &tmplt_p->dst_addr);
return val;
}
static int
dissect_pdu(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *pdutree, int offset, hdrinfo_t *hdrinfo_p)
{
proto_item *hidden_item;
int startoffset = offset;
guint32 srcaddr, dstaddr;
guint8 mask;
nstime_t ts;
guint8 ver;
memset(&ts, 0, sizeof(ts));
srcaddr = tvb_get_ipv4(tvb, offset);
proto_tree_add_ipv4(pdutree, hf_cflow_srcaddr, tvb, offset, 4, srcaddr);
offset += 4;
dstaddr = tvb_get_ipv4(tvb, offset);
proto_tree_add_ipv4(pdutree, hf_cflow_dstaddr, tvb, offset, 4, dstaddr);
offset += 4;
proto_tree_add_item(pdutree, hf_cflow_nexthop, tvb, offset, 4, ENC_NA);
offset += 4;
offset = flow_process_ints(pdutree, tvb, offset);
offset = flow_process_sizecount(pdutree, tvb, offset);
offset = flow_process_timeperiod(pdutree, tvb, offset);
offset = flow_process_ports(pdutree, tvb, offset);
ver = hdrinfo_p->vspec;
if (ver == 1) {
offset = flow_process_textfield(pdutree, tvb, offset, 2, "padding");
proto_tree_add_item(pdutree, hf_cflow_prot, tvb, offset++, 1, ENC_NA);
proto_tree_add_item(pdutree, hf_cflow_tos, tvb, offset++, 1, ENC_NA);
proto_tree_add_item(pdutree, hf_cflow_tcpflags, tvb, offset++, 1, ENC_NA);
offset = flow_process_textfield(pdutree, tvb, offset, 3, "padding");
offset = flow_process_textfield(pdutree, tvb, offset, 4, "reserved");
} else {
if (ver == 5)
offset = flow_process_textfield(pdutree, tvb, offset, 1, "padding");
else {
proto_tree_add_item(pdutree, hf_cflow_flags, tvb, offset++, 1, ENC_NA);
}
proto_tree_add_item(pdutree, hf_cflow_tcpflags, tvb, offset++, 1, ENC_NA);
proto_tree_add_item(pdutree, hf_cflow_prot, tvb, offset++, 1, ENC_NA);
proto_tree_add_item(pdutree, hf_cflow_tos, tvb, offset++, 1, ENC_NA);
offset = flow_process_aspair(pdutree, tvb, offset);
mask = tvb_get_guint8(tvb, offset);
proto_tree_add_text(pdutree, tvb, offset, 1,
"SrcMask: %u (prefix: %s/%u)",
mask, getprefix(&srcaddr, mask),
mask != 0 ? mask : 32);
hidden_item = proto_tree_add_uint(pdutree, hf_cflow_srcmask, tvb, offset++, 1, mask);
PROTO_ITEM_SET_HIDDEN(hidden_item);
mask = tvb_get_guint8(tvb, offset);
proto_tree_add_text(pdutree, tvb, offset, 1,
"DstMask: %u (prefix: %s/%u)",
mask, getprefix(&dstaddr, mask),
mask != 0 ? mask : 32);
hidden_item = proto_tree_add_uint(pdutree, hf_cflow_dstmask, tvb, offset++, 1, mask);
PROTO_ITEM_SET_HIDDEN(hidden_item);
offset = flow_process_textfield(pdutree, tvb, offset, 2, "padding");
if (ver == 7) {
proto_tree_add_item(pdutree, hf_cflow_routersc, tvb, offset, 4, ENC_NA);
offset += 4;
}
}
return (offset - startoffset);
}
static const gchar *
getprefix(const guint32 *addr, int prefix)
{
guint32 gprefix;
gprefix = *addr & g_htonl((0xffffffff << (32 - prefix)));
return (ip_to_str((const guint8 *)&gprefix));
}
static void
netflow_init(void)
{
if (v9_v10_tmplt_table != NULL) {
g_hash_table_destroy(v9_v10_tmplt_table);
}
v9_v10_tmplt_table = g_hash_table_new(v9_v10_tmplt_table_hash, v9_v10_tmplt_table_equal);
}
void
proto_register_netflow(void)
{
static hf_register_info hf[] = {
{&hf_cflow_version,
{"Version", "cflow.version",
FT_UINT16, BASE_DEC, NULL, 0x0,
"NetFlow Version", HFILL}
},
{&hf_cflow_len,
{"Length", "cflow.len",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Length of PDUs", HFILL}
},
{&hf_cflow_count,
{"Count", "cflow.count",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Count of PDUs", HFILL}
},
{&hf_cflow_sysuptime,
{"SysUptime", "cflow.sysuptime",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Time since router booted (in milliseconds)", HFILL}
},
{&hf_cflow_exporttime,
{"ExportTime", "cflow.exporttime",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Time when the flow has been exported", HFILL}
},
{&hf_cflow_timestamp,
{"Timestamp", "cflow.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
"Current seconds since epoch", HFILL}
},
{&hf_cflow_unix_secs,
{"CurrentSecs", "cflow.unix_secs",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Current seconds since epoch", HFILL}
},
{&hf_cflow_unix_nsecs,
{"CurrentNSecs", "cflow.unix_nsecs",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Residual nanoseconds since epoch", HFILL}
},
{&hf_cflow_samplingmode,
{"SamplingMode", "cflow.samplingmode",
FT_UINT16, BASE_DEC, VALS(v5_sampling_mode), 0xC000,
"Sampling Mode of exporter", HFILL}
},
{&hf_cflow_samplerate,
{"SampleRate", "cflow.samplerate",
FT_UINT16, BASE_DEC, NULL, 0x3FFF,
"Sample Frequency of exporter", HFILL}
},
{&hf_cflow_sequence,
{"FlowSequence", "cflow.sequence",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Sequence number of flows seen", HFILL}
},
{&hf_cflow_engine_type,
{"EngineType", "cflow.engine_type",
FT_UINT8, BASE_DEC, VALS(engine_type), 0x0,
"Flow switching engine type", HFILL}
},
{&hf_cflow_engine_id,
{"EngineId", "cflow.engine_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Slot number of switching engine", HFILL}
},
{&hf_cflow_source_id,
{"SourceId", "cflow.source_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Identifier for export device", HFILL}
},
{&hf_cflow_aggmethod,
{"AggMethod", "cflow.aggmethod",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &v8_agg_ext, 0x0,
"CFlow V8 Aggregation Method", HFILL}
},
{&hf_cflow_aggversion,
{"AggVersion", "cflow.aggversion",
FT_UINT8, BASE_DEC, NULL, 0x0,
"CFlow V8 Aggregation Version", HFILL}
},
{&hf_cflow_flowset_id,
{"FlowSet Id", "cflow.flowset_id",
FT_UINT16, BASE_RANGE_STRING | BASE_DEC, RVALS(rs_flowset_ids), 0x0,
NULL, HFILL}
},
{&hf_cflow_flowset_length,
{"FlowSet Length", "cflow.flowset_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_template_id,
{"Template Id", "cflow.template_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_template_field_count,
{"Field Count", "cflow.template_field_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Template field count", HFILL}
},
{&hf_cflow_template_field_type,
{"Type", "cflow.template_field_type",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &v9_v10_template_types_ext, 0x0,
"Template field type", HFILL}
},
{&hf_cflow_template_field_length,
{"Length", "cflow.template_field_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Template field length", HFILL}
},
{&hf_cflow_option_scope_length,
{"Option Scope Length", "cflow.option_scope_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_option_length,
{"Option Length", "cflow.option_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_template_scope_field_type,
{"Scope Type", "cflow.scope_field_type",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &v9_scope_field_types_ext, 0x0,
"Scope field type", HFILL}
},
{&hf_cflow_icmp_type,
{"ICMP Type", "cflow.icmp_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_igmp_type,
{"IGMP Type", "cflow.igmp_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_sampling_interval,
{"Sampling interval", "cflow.sampling_interval",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_sampling_algorithm,
{"Sampling algorithm", "cflow.sampling_algorithm",
FT_UINT8, BASE_DEC, VALS(v5_sampling_mode), 0x0,
NULL, HFILL}
},
{&hf_cflow_flow_active_timeout,
{"Flow active timeout", "cflow.flow_active_timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_flow_inactive_timeout,
{"Flow inactive timeout", "cflow.flow_inactive_timeout",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_srcaddr,
{"SrcAddr", "cflow.srcaddr",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Flow Source Address (IPv4)", HFILL}
},
{&hf_cflow_srcaddr_v6,
{"SrcAddr", "cflow.srcaddrv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Flow Source Address (IPv6)", HFILL}
},
{&hf_cflow_srcnet,
{"SrcNet", "cflow.srcnet",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Flow Source Network", HFILL}
},
{&hf_cflow_dstaddr,
{"DstAddr", "cflow.dstaddr",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Flow Destination Address (IPv4)", HFILL}
},
{&hf_cflow_dstaddr_v6,
{"DstAddr", "cflow.dstaddrv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Flow Destination Address (IPv6)", HFILL}
},
{&hf_cflow_dstnet,
{"DstNet", "cflow.dstnet",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Flow Destination Network", HFILL}
},
{&hf_cflow_nexthop,
{"NextHop", "cflow.nexthop",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Router nexthop (IPv4)", HFILL}
},
{&hf_cflow_nexthop_v6,
{"NextHop", "cflow.nexthopv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Router nexthop (IPv6)", HFILL}
},
{&hf_cflow_bgpnexthop,
{"BGPNextHop", "cflow.bgpnexthop",
FT_IPv4, BASE_NONE, NULL, 0x0,
"BGP Router Nexthop (IPv4)", HFILL}
},
{&hf_cflow_bgpnexthop_v6,
{"BGPNextHop", "cflow.bgpnexthopv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
"BGP Router Nexthop (IPv6)", HFILL}
},
{&hf_cflow_inputint,
{"InputInt", "cflow.inputint",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Flow Input Interface", HFILL}
},
{&hf_cflow_outputint,
{"OutputInt", "cflow.outputint",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Flow Output Interface", HFILL}
},
{&hf_cflow_flows,
{"Flows", "cflow.flows",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Flows Aggregated in PDU", HFILL}
},
{&hf_cflow_flows64,
{"Flows", "cflow.flows64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Flows Aggregated in PDU", HFILL}
},
{&hf_cflow_packets,
{"Packets", "cflow.packets",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Count of packets", HFILL}
},
{&hf_cflow_packets64,
{"Packets", "cflow.packets64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Count of packets", HFILL}
},
{&hf_cflow_octets,
{"Octets", "cflow.octets",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Count of bytes", HFILL}
},
{&hf_cflow_octets64,
{"Octets", "cflow.octets64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Count of bytes", HFILL}
},
{&hf_cflow_length_min,
{"MinLength", "cflow.length_min",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Packet Length Min", HFILL}
},
{&hf_cflow_length_max,
{"MaxLength", "cflow.length_max",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Packet Length Max", HFILL}
},
{&hf_cflow_timedelta,
{"Duration", "cflow.timedelta",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"Duration of flow sample (end - start)", HFILL}
},
{&hf_cflow_timestart,
{"StartTime", "cflow.timestart",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"Uptime at start of flow", HFILL}
},
{&hf_cflow_timeend,
{"EndTime", "cflow.timeend",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
"Uptime at end of flow", HFILL}
},
{&hf_cflow_srcport,
{"SrcPort", "cflow.srcport",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Flow Source Port", HFILL}
},
{&hf_cflow_dstport,
{"DstPort", "cflow.dstport",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Flow Destination Port", HFILL}
},
{&hf_cflow_prot,
{"Protocol", "cflow.protocol",
FT_UINT8, BASE_DEC, NULL, 0x0,
"IP Protocol", HFILL}
},
{&hf_cflow_tos,
{"IP ToS", "cflow.tos",
FT_UINT8, BASE_HEX, NULL, 0x0,
"IP Type of Service", HFILL}
},
{&hf_cflow_flags,
{"Export Flags", "cflow.flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
"CFlow Flags", HFILL}
},
{&hf_cflow_tcpflags,
{"TCP Flags", "cflow.tcpflags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_srcas,
{"SrcAS", "cflow.srcas",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Source AS", HFILL}
},
{&hf_cflow_dstas,
{"DstAS", "cflow.dstas",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Destination AS", HFILL}
},
{&hf_cflow_srcmask,
{"SrcMask", "cflow.srcmask",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Source Prefix Mask", HFILL}
},
{&hf_cflow_srcmask_v6,
{"SrcMask", "cflow.srcmaskv6",
FT_UINT8, BASE_DEC, NULL, 0x0,
"IPv6 Source Prefix Mask", HFILL}
},
{&hf_cflow_dstmask,
{"DstMask", "cflow.dstmask",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Destination Prefix Mask", HFILL}
},
{&hf_cflow_dstmask_v6,
{"DstMask", "cflow.dstmaskv6",
FT_UINT8, BASE_DEC, NULL, 0x0,
"IPv6 Destination Prefix Mask", HFILL}
},
{&hf_cflow_routersc,
{"Router Shortcut", "cflow.routersc",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Router shortcut by switch", HFILL}
},
{&hf_cflow_mulpackets,
{"MulticastPackets", "cflow.mulpackets",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Count of multicast packets", HFILL}
},
{&hf_cflow_muloctets,
{"MulticastOctets", "cflow.muloctets",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Count of multicast octets", HFILL}
},
{&hf_cflow_octets_exp,
{"OctetsExp", "cflow.octetsexp",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Octets exported", HFILL}
},
{&hf_cflow_octets_exp64,
{"OctetsExp", "cflow.octetsexp64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Octets exported", HFILL}
},
{&hf_cflow_packets_exp,
{"PacketsExp", "cflow.packetsexp",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Packets exported", HFILL}
},
{&hf_cflow_packets_exp64,
{"PacketsExp", "cflow.packetsexp64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Packets exported", HFILL}
},
{&hf_cflow_flows_exp,
{"FlowsExp", "cflow.flowsexp",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Flows exported", HFILL}
},
{&hf_cflow_flows_exp64,
{"FlowsExp", "cflow.flowsexp64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Flows exported", HFILL}
},
{&hf_cflow_srcprefix,
{"SrcPrefix", "cflow.srcprefix",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Flow Source Prefix", HFILL}
},
{&hf_cflow_dstprefix,
{"DstPrefix", "cflow.dstprefix",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Flow Destination Prefix", HFILL}
},
{&hf_cflow_mpls_top_label_type,
{"TopLabelType", "cflow.toplabeltype",
FT_UINT8, BASE_DEC, VALS(special_mpls_top_label_type), 0x0,
"Top MPLS label Type", HFILL}
},
{&hf_cflow_mpls_pe_addr,
{"TopLabelAddr", "cflow.toplabeladdr",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Top MPLS label PE address", HFILL}
},
{&hf_cflow_sampler_id,
{"SamplerID", "cflow.sampler_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Flow Sampler ID", HFILL}
},
{&hf_cflow_sampler_mode,
{"SamplerMode", "cflow.sampler_mode",
FT_UINT8, BASE_DEC, VALS(v9_sampler_mode), 0x0,
"Flow Sampler Mode", HFILL}
},
{&hf_cflow_sampler_random_interval,
{"SamplerRandomInterval", "cflow.sampler_random_interval",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Flow Sampler Random Interval", HFILL}
},
{&hf_cflow_flow_class,
{"FlowClass", "cflow.flow_class",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Flow Class", HFILL}
},
{&hf_cflow_ttl_minimum,
{"MinTTL", "cflow.ttl_min",
FT_UINT8, BASE_DEC, NULL, 0x0,
"TTL minimum", HFILL}
},
{&hf_cflow_ttl_maximum,
{"MaxTTL", "cflow.ttl_max",
FT_UINT8, BASE_DEC, NULL, 0x0,
"TTL maximum", HFILL}
},
{&hf_cflow_ipv4_id,
{"IPv4Ident", "cflow.ipv4_ident",
FT_UINT16, BASE_DEC, NULL, 0x0,
"IPv4 Identifier", HFILL}
},
{&hf_cflow_ip_version,
{"IPVersion", "cflow.ip_version",
FT_BYTES, BASE_NONE, NULL, 0x0,
"IP Version", HFILL}
},
{&hf_cflow_direction,
{"Direction", "cflow.direction",
FT_UINT8, BASE_DEC, VALS(v9_direction), 0x0,
NULL, HFILL}
},
{&hf_cflow_if_name,
{"IfName", "cflow.if_name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"SNMP Interface Name", HFILL}
},
{&hf_cflow_if_descr,
{"IfDescr", "cflow.if_descr",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"SNMP Interface Description", HFILL}
},
{&hf_cflow_sampler_name,
{"SamplerName", "cflow.sampler_name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Sampler Name", HFILL}
},
{&hf_cflow_forwarding_status,
{"ForwdStat", "cflow.forwarding_status",
FT_UINT8, BASE_DEC, VALS(v9_forwarding_status), 0xC0,
"Forwarding Status", HFILL}
},
{&hf_cflow_forwarding_status_unknown_code,
{"ForwdCode", "cflow.forwarding_status_unknown_code",
FT_UINT8, BASE_DEC, VALS(v9_forwarding_status_unknown_code), 0x3F,
NULL, HFILL}
},
{&hf_cflow_forwarding_status_forward_code,
{"ForwdCode", "cflow.forwarding_status_foreward_code",
FT_UINT8, BASE_DEC, VALS(v9_forwarding_status_forward_code), 0x3F,
NULL, HFILL}
},
{&hf_cflow_forwarding_status_drop_code,
{"ForwdCode", "cflow.forwarding_status_drop_code",
FT_UINT8, BASE_DEC, VALS(v9_forwarding_status_drop_code), 0x3F,
NULL, HFILL}
},
{&hf_cflow_forwarding_status_consume_code,
{"ForwdCode", "cflow.forwarding_status_consume_code",
FT_UINT8, BASE_DEC, VALS(v9_forwarding_status_consume_code), 0x3F,
NULL, HFILL}
},
{&hf_cflow_nbar_appl_desc,
{"ApplicationDesc", "cflow.appl_desc",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Application Desc (NBAR)", HFILL}
},
{&hf_cflow_nbar_appl_id,
{"ApplicationID", "cflow.appl_id",
FT_UINT32, BASE_CUSTOM, nbar_fmt_id, 0x0,
"Application ID (NBAR)", HFILL}
},
{&hf_cflow_nbar_appl_name,
{"ApplicationName", "cflow.appl_name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Application Name (NBAR)", HFILL}
},
{&hf_cflow_peer_srcas,
{"PeerSrcAS", "cflow.peer_srcas",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Peer Source AS", HFILL}
},
{&hf_cflow_peer_dstas,
{"PeerDstAS", "cflow.peer_dstas",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Peer Destination AS", HFILL}
},
{&hf_cflow_flow_exporter,
{"FlowExporter", "cflow.flow_exporter",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_icmp_ipv4_type,
{"IPv4 ICMP Type", "cflow.icmp_ipv4_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_icmp_ipv4_code,
{"IPv4 ICMP Code", "cflow.icmp_ipv4_code",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_icmp_ipv6_type,
{"IPv6 ICMP Type", "cflow.icmp_ipv6_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_icmp_ipv6_code,
{"IPv6 ICMP Code", "cflow.icmp_ipv6_code",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_tcp_window_size,
{"TCP Windows Size", "cflow.tcp_windows_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_ipv4_total_length,
{"IPV4 Total Length", "cflow.ipv4_total_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_ip_ttl,
{"IP TTL", "cflow.ip_ttl",
FT_UINT8, BASE_DEC, NULL, 0x0,
"IP time to live", HFILL}
},
{&hf_cflow_ip_tos,
{"IP TOS", "cflow.ip_tos",
FT_UINT8, BASE_DEC, NULL, 0x0,
"IP type of service", HFILL}
},
{&hf_cflow_ip_dscp,
{"DSCP", "cflow.ip_dscp",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_octets_squared64,
{"OctetsSquared", "cflow.octets_squared",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_udp_length,
{"UDP Length", "cflow.udp_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_is_multicast,
{"IsMulticast", "cflow.is_multicast",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_ip_header_words,
{"IPHeaderLen", "cflow.ip_header_words",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_option_map,
{"OptionMap", "cflow.option_map",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_section_header,
{"SectionHeader", "cflow.section_header",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Header of Packet", HFILL}
},
{&hf_cflow_section_payload,
{"SectionPayload", "cflow.section_payload",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Payload of Packet", HFILL}
},
{&hf_cflow_post_octets,
{"Post Octets", "cflow.post_octets",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Count of post bytes", HFILL}
},
{&hf_cflow_post_octets64,
{"Post Octets", "cflow.post_octets64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Count of post bytes", HFILL}
},
{&hf_cflow_post_packets,
{"Post Packets", "cflow.post_packets",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Count of post packets", HFILL}
},
{&hf_cflow_post_packets64,
{"Post Packets", "cflow.post_packets64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Count of post packets", HFILL}
},
{&hf_cflow_ipv6_flowlabel,
{"ipv6FlowLabel", "cflow.ipv6flowlabel",
FT_UINT32, BASE_DEC, NULL, 0x0,
"IPv6 Flow Label", HFILL}
},
{&hf_cflow_ipv6_flowlabel24,
{"ipv6FlowLabel", "cflow.ipv6flowlabel24",
FT_UINT32, BASE_DEC, NULL, 0x0,
"IPv6 Flow Label", HFILL}
},
{&hf_cflow_post_tos,
{"Post IP ToS", "cflow.post_tos",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Post IP Type of Service", HFILL}
},
{&hf_cflow_srcmac,
{"Source Mac Address", "cflow.srcmac",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_post_dstmac,
{"Post Destination Mac Address", "cflow.post_dstmac",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_vlanid,
{"Vlan Id", "cflow.vlanid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_post_vlanid,
{"Post Vlan Id", "cflow.post_vlanid",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_ipv6_exthdr,
{"IPv6 Extension Headers", "cflow.ipv6_exthdr",
FT_UINT32, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_dstmac,
{"Destination Mac Address", "cflow.dstmac",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_post_srcmac,
{"Post Source Mac Address", "cflow.post_srcmac",
FT_ETHER, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_permanent_packets,
{"Permanent Packets", "cflow.permanent_packets",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Running Count of packets for permanent flows", HFILL}
},
{&hf_cflow_permanent_packets64,
{"Permanent Packets", "cflow.permanent_packets64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Running Count of packets for permanent flows", HFILL}
},
{&hf_cflow_permanent_octets,
{"Permanent Octets", "cflow.permanent_octets",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Running Count of bytes for permanent flows", HFILL}
},
{&hf_cflow_permanent_octets64,
{"Permanent Octets", "cflow.permanent_octets64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Running Count of bytes for permanent flows", HFILL}
},
{&hf_cflow_fragment_offset,
{"Fragment Offset", "cflow.fragment_offset",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_mpls_vpn_rd,
{"MPLS VPN RD", "cflow.mpls_vpn_rd",
FT_BYTES, BASE_NONE, NULL, 0x0,
"MPLS VPN Route Distinguisher", HFILL}
},
{&hf_cflow_mpls_top_label_prefix_length,
{"Mpls Top Label Prefix Length", "cflow.mpls_top_label_prefix_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_post_ip_diff_serv_code_point,
{"Post Ip Diff Serv Code Point", "cflow.post_ip_diff_serv_code_point",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_multicast_replication_factor,
{"Multicast Replication Factor", "cflow.multicast_replication_factor",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_exporter_addr,
{"ExporterAddr", "cflow.exporter_addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Flow Exporter Address", HFILL}
},
{&hf_cflow_exporter_addr_v6,
{"ExporterAddr", "cflow.exporter_addr_v6",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Flow Exporter Address", HFILL}
},
{&hf_cflow_drop_octets,
{"Dropped Octets", "cflow.drop_octets",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Count of dropped bytes", HFILL}
},
{&hf_cflow_drop_octets64,
{"Dropped Octets", "cflow.drop_octets64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Count of dropped bytes", HFILL}
},
{&hf_cflow_drop_packets,
{"Dropped Packets", "cflow.drop_packets",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Count of dropped packets", HFILL}
},
{&hf_cflow_drop_packets64,
{"Dropped Packets", "cflow.drop_packets64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Count of dropped packets", HFILL}
},
{&hf_cflow_drop_total_octets,
{"Dropped Total Octets", "cflow.drop_total_octets",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Count of total dropped bytes", HFILL}
},
{&hf_cflow_drop_total_octets64,
{"Dropped Total Octets", "cflow.drop_total_octets64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Count of total dropped bytes", HFILL}
},
{&hf_cflow_drop_total_packets,
{"Dropped Total Packets", "cflow.drop_total_packets",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Count of total dropped packets", HFILL}
},
{&hf_cflow_drop_total_packets64,
{"Dropped Total Packets", "cflow.drop_total_packets64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Count of total dropped packets", HFILL}
},
{&hf_cflow_flow_end_reason,
{"Flow End Reason", "cflow.flow_end_reason",
FT_UINT8, BASE_DEC, VALS(v9_flow_end_reason), 0x0,
NULL, HFILL}
},
{&hf_cflow_common_properties_id,
{"Common Properties Id", "cflow.common_properties_id",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_observation_point_id,
{"Observation Point Id", "cflow.observation_point_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_mpls_pe_addr_v6,
{"TopLabelAddr V6", "cflow.toplabeladdr_v6",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Top MPLS label PE address IPv6", HFILL}
},
{&hf_cflow_port_id,
{"Port Id", "cflow.port_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_mp_id,
{"Metering Process Id", "cflow.mp_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_wlan_channel_id,
{"Wireless LAN Channel Id", "cflow.wlan_channel_id",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_wlan_ssid,
{"Wireless LAN SSId", "cflow.wlan_ssid",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_flow_id,
{"Flow Id", "cflow.flow_id",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_od_id,
{"Observation Domain Id", "cflow.od_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Identifier of an Observation Domain that is locally unique to an Exporting Process", HFILL}
},
{&hf_cflow_sys_init_time,
{"System Init Time", "cflow.sys_init_time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_abstimestart,
{"StartTime", "cflow.abstimestart",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
"Uptime at start of flow", HFILL}
},
{&hf_cflow_abstimeend,
{"EndTime", "cflow.abstimeend",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
"Uptime at end of flow", HFILL}
},
{&hf_cflow_dstnet_v6,
{"DstNet", "cflow.dstnetv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Flow Destination Network (IPv6)", HFILL}
},
{&hf_cflow_srcnet_v6,
{"SrcNet", "cflow.srcnetv6",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Flow Source Network (IPv6)", HFILL}
},
{&hf_cflow_ignore_packets,
{"Ignored Packets", "cflow.ignore_packets",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Count of ignored packets", HFILL}
},
{&hf_cflow_ignore_packets64,
{"Ignored Packets", "cflow.ignore_packets64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Count of ignored packets", HFILL}
},
{&hf_cflow_ignore_octets,
{"Ignored Octets", "cflow.ignore_octets",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Count of ignored octets", HFILL}
},
{&hf_cflow_ignore_octets64,
{"Ignored Octets", "cflow.ignore_octets64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Count of ignored octets", HFILL}
},
{&hf_cflow_notsent_flows,
{"Not Sent Flows", "cflow.notsent_flows",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Count of not sent flows", HFILL}
},
{&hf_cflow_notsent_flows64,
{"Not Sent Flows", "cflow.notsent_flows64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Count of not sent flows", HFILL}
},
{&hf_cflow_notsent_packets,
{"Not Sent Packets", "cflow.notsent_packets",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Count of not sent packets", HFILL}
},
{&hf_cflow_notsent_packets64,
{"Not Sent Packets", "cflow.notsent_packets64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Count of not sent packets", HFILL}
},
{&hf_cflow_notsent_octets,
{"Not Sent Octets", "cflow.notsent_octets",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Count of not sent octets", HFILL}
},
{&hf_cflow_notsent_octets64,
{"Not Sent Octets", "cflow.notsent_octets64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Count of not sent octets", HFILL}
},
{&hf_cflow_post_total_octets,
{"Post Total Octets", "cflow.post_total_octets",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Count of post total octets", HFILL}
},
{&hf_cflow_post_total_octets64,
{"Post Total Octets", "cflow.post_total_octets64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Count of post total octets", HFILL}
},
{&hf_cflow_post_total_packets,
{"Post Total Packets", "cflow.post_total_packets",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Count of post total packets", HFILL}
},
{&hf_cflow_post_total_packets64,
{"Post Total Packets", "cflow.post_total_packets64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Count of post total packets", HFILL}
},
{&hf_cflow_key,
{"floKeyIndicator", "cflow.post_key",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Flow Key Indicator", HFILL}
},
{&hf_cflow_post_total_mulpackets,
{"Post Total Multicast Packets", "cflow.post_total_mulpackets",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Count of post total multicast packets", HFILL}
},
{&hf_cflow_post_total_mulpackets64,
{"Post Total Multicast Packets", "cflow.post_total_mulpackets64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Count of post total multicast packets", HFILL}
},
{&hf_cflow_post_total_muloctets,
{"Post Total Multicast Octets", "cflow.post_total_muloctets",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Count of post total multicast octets", HFILL}
},
{&hf_cflow_post_total_muloctets64,
{"Post Total Multicast Octets", "cflow.post_total_muloctets64",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Count of post total multicast octets", HFILL}
},
{&hf_cflow_tcp_seq_num,
{"TCP Sequence Number", "cflow.tcp_seq_num",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_tcp_ack_num,
{"TCP Acknowledgement Number", "cflow.tcp_ack_num",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_tcp_urg_ptr,
{"TCP Urgent Pointer", "cflow.tcp_urg_ptr",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_tcp_header_length,
{"TCP Header Length", "cflow.tcp_header_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_ip_header_length,
{"IP Header Length", "cflow.ip_header_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_ipv6_payload_length,
{"IPv6 Payload Length", "cflow.ipv6_payload_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_ipv6_next_hdr,
{"IPv6 Next Header", "cflow.ipv6_next_hdr",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_ip_precedence,
{"IP Precedence", "cflow.ip_precedence",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_ip_fragment_flags,
{"IP Fragment Flags", "cflow.ip_fragment_flags",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_mpls_top_label_ttl,
{"MPLS Top Label TTL", "cflow.mpls_top_label_ttl",
FT_UINT8, BASE_DEC, NULL, 0x0,
"MPLS top label time to live", HFILL}
},
{&hf_cflow_mpls_label_length,
{"MPLS Label Stack Length", "cflow.mpls_label_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The length of the MPLS label stac", HFILL}
},
{&hf_cflow_mpls_label_depth,
{"MPLS Label Stack Depth", "cflow.mpls_label_depth",
FT_UINT32, BASE_DEC, NULL, 0x0,
"The number of labels in the MPLS label stack", HFILL}
},
{&hf_cflow_ip_payload_length,
{"IP Payload Length", "cflow.ip_payload_length",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_mpls_top_label_exp,
{"MPLS Top Label Exp", "cflow.mpls_top_label_exp",
FT_UINT8, BASE_OCT, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_tcp_option_map,
{"TCP OptionMap", "cflow.tcp_option_map",
FT_BYTES, BASE_NONE, NULL, 0x0,
"TCP Option Map", HFILL}
},
{&hf_cflow_collector_addr,
{"CollectorAddr", "cflow.collector_addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Flow Collector Address (IPv4)", HFILL}
},
{&hf_cflow_collector_addr_v6,
{"CollectorAddr", "cflow.collector_addr_v6",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Flow Collector Address (IPv6)", HFILL}
},
{&hf_cflow_export_interface,
{"ExportInterface", "cflow.export_interface",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_export_protocol_version,
{"ExportProtocolVersion", "cflow.export_protocol_version",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_export_prot,
{"ExportTransportProtocol", "cflow.exporter_protocol",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Transport Protocol used by the Exporting Process", HFILL}
},
{&hf_cflow_collector_port,
{"CollectorPort", "cflow.collector_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Flow Collector Port", HFILL}
},
{&hf_cflow_exporter_port,
{"ExporterPort", "cflow.exporter_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Flow Exporter Port", HFILL}
},
{&hf_cflow_total_tcp_syn,
{"Total TCP syn", "cflow.total_tcp_syn",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Count of total TCP syn", HFILL}
},
{&hf_cflow_total_tcp_fin,
{"Total TCP fin", "cflow.total_tcp_fin",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Count of total TCP fin", HFILL}
},
{&hf_cflow_total_tcp_rst,
{"Total TCP rst", "cflow.total_tcp_rst",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Count of total TCP rst", HFILL}
},
{&hf_cflow_total_tcp_psh,
{"Total TCP psh", "cflow.total_tcp_psh",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Count of total TCP psh", HFILL}
},
{&hf_cflow_total_tcp_ack,
{"Total TCP ack", "cflow.total_tcp_ack",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Count of total TCP ack", HFILL}
},
{&hf_cflow_total_tcp_urg,
{"Total TCP urg", "cflow.total_tcp_urg",
FT_UINT64, BASE_DEC, NULL, 0x0,
"Count of total TCP urg", HFILL}
},
{&hf_cflow_ip_total_length,
{"IP Total Length", "cflow.ip_total_length",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_post_natsource_ipv4_address,
{"Post NAT Source IPv4 Address", "cflow.post_natsource_ipv4_address",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_post_natdestination_ipv4_address,
{"Post NAT Destination IPv4 Address", "cflow.post_natdestination_ipv4_address",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_post_naptsource_transport_port,
{"Post NAPT Source Transport Port", "cflow.post_naptsource_transport_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_post_naptdestination_transport_port,
{"Post NAPT Destination Transport Port", "cflow.post_naptdestination_transport_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_nat_originating_address_realm,
{"Nat Originating Address Realm", "cflow.nat_originating_address_realm",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_nat_event,
{"Nat Event", "cflow.nat_event",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_initiator_octets,
{"Initiator Octets", "cflow.initiator_octets",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_responder_octets,
{"Responder Octets", "cflow.responder_octets",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_firewall_event,
{"Firewall Event", "cflow.firewall_event",
FT_UINT8, BASE_DEC, VALS(v9_firewall_event), 0x0,
NULL, HFILL}
},
{&hf_cflow_ingress_vrfid,
{"Ingress VRFID", "cflow.ingress_vrfid",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_egress_vrfid,
{"Egress VRFID", "cflow.egress_vrfid",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_vrfname,
{"VRFname", "cflow.vrfname",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_post_mpls_top_label_exp,
{"Post Mpls Top Label Exp", "cflow.post_mpls_top_label_exp",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_tcp_window_scale,
{"Tcp Window Scale", "cflow.tcp_window_scale",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_biflow_direction,
{"Biflow Direction", "cflow.biflow_direction",
FT_UINT8, BASE_DEC, VALS(v9_biflow_direction), 0x0,
NULL, HFILL}
},
{&hf_cflow_ethernet_header_length,
{"Ethernet Header Length", "cflow.ethernet_header_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_ethernet_payload_length,
{"Ethernet Payload Length", "cflow.ethernet_payload_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_ethernet_total_length,
{"Ethernet Total Length", "cflow.ethernet_total_length",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_dot1q_vlan_id,
{"Dot1q Vlan Id", "cflow.dot1q_vlan_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_dot1q_priority,
{"Dot1q Priority", "cflow.dot1q_priority",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_dot1q_customer_vlan_id,
{"Dot1q Customer Vlan Id", "cflow.dot1q_customer_vlan_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_dot1q_customer_priority,
{"Dot1q Customer Priority", "cflow.dot1q_customer_priority",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_metro_evc_id,
{"Metro Evc Id", "cflow.metro_evc_id",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_metro_evc_type,
{"Metro Evc Type", "cflow.metro_evc_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_pseudo_wire_id,
{"Pseudo Wire Id", "cflow.pseudo_wire_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_pseudo_wire_type,
{"Pseudo Wire Type", "cflow.pseudo_wire_type",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_pseudo_wire_control_word,
{"Pseudo Wire Control Word", "cflow.pseudo_wire_control_word",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_ingress_physical_interface,
{"Ingress Physical Interface", "cflow.ingress_physical_interface",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_egress_physical_interface,
{"Egress Physical Interface", "cflow.egress_physical_interface",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_post_dot1q_vlan_id,
{"Post Dot1q Vlan Id", "cflow.post_dot1q_vlan_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_post_dot1q_customer_vlan_id,
{"Post Dot1q Customer Vlan Id", "cflow.post_dot1q_customer_vlan_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_ethernet_type,
{"Ethernet Type", "cflow.ethernet_type",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_post_ip_precedence,
{"Post Ip Precedence", "cflow.post_ip_precedence",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_collection_time_milliseconds,
{"Collection Time Milliseconds", "cflow.collection_time_milliseconds",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_export_sctp_stream_id,
{"Export Sctp Stream Id", "cflow.export_sctp_stream_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_max_export_seconds,
{"Max Export Seconds", "cflow.max_export_seconds",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_max_flow_end_seconds,
{"Max Flow End Seconds", "cflow.max_flow_end_seconds",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_message_md5_checksum,
{"Message MD5 Checksum", "cflow.message_md5_checksum",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_message_scope,
{"Message Scope", "cflow.message_scope",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_min_export_seconds,
{"Min Export Seconds", "cflow.min_export_seconds",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_min_flow_start_seconds,
{"Min Flow Start Seconds", "cflow.min_flow_start_seconds",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_opaque_octets,
{"Opaque Octets", "cflow.opaque_octets",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_session_scope,
{"Session Scope", "cflow.session_scope",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_max_flow_end_microseconds,
{"Max Flow End Microseconds", "cflow.max_flow_end_microseconds",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_max_flow_end_milliseconds,
{"Max Flow End Milliseconds", "cflow.max_flow_end_milliseconds",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_max_flow_end_nanoseconds,
{"Max Flow End Nanoseconds", "cflow.max_flow_end_nanoseconds",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_min_flow_start_microseconds,
{"Min Flow Start Microseconds", "cflow.min_flow_start_microseconds",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_min_flow_start_milliseconds,
{"Min Flow Start Milliseconds", "cflow.min_flow_start_milliseconds",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_min_flow_start_nanoseconds,
{"Min Flow Start Nanoseconds", "cflow.min_flow_start_nanoseconds",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_collector_certificate,
{"Collector Certificate", "cflow.collector_certificate",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_exporter_certificate,
{"Exporter Certificate", "cflow.exporter_certificate",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_selection_sequence_id,
{"Selection Sequence Id", "cflow.selection_sequence_id",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_selector_id,
{"Selector Id", "cflow.selector_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_information_element_id,
{"Information Element Id", "cflow.information_element_id",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_selector_algorithm,
{"Selector Algorithm", "cflow.selector_algorithm",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &selector_algorithm_ext, 0x0,
NULL, HFILL}
},
{&hf_cflow_sampling_packet_interval,
{"Sampling Packet Interval", "cflow.sampling_packet_interval",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_sampling_packet_space,
{"Sampling Packet Space", "cflow.sampling_packet_space",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_sampling_time_interval,
{"Sampling Time Interval", "cflow.sampling_time_interval",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_sampling_time_space,
{"Sampling Time Space", "cflow.sampling_time_space",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_sampling_size,
{"Sampling Size", "cflow.sampling_size",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_sampling_population,
{"Sampling Population", "cflow.sampling_population",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_sampling_probability,
{"Sampling Probability", "cflow.sampling_probability",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_mpls_label_stack_section,
{"Mpls Label Stack Section", "cflow.mpls_label_stack_section",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_mpls_payload_packet_section,
{"Mpls Payload Packet Section", "cflow.mpls_payload_packet_section",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_selector_id_total_pkts_observed,
{"Selector Id Total Pkts Observed", "cflow.selector_id_total_pkts_observed",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_selector_id_total_pkts_selected,
{"Selector Id Total Pkts Selected", "cflow.selector_id_total_pkts_selected",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_absolute_error,
{"Absolute Error", "cflow.absolute_error",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_relative_error,
{"Relative Error", "cflow.relative_error",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_observation_time_seconds,
{"Observation Time Seconds", "cflow.observation_time_seconds",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_observation_time_milliseconds,
{"Observation Time Milliseconds", "cflow.observation_time_milliseconds",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_observation_time_microseconds,
{"Observation Time Microseconds", "cflow.observation_time_microseconds",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_observation_time_nanoseconds,
{"Observation Time Nanoseconds", "cflow.observation_time_nanoseconds",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_UTC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_digest_hash_value,
{"Digest Hash Value", "cflow.digest_hash_value",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_hash_ippayload_offset,
{"Hash IPPayload Offset", "cflow.hash_ippayload_offset",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_hash_ippayload_size,
{"Hash IPPayload Size", "cflow.hash_ippayload_size",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_hash_output_range_min,
{"Hash Output Range Min", "cflow.hash_output_range_min",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_hash_output_range_max,
{"Hash Output Range Max", "cflow.hash_output_range_max",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_hash_selected_range_min,
{"Hash Selected Range Min", "cflow.hash_selected_range_min",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_hash_selected_range_max,
{"Hash Selected Range Max", "cflow.hash_selected_range_max",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_hash_digest_output,
{"Hash Digest Output", "cflow.hash_digest_output",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_hash_initialiser_value,
{"Hash Initialiser Value", "cflow.hash_initialiser_value",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_selector_name,
{"Selector Name", "cflow.selector_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_upper_cilimit,
{"Upper CILimit", "cflow.upper_cilimit",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_lower_cilimit,
{"Lower CILimit", "cflow.lower_cilimit",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_confidence_level,
{"Confidence Level", "cflow.confidence_level",
FT_FLOAT, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_information_element_data_type,
{"Information Element Data Type", "cflow.information_element_data_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_information_element_description,
{"Information Element Description", "cflow.information_element_description",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_information_element_name,
{"Information Element Name", "cflow.information_element_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_information_element_range_begin,
{"Information Element Range Begin", "cflow.information_element_range_begin",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_information_element_range_end,
{"Information Element Range End", "cflow.information_element_range_end",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_information_element_semantics,
{"Information Element Semantics", "cflow.information_element_semantics",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_information_element_units,
{"Information Element Units", "cflow.information_element_units",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_private_enterprise_number,
{"Private Enterprise Number", "cflow.private_enterprise_number",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_scope_system,
{"ScopeSystem", "cflow.scope_system",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option Scope System", HFILL}
},
{&hf_cflow_scope_interface,
{"ScopeInterface", "cflow.scope_interface",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Option Scope Interface", HFILL}
},
{&hf_cflow_scope_linecard,
{"ScopeLinecard", "cflow.scope_linecard",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option Scope Linecard", HFILL}
},
{&hf_cflow_scope_cache,
{"ScopeCache", "cflow.scope_cache",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option Scope Cache", HFILL}
},
{&hf_cflow_scope_template,
{"ScopeTemplate", "cflow.scope_template",
FT_BYTES, BASE_NONE, NULL, 0x0,
"Option Scope Template", HFILL}
},
{&hf_cflow_unknown_field_type,
{"Unknown Field Type", "cflow.unknown_field_type",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_template_ipfix_total_field_count,
{"Total Field Count", "cflow.template_ipfix_total_field_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
"IPFIX Options Template Total Field Count", HFILL}
},
{&hf_cflow_template_ipfix_scope_field_count,
{"Scope Field Count", "cflow.template_ipfix_scope_field_count",
FT_UINT16, BASE_DEC, NULL, 0x0,
"IPFIX Options Template Scope Field Count", HFILL}
},
{&hf_cflow_template_ipfix_pen_provided,
{"Pen provided", "cflow.template_ipfix_pen_provided",
FT_BOOLEAN, 16, TFS(&tfs_yes_no), 0x8000,
"Is Template Enterprise Specific", HFILL}
},
{&hf_cflow_template_ipfix_field_type,
{"Type", "cflow.template_ipfix_field_type",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &v9_v10_template_types_ext, 0x7FFF,
"Template field type", HFILL}
},
{&hf_cflow_template_plixer_field_type,
{"Type", "cflow.template_plixer_field_type",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &v10_template_types_plixer_ext, 0x7FFF,
"Template field type", HFILL}
},
{&hf_cflow_template_ntop_field_type,
{"Type", "cflow.template_ntop_field_type",
FT_UINT16, BASE_DEC|BASE_EXT_STRING, &v10_template_types_ntop_ext, 0x7FFF,
"Template field type", HFILL}
},
{&hf_cflow_template_ipfix_field_type_enterprise,
{"Type", "cflow.template_ipfix_field_type_enterprise",
FT_UINT16, BASE_DEC, NULL, 0x7FFF,
"Template field type", HFILL}
},
{&hf_cflow_template_ipfix_field_pen,
{"PEN",
"cflow.template_ipfix_field_pen",
FT_UINT32, BASE_DEC, NULL, 0x0,
"IPFIX Private Enterprise Number", HFILL}
},
{&hf_cflow_packets_dropped,
{"Packets Dropped",
"cflow.packets_dropped",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_byte_rate,
{"Byte Rate",
"cflow.byte_rate",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_application_media_bytes,
{"Media Bytes",
"cflow.application_media_bytes",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_application_media_byte_rate,
{"Media Byte Rate",
"cflow.media_byte_rate",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_application_media_packets,
{"Media Packets",
"cflow.application_media_packets",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_application_media_packet_rate,
{"Media Packet Rate",
"cflow.media_packet_rate",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_application_media_event,
{"Media Event",
"cflow.application_media_event",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_monitor_event,
{"Monitor Event",
"cflow.monitor_event",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_timestamp_interval,
{"Timestamp Interval",
"cflow.timestamp_interval",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_packets_expected,
{"Transport Packets Expected",
"cflow.transport_packets_expected",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_round_trip_time_string,
{"Transport Round-Trip-Time",
"cflow.transport_rtt",
FT_UINT32, BASE_HEX, VALS(performance_monitor_specials), 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_round_trip_time,
{"Transport Round-Trip-Time",
"cflow.transport_rtt",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_event_packet_loss,
{"Transport Packet Loss Events",
"cflow.transport_packet_loss_event",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_packets_lost,
{"Transport Packets Lost",
"cflow.transport_packets_lost",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_packets_lost_string,
{"Transport Packets Lost",
"cflow.transport_packets_lost",
FT_UINT32, BASE_HEX, VALS(performance_monitor_specials), 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_packets_lost_rate,
{"Transport Packet Loss Rate",
"cflow.transport_packet_loss_rate",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_packets_lost_rate_string,
{"Transport Packet Loss Rate",
"cflow.transport_packet_loss_rate",
FT_UINT32, BASE_HEX, VALS(performance_monitor_specials) , 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_rtp_ssrc,
{"RTP SSRC",
"cflow.transport_rtp_ssrc",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_rtp_jitter_mean,
{"RTP Mean Jitter",
"cflow.transport_jitter_mean",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_rtp_jitter_mean_string,
{"RTP Mean Jitter",
"cflow.transport_jitter_mean",
FT_UINT32, BASE_HEX, VALS(performance_monitor_specials), 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_rtp_jitter_min,
{"RTP Min Jitter",
"cflow.transport_jitter_min",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_rtp_jitter_min_string,
{"RTP Min Jitter",
"cflow.transport_jitter_min",
FT_UINT32, BASE_HEX, VALS(performance_monitor_specials), 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_rtp_jitter_max,
{"RTP Max Jitter",
"cflow.transport_jitter_max",
FT_RELATIVE_TIME, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_rtp_jitter_max_string,
{"RTP Max Jitter",
"cflow.transport_jitter_max",
FT_UINT32, BASE_HEX, VALS(performance_monitor_specials), 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_rtp_payload_type,
{"RTP Payload Type",
"cflow.rtp_payload_type",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_rtp_payload_type_string,
{"RTP Payload Type",
"cflow.rtp_payload_type",
FT_UINT8, BASE_HEX, VALS(performance_monitor_specials), 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_bytes_out_of_order,
{"Transport Bytes Out of Order",
"cflow.transport_bytes_out_of_ordera",
FT_UINT64, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_packets_out_of_order,
{"Transport Packets Out of Order",
"cflow.transport_packets_out_of_order",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_packets_out_of_order_string,
{"Transport Packets Out of Order",
"cflow.transport_packets_out_of_order",
FT_UINT32, BASE_HEX, VALS(performance_monitor_specials), 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_tcp_window_size_min,
{"Transport TCP Window Size Min",
"cflow.transport_tcp_window_size_min",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_tcp_window_size_min_string,
{"Transport TCP Window Size Min",
"cflow.transport_tcp_window_size_min",
FT_UINT32, BASE_HEX, VALS(performance_monitor_specials), 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_tcp_window_size_max,
{"Transport TCP Window Size Max",
"cflow.transport_tcp_window_size_max",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_tcp_window_size_max_string,
{"Transport TCP Window Size Max",
"cflow.transport_tcp_window_size_max",
FT_UINT32, BASE_HEX, VALS(performance_monitor_specials), 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_tcp_window_size_mean,
{"Transport TCP Window Size Mean",
"cflow.transport_tcp_window_size_mean",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_tcp_window_size_mean_string,
{"Transport TCP Window Size Mean",
"cflow.transport_tcp_window_size_mean",
FT_UINT32, BASE_HEX, VALS(performance_monitor_specials), 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_tcp_maximum_segment_size,
{"Transport TCP Maximum Segment Size",
"cflow.transport_tcp_maximum_segment_size",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_transport_tcp_maximum_segment_size_string,
{"Transport TCP Maximum Segment Size",
"cflow.transport_tcp_maximum_segment_size",
FT_UINT16, BASE_HEX, VALS(performance_monitor_specials), 0x0,
NULL, HFILL}
},
{&hf_cflow_nat_context_id,
{"NAT Context ID", "cflow.nat_context_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Internal context ID", HFILL}
},
{&hf_cflow_nat_context_name,
{"NAT Context Name", "cflow.nat_context_name",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
"Zero terminated context Name", HFILL}
},
{&hf_cflow_nat_assign_time,
{"NAT Assign Time", "cflow.nat_assign_time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
"Seconds of UNIX timestamp for assign", HFILL}
},
{&hf_cflow_nat_unassign_time,
{"NAT Unassign Time", "cflow.nat_unassign_time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
"Seconds of UNIX timestamp for unassign", HFILL}
},
{&hf_cflow_nat_int_addr,
{"Internal IPv4 address", "cflow.nat_int_addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_nat_ext_addr,
{"External IPv4 address", "cflow.nat_ext_addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_nat_ext_port_first,
{"NAT port start", "cflow.nat_ext_port_first",
FT_UINT16, BASE_DEC, NULL, 0x0,
"External L4 port start", HFILL}
},
{&hf_cflow_nat_ext_port_last,
{"NAT port end", "cflow.nat_ext_port_last",
FT_UINT16, BASE_DEC, NULL, 0x0,
"External L4 port end", HFILL}
},
{&hf_cflow_ingress_acl_id,
{"Ingress ACL ID", "cflow.ingress_acl_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_egress_acl_id,
{"Egress ACL ID", "cflow.egress_acl_id",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_cflow_fw_ext_event,
{"Extended firewall event code", "cflow.fw_ext_event",
FT_UINT16, BASE_DEC, VALS(v9_extended_firewall_event), 0x0,
NULL, HFILL}
},
{&hf_cflow_aaa_username,
{"AAA username", "cflow.aaa_username",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_ipfix_enterprise_private_entry,
{"Enterprise Private entry", "cflow.enterprise_private_entry",
FT_BYTES, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_cace_local_ipv4_address,
{"Local IPv4 Address", "cflow.pie.cace.localaddr4",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Local IPv4 Address (caceLocalIPv4Address)", HFILL}
},
{&hf_pie_cace_remote_ipv4_address,
{"Remote IPv4 Address", "cflow.pie.cace.remoteaddr4",
FT_IPv4, BASE_NONE, NULL, 0x0,
"Remote IPv4 Address (caceRemoteIPv4Address)", HFILL}
},
{&hf_pie_cace_local_ipv6_address,
{"Local IPv6 Address", "cflow.pie.cace.localaddr6",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Local IPv6 Address (caceLocalIPv6Address)", HFILL}
},
{&hf_pie_cace_remote_ipv6_address,
{"Remote IPv6 Address", "cflow.pie.cace.remoteaddr6",
FT_IPv6, BASE_NONE, NULL, 0x0,
"Remote IPv6 Address (caceRemoteIPv6Address)", HFILL}
},
{&hf_pie_cace_local_port,
{"Local Port", "cflow.pie.cace.localport",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Local Transport Port (caceLocalTransportPort)", HFILL}
},
{&hf_pie_cace_remote_port,
{"Remote Port", "cflow.pie.cace.remoteport",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Remote Transport Port (caceRemoteTransportPort)", HFILL}
},
{&hf_pie_cace_local_ipv4_id,
{"Local IPv4 ID", "cflow.pie.cace.localip4id",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The IPv4 identification header field from a locally-originated packet (caceLocalIPv4id)", HFILL}
},
{&hf_pie_cace_local_icmp_id,
{"Local ICMP ID", "cflow.pie.cace.localicmpid",
FT_UINT16, BASE_DEC, NULL, 0x0,
"The ICMP identification header field from a locally-originated ICMPv4 or ICMPv6 echo request (caceLocalICMPid)", HFILL}
},
{&hf_pie_cace_local_uid,
{"Local User ID", "cflow.pie.cace.localuid",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Local User ID (caceLocalProcessUserId)", HFILL}
},
{&hf_pie_cace_local_pid,
{"Local Process ID", "cflow.pie.cace.localpid",
FT_UINT32, BASE_DEC, NULL, 0x0,
"Local Process ID (caceLocalProcessId)", HFILL}
},
{&hf_pie_cace_local_username_len,
{"Local Username Length", "cflow.pie.cace.localusernamelen",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Local User Name Length (caceLocalProcessUserName)", HFILL}
},
{&hf_pie_cace_local_username,
{"Local User Name", "cflow.pie.cace.localusername",
FT_STRING, BASE_NONE, NULL, 0x0,
"Local User Name (caceLocalProcessUserName)", HFILL}
},
{&hf_pie_cace_local_cmd_len,
{"Local Command Length", "cflow.pie.cace.localcmdlen",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Local Command Length (caceLocalProcessCommand)", HFILL}
},
{&hf_pie_cace_local_cmd,
{"Local Command", "cflow.pie.cace.localcmd",
FT_STRING, BASE_NONE, NULL, 0x0,
"Local Command (caceLocalProcessCommand)", HFILL}
},
{&hf_pie_ntop_fragmented,
{"Fragmented","cflow.pie.ntop.fragmented",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_fingerprint,
{"Fingerprint","cflow.pie.ntop.fingerprint",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_client_nw_delay_sec,
{"Client_nw_delay_sec","cflow.pie.ntop.client_nw_delay_sec",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_client_nw_delay_usec,
{"Client_nw_delay_usec","cflow.pie.ntop.client_nw_delay_usec",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_server_nw_delay_sec,
{"Server_nw_delay_sec","cflow.pie.ntop.server_nw_delay_sec",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_server_nw_delay_usec,
{"Server_nw_delay_usec","cflow.pie.ntop.server_nw_delay_usec",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_appl_latency_sec,
{"Appl_latency_sec","cflow.pie.ntop.appl_latency_sec",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_icmp_flags,
{"Icmp_flags","cflow.pie.ntop.icmp_flags",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_src_ip_country,
{"Src_ip_country","cflow.pie.ntop.src_ip_country",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_src_ip_city,
{"Src_ip_city","cflow.pie.ntop.src_ip_city",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_dst_ip_country,
{"Dst_ip_country","cflow.pie.ntop.dst_ip_country",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_dst_ip_city,
{"Dst_ip_city","cflow.pie.ntop.dst_ip_city",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_flow_proto_port,
{"Flow_proto_port","cflow.pie.ntop.flow_proto_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_tunnel_id,
{"Tunnel_id","cflow.pie.ntop.tunnel_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_longest_flow_pkt,
{"Longest_flow_pkt","cflow.pie.ntop.longest_flow_pkt",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_shortest_flow_pkt,
{"Shortest_flow_pkt","cflow.pie.ntop.shortest_flow_pkt",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_retransmitted_in_pkts,
{"Retransmitted_in_pkts","cflow.pie.ntop.retransmitted_in_pkts",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_retransmitted_out_pkts,
{"Retransmitted_out_pkts","cflow.pie.ntop.retransmitted_out_pkts",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_ooorder_in_pkts,
{"Ooorder_in_pkts","cflow.pie.ntop.ooorder_in_pkts",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_ooorder_out_pkts,
{"Ooorder_out_pkts","cflow.pie.ntop.ooorder_out_pkts",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_untunneled_protocol,
{"Untunneled_protocol","cflow.pie.ntop.untunneled_protocol",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_untunneled_ipv4_src_addr,
{"Untunneled_ipv4_src_addr","cflow.pie.ntop.untunneled_ipv4_src_addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_untunneled_l4_src_port,
{"Untunneled_l4_src_port","cflow.pie.ntop.untunneled_l4_src_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_untunneled_ipv4_dst_addr,
{"Untunneled_ipv4_dst_addr","cflow.pie.ntop.untunneled_ipv4_dst_addr",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_untunneled_l4_dst_port,
{"Untunneled_l4_dst_port","cflow.pie.ntop.untunneled_l4_dst_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_dump_path,
{"Dump_path","cflow.pie.ntop.dump_path",
FT_STRINGZ, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_sip_call_id,
{"Sip_call_id","cflow.pie.ntop.sip_call_id",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_sip_calling_party,
{"Sip_calling_party","cflow.pie.ntop.sip_calling_party",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_sip_called_party,
{"Sip_called_party","cflow.pie.ntop.sip_called_party",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_sip_rtp_codecs,
{"Sip_rtp_codecs","cflow.pie.ntop.sip_rtp_codecs",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_sip_invite_time,
{"Sip_invite_time","cflow.pie.ntop.sip_invite_time",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_sip_trying_time,
{"Sip_trying_time","cflow.pie.ntop.sip_trying_time",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_sip_ringing_time,
{"Sip_ringing_time","cflow.pie.ntop.sip_ringing_time",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_sip_ok_time,
{"Sip_ok_time","cflow.pie.ntop.sip_ok_time",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_sip_bye_time,
{"Sip_bye_time","cflow.pie.ntop.sip_bye_time",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_sip_rtp_src_ip,
{"Sip_rtp_src_ip","cflow.pie.ntop.sip_rtp_src_ip",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_sip_rtp_src_port,
{"Sip_rtp_src_port","cflow.pie.ntop.sip_rtp_src_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_sip_rtp_dst_ip,
{"Sip_rtp_dst_ip","cflow.pie.ntop.sip_rtp_dst_ip",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_sip_rtp_dst_port,
{"Sip_rtp_dst_port","cflow.pie.ntop.sip_rtp_dst_port",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_rtp_first_ssrc,
{"Rtp_first_ssrc","cflow.pie.ntop.rtp_first_ssrc",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_rtp_first_ts,
{"Rtp_first_ts","cflow.pie.ntop.rtp_first_ts",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_rtp_last_ssrc,
{"Rtp_last_ssrc","cflow.pie.ntop.rtp_last_ssrc",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_rtp_last_ts,
{"Rtp_last_ts","cflow.pie.ntop.rtp_last_ts",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_rtp_in_jitter,
{"Rtp_in_jitter","cflow.pie.ntop.rtp_in_jitter",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_rtp_out_jitter,
{"Rtp_out_jitter","cflow.pie.ntop.rtp_out_jitter",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_rtp_in_pkt_lost,
{"Rtp_in_pkt_lost","cflow.pie.ntop.rtp_in_pkt_lost",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_rtp_out_pkt_lost,
{"Rtp_out_pkt_lost","cflow.pie.ntop.rtp_out_pkt_lost",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_rtp_out_payload_type,
{"Rtp_out_payload_type","cflow.pie.ntop.rtp_out_payload_type",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_rtp_in_max_delta,
{"Rtp_in_max_delta","cflow.pie.ntop.rtp_in_max_delta",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_rtp_out_max_delta,
{"Rtp_out_max_delta","cflow.pie.ntop.rtp_out_max_delta",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_proc_id,
{"Proc_id","cflow.pie.ntop.proc_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_proc_name,
{"Proc_name","cflow.pie.ntop.proc_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_http_url,
{"Http_url","cflow.pie.ntop.http_url",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_http_ret_code,
{"Http_ret_code","cflow.pie.ntop.http_ret_code",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_smtp_mail_from,
{"Smtp_mail_from","cflow.pie.ntop.smtp_mail_from",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_smtp_rcpt_to,
{"Smtp_rcpt_to","cflow.pie.ntop.smtp_rcpt_to",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_mysql_server_version,
{"Mysql_server_version","cflow.pie.ntop.mysql_server_version",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_mysql_username,
{"Mysql_username","cflow.pie.ntop.mysql_username",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_mysql_db,
{"Mysql_db","cflow.pie.ntop.mysql_db",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_mysql_query,
{"Mysql_query","cflow.pie.ntop.mysql_query",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_ntop_mysql_response,
{"Mysql_response","cflow.pie.ntop.mysql_response",
FT_UINT16, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_plixer_client_ip_v4,
{"client_ip_v4","cflow.pie.plixer.client.ip_v4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_plixer_client_hostname,
{"client_hostname","cflow.pie.plixer.client_hostname",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_plixer_partner_name,
{"Partner_name","cflow.pie.plixer.partner_name",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_plixer_server_hostname,
{"Server_hostname","cflow.pie.plixer.server_hostname",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_plixer_server_ip_v4,
{"Server_ip_v4","cflow.pie.plixer.server_ip_v4",
FT_IPv4, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_plixer_recipient_address,
{"Recipient_address","cflow.pie.plixer.recipient_address",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_plixer_event_id,
{"Event_id","cflow.pie.plixer.event_id",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_plixer_msgid,
{"Msgid","cflow.pie.plixer.msgid",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_plixer_priority,
{"Priority","cflow.pie.plixer_priority",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_plixer_recipient_report_status,
{"Recipient_report_status","cflow.pie.plixer.recipient_report_status",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_plixer_number_recipients,
{"Number_recipients","cflow.pie.plixer.number_recipients",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_plixer_origination_time,
{"Origination_time","cflow.pie.plixer.origination_time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_plixer_encryption,
{"Cncryption","cflow.pie.plixer.encryption",
FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_plixer_service_version,
{"Service_version","cflow.pie.plixer.service_version",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_plixer_linked_msgid,
{"Linked_msgid","cflow.pie.plixer.linked_msgid",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_plixer_message_subject,
{"Message_subject","cflow.pie.plixer.message_subject",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_plixer_sender_address,
{"Sender_address","cflow.pie.plixer.sender_address",
FT_STRING, BASE_NONE, NULL, 0x0,
NULL, HFILL}
},
{&hf_pie_plixer_date_time,
{"Date_time","cflow.pie.plixer.date_time",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0x0,
NULL, HFILL}
},
{&hf_string_len_short,
{"String_len_short","cflow.string_len_short",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
},
{&hf_string_len_long,
{"String_len_short","cflow.string_len_long",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL}
}
};
static gint *ett[] = {
&ett_netflow,
&ett_unixtime,
&ett_flow,
&ett_flowtime,
&ett_str_len,
&ett_template,
&ett_field,
&ett_dataflowset,
&ett_fwdstat
};
module_t *netflow_module;
proto_netflow = proto_register_protocol("Cisco NetFlow/IPFIX", "CFLOW", "cflow");
proto_register_field_array(proto_netflow, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
netflow_module = prefs_register_protocol(proto_netflow, proto_reg_handoff_netflow);
range_convert_str(&global_netflow_ports,NETFLOW_UDP_PORTS, MAX_UDP_PORT);
range_convert_str(&global_ipfix_ports, IPFIX_UDP_PORTS, MAX_UDP_PORT);
prefs_register_obsolete_preference(netflow_module, "udp.port");
prefs_register_range_preference(netflow_module, "netflow.ports",
"NetFlow UDP Port(s)",
"Set the port(s) for NetFlow messages"
" (default: " NETFLOW_UDP_PORTS ")",
&global_netflow_ports, MAX_UDP_PORT);
prefs_register_range_preference(netflow_module, "ipfix.ports",
"IPFIX UDP/TCP/SCTP Port(s)",
"Set the port(s) for IPFIX messages"
" (default: " IPFIX_UDP_PORTS ")",
&global_ipfix_ports, MAX_UDP_PORT);
prefs_register_uint_preference(netflow_module, "max_template_fields",
"Maximum number of fields allowed in a template",
"Set the number of fields allowed in a template. "
"Use 0 (zero) for unlimited. "
" (default: " STRINGIFY(V9TEMPLATE_MAX_FIELDS_DEF) ")",
10, &v9_tmplt_max_fields);
register_init_routine(&netflow_init);
}
static void
netflow_delete_callback(guint32 port)
{
if ( port ) {
dissector_delete_uint("udp.port", port, netflow_handle);
}
}
static void
netflow_add_callback(guint32 port)
{
if ( port ) {
dissector_add_uint("udp.port", port, netflow_handle);
}
}
static void
ipfix_delete_callback(guint32 port)
{
if ( port ) {
dissector_delete_uint("udp.port", port, netflow_handle);
dissector_delete_uint("tcp.port", port, netflow_handle);
dissector_delete_uint("sctp.port", port, netflow_handle);
}
}
static void
ipfix_add_callback(guint32 port)
{
if ( port ) {
dissector_add_uint("udp.port", port, netflow_handle);
dissector_add_uint("tcp.port", port, netflow_handle);
dissector_add_uint("sctp.port", port, netflow_handle);
}
}
void
proto_reg_handoff_netflow(void)
{
static gboolean netflow_prefs_initialized = FALSE;
static range_t *netflow_ports;
static range_t *ipfix_ports;
if (!netflow_prefs_initialized) {
netflow_handle = new_create_dissector_handle(dissect_netflow, proto_netflow);
netflow_prefs_initialized = TRUE;
dissector_add_uint("wtap_encap", WTAP_ENCAP_RAW_IPFIX, netflow_handle);
} else {
range_foreach(netflow_ports, netflow_delete_callback);
g_free(netflow_ports);
range_foreach(ipfix_ports, ipfix_delete_callback);
g_free(ipfix_ports);
}
netflow_ports = range_copy(global_netflow_ports);
ipfix_ports = range_copy(global_ipfix_ports);
range_foreach(netflow_ports, netflow_add_callback);
range_foreach(ipfix_ports, ipfix_add_callback);
}
