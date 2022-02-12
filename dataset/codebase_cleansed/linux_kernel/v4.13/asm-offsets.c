void foo(void)
{
DEFINE(SINGLESTEP_STATE_BUFFER_OFFSET,
offsetof(struct single_step_state, buffer));
DEFINE(SINGLESTEP_STATE_FLAGS_OFFSET,
offsetof(struct single_step_state, flags));
DEFINE(SINGLESTEP_STATE_ORIG_PC_OFFSET,
offsetof(struct single_step_state, orig_pc));
DEFINE(SINGLESTEP_STATE_NEXT_PC_OFFSET,
offsetof(struct single_step_state, next_pc));
DEFINE(SINGLESTEP_STATE_BRANCH_NEXT_PC_OFFSET,
offsetof(struct single_step_state, branch_next_pc));
DEFINE(SINGLESTEP_STATE_UPDATE_VALUE_OFFSET,
offsetof(struct single_step_state, update_value));
DEFINE(THREAD_INFO_TASK_OFFSET,
offsetof(struct thread_info, task));
DEFINE(THREAD_INFO_FLAGS_OFFSET,
offsetof(struct thread_info, flags));
DEFINE(THREAD_INFO_STATUS_OFFSET,
offsetof(struct thread_info, status));
DEFINE(THREAD_INFO_HOMECACHE_CPU_OFFSET,
offsetof(struct thread_info, homecache_cpu));
DEFINE(THREAD_INFO_PREEMPT_COUNT_OFFSET,
offsetof(struct thread_info, preempt_count));
DEFINE(THREAD_INFO_STEP_STATE_OFFSET,
offsetof(struct thread_info, step_state));
#ifdef __tilegx__
DEFINE(THREAD_INFO_UNALIGN_JIT_BASE_OFFSET,
offsetof(struct thread_info, unalign_jit_base));
DEFINE(THREAD_INFO_UNALIGN_JIT_TMP_OFFSET,
offsetof(struct thread_info, unalign_jit_tmp));
#endif
DEFINE(TASK_STRUCT_THREAD_KSP_OFFSET,
offsetof(struct task_struct, thread.ksp));
DEFINE(TASK_STRUCT_THREAD_PC_OFFSET,
offsetof(struct task_struct, thread.pc));
DEFINE(HV_TOPOLOGY_WIDTH_OFFSET,
offsetof(HV_Topology, width));
DEFINE(HV_TOPOLOGY_HEIGHT_OFFSET,
offsetof(HV_Topology, height));
DEFINE(IRQ_CPUSTAT_SYSCALL_COUNT_OFFSET,
offsetof(irq_cpustat_t, irq_syscall_count));
}
