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
