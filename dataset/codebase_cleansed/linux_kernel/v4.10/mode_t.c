static size_t syscall_arg__scnprintf_mode_t(char *bf, size_t size, struct syscall_arg *arg)
{
int printed = 0, mode = arg->val;
#define P_MODE(n) \
if ((mode & S_##n) == S_##n) { \
printed += scnprintf(bf + printed, size - printed, "%s%s", printed ? "|" : "", #n); \
mode &= ~S_##n; \
}
P_MODE(IALLUGO);
P_MODE(IRWXUGO);
P_MODE(IRUGO);
P_MODE(IWUGO);
P_MODE(IXUGO);
P_MODE(IFMT);
P_MODE(IFSOCK);
P_MODE(IFLNK);
P_MODE(IFREG);
P_MODE(IFBLK);
P_MODE(IFDIR);
P_MODE(IFCHR);
P_MODE(IFIFO);
P_MODE(ISUID);
P_MODE(ISGID);
P_MODE(ISVTX);
P_MODE(IRWXU);
P_MODE(IRUSR);
P_MODE(IWUSR);
P_MODE(IXUSR);
P_MODE(IRWXG);
P_MODE(IRGRP);
P_MODE(IWGRP);
P_MODE(IXGRP);
P_MODE(IRWXO);
P_MODE(IROTH);
P_MODE(IWOTH);
P_MODE(IXOTH);
#undef P_MODE
if (mode)
printed += scnprintf(bf + printed, size - printed, "%s%#x", printed ? "|" : "", mode);
return printed;
}
