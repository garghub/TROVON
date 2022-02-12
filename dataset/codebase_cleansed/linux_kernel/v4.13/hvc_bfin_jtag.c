static inline uint32_t bfin_write_emudat(uint32_t emudat)
{
__asm__ __volatile__("emudat = %0;" : : "d"(emudat));
return emudat;
}
static inline uint32_t bfin_read_emudat(void)
{
uint32_t emudat;
__asm__ __volatile__("%0 = emudat;" : "=d"(emudat));
return emudat;
}
static int hvc_bfin_put_chars(uint32_t vt, const char *buf, int count)
{
static uint32_t outbound_len;
uint32_t emudat;
int ret;
if (bfin_read_DBGSTAT() & EMUDOF)
return 0;
if (!outbound_len) {
outbound_len = count;
bfin_write_emudat(outbound_len);
return 0;
}
ret = min(outbound_len, (uint32_t)4);
memcpy(&emudat, buf, ret);
bfin_write_emudat(emudat);
outbound_len -= ret;
return ret;
}
static int hvc_bfin_get_chars(uint32_t vt, char *buf, int count)
{
static uint32_t inbound_len;
uint32_t emudat;
int ret;
if (!(bfin_read_DBGSTAT() & EMUDIF))
return 0;
emudat = bfin_read_emudat();
if (!inbound_len) {
inbound_len = emudat;
return 0;
}
ret = min(inbound_len, (uint32_t)4);
memcpy(buf, &emudat, ret);
inbound_len -= ret;
return ret;
}
static int __init hvc_bfin_console_init(void)
{
hvc_instantiate(0, 0, &hvc_bfin_get_put_ops);
return 0;
}
static int __init hvc_bfin_init(void)
{
hvc_alloc(0, 0, &hvc_bfin_get_put_ops, 128);
return 0;
}
