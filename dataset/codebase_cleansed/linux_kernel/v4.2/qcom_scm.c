int qcom_scm_set_cold_boot_addr(void *entry, const cpumask_t *cpus)
{
return __qcom_scm_set_cold_boot_addr(entry, cpus);
}
int qcom_scm_set_warm_boot_addr(void *entry, const cpumask_t *cpus)
{
return __qcom_scm_set_warm_boot_addr(entry, cpus);
}
void qcom_scm_cpu_power_down(u32 flags)
{
__qcom_scm_cpu_power_down(flags);
}
bool qcom_scm_hdcp_available(void)
{
int ret;
ret = __qcom_scm_is_call_available(QCOM_SCM_SVC_HDCP,
QCOM_SCM_CMD_HDCP);
return (ret > 0) ? true : false;
}
int qcom_scm_hdcp_req(struct qcom_scm_hdcp_req *req, u32 req_cnt, u32 *resp)
{
return __qcom_scm_hdcp_req(req, req_cnt, resp);
}
