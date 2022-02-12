int __qcom_scm_set_cold_boot_addr(void *entry, const cpumask_t *cpus)
{
return -ENOTSUPP;
}
int __qcom_scm_set_warm_boot_addr(void *entry, const cpumask_t *cpus)
{
return -ENOTSUPP;
}
void __qcom_scm_cpu_power_down(u32 flags)
{
}
int __qcom_scm_is_call_available(u32 svc_id, u32 cmd_id)
{
return -ENOTSUPP;
}
int __qcom_scm_hdcp_req(struct qcom_scm_hdcp_req *req, u32 req_cnt, u32 *resp)
{
return -ENOTSUPP;
}
