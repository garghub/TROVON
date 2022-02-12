static u8
acpi_ex_do_match(u32 match_op,
union acpi_operand_object *package_obj,
union acpi_operand_object *match_obj)
{
u8 logical_result = TRUE;
acpi_status status;
switch (match_op) {
case MATCH_MTR:
break;
case MATCH_MEQ:
status =
acpi_ex_do_logical_op(AML_LEQUAL_OP, match_obj, package_obj,
&logical_result);
if (ACPI_FAILURE(status)) {
return (FALSE);
}
break;
case MATCH_MLE:
status =
acpi_ex_do_logical_op(AML_LLESS_OP, match_obj, package_obj,
&logical_result);
if (ACPI_FAILURE(status)) {
return (FALSE);
}
logical_result = (u8) ! logical_result;
break;
case MATCH_MLT:
status =
acpi_ex_do_logical_op(AML_LGREATER_OP, match_obj,
package_obj, &logical_result);
if (ACPI_FAILURE(status)) {
return (FALSE);
}
break;
case MATCH_MGE:
status =
acpi_ex_do_logical_op(AML_LGREATER_OP, match_obj,
package_obj, &logical_result);
if (ACPI_FAILURE(status)) {
return (FALSE);
}
logical_result = (u8) ! logical_result;
break;
case MATCH_MGT:
status =
acpi_ex_do_logical_op(AML_LLESS_OP, match_obj, package_obj,
&logical_result);
if (ACPI_FAILURE(status)) {
return (FALSE);
}
break;
default:
return (FALSE);
}
return (logical_result);
}
acpi_status acpi_ex_opcode_6A_0T_1R(struct acpi_walk_state * walk_state)
{
union acpi_operand_object **operand = &walk_state->operands[0];
union acpi_operand_object *return_desc = NULL;
acpi_status status = AE_OK;
u64 index;
union acpi_operand_object *this_element;
ACPI_FUNCTION_TRACE_STR(ex_opcode_6A_0T_1R,
acpi_ps_get_opcode_name(walk_state->opcode));
switch (walk_state->opcode) {
case AML_MATCH_OP:
if ((operand[1]->integer.value > MAX_MATCH_OPERATOR) ||
(operand[3]->integer.value > MAX_MATCH_OPERATOR)) {
ACPI_ERROR((AE_INFO, "Match operator out of range"));
status = AE_AML_OPERAND_VALUE;
goto cleanup;
}
index = operand[5]->integer.value;
if (index >= operand[0]->package.count) {
ACPI_ERROR((AE_INFO,
"Index (0x%8.8X%8.8X) beyond package end (0x%X)",
ACPI_FORMAT_UINT64(index),
operand[0]->package.count));
status = AE_AML_PACKAGE_LIMIT;
goto cleanup;
}
return_desc = acpi_ut_create_integer_object(ACPI_UINT64_MAX);
if (!return_desc) {
status = AE_NO_MEMORY;
goto cleanup;
}
for (; index < operand[0]->package.count; index++) {
this_element = operand[0]->package.elements[index];
if (!this_element) {
continue;
}
if (!acpi_ex_do_match((u32) operand[1]->integer.value,
this_element, operand[2])) {
continue;
}
if (!acpi_ex_do_match((u32) operand[3]->integer.value,
this_element, operand[4])) {
continue;
}
return_desc->integer.value = index;
break;
}
break;
case AML_LOAD_TABLE_OP:
status = acpi_ex_load_table_op(walk_state, &return_desc);
break;
default:
ACPI_ERROR((AE_INFO, "Unknown AML opcode 0x%X",
walk_state->opcode));
status = AE_AML_BAD_OPCODE;
goto cleanup;
}
cleanup:
if (ACPI_FAILURE(status)) {
acpi_ut_remove_reference(return_desc);
}
else {
walk_state->result_obj = return_desc;
}
return_ACPI_STATUS(status);
}
