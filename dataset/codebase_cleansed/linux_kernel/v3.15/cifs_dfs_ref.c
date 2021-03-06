static void cifs_dfs_expire_automounts(struct work_struct *work)\r\n{\r\nstruct list_head *list = &cifs_dfs_automount_list;\r\nmark_mounts_for_expiry(list);\r\nif (!list_empty(list))\r\nschedule_delayed_work(&cifs_dfs_automount_task,\r\ncifs_dfs_mountpoint_expiry_timeout);\r\n}\r\nvoid cifs_dfs_release_automount_timer(void)\r\n{\r\nBUG_ON(!list_empty(&cifs_dfs_automount_list));\r\ncancel_delayed_work_sync(&cifs_dfs_automount_task);\r\n}\r\nstatic char *\r\ncifs_build_devname(char *nodename, const char *prepath)\r\n{\r\nsize_t pplen;\r\nsize_t unclen;\r\nchar *dev;\r\nchar *pos;\r\nnodename += strspn(nodename, "\\");\r\nif (!*nodename)\r\nreturn ERR_PTR(-EINVAL);\r\nunclen = strlen(nodename);\r\npos = nodename + unclen - 1;\r\nwhile (*pos == '\\') {\r\n--pos;\r\n--unclen;\r\n}\r\npplen = prepath ? strlen(prepath) : 0;\r\ndev = kmalloc(2 + unclen + 1 + pplen + 1, GFP_KERNEL);\r\nif (!dev)\r\nreturn ERR_PTR(-ENOMEM);\r\npos = dev;\r\n*pos = '/';\r\n++pos;\r\n*pos = '/';\r\n++pos;\r\nmemcpy(pos, nodename, unclen);\r\npos += unclen;\r\nif (pplen) {\r\n*pos = '/';\r\n++pos;\r\nmemcpy(pos, prepath, pplen);\r\npos += pplen;\r\n}\r\n*pos = '\0';\r\nconvert_delimiter(dev, '/');\r\nreturn dev;\r\n}\r\nchar *cifs_compose_mount_options(const char *sb_mountdata,\r\nconst char *fullpath,\r\nconst struct dfs_info3_param *ref,\r\nchar **devname)\r\n{\r\nint rc;\r\nchar *mountdata = NULL;\r\nconst char *prepath = NULL;\r\nint md_len;\r\nchar *tkn_e;\r\nchar *srvIP = NULL;\r\nchar sep = ',';\r\nint off, noff;\r\nif (sb_mountdata == NULL)\r\nreturn ERR_PTR(-EINVAL);\r\nif (strlen(fullpath) - ref->path_consumed)\r\nprepath = fullpath + ref->path_consumed;\r\n*devname = cifs_build_devname(ref->node_name, prepath);\r\nif (IS_ERR(*devname)) {\r\nrc = PTR_ERR(*devname);\r\n*devname = NULL;\r\ngoto compose_mount_options_err;\r\n}\r\nrc = dns_resolve_server_name_to_ip(*devname, &srvIP);\r\nif (rc < 0) {\r\ncifs_dbg(FYI, "%s: Failed to resolve server part of %s to IP: %d\n",\r\n__func__, *devname, rc);\r\ngoto compose_mount_options_err;\r\n}\r\nmd_len = strlen(sb_mountdata) + INET6_ADDRSTRLEN;\r\nmountdata = kzalloc(md_len + 1, GFP_KERNEL);\r\nif (mountdata == NULL) {\r\nrc = -ENOMEM;\r\ngoto compose_mount_options_err;\r\n}\r\noff = 0;\r\nif (strncmp(sb_mountdata, "sep=", 4) == 0) {\r\nsep = sb_mountdata[4];\r\nstrncpy(mountdata, sb_mountdata, 5);\r\noff += 5;\r\n}\r\ndo {\r\ntkn_e = strchr(sb_mountdata + off, sep);\r\nif (tkn_e == NULL)\r\nnoff = strlen(sb_mountdata + off);\r\nelse\r\nnoff = tkn_e - (sb_mountdata + off) + 1;\r\nif (strnicmp(sb_mountdata + off, "unc=", 4) == 0) {\r\noff += noff;\r\ncontinue;\r\n}\r\nif (strnicmp(sb_mountdata + off, "ip=", 3) == 0) {\r\noff += noff;\r\ncontinue;\r\n}\r\nif (strnicmp(sb_mountdata + off, "prefixpath=", 11) == 0) {\r\noff += noff;\r\ncontinue;\r\n}\r\nstrncat(mountdata, sb_mountdata + off, noff);\r\noff += noff;\r\n} while (tkn_e);\r\nstrcat(mountdata, sb_mountdata + off);\r\nmountdata[md_len] = '\0';\r\nif (mountdata[strlen(mountdata) - 1] != sep)\r\nstrncat(mountdata, &sep, 1);\r\nstrcat(mountdata, "ip=");\r\nstrcat(mountdata, srvIP);\r\ncompose_mount_options_out:\r\nkfree(srvIP);\r\nreturn mountdata;\r\ncompose_mount_options_err:\r\nkfree(mountdata);\r\nmountdata = ERR_PTR(rc);\r\nkfree(*devname);\r\n*devname = NULL;\r\ngoto compose_mount_options_out;\r\n}\r\nstatic struct vfsmount *cifs_dfs_do_refmount(struct cifs_sb_info *cifs_sb,\r\nconst char *fullpath, const struct dfs_info3_param *ref)\r\n{\r\nstruct vfsmount *mnt;\r\nchar *mountdata;\r\nchar *devname = NULL;\r\nmountdata = cifs_compose_mount_options(cifs_sb->mountdata,\r\nfullpath + 1, ref, &devname);\r\nif (IS_ERR(mountdata))\r\nreturn (struct vfsmount *)mountdata;\r\nmnt = vfs_kern_mount(&cifs_fs_type, 0, devname, mountdata);\r\nkfree(mountdata);\r\nkfree(devname);\r\nreturn mnt;\r\n}\r\nstatic void dump_referral(const struct dfs_info3_param *ref)\r\n{\r\ncifs_dbg(FYI, "DFS: ref path: %s\n", ref->path_name);\r\ncifs_dbg(FYI, "DFS: node path: %s\n", ref->node_name);\r\ncifs_dbg(FYI, "DFS: fl: %hd, srv_type: %hd\n",\r\nref->flags, ref->server_type);\r\ncifs_dbg(FYI, "DFS: ref_flags: %hd, path_consumed: %hd\n",\r\nref->ref_flag, ref->path_consumed);\r\n}\r\nstatic struct vfsmount *cifs_dfs_do_automount(struct dentry *mntpt)\r\n{\r\nstruct dfs_info3_param *referrals = NULL;\r\nunsigned int num_referrals = 0;\r\nstruct cifs_sb_info *cifs_sb;\r\nstruct cifs_ses *ses;\r\nchar *full_path;\r\nunsigned int xid;\r\nint i;\r\nint rc;\r\nstruct vfsmount *mnt;\r\nstruct tcon_link *tlink;\r\ncifs_dbg(FYI, "in %s\n", __func__);\r\nBUG_ON(IS_ROOT(mntpt));\r\nmnt = ERR_PTR(-ENOMEM);\r\nfull_path = build_path_from_dentry(mntpt);\r\nif (full_path == NULL)\r\ngoto cdda_exit;\r\ncifs_sb = CIFS_SB(mntpt->d_inode->i_sb);\r\ntlink = cifs_sb_tlink(cifs_sb);\r\nif (IS_ERR(tlink)) {\r\nmnt = ERR_CAST(tlink);\r\ngoto free_full_path;\r\n}\r\nses = tlink_tcon(tlink)->ses;\r\nxid = get_xid();\r\nrc = get_dfs_path(xid, ses, full_path + 1, cifs_sb->local_nls,\r\n&num_referrals, &referrals,\r\ncifs_sb->mnt_cifs_flags & CIFS_MOUNT_MAP_SPECIAL_CHR);\r\nfree_xid(xid);\r\ncifs_put_tlink(tlink);\r\nmnt = ERR_PTR(-ENOENT);\r\nfor (i = 0; i < num_referrals; i++) {\r\nint len;\r\ndump_referral(referrals + i);\r\nlen = strlen(referrals[i].node_name);\r\nif (len < 2) {\r\ncifs_dbg(VFS, "%s: Net Address path too short: %s\n",\r\n__func__, referrals[i].node_name);\r\nmnt = ERR_PTR(-EINVAL);\r\nbreak;\r\n}\r\nmnt = cifs_dfs_do_refmount(cifs_sb,\r\nfull_path, referrals + i);\r\ncifs_dbg(FYI, "%s: cifs_dfs_do_refmount:%s , mnt:%p\n",\r\n__func__, referrals[i].node_name, mnt);\r\nif (!IS_ERR(mnt))\r\ngoto success;\r\n}\r\nif (rc != 0)\r\nmnt = ERR_PTR(rc);\r\nsuccess:\r\nfree_dfs_info_array(referrals, num_referrals);\r\nfree_full_path:\r\nkfree(full_path);\r\ncdda_exit:\r\ncifs_dbg(FYI, "leaving %s\n" , __func__);\r\nreturn mnt;\r\n}\r\nstruct vfsmount *cifs_dfs_d_automount(struct path *path)\r\n{\r\nstruct vfsmount *newmnt;\r\ncifs_dbg(FYI, "in %s\n", __func__);\r\nnewmnt = cifs_dfs_do_automount(path->dentry);\r\nif (IS_ERR(newmnt)) {\r\ncifs_dbg(FYI, "leaving %s [automount failed]\n" , __func__);\r\nreturn newmnt;\r\n}\r\nmntget(newmnt);\r\nmnt_set_expiry(newmnt, &cifs_dfs_automount_list);\r\nschedule_delayed_work(&cifs_dfs_automount_task,\r\ncifs_dfs_mountpoint_expiry_timeout);\r\ncifs_dbg(FYI, "leaving %s [ok]\n" , __func__);\r\nreturn newmnt;\r\n}
