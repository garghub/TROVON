static void *ext2_follow_link(struct dentry *dentry, struct nameidata *nd)\r\n{\r\nstruct ext2_inode_info *ei = EXT2_I(dentry->d_inode);\r\nnd_set_link(nd, (char *)ei->i_data);\r\nreturn NULL;\r\n}
