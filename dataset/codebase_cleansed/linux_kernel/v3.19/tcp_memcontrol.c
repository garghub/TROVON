int tcp_init_cgroup(struct mem_cgroup *memcg, struct cgroup_subsys *ss)
{
struct mem_cgroup *parent = parent_mem_cgroup(memcg);
struct page_counter *counter_parent = NULL;
struct cg_proto *cg_proto, *parent_cg;
cg_proto = tcp_prot.proto_cgroup(memcg);
if (!cg_proto)
return 0;
cg_proto->sysctl_mem[0] = sysctl_tcp_mem[0];
cg_proto->sysctl_mem[1] = sysctl_tcp_mem[1];
cg_proto->sysctl_mem[2] = sysctl_tcp_mem[2];
cg_proto->memory_pressure = 0;
cg_proto->memcg = memcg;
parent_cg = tcp_prot.proto_cgroup(parent);
if (parent_cg)
counter_parent = &parent_cg->memory_allocated;
page_counter_init(&cg_proto->memory_allocated, counter_parent);
percpu_counter_init(&cg_proto->sockets_allocated, 0, GFP_KERNEL);
return 0;
}
void tcp_destroy_cgroup(struct mem_cgroup *memcg)
{
struct cg_proto *cg_proto;
cg_proto = tcp_prot.proto_cgroup(memcg);
if (!cg_proto)
return;
percpu_counter_destroy(&cg_proto->sockets_allocated);
}
static int tcp_update_limit(struct mem_cgroup *memcg, unsigned long nr_pages)
{
struct cg_proto *cg_proto;
int i;
int ret;
cg_proto = tcp_prot.proto_cgroup(memcg);
if (!cg_proto)
return -EINVAL;
ret = page_counter_limit(&cg_proto->memory_allocated, nr_pages);
if (ret)
return ret;
for (i = 0; i < 3; i++)
cg_proto->sysctl_mem[i] = min_t(long, nr_pages,
sysctl_tcp_mem[i]);
if (nr_pages == PAGE_COUNTER_MAX)
clear_bit(MEMCG_SOCK_ACTIVE, &cg_proto->flags);
else {
if (!test_and_set_bit(MEMCG_SOCK_ACTIVATED, &cg_proto->flags))
static_key_slow_inc(&memcg_socket_limit_enabled);
set_bit(MEMCG_SOCK_ACTIVE, &cg_proto->flags);
}
return 0;
}
static ssize_t tcp_cgroup_write(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(of_css(of));
unsigned long nr_pages;
int ret = 0;
buf = strstrip(buf);
switch (of_cft(of)->private) {
case RES_LIMIT:
ret = page_counter_memparse(buf, &nr_pages);
if (ret)
break;
mutex_lock(&tcp_limit_mutex);
ret = tcp_update_limit(memcg, nr_pages);
mutex_unlock(&tcp_limit_mutex);
break;
default:
ret = -EINVAL;
break;
}
return ret ?: nbytes;
}
static u64 tcp_cgroup_read(struct cgroup_subsys_state *css, struct cftype *cft)
{
struct mem_cgroup *memcg = mem_cgroup_from_css(css);
struct cg_proto *cg_proto = tcp_prot.proto_cgroup(memcg);
u64 val;
switch (cft->private) {
case RES_LIMIT:
if (!cg_proto)
return PAGE_COUNTER_MAX;
val = cg_proto->memory_allocated.limit;
val *= PAGE_SIZE;
break;
case RES_USAGE:
if (!cg_proto)
val = atomic_long_read(&tcp_memory_allocated);
else
val = page_counter_read(&cg_proto->memory_allocated);
val *= PAGE_SIZE;
break;
case RES_FAILCNT:
if (!cg_proto)
return 0;
val = cg_proto->memory_allocated.failcnt;
break;
case RES_MAX_USAGE:
if (!cg_proto)
return 0;
val = cg_proto->memory_allocated.watermark;
val *= PAGE_SIZE;
break;
default:
BUG();
}
return val;
}
static ssize_t tcp_cgroup_reset(struct kernfs_open_file *of,
char *buf, size_t nbytes, loff_t off)
{
struct mem_cgroup *memcg;
struct cg_proto *cg_proto;
memcg = mem_cgroup_from_css(of_css(of));
cg_proto = tcp_prot.proto_cgroup(memcg);
if (!cg_proto)
return nbytes;
switch (of_cft(of)->private) {
case RES_MAX_USAGE:
page_counter_reset_watermark(&cg_proto->memory_allocated);
break;
case RES_FAILCNT:
cg_proto->memory_allocated.failcnt = 0;
break;
}
return nbytes;
}
static int __init tcp_memcontrol_init(void)
{
WARN_ON(cgroup_add_legacy_cftypes(&memory_cgrp_subsys, tcp_files));
return 0;
}
