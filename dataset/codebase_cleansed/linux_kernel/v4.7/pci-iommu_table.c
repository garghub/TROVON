static struct iommu_table_entry * __init
find_dependents_of(struct iommu_table_entry *start,
struct iommu_table_entry *finish,
struct iommu_table_entry *q)
{
struct iommu_table_entry *p;
if (!q)
return NULL;
for (p = start; p < finish; p++)
if (p->detect == q->depend)
return p;
return NULL;
}
void __init sort_iommu_table(struct iommu_table_entry *start,
struct iommu_table_entry *finish) {
struct iommu_table_entry *p, *q, tmp;
for (p = start; p < finish; p++) {
again:
q = find_dependents_of(start, finish, p);
if (q > p) {
tmp = *p;
memmove(p, q, sizeof(*p));
*q = tmp;
goto again;
}
}
}
void __init check_iommu_entries(struct iommu_table_entry *start,
struct iommu_table_entry *finish)
{
struct iommu_table_entry *p, *q, *x;
for (p = start; p < finish; p++) {
q = find_dependents_of(start, finish, p);
x = find_dependents_of(start, finish, q);
if (p == x) {
printk(KERN_ERR "CYCLIC DEPENDENCY FOUND! %pS depends on %pS and vice-versa. BREAKING IT.\n",
p->detect, q->detect);
x->depend = 0;
}
}
for (p = start; p < finish; p++) {
q = find_dependents_of(p, finish, p);
if (q && q > p) {
printk(KERN_ERR "EXECUTION ORDER INVALID! %pS should be called before %pS!\n",
p->detect, q->detect);
}
}
}
void __init check_iommu_entries(struct iommu_table_entry *start,
struct iommu_table_entry *finish)
{
}
