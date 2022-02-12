int
get_natural_int(const char *string, const char *name)
{
gint32 number;
if (!ws_strtoi32(string, NULL, &number)) {
if (errno == EINVAL) {
cmdarg_err("The specified %s \"%s\" isn't a decimal number", name, string);
exit(1);
}
if (number < 0) {
cmdarg_err("The specified %s \"%s\" is a negative number", name, string);
exit(1);
}
cmdarg_err("The specified %s \"%s\" is too large (greater than %d)",
name, string, number);
exit(1);
}
if (number < 0) {
cmdarg_err("The specified %s \"%s\" is a negative number", name, string);
exit(1);
}
return (int)number;
}
int
get_positive_int(const char *string, const char *name)
{
int number;
number = get_natural_int(string, name);
if (number == 0) {
cmdarg_err("The specified %s is zero", name);
exit(1);
}
return number;
}
guint32
get_guint32(const char *string, const char *name)
{
guint32 number;
if (!ws_strtou32(string, NULL, &number)) {
if (errno == EINVAL) {
cmdarg_err("The specified %s \"%s\" isn't a decimal number", name, string);
exit(1);
}
cmdarg_err("The specified %s \"%s\" is too large (greater than %d)",
name, string, number);
exit(1);
}
return number;
}
guint32
get_nonzero_guint32(const char *string, const char *name)
{
guint32 number;
number = get_guint32(string, name);
if (number == 0) {
cmdarg_err("The specified %s is zero", name);
exit(1);
}
return number;
}
