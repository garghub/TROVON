int ft_queue_data_in(struct se_cmd *se_cmd)
{
struct ft_cmd *cmd = container_of(se_cmd, struct ft_cmd, se_cmd);
struct fc_frame *fp = NULL;
struct fc_exch *ep;
struct fc_lport *lport;
struct scatterlist *sg = NULL;
size_t remaining;
u32 f_ctl = FC_FC_EX_CTX | FC_FC_REL_OFF;
u32 mem_off = 0;
u32 fh_off = 0;
u32 frame_off = 0;
size_t frame_len = 0;
size_t mem_len = 0;
size_t tlen;
size_t off_in_page;
struct page *page = NULL;
int use_sg;
int error;
void *page_addr;
void *from;
void *to = NULL;
if (cmd->aborted)
return 0;
ep = fc_seq_exch(cmd->seq);
lport = ep->lp;
cmd->seq = lport->tt.seq_start_next(cmd->seq);
remaining = se_cmd->data_length;
BUG_ON(remaining && !se_cmd->t_data_sg);
if (remaining) {
sg = se_cmd->t_data_sg;
mem_len = sg->length;
mem_off = sg->offset;
page = sg_page(sg);
}
use_sg = !(remaining % 4);
while (remaining) {
if (!mem_len) {
sg = sg_next(sg);
mem_len = min((size_t)sg->length, remaining);
mem_off = sg->offset;
page = sg_page(sg);
}
if (!frame_len) {
frame_len = (lport->seq_offload) ? lport->lso_max :
cmd->sess->max_frame;
frame_len = min(frame_len, remaining);
fp = fc_frame_alloc(lport, use_sg ? 0 : frame_len);
if (!fp)
return -ENOMEM;
to = fc_frame_payload_get(fp, 0);
fh_off = frame_off;
frame_off += frame_len;
fr_max_payload(fp) = cmd->sess->max_frame;
}
tlen = min(mem_len, frame_len);
if (use_sg) {
off_in_page = mem_off;
BUG_ON(!page);
get_page(page);
skb_fill_page_desc(fp_skb(fp),
skb_shinfo(fp_skb(fp))->nr_frags,
page, off_in_page, tlen);
fr_len(fp) += tlen;
fp_skb(fp)->data_len += tlen;
fp_skb(fp)->truesize +=
PAGE_SIZE << compound_order(page);
} else {
BUG_ON(!page);
from = kmap_atomic(page + (mem_off >> PAGE_SHIFT));
page_addr = from;
from += mem_off & ~PAGE_MASK;
tlen = min(tlen, (size_t)(PAGE_SIZE -
(mem_off & ~PAGE_MASK)));
memcpy(to, from, tlen);
kunmap_atomic(page_addr);
to += tlen;
}
mem_off += tlen;
mem_len -= tlen;
frame_len -= tlen;
remaining -= tlen;
if (frame_len &&
(skb_shinfo(fp_skb(fp))->nr_frags < FC_FRAME_SG_LEN))
continue;
if (!remaining)
f_ctl |= FC_FC_END_SEQ;
fc_fill_fc_hdr(fp, FC_RCTL_DD_SOL_DATA, ep->did, ep->sid,
FC_TYPE_FCP, f_ctl, fh_off);
error = lport->tt.seq_send(lport, cmd->seq, fp);
if (error) {
pr_err_ratelimited("%s: Failed to send frame %p, "
"xid <0x%x>, remaining %zu, "
"lso_max <0x%x>\n",
__func__, fp, ep->xid,
remaining, lport->lso_max);
}
}
return ft_queue_status(se_cmd);
}
static void ft_execute_work(struct work_struct *work)
{
struct ft_cmd *cmd = container_of(work, struct ft_cmd, work);
target_execute_cmd(&cmd->se_cmd);
}
void ft_recv_write_data(struct ft_cmd *cmd, struct fc_frame *fp)
{
struct se_cmd *se_cmd = &cmd->se_cmd;
struct fc_seq *seq = cmd->seq;
struct fc_exch *ep;
struct fc_lport *lport;
struct fc_frame_header *fh;
struct scatterlist *sg = NULL;
u32 mem_off = 0;
u32 rel_off;
size_t frame_len;
size_t mem_len = 0;
size_t tlen;
struct page *page = NULL;
void *page_addr;
void *from;
void *to;
u32 f_ctl;
void *buf;
fh = fc_frame_header_get(fp);
if (!(ntoh24(fh->fh_f_ctl) & FC_FC_REL_OFF))
goto drop;
f_ctl = ntoh24(fh->fh_f_ctl);
ep = fc_seq_exch(seq);
lport = ep->lp;
if (cmd->was_ddp_setup) {
BUG_ON(!ep);
BUG_ON(!lport);
buf = fc_frame_payload_get(fp, 1);
if (buf)
pr_err("%s: xid 0x%x, f_ctl 0x%x, cmd->sg %p, "
"cmd->sg_cnt 0x%x. DDP was setup"
" hence not expected to receive frame with "
"payload, Frame will be dropped if"
"'Sequence Initiative' bit in f_ctl is"
"not set\n", __func__, ep->xid, f_ctl,
se_cmd->t_data_sg, se_cmd->t_data_nents);
ft_invl_hw_context(cmd);
if (f_ctl & FC_FC_SEQ_INIT)
goto last_frame;
else
goto drop;
}
rel_off = ntohl(fh->fh_parm_offset);
frame_len = fr_len(fp);
if (frame_len <= sizeof(*fh))
goto drop;
frame_len -= sizeof(*fh);
from = fc_frame_payload_get(fp, 0);
if (rel_off >= se_cmd->data_length)
goto drop;
if (frame_len + rel_off > se_cmd->data_length)
frame_len = se_cmd->data_length - rel_off;
BUG_ON(frame_len && !se_cmd->t_data_sg);
if (frame_len) {
sg = se_cmd->t_data_sg;
mem_len = sg->length;
mem_off = sg->offset;
page = sg_page(sg);
}
while (frame_len) {
if (!mem_len) {
sg = sg_next(sg);
mem_len = sg->length;
mem_off = sg->offset;
page = sg_page(sg);
}
if (rel_off >= mem_len) {
rel_off -= mem_len;
mem_len = 0;
continue;
}
mem_off += rel_off;
mem_len -= rel_off;
rel_off = 0;
tlen = min(mem_len, frame_len);
to = kmap_atomic(page + (mem_off >> PAGE_SHIFT));
page_addr = to;
to += mem_off & ~PAGE_MASK;
tlen = min(tlen, (size_t)(PAGE_SIZE -
(mem_off & ~PAGE_MASK)));
memcpy(to, from, tlen);
kunmap_atomic(page_addr);
from += tlen;
frame_len -= tlen;
mem_off += tlen;
mem_len -= tlen;
cmd->write_data_len += tlen;
}
last_frame:
if (cmd->write_data_len == se_cmd->data_length) {
INIT_WORK(&cmd->work, ft_execute_work);
queue_work(cmd->sess->tport->tpg->workqueue, &cmd->work);
}
drop:
fc_frame_free(fp);
}
void ft_invl_hw_context(struct ft_cmd *cmd)
{
struct fc_seq *seq;
struct fc_exch *ep = NULL;
struct fc_lport *lport = NULL;
BUG_ON(!cmd);
seq = cmd->seq;
if (cmd->was_ddp_setup && seq) {
ep = fc_seq_exch(seq);
if (ep) {
lport = ep->lp;
if (lport && (ep->xid <= lport->lro_xid))
cmd->write_data_len = lport->tt.ddp_done(lport,
ep->xid);
cmd->was_ddp_setup = 0;
}
}
}
