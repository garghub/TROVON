static void
addTlvHeaderElements(tvbuff_t *tvb, proto_tree *tlv_tree, lwm2mElement_t *element)
{
proto_tree_add_item(tlv_tree, hf_lwm2mtlv_type_type, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_lwm2mtlv_type_length_of_identifier, tvb, 0, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_lwm2mtlv_type_length_of_length, tvb, 0, 1, ENC_BIG_ENDIAN);
if ( element->length_of_length == 0 ) {
proto_tree_add_item(tlv_tree, hf_lwm2mtlv_type_length, tvb, 0, 1, ENC_BIG_ENDIAN);
} else {
proto_tree_add_item(tlv_tree, hf_lwm2mtlv_type_ignored, tvb, 0, 1, ENC_BIG_ENDIAN);
}
proto_tree_add_item(tlv_tree, hf_lwm2mtlv_identifier, tvb, 1, element->length_of_identifier, ENC_BIG_ENDIAN);
if ( element->length_of_length > 0 ) {
proto_tree_add_item(tlv_tree, hf_lwm2mtlv_length, tvb, 1+element->length_of_identifier, element->length_of_length, ENC_BIG_ENDIAN);
}
}
static void
addTlvHeaderTree(tvbuff_t *tvb, proto_tree *tlv_tree, lwm2mElement_t *element)
{
proto_item *item = NULL;
proto_tree *header_tree = NULL;
guint valueOffset = 1 + element->length_of_identifier + element->length_of_length;
item = proto_tree_add_item(tlv_tree, hf_lwm2mtlv_header, tvb, 0, valueOffset, ENC_NA);
header_tree = proto_item_add_subtree(item, ett_lwm2mtlv_header);
addTlvHeaderElements(tvb, header_tree, element);
}
static proto_tree*
addElementTree(tvbuff_t *tvb, proto_tree *tlv_tree, lwm2mElement_t *element)
{
guint valueOffset = 1 + element->length_of_identifier + element->length_of_length;
guint8 *str;
switch ( element->type )
{
case OBJECT_INSTANCE:
return proto_tree_add_subtree_format(tlv_tree, tvb, 0, element->totalLength, ett_lwm2mtlv_objectInstance, NULL,
"Object Instance %02u (%u Bytes)", element->identifier, element->length_of_value);
case RESOURCE_INSTANCE:
str = tvb_get_string_enc(wmem_packet_scope(), tvb, valueOffset, element->length_of_value, ENC_ASCII);
return proto_tree_add_subtree_format(tlv_tree, tvb, 0, element->totalLength, ett_lwm2mtlv_resourceInstance, NULL,
"%02u: %s", element->identifier, str);
case RESOURCE_ARRAY:
return proto_tree_add_subtree_format(tlv_tree, tvb, 0, element->totalLength, ett_lwm2mtlv_resourceArray, NULL,
"%02u: (Array of %u Bytes)", element->identifier, element->length_of_value);
case RESOURCE:
str = tvb_get_string_enc(wmem_packet_scope(), tvb, valueOffset, element->length_of_value, ENC_ASCII);
return proto_tree_add_subtree_format(tlv_tree, tvb, 0, element->totalLength, ett_lwm2mtlv_resource, NULL,
"%02u: %s", element->identifier, str);
}
return NULL;
}
static void
addValueInterpretations(tvbuff_t *tvb, proto_tree *tlv_tree, lwm2mElement_t *element)
{
guint valueOffset;
if ( element->length_of_value == 0 ) return;
valueOffset = 1 + element->length_of_identifier + element->length_of_length;
proto_tree_add_item(tlv_tree, hf_lwm2mtlv_value_string, tvb, valueOffset, element->length_of_value, ENC_ASCII|ENC_NA);
switch(element->length_of_value)
{
case 0x01:
proto_tree_add_item(tlv_tree, hf_lwm2mtlv_value_integer, tvb, valueOffset, element->length_of_value, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_lwm2mtlv_value_boolean, tvb, valueOffset, element->length_of_value, ENC_BIG_ENDIAN);
break;
case 0x02:
proto_tree_add_item(tlv_tree, hf_lwm2mtlv_value_integer, tvb, valueOffset, element->length_of_value, ENC_BIG_ENDIAN);
break;
case 0x04:
proto_tree_add_item(tlv_tree, hf_lwm2mtlv_value_integer, tvb, valueOffset, element->length_of_value, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_lwm2mtlv_value_float, tvb, valueOffset, element->length_of_value, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_lwm2mtlv_value_timestamp, tvb, valueOffset, element->length_of_value, ENC_BIG_ENDIAN);
break;
case 0x08:
proto_tree_add_item(tlv_tree, hf_lwm2mtlv_value_integer, tvb, valueOffset, element->length_of_value, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_lwm2mtlv_value_double, tvb, valueOffset, element->length_of_value, ENC_BIG_ENDIAN);
proto_tree_add_item(tlv_tree, hf_lwm2mtlv_value_timestamp, tvb, valueOffset+4, element->length_of_value-4, ENC_BIG_ENDIAN);
break;
}
}
static void
addValueTree(tvbuff_t *tvb, proto_tree *tlv_tree, lwm2mElement_t *element)
{
guint valueOffset = 1 + element->length_of_identifier + element->length_of_length;
if ( element->type == RESOURCE || element->type == RESOURCE_INSTANCE ) {
proto_tree_add_item(tlv_tree, hf_lwm2mtlv_value, tvb, valueOffset, element->length_of_value, ENC_NA);
addValueInterpretations(tvb, tlv_tree, element);
} else {
tvbuff_t* sub = tvb_new_subset_length(tvb, valueOffset, element->length_of_value);
parseArrayOfElements(sub, tlv_tree);
}
}
static void
addTlvElement(tvbuff_t *tvb, proto_tree *tlv_tree, lwm2mElement_t *element)
{
proto_tree *element_tree = NULL;
element_tree = addElementTree(tvb, tlv_tree, element);
addTlvHeaderTree(tvb, element_tree, element);
addValueTree(tvb, element_tree, element);
}
static guint64
decodeVariableInt(tvbuff_t *tvb, const gint offset, const guint length)
{
switch(length)
{
case 1:
return tvb_get_guint8(tvb, offset);
case 2:
return tvb_get_letohs(tvb, offset);
case 3:
return tvb_get_letoh24(tvb, offset);
case 4:
return tvb_get_letohl(tvb, offset);
case 5:
return tvb_get_letoh40(tvb, offset);
case 6:
return tvb_get_letoh48(tvb, offset);
case 7:
return tvb_get_letoh56(tvb, offset);
case 8:
return tvb_get_letoh64(tvb, offset);
default:
return 0;
}
}
static guint parseTLVHeader(tvbuff_t *tvb, lwm2mElement_t *element)
{
guint type_field = tvb_get_guint8(tvb, 0);
element->type = (( type_field >> 6 ) & 0x03 );
element->length_of_identifier = (( type_field >> 5 ) & 0x01 ) + 1;
element->length_of_length = (( type_field >> 3 ) & 0x03 );
element->length_of_value = (( type_field >> 0 ) & 0x07 );
element->identifier = (guint) decodeVariableInt(tvb, 1, element->length_of_identifier);
if ( element->length_of_length > 0 ) {
element->length_of_value = (guint) decodeVariableInt(tvb, 1 + element->length_of_identifier, element->length_of_length);
}
element->totalLength = 1 + element->length_of_identifier + element->length_of_length + element->length_of_value;
return element->totalLength;
}
static void parseArrayOfElements(tvbuff_t *tvb, proto_tree *tlv_tree)
{
guint length;
guint offset = 0;
guint elementLength = 0;
lwm2mElement_t element;
length = tvb_reported_length(tvb);
while ( length > 0 ) {
tvbuff_t* sub = tvb_new_subset_length(tvb, offset, length);
elementLength = parseTLVHeader(sub, &element);
addTlvElement(sub, tlv_tree, &element);
length -= elementLength;
offset += elementLength;
if ( elementLength == 0 )
{
break;
}
}
}
static int
dissect_lwm2mtlv(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *tree, void* data _U_)
{
proto_tree* lwm2mtlv_tree;
proto_item* lwm2mtlv_item;
if (tree) {
lwm2mtlv_item = proto_tree_add_item(tree, proto_lwm2mtlv, tvb, 0, -1, ENC_NA);
lwm2mtlv_tree = proto_item_add_subtree(lwm2mtlv_item, ett_lwm2mtlv);
parseArrayOfElements(tvb, lwm2mtlv_tree);
}
return tvb_captured_length(tvb);
}
void proto_register_lwm2mtlv(void)
{
static hf_register_info hf[] = {
{ &hf_lwm2mtlv_header,
{ "TLV header", "lwm2mtlv.header",
FT_NONE, BASE_NONE, NULL, 0x0,
NULL, HFILL }
},
{ &hf_lwm2mtlv_type_type,
{ "Type of Identifier", "lwm2mtlv.type.type",
FT_UINT8, BASE_DEC, VALS(identifiers), 0xC0,
NULL, HFILL }
},
{ &hf_lwm2mtlv_type_length_of_identifier,
{ "Length of Identifier", "lwm2mtlv.type.loi",
FT_UINT8, BASE_DEC, VALS(length_identifier), 0x20,
NULL, HFILL }
},
{ &hf_lwm2mtlv_type_length_of_length,
{ "Length of Length", "lwm2mtlv.type.lol",
FT_UINT8, BASE_DEC, VALS(length_type), 0x18,
NULL, HFILL }
},
{ &hf_lwm2mtlv_type_length,
{ "Length", "lwm2mtlv.type.length",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }
},
{ &hf_lwm2mtlv_type_ignored,
{ "Ignored", "lwm2mtlv.type.ignored",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }
},
{ &hf_lwm2mtlv_identifier,
{ "Identifier", "lwm2mtlv.identifier",
FT_UINT16, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_lwm2mtlv_length,
{ "Length", "lwm2mtlv.length",
FT_UINT32, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_lwm2mtlv_value,
{ "Value", "lwm2mtlv.value",
FT_BYTES, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_lwm2mtlv_value_string,
{ "As String", "lwm2mtlv.value.string",
FT_STRING, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_lwm2mtlv_value_integer,
{ "As Integer", "lwm2mtlv.value.integer",
FT_INT64, BASE_DEC, NULL, 0,
NULL, HFILL }
},
{ &hf_lwm2mtlv_value_float,
{ "As Float", "lwm2mtlv.value.float",
FT_FLOAT, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_lwm2mtlv_value_double,
{ "As Double", "lwm2mtlv.value.double",
FT_DOUBLE, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_lwm2mtlv_value_boolean,
{ "As Boolean", "lwm2mtlv.value.boolean",
FT_BOOLEAN, BASE_NONE, NULL, 0,
NULL, HFILL }
},
{ &hf_lwm2mtlv_value_timestamp,
{ "As Timestamp", "lwm2mtlv.value.timestamp",
FT_ABSOLUTE_TIME, ABSOLUTE_TIME_LOCAL, NULL, 0,
NULL, HFILL }
},
};
static gint* ett[] = {
&ett_lwm2mtlv,
&ett_lwm2mtlv_header,
&ett_lwm2mtlv_resource,
&ett_lwm2mtlv_resourceInstance,
&ett_lwm2mtlv_resourceArray,
&ett_lwm2mtlv_objectInstance
};
proto_lwm2mtlv = proto_register_protocol (
"Lightweight M2M TLV",
"LwM2M-TLV",
"lwm2mtlv"
);
proto_register_field_array(proto_lwm2mtlv, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
register_dissector("lwm2mtlv", dissect_lwm2mtlv, proto_lwm2mtlv);
}
void
proto_reg_handoff_lwm2mtlv(void)
{
static dissector_handle_t lwm2mtlv_handle;
lwm2mtlv_handle = create_dissector_handle(dissect_lwm2mtlv, proto_lwm2mtlv);
dissector_add_string("media_type", "application/vnd.oma.lwm2m+tlv", lwm2mtlv_handle);
}
