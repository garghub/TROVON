static struct tcf_ematch_ops *tcf_em_lookup(u16 kind)
{
struct tcf_ematch_ops *e = NULL;
read_lock(&ematch_mod_lock);
list_for_each_entry(e, &ematch_ops, link) {
if (kind == e->kind) {
if (!try_module_get(e->owner))
e = NULL;
read_unlock(&ematch_mod_lock);
return e;
}
}
read_unlock(&ematch_mod_lock);
return NULL;
}
int tcf_em_register(struct tcf_ematch_ops *ops)
{
int err = -EEXIST;
struct tcf_ematch_ops *e;
if (ops->match == NULL)
return -EINVAL;
write_lock(&ematch_mod_lock);
list_for_each_entry(e, &ematch_ops, link)
if (ops->kind == e->kind)
goto errout;
list_add_tail(&ops->link, &ematch_ops);
err = 0;
errout:
write_unlock(&ematch_mod_lock);
return err;
}
void tcf_em_unregister(struct tcf_ematch_ops *ops)
{
write_lock(&ematch_mod_lock);
list_del(&ops->link);
write_unlock(&ematch_mod_lock);
}
static inline struct tcf_ematch *tcf_em_get_match(struct tcf_ematch_tree *tree,
int index)
{
return &tree->matches[index];
}
static int tcf_em_validate(struct tcf_proto *tp,
struct tcf_ematch_tree_hdr *tree_hdr,
struct tcf_ematch *em, struct nlattr *nla, int idx)
{
int err = -EINVAL;
struct tcf_ematch_hdr *em_hdr = nla_data(nla);
int data_len = nla_len(nla) - sizeof(*em_hdr);
void *data = (void *) em_hdr + sizeof(*em_hdr);
if (!TCF_EM_REL_VALID(em_hdr->flags))
goto errout;
if (em_hdr->kind == TCF_EM_CONTAINER) {
u32 ref;
if (data_len < sizeof(ref))
goto errout;
ref = *(u32 *) data;
if (ref >= tree_hdr->nmatches)
goto errout;
if (ref <= idx)
goto errout;
em->data = ref;
} else {
em->ops = tcf_em_lookup(em_hdr->kind);
if (em->ops == NULL) {
err = -ENOENT;
#ifdef CONFIG_MODULES
__rtnl_unlock();
request_module("ematch-kind-%u", em_hdr->kind);
rtnl_lock();
em->ops = tcf_em_lookup(em_hdr->kind);
if (em->ops) {
module_put(em->ops->owner);
err = -EAGAIN;
}
#endif
goto errout;
}
if (em->ops->datalen && data_len < em->ops->datalen)
goto errout;
if (em->ops->change) {
err = em->ops->change(tp, data, data_len, em);
if (err < 0)
goto errout;
} else if (data_len > 0) {
if (em_hdr->flags & TCF_EM_SIMPLE) {
if (data_len < sizeof(u32))
goto errout;
em->data = *(u32 *) data;
} else {
void *v = kmemdup(data, data_len, GFP_KERNEL);
if (v == NULL) {
err = -ENOBUFS;
goto errout;
}
em->data = (unsigned long) v;
}
}
}
em->matchid = em_hdr->matchid;
em->flags = em_hdr->flags;
em->datalen = data_len;
err = 0;
errout:
return err;
}
int tcf_em_tree_validate(struct tcf_proto *tp, struct nlattr *nla,
struct tcf_ematch_tree *tree)
{
int idx, list_len, matches_len, err;
struct nlattr *tb[TCA_EMATCH_TREE_MAX + 1];
struct nlattr *rt_match, *rt_hdr, *rt_list;
struct tcf_ematch_tree_hdr *tree_hdr;
struct tcf_ematch *em;
memset(tree, 0, sizeof(*tree));
if (!nla)
return 0;
err = nla_parse_nested(tb, TCA_EMATCH_TREE_MAX, nla, em_policy);
if (err < 0)
goto errout;
err = -EINVAL;
rt_hdr = tb[TCA_EMATCH_TREE_HDR];
rt_list = tb[TCA_EMATCH_TREE_LIST];
if (rt_hdr == NULL || rt_list == NULL)
goto errout;
tree_hdr = nla_data(rt_hdr);
memcpy(&tree->hdr, tree_hdr, sizeof(*tree_hdr));
rt_match = nla_data(rt_list);
list_len = nla_len(rt_list);
matches_len = tree_hdr->nmatches * sizeof(*em);
tree->matches = kzalloc(matches_len, GFP_KERNEL);
if (tree->matches == NULL)
goto errout;
for (idx = 0; nla_ok(rt_match, list_len); idx++) {
err = -EINVAL;
if (rt_match->nla_type != (idx + 1))
goto errout_abort;
if (idx >= tree_hdr->nmatches)
goto errout_abort;
if (nla_len(rt_match) < sizeof(struct tcf_ematch_hdr))
goto errout_abort;
em = tcf_em_get_match(tree, idx);
err = tcf_em_validate(tp, tree_hdr, em, rt_match, idx);
if (err < 0)
goto errout_abort;
rt_match = nla_next(rt_match, &list_len);
}
if (idx != tree_hdr->nmatches) {
err = -EINVAL;
goto errout_abort;
}
err = 0;
errout:
return err;
errout_abort:
tcf_em_tree_destroy(tp, tree);
return err;
}
void tcf_em_tree_destroy(struct tcf_proto *tp, struct tcf_ematch_tree *tree)
{
int i;
if (tree->matches == NULL)
return;
for (i = 0; i < tree->hdr.nmatches; i++) {
struct tcf_ematch *em = tcf_em_get_match(tree, i);
if (em->ops) {
if (em->ops->destroy)
em->ops->destroy(tp, em);
else if (!tcf_em_is_simple(em))
kfree((void *) em->data);
module_put(em->ops->owner);
}
}
tree->hdr.nmatches = 0;
kfree(tree->matches);
tree->matches = NULL;
}
int tcf_em_tree_dump(struct sk_buff *skb, struct tcf_ematch_tree *tree, int tlv)
{
int i;
u8 *tail;
struct nlattr *top_start;
struct nlattr *list_start;
top_start = nla_nest_start(skb, tlv);
if (top_start == NULL)
goto nla_put_failure;
if (nla_put(skb, TCA_EMATCH_TREE_HDR, sizeof(tree->hdr), &tree->hdr))
goto nla_put_failure;
list_start = nla_nest_start(skb, TCA_EMATCH_TREE_LIST);
if (list_start == NULL)
goto nla_put_failure;
tail = skb_tail_pointer(skb);
for (i = 0; i < tree->hdr.nmatches; i++) {
struct nlattr *match_start = (struct nlattr *)tail;
struct tcf_ematch *em = tcf_em_get_match(tree, i);
struct tcf_ematch_hdr em_hdr = {
.kind = em->ops ? em->ops->kind : TCF_EM_CONTAINER,
.matchid = em->matchid,
.flags = em->flags
};
if (nla_put(skb, i + 1, sizeof(em_hdr), &em_hdr))
goto nla_put_failure;
if (em->ops && em->ops->dump) {
if (em->ops->dump(skb, em) < 0)
goto nla_put_failure;
} else if (tcf_em_is_container(em) || tcf_em_is_simple(em)) {
u32 u = em->data;
nla_put_nohdr(skb, sizeof(u), &u);
} else if (em->datalen > 0)
nla_put_nohdr(skb, em->datalen, (void *) em->data);
tail = skb_tail_pointer(skb);
match_start->nla_len = tail - (u8 *)match_start;
}
nla_nest_end(skb, list_start);
nla_nest_end(skb, top_start);
return 0;
nla_put_failure:
return -1;
}
static inline int tcf_em_match(struct sk_buff *skb, struct tcf_ematch *em,
struct tcf_pkt_info *info)
{
int r = em->ops->match(skb, em, info);
return tcf_em_is_inverted(em) ? !r : r;
}
int __tcf_em_tree_match(struct sk_buff *skb, struct tcf_ematch_tree *tree,
struct tcf_pkt_info *info)
{
int stackp = 0, match_idx = 0, res = 0;
struct tcf_ematch *cur_match;
int stack[CONFIG_NET_EMATCH_STACK];
proceed:
while (match_idx < tree->hdr.nmatches) {
cur_match = tcf_em_get_match(tree, match_idx);
if (tcf_em_is_container(cur_match)) {
if (unlikely(stackp >= CONFIG_NET_EMATCH_STACK))
goto stack_overflow;
stack[stackp++] = match_idx;
match_idx = cur_match->data;
goto proceed;
}
res = tcf_em_match(skb, cur_match, info);
if (tcf_em_early_end(cur_match, res))
break;
match_idx++;
}
pop_stack:
if (stackp > 0) {
match_idx = stack[--stackp];
cur_match = tcf_em_get_match(tree, match_idx);
if (tcf_em_early_end(cur_match, res))
goto pop_stack;
else {
match_idx++;
goto proceed;
}
}
return res;
stack_overflow:
net_warn_ratelimited("tc ematch: local stack overflow, increase NET_EMATCH_STACK\n");
return -1;
}
