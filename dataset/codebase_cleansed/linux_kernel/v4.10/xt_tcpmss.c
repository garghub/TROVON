static bool
tcpmss_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_tcpmss_match_info *info = par->matchinfo;
const struct tcphdr *th;
struct tcphdr _tcph;
const u_int8_t *op;
u8 _opt[15 * 4 - sizeof(_tcph)];
unsigned int i, optlen;
th = skb_header_pointer(skb, par->thoff, sizeof(_tcph), &_tcph);
if (th == NULL)
goto dropit;
if (th->doff*4 < sizeof(*th))
goto dropit;
optlen = th->doff*4 - sizeof(*th);
if (!optlen)
goto out;
op = skb_header_pointer(skb, par->thoff + sizeof(*th), optlen, _opt);
if (op == NULL)
goto dropit;
for (i = 0; i < optlen; ) {
if (op[i] == TCPOPT_MSS
&& (optlen - i) >= TCPOLEN_MSS
&& op[i+1] == TCPOLEN_MSS) {
u_int16_t mssval;
mssval = (op[i+2] << 8) | op[i+3];
return (mssval >= info->mss_min &&
mssval <= info->mss_max) ^ info->invert;
}
if (op[i] < 2)
i++;
else
i += op[i+1] ? : 1;
}
out:
return info->invert;
dropit:
par->hotdrop = true;
return false;
}
static int __init tcpmss_mt_init(void)
{
return xt_register_matches(tcpmss_mt_reg, ARRAY_SIZE(tcpmss_mt_reg));
}
static void __exit tcpmss_mt_exit(void)
{
xt_unregister_matches(tcpmss_mt_reg, ARRAY_SIZE(tcpmss_mt_reg));
}
