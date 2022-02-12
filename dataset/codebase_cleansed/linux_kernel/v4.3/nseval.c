acpi_status acpi_ns_evaluate(struct acpi_evaluate_info *info)
{
acpi_status status;
ACPI_FUNCTION_TRACE(ns_evaluate);
if (!info) {
return_ACPI_STATUS(AE_BAD_PARAMETER);
}
if (!info->node) {
status =
acpi_ns_get_node(info->prefix_node, info->relative_pathname,
ACPI_NS_NO_UPSEARCH, &info->node);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
}
if (acpi_ns_get_type(info->node) == ACPI_TYPE_LOCAL_METHOD_ALIAS) {
info->node =
ACPI_CAST_PTR(struct acpi_namespace_node,
info->node->object);
}
info->return_object = NULL;
info->node_flags = info->node->flags;
info->obj_desc = acpi_ns_get_attached_object(info->node);
ACPI_DEBUG_PRINT((ACPI_DB_NAMES, "%s [%p] Value %p\n",
info->relative_pathname, info->node,
acpi_ns_get_attached_object(info->node)));
info->predefined =
acpi_ut_match_predefined_method(info->node->name.ascii);
info->full_pathname = acpi_ns_get_external_pathname(info->node);
if (!info->full_pathname) {
return_ACPI_STATUS(AE_NO_MEMORY);
}
info->param_count = 0;
if (info->parameters) {
while (info->parameters[info->param_count]) {
info->param_count++;
}
if (info->param_count > ACPI_METHOD_NUM_ARGS) {
ACPI_WARN_PREDEFINED((AE_INFO, info->full_pathname,
ACPI_WARN_ALWAYS,
"Excess arguments (%u) - using only %u",
info->param_count,
ACPI_METHOD_NUM_ARGS));
info->param_count = ACPI_METHOD_NUM_ARGS;
}
}
acpi_ns_check_acpi_compliance(info->full_pathname, info->node,
info->predefined);
acpi_ns_check_argument_count(info->full_pathname, info->node,
info->param_count, info->predefined);
acpi_ns_check_argument_types(info);
switch (acpi_ns_get_type(info->node)) {
case ACPI_TYPE_DEVICE:
case ACPI_TYPE_EVENT:
case ACPI_TYPE_MUTEX:
case ACPI_TYPE_REGION:
case ACPI_TYPE_THERMAL:
case ACPI_TYPE_LOCAL_SCOPE:
ACPI_ERROR((AE_INFO,
"%s: Evaluation of object type [%s] is not supported",
info->full_pathname,
acpi_ut_get_type_name(info->node->type)));
status = AE_TYPE;
goto cleanup;
case ACPI_TYPE_METHOD:
if (!info->obj_desc) {
ACPI_ERROR((AE_INFO,
"%s: Method has no attached sub-object",
info->full_pathname));
status = AE_NULL_OBJECT;
goto cleanup;
}
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"**** Execute method [%s] at AML address %p length %X\n",
info->full_pathname,
info->obj_desc->method.aml_start + 1,
info->obj_desc->method.aml_length - 1));
acpi_ex_enter_interpreter();
status = acpi_ps_execute_method(info);
acpi_ex_exit_interpreter();
break;
default:
acpi_ex_enter_interpreter();
info->return_object =
ACPI_CAST_PTR(union acpi_operand_object, info->node);
status =
acpi_ex_resolve_node_to_value(ACPI_CAST_INDIRECT_PTR
(struct acpi_namespace_node,
&info->return_object), NULL);
acpi_ex_exit_interpreter();
if (ACPI_FAILURE(status)) {
info->return_object = NULL;
goto cleanup;
}
ACPI_DEBUG_PRINT((ACPI_DB_NAMES, "Returned object %p [%s]\n",
info->return_object,
acpi_ut_get_object_type_name(info->
return_object)));
status = AE_CTRL_RETURN_VALUE;
break;
}
(void)acpi_ns_check_return_value(info->node, info, info->param_count,
status, &info->return_object);
if (status == AE_CTRL_RETURN_VALUE) {
if (info->flags & ACPI_IGNORE_RETURN_VALUE) {
acpi_ut_remove_reference(info->return_object);
info->return_object = NULL;
}
status = AE_OK;
}
ACPI_DEBUG_PRINT((ACPI_DB_NAMES,
"*** Completed evaluation of object %s ***\n",
info->relative_pathname));
cleanup:
ACPI_FREE(info->full_pathname);
info->full_pathname = NULL;
return_ACPI_STATUS(status);
}
void acpi_ns_exec_module_code_list(void)
{
union acpi_operand_object *prev;
union acpi_operand_object *next;
struct acpi_evaluate_info *info;
u32 method_count = 0;
ACPI_FUNCTION_TRACE(ns_exec_module_code_list);
next = acpi_gbl_module_code_list;
if (!next) {
return_VOID;
}
info = ACPI_ALLOCATE(sizeof(struct acpi_evaluate_info));
if (!info) {
return_VOID;
}
while (next) {
prev = next;
next = next->method.mutex;
prev->method.mutex = NULL;
acpi_ns_exec_module_code(prev, info);
method_count++;
acpi_ut_remove_reference(prev);
}
ACPI_INFO((AE_INFO,
"Executed %u blocks of module-level executable AML code",
method_count));
ACPI_FREE(info);
acpi_gbl_module_code_list = NULL;
return_VOID;
}
static void
acpi_ns_exec_module_code(union acpi_operand_object *method_obj,
struct acpi_evaluate_info *info)
{
union acpi_operand_object *parent_obj;
struct acpi_namespace_node *parent_node;
acpi_object_type type;
acpi_status status;
ACPI_FUNCTION_TRACE(ns_exec_module_code);
parent_node = ACPI_CAST_PTR(struct acpi_namespace_node,
method_obj->method.next_object);
type = acpi_ns_get_type(parent_node);
if ((type == ACPI_TYPE_DEVICE) && parent_node->object) {
method_obj->method.dispatch.handler =
parent_node->object->device.handler;
}
method_obj->method.next_object = NULL;
memset(info, 0, sizeof(struct acpi_evaluate_info));
info->prefix_node = parent_node;
parent_obj = acpi_ns_get_attached_object(parent_node);
if (parent_obj) {
acpi_ut_add_reference(parent_obj);
}
status = acpi_ns_attach_object(parent_node, method_obj,
ACPI_TYPE_METHOD);
if (ACPI_FAILURE(status)) {
goto exit;
}
status = acpi_ns_evaluate(info);
ACPI_DEBUG_PRINT((ACPI_DB_INIT_NAMES,
"Executed module-level code at %p\n",
method_obj->method.aml_start));
if (info->return_object) {
acpi_ut_remove_reference(info->return_object);
}
acpi_ns_detach_object(parent_node);
if (parent_obj) {
status = acpi_ns_attach_object(parent_node, parent_obj, type);
} else {
parent_node->type = (u8)type;
}
exit:
if (parent_obj) {
acpi_ut_remove_reference(parent_obj);
}
return_VOID;
}
