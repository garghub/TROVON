void
wpcap_packet_load(void)
{
static const symbol_table_t symbols[] = {
SYM(PacketGetVersion, FALSE),
SYM(PacketOpenAdapter, FALSE),
SYM(PacketCloseAdapter, FALSE),
SYM(PacketRequest, FALSE),
{ NULL, NULL, FALSE }
};
GModule *wh;
const symbol_table_t *sym;
wh = ws_module_open("packet.dll", 0);
if (!wh) {
return;
}
sym = symbols;
while (sym->name) {
if (!g_module_symbol(wh, sym->name, sym->ptr)) {
if (sym->optional) {
*sym->ptr = NULL;
} else {
return;
}
}
sym++;
}
has_wpacket = TRUE;
}
char *
wpcap_packet_get_version(void)
{
if(!has_wpacket) {
return NULL;
}
return p_PacketGetVersion();
}
void *
wpcap_packet_open(char *if_name)
{
LPADAPTER adapter;
g_assert(has_wpacket);
adapter = p_PacketOpenAdapter(if_name);
return adapter;
}
void
wpcap_packet_close(void *adapter)
{
g_assert(has_wpacket);
p_PacketCloseAdapter(adapter);
}
int
wpcap_packet_request(void *adapter, ULONG Oid, int set, char *value, unsigned int *length)
{
BOOLEAN Status;
ULONG IoCtlBufferLength=(sizeof(PACKET_OID_DATA) + (*length) - 1);
PPACKET_OID_DATA OidData;
g_assert(has_wpacket);
if(p_PacketRequest == NULL) {
g_warning("packet_request not available\n");
return 0;
}
OidData=GlobalAllocPtr(GMEM_MOVEABLE | GMEM_ZEROINIT,IoCtlBufferLength);
if (OidData == NULL) {
g_warning("GlobalAllocPtr failed for %u\n", IoCtlBufferLength);
return 0;
}
OidData->Oid = Oid;
OidData->Length = *length;
memcpy(OidData->Data, value, *length);
Status = p_PacketRequest(adapter, set, OidData);
if(Status) {
if(OidData->Length <= *length) {
memcpy(value, OidData->Data, OidData->Length);
*length = OidData->Length;
} else {
g_warning("returned oid too long, Oid: 0x%x OidLen:%u MaxLen:%u", Oid, OidData->Length, *length);
Status = FALSE;
}
}
GlobalFreePtr (OidData);
if(Status) {
return 1;
} else {
return 0;
}
}
int
wpcap_packet_request_uint(void *adapter, ULONG Oid, UINT *value)
{
BOOLEAN Status;
int length = sizeof(UINT);
Status = wpcap_packet_request(adapter, Oid, FALSE , (char *) value, &length);
if(Status && length == sizeof(UINT)) {
return 1;
} else {
return 0;
}
}
int
wpcap_packet_request_ulong(void *adapter, ULONG Oid, ULONG *value)
{
BOOLEAN Status;
int length = sizeof(ULONG);
Status = wpcap_packet_request(adapter, Oid, FALSE , (char *) value, &length);
if(Status && length == sizeof(ULONG)) {
return 1;
} else {
return 0;
}
}
void
wpcap_packet_load(void)
{
return;
}
