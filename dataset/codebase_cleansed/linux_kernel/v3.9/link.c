static int
symlink_hash(unsigned int link_len, const char *link_str, u8 *md5_hash)
{
int rc;
unsigned int size;
struct crypto_shash *md5;
struct sdesc *sdescmd5;
md5 = crypto_alloc_shash("md5", 0, 0);
if (IS_ERR(md5)) {
rc = PTR_ERR(md5);
cERROR(1, "%s: Crypto md5 allocation error %d", __func__, rc);
return rc;
}
size = sizeof(struct shash_desc) + crypto_shash_descsize(md5);
sdescmd5 = kmalloc(size, GFP_KERNEL);
if (!sdescmd5) {
rc = -ENOMEM;
cERROR(1, "%s: Memory allocation failure", __func__);
goto symlink_hash_err;
}
sdescmd5->shash.tfm = md5;
sdescmd5->shash.flags = 0x0;
rc = crypto_shash_init(&sdescmd5->shash);
if (rc) {
cERROR(1, "%s: Could not init md5 shash", __func__);
goto symlink_hash_err;
}
rc = crypto_shash_update(&sdescmd5->shash, link_str, link_len);
if (rc) {
cERROR(1, "%s: Could not update with link_str", __func__);
goto symlink_hash_err;
}
rc = crypto_shash_final(&sdescmd5->shash, md5_hash);
if (rc)
cERROR(1, "%s: Could not generate md5 hash", __func__);
symlink_hash_err:
crypto_free_shash(md5);
kfree(sdescmd5);
return rc;
}
static int
CIFSParseMFSymlink(const u8 *buf,
unsigned int buf_len,
unsigned int *_link_len,
char **_link_str)
{
int rc;
unsigned int link_len;
const char *md5_str1;
const char *link_str;
u8 md5_hash[16];
char md5_str2[34];
if (buf_len != CIFS_MF_SYMLINK_FILE_SIZE)
return -EINVAL;
md5_str1 = (const char *)&buf[CIFS_MF_SYMLINK_MD5_OFFSET];
link_str = (const char *)&buf[CIFS_MF_SYMLINK_LINK_OFFSET];
rc = sscanf(buf, CIFS_MF_SYMLINK_LEN_FORMAT, &link_len);
if (rc != 1)
return -EINVAL;
rc = symlink_hash(link_len, link_str, md5_hash);
if (rc) {
cFYI(1, "%s: MD5 hash failure: %d", __func__, rc);
return rc;
}
snprintf(md5_str2, sizeof(md5_str2),
CIFS_MF_SYMLINK_MD5_FORMAT,
CIFS_MF_SYMLINK_MD5_ARGS(md5_hash));
if (strncmp(md5_str1, md5_str2, 17) != 0)
return -EINVAL;
if (_link_str) {
*_link_str = kstrndup(link_str, link_len, GFP_KERNEL);
if (!*_link_str)
return -ENOMEM;
}
*_link_len = link_len;
return 0;
}
static int
CIFSFormatMFSymlink(u8 *buf, unsigned int buf_len, const char *link_str)
{
int rc;
unsigned int link_len;
unsigned int ofs;
u8 md5_hash[16];
if (buf_len != CIFS_MF_SYMLINK_FILE_SIZE)
return -EINVAL;
link_len = strlen(link_str);
if (link_len > CIFS_MF_SYMLINK_LINK_MAXLEN)
return -ENAMETOOLONG;
rc = symlink_hash(link_len, link_str, md5_hash);
if (rc) {
cFYI(1, "%s: MD5 hash failure: %d", __func__, rc);
return rc;
}
snprintf(buf, buf_len,
CIFS_MF_SYMLINK_LEN_FORMAT CIFS_MF_SYMLINK_MD5_FORMAT,
link_len,
CIFS_MF_SYMLINK_MD5_ARGS(md5_hash));
ofs = CIFS_MF_SYMLINK_LINK_OFFSET;
memcpy(buf + ofs, link_str, link_len);
ofs += link_len;
if (ofs < CIFS_MF_SYMLINK_FILE_SIZE) {
buf[ofs] = '\n';
ofs++;
}
while (ofs < CIFS_MF_SYMLINK_FILE_SIZE) {
buf[ofs] = ' ';
ofs++;
}
return 0;
}
static int
CIFSCreateMFSymLink(const unsigned int xid, struct cifs_tcon *tcon,
const char *fromName, const char *toName,
struct cifs_sb_info *cifs_sb)
{
int rc;
int oplock = 0;
int remap;
int create_options = CREATE_NOT_DIR;
__u16 netfid = 0;
u8 *buf;
unsigned int bytes_written = 0;
struct cifs_io_parms io_parms;
struct nls_table *nls_codepage;
nls_codepage = cifs_sb->local_nls;
remap = cifs_sb->mnt_cifs_flags & CIFS_MOUNT_MAP_SPECIAL_CHR;
buf = kmalloc(CIFS_MF_SYMLINK_FILE_SIZE, GFP_KERNEL);
if (!buf)
return -ENOMEM;
rc = CIFSFormatMFSymlink(buf, CIFS_MF_SYMLINK_FILE_SIZE, toName);
if (rc != 0) {
kfree(buf);
return rc;
}
if (backup_cred(cifs_sb))
create_options |= CREATE_OPEN_BACKUP_INTENT;
rc = CIFSSMBOpen(xid, tcon, fromName, FILE_CREATE, GENERIC_WRITE,
create_options, &netfid, &oplock, NULL,
nls_codepage, remap);
if (rc != 0) {
kfree(buf);
return rc;
}
io_parms.netfid = netfid;
io_parms.pid = current->tgid;
io_parms.tcon = tcon;
io_parms.offset = 0;
io_parms.length = CIFS_MF_SYMLINK_FILE_SIZE;
rc = CIFSSMBWrite(xid, &io_parms, &bytes_written, buf, NULL, 0);
CIFSSMBClose(xid, tcon, netfid);
kfree(buf);
if (rc != 0)
return rc;
if (bytes_written != CIFS_MF_SYMLINK_FILE_SIZE)
return -EIO;
return 0;
}
static int
CIFSQueryMFSymLink(const unsigned int xid, struct cifs_tcon *tcon,
const unsigned char *searchName, char **symlinkinfo,
const struct nls_table *nls_codepage, int remap)
{
int rc;
int oplock = 0;
__u16 netfid = 0;
u8 *buf;
char *pbuf;
unsigned int bytes_read = 0;
int buf_type = CIFS_NO_BUFFER;
unsigned int link_len = 0;
struct cifs_io_parms io_parms;
FILE_ALL_INFO file_info;
rc = CIFSSMBOpen(xid, tcon, searchName, FILE_OPEN, GENERIC_READ,
CREATE_NOT_DIR, &netfid, &oplock, &file_info,
nls_codepage, remap);
if (rc != 0)
return rc;
if (file_info.EndOfFile != cpu_to_le64(CIFS_MF_SYMLINK_FILE_SIZE)) {
CIFSSMBClose(xid, tcon, netfid);
return -EINVAL;
}
buf = kmalloc(CIFS_MF_SYMLINK_FILE_SIZE, GFP_KERNEL);
if (!buf)
return -ENOMEM;
pbuf = buf;
io_parms.netfid = netfid;
io_parms.pid = current->tgid;
io_parms.tcon = tcon;
io_parms.offset = 0;
io_parms.length = CIFS_MF_SYMLINK_FILE_SIZE;
rc = CIFSSMBRead(xid, &io_parms, &bytes_read, &pbuf, &buf_type);
CIFSSMBClose(xid, tcon, netfid);
if (rc != 0) {
kfree(buf);
return rc;
}
rc = CIFSParseMFSymlink(buf, bytes_read, &link_len, symlinkinfo);
kfree(buf);
if (rc != 0)
return rc;
return 0;
}
bool
CIFSCouldBeMFSymlink(const struct cifs_fattr *fattr)
{
if (!(fattr->cf_mode & S_IFREG))
return false;
if (fattr->cf_eof != CIFS_MF_SYMLINK_FILE_SIZE)
return false;
return true;
}
int
CIFSCheckMFSymlink(struct cifs_fattr *fattr,
const unsigned char *path,
struct cifs_sb_info *cifs_sb, unsigned int xid)
{
int rc;
int oplock = 0;
__u16 netfid = 0;
struct tcon_link *tlink;
struct cifs_tcon *pTcon;
struct cifs_io_parms io_parms;
u8 *buf;
char *pbuf;
unsigned int bytes_read = 0;
int buf_type = CIFS_NO_BUFFER;
unsigned int link_len = 0;
FILE_ALL_INFO file_info;
if (!CIFSCouldBeMFSymlink(fattr))
return 0;
tlink = cifs_sb_tlink(cifs_sb);
if (IS_ERR(tlink))
return PTR_ERR(tlink);
pTcon = tlink_tcon(tlink);
rc = CIFSSMBOpen(xid, pTcon, path, FILE_OPEN, GENERIC_READ,
CREATE_NOT_DIR, &netfid, &oplock, &file_info,
cifs_sb->local_nls,
cifs_sb->mnt_cifs_flags &
CIFS_MOUNT_MAP_SPECIAL_CHR);
if (rc != 0)
goto out;
if (file_info.EndOfFile != cpu_to_le64(CIFS_MF_SYMLINK_FILE_SIZE)) {
CIFSSMBClose(xid, pTcon, netfid);
goto out;
}
buf = kmalloc(CIFS_MF_SYMLINK_FILE_SIZE, GFP_KERNEL);
if (!buf) {
rc = -ENOMEM;
goto out;
}
pbuf = buf;
io_parms.netfid = netfid;
io_parms.pid = current->tgid;
io_parms.tcon = pTcon;
io_parms.offset = 0;
io_parms.length = CIFS_MF_SYMLINK_FILE_SIZE;
rc = CIFSSMBRead(xid, &io_parms, &bytes_read, &pbuf, &buf_type);
CIFSSMBClose(xid, pTcon, netfid);
if (rc != 0) {
kfree(buf);
goto out;
}
rc = CIFSParseMFSymlink(buf, bytes_read, &link_len, NULL);
kfree(buf);
if (rc == -EINVAL) {
rc = 0;
goto out;
}
if (rc != 0)
goto out;
fattr->cf_eof = link_len;
fattr->cf_mode &= ~S_IFMT;
fattr->cf_mode |= S_IFLNK | S_IRWXU | S_IRWXG | S_IRWXO;
fattr->cf_dtype = DT_LNK;
out:
cifs_put_tlink(tlink);
return rc;
}
int
cifs_hardlink(struct dentry *old_file, struct inode *inode,
struct dentry *direntry)
{
int rc = -EACCES;
unsigned int xid;
char *from_name = NULL;
char *to_name = NULL;
struct cifs_sb_info *cifs_sb = CIFS_SB(inode->i_sb);
struct tcon_link *tlink;
struct cifs_tcon *tcon;
struct TCP_Server_Info *server;
struct cifsInodeInfo *cifsInode;
tlink = cifs_sb_tlink(cifs_sb);
if (IS_ERR(tlink))
return PTR_ERR(tlink);
tcon = tlink_tcon(tlink);
xid = get_xid();
from_name = build_path_from_dentry(old_file);
to_name = build_path_from_dentry(direntry);
if ((from_name == NULL) || (to_name == NULL)) {
rc = -ENOMEM;
goto cifs_hl_exit;
}
if (tcon->unix_ext)
rc = CIFSUnixCreateHardLink(xid, tcon, from_name, to_name,
cifs_sb->local_nls,
cifs_sb->mnt_cifs_flags &
CIFS_MOUNT_MAP_SPECIAL_CHR);
else {
server = tcon->ses->server;
if (!server->ops->create_hardlink)
return -ENOSYS;
rc = server->ops->create_hardlink(xid, tcon, from_name, to_name,
cifs_sb);
if ((rc == -EIO) || (rc == -EINVAL))
rc = -EOPNOTSUPP;
}
d_drop(direntry);
if (old_file->d_inode) {
cifsInode = CIFS_I(old_file->d_inode);
if (rc == 0) {
spin_lock(&old_file->d_inode->i_lock);
inc_nlink(old_file->d_inode);
spin_unlock(&old_file->d_inode->i_lock);
}
cifsInode->time = 0;
}
cifs_hl_exit:
kfree(from_name);
kfree(to_name);
free_xid(xid);
cifs_put_tlink(tlink);
return rc;
}
void *
cifs_follow_link(struct dentry *direntry, struct nameidata *nd)
{
struct inode *inode = direntry->d_inode;
int rc = -ENOMEM;
unsigned int xid;
char *full_path = NULL;
char *target_path = NULL;
struct cifs_sb_info *cifs_sb = CIFS_SB(inode->i_sb);
struct tcon_link *tlink = NULL;
struct cifs_tcon *tcon;
xid = get_xid();
tlink = cifs_sb_tlink(cifs_sb);
if (IS_ERR(tlink)) {
rc = PTR_ERR(tlink);
tlink = NULL;
goto out;
}
tcon = tlink_tcon(tlink);
if (!(cifs_sb->mnt_cifs_flags & CIFS_MOUNT_MF_SYMLINKS) &&
!cap_unix(tcon->ses)) {
rc = -EACCES;
goto out;
}
full_path = build_path_from_dentry(direntry);
if (!full_path)
goto out;
cFYI(1, "Full path: %s inode = 0x%p", full_path, inode);
rc = -EACCES;
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_MF_SYMLINKS)
rc = CIFSQueryMFSymLink(xid, tcon, full_path, &target_path,
cifs_sb->local_nls,
cifs_sb->mnt_cifs_flags &
CIFS_MOUNT_MAP_SPECIAL_CHR);
if ((rc != 0) && cap_unix(tcon->ses))
rc = CIFSSMBUnixQuerySymLink(xid, tcon, full_path, &target_path,
cifs_sb->local_nls);
kfree(full_path);
out:
if (rc != 0) {
kfree(target_path);
target_path = ERR_PTR(rc);
}
free_xid(xid);
if (tlink)
cifs_put_tlink(tlink);
nd_set_link(nd, target_path);
return NULL;
}
int
cifs_symlink(struct inode *inode, struct dentry *direntry, const char *symname)
{
int rc = -EOPNOTSUPP;
unsigned int xid;
struct cifs_sb_info *cifs_sb = CIFS_SB(inode->i_sb);
struct tcon_link *tlink;
struct cifs_tcon *pTcon;
char *full_path = NULL;
struct inode *newinode = NULL;
xid = get_xid();
tlink = cifs_sb_tlink(cifs_sb);
if (IS_ERR(tlink)) {
rc = PTR_ERR(tlink);
goto symlink_exit;
}
pTcon = tlink_tcon(tlink);
full_path = build_path_from_dentry(direntry);
if (full_path == NULL) {
rc = -ENOMEM;
goto symlink_exit;
}
cFYI(1, "Full path: %s", full_path);
cFYI(1, "symname is %s", symname);
if (cifs_sb->mnt_cifs_flags & CIFS_MOUNT_MF_SYMLINKS)
rc = CIFSCreateMFSymLink(xid, pTcon, full_path, symname,
cifs_sb);
else if (pTcon->unix_ext)
rc = CIFSUnixCreateSymLink(xid, pTcon, full_path, symname,
cifs_sb->local_nls);
if (rc == 0) {
if (pTcon->unix_ext)
rc = cifs_get_inode_info_unix(&newinode, full_path,
inode->i_sb, xid);
else
rc = cifs_get_inode_info(&newinode, full_path, NULL,
inode->i_sb, xid, NULL);
if (rc != 0) {
cFYI(1, "Create symlink ok, getinodeinfo fail rc = %d",
rc);
} else {
d_instantiate(direntry, newinode);
}
}
symlink_exit:
kfree(full_path);
cifs_put_tlink(tlink);
free_xid(xid);
return rc;
}
void cifs_put_link(struct dentry *direntry, struct nameidata *nd, void *cookie)
{
char *p = nd_get_link(nd);
if (!IS_ERR(p))
kfree(p);
}
