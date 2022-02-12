static enum smi_action __smi_handle_dr_smp_send(bool is_switch, int port_num,
u8 *hop_ptr, u8 hop_cnt,
const u8 *initial_path,
const u8 *return_path,
u8 direction,
bool dr_dlid_is_permissive,
bool dr_slid_is_permissive)
{
if (hop_cnt >= IB_SMP_MAX_PATH_HOPS)
return IB_SMI_DISCARD;
if (!direction) {
if (hop_cnt && *hop_ptr == 0) {
(*hop_ptr)++;
return (initial_path[*hop_ptr] ==
port_num ? IB_SMI_HANDLE : IB_SMI_DISCARD);
}
if (*hop_ptr && *hop_ptr < hop_cnt) {
if (!is_switch)
return IB_SMI_DISCARD;
(*hop_ptr)++;
return (initial_path[*hop_ptr] ==
port_num ? IB_SMI_HANDLE : IB_SMI_DISCARD);
}
if (*hop_ptr == hop_cnt) {
(*hop_ptr)++;
return (is_switch ||
dr_dlid_is_permissive ?
IB_SMI_HANDLE : IB_SMI_DISCARD);
}
return (*hop_ptr == hop_cnt + 1 ? IB_SMI_HANDLE : IB_SMI_DISCARD);
} else {
if (hop_cnt && *hop_ptr == hop_cnt + 1) {
(*hop_ptr)--;
return (return_path[*hop_ptr] ==
port_num ? IB_SMI_HANDLE : IB_SMI_DISCARD);
}
if (2 <= *hop_ptr && *hop_ptr <= hop_cnt) {
if (!is_switch)
return IB_SMI_DISCARD;
(*hop_ptr)--;
return (return_path[*hop_ptr] ==
port_num ? IB_SMI_HANDLE : IB_SMI_DISCARD);
}
if (*hop_ptr == 1) {
(*hop_ptr)--;
return (is_switch ||
dr_slid_is_permissive ?
IB_SMI_HANDLE : IB_SMI_DISCARD);
}
if (*hop_ptr == 0)
return IB_SMI_HANDLE;
return IB_SMI_DISCARD;
}
}
enum smi_action smi_handle_dr_smp_send(struct ib_smp *smp,
bool is_switch, int port_num)
{
return __smi_handle_dr_smp_send(is_switch, port_num,
&smp->hop_ptr, smp->hop_cnt,
smp->initial_path,
smp->return_path,
ib_get_smp_direction(smp),
smp->dr_dlid == IB_LID_PERMISSIVE,
smp->dr_slid == IB_LID_PERMISSIVE);
}
enum smi_action opa_smi_handle_dr_smp_send(struct opa_smp *smp,
bool is_switch, int port_num)
{
return __smi_handle_dr_smp_send(is_switch, port_num,
&smp->hop_ptr, smp->hop_cnt,
smp->route.dr.initial_path,
smp->route.dr.return_path,
opa_get_smp_direction(smp),
smp->route.dr.dr_dlid ==
OPA_LID_PERMISSIVE,
smp->route.dr.dr_slid ==
OPA_LID_PERMISSIVE);
}
static enum smi_action __smi_handle_dr_smp_recv(bool is_switch, int port_num,
int phys_port_cnt,
u8 *hop_ptr, u8 hop_cnt,
const u8 *initial_path,
u8 *return_path,
u8 direction,
bool dr_dlid_is_permissive,
bool dr_slid_is_permissive)
{
if (hop_cnt >= IB_SMP_MAX_PATH_HOPS)
return IB_SMI_DISCARD;
if (!direction) {
if (hop_cnt && *hop_ptr == 0)
return IB_SMI_DISCARD;
if (*hop_ptr && *hop_ptr < hop_cnt) {
if (!is_switch)
return IB_SMI_DISCARD;
return_path[*hop_ptr] = port_num;
return (initial_path[*hop_ptr+1] <= phys_port_cnt ?
IB_SMI_HANDLE : IB_SMI_DISCARD);
}
if (*hop_ptr == hop_cnt) {
if (hop_cnt)
return_path[*hop_ptr] = port_num;
return (is_switch ||
dr_dlid_is_permissive ?
IB_SMI_HANDLE : IB_SMI_DISCARD);
}
return (*hop_ptr == hop_cnt + 1 ? IB_SMI_HANDLE : IB_SMI_DISCARD);
} else {
if (hop_cnt && *hop_ptr == hop_cnt + 1) {
(*hop_ptr)--;
return (return_path[*hop_ptr] ==
port_num ? IB_SMI_HANDLE : IB_SMI_DISCARD);
}
if (2 <= *hop_ptr && *hop_ptr <= hop_cnt) {
if (!is_switch)
return IB_SMI_DISCARD;
return (return_path[*hop_ptr-1] <= phys_port_cnt ?
IB_SMI_HANDLE : IB_SMI_DISCARD);
}
if (*hop_ptr == 1) {
if (dr_slid_is_permissive) {
(*hop_ptr)--;
return IB_SMI_HANDLE;
}
return (is_switch ? IB_SMI_HANDLE : IB_SMI_DISCARD);
}
return (*hop_ptr == 0 ? IB_SMI_HANDLE : IB_SMI_DISCARD);
}
}
enum smi_action smi_handle_dr_smp_recv(struct ib_smp *smp, bool is_switch,
int port_num, int phys_port_cnt)
{
return __smi_handle_dr_smp_recv(is_switch, port_num, phys_port_cnt,
&smp->hop_ptr, smp->hop_cnt,
smp->initial_path,
smp->return_path,
ib_get_smp_direction(smp),
smp->dr_dlid == IB_LID_PERMISSIVE,
smp->dr_slid == IB_LID_PERMISSIVE);
}
enum smi_action opa_smi_handle_dr_smp_recv(struct opa_smp *smp, bool is_switch,
int port_num, int phys_port_cnt)
{
return __smi_handle_dr_smp_recv(is_switch, port_num, phys_port_cnt,
&smp->hop_ptr, smp->hop_cnt,
smp->route.dr.initial_path,
smp->route.dr.return_path,
opa_get_smp_direction(smp),
smp->route.dr.dr_dlid ==
OPA_LID_PERMISSIVE,
smp->route.dr.dr_slid ==
OPA_LID_PERMISSIVE);
}
static enum smi_forward_action __smi_check_forward_dr_smp(u8 hop_ptr, u8 hop_cnt,
u8 direction,
bool dr_dlid_is_permissive,
bool dr_slid_is_permissive)
{
if (!direction) {
if (hop_ptr && hop_ptr < hop_cnt)
return IB_SMI_FORWARD;
if (hop_ptr == hop_cnt)
return (dr_dlid_is_permissive ?
IB_SMI_SEND : IB_SMI_LOCAL);
if (hop_ptr == hop_cnt + 1)
return IB_SMI_SEND;
} else {
if (2 <= hop_ptr && hop_ptr <= hop_cnt)
return IB_SMI_FORWARD;
if (hop_ptr == 1)
return (!dr_slid_is_permissive ?
IB_SMI_SEND : IB_SMI_LOCAL);
}
return IB_SMI_LOCAL;
}
enum smi_forward_action smi_check_forward_dr_smp(struct ib_smp *smp)
{
return __smi_check_forward_dr_smp(smp->hop_ptr, smp->hop_cnt,
ib_get_smp_direction(smp),
smp->dr_dlid == IB_LID_PERMISSIVE,
smp->dr_slid == IB_LID_PERMISSIVE);
}
enum smi_forward_action opa_smi_check_forward_dr_smp(struct opa_smp *smp)
{
return __smi_check_forward_dr_smp(smp->hop_ptr, smp->hop_cnt,
opa_get_smp_direction(smp),
smp->route.dr.dr_dlid ==
OPA_LID_PERMISSIVE,
smp->route.dr.dr_slid ==
OPA_LID_PERMISSIVE);
}
int smi_get_fwd_port(struct ib_smp *smp)
{
return (!ib_get_smp_direction(smp) ? smp->initial_path[smp->hop_ptr+1] :
smp->return_path[smp->hop_ptr-1]);
}
int opa_smi_get_fwd_port(struct opa_smp *smp)
{
return !opa_get_smp_direction(smp) ? smp->route.dr.initial_path[smp->hop_ptr+1] :
smp->route.dr.return_path[smp->hop_ptr-1];
}
