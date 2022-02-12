ssize_t v9fs_fid_xattr_get(struct p9_fid *fid, const char *name,
void *buffer, size_t buffer_size)
{
ssize_t retval;
int msize, read_count;
u64 offset = 0, attr_size;
struct p9_fid *attr_fid;
attr_fid = p9_client_xattrwalk(fid, name, &attr_size);
if (IS_ERR(attr_fid)) {
retval = PTR_ERR(attr_fid);
p9_debug(P9_DEBUG_VFS, "p9_client_attrwalk failed %zd\n",
retval);
attr_fid = NULL;
goto error;
}
if (!buffer_size) {
retval = attr_size;
goto error;
}
if (attr_size > buffer_size) {
retval = -ERANGE;
goto error;
}
msize = attr_fid->clnt->msize;
while (attr_size) {
if (attr_size > (msize - P9_IOHDRSZ))
read_count = msize - P9_IOHDRSZ;
else
read_count = attr_size;
read_count = p9_client_read(attr_fid, ((char *)buffer)+offset,
NULL, offset, read_count);
if (read_count < 0) {
retval = read_count;
goto error;
}
offset += read_count;
attr_size -= read_count;
}
retval = offset;
error:
if (attr_fid)
p9_client_clunk(attr_fid);
return retval;
}
ssize_t v9fs_xattr_get(struct dentry *dentry, const char *name,
void *buffer, size_t buffer_size)
{
struct p9_fid *fid;
p9_debug(P9_DEBUG_VFS, "name = %s value_len = %zu\n",
name, buffer_size);
fid = v9fs_fid_lookup(dentry);
if (IS_ERR(fid))
return PTR_ERR(fid);
return v9fs_fid_xattr_get(fid, name, buffer, buffer_size);
}
int v9fs_xattr_set(struct dentry *dentry, const char *name,
const void *value, size_t value_len, int flags)
{
struct p9_fid *fid = v9fs_fid_lookup(dentry);
if (IS_ERR(fid))
return PTR_ERR(fid);
return v9fs_fid_xattr_set(fid, name, value, value_len, flags);
}
int v9fs_fid_xattr_set(struct p9_fid *fid, const char *name,
const void *value, size_t value_len, int flags)
{
u64 offset = 0;
int retval, msize, write_count;
p9_debug(P9_DEBUG_VFS, "name = %s value_len = %zu flags = %d\n",
name, value_len, flags);
fid = p9_client_walk(fid, 0, NULL, 1);
if (IS_ERR(fid))
return PTR_ERR(fid);
retval = p9_client_xattrcreate(fid, name, value_len, flags);
if (retval < 0) {
p9_debug(P9_DEBUG_VFS, "p9_client_xattrcreate failed %d\n",
retval);
goto err;
}
msize = fid->clnt->msize;
while (value_len) {
if (value_len > (msize - P9_IOHDRSZ))
write_count = msize - P9_IOHDRSZ;
else
write_count = value_len;
write_count = p9_client_write(fid, ((char *)value)+offset,
NULL, offset, write_count);
if (write_count < 0) {
retval = write_count;
goto err;
}
offset += write_count;
value_len -= write_count;
}
retval = offset;
err:
p9_client_clunk(fid);
return retval;
}
ssize_t v9fs_listxattr(struct dentry *dentry, char *buffer, size_t buffer_size)
{
return v9fs_xattr_get(dentry, NULL, buffer, buffer_size);
}
