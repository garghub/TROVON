int scm_set_boot_addr(phys_addr_t addr, int flags)
{
struct {
unsigned int flags;
phys_addr_t addr;
} cmd;
cmd.addr = addr;
cmd.flags = flags;
return scm_call(SCM_SVC_BOOT, SCM_BOOT_ADDR,
&cmd, sizeof(cmd), NULL, 0);
}
