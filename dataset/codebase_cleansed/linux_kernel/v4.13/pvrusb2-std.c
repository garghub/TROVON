static const struct std_name *find_std_name(const struct std_name *arrPtr,
unsigned int arrSize,
const char *bufPtr,
unsigned int bufSize)
{
unsigned int idx;
const struct std_name *p;
for (idx = 0; idx < arrSize; idx++) {
p = arrPtr + idx;
if (strlen(p->name) != bufSize) continue;
if (!memcmp(bufPtr,p->name,bufSize)) return p;
}
return NULL;
}
int pvr2_std_str_to_id(v4l2_std_id *idPtr,const char *bufPtr,
unsigned int bufSize)
{
v4l2_std_id id = 0;
v4l2_std_id cmsk = 0;
v4l2_std_id t;
int mMode = 0;
unsigned int cnt;
char ch;
const struct std_name *sp;
while (bufSize) {
if (!mMode) {
cnt = 0;
while ((cnt < bufSize) && (bufPtr[cnt] != '-')) cnt++;
if (cnt >= bufSize) return 0;
sp = find_std_name(std_groups, ARRAY_SIZE(std_groups),
bufPtr,cnt);
if (!sp) return 0;
cnt++;
bufPtr += cnt;
bufSize -= cnt;
mMode = !0;
cmsk = sp->id;
continue;
}
cnt = 0;
while (cnt < bufSize) {
ch = bufPtr[cnt];
if (ch == ';') {
mMode = 0;
break;
}
if (ch == '/') break;
cnt++;
}
sp = find_std_name(std_items, ARRAY_SIZE(std_items),
bufPtr,cnt);
if (!sp) return 0;
t = sp->id & cmsk;
if (!t) return 0;
id |= t;
if (cnt < bufSize) cnt++;
bufPtr += cnt;
bufSize -= cnt;
}
if (idPtr) *idPtr = id;
return !0;
}
unsigned int pvr2_std_id_to_str(char *bufPtr, unsigned int bufSize,
v4l2_std_id id)
{
unsigned int idx1,idx2;
const struct std_name *ip,*gp;
int gfl,cfl;
unsigned int c1,c2;
cfl = 0;
c1 = 0;
for (idx1 = 0; idx1 < ARRAY_SIZE(std_groups); idx1++) {
gp = std_groups + idx1;
gfl = 0;
for (idx2 = 0; idx2 < ARRAY_SIZE(std_items); idx2++) {
ip = std_items + idx2;
if (!(gp->id & ip->id & id)) continue;
if (!gfl) {
if (cfl) {
c2 = scnprintf(bufPtr,bufSize,";");
c1 += c2;
bufSize -= c2;
bufPtr += c2;
}
cfl = !0;
c2 = scnprintf(bufPtr,bufSize,
"%s-",gp->name);
gfl = !0;
} else {
c2 = scnprintf(bufPtr,bufSize,"/");
}
c1 += c2;
bufSize -= c2;
bufPtr += c2;
c2 = scnprintf(bufPtr,bufSize,
ip->name);
c1 += c2;
bufSize -= c2;
bufPtr += c2;
}
}
return c1;
}
static struct v4l2_standard *match_std(v4l2_std_id id)
{
unsigned int idx;
for (idx = 0; idx < ARRAY_SIZE(generic_standards); idx++) {
if (generic_standards[idx].id & id) {
return generic_standards + idx;
}
}
return NULL;
}
static int pvr2_std_fill(struct v4l2_standard *std,v4l2_std_id id)
{
struct v4l2_standard *template;
int idx;
unsigned int bcnt;
template = match_std(id);
if (!template) return 0;
idx = std->index;
memcpy(std,template,sizeof(*template));
std->index = idx;
std->id = id;
bcnt = pvr2_std_id_to_str(std->name,sizeof(std->name)-1,id);
std->name[bcnt] = 0;
pvr2_trace(PVR2_TRACE_STD,"Set up standard idx=%u name=%s",
std->index,std->name);
return !0;
}
struct v4l2_standard *pvr2_std_create_enum(unsigned int *countptr,
v4l2_std_id id)
{
unsigned int std_cnt = 0;
unsigned int idx,bcnt,idx2;
v4l2_std_id idmsk,cmsk,fmsk;
struct v4l2_standard *stddefs;
if (pvrusb2_debug & PVR2_TRACE_STD) {
char buf[100];
bcnt = pvr2_std_id_to_str(buf,sizeof(buf),id);
pvr2_trace(
PVR2_TRACE_STD,"Mapping standards mask=0x%x (%.*s)",
(int)id,bcnt,buf);
}
*countptr = 0;
std_cnt = 0;
fmsk = 0;
for (idmsk = 1, cmsk = id; cmsk; idmsk <<= 1) {
if (!(idmsk & cmsk)) continue;
cmsk &= ~idmsk;
if (match_std(idmsk)) {
std_cnt++;
continue;
}
fmsk |= idmsk;
}
for (idx2 = 0; idx2 < ARRAY_SIZE(std_mixes); idx2++) {
if ((id & std_mixes[idx2]) == std_mixes[idx2]) std_cnt++;
}
fmsk &= ~CSTD_ATSC;
if (fmsk) {
char buf[100];
bcnt = pvr2_std_id_to_str(buf,sizeof(buf),fmsk);
pvr2_trace(
PVR2_TRACE_ERROR_LEGS,
"WARNING: Failed to classify the following standard(s): %.*s",
bcnt,buf);
}
pvr2_trace(PVR2_TRACE_STD,"Setting up %u unique standard(s)",
std_cnt);
if (!std_cnt) return NULL;
stddefs = kzalloc(sizeof(struct v4l2_standard) * std_cnt,
GFP_KERNEL);
if (!stddefs)
return NULL;
for (idx = 0; idx < std_cnt; idx++)
stddefs[idx].index = idx;
idx = 0;
for (idx2 = 0; (idx2 < ARRAY_SIZE(std_mixes)) && (idx < std_cnt);
idx2++) {
if (!(id & std_mixes[idx2])) continue;
if (pvr2_std_fill(stddefs+idx,std_mixes[idx2])) idx++;
}
for (idmsk = 1, cmsk = id; cmsk && (idx < std_cnt); idmsk <<= 1) {
if (!(idmsk & cmsk)) continue;
cmsk &= ~idmsk;
if (!pvr2_std_fill(stddefs+idx,idmsk)) continue;
idx++;
}
*countptr = std_cnt;
return stddefs;
}
v4l2_std_id pvr2_std_get_usable(void)
{
return CSTD_ALL;
}
