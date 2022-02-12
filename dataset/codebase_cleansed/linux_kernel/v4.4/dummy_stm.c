static ssize_t
dummy_stm_packet(struct stm_data *stm_data, unsigned int master,
unsigned int channel, unsigned int packet, unsigned int flags,
unsigned int size, const unsigned char *payload)
{
#ifdef DEBUG
u64 pl = 0;
if (payload)
pl = *(u64 *)payload;
if (size < 8)
pl &= (1ull << (size * 8)) - 1;
trace_printk("[%u:%u] [pkt: %x/%x] (%llx)\n", master, channel,
packet, size, pl);
#endif
return size;
}
static int dummy_stm_init(void)
{
return stm_register_device(NULL, &dummy_stm, THIS_MODULE);
}
static void dummy_stm_exit(void)
{
stm_unregister_device(&dummy_stm);
}
