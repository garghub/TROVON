static void encode_fallocate(struct xdr_stream *xdr,
struct nfs42_falloc_args *args)
{
encode_nfs4_stateid(xdr, &args->falloc_stateid);
encode_uint64(xdr, args->falloc_offset);
encode_uint64(xdr, args->falloc_length);
}
static void encode_allocate(struct xdr_stream *xdr,
struct nfs42_falloc_args *args,
struct compound_hdr *hdr)
{
encode_op_hdr(xdr, OP_ALLOCATE, decode_allocate_maxsz, hdr);
encode_fallocate(xdr, args);
}
static void encode_deallocate(struct xdr_stream *xdr,
struct nfs42_falloc_args *args,
struct compound_hdr *hdr)
{
encode_op_hdr(xdr, OP_DEALLOCATE, decode_deallocate_maxsz, hdr);
encode_fallocate(xdr, args);
}
static void encode_seek(struct xdr_stream *xdr,
struct nfs42_seek_args *args,
struct compound_hdr *hdr)
{
encode_op_hdr(xdr, OP_SEEK, decode_seek_maxsz, hdr);
encode_nfs4_stateid(xdr, &args->sa_stateid);
encode_uint64(xdr, args->sa_offset);
encode_uint32(xdr, args->sa_what);
}
static void encode_layoutstats(struct xdr_stream *xdr,
struct nfs42_layoutstat_args *args,
struct nfs42_layoutstat_devinfo *devinfo,
struct compound_hdr *hdr)
{
__be32 *p;
encode_op_hdr(xdr, OP_LAYOUTSTATS, decode_layoutstats_maxsz, hdr);
p = reserve_space(xdr, 8 + 8);
p = xdr_encode_hyper(p, devinfo->offset);
p = xdr_encode_hyper(p, devinfo->length);
encode_nfs4_stateid(xdr, &args->stateid);
p = reserve_space(xdr, 4*8 + NFS4_DEVICEID4_SIZE + 4);
p = xdr_encode_hyper(p, devinfo->read_count);
p = xdr_encode_hyper(p, devinfo->read_bytes);
p = xdr_encode_hyper(p, devinfo->write_count);
p = xdr_encode_hyper(p, devinfo->write_bytes);
p = xdr_encode_opaque_fixed(p, devinfo->dev_id.data,
NFS4_DEVICEID4_SIZE);
*p++ = cpu_to_be32(devinfo->layout_type);
if (devinfo->layoutstats_encode != NULL)
devinfo->layoutstats_encode(xdr, args, devinfo);
else
encode_uint32(xdr, 0);
}
static void nfs4_xdr_enc_allocate(struct rpc_rqst *req,
struct xdr_stream *xdr,
struct nfs42_falloc_args *args)
{
struct compound_hdr hdr = {
.minorversion = nfs4_xdr_minorversion(&args->seq_args),
};
encode_compound_hdr(xdr, req, &hdr);
encode_sequence(xdr, &args->seq_args, &hdr);
encode_putfh(xdr, args->falloc_fh, &hdr);
encode_allocate(xdr, args, &hdr);
encode_getfattr(xdr, args->falloc_bitmask, &hdr);
encode_nops(&hdr);
}
static void nfs4_xdr_enc_deallocate(struct rpc_rqst *req,
struct xdr_stream *xdr,
struct nfs42_falloc_args *args)
{
struct compound_hdr hdr = {
.minorversion = nfs4_xdr_minorversion(&args->seq_args),
};
encode_compound_hdr(xdr, req, &hdr);
encode_sequence(xdr, &args->seq_args, &hdr);
encode_putfh(xdr, args->falloc_fh, &hdr);
encode_deallocate(xdr, args, &hdr);
encode_getfattr(xdr, args->falloc_bitmask, &hdr);
encode_nops(&hdr);
}
static void nfs4_xdr_enc_seek(struct rpc_rqst *req,
struct xdr_stream *xdr,
struct nfs42_seek_args *args)
{
struct compound_hdr hdr = {
.minorversion = nfs4_xdr_minorversion(&args->seq_args),
};
encode_compound_hdr(xdr, req, &hdr);
encode_sequence(xdr, &args->seq_args, &hdr);
encode_putfh(xdr, args->sa_fh, &hdr);
encode_seek(xdr, args, &hdr);
encode_nops(&hdr);
}
static void nfs4_xdr_enc_layoutstats(struct rpc_rqst *req,
struct xdr_stream *xdr,
struct nfs42_layoutstat_args *args)
{
int i;
struct compound_hdr hdr = {
.minorversion = nfs4_xdr_minorversion(&args->seq_args),
};
encode_compound_hdr(xdr, req, &hdr);
encode_sequence(xdr, &args->seq_args, &hdr);
encode_putfh(xdr, args->fh, &hdr);
WARN_ON(args->num_dev > PNFS_LAYOUTSTATS_MAXDEV);
for (i = 0; i < args->num_dev; i++)
encode_layoutstats(xdr, args, &args->devinfo[i], &hdr);
encode_nops(&hdr);
}
static int decode_allocate(struct xdr_stream *xdr, struct nfs42_falloc_res *res)
{
return decode_op_hdr(xdr, OP_ALLOCATE);
}
static int decode_deallocate(struct xdr_stream *xdr, struct nfs42_falloc_res *res)
{
return decode_op_hdr(xdr, OP_DEALLOCATE);
}
static int decode_seek(struct xdr_stream *xdr, struct nfs42_seek_res *res)
{
int status;
__be32 *p;
status = decode_op_hdr(xdr, OP_SEEK);
if (status)
return status;
p = xdr_inline_decode(xdr, 4 + 8);
if (unlikely(!p))
goto out_overflow;
res->sr_eof = be32_to_cpup(p++);
p = xdr_decode_hyper(p, &res->sr_offset);
return 0;
out_overflow:
print_overflow_msg(__func__, xdr);
return -EIO;
}
static int decode_layoutstats(struct xdr_stream *xdr)
{
return decode_op_hdr(xdr, OP_LAYOUTSTATS);
}
static int nfs4_xdr_dec_allocate(struct rpc_rqst *rqstp,
struct xdr_stream *xdr,
struct nfs42_falloc_res *res)
{
struct compound_hdr hdr;
int status;
status = decode_compound_hdr(xdr, &hdr);
if (status)
goto out;
status = decode_sequence(xdr, &res->seq_res, rqstp);
if (status)
goto out;
status = decode_putfh(xdr);
if (status)
goto out;
status = decode_allocate(xdr, res);
if (status)
goto out;
decode_getfattr(xdr, res->falloc_fattr, res->falloc_server);
out:
return status;
}
static int nfs4_xdr_dec_deallocate(struct rpc_rqst *rqstp,
struct xdr_stream *xdr,
struct nfs42_falloc_res *res)
{
struct compound_hdr hdr;
int status;
status = decode_compound_hdr(xdr, &hdr);
if (status)
goto out;
status = decode_sequence(xdr, &res->seq_res, rqstp);
if (status)
goto out;
status = decode_putfh(xdr);
if (status)
goto out;
status = decode_deallocate(xdr, res);
if (status)
goto out;
decode_getfattr(xdr, res->falloc_fattr, res->falloc_server);
out:
return status;
}
static int nfs4_xdr_dec_seek(struct rpc_rqst *rqstp,
struct xdr_stream *xdr,
struct nfs42_seek_res *res)
{
struct compound_hdr hdr;
int status;
status = decode_compound_hdr(xdr, &hdr);
if (status)
goto out;
status = decode_sequence(xdr, &res->seq_res, rqstp);
if (status)
goto out;
status = decode_putfh(xdr);
if (status)
goto out;
status = decode_seek(xdr, res);
out:
return status;
}
static int nfs4_xdr_dec_layoutstats(struct rpc_rqst *rqstp,
struct xdr_stream *xdr,
struct nfs42_layoutstat_res *res)
{
struct compound_hdr hdr;
int status, i;
status = decode_compound_hdr(xdr, &hdr);
if (status)
goto out;
status = decode_sequence(xdr, &res->seq_res, rqstp);
if (status)
goto out;
status = decode_putfh(xdr);
if (status)
goto out;
WARN_ON(res->num_dev > PNFS_LAYOUTSTATS_MAXDEV);
for (i = 0; i < res->num_dev; i++) {
status = decode_layoutstats(xdr);
if (status)
goto out;
}
out:
res->rpc_status = status;
return status;
}
