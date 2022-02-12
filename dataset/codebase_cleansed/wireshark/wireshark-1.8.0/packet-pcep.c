static void
dissect_pcep_tlvs(proto_tree *pcep_obj, tvbuff_t *tvb, int offset, gint length, gint ett_pcep_obj)
{
proto_tree *tlv;
proto_item *ti;
guint16 tlv_length;
guint16 tlv_type;
int i, j;
int padding = 0;
for (j = 0; j < length; j += 4 + tlv_length + padding){
tlv_type = tvb_get_ntohs(tvb, offset+j);
tlv_length = tvb_get_ntohs(tvb, offset + j + 2);
ti = proto_tree_add_text(pcep_obj, tvb, offset + j, tlv_length+4, "%s", val_to_str(tlv_type, pcep_tlvs_vals, "Unknown TLV (%u). "));
tlv = proto_item_add_subtree(ti, ett_pcep_obj);
proto_tree_add_text(tlv, tvb, offset + j, 2, "Type: %u", tlv_type);
proto_tree_add_text(tlv, tvb, offset + 2 + j, 2, "Length: %u", tlv_length);
switch (tlv_type)
{
case 1:
proto_tree_add_text(tlv, tvb, offset+4+j, tlv_length, "%s",
decode_boolean_bitfield(tvb_get_ntohl(tvb, offset+4+j), 0x0001, 32, "PCE currently unavailable", ""));
proto_tree_add_text(tlv, tvb, offset+4+j, tlv_length, "%s",
decode_boolean_bitfield(tvb_get_ntohl(tvb, offset+4+j), 0x0002, 32, "Unknown destination", ""));
proto_tree_add_text(tlv, tvb, offset+4+j, tlv_length, "%s",
decode_boolean_bitfield(tvb_get_ntohl(tvb, offset+4+j), 0x0004, 32, "Unknown source", ""));
break;
case 3:
proto_tree_add_text(tlv, tvb, offset+4+j, tlv_length, "Request-ID: %u", tvb_get_ntohl(tvb, offset+4+j));
break;
case 4:
for (i=0; i<tlv_length/2; i++)
proto_tree_add_text(tlv, tvb, offset+4+j+i*2, 2, "OF-Code #%d: %s (%u)",
i+1, val_to_str(tvb_get_ntohs(tvb, offset+4+j+i*2), pcep_of_vals, "Unknown"),
tvb_get_ntohs(tvb, offset+4+j+i*2));
break;
default:
proto_tree_add_text(tlv, tvb, offset+4+j, tlv_length, "Data: %s",
tvb_bytes_to_str_punct(tvb, (offset) + 4 + j, tlv_length, ' '));
}
padding = (4 - (tlv_length % 4)) % 4;
if (padding != 0){
proto_tree_add_text(tlv, tvb, offset+4+j+tlv_length, padding, "Padding: %s",
tvb_bytes_to_str_punct(tvb, (offset) + 4 + j + tlv_length, padding, ' '));
}
}
}
static void
dissect_subobj_ipv4(proto_tree *pcep_subobj_tree, tvbuff_t *tvb, int offset, int obj_class, gint ett_pcep_obj, guint l_and_or_type, guint length)
{
proto_tree *pcep_subobj_ipv4;
proto_tree *pcep_subobj_ipv4_flags;
proto_item *ti;
guint8 prefix_length;
guint8 resvd;
guint l;
ti = proto_tree_add_item(pcep_subobj_tree, pcep_filter[PCEPF_SUBOBJ_IPv4], tvb, offset, length, ENC_NA);
pcep_subobj_ipv4 = proto_item_add_subtree(ti, ett_pcep_obj);
if (length != 8) {
proto_tree_add_text(pcep_subobj_ipv4, tvb, offset, length,
"Bad IPv4 subobject: length %u != 8", length);
return;
}
prefix_length = tvb_get_guint8(tvb, offset+6);
resvd = tvb_get_guint8(tvb, offset+7);
proto_item_append_text(ti, ": %s/%u", tvb_ip_to_str(tvb, offset+2),
prefix_length);
switch(obj_class){
case PCEP_EXPLICIT_ROUTE_OBJ:
l = (l_and_or_type& Mask_L)>>7;
proto_tree_add_text(pcep_subobj_ipv4, tvb, offset, 1, "%s",val_to_str(l, pcep_route_l_obj_vals, "Unknown Object (%u). "));
proto_tree_add_uint(pcep_subobj_ipv4, pcep_filter[PCEPF_SUBOBJ], tvb, offset, 1, (l_and_or_type & 0x7f));
proto_tree_add_text(pcep_subobj_ipv4, tvb, offset+1, 1, "Length: %u", length);
proto_tree_add_text(pcep_subobj_ipv4, tvb, offset+2, 4, "IPv4 Address: %s", tvb_ip_to_str(tvb, offset+2));
proto_tree_add_text(pcep_subobj_ipv4, tvb, offset+6, 1, "Prefix Length: %u", prefix_length);
proto_tree_add_text(pcep_subobj_ipv4, tvb, offset+7, 1, "Padding: 0x%02x", resvd);
break;
case PCEP_RECORD_ROUTE_OBJ:
proto_tree_add_uint(pcep_subobj_ipv4, pcep_filter[PCEPF_SUBOBJ], tvb, offset, 1, l_and_or_type);
proto_tree_add_text(pcep_subobj_ipv4, tvb, offset+1, 1, "Length: %u", length);
proto_tree_add_text(pcep_subobj_ipv4, tvb, offset+2, 4, "IPv4 Address: %s", tvb_ip_to_str(tvb, offset+2));
proto_tree_add_text(pcep_subobj_ipv4, tvb, offset+6, 1, "Prefix Length: %u", prefix_length);
ti = proto_tree_add_text(pcep_subobj_ipv4, tvb, offset+7, 1, "Flags: 0x%02x ", resvd);
pcep_subobj_ipv4_flags = proto_item_add_subtree(ti, ett_pcep_obj);
proto_tree_add_boolean(pcep_subobj_ipv4_flags, pcep_subobj_flags_lpa, tvb, offset+7, 1, resvd);
proto_tree_add_boolean(pcep_subobj_ipv4_flags, pcep_subobj_flags_lpu, tvb, offset+7, 1, resvd);
break;
case PCEP_IRO_OBJ:
proto_tree_add_text(pcep_subobj_ipv4, tvb, offset, 1, "l: %x", (l_and_or_type & 0x80)>>7);
proto_tree_add_uint(pcep_subobj_ipv4, pcep_filter[PCEPF_SUBOBJ], tvb, offset, 1, (l_and_or_type & 0x7f));
proto_tree_add_text(pcep_subobj_ipv4, tvb, offset+1, 1, "Length: %u", length);
proto_tree_add_text(pcep_subobj_ipv4, tvb, offset+2, 4, "IPv4 Address: %s", tvb_ip_to_str(tvb, offset+2));
proto_tree_add_text(pcep_subobj_ipv4, tvb, offset+6, 1, "Prefix Length: %u", prefix_length);
proto_tree_add_text(pcep_subobj_ipv4, tvb, offset+7, 1, "Padding: 0x%02x", resvd);
break;
case PCEP_XRO_OBJ:
proto_tree_add_text(pcep_subobj_ipv4, tvb, offset, 1, "X: %x", (l_and_or_type & 0x01)>>7);
proto_tree_add_uint(pcep_subobj_ipv4, pcep_filter[PCEPF_SUBOBJ_XRO], tvb, offset, 1, (l_and_or_type & 0x7f));
proto_tree_add_text(pcep_subobj_ipv4, tvb, offset, 1, "Type: %u", (l_and_or_type & 0x7f));
proto_tree_add_text(pcep_subobj_ipv4, tvb, offset+1, 1, "Length: %u", length);
proto_tree_add_text(pcep_subobj_ipv4, tvb, offset+2, 4, "IPv4 Address: %s", tvb_ip_to_str(tvb, offset+2));
proto_tree_add_text(pcep_subobj_ipv4, tvb, offset+6, 1, "Prefix Length: %u", prefix_length);
proto_tree_add_text(pcep_subobj_ipv4, tvb, offset+7, 1, "Attribute: %s (%u)",val_to_str(resvd, pcep_xro_attribute_obj_vals, "Unknown"), resvd);
break;
default:
proto_tree_add_text(pcep_subobj_ipv4, tvb, offset, 8, "Non defined subobject for this object");
break;
}
}
static void
dissect_subobj_ipv6(proto_tree *pcep_subobj_tree, tvbuff_t *tvb, int offset, int obj_class, gint ett_pcep_obj, guint l_and_or_type, guint length)
{
proto_tree *pcep_subobj_ipv6;
proto_tree *pcep_subobj_ipv6_flags;
proto_item *ti;
guint8 prefix_length;
guint8 resv;
int l;
ti = proto_tree_add_item(pcep_subobj_tree, pcep_filter[PCEPF_SUBOBJ_IPv6], tvb, offset, length, ENC_NA);
pcep_subobj_ipv6 = proto_item_add_subtree(ti, ett_pcep_obj);
if (length != 20) {
proto_tree_add_text(pcep_subobj_ipv6, tvb, offset, length,
"Bad IPv6 subobject: length %u != 20", length);
return;
}
prefix_length = tvb_get_guint8(tvb, offset+18);
resv = tvb_get_guint8(tvb, offset+19);
proto_item_append_text(ti, ": %s/%u", tvb_ip6_to_str(tvb, offset+2),
prefix_length);
switch(obj_class){
case PCEP_EXPLICIT_ROUTE_OBJ:
l = (l_and_or_type& Mask_L)>>7;
proto_tree_add_text(pcep_subobj_ipv6, tvb, offset, 1, "%s",val_to_str(l, pcep_route_l_obj_vals, "Unknown Object (%u). "));
proto_tree_add_uint(pcep_subobj_ipv6, pcep_filter[PCEPF_SUBOBJ], tvb, offset, 1, (l_and_or_type & 0x7f));
proto_tree_add_text(pcep_subobj_ipv6, tvb, offset+1, 1, "Length: %u", length);
proto_tree_add_text(pcep_subobj_ipv6, tvb, offset+2, 16, "IPv6 Address: %s", tvb_ip6_to_str(tvb, offset+2));
proto_tree_add_text(pcep_subobj_ipv6, tvb, offset+18, 1, "Prefix Length: %u", prefix_length);
proto_tree_add_text(pcep_subobj_ipv6, tvb, offset+19, 1, "Padding: 0x%02x", resv);
break;
case PCEP_RECORD_ROUTE_OBJ:
proto_tree_add_uint(pcep_subobj_ipv6, pcep_filter[PCEPF_SUBOBJ], tvb, offset, 1, l_and_or_type);
proto_tree_add_text(pcep_subobj_ipv6, tvb, offset+1, 1, "Length: %u", length);
proto_tree_add_text(pcep_subobj_ipv6, tvb, offset+2, 16, "IPv6 Address: %s", tvb_ip6_to_str(tvb, offset+2));
proto_tree_add_text(pcep_subobj_ipv6, tvb, offset+18, 1, "Prefix Length: %u", prefix_length);
ti = proto_tree_add_text(pcep_subobj_ipv6, tvb, offset+19, 1, "Flags: 0x%02x ", resv);
pcep_subobj_ipv6_flags = proto_item_add_subtree(ti, ett_pcep_obj);
proto_tree_add_boolean(pcep_subobj_ipv6_flags, pcep_subobj_flags_lpa, tvb, offset+19, 1, resv);
proto_tree_add_boolean(pcep_subobj_ipv6_flags, pcep_subobj_flags_lpu, tvb, offset+19, 1, resv);
break;
case PCEP_IRO_OBJ:
proto_tree_add_text(pcep_subobj_ipv6, tvb, offset, 1, "l: %x", (l_and_or_type & 0x80)>>7);
proto_tree_add_uint(pcep_subobj_ipv6, pcep_filter[PCEPF_SUBOBJ], tvb, offset, 1, (l_and_or_type & 0x7f));
proto_tree_add_text(pcep_subobj_ipv6, tvb, offset+1, 1, "Length: %u", length);
proto_tree_add_text(pcep_subobj_ipv6, tvb, offset+2, 16, "IPv6 Address: %s", tvb_ip6_to_str(tvb, offset+2));
proto_tree_add_text(pcep_subobj_ipv6, tvb, offset+18, 1, "Prefix Length: %u", prefix_length);
proto_tree_add_text(pcep_subobj_ipv6, tvb, offset+19, 1, "Padding: 0x%02x", resv);
break;
case PCEP_XRO_OBJ:
proto_tree_add_text(pcep_subobj_ipv6, tvb, offset, 1, "X: %x", (l_and_or_type & 0x01)>>7);
proto_tree_add_uint(pcep_subobj_ipv6, pcep_filter[PCEPF_SUBOBJ_XRO], tvb, offset, 1, (l_and_or_type & 0x7f));
proto_tree_add_text(pcep_subobj_ipv6, tvb, offset+1, 1, "Length: %u", length);
proto_tree_add_text(pcep_subobj_ipv6, tvb, offset+2, 16, "IPv6 Address: %s", tvb_ip6_to_str(tvb, offset+2));
proto_tree_add_text(pcep_subobj_ipv6, tvb, offset+18, 1, "Prefix Length: %u", prefix_length);
proto_tree_add_text(pcep_subobj_ipv6, tvb, offset+19, 1, "Attribute: %s (%u)", val_to_str(resv, pcep_xro_attribute_obj_vals, "Unknown"), resv);
break;
default:
proto_tree_add_text(pcep_subobj_ipv6, tvb, offset, 20, "Non defined subobject for this object");
break;
}
}
static void
dissect_subobj_label_control(proto_tree *pcep_subobj_tree, tvbuff_t *tvb, int offset, int obj_class, gint ett_pcep_obj, guint l_and_or_type, guint length)
{
proto_tree *pcep_subobj_label_control;
proto_tree *pcep_subobj_label_flags;
proto_item *ti;
guint8 u_reserved;
guint8 c_type;
int l;
int u;
ti = proto_tree_add_item(pcep_subobj_tree, pcep_filter[PCEPF_SUBOBJ_LABEL_CONTROL], tvb, offset, length, ENC_NA);
pcep_subobj_label_control = proto_item_add_subtree(ti, ett_pcep_obj);
if (length < 5) {
proto_tree_add_text(pcep_subobj_label_control, tvb, offset, length,
"Bad label control subobject: length %u < 5", length);
return;
}
u_reserved = tvb_get_guint8(tvb, offset+2);
c_type = tvb_get_guint8(tvb, offset+3);
switch(obj_class){
case PCEP_EXPLICIT_ROUTE_OBJ:
l = (l_and_or_type& Mask_L)>>7;
proto_tree_add_text(pcep_subobj_label_control, tvb, offset, 1, "%s", val_to_str(l, pcep_route_l_obj_vals, "Unknown Object (%u). "));
proto_tree_add_uint(pcep_subobj_label_control, pcep_filter[PCEPF_SUBOBJ], tvb, offset, 1, (l_and_or_type & 0x7f));
proto_tree_add_text(pcep_subobj_label_control, tvb, offset+1, 1, "Length: %u", length);
u = (u_reserved & 0x80)>>7;
proto_tree_add_text(pcep_subobj_label_control, tvb, offset+2, 1, "%s", val_to_str(u, pcep_route_u_obj_vals, "Unknown Object (%u). "));
proto_tree_add_text(pcep_subobj_label_control, tvb, offset+2, 1, "Reserved: %u", (u_reserved & 0x7f));
proto_tree_add_text(pcep_subobj_label_control, tvb, offset+3, 1, "C-Type: %u", c_type);
proto_tree_add_text(pcep_subobj_label_control, tvb, offset+4, length-4, "Label: %s",
tvb_bytes_to_str_punct(tvb, offset+4, length-4, ' '));
break;
case PCEP_RECORD_ROUTE_OBJ:
proto_tree_add_uint(pcep_subobj_label_control, pcep_filter[PCEPF_SUBOBJ], tvb, offset, 1, l_and_or_type);
proto_tree_add_text(pcep_subobj_label_control, tvb, offset+1, 1, "Length: %u", length);
u = (u_reserved & 0x80)>>7;
proto_tree_add_text(pcep_subobj_label_control, tvb, offset+2, 1, "%s", val_to_str(u, pcep_route_u_obj_vals, "Unknown Object (%u). "));
ti = proto_tree_add_text(pcep_subobj_label_control, tvb, offset+2, 1, "Flags: 0x%02x ", (u_reserved & 0x7f));
pcep_subobj_label_flags = proto_item_add_subtree(ti, ett_pcep_obj);
proto_tree_add_boolean(pcep_subobj_label_flags, pcep_subobj_label_flags_gl, tvb, offset+2, 1, (u_reserved & 0x7f));
proto_tree_add_text(pcep_subobj_label_control, tvb, offset+3, 1, "C-Type: %u", c_type);
proto_tree_add_text(pcep_subobj_label_control, tvb, offset+4, length-4, "Label: %s",
tvb_bytes_to_str_punct(tvb, offset+4, length-4, ' '));
break;
default:
proto_tree_add_text(pcep_subobj_label_control, tvb, offset, length, "Non defined subobject for this object");
break;
}
}
static void
dissect_subobj_unnumb_interfaceID(proto_tree *pcep_subobj_tree, tvbuff_t *tvb, int offset, int obj_class, gint ett_pcep_obj, guint l_and_or_type, guint length)
{
proto_tree *pcep_subobj_unnumb_interfaceID;
proto_tree *pcep_subobj_unnumb_interfaceID_flags;
proto_item *ti;
guint32 router_ID;
guint32 interface_ID;
guint16 reserved_flags;
int l;
ti = proto_tree_add_item(pcep_subobj_tree, pcep_filter[PCEPF_SUBOBJ_UNNUM_INTERFACEID], tvb, offset, length, ENC_NA);
pcep_subobj_unnumb_interfaceID = proto_item_add_subtree(ti, ett_pcep_obj);
if (length != 12) {
proto_tree_add_text(pcep_subobj_unnumb_interfaceID, tvb, offset, length,
"Bad unnumbered interface ID subobject: length %u != 12", length);
return;
}
reserved_flags = tvb_get_ntohs(tvb, offset+2);
router_ID = tvb_get_ipv4(tvb, offset+4);
interface_ID = tvb_get_ntohl(tvb, offset+8);
proto_item_append_text(ti, ": %s:%u", ip_to_str ((guint8 *) &router_ID),
interface_ID);
switch(obj_class){
case PCEP_EXPLICIT_ROUTE_OBJ:
l = (l_and_or_type& Mask_L)>>7;
proto_tree_add_text(pcep_subobj_unnumb_interfaceID, tvb, offset, 1, "%s", val_to_str(l, pcep_route_l_obj_vals, "Unknown Object (%u). "));
proto_tree_add_uint(pcep_subobj_unnumb_interfaceID, pcep_filter[PCEPF_SUBOBJ], tvb, offset, 1, (l_and_or_type & 0x7f));
proto_tree_add_text(pcep_subobj_unnumb_interfaceID, tvb, offset+1, 1, "Length: %u", length);
proto_tree_add_text(pcep_subobj_unnumb_interfaceID, tvb, offset+2, 2, "Reserved: 0x%04x", reserved_flags);
break;
case PCEP_RECORD_ROUTE_OBJ:
proto_tree_add_uint(pcep_subobj_unnumb_interfaceID, pcep_filter[PCEPF_SUBOBJ], tvb, offset, 1, l_and_or_type);
proto_tree_add_text(pcep_subobj_unnumb_interfaceID, tvb, offset+1, 1, "Length: %u", length);
ti = proto_tree_add_text(pcep_subobj_unnumb_interfaceID, tvb, offset+2, 2, "Flags: 0x%02x ", (reserved_flags & 0xff00)>>8);
pcep_subobj_unnumb_interfaceID_flags = proto_item_add_subtree(ti, ett_pcep_obj);
proto_tree_add_boolean(pcep_subobj_unnumb_interfaceID_flags, pcep_subobj_flags_lpa, tvb, offset+2, 1, (reserved_flags & 0xff00)>>8);
proto_tree_add_boolean(pcep_subobj_unnumb_interfaceID_flags, pcep_subobj_flags_lpu, tvb, offset+2, 1, (reserved_flags & 0xff00)>>8);
proto_tree_add_text(pcep_subobj_unnumb_interfaceID, tvb, offset+3, 1, "Reserved: 0x%02x", (reserved_flags & 0x00ff));
break;
case PCEP_IRO_OBJ:
proto_tree_add_text(pcep_subobj_unnumb_interfaceID, tvb, offset, 1, "l: %x", (l_and_or_type & 0x80)>>7);
proto_tree_add_uint(pcep_subobj_unnumb_interfaceID, pcep_filter[PCEPF_SUBOBJ], tvb, offset, 1, (l_and_or_type & 0x7f));
proto_tree_add_text(pcep_subobj_unnumb_interfaceID, tvb, offset+1, 1, "Length: %u", length);
proto_tree_add_text(pcep_subobj_unnumb_interfaceID, tvb, offset+2, 2, "Reserved: 0x%04x", reserved_flags);
break;
case PCEP_XRO_OBJ:
proto_tree_add_text(pcep_subobj_unnumb_interfaceID, tvb, offset, 1, "X: %x", (l_and_or_type & 0x01)>>7);
proto_tree_add_uint(pcep_subobj_unnumb_interfaceID, pcep_filter[PCEPF_SUBOBJ_XRO], tvb, offset, 1, (l_and_or_type & 0x7f));
proto_tree_add_text(pcep_subobj_unnumb_interfaceID, tvb, offset+2, 1, "Reserved: 0x%02x", (reserved_flags & 0xff00)>>4);
proto_tree_add_text(pcep_subobj_unnumb_interfaceID, tvb, offset+3, 1, "Attribute: %s (%u)", val_to_str(reserved_flags & 0x00ff, pcep_xro_attribute_obj_vals, "Unknown"), reserved_flags & 0x00ff);
break;
default:
proto_tree_add_text(pcep_subobj_unnumb_interfaceID, tvb, offset, 12, "Non defined subobject for this object");
break;
}
proto_tree_add_text(pcep_subobj_unnumb_interfaceID, tvb, offset+4, 4, "Router ID: %s", ip_to_str((guint8 *) &router_ID));
proto_tree_add_text(pcep_subobj_unnumb_interfaceID, tvb, offset+8, 4, "Interface ID: %d (0x%08x)", interface_ID, interface_ID);
}
static void
dissect_subobj_autonomous_sys_num(proto_tree *pcep_subobj_tree, tvbuff_t *tvb, int offset, int obj_class, guint ett_pcep_obj, guint l_and_or_type, guint length)
{
proto_tree *pcep_subobj_autonomous_sys_num;
proto_item *ti;
guint16 AS_number;
guint8 reserved;
guint8 attribute;
int l;
l = (l_and_or_type& Mask_L)>>7;
if(obj_class == PCEP_XRO_OBJ){
reserved = tvb_get_guint8(tvb, offset+2);
attribute = tvb_get_guint8(tvb, offset+3);
AS_number = tvb_get_ntohs(tvb, offset+6);
ti = proto_tree_add_item(pcep_subobj_tree, pcep_filter[PCEPF_SUBOBJ_AUTONOMOUS_SYS_NUM], tvb, offset, length, ENC_NA);
pcep_subobj_autonomous_sys_num = proto_item_add_subtree(ti, ett_pcep_obj);
if (length != 8) {
proto_tree_add_text(pcep_subobj_autonomous_sys_num, tvb, offset, length,
"Bad autonomous system number subobject: length %u != 8", length);
return;
}
proto_tree_add_text(pcep_subobj_autonomous_sys_num, tvb, offset, 1, "X: %x", (l_and_or_type & 0x01)>>7);
proto_tree_add_uint(pcep_subobj_autonomous_sys_num, pcep_filter[PCEPF_SUBOBJ_XRO], tvb, offset, 1, (l_and_or_type & 0x7f));
proto_tree_add_text(pcep_subobj_autonomous_sys_num, tvb, offset+1, 1, "Length: %u", length);
proto_tree_add_text(pcep_subobj_autonomous_sys_num, tvb, offset+2, 1, "Reserved: 0x%02x", reserved);
proto_tree_add_text(pcep_subobj_autonomous_sys_num, tvb, offset+3, 1, "Attribute: %s (%u)", val_to_str(attribute, pcep_xro_attribute_obj_vals, "Unknown"), attribute);
proto_tree_add_text(pcep_subobj_autonomous_sys_num, tvb, offset+4, 2, "Optional AS Number High Octets: 0x%04x", AS_number);
proto_tree_add_text(pcep_subobj_autonomous_sys_num, tvb, offset+6, 2, "AS Number: 0x%04x", AS_number);
} else {
AS_number = tvb_get_ntohs(tvb, offset+2);
ti = proto_tree_add_item(pcep_subobj_tree, pcep_filter[PCEPF_SUBOBJ_AUTONOMOUS_SYS_NUM], tvb, offset, length, ENC_NA);
pcep_subobj_autonomous_sys_num = proto_item_add_subtree(ti, ett_pcep_obj);
if (length != 4) {
proto_tree_add_text(pcep_subobj_autonomous_sys_num, tvb, offset, length,
"Bad autonomous system number subobject: length %u != 4", length);
return;
}
if(obj_class == PCEP_IRO_OBJ)
proto_tree_add_text(pcep_subobj_autonomous_sys_num, tvb, offset, 1, "l: %x", (l_and_or_type & 0x80)>>7);
else
proto_tree_add_text(pcep_subobj_autonomous_sys_num, tvb, offset, 1, "%s", val_to_str(l, pcep_route_l_obj_vals, "Unknown Object (%u). "));
proto_tree_add_uint(pcep_subobj_autonomous_sys_num, pcep_filter[PCEPF_SUBOBJ], tvb, offset, 1, (l_and_or_type & 0x7f));
proto_tree_add_text(pcep_subobj_autonomous_sys_num, tvb, offset+1, 1, "Length: %u", length);
proto_tree_add_text(pcep_subobj_autonomous_sys_num, tvb, offset+2, 2, "AS Number: 0x%04x", AS_number);
}
}
static void
dissect_subobj_srlg(proto_tree *pcep_subobj_tree, tvbuff_t *tvb, int offset, guint ett_pcep_obj, guint l_and_or_type, guint length)
{
proto_tree *pcep_subobj_srlg;
proto_item *ti;
guint32 srlg_id;
guint8 reserved;
guint8 attribute;
srlg_id = tvb_get_ntohl(tvb, offset+2);
reserved = tvb_get_guint8(tvb, offset+6);
attribute = tvb_get_guint8(tvb, offset+7);
ti = proto_tree_add_item(pcep_subobj_tree, pcep_filter[PCEPF_SUBOBJ_SRLG], tvb, offset, length, ENC_NA);
pcep_subobj_srlg = proto_item_add_subtree(ti, ett_pcep_obj);
if (length != 8) {
proto_tree_add_text(pcep_subobj_srlg, tvb, offset, length,
"Bad SRLG subobject: length %u != 8", length);
return;
}
proto_tree_add_text(pcep_subobj_srlg, tvb, offset, 1, "X: %x", (l_and_or_type & 0x01)>>7);
proto_tree_add_uint(pcep_subobj_srlg, pcep_filter[PCEPF_SUBOBJ_XRO], tvb, offset, 1, (l_and_or_type & 0x7f));
proto_tree_add_text(pcep_subobj_srlg, tvb, offset+1, 1, "Length: %u", length);
proto_tree_add_text(pcep_subobj_srlg, tvb, offset+2, 4, "SRLG ID: 0x%08x", srlg_id);
proto_tree_add_text(pcep_subobj_srlg, tvb, offset+6, 1, "Reserved: 0x%02x", reserved);
proto_tree_add_text(pcep_subobj_srlg, tvb, offset+7, 1, "Attribute: %s (%u)", val_to_str(attribute, pcep_xro_attribute_obj_vals, "Unknown"), attribute);
}
static void
dissect_subobj_exrs(proto_tree *pcep_subobj_tree, tvbuff_t *tvb, int offset, int obj_class, guint ett_pcep_obj, guint type_iro, guint l_and_or_type, guint length)
{
proto_tree *pcep_subobj_exrs;
proto_item *ti;
guint16 reserved;
guint8 l_type;
guint8 length2;
guint type_exrs;
guint offset_exrs = 0;
guint l;
ti = proto_tree_add_item(pcep_subobj_tree, pcep_filter[PCEPF_SUBOBJ_EXRS], tvb, offset, length, ENC_NA);
pcep_subobj_exrs = proto_item_add_subtree(ti, ett_pcep_obj);
if (length < 4) {
proto_tree_add_text(pcep_subobj_exrs, tvb, offset, length,
"Bad EXRS subobject: length %u < 4", length);
return;
}
l = (l_and_or_type& Mask_L)>>7;
proto_tree_add_text(pcep_subobj_exrs, tvb, offset, 1, "%s", val_to_str(l, pcep_route_l_obj_vals, "Unknown Object (%u). "));
proto_tree_add_text(pcep_subobj_exrs, tvb, offset, 1, "Type: %u", (l_and_or_type & 0x7f));
proto_tree_add_text(pcep_subobj_exrs, tvb, offset+1, 1, "Length: %u", length);
reserved = tvb_get_ntohs(tvb, offset+2);
proto_tree_add_text(pcep_subobj_exrs, tvb, offset+2, 2, "Reserved: 0x%04x", reserved);
offset += 4;
while(offset_exrs<length-4){
l_type = tvb_get_guint8(tvb, offset);
length2 = tvb_get_guint8(tvb, offset+1);
if (length2 < 2) {
proto_tree_add_text(pcep_subobj_exrs, tvb, offset, 0,
"Bad packet: subobject length %u < 2",
length2);
break;
}
type_exrs = (l_type & Mask_Type);
if(type_iro==PCEP_SUB_EXRS)
obj_class = PCEP_XRO_OBJ;
switch(type_exrs) {
case PCEP_SUB_IPv4:
dissect_subobj_ipv4(pcep_subobj_exrs, tvb, offset, obj_class, ett_pcep_obj, l_type, length2);
break;
case PCEP_SUB_IPv6:
dissect_subobj_ipv6(pcep_subobj_exrs, tvb, offset, obj_class, ett_pcep_obj, l_type, length2);
break;
case PCEP_SUB_UNNUMB_INTERFACE_ID:
dissect_subobj_unnumb_interfaceID(pcep_subobj_exrs, tvb, offset, obj_class, ett_pcep_obj, l_type, length2);
break;
case PCEP_SUB_AUTONOMOUS_SYS_NUM:
dissect_subobj_autonomous_sys_num(pcep_subobj_exrs, tvb, offset, obj_class, ett_pcep_obj, l_type, length2);
break;
case PCEP_SUB_SRLG:
dissect_subobj_srlg(pcep_subobj_exrs, tvb, offset, ett_pcep_obj, l_type, length2);
break;
default:
proto_tree_add_text(pcep_subobj_exrs, tvb, offset+2, length-2,
"Non defined subobject (%d)", type_exrs);
break;
}
offset_exrs += length2;
offset += length2;
}
}
static void
dissect_subobj_pksv4(proto_tree *pcep_subobj_tree, tvbuff_t *tvb, int offset, gint ett_pcep_obj, guint l_and_or_type, guint length)
{
proto_tree *pcep_subobj_pksv4;
proto_item *ti;
guint16 path_key;
int l;
ti = proto_tree_add_item(pcep_subobj_tree, pcep_filter[PCEPF_SUBOBJ_PKSv4], tvb, offset, length, ENC_NA);
pcep_subobj_pksv4 = proto_item_add_subtree(ti, ett_pcep_obj);
if (length != 8) {
proto_tree_add_text(pcep_subobj_pksv4, tvb, offset, length,
"Bad path key subobject: length %u != 8", length);
return;
}
path_key = tvb_get_ntohs(tvb, offset+2);
proto_item_append_text(ti, ": %s, Path Key %u", tvb_ip_to_str(tvb, offset+4), path_key);
l = (l_and_or_type& Mask_L)>>7;
proto_tree_add_text(pcep_subobj_pksv4, tvb, offset, 1, "%s", val_to_str(l, pcep_route_l_obj_vals, "Unknown Object (%u). "));
proto_tree_add_uint(pcep_subobj_pksv4, pcep_filter[PCEPF_SUBOBJ], tvb, offset, 1, (l_and_or_type & 0x7f));
proto_tree_add_text(pcep_subobj_pksv4, tvb, offset+1, 1, "Length: %u", length);
proto_tree_add_text(pcep_subobj_pksv4, tvb, offset+2, 2, "Path Key: %d (0x%04x)", path_key, path_key);
proto_tree_add_text(pcep_subobj_pksv4, tvb, offset+4, 4, "PCE ID: %s", tvb_ip_to_str(tvb, offset+4));
}
static void
dissect_subobj_pksv6(proto_tree *pcep_subobj_tree, tvbuff_t *tvb, int offset, gint ett_pcep_obj, guint l_and_or_type, guint length)
{
proto_tree *pcep_subobj_pksv6;
proto_item *ti;
guint16 path_key;
int l;
ti = proto_tree_add_item(pcep_subobj_tree, pcep_filter[PCEPF_SUBOBJ_PKSv6], tvb, offset, length, ENC_NA);
pcep_subobj_pksv6 = proto_item_add_subtree(ti, ett_pcep_obj);
if (length != 20) {
proto_tree_add_text(pcep_subobj_pksv6, tvb, offset, length,
"Bad path key subobject: length %u != 20", length);
return;
}
path_key = tvb_get_ntohs(tvb, offset+2);
proto_item_append_text(ti, ": %s, Path Key %u", tvb_ip6_to_str(tvb, offset+4), path_key);
l = (l_and_or_type& Mask_L)>>7;
proto_tree_add_text(pcep_subobj_pksv6, tvb, offset, 1, "%s", val_to_str(l, pcep_route_l_obj_vals, "Unknown Object (%u). "));
proto_tree_add_uint(pcep_subobj_pksv6, pcep_filter[PCEPF_SUBOBJ], tvb, offset, 1, (l_and_or_type & 0x7f));
proto_tree_add_text(pcep_subobj_pksv6, tvb, offset+1, 1, "Length: %u", length);
proto_tree_add_text(pcep_subobj_pksv6, tvb, offset+2, 2, "Path Key: %d (0x%04x)", path_key, path_key);
proto_tree_add_text(pcep_subobj_pksv6, tvb, offset+4, 4, "PCE ID: %s", tvb_ip6_to_str(tvb, offset+4));
}
static void
dissect_pcep_open_obj (proto_tree *pcep_object_tree, tvbuff_t *tvb, int offset2, int obj_length)
{
proto_tree *pcep_open_obj_flags;
proto_item *ti;
guint8 version_flags;
guint8 keepalive;
guint8 deadtimer;
guint8 SID;
if (obj_length < OBJ_HDR_LEN+OPEN_OBJ_MIN_LEN) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length,
"Bad OPEN object length %u, should be >= %u", obj_length,
OBJ_HDR_LEN+OPEN_OBJ_MIN_LEN);
return;
}
version_flags = tvb_get_guint8(tvb, offset2);
proto_tree_add_text(pcep_object_tree, tvb, offset2, 1, "PCEP Version: %u", (version_flags & 0xe0)>>5);
ti = proto_tree_add_text(pcep_object_tree, tvb, offset2, 1, "Flags: 0x%02x", version_flags & 0x1f);
pcep_open_obj_flags = proto_item_add_subtree(ti, ett_pcep_obj_open);
proto_tree_add_boolean(pcep_open_obj_flags, pcep_open_flags_res, tvb, offset2, 1, version_flags & 0x1f);
keepalive = tvb_get_guint8(tvb, offset2+1);
proto_tree_add_text(pcep_object_tree, tvb, offset2+1, 1, "Keepalive: %u", keepalive);
deadtimer = tvb_get_guint8(tvb, offset2+2);
proto_tree_add_text(pcep_object_tree, tvb, offset2+2, 1, "Deadtime: %u", deadtimer);
SID = tvb_get_guint8(tvb, offset2+3);
proto_tree_add_text(pcep_object_tree, tvb, offset2+3, 1, "SID: %u", SID);
offset2 += OPEN_OBJ_MIN_LEN;
obj_length -= OBJ_HDR_LEN+OPEN_OBJ_MIN_LEN;
dissect_pcep_tlvs(pcep_object_tree, tvb, offset2, obj_length, ett_pcep_obj_open);
}
static void
dissect_pcep_rp_obj(proto_tree *pcep_object_tree,
tvbuff_t *tvb, int offset2, int obj_length)
{
proto_tree *pcep_rp_obj_flags;
proto_item *ti;
guint8 reserved;
guint32 flags;
guint32 requested_id_number;
if (obj_length < OBJ_HDR_LEN+RP_OBJ_MIN_LEN) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length,
"Bad RP object length %u, should be >= %u", obj_length,
OBJ_HDR_LEN+RP_OBJ_MIN_LEN);
return;
}
reserved = tvb_get_guint8(tvb, offset2);
proto_tree_add_text(pcep_object_tree, tvb, offset2, 1, "Reserved: 0x%02x", reserved);
flags = tvb_get_ntoh24(tvb, offset2+1);
ti = proto_tree_add_text(pcep_object_tree, tvb, offset2+1, 3, "Flags: 0x%06x ", flags);
pcep_rp_obj_flags = proto_item_add_subtree(ti, ett_pcep_obj_request_parameters);
proto_tree_add_boolean(pcep_rp_obj_flags, pcep_rp_flags_reserved, tvb, offset2+1, 3, flags);
proto_tree_add_boolean(pcep_rp_obj_flags, pcep_rp_flags_f, tvb, offset2+1, 3, flags);
proto_tree_add_boolean(pcep_rp_obj_flags, pcep_rp_flags_n, tvb, offset2+1, 3, flags);
proto_tree_add_boolean(pcep_rp_obj_flags, pcep_rp_flags_e, tvb, offset2+1, 3, flags);
proto_tree_add_boolean(pcep_rp_obj_flags, pcep_rp_flags_m, tvb, offset2+1, 3, flags);
proto_tree_add_boolean(pcep_rp_obj_flags, pcep_rp_flags_d, tvb, offset2+1, 3, flags);
proto_tree_add_boolean(pcep_rp_obj_flags, pcep_rp_flags_p, tvb, offset2+1, 3, flags);
proto_tree_add_boolean(pcep_rp_obj_flags, pcep_rp_flags_s, tvb, offset2+1, 3, flags);
proto_tree_add_boolean(pcep_rp_obj_flags, pcep_rp_flags_v, tvb, offset2+1, 3, flags);
proto_tree_add_boolean(pcep_rp_obj_flags, pcep_rp_flags_o, tvb, offset2+1, 3, flags);
proto_tree_add_boolean(pcep_rp_obj_flags, pcep_rp_flags_b, tvb, offset2+1, 3, flags);
proto_tree_add_boolean(pcep_rp_obj_flags, pcep_rp_flags_r, tvb, offset2+1, 3, flags);
proto_tree_add_boolean(pcep_rp_obj_flags, pcep_rp_flags_pri, tvb, offset2+1, 3, flags);
requested_id_number = tvb_get_ntohl(tvb, offset2+4);
proto_tree_add_text(pcep_object_tree, tvb, offset2+4, 4, "Requested ID Number: 0x%08x", requested_id_number);
offset2 += RP_OBJ_MIN_LEN;
obj_length -= OBJ_HDR_LEN+RP_OBJ_MIN_LEN;
dissect_pcep_tlvs(pcep_object_tree, tvb, offset2, obj_length, ett_pcep_obj_request_parameters);
}
static void
dissect_pcep_no_path_obj(proto_tree *pcep_object_tree,
tvbuff_t *tvb, int offset2, int obj_length)
{
proto_tree *pcep_no_path_obj_flags;
proto_item *ti;
guint8 ni;
guint16 flags;
guint8 reserved;
if (obj_length < OBJ_HDR_LEN+NO_PATH_OBJ_MIN_LEN) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length,
"Bad NO-PATH object length %u, should be >= %u", obj_length,
OBJ_HDR_LEN+NO_PATH_OBJ_MIN_LEN);
return;
}
ni = tvb_get_guint8(tvb, offset2);
proto_tree_add_text(pcep_object_tree, tvb, offset2, 1, "%s", val_to_str(ni, pcep_no_path_obj_vals, "Unknown Object (%u). "));
flags = tvb_get_ntohs(tvb, offset2+1);
ti = proto_tree_add_text(pcep_object_tree, tvb, offset2+1, 2, "Flags: 0x%04x", flags);
pcep_no_path_obj_flags = proto_item_add_subtree(ti, ett_pcep_obj_no_path);
proto_tree_add_boolean(pcep_no_path_obj_flags, pcep_no_path_flags_c, tvb, offset2+1, 2, flags);
reserved = tvb_get_guint8(tvb, offset2+3);
proto_tree_add_text(pcep_object_tree, tvb, offset2+3, 1, "Reserved: 0x%02x", reserved);
offset2 += NO_PATH_OBJ_MIN_LEN;
obj_length -= OBJ_HDR_LEN+NO_PATH_OBJ_MIN_LEN;
dissect_pcep_tlvs(pcep_object_tree, tvb, offset2, obj_length, ett_pcep_obj_no_path);
}
static void
dissect_pcep_end_point_obj(proto_tree *pcep_object_tree,
tvbuff_t *tvb, int offset2, int obj_length, int type)
{
switch(type)
{
case IPv4:
if (obj_length != OBJ_HDR_LEN+END_POINT_IPV4_OBJ_LEN) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length,
"Bad IPv4 END-POINTS object length %u, should be %u", obj_length,
OBJ_HDR_LEN+END_POINT_IPV4_OBJ_LEN);
return;
}
proto_tree_add_text(pcep_object_tree, tvb, offset2, 4, "Source IPv4 Address: %s", tvb_ip_to_str(tvb, offset2));
proto_tree_add_text(pcep_object_tree, tvb, offset2+4, 4, "Destination IPv4 Address: %s", tvb_ip_to_str(tvb, offset2+4));
break;
case IPv6:
if (obj_length != OBJ_HDR_LEN+END_POINT_IPV6_OBJ_LEN) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length,
"Bad IPv6 END-POINTS object length %u, should be %u", obj_length,
OBJ_HDR_LEN+END_POINT_IPV6_OBJ_LEN);
return;
}
proto_tree_add_text(pcep_object_tree, tvb, offset2, 16, "Source IPv6 Address: %s",
tvb_ip6_to_str(tvb, offset2));
proto_tree_add_text(pcep_object_tree, tvb, offset2+16, 16, "Destination IPv6 Address: %s",
tvb_ip6_to_str(tvb, offset2+16));
break;
default:
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length-OBJ_HDR_LEN, "UNKNOWN Type Object (%u)", type);
break;
}
}
static void
dissect_pcep_bandwidth_obj(proto_tree *pcep_object_tree, tvbuff_t *tvb, int offset2, int obj_length)
{
gfloat bandwidth;
if (obj_length != OBJ_HDR_LEN+BANDWIDTH_OBJ_LEN) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length,
"Bad BANDWIDTH object length %u, should be %u", obj_length,
OBJ_HDR_LEN+BANDWIDTH_OBJ_LEN);
return;
}
bandwidth = tvb_get_ntohieee_float(tvb, offset2);
proto_tree_add_text(pcep_object_tree, tvb, offset2, 4, "Bandwidth: %f", bandwidth);
}
static void
dissect_pcep_metric_obj(proto_tree *pcep_object_tree,
tvbuff_t *tvb, int offset2, int obj_length)
{
proto_tree *pcep_metric_obj_flags;
proto_item *ti;
guint16 reserved;
guint8 flags;
guint8 metric_type;
gfloat metric_value;
if (obj_length != OBJ_HDR_LEN+METRIC_OBJ_LEN) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length,
"Bad METRIC object length %u, should be %u", obj_length,
OBJ_HDR_LEN+METRIC_OBJ_LEN);
return;
}
reserved = tvb_get_ntohs(tvb, offset2);
proto_tree_add_text(pcep_object_tree, tvb, offset2, 2, "Reserved: %u", reserved);
flags = tvb_get_guint8(tvb, offset2+2);
ti = proto_tree_add_text(pcep_object_tree, tvb, offset2+2, 1, "Flags: 0x%02x", flags);
pcep_metric_obj_flags = proto_item_add_subtree(ti, ett_pcep_obj_metric);
proto_tree_add_boolean(pcep_metric_obj_flags, pcep_metric_flags_c, tvb, offset2+2, 1, flags);
proto_tree_add_boolean(pcep_metric_obj_flags, pcep_metric_flags_b, tvb, offset2+2, 1, flags);
metric_type = tvb_get_guint8(tvb, offset2+3);
proto_tree_add_text(pcep_object_tree, tvb, offset2+3, 1, "Type: %s (T=%u)", val_to_str(metric_type, pcep_metric_obj_vals, "Unknown"), metric_type);
metric_value = tvb_get_ntohieee_float(tvb, offset2+4);
proto_tree_add_text(pcep_object_tree, tvb, offset2+4, 4, "Metric Value: %f", metric_value);
}
static void
dissect_pcep_explicit_route_obj(proto_tree *pcep_object_tree,
tvbuff_t *tvb, int offset2, int obj_length, int obj_class)
{
guint8 l_type;
guint8 length;
guint type_exp_route;
guint body_obj_len;
body_obj_len = obj_length - OBJ_HDR_LEN;
while(body_obj_len){
if (body_obj_len < 2) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, 0,
"Bad ERO object: subobject goes past end of object");
break;
}
l_type = tvb_get_guint8(tvb, offset2);
length = tvb_get_guint8(tvb, offset2+1);
if (length < 2) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, 0,
"Bad ERO object: subobject length %u < 2",
length);
break;
}
type_exp_route = (l_type & Mask_Type);
if (body_obj_len <length) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, length,
"Bad ERO object: subobject length %u > remaining length %u",
length, body_obj_len);
break;
}
switch(type_exp_route) {
case PCEP_SUB_IPv4:
dissect_subobj_ipv4(pcep_object_tree, tvb, offset2, obj_class, ett_pcep_obj_explicit_route, l_type, length);
break;
case PCEP_SUB_IPv6:
dissect_subobj_ipv6(pcep_object_tree, tvb, offset2, obj_class, ett_pcep_obj_explicit_route, l_type, length);
break;
case PCEP_SUB_LABEL_CONTROL:
dissect_subobj_label_control(pcep_object_tree, tvb, offset2, obj_class, ett_pcep_obj_explicit_route, l_type, length);
break;
case PCEP_SUB_UNNUMB_INTERFACE_ID:
dissect_subobj_unnumb_interfaceID(pcep_object_tree, tvb, offset2, obj_class, ett_pcep_obj_explicit_route, l_type, length);
break;
case PCEP_SUB_AUTONOMOUS_SYS_NUM:
dissect_subobj_autonomous_sys_num(pcep_object_tree, tvb, offset2, obj_class, ett_pcep_obj_explicit_route, l_type, length);
break;
case PCEP_SUB_PKSv4:
dissect_subobj_pksv4(pcep_object_tree, tvb, offset2, ett_pcep_obj_explicit_route, l_type, length);
break;
default:
proto_tree_add_text(pcep_object_tree, tvb, offset2, length, "Non defined subobject (%d)", type_exp_route);
break;
}
offset2 += length;
body_obj_len -= length;
}
}
static void
dissect_pcep_record_route_obj(proto_tree *pcep_object_tree, tvbuff_t *tvb, int offset2, int obj_length, int obj_class)
{
guint8 type;
guint8 length;
guint body_obj_len;
body_obj_len = obj_length - OBJ_HDR_LEN;
while(body_obj_len){
if (body_obj_len < 2) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, 0,
"Bad RRO object: subobject goes past end of object");
break;
}
type = tvb_get_guint8(tvb, offset2);
length = tvb_get_guint8(tvb, offset2+1);
if (length < 2) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, 0,
"Bad RRO object: subobject length %u < 2",
length);
break;
}
if (body_obj_len <length) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, length,
"Bad RRO subobject: subobject length %u > remaining length %u",
length, body_obj_len);
break;
}
switch(type) {
case PCEP_SUB_IPv4:
dissect_subobj_ipv4(pcep_object_tree, tvb, offset2, obj_class, ett_pcep_obj_record_route, type, length);
break;
case PCEP_SUB_IPv6:
dissect_subobj_ipv6(pcep_object_tree, tvb, offset2, obj_class, ett_pcep_obj_record_route, type, length);
break;
case PCEP_SUB_LABEL_CONTROL:
dissect_subobj_label_control(pcep_object_tree, tvb, offset2, obj_class, ett_pcep_obj_record_route, type, length);
break;
case PCEP_SUB_UNNUMB_INTERFACE_ID:
dissect_subobj_unnumb_interfaceID(pcep_object_tree, tvb, offset2, obj_class, ett_pcep_obj_record_route, type, length);
break;
default:
proto_tree_add_text(pcep_object_tree, tvb, offset2, length, "Non defined subobject (%d)", type);
break;
}
offset2 += length;
body_obj_len -= length;
}
}
static void
dissect_pcep_lspa_obj(proto_tree *pcep_object_tree, tvbuff_t *tvb, int offset2, int obj_length)
{
proto_tree *pcep_lspa_obj_flags;
proto_item *ti;
guint32 exclude_any;
guint32 include_any;
guint32 include_all;
guint8 setup_prio;
guint8 holding_prio;
guint8 flags;
guint8 reserved;
if (obj_length < OBJ_HDR_LEN+LSPA_OBJ_MIN_LEN) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length,
"Bad LSPA object length %u, should be >= %u", obj_length,
OBJ_HDR_LEN+LSPA_OBJ_MIN_LEN);
return;
}
exclude_any = tvb_get_ntohl(tvb, offset2);
proto_tree_add_text(pcep_object_tree, tvb, offset2, 4, "Exclude-Any: 0x%08x", exclude_any);
include_any = tvb_get_ntohl(tvb, offset2+4);
proto_tree_add_text(pcep_object_tree, tvb, offset2+4, 4, "Include-Any: 0x%08x", include_any);
include_all = tvb_get_ntohl(tvb, offset2+8);
proto_tree_add_text(pcep_object_tree, tvb, offset2+8, 4, "Include-All: 0x%08x", include_all);
setup_prio = tvb_get_guint8(tvb, offset2+12);
proto_tree_add_text(pcep_object_tree, tvb, offset2+12, 1, "Setup Priority: %u", setup_prio);
holding_prio = tvb_get_guint8(tvb, offset2+13);
proto_tree_add_text(pcep_object_tree, tvb, offset2+13, 1, "Holding Priority: %u", holding_prio);
flags = tvb_get_guint8(tvb, offset2+14);
ti = proto_tree_add_text(pcep_object_tree, tvb, offset2+14, 1, "Flags: 0x%02x", flags);
pcep_lspa_obj_flags = proto_item_add_subtree(ti, ett_pcep_obj_metric);
proto_tree_add_boolean(pcep_lspa_obj_flags, pcep_lspa_flags_l, tvb, offset2+14, 1, flags);
reserved = tvb_get_guint8(tvb, offset2+15);
proto_tree_add_text(pcep_object_tree, tvb, offset2+15, 1, "Reserved: 0x%02x", reserved);
offset2 += LSPA_OBJ_MIN_LEN;
obj_length -= OBJ_HDR_LEN+LSPA_OBJ_MIN_LEN;
dissect_pcep_tlvs(pcep_object_tree, tvb, offset2, obj_length, ett_pcep_obj_lspa);
}
static void
dissect_pcep_iro_obj(proto_tree *pcep_object_tree,
tvbuff_t *tvb, int offset2, int obj_length, int obj_class)
{
guint8 l_type;
guint8 length;
int type_iro;
guint body_obj_len;
body_obj_len = obj_length - OBJ_HDR_LEN;
while(body_obj_len){
if (body_obj_len < 2) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, 0,
"Bad IRO object: subobject goes past end of object");
break;
}
l_type = tvb_get_guint8(tvb, offset2);
length = tvb_get_guint8(tvb, offset2+1);
if (length < 2) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, 0,
"Bad IRO object: subobject length %u < 2",
length);
break;
}
type_iro = (l_type & Mask_Type);
if (body_obj_len <length) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, length,
"Bad IRO object: subobject length %u > remaining length %u",
length, body_obj_len);
break;
}
switch(type_iro) {
case PCEP_SUB_IPv4:
dissect_subobj_ipv4(pcep_object_tree, tvb, offset2, obj_class, ett_pcep_obj_iro, l_type, length);
break;
case PCEP_SUB_IPv6:
dissect_subobj_ipv6(pcep_object_tree, tvb, offset2, obj_class, ett_pcep_obj_iro, l_type, length);
break;
case PCEP_SUB_UNNUMB_INTERFACE_ID:
dissect_subobj_unnumb_interfaceID(pcep_object_tree, tvb, offset2, obj_class, ett_pcep_obj_iro, l_type, length);
break;
case PCEP_SUB_AUTONOMOUS_SYS_NUM:
dissect_subobj_autonomous_sys_num(pcep_object_tree, tvb, offset2, obj_class, ett_pcep_obj_iro, l_type, length);
break;
case PCEP_SUB_EXRS:
dissect_subobj_exrs(pcep_object_tree, tvb, offset2, obj_class, ett_pcep_obj_iro, type_iro, l_type, length);
break;
default:
proto_tree_add_text(pcep_object_tree, tvb, offset2, length, "Non defined subobject (%d)", type_iro);
break;
}
offset2 += length;
body_obj_len -= length;
}
}
static void
dissect_pcep_svec_obj(proto_tree *pcep_object_tree,
tvbuff_t *tvb, int offset2, int obj_length)
{
proto_item *ti;
proto_tree *pcep_svec_flags_obj;
guint8 reserved;
guint32 flags;
int m = 1;
int i = 0;
if (obj_length < OBJ_HDR_LEN+SVEC_OBJ_MIN_LEN) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length,
"Bad SVEC object length %u, should be >= %u", obj_length,
OBJ_HDR_LEN+SVEC_OBJ_MIN_LEN);
return;
}
reserved = tvb_get_guint8(tvb, offset2);
proto_tree_add_text(pcep_object_tree, tvb, offset2, 1, "Reserved: 0x%02x", reserved);
flags = tvb_get_ntoh24(tvb, offset2+1);
ti = proto_tree_add_text(pcep_object_tree, tvb, offset2+1, 3, "Flags: 0x%06x", flags);
pcep_svec_flags_obj = proto_item_add_subtree(ti, ett_pcep_obj_svec);
proto_tree_add_boolean(pcep_svec_flags_obj, pcep_svec_flags_l, tvb, offset2 + 1, 3, flags);
proto_tree_add_boolean(pcep_svec_flags_obj, pcep_svec_flags_n, tvb, offset2 + 1, 3, flags);
proto_tree_add_boolean(pcep_svec_flags_obj, pcep_svec_flags_s, tvb, offset2 + 1, 3, flags);
for ( i=4 ; i<(obj_length-OBJ_HDR_LEN) ; ){
proto_tree_add_text(pcep_object_tree, tvb, offset2+i, 4, "Request-ID-Number %u: 0x%s", m,
tvb_bytes_to_str_punct(tvb, offset2+i, 4, ' '));
i += 4;
}
}
static void
dissect_pcep_notification_obj(proto_tree *pcep_object_tree, tvbuff_t *tvb, int offset2, int obj_length)
{
guint8 reserved;
guint8 flags;
guint8 nt;
guint8 nv;
if (obj_length < OBJ_HDR_LEN+NOTIFICATION_OBJ_MIN_LEN) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length,
"Bad NOTIFICATION object length %u, should be >= %u", obj_length,
OBJ_HDR_LEN+NOTIFICATION_OBJ_MIN_LEN);
return;
}
reserved = tvb_get_guint8(tvb, offset2);
proto_tree_add_text(pcep_object_tree, tvb, offset2, 1, "Reserved: 0x%02x", reserved);
flags = tvb_get_guint8(tvb, offset2+1);
proto_tree_add_text(pcep_object_tree, tvb, offset2+1, 1, "Flags: 0x%02x", flags);
nt = tvb_get_guint8(tvb, offset2+2);
proto_tree_add_uint(pcep_object_tree, pcep_filter[PCEPF_NOTI_TYPE], tvb, offset2+2, 1, nt);
switch(nt){
case 1:
proto_tree_add_uint(pcep_object_tree, pcep_filter[PCEPF_NOTI_VAL1], tvb, offset2+2, 1, nt);
break;
case 2:
proto_tree_add_uint(pcep_object_tree, pcep_filter[PCEPF_NOTI_VAL2], tvb, offset2+2, 1, nt);
break;
default:
proto_tree_add_text(pcep_object_tree, tvb, offset2+2, 1, "Notification Type: %u", nt);
break;
}
nv = tvb_get_guint8(tvb, offset2+3);
proto_tree_add_text(pcep_object_tree, tvb, offset2+3, 1, "Notification Value: 0x%02x", nv);
offset2 += NOTIFICATION_OBJ_MIN_LEN;
obj_length -= OBJ_HDR_LEN+NOTIFICATION_OBJ_MIN_LEN;
dissect_pcep_tlvs(pcep_object_tree, tvb, offset2, obj_length, ett_pcep_obj_notification);
}
static void
dissect_pcep_error_obj(proto_tree *pcep_object_tree, tvbuff_t *tvb, int offset2, int obj_length)
{
guint8 reserved;
guint8 flags;
guint8 error_type;
guint8 error_value;
const gchar *err_str;
const gchar *default_str = "Unassigned";
if (obj_length < OBJ_HDR_LEN+ERROR_OBJ_MIN_LEN) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length,
"Bad ERROR object length %u, should be >= %u", obj_length,
OBJ_HDR_LEN+ERROR_OBJ_MIN_LEN);
return;
}
reserved = tvb_get_guint8(tvb, offset2);
proto_tree_add_text(pcep_object_tree, tvb, offset2, 1, "Reserved: 0x%02x", reserved);
flags = tvb_get_guint8(tvb, offset2+1);
proto_tree_add_text(pcep_object_tree, tvb, offset2+1, 1, "Flags: 0x%02x", flags);
error_type = tvb_get_guint8(tvb, offset2+2);
error_value = tvb_get_guint8(tvb, offset2+3);
proto_tree_add_uint(pcep_object_tree, pcep_filter[PCEPF_ERROR_TYPE], tvb, offset2+2, 1, error_type);
err_str = default_str;
switch (error_type){
case ESTABLISH_FAILURE:
err_str = val_to_str(error_value, pcep_error_value_1_vals, "Unknown");
break;
case CAP_NOT_SUPPORTED:
break;
case UNKNOWN_OBJ:
err_str = val_to_str(error_value, pcep_error_value_3_vals, "Unknown");
break;
case NOT_SUPP_OBJ:
err_str = val_to_str(error_value, pcep_error_value_4_vals, "Unknown");
break;
case POLICY_VIOLATION:
err_str = val_to_str(error_value, pcep_error_value_5_vals, "Unknown");
break;
case MANDATORY_OBJ_MIS:
err_str = val_to_str(error_value, pcep_error_value_6_vals, "Unknown");
break;
case SYNCH_PCREQ_MIS:
break;
case UNKNOWN_REQ_REF:
break;
case ATTEMPT_2_SESSION:
break;
case INVALID_OBJ:
err_str = val_to_str(error_value, pcep_error_value_10_vals, "Unknown");
break;
case UNRECO_EXRS_SUBOBJ:
break;
case DIFFSERV_TE_ERROR:
err_str = val_to_str(error_value, pcep_error_value_12_vals, "Unknown");
break;
case BRPC_FAILURE:
err_str = val_to_str(error_value, pcep_error_value_13_vals, "Unknown");
break;
case GCO_ERROR:
err_str = val_to_str(error_value, pcep_error_value_15_vals, "Unknown");
break;
case P2MP_CAPABILITY_ERROR:
err_str = val_to_str(error_value, pcep_error_value_16_vals, "Unknown");
break;
case P2MP_END_POINTS_ERROR:
err_str = val_to_str(error_value, pcep_error_value_17_vals, "Unknown");
break;
case P2MP_FRAGMENT_ERROR:
err_str = val_to_str(error_value, pcep_error_value_18_vals, "Unknown");
break;
default:
proto_tree_add_text(pcep_object_tree, tvb, offset2+2, 1, "Error-Type: %u Non defined Error-Value", error_type);
}
proto_tree_add_text(pcep_object_tree, tvb, offset2+3, 1, "Error-Value: %s (%u)", err_str, error_value);
offset2 += ERROR_OBJ_MIN_LEN;
obj_length -= OBJ_HDR_LEN+ERROR_OBJ_MIN_LEN;
dissect_pcep_tlvs(pcep_object_tree, tvb, offset2, obj_length, ett_pcep_obj_error);
}
static void
dissect_pcep_balancing_obj(proto_tree *pcep_object_tree, tvbuff_t *tvb, int offset2, int obj_length)
{
guint16 reserved;
guint8 flags;
guint8 max_LSP;
guint32 min_bandwidth;
if (obj_length != OBJ_HDR_LEN+LOAD_BALANCING_OBJ_LEN) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length,
"Bad LOAD-BALANCING object length %u, should be %u", obj_length,
OBJ_HDR_LEN+LOAD_BALANCING_OBJ_LEN);
return;
}
reserved = tvb_get_ntohs(tvb, offset2);
proto_tree_add_text(pcep_object_tree, tvb, offset2, 2, "Reserved: 0x%04x", reserved);
flags = tvb_get_guint8(tvb, offset2+2);
proto_tree_add_text(pcep_object_tree, tvb, offset2+2, 1, "Flags: 0x%02x", flags);
max_LSP = tvb_get_guint8(tvb, offset2+3);
proto_tree_add_text(pcep_object_tree, tvb, offset2+3, 1, "Maximum Number of TE LSPs: 0x%02x", max_LSP);
min_bandwidth = tvb_get_ntohl(tvb, offset2+4);
proto_tree_add_text(pcep_object_tree, tvb, offset2+4, 4, "Minimum Bandwidth: 0x%08x", min_bandwidth);
}
static void
dissect_pcep_close_obj(proto_tree *pcep_object_tree, tvbuff_t *tvb, int offset2, int obj_length)
{
guint16 reserved;
guint8 flags;
guint8 reason;
if (obj_length < OBJ_HDR_LEN+CLOSE_OBJ_MIN_LEN) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length,
"Bad CLOSE object length %u, should be >= %u", obj_length,
OBJ_HDR_LEN+CLOSE_OBJ_MIN_LEN);
return;
}
reserved = tvb_get_ntohs(tvb, offset2);
proto_tree_add_text(pcep_object_tree, tvb, offset2, 2, "Reserved: 0x%04x", reserved);
flags = tvb_get_guint8(tvb, offset2+2);
proto_tree_add_text(pcep_object_tree, tvb, offset2+2, 1, "Flags: 0x%02x", flags);
reason = tvb_get_guint8(tvb, offset2+3);
proto_tree_add_text(pcep_object_tree, tvb, offset2+3, 1, "Reason: %s (%u)", val_to_str(reason, pcep_close_reason_obj_vals, "Unknown"), reason);
offset2 += CLOSE_OBJ_MIN_LEN;
obj_length -= OBJ_HDR_LEN+CLOSE_OBJ_MIN_LEN;
dissect_pcep_tlvs(pcep_object_tree, tvb, offset2, obj_length, ett_pcep_obj_load_balancing);
}
static void
dissect_pcep_path_key_obj(proto_tree *pcep_object_tree,
tvbuff_t *tvb, int offset2, int obj_length)
{
guint8 l_type;
guint8 length;
guint type_exp_route;
guint body_obj_len;
body_obj_len = obj_length - OBJ_HDR_LEN;
while(body_obj_len){
if (body_obj_len < 2) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, 0,
"Bad PATH-KEY object: subobject goes past end of object");
break;
}
l_type = tvb_get_guint8(tvb, offset2);
length = tvb_get_guint8(tvb, offset2+1);
if (length < 2) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, 0,
"Bad PATH-KEY object: subobject length %u < 2",
length);
break;
}
type_exp_route = (l_type & Mask_Type);
if (body_obj_len <length) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, length,
"Bad PATH-KEY object: subobject length %u > remaining length %u",
length, body_obj_len);
break;
}
switch(type_exp_route) {
case PCEP_SUB_PKSv4:
dissect_subobj_pksv4(pcep_object_tree, tvb, offset2, ett_pcep_obj_explicit_route, l_type, length);
break;
default:
proto_tree_add_text(pcep_object_tree, tvb, offset2, length, "Non defined subobject (%d)", type_exp_route);
break;
}
offset2 += length;
body_obj_len -= length;
}
}
static void
dissect_pcep_xro_obj(proto_tree *pcep_object_tree, tvbuff_t *tvb, int offset2, int obj_length, int obj_class)
{
proto_tree *pcep_xro_flags_obj;
proto_item *ti;
guint16 reserved;
guint16 flags;
guint8 x_type;
guint8 length;
guint type_xro;
guint body_obj_len;
body_obj_len = obj_length - OBJ_HDR_LEN;
if (obj_length < OBJ_HDR_LEN+XRO_OBJ_MIN_LEN) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length,
"Bad XRO object length %u, should be >= %u", obj_length,
OBJ_HDR_LEN+XRO_OBJ_MIN_LEN);
return;
}
reserved = tvb_get_ntohs(tvb, offset2);
proto_tree_add_text(pcep_object_tree, tvb, offset2, 2, "Reserved: 0x%04x", reserved);
flags = tvb_get_ntohs(tvb, offset2+2);
ti = proto_tree_add_text(pcep_object_tree, tvb, offset2+2, 2, "Flags: 0x%04x ", flags);
pcep_xro_flags_obj = proto_item_add_subtree(ti, ett_pcep_obj_xro);
proto_tree_add_boolean(pcep_xro_flags_obj, pcep_xro_flags_f, tvb, offset2 + 2, 2, flags);
offset2 += XRO_OBJ_MIN_LEN;
body_obj_len -= XRO_OBJ_MIN_LEN;
while(body_obj_len >= 2){
if (body_obj_len < 2) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, 0,
"Bad XRO object: subobject goes past end of object");
break;
}
x_type = tvb_get_guint8(tvb, offset2);
length = tvb_get_guint8(tvb, offset2+1);
if (length < 2) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, 0,
"Bad XRO object: object length %u < 2", length);
break;
}
type_xro = (x_type & Mask_Type);
if (body_obj_len <length) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, length,
"Bad XRO object: object length %u > remaining length %u",
length, body_obj_len);
break;
}
switch(type_xro) {
case PCEP_SUB_IPv4:
dissect_subobj_ipv4(pcep_object_tree, tvb, offset2, obj_class, ett_pcep_obj_xro, x_type, length);
break;
case PCEP_SUB_IPv6:
dissect_subobj_ipv6(pcep_object_tree, tvb, offset2, obj_class, ett_pcep_obj_xro, x_type, length);
break;
case PCEP_SUB_UNNUMB_INTERFACE_ID:
dissect_subobj_unnumb_interfaceID(pcep_object_tree, tvb, offset2, obj_class, ett_pcep_obj_xro, x_type, length);
break;
case PCEP_SUB_AUTONOMOUS_SYS_NUM:
dissect_subobj_autonomous_sys_num(pcep_object_tree, tvb, offset2, obj_class, ett_pcep_obj_xro, x_type, length);
break;
case PCEP_SUB_SRLG:
dissect_subobj_srlg(pcep_object_tree, tvb, offset2, ett_pcep_obj_xro, x_type, length);
break;
case PCEP_SUB_PKSv4:
dissect_subobj_pksv4(pcep_object_tree, tvb, offset2, ett_pcep_obj_xro, x_type, length);
break;
case PCEP_SUB_PKSv6:
dissect_subobj_pksv6(pcep_object_tree, tvb, offset2, ett_pcep_obj_xro, x_type, length);
break;
default:
proto_tree_add_text(pcep_object_tree, tvb, offset2-4, length, "Non defined subobject (%d)", type_xro);
break;
}
offset2 += length;
body_obj_len -= length;
}
}
static void
dissect_pcep_obj_monitoring(proto_tree *pcep_object_tree, tvbuff_t *tvb, int offset2, int obj_length)
{
proto_item *ti;
proto_tree *monitoring_flags;
if (obj_length < OBJ_HDR_LEN + OBJ_MONITORING_MIN_LEN) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length,
"Bad MONITORING object length %u, should be >= %u", obj_length,
OBJ_HDR_LEN + OBJ_MONITORING_MIN_LEN);
return;
}
proto_tree_add_text(pcep_object_tree, tvb, offset2, 1, "Reserved: 0x%02x", tvb_get_guint8(tvb, offset2));
ti = proto_tree_add_text(pcep_object_tree, tvb, offset2+1, 3, "Flags: 0x%06x", tvb_get_ntoh24(tvb, offset2+1));
monitoring_flags = proto_item_add_subtree(ti, ett_pcep_obj_monitoring);
proto_tree_add_item(monitoring_flags, pcep_obj_monitoring_flags_reserved, tvb, offset2 + 1, 3, ENC_NA);
proto_tree_add_item(monitoring_flags, pcep_obj_monitoring_flags_i, tvb, offset2 + 1, 3, ENC_NA);
proto_tree_add_item(monitoring_flags, pcep_obj_monitoring_flags_c, tvb, offset2 + 1, 3, ENC_NA);
proto_tree_add_item(monitoring_flags, pcep_obj_monitoring_flags_p, tvb, offset2 + 1, 3, ENC_NA);
proto_tree_add_item(monitoring_flags, pcep_obj_monitoring_flags_g, tvb, offset2 + 1, 3, ENC_NA);
proto_tree_add_item(monitoring_flags, pcep_obj_monitoring_flags_l, tvb, offset2 + 1, 3, ENC_NA);
proto_tree_add_item(pcep_object_tree, pcep_obj_monitoring_monitoring_id_number, tvb, offset2 + 4, 4, ENC_NA);
offset2 += OBJ_MONITORING_MIN_LEN;
obj_length -= OBJ_HDR_LEN + OBJ_MONITORING_MIN_LEN;
dissect_pcep_tlvs(pcep_object_tree, tvb, offset2, obj_length, ett_pcep_obj_monitoring);
}
static void
dissect_pcep_obj_pcc_id_req(proto_tree *pcep_object_tree, tvbuff_t *tvb, int offset2, int obj_length, int type)
{
switch(type)
{
case PCEP_OBJ_PCC_ID_REQ_IPv4:
if (obj_length != OBJ_HDR_LEN + OBJ_PCC_ID_REQ_IPV4_LEN) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length,
"Bad IPv4 PCC-ID-REQ object length %u, should be %u", obj_length,
OBJ_HDR_LEN + OBJ_PCC_ID_REQ_IPV4_LEN);
return;
}
proto_tree_add_item(pcep_object_tree, pcep_obj_pcc_id_req_ipv4, tvb, offset2, 4, ENC_NA);
break;
case PCEP_OBJ_PCC_ID_REQ_IPv6:
if (obj_length != OBJ_HDR_LEN + OBJ_PCC_ID_REQ_IPV6_LEN) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length,
"Bad IPv6 PCC-ID-REQ object length %u, should be %u", obj_length,
OBJ_HDR_LEN + OBJ_PCC_ID_REQ_IPV6_LEN);
return;
}
proto_tree_add_item(pcep_object_tree, pcep_obj_pcc_id_req_ipv6, tvb, offset2, 16, ENC_NA);
break;
default:
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length - OBJ_HDR_LEN, "UNKNOWN Type Object (%u)", type);
break;
}
}
static void
dissect_pcep_of_obj(proto_tree *pcep_object_tree, tvbuff_t *tvb, int offset2, int obj_length)
{
guint16 of_code;
if (obj_length < OBJ_HDR_LEN+OF_OBJ_MIN_LEN) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length,
"Bad OF object length %u, should be >= %u", obj_length,
OBJ_HDR_LEN+OF_OBJ_MIN_LEN);
return;
}
of_code = tvb_get_ntohs(tvb, offset2);
proto_tree_add_text(pcep_object_tree, tvb, offset2, 2, "OF-Code: %s (%u)",
val_to_str(of_code, pcep_of_vals, "Unknown"), of_code);
offset2 += OPEN_OBJ_MIN_LEN;
obj_length -= OBJ_HDR_LEN+OF_OBJ_MIN_LEN;
dissect_pcep_tlvs(pcep_object_tree, tvb, offset2, obj_length, ett_pcep_obj_open);
}
static void
dissect_pcep_obj_pce_id(proto_tree *pcep_object_tree, tvbuff_t *tvb, int offset2, int obj_length, int type)
{
switch(type)
{
case PCEP_OBJ_PCE_ID_IPv4:
if (obj_length != OBJ_HDR_LEN + OBJ_PCE_ID_IPV4_LEN) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length,
"Bad IPv4 PCE-ID object length %u, should be %u", obj_length,
OBJ_HDR_LEN + OBJ_PCE_ID_IPV4_LEN);
return;
}
proto_tree_add_item(pcep_object_tree, pcep_obj_pce_id_ipv4, tvb, offset2, 4, ENC_NA);
break;
case PCEP_OBJ_PCE_ID_IPv6:
if (obj_length != OBJ_HDR_LEN + OBJ_PCE_ID_IPV6_LEN) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length,
"Bad IPv6 PCE-ID object length %u, should be %u", obj_length,
OBJ_HDR_LEN + OBJ_PCE_ID_IPV6_LEN);
return;
}
proto_tree_add_item(pcep_object_tree, pcep_obj_pce_id_ipv6, tvb, offset2, 16, ENC_NA);
break;
default:
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length - OBJ_HDR_LEN, "UNKNOWN Type Object (%u)", type);
break;
}
}
static void
dissect_pcep_obj_proc_time(proto_tree *pcep_object_tree, tvbuff_t *tvb, int offset2, int obj_length)
{
proto_item *ti;
proto_tree *proc_time_flags;
if (obj_length != OBJ_HDR_LEN + OBJ_PROC_TIME_LEN) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length,
"Bad PROC-TIME object length %u, should be %u", obj_length,
OBJ_HDR_LEN + OBJ_PROC_TIME_LEN);
return;
}
proto_tree_add_text(pcep_object_tree, tvb, offset2, 2, "Reserved: 0x%04x", tvb_get_ntohs(tvb, offset2));
ti = proto_tree_add_text(pcep_object_tree, tvb, offset2 + 2, 2, "Flags: 0x%04x ", tvb_get_ntohs(tvb, offset2 + 2));
proc_time_flags = proto_item_add_subtree(ti, ett_pcep_obj_proc_time);
proto_tree_add_item(proc_time_flags, pcep_obj_proc_time_flags_reserved, tvb, offset2 + 2, 2, ENC_NA);
proto_tree_add_item(proc_time_flags, pcep_obj_proc_time_flags_e, tvb, offset2 + 2, 2, ENC_NA);
proto_tree_add_item(pcep_object_tree, pcep_obj_proc_time_cur_proc_time, tvb, offset2 + 4, 4, ENC_NA);
proto_tree_add_item(pcep_object_tree, pcep_obj_proc_time_min_proc_time, tvb, offset2 + 8, 4, ENC_NA);
proto_tree_add_item(pcep_object_tree, pcep_obj_proc_time_max_proc_time, tvb, offset2 + 12, 4, ENC_NA);
proto_tree_add_item(pcep_object_tree, pcep_obj_proc_time_ave_proc_time, tvb, offset2 + 16, 4, ENC_NA);
proto_tree_add_item(pcep_object_tree, pcep_obj_proc_time_var_proc_time, tvb, offset2 + 20, 4, ENC_NA);
}
static void
dissect_pcep_obj_overload(proto_tree *pcep_object_tree, tvbuff_t *tvb, int offset2, int obj_length)
{
if (obj_length != OBJ_HDR_LEN + OBJ_OVERLOAD_LEN) {
proto_tree_add_text(pcep_object_tree, tvb, offset2, obj_length,
"Bad OVERLOAD object length %u, should be %u", obj_length,
OBJ_HDR_LEN + OBJ_OVERLOAD_LEN);
return;
}
proto_tree_add_text(pcep_object_tree, tvb, offset2, 1, "Flags: 0x%02x", tvb_get_guint8(tvb, offset2));
proto_tree_add_text(pcep_object_tree, tvb, offset2 + 1, 1, "Reserved: 0x%02x", tvb_get_guint8(tvb, offset2 + 1));
proto_tree_add_item(pcep_object_tree, pcep_obj_overload_duration, tvb, offset2 + 2, 2, ENC_NA);
}
static void
dissect_pcep_obj_tree(proto_tree *pcep_tree, tvbuff_t *tvb, int len, int offset, int msg_length)
{
guint8 obj_class;
guint8 ot_res_p_i;
guint16 obj_length;
int type;
proto_tree *pcep_object_tree;
proto_item *pcep_object_item;
proto_tree *pcep_header_obj_flags;
proto_item *ti;
while (len < msg_length) {
obj_class = tvb_get_guint8(tvb, offset);
switch (obj_class) {
case PCEP_OPEN_OBJ:
pcep_object_item = proto_tree_add_item(pcep_tree, pcep_filter[PCEPF_OBJ_OPEN], tvb, offset, -1, ENC_NA);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_open);
break;
case PCEP_RP_OBJ:
pcep_object_item = proto_tree_add_item(pcep_tree, pcep_filter[PCEPF_OBJ_RP], tvb, offset, -1, ENC_NA);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_request_parameters);
break;
case PCEP_NO_PATH_OBJ:
pcep_object_item = proto_tree_add_item(pcep_tree, pcep_filter[PCEPF_OBJ_NO_PATH], tvb, offset, -1, ENC_NA);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_no_path);
break;
case PCEP_END_POINT_OBJ:
pcep_object_item = proto_tree_add_item(pcep_tree, pcep_filter[PCEPF_OBJ_END_POINT], tvb, offset, -1, ENC_NA);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_end_point);
break;
case PCEP_BANDWIDTH_OBJ:
pcep_object_item = proto_tree_add_item(pcep_tree, pcep_filter[PCEPF_OBJ_BANDWIDTH], tvb, offset, -1, ENC_NA);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_bandwidth);
break;
case PCEP_METRIC_OBJ:
pcep_object_item = proto_tree_add_item(pcep_tree, pcep_filter[PCEPF_OBJ_METRIC], tvb, offset, -1, ENC_NA);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_metric);
break;
case PCEP_EXPLICIT_ROUTE_OBJ:
pcep_object_item = proto_tree_add_item(pcep_tree, pcep_filter[PCEPF_OBJ_EXPLICIT_ROUTE], tvb, offset, -1, ENC_NA);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_explicit_route);
break;
case PCEP_RECORD_ROUTE_OBJ:
pcep_object_item = proto_tree_add_item(pcep_tree, pcep_filter[PCEPF_OBJ_RECORD_ROUTE], tvb, offset, -1, ENC_NA);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_record_route);
break;
case PCEP_LSPA_OBJ:
pcep_object_item = proto_tree_add_item(pcep_tree, pcep_filter[PCEPF_OBJ_LSPA], tvb, offset, -1, ENC_NA);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_lspa);
break;
case PCEP_IRO_OBJ:
pcep_object_item = proto_tree_add_item(pcep_tree, pcep_filter[PCEPF_OBJ_IRO], tvb, offset, -1, ENC_NA);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_iro);
break;
case PCEP_SVEC_OBJ:
pcep_object_item = proto_tree_add_item(pcep_tree, pcep_filter[PCEPF_OBJ_SVEC], tvb, offset, -1, ENC_NA);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_svec);
break;
case PCEP_NOTIFICATION_OBJ:
pcep_object_item = proto_tree_add_item(pcep_tree, pcep_filter[PCEPF_OBJ_NOTIFICATION], tvb, offset, -1, ENC_NA);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_notification);
break;
case PCEP_PCEP_ERROR_OBJ:
pcep_object_item = proto_tree_add_item(pcep_tree, pcep_filter[PCEPF_OBJ_PCEP_ERROR], tvb, offset, -1, ENC_NA);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_error);
break;
case PCEP_LOAD_BALANCING_OBJ:
pcep_object_item = proto_tree_add_item(pcep_tree, pcep_filter[PCEPF_OBJ_LOAD_BALANCING], tvb, offset, -1, ENC_NA);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_load_balancing);
break;
case PCEP_CLOSE_OBJ:
pcep_object_item = proto_tree_add_item(pcep_tree, pcep_filter[PCEPF_OBJ_CLOSE], tvb, offset, -1, ENC_NA);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_close);
break;
case PCEP_PATH_KEY_OBJ:
pcep_object_item = proto_tree_add_item(pcep_tree, pcep_filter[PCEPF_OBJ_PATH_KEY], tvb, offset, -1, ENC_NA);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_path_key);
break;
case PCEP_XRO_OBJ:
pcep_object_item = proto_tree_add_item(pcep_tree, pcep_filter[PCEPF_OBJ_XRO], tvb, offset, -1, ENC_NA);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_xro);
break;
case PCEP_OBJ_MONITORING:
pcep_object_item = proto_tree_add_item(pcep_tree, pcep_filter[PCEPF_OBJ_MONITORING], tvb, offset, -1, ENC_NA);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_monitoring);
break;
case PCEP_OBJ_PCC_ID_REQ:
pcep_object_item = proto_tree_add_item(pcep_tree, pcep_filter[PCEPF_OBJ_PCC_ID_REQ], tvb, offset, -1, ENC_NA);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_pcc_id_req);
break;
case PCEP_OF_OBJ:
pcep_object_item = proto_tree_add_item(pcep_tree, pcep_filter[PCEPF_OBJ_OF], tvb, offset, -1, ENC_NA);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_of);
break;
case PCEP_OBJ_PCE_ID:
pcep_object_item = proto_tree_add_item(pcep_tree, pcep_filter[PCEPF_OBJ_PCE_ID], tvb, offset, -1, ENC_NA);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_pce_id);
break;
case PCEP_OBJ_PROC_TIME:
pcep_object_item = proto_tree_add_item(pcep_tree, pcep_filter[PCEPF_OBJ_PROC_TIME], tvb, offset, -1, ENC_NA);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_proc_time);
break;
case PCEP_OBJ_OVERLOAD:
pcep_object_item = proto_tree_add_item(pcep_tree, pcep_filter[PCEPF_OBJ_OVERLOAD], tvb, offset, -1, ENC_NA);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_overload);
break;
default:
pcep_object_item = proto_tree_add_text(pcep_tree, tvb, offset, -1, "Unknown object (%u)", obj_class);
pcep_object_tree = proto_item_add_subtree(pcep_object_item, ett_pcep_obj_unknown);
break;
}
proto_tree_add_uint(pcep_object_tree, pcep_filter[PCEPF_OBJECT_CLASS], tvb, offset, 1, obj_class);
ot_res_p_i = tvb_get_guint8(tvb, offset+1);
type = (ot_res_p_i & MASK_OBJ_TYPE)>>4;
proto_tree_add_text(pcep_object_tree, tvb, offset+1, 1, "Object Type: %u", type);
ti = proto_tree_add_text(pcep_object_tree, tvb, offset+1, 1, "Flags");
pcep_header_obj_flags = proto_item_add_subtree(ti, ett_pcep_hdr);
proto_tree_add_boolean(pcep_header_obj_flags, pcep_hdr_obj_flags_reserved, tvb, offset+1, 1, ot_res_p_i);
proto_tree_add_boolean(pcep_header_obj_flags, pcep_hdr_obj_flags_p, tvb, offset+1, 1, ot_res_p_i);
proto_tree_add_boolean(pcep_header_obj_flags, pcep_hdr_obj_flags_i, tvb, offset+1, 1, ot_res_p_i);
obj_length = tvb_get_ntohs(tvb, offset+2);
proto_item_set_len(pcep_object_item, obj_length);
if (obj_length < 4) {
proto_tree_add_text(pcep_object_tree, tvb, offset+2, 2, "Object Length: %u (bogus, must be >= 4)", obj_length);
break;
}
proto_tree_add_text(pcep_object_tree, tvb, offset+2, 2, "Object Length: %u", obj_length);
switch(obj_class) {
case PCEP_OPEN_OBJ:
dissect_pcep_open_obj(pcep_object_tree, tvb, offset+4, obj_length);
break;
case PCEP_RP_OBJ:
dissect_pcep_rp_obj(pcep_object_tree, tvb, offset+4, obj_length);
break;
case PCEP_NO_PATH_OBJ:
dissect_pcep_no_path_obj(pcep_object_tree, tvb, offset+4, obj_length);
break;
case PCEP_END_POINT_OBJ:
dissect_pcep_end_point_obj(pcep_object_tree, tvb, offset+4, obj_length, type);
break;
case PCEP_BANDWIDTH_OBJ:
dissect_pcep_bandwidth_obj(pcep_object_tree, tvb, offset+4, obj_length);
break;
case PCEP_METRIC_OBJ:
dissect_pcep_metric_obj(pcep_object_tree, tvb, offset+4, obj_length);
break;
case PCEP_EXPLICIT_ROUTE_OBJ:
dissect_pcep_explicit_route_obj(pcep_object_tree, tvb, offset+4, obj_length, obj_class);
break;
case PCEP_RECORD_ROUTE_OBJ:
dissect_pcep_record_route_obj(pcep_object_tree, tvb, offset+4, obj_length, obj_class);
break;
case PCEP_LSPA_OBJ:
dissect_pcep_lspa_obj(pcep_object_tree, tvb, offset+4, obj_length);
break;
case PCEP_IRO_OBJ:
dissect_pcep_iro_obj(pcep_object_tree, tvb, offset+4, obj_length, obj_class);
break;
case PCEP_SVEC_OBJ:
dissect_pcep_svec_obj(pcep_object_tree, tvb, offset+4, obj_length);
break;
case PCEP_NOTIFICATION_OBJ:
dissect_pcep_notification_obj(pcep_object_tree, tvb, offset+4, obj_length);
break;
case PCEP_PCEP_ERROR_OBJ:
dissect_pcep_error_obj(pcep_object_tree, tvb, offset+4, obj_length);
break;
case PCEP_LOAD_BALANCING_OBJ:
dissect_pcep_balancing_obj(pcep_object_tree, tvb, offset+4, obj_length);
break;
case PCEP_CLOSE_OBJ:
dissect_pcep_close_obj(pcep_object_tree, tvb, offset+4, obj_length);
break;
case PCEP_PATH_KEY_OBJ:
dissect_pcep_path_key_obj(pcep_object_tree, tvb, offset+4, obj_length);
break;
case PCEP_XRO_OBJ:
dissect_pcep_xro_obj(pcep_object_tree, tvb, offset+4, obj_length, obj_class);
break;
case PCEP_OBJ_MONITORING:
dissect_pcep_obj_monitoring(pcep_object_tree, tvb, offset+4, obj_length);
break;
case PCEP_OBJ_PCC_ID_REQ:
dissect_pcep_obj_pcc_id_req(pcep_object_tree, tvb, offset+4, obj_length, type);
break;
case PCEP_OF_OBJ:
dissect_pcep_of_obj(pcep_object_tree, tvb, offset+4, obj_length);
break;
case PCEP_OBJ_PCE_ID:
dissect_pcep_obj_pce_id(pcep_object_tree, tvb, offset+4, obj_length, type);
break;
case PCEP_OBJ_PROC_TIME:
dissect_pcep_obj_proc_time(pcep_object_tree, tvb, offset+4, obj_length);
break;
case PCEP_OBJ_OVERLOAD:
dissect_pcep_obj_overload(pcep_object_tree, tvb, offset+4, obj_length);
break;
default:
proto_tree_add_text(pcep_object_tree, tvb, offset+4, obj_length-OBJ_HDR_LEN, "PCEP Object BODY non defined (%u)", type);
break;
}
offset += obj_length;
len += obj_length;
}
}
static void
dissect_pcep_msg_tree(tvbuff_t *tvb, proto_tree *tree, guint tree_mode, packet_info *pinfo)
{
proto_tree *pcep_tree = NULL;
proto_tree *pcep_header_tree;
proto_tree *ti;
proto_tree *pcep_header_msg_flags;
proto_item *hidden_item;
int offset = 0;
int len=0;
guint8 ver_flags;
guint8 message_type;
guint16 msg_length;
ver_flags = tvb_get_guint8(tvb, 0);
message_type = tvb_get_guint8(tvb, 1);
msg_length = tvb_get_ntohs(tvb, 2);
if (check_col(pinfo->cinfo, COL_INFO)) {
col_append_fstr(pinfo->cinfo, COL_INFO, "%s", val_to_str(message_type, message_type_vals, "Unknown Message (%u). "));
}
ti = proto_tree_add_item(tree, proto_pcep, tvb, offset, msg_length, ENC_NA);
pcep_tree = proto_item_add_subtree(ti, tree_mode);
ti = proto_tree_add_text(pcep_tree, tvb, offset, 4, "%s Header", val_to_str(message_type, message_type_vals, "Unknown Message (%u). "));
pcep_header_tree = proto_item_add_subtree(ti, ett_pcep_hdr);
proto_tree_add_text(pcep_header_tree, tvb, offset, 1, "PCEP Version: %x", (ver_flags & 0x20)>>5);
ti = proto_tree_add_text(pcep_header_tree, tvb, offset, 1, "Flags: 0x%02x", ver_flags & 0x1f);
pcep_header_msg_flags = proto_item_add_subtree(ti, ett_pcep_hdr);
proto_tree_add_boolean(pcep_header_msg_flags, pcep_hdr_msg_flags_reserved, tvb, offset, 1, (ver_flags & 0x1f));
proto_tree_add_uint(pcep_header_tree, pcep_filter[PCEPF_MSG], tvb, offset+1, 1, message_type);
proto_tree_add_text(pcep_header_tree, tvb, offset+2, 2, "Message length: %u", msg_length);
switch (PCEPF_MSG + message_type) {
case PCEPF_OPEN:
case PCEPF_KEEPALIVE:
case PCEPF_PATH_COMPUTATION_REQUEST:
case PCEPF_PATH_COMPUTATION_REPLY:
case PCEPF_NOTIFICATION:
case PCEPF_ERROR:
case PCEPF_CLOSE:
case PCEPF_PATH_COMPUTATION_MONITORING_REQUEST:
case PCEPF_PATH_COMPUTATION_MONITORING_REPLY:
hidden_item = proto_tree_add_boolean(pcep_header_tree, pcep_filter[PCEPF_MSG + message_type], tvb, offset+1, 1, 1);
PROTO_ITEM_SET_HIDDEN(hidden_item);
break;
default:
proto_tree_add_protocol_format(pcep_header_tree, proto_malformed, tvb, offset+1, 1, "Invalid message type: %u", message_type);
return;
}
offset = 4;
len = 4;
dissect_pcep_obj_tree(pcep_tree, tvb, len, offset, msg_length);
}
static guint
get_pcep_message_len(packet_info *pinfo _U_, tvbuff_t *tvb, int offset)
{
guint16 plen;
plen = tvb_get_ntohs(tvb, offset+2);
return plen;
}
static void
dissect_pcep_pdu(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "PCEP");
col_clear(pinfo->cinfo, COL_INFO);
dissect_pcep_msg_tree(tvb, tree, ett_pcep, pinfo);
}
static void
dissect_pcep(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
tcp_dissect_pdus(tvb, pinfo, tree, TRUE, 4, get_pcep_message_len,
dissect_pcep_pdu);
}
void
proto_register_pcep(void){
static hf_register_info pcepf_info[] = {
{&pcep_filter[PCEPF_MSG],
{ "Message Type", "pcep.msg", FT_UINT8, BASE_DEC, VALS(message_type_vals), 0x0,
NULL, HFILL }},
{&pcep_hdr_msg_flags_reserved,
{ "Reserved Flags", "pcep.hdr.msg.flags.reserved", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PCEP_HDR_MSG_RESERVED,
NULL, HFILL }},
{&pcep_filter[PCEPF_OPEN],
{ "Open Message", "pcep.msg.open", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_KEEPALIVE],
{ "Keepalive Message", "pcep.msg.keepalive", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_PATH_COMPUTATION_REQUEST],
{ "Path Computation Request Message", "pcep.msg.path.computation.request", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_PATH_COMPUTATION_REPLY],
{ "Path Computation Reply Mesagge", "pcep.msg.path.computation.reply", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_NOTIFICATION],
{ "Notification Message", "pcep.msg.notification", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_ERROR],
{ "Error Message", "pcep.msg.error", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_CLOSE],
{ "Close Message", "pcep.msg.close", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_PATH_COMPUTATION_MONITORING_REQUEST],
{ "Path Computation Monitoring Request Message", "pcep.msg.path.computation.monitoring.request", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_PATH_COMPUTATION_MONITORING_REPLY],
{ "Path Computation Monitoring Reply Mesagge", "pcep.msg.path.computation.monitoring.reply", FT_BOOLEAN, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_hdr_obj_flags_reserved,
{ "Reserved Flags", "pcep.hdr.obj.flags.reserved", FT_BOOLEAN, 4, TFS(&tfs_set_notset), PCEP_HDR_OBJ_RESERVED,
NULL, HFILL }},
{&pcep_hdr_obj_flags_p,
{ "Processing-Rule (P)", "pcep.hdr.obj.flags.p", FT_BOOLEAN, 4, TFS(&tfs_set_notset), PCEP_HDR_OBJ_P,
NULL, HFILL }},
{&pcep_hdr_obj_flags_i,
{ "Ignore (I)", "pcep.hdr.obj.flags.i", FT_BOOLEAN, 4, TFS(&tfs_set_notset), PCEP_HDR_OBJ_I,
NULL, HFILL }},
{&pcep_filter[PCEPF_OBJECT_CLASS],
{ "Object Class", "pcep.object", FT_UINT32, BASE_DEC, VALS(pcep_class_vals), 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_OBJ_OPEN],
{ "OPEN object", "pcep.obj.open", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_open_flags_res,
{ "Reserved Flags", "pcep.open.flags.res", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PCEP_OPEN_RES,
NULL, HFILL }},
{&pcep_filter[PCEPF_OBJ_RP],
{ "RP object", "pcep.obj.rp", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_rp_flags_reserved,
{ "Reserved Flags", "pcep.rp.flags.reserved", FT_BOOLEAN, 24, TFS(&tfs_set_notset), PCEP_RP_RESERVED,
NULL, HFILL }},
{&pcep_rp_flags_pri,
{ "(PRI) Priority", "pcep.rp.flags.pri", FT_BOOLEAN, 24, TFS(&tfs_on_off), PCEP_RP_PRI,
NULL, HFILL }},
{&pcep_rp_flags_r,
{ "(R) Reoptimization", "pcep.rp.flags.r", FT_BOOLEAN, 24, TFS(&tfs_set_notset), PCEP_RP_R,
NULL, HFILL }},
{&pcep_rp_flags_b,
{ "(B) Bi-directional", "pcep.rp.flags.b", FT_BOOLEAN, 24, TFS(&tfs_set_notset), PCEP_RP_B,
NULL, HFILL }},
{&pcep_rp_flags_o,
{ "(L) Strict/Loose", "pcep.rp.flags.o", FT_BOOLEAN, 24, TFS(&tfs_set_notset), PCEP_RP_O,
NULL, HFILL }},
{&pcep_rp_flags_v,
{ "(V) VSPT", "pcep.rp.flags.v", FT_BOOLEAN, 24, TFS(&tfs_set_notset), PCEP_RP_V,
NULL, HFILL }},
{&pcep_rp_flags_s,
{ "(S) Supply OF on response", "pcep.rp.flags.s", FT_BOOLEAN, 24, TFS(&tfs_set_notset), PCEP_RP_S,
NULL, HFILL }},
{&pcep_rp_flags_p,
{ "(P) Path Key", "pcep.rp.flags.p", FT_BOOLEAN, 24, TFS(&tfs_set_notset), PCEP_RP_P,
NULL, HFILL }},
{&pcep_rp_flags_d,
{ "(D) Report the request order", "pcep.rp.flags.d", FT_BOOLEAN, 24, TFS(&tfs_set_notset), PCEP_RP_D,
NULL, HFILL }},
{&pcep_rp_flags_m,
{ "(M) Make-before-break", "pcep.rp.flags.m", FT_BOOLEAN, 24, TFS(&tfs_set_notset), PCEP_RP_M,
NULL, HFILL }},
{&pcep_rp_flags_e,
{ "(E) ERO-compression", "pcep.rp.flags.e", FT_BOOLEAN, 24, TFS(&tfs_set_notset), PCEP_RP_E,
NULL, HFILL }},
{&pcep_rp_flags_n,
{ "(N) P2MP", "pcep.rp.flags.n", FT_BOOLEAN, 24, TFS(&tfs_set_notset), PCEP_RP_N,
NULL, HFILL }},
{&pcep_rp_flags_f,
{ "(F) Fragmentation", "pcep.rp.flags.f", FT_BOOLEAN, 24, TFS(&tfs_set_notset), PCEP_RP_F,
NULL, HFILL }},
{&pcep_filter[PCEPF_OBJ_NO_PATH],
{ "NO-PATH object", "pcep.obj.nopath", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_no_path_flags_c,
{ "C", "pcep.no.path.flags.c", FT_BOOLEAN, 16, TFS(&tfs_set_notset), PCEP_NO_PATH_C,
NULL, HFILL }},
{&pcep_filter[PCEPF_OBJ_END_POINT],
{ "END-POINT object", "pcep.obj.endpoint", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_OBJ_BANDWIDTH],
{ "BANDWIDTH object", "pcep.obj.bandwidth", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_OBJ_METRIC],
{ "METRIC object", "pcep.obj.metric", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_metric_flags_c,
{ "(C) Cost", "pcep.metric.flags.c", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PCEP_METRIC_C,
NULL, HFILL }},
{&pcep_metric_flags_b,
{ "(B) Bound", "pcep.metric.flags.b", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PCEP_METRIC_B,
NULL, HFILL }},
{&pcep_filter[PCEPF_OBJ_EXPLICIT_ROUTE],
{ "EXPLICIT ROUTE object (ERO)", "pcep.obj.ero", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_OBJ_RECORD_ROUTE],
{ "RECORD ROUTE object (RRO)", "pcep.obj.rro", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_OBJ_LSPA],
{ "LSPA object", "pcep.obj.lspa", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_lspa_flags_l,
{ "Local Protection Desired (L)", "pcep.lspa.flags.l", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PCEP_LSPA_L,
NULL, HFILL }},
{&pcep_filter[PCEPF_OBJ_IRO],
{ "IRO object", "pcep.obj.iro", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_OBJ_SVEC],
{ "SVEC object", "pcep.obj.svec", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_svec_flags_l,
{ "Link diverse (L)", "pcep.svec.flags.l", FT_BOOLEAN, 24, TFS(&tfs_set_notset), PCEP_SVEC_L,
NULL, HFILL }},
{&pcep_svec_flags_n,
{ "Node diverse (N)", "pcep.svec.flags.n", FT_BOOLEAN, 24, TFS(&tfs_set_notset), PCEP_SVEC_N,
NULL, HFILL }},
{&pcep_svec_flags_s,
{ "SRLG diverse (S)", "pcep.svec.flags.s", FT_BOOLEAN, 24, TFS(&tfs_set_notset), PCEP_SVEC_S,
NULL, HFILL }},
{&pcep_filter[PCEPF_OBJ_NOTIFICATION],
{ "NOTIFICATION object", "pcep.obj.notification", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_NOTI_TYPE],
{ "Notification Value", "pcep.notification.value1", FT_UINT32, BASE_DEC, VALS(pcep_notification_types_vals), 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_NOTI_VAL1],
{ "Notification Type", "pcep.notification.type2", FT_UINT32, BASE_DEC, VALS(pcep_notification_values1_vals), 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_NOTI_VAL2],
{ "Notification Type", "pcep.notification.type", FT_UINT32, BASE_DEC, VALS(pcep_notification_values2_vals), 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_OBJ_PCEP_ERROR],
{ "ERROR object", "pcep.obj.error", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_ERROR_TYPE],
{ "Error-Type", "pcep.error.type", FT_UINT8, BASE_DEC, VALS(pcep_error_types_obj_vals), 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_OBJ_LOAD_BALANCING],
{ "LOAD BALANCING object", "pcep.obj.loadbalancing", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_OBJ_CLOSE],
{ "CLOSE object", "pcep.obj.close", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_OBJ_PATH_KEY],
{ "PATH-KEY object", "pcep.obj.path_key", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_OBJ_XRO],
{ "EXCLUDE ROUTE object (XRO)", "pcep.obj.xro", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_OBJ_MONITORING],
{ "MONITORING object", "pcep.obj.monitoring", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_obj_monitoring_flags_reserved,
{ "Reserved Flags", "pcep.obj.monitoring.flags.reserved", FT_BOOLEAN, 24, TFS(&tfs_set_notset),
PCEP_OBJ_MONITORING_FLAGS_RESERVED, NULL, HFILL }},
{&pcep_obj_monitoring_flags_l,
{ "Liveness (L)", "pcep.obj.monitoring.flags.l", FT_BOOLEAN, 24, TFS(&tfs_set_notset),
PCEP_OBJ_MONITORING_FLAGS_L, NULL, HFILL }},
{&pcep_obj_monitoring_flags_g,
{ "General (G)", "pcep.obj.monitoring.flags.g", FT_BOOLEAN, 24, TFS(&tfs_set_notset),
PCEP_OBJ_MONITORING_FLAGS_G, NULL, HFILL }},
{&pcep_obj_monitoring_flags_p,
{ "Processing Time (P)", "pcep.obj.monitoring.flags.p", FT_BOOLEAN, 24, TFS(&tfs_set_notset),
PCEP_OBJ_MONITORING_FLAGS_P, NULL, HFILL }},
{&pcep_obj_monitoring_flags_c,
{ "Overload (C)", "pcep.obj.monitoring.flags.c", FT_BOOLEAN, 24, TFS(&tfs_set_notset),
PCEP_OBJ_MONITORING_FLAGS_C, NULL, HFILL }},
{&pcep_obj_monitoring_flags_i,
{ "Incomplete (I)", "pcep.obj.monitoring.flags.i", FT_BOOLEAN, 24, TFS(&tfs_set_notset),
PCEP_OBJ_MONITORING_FLAGS_I, NULL, HFILL }},
{ &pcep_obj_monitoring_monitoring_id_number,
{ "Monitoring ID Number", "pcep.obj.monitoring.monidnumber", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{&pcep_filter[PCEPF_OBJ_PCC_ID_REQ],
{ "PCC-ID-REQ object", "pcep.obj.pccidreq", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &pcep_obj_pcc_id_req_ipv4,
{ "IPv4 address", "pcep.obj.pccidreq.ipv4", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &pcep_obj_pcc_id_req_ipv6,
{ "IPv6 address", "pcep.obj.pccidreq.ipv6", FT_IPv6, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&pcep_filter[PCEPF_OBJ_OF],
{ "OBJECTIVE FUNCTION object (OF)", "pcep.obj.of", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_OBJ_PCE_ID],
{ "PCE-ID object", "pcep.obj.pceid", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &pcep_obj_pce_id_ipv4,
{ "IPv4 address", "pcep.obj.pceid.ipv4", FT_IPv4, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{ &pcep_obj_pce_id_ipv6,
{ "IPv6 address", "pcep.obj.pceid.ipv6", FT_IPv6, BASE_NONE,
NULL, 0x0, NULL, HFILL }},
{&pcep_filter[PCEPF_OBJ_PROC_TIME],
{ "PROC-TIME object", "pcep.obj.proctime", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_obj_proc_time_flags_reserved,
{ "Reserved Flags", "pcep.obj.proctime.flags.reserved", FT_BOOLEAN, 16, TFS(&tfs_set_notset),
PCEP_OBJ_PROC_TIME_FLAGS_RESERVED, NULL, HFILL }},
{&pcep_obj_proc_time_flags_e,
{ "Estimated (E)", "pcep.obj.proctime.flags.e", FT_BOOLEAN, 16, TFS(&tfs_set_notset),
PCEP_OBJ_PROC_TIME_FLAGS_E, NULL, HFILL }},
{ &pcep_obj_proc_time_cur_proc_time,
{ "Current processing time", "pcep.obj.proctime.curproctime", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &pcep_obj_proc_time_min_proc_time,
{ "Minimum processing time", "pcep.obj.proctime.minproctime", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &pcep_obj_proc_time_max_proc_time,
{ "Maximum processing time", "pcep.obj.proctime.maxproctime", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &pcep_obj_proc_time_ave_proc_time,
{ "Average processing time", "pcep.obj.proctime.aveproctime", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{ &pcep_obj_proc_time_var_proc_time,
{ "Variance processing time", "pcep.obj.proctime.varproctime", FT_UINT32, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{&pcep_filter[PCEPF_OBJ_OVERLOAD],
{ "OVERLOAD object", "pcep.obj.overload", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{ &pcep_obj_overload_duration,
{ "Overload Duration", "pcep.obj.overload.duration", FT_UINT16, BASE_DEC,
NULL, 0x0, NULL, HFILL }},
{&pcep_filter[PCEPF_SUBOBJ],
{ "Type", "pcep.subobj", FT_UINT8, BASE_DEC, VALS(pcep_subobj_vals), 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_SUBOBJ_IPv4],
{ "SUBOBJECT: IPv4 Prefix", "pcep.subobj.ipv4", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_SUBOBJ_IPv6],
{ "SUBOBJECT: IPv6 Prefix", "pcep.subobj.ipv6", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_SUBOBJ_LABEL_CONTROL],
{ "SUBOBJECT: Label Control", "pcep.subobj.label.control", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_SUBOBJ_UNNUM_INTERFACEID],
{ "SUBOBJECT: Unnumbered Interface ID", "pcep.subobj.unnum.interfaceid", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_SUBOBJ_AUTONOMOUS_SYS_NUM],
{ "SUBOBJECT: Autonomous System Number", "pcep.subobj.autonomous.sys.num", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_SUBOBJ_SRLG],
{ "SUBOBJECT: SRLG", "pcep.subobj.srlg", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_SUBOBJ_EXRS],
{ "SUBOBJECT: EXRS", "pcep.subobj.exrs", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_SUBOBJ_PKSv4],
{ "SUBOBJECT: Path Key (IPv4)", "pcep.subobj.path_key.ipv4", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_SUBOBJ_PKSv6],
{ "SUBOBJECT: Path Key (IPv6)", "pcep.subobj.path_key.ipv6", FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }},
{&pcep_filter[PCEPF_SUBOBJ_XRO],
{ "Type", "pcep.subobj.label", FT_UINT32, BASE_DEC, VALS(pcep_subobj_xro_vals), 0x0,
NULL, HFILL }},
{&pcep_xro_flags_f,
{ "Fail (F)", "pcep.xro.flags.f", FT_BOOLEAN, 16, TFS(&tfs_set_notset), PCEP_XRO_F,
NULL, HFILL }},
{&pcep_filter[PCEPF_SUB_XRO_ATTRIB],
{ "Attribute", "pcep.xro.sub.attribute", FT_UINT32, BASE_DEC, VALS(pcep_xro_attribute_obj_vals), 0x0,
NULL, HFILL }},
{&pcep_subobj_flags_lpa,
{ "Local Protection Available", "pcep.subobj.flags.lpa", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PCEP_SUB_LPA,
NULL, HFILL }},
{&pcep_subobj_flags_lpu,
{ "Local protection in Use", "pcep.subobj.flags.lpu", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PCEP_SUB_LPU,
NULL, HFILL }},
{&pcep_subobj_label_flags_gl,
{ "Global Label", "pcep.subobj.label.flags.gl", FT_BOOLEAN, 8, TFS(&tfs_set_notset), PCEP_SUB_LABEL_GL,
NULL, HFILL }},
};
proto_pcep = proto_register_protocol (
"Path Computation Element communication Protocol",
"PCEP",
"pcep" );
proto_register_field_array(proto_pcep, pcepf_info, array_length(pcepf_info));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_pcep(void)
{
dissector_handle_t pcep_handle;
pcep_handle = create_dissector_handle(dissect_pcep, proto_pcep);
dissector_add_uint("tcp.port", TCP_PORT_PCEP, pcep_handle);
}
