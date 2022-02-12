asmlinkage long sys32_unimplemented(int r26, int r25, int r24, int r23,
int r22, int r21, int r20)
{
printk(KERN_ERR "%s(%d): Unimplemented 32 on 64 syscall #%d!\n",
current->comm, current->pid, r20);
return -ENOSYS;
}
