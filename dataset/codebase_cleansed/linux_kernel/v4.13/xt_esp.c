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
static bool esp_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct ip_esp_hdr *eh;
struct ip_esp_hdr _esp;
const struct xt_esp *espinfo = par->matchinfo;
if (par->fragoff != 0)
return false;
eh = skb_header_pointer(skb, par->thoff, sizeof(_esp), &_esp);
if (eh == NULL) {
pr_debug("Dropping evil ESP tinygram.\n");
par->hotdrop = true;
return false;
}
return spi_match(espinfo->spis[0], espinfo->spis[1], ntohl(eh->spi),
!!(espinfo->invflags & XT_ESP_INV_SPI));
}
static int esp_mt_check(const struct xt_mtchk_param *par)
{
const struct xt_esp *espinfo = par->matchinfo;
if (espinfo->invflags & ~XT_ESP_INV_MASK) {
pr_debug("unknown flags %X\n", espinfo->invflags);
return -EINVAL;
}
return 0;
}
static int __init esp_mt_init(void)
{
return xt_register_matches(esp_mt_reg, ARRAY_SIZE(esp_mt_reg));
}
static void __exit esp_mt_exit(void)
{
xt_unregister_matches(esp_mt_reg, ARRAY_SIZE(esp_mt_reg));
}
