static struct dentry *cifs_get_parent(struct dentry *dentry)
{
cifs_dbg(FYI, "get parent for %p\n", dentry);
return ERR_PTR(-EACCES);
}
