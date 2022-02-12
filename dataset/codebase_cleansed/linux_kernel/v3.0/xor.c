void
xor_blocks(unsigned int src_count, unsigned int bytes, void *dest, void **srcs)
{
unsigned long *p1, *p2, *p3, *p4;
p1 = (unsigned long *) srcs[0];
if (src_count == 1) {
active_template->do_2(bytes, dest, p1);
return;
}
p2 = (unsigned long *) srcs[1];
if (src_count == 2) {
active_template->do_3(bytes, dest, p1, p2);
return;
}
p3 = (unsigned long *) srcs[2];
if (src_count == 3) {
active_template->do_4(bytes, dest, p1, p2, p3);
return;
}
p4 = (unsigned long *) srcs[3];
active_template->do_5(bytes, dest, p1, p2, p3, p4);
}
static void
do_xor_speed(struct xor_block_template *tmpl, void *b1, void *b2)
{
int speed;
unsigned long now;
int i, count, max;
tmpl->next = template_list;
template_list = tmpl;
max = 0;
for (i = 0; i < 5; i++) {
now = jiffies;
count = 0;
while (jiffies == now) {
mb();
tmpl->do_2(BENCH_SIZE, b1, b2);
mb();
count++;
mb();
}
if (count > max)
max = count;
}
speed = max * (HZ * BENCH_SIZE / 1024);
tmpl->speed = speed;
printk(KERN_INFO " %-10s: %5d.%03d MB/sec\n", tmpl->name,
speed / 1000, speed % 1000);
}
static int __init
calibrate_xor_blocks(void)
{
void *b1, *b2;
struct xor_block_template *f, *fastest;
b1 = (void *) __get_free_pages(GFP_KERNEL | __GFP_NOTRACK, 2);
if (!b1) {
printk(KERN_WARNING "xor: Yikes! No memory available.\n");
return -ENOMEM;
}
b2 = b1 + 2*PAGE_SIZE + BENCH_SIZE;
fastest = NULL;
#ifdef XOR_SELECT_TEMPLATE
fastest = XOR_SELECT_TEMPLATE(fastest);
#endif
#define xor_speed(templ) do_xor_speed((templ), b1, b2)
if (fastest) {
printk(KERN_INFO "xor: automatically using best "
"checksumming function: %s\n",
fastest->name);
xor_speed(fastest);
} else {
printk(KERN_INFO "xor: measuring software checksum speed\n");
XOR_TRY_TEMPLATES;
fastest = template_list;
for (f = fastest; f; f = f->next)
if (f->speed > fastest->speed)
fastest = f;
}
printk(KERN_INFO "xor: using function: %s (%d.%03d MB/sec)\n",
fastest->name, fastest->speed / 1000, fastest->speed % 1000);
#undef xor_speed
free_pages((unsigned long)b1, 2);
active_template = fastest;
return 0;
}
static __exit void xor_exit(void) { }
