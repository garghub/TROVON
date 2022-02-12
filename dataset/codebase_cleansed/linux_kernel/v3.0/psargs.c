static u32
acpi_ps_get_next_package_length(struct acpi_parse_state *parser_state)
{
u8 *aml = parser_state->aml;
u32 package_length = 0;
u32 byte_count;
u8 byte_zero_mask = 0x3F;
ACPI_FUNCTION_TRACE(ps_get_next_package_length);
byte_count = (aml[0] >> 6);
parser_state->aml += ((acpi_size) byte_count + 1);
while (byte_count) {
package_length |= (aml[byte_count] << ((byte_count << 3) - 4));
byte_zero_mask = 0x0F;
byte_count--;
}
package_length |= (aml[0] & byte_zero_mask);
return_UINT32(package_length);
}
u8 *acpi_ps_get_next_package_end(struct acpi_parse_state *parser_state)
{
u8 *start = parser_state->aml;
u32 package_length;
ACPI_FUNCTION_TRACE(ps_get_next_package_end);
package_length = acpi_ps_get_next_package_length(parser_state);
return_PTR(start + package_length);
}
char *acpi_ps_get_next_namestring(struct acpi_parse_state *parser_state)
{
u8 *start = parser_state->aml;
u8 *end = parser_state->aml;
ACPI_FUNCTION_TRACE(ps_get_next_namestring);
while (acpi_ps_is_prefix_char(*end)) {
end++;
}
switch (*end) {
case 0:
if (end == start) {
start = NULL;
}
end++;
break;
case AML_DUAL_NAME_PREFIX:
end += 1 + (2 * ACPI_NAME_SIZE);
break;
case AML_MULTI_NAME_PREFIX_OP:
end += 2 + (*(end + 1) * ACPI_NAME_SIZE);
break;
default:
end += ACPI_NAME_SIZE;
break;
}
parser_state->aml = end;
return_PTR((char *)start);
}
acpi_status
acpi_ps_get_next_namepath(struct acpi_walk_state *walk_state,
struct acpi_parse_state *parser_state,
union acpi_parse_object *arg, u8 possible_method_call)
{
acpi_status status;
char *path;
union acpi_parse_object *name_op;
union acpi_operand_object *method_desc;
struct acpi_namespace_node *node;
u8 *start = parser_state->aml;
ACPI_FUNCTION_TRACE(ps_get_next_namepath);
path = acpi_ps_get_next_namestring(parser_state);
acpi_ps_init_op(arg, AML_INT_NAMEPATH_OP);
if (!path) {
arg->common.value.name = path;
return_ACPI_STATUS(AE_OK);
}
status = acpi_ns_lookup(walk_state->scope_info, path,
ACPI_TYPE_ANY, ACPI_IMODE_EXECUTE,
ACPI_NS_SEARCH_PARENT | ACPI_NS_DONT_OPEN_SCOPE,
NULL, &node);
if (ACPI_SUCCESS(status) &&
possible_method_call && (node->type == ACPI_TYPE_METHOD)) {
if (walk_state->opcode == AML_UNLOAD_OP) {
walk_state->parser_state.aml = start;
walk_state->arg_count = 1;
acpi_ps_init_op(arg, AML_INT_METHODCALL_OP);
return_ACPI_STATUS(AE_OK);
}
method_desc = acpi_ns_get_attached_object(node);
ACPI_DEBUG_PRINT((ACPI_DB_PARSE,
"Control Method - %p Desc %p Path=%p\n", node,
method_desc, path));
name_op = acpi_ps_alloc_op(AML_INT_NAMEPATH_OP);
if (!name_op) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
acpi_ps_init_op(arg, AML_INT_METHODCALL_OP);
name_op->common.value.name = path;
name_op->common.node = node;
acpi_ps_append_arg(arg, name_op);
if (!method_desc) {
ACPI_ERROR((AE_INFO,
"Control Method %p has no attached object",
node));
return_ACPI_STATUS(AE_AML_INTERNAL);
}
ACPI_DEBUG_PRINT((ACPI_DB_PARSE,
"Control Method - %p Args %X\n",
node, method_desc->method.param_count));
walk_state->arg_count = method_desc->method.param_count;
return_ACPI_STATUS(AE_OK);
}
if (status == AE_NOT_FOUND) {
if ((walk_state->parse_flags & ACPI_PARSE_MODE_MASK) !=
ACPI_PARSE_EXECUTE) {
status = AE_OK;
}
else if (walk_state->op->common.aml_opcode ==
AML_COND_REF_OF_OP) {
status = AE_OK;
}
else if ((arg->common.parent) &&
((arg->common.parent->common.aml_opcode ==
AML_PACKAGE_OP)
|| (arg->common.parent->common.aml_opcode ==
AML_VAR_PACKAGE_OP))) {
status = AE_OK;
}
}
if (ACPI_FAILURE(status)) {
ACPI_ERROR_NAMESPACE(path, status);
if ((walk_state->parse_flags & ACPI_PARSE_MODE_MASK) ==
ACPI_PARSE_EXECUTE) {
status = acpi_ds_method_error(status, walk_state);
}
}
arg->common.value.name = path;
return_ACPI_STATUS(status);
}
void
acpi_ps_get_next_simple_arg(struct acpi_parse_state *parser_state,
u32 arg_type, union acpi_parse_object *arg)
{
u32 length;
u16 opcode;
u8 *aml = parser_state->aml;
ACPI_FUNCTION_TRACE_U32(ps_get_next_simple_arg, arg_type);
switch (arg_type) {
case ARGP_BYTEDATA:
opcode = AML_BYTE_OP;
arg->common.value.integer = (u64) *aml;
length = 1;
break;
case ARGP_WORDDATA:
opcode = AML_WORD_OP;
ACPI_MOVE_16_TO_64(&arg->common.value.integer, aml);
length = 2;
break;
case ARGP_DWORDDATA:
opcode = AML_DWORD_OP;
ACPI_MOVE_32_TO_64(&arg->common.value.integer, aml);
length = 4;
break;
case ARGP_QWORDDATA:
opcode = AML_QWORD_OP;
ACPI_MOVE_64_TO_64(&arg->common.value.integer, aml);
length = 8;
break;
case ARGP_CHARLIST:
opcode = AML_STRING_OP;
arg->common.value.string = ACPI_CAST_PTR(char, aml);
length = 0;
while (aml[length]) {
length++;
}
length++;
break;
case ARGP_NAME:
case ARGP_NAMESTRING:
acpi_ps_init_op(arg, AML_INT_NAMEPATH_OP);
arg->common.value.name =
acpi_ps_get_next_namestring(parser_state);
return_VOID;
default:
ACPI_ERROR((AE_INFO, "Invalid ArgType 0x%X", arg_type));
return_VOID;
}
acpi_ps_init_op(arg, opcode);
parser_state->aml += length;
return_VOID;
}
static union acpi_parse_object *acpi_ps_get_next_field(struct acpi_parse_state
*parser_state)
{
u32 aml_offset = (u32)
ACPI_PTR_DIFF(parser_state->aml,
parser_state->aml_start);
union acpi_parse_object *field;
u16 opcode;
u32 name;
ACPI_FUNCTION_TRACE(ps_get_next_field);
switch (ACPI_GET8(parser_state->aml)) {
default:
opcode = AML_INT_NAMEDFIELD_OP;
break;
case 0x00:
opcode = AML_INT_RESERVEDFIELD_OP;
parser_state->aml++;
break;
case 0x01:
opcode = AML_INT_ACCESSFIELD_OP;
parser_state->aml++;
break;
}
field = acpi_ps_alloc_op(opcode);
if (!field) {
return_PTR(NULL);
}
field->common.aml_offset = aml_offset;
switch (opcode) {
case AML_INT_NAMEDFIELD_OP:
ACPI_MOVE_32_TO_32(&name, parser_state->aml);
acpi_ps_set_name(field, name);
parser_state->aml += ACPI_NAME_SIZE;
field->common.value.size =
acpi_ps_get_next_package_length(parser_state);
break;
case AML_INT_RESERVEDFIELD_OP:
field->common.value.size =
acpi_ps_get_next_package_length(parser_state);
break;
case AML_INT_ACCESSFIELD_OP:
field->common.value.integer =
(((u32) ACPI_GET8(parser_state->aml) << 8));
parser_state->aml++;
field->common.value.integer |= ACPI_GET8(parser_state->aml);
parser_state->aml++;
break;
default:
break;
}
return_PTR(field);
}
acpi_status
acpi_ps_get_next_arg(struct acpi_walk_state *walk_state,
struct acpi_parse_state *parser_state,
u32 arg_type, union acpi_parse_object **return_arg)
{
union acpi_parse_object *arg = NULL;
union acpi_parse_object *prev = NULL;
union acpi_parse_object *field;
u32 subop;
acpi_status status = AE_OK;
ACPI_FUNCTION_TRACE_PTR(ps_get_next_arg, parser_state);
switch (arg_type) {
case ARGP_BYTEDATA:
case ARGP_WORDDATA:
case ARGP_DWORDDATA:
case ARGP_CHARLIST:
case ARGP_NAME:
case ARGP_NAMESTRING:
arg = acpi_ps_alloc_op(AML_BYTE_OP);
if (!arg) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
acpi_ps_get_next_simple_arg(parser_state, arg_type, arg);
break;
case ARGP_PKGLENGTH:
parser_state->pkg_end =
acpi_ps_get_next_package_end(parser_state);
break;
case ARGP_FIELDLIST:
if (parser_state->aml < parser_state->pkg_end) {
while (parser_state->aml < parser_state->pkg_end) {
field = acpi_ps_get_next_field(parser_state);
if (!field) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
if (prev) {
prev->common.next = field;
} else {
arg = field;
}
prev = field;
}
parser_state->aml = parser_state->pkg_end;
}
break;
case ARGP_BYTELIST:
if (parser_state->aml < parser_state->pkg_end) {
arg = acpi_ps_alloc_op(AML_INT_BYTELIST_OP);
if (!arg) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
arg->common.value.size = (u32)
ACPI_PTR_DIFF(parser_state->pkg_end,
parser_state->aml);
arg->named.data = parser_state->aml;
parser_state->aml = parser_state->pkg_end;
}
break;
case ARGP_TARGET:
case ARGP_SUPERNAME:
case ARGP_SIMPLENAME:
subop = acpi_ps_peek_opcode(parser_state);
if (subop == 0 ||
acpi_ps_is_leading_char(subop) ||
acpi_ps_is_prefix_char(subop)) {
arg = acpi_ps_alloc_op(AML_INT_NAMEPATH_OP);
if (!arg) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
if (walk_state->opcode == AML_UNLOAD_OP) {
status =
acpi_ps_get_next_namepath(walk_state,
parser_state, arg,
1);
if (arg->common.aml_opcode ==
AML_INT_METHODCALL_OP) {
acpi_ps_free_op(arg);
arg = NULL;
}
} else {
status =
acpi_ps_get_next_namepath(walk_state,
parser_state, arg,
0);
}
} else {
walk_state->arg_count = 1;
}
break;
case ARGP_DATAOBJ:
case ARGP_TERMARG:
walk_state->arg_count = 1;
break;
case ARGP_DATAOBJLIST:
case ARGP_TERMLIST:
case ARGP_OBJLIST:
if (parser_state->aml < parser_state->pkg_end) {
walk_state->arg_count = ACPI_VAR_ARGS;
}
break;
default:
ACPI_ERROR((AE_INFO, "Invalid ArgType: 0x%X", arg_type));
status = AE_AML_OPERAND_TYPE;
break;
}
*return_arg = arg;
return_ACPI_STATUS(status);
}
