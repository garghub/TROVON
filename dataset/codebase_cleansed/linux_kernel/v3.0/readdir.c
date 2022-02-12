static void dump_cifs_file_struct(struct file *file, char *label)
{
struct cifsFileInfo *cf;
if (file) {
cf = file->private_data;
if (cf == NULL) {
cFYI(1, "empty cifs private file data");
return;
}
if (cf->invalidHandle)
cFYI(1, "invalid handle");
if (cf->srch_inf.endOfSearch)
cFYI(1, "end of search");
if (cf->srch_inf.emptyDir)
cFYI(1, "empty dir");
}
}
static inline void dump_cifs_file_struct(struct file *file, char *label)
{
}
static struct dentry *
cifs_readdir_lookup(struct dentry *parent, struct qstr *name,
struct cifs_fattr *fattr)
{
struct dentry *dentry, *alias;
struct inode *inode;
struct super_block *sb = parent->d_inode->i_sb;
cFYI(1, "For %s", name->name);
if (parent->d_op && parent->d_op->d_hash)
parent->d_op->d_hash(parent, parent->d_inode, name);
else
name->hash = full_name_hash(name->name, name->len);
dentry = d_lookup(parent, name);
if (dentry) {
if (dentry->d_inode != NULL)
return dentry;
d_drop(dentry);
dput(dentry);
}
dentry = d_alloc(parent, name);
if (dentry == NULL)
return NULL;
inode = cifs_iget(sb, fattr);
if (!inode) {
dput(dentry);
return NULL;
}
alias = d_materialise_unique(dentry, inode);
if (alias != NULL) {
dput(dentry);
if (IS_ERR(alias))
return NULL;
dentry = alias;
}
return dentry;
}
static void
cifs_fill_common_info(struct cifs_fattr *fattr, struct cifs_sb_info *cifs_sb)
{
fattr->cf_uid = cifs_sb->mnt_uid;
fattr->cf_gid = cifs_sb->mnt_gid;
if (fattr->cf_cifsattrs & ATTR_DIRECTORY) {
fattr->cf_mode = S_IFDIR | cifs_sb->mnt_dir_mode;
fattr->cf_dtype = DT_DIR;
} else {
fattr->cf_mode = S_IFREG | cifs_sb->mnt_file_mode;
fattr->cf_dtype = DT_REG;
}
if (fattr->cf_cifsattrs & ATTR_READONLY)
fattr->cf_mode &= ~S_IWUGO;
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_UNX_EMUL &&
fattr->cf_cifsattrs & ATTR_SYSTEM) {
if (fattr->cf_eof == 0) {
fattr->cf_mode &= ~S_IFMT;
fattr->cf_mode |= S_IFIFO;
fattr->cf_dtype = DT_FIFO;
} else {
fattr->cf_flags |= CIFS_FATTR_NEED_REVAL;
}
}
}
static void
cifs_dir_info_to_fattr(struct cifs_fattr *fattr, FILE_DIRECTORY_INFO *info,
struct cifs_sb_info *cifs_sb)
{
memset(fattr, 0, sizeof(*fattr));
fattr->cf_cifsattrs = le32_to_cpu(info->ExtFileAttributes);
fattr->cf_eof = le64_to_cpu(info->EndOfFile);
fattr->cf_bytes = le64_to_cpu(info->AllocationSize);
fattr->cf_createtime = le64_to_cpu(info->CreationTime);
fattr->cf_atime = cifs_NTtimeToUnix(info->LastAccessTime);
fattr->cf_ctime = cifs_NTtimeToUnix(info->ChangeTime);
fattr->cf_mtime = cifs_NTtimeToUnix(info->LastWriteTime);
cifs_fill_common_info(fattr, cifs_sb);
}
static void
cifs_std_info_to_fattr(struct cifs_fattr *fattr, FIND_FILE_STANDARD_INFO *info,
struct cifs_sb_info *cifs_sb)
{
int offset = cifs_sb_master_tcon(cifs_sb)->ses->server->timeAdj;
memset(fattr, 0, sizeof(*fattr));
fattr->cf_atime = cnvrtDosUnixTm(info->LastAccessDate,
info->LastAccessTime, offset);
fattr->cf_ctime = cnvrtDosUnixTm(info->LastWriteDate,
info->LastWriteTime, offset);
fattr->cf_mtime = cnvrtDosUnixTm(info->LastWriteDate,
info->LastWriteTime, offset);
fattr->cf_cifsattrs = le16_to_cpu(info->Attributes);
fattr->cf_bytes = le32_to_cpu(info->AllocationSize);
fattr->cf_eof = le32_to_cpu(info->DataSize);
cifs_fill_common_info(fattr, cifs_sb);
}
static int initiate_cifs_search(const int xid, struct file *file)
{
int rc = 0;
char *full_path = NULL;
struct cifsFileInfo *cifsFile;
struct cifs_sb_info *cifs_sb = CIFS_SB(file->f_path.dentry->d_sb);
struct tcon_link *tlink = NULL;
struct cifs_tcon *pTcon;
if (file->private_data == NULL) {
tlink = cifs_sb_tlink(cifs_sb);
if (IS_ERR(tlink))
return PTR_ERR(tlink);
cifsFile = kzalloc(sizeof(struct cifsFileInfo), GFP_KERNEL);
if (cifsFile == NULL) {
rc = -ENOMEM;
goto error_exit;
}
file->private_data = cifsFile;
cifsFile->tlink = cifs_get_tlink(tlink);
pTcon = tlink_tcon(tlink);
} else {
cifsFile = file->private_data;
pTcon = tlink_tcon(cifsFile->tlink);
}
cifsFile->invalidHandle = true;
cifsFile->srch_inf.endOfSearch = false;
full_path = build_path_from_dentry(file->f_path.dentry);
if (full_path == NULL) {
rc = -ENOMEM;
goto error_exit;
}
cFYI(1, "Full path: %s start at: %lld", full_path, file->f_pos);
ffirst_retry:
if (pTcon->unix_ext)
cifsFile->srch_inf.info_level = SMB_FIND_FILE_UNIX;
else if ((pTcon->ses->capabilities &
(CAP_NT_SMBS | CAP_NT_FIND)) == 0) {
cifsFile->srch_inf.info_level = SMB_FIND_FILE_INFO_STANDARD;
} else if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_SERVER_INUM) {
cifsFile->srch_inf.info_level = SMB_FIND_FILE_ID_FULL_DIR_INFO;
} else {
cifsFile->srch_inf.info_level = SMB_FIND_FILE_DIRECTORY_INFO;
}
rc = CIFSFindFirst(xid, pTcon, full_path, cifs_sb->local_nls,
&cifsFile->netfid, &cifsFile->srch_inf,
cifs_sb->mnt_cifs_flags &
CIFS_MOUNT_MAP_SPECIAL_CHR, CIFS_DIR_SEP(cifs_sb));
if (rc == 0)
cifsFile->invalidHandle = false;
else if ((rc == -EOPNOTSUPP) &&
(cifs_sb->mnt_cifs_flags & CIFS_MOUNT_SERVER_INUM)) {
cifs_sb->mnt_cifs_flags &= ~CIFS_MOUNT_SERVER_INUM;
goto ffirst_retry;
}
error_exit:
kfree(full_path);
cifs_put_tlink(tlink);
return rc;
}
static int cifs_unicode_bytelen(char *str)
{
int len;
__le16 *ustr = (__le16 *)str;
for (len = 0; len <= PATH_MAX; len++) {
if (ustr[len] == 0)
return len << 1;
}
cFYI(1, "Unicode string longer than PATH_MAX found");
return len << 1;
}
static char *nxt_dir_entry(char *old_entry, char *end_of_smb, int level)
{
char *new_entry;
FILE_DIRECTORY_INFO *pDirInfo = (FILE_DIRECTORY_INFO *)old_entry;
if (level == SMB_FIND_FILE_INFO_STANDARD) {
FIND_FILE_STANDARD_INFO *pfData;
pfData = (FIND_FILE_STANDARD_INFO *)pDirInfo;
new_entry = old_entry + sizeof(FIND_FILE_STANDARD_INFO) +
pfData->FileNameLength;
} else
new_entry = old_entry + le32_to_cpu(pDirInfo->NextEntryOffset);
cFYI(1, "new entry %p old entry %p", new_entry, old_entry);
if (new_entry >= end_of_smb) {
cERROR(1, "search entry %p began after end of SMB %p old entry %p",
new_entry, end_of_smb, old_entry);
return NULL;
} else if (((level == SMB_FIND_FILE_INFO_STANDARD) &&
(new_entry + sizeof(FIND_FILE_STANDARD_INFO) > end_of_smb))
|| ((level != SMB_FIND_FILE_INFO_STANDARD) &&
(new_entry + sizeof(FILE_DIRECTORY_INFO) > end_of_smb))) {
cERROR(1, "search entry %p extends after end of SMB %p",
new_entry, end_of_smb);
return NULL;
} else
return new_entry;
}
static int cifs_entry_is_dot(char *current_entry, struct cifsFileInfo *cfile)
{
int rc = 0;
char *filename = NULL;
int len = 0;
if (cfile->srch_inf.info_level == SMB_FIND_FILE_UNIX) {
FILE_UNIX_INFO *pFindData = (FILE_UNIX_INFO *)current_entry;
filename = &pFindData->FileName[0];
if (cfile->srch_inf.unicode) {
len = cifs_unicode_bytelen(filename);
} else {
len = strnlen(filename, 5);
}
} else if (cfile->srch_inf.info_level == SMB_FIND_FILE_DIRECTORY_INFO) {
FILE_DIRECTORY_INFO *pFindData =
(FILE_DIRECTORY_INFO *)current_entry;
filename = &pFindData->FileName[0];
len = le32_to_cpu(pFindData->FileNameLength);
} else if (cfile->srch_inf.info_level ==
SMB_FIND_FILE_FULL_DIRECTORY_INFO) {
FILE_FULL_DIRECTORY_INFO *pFindData =
(FILE_FULL_DIRECTORY_INFO *)current_entry;
filename = &pFindData->FileName[0];
len = le32_to_cpu(pFindData->FileNameLength);
} else if (cfile->srch_inf.info_level ==
SMB_FIND_FILE_ID_FULL_DIR_INFO) {
SEARCH_ID_FULL_DIR_INFO *pFindData =
(SEARCH_ID_FULL_DIR_INFO *)current_entry;
filename = &pFindData->FileName[0];
len = le32_to_cpu(pFindData->FileNameLength);
} else if (cfile->srch_inf.info_level ==
SMB_FIND_FILE_BOTH_DIRECTORY_INFO) {
FILE_BOTH_DIRECTORY_INFO *pFindData =
(FILE_BOTH_DIRECTORY_INFO *)current_entry;
filename = &pFindData->FileName[0];
len = le32_to_cpu(pFindData->FileNameLength);
} else if (cfile->srch_inf.info_level == SMB_FIND_FILE_INFO_STANDARD) {
FIND_FILE_STANDARD_INFO *pFindData =
(FIND_FILE_STANDARD_INFO *)current_entry;
filename = &pFindData->FileName[0];
len = pFindData->FileNameLength;
} else {
cFYI(1, "Unknown findfirst level %d",
cfile->srch_inf.info_level);
}
if (filename) {
if (cfile->srch_inf.unicode) {
__le16 *ufilename = (__le16 *)filename;
if (len == 2) {
if (ufilename[0] == UNICODE_DOT)
rc = 1;
} else if (len == 4) {
if ((ufilename[0] == UNICODE_DOT)
&& (ufilename[1] == UNICODE_DOT))
rc = 2;
}
} else {
if (len == 1) {
if (filename[0] == '.')
rc = 1;
} else if (len == 2) {
if ((filename[0] == '.') && (filename[1] == '.'))
rc = 2;
}
}
}
return rc;
}
static int is_dir_changed(struct file *file)
{
struct inode *inode = file->f_path.dentry->d_inode;
struct cifsInodeInfo *cifsInfo = CIFS_I(inode);
if (cifsInfo->time == 0)
return 1;
else
return 0;
}
static int cifs_save_resume_key(const char *current_entry,
struct cifsFileInfo *cifsFile)
{
int rc = 0;
unsigned int len = 0;
__u16 level;
char *filename;
if ((cifsFile == NULL) || (current_entry == NULL))
return -EINVAL;
level = cifsFile->srch_inf.info_level;
if (level == SMB_FIND_FILE_UNIX) {
FILE_UNIX_INFO *pFindData = (FILE_UNIX_INFO *)current_entry;
filename = &pFindData->FileName[0];
if (cifsFile->srch_inf.unicode) {
len = cifs_unicode_bytelen(filename);
} else {
len = strnlen(filename, PATH_MAX);
}
cifsFile->srch_inf.resume_key = pFindData->ResumeKey;
} else if (level == SMB_FIND_FILE_DIRECTORY_INFO) {
FILE_DIRECTORY_INFO *pFindData =
(FILE_DIRECTORY_INFO *)current_entry;
filename = &pFindData->FileName[0];
len = le32_to_cpu(pFindData->FileNameLength);
cifsFile->srch_inf.resume_key = pFindData->FileIndex;
} else if (level == SMB_FIND_FILE_FULL_DIRECTORY_INFO) {
FILE_FULL_DIRECTORY_INFO *pFindData =
(FILE_FULL_DIRECTORY_INFO *)current_entry;
filename = &pFindData->FileName[0];
len = le32_to_cpu(pFindData->FileNameLength);
cifsFile->srch_inf.resume_key = pFindData->FileIndex;
} else if (level == SMB_FIND_FILE_ID_FULL_DIR_INFO) {
SEARCH_ID_FULL_DIR_INFO *pFindData =
(SEARCH_ID_FULL_DIR_INFO *)current_entry;
filename = &pFindData->FileName[0];
len = le32_to_cpu(pFindData->FileNameLength);
cifsFile->srch_inf.resume_key = pFindData->FileIndex;
} else if (level == SMB_FIND_FILE_BOTH_DIRECTORY_INFO) {
FILE_BOTH_DIRECTORY_INFO *pFindData =
(FILE_BOTH_DIRECTORY_INFO *)current_entry;
filename = &pFindData->FileName[0];
len = le32_to_cpu(pFindData->FileNameLength);
cifsFile->srch_inf.resume_key = pFindData->FileIndex;
} else if (level == SMB_FIND_FILE_INFO_STANDARD) {
FIND_FILE_STANDARD_INFO *pFindData =
(FIND_FILE_STANDARD_INFO *)current_entry;
filename = &pFindData->FileName[0];
len = (unsigned int)pFindData->FileNameLength;
cifsFile->srch_inf.resume_key = pFindData->ResumeKey;
} else {
cFYI(1, "Unknown findfirst level %d", level);
return -EINVAL;
}
cifsFile->srch_inf.resume_name_len = len;
cifsFile->srch_inf.presume_name = filename;
return rc;
}
static int find_cifs_entry(const int xid, struct cifs_tcon *pTcon,
struct file *file, char **ppCurrentEntry, int *num_to_ret)
{
int rc = 0;
int pos_in_buf = 0;
loff_t first_entry_in_buffer;
loff_t index_to_find = file->f_pos;
struct cifsFileInfo *cifsFile = file->private_data;
if ((cifsFile == NULL) || (ppCurrentEntry == NULL) ||
(num_to_ret == NULL))
return -ENOENT;
*ppCurrentEntry = NULL;
first_entry_in_buffer =
cifsFile->srch_inf.index_of_last_entry -
cifsFile->srch_inf.entries_in_buffer;
dump_cifs_file_struct(file, "In fce ");
if (((index_to_find < cifsFile->srch_inf.index_of_last_entry) &&
is_dir_changed(file)) ||
(index_to_find < first_entry_in_buffer)) {
cFYI(1, "search backing up - close and restart search");
spin_lock(&cifs_file_list_lock);
if (!cifsFile->srch_inf.endOfSearch &&
!cifsFile->invalidHandle) {
cifsFile->invalidHandle = true;
spin_unlock(&cifs_file_list_lock);
CIFSFindClose(xid, pTcon, cifsFile->netfid);
} else
spin_unlock(&cifs_file_list_lock);
if (cifsFile->srch_inf.ntwrk_buf_start) {
cFYI(1, "freeing SMB ff cache buf on search rewind");
if (cifsFile->srch_inf.smallBuf)
cifs_small_buf_release(cifsFile->srch_inf.
ntwrk_buf_start);
else
cifs_buf_release(cifsFile->srch_inf.
ntwrk_buf_start);
cifsFile->srch_inf.ntwrk_buf_start = NULL;
}
rc = initiate_cifs_search(xid, file);
if (rc) {
cFYI(1, "error %d reinitiating a search on rewind",
rc);
return rc;
}
cifs_save_resume_key(cifsFile->srch_inf.last_entry, cifsFile);
}
while ((index_to_find >= cifsFile->srch_inf.index_of_last_entry) &&
(rc == 0) && !cifsFile->srch_inf.endOfSearch) {
cFYI(1, "calling findnext2");
rc = CIFSFindNext(xid, pTcon, cifsFile->netfid,
&cifsFile->srch_inf);
cifs_save_resume_key(cifsFile->srch_inf.last_entry, cifsFile);
if (rc)
return -ENOENT;
}
if (index_to_find < cifsFile->srch_inf.index_of_last_entry) {
int i;
char *current_entry;
char *end_of_smb = cifsFile->srch_inf.ntwrk_buf_start +
smbCalcSize((struct smb_hdr *)
cifsFile->srch_inf.ntwrk_buf_start);
current_entry = cifsFile->srch_inf.srch_entries_start;
first_entry_in_buffer = cifsFile->srch_inf.index_of_last_entry
- cifsFile->srch_inf.entries_in_buffer;
pos_in_buf = index_to_find - first_entry_in_buffer;
cFYI(1, "found entry - pos_in_buf %d", pos_in_buf);
for (i = 0; (i < (pos_in_buf)) && (current_entry != NULL); i++) {
current_entry = nxt_dir_entry(current_entry, end_of_smb,
cifsFile->srch_inf.info_level);
}
if ((current_entry == NULL) && (i < pos_in_buf)) {
cERROR(1, "reached end of buf searching for pos in buf"
" %d index to find %lld rc %d",
pos_in_buf, index_to_find, rc);
}
rc = 0;
*ppCurrentEntry = current_entry;
} else {
cFYI(1, "index not in buffer - could not findnext into it");
return 0;
}
if (pos_in_buf >= cifsFile->srch_inf.entries_in_buffer) {
cFYI(1, "can not return entries pos_in_buf beyond last");
*num_to_ret = 0;
} else
*num_to_ret = cifsFile->srch_inf.entries_in_buffer - pos_in_buf;
return rc;
}
static int cifs_get_name_from_search_buf(struct qstr *pqst,
char *current_entry, __u16 level, unsigned int unicode,
struct cifs_sb_info *cifs_sb, unsigned int max_len, __u64 *pinum)
{
int rc = 0;
unsigned int len = 0;
char *filename;
struct nls_table *nlt = cifs_sb->local_nls;
*pinum = 0;
if (level == SMB_FIND_FILE_UNIX) {
FILE_UNIX_INFO *pFindData = (FILE_UNIX_INFO *)current_entry;
filename = &pFindData->FileName[0];
if (unicode) {
len = cifs_unicode_bytelen(filename);
} else {
len = strnlen(filename, PATH_MAX);
}
*pinum = le64_to_cpu(pFindData->basic.UniqueId);
} else if (level == SMB_FIND_FILE_DIRECTORY_INFO) {
FILE_DIRECTORY_INFO *pFindData =
(FILE_DIRECTORY_INFO *)current_entry;
filename = &pFindData->FileName[0];
len = le32_to_cpu(pFindData->FileNameLength);
} else if (level == SMB_FIND_FILE_FULL_DIRECTORY_INFO) {
FILE_FULL_DIRECTORY_INFO *pFindData =
(FILE_FULL_DIRECTORY_INFO *)current_entry;
filename = &pFindData->FileName[0];
len = le32_to_cpu(pFindData->FileNameLength);
} else if (level == SMB_FIND_FILE_ID_FULL_DIR_INFO) {
SEARCH_ID_FULL_DIR_INFO *pFindData =
(SEARCH_ID_FULL_DIR_INFO *)current_entry;
filename = &pFindData->FileName[0];
len = le32_to_cpu(pFindData->FileNameLength);
*pinum = le64_to_cpu(pFindData->UniqueId);
} else if (level == SMB_FIND_FILE_BOTH_DIRECTORY_INFO) {
FILE_BOTH_DIRECTORY_INFO *pFindData =
(FILE_BOTH_DIRECTORY_INFO *)current_entry;
filename = &pFindData->FileName[0];
len = le32_to_cpu(pFindData->FileNameLength);
} else if (level == SMB_FIND_FILE_INFO_STANDARD) {
FIND_FILE_STANDARD_INFO *pFindData =
(FIND_FILE_STANDARD_INFO *)current_entry;
filename = &pFindData->FileName[0];
len = (unsigned int)pFindData->FileNameLength;
} else {
cFYI(1, "Unknown findfirst level %d", level);
return -EINVAL;
}
if (len > max_len) {
cERROR(1, "bad search response length %d past smb end", len);
return -EINVAL;
}
if (unicode) {
pqst->len = cifs_from_ucs2((char *) pqst->name,
(__le16 *) filename,
UNICODE_NAME_MAX,
min(len, max_len), nlt,
cifs_sb->mnt_cifs_flags &
CIFS_MOUNT_MAP_SPECIAL_CHR);
pqst->len -= nls_nullsize(nlt);
} else {
pqst->name = filename;
pqst->len = len;
}
return rc;
}
static int cifs_filldir(char *pfindEntry, struct file *file, filldir_t filldir,
void *direntry, char *scratch_buf, unsigned int max_len)
{
int rc = 0;
struct qstr qstring;
struct cifsFileInfo *pCifsF;
u64 inum;
ino_t ino;
struct super_block *sb;
struct cifs_sb_info *cifs_sb;
struct dentry *tmp_dentry;
struct cifs_fattr fattr;
if ((direntry == NULL) || (file == NULL))
return -EINVAL;
pCifsF = file->private_data;
if ((scratch_buf == NULL) || (pfindEntry == NULL) || (pCifsF == NULL))
return -ENOENT;
rc = cifs_entry_is_dot(pfindEntry, pCifsF);
if (rc != 0)
return 0;
sb = file->f_path.dentry->d_sb;
cifs_sb = CIFS_SB(sb);
qstring.name = scratch_buf;
rc = cifs_get_name_from_search_buf(&qstring, pfindEntry,
pCifsF->srch_inf.info_level,
pCifsF->srch_inf.unicode, cifs_sb,
max_len, &inum );
if (rc)
return rc;
if (pCifsF->srch_inf.info_level == SMB_FIND_FILE_UNIX)
cifs_unix_basic_to_fattr(&fattr,
&((FILE_UNIX_INFO *) pfindEntry)->basic,
cifs_sb);
else if (pCifsF->srch_inf.info_level == SMB_FIND_FILE_INFO_STANDARD)
cifs_std_info_to_fattr(&fattr, (FIND_FILE_STANDARD_INFO *)
pfindEntry, cifs_sb);
else
cifs_dir_info_to_fattr(&fattr, (FILE_DIRECTORY_INFO *)
pfindEntry, cifs_sb);
if (inum && (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_SERVER_INUM)) {
fattr.cf_uniqueid = inum;
} else {
fattr.cf_uniqueid = iunique(sb, ROOT_I);
cifs_autodisable_serverino(cifs_sb);
}
if ((cifs_sb->mnt_cifs_flags & CIFS_MOUNT_MF_SYMLINKS) &&
CIFSCouldBeMFSymlink(&fattr))
fattr.cf_flags |= CIFS_FATTR_NEED_REVAL;
ino = cifs_uniqueid_to_ino_t(fattr.cf_uniqueid);
tmp_dentry = cifs_readdir_lookup(file->f_dentry, &qstring, &fattr);
rc = filldir(direntry, qstring.name, qstring.len, file->f_pos,
ino, fattr.cf_dtype);
dput(tmp_dentry);
return rc;
}
int cifs_readdir(struct file *file, void *direntry, filldir_t filldir)
{
int rc = 0;
int xid, i;
struct cifs_tcon *pTcon;
struct cifsFileInfo *cifsFile = NULL;
char *current_entry;
int num_to_fill = 0;
char *tmp_buf = NULL;
char *end_of_smb;
unsigned int max_len;
xid = GetXid();
if (file->private_data == NULL) {
rc = initiate_cifs_search(xid, file);
cFYI(1, "initiate cifs search rc %d", rc);
if (rc)
goto rddir2_exit;
}
switch ((int) file->f_pos) {
case 0:
if (filldir(direntry, ".", 1, file->f_pos,
file->f_path.dentry->d_inode->i_ino, DT_DIR) < 0) {
cERROR(1, "Filldir for current dir failed");
rc = -ENOMEM;
break;
}
file->f_pos++;
case 1:
if (filldir(direntry, "..", 2, file->f_pos,
file->f_path.dentry->d_parent->d_inode->i_ino, DT_DIR) < 0) {
cERROR(1, "Filldir for parent dir failed");
rc = -ENOMEM;
break;
}
file->f_pos++;
default:
if (file->private_data == NULL) {
rc = -EINVAL;
FreeXid(xid);
return rc;
}
cifsFile = file->private_data;
if (cifsFile->srch_inf.endOfSearch) {
if (cifsFile->srch_inf.emptyDir) {
cFYI(1, "End of search, empty dir");
rc = 0;
break;
}
}
pTcon = tlink_tcon(cifsFile->tlink);
rc = find_cifs_entry(xid, pTcon, file,
&current_entry, &num_to_fill);
if (rc) {
cFYI(1, "fce error %d", rc);
goto rddir2_exit;
} else if (current_entry != NULL) {
cFYI(1, "entry %lld found", file->f_pos);
} else {
cFYI(1, "could not find entry");
goto rddir2_exit;
}
cFYI(1, "loop through %d times filling dir for net buf %p",
num_to_fill, cifsFile->srch_inf.ntwrk_buf_start);
max_len = smbCalcSize((struct smb_hdr *)
cifsFile->srch_inf.ntwrk_buf_start);
end_of_smb = cifsFile->srch_inf.ntwrk_buf_start + max_len;
tmp_buf = kmalloc(UNICODE_NAME_MAX, GFP_KERNEL);
if (tmp_buf == NULL) {
rc = -ENOMEM;
break;
}
for (i = 0; (i < num_to_fill) && (rc == 0); i++) {
if (current_entry == NULL) {
cERROR(1, "past SMB end, num to fill %d i %d",
num_to_fill, i);
break;
}
rc = cifs_filldir(current_entry, file,
filldir, direntry, tmp_buf, max_len);
if (rc == -EOVERFLOW) {
rc = 0;
break;
}
file->f_pos++;
if (file->f_pos ==
cifsFile->srch_inf.index_of_last_entry) {
cFYI(1, "last entry in buf at pos %lld %s",
file->f_pos, tmp_buf);
cifs_save_resume_key(current_entry, cifsFile);
break;
} else
current_entry =
nxt_dir_entry(current_entry, end_of_smb,
cifsFile->srch_inf.info_level);
}
kfree(tmp_buf);
break;
}
rddir2_exit:
FreeXid(xid);
return rc;
}
