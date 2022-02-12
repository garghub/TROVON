int static_init(struct pcmcia_socket *s)
{
s->resource_setup_done = 1;
return 0;
}
struct resource *pcmcia_make_resource(resource_size_t start,
resource_size_t end,
unsigned long flags, const char *name)
{
struct resource *res = kzalloc(sizeof(*res), GFP_KERNEL);
if (res) {
res->name = name;
res->start = start;
res->end = start + end - 1;
res->flags = flags;
}
return res;
}
static int static_find_io(struct pcmcia_socket *s, unsigned int attr,
unsigned int *base, unsigned int num,
unsigned int align, struct resource **parent)
{
if (!s->io_offset)
return -EINVAL;
*base = s->io_offset | (*base & 0x0fff);
*parent = NULL;
return 0;
}
