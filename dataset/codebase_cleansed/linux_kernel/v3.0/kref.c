void kref_init(struct kref *kref)
{
atomic_set(&kref->refcount, 1);
smp_mb();
}
void kref_get(struct kref *kref)
{
WARN_ON(!atomic_read(&kref->refcount));
atomic_inc(&kref->refcount);
smp_mb__after_atomic_inc();
}
int kref_put(struct kref *kref, void (*release)(struct kref *kref))
{
WARN_ON(release == NULL);
WARN_ON(release == (void (*)(struct kref *))kfree);
if (atomic_dec_and_test(&kref->refcount)) {
release(kref);
return 1;
}
return 0;
}
int kref_sub(struct kref *kref, unsigned int count,
void (*release)(struct kref *kref))
{
WARN_ON(release == NULL);
WARN_ON(release == (void (*)(struct kref *))kfree);
if (atomic_sub_and_test((int) count, &kref->refcount)) {
release(kref);
return 1;
}
return 0;
}
