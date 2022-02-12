int setns(int fd, int nstype)
{
return syscall(__NR_setns, fd, nstype);
}
