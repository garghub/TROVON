static int
lolnd_send(struct lnet_ni *ni, void *private, struct lnet_msg *lntmsg)
{
LASSERT(!lntmsg->msg_routing);
LASSERT(!lntmsg->msg_target_is_router);
return lnet_parse(ni, &lntmsg->msg_hdr, ni->ni_nid, lntmsg, 0);
}
static int
lolnd_recv(struct lnet_ni *ni, void *private, struct lnet_msg *lntmsg,
int delayed, struct iov_iter *to, unsigned int rlen)
{
struct lnet_msg *sendmsg = private;
if (lntmsg) {
if (sendmsg->msg_iov)
lnet_copy_iov2iter(to,
sendmsg->msg_niov,
sendmsg->msg_iov,
sendmsg->msg_offset,
iov_iter_count(to));
else
lnet_copy_kiov2iter(to,
sendmsg->msg_niov,
sendmsg->msg_kiov,
sendmsg->msg_offset,
iov_iter_count(to));
lnet_finalize(ni, lntmsg, 0);
}
lnet_finalize(ni, sendmsg, 0);
return 0;
}
static void
lolnd_shutdown(struct lnet_ni *ni)
{
CDEBUG(D_NET, "shutdown\n");
LASSERT(lolnd_instanced);
lolnd_instanced = 0;
}
static int
lolnd_startup(struct lnet_ni *ni)
{
LASSERT(ni->ni_lnd == &the_lolnd);
LASSERT(!lolnd_instanced);
lolnd_instanced = 1;
return 0;
}
