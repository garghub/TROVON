int ceph_mdsmap_get_random_mds(struct ceph_mdsmap *m)
{
int n = 0;
int i;
if (1 == m->m_max_mds && m->m_info[0].state > 0)
return 0;
for (i = 0; i < m->m_max_mds; i++)
if (m->m_info[i].state > 0)
n++;
if (n == 0)
return -1;
n = prandom_u32() % n;
i = 0;
for (i = 0; n > 0; i++, n--)
while (m->m_info[i].state <= 0)
i++;
return i;
}
struct ceph_mdsmap *ceph_mdsmap_decode(void **p, void *end)
{
struct ceph_mdsmap *m;
const void *start = *p;
int i, j, n;
int err = -EINVAL;
u8 mdsmap_v, mdsmap_cv;
m = kzalloc(sizeof(*m), GFP_NOFS);
if (m == NULL)
return ERR_PTR(-ENOMEM);
ceph_decode_need(p, end, 1 + 1, bad);
mdsmap_v = ceph_decode_8(p);
mdsmap_cv = ceph_decode_8(p);
if (mdsmap_v >= 4) {
u32 mdsmap_len;
ceph_decode_32_safe(p, end, mdsmap_len, bad);
if (end < *p + mdsmap_len)
goto bad;
end = *p + mdsmap_len;
}
ceph_decode_need(p, end, 8*sizeof(u32) + sizeof(u64), bad);
m->m_epoch = ceph_decode_32(p);
m->m_client_epoch = ceph_decode_32(p);
m->m_last_failure = ceph_decode_32(p);
m->m_root = ceph_decode_32(p);
m->m_session_timeout = ceph_decode_32(p);
m->m_session_autoclose = ceph_decode_32(p);
m->m_max_file_size = ceph_decode_64(p);
m->m_max_mds = ceph_decode_32(p);
m->m_info = kcalloc(m->m_max_mds, sizeof(*m->m_info), GFP_NOFS);
if (m->m_info == NULL)
goto badmem;
n = ceph_decode_32(p);
for (i = 0; i < n; i++) {
u64 global_id;
u32 namelen;
s32 mds, inc, state;
u64 state_seq;
u8 info_v;
void *info_end = NULL;
struct ceph_entity_addr addr;
u32 num_export_targets;
void *pexport_targets = NULL;
struct ceph_timespec laggy_since;
struct ceph_mds_info *info;
ceph_decode_need(p, end, sizeof(u64) + 1, bad);
global_id = ceph_decode_64(p);
info_v= ceph_decode_8(p);
if (info_v >= 4) {
u32 info_len;
u8 info_cv;
ceph_decode_need(p, end, 1 + sizeof(u32), bad);
info_cv = ceph_decode_8(p);
info_len = ceph_decode_32(p);
info_end = *p + info_len;
if (info_end > end)
goto bad;
}
ceph_decode_need(p, end, sizeof(u64) + sizeof(u32), bad);
*p += sizeof(u64);
namelen = ceph_decode_32(p);
*p += namelen;
ceph_decode_need(p, end,
4*sizeof(u32) + sizeof(u64) +
sizeof(addr) + sizeof(struct ceph_timespec),
bad);
mds = ceph_decode_32(p);
inc = ceph_decode_32(p);
state = ceph_decode_32(p);
state_seq = ceph_decode_64(p);
ceph_decode_copy(p, &addr, sizeof(addr));
ceph_decode_addr(&addr);
ceph_decode_copy(p, &laggy_since, sizeof(laggy_since));
*p += sizeof(u32);
ceph_decode_32_safe(p, end, namelen, bad);
*p += namelen;
if (info_v >= 2) {
ceph_decode_32_safe(p, end, num_export_targets, bad);
pexport_targets = *p;
*p += num_export_targets * sizeof(u32);
} else {
num_export_targets = 0;
}
if (info_end && *p != info_end) {
if (*p > info_end)
goto bad;
*p = info_end;
}
dout("mdsmap_decode %d/%d %lld mds%d.%d %s %s\n",
i+1, n, global_id, mds, inc,
ceph_pr_addr(&addr.in_addr),
ceph_mds_state_name(state));
if (mds < 0 || mds >= m->m_max_mds || state <= 0)
continue;
info = &m->m_info[mds];
info->global_id = global_id;
info->state = state;
info->addr = addr;
info->laggy = (laggy_since.tv_sec != 0 ||
laggy_since.tv_nsec != 0);
info->num_export_targets = num_export_targets;
if (num_export_targets) {
info->export_targets = kcalloc(num_export_targets,
sizeof(u32), GFP_NOFS);
if (info->export_targets == NULL)
goto badmem;
for (j = 0; j < num_export_targets; j++)
info->export_targets[j] =
ceph_decode_32(&pexport_targets);
} else {
info->export_targets = NULL;
}
}
ceph_decode_32_safe(p, end, n, bad);
m->m_num_data_pg_pools = n;
m->m_data_pg_pools = kcalloc(n, sizeof(u64), GFP_NOFS);
if (!m->m_data_pg_pools)
goto badmem;
ceph_decode_need(p, end, sizeof(u64)*(n+1), bad);
for (i = 0; i < n; i++)
m->m_data_pg_pools[i] = ceph_decode_64(p);
m->m_cas_pg_pool = ceph_decode_64(p);
*p = end;
dout("mdsmap_decode success epoch %u\n", m->m_epoch);
return m;
badmem:
err = -ENOMEM;
bad:
pr_err("corrupt mdsmap\n");
print_hex_dump(KERN_DEBUG, "mdsmap: ",
DUMP_PREFIX_OFFSET, 16, 1,
start, end - start, true);
ceph_mdsmap_destroy(m);
return ERR_PTR(err);
}
void ceph_mdsmap_destroy(struct ceph_mdsmap *m)
{
int i;
for (i = 0; i < m->m_max_mds; i++)
kfree(m->m_info[i].export_targets);
kfree(m->m_info);
kfree(m->m_data_pg_pools);
kfree(m);
}
