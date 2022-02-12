static inline const struct raid6_recov_calls *raid6_choose_recov(void)
{
const struct raid6_recov_calls *const *algo;
const struct raid6_recov_calls *best;
for (best = NULL, algo = raid6_recov_algos; *algo; algo++)
if (!best || (*algo)->priority > best->priority)
if (!(*algo)->valid || (*algo)->valid())
best = *algo;
if (best) {
raid6_2data_recov = best->data2;
raid6_datap_recov = best->datap;
pr_info("raid6: using %s recovery algorithm\n", best->name);
} else
pr_err("raid6: Yikes! No recovery algorithm found!\n");
return best;
}
int __init raid6_select_algo(void)
{
const int disks = (65536/PAGE_SIZE)+2;
const struct raid6_calls *gen_best;
const struct raid6_recov_calls *rec_best;
char *syndromes;
void *dptrs[(65536/PAGE_SIZE)+2];
int i;
for (i = 0; i < disks-2; i++)
dptrs[i] = ((char *)raid6_gfmul) + PAGE_SIZE*i;
syndromes = (void *) __get_free_pages(GFP_KERNEL, 1);
if (!syndromes) {
pr_err("raid6: Yikes! No memory available.\n");
return -ENOMEM;
}
dptrs[disks-2] = syndromes;
dptrs[disks-1] = syndromes + PAGE_SIZE;
gen_best = raid6_choose_gen(&dptrs, disks);
rec_best = raid6_choose_recov();
free_pages((unsigned long)syndromes, 1);
return gen_best && rec_best ? 0 : -EINVAL;
}
static void raid6_exit(void)
{
do { } while (0);
}
