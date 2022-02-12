void
myDbgPrint_EVL (long msgID, ...)
{ va_list ap ;
if ( myDriverDebugHandle.dbg_ev )
{ va_start (ap, msgID) ;
(myDriverDebugHandle.dbg_ev)
(myDriverDebugHandle.id, (unsigned long)msgID, ap) ;
va_end (ap) ;
} }
int
DbgRegister (char *drvName, char *drvTag, unsigned long dbgMask)
{
int len;
DbgDeregister () ;
myDriverDebugHandle.Version = DBG_HANDLE_VERSION ;
myDriverDebugHandle.id = -1 ;
myDriverDebugHandle.dbgMask = dbgMask | (DL_EVL | DL_FTL | DL_LOG) ;
len = strlen (drvName) ;
memcpy (myDriverDebugHandle.drvName, drvName,
(len < sizeof(myDriverDebugHandle.drvName)) ?
len : sizeof(myDriverDebugHandle.drvName) - 1) ;
len = strlen (drvTag) ;
memcpy (myDriverDebugHandle.drvTag, drvTag,
(len < sizeof(myDriverDebugHandle.drvTag)) ?
len : sizeof(myDriverDebugHandle.drvTag) - 1) ;
dprintf("\000\377", &myDriverDebugHandle) ;
if ( myDriverDebugHandle.dbg_prt )
{
return (1) ;
}
if ( myDriverDebugHandle.dbg_end != NULL
&& (myDriverDebugHandle.regTime.LowPart ||
myDriverDebugHandle.regTime.HighPart ) )
{
dprintf("%s: Cannot log to old maint driver !", drvName) ;
myDriverDebugHandle.dbg_end =
((_OldDbgHandle_ *)&myDriverDebugHandle)->dbg_end ;
DbgDeregister () ;
}
return (0) ;
}
void
DbgSetLevel (unsigned long dbgMask)
{
myDriverDebugHandle.dbgMask = dbgMask | (DL_EVL | DL_FTL | DL_LOG) ;
}
void
DbgDeregister (void)
{
if ( myDriverDebugHandle.dbg_end )
{
(myDriverDebugHandle.dbg_end)(&myDriverDebugHandle) ;
}
memset (&myDriverDebugHandle, 0, sizeof(myDriverDebugHandle)) ;
}
void xdi_dbg_xlog (char* x, ...) {
va_list ap;
va_start (ap, x);
if (myDriverDebugHandle.dbg_end &&
(myDriverDebugHandle.dbg_irq || myDriverDebugHandle.dbg_old) &&
(myDriverDebugHandle.dbgMask & DL_STAT)) {
if (myDriverDebugHandle.dbg_irq) {
(*(myDriverDebugHandle.dbg_irq))(myDriverDebugHandle.id,
(x[0] != 0) ? DLI_TRC : DLI_XLOG, x, ap);
} else {
(*(myDriverDebugHandle.dbg_old))(myDriverDebugHandle.id, x, ap);
}
}
va_end(ap);
}
