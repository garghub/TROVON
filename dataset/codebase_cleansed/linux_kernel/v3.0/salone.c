LONG __init ArcLoad(CHAR *Path, ULONG TopAddr, ULONG *ExecAddr, ULONG *LowAddr)
{
return ARC_CALL4(load, Path, TopAddr, ExecAddr, LowAddr);
}
LONG __init ArcInvoke(ULONG ExecAddr, ULONG StackAddr, ULONG Argc, CHAR *Argv[],
CHAR *Envp[])
{
return ARC_CALL5(invoke, ExecAddr, StackAddr, Argc, Argv, Envp);
}
LONG __init ArcExecute(CHAR *Path, LONG Argc, CHAR *Argv[], CHAR *Envp[])
{
return ARC_CALL4(exec, Path, Argc, Argv, Envp);
}
