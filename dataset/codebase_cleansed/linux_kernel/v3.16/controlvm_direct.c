int controlvm_init(void)
{
return 0;
}
void controlvm_deinit(void)
{
}
HOSTADDRESS controlvm_get_channel_address(void)
{
static BOOL warned = FALSE;
U64 addr = 0;
U32 size = 0;
if (!VMCALL_SUCCESSFUL(Issue_VMCALL_IO_CONTROLVM_ADDR(&addr, &size))) {
if (!warned) {
ERRDRV("%s - vmcall to determine controlvm channel addr failed",
__func__);
warned = TRUE;
}
return 0;
}
INFODRV("controlvm addr=%Lx", addr);
return addr;
}
