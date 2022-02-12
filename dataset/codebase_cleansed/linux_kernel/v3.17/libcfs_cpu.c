struct cfs_cpt_table *
cfs_cpt_table_alloc(unsigned int ncpt)
{
struct cfs_cpt_table *cptab;
if (ncpt != 1) {
CERROR("Can't support cpu partition number %d\n", ncpt);
return NULL;
}
LIBCFS_ALLOC(cptab, sizeof(*cptab));
if (cptab != NULL) {
cptab->ctb_version = CFS_CPU_VERSION_MAGIC;
cptab->ctb_nparts = ncpt;
}
return cptab;
}
void
cfs_cpt_table_free(struct cfs_cpt_table *cptab)
{
LASSERT(cptab->ctb_version == CFS_CPU_VERSION_MAGIC);
LIBCFS_FREE(cptab, sizeof(*cptab));
}
int
cfs_cpt_table_print(struct cfs_cpt_table *cptab, char *buf, int len)
{
int rc = 0;
rc = snprintf(buf, len, "%d\t: %d\n", 0, 0);
len -= rc;
if (len <= 0)
return -EFBIG;
return rc;
}
int
cfs_cpt_number(struct cfs_cpt_table *cptab)
{
return 1;
}
int
cfs_cpt_weight(struct cfs_cpt_table *cptab, int cpt)
{
return 1;
}
int
cfs_cpt_online(struct cfs_cpt_table *cptab, int cpt)
{
return 1;
}
int
cfs_cpt_set_cpu(struct cfs_cpt_table *cptab, int cpt, int cpu)
{
return 1;
}
void
cfs_cpt_unset_cpu(struct cfs_cpt_table *cptab, int cpt, int cpu)
{
}
int
cfs_cpt_set_cpumask(struct cfs_cpt_table *cptab, int cpt, cpumask_t *mask)
{
return 1;
}
void
cfs_cpt_unset_cpumask(struct cfs_cpt_table *cptab, int cpt, cpumask_t *mask)
{
}
int
cfs_cpt_set_node(struct cfs_cpt_table *cptab, int cpt, int node)
{
return 1;
}
void
cfs_cpt_unset_node(struct cfs_cpt_table *cptab, int cpt, int node)
{
}
int
cfs_cpt_set_nodemask(struct cfs_cpt_table *cptab, int cpt, nodemask_t *mask)
{
return 1;
}
void
cfs_cpt_unset_nodemask(struct cfs_cpt_table *cptab, int cpt, nodemask_t *mask)
{
}
void
cfs_cpt_clear(struct cfs_cpt_table *cptab, int cpt)
{
}
int
cfs_cpt_spread_node(struct cfs_cpt_table *cptab, int cpt)
{
return 0;
}
int
cfs_cpu_ht_nsiblings(int cpu)
{
return 1;
}
int
cfs_cpt_current(struct cfs_cpt_table *cptab, int remap)
{
return 0;
}
int
cfs_cpt_of_cpu(struct cfs_cpt_table *cptab, int cpu)
{
return 0;
}
int
cfs_cpt_bind(struct cfs_cpt_table *cptab, int cpt)
{
return 0;
}
void
cfs_cpu_fini(void)
{
if (cfs_cpt_table != NULL) {
cfs_cpt_table_free(cfs_cpt_table);
cfs_cpt_table = NULL;
}
}
int
cfs_cpu_init(void)
{
cfs_cpt_table = cfs_cpt_table_alloc(1);
return cfs_cpt_table != NULL ? 0 : -1;
}
