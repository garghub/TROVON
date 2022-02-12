static void
smb2_print_status(__le32 status)
{
int idx = 0;
while (smb2_error_map_table[idx].status_string != NULL) {
if ((smb2_error_map_table[idx].smb2_status) == status) {
pr_notice("Status code returned 0x%08x %s\n", status,
smb2_error_map_table[idx].status_string);
}
idx++;
}
return;
}
int
map_smb2_to_linux_error(char *buf, bool log_err)
{
struct smb2_sync_hdr *shdr = get_sync_hdr(buf);
unsigned int i;
int rc = -EIO;
__le32 smb2err = shdr->Status;
if (smb2err == 0)
return 0;
if (log_err && (smb2err != STATUS_MORE_PROCESSING_REQUIRED) &&
(smb2err != STATUS_END_OF_FILE))
smb2_print_status(smb2err);
else if (cifsFYI & CIFS_RC)
smb2_print_status(smb2err);
for (i = 0; i < sizeof(smb2_error_map_table) /
sizeof(struct status_to_posix_error); i++) {
if (smb2_error_map_table[i].smb2_status == smb2err) {
rc = smb2_error_map_table[i].posix_error;
break;
}
}
cifs_dbg(FYI, "Mapping SMB2 status code 0x%08x to POSIX err %d\n",
__le32_to_cpu(smb2err), rc);
return rc;
}
