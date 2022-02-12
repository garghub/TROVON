long spu_sys_callback(struct spu_syscall_block *s)
{
long (*syscall)(u64 a1, u64 a2, u64 a3, u64 a4, u64 a5, u64 a6);
if (s->nr_ret >= ARRAY_SIZE(spu_syscall_table)) {
pr_debug("%s: invalid syscall #%lld", __func__, s->nr_ret);
return -ENOSYS;
}
syscall = spu_syscall_table[s->nr_ret];
pr_debug("SPU-syscall "
"%pSR:syscall%lld(%llx, %llx, %llx, %llx, %llx, %llx)\n",
syscall,
s->nr_ret,
s->parm[0], s->parm[1], s->parm[2],
s->parm[3], s->parm[4], s->parm[5]);
return syscall(s->parm[0], s->parm[1], s->parm[2],
s->parm[3], s->parm[4], s->parm[5]);
}
