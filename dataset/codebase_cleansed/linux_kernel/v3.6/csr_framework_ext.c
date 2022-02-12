CsrResult CsrMutexCreate(CsrMutexHandle *mutexHandle)
{
if (mutexHandle == NULL)
{
return CSR_FE_RESULT_INVALID_POINTER;
}
sema_init(mutexHandle, 1);
return CSR_RESULT_SUCCESS;
}
void CsrMutexDestroy(CsrMutexHandle *mutexHandle)
{
}
CsrResult CsrMutexLock(CsrMutexHandle *mutexHandle)
{
if (mutexHandle == NULL)
{
return CSR_FE_RESULT_INVALID_POINTER;
}
if (down_interruptible(mutexHandle))
{
CsrPanic(CSR_TECH_FW, CSR_PANIC_FW_UNEXPECTED_VALUE, "CsrMutexLock Failed");
return CSR_FE_RESULT_INVALID_POINTER;
}
return CSR_RESULT_SUCCESS;
}
CsrResult CsrMutexUnlock(CsrMutexHandle *mutexHandle)
{
if (mutexHandle == NULL)
{
return CSR_FE_RESULT_INVALID_POINTER;
}
up(mutexHandle);
return CSR_RESULT_SUCCESS;
}
void CsrThreadSleep(u16 sleepTimeInMs)
{
unsigned long t;
t = ((sleepTimeInMs * HZ) + 999) / 1000;
schedule_timeout_uninterruptible(t);
}
