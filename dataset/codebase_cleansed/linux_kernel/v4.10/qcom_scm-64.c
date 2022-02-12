static int qcom_scm_call(struct device *dev, u32 svc_id, u32 cmd_id,
const struct qcom_scm_desc *desc,
struct arm_smccc_res *res)
{
int arglen = desc->arginfo & 0xf;
int retry_count = 0, i;
u32 fn_id = QCOM_SCM_FNID(svc_id, cmd_id);
u64 cmd, x5 = desc->args[FIRST_EXT_ARG_IDX];
dma_addr_t args_phys = 0;
void *args_virt = NULL;
size_t alloc_len;
if (unlikely(arglen > N_REGISTER_ARGS)) {
alloc_len = N_EXT_QCOM_SCM_ARGS * sizeof(u64);
args_virt = kzalloc(PAGE_ALIGN(alloc_len), GFP_KERNEL);
if (!args_virt)
return -ENOMEM;
if (qcom_smccc_convention == ARM_SMCCC_SMC_32) {
__le32 *args = args_virt;
for (i = 0; i < N_EXT_QCOM_SCM_ARGS; i++)
args[i] = cpu_to_le32(desc->args[i +
FIRST_EXT_ARG_IDX]);
} else {
__le64 *args = args_virt;
for (i = 0; i < N_EXT_QCOM_SCM_ARGS; i++)
args[i] = cpu_to_le64(desc->args[i +
FIRST_EXT_ARG_IDX]);
}
args_phys = dma_map_single(dev, args_virt, alloc_len,
DMA_TO_DEVICE);
if (dma_mapping_error(dev, args_phys)) {
kfree(args_virt);
return -ENOMEM;
}
x5 = args_phys;
}
do {
mutex_lock(&qcom_scm_lock);
cmd = ARM_SMCCC_CALL_VAL(ARM_SMCCC_STD_CALL,
qcom_smccc_convention,
ARM_SMCCC_OWNER_SIP, fn_id);
do {
arm_smccc_smc(cmd, desc->arginfo, desc->args[0],
desc->args[1], desc->args[2], x5, 0, 0,
res);
} while (res->a0 == QCOM_SCM_INTERRUPTED);
mutex_unlock(&qcom_scm_lock);
if (res->a0 == QCOM_SCM_V2_EBUSY) {
if (retry_count++ > QCOM_SCM_EBUSY_MAX_RETRY)
break;
msleep(QCOM_SCM_EBUSY_WAIT_MS);
}
} while (res->a0 == QCOM_SCM_V2_EBUSY);
if (args_virt) {
dma_unmap_single(dev, args_phys, alloc_len, DMA_TO_DEVICE);
kfree(args_virt);
}
if (res->a0 < 0)
return qcom_scm_remap_error(res->a0);
return 0;
}
int __qcom_scm_set_cold_boot_addr(void *entry, const cpumask_t *cpus)
{
return -ENOTSUPP;
}
int __qcom_scm_set_warm_boot_addr(struct device *dev, void *entry,
const cpumask_t *cpus)
{
return -ENOTSUPP;
}
void __qcom_scm_cpu_power_down(u32 flags)
{
}
int __qcom_scm_is_call_available(struct device *dev, u32 svc_id, u32 cmd_id)
{
int ret;
struct qcom_scm_desc desc = {0};
struct arm_smccc_res res;
desc.arginfo = QCOM_SCM_ARGS(1);
desc.args[0] = QCOM_SCM_FNID(svc_id, cmd_id) |
(ARM_SMCCC_OWNER_SIP << ARM_SMCCC_OWNER_SHIFT);
ret = qcom_scm_call(dev, QCOM_SCM_SVC_INFO, QCOM_IS_CALL_AVAIL_CMD,
&desc, &res);
return ret ? : res.a1;
}
int __qcom_scm_hdcp_req(struct device *dev, struct qcom_scm_hdcp_req *req,
u32 req_cnt, u32 *resp)
{
int ret;
struct qcom_scm_desc desc = {0};
struct arm_smccc_res res;
if (req_cnt > QCOM_SCM_HDCP_MAX_REQ_CNT)
return -ERANGE;
desc.args[0] = req[0].addr;
desc.args[1] = req[0].val;
desc.args[2] = req[1].addr;
desc.args[3] = req[1].val;
desc.args[4] = req[2].addr;
desc.args[5] = req[2].val;
desc.args[6] = req[3].addr;
desc.args[7] = req[3].val;
desc.args[8] = req[4].addr;
desc.args[9] = req[4].val;
desc.arginfo = QCOM_SCM_ARGS(10);
ret = qcom_scm_call(dev, QCOM_SCM_SVC_HDCP, QCOM_SCM_CMD_HDCP, &desc,
&res);
*resp = res.a1;
return ret;
}
void __qcom_scm_init(void)
{
u64 cmd;
struct arm_smccc_res res;
u32 function = QCOM_SCM_FNID(QCOM_SCM_SVC_INFO, QCOM_IS_CALL_AVAIL_CMD);
cmd = ARM_SMCCC_CALL_VAL(ARM_SMCCC_FAST_CALL, ARM_SMCCC_SMC_64,
ARM_SMCCC_OWNER_SIP, function);
arm_smccc_smc(cmd, QCOM_SCM_ARGS(1), cmd & (~BIT(ARM_SMCCC_TYPE_SHIFT)),
0, 0, 0, 0, 0, &res);
if (!res.a0 && res.a1)
qcom_smccc_convention = ARM_SMCCC_SMC_64;
else
qcom_smccc_convention = ARM_SMCCC_SMC_32;
}
bool __qcom_scm_pas_supported(struct device *dev, u32 peripheral)
{
int ret;
struct qcom_scm_desc desc = {0};
struct arm_smccc_res res;
desc.args[0] = peripheral;
desc.arginfo = QCOM_SCM_ARGS(1);
ret = qcom_scm_call(dev, QCOM_SCM_SVC_PIL,
QCOM_SCM_PAS_IS_SUPPORTED_CMD,
&desc, &res);
return ret ? false : !!res.a1;
}
int __qcom_scm_pas_init_image(struct device *dev, u32 peripheral,
dma_addr_t metadata_phys)
{
int ret;
struct qcom_scm_desc desc = {0};
struct arm_smccc_res res;
desc.args[0] = peripheral;
desc.args[1] = metadata_phys;
desc.arginfo = QCOM_SCM_ARGS(2, QCOM_SCM_VAL, QCOM_SCM_RW);
ret = qcom_scm_call(dev, QCOM_SCM_SVC_PIL, QCOM_SCM_PAS_INIT_IMAGE_CMD,
&desc, &res);
return ret ? : res.a1;
}
int __qcom_scm_pas_mem_setup(struct device *dev, u32 peripheral,
phys_addr_t addr, phys_addr_t size)
{
int ret;
struct qcom_scm_desc desc = {0};
struct arm_smccc_res res;
desc.args[0] = peripheral;
desc.args[1] = addr;
desc.args[2] = size;
desc.arginfo = QCOM_SCM_ARGS(3);
ret = qcom_scm_call(dev, QCOM_SCM_SVC_PIL, QCOM_SCM_PAS_MEM_SETUP_CMD,
&desc, &res);
return ret ? : res.a1;
}
int __qcom_scm_pas_auth_and_reset(struct device *dev, u32 peripheral)
{
int ret;
struct qcom_scm_desc desc = {0};
struct arm_smccc_res res;
desc.args[0] = peripheral;
desc.arginfo = QCOM_SCM_ARGS(1);
ret = qcom_scm_call(dev, QCOM_SCM_SVC_PIL,
QCOM_SCM_PAS_AUTH_AND_RESET_CMD,
&desc, &res);
return ret ? : res.a1;
}
int __qcom_scm_pas_shutdown(struct device *dev, u32 peripheral)
{
int ret;
struct qcom_scm_desc desc = {0};
struct arm_smccc_res res;
desc.args[0] = peripheral;
desc.arginfo = QCOM_SCM_ARGS(1);
ret = qcom_scm_call(dev, QCOM_SCM_SVC_PIL, QCOM_SCM_PAS_SHUTDOWN_CMD,
&desc, &res);
return ret ? : res.a1;
}
int __qcom_scm_pas_mss_reset(struct device *dev, bool reset)
{
struct qcom_scm_desc desc = {0};
struct arm_smccc_res res;
int ret;
desc.args[0] = reset;
desc.args[1] = 0;
desc.arginfo = QCOM_SCM_ARGS(2);
ret = qcom_scm_call(dev, QCOM_SCM_SVC_PIL, QCOM_SCM_PAS_MSS_RESET, &desc,
&res);
return ret ? : res.a1;
}
