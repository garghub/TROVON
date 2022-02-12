static short CheckHandle(short h)
{
if ((h < 0) || (h >= MAX1401))
return U14ERR_BADHAND;
if (aHand1401[h] <= 0)
return U14ERR_BADHAND;
return U14ERR_NOERROR;
}
static short U14Status1401(short sHand, LONG lCode, TCSBLOCK* pBlk)
{
unsigned int dwBytes = 0;
if ((sHand < 0) || (sHand >= MAX1401))
return U14ERR_BADHAND;
#ifndef _WIN64
if (!USE_NT_DIOC(sHand))
{
if (DeviceIoControl(aHand1401[sHand], lCode, NULL, 0, pBlk,sizeof(TCSBLOCK),&dwBytes,NULL))
return (short)((dwBytes>=sizeof(TCSBLOCK)) ? U14ERR_NOERROR : U14ERR_DRIVCOMMS);
else
return (short)GetLastError();
}
else
#endif
{
PARAMBLK rWork;
rWork.sState = U14ERR_DRIVCOMMS;
if (DeviceIoControl(aHand1401[sHand], lCode, NULL, 0, &rWork,sizeof(PARAMBLK),&dwBytes,NULL) &&
(dwBytes >= sizeof(PARAMBLK)))
{
*pBlk = rWork.csBlock;
return rWork.sState;
}
}
return U14ERR_DRIVCOMMS;
}
static short U14Control1401(short sHand, LONG lCode, TCSBLOCK* pBlk)
{
unsigned int dwBytes = 0;
if ((sHand < 0) || (sHand >= MAX1401))
return U14ERR_BADHAND;
#ifndef _WIN64
if (!USE_NT_DIOC(sHand))
{
if (DeviceIoControl(aHand1401[sHand], lCode, NULL, 0, pBlk, sizeof(TCSBLOCK), &dwBytes, NULL))
return (short)(dwBytes >= sizeof(TCSBLOCK) ? U14ERR_NOERROR : U14ERR_DRIVCOMMS);
else
return (short)GetLastError();
}
else
#endif
{
PARAMBLK rWork;
rWork.sState = U14ERR_DRIVCOMMS;
if (DeviceIoControl(aHand1401[sHand], lCode, pBlk, sizeof(TCSBLOCK), &rWork, sizeof(PARAMBLK), &dwBytes, NULL) &&
(dwBytes >= sizeof(PARAMBLK)))
return rWork.sState;
}
return U14ERR_DRIVCOMMS;
}
static long SafeTickCount()
{
#ifdef _IS_WINDOWS_
return GetTickCount();
#endif
#ifdef LINUX
struct timeval tv;
gettimeofday(&tv, NULL);
return (tv.tv_sec*1000 + tv.tv_usec/1000);
#endif
}
static int ExtForType(short sType, char* szExt)
{
szExt[0] = 0;
switch (sType)
{
case U14TYPE1401: strcpy(szExt, ".CMD"); break;
case U14TYPEPLUS: strcpy(szExt, ".GXC"); break;
default:
strcpy(szExt, ".ARM");
szExt[3] = (char)('M' + sType - U14TYPEU1401);
if (szExt[3] > 'Z')
szExt[3] = (char)(szExt[3] - 26);
}
return 0;
}
static void TranslateString(char* pStr)
{
int i = 0;
while (pStr[i])
{
if (pStr[i] == ',')
pStr[i] = ' ';
++i;
}
if ((i > 0) && (pStr[i-1] == '\n'))
pStr[i-1] = (char)0;
}
static int GetDriverVersion(short hand)
{
#ifdef _IS_WINDOWS_
TCSBLOCK csBlock;
int iErr = U14Status1401(hand, U14_GETDRIVERREVISION, &csBlock);
if (iErr == U14ERR_NOERROR)
iErr = csBlock.longs[0];
return iErr;
#endif
#ifdef LINUX
return CED_GetDriverRevision(aHand1401[hand]);
#endif
}
static short U14TryToOpen(int n1401, long* plRetVal, short* psHandle)
{
short sErr = U14ERR_NOERROR;
HANDLE hDevice = INVALID_HANDLE_VALUE;
unsigned int dwErr = 0;
int nFirst, nLast, nDev = 0;
BOOL bOldName = FALSE;
if (n1401 == 0)
{
nFirst = 1;
nLast = MAX1401;
}
else
nFirst = nLast = n1401;
while (hDevice == INVALID_HANDLE_VALUE)
{
for (nDev = nFirst; nDev <= nLast; nDev++)
{
char szDevName[40];
sprintf(szDevName, bOldName ? U14NAMEOLD : U14NAMENEW, nDev);
hDevice = CreateFile(szDevName, GENERIC_WRITE | GENERIC_READ,
0, 0,
OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
if (hDevice != INVALID_HANDLE_VALUE)
{
TCSBLOCK csBlock;
assert(aHand1401[nDev-1] == INVALID_HANDLE_VALUE);
aHand1401[nDev-1] = hDevice;
#ifndef _WIN64
abUseNTDIOC[nDev-1] = (BOOL)(!bWindows9x || !bOldName);
#endif
sErr = U14Status1401((short)(nDev-1), U14_TYPEOF1401, &csBlock);
if (sErr == U14ERR_NOERROR)
{
*plRetVal = csBlock.ints[0];
if (csBlock.ints[0] == U14ERR_INUSE)
{
CloseHandle(hDevice);
hDevice = INVALID_HANDLE_VALUE;
aHand1401[nDev-1] = INVALID_HANDLE_VALUE;
sErr = U14ERR_INUSE;
}
else
break;
}
else
{
CloseHandle(hDevice);
hDevice = INVALID_HANDLE_VALUE;
aHand1401[nDev-1] = INVALID_HANDLE_VALUE;
}
}
else
{
unsigned int dwe = GetLastError();
if ((dwe != ERROR_FILE_NOT_FOUND) || (dwErr == 0))
dwErr = dwe;
}
}
if ((hDevice == INVALID_HANDLE_VALUE) &&
(bWindows9x) &&
(bOldName == FALSE))
bOldName = TRUE;
else
break;
}
if (hDevice != INVALID_HANDLE_VALUE)
*psHandle = (short)(nDev-1);
else
{
if (dwErr == ERROR_FILE_NOT_FOUND)
sErr = U14ERR_NO1401DRIV;
else if (dwErr == ERROR_NOT_SUPPORTED)
sErr = U14ERR_DRIVTOOOLD;
else if (dwErr == ERROR_ACCESS_DENIED)
sErr = U14ERR_INUSE;
else
sErr = U14ERR_DRIVCOMMS;
}
return sErr;
}
static short U14TryToOpen(int n1401, long* plRetVal, short* psHandle)
{
short sErr = U14ERR_NOERROR;
int fh = 0;
int iErr = 0;
int nFirst, nLast, nDev = 0;
if (n1401 == 0)
{
nFirst = 1;
nLast = MAX1401;
}
else
nFirst = nLast = n1401;
for (nDev = nFirst; nDev <= nLast; nDev++)
{
char szDevName[40];
sprintf(szDevName,"/dev/cedusb/%d", nDev-1);
fh = open(szDevName, O_RDWR);
if (fh > 0)
{
int iType1401 = CED_TypeOf1401(fh);
aHand1401[nDev-1] = fh;
if (iType1401 >= 0)
{
*plRetVal = iType1401;
break;
}
else
{
close(fh);
fh = 0;
aHand1401[nDev-1] = 0;
}
}
else
{
if (((errno != ENODEV) && (errno != ENOENT)) || (iErr == 0))
iErr = errno;
}
}
if (fh)
*psHandle = (short)(nDev-1);
else
{
if ((iErr == ENODEV) || (iErr == ENOENT))
sErr = U14ERR_NO1401DRIV;
else if (iErr == EBUSY)
sErr = U14ERR_INUSE;
else
sErr = U14ERR_DRIVCOMMS;
}
return sErr;
}
static short Transfer(short hand, BOOL bTo1401, char* pData,
unsigned int dwSize, unsigned int dw1401, short eSz)
{
char strcopy[MAXSTRLEN+1];
short sResult = U14SetTransArea(hand, 0, (void *)pData, dwSize, eSz);
if (sResult == U14ERR_NOERROR)
{
sprintf(strcopy,
"TO%s,$%X,$%X,0;", bTo1401 ? "1401" : "HOST", dw1401, dwSize);
U14SendString(hand, strcopy);
sResult = U14CheckErr(hand);
if (sResult > 0)
sResult = U14ERR_TOXXXERR;
U14UnSetTransfer(hand, 0);
}
return sResult;
}
static unsigned int GetModuleFileName(void* dummy, char* buffer, int max)
{
char szProcPath[32];
sprintf(szProcPath, "/proc/%d/exe", getpid());
if (readlink(szProcPath, buffer, max) != -1)
{
dirname (buffer);
strcat (buffer, "/");
return strlen(buffer);
}
return 0;
}
INT APIENTRY DllMain(HANDLE hInst, unsigned int ul_reason_being_called, LPVOID lpReserved)
{
int iRetVal = 1;
switch (ul_reason_being_called)
{
case DLL_PROCESS_ATTACH:
iRetVal = U14InitLib() > 0;
++iAttached;
break;
case DLL_PROCESS_DETACH:
if (--iAttached == 0)
U14CloseAll();
break;
}
return iRetVal;
UNREFERENCED_PARAMETER(lpReserved);
}
