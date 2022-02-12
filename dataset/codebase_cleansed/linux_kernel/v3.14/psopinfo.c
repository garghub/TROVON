const struct acpi_opcode_info *acpi_ps_get_opcode_info(u16 opcode)
{
#ifdef ACPI_DEBUG_OUTPUT
const char *opcode_name = "Unknown AML opcode";
#endif
ACPI_FUNCTION_NAME(ps_get_opcode_info);
if (!(opcode & 0xFF00)) {
return (&acpi_gbl_aml_op_info
[acpi_gbl_short_op_index[(u8)opcode]]);
}
if (((opcode & 0xFF00) == AML_EXTENDED_OPCODE) &&
(((u8)opcode) <= MAX_EXTENDED_OPCODE)) {
return (&acpi_gbl_aml_op_info
[acpi_gbl_long_op_index[(u8)opcode]]);
}
#if defined ACPI_ASL_COMPILER && defined ACPI_DEBUG_OUTPUT
#include "asldefine.h"
switch (opcode) {
case AML_RAW_DATA_BYTE:
opcode_name = "-Raw Data Byte-";
break;
case AML_RAW_DATA_WORD:
opcode_name = "-Raw Data Word-";
break;
case AML_RAW_DATA_DWORD:
opcode_name = "-Raw Data Dword-";
break;
case AML_RAW_DATA_QWORD:
opcode_name = "-Raw Data Qword-";
break;
case AML_RAW_DATA_BUFFER:
opcode_name = "-Raw Data Buffer-";
break;
case AML_RAW_DATA_CHAIN:
opcode_name = "-Raw Data Buffer Chain-";
break;
case AML_PACKAGE_LENGTH:
opcode_name = "-Package Length-";
break;
case AML_UNASSIGNED_OPCODE:
opcode_name = "-Unassigned Opcode-";
break;
case AML_DEFAULT_ARG_OP:
opcode_name = "-Default Arg-";
break;
default:
break;
}
#endif
ACPI_DEBUG_PRINT((ACPI_DB_EXEC, "%s [%4.4X]\n", opcode_name, opcode));
return (&acpi_gbl_aml_op_info[_UNK]);
}
char *acpi_ps_get_opcode_name(u16 opcode)
{
#if defined(ACPI_DISASSEMBLER) || defined (ACPI_DEBUG_OUTPUT)
const struct acpi_opcode_info *op;
op = acpi_ps_get_opcode_info(opcode);
return (op->name);
#else
return ("OpcodeName unavailable");
#endif
}
u8 acpi_ps_get_argument_count(u32 op_type)
{
if (op_type <= AML_TYPE_EXEC_6A_0T_1R) {
return (acpi_gbl_argument_count[op_type]);
}
return (0);
}
