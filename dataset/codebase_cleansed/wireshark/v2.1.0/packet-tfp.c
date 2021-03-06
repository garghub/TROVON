static void
base58_encode(guint32 value, char *str) {
guint32 mod;
gint i = 0;
gint k;
gchar reverse_str[BASE58_MAX_STR_SIZE] = {'\0'};
while (value >= 58) {
mod = value % 58;
reverse_str[i] = BASE58_ALPHABET[mod];
value = value / 58;
++i;
}
reverse_str[i] = BASE58_ALPHABET[value];
for (k = 0; k <= i; k++) {
str[k] = reverse_str[i - k];
}
for (; k < BASE58_MAX_STR_SIZE; k++) {
str[k] = '\0';
}
}
static void
dissect_tfp_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree) {
gint byte_offset = 0;
gint bit_offset = 48;
guint8 hv_tfp_len;
guint8 hv_tfp_fid;
guint8 hv_tfp_seq;
gchar tfp_uid_string[BASE58_MAX_STR_SIZE];
base58_encode(tvb_get_letohl(tvb, 0), &tfp_uid_string[0]);
hv_tfp_len = tvb_get_guint8(tvb, byte_offset_len);
hv_tfp_fid = tvb_get_guint8(tvb, byte_offset_fid);
hv_tfp_seq = tvb_get_bits8(tvb, bit_offset, bit_count_tfp_seq);
col_add_fstr(pinfo->cinfo, COL_INFO,
"UID: %s, Len: %d, FID: %d, Seq: %d",
&tfp_uid_string[0], hv_tfp_len, hv_tfp_fid, hv_tfp_seq);
if (tree) {
proto_tree *tfp_tree;
proto_item *ti;
ti = proto_tree_add_protocol_format(tree, proto_tfp, tvb, 0, -1,
"Tinkerforge Protocol, UID: %s, Len: %d, FID: %d, Seq: %d",
&tfp_uid_string[0], hv_tfp_len, hv_tfp_fid, hv_tfp_seq);
tfp_tree = proto_item_add_subtree(ti, ett_tfp);
ti = proto_tree_add_string_format_value(tfp_tree,
hf_tfp_uid,
tvb, byte_offset, byte_count_tfp_uid,
&tfp_uid_string[0], "%s", &tfp_uid_string[0]);
PROTO_ITEM_SET_GENERATED(ti);
proto_tree_add_item(tfp_tree,
hf_tfp_uid_numeric,
tvb,
byte_offset,
byte_count_tfp_uid,
ENC_LITTLE_ENDIAN);
byte_offset += byte_count_tfp_uid;
proto_tree_add_item(tfp_tree,
hf_tfp_len,
tvb,
byte_offset,
byte_count_tfp_len,
ENC_LITTLE_ENDIAN);
byte_offset += byte_count_tfp_len;
proto_tree_add_item(tfp_tree,
hf_tfp_fid,
tvb,
byte_offset,
byte_count_tfp_fid,
ENC_LITTLE_ENDIAN);
byte_offset += byte_count_tfp_fid;
proto_tree_add_bits_item(tfp_tree,
hf_tfp_seq,
tvb,
bit_offset,
bit_count_tfp_seq,
ENC_LITTLE_ENDIAN);
bit_offset += bit_count_tfp_seq;
proto_tree_add_bits_item(tfp_tree,
hf_tfp_r,
tvb,
bit_offset,
bit_count_tfp_r,
ENC_LITTLE_ENDIAN);
bit_offset += bit_count_tfp_r;
proto_tree_add_bits_item(tfp_tree,
hf_tfp_a,
tvb,
bit_offset,
bit_count_tfp_a,
ENC_LITTLE_ENDIAN);
bit_offset += bit_count_tfp_a;
proto_tree_add_bits_item(tfp_tree,
hf_tfp_oo,
tvb,
bit_offset,
bit_count_tfp_oo,
ENC_LITTLE_ENDIAN);
bit_offset += bit_count_tfp_oo;
proto_tree_add_bits_item(tfp_tree,
hf_tfp_e,
tvb,
bit_offset,
bit_count_tfp_e,
ENC_LITTLE_ENDIAN);
bit_offset += bit_count_tfp_e;
proto_tree_add_bits_item(tfp_tree,
hf_tfp_future_use,
tvb,
bit_offset,
bit_count_tfp_future_use,
ENC_LITTLE_ENDIAN);
if ((tvb_reported_length(tvb)) > 8) {
byte_offset += byte_count_tfp_flags;
proto_tree_add_item(tfp_tree, hf_tfp_payload, tvb, byte_offset, -1, ENC_NA);
}
}
}
static int
dissect_tfp_tcp(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void* data _U_)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TFP over TCP");
col_clear(pinfo->cinfo, COL_INFO);
dissect_tfp_common(tvb, pinfo, tree);
return tvb_captured_length(tvb);
}
static gboolean
dissect_tfp_bulk_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data)
{
usb_conv_info_t *usb_conv_info = (usb_conv_info_t *)data;
if ((usb_conv_info != NULL) &&
(usb_conv_info->deviceVendor == tfp_USB_VENDOR_ID) &&
(usb_conv_info->deviceProduct == tfp_USB_PRODUCT_ID)) {
col_set_str(pinfo->cinfo, COL_PROTOCOL, "TFP over USB");
col_clear(pinfo->cinfo, COL_INFO);
dissect_tfp_common(tvb, pinfo, tree);
return TRUE;
}
return FALSE;
}
void
proto_register_tfp(void)
{
static hf_register_info hf_tfp[] = {
{ &hf_tfp_uid,
{ "UID (String)",
"tfp.uid",
FT_STRINGZ,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
},
{ &hf_tfp_uid_numeric,
{ "UID (Numeric)",
"tfp.uid_numeric",
FT_UINT32,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
{ &hf_tfp_len,
{ "Length",
"tfp.len",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
{ &hf_tfp_fid,
{ "Function ID",
"tfp.fid",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
{ &hf_tfp_seq,
{ "Sequence Number",
"tfp.seq",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
{ &hf_tfp_r,
{ "Response Expected",
"tfp.r",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
{ &hf_tfp_a,
{ "Authentication",
"tfp.a",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
{ &hf_tfp_oo,
{ "Other Options",
"tfp.oo",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
{ &hf_tfp_e,
{ "Error Code",
"tfp.e",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
{ &hf_tfp_future_use,
{ "Future Use",
"tfp.future_use",
FT_UINT8,
BASE_DEC,
NULL,
0x0,
NULL,
HFILL
}
},
{ &hf_tfp_payload,
{ "Payload",
"tfp.payload",
FT_BYTES,
BASE_NONE,
NULL,
0x0,
NULL,
HFILL
}
}
};
static gint *ett[] = {
&ett_tfp
};
proto_tfp = proto_register_protocol (
"Tinkerforge Protocol",
"TFP",
"tfp"
);
proto_register_field_array(proto_tfp, hf_tfp, array_length(hf_tfp));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_tfp(void) {
dissector_handle_t tfp_handle_tcp;
tfp_handle_tcp = create_dissector_handle(dissect_tfp_tcp, proto_tfp);
dissector_add_uint("tcp.port", tfp_PORT, tfp_handle_tcp);
heur_dissector_add("usb.bulk", dissect_tfp_bulk_heur, "Tinkerforge USB bulk endpoint", "tfp_usb_bulk", proto_tfp, HEURISTIC_ENABLE);
}
