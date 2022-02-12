void update_stats(struct stats *stats, u64 val)
{
double delta;
stats->n++;
delta = val - stats->mean;
stats->mean += delta / stats->n;
stats->M2 += delta*(val - stats->mean);
if (val > stats->max)
stats->max = val;
if (val < stats->min)
stats->min = val;
}
double avg_stats(struct stats *stats)
{
return stats->mean;
}
double stddev_stats(struct stats *stats)
{
double variance, variance_mean;
if (stats->n < 2)
return 0.0;
variance = stats->M2 / (stats->n - 1);
variance_mean = variance / stats->n;
return sqrt(variance_mean);
}
double rel_stddev_stats(double stddev, double avg)
{
double pct = 0.0;
if (avg)
pct = 100.0 * stddev/avg;
return pct;
}
