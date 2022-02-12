void nstime_set_zero(nstime_t *nstime)
{
nstime->secs = 0;
nstime->nsecs = 0;
}
gboolean nstime_is_zero(nstime_t *nstime)
{
if(nstime->secs == 0 && nstime->nsecs == 0) {
return TRUE;
} else {
return FALSE;
}
}
void nstime_set_unset(nstime_t *nstime)
{
nstime->secs = 0;
nstime->nsecs = G_MAXINT;
}
gboolean nstime_is_unset(const nstime_t *nstime)
{
if(nstime->secs == 0 && nstime->nsecs == G_MAXINT) {
return TRUE;
} else {
return FALSE;
}
}
void nstime_copy(nstime_t *a, const nstime_t *b)
{
a->secs = b->secs;
a->nsecs = b->nsecs;
}
void nstime_delta(nstime_t *delta, const nstime_t *b, const nstime_t *a )
{
if (b->secs == a->secs) {
delta->secs = 0;
delta->nsecs = b->nsecs - a->nsecs;
} else if (b->secs < a->secs) {
delta->secs = b->secs - a->secs;
delta->nsecs = b->nsecs - a->nsecs;
if(delta->nsecs > 0) {
delta->nsecs -= NS_PER_S;
delta->secs ++;
}
} else {
delta->secs = b->secs - a->secs;
delta->nsecs = b->nsecs - a->nsecs;
if(delta->nsecs < 0) {
delta->nsecs += NS_PER_S;
delta->secs --;
}
}
}
void nstime_sum(nstime_t *sum, const nstime_t *a, const nstime_t *b)
{
sum->secs = a->secs + b->secs;
sum->nsecs = a->nsecs + b->nsecs;
if(sum->nsecs>=NS_PER_S || (sum->nsecs>0 && sum->secs<0)){
sum->nsecs-=NS_PER_S;
sum->secs++;
} else if(sum->nsecs<=-NS_PER_S || (sum->nsecs<0 && sum->secs>0)) {
sum->nsecs+=NS_PER_S;
sum->secs--;
}
}
int nstime_cmp (const nstime_t *a, const nstime_t *b )
{
if (G_UNLIKELY(nstime_is_unset(a))) {
if (G_UNLIKELY(nstime_is_unset(b))) {
return 0;
} else {
return -1;
}
} else {
if (G_UNLIKELY(nstime_is_unset(b))) {
return 1;
}
}
if (a->secs == b->secs) {
return a->nsecs - b->nsecs;
} else {
return (int) (a->secs - b->secs);
}
}
double nstime_to_msec(const nstime_t *nstime)
{
return ((double)nstime->secs*1000 + (double)nstime->nsecs/1000000);
}
double nstime_to_sec(const nstime_t *nstime)
{
return ((double)nstime->secs + (double)nstime->nsecs/NS_PER_S);
}
static gboolean
common_filetime_to_nstime(nstime_t *nstime, guint64 ftsecs, int nsecs)
{
gint64 secs;
secs = (gint64)ftsecs - TIME_FIXUP_CONSTANT;
if (!(TIME_T_MIN <= secs && secs <= TIME_T_MAX)) {
return FALSE;
}
nstime->secs = (time_t) secs;
nstime->nsecs = nsecs;
return TRUE;
}
gboolean
filetime_to_nstime(nstime_t *nstime, guint64 filetime)
{
guint64 ftsecs;
int nsecs;
ftsecs = filetime / 10000000;
nsecs = (int)((filetime % 10000000)*100);
return common_filetime_to_nstime(nstime, ftsecs, nsecs);
}
gboolean
nsfiletime_to_nstime(nstime_t *nstime, guint64 nsfiletime)
{
guint64 ftsecs;
int nsecs;
ftsecs = nsfiletime / NS_PER_S;
nsecs = (int)(nsfiletime % NS_PER_S);
return common_filetime_to_nstime(nstime, ftsecs, nsecs);
}
