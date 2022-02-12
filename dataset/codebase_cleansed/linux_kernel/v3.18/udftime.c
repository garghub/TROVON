struct timespec *
udf_disk_stamp_to_time(struct timespec *dest, struct timestamp src)
{
int yday;
u16 typeAndTimezone = le16_to_cpu(src.typeAndTimezone);
u16 year = le16_to_cpu(src.year);
uint8_t type = typeAndTimezone >> 12;
int16_t offset;
if (type == 1) {
offset = typeAndTimezone << 4;
offset = (offset >> 4);
if (offset == -2047)
offset = 0;
} else
offset = 0;
if ((year < EPOCH_YEAR) ||
(year >= EPOCH_YEAR + MAX_YEAR_SECONDS)) {
return NULL;
}
dest->tv_sec = year_seconds[year - EPOCH_YEAR];
dest->tv_sec -= offset * 60;
yday = ((__mon_yday[__isleap(year)][src.month - 1]) + src.day - 1);
dest->tv_sec += (((yday * 24) + src.hour) * 60 + src.minute) * 60 + src.second;
dest->tv_nsec = 1000 * (src.centiseconds * 10000 +
src.hundredsOfMicroseconds * 100 + src.microseconds);
return dest;
}
struct timestamp *
udf_time_to_disk_stamp(struct timestamp *dest, struct timespec ts)
{
long int days, rem, y;
const unsigned short int *ip;
int16_t offset;
offset = -sys_tz.tz_minuteswest;
if (!dest)
return NULL;
dest->typeAndTimezone = cpu_to_le16(0x1000 | (offset & 0x0FFF));
ts.tv_sec += offset * 60;
days = ts.tv_sec / SECS_PER_DAY;
rem = ts.tv_sec % SECS_PER_DAY;
dest->hour = rem / SECS_PER_HOUR;
rem %= SECS_PER_HOUR;
dest->minute = rem / 60;
dest->second = rem % 60;
y = 1970;
#define DIV(a, b) ((a) / (b) - ((a) % (b) < 0))
#define LEAPS_THRU_END_OF(y) (DIV (y, 4) - DIV (y, 100) + DIV (y, 400))
while (days < 0 || days >= (__isleap(y) ? 366 : 365)) {
long int yg = y + days / 365 - (days % 365 < 0);
days -= ((yg - y) * 365
+ LEAPS_THRU_END_OF(yg - 1)
- LEAPS_THRU_END_OF(y - 1));
y = yg;
}
dest->year = cpu_to_le16(y);
ip = __mon_yday[__isleap(y)];
for (y = 11; days < (long int)ip[y]; --y)
continue;
days -= ip[y];
dest->month = y + 1;
dest->day = days + 1;
dest->centiseconds = ts.tv_nsec / 10000000;
dest->hundredsOfMicroseconds = (ts.tv_nsec / 1000 -
dest->centiseconds * 10000) / 100;
dest->microseconds = (ts.tv_nsec / 1000 - dest->centiseconds * 10000 -
dest->hundredsOfMicroseconds * 100);
return dest;
}
