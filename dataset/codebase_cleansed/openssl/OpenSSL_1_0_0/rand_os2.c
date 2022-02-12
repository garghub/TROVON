int RAND_poll(void)
{
char failed_module[20];
QWORD qwTime;
ULONG SysVars[QSV_FOREGROUND_PROCESS];
if (hDoscalls == 0) {
ULONG rc = DosLoadModule(failed_module, sizeof(failed_module), "DOSCALLS", &hDoscalls);
#ifndef __KLIBC__
if (rc == 0) {
rc = DosQueryProcAddr(hDoscalls, 976, NULL, (PFN *)&DosPerfSysCall);
if (rc)
DosPerfSysCall = NULL;
rc = DosQueryProcAddr(hDoscalls, 368, NULL, (PFN *)&DosQuerySysState);
if (rc)
DosQuerySysState = NULL;
}
#endif
}
DosTmrQueryTime(&qwTime);
RAND_add(&qwTime, sizeof(qwTime), 2);
DosQuerySysInfo(1, QSV_FOREGROUND_PROCESS, SysVars, sizeof(SysVars));
RAND_add(SysVars, sizeof(SysVars), 4);
if (DosPerfSysCall) {
CPUUTIL util;
if (DosPerfSysCall(CMD_KI_RDCNT, (ULONG)&util, 0, 0) == 0) {
RAND_add(&util, sizeof(util), 10);
}
else {
#ifndef __KLIBC__
DosPerfSysCall = NULL;
#endif
}
}
if (DosQuerySysState) {
char *buffer = OPENSSL_malloc(256 * 1024);
if (DosQuerySysState(0x1F, 0, 0, 0, buffer, 256 * 1024) == 0) {
RAND_add(buffer, 256 * 1024, **(ULONG **)buffer);
}
OPENSSL_free(buffer);
return 1;
}
return 0;
}
