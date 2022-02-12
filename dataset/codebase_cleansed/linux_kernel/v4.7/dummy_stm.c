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
static int dummy_stm_link(struct stm_data *data, unsigned int master,
unsigned int channel)
{
if (fail_mode && (channel & fail_mode))
return -EINVAL;
return 0;
}
static int dummy_stm_init(void)
{
int i, ret = -ENOMEM;
if (nr_dummies < 0 || nr_dummies > DUMMY_STM_MAX)
return -EINVAL;
for (i = 0; i < nr_dummies; i++) {
dummy_stm[i].name = kasprintf(GFP_KERNEL, "dummy_stm.%d", i);
if (!dummy_stm[i].name)
goto fail_unregister;
dummy_stm[i].sw_start = 0x0000;
dummy_stm[i].sw_end = 0xffff;
dummy_stm[i].sw_nchannels = 0xffff;
dummy_stm[i].packet = dummy_stm_packet;
dummy_stm[i].link = dummy_stm_link;
ret = stm_register_device(NULL, &dummy_stm[i], THIS_MODULE);
if (ret)
goto fail_free;
}
return 0;
fail_unregister:
for (i--; i >= 0; i--) {
stm_unregister_device(&dummy_stm[i]);
fail_free:
kfree(dummy_stm[i].name);
}
return ret;
}
static void dummy_stm_exit(void)
{
int i;
for (i = 0; i < nr_dummies; i++) {
stm_unregister_device(&dummy_stm[i]);
kfree(dummy_stm[i].name);
}
}
