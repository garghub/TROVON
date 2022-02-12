static int drbd_nla_check_mandatory(int maxtype, struct nlattr *nla)
{
struct nlattr *head = nla_data(nla);
int len = nla_len(nla);
int rem;
nla_for_each_attr(nla, head, len, rem) {
if (nla->nla_type & DRBD_GENLA_F_MANDATORY) {
nla->nla_type &= ~DRBD_GENLA_F_MANDATORY;
if (nla_type(nla) > maxtype)
return -EOPNOTSUPP;
}
}
return 0;
}
int drbd_nla_parse_nested(struct nlattr *tb[], int maxtype, struct nlattr *nla,
const struct nla_policy *policy)
{
int err;
err = drbd_nla_check_mandatory(maxtype, nla);
if (!err)
err = nla_parse_nested(tb, maxtype, nla, policy);
return err;
}
struct nlattr *drbd_nla_find_nested(int maxtype, struct nlattr *nla, int attrtype)
{
int err;
err = drbd_nla_check_mandatory(maxtype, nla);
if (err)
return ERR_PTR(err);
return nla_find_nested(nla, attrtype);
}
