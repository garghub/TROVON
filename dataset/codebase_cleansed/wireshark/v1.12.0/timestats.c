void
time_stat_init(timestat_t *stats)
{
stats->num = 0;
stats->min_num = 0;
stats->max_num = 0;
nstime_set_zero(&stats->min);
nstime_set_zero(&stats->max);
nstime_set_zero(&stats->tot);
stats->variance = 0.0;
}
void
time_stat_update(timestat_t *stats, const nstime_t *delta, packet_info *pinfo)
{
if(stats->num==0){
stats->max=*delta;
stats->max_num=pinfo->fd->num;
stats->min=*delta;
stats->min_num=pinfo->fd->num;
}
if( (delta->secs<stats->min.secs)
||( (delta->secs==stats->min.secs)
&&(delta->nsecs<stats->min.nsecs) ) ){
stats->min=*delta;
stats->min_num=pinfo->fd->num;
}
if( (delta->secs>stats->max.secs)
||( (delta->secs==stats->max.secs)
&&(delta->nsecs>stats->max.nsecs) ) ){
stats->max=*delta;
stats->max_num=pinfo->fd->num;
}
nstime_add(&stats->tot, delta);
stats->num++;
}
gdouble get_average(const nstime_t *sum, guint32 num)
{
gdouble average;
if(num > 0) {
average = (double)sum->secs*1000 + (double)sum->nsecs/1000000;
average /= num;
}
else {
average = 0;
}
return average;
}
