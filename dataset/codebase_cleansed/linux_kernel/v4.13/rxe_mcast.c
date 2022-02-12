int rxe_mcast_get_grp(struct rxe_dev *rxe, union ib_gid *mgid,
struct rxe_mc_grp **grp_p)
{
int err;
struct rxe_mc_grp *grp;
if (rxe->attr.max_mcast_qp_attach == 0) {
err = -EINVAL;
goto err1;
}
grp = rxe_pool_get_key(&rxe->mc_grp_pool, mgid);
if (grp)
goto done;
grp = rxe_alloc(&rxe->mc_grp_pool);
if (!grp) {
err = -ENOMEM;
goto err1;
}
INIT_LIST_HEAD(&grp->qp_list);
spin_lock_init(&grp->mcg_lock);
grp->rxe = rxe;
rxe_add_key(grp, mgid);
err = rxe_mcast_add(rxe, mgid);
if (err)
goto err2;
done:
*grp_p = grp;
return 0;
err2:
rxe_drop_ref(grp);
err1:
return err;
}
int rxe_mcast_add_grp_elem(struct rxe_dev *rxe, struct rxe_qp *qp,
struct rxe_mc_grp *grp)
{
int err;
struct rxe_mc_elem *elem;
spin_lock_bh(&qp->grp_lock);
spin_lock_bh(&grp->mcg_lock);
list_for_each_entry(elem, &grp->qp_list, qp_list) {
if (elem->qp == qp) {
err = 0;
goto out;
}
}
if (grp->num_qp >= rxe->attr.max_mcast_qp_attach) {
err = -ENOMEM;
goto out;
}
elem = rxe_alloc(&rxe->mc_elem_pool);
if (!elem) {
err = -ENOMEM;
goto out;
}
rxe_add_ref(grp);
grp->num_qp++;
elem->qp = qp;
elem->grp = grp;
list_add(&elem->qp_list, &grp->qp_list);
list_add(&elem->grp_list, &qp->grp_list);
err = 0;
out:
spin_unlock_bh(&grp->mcg_lock);
spin_unlock_bh(&qp->grp_lock);
return err;
}
int rxe_mcast_drop_grp_elem(struct rxe_dev *rxe, struct rxe_qp *qp,
union ib_gid *mgid)
{
struct rxe_mc_grp *grp;
struct rxe_mc_elem *elem, *tmp;
grp = rxe_pool_get_key(&rxe->mc_grp_pool, mgid);
if (!grp)
goto err1;
spin_lock_bh(&qp->grp_lock);
spin_lock_bh(&grp->mcg_lock);
list_for_each_entry_safe(elem, tmp, &grp->qp_list, qp_list) {
if (elem->qp == qp) {
list_del(&elem->qp_list);
list_del(&elem->grp_list);
grp->num_qp--;
spin_unlock_bh(&grp->mcg_lock);
spin_unlock_bh(&qp->grp_lock);
rxe_drop_ref(elem);
rxe_drop_ref(grp);
rxe_drop_ref(grp);
return 0;
}
}
spin_unlock_bh(&grp->mcg_lock);
spin_unlock_bh(&qp->grp_lock);
rxe_drop_ref(grp);
err1:
return -EINVAL;
}
void rxe_drop_all_mcast_groups(struct rxe_qp *qp)
{
struct rxe_mc_grp *grp;
struct rxe_mc_elem *elem;
while (1) {
spin_lock_bh(&qp->grp_lock);
if (list_empty(&qp->grp_list)) {
spin_unlock_bh(&qp->grp_lock);
break;
}
elem = list_first_entry(&qp->grp_list, struct rxe_mc_elem,
grp_list);
list_del(&elem->grp_list);
spin_unlock_bh(&qp->grp_lock);
grp = elem->grp;
spin_lock_bh(&grp->mcg_lock);
list_del(&elem->qp_list);
grp->num_qp--;
spin_unlock_bh(&grp->mcg_lock);
rxe_drop_ref(grp);
rxe_drop_ref(elem);
}
}
void rxe_mc_cleanup(struct rxe_pool_entry *arg)
{
struct rxe_mc_grp *grp = container_of(arg, typeof(*grp), pelem);
struct rxe_dev *rxe = grp->rxe;
rxe_drop_key(grp);
rxe_mcast_delete(rxe, &grp->mgid);
}
