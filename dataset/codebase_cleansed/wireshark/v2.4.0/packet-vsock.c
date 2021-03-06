static int vsock_addr_to_str(const address* addr, gchar *buf, int buf_len)
{
const guint8 *addrp = (const guint8 *)addr->data;
if(pletoh64(&addrp[0])==2){
g_strlcpy(buf, "host", buf_len);
} else {
g_snprintf(buf, buf_len, "%" G_GINT64_MODIFIER "u", pletoh64(&addrp[0]));
}
return (int)(strlen(buf)+1);
}
static int vsock_addr_str_len(const address* addr _U_)
{
return 19;
}
static int
dissect_vsock(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree,
void *data _U_)
{
proto_item *ti, *virtio_ti;
proto_tree *vsock_tree, *virtio_tree;
guint32 t_len, payload_len, virtio_buf_alloc, op, type,
virtio_fwd_cnt, virtio_op, virtio_type;
guint16 payload_offset = 0, offset = 0;
if (tvb_reported_length(tvb) < VSOCK_MIN_LENGTH)
return 0;
col_clear(pinfo->cinfo, COL_INFO);
ti = proto_tree_add_item(tree, proto_vsock, tvb, 0, -1, ENC_NA);
vsock_tree = proto_item_add_subtree(ti, ett_vsock);
proto_tree_add_item(vsock_tree, hf_vsock_src_cid, tvb, offset, 8, ENC_LITTLE_ENDIAN);
set_address_tvb(&pinfo->src, vsock_address_type, 8, tvb, offset);
offset += 8;
proto_tree_add_item(vsock_tree, hf_vsock_dst_cid, tvb, offset, 8, ENC_LITTLE_ENDIAN);
set_address_tvb(&pinfo->dst, vsock_address_type, 8, tvb, offset);
offset += 8;
proto_tree_add_item_ret_uint(vsock_tree, hf_vsock_src_port, tvb, offset, 4, ENC_LITTLE_ENDIAN, &pinfo->srcport);
offset += 4;
proto_tree_add_item_ret_uint(vsock_tree, hf_vsock_dst_port, tvb, offset, 4, ENC_LITTLE_ENDIAN, &pinfo->destport);
offset += 4;
proto_tree_add_item_ret_uint(vsock_tree, hf_vsock_op, tvb, offset, 2, ENC_LITTLE_ENDIAN, &op);
offset += 2;
proto_tree_add_item_ret_uint(vsock_tree, hf_vsock_t, tvb, offset, 2, ENC_LITTLE_ENDIAN, &type);
offset += 2;
proto_tree_add_item_ret_uint(vsock_tree, hf_vsock_t_len, tvb, offset, 2, ENC_LITTLE_ENDIAN, &t_len);
offset += 2;
payload_offset = offset + t_len;
proto_item_append_text(ti, ", Op: %s, Transport: %s",
val_to_str(op, af_vsockmon_op_names, "Unknown (%d)"),
val_to_str(type, af_vsockmon_t_names, "Unknown (%d)"));
col_add_fstr(pinfo->cinfo, COL_INFO, "[%s] %s",
val_to_str(op, af_vsockmon_op_names, "Unknown (%d)"),
val_to_str(type, af_vsockmon_t_names, "Unknown (%d)"));
col_set_str(pinfo->cinfo, COL_PROTOCOL, "vSocket");
switch (type) {
case AF_VSOCK_T_UNKNOWN:
case AF_VSOCK_T_NO_INFO:
break;
case AF_VSOCK_T_VIRTIO:
virtio_tree = proto_tree_add_subtree(vsock_tree, tvb, offset, 44, ett_virtio, &virtio_ti, "Virtio transport header");
proto_tree_add_item(virtio_tree, hf_virtio_src_cid, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(virtio_tree, hf_virtio_dst_cid, tvb, offset, 8, ENC_LITTLE_ENDIAN);
offset += 8;
proto_tree_add_item(virtio_tree, hf_virtio_src_port, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(virtio_tree, hf_virtio_dst_port, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item(virtio_tree, hf_virtio_len, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(virtio_tree, hf_virtio_type, tvb, offset, 2, ENC_LITTLE_ENDIAN, &virtio_type);
offset += 2;
proto_tree_add_item_ret_uint(virtio_tree, hf_virtio_op, tvb, offset, 2, ENC_LITTLE_ENDIAN, &virtio_op);
offset += 2;
proto_tree_add_item(virtio_tree, hf_virtio_flags, tvb, offset, 4, ENC_LITTLE_ENDIAN);
offset += 4;
proto_tree_add_item_ret_uint(virtio_tree, hf_virtio_buf_alloc, tvb, offset, 4, ENC_LITTLE_ENDIAN, &virtio_buf_alloc);
offset += 4;
proto_tree_add_item_ret_uint(virtio_tree, hf_virtio_fwd_cnt, tvb, offset, 4, ENC_LITTLE_ENDIAN, &virtio_fwd_cnt);
col_append_fstr(pinfo->cinfo, COL_INFO, ": %s, Op: %s, Buf alloc: %u, Fwd cnt: %u",
val_to_str(virtio_type, virtio_vsock_type_names, "Unknown (%d)"),
val_to_str(virtio_op, virtio_vsock_op_names, "Unknown (%d)"),
virtio_buf_alloc, virtio_fwd_cnt);
break;
}
payload_len = tvb_reported_length_remaining(tvb, payload_offset);
if (payload_len)
proto_tree_add_bytes_format(vsock_tree, hf_vsock_payload, tvb, payload_offset, payload_len,
NULL, "Payload (%uB)", payload_len);
return tvb_reported_length(tvb);
}
void
proto_register_vsock(void)
{
static hf_register_info hf[] = {
{ &hf_vsock_src_cid,
{"Source cid", "vsock.src_cid", FT_UINT64, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_vsock_dst_cid,
{"Destination cid", "vsock.dst_cid", FT_UINT64, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_vsock_src_port,
{"Source port", "vsock.src_port", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_vsock_dst_port,
{"Destination port", "vsock.dst_port", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_vsock_op,
{"Operation", "vsock.op", FT_UINT16, BASE_DEC, VALS(af_vsockmon_op_names),
0x0, NULL, HFILL }},
{ &hf_vsock_t,
{"Transport", "vsock.trans", FT_UINT16, BASE_DEC, VALS(af_vsockmon_t_names),
0x0, NULL, HFILL }},
{ &hf_vsock_t_len,
{"Transport length", "vsock.trans_len", FT_UINT16, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_vsock_payload,
{ "Payload", "vsock.payload", FT_BYTES, BASE_NONE, NULL,
0x0, NULL, HFILL}},
{ &hf_virtio_src_cid,
{"Source cid", "vsock.virtio.src_cid", FT_UINT64, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_virtio_dst_cid,
{"Destination cid", "vsock.virtio.dst_cid", FT_UINT64, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_virtio_src_port,
{"Source port", "vsock.virtio.src_prot", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_virtio_dst_port,
{"Destination port", "vsock.virtio.dst_prot", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_virtio_len,
{"Length", "vsock.virtio.len", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_virtio_type,
{"Type", "vsock.virtio.type", FT_UINT16, BASE_DEC, VALS(virtio_vsock_type_names),
0x0, NULL, HFILL }},
{ &hf_virtio_op,
{"Operation", "vsock.virtio.op", FT_UINT16, BASE_DEC, VALS(virtio_vsock_op_names),
0x0, NULL, HFILL }},
{ &hf_virtio_flags,
{"Flags", "vsock.virtio.flags", FT_UINT32, BASE_HEX, NULL,
0x0, NULL, HFILL }},
{ &hf_virtio_buf_alloc,
{"Buf alloc", "vsock.virtio.buf_alloc", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }},
{ &hf_virtio_fwd_cnt,
{"Fwd cnt", "vsock.virtio.fwd_cnt", FT_UINT32, BASE_DEC, NULL,
0x0, NULL, HFILL }}
};
static gint *ett[] = {
&ett_vsock,
&ett_virtio
};
vsock_address_type = address_type_dissector_register("AT_VSOCK", "vSocket Address",
vsock_addr_to_str, vsock_addr_str_len, NULL, NULL, NULL, NULL, NULL);
proto_vsock = proto_register_protocol("vSocket", "vsock", "vsock");
proto_register_field_array(proto_vsock, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("vsock", dissect_vsock, proto_vsock);
}
