static void dissect_ipsictl(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
proto_tree *ipsictl_tree = NULL;
proto_tree *pdu_tree = NULL;
proto_item *ti;
int offset = 0;
int loffset = 0;
int llength = 0;
int remaining_length;
guint16 magic;
guint16 length;
guint16 type=0;
guint16 sequence=0;
int first_sequence=-1;
int last_sequence=-1;
guint16 field1=0;
guint16 pdu=0;
int haspdus=0;
remaining_length=tvb_reported_length_remaining(tvb, offset);
if (tree) {
ti = proto_tree_add_item(tree, proto_ipsictl, tvb, offset, remaining_length, ENC_NA);
ipsictl_tree = proto_item_add_subtree(ti, ett_ipsictl);
}
magic = tvb_get_ntohs(tvb, offset);
if (magic == IPSICTL_PDU_MAGIC)
{
haspdus=1;
}
while (haspdus &&
((remaining_length=tvb_reported_length_remaining(tvb, offset)) > 6))
{
loffset = offset;
magic = tvb_get_ntohs(tvb, loffset); loffset+=2;
length = tvb_get_ntohs(tvb, loffset); loffset+=2;
llength=length;
remaining_length-=4;
if (remaining_length>=2)
{
type = tvb_get_ntohs(tvb, loffset); loffset+=2;
remaining_length-=2;
llength-=2;
}
if (remaining_length>=2)
{
sequence = tvb_get_ntohs(tvb, loffset); loffset+=2;
remaining_length-=2;
llength-=2;
if (first_sequence==-1)
{
first_sequence=sequence;
}else{
last_sequence=sequence;
}
}
if (remaining_length>=2)
{
field1 = tvb_get_ntohs(tvb, loffset);
llength-=2;
}
if (tree) {
ti = proto_tree_add_uint(ipsictl_tree, hf_ipsictl_pdu, tvb,
offset, (length+4), pdu);
pdu_tree = proto_item_add_subtree(ti, ett_ipsictl_pdu);
}
loffset=offset;
remaining_length=tvb_reported_length_remaining(tvb, offset);
if (tree) {
proto_tree_add_uint(pdu_tree, hf_ipsictl_magic, tvb, loffset, 2, magic);
}
loffset+=2; remaining_length-=2;
if (tree) {
proto_tree_add_uint(pdu_tree, hf_ipsictl_length, tvb, loffset, 2, length);
}
loffset+=2; remaining_length-=2;
if (remaining_length>=2)
{
if (tree) {
proto_tree_add_uint(pdu_tree, hf_ipsictl_type, tvb, loffset, 2, type);
}
loffset+=2; remaining_length-=2;
}
if (remaining_length>=2)
{
if (tree) {
proto_tree_add_uint(pdu_tree, hf_ipsictl_sequence, tvb, loffset, 2, sequence);
}
loffset+=2; remaining_length-=2;
}
if (remaining_length>=2)
{
if (tree) {
proto_tree_add_uint(pdu_tree, hf_ipsictl_field1, tvb, loffset, 2, field1);
}
loffset+=2; remaining_length-=2;
}
if (remaining_length>=2)
{
if (tree) {
proto_tree_add_item(pdu_tree, hf_ipsictl_data, tvb, loffset, llength, ENC_NA);
}
loffset+=llength;
}
offset=loffset;
pdu++;
}
if (!haspdus)
{
if (tree) {
proto_tree_add_item(ipsictl_tree, hf_ipsictl_data, tvb, offset, -1, ENC_NA);
}
}
col_set_str(pinfo->cinfo, COL_PROTOCOL, "IPSICTL");
if (haspdus)
{
if (last_sequence==-1)
{
col_add_fstr(pinfo->cinfo, COL_INFO, "PDUS=%d, Seq=0x%04x",
pdu,first_sequence);
}else{
col_add_fstr(pinfo->cinfo, COL_INFO, "PDUS=%d, Seq=0x%04x-0x%04x",
pdu,first_sequence,last_sequence);
}
}else{
col_set_str(pinfo->cinfo, COL_INFO, "Initialization");
}
}
void proto_register_ipsictl(void)
{
static hf_register_info hf[] = {
{ &hf_ipsictl_pdu,
{ "PDU", "ipsictl.pdu",
FT_UINT16, BASE_DEC, NULL, 0x0,
"IPSICTL PDU", HFILL }},
{ &hf_ipsictl_magic,
{ "Magic", "ipsictl.magic",
FT_UINT16, BASE_HEX, NULL, 0x0,
"IPSICTL Magic", HFILL }},
{ &hf_ipsictl_length,
{ "Length", "ipsictl.length",
FT_UINT16, BASE_HEX, NULL, 0x0,
"IPSICTL Length", HFILL }},
{ &hf_ipsictl_type,
{ "Type", "ipsictl.type",
FT_UINT16, BASE_HEX, NULL, 0x0,
"IPSICTL Type", HFILL }},
{ &hf_ipsictl_sequence,
{ "Sequence", "ipsictl.sequence",
FT_UINT16, BASE_HEX, NULL, 0x0,
"IPSICTL Sequence", HFILL }},
{ &hf_ipsictl_field1,
{ "Field1", "ipsictl.field1",
FT_UINT16, BASE_HEX, NULL, 0x0,
"IPSICTL Field1", HFILL }},
{ &hf_ipsictl_data,
{ "Data", "ipsictl.data",
FT_BYTES, BASE_NONE, NULL, 0x0,
"IPSICTL data", HFILL }},
};
static gint *ett[] = {
&ett_ipsictl,
&ett_ipsictl_pdu
};
proto_ipsictl = proto_register_protocol("IPSICTL", "IPSICTL", "ipsictl");
proto_register_field_array(proto_ipsictl, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void proto_reg_handoff_ipsictl(void)
{
dissector_handle_t ipsictl_handle = NULL;
ipsictl_handle = create_dissector_handle(dissect_ipsictl, proto_ipsictl);
dissector_add_uint("tcp.port", IPSICTL_PORT, ipsictl_handle);
}
