static struct dentry *cifs_get_parent(struct dentry *dentry)\r\n{\r\ncifs_dbg(FYI, "get parent for %p\n", dentry);\r\nreturn ERR_PTR(-EACCES);\r\n}
