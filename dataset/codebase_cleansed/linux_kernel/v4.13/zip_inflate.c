static int prepare_inflate_zcmd(struct zip_operation *zip_ops,
struct zip_state *s, union zip_inst_s *zip_cmd)
{
union zip_zres_s *result_ptr = &s->result;
memset(zip_cmd, 0, sizeof(s->zip_cmd));
memset(result_ptr, 0, sizeof(s->result));
zip_cmd->s.hg = 0;
zip_cmd->s.ce = 0;
zip_cmd->s.ss = 0;
zip_cmd->s.sf = 1;
if (zip_ops->begin_file == 0)
zip_cmd->s.bf = 0;
else
zip_cmd->s.bf = 1;
zip_cmd->s.ef = 1;
zip_cmd->s.cc = zip_ops->ccode;
zip_cmd->s.adlercrc32 = zip_ops->csum;
zip_cmd->s.historylength = 0;
zip_cmd->s.ds = 0;
zip_cmd->s.out_ptr_addr.s.addr = __pa(zip_ops->output);
zip_cmd->s.out_ptr_ctl.s.length = zip_ops->output_len;
zip_cmd->s.totaloutputlength = zip_ops->output_len;
zip_dbg("Data Direct Input case ");
zip_cmd->s.dg = 0;
zip_cmd->s.inp_ptr_addr.s.addr = __pa((u8 *)zip_ops->input);
zip_cmd->s.inp_ptr_ctl.s.length = zip_ops->input_len;
zip_cmd->s.res_ptr_addr.s.addr = __pa(result_ptr);
result_ptr->s.compcode = 0;
return 0;
}
int zip_inflate(struct zip_operation *zip_ops, struct zip_state *s,
struct zip_device *zip_dev)
{
union zip_inst_s *zip_cmd = &s->zip_cmd;
union zip_zres_s *result_ptr = &s->result;
u32 queue;
prepare_inflate_zcmd(zip_ops, s, zip_cmd);
atomic64_add(zip_ops->input_len, &zip_dev->stats.decomp_in_bytes);
queue = zip_load_instr(zip_cmd, zip_dev);
atomic64_inc(&zip_dev->stats.decomp_req_submit);
while (!result_ptr->s.compcode)
continue;
atomic64_inc(&zip_dev->stats.decomp_req_complete);
zip_ops->compcode = result_ptr->s.compcode;
switch (zip_ops->compcode) {
case ZIP_CMD_NOTDONE:
zip_dbg("Zip Instruction not yet completed\n");
return ZIP_ERROR;
case ZIP_CMD_SUCCESS:
zip_dbg("Zip Instruction completed successfully\n");
break;
case ZIP_CMD_DYNAMIC_STOP:
zip_dbg(" Dynamic stop Initiated\n");
break;
default:
zip_dbg("Instruction failed. Code = %d\n", zip_ops->compcode);
atomic64_inc(&zip_dev->stats.decomp_bad_reqs);
zip_update_cmd_bufs(zip_dev, queue);
return ZIP_ERROR;
}
zip_update_cmd_bufs(zip_dev, queue);
if ((zip_ops->ccode == 3) && (zip_ops->flush == 4) &&
(zip_ops->compcode != ZIP_CMD_DYNAMIC_STOP))
result_ptr->s.ef = 1;
zip_ops->csum = result_ptr->s.adler32;
atomic64_add(result_ptr->s.totalbyteswritten,
&zip_dev->stats.decomp_out_bytes);
if (zip_ops->output_len < result_ptr->s.totalbyteswritten) {
zip_err("output_len (%d) < total bytes written (%d)\n",
zip_ops->output_len, result_ptr->s.totalbyteswritten);
zip_ops->output_len = 0;
} else {
zip_ops->output_len = result_ptr->s.totalbyteswritten;
}
zip_ops->bytes_read = result_ptr->s.totalbytesread;
zip_ops->bits_processed = result_ptr->s.totalbitsprocessed;
zip_ops->end_file = result_ptr->s.ef;
if (zip_ops->end_file) {
switch (zip_ops->format) {
case RAW_FORMAT:
zip_dbg("RAW Format: %d ", zip_ops->format);
zip_ops->csum = result_ptr->s.adler32;
break;
case ZLIB_FORMAT:
zip_dbg("ZLIB Format: %d ", zip_ops->format);
zip_ops->csum = result_ptr->s.adler32;
break;
case GZIP_FORMAT:
zip_dbg("GZIP Format: %d ", zip_ops->format);
zip_ops->csum = result_ptr->s.crc32;
break;
case LZS_FORMAT:
zip_dbg("LZS Format: %d ", zip_ops->format);
break;
default:
zip_err("Format error:%d\n", zip_ops->format);
}
}
return 0;
}
