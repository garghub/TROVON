static noinline void __nft_trace_packet(struct nft_traceinfo *info,
const struct nft_chain *chain,
int rulenum, enum nft_trace_types type)
{
const struct nft_pktinfo *pkt = info->pkt;
if (!info->trace || !pkt->skb->nf_trace)
return;
info->chain = chain;
info->type = type;
nft_trace_notify(info);
nf_log_trace(nft_net(pkt), nft_pf(pkt), nft_hook(pkt), pkt->skb,
nft_in(pkt), nft_out(pkt), &trace_loginfo,
"TRACE: %s:%s:%s:%u ",
chain->table->name, chain->name, comments[type], rulenum);
}
static inline void nft_trace_packet(struct nft_traceinfo *info,
const struct nft_chain *chain,
const struct nft_rule *rule,
int rulenum,
enum nft_trace_types type)
{
if (static_branch_unlikely(&nft_trace_enabled)) {
info->rule = rule;
__nft_trace_packet(info, chain, rulenum, type);
}
}
static void nft_cmp_fast_eval(const struct nft_expr *expr,
struct nft_regs *regs)
{
const struct nft_cmp_fast_expr *priv = nft_expr_priv(expr);
u32 mask = nft_cmp_fast_mask(priv->len);
if ((regs->data[priv->sreg] & mask) == priv->data)
return;
regs->verdict.code = NFT_BREAK;
}
static bool nft_payload_fast_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
const struct nft_payload *priv = nft_expr_priv(expr);
const struct sk_buff *skb = pkt->skb;
u32 *dest = &regs->data[priv->dreg];
unsigned char *ptr;
if (priv->base == NFT_PAYLOAD_NETWORK_HEADER)
ptr = skb_network_header(skb);
else {
if (!pkt->tprot_set)
return false;
ptr = skb_network_header(skb) + pkt->xt.thoff;
}
ptr += priv->offset;
if (unlikely(ptr + priv->len > skb_tail_pointer(skb)))
return false;
*dest = 0;
if (priv->len == 2)
*(u16 *)dest = *(u16 *)ptr;
else if (priv->len == 4)
*(u32 *)dest = *(u32 *)ptr;
else
*(u8 *)dest = *(u8 *)ptr;
return true;
}
static noinline void nft_update_chain_stats(const struct nft_chain *chain,
const struct nft_pktinfo *pkt)
{
struct nft_stats *stats;
local_bh_disable();
stats = this_cpu_ptr(rcu_dereference(nft_base_chain(chain)->stats));
u64_stats_update_begin(&stats->syncp);
stats->pkts++;
stats->bytes += pkt->skb->len;
u64_stats_update_end(&stats->syncp);
local_bh_enable();
}
unsigned int
nft_do_chain(struct nft_pktinfo *pkt, void *priv)
{
const struct nft_chain *chain = priv, *basechain = chain;
const struct net *net = nft_net(pkt);
const struct nft_rule *rule;
const struct nft_expr *expr, *last;
struct nft_regs regs;
unsigned int stackptr = 0;
struct nft_jumpstack jumpstack[NFT_JUMP_STACK_SIZE];
int rulenum;
unsigned int gencursor = nft_genmask_cur(net);
struct nft_traceinfo info;
info.trace = false;
if (static_branch_unlikely(&nft_trace_enabled))
nft_trace_init(&info, pkt, &regs.verdict, basechain);
do_chain:
rulenum = 0;
rule = list_entry(&chain->rules, struct nft_rule, list);
next_rule:
regs.verdict.code = NFT_CONTINUE;
list_for_each_entry_continue_rcu(rule, &chain->rules, list) {
if (unlikely(rule->genmask & gencursor))
continue;
rulenum++;
nft_rule_for_each_expr(expr, last, rule) {
if (expr->ops == &nft_cmp_fast_ops)
nft_cmp_fast_eval(expr, &regs);
else if (expr->ops != &nft_payload_fast_ops ||
!nft_payload_fast_eval(expr, &regs, pkt))
expr->ops->eval(expr, &regs, pkt);
if (regs.verdict.code != NFT_CONTINUE)
break;
}
switch (regs.verdict.code) {
case NFT_BREAK:
regs.verdict.code = NFT_CONTINUE;
continue;
case NFT_CONTINUE:
nft_trace_packet(&info, chain, rule,
rulenum, NFT_TRACETYPE_RULE);
continue;
}
break;
}
switch (regs.verdict.code & NF_VERDICT_MASK) {
case NF_ACCEPT:
case NF_DROP:
case NF_QUEUE:
case NF_STOLEN:
nft_trace_packet(&info, chain, rule,
rulenum, NFT_TRACETYPE_RULE);
return regs.verdict.code;
}
switch (regs.verdict.code) {
case NFT_JUMP:
BUG_ON(stackptr >= NFT_JUMP_STACK_SIZE);
jumpstack[stackptr].chain = chain;
jumpstack[stackptr].rule = rule;
jumpstack[stackptr].rulenum = rulenum;
stackptr++;
case NFT_GOTO:
nft_trace_packet(&info, chain, rule,
rulenum, NFT_TRACETYPE_RULE);
chain = regs.verdict.chain;
goto do_chain;
case NFT_CONTINUE:
rulenum++;
case NFT_RETURN:
nft_trace_packet(&info, chain, rule,
rulenum, NFT_TRACETYPE_RETURN);
break;
default:
WARN_ON(1);
}
if (stackptr > 0) {
stackptr--;
chain = jumpstack[stackptr].chain;
rule = jumpstack[stackptr].rule;
rulenum = jumpstack[stackptr].rulenum;
goto next_rule;
}
nft_trace_packet(&info, basechain, NULL, -1,
NFT_TRACETYPE_POLICY);
if (static_branch_unlikely(&nft_counters_enabled))
nft_update_chain_stats(basechain, pkt);
return nft_base_chain(basechain)->policy;
}
int __init nf_tables_core_module_init(void)
{
int err, i;
for (i = 0; i < ARRAY_SIZE(nft_basic_types); i++) {
err = nft_register_expr(nft_basic_types[i]);
if (err)
goto err;
}
return 0;
err:
while (i-- > 0)
nft_unregister_expr(nft_basic_types[i]);
return err;
}
void nf_tables_core_module_exit(void)
{
int i;
i = ARRAY_SIZE(nft_basic_types);
while (i-- > 0)
nft_unregister_expr(nft_basic_types[i]);
}
