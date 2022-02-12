acpi_status acpi_ex_opcode_3A_0T_0R(struct acpi_walk_state *walk_state)
{
union acpi_operand_object **operand = &walk_state->operands[0];
struct acpi_signal_fatal_info *fatal;
acpi_status status = AE_OK;
ACPI_FUNCTION_TRACE_STR(ex_opcode_3A_0T_0R,
acpi_ps_get_opcode_name(walk_state->opcode));
switch (walk_state->opcode) {
case AML_FATAL_OP:
ACPI_DEBUG_PRINT((ACPI_DB_INFO,
"FatalOp: Type %X Code %X Arg %X "
"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n",
(u32)operand[0]->integer.value,
(u32)operand[1]->integer.value,
(u32)operand[2]->integer.value));
fatal = ACPI_ALLOCATE(sizeof(struct acpi_signal_fatal_info));
if (fatal) {
fatal->type = (u32) operand[0]->integer.value;
fatal->code = (u32) operand[1]->integer.value;
fatal->argument = (u32) operand[2]->integer.value;
}
status = acpi_os_signal(ACPI_SIGNAL_FATAL, fatal);
ACPI_FREE(fatal);
goto cleanup;
case AML_EXTERNAL_OP:
ACPI_ERROR((AE_INFO, "Executed External Op"));
status = AE_OK;
goto cleanup;
default:
ACPI_ERROR((AE_INFO, "Unknown AML opcode 0x%X",
walk_state->opcode));
status = AE_AML_BAD_OPCODE;
goto cleanup;
}
cleanup:
return_ACPI_STATUS(status);
}
acpi_status acpi_ex_opcode_3A_1T_1R(struct acpi_walk_state *walk_state)
{
union acpi_operand_object **operand = &walk_state->operands[0];
union acpi_operand_object *return_desc = NULL;
char *buffer = NULL;
acpi_status status = AE_OK;
u64 index;
acpi_size length;
ACPI_FUNCTION_TRACE_STR(ex_opcode_3A_1T_1R,
acpi_ps_get_opcode_name(walk_state->opcode));
switch (walk_state->opcode) {
case AML_MID_OP:
return_desc = acpi_ut_create_internal_object((operand[0])->
common.type);
if (!return_desc) {
status = AE_NO_MEMORY;
goto cleanup;
}
index = operand[1]->integer.value;
length = (acpi_size) operand[2]->integer.value;
if (index >= operand[0]->string.length) {
length = 0;
}
else if ((index + length) > operand[0]->string.length) {
length =
(acpi_size) operand[0]->string.length -
(acpi_size) index;
}
switch ((operand[0])->common.type) {
case ACPI_TYPE_STRING:
buffer = ACPI_ALLOCATE_ZEROED((acpi_size) length + 1);
if (!buffer) {
status = AE_NO_MEMORY;
goto cleanup;
}
break;
case ACPI_TYPE_BUFFER:
if (length > 0) {
buffer = ACPI_ALLOCATE_ZEROED(length);
if (!buffer) {
status = AE_NO_MEMORY;
goto cleanup;
}
}
break;
default:
status = AE_AML_OPERAND_TYPE;
goto cleanup;
}
if (buffer) {
memcpy(buffer,
operand[0]->string.pointer + index, length);
}
return_desc->string.pointer = buffer;
return_desc->string.length = (u32) length;
return_desc->buffer.flags |= AOPOBJ_DATA_VALID;
break;
default:
ACPI_ERROR((AE_INFO, "Unknown AML opcode 0x%X",
walk_state->opcode));
status = AE_AML_BAD_OPCODE;
goto cleanup;
}
status = acpi_ex_store(return_desc, operand[3], walk_state);
cleanup:
if (ACPI_FAILURE(status) || walk_state->result_obj) {
acpi_ut_remove_reference(return_desc);
walk_state->result_obj = NULL;
} else {
walk_state->result_obj = return_desc;
}
return_ACPI_STATUS(status);
}
