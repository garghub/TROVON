int string_get_size(u64 size, const enum string_size_units units,
char *buf, int len)
{
static const char *units_10[] = { "B", "kB", "MB", "GB", "TB", "PB",
"EB", "ZB", "YB", NULL};
static const char *units_2[] = {"B", "KiB", "MiB", "GiB", "TiB", "PiB",
"EiB", "ZiB", "YiB", NULL };
static const char **units_str[] = {
[STRING_UNITS_10] = units_10,
[STRING_UNITS_2] = units_2,
};
static const unsigned int divisor[] = {
[STRING_UNITS_10] = 1000,
[STRING_UNITS_2] = 1024,
};
int i, j;
u64 remainder = 0, sf_cap;
char tmp[8];
tmp[0] = '\0';
i = 0;
if (size >= divisor[units]) {
while (size >= divisor[units] && units_str[units][i]) {
remainder = do_div(size, divisor[units]);
i++;
}
sf_cap = size;
for (j = 0; sf_cap*10 < 1000; j++)
sf_cap *= 10;
if (j) {
remainder *= 1000;
do_div(remainder, divisor[units]);
snprintf(tmp, sizeof(tmp), ".%03lld",
(unsigned long long)remainder);
tmp[j+1] = '\0';
}
}
snprintf(buf, len, "%lld%s %s", (unsigned long long)size,
tmp, units_str[units][i]);
return 0;
}
