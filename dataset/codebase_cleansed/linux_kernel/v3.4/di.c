void pr_out(ADAPTER *a)
{
byte e_no;
ENTITY *this = NULL;
BUFFERS *X;
word length;
word i;
word clength;
REQ *ReqOut;
byte more;
byte ReadyCount;
byte ReqCount;
byte Id;
dtrc(dprintf("pr_out"));
e_no = look_req(a);
if (!e_no)
{
dtrc(dprintf("no_req"));
return;
}
ReadyCount = pr_ready(a);
if (!ReadyCount)
{
dtrc(dprintf("not_ready"));
return;
}
ReqCount = 0;
while (e_no && ReadyCount) {
next_req(a);
this = entity_ptr(a, e_no);
#ifdef USE_EXTENDED_DEBUGS
if (!this)
{
DBG_FTL(("XDI: [%02x] !A%d ==> NULL entity ptr - try to ignore",
xdi_xlog_sec++, (int)((ISDN_ADAPTER *)a->io)->ANum))
e_no = look_req(a);
ReadyCount--;
continue;
}
{
DBG_TRC((">A%d Id=0x%x Req=0x%x", ((ISDN_ADAPTER *)a->io)->ANum, this->Id, this->Req))
}
#else
dbug(dprintf("out:Req=%x,Id=%x,Ch=%x", this->Req, this->Id, this->ReqCh));
#endif
ReqOut = (REQ *)&PR_RAM->B[a->ram_inw(a, &PR_RAM->NextReq)];
#if defined(DIVA_ISTREAM)
if (!(a->tx_stream[this->Id] &&
this->Req == N_DATA)) {
#endif
length = 0;
i = this->XCurrent;
X = PTR_X(a, this);
while (i < this->XNum && length < 270) {
clength = min((word)(270 - length), (word)(X[i].PLength-this->XOffset));
a->ram_out_buffer(a,
&ReqOut->XBuffer.P[length],
PTR_P(a, this, &X[i].P[this->XOffset]),
clength);
length += clength;
this->XOffset += clength;
if (this->XOffset == X[i].PLength) {
this->XCurrent = (byte)++i;
this->XOffset = 0;
}
}
#if defined(DIVA_ISTREAM)
} else {
i = this->XCurrent;
X = PTR_X(a, this);
while (i < this->XNum) {
diva_istream_write(a,
this->Id,
PTR_P(a, this, &X[i].P[0]),
X[i].PLength,
((i + 1) == this->XNum),
0, 0);
this->XCurrent = (byte)++i;
}
length = 0;
}
#endif
a->ram_outw(a, &ReqOut->XBuffer.length, length);
a->ram_out(a, &ReqOut->ReqId, this->Id);
a->ram_out(a, &ReqOut->ReqCh, this->ReqCh);
if (this->Id & 0x1f) {
this->More++;
if (i < this->XNum && this->MInd) {
xdi_xlog_request(XDI_A_NR(a), this->Id, this->ReqCh, this->MInd,
a->IdTypeTable[this->No]);
a->ram_out(a, &ReqOut->Req, this->MInd);
more = true;
}
else {
xdi_xlog_request(XDI_A_NR(a), this->Id, this->ReqCh, this->Req,
a->IdTypeTable[this->No]);
this->More |= XMOREF;
a->ram_out(a, &ReqOut->Req, this->Req);
more = false;
if (a->FlowControlIdTable[this->ReqCh] == this->Id)
a->FlowControlSkipTable[this->ReqCh] = true;
if (this->Req == REMOVE) {
a->misc_flags_table[e_no] |= DIVA_MISC_FLAGS_REMOVE_PENDING;
}
}
if (more) {
req_queue(a, this->No);
}
}
else {
this->MInd = 0;
if (this->Id == BLLC_ID) this->MInd = LL_MDATA;
if (this->Id == NL_ID ||
this->Id == TASK_ID ||
this->Id == MAN_ID
) this->MInd = N_MDATA;
a->IdTypeTable[this->No] = this->Id;
xdi_xlog_request(XDI_A_NR(a), this->Id, this->ReqCh, this->Req, this->Id);
this->More |= XMOREF;
a->ram_out(a, &ReqOut->Req, this->Req);
assign_queue(a, this->No, a->ram_inw(a, &ReqOut->Reference));
}
a->ram_outw(a, &PR_RAM->NextReq, a->ram_inw(a, &ReqOut->next));
ReadyCount--;
ReqCount++;
e_no = look_req(a);
}
a->ram_out(a, &PR_RAM->ReqInput,
(byte)(a->ram_in(a, &PR_RAM->ReqInput) + ReqCount));
if (this && (this->Req == UREMOVE) && this->Id) {
Id = this->Id;
e_no = a->IdTable[Id];
free_entity(a, e_no);
for (i = 0; i < 256; i++)
{
if (a->FlowControlIdTable[i] == Id)
a->FlowControlIdTable[i] = 0;
}
a->IdTable[Id] = 0;
this->Id = 0;
}
}
static byte pr_ready(ADAPTER *a)
{
byte ReadyCount;
ReadyCount = (byte)(a->ram_in(a, &PR_RAM->ReqOutput) -
a->ram_in(a, &PR_RAM->ReqInput));
if (!ReadyCount) {
if (!a->ReadyInt) {
a->ram_inc(a, &PR_RAM->ReadyInt);
a->ReadyInt++;
}
}
return ReadyCount;
}
byte pr_dpc(ADAPTER *a)
{
byte Count;
RC *RcIn;
IND *IndIn;
byte c;
byte RNRId;
byte Rc;
byte Ind;
if ((Count = a->ram_in(a, &PR_RAM->RcOutput)) != 0) {
dtrc(dprintf("#Rc=%x", Count));
RcIn = (RC *)&PR_RAM->B[a->ram_inw(a, &PR_RAM->NextRc)];
while (Count--) {
if ((Rc = a->ram_in(a, &RcIn->Rc)) != 0) {
dword tmp[2];
a->ram_in_buffer(a,
&RcIn->Reserved2[0],
(byte *)&tmp[0],
8);
isdn_rc(a,
Rc,
a->ram_in(a, &RcIn->RcId),
a->ram_in(a, &RcIn->RcCh),
a->ram_inw(a, &RcIn->Reference),
tmp[0],
tmp[1]);
a->ram_out(a, &RcIn->Rc, 0);
}
RcIn = (RC *)&PR_RAM->B[a->ram_inw(a, &RcIn->next)];
}
a->ram_out(a, &PR_RAM->RcOutput, 0);
pr_out(a);
}
RNRId = 0;
if ((Count = a->ram_in(a, &PR_RAM->IndOutput)) != 0) {
dtrc(dprintf("#Ind=%x", Count));
IndIn = (IND *)&PR_RAM->B[a->ram_inw(a, &PR_RAM->NextInd)];
while (Count--) {
if (RNRId && RNRId == a->ram_in(a, &IndIn->IndId)) {
a->ram_out(a, &IndIn->Ind, 0);
a->ram_out(a, &IndIn->RNR, true);
}
else {
Ind = a->ram_in(a, &IndIn->Ind);
if (Ind) {
RNRId = 0;
c = isdn_ind(a,
Ind,
a->ram_in(a, &IndIn->IndId),
a->ram_in(a, &IndIn->IndCh),
&IndIn->RBuffer,
a->ram_in(a, &IndIn->MInd),
a->ram_inw(a, &IndIn->MLength));
if (c == 1) {
dtrc(dprintf("RNR"));
a->ram_out(a, &IndIn->Ind, 0);
RNRId = a->ram_in(a, &IndIn->IndId);
a->ram_out(a, &IndIn->RNR, true);
}
}
}
IndIn = (IND *)&PR_RAM->B[a->ram_inw(a, &IndIn->next)];
}
a->ram_out(a, &PR_RAM->IndOutput, 0);
}
return false;
}
byte scom_test_int(ADAPTER *a)
{
return a->ram_in(a, (void *)0x3fe);
}
void scom_clear_int(ADAPTER *a)
{
a->ram_out(a, (void *)0x3fe, 0);
}
static byte isdn_rc(ADAPTER *a,
byte Rc,
byte Id,
byte Ch,
word Ref,
dword extended_info_type,
dword extended_info)
{
ENTITY *this;
byte e_no;
word i;
int cancel_rc;
#ifdef USE_EXTENDED_DEBUGS
{
DBG_TRC(("<A%d Id=0x%x Rc=0x%x", ((ISDN_ADAPTER *)a->io)->ANum, Id, Rc))
}
#else
dbug(dprintf("isdn_rc(Rc=%x,Id=%x,Ch=%x)", Rc, Id, Ch));
#endif
if (Rc == READY_INT) {
xdi_xlog_rc_event(XDI_A_NR(a), Id, Ch, Rc, 0, 0);
if (a->ReadyInt) {
a->ReadyInt--;
return 0;
}
return 2;
}
e_no = a->IdTable[Id];
if (e_no) {
this = entity_ptr(a, e_no);
xdi_xlog_rc_event(XDI_A_NR(a), Id, Ch, Rc, 0, a->IdTypeTable[this->No]);
this->RcCh = Ch;
if ((a->misc_flags_table[e_no] & DIVA_MISC_FLAGS_REMOVE_PENDING) &&
(Rc == OK)) {
if (a->IdTypeTable[e_no] == NL_ID) {
if (a->RcExtensionSupported &&
(extended_info_type != DIVA_RC_TYPE_REMOVE_COMPLETE)) {
dtrc(dprintf("XDI: N-REMOVE, A(%02x) Id:%02x, ignore RC=OK",
XDI_A_NR(a), Id));
return (0);
}
if (extended_info_type == DIVA_RC_TYPE_REMOVE_COMPLETE)
a->RcExtensionSupported = true;
}
a->misc_flags_table[e_no] &= ~DIVA_MISC_FLAGS_REMOVE_PENDING;
a->misc_flags_table[e_no] &= ~DIVA_MISC_FLAGS_NO_RC_CANCELLING;
free_entity(a, e_no);
for (i = 0; i < 256; i++)
{
if (a->FlowControlIdTable[i] == Id)
a->FlowControlIdTable[i] = 0;
}
a->IdTable[Id] = 0;
this->Id = 0;
if ((this->More & XMOREC) > 1) {
this->More &= ~XMOREC;
this->More |= 1;
dtrc(dprintf("XDI: correct MORE on REMOVE A(%02x) Id:%02x",
XDI_A_NR(a), Id));
}
}
if (Rc == OK_FC) {
a->FlowControlIdTable[Ch] = Id;
a->FlowControlSkipTable[Ch] = false;
this->Rc = Rc;
this->More &= ~(XBUSY | XMOREC);
this->complete = 0xff;
xdi_xlog_rc_event(XDI_A_NR(a), Id, Ch, Rc, 1, a->IdTypeTable[this->No]);
CALLBACK(a, this);
return 0;
}
if (extended_info_type == DIVA_RC_TYPE_OK_FC) {
a->misc_flags_table[e_no] |= DIVA_MISC_FLAGS_NO_RC_CANCELLING;
this->Rc = Rc;
this->complete = 0xff;
xdi_xlog_rc_event(XDI_A_NR(a), Id, Ch, Rc, 1, a->IdTypeTable[this->No]);
DBG_TRC(("XDI OK_FC A(%02x) Id:%02x Ch:%02x Rc:%02x",
XDI_A_NR(a), Id, Ch, Rc))
CALLBACK(a, this);
return 0;
}
cancel_rc = !(a->misc_flags_table[e_no] & DIVA_MISC_FLAGS_NO_RC_CANCELLING);
if (cancel_rc && (a->FlowControlIdTable[Ch] == Id))
{
a->FlowControlIdTable[Ch] = 0;
if ((Rc != OK) || !a->FlowControlSkipTable[Ch])
{
this->Rc = Rc;
if (Ch == this->ReqCh)
{
this->More &= ~(XBUSY | XMOREC);
this->complete = 0xff;
}
xdi_xlog_rc_event(XDI_A_NR(a), Id, Ch, Rc, 1, a->IdTypeTable[this->No]);
CALLBACK(a, this);
}
return 0;
}
if (this->More & XMOREC)
this->More--;
if (((!cancel_rc) || (this->More & XMOREF)) && !(this->More & XMOREC)) {
this->Rc = Rc;
this->More &= ~XBUSY;
this->complete = 0xff;
xdi_xlog_rc_event(XDI_A_NR(a), Id, Ch, Rc, 1, a->IdTypeTable[this->No]);
CALLBACK(a, this);
}
return 0;
}
if ((Rc & 0xf0) == ASSIGN_RC) {
e_no = get_assign(a, Ref);
if (e_no) {
this = entity_ptr(a, e_no);
this->Id = Id;
xdi_xlog_rc_event(XDI_A_NR(a), Id, Ch, Rc, 2, a->IdTypeTable[this->No]);
this->Rc = Rc;
this->More &= ~XBUSY;
this->complete = 0xff;
#if defined(DIVA_ISTREAM)
if ((Rc == ASSIGN_OK) && a->ram_offset &&
(a->IdTypeTable[this->No] == NL_ID) &&
((extended_info_type == DIVA_RC_TYPE_RX_DMA) ||
(extended_info_type == DIVA_RC_TYPE_CMA_PTR)) &&
extended_info) {
dword offset = (*(a->ram_offset)) (a);
dword tmp[2];
extended_info -= offset;
#ifdef PLATFORM_GT_32BIT
a->ram_in_dw(a, (void *)ULongToPtr(extended_info), (dword *)&tmp[0], 2);
#else
a->ram_in_dw(a, (void *)extended_info, (dword *)&tmp[0], 2);
#endif
a->tx_stream[Id] = tmp[0];
a->rx_stream[Id] = tmp[1];
if (extended_info_type == DIVA_RC_TYPE_RX_DMA) {
DBG_TRC(("Id=0x%x RxDMA=%08x:%08x",
Id, a->tx_stream[Id], a->rx_stream[Id]))
a->misc_flags_table[this->No] |= DIVA_MISC_FLAGS_RX_DMA;
} else {
DBG_TRC(("Id=0x%x CMA=%08x:%08x",
Id, a->tx_stream[Id], a->rx_stream[Id]))
a->misc_flags_table[this->No] &= ~DIVA_MISC_FLAGS_RX_DMA;
a->rx_pos[Id] = 0;
a->rx_stream[Id] -= offset;
}
a->tx_pos[Id] = 0;
a->tx_stream[Id] -= offset;
} else {
a->tx_stream[Id] = 0;
a->rx_stream[Id] = 0;
a->misc_flags_table[this->No] &= ~DIVA_MISC_FLAGS_RX_DMA;
}
#endif
CALLBACK(a, this);
if (Rc == ASSIGN_OK) {
a->IdTable[Id] = e_no;
}
else
{
free_entity(a, e_no);
for (i = 0; i < 256; i++)
{
if (a->FlowControlIdTable[i] == Id)
a->FlowControlIdTable[i] = 0;
}
a->IdTable[Id] = 0;
this->Id = 0;
}
return 1;
}
}
return 2;
}
static byte isdn_ind(ADAPTER *a,
byte Ind,
byte Id,
byte Ch,
PBUFFER *RBuffer,
byte MInd,
word MLength)
{
ENTITY *this;
word clength;
word offset;
BUFFERS *R;
byte *cma = NULL;
#ifdef USE_EXTENDED_DEBUGS
{
DBG_TRC(("<A%d Id=0x%x Ind=0x%x", ((ISDN_ADAPTER *)a->io)->ANum, Id, Ind))
}
#else
dbug(dprintf("isdn_ind(Ind=%x,Id=%x,Ch=%x)", Ind, Id, Ch));
#endif
if (a->IdTable[Id]) {
this = entity_ptr(a, a->IdTable[Id]);
this->IndCh = Ch;
xdi_xlog_ind(XDI_A_NR(a), Id, Ch, Ind,
0, 0 , a->IdTypeTable[this->No]);
if (this->RCurrent == 0xff) {
if (Ind == this->MInd) {
this->complete = 0;
this->Ind = MInd;
}
else {
this->complete = 1;
this->Ind = Ind;
}
this->RLength = MLength;
#if defined(DIVA_ISTREAM)
if ((a->rx_stream[this->Id] ||
(a->misc_flags_table[this->No] & DIVA_MISC_FLAGS_RX_DMA)) &&
((Ind == N_DATA) ||
(a->protocol_capabilities & PROTCAP_CMA_ALLPR))) {
PISDN_ADAPTER IoAdapter = (PISDN_ADAPTER)a->io;
if (a->misc_flags_table[this->No] & DIVA_MISC_FLAGS_RX_DMA) {
#if defined(DIVA_IDI_RX_DMA)
dword d;
diva_get_dma_map_entry(\
(struct _diva_dma_map_entry *)IoAdapter->dma_map,
(int)a->rx_stream[this->Id], (void **)&cma, &d);
#else
cma = &a->stream_buffer[0];
cma[0] = cma[1] = cma[2] = cma[3] = 0;
#endif
this->RLength = MLength = (word)*(dword *)cma;
cma += 4;
} else {
int final = 0;
cma = &a->stream_buffer[0];
this->RLength = MLength = (word)diva_istream_read(a,
Id,
cma,
sizeof(a->stream_buffer),
&final, NULL, NULL);
}
IoAdapter->RBuffer.length = min(MLength, (word)270);
if (IoAdapter->RBuffer.length != MLength) {
this->complete = 0;
} else {
this->complete = 1;
}
memcpy(IoAdapter->RBuffer.P, cma, IoAdapter->RBuffer.length);
this->RBuffer = (DBUFFER *)&IoAdapter->RBuffer;
}
#endif
if (!cma) {
a->ram_look_ahead(a, RBuffer, this);
}
this->RNum = 0;
CALLBACK(a, this);
this = entity_ptr(a, a->IdTable[Id]);
xdi_xlog_ind(XDI_A_NR(a), Id, Ch, Ind,
1, this->RNR, a->IdTypeTable[this->No]);
if (this->RNR == 1) {
this->RNR = 0;
return 1;
}
if (!this->RNR && !this->RNum) {
xdi_xlog_ind(XDI_A_NR(a), Id, Ch, Ind,
2, 0, a->IdTypeTable[this->No]);
return 0;
}
this->RCurrent = 0;
this->ROffset = 0;
}
if (this->RNR == 2) {
if (Ind != this->MInd) {
this->RCurrent = 0xff;
this->RNR = 0;
}
return 0;
}
offset = 0;
R = PTR_R(a, this);
do {
if (this->ROffset == R[this->RCurrent].PLength) {
this->ROffset = 0;
this->RCurrent++;
}
if (cma) {
clength = min(MLength, (word)(R[this->RCurrent].PLength-this->ROffset));
} else {
clength = min(a->ram_inw(a, &RBuffer->length)-offset,
R[this->RCurrent].PLength-this->ROffset);
}
if (R[this->RCurrent].P) {
if (cma) {
memcpy(PTR_P(a, this, &R[this->RCurrent].P[this->ROffset]),
&cma[offset],
clength);
} else {
a->ram_in_buffer(a,
&RBuffer->P[offset],
PTR_P(a, this, &R[this->RCurrent].P[this->ROffset]),
clength);
}
}
offset += clength;
this->ROffset += clength;
if (cma) {
if (offset >= MLength) {
break;
}
continue;
}
} while (offset < (a->ram_inw(a, &RBuffer->length)));
if (Ind != this->MInd) {
R[this->RCurrent].PLength = this->ROffset;
if (this->ROffset) this->RCurrent++;
this->RNum = this->RCurrent;
this->RCurrent = 0xff;
this->Ind = Ind;
this->complete = 2;
xdi_xlog_ind(XDI_A_NR(a), Id, Ch, Ind,
3, 0, a->IdTypeTable[this->No]);
CALLBACK(a, this);
}
return 0;
}
return 2;
}
static void xdi_xlog(byte *msg, word code, int length) {
xdi_dbg_xlog("\x00\x02", msg, code, length);
}
static void xdi_xlog_rc_event(byte Adapter,
byte Id, byte Ch, byte Rc, byte cb, byte type) {
#if defined(XDI_USE_XLOG)
word LogInfo[4];
PUT_WORD(&LogInfo[0], ((word)Adapter | (word)(xdi_xlog_sec++ << 8)));
PUT_WORD(&LogInfo[1], ((word)Id | (word)(Ch << 8)));
PUT_WORD(&LogInfo[2], ((word)Rc | (word)(type << 8)));
PUT_WORD(&LogInfo[3], cb);
xdi_xlog((byte *)&LogInfo[0], 221, sizeof(LogInfo));
#endif
}
static void xdi_xlog_request(byte Adapter, byte Id,
byte Ch, byte Req, byte type) {
#if defined(XDI_USE_XLOG)
word LogInfo[3];
PUT_WORD(&LogInfo[0], ((word)Adapter | (word)(xdi_xlog_sec++ << 8)));
PUT_WORD(&LogInfo[1], ((word)Id | (word)(Ch << 8)));
PUT_WORD(&LogInfo[2], ((word)Req | (word)(type << 8)));
xdi_xlog((byte *)&LogInfo[0], 220, sizeof(LogInfo));
#endif
}
static void xdi_xlog_ind(byte Adapter,
byte Id,
byte Ch,
byte Ind,
byte rnr_valid,
byte rnr,
byte type) {
#if defined(XDI_USE_XLOG)
word LogInfo[4];
PUT_WORD(&LogInfo[0], ((word)Adapter | (word)(xdi_xlog_sec++ << 8)));
PUT_WORD(&LogInfo[1], ((word)Id | (word)(Ch << 8)));
PUT_WORD(&LogInfo[2], ((word)Ind | (word)(type << 8)));
PUT_WORD(&LogInfo[3], ((word)rnr | (word)(rnr_valid << 8)));
xdi_xlog((byte *)&LogInfo[0], 222, sizeof(LogInfo));
#endif
}
