static void nft_cmp_fast_eval(const struct nft_expr *expr,
struct nft_data data[NFT_REG_MAX + 1])
{
const struct nft_cmp_fast_expr *priv = nft_expr_priv(expr);
u32 mask;
mask = ~0U >> (sizeof(priv->data) * BITS_PER_BYTE - priv->len);
if ((data[priv->sreg].data[0] & mask) == priv->data)
return;
data[NFT_REG_VERDICT].verdict = NFT_BREAK;
}
static bool nft_payload_fast_eval(const struct nft_expr *expr,
struct nft_data data[NFT_REG_MAX + 1],
const struct nft_pktinfo *pkt)
{
const struct nft_payload *priv = nft_expr_priv(expr);
const struct sk_buff *skb = pkt->skb;
struct nft_data *dest = &data[priv->dreg];
unsigned char *ptr;
if (priv->base == NFT_PAYLOAD_NETWORK_HEADER)
ptr = skb_network_header(skb);
else
ptr = skb_network_header(skb) + pkt->xt.thoff;
ptr += priv->offset;
if (unlikely(ptr + priv->len >= skb_tail_pointer(skb)))
return false;
if (priv->len == 2)
*(u16 *)dest->data = *(u16 *)ptr;
else if (priv->len == 4)
*(u32 *)dest->data = *(u32 *)ptr;
else
*(u8 *)dest->data = *(u8 *)ptr;
return true;
}
static inline void
nft_chain_stats(const struct nft_chain *this, const struct nft_pktinfo *pkt,
struct nft_jumpstack *jumpstack, unsigned int stackptr)
{
struct nft_stats __percpu *stats;
const struct nft_chain *chain = stackptr ? jumpstack[0].chain : this;
rcu_read_lock_bh();
stats = rcu_dereference(nft_base_chain(chain)->stats);
__this_cpu_inc(stats->pkts);
__this_cpu_add(stats->bytes, pkt->skb->len);
rcu_read_unlock_bh();
}
static void nft_trace_packet(const struct nft_pktinfo *pkt,
const struct nft_chain *chain,
int rulenum, enum nft_trace type)
{
struct net *net = dev_net(pkt->in ? pkt->in : pkt->out);
nf_log_packet(net, pkt->xt.family, pkt->ops->hooknum, pkt->skb, pkt->in,
pkt->out, &trace_loginfo, "TRACE: %s:%s:%s:%u ",
chain->table->name, chain->name, comments[type],
rulenum);
}
unsigned int
nft_do_chain(struct nft_pktinfo *pkt, const struct nf_hook_ops *ops)
{
const struct nft_chain *chain = ops->priv;
const struct nft_rule *rule;
const struct nft_expr *expr, *last;
struct nft_data data[NFT_REG_MAX + 1];
unsigned int stackptr = 0;
struct nft_jumpstack jumpstack[NFT_JUMP_STACK_SIZE];
int rulenum = 0;
unsigned int gencursor = ACCESS_ONCE(chain->net->nft.gencursor);
do_chain:
rule = list_entry(&chain->rules, struct nft_rule, list);
next_rule:
data[NFT_REG_VERDICT].verdict = NFT_CONTINUE;
list_for_each_entry_continue_rcu(rule, &chain->rules, list) {
if (unlikely(rule->genmask & (1 << gencursor)))
continue;
rulenum++;
nft_rule_for_each_expr(expr, last, rule) {
if (expr->ops == &nft_cmp_fast_ops)
nft_cmp_fast_eval(expr, data);
else if (expr->ops != &nft_payload_fast_ops ||
!nft_payload_fast_eval(expr, data, pkt))
expr->ops->eval(expr, data, pkt);
if (data[NFT_REG_VERDICT].verdict != NFT_CONTINUE)
break;
}
switch (data[NFT_REG_VERDICT].verdict) {
case NFT_BREAK:
data[NFT_REG_VERDICT].verdict = NFT_CONTINUE;
case NFT_CONTINUE:
continue;
}
break;
}
switch (data[NFT_REG_VERDICT].verdict & NF_VERDICT_MASK) {
case NF_ACCEPT:
case NF_DROP:
case NF_QUEUE:
if (unlikely(pkt->skb->nf_trace))
nft_trace_packet(pkt, chain, rulenum, NFT_TRACE_RULE);
return data[NFT_REG_VERDICT].verdict;
}
switch (data[NFT_REG_VERDICT].verdict) {
case NFT_JUMP:
if (unlikely(pkt->skb->nf_trace))
nft_trace_packet(pkt, chain, rulenum, NFT_TRACE_RULE);
BUG_ON(stackptr >= NFT_JUMP_STACK_SIZE);
jumpstack[stackptr].chain = chain;
jumpstack[stackptr].rule = rule;
jumpstack[stackptr].rulenum = rulenum;
stackptr++;
case NFT_GOTO:
chain = data[NFT_REG_VERDICT].chain;
goto do_chain;
case NFT_RETURN:
if (unlikely(pkt->skb->nf_trace))
nft_trace_packet(pkt, chain, rulenum, NFT_TRACE_RETURN);
case NFT_CONTINUE:
break;
default:
WARN_ON(1);
}
if (stackptr > 0) {
if (unlikely(pkt->skb->nf_trace))
nft_trace_packet(pkt, chain, ++rulenum, NFT_TRACE_RETURN);
stackptr--;
chain = jumpstack[stackptr].chain;
rule = jumpstack[stackptr].rule;
rulenum = jumpstack[stackptr].rulenum;
goto next_rule;
}
nft_chain_stats(chain, pkt, jumpstack, stackptr);
if (unlikely(pkt->skb->nf_trace))
nft_trace_packet(pkt, chain, ++rulenum, NFT_TRACE_POLICY);
return nft_base_chain(chain)->policy;
}
int __init nf_tables_core_module_init(void)
{
int err;
err = nft_immediate_module_init();
if (err < 0)
goto err1;
err = nft_cmp_module_init();
if (err < 0)
goto err2;
err = nft_lookup_module_init();
if (err < 0)
goto err3;
err = nft_bitwise_module_init();
if (err < 0)
goto err4;
err = nft_byteorder_module_init();
if (err < 0)
goto err5;
err = nft_payload_module_init();
if (err < 0)
goto err6;
return 0;
err6:
nft_byteorder_module_exit();
err5:
nft_bitwise_module_exit();
err4:
nft_lookup_module_exit();
err3:
nft_cmp_module_exit();
err2:
nft_immediate_module_exit();
err1:
return err;
}
void nf_tables_core_module_exit(void)
{
nft_payload_module_exit();
nft_byteorder_module_exit();
nft_bitwise_module_exit();
nft_lookup_module_exit();
nft_cmp_module_exit();
nft_immediate_module_exit();
}
