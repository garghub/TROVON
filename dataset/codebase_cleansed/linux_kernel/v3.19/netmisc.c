static int
cifs_inet_pton(const int address_family, const char *cp, int len, void *dst)
{
int ret = 0;
if (address_family == AF_INET)
ret = in4_pton(cp, len, dst, '\\', NULL);
else if (address_family == AF_INET6)
ret = in6_pton(cp, len, dst , '\\', NULL);
cifs_dbg(NOISY, "address conversion returned %d for %*.*s\n",
ret, len, len, cp);
if (ret > 0)
ret = 1;
return ret;
}
int
cifs_convert_address(struct sockaddr *dst, const char *src, int len)
{
int rc, alen, slen;
const char *pct;
char scope_id[13];
struct sockaddr_in *s4 = (struct sockaddr_in *) dst;
struct sockaddr_in6 *s6 = (struct sockaddr_in6 *) dst;
if (cifs_inet_pton(AF_INET, src, len, &s4->sin_addr.s_addr)) {
s4->sin_family = AF_INET;
return 1;
}
pct = memchr(src, '%', len);
alen = pct ? pct - src : len;
rc = cifs_inet_pton(AF_INET6, src, alen, &s6->sin6_addr.s6_addr);
if (!rc)
return rc;
s6->sin6_family = AF_INET6;
if (pct) {
slen = len - (alen + 1);
if (slen <= 0 || slen > 12)
return 0;
memcpy(scope_id, pct + 1, slen);
scope_id[slen] = '\0';
rc = kstrtouint(scope_id, 0, &s6->sin6_scope_id);
rc = (rc == 0) ? 1 : 0;
}
return rc;
}
void
cifs_set_port(struct sockaddr *addr, const unsigned short int port)
{
switch (addr->sa_family) {
case AF_INET:
((struct sockaddr_in *)addr)->sin_port = htons(port);
break;
case AF_INET6:
((struct sockaddr_in6 *)addr)->sin6_port = htons(port);
break;
}
}
static void
cifs_print_status(__u32 status_code)
{
int idx = 0;
while (nt_errs[idx].nt_errstr != NULL) {
if (((nt_errs[idx].nt_errcode) & 0xFFFFFF) ==
(status_code & 0xFFFFFF)) {
pr_notice("Status code returned 0x%08x %s\n",
status_code, nt_errs[idx].nt_errstr);
}
idx++;
}
return;
}
static void
ntstatus_to_dos(__u32 ntstatus, __u8 *eclass, __u16 *ecode)
{
int i;
if (ntstatus == 0) {
*eclass = 0;
*ecode = 0;
return;
}
for (i = 0; ntstatus_to_dos_map[i].ntstatus; i++) {
if (ntstatus == ntstatus_to_dos_map[i].ntstatus) {
*eclass = ntstatus_to_dos_map[i].dos_class;
*ecode = ntstatus_to_dos_map[i].dos_code;
return;
}
}
*eclass = ERRHRD;
*ecode = ERRgeneral;
}
int
map_smb_to_linux_error(char *buf, bool logErr)
{
struct smb_hdr *smb = (struct smb_hdr *)buf;
unsigned int i;
int rc = -EIO;
__u8 smberrclass;
__u16 smberrcode;
if (smb->Status.CifsError == 0)
return 0;
if (smb->Flags2 & SMBFLG2_ERR_STATUS) {
__u32 err = le32_to_cpu(smb->Status.CifsError);
if (logErr && (err != (NT_STATUS_MORE_PROCESSING_REQUIRED)))
cifs_print_status(err);
else if (cifsFYI & CIFS_RC)
cifs_print_status(err);
ntstatus_to_dos(err, &smberrclass, &smberrcode);
} else {
smberrclass = smb->Status.DosError.ErrorClass;
smberrcode = le16_to_cpu(smb->Status.DosError.Error);
}
if (smberrclass == ERRDOS) {
for (i = 0;
i <
sizeof(mapping_table_ERRDOS) /
sizeof(struct smb_to_posix_error); i++) {
if (mapping_table_ERRDOS[i].smb_err == 0)
break;
else if (mapping_table_ERRDOS[i].smb_err ==
smberrcode) {
rc = mapping_table_ERRDOS[i].posix_code;
break;
}
}
} else if (smberrclass == ERRSRV) {
for (i = 0;
i <
sizeof(mapping_table_ERRSRV) /
sizeof(struct smb_to_posix_error); i++) {
if (mapping_table_ERRSRV[i].smb_err == 0)
break;
else if (mapping_table_ERRSRV[i].smb_err ==
smberrcode) {
rc = mapping_table_ERRSRV[i].posix_code;
break;
}
}
}
cifs_dbg(FYI, "Mapping smb error code 0x%x to POSIX err %d\n",
le32_to_cpu(smb->Status.CifsError), rc);
return rc;
}
unsigned int
smbCalcSize(void *buf)
{
struct smb_hdr *ptr = (struct smb_hdr *)buf;
return (sizeof(struct smb_hdr) + (2 * ptr->WordCount) +
2 + get_bcc(ptr));
}
struct timespec
cifs_NTtimeToUnix(__le64 ntutc)
{
struct timespec ts;
s64 t = le64_to_cpu(ntutc) - NTFS_TIME_OFFSET;
u64 abs_t;
if (t < 0) {
abs_t = -t;
ts.tv_nsec = (long)(do_div(abs_t, 10000000) * 100);
ts.tv_nsec = -ts.tv_nsec;
ts.tv_sec = -abs_t;
} else {
abs_t = t;
ts.tv_nsec = (long)do_div(abs_t, 10000000) * 100;
ts.tv_sec = abs_t;
}
return ts;
}
u64
cifs_UnixTimeToNT(struct timespec t)
{
return (u64) t.tv_sec * 10000000 + t.tv_nsec/100 + NTFS_TIME_OFFSET;
}
struct timespec cnvrtDosUnixTm(__le16 le_date, __le16 le_time, int offset)
{
struct timespec ts;
int sec, min, days, month, year;
u16 date = le16_to_cpu(le_date);
u16 time = le16_to_cpu(le_time);
SMB_TIME *st = (SMB_TIME *)&time;
SMB_DATE *sd = (SMB_DATE *)&date;
cifs_dbg(FYI, "date %d time %d\n", date, time);
sec = 2 * st->TwoSeconds;
min = st->Minutes;
if ((sec > 59) || (min > 59))
cifs_dbg(VFS, "illegal time min %d sec %d\n", min, sec);
sec += (min * 60);
sec += 60 * 60 * st->Hours;
if (st->Hours > 24)
cifs_dbg(VFS, "illegal hours %d\n", st->Hours);
days = sd->Day;
month = sd->Month;
if ((days > 31) || (month > 12)) {
cifs_dbg(VFS, "illegal date, month %d day: %d\n", month, days);
if (month > 12)
month = 12;
}
month -= 1;
days += total_days_of_prev_months[month];
days += 3652;
year = sd->Year;
days += year * 365;
days += (year/4);
if (year >= 120)
days = days - 1;
if (year != 120)
days -= ((year & 0x03) == 0) && (month < 2 ? 1 : 0);
sec += 24 * 60 * 60 * days;
ts.tv_sec = sec + offset;
ts.tv_nsec = 0;
return ts;
}
