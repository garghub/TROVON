int ft_queue_data_in(struct se_cmd *se_cmd)
{
struct ft_cmd *cmd = container_of(se_cmd, struct ft_cmd, se_cmd);
struct se_transport_task *task;
struct fc_frame *fp = NULL;
struct fc_exch *ep;
struct fc_lport *lport;
struct se_mem *mem;
size_t remaining;
u32 f_ctl = FC_FC_EX_CTX | FC_FC_REL_OFF;
u32 mem_off;
u32 fh_off = 0;
u32 frame_off = 0;
size_t frame_len = 0;
size_t mem_len;
size_t tlen;
size_t off_in_page;
struct page *page;
int use_sg;
int error;
void *page_addr;
void *from;
void *to = NULL;
ep = fc_seq_exch(cmd->seq);
lport = ep->lp;
cmd->seq = lport->tt.seq_start_next(cmd->seq);
task = T_TASK(se_cmd);
BUG_ON(!task);
remaining = se_cmd->data_length;
if (task->t_tasks_se_num) {
mem = list_first_entry(task->t_mem_list,
struct se_mem, se_list);
mem_len = mem->se_len;
mem_off = mem->se_off;
page = mem->se_page;
} else {
mem = NULL;
mem_len = remaining;
mem_off = 0;
page = NULL;
}
use_sg = !(remaining % 4);
while (remaining) {
if (!mem_len) {
BUG_ON(!mem);
mem = list_entry(mem->se_list.next,
struct se_mem, se_list);
mem_len = min((size_t)mem->se_len, remaining);
mem_off = mem->se_off;
page = mem->se_page;
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
if (!mem) {
BUG_ON(!task->t_task_buf);
page_addr = task->t_task_buf + mem_off;
off_in_page = offset_in_page(page_addr);
page = virt_to_page(page_addr);
tlen = min(tlen, PAGE_SIZE - off_in_page);
} else
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
} else if (mem) {
BUG_ON(!page);
from = kmap_atomic(page + (mem_off >> PAGE_SHIFT),
KM_SOFTIRQ0);
page_addr = from;
from += mem_off & ~PAGE_MASK;
tlen = min(tlen, (size_t)(PAGE_SIZE -
(mem_off & ~PAGE_MASK)));
memcpy(to, from, tlen);
kunmap_atomic(page_addr, KM_SOFTIRQ0);
to += tlen;
} else {
from = task->t_task_buf + mem_off;
memcpy(to, from, tlen);
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
if (printk_ratelimit())
printk(KERN_ERR "%s: Failed to send frame %p, "
"xid <0x%x>, remaining %zu, "
"lso_max <0x%x>\n",
__func__, fp, ep->xid,
remaining, lport->lso_max);
}
}
return ft_queue_status(se_cmd);
}
void ft_recv_write_data(struct ft_cmd *cmd, struct fc_frame *fp)
{
struct se_cmd *se_cmd = &cmd->se_cmd;
struct fc_seq *seq = cmd->seq;
struct fc_exch *ep;
struct fc_lport *lport;
struct se_transport_task *task;
struct fc_frame_header *fh;
struct se_mem *mem;
u32 mem_off;
u32 rel_off;
size_t frame_len;
size_t mem_len;
size_t tlen;
struct page *page;
void *page_addr;
void *from;
void *to;
u32 f_ctl;
void *buf;
task = T_TASK(se_cmd);
BUG_ON(!task);
fh = fc_frame_header_get(fp);
if (!(ntoh24(fh->fh_f_ctl) & FC_FC_REL_OFF))
goto drop;
buf = fc_frame_payload_get(fp, 1);
if (cmd->was_ddp_setup && buf) {
printk(KERN_INFO "%s: When DDP was setup, not expected to"
"receive frame with payload, Payload shall be"
"copied directly to buffer instead of coming "
"via. legacy receive queues\n", __func__);
BUG_ON(buf);
}
ep = fc_seq_exch(seq);
if (cmd->was_ddp_setup) {
BUG_ON(!ep);
lport = ep->lp;
BUG_ON(!lport);
}
if (cmd->was_ddp_setup && ep->xid != FC_XID_UNKNOWN) {
f_ctl = ntoh24(fh->fh_f_ctl);
if (f_ctl & FC_FC_SEQ_INIT) {
cmd->write_data_len = lport->tt.ddp_done(lport,
ep->xid);
goto last_frame;
} else {
printk(KERN_ERR "%s: Received frame with TSI bit not"
" being SET, dropping the frame, "
"cmd->sg <%p>, cmd->sg_cnt <0x%x>\n",
__func__, cmd->sg, cmd->sg_cnt);
cmd->write_data_len = lport->tt.ddp_done(lport,
ep->xid);
lport->tt.seq_exch_abort(cmd->seq, 0);
goto drop;
}
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
if (task->t_tasks_se_num) {
mem = list_first_entry(task->t_mem_list,
struct se_mem, se_list);
mem_len = mem->se_len;
mem_off = mem->se_off;
page = mem->se_page;
} else {
mem = NULL;
page = NULL;
mem_off = 0;
mem_len = frame_len;
}
while (frame_len) {
if (!mem_len) {
BUG_ON(!mem);
mem = list_entry(mem->se_list.next,
struct se_mem, se_list);
mem_len = mem->se_len;
mem_off = mem->se_off;
page = mem->se_page;
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
if (mem) {
to = kmap_atomic(page + (mem_off >> PAGE_SHIFT),
KM_SOFTIRQ0);
page_addr = to;
to += mem_off & ~PAGE_MASK;
tlen = min(tlen, (size_t)(PAGE_SIZE -
(mem_off & ~PAGE_MASK)));
memcpy(to, from, tlen);
kunmap_atomic(page_addr, KM_SOFTIRQ0);
} else {
to = task->t_task_buf + mem_off;
memcpy(to, from, tlen);
}
from += tlen;
frame_len -= tlen;
mem_off += tlen;
mem_len -= tlen;
cmd->write_data_len += tlen;
}
last_frame:
if (cmd->write_data_len == se_cmd->data_length)
transport_generic_handle_data(se_cmd);
drop:
fc_frame_free(fp);
}
