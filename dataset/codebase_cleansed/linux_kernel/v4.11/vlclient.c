static int afs_vl_abort_to_error(u32 abort_code)
{
_enter("%u", abort_code);
switch (abort_code) {
case AFSVL_IDEXIST: return -EEXIST;
case AFSVL_IO: return -EREMOTEIO;
case AFSVL_NAMEEXIST: return -EEXIST;
case AFSVL_CREATEFAIL: return -EREMOTEIO;
case AFSVL_NOENT: return -ENOMEDIUM;
case AFSVL_EMPTY: return -ENOMEDIUM;
case AFSVL_ENTDELETED: return -ENOMEDIUM;
case AFSVL_BADNAME: return -EINVAL;
case AFSVL_BADINDEX: return -EINVAL;
case AFSVL_BADVOLTYPE: return -EINVAL;
case AFSVL_BADSERVER: return -EINVAL;
case AFSVL_BADPARTITION: return -EINVAL;
case AFSVL_REPSFULL: return -EFBIG;
case AFSVL_NOREPSERVER: return -ENOENT;
case AFSVL_DUPREPSERVER: return -EEXIST;
case AFSVL_RWNOTFOUND: return -ENOENT;
case AFSVL_BADREFCOUNT: return -EINVAL;
case AFSVL_SIZEEXCEEDED: return -EINVAL;
case AFSVL_BADENTRY: return -EINVAL;
case AFSVL_BADVOLIDBUMP: return -EINVAL;
case AFSVL_IDALREADYHASHED: return -EINVAL;
case AFSVL_ENTRYLOCKED: return -EBUSY;
case AFSVL_BADVOLOPER: return -EBADRQC;
case AFSVL_BADRELLOCKTYPE: return -EINVAL;
case AFSVL_RERELEASE: return -EREMOTEIO;
case AFSVL_BADSERVERFLAG: return -EINVAL;
case AFSVL_PERM: return -EACCES;
case AFSVL_NOMEM: return -EREMOTEIO;
default:
return afs_abort_to_error(abort_code);
}
}
static int afs_deliver_vl_get_entry_by_xxx(struct afs_call *call)
{
struct afs_cache_vlocation *entry;
__be32 *bp;
u32 tmp;
int loop, ret;
_enter("");
ret = afs_transfer_reply(call);
if (ret < 0)
return ret;
entry = call->reply;
bp = call->buffer;
for (loop = 0; loop < 64; loop++)
entry->name[loop] = ntohl(*bp++);
entry->name[loop] = 0;
bp++;
bp++;
entry->nservers = ntohl(*bp++);
for (loop = 0; loop < 8; loop++)
entry->servers[loop].s_addr = *bp++;
bp += 8;
for (loop = 0; loop < 8; loop++) {
tmp = ntohl(*bp++);
entry->srvtmask[loop] = 0;
if (tmp & AFS_VLSF_RWVOL)
entry->srvtmask[loop] |= AFS_VOL_VTM_RW;
if (tmp & AFS_VLSF_ROVOL)
entry->srvtmask[loop] |= AFS_VOL_VTM_RO;
if (tmp & AFS_VLSF_BACKVOL)
entry->srvtmask[loop] |= AFS_VOL_VTM_BAK;
}
entry->vid[0] = ntohl(*bp++);
entry->vid[1] = ntohl(*bp++);
entry->vid[2] = ntohl(*bp++);
bp++;
tmp = ntohl(*bp++);
entry->vidmask = 0;
if (tmp & AFS_VLF_RWEXISTS)
entry->vidmask |= AFS_VOL_VTM_RW;
if (tmp & AFS_VLF_ROEXISTS)
entry->vidmask |= AFS_VOL_VTM_RO;
if (tmp & AFS_VLF_BACKEXISTS)
entry->vidmask |= AFS_VOL_VTM_BAK;
if (!entry->vidmask)
return -EBADMSG;
_leave(" = 0 [done]");
return 0;
}
int afs_vl_get_entry_by_name(struct in_addr *addr,
struct key *key,
const char *volname,
struct afs_cache_vlocation *entry,
bool async)
{
struct afs_call *call;
size_t volnamesz, reqsz, padsz;
__be32 *bp;
_enter("");
volnamesz = strlen(volname);
padsz = (4 - (volnamesz & 3)) & 3;
reqsz = 8 + volnamesz + padsz;
call = afs_alloc_flat_call(&afs_RXVLGetEntryByName, reqsz, 384);
if (!call)
return -ENOMEM;
call->key = key;
call->reply = entry;
call->service_id = VL_SERVICE;
call->port = htons(AFS_VL_PORT);
bp = call->request;
*bp++ = htonl(VLGETENTRYBYNAME);
*bp++ = htonl(volnamesz);
memcpy(bp, volname, volnamesz);
if (padsz > 0)
memset((void *) bp + volnamesz, 0, padsz);
return afs_make_call(addr, call, GFP_KERNEL, async);
}
int afs_vl_get_entry_by_id(struct in_addr *addr,
struct key *key,
afs_volid_t volid,
afs_voltype_t voltype,
struct afs_cache_vlocation *entry,
bool async)
{
struct afs_call *call;
__be32 *bp;
_enter("");
call = afs_alloc_flat_call(&afs_RXVLGetEntryById, 12, 384);
if (!call)
return -ENOMEM;
call->key = key;
call->reply = entry;
call->service_id = VL_SERVICE;
call->port = htons(AFS_VL_PORT);
bp = call->request;
*bp++ = htonl(VLGETENTRYBYID);
*bp++ = htonl(volid);
*bp = htonl(voltype);
return afs_make_call(addr, call, GFP_KERNEL, async);
}
