static void
modify_time_init(frame_data *fd)
{
modify_time_perform(fd, SHIFT_NEG, NULL, SHIFT_KEEPOFFSET);
}
static void
modify_time_perform(frame_data *fd, int neg, nstime_t *offset, int settozero)
{
static frame_data *first_packet = NULL;
static nstime_t nulltime;
if (offset == NULL) {
first_packet = fd;
nulltime.secs = nulltime.nsecs = 0;
return;
}
if (first_packet == NULL) {
fprintf(stderr, "Modify_time_perform: not initialized?\n");
return;
}
if (settozero == SHIFT_SETTOZERO) {
nstime_subtract(&(fd->abs_ts), &(fd->shift_offset));
nstime_copy(&(fd->shift_offset), &nulltime);
}
if (neg == SHIFT_POS) {
nstime_add(&(fd->abs_ts), offset);
nstime_add(&(fd->shift_offset), offset);
} else if (neg == SHIFT_NEG) {
nstime_subtract(&(fd->abs_ts), offset);
nstime_subtract(&(fd->shift_offset), offset);
} else {
fprintf(stderr, "Modify_time_perform: neg = %d?\n", neg);
}
if (first_packet != NULL) {
nstime_copy(&(fd->rel_ts), &(fd->abs_ts));
nstime_subtract(&(fd->rel_ts), &(first_packet->abs_ts));
} else
nstime_copy(&(fd->rel_ts), &nulltime);
}
static void
calcNT3(nstime_t *OT1, nstime_t *OT3, nstime_t *NT1, nstime_t *NT3,
nstime_t *deltaOT, nstime_t *deltaNT)
{
long double fnt, fot, f, secs, nsecs;
fnt = (long double)deltaNT->secs + (deltaNT->nsecs / 1000000000.0L);
fot = (long double)deltaOT->secs + (deltaOT->nsecs / 1000000000.0L);
f = fnt / fot;
nstime_copy(NT3, OT3);
nstime_subtract(NT3, OT1);
secs = f * (long double)NT3->secs;
nsecs = f * (long double)NT3->nsecs;
nsecs += (secs - floorl(secs)) * 1000000000.0L;
while (nsecs > 1000000000L) {
secs += 1;
nsecs -= 1000000000L;
}
while (nsecs < 0) {
secs -= 1;
nsecs += 1000000000L;
}
NT3->secs = (time_t)secs;
NT3->nsecs = (int)nsecs;
nstime_add(NT3, NT1);
}
const gchar *
time_string_parse(const gchar *time_text, int *year, int *month, int *day, gboolean *negative, int *hour, int *minute, long double *second) {
gchar *pts;
if (!time_text || !hour || !minute || !second)
return "Unable to convert time.";
pts = (gchar *)time_text;
while (isspace(pts[0]))
++pts;
if (year && month && day) {
if (pts[0] == '\0')
return "Time is empty.";
if (sscanf(pts, "%d-%d-%d %d:%d:%Lf", year, month, day, hour, minute, second) == 6) {
CHECK_YEARS(year);
CHECK_MONTHS(month);
CHECK_DAYS(day);
CHECK_HOURS(hour);
CHECK_MINUTE(minute);
CHECK_SECOND(second);
} else if (sscanf(pts, "%d:%d:%Lf", hour, minute, second) == 3) {
*year = *month = *day = 0;
CHECK_HOUR(hour);
CHECK_MINUTE(minute);
CHECK_SECOND(second);
} else {
return "Could not parse the time. Expected [YYYY-MM-DD] "
"hh:mm:ss[.dec].";
}
} else {
if (!negative)
return "Unable to convert time.";
*negative = FALSE;
if (pts[0] == '-') {
*negative = TRUE;
pts++;
}
if (pts[0] == '\0')
return "Time is empty.";
if (sscanf(pts, "%d:%d:%Lf", hour, minute, second) == 3) {
CHECK_HOUR(hour);
CHECK_MINUTE(minute);
CHECK_SECOND(second);
} else if (sscanf(pts, "%d:%Lf", minute, second) == 2) {
CHECK_MINUTE(minute);
CHECK_SECOND(second);
*hour = 0;
} else if (sscanf(pts, "%Lf", second) == 1) {
CHECK_SECOND(second);
*hour = *minute = 0;
} else {
return "Could not parse the time: Expected [[hh:]mm:]ss.[dec].";
}
}
return NULL;
}
static const gchar *
time_string_to_nstime(const gchar *time_text, nstime_t *packettime, nstime_t *nstime)
{
int h, m, Y, M, D;
long double f;
struct tm tm, *tmptm;
time_t tt;
const gchar *err_str;
if ((err_str = time_string_parse(time_text, &Y, &M, &D, NULL, &h, &m, &f)) != NULL)
return err_str;
tmptm = localtime(&(packettime->secs));
if (tmptm) {
tm = *tmptm;
} else {
memset (&tm, 0, sizeof (tm));
}
if (Y != 0) {
tm.tm_year = Y - 1900;
tm.tm_mon = M - 1;
tm.tm_mday = D;
}
tm.tm_hour = h;
tm.tm_min = m;
tm.tm_sec = (int)floorl(f);
tt = mktime(&tm);
if (tt == -1) {
return "Mktime went wrong. Is the time valid?";
}
nstime->secs = tt;
f -= tm.tm_sec;
nstime->nsecs = (int)(f * 1000000000);
return NULL;
}
const gchar *
time_shift_all(capture_file *cf, const gchar *offset_text)
{
nstime_t offset;
long double offset_float = 0;
guint32 i;
frame_data *fd;
gboolean neg;
int h, m;
long double f;
const gchar *err_str;
if (!cf || !offset_text)
return "Nothing to work with.";
if ((err_str = time_string_parse(offset_text, NULL, NULL, NULL, &neg, &h, &m, &f)) != NULL)
return err_str;
offset_float = h * 3600 + m * 60 + f;
if (offset_float == 0)
return "Offset is zero.";
nstime_set_zero(&offset);
offset.secs = (time_t)floorl(offset_float);
offset_float -= offset.secs;
offset.nsecs = (int)(offset_float * 1000000000);
if ((fd = frame_data_sequence_find(cf->frames, 1)) == NULL)
return "No frames found.";
modify_time_init(fd);
for (i = 1; i <= cf->count; i++) {
if ((fd = frame_data_sequence_find(cf->frames, i)) == NULL)
continue;
modify_time_perform(fd, neg ? SHIFT_NEG : SHIFT_POS, &offset, SHIFT_KEEPOFFSET);
}
packet_list_queue_draw();
return NULL;
}
const gchar *
time_shift_settime(capture_file *cf, guint packet_num, const gchar *time_text)
{
nstime_t set_time, diff_time, packet_time;
frame_data *fd, *packetfd;
guint32 i;
const gchar *err_str;
if (!cf || !time_text)
return "Nothing to work with.";
if (packet_num < 1 || packet_num > cf->count)
return "Packet out of range.";
if ((packetfd = frame_data_sequence_find(cf->frames, packet_num)) == NULL)
return "No packets found.";
nstime_delta(&packet_time, &(packetfd->abs_ts), &(packetfd->shift_offset));
if ((err_str = time_string_to_nstime(time_text, &packet_time, &set_time)) != NULL)
return err_str;
nstime_delta(&diff_time, &set_time, &packet_time);
if ((fd = frame_data_sequence_find(cf->frames, 1)) == NULL)
return "No frames found.";
modify_time_init(fd);
for (i = 1; i <= cf->count; i++) {
if ((fd = frame_data_sequence_find(cf->frames, i)) == NULL)
continue;
modify_time_perform(fd, SHIFT_POS, &diff_time, SHIFT_SETTOZERO);
}
packet_list_queue_draw();
return NULL;
}
const gchar *
time_shift_adjtime(capture_file *cf, guint packet1_num, const gchar *time1_text, guint packet2_num, const gchar *time2_text)
{
nstime_t nt1, nt2, ot1, ot2, nt3;
nstime_t dnt, dot, d3t;
frame_data *fd, *packet1fd, *packet2fd;
guint32 i;
const gchar *err_str;
if (!cf || !time1_text || !time2_text)
return "Nothing to work with.";
if (packet1_num < 1 || packet1_num > cf->count || packet2_num < 1 || packet2_num > cf->count)
return "Packet out of range.";
if ((packet1fd = frame_data_sequence_find(cf->frames, packet1_num)) == NULL)
return "No frames found.";
nstime_copy(&ot1, &(packet1fd->abs_ts));
nstime_subtract(&ot1, &(packet1fd->shift_offset));
if ((err_str = time_string_to_nstime(time1_text, &ot1, &nt1)) != NULL)
return err_str;
if ((packet2fd = frame_data_sequence_find(cf->frames, packet2_num)) == NULL)
return "No frames found.";
nstime_copy(&ot2, &(packet2fd->abs_ts));
nstime_subtract(&ot2, &(packet2fd->shift_offset));
if ((err_str = time_string_to_nstime(time2_text, &ot2, &nt2)) != NULL)
return err_str;
nstime_copy(&dot, &ot2);
nstime_subtract(&dot, &ot1);
nstime_copy(&dnt, &nt2);
nstime_subtract(&dnt, &nt1);
if ((fd = frame_data_sequence_find(cf->frames, 1)) == NULL)
return "No frames found.";
modify_time_init(fd);
for (i = 1; i <= cf->count; i++) {
if ((fd = frame_data_sequence_find(cf->frames, i)) == NULL)
continue;
nstime_subtract(&(fd->abs_ts), &(fd->shift_offset));
nstime_set_zero(&(fd->shift_offset));
calcNT3(&ot1, &(fd->abs_ts), &nt1, &nt3, &dot, &dnt);
nstime_copy(&d3t, &nt3);
nstime_subtract(&d3t, &(fd->abs_ts));
modify_time_perform(fd, SHIFT_POS, &d3t, SHIFT_SETTOZERO);
}
packet_list_queue_draw();
return NULL;
}
const gchar *
time_shift_undo(capture_file *cf)
{
guint32 i;
frame_data *fd;
nstime_t nulltime;
if (!cf)
return "Nothing to work with.";
nulltime.secs = nulltime.nsecs = 0;
if ((fd = frame_data_sequence_find(cf->frames, 1)) == NULL)
return "No frames found.";
modify_time_init(fd);
for (i = 1; i <= cf->count; i++) {
if ((fd = frame_data_sequence_find(cf->frames, i)) == NULL)
continue;
modify_time_perform(fd, SHIFT_NEG, &nulltime, SHIFT_SETTOZERO);
}
packet_list_queue_draw();
return NULL;
}
