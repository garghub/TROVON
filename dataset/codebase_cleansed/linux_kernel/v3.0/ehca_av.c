int ehca_calc_ipd(struct ehca_shca *shca, int port,
enum ib_rate path_rate, u32 *ipd)
{
int path = ib_rate_to_mult(path_rate);
int link, ret;
struct ib_port_attr pa;
if (path_rate == IB_RATE_PORT_CURRENT) {
*ipd = 0;
return 0;
}
if (unlikely(path < 0)) {
ehca_err(&shca->ib_device, "Invalid static rate! path_rate=%x",
path_rate);
return -EINVAL;
}
ret = ehca_query_port(&shca->ib_device, port, &pa);
if (unlikely(ret < 0)) {
ehca_err(&shca->ib_device, "Failed to query port ret=%i", ret);
return ret;
}
link = ib_width_enum_to_int(pa.active_width) * pa.active_speed;
if (path >= link)
*ipd = 0;
else
*ipd = ((link + (path >> 1)) / path) - 1;
return 0;
}
struct ib_ah *ehca_create_ah(struct ib_pd *pd, struct ib_ah_attr *ah_attr)
{
int ret;
struct ehca_av *av;
struct ehca_shca *shca = container_of(pd->device, struct ehca_shca,
ib_device);
av = kmem_cache_alloc(av_cache, GFP_KERNEL);
if (!av) {
ehca_err(pd->device, "Out of memory pd=%p ah_attr=%p",
pd, ah_attr);
return ERR_PTR(-ENOMEM);
}
av->av.sl = ah_attr->sl;
av->av.dlid = ah_attr->dlid;
av->av.slid_path_bits = ah_attr->src_path_bits;
if (ehca_static_rate < 0) {
u32 ipd;
if (ehca_calc_ipd(shca, ah_attr->port_num,
ah_attr->static_rate, &ipd)) {
ret = -EINVAL;
goto create_ah_exit1;
}
av->av.ipd = ipd;
} else
av->av.ipd = ehca_static_rate;
av->av.lnh = ah_attr->ah_flags;
av->av.grh.word_0 = EHCA_BMASK_SET(GRH_IPVERSION_MASK, 6);
av->av.grh.word_0 |= EHCA_BMASK_SET(GRH_TCLASS_MASK,
ah_attr->grh.traffic_class);
av->av.grh.word_0 |= EHCA_BMASK_SET(GRH_FLOWLABEL_MASK,
ah_attr->grh.flow_label);
av->av.grh.word_0 |= EHCA_BMASK_SET(GRH_HOPLIMIT_MASK,
ah_attr->grh.hop_limit);
av->av.grh.word_0 |= EHCA_BMASK_SET(GRH_NEXTHEADER_MASK, 0x1B);
if (ah_attr->ah_flags & IB_AH_GRH) {
int rc;
struct ib_port_attr port_attr;
union ib_gid gid;
memset(&port_attr, 0, sizeof(port_attr));
rc = ehca_query_port(pd->device, ah_attr->port_num,
&port_attr);
if (rc) {
ret = -EINVAL;
ehca_err(pd->device, "Invalid port number "
"ehca_query_port() returned %x "
"pd=%p ah_attr=%p", rc, pd, ah_attr);
goto create_ah_exit1;
}
memset(&gid, 0, sizeof(gid));
rc = ehca_query_gid(pd->device,
ah_attr->port_num,
ah_attr->grh.sgid_index, &gid);
if (rc) {
ret = -EINVAL;
ehca_err(pd->device, "Failed to retrieve sgid "
"ehca_query_gid() returned %x "
"pd=%p ah_attr=%p", rc, pd, ah_attr);
goto create_ah_exit1;
}
memcpy(&av->av.grh.word_1, &gid, sizeof(gid));
}
av->av.pmtu = shca->max_mtu;
memcpy(&av->av.grh.word_3, &ah_attr->grh.dgid,
sizeof(ah_attr->grh.dgid));
return &av->ib_ah;
create_ah_exit1:
kmem_cache_free(av_cache, av);
return ERR_PTR(ret);
}
int ehca_modify_ah(struct ib_ah *ah, struct ib_ah_attr *ah_attr)
{
struct ehca_av *av;
struct ehca_ud_av new_ehca_av;
struct ehca_shca *shca = container_of(ah->pd->device, struct ehca_shca,
ib_device);
memset(&new_ehca_av, 0, sizeof(new_ehca_av));
new_ehca_av.sl = ah_attr->sl;
new_ehca_av.dlid = ah_attr->dlid;
new_ehca_av.slid_path_bits = ah_attr->src_path_bits;
new_ehca_av.ipd = ah_attr->static_rate;
new_ehca_av.lnh = EHCA_BMASK_SET(GRH_FLAG_MASK,
(ah_attr->ah_flags & IB_AH_GRH) > 0);
new_ehca_av.grh.word_0 = EHCA_BMASK_SET(GRH_TCLASS_MASK,
ah_attr->grh.traffic_class);
new_ehca_av.grh.word_0 |= EHCA_BMASK_SET(GRH_FLOWLABEL_MASK,
ah_attr->grh.flow_label);
new_ehca_av.grh.word_0 |= EHCA_BMASK_SET(GRH_HOPLIMIT_MASK,
ah_attr->grh.hop_limit);
new_ehca_av.grh.word_0 |= EHCA_BMASK_SET(GRH_NEXTHEADER_MASK, 0x1b);
if (ah_attr->ah_flags & IB_AH_GRH) {
int rc;
struct ib_port_attr port_attr;
union ib_gid gid;
memset(&port_attr, 0, sizeof(port_attr));
rc = ehca_query_port(ah->device, ah_attr->port_num,
&port_attr);
if (rc) {
ehca_err(ah->device, "Invalid port number "
"ehca_query_port() returned %x "
"ah=%p ah_attr=%p port_num=%x",
rc, ah, ah_attr, ah_attr->port_num);
return -EINVAL;
}
memset(&gid, 0, sizeof(gid));
rc = ehca_query_gid(ah->device,
ah_attr->port_num,
ah_attr->grh.sgid_index, &gid);
if (rc) {
ehca_err(ah->device, "Failed to retrieve sgid "
"ehca_query_gid() returned %x "
"ah=%p ah_attr=%p port_num=%x "
"sgid_index=%x",
rc, ah, ah_attr, ah_attr->port_num,
ah_attr->grh.sgid_index);
return -EINVAL;
}
memcpy(&new_ehca_av.grh.word_1, &gid, sizeof(gid));
}
new_ehca_av.pmtu = shca->max_mtu;
memcpy(&new_ehca_av.grh.word_3, &ah_attr->grh.dgid,
sizeof(ah_attr->grh.dgid));
av = container_of(ah, struct ehca_av, ib_ah);
av->av = new_ehca_av;
return 0;
}
int ehca_query_ah(struct ib_ah *ah, struct ib_ah_attr *ah_attr)
{
struct ehca_av *av = container_of(ah, struct ehca_av, ib_ah);
memcpy(&ah_attr->grh.dgid, &av->av.grh.word_3,
sizeof(ah_attr->grh.dgid));
ah_attr->sl = av->av.sl;
ah_attr->dlid = av->av.dlid;
ah_attr->src_path_bits = av->av.slid_path_bits;
ah_attr->static_rate = av->av.ipd;
ah_attr->ah_flags = EHCA_BMASK_GET(GRH_FLAG_MASK, av->av.lnh);
ah_attr->grh.traffic_class = EHCA_BMASK_GET(GRH_TCLASS_MASK,
av->av.grh.word_0);
ah_attr->grh.hop_limit = EHCA_BMASK_GET(GRH_HOPLIMIT_MASK,
av->av.grh.word_0);
ah_attr->grh.flow_label = EHCA_BMASK_GET(GRH_FLOWLABEL_MASK,
av->av.grh.word_0);
return 0;
}
int ehca_destroy_ah(struct ib_ah *ah)
{
kmem_cache_free(av_cache, container_of(ah, struct ehca_av, ib_ah));
return 0;
}
int ehca_init_av_cache(void)
{
av_cache = kmem_cache_create("ehca_cache_av",
sizeof(struct ehca_av), 0,
SLAB_HWCACHE_ALIGN,
NULL);
if (!av_cache)
return -ENOMEM;
return 0;
}
void ehca_cleanup_av_cache(void)
{
if (av_cache)
kmem_cache_destroy(av_cache);
}
