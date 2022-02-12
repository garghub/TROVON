__be32
nfsd4_ff_encode_layoutget(struct xdr_stream *xdr,
struct nfsd4_layoutget *lgp)
{
struct pnfs_ff_layout *fl = lgp->lg_content;
int len, mirror_len, ds_len, fh_len;
__be32 *p;
struct ff_idmap uid;
struct ff_idmap gid;
fh_len = 4 + fl->fh.size;
uid.len = sprintf(uid.buf, "%u", from_kuid(&init_user_ns, fl->uid));
gid.len = sprintf(gid.buf, "%u", from_kgid(&init_user_ns, fl->gid));
ds_len = 20 + sizeof(stateid_opaque_t) + 4 + fh_len +
8 + uid.len + 8 + gid.len;
mirror_len = 4 + ds_len;
len = 20 + mirror_len;
p = xdr_reserve_space(xdr, sizeof(__be32) + len);
if (!p)
return nfserr_toosmall;
*p++ = cpu_to_be32(len);
p = xdr_encode_hyper(p, 0);
*p++ = cpu_to_be32(1);
*p++ = cpu_to_be32(1);
p = xdr_encode_opaque_fixed(p, &fl->deviceid,
sizeof(struct nfsd4_deviceid));
*p++ = cpu_to_be32(1);
*p++ = cpu_to_be32(fl->stateid.si_generation);
p = xdr_encode_opaque_fixed(p, &fl->stateid.si_opaque,
sizeof(stateid_opaque_t));
*p++ = cpu_to_be32(1);
p = xdr_encode_opaque(p, fl->fh.data, fl->fh.size);
p = xdr_encode_opaque(p, uid.buf, uid.len);
p = xdr_encode_opaque(p, gid.buf, gid.len);
*p++ = cpu_to_be32(fl->flags);
*p++ = cpu_to_be32(0);
return 0;
}
__be32
nfsd4_ff_encode_getdeviceinfo(struct xdr_stream *xdr,
struct nfsd4_getdeviceinfo *gdp)
{
struct pnfs_ff_device_addr *da = gdp->gd_device;
int len;
int ver_len;
int addr_len;
__be32 *p;
addr_len = 16 + da->netaddr.netid_len + da->netaddr.addr_len;
ver_len = 20;
len = 4 + ver_len + 4 + addr_len;
p = xdr_reserve_space(xdr, len + sizeof(__be32));
if (!p)
return nfserr_resource;
*p++ = cpu_to_be32(len);
*p++ = cpu_to_be32(1);
p = xdr_encode_opaque(p, da->netaddr.netid, da->netaddr.netid_len);
p = xdr_encode_opaque(p, da->netaddr.addr, da->netaddr.addr_len);
*p++ = cpu_to_be32(1);
*p++ = cpu_to_be32(da->version);
*p++ = cpu_to_be32(da->minor_version);
*p++ = cpu_to_be32(da->rsize);
*p++ = cpu_to_be32(da->wsize);
*p++ = cpu_to_be32(da->tightly_coupled);
return 0;
}
