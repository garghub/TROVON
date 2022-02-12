static int gethexdigit(const char *p)
{
if(*p >= '0' && *p <= '9'){
return *p - '0';
}else if(*p >= 'A' && *p <= 'F'){
return *p - 'A' + 0xA;
}else if(*p >= 'a' && *p <= 'f'){
return *p - 'a' + 0xa;
}else{
return -1;
}
}
static gboolean get8hexdigits(const char *p, DWORD *d)
{
int digit;
DWORD val;
int i;
val = 0;
for(i = 0; i < 8; i++){
digit = gethexdigit(p++);
if(digit == -1){
return FALSE;
}
val = (val << 4) | digit;
}
*d = val;
return TRUE;
}
static gboolean get4hexdigits(const char *p, WORD *w)
{
int digit;
WORD val;
int i;
val = 0;
for(i = 0; i < 4; i++){
digit = gethexdigit(p++);
if(digit == -1){
return FALSE;
}
val = (val << 4) | digit;
}
*w = val;
return TRUE;
}
gboolean
parse_as_guid(const char *guid_text, GUID *guid)
{
int i;
int digit1, digit2;
if(*guid_text != '{'){
return FALSE;
}
guid_text++;
if(!get8hexdigits(guid_text, &guid->Data1)){
return FALSE;
}
guid_text += 8;
if(*guid_text != '-'){
return FALSE;
}
guid_text++;
if(!get4hexdigits(guid_text, &guid->Data2)){
return FALSE;
}
guid_text += 4;
if(*guid_text != '-'){
return FALSE;
}
guid_text++;
if(!get4hexdigits(guid_text, &guid->Data3)){
return FALSE;
}
guid_text += 4;
if(*guid_text != '-'){
return FALSE;
}
guid_text++;
for(i = 0; i < 2; i++){
digit1 = gethexdigit(guid_text);
if(digit1 == -1){
return FALSE;
}
guid_text++;
digit2 = gethexdigit(guid_text);
if(digit2 == -1){
return FALSE;
}
guid_text++;
guid->Data4[i] = (digit1 << 4)|(digit2);
}
if(*guid_text != '-'){
return FALSE;
}
guid_text++;
for(i = 0; i < 6; i++){
digit1 = gethexdigit(guid_text);
if(digit1 == -1){
return FALSE;
}
guid_text++;
digit2 = gethexdigit(guid_text);
if(digit2 == -1){
return FALSE;
}
guid_text++;
guid->Data4[i+2] = (digit1 << 4)|(digit2);
}
if(*guid_text != '}'){
return FALSE;
}
guid_text++;
if(*guid_text != '\0'){
return FALSE;
}
return TRUE;
}
gboolean IsWindowsVistaOrLater()
{
#if (_MSC_VER >= 1800)
OSVERSIONINFOEX osvi;
DWORDLONG dwlConditionMask = 0;
int op = VER_GREATER_EQUAL;
SecureZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
osvi.dwMajorVersion = 6;
VER_SET_CONDITION(dwlConditionMask, VER_MAJORVERSION, op);
return VerifyVersionInfo(&osvi, VER_MAJORVERSION, dwlConditionMask);
#else
OSVERSIONINFO osvi;
SecureZeroMemory(&osvi, sizeof(OSVERSIONINFO));
osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
if(GetVersionEx(&osvi)){
return osvi.dwMajorVersion >= 6;
}
return FALSE;
#endif
}
char *
get_interface_friendly_name_from_device_guid(__in GUID *guid)
{
HMODULE hIPHlpApi;
HRESULT status;
WCHAR wName[NDIS_IF_MAX_STRING_SIZE + 1];
HRESULT hr;
gboolean fallbackToUnpublishedApi=TRUE;
gboolean haveInterfaceFriendlyName=FALSE;
int size;
char *name;
hIPHlpApi = LoadLibrary(TEXT("iphlpapi.dll"));
if (hIPHlpApi == NULL) {
return NULL;
}
if(IsWindowsVistaOrLater()){
typedef NETIO_STATUS (WINAPI *ProcAddr_CIG2L) (__in CONST GUID *InterfaceGuid, __out PNET_LUID InterfaceLuid);
typedef NETIO_STATUS (WINAPI *ProcAddr_CIL2A) ( __in CONST NET_LUID *InterfaceLuid,__out_ecount(Length) PWSTR InterfaceAlias, __in SIZE_T Length);
ProcAddr_CIG2L proc_ConvertInterfaceGuidToLuid=(ProcAddr_CIG2L) GetProcAddress(hIPHlpApi, "ConvertInterfaceGuidToLuid");
if(proc_ConvertInterfaceGuidToLuid!=NULL){
ProcAddr_CIL2A Proc_ConvertInterfaceLuidToAlias=(ProcAddr_CIL2A) GetProcAddress(hIPHlpApi, "ConvertInterfaceLuidToAlias");
if(Proc_ConvertInterfaceLuidToAlias!=NULL){
NET_LUID InterfaceLuid;
hr = proc_ConvertInterfaceGuidToLuid(guid, &InterfaceLuid);
if(hr==NO_ERROR){
hr = Proc_ConvertInterfaceLuidToAlias(&InterfaceLuid, wName, NDIS_IF_MAX_STRING_SIZE+1);
if(hr==NO_ERROR){
haveInterfaceFriendlyName=TRUE;
}else{
fallbackToUnpublishedApi=FALSE;
}
}else{
fallbackToUnpublishedApi=FALSE;
}
}
}
}
if(fallbackToUnpublishedApi && !haveInterfaceFriendlyName){
typedef HRESULT (WINAPI *ProcAddr_nhGINFG) (__in GUID *InterfaceGuid, __out PCWSTR InterfaceAlias, __inout DWORD *LengthAddress, wchar_t *a4, wchar_t *a5);
ProcAddr_nhGINFG Proc_nhGetInterfaceNameFromGuid = NULL;
Proc_nhGetInterfaceNameFromGuid = (ProcAddr_nhGINFG) GetProcAddress(hIPHlpApi, "NhGetInterfaceNameFromGuid");
if (Proc_nhGetInterfaceNameFromGuid!= NULL) {
wchar_t *p4=NULL, *p5=NULL;
DWORD NameSize;
NameSize = sizeof(wName);
status = Proc_nhGetInterfaceNameFromGuid(guid, wName, &NameSize, p4, p5);
if(status==0){
haveInterfaceFriendlyName=TRUE;
}
}
}
FreeLibrary(hIPHlpApi);
if(!haveInterfaceFriendlyName){
return NULL;
}
size=WideCharToMultiByte(CP_UTF8, 0, wName, -1, NULL, 0, NULL, NULL);
name=(char *) g_malloc(size);
if (name == NULL){
return NULL;
}
size=WideCharToMultiByte(CP_UTF8, 0, wName, -1, name, size, NULL, NULL);
if(size==0){
g_free(name);
return NULL;
}
return name;
}
char *
get_windows_interface_friendly_name(const char *interface_devicename)
{
const char* guid_text;
GUID guid;
if(strncmp("\\Device\\NPF_", interface_devicename, 12)==0){
guid_text=interface_devicename+12;
}else{
guid_text=interface_devicename;
}
if (!parse_as_guid(guid_text, &guid)){
return NULL;
}
return get_interface_friendly_name_from_device_guid(&guid);
}
