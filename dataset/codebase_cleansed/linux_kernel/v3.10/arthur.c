static void arthur_lcall7(int nr, struct pt_regs *regs)
{
struct siginfo info;
info.si_signo = SIGSWI;
info.si_errno = nr;
send_sig_info(SIGSWI, &info, current);
}
static int __init arthur_init(void)
{
return register_exec_domain(&arthur_exec_domain);
}
static void __exit arthur_exit(void)
{
unregister_exec_domain(&arthur_exec_domain);
}
