static inline bool
spi_match(u_int32_t min, u_int32_t max, u_int32_t spi, bool invert)
{
bool r;
pr_debug("spi_match:%c 0x%x <= 0x%x <= 0x%x\n",
invert ? '!' : ' ', min, spi, max);
r = (spi >= min && spi <= max) ^ invert;
pr_debug(" result %s\n", r ? "PASS" : "FAILED");
return r;
}
static bool comp_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
struct ip_comp_hdr _comphdr;
const struct ip_comp_hdr *chdr;
const struct xt_ipcomp *compinfo = par->matchinfo;
if (par->fragoff != 0)
return false;
chdr = skb_header_pointer(skb, par->thoff, sizeof(_comphdr), &_comphdr);
if (chdr == NULL) {
pr_debug("Dropping evil IPComp tinygram.\n");
par->hotdrop = true;
return 0;
}
return spi_match(compinfo->spis[0], compinfo->spis[1],
ntohl(chdr->cpi << 16),
!!(compinfo->invflags & XT_IPCOMP_INV_SPI));
}
static int comp_mt_check(const struct xt_mtchk_param *par)
{
const struct xt_ipcomp *compinfo = par->matchinfo;
if (compinfo->invflags & ~XT_IPCOMP_INV_MASK) {
pr_err("unknown flags %X\n", compinfo->invflags);
return -EINVAL;
}
return 0;
}
static int __init comp_mt_init(void)
{
return xt_register_matches(comp_mt_reg, ARRAY_SIZE(comp_mt_reg));
}
static void __exit comp_mt_exit(void)
{
xt_unregister_matches(comp_mt_reg, ARRAY_SIZE(comp_mt_reg));
}
