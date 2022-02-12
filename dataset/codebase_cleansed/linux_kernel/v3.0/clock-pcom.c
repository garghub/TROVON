int pc_clk_enable(unsigned id)
{
int rc = msm_proc_comm(PCOM_CLKCTL_RPC_ENABLE, &id, NULL);
if (rc < 0)
return rc;
else
return (int)id < 0 ? -EINVAL : 0;
}
void pc_clk_disable(unsigned id)
{
msm_proc_comm(PCOM_CLKCTL_RPC_DISABLE, &id, NULL);
}
int pc_clk_reset(unsigned id, enum clk_reset_action action)
{
int rc;
if (action == CLK_RESET_ASSERT)
rc = msm_proc_comm(PCOM_CLKCTL_RPC_RESET_ASSERT, &id, NULL);
else
rc = msm_proc_comm(PCOM_CLKCTL_RPC_RESET_DEASSERT, &id, NULL);
if (rc < 0)
return rc;
else
return (int)id < 0 ? -EINVAL : 0;
}
int pc_clk_set_rate(unsigned id, unsigned rate)
{
int rc = msm_proc_comm(PCOM_CLKCTL_RPC_SET_RATE, &id, &rate);
if (rc < 0)
return rc;
else
return (int)id < 0 ? -EINVAL : 0;
}
int pc_clk_set_min_rate(unsigned id, unsigned rate)
{
int rc = msm_proc_comm(PCOM_CLKCTL_RPC_MIN_RATE, &id, &rate);
if (rc < 0)
return rc;
else
return (int)id < 0 ? -EINVAL : 0;
}
int pc_clk_set_max_rate(unsigned id, unsigned rate)
{
int rc = msm_proc_comm(PCOM_CLKCTL_RPC_MAX_RATE, &id, &rate);
if (rc < 0)
return rc;
else
return (int)id < 0 ? -EINVAL : 0;
}
int pc_clk_set_flags(unsigned id, unsigned flags)
{
int rc = msm_proc_comm(PCOM_CLKCTL_RPC_SET_FLAGS, &id, &flags);
if (rc < 0)
return rc;
else
return (int)id < 0 ? -EINVAL : 0;
}
unsigned pc_clk_get_rate(unsigned id)
{
if (msm_proc_comm(PCOM_CLKCTL_RPC_RATE, &id, NULL))
return 0;
else
return id;
}
unsigned pc_clk_is_enabled(unsigned id)
{
if (msm_proc_comm(PCOM_CLKCTL_RPC_ENABLED, &id, NULL))
return 0;
else
return id;
}
long pc_clk_round_rate(unsigned id, unsigned rate)
{
return rate;
}
static bool pc_clk_is_local(unsigned id)
{
return false;
}
