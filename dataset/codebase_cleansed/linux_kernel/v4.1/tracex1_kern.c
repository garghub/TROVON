int bpf_prog1(struct pt_regs *ctx)
{
char devname[IFNAMSIZ] = {};
struct net_device *dev;
struct sk_buff *skb;
int len;
skb = (struct sk_buff *) ctx->di;
dev = _(skb->dev);
len = _(skb->len);
bpf_probe_read(devname, sizeof(devname), dev->name);
if (devname[0] == 'l' && devname[1] == 'o') {
char fmt[] = "skb %p len %d\n";
bpf_trace_printk(fmt, sizeof(fmt), skb, len);
}
return 0;
}
