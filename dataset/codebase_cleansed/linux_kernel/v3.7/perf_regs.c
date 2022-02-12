u64 perf_reg_value(struct pt_regs *regs, int idx)
{
if (WARN_ON_ONCE(idx >= ARRAY_SIZE(pt_regs_offset)))
return 0;
return regs_get_register(regs, pt_regs_offset[idx]);
}
int perf_reg_validate(u64 mask)
{
if (!mask || mask & REG_RESERVED)
return -EINVAL;
return 0;
}
u64 perf_reg_abi(struct task_struct *task)
{
return PERF_SAMPLE_REGS_ABI_32;
}
int perf_reg_validate(u64 mask)
{
if (!mask || mask & REG_RESERVED)
return -EINVAL;
if (mask & REG_NOSUPPORT)
return -EINVAL;
return 0;
}
u64 perf_reg_abi(struct task_struct *task)
{
if (test_tsk_thread_flag(task, TIF_IA32))
return PERF_SAMPLE_REGS_ABI_32;
else
return PERF_SAMPLE_REGS_ABI_64;
}
