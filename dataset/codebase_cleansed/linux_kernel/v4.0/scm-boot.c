int scm_set_boot_addr(u32 addr, int flags)
{
struct {
__le32 flags;
__le32 addr;
} cmd;
cmd.addr = cpu_to_le32(addr);
cmd.flags = cpu_to_le32(flags);
return scm_call(SCM_SVC_BOOT, SCM_BOOT_ADDR,
&cmd, sizeof(cmd), NULL, 0);
}
