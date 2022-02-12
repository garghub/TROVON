static inline int get_compat_mq_attr(struct mq_attr *attr,
const struct compat_mq_attr __user *uattr)
{
if (!access_ok(VERIFY_READ, uattr, sizeof *uattr))
return -EFAULT;
return __get_user(attr->mq_flags, &uattr->mq_flags)
| __get_user(attr->mq_maxmsg, &uattr->mq_maxmsg)
| __get_user(attr->mq_msgsize, &uattr->mq_msgsize)
| __get_user(attr->mq_curmsgs, &uattr->mq_curmsgs);
}
static inline int put_compat_mq_attr(const struct mq_attr *attr,
struct compat_mq_attr __user *uattr)
{
if (clear_user(uattr, sizeof *uattr))
return -EFAULT;
return __put_user(attr->mq_flags, &uattr->mq_flags)
| __put_user(attr->mq_maxmsg, &uattr->mq_maxmsg)
| __put_user(attr->mq_msgsize, &uattr->mq_msgsize)
| __put_user(attr->mq_curmsgs, &uattr->mq_curmsgs);
}
