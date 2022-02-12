int
get_natural_int(const char *string, const char *name)
{
long number;
char *p;
number = strtol(string, &p, 10);
if (p == string || *p != '\0') {
cmdarg_err("The specified %s \"%s\" isn't a decimal number", name, string);
exit(1);
}
if (number < 0) {
cmdarg_err("The specified %s \"%s\" is a negative number", name, string);
exit(1);
}
if (number > INT_MAX) {
cmdarg_err("The specified %s \"%s\" is too large (greater than %d)",
name, string, INT_MAX);
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
