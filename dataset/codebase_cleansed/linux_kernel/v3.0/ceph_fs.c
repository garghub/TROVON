int ceph_file_layout_is_valid(const struct ceph_file_layout *layout)
{
__u32 su = le32_to_cpu(layout->fl_stripe_unit);
__u32 sc = le32_to_cpu(layout->fl_stripe_count);
__u32 os = le32_to_cpu(layout->fl_object_size);
if (!su || (su & (CEPH_MIN_STRIPE_UNIT-1)))
return 0;
if (!os || (os & (CEPH_MIN_STRIPE_UNIT-1)))
return 0;
if (os < su || os % su)
return 0;
if (!sc)
return 0;
return 1;
}
int ceph_flags_to_mode(int flags)
{
int mode;
#ifdef O_DIRECTORY
if ((flags & O_DIRECTORY) == O_DIRECTORY)
return CEPH_FILE_MODE_PIN;
#endif
switch (flags & O_ACCMODE) {
case O_WRONLY:
mode = CEPH_FILE_MODE_WR;
break;
case O_RDONLY:
mode = CEPH_FILE_MODE_RD;
break;
case O_RDWR:
case O_ACCMODE:
mode = CEPH_FILE_MODE_RDWR;
break;
}
#ifdef O_LAZY
if (flags & O_LAZY)
mode |= CEPH_FILE_MODE_LAZY;
#endif
return mode;
}
int ceph_caps_for_mode(int mode)
{
int caps = CEPH_CAP_PIN;
if (mode & CEPH_FILE_MODE_RD)
caps |= CEPH_CAP_FILE_SHARED |
CEPH_CAP_FILE_RD | CEPH_CAP_FILE_CACHE;
if (mode & CEPH_FILE_MODE_WR)
caps |= CEPH_CAP_FILE_EXCL |
CEPH_CAP_FILE_WR | CEPH_CAP_FILE_BUFFER |
CEPH_CAP_AUTH_SHARED | CEPH_CAP_AUTH_EXCL |
CEPH_CAP_XATTR_SHARED | CEPH_CAP_XATTR_EXCL;
if (mode & CEPH_FILE_MODE_LAZY)
caps |= CEPH_CAP_FILE_LAZYIO;
return caps;
}
