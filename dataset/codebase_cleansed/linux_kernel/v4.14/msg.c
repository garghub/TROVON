static unsigned int align(unsigned int i)
{
return (i + 3) & ~3u;
}
struct sk_buff *tipc_buf_acquire(u32 size, gfp_t gfp)
{
struct sk_buff *skb;
unsigned int buf_size = (BUF_HEADROOM + size + 3) & ~3u;
skb = alloc_skb_fclone(buf_size, gfp);
if (skb) {
skb_reserve(skb, BUF_HEADROOM);
skb_put(skb, size);
skb->next = NULL;
}
return skb;
}
void tipc_msg_init(u32 own_node, struct tipc_msg *m, u32 user, u32 type,
u32 hsize, u32 dnode)
{
memset(m, 0, hsize);
msg_set_version(m);
msg_set_user(m, user);
msg_set_hdr_sz(m, hsize);
msg_set_size(m, hsize);
msg_set_prevnode(m, own_node);
msg_set_type(m, type);
if (hsize > SHORT_H_SIZE) {
msg_set_orignode(m, own_node);
msg_set_destnode(m, dnode);
}
}
struct sk_buff *tipc_msg_create(uint user, uint type,
uint hdr_sz, uint data_sz, u32 dnode,
u32 onode, u32 dport, u32 oport, int errcode)
{
struct tipc_msg *msg;
struct sk_buff *buf;
buf = tipc_buf_acquire(hdr_sz + data_sz, GFP_ATOMIC);
if (unlikely(!buf))
return NULL;
msg = buf_msg(buf);
tipc_msg_init(onode, msg, user, type, hdr_sz, dnode);
msg_set_size(msg, hdr_sz + data_sz);
msg_set_origport(msg, oport);
msg_set_destport(msg, dport);
msg_set_errcode(msg, errcode);
if (hdr_sz > SHORT_H_SIZE) {
msg_set_orignode(msg, onode);
msg_set_destnode(msg, dnode);
}
return buf;
}
int tipc_buf_append(struct sk_buff **headbuf, struct sk_buff **buf)
{
struct sk_buff *head = *headbuf;
struct sk_buff *frag = *buf;
struct sk_buff *tail = NULL;
struct tipc_msg *msg;
u32 fragid;
int delta;
bool headstolen;
if (!frag)
goto err;
msg = buf_msg(frag);
fragid = msg_type(msg);
frag->next = NULL;
skb_pull(frag, msg_hdr_sz(msg));
if (fragid == FIRST_FRAGMENT) {
if (unlikely(head))
goto err;
if (unlikely(skb_unclone(frag, GFP_ATOMIC)))
goto err;
head = *headbuf = frag;
*buf = NULL;
TIPC_SKB_CB(head)->tail = NULL;
if (skb_is_nonlinear(head)) {
skb_walk_frags(head, tail) {
TIPC_SKB_CB(head)->tail = tail;
}
} else {
skb_frag_list_init(head);
}
return 0;
}
if (!head)
goto err;
if (skb_try_coalesce(head, frag, &headstolen, &delta)) {
kfree_skb_partial(frag, headstolen);
} else {
tail = TIPC_SKB_CB(head)->tail;
if (!skb_has_frag_list(head))
skb_shinfo(head)->frag_list = frag;
else
tail->next = frag;
head->truesize += frag->truesize;
head->data_len += frag->len;
head->len += frag->len;
TIPC_SKB_CB(head)->tail = frag;
}
if (fragid == LAST_FRAGMENT) {
TIPC_SKB_CB(head)->validated = false;
if (unlikely(!tipc_msg_validate(head)))
goto err;
*buf = head;
TIPC_SKB_CB(head)->tail = NULL;
*headbuf = NULL;
return 1;
}
*buf = NULL;
return 0;
err:
kfree_skb(*buf);
kfree_skb(*headbuf);
*buf = *headbuf = NULL;
return 0;
}
bool tipc_msg_validate(struct sk_buff *skb)
{
struct tipc_msg *msg;
int msz, hsz;
if (unlikely(TIPC_SKB_CB(skb)->validated))
return true;
if (unlikely(!pskb_may_pull(skb, MIN_H_SIZE)))
return false;
hsz = msg_hdr_sz(buf_msg(skb));
if (unlikely(hsz < MIN_H_SIZE) || (hsz > MAX_H_SIZE))
return false;
if (unlikely(!pskb_may_pull(skb, hsz)))
return false;
msg = buf_msg(skb);
if (unlikely(msg_version(msg) != TIPC_VERSION))
return false;
msz = msg_size(msg);
if (unlikely(msz < hsz))
return false;
if (unlikely((msz - hsz) > TIPC_MAX_USER_MSG_SIZE))
return false;
if (unlikely(skb->len < msz))
return false;
TIPC_SKB_CB(skb)->validated = true;
return true;
}
int tipc_msg_build(struct tipc_msg *mhdr, struct msghdr *m,
int offset, int dsz, int pktmax, struct sk_buff_head *list)
{
int mhsz = msg_hdr_sz(mhdr);
int msz = mhsz + dsz;
int pktno = 1;
int pktsz;
int pktrem = pktmax;
int drem = dsz;
struct tipc_msg pkthdr;
struct sk_buff *skb;
char *pktpos;
int rc;
msg_set_size(mhdr, msz);
if (likely(msz <= pktmax)) {
skb = tipc_buf_acquire(msz, GFP_KERNEL);
if (unlikely(!skb))
return -ENOMEM;
skb_orphan(skb);
__skb_queue_tail(list, skb);
skb_copy_to_linear_data(skb, mhdr, mhsz);
pktpos = skb->data + mhsz;
if (copy_from_iter_full(pktpos, dsz, &m->msg_iter))
return dsz;
rc = -EFAULT;
goto error;
}
tipc_msg_init(msg_prevnode(mhdr), &pkthdr, MSG_FRAGMENTER,
FIRST_FRAGMENT, INT_H_SIZE, msg_destnode(mhdr));
msg_set_size(&pkthdr, pktmax);
msg_set_fragm_no(&pkthdr, pktno);
msg_set_importance(&pkthdr, msg_importance(mhdr));
skb = tipc_buf_acquire(pktmax, GFP_KERNEL);
if (!skb)
return -ENOMEM;
skb_orphan(skb);
__skb_queue_tail(list, skb);
pktpos = skb->data;
skb_copy_to_linear_data(skb, &pkthdr, INT_H_SIZE);
pktpos += INT_H_SIZE;
pktrem -= INT_H_SIZE;
skb_copy_to_linear_data_offset(skb, INT_H_SIZE, mhdr, mhsz);
pktpos += mhsz;
pktrem -= mhsz;
do {
if (drem < pktrem)
pktrem = drem;
if (!copy_from_iter_full(pktpos, pktrem, &m->msg_iter)) {
rc = -EFAULT;
goto error;
}
drem -= pktrem;
if (!drem)
break;
if (drem < (pktmax - INT_H_SIZE))
pktsz = drem + INT_H_SIZE;
else
pktsz = pktmax;
skb = tipc_buf_acquire(pktsz, GFP_KERNEL);
if (!skb) {
rc = -ENOMEM;
goto error;
}
skb_orphan(skb);
__skb_queue_tail(list, skb);
msg_set_type(&pkthdr, FRAGMENT);
msg_set_size(&pkthdr, pktsz);
msg_set_fragm_no(&pkthdr, ++pktno);
skb_copy_to_linear_data(skb, &pkthdr, INT_H_SIZE);
pktpos = skb->data + INT_H_SIZE;
pktrem = pktsz - INT_H_SIZE;
} while (1);
msg_set_type(buf_msg(skb), LAST_FRAGMENT);
return dsz;
error:
__skb_queue_purge(list);
__skb_queue_head_init(list);
return rc;
}
bool tipc_msg_bundle(struct sk_buff *skb, struct tipc_msg *msg, u32 mtu)
{
struct tipc_msg *bmsg;
unsigned int bsz;
unsigned int msz = msg_size(msg);
u32 start, pad;
u32 max = mtu - INT_H_SIZE;
if (likely(msg_user(msg) == MSG_FRAGMENTER))
return false;
if (!skb)
return false;
bmsg = buf_msg(skb);
bsz = msg_size(bmsg);
start = align(bsz);
pad = start - bsz;
if (unlikely(msg_user(msg) == TUNNEL_PROTOCOL))
return false;
if (unlikely(msg_user(msg) == BCAST_PROTOCOL))
return false;
if (unlikely(msg_user(bmsg) != MSG_BUNDLER))
return false;
if (unlikely(skb_tailroom(skb) < (pad + msz)))
return false;
if (unlikely(max < (start + msz)))
return false;
if ((msg_importance(msg) < TIPC_SYSTEM_IMPORTANCE) &&
(msg_importance(bmsg) == TIPC_SYSTEM_IMPORTANCE))
return false;
skb_put(skb, pad + msz);
skb_copy_to_linear_data_offset(skb, start, msg, msz);
msg_set_size(bmsg, start + msz);
msg_set_msgcnt(bmsg, msg_msgcnt(bmsg) + 1);
return true;
}
bool tipc_msg_extract(struct sk_buff *skb, struct sk_buff **iskb, int *pos)
{
struct tipc_msg *msg;
int imsz, offset;
*iskb = NULL;
if (unlikely(skb_linearize(skb)))
goto none;
msg = buf_msg(skb);
offset = msg_hdr_sz(msg) + *pos;
if (unlikely(offset > (msg_size(msg) - MIN_H_SIZE)))
goto none;
*iskb = skb_clone(skb, GFP_ATOMIC);
if (unlikely(!*iskb))
goto none;
skb_pull(*iskb, offset);
imsz = msg_size(buf_msg(*iskb));
skb_trim(*iskb, imsz);
if (unlikely(!tipc_msg_validate(*iskb)))
goto none;
*pos += align(imsz);
return true;
none:
kfree_skb(skb);
kfree_skb(*iskb);
*iskb = NULL;
return false;
}
bool tipc_msg_make_bundle(struct sk_buff **skb, struct tipc_msg *msg,
u32 mtu, u32 dnode)
{
struct sk_buff *_skb;
struct tipc_msg *bmsg;
u32 msz = msg_size(msg);
u32 max = mtu - INT_H_SIZE;
if (msg_user(msg) == MSG_FRAGMENTER)
return false;
if (msg_user(msg) == TUNNEL_PROTOCOL)
return false;
if (msg_user(msg) == BCAST_PROTOCOL)
return false;
if (msz > (max / 2))
return false;
_skb = tipc_buf_acquire(max, GFP_ATOMIC);
if (!_skb)
return false;
skb_trim(_skb, INT_H_SIZE);
bmsg = buf_msg(_skb);
tipc_msg_init(msg_prevnode(msg), bmsg, MSG_BUNDLER, 0,
INT_H_SIZE, dnode);
if (msg_isdata(msg))
msg_set_importance(bmsg, TIPC_CRITICAL_IMPORTANCE);
else
msg_set_importance(bmsg, TIPC_SYSTEM_IMPORTANCE);
msg_set_seqno(bmsg, msg_seqno(msg));
msg_set_ack(bmsg, msg_ack(msg));
msg_set_bcast_ack(bmsg, msg_bcast_ack(msg));
tipc_msg_bundle(_skb, msg, mtu);
*skb = _skb;
return true;
}
bool tipc_msg_reverse(u32 own_node, struct sk_buff **skb, int err)
{
struct sk_buff *_skb = *skb;
struct tipc_msg *hdr;
struct tipc_msg ohdr;
int dlen;
if (skb_linearize(_skb))
goto exit;
hdr = buf_msg(_skb);
dlen = min_t(uint, msg_data_sz(hdr), MAX_FORWARD_SIZE);
if (msg_dest_droppable(hdr))
goto exit;
if (msg_errcode(hdr))
goto exit;
memcpy(&ohdr, hdr, msg_hdr_sz(hdr));
if (msg_short(hdr)) {
*skb = tipc_buf_acquire(BASIC_H_SIZE + dlen, GFP_ATOMIC);
if (!*skb)
goto exit;
memcpy((*skb)->data + BASIC_H_SIZE, msg_data(hdr), dlen);
kfree_skb(_skb);
_skb = *skb;
hdr = buf_msg(_skb);
memcpy(hdr, &ohdr, BASIC_H_SIZE);
msg_set_hdr_sz(hdr, BASIC_H_SIZE);
}
if (skb_cloned(_skb) &&
pskb_expand_head(_skb, BUF_HEADROOM, BUF_TAILROOM, GFP_ATOMIC))
goto exit;
hdr = buf_msg(_skb);
msg_set_errcode(hdr, err);
msg_set_non_seq(hdr, 0);
msg_set_origport(hdr, msg_destport(&ohdr));
msg_set_destport(hdr, msg_origport(&ohdr));
msg_set_destnode(hdr, msg_prevnode(&ohdr));
msg_set_prevnode(hdr, own_node);
msg_set_orignode(hdr, own_node);
msg_set_size(hdr, msg_hdr_sz(hdr) + dlen);
skb_trim(_skb, msg_size(hdr));
skb_orphan(_skb);
return true;
exit:
kfree_skb(_skb);
*skb = NULL;
return false;
}
bool tipc_msg_lookup_dest(struct net *net, struct sk_buff *skb, int *err)
{
struct tipc_msg *msg = buf_msg(skb);
u32 dport, dnode;
u32 onode = tipc_own_addr(net);
if (!msg_isdata(msg))
return false;
if (!msg_named(msg))
return false;
if (msg_errcode(msg))
return false;
*err = TIPC_ERR_NO_NAME;
if (skb_linearize(skb))
return false;
msg = buf_msg(skb);
if (msg_reroute_cnt(msg))
return false;
dnode = addr_domain(net, msg_lookup_scope(msg));
dport = tipc_nametbl_translate(net, msg_nametype(msg),
msg_nameinst(msg), &dnode);
if (!dport)
return false;
msg_incr_reroute_cnt(msg);
if (dnode != onode)
msg_set_prevnode(msg, onode);
msg_set_destnode(msg, dnode);
msg_set_destport(msg, dport);
*err = TIPC_OK;
if (!skb_cloned(skb))
return true;
if (pskb_expand_head(skb, BUF_HEADROOM, BUF_TAILROOM, GFP_ATOMIC))
return false;
return true;
}
bool tipc_msg_reassemble(struct sk_buff_head *list, struct sk_buff_head *rcvq)
{
struct sk_buff *skb, *_skb;
struct sk_buff *frag = NULL;
struct sk_buff *head = NULL;
int hdr_len;
if (skb_queue_len(list) == 1) {
skb = skb_peek(list);
hdr_len = skb_headroom(skb) + msg_hdr_sz(buf_msg(skb));
_skb = __pskb_copy(skb, hdr_len, GFP_ATOMIC);
if (!_skb)
return false;
__skb_queue_tail(rcvq, _skb);
return true;
}
skb_queue_walk(list, skb) {
frag = skb_clone(skb, GFP_ATOMIC);
if (!frag)
goto error;
frag->next = NULL;
if (tipc_buf_append(&head, &frag))
break;
if (!head)
goto error;
}
__skb_queue_tail(rcvq, frag);
return true;
error:
pr_warn("Failed do clone local mcast rcv buffer\n");
kfree_skb(head);
return false;
}
bool tipc_msg_pskb_copy(u32 dst, struct sk_buff_head *msg,
struct sk_buff_head *cpy)
{
struct sk_buff *skb, *_skb;
skb_queue_walk(msg, skb) {
_skb = pskb_copy(skb, GFP_ATOMIC);
if (!_skb) {
__skb_queue_purge(cpy);
return false;
}
msg_set_destnode(buf_msg(_skb), dst);
__skb_queue_tail(cpy, _skb);
}
return true;
}
void __tipc_skb_queue_sorted(struct sk_buff_head *list, u16 seqno,
struct sk_buff *skb)
{
struct sk_buff *_skb, *tmp;
if (skb_queue_empty(list) || less(seqno, buf_seqno(skb_peek(list)))) {
__skb_queue_head(list, skb);
return;
}
if (more(seqno, buf_seqno(skb_peek_tail(list)))) {
__skb_queue_tail(list, skb);
return;
}
skb_queue_walk_safe(list, _skb, tmp) {
if (more(seqno, buf_seqno(_skb)))
continue;
if (seqno == buf_seqno(_skb))
break;
__skb_queue_before(list, _skb, skb);
return;
}
kfree_skb(skb);
}
