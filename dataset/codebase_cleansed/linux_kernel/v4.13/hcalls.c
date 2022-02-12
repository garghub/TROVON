static char *op_str(unsigned int op, char *name_array[], int array_len)
{
if (op >= array_len)
return "UNKNOWN_OP";
return name_array[op];
}
long cxl_h_attach_process(u64 unit_address,
struct cxl_process_element_hcall *element,
u64 *process_token, u64 *mmio_addr, u64 *mmio_size)
{
unsigned long retbuf[PLPAR_HCALL_BUFSIZE];
long rc;
CXL_H_WAIT_UNTIL_DONE(rc, retbuf, H_ATTACH_CA_PROCESS, unit_address, virt_to_phys(element));
_PRINT_MSG(rc, "cxl_h_attach_process(%#.16llx, %#.16lx): %li\n",
unit_address, virt_to_phys(element), rc);
trace_cxl_hcall_attach(unit_address, virt_to_phys(element), retbuf[0], retbuf[1], retbuf[2], rc);
pr_devel("token: 0x%.8lx mmio_addr: 0x%lx mmio_size: 0x%lx\nProcess Element Structure:\n",
retbuf[0], retbuf[1], retbuf[2]);
cxl_dump_debug_buffer(element, sizeof(*element));
switch (rc) {
case H_SUCCESS:
*process_token = retbuf[0];
if (mmio_addr)
*mmio_addr = retbuf[1];
if (mmio_size)
*mmio_size = retbuf[2];
return 0;
case H_PARAMETER:
case H_FUNCTION:
return -EINVAL;
case H_AUTHORITY:
case H_RESOURCE:
case H_HARDWARE:
case H_STATE:
case H_BUSY:
return -EBUSY;
default:
WARN(1, "Unexpected return code: %lx", rc);
return -EINVAL;
}
}
long cxl_h_detach_process(u64 unit_address, u64 process_token)
{
unsigned long retbuf[PLPAR_HCALL_BUFSIZE];
long rc;
CXL_H_WAIT_UNTIL_DONE(rc, retbuf, H_DETACH_CA_PROCESS, unit_address, process_token);
_PRINT_MSG(rc, "cxl_h_detach_process(%#.16llx, 0x%.8llx): %li\n", unit_address, process_token, rc);
trace_cxl_hcall_detach(unit_address, process_token, rc);
switch (rc) {
case H_SUCCESS:
return 0;
case H_PARAMETER:
return -EINVAL;
case H_AUTHORITY:
case H_RESOURCE:
case H_HARDWARE:
case H_STATE:
case H_BUSY:
return -EBUSY;
default:
WARN(1, "Unexpected return code: %lx", rc);
return -EINVAL;
}
}
static long cxl_h_control_function(u64 unit_address, u64 op,
u64 p1, u64 p2, u64 p3, u64 p4, u64 *out)
{
unsigned long retbuf[PLPAR_HCALL9_BUFSIZE];
long rc;
CXL_H9_WAIT_UNTIL_DONE(rc, retbuf, H_CONTROL_CA_FUNCTION, unit_address, op, p1, p2, p3, p4);
_PRINT_MSG(rc, "cxl_h_control_function(%#.16llx, %s(%#llx, %#llx, %#llx, %#llx, R4: %#lx)): %li\n",
unit_address, OP_STR_AFU(op), p1, p2, p3, p4, retbuf[0], rc);
trace_cxl_hcall_control_function(unit_address, OP_STR_AFU(op), p1, p2, p3, p4, retbuf[0], rc);
switch (rc) {
case H_SUCCESS:
if ((op == H_CONTROL_CA_FUNCTION_GET_FUNCTION_ERR_INT ||
op == H_CONTROL_CA_FUNCTION_READ_ERR_STATE ||
op == H_CONTROL_CA_FUNCTION_COLLECT_VPD))
*out = retbuf[0];
return 0;
case H_PARAMETER:
case H_FUNCTION:
case H_NOT_FOUND:
case H_NOT_AVAILABLE:
case H_SG_LIST:
return -EINVAL;
case H_AUTHORITY:
case H_RESOURCE:
case H_HARDWARE:
case H_STATE:
case H_BUSY:
return -EBUSY;
default:
WARN(1, "Unexpected return code: %lx", rc);
return -EINVAL;
}
}
long cxl_h_reset_afu(u64 unit_address)
{
return cxl_h_control_function(unit_address,
H_CONTROL_CA_FUNCTION_RESET,
0, 0, 0, 0,
NULL);
}
long cxl_h_suspend_process(u64 unit_address, u64 process_token)
{
return cxl_h_control_function(unit_address,
H_CONTROL_CA_FUNCTION_SUSPEND_PROCESS,
process_token, 0, 0, 0,
NULL);
}
long cxl_h_resume_process(u64 unit_address, u64 process_token)
{
return cxl_h_control_function(unit_address,
H_CONTROL_CA_FUNCTION_RESUME_PROCESS,
process_token, 0, 0, 0,
NULL);
}
long cxl_h_read_error_state(u64 unit_address, u64 *state)
{
return cxl_h_control_function(unit_address,
H_CONTROL_CA_FUNCTION_READ_ERR_STATE,
0, 0, 0, 0,
state);
}
long cxl_h_get_afu_err(u64 unit_address, u64 offset,
u64 buf_address, u64 len)
{
return cxl_h_control_function(unit_address,
H_CONTROL_CA_FUNCTION_GET_AFU_ERR,
offset, buf_address, len, 0,
NULL);
}
long cxl_h_get_config(u64 unit_address, u64 cr_num, u64 offset,
u64 buf_address, u64 len)
{
return cxl_h_control_function(unit_address,
H_CONTROL_CA_FUNCTION_GET_CONFIG,
cr_num, offset, buf_address, len,
NULL);
}
long cxl_h_terminate_process(u64 unit_address, u64 process_token)
{
return cxl_h_control_function(unit_address,
H_CONTROL_CA_FUNCTION_TERMINATE_PROCESS,
process_token, 0, 0, 0,
NULL);
}
long cxl_h_collect_vpd(u64 unit_address, u64 record, u64 list_address,
u64 num, u64 *out)
{
return cxl_h_control_function(unit_address,
H_CONTROL_CA_FUNCTION_COLLECT_VPD,
record, list_address, num, 0,
out);
}
long cxl_h_get_fn_error_interrupt(u64 unit_address, u64 *reg)
{
return cxl_h_control_function(unit_address,
H_CONTROL_CA_FUNCTION_GET_FUNCTION_ERR_INT,
0, 0, 0, 0, reg);
}
long cxl_h_ack_fn_error_interrupt(u64 unit_address, u64 value)
{
return cxl_h_control_function(unit_address,
H_CONTROL_CA_FUNCTION_ACK_FUNCTION_ERR_INT,
value, 0, 0, 0,
NULL);
}
long cxl_h_get_error_log(u64 unit_address, u64 value)
{
return cxl_h_control_function(unit_address,
H_CONTROL_CA_FUNCTION_GET_ERROR_LOG,
0, 0, 0, 0,
NULL);
}
long cxl_h_collect_int_info(u64 unit_address, u64 process_token,
struct cxl_irq_info *info)
{
long rc;
BUG_ON(sizeof(*info) != sizeof(unsigned long[PLPAR_HCALL9_BUFSIZE]));
rc = plpar_hcall9(H_COLLECT_CA_INT_INFO, (unsigned long *) info,
unit_address, process_token);
_PRINT_MSG(rc, "cxl_h_collect_int_info(%#.16llx, 0x%llx): %li\n",
unit_address, process_token, rc);
trace_cxl_hcall_collect_int_info(unit_address, process_token, rc);
switch (rc) {
case H_SUCCESS:
pr_devel("dsisr:%#llx, dar:%#llx, dsr:%#llx, pid_tid:%#llx, afu_err:%#llx, errstat:%#llx\n",
info->dsisr, info->dar, info->dsr, info->reserved,
info->afu_err, info->errstat);
return 0;
case H_PARAMETER:
return -EINVAL;
case H_AUTHORITY:
case H_HARDWARE:
case H_STATE:
return -EBUSY;
default:
WARN(1, "Unexpected return code: %lx", rc);
return -EINVAL;
}
}
long cxl_h_control_faults(u64 unit_address, u64 process_token,
u64 control_mask, u64 reset_mask)
{
unsigned long retbuf[PLPAR_HCALL_BUFSIZE];
long rc;
memset(retbuf, 0, sizeof(retbuf));
rc = plpar_hcall(H_CONTROL_CA_FAULTS, retbuf, unit_address,
H_CONTROL_CA_FAULTS_RESPOND_PSL, process_token,
control_mask, reset_mask);
_PRINT_MSG(rc, "cxl_h_control_faults(%#.16llx, 0x%llx, %#llx, %#llx): %li (%#lx)\n",
unit_address, process_token, control_mask, reset_mask,
rc, retbuf[0]);
trace_cxl_hcall_control_faults(unit_address, process_token,
control_mask, reset_mask, retbuf[0], rc);
switch (rc) {
case H_SUCCESS:
return 0;
case H_PARAMETER:
return -EINVAL;
case H_HARDWARE:
case H_STATE:
case H_AUTHORITY:
return -EBUSY;
case H_FUNCTION:
case H_NOT_FOUND:
return -EINVAL;
default:
WARN(1, "Unexpected return code: %lx", rc);
return -EINVAL;
}
}
static long cxl_h_control_facility(u64 unit_address, u64 op,
u64 p1, u64 p2, u64 p3, u64 p4, u64 *out)
{
unsigned long retbuf[PLPAR_HCALL9_BUFSIZE];
long rc;
CXL_H9_WAIT_UNTIL_DONE(rc, retbuf, H_CONTROL_CA_FACILITY, unit_address, op, p1, p2, p3, p4);
_PRINT_MSG(rc, "cxl_h_control_facility(%#.16llx, %s(%#llx, %#llx, %#llx, %#llx, R4: %#lx)): %li\n",
unit_address, OP_STR_CONTROL_ADAPTER(op), p1, p2, p3, p4, retbuf[0], rc);
trace_cxl_hcall_control_facility(unit_address, OP_STR_CONTROL_ADAPTER(op), p1, p2, p3, p4, retbuf[0], rc);
switch (rc) {
case H_SUCCESS:
if (op == H_CONTROL_CA_FACILITY_COLLECT_VPD)
*out = retbuf[0];
return 0;
case H_PARAMETER:
case H_FUNCTION:
case H_NOT_FOUND:
case H_NOT_AVAILABLE:
case H_SG_LIST:
return -EINVAL;
case H_AUTHORITY:
case H_RESOURCE:
case H_HARDWARE:
case H_STATE:
case H_BUSY:
return -EBUSY;
default:
WARN(1, "Unexpected return code: %lx", rc);
return -EINVAL;
}
}
long cxl_h_reset_adapter(u64 unit_address)
{
return cxl_h_control_facility(unit_address,
H_CONTROL_CA_FACILITY_RESET,
0, 0, 0, 0,
NULL);
}
long cxl_h_collect_vpd_adapter(u64 unit_address, u64 list_address,
u64 num, u64 *out)
{
return cxl_h_control_facility(unit_address,
H_CONTROL_CA_FACILITY_COLLECT_VPD,
list_address, num, 0, 0,
out);
}
static long cxl_h_download_facility(u64 unit_address, u64 op,
u64 list_address, u64 num,
u64 *out)
{
unsigned long retbuf[PLPAR_HCALL_BUFSIZE];
unsigned int delay, total_delay = 0;
u64 token = 0;
long rc;
if (*out != 0)
token = *out;
memset(retbuf, 0, sizeof(retbuf));
while (1) {
rc = plpar_hcall(H_DOWNLOAD_CA_FACILITY, retbuf,
unit_address, op, list_address, num,
token);
token = retbuf[0];
if (rc != H_BUSY && !H_IS_LONG_BUSY(rc))
break;
if (rc != H_BUSY) {
delay = get_longbusy_msecs(rc);
total_delay += delay;
if (total_delay > CXL_HCALL_TIMEOUT_DOWNLOAD) {
WARN(1, "Warning: Giving up waiting for CXL hcall "
"%#x after %u msec\n",
H_DOWNLOAD_CA_FACILITY, total_delay);
rc = H_BUSY;
break;
}
msleep(delay);
}
}
_PRINT_MSG(rc, "cxl_h_download_facility(%#.16llx, %s(%#llx, %#llx), %#lx): %li\n",
unit_address, OP_STR_DOWNLOAD_ADAPTER(op), list_address, num, retbuf[0], rc);
trace_cxl_hcall_download_facility(unit_address, OP_STR_DOWNLOAD_ADAPTER(op), list_address, num, retbuf[0], rc);
switch (rc) {
case H_SUCCESS:
return 0;
case H_PARAMETER:
case H_FUNCTION:
case H_SG_LIST:
case H_BAD_DATA:
return -EINVAL;
case H_AUTHORITY:
case H_RESOURCE:
case H_HARDWARE:
case H_STATE:
case H_BUSY:
return -EBUSY;
case H_CONTINUE:
*out = retbuf[0];
return 1;
default:
WARN(1, "Unexpected return code: %lx", rc);
return -EINVAL;
}
}
long cxl_h_download_adapter_image(u64 unit_address,
u64 list_address, u64 num,
u64 *out)
{
return cxl_h_download_facility(unit_address,
H_DOWNLOAD_CA_FACILITY_DOWNLOAD,
list_address, num, out);
}
long cxl_h_validate_adapter_image(u64 unit_address,
u64 list_address, u64 num,
u64 *out)
{
return cxl_h_download_facility(unit_address,
H_DOWNLOAD_CA_FACILITY_VALIDATE,
list_address, num, out);
}
