static struct dentry *cifs_get_parent(struct dentry *dentry)
{
cFYI(1, "get parent for %p", dentry);
return ERR_PTR(-EACCES);
}
