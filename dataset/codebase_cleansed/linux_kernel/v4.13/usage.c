static __noreturn void usage_builtin(const char *err)
{
fprintf(stderr, "\n Usage: %s\n", err);
exit(129);
}
void usage(const char *err)
{
usage_routine(err);
}
