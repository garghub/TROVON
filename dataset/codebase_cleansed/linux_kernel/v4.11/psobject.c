static acpi_status acpi_ps_get_aml_opcode(struct acpi_walk_state *walk_state)
{
u32 aml_offset;
ACPI_FUNCTION_TRACE_PTR(ps_get_aml_opcode, walk_state);
walk_state->aml = walk_state->parser_state.aml;
walk_state->opcode = acpi_ps_peek_opcode(&(walk_state->parser_state));
walk_state->op_info = acpi_ps_get_opcode_info(walk_state->opcode);
switch (walk_state->op_info->class) {
case AML_CLASS_ASCII:
case AML_CLASS_PREFIX:
walk_state->opcode = AML_INT_NAMEPATH_OP;
walk_state->arg_types = ARGP_NAMESTRING;
break;
case AML_CLASS_UNKNOWN:
if (walk_state->pass_number == 2) {
aml_offset = (u32)ACPI_PTR_DIFF(walk_state->aml,
walk_state->
parser_state.aml_start);
ACPI_ERROR((AE_INFO,
"Unknown opcode 0x%.2X at table offset 0x%.4X, ignoring",
walk_state->opcode,
(u32)(aml_offset +
sizeof(struct acpi_table_header))));
ACPI_DUMP_BUFFER((walk_state->parser_state.aml - 16),
48);
#ifdef ACPI_ASL_COMPILER
acpi_os_printf
("/*\nError: Unknown opcode 0x%.2X at table offset 0x%.4X, context:\n",
walk_state->opcode,
(u32)(aml_offset +
sizeof(struct acpi_table_header)));
acpi_ut_dump_buffer(((u8 *)walk_state->parser_state.
aml - 16), 48, DB_BYTE_DISPLAY,
(aml_offset +
sizeof(struct acpi_table_header) -
16));
acpi_os_printf(" */\n");
#endif
}
walk_state->parser_state.aml++;
if (walk_state->opcode > 0xFF) {
walk_state->parser_state.aml++;
}
return_ACPI_STATUS(AE_CTRL_PARSE_CONTINUE);
default:
walk_state->parser_state.aml +=
acpi_ps_get_opcode_size(walk_state->opcode);
walk_state->arg_types = walk_state->op_info->parse_args;
break;
}
return_ACPI_STATUS(AE_OK);
}
acpi_status
acpi_ps_build_named_op(struct acpi_walk_state *walk_state,
u8 *aml_op_start,
union acpi_parse_object *unnamed_op,
union acpi_parse_object **op)
{
acpi_status status = AE_OK;
union acpi_parse_object *arg = NULL;
ACPI_FUNCTION_TRACE_PTR(ps_build_named_op, walk_state);
unnamed_op->common.value.arg = NULL;
unnamed_op->common.arg_list_length = 0;
unnamed_op->common.aml_opcode = walk_state->opcode;
while (GET_CURRENT_ARG_TYPE(walk_state->arg_types) &&
(GET_CURRENT_ARG_TYPE(walk_state->arg_types) != ARGP_NAME)) {
status =
acpi_ps_get_next_arg(walk_state,
&(walk_state->parser_state),
GET_CURRENT_ARG_TYPE(walk_state->
arg_types), &arg);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
acpi_ps_append_arg(unnamed_op, arg);
INCREMENT_ARG_LIST(walk_state->arg_types);
}
if (!GET_CURRENT_ARG_TYPE(walk_state->arg_types)) {
return_ACPI_STATUS(AE_AML_NO_OPERAND);
}
INCREMENT_ARG_LIST(walk_state->arg_types);
walk_state->op = NULL;
status = walk_state->descending_callback(walk_state, op);
if (ACPI_FAILURE(status)) {
if (status != AE_CTRL_TERMINATE) {
ACPI_EXCEPTION((AE_INFO, status,
"During name lookup/catalog"));
}
return_ACPI_STATUS(status);
}
if (!*op) {
return_ACPI_STATUS(AE_CTRL_PARSE_CONTINUE);
}
status = acpi_ps_next_parse_state(walk_state, *op, status);
if (ACPI_FAILURE(status)) {
if (status == AE_CTRL_PENDING) {
status = AE_CTRL_PARSE_PENDING;
}
return_ACPI_STATUS(status);
}
acpi_ps_append_arg(*op, unnamed_op->common.value.arg);
if ((*op)->common.aml_opcode == AML_REGION_OP ||
(*op)->common.aml_opcode == AML_DATA_REGION_OP) {
(*op)->named.data = aml_op_start;
(*op)->named.length = 0;
}
return_ACPI_STATUS(AE_OK);
}
acpi_status
acpi_ps_create_op(struct acpi_walk_state *walk_state,
u8 *aml_op_start, union acpi_parse_object **new_op)
{
acpi_status status = AE_OK;
union acpi_parse_object *op;
union acpi_parse_object *named_op = NULL;
union acpi_parse_object *parent_scope;
u8 argument_count;
const struct acpi_opcode_info *op_info;
ACPI_FUNCTION_TRACE_PTR(ps_create_op, walk_state);
status = acpi_ps_get_aml_opcode(walk_state);
if (status == AE_CTRL_PARSE_CONTINUE) {
return_ACPI_STATUS(AE_CTRL_PARSE_CONTINUE);
}
walk_state->op_info = acpi_ps_get_opcode_info(walk_state->opcode);
op = acpi_ps_alloc_op(walk_state->opcode, aml_op_start);
if (!op) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
if (walk_state->op_info->flags & AML_NAMED) {
status =
acpi_ps_build_named_op(walk_state, aml_op_start, op,
&named_op);
acpi_ps_free_op(op);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
*new_op = named_op;
return_ACPI_STATUS(AE_OK);
}
if (walk_state->op_info->flags & AML_CREATE) {
op->named.data = aml_op_start;
op->named.length = 0;
}
if (walk_state->opcode == AML_BANK_FIELD_OP) {
op->named.data = aml_op_start;
op->named.length = 0;
}
parent_scope = acpi_ps_get_parent_scope(&(walk_state->parser_state));
acpi_ps_append_arg(parent_scope, op);
if (parent_scope) {
op_info =
acpi_ps_get_opcode_info(parent_scope->common.aml_opcode);
if (op_info->flags & AML_HAS_TARGET) {
argument_count =
acpi_ps_get_argument_count(op_info->type);
if (parent_scope->common.arg_list_length >
argument_count) {
op->common.flags |= ACPI_PARSEOP_TARGET;
}
}
else if ((parent_scope->common.aml_opcode == AML_INCREMENT_OP)
|| (parent_scope->common.aml_opcode ==
AML_DECREMENT_OP)) {
op->common.flags |= ACPI_PARSEOP_TARGET;
}
}
if (walk_state->descending_callback != NULL) {
walk_state->op = *new_op = op;
status = walk_state->descending_callback(walk_state, &op);
status = acpi_ps_next_parse_state(walk_state, op, status);
if (status == AE_CTRL_PENDING) {
status = AE_CTRL_PARSE_PENDING;
}
}
return_ACPI_STATUS(status);
}
acpi_status
acpi_ps_complete_op(struct acpi_walk_state *walk_state,
union acpi_parse_object **op, acpi_status status)
{
acpi_status status2;
ACPI_FUNCTION_TRACE_PTR(ps_complete_op, walk_state);
walk_state->parser_state.scope->parse_scope.arg_count--;
status2 = acpi_ps_complete_this_op(walk_state, *op);
if (ACPI_FAILURE(status2)) {
return_ACPI_STATUS(status2);
}
*op = NULL;
switch (status) {
case AE_OK:
break;
case AE_CTRL_TRANSFER:
walk_state->prev_op = NULL;
walk_state->prev_arg_types = walk_state->arg_types;
return_ACPI_STATUS(status);
case AE_CTRL_END:
acpi_ps_pop_scope(&(walk_state->parser_state), op,
&walk_state->arg_types,
&walk_state->arg_count);
if (*op) {
walk_state->op = *op;
walk_state->op_info =
acpi_ps_get_opcode_info((*op)->common.aml_opcode);
walk_state->opcode = (*op)->common.aml_opcode;
status = walk_state->ascending_callback(walk_state);
status =
acpi_ps_next_parse_state(walk_state, *op, status);
status2 = acpi_ps_complete_this_op(walk_state, *op);
if (ACPI_FAILURE(status2)) {
return_ACPI_STATUS(status2);
}
}
status = AE_OK;
break;
case AE_CTRL_BREAK:
case AE_CTRL_CONTINUE:
while (!(*op) || ((*op)->common.aml_opcode != AML_WHILE_OP)) {
acpi_ps_pop_scope(&(walk_state->parser_state), op,
&walk_state->arg_types,
&walk_state->arg_count);
}
walk_state->op = *op;
walk_state->op_info =
acpi_ps_get_opcode_info((*op)->common.aml_opcode);
walk_state->opcode = (*op)->common.aml_opcode;
status = walk_state->ascending_callback(walk_state);
status = acpi_ps_next_parse_state(walk_state, *op, status);
status2 = acpi_ps_complete_this_op(walk_state, *op);
if (ACPI_FAILURE(status2)) {
return_ACPI_STATUS(status2);
}
status = AE_OK;
break;
case AE_CTRL_TERMINATE:
do {
if (*op) {
status2 =
acpi_ps_complete_this_op(walk_state, *op);
if (ACPI_FAILURE(status2)) {
return_ACPI_STATUS(status2);
}
acpi_ut_delete_generic_state
(acpi_ut_pop_generic_state
(&walk_state->control_state));
}
acpi_ps_pop_scope(&(walk_state->parser_state), op,
&walk_state->arg_types,
&walk_state->arg_count);
} while (*op);
return_ACPI_STATUS(AE_OK);
default:
do {
if (*op) {
status2 =
acpi_ps_complete_this_op(walk_state, *op);
if (ACPI_FAILURE(status2)) {
return_ACPI_STATUS(status2);
}
}
acpi_ps_pop_scope(&(walk_state->parser_state), op,
&walk_state->arg_types,
&walk_state->arg_count);
} while (*op);
#if 0
if (*op == NULL) {
acpi_ps_pop_scope(parser_state, op,
&walk_state->arg_types,
&walk_state->arg_count);
}
#endif
walk_state->prev_op = NULL;
walk_state->prev_arg_types = walk_state->arg_types;
return_ACPI_STATUS(status);
}
if (acpi_ps_has_completed_scope(&(walk_state->parser_state))) {
acpi_ps_pop_scope(&(walk_state->parser_state), op,
&walk_state->arg_types,
&walk_state->arg_count);
ACPI_DEBUG_PRINT((ACPI_DB_PARSE, "Popped scope, Op=%p\n", *op));
} else {
*op = NULL;
}
return_ACPI_STATUS(AE_OK);
}
acpi_status
acpi_ps_complete_final_op(struct acpi_walk_state *walk_state,
union acpi_parse_object *op, acpi_status status)
{
acpi_status status2;
ACPI_FUNCTION_TRACE_PTR(ps_complete_final_op, walk_state);
ACPI_DEBUG_PRINT((ACPI_DB_PARSE, "AML package complete at Op %p\n",
op));
do {
if (op) {
if (walk_state->ascending_callback != NULL) {
walk_state->op = op;
walk_state->op_info =
acpi_ps_get_opcode_info(op->common.
aml_opcode);
walk_state->opcode = op->common.aml_opcode;
status =
walk_state->ascending_callback(walk_state);
status =
acpi_ps_next_parse_state(walk_state, op,
status);
if (status == AE_CTRL_PENDING) {
status =
acpi_ps_complete_op(walk_state, &op,
AE_OK);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
}
if (status == AE_CTRL_TERMINATE) {
status = AE_OK;
do {
if (op) {
status2 =
acpi_ps_complete_this_op
(walk_state, op);
if (ACPI_FAILURE
(status2)) {
return_ACPI_STATUS
(status2);
}
}
acpi_ps_pop_scope(&
(walk_state->
parser_state),
&op,
&walk_state->
arg_types,
&walk_state->
arg_count);
} while (op);
return_ACPI_STATUS(status);
}
else if (ACPI_FAILURE(status)) {
(void)
acpi_ps_complete_this_op(walk_state,
op);
return_ACPI_STATUS(status);
}
}
status2 = acpi_ps_complete_this_op(walk_state, op);
if (ACPI_FAILURE(status2)) {
return_ACPI_STATUS(status2);
}
}
acpi_ps_pop_scope(&(walk_state->parser_state), &op,
&walk_state->arg_types,
&walk_state->arg_count);
} while (op);
return_ACPI_STATUS(status);
}
