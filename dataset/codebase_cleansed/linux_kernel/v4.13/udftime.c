struct timespec *
udf_disk_stamp_to_time(struct timespec *dest, struct timestamp src)
{
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
dest->tv_sec = mktime64(year, src.month, src.day, src.hour, src.minute,
src.second);
dest->tv_sec -= offset * 60;
dest->tv_nsec = 1000 * (src.centiseconds * 10000 +
src.hundredsOfMicroseconds * 100 + src.microseconds);
return dest;
}
struct timestamp *
udf_time_to_disk_stamp(struct timestamp *dest, struct timespec ts)
{
long seconds;
int16_t offset;
struct tm tm;
offset = -sys_tz.tz_minuteswest;
if (!dest)
return NULL;
dest->typeAndTimezone = cpu_to_le16(0x1000 | (offset & 0x0FFF));
seconds = ts.tv_sec + offset * 60;
time64_to_tm(seconds, 0, &tm);
dest->year = cpu_to_le16(tm.tm_year + 1900);
dest->month = tm.tm_mon + 1;
dest->day = tm.tm_mday;
dest->hour = tm.tm_hour;
dest->minute = tm.tm_min;
dest->second = tm.tm_sec;
dest->centiseconds = ts.tv_nsec / 10000000;
dest->hundredsOfMicroseconds = (ts.tv_nsec / 1000 -
dest->centiseconds * 10000) / 100;
dest->microseconds = (ts.tv_nsec / 1000 - dest->centiseconds * 10000 -
dest->hundredsOfMicroseconds * 100);
return dest;
}
