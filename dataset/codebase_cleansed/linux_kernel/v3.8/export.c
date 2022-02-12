static struct dentry *cifs_get_parent(struct dentry *dentry)\r\n{\r\ncFYI(1, "get parent for %p", dentry);\r\nreturn ERR_PTR(-EACCES);\r\n}
