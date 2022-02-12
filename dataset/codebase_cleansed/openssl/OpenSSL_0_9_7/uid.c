int OPENSSL_issetugid(void)
{
return issetugid();
}
int OPENSSL_issetugid(void)
{
return 0;
}
int OPENSSL_issetugid(void)
{
if (getuid() != geteuid()) return 1;
if (getgid() != getegid()) return 1;
return 0;
}
