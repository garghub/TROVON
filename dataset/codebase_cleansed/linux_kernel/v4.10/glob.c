bool __pure glob_match(char const *pat, char const *str)
{
char const *back_pat = NULL, *back_str = back_str;
for (;;) {
unsigned char c = *str++;
unsigned char d = *pat++;
switch (d) {
case '?':
if (c == '\0')
return false;
break;
case '*':
if (*pat == '\0')
return true;
back_pat = pat;
back_str = --str;
break;
case '[': {
bool match = false, inverted = (*pat == '!');
char const *class = pat + inverted;
unsigned char a = *class++;
do {
unsigned char b = a;
if (a == '\0')
goto literal;
if (class[0] == '-' && class[1] != ']') {
b = class[1];
if (b == '\0')
goto literal;
class += 2;
}
match |= (a <= c && c <= b);
} while ((a = *class++) != ']');
if (match == inverted)
goto backtrack;
pat = class;
}
break;
case '\\':
d = *pat++;
default:
literal:
if (c == d) {
if (d == '\0')
return true;
break;
}
backtrack:
if (c == '\0' || !back_pat)
return false;
pat = back_pat;
str = ++back_str;
break;
}
}
}
static bool __pure __init test(char const *pat, char const *str, bool expected)
{
bool match = glob_match(pat, str);
bool success = match == expected;
static char const msg_error[] __initconst =
KERN_ERR "glob: \"%s\" vs. \"%s\": %s *** ERROR ***\n";
static char const msg_ok[] __initconst =
KERN_DEBUG "glob: \"%s\" vs. \"%s\": %s OK\n";
static char const mismatch[] __initconst = "mismatch";
char const *message;
if (!success)
message = msg_error;
else if (verbose)
message = msg_ok;
else
return success;
printk(message, pat, str, mismatch + 3*match);
return success;
}
static int __init glob_init(void)
{
unsigned successes = 0;
unsigned n = 0;
char const *p = glob_tests;
static char const message[] __initconst =
KERN_INFO "glob: %u self-tests passed, %u failed\n";
while (*p) {
bool expected = *p++ & 1;
char const *pat = p;
p += strlen(p) + 1;
successes += test(pat, p, expected);
p += strlen(p) + 1;
n++;
}
n -= successes;
printk(message, successes, n);
return n ? -ECANCELED : 0;
}
static void __exit glob_fini(void) { }
