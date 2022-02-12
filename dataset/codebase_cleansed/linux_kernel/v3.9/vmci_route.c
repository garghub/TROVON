int vmci_route(struct vmci_handle *src,
const struct vmci_handle *dst,
bool from_guest,
enum vmci_route *route)
{
bool has_host_device = vmci_host_code_active();
bool has_guest_device = vmci_guest_code_active();
*route = VMCI_ROUTE_NONE;
if (VMCI_INVALID_ID == dst->context)
return VMCI_ERROR_INVALID_ARGS;
if (VMCI_HYPERVISOR_CONTEXT_ID == dst->context) {
if (from_guest)
return VMCI_ERROR_DST_UNREACHABLE;
if (!has_guest_device)
return VMCI_ERROR_DEVICE_NOT_FOUND;
if (VMCI_HOST_CONTEXT_ID == src->context)
return VMCI_ERROR_INVALID_ARGS;
if (VMCI_INVALID_ID == src->context &&
VMCI_INVALID_ID != src->resource)
src->context = vmci_get_context_id();
*route = VMCI_ROUTE_AS_GUEST;
return VMCI_SUCCESS;
}
if (VMCI_HOST_CONTEXT_ID == dst->context) {
if (src->context == VMCI_HYPERVISOR_CONTEXT_ID) {
if (has_host_device) {
*route = VMCI_ROUTE_AS_HOST;
return VMCI_SUCCESS;
} else {
return VMCI_ERROR_DEVICE_NOT_FOUND;
}
}
if (!from_guest && has_guest_device) {
if (VMCI_INVALID_ID == src->context)
src->context = vmci_get_context_id();
*route = VMCI_ROUTE_AS_GUEST;
return VMCI_SUCCESS;
}
if (!has_host_device)
return VMCI_ERROR_DEVICE_NOT_FOUND;
if (VMCI_INVALID_ID == src->context) {
if (from_guest)
return VMCI_ERROR_INVALID_ARGS;
src->context = VMCI_HOST_CONTEXT_ID;
}
*route = VMCI_ROUTE_AS_HOST;
return VMCI_SUCCESS;
}
if (has_host_device) {
if (vmci_ctx_exists(dst->context)) {
if (VMCI_INVALID_ID == src->context) {
if (from_guest)
return VMCI_ERROR_INVALID_ARGS;
src->context = VMCI_HOST_CONTEXT_ID;
} else if (VMCI_CONTEXT_IS_VM(src->context) &&
src->context != dst->context) {
return VMCI_ERROR_DST_UNREACHABLE;
}
*route = VMCI_ROUTE_AS_HOST;
return VMCI_SUCCESS;
} else if (!has_guest_device) {
return VMCI_ERROR_DST_UNREACHABLE;
}
}
if (!has_guest_device) {
return VMCI_ERROR_DEVICE_NOT_FOUND;
}
if (VMCI_INVALID_ID == src->context)
src->context = vmci_get_context_id();
*route = VMCI_ROUTE_AS_GUEST;
return VMCI_SUCCESS;
}
