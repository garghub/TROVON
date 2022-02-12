static int
check_smb2_hdr(struct smb2_hdr *hdr, __u64 mid)
{
if ((*(__le32 *)hdr->ProtocolId == SMB2_PROTO_NUMBER) &&
(mid == hdr->MessageId)) {
if (hdr->Flags & SMB2_FLAGS_SERVER_TO_REDIR)
return 0;
else {
if (hdr->Command == SMB2_OPLOCK_BREAK)
return 0;
else
cERROR(1, "Received Request not response");
}
} else {
if (*(__le32 *)hdr->ProtocolId != SMB2_PROTO_NUMBER)
cERROR(1, "Bad protocol string signature header %x",
*(unsigned int *) hdr->ProtocolId);
if (mid != hdr->MessageId)
cERROR(1, "Mids do not match: %llu and %llu", mid,
hdr->MessageId);
}
cERROR(1, "Bad SMB detected. The Mid=%llu", hdr->MessageId);
return 1;
}
int
smb2_check_message(char *buf, unsigned int length)
{
struct smb2_hdr *hdr = (struct smb2_hdr *)buf;
struct smb2_pdu *pdu = (struct smb2_pdu *)hdr;
__u64 mid = hdr->MessageId;
__u32 len = get_rfc1002_length(buf);
__u32 clc_len;
int command;
cFYI(1, "%s length: 0x%x, smb_buf_length: 0x%x", __func__, length, len);
if (length < sizeof(struct smb2_pdu)) {
if ((length >= sizeof(struct smb2_hdr)) && (hdr->Status != 0)) {
pdu->StructureSize2 = 0;
return 0;
} else {
cERROR(1, "Length less than SMB header size");
}
return 1;
}
if (len > CIFSMaxBufSize + MAX_SMB2_HDR_SIZE - 4) {
cERROR(1, "SMB length greater than maximum, mid=%llu", mid);
return 1;
}
if (check_smb2_hdr(hdr, mid))
return 1;
if (hdr->StructureSize != SMB2_HEADER_STRUCTURE_SIZE) {
cERROR(1, "Illegal structure size %u",
le16_to_cpu(hdr->StructureSize));
return 1;
}
command = le16_to_cpu(hdr->Command);
if (command >= NUMBER_OF_SMB2_COMMANDS) {
cERROR(1, "Illegal SMB2 command %d", command);
return 1;
}
if (smb2_rsp_struct_sizes[command] != pdu->StructureSize2) {
if (command != SMB2_OPLOCK_BREAK_HE && (hdr->Status == 0 ||
pdu->StructureSize2 != SMB2_ERROR_STRUCTURE_SIZE2)) {
cERROR(1, "Illegal response size %u for command %d",
le16_to_cpu(pdu->StructureSize2), command);
return 1;
} else if (command == SMB2_OPLOCK_BREAK_HE && (hdr->Status == 0)
&& (le16_to_cpu(pdu->StructureSize2) != 44)
&& (le16_to_cpu(pdu->StructureSize2) != 36)) {
cERROR(1, "Illegal response size %d for oplock break",
le16_to_cpu(pdu->StructureSize2));
return 1;
}
}
if (4 + len != length) {
cERROR(1, "Total length %u RFC1002 length %u mismatch mid %llu",
length, 4 + len, mid);
return 1;
}
clc_len = smb2_calc_size(hdr);
if (4 + len != clc_len) {
cFYI(1, "Calculated size %u length %u mismatch mid %llu",
clc_len, 4 + len, mid);
if (clc_len + 20 == len && command == SMB2_OPLOCK_BREAK_HE)
return 0;
if (clc_len == 4 + len + 1)
return 0;
return 1;
}
return 0;
}
char *
smb2_get_data_area_len(int *off, int *len, struct smb2_hdr *hdr)
{
*off = 0;
*len = 0;
if (hdr->Status && hdr->Status != STATUS_MORE_PROCESSING_REQUIRED &&
(((struct smb2_err_rsp *)hdr)->StructureSize) ==
SMB2_ERROR_STRUCTURE_SIZE2)
return NULL;
switch (hdr->Command) {
case SMB2_NEGOTIATE:
*off = le16_to_cpu(
((struct smb2_negotiate_rsp *)hdr)->SecurityBufferOffset);
*len = le16_to_cpu(
((struct smb2_negotiate_rsp *)hdr)->SecurityBufferLength);
break;
case SMB2_SESSION_SETUP:
*off = le16_to_cpu(
((struct smb2_sess_setup_rsp *)hdr)->SecurityBufferOffset);
*len = le16_to_cpu(
((struct smb2_sess_setup_rsp *)hdr)->SecurityBufferLength);
break;
case SMB2_CREATE:
*off = le32_to_cpu(
((struct smb2_create_rsp *)hdr)->CreateContextsOffset);
*len = le32_to_cpu(
((struct smb2_create_rsp *)hdr)->CreateContextsLength);
break;
case SMB2_QUERY_INFO:
*off = le16_to_cpu(
((struct smb2_query_info_rsp *)hdr)->OutputBufferOffset);
*len = le32_to_cpu(
((struct smb2_query_info_rsp *)hdr)->OutputBufferLength);
break;
case SMB2_READ:
*off = ((struct smb2_read_rsp *)hdr)->DataOffset;
*len = le32_to_cpu(((struct smb2_read_rsp *)hdr)->DataLength);
break;
case SMB2_QUERY_DIRECTORY:
*off = le16_to_cpu(
((struct smb2_query_directory_rsp *)hdr)->OutputBufferOffset);
*len = le32_to_cpu(
((struct smb2_query_directory_rsp *)hdr)->OutputBufferLength);
break;
case SMB2_IOCTL:
case SMB2_CHANGE_NOTIFY:
default:
cERROR(1, "no length check for command");
break;
}
if (*off > 4096) {
cERROR(1, "offset %d too large, data area ignored", *off);
*len = 0;
*off = 0;
} else if (*off < 0) {
cERROR(1, "negative offset %d to data invalid ignore data area",
*off);
*off = 0;
*len = 0;
} else if (*len < 0) {
cERROR(1, "negative data length %d invalid, data area ignored",
*len);
*len = 0;
} else if (*len > 128 * 1024) {
cERROR(1, "data area larger than 128K: %d", *len);
*len = 0;
}
if ((*off != 0) && (*len != 0))
return hdr->ProtocolId + *off;
else
return NULL;
}
unsigned int
smb2_calc_size(void *buf)
{
struct smb2_hdr *hdr = (struct smb2_hdr *)buf;
struct smb2_pdu *pdu = (struct smb2_pdu *)hdr;
int offset;
int data_length;
int len = 4 + le16_to_cpu(pdu->hdr.StructureSize);
len += le16_to_cpu(pdu->StructureSize2);
if (has_smb2_data_area[le16_to_cpu(hdr->Command)] == false)
goto calc_size_exit;
smb2_get_data_area_len(&offset, &data_length, hdr);
cFYI(1, "SMB2 data length %d offset %d", data_length, offset);
if (data_length > 0) {
if (offset + 4 + 1 < len) {
cERROR(1, "data area offset %d overlaps SMB2 header %d",
offset + 4 + 1, len);
data_length = 0;
} else {
len = 4 + offset + data_length;
}
}
calc_size_exit:
cFYI(1, "SMB2 len %d", len);
return len;
}
__le16 *
cifs_convert_path_to_utf16(const char *from, struct cifs_sb_info *cifs_sb)
{
int len;
const char *start_of_path;
__le16 *to;
if (from[0] == '\\')
start_of_path = from + 1;
else
start_of_path = from;
to = cifs_strndup_to_utf16(start_of_path, PATH_MAX, &len,
cifs_sb->local_nls,
cifs_sb->mnt_cifs_flags &
CIFS_MOUNT_MAP_SPECIAL_CHR);
return to;
}
__le32
smb2_get_lease_state(struct cifsInodeInfo *cinode)
{
if (cinode->clientCanCacheAll)
return SMB2_LEASE_WRITE_CACHING | SMB2_LEASE_READ_CACHING;
else if (cinode->clientCanCacheRead)
return SMB2_LEASE_READ_CACHING;
return 0;
}
__u8 smb2_map_lease_to_oplock(__le32 lease_state)
{
if (lease_state & SMB2_LEASE_WRITE_CACHING) {
if (lease_state & SMB2_LEASE_HANDLE_CACHING)
return SMB2_OPLOCK_LEVEL_BATCH;
else
return SMB2_OPLOCK_LEVEL_EXCLUSIVE;
} else if (lease_state & SMB2_LEASE_READ_CACHING)
return SMB2_OPLOCK_LEVEL_II;
return 0;
}
static void
cifs_ses_oplock_break(struct work_struct *work)
{
struct smb2_lease_break_work *lw = container_of(work,
struct smb2_lease_break_work, lease_break);
int rc;
rc = SMB2_lease_break(0, tlink_tcon(lw->tlink), lw->lease_key,
lw->lease_state);
cFYI(1, "Lease release rc %d", rc);
cifs_put_tlink(lw->tlink);
kfree(lw);
}
static bool
smb2_is_valid_lease_break(char *buffer, struct TCP_Server_Info *server)
{
struct smb2_lease_break *rsp = (struct smb2_lease_break *)buffer;
struct list_head *tmp, *tmp1, *tmp2;
struct cifs_ses *ses;
struct cifs_tcon *tcon;
struct cifsInodeInfo *cinode;
struct cifsFileInfo *cfile;
struct cifs_pending_open *open;
struct smb2_lease_break_work *lw;
bool found;
int ack_req = le32_to_cpu(rsp->Flags &
SMB2_NOTIFY_BREAK_LEASE_FLAG_ACK_REQUIRED);
lw = kmalloc(sizeof(struct smb2_lease_break_work), GFP_KERNEL);
if (!lw) {
cERROR(1, "Memory allocation failed during lease break check");
return false;
}
INIT_WORK(&lw->lease_break, cifs_ses_oplock_break);
lw->lease_state = rsp->NewLeaseState;
cFYI(1, "Checking for lease break");
spin_lock(&cifs_tcp_ses_lock);
list_for_each(tmp, &server->smb_ses_list) {
ses = list_entry(tmp, struct cifs_ses, smb_ses_list);
spin_lock(&cifs_file_list_lock);
list_for_each(tmp1, &ses->tcon_list) {
tcon = list_entry(tmp1, struct cifs_tcon, tcon_list);
cifs_stats_inc(&tcon->stats.cifs_stats.num_oplock_brks);
list_for_each(tmp2, &tcon->openFileList) {
cfile = list_entry(tmp2, struct cifsFileInfo,
tlist);
cinode = CIFS_I(cfile->dentry->d_inode);
if (memcmp(cinode->lease_key, rsp->LeaseKey,
SMB2_LEASE_KEY_SIZE))
continue;
cFYI(1, "found in the open list");
cFYI(1, "lease key match, lease break 0x%d",
le32_to_cpu(rsp->NewLeaseState));
smb2_set_oplock_level(cinode,
smb2_map_lease_to_oplock(rsp->NewLeaseState));
if (ack_req)
cfile->oplock_break_cancelled = false;
else
cfile->oplock_break_cancelled = true;
queue_work(cifsiod_wq, &cfile->oplock_break);
spin_unlock(&cifs_file_list_lock);
spin_unlock(&cifs_tcp_ses_lock);
return true;
}
found = false;
list_for_each_entry(open, &tcon->pending_opens, olist) {
if (memcmp(open->lease_key, rsp->LeaseKey,
SMB2_LEASE_KEY_SIZE))
continue;
if (!found && ack_req) {
found = true;
memcpy(lw->lease_key, open->lease_key,
SMB2_LEASE_KEY_SIZE);
lw->tlink = cifs_get_tlink(open->tlink);
queue_work(cifsiod_wq,
&lw->lease_break);
}
cFYI(1, "found in the pending open list");
cFYI(1, "lease key match, lease break 0x%d",
le32_to_cpu(rsp->NewLeaseState));
open->oplock =
smb2_map_lease_to_oplock(rsp->NewLeaseState);
}
if (found) {
spin_unlock(&cifs_file_list_lock);
spin_unlock(&cifs_tcp_ses_lock);
return true;
}
}
spin_unlock(&cifs_file_list_lock);
}
spin_unlock(&cifs_tcp_ses_lock);
kfree(lw);
cFYI(1, "Can not process lease break - no lease matched");
return false;
}
bool
smb2_is_valid_oplock_break(char *buffer, struct TCP_Server_Info *server)
{
struct smb2_oplock_break *rsp = (struct smb2_oplock_break *)buffer;
struct list_head *tmp, *tmp1, *tmp2;
struct cifs_ses *ses;
struct cifs_tcon *tcon;
struct cifsInodeInfo *cinode;
struct cifsFileInfo *cfile;
cFYI(1, "Checking for oplock break");
if (rsp->hdr.Command != SMB2_OPLOCK_BREAK)
return false;
if (rsp->StructureSize !=
smb2_rsp_struct_sizes[SMB2_OPLOCK_BREAK_HE]) {
if (le16_to_cpu(rsp->StructureSize) == 44)
return smb2_is_valid_lease_break(buffer, server);
else
return false;
}
cFYI(1, "oplock level 0x%d", rsp->OplockLevel);
spin_lock(&cifs_tcp_ses_lock);
list_for_each(tmp, &server->smb_ses_list) {
ses = list_entry(tmp, struct cifs_ses, smb_ses_list);
list_for_each(tmp1, &ses->tcon_list) {
tcon = list_entry(tmp1, struct cifs_tcon, tcon_list);
cifs_stats_inc(&tcon->stats.cifs_stats.num_oplock_brks);
spin_lock(&cifs_file_list_lock);
list_for_each(tmp2, &tcon->openFileList) {
cfile = list_entry(tmp2, struct cifsFileInfo,
tlist);
if (rsp->PersistentFid !=
cfile->fid.persistent_fid ||
rsp->VolatileFid !=
cfile->fid.volatile_fid)
continue;
cFYI(1, "file id match, oplock break");
cinode = CIFS_I(cfile->dentry->d_inode);
if (!cinode->clientCanCacheAll &&
rsp->OplockLevel == SMB2_OPLOCK_LEVEL_NONE)
cfile->oplock_break_cancelled = true;
else
cfile->oplock_break_cancelled = false;
smb2_set_oplock_level(cinode,
rsp->OplockLevel ? SMB2_OPLOCK_LEVEL_II : 0);
queue_work(cifsiod_wq, &cfile->oplock_break);
spin_unlock(&cifs_file_list_lock);
spin_unlock(&cifs_tcp_ses_lock);
return true;
}
spin_unlock(&cifs_file_list_lock);
spin_unlock(&cifs_tcp_ses_lock);
cFYI(1, "No matching file for oplock break");
return true;
}
}
spin_unlock(&cifs_tcp_ses_lock);
cFYI(1, "Can not process oplock break for non-existent connection");
return false;
}
