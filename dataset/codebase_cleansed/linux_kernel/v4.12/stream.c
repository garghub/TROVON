int sctp_stream_new(struct sctp_association *asoc, gfp_t gfp)
{
struct sctp_stream *stream;
int i;
stream = kzalloc(sizeof(*stream), gfp);
if (!stream)
return -ENOMEM;
stream->outcnt = asoc->c.sinit_num_ostreams;
stream->out = kcalloc(stream->outcnt, sizeof(*stream->out), gfp);
if (!stream->out) {
kfree(stream);
return -ENOMEM;
}
for (i = 0; i < stream->outcnt; i++)
stream->out[i].state = SCTP_STREAM_OPEN;
asoc->stream = stream;
return 0;
}
int sctp_stream_init(struct sctp_association *asoc, gfp_t gfp)
{
struct sctp_stream *stream = asoc->stream;
int i;
kfree(stream->out);
stream->outcnt = asoc->c.sinit_num_ostreams;
stream->out = kcalloc(stream->outcnt, sizeof(*stream->out), gfp);
if (!stream->out)
goto nomem;
for (i = 0; i < stream->outcnt; i++)
stream->out[i].state = SCTP_STREAM_OPEN;
stream->incnt = asoc->c.sinit_max_instreams;
stream->in = kcalloc(stream->incnt, sizeof(*stream->in), gfp);
if (!stream->in) {
kfree(stream->out);
goto nomem;
}
return 0;
nomem:
asoc->stream = NULL;
kfree(stream);
return -ENOMEM;
}
void sctp_stream_free(struct sctp_stream *stream)
{
if (unlikely(!stream))
return;
kfree(stream->out);
kfree(stream->in);
kfree(stream);
}
void sctp_stream_clear(struct sctp_stream *stream)
{
int i;
for (i = 0; i < stream->outcnt; i++)
stream->out[i].ssn = 0;
for (i = 0; i < stream->incnt; i++)
stream->in[i].ssn = 0;
}
static int sctp_send_reconf(struct sctp_association *asoc,
struct sctp_chunk *chunk)
{
struct net *net = sock_net(asoc->base.sk);
int retval = 0;
retval = sctp_primitive_RECONF(net, asoc, chunk);
if (retval)
sctp_chunk_free(chunk);
return retval;
}
int sctp_send_reset_streams(struct sctp_association *asoc,
struct sctp_reset_streams *params)
{
struct sctp_stream *stream = asoc->stream;
__u16 i, str_nums, *str_list;
struct sctp_chunk *chunk;
int retval = -EINVAL;
bool out, in;
if (!asoc->peer.reconf_capable ||
!(asoc->strreset_enable & SCTP_ENABLE_RESET_STREAM_REQ)) {
retval = -ENOPROTOOPT;
goto out;
}
if (asoc->strreset_outstanding) {
retval = -EINPROGRESS;
goto out;
}
out = params->srs_flags & SCTP_STREAM_RESET_OUTGOING;
in = params->srs_flags & SCTP_STREAM_RESET_INCOMING;
if (!out && !in)
goto out;
str_nums = params->srs_number_streams;
str_list = params->srs_stream_list;
if (out && str_nums)
for (i = 0; i < str_nums; i++)
if (str_list[i] >= stream->outcnt)
goto out;
if (in && str_nums)
for (i = 0; i < str_nums; i++)
if (str_list[i] >= stream->incnt)
goto out;
for (i = 0; i < str_nums; i++)
str_list[i] = htons(str_list[i]);
chunk = sctp_make_strreset_req(asoc, str_nums, str_list, out, in);
for (i = 0; i < str_nums; i++)
str_list[i] = ntohs(str_list[i]);
if (!chunk) {
retval = -ENOMEM;
goto out;
}
if (out) {
if (str_nums)
for (i = 0; i < str_nums; i++)
stream->out[str_list[i]].state =
SCTP_STREAM_CLOSED;
else
for (i = 0; i < stream->outcnt; i++)
stream->out[i].state = SCTP_STREAM_CLOSED;
}
asoc->strreset_chunk = chunk;
sctp_chunk_hold(asoc->strreset_chunk);
retval = sctp_send_reconf(asoc, chunk);
if (retval) {
sctp_chunk_put(asoc->strreset_chunk);
asoc->strreset_chunk = NULL;
if (!out)
goto out;
if (str_nums)
for (i = 0; i < str_nums; i++)
stream->out[str_list[i]].state =
SCTP_STREAM_OPEN;
else
for (i = 0; i < stream->outcnt; i++)
stream->out[i].state = SCTP_STREAM_OPEN;
goto out;
}
asoc->strreset_outstanding = out + in;
out:
return retval;
}
int sctp_send_reset_assoc(struct sctp_association *asoc)
{
struct sctp_chunk *chunk = NULL;
int retval;
__u16 i;
if (!asoc->peer.reconf_capable ||
!(asoc->strreset_enable & SCTP_ENABLE_RESET_ASSOC_REQ))
return -ENOPROTOOPT;
if (asoc->strreset_outstanding)
return -EINPROGRESS;
chunk = sctp_make_strreset_tsnreq(asoc);
if (!chunk)
return -ENOMEM;
for (i = 0; i < asoc->stream->outcnt; i++)
asoc->stream->out[i].state = SCTP_STREAM_CLOSED;
asoc->strreset_chunk = chunk;
sctp_chunk_hold(asoc->strreset_chunk);
retval = sctp_send_reconf(asoc, chunk);
if (retval) {
sctp_chunk_put(asoc->strreset_chunk);
asoc->strreset_chunk = NULL;
for (i = 0; i < asoc->stream->outcnt; i++)
asoc->stream->out[i].state = SCTP_STREAM_OPEN;
return retval;
}
asoc->strreset_outstanding = 1;
return 0;
}
int sctp_send_add_streams(struct sctp_association *asoc,
struct sctp_add_streams *params)
{
struct sctp_stream *stream = asoc->stream;
struct sctp_chunk *chunk = NULL;
int retval = -ENOMEM;
__u32 outcnt, incnt;
__u16 out, in;
if (!asoc->peer.reconf_capable ||
!(asoc->strreset_enable & SCTP_ENABLE_CHANGE_ASSOC_REQ)) {
retval = -ENOPROTOOPT;
goto out;
}
if (asoc->strreset_outstanding) {
retval = -EINPROGRESS;
goto out;
}
out = params->sas_outstrms;
in = params->sas_instrms;
outcnt = stream->outcnt + out;
incnt = stream->incnt + in;
if (outcnt > SCTP_MAX_STREAM || incnt > SCTP_MAX_STREAM ||
(!out && !in)) {
retval = -EINVAL;
goto out;
}
if (out) {
struct sctp_stream_out *streamout;
streamout = krealloc(stream->out, outcnt * sizeof(*streamout),
GFP_KERNEL);
if (!streamout)
goto out;
memset(streamout + stream->outcnt, 0, out * sizeof(*streamout));
stream->out = streamout;
}
chunk = sctp_make_strreset_addstrm(asoc, out, in);
if (!chunk)
goto out;
asoc->strreset_chunk = chunk;
sctp_chunk_hold(asoc->strreset_chunk);
retval = sctp_send_reconf(asoc, chunk);
if (retval) {
sctp_chunk_put(asoc->strreset_chunk);
asoc->strreset_chunk = NULL;
goto out;
}
stream->incnt = incnt;
stream->outcnt = outcnt;
asoc->strreset_outstanding = !!out + !!in;
out:
return retval;
}
static sctp_paramhdr_t *sctp_chunk_lookup_strreset_param(
struct sctp_association *asoc, __u32 resp_seq,
__be16 type)
{
struct sctp_chunk *chunk = asoc->strreset_chunk;
struct sctp_reconf_chunk *hdr;
union sctp_params param;
if (!chunk)
return NULL;
hdr = (struct sctp_reconf_chunk *)chunk->chunk_hdr;
sctp_walk_params(param, hdr, params) {
struct sctp_strreset_tsnreq *req = param.v;
if ((!resp_seq || req->request_seq == resp_seq) &&
(!type || type == req->param_hdr.type))
return param.v;
}
return NULL;
}
static void sctp_update_strreset_result(struct sctp_association *asoc,
__u32 result)
{
asoc->strreset_result[1] = asoc->strreset_result[0];
asoc->strreset_result[0] = result;
}
struct sctp_chunk *sctp_process_strreset_outreq(
struct sctp_association *asoc,
union sctp_params param,
struct sctp_ulpevent **evp)
{
struct sctp_strreset_outreq *outreq = param.v;
struct sctp_stream *stream = asoc->stream;
__u16 i, nums, flags = 0, *str_p = NULL;
__u32 result = SCTP_STRRESET_DENIED;
__u32 request_seq;
request_seq = ntohl(outreq->request_seq);
if (ntohl(outreq->send_reset_at_tsn) >
sctp_tsnmap_get_ctsn(&asoc->peer.tsn_map)) {
result = SCTP_STRRESET_IN_PROGRESS;
goto err;
}
if (TSN_lt(asoc->strreset_inseq, request_seq) ||
TSN_lt(request_seq, asoc->strreset_inseq - 2)) {
result = SCTP_STRRESET_ERR_BAD_SEQNO;
goto err;
} else if (TSN_lt(request_seq, asoc->strreset_inseq)) {
i = asoc->strreset_inseq - request_seq - 1;
result = asoc->strreset_result[i];
goto err;
}
asoc->strreset_inseq++;
if (!(asoc->strreset_enable & SCTP_ENABLE_RESET_STREAM_REQ))
goto out;
if (asoc->strreset_chunk) {
if (!sctp_chunk_lookup_strreset_param(
asoc, outreq->response_seq,
SCTP_PARAM_RESET_IN_REQUEST)) {
result = SCTP_STRRESET_ERR_IN_PROGRESS;
goto out;
}
asoc->strreset_outstanding--;
asoc->strreset_outseq++;
if (!asoc->strreset_outstanding) {
struct sctp_transport *t;
t = asoc->strreset_chunk->transport;
if (del_timer(&t->reconf_timer))
sctp_transport_put(t);
sctp_chunk_put(asoc->strreset_chunk);
asoc->strreset_chunk = NULL;
}
flags = SCTP_STREAM_RESET_INCOMING_SSN;
}
nums = (ntohs(param.p->length) - sizeof(*outreq)) / 2;
if (nums) {
str_p = outreq->list_of_streams;
for (i = 0; i < nums; i++) {
if (ntohs(str_p[i]) >= stream->incnt) {
result = SCTP_STRRESET_ERR_WRONG_SSN;
goto out;
}
}
for (i = 0; i < nums; i++)
stream->in[ntohs(str_p[i])].ssn = 0;
} else {
for (i = 0; i < stream->incnt; i++)
stream->in[i].ssn = 0;
}
result = SCTP_STRRESET_PERFORMED;
*evp = sctp_ulpevent_make_stream_reset_event(asoc,
flags | SCTP_STREAM_RESET_OUTGOING_SSN, nums, str_p,
GFP_ATOMIC);
out:
sctp_update_strreset_result(asoc, result);
err:
return sctp_make_strreset_resp(asoc, result, request_seq);
}
struct sctp_chunk *sctp_process_strreset_inreq(
struct sctp_association *asoc,
union sctp_params param,
struct sctp_ulpevent **evp)
{
struct sctp_strreset_inreq *inreq = param.v;
struct sctp_stream *stream = asoc->stream;
__u32 result = SCTP_STRRESET_DENIED;
struct sctp_chunk *chunk = NULL;
__u16 i, nums, *str_p;
__u32 request_seq;
request_seq = ntohl(inreq->request_seq);
if (TSN_lt(asoc->strreset_inseq, request_seq) ||
TSN_lt(request_seq, asoc->strreset_inseq - 2)) {
result = SCTP_STRRESET_ERR_BAD_SEQNO;
goto err;
} else if (TSN_lt(request_seq, asoc->strreset_inseq)) {
i = asoc->strreset_inseq - request_seq - 1;
result = asoc->strreset_result[i];
if (result == SCTP_STRRESET_PERFORMED)
return NULL;
goto err;
}
asoc->strreset_inseq++;
if (!(asoc->strreset_enable & SCTP_ENABLE_RESET_STREAM_REQ))
goto out;
if (asoc->strreset_outstanding) {
result = SCTP_STRRESET_ERR_IN_PROGRESS;
goto out;
}
nums = (ntohs(param.p->length) - sizeof(*inreq)) / 2;
str_p = inreq->list_of_streams;
for (i = 0; i < nums; i++) {
if (ntohs(str_p[i]) >= stream->outcnt) {
result = SCTP_STRRESET_ERR_WRONG_SSN;
goto out;
}
}
chunk = sctp_make_strreset_req(asoc, nums, str_p, 1, 0);
if (!chunk)
goto out;
if (nums)
for (i = 0; i < nums; i++)
stream->out[ntohs(str_p[i])].state =
SCTP_STREAM_CLOSED;
else
for (i = 0; i < stream->outcnt; i++)
stream->out[i].state = SCTP_STREAM_CLOSED;
asoc->strreset_chunk = chunk;
asoc->strreset_outstanding = 1;
sctp_chunk_hold(asoc->strreset_chunk);
result = SCTP_STRRESET_PERFORMED;
*evp = sctp_ulpevent_make_stream_reset_event(asoc,
SCTP_STREAM_RESET_INCOMING_SSN, nums, str_p, GFP_ATOMIC);
out:
sctp_update_strreset_result(asoc, result);
err:
if (!chunk)
chunk = sctp_make_strreset_resp(asoc, result, request_seq);
return chunk;
}
struct sctp_chunk *sctp_process_strreset_tsnreq(
struct sctp_association *asoc,
union sctp_params param,
struct sctp_ulpevent **evp)
{
__u32 init_tsn = 0, next_tsn = 0, max_tsn_seen;
struct sctp_strreset_tsnreq *tsnreq = param.v;
struct sctp_stream *stream = asoc->stream;
__u32 result = SCTP_STRRESET_DENIED;
__u32 request_seq;
__u16 i;
request_seq = ntohl(tsnreq->request_seq);
if (TSN_lt(asoc->strreset_inseq, request_seq) ||
TSN_lt(request_seq, asoc->strreset_inseq - 2)) {
result = SCTP_STRRESET_ERR_BAD_SEQNO;
goto err;
} else if (TSN_lt(request_seq, asoc->strreset_inseq)) {
i = asoc->strreset_inseq - request_seq - 1;
result = asoc->strreset_result[i];
if (result == SCTP_STRRESET_PERFORMED) {
next_tsn = asoc->next_tsn;
init_tsn =
sctp_tsnmap_get_ctsn(&asoc->peer.tsn_map) + 1;
}
goto err;
}
asoc->strreset_inseq++;
if (!(asoc->strreset_enable & SCTP_ENABLE_RESET_ASSOC_REQ))
goto out;
if (asoc->strreset_outstanding) {
result = SCTP_STRRESET_ERR_IN_PROGRESS;
goto out;
}
max_tsn_seen = sctp_tsnmap_get_max_tsn_seen(&asoc->peer.tsn_map);
sctp_ulpq_reasm_flushtsn(&asoc->ulpq, max_tsn_seen);
sctp_ulpq_abort_pd(&asoc->ulpq, GFP_ATOMIC);
init_tsn = sctp_tsnmap_get_ctsn(&asoc->peer.tsn_map) + (1 << 31);
sctp_tsnmap_init(&asoc->peer.tsn_map, SCTP_TSN_MAP_INITIAL,
init_tsn, GFP_ATOMIC);
sctp_outq_free(&asoc->outqueue);
next_tsn = asoc->next_tsn;
asoc->ctsn_ack_point = next_tsn - 1;
asoc->adv_peer_ack_point = asoc->ctsn_ack_point;
for (i = 0; i < stream->outcnt; i++)
stream->out[i].ssn = 0;
for (i = 0; i < stream->incnt; i++)
stream->in[i].ssn = 0;
result = SCTP_STRRESET_PERFORMED;
*evp = sctp_ulpevent_make_assoc_reset_event(asoc, 0, init_tsn,
next_tsn, GFP_ATOMIC);
out:
sctp_update_strreset_result(asoc, result);
err:
return sctp_make_strreset_tsnresp(asoc, result, request_seq,
next_tsn, init_tsn);
}
struct sctp_chunk *sctp_process_strreset_addstrm_out(
struct sctp_association *asoc,
union sctp_params param,
struct sctp_ulpevent **evp)
{
struct sctp_strreset_addstrm *addstrm = param.v;
struct sctp_stream *stream = asoc->stream;
__u32 result = SCTP_STRRESET_DENIED;
struct sctp_stream_in *streamin;
__u32 request_seq, incnt;
__u16 in, i;
request_seq = ntohl(addstrm->request_seq);
if (TSN_lt(asoc->strreset_inseq, request_seq) ||
TSN_lt(request_seq, asoc->strreset_inseq - 2)) {
result = SCTP_STRRESET_ERR_BAD_SEQNO;
goto err;
} else if (TSN_lt(request_seq, asoc->strreset_inseq)) {
i = asoc->strreset_inseq - request_seq - 1;
result = asoc->strreset_result[i];
goto err;
}
asoc->strreset_inseq++;
if (!(asoc->strreset_enable & SCTP_ENABLE_CHANGE_ASSOC_REQ))
goto out;
if (asoc->strreset_chunk) {
if (!sctp_chunk_lookup_strreset_param(
asoc, 0, SCTP_PARAM_RESET_ADD_IN_STREAMS)) {
result = SCTP_STRRESET_ERR_IN_PROGRESS;
goto out;
}
asoc->strreset_outstanding--;
asoc->strreset_outseq++;
if (!asoc->strreset_outstanding) {
struct sctp_transport *t;
t = asoc->strreset_chunk->transport;
if (del_timer(&t->reconf_timer))
sctp_transport_put(t);
sctp_chunk_put(asoc->strreset_chunk);
asoc->strreset_chunk = NULL;
}
}
in = ntohs(addstrm->number_of_streams);
incnt = stream->incnt + in;
if (!in || incnt > SCTP_MAX_STREAM)
goto out;
streamin = krealloc(stream->in, incnt * sizeof(*streamin),
GFP_ATOMIC);
if (!streamin)
goto out;
memset(streamin + stream->incnt, 0, in * sizeof(*streamin));
stream->in = streamin;
stream->incnt = incnt;
result = SCTP_STRRESET_PERFORMED;
*evp = sctp_ulpevent_make_stream_change_event(asoc,
0, ntohs(addstrm->number_of_streams), 0, GFP_ATOMIC);
out:
sctp_update_strreset_result(asoc, result);
err:
return sctp_make_strreset_resp(asoc, result, request_seq);
}
struct sctp_chunk *sctp_process_strreset_addstrm_in(
struct sctp_association *asoc,
union sctp_params param,
struct sctp_ulpevent **evp)
{
struct sctp_strreset_addstrm *addstrm = param.v;
struct sctp_stream *stream = asoc->stream;
__u32 result = SCTP_STRRESET_DENIED;
struct sctp_stream_out *streamout;
struct sctp_chunk *chunk = NULL;
__u32 request_seq, outcnt;
__u16 out, i;
request_seq = ntohl(addstrm->request_seq);
if (TSN_lt(asoc->strreset_inseq, request_seq) ||
TSN_lt(request_seq, asoc->strreset_inseq - 2)) {
result = SCTP_STRRESET_ERR_BAD_SEQNO;
goto err;
} else if (TSN_lt(request_seq, asoc->strreset_inseq)) {
i = asoc->strreset_inseq - request_seq - 1;
result = asoc->strreset_result[i];
if (result == SCTP_STRRESET_PERFORMED)
return NULL;
goto err;
}
asoc->strreset_inseq++;
if (!(asoc->strreset_enable & SCTP_ENABLE_CHANGE_ASSOC_REQ))
goto out;
if (asoc->strreset_outstanding) {
result = SCTP_STRRESET_ERR_IN_PROGRESS;
goto out;
}
out = ntohs(addstrm->number_of_streams);
outcnt = stream->outcnt + out;
if (!out || outcnt > SCTP_MAX_STREAM)
goto out;
streamout = krealloc(stream->out, outcnt * sizeof(*streamout),
GFP_ATOMIC);
if (!streamout)
goto out;
memset(streamout + stream->outcnt, 0, out * sizeof(*streamout));
stream->out = streamout;
chunk = sctp_make_strreset_addstrm(asoc, out, 0);
if (!chunk)
goto out;
asoc->strreset_chunk = chunk;
asoc->strreset_outstanding = 1;
sctp_chunk_hold(asoc->strreset_chunk);
stream->outcnt = outcnt;
result = SCTP_STRRESET_PERFORMED;
*evp = sctp_ulpevent_make_stream_change_event(asoc,
0, 0, ntohs(addstrm->number_of_streams), GFP_ATOMIC);
out:
sctp_update_strreset_result(asoc, result);
err:
if (!chunk)
chunk = sctp_make_strreset_resp(asoc, result, request_seq);
return chunk;
}
struct sctp_chunk *sctp_process_strreset_resp(
struct sctp_association *asoc,
union sctp_params param,
struct sctp_ulpevent **evp)
{
struct sctp_strreset_resp *resp = param.v;
struct sctp_stream *stream = asoc->stream;
struct sctp_transport *t;
__u16 i, nums, flags = 0;
sctp_paramhdr_t *req;
__u32 result;
req = sctp_chunk_lookup_strreset_param(asoc, resp->response_seq, 0);
if (!req)
return NULL;
result = ntohl(resp->result);
if (result != SCTP_STRRESET_PERFORMED) {
if (result == SCTP_STRRESET_IN_PROGRESS)
return NULL;
else if (result == SCTP_STRRESET_DENIED)
flags = SCTP_STREAM_RESET_DENIED;
else
flags = SCTP_STREAM_RESET_FAILED;
}
if (req->type == SCTP_PARAM_RESET_OUT_REQUEST) {
struct sctp_strreset_outreq *outreq;
__u16 *str_p;
outreq = (struct sctp_strreset_outreq *)req;
str_p = outreq->list_of_streams;
nums = (ntohs(outreq->param_hdr.length) - sizeof(*outreq)) / 2;
if (result == SCTP_STRRESET_PERFORMED) {
if (nums) {
for (i = 0; i < nums; i++)
stream->out[ntohs(str_p[i])].ssn = 0;
} else {
for (i = 0; i < stream->outcnt; i++)
stream->out[i].ssn = 0;
}
flags = SCTP_STREAM_RESET_OUTGOING_SSN;
}
for (i = 0; i < stream->outcnt; i++)
stream->out[i].state = SCTP_STREAM_OPEN;
*evp = sctp_ulpevent_make_stream_reset_event(asoc, flags,
nums, str_p, GFP_ATOMIC);
} else if (req->type == SCTP_PARAM_RESET_IN_REQUEST) {
struct sctp_strreset_inreq *inreq;
__u16 *str_p;
if (result == SCTP_STRRESET_PERFORMED)
return NULL;
inreq = (struct sctp_strreset_inreq *)req;
str_p = inreq->list_of_streams;
nums = (ntohs(inreq->param_hdr.length) - sizeof(*inreq)) / 2;
*evp = sctp_ulpevent_make_stream_reset_event(asoc, flags,
nums, str_p, GFP_ATOMIC);
} else if (req->type == SCTP_PARAM_RESET_TSN_REQUEST) {
struct sctp_strreset_resptsn *resptsn;
__u32 stsn, rtsn;
if (ntohs(param.p->length) != sizeof(*resptsn))
return NULL;
resptsn = (struct sctp_strreset_resptsn *)resp;
stsn = ntohl(resptsn->senders_next_tsn);
rtsn = ntohl(resptsn->receivers_next_tsn);
if (result == SCTP_STRRESET_PERFORMED) {
__u32 mtsn = sctp_tsnmap_get_max_tsn_seen(
&asoc->peer.tsn_map);
sctp_ulpq_reasm_flushtsn(&asoc->ulpq, mtsn);
sctp_ulpq_abort_pd(&asoc->ulpq, GFP_ATOMIC);
sctp_tsnmap_init(&asoc->peer.tsn_map,
SCTP_TSN_MAP_INITIAL,
stsn, GFP_ATOMIC);
sctp_outq_free(&asoc->outqueue);
asoc->next_tsn = rtsn;
asoc->ctsn_ack_point = asoc->next_tsn - 1;
asoc->adv_peer_ack_point = asoc->ctsn_ack_point;
for (i = 0; i < stream->outcnt; i++)
stream->out[i].ssn = 0;
for (i = 0; i < stream->incnt; i++)
stream->in[i].ssn = 0;
}
for (i = 0; i < stream->outcnt; i++)
stream->out[i].state = SCTP_STREAM_OPEN;
*evp = sctp_ulpevent_make_assoc_reset_event(asoc, flags,
stsn, rtsn, GFP_ATOMIC);
} else if (req->type == SCTP_PARAM_RESET_ADD_OUT_STREAMS) {
struct sctp_strreset_addstrm *addstrm;
__u16 number;
addstrm = (struct sctp_strreset_addstrm *)req;
nums = ntohs(addstrm->number_of_streams);
number = stream->outcnt - nums;
if (result == SCTP_STRRESET_PERFORMED)
for (i = number; i < stream->outcnt; i++)
stream->out[i].state = SCTP_STREAM_OPEN;
else
stream->outcnt = number;
*evp = sctp_ulpevent_make_stream_change_event(asoc, flags,
0, nums, GFP_ATOMIC);
} else if (req->type == SCTP_PARAM_RESET_ADD_IN_STREAMS) {
struct sctp_strreset_addstrm *addstrm;
if (result == SCTP_STRRESET_PERFORMED)
return NULL;
addstrm = (struct sctp_strreset_addstrm *)req;
nums = ntohs(addstrm->number_of_streams);
*evp = sctp_ulpevent_make_stream_change_event(asoc, flags,
nums, 0, GFP_ATOMIC);
}
asoc->strreset_outstanding--;
asoc->strreset_outseq++;
if (!asoc->strreset_outstanding) {
t = asoc->strreset_chunk->transport;
if (del_timer(&t->reconf_timer))
sctp_transport_put(t);
sctp_chunk_put(asoc->strreset_chunk);
asoc->strreset_chunk = NULL;
}
return NULL;
}
