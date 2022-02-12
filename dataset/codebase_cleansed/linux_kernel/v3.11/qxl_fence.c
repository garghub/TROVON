void qxl_fence_add_release_locked(struct qxl_fence *qfence, uint32_t rel_id)
{
radix_tree_insert(&qfence->tree, rel_id, qfence);
qfence->num_active_releases++;
}
int qxl_fence_remove_release(struct qxl_fence *qfence, uint32_t rel_id)
{
void *ret;
int retval = 0;
struct qxl_bo *bo = container_of(qfence, struct qxl_bo, fence);
spin_lock(&bo->tbo.bdev->fence_lock);
ret = radix_tree_delete(&qfence->tree, rel_id);
if (ret == qfence)
qfence->num_active_releases--;
else {
DRM_DEBUG("didn't find fence in radix tree for %d\n", rel_id);
retval = -ENOENT;
}
spin_unlock(&bo->tbo.bdev->fence_lock);
return retval;
}
int qxl_fence_init(struct qxl_device *qdev, struct qxl_fence *qfence)
{
qfence->qdev = qdev;
qfence->num_active_releases = 0;
INIT_RADIX_TREE(&qfence->tree, GFP_ATOMIC);
return 0;
}
void qxl_fence_fini(struct qxl_fence *qfence)
{
kfree(qfence->release_ids);
qfence->num_active_releases = 0;
}
