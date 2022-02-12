static void
x25_hash_add_proto_start(guint16 vc, guint32 frame, dissector_handle_t dissect)
{
circuit_t *circuit;
circuit = find_circuit(CT_X25, vc, frame);
if (circuit != NULL) {
close_circuit(circuit, frame - 1);
}
circuit = circuit_new(CT_X25, vc, frame);
circuit_set_dissector(circuit, dissect);
}
static void
x25_hash_add_proto_end(guint16 vc, guint32 frame)
{
circuit_t *circuit;
circuit = find_circuit(CT_X25, vc, frame);
if (circuit != NULL)
close_circuit(circuit, frame);
}
static const char *clear_code(unsigned char code)
{
if (code == 0x00 || (code & 0x80) == 0x80)
return "DTE Originated";
if (code == 0x01)
return "Number Busy";
if (code == 0x03)
return "Invalid Facility Requested";
if (code == 0x05)
return "Network Congestion";
if (code == 0x09)
return "Out Of Order";
if (code == 0x0B)
return "Access Barred";
if (code == 0x0D)
return "Not Obtainable";
if (code == 0x11)
return "Remote Procedure Error";
if (code == 0x13)
return "Local Procedure Error";
if (code == 0x15)
return "RPOA Out Of Order";
if (code == 0x19)
return "Reverse Charging Acceptance Not Subscribed";
if (code == 0x21)
return "Incompatible Destination";
if (code == 0x29)
return "Fast Select Acceptance Not Subscribed";
if (code == 0x39)
return "Destination Absent";
return ep_strdup_printf("Unknown %02X", code);
}
static const char *clear_diag(unsigned char code)
{
if (code == 0)
return "No additional information";
if (code == 1)
return "Invalid P(S)";
if (code == 2)
return "Invalid P(R)";
if (code == 16)
return "Packet type invalid";
if (code == 17)
return "Packet type invalid for state r1";
if (code == 18)
return "Packet type invalid for state r2";
if (code == 19)
return "Packet type invalid for state r3";
if (code == 20)
return "Packet type invalid for state p1";
if (code == 21)
return "Packet type invalid for state p2";
if (code == 22)
return "Packet type invalid for state p3";
if (code == 23)
return "Packet type invalid for state p4";
if (code == 24)
return "Packet type invalid for state p5";
if (code == 25)
return "Packet type invalid for state p6";
if (code == 26)
return "Packet type invalid for state p7";
if (code == 27)
return "Packet type invalid for state d1";
if (code == 28)
return "Packet type invalid for state d2";
if (code == 29)
return "Packet type invalid for state d3";
if (code == 32)
return "Packet not allowed";
if (code == 33)
return "Unidentifiable packet";
if (code == 34)
return "Call on one-way logical channel";
if (code == 35)
return "Invalid packet type on a PVC";
if (code == 36)
return "Packet on unassigned LC";
if (code == 37)
return "Reject not subscribed to";
if (code == 38)
return "Packet too short";
if (code == 39)
return "Packet too long";
if (code == 40)
return "Invalid general format identifier";
if (code == 41)
return "Restart/registration packet with nonzero bits";
if (code == 42)
return "Packet type not compatible with facility";
if (code == 43)
return "Unauthorised interrupt confirmation";
if (code == 44)
return "Unauthorised interrupt";
if (code == 45)
return "Unauthorised reject";
if (code == 48)
return "Time expired";
if (code == 49)
return "Time expired for incoming call";
if (code == 50)
return "Time expired for clear indication";
if (code == 51)
return "Time expired for reset indication";
if (code == 52)
return "Time expired for restart indication";
if (code == 53)
return "Time expired for call deflection";
if (code == 64)
return "Call set-up/clearing or registration pb.";
if (code == 65)
return "Facility/registration code not allowed";
if (code == 66)
return "Facility parameter not allowed";
if (code == 67)
return "Invalid called DTE address";
if (code == 68)
return "Invalid calling DTE address";
if (code == 69)
return "Invalid facility/registration length";
if (code == 70)
return "Incoming call barred";
if (code == 71)
return "No logical channel available";
if (code == 72)
return "Call collision";
if (code == 73)
return "Duplicate facility requested";
if (code == 74)
return "Non zero address length";
if (code == 75)
return "Non zero facility length";
if (code == 76)
return "Facility not provided when expected";
if (code == 77)
return "Invalid CCITT-specified DTE facility";
if (code == 78)
return "Max. nb of call redir/defl. exceeded";
if (code == 80)
return "Miscellaneous";
if (code == 81)
return "Improper cause code from DTE";
if (code == 82)
return "Not aligned octet";
if (code == 83)
return "Inconsistent Q bit setting";
if (code == 84)
return "NUI problem";
if (code == 112)
return "International problem";
if (code == 113)
return "Remote network problem";
if (code == 114)
return "International protocol problem";
if (code == 115)
return "International link out of order";
if (code == 116)
return "International link busy";
if (code == 117)
return "Transit network facility problem";
if (code == 118)
return "Remote network facility problem";
if (code == 119)
return "International routing problem";
if (code == 120)
return "Temporary routing problem";
if (code == 121)
return "Unknown called DNIC";
if (code == 122)
return "Maintenance action";
if (code == 144)
return "Timer expired or retransmission count surpassed";
if (code == 145)
return "Timer expired or retransmission count surpassed for INTERRUPT";
if (code == 146)
return "Timer expired or retransmission count surpassed for DATA "
"packet transmission";
if (code == 147)
return "Timer expired or retransmission count surpassed for REJECT";
if (code == 160)
return "DTE-specific signals";
if (code == 161)
return "DTE operational";
if (code == 162)
return "DTE not operational";
if (code == 163)
return "DTE resource constraint";
if (code == 164)
return "Fast select not subscribed";
if (code == 165)
return "Invalid partially full DATA packet";
if (code == 166)
return "D-bit procedure not supported";
if (code == 167)
return "Registration/Cancellation confirmed";
if (code == 224)
return "OSI network service problem";
if (code == 225)
return "Disconnection (transient condition)";
if (code == 226)
return "Disconnection (permanent condition)";
if (code == 227)
return "Connection rejection - reason unspecified (transient "
"condition)";
if (code == 228)
return "Connection rejection - reason unspecified (permanent "
"condition)";
if (code == 229)
return "Connection rejection - quality of service not available "
"transient condition)";
if (code == 230)
return "Connection rejection - quality of service not available "
"permanent condition)";
if (code == 231)
return "Connection rejection - NSAP unreachable (transient condition)";
if (code == 232)
return "Connection rejection - NSAP unreachable (permanent condition)";
if (code == 233)
return "reset - reason unspecified";
if (code == 234)
return "reset - congestion";
if (code == 235)
return "Connection rejection - NSAP address unknown (permanent "
"condition)";
if (code == 240)
return "Higher layer initiated";
if (code == 241)
return "Disconnection - normal";
if (code == 242)
return "Disconnection - abnormal";
if (code == 243)
return "Disconnection - incompatible information in user data";
if (code == 244)
return "Connection rejection - reason unspecified (transient "
"condition)";
if (code == 245)
return "Connection rejection - reason unspecified (permanent "
"condition)";
if (code == 246)
return "Connection rejection - quality of service not available "
"(transient condition)";
if (code == 247)
return "Connection rejection - quality of service not available "
"(permanent condition)";
if (code == 248)
return "Connection rejection - incompatible information in user data";
if (code == 249)
return "Connection rejection - unrecognizable protocol identifier "
"in user data";
if (code == 250)
return "Reset - user resynchronization";
return ep_strdup_printf("Unknown %d", code);
}
static const char *reset_code(unsigned char code)
{
if (code == 0x00 || (code & 0x80) == 0x80)
return "DTE Originated";
if (code == 0x01)
return "Out of order";
if (code == 0x03)
return "Remote Procedure Error";
if (code == 0x05)
return "Local Procedure Error";
if (code == 0x07)
return "Network Congestion";
if (code == 0x09)
return "Remote DTE operational";
if (code == 0x0F)
return "Network operational";
if (code == 0x11)
return "Incompatible Destination";
if (code == 0x1D)
return "Network out of order";
return ep_strdup_printf("Unknown %02X", code);
}
static const char *restart_code(unsigned char code)
{
if (code == 0x00 || (code & 0x80) == 0x80)
return "DTE Originated";
if (code == 0x01)
return "Local Procedure Error";
if (code == 0x03)
return "Network Congestion";
if (code == 0x07)
return "Network Operational";
if (code == 0x7F)
return "Registration/cancellation confirmed";
return ep_strdup_printf("Unknown %02X", code);
}
static const char *registration_code(unsigned char code)
{
if (code == 0x03)
return "Invalid facility request";
if (code == 0x05)
return "Network congestion";
if (code == 0x13)
return "Local procedure error";
if (code == 0x7F)
return "Registration/cancellation confirmed";
return ep_strdup_printf("Unknown %02X", code);
}
static void
dump_facilities(proto_tree *tree, int *offset, tvbuff_t *tvb)
{
guint8 fac, byte1, byte2, byte3;
guint32 len;
proto_item *ti=0;
proto_tree *fac_tree = 0;
proto_tree *fac_subtree;
len = tvb_get_guint8(tvb, *offset);
if (len && tree) {
ti = proto_tree_add_text(tree, tvb, *offset, len + 1,
"Facilities");
fac_tree = proto_item_add_subtree(ti, ett_x25_fac);
proto_tree_add_text(fac_tree, tvb, *offset, 1,
"Facilities length: %d", len);
}
(*offset)++;
while (len > 0) {
fac = tvb_get_guint8(tvb, *offset);
switch(fac & X25_FAC_CLASS_MASK) {
case X25_FAC_CLASS_A:
switch (fac) {
case X25_FAC_COMP_MARK:
if (fac_tree)
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1,
"Code : 00 (Marker)");
switch (tvb_get_guint8(tvb, *offset + 1)) {
case 0x00:
if (fac_tree) {
fac_subtree = proto_item_add_subtree(ti, ett_x25_fac_mark);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Parameter : 00 (Network complementary "
"services - calling DTE)");
}
break;
case 0xFF:
if (fac_tree) {
fac_subtree = proto_item_add_subtree(ti, ett_x25_fac_mark);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Parameter : FF (Network complementary "
"services - called DTE)");
}
break;
case 0x0F:
if (fac_tree) {
fac_subtree = proto_item_add_subtree(ti, ett_x25_fac_mark);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Parameter : 0F (DTE complementary "
"services)");
}
break;
default:
if (fac_tree) {
fac_subtree = proto_item_add_subtree(ti, ett_x25_fac_mark);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Parameter : %02X (Unknown marker)",
tvb_get_guint8(tvb, *offset+1));
}
break;
}
break;
case X25_FAC_REVERSE:
if (fac_tree) {
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(Reverse charging / Fast select)", fac);
fac_subtree = proto_item_add_subtree(ti, ett_x25_fac_reverse);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Parameter : %02X", tvb_get_guint8(tvb, *offset + 1));
proto_tree_add_item(fac_subtree, hf_x25_fast_select, tvb, *offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fac_subtree, hf_x25_icrd, tvb, *offset+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(fac_subtree, hf_x25_reverse_charging, tvb, *offset+1, 1, ENC_BIG_ENDIAN);
}
break;
case X25_FAC_CHARGING_INFO:
if (fac_tree) {
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(Charging information)", fac);
fac_subtree = proto_item_add_subtree(ti, ett_x25_fac_charging_info);
byte1 = tvb_get_guint8(tvb, *offset + 1);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Parameter : %02X", byte1);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1, "%s",
decode_boolean_bitfield(byte1, 0x01, 1*8,
"Charging information requested",
"Charging information not requested"));
}
break;
case X25_FAC_THROUGHPUT:
if (fac_tree) {
char *tmpbuf;
tmpbuf=ep_alloc(80);
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(Throughput class negotiation)", fac);
fac_subtree = proto_item_add_subtree(ti, ett_x25_fac_throughput);
byte1 = tvb_get_guint8(tvb, *offset + 1);
switch (byte1 >> 4)
{
case 3:
case 4:
case 5:
case 6:
case 7:
case 8:
case 9:
case 10:
case 11:
g_snprintf(tmpbuf, 80, "From the called DTE : %%u (%d bps)",
75*(1<<((byte1 >> 4)-3)));
break;
case 12:
g_snprintf(tmpbuf, 80, "From the called DTE : %%u (48000 bps)");
break;
case 13:
g_snprintf(tmpbuf, 80, "From the called DTE : %%u (64000 bps)");
break;
default:
g_snprintf(tmpbuf, 80, "From the called DTE : %%u (Reserved)");
}
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1, "%s",
decode_numeric_bitfield(byte1, 0xF0, 1*8, tmpbuf));
switch (byte1 & 0x0F)
{
case 3:
case 4:
case 5:
case 6:
case 7:
case 8:
case 9:
case 10:
case 11:
g_snprintf(tmpbuf, 80, "From the calling DTE : %%u (%d bps)",
75*(1<<((byte1 & 0x0F)-3)));
break;
case 12:
g_snprintf(tmpbuf, 80, "From the calling DTE : %%u (48000 bps)");
break;
case 13:
g_snprintf(tmpbuf, 80, "From the calling DTE : %%u (64000 bps)");
break;
default:
g_snprintf(tmpbuf, 80, "From the calling DTE : %%u (Reserved)");
}
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1, "%s",
decode_numeric_bitfield(byte1, 0x0F, 1*8, tmpbuf));
}
break;
case X25_FAC_CUG:
if (fac_tree) {
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(Closed user group selection)", fac);
fac_subtree = proto_item_add_subtree(ti, ett_x25_fac_cug);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Closed user group: %02X", tvb_get_guint8(tvb, *offset+1));
}
break;
case X25_FAC_CALLED_MODIF:
if (fac_tree) {
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(Called address modified)", fac);
fac_subtree = proto_item_add_subtree(ti,
ett_x25_fac_called_modif);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Parameter %02X", tvb_get_guint8(tvb, *offset+1));
}
break;
case X25_FAC_CUG_OUTGOING_ACC:
if (fac_tree) {
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(Closed user group with outgoing access selection)",
fac);
fac_subtree = proto_item_add_subtree(ti,
ett_x25_fac_cug_outgoing_acc);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Closed user group: %02X", tvb_get_guint8(tvb, *offset+1));
}
break;
case X25_FAC_THROUGHPUT_MIN:
if (fac_tree) {
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(Minimum throughput class)", fac);
fac_subtree = proto_item_add_subtree(ti,
ett_x25_fac_throughput_min);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Parameter %02X", tvb_get_guint8(tvb, *offset+1));
}
break;
case X25_FAC_EXPRESS_DATA:
if (fac_tree) {
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(Negotiation of express data)", fac);
fac_subtree = proto_item_add_subtree(ti,
ett_x25_fac_express_data);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Parameter %02X", tvb_get_guint8(tvb, *offset+1));
}
break;
default:
if (fac_tree) {
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1,
"Code : %02X (Unknown class A)", fac);
fac_subtree = proto_item_add_subtree(ti, ett_x25_fac_unknown);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Parameter %02X", tvb_get_guint8(tvb, *offset+1));
}
break;
}
(*offset) += 2;
len -= 2;
break;
case X25_FAC_CLASS_B:
switch (fac) {
case X25_FAC_BILATERAL_CUG:
if (fac_tree) {
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(Bilateral closed user group selection)", fac);
fac_subtree = proto_item_add_subtree(ti,
ett_x25_fac_bilateral_cug);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 2,
"Bilateral CUG: %04X",
tvb_get_ntohs(tvb, *offset+1));
}
break;
case X25_FAC_PACKET_SIZE:
if (fac_tree)
{
char *tmpbuf;
tmpbuf=ep_alloc(80);
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(Packet size)", fac);
fac_subtree = proto_item_add_subtree(ti, ett_x25_fac_packet_size);
byte1 = tvb_get_guint8(tvb, *offset + 1);
switch (byte1)
{
case 0x04:
g_snprintf(tmpbuf, 80, "From the called DTE : %%u (16)");
break;
case 0x05:
g_snprintf(tmpbuf, 80, "From the called DTE : %%u (32)");
break;
case 0x06:
g_snprintf(tmpbuf, 80, "From the called DTE : %%u (64)");
break;
case 0x07:
g_snprintf(tmpbuf, 80, "From the called DTE : %%u (128)");
break;
case 0x08:
g_snprintf(tmpbuf, 80, "From the called DTE : %%u (256)");
break;
case 0x09:
g_snprintf(tmpbuf, 80, "From the called DTE : %%u (512)");
break;
case 0x0A:
g_snprintf(tmpbuf, 80, "From the called DTE : %%u (1024)");
break;
case 0x0B:
g_snprintf(tmpbuf, 80, "From the called DTE : %%u (2048)");
break;
case 0x0C:
g_snprintf(tmpbuf, 80, "From the called DTE : %%u (4096)");
break;
default:
g_snprintf(tmpbuf, 80, "From the called DTE : %%u (Unknown)");
break;
}
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1, "%s",
decode_numeric_bitfield(byte1, 0x0F, 1*8, tmpbuf));
byte2 = tvb_get_guint8(tvb, *offset + 2);
switch (byte2)
{
case 0x04:
g_snprintf(tmpbuf, 80, "From the calling DTE : %%u (16)");
break;
case 0x05:
g_snprintf(tmpbuf, 80, "From the calling DTE : %%u (32)");
break;
case 0x06:
g_snprintf(tmpbuf, 80, "From the calling DTE : %%u (64)");
break;
case 0x07:
g_snprintf(tmpbuf, 80, "From the calling DTE : %%u (128)");
break;
case 0x08:
g_snprintf(tmpbuf, 80, "From the calling DTE : %%u (256)");
break;
case 0x09:
g_snprintf(tmpbuf, 80, "From the calling DTE : %%u (512)");
break;
case 0x0A:
g_snprintf(tmpbuf, 80, "From the calling DTE : %%u (1024)");
break;
case 0x0B:
g_snprintf(tmpbuf, 80, "From the calling DTE : %%u (2048)");
break;
case 0x0C:
g_snprintf(tmpbuf, 80, "From the calling DTE : %%u (4096)");
break;
default:
g_snprintf(tmpbuf, 80, "From the calling DTE : %%u (Unknown)");
break;
}
proto_tree_add_text(fac_subtree, tvb, *offset+2, 1, "%s",
decode_numeric_bitfield(byte2, 0x0F, 1*8, tmpbuf));
}
break;
case X25_FAC_WINDOW_SIZE:
if (fac_tree) {
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(Window size)", fac);
fac_subtree = proto_item_add_subtree(ti, ett_x25_fac_window_size);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1, "%s",
decode_numeric_bitfield(tvb_get_guint8(tvb, *offset+1),
0x7F, 1*8, "From the called DTE: %u"));
proto_tree_add_text(fac_subtree, tvb, *offset+2, 1, "%s",
decode_numeric_bitfield(tvb_get_guint8(tvb, *offset+2),
0x7F, 1*8, "From the calling DTE: %u"));
}
break;
case X25_FAC_RPOA_SELECTION:
if (fac_tree) {
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(RPOA selection)", fac);
fac_subtree = proto_item_add_subtree(ti,
ett_x25_fac_rpoa_selection);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 2,
"Data network identification code : %04X",
tvb_get_ntohs(tvb, *offset+1));
}
break;
case X25_FAC_CUG_EXT:
if (fac_tree) {
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(Extended closed user group selection)", fac);
fac_subtree = proto_item_add_subtree(ti, ett_x25_fac_cug_ext);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 2,
"Closed user group: %04X", tvb_get_ntohs(tvb, *offset+1));
}
break;
case X25_FAC_CUG_OUTGOING_ACC_EXT:
if (fac_tree) {
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(Extended closed user group with outgoing access selection)",
fac);
fac_subtree = proto_item_add_subtree(ti,
ett_x25_fac_cug_outgoing_acc_ext);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 2,
"Closed user group: %04X", tvb_get_ntohs(tvb, *offset+1));
}
break;
case X25_FAC_TRANSIT_DELAY:
if (fac_tree) {
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(Transit delay selection and indication)", fac);
fac_subtree = proto_item_add_subtree(ti,
ett_x25_fac_transit_delay);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 2,
"Transit delay: %d ms",
tvb_get_ntohs(tvb, *offset+1));
}
break;
default:
if (fac_tree) {
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1,
"Code : %02X (Unknown class B)", fac);
fac_subtree = proto_item_add_subtree(ti, ett_x25_fac_unknown);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 2,
"Parameter %04X", tvb_get_ntohs(tvb, *offset+1));
}
break;
}
(*offset) += 3;
len -= 3;
break;
case X25_FAC_CLASS_C:
if (fac_tree) {
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1,
"Code : %02X (Unknown class C)", fac);
fac_subtree = proto_item_add_subtree(ti, ett_x25_fac_unknown);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 3,
"Parameter %06X",
tvb_get_ntoh24(tvb, *offset+1));
}
(*offset) += 4;
len -= 4;
break;
case X25_FAC_CLASS_D:
switch (fac) {
case X25_FAC_CALL_DURATION:
if (fac_tree) {
int i;
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(Call duration)", fac);
fac_subtree = proto_item_add_subtree(ti,
ett_x25_fac_call_duration);
byte1 = tvb_get_guint8(tvb, *offset+1);
if ((byte1 < 4) || (byte1 % 4)) {
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Bogus length : %d", byte1);
return;
} else {
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Length : %u", byte1);
}
for (i = 0; (i<byte1); i+=4) {
proto_tree_add_text(fac_subtree, tvb, *offset+2+i, 4,
"Call duration : %u Day(s) %02X:%02X:%02X Hour(s)",
tvb_get_guint8(tvb, *offset+2+i),
tvb_get_guint8(tvb, *offset+3+i),
tvb_get_guint8(tvb, *offset+4+i),
tvb_get_guint8(tvb, *offset+5+i));
}
}
break;
case X25_FAC_SEGMENT_COUNT:
if (fac_tree) {
int i;
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(Segment count)", fac);
fac_subtree = proto_item_add_subtree(ti,
ett_x25_fac_segment_count);
byte1 = tvb_get_guint8(tvb, *offset+1);
if ((byte1 < 8) || (byte1 % 8)) {
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Bogus length : %d", byte1);
return;
} else {
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Length : %u", byte1);
}
for (i = 0; (i<byte1); i+=8) {
proto_tree_add_text(fac_subtree, tvb, *offset+2+i, 4,
"Segments sent to DTE : %02X%02X%02X%02X",
tvb_get_guint8(tvb, *offset+2+i),
tvb_get_guint8(tvb, *offset+3+i),
tvb_get_guint8(tvb, *offset+4+i),
tvb_get_guint8(tvb, *offset+5+i));
proto_tree_add_text(fac_subtree, tvb, *offset+6+i, 4,
"Segments received from DTE : %02X%02X%02X%02X",
tvb_get_guint8(tvb, *offset+6+i),
tvb_get_guint8(tvb, *offset+7+i),
tvb_get_guint8(tvb, *offset+8+i),
tvb_get_guint8(tvb, *offset+9+i));
}
}
break;
case X25_FAC_CALL_TRANSFER:
if (fac_tree) {
int i;
char *tmpbuf;
tmpbuf=ep_alloc(258);
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(Call redirection or deflection notification)", fac);
fac_subtree = proto_item_add_subtree(ti, ett_x25_fac_call_transfer);
byte1 = tvb_get_guint8(tvb, *offset+1);
if (byte1 < 2) {
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Bogus length : %d", byte1);
return;
} else {
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Length : %u", byte1);
}
byte2 = tvb_get_guint8(tvb, *offset+2);
if ((byte2 & 0xC0) == 0xC0) {
proto_tree_add_text(fac_subtree, tvb, *offset+2, 1,
"Reason : call deflection by the originally "
"called DTE address");
}
else {
switch (byte2) {
case 0x01:
proto_tree_add_text(fac_subtree, tvb, *offset+2, 1,
"Reason : originally called DTE busy");
break;
case 0x07:
proto_tree_add_text(fac_subtree, tvb, *offset+2, 1,
"Reason : call dist. within a hunt group");
break;
case 0x09:
proto_tree_add_text(fac_subtree, tvb, *offset+2, 1,
"Reason : originally called DTE out of order");
break;
case 0x0F:
proto_tree_add_text(fac_subtree, tvb, *offset+2, 1,
"Reason : systematic call redirection");
break;
default:
proto_tree_add_text(fac_subtree, tvb, *offset+2, 1,
"Reason : unknown");
break;
}
}
byte3 = tvb_get_guint8(tvb, *offset+3);
proto_tree_add_text(fac_subtree, tvb, *offset+3, 1,
"Number of semi-octets in DTE address : %u",
byte3);
for (i = 0; (i<byte3)&&(i<256); i++) {
if (i % 2 == 0) {
tmpbuf[i] = ((tvb_get_guint8(tvb, *offset+4+i/2) >> 4)
& 0x0F) + '0';
if (tmpbuf[i] > '9') tmpbuf[i] += ('A' - '0' - 10);
} else {
tmpbuf[i] = (tvb_get_guint8(tvb, *offset+4+i/2)
& 0x0F) + '0';
if (tmpbuf[i] > '9') tmpbuf[i] += ('A' - '0' - 10);
}
}
tmpbuf[i] = 0;
proto_tree_add_text(fac_subtree, tvb, *offset+4, byte1 - 2,
"DTE address : %s", tmpbuf);
}
break;
case X25_FAC_RPOA_SELECTION_EXT:
if (fac_tree) {
int i;
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(Extended RPOA selection)", fac);
fac_subtree = proto_item_add_subtree(ti,
ett_x25_fac_rpoa_selection_ext);
byte1 = tvb_get_guint8(tvb, *offset+1);
if ((byte1 < 2) || (byte1 % 2)) {
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Bogus length : %d", byte1);
return;
} else {
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Length : %u", byte1);
}
for (i = 0; (i<byte1); i+=2) {
proto_tree_add_text(fac_subtree, tvb, *offset+2+i, 2,
"Data network identification code : %04X",
tvb_get_ntohs(tvb, *offset+2+i));
}
}
break;
case X25_FAC_CALLING_ADDR_EXT:
if (fac_tree) {
int i;
char *tmpbuf;
tmpbuf=ep_alloc(258);
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(Calling address extension)", fac);
fac_subtree = proto_item_add_subtree(ti,
ett_x25_fac_calling_addr_ext);
byte1 = tvb_get_guint8(tvb, *offset+1);
if (byte1 < 1) {
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Bogus length : %d", byte1);
return;
} else {
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Length : %u", byte1);
}
byte2 = tvb_get_guint8(tvb, *offset+2) & 0x3F;
proto_tree_add_text(fac_subtree, tvb, *offset+2, 1,
"Number of semi-octets in DTE address : %u", byte2);
for (i = 0; (i<byte2)&&(i<256) ; i++) {
if (i % 2 == 0) {
tmpbuf[i] = ((tvb_get_guint8(tvb, *offset+3+i/2) >> 4)
& 0x0F) + '0';
if (tmpbuf[i] > '9') tmpbuf[i] += ('A' - '0' - 10);
} else {
tmpbuf[i] = (tvb_get_guint8(tvb, *offset+3+i/2)
& 0x0F) + '0';
if (tmpbuf[i] > '9') tmpbuf[i] += ('A' - '0' - 10);
}
}
tmpbuf[i] = 0;
proto_tree_add_text(fac_subtree, tvb, *offset+3, byte1 - 1,
"DTE address : %s", tmpbuf);
}
break;
case X25_FAC_MONETARY_UNIT:
if (fac_tree) {
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(Monetary Unit)", fac);
fac_subtree = proto_item_add_subtree(ti,
ett_x25_fac_monetary_unit);
byte1 = tvb_get_guint8(tvb, *offset+1);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Length : %u", byte1);
proto_tree_add_text(fac_subtree, tvb, *offset+2, byte1, "Value");
}
break;
case X25_FAC_NUI:
if (fac_tree) {
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(Network User Identification selection)", fac);
fac_subtree = proto_item_add_subtree(ti,
ett_x25_fac_nui);
byte1 = tvb_get_guint8(tvb, *offset+1);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Length : %u", byte1);
proto_tree_add_text(fac_subtree, tvb, *offset+2, byte1, "NUI");
}
break;
case X25_FAC_CALLED_ADDR_EXT:
if (fac_tree) {
int i;
char *tmpbuf;
tmpbuf=ep_alloc(258);
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(Called address extension)", fac);
fac_subtree = proto_item_add_subtree(ti,
ett_x25_fac_called_addr_ext);
byte1 = tvb_get_guint8(tvb, *offset+1);
if (byte1 < 1) {
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Bogus length : %d", byte1);
return;
} else {
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Length : %u", byte1);
}
byte2 = tvb_get_guint8(tvb, *offset+2) & 0x3F;
proto_tree_add_text(fac_subtree, tvb, *offset+2, 1,
"Number of semi-octets in DTE address : %u", byte2);
for (i = 0; (i<byte2)&&(i<256) ; i++) {
if (i % 2 == 0) {
tmpbuf[i] = ((tvb_get_guint8(tvb, *offset+3+i/2) >> 4)
& 0x0F) + '0';
if (tmpbuf[i] > '9') tmpbuf[i] += ('A' - '0' - 10);
} else {
tmpbuf[i] = (tvb_get_guint8(tvb, *offset+3+i/2)
& 0x0F) + '0';
if (tmpbuf[i] > '9') tmpbuf[i] += ('A' - '0' - 10);
}
}
tmpbuf[i] = 0;
proto_tree_add_text(fac_subtree, tvb, *offset+3, byte1 - 1,
"DTE address : %s", tmpbuf);
}
break;
case X25_FAC_ETE_TRANSIT_DELAY:
if (fac_tree) {
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(End to end transit delay)", fac);
fac_subtree = proto_item_add_subtree(ti,
ett_x25_fac_ete_transit_delay);
byte1 = tvb_get_guint8(tvb, *offset+1);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Length : %u", byte1);
proto_tree_add_text(fac_subtree, tvb, *offset+2, byte1, "Value");
}
break;
case X25_FAC_CALL_DEFLECT:
if (fac_tree) {
int i;
char *tmpbuf;
tmpbuf=ep_alloc(258);
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1, "Code : %02X "
"(Call deflection selection)", fac);
fac_subtree = proto_item_add_subtree(ti,
ett_x25_fac_call_deflect);
byte1 = tvb_get_guint8(tvb, *offset+1);
if (byte1 < 2) {
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Bogus length : %d", byte1);
return;
} else {
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Length : %u", byte1);
}
byte2 = tvb_get_guint8(tvb, *offset+2);
if ((byte2 & 0xC0) == 0xC0)
proto_tree_add_text(fac_subtree, tvb, *offset+2, 1,
"Reason : call DTE originated");
else
proto_tree_add_text(fac_subtree, tvb, *offset+2, 1,
"Reason : unknown");
byte3 = tvb_get_guint8(tvb, *offset+3);
proto_tree_add_text(fac_subtree, tvb, *offset+3, 1,
"Number of semi-octets in the alternative DTE address : %u",
byte3);
for (i = 0; (i<byte3)&&(i<256) ; i++) {
if (i % 2 == 0) {
tmpbuf[i] = ((tvb_get_guint8(tvb, *offset+4+i/2) >> 4)
& 0x0F) + '0';
if (tmpbuf[i] > '9') tmpbuf[i] += ('A' - '0' - 10);
} else {
tmpbuf[i] = (tvb_get_guint8(tvb, *offset+4+i/2)
& 0x0F) + '0';
if (tmpbuf[i] > '9') tmpbuf[i] += ('A' - '0' - 10);
}
}
tmpbuf[i] = 0;
proto_tree_add_text(fac_subtree, tvb, *offset+4, byte1 - 2,
"Alternative DTE address : %s", tmpbuf);
}
break;
case X25_FAC_PRIORITY:
if (fac_tree) {
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1,
"Code : %02X (Priority)", fac);
fac_subtree = proto_item_add_subtree(ti, ett_x25_fac_priority);
byte1 = tvb_get_guint8(tvb, *offset+1);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Length : %u", byte1);
proto_tree_add_text(fac_subtree, tvb, *offset+2, byte1, "Value");
}
break;
default:
if (fac_tree) {
ti = proto_tree_add_text(fac_tree, tvb, *offset, 1,
"Code : %02X (Unknown class D)", fac);
fac_subtree = proto_item_add_subtree(ti, ett_x25_fac_unknown);
byte1 = tvb_get_guint8(tvb, *offset+1);
proto_tree_add_text(fac_subtree, tvb, *offset+1, 1,
"Length : %u", byte1);
proto_tree_add_text(fac_subtree, tvb, *offset+2, byte1, "Value");
}
}
byte1 = tvb_get_guint8(tvb, *offset+1);
(*offset) += byte1+2;
len -= byte1+2;
break;
}
}
}
static void
x25_ntoa(proto_tree *tree, int *offset, tvbuff_t *tvb,
packet_info *pinfo, gboolean is_registration)
{
int len1, len2;
int i;
char *addr1, *addr2;
char *first, *second;
guint8 byte;
int localoffset;
addr1=ep_alloc(16);
addr2=ep_alloc(16);
byte = tvb_get_guint8(tvb, *offset);
len1 = (byte >> 0) & 0x0F;
len2 = (byte >> 4) & 0x0F;
if (tree) {
proto_tree_add_text(tree, tvb, *offset, 1, "%s",
decode_numeric_bitfield(byte, 0xF0, 1*8,
is_registration ?
"DTE address length : %u" :
"Calling address length : %u"));
proto_tree_add_text(tree, tvb, *offset, 1, "%s",
decode_numeric_bitfield(byte, 0x0F, 1*8,
is_registration ?
"DCE address length : %u" :
"Called address length : %u"));
}
(*offset)++;
localoffset = *offset;
byte = tvb_get_guint8(tvb, localoffset);
first=addr1;
second=addr2;
for (i = 0; i < (len1 + len2); i++) {
if (i < len1) {
if (i % 2 != 0) {
*first++ = ((byte >> 0) & 0x0F) + '0';
localoffset++;
byte = tvb_get_guint8(tvb, localoffset);
} else {
*first++ = ((byte >> 4) & 0x0F) + '0';
}
} else {
if (i % 2 != 0) {
*second++ = ((byte >> 0) & 0x0F) + '0';
localoffset++;
byte = tvb_get_guint8(tvb, localoffset);
} else {
*second++ = ((byte >> 4) & 0x0F) + '0';
}
}
}
*first = '\0';
*second = '\0';
if (len1) {
col_add_str(pinfo->cinfo, COL_RES_DL_DST, addr1);
if (tree)
proto_tree_add_text(tree, tvb, *offset,
(len1 + 1) / 2,
is_registration ?
"DCE address : %s" :
"Called address : %s",
addr1);
}
if (len2) {
col_add_str(pinfo->cinfo, COL_RES_DL_SRC, addr2);
if (tree)
proto_tree_add_text(tree, tvb, *offset + len1/2,
(len2+1)/2+(len1%2+(len2+1)%2)/2,
is_registration ?
"DTE address : %s" :
"Calling address : %s",
addr2);
}
(*offset) += ((len1 + len2 + 1) / 2);
}
static void
x25_toa(proto_tree *tree, int *offset, tvbuff_t *tvb,
packet_info *pinfo)
{
int len1, len2;
int i;
char *addr1, *addr2;
char *first, *second;
guint8 byte;
int localoffset;
addr1=ep_alloc(256);
addr2=ep_alloc(256);
len1 = tvb_get_guint8(tvb, *offset);
if (tree) {
proto_tree_add_text(tree, tvb, *offset, 1,
"Called address length : %u",
len1);
}
(*offset)++;
len2 = tvb_get_guint8(tvb, *offset);
if (tree) {
proto_tree_add_text(tree, tvb, *offset, 1,
"Calling address length : %u",
len2);
}
(*offset)++;
localoffset = *offset;
byte = tvb_get_guint8(tvb, localoffset);
first=addr1;
second=addr2;
for (i = 0; i < (len1 + len2); i++) {
if (i < len1) {
if (i % 2 != 0) {
*first++ = ((byte >> 0) & 0x0F) + '0';
localoffset++;
byte = tvb_get_guint8(tvb, localoffset);
} else {
*first++ = ((byte >> 4) & 0x0F) + '0';
}
} else {
if (i % 2 != 0) {
*second++ = ((byte >> 0) & 0x0F) + '0';
localoffset++;
byte = tvb_get_guint8(tvb, localoffset);
} else {
*second++ = ((byte >> 4) & 0x0F) + '0';
}
}
}
*first = '\0';
*second = '\0';
if (len1) {
col_add_str(pinfo->cinfo, COL_RES_DL_DST, addr1);
if (tree)
proto_tree_add_text(tree, tvb, *offset,
(len1 + 1) / 2,
"Called address : %s",
addr1);
}
if (len2) {
col_add_str(pinfo->cinfo, COL_RES_DL_SRC, addr2);
if (tree)
proto_tree_add_text(tree, tvb, *offset + len1/2,
(len2+1)/2+(len1%2+(len2+1)%2)/2,
"Calling address : %s",
addr2);
}
(*offset) += ((len1 + len2 + 1) / 2);
}
static int
get_x25_pkt_len(tvbuff_t *tvb)
{
guint length, called_len, calling_len, dte_len, dce_len;
guint8 byte2, bytex;
byte2 = tvb_get_guint8(tvb, 2);
switch (byte2)
{
case X25_CALL_REQUEST:
bytex = tvb_get_guint8(tvb, 3);
called_len = (bytex >> 0) & 0x0F;
calling_len = (bytex >> 4) & 0x0F;
length = 4 + (called_len + calling_len + 1) / 2;
if (length < tvb_reported_length(tvb))
length += (1 + tvb_get_guint8(tvb, length));
return MIN(tvb_reported_length(tvb),length);
case X25_CALL_ACCEPTED:
if (tvb_reported_length(tvb) == 3)
return(3);
bytex = tvb_get_guint8(tvb, 3);
called_len = (bytex >> 0) & 0x0F;
calling_len = (bytex >> 4) & 0x0F;
length = 4 + (called_len + calling_len + 1) / 2;
if (length < tvb_reported_length(tvb))
length += (1 + tvb_get_guint8(tvb, length));
return MIN(tvb_reported_length(tvb),length);
case X25_CLEAR_REQUEST:
case X25_RESET_REQUEST:
case X25_RESTART_REQUEST:
return MIN(tvb_reported_length(tvb),5);
case X25_DIAGNOSTIC:
return MIN(tvb_reported_length(tvb),4);
case X25_CLEAR_CONFIRMATION:
case X25_INTERRUPT:
case X25_INTERRUPT_CONFIRMATION:
case X25_RESET_CONFIRMATION:
case X25_RESTART_CONFIRMATION:
return MIN(tvb_reported_length(tvb),3);
case X25_REGISTRATION_REQUEST:
bytex = tvb_get_guint8(tvb, 3);
dce_len = (bytex >> 0) & 0x0F;
dte_len = (bytex >> 4) & 0x0F;
length = 4 + (dte_len + dce_len + 1) / 2;
if (length < tvb_reported_length(tvb))
length += (1 + tvb_get_guint8(tvb, length));
return MIN(tvb_reported_length(tvb),length);
case X25_REGISTRATION_CONFIRMATION:
bytex = tvb_get_guint8(tvb, 5);
dce_len = (bytex >> 0) & 0x0F;
dte_len = (bytex >> 4) & 0x0F;
length = 6 + (dte_len + dce_len + 1) / 2;
if (length < tvb_reported_length(tvb))
length += (1 + tvb_get_guint8(tvb, length));
return MIN(tvb_reported_length(tvb),length);
}
if (PACKET_IS_DATA(byte2))
return MIN(tvb_reported_length(tvb),3);
switch (PACKET_TYPE_FC(byte2))
{
case X25_RR:
return MIN(tvb_reported_length(tvb),3);
case X25_RNR:
return MIN(tvb_reported_length(tvb),3);
case X25_REJ:
return MIN(tvb_reported_length(tvb),3);
}
return 0;
}
static void
dissect_x25_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
x25_dir_t dir, gboolean side)
{
proto_tree *x25_tree=0, *gfi_tree=0, *userdata_tree=0;
proto_item *ti;
guint localoffset=0;
guint x25_pkt_len;
int modulo;
guint16 vc;
dissector_handle_t dissect = NULL;
gboolean toa;
guint16 bytes0_1;
guint8 pkt_type;
const char *short_name = NULL, *long_name = NULL;
tvbuff_t *next_tvb = NULL;
gboolean q_bit_set = FALSE;
gboolean m_bit_set;
gint payload_len;
guint32 frag_key;
void *saved_private_data;
fragment_data *fd_head;
guint8 spi;
int is_x_264;
guint8 prt_id;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "X.25");
bytes0_1 = tvb_get_ntohs(tvb, 0);
modulo = ((bytes0_1 & 0x2000) ? 128 : 8);
vc = (int)(bytes0_1 & 0x0FFF);
pinfo->ctype = CT_X25;
pinfo->circuit_id = vc;
if (bytes0_1 & X25_ABIT) toa = TRUE;
else toa = FALSE;
x25_pkt_len = get_x25_pkt_len(tvb);
if (x25_pkt_len < 3)
{
col_set_str(pinfo->cinfo, COL_INFO, "Invalid/short X.25 packet");
if (tree)
proto_tree_add_protocol_format(tree, proto_x25, tvb, 0, -1,
"Invalid/short X.25 packet");
return;
}
pkt_type = tvb_get_guint8(tvb, 2);
if (PACKET_IS_DATA(pkt_type)) {
if (bytes0_1 & X25_QBIT)
q_bit_set = TRUE;
}
if (tree) {
ti = proto_tree_add_item(tree, proto_x25, tvb, 0, x25_pkt_len, ENC_NA);
x25_tree = proto_item_add_subtree(ti, ett_x25);
ti = proto_tree_add_item(x25_tree, hf_x25_gfi, tvb, 0, 2, ENC_BIG_ENDIAN);
gfi_tree = proto_item_add_subtree(ti, ett_x25_gfi);
if (PACKET_IS_DATA(pkt_type)) {
proto_tree_add_boolean(gfi_tree, hf_x25_qbit, tvb, 0, 2,
bytes0_1);
}
else if (pkt_type == X25_CALL_REQUEST ||
pkt_type == X25_CALL_ACCEPTED ||
pkt_type == X25_CLEAR_REQUEST ||
pkt_type == X25_CLEAR_CONFIRMATION) {
proto_tree_add_boolean(gfi_tree, hf_x25_abit, tvb, 0, 2,
bytes0_1);
}
if (pkt_type == X25_CALL_REQUEST || pkt_type == X25_CALL_ACCEPTED ||
PACKET_IS_DATA(pkt_type)) {
proto_tree_add_boolean(gfi_tree, hf_x25_dbit, tvb, 0, 2,
bytes0_1);
}
proto_tree_add_uint(gfi_tree, hf_x25_mod, tvb, 0, 2, bytes0_1);
}
switch (pkt_type) {
case X25_CALL_REQUEST:
switch (dir) {
case X25_FROM_DCE:
short_name = "Inc. call";
long_name = "Incoming call";
break;
case X25_FROM_DTE:
short_name = "Call req.";
long_name = "Call request";
break;
case X25_UNKNOWN:
short_name = "Inc. call/Call req.";
long_name = "Incoming call/Call request";
break;
}
if (check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "%s VC:%d", short_name, vc);
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_lcn, tvb,
0, 2, bytes0_1);
proto_tree_add_uint_format(x25_tree, hf_x25_type, tvb, 2, 1,
X25_CALL_REQUEST, "Packet Type: %s", long_name);
}
localoffset = 3;
if (localoffset < x25_pkt_len) {
if (toa)
x25_toa(x25_tree, (gint*)&localoffset, tvb, pinfo);
else
x25_ntoa(x25_tree, (gint*)&localoffset, tvb, pinfo, FALSE);
}
if (localoffset < x25_pkt_len)
dump_facilities(x25_tree, (gint*)&localoffset, tvb);
if (localoffset < tvb_reported_length(tvb))
{
if (x25_tree) {
ti = proto_tree_add_text(x25_tree, tvb, localoffset, -1,
"User data");
userdata_tree = proto_item_add_subtree(ti, ett_x25_user_data);
}
spi = tvb_get_guint8(tvb, localoffset);
if (spi > 32 || spi < 3) {
is_x_264 = FALSE;
} else {
if (tvb_bytes_exist(tvb, localoffset+1, 1)) {
if (tvb_get_guint8(tvb, localoffset+1) == 0x01) {
is_x_264 = TRUE;
} else {
is_x_264 = FALSE;
}
} else {
is_x_264 = -1;
}
}
if (is_x_264 == -1) {
localoffset = tvb_length(tvb);
} else if (is_x_264) {
if (userdata_tree) {
proto_tree_add_text(userdata_tree, tvb, localoffset, 1,
"X.264 length indicator: %u",
spi);
proto_tree_add_text(userdata_tree, tvb, localoffset+1, 1,
"X.264 UN TPDU identifier: 0x%02X",
tvb_get_guint8(tvb, localoffset+1));
}
prt_id = tvb_get_guint8(tvb, localoffset+2);
if (userdata_tree) {
proto_tree_add_text(userdata_tree, tvb, localoffset+2, 1,
"X.264 protocol identifier: %s",
val_to_str(prt_id, prt_id_vals,
"Unknown (0x%02X)"));
proto_tree_add_text(userdata_tree, tvb, localoffset+3, 1,
"X.264 sharing strategy: %s",
val_to_str(tvb_get_guint8(tvb, localoffset+3),
sharing_strategy_vals, "Unknown (0x%02X)"));
}
localoffset += spi + 1;
switch (prt_id) {
case PRT_ID_ISO_8073:
if (!pinfo->fd->flags.visited)
x25_hash_add_proto_start(vc, pinfo->fd->num, ositp_handle);
break;
case PRT_ID_ISO_8602:
if (!pinfo->fd->flags.visited)
x25_hash_add_proto_start(vc, pinfo->fd->num, ositp_handle);
break;
}
} else if (is_x_264 == 0) {
if (userdata_tree) {
proto_tree_add_text(userdata_tree, tvb, localoffset, 1,
"X.263 secondary protocol ID: %s",
val_to_str(spi, nlpid_vals, "Unknown (0x%02x)"));
}
if (!pinfo->fd->flags.visited) {
dissect = dissector_get_uint_handle(x25_subdissector_table, spi);
if (dissect != NULL)
x25_hash_add_proto_start(vc, pinfo->fd->num, dissect);
}
if (localoffset + 1 == tvb_reported_length(tvb))
return;
switch (spi) {
case NLPID_ISO8473_CLNP:
case NLPID_ISO9542_ESIS:
case NLPID_ISO10589_ISIS:
case NLPID_ISO10747_IDRP:
case NLPID_SNDCF:
break;
case NLPID_SPI_X_29:
localoffset += 4;
break;
default:
localoffset++;
}
}
} else {
if (call_request_nodata_is_cotp){
x25_hash_add_proto_start(vc, pinfo->fd->num, ositp_handle);
}
}
break;
case X25_CALL_ACCEPTED:
switch (dir) {
case X25_FROM_DCE:
short_name = "Call conn.";
long_name = "Call connected";
break;
case X25_FROM_DTE:
short_name = "Call acc.";
long_name = "Call accepted";
break;
case X25_UNKNOWN:
short_name = "Call conn./Call acc.";
long_name = "Call connected/Call accepted";
break;
}
if(check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "%s VC:%d", short_name, vc);
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_lcn, tvb, 0, 2, bytes0_1);
proto_tree_add_uint_format(x25_tree, hf_x25_type, tvb, 2, 1,
X25_CALL_ACCEPTED, "Packet Type: %s", long_name);
}
localoffset = 3;
if (localoffset < x25_pkt_len) {
if (toa)
x25_toa(x25_tree, (gint*)&localoffset, tvb, pinfo);
else
x25_ntoa(x25_tree, (gint*)&localoffset, tvb, pinfo, FALSE);
}
if (localoffset < x25_pkt_len)
dump_facilities(x25_tree, (gint*)&localoffset, tvb);
break;
case X25_CLEAR_REQUEST:
switch (dir) {
case X25_FROM_DCE:
short_name = "Clear ind.";
long_name = "Clear indication";
break;
case X25_FROM_DTE:
short_name = "Clear req.";
long_name = "Clear request";
break;
case X25_UNKNOWN:
short_name = "Clear ind./Clear req.";
long_name = "Clear indication/Clear request";
break;
}
if(check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s VC:%d %s - %s", short_name,
vc, clear_code(tvb_get_guint8(tvb, 3)),
clear_diag(tvb_get_guint8(tvb, 4)));
}
x25_hash_add_proto_end(vc, pinfo->fd->num);
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_lcn, tvb, 0, 2, bytes0_1);
proto_tree_add_uint_format(x25_tree, hf_x25_type, tvb,
localoffset+2, 1, X25_CLEAR_REQUEST, "Packet Type: %s",
long_name);
proto_tree_add_text(x25_tree, tvb, 3, 1,
"Cause : %s", clear_code(tvb_get_guint8(tvb, 3)));
proto_tree_add_text(x25_tree, tvb, 4, 1,
"Diagnostic : %s", clear_diag(tvb_get_guint8(tvb, 4)));
}
localoffset = x25_pkt_len;
break;
case X25_CLEAR_CONFIRMATION:
if(check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "Clear Conf. VC:%d", vc);
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_lcn, tvb, 0, 2, bytes0_1);
proto_tree_add_uint(x25_tree, hf_x25_type, tvb, 2, 1,
X25_CLEAR_CONFIRMATION);
}
localoffset = x25_pkt_len;
if (localoffset < tvb_reported_length(tvb)) {
if (toa)
x25_toa(x25_tree, (gint*)&localoffset, tvb, pinfo);
else
x25_ntoa(x25_tree,(gint*)&localoffset, tvb, pinfo, FALSE);
}
if (localoffset < tvb_reported_length(tvb))
dump_facilities(x25_tree, (gint*)&localoffset, tvb);
break;
case X25_DIAGNOSTIC:
if(check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "Diag. %d",
(int)tvb_get_guint8(tvb, 3));
}
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_type, tvb, 2, 1,
X25_DIAGNOSTIC);
proto_tree_add_text(x25_tree, tvb, 3, 1,
"Diagnostic : %d", (int)tvb_get_guint8(tvb, 3));
}
localoffset = x25_pkt_len;
break;
case X25_INTERRUPT:
if(check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "Interrupt VC:%d", vc);
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_lcn, tvb, 0, 2, bytes0_1);
proto_tree_add_uint(x25_tree, hf_x25_type, tvb, 2, 1,
X25_INTERRUPT);
}
localoffset = x25_pkt_len;
break;
case X25_INTERRUPT_CONFIRMATION:
if(check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "Interrupt Conf. VC:%d", vc);
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_lcn, tvb, 0, 2, bytes0_1);
proto_tree_add_uint(x25_tree, hf_x25_type, tvb, 2, 1,
X25_INTERRUPT_CONFIRMATION);
}
localoffset = x25_pkt_len;
break;
case X25_RESET_REQUEST:
switch (dir) {
case X25_FROM_DCE:
short_name = "Reset ind.";
long_name = "Reset indication";
break;
case X25_FROM_DTE:
short_name = "Reset req.";
long_name = "Reset request";
break;
case X25_UNKNOWN:
short_name = "Reset ind./Reset req.";
long_name = "Reset indication/Reset request";
break;
}
if(check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s VC:%d %s - Diag.:%d",
short_name, vc, reset_code(tvb_get_guint8(tvb, 3)),
(int)tvb_get_guint8(tvb, 4));
}
x25_hash_add_proto_end(vc, pinfo->fd->num);
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_lcn, tvb, 0, 2, bytes0_1);
proto_tree_add_uint_format(x25_tree, hf_x25_type, tvb, 2, 1,
X25_RESET_REQUEST, "Packet Type: %s", long_name);
proto_tree_add_text(x25_tree, tvb, 3, 1,
"Cause : %s", reset_code(tvb_get_guint8(tvb, 3)));
proto_tree_add_text(x25_tree, tvb, 4, 1,
"Diagnostic : %d", (int)tvb_get_guint8(tvb, 4));
}
localoffset = x25_pkt_len;
break;
case X25_RESET_CONFIRMATION:
if(check_col(pinfo->cinfo, COL_INFO))
col_add_fstr(pinfo->cinfo, COL_INFO, "Reset conf. VC:%d", vc);
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_lcn, tvb, 0, 2, bytes0_1);
proto_tree_add_uint(x25_tree, hf_x25_type, tvb, 2, 1,
X25_RESET_CONFIRMATION);
}
localoffset = x25_pkt_len;
break;
case X25_RESTART_REQUEST:
switch (dir) {
case X25_FROM_DCE:
short_name = "Restart ind.";
long_name = "Restart indication";
break;
case X25_FROM_DTE:
short_name = "Restart req.";
long_name = "Restart request";
break;
case X25_UNKNOWN:
short_name = "Restart ind./Restart req.";
long_name = "Restart indication/Restart request";
break;
}
if(check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO, "%s %s - Diag.:%d",
short_name,
restart_code(tvb_get_guint8(tvb, 3)),
(int)tvb_get_guint8(tvb, 4));
}
if (x25_tree) {
proto_tree_add_uint_format(x25_tree, hf_x25_type, tvb, 2, 1,
X25_RESTART_REQUEST, "Packet Type: %s", long_name);
proto_tree_add_text(x25_tree, tvb, 3, 1,
"Cause : %s", restart_code(tvb_get_guint8(tvb, 3)));
proto_tree_add_text(x25_tree, tvb, 4, 1,
"Diagnostic : %d", (int)tvb_get_guint8(tvb, 4));
}
localoffset = x25_pkt_len;
break;
case X25_RESTART_CONFIRMATION:
col_set_str(pinfo->cinfo, COL_INFO, "Restart conf.");
if (x25_tree)
proto_tree_add_uint(x25_tree, hf_x25_type, tvb, 2, 1,
X25_RESTART_CONFIRMATION);
localoffset = x25_pkt_len;
break;
case X25_REGISTRATION_REQUEST:
col_set_str(pinfo->cinfo, COL_INFO, "Registration req.");
if (x25_tree)
proto_tree_add_uint(x25_tree, hf_x25_type, tvb, 2, 1,
X25_REGISTRATION_REQUEST);
localoffset = 3;
if (localoffset < x25_pkt_len)
x25_ntoa(x25_tree, (gint*)&localoffset, tvb, pinfo, TRUE);
if (x25_tree) {
if (localoffset < x25_pkt_len)
proto_tree_add_text(x25_tree, tvb, localoffset, 1,
"Registration length: %d",
tvb_get_guint8(tvb, localoffset) & 0x7F);
if (localoffset+1 < x25_pkt_len)
proto_tree_add_text(x25_tree, tvb, localoffset+1,
tvb_get_guint8(tvb, localoffset) & 0x7F,
"Registration");
}
localoffset = tvb_reported_length(tvb);
break;
case X25_REGISTRATION_CONFIRMATION:
col_set_str(pinfo->cinfo, COL_INFO, "Registration conf.");
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_type, tvb, 2, 1,
X25_REGISTRATION_CONFIRMATION);
proto_tree_add_text(x25_tree, tvb, 3, 1,
"Cause: %s", registration_code(tvb_get_guint8(tvb, 3)));
proto_tree_add_text(x25_tree, tvb, 4, 1,
"Diagnostic: %s", registration_code(tvb_get_guint8(tvb, 4)));
}
localoffset = 5;
if (localoffset < x25_pkt_len)
x25_ntoa(x25_tree, (gint*)&localoffset, tvb, pinfo, TRUE);
if (x25_tree) {
if (localoffset < x25_pkt_len)
proto_tree_add_text(x25_tree, tvb, localoffset, 1,
"Registration length: %d",
tvb_get_guint8(tvb, localoffset) & 0x7F);
if (localoffset+1 < x25_pkt_len)
proto_tree_add_text(x25_tree, tvb, localoffset+1,
tvb_get_guint8(tvb, localoffset) & 0x7F,
"Registration");
}
localoffset = tvb_reported_length(tvb);
break;
default :
localoffset = 2;
if (PACKET_IS_DATA(pkt_type))
{
if(check_col(pinfo->cinfo, COL_INFO)) {
if (modulo == 8)
col_add_fstr(pinfo->cinfo, COL_INFO,
"Data VC:%d P(S):%d P(R):%d %s", vc,
(pkt_type >> 1) & 0x07,
(pkt_type >> 5) & 0x07,
(pkt_type & X25_MBIT_MOD8) ? " M" : "");
else
col_add_fstr(pinfo->cinfo, COL_INFO,
"Data VC:%d P(S):%d P(R):%d %s", vc,
tvb_get_guint8(tvb, localoffset+1) >> 1,
pkt_type >> 1,
(tvb_get_guint8(tvb, localoffset+1) & X25_MBIT_MOD128) ? " M" : "");
}
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_lcn, tvb, localoffset-2,
2, bytes0_1);
if (modulo == 8) {
proto_tree_add_uint(x25_tree, hf_x25_p_r_mod8, tvb,
localoffset, 1, pkt_type);
proto_tree_add_boolean(x25_tree, hf_x25_mbit_mod8, tvb,
localoffset, 1, pkt_type);
proto_tree_add_uint(x25_tree, hf_x25_p_s_mod8, tvb,
localoffset, 1, pkt_type);
proto_tree_add_uint(x25_tree, hf_x25_type_data, tvb,
localoffset, 1, pkt_type);
}
else {
proto_tree_add_uint(x25_tree, hf_x25_p_r_mod128, tvb,
localoffset, 1, pkt_type);
proto_tree_add_uint(x25_tree, hf_x25_type_data, tvb,
localoffset, 1, pkt_type);
proto_tree_add_uint(x25_tree, hf_x25_p_s_mod128, tvb,
localoffset+1, 1,
tvb_get_guint8(tvb, localoffset+1));
proto_tree_add_boolean(x25_tree, hf_x25_mbit_mod128, tvb,
localoffset+1, 1,
tvb_get_guint8(tvb, localoffset+1));
}
}
if (modulo == 8) {
m_bit_set = pkt_type & X25_MBIT_MOD8;
localoffset += 1;
} else {
m_bit_set = tvb_get_guint8(tvb, localoffset+1) & X25_MBIT_MOD128;
localoffset += 2;
}
payload_len = tvb_reported_length_remaining(tvb, localoffset);
if (reassemble_x25) {
frag_key = vc;
if (side) {
frag_key |= 0x10000;
}
fd_head = fragment_add_seq_next(tvb, localoffset,
pinfo, frag_key,
x25_segment_table,
x25_reassembled_table,
payload_len, m_bit_set);
pinfo->fragmented = m_bit_set;
if (!m_bit_set && fd_head) {
if (fd_head->next) {
proto_item *frag_tree_item;
next_tvb = tvb_new_child_real_data(tvb, fd_head->data,
fd_head->len,
fd_head->len);
add_new_data_source(pinfo, next_tvb, "Reassembled X.25");
if (x25_tree) {
show_fragment_seq_tree(fd_head,
&x25_frag_items,
x25_tree,
pinfo, next_tvb, &frag_tree_item);
}
}
}
if (m_bit_set && next_tvb == NULL) {
proto_tree_add_text(x25_tree, tvb, localoffset, -1,
"User data (%u byte%s)", payload_len,
plurality(payload_len, "", "s"));
return;
}
}
break;
}
switch (PACKET_TYPE_FC(pkt_type))
{
case X25_RR:
if(check_col(pinfo->cinfo, COL_INFO)) {
if (modulo == 8)
col_add_fstr(pinfo->cinfo, COL_INFO, "RR VC:%d P(R):%d",
vc, (pkt_type >> 5) & 0x07);
else
col_add_fstr(pinfo->cinfo, COL_INFO, "RR VC:%d P(R):%d",
vc, tvb_get_guint8(tvb, localoffset+1) >> 1);
}
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_lcn, tvb, localoffset-2,
2, bytes0_1);
if (modulo == 8) {
proto_tree_add_uint(x25_tree, hf_x25_p_r_mod8, tvb,
localoffset, 1, pkt_type);
proto_tree_add_uint(x25_tree, hf_x25_type_fc_mod8, tvb,
localoffset, 1, X25_RR);
}
else {
proto_tree_add_uint(x25_tree, hf_x25_type, tvb,
localoffset, 1, X25_RR);
proto_tree_add_item(x25_tree, hf_x25_p_r_mod128, tvb,
localoffset+1, 1, ENC_BIG_ENDIAN);
}
}
break;
case X25_RNR:
if(check_col(pinfo->cinfo, COL_INFO)) {
if (modulo == 8)
col_add_fstr(pinfo->cinfo, COL_INFO, "RNR VC:%d P(R):%d",
vc, (pkt_type >> 5) & 0x07);
else
col_add_fstr(pinfo->cinfo, COL_INFO, "RNR VC:%d P(R):%d",
vc, tvb_get_guint8(tvb, localoffset+1) >> 1);
}
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_lcn, tvb, localoffset-2,
2, bytes0_1);
if (modulo == 8) {
proto_tree_add_uint(x25_tree, hf_x25_p_r_mod8, tvb,
localoffset, 1, pkt_type);
proto_tree_add_uint(x25_tree, hf_x25_type_fc_mod8, tvb,
localoffset, 1, X25_RNR);
}
else {
proto_tree_add_uint(x25_tree, hf_x25_type, tvb,
localoffset, 1, X25_RNR);
proto_tree_add_item(x25_tree, hf_x25_p_r_mod128, tvb,
localoffset+1, 1, ENC_BIG_ENDIAN);
}
}
break;
case X25_REJ:
if(check_col(pinfo->cinfo, COL_INFO)) {
if (modulo == 8)
col_add_fstr(pinfo->cinfo, COL_INFO, "REJ VC:%d P(R):%d",
vc, (pkt_type >> 5) & 0x07);
else
col_add_fstr(pinfo->cinfo, COL_INFO, "REJ VC:%d P(R):%d",
vc, tvb_get_guint8(tvb, localoffset+1) >> 1);
}
if (x25_tree) {
proto_tree_add_uint(x25_tree, hf_x25_lcn, tvb, localoffset-2,
2, bytes0_1);
if (modulo == 8) {
proto_tree_add_uint(x25_tree, hf_x25_p_r_mod8, tvb,
localoffset, 1, pkt_type);
proto_tree_add_uint(x25_tree, hf_x25_type_fc_mod8, tvb,
localoffset, 1, X25_REJ);
}
else {
proto_tree_add_uint(x25_tree, hf_x25_type, tvb,
localoffset, 1, X25_REJ);
proto_tree_add_item(x25_tree, hf_x25_p_r_mod128, tvb,
localoffset+1, 1, ENC_BIG_ENDIAN);
}
}
}
localoffset += (modulo == 8) ? 1 : 2;
}
if (localoffset >= tvb_reported_length(tvb))
return;
if (pinfo->fragmented)
return;
if (!next_tvb)
next_tvb = tvb_new_subset_remaining(tvb, localoffset);
saved_private_data = pinfo->private_data;
pinfo->private_data = &q_bit_set;
if (try_circuit_dissector(CT_X25, vc, pinfo->fd->num, next_tvb, pinfo,
tree)) {
pinfo->private_data = saved_private_data;
return;
}
if (payload_is_qllc_sna) {
if (!pinfo->fd->flags.visited)
x25_hash_add_proto_start(vc, pinfo->fd->num, qllc_handle);
call_dissector(qllc_handle, next_tvb, pinfo, tree);
pinfo->private_data = saved_private_data;
return;
}
if (payload_check_data){
if (tvb_get_guint8(tvb, localoffset) == tvb_length(next_tvb)-1) {
if ((tvb_get_guint8(tvb, localoffset+1) & 0x0F) == 0) {
if (!pinfo->fd->flags.visited)
x25_hash_add_proto_start(vc, pinfo->fd->num, ositp_handle);
call_dissector(ositp_handle, next_tvb, pinfo, tree);
pinfo->private_data = saved_private_data;
return;
}
}
switch (tvb_get_guint8(tvb, localoffset)) {
case 0x45:
if (!pinfo->fd->flags.visited)
x25_hash_add_proto_start(vc, pinfo->fd->num, ip_handle);
call_dissector(ip_handle, next_tvb, pinfo, tree);
pinfo->private_data = saved_private_data;
return;
case NLPID_ISO8473_CLNP:
if (!pinfo->fd->flags.visited)
x25_hash_add_proto_start(vc, pinfo->fd->num, clnp_handle);
call_dissector(clnp_handle, next_tvb, pinfo, tree);
pinfo->private_data = saved_private_data;
return;
}
}
if (dissector_try_heuristic(x25_heur_subdissector_list, next_tvb, pinfo,
tree)) {
pinfo->private_data = saved_private_data;
return;
}
call_dissector(data_handle, next_tvb, pinfo, tree);
pinfo->private_data = saved_private_data;
}
static void
dissect_x25_dir(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
dissect_x25_common(tvb, pinfo, tree,
(pinfo->pseudo_header->x25.flags & FROM_DCE) ? X25_FROM_DCE :
X25_FROM_DTE,
pinfo->pseudo_header->x25.flags & FROM_DCE);
}
static void
dissect_x25(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
int direction;
direction = CMP_ADDRESS(&pinfo->src, &pinfo->dst);
if (direction == 0)
direction = (pinfo->srcport > pinfo->destport)*2 - 1;
dissect_x25_common(tvb, pinfo, tree, X25_UNKNOWN, direction > 0);
}
static void
x25_reassemble_init(void)
{
fragment_table_init(&x25_segment_table);
reassembled_table_init(&x25_reassembled_table);
}
void
proto_register_x25(void)
{
static hf_register_info hf[] = {
{ &hf_x25_gfi,
{ "GFI", "x25.gfi", FT_UINT16, BASE_DEC, NULL, 0xF000,
"General format identifier", HFILL }},
{ &hf_x25_abit,
{ "A Bit", "x25.a", FT_BOOLEAN, 16, NULL, X25_ABIT,
"Address Bit", HFILL }},
{ &hf_x25_qbit,
{ "Q Bit", "x25.q", FT_BOOLEAN, 16, NULL, X25_QBIT,
"Qualifier Bit", HFILL }},
{ &hf_x25_dbit,
{ "D Bit", "x25.d", FT_BOOLEAN, 16, NULL, X25_DBIT,
"Delivery Confirmation Bit", HFILL }},
{ &hf_x25_mod,
{ "Modulo", "x25.mod", FT_UINT16, BASE_DEC, VALS(vals_modulo), 0x3000,
"Specifies whether the frame is modulo 8 or 128", HFILL }},
{ &hf_x25_lcn,
{ "Logical Channel", "x25.lcn", FT_UINT16, BASE_DEC, NULL, 0x0FFF,
"Logical Channel Number", HFILL }},
{ &hf_x25_type,
{ "Packet Type", "x25.type", FT_UINT8, BASE_HEX, VALS(vals_x25_type), 0x0,
NULL, HFILL }},
{ &hf_x25_type_fc_mod8,
{ "Packet Type", "x25.type", FT_UINT8, BASE_HEX, VALS(vals_x25_type), 0x1F,
NULL, HFILL }},
{ &hf_x25_type_data,
{ "Packet Type", "x25.type", FT_UINT8, BASE_HEX, VALS(vals_x25_type), 0x01,
NULL, HFILL }},
{ &hf_x25_p_r_mod8,
{ "P(R)", "x25.p_r", FT_UINT8, BASE_DEC, NULL, 0xE0,
"Packet Receive Sequence Number", HFILL }},
{ &hf_x25_p_r_mod128,
{ "P(R)", "x25.p_r", FT_UINT8, BASE_DEC, NULL, 0xFE,
"Packet Receive Sequence Number", HFILL }},
{ &hf_x25_mbit_mod8,
{ "M Bit", "x25.m", FT_BOOLEAN, 8, TFS(&m_bit_tfs), X25_MBIT_MOD8,
"More Bit", HFILL }},
{ &hf_x25_mbit_mod128,
{ "M Bit", "x25.m", FT_BOOLEAN, 8, TFS(&m_bit_tfs), X25_MBIT_MOD128,
"More Bit", HFILL }},
{ &hf_x25_p_s_mod8,
{ "P(S)", "x25.p_s", FT_UINT8, BASE_DEC, NULL, 0x0E,
"Packet Send Sequence Number", HFILL }},
{ &hf_x25_p_s_mod128,
{ "P(S)", "x25.p_s", FT_UINT8, BASE_DEC, NULL, 0xFE,
"Packet Send Sequence Number", HFILL }},
{ &hf_x25_segment_overlap,
{ "Fragment overlap", "x25.fragment.overlap", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment overlaps with other fragments", HFILL }},
{ &hf_x25_segment_overlap_conflict,
{ "Conflicting data in fragment overlap", "x25.fragment.overlap.conflict", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Overlapping fragments contained conflicting data", HFILL }},
{ &hf_x25_segment_multiple_tails,
{ "Multiple tail fragments found", "x25.fragment.multipletails", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Several tails were found when defragmenting the packet", HFILL }},
{ &hf_x25_segment_too_long_segment,
{ "Fragment too long", "x25.fragment.toolongfragment", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Fragment contained data past end of packet", HFILL }},
{ &hf_x25_segment_error,
{ "Defragmentation error", "x25.fragment.error", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"Defragmentation error due to illegal fragments", HFILL }},
{ &hf_x25_segment_count,
{ "Fragment count", "x25.fragment.count", FT_UINT32, BASE_DEC, NULL, 0x0,
NULL, HFILL }},
{ &hf_x25_reassembled_length,
{ "Reassembled X.25 length", "x25.reassembled.length", FT_UINT32, BASE_DEC, NULL, 0x0,
"The total length of the reassembled payload", HFILL }},
{ &hf_x25_segment,
{ "X.25 Fragment", "x25.fragment", FT_FRAMENUM, BASE_NONE, NULL, 0x0,
"X25 Fragment", HFILL }},
{ &hf_x25_segments,
{ "X.25 Fragments", "x25.fragments", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &hf_x25_fast_select,
{ "Fast select", "x25.fast_select", FT_UINT8, BASE_DEC, VALS(x25_fast_select_vals), 0xC0,
NULL, HFILL }},
{ &hf_x25_icrd,
{ "ICRD", "x25.icrd", FT_UINT8, BASE_DEC, VALS(x25_icrd_vals), 0x30,
NULL, HFILL }},
{ &hf_x25_reverse_charging,
{ "Reverse charging", "x25.reverse_charging", FT_BOOLEAN, 8, TFS(&x25_reverse_charging_val), 0x01,
NULL, HFILL }},
};
static gint *ett[] = {
&ett_x25,
&ett_x25_gfi,
&ett_x25_fac,
&ett_x25_fac_unknown,
&ett_x25_fac_mark,
&ett_x25_fac_reverse,
&ett_x25_fac_charging_info,
&ett_x25_fac_throughput,
&ett_x25_fac_cug,
&ett_x25_fac_called_modif,
&ett_x25_fac_cug_outgoing_acc,
&ett_x25_fac_throughput_min,
&ett_x25_fac_express_data,
&ett_x25_fac_bilateral_cug,
&ett_x25_fac_packet_size,
&ett_x25_fac_window_size,
&ett_x25_fac_rpoa_selection,
&ett_x25_fac_cug_ext,
&ett_x25_fac_cug_outgoing_acc_ext,
&ett_x25_fac_transit_delay,
&ett_x25_fac_call_duration,
&ett_x25_fac_segment_count,
&ett_x25_fac_call_transfer,
&ett_x25_fac_rpoa_selection_ext,
&ett_x25_fac_monetary_unit,
&ett_x25_fac_nui,
&ett_x25_fac_called_addr_ext,
&ett_x25_fac_ete_transit_delay,
&ett_x25_fac_calling_addr_ext,
&ett_x25_fac_call_deflect,
&ett_x25_fac_priority,
&ett_x25_user_data,
&ett_x25_segment,
&ett_x25_segments
};
module_t *x25_module;
proto_x25 = proto_register_protocol ("X.25", "X.25", "x25");
proto_register_field_array (proto_x25, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
x25_subdissector_table = register_dissector_table("x.25.spi",
"X.25 secondary protocol identifier", FT_UINT8, BASE_HEX);
register_heur_dissector_list("x.25", &x25_heur_subdissector_list);
register_dissector("x.25_dir", dissect_x25_dir, proto_x25);
register_dissector("x.25", dissect_x25, proto_x25);
x25_module = prefs_register_protocol(proto_x25, NULL);
prefs_register_obsolete_preference(x25_module, "non_q_bit_is_sna");
prefs_register_bool_preference(x25_module, "payload_is_qllc_sna",
"Default to QLLC/SNA",
"If CALL REQUEST not seen or didn't specify protocol, dissect as QLLC/SNA",
&payload_is_qllc_sna);
prefs_register_bool_preference(x25_module, "call_request_nodata_is_cotp",
"Assume COTP for Call Request without data",
"If CALL REQUEST has no data, assume the protocol handled is COTP",
&call_request_nodata_is_cotp);
prefs_register_bool_preference(x25_module, "payload_check_data",
"Check data for COTP/IP/CLNP",
"If CALL REQUEST not seen or didn't specify protocol, check user data before checking heuristic dissectors",
&payload_check_data);
prefs_register_bool_preference(x25_module, "reassemble",
"Reassemble fragmented X.25 packets",
"Reassemble fragmented X.25 packets",
&reassemble_x25);
register_init_routine(&x25_reassemble_init);
}
void
proto_reg_handoff_x25(void)
{
dissector_handle_t x25_handle;
ip_handle = find_dissector("ip");
clnp_handle = find_dissector("clnp");
ositp_handle = find_dissector("ositp");
qllc_handle = find_dissector("qllc");
data_handle = find_dissector("data");
x25_handle = find_dissector("x.25");
dissector_add_uint("llc.dsap", SAP_X25, x25_handle);
}
