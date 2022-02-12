const sctp_sm_table_entry_t *sctp_sm_lookup_event(struct net *net,
sctp_event_t event_type,
sctp_state_t state,
sctp_subtype_t event_subtype)
{
switch (event_type) {
case SCTP_EVENT_T_CHUNK:
return sctp_chunk_event_lookup(net, event_subtype.chunk, state);
case SCTP_EVENT_T_TIMEOUT:
return DO_LOOKUP(SCTP_EVENT_TIMEOUT_MAX, timeout,
timeout_event_table);
case SCTP_EVENT_T_OTHER:
return DO_LOOKUP(SCTP_EVENT_OTHER_MAX, other,
other_event_table);
case SCTP_EVENT_T_PRIMITIVE:
return DO_LOOKUP(SCTP_EVENT_PRIMITIVE_MAX, primitive,
primitive_event_table);
default:
return &bug;
}
}
static const sctp_sm_table_entry_t *sctp_chunk_event_lookup(struct net *net,
sctp_cid_t cid,
sctp_state_t state)
{
if (state > SCTP_STATE_MAX)
return &bug;
if (cid <= SCTP_CID_BASE_MAX)
return &chunk_event_table[cid][state];
if (net->sctp.prsctp_enable) {
if (cid == SCTP_CID_FWD_TSN)
return &prsctp_chunk_event_table[0][state];
}
if (net->sctp.addip_enable) {
if (cid == SCTP_CID_ASCONF)
return &addip_chunk_event_table[0][state];
if (cid == SCTP_CID_ASCONF_ACK)
return &addip_chunk_event_table[1][state];
}
if (net->sctp.auth_enable) {
if (cid == SCTP_CID_AUTH)
return &auth_chunk_event_table[0][state];
}
return &chunk_event_table_unknown[state];
}
